// CadClientes.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadClientes.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadClientes dialog


CFrmCadClientes::CFrmCadClientes(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadClientes)
	//}}AFX_DATA_INIT
}


void CFrmCadClientes::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadClientes)
	DDX_Control(pDX, ID_FRMCADCLIENTES_RBMASCULINO, m_RbMasculino);
	DDX_Control(pDX, ID_FRMCADCLIENTES_RBFEMININO, m_RbFeminino);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTDTNASC, m_EdtDtNasc);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNPENDERECO, m_BtnPEndereco);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNPPROFISSAO, m_BtnPProfissao);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNPPAIS, m_BtnPPais);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTTELEFONE, m_EdtTelefone);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTPROFISSAO, m_EdtProfissao);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTPAIS, m_EdtPais);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTLOGRADOURO, m_EdtLogradouro);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTIDENTIDADE, m_EdtIdentidade);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTESTADO, m_EdtEstado);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTEMAIL, m_EdtEmail);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTCIDADE, m_EdtCidade);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTCODENDERECO, m_EdtCodEndereco);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTCODPAIS, m_EdtCodPais);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTCODPROFISSAO, m_EdtCodProfissao);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTCEP, m_EdtCep);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTBAIRRO, m_EdtBairro);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADCLIENTES_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTNOME, m_EdtNome);
	DDX_Control(pDX, ID_FRMCADCLIENTES_EDTCPF, m_EdtCPF);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadClientes, CDialog)
	//{{AFX_MSG_MAP(CFrmCadClientes)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	ON_EN_KILLFOCUS(ID_FRMCADCLIENTES_EDTCPF, OnEdtCpf_Killfocus)
	ON_EN_KILLFOCUS(ID_FRMCADCLIENTES_EDTCODENDERECO, OnEdtCodEndereco_Killfocus)
	ON_EN_KILLFOCUS(ID_FRMCADCLIENTES_EDTCODPAIS, OnEdtCodPais_Killfocus)
	ON_EN_KILLFOCUS(ID_FRMCADCLIENTES_EDTCODPROFISSAO, OnEdtCodProfissao_Killfocus)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNPENDERECO, OnBtnPEndereco)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNPPAIS, OnBtnPPais)
	ON_BN_CLICKED(ID_FRMCADCLIENTES_BTNPPROFISSAO, OnBtnPProfissao)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadClientes message handlers

BOOL CFrmCadClientes::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	m_EdtCPF.SetLimitText(14);
  m_EdtNome.SetLimitText(30);
  m_EdtEmail.SetLimitText(30);
  m_EdtIdentidade.SetLimitText(10);
  m_EdtCodEndereco.SetLimitText(10);
  m_EdtTelefone.SetLimitText(17);
  m_EdtCodPais.SetLimitText(3);
  m_EdtCodProfissao.SetLimitText(10);

 //SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
//          CM_CAD_CLIENTES, MAKELONG(FALSE, 0));
  
  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadClientes::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCPF), 
    Rotinas->lerStr(STR_CPFNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtNome), 
           Rotinas->lerStr(STR_CLININF)))
  		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtEmail), 
           Rotinas->lerStr(STR_EMAILNINF)))
  		  return FALSE;
      if (m_RbMasculino.GetCheck() == BST_UNCHECKED && 
          m_RbFeminino.GetCheck() == BST_UNCHECKED){
         AfxMessageBox(Rotinas->lerStr(STR_SEXNINF), MB_ICONERROR | MB_OK, 0);
        return FALSE;
      }
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtTelefone), 
           Rotinas->lerStr(STR_TELNINF)))
  		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodEndereco), 
           Rotinas->lerStr(STR_ENDNINF)))
  		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodPais), 
           Rotinas->lerStr(STR_PAISNINF)))
  		  return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtCodProfissao), 
           Rotinas->lerStr(STR_PROFNINF)))
  		  return FALSE;
  	}
  	return TRUE;
}

void CFrmCadClientes::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtCPF, 
  &m_EdtNome, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);
  
  InformaLimpaDados(NULL, 0, FALSE);
  HabilitaDados(TRUE);	
}

