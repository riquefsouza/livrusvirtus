#include "stdafx.h"

#include <ibase.h>

#include "Livrus.h"
#include "Principal.h"
#include "resource.h"
#include "RotinasGlobais.h"

CONEXAO gConexao;

CString Rotinas_sBarraLogin;
CString Rotinas_sUsuarioLogin;
CString Rotinas_sUsuarioSenha;
CString Rotinas_sCodigoSelecionado;
CString Rotinas_sPreco;
CString Rotinas_sQtdEstoque;
//CString Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
CString Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

CRotinasGlobais::CRotinasGlobais() {
}

BOOL CRotinasGlobais::VerificaInstancia(LPTSTR sNomeClasse, LPTSTR sNomeJanela)
{
  CWnd *pWndAnterior, *pWndFilha;

  if (pWndAnterior = CWnd::FindWindow(sNomeClasse,sNomeJanela))
  {
    pWndFilha = pWndAnterior->GetLastActivePopup();

    AfxMessageBox(Rotinas->lerStr(STR_APPEXEC), 
      MB_ICONEXCLAMATION | MB_OK, 0);

    if (pWndAnterior->IsIconic())
       pWndAnterior->ShowWindow(SW_RESTORE);

    pWndFilha->SetForegroundWindow();

    return FALSE;
  }
  return TRUE;
}

VOID CRotinasGlobais::habilitaSubMenu(INT nPosSubMenu, INT idSubMenu, 
    BOOL bHabilita)
{
 if (bHabilita)
   AfxGetApp()->GetMainWnd()->GetMenu()->GetSubMenu(nPosSubMenu)->
     EnableMenuItem(idSubMenu, MF_BYCOMMAND | MF_ENABLED);
 else  
   AfxGetApp()->GetMainWnd()->GetMenu()->GetSubMenu(nPosSubMenu)->
     EnableMenuItem(idSubMenu, MF_BYCOMMAND | MF_GRAYED);

 AfxGetApp()->GetMainWnd()->DrawMenuBar();
}

LPTSTR CRotinasGlobais::alocaString(INT ntam)
{ LPTSTR strlocal;

 strlocal = LPTSTR(GlobalAlloc(GPTR, ntam));
 return strlocal;
}

BOOL CRotinasGlobais::ValidaFloat(CString sNum)
{
 LPCTSTR sLocalNum;

 if (sNum.GetLength() > 0) {    
    sLocalNum = sNum.operator LPCTSTR();
    if (atof(sLocalNum) >= 0.01)
      return TRUE;
    else {
      AfxMessageBox(lerStr(STR_NUMINV), MB_ICONERROR | MB_OK, 0);
      return FALSE;
    }
 } else
   return FALSE;
} 

CString CRotinasGlobais::VirgulaParaPonto(CString sNum, BOOL bRevertido) 
{
if (bRevertido) 
  sNum.Replace('.',',');
else
  sNum.Replace(',','.');

return sNum;
}

