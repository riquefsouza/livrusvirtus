#include "resource.h"
#include "Cadastros.h"
#include "CadPaises.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadPaises *frmCadPaises = (CfrmCadPaises *) NULL;

FXDEFMAP(CfrmCadPaises) CfrmCadPaisesMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadPaises::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadPaises::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadPaises::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadPaises::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadPaises::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadPaises::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadPaises::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadPaises::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadPaises::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadPaises::onClose)
};
FXIMPLEMENT(CfrmCadPaises,CfrmCadastros,CfrmCadPaisesMap,
  ARRAYNUMBER(CfrmCadPaisesMap))

CfrmCadPaises::CfrmCadPaises(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADPAIS, 
  iconeMDI, menuMDI, TEXTFIELD_NORMAL, true) {
  IniciaControles();
}

void CfrmCadPaises::IniciaControles() {
 this->labDescricao->setText("Pais: ");  

 this->edtCodigo->setNumColumns(3);
}

CfrmCadPaises::~CfrmCadPaises(){
  frmPrincipal->mnuCadPaises->enable();  
}

FXbool CfrmCadPaises::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_PAISNINF))
  		return false;
  	}
  	return true;
}

long CfrmCadPaises::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadPaises::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  return true;
}

long CfrmCadPaises::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Pais('S', edtCodigo->getText(),""), STR_PAISNENC);
  return true;
}

long CfrmCadPaises::onBtnAnterior(FXObject*,FXSelector,void*) {
  registroAnterior();
  return true;
}

long CfrmCadPaises::onBtnProximo(FXObject*,FXSelector,void*) {
  registroProximo();
  return true;
}

long CfrmCadPaises::onBtnSalvar(FXObject*,FXSelector,void*) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Pais('S', edtCodigo->getText(),""),
    ConsSQL->Pais('U', edtCodigo->getText(), edtDescricao->getText()),
    ConsSQL->Pais('I', edtCodigo->getText(), edtDescricao->getText()),
    true);
  return true;
}

long CfrmCadPaises::onBtnExcluir(FXObject*,FXSelector,void*) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Pais('D', edtCodigo->getText(),""));
  return true;
}

long CfrmCadPaises::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  return true;
}

long CfrmCadPaises::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}
