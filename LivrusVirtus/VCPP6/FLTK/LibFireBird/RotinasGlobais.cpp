#include "Livrus.h"
#include "Principal.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"

string Rotinas_sUsuarioLogin;
string Rotinas_sUsuarioSenha;
string Rotinas_sCodigoSelecionado;
string Rotinas_sPreco;
string Rotinas_sQtdEstoque;
//string Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
string Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

CONEXAO gConexao;

CRotinasGlobais *Rotinas;

CRotinasGlobais::CRotinasGlobais() {
}

char* CRotinasGlobais::alocaString(int ntam)
{ char *strlocal;

 strlocal = (char*) malloc(ntam);
 strlocal[0]='\0';
 return strlocal;
}

char* CRotinasGlobais::trim(const char *sTexto) {
int ncont, npos, nPosIni, nPosFim;
char *sret = Rotinas->alocaString(TAM_MAX_STR);

  nPosIni = 0;
  for (ncont=0; abs(ncont) < strlen(sTexto); ncont++) {
    if (sTexto[ncont]==' ')
      nPosIni++;
    else
      break;    
  }
  nPosFim = (strlen(sTexto)-1);
  for (ncont=(strlen(sTexto)-1); ncont >= 0 ; ncont--) {
    if (sTexto[ncont]==' ')
      nPosFim--;
    else
      break;
  }
  ncont = 0;
  for (npos=nPosIni; npos <= nPosFim; npos++) {
    sret[ncont] = sTexto[npos];
    ncont++;
  }
  sret[ncont]='\0';

return sret;
}

bool CRotinasGlobais::ValidaFloat(string sNum)
{
 if (sNum.length() > 0) {    
    if (atof(sNum.c_str()) >= 0.01)
      return true;
    else {
      fl_alert(STR_NUMINV);
      return false;
    }
 } else
   return false;
} 

char *CRotinasGlobais::VirgulaParaPonto(char *sNum, bool bRevertido) 
{
int ncont;
char *sret = Rotinas->alocaString(TAM_MAX_STR);
char sponto[2], svirgula[2];

if (bRevertido) {
  strcpy(sponto, ",");
  strcpy(svirgula, ".");
} else {
  strcpy(sponto, ".");
  strcpy(svirgula, ",");
}

for (ncont=0; abs(ncont) < strlen(sNum); ncont++) {
  if (sNum[ncont] == svirgula[0])
    sret[ncont] = sponto[0];
  else 
    sret[ncont] = sNum[ncont];
}
sret[strlen(sNum)]='\0';
return sret;
}