INT CRotinasGlobais::modulo11(CString svalor, INT ndig)
{ INT ncont, nsoma, nvalor, npos;
  CString slocal, sres;
 
 slocal.Empty(); 
 ncont=0;
 while (ncont <= 11) {
   slocal = svalor.Mid(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont <= 11) {
   sres = slocal.Mid(ncont,1);
   nvalor = atoi(sres);
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   return(0);
 else
   return(nsoma);
}

BOOL CRotinasGlobais::validaCPF(CString cpf)
{ CString scpf, sres;
  INT nvalor1, nvalor2;

if (cpf.GetLength()==14) {
  scpf.Format("%s%s%s%s",cpf.Mid(0,3),cpf.Mid(4,3),cpf.Mid(8,3),cpf.Mid(12,2));
  sres = cpf.Mid(12,1);
  nvalor1 = atoi(sres);
  sres = cpf.Mid(13,1);
  nvalor2 = atoi(sres);
  if ((modulo11(scpf,1)==nvalor1) && (modulo11(scpf,2)==nvalor2))
    return TRUE;
  else
    return FALSE;
} else
  return FALSE;
}

BOOL CRotinasGlobais::validaISBN(CString isbn)
{ CString sisbn, sdigito, snum;
  INT nvalor, nsoma, ncont;

if (isbn.GetLength()==13) {
  sdigito = isbn.Mid(isbn.GetLength()-1, 1);
  sisbn.Empty();
  for(ncont = 0; ncont < abs(isbn.GetLength()-1); ncont++)  {
    if (isbn.Mid(ncont,1).Compare("-")!=0)
      sisbn += isbn.Mid(ncont,1);
  }
  if (sdigito.Compare("X")==0)
    nsoma = 10;
  else {
    nvalor = atoi(sdigito);
    nsoma = nvalor;
  } 
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.Mid(ncont-1, 1);
    nvalor = atoi(snum);
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    return TRUE;
  else
    return FALSE;
} else
  return FALSE;
}

BOOL CRotinasGlobais::validaDataHora(CString sDataHora, BOOL bSoData)
{ BOOL bvalida, bdatavalida, bhoravalida;
  CString sdia, smes, sano, shora, smin, sseg;
  INT ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = FALSE;
bdatavalida = FALSE;
bhoravalida = FALSE;
nudiames = 0;
if (bSoData==TRUE) ntam=10;
else ntam=19;

  if (lstrlen(sDataHora)==ntam) {
    sdia = sDataHora.Mid(0,2);
    ndia = atoi(sdia);
    smes = sDataHora.Mid(3,2);
    nmes = atoi(smes);
    sano = sDataHora.Mid(6,4);
    nano = atoi(sano);
  
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
             bdatavalida = TRUE;
      }
    }
  
    if (bSoData) {
       if (bdatavalida) 
         bvalida = TRUE;
       else 
		 bvalida = FALSE;
    } else {
      if (bdatavalida) {
          shora = sDataHora.Mid(11,2);
          nhora = atoi(shora);
          smin = sDataHora.Mid(14,2);
          nmin = atoi(smin);
          sseg = sDataHora.Mid(17,2);
          nseg = atoi(sseg);
  
          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = TRUE;
            }
          }
  
          if (bhoravalida) 
  			    bvalida = TRUE;
          else 
  			    bvalida = FALSE;
      } else
        bvalida = FALSE;
    }
  } else 
     bvalida = FALSE;

return bvalida;
}

CString CRotinasGlobais::FormataDataHoraStr(SYSTEMTIME sTempo, CString sFrmtData, 
    CString sFrmtHora)
{ CString sDataHora;
  TCHAR sData[TAM_MAX_STR], sHora[TAM_MAX_STR];  
  LCID local_id;

sDataHora.Empty();

//local_id = MAKELCID(
//    MAKELANGID(LANG_PORTUGUESE, SUBLANG_PORTUGUESE_BRAZILIAN), SORT_DEFAULT);
local_id = LOCALE_SYSTEM_DEFAULT; //LOCALE_USER_DEFAULT

if (sFrmtData.GetLength() > 0)
  GetDateFormat(local_id, 0, &sTempo, sFrmtData, sData, TAM_MAX_STR);
if (sFrmtHora.GetLength() > 0)
  GetTimeFormat(local_id, 0, &sTempo, sFrmtHora, sHora, TAM_MAX_STR);

if (sFrmtData.GetLength() > 0 && sFrmtHora.GetLength() > 0)
  sDataHora.Format("%s %s", sData, sHora);
else if (sFrmtData.GetLength() > 0)
  sDataHora.Format("%s", sData);
else if (sFrmtHora.GetLength() > 0)
  sDataHora.Format("%s", sHora);

  return sDataHora;
}

CString CRotinasGlobais::retDataHoraStr(BOOL bData, BOOL bHora)
{ CString sDataHora;
  SYSTEMTIME sTempo;
  
  GetSystemTime(&sTempo);
if (bData && bHora)
  sDataHora = FormataDataHoraStr(sTempo, "dd/MM/yyyy", "HH:mm:ss");
else if (bData)
  sDataHora = FormataDataHoraStr(sTempo, "dd/MM/yyyy", "");
else if (bHora)
  sDataHora = FormataDataHoraStr(sTempo, "", "HH:mm:ss");

return sDataHora;
}

