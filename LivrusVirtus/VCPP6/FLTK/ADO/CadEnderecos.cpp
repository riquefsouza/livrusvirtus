#include "Principal.h"
#include "CadEnderecos.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CfrmCadEnderecos *frmCadEnderecos;

void frmCadEnderecos_btnNovoClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnPesquisarClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnAnteriorClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnProximoClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnSalvarClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnExcluirClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnLimparClick_cb(Fl_Button* b, void* v);
void frmCadEnderecos_btnFecharClick_cb(Fl_Button* b, void* v);

CfrmCadEnderecos::CfrmCadEnderecos()
       : CfrmCadastros(false, STR_CADENDERECO) {
	IniciaControles();
}

CfrmCadEnderecos::~CfrmCadEnderecos() { }

void CfrmCadEnderecos::IniciaControles() {
  this->size(530, 180);
  edtDescricao->label("Logradouro:");
  edtDescricao->maximum_size(40);

  edtBairro = new Fl_Input(290, 70, 150, 25, "Bairro:");
  edtBairro->align(FL_ALIGN_TOP_LEFT);
  edtBairro->deactivate();
  edtBairro->maximum_size(15);
  edtCep = new Fl_Input(10, 115, 85, 25, "CEP:");
  edtCep->align(FL_ALIGN_TOP_LEFT);
  edtCep->deactivate();
  edtCep->maximum_size(8);
  edtCidade = new Fl_Input(100, 115, 185, 25, "Cidade:");
  edtCidade->align(FL_ALIGN_TOP_LEFT);
  edtCidade->deactivate();
  edtCidade->maximum_size(30);
  cmbEstado = new Fl_Choice(290, 115, 150, 25, "Estado:");
  cmbEstado->down_box(FL_BORDER_BOX);
  cmbEstado->align(FL_ALIGN_TOP_LEFT);
  cmbEstado->deactivate();

  IniciaBotoes(450, 15, 210, 150);

  btnNovo->callback((Fl_Callback*)frmCadEnderecos_btnNovoClick_cb);
  btnPesquisar->callback((Fl_Callback*)frmCadEnderecos_btnPesquisarClick_cb);
  btnAnterior->callback((Fl_Callback*)frmCadEnderecos_btnAnteriorClick_cb);
  btnProximo->callback((Fl_Callback*)frmCadEnderecos_btnProximoClick_cb);
  btnSalvar->callback((Fl_Callback*)frmCadEnderecos_btnSalvarClick_cb);
  btnExcluir->callback((Fl_Callback*)frmCadEnderecos_btnExcluirClick_cb);
  btnLimpar->callback((Fl_Callback*)frmCadEnderecos_btnLimparClick_cb);
  btnFechar->callback((Fl_Callback*)frmCadEnderecos_btnFecharClick_cb);

  AdicionaCombo();
}

bool CfrmCadEnderecos::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->value(), STR_CODNINF))
  	  return false;
	if (bTodosDados) {
	  if (Rotinas->ValidaCampo(edtDescricao->value(), STR_ENDNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtBairro->value(), STR_BAIRRONINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtCep->value(), STR_CEPNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtCidade->value(), STR_CIDADENINF))
  		return false;
	}
	return true;
}

void frmCadEnderecos_btnNovoClick_cb(Fl_Button* b, void* v){
  frmCadEnderecos->btnNovoClick();
  frmCadEnderecos->InformaLimpaDados(false);
  frmCadEnderecos->HabilitaDados(true);	
  frmCadEnderecos->NovoDado(ConsSQL->Endereco('N', 
    frmCadEnderecos->edtCodigo->value(),"","","","",""));
}

void frmCadEnderecos_btnPesquisarClick_cb(Fl_Button* b, void* v){
  if (frmCadEnderecos->PesquisarDados(ConsSQL->Endereco('S', 
    frmCadEnderecos->edtCodigo->value(),"","","","",""), STR_ENDNENC)){
    frmCadEnderecos->InformaLimpaDados(true);
    frmCadEnderecos->HabilitaDados(true);	
  }
}

void frmCadEnderecos_btnAnteriorClick_cb(Fl_Button* b, void* v){
  if (frmCadEnderecos->registroAnterior())
    frmCadEnderecos->InformaLimpaDados(true);
}

void frmCadEnderecos_btnProximoClick_cb(Fl_Button* b, void* v){
  if (frmCadEnderecos->registroProximo())
    frmCadEnderecos->InformaLimpaDados(true);
}

