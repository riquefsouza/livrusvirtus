#include "resource.h"
#include "Cadastros.h"
#include "VenderLivros.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

CfrmVenderLivros *frmVenderLivros = (CfrmVenderLivros *) NULL;

FXDEFMAP(CfrmVenderLivros) CfrmVenderLivrosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmVenderLivros::ID_FRMVENDERLIVROS_BTNVENDER, 
    CfrmVenderLivros::onBtnVender),
  FXMAPFUNC(SEL_COMMAND, CfrmVenderLivros::ID_FRMVENDERLIVROS_BTNLIMPAR, 
    CfrmVenderLivros::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmVenderLivros::ID_FRMVENDERLIVROS_BTNFECHAR, 
    CfrmVenderLivros::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmVenderLivros::onClose),
  FXMAPFUNC(SEL_COMMAND, CfrmVenderLivros::ID_FRMVENDERLIVROS_BTNPCLIENTE, 
    CfrmVenderLivros::onBtnPCliente),
  FXMAPFUNC(SEL_COMMAND, CfrmVenderLivros::ID_FRMVENDERLIVROS_BTNPLIVRO, 
    CfrmVenderLivros::onBtnPLivro),
  FXMAPFUNC(SEL_COMMAND, CfrmVenderLivros::ID_FRMVENDERLIVROS_BTNADLIVROS, 
    CfrmVenderLivros::onBtnAdLivros),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmVenderLivros::ID_FRMCADASTROS_EDTCODIGO, 
    CfrmVenderLivros::onEdtCodigo_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmVenderLivros::ID_FRMVENDERLIVROS_EDTISBN, 
    CfrmVenderLivros::onEdtISBN_Killfocus),
  FXMAPFUNC(SEL_DOUBLECLICKED, CfrmVenderLivros::ID_FRMVENDERLIVROS_LSTLIVROS, 
    CfrmVenderLivros::onLstLivros_Dblclk)
};
FXIMPLEMENT(CfrmVenderLivros,CfrmCadastros,CfrmVenderLivrosMap,
  ARRAYNUMBER(CfrmVenderLivrosMap))

CfrmVenderLivros::CfrmVenderLivros(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_VENLIVRO, 
  iconeMDI, menuMDI, TEXTFIELD_NORMAL, false) {
  IniciaControles();
}

