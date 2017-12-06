#include "resource.h"
#include "Cadastros.h"

CfrmCadastros::CfrmCadastros(wxWindow *parent, long nFiltroCodigo, 
                             bool bIniciaBotoes)
       : wxPanel(parent, -1, wxPoint(0, 0), wxSize(330, 140)) {
	IniciaControles(nFiltroCodigo, bIniciaBotoes);
}

CfrmCadastros::~CfrmCadastros() { }

void CfrmCadastros::IniciaControles(long nFiltroCodigo, bool bIniciaBotoes) {

  this->labCodigo = new wxStaticText(this, ID_FRMCADASTROS_LABCODIGO,
    wxT("Código:"), wxPoint(8, 8), wxSize(36, 13), 0);  
  this->edtCodigo = new wxTextCtrl(this, ID_FRMCADASTROS_EDTCODIGO,
    wxT(""), wxPoint(8, 24), wxSize(121, 21), 0, 
    wxTextValidator(nFiltroCodigo, NULL));  
  this->btnNovo = new wxButton(this, ID_FRMCADASTROS_BTNNOVO, 
  	wxT("&Novo"), wxPoint(144, 24), wxSize(75, 25), 0);
  this->labDescricao = new wxStaticText(this, ID_FRMCADASTROS_LABDESCRICAO,
    wxT("Descrição:"), wxPoint(8, 48), wxSize(51, 13), 0);  
  this->edtDescricao = new wxTextCtrl(this, ID_FRMCADASTROS_EDTDESCRICAO,
    wxT(""), wxPoint(8, 64), wxSize(217, 21), 0);  

  if (bIniciaBotoes) {
    IniciaBotoes();
    FazLayout();
  }
  this->edtCodigo->SetMaxLength(10);
  this->edtDescricao->SetMaxLength(30);
  nLinhaRegistro = 0;
}

// Necessário por causa da tabulação dos campos
void CfrmCadastros::IniciaBotoes() {
  this->btnPesquisar = new wxButton(this, ID_FRMCADASTROS_BTNPESQUISAR,
    wxT("&Pesquisar"), wxPoint(248, 8), wxSize(75, 25), 0);  
  this->btnAnterior = new wxButton(this, ID_FRMCADASTROS_BTNANTERIOR,
    wxT("&Anterior"), wxPoint(248, 40), wxSize(75, 25), 0);  
  this->btnProximo = new wxButton(this, ID_FRMCADASTROS_BTNPROXIMO,
    wxT("Próxi&mo"), wxPoint(248, 72), wxSize(75, 25), 0);  
  this->btnSalvar = new wxButton(this, ID_FRMCADASTROS_BTNSALVAR,
    wxT("&Salvar"), wxPoint(8, 104), wxSize(75, 25), 0);  
  this->btnExcluir = new wxButton(this, ID_FRMCADASTROS_BTNEXCLUIR,
    wxT("&Excluir"), wxPoint(88, 104), wxSize(75, 25), 0);  
  this->btnLimpar = new wxButton(this, ID_FRMCADASTROS_BTNLIMPAR,
    wxT("&Limpar"), wxPoint(168, 104), wxSize(75, 25), 0); 
  this->btnFechar = new wxButton(this, ID_FRMCADASTROS_BTNFECHAR,
    wxT("&Fechar"), wxPoint(248, 104), wxSize(75, 25), 0);  

  btnLimparClick();
}

