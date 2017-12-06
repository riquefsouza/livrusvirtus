#include "resource.h"
#include "ConPaises.h"
#include "Principal.h"
#include "ConsultasSQL.h"

CfrmConPaises *frmConPaises = (CfrmConPaises *) NULL;

FXDEFMAP(CfrmConPaises) CfrmConPaisesMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConPaises::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConPaises::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConPaises::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConPaises::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConPaises::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConPaises::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConPaises::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConPaises::onGridChanged)
};
FXIMPLEMENT(CfrmConPaises,CfrmConsultas,CfrmConPaisesMap,
  ARRAYNUMBER(CfrmConPaisesMap))

CfrmConPaises::CfrmConPaises(FXWindow* owner):
  CfrmConsultas(owner, STR_CONPAIS) {
  IniciaControles();
}

void CfrmConPaises::IniciaControles() {
  this->labDescricao->setText("País:");
  this->gridConsulta->setColumnText(1, "País");
}

void CfrmConPaises::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConPaises::~CfrmConPaises(){  
}

long CfrmConPaises::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Pais('S',"", edtDescricao->getText()), STR_PAISNENC, 2);
  return true;
}

long CfrmConPaises::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConPaises::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConPaises::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
