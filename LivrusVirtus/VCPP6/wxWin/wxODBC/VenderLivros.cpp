#include "resource.h"
#include "Cadastros.h"
#include "VenderLivros.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

BEGIN_EVENT_TABLE(CfrmVenderLivros, CfrmCadastros)
  EVT_BUTTON(ID_FRMVENDERLIVROS_BTNVENDER, CfrmVenderLivros::OnBtnVender)
  EVT_BUTTON(ID_FRMVENDERLIVROS_BTNLIMPAR, CfrmVenderLivros::OnBtnLimpar)
  EVT_BUTTON(ID_FRMVENDERLIVROS_BTNFECHAR, CfrmVenderLivros::OnBtnFechar)
  EVT_CLOSE(CfrmVenderLivros::OnClose)
  EVT_BUTTON(ID_FRMVENDERLIVROS_BTNPCLIENTE, CfrmVenderLivros::OnBtnPCliente)
  EVT_BUTTON(ID_FRMVENDERLIVROS_BTNPLIVRO, CfrmVenderLivros::OnBtnPLivro)
  EVT_BUTTON(ID_FRMVENDERLIVROS_BTNADLIVROS, CfrmVenderLivros::OnBtnAdLivros) 
  EVT_LISTBOX_DCLICK(ID_FRMVENDERLIVROS_LSTLIVROS, CfrmVenderLivros::OnLstLivros_Dblclk)
END_EVENT_TABLE()

CfrmVenderLivros::CfrmVenderLivros(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NONE, false) {
  CfrmVenderLivros::IniciaControles();
}

CfrmVenderLivros::~CfrmVenderLivros() { }

void CfrmVenderLivros::IniciaControles() {
  btnNovo->Hide();

  labDtHrVenda = new wxStaticText(this, ID_FRMVENDERLIVROS_LABDTHRVENDA,
    wxT("Data/Hora Venda: "), wxPoint(8, 8), wxSize(91, 13), 0);  
  edtDtHrVenda = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTDTHRVENDA,
    wxT(""), wxPoint(8, 24), wxSize(128, 21), 0);
  edtDtHrVenda->Enable(false);

  labCodigo->SetLabel(wxT("CPF: "));  
  labCodigo->SetSize(8, 48, 48, 13); 
  edtCodigo->SetSize(8, 64, 128, 21);
  edtCodigo->Connect(edtCodigo->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmVenderLivros::OnEdtCodigo_Killfocus);

  labDescricao->SetLabel(wxT("Cliente: "));  
  labDescricao->SetSize(142, 48, 56, 13);  
  edtDescricao->SetSize(142, 64, 306, 21);
  edtDescricao->Enable(false);
 
  btnPCliente = new wxButton(this, ID_FRMVENDERLIVROS_BTNPCLIENTE,
    wxT("..."), wxPoint(448, 64), wxSize(21, 21), 0);
  
  labISBN = new wxStaticText(this, ID_FRMVENDERLIVROS_LABISBN,
    wxT("ISBN: "), wxPoint(8, 88), wxSize(48, 13), 0);  
  edtISBN = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTISBN,
    wxT(""), wxPoint(8, 104), wxSize(128, 21), 0);
  edtISBN->Connect(edtISBN->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmVenderLivros::OnEdtISBN_Killfocus);
  
  labLivro = new wxStaticText(this, ID_FRMVENDERLIVROS_LABLIVRO,
    wxT("Livro: "), wxPoint(142, 88), wxSize(40, 13), 0);  
  edtLivro = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTLIVRO,
    wxT(""), wxPoint(142, 104), wxSize(282, 21), 0);
  edtLivro->Enable(false);

  btnAdLivros = new wxButton(this, ID_FRMVENDERLIVROS_BTNADLIVROS,
  wxT("+"), wxPoint(424, 104), wxSize(21, 21), 0);
  
  btnPLivro = new wxButton(this, ID_FRMVENDERLIVROS_BTNPLIVRO,
    wxT("..."), wxPoint(448, 104), wxSize(21, 21), 0);
  
  labLivros = new wxStaticText(this, ID_FRMVENDERLIVROS_LABLIVROS,
    wxT("Livros para vender: "), wxPoint(8, 128), wxSize(120, 13), 0);
  
  lstLivros = new wxListBox(this, ID_FRMVENDERLIVROS_LSTLIVROS,
    wxPoint(8, 144), wxSize(464, 96), 0);
  
  labPrecoTotal = new wxStaticText(this, ID_FRMVENDERLIVROS_LABPRECOTOTAL,
    wxT("Preço Total: "), wxPoint(280, 248), wxSize(61, 13), 0);  
  edtPrecoTotal = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTPRECOTOTAL,
    wxT(""), wxPoint(344, 246), wxSize(127, 21), 0);
  edtPrecoTotal->Enable(false);
  
  btnVender = new wxButton(this, ID_FRMVENDERLIVROS_BTNVENDER,
    wxT("&Vender"), wxPoint(239, 275), wxSize(75, 25), 0);  
  btnLimpar = new wxButton(this, ID_FRMVENDERLIVROS_BTNLIMPAR,
    wxT("&Limpar"), wxPoint(319, 275), wxSize(75, 25), 0);  
  btnFechar = new wxButton(this, ID_FRMVENDERLIVROS_BTNFECHAR,
    wxT("&Fechar"), wxPoint(399, 275), wxSize(75, 25), 0);

  FazLayout();

  edtDtHrVenda->SetValue(Rotinas->retDataHoraStr(true, true));   
  edtCodigo->SetMaxLength(14);
  edtISBN->SetMaxLength(13);  
  nPrecoTotal = 0;
}