void CfrmCadastros::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
  wxGridSizer* grid_sizer_2 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_1 = new wxGridSizer(2, 2, 0, 1);
  grid_sizer_1->Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_1->Add(20, 10, 0, 0, 0);
  grid_sizer_1->Add(edtCodigo, 0, 0, 0);
  grid_sizer_1->Add(btnNovo, 0, wxLEFT, 6);
  sizer_5->Add(grid_sizer_1, 0, 0, 0);
  grid_sizer_2->Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_2->Add(edtDescricao, 0, 0, 2);
  sizer_5->Add(grid_sizer_2, 0, 0, 0);
  sizer_3->Add(sizer_5, 1, 0, 0);
  sizer_4->Add(btnPesquisar, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_4->Add(btnAnterior, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_4->Add(btnProximo, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_3->Add(sizer_4, 0, wxALIGN_RIGHT, 0);
  sizer_1->Add(sizer_3, 1, wxALL|wxEXPAND, 4);
  sizer_2->Add(btnSalvar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_2->Add(btnExcluir, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_2->Add(btnLimpar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_2->Add(btnFechar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_1->Add(sizer_2, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
}

void CfrmCadastros::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtCodigo->SetValue(lstRegistros.col[0].Item(nLinhaRegistro));
    edtDescricao->SetValue(lstRegistros.col[1].Item(nLinhaRegistro));
  } else {
    edtCodigo->Clear();
    edtDescricao->Clear();
    edtCodigo->Enable(true);
    edtCodigo->SetFocus();
  }
} 

void CfrmCadastros::HabilitaDados(bool bHabilita)
{
  edtDescricao->Enable(bHabilita);
}

void CfrmCadastros::btnNovoClick()
{ 
  btnSalvar->Enable(true);
  btnExcluir->Enable(false);
  btnPesquisar->Enable(false);
  btnAnterior->Enable(false);
  btnProximo->Enable(false);
  btnNovo->Enable(false);
  
  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(true);	
}

void CfrmCadastros::NovoDado(wxString sTextoSql)
{ 
  LISTAMSTR lstRegs;

  if (Rotinas->ConsultaDadosLista(wxBanco, &lstRegs, sTextoSql, 1)) {
    edtCodigo->SetValue(lstRegs.col[0].Item(0));

    edtCodigo->Enable(false);
    edtDescricao->SetFocus();
  }
}

void CfrmCadastros::btnLimparClick() 
{
  nLinhaRegistro = 0;
  btnSalvar->Enable(false);
  btnExcluir->Enable(false);
  btnPesquisar->Enable(true);
  btnAnterior->Enable(false);
  btnProximo->Enable(false);
  btnNovo->Enable(true);

  nLinhaRegistro = 0;
  InformaLimpaDados(false);
  HabilitaDados(false);	
}

bool CfrmCadastros::ExcluirDados(bool bValidaDados, wxString sTextoSql)
{
   if (bValidaDados) {

     if ( wxMessageBox(STR_CERTEXCL, wxT("Confirme"),
                      wxICON_QUESTION | wxYES_NO) == wxYES ) {       
        if (Rotinas->AtualizaDados(wxBanco, sTextoSql)) {
           btnLimparClick();
           return true;
        }

  	 }
   }
  return false;
}

bool CfrmCadastros::PesquisarDados(wxString sTextoSql, wxString sMensagemErro, 
                                   unsigned long nQtdCol)
{  
	if (edtCodigo->GetValue().Len() == 0) {
    btnAnterior->Enable(true);
    btnProximo->Enable(true);
	}

  if (Rotinas->ConsultaDadosLista(wxBanco, &lstRegistros, sTextoSql, nQtdCol)) {
     InformaLimpaDados(true);
     HabilitaDados(true);	

     btnSalvar->Enable(true);
     btnExcluir->Enable(true);
     btnPesquisar->Enable(false);
     return true;
	} else
    wxMessageBox(sMensagemErro, wxT("Erro"), wxOK | wxICON_ERROR);

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
	if (nLinhaRegistro < (lstRegistros.col[0].GetCount()-1)) {
    nLinhaRegistro++;
    InformaLimpaDados(true);
    return true;
	} else
    return false;
}

bool CfrmCadastros::SalvarDados(bool bValidaDados, wxString sTextoSql, 
  wxString sTextoUpdate, wxString sTextoInsert, bool bLimparDados)
{
wxString sArquiva;

	if (bValidaDados) {    
	   if (Rotinas->ConsultaDados(wxBanco,sTextoSql))
         sArquiva = sTextoUpdate;
     else
  	     sArquiva = sTextoInsert;	  	     

     if (Rotinas->AtualizaDados(wxBanco, sArquiva)) {
  	   if (bLimparDados)
         btnLimparClick();
       return true;
     }
	}
  return false;
}
