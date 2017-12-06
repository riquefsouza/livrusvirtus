#include "resource.h"
#include "AlterarSenha.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmAlterarSenha *frmAlterarSenha = (CfrmAlterarSenha *) NULL;

FXDEFMAP(CfrmAlterarSenha) CfrmAlterarSenhaMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmAlterarSenha::ID_FRMALTERARSENHA_BTNSALVAR, 
    CfrmAlterarSenha::onBtnSalvar),
  FXMAPFUNC(SEL_COMMAND, CfrmAlterarSenha::ID_FRMALTERARSENHA_BTNLIMPAR, 
    CfrmAlterarSenha::onBtnLimpar),
  FXMAPFUNC(SEL_COMMAND, CfrmAlterarSenha::ID_FRMALTERARSENHA_BTNFECHAR, 
    CfrmAlterarSenha::onBtnFechar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmAlterarSenha::onClose)
};
FXIMPLEMENT(CfrmAlterarSenha,FXMDIChild,CfrmAlterarSenhaMap,
  ARRAYNUMBER(CfrmAlterarSenhaMap))

CfrmAlterarSenha::CfrmAlterarSenha(FXMDIClient *clienteMDI, FXIcon *iconeMDI, 
  FXMDIMenu *menuMDI): FXMDIChild(clienteMDI, STR_ALTSENHA, 
  iconeMDI, menuMDI, MDI_NORMAL|MDI_TRACKING, 0, 0, 257, 181) {
  IniciaControles();
}

void CfrmAlterarSenha::IniciaControles() {
  this->setIcon(new FXBMPIcon(getApp(),Livrus));

  frame = new FXVerticalFrame(this, LAYOUT_FILL_X | LAYOUT_FILL_Y);

  frame1 = new FXVerticalFrame(frame, LAYOUT_FILL_X);
  frame2 = new FXHorizontalFrame(frame1, LAYOUT_TOP);
  frame2->setHSpacing(0);
  frame2->setVSpacing(0);
  frame3 = new FXHorizontalFrame(frame1, LAYOUT_TOP);
  frame3->setHSpacing(0);
  frame3->setVSpacing(0);

  frame4 = new FXVerticalFrame(frame2, LAYOUT_LEFT);
  frame4->setPadTop(0);
  frame4->setPadBottom(0);
  frame5 = new FXVerticalFrame(frame2, LAYOUT_LEFT);
  frame5->setPadTop(0);
  frame5->setPadBottom(0);

  frame6 = new FXVerticalFrame(frame3, LAYOUT_LEFT);
  frame6->setPadTop(0);
  frame6->setPadBottom(0);
  frame7 = new FXVerticalFrame(frame3, LAYOUT_LEFT);
  frame7->setPadTop(0);
  frame7->setPadBottom(0);

  this->labLogin = new FXLabel(frame4, "Login: ", NULL, LAYOUT_LEFT, 
    8, 8, 29, 13);
  this->edtLogin = new FXTextField(frame4, 10, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK, 8, 24, 100, 21, 3, 20);
  this->edtLogin->disable();
  this->labSenhaAtual = new FXLabel(frame5, "Senha atual:", NULL, LAYOUT_LEFT, 
    112, 8, 60, 13);
  this->edtSenhaAtual = new FXTextField(frame5, 10, NULL, 0, TEXTFIELD_LIMITED|
    TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 24, 100, 21, 3, 20);
  this->labNovaSenha = new FXLabel(frame6, "Nova Senha:", NULL, LAYOUT_LEFT, 
    8, 48, 61, 13);
  this->edtNovaSenha = new FXTextField(frame6, 10, NULL, 0, TEXTFIELD_LIMITED|
    TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 8, 64, 100, 21, 3, 20);
  this->labConfirmarSenha = new FXLabel(frame7, "Confirmar Senha:", NULL, LAYOUT_LEFT, 
    112, 48, 79, 13);
  this->edtConfirmaSenha = new FXTextField(frame7, 10, NULL, 0, TEXTFIELD_LIMITED|
    TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 64, 100, 21, 3, 20);

  frameBotoes = new FXHorizontalFrame(frame,
    LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH);
  this->btnSalvar = new FXButton(frameBotoes, "&Salvar", NULL, this, 
    ID_FRMALTERARSENHA_BTNSALVAR, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
    LAYOUT_LEFT, 8, 104, 75, 25, 15, 15, 3, 3 );
  this->btnLimpar = new FXButton(frameBotoes, "&Limpar", NULL, this, 
    ID_FRMALTERARSENHA_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|LAYOUT_LEFT, 
    88, 104, 75, 25, 15, 15, 3, 3 );
  this->btnFechar = new FXButton(frameBotoes, "&Fechar", NULL, this, 
    ID_FRMALTERARSENHA_BTNFECHAR, FRAME_RAISED|FRAME_THICK|LAYOUT_LEFT, 
    168, 104, 75, 25, 15, 15, 3, 3 );

  this->edtLogin->setText(Rotinas_sUsuarioLogin);
  this->edtSenhaAtual->setFocus();
}

CfrmAlterarSenha::~CfrmAlterarSenha(){
  frmPrincipal->mnuAlterarSenha->enable();
}

long CfrmAlterarSenha::onBtnSalvar(FXObject*,FXSelector,void*) {
  if (ValidaDados()) {
    if (Rotinas->AtualizaDados(gConexao, ConsSQL->Usuario('U',
      edtLogin->getText(), edtConfirmaSenha->getText()))) {
      FXMessageBox::error(this, MBOX_OK, "Erro", STR_SENALTSUC);
    }
  }
  return true;
}

long CfrmAlterarSenha::onBtnLimpar(FXObject*,FXSelector,void*) {
  edtSenhaAtual->setText("");
  edtNovaSenha->setText("");
  edtConfirmaSenha->setText("");
  edtSenhaAtual->setFocus();
  return true;
}

long CfrmAlterarSenha::onBtnFechar(FXObject*,FXSelector,void*) {
  this->close();
  return true;
}

long CfrmAlterarSenha::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  return true;
}

FXbool CfrmAlterarSenha::ValidaDados()
{
  if (compare(edtSenhaAtual->getText(), Rotinas_sUsuarioSenha)!=0) {
     FXMessageBox::error(this, MBOX_OK, "Erro", STR_SENNCSU);
     return FALSE;
  }
  if (Rotinas->ValidaCampo(edtNovaSenha->getText(),STR_NSENNINF)) {
  	  return FALSE;
  }
  if (compare(edtNovaSenha->getText(), edtConfirmaSenha->getText())!=0) {
   FXMessageBox::error(this, MBOX_OK, "Erro", STR_NSENNCCON);
   return FALSE;
  } 
 return TRUE;
}