void CfrmVenderLivros::FazLayout()
{
    wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_6 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_7 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer* grid_sizer_8 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer* grid_sizer_7 = new wxGridSizer(2, 1, 0, 0);
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
    sizer_2->Add(20, 20, 0, 0, 0);
    sizer_1->Add(sizer_2, 0, 0, 0);
    grid_sizer_2->Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_2->Add(edtCodigo, 0, 0, 0);
    sizer_3->Add(grid_sizer_2, 0, wxLEFT, 2);
    grid_sizer_3->Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_3->Add(edtDescricao, 0, 0, 0);
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
    grid_sizer_7->Add(20, 20, 0, 0, 0);
    grid_sizer_7->Add(btnAdLivros, 0, 0, 0);
    sizer_4->Add(grid_sizer_7, 1, wxEXPAND, 0);
    grid_sizer_8->Add(20, 20, 0, 0, 0);
    grid_sizer_8->Add(btnPLivro, 0, 0, 0);
    sizer_4->Add(grid_sizer_8, 0, 0, 0);
    sizer_1->Add(sizer_4, 0, 0, 0);
    sizer_5->Add(labLivros, 0, wxALIGN_BOTTOM, 0);
    sizer_5->Add(lstLivros, 1, wxALL|wxEXPAND, 1);
    sizer_1->Add(sizer_5, 1, wxEXPAND, 0);
    sizer_7->Add(labPrecoTotal, 0, wxALL, 2);
    sizer_7->Add(edtPrecoTotal, 0, wxALL, 2);
    sizer_6->Add(sizer_7, 0, wxALL|wxALIGN_RIGHT, 2);
    sizer_8->Add(btnVender, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
    sizer_8->Add(btnLimpar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
    sizer_8->Add(btnFechar, 0, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2);
    sizer_6->Add(sizer_8, 0, wxALL, 2);
    sizer_1->Add(sizer_6, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 0);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
}

void CfrmVenderLivros::LimpaDados() {
  edtDtHrVenda->SetValue(Rotinas->retDataHoraStr(true, true));  
  edtCodigo->Clear();
  edtDescricao->Clear();
  edtISBN->Clear();
  edtLivro->Clear();
  lstLivros->Clear();
  nPrecoTotal = 0;
  edtPrecoTotal->SetValue("R$ 0,00");
  edtCodigo->SetFocus();
}

bool CfrmVenderLivros::ValidaDados()
{
  if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_CPFNINF))
    return false;
  if (lstLivros->GetCount()==0) {
    wxMessageBox(STR_LIVVENNINF, wxT("Erro"), wxOK | wxICON_ERROR);
    return false;
  }
return true;
}

bool CfrmVenderLivros::SalvaLista()
{ wxString sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR;
  int nCont, nQtd;
  unsigned long nQtdEstoque = 0;

  nQtd = lstLivros->GetCount();
  sCPF = edtCodigo->GetValue();
  sPrecoTotal = wxString::Format("%.2f",nPrecoTotal);
  
  sDTHR = edtDtHrVenda->GetValue();
  sDataHora = Rotinas->ConverteDataHoraStr(sDTHR, true, 
    "%m/%d/%Y","%H:%M:%S");
  
  for (nCont=0; nCont < nQtd; nCont++) {
    sISBN = slISBNs.col.Item(nCont);
  
    Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('I',sISBN, sCPF, 
      sDataHora,Rotinas->VirgulaParaPonto(sPrecoTotal,false),""));
  
    slQtdEstoque.col.Item(nCont).ToULong(&nQtdEstoque,10);
    if (nQtdEstoque >= 0) nQtdEstoque--;
    sQtdEstoque = wxString::Format("%d", (int) nQtdEstoque);
    Rotinas->AtualizaDados(gConexao, ConsSQL->Venda('U',sISBN, 
      "","","", sQtdEstoque));
  }
return true;
}

