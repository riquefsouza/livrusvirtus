#include "Principal.h"
#include "ConClientes.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "VenderLivros.h"
#include "ConVendas.h"

CfrmConClientes *frmConClientes;

void frmConClientes_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConClientes_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConClientes_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConClientes_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConClientes::CfrmConClientes(int nRetSelecionado)
       : CfrmConsultas(STR_CONCLIENTE) {
  nSelecionado = nRetSelecionado;
	IniciaControles();
}

CfrmConClientes::~CfrmConClientes() { }

void CfrmConClientes::IniciaControles() {
  edtDescricao->label("Cliente:");

  btnPesquisar->callback((Fl_Callback*)frmConClientes_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConClientes_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConClientes_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConClientes_btnFecharClick_cb);
}

void frmConClientes_btnPesquisarClick_cb(Fl_Button* b, void* v){
 int nLarguras[] = { 14,30,30,10,5,17,19,12,40,15,
          8,30,20,8,50,13,30 };
 string sRotulos[] = { "CPF", "Nome", "Email", "Identidade", "Sexo", 
   "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
   "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
   "CodProfissão", "Profissão" };
  frmConClientes->PesquisarDados(ConsSQL->Cliente('S',"",
    frmConClientes->edtDescricao->value(),
    "","","","","","","",""), STR_CLINENC, 17, 
    nLarguras, sRotulos);
}

void frmConClientes_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConClientes->setLabRegistros(b->value());
}

void frmConClientes_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConClientes->LimparDados();
}

void frmConClientes_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConClientes->Fecha();
  frmConClientes->hide();
}

int CfrmConClientes::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConClientes::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (bSelecionado) {
    if (Rotinas_sCodigoSelecionado.length() > 0) {
      if (nSelecionado==1) {
        frmVenderLivros->edtCPF->value(
          Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,14).c_str()));
        frmVenderLivros_edtCPFKillFocus_cb(
          frmVenderLivros->edtCPF, NULL);
      } else if (nSelecionado==2) {
        frmConVendas->edtCPF->value(
          Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,14).c_str()));
        frmConVendas_edtCPFKillFocus_cb(
          frmConVendas->edtCPF, NULL);
      }
    } else {
      if (nSelecionado==1) {
        frmVenderLivros->edtCPF->value("");
        frmVenderLivros->edtCliente->value("");
      } else if (nSelecionado==2) {
        frmConVendas->edtCPF->value("");
        frmConVendas->edtCliente->value("");
      }
    }
  }
}
