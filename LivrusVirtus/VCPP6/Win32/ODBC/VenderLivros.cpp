#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "resource.h"
#include "livrus.h"
#include "Principal.h"
#include "Cadastros.h"
#include "VenderLivros.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

LISTAMSTR lstVender;
UINT nRegVender;
LISTASTR slPrecos, slISBNs, slQtdEstoque;
FLOAT nPrecoTotal;
BOOL bAtivaVender;

LRESULT CALLBACK frmVenderLivrosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMVenderLivros, 
                (DLGPROC)frmVenderLivrosProc))
          return FALSE;          
        
        SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                CM_VEN_VENDERLIVROS, MAKELONG(FALSE, 0));
          
        SetWindowText(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA),
         ID_FRMVENDERLIVROS_EDTDTHRVENDA), Rotinas_retDataHoraStr(TRUE, TRUE));  
         
        frmCadastros_TamMaxEdit(hwnd, ID_FRMVENDERLIVROS_EDTCPF, 14);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMVENDERLIVROS_EDTISBN, 13);
        
        nRegVender = 0;        
      }
      break;
      case WM_MDIACTIVATE:
      {      
        bAtivaVender = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMVENDERLIVROS_EDTCPF, 2, CM_VEN_VENDERLIVROS);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                CM_VEN_VENDERLIVROS, MAKELONG(TRUE, 0));

         frmCadastros_Fechar(hwnd, 2, CM_VEN_VENDERLIVROS);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMVENDERLIVROS_EDTISBN:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmVenderLivros_edtISBNKillFocus(hwnd);
            }
            break;
            case ID_FRMVENDERLIVROS_EDTCPF:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmVenderLivros_edtCPFKillFocus(hwnd);
            }
            break;
            case ID_FRMVENDERLIVROS_BTNPCLIENTE:
              frmVenderLivros_btnPClienteClick(hwnd);
            break;
            case ID_FRMVENDERLIVROS_BTNPLIVRO:
              frmVenderLivros_btnPLivroClick(hwnd);
            break;
            case ID_FRMVENDERLIVROS_BTNADLIVROS:
              frmVenderLivros_btnAdLivrosClick(hwnd);
            break;
            case ID_FRMVENDERLIVROS_LSTLIVROS:
            {
              if (HIWORD(wParam) == LBN_DBLCLK)
                frmVenderLivros_lstLivrosDoubleClick(hwnd);
            }
            break;
            case ID_FRMVENDERLIVROS_BTNVENDER:
              frmVenderLivros_btnVenderClick(hwnd);
            break;
            case ID_FRMVENDERLIVROS_BTNLIMPAR:
              frmVenderLivros_LimpaDados(hwnd);
            break;
            case ID_FRMVENDERLIVROS_BTNFECHAR: 
              if (bAtivaVender)   
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

VOID frmVenderLivros_LimpaDados(HWND hwnd) {
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTDTHRVENDA), 
    Rotinas_retDataHoraStr(TRUE, TRUE));  
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCLIENTE), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTISBN), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTLIVRO), "");
  SendMessage(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_LSTLIVROS), 
    LB_RESETCONTENT,0,0);
  slISBNs = ListaStr_inicia();
  slQtdEstoque = ListaStr_inicia();
  slPrecos = ListaStr_inicia();   
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTLIVRO), "");
  nPrecoTotal = 0;
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTPRECOTOTAL), "R$ 0,00");
  SetFocus(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF));
}


BOOL frmVenderLivros_ValidaDados(HWND hwnd)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTCPF), 
    Rotinas_lerStr(STR_CPFNINF)))
  	  return FALSE;
if (SendMessage(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_LSTLIVROS), 
  LB_GETCOUNT, 0, 0)==0) {
   MessageBox(hwnd, Rotinas_lerStr(STR_LIVVENNINF), 
     "Erro", MB_ICONERROR | MB_OK);
  return FALSE;
}
return TRUE;
}

BOOL frmVenderLivros_SalvaLista(HWND hwnd)
{ LPTSTR sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR;
INT nCont, nQtdEstoque, nQtd, nRad;

sPrecoTotal = Rotinas_alocaString(TAM_MAX_STR);
sQtdEstoque = Rotinas_alocaString(TAM_MAX_STR);
nRad = 10;

nQtd = SendMessage(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_LSTLIVROS), 
                   LB_GETCOUNT, 0, 0);
