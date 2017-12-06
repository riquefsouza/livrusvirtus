#include "resource.h"
#include "ConAssuntos.h"
#include "Principal.h"
#include "ConsultasSQL.h"

CfrmConAssuntos *frmConAssuntos = (CfrmConAssuntos *) NULL;

FXDEFMAP(CfrmConAssuntos) CfrmConAssuntosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConAssuntos::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConAssuntos::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConAssuntos::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConAssuntos::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConAssuntos::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConAssuntos::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConAssuntos::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConAssuntos::onGridChanged)
};
FXIMPLEMENT(CfrmConAssuntos,CfrmConsultas,CfrmConAssuntosMap,
  ARRAYNUMBER(CfrmConAssuntosMap))

CfrmConAssuntos::CfrmConAssuntos(FXWindow* owner):
  CfrmConsultas(owner, STR_CONASSUNTO) {
  IniciaControles();
}

void CfrmConAssuntos::IniciaControles() {
  this->labDescricao->setText("Assunto:");
  this->gridConsulta->setColumnText(1, "Assunto");
}

void CfrmConAssuntos::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConAssuntos::~CfrmConAssuntos(){  
}

long CfrmConAssuntos::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Assunto('S',"", edtDescricao->getText()), STR_ASSNENC, 2);
  return true;
}

long CfrmConAssuntos::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConAssuntos::onGridSelected(FXObject*,FXSelector,void* ptr) {
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConAssuntos::onGridChanged(FXObject*,FXSelector,void* ptr) {
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