void CFrmCadClientes::OnBtnPesquisar() 
{
  if (CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtCPF, &m_EdtNome, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Cliente('S', Rotinas->retTexto(&m_EdtCPF),
    "","","","","","","","",""), Rotinas->lerStr(STR_CLINENC))) {
    InformaLimpaDados(&lstRegistros,0, TRUE);
    HabilitaDados(TRUE);	
  }
}

void CFrmCadClientes::OnBtnAnterior() 
{
  if (CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtCPF, &m_EdtNome, &nRegistros)) {
    InformaLimpaDados(&lstRegistros, nRegistros, TRUE);
  }  	
}

void CFrmCadClientes::OnBtnProximo() 
{
  if (CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtCPF, &m_EdtNome, &nRegistros)) {
    InformaLimpaDados(&lstRegistros, nRegistros, TRUE);
  }  			
}

void CFrmCadClientes::OnBtnSalvar() 
{
  CString sSexo, sDtNasc, sSqlInsert, sSqlUpdate;

  if (m_RbMasculino.GetCheck() == BST_CHECKED)
     sSexo = "M"; 
  else   
     sSexo = "F";

  sDtNasc = Rotinas->retDataHora(&m_EdtDtNasc, "MM/dd/yyyy", "");

  sSqlUpdate = ConsSQL->Cliente('U', Rotinas->retTexto(&m_EdtCPF), 
    Rotinas->retTexto(&m_EdtNome), Rotinas->retTexto(&m_EdtEmail),
    Rotinas->retTexto(&m_EdtIdentidade), sSexo,
    Rotinas->retTexto(&m_EdtTelefone), sDtNasc, 
    Rotinas->retTexto(&m_EdtCodEndereco), Rotinas->retTexto(&m_EdtCodPais),
    Rotinas->retTexto(&m_EdtCodProfissao));

  sSqlInsert = ConsSQL->Cliente('I', Rotinas->retTexto(&m_EdtCPF), 
    Rotinas->retTexto(&m_EdtNome), Rotinas->retTexto(&m_EdtEmail),
    Rotinas->retTexto(&m_EdtIdentidade), sSexo,
    Rotinas->retTexto(&m_EdtTelefone), sDtNasc, 
    Rotinas->retTexto(&m_EdtCodEndereco), Rotinas->retTexto(&m_EdtCodPais), 
    Rotinas->retTexto(&m_EdtCodProfissao));

  if (CFrmCadastros::SalvarDados(&m_EdtCPF, 
    &m_EdtNome, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Cliente('S', Rotinas->retTexto(&m_EdtCPF),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, TRUE)) {
    InformaLimpaDados(NULL, 0, FALSE);
    HabilitaDados(FALSE);	
  }
}

void CFrmCadClientes::OnBtnExcluir() 
{
  if (CFrmCadastros::ExcluirDados(&m_EdtCPF, 
    &m_EdtNome, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Cliente('D', Rotinas->retTexto(&m_EdtCPF),
    "","","","","","","","",""))) {
    InformaLimpaDados(NULL, 0, FALSE);
    HabilitaDados(FALSE);	
  }  
}

void CFrmCadClientes::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtCPF, 
    &m_EdtNome, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
  InformaLimpaDados(NULL, 0, FALSE);
  HabilitaDados(FALSE);	
}

void CFrmCadClientes::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadClientes::OnClose() 
{
  //SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
//    CM_CAD_CLIENTES, MAKELONG(TRUE, 0));
  CFrmCadastros::Fechar(0, CM_CAD_CLIENTES);  
}

