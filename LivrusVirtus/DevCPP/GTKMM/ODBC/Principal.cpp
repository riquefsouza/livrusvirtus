#include "Principal.h"
#include "CadAssuntos.h"
#include "CadAutores.h"
#include "CadEditoras.h"
#include "CadEnderecos.h"
#include "CadIdiomas.h"
#include "CadPaises.h"
#include "CadProfissoes.h"
#include "CadClientes.h"
#include "CadLivros.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"
#include "Splash.h"
#include "Sobre.h"
#include "AlterarSenha.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

#include "xpms/cliente.xpm"
#include "xpms/livro.xpm"
#include "xpms/livros.xpm"
#include "xpms/livrus.xpm"
#include "xpms/sobre.xpm"
#include "xpms/sair.xpm"

CfrmPrincipal * frmPrincipal = (CfrmPrincipal *) NULL;

CfrmPrincipal::CfrmPrincipal() : Gtk::Window(Gtk::WINDOW_TOPLEVEL) {
  set_position(Gtk::WIN_POS_CENTER);
  set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));

  mnuCadAssuntos = NULL;
  mnuCadAutores = NULL;
  mnuCadEditoras = NULL;
  mnuCadEnderecos = NULL;
  mnuCadIdiomas = NULL;
  mnuCadPaises = NULL;
  mnuCadProfissoes = NULL;
  separator2 = NULL;
  mnuCadClientes = NULL;
  mnuCadLivros = NULL;
  mnuCadastros_menu = manage(new class Gtk::Menu());
  mnuCadastros = NULL;
  mnuConAssuntos = NULL;
  mnuConAutores = NULL;
  mnuConEditoras = NULL;
  mnuConEnderecos = NULL;
  mnuConIdiomas = NULL;
  mnuConPaises = NULL;
  mnuConProfissoes = NULL;
  separator3 = NULL;
  mnuConClientes = NULL;
  mnuConLivros = NULL;
  mnuPesquisas_menu = manage(new class Gtk::Menu());
  mnuPesquisas = NULL;
  mnuVenderLivros = NULL;
  mnuVendasRealizadas = NULL;
  mnuVendas_menu = manage(new class Gtk::Menu());
  mnuVendas = NULL;
  mnuAlterarsenha = NULL;
  separator1 = NULL;
  mnuSobre = NULL;
  mnuSair = NULL;
  mnuOpcoes_menu = manage(new class Gtk::Menu());
  mnuOpcoes = NULL;

  barraMenu = manage(new class Gtk::MenuBar());
  vseparador1 = manage(new class Gtk::VSeparator());
  barraFerra = manage(new class Gtk::Toolbar());
  fixed1 = manage(new class Gtk::Fixed());
  BarraStatus1 = manage(new class Gtk::Statusbar());
  BarraStatus2 = manage(new class Gtk::Statusbar());
  hbox1 = manage(new class Gtk::HBox(false, 0));
  vbox1 = manage(new class Gtk::VBox(false, 0));

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Assuntos"));
  mnuCadAssuntos = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("A_utores"));
  mnuCadAutores = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Editoras"));
  mnuCadEditoras = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("E_ndereços")));
  mnuCadEnderecos = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Idiomas"));
  mnuCadIdiomas = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("_Países")));
  mnuCadPaises = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("P_rofissões")));
  mnuCadProfissoes = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
  separator2 = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Clientes"));
  mnuCadClientes = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuCadastros_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("_Livros"));
  mnuCadLivros = (Gtk::MenuItem *) & mnuCadastros_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Assuntos"));
  mnuConAssuntos = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("A_utores"));
  mnuConAutores = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Editoras"));
  mnuConEditoras = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("E_ndereços")));
  mnuConEnderecos = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Idiomas"));
  mnuConIdiomas = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("_Países")));
  mnuConPaises = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("P_rofissões")));
  mnuConProfissoes = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
  separator3 = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Clientes"));
  mnuConClientes = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuPesquisas_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("_Livros"));
  mnuConLivros = (Gtk::MenuItem *) & mnuPesquisas_menu->items().back();

  mnuVendas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Vender Livros"));
  mnuVenderLivros = (Gtk::MenuItem *) & mnuVendas_menu->items().back();

  mnuVendas_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("Vendas _realizadas"));
  mnuVendasRealizadas = (Gtk::MenuItem *) & mnuVendas_menu->items().back();

  mnuOpcoes_menu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Alterar Senha"));
  mnuAlterarsenha = (Gtk::MenuItem *) & mnuOpcoes_menu->items().back();

  mnuOpcoes_menu->items().push_back(Gtk::Menu_Helpers::SeparatorElem());
  separator1 = (Gtk::MenuItem *) & mnuOpcoes_menu->items().back();

  mnuOpcoes_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("_Sobre"));
  mnuSobre = (Gtk::MenuItem *) & mnuOpcoes_menu->items().back();

  mnuOpcoes_menu->items().push_back(Gtk::Menu_Helpers::MenuElem("Sa_ir"));
  mnuSair = (Gtk::MenuItem *) & mnuOpcoes_menu->items().back();

  barraMenu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Cadastros", * mnuCadastros_menu));
  mnuCadastros = (Gtk::MenuItem *) & barraMenu->items().back();

  barraMenu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Pesquisas", * mnuPesquisas_menu));
  mnuPesquisas = (Gtk::MenuItem *) & barraMenu->items().back();

  barraMenu->items().push_back(
   Gtk::Menu_Helpers::MenuElem("_Vendas", * mnuVendas_menu));
  mnuVendas = (Gtk::MenuItem *) & barraMenu->items().back();

  barraMenu->items().push_back(
   Gtk::Menu_Helpers::MenuElem(Rotinas->retUTF8("_Opções"), * mnuOpcoes_menu));
  mnuOpcoes = (Gtk::MenuItem *) & barraMenu->items().back();

  xpm_cliente = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(cliente_xpm));
  barraFerra->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem(*xpm_cliente,
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadClientes_activate), ""));
  tlbCliente = static_cast < Gtk::Button *
   > (barraFerra->tools().back().get_widget());

  xpm_livro = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(livro_xpm));
  barraFerra->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem(*xpm_livro,
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadLivros_activate), ""));
  tlbLivro = static_cast < Gtk::Button *
   > (barraFerra->tools().back().get_widget());

  xpm_venda = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(livros_xpm));
  barraFerra->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem(*xpm_venda,
   SigC::slot(* this, & CfrmPrincipal::on_mnuVenderLivros_activate), ""));
  tlbVenda = static_cast < Gtk::Button *
   > (barraFerra->tools().back().get_widget());

  barraFerra->tools().push_back(Gtk::Toolbar_Helpers::Element(* vseparador1));

  xpm_sobre = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(sobre_xpm));
  barraFerra->tools().push_back(Gtk::Toolbar_Helpers::ButtonElem(*xpm_sobre,
   SigC::slot(* this, & CfrmPrincipal::on_mnuSobre_activate), ""));
  tlbSobre = static_cast < Gtk::Button *
   > (barraFerra->tools().back().get_widget());

  xpm_sair = new Gtk::Image(Gdk::Pixbuf::create_from_xpm_data(sair_xpm));
  barraFerra->tools().push_back(
   Gtk::Toolbar_Helpers::ButtonElem(*xpm_sair,
   SigC::slot(* this, & CfrmPrincipal::on_mnuSair_activate), ""));
  tlbSair = static_cast < Gtk::Button *
   > (barraFerra->tools().back().get_widget());

  barraFerra->set_tooltips(false);
  BarraStatus1->set_has_resize_grip(false);
  hbox1->pack_start(* BarraStatus1, false, true, 0);
  BarraStatus1->set_size_request(120, 21);
  hbox1->pack_start(* BarraStatus2, true, true, 0);
  BarraStatus2->set_size_request(-1, 21);
  vbox1->pack_start(* barraMenu, false, false, 0);
  vbox1->pack_start(* barraFerra, false, false, 0);
  vbox1->pack_start(* fixed1);
  vbox1->pack_start(* hbox1, false, false, 0);

  set_title("Livrus Virtus");
  set_default_size(500, 400);
  set_modal(false);
  add(* vbox1);
  show_all_children();

  mnuCadAssuntos->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadAssuntos_activate));
  mnuCadAutores->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadAutores_activate));
  mnuCadEditoras->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadEditoras_activate));
  mnuCadEnderecos->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadEnderecos_activate));
  mnuCadIdiomas->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadIdiomas_activate));
  mnuCadPaises->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadPaises_activate));
  mnuCadProfissoes->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadProfissoes_activate));
  mnuCadClientes->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadClientes_activate));
  mnuCadLivros->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuCadLivros_activate));
  mnuConAssuntos->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConAssuntos_activate));
  mnuConAutores->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConAutores_activate));
  mnuConEditoras->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConEditoras_activate));
  mnuConEnderecos->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConEnderecos_activate));
  mnuConIdiomas->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConIdiomas_activate));
  mnuConPaises->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConPaises_activate));
  mnuConProfissoes->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConProfissoes_activate));
  mnuConClientes->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConClientes_activate));
  mnuConLivros->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuConLivros_activate));
  mnuVenderLivros->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuVenderLivros_activate));
  mnuVendasRealizadas->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuVendasRealizadas_activate));
  mnuAlterarsenha->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuAlterarsenha_activate));
  mnuSobre->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuSobre_activate));
  mnuSair->signal_activate().connect(
   SigC::slot(* this, & CfrmPrincipal::on_mnuSair_activate));
}

