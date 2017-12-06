// CadLivros.cpp : implementation file
//

#include "stdafx.h"
#include "Livrus.h"
#include "CadLivros.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFrmCadLivros dialog


CFrmCadLivros::CFrmCadLivros(CWnd* pParent /*=NULL*/)
	: CFrmCadastros()
{
	//{{AFX_DATA_INIT(CFrmCadLivros)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CFrmCadLivros::DoDataExchange(CDataExchange* pDX)
{
	CFrmCadastros::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFrmCadLivros)
	DDX_Control(pDX, ID_FRMCADLIVROS_SPINVOLUME, m_SpinVolume);
	DDX_Control(pDX, ID_FRMCADLIVROS_SPINQTDESTOQUE, m_SpinQtdEstoque);
	DDX_Control(pDX, ID_FRMCADLIVROS_SPINNPAGINAS, m_SpinNPaginas);
	DDX_Control(pDX, ID_FRMCADLIVROS_SPINEDICAO, m_SpinEdicao);
	DDX_Control(pDX, ID_FRMCADLIVROS_SPINANOPUBLI, m_SpinAnoPubli);
	DDX_Control(pDX, ID_FRMCADLIVROS_LSTAUTORES, m_LstAutores);
	DDX_Control(pDX, ID_FRMCADLIVROS_LSTASSUNTOS, m_LstAssuntos);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTVOLUME, m_EdtVolume);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTQTDESTOQUE, m_EdtQtdEstoque);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTPRECO, m_EdtPreco);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTNPAGINAS, m_EdtNPaginas);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTEDITORA, m_EdtEditora);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTEDICAO, m_EdtEdicao);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTCODEDITORA, m_EdtCodEditora);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTCODAUTOR, m_EdtCodAutor);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTCODASSUNTO, m_EdtCodAssunto);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTAUTOR, m_EdtAutor);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTASSUNTO, m_EdtAssunto);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTANOPUBLI, m_EdtAnoPubli);
	DDX_Control(pDX, ID_FRMCADLIVROS_CMBIDIOMA, m_CmbIdioma);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNPEDITORA, m_BtnPEditora);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNPAUTOR, m_BtnPAutor);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNPASSUNTO, m_BtnPAssunto);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNADAUTORES, m_BtnAdAutores);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNADASSUNTOS, m_BtnAdAssuntos);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNSALVAR, m_BtnSalvar);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNPROXIMO, m_BtnProximo);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNPESQUISAR, m_BtnPesquisar);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNNOVO, m_BtnNovo);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNLIMPAR, m_BtnLimpar);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNFECHAR, m_BtnFechar);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNEXCLUIR, m_BtnExcluir);
	DDX_Control(pDX, ID_FRMCADLIVROS_BTNANTERIOR, m_BtnAnterior);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTTITULO, m_EdtTitulo);
	DDX_Control(pDX, ID_FRMCADLIVROS_EDTISBN, m_EdtISBN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFrmCadLivros, CFrmCadastros)
	//{{AFX_MSG_MAP(CFrmCadLivros)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNFECHAR, OnBtnFechar)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNNOVO, OnBtnNovo)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNPESQUISAR, OnBtnPesquisar)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNANTERIOR, OnBtnAnterior)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNPROXIMO, OnBtnProximo)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNSALVAR, OnBtnSalvar)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNEXCLUIR, OnBtnExcluir)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNLIMPAR, OnBtnLimpar)
	ON_WM_CLOSE()
	ON_EN_KILLFOCUS(ID_FRMCADLIVROS_EDTISBN, OnEdtISBN_Killfocus)
	ON_EN_KILLFOCUS(ID_FRMCADLIVROS_EDTCODEDITORA, OnEdtCodEditora_Killfocus)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNPEDITORA, OnBtnPEditora)
	ON_EN_KILLFOCUS(ID_FRMCADLIVROS_EDTPRECO, OnEdtPreco_Killfocus)
	ON_EN_KILLFOCUS(ID_FRMCADLIVROS_EDTCODASSUNTO, OnEdtCodAssunto_Killfocus)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNPASSUNTO, OnBtnPAssunto)
	ON_EN_KILLFOCUS(ID_FRMCADLIVROS_EDTCODAUTOR, OnEdtCodAutor_Killfocus)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNPAUTOR, OnBtnPAutor)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNADASSUNTOS, OnBtnAdAssuntos)
	ON_LBN_DBLCLK(ID_FRMCADLIVROS_LSTASSUNTOS, OnLstAssuntos_Dblclk)
	ON_BN_CLICKED(ID_FRMCADLIVROS_BTNADAUTORES, OnBtnAdAutores)
	ON_LBN_DBLCLK(ID_FRMCADLIVROS_LSTAUTORES, OnLstAutores_Dblclk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFrmCadLivros message handlers

BOOL CFrmCadLivros::OnInitDialog() 
{
	CFrmCadastros::OnInitDialog();
	
	m_EdtISBN.SetLimitText(13);
  m_EdtTitulo.SetLimitText(50);

  m_EdtEdicao.SetLimitText(4);
  m_EdtAnoPubli.SetLimitText(4);
  m_EdtCodEditora.SetLimitText(5);
  m_EdtVolume.SetLimitText(4);        
  m_EdtNPaginas.SetLimitText(5);
  m_EdtPreco.SetLimitText(7);
  m_EdtQtdEstoque.SetLimitText(5);
  
  //SendMessage(g_hBarraFerram, TB_ENABLEBUTTON, 
//          CM_CAD_LIVROS, MAKELONG(FALSE, 0));

  m_SpinEdicao.SetRange(9999, 1);
  m_SpinAnoPubli.SetRange(9999, 1); 
  m_SpinVolume.SetRange(9999, 1);
  m_SpinNPaginas.SetRange(9999, 1);
  m_SpinQtdEstoque.SetRange(9999, 0);

  AdicionaCombo();

  nRegistros = 0;
	return TRUE;  
}

BOOL CFrmCadLivros::ValidaDados(BOOL bTodosDados)
{
if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtISBN), 
    Rotinas->lerStr(STR_ISBNNINF)))
  	  return FALSE;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtTitulo), 
           Rotinas->lerStr(STR_TITNINF)))
  		return FALSE;
  	  if (Rotinas->ValidaCampo(Rotinas->retTexto(&m_EdtEditora), 
           Rotinas->lerStr(STR_EDTNINF)))
  		    return FALSE;
      if (m_LstAssuntos.GetCount()==0) {
        AfxMessageBox(Rotinas->lerStr(STR_ASSNINF), MB_ICONERROR | MB_OK, 0);
        return FALSE;
      }
      if (m_LstAutores.GetCount()==0) {
        AfxMessageBox(Rotinas->lerStr(STR_AUTNINF), MB_ICONERROR | MB_OK, 0);
        return FALSE;
      }
  	}
  	return TRUE;
}