void CFrmCadClientes::InformaLimpaDados(LISTAMSTR *lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar)
{ POSITION pos[17];
  UINT ncont;
  if (bInformar) {
    for (ncont=2; ncont < 17; ncont++)
      pos[ncont] = lstRegistros->col[ncont].FindIndex(nLinhaRegistro);

    m_EdtEmail.SetWindowText(lstRegistros->col[2].GetAt(pos[2]));
    m_EdtIdentidade.SetWindowText(lstRegistros->col[3].GetAt(pos[3]));
    if (lstRegistros->col[4].GetAt(pos[4]).Compare("M")==0) {
      m_RbMasculino.SetCheck(BST_CHECKED);
      m_RbFeminino.SetCheck(BST_UNCHECKED);
    } else {
      m_RbMasculino.SetCheck(BST_UNCHECKED);
      m_RbFeminino.SetCheck(BST_CHECKED);
    }      
    m_EdtTelefone.SetWindowText(lstRegistros->col[5].GetAt(pos[5]));
    Rotinas->setDataHora(&m_EdtDtNasc, 
      lstRegistros->col[6].GetAt(pos[6]).Mid(0,10), "");
    m_EdtCodEndereco.SetWindowText(lstRegistros->col[7].GetAt(pos[7]));
    m_EdtLogradouro.SetWindowText(lstRegistros->col[8].GetAt(pos[8]));
    m_EdtBairro.SetWindowText(lstRegistros->col[9].GetAt(pos[9]));
    m_EdtCep.SetWindowText(lstRegistros->col[10].GetAt(pos[10]));
    m_EdtCidade.SetWindowText(lstRegistros->col[11].GetAt(pos[11]));
    m_EdtEstado.SetWindowText(lstRegistros->col[12].GetAt(pos[12]));
    m_EdtCodPais.SetWindowText(lstRegistros->col[13].GetAt(pos[13]));
    m_EdtPais.SetWindowText(lstRegistros->col[14].GetAt(pos[14]));
    m_EdtCodProfissao.SetWindowText(lstRegistros->col[15].GetAt(pos[15]));
    m_EdtProfissao.SetWindowText(lstRegistros->col[16].GetAt(pos[16]));
  } else {
    m_EdtEmail.SetWindowText("");
    m_EdtIdentidade.SetWindowText("");
    m_RbMasculino.SetCheck(BST_CHECKED);
    m_RbFeminino.SetCheck(BST_UNCHECKED);
    m_EdtTelefone.SetWindowText("");
    m_EdtDtNasc.SetWindowText("");
    m_EdtCodEndereco.SetWindowText("");
    m_EdtLogradouro.SetWindowText("");
    m_EdtBairro.SetWindowText("");
    m_EdtCep.SetWindowText("");
    m_EdtCidade.SetWindowText("");
    m_EdtEstado.SetWindowText("");
    m_EdtCodPais.SetWindowText("");
    m_EdtPais.SetWindowText("");
    m_EdtCodProfissao.SetWindowText("");
    m_EdtProfissao.SetWindowText("");
  }
} 

void CFrmCadClientes::HabilitaDados(BOOL bHabilita)
{
  m_EdtEmail.EnableWindow(bHabilita);
  m_EdtIdentidade.EnableWindow(bHabilita);
  m_RbMasculino.EnableWindow(bHabilita);
  m_RbFeminino.EnableWindow(bHabilita);
  m_EdtTelefone.EnableWindow(bHabilita);
  m_EdtDtNasc.EnableWindow(bHabilita);
  m_EdtCodEndereco.EnableWindow(bHabilita);
  m_BtnPEndereco.EnableWindow(bHabilita);
  m_EdtLogradouro.EnableWindow(bHabilita);
  m_EdtBairro.EnableWindow(bHabilita);
  m_EdtCep.EnableWindow(bHabilita);
  m_EdtCidade.EnableWindow(bHabilita);
  m_EdtEstado.EnableWindow(bHabilita);
  m_EdtCodPais.EnableWindow(bHabilita);
  m_BtnPPais.EnableWindow(bHabilita);
  m_EdtCodProfissao.EnableWindow(bHabilita);
  m_BtnPProfissao.EnableWindow(bHabilita);
}

void CFrmCadClientes::OnEdtCpf_Killfocus() 
{ CString sCPF;
  sCPF = Rotinas->retTexto(&m_EdtCPF);

  if (sCPF.GetLength() > 0) {
  	if (Rotinas->validaCPF(sCPF)==FALSE) {      
      AfxMessageBox(Rotinas->lerStr(STR_CPFINV),MB_ICONERROR | MB_OK, 0);
      m_EdtCPF.SetWindowText("");
  		m_EdtCPF.SetFocus();
  	}
  }	
}

