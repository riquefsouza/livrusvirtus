#include "CadLivros.h"
#include "Principal.h"
#include "Cadastros.h"
#include "ConsultasSQL.h"
#include "ConIdiomas.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

CfrmCadLivros * frmCadLivros = (CfrmCadLivros *) NULL;

CfrmCadLivros::CfrmCadLivros()
  : CfrmCadastros(false, STR_CADLIVRO) {

  this->set_default_size(560, 415);

  labCodigo->set_label("ISBN: ");
  labCodigo->set_alignment(0, 0.5);
  edtCodigo->set_max_length(13);

  labDescricao->set_label(Rotinas->retUTF8("Título: "));
  labDescricao->set_alignment(0, 0.5);
  edtDescricao->set_size_request(352, 24);
  edtDescricao->set_max_length(50);

  edtCodEditora = manage(new class Gtk::Entry());
  fixed1->put(*edtCodEditora, 112, 112);
  edtCodEditora->set_size_request(88, 24);
  edtCodEditora->set_max_length(5);
  edtCodEditora->set_sensitive(false);

  edtEditora = manage(new class Gtk::Entry());
  fixed1->put(*edtEditora, 208, 112);
  edtEditora->set_size_request(232, 24);
  #ifdef G_OS_WIN32
    edtEditora->set_sensitive(false);
  #else
    edtEditora->unset_flags(GTK_CAN_FOCUS);
  #endif

  edtEdicao_adj = manage(new class Gtk::Adjustment(1, 1, 9999, 1, 10, 10));
  edtEdicao = manage(new class Gtk::SpinButton(*edtEdicao_adj, 1, 0));
  fixed1->put(*edtEdicao, 368, 72);
  edtEdicao->set_size_request(96, 24);
  edtEdicao->set_numeric(true);
  edtEdicao->set_sensitive(false);

  labEdicao = manage(new class Gtk::Label(Rotinas->retUTF8("Edição:")));
  fixed1->put(*labEdicao, 368, 56);
  labEdicao->set_size_request( 50, 16);
  labEdicao->set_alignment(0, 0);

  btnPEditora = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPEditora, 440, 112);
  btnPEditora->set_size_request(25, 25);
  btnPEditora->set_sensitive(false);

  labEditora = manage(new class Gtk::Label("Editora:"));
  fixed1->put(*labEditora, 112, 96);
  labEditora->set_size_request(55, 16);

  edtAnoPubli_adj = manage(new class Gtk::Adjustment(1, 1, 9999, 1, 10, 10));
  edtAnoPubli = manage(new class Gtk::SpinButton(*edtAnoPubli_adj, 1, 0));
  fixed1->put(*edtAnoPubli, 8, 112);
  edtAnoPubli->set_size_request(96, 24);
  edtAnoPubli->set_numeric(true);
  edtAnoPubli->set_sensitive(false);

  labIdioma = manage(new class Gtk::Label("Idioma:"));
  fixed1->put(*labIdioma, 112, 136);
  labIdioma->set_size_request(55, 16);
  labIdioma->set_alignment(0, 0);

  labAnoPubli = manage(new class Gtk::Label(Rotinas->retUTF8("Ano Publicação:")));
  fixed1->put(*labAnoPubli, 8, 96);
  labAnoPubli->set_size_request(104, 16);
  labAnoPubli->set_alignment(0, 0);

  edtVolume_adj = manage(new class Gtk::Adjustment(1, 1, 9999, 1, 10, 10));
  edtVolume = manage(new class Gtk::SpinButton(*edtVolume_adj, 1, 0));
  fixed1->put(*edtVolume, 8, 152);
  edtVolume->set_size_request(96, 24);
  edtVolume->set_numeric(true);
  edtVolume->set_sensitive(false);

  labVolume = manage(new class Gtk::Label("Volume:"));
  fixed1->put(*labVolume, 8, 136);
  labVolume->set_size_request(80, 16);
  labVolume->set_alignment(0, 0);

  labNPaginas = manage(new class Gtk::Label(Rotinas->retUTF8("Nº Páginas:")));
  fixed1->put(*labNPaginas, 8, 176);
  labNPaginas->set_size_request(80, 16);
  labNPaginas->set_alignment(0, 0);

  edtNPaginas_adj = manage(new class Gtk::Adjustment(1, 1, 9999, 1, 10, 10));
  edtNPaginas = manage(new class Gtk::SpinButton(*edtNPaginas_adj, 1, 0));
  fixed1->put(*edtNPaginas, 8, 192);
  edtNPaginas->set_size_request(96, 24);
  edtNPaginas->set_numeric(true);
  edtNPaginas->set_sensitive(false);

  labAssunto = manage(new class Gtk::Label("Assunto:"));
  fixed1->put(*labAssunto, 112, 176);
  labAssunto->set_size_request(80, 16);
  labAssunto->set_alignment(0, 0);

  edtCodAssunto = manage(new class Gtk::Entry());
  fixed1->put(*edtCodAssunto, 112, 192);
  edtCodAssunto->set_size_request(88, 24);
  edtCodAssunto->set_max_length(10);
  edtCodAssunto->set_sensitive(false);

  edtAssunto = manage(new class Gtk::Entry());
  fixed1->put(*edtAssunto, 208, 192);
  edtAssunto->set_size_request(200, 24);
  #ifdef G_OS_WIN32
    edtAssunto->set_sensitive(false);
  #else
    edtAssunto->unset_flags(Gtk::CAN_FOCUS);
  #endif

  btnPAssunto = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPAssunto, 440, 192);
  btnPAssunto->set_size_request(25, 25);
  btnPAssunto->set_sensitive(false);

  btnAdAssuntos = manage(new class Gtk::Button("+"));
  fixed1->put(*btnAdAssuntos, 408, 192);
  btnAdAssuntos->set_size_request(25, 25);
  btnAdAssuntos->set_sensitive(false);

  scrolledwindow1 = manage(new class Gtk::ScrolledWindow());
  scrolledwindow1->set_border_width(1);
  scrolledwindow1->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  scrolledwindow1->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
  fixed1->put(*scrolledwindow1, 112, 218);

  lstAssuntos = manage(new class Gtk::TreeView());
  scrolledwindow1->add(*lstAssuntos);
  lstAssuntos->set_size_request(296, 54);
  selection = lstAssuntos->get_selection();
  selection->set_mode(Gtk::SELECTION_SINGLE);
  lstAssuntos->set_rules_hint(true);
  LSAssuntos = Rotinas->CriaModeloGrid(lstAssuntos);

  edtPreco = manage(new class Gtk::Entry());
  fixed1->put(*edtPreco, 8, 248);
  edtPreco->set_size_request(96, 24);
  edtPreco->set_max_length(7);
  edtPreco->set_sensitive(false);

  labPreco = manage(new class Gtk::Label(Rotinas->retUTF8("Preço:")));
  fixed1->put(*labPreco, 8, 232);
  labPreco->set_size_request(80, 16);
  labPreco->set_alignment(0, 0);

  labQtdEstoque = manage(new class Gtk::Label("Qtd.Estoque:"));
  fixed1->put(*labQtdEstoque, 8, 272);
  labQtdEstoque->set_size_request(104, 16);
  labQtdEstoque->set_alignment(0, 0);

  edtQtdEstoque_adj = manage(new class Gtk::Adjustment(0, 0, 9999, 1, 10, 10));
  edtQtdEstoque = manage(new class Gtk::SpinButton(*edtQtdEstoque_adj, 1, 0));
  fixed1->put(*edtQtdEstoque, 8, 288);
  edtQtdEstoque->set_size_request(96, 24);
  edtQtdEstoque->set_numeric(true);
  edtQtdEstoque->set_sensitive(false);

  labAutor = manage(new class Gtk::Label("Autor:"));
  fixed1->put(*labAutor, 112, 272);
  labAutor->set_size_request(64, 16);
  labAutor->set_alignment(0, 0);

  edtCodAutor = manage(new class Gtk::Entry());
  fixed1->put(*edtCodAutor, 112, 288);
  edtCodAutor->set_size_request(88, 24);
  edtCodAutor->set_max_length(10);
  edtCodAutor->set_sensitive(false);

  edtAutor = manage(new class Gtk::Entry());
  fixed1->put(*edtAutor, 208, 288);
  edtAutor->set_size_request(200, 24);
  #ifdef G_OS_WIN32
    edtAutor->set_sensitive(false);
  #else
    edtAutor->unset_flags(Gtk::CAN_FOCUS);
  #endif

  btnAdAutores = manage(new class Gtk::Button("+"));
  fixed1->put(*btnAdAutores, 408, 288);
  btnAdAutores->set_size_request(25, 25);
  btnAdAutores->set_sensitive(false);

  btnPAutor = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPAutor, 440, 288);
  btnPAutor->set_size_request(25, 25);
  btnPAutor->set_sensitive(false);

  scrolledwindow2 = manage(new class Gtk::ScrolledWindow());
  scrolledwindow2->set_border_width(1);
  scrolledwindow2->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  scrolledwindow2->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
  fixed1->put(*scrolledwindow2, 112, 312);

  lstAutores = manage(new class Gtk::TreeView());
  scrolledwindow2->add(*lstAutores);
  lstAutores->set_size_request(296, 54);
  selection = lstAutores->get_selection();
  selection->set_mode(Gtk::SELECTION_SINGLE);
  lstAutores->set_rules_hint(true);
  LSAutores = Rotinas->CriaModeloGrid(lstAutores);

  cmbIdioma = manage(new class Gtk::Combo());
  fixed1->put(*cmbIdioma, 112, 152);
  cmbIdioma->set_size_request(352, 26);
  cmbIdioma->set_sensitive(false);

  cmbIdiomaEntrada = cmbIdioma->get_entry();
  cmbIdiomaEntrada->set_editable(false);

  IniciaBotoes(464, 10, 197, 380);

  int nLargura[] = { 180 };
  Glib::ustring sRotulos[] = { "Item" };
  lstAssuntos->set_headers_visible(false);
  Rotinas->AdicionaColunasGrid(lstAssuntos, 0, 1, nLargura, sRotulos);
  lstAutores->set_headers_visible(false);
  Rotinas->AdicionaColunasGrid(lstAutores, 0, 1, nLargura, sRotulos);
  AdicionaCombo();

  show_all_children();

  edtCodigo->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_edtCodigo_focus_out_event));
  btnNovo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnNovo_clicked));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnPesquisar_clicked));
  btnAnterior->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnAnterior_clicked));
  btnProximo->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnProximo_clicked));
  btnSalvar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnSalvar_clicked));
  btnExcluir->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnExcluir_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnFechar_clicked));

  btnPEditora->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnPEditora_clicked));
  btnPAssunto->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnPAssunto_clicked));
  btnAdAssuntos->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnAdAssuntos_clicked));
  btnPAutor->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnPAutor_clicked));
  btnAdAutores->signal_clicked().connect(SigC::slot(* this,
   & CfrmCadLivros::on_btnAdAutores_clicked));
  edtCodEditora->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_edtCodEditora_focus_out_event));
  edtPreco->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_edtPreco_focus_out_event));
  edtCodAssunto->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_edtCodAssunto_focus_out_event));
  edtCodAutor->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_edtCodAutor_focus_out_event));
  lstAssuntos->signal_button_press_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_lstAssuntos_button_press_event));
  lstAutores->signal_button_press_event().connect(SigC::slot(* this,
   & CfrmCadLivros::on_lstAutores_button_press_event));
}

