#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>
#include <stdlib.h>
#include <stdio.h>

#include "Livrus.h"
#include "Principal.h"
#include "Consultas.h"
#include "Cadastros.h"
#include "resource.h"
#include "ConVendas.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

LISTAMSTR lstLinVendas;
HWND hLstVendas;
LPTSTR sSelVendas;
BOOL bAtivaVendas;
    
LRESULT CALLBACK frmConVendasProc(HWND hwnd, UINT Message, WPARAM wParam, 
    LPARAM lParam )
{ 
   switch( Message ) {
      case WM_CREATE:
      {      
        if (!frmCadastros_Criar(hwnd, g_sFRMConVendas, 
                (DLGPROC)frmConVendasProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCONVENDAS_EDTDTHRVENDA, 19);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCONVENDAS_EDTCPF, 14);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCONVENDAS_EDTISBN, 13);

        hLstVendas = GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA),
          ID_FRMCONVENDAS_LISTCONSULTA);
        
        //hLstVendas = Rotinas_criaVisaoLista(hwnd, 
        //ID_FRMCONVENDAS_LISTCONSULTA, 0, 0, 165);
            
        LISTASTR sColunas;
        UINT nLargura[] = { 120, 100, 220, 100, 280, 80 };
        sColunas = ListaStr_inicia();
        ListaStr_insereFim(&sColunas, "Data/Hora Venda");
        ListaStr_insereFim(&sColunas, "CPF");
        ListaStr_insereFim(&sColunas, "Cliente");
        ListaStr_insereFim(&sColunas, "ISBN");
        ListaStr_insereFim(&sColunas, "Livro");
        ListaStr_insereFim(&sColunas, "Preço");
          
        Rotinas_VisaoListaInsereColunas(hLstVendas, nLargura, sColunas);

    		SetWindowText(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCONVENDAS_EDTDTHRVENDA), Rotinas_retDataHoraStr(TRUE, TRUE));
        SetWindowText(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCONVENDAS_EDTPRECOTOTAL), "R$ 0,00");
        return TRUE;
      }
      break;       
      case WM_MDIACTIVATE:
      {
        bAtivaVendas = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCONVENDAS_EDTDTHRVENDA, 2, CM_VEN_VENDASREALIZADAS);               
                  
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         frmCadastros_Fechar(hwnd, 2, CM_VEN_VENDASREALIZADAS);
      }  
      break;
      case WM_COMMAND:
      {
         switch( LOWORD(wParam) ) {
			    case ID_FRMCONVENDAS_EDTDTHRVENDA:
			    {
			       if (HIWORD(wParam) == EN_KILLFOCUS)
              frmConVendas_edtDtHrVendaKillFocus(hwnd);
			    }
			    break;
          case ID_FRMCONVENDAS_EDTISBN:
          {            
             if (HIWORD(wParam) == EN_KILLFOCUS)
               frmConVendas_edtISBNKillFocus(hwnd);
          }
          break;
          case ID_FRMCONVENDAS_EDTCPF:
          {            
             if (HIWORD(wParam) == EN_KILLFOCUS)
               frmConVendas_edtCPFKillFocus(hwnd);
          }
          break;
          case ID_FRMCONVENDAS_BTNPCLIENTE:
            frmConVendas_btnPClienteClick(hwnd);
          break;
          case ID_FRMCONVENDAS_BTNPLIVRO:
            frmConVendas_btnPLivroClick(hwnd);
          break;
			    case ID_FRMCONVENDAS_BTNPESQUISAR: 
            frmConVendas_PesquisarDados(hwnd);
			    break;
			    case ID_FRMCONVENDAS_BTNLIMPAR: 
			      frmConVendas_btnLimparClick(hwnd);
			    break;
			    case ID_FRMCONVENDAS_BTNFECHAR: 
            if (bAtivaVendas) 
              DestroyWindow(g_hTelaAtiva);
			    break;
        }
      }   
      break;
      case WM_NOTIFY:
      { 
        if (frmConsultas_Notifica(hwnd, lParam, hLstVendas,
            ID_FRMCONVENDAS_LABREGISTROS, lstLinVendas, &sSelVendas))
             return 0;
      }      
      break;
      case WM_SIZE:
        frmConVendas_arrumaTamanho(hwnd);
      break;      
   }
  
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