CString CRotinasGlobais::ConverteDataHoraStr(CString sDTHR, BOOL DMY_ou_YMD, 
  CString sFrmtData, CString sFrmtHora)
{ CString sDataHora;
  SYSTEMTIME sTempo;

if (sFrmtData.GetLength() > 0) {
  if (DMY_ou_YMD) {
    sTempo.wDay = atoi(sDTHR.Mid(0,2));
    sTempo.wMonth = atoi(sDTHR.Mid(3,2));
    sTempo.wYear = atoi(sDTHR.Mid(6,4));
  } else {
    sTempo.wYear = atoi(sDTHR.Mid(0,4));
    sTempo.wMonth = atoi(sDTHR.Mid(5,2));
    sTempo.wDay = atoi(sDTHR.Mid(8,2));
  }
}
if (sFrmtHora.GetLength() > 0) {
  sTempo.wHour = atoi(sDTHR.Mid(11,2));
  sTempo.wMinute = atoi(sDTHR.Mid(14,2));
  sTempo.wSecond = atoi(sDTHR.Mid(17,2));
  sTempo.wMilliseconds = 0;
}
sDataHora = FormataDataHoraStr(sTempo,sFrmtData,sFrmtHora);
return sDataHora;
}

CString CRotinasGlobais::retTexto(CEdit *cEdit)
{
CString sValor;
cEdit->GetWindowText(sValor);
return sValor;
}

CString CRotinasGlobais::retTexto(CComboBox *cCmb)
{
CString sValor;
cCmb->GetWindowText(sValor);
return sValor;
}

CString CRotinasGlobais::retTexto(CDateTimeCtrl *cDTCtrl)
{
CString sValor;
cDTCtrl->GetWindowText(sValor);
return sValor;
}

VOID CRotinasGlobais::setDataHora(CDateTimeCtrl *cDTCtrl, 
  CString sData, CString sHora)
{ SYSTEMTIME sTempo;

memset(&sTempo, 0, sizeof(sTempo));

if (sData.GetLength() > 0) {
  sTempo.wDay = atoi(sData.Mid(0,2));
  sTempo.wMonth = atoi(sData.Mid(3,2));
  sTempo.wYear = atoi(sData.Mid(6,4));
}
if (sHora.GetLength() > 0) {
  sTempo.wHour = atoi(sHora.Mid(0,2));
  sTempo.wMinute = atoi(sHora.Mid(3,2));
  sTempo.wSecond = atoi(sHora.Mid(6,2));
  sTempo.wMilliseconds = 0;
}
  VERIFY(cDTCtrl->SetTime(&sTempo));
}

CString CRotinasGlobais::retDataHora(CDateTimeCtrl *cDTCtrl, 
  CString sFrmtData, CString sFrmtHora)
{ DWORD dwResultado;
  CString sDTHR;
  SYSTEMTIME sTempo;
  
  dwResultado = cDTCtrl->GetTime(&sTempo);
  if (dwResultado == GDT_VALID)
  {
    if ((cDTCtrl->GetStyle() & DTS_TIMEFORMAT) == DTS_TIMEFORMAT)
       sDTHR = Rotinas->FormataDataHoraStr(sTempo, "", sFrmtHora);
    else
       sDTHR = Rotinas->FormataDataHoraStr(sTempo, sFrmtData,"");
    return sDTHR;
  }
  else
   return "";
}

CString CRotinasGlobais::lerStr(UINT nId)
{
CString sValor;
LPTSTR sTemp;

sTemp = Rotinas->alocaString(TAM_MAX_STR);
LoadString(AfxGetApp()->m_hInstance, nId, sTemp, TAM_MAX_STR);
sValor = sTemp;

return sValor;
}

BOOL CRotinasGlobais::ConectaBanco(CString sBancoDeDados, 
                                   CString sLogin, CString sSenha) {
char ISC_FAR *params = NULL;
short nparams = 0;
char ISC_FAR *d, *p, *copia;
long l, sweep_interval = 16384;
long status[20];
CString sTemp;
  
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
                 isc_dpb_user_name, sLogin.operator LPCTSTR(),
                 isc_dpb_password, sSenha.operator LPCTSTR(),  NULL);

  if (isc_attach_database(status, 0, 
      (LPTSTR)sBancoDeDados.operator LPCTSTR(), &gConexao, nparams, params)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NCONBANCO), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    return FALSE;
  }
  return TRUE;
}

VOID CRotinasGlobais::DisconectaBanco() {
long status[20];
CString sTemp;

  if (isc_detach_database(status, &gConexao)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NDCOBANCO), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
  }
}