CfrmCadLivros::~CfrmCadLivros() {}

bool CfrmCadLivros::ValidaDados(bool bTodosDados) {
int nQtdLinhas;
  if (Rotinas->ValidaCampo(edtCodigo->get_text(), STR_ISBNNINF))
 	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_TITNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtDescricao->get_text(), STR_EDTNINF))
  		return false;
    Rotinas->PesquisaContaItemGrid(LSAssuntos, "", &nQtdLinhas);
    if (nQtdLinhas==0) {
      Rotinas->MsgDlg(STR_ASSNINF, Gtk::MESSAGE_ERROR);
      return false;
    }
    Rotinas->PesquisaContaItemGrid(LSAutores, "", &nQtdLinhas);
    if (nQtdLinhas==0) {
      Rotinas->MsgDlg(STR_AUTNINF, Gtk::MESSAGE_ERROR);
      return false;
    }
	}
	return true;
}

bool CfrmCadLivros::on_edtCodigo_focus_out_event(GdkEventFocus* event) {
  if (edtCodigo->get_text().length() > 0) {
    if (Rotinas->ValidaISBN(edtCodigo->get_text())==false) {
      Rotinas->MsgDlg(STR_ISBNINV, Gtk::MESSAGE_ERROR);
      edtCodigo->set_text("");
      edtCodigo->grab_focus();
    }
  }
  return false;
}