VOID frmConVendas_edtDtHrVendaKillFocus(HWND hwnd)
{ LPTSTR sDTHR;

  sDTHR = Rotinas_retTexto(hwnd, ID_FRMCONVENDAS_EDTDTHRVENDA);
  if (strlen(sDTHR) > 0) {
    if (Rotinas_validaDataHora(sDTHR, FALSE)==FALSE) {
	    MessageBox(hwnd, Rotinas_lerStr(STR_DTHRINV), "Erro", MB_ICONERROR | MB_OK);
      SetFocus(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTDTHRVENDA));
    }
  }
}

VOID frmConVendas_btnLimparClick(HWND hwnd) 
{ 
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCPF), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCLIENTE), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTISBN), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTLIVRO), "");
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTPRECOTOTAL), "R$ 0,00");

  frmConsultas_LimparDados(hwnd, ID_FRMCONVENDAS_LABREGISTROS, 
  ID_FRMCONVENDAS_EDTDTHRVENDA, hLstVendas, lstLinVendas);

  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTDTHRVENDA),
	Rotinas_retDataHoraStr(TRUE, TRUE));

}

LPTSTR frmConVendas_ConsVenda(HWND hwnd, TCHAR sOpcao)  
{
  LPTSTR sISBN, sCPF, sDtHrVenda, sDataHora;

  sDataHora = Rotinas_alocaString(TAM_MAX_STR);
  sDtHrVenda = Rotinas_retTexto(hwnd, ID_FRMCONVENDAS_EDTDTHRVENDA);
  
  if (lstrlen(sDtHrVenda) > 0)
    sDataHora = Rotinas_ConverteDataHoraStr(sDtHrVenda, TRUE,
      "yyyy-MM-dd","HH:mm:ss");
  else
    lstrcpy(sDataHora, "");   

  sISBN = Rotinas_retTexto(hwnd, ID_FRMCONVENDAS_EDTISBN);
  sCPF = Rotinas_retTexto(hwnd, ID_FRMCONVENDAS_EDTCPF);

  if (sOpcao=='L')
    return ConsSQL_Venda('S',"ZERO","","","","");
  else
    return ConsSQL_Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");  
}

VOID frmConVendas_PesquisarDados(HWND hwnd)
{
  LISTAMSTR ConsTotal;  
  LPTSTR sPrecoTotal;
  FLOAT nTemp;

  sPrecoTotal = Rotinas_alocaString(TAM_MAX_STR);

  if (Rotinas_ConsultaDadosLista(gConexao, &lstLinVendas, 
        frmConVendas_ConsVenda(hwnd,'S'))) {
     Rotinas_VisaoListaInsereLinhas(hLstVendas, lstLinVendas);
     frmConsultas_setLabRegistros(hwnd, 
       ID_FRMCONVENDAS_LABREGISTROS, lstLinVendas, 1);

     if (Rotinas_ConsultaDadosLista(gConexao, &ConsTotal, 
          frmConVendas_ConsVenda(hwnd,'P'))) {       
  	   if (ListaStr_contaM(ConsTotal) > 0) {
         nTemp = (FLOAT)atof(ConsTotal->str[0]);
         sprintf(sPrecoTotal, "R$ %.2f", nTemp);
  		   SetWindowText(GetDlgItem(hwnd, 
           ID_FRMCONVENDAS_EDTPRECOTOTAL),sPrecoTotal);
  	   }
     }

  } else {
     MessageBox(hwnd, Rotinas_lerStr(STR_VENNENC), 
       "Erro", MB_ICONERROR | MB_OK);
  }
}

VOID frmConVendas_edtCPFKillFocus(HWND hwnd)
{ LPTSTR sCPF, sCliente;
  LISTAMSTR ConsCampo;

  sCPF = Rotinas_retTexto(hwnd, ID_FRMCONVENDAS_EDTCPF);
  if (lstrcmp(sCPF,"")!=0) {
  	if (Rotinas_validaCPF(sCPF)) {      
      sCliente = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Cliente('S',
      sCPF,"","","","","","","","",""),Rotinas_lerStr(STR_CLINENC));    
      if (lstrcmp(sCliente,"")==0) {
        SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCPF),"");
    		SetFocus(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCPF));
      } else
         SetWindowText(GetDlgItem(hwnd, 
           ID_FRMCONVENDAS_EDTCLIENTE),sCliente);
    } else {
      MessageBox(hwnd, Rotinas_lerStr(STR_CPFINV),"Erro",MB_ICONERROR | MB_OK);
      SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCPF),"");
  		SetFocus(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCPF));
  	}
  } else
     SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCLIENTE),"");
}