int CRotinasGlobais::modulo11(string svalor, int ndig) {
int ncont, nsoma, nvalor, npos;
string slocal, sres;

 ncont=0;
 while (ncont < 11) {
   slocal=svalor.substr(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres = slocal.substr(ncont,1);
   nvalor = atoi(sres.c_str());
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   return 0;
 else
   return nsoma;
}

bool CRotinasGlobais::validaCPF(string cpf) {
string scpf;
  
if (cpf.length()==14) {	
  scpf=cpf.substr(0,3) + cpf.substr(4,3)+cpf.substr(8,3)+cpf.substr(12,2);
  if ( (modulo11(scpf,1)==atoi(cpf.substr(12,1).c_str())) &&
  (modulo11(scpf,2)==atoi(cpf.substr(13,1).c_str())) )
    return true;
  else
  	return false;
} else
  return false;
}

bool CRotinasGlobais::validaISBN(string isbn) {
 string sisbn, sdigito, snum;
 int nvalor, nsoma, ncont;

if (isbn.length()==13) {
  sdigito = isbn.substr(isbn.length()-1, 1);
  sisbn="";
  for(ncont = 0; ncont < abs(isbn.length()-1); ncont++)  {
    if (isbn.substr(ncont,1)!="-")
      sisbn = sisbn + isbn.substr(ncont,1);
  }
  if (sdigito=="X")
    nsoma = 10;
  else {
    nvalor = atoi(sdigito.c_str());
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.substr(ncont-1, 1);
    nvalor = atoi(snum.c_str());
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    return true;
  else
    return false;
} else
  return false;
}

bool CRotinasGlobais::validaDataHora(string sDataHora, bool bSoData)
{ bool bvalida, bdatavalida, bhoravalida;
  string sdia, smes, sano, shora, smin, sseg;
  int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;

  if (sDataHora.length()==abs(ntam)) {
    sdia = sDataHora.substr(0,2);
    ndia = atoi(sdia.c_str());
    smes = sDataHora.substr(3,2);
    nmes = atoi(smes.c_str());
    sano = sDataHora.substr(6,4);
    nano = atoi(sano.c_str());
  
    if ((nano >= 1) && (nano <= 9999)) {
      if ((nmes >= 1) && (nmes <= 31)) {
          switch(nmes) {
           case 1: case 3: case 5: case 7: case 8: 
           case 10: case 12: nudiames = 31; break;
           case 2: {
               /* ano bissexto */
               if ((nano % 4)==0) nudiames = 29;
               else nudiames = 28;
              } break;
           case 4: case 6: case 9: case 11: nudiames = 30; break;
          }
          if ((ndia >=1) && (ndia <=nudiames))
             bdatavalida = true;
      }
    }
  
    if (bSoData) {
       if (bdatavalida) 
         bvalida = true;
       else 
         bvalida = false;
    } else {
      if (bdatavalida) {
          shora = sDataHora.substr(11,2);
          nhora = atoi(shora.c_str());
          smin = sDataHora.substr(14,2);
          nmin = atoi(smin.c_str());
          sseg = sDataHora.substr(17,2);
          nseg = atoi(sseg.c_str());
  
          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = true;
            }
          }
  
          if (bhoravalida) 
            bvalida = true;
          else 
            bvalida = false;
      } else
        bvalida = false;
    }
  } else 
     bvalida = false;

return bvalida;
}

char* CRotinasGlobais::FormataDataHoraStr(struct tm* sTempo, 
  string sFrmtData, string sFrmtHora) {
char *sDataHora = alocaString(TAM_MAX_STR);
string sTemp;

if (sFrmtData.length() > 0 && sFrmtHora.length() > 0)
  sTemp = sFrmtData + " " + sFrmtHora;
else if (sFrmtData.length() > 0)
  sTemp = sFrmtData;
else if (sFrmtHora.length() > 0)
  sTemp = sFrmtHora;

strftime(sDataHora, TAM_MAX_STR, sTemp.c_str(), sTempo);
return sDataHora;
}

char* CRotinasGlobais::retDataHoraStr(bool bData, bool bHora)
{ char* sDataHora = alocaString(TAM_MAX_STR);
  time_t agora;   
  struct tm* sTempo;

  time(&agora);
  sTempo = localtime(&agora); 

if (bData && bHora)
  strcpy(sDataHora, FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S"));
else if (bData)
  strcpy(sDataHora, FormataDataHoraStr(sTempo, "%d/%m/%Y", ""));
else if (bHora)
  strcpy(sDataHora, FormataDataHoraStr(sTempo, "", "%H:%M:%S"));

return sDataHora;
}

char* CRotinasGlobais::ConverteDataHoraStr(string sDTHR, 
  bool DMY_ou_YMD, string sFrmtData, string sFrmtHora)
{ char* sDataHora = alocaString(TAM_MAX_STR);
  struct tm sTempo;

if (sFrmtData.length() > 0) {
  if (DMY_ou_YMD) {
    sTempo.tm_mday = atoi(sDTHR.substr(0, 2).c_str());
    sTempo.tm_mon = atoi(sDTHR.substr(3, 2).c_str());
    sTempo.tm_year = atoi(sDTHR.substr(6, 4).c_str());
  } else {
    sTempo.tm_year = atoi(sDTHR.substr(0, 4).c_str());
    sTempo.tm_mon = atoi(sDTHR.substr(5, 2).c_str());
    sTempo.tm_mday = atoi(sDTHR.substr(8, 2).c_str());
  }
  sTempo.tm_mon -= 1;
  sTempo.tm_year -= 1900;
}

if (sFrmtHora.length() > 0) {
  sTempo.tm_hour = atoi(sDTHR.substr(11, 2).c_str());
  sTempo.tm_min = atoi(sDTHR.substr(14, 2).c_str());
  sTempo.tm_sec = atoi(sDTHR.substr(17, 2).c_str());
}

sDataHora = FormataDataHoraStr(&sTempo,sFrmtData,sFrmtHora);

return sDataHora;
}

bool CRotinasGlobais::ConectaBanco(string sBancoDeDados, 
  string sLogin, string sSenha) 
{
char ISC_FAR *params = NULL;
short nparams = 0;
char ISC_FAR *d, *p, *copia;
long l, sweep_interval = 16384;
long status[20];
char sTemp[TAM_MAX_STR * 2];
  
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
                 isc_dpb_user_name, sLogin.c_str(),
                 isc_dpb_password, sSenha.c_str(),  NULL);

  if (isc_attach_database(status, 0,
             (char*)sBancoDeDados.c_str(), &gConexao, nparams, params)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NCONBANCO, isc_sqlcode(status));
    fl_alert(sTemp);
    return false;
  }
  return true;
}

