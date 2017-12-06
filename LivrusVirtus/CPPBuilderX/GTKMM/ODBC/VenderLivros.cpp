#include "VenderLivros.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"
#include "xpms/livrus.xpm"

CfrmVenderLivros * frmVenderLivros = (CfrmVenderLivros *) NULL;

CfrmVenderLivros::CfrmVenderLivros()
  : Gtk::Window(Gtk::WINDOW_TOPLEVEL) {

  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_title("Vender Livros");
  this->set_default_size(480, 310);
  this->set_position(Gtk::WIN_POS_CENTER_ALWAYS);
  this->property_destroy_with_parent()=true;

  fixed1 = manage(new class Gtk::Fixed());
  this->add(*fixed1);

  edtDtHrVenda = manage(new class Gtk::Entry());
  fixed1->put(*edtDtHrVenda, 8, 24);
  edtDtHrVenda->set_size_request(158, 24);
  #ifdef G_OS_WIN32
    edtDtHrVenda->set_sensitive(false);
  #else
    edtDtHrVenda->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labCPF = manage(new class Gtk::Label("CPF: "));
  fixed1->put(*labCPF, 8, 56);
  labCPF->set_size_request(38, 16);

  edtCPF = manage(new class Gtk::Entry());
  fixed1->put(*edtCPF, 8, 72);
  edtCPF->set_size_request(158, 24);
  edtCPF->set_max_length(14);

  labISBN = manage(new class Gtk::Label("ISBN: "));
  fixed1->put(*labISBN, 8, 104);
  labISBN->set_size_request(38, 16);

  edtISBN = manage(new class Gtk::Entry());
  fixed1->put(*edtISBN, 8, 120);
  edtISBN->set_size_request(158, 24);
  edtISBN->set_max_length(13);

  edtCliente = manage(new class Gtk::Entry());
  fixed1->put(*edtCliente, 168, 72);
  edtCliente->set_size_request(344, 24);
  #ifdef G_OS_WIN32
    edtCliente->set_sensitive(false);
  #else
    edtCliente->unset_flags(Gtk::CAN_FOCUS);
  #endif

  btnPCliente = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPCliente, 512, 72);
  btnPCliente->set_size_request(25, 25);

  labCliente = manage(new class Gtk::Label("Cliente: "));
  fixed1->put(*labCliente, 168, 56);
  labCliente->set_size_request(56, 16);

  labLivro = manage(new class Gtk::Label("Livro: "));
  fixed1->put(*labLivro, 168, 104);
  labLivro->set_size_request(38, 16);

  edtLivro = manage(new class Gtk::Entry());
  fixed1->put(*edtLivro, 168, 120);
  edtLivro->set_size_request(312, 24);
  #ifdef G_OS_WIN32
    edtLivro->set_sensitive(false);
  #else
    edtLivro->unset_flags(Gtk::CAN_FOCUS);
  #endif

  btnPLivro = manage(new class Gtk::Button("..."));
  fixed1->put(*btnPLivro, 512, 120);
  btnPLivro->set_size_request(25, 25);

  btnAdLivros = manage(new class Gtk::Button("+"));
  fixed1->put(*btnAdLivros, 480, 120);
  btnAdLivros->set_size_request(25, 25);

  labLivros = manage(new class Gtk::Label("Livros para vender: "));
  fixed1->put(*labLivros, 8, 152);
  labLivros->set_size_request(128, 16);

  scrolledwindow1 = manage(new class Gtk::ScrolledWindow());
  fixed1->put(*scrolledwindow1, 8, 168);
  scrolledwindow1->set_size_request(528, 136);
  scrolledwindow1->set_border_width(1);
  scrolledwindow1->set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
  scrolledwindow1->set_shadow_type(Gtk::SHADOW_ETCHED_IN);

  lstLivros = manage(new class Gtk::TreeView());
  scrolledwindow1->add(*lstLivros);
  lstLivros->set_size_request(134, 26);
  lstLivros->set_headers_visible(false);
  lstLivros->set_rules_hint(true);
  selection = lstLivros->get_selection();
  selection->set_mode(Gtk::SELECTION_SINGLE);
  LSLivros = Rotinas->CriaModeloGrid(lstLivros);

  edtPrecoTotal = manage(new class Gtk::Entry());
  fixed1->put(*edtPrecoTotal, 392, 312);
  edtPrecoTotal->set_size_request(142, 24);
  #ifdef G_OS_WIN32
    edtPrecoTotal->set_sensitive(false);
  #else
    edtPrecoTotal->unset_flags(Gtk::CAN_FOCUS);
  #endif

  labPrecoTotal = manage(new class Gtk::Label(Rotinas->retUTF8("Preço Total: ")));
  fixed1->put(*labPrecoTotal, 304, 312);
  labPrecoTotal->set_size_request(88, 16);

  hbuttonbox1 = manage(new class Gtk::HButtonBox());
  fixed1->put(*hbuttonbox1, 265, 344);
  hbuttonbox1->set_size_request(270, 32);

  btnVender = manage(new class Gtk::Button("_Vender", true));
  hbuttonbox1->add(*btnVender);
  btnVender->set_flags(Gtk::CAN_DEFAULT);

  btnLimpar = manage(new class Gtk::Button("_Limpar", true));
  hbuttonbox1->add(*btnLimpar);
  btnLimpar->set_flags(Gtk::CAN_DEFAULT);

  btnFechar = manage(new class Gtk::Button("_Fechar", true));
  hbuttonbox1->add(*btnFechar);
  btnFechar->set_flags(Gtk::CAN_DEFAULT);

  labDtHrVenda = manage(new class Gtk::Label("Data/Hora Venda: "));
  fixed1->put(*labDtHrVenda, 8, 8);
  labDtHrVenda->set_size_request(120, 16);

  int nLargura[] = { 180 };
  Glib::ustring sRotulos[] = { "Item" };
  Rotinas->AdicionaColunasGrid(lstLivros, 0, 1, nLargura, sRotulos);

  edtDtHrVenda->set_text(Rotinas->retDataHoraStr(true, true));
  nPrecoTotal = 0;

  show_all_children();

  edtCPF->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_edtCPF_focus_out_event));
  edtISBN->signal_focus_out_event().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_edtISBN_focus_out_event));

  lstLivros->signal_button_press_event().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_lstLivros_button_press_event));

  btnVender->signal_clicked().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_btnVender_clicked));
  btnLimpar->signal_clicked().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_btnLimpar_clicked));
  btnFechar->signal_clicked().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_btnFechar_clicked));
  btnPCliente->signal_clicked().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_btnPCliente_clicked));
  btnAdLivros->signal_clicked().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_btnAdLivros_clicked));
  btnPLivro->signal_clicked().connect(SigC::slot(* this,
   & CfrmVenderLivros::on_btnPLivro_clicked));
}

