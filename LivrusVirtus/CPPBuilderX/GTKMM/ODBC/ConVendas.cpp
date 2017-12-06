#include "ConVendas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"
#include "xpms/livrus.xpm"

CfrmConVendas * frmConVendas = (CfrmConVendas *) NULL;

CfrmConVendas::CfrmConVendas()
  : Gtk::Window(Gtk::WINDOW_TOPLEVEL) {

  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_title(STR_CONVENLIVRO);
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->set_default_size(480, 330);
  this->property_destroy_with_parent()=true;

  vbox1 = manage(new class Gtk::VBox(false, 0));
  this->add(*vbox1);

  fixed1 = manage(new class Gtk::Fixed());
  vbox1->pack_start(*fixed1, false, true, 0);
  fixed1->set_size_request(-1, 155);

  labDtHrVenda = manage(new class Gtk::Label("Data/Hora Venda: "));
  fixed1->put(*labDtHrVenda, 8, 8);
  labDtHrVenda->set_size_request(120, 16);

  edtDtHrVenda = manage(new class Gtk::Entry());
  fixed1->put(*edtDtHrVenda, 8, 24);
  edtDtHrVenda->set_size_request(158, 24);
  edtDtHrVenda->set_max_length(19);

  btnPesquisar = manage(new class Gtk::Button("_Pesquisar", true));
  fixed1->put(*btnPesquisar, 176, 24);
  btnPesquisar->set_size_request(88, 26);

  edtCPF = manage(new class Gtk::Entry());
  fixed1->put(*edtCPF, 8, 72);
  edtCPF->set_size_request(158, 24);
  edtCPF->set_max_length(14);

  labCPF = manage(new class Gtk::Label("CPF: "));
  fixed1->put(*labCPF, 8, 56);
  labCPF->set_size_request(40, 16);

  edtCliente = manage(new class Gtk::Entry());
  fixed1->put(*edtCliente, 168, 72);
  edtCliente->set_size_request(368, 24);
  #ifdef G_OS_WIN32
    edtCliente->set_sensitive(false);
  #else
    edtCliente->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labCliente = manage(new class Gtk::Label("Cliente: "));
  fixed1->put(*labCliente, 168, 56);
  labCliente->set_size_request(46, 16);

  btnPCliente = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPCliente, 536, 72);
  btnPCliente->set_size_request(25, 25);

  edtISBN = manage(new class Gtk::Entry());
  fixed1->put(*edtISBN, 8, 120);
  edtISBN->set_size_request(158, 24);
  edtISBN->set_max_length(13);

  labISBN = manage(new class Gtk::Label("ISBN: "));
  fixed1->put(*labISBN, 8, 104);
  labISBN->set_size_request(40, 16);

  edtLivro = manage(new class Gtk::Entry());
  fixed1->put(*edtLivro, 168, 120);
  edtLivro->set_size_request(368, 24);
  #ifdef G_OS_WIN32
    edtLivro->set_sensitive(false);
  #else
    edtLivro->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labLivro = manage(new class Gtk::Label("Livro: "));
  fixed1->put(*labLivro, 168, 104);
  labLivro->set_size_request(40, 16);

  btnPLivro = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPLivro, 536, 120);
  btnPLivro->set_size_request(25, 25);

  scrolledwindow1 = manage(new class Gtk::ScrolledWindow());
  scrolledwindow1->set_border_width(1);
  scrolledwindow1->set_policy (Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  scrolledwindow1->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
  vbox1->pack_start(*scrolledwindow1, true, true, 0);

  gridConsulta = manage(new class Gtk::TreeView());
  gridConsulta->set_rules_hint(true);
  selection = gridConsulta->get_selection();
  selection->set_mode(Gtk::SELECTION_SINGLE);
  LSVendas = Rotinas->CriaModeloGrid(gridConsulta);

  scrolledwindow1->add (*gridConsulta);

  hbox1 = manage(new class Gtk::HBox(false, 0));
  vbox1->pack_start(*hbox1, false, false, 0);
  hbox1->set_size_request(-1, 70);

  vbox5 = manage(new class Gtk::VBox(true, 0));
  hbox1->pack_start(*vbox5, true, true, 0);

  fixed4 = manage(new class Gtk::Fixed());
  vbox5->pack_start(*fixed4, false, false, 0);

  labRegistros = manage(new class Gtk::Label("Registro 0 de 0 "));
  fixed4->put(*labRegistros, 8, 8);
  labRegistros->set_size_request(248, 16);
  labRegistros->set_alignment(0, 0.5);

  fixed5 = manage(new class Gtk::Fixed());
  vbox5->pack_start(*fixed5, false, false, 0);

  vbox2 = manage(new class Gtk::VBox(true, 10));
  hbox1->pack_start(*vbox2, false, false, 2);
  vbox2->set_border_width(2);

  fixed3 = manage(new class Gtk::Fixed());
  vbox2->pack_start(*fixed3, true, true, 0);
  fixed3->set_border_width(6);

  edtPrecoTotal = manage(new class Gtk::Entry());
  fixed3->put(*edtPrecoTotal, 128, 0);
  edtPrecoTotal->set_size_request(158, 24);
  #ifdef G_OS_WIN32
    edtPrecoTotal->set_sensitive(false);
  #else
    edtPrecoTotal->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labPrecoTotal = manage(new class Gtk::Label(Rotinas->retUTF8("Preço Total: ")));
  fixed3->put(*labPrecoTotal, 48, 0);
  labPrecoTotal->set_size_request(80, 16);

  hbuttonbox1 = manage(new class Gtk::HButtonBox());
  vbox2->pack_end(*hbuttonbox1, false, false, 0);
  hbuttonbox1->set_border_width(2);
  hbuttonbox1->set_layout(Gtk::BUTTONBOX_END);
  hbuttonbox1->set_spacing(9);

  btnLimpar = manage(new class Gtk::Button("_Limpar", true));
  hbuttonbox1->add(*btnLimpar);
  btnLimpar->set_flags(Gtk::CAN_DEFAULT);

  btnFechar = manage(new class Gtk::Button("_Fechar", true));
  hbuttonbox1->add(*btnFechar);
  btnFechar->set_flags(Gtk::CAN_DEFAULT);

  int nLargura[] = { 120, 100, 220, 100, 280, 80 };
  Glib::ustring sRotulos[] = { "Data/Hora Venda", "CPF", "Cliente",
    "ISBN", "Livro", Rotinas->retUTF8("Preço") };

  Rotinas->AdicionaColunasGrid(gridConsulta, 0, 6, nLargura, sRotulos);

  edtDtHrVenda->set_text(Rotinas->retDataHoraStr(true, true));
  edtDtHrVenda->grab_focus();

  show_all_children();

  edtDtHrVenda->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmConVendas::on_edtDtHrVenda_focus_out_event));
  edtCPF->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmConVendas::on_edtCPF_focus_out_event));
  edtISBN->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmConVendas::on_edtISBN_focus_out_event));
  btnPesquisar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConVendas::on_btnPesquisar_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConVendas::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmConVendas::on_btnFechar_clicked));
  btnPCliente->signal_clicked().connect(SigC::slot(* this,
   & CfrmConVendas::on_btnPCliente_clicked));
  btnPLivro->signal_clicked().connect(SigC::slot(* this,
   & CfrmConVendas::on_btnPLivro_clicked));
  selection->signal_changed().connect(SigC::slot(* this,
   & CfrmConVendas::on_gridConsulta_selection_changed));
}

