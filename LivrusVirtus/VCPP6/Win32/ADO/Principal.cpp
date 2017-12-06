#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>
#include <commdlg.h>

#include "Livrus.h"
#include "resource.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "Splash.h"
#include "Login.h"
#include "AlterarSenha.h"
#include "Sobre.h"
#include "CadAssuntos.h"
#include "ConAssuntos.h"
#include "CadAutores.h"
#include "ConAutores.h"
#include "CadEditoras.h"
#include "ConEditoras.h"
#include "CadEnderecos.h"
#include "ConEnderecos.h"
#include "CadIdiomas.h"
#include "ConIdiomas.h"
#include "CadPaises.h"
#include "ConPaises.h"
#include "CadProfissoes.h"
#include "ConProfissoes.h"
#include "CadClientes.h"
#include "ConClientes.h"
#include "CadLivros.h"
#include "ConLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"

HWND g_hMDICliente, g_hBarraStatus, g_hBarraFerram;
HWND g_hFRMPrincipal;
HWND g_hDlgAtual;
HWND g_hTelaAtiva;

LRESULT CALLBACK frmPrincipalProc(HWND hwnd, UINT Message, 
                                  WPARAM wParam, LPARAM lParam)
{
   switch(Message)
   {
      case WM_CREATE:
      {
         CLIENTCREATESTRUCT ccs;
         int iStatusWidths[] = {100, -1};
         TBADDBITMAP tbab;
         TBBUTTON tbb[6];

         // Acha no menu onde as janelas filhas serão listadas
         ccs.hWindowMenu  = GetSubMenu(GetMenu(hwnd), 3);
         ccs.idFirstChild = ID_MDI_PRIMEIROFORM;
         g_hMDICliente = CreateWindowEx(WS_EX_CLIENTEDGE, "MDICLIENT", NULL,
            WS_CHILD | WS_CLIPCHILDREN | WS_VSCROLL | WS_HSCROLL | WS_TABSTOP,
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
            hwnd, (HMENU)ID_MDI_CLIENTE, g_hInstancia, (LPVOID)&ccs);
         ShowWindow(g_hMDICliente, SW_SHOW);

         g_hBarraStatus = CreateWindowEx(0, STATUSCLASSNAME, NULL,
            WS_CHILD | WS_VISIBLE | SBARS_SIZEGRIP, 0, 0, 0, 0,
            hwnd, (HMENU)ID_BARRADESTATUS, g_hInstancia, NULL);
         SendMessage(g_hBarraStatus, SB_SETPARTS, 2, (LPARAM)iStatusWidths);
         SendMessage(g_hBarraStatus, SB_SETTEXT, 0, 
                  (LPARAM)Rotinas_lerStr(STR_USUARIO));

         g_hBarraFerram = CreateWindowEx(0, TOOLBARCLASSNAME, NULL,
            WS_CHILD | WS_VISIBLE, 0, 0, 0, 0,
            hwnd, (HMENU)ID_BARRADEFERRAMENTAS, g_hInstancia, NULL);

         // Envia a mensagem TB_BUTTONSTRUCTSIZE, a qual é requerida para
         // compatibilidade retroativa.
         SendMessage(g_hBarraFerram, TB_BUTTONSTRUCTSIZE, 
                  (WPARAM)sizeof(TBBUTTON), 0);

         tbab.hInst = g_hInstancia;
         tbab.nID = ID_BMP_BARRAFERRAM;
         SendMessage(g_hBarraFerram, TB_ADDBITMAP, 5, (LPARAM)&tbab);

         ZeroMemory(tbb, sizeof(tbb));

         tbb[0].iBitmap = 0;
         tbb[0].fsState = TBSTATE_ENABLED;
         tbb[0].fsStyle = TBSTYLE_BUTTON;
         tbb[0].idCommand = CM_CAD_CLIENTES;

         tbb[1].iBitmap = 1;
         tbb[1].fsState = TBSTATE_ENABLED;
         tbb[1].fsStyle = TBSTYLE_BUTTON;
         tbb[1].idCommand = CM_CAD_LIVROS;

         tbb[2].iBitmap = 2;
         tbb[2].fsState = TBSTATE_ENABLED;         
         tbb[2].fsStyle = TBSTYLE_BUTTON;
         tbb[2].idCommand = CM_VEN_VENDERLIVROS;

         tbb[3].fsStyle = TBSTYLE_SEP;

         tbb[4].iBitmap = 3;
         tbb[4].fsState = TBSTATE_ENABLED;
         tbb[4].fsStyle = TBSTYLE_BUTTON;
         tbb[4].idCommand = CM_OP_SOBRE;

         tbb[5].iBitmap = 4;
         tbb[5].fsState = TBSTATE_ENABLED;
         tbb[5].fsStyle = TBSTYLE_BUTTON;
         tbb[5].idCommand = CM_OP_SAIR;

         SendMessage(g_hBarraFerram, TB_ADDBUTTONS, 6, (LPARAM)&tbb);
         
         Rotinas_CentralizaTela(hwnd);
         if (!Rotinas_ConectaBanco(
           "FILE NAME=C:\\LivrusVirtus\\Bancos\\access\\Access2k_Livrus.udl")) {
           MessageBox(0, Rotinas_lerStr(STR_NCONBANCO), 
                      "Erro", MB_ICONERROR | MB_OK);
           return -1;
         }
         
         return 0;
      }
      case WM_COMMAND:
      {
         switch(LOWORD(wParam))
         {
            case CM_CAD_ASSUNTOS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADASSUNTO), 
                          g_sFRMCadAssuntos, g_hMDICliente, 340, 165);
            break;
            case CM_CAD_AUTORES:
              Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADAUTOR), 
                            g_sFRMCadAutores, g_hMDICliente, 340, 165);                          
            break;
            case CM_CAD_EDITORAS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADEDITORA), 
                          g_sFRMCadEditoras, g_hMDICliente, 340, 165);                          
            break;
            case CM_CAD_ENDERECOS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADENDERECO), 
                          g_sFRMCadEnderecos, g_hMDICliente, 530, 195);                          
            break;
            case CM_CAD_IDIOMAS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADIDIOMA), 
                          g_sFRMCadIdiomas, g_hMDICliente, 340, 165);                          
            break;
            case CM_CAD_PAISES:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADPAIS), 
                          g_sFRMCadPaises, g_hMDICliente, 340, 165);                          
            break;
            case CM_CAD_PROFISSOES:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADPROFISS), 
                          g_sFRMCadProfissoes, g_hMDICliente, 340, 165);                          
            break;
            case CM_CAD_CLIENTES:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADCLIENTE), 
                          g_sFRMCadClientes, g_hMDICliente, 530, 468);                          
            break;
            case CM_CAD_LIVROS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CADLIVRO), 
                          g_sFRMCadLivros, g_hMDICliente, 520, 411);
            break;
            case CM_CON_ASSUNTOS:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConAssuntos, 
                            (DLGPROC) frmConAssuntosProc);
            break;            
            case CM_CON_AUTORES:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConAutores, 
                            (DLGPROC) frmConAutoresProc);
            break;            
            case CM_CON_EDITORAS:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConEditoras, 
                            (DLGPROC) frmConEditorasProc);
            break;            
            case CM_CON_ENDERECOS:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConEnderecos, 
                            (DLGPROC) frmConEnderecosProc);
            break;            
            case CM_CON_IDIOMAS:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConIdiomas, 
                            (DLGPROC) frmConIdiomasProc);
            break;            
            case CM_CON_PAISES:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConPaises, 
                            (DLGPROC) frmConPaisesProc);
            break;            
            case CM_CON_PROFISSOES:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConProfissoes, 
                            (DLGPROC) frmConProfissoesProc);
            break;            
            case CM_CON_CLIENTES:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConClientes, 
                            (DLGPROC) frmConClientesProc);
            break;
            case CM_CON_LIVROS:
              Rotinas_ChamarDlgNaoModal(hwnd, g_sFRMConLivros, 
                            (DLGPROC) frmConLivrosProc);
            break;
               PostMessage(g_hMDICliente, WM_MDIICONARRANGE, 0, 0);
            break;
            case CM_VEN_VENDERLIVROS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_VENLIVRO), 
                          g_sFRMVenderLivros, g_hMDICliente, 490, 340);
            break;            
            case CM_VEN_VENDASREALIZADAS:
             Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_CONVENLIVRO), 
                          g_sFRMConVendas, g_hMDICliente, 470, 330);
            break;            
            case CM_OP_ALTERARSENHA:        
              Rotinas_ChamarForm(hwnd, Rotinas_lerStr(STR_ALTSENHA), 
                            g_sFRMAlterarSenha, g_hMDICliente, 255, 160);
            break;
            case CM_OP_SOBRE:
               DialogBox( g_hInstancia, g_sFRMSobre, hwnd, 
                                             (DLGPROC)frmSobreProc );
            break;
            case CM_OP_SAIR:
                 PostMessage(hwnd, WM_CLOSE, 0, 0);
            break;
            default:
            {
               if(LOWORD(wParam) >= ID_MDI_PRIMEIROFORM){
                  DefFrameProc(hwnd, g_hMDICliente, Message, wParam, lParam);
               }
               else {
                 HWND hFilha;
                 hFilha = (HWND)SendMessage(g_hMDICliente, WM_MDIGETACTIVE,0,0);
                 if(hFilha){
                    SendMessage(hFilha, WM_COMMAND, wParam, lParam);
                 }
               }
            }
         }
      }
      break;
      case WM_SIZE:
      {
         RECT rectClient, rectStatus, rectTool;
         UINT uToolHeight, uStatusHeight, uClientAlreaHeight;

         SendMessage(g_hBarraFerram, TB_AUTOSIZE, 0, 0);
         SendMessage(g_hBarraStatus, WM_SIZE, 0, 0);

         GetClientRect(hwnd, &rectClient);
         GetWindowRect(g_hBarraStatus, &rectStatus);
         GetWindowRect(g_hBarraFerram, &rectTool);

         uToolHeight = rectTool.bottom - rectTool.top;
         uStatusHeight = rectStatus.bottom - rectStatus.top;
         uClientAlreaHeight = rectClient.bottom;

         MoveWindow(g_hMDICliente, 0, uToolHeight, rectClient.right, 
                  uClientAlreaHeight - uStatusHeight - uToolHeight, TRUE);
      }
      break;
      case WM_CLOSE:
      {  
         if (MessageBox(hwnd, Rotinas_lerStr(STR_SAIRSIS), 
             Rotinas_lerStr(STR_TITULO), MB_ICONQUESTION | MB_YESNO) == IDYES) {
             Rotinas_DisconectaBanco();
             DestroyWindow(hwnd);
         }
      }       
      break;
      case WM_DESTROY:
         PostQuitMessage(0);
      break;
      default:
         return DefFrameProc(hwnd, g_hMDICliente, Message, wParam, lParam);
   }
   return 0;
}
