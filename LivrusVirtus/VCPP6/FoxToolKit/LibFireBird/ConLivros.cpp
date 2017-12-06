#include "resource.h"
#include "ConLivros.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmConLivros *frmConLivros = (CfrmConLivros *) NULL;

FXDEFMAP(CfrmConLivros) CfrmConLivrosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConLivros::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConLivros::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConLivros::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConLivros::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConLivros::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConLivros::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConLivros::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConLivros::onGridChanged)
};
FXIMPLEMENT(CfrmConLivros,CfrmConsultas,CfrmConLivrosMap,
  ARRAYNUMBER(CfrmConLivrosMap))

CfrmConLivros::CfrmConLivros(FXWindow* owner):
  CfrmConsultas(owner, STR_CONLIVRO) {
  IniciaControles();
}

void CfrmConLivros::IniciaControles() {
  this->labDescricao->setText("Livro:");
  this->gridConsulta->setColumnText(0, "ISBN");
  this->gridConsulta->setColumnWidth(0, 80);
  this->gridConsulta->setColumnText(1, "Título");
  this->gridConsulta->setColumnWidth(1, 180);

  int nLargura[] = { 80,90,80,80,100,80,100,80,80,80 };
  FXString sRotulos[] = { "Edição", "AnoPublicação", "Volume",
    "CodEditora", "Editora", "CodIdioma", "Idioma",
    "NumPáginas", "Preço", "Estoque" };
  Rotinas->AdicionaColunasGrid(gridConsulta, 2, 10, nLargura, sRotulos);
}

void CfrmConLivros::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConLivros::~CfrmConLivros(){  
}

long CfrmConLivros::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Livro('S',"", edtDescricao->getText()
    ,"","","","","","","",""), STR_LIVNENC, 12);
  return true;
}

long CfrmConLivros::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConLivros::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConLivros::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
