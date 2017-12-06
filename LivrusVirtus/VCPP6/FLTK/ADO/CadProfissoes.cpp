#include "Principal.h"
#include "CadProfissoes.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadProfissoes *frmCadProfissoes;

void frmCadProfissoes_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadProfissoes_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadProfissoes::CfrmCadProfissoes()
       : CfrmCadastros(true, STR_CADPROFISS) {
	IniciaControles();
}

CfrmCadProfissoes::~CfrmCadProfissoes() { }

void CfrmCadProfissoes::IniciaControles() {
  edtDescricao->label("Profissao:");

  btnNovo->callback((Fl_Callback*)frmCadProfissoes_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadProfissoes_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadProfissoes_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadProfissoes_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadProfissoes_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadProfissoes_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadProfissoes_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadProfissoes_btnFecharClick_cb);
}

bool CfrmCadProfissoes::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_PROFNINF))
  		return false;
  	}
  	return true;
}

void frmCadProfissoes_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->btnNovoClick();
  frmCadProfissoes->NovoDado(ConsSQL->Profissao('N', 
    frmCadProfissoes->edtCodigo->value(),""));
}

void frmCadProfissoes_btnPesquisarClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->PesquisarDados(ConsSQL->Profissao('S', 
    frmCadProfissoes->edtCodigo->value(),""), STR_PROFNENC);
}

void frmCadProfissoes_btnAnteriorClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->registroAnterior();	
}

void frmCadProfissoes_btnProximoClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->registroProximo();
}

void frmCadProfissoes_btnSalvarClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->SalvarDados(frmCadProfissoes->ValidaDados(true),
    ConsSQL->Profissao('S', frmCadProfissoes->edtCodigo->value(),""),
    ConsSQL->Profissao('U', frmCadProfissoes->edtCodigo->value(), 
    frmCadProfissoes->edtDescricao->value()),
    ConsSQL->Profissao('I', frmCadProfissoes->edtCodigo->value(), 
    frmCadProfissoes->edtDescricao->value()), true);
}

void frmCadProfissoes_btnExcluirClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->ExcluirDados(frmCadProfissoes->ValidaDados(false),
    ConsSQL->Profissao('D', frmCadProfissoes->edtCodigo->value(),""));
}

void frmCadProfissoes_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->btnLimparClick();
}

void frmCadProfissoes_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadProfissoes->hide();
}

int CfrmCadProfissoes::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadProfissoes->activate();
  }
  return CfrmCadastros::handle(event);
}
