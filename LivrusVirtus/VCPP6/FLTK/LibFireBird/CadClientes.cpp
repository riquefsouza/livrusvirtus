#include "Principal.h"
#include "CadClientes.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

CfrmCadClientes *frmCadClientes;

void frmCadClientes_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnFecharClick_cb(Fl_Button* b, void* v);
void frmCadClientes_rbMasculinoClick_cb(Fl_Round_Button* b, void* v);
void frmCadClientes_rbFemininoClick_cb(Fl_Round_Button* b, void* v);
void frmCadClientes_edtCodigoKillFocus_cb(Fl_Input* i, void* v);
void frmCadClientes_edtDtNascKillFocus_cb(Fl_Input* i, void* v);
void frmCadClientes_btnPEnderecoClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnPPaisClick_cb(Fl_Button* b, void* v);
void frmCadClientes_btnPProfissaoClick_cb(Fl_Button* b, void* v);

CfrmCadClientes::CfrmCadClientes()
       : CfrmCadastros(false, STR_CADCLIENTE) {
	IniciaControles();
}

CfrmCadClientes::~CfrmCadClientes() { }

void CfrmCadClientes::IniciaControles() {
  this->size(535, 469);
  edtCodigo->label("CPF:");
  edtCodigo->type(0);
	edtCodigo->maximum_size(14);
  edtCodigo->callback((Fl_Callback*)frmCadClientes_edtCodigoKillFocus_cb);
  edtDescricao->label("Nome:");
  edtDescricao->size(305, 25);
  edtDescricao->maximum_size(30);

  edtEmail = new Fl_Input(10, 115, 305, 25, "E-mail:");
  edtEmail->align(FL_ALIGN_TOP_LEFT);
  edtEmail->deactivate();
  edtEmail->maximum_size(30);
  edtIdentidade = new Fl_Input(320, 115, 120, 25, "Identidade:");
  edtIdentidade->align(FL_ALIGN_TOP_LEFT);
  edtIdentidade->deactivate();
  edtIdentidade->maximum_size(10);

  grpSexo = new Fl_Group(10, 160, 190, 30, "Sexo");
    grpSexo->box(FL_ENGRAVED_BOX);
    grpSexo->align(FL_ALIGN_TOP_LEFT);
    grpSexo->deactivate();
    rbMasculino = new Fl_Round_Button(20, 165, 90, 20, "Masculino");
    rbMasculino->callback((Fl_Callback*)frmCadClientes_rbMasculinoClick_cb);
    rbMasculino->down_box(FL_ROUND_DOWN_BOX);
    rbFeminino = new Fl_Round_Button(110, 165, 85, 20, "Feminino");
    rbFeminino->callback((Fl_Callback*)frmCadClientes_rbFemininoClick_cb);
    rbFeminino->down_box(FL_ROUND_DOWN_BOX);
  grpSexo->end();

  edtTelefone = new Fl_Input(205, 165, 110, 25, "Telefone:");
  edtTelefone->align(FL_ALIGN_TOP_LEFT);
  edtTelefone->deactivate();
  edtTelefone->maximum_size(17);
  edtDtNasc = new Fl_Input(320, 165, 120, 25, "Dt. Nascimento:");
  edtDtNasc->callback((Fl_Callback*)frmCadClientes_edtDtNascKillFocus_cb);
  edtDtNasc->align(FL_ALIGN_TOP_LEFT);
  edtDtNasc->deactivate();

  grpEndereco = new Fl_Group(10, 210, 440, 130, "Endere\347o");
    grpEndereco->box(FL_ENGRAVED_BOX);
    grpEndereco->align(FL_ALIGN_TOP_LEFT);
    grpEndereco->deactivate();
    edtCodEndereco = new Fl_Input(20, 220, 140, 25);
    edtCodEndereco->type(2);
    edtCodEndereco->maximum_size(10);
    edtCodEndereco->labeltype(FL_NO_LABEL);
    edtCodEndereco->callback((Fl_Callback*)frmCadClientes_edtCodEnderecoKillFocus_cb);
    edtCodEndereco->align(FL_ALIGN_TOP_LEFT);
    btnPEndereco = new Fl_Button(160, 220, 25, 25, "...");
    btnPEndereco->callback((Fl_Callback*)frmCadClientes_btnPEnderecoClick_cb);
    edtLogradouro = new Fl_Input(20, 265, 275, 25, "Logradouro:");
    edtLogradouro->align(FL_ALIGN_TOP_LEFT);
    edtLogradouro->deactivate();
    edtBairro = new Fl_Input(300, 265, 145, 25, "Bairro:");
    edtBairro->align(FL_ALIGN_TOP_LEFT);
    edtBairro->deactivate();
    edtCep = new Fl_Input(20, 310, 85, 25, "CEP:");
    edtCep->align(FL_ALIGN_TOP_LEFT);
    edtCep->deactivate();
    edtCidade = new Fl_Input(110, 310, 185, 25, "Cidade:");
    edtCidade->align(FL_ALIGN_TOP_LEFT);
    edtCidade->deactivate();
    edtEstado = new Fl_Input(300, 310, 145, 25, "Estado:");
    edtEstado->align(FL_ALIGN_TOP_LEFT);
    edtEstado->deactivate();
  grpEndereco->end();

  edtCodPais = new Fl_Input(10, 360, 100, 25, "Pa\355s de origem:");
  edtCodPais->type(0);
  edtCodPais->callback((Fl_Callback*)frmCadClientes_edtCodPaisKillFocus_cb);
  edtCodPais->align(FL_ALIGN_TOP_LEFT);
  edtCodPais->deactivate();
  edtCodPais->maximum_size(3);
  edtPais = new Fl_Input(115, 360, 275, 25);
  edtPais->labeltype(FL_NO_LABEL);
  edtPais->align(FL_ALIGN_TOP_LEFT);
  edtPais->deactivate();
  btnPPais = new Fl_Button(390, 360, 25, 25, "...");
  btnPPais->callback((Fl_Callback*)frmCadClientes_btnPPaisClick_cb);
  btnPPais->deactivate();

  edtCodProfissao = new Fl_Input(10, 405, 100, 25, "Profiss\343o:");
  edtCodProfissao->type(2);
  edtCodProfissao->callback((Fl_Callback*)frmCadClientes_edtCodProfissaoKillFocus_cb);
  edtCodProfissao->align(FL_ALIGN_TOP_LEFT);
  edtCodProfissao->deactivate();
  edtCodProfissao->maximum_size(10);
  edtProfissao = new Fl_Input(115, 405, 275, 25);
  edtProfissao->labeltype(FL_NO_LABEL);
  edtProfissao->align(FL_ALIGN_TOP_LEFT);
  edtProfissao->deactivate();
  btnPProfissao = new Fl_Button(390, 405, 25, 25, "...");
  btnPProfissao->callback((Fl_Callback*)frmCadClientes_btnPProfissaoClick_cb);
  btnPProfissao->deactivate();

  IniciaBotoes(450, 15, 210, 440);

  btnNovo->callback((Fl_Callback*)frmCadClientes_btnNovoClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadClientes_btnAnteriorClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadClientes_btnPesquisarClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadClientes_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadClientes_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadClientes_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadClientes_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadClientes_btnFecharClick_cb);

}

