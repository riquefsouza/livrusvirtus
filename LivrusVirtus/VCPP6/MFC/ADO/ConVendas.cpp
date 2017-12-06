// ConVendas.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "ConVendas.h"
#include "Cadastros.h"
#include "Consultas.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmConVendas dialog


CFrmConVendas::CFrmConVendas(CWnd* pParent /*=NULL*/)
	: CFrmConsultas(CFrmConVendas::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFrmConVendas)
	//}}AFX_DATA_INIT
}


void CFrmConVendas::DoDataExchange(CDataExchange* pDX)
{
  CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmConVendas)
	DDX_Control(pDX, ID_FRMCONVENDAS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCONVENDAS_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCONVENDAS_LABPRECOTOTAL, m_LabPrecoTotal);
	DDX_Control(pDX, ID_FRMCONVENDAS_LABREGISTROS, m_LabRegistros);
	DDX_Control(pDX, ID_FRMCONVENDAS_LISTCONSULTA, m_ListVendas);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTPRECOTOTAL, m_EdtPrecoTotal);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTLIVRO, m_EdtLivro);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTCLIENTE, m_EdtCliente);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTISBN, m_EdtISBN);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTHRVENDA, m_EdtHrVenda);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTDTVENDA, m_EdtDtVenda);
	DDX_Control(pDX, ID_FRMCONVENDAS_EDTCPF, m_EdtCPF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmConVendas, CDialog)
	//{{AFX_MSG_MAP(CFrmConVendas)
	ON_WM_CLOSE()
	ON_BN_CLICKED(ID_FRMCONVENDAS_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCONVENDAS_BTNLIMPAR, OnBtnLimpar)
	ON_BN_CLICKED(ID_FRMCONVENDAS_BTNPESQUISAR, OnBtnPesquisar)
	ON_EN_KILLFOCUS(ID_FRMCONVENDAS_EDTCPF, OnEdtCPF_Killfocus)
	ON_BN_CLICKED(ID_FRMCONVENDAS_BTNPCLIENTE, OnBtnPCliente)
	ON_EN_KILLFOCUS(ID_FRMCONVENDAS_EDTISBN, OnEdtISBN_Killfocus)
	ON_BN_CLICKED(ID_FRMCONVENDAS_BTNPLIVRO, OnBtnPLivro)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmConVendas message handlers

BOOL CFrmConVendas::OnInitDialog() 
{
	CFrmConsultas::OnInitDialog();

  m_EdtCPF.SetLimitText(14);
  m_EdtISBN.SetLimitText(13);
      
  LISTASTR sColunas;
  POSITION pos;
  UINT nLargura[] = { 120, 100, 220, 100, 280, 80 };

  pos = sColunas.col.GetHeadPosition();
  sColunas.col.InsertAfter(pos, "Data/Hora Venda");
  sColunas.col.InsertAfter(pos, "CPF");
  sColunas.col.InsertAfter(pos, "Cliente");
  sColunas.col.InsertAfter(pos, "ISBN");
  sColunas.col.InsertAfter(pos, "Livro");
  sColunas.col.InsertAfter(pos, "Preço");
    
  Rotinas->VisaoListaInsereColunas(&m_ListVendas, nLargura, &sColunas);

  DateTime_SetSystemtime(m_EdtDtVenda.m_hWnd, GDT_NONE, NULL);
  DateTime_SetSystemtime(m_EdtHrVenda.m_hWnd, GDT_NONE, NULL);
  m_EdtPrecoTotal.SetWindowText("R$ 0,00");
	
	return TRUE;
}

void CFrmConVendas::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);  
}

void CFrmConVendas::OnClose() 
{
  Rotinas->habilitaSubMenu(2, CM_VEN_VENDASREALIZADAS, TRUE);       
  GetParent()->DestroyWindow();
}


BOOL CFrmConVendas::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
  if (CFrmConsultas::Notifica(lParam, &m_ListVendas,
      &m_LabRegistros, &lstLinhas, &sSelecionados))
    return 0;
 
	return CDialog::OnNotify(wParam, lParam, pResult);
}

