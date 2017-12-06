#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>
#include <commdlg.h>

#include <math.h>
#include <stdlib.h>

#include	<mysql.h>

#include "Livrus.h"
#include "Principal.h"
#include "ListaStr.h"
#include "resource.h"
#include "RotinasGlobais.h"

TCHAR Rotinas_sUsuarioLogin[TAM_MAX_STR];
TCHAR Rotinas_sUsuarioSenha[TAM_MAX_STR];
TCHAR Rotinas_sCodigoSelecionado[TAM_MAX_STR];
TCHAR Rotinas_sPreco[TAM_MAX_STR];
TCHAR Rotinas_sQtdEstoque[TAM_MAX_STR];
//TCHAR Rotinas_sepDTHR[2] = "#"; /* SOMENTE ACCESS */
TCHAR Rotinas_sepDTHR[2] = "'"; /* OUTROS BANCOS */

CONEXAO gConexao;

INT Rotinas_RegistrarClasseForm(WNDCLASSEX WndClassEx, WNDPROC WndFrmProc, 
  LPCTSTR sNomeClasse) 
{
   WndClassEx.lpfnWndProc     = WndFrmProc;
   WndClassEx.lpszMenuName    = NULL;
   WndClassEx.lpszClassName   = sNomeClasse; 
   WndClassEx.hbrBackground   = (HBRUSH)(COLOR_3DFACE+1);
   WndClassEx.cbWndExtra      = 4;

   if(!RegisterClassEx(&WndClassEx))
   {
      MessageBox(0, Rotinas_lerStr(STR_NREGTELA), "Erro", MB_ICONERROR | MB_OK);
      return -1;
   }
   return TRUE;
}

HWND Rotinas_ChamarForm(HWND hwnd, LPCTSTR sTituloForm, LPCTSTR sNomeClasse, 
                HWND hMDICliente, INT largura, INT altura)
{
  MDICREATESTRUCT mcs;
  HWND hTelaFilha;
  
  mcs.szTitle = sTituloForm;
  mcs.szClass = sNomeClasse;
  mcs.hOwner  = (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE);
  mcs.x = CW_USEDEFAULT;
  mcs.y = CW_USEDEFAULT;
  mcs.cx = largura;
  mcs.cy = altura;
//  mcs.style = MDIS_ALLCHILDSTYLES;
  mcs.style = g_hTelaAtiva && IsZoomed(g_hTelaAtiva) ? WS_MAXIMIZE : 0;

  hTelaFilha = (HWND)(UINT)SendMessage(hMDICliente, WM_MDICREATE, 0, 
    (LPARAM)(LPMDICREATESTRUCT)&mcs);  
  
  if(!hTelaFilha)
    MessageBox(hwnd, Rotinas_lerStr(STR_NCCRIATELA), 
        "Erro", MB_ICONERROR | MB_OK);
  
  return hTelaFilha;
}

HWND Rotinas_ChamarDlgNaoModal(HWND hwnd, LPCTSTR sNomeDialog, DLGPROC lpDlgProc)
{
HWND hLocal;                       
  hLocal = CreateDialog((HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), 
                        sNomeDialog, hwnd, lpDlgProc);  
  if (!hLocal)
     MessageBox(hwnd, Rotinas_lerStr(STR_NCCRIATELA), 
          "Erro", MB_ICONERROR | MB_OK);
  else 
    ShowWindow(hLocal, SW_SHOW);
    
return hLocal;
}

VOID Rotinas_habilitaSubMenu(HWND hwnd, INT nPosSubMenu, INT idSubMenu, 
    BOOL bHabilita)
{
 HMENU hMenu, hSubMenu;

 hMenu = GetMenu(hwnd);
 hSubMenu = GetSubMenu(hMenu, nPosSubMenu);
 if (bHabilita)
   EnableMenuItem(hSubMenu, idSubMenu, MF_BYCOMMAND | MF_ENABLED);
 else  
   EnableMenuItem(hSubMenu, idSubMenu, MF_BYCOMMAND | MF_GRAYED);    
   
 DrawMenuBar(hwnd);
}

