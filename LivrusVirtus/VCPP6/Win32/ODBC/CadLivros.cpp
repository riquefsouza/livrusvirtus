#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Livrus.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadLivros.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

LISTAMSTR lstRegLivros;
UINT nRegLivros;
LISTASTR slAssuntos, slAutores, slIdiomas;
BOOL bAtivaLivros;

LRESULT CALLBACK frmCadLivrosProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadLivros, 
                (DLGPROC)frmCadLivrosProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTISBN, 13);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTTITULO, 50);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTEDICAO, 4);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTANOPUBLI, 4);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA, 5);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTVOLUME, 4);        
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTNPAGINAS, 5);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTPRECO, 7);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADLIVROS_EDTQTDESTOQUE, 5);
        
        SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                CM_CAD_LIVROS, MAKELONG(FALSE, 0));

        SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCADLIVROS_SPINEDICAO),
          UDM_SETRANGE, 0, (LPARAM) MAKELONG((short) 9999, (short) 1));
        SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCADLIVROS_SPINANOPUBLI),
          UDM_SETRANGE, 0, (LPARAM) MAKELONG((short) 9999, (short) 1));
        SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCADLIVROS_SPINVOLUME),
          UDM_SETRANGE, 0, (LPARAM) MAKELONG((short) 9999, (short) 1));
        SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCADLIVROS_SPINNPAGINAS),
          UDM_SETRANGE, 0, (LPARAM) MAKELONG((short) 9999, (short) 1));
        SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
          ID_FRMCADLIVROS_SPINQTDESTOQUE),
          UDM_SETRANGE, 0, (LPARAM) MAKELONG((short) 9999, (short) 0));

        frmCadLivros_AdicionaCombo(hwnd);

	      slAssuntos = ListaStr_inicia();
        slAutores = ListaStr_inicia();

        nRegLivros = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaLivros = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADLIVROS_EDTISBN, 0, CM_CAD_LIVROS);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
         SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                CM_CAD_LIVROS, MAKELONG(TRUE, 0));
      
         frmCadastros_Fechar(hwnd, 0, CM_CAD_LIVROS);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADLIVROS_EDTISBN:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadLivros_edtISBNKillFocus(hwnd);
            }
            break;
            case ID_FRMCADLIVROS_EDTCODEDITORA:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadLivros_edtCodEditoraKillFocus(hwnd);
            }
            break;
            case ID_FRMCADLIVROS_EDTPRECO:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadLivros_edtPrecoKillFocus(hwnd);
            }
            break;
            case ID_FRMCADLIVROS_EDTCODASSUNTO:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadLivros_edtCodAssuntoKillFocus(hwnd);
            }
            break;
            case ID_FRMCADLIVROS_EDTCODAUTOR:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadLivros_edtCodAutorKillFocus(hwnd);
            }
            break;
            case ID_FRMCADLIVROS_BTNPEDITORA:
              frmCadLivros_btnPEditoraClick(hwnd);
            break;
            case ID_FRMCADLIVROS_BTNPASSUNTO:
              frmCadLivros_btnPAssuntoClick(hwnd);
            break;
            case ID_FRMCADLIVROS_BTNADASSUNTOS:
              Rotinas_AdicionaItemLista(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTASSUNTOS),
                &slAssuntos, GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO),
                GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTASSUNTO));
            break;
            case ID_FRMCADLIVROS_LSTASSUNTOS:
            {
              if (HIWORD(wParam) == LBN_DBLCLK)
                Rotinas_RemoveItemLista(
                  GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTASSUNTOS),&slAssuntos);
            }
            break;
            case ID_FRMCADLIVROS_BTNPAUTOR:
              frmCadLivros_btnPAutorClick(hwnd);
            break;
            case ID_FRMCADLIVROS_BTNADAUTORES:
              Rotinas_AdicionaItemLista(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTAUTORES),
                &slAutores, GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR),
                GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTAUTOR));
            break;
            case ID_FRMCADLIVROS_LSTAUTORES:
            {
              if (HIWORD(wParam) == LBN_DBLCLK)
              Rotinas_RemoveItemLista(
                GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTAUTORES),&slAutores);
            }
            break;
            case ID_FRMCADLIVROS_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADLIVROS_EDTISBN, 
              ID_FRMCADLIVROS_EDTTITULO, ID_FRMCADLIVROS_BTNNOVO,
              ID_FRMCADLIVROS_BTNPESQUISAR, ID_FRMCADLIVROS_BTNANTERIOR,
              ID_FRMCADLIVROS_BTNPROXIMO, ID_FRMCADLIVROS_BTNSALVAR,
              ID_FRMCADLIVROS_BTNEXCLUIR);

              frmCadLivros_InformaLimpaDados(hwnd, NULL, 0, FALSE);
              frmCadLivros_HabilitaDados(hwnd, TRUE);	
            }
            break;
            case ID_FRMCADLIVROS_BTNPESQUISAR:
            {
              if (frmCadastros_PesquisarDados(hwnd, &lstRegLivros, 
              ID_FRMCADLIVROS_EDTISBN, ID_FRMCADLIVROS_EDTTITULO,
              ID_FRMCADLIVROS_BTNPESQUISAR, ID_FRMCADLIVROS_BTNANTERIOR,
              ID_FRMCADLIVROS_BTNPROXIMO, ID_FRMCADLIVROS_BTNSALVAR,
              ID_FRMCADLIVROS_BTNEXCLUIR, ConsSQL_Livro('S',
              Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN),
              "","","","","","","","",""), Rotinas_lerStr(STR_LIVNENC))) {
                frmCadLivros_InformaLimpaDados(hwnd,lstRegLivros,0, TRUE);
                frmCadLivros_HabilitaDados(hwnd, TRUE);	
              }
            }
            break;
            case ID_FRMCADLIVROS_BTNANTERIOR:
            {
              if (frmCadastros_registroAnterior(hwnd, lstRegLivros, 
              ID_FRMCADLIVROS_EDTISBN, ID_FRMCADLIVROS_EDTTITULO,
              &nRegLivros)) {
                frmCadLivros_InformaLimpaDados(hwnd,lstRegLivros,
                  nRegLivros, TRUE);              
              }  
            }
            break;
            case ID_FRMCADLIVROS_BTNPROXIMO:
            {
              if (frmCadastros_registroProximo(hwnd, lstRegLivros, 
              ID_FRMCADLIVROS_EDTISBN, ID_FRMCADLIVROS_EDTTITULO,
              &nRegLivros)) {
                frmCadLivros_InformaLimpaDados(hwnd,lstRegLivros,
                  nRegLivros, TRUE);              
              }  
            }
            break;
            case ID_FRMCADLIVROS_BTNSALVAR:
            {
              LPTSTR sCodIdioma, sSqlInsert, sSqlUpdate;
              UINT nPos;
              
              sCodIdioma = Rotinas_alocaString(TAM_MAX_STR);
              sSqlInsert = Rotinas_alocaString(TAM_MAX_STR * 2);
              sSqlUpdate = Rotinas_alocaString(TAM_MAX_STR * 2);

              nPos = SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_CMBIDIOMA), 
                CB_GETCURSEL, 0, 0);
              sCodIdioma = ListaStr_pesquisaItemOrd(slIdiomas, nPos);             

              sSqlUpdate = ConsSQL_Livro('U',
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTTITULO),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTEDICAO), 
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTANOPUBLI),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTVOLUME),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA), 
                sCodIdioma,
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTNPAGINAS),
                Rotinas_VirgulaParaPonto(
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTPRECO),FALSE),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTQTDESTOQUE));
              
              sSqlInsert = ConsSQL_Livro('I',
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTTITULO),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTEDICAO), 
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTANOPUBLI),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTVOLUME),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA), 
                sCodIdioma,
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTNPAGINAS),
                Rotinas_VirgulaParaPonto(
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTPRECO),FALSE),
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTQTDESTOQUE));

              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADLIVROS_EDTISBN, 
                ID_FRMCADLIVROS_EDTTITULO, ID_FRMCADLIVROS_BTNNOVO,
                ID_FRMCADLIVROS_BTNPESQUISAR, ID_FRMCADLIVROS_BTNANTERIOR,
                ID_FRMCADLIVROS_BTNPROXIMO, ID_FRMCADLIVROS_BTNSALVAR,
                ID_FRMCADLIVROS_BTNEXCLUIR, 
                frmCadLivros_ValidaDados(hwnd, TRUE),
                ConsSQL_Livro('S',
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN),
                "","","","","","","","",""), sSqlUpdate, sSqlInsert, FALSE)) {
                	frmCadLivros_SalvaLista(hwnd, 'A');
                	frmCadLivros_SalvaLista(hwnd, 'B');
                  frmCadastros_btnLimparClick(hwnd, ID_FRMCADLIVROS_EDTISBN, 
                    ID_FRMCADLIVROS_EDTTITULO, ID_FRMCADLIVROS_BTNNOVO,
                    ID_FRMCADLIVROS_BTNPESQUISAR, ID_FRMCADLIVROS_BTNANTERIOR,
                    ID_FRMCADLIVROS_BTNPROXIMO, ID_FRMCADLIVROS_BTNSALVAR,
                    ID_FRMCADLIVROS_BTNEXCLUIR);
                  frmCadLivros_InformaLimpaDados(hwnd, NULL, 0, FALSE);
                  frmCadLivros_HabilitaDados(hwnd, FALSE);	
              }
            }
            break;
            case ID_FRMCADLIVROS_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADLIVROS_EDTISBN, 
              ID_FRMCADLIVROS_EDTTITULO, ID_FRMCADLIVROS_BTNNOVO,
              ID_FRMCADLIVROS_BTNPESQUISAR, ID_FRMCADLIVROS_BTNANTERIOR,
              ID_FRMCADLIVROS_BTNPROXIMO, ID_FRMCADLIVROS_BTNSALVAR,
              ID_FRMCADLIVROS_BTNEXCLUIR, 
              frmCadLivros_ValidaDados(hwnd, FALSE),
              ConsSQL_Livro('D',
                Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN),
                "","","","","","","","",""))) {
                frmCadLivros_InformaLimpaDados(hwnd, NULL, 0, FALSE);
                frmCadLivros_HabilitaDados(hwnd, FALSE);	
              }  
            }
            break;
            case ID_FRMCADLIVROS_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADLIVROS_EDTISBN, 
              ID_FRMCADLIVROS_EDTTITULO, ID_FRMCADLIVROS_BTNNOVO,
              ID_FRMCADLIVROS_BTNPESQUISAR, ID_FRMCADLIVROS_BTNANTERIOR,
              ID_FRMCADLIVROS_BTNPROXIMO, ID_FRMCADLIVROS_BTNSALVAR,
              ID_FRMCADLIVROS_BTNEXCLUIR);

              frmCadLivros_InformaLimpaDados(hwnd, NULL, 0, FALSE);
              frmCadLivros_HabilitaDados(hwnd, FALSE);	
            }
            break;
            case ID_FRMCADLIVROS_BTNFECHAR: 
              if (bAtivaLivros)
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadLivros_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN), 
    Rotinas_lerStr(STR_ISBNNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTTITULO), 
           Rotinas_lerStr(STR_TITNINF)))
  		    return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTEDITORA), 
           Rotinas_lerStr(STR_EDTNINF)))
  		    return FALSE;
      if (SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTASSUNTOS), 
        LB_GETCOUNT, 0, 0)==0) {
         MessageBox(hwnd, Rotinas_lerStr(STR_ASSNINF), 
           "Erro", MB_ICONERROR | MB_OK);
        return FALSE;
      }
      if (SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTAUTORES), 
        LB_GETCOUNT, 0, 0)==0) {
         MessageBox(hwnd, Rotinas_lerStr(STR_AUTNINF), 
           "Erro", MB_ICONERROR | MB_OK);
        return FALSE;
      }
  	}
  	return TRUE;
}

