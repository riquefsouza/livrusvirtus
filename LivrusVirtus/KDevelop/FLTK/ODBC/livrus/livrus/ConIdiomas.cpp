#include "Principal.h"
#include "ConIdiomas.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

CfrmConIdiomas *frmConIdiomas;

void frmConIdiomas_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConIdiomas_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConIdiomas_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConIdiomas_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConIdiomas::CfrmConIdiomas()
       : CfrmConsultas(STR_CONIDIOMA) {
	IniciaControles();
}

CfrmConIdiomas::~CfrmConIdiomas() { }

void CfrmConIdiomas::IniciaControles() {
  edtDescricao->label("Idioma:");

  btnPesquisar->callback((Fl_Callback*)frmConIdiomas_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConIdiomas_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConIdiomas_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConIdiomas_btnFecharClick_cb);
}

void frmConIdiomas_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 10, 30 };
  string sRotulos[] = { "Código", "Idioma" };
  frmConIdiomas->PesquisarDados(ConsSQL->Idioma('S',"", 
    frmConIdiomas->edtDescricao->value()), STR_IDINENC, 2, 
    nLarguras, sRotulos);
}

void frmConIdiomas_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConIdiomas->setLabRegistros(b->value());
}

void frmConIdiomas_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConIdiomas->LimparDados();
}

void frmConIdiomas_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConIdiomas->Fecha();
  frmConIdiomas->hide();
}

int CfrmConIdiomas::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
  }
  return CfrmConsultas::handle(event);
}
