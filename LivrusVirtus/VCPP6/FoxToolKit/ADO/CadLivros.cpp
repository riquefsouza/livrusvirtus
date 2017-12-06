#include "resource.h"
#include "Cadastros.h"
#include "CadLivros.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

CfrmCadLivros *frmCadLivros = (CfrmCadLivros *) NULL;

FXDEFMAP(CfrmCadLivros) CfrmCadLivrosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadLivros::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadLivros::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadLivros::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadLivros::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadLivros::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadLivros::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadLivros::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadLivros::onBtnFechar),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadLivros::ID_FRMCADASTROS_EDTCODIGO, 
    CfrmCadLivros::onEdtCodigo_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadLivros::ID_FRMCADLIVROS_EDTCODEDITORA, 
    CfrmCadLivros::onEdtCodEditora_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadLivros::ID_FRMCADLIVROS_EDTCODASSUNTO, 
    CfrmCadLivros::onEdtCodAssunto_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadLivros::ID_FRMCADLIVROS_EDTCODAUTOR, 
    CfrmCadLivros::onEdtCodAutor_Killfocus),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADLIVROS_BTNPEDITORA, 
    CfrmCadLivros::onBtnPEditora),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADLIVROS_BTNPASSUNTO, 
    CfrmCadLivros::onBtnPAssunto),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADLIVROS_BTNADASSUNTOS, 
    CfrmCadLivros::onBtnAdAssuntos),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADLIVROS_BTNPAUTOR, 
    CfrmCadLivros::onBtnPAutor),
  FXMAPFUNC(SEL_COMMAND, CfrmCadLivros::ID_FRMCADLIVROS_BTNADAUTORES, 
    CfrmCadLivros::onBtnAdAutores),
  FXMAPFUNC(SEL_DOUBLECLICKED, CfrmCadLivros::ID_FRMCADLIVROS_LSTASSUNTOS, 
    CfrmCadLivros::onLstAssuntos_Dblclk),
  FXMAPFUNC(SEL_DOUBLECLICKED, CfrmCadLivros::ID_FRMCADLIVROS_LSTAUTORES, 
    CfrmCadLivros::onLstAutores_Dblclk),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadLivros::onClose)
};
FXIMPLEMENT(CfrmCadLivros,CfrmCadastros,CfrmCadLivrosMap,
  ARRAYNUMBER(CfrmCadLivrosMap))

CfrmCadLivros::CfrmCadLivros(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADLIVRO, 
  iconeMDI, menuMDI, TEXTFIELD_NORMAL, false) {
  IniciaControles();
}

