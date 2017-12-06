#include "stdafx.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include "resource.h"
#include "Livrus.h"
#include "Principal.h"
#include "Cadastros.h"
#include "CadClientes.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

LISTAMSTR lstRegClientes;
UINT nRegClientes;
BOOL bAtivaClientes;

LRESULT CALLBACK frmCadClientesProc(HWND hwnd, UINT Message, WPARAM wParam,
   LPARAM lParam)
{
   switch(Message)
   {         
      case WM_CREATE:
      {
        if (!frmCadastros_Criar(hwnd, g_sFRMCadClientes, 
                (DLGPROC)frmCadClientesProc))
          return FALSE;          

        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTCPF, 14);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTNOME, 30);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTEMAIL, 30);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTIDENTIDADE, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE, 17);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS, 3);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 10);
        frmCadastros_TamMaxEdit(hwnd, ID_FRMCADCLIENTES_EDTDTNASC, 10);

        SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                CM_CAD_CLIENTES, MAKELONG(FALSE, 0));
        
        nRegClientes = 0;
      }
      break;
      case WM_MDIACTIVATE:
      {
        bAtivaClientes = frmCadastros_Ativar(hwnd, wParam, lParam, 
          ID_FRMCADCLIENTES_EDTCPF, 0, CM_CAD_CLIENTES);
        return FALSE;
      }
      break;      
      case WM_DESTROY:
      {
        SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                CM_CAD_CLIENTES, MAKELONG(TRUE, 0));

         frmCadastros_Fechar(hwnd, 0, CM_CAD_CLIENTES);
      }  
      break;
      case WM_COMMAND:     
         switch(LOWORD(wParam))
         {  
            case ID_FRMCADCLIENTES_EDTCPF:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadClientes_edtCPFKillFocus(hwnd);
            }
            break;
            case ID_FRMCADCLIENTES_EDTDTNASC:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadClientes_edtDtNascKillFocus(hwnd);
            }
            break;
            case ID_FRMCADCLIENTES_EDTCODENDERECO:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadClientes_edtCodEnderecoKillFocus(hwnd);
            }
            break;
            case ID_FRMCADCLIENTES_EDTCODPAIS:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadClientes_edtCodPaisKillFocus(hwnd);
            }
            break;
            case ID_FRMCADCLIENTES_EDTCODPROFISSAO:
            {            
               if (HIWORD(wParam) == EN_KILLFOCUS)
                 frmCadClientes_edtCodProfissaoKillFocus(hwnd);
            }
            break;
            case ID_FRMCADCLIENTES_BTNPENDERECO:
              frmCadClientes_btnPEnderecoClick(hwnd);
            break;
            case ID_FRMCADCLIENTES_BTNPPAIS:
              frmCadClientes_btnPPaisClick(hwnd);
            break;
            case ID_FRMCADCLIENTES_BTNPPROFISSAO:
              frmCadClientes_btnPProfissaoClick(hwnd);
            break;
            case ID_FRMCADCLIENTES_BTNNOVO:
            {
              frmCadastros_btnNovoClick(hwnd, ID_FRMCADCLIENTES_EDTCPF, 
              ID_FRMCADCLIENTES_EDTNOME, ID_FRMCADCLIENTES_BTNNOVO,
              ID_FRMCADCLIENTES_BTNPESQUISAR, ID_FRMCADCLIENTES_BTNANTERIOR,
              ID_FRMCADCLIENTES_BTNPROXIMO, ID_FRMCADCLIENTES_BTNSALVAR,
              ID_FRMCADCLIENTES_BTNEXCLUIR);

              frmCadClientes_InformaLimpaDados(hwnd, NULL, 0, FALSE);
              frmCadClientes_HabilitaDados(hwnd, TRUE);	
            }
            break;
            case ID_FRMCADCLIENTES_BTNPESQUISAR:
            {
              if (frmCadastros_PesquisarDados(hwnd, &lstRegClientes, 
              ID_FRMCADCLIENTES_EDTCPF, ID_FRMCADCLIENTES_EDTNOME,
              ID_FRMCADCLIENTES_BTNPESQUISAR, ID_FRMCADCLIENTES_BTNANTERIOR,
              ID_FRMCADCLIENTES_BTNPROXIMO, ID_FRMCADCLIENTES_BTNSALVAR,
              ID_FRMCADCLIENTES_BTNEXCLUIR, ConsSQL_Cliente('S',
              Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF),
              "","","","","","","","",""), Rotinas_lerStr(STR_CLINENC))) {
                frmCadClientes_InformaLimpaDados(hwnd,lstRegClientes,0, TRUE);
                frmCadClientes_HabilitaDados(hwnd, TRUE);	
              }
            }
            break;
            case ID_FRMCADCLIENTES_BTNANTERIOR:
            {
              if (frmCadastros_registroAnterior(hwnd, lstRegClientes, 
              ID_FRMCADCLIENTES_EDTCPF, ID_FRMCADCLIENTES_EDTNOME,
              &nRegClientes)) {
                frmCadClientes_InformaLimpaDados(hwnd,lstRegClientes,
                  nRegClientes, TRUE);              
              }  
            }
            break;
            case ID_FRMCADCLIENTES_BTNPROXIMO:
            {
              if (frmCadastros_registroProximo(hwnd, lstRegClientes, 
              ID_FRMCADCLIENTES_EDTCPF, ID_FRMCADCLIENTES_EDTNOME,
              &nRegClientes)) {
                frmCadClientes_InformaLimpaDados(hwnd,lstRegClientes,
                  nRegClientes, TRUE);              
              }  
            }
            break;
            case ID_FRMCADCLIENTES_BTNSALVAR:
            {
              LPTSTR sSexo, sDTHR, sDtNasc, sSqlInsert, sSqlUpdate;
              sSexo = Rotinas_alocaString(TAM_MAX_STR);
              sSqlInsert = Rotinas_alocaString(TAM_MAX_STR * 2);
              sSqlUpdate = Rotinas_alocaString(TAM_MAX_STR * 2);

              if (IsDlgButtonChecked(hwnd, 
                 ID_FRMCADCLIENTES_RBMASCULINO) == BST_CHECKED)              
                 lstrcpy(sSexo, "M"); 
              else   
                 lstrcpy(sSexo, "F");
                 
              sDTHR = Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTDTNASC);
              sDtNasc = Rotinas_ConverteDataHoraStr(sDTHR, TRUE, "MM/dd/yyyy", "");

              sSqlInsert = ConsSQL_Cliente('I',
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTNOME),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTEMAIL),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTIDENTIDADE),
                sSexo,
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE),
                sDtNasc, 
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS), 
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO));

              sSqlUpdate = ConsSQL_Cliente('U',
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTNOME),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTEMAIL),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTIDENTIDADE),
                sSexo,
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE),
                sDtNasc, 
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO),
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS), 
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO));

              if (frmCadastros_SalvarDados(hwnd, ID_FRMCADCLIENTES_EDTCPF, 
              ID_FRMCADCLIENTES_EDTNOME, ID_FRMCADCLIENTES_BTNNOVO,
              ID_FRMCADCLIENTES_BTNPESQUISAR, ID_FRMCADCLIENTES_BTNANTERIOR,
              ID_FRMCADCLIENTES_BTNPROXIMO, ID_FRMCADCLIENTES_BTNSALVAR,
              ID_FRMCADCLIENTES_BTNEXCLUIR, 
              frmCadClientes_ValidaDados(hwnd, TRUE),
              ConsSQL_Cliente('S',
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF),
                "","","","","","","","",""), sSqlUpdate, sSqlInsert, TRUE)) {
                  frmCadClientes_InformaLimpaDados(hwnd, NULL, 0, FALSE);
                  frmCadClientes_HabilitaDados(hwnd, FALSE);	
              }
            }
            break;
            case ID_FRMCADCLIENTES_BTNEXCLUIR:
            {
              if (frmCadastros_ExcluirDados(hwnd, ID_FRMCADCLIENTES_EDTCPF, 
              ID_FRMCADCLIENTES_EDTNOME, ID_FRMCADCLIENTES_BTNNOVO,
              ID_FRMCADCLIENTES_BTNPESQUISAR, ID_FRMCADCLIENTES_BTNANTERIOR,
              ID_FRMCADCLIENTES_BTNPROXIMO, ID_FRMCADCLIENTES_BTNSALVAR,
              ID_FRMCADCLIENTES_BTNEXCLUIR, 
              frmCadClientes_ValidaDados(hwnd, FALSE),
              ConsSQL_Cliente('D',
                Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF),
                "","","","","","","","",""))) {
                frmCadClientes_InformaLimpaDados(hwnd, NULL, 0, FALSE);
                frmCadClientes_HabilitaDados(hwnd, FALSE);	
              }  
            }
            break;
            case ID_FRMCADCLIENTES_BTNLIMPAR:
            {
              frmCadastros_btnLimparClick(hwnd, ID_FRMCADCLIENTES_EDTCPF, 
              ID_FRMCADCLIENTES_EDTNOME, ID_FRMCADCLIENTES_BTNNOVO,
              ID_FRMCADCLIENTES_BTNPESQUISAR, ID_FRMCADCLIENTES_BTNANTERIOR,
              ID_FRMCADCLIENTES_BTNPROXIMO, ID_FRMCADCLIENTES_BTNSALVAR,
              ID_FRMCADCLIENTES_BTNEXCLUIR);

              frmCadClientes_InformaLimpaDados(hwnd, NULL, 0, FALSE);
              frmCadClientes_HabilitaDados(hwnd, FALSE);	
            }
            break;
            case ID_FRMCADCLIENTES_BTNFECHAR: 
              if (bAtivaClientes)   
                DestroyWindow(g_hTelaAtiva);                
            break;               
         }
      return 0;
   }
   return DefMDIChildProc(hwnd, Message, wParam, lParam);
}

