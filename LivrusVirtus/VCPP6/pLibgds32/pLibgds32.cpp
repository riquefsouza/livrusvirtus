#include "stdafx.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

#include <ibase.h>

#define TAM_MAX_STR 256
#define QTD_MAX_COL 20

#define STR_NCONBANCO           "Não consigo conectar com o banco de dados!"
#define STR_NDCOBANCO           "Não consigo desconectar com o banco de dados!"
#define STR_NALOCHSTM           "Não foi possível alocar o manuseador para o procedimento!"
#define STR_NCPREPSQL           "Não conseguiu preparar o SQL!"
#define STR_NCEXECSQL           "Não conseguiu executar o SQL!"
#define STR_DESCPROC            "Não conseguiu descrever o procedimento!"
#define STR_NINITRAN            "Não conseguiu iniciar a transação!"
#define STR_NLIBTRAN            "Não conseguiu liberar a transação!"
#define STR_NFINTRAN            "Não conseguiu finalizar a transação!"

typedef isc_db_handle CONEXAO;
//extern CONEXAO  gConexao;

CONEXAO gConexao;

bool Rotinas_ConectaBanco(char *sBancoDeDados, char *sLogin, char *sSenha);
void Rotinas_DisconectaBanco();
bool Rotinas_AtualizaDados(CONEXAO hBancoLocal, char *sSql);
bool Rotinas_PreConsultaDados(CONEXAO hBancoLocal, char *sSql, 
  isc_tr_handle *hTransacao, isc_stmt_handle *hstmtLocal, XSQLDA **sqlda);
bool Rotinas_PosConsultaDados(isc_tr_handle *hTransacao, 
                              isc_stmt_handle *hstmtLocal);
bool Rotinas_DescreveProcedimento(isc_stmt_handle hstmtLocal, XSQLDA **sqlda,                                
  int *nQtdCols, char *sCampo[], float dCampo[], short nsCampo[], long tsCampo[]);
bool Rotinas_ConsultaDados(CONEXAO hBancoLocal, char *sSql);
bool Rotinas_ConsultaDadosLista(CONEXAO hBancoLocal, char *sSql);
//                                      LISTAMSTR *lstLocal, char *sSql);

bool Rotinas_ConectaBanco(char *sBancoDeDados, char *sLogin, char *sSenha) {
char ISC_FAR *params = NULL;
short nparams = 0;
char ISC_FAR *d, *p, *copia;
long l, sweep_interval = 16384;
long status[20];
  
  copia = params = (char *) malloc(7);
  p = params;
  *p++ = '\1';
  *p++ = isc_dpb_sweep_interval;
  *p++ = '\4';
  l = isc_vax_integer((char ISC_FAR *) &sweep_interval, 4);
  d = (char *) &l;
  *p++ = *d++;
  *p++ = *d++;
  *p++ = *d++;
  *p = *d;
  nparams = 7;
  isc_expand_dpb(&params, (short ISC_FAR *) &nparams,
                 isc_dpb_user_name, sLogin,
                 isc_dpb_password, sSenha,  NULL);

  if (isc_attach_database(status, 0, sBancoDeDados, &gConexao, nparams, params)) {
    printf("%s, SQLCODE: %d\n", STR_NCONBANCO, isc_sqlcode(status));
    return false;
  }
  return true;
}

void Rotinas_DisconectaBanco() {
long status[20];

  if (isc_detach_database(status, &gConexao))
    printf("%s, SQLCODE: %d\n", STR_NDCOBANCO, isc_sqlcode(status));
}


bool Rotinas_AtualizaDados(CONEXAO hBancoLocal, char *sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
long status[20];

  if (isc_start_transaction(status, &hTransacao, 1, &hBancoLocal, 0, NULL)) {
    printf("%s, SQLCODE: %d\n", STR_NINITRAN, isc_sqlcode(status));
    bret = false;
  }
  if (isc_dsql_execute_immediate(
          status, &hBancoLocal, &hTransacao, 0, sSql, 1, NULL)) {
    printf("%s, SQLCODE: %d\n", STR_NCEXECSQL, isc_sqlcode(status));
    bret = false;
  }
  if (isc_commit_transaction(status, &hTransacao)) {
    printf("%s, SQLCODE: %d\n", STR_NFINTRAN, isc_sqlcode(status));
    bret = false;
  }
  return bret;
}

bool Rotinas_PreConsultaDados(CONEXAO hBancoLocal, char *sSql, 
  isc_tr_handle *hTransacao, isc_stmt_handle *hstmtLocal, XSQLDA **sqlda) {
bool bret = true;
long status[20];

  if (isc_start_transaction(status, hTransacao, 1, &hBancoLocal, 0, NULL)) {
    printf("%s, SQLCODE: %d\n", STR_NINITRAN, isc_sqlcode(status));
    bret = false;
  }
  if (isc_dsql_allocate_statement(status, &hBancoLocal, hstmtLocal)) {
    printf("%s, SQLCODE: %d\n", STR_NALOCHSTM, isc_sqlcode(status));
    bret = false;
  }

  /* Aloca SQLDA com um tamanho mínimo. */
  (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH(1));
  (*sqlda)->sqln = 1;
  (*sqlda)->version = 1;

  if (isc_dsql_prepare(status, hTransacao, hstmtLocal, 0, 
    sSql, 1, (*sqlda))) {
    printf("%s, SQLCODE: %d\n", STR_NCPREPSQL, isc_sqlcode(status));
    bret = false;
  }
  return bret;
}

