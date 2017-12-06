#include "resource.h"
#include "Cadastros.h"
#include "CadAssuntos.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadAssuntos *frmCadAssuntos = (CfrmCadAssuntos *) NULL;

FXDEFMAP(CfrmCadAssuntos) CfrmCadAssuntosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadAssuntos::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadAssuntos::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadAssuntos::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadAssuntos::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadAssuntos::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadAssuntos::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadAssuntos::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadAssuntos::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadAssuntos::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadAssuntos::onClose)
};
FXIMPLEMENT(CfrmCadAssuntos,CfrmCadastros,CfrmCadAssuntosMap,
  ARRAYNUMBER(CfrmCadAssuntosMap))

CfrmCadAssuntos::CfrmCadAssuntos(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADASSUNTO, 
  iconeMDI, menuMDI, TEXTFIELD_INTEGER, true) {
  IniciaControles();
}

void CfrmCadAssuntos::IniciaControles() {
 this->labDescricao->setText("Assunto: ");  
}

CfrmCadAssuntos::~CfrmCadAssuntos(){
  frmPrincipal->mnuCadAssuntos->enable();  
}

FXbool CfrmCadAssuntos::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_ASSNINF))
  		return false;
  	}
  	return true;
}

long CfrmCadAssuntos::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadAssuntos::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  NovoDado(ConsSQL->Assunto('N', edtCodigo->getText(),""));
  return true;
}

long CfrmCadAssuntos::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Assunto('S', edtCodigo->getText(),""), STR_ASSNENC);
  return true;
}

long CfrmCadAssuntos::onBtnAnterior(FXObject*,FXSelector,void*) {
  registroAnterior();
  return true;
}

long CfrmCadAssuntos::onBtnProximo(FXObject*,FXSelector,void*) {
  registroProximo();
  return true;
}

long CfrmCadAssuntos::onBtnSalvar(FXObject*,FXSelector,void*) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Assunto('S', edtCodigo->getText(),""),
    ConsSQL->Assunto('U', edtCodigo->getText(), edtDescricao->getText()),
    ConsSQL->Assunto('I', edtCodigo->getText(), edtDescricao->getText()),
    true);
  return true;
}

long CfrmCadAssuntos::onBtnExcluir(FXObject*,FXSelector,void*) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Assunto('D', edtCodigo->getText(),""));
  return true;
}

long CfrmCadAssuntos::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  return true;
}

long CfrmCadAssuntos::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}
