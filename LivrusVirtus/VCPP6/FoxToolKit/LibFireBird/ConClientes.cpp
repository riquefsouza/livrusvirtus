#include "resource.h"
#include "ConClientes.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmConClientes *frmConClientes = (CfrmConClientes *) NULL;

FXDEFMAP(CfrmConClientes) CfrmConClientesMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmConClientes::ID_FRMCONSULTAS_BTNPESQUISAR, 
    CfrmConClientes::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmConClientes::ID_FRMCONSULTAS_BTNLIMPAR, 
    CfrmConClientes::onBtnLimpar),
  FXMAPFUNC(SEL_SELECTED,CfrmConClientes::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConClientes::onGridSelected),
  FXMAPFUNC(SEL_CHANGED,CfrmConClientes::ID_FRMCONSULTAS_GRIDCONSULTA,
    CfrmConClientes::onGridChanged)
};
FXIMPLEMENT(CfrmConClientes,CfrmConsultas,CfrmConClientesMap,
  ARRAYNUMBER(CfrmConClientesMap))

CfrmConClientes::CfrmConClientes(FXWindow* owner):
  CfrmConsultas(owner, STR_CONCLIENTE) {
  IniciaControles();
}

void CfrmConClientes::IniciaControles() {
  this->labDescricao->setText("Cliente:");
  this->gridConsulta->setColumnText(0, "CPF");
  this->gridConsulta->setColumnWidth(0, 90);
  this->gridConsulta->setColumnText(1, "Nome");
  this->gridConsulta->setColumnWidth(1, 220);

  int nLargura[] = { 180,80,40,80,120,80,220,150,
          80,100,100,80,180,80,100 };

  FXString sRotulos[] = { "Email", "Identidade", "Sexo", 
   "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
   "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
   "CodProfissão", "Profissão" };

  Rotinas->AdicionaColunasGrid(gridConsulta, 2, 15, nLargura, sRotulos);
}

void CfrmConClientes::create(){
  FXDialogBox::create();
  show(PLACEMENT_SCREEN);
}

CfrmConClientes::~CfrmConClientes(){  
}

long CfrmConClientes::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Cliente('S',"", edtDescricao->getText(),
    "","","","","","","",""), STR_CLINENC, 17);
  return true;
}

long CfrmConClientes::onBtnLimpar(FXObject*,FXSelector,void*) {
  LimparDados();
  return true;
}

long CfrmConClientes::onGridSelected(FXObject*,FXSelector,void* ptr){
  FXTableRange *escala = (FXTableRange*) ptr;
  setLabRegistros(escala->fm.row);
  return true;
}

long CfrmConClientes::onGridChanged(FXObject*,FXSelector,void* ptr){
  FXTablePos *pos = (FXTablePos*) ptr;
  setLabRegistros(pos->row);
  return true;
}