VOID CRotinasGlobais::DisconectaBanco() {
long status[20];
char sTemp[TAM_MAX_STR * 2];

  if (isc_detach_database(status, &gConexao)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NDCOBANCO, isc_sqlcode(status));
    fl_alert(sTemp);
  }
}

bool CRotinasGlobais::AtualizaDados(CONEXAO hBancoLocal, string sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
long status[20];
char sTemp[TAM_MAX_STR * 2];

  if (isc_start_transaction(status, &hTransacao, 1, &hBancoLocal, 0, NULL)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NINITRAN, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }
  if (isc_dsql_execute_immediate(
          status, &hBancoLocal, &hTransacao, 0, (char*)sSql.c_str(), 1, NULL)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NCEXECSQL, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }
  if (isc_commit_transaction(status, &hTransacao)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NFINTRAN, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }
  return bret;
}

bool CRotinasGlobais::PreConsultaDados(CONEXAO hBancoLocal, string sSql, 
  isc_tr_handle *hTransacao, isc_stmt_handle *hstmtLocal, XSQLDA **sqlda) {
bool bret = true;
long status[20];
char sTemp[TAM_MAX_STR * 2];

  if (isc_start_transaction(status, hTransacao, 1, &hBancoLocal, 0, NULL)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NINITRAN, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }

  if (isc_dsql_allocate_statement(status, &hBancoLocal, hstmtLocal)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NALOCHSTM, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }

  /* Aloca SQLDA com um tamanho mínimo. */
  (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH(1));
  (*sqlda)->sqln = 1;
  (*sqlda)->version = 1;

  if (isc_dsql_prepare(status, hTransacao, hstmtLocal, 0, 
    (char*)sSql.c_str(), 1, (*sqlda))) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NCPREPSQL, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;    
  }
  return bret;
}

bool CRotinasGlobais::PosConsultaDados(isc_tr_handle *hTransacao, 
                              isc_stmt_handle *hstmtLocal) {
bool bret = true;
long status[20];
char sTemp[TAM_MAX_STR * 2];

  if (isc_dsql_free_statement(status, hstmtLocal, DSQL_drop)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NLIBTRAN, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }
  if (isc_commit_transaction(status, hTransacao)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NFINTRAN, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }
  return bret;
}

bool CRotinasGlobais::DescreveProcedimento(isc_stmt_handle hstmtLocal, XSQLDA **sqlda,
  int *nQtdCols, char *sCampo[], float dCampo[], short nsCampo[], 
  long tsCampo[], long nlCampo[], SQLVARCHAR varCampo[]) {
bool bret = true;
short flag = 0;
int nCol, nNulo;
long status[20];
char sTemp[TAM_MAX_STR * 2];

  /* Descreve o procedimento. */
  if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_DESCPROC, isc_sqlcode(status));
    fl_alert(sTemp);
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
        sprintf(sTemp, "%s - SQLCODE: %d", STR_DESCPROC, isc_sqlcode(status));
        fl_alert(sTemp);
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
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_LONG + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &nlCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_LONG + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else if ((*sqlda)->sqlvar[nCol].sqltype == (SQL_VARYING + nNulo)) {
      (*sqlda)->sqlvar[nCol].sqldata = (char *) &varCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_VARYING + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    } else {
      (*sqlda)->sqlvar[nCol].sqldata = sCampo[nCol];
      (*sqlda)->sqlvar[nCol].sqltype = SQL_TEXT + nNulo;
      (*sqlda)->sqlvar[nCol].sqlind  = &flag;
    }
  }

  return bret;
}

