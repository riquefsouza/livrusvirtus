#include "resource.h"
#include "ConProfissoes.h"
#include "Principal.h"
#include "ConsultasSQL.h"

CfrmConProfissoes *frmConProfissoes = (CfrmConProfissoes *) NULL;

FXDEFMAP(CfrmConProfissoes) CfrmConProfissoesMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConProfissoes::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConProfissoes::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConProfissoes::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConProfissoes::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConProfissoes::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConProfissoes::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConProfissoes::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConProfissoes::onGridChanged)
};
FXIMPLEMENT(CfrmConProfissoes,CfrmConsultas,CfrmConProfissoesMap,
  ARRAYNUMBER(CfrmConProfissoesMap))

CfrmConProfissoes::CfrmConProfissoes(FXWindow* owner):
  CfrmConsultas(owner, STR_CONPROFISS) {
  IniciaControles();
}

void CfrmConProfissoes::IniciaControles() {
  this->labDescricao->setText("Profissão:");
  this->gridConsulta->setColumnText(1, "Profissão");
}

void CfrmConProfissoes::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConProfissoes::~CfrmConProfissoes(){  
}

long CfrmConProfissoes::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Profissao('S',"", edtDescricao->getText()), STR_PROFNENC, 2);
  return true;
}

long CfrmConProfissoes::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConProfissoes::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConProfissoes::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
