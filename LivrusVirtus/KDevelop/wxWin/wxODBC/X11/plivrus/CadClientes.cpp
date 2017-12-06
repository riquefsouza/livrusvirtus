#include "resource.h"
#include "Cadastros.h"
#include "CadClientes.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

BEGIN_EVENT_TABLE(CfrmCadClientes, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadClientes::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadClientes::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadClientes::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadClientes::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadClientes::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadClientes::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadClientes::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadClientes::OnBtnFechar)
  EVT_CLOSE(CfrmCadClientes::OnClose)
  EVT_BUTTON(ID_FRMCADCLIENTES_BTNPENDERECO, CfrmCadClientes::OnBtnPEndereco)
  EVT_BUTTON(ID_FRMCADCLIENTES_BTNPPAIS, CfrmCadClientes::OnBtnPPais)
  EVT_BUTTON(ID_FRMCADCLIENTES_BTNPPROFISSAO, CfrmCadClientes::OnBtnPProfissao)
END_EVENT_TABLE()

CfrmCadClientes::CfrmCadClientes(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NONE, false) {
  CfrmCadClientes::IniciaControles();
}

CfrmCadClientes::~CfrmCadClientes() { }

void CfrmCadClientes::IniciaControles() {
  labDescricao->SetLabel(wxT("Nome: "));
  edtDescricao->SetSize(wxSize(312, 21));

  edtCodigo->Connect(edtCodigo->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadClientes::OnEdtCodigo_Killfocus);

  labEmail = new wxStaticText(this, ID_FRMCADCLIENTES_LABEMAIL,
             wxT("E-mail: "), wxPoint(8, 88), wxSize(34, 13), 0);
  edtEmail = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTEMAIL,
             wxT(""), wxPoint(8, 104), wxSize(312, 21), 0);
  edtEmail->Enable(false);

  labIdentidade = new wxStaticText(this, ID_FRMCADCLIENTES_LABIDENTIDADE,
              wxT("Identidade: "), wxPoint(322, 88), wxSize(56, 13), 0);
  edtIdentidade = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTIDENTIDADE,
              wxT(""), wxPoint(322, 104), wxSize(100, 21), 0);
  edtIdentidade->Enable(false);

  wxString sItems[] = {wxT("Masculino"), wxT("Feminino")};
  rbSexo = new wxRadioBox(this, ID_FRMCADCLIENTES_RBSEXO, wxT("Sexo"),
              wxPoint(9, 128), wxSize(200, 44), 2, sItems, 2, 
              wxRA_SPECIFY_COLS);
  rbSexo->Enable(false);

  labTelefone = new wxStaticText(this, ID_FRMCADCLIENTES_LABTELEFONE,
              wxT("Telefone: "), wxPoint(216, 128), wxSize(48, 13), 0);
  edtTelefone = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTTELEFONE,
              wxT(""), wxPoint(216, 144), wxSize(104, 21), 0);
  edtTelefone->Enable(false);

  labDtNasc = new wxStaticText(this, ID_FRMCADCLIENTES_LABDTNASC,
              wxT("Dt. Nascimento"), wxPoint(322, 128), wxSize(73, 13), 0);
  #if __WXMSW__ || __WXX11__ || __WXMOTIF__
    edtDtNasc = new CDateCtrl(this, ID_FRMCADCLIENTES_EDTDTNASC,
              wxPoint(322, 144), wxSize(100, 21));
    edtDtNasc->Habilitar(false);
  #else
    edtDtNasc = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTDTNASC,
              wxT(""), wxPoint(322, 144), wxSize(100, 21), 0);
    edtDtNasc->Enable(false);
  #endif

  edtCodEndereco = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCODENDERECO,
              wxT(""), wxPoint(16, 200), wxSize(88, 21), 0);
  edtCodEndereco->Enable(false);
  edtCodEndereco->Connect(edtCodEndereco->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadClientes::OnEdtCodEndereco_Killfocus);

  btnPEndereco = new wxButton(this, ID_FRMCADCLIENTES_BTNPENDERECO,
              wxT("..."), wxPoint(104, 200), wxSize(21, 21), 0);
  btnPEndereco->Enable(false);

  labLogradouro = new wxStaticText(this, ID_FRMCADCLIENTES_LABLOGRADOURO,
              wxT("Logradouro: "), wxPoint(16, 224), wxSize(60, 13), 0);
  edtLogradouro = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTLOGRADOURO,
              wxT(""), wxPoint(16, 240), wxSize(264, 21), 0);
  edtLogradouro->Enable(false);

  labBairro = new wxStaticText(this, ID_FRMCADCLIENTES_LABBAIRRO,
              wxT("Bairro:"), wxPoint(284, 224), wxSize(48, 13), 0);
  edtBairro = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTBAIRRO,
              wxT(""), wxPoint(284, 240), wxSize(144, 21), 0);
  edtBairro->Enable(false);

  labCEP = new wxStaticText(this, ID_FRMCADCLIENTES_LABCEP, wxT("CEP: "),
              wxPoint(16, 264), wxSize(40, 13), 0);
  edtCEP = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCEP, wxT(""),
              wxPoint(16, 280), wxSize(78, 21), 0);
  edtCEP->Enable(false);

  labCidade = new wxStaticText(this, ID_FRMCADCLIENTES_LABCIDADE,
              wxT("Cidade: "), wxPoint(96, 264), wxSize(39, 13), 0);
  edtCidade = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCIDADE,
              wxT(""), wxPoint(96, 280), wxSize(184, 21), 0);
  edtCidade->Enable(false);

  labEstado = new wxStaticText(this, ID_FRMCADCLIENTES_LABESTADO,
              wxT("Estado: "), wxPoint(284, 264), wxSize(56, 13), 0);
  edtEstado = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTESTADO,
              wxT(""), wxPoint(284, 280), wxSize(144, 21), 0);
  edtEstado->Enable(false);

  labPais = new wxStaticText(this, ID_FRMCADCLIENTES_LABPAIS,
              wxT("País de origem: "), wxPoint(8, 320), wxSize(77, 16), 0);
  edtCodPais = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCODPAIS,
              wxT(""), wxPoint(8, 336), wxSize(78, 21), 0);
  edtCodPais->Enable(false);
  edtCodPais->Connect(edtCodPais->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadClientes::OnEdtCodPais_Killfocus);
  edtPais = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTPAIS,
              wxT(""), wxPoint(88, 336), wxSize(240, 21), 0);
  edtPais->Enable(false);
  btnPPais = new wxButton(this, ID_FRMCADCLIENTES_BTNPPAIS, wxT("..."),
               wxPoint(328, 336), wxSize(21, 21), 0);
  btnPPais->Enable(false);

  labProfissao = new wxStaticText(this, ID_FRMCADCLIENTES_LABPROFISSAO,
              wxT("Profissão: "), wxPoint(8, 360), wxSize(56, 13), 0);
  edtCodProfissao = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTCODPROFISSAO,
              wxT(""), wxPoint(8, 376), wxSize(78, 21), 0);
  edtCodProfissao->Enable(false);
  edtCodProfissao->Connect(edtCodProfissao->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadClientes::OnEdtCodProfissao_Killfocus);
  edtProfissao = new wxTextCtrl(this, ID_FRMCADCLIENTES_EDTPROFISSAO,
              wxT(""), wxPoint(88, 376), wxSize(240, 21), 0);
  edtProfissao->Enable(false);
  btnPProfissao = new wxButton(this, ID_FRMCADCLIENTES_BTNPPROFISSAO,
              wxT("..."), wxPoint(328, 376), wxSize(21, 21), 0);
  btnPProfissao->Enable(false);

  IniciaBotoes();
  btnPesquisar->SetSize(440, 8, 75, 25);
  btnAnterior->SetSize(440, 40, 75, 25);
  btnProximo->SetSize(440, 72, 75, 25);
  btnSalvar->SetSize(200, 408, 75, 25);
  btnExcluir->SetSize(280, 408, 75, 25);
  btnLimpar->SetSize(360, 408, 75, 25);
  btnFechar->SetSize(440, 408, 75, 25);

  FazLayout();

	edtCodigo->SetMaxLength(14);
  edtDescricao->SetMaxLength(30);
  edtEmail->SetMaxLength(30);
  edtIdentidade->SetMaxLength(10);
  edtCodEndereco->SetMaxLength(10);
  edtTelefone->SetMaxLength(17);
  edtCodPais->SetMaxLength(3);
  edtCodProfissao->SetMaxLength(10);

}