BOOL frmCadClientes_ValidaDados(HWND hwnd, BOOL bTodosDados)
{
if (Rotinas_ValidaCampo(Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF), 
    Rotinas_lerStr(STR_CPFNINF)))
  	  return FALSE;
  	if (bTodosDados) {      
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTNOME), 
           Rotinas_lerStr(STR_CLININF)))
  		return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTEMAIL), 
           Rotinas_lerStr(STR_EMAILNINF)))
  		return FALSE;
      if (IsDlgButtonChecked(hwnd, ID_FRMCADCLIENTES_RBMASCULINO) == BST_UNCHECKED
      && IsDlgButtonChecked(hwnd, ID_FRMCADCLIENTES_RBFEMININO) == BST_UNCHECKED){             
         MessageBox(hwnd, Rotinas_lerStr(STR_SEXNINF), 
           "Erro", MB_ICONERROR | MB_OK);
        return FALSE;
      }
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE), 
           Rotinas_lerStr(STR_TELNINF)))
  		return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO), 
           Rotinas_lerStr(STR_ENDNINF)))
  		return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS), 
           Rotinas_lerStr(STR_PAISNINF)))
  		return FALSE;
  	  if (Rotinas_ValidaCampo(
           Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO), 
           Rotinas_lerStr(STR_PROFNINF)))
  		return FALSE;
  	}
  	return TRUE;
}

