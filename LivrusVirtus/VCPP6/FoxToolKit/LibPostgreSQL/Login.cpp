#include "resource.h"
#include "Login.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmLogin *frmLogin = (CfrmLogin *) NULL;

FXDEFMAP(CfrmLogin) CfrmLoginMap[]={
  FXMAPFUNC(SEL_COMMAND, CfrmLogin::ID_FRMLOGIN_BTNLOGIN, 
    CfrmLogin::onBtnLogin),
  FXMAPFUNC(SEL_COMMAND, CfrmLogin::ID_FRMLOGIN_BTNCANCELAR, 
    CfrmLogin::onBtnCancelar),
  FXMAPFUNC(SEL_CLOSE, 0, CfrmLogin::onClose)
};
FXIMPLEMENT(CfrmLogin,FXDialogBox,CfrmLoginMap,ARRAYNUMBER(CfrmLoginMap))

CfrmLogin::CfrmLogin(FXApp* owner):
  FXDialogBox(owner, "Login do Sistema", DECOR_TITLE | DECOR_CLOSE, 
    546, 346, 211, 148, 0, 0, 0, 0, 4, 4){
  IniciaControles();
}

void CfrmLogin::IniciaControles() {
  this->setIcon(new FXBMPIcon(getApp(),Livrus));

  frame1 = new FXHorizontalFrame(this, LAYOUT_FILL_X);
  frame2 = new FXHorizontalFrame(frame1, LAYOUT_LEFT);
  frame3 = new FXVerticalFrame(frame1, LAYOUT_LEFT);

  this->bmpLoginIcon = new FXBMPIcon(getApp(), Login);  
  this->bmpLogin = new FXLabel(frame2, "", bmpLoginIcon, 
    LAYOUT_LEFT, 8, 8, 88, 90); 
  this->labLogin = new FXLabel(frame3, "Login: ", NULL, LAYOUT_LEFT, 
    112, 8, 29, 13);
  this->edtLogin = new FXTextField(frame3, 10, NULL, 0, TEXTFIELD_LIMITED|
    FRAME_SUNKEN|FRAME_THICK, 112, 24, 80, 21, 3, 10);
  this->labSenha = new FXLabel(frame3, "Senha:", NULL, LAYOUT_LEFT, 
    112, 56, 34, 13);
  this->edtSenha = new FXTextField(frame3, 10, NULL, 0, TEXTFIELD_LIMITED|
    TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 72, 80, 21, 3, 10);

  frameBotoes = new FXHorizontalFrame(this,
    LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH);
  this->btnLogin = new FXButton(frameBotoes, "&Login", NULL, this, 
    ID_FRMLOGIN_BTNLOGIN, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
    LAYOUT_CENTER_X, 24, 107, 75, 25, 15, 15, 3, 3 );
  this->btnCancelar = new FXButton(frameBotoes, "&Cancelar", NULL, this, 
    ID_FRMLOGIN_BTNCANCELAR, FRAME_RAISED|FRAME_THICK|LAYOUT_CENTER_X, 
    112, 107, 75, 25, 15, 15, 3, 3 );
  this->edtLogin->setFocus();
}

void CfrmLogin::create(){
  FXDialogBox::create();
}

CfrmLogin::~CfrmLogin(){
  delete bmpLoginIcon;
}

long CfrmLogin::onBtnLogin(FXObject*,FXSelector,void*) {
  Rotinas_sUsuarioLogin = edtLogin->getText();
  Rotinas_sUsuarioSenha = edtSenha->getText();

  if (Rotinas->ConsultaDados(gConexao, 
     ConsSQL->Usuario('S',Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) ) {
                
     Rotinas_sBarraLogin = 
      FXStringFormat("%s%s", STR_USUARIO, Rotinas_sUsuarioLogin.text());

     frmPrincipal->labStatus->setText(Rotinas_sBarraLogin);

     bFechar=FALSE;
     frmPrincipal->show(PLACEMENT_SCREEN);
     this->close();	
  } else
     FXMessageBox::error(this, MBOX_OK, "Erro", STR_LOGSENINC);

  return true;
}

long CfrmLogin::onBtnCancelar(FXObject*,FXSelector,void*) {
  bFechar = TRUE;
  getApp()->exit(0);
  return true;
}

long CfrmLogin::onClose(FXObject*,FXSelector,void*) {
  this->destroy();
  if (bFechar) {
    frmPrincipal->destroy();
    getApp()->exit(0);
  }
  return true;
}

