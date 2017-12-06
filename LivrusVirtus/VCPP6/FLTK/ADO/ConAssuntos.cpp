#include "Principal.h"
#include "ConAssuntos.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "CadLivros.h"

CfrmConAssuntos *frmConAssuntos;

void frmConAssuntos_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConAssuntos_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConAssuntos_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConAssuntos_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConAssuntos::CfrmConAssuntos(bool bRetSelecionado)
       : CfrmConsultas(STR_CONASSUNTO) {
  bSelecionado = bRetSelecionado;
	IniciaControles();
}

CfrmConAssuntos::~CfrmConAssuntos() { }

void CfrmConAssuntos::IniciaControles() {
  edtDescricao->label("Assunto:");

  btnPesquisar->callback((Fl_Callback*)frmConAssuntos_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConAssuntos_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConAssuntos_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConAssuntos_btnFecharClick_cb);
}

void frmConAssuntos_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 10, 30 };
  string sRotulos[] = { "Código", "Assunto" };
  frmConAssuntos->PesquisarDados(ConsSQL->Assunto('S',"", 
    frmConAssuntos->edtDescricao->value()), STR_ASSNENC, 2, 
    nLarguras, sRotulos);
}

void frmConAssuntos_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConAssuntos->setLabRegistros(b->value());
}

void frmConAssuntos_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConAssuntos->LimparDados();
}

void frmConAssuntos_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConAssuntos->Fecha();
  frmConAssuntos->hide();
}

int CfrmConAssuntos::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConAssuntos::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) {
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      frmCadLivros->edtCodAssunto->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,10).c_str()));
      frmCadLivros_edtCodAssuntoKillFocus_cb(frmCadLivros->edtCodAssunto, NULL);
    } else {
      frmCadLivros->edtCodAssunto->value("");
      frmCadLivros->edtAssunto->value("");
    }
  }
}