void CfrmCadLivros::on_btnNovo_clicked(){
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
}

void CfrmCadLivros::on_btnPesquisar_clicked() {
  if (PesquisarDados(ConsSQL->Livro('S', edtCodigo->get_text(),
    "","","","","","","","",""), STR_LIVNENC)) {
    InformaLimpaDados(true);
    HabilitaDados(true);
  }
}

void CfrmCadLivros::on_btnAnterior_clicked() {
  if (registroAnterior())
    InformaLimpaDados(true);
}

void CfrmCadLivros::on_btnProximo_clicked() {
  if (registroProximo())
    InformaLimpaDados(true);
}

void CfrmCadLivros::on_btnSalvar_clicked() {
Glib::ustring sCodIdioma, sSqlInsert, sSqlUpdate;
int nPos;

  nPos = retIdioma(cmbIdiomaEntrada->get_text());
  sCodIdioma = slIdiomas.col[nPos];

  sSqlUpdate = ConsSQL->Livro('U', edtCodigo->get_text(),
    edtDescricao->get_text(), edtEdicao->get_text(),
    edtAnoPubli->get_text(), edtVolume->get_text(),
    edtCodEditora->get_text(), sCodIdioma, edtNPaginas->get_text(),
    Rotinas->VirgulaParaPonto(edtPreco->get_text(),false),
    edtQtdEstoque->get_text());

  sSqlInsert = ConsSQL->Livro('I', edtCodigo->get_text(),
    edtDescricao->get_text(), edtEdicao->get_text(),
    edtAnoPubli->get_text(), edtVolume->get_text(),
    edtCodEditora->get_text(), sCodIdioma, edtNPaginas->get_text(),
    Rotinas->VirgulaParaPonto(edtPreco->get_text(),false),
    edtQtdEstoque->get_text());

  if (SalvarDados(ValidaDados(true),
    ConsSQL->Livro('S', edtCodigo->get_text(),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, false)) {
    SalvaLista('A');
    SalvaLista('B');
    btnLimparClick();
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
}

void CfrmCadLivros::on_btnExcluir_clicked() {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Livro('D', edtCodigo->get_text(),
    "","","","","","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);
  }
}

void CfrmCadLivros::on_btnLimpar_clicked() {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
}

void CfrmCadLivros::destroy_() {
  frmPrincipal->tlbLivro->set_sensitive(true);
  frmPrincipal->mnuCadLivros->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmCadLivros::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}

void CfrmCadLivros::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtEdicao->set_text(lstRegistros.col[2][nLinhaRegistro]);
    edtAnoPubli->set_text(lstRegistros.col[3][nLinhaRegistro]);
    edtVolume->set_text(lstRegistros.col[4][nLinhaRegistro]);
    edtCodEditora->set_text(lstRegistros.col[5][nLinhaRegistro]);
    edtEditora->set_text(lstRegistros.col[6][nLinhaRegistro]);
    AtribuiIdioma(lstRegistros.col[7][nLinhaRegistro]);
    edtNPaginas->set_text(lstRegistros.col[9][nLinhaRegistro]);
    edtPreco->set_text(Rotinas->VirgulaParaPonto(
      lstRegistros.col[10][nLinhaRegistro], true));
    edtQtdEstoque->set_text(lstRegistros.col[11][nLinhaRegistro]);
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAss('S',
      edtCodigo->get_text(), ""), LSAssuntos);
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAut('S',
      edtCodigo->get_text(), ""), LSAutores);
  } else {
    edtEdicao->set_text("1");
    edtAnoPubli->set_text(Rotinas->retDataHoraStr(true,false).substr(6,4));
    edtVolume->set_text("1");
    edtCodEditora->set_text("");
    edtEditora->set_text("");
    cmbIdiomaEntrada->set_text(listCmbIdioma[0]);
    edtNPaginas->set_text("1");
    edtPreco->set_text("0,00");
    edtQtdEstoque->set_text("1");
    edtCodAssunto->set_text("");
    Rotinas->LimpaModeloGrid(LSAssuntos);
    edtCodAutor->set_text("");
    Rotinas->LimpaModeloGrid(LSAutores);
  }
}