sCPF = Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTCPF);
gcvt(nPrecoTotal, nRad, sPrecoTotal);

sDTHR = Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTDTHRVENDA);
sDataHora = Rotinas_ConverteDataHoraStr(sDTHR, TRUE, "MM/dd/yyyy","HH:mm:ss");

for (nCont=0; nCont < nQtd; nCont++) {
  sISBN = ListaStr_pesquisaItemOrd(slISBNs, nCont);

  Rotinas_AtualizaDados(gConexao, ConsSQL_Venda('I',sISBN, sCPF, 
    sDataHora,Rotinas_VirgulaParaPonto(sPrecoTotal,FALSE),""));
  
  nQtdEstoque = atoi(ListaStr_pesquisaItemOrd(slQtdEstoque, nCont));
  nQtdEstoque--;
  itoa(nQtdEstoque, sQtdEstoque, 10);
  Rotinas_AtualizaDados(gConexao, ConsSQL_Venda('U',sISBN, 
    "","","", sQtdEstoque));
}
return TRUE;
}

VOID frmVenderLivros_edtCPFKillFocus(HWND hwnd)
{ LPTSTR sCPF, sCliente;
  LISTAMSTR ConsCampo;

  sCPF = Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTCPF);
  if (lstrcmp(sCPF,"")!=0) {
  	if (Rotinas_validaCPF(sCPF)) {      
      sCliente = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Cliente('S',
      sCPF,"","","","","","","","",""),Rotinas_lerStr(STR_CLINENC));    
      if (lstrcmp(sCliente,"")==0) {
        SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF),"");
    		SetFocus(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF));
      } else
         SetWindowText(GetDlgItem(hwnd, 
           ID_FRMVENDERLIVROS_EDTCLIENTE),sCliente);
    } else {
      MessageBox(hwnd, Rotinas_lerStr(STR_CPFINV),"Erro",MB_ICONERROR | MB_OK);
      SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF),"");
  		SetFocus(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF));
  	}
  } else
     SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCLIENTE),"");
}

VOID frmVenderLivros_btnPClienteClick(HWND hwnd)
{
  DialogBox(g_hInstancia, g_sFRMConClientes, hwnd, 
    (DLGPROC)frmConClientesProc);
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTCPF),
    Rotinas_sCodigoSelecionado);
  frmVenderLivros_edtCPFKillFocus(hwnd);
}

VOID frmVenderLivros_edtISBNKillFocus(HWND hwnd)
{ LPTSTR sISBN, sLivro;
  INT nQtdEstoque;
  LISTAMSTR ConsCampo;

  sISBN = Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTISBN);
  if (lstrcmp(sISBN,"")!=0) {
  	if (Rotinas_validaISBN(sISBN)) {      
      sLivro = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Livro('Q',
      sISBN,"","","","","","","","",""),Rotinas_lerStr(STR_LIVNENC));    
      if (lstrcmp(sLivro,"")==0) {
        SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTISBN),"");
    		SetFocus(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTISBN));
      } else {
         SetWindowText(GetDlgItem(hwnd, 
           ID_FRMVENDERLIVROS_EDTLIVRO),sLivro);                  
         nQtdEstoque = atoi(ListaStr_pesquisaItemOrdM(ConsCampo,3,0));
  		   if (nQtdEstoque > 0) {
  			   lstrcpy(Rotinas_sPreco, ListaStr_pesquisaItemOrdM(ConsCampo,2,0));
           lstrcpy(Rotinas_sQtdEstoque, ListaStr_pesquisaItemOrdM(ConsCampo,3,0));
  		   } else
           MessageBox(hwnd, Rotinas_lerStr(STR_LIVNEST),
             "Erro",MB_ICONERROR | MB_OK);
      }

    } else {
      MessageBox(hwnd, Rotinas_lerStr(STR_ISBNINV),"Erro",MB_ICONERROR | MB_OK);
      SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTISBN),"");
  		SetFocus(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTISBN));
  	}
  } else
     SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTLIVRO),"");
}