void CFrmCadLivros::OnBtnNovo() 
{
  CFrmCadastros::btnNovoClick(&m_EdtISBN, 
  &m_EdtTitulo, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
  &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);
  
  InformaLimpaDados(NULL, 0, FALSE);
  HabilitaDados(TRUE);	
}

void CFrmCadLivros::OnBtnPesquisar() 
{
  if (CFrmCadastros::PesquisarDados(&lstRegistros, 
    &m_EdtISBN, &m_EdtTitulo, &m_BtnPesquisar, 
    &m_BtnAnterior, &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, 
    ConsSQL->Livro('S', Rotinas->retTexto(&m_EdtISBN),
    "","","","","","","","",""), Rotinas->lerStr(STR_LIVNENC))) {
    InformaLimpaDados(&lstRegistros,0, TRUE);
    HabilitaDados(TRUE);	
  }
}

void CFrmCadLivros::OnBtnAnterior() 
{
  if (CFrmCadastros::registroAnterior(&lstRegistros, 
    &m_EdtISBN, &m_EdtTitulo, &nRegistros)) {
    InformaLimpaDados(&lstRegistros, nRegistros, TRUE);
  }  
}

void CFrmCadLivros::OnBtnProximo() 
{
  if (CFrmCadastros::registroProximo(&lstRegistros, 
    &m_EdtISBN, &m_EdtTitulo, &nRegistros)) {
    InformaLimpaDados(&lstRegistros, nRegistros, TRUE);
  }  		
}

