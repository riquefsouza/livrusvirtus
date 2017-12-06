// VenderLivros.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "Cadastros.h"
#include "VenderLivros.h"
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
// CFrmVenderLivros dialog


CFrmVenderLivros::CFrmVenderLivros(CWnd* pParent /*=NULL*/)
  : CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmVenderLivros)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
  nPrecoTotal = 0;
}


void CFrmVenderLivros::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmVenderLivros)
	DDX_Control(pDX, ID_FRMVENDERLIVROS_LSTLIVROS, m_LstLivros);
	DDX_Control(pDX, ID_FRMVENDERLIVROS_EDTPRECOTOTAL, m_EdtPrecoTotal);
	DDX_Control(pDX, ID_FRMVENDERLIVROS_EDTLIVRO, m_EdtLivro);
	DDX_Control(pDX, ID_FRMVENDERLIVROS_EDTISBN, m_EdtISBN);
	DDX_Control(pDX, ID_FRMVENDERLIVROS_EDTDTHRVENDA, m_EdtDtHrVenda);
	DDX_Control(pDX, ID_FRMVENDERLIVROS_EDTCPF, m_EdtCPF);
	DDX_Control(pDX, ID_FRMVENDERLIVROS_EDTCLIENTE, m_EdtCliente);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmVenderLivros, CDialog)
	//{{AFX_MSG_MAP(CFrmVenderLivros)
	ON_BN_CLICKED(ID_FRMVENDERLIVROS_BTNFECHAR, OnBtnFechar)
	ON_WM_CLOSE()
	ON_EN_KILLFOCUS(ID_FRMVENDERLIVROS_EDTCPF, OnEdtCPF_Killfocus)
	ON_BN_CLICKED(ID_FRMVENDERLIVROS_BTNPCLIENTE, OnBtnPCliente)
	ON_EN_KILLFOCUS(ID_FRMVENDERLIVROS_EDTISBN, OnEdtISBN_Killfocus)
	ON_BN_CLICKED(ID_FRMVENDERLIVROS_BTNPLIVRO, OnBtnPLivro)
	ON_BN_CLICKED(ID_FRMVENDERLIVROS_BTNADLIVROS, OnBtnAdLivros)
	ON_LBN_DBLCLK(ID_FRMVENDERLIVROS_LSTLIVROS, OnLstLivros_Dblclk)
	ON_BN_CLICKED(ID_FRMVENDERLIVROS_BTNVENDER, OnBtnVender)
	ON_BN_CLICKED(ID_FRMVENDERLIVROS_BTNLIMPAR, OnBtnLimpar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmVenderLivros message handlers

void CFrmVenderLivros::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);	
}

void CFrmVenderLivros::OnClose() 
{
//SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
                //CM_VEN_VENDERLIVROS, MAKELONG(TRUE, 0));
  CFrmCadastros::Fechar(2, CM_VEN_VENDERLIVROS);
}

BOOL CFrmVenderLivros::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
//  SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
//          CM_VEN_VENDERLIVROS, MAKELONG(FALSE, 0));
    
  m_EdtDtHrVenda.SetWindowText(Rotinas->retDataHoraStr(TRUE, TRUE));   
  m_EdtCPF.SetLimitText(14);
  m_EdtISBN.SetLimitText(13);  
  nRegistros = 0;        
	return TRUE;
}

void CFrmVenderLivros::LimpaDados() {
  m_EdtDtHrVenda.SetWindowText(Rotinas->retDataHoraStr(TRUE, TRUE));  
  m_EdtCPF.SetWindowText("");
  m_EdtCliente.SetWindowText("");
  m_EdtISBN.SetWindowText("");
  m_EdtLivro.SetWindowText("");
  m_LstLivros.ResetContent();
  m_EdtLivro.SetWindowText("");
  nPrecoTotal = 0;
  m_EdtPrecoTotal.SetWindowText("R$ 0,00");
  m_EdtCPF.SetFocus();
}

BOOL CFrmVenderLivros::ValidaDados()
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCPF), 
    Rotinas->lerStr(STR_CPFNINF)))
  	  return FALSE;
if (m_LstLivros.GetCount()==0) {
   AfxMessageBox(Rotinas->lerStr(STR_LIVVENNINF), MB_ICONERROR | MB_OK, 0);
  return FALSE;
}
return TRUE;
}

BOOL CFrmVenderLivros::SalvaLista()
{ CString sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR;
  INT nCont, nQtdEstoque, nQtd;
  POSITION pos;

nQtd = m_LstLivros.GetCount();
sCPF = Rotinas->retTexto(&m_EdtCPF);
sPrecoTotal.Format("%.2f",nPrecoTotal);

sDTHR = Rotinas->retTexto(&m_EdtDtHrVenda);
sDataHora = Rotinas->ConverteDataHoraStr(sDTHR, TRUE, "MM/dd/yyyy","HH:mm:ss");

for (nCont=0; nCont < nQtd; nCont++) {
  pos = slISBNs.col.FindIndex(nCont);
  sISBN = slISBNs.col.GetAt(pos);

  Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('I',sISBN, sCPF, 
    sDataHora,Rotinas->VirgulaParaPonto(sPrecoTotal,FALSE),""));

  pos = slQtdEstoque.col.FindIndex(nCont);
  nQtdEstoque = atoi(slQtdEstoque.col.GetAt(pos));
  nQtdEstoque--;
  sQtdEstoque.Format("%d", nQtdEstoque);
  Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('U',sISBN, 
    "","","", sQtdEstoque));
}
return TRUE;
}

