#include "Principal.h"
#include "ConProfissoes.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "CadClientes.h"

CfrmConProfissoes *frmConProfissoes;

void frmConProfissoes_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConProfissoes_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConProfissoes_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConProfissoes_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConProfissoes::CfrmConProfissoes(bool bRetSelecionado)
       : CfrmConsultas(STR_CONPROFISS) {
  bSelecionado = bRetSelecionado;
	IniciaControles();
}

CfrmConProfissoes::~CfrmConProfissoes() { }

void CfrmConProfissoes::IniciaControles() {
  edtDescricao->label("Profissao:");

  btnPesquisar->callback((Fl_Callback*)frmConProfissoes_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConProfissoes_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConProfissoes_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConProfissoes_btnFecharClick_cb);
}

void frmConProfissoes_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 10, 30 };
  string sRotulos[] = { "Código", "Profissao" };
  frmConProfissoes->PesquisarDados(ConsSQL->Profissao('S',"", 
    frmConProfissoes->edtDescricao->value()), STR_PROFNENC, 2, 
    nLarguras, sRotulos);
}

void frmConProfissoes_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConProfissoes->setLabRegistros(b->value());
}

void frmConProfissoes_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConProfissoes->LimparDados();
}

void frmConProfissoes_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConProfissoes->Fecha();
  frmConProfissoes->hide();
}

int CfrmConProfissoes::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConProfissoes::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) { 
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      frmCadClientes->edtCodProfissao->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,10).c_str()));
      frmCadClientes_edtCodProfissaoKillFocus_cb(
        frmCadClientes->edtCodProfissao, NULL);
    } else {
      frmCadClientes->edtCodProfissao->value("");
      frmCadClientes->edtProfissao->value("");
    }
  }
}