void CFrmCadLivros::OnBtnSalvar() 
{
  CString sCodIdioma, sSqlInsert, sSqlUpdate;
  UINT nPos;
  POSITION pos;
  
  nPos = m_CmbIdioma.GetCurSel();
  pos = slIdiomas.col.FindIndex(nPos);
  sCodIdioma = slIdiomas.col.GetAt(pos);

  sSqlUpdate = ConsSQL->Livro('U', Rotinas->retTexto(&m_EdtISBN), 
    Rotinas->retTexto(&m_EdtTitulo), Rotinas->retTexto(&m_EdtEdicao), 
    Rotinas->retTexto(&m_EdtAnoPubli), Rotinas->retTexto(&m_EdtVolume),
    Rotinas->retTexto(&m_EdtCodEditora), sCodIdioma,
    Rotinas->retTexto(&m_EdtNPaginas),
    Rotinas->VirgulaParaPonto(Rotinas->retTexto(&m_EdtPreco),FALSE),
    Rotinas->retTexto(&m_EdtQtdEstoque));

  sSqlInsert = ConsSQL->Livro('I', Rotinas->retTexto(&m_EdtISBN), 
    Rotinas->retTexto(&m_EdtTitulo), Rotinas->retTexto(&m_EdtEdicao), 
    Rotinas->retTexto(&m_EdtAnoPubli), Rotinas->retTexto(&m_EdtVolume),
    Rotinas->retTexto(&m_EdtCodEditora), sCodIdioma,
    Rotinas->retTexto(&m_EdtNPaginas),
    Rotinas->VirgulaParaPonto(Rotinas->retTexto(&m_EdtPreco),FALSE),
    Rotinas->retTexto(&m_EdtQtdEstoque));

  if (CFrmCadastros::SalvarDados(&m_EdtISBN, 
    &m_EdtTitulo, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(TRUE),
    ConsSQL->Livro('S', Rotinas->retTexto(&m_EdtISBN),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, FALSE)) {
    SalvaLista('A');
    SalvaLista('B');
    CFrmCadastros::btnLimparClick(&m_EdtISBN, 
    &m_EdtTitulo, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);
    InformaLimpaDados(NULL, 0, FALSE);
    HabilitaDados(FALSE);	    
  }  
}

void CFrmCadLivros::OnBtnExcluir() 
{
  if (CFrmCadastros::ExcluirDados(&m_EdtISBN, 
    &m_EdtTitulo, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir, ValidaDados(FALSE),
    ConsSQL->Livro('D', Rotinas->retTexto(&m_EdtISBN),
    "","","","","","","","",""))) {
    InformaLimpaDados(NULL, 0, FALSE);
    HabilitaDados(FALSE);	
  }  
}

void CFrmCadLivros::OnBtnLimpar() 
{
  CFrmCadastros::btnLimparClick(&m_EdtISBN, 
    &m_EdtTitulo, &m_BtnNovo, &m_BtnPesquisar, &m_BtnAnterior, 
    &m_BtnProximo, &m_BtnSalvar, &m_BtnExcluir);	
  InformaLimpaDados(NULL, 0, FALSE);
  HabilitaDados(FALSE);	
}

void CFrmCadLivros::OnBtnFechar() 
{
  SendMessage(WM_CLOSE, 0, 0);
}

void CFrmCadLivros::OnClose() 
{
  CFrmCadastros::Fechar(0, CM_CAD_LIVROS);  
}

void CFrmCadLivros::InformaLimpaDados(LISTAMSTR *lstRegistros, 
  UINT nLinhaRegistro, BOOL bInformar)
{ POSITION pos[12];
  UINT ncont;
  if (bInformar) {
    for (ncont=2; ncont < 12; ncont++)
      pos[ncont] = lstRegistros->col[ncont].FindIndex(nLinhaRegistro);

    m_EdtEdicao.SetWindowText(lstRegistros->col[2].GetAt(pos[2]));
    m_EdtAnoPubli.SetWindowText(lstRegistros->col[3].GetAt(pos[3]));
    m_EdtVolume.SetWindowText(lstRegistros->col[4].GetAt(pos[4]));
    m_EdtCodEditora.SetWindowText(lstRegistros->col[5].GetAt(pos[5]));
    m_EdtEditora.SetWindowText(lstRegistros->col[6].GetAt(pos[6]));
    m_CmbIdioma.SelectString(0, lstRegistros->col[8].GetAt(pos[8]));
    m_EdtNPaginas.SetWindowText(lstRegistros->col[9].GetAt(pos[9]));
    m_EdtPreco.SetWindowText(
      Rotinas->VirgulaParaPonto(lstRegistros->col[10].GetAt(pos[10]), TRUE));
    m_EdtQtdEstoque.SetWindowText(lstRegistros->col[11].GetAt(pos[11]));
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAss('S', 
      Rotinas->retTexto(&m_EdtISBN),""),&m_LstAssuntos,&slAssuntos);      
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAut('S',
      Rotinas->retTexto(&m_EdtISBN),""),&m_LstAutores,&slAutores);
  } else {  
    m_EdtEdicao.SetWindowText("1");
    m_EdtAnoPubli.SetWindowText(Rotinas->retDataHoraStr(TRUE,FALSE).Mid(6,4));
    m_EdtVolume.SetWindowText("1");
    m_EdtCodEditora.SetWindowText("");
    m_EdtEditora.SetWindowText("");
    m_CmbIdioma.SetCurSel(0);    
    m_EdtNPaginas.SetWindowText("1");
    m_EdtPreco.SetWindowText("0,00");
    m_EdtQtdEstoque.SetWindowText("1");
    m_EdtCodAssunto.SetWindowText("");
    m_LstAssuntos.ResetContent();
    m_EdtCodAutor.SetWindowText("");
    m_LstAutores.ResetContent();
    slAssuntos.col.RemoveAll();
    slAutores.col.RemoveAll();
  }
} 

