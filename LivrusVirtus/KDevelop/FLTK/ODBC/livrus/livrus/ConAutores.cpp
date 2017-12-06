#include "Principal.h"
#include "ConAutores.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "CadLivros.h"

CfrmConAutores *frmConAutores;

void frmConAutores_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConAutores_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConAutores_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConAutores_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConAutores::CfrmConAutores(bool bRetSelecionado)
       : CfrmConsultas(STR_CONAUTOR) {
  bSelecionado = bRetSelecionado;
	IniciaControles();
}

CfrmConAutores::~CfrmConAutores() { }

void CfrmConAutores::IniciaControles() {
  edtDescricao->label("Autor:");

  btnPesquisar->callback((Fl_Callback*)frmConAutores_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConAutores_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConAutores_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConAutores_btnFecharClick_cb);
}

void frmConAutores_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 10, 30 };
  string sRotulos[] = { "Código", "Autor" };
  frmConAutores->PesquisarDados(ConsSQL->Autor('S',"", 
    frmConAutores->edtDescricao->value()), STR_AUTNENC, 2, 
    nLarguras, sRotulos);
}

void frmConAutores_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConAutores->setLabRegistros(b->value());
}

void frmConAutores_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConAutores->LimparDados();
}

void frmConAutores_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConAutores->Fecha();
  frmConAutores->hide();
}

int CfrmConAutores::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConAutores::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) {
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      frmCadLivros->edtCodAutor->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,10).c_str()));
      frmCadLivros_edtCodAutorKillFocus_cb(frmCadLivros->edtCodAutor, NULL);
    } else {
      frmCadLivros->edtCodAutor->value("");
      frmCadLivros->edtAutor->value("");
    }
  }
}
