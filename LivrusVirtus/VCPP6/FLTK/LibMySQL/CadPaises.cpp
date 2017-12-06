#include "Principal.h"
#include "CadPaises.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadPaises *frmCadPaises;

void frmCadPaises_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadPaises_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadPaises::CfrmCadPaises()
       : CfrmCadastros(true, STR_CADPAIS) {
	IniciaControles();
}

CfrmCadPaises::~CfrmCadPaises() { }

void CfrmCadPaises::IniciaControles() {
  edtCodigo->type(0);
  edtCodigo->maximum_size(3);
  edtDescricao->label("Pais:");

  btnNovo->callback((Fl_Callback*)frmCadPaises_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadPaises_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadPaises_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadPaises_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadPaises_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadPaises_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadPaises_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadPaises_btnFecharClick_cb);
}

bool CfrmCadPaises::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_PAISNINF))
  		return false;
  	}
  	return true;
}

void frmCadPaises_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadPaises->btnNovoClick();
}

void frmCadPaises_btnPesquisarClick_cb(Fl_Button* b, void* v){
  frmCadPaises->PesquisarDados(ConsSQL->Pais('S', 
    frmCadPaises->edtCodigo->value(),""), STR_PAISNENC);
}

void frmCadPaises_btnAnteriorClick_cb(Fl_Button* b, void* v){
  frmCadPaises->registroAnterior();	
}

void frmCadPaises_btnProximoClick_cb(Fl_Button* b, void* v){
  frmCadPaises->registroProximo();
}

void frmCadPaises_btnSalvarClick_cb(Fl_Button* b, void* v){
  frmCadPaises->SalvarDados(frmCadPaises->ValidaDados(true),
    ConsSQL->Pais('S', frmCadPaises->edtCodigo->value(),""),
    ConsSQL->Pais('U', frmCadPaises->edtCodigo->value(), 
    frmCadPaises->edtDescricao->value()),
    ConsSQL->Pais('I', frmCadPaises->edtCodigo->value(), 
    frmCadPaises->edtDescricao->value()), true);
}

void frmCadPaises_btnExcluirClick_cb(Fl_Button* b, void* v){
  frmCadPaises->ExcluirDados(frmCadPaises->ValidaDados(false),
    ConsSQL->Pais('D', frmCadPaises->edtCodigo->value(),""));
}

void frmCadPaises_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadPaises->btnLimparClick();
}

void frmCadPaises_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadPaises->hide();
}

int CfrmCadPaises::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadPaises->activate();
  }
  return CfrmCadastros::handle(event);
}