VOID frmCadClientes_InformaLimpaDados(HWND hwnd, LISTAMSTR lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar)
{ 
  if (bInformar) {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTEMAIL), 
      ListaStr_pesquisaItemOrdM(lstRegistros, 2, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTIDENTIDADE),
      ListaStr_pesquisaItemOrdM(lstRegistros, 3, nLinhaRegistro));
    if (lstrcmp(ListaStr_pesquisaItemOrdM(lstRegistros, 4, 
                                          nLinhaRegistro), "M")==0) {
      CheckDlgButton(hwnd, ID_FRMCADCLIENTES_RBMASCULINO, BST_CHECKED);
      CheckDlgButton(hwnd, ID_FRMCADCLIENTES_RBFEMININO, BST_UNCHECKED);
    } else {
      CheckDlgButton(hwnd, ID_FRMCADCLIENTES_RBMASCULINO, BST_UNCHECKED);
      CheckDlgButton(hwnd, ID_FRMCADCLIENTES_RBFEMININO, BST_CHECKED);
    }      
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE),
      ListaStr_pesquisaItemOrdM(lstRegistros, 5, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTDTNASC),
      Rotinas_subString(
      ListaStr_pesquisaItemOrdM(lstRegistros, 6, nLinhaRegistro),1,10));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO),
      ListaStr_pesquisaItemOrdM(lstRegistros, 7, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTLOGRADOURO),
      ListaStr_pesquisaItemOrdM(lstRegistros, 8, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTBAIRRO),
      ListaStr_pesquisaItemOrdM(lstRegistros, 9, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCEP),
      ListaStr_pesquisaItemOrdM(lstRegistros, 10, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCIDADE),
      ListaStr_pesquisaItemOrdM(lstRegistros, 11, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTESTADO),
      ListaStr_pesquisaItemOrdM(lstRegistros, 12, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS),
      ListaStr_pesquisaItemOrdM(lstRegistros, 13, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPAIS),
      ListaStr_pesquisaItemOrdM(lstRegistros, 14, nLinhaRegistro));
   SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO),
      ListaStr_pesquisaItemOrdM(lstRegistros, 15, nLinhaRegistro));
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPROFISSAO),
      ListaStr_pesquisaItemOrdM(lstRegistros, 16, nLinhaRegistro));
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTEMAIL),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTIDENTIDADE),"");
    CheckDlgButton(hwnd, ID_FRMCADCLIENTES_RBMASCULINO, BST_CHECKED);
    CheckDlgButton(hwnd, ID_FRMCADCLIENTES_RBFEMININO, BST_UNCHECKED);
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTDTNASC),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTLOGRADOURO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTBAIRRO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCEP),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCIDADE),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTESTADO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPAIS),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPROFISSAO),"");
    nRegClientes = 0;
  }
} 