void CfrmVenderLivros::IniciaControles() {
  this->resize(500, 370);
  this->btnNovo->hide();

  frame10 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame11 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame12 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame13 = new FXVerticalFrame(frame12, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame14 = new FXVerticalFrame(frame12, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame15 = new FXVerticalFrame(frame12, LAYOUT_LEFT|LAYOUT_BOTTOM, 
    0,0,0,0,0,0,0,0);

  frame16 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame17 = new FXVerticalFrame(frame16, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame18 = new FXVerticalFrame(frame16, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame19 = new FXHorizontalFrame(frame16, LAYOUT_LEFT|LAYOUT_BOTTOM, 
    0,0,0,0,0,0,0,0);

  frame20 = new FXVerticalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame21 = new FXHorizontalFrame(frame20, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame22 = new FXHorizontalFrame(frame20, LAYOUT_LEFT|FRAME_THICK|
    FRAME_SUNKEN, 0,0,0,0,0,0,0,0);

  frame23 = new FXHorizontalFrame(frame3, LAYOUT_RIGHT, 0,0,0,0,0,0,0,0);

  frame24 = new FXHorizontalFrame(frame3, LAYOUT_BOTTOM|LAYOUT_RIGHT);

  this->labDtHrVenda = new FXLabel(frame11, "Data/Hora Venda:", NULL, LAYOUT_LEFT, 
    8, 8, 91, 13);
  this->edtDtHrVenda = new FXTextField(frame11, 30, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 24, 128, 21, 3, 20);
  this->edtDtHrVenda->disable();

  CfrmCadastros::labCodigo->hide();
  this->labCodigo = new FXLabel(frame13, "CPF:", NULL, LAYOUT_LEFT, 
    8, 48, 48, 13);
  CfrmCadastros::edtCodigo->hide();
  this->edtCodigo = new FXTextField(frame13, 14, this, 
    ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 64, 128, 21, 3, 20);

  CfrmCadastros::labDescricao->hide();
  this->labDescricao = new FXLabel(frame14, "Cliente:", NULL, LAYOUT_LEFT, 
    142, 48, 56, 13);
  CfrmCadastros::edtDescricao->hide();
  this->edtDescricao = new FXTextField(frame14, 30, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    142, 64, 306, 21, 3, 20);
  this->edtDescricao->disable();

  this->btnPCliente = new FXButton(frame15, "...", NULL, this, 
    ID_FRMVENDERLIVROS_BTNPCLIENTE, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 448, 64, 21, 21, 10, 10, 3, 3 );

  this->labISBN = new FXLabel(frame17, "ISBN:", NULL, LAYOUT_LEFT, 
    8, 88, 48, 13);
  this->edtISBN = new FXTextField(frame17, 13, this, 
    ID_FRMVENDERLIVROS_EDTISBN, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 104, 128, 21, 3, 20);

  this->labLivro = new FXLabel(frame18, "Livro:", NULL, LAYOUT_LEFT, 
    142, 88, 40, 13);
  this->edtLivro = new FXTextField(frame18, 30, this, 0,
    TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 142, 104, 282, 21, 3, 20);
  this->edtLivro->disable();

  this->btnAdLivros = new FXButton(frame19, "+", NULL, this, 
    ID_FRMVENDERLIVROS_BTNADLIVROS, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 424, 104, 21, 21, 10, 10, 3, 3 );
  this->btnPLivro = new FXButton(frame19, "...", NULL, this, 
    ID_FRMVENDERLIVROS_BTNPLIVRO, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 448, 104, 21, 21, 10, 10, 3, 3 );

  this->labLivros = new FXLabel(frame21, "Livros para vender:", NULL, 
    LAYOUT_LEFT, 8, 128, 120, 13);
  lstLivros = new FXList(frame22, this, ID_FRMVENDERLIVROS_LSTLIVROS, 
    LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 144, 464, 96);

  this->labPrecoTotal = new FXLabel(frame23, "Preço Total:", NULL, 
    LAYOUT_LEFT, 280, 248, 61, 13);
  this->edtPrecoTotal = new FXTextField(frame23, 30, 0, 0,
    TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 344, 246, 127, 21, 3, 20);
  this->edtPrecoTotal->disable();

  this->btnVender = new FXButton(frame24, "&Vender", NULL, this, 
    ID_FRMVENDERLIVROS_BTNVENDER, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 239, 275, 75, 25, 15, 15, 3, 3 );
  this->btnLimpar = new FXButton(frame24, "&Limpar", NULL, this, 
    ID_FRMVENDERLIVROS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 319, 275, 75, 25, 15, 15, 3, 3 );
  this->btnFechar = new FXButton(frame24, "&Fechar", NULL, this, 
    ID_FRMVENDERLIVROS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 399, 275, 75, 25, 15, 15, 3, 3 );

  this->edtDtHrVenda->setText(Rotinas->retDataHoraStr(true, true));   
  nPrecoTotal = 0;
}

CfrmVenderLivros::~CfrmVenderLivros(){
  frmPrincipal->tlbVenda->enable();
  frmPrincipal->mnuVenderLivros->enable();  
}

void CfrmVenderLivros::LimpaDados() {
  edtDtHrVenda->setText(Rotinas->retDataHoraStr(true, true));  
  edtCodigo->setText("");
  edtDescricao->setText("");
  edtISBN->setText("");
  edtLivro->setText("");
  lstLivros->clearItems();
  nPrecoTotal = 0;
  edtPrecoTotal->setText("R$ 0,00");
  edtCodigo->setFocus();
}

FXbool CfrmVenderLivros::ValidaDados()
{
  if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CPFNINF))
    return false;
  if (lstLivros->getNumItems()==0) {
    FXMessageBox::error(this, MBOX_OK, "Erro", STR_LIVVENNINF);
    return false;
  }
return true;
}

FXbool CfrmVenderLivros::SalvaLista() {
  FXString sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR;
  FXint nCont, nQtd, nQtdEstoque;

  nQtd = lstLivros->getNumItems();
  sCPF = edtCodigo->getText();
  sPrecoTotal = FXStringFormat("%.2f",nPrecoTotal);
  
  sDTHR = edtDtHrVenda->getText();
  sDataHora = Rotinas->ConverteDataHoraStr(sDTHR, true, 
    "%m/%d/%Y","%H:%M:%S");
  
  for (nCont=0; nCont < nQtd; nCont++) {
    sISBN = slISBNs.col[nCont];
  
    Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('I',sISBN, sCPF, 
      sDataHora,Rotinas->VirgulaParaPonto(sPrecoTotal,false),""));
  
    nQtdEstoque = FXIntVal(slQtdEstoque.col[nCont]);
    if (nQtdEstoque >= 0) nQtdEstoque--;
    sQtdEstoque = FXStringFormat("%d", nQtdEstoque);
    Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('U',sISBN, 
      "","","", sQtdEstoque));
  }
return true;
}

long CfrmVenderLivros::onClose(FXObject*,FXSelector,void*) {  
  this->destroy();
  return true;
}

long CfrmVenderLivros::onBtnVender(FXObject*,FXSelector,void*) {
  if (ValidaDados()) {
    if (SalvaLista()) {
      FXMessageBox::information(this, MBOX_OK, STR_TITULO, STR_VENRESUC);
      LimpaDados();
    }
  }	
  return true;
}

long CfrmVenderLivros::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimpaDados();
  return true;
}

long CfrmVenderLivros::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}