VOID frmCadLivros_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar)
{ 
  if (bInformar) {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDICAO), 
      ListaStr_pesquisaItemOrdM(lstRegistros, 2, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTANOPUBLI),
      ListaStr_pesquisaItemOrdM(lstRegistros, 3, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTVOLUME),
      ListaStr_pesquisaItemOrdM(lstRegistros, 4, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA),
      ListaStr_pesquisaItemOrdM(lstRegistros, 5, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDITORA),
      ListaStr_pesquisaItemOrdM(lstRegistros, 6, nLinhaRegistro));
    SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_CMBIDIOMA), CB_SELECTSTRING,
      0, (LPARAM) ListaStr_pesquisaItemOrdM(lstRegistros, 8, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTNPAGINAS),
      ListaStr_pesquisaItemOrdM(lstRegistros, 9, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTPRECO),
      Rotinas_VirgulaParaPonto(
      ListaStr_pesquisaItemOrdM(lstRegistros, 10, nLinhaRegistro),TRUE));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTQTDESTOQUE),
      ListaStr_pesquisaItemOrdM(lstRegistros, 11, nLinhaRegistro));
    Rotinas_AdicionaValoresLista(ConsSQL_LivroAss('S',
      Rotinas_retTexto(hwnd,ID_FRMCADLIVROS_EDTISBN),""),
      GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTASSUNTOS),&slAssuntos);      
    Rotinas_AdicionaValoresLista(ConsSQL_LivroAut('S',
      Rotinas_retTexto(hwnd,ID_FRMCADLIVROS_EDTISBN),""),
      GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTAUTORES),&slAutores);
  } else {  
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDICAO),"1");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTANOPUBLI),
      Rotinas_subString(Rotinas_retDataHoraStr(TRUE,FALSE),7,4));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTVOLUME),"1");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDITORA),"");
    SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_CMBIDIOMA), CB_SETCURSEL,
      (WPARAM) 0, 0);    
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTNPAGINAS),"1");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTPRECO),"0,00");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTQTDESTOQUE),"1");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO),"");
    SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTASSUNTOS),
      LB_RESETCONTENT,0,0);
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR),"");
    SendMessage(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTAUTORES),
      LB_RESETCONTENT,0,0);
    ListaStr_libera(slAssuntos);
    ListaStr_libera(slAutores);
    nRegLivros = 0;
  }
} 

