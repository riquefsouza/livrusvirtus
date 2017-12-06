#include "AlterarSenha.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmAlterarSenha *frmAlterarSenha;

void frmAlterarSenha_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmAlterarSenha_btnLimparClick_cb(Fl_Button* b, void* v);
void frmAlterarSenha_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmAlterarSenha::CfrmAlterarSenha()
  : Fl_Double_Window(258, 137, STR_ALTSENHA){
	IniciaControles();
}

CfrmAlterarSenha::~CfrmAlterarSenha() { }

void CfrmAlterarSenha::IniciaControles() {
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
  edtLogin = new Fl_Input(10, 25, 105, 25, "Login:");
  edtLogin->align(FL_ALIGN_TOP_LEFT);
  edtLogin->deactivate();
  edtLogin->value(Rotinas_sUsuarioLogin.c_str());
  edtSenhaAtual = new Fl_Input(120, 25, 105, 25, "Senha atual:");
  edtSenhaAtual->type(5);
  edtSenhaAtual->align(FL_ALIGN_TOP_LEFT);
  edtNovaSenha = new Fl_Input(10, 70, 105, 25, "Nova senha:");
  edtNovaSenha->type(5);
  edtNovaSenha->align(FL_ALIGN_TOP_LEFT);
  edtConfirmaSenha = new Fl_Input(120, 70, 105, 25, "Confirma Senha:");
  edtConfirmaSenha->type(5);
  edtConfirmaSenha->align(FL_ALIGN_TOP_LEFT);
  btnSalvar = new Fl_Button(10, 105, 75, 25, "&Salvar");
  btnSalvar->callback((Fl_Callback*)frmAlterarSenha_btnSalvarClick_cb);
  btnLimpar = new Fl_Button(90, 105, 75, 25, "&Limpar");
  btnLimpar->callback((Fl_Callback*)frmAlterarSenha_btnLimparClick_cb);
  btnFechar = new Fl_Button(170, 105, 75, 25, "&Fechar");
  btnFechar->callback((Fl_Callback*)frmAlterarSenha_btnFecharClick_cb);
  this->hotspot(this);
  this->end();
}

void frmAlterarSenha_btnSalvarClick_cb(Fl_Button* b, void* v) {
  if (frmAlterarSenha->ValidaDados()) {
    if (Rotinas->AtualizaDados(gConexao, 
      ConsSQL->Usuario('U', frmAlterarSenha->edtLogin->value(), 
      frmAlterarSenha->edtConfirmaSenha->value()) 
      ))  {
      fl_message(STR_SENALTSUC);
    }         
  }	
}

void frmAlterarSenha_btnLimparClick_cb(Fl_Button* b, void* v) {
  frmAlterarSenha->edtSenhaAtual->value("");
  frmAlterarSenha->edtNovaSenha->value("");
  frmAlterarSenha->edtConfirmaSenha->value("");
  frmAlterarSenha->edtSenhaAtual->take_focus();
}

void frmAlterarSenha_btnFecharClick_cb(Fl_Button* b, void* v) {
  frmAlterarSenha->hide();
}

bool CfrmAlterarSenha::ValidaDados()
{
  if (strcmp(edtSenhaAtual->value(), Rotinas_sUsuarioSenha.c_str())!=0) {
     fl_alert(STR_SENNCSU);
     return false;
  }
  if (Rotinas->ValidaCampo(edtNovaSenha->value(), STR_NSENNINF)) {
  	  return false;
  }
  if (strcmp(edtNovaSenha->value(), edtConfirmaSenha->value())!=0) {
   fl_alert(STR_NSENNCCON);   
   return false;
  } 
return true;
}

int CfrmAlterarSenha::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuOpAlterarSenha->activate();
  }
  return Fl_Double_Window::handle(event);
}
