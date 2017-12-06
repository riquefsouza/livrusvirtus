#include "resource.h"
#include "Cadastros.h"
#include "CadIdiomas.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadIdiomas *frmCadIdiomas = (CfrmCadIdiomas *) NULL;

FXDEFMAP(CfrmCadIdiomas) CfrmCadIdiomasMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadIdiomas::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadIdiomas::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadIdiomas::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadIdiomas::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadIdiomas::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadIdiomas::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadIdiomas::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadIdiomas::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadIdiomas::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadIdiomas::onClose)
};
FXIMPLEMENT(CfrmCadIdiomas,CfrmCadastros,CfrmCadIdiomasMap,
  ARRAYNUMBER(CfrmCadIdiomasMap))

CfrmCadIdiomas::CfrmCadIdiomas(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADIDIOMA, 
  iconeMDI, menuMDI, TEXTFIELD_INTEGER, true) {
  IniciaControles();
}

void CfrmCadIdiomas::IniciaControles() {
 this->labDescricao->setText("Idioma: ");  
}

CfrmCadIdiomas::~CfrmCadIdiomas(){
  frmPrincipal->mnuCadIdiomas->enable();  
}

FXbool CfrmCadIdiomas::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_IDININF))
  		return false;
  	}
  	return true;
}

long CfrmCadIdiomas::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadIdiomas::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  NovoDado(ConsSQL->Idioma('N', edtCodigo->getText(),""));
  return true;
}

long CfrmCadIdiomas::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Idioma('S', edtCodigo->getText(),""), STR_IDINENC);
  return true;
}

long CfrmCadIdiomas::onBtnAnterior(FXObject*,FXSelector,void*) {
  registroAnterior();
  return true;
}

long CfrmCadIdiomas::onBtnProximo(FXObject*,FXSelector,void*) {
  registroProximo();
  return true;
}

long CfrmCadIdiomas::onBtnSalvar(FXObject*,FXSelector,void*) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Idioma('S', edtCodigo->getText(),""),
    ConsSQL->Idioma('U', edtCodigo->getText(), edtDescricao->getText()),
    ConsSQL->Idioma('I', edtCodigo->getText(), edtDescricao->getText()),
    true);
  return true;
}

long CfrmCadIdiomas::onBtnExcluir(FXObject*,FXSelector,void*) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Idioma('D', edtCodigo->getText(),""));
  return true;
}

long CfrmCadIdiomas::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  return true;
}

long CfrmCadIdiomas::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}