CfrmPrincipal::~CfrmPrincipal() { }

void CfrmPrincipal::setaBarraStatus(gchar *sTexto) {
  BarraStatus2->push(Rotinas->retUTF8(sTexto),
    BarraStatus2->get_context_id("contexto2"));
}

void CfrmPrincipal::on_mnuCadAssuntos_activate() {
  setaBarraStatus(STR_CADASSUNTO);
  mnuCadAssuntos->set_sensitive(false);
  frmCadAssuntos = new CfrmCadAssuntos();
  frmCadAssuntos->show();
}

void CfrmPrincipal::on_mnuCadAutores_activate() {
  setaBarraStatus(STR_CADAUTOR);
  mnuCadAutores->set_sensitive(false);
  frmCadAutores = new CfrmCadAutores();
  frmCadAutores->show();
}

void CfrmPrincipal::on_mnuCadEditoras_activate() {
  setaBarraStatus(STR_CADEDITORA);
  mnuCadEditoras->set_sensitive(false);
  frmCadEditoras = new CfrmCadEditoras();
  frmCadEditoras->show();
}

void CfrmPrincipal::on_mnuCadEnderecos_activate() {
  setaBarraStatus(STR_CADENDERECO);
  mnuCadEnderecos->set_sensitive(false);
  frmCadEnderecos = new CfrmCadEnderecos();
  frmCadEnderecos->show();
}