void CfrmVenderLivros::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmVenderLivros::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmVenderLivros::OnEdtCodigo_Killfocus()
{ wxString sCliente;
  wxTextCtrl *m_EdtCodigo, *m_EdtCliente;
  LISTAMSTR ConsCampo;
 
  m_EdtCodigo = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADASTROS_EDTCODIGO);
  m_EdtCliente = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADASTROS_EDTDESCRICAO);

  if (m_EdtCodigo->GetValue().Len() > 0) {
    if (Rotinas->validaCPF(m_EdtCodigo->GetValue())) {      
      sCliente = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Cliente('S',
      m_EdtCodigo->GetValue(),"","","","","","","","",""),STR_CLINENC, 2); 
      if (sCliente.Len()==0) {
        m_EdtCodigo->Clear();
        m_EdtCodigo->SetFocus();
      } else
         m_EdtCliente->SetValue(sCliente);
    } else {
      wxMessageBox(STR_CPFINV, wxT("Erro"), wxOK | wxICON_ERROR);
      m_EdtCodigo->Clear();
      m_EdtCodigo->SetFocus();
    }
  } else
     m_EdtCliente->Clear();
}

void CfrmVenderLivros::OnBtnPCliente(wxCommandEvent& event) {
  CfrmConClientes *fConClientes = new CfrmConClientes(this);
  fConClientes->ShowModal();
  edtCodigo->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodigo_Killfocus();	
  event.Skip();
}

void CfrmVenderLivros::OnEdtISBN_Killfocus() 
{ wxString sLivro;
  wxTextCtrl *m_EdtISBN, *m_EdtLivro;
  unsigned long nQtdEstoque = 0;
  LISTAMSTR ConsCampo;

  m_EdtISBN = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMVENDERLIVROS_EDTISBN);
  m_EdtLivro = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMVENDERLIVROS_EDTLIVRO);

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
           Rotinas_sQtdEstoque = ConsCampo.col[3].Item(0);
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

void CfrmVenderLivros::OnBtnPLivro(wxCommandEvent& event) {
  CfrmConLivros *fConLivros = new CfrmConLivros(this);
  fConLivros->ShowModal();
  edtISBN->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtISBN_Killfocus();	
  event.Skip();
}

void CfrmVenderLivros::OnBtnAdLivros(wxCommandEvent& event) 
{ double nPreco; 
  wxString sLivros, sISBN, sEdtLivro, sPrecoTotal;

 sISBN = edtISBN->GetValue();
 sEdtLivro = edtLivro->GetValue();
 if (sISBN.Len() > 0) {
   sLivros = wxString::Format("%s - %s - R$ %s", 
     sISBN.c_str(), sEdtLivro.c_str(), Rotinas_sPreco.c_str());
   if (lstLivros->FindString(sLivros)==-1) {
     slISBNs.col.Add(sISBN);
     slPrecos.col.Add(Rotinas_sPreco);
     slQtdEstoque.col.Add(Rotinas_sQtdEstoque);
     lstLivros->Append(sLivros);
     Rotinas_sPreco.ToDouble(&nPreco);
     nPrecoTotal = nPrecoTotal + nPreco;
   }
   edtISBN->Clear();
   edtLivro->Clear();
   sPrecoTotal = wxString::Format("R$ %.2f", nPrecoTotal);
   edtPrecoTotal->SetValue(Rotinas->VirgulaParaPonto(sPrecoTotal,true));
 }
 event.Skip();
}

void CfrmVenderLivros::OnLstLivros_Dblclk(wxCommandEvent& event)
{ wxString sPrecoTotal;
  double nPreco;
  int nSelIndice;

  if (lstLivros->GetCount() > 0) {   
    nSelIndice = lstLivros->GetSelection();   
    if (lstLivros->Selected(nSelIndice)) {
      slPrecos.col.Item(nSelIndice).ToDouble(&nPreco);
      nPrecoTotal = nPrecoTotal-nPreco;     
      sPrecoTotal = wxString::Format("R$ %.2f",nPrecoTotal);
      edtPrecoTotal->SetValue(Rotinas->VirgulaParaPonto(sPrecoTotal,true));
      slISBNs.col.Remove(nSelIndice);
      slPrecos.col.Remove(nSelIndice);
      slQtdEstoque.col.Remove(nSelIndice);
      lstLivros->Delete(nSelIndice);
    }	
  }
  event.Skip();
}

void CfrmVenderLivros::OnBtnVender(wxCommandEvent& event) {
  if (ValidaDados()) {
    if (SalvaLista()) {
      wxMessageBox(STR_VENRESUC, GetTitle(), wxOK | wxICON_INFORMATION);
      LimpaDados();
    }
  }	
  event.Skip();
}

void CfrmVenderLivros::OnBtnLimpar(wxCommandEvent& event) {
  LimpaDados();
  event.Skip();
}