VOID frmCadClientes_HabilitaDados(HWND hwnd, BOOL bHabilita)
{
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTEMAIL),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTIDENTIDADE),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_RBMASCULINO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_RBFEMININO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTTELEFONE),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTDTNASC),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_BTNPENDERECO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTLOGRADOURO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTBAIRRO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCEP),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCIDADE),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTESTADO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_BTNPPAIS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPAIS),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_BTNPPROFISSAO),bHabilita);
  EnableWindow(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPROFISSAO),bHabilita);
}

VOID frmCadClientes_edtCPFKillFocus(HWND hwnd)
{ LPTSTR sCPF;
  sCPF = Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCPF);

  if (lstrcmp(sCPF,"")!=0) {
  	if (Rotinas_validaCPF(sCPF)==FALSE) {      
      MessageBox(hwnd, Rotinas_lerStr(STR_CPFINV),"Erro",MB_ICONERROR | MB_OK);
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCPF),"");
  		SetFocus(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCPF));
  	}
  }
}

VOID frmCadClientes_edtCodEnderecoKillFocus(HWND hwnd)
{ LPTSTR sCodEnd, sLogradouro;
  LISTAMSTR ConsCampo;

  sCodEnd = Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO);

  if (lstrcmp(sCodEnd,"")!=0) {
    sLogradouro = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Endereco('S',
    sCodEnd,"","","","",""),Rotinas_lerStr(STR_ENDNENC));    
    if (lstrcmp(sLogradouro,"")!=0) {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTLOGRADOURO),sLogradouro);
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTBAIRRO),
        ListaStr_pesquisaItemOrdM(ConsCampo,2,0));
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCEP),
        ListaStr_pesquisaItemOrdM(ConsCampo,3,0));
  	  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCIDADE),
        ListaStr_pesquisaItemOrdM(ConsCampo,4,0));
  	  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTESTADO),
        ListaStr_pesquisaItemOrdM(ConsCampo,5,0));
      ListaStr_liberaM(ConsCampo);
    } else {
  	  SetFocus(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO));
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTLOGRADOURO),"");
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTBAIRRO),"");
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCEP),"");
  	  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCIDADE),"");
  	  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTESTADO),"");
      ListaStr_liberaM(ConsCampo);
    }
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTLOGRADOURO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTBAIRRO),"");
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCEP),"");
  	SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCIDADE),"");
  	SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTESTADO),"");
  }
}