void CfrmPrincipal::on_mnuCadIdiomas_activate() {
  setaBarraStatus(STR_CADIDIOMA);
  mnuCadIdiomas->set_sensitive(false);
  frmCadIdiomas = new CfrmCadIdiomas();
  frmCadIdiomas->show();
}

void CfrmPrincipal::on_mnuCadPaises_activate() {
  setaBarraStatus(STR_CADPAIS);
  mnuCadPaises->set_sensitive(false);
  frmCadPaises = new CfrmCadPaises();
  frmCadPaises->show();
}

void CfrmPrincipal::on_mnuCadProfissoes_activate() {
  setaBarraStatus(STR_CADPROFISS);
  mnuCadProfissoes->set_sensitive(false);
  frmCadProfissoes = new CfrmCadProfissoes();
  frmCadProfissoes->show();
}

void CfrmPrincipal::on_mnuCadClientes_activate() {
  setaBarraStatus(STR_CADCLIENTE);
  tlbCliente->set_sensitive(false);
  mnuCadClientes->set_sensitive(false);
  frmCadClientes = new CfrmCadClientes();
  frmCadClientes->show();
}

void CfrmPrincipal::on_mnuCadLivros_activate() {
  setaBarraStatus(STR_CADLIVRO);
  tlbLivro->set_sensitive(false);
  mnuCadLivros->set_sensitive(false);
  frmCadLivros = new CfrmCadLivros();
  frmCadLivros->show();
}