void CfrmCadClientes::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_16 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_23 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_22 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_19 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_15 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_21 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_20 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_18 = new wxGridSizer(2, 1, 0, 0);
  wxStaticBoxSizer* sizer_11 = new 
    wxStaticBoxSizer(new wxStaticBox(this, -1, wxT("Endereço")), wxVERTICAL);
  wxBoxSizer* sizer_14 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_17 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_16 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_15 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_13 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_14 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_13 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_12 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_10 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_12 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_11 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_6 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_5 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_4 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
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
  sizer_5->Add(sizer_8, 1, wxEXPAND, 0);
  grid_sizer_4->Add(labEmail, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_4->Add(edtEmail, 0, 0, 0);
  sizer_6->Add(grid_sizer_4, 0, 0, 0);
  grid_sizer_5->Add(labIdentidade, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_5->Add(edtIdentidade, 0, 0, 0);
  sizer_6->Add(grid_sizer_5, 0, wxLEFT, 4);
  sizer_5->Add(sizer_6, 0, 0, 0);
  sizer_10->Add(rbSexo, 0, 0, 0);
  grid_sizer_11->Add(labTelefone, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_11->Add(edtTelefone, 0, 0, 0);
  sizer_10->Add(grid_sizer_11, 1, wxLEFT|wxEXPAND, 4);
  grid_sizer_12->Add(labDtNasc, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_12->Add(edtDtNasc, 0, 0, 0);
  sizer_10->Add(grid_sizer_12, 1, wxLEFT|wxEXPAND, 4);
  sizer_5->Add(sizer_10, 1, wxEXPAND, 0);
  sizer_12->Add(edtCodEndereco, 0, 0, 0);
  sizer_12->Add(btnPEndereco, 0, 0, 0);
  sizer_11->Add(sizer_12, 0, wxALL, 2);
  grid_sizer_13->Add(labLogradouro, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_13->Add(edtLogradouro, 0, 0, 0);
  sizer_13->Add(grid_sizer_13, 0, 0, 0);
  grid_sizer_14->Add(labBairro, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_14->Add(edtBairro, 0, 0, 0);
  sizer_13->Add(grid_sizer_14, 0, wxLEFT, 4);
  sizer_11->Add(sizer_13, 0, 0, 0);
  grid_sizer_15->Add(labCEP, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_15->Add(edtCEP, 0, 0, 0);
  sizer_14->Add(grid_sizer_15, 0, 0, 0);
  grid_sizer_16->Add(labCidade, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_16->Add(edtCidade, 0, 0, 0);
  sizer_14->Add(grid_sizer_16, 0, wxLEFT, 4);
  grid_sizer_17->Add(labEstado, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_17->Add(edtEstado, 0, 0, 0);
  sizer_14->Add(grid_sizer_17, 0, wxLEFT, 4);
  sizer_11->Add(sizer_14, 1, 0, 0);
  sizer_5->Add(sizer_11, 0, 0, 0);
  grid_sizer_18->Add(labPais, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_18->Add(edtCodPais, 0, 0, 0);
  sizer_15->Add(grid_sizer_18, 0, 0, 0);
  grid_sizer_20->Add(20, 20, 0, 0, 0);
  grid_sizer_20->Add(edtPais, 0, 0, 0);
  sizer_15->Add(grid_sizer_20, 0, wxLEFT, 2);
  grid_sizer_21->Add(20, 20, 0, 0, 0);
  grid_sizer_21->Add(btnPPais, 0, 0, 0);
  sizer_15->Add(grid_sizer_21, 0, 0, 0);
  sizer_5->Add(sizer_15, 0, 0, 0);
  grid_sizer_19->Add(labProfissao, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_19->Add(edtCodProfissao, 0, 0, 0);
  sizer_16->Add(grid_sizer_19, 0, 0, 0);
  grid_sizer_22->Add(20, 20, 0, 0, 0);
  grid_sizer_22->Add(edtProfissao, 0, 0, 0);
  sizer_16->Add(grid_sizer_22, 0, wxLEFT, 2);
  grid_sizer_23->Add(20, 20, 0, 0, 0);
  grid_sizer_23->Add(btnPProfissao, 0, 0, 0);
  sizer_16->Add(grid_sizer_23, 0, 0, 0);
  sizer_5->Add(sizer_16, 0, 0, 0);
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

bool CfrmCadClientes::ValidaDados(bool bTodosDados)
{
  if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CPFNINF))
  	  return false;
  if (bTodosDados) {
    if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_CLININF))
      return false;
    if (Rotinas->ValidaCampo(edtEmail->GetValue(), STR_EMAILNINF))
      return false;
	  if (Rotinas->ValidaCampo(edtTelefone->GetValue(), STR_TELNINF))
		  return false;
	  if (Rotinas->ValidaCampo(edtCodEndereco->GetValue(), STR_ENDNINF))
		  return false;
	  if (Rotinas->ValidaCampo(edtCodPais->GetValue(), STR_PAISNINF))
		  return false;
	  if (Rotinas->ValidaCampo(edtCodProfissao->GetValue(), STR_PROFNINF))
		  return false;
  }
  return true;
}

void CfrmCadClientes::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadClientes::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  event.Skip();
}

void CfrmCadClientes::OnBtnPesquisar(wxCommandEvent& event) {
  if (PesquisarDados(
    ConsSQL->Cliente('S', edtCodigo->GetValue(),
    "","","","","","","","",""), STR_CLINENC, 17)) {
    InformaLimpaDados(true);
    HabilitaDados(true);	
  }
  event.Skip();
}

void CfrmCadClientes::OnBtnAnterior(wxCommandEvent& event) {
  if (registroAnterior())
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadClientes::OnBtnProximo(wxCommandEvent& event) {
  if (registroProximo())
    InformaLimpaDados(true);		
  event.Skip();
}

void CfrmCadClientes::OnBtnSalvar(wxCommandEvent& event) {

  wxString sSexo, sDtNasc, sSqlInsert, sSqlUpdate;

  if (rbSexo->GetSelection() == 0)
     sSexo = "M"; 
  else   
     sSexo = "F";

  sDtNasc = edtDtNasc->GetDataStr(false);

  sSqlUpdate = ConsSQL->Cliente('U', edtCodigo->GetValue(), edtDescricao->GetValue(), 
    edtEmail->GetValue(),  edtIdentidade->GetValue(), sSexo,  
    edtTelefone->GetValue(), sDtNasc, edtCodEndereco->GetValue(), 
    edtCodPais->GetValue(), edtCodProfissao->GetValue());

  sSqlInsert = ConsSQL->Cliente('I', edtCodigo->GetValue(), edtDescricao->GetValue(), 
    edtEmail->GetValue(),  edtIdentidade->GetValue(), sSexo,  
    edtTelefone->GetValue(), sDtNasc, edtCodEndereco->GetValue(), 
    edtCodPais->GetValue(), edtCodProfissao->GetValue());

  if (SalvarDados(ValidaDados(true),
    ConsSQL->Cliente('S', edtCodigo->GetValue(),"","","","","","","","",""),
    sSqlUpdate, sSqlInsert, true)) {
    InformaLimpaDados(false);
    HabilitaDados(false);	
  }
  event.Skip();
}

void CfrmCadClientes::OnBtnExcluir(wxCommandEvent& event) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Cliente('D', edtCodigo->GetValue(),
    "","","","","","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);	
  }  
  event.Skip();
}

void CfrmCadClientes::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadClientes::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);	
  event.Skip();
}

void CfrmCadClientes::InformaLimpaDados(bool bInformar)
{ 
  if (bInformar) {
    edtEmail->SetValue(lstRegistros.col[2].Item(nLinhaRegistro));
    edtIdentidade->SetValue(lstRegistros.col[3].Item(nLinhaRegistro));
    if (lstRegistros.col[4].Item(nLinhaRegistro).Cmp("M")==0)
      rbSexo->SetSelection(0);
    else
      rbSexo->SetSelection(1);
    edtTelefone->SetValue(lstRegistros.col[5].Item(nLinhaRegistro));
    edtDtNasc->SetDataStr(lstRegistros.col[6].Item(nLinhaRegistro).Mid(0,10),false);
    edtCodEndereco->SetValue(lstRegistros.col[7].Item(nLinhaRegistro));
    edtLogradouro->SetValue(lstRegistros.col[8].Item(nLinhaRegistro));
    edtBairro->SetValue(lstRegistros.col[9].Item(nLinhaRegistro));
    edtCEP->SetValue(lstRegistros.col[10].Item(nLinhaRegistro));
    edtCidade->SetValue(lstRegistros.col[11].Item(nLinhaRegistro));
    edtEstado->SetValue(lstRegistros.col[12].Item(nLinhaRegistro));
    edtCodPais->SetValue(lstRegistros.col[13].Item(nLinhaRegistro));
    edtPais->SetValue(lstRegistros.col[14].Item(nLinhaRegistro));
    edtCodProfissao->SetValue(lstRegistros.col[15].Item(nLinhaRegistro));
    edtProfissao->SetValue(lstRegistros.col[16].Item(nLinhaRegistro));
  } else {
    edtEmail->Clear();
    edtIdentidade->Clear();
    rbSexo->SetSelection(0);
    edtTelefone->Clear();
    edtDtNasc->Limpar();
    edtCodEndereco->Clear();
    edtLogradouro->Clear();
    edtBairro->Clear();
    edtCEP->Clear();
    edtCidade->Clear();
    edtEstado->Clear();
    edtCodPais->Clear();
    edtPais->Clear();
    edtCodProfissao->Clear();
    edtProfissao->Clear();
    edtCodigo->SetFocus();
  }
} 

void CfrmCadClientes::HabilitaDados(bool bHabilita)
{
  edtEmail->Enable(bHabilita);
  edtIdentidade->Enable(bHabilita);
  rbSexo->Enable(bHabilita);
  edtTelefone->Enable(bHabilita);
  edtDtNasc->Habilitar(bHabilita);
  edtCodEndereco->Enable(bHabilita);
  btnPEndereco->Enable(bHabilita);
  edtCodPais->Enable(bHabilita);
  btnPPais->Enable(bHabilita);
  edtCodProfissao->Enable(bHabilita);
  btnPProfissao->Enable(bHabilita);
}

void CfrmCadClientes::OnEdtCodigo_Killfocus(wxFocusEvent& event)
{ wxTextCtrl *mCodigo;
 
  mCodigo = (wxTextCtrl*)event.GetEventObject();

  if (mCodigo->GetValue().Len() > 0) {
  	if (Rotinas->validaCPF(mCodigo->GetValue())==false) {      
      wxMessageBox(STR_CPFINV, wxT("Erro"), wxOK | wxICON_ERROR);
      mCodigo->Clear();
  		mCodigo->SetFocus();
  	}
  }	
}

void CfrmCadClientes::OnEdtCodEndereco_Killfocus() 
{ wxString sLogradouro;
  wxTextCtrl *m_EdtCodEnd, *m_EdtLogradouro, *m_EdtBairro, 
    *m_EdtCep, *m_EdtCidade, *m_EdtEstado;
  LISTAMSTR ConsCampo;

  m_EdtCodEnd = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTCODENDERECO);
  m_EdtLogradouro = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTLOGRADOURO);
  m_EdtBairro = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTBAIRRO);
  m_EdtCep = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTCEP);
  m_EdtCidade = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTCIDADE);
  m_EdtEstado = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTESTADO);

  if (m_EdtCodEnd->GetValue().Len() > 0) {
    sLogradouro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Endereco('S',
    m_EdtCodEnd->GetValue(),"","","","",""),STR_ENDNENC, 6);
    if (sLogradouro.Len() > 0) {
      m_EdtLogradouro->SetValue(sLogradouro);
      m_EdtBairro->SetValue(ConsCampo.col[2].Item(0));
      m_EdtCep->SetValue(ConsCampo.col[3].Item(0));
      m_EdtCidade->SetValue(ConsCampo.col[4].Item(0));
      m_EdtEstado->SetValue(ConsCampo.col[5].Item(0));
    } else {
  	  m_EdtCodEnd->SetFocus();
      m_EdtLogradouro->Clear();
      m_EdtBairro->Clear();
      m_EdtCep->Clear();
  	  m_EdtCidade->Clear();
  	  m_EdtEstado->Clear();
    }
  } else {
    m_EdtLogradouro->Clear();
    m_EdtBairro->Clear();
    m_EdtCep->Clear();
	  m_EdtCidade->Clear();
	  m_EdtEstado->Clear();
  }
}

