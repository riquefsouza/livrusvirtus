#include "Principal.h"
#include "CadAutores.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadAutores *frmCadAutores;

void frmCadAutores_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadAutores_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadAutores::CfrmCadAutores()
       : CfrmCadastros(true, STR_CADAUTOR) {
	IniciaControles();
}

CfrmCadAutores::~CfrmCadAutores() { }

void CfrmCadAutores::IniciaControles() {
  edtDescricao->label("Autor:");

  btnNovo->callback((Fl_Callback*)frmCadAutores_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadAutores_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadAutores_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadAutores_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadAutores_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadAutores_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadAutores_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadAutores_btnFecharClick_cb);
}

bool CfrmCadAutores::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_AUTNINF))
  		return false;
  	}
  	return true;
}

void frmCadAutores_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadAutores->btnNovoClick();
  frmCadAutores->NovoDado(ConsSQL->Autor('N', 
    frmCadAutores->edtCodigo->value(),""));
}

void frmCadAutores_btnPesquisarClick_cb(Fl_Button* b, void* v){
  frmCadAutores->PesquisarDados(ConsSQL->Autor('S', 
    frmCadAutores->edtCodigo->value(),""), STR_AUTNENC);
}

void frmCadAutores_btnAnteriorClick_cb(Fl_Button* b, void* v){
  frmCadAutores->registroAnterior();	
}

void frmCadAutores_btnProximoClick_cb(Fl_Button* b, void* v){
  frmCadAutores->registroProximo();
}

void frmCadAutores_btnSalvarClick_cb(Fl_Button* b, void* v){
  frmCadAutores->SalvarDados(frmCadAutores->ValidaDados(true),
    ConsSQL->Autor('S', frmCadAutores->edtCodigo->value(),""),
    ConsSQL->Autor('U', frmCadAutores->edtCodigo->value(), 
    frmCadAutores->edtDescricao->value()),
    ConsSQL->Autor('I', frmCadAutores->edtCodigo->value(), 
    frmCadAutores->edtDescricao->value()), true);
}

void frmCadAutores_btnExcluirClick_cb(Fl_Button* b, void* v){
  frmCadAutores->ExcluirDados(frmCadAutores->ValidaDados(false),
    ConsSQL->Autor('D', frmCadAutores->edtCodigo->value(),""));
}

void frmCadAutores_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadAutores->btnLimparClick();
}

void frmCadAutores_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadAutores->hide();
}

int CfrmCadAutores::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadAutores->activate();
  }
  return CfrmCadastros::handle(event);
}
