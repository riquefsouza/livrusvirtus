#include "Login.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmLogin *frmLogin;
Fl_Pixmap image_login(idata_login);

void frmLogin_btnLoginClick_cb(Fl_Button* b, void* v);
void frmLogin_btnCancelarClick_cb(Fl_Button* b, void* v);

CfrmLogin::CfrmLogin()
       : Fl_Double_Window(207, 141, "Login do Sistema") {
	IniciaControles();
}

CfrmLogin::~CfrmLogin() { }

void CfrmLogin::IniciaControles() {
  this->box(FL_FLAT_BOX);
  this->color(FL_BACKGROUND_COLOR);
  this->selection_color(FL_BACKGROUND_COLOR);
  this->labeltype(FL_NO_LABEL);
  this->labelfont(0);
  this->labelsize(14);
  this->labelcolor(FL_BLACK);
  this->user_data((void*)(this));
  this->align(FL_ALIGN_TOP);
  this->when(FL_WHEN_RELEASE);
  box1 = new Fl_Box(5, 5, 100, 105);
  box1->image(image_login);
  edtLogin = new Fl_Input(110, 30, 95, 25, "Login:");
  edtLogin->align(FL_ALIGN_TOP_LEFT);
  edtSenha = new Fl_Input(110, 75, 95, 25, "Senha:");
  edtSenha->type(5);
  edtSenha->align(FL_ALIGN_TOP_LEFT);
  btnLogin = new Fl_Return_Button(25, 110, 75, 25, "&Login");
  btnLogin->callback((Fl_Callback*)frmLogin_btnLoginClick_cb);
  btnCancelar = new Fl_Button(110, 110, 75, 25, "&Cancelar");
  btnCancelar->callback((Fl_Callback*)frmLogin_btnCancelarClick_cb);
  this->hotspot(this, 15);
  this->set_modal();
  this->end();
}

void frmLogin_btnLoginClick_cb(Fl_Button* b, void* v){
  char *sTemp = Rotinas->alocaString(TAM_MAX_STR);
  
  Rotinas_sUsuarioLogin = frmLogin->edtLogin->value();
  Rotinas_sUsuarioSenha = frmLogin->edtSenha->value();

  if (Rotinas->ConsultaDados(gConexao, 
    ConsSQL->Usuario('S',Rotinas_sUsuarioLogin, Rotinas_sUsuarioSenha)) ) {
     
    sprintf(sTemp, "%s%s", STR_USUARIO, Rotinas_sUsuarioLogin.c_str());    
    frmPrincipal = new CfrmPrincipal();
    frmPrincipal->show();
    frmPrincipal->BarraDeStatus1->label(sTemp);

    frmLogin->hide();
  } else
     fl_alert(STR_LOGSENINC); 
}

void frmLogin_btnCancelarClick_cb(Fl_Button* b, void* v){
  frmLogin->hide();
}