VOID frmCadLivros_HabilitaDados(HWND hwnd, BOOL bHabilita)
{
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDICAO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTANOPUBLI),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTVOLUME),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_BTNPEDITORA),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_CMBIDIOMA),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTNPAGINAS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTPRECO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTQTDESTOQUE),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_BTNPASSUNTO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_BTNADASSUNTOS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTASSUNTOS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_BTNPAUTOR),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_BTNADAUTORES),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_LSTAUTORES),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_SPINEDICAO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_SPINANOPUBLI),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_SPINVOLUME),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_SPINNPAGINAS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADLIVROS_SPINQTDESTOQUE),bHabilita);
}

VOID frmCadLivros_edtISBNKillFocus(HWND hwnd)
{ LPTSTR sISBN;
  sISBN = Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN);

  if (lstrcmp(sISBN,"")!=0) {
  	if (Rotinas_validaISBN(sISBN)==FALSE) {      
      MessageBox(hwnd, Rotinas_lerStr(STR_ISBNINV),"Erro",MB_ICONERROR | MB_OK);
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTISBN),"");
  		SetFocus(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTISBN));
  	}
  }
}

VOID frmCadLivros_AdicionaCombo(HWND hwnd) 
{
  LISTAMSTR Campos, local;

  if (Rotinas_ConsultaDadosLista(gConexao, &Campos, ConsSQL_Idioma('S',"",""))) {
	  slIdiomas = ListaStr_inicia();
	  for (local = Campos; local != NULL; local = local->proximo) {	
	    ListaStr_insereFim(&slIdiomas, local->str[0]);
	    SendMessage(GetDlgItem((HWND)GetWindowLong(hwnd, HWNDMDIFILHA), 
        ID_FRMCADLIVROS_CMBIDIOMA), 
        CB_ADDSTRING, 0, (LPARAM) local->str[1]);
	  }      
  }
  ListaStr_liberaM(Campos);
  ListaStr_liberaM(local);

}

