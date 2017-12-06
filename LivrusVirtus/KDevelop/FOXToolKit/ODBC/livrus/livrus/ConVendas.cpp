#include "resource.h"
#include "Cadastros.h"
#include "ConVendas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

CfrmConVendas *frmConVendas = (CfrmConVendas *) NULL;

FXDEFMAP(CfrmConVendas) CfrmConVendasMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConVendas::ID_FRMCONVENDAS_BTNPESQUISAR, 
    CfrmConVendas::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConVendas::ID_FRMCONVENDAS_BTNLIMPAR, 
    CfrmConVendas::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmConVendas::ID_FRMCONVENDAS_BTNFECHAR, 
    CfrmConVendas::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmConVendas::onClose),
  FXMAPFUNC(SEL_COMMAND, CfrmConVendas::ID_FRMCONVENDAS_BTNPCLIENTE, 
    CfrmConVendas::onBtnPCliente),
  FXMAPFUNC(SEL_COMMAND, CfrmConVendas::ID_FRMCONVENDAS_BTNPLIVRO, 
    CfrmConVendas::onBtnPLivro),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmConVendas::ID_FRMCONVENDAS_EDTDTHRVENDA, 
    CfrmConVendas::onEdtDtHrVenda_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmConVendas::ID_FRMCONVENDAS_EDTISBN, 
    CfrmConVendas::onEdtISBN_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmConVendas::ID_FRMCONVENDAS_EDTCPF, 
    CfrmConVendas::onEdtCPF_Killfocus),
  FXMAPFUNC(SEL_SELECTED,CfrmConVendas::ID_FRMCONVENDAS_GRIDVENDAS,
    CfrmConVendas::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConVendas::ID_FRMCONVENDAS_GRIDVENDAS,
    CfrmConVendas::onGridChanged)
};
FXIMPLEMENT(CfrmConVendas,CfrmCadastros,CfrmConVendasMap,
  ARRAYNUMBER(CfrmConVendasMap))

CfrmConVendas::CfrmConVendas(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CONVENLIVRO, 
  iconeMDI, menuMDI, TEXTFIELD_NORMAL, false) {
  IniciaControles();
}