void CfrmCadLivros::HabilitaDados(bool bHabilita) {
  edtEdicao->set_sensitive(bHabilita);
  edtAnoPubli->set_sensitive(bHabilita);
  edtVolume->set_sensitive(bHabilita);
  edtCodEditora->set_sensitive(bHabilita);
  btnPEditora->set_sensitive(bHabilita);
  cmbIdioma->set_sensitive(bHabilita);
  edtNPaginas->set_sensitive(bHabilita);
  edtPreco->set_sensitive(bHabilita);
  edtQtdEstoque->set_sensitive(bHabilita);
  edtCodAssunto->set_sensitive(bHabilita);
  btnPAssunto->set_sensitive(bHabilita);
  btnAdAssuntos->set_sensitive(bHabilita);
  lstAssuntos->set_sensitive(bHabilita);
  edtCodAutor->set_sensitive(bHabilita);
  btnPAutor->set_sensitive(bHabilita);
  btnAdAutores->set_sensitive(bHabilita);
  lstAutores->set_sensitive(bHabilita);
}

void CfrmCadLivros::AdicionaCombo()
{
  LISTAMSTR Campos;
  int nLinha;

  if (Rotinas->ConsultaDadosLista(gConexao, &Campos,
    ConsSQL->Idioma('S',"",""))) {
    for (nLinha = 0; nLinha < abs(Campos.col[0].size()); nLinha++) {
	    slIdiomas.col.push_back(Campos.col[0][nLinha]);
      listCmbIdioma.push_back(Campos.col[1][nLinha]);
	  }
    cmbIdioma->set_popdown_strings(listCmbIdioma);
  }
}

