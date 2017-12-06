#include "resource.h"
#include "Cadastros.h"
#include "CadClientes.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

CfrmCadClientes *frmCadClientes = (CfrmCadClientes *) NULL;

FXDEFMAP(CfrmCadClientes) CfrmCadClientesMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNNOVO, 
    CfrmCadClientes::onBtnNovo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNPESQUISAR, 
    CfrmCadClientes::onBtnPesquisar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNANTERIOR, 
    CfrmCadClientes::onBtnAnterior),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNPROXIMO, 
    CfrmCadClientes::onBtnProximo),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNSALVAR, 
    CfrmCadClientes::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNEXCLUIR, 
    CfrmCadClientes::onBtnExcluir),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNLIMPAR, 
    CfrmCadClientes::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADASTROS_BTNFECHAR, 
    CfrmCadClientes::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmCadClientes::onClose),
  FXMAPFUNCS(SEL_COMMAND, CfrmCadClientes::ID_FRMCADCLIENTES_RBMASCULINO,
    CfrmCadClientes::ID_FRMCADCLIENTES_RBFEMININO,CfrmCadClientes::onCmdSexo),
  FXMAPFUNCS(SEL_UPDATE, CfrmCadClientes::ID_FRMCADCLIENTES_RBMASCULINO,
    CfrmCadClientes::ID_FRMCADCLIENTES_RBFEMININO,CfrmCadClientes::onUpdSexo),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadClientes::ID_FRMCADASTROS_EDTCODIGO, 
    CfrmCadClientes::onEdtCodigo_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadClientes::ID_FRMCADCLIENTES_EDTDTNASC, 
    CfrmCadClientes::onEdtDtNasc_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadClientes::ID_FRMCADCLIENTES_EDTCODENDERECO, 
    CfrmCadClientes::onEdtCodEndereco_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadClientes::ID_FRMCADCLIENTES_EDTCODPAIS, 
    CfrmCadClientes::onEdtCodPais_Killfocus),
  FXMAPFUNC(SEL_FOCUSOUT, CfrmCadClientes::ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
    CfrmCadClientes::onEdtCodProfissao_Killfocus),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADCLIENTES_BTNPENDERECO, 
    CfrmCadClientes::onBtnPEndereco),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADCLIENTES_BTNPPAIS, 
    CfrmCadClientes::onBtnPPais),
  FXMAPFUNC(SEL_COMMAND, CfrmCadClientes::ID_FRMCADCLIENTES_BTNPPROFISSAO, 
    CfrmCadClientes::onBtnPProfissao)
};
FXIMPLEMENT(CfrmCadClientes,CfrmCadastros,CfrmCadClientesMap,
  ARRAYNUMBER(CfrmCadClientesMap))

CfrmCadClientes::CfrmCadClientes(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): CfrmCadastros(clienteMDI, STR_CADCLIENTE, 
  iconeMDI, menuMDI, TEXTFIELD_NORMAL, false) {
  IniciaControles();
}

