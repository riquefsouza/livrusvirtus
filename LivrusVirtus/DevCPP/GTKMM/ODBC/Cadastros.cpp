#include "Cadastros.h"
#include "Principal.h"
#include "xpms/livrus.xpm"

CfrmCadastros * frmCadastros = (CfrmCadastros *) NULL;

CfrmCadastros::CfrmCadastros(bool bIniciaBotoes, Glib::ustring sTitulo)
  : Gtk::Window(Gtk::WINDOW_TOPLEVEL) {
  this->set_icon(Gdk::Pixbuf::create_from_xpm_data(Livrus_xpm));
  this->set_title(Rotinas->retUTF8(sTitulo));
  this->set_position(Gtk::WIN_POS_CENTER);
  this->set_default_size(300, 150);
  this->property_destroy_with_parent()=true;

  fixed1 = manage(new class Gtk::Fixed());
  this->add(*fixed1);

  labCodigo = manage(new class Gtk::Label(Rotinas->retUTF8("Código:")));
  fixed1->put(*labCodigo, 8, 8);
  labCodigo->set_size_request(64, 16);
  labCodigo->set_alignment(0, 0.5);

  edtCodigo = manage(new class Gtk::Entry());
  fixed1->put(*edtCodigo, 8, 24);
  edtCodigo->set_size_request(158, 24);
  edtCodigo->set_max_length(10);

  btnNovo = manage(new class Gtk::Button("_Novo", true));
  fixed1->put(*btnNovo, 176, 24);
  btnNovo->set_size_request(85, 28);

  labDescricao = manage(new class Gtk::Label(Rotinas->retUTF8("Descrição:")));
  fixed1->put(*labDescricao, 8, 56);
  labDescricao->set_size_request(80, 16);
  labDescricao->set_alignment(0, 0.5);

  edtDescricao = manage(new class Gtk::Entry());
  edtDescricao->set_sensitive(false);
  fixed1->put(*edtDescricao, 8, 72);
  edtDescricao->set_size_request(288, 24);
  edtDescricao->set_max_length(30);

  if (bIniciaBotoes) {
    IniciaBotoes(312, 10, 45, 112);
    show_all_children();
  }

  nLinhaRegistro = 0;
}

CfrmCadastros::~CfrmCadastros() { }

// Necessário por causa da tabulação dos campos
void CfrmCadastros::IniciaBotoes(int nX1, int nY1, int nX2, int nY2) {

  Gtk::VButtonBox * vbuttonbox1;
  Gtk::HButtonBox * hbuttonbox1;

  vbuttonbox1 = manage(new class Gtk::VButtonBox());
  fixed1->put(*vbuttonbox1, nX1, nY1);
  vbuttonbox1->set_size_request(96, 94);

  btnPesquisar = manage(new class Gtk::Button("_Pesquisar", true));
  vbuttonbox1->add(*btnPesquisar);
  btnPesquisar->set_flags(Gtk::CAN_DEFAULT);

  btnAnterior = manage(new class Gtk::Button("_Anterior", true));
  btnAnterior->set_sensitive(false);
  vbuttonbox1->add(*btnAnterior);
  btnAnterior->set_flags(Gtk::CAN_DEFAULT);

  btnProximo = manage(new class Gtk::Button(Rotinas->retUTF8("Próxi_mo"),true));
  btnProximo->set_sensitive(false);
  vbuttonbox1->add(*btnProximo);
  btnProximo->set_flags(Gtk::CAN_DEFAULT);

  hbuttonbox1 = manage(new class Gtk::HButtonBox());
  fixed1->put(*hbuttonbox1, nX2, nY2);
  hbuttonbox1->set_size_request(360, 32);

  btnSalvar = manage(new class Gtk::Button("_Salvar", true));
  btnSalvar->set_sensitive(false);
  hbuttonbox1->add(*btnSalvar);
  btnSalvar->set_flags(Gtk::CAN_DEFAULT);

  btnExcluir = manage(new class Gtk::Button("_Excluir", true));
  btnExcluir->set_sensitive (false);
  hbuttonbox1->add(*btnExcluir);
  btnExcluir->set_flags(Gtk::CAN_DEFAULT);

  btnLimpar = manage(new class Gtk::Button("_Limpar", true));
  hbuttonbox1->add(*btnLimpar);
  btnLimpar->set_flags(Gtk::CAN_DEFAULT);

  btnFechar = manage(new class Gtk::Button("_Fechar", true));
  hbuttonbox1->add(*btnFechar);
  btnFechar->set_flags(Gtk::CAN_DEFAULT);
}