BOOL CRotinasGlobais::AtualizaDados(CONEXAO hBancoLocal, CString sSql) {
BOOL bret = TRUE;
isc_tr_handle hTransacao = NULL;
long status[20];
CString sTemp;

  if (isc_start_transaction(status, &hTransacao, 1, &hBancoLocal, 0, NULL)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NINITRAN), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  if (isc_dsql_execute_immediate(status, &hBancoLocal, &hTransacao, 
                                 0, (LPTSTR)sSql.operator LPCTSTR(), 1, NULL)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NCEXECSQL), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  if (isc_commit_transaction(status, &hTransacao)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NFINTRAN), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  return bret;
}

BOOL CRotinasGlobais::PreConsultaDados(CONEXAO hBancoLocal, CString sSql, 
  isc_tr_handle *hTransacao, isc_stmt_handle *hstmtLocal, XSQLDA **sqlda) {
BOOL bret = TRUE;
long status[20];
CString sTemp;

  if (isc_start_transaction(status, hTransacao, 1, &hBancoLocal, 0, NULL)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NINITRAN), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  if (isc_dsql_allocate_statement(status, &hBancoLocal, hstmtLocal)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NALOCHSTM), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }

  /* Aloca SQLDA com um tamanho mínimo. */
  (*sqlda) = (XSQLDA *) malloc(XSQLDA_LENGTH(1));
  (*sqlda)->sqln = 1;
  (*sqlda)->version = 1;

  if (isc_dsql_prepare(status, hTransacao, hstmtLocal, 0, 
    (LPTSTR)sSql.operator LPCTSTR(), 1, (*sqlda))) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NCPREPSQL), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  return bret;
}

BOOL CRotinasGlobais::PosConsultaDados(isc_tr_handle *hTransacao, 
                                    isc_stmt_handle *hstmtLocal) {
BOOL bret = TRUE;
long status[20];
CString sTemp;

  if (isc_dsql_free_statement(status, hstmtLocal, DSQL_drop)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NLIBTRAN), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  if (isc_commit_transaction(status, hTransacao)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NFINTRAN), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  return bret;
}

BOOL CRotinasGlobais::DescreveProcedimento(isc_stmt_handle hstmtLocal, 
  XSQLDA **sqlda, int *nQtdCols, char *sCampo[], float dCampo[], 
  short nsCampo[], long tsCampo[], long nlCampo[], SQLVARCHAR varCampo[]) {
BOOL bret = TRUE;
short flag = 0;
int nCol, nNulo;
long status[20];
CString sTemp;

  /* Descreve o procedimento. */
  if (isc_dsql_describe(status, &hstmtLocal, 1, *sqlda)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_DESCPROC), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
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
        sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_DESCPROC), 
          isc_sqlcode(status));
        AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
        bret = FALSE;
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