void CFrmCadClientes::OnEdtCodEndereco_Killfocus() 
{ CString sCodEnd, sLogradouro;
  POSITION pos;
  LISTAMSTR ConsCampo;

  sCodEnd = Rotinas->retTexto(&m_EdtCodEndereco);

  if (sCodEnd.GetLength() > 0) {
    sLogradouro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Endereco('S',
    sCodEnd,"","","","",""),Rotinas->lerStr(STR_ENDNENC));    
    if (sLogradouro.GetLength() > 0) {
      m_EdtLogradouro.SetWindowText(sLogradouro);
      pos = ConsCampo.col[2].FindIndex(0);
      m_EdtBairro.SetWindowText(ConsCampo.col[2].GetAt(pos));
      pos = ConsCampo.col[3].FindIndex(0);
      m_EdtCep.SetWindowText(ConsCampo.col[3].GetAt(pos));
      pos = ConsCampo.col[4].FindIndex(0);
      m_EdtCidade.SetWindowText(ConsCampo.col[4].GetAt(pos));
      pos = ConsCampo.col[5].FindIndex(0);
      m_EdtEstado.SetWindowText(ConsCampo.col[5].GetAt(pos));
    } else {
  	  m_EdtCodEndereco.SetFocus();
      m_EdtLogradouro.SetWindowText("");
      m_EdtBairro.SetWindowText("");
      m_EdtCep.SetWindowText("");
  	  m_EdtCidade.SetWindowText("");
  	  m_EdtEstado.SetWindowText("");
    }
  } else {
    m_EdtLogradouro.SetWindowText("");
    m_EdtBairro.SetWindowText("");
    m_EdtCep.SetWindowText("");
  	m_EdtCidade.SetWindowText("");
  	m_EdtEstado.SetWindowText("");
  }
}

void CFrmCadClientes::OnEdtCodPais_Killfocus() 
{ CString sCodPais, sPais;
  LISTAMSTR ConsCampo;
  sCodPais = Rotinas->retTexto(&m_EdtCodPais);

  if (sCodPais.GetLength() > 0) {
    sPais = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Pais('S',
    sCodPais,""),Rotinas->lerStr(STR_PAISNENC));    

    if (sPais.GetLength() > 0) {
      m_EdtPais.SetWindowText(sPais);
    } else {
      m_EdtCodPais.SetWindowText("");
      m_EdtCodPais.SetFocus();
    }
  } else {
    m_EdtPais.SetWindowText("");
  }
}

void CFrmCadClientes::OnEdtCodProfissao_Killfocus() 
{ CString sCodProfissao, sProfissao;
  LISTAMSTR ConsCampo;
  sCodProfissao = Rotinas->retTexto(&m_EdtCodProfissao);

  if (sCodProfissao.GetLength() > 0) {
    sProfissao = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Profissao('S',
    sCodProfissao,""),Rotinas->lerStr(STR_PROFNENC));    

    if (sProfissao.GetLength() > 0) {
      m_EdtProfissao.SetWindowText(sProfissao);
    } else {
      m_EdtCodProfissao.SetWindowText("");
      m_EdtCodProfissao.SetFocus();
    }
  } else {
    m_EdtProfissao.SetWindowText("");
  }
}

void CFrmCadClientes::OnBtnPEndereco() 
{
  CFrmConEnderecos *fConEnderecos = new CFrmConEnderecos(this);
  fConEnderecos->DoModal();
  m_EdtCodEndereco.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCodEndereco_Killfocus();	
}

void CFrmCadClientes::OnBtnPPais() 
{
  CFrmConPaises *fConPaises = new CFrmConPaises(this);
  fConPaises->DoModal();
  m_EdtCodPais.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCodPais_Killfocus();	
}

void CFrmCadClientes::OnBtnPProfissao() 
{
  CFrmConProfissoes *fConProfissoes = new CFrmConProfissoes(this);
  fConProfissoes->DoModal();
  m_EdtCodProfissao.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCodProfissao_Killfocus();		
}