void CfrmCadLivros::AtribuiIdioma(Glib::ustring sIdioma) {
int nCont;

 for (nCont=0; nCont < abs(slIdiomas.col.size()); nCont++) {
   if (slIdiomas.col[nCont] == sIdioma) {
     cmbIdiomaEntrada->set_text(listCmbIdioma[nCont]);
     break;
   }
 }
}

int CfrmCadLivros::retIdioma(Glib::ustring sIdioma) {
int nCont;

 for (nCont=0; nCont < abs(listCmbIdioma.size()); nCont++) {
   if (listCmbIdioma[nCont] == sIdioma)
     break;
 }
 return nCont;
}

void CfrmCadLivros::SalvaLista(char sOpcao) {
int nCont;
Glib::ustring sCod, sISBN;

  sISBN = edtCodigo->get_text();
  if (sOpcao=='A') {
    Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('D',sISBN,""));

    if (!LSAssuntos->children().empty()) {
      for (nCont=0; nCont < LSAssuntos->children().size(); nCont++) {
        //LSAssuntos->children()[nCont]->get_value(1, sDesc);
        LSAssuntos->children()[nCont]->get_value(2, sCod);
        Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAss('I', sISBN, sCod));
      }
    }
  } else if (sOpcao=='B') {
  	Rotinas->AtualizaDados(gConexao,ConsSQL->LivroAut('D',sISBN,""));

    if (!LSAutores->children().empty()) {
      for (nCont=0; nCont < LSAutores->children().size(); nCont++) {
        //LSAutores->children()[nCont]->get_value(1, sDesc);
        LSAutores->children()[nCont]->get_value(2, sCod);
        Rotinas->AtualizaDados(gConexao, ConsSQL->LivroAut('I', sISBN, sCod));
      }
    }
  }
}

bool CfrmCadLivros::on_edtPreco_focus_out_event(GdkEventFocus * event) {
  if (edtPreco->get_text().length() > 0) {
    if (Rotinas->ValidaFloat(
          Rotinas->VirgulaParaPonto(edtPreco->get_text(),false)))
      edtPreco->set_text(
        Rotinas->VirgulaParaPonto(edtPreco->get_text(), true));
    else {
      edtPreco->set_text("0,01");
      edtPreco->grab_focus();
    }
  }
  return false;
}