CfrmVenderLivros::~CfrmVenderLivros() {}

void CfrmVenderLivros::LimpaDados() {
  edtDtHrVenda->set_text(Rotinas->retDataHoraStr(true, true));
  edtCPF->set_text("");
  edtCliente->set_text("");
  edtISBN->set_text("");
  edtLivro->set_text("");
  Rotinas->LimpaModeloGrid(LSLivros);
  nPrecoTotal = 0;
  edtPrecoTotal->set_text("R$ 0,00");
  edtCPF->grab_focus();
}

bool CfrmVenderLivros::ValidaDados() {
int nQtdLinhas = 0;

  if (Rotinas->ValidaCampo(edtCPF->get_text(), STR_CPFNINF))
 	  return false;

  Rotinas->PesquisaContaItemGrid(LSLivros, "", &nQtdLinhas);
  if (nQtdLinhas == 0) {
    Rotinas->MsgDlg(STR_LIVVENNINF, Gtk::MESSAGE_ERROR);
    return false;
  }
	return true;
}

bool CfrmVenderLivros::SalvaLista() {
Glib::ustring sDesc, sISBN, sPreco, sQtdEstoque, sCPF, sDTHR, sDataHora;
GString *sPrecoTotal = g_string_new("");
GString *sTemp = g_string_new("");
int nQtdEstoque, nCont;

  sCPF = edtCPF->get_text();
  g_string_sprintf(sPrecoTotal, "%.2f", nPrecoTotal);

  sDTHR = edtDtHrVenda->get_text();
  sDataHora = Rotinas->ConverteDataHoraStr(sDTHR, true, "%m/%d/%Y","%H:%M:%S");

  if (!LSLivros->children().empty()) {
    for (nCont=0; nCont < LSLivros->children().size(); nCont++) {
      LSLivros->children()[nCont]->get_value(1, sDesc);
      LSLivros->children()[nCont]->get_value(2, sISBN);
      LSLivros->children()[nCont]->get_value(3, sPreco);
      LSLivros->children()[nCont]->get_value(4, sQtdEstoque);

      Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('I',sISBN, sCPF,
        sDataHora,Rotinas->VirgulaParaPonto(sPrecoTotal->str,false),""));

      nQtdEstoque = atoi(sQtdEstoque.c_str());
      if (nQtdEstoque > 0) {
        nQtdEstoque--;
        g_string_sprintf(sTemp, "%d", nQtdEstoque);
        Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('U',sISBN,
          "","","", sTemp->str));
      }
    }
  }