bool CfrmCadClientes::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CPFNINF))
  	  return false;
  if (bTodosDados) {
    if (Rotinas->ValidaCampo(edtDescricao->value(), STR_CLININF))
      return false;
    if (Rotinas->ValidaCampo(edtEmail->value(), STR_EMAILNINF))
      return false;
	  if (Rotinas->ValidaCampo(edtTelefone->value(), STR_TELNINF))
		  return false;
	  if (Rotinas->ValidaCampo(edtCodEndereco->value(), STR_ENDNINF))
		  return false;
	  if (Rotinas->ValidaCampo(edtCodPais->value(), STR_PAISNINF))
		  return false;
	  if (Rotinas->ValidaCampo(edtCodProfissao->value(), STR_PROFNINF))
		  return false;
  }
  return true;
}

void frmCadClientes_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadClientes->btnNovoClick();
  frmCadClientes->InformaLimpaDados(false);
  frmCadClientes->HabilitaDados(true);	
}

void frmCadClientes_btnPesquisarClick_cb(Fl_Button* b, void* v){
  if (frmCadClientes->PesquisarDados(ConsSQL->Cliente('S', 
    frmCadClientes->edtCodigo->value(),
    "","","","","","","","",""), STR_CLINENC)){
    frmCadClientes->InformaLimpaDados(true);
    frmCadClientes->HabilitaDados(true);	
  }
}

