#include "stdafx.h"

#include <sql.h>
#include <sqlext.h>

#include "Livrus.h"
#include "Principal.h"
#include "resource.h"
#include "RotinasGlobais.h"

CONEXAO gConexao;
SQLHENV  henv;
SQLHDBC  hdbc;

CString Rotinas_sBarraLogin;
CString Rotinas_sUsuarioLogin;
CString Rotinas_sUsuarioSenha;
CString Rotinas_sCodigoSelecionado;
CString Rotinas_sPreco;
CString Rotinas_sQtdEstoque;
CString Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
//CString Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

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

BOOL CRotinasGlobais::ConectaBanco(CString sFonteDeDados, CString sLogin, CString sSenha)
{
SQLRETURN rc;

gConexao = SQL_NULL_HSTMT;
henv  = SQL_NULL_HENV;
hdbc  = SQL_NULL_HDBC;

// Aloca o ambiente ODBC e salva o manuseador.
rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
  // Faz o ODBC saber que esta � uma aplica��o ODBC 3.0.
  rc = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0); 

  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    /* Aloca o manuseador da conex�o */
    rc = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); 

    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
      /* Atribui login timeout para 5 segundos. */
      SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER) 5, 0);

      /* Conecta na fonte de dados */
      rc = SQLConnect(hdbc, (SQLTCHAR*) sFonteDeDados.operator LPCTSTR(), SQL_NTS,
               (SQLTCHAR*) sLogin.operator LPCTSTR(), SQL_NTS, 
               (SQLCHAR*) sSenha.operator LPCTSTR(), SQL_NTS);

      if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO){
        /* Aloca manuseador do procedimento */
        rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &gConexao); 
	
		if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
          return TRUE; 
		} else
          SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
	  } else
          SQLDisconnect(hdbc);
	} else
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  }
} else
    SQLFreeHandle(SQL_HANDLE_ENV, henv);

return FALSE;

}

VOID CRotinasGlobais::DisconectaBanco()
{
  SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
  SQLDisconnect(hdbc);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

BOOL CRotinasGlobais::ConsultaDados(CONEXAO hstmtlocal, CString sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.operator LPCTSTR(), SQL_NTS);   
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  AfxMessageBox(lerStr(STR_NCPREPSQL), MB_ICONERROR | MB_OK, 0);
  return FALSE;
}   
rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  AfxMessageBox(lerStr(STR_NCEXECSQL), MB_ICONERROR | MB_OK, 0);
  return FALSE;
}
if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
  rc = SQLFetch(hstmtlocal);
  if ( rc == SQL_NO_DATA ) {
  	SQLCloseCursor(hstmtlocal); 
  	return FALSE;
  } else {
  	SQLCloseCursor(hstmtlocal); 
    return TRUE;
  }
} else {
  SQLCloseCursor(hstmtlocal); 
  return FALSE;
} 
}

VOID CRotinasGlobais::arrumaColunas(CONEXAO hstmtlocal, CString sLinha[],
				 SQLUSMALLINT nQtdCol)
{
SQLUSMALLINT  nCol;
SQLRETURN   rc;
SQLCHAR   sColNome[TAM_MAX_STR];
SWORD     nColTipo;
SWORD     nColEscala;
SWORD     nColNula;
SWORD     nColTam = TAM_MAX_STR;
UDWORD    nColPrecisao;

   for (nCol = 0; nCol < nQtdCol; nCol++) {	
	  rc = SQLDescribeCol(hstmtlocal, nCol+1, sColNome, TAM_MAX_STR, 
	  &nColTam, &nColTipo, &nColPrecisao, &nColEscala, &nColNula);
	       
    if (nColTipo == SQL_TYPE_TIMESTAMP) {
      sLinha[nCol] = Rotinas->ConverteDataHoraStr(sLinha[nCol], FALSE, 
        "dd/MM/yyyy", "HH:mm:ss");
    }
	  /*
	 else if (nColTipo == SQL_DECIMAL || nColTipo == SQL_DOUBLE 
		 || nColTipo == SQL_FLOAT)
		 sLinha[nCol] = CRotinasGlobais::VirgulaParaPonto(sLinha[nCol], FALSE);*/
   }
}

BOOL CRotinasGlobais::ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, CString sSql)
{
LPTSTR sLinha[QTD_MAX_COL];
SQLRETURN   rc;
SQLINTEGER  nLen;
SQLUSMALLINT  nCol, nQtdCol;
POSITION pos[QTD_MAX_COL];
CString sTemp[QTD_MAX_COL];

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.operator LPCTSTR(), SQL_NTS);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  AfxMessageBox(lerStr(STR_NCPREPSQL), MB_ICONERROR | MB_OK, 0);
  return FALSE;
}   

rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  AfxMessageBox(lerStr(STR_NCEXECSQL), MB_ICONERROR | MB_OK, 0);
  return FALSE;
}

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {

    if (!SQL_SUCCEEDED(SQLNumResultCols(hstmtlocal, (SQLSMALLINT*) &nQtdCol)))
      return FALSE;
	
	for (nCol = 0; nCol < nQtdCol; nCol++) {
      sLinha[nCol] = alocaString(TAM_MAX_STR);

  	  rc = SQLBindCol(hstmtlocal, nCol+1, SQL_C_CHAR, 
		  sLinha[nCol], TAM_MAX_STR, &nLen);

	  if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
	    SQLCloseCursor(hstmtlocal);
	    return FALSE;
	  }
	}

  
    rc = SQLFetch(hstmtlocal);
   	if ( rc != SQL_NO_DATA ) {	
      
      for (nCol = 0; nCol < nQtdCol; nCol++)
        (*lstLocal).col[nCol].RemoveAll();

      for (nCol = 0; nCol < nQtdCol; nCol++)
        pos[nCol] = (*lstLocal).col[nCol].GetHeadPosition();

    	while ( rc != SQL_NO_DATA ) {				
		    //SQLGetData(hstmtlocal, nCol+1, SQL_C_CHAR, 
			  //sLinha[nCol], TAM_MAX_STR, &nLen)

			  for (nCol = 0; nCol < nQtdCol; nCol++) {
			    sTemp[nCol] = sLinha[nCol];
			  }        
			  arrumaColunas(hstmtlocal, sTemp, nQtdCol);

		    for (nCol = 0; nCol < nQtdCol; nCol++) {
		      (*lstLocal).col[nCol].InsertAfter(pos[nCol],sTemp[nCol]); 
		    }

    		rc = SQLFetch(hstmtlocal);
    	}
    	SQLCloseCursor(hstmtlocal);
    	return TRUE;
    } else {
       SQLCloseCursor(hstmtlocal);
       return FALSE;     	
    }   
 } else
    return FALSE; 
}


BOOL CRotinasGlobais::AtualizaDados(CONEXAO hstmtlocal, CString sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.operator LPCTSTR(), SQL_NTS);
  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    rc = SQLExecute(hstmtlocal);
    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
      return TRUE;
    else {
     //AfxMessageBox(lerStr(STR_NCEXECSQL), MB_ICONERROR | MB_OK, 0);
     return FALSE;      
    }  
  } else {
    AfxMessageBox(lerStr(STR_NCPREPSQL), MB_ICONERROR | MB_OK, 0);
    return FALSE;
  }   
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