void CfrmConVendas::IniciaControles() {
  this->resize(500, 370);
  CfrmCadastros::labCodigo->hide();
  CfrmCadastros::edtCodigo->hide();
  CfrmCadastros::labDescricao->hide();
  CfrmCadastros::edtDescricao->hide();
  this->btnNovo->hide();

  frame10 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame11 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame12 = new FXVerticalFrame(frame10, LAYOUT_LEFT|LAYOUT_BOTTOM, 
    0,0,0,0,0,0,0,0);

  frame13 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame14 = new FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame15 = new FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame16 = new FXVerticalFrame(frame13, LAYOUT_LEFT|LAYOUT_BOTTOM, 
    0,0,0,0,0,0,0,0);

  frame17 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame18 = new FXVerticalFrame(frame17, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame19 = new FXVerticalFrame(frame17, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame20 = new FXHorizontalFrame(frame17, LAYOUT_LEFT|LAYOUT_BOTTOM, 
    0,0,0,0,0,0,0,0);

  frame21 = new FXVerticalFrame(frame, LAYOUT_LEFT|LAYOUT_FILL_X|
    LAYOUT_FILL_Y, 0,0,0,0,0,0,0,0);

  frame22 = new FXHorizontalFrame(frame, LAYOUT_FILL_X, 0,0,0,0,0,0,0,0);
  frame23 = new FXHorizontalFrame(frame22, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame24 = new FXHorizontalFrame(frame22, LAYOUT_RIGHT, 0,0,0,0,0,0,0,0);

  frame25 = new FXHorizontalFrame(frame, LAYOUT_BOTTOM|LAYOUT_RIGHT);

  this->labDtHrVenda = new FXLabel(frame11, "Data/Hora Venda:", NULL, LAYOUT_LEFT, 
    8, 8, 91, 13);
  this->edtDtHrVenda = new FXTextField(frame11, 19, NULL, 
    ID_FRMCONVENDAS_EDTDTHRVENDA, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 24, 128, 21, 3, 20);

  this->btnPesquisar = new FXButton(frame12, "&Pesquisar", NULL, this, 
    ID_FRMCONVENDAS_BTNPESQUISAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_RIGHT, 144, 22, 75, 25, 15, 15, 3, 3 );

  this->labCPF = new FXLabel(frame14, "CPF:", NULL, LAYOUT_LEFT, 
    8, 48, 48, 13);
  this->edtCPF = new FXTextField(frame14, 14, this, 
    ID_FRMCONVENDAS_EDTCPF, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 64, 128, 21, 3, 20);

  this->labCliente = new FXLabel(frame15, "Cliente:", NULL, LAYOUT_LEFT, 
    142, 48, 56, 13);
  CfrmCadastros::edtDescricao->hide();
  this->edtCliente = new FXTextField(frame15, 30, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    142, 64, 306, 21, 3, 20);
  this->edtCliente->disable();
  this->btnPCliente = new FXButton(frame16, "...", NULL, this, 
    ID_FRMCONVENDAS_BTNPCLIENTE, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 448, 64, 21, 21, 10, 10, 3, 3 );

  this->labISBN = new FXLabel(frame18, "ISBN:", NULL, LAYOUT_LEFT, 
    8, 88, 48, 13);
  this->edtISBN = new FXTextField(frame18, 13, this, 
    ID_FRMCONVENDAS_EDTISBN, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 104, 128, 21, 3, 20);

  this->labLivro = new FXLabel(frame19, "Livro:", NULL, LAYOUT_LEFT, 
    142, 88, 40, 13);
  this->edtLivro = new FXTextField(frame19, 30, this, 0,
    TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 142, 104, 306, 21, 3, 20);
  this->edtLivro->disable();
  this->btnPLivro = new FXButton(frame20, "...", NULL, this, 
    ID_FRMCONVENDAS_BTNPLIVRO, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 448, 104, 21, 21, 10, 10, 3, 3 );

  this->gridVendas = new FXTable(frame21, this, ID_FRMCONVENDAS_GRIDVENDAS, 
    TABLE_COL_SIZABLE|LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 136, 355, 122);
  this->gridVendas->setTableSize(1, 6);

  this->labRegistro = new FXLabel(frame23, "Registro 0 de 0", NULL, LAYOUT_LEFT, 
    8, 16, 144, 13);
  this->labPrecoTotal = new FXLabel(frame24, "Preço Total:", NULL, LAYOUT_LEFT, 
    280, 248, 61, 13);
  this->edtPrecoTotal = new FXTextField(frame24, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    344, 246, 127, 21, 3, 20);
  this->edtPrecoTotal->disable();

  this->btnFechar = new FXButton(frame25, "&Fechar", NULL, this, 
    ID_FRMCONVENDAS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_RIGHT, 75, 13, 75, 25, 15, 15, 3, 3 );
  this->btnLimpar = new FXButton(frame25, "&Limpar", NULL, this, 
    ID_FRMCONVENDAS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_RIGHT, 16, 13, 75, 25, 15, 15, 3, 3 );


  FXint nLargura[] = { 120, 100, 220, 100, 280, 80 };

  FXString sRotulos[] = { "Data/Hora Venda", "CPF", "Cliente", 
   "ISBN", "Livro", "Preço" };

  Rotinas->AdicionaColunasGrid(gridVendas, 0, 6, nLargura, sRotulos);
  edtPrecoTotal->setText("R$ 0,00");
  edtDtHrVenda->setText(Rotinas->retDataHoraStr(true,true));
  edtDtHrVenda->setFocus();
}

CfrmConVendas::~CfrmConVendas(){
  frmPrincipal->mnuVendasRealizadas->enable();  
}

FXString CfrmConVendas::ConsVenda(FXchar sOpcao)
{
  FXString sISBN, sCPF, sDataHora;
  FXString sret = "";

  if (edtDtHrVenda->getText().length() > 0)
    sDataHora = Rotinas->ConverteDataHoraStr(edtDtHrVenda->getText(), 
      true, "%m/%d/%Y","%H:%M:%S");
  else
    sDataHora = "";

  sISBN = edtISBN->getText();
  sCPF = edtCPF->getText();

  if (sOpcao=='L')
    sret = ConsSQL->Venda('S',"ZERO","","","","");
  else
    sret = ConsSQL->Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");

 return sret;
}

long CfrmConVendas::onClose(FXObject*,FXSelector,void*) {  
  this->destroy();
  return true;
}

long CfrmConVendas::onBtnPesquisar(FXObject*,FXSelector,void*) {
  LISTAMSTR ConsTotal;  
  FXString sPrecoTotal;
  FXdouble nTemp;

  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinhas, ConsVenda('S'))) {
    Rotinas->AdicionaLinhasGrid(gridVendas, lstLinhas, 6);
    setLabRegistros(0);
    if (Rotinas->ConsultaDadosLista(gConexao, &ConsTotal, ConsVenda('P'))) {
      if (ConsTotal.col[0].no() > 0) {
        nTemp = FXDoubleVal(ConsTotal.col[0][0]);
        sPrecoTotal = FXStringFormat("R$ %.2f", nTemp); 
        edtPrecoTotal->setText(sPrecoTotal);
      }
    }

  } else {
     FXMessageBox::error(this, MBOX_OK, "Erro", STR_VENNENC);
  }
  return true;
}

long CfrmConVendas::onBtnLimpar(FXObject*,FXSelector,void*) {
FXint nCol;

  edtCPF->setText("");
  edtCliente->setText("");
  edtISBN->setText("");
  edtLivro->setText("");
  if (gridVendas->getNumRows() > 0) {
    gridVendas->removeRows(0, gridVendas->getNumRows()-1);
    gridVendas->setRowText(0,"");
    for (nCol = 0; nCol < gridVendas->getNumColumns(); nCol++)
      gridVendas->setItemText(0, nCol, "");    
  }
  edtPrecoTotal->setText("R$ 0,00");
  edtDtHrVenda->setText(Rotinas->retDataHoraStr(true,true));
  edtDtHrVenda->setFocus();
  return true;
}

long CfrmConVendas::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}