void CfrmCadLivros::IniciaControles() {
  this->resize(548, 475);
  this->labCodigo->setText("ISBN:");
  CfrmCadastros::edtCodigo->hide();
  this->edtCodigo = new FXTextField(frame5, 13, this, 
    ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 24, 121, 21, 3, 20);
  this->labDescricao->setText("Título:");  
  this->edtDescricao->resize(312, 21);
  this->edtDescricao->setNumColumns(50);

  frame10 = new FXVerticalFrame(frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame11 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame12 = new FXVerticalFrame(frame11, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame13 = new FXHorizontalFrame(frame11, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame14 = new FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame15 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame16 = new FXVerticalFrame(frame15, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame17 = new FXVerticalFrame(frame15, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame18 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame19 = new FXVerticalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame20 = new FXHorizontalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame21 = new FXVerticalFrame(frame20, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame22 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame23 = new FXVerticalFrame(frame22, LAYOUT_LEFT|LAYOUT_BOTTOM, 
    0,0,0,0,0,0,0,0);
  frame24 = new FXHorizontalFrame(frame22, LAYOUT_LEFT|FRAME_THICK|
    FRAME_SUNKEN, 0,0,0,0,0,0,0,0);

  frame25 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame26 = new FXVerticalFrame(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame27 = new FXHorizontalFrame(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame28 = new FXVerticalFrame(frame27, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame29 = new FXHorizontalFrame(frame3, LAYOUT_RIGHT|FRAME_THICK|
    FRAME_SUNKEN, 0,0,0,0,0,0,0,0);

  this->labEdicao = new FXLabel(frame10, "Edição:", NULL, LAYOUT_LEFT, 
    326, 48, 39, 13);
  this->edtEdicao = new FXSpinner(frame10, 10, NULL, 0, SPIN_NORMAL|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
    324, 64, 92, 21);
  this->edtEdicao->setRange(1,9999);
  this->edtEdicao->disable();

  this->labAnoPubli = new FXLabel(frame12, "Ano Publicação:", NULL, LAYOUT_LEFT, 
    8, 88, 81, 13);
  this->edtAnoPubli = new FXSpinner(frame12, 10, NULL, 0, SPIN_NORMAL|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
    8, 104, 92, 21);
  this->edtAnoPubli->setRange(1,9999);
  this->edtAnoPubli->disable();

  this->labEditora = new FXLabel(frame14, "Editora:", NULL, LAYOUT_LEFT, 
    104, 88, 39, 13);
  this->edtCodEditora = new FXTextField(frame14, 5, this, 
    ID_FRMCADLIVROS_EDTCODEDITORA, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    104, 104, 78, 21, 3, 20);
  this->edtCodEditora->disable();
  this->edtEditora = new FXTextField(frame13, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
    184, 104, 216, 21, 3, 20);
  this->edtEditora->disable();
  this->btnPEditora = new FXButton(frame13, "...", NULL, this, 
    ID_FRMCADLIVROS_BTNPEDITORA, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 400, 104, 21, 21, 10, 10, 3, 3 );
  this->btnPEditora->disable();

  this->labVolume = new FXLabel(frame16, "Volume:", NULL, LAYOUT_LEFT, 
    8, 128, 41, 13);
  this->edtVolume = new FXSpinner(frame16, 10, NULL, 0, SPIN_NORMAL|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
    8, 144, 92, 21);
  this->edtVolume->setRange(1,9999);
  this->edtVolume->disable();

  this->labIdioma = new FXLabel(frame17, "Volume:", NULL, LAYOUT_LEFT, 
    104, 128, 56, 13);
  this->cmbIdioma = new FXComboBox(frame17,8,NULL,0,
    COMBOBOX_INSERT_LAST|FRAME_SUNKEN|FRAME_THICK|LAYOUT_SIDE_TOP
    |LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 144, 320, 21, 3, 20);
  this->cmbIdioma->setEditable(false);
  this->cmbIdioma->setNumVisible(8);
  this->cmbIdioma->disable();
  
  this->labNPaginas = new FXLabel(frame19, "Nº Páginas:", NULL, LAYOUT_LEFT, 
    8, 168, 59, 13);
  this->edtNPaginas = new FXSpinner(frame19, 10, NULL, 0, SPIN_NORMAL|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
    8, 184, 92, 21);
  this->edtNPaginas->setRange(1,9999);
  this->edtNPaginas->disable();

  this->labAssunto = new FXLabel(frame21, "Assunto:", NULL, LAYOUT_LEFT, 
    104, 168, 44, 13);
  this->edtCodAssunto = new FXTextField(frame21, 10, this, 
    ID_FRMCADLIVROS_EDTCODASSUNTO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    104, 184, 78, 21, 3, 20);
  this->edtCodAssunto->disable();
  this->edtAssunto = new FXTextField(frame20, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
    184, 184, 192, 21, 3, 20);
  this->edtAssunto->disable();
  this->btnAdAssuntos = new FXButton(frame20, "+", NULL, this, 
    ID_FRMCADLIVROS_BTNADASSUNTOS, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 376, 184, 21, 21, 10, 10, 3, 3 );
  this->btnAdAssuntos->disable();
  this->btnPAssunto = new FXButton(frame20, "...", NULL, this, 
    ID_FRMCADLIVROS_BTNPASSUNTO, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 400, 184, 21, 21, 10, 10, 3, 3 );
  this->btnPAssunto->disable();

  this->labPreco = new FXLabel(frame23, "Preço:", NULL, LAYOUT_LEFT, 
    8, 216, 40, 13);
  this->edtPreco = new FXTextField(frame23, 7, NULL, 
    ID_FRMCADLIVROS_EDTCODEDITORA, TEXTFIELD_LIMITED|TEXTFIELD_REAL|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    7, 232, 92, 21, 3, 20);
  this->edtPreco->disable();

  lstAssuntos = new FXList(frame24, this, ID_FRMCADLIVROS_LSTASSUNTOS, 
    LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 208, 320, 48);
  lstAssuntos->disable();

  this->labQtdEstoque = new FXLabel(frame26, "Qtd. Estoque:", NULL, LAYOUT_LEFT, 
    6, 256, 68, 13);
  this->edtQtdEstoque = new FXSpinner(frame26, 10, NULL, 0, SPIN_NORMAL|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
    8, 272, 92, 21);
  this->edtQtdEstoque->setRange(0,9999);
  this->edtQtdEstoque->disable();

  this->labAutor = new FXLabel(frame28, "Autor:", NULL, LAYOUT_LEFT, 
    104, 256, 31, 13);
  this->edtCodAutor = new FXTextField(frame28, 10, this, 
    ID_FRMCADLIVROS_EDTCODAUTOR, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    104, 272, 78, 21, 3, 20);
  this->edtCodAutor->disable();
  this->edtAutor = new FXTextField(frame27, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
    184, 272, 192, 21, 3, 20);
  this->edtAutor->disable();
  this->btnAdAutores = new FXButton(frame27, "+", NULL, this, 
    ID_FRMCADLIVROS_BTNADAUTORES, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 376, 272, 21, 21, 10, 10, 3, 3 );
  this->btnAdAutores->disable();
  this->btnPAutor = new FXButton(frame27, "...", NULL, this, 
    ID_FRMCADLIVROS_BTNPAUTOR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 400, 272, 21, 21, 10, 10, 3, 3 );
  this->btnPAutor->disable();

  lstAutores = new FXList(frame29, this, ID_FRMCADLIVROS_LSTASSUNTOS, 
    LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 296, 320, 48);
  lstAutores->disable();
  
  IniciaBotoes();
  AdicionaCombo();
}

CfrmCadLivros::~CfrmCadLivros(){
  frmPrincipal->tlbLivro->enable();
  frmPrincipal->mnuCadLivros->enable();  
}

FXbool CfrmCadLivros::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_ISBNNINF))
  	  return false;
  if (bTodosDados) {
    if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_TITNINF))
      return false;
	  if (Rotinas->ValidaCampo(edtEditora->getText(), STR_EDTNINF))
		    return false;
    if (lstAssuntos->getNumItems()==0) {
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_ASSNINF);

      return false;
    }
    if (lstAutores->getNumItems()==0) {
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_AUTNINF);
      return false;
    }
  }
  return true;
}

long CfrmCadLivros::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadLivros::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  return true;
}

long CfrmCadLivros::onBtnPesquisar(FXObject*,FXSelector,void*) {
  if (PesquisarDados(ConsSQL->Livro('S', edtCodigo->getText(),
    "","","","","","","","",""), STR_LIVNENC)) {
    InformaLimpaDados(true);
    HabilitaDados(true);
  }
  return true;
}

long CfrmCadLivros::onBtnAnterior(FXObject*,FXSelector,void*) {
  if (registroAnterior())
    InformaLimpaDados(true);
  return true;
}

long CfrmCadLivros::onBtnProximo(FXObject*,FXSelector,void*) {
  if (registroProximo())
    InformaLimpaDados(true);
  return true;
}

long CfrmCadLivros::onBtnSalvar(FXObject*,FXSelector,void*) {
  FXString sCodIdioma, sSqlInsert, sSqlUpdate;
  int nPos;

  nPos = cmbIdioma->getCurrentItem();
  sCodIdioma = slIdiomas.col[nPos];

  sSqlUpdate = ConsSQL->Livro('U', edtCodigo->getText(),
    edtDescricao->getText(), FXStringFormat("%d",edtEdicao->getValue()),
    FXStringFormat("%d",edtAnoPubli->getValue()),
    FXStringFormat("%d",edtVolume->getValue()),
    edtCodEditora->getText(), sCodIdioma,
    FXStringFormat("%d",edtNPaginas->getValue()),
    Rotinas->VirgulaParaPonto(edtPreco->getText(),false),
    FXStringFormat("%d",edtQtdEstoque->getValue()));

  sSqlInsert = ConsSQL->Livro('I', edtCodigo->getText(),
    edtDescricao->getText(), FXStringFormat("%d",edtEdicao->getValue()),
    FXStringFormat("%d",edtAnoPubli->getValue()),
    FXStringFormat("%d",edtVolume->getValue()),
    edtCodEditora->getText(), sCodIdioma,
    FXStringFormat("%d",edtNPaginas->getValue()),
    Rotinas->VirgulaParaPonto(edtPreco->getText(),false),
    FXStringFormat("%d",edtQtdEstoque->getValue()));

  if (SalvarDados(ValidaDados(true),
    ConsSQL->Livro('S', edtCodigo->getText(),"","","","","","","","",""),
    sSqlUpdate, sSqlInsert, false)) {
    SalvaLista('A');
    SalvaLista('B');
    btnLimparClick();
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
  return true;
}

long CfrmCadLivros::onBtnExcluir(FXObject*,FXSelector,void*) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Livro('D', edtCodigo->getText(),
    "","","","","","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
  return true;
}

long CfrmCadLivros::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
  return true;
}

long CfrmCadLivros::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}

