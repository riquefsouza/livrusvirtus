#include "Principal.h"
#include "CadIdiomas.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadIdiomas *frmCadIdiomas;

void frmCadIdiomas_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadIdiomas_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadIdiomas::CfrmCadIdiomas()
       : CfrmCadastros(true, STR_CADIDIOMA) {
	IniciaControles();
}

CfrmCadIdiomas::~CfrmCadIdiomas() { }

void CfrmCadIdiomas::IniciaControles() {
  edtDescricao->label("Idioma:");

  btnNovo->callback((Fl_Callback*)frmCadIdiomas_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadIdiomas_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadIdiomas_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadIdiomas_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadIdiomas_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadIdiomas_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadIdiomas_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadIdiomas_btnFecharClick_cb);
}

bool CfrmCadIdiomas::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_IDININF))
  		return false;
  	}
  	return true;
}

void frmCadIdiomas_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->btnNovoClick();
  frmCadIdiomas->NovoDado(ConsSQL->Idioma('N', 
    frmCadIdiomas->edtCodigo->value(),""));
}

void frmCadIdiomas_btnPesquisarClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->PesquisarDados(ConsSQL->Idioma('S', 
    frmCadIdiomas->edtCodigo->value(),""), STR_IDINENC);
}

void frmCadIdiomas_btnAnteriorClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->registroAnterior();	
}

void frmCadIdiomas_btnProximoClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->registroProximo();
}

void frmCadIdiomas_btnSalvarClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->SalvarDados(frmCadIdiomas->ValidaDados(true),
    ConsSQL->Idioma('S', frmCadIdiomas->edtCodigo->value(),""),
    ConsSQL->Idioma('U', frmCadIdiomas->edtCodigo->value(), 
    frmCadIdiomas->edtDescricao->value()),
    ConsSQL->Idioma('I', frmCadIdiomas->edtCodigo->value(), 
    frmCadIdiomas->edtDescricao->value()), true);
}

void frmCadIdiomas_btnExcluirClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->ExcluirDados(frmCadIdiomas->ValidaDados(false),
    ConsSQL->Idioma('D', frmCadIdiomas->edtCodigo->value(),""));
}

void frmCadIdiomas_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->btnLimparClick();
}

void frmCadIdiomas_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadIdiomas->hide();
}

int CfrmCadIdiomas::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadIdiomas->activate();
  }
  return CfrmCadastros::handle(event);
}