bool Rotinas_PosConsultaDados(isc_tr_handle *hTransacao, 
                              isc_stmt_handle *hstmtLocal) {
bool bret = true;
long status[20];

  if (isc_dsql_free_statement(status, hstmtLocal, DSQL_drop)) {
    printf("%s, SQLCODE: %d\n", STR_NLIBTRAN, isc_sqlcode(status));
    bret = false;
  }
  if (isc_commit_transaction(status, hTransacao)) {
    printf("%s, SQLCODE: %d\n", STR_NFINTRAN, isc_sqlcode(status));
    bret = false;
  }
  return bret;
}

bool Rotinas_DescreveProcedimento(isc_stmt_handle hstmtLocal, XSQLDA **sqlda,
  int *nQtdCols, char *sCampo[], float dCampo[], short nsCampo[], long tsCampo[]){
bool bret = true;
short flag = 0;
int nCol, nNulo;
long status[20];

  /* Descreve o procedimento. */
  if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
    printf("%s, SQLCODE: %d\n", STR_DESCPROC, isc_sqlcode(status));
    bret = false;
  }
  
  (*nQtdCols) = (*sqlda)->sqld;

  /* Realoca SQLDA se necessário. */
  if ((*sqlda)->sqln < (*sqlda)->sqld)
  {
      (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH((*nQtdCols)));
      (*sqlda)->sqln = (*nQtdCols);
      (*sqlda)->version = 1;
  
      /* Redescreve o procedimento. */
      if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
        printf("%s, SQLCODE: %d\n", STR_DESCPROC, isc_sqlcode(status));
        bret = false;
      }
      (*nQtdCols) = (*sqlda)->sqld;
  }
  for (nCol = 0; nCol < (*nQtdCols); nCol++) {
    /* verifica se é nulo */
    if ((*sqlda)->sqlvar[nCol].sqltype & 1)
      nNulo = 1;    
    else
      nNulo = 0;
    if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &dCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_FLOAT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &nsCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_SHORT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &tsCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_TIMESTAMP + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else {
      (*sqlda)->sqlvar[nCol].sqldata = sCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_TEXT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    }
  }

  return bret;
}

bool Rotinas_ConsultaDados(CONEXAO hBancoLocal, char *sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
isc_stmt_handle hstmtLocal = NULL;
long  status_fetch;
XSQLDA *sqlda;
char *sCampo[QTD_MAX_COL];
float dCampo[QTD_MAX_COL];
short nsCampo[QTD_MAX_COL];
long tsCampo[QTD_MAX_COL];
int nCol, nQtdCols;
long status[20];

  bret = Rotinas_PreConsultaDados(hBancoLocal, sSql, &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = (char*)malloc(TAM_MAX_STR);

  bret = Rotinas_DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    printf("%s, SQLCODE: %d\n", STR_NCEXECSQL, isc_sqlcode(status));
    bret = false;
  }

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  if (status_fetch == 0) 
    bret = true;
  else
    bret = false;

  Rotinas_PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

bool Rotinas_ConsultaDadosLista(CONEXAO hBancoLocal, char *sSql) {
                                          //LISTAMSTR *lstLocal, char *sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
isc_stmt_handle hstmtLocal = NULL;
XSQLDA *sqlda;
long  status_fetch;
char *sCampo[QTD_MAX_COL];
float dCampo[QTD_MAX_COL];
short nsCampo[QTD_MAX_COL];
long tsCampo[QTD_MAX_COL];
struct tm mTempo;
int nCol, nQtdCols, nNulo;
long status[20];

  bret = Rotinas_PreConsultaDados(hBancoLocal, sSql, &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = (char*)malloc(TAM_MAX_STR);

  bret = Rotinas_DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    printf("%s, SQLCODE: %d\n", STR_NCEXECSQL, isc_sqlcode(status));
    bret = false;
  }

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  while (status_fetch == 0) {

    for (nCol = 0; nCol < nQtdCols; nCol++) {
      /* verifica se é nulo */
      if (sqlda->sqlvar[nCol].sqltype & 1)
        nNulo = 1;    
      else
        nNulo = 0;
      if (sqlda->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
        printf("Campo[%d] = %.2f\n", nCol, dCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
        printf("Campo[%d] = %d\n", nCol, nsCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
        isc_decode_timestamp((ISC_TIMESTAMP *)&tsCampo[nCol], &mTempo);          
	      printf("%02d/%02d/%04d %02d:%02d:%02d.%04d\n",
				      mTempo.tm_mday,
              mTempo.tm_mon+1,
				      mTempo.tm_year + 1900,
				      mTempo.tm_hour,
				      mTempo.tm_min,
				      mTempo.tm_sec,
				      ((ISC_TIMESTAMP *)&tsCampo[nCol])->timestamp_time % 10000);
      } else {
        sCampo[nCol][sqlda->sqlvar[nCol].sqllen] = '\0';
        printf("Campo[%d] = %s\n", nCol, sCampo[nCol]);
      }

    }
    status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  }

  if (status_fetch != 100L) {
    printf("SQLCODE: %d\n", isc_sqlcode(status));
    bret = false;
  }
  Rotinas_PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

int main(int argc, char* argv[])
{
  if (Rotinas_ConectaBanco(
    "C:\\LivrusVirtus\\Bancos\\interbase\\Livrus.gdb", "SYSDBA", "masterkey"))
   if (Rotinas_ConsultaDadosLista(gConexao, "select * from cliente"))
     printf("BELEZA");
  //  "C:\\Arquivos de programas\\Firebird\\Firebird_1_5\\examples\\EMPLOYEE.fdb", "SYSDBA", "masterkey"))
  //  Rotinas_ConsultaDados(gConexao, "select proj_id, dept_no, fiscal_year, projected_budget from proj_dept_budget");
  Rotinas_DisconectaBanco();
	return 0;
}