void CfrmCadLivros::on_btnPEditora_clicked() {
  frmConEditoras = new CfrmConEditoras();
	frmConEditoras->run();
  delete frmConEditoras;
  edtCodEditora->set_text(Rotinas_sCodigoSelecionado);
  on_edtCodEditora_focus_out_event(NULL);
}

void CfrmCadLivros::on_btnPAssunto_clicked() {
  frmConAssuntos = new CfrmConAssuntos();
	frmConAssuntos->run();
  delete frmConAssuntos;
  edtCodAssunto->set_text(Rotinas_sCodigoSelecionado);
  on_edtCodAssunto_focus_out_event(NULL);
}

void CfrmCadLivros::on_btnAdAssuntos_clicked() {
  Rotinas->AdicionaItemLista(LSAssuntos, edtCodAssunto, edtAssunto);
}

void CfrmCadLivros::on_btnPAutor_clicked() {
  frmConAutores = new CfrmConAutores();
	frmConAutores->run();
  delete frmConAutores;
  edtCodAutor->set_text(Rotinas_sCodigoSelecionado);
  on_edtCodAutor_focus_out_event(NULL);
}

void CfrmCadLivros::on_btnAdAutores_clicked() {
  Rotinas->AdicionaItemLista(LSAutores, edtCodAutor, edtAutor);
}

bool CfrmCadLivros::on_edtCodEditora_focus_out_event(
			      GdkEventFocus *event) {
  Glib::ustring sEditora;
  LISTAMSTR ConsCampo;

  if (edtCodEditora->get_text().length() > 0) {
    sEditora = Rotinas->ConsultaCampoDesc(&ConsCampo,
      edtCodEditora->get_text(), true,
      ConsSQL->Editora('S',edtCodEditora->get_text(),""),STR_EDTNENC);
    if (sEditora.length() > 0)
      edtEditora->set_text(sEditora);
    else {
      edtCodEditora->set_text("");
      edtCodEditora->grab_focus();
    }
  } else
    edtEditora->set_text("");

  return false;
}

bool CfrmCadLivros::on_edtCodAssunto_focus_out_event(
			      GdkEventFocus *event) {
  Glib::ustring sAssunto;
  LISTAMSTR ConsCampo;

  if (edtCodAssunto->get_text().length() > 0) {
    sAssunto = Rotinas->ConsultaCampoDesc(&ConsCampo,
      edtCodAssunto->get_text(), true,
      ConsSQL->Assunto('S',edtCodAssunto->get_text(),""),STR_ASSNENC);
    if (sAssunto.length() > 0)
      edtAssunto->set_text(sAssunto);
    else {
      edtCodAssunto->set_text("");
      edtCodAssunto->grab_focus();
    }
  } else
    edtAssunto->set_text("");

  return false;
}

bool CfrmCadLivros::on_edtCodAutor_focus_out_event(
			      GdkEventFocus *event) {
  Glib::ustring sAutor;
  LISTAMSTR ConsCampo;

  if (edtCodAutor->get_text().length() > 0) {
    sAutor = Rotinas->ConsultaCampoDesc(&ConsCampo,
      edtCodAutor->get_text(), true,
      ConsSQL->Autor('S',edtCodAutor->get_text(),""),STR_AUTNENC);
    if (sAutor.length() > 0)
      edtAutor->set_text(sAutor);
    else {
      edtCodAutor->set_text("");
      edtCodAutor->grab_focus();
    }
  } else
    edtAutor->set_text("");

  return false;
}

bool CfrmCadLivros::on_lstAssuntos_button_press_event(GdkEventButton *event) {
//  if (event->button == Gdk::DOUBLE_BUTTON_PRESS)
    Rotinas->RemoveItemLista(lstAssuntos, LSAssuntos);
  return false;
}

bool CfrmCadLivros::on_lstAutores_button_press_event(GdkEventButton *event) {
  if (event->button == Gdk::DOUBLE_BUTTON_PRESS)
    Rotinas->RemoveItemLista(lstAutores, LSAutores);
  return false;
}