CfrmConVendas::~CfrmConVendas() {}

Glib::ustring CfrmConVendas::ConsVenda(char sOpcao) {
Glib::ustring sCPF, sISBN, sDTHR, sret, sDataHora;

  sDTHR = edtDtHrVenda->get_text();
  if (sDTHR.length() > 0)
    sDataHora = Rotinas->ConverteDataHoraStr(sDTHR,
      true, "%m/%d/%Y","%H:%M:%S");
  else
    sDataHora.clear();

  sISBN = edtISBN->get_text();
  sCPF = edtCPF->get_text();

  if (sOpcao=='L')
    sret = ConsSQL->Venda('S',"ZERO","","","","");
  else
    sret = ConsSQL->Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");

 return sret;
}

bool CfrmConVendas::on_edtDtHrVenda_focus_out_event(GdkEventFocus* event) {
  if (edtDtHrVenda->get_text().length() > 0) {
  	if (Rotinas->validaDataHora(edtDtHrVenda->get_text(), false)==false) {
      Rotinas->MsgDlg(STR_DTHRINV, Gtk::MESSAGE_ERROR);
      edtDtHrVenda->set_text(Rotinas->retDataHoraStr(true,true));
      edtDtHrVenda->grab_focus();
  	}
  }
  return false;
}

bool CfrmConVendas::on_edtCPF_focus_out_event(GdkEventFocus* event) {
Glib::ustring sCliente;
LISTAMSTR ConsCampo;

  if (edtCPF->get_text().length() > 0) {
  	if (Rotinas->ValidaCPF(edtCPF->get_text())) {
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, "", false,
      ConsSQL->Cliente('S', edtCPF->get_text(),
      "","","","","","","","",""),STR_CLINENC);
      if (sCliente.length()==0) {
        edtCPF->set_text("");
        edtCPF->grab_focus();
      } else
        edtCliente->set_text(sCliente);
  	} else {
      Rotinas->MsgDlg(STR_CPFINV, Gtk::MESSAGE_ERROR);
      edtCPF->set_text("");
      edtCPF->grab_focus();
    }
  } else
     edtCliente->set_text("");

  return false;
}

