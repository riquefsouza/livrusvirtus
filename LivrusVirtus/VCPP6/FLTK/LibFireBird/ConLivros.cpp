#include "Principal.h"
#include "ConLivros.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "VenderLivros.h"
#include "ConVendas.h"

CfrmConLivros *frmConLivros;

void frmConLivros_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmConLivros_gridConsultaSelect_cb(Fl_Browser* b, void* v);
void frmConLivros_btnLimparClick_cb(Fl_Button* b, void* v);
void frmConLivros_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmConLivros::CfrmConLivros(int nRetSelecionado)
       : CfrmConsultas(STR_CONLIVRO) {
  nSelecionado = nRetSelecionado;
	IniciaControles();
}

CfrmConLivros::~CfrmConLivros() { }

void CfrmConLivros::IniciaControles() {
  edtDescricao->label("Livro:");

  btnPesquisar->callback((Fl_Callback*)frmConLivros_btnPesquisarClick_cb);
  gridConsulta->callback((Fl_Callback*)frmConLivros_gridConsultaSelect_cb);
  btnLimpar->callback((Fl_Callback*)frmConLivros_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmConLivros_btnFecharClick_cb);
}

void frmConLivros_btnPesquisarClick_cb(Fl_Button* b, void* v){
  int nLarguras[] = { 13, 50, 10,15,10,11,30,10,30,11,10,10 };
  string sRotulos[] = { "ISBN", "Título", "Edição", "AnoPublicação", 
    "Volume", "CodEditora", "Editora", "CodIdioma", "Idioma",
    "NumPáginas", "Preço", "Estoque" };
  frmConLivros->PesquisarDados(ConsSQL->Livro('S',"",    
    frmConLivros->edtDescricao->value(),
    "","","","","","","",""), STR_LIVNENC, 12, 
    nLarguras, sRotulos);
}

void frmConLivros_gridConsultaSelect_cb(Fl_Browser* b, void* v){
  frmConLivros->setLabRegistros(b->value());
}

void frmConLivros_btnLimparClick_cb(Fl_Button* b, void* v){
  frmConLivros->LimparDados();
}

void frmConLivros_btnFecharClick_cb(Fl_Button* b, void* v){
  frmConLivros->Fecha();
  frmConLivros->hide();
}

int CfrmConLivros::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    setSelecionado();
  }
  return CfrmConsultas::handle(event);
}

void CfrmConLivros::setSelecionado() {
  /* necessário pois não existe dialogs na FLTK */
  if (Rotinas_sCodigoSelecionado.length() > 0) {
    if (nSelecionado==1) {
      frmVenderLivros->edtISBN->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,13).c_str()));
      frmVenderLivros_edtISBNKillFocus_cb(
        frmVenderLivros->edtISBN, NULL);
    } else if (nSelecionado==2) {
      frmConVendas->edtISBN->value(
        Rotinas->trim(Rotinas_sCodigoSelecionado.substr(2,13).c_str()));
      frmConVendas_edtISBNKillFocus_cb(
        frmConVendas->edtISBN, NULL);
    }
  } else {
    if (nSelecionado==1) {
      frmVenderLivros->edtISBN->value("");
      frmVenderLivros->edtLivro->value("");
    } else if (nSelecionado==2) {
      frmConVendas->edtISBN->value("");
      frmConVendas->edtLivro->value("");
    }
  }
}
