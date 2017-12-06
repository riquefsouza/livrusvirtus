#include "resource.h"
#include "RotinasGlobais.h"
#include "Principal.h"

#include <ibase.h>

CONEXAO  gConexao;

wxString Rotinas_sBarraLogin;
wxString Rotinas_sUsuarioLogin;
wxString Rotinas_sUsuarioSenha;
wxString Rotinas_sCodigoSelecionado;
wxString Rotinas_sPreco;
wxString Rotinas_sQtdEstoque;
//wxString Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
wxString Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

CRotinasGlobais *Rotinas = (CRotinasGlobais *) NULL;

CRotinasGlobais::CRotinasGlobais() { }

CRotinasGlobais::~CRotinasGlobais() { }

bool CRotinasGlobais::ValidaFloat(wxString sNum) {
double nNum;
bool bret = false;

 if (sNum.Len() > 0) {        
   if (sNum.ToDouble(&nNum)) {
      if (nNum >= 0.01)
        bret = true;
      else {
        wxMessageBox(wxT(STR_NUMINV), wxT("Erro"), wxOK | wxICON_ERROR);
        bret = false;
      }
   } else {
      wxMessageBox(wxT(STR_NUMINV), wxT("Erro"), wxOK | wxICON_ERROR);
      bret = false;
    }
 } else
   bret = false;

 return bret;
} 

wxString CRotinasGlobais::VirgulaParaPonto(wxString sNum, bool bRevertido) {

 if (bRevertido)
   sNum.Replace(wxT("."),wxT(","),true);
 else
   sNum.Replace(wxT(","),wxT("."),true);

 return sNum;
}