void CfrmCadClientes::OnEdtCodPais_Killfocus() 
{ wxString sPais;
  wxTextCtrl *m_EdtCodPais, *m_EdtPais;
  LISTAMSTR ConsCampo;

  m_EdtCodPais = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTCODPAIS);
  m_EdtPais = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTPAIS);

  if (m_EdtCodPais->GetValue().Len() > 0) {
    sPais = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Pais('S',
      m_EdtCodPais->GetValue(),""),STR_PAISNENC, 2);    
    if (sPais.Len() > 0) {
      m_EdtPais->SetValue(sPais);
    } else {
      m_EdtCodPais->Clear();
      m_EdtCodPais->SetFocus();
    }
  } else {
    m_EdtPais->Clear();
  }
}

void CfrmCadClientes::OnEdtCodProfissao_Killfocus() 
{ wxString sProfissao;
  wxTextCtrl *m_EdtCodProfissao, *m_EdtProfissao;
  LISTAMSTR ConsCampo;

  m_EdtCodProfissao = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTCODPROFISSAO);
  m_EdtProfissao = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADCLIENTES_EDTPROFISSAO);

  if (m_EdtCodProfissao->GetValue().Len() > 0) {
    sProfissao = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Profissao('S',
      m_EdtCodProfissao->GetValue(),""),STR_PROFNENC, 2);    

    if (sProfissao.Len() > 0) {
      m_EdtProfissao->SetValue(sProfissao);
    } else {
      m_EdtCodProfissao->Clear();
      m_EdtCodProfissao->SetFocus();
    }
  } else {
    m_EdtProfissao->Clear();
  }
}

void CfrmCadClientes::OnBtnPEndereco(wxCommandEvent& event) {
  CfrmConEnderecos *fConEnderecos = new CfrmConEnderecos(this);
  fConEnderecos->ShowModal();
  edtCodEndereco->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodEndereco_Killfocus();
  event.Skip();
}

void CfrmCadClientes::OnBtnPPais(wxCommandEvent& event) {
  CfrmConPaises *fConPaises = new CfrmConPaises(this);
  fConPaises->ShowModal();
  edtCodPais->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodPais_Killfocus();
  event.Skip();
}

void CfrmCadClientes::OnBtnPProfissao(wxCommandEvent& event) {
  CfrmConProfissoes *fConProfissoes = new CfrmConProfissoes(this);
  fConProfissoes->ShowModal();
  edtCodProfissao->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodProfissao_Killfocus();
  event.Skip();
}