VOID frmVenderLivros_btnPLivroClick(HWND hwnd)
{
  DialogBox(g_hInstancia, g_sFRMConLivros, hwnd, (DLGPROC)frmConLivrosProc);
  SetWindowText(GetDlgItem(hwnd, ID_FRMVENDERLIVROS_EDTISBN),
    Rotinas_sCodigoSelecionado);
  frmVenderLivros_edtISBNKillFocus(hwnd);
}

VOID frmVenderLivros_btnAdLivrosClick(HWND hwnd)
{
 LPTSTR sLivros, sISBN, sEdtLivro, sPrecoTotal;

 sLivros = Rotinas_alocaString(TAM_MAX_STR);
 sPrecoTotal = Rotinas_alocaString(TAM_MAX_STR);

 sISBN = Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTISBN);
 sEdtLivro = Rotinas_retTexto(hwnd, ID_FRMVENDERLIVROS_EDTLIVRO);
 if (lstrcmp(sISBN,"")!=0) {
   wsprintf(sLivros, "%s - %s - R$ %s", sISBN, sEdtLivro, Rotinas_sPreco);
   if (SendMessage(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_LSTLIVROS), 
     LB_FINDSTRING, 0, (LPARAM) sLivros)==LB_ERR) {
     ListaStr_insereFim(&slISBNs, sISBN);
     ListaStr_insereFim(&slPrecos, Rotinas_sPreco);
     ListaStr_insereFim(&slQtdEstoque, Rotinas_sQtdEstoque);
     SendMessage(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_LSTLIVROS), 
       LB_ADDSTRING, 0, (LPARAM) sLivros);
   	 nPrecoTotal = nPrecoTotal + (FLOAT)atof(Rotinas_sPreco);
   }
   SetWindowText(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_EDTISBN), "");
   SetWindowText(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_EDTLIVRO), "");

   sprintf(sPrecoTotal,"R$ %.2f",nPrecoTotal);
   SetWindowText(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_EDTPRECOTOTAL), 
     Rotinas_VirgulaParaPonto(sPrecoTotal,TRUE));
 }
}

VOID frmVenderLivros_lstLivrosDoubleClick(HWND hwnd)
{ LPTSTR sPrecoTotal;
  FLOAT nPreco;
  INT nSelIndice;

  sPrecoTotal = Rotinas_alocaString(TAM_MAX_STR);

 if (SendMessage(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_LSTLIVROS), 
      LB_GETCOUNT, 0, 0) > 0) {   
   nSelIndice = SendMessage(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_LSTLIVROS), 
     LB_GETCURSEL, 0, 0);   
   if (SendMessage(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_LSTLIVROS), 
        LB_GETSEL, (WPARAM) nSelIndice, 0) > 0) {                 
     nPreco=(FLOAT)atof(ListaStr_pesquisaItemOrd(slPrecos,nSelIndice));
     nPrecoTotal=nPrecoTotal-nPreco;     
     sprintf(sPrecoTotal,"R$ %.2f",nPrecoTotal);
     SetWindowText(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_EDTPRECOTOTAL), 
       Rotinas_VirgulaParaPonto(sPrecoTotal,TRUE));
	   ListaStr_removeItemOrd(&slISBNs, nSelIndice, TRUE);
     ListaStr_removeItemOrd(&slPrecos, nSelIndice, TRUE);         
     ListaStr_removeItemOrd(&slQtdEstoque, nSelIndice, TRUE);     
	   SendMessage(GetDlgItem(hwnd,ID_FRMVENDERLIVROS_LSTLIVROS), 
       LB_DELETESTRING, (WPARAM) nSelIndice, 0);
   }	
 }
}

VOID frmVenderLivros_btnVenderClick(HWND hwnd)
{
   if (frmVenderLivros_ValidaDados(hwnd)) {
      if (frmVenderLivros_SalvaLista(hwnd)) {
        MessageBox(hwnd, Rotinas_lerStr(STR_VENRESUC),
          Rotinas_lerStr(STR_TITULO),MB_ICONINFORMATION | MB_OK);
        frmVenderLivros_LimpaDados(hwnd);
      }
   }
}

