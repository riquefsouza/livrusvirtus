#include "resource.h"
#include "Cadastros.h"
#include "CadProfissoes.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadProfissoes *frmCadProfissoes = (CfrmCadProfissoes *) NULL;

FXDEFMAP(CfrmCadProfissoes) CfrmCadProfissoesMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadProfissoes::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadProfissoes::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadProfissoes::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadProfissoes::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadProfissoes::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadProfissoes::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadProfissoes::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadProfissoes::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadProfissoes::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadProfissoes::onClose)
};
FXIMPLEMENT(CfrmCadProfissoes,CfrmCadastros,CfrmCadProfissoesMap,
  ARRAYNUMBER(CfrmCadProfissoesMap))

CfrmCadProfissoes::CfrmCadProfissoes(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADPROFISS, 
  iconeMDI, menuMDI, TEXTFIELD_INTEGER, true) {
  IniciaControles();
}

void CfrmCadProfissoes::IniciaControles() {
 this->labDescricao->setText("Profissao: ");  
}

CfrmCadProfissoes::~CfrmCadProfissoes(){
  frmPrincipal->mnuCadProfissoes->enable();  
}

FXbool CfrmCadProfissoes::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_PROFNINF))
  		return false;
  	}
  	return true;
}

long CfrmCadProfissoes::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadProfissoes::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  NovoDado(ConsSQL->Profissao('N', edtCodigo->getText(),""));
  return true;
}

long CfrmCadProfissoes::onBtnPesquisar(FXObject*,FXSelector,void*) {
  PesquisarDados(
    ConsSQL->Profissao('S', edtCodigo->getText(),""), STR_PROFNENC);
  return true;
}

long CfrmCadProfissoes::onBtnAnterior(FXObject*,FXSelector,void*) {
  registroAnterior();
  return true;
}

long CfrmCadProfissoes::onBtnProximo(FXObject*,FXSelector,void*) {
  registroProximo();
  return true;
}

long CfrmCadProfissoes::onBtnSalvar(FXObject*,FXSelector,void*) {
  SalvarDados(ValidaDados(true),
    ConsSQL->Profissao('S', edtCodigo->getText(),""),
    ConsSQL->Profissao('U', edtCodigo->getText(), edtDescricao->getText()),
    ConsSQL->Profissao('I', edtCodigo->getText(), edtDescricao->getText()),
    true);
  return true;
}

long CfrmCadProfissoes::onBtnExcluir(FXObject*,FXSelector,void*) {
  ExcluirDados(ValidaDados(false),
    ConsSQL->Profissao('D', edtCodigo->getText(),""));
  return true;
}

long CfrmCadProfissoes::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  return true;
}

long CfrmCadProfissoes::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}