void frmCadClientes_btnAnteriorClick_cb(Fl_Button* b, void* v){
  if (frmCadClientes->registroAnterior())
    frmCadClientes->InformaLimpaDados(true);
}

void frmCadClientes_btnProximoClick_cb(Fl_Button* b, void* v){
  if (frmCadClientes->registroProximo())
    frmCadClientes->InformaLimpaDados(true);
}

void frmCadClientes_btnSalvarClick_cb(Fl_Button* b, void* v){
  string sSexo, sDtNasc, sSqlInsert, sSqlUpdate;

  if (frmCadClientes->rbMasculino->value() == 1)
     sSexo = "M"; 
  else   
     sSexo = "F";

  sDtNasc = Rotinas->ConverteDataHoraStr(frmCadClientes->edtDtNasc->value(), 
    true, "%d/%m/%Y", "");

  sSqlUpdate = ConsSQL->Cliente('U', frmCadClientes->edtCodigo->value(), 
    frmCadClientes->edtDescricao->value(), 
    frmCadClientes->edtEmail->value(), frmCadClientes->edtIdentidade->value(), 
    sSexo,  frmCadClientes->edtTelefone->value(), sDtNasc, 
    frmCadClientes->edtCodEndereco->value(), 
    frmCadClientes->edtCodPais->value(), 
    frmCadClientes->edtCodProfissao->value());

  sSqlInsert = ConsSQL->Cliente('I', frmCadClientes->edtCodigo->value(), 
    frmCadClientes->edtDescricao->value(), 
    frmCadClientes->edtEmail->value(), frmCadClientes->edtIdentidade->value(), 
    sSexo,  frmCadClientes->edtTelefone->value(), sDtNasc, 
    frmCadClientes->edtCodEndereco->value(), 
    frmCadClientes->edtCodPais->value(), 
    frmCadClientes->edtCodProfissao->value());

 if (frmCadClientes->SalvarDados(frmCadClientes->ValidaDados(true),
    ConsSQL->Cliente('S', frmCadClientes->edtCodigo->value(),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, true)) {
    frmCadClientes->InformaLimpaDados(false);
    frmCadClientes->HabilitaDados(false);	
  }  
}

void frmCadClientes_btnExcluirClick_cb(Fl_Button* b, void* v){
  if (frmCadClientes->ExcluirDados(frmCadClientes->ValidaDados(false),
    ConsSQL->Cliente('D', frmCadClientes->edtCodigo->value(),
    "","","","","","","","",""))) {
    frmCadClientes->InformaLimpaDados(false);
    frmCadClientes->HabilitaDados(false);	
  }  
}

void frmCadClientes_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadClientes->btnLimparClick();
  frmCadClientes->InformaLimpaDados(false);
  frmCadClientes->HabilitaDados(false);	
}

void frmCadClientes_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadClientes->hide();
}