void CfrmPrincipal::on_mnuConAssuntos_activate() {
  setaBarraStatus(STR_CONASSUNTO);
  frmConAssuntos = new CfrmConAssuntos();
  frmConAssuntos->run();
  delete frmConAssuntos;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConAutores_activate() {
  setaBarraStatus(STR_CONAUTOR);
  frmConAutores = new CfrmConAutores();
  frmConAutores->run();
  delete frmConAutores;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConEditoras_activate() {
  setaBarraStatus(STR_CONEDITORA);
  frmConEditoras = new CfrmConEditoras();
  frmConEditoras->run();
  delete frmConEditoras;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConEnderecos_activate() {
  setaBarraStatus(STR_CONENDERECO);
  frmConEnderecos = new CfrmConEnderecos();
  frmConEnderecos->run();
  delete frmConEnderecos;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConIdiomas_activate() {
  setaBarraStatus(STR_CONIDIOMA);
  frmConIdiomas = new CfrmConIdiomas();
  frmConIdiomas->run();
  delete frmConIdiomas;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConPaises_activate() {
  setaBarraStatus(STR_CONPAIS);
  frmConPaises = new CfrmConPaises();
  frmConPaises->run();
  delete frmConPaises;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConProfissoes_activate() {
  setaBarraStatus(STR_CONPROFISS);
  frmConProfissoes = new CfrmConProfissoes();
  frmConProfissoes->run();
  delete frmConProfissoes;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConClientes_activate() {
  setaBarraStatus(STR_CONCLIENTE);
  frmConClientes = new CfrmConClientes();
  frmConClientes->run();
  delete frmConClientes;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuConLivros_activate() {
  setaBarraStatus(STR_CONLIVRO);
  frmConLivros = new CfrmConLivros();
  frmConLivros->run();
  delete frmConLivros;
  setaBarraStatus("");
}

void CfrmPrincipal::on_mnuVenderLivros_activate() {
  setaBarraStatus(STR_VENLIVRO);
  tlbVenda->set_sensitive(false);
  mnuVenderLivros->set_sensitive(false);
  frmVenderLivros = new CfrmVenderLivros();
  frmVenderLivros->show();
}

void CfrmPrincipal::on_mnuVendasRealizadas_activate() {
  setaBarraStatus(STR_CONVENLIVRO);
  mnuVendasRealizadas->set_sensitive(false);
  frmConVendas = new CfrmConVendas();
  frmConVendas->show();
}

void CfrmPrincipal::on_mnuAlterarsenha_activate() {
  setaBarraStatus(STR_ALTSENHA);
  mnuAlterarsenha->set_sensitive(false);
  frmAlterarSenha = new CfrmAlterarSenha();
  frmAlterarSenha->show();
}

void CfrmPrincipal::on_mnuSobre_activate() {
  setaBarraStatus(STR_OPSOBRE);
  frmSobre = new CfrmSobre();
  frmSobre->run();
  setaBarraStatus("");
  delete frmSobre;
}

void CfrmPrincipal::on_mnuSair_activate() {
  if (DlgSair()) {
    destroy_();
    Gtk::Main::quit();
  }
}

gboolean CfrmPrincipal::DlgSair() {
  Gtk::MessageDialog dialog(STR_SAIRSIS, Gtk::MESSAGE_QUESTION,
   Gtk::BUTTONS_YES_NO, true, false);
  dialog.set_position(Gtk::WIN_POS_CENTER);
  if (dialog.run() == Gtk::RESPONSE_YES) {
    return (TRUE);
  } else {
    return (FALSE);
  }
}

bool CfrmPrincipal::on_delete_event(GdkEventAny * event) {
  if (DlgSair())
    return false;
  else
   //return true;
     Gtk::Main::quit();
}
