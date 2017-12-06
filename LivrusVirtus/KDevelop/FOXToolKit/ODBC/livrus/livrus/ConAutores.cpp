#include "resource.h"
#include "ConAutores.h"
#include "Principal.h"
#include "ConsultasSQL.h"

CfrmConAutores *frmConAutores = (CfrmConAutores *) NULL;

FXDEFMAP(CfrmConAutores) CfrmConAutoresMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConAutores::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConAutores::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConAutores::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConAutores::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConAutores::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConAutores::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConAutores::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConAutores::onGridChanged)
};
FXIMPLEMENT(CfrmConAutores,CfrmConsultas,CfrmConAutoresMap,
  ARRAYNUMBER(CfrmConAutoresMap))

CfrmConAutores::CfrmConAutores(FXWindow* owner):
  CfrmConsultas(owner, STR_CONAUTOR) {
  IniciaControles();
}

void CfrmConAutores::IniciaControles() {
  this->labDescricao->setText("Autor:");
  this->gridConsulta->setColumnText(1, "Autor");
}

void CfrmConAutores::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConAutores::~CfrmConAutores(){  
}

long CfrmConAutores::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Autor('S',"", edtDescricao->getText()), STR_AUTNENC, 2);
  return true;
}

long CfrmConAutores::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConAutores::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConAutores::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