VOID Rotinas_CentralizaTela(HWND hWnd)
{
RECT rect, rectTela;
INT hFrm, wFrm, hTela, wTela;

GetWindowRect(hWnd, &rect);
GetWindowRect(GetDesktopWindow(), &rectTela);

hFrm = rect.bottom - rect.top;
wFrm = rect.right - rect.left;

hTela = rectTela.bottom - rectTela.top;
wTela = rectTela.right - rectTela.left;

MoveWindow(hWnd, abs((wTela - wFrm) / 2), abs((hTela - hFrm)/2), 
        wFrm, hFrm, TRUE);
}

LPTSTR Rotinas_alocaString(INT ntam)
{ LPTSTR strlocal;

 strlocal = LPTSTR(GlobalAlloc(GPTR, ntam));
 return strlocal;
}

LPTSTR Rotinas_subString(LPTSTR string, INT nini, INT ntam)
{
LPTSTR str1, slocal;
INT i,j;

str1 = Rotinas_alocaString(TAM_MAX_STR);
slocal = Rotinas_alocaString(TAM_MAX_STR);
  
lstrcpy(slocal, string);   
j=0;
nini--;
for(i=nini;i<(nini+ntam);i++)
 {
   str1[j]=slocal[i];
   j++;
 }
str1[j]='\0';
GlobalFree(slocal);
return str1;
}

BOOL Rotinas_ValidaFloat(LPTSTR sNum)
{
 if (lstrlen(sNum) > 0) {    
    if (atof(sNum) >= 0.01)
      return TRUE;
    else {
      MessageBox(0, Rotinas_lerStr(STR_NUMINV),
        "Erro", MB_ICONERROR | MB_OK);
      return FALSE;
    }
 } else
   return FALSE;
} 

LPTSTR Rotinas_VirgulaParaPonto(LPTSTR sNum, BOOL bRevertido) 
{
INT ncont;
LPTSTR sret;
TCHAR sponto[2], svirgula[2];

sret = Rotinas_alocaString(TAM_MAX_STR);

if (bRevertido) {
  lstrcpy(sponto, ",");
  lstrcpy(svirgula, ".");
} else {
  lstrcpy(sponto, ".");
  lstrcpy(svirgula, ",");
}

for (ncont=1; ncont <= lstrlen(sNum); ncont++) {
  if (lstrcmp(Rotinas_subString(sNum, ncont, 1),svirgula)==0)
    lstrcpy(sret, lstrcat(sret, sponto));
  else 
    lstrcpy(sret, strcat(sret, Rotinas_subString(sNum,ncont,1)));
}
return sret;

}

