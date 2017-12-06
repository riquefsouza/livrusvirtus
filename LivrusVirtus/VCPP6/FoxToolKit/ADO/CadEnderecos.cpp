#include "resource.h"
#include "Cadastros.h"
#include "CadEnderecos.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmCadEnderecos *frmCadEnderecos = (CfrmCadEnderecos *) NULL;

FXDEFMAP(CfrmCadEnderecos) CfrmCadEnderecosMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadEnderecos::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadEnderecos::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadEnderecos::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadEnderecos::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadEnderecos::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadEnderecos::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadEnderecos::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadEnderecos::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadEnderecos::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadEnderecos::onClose)
};
FXIMPLEMENT(CfrmCadEnderecos,CfrmCadastros,CfrmCadEnderecosMap,
  ARRAYNUMBER(CfrmCadEnderecosMap))

CfrmCadEnderecos::CfrmCadEnderecos(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADENDERECO, 
  iconeMDI, menuMDI, TEXTFIELD_INTEGER, false) {
  IniciaControles();
}

void CfrmCadEnderecos::IniciaControles() {
  this->resize(540, 225);
  this->labDescricao->setText("Logradouro: ");
  this->labDescricao->resize(57, 13);
  this->edtDescricao->resize(264, 21);
  this->edtDescricao->setNumColumns(40);

  frame9 = new FXVerticalFrame(frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame10 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame11 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame12 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame13 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  this->labBairro = new FXLabel(frame9, "Bairro:", NULL, LAYOUT_LEFT, 
    280, 48, 48, 13);
  this->edtBairro = new FXTextField(frame9, 15, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    280, 64, 144, 21, 3, 20);
  this->edtBairro->disable();
  this->labCEP = new FXLabel(frame11, "CEP:", NULL, LAYOUT_LEFT, 
    8, 88, 40, 13);
  this->edtCEP = new FXTextField(frame11, 8, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 104, 72, 21, 3, 20);
  this->edtCEP->disable();
  this->labCidade = new FXLabel(frame12, "Cidade:", NULL, LAYOUT_LEFT, 
    88, 88, 40, 13);
  this->edtCidade = new FXTextField(frame12, 30, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    88, 104, 184, 21, 3, 20);
  this->edtCidade->disable();
  this->labEstado = new FXLabel(frame13, "Estado:", NULL, LAYOUT_LEFT, 
    280, 88, 56, 13);
  this->cmbEstado = new FXComboBox(frame13,8,NULL,0,
    COMBOBOX_INSERT_LAST|FRAME_SUNKEN|FRAME_THICK|LAYOUT_SIDE_TOP
    |LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 280, 104, 144, 21, 3, 20);
  this->cmbEstado->setEditable(false);
  this->cmbEstado->setNumVisible(8);
  this->cmbEstado->disable();

  IniciaBotoes();
  AdicionaCombo();
}

CfrmCadEnderecos::~CfrmCadEnderecos(){
  frmPrincipal->mnuCadEnderecos->enable();  
}

FXbool CfrmCadEnderecos::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_ENDNINF))
    		return false;
  	  if (Rotinas->ValidaCampo(edtBairro->getText(), STR_BAIRRONINF))
    		return false;
  	  if (Rotinas->ValidaCampo(edtCEP->getText(), STR_CEPNINF))
  	  	return false;
  	  if (Rotinas->ValidaCampo(edtCidade->getText(), STR_CIDADENINF))
  		  return false;
  	}
  	return true;
}

long CfrmCadEnderecos::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadEnderecos::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  NovoDado(ConsSQL->Endereco('N', edtCodigo->getText(),"","","","",""));
  return true;
}

long CfrmCadEnderecos::onBtnPesquisar(FXObject*,FXSelector,void*) {
  if (PesquisarDados(
    ConsSQL->Endereco('S', edtCodigo->getText(),"","","","",""), STR_ENDNENC)){
    InformaLimpaDados(true);
    HabilitaDados(true);
  }
  return true;
}

long CfrmCadEnderecos::onBtnAnterior(FXObject*,FXSelector,void*) {
  if (registroAnterior())
    InformaLimpaDados(true);
  return true;
}

long CfrmCadEnderecos::onBtnProximo(FXObject*,FXSelector,void*) {
  if (registroProximo())
    InformaLimpaDados(true);
  return true;
}

long CfrmCadEnderecos::onBtnSalvar(FXObject*,FXSelector,void*) {
  if (SalvarDados(ValidaDados(true),
    ConsSQL->Endereco('S', edtCodigo->getText(),"","","","",""),
    ConsSQL->Endereco('U', edtCodigo->getText(), edtDescricao->getText(),
      edtBairro->getText(), edtCEP->getText(), edtCidade->getText(),
      cmbEstado->getText()),
    ConsSQL->Endereco('I', edtCodigo->getText(), edtDescricao->getText(),
      edtBairro->getText(), edtCEP->getText(), edtCidade->getText(),
      cmbEstado->getText()), true)) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
  return true;
}

long CfrmCadEnderecos::onBtnExcluir(FXObject*,FXSelector,void*) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Endereco('D', edtCodigo->getText(),"","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
  return true;
}

long CfrmCadEnderecos::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
  return true;

}

long CfrmCadEnderecos::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}

void CfrmCadEnderecos::InformaLimpaDados(FXbool bInformar)
{
  if (bInformar) {
    edtBairro->setText(lstRegistros.col[2][nLinhaRegistro]);
    edtCEP->setText(lstRegistros.col[3][nLinhaRegistro]);
    edtCidade->setText(lstRegistros.col[4][nLinhaRegistro]);
    cmbEstado->setText(lstRegistros.col[5][nLinhaRegistro]);
  } else {
    edtBairro->setText("");
    edtCEP->setText("");
    edtCidade->setText("");
    cmbEstado->setCurrentItem(0);
  }

} 

void CfrmCadEnderecos::HabilitaDados(FXbool bHabilita)
{
  if (bHabilita) {
    edtBairro->enable();
    edtCEP->enable();
    edtCidade->enable();
    cmbEstado->enable();
  } else {
    edtBairro->disable();
    edtCEP->disable();
    edtCidade->disable();
    cmbEstado->disable();
  }
}

void CfrmCadEnderecos::AdicionaCombo()
{ 
  cmbEstado->appendItem(STR_PE);
  cmbEstado->appendItem(STR_AC);
  cmbEstado->appendItem(STR_AL);
  cmbEstado->appendItem(STR_AP);
  cmbEstado->appendItem(STR_AM);
  cmbEstado->appendItem(STR_BA);
  cmbEstado->appendItem(STR_BR);
  cmbEstado->appendItem(STR_CE);
  cmbEstado->appendItem(STR_DF);
  cmbEstado->appendItem(STR_ES);
  cmbEstado->appendItem(STR_GO);
  cmbEstado->appendItem(STR_MT);
  cmbEstado->appendItem(STR_MS);
  cmbEstado->appendItem(STR_MG);
  cmbEstado->appendItem(STR_PA);
  cmbEstado->appendItem(STR_PB);
  cmbEstado->appendItem(STR_PR);
  cmbEstado->appendItem(STR_SC);
  cmbEstado->appendItem(STR_RN);
  cmbEstado->appendItem(STR_RS);
  cmbEstado->appendItem(STR_RJ);
  cmbEstado->appendItem(STR_RO);
  cmbEstado->appendItem(STR_RR);
  cmbEstado->appendItem(STR_SP);
  cmbEstado->appendItem(STR_SE);
  cmbEstado->appendItem(STR_TO);
}