void CfrmCadastros::InformaLimpaDados(bool bInformar) {
  if (bInformar) {
    edtCodigo->set_text(lstRegistros.col[0][nLinhaRegistro]);
    edtDescricao->set_text(lstRegistros.col[1][nLinhaRegistro]);
  } else {
    edtCodigo->set_text("");
    edtDescricao->set_text("");
    edtCodigo->set_sensitive(true);
    edtCodigo->grab_focus();
  }
}

void CfrmCadastros::HabilitaDados(bool bHabilita){
  edtDescricao->set_sensitive(bHabilita);
}

void CfrmCadastros::btnNovoClick()
{
  btnSalvar->set_sensitive(true);
  btnExcluir->set_sensitive(false);
  btnPesquisar->set_sensitive(false);
  btnAnterior->set_sensitive(false);
  btnProximo->set_sensitive(false);
  btnNovo->set_sensitive(false);

  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(true);
}

void CfrmCadastros::NovoDado(Glib::ustring sTextoSql)
{
  LISTAMSTR lstRegs;

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegs, sTextoSql)) {
    edtCodigo->set_text(lstRegs.col[0][0]);
    #ifdef G_OS_WIN32
      edtCodigo->set_sensitive(false);
    #else
      edtCodigo->unset_flags(Gtk::CAN_FOCUS);
    #endif
    edtDescricao->grab_focus();
  }
}

void CfrmCadastros::btnLimparClick() {
  btnSalvar->set_sensitive(false);
  btnExcluir->set_sensitive(false);
  btnPesquisar->set_sensitive(true);
  btnAnterior->set_sensitive(false);
  btnProximo->set_sensitive(false);
  btnNovo->set_sensitive(true);

  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(false);
}

bool CfrmCadastros::ExcluirDados(bool bValidaDados, Glib::ustring sTextoSql) {
   if (bValidaDados) {
     Gtk::MessageDialog dialog(STR_SAIRSIS, Gtk::MESSAGE_QUESTION,
       Gtk::BUTTONS_YES_NO, true, false);
     dialog.set_position(Gtk::WIN_POS_CENTER);
     if (dialog.run() == Gtk::RESPONSE_YES) {
        if (Rotinas->AtualizaDados(gConexao, sTextoSql)) {
           btnLimparClick();
           return true;
        }
      }
   }
  return false;
}

bool CfrmCadastros::PesquisarDados(Glib::ustring sTextoSql,
  Glib::ustring sMensagemErro) {
	if ( edtCodigo->get_text().length() == 0) {
    btnAnterior->set_sensitive(true);
    btnProximo->set_sensitive(true);
	}

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegistros, sTextoSql)) {
     InformaLimpaDados(true);
     HabilitaDados(true);

     btnSalvar->set_sensitive(true);
     btnExcluir->set_sensitive(true);
     btnPesquisar->set_sensitive(false);

     return true;
	} else
    Rotinas->MsgDlg(sMensagemErro, Gtk::MESSAGE_ERROR);

  return false;
}

bool CfrmCadastros::registroAnterior() {
	if (nLinhaRegistro > 0) {
    nLinhaRegistro--;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

bool CfrmCadastros::registroProximo()
{
	if (nLinhaRegistro < abs(lstRegistros.col[0].size()-1)) {
    nLinhaRegistro++;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

bool CfrmCadastros::SalvarDados(bool bValidaDados, Glib::ustring sTextoSql,
  Glib::ustring sTextoUpdate, Glib::ustring sTextoInsert, bool bLimparDados)
{
  Glib::ustring sArquiva;

	if (bValidaDados) {
	   if (Rotinas->ConsultaDados(gConexao,sTextoSql))
       sArquiva = sTextoUpdate;
     else
       sArquiva = sTextoInsert;

     if (Rotinas->AtualizaDados(gConexao, sArquiva)) {
  	   if (bLimparDados)
         btnLimparClick();
       return true;
     }
	}
  return false;
}

void CfrmCadastros::ValidaCodigo() {
  if (edtCodigo->get_text().length() > 0) {
  	if (Rotinas->ValidaInteger(edtCodigo->get_text())==false) {
      edtCodigo->set_text("");
      edtCodigo->grab_focus();
  	}
  }
}