long CfrmConVendas::onEdtCPF_Killfocus(FXObject*,FXSelector,void*) {
  FXString sCliente;
  LISTAMSTR ConsCampo;

  if (edtCPF->getText().length() > 0) {
    if (Rotinas->validaCPF(edtCPF->getText())) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      edtCPF->getText(),"","","","","","","","",""),STR_CLINENC); 
      if (sCliente.length()==0) {
        edtCPF->setText("");
        edtCPF->killFocus();
        FXMessageBox::error(this, MBOX_OK, "Erro", STR_CLINENC);
      } else
         edtCliente->setText(sCliente);
    } else {
      edtCPF->setText("");
      edtCPF->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_CPFINV);
    }
  } else
     edtCliente->setText("");
  return true;
}

long CfrmConVendas::onEdtISBN_Killfocus(FXObject*,FXSelector,void*) {
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

long CfrmConVendas::onBtnPCliente(FXObject*,FXSelector,void*) {
  CfrmConClientes *fConClientes = new CfrmConClientes(this);
  fConClientes->execute();
  edtCPF->setText(Rotinas_sCodigoSelecionado);
  onEdtCPF_Killfocus(NULL,0,NULL);
  return true;
}

long CfrmConVendas::onBtnPLivro(FXObject*,FXSelector,void*) {
  CfrmConLivros *fConLivros = new CfrmConLivros(this);
  fConLivros->execute();
  edtISBN->setText(Rotinas_sCodigoSelecionado);
  onEdtISBN_Killfocus(NULL,0,NULL);
  return true;
}

void CfrmConVendas::setLabRegistros(FXint nLinha) {
  if (nLinha >= 0) {
    labRegistro->setText(FXStringFormat("Registro %d de %d", nLinha+1, 
      gridVendas->getNumRows()));
  }
}

long CfrmConVendas::onGridSelected(FXObject*,FXSelector,void* ptr) {
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConVendas::onGridChanged(FXObject*,FXSelector,void* ptr) {
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}

long CfrmConVendas::onEdtDtHrVenda_Killfocus(FXObject*,FXSelector,void*) {
  if (edtDtHrVenda->getText().length() > 0) {
    if (!Rotinas->validaDataHora(edtDtHrVenda->getText(), false)) {
  		edtDtHrVenda->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_DTHRINV);
    }
  } 
  return true;
}