void CfrmCadLivros::InformaLimpaDados(FXbool bInformar)
{
  if (bInformar) {
    edtEdicao->setValue(FXIntVal(lstRegistros.col[2][nLinhaRegistro]));
    edtAnoPubli->setValue(FXIntVal(lstRegistros.col[3][nLinhaRegistro]));
    edtVolume->setValue(FXIntVal(lstRegistros.col[4][nLinhaRegistro]));
    edtCodEditora->setText(lstRegistros.col[5][nLinhaRegistro]);
    edtEditora->setText(lstRegistros.col[6][nLinhaRegistro]);
    cmbIdioma->setText(lstRegistros.col[8][nLinhaRegistro]);
    edtNPaginas->setValue(FXIntVal(lstRegistros.col[9][nLinhaRegistro]));
    edtPreco->setText(
      Rotinas->VirgulaParaPonto(lstRegistros.col[10][nLinhaRegistro], true));
    edtQtdEstoque->setValue(FXIntVal(lstRegistros.col[11][nLinhaRegistro]));
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAss('S',
      edtCodigo->getText(), ""), lstAssuntos, &slAssuntos);
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAut('S',
      edtCodigo->getText(), ""), lstAutores, &slAutores);
  } else {
    edtEdicao->setValue(1);
    edtAnoPubli->setValue(FXIntVal(
      Rotinas->retDataHoraStr(true,false).mid(6,4)));
    edtVolume->setValue(1);
    edtCodEditora->setText("");
    edtEditora->setText("");
    cmbIdioma->setCurrentItem(0);
    edtNPaginas->setValue(1);
    edtPreco->setText("0,00");
    edtQtdEstoque->setValue(1);
    edtCodAssunto->setText("");
    lstAssuntos->clearItems();
    edtCodAutor->setText("");
    lstAutores->clearItems();
    slAssuntos.col.clear();
    slAutores.col.clear();
  }
}