void CFrmCadLivros::HabilitaDados(BOOL bHabilita)
{
  m_EdtEdicao.EnableWindow(bHabilita);
  m_EdtAnoPubli.EnableWindow(bHabilita);
  m_EdtVolume.EnableWindow(bHabilita);
  m_EdtCodEditora.EnableWindow(bHabilita);
  m_BtnPEditora.EnableWindow(bHabilita);
  m_CmbIdioma.EnableWindow(bHabilita);
  m_EdtNPaginas.EnableWindow(bHabilita);
  m_EdtPreco.EnableWindow(bHabilita);
  m_EdtQtdEstoque.EnableWindow(bHabilita);
  m_EdtCodAssunto.EnableWindow(bHabilita);
  m_BtnPAssunto.EnableWindow(bHabilita);
  m_BtnAdAssuntos.EnableWindow(bHabilita);
  m_LstAssuntos.EnableWindow(bHabilita);
  m_EdtCodAutor.EnableWindow(bHabilita);
  m_BtnPAutor.EnableWindow(bHabilita);
  m_BtnAdAutores.EnableWindow(bHabilita);
  m_LstAutores.EnableWindow(bHabilita);
  m_SpinEdicao.EnableWindow(bHabilita);
  m_SpinAnoPubli.EnableWindow(bHabilita);
  m_SpinVolume.EnableWindow(bHabilita);
  m_SpinNPaginas.EnableWindow(bHabilita);
  m_SpinQtdEstoque.EnableWindow(bHabilita);
}

void CFrmCadLivros::OnEdtISBN_Killfocus() 
{ CString sISBN;
  sISBN = Rotinas->retTexto(&m_EdtISBN);

  if (sISBN.GetLength() > 0) {
  	if (Rotinas->validaISBN(sISBN)==FALSE) {      
      AfxMessageBox(Rotinas->lerStr(STR_ISBNINV), MB_ICONERROR | MB_OK, 0);
      m_EdtISBN.SetWindowText("");
  		m_EdtISBN.SetFocus();
  	}
  }
}

void CFrmCadLivros::AdicionaCombo() 
{ POSITION pos[3];
  LISTAMSTR Campos;

  if (Rotinas->ConsultaDadosLista(gConexao, &Campos, ConsSQL->Idioma('S',"",""))) {
	  pos[0] = Campos.col[0].GetHeadPosition();
    pos[1] = Campos.col[1].GetHeadPosition();
    pos[2] = slIdiomas.col.GetHeadPosition();
    while (pos[0] != NULL) {
      slIdiomas.col.InsertAfter(pos[2], Campos.col[0].GetNext(pos[0]));
	    m_CmbIdioma.AddString(Campos.col[1].GetNext(pos[1]));
	  }      
  }
}

void CFrmCadLivros::SalvaLista(TCHAR sOpcao) 
{
POSITION pos;
CString sISBN;
INT nCont, nQtd;

  sISBN = Rotinas->retTexto(&m_EdtISBN);
  if (sOpcao=='A') {
    Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('D',sISBN,"")); 

    nQtd = slAssuntos.col.GetCount();
    for (nCont=0; nCont < nQtd; nCont++)  {      
      pos = slAssuntos.col.FindIndex(nCont);
      Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('I', 
        sISBN, slAssuntos.col.GetAt(pos)));
    }
  } else if (sOpcao=='B') {
  	Rotinas->AtualizaDados(gConexao,ConsSQL->LivroAut('D',sISBN,""));

    nQtd = slAutores.col.GetCount();
    for (nCont=0; nCont < nQtd; nCont++)  {      
      pos = slAutores.col.FindIndex(nCont);
      Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAut('I', 
        sISBN, slAutores.col.GetAt(pos)));
    }
  }
}