void CfrmCadClientes::InformaLimpaDados(bool bInformar) {
string sTemp;

  if (bInformar) {
    edtEmail->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 2, nLinhaRegistro));
    edtIdentidade->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 3, nLinhaRegistro));
    if (strcmp(
      ListaStr->pesquisaItemOrdM(lstRegistros, 4, nLinhaRegistro),"M")==0) {
      rbMasculino->set();
      rbFeminino->clear();
    } else {
      rbMasculino->clear();
      rbFeminino->set();
    }
    edtTelefone->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 5, nLinhaRegistro));
    sTemp = ListaStr->pesquisaItemOrdM(lstRegistros, 6, nLinhaRegistro);
    edtDtNasc->value(sTemp.substr(0,10).c_str());
    edtCodEndereco->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 7, nLinhaRegistro));
    edtLogradouro->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 8, nLinhaRegistro));
    edtBairro->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 9, nLinhaRegistro));
    edtCep->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 10, nLinhaRegistro));
    edtCidade->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 11, nLinhaRegistro));
    edtEstado->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 12, nLinhaRegistro));
    edtCodPais->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 13, nLinhaRegistro));
    edtPais->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 14, nLinhaRegistro));
    edtCodProfissao->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 15, nLinhaRegistro));
    edtProfissao->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 16, nLinhaRegistro));
  } else {
    edtEmail->value("");
    edtIdentidade->value("");
    rbMasculino->set();
    rbFeminino->clear();
    edtTelefone->value("");
    edtDtNasc->value("");
    edtCodEndereco->value("");
    edtLogradouro->value("");
    edtBairro->value("");
    edtCep->value("");
    edtCidade->value("");
    edtEstado->value("");
    edtCodPais->value("");
    edtPais->value("");
    edtCodProfissao->value("");
    edtProfissao->value("");
    edtCodigo->take_focus();
  }
} 

void CfrmCadClientes::HabilitaDados(bool bHabilita) {
  if (bHabilita) {
    edtEmail->activate();
    edtIdentidade->activate();
    grpSexo->activate();
    edtTelefone->activate();
    edtDtNasc->activate();
    grpEndereco->activate();
    edtCodPais->activate();
    btnPPais->activate();
    edtCodProfissao->activate();
    btnPProfissao->activate();
  } else {
    edtEmail->deactivate();
    edtIdentidade->deactivate();
    grpSexo->deactivate();
    edtTelefone->deactivate();
    edtDtNasc->deactivate();
    grpEndereco->deactivate();
    edtCodPais->deactivate();
    btnPPais->deactivate();
    edtCodProfissao->deactivate();
    btnPProfissao->deactivate();    
  }
}

void frmCadClientes_rbMasculinoClick_cb(Fl_Round_Button* b, void* v){
  frmCadClientes->rbFeminino->clear();
}

void frmCadClientes_rbFemininoClick_cb(Fl_Round_Button* b, void* v){
  frmCadClientes->rbMasculino->clear();
}

void frmCadClientes_edtCodigoKillFocus_cb(Fl_Input* i, void* v){
  if (strlen(frmCadClientes->edtCodigo->value()) > 0) {
  	if (Rotinas->validaCPF(frmCadClientes->edtCodigo->value())==false) {      
      fl_alert(STR_CPFINV);
      frmCadClientes->edtCodigo->value("");
  		frmCadClientes->edtCodigo->take_focus();
  	}
  }	
}

void frmCadClientes_edtDtNascKillFocus_cb(Fl_Input* i, void* v){
  if (strlen(frmCadClientes->edtDtNasc->value()) > 0) {
    if (!Rotinas->validaDataHora(frmCadClientes->edtDtNasc->value(), true)) {
      fl_alert(STR_DTHRINV);
      frmCadClientes->edtDtNasc->value(Rotinas->retDataHoraStr(true,false));
  		frmCadClientes->edtDtNasc->take_focus();
    }
  } else
      frmCadClientes->edtDtNasc->value(Rotinas->retDataHoraStr(true,false));
}

