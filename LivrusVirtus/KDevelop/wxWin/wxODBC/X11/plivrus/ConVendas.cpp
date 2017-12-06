#include "resource.h"
#include "Cadastros.h"
#include "ConVendas.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

BEGIN_EVENT_TABLE(CfrmConVendas, wxPanel)
  EVT_BUTTON(ID_FRMCONVENDAS_BTNPESQUISAR, CfrmConVendas::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONVENDAS_BTNLIMPAR, CfrmConVendas::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONVENDAS_BTNFECHAR, CfrmConVendas::OnBtnFechar)
  EVT_CLOSE(CfrmConVendas::OnClose)
  EVT_BUTTON(ID_FRMCONVENDAS_BTNPCLIENTE, CfrmConVendas::OnBtnPCliente)
  EVT_BUTTON(ID_FRMCONVENDAS_BTNPLIVRO, CfrmConVendas::OnBtnPLivro)
  EVT_GRID_SELECT_CELL(CfrmConVendas::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConVendas::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConVendas::CfrmConVendas(wxWindow *parent)
       : wxPanel(parent, -1, wxPoint(0, 0), wxSize(480, 310)) {
  CfrmConVendas::IniciaControles();
}

CfrmConVendas::~CfrmConVendas() { }

void CfrmConVendas::IniciaControles() {
  labDtHrVenda = new wxStaticText(this, ID_FRMCONVENDAS_LABDTHRVENDA,
    wxT("Data/Hora Venda: "), wxPoint(8, 8), wxSize(91, 13), 0);  
  edtDtHrVenda = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTDTHRVENDA,
    wxT(""), wxPoint(8, 24), wxSize(128, 21), 0);
  edtDtHrVenda->Connect(edtDtHrVenda->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmConVendas::OnEdtDtHrVenda_Killfocus);

  btnPesquisar = new wxButton(this, ID_FRMCONVENDAS_BTNPESQUISAR,
    wxT("&Pesquisar"), wxPoint(144, 22), wxSize(75, 25), 0);

  labCPF = new wxStaticText(this, ID_FRMCONVENDAS_LABCPF,
    wxT("CPF: "), wxPoint(8, 48), wxSize(48, 13), 0);  
  edtCPF = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTCPF,
    wxT(""), wxPoint(8, 64), wxSize(128, 21), 0);
  edtCPF->Connect(edtCPF->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmConVendas::OnEdtCPF_Killfocus);

  labCliente = new wxStaticText(this, ID_FRMCONVENDAS_LABCLIENTE,
    wxT("Cliente: "), wxPoint(142, 48), wxSize(56, 13), 0);  
  edtCliente = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTCLIENTE,
    wxT(""), wxPoint(142, 64), wxSize(306, 21), 0);
  edtCliente->Enable(false);
 
  btnPCliente = new wxButton(this, ID_FRMCONVENDAS_BTNPCLIENTE,
    wxT("..."), wxPoint(448, 64), wxSize(21, 21), 0);
  
  labISBN = new wxStaticText(this, ID_FRMCONVENDAS_LABISBN,
    wxT("ISBN: "), wxPoint(8, 88), wxSize(48, 13), 0);  
  edtISBN = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTISBN,
    wxT(""), wxPoint(8, 104), wxSize(128, 21), 0);
  edtISBN->Connect(edtISBN->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmConVendas::OnEdtISBN_Killfocus);
  
  labLivro = new wxStaticText(this, ID_FRMCONVENDAS_LABLIVRO,
    wxT("Livro: "), wxPoint(142, 88), wxSize(40, 13), 0);  
  edtLivro = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTLIVRO,
    wxT(""), wxPoint(142, 104), wxSize(306, 21), 0);
  edtLivro->Enable(false);

  btnPLivro = new wxButton(this, ID_FRMCONVENDAS_BTNPLIVRO,
    wxT("..."), wxPoint(448, 104), wxSize(21, 21), 0);

  this->gridVendas = new wxGrid(this, ID_FRMCONVENDAS_GRIDVENDAS, 
    wxPoint(0, 136), wxSize(355, 122), wxSUNKEN_BORDER);
  this->gridVendas->CreateGrid(1, 6, wxGrid::wxGridSelectRows);
  this->gridVendas->HideCellEditControl();
  this->gridVendas->SetColLabelSize(21);

  this->labRegistro = new wxStaticText(this, ID_FRMCONVENDAS_LABREGISTRO,
    wxT("Registro 0 de 0"), wxPoint(8, 16), wxSize(144, 13), 0);

  labPrecoTotal = new wxStaticText(this, ID_FRMCONVENDAS_LABPRECOTOTAL,
    wxT("Preço Total: "), wxPoint(280, 248), wxSize(61, 13), 0);  
  edtPrecoTotal = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTPRECOTOTAL,
    wxT(""), wxPoint(344, 246), wxSize(127, 21), 0);
  edtPrecoTotal->Enable(false);

  this->btnLimpar = new wxButton(this, ID_FRMCONVENDAS_BTNLIMPAR,
    wxT("&Limpar"), wxPoint(16, 13), wxSize(75, 25), 0);
  this->btnFechar = new wxButton(this, ID_FRMCONVENDAS_BTNFECHAR,
    wxT("&Fechar"), wxPoint(75, 13), wxSize(75, 25), 0);

  FazLayout();

  int nLargura[] = { 120, 100, 220, 100, 280, 80 };

  wxString sRotulos[] = { "Data/Hora Venda", "CPF", "Cliente", 
   "ISBN", "Livro", "Preço" };

  Rotinas->AdicionaColunasGrid(gridVendas, 0, 6, nLargura, sRotulos);
  gridVendas->EnableEditing(false); 
  edtCPF->SetMaxLength(14);
  edtISBN->SetMaxLength(13);  
  edtPrecoTotal->SetValue("R$ 0,00");
  edtDtHrVenda->SetValue(Rotinas->retDataHoraStr(true,true));
  edtDtHrVenda->SetFocus();
}