void CfrmCadLivros::HabilitaDados(FXbool bHabilita)
{
  bHabilita ? edtEdicao->enable() : edtEdicao->disable();
  bHabilita ? edtAnoPubli->enable() : edtAnoPubli->disable();
  bHabilita ? edtVolume->enable() : edtVolume->disable();
  bHabilita ? edtCodEditora->enable() : edtCodEditora->disable();
  bHabilita ? btnPEditora->enable() : btnPEditora->disable();
  bHabilita ? cmbIdioma->enable() : cmbIdioma->disable();
  bHabilita ? edtNPaginas->enable() : edtNPaginas->disable();
  bHabilita ? edtPreco->enable() : edtPreco->disable();
  bHabilita ? edtQtdEstoque->enable() : edtQtdEstoque->disable();
  bHabilita ? edtCodAssunto->enable() : edtCodAssunto->disable();
  bHabilita ? btnPAssunto->enable() : btnPAssunto->disable();
  bHabilita ? btnAdAssuntos->enable() : btnAdAssuntos->disable();
  bHabilita ? lstAssuntos->enable() : lstAssuntos->disable();
  bHabilita ? edtCodAutor->enable() : edtCodAutor->disable();
  bHabilita ? btnPAutor->enable() : btnPAutor->disable();
  bHabilita ? btnAdAutores->enable() : btnAdAutores->disable();
  bHabilita ? lstAutores->enable() : lstAutores->disable();
}

void CfrmCadLivros::AdicionaCombo()
{
  LISTAMSTR Campos;
  FXint nLinha;

  if (Rotinas->ConsultaDadosLista(gConexao, &Campos,
    ConsSQL->Idioma('S',"",""))) {
    for (nLinha = 0; nLinha < Campos.col[0].no(); nLinha++) {
	    slIdiomas.col.append(Campos.col[0][nLinha]);
	    cmbIdioma->appendItem(Campos.col[1][nLinha]);
	  }
  }
  if (Campos.col[0].no() < 8)
    this->cmbIdioma->setNumVisible(Campos.col[0].no());
}

void CfrmCadLivros::SalvaLista(FXchar sOpcao)
{
FXString sISBN;
FXint nCont, nQtd;

  sISBN = edtCodigo->getText();
  if (sOpcao=='A') {
    Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('D',sISBN,""));

    nQtd = slAssuntos.col.no();
    for (nCont=0; nCont < nQtd; nCont++)  {
      Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('I',
        sISBN, slAssuntos.col[nCont]));
    }
  } else if (sOpcao=='B') {
  	Rotinas->AtualizaDados(gConexao,ConsSQL->LivroAut('D',sISBN,""));

    nQtd = slAutores.col.no();
    for (nCont=0; nCont < nQtd; nCont++)  {
      Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAut('I',
        sISBN, slAutores.col[nCont]));
    }
  }
}

