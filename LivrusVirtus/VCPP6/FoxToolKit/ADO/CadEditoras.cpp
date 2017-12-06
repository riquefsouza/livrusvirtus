#include "resource.h"
#include "Cadastros.h"
#include "CadEditoras.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadEditoras *frmCadEditoras = (CfrmCadEditoras *) NULL;

FXDEFMAP(CfrmCadEditoras) CfrmCadEditorasMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadEditoras::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadEditoras::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadEditoras::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadEditoras::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadEditoras::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadEditoras::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadEditoras::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEditoras::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadEditoras::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadEditoras::onClose)
};
FXIMPLEMENT(CfrmCadEditoras,CfrmCadastros,CfrmCadEditorasMap,
  ARRAYNUMBER(CfrmCadEditorasMap))

CfrmCadEditoras::CfrmCadEditoras(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADEDITORA, 
  iconeMDI, menuMDI, TEXTFIELD_INTEGER, true) {
  IniciaControles();
}

void CfrmCadEditoras::IniciaControles() {
 this->labDescricao->setText("Editora: ");  
}

CfrmCadEditoras::~CfrmCadEditoras(){
  frmPrincipal->mnuCadEditoras->enable();  
}

FXbool CfrmCadEditoras::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_EDTNINF))
  		return false;
  	}
  	return true;
}

long CfrmCadEditoras::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadEditoras::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  NovoDado(ConsSQL->Editora('N', edtCodigo->getText(),""));
  return true;
}

long CfrmCadEditoras::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Editora('S', edtCodigo->getText(),""), STR_EDTNENC);
  return true;
}

long CfrmCadEditoras::onBtnAnterior(FXObject*,FXSelector,void*) {
  registroAnterior();
  return true;
}

long CfrmCadEditoras::onBtnProximo(FXObject*,FXSelector,void*) {
  registroProximo();
  return true;
}

long CfrmCadEditoras::onBtnSalvar(FXObject*,FXSelector,void*) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Editora('S', edtCodigo->getText(),""),
    ConsSQL->Editora('U', edtCodigo->getText(), edtDescricao->getText()),
    ConsSQL->Editora('I', edtCodigo->getText(), edtDescricao->getText()),
    true);
  return true;
}

long CfrmCadEditoras::onBtnExcluir(FXObject*,FXSelector,void*) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Editora('D', edtCodigo->getText(),""));
  return true;
}

long CfrmCadEditoras::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  return true;
}

long CfrmCadEditoras::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}