VOID CFrmConVendas::arrumaTamanho(RECT rForm) 
{
RECT rRegs, rLimpar, rFechar, rLabPreco, rEdtPreco;
INT hFrm, wFrm;
        
  hFrm = (rForm.bottom - rForm.top);
  wFrm = (rForm.right - rForm.left);

  m_LabPrecoTotal.GetWindowRect(&rLabPreco);
  m_EdtPrecoTotal.GetWindowRect(&rEdtPreco);
  m_LabRegistros.GetWindowRect(&rRegs);
  m_BtnLimpar.GetClientRect(&rLimpar);
  m_BtnFechar.GetClientRect(&rFechar);        
  
  MoveWindow(0, 0, wFrm, hFrm, TRUE);
  m_ListVendas.MoveWindow(0, 125, wFrm, hFrm - 190, TRUE);
  m_LabPrecoTotal.MoveWindow((wFrm - 200), (hFrm - 60),
  (rLabPreco.right - rLabPreco.left), (rLabPreco.bottom - rLabPreco.top), TRUE);
  m_EdtPrecoTotal.MoveWindow((wFrm - 140), (hFrm - 60), 
  (rEdtPreco.right - rEdtPreco.left), (rEdtPreco.bottom - rEdtPreco.top), TRUE);
  m_LabRegistros.MoveWindow(8, (hFrm - 30), 
    (rRegs.right - rRegs.left), (rRegs.bottom - rRegs.top), TRUE);
  m_BtnLimpar.MoveWindow((wFrm - 155), (hFrm - 30), 
    (rLimpar.right - rLimpar.left), (rLimpar.bottom - rLimpar.top), TRUE);
  m_BtnFechar.MoveWindow((wFrm - 80), (hFrm - 30), 
    (rFechar.right - rFechar.left), (rFechar.bottom - rFechar.top), TRUE);
}

void CFrmConVendas::OnBtnLimpar() 
{
  SYSTEMTIME sTempo;

  m_EdtCPF.SetWindowText("");
  m_EdtCliente.SetWindowText("");
  m_EdtISBN.SetWindowText("");
  m_EdtLivro.SetWindowText("");
  m_EdtPrecoTotal.SetWindowText("R$ 0,00");

  CFrmConsultas::LimparDados(&m_LabRegistros, &m_EdtCPF, 
    &m_ListVendas, &lstLinhas);

  GetSystemTime(&sTempo);
  DateTime_SetSystemtime(m_EdtDtVenda.m_hWnd, GDT_VALID, &sTempo);
  DateTime_SetSystemtime(m_EdtDtVenda.m_hWnd, GDT_NONE, NULL);
  DateTime_SetSystemtime(m_EdtHrVenda.m_hWnd, GDT_VALID, &sTempo);
  DateTime_SetSystemtime(m_EdtHrVenda.m_hWnd, GDT_NONE, NULL);
  m_EdtDtVenda.SetFocus();
}

CString CFrmConVendas::ConsVenda(TCHAR sOpcao)
{
  CString sISBN, sCPF, sDataHora;
  SYSTEMTIME sTempo;
  
  if (DateTime_GetSystemtime(m_EdtDtVenda.m_hWnd, &sTempo)!=GDT_NONE
    && DateTime_GetSystemtime(m_EdtHrVenda.m_hWnd, &sTempo)!=GDT_NONE)
    sDataHora = Rotinas->retDataHora(&m_EdtDtVenda, "MM/dd/yyyy", "") + 
    " " + Rotinas->retDataHora(&m_EdtHrVenda, "", "HH:mm:ss");
  else
    sDataHora = "";

  sISBN = Rotinas->retTexto(&m_EdtISBN);
  sCPF = Rotinas->retTexto(&m_EdtCPF);

  if (sOpcao=='L')
    return ConsSQL->Venda('S',"ZERO","","","","");
  else
    return ConsSQL->Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");    

}