BOOL CRotinasGlobais::ConsultaDados(CONEXAO hBancoLocal, CString sSql) {
BOOL bret = TRUE;
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
CString sTemp;

  bret = PreConsultaDados(hBancoLocal, sSql.operator LPCTSTR(), &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = alocaString(TAM_MAX_STR);

  bret = DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NCEXECSQL), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  if (status_fetch == 0) 
    bret = TRUE;
  else
    bret = FALSE;

  PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

BOOL CRotinasGlobais::ConsultaDadosLista(CONEXAO hBancoLocal, 
                                    LISTAMSTR *lstLocal, CString sSql) {
BOOL bret = TRUE;
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
CString sTemp;
CString sLinha;
POSITION pos[QTD_MAX_COL];
SYSTEMTIME smTempo;

  bret = PreConsultaDados(hBancoLocal, sSql.operator LPCTSTR(), &hTransacao, 
    &hstmtLocal, &sqlda);

  for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
    sCampo[nCol] = alocaString(TAM_MAX_STR);

  bret = DescreveProcedimento(hstmtLocal, &sqlda,
    &nQtdCols, sCampo, dCampo, nsCampo, tsCampo, nlCampo, varCampo);

  if (isc_dsql_execute(status, &hTransacao, &hstmtLocal, 1, NULL)) {
    sTemp.Format("%s - SQLCODE: %d", Rotinas->lerStr(STR_NCEXECSQL), 
      isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }

  for (nCol = 0; nCol < nQtdCols; nCol++)
    lstLocal->col[nCol].RemoveAll();

  for (nCol = 0; nCol < nQtdCols; nCol++)
    pos[nCol] = lstLocal->col[nCol].GetHeadPosition();

  status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  while (status_fetch == 0) {

    for (nCol = 0; nCol < nQtdCols; nCol++) {
      /* verifica se é nulo */
      if (sqlda->sqlvar[nCol].sqltype & 1)
        nNulo = 1;    
      else
        nNulo = 0;
      if (sqlda->sqlvar[nCol].sqltype == (SQL_FLOAT + nNulo)) {
        sLinha.Format("%.2f", dCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_SHORT + nNulo)) {
        sLinha.Format("%d", nsCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_LONG + nNulo)) {
        sLinha.Format("%d", nlCampo[nCol]);
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_TIMESTAMP + nNulo)) {
        isc_decode_timestamp((ISC_TIMESTAMP *)&tsCampo[nCol], &mTempo);
        smTempo.wDay = mTempo.tm_mday;
        smTempo.wMonth = mTempo.tm_mon + 1;
        smTempo.wYear = mTempo.tm_year + 1900;
        smTempo.wHour = mTempo.tm_hour;
        smTempo.wMinute = mTempo.tm_min;
        smTempo.wSecond = mTempo.tm_sec;
        smTempo.wMilliseconds = 0;      
        sLinha = FormataDataHoraStr(smTempo, "dd/MM/yyyy", "HH:mm:ss");
      } else if (sqlda->sqlvar[nCol].sqltype == (SQL_VARYING + nNulo)) {
        varCampo[nCol].vary_string[varCampo[nCol].vary_length] = '\0';
        sLinha = varCampo[nCol].vary_string;
      } else {
        sCampo[nCol][sqlda->sqlvar[nCol].sqllen] = '\0';
        sLinha = sCampo[nCol];
      }
      lstLocal->col[nCol].InsertAfter(pos[nCol], sLinha); 
    }
    status_fetch = isc_dsql_fetch(status, &hstmtLocal, 1, sqlda);
  }

  if (status_fetch != 100L) {
    sTemp.Format("SQLCODE: %d", isc_sqlcode(status));
    AfxMessageBox(sTemp, MB_ICONERROR | MB_OK, 0);
    bret = FALSE;
  }
  PosConsultaDados(&hTransacao, &hstmtLocal);
  return bret;
}

BOOL CRotinasGlobais::ValidaCampo(CString sCampo, CString sMensagemErro)
{
  if (sCampo.GetLength()==0) {
    AfxMessageBox(sMensagemErro, MB_ICONERROR | MB_OK, 0);
	return TRUE;
  } else
	return FALSE;
}

CString CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR *Campos, 
            CString sTextoSql, CString sMensagemErro)
{
  POSITION pos;
  if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {  	
    pos = (*Campos).col[1].FindIndex(0);
    return (*Campos).col[1].GetAt(pos);
  } else {
	  AfxMessageBox(sMensagemErro, MB_ICONERROR | MB_OK, 0);
    return "";
  }
}

VOID CRotinasGlobais::AdicionaItemLista(CListBox *lstLista,
     LISTASTR *slCodLista, CEdit *sCampoCodigo, CEdit *sCampoDesc)
{
POSITION pos;
CString sItems, sCodigo, sDesc;

if (sCampoDesc->GetWindowTextLength() > 0) {

 sCodigo = Rotinas->retTexto(sCampoCodigo);
 sDesc = Rotinas->retTexto(sCampoDesc);

 sItems.Format("%s - %s", sCodigo, sDesc);

 if (lstLista->FindString(0, sItems.operator LPCTSTR())==LB_ERR)
 { 
  pos = slCodLista->col.GetHeadPosition();
	slCodLista->col.InsertAfter(pos, sCodigo);
	lstLista->AddString(sItems.operator LPCTSTR());
 }
 sCampoCodigo->SetWindowText("");
 sCampoDesc->SetWindowText("");
}

}

VOID CRotinasGlobais::RemoveItemLista(CListBox *lstLista, LISTASTR *slCodLista)
{
POSITION pos;
INT nSelIndice;

 if (lstLista->GetCount() > 0) {   
   nSelIndice = lstLista->GetCurSel();
   if (lstLista->GetSel(nSelIndice) > 0) {
     pos = slCodLista->col.FindIndex(nSelIndice);
	   slCodLista->col.RemoveAt(pos);
	   lstLista->DeleteString(nSelIndice);
   }	
 }
}