void CFrmVenderLivros::OnEdtCPF_Killfocus() 
{ CString sCPF, sCliente;
  LISTAMSTR ConsCampo;

  sCPF = Rotinas->retTexto(&m_EdtCPF);
  if (sCPF.GetLength() > 0) {
  	if (Rotinas->validaCPF(sCPF)) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      sCPF,"","","","","","","","",""),Rotinas->lerStr(STR_CLINENC));    
      if (sCliente.GetLength()==0) {
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

void CFrmVenderLivros::OnBtnPCliente() 
{
  CFrmConClientes *fConClientes = new CFrmConClientes(this);
  fConClientes->DoModal();
  m_EdtCPF.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCPF_Killfocus();	
}

void CFrmVenderLivros::OnEdtISBN_Killfocus() 
{ CString sISBN, sLivro;
  INT nQtdEstoque;
  LISTAMSTR ConsCampo;
  POSITION pos;
  LPTSTR sTemp;

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
         pos = ConsCampo.col[3].GetHeadPosition();
         sTemp = (LPTSTR) ConsCampo.col[3].GetAt(pos).operator LPCTSTR();
         nQtdEstoque = atoi(sTemp);
         if (nQtdEstoque > 0) {
           pos = ConsCampo.col[2].GetHeadPosition();
           Rotinas_sPreco = (LPTSTR) 
             ConsCampo.col[2].GetAt(pos).operator LPCTSTR();
           Rotinas_sQtdEstoque = (LPTSTR) 
             ConsCampo.col[3].GetAt(pos).operator LPCTSTR();
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

void CFrmVenderLivros::OnBtnPLivro() 
{
  CFrmConLivros *fConLivros = new CFrmConLivros(this);
  fConLivros->DoModal();
  m_EdtISBN.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtISBN_Killfocus();	
}

void CFrmVenderLivros::OnBtnAdLivros() 
{
 CString sLivros, sISBN, sEdtLivro, sPrecoTotal;
 POSITION pos;

 sISBN = Rotinas->retTexto(&m_EdtISBN);
 sEdtLivro = Rotinas->retTexto(&m_EdtLivro);
 if (sISBN.GetLength() > 0) {
   sLivros.Format("%s - %s - R$ %s", sISBN, sEdtLivro, Rotinas_sPreco);
   if (m_LstLivros.FindString(0, sLivros)==LB_ERR) {
     pos = slISBNs.col.GetHeadPosition();
     slISBNs.col.InsertAfter(pos, sISBN);
     pos = slPrecos.col.GetHeadPosition();
     slPrecos.col.InsertAfter(pos, Rotinas_sPreco);
     pos = slQtdEstoque.col.GetHeadPosition();
     slQtdEstoque.col.InsertAfter(pos, Rotinas_sQtdEstoque);
     m_LstLivros.AddString(sLivros);
   	 nPrecoTotal = nPrecoTotal + (FLOAT)atof(Rotinas_sPreco);
   }
   m_EdtISBN.SetWindowText("");
   m_EdtLivro.SetWindowText("");

   sPrecoTotal.Format("R$ %.2f",nPrecoTotal);
   m_EdtPrecoTotal.SetWindowText(Rotinas->VirgulaParaPonto(sPrecoTotal,TRUE));
 }
}

void CFrmVenderLivros::OnLstLivros_Dblclk() 
{ CString sPrecoTotal;
  FLOAT nPreco;
  INT nSelIndice;
  POSITION pos;

 if (m_LstLivros.GetCount() > 0) {   
   nSelIndice = m_LstLivros.GetCurSel();   
   if (m_LstLivros.GetSel(nSelIndice) > 0) {                 
     pos = slPrecos.col.FindIndex(nSelIndice);
     nPreco=(FLOAT)atof(slPrecos.col.GetAt(pos).operator LPCTSTR());
     nPrecoTotal=nPrecoTotal-nPreco;     
     sPrecoTotal.Format("R$ %.2f",nPrecoTotal);
     m_EdtPrecoTotal.SetWindowText(Rotinas->VirgulaParaPonto(sPrecoTotal,TRUE));
     pos = slISBNs.col.FindIndex(nSelIndice);
	   slISBNs.col.RemoveAt(pos);
     pos = slPrecos.col.FindIndex(nSelIndice);
	   slPrecos.col.RemoveAt(pos);
     pos = slQtdEstoque.col.FindIndex(nSelIndice);
	   slQtdEstoque.col.RemoveAt(pos);
	   m_LstLivros.DeleteString(nSelIndice);
   }	
 }
}

void CFrmVenderLivros::OnBtnVender() 
{
   if (ValidaDados()) {
      if (SalvaLista()) {
        AfxMessageBox(Rotinas->lerStr(STR_VENRESUC), 
          MB_ICONINFORMATION | MB_OK, 0);
        LimpaDados();
      }
   }	
}


void CFrmVenderLivros::OnBtnLimpar() 
{
	LimpaDados();	
}