void CfrmConVendas::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_6 = new wxBoxSizer(wxVERTICAL);
  wxGridSizer* sizer_22 = new wxGridSizer(1, 2, 0, 0);
  wxBoxSizer* sizer_23 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_7 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_24 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_8 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_6 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_5 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_4 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_3 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_2 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_1 = new wxGridSizer(2, 1, 0, 0);
  grid_sizer_1->Add(labDtHrVenda, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_1->Add(edtDtHrVenda, 0, 0, 0);
  sizer_2->Add(grid_sizer_1, 0, wxLEFT, 2);
  sizer_2->Add(btnPesquisar, 0, wxLEFT|wxTOP|wxALIGN_BOTTOM, 10);
  sizer_1->Add(sizer_2, 0, 0, 0);
  grid_sizer_2->Add(labCPF, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_2->Add(edtCPF, 0, 0, 0);
  sizer_3->Add(grid_sizer_2, 0, wxLEFT, 2);
  grid_sizer_3->Add(labCliente, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_3->Add(edtCliente, 0, 0, 0);
  sizer_3->Add(grid_sizer_3, 0, wxLEFT, 2);
  grid_sizer_4->Add(20, 20, 0, 0, 0);
  grid_sizer_4->Add(btnPCliente, 0, 0, 0);
  sizer_3->Add(grid_sizer_4, 0, 0, 0);
  sizer_1->Add(sizer_3, 0, 0, 0);
  grid_sizer_5->Add(labISBN, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_5->Add(edtISBN, 0, 0, 0);
  sizer_4->Add(grid_sizer_5, 0, wxLEFT, 2);
  grid_sizer_6->Add(labLivro, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_6->Add(edtLivro, 0, 0, 0);
  sizer_4->Add(grid_sizer_6, 0, wxLEFT, 2);
  grid_sizer_8->Add(20, 20, 0, 0, 0);
  grid_sizer_8->Add(btnPLivro, 0, 0, 0);
  sizer_4->Add(grid_sizer_8, 0, 0, 0);
  sizer_1->Add(sizer_4, 0, 0, 0);
  sizer_1->Add(gridVendas, 1, wxALL|wxEXPAND, 2);
  sizer_24->Add(labRegistro, 0, wxALL, 4);
  sizer_24->Add(20, 20, 0, 0, 0);
  sizer_22->Add(sizer_24, 0, 0, 0);
  sizer_7->Add(labPrecoTotal, 0, wxALL, 2);
  sizer_7->Add(edtPrecoTotal, 0, wxALL, 2);
  sizer_23->Add(sizer_7, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_8->Add(btnLimpar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_8->Add(btnFechar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
  sizer_23->Add(sizer_8, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_22->Add(sizer_23, 1, wxALIGN_RIGHT|wxALIGN_BOTTOM, 0);
  sizer_6->Add(sizer_22, 0, wxEXPAND, 0);
  sizer_1->Add(sizer_6, 0, wxEXPAND, 0);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
}

void CfrmConVendas::OnBtnLimpar(wxCommandEvent& event) {
  edtCPF->Clear();
  edtCliente->Clear();
  edtISBN->Clear();
  edtLivro->Clear();
  gridVendas->ClearGrid();
  gridVendas->DeleteRows(0, gridVendas->GetNumberRows()-1,true);
  edtPrecoTotal->SetValue("R$ 0,00");
  edtDtHrVenda->SetValue(Rotinas->retDataHoraStr(true,true));
  edtDtHrVenda->SetFocus();
  event.Skip();
}

wxString CfrmConVendas::ConsVenda(wxChar sOpcao)
{
  wxString sISBN, sCPF, sDataHora;
  wxString sret = "";

  if (edtDtHrVenda->GetValue().Len() > 0)
    sDataHora = Rotinas->ConverteDataHoraStr(edtDtHrVenda->GetValue(), 
      true, "%m/%d/%Y","%H:%M:%S");
  else
    sDataHora = "";

  sISBN = edtISBN->GetValue();
  sCPF = edtCPF->GetValue();

  if (sOpcao=='L')
    sret = ConsSQL->Venda('S',wxT("ZERO"),"","","","");
  else
    sret = ConsSQL->Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");

 return sret;
}

void CfrmConVendas::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmConVendas::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmConVendas::OnBtnPesquisar(wxCommandEvent& event) {
  LISTAMSTR ConsTotal;  
  wxString sPrecoTotal;
  double nTemp;

  if (Rotinas->ConsultaDadosLista(wxBanco, &lstLinhas, ConsVenda('S'), 6)) {
    Rotinas->AdicionaLinhasGrid(gridVendas, lstLinhas, 6);

    if (Rotinas->ConsultaDadosLista(wxBanco, &ConsTotal, ConsVenda('P'), 1)) {
      if (ConsTotal.col[0].GetCount() > 0) {
        ConsTotal.col[0].Item(0).ToDouble(&nTemp);
        sPrecoTotal = wxString::Format("R$ %.2f", nTemp); 
        edtPrecoTotal->SetValue(sPrecoTotal);
      }
    }

  } else {
     wxMessageBox(wxT(STR_VENNENC), wxT("Erro"), wxOK | wxICON_ERROR);
  }
}

void CfrmConVendas::OnEdtCPF_Killfocus()
{ wxString sCliente;
  wxTextCtrl *m_EdtCPF, *m_EdtCliente;
  LISTAMSTR ConsCampo;
 
  m_EdtCPF = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCONVENDAS_EDTCPF);
  m_EdtCliente = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCONVENDAS_EDTCLIENTE);

  if (m_EdtCPF->GetValue().Len() > 0) {
    if (Rotinas->validaCPF(m_EdtCPF->GetValue())) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      m_EdtCPF->GetValue(),"","","","","","","","",""),STR_CLINENC, 2); 
      if (sCliente.Len()==0) {
        m_EdtCPF->Clear();
        m_EdtCPF->SetFocus();
      } else
         m_EdtCliente->SetValue(sCliente);
    } else {
      wxMessageBox(STR_CPFINV, wxT("Erro"), wxOK | wxICON_ERROR);
      m_EdtCPF->Clear();
      m_EdtCPF->SetFocus();
    }
  } else
     m_EdtCliente->Clear();
}

void CfrmConVendas::OnBtnPCliente(wxCommandEvent& event) {
  CfrmConClientes *fConClientes = new CfrmConClientes(this);
  fConClientes->ShowModal();
  edtCPF->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCPF_Killfocus();	
  event.Skip();
}

void CfrmConVendas::OnEdtISBN_Killfocus() 
{ wxString sLivro;
  wxTextCtrl *m_EdtISBN, *m_EdtLivro;
  unsigned long nQtdEstoque = 0;
  LISTAMSTR ConsCampo;

  m_EdtISBN = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCONVENDAS_EDTISBN);
  m_EdtLivro = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCONVENDAS_EDTLIVRO);

  if (m_EdtISBN->GetValue().Len() > 0) {
    if (Rotinas->validaISBN(m_EdtISBN->GetValue())) {      
      sLivro = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Livro('Q',
      m_EdtISBN->GetValue(),"","","","","","","","",""),STR_LIVNENC, 4);
      if (sLivro.Len()==0) {
        m_EdtISBN->Clear();
    	m_EdtISBN->SetFocus();
      } else {
         m_EdtLivro->SetValue(sLivro);
         ConsCampo.col[3].Item(0).ToULong(&nQtdEstoque, 10);
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = ConsCampo.col[2].Item(0);
         } else
           wxMessageBox(STR_LIVNEST, wxT("Erro"), wxOK | wxICON_ERROR);
      }
    } else {
      wxMessageBox(STR_ISBNINV, wxT("Erro"), wxOK | wxICON_ERROR);
      m_EdtISBN->Clear();
      m_EdtISBN->SetFocus();
    }
  } else
     m_EdtLivro->Clear();
}

void CfrmConVendas::OnBtnPLivro(wxCommandEvent& event) {
  CfrmConLivros *fConLivros = new CfrmConLivros(this);
  fConLivros->ShowModal();
  edtISBN->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtISBN_Killfocus();	
  event.Skip();
}

void CfrmConVendas::setLabRegistros(int nLinha) {
  if (nLinha >= 0) {
    labRegistro->SetLabel(wxString::Format("Registro %d de %d", nLinha+1, 
      lstLinhas.col[0].GetCount()));
  }
}

void CfrmConVendas::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConVendas::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConVendas::OnEdtDtHrVenda_Killfocus(wxFocusEvent& event)
{ wxTextCtrl *m_EdtDtHrVenda;
 
  m_EdtDtHrVenda = (wxTextCtrl*)event.GetEventObject();
  if (m_EdtDtHrVenda->GetValue().Len() > 0) {
    if (!Rotinas->validaDataHora(m_EdtDtHrVenda->GetValue(), false)) {
      wxMessageBox(wxT(STR_DTHRINV), wxT("Erro"), wxOK | wxICON_ERROR);
  		m_EdtDtHrVenda->SetFocus();
    }
  } 
}