void CfrmCadClientes::IniciaControles() {
  this->resize(558, 515);
  this->labCodigo->setText("CPF:");
  CfrmCadastros::edtCodigo->hide();
  this->edtCodigo = new FXTextField(frame5, 14, this, 
    ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 24, 121, 21, 3, 20);
  this->labDescricao->setText("Nome: ");  
  this->edtDescricao->resize(312, 21);
  this->edtDescricao->setNumColumns(30);

  frame10 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame11 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame12 = new FXVerticalFrame(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame13 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame14 = new FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame15 = new FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame16 = new FXVerticalFrame(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  this->labEmail = new FXLabel(frame11, "Bairro:", NULL, LAYOUT_LEFT, 
    8, 88, 34, 13);
  this->edtEmail = new FXTextField(frame11, 30, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 104, 312, 21, 3, 20);
  this->edtEmail->disable();

  this->labIdentidade = new FXLabel(frame12, "Identidade:", NULL, LAYOUT_LEFT, 
    322, 88, 56, 13);
  this->edtIdentidade = new FXTextField(frame12, 10, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    322, 104, 100, 21, 3, 20);
  this->edtIdentidade->disable();

  rbSexoAlvo = new FXDataTarget(nSexoEscolha);
  this->gpSexo = new FXGroupBox(frame14,"Sexo",LAYOUT_LEFT|FRAME_GROOVE|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 9, 128, 200, 44);
  frameSexo = new FXHorizontalFrame(gpSexo, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  this->rbMasculino = new FXRadioButton(frameSexo,"Masculino",rbSexoAlvo,
    FXDataTarget::ID_OPTION, ICON_BEFORE_TEXT|LAYOUT_LEFT);
  this->rbMasculino->disable();
  this->rbFeminino = new FXRadioButton(frameSexo,"Feminino",rbSexoAlvo,
    FXDataTarget::ID_OPTION+1, ICON_BEFORE_TEXT|LAYOUT_LEFT);
  this->rbFeminino->disable();
  this->gpSexo->disable();
  nSexoEscolha = 0;

  this->labTelefone = new FXLabel(frame15, "Telefone:", NULL, LAYOUT_LEFT, 
    216, 128, 48, 13);
  this->edtTelefone = new FXTextField(frame15, 17, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    216, 144, 104, 21, 3, 20);
  this->edtTelefone->disable();

  this->labDtNasc = new FXLabel(frame16, "Dt. Nascimento:", NULL, LAYOUT_LEFT, 
    216, 128, 48, 13);
  this->edtDtNasc = new FXTextField(frame16, 10, this, 
    ID_FRMCADCLIENTES_EDTDTNASC, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 216, 144, 104, 21, 3, 20);
  this->edtDtNasc->disable();

  this->gpEndereco = new FXGroupBox(frame3,"Endereço",LAYOUT_SIDE_TOP|FRAME_GROOVE|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 9, 128, 430, 145);

  frame17 = new FXHorizontalFrame(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame18 = new FXHorizontalFrame(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame19 = new FXVerticalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame20 = new FXVerticalFrame(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  frame21 = new FXHorizontalFrame(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame22 = new FXVerticalFrame(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame23 = new FXVerticalFrame(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame24 = new FXVerticalFrame(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  this->edtCodEndereco = new FXTextField(frame17, 10, this, 
    ID_FRMCADCLIENTES_EDTCODENDERECO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    16, 200, 88, 21, 3, 20);
  this->edtCodEndereco->disable();

  this->btnPEndereco = new FXButton(frame17, "...", NULL, this, 
    ID_FRMCADCLIENTES_BTNPENDERECO, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
    LAYOUT_LEFT, 104, 200, 21, 21, 10, 10, 3, 3 );
  this->btnPEndereco->disable();

  this->labLogradouro = new FXLabel(frame19, "Logradouro:", NULL, LAYOUT_LEFT, 
    16, 224, 60, 13);
  this->edtLogradouro = new FXTextField(frame19, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    16, 240, 264, 21, 3, 20);
  this->edtLogradouro->disable();

  this->labBairro = new FXLabel(frame20, "Bairro:", NULL, LAYOUT_LEFT, 
    284, 224, 48, 13);
  this->edtBairro = new FXTextField(frame20, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    284, 240, 144, 21, 3, 20);
  this->edtBairro->disable();



  this->labCEP = new FXLabel(frame22, "CEP:", NULL, LAYOUT_LEFT, 
    16, 264, 40, 13);
  this->edtCEP = new FXTextField(frame22, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    16, 280, 78, 21, 3, 20);
  this->edtCEP->disable();

  this->labCidade = new FXLabel(frame23, "Cidade:", NULL, LAYOUT_LEFT, 
    96, 264, 39, 13);
  this->edtCidade = new FXTextField(frame23, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    96, 280, 184, 21, 3, 20);
  this->edtCidade->disable();

  this->labEstado = new FXLabel(frame24, "Estado:", NULL, LAYOUT_LEFT, 
    284, 264, 56, 13);
  this->edtEstado = new FXTextField(frame24, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    284, 280, 144, 21, 3, 20);
  this->edtEstado->disable();

  frame25 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame26 = new FXVerticalFrame(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame27 = new FXHorizontalFrame(frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);
  frame28 = new FXVerticalFrame(frame27, LAYOUT_LEFT, 0,0,0,0,0,0,0,0);

  this->labPais = new FXLabel(frame26, "País de origem:", NULL, LAYOUT_LEFT, 
    8, 320, 77, 16);
  
  this->edtCodPais = new FXTextField(frame26, 3, this, 
    ID_FRMCADCLIENTES_EDTCODPAIS, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 336, 90, 21, 3, 20);
  this->edtCodPais->disable();

  this->edtPais = new FXTextField(frame25, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
    88, 336, 240, 21, 3, 20);
  this->edtPais->disable();
  this->btnPPais = new FXButton(frame25, "...", NULL, this, 
    ID_FRMCADCLIENTES_BTNPPAIS, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 328, 336, 21, 21, 10, 10, 3, 3 );
  this->btnPPais->disable();

  this->labProfissao = new FXLabel(frame28, "Profissão:", NULL, LAYOUT_LEFT,
    8, 360, 56, 13);
  this->edtCodProfissao = new FXTextField(frame28, 10, this, 
    ID_FRMCADCLIENTES_EDTCODPROFISSAO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
    8, 376, 90, 21, 3, 20);
  this->edtCodProfissao->disable();
  this->edtProfissao = new FXTextField(frame27, 50, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
    88, 376, 240, 21, 3, 20);
  this->edtProfissao->disable();
  this->btnPProfissao = new FXButton(frame27, "...", NULL, this, 
    ID_FRMCADCLIENTES_BTNPPROFISSAO, FRAME_RAISED|FRAME_THICK|
    LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
    LAYOUT_LEFT, 328, 376, 21, 21, 10, 10, 3, 3 );
  this->btnPProfissao->disable();

  IniciaBotoes();

}

CfrmCadClientes::~CfrmCadClientes(){
  frmPrincipal->tlbCliente->enable();
  frmPrincipal->mnuCadClientes->enable();  
}

FXbool CfrmCadClientes::ValidaDados(FXbool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->getText(), STR_CPFNINF))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->getText(), STR_CLININF))
		return false;
  if (Rotinas->ValidaCampo(edtEmail->getText(), STR_EMAILNINF))
    return false;
  if (Rotinas->ValidaCampo(edtTelefone->getText(), STR_TELNINF))
	  return false;
  if (Rotinas->ValidaCampo(edtCodEndereco->getText(), STR_ENDNINF))
	  return false;
  if (Rotinas->ValidaCampo(edtCodPais->getText(), STR_PAISNINF))
	  return false;
  if (Rotinas->ValidaCampo(edtCodProfissao->getText(), STR_PROFNINF))
	  return false;
}
return true;
}

long CfrmCadClientes::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

long CfrmCadClientes::onBtnNovo(FXObject*,FXSelector,void*) {
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  return true;
}

long CfrmCadClientes::onBtnPesquisar(FXObject*,FXSelector,void*) {
  if (PesquisarDados(ConsSQL->Cliente('S', edtCodigo->getText(),
    "","","","","","","","",""), STR_CLINENC)) {
    InformaLimpaDados(true);
    HabilitaDados(true);
  }
  return true;
}

long CfrmCadClientes::onBtnAnterior(FXObject*,FXSelector,void*) {
  if (registroAnterior())
    InformaLimpaDados(true);
  return true;
}

long CfrmCadClientes::onBtnProximo(FXObject*,FXSelector,void*) {
  if (registroProximo())
    InformaLimpaDados(true);
  return true;
}

long CfrmCadClientes::onBtnSalvar(FXObject*,FXSelector,void*) {
  FXString sSexo, sDtNasc, sSqlInsert, sSqlUpdate;

  if (nSexoEscolha == 0)
     sSexo = "M";
  else
     sSexo = "F";

  sDtNasc = Rotinas->ConverteDataHoraStr(edtDtNasc->getText(),
    true, "%Y/%m/%d", "");

  sSqlUpdate = ConsSQL->Cliente('U', edtCodigo->getText(), edtDescricao->getText(),
    edtEmail->getText(),  edtIdentidade->getText(), sSexo,
    edtTelefone->getText(), sDtNasc, edtCodEndereco->getText(),
    edtCodPais->getText(), edtCodProfissao->getText());

  sSqlInsert = ConsSQL->Cliente('I', edtCodigo->getText(), edtDescricao->getText(),
    edtEmail->getText(),  edtIdentidade->getText(), sSexo,
    edtTelefone->getText(), sDtNasc, edtCodEndereco->getText(),
    edtCodPais->getText(), edtCodProfissao->getText());

  if (SalvarDados(ValidaDados(true),
    ConsSQL->Cliente('S', edtCodigo->getText(),"","","","","","","","",""),
    sSqlUpdate, sSqlInsert, true)) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
  return true;
}

long CfrmCadClientes::onBtnExcluir(FXObject*,FXSelector,void*) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Cliente('D', edtCodigo->getText(),
    "","","","","","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
  return true;
}

long CfrmCadClientes::onBtnLimpar(FXObject*,FXSelector,void*) {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
  return true;
}

long CfrmCadClientes::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}

void CfrmCadClientes::InformaLimpaDados(FXbool bInformar) {
FXString sTemp;

  if (bInformar) {
    edtCodigo->setText(lstRegistros.col[0][nLinhaRegistro]);
    edtEmail->setText(lstRegistros.col[2][nLinhaRegistro]);
    edtIdentidade->setText(lstRegistros.col[3][nLinhaRegistro]);
    if (compare(lstRegistros.col[4][nLinhaRegistro].text(),"M")==0) {
      nSexoEscolha = 0;
    } else {
      nSexoEscolha = 1;
    }
    edtTelefone->setText(lstRegistros.col[5][nLinhaRegistro]);
    sTemp = lstRegistros.col[6][nLinhaRegistro];
    edtDtNasc->setText(sTemp.mid(0,10));
    edtCodEndereco->setText(lstRegistros.col[7][nLinhaRegistro]);
    edtLogradouro->setText(lstRegistros.col[8][nLinhaRegistro]);
    edtBairro->setText(lstRegistros.col[9][nLinhaRegistro]);
    edtCEP->setText(lstRegistros.col[10][nLinhaRegistro]);
    edtCidade->setText(lstRegistros.col[11][nLinhaRegistro]);
    edtEstado->setText(lstRegistros.col[12][nLinhaRegistro]);
    edtCodPais->setText(lstRegistros.col[13][nLinhaRegistro]);
    edtPais->setText(lstRegistros.col[14][nLinhaRegistro]);
    edtCodProfissao->setText(lstRegistros.col[15][nLinhaRegistro]);
    edtProfissao->setText(lstRegistros.col[16][nLinhaRegistro]);
  } else {
    edtEmail->setText("");
    edtIdentidade->setText("");
    rbMasculino->setCheck(true);
    rbFeminino->setCheck(false);
    edtTelefone->setText("");
    edtDtNasc->setText("");
    edtCodEndereco->setText("");
    edtLogradouro->setText("");
    edtBairro->setText("");
    edtCEP->setText("");
    edtCidade->setText("");
    edtEstado->setText("");
    edtCodPais->setText("");
    edtPais->setText("");
    edtCodProfissao->setText("");
    edtProfissao->setText("");
    edtCodigo->setFocus();
  }
}

void CfrmCadClientes::HabilitaDados(FXbool bHabilita)
{
  if (bHabilita) {
    edtEmail->enable();
    edtIdentidade->enable();
    gpSexo->enable();
    rbMasculino->enable();
    rbFeminino->enable();
    edtTelefone->enable();
    edtDtNasc->enable();
    edtCodEndereco->enable();
    btnPEndereco->enable();
    edtCodPais->enable();
    btnPPais->enable();
    edtCodProfissao->enable();
    btnPProfissao->enable();
  } else {
    edtEmail->disable();
    edtIdentidade->disable();
    gpSexo->disable();
    rbMasculino->disable();
    rbFeminino->disable();
    edtTelefone->disable();
    edtDtNasc->disable();
    edtCodEndereco->disable();
    btnPEndereco->disable();
    edtCodPais->disable();
    btnPPais->disable();
    edtCodProfissao->disable();
    btnPProfissao->disable();
  }
}

long CfrmCadClientes::onCmdSexo(FXObject*,FXSelector sel,void*) {
  nSexoEscolha=FXSELID(sel);
  return true;
}

long CfrmCadClientes::onUpdSexo(FXObject* obj,FXSelector sel,void*) {
  obj->handle(this,(FXSELID(sel)==nSexoEscolha)?
    FXSEL(SEL_COMMAND,ID_CHECK):FXSEL(SEL_COMMAND,ID_UNCHECK),(void*)&nSexoEscolha);
  return true;
}

long CfrmCadClientes::onEdtCodigo_Killfocus(FXObject*,FXSelector,void*){
  if (edtCodigo->getText().length() > 0) {
	  if (Rotinas->validaCPF(edtCodigo->getText())==false) {
      edtCodigo->setText("");
		  edtCodigo->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_CPFINV);
	  }
  }
  return true;
}

long CfrmCadClientes::onEdtDtNasc_Killfocus(FXObject*,FXSelector,void*){
  if (edtDtNasc->getText().length() > 0) {
    if (!Rotinas->validaDataHora(edtDtNasc->getText(), true)) {
      edtDtNasc->setText(Rotinas->retDataHoraStr(true,false));
		  edtDtNasc->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_DTHRINV);
    }
  } else
      edtDtNasc->setText(Rotinas->retDataHoraStr(true,false));
  return true;
}

long CfrmCadClientes::onEdtCodEndereco_Killfocus(FXObject*,FXSelector,void*){
  FXString sLogradouro;
  LISTAMSTR ConsCampo;

  if (edtCodEndereco->getText().length() > 0) {
    sLogradouro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Endereco('S',
    edtCodEndereco->getText(),"","","","",""),STR_ENDNENC);
    if (sLogradouro.length() > 0) {
      frmCadClientes->edtLogradouro->setText(sLogradouro);
      edtBairro->setText(ConsCampo.col[2][0]);
      edtCEP->setText(ConsCampo.col[3][0]);
      edtCidade->setText(ConsCampo.col[4][0]);
      edtEstado->setText(ConsCampo.col[5][0]);
    } else {
      edtCodEndereco->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_ENDNENC);
      edtLogradouro->setText("");
      edtBairro->setText("");
      edtCEP->setText("");
	    edtCidade->setText("");
	    edtEstado->setText("");
    }
  } else {
    edtLogradouro->setText("");
    edtBairro->setText("");
    edtCEP->setText("");
    edtCidade->setText("");
    edtEstado->setText("");
  }
  return true;
}

long CfrmCadClientes::onEdtCodPais_Killfocus(FXObject*,FXSelector,void*){
  FXString sPais;
  LISTAMSTR ConsCampo;

  if (edtCodPais->getText().length() > 0) {
    sPais = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Pais('S',
      edtCodPais->getText(),""),STR_PAISNENC);
    if (sPais.length() > 0) {
      edtPais->setText(sPais);
    } else {
      edtCodPais->killFocus();
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_PAISNENC);
      edtCodPais->setText("");
      edtPais->setText("");
    }
  } else {
    edtPais->setText("");
  }
  return true;
}