VOID frmCadClientes_edtCodPaisKillFocus(HWND hwnd)
{ LPTSTR sCodPais, sPais;
  LISTAMSTR ConsCampo;
  sCodPais = Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS);

  if (lstrcmp(sCodPais,"")!=0) {
    sPais = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Pais('S',
    sCodPais,""),Rotinas_lerStr(STR_PAISNENC));    
    ListaStr_liberaM(ConsCampo);
    if (lstrcmp(sPais,"")!=0) {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPAIS),sPais);
    } else {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS),"");
      SetFocus(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS));
    }
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPAIS),"");
  }
}

VOID frmCadClientes_edtCodProfissaoKillFocus(HWND hwnd)
{ LPTSTR sCodProfissao, sProfissao;
  LISTAMSTR ConsCampo;
  sCodProfissao = Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO);

  if (lstrcmp(sCodProfissao,"")!=0) {
    sProfissao = Rotinas_ConsultaCampoDesc(&ConsCampo, ConsSQL_Profissao('S',
    sCodProfissao,""),Rotinas_lerStr(STR_PROFNENC));    
    ListaStr_liberaM(ConsCampo);
    if (lstrcmp(sProfissao,"")!=0) {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPROFISSAO),sProfissao);
    } else {
      SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO),"");
      SetFocus(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO));
    }
  } else {
    SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTPROFISSAO),"");
  }
}

VOID frmCadClientes_edtDtNascKillFocus(HWND hwnd)
{ LPTSTR sDtNasc;

 sDtNasc = Rotinas_retTexto(hwnd, ID_FRMCADCLIENTES_EDTDTNASC);
 if (strlen(sDtNasc) > 0) {
   if (Rotinas_validaDataHora(sDtNasc, TRUE)==FALSE) {
     MessageBox(hwnd, Rotinas_lerStr(STR_DATINV), "Erro", MB_ICONERROR | MB_OK);
     SetFocus(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTDTNASC));
   }
 }
}

VOID frmCadClientes_btnPEnderecoClick(HWND hwnd)
{
  DialogBox( g_hInstancia, g_sFRMConEnderecos, hwnd, 
                       (DLGPROC)frmConEnderecosProc );
  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODENDERECO),
    Rotinas_sCodigoSelecionado);
  frmCadClientes_edtCodEnderecoKillFocus(hwnd);
}

VOID frmCadClientes_btnPPaisClick(HWND hwnd)
{
  DialogBox( g_hInstancia, g_sFRMConPaises, hwnd, (DLGPROC)frmConPaisesProc );
  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPAIS),
    Rotinas_sCodigoSelecionado);
  frmCadClientes_edtCodPaisKillFocus(hwnd);
}

VOID frmCadClientes_btnPProfissaoClick(HWND hwnd)
{
  DialogBox( g_hInstancia, g_sFRMConProfissoes, hwnd, 
                       (DLGPROC)frmConProfissoesProc );
  SetWindowText(GetDlgItem(hwnd, ID_FRMCADCLIENTES_EDTCODPROFISSAO),
    Rotinas_sCodigoSelecionado);
  frmCadClientes_edtCodProfissaoKillFocus(hwnd);
}