INT Rotinas_modulo11(LPTSTR svalor, INT ndig)
{ INT ncont, nsoma, nvalor, npos;
  LPTSTR slocal, sres;
  
 slocal = Rotinas_alocaString(TAM_MAX_STR);
 ncont=1;
 while (ncont <= 11) {
   slocal=lstrcat(Rotinas_subString(svalor,ncont,1),slocal);
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=3;
 else
   ncont=2;
 npos=2;
 while (ncont <= 11) {
   sres = Rotinas_subString(slocal,ncont,1);
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

BOOL Rotinas_validaCPF(LPTSTR cpf)
{ LPTSTR scpf, sres;
  INT nvalor1, nvalor2;

if (lstrlen(cpf)==14) {
  scpf = Rotinas_alocaString(TAM_MAX_STR);
  wsprintf(scpf,"%s%s%s%s",Rotinas_subString(cpf,1,3),Rotinas_subString(cpf,5,3),
    Rotinas_subString(cpf,9,3),Rotinas_subString(cpf,13,2));
  sres = Rotinas_subString(cpf,13,1);
  nvalor1 = atoi(sres);
  lstrcpy(sres, Rotinas_subString(cpf,14,1));
  nvalor2 = atoi(sres);
  if ((Rotinas_modulo11(scpf,1)==nvalor1) 
	  && (Rotinas_modulo11(scpf,2)==nvalor2))
    return TRUE;
  else
    return FALSE;
} else
  return FALSE;
}

BOOL Rotinas_validaISBN(LPTSTR isbn)
{ LPTSTR sisbn, sdigito, snum;
  INT nvalor, nsoma, ncont;

sisbn = Rotinas_alocaString(TAM_MAX_STR);

if (lstrlen(isbn)==13) {
  sdigito = Rotinas_subString(isbn, lstrlen(isbn), 1);

  for(ncont = 1; ncont <= abs(lstrlen(isbn)-1); ncont++)  {
    if (lstrcmp(Rotinas_subString(isbn,ncont,1),"-")!=0)
      sisbn = lstrcat(sisbn, Rotinas_subString(isbn,ncont,1));
  }
  if (lstrcmp(sdigito, "X")==0)
    nsoma = 10;
  else {
    nvalor = atoi(sdigito);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = Rotinas_subString(sisbn, ncont, 1);
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

BOOL Rotinas_validaDataHora(LPTSTR sDataHora, BOOL bSoData)
{ BOOL bvalida, bdatavalida, bhoravalida;
  LPTSTR sdia, smes, sano, shora, smin, sseg;
  INT ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = FALSE;
bdatavalida = FALSE;
bhoravalida = FALSE;
nudiames = 0;
if (bSoData==TRUE) ntam=10;
else ntam=19;

  if (lstrlen(sDataHora)==ntam) {
    sdia = Rotinas_subString(sDataHora,1,2);
    ndia = atoi(sdia);
    smes = Rotinas_subString(sDataHora,4,2);
    nmes = atoi(smes);
    sano = Rotinas_subString(sDataHora,7,4);
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
          shora = Rotinas_subString(sDataHora,12,2);
          nhora = atoi(shora);
          smin = Rotinas_subString(sDataHora,15,2);
          nmin = atoi(smin);
          sseg = Rotinas_subString(sDataHora,18,2);
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

LPTSTR Rotinas_FormataDataHoraStr(SYSTEMTIME sTempo, LPTSTR sFrmtData, 
    LPTSTR sFrmtHora)
{ LPTSTR sDataHora;
  TCHAR sData[TAM_MAX_STR], sHora[TAM_MAX_STR];  
  LCID local_id;

sDataHora = Rotinas_alocaString(TAM_MAX_STR);

//local_id = MAKELCID(
//    MAKELANGID(LANG_PORTUGUESE, SUBLANG_PORTUGUESE_BRAZILIAN), SORT_DEFAULT);
local_id = LOCALE_SYSTEM_DEFAULT; //LOCALE_USER_DEFAULT

if (lstrlen(sFrmtData) > 0)
  GetDateFormat(local_id, 0, &sTempo, sFrmtData, sData, TAM_MAX_STR);
if (lstrlen(sFrmtHora) > 0)
  GetTimeFormat(local_id, 0, &sTempo, sFrmtHora, sHora, TAM_MAX_STR);

if (lstrlen(sFrmtData) > 0 && lstrlen(sFrmtHora) > 0)
  wsprintf(sDataHora, "%s %s", sData, sHora);
else if (lstrlen(sFrmtData) > 0)
  wsprintf(sDataHora, "%s", sData);
else if (lstrlen(sFrmtHora) > 0)
  wsprintf(sDataHora, "%s", sHora);

  return sDataHora;
}

LPTSTR Rotinas_retDataHoraStr(BOOL bData, BOOL bHora)
{ LPTSTR sDataHora;
  SYSTEMTIME sTempo;
  
  GetSystemTime(&sTempo);
if (bData && bHora)
  sDataHora = Rotinas_FormataDataHoraStr(sTempo, "dd/MM/yyyy", "HH:mm:ss");
else if (bData)
  sDataHora = Rotinas_FormataDataHoraStr(sTempo, "dd/MM/yyyy", "");
else if (bHora)
  sDataHora = Rotinas_FormataDataHoraStr(sTempo, "", "HH:mm:ss");

return sDataHora;
}

LPTSTR Rotinas_ConverteDataHoraStr(LPTSTR sDTHR, BOOL DMY_ou_YMD, 
    LPTSTR sFrmtData, LPTSTR sFrmtHora)
{ LPTSTR sDataHora;
  SYSTEMTIME sTempo;

if (lstrlen(sFrmtData) > 0) {
  if (DMY_ou_YMD) {
    sTempo.wDay = atoi(Rotinas_subString(sDTHR,1,2));
    sTempo.wMonth = atoi(Rotinas_subString(sDTHR,4,2));
    sTempo.wYear = atoi(Rotinas_subString(sDTHR,7,4));
  } else {
    sTempo.wYear = atoi(Rotinas_subString(sDTHR,1,4));
    sTempo.wMonth = atoi(Rotinas_subString(sDTHR,6,2));
    sTempo.wDay = atoi(Rotinas_subString(sDTHR,9,2));
  }
}
if (lstrlen(sFrmtHora) > 0) {
  sTempo.wHour = atoi(Rotinas_subString(sDTHR,12,2));
  sTempo.wMinute = atoi(Rotinas_subString(sDTHR,15,2));
  sTempo.wSecond = atoi(Rotinas_subString(sDTHR,18,2));
  sTempo.wMilliseconds = 0;
}
sDataHora = Rotinas_FormataDataHoraStr(sTempo,sFrmtData,sFrmtHora);
return sDataHora;
}

LPTSTR Rotinas_retTexto(HWND hwnd, INT nItem)
{
LPTSTR sValor;
sValor = Rotinas_alocaString(TAM_MAX_STR);
GetWindowText(GetDlgItem(hwnd, nItem), sValor, TAM_MAX_STR);       
return sValor;
}

LPTSTR Rotinas_lerStr(UINT nId)
{
LPTSTR sValor;
sValor = Rotinas_alocaString(TAM_MAX_STR);
LoadString(g_hInstancia, nId, sValor, TAM_MAX_STR);
return sValor;
}

HWND Rotinas_criaBotao(HWND hwnd, LPTSTR sTexto, INT id, INT x, INT y, 
    BOOL bHabilitado)
{ 
HWND hwndBotao;
DWORD nEstilo;

nEstilo = WS_VISIBLE | WS_CHILD | WS_TABSTOP | BS_TEXT; 
if (bHabilitado==FALSE) nEstilo += WS_DISABLED;

hwndBotao = CreateWindowEx(WS_EX_LEFT, "BUTTON", sTexto,
    nEstilo, x, y, 75, 25, hwnd, (HMENU)id, 
    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

SendMessage(hwndBotao, WM_SETFONT, 
(WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));         
  
return hwndBotao;    
}

HWND Rotinas_criaEdit(HWND hwnd, INT id, INT x, INT y, INT largura, 
    BOOL bHabilitado, INT nMaxTam, BOOL bComSenha, BOOL bSoNumero)
{ 
HWND hwndEdit;
DWORD nEstilo;

nEstilo = WS_VISIBLE | WS_CHILD | WS_TABSTOP;
if (bHabilitado==FALSE) nEstilo += WS_DISABLED;
if (bComSenha) nEstilo += ES_PASSWORD;
if (bSoNumero) nEstilo += ES_NUMBER;

hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "",
    nEstilo, x, y, largura, 21, hwnd, (HMENU)id, 
    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

SendMessage(hwndEdit, WM_SETFONT,
(WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));

SendMessage(hwndEdit, EM_SETLIMITTEXT,(WPARAM) nMaxTam, 0);

return hwndEdit;
}

HWND Rotinas_criaRotulo(HWND hwnd, LPTSTR sTexto, INT id, INT x, INT y, 
    INT largura)
{ 
HWND hwndRotulo;
DWORD nEstilo;

nEstilo = WS_VISIBLE | WS_CHILD;

hwndRotulo = CreateWindowEx(WS_EX_LEFT, "STATIC", sTexto,
    nEstilo, x, y, largura, 21, hwnd, (HMENU)id, 
    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), NULL);

SendMessage(hwndRotulo, WM_SETFONT,
(WPARAM)GetStockObject(DEFAULT_GUI_FONT), MAKELPARAM(TRUE, 0));

return hwndRotulo;
}

HWND Rotinas_criaVisaoLista(HWND hwnd, INT id, 
    INT x, INT y, INT altura)
{ 
HWND hwndVisaoLista;
DWORD nEstilo;
INT largura;
RECT rc;

GetClientRect(hwnd, &rc);
largura = rc.right - rc.left;

nEstilo = WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_VSCROLL | WS_HSCROLL |
LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS | LVS_ALIGNLEFT | 
ES_AUTOVSCROLL | ES_AUTOHSCROLL;
      
hwndVisaoLista = CreateWindowEx(WS_EX_CLIENTEDGE, WC_LISTVIEW, "",  nEstilo,                  
     x, y, largura, altura, hwnd, (HMENU)id, 
    (HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE), NULL); 

return hwndVisaoLista;
}

BOOL Rotinas_ConectaBanco(LPTSTR sBancoDeDados, LPTSTR sLogin, LPTSTR sSenha)
{ LPTSTR sTemp;

  if ((gConexao = mysql_init((MYSQL*) 0)) && 
       mysql_real_connect( gConexao, "localhost", 
         sLogin, sSenha, NULL, MYSQL_PORT, NULL, 0 ) )
  {
    if ( mysql_select_db( gConexao, sBancoDeDados ) < 0 ) {
        MessageBox(0, Rotinas_lerStr(STR_NCONBANCO), "Erro", MB_ICONERROR | MB_OK);
	    mysql_close(gConexao);
	    return FALSE;
    } else 
      return TRUE;
  } else {
    sTemp = Rotinas_alocaString(TAM_MAX_STR);
    wsprintf(sTemp,"%s: %d",Rotinas_lerStr(STR_NCONPORTA), MYSQL_PORT);
    MessageBox(0, sTemp, "Erro", MB_ICONERROR | MB_OK);
    mysql_close(gConexao);
    return FALSE;
  }
}

VOID Rotinas_DisconectaBanco()
{
  mysql_close(gConexao);
}

BOOL Rotinas_ConsultaDados(CONEXAO mConLocal, LPTSTR sSql)
{
BOOL bRet;
MYSQL_RES	*mResultado;
  
  if ( mysql_query(mConLocal, sSql) == 0 ) {
    mResultado = mysql_store_result(mConLocal);

    if (mysql_num_rows(mResultado) > 0)
      bRet = TRUE;
    else      
      bRet = FALSE;

    mysql_free_result(mResultado);
  }
  else {
    MessageBox(0, Rotinas_lerStr(STR_NCEXECSQL), "Erro", MB_ICONERROR | MB_OK);
    bRet = FALSE;
  }
 return bRet;
}

BOOL Rotinas_ConsultaDadosLista(CONEXAO mConLocal, LISTAMSTR *lstLocal, LPTSTR sSql)
{
  LPTSTR sLinha[QTD_MAX_COL];
  INT nQtdCol, nCol;
  MYSQL_RES	*mResultado;
  MYSQL_FIELD	*mCampo;
  MYSQL_ROW	mLinha;  

  if ( mysql_query(mConLocal, sSql) == 0 ) {
    mResultado = mysql_store_result(mConLocal);

    for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
	    sLinha[nCol] = Rotinas_alocaString(TAM_MAX_STR);

    *lstLocal = ListaStr_iniciaM();
    while ( mLinha = mysql_fetch_row(mResultado) ) {

      nQtdCol = mysql_num_fields(mResultado);
      mCampo = mysql_fetch_fields(mResultado);
      for (nCol = 0; nCol < nQtdCol; nCol++) {	  
        if (mCampo[nCol].type == FIELD_TYPE_DATETIME)
          sLinha[nCol] = Rotinas_ConverteDataHoraStr(mLinha[nCol], FALSE, 
            "dd/MM/yyyy","HH:mm:ss");          
        else
          sLinha[nCol] = mLinha[nCol];
      }      
      ListaStr_insereFimM(lstLocal, sLinha);
    }
    mysql_free_result(mResultado);
  }
  else {
    MessageBox(0, Rotinas_lerStr(STR_NCEXECSQL), "Erro", MB_ICONERROR | MB_OK);
    return FALSE;
  }

  return TRUE;
}

BOOL Rotinas_AtualizaDados(CONEXAO mConLocal, LPTSTR sSql)
{ 
  if ( mysql_query(mConLocal, sSql) == 0)
    return TRUE;
  else {
    MessageBox(0, Rotinas_lerStr(STR_NCEXECSQL), "Erro", MB_ICONERROR | MB_OK);
    return FALSE;
  } 
}

BOOL Rotinas_ValidaCampo(LPTSTR sCampo, LPTSTR sMensagemErro)
{
  if (lstrlen(sCampo)==0) {
    MessageBox(0, sMensagemErro, "Erro", MB_ICONERROR | MB_OK);
	return TRUE;
  } else
	return FALSE;
}

LPTSTR Rotinas_ConsultaCampoDesc(LISTAMSTR *Campos, 
            LPTSTR sTextoSql, LPTSTR sMensagemErro)
{
  if (Rotinas_ConsultaDadosLista(gConexao, Campos, sTextoSql)) {  	
    return ListaStr_pesquisaItemOrdM((*Campos),1,0);
  } else {
	  MessageBox(0, sMensagemErro, "Erro", MB_ICONERROR | MB_OK);
    return "";
  }
}

VOID Rotinas_AdicionaItemLista(HWND lstLista,
     LISTASTR *slCodLista, HWND sCampoCodigo, HWND sCampoDesc)
{
LPTSTR sItems, sCodigo, sDesc;

sItems = Rotinas_alocaString(TAM_MAX_STR);
sCodigo = Rotinas_alocaString(TAM_MAX_STR);
sDesc = Rotinas_alocaString(TAM_MAX_STR);

if (GetWindowTextLength(sCampoDesc) > 0) {

 GetWindowText(sCampoCodigo, sCodigo, TAM_MAX_STR);
 GetWindowText(sCampoDesc, sDesc, TAM_MAX_STR);

 wsprintf(sItems, "%s%s%s", sCodigo, " - ", sDesc);

 if (SendMessage(lstLista, LB_FINDSTRING, 0, (LPARAM) sItems)==LB_ERR)
 { 
	ListaStr_insereFim(slCodLista, sCodigo);
	SendMessage(lstLista, LB_ADDSTRING, 0, (LPARAM) sItems);
 }
 SetWindowText(sCampoCodigo, "");
 SetWindowText(sCampoDesc, "");
}

}

VOID Rotinas_RemoveItemLista(HWND lstLista, LISTASTR *slCodLista)
{
INT nSelIndice;

 if (SendMessage(lstLista, LB_GETCOUNT, 0, 0) > 0) {   
   nSelIndice = SendMessage(lstLista, LB_GETCURSEL, 0, 0);
   //if (nSelIndice != LB_ERR) {
   if (SendMessage(lstLista, LB_GETSEL, (WPARAM) nSelIndice, 0) > 0) {
	   ListaStr_removeItemOrd(slCodLista, nSelIndice, TRUE);
	   SendMessage(lstLista, LB_DELETESTRING, (WPARAM) nSelIndice, 0);
   }	
 }
}

VOID Rotinas_AdicionaValoresLista(LPTSTR sTextoSql, HWND lstLista, LISTASTR *slCodLista)
{
  LISTAMSTR Campos, local;
  LPTSTR sItems, sCodigo;

  sItems = Rotinas_alocaString(TAM_MAX_STR);
  sCodigo = Rotinas_alocaString(TAM_MAX_STR);

  SendMessage(lstLista, LB_RESETCONTENT,0,0);
  (*slCodLista) = ListaStr_inicia();

  if (Rotinas_ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
	  for (local = Campos; local != NULL; local = local->proximo) {	
	    ListaStr_insereFim(slCodLista, local->str[0]);
	    wsprintf(sItems, "%s - %s", local->str[0], local->str[1]);
	    SendMessage(lstLista, LB_ADDSTRING, 0, (LPARAM) sItems);		
	  }      
  }
  ListaStr_liberaM(Campos);
  ListaStr_liberaM(local);   
}

BOOL Rotinas_VisaoListaInsereColunas(HWND hwndVisaoLista, UINT largura[], 
    LISTASTR sColunas)
{
    LV_COLUMN lvc; 
  	LISTASTR local;
    INT nColunas;
     
    lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM; 
    lvc.fmt = LVCFMT_LEFT; 
    
    nColunas = -1;
	  for (local = sColunas; local != NULL; local = local->proximo) {
   	    nColunas++;    
   	    lvc.cx = largura[nColunas];
        lvc.iSubItem = nColunas; 
        lvc.pszText = local->str;
        if (ListView_InsertColumn(hwndVisaoLista, nColunas, &lvc) == -1) 
            return FALSE; 
    } 
    ListView_SetItemCount(hwndVisaoLista, MAXLINHAS_VISAOLISTA);
    return TRUE;
}

BOOL Rotinas_VisaoListaInsereLinhas(HWND hwndVisaoLista, LISTAMSTR sLinhas)
{
    LVITEM lvItem;
    LISTAMSTR local;
    INT nLinhas;

    ListView_DeleteAllItems(hwndVisaoLista);           
    
    lvItem.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE; 
    lvItem.state = LVIS_FOCUSED | LVIS_SELECTED; //0;
    lvItem.stateMask = LVIS_FOCUSED | LVIS_SELECTED; //0;     
    
    nLinhas = -1;
    for (local = sLinhas; local != NULL; local = local->proximo) {
        nLinhas++;
       	lvItem.iItem = nLinhas;
    	lvItem.iImage = nLinhas;
    	lvItem.iSubItem = 0;
    	lvItem.lParam = (LPARAM) local;
    	lvItem.pszText = LPSTR_TEXTCALLBACK;
    	lvItem.cchTextMax = TAM_MAX_STR;
    
    	if(ListView_InsertItem(hwndVisaoLista, &lvItem) == -1)      	  
    	  return FALSE;  	  
    }
  return TRUE;
}

BOOL Rotinas_VisaoListaNotifica(HWND hwndVisaoLista, LISTAMSTR sLinhas, 
    LPARAM lParam, INT *nLinha, LPTSTR *sSelecionado)
{ 
  NMHDR *nm = (LPNMHDR) lParam;  
  
 *nLinha = 0;
 switch( nm->code ) {
   case LVN_GETDISPINFO: 
   {  
     LV_DISPINFO *lpdi = (LV_DISPINFO *)lParam;         
     
     lpdi->item.pszText = ListaStr_pesquisaItemOrdM(sLinhas, 
                             lpdi->item.iSubItem, lpdi->item.iItem);
     //lpdi->item.state = LVIS_FOCUSED | LVIS_SELECTED; //0;
     //lpdi->item.stateMask = LVIS_FOCUSED | LVIS_SELECTED; //0; 
     return TRUE;
   }
   break;  
   case LVN_ITEMCHANGED:
   {
       NM_LISTVIEW *pnmv = (NM_LISTVIEW *) lParam; 
       
       if (ListaStr_contaM(sLinhas) == ListView_GetItemCount(hwndVisaoLista)) {
         *nLinha = pnmv->iItem + 1;
         *sSelecionado = ListaStr_pesquisaItemOrdM(sLinhas, 
                             pnmv->iSubItem, pnmv->iItem);         
       }       
       return TRUE;
   }
   break;
 } 
  return FALSE;
}

VOID Rotinas_copiaBitmap(HWND hwnd, INT idBMP, RECT rc)
{
HDC hDC; 
HDC hDCMem; 
PAINTSTRUCT ps; 
HBITMAP hBMP; 
       
hDC = BeginPaint(hwnd, &ps);            
hDCMem = CreateCompatibleDC(hDC); 
if (hDCMem != NULL) 
{ 
  hBMP = LoadBitmap((HINSTANCE) GetWindowLong(hwnd, GWL_HINSTANCE),
    MAKEINTRESOURCE(idBMP));	
  SelectObject(hDCMem, hBMP);  
  BitBlt(hDC, rc.left, rc.top, rc.right, rc.bottom, hDCMem, 0, 0, SRCCOPY); 
  DeleteDC(hDCMem); 
}            
EndPaint(hwnd, &ps); 
}                
