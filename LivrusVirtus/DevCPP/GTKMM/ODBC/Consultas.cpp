#include "Consultas.h"
#include "xpms/livrus.xpm"

CfrmConsultas * frmConsultas = (CfrmConsultas *) NULL;

CfrmConsultas::CfrmConsultas(Glib::ustring sTitulo) : Gtk::Dialog() {
  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_title(Rotinas->retUTF8(sTitulo));
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->set_modal(true);
  this->set_resizable(true);
  this->set_default_size(400, 300);
  this->property_destroy_with_parent()=true;
  this->set_has_separator(false);
  this->set_type_hint(Gdk::WINDOW_TYPE_HINT_DIALOG);

  vbox1 = this->get_vbox();

  fixed1 = manage(new class Gtk::Fixed());
  vbox1->pack_start(*fixed1, false, true, 0);
  fixed1->set_size_request(-1, 60);

  edtDescricao = manage(new class Gtk::Entry());
  fixed1->put(*edtDescricao, 8, 24);
  edtDescricao->set_size_request(312, 24);

  labDescricao = manage(new class Gtk::Label(Rotinas->retUTF8("Descrição:")));
  fixed1->put(*labDescricao, 8, 8);
  labDescricao->set_size_request(80, 16);
  labDescricao->set_alignment(0, 0.5);

  btnPesquisar = manage(new class Gtk::Button("_Pesquisar", true));
  fixed1->put(*btnPesquisar, 328, 24);
  btnPesquisar->set_size_request(85, 28);

  scrolledwindow1 = manage(new class Gtk::ScrolledWindow());
  scrolledwindow1->set_border_width(1);
  scrolledwindow1->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  scrolledwindow1->set_shadow_type(Gtk::SHADOW_ETCHED_IN);
  vbox1->pack_start(*scrolledwindow1, true, true, 0);

  gridConsulta = manage(new class Gtk::TreeView());
  gridConsulta->set_rules_hint(true);
  gListaGrid = Rotinas->CriaModeloGrid(gridConsulta);
  selection = gridConsulta->get_selection();
  selection->set_mode(Gtk::SELECTION_SINGLE);
  scrolledwindow1->add(*gridConsulta);

  hbox1 = manage(new class Gtk::HBox(false, 0));
  vbox1->pack_start(*hbox1, false, true, 0);

  fixed3 = manage(new class Gtk::Fixed());
  hbox1->pack_start(*fixed3, true, true, 0);
  fixed3->set_size_request(-1, 60);

  labRegistros = manage(new class Gtk::Label("Registro 0 de 0"));
  fixed3->put(*labRegistros, 8, 24);
  labRegistros->set_size_request(200, 16);
  labRegistros->set_alignment(0, 0.5);

  vbox2 = manage(new class Gtk::VBox(false, 0));
  hbox1->pack_start(*vbox2, false, true, 0);

  fixed4 = manage(new class Gtk::Fixed());
  vbox2->pack_start(*fixed4, true, true, 0);
  fixed4->set_size_request(-1, 8);

  hbuttonbox1 = manage(new class Gtk::HButtonBox());
  vbox2->pack_start(*hbuttonbox1, true, true, 0);
  hbuttonbox1->set_border_width(4);
  hbuttonbox1->set_spacing(6);

  btnLimpar = manage(new class Gtk::Button("_Limpar", true));
  hbuttonbox1->add(*btnLimpar);
  btnLimpar->set_flags(Gtk::CAN_DEFAULT);

  btnFechar = manage(new class Gtk::Button("_Fechar", true));
  hbuttonbox1->add(*btnFechar);
  btnFechar->set_flags(Gtk::CAN_DEFAULT);

  show_all_children();
}

CfrmConsultas::~CfrmConsultas() { }

void CfrmConsultas::Fecha() {
  if (sSelecionado.length() > 0)
    Rotinas_sCodigoSelecionado = sSelecionado;
  else
    Rotinas_sCodigoSelecionado = "";

  response(Gtk::RESPONSE_CANCEL);
}

void CfrmConsultas::LimparDados() {
  Rotinas->LimpaModeloGrid(gListaGrid);
  labRegistros->set_text("Registro 0 de 0");
  edtDescricao->set_text("");
  edtDescricao->grab_focus();
}

void CfrmConsultas::PesquisarDados(Glib::ustring sTextoSql,
                     Glib::ustring sMensagemErro, int nQtdCols) {

  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinhas, sTextoSql)) {
    Rotinas->AdicionaLinhasGrid(gListaGrid,
                             &lstLinhas, nQtdCols, true);
    setLabRegistros(0);
  } else
    Rotinas->MsgDlg(sMensagemErro, Gtk::MESSAGE_ERROR);
}

void CfrmConsultas::setLabRegistros(int nLinha) {
GString *sTemp = g_string_new("");

  g_string_sprintf(sTemp, "Registro %d de %d", nLinha,
    lstLinhas.col[0].size());

  labRegistros->set_text(sTemp->str);
}

void CfrmConsultas::setSelecionado() {
int nLinha;

  if(const Gtk::TreeIter iter = selection->get_selected()) {
    iter->get_value (0, nLinha);
    iter->get_value (1, sSelecionado);
    setLabRegistros(nLinha);
  }
}