void frmCadClientes_edtCodEnderecoKillFocus_cb(Fl_Input* i, void* v){
string sLogradouro;
LISTAMSTR ConsCampo;

  if (strlen(frmCadClientes->edtCodEndereco->value()) > 0) {
    sLogradouro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Endereco('S',
    frmCadClientes->edtCodEndereco->value(),"","","","",""),STR_ENDNENC);
    if (sLogradouro.length() > 0) {
      frmCadClientes->edtLogradouro->value(sLogradouro.c_str());
      frmCadClientes->edtBairro->value(
        ListaStr->pesquisaItemOrdM(ConsCampo, 2, 0));
      frmCadClientes->edtCep->value(
        ListaStr->pesquisaItemOrdM(ConsCampo, 3, 0));
      frmCadClientes->edtCidade->value(
        ListaStr->pesquisaItemOrdM(ConsCampo, 4, 0));
      frmCadClientes->edtEstado->value(
        ListaStr->pesquisaItemOrdM(ConsCampo, 5, 0));
    } else {
  	  frmCadClientes->edtCodEndereco->take_focus();
      frmCadClientes->edtLogradouro->value("");
      frmCadClientes->edtBairro->value("");
      frmCadClientes->edtCep->value("");
  	  frmCadClientes->edtCidade->value("");
  	  frmCadClientes->edtEstado->value("");
    }
  } else {
    frmCadClientes->edtLogradouro->value("");
    frmCadClientes->edtBairro->value("");
    frmCadClientes->edtCep->value("");
	  frmCadClientes->edtCidade->value("");
	  frmCadClientes->edtEstado->value("");
  }
}

void frmCadClientes_btnPEnderecoClick_cb(Fl_Button* b, void* v){
  frmConEnderecos = new CfrmConEnderecos(true);
  frmConEnderecos->show();
}

void frmCadClientes_edtCodPaisKillFocus_cb(Fl_Input* i, void* v){
string sPais;
LISTAMSTR ConsCampo;

  if (strlen(frmCadClientes->edtCodPais->value()) > 0) {
    sPais = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Pais('S',
      frmCadClientes->edtCodPais->value(),""),STR_PAISNENC);    
    if (sPais.length() > 0) {
      frmCadClientes->edtPais->value(sPais.c_str());
    } else {
      frmCadClientes->edtCodPais->value("");
      frmCadClientes->edtCodPais->take_focus();
    }
  } else {
    frmCadClientes->edtPais->value("");
  }
}

void frmCadClientes_btnPPaisClick_cb(Fl_Button* b, void* v){
  frmConPaises = new CfrmConPaises(true);
  frmConPaises->show();
}

void frmCadClientes_edtCodProfissaoKillFocus_cb(Fl_Input* i, void* v){
string sProfissao;
LISTAMSTR ConsCampo;

  if (strlen(frmCadClientes->edtCodProfissao->value()) > 0) {
    sProfissao = Rotinas->ConsultaCampoDesc(&ConsCampo, 
      ConsSQL->Profissao('S',
      frmCadClientes->edtCodProfissao->value(),""),STR_PROFNENC);
    if (sProfissao.length() > 0) {
      frmCadClientes->edtProfissao->value(sProfissao.c_str());
    } else {
      frmCadClientes->edtCodProfissao->value("");
      frmCadClientes->edtCodProfissao->take_focus();
    }
  } else {
    frmCadClientes->edtProfissao->value("");
  }
}

void frmCadClientes_btnPProfissaoClick_cb(Fl_Button* b, void* v){
  frmConProfissoes = new CfrmConProfissoes(true);
  frmConProfissoes->show();
}

int CfrmCadClientes::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->tlbClientes->activate();
    frmPrincipal->mnuCadClientes->activate();
  }
  return CfrmCadastros::handle(event);
}



