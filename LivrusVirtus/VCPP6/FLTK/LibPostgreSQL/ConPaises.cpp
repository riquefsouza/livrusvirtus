#include "Principal.h"
#include "ConPaises.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "CadClientes.h"

CfrmConPaises *frmConPaises;

void frmConPaises_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConPaises_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConPaises_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConPaises_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConPaises::CfrmConPaises(bool bRetSelecionado)
       : CfrmConsultas(STR_CONPAIS) {
  bSelecionado = bRetSelecionado;
	IniciaControles();
}

CfrmConPaises::~CfrmConPaises() { }

void CfrmConPaises::IniciaControles() {
  edtDescricao->label("Pais:");

  btnPesquisar->callback((Fl_Callback*)frmConPaises_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConPaises_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConPaises_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConPaises_btnFecharClick_cb);
}

void frmConPaises_btnPesquisarClick_cb(Fl_Button* b, void* v){
int nLarguras[] = { 10, 30 };
string sRotulos[] = { "Código", "Pais" };

  frmConPaises->PesquisarDados(ConsSQL->Pais('S',"", 
    frmConPaises->edtDescricao->value()), STR_PAISNENC, 2, 
    nLarguras, sRotulos);
}

void frmConPaises_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConPaises->setLabRegistros(b->value());
}

void frmConPaises_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConPaises->LimparDados();
}

void frmConPaises_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConPaises->Fecha();
  frmConPaises->hide();
}

int CfrmConPaises::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConPaises::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) { 
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      frmCadClientes->edtCodPais->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,3).c_str()));
      frmCadClientes_edtCodPaisKillFocus_cb(
        frmCadClientes->edtCodPais, NULL);
    } else {
      frmCadClientes->edtCodPais->value("");
      frmCadClientes->edtPais->value("");
    }
  }
}