void CFrmConVendas::OnBtnPesquisar() 
{
  LISTAMSTR ConsTotal;  
  CString sPrecoTotal;
  POSITION pos;
  FLOAT nTemp;

  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinhas, ConsVenda('S'))) {
     Rotinas->VisaoListaInsereLinhas(&m_ListVendas, &lstLinhas);
     CFrmConsultas::setLabRegistros(&m_LabRegistros, &lstLinhas, 1);

     if (Rotinas->ConsultaDadosLista(gConexao, &ConsTotal, ConsVenda('P'))) {
  	   if (ConsTotal.col[0].GetCount() > 0) {
         pos = ConsTotal.col[0].FindIndex(0);
         nTemp = (FLOAT) atof(ConsTotal.col[0].GetAt(pos).operator LPCTSTR());
         sPrecoTotal.Format("R$ %7.2f", nTemp);          
  		   m_EdtPrecoTotal.SetWindowText(Rotinas->VirgulaParaPonto(sPrecoTotal,TRUE));
  	   }
     }

  } else {
     AfxMessageBox(Rotinas->lerStr(STR_VENNENC), MB_ICONERROR | MB_OK, 0);
  }
}

void CFrmConVendas::OnEdtCPF_Killfocus() 
{ CString sCPF, sCliente;
  LISTAMSTR ConsCampo;

  sCPF = Rotinas->retTexto(&m_EdtCPF);
  if (sCPF.GetLength() > 0) {
  	if (Rotinas->validaCPF(sCPF)) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      sCPF,"","","","","","","","",""),Rotinas->lerStr(STR_CLINENC));    
      if (sCliente.GetLength() == 0) {
        m_EdtCPF.SetWindowText("");
    		m_EdtCPF.SetFocus();
      } else
         m_EdtCliente.SetWindowText(sCliente);
    } else {
      AfxMessageBox(Rotinas->lerStr(STR_CPFINV), MB_ICONERROR | MB_OK, 0);
      m_EdtCPF.SetWindowText("");
  		m_EdtCPF.SetFocus();
  	}
  } else
     m_EdtCliente.SetWindowText("");
}

void CFrmConVendas::OnBtnPCliente() 
{
  CFrmConClientes *fConClientes = new CFrmConClientes(this);
  fConClientes->DoModal();
  m_EdtCPF.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCPF_Killfocus();		
}

void CFrmConVendas::OnEdtISBN_Killfocus() 
{ CString sISBN, sLivro;
  INT nQtdEstoque;
  LISTAMSTR ConsCampo;
  POSITION pos;

  sISBN = Rotinas->retTexto(&m_EdtISBN);
  if (sISBN.GetLength() > 0) {
  	if (Rotinas->validaISBN(sISBN)) {      
      sLivro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Livro('Q',
      sISBN,"","","","","","","","",""),Rotinas->lerStr(STR_LIVNENC));    
      if (sLivro.GetLength()==0) {
        m_EdtISBN.SetWindowText("");
    		m_EdtISBN.SetFocus();
      } else {
         m_EdtLivro.SetWindowText(sLivro);                  
         pos = ConsCampo.col[3].FindIndex(0);
         nQtdEstoque = atoi(ConsCampo.col[3].GetAt(pos).operator LPCTSTR());
         if (nQtdEstoque > 0) {
           pos = ConsCampo.col[2].FindIndex(0);
  			   Rotinas_sPreco = ConsCampo.col[2].GetAt(pos);
         } else
           AfxMessageBox(Rotinas->lerStr(STR_LIVNEST), 
             MB_ICONERROR | MB_OK, 0);
      }

    } else {
      AfxMessageBox(Rotinas->lerStr(STR_ISBNINV), MB_ICONERROR | MB_OK, 0);
      m_EdtISBN.SetWindowText("");
  		m_EdtISBN.SetFocus();
  	}
  } else
     m_EdtLivro.SetWindowText("");
}

void CFrmConVendas::OnBtnPLivro() 
{
  CFrmConLivros *fConLivros = new CFrmConLivros(this);
  fConLivros->DoModal();
  m_EdtISBN.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtISBN_Killfocus();	
}

