#include "resource.h"
#include "Consultas.h"
#include "Principal.h"

FXIMPLEMENT(CfrmConsultas,FXDialogBox,NULL,0)

CfrmConsultas::CfrmConsultas(FXWindow* owner, FXString sTitulo):
  FXDialogBox(owner, sTitulo, DECOR_ALL, 
    0, 0, 385, 263, 0, 0, 0, 0, 4, 4){
  IniciaControles();
}

void CfrmConsultas::IniciaControles() {
  this->setIcon(new FXBMPIcon(getApp(),Livrus));

  frame = new FXVerticalFrame(this, LAYOUT_FILL_X | LAYOUT_FILL_Y);
  frame1 = new FXVerticalFrame(frame, LAYOUT_FILL_X);
  frame2 = new FXHorizontalFrame(frame1, LAYOUT_TOP);
  
  frame3 = new FXVerticalFrame(frame2, LAYOUT_LEFT);
  frame3->setPadTop(0);
  frame3->setPadBottom(0);

  frame4 = new FXVerticalFrame(frame2, LAYOUT_LEFT|LAYOUT_BOTTOM);
  frame4->setPadTop(0);
  frame4->setPadBottom(0);

  frameBotoesH = new FXHorizontalFrame(frame, LAYOUT_BOTTOM|LAYOUT_FILL_X);

  this->labDescricao = new FXLabel(frame3, "Descrição:", NULL, LAYOUT_LEFT, 
    8, 8, 51, 13);
  this->edtDescricao = new FXTextField(frame3, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 24, 257, 21, 3, 20);
  this->btnPesquisar = new FXButton(frame4, "&Pesquisar", NULL, this, 
    ID_FRMCONSULTAS_BTNPESQUISAR, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    272, 24, 75, 25, 15, 15, 3, 3 );

  this->gridConsulta = new FXTable(frame, this, ID_FRMCONSULTAS_GRIDCONSULTA, 
    TABLE_COL_SIZABLE|LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 56, 355, 125);
  this->gridConsulta->setTableSize(1, 2);
  this->gridConsulta->setColumnText(0, "Código");
  this->gridConsulta->setColumnWidth(0, 80);
  this->gridConsulta->setColumnText(1, "Descrição");
  this->gridConsulta->setColumnWidth(1, 180);

  this->labRegistro = new FXLabel(frameBotoesH, "Registro 0 de 0", NULL, LAYOUT_LEFT, 
    8, 16, 144, 13);
  this->btnFechar = new FXButton(frameBotoesH, "&Fechar", NULL, this, 
    FXDialogBox::ID_CANCEL, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_RIGHT, 75, 13, 75, 25, 15, 15, 3, 3 );
  this->btnLimpar = new FXButton(frameBotoesH, "&Limpar", NULL, this, 
    ID_FRMCONSULTAS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_RIGHT, 16, 13, 75, 25, 15, 15, 3, 3 );

  this->edtDescricao->setFocus();
  nRegistro = 0;
  Rotinas_sCodigoSelecionado = "";
}

void CfrmConsultas::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConsultas::~CfrmConsultas(){
}

void CfrmConsultas::LimparDados() {
FXint nCol;

  Rotinas_sCodigoSelecionado = "";
  labRegistro->setText("Registro 0 de 0");
  if (gridConsulta->getNumRows() > 0) {
    gridConsulta->removeRows(0, gridConsulta->getNumRows()-1);
    gridConsulta->setRowText(0,"");
    for (nCol = 0; nCol < gridConsulta->getNumColumns(); nCol++)
      gridConsulta->setItemText(0, nCol, "");    
  }
  edtDescricao->setText("");
  edtDescricao->setFocus();
}

void CfrmConsultas::PesquisarDados(FXString sTextoSql, FXString sMensagemErro, 
    FXint nQtdCol) {

  Rotinas_sCodigoSelecionado = "";
  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinhas, sTextoSql)) {
    Rotinas->AdicionaLinhasGrid(gridConsulta, lstLinhas, nQtdCol);
    setLabRegistros(0);
  } else
    FXMessageBox::error(this, MBOX_OK, "Erro", sMensagemErro.text());
}

void CfrmConsultas::setLabRegistros(FXint nLinha) {
  if (nLinha >= 0) {
    labRegistro->setText(FXStringFormat("Registro %d de %d", nLinha+1, 
      gridConsulta->getNumRows()));
    Rotinas_sCodigoSelecionado = gridConsulta->getItemText(nLinha, 0);
  }
}