bool CfrmConVendas::on_edtISBN_focus_out_event(GdkEventFocus *event) {
Glib::ustring sLivro, sQtdEstoque;
int nQtdEstoque;
LISTAMSTR ConsCampo;

  if (edtISBN->get_text().length() > 0) {
  	if (Rotinas->ValidaISBN(edtISBN->get_text())) {
      sLivro = Rotinas->ConsultaCampoDesc(&ConsCampo, "", false,
      ConsSQL->Livro('Q',edtISBN->get_text(),
      "","","","","","","","",""),STR_CLINENC);
      if (sLivro.length()==0) {
        edtISBN->set_text("");
        edtISBN->grab_focus();
      } else {
         edtLivro->set_text(sLivro);

         sQtdEstoque = ConsCampo.col[3][0];
         nQtdEstoque = atoi(sQtdEstoque.c_str());
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = ConsCampo.col[2][0];
           Rotinas_sQtdEstoque = sQtdEstoque;
         } else
           Rotinas->MsgDlg(STR_LIVNEST, Gtk::MESSAGE_ERROR);
      }
  	} else {
      Rotinas->MsgDlg(STR_ISBNINV, Gtk::MESSAGE_ERROR);
      edtISBN->set_text("");
      edtISBN->grab_focus();
    }
  } else
     edtLivro->set_text("");

  return false;
}

void CfrmConVendas::on_btnPCliente_clicked() {
  frmConClientes = new CfrmConClientes();
	frmConClientes->run();
  delete frmConClientes;
  edtCPF->set_text(Rotinas_sCodigoSelecionado);
  on_edtCPF_focus_out_event(NULL);
}

void CfrmConVendas::on_btnPLivro_clicked() {
  frmConLivros = new CfrmConLivros();
	frmConLivros->run();
  delete frmConLivros;
  edtISBN->set_text(Rotinas_sCodigoSelecionado);
  on_edtISBN_focus_out_event(NULL);
}

void CfrmConVendas::on_btnPesquisar_clicked() {
LISTAMSTR ConsTotal;
GString *sPrecoTotal = g_string_new("");
gdouble nPreco;
gchar* fimptr[TAM_MAX_STR];

  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinVendas, ConsVenda('S'))) {
    Rotinas->AdicionaLinhasGrid(LSVendas, &lstLinVendas, 6, true);

    if (Rotinas->ConsultaDadosLista(gConexao, &ConsTotal, ConsVenda('P'))) {
      if (ConsTotal.col[0].size() > 0) {
        nPreco = g_strtod(ConsTotal.col[0][0].c_str(), fimptr);
        g_string_sprintf(sPrecoTotal, "R$ %.2f", nPreco);
        edtPrecoTotal->set_text(sPrecoTotal->str);
        setLabRegistros(0);
      }
    }
  } else
     Rotinas->MsgDlg(STR_VENNENC, Gtk::MESSAGE_ERROR);
}

void CfrmConVendas::on_btnLimpar_clicked() {
  edtCPF->set_text("");
  edtCliente->set_text("");
  edtISBN->set_text("");
  edtLivro->set_text("");
  edtDtHrVenda->set_text(Rotinas->retDataHoraStr(true, true));
  Rotinas->LimpaModeloGrid(LSVendas);
  edtPrecoTotal->set_text("R$ 0,00");
  edtDtHrVenda->grab_focus();
}

void CfrmConVendas::destroy_() {
  frmPrincipal->mnuVendasRealizadas->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmConVendas::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}

void CfrmConVendas::setLabRegistros(int nLinha) {
GString *sTemp = g_string_new("");

  g_string_sprintf(sTemp, "Registro %d de %d", nLinha,
    lstLinVendas.col[0].size());
  labRegistros->set_text(sTemp->str);
}

void CfrmConVendas::on_gridConsulta_selection_changed() {
int nLinha;

  if(const Gtk::TreeIter iter = selection->get_selected()) {
    iter->get_value (0, nLinha);
    setLabRegistros(nLinha);
  }
}
