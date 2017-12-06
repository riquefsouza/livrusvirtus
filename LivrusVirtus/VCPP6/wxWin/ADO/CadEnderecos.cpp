#include "resource.h"
#include "Cadastros.h"
#include "CadEnderecos.h"
#include "Principal.h"
#include "ConsultasSQL.h"

BEGIN_EVENT_TABLE(CfrmCadEnderecos, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadEnderecos::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadEnderecos::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadEnderecos::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadEnderecos::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadEnderecos::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadEnderecos::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadEnderecos::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadEnderecos::OnBtnFechar)
  EVT_CLOSE(CfrmCadEnderecos::OnClose)
END_EVENT_TABLE()

CfrmCadEnderecos::CfrmCadEnderecos(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NUMERIC, false) {
  CfrmCadEnderecos::IniciaControles();
}

CfrmCadEnderecos::~CfrmCadEnderecos() { }

void CfrmCadEnderecos::IniciaControles() {
  labDescricao->SetLabel(wxT("Logradouro: "));
  labDescricao->SetSize(wxSize(57, 13));
  edtDescricao->SetSize(wxSize(264, 21));
  
  labBairro = new wxStaticText(this, ID_FRMCADENDERECOS_LABBAIRRO,
   wxT("Bairro:"), wxPoint(280, 48), wxSize(48, 13), 0);
  edtBairro = new wxTextCtrl(this, ID_FRMCADENDERECOS_EDTBAIRRO,
   wxT(""), wxPoint(280, 64), wxSize(144, 21), 0);
  edtBairro->Enable(false);
  labCEP = new wxStaticText(this, ID_FRMCADENDERECOS_LABCEP,
   wxT("CEP: "), wxPoint(8, 88), wxSize(40, 13), 0);
  edtCEP = new wxTextCtrl(this, ID_FRMCADENDERECOS_EDTCEP, 
   wxT(""), wxPoint(8, 104), wxSize(72, 21), 0);
  edtCEP->Enable(false);
  labCidade = new wxStaticText(this, ID_FRMCADENDERECOS_LABCIDADE,
   wxT("Cidade: "), wxPoint(88, 88), wxSize(39, 13), 0);
  edtCidade = new wxTextCtrl(this, ID_FRMCADENDERECOS_EDTCIDADE,
    wxT(""), wxPoint(88, 104), wxSize(184, 21), 0);
  edtCidade->Enable(false);
  labEstado = new wxStaticText(this, ID_FRMCADENDERECOS_LABESTADO,
   wxT("Estado: "), wxPoint(280, 88), wxSize(56, 13), 0);
  cmbEstado = new wxChoice(this, ID_FRMCADENDERECOS_CMBESTADO,
   wxPoint(280, 104), wxSize(144, 21), 0);
  cmbEstado->Enable(false);

  IniciaBotoes();

  btnPesquisar->SetSize(440, 8, 75, 25);
  btnAnterior->SetSize(440, 40, 75, 25);
  btnProximo->SetSize(440, 72, 75, 25);
  btnSalvar->SetSize(200, 136, 75, 25);
  btnExcluir->SetSize(280, 136, 75, 25);
  btnLimpar->SetSize(360, 136, 75, 25);
  btnFechar->SetSize(440, 136, 75, 25);

  FazLayout();

  edtDescricao->SetMaxLength(40);
  edtBairro->SetMaxLength(15);
  edtCEP->SetMaxLength(8);
  edtCidade->SetMaxLength(30);
  AdicionaCombo();
}