VOID frmConVendas_btnPClienteClick(HWND hwnd)
{
  DialogBox(g_hInstancia, g_sFRMConClientes, hwnd, 
    (DLGPROC)frmConClientesProc);
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTCPF),
    Rotinas_sCodigoSelecionado);
  frmConVendas_edtCPFKillFocus(hwnd);
}

VOID frmConVendas_edtISBNKillFocus(HWND hwnd)
{ LPTSTR sISBN, sLivro;
  INT nQtdEstoque;
  LISTAMSTR ConsCampo;

  sISBN = Rotinas_retTexto(hwnd, ID_FRMCONVENDAS_EDTISBN);
  if (lstrcmp(sISBN,"")!=0) {
  	if (Rotinas_validaISBN(sISBN)) {      
      sLivro = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Livro('Q',
      sISBN,"","","","","","","","",""),Rotinas_lerStr(STR_LIVNENC));    
      if (lstrcmp(sLivro,"")==0) {
        SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTISBN),"");
    		SetFocus(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTISBN));
      } else {
         SetWindowText(GetDlgItem(hwnd, 
           ID_FRMCONVENDAS_EDTLIVRO),sLivro);                  
         nQtdEstoque = atoi(ListaStr_pesquisaItemOrdM(ConsCampo,3,0));
  		   if (nQtdEstoque > 0)
  			   lstrcpy(Rotinas_sPreco, ListaStr_pesquisaItemOrdM(ConsCampo,2,0));
  		   else
           MessageBox(hwnd, Rotinas_lerStr(STR_LIVNEST),
             "Erro",MB_ICONERROR | MB_OK);
      }

    } else {
      MessageBox(hwnd, Rotinas_lerStr(STR_ISBNINV),"Erro",MB_ICONERROR | MB_OK);
      SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTISBN),"");
  		SetFocus(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTISBN));
  	}
  } else
     SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTLIVRO),"");
}

VOID frmConVendas_btnPLivroClick(HWND hwnd)
{
  DialogBox(g_hInstancia, g_sFRMConLivros, hwnd, (DLGPROC)frmConLivrosProc);
  SetWindowText(GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTISBN),
    Rotinas_sCodigoSelecionado);
  frmConVendas_edtISBNKillFocus(hwnd);
}

VOID frmConVendas_arrumaTamanho(HWND hwnd)
{ 
  HWND hLabPreco, hEdtPreco;
  RECT rForm, rLabPreco, rEdtPreco;
  INT hFrm, wFrm;
  
  frmConsultas_arrumaTamanho(hwnd, 
  ID_FRMCONVENDAS_LISTCONSULTA, 
  ID_FRMCONVENDAS_LABREGISTROS, ID_FRMCONVENDAS_BTNLIMPAR, 
  ID_FRMCONVENDAS_BTNFECHAR);       
  
  hLabPreco = GetDlgItem(hwnd, ID_FRMCONVENDAS_LABPRECOTOTAL);
  hEdtPreco = GetDlgItem(hwnd, ID_FRMCONVENDAS_EDTPRECOTOTAL);        
          
  GetClientRect(hwnd, &rForm);       
  GetWindowRect(hLabPreco, &rLabPreco);
  GetWindowRect(hEdtPreco, &rEdtPreco);
          
  hFrm = (rForm.bottom - rForm.top);
  wFrm = (rForm.right - rForm.left);
  
  MoveWindow((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 0, 0, wFrm, hFrm, TRUE);
  MoveWindow(hLstVendas, 0, 125, wFrm, hFrm - 190, TRUE);
  MoveWindow(hLabPreco, (wFrm - 200), (hFrm - 60),
  (rLabPreco.right - rLabPreco.left), (rLabPreco.bottom - rLabPreco.top), TRUE);
  MoveWindow(hEdtPreco, (wFrm - 140), (hFrm - 60), 
  (rEdtPreco.right - rEdtPreco.left), (rEdtPreco.bottom - rEdtPreco.top), TRUE);
}  