VOID frmCadLivros_SalvaLista(HWND hwnd, CHAR sOpcao) 
{
LPTSTR sISBN;
INT nCont, nQtd;

  sISBN = Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTISBN);
  if (sOpcao=='A') {
    Rotinas_AtualizaDados(gConexao, ConsSQL_LivroAss('D',sISBN,""));
   
    nQtd = ListaStr_conta(slAssuntos);
    for (nCont=0; nCont < nQtd; nCont++)  {      
      Rotinas_AtualizaDados(gConexao, ConsSQL_LivroAss('I', 
        sISBN, ListaStr_pesquisaItemOrd(slAssuntos, nCont)));
    }
  } else if (sOpcao=='B') {
  	Rotinas_AtualizaDados(gConexao,ConsSQL_LivroAut('D',sISBN,""));

    nQtd = ListaStr_conta(slAutores);    
  	for (nCont=0; nCont < nQtd; nCont++)  {
  	  Rotinas_AtualizaDados(gConexao, ConsSQL_LivroAut('I', 
        sISBN, ListaStr_pesquisaItemOrd(slAutores, nCont)));
  	}
  }
}

VOID frmCadLivros_edtCodEditoraKillFocus(HWND hwnd)
{ LPTSTR sCodEditora, sEditora;
  LISTAMSTR ConsCampo;
  sCodEditora = Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA);

  if (lstrcmp(sCodEditora,"")!=0) {
    sEditora = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Editora('S',
    sCodEditora,""),Rotinas_lerStr(STR_EDTNENC));    
    ListaStr_liberaM(ConsCampo);
    if (lstrcmp(sEditora,"")!=0) {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDITORA),sEditora);
    } else {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA),"");
      SetFocus(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA));
    }
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTEDITORA),"");
  }
}