void CfrmCadEnderecos::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_6 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_6 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_5 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_4 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_9 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_8 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_7 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_7 = new wxGridSizer(2, 1, 0, 0);
  grid_sizer_7->Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_7->Add(edtCodigo, 0, 0, 0);
  sizer_7->Add(grid_sizer_7, 0, 0, 0);
  sizer_7->Add(btnNovo, 0, wxLEFT|wxALIGN_BOTTOM, 5);
  sizer_5->Add(sizer_7, 1, 0, 0);
  grid_sizer_8->Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_8->Add(edtDescricao, 0, 0, 0);
  sizer_8->Add(grid_sizer_8, 0, 0, 0);
  grid_sizer_9->Add(labBairro, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_9->Add(edtBairro, 0, 0, 0);
  sizer_8->Add(grid_sizer_9, 0, wxLEFT, 2);
  sizer_5->Add(sizer_8, 1, wxEXPAND, 0);
  grid_sizer_4->Add(labCEP, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_4->Add(edtCEP, 0, 0, 0);
  sizer_6->Add(grid_sizer_4, 0, 0, 0);
  grid_sizer_5->Add(labCidade, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_5->Add(edtCidade, 0, 0, 0);
  sizer_6->Add(grid_sizer_5, 0, wxLEFT, 4);
  grid_sizer_6->Add(labEstado, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_6->Add(cmbEstado, 0, 0, 0);
  sizer_6->Add(grid_sizer_6, 0, wxLEFT, 5);
  sizer_5->Add(sizer_6, 0, 0, 0);
  sizer_3->Add(sizer_5, 0, 0, 0);
  sizer_4->Add(btnPesquisar, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_4->Add(btnAnterior, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_4->Add(btnProximo, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_3->Add(sizer_4, 1, 0, 0);
  sizer_1->Add(sizer_3, 1, wxALL|wxEXPAND, 4);
  sizer_2->Add(btnSalvar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_2->Add(btnExcluir, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_2->Add(btnLimpar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_2->Add(btnFechar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_1->Add(sizer_2, 0, wxRIGHT|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
}

bool CfrmCadEnderecos::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CODNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_ENDNINF))
    		return false;
  	  if (Rotinas->ValidaCampo(edtBairro->GetValue(), STR_BAIRRONINF))
    		return false;
  	  if (Rotinas->ValidaCampo(edtCEP->GetValue(), STR_CEPNINF))
    		return false;
  	  if (Rotinas->ValidaCampo(edtCidade->GetValue(), STR_CIDADENINF))
    		return false;
  	}
  	return true;
}

void CfrmCadEnderecos::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadEnderecos::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);	
  NovoDado(ConsSQL->Endereco('N', edtCodigo->GetValue(),"","","","",""));	
  event.Skip();
}

void CfrmCadEnderecos::OnBtnPesquisar(wxCommandEvent& event) {
  if (PesquisarDados(ConsSQL->Endereco('S', 
    edtCodigo->GetValue(),"","","","",""), STR_ENDNENC)) {
    InformaLimpaDados(true);
    HabilitaDados(true);	
  }
  event.Skip();
}

void CfrmCadEnderecos::OnBtnAnterior(wxCommandEvent& event) {
  if (registroAnterior())
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadEnderecos::OnBtnProximo(wxCommandEvent& event) {
  if (registroProximo())
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadEnderecos::OnBtnSalvar(wxCommandEvent& event) {
  if (SalvarDados(ValidaDados(true),
    ConsSQL->Endereco('S', edtCodigo->GetValue(),"","","","",""),
    ConsSQL->Endereco('U', edtCodigo->GetValue(), edtDescricao->GetValue(),
      edtBairro->GetValue(), edtCEP->GetValue(), edtCidade->GetValue(), 
      cmbEstado->GetStringSelection()),
    ConsSQL->Endereco('I', edtCodigo->GetValue(), edtDescricao->GetValue(),
      edtBairro->GetValue(), edtCEP->GetValue(), edtCidade->GetValue(), 
      cmbEstado->GetStringSelection()), true)) {
    InformaLimpaDados(false);
    HabilitaDados(false);	
  }  
  event.Skip();
}

void CfrmCadEnderecos::OnBtnExcluir(wxCommandEvent& event) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Endereco('D', edtCodigo->GetValue(),"","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);	
  }  
  event.Skip();
}

void CfrmCadEnderecos::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadEnderecos::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);	
  event.Skip();
}

void CfrmCadEnderecos::InformaLimpaDados(bool bInformar)
{
  if (bInformar) {
    edtBairro->SetValue(lstRegistros.col[2].Item(nLinhaRegistro));
    edtCEP->SetValue(lstRegistros.col[3].Item(nLinhaRegistro));
    edtCidade->SetValue(lstRegistros.col[4].Item(nLinhaRegistro));
    cmbEstado->SetStringSelection(lstRegistros.col[5].Item(nLinhaRegistro));
  } else {
    edtBairro->Clear();
    edtCEP->Clear();
    edtCidade->Clear();
    cmbEstado->SetSelection(0);
  }

} 

void CfrmCadEnderecos::HabilitaDados(bool bHabilita)
{
  edtBairro->Enable(bHabilita);
  edtCEP->Enable(bHabilita);  
  edtCidade->Enable(bHabilita);
  cmbEstado->Enable(bHabilita);  
}

void CfrmCadEnderecos::AdicionaCombo()
{ 
  cmbEstado->Append(STR_PE);
  cmbEstado->Append(STR_AC);
  cmbEstado->Append(STR_AL);
  cmbEstado->Append(STR_AP);
  cmbEstado->Append(STR_AM);
  cmbEstado->Append(STR_BA);
  cmbEstado->Append(STR_BR);
  cmbEstado->Append(STR_CE);
  cmbEstado->Append(STR_DF);
  cmbEstado->Append(STR_ES);
  cmbEstado->Append(STR_GO);
  cmbEstado->Append(STR_MT);
  cmbEstado->Append(STR_MS);
  cmbEstado->Append(STR_MG);
  cmbEstado->Append(STR_PA);
  cmbEstado->Append(STR_PB);
  cmbEstado->Append(STR_PR);
  cmbEstado->Append(STR_SC);
  cmbEstado->Append(STR_RN);
  cmbEstado->Append(STR_RS);
  cmbEstado->Append(STR_RJ);
  cmbEstado->Append(STR_RO);
  cmbEstado->Append(STR_RR);
  cmbEstado->Append(STR_SP);
  cmbEstado->Append(STR_SE);
  cmbEstado->Append(STR_TO);
}
