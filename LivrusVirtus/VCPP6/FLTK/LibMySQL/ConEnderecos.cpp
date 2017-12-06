#include "Principal.h"
#include "ConEnderecos.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "CadClientes.h"

CfrmConEnderecos *frmConEnderecos;

void frmConEnderecos_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConEnderecos_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConEnderecos_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConEnderecos_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConEnderecos::CfrmConEnderecos(bool bRetSelecionado)
       : CfrmConsultas(STR_CONENDERECO) {
  bSelecionado = bRetSelecionado;
	IniciaControles();
}

CfrmConEnderecos::~CfrmConEnderecos() { }

void CfrmConEnderecos::IniciaControles() {
  edtDescricao->label("Endereco:");

  btnPesquisar->callback((Fl_Callback*)frmConEnderecos_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConEnderecos_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConEnderecos_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConEnderecos_btnFecharClick_cb);
}

void frmConEnderecos_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 10,40,15,8,30,20 };
  string sRotulos[] = { "Código", "Logradouro", "Bairro", 
    "CEP", "Cidade", "Estado" };
  frmConEnderecos->PesquisarDados(ConsSQL->Endereco('S',"",
    frmConEnderecos->edtDescricao->value(),"","","",""), STR_ENDNENC, 6, 
    nLarguras, sRotulos);
}

void frmConEnderecos_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConEnderecos->setLabRegistros(b->value());
}

void frmConEnderecos_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConEnderecos->LimparDados();
}

void frmConEnderecos_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConEnderecos->Fecha();
  frmConEnderecos->hide();
}

int CfrmConEnderecos::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConEnderecos::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) { 
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      frmCadClientes->edtCodEndereco->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,10).c_str()));
      frmCadClientes_edtCodEnderecoKillFocus_cb(
        frmCadClientes->edtCodEndereco, NULL);
    } else {
      frmCadClientes->edtCodEndereco->value("");
      frmCadClientes->edtLogradouro->value("");
      frmCadClientes->edtBairro->value("");
      frmCadClientes->edtCep->value("");
	    frmCadClientes->edtCidade->value("");
	    frmCadClientes->edtEstado->value("");
    }
  }
}
