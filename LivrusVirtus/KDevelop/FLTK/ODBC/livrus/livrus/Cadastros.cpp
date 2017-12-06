#include "Cadastros.h"
#include "RotinasGlobais.h"

CfrmCadastros *frmCadastros;

CfrmCadastros::CfrmCadastros(bool bIniciaBotoes, char* sTitulo)
       : Fl_Double_Window(382, 136, sTitulo) {
	IniciaControles(bIniciaBotoes);
}

CfrmCadastros::~CfrmCadastros() { }

void CfrmCadastros::IniciaControles(bool bIniciaBotoes) {
  this->iconlabel((const char *)idata_Livrus);
  this->user_data((void*)(this));
  edtCodigo = new Fl_Input(10, 25, 140, 25, "C\363""digo:");
  edtCodigo->type(2);
  edtCodigo->align(FL_ALIGN_TOP_LEFT);
  edtCodigo->maximum_size(10);
  btnNovo = new Fl_Button(160, 25, 75, 25, "&Novo");
  edtDescricao = new Fl_Input(10, 70, 275, 25, "Descri\347\343o:");
  edtDescricao->align(FL_ALIGN_TOP_LEFT);    
  edtDescricao->deactivate();
  edtDescricao->maximum_size(30);

  if (bIniciaBotoes) {
    IniciaBotoes(300, 10, 60, 105);
  }
  nLinhaRegistro = 0;
}

void CfrmCadastros::IniciaBotoes(int nX1, int nY1, int nX2, int nY2) {
  btnPesquisar = new Fl_Button(nX1, nY1, 75, 25, "&Pesquisar");
  btnAnterior = new Fl_Button(nX1, nY1 + 30, 75, 25, "&Anterior");
  btnAnterior->deactivate();
  btnProximo = new Fl_Button(nX1, nY1 + 60, 75, 25, "Pr\363xi&mo");
  btnProximo->deactivate();
  btnSalvar = new Fl_Button(nX2, nY2, 75, 25, "&Salvar");
  btnSalvar->deactivate();
  btnExcluir = new Fl_Button(nX2 + 80, nY2, 75, 25, "&Excluir");
  btnExcluir->deactivate();
  btnLimpar = new Fl_Button(nX2 + 160, nY2, 75, 25, "&Limpar");
  btnFechar = new Fl_Button(nX2 + 240, nY2, 75, 25, "&Fechar");
  this->end();
}

void CfrmCadastros::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtCodigo->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 0, nLinhaRegistro));
    edtDescricao->value(
      ListaStr->pesquisaItemOrdM(lstRegistros, 1, nLinhaRegistro));
  } else {
    edtCodigo->value("");
    edtDescricao->value("");
    edtCodigo->activate();
    edtCodigo->take_focus();
  }
} 

void CfrmCadastros::HabilitaDados(bool bHabilita)
{
  if (bHabilita)
    edtDescricao->activate();
  else
    edtDescricao->deactivate();    
}

void CfrmCadastros::btnNovoClick()
{ 
  btnSalvar->activate();
  btnExcluir->deactivate();
  btnPesquisar->deactivate();
  btnAnterior->deactivate();
  btnProximo->deactivate();
  btnNovo->deactivate();
  
  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(true);	
}

void CfrmCadastros::NovoDado(string sTextoSql)
{ 
  LISTAMSTR lstRegs;

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegs, sTextoSql)) {
    edtCodigo->value(ListaStr->pesquisaItemOrdM(lstRegs, 0, 0));

    edtCodigo->deactivate();
    edtDescricao->take_focus();
  }
}

void CfrmCadastros::btnLimparClick() 
{
  nLinhaRegistro = 0;
  btnSalvar->deactivate();
  btnExcluir->deactivate();
  btnPesquisar->activate();
  btnAnterior->deactivate();
  btnProximo->deactivate();
  btnNovo->activate();

  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(false);	
}

bool CfrmCadastros::ExcluirDados(bool bValidaDados, string sTextoSql)
{
   if (bValidaDados) {

     if (fl_ask(STR_CERTEXCL)==1) {
        if (Rotinas->AtualizaDados(gConexao, sTextoSql)) {
           btnLimparClick();
           return true;
        }     
  	 }
   }
  return false;
}

bool CfrmCadastros::PesquisarDados(string sTextoSql, string sMensagemErro)
{  
	if (strlen(edtCodigo->value()) == 0) {
    btnAnterior->activate();
    btnProximo->activate();
	}

  if (Rotinas->ConsultaDadosLista(gConexao, &lstRegistros, sTextoSql)) {
     InformaLimpaDados(true);
     HabilitaDados(true);	

     btnSalvar->activate();
     btnExcluir->activate();
     btnPesquisar->deactivate();
     return true;
	} else
    fl_alert(sMensagemErro.c_str());

  return false;
}

bool CfrmCadastros::registroAnterior()
{
	if (nLinhaRegistro > 0) {
    nLinhaRegistro--;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

bool CfrmCadastros::registroProximo()
{
	if (nLinhaRegistro < abs(ListaStr->contaM(lstRegistros)-1)) {
    nLinhaRegistro++;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

bool CfrmCadastros::SalvarDados(bool bValidaDados, string sTextoSql, 
  string sTextoUpdate, string sTextoInsert, bool bLimparDados)
{
string sArquiva;

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