long CfrmCadClientes::onEdtCodProfissao_Killfocus(FXObject*,FXSelector,void*){
  FXString sProfissao;
  LISTAMSTR ConsCampo;

  if (edtCodProfissao->getText().length() > 0) {
    sProfissao = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Profissao('S',
      edtCodProfissao->getText(),""),STR_PROFNENC);

    if (sProfissao.length() > 0) {
      edtProfissao->setText(sProfissao);
    } else {
       edtCodProfissao->killFocus();
       FXMessageBox::error(this, MBOX_OK, "Erro", STR_PROFNENC);
       edtCodProfissao->setText("");
       edtProfissao->setText("");
    }
  } else {
    edtProfissao->setText("");
  }
  return true;
}

long CfrmCadClientes::onBtnPEndereco(FXObject*,FXSelector,void*){
  CfrmConEnderecos *fConEnderecos = new CfrmConEnderecos(this);
  fConEnderecos->execute();
  edtCodEndereco->setText(Rotinas_sCodigoSelecionado);
  onEdtCodEndereco_Killfocus(NULL,0,NULL);
  return true;
}

long CfrmCadClientes::onBtnPPais(FXObject*,FXSelector,void*){
  CfrmConPaises *fConPaises = new CfrmConPaises(this);
  fConPaises->execute();
  edtCodPais->setText(Rotinas_sCodigoSelecionado);
  onEdtCodPais_Killfocus(NULL,0,NULL);
  return true;
}

long CfrmCadClientes::onBtnPProfissao(FXObject*,FXSelector,void*){
  CfrmConProfissoes *fConProfissoes = new CfrmConProfissoes(this);
  fConProfissoes->execute();
  edtCodProfissao->setText(Rotinas_sCodigoSelecionado);
  onEdtCodProfissao_Killfocus(NULL,0,NULL);
  return true;
}

