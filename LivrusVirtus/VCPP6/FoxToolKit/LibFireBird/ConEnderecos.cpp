#include "resource.h"
#include "ConEnderecos.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmConEnderecos *frmConEnderecos = (CfrmConEnderecos *) NULL;

FXDEFMAP(CfrmConEnderecos) CfrmConEnderecosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConEnderecos::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConEnderecos::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConEnderecos::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConEnderecos::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConEnderecos::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConEnderecos::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConEnderecos::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConEnderecos::onGridChanged)
};
FXIMPLEMENT(CfrmConEnderecos,CfrmConsultas,CfrmConEnderecosMap,
  ARRAYNUMBER(CfrmConEnderecosMap))

CfrmConEnderecos::CfrmConEnderecos(FXWindow* owner):
  CfrmConsultas(owner, STR_CONENDERECO) {
  IniciaControles();
}

void CfrmConEnderecos::IniciaControles() {
  this->labDescricao->setText("Endereço:");
  this->gridConsulta->setColumnText(1, "Logradouro");
  this->gridConsulta->setColumnWidth(1, 200);

  int nLargura[] = { 150,80,100,80 };
  FXString sRotulos[] = { "Bairro", "CEP", "Cidade", "Estado" };
  Rotinas->AdicionaColunasGrid(gridConsulta, 2, 4, nLargura, sRotulos);
}

void CfrmConEnderecos::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConEnderecos::~CfrmConEnderecos(){  
}

long CfrmConEnderecos::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Endereco('S',"", edtDescricao->getText(),
    "","","",""), STR_ENDNENC, 6);
  return true;
}

long CfrmConEnderecos::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConEnderecos::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConEnderecos::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