long CfrmCadLivros::onEdtCodigo_Killfocus(FXObject*,FXSelector,void*) {
  if (edtCodigo->getText().length() > 0) {
	  if (Rotinas->validaISBN(edtCodigo->getText())==false) {
      edtCodigo->setText("");
		  edtCodigo->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_ISBNINV);
	  }
  }
  return true;
}

long CfrmCadLivros::onEdtCodEditora_Killfocus(FXObject*,FXSelector,void*) {
  FXString sEditora;
  LISTAMSTR ConsCampo;

  if (edtCodEditora->getText().length() > 0) {
    sEditora = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Editora('S',
      edtCodEditora->getText(),""),STR_EDTNENC);
    if (sEditora.length() > 0) {
      edtEditora->setText(sEditora);
    } else {
      edtCodEditora->setText("");
      edtEditora->setText("");
      edtCodEditora->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_EDTNENC);
    }
  } else {
    edtEditora->setText("");
  }
  return true;
}

long CfrmCadLivros::onEdtCodAssunto_Killfocus(FXObject*,FXSelector,void*) {
  FXString sAssunto;
  LISTAMSTR ConsCampo;

  if (edtCodAssunto->getText().length() > 0) {
    sAssunto = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Assunto('S',
      edtCodAssunto->getText(),""),STR_ASSNENC);

    if (sAssunto.length() > 0) {
      edtAssunto->setText(sAssunto);
    } else {
      edtCodAssunto->setText("");
      edtAssunto->setText("");
      edtCodAssunto->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_ASSNENC);
    }
  } else {
    edtAssunto->setText("");
  }
  return true;
}

long CfrmCadLivros::onEdtCodAutor_Killfocus(FXObject*,FXSelector,void*) {
  FXString sAutor;
  LISTAMSTR ConsCampo;

  if (edtCodAutor->getText().length() > 0) {
    sAutor = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Autor('S',
      edtCodAutor->getText(),""),STR_AUTNENC);

    if (sAutor.length() > 0) {
      edtAutor->setText(sAutor);
    } else {
      edtCodAutor->setText("");
      edtAutor->setText("");
      edtCodAutor->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_AUTNENC);
    }
  } else {
    edtAutor->setText("");
  }
  return true;
}

long CfrmCadLivros::onBtnPEditora(FXObject*,FXSelector,void*) {
  CfrmConEditoras *fConEditoras = new CfrmConEditoras(this);
  fConEditoras->execute();
  edtCodEditora->setText(Rotinas_sCodigoSelecionado);
  onEdtCodEditora_Killfocus(NULL,0,NULL);
  return true;
}

long CfrmCadLivros::onBtnPAssunto(FXObject*,FXSelector,void*) {
  CfrmConAssuntos *fConAssuntos = new CfrmConAssuntos(this);
  fConAssuntos->execute();
  edtCodAssunto->setText(Rotinas_sCodigoSelecionado);
  onEdtCodAssunto_Killfocus(edtCodAssunto,0,NULL);
  return true;
}

long CfrmCadLivros::onBtnAdAssuntos(FXObject*,FXSelector,void*) {
  Rotinas->AdicionaItemLista(lstAssuntos,
    &slAssuntos, edtCodAssunto, edtAssunto);
  return true;
}

long CfrmCadLivros::onBtnPAutor(FXObject*,FXSelector,void*) {
  CfrmConAutores *fConAutores = new CfrmConAutores(this);
  fConAutores->execute();
  edtCodAutor->setText(Rotinas_sCodigoSelecionado);
  onEdtCodAutor_Killfocus(edtCodAutor,0,NULL);
  return true;
}

long CfrmCadLivros::onBtnAdAutores(FXObject*,FXSelector,void*) {
  Rotinas->AdicionaItemLista(lstAutores,
    &slAutores, edtCodAutor, edtAutor);
  return true;
}

long CfrmCadLivros::onLstAssuntos_Dblclk(
  FXObject*,FXSelector,void*) {
  Rotinas->RemoveItemLista(lstAssuntos,&slAssuntos);
  return true;
}

long CfrmCadLivros::onLstAutores_Dblclk(
  FXObject*,FXSelector,void*) {
  Rotinas->RemoveItemLista(lstAutores,&slAutores);
  return true;
}

