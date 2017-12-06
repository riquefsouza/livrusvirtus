#include "Principal.h"
#include "CadEditoras.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadEditoras *frmCadEditoras;

void frmCadEditoras_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadEditoras_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadEditoras::CfrmCadEditoras()
       : CfrmCadastros(true, STR_CADEDITORA) {
	IniciaControles();
}

CfrmCadEditoras::~CfrmCadEditoras() { }

void CfrmCadEditoras::IniciaControles() {
  edtDescricao->label("Editora:");

  btnNovo->callback((Fl_Callback*)frmCadEditoras_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadEditoras_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadEditoras_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadEditoras_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadEditoras_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadEditoras_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadEditoras_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadEditoras_btnFecharClick_cb);
}

bool CfrmCadEditoras::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_EDTNINF))
  		return false;
  	}
  	return true;
}

void frmCadEditoras_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->btnNovoClick();
  frmCadEditoras->NovoDado(ConsSQL->Editora('N', 
    frmCadEditoras->edtCodigo->value(),""));
}

void frmCadEditoras_btnPesquisarClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->PesquisarDados(ConsSQL->Editora('S', 
    frmCadEditoras->edtCodigo->value(),""), STR_EDTNENC);
}

void frmCadEditoras_btnAnteriorClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->registroAnterior();	
}

void frmCadEditoras_btnProximoClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->registroProximo();
}

void frmCadEditoras_btnSalvarClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->SalvarDados(frmCadEditoras->ValidaDados(true),
    ConsSQL->Editora('S', frmCadEditoras->edtCodigo->value(),""),
    ConsSQL->Editora('U', frmCadEditoras->edtCodigo->value(), 
    frmCadEditoras->edtDescricao->value()),
    ConsSQL->Editora('I', frmCadEditoras->edtCodigo->value(), 
    frmCadEditoras->edtDescricao->value()), true);
}

void frmCadEditoras_btnExcluirClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->ExcluirDados(frmCadEditoras->ValidaDados(false),
    ConsSQL->Editora('D', frmCadEditoras->edtCodigo->value(),""));
}

void frmCadEditoras_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->btnLimparClick();
}

void frmCadEditoras_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadEditoras->hide();
}

int CfrmCadEditoras::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadEditoras->activate();
  }
  return CfrmCadastros::handle(event);
}