VOID frmCadLivros_btnPEditoraClick(HWND hwnd)
{
  DialogBox( g_hInstancia, g_sFRMConEditoras, hwnd, (DLGPROC)frmConEditorasProc );
  SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODEDITORA),
    Rotinas_sCodigoSelecionado);
  frmCadLivros_edtCodEditoraKillFocus(hwnd);
}

VOID frmCadLivros_edtPrecoKillFocus(HWND hwnd)
{ LPTSTR sPreco;

  sPreco = Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTPRECO);
  if (Rotinas_ValidaFloat(Rotinas_VirgulaParaPonto(sPreco, FALSE)))
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTPRECO),
      Rotinas_VirgulaParaPonto(sPreco, TRUE));
  else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTPRECO),"0,01");
    SetFocus(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTPRECO));
  }
}

VOID frmCadLivros_edtCodAssuntoKillFocus(HWND hwnd)
{ LPTSTR sCodAssunto, sAssunto;
  LISTAMSTR ConsCampo;
  sCodAssunto = Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO);

  if (lstrcmp(sCodAssunto,"")!=0) {
    sAssunto = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Assunto('S',
    sCodAssunto,""),Rotinas_lerStr(STR_ASSNENC));    
    ListaStr_liberaM(ConsCampo);
    if (lstrcmp(sAssunto,"")!=0) {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTASSUNTO),sAssunto);
    } else {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO),"");
      SetFocus(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO));
    }
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTASSUNTO),"");
  }
}

VOID frmCadLivros_btnPAssuntoClick(HWND hwnd)
{
  DialogBox(g_hInstancia, g_sFRMConAssuntos, hwnd, (DLGPROC)frmConAssuntosProc);
  SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODASSUNTO),
    Rotinas_sCodigoSelecionado);
  frmCadLivros_edtCodAssuntoKillFocus(hwnd);
}

VOID frmCadLivros_edtCodAutorKillFocus(HWND hwnd)
{ LPTSTR sCodAutor, sAutor;
  LISTAMSTR ConsCampo;
  sCodAutor = Rotinas_retTexto(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR);

  if (lstrcmp(sCodAutor,"")!=0) {
    sAutor = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Autor('S',
    sCodAutor,""),Rotinas_lerStr(STR_AUTNENC));    
    ListaStr_liberaM(ConsCampo);
    if (lstrcmp(sAutor,"")!=0) {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTAUTOR),sAutor);
    } else {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR),"");
      SetFocus(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR));
    }
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTAUTOR),"");
  }
}

VOID frmCadLivros_btnPAutorClick(HWND hwnd)
{
  DialogBox(g_hInstancia, g_sFRMConAutores, hwnd, (DLGPROC)frmConAutoresProc);
  SetWindowText(GetDlgItem(hwnd, ID_FRMCADLIVROS_EDTCODAUTOR),
    Rotinas_sCodigoSelecionado);
  frmCadLivros_edtCodAutorKillFocus(hwnd);
}

