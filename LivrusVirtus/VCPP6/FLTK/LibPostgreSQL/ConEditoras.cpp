#include "Principal.h"
#include "ConEditoras.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "CadLivros.h"

CfrmConEditoras *frmConEditoras;

void frmConEditoras_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConEditoras_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConEditoras_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConEditoras_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConEditoras::CfrmConEditoras(bool bRetSelecionado)
       : CfrmConsultas(STR_CONEDITORA) {
  bSelecionado = bRetSelecionado;
	IniciaControles();
}

CfrmConEditoras::~CfrmConEditoras() { }

void CfrmConEditoras::IniciaControles() {
  edtDescricao->label("Editora:");

  btnPesquisar->callback((Fl_Callback*)frmConEditoras_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConEditoras_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConEditoras_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConEditoras_btnFecharClick_cb);
}

void frmConEditoras_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 10, 30 };
  string sRotulos[] = { "Código", "Editora" };
  frmConEditoras->PesquisarDados(ConsSQL->Editora('S',"", 
    frmConEditoras->edtDescricao->value()), STR_EDTNENC, 2, 
    nLarguras, sRotulos);
}

void frmConEditoras_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConEditoras->setLabRegistros(b->value());
}

void frmConEditoras_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConEditoras->LimparDados();
}

void frmConEditoras_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConEditoras->Fecha();
  frmConEditoras->hide();
}

int CfrmConEditoras::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConEditoras::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) { 
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      frmCadLivros->edtCodEditora->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,10).c_str()));
      frmCadLivros_edtCodEditoraKillFocus_cb(frmCadLivros->edtCodEditora, NULL);
    } else {
      frmCadLivros->edtCodEditora->value("");
      frmCadLivros->edtEditora->value("");
    }
  }
}