void CFrmCadLivros::OnEdtCodEditora_Killfocus() 
{ CString sCodEditora, sEditora;
  LISTAMSTR ConsCampo;
  sCodEditora = Rotinas->retTexto(&m_EdtCodEditora);

  if (sCodEditora.GetLength() > 0) {
    sEditora = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Editora('S',
    sCodEditora,""),Rotinas->lerStr(STR_EDTNENC));    
    
    if (sEditora.GetLength() > 0) {
      m_EdtEditora.SetWindowText(sEditora);
    } else {
      m_EdtCodEditora.SetWindowText("");
      m_EdtCodEditora.SetFocus();
    }
  } else {
    m_EdtEditora.SetWindowText("");
  }
}

void CFrmCadLivros::OnBtnPEditora() 
{
  CFrmConEditoras *fConEditoras = new CFrmConEditoras(this);
  fConEditoras->DoModal();
  m_EdtCodEditora.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCodEditora_Killfocus();	  
}

void CFrmCadLivros::OnEdtPreco_Killfocus() 
{ CString sPreco;

  sPreco = Rotinas->retTexto(&m_EdtPreco);
  if (Rotinas->ValidaFloat(Rotinas->VirgulaParaPonto(sPreco, FALSE)))
    m_EdtPreco.SetWindowText(Rotinas->VirgulaParaPonto(sPreco, TRUE));
  else {
    m_EdtPreco.SetWindowText("0,01");
    m_EdtPreco.SetFocus();
  }
}

void CFrmCadLivros::OnEdtCodAssunto_Killfocus() 
{ CString sCodAssunto, sAssunto;
  LISTAMSTR ConsCampo;
  sCodAssunto = Rotinas->retTexto(&m_EdtCodAssunto);

  if (sCodAssunto.GetLength() > 0) {
    sAssunto = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Assunto('S',
    sCodAssunto,""),Rotinas->lerStr(STR_ASSNENC));    
    
    if (sAssunto.GetLength() > 0) {
      m_EdtAssunto.SetWindowText(sAssunto);
    } else {
      m_EdtCodAssunto.SetWindowText("");
      m_EdtCodAssunto.SetFocus();
    }
  } else {
    m_EdtAssunto.SetWindowText("");
  }
}

void CFrmCadLivros::OnBtnPAssunto() 
{
  CFrmConAssuntos *fConAssuntos = new CFrmConAssuntos(this);
  fConAssuntos->DoModal();
  m_EdtCodAssunto.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCodAssunto_Killfocus();	  
}

void CFrmCadLivros::OnEdtCodAutor_Killfocus() 
{ CString sCodAutor, sAutor;
  LISTAMSTR ConsCampo;
  sCodAutor = Rotinas->retTexto(&m_EdtCodAutor);

  if (sCodAutor.GetLength() > 0) {
    sAutor = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Autor('S',
    sCodAutor,""),Rotinas->lerStr(STR_AUTNENC));    
    
    if (sAutor.GetLength() > 0) {
      m_EdtAutor.SetWindowText(sAutor);
    } else {
      m_EdtCodAutor.SetWindowText("");
      m_EdtCodAutor.SetFocus();
    }
  } else {
    m_EdtAutor.SetWindowText("");
  }
}

void CFrmCadLivros::OnBtnPAutor() 
{
  CFrmConAutores *fConAutores = new CFrmConAutores(this);
  fConAutores->DoModal();
  m_EdtCodAutor.SetWindowText(Rotinas_sCodigoSelecionado);
  OnEdtCodAutor_Killfocus();	  
}

void CFrmCadLivros::OnBtnAdAssuntos() 
{
  Rotinas->AdicionaItemLista(&m_LstAssuntos, 
    &slAssuntos, &m_EdtCodAssunto, &m_EdtAssunto);
}

void CFrmCadLivros::OnLstAssuntos_Dblclk() 
{
  Rotinas->RemoveItemLista(&m_LstAssuntos,&slAssuntos);
}

void CFrmCadLivros::OnBtnAdAutores() 
{
  Rotinas->AdicionaItemLista(&m_LstAutores, 
    &slAutores, &m_EdtCodAutor, &m_EdtAutor);	
}

void CFrmCadLivros::OnLstAutores_Dblclk() 
{
  Rotinas->RemoveItemLista(&m_LstAutores,&slAutores);
}
