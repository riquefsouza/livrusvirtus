#include "resource.h"
#include "ConEditoras.h"
#include "Principal.h"
#include "ConsultasSQL.h"

CfrmConEditoras *frmConEditoras = (CfrmConEditoras *) NULL;

FXDEFMAP(CfrmConEditoras) CfrmConEditorasMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConEditoras::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConEditoras::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConEditoras::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConEditoras::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConEditoras::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConEditoras::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConEditoras::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConEditoras::onGridChanged)
};
FXIMPLEMENT(CfrmConEditoras,CfrmConsultas,CfrmConEditorasMap,
  ARRAYNUMBER(CfrmConEditorasMap))

CfrmConEditoras::CfrmConEditoras(FXWindow* owner):
  CfrmConsultas(owner, STR_CONEDITORA) {
  IniciaControles();
}

void CfrmConEditoras::IniciaControles() {
  this->labDescricao->setText("Editora:");
  this->gridConsulta->setColumnText(1, "Editora");
}

void CfrmConEditoras::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConEditoras::~CfrmConEditoras(){  
}

long CfrmConEditoras::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Editora('S',"", edtDescricao->getText()), STR_EDTNENC, 2);
  return true;
}

long CfrmConEditoras::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConEditoras::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConEditoras::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
