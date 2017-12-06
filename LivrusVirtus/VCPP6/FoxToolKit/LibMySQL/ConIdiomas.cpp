#include "resource.h"
#include "ConIdiomas.h"
#include "Principal.h"
#include "ConsultasSQL.h"

CfrmConIdiomas *frmConIdiomas = (CfrmConIdiomas *) NULL;

FXDEFMAP(CfrmConIdiomas) CfrmConIdiomasMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConIdiomas::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConIdiomas::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConIdiomas::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConIdiomas::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConIdiomas::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConIdiomas::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConIdiomas::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConIdiomas::onGridChanged)
};
FXIMPLEMENT(CfrmConIdiomas,CfrmConsultas,CfrmConIdiomasMap,
  ARRAYNUMBER(CfrmConIdiomasMap))

CfrmConIdiomas::CfrmConIdiomas(FXWindow* owner):
  CfrmConsultas(owner, STR_CONIDIOMA) {
  IniciaControles();
}

void CfrmConIdiomas::IniciaControles() {
  this->labDescricao->setText("Idioma:");
  this->gridConsulta->setColumnText(1, "Idioma");
}

void CfrmConIdiomas::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConIdiomas::~CfrmConIdiomas(){  
}

long CfrmConIdiomas::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Idioma('S',"", edtDescricao->getText()), STR_IDINENC, 2);
  return true;
}

long CfrmConIdiomas::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConIdiomas::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConIdiomas::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