void frmCadEnderecos_btnSalvarClick_cb(Fl_Button* b, void* v){
 if (frmCadEnderecos->SalvarDados(frmCadEnderecos->ValidaDados(true),
    ConsSQL->Endereco('S', frmCadEnderecos->edtCodigo->value(),
    "","","","",""),
    ConsSQL->Endereco('U', frmCadEnderecos->edtCodigo->value(), 
    frmCadEnderecos->edtDescricao->value(),
    frmCadEnderecos->edtBairro->value(),
    frmCadEnderecos->edtCep->value(),
    frmCadEnderecos->edtCidade->value(),
    frmCadEnderecos->cmbEstado->text(frmCadEnderecos->cmbEstado->value())),
    ConsSQL->Endereco('I', frmCadEnderecos->edtCodigo->value(), 
    frmCadEnderecos->edtDescricao->value(),
    frmCadEnderecos->edtBairro->value(),
    frmCadEnderecos->edtCep->value(),
    frmCadEnderecos->edtCidade->value(),
    frmCadEnderecos->cmbEstado->text(frmCadEnderecos->cmbEstado->value())), 
    true)) {
    frmCadEnderecos->InformaLimpaDados(false);
    frmCadEnderecos->HabilitaDados(false);	
  }  
}

void frmCadEnderecos_btnExcluirClick_cb(Fl_Button* b, void* v){
  if (frmCadEnderecos->ExcluirDados(frmCadEnderecos->ValidaDados(false),
    ConsSQL->Endereco('D', frmCadEnderecos->edtCodigo->value(),
    "","","","",""))) {
    frmCadEnderecos->InformaLimpaDados(false);
    frmCadEnderecos->HabilitaDados(false);	
  }  
}

void frmCadEnderecos_btnLimparClick_cb(Fl_Button* b, void* v){
  frmCadEnderecos->btnLimparClick();
  frmCadEnderecos->InformaLimpaDados(false);
  frmCadEnderecos->HabilitaDados(false);	
}

void frmCadEnderecos_btnFecharClick_cb(Fl_Button* b, void* v){
  frmCadEnderecos->hide();
}

int CfrmCadEnderecos::handle(int event) {
  if (event == FL_HIDE) {
    frmPrincipal->BarraDeStatus2->label("");
    frmPrincipal->mnuCadEnderecos->activate();
  }
  return CfrmCadastros::handle(event);
}

void CfrmCadEnderecos::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtBairro->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 2, nLinhaRegistro));
    edtCep->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 3, nLinhaRegistro));
    edtCidade->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 4, nLinhaRegistro));
    cmbEstado->value(cmbEstado->find_item(
      ListaStr->pesquisaItemOrdM(lstRegistros, 5, nLinhaRegistro)));
  } else {
    edtBairro->value("");
    edtCep->value("");
    edtCidade->value("");
    cmbEstado->value(0);
  }

} 

void CfrmCadEnderecos::HabilitaDados(bool bHabilita)
{
  if (bHabilita) {
    edtBairro->activate();
    edtCep->activate();
    edtCidade->activate();
    cmbEstado->activate();
  } else {
    edtBairro->deactivate();
    edtCep->deactivate();
    edtCidade->deactivate();
    cmbEstado->deactivate();
  }
}

void CfrmCadEnderecos::AdicionaCombo()
{ 
  cmbEstado->add(STR_PE);
  cmbEstado->add(STR_AC);
  cmbEstado->add(STR_AL);
  cmbEstado->add(STR_AP);
  cmbEstado->add(STR_AM);
  cmbEstado->add(STR_BA);
  cmbEstado->add(STR_BR);
  cmbEstado->add(STR_CE);
  cmbEstado->add(STR_DF);
  cmbEstado->add(STR_ES);
  cmbEstado->add(STR_GO);
  cmbEstado->add(STR_MT);
  cmbEstado->add(STR_MS);
  cmbEstado->add(STR_MG);
  cmbEstado->add(STR_PA);
  cmbEstado->add(STR_PB);
  cmbEstado->add(STR_PR);
  cmbEstado->add(STR_SC);
  cmbEstado->add(STR_RN);
  cmbEstado->add(STR_RS);
  cmbEstado->add(STR_RJ);
  cmbEstado->add(STR_RO);
  cmbEstado->add(STR_RR);
  cmbEstado->add(STR_SP);
  cmbEstado->add(STR_SE);
  cmbEstado->add(STR_TO);
}