long CfrmVenderLivros::onEdtCodigo_Killfocus(FXObject*,
                                             FXSelector,void*) {
  FXString sCliente;
  LISTAMSTR ConsCampo;

  if (edtCodigo->getText().length() > 0) {
    if (Rotinas->validaCPF(edtCodigo->getText())) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      edtCodigo->getText(),"","","","","","","","",""),STR_CLINENC); 
      if (sCliente.length()==0) {
        edtCodigo->setText("");
        edtCodigo->killFocus();
        FXMessageBox::error(this, MBOX_OK, "Erro", STR_CLINENC);
      } else
         edtDescricao->setText(sCliente);
    } else {
      edtCodigo->setText("");
      edtCodigo->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_CPFINV);
    }
  } else
     edtDescricao->setText("");
  return true;
}

long CfrmVenderLivros::onEdtISBN_Killfocus(FXObject*,
                                           FXSelector,void*) {
  FXString sLivro;
  FXint nQtdEstoque;
  LISTAMSTR ConsCampo;

  if (edtISBN->getText().length() > 0) {
    if (Rotinas->validaISBN(edtISBN->getText())) {      
      sLivro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Livro('Q',
      edtISBN->getText(),"","","","","","","","",""),STR_LIVNENC);
      if (sLivro.length()==0) {
        edtISBN->setText("");
      	edtISBN->killFocus();
        FXMessageBox::error(this, MBOX_OK, "Erro", STR_LIVNENC);
      } else {
         edtLivro->setText(sLivro);
         nQtdEstoque = FXIntVal(ConsCampo.col[3][0]);
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = ConsCampo.col[2][0];
           Rotinas_sQtdEstoque = ConsCampo.col[3][0];
         } else
           FXMessageBox::error(this, MBOX_OK, "Erro", STR_LIVNEST);
      }
    } else {
      edtISBN->setText("");
      edtISBN->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_ISBNINV);
    }
  } else
     edtLivro->setText("");
  return true;
}

long CfrmVenderLivros::onBtnPCliente(FXObject*,FXSelector,void*) {
  CfrmConClientes *fConClientes = new CfrmConClientes(this);
  fConClientes->execute();
  edtCodigo->setText(Rotinas_sCodigoSelecionado);
  onEdtCodigo_Killfocus(NULL,0,NULL);
  return true;
}

long CfrmVenderLivros::onBtnPLivro(FXObject*,FXSelector,void*) {
  CfrmConLivros *fConLivros = new CfrmConLivros(this);
  fConLivros->execute();
  edtISBN->setText(Rotinas_sCodigoSelecionado);
  onEdtISBN_Killfocus(NULL,0,NULL);
  return true;
}

long CfrmVenderLivros::onBtnAdLivros(FXObject*,FXSelector,void*) {
  FXdouble nPreco; 
  FXString sLivros, sISBN, sEdtLivro, sPrecoTotal;

 sISBN = edtISBN->getText();
 sEdtLivro = edtLivro->getText();
 if (sISBN.length() > 0) {
   sLivros = FXStringFormat("%s - %s - R$ %s", 
     sISBN.text(), sEdtLivro.text(), Rotinas_sPreco.text());
   if (lstLivros->findItem(sLivros)==-1) {
     slISBNs.col.append(sISBN);
     slPrecos.col.append(Rotinas_sPreco);
     slQtdEstoque.col.append(Rotinas_sQtdEstoque);
     lstLivros->appendItem(sLivros);
     nPreco = FXDoubleVal(Rotinas_sPreco);
     nPrecoTotal = nPrecoTotal + nPreco;
   }
   edtISBN->setText("");
   edtLivro->setText("");
   sPrecoTotal = FXStringFormat("R$ %.2f", nPrecoTotal);
   edtPrecoTotal->setText(Rotinas->VirgulaParaPonto(sPrecoTotal,true));
 }
  return true;
}

long CfrmVenderLivros::onLstLivros_Dblclk(FXObject*,
                                          FXSelector,void*) {
  FXString sPrecoTotal;
  FXdouble nPreco;
  FXint nSelIndice;

  if (lstLivros->getNumItems() > 0) {   
    nSelIndice = lstLivros->getCurrentItem();   
    if (lstLivros->isItemCurrent(nSelIndice)) {
      nPreco = FXDoubleVal(slPrecos.col[nSelIndice]);
      nPrecoTotal = nPrecoTotal-nPreco;
      if (nPrecoTotal < 0) nPrecoTotal = nPrecoTotal * (-1.0);
      sPrecoTotal = FXStringFormat("R$ %.2f",nPrecoTotal);
      edtPrecoTotal->setText(Rotinas->VirgulaParaPonto(sPrecoTotal,true));
      slISBNs.col.remove(nSelIndice);
      slPrecos.col.remove(nSelIndice);
      slQtdEstoque.col.remove(nSelIndice);
      lstLivros->removeItem(nSelIndice);
    }	
  }
  return true;
}