bool CRotinasGlobais::ConsultaDados(CONEXAO hBancoLocal, string sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
isc_stmt_handle hstmtLocal = NULL;
long  status_fetch;
XSQLDA *sqlda;
char *sCampo[QTD_MAX_COL];
float dCampo[QTD_MAX_COL];
short nsCampo[QTD_MAX_COL];
long tsCampo[QTD_MAX_COL];
long nlCampo[QTD_MAX_COL];
SQLVARCHAR varCampo[QTD_MAX_COL];
int nCol, nQtdCols;
long status[20];
char sTemp[TAM_MAX_STR * 2];

  bret = PreConsultaDados(hBancoLocal, sSql.c_str(), &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = alocaString(TAM_MAX_STR);

  bret = DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NCEXECSQL, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  if (status_fetch == 0) 
    bret = true;
  else
    bret = false;

  PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

bool CRotinasGlobais::ConsultaDadosLista(CONEXAO hBancoLocal, 
                                    LISTAMSTR *lstLocal, string sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
isc_stmt_handle hstmtLocal = NULL;
XSQLDA *sqlda;
long  status_fetch;
char *sCampo[QTD_MAX_COL];
float dCampo[QTD_MAX_COL];
short nsCampo[QTD_MAX_COL];
long tsCampo[QTD_MAX_COL];
long nlCampo[QTD_MAX_COL];
SQLVARCHAR varCampo[QTD_MAX_COL];
struct tm mTempo;
int nCol, nQtdCols, nNulo;
long status[20];
LPTSTR sLinha[QTD_MAX_COL];
char sTemp[TAM_MAX_STR * 2];
INT nRad = 10;

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sLinha[nCol] = alocaString(TAM_MAX_STR);

  bret = PreConsultaDados(hBancoLocal, sSql.c_str(), &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = alocaString(TAM_MAX_STR);

  bret = DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    sprintf(sTemp, "%s - SQLCODE: %d", STR_NCEXECSQL, isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }

  *lstLocal = ListaStr->iniciaM();
  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  while (status_fetch == 0) {

    for (nCol = 0; nCol < nQtdCols; nCol++) {
      /* verifica se é nulo */
      if (sqlda->sqlvar[nCol].sqltype & 1)
        nNulo = 1;    
      else
        nNulo = 0;
      if (sqlda->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
        gcvt(dCampo[nCol], nRad, sLinha[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
        itoa(nsCampo[nCol], sLinha[nCol], 10);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_LONG + nNulo)) {
        itoa(nlCampo[nCol], sLinha[nCol], 10);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
        isc_decode_timestamp((ISC_TIMESTAMP *)&tsCampo[nCol], &mTempo);                  
        sLinha[nCol] = FormataDataHoraStr(&mTempo, "%d/%m/%Y", "%H:%M:%S");
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_VARYING + nNulo)) {
        varCampo[nCol].vary_string[varCampo[nCol].vary_length] = '\0';
        sLinha[nCol] = varCampo[nCol].vary_string;
      } else {
        sCampo[nCol][sqlda->sqlvar[nCol].sqllen] = '\0';
        sLinha[nCol] = sCampo[nCol];
      }            
    }
    ListaStr->insereFimM(lstLocal, sLinha);
    status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  }

  if (status_fetch != 100L) {
    sprintf(sTemp, "SQLCODE: %d", isc_sqlcode(status));
    fl_alert(sTemp);
    bret = false;
  }
  PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

bool CRotinasGlobais::ValidaCampo(string sCampo, string sMensagemErro)
{
  if (sCampo.length()==0) {
    fl_alert(sMensagemErro.c_str());
  	return true;
  } else
	  return false;
}

string CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR *Campos, 
            string sTextoSql, string sMensagemErro)
{
  if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {  	
    return ListaStr->pesquisaItemOrdM((*Campos),1,0);
  } else {
	  fl_alert(sMensagemErro.c_str());
    return "";
  }
}

bool CRotinasGlobais::VerificaItemLista(Fl_Browser *lstLista, string sItem) {
int nLinha;
bool bret = false;

  for (nLinha = 1; nLinha <= lstLista->size(); nLinha++) {
    if (strcmp(lstLista->text(nLinha), sItem.c_str())==0)
      bret = true;
    else
      bret = false;
  }
  return bret;
}

void CRotinasGlobais::AdicionaItemLista(Fl_Browser *lstLista,
     LISTASTR *slCodLista, Fl_Input *sCampoCodigo, Fl_Input *sCampoDesc)
{
string sItems, sCodigo, sDesc;

if (strlen(sCampoDesc->value()) > 0) {

 sCodigo = sCampoCodigo->value();
 sDesc = sCampoDesc->value();

 sItems = sCodigo + " - " + sDesc;

 if (VerificaItemLista(lstLista, sItems)==false) { 
 	 ListaStr->insereFim(slCodLista, (char*)sCodigo.c_str()); 
   sItems = "@f" + sItems;
   lstLista->add(sItems.c_str());
 }
 sCampoCodigo->value("");
 sCampoDesc->value("");
}

}

void CRotinasGlobais::RemoveItemLista(Fl_Browser *lstLista, 
                                      LISTASTR *slCodLista)
{
int nSelIndice;

 if (lstLista->size() > 0) {   
   nSelIndice = lstLista->value();
   if (nSelIndice > 0) {
	   ListaStr->removeItemOrd(slCodLista, nSelIndice, true);
	   lstLista->remove(nSelIndice);
   }	
 }
}

void CRotinasGlobais::AdicionaValoresLista(string sTextoSql, 
                      Fl_Browser *lstLista, LISTASTR *slCodLista)
{
  LISTAMSTR Campos, local;
  string sItems, sCodigo;

  lstLista->clear();
  (*slCodLista) = ListaStr->inicia();

  if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
	  for (local = Campos; local != NULL; local = local->proximo) {	
	    ListaStr->insereFim(slCodLista, local->str[0]);
	    sItems = "@f";
      sItems = sItems + local->str[0] + " - " + local->str[1];
      lstLista->add(sItems.c_str());
      sItems = "";
	  }      
    ListaStr->liberaM(Campos);
    ListaStr->liberaM(local);   
    lstLista->select(1);
  }
}

string CRotinasGlobais::setLargura(string sTexto, int nTam) {
unsigned int ncont;
string sret = "";

  if ((nTam-sTexto.length()) > 0) {
    for(ncont = 0; ncont < nTam-sTexto.length(); ncont++)
      sret = sret + " ";
  }
  sret = sTexto + sret;
  return sret;
}

void CRotinasGlobais::AdicionaLinhasBrowser(Fl_Browser *browser, 
  LISTAMSTR sLinhas, int nQtdCol, int nLarguras[], string sRotulos[]) {
LISTAMSTR local;
string sTemp;
int nCol;

  browser->clear();
  for (nCol = 0; nCol < nQtdCol; nCol++) {
    if (nCol == 0)
      sTemp = setLargura(sRotulos[nCol], nLarguras[nCol]);
    else
      sTemp = sTemp + "|" + setLargura(sRotulos[nCol], nLarguras[nCol]);
  }
  sTemp = "@f@b@_" + sTemp;
  browser->add(sTemp.c_str());

  for (local = sLinhas; local != NULL; local = local->proximo) {
    for (nCol = 0; nCol < nQtdCol; nCol++) {
      if (nCol == 0)
        sTemp = setLargura(local->str[nCol], nLarguras[nCol]);
      else
        sTemp = sTemp + "|" + setLargura(local->str[nCol], nLarguras[nCol]);
    }
    sTemp = "@f" + sTemp;
    browser->add(sTemp.c_str());
  }
  browser->select(2);
}