return true;
}

bool CfrmVenderLivros::on_edtCPF_focus_out_event(GdkEventFocus* event) {
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

bool CfrmVenderLivros::on_edtISBN_focus_out_event(GdkEventFocus *event) {
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

void CfrmVenderLivros::on_btnVender_clicked() {
  if (ValidaDados()) {
    if (SalvaLista()) {
      Rotinas->MsgDlg(STR_VENRESUC, Gtk::MESSAGE_INFO);
      LimpaDados();
    }
  }
}

void CfrmVenderLivros::on_btnLimpar_clicked() {
  LimpaDados();
}

void CfrmVenderLivros::destroy_() {
  frmPrincipal->tlbVenda->set_sensitive(true);
  frmPrincipal->mnuVenderLivros->set_sensitive(true);
  frmPrincipal->setaBarraStatus("");
}

void CfrmVenderLivros::on_btnFechar_clicked() {
  this->hide();
  this->destroy_();
}

void CfrmVenderLivros::on_btnPCliente_clicked() {
  frmConClientes = new CfrmConClientes();
	frmConClientes->run();
  delete frmConClientes;
  edtCPF->set_text(Rotinas_sCodigoSelecionado);
  on_edtCPF_focus_out_event(NULL);
}

void CfrmVenderLivros::on_btnPLivro_clicked() {
  frmConLivros = new CfrmConLivros();
	frmConLivros->run();
  delete frmConLivros;
  edtISBN->set_text(Rotinas_sCodigoSelecionado);
  on_edtISBN_focus_out_event(NULL);
}

bool CfrmVenderLivros::on_lstLivros_button_press_event(
                      				 GdkEventButton *event) {
int nQtdLinhas = 0;
Glib::ustring sDesc, sISBN, sPreco, sQtdEstoque;
double nPreco;
gchar* fimptr[TAM_MAX_STR];
GString *sPrecoTotal = g_string_new("");

  if (event->button==Gdk::DOUBLE_BUTTON_PRESS) {
    Rotinas->PesquisaContaItemGrid(LSLivros, "", &nQtdLinhas);
    if (nQtdLinhas > 0) {

      if(const Gtk::TreeIter iter = selection->get_selected()) {
        iter->get_value(1, sDesc);
        iter->get_value(2, sISBN);
        iter->get_value(3, sPreco);
        iter->get_value(4, sQtdEstoque);

        nPreco = g_strtod(sPreco.c_str(), fimptr);
        nPrecoTotal = nPrecoTotal - nPreco;
        g_string_sprintf(sPrecoTotal, "R$ %.2f", nPrecoTotal);
        edtPrecoTotal->set_text(
          Rotinas->VirgulaParaPonto(sPrecoTotal->str,true));
        LSLivros->erase(iter);
      }
    }
  }
  return false;
}

void CfrmVenderLivros::on_btnAdLivros_clicked() {
LISTAMSTR lstLinhas;
GString *sItems = g_string_new("");
Glib::ustring sISBN, sLivro;
int nQtdLinhas = 0, nCol;
GString *sPrecoTotal = g_string_new("");
gdouble nPreco;
char* fimptr[TAM_MAX_STR];

  sISBN = edtISBN->get_text();
  sLivro = edtLivro->get_text();

  if (sLivro.length() > 0) {
    g_string_sprintf(sItems, "%s - %s - R$ %s",
      sISBN.c_str(), sLivro.c_str(), Rotinas_sPreco.c_str());

    if (Rotinas->PesquisaContaItemGrid(LSLivros,
        sItems->str, &nQtdLinhas)==false) {

      for (nCol = 0; nCol < 4; nCol++)
        lstLinhas.col[nCol].clear();

      lstLinhas.col[0].push_back(sItems->str);
      lstLinhas.col[1].push_back(sISBN);
      lstLinhas.col[2].push_back(Rotinas_sPreco);
      lstLinhas.col[3].push_back(Rotinas_sQtdEstoque);

      Rotinas->AdicionaLinhasGrid(LSLivros, &lstLinhas, 4, false);

      nPreco = g_strtod(Rotinas_sPreco.c_str(), fimptr);
      nPrecoTotal = nPrecoTotal + nPreco;
    }
    edtISBN->set_text("");
    edtLivro->set_text("");
    g_string_sprintf(sPrecoTotal, "R$ %.2f", nPrecoTotal);
    edtPrecoTotal->set_text(
      Rotinas->VirgulaParaPonto(sPrecoTotal->str,true));
  }
}