VOID CRotinasGlobais::AdicionaValoresLista(CString sTextoSql, 
    CListBox *lstLista, LISTASTR *slCodLista)
{ POSITION pos[3];
  LISTAMSTR Campos;
  CString sItems, sCodigo, sDesc;

  lstLista->ResetContent();
  slCodLista->col.RemoveAll();
  if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
    pos[0] = Campos.col[0].GetHeadPosition();
    pos[1] = Campos.col[1].GetHeadPosition();
    pos[2] = slCodLista->col.GetHeadPosition();
    while (pos[0] != NULL) {
      sCodigo = Campos.col[0].GetNext(pos[0]);
      sDesc = Campos.col[1].GetNext(pos[1]);
	    slCodLista->col.InsertAfter(pos[2], sCodigo);
	    sItems.Format("%s - %s", sCodigo, sDesc);
	    lstLista->AddString(sItems.operator LPCTSTR());		
	  }      
  }
}

BOOL CRotinasGlobais::VisaoListaInsereColunas(CListCtrl *cVisaoLista, UINT largura[], 
    LISTASTR *sColunas)
{
    LV_COLUMN lvc; 
    POSITION pos;
    INT nColunas;
     
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 
    lvc.fmt = LVCFMT_LEFT; 
    
    nColunas = -1;
    pos = sColunas->col.GetHeadPosition();
    while (pos != NULL) {
   	    nColunas++;    
   	    lvc.cx = largura[nColunas];
        lvc.iSubItem = nColunas; 
        lvc.pszText = (LPTSTR) sColunas->col.GetNext(pos).operator LPCTSTR();
        if (cVisaoLista->InsertColumn(nColunas, &lvc) == -1) 
            return FALSE;         
    }
    cVisaoLista->SetItemCount(MAXLINHAS_VISAOLISTA);
    return TRUE;
}

BOOL CRotinasGlobais::VisaoListaInsereLinhas(CListCtrl *cVisaoLista, LISTAMSTR *sLinhas)
{
    LVITEM lvItem;
    POSITION pos;
    INT nLinhas;
    CString sTemp;

    cVisaoLista->DeleteAllItems();
    
    lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE; 
    lvItem.state = LVIS_FOCUSED | LVIS_SELECTED;
    lvItem.stateMask = LVIS_FOCUSED | LVIS_SELECTED;
    
    nLinhas = -1;
    pos = sLinhas->col[0].GetHeadPosition();
    while (pos != NULL) {
      nLinhas++;
     	lvItem.iItem = nLinhas;
    	lvItem.iImage = nLinhas;
    	lvItem.iSubItem = 0;
      sTemp = sLinhas->col[0].GetNext(pos);
    	lvItem.lParam = (LPARAM) sLinhas;
    	lvItem.pszText = LPSTR_TEXTCALLBACK;
    	lvItem.cchTextMax = TAM_MAX_STR;
    
    	if(cVisaoLista->InsertItem(&lvItem) == -1)      	  
    	  return FALSE;  	  
    }
  return TRUE;
}

BOOL CRotinasGlobais::VisaoListaNotifica(CListCtrl *cVisaoLista, LISTAMSTR *sLinhas, 
    LPARAM lParam, INT *nLinha, CString *sSelecionado)
{ 
  NMHDR *nm = (LPNMHDR) lParam;  
  
 *nLinha = 0;
 switch( nm->code ) {
   case LVN_GETDISPINFO: 
   { POSITION pos; 
     LPTSTR sTexto;
     LV_DISPINFO *lpdi = (LV_DISPINFO *)lParam;         
     
     pos = sLinhas->col[lpdi->item.iSubItem].FindIndex(lpdi->item.iItem);
     sTexto = (LPTSTR) 
       sLinhas->col[lpdi->item.iSubItem].GetAt(pos).operator LPCTSTR();
     lpdi->item.pszText = sTexto;
     //lpdi->item.state = LVIS_FOCUSED | LVIS_SELECTED; //0;
     //lpdi->item.stateMask = LVIS_FOCUSED | LVIS_SELECTED; //0; 
     return TRUE;
   }
   break;  
   case LVN_ITEMCHANGED:
   {   POSITION pos; 
       NM_LISTVIEW *pnmv = (NM_LISTVIEW *) lParam; 
       
       if (sLinhas->col[pnmv->iSubItem].GetCount() == 
              cVisaoLista->GetItemCount()) {
         *nLinha = pnmv->iItem + 1;
         pos = sLinhas->col[pnmv->iSubItem].FindIndex(pnmv->iItem);
         *sSelecionado = sLinhas->col[pnmv->iSubItem].GetAt(pos);
       }       
       return TRUE;
   }
   break;
 } 
  return FALSE;
}

