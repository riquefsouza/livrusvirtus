#include "resource.h"
#include "Consultas.h"
#include "Principal.h"

#ifndef __WXMOTIF__
  #include "xpms/livrus.xpm"
#endif  

CfrmConsultas::CfrmConsultas(wxWindow *parent)
  : wxDialog(parent, -1, wxT("Consulta de"), wxPoint(0, 0), wxSize(355, 263),
 	wxDEFAULT_DIALOG_STYLE | wxCAPTION | wxRESIZE_BORDER | 
  wxMINIMIZE_BOX | wxMAXIMIZE_BOX) {
	IniciaControles();
}

CfrmConsultas::~CfrmConsultas() { }

void CfrmConsultas::IniciaControles() {

#ifdef __WXMSW__
    this->SetIcon(wxIcon(wxT("LIVRUS_ICO")));
#else
  #ifndef __WXMOTIF__
    this->SetIcon(wxIcon( Livrus_xpm ));
  #endif
#endif

  this->SetClientSize(wxSize(355, 263));
  this->Centre(wxBOTH);

  this->labDescricao = new wxStaticText(this, ID_FRMCONSULTAS_LABDESCRICAO,
    wxT("Descrição:"), wxPoint(8, 8), wxSize(51, 13), 0);
  this->edtDescricao = new wxTextCtrl(this, ID_FRMCONSULTAS_EDTDESCRICAO,
    wxT(""), wxPoint(8, 24), wxSize(257, 21), 0);
  this->btnPesquisar = new wxButton(this, ID_FRMCONSULTAS_BTNPESQUISAR,
    wxT("&Pesquisar"), wxPoint(272, 24), wxSize(75, 25), 0);

  this->gridConsulta = new wxGrid(this, ID_FRMCONSULTAS_GRIDCONSULTA, 
    wxPoint(0, 56), wxSize(355, 125), wxSUNKEN_BORDER);
  this->gridConsulta->CreateGrid(1, 2, wxGrid::wxGridSelectRows);
  this->gridConsulta->SetColLabelValue(0, wxT("Código"));
  this->gridConsulta->SetColSize(0, 80);
  this->gridConsulta->SetColLabelValue(1, wxT("Descrição"));
  this->gridConsulta->SetColSize(1, 180);
  this->gridConsulta->EnableEditing(false);
  this->gridConsulta->HideCellEditControl();
  this->gridConsulta->SetColLabelSize(21);

  this->labRegistro = new wxStaticText(this, ID_FRMCONSULTAS_LABREGISTRO,
    wxT("Registro 0 de 0"), wxPoint(8, 16), wxSize(144, 13), 0);
  this->btnLimpar = new wxButton(this, ID_FRMCONSULTAS_BTNLIMPAR,
    wxT("&Limpar"), wxPoint(16, 13), wxSize(75, 25), 0);
  this->btnFechar = new wxButton(this, ID_FRMCONSULTAS_BTNFECHAR,
    wxT("&Fechar"), wxPoint(75, 13), wxSize(75, 25), 0);

  FazLayout();

  this->edtDescricao->SetFocus();
  nRegistro = 0;
}

void CfrmConsultas::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxGridSizer* gird_sizer_2 = new wxGridSizer(1, 2, 0, 0);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  wxGridSizer* grid_sizer_1 = new wxGridSizer(2, 1, 0, 0);
  grid_sizer_1->Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_1->Add(edtDescricao, 0, 0, 0);
  sizer_3->Add(grid_sizer_1, 0, wxALL, 2);
  sizer_4->Add(20, 20, 0, 0, 0);
  sizer_4->Add(btnPesquisar, 0, wxLEFT|wxTOP|wxBOTTOM, 5);
  sizer_3->Add(sizer_4, 0, 0, 0);
  sizer_1->Add(sizer_3, 0, wxALL, 4);
  sizer_1->Add(gridConsulta, 1, wxEXPAND, 0);
  gird_sizer_2->Add(labRegistro, 0, wxALL, 10);
  sizer_2->Add(btnLimpar, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 8);
  sizer_2->Add(btnFechar, 0, wxLEFT|wxALIGN_RIGHT|wxALIGN_BOTTOM, 8);
  gird_sizer_2->Add(sizer_2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4);
  sizer_1->Add(gird_sizer_2, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM, 0);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
  Layout();
}

void CfrmConsultas::Fecha(int nIndMenu) {
  if (sSelecionado.Len() > 0)
    Rotinas_sCodigoSelecionado = sSelecionado;
  else
    Rotinas_sCodigoSelecionado = ""; 

  if (nIndMenu == 0) {
    if (IsModal())
      EndModal(true);
    else
      Close();
  } else
    frmPrincipal->barraMenu->GetMenu(1)->Enable(nIndMenu, true);
}

void CfrmConsultas::LimparDados() {
  labRegistro->SetLabel(wxT("Registro 0 de 0"));
  gridConsulta->ClearGrid();
  gridConsulta->DeleteRows(0,gridConsulta->GetNumberRows()-1,true);
  edtDescricao->Clear();
  edtDescricao->SetFocus();
}

void CfrmConsultas::PesquisarDados(wxString sTextoSql, wxString sMensagemErro,
                                    unsigned long nQtdCol) {

  if (Rotinas->ConsultaDadosLista(gConexao, &lstLinhas, sTextoSql, nQtdCol))
    Rotinas->AdicionaLinhasGrid(gridConsulta, lstLinhas, nQtdCol);
  else
     wxMessageBox(sMensagemErro,wxT("Erro"), wxOK | wxICON_ERROR);
}

void CfrmConsultas::setLabRegistros(int nLinha) {
  if (nLinha >= 0) {
    labRegistro->SetLabel(wxString::Format("Registro %d de %d", nLinha+1, 
      gridConsulta->GetNumberRows()));
    sSelecionado = gridConsulta->GetCellValue(nLinha, 0);
  }
}