int CRotinasGlobais::modulo11(wxString svalor, int ndig) {
int ncont, nsoma, npos;
long nvalor = 0;
wxString slocal, sres;
int nret = 0;

 ncont=0;
 while (ncont < 11) {
   slocal=svalor.Mid(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres = slocal.Mid(ncont,1);
   sres.ToLong(&nvalor,10);

   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   nret = 0;
 else
   nret = nsoma;

 return nret;
}

bool CRotinasGlobais::validaCPF(wxString cpf) {
wxString scpf;
long nNum1 = 0;
long nNum2 = 0;
wxString sNum1, sNum2;
bool bret = false;

if (cpf.Length()==14) {
  scpf = wxString::Format("%s%s%s%s", cpf.Mid(0,3).c_str(),
    cpf.Mid(4,3).c_str(),cpf.Mid(8,3).c_str(),cpf.Mid(12,2).c_str());
  sNum1 = cpf.Mid(12,1);
  sNum1.ToLong(&nNum1, 10);
  sNum2 = cpf.Mid(13,1);
  sNum2.ToLong(&nNum2, 10);
  if ( (modulo11(scpf,1)==nNum1) && (modulo11(scpf,2)==nNum2) )
    bret = true;
  else
    bret = false;
} else
  bret = false;

return bret;
}

bool CRotinasGlobais::validaISBN(wxString isbn) {
 wxString sisbn, sdigito, snum;
 int nsoma, ncont;
 long nvalor = 0;
 bool bret = false;

if (isbn.Length()==13) {
  sdigito = isbn.substr(isbn.Length()-1, 1);
  sisbn.Clear();
  for(ncont = 0; ncont < abs(isbn.length()-1); ncont++)  {
    if (isbn.Mid(ncont,1).Cmp(wxT("-"))!=0)
      sisbn += isbn.Mid(ncont,1);
  }
  if (sdigito.Cmp(wxT("X"))==0)
    nsoma = 10;
  else {
    sdigito.ToLong(&nvalor,10);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.Mid(ncont-1, 1);
    snum.ToLong(&nvalor,10);
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    bret = true;
  else
    bret = false;
} else
  bret = false;

 return bret;
}

bool CRotinasGlobais::validaDataHora(wxString sDataHora, bool bSoData)
{ bool bvalida, bdatavalida, bhoravalida;
  wxString sdia, smes, sano, shora, smin, sseg;
  unsigned long ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;

  if (sDataHora.Len()==ntam) {
    sdia = sDataHora.Mid(0,2);
    sdia.ToULong(&ndia);
    smes = sDataHora.Mid(3,2);
    smes.ToULong(&nmes);
    sano = sDataHora.Mid(6,4);
    sano.ToULong(&nano);
  
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
          shora = sDataHora.Mid(11,2);
          shora.ToULong(&nhora);
          smin = sDataHora.Mid(14,2);
          smin.ToULong(&nmin);
          sseg = sDataHora.Mid(17,2);
          sseg.ToULong(&nseg);
  
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

wxString CRotinasGlobais::FormataDataHoraStr(wxDateTime sTempo, 
  wxString sFrmtData, wxString sFrmtHora)
{ wxString sDataHora;

if (sFrmtData.Len() > 0 && sFrmtHora.Len() > 0)
  sDataHora = sTempo.Format(sFrmtData + " " + sFrmtHora);
else if (sFrmtData.Len() > 0)
  sDataHora = sTempo.Format(sFrmtData);
else if (sFrmtHora.Len() > 0)
  sDataHora = sTempo.Format(sFrmtHora);

  return sDataHora;
}

wxString CRotinasGlobais::retDataHoraStr(bool bData, bool bHora)
{ wxString sDataHora;
  wxDateTime sTempo = wxDateTime::Now();

if (bData && bHora)
  sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S");
else if (bData)
  sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "");
else if (bHora)
  sDataHora = FormataDataHoraStr(sTempo, "", "%H:%M:%S");

return sDataHora;
}

wxString CRotinasGlobais::ConverteDataHoraStr(wxString sDTHR, bool DMY_ou_YMD, 
  wxString sFrmtData, wxString sFrmtHora)
{ wxString sDataHora;
  wxDateTime mTempo;
  unsigned long ndia = 1, nmes = 0, nano = 1, nhora = 0, nmin = 0, nseg = 0;

if (sFrmtData.Len() > 0) {
  if (DMY_ou_YMD) {
    sDTHR.Mid(0,2).ToULong(&ndia,10);
    sDTHR.Mid(3,2).ToULong(&nmes,10);
    sDTHR.Mid(6,4).ToULong(&nano,10);
  } else {
    sDTHR.Mid(0,4).ToULong(&nano,10);
    sDTHR.Mid(5,2).ToULong(&nmes,10);
    sDTHR.Mid(8,2).ToULong(&ndia,10);
  }
}
if (sFrmtHora.Len() > 0) {
  sDTHR.Mid(11,2).ToULong(&nhora,10);
  sDTHR.Mid(14,2).ToULong(&nmin,10);
  sDTHR.Mid(17,2).ToULong(&nseg,10);
}
mTempo.Set(ndia, wxDateTime::Month(nmes-1), nano, nhora, nmin, nseg, 0);
sDataHora = FormataDataHoraStr(mTempo,sFrmtData,sFrmtHora);
return sDataHora;
}

bool CRotinasGlobais::ConectaBanco(wxString sBancoDeDados, 
      wxString sLogin, wxString sSenha) {
char ISC_FAR *params = NULL;
short nparams = 0;
char ISC_FAR *d, *p, *copia;
long l, sweep_interval = 16384;
long status[20];
wxString sTemp;
  
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
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NCONBANCO, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    return false;
  }
  return true;
}

void CRotinasGlobais::DisconectaBanco() {
long status[20];
wxString sTemp;

  if (isc_detach_database(status, &gConexao)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NDCOBANCO, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
  }
}

bool CRotinasGlobais::AtualizaDados(CONEXAO hBancoLocal, wxString sSql) {
bool bret = true;
isc_tr_handle hTransacao = NULL;
long status[20];
wxString sTemp;

  if (isc_start_transaction(status, &hTransacao, 1, &hBancoLocal, 0, NULL)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NINITRAN, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  if (isc_dsql_execute_immediate(status, &hBancoLocal, &hTransacao, 
      0, (char*)sSql.c_str(), 1, NULL)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NCEXECSQL, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  if (isc_commit_transaction(status, &hTransacao)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NFINTRAN, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  return bret;
}

bool CRotinasGlobais::PreConsultaDados(CONEXAO hBancoLocal, wxString sSql, 
  isc_tr_handle *hTransacao, isc_stmt_handle *hstmtLocal, XSQLDA **sqlda) {
bool bret = true;
long status[20];
wxString sTemp;

  if (isc_start_transaction(status, hTransacao, 1, &hBancoLocal, 0, NULL)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NINITRAN, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  if (isc_dsql_allocate_statement(status, &hBancoLocal, hstmtLocal)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NALOCHSTM, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }

  /* Aloca SQLDA com um tamanho mínimo. */
  (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH(1));
  (*sqlda)->sqln = 1;
  (*sqlda)->version = 1;

  if (isc_dsql_prepare(status, hTransacao, hstmtLocal, 0, 
    (char*)sSql.c_str(), 1, (*sqlda))) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NCPREPSQL, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  return bret;
}

bool CRotinasGlobais::PosConsultaDados(isc_tr_handle *hTransacao, 
                              isc_stmt_handle *hstmtLocal) {
bool bret = true;
long status[20];
wxString sTemp;

  if (isc_dsql_free_statement(status, hstmtLocal, DSQL_drop)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NLIBTRAN,
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  if (isc_commit_transaction(status, hTransacao)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NFINTRAN, 
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  return bret;
}

bool CRotinasGlobais::DescreveProcedimento(isc_stmt_handle hstmtLocal, 
  XSQLDA **sqlda, int *nQtdCols, char *sCampo[], float dCampo[], 
  short nsCampo[], long tsCampo[], long nlCampo[], SQLVARCHAR varCampo[]) {
bool bret = true;
short flag = 0;
int nCol, nNulo;
long status[20];
wxString sTemp;

  /* Descreve o procedimento. */
  if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_DESCPROC,
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
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
        sTemp = wxString::Format("%s - SQLCODE: %d", STR_DESCPROC,
          isc_sqlcode(status));
        wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
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

bool CRotinasGlobais::ConsultaDados(CONEXAO hBancoLocal, wxString sSql) {
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
wxString sTemp;

  bret = PreConsultaDados(hBancoLocal, sSql.c_str(), &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = (char*)malloc(TAM_MAX_STR);

  bret = DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NCEXECSQL,
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
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
                                    LISTAMSTR *lstLocal, wxString sSql) {
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
wxString sTemp;
wxString sLinha;
wxDateTime smTempo;

  bret = PreConsultaDados(hBancoLocal, sSql.c_str(), &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = (char*)malloc(TAM_MAX_STR);

  bret = DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    sTemp = wxString::Format("%s - SQLCODE: %d", STR_NCEXECSQL,
      isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }

  for (nCol = 0; nCol < nQtdCols; nCol++)
    lstLocal->col[nCol].Clear();

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  while (status_fetch == 0) {

    for (nCol = 0; nCol < nQtdCols; nCol++) {
      /* verifica se é nulo */
      if (sqlda->sqlvar[nCol].sqltype & 1)
        nNulo = 1;    
      else
        nNulo = 0;
      if (sqlda->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
        sLinha = wxString::Format("%.2f", dCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
        sLinha = wxString::Format("%d", nsCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_LONG + nNulo)) {
        sLinha = wxString::Format("%d", nlCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
        isc_decode_timestamp((ISC_TIMESTAMP *)&tsCampo[nCol], &mTempo);                  
        smTempo.Set(mTempo);
        sLinha = FormataDataHoraStr(smTempo, "%d/%m/%Y", "%H:%M:%S");
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_VARYING + nNulo)) {
        varCampo[nCol].vary_string[varCampo[nCol].vary_length] = '\0';
        sLinha = varCampo[nCol].vary_string;
      } else {
        sCampo[nCol][sqlda->sqlvar[nCol].sqllen] = '\0';
        sLinha = sCampo[nCol];
      }
      lstLocal->col[nCol].Add(sLinha); 
    }
    status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  }

  if (status_fetch != 100L) {
    sTemp = wxString::Format("%s - SQLCODE: %d", isc_sqlcode(status));
    wxMessageBox(sTemp, wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  }
  PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

bool CRotinasGlobais::ValidaCampo(wxString sCampo, wxString sMensagemErro) {
bool bret = false;
  if (sCampo.Len()==0) {
    wxMessageBox(sMensagemErro, wxT("Erro"), wxOK | wxICON_ERROR);
	  bret = true;
  } else
	  bret = false;

  return bret;
}

wxString CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR *Campos, 
  wxString sTextoSql, wxString sMensagemErro) {
wxString sret = "";

  if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {
    sret = Campos->col[1].Item(0);
  } else {
    wxMessageBox(sMensagemErro, wxT("Erro"), wxOK | wxICON_ERROR);
    sret = "";
  }
 return sret;
}

void CRotinasGlobais::AdicionaItemLista(wxListBox *lstLista,
     LISTASTR *slCodLista, wxTextCtrl *sCampoCodigo, wxTextCtrl *sCampoDesc)
{
wxString sItems, sCodigo, sDesc;

if (sCampoDesc->GetValue().Len() > 0) {

 sCodigo = sCampoCodigo->GetValue();
 sDesc = sCampoDesc->GetValue();

 sItems = wxString::Format("%s - %s", sCodigo.c_str(), sDesc.c_str());

 if (lstLista->FindString(sItems)==-1) {   
	slCodLista->col.Add(sCodigo);
	lstLista->Append(sItems);
 }
 sCampoCodigo->Clear();
 sCampoDesc->Clear();
}

}

void CRotinasGlobais::RemoveItemLista(wxListBox *lstLista, LISTASTR *slCodLista)
{
int nSelIndice;

 if (lstLista->GetCount() > 0) {   
   nSelIndice = lstLista->GetSelection();
   if (lstLista->Selected(nSelIndice)) {
	   slCodLista->col.Remove(nSelIndice);
	   lstLista->Delete(nSelIndice);
   }	
 }
}

void CRotinasGlobais::AdicionaValoresLista(wxString sTextoSql, 
    wxListBox *lstLista, LISTASTR *slCodLista)
{ 
  LISTAMSTR Campos;
  wxString sItems, sCodigo, sDesc;
  unsigned long nLinha;

  lstLista->Clear();
  slCodLista->col.Clear();
  if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
    for (nLinha = 0; nLinha < Campos.col[0].Count(); nLinha++) {
      sCodigo = Campos.col[0].Item(nLinha);
      sDesc = Campos.col[1].Item(nLinha);

	    slCodLista->col.Add(sCodigo);
      sItems = wxString::Format("%s - %s", sCodigo.c_str(), sDesc.c_str());
	    lstLista->Append(sItems);
	  }      
  }
}

void CRotinasGlobais::AdicionaColunasGrid(wxGrid *grid, 
  int nPosIni, int nQtdCols, int nLargura[], wxString sRotulos[])
{
 int nPos, nCont;

 if (nPosIni > 0)
   grid->AppendCols(nQtdCols);
 nCont = 0;
 for (nPos = nPosIni; nPos < (nPosIni+nQtdCols); nPos++) {
   grid->SetColSize(nPos, nLargura[nCont]);
   grid->SetColLabelValue(nPos, sRotulos[nCont]);
   nCont++;
 }
}

void CRotinasGlobais::AdicionaLinhasGrid(wxGrid *grid, 
  LISTAMSTR lstLinhas, unsigned long nQtdCol)
{
  unsigned long nCol, nLinha;

  grid->DeleteRows(0,grid->GetNumberRows(),true);  
  grid->AppendRows(lstLinhas.col[0].Count(), true);
  for (nCol = 0; nCol < nQtdCol; nCol++) {
    for (nLinha = 0; nLinha < lstLinhas.col[nCol].Count(); nLinha++) {
      grid->SetCellValue(nLinha, nCol, lstLinhas.col[nCol].Item(nLinha));
    }      
  }
}

