#include "Principal.h"
#include "CadAssuntos.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadAssuntos *frmCadAssuntos;

void frmCadAssuntos_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadAssuntos_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadAssuntos::CfrmCadAssuntos()
       : CfrmCadastros(true, STR_CADASSUNTO) {
	IniciaControles();
}

CfrmCadAssuntos::~CfrmCadAssuntos() { }

void CfrmCadAssuntos::IniciaControles() {
  edtDescricao->label("Assunto:");

  btnNovo->callback((Fl_Callback*)frmCadAssuntos_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadAssuntos_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadAssuntos_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadAssuntos_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadAssuntos_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadAssuntos_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadAssuntos_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadAssuntos_btnFecharClick_cb);
}

bool CfrmCadAssuntos::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_ASSNINF))
  		return false;
  	}
  	return true;
}

void frmCadAssuntos_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->btnNovoClick();
  frmCadAssuntos->NovoDado(ConsSQL->Assunto('N', 
    frmCadAssuntos->edtCodigo->value(),""));
}

void frmCadAssuntos_btnPesquisarClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->PesquisarDados(ConsSQL->Assunto('S', 
    frmCadAssuntos->edtCodigo->value(),""), STR_ASSNENC);
}

void frmCadAssuntos_btnAnteriorClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->registroAnterior();	
}

void frmCadAssuntos_btnProximoClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->registroProximo();
}

void frmCadAssuntos_btnSalvarClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->SalvarDados(frmCadAssuntos->ValidaDados(true),
    ConsSQL->Assunto('S', frmCadAssuntos->edtCodigo->value(),""),
    ConsSQL->Assunto('U', frmCadAssuntos->edtCodigo->value(), 
    frmCadAssuntos->edtDescricao->value()),
    ConsSQL->Assunto('I', frmCadAssuntos->edtCodigo->value(), 
    frmCadAssuntos->edtDescricao->value()), true);
}

void frmCadAssuntos_btnExcluirClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->ExcluirDados(frmCadAssuntos->ValidaDados(false),
    ConsSQL->Assunto('D', frmCadAssuntos->edtCodigo->value(),""));
}

void frmCadAssuntos_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->btnLimparClick();
}

void frmCadAssuntos_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadAssuntos->hide();
}

int CfrmCadAssuntos::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadAssuntos->activate();
  }
  return CfrmCadastros::handle(event);
}
