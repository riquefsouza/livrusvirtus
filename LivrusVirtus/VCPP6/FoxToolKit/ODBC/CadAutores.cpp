#include "resource.h"
#include "Cadastros.h"
#include "CadAutores.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadAutores *frmCadAutores = (CfrmCadAutores *) NULL;

FXDEFMAP(CfrmCadAutores) CfrmCadAutoresMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadAutores::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadAutores::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadAutores::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadAutores::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadAutores::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadAutores::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadAutores::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAutores::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadAutores::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadAutores::onClose)
};
FXIMPLEMENT(CfrmCadAutores,CfrmCadastros,CfrmCadAutoresMap,
  ARRAYNUMBER(CfrmCadAutoresMap))

CfrmCadAutores::CfrmCadAutores(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADAUTOR, 
  iconeMDI, menuMDI, TEXTFIELD_INTEGER, true) {
  IniciaControles();
}

void CfrmCadAutores::IniciaControles() {
 this->labDescricao->setText("Autor: ");  
}

CfrmCadAutores::~CfrmCadAutores(){
  frmPrincipal->mnuCadAutores->enable();  
}

FXbool CfrmCadAutores::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_AUTNINF))
  		return false;
  	}
  	return true;
}

long CfrmCadAutores::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadAutores::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  NovoDado(ConsSQL->Autor('N', edtCodigo->getText(),""));
  return true;
}

long CfrmCadAutores::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Autor('S', edtCodigo->getText(),""), STR_AUTNENC);
  return true;
}

long CfrmCadAutores::onBtnAnterior(FXObject*,FXSelector,void*) {
  registroAnterior();
  return true;
}

long CfrmCadAutores::onBtnProximo(FXObject*,FXSelector,void*) {
  registroProximo();
  return true;
}

long CfrmCadAutores::onBtnSalvar(FXObject*,FXSelector,void*) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Autor('S', edtCodigo->getText(),""),
    ConsSQL->Autor('U', edtCodigo->getText(), edtDescricao->getText()),
    ConsSQL->Autor('I', edtCodigo->getText(), edtDescricao->getText()),
    true);
  return true;
}

long CfrmCadAutores::onBtnExcluir(FXObject*,FXSelector,void*) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Autor('D', edtCodigo->getText(),""));
  return true;
}

long CfrmCadAutores::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  return true;
}

long CfrmCadAutores::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}
