#include "resource.h"
#include "Cadastros.h"
#include "CadLivros.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

BEGIN_EVENT_TABLE(CfrmCadLivros, CfrmCadastros)
  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, CfrmCadLivros::OnBtnNovo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, CfrmCadLivros::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, CfrmCadLivros::OnBtnAnterior)
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, CfrmCadLivros::OnBtnProximo)
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, CfrmCadLivros::OnBtnSalvar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, CfrmCadLivros::OnBtnExcluir)
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, CfrmCadLivros::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, CfrmCadLivros::OnBtnFechar)
  EVT_CLOSE(CfrmCadLivros::OnClose)
  EVT_BUTTON(ID_FRMCADLIVROS_BTNPEDITORA, CfrmCadLivros::OnBtnPEditora)
  EVT_BUTTON(ID_FRMCADLIVROS_BTNPASSUNTO, CfrmCadLivros::OnBtnPAssunto)
  EVT_BUTTON(ID_FRMCADLIVROS_BTNADASSUNTOS, CfrmCadLivros::OnBtnAdAssuntos)
  EVT_BUTTON(ID_FRMCADLIVROS_BTNPAUTOR, CfrmCadLivros::OnBtnPAutor)
  EVT_BUTTON(ID_FRMCADLIVROS_BTNADAUTORES, CfrmCadLivros::OnBtnAdAutores)
  EVT_LISTBOX_DCLICK(ID_FRMCADLIVROS_LSTASSUNTOS, CfrmCadLivros::OnLstAssuntos_Dblclk)
  EVT_LISTBOX_DCLICK(ID_FRMCADLIVROS_LSTAUTORES, CfrmCadLivros::OnLstAutores_Dblclk)
END_EVENT_TABLE()

CfrmCadLivros::CfrmCadLivros(wxWindow *parent)
       : CfrmCadastros(parent, wxFILTER_NONE, false) {
  CfrmCadLivros::IniciaControles();
}

CfrmCadLivros::~CfrmCadLivros() { }

void CfrmCadLivros::IniciaControles() {
  labCodigo->SetLabel(wxT("ISBN: "));
  labDescricao->SetLabel(wxT("Título: "));
  edtDescricao->SetSize(wxSize(312, 21));

  edtCodigo->Connect(edtCodigo->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadLivros::OnEdtCodigo_Killfocus); 
 
  labEdicao = new wxStaticText(this, ID_FRMCADLIVROS_LABEDICAO,
    wxT("Edição: "), wxPoint(326, 48), wxSize(39, 13), 0);
  edtEdicao = new wxSpinCtrl(this, ID_FRMCADLIVROS_EDTEDICAO, 
    wxT("1"), wxPoint(324, 64), wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
  edtEdicao->Enable(false);
  
  labAnoPubli = new wxStaticText(this, ID_FRMCADLIVROS_LABANOPUBLI,
    wxT("Ano Publicação: "), wxPoint(8, 88), wxSize(81, 13), 0);  
  edtAnoPubli = new wxSpinCtrl(this, ID_FRMCADLIVROS_EDTANOPUBLI,
    wxT("1"), wxPoint(8, 104), wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
  edtAnoPubli->Enable(false);
  
  labEditora = new wxStaticText(this, ID_FRMCADLIVROS_LABEDITORA,
    wxT("Editora: "), wxPoint(104, 88), wxSize(39, 13), 0);  
  edtCodEditora = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTCODEDITORA,
    wxT(""), wxPoint(104, 104), wxSize(78, 21), 0);
  edtCodEditora->Enable(false);
  edtCodEditora->Connect(edtCodEditora->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadLivros::OnEdtCodEditora_Killfocus);
  
  edtEditora = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTEDITORA,
     wxT(""), wxPoint(184, 104), wxSize(216, 21), 0);
  edtEditora->Enable(false);
  
  btnPEditora = new wxButton(this, ID_FRMCADLIVROS_BTNPEDITORA,
    wxT("..."), wxPoint(400, 104), wxSize(21, 21), 0);
  btnPEditora->Enable(false);
  
  labVolume = new wxStaticText(this, ID_FRMCADLIVROS_LABVOLUME,
    wxT("Volume: "), wxPoint(8, 128), wxSize(41, 13), 0);  
  edtVolume = new wxSpinCtrl(this, ID_FRMCADLIVROS_EDTVOLUME, 
    wxT("1"), wxPoint(8, 144), wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
  edtVolume->Enable(false);
  
  labIdioma = new wxStaticText(this, ID_FRMCADLIVROS_LABIDIOMA,
    wxT("Idioma: "), wxPoint(104, 128), wxSize(56, 13), 0);
    
  cmbIdioma = new wxChoice(this, ID_FRMCADLIVROS_CMBIDIOMA,
    wxPoint(104, 144), wxSize(320, 21), 0);
  cmbIdioma->Enable(false);
  
  labNPaginas = new wxStaticText(this, ID_FRMCADLIVROS_LABNPAGINAS,
    wxT("Nº Páginas: "), wxPoint(8, 168), wxSize(59, 13), 0);
  
  edtNPaginas = new wxSpinCtrl(this, ID_FRMCADLIVROS_EDTNPAGINAS,
    wxT("1"), wxPoint(8, 184), wxSize(92, 21), wxSP_ARROW_KEYS, 1, 9999, 1);
  edtNPaginas->Enable(false);
  
  labAssunto = new wxStaticText(this, ID_FRMCADLIVROS_LABASSUNTO,
    wxT("Assunto: "), wxPoint(104, 168), wxSize(44, 13), 0);
  
  edtCodAssunto = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTCODASSUNTO,
    wxT(""), wxPoint(104, 184), wxSize(78, 21), 0);
  edtCodAssunto->Enable(false);
  edtCodAssunto->Connect(edtCodAssunto->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadLivros::OnEdtCodAssunto_Killfocus);
  
  edtAssunto = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTASSUNTO,
    wxT(""), wxPoint(184, 184), wxSize(192, 21), 0);
  edtAssunto->Enable(false);
  
  btnAdAssuntos = new wxButton(this, ID_FRMCADLIVROS_BTNADASSUNTOS,
    wxT("+"), wxPoint(376, 184), wxSize(21, 21), 0);
  btnAdAssuntos->Enable(false);
  
  btnPAssunto = new wxButton(this, ID_FRMCADLIVROS_BTNPASSUNTO,
    wxT("..."), wxPoint(400, 184), wxSize(21, 21), 0);
  btnPAssunto->Enable(false);
  
  lstAssuntos = new wxListBox(this, ID_FRMCADLIVROS_LSTASSUNTOS,
    wxPoint(104, 208), wxSize(320, 48), 0);
  lstAssuntos->Enable(false);
  
  labPreco = new wxStaticText(this, ID_FRMCADLIVROS_LABPRECO,
    wxT("Preço: "), wxPoint(8, 216), wxSize(40, 13), 0);
  
  edtPreco = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTPRECO,
    wxT(""), wxPoint(7, 232), wxSize(92, 21), 0);
  edtPreco->Enable(false);
  edtPreco->Connect(edtPreco->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadLivros::OnEdtPreco_Killfocus); 
  
  labQtdEstoque = new wxStaticText(this, ID_FRMCADLIVROS_LABQTDESTOQUE,
    wxT("Qtd. Estoque: "), wxPoint(6, 256), wxSize(68, 13), 0);
  
  edtQtdEstoque = new wxSpinCtrl(this, ID_FRMCADLIVROS_EDTQTDESTOQUE,
    wxT("0"), wxPoint(8, 272), wxSize(92, 21), wxSP_ARROW_KEYS, 0, 9999, 0);
  edtQtdEstoque->Enable(false);
  
  labAutor = new wxStaticText(this, ID_FRMCADLIVROS_LABAUTOR,
    wxT("Autor: "), wxPoint(104, 256), wxSize(31, 13), 0);  
  edtCodAutor = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTCODAUTOR,
    wxT(""), wxPoint(104, 272), wxSize(78, 21), 0);
  edtCodAutor->Enable(false);
  edtCodAutor->Connect(edtCodAutor->GetId(), wxEVT_KILL_FOCUS, 
    (wxObjectEventFunction) (wxEventFunction)
    &CfrmCadLivros::OnEdtCodAutor_Killfocus);
  
  edtAutor = new wxTextCtrl(this, ID_FRMCADLIVROS_EDTAUTOR,
    wxT(""), wxPoint(184, 272), wxSize(192, 21), 0);
  edtAutor->Enable(false);
  
  btnAdAutores = new wxButton(this, ID_FRMCADLIVROS_BTNADAUTORES,
    wxT("+"), wxPoint(376, 272), wxSize(21, 21), 0);
  btnAdAutores->Enable(false);
  
  btnPAutor = new wxButton(this, ID_FRMCADLIVROS_BTNPAUTOR, wxT("..."),
    wxPoint(400, 272), wxSize(21, 21), 0);
  btnPAutor->Enable(false);
  
  lstAutores = new wxListBox(this, ID_FRMCADLIVROS_LSTAUTORES,
    wxPoint(104, 296), wxSize(320, 48), 0);
  lstAutores->Enable(false);

  IniciaBotoes();
  btnPesquisar->SetSize(427, 8, 75, 25);
  btnAnterior->SetSize(427, 40, 75, 25);
  btnProximo->SetSize(427, 72, 75, 25);
  btnSalvar->SetSize(187, 352, 75, 25);
  btnExcluir->SetSize(267, 352, 75, 25);
  btnLimpar->SetSize(347, 352, 75, 25);
  btnFechar->SetSize(427, 352, 75, 25);

  FazLayout();

	edtCodigo->SetMaxLength(13);
  edtDescricao->SetMaxLength(50);
  edtCodEditora->SetMaxLength(5);
  edtPreco->SetMaxLength(7);

//  AdicionaCombo();
}

void CfrmCadLivros::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_3 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_5 = new wxBoxSizer(wxVERTICAL);
  wxBoxSizer* sizer_21 = new wxBoxSizer(wxHORIZONTAL);
  wxBoxSizer* sizer_20 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_37 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_36 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_35 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_34 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_33 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_19 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_32 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_18 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_31 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_30 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_29 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_28 = new wxGridSizer(2, 1, 0, 0);

  wxGridSizer* grid_sizer_27 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_17 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_26 = new wxGridSizer(2, 1, 0, 0);
  wxGridSizer* grid_sizer_25 = new wxGridSizer(2, 1, 0, 0);
  wxBoxSizer* sizer_6 = new wxBoxSizer(wxHORIZONTAL);
  wxGridSizer* grid_sizer_24 = new wxGridSizer(2, 1, 0, 0);
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
  grid_sizer_9->Add(labEdicao, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_9->Add(edtEdicao, 0, 0, 0);
  sizer_8->Add(grid_sizer_9, 0, wxLEFT, 2);
  sizer_5->Add(sizer_8, 1, wxEXPAND, 0);
  grid_sizer_4->Add(labAnoPubli, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_4->Add(edtAnoPubli, 0, 0, 0);
  sizer_6->Add(grid_sizer_4, 0, 0, 0);
  grid_sizer_5->Add(labEditora, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_5->Add(edtCodEditora, 0, 0, 0);
  sizer_6->Add(grid_sizer_5, 0, wxLEFT, 4);
  grid_sizer_6->Add(20, 20, 0, 0, 0);
  grid_sizer_6->Add(edtEditora, 0, 0, 0);
  sizer_6->Add(grid_sizer_6, 0, wxLEFT, 2);
  grid_sizer_24->Add(20, 20, 0, 0, 0);
  grid_sizer_24->Add(btnPEditora, 0, 0, 0);
  sizer_6->Add(grid_sizer_24, 0, 0, 0);
  sizer_5->Add(sizer_6, 0, 0, 0);
  grid_sizer_25->Add(labVolume, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_25->Add(edtVolume, 0, 0, 0);
  sizer_17->Add(grid_sizer_25, 0, wxEXPAND, 0);
  grid_sizer_26->Add(labIdioma, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_26->Add(cmbIdioma, 0, 0, 0);
  sizer_17->Add(grid_sizer_26, 0, wxLEFT|wxEXPAND, 4);
  sizer_5->Add(sizer_17, 1, 0, 0);
  grid_sizer_27->Add(labNPaginas, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_27->Add(edtNPaginas, 0, 0, 0);
  sizer_18->Add(grid_sizer_27, 0, 0, 0);
  grid_sizer_28->Add(labAssunto, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_28->Add(edtCodAssunto, 0, 0, 0);
  sizer_18->Add(grid_sizer_28, 0, wxLEFT, 4);
  grid_sizer_29->Add(20, 20, 0, 0, 0);
  grid_sizer_29->Add(edtAssunto, 0, 0, 0);
  sizer_18->Add(grid_sizer_29, 0, wxLEFT, 2);
  grid_sizer_30->Add(20, 20, 0, 0, 0);
  grid_sizer_30->Add(btnAdAssuntos, 0, 0, 0);
  sizer_18->Add(grid_sizer_30, 0, 0, 0);
  grid_sizer_31->Add(20, 20, 0, 0, 0);
  grid_sizer_31->Add(btnPAssunto, 0, 0, 0);
  sizer_18->Add(grid_sizer_31, 0, 0, 0);
  sizer_5->Add(sizer_18, 1, 0, 0);
  grid_sizer_32->Add(labPreco, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_32->Add(edtPreco, 0, 0, 0);
  sizer_19->Add(grid_sizer_32, 0, 0, 0);
  sizer_19->Add(lstAssuntos, 0, wxLEFT, 4);
  sizer_5->Add(sizer_19, 1, 0, 0);
  grid_sizer_33->Add(labQtdEstoque, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_33->Add(edtQtdEstoque, 0, 0, 0);
  sizer_20->Add(grid_sizer_33, 0, 0, 0);
  grid_sizer_34->Add(labAutor, 0, wxALIGN_BOTTOM, 0);
  grid_sizer_34->Add(edtCodAutor, 0, 0, 0);
  sizer_20->Add(grid_sizer_34, 0, 0, 0);
  grid_sizer_35->Add(20, 20, 0, 0, 0);
  grid_sizer_35->Add(edtAutor, 0, 0, 0);
  sizer_20->Add(grid_sizer_35, 0, wxLEFT, 2);
  grid_sizer_36->Add(20, 20, 0, 0, 0);
  grid_sizer_36->Add(btnAdAutores, 0, 0, 0);
  sizer_20->Add(grid_sizer_36, 0, 0, 0);
  grid_sizer_37->Add(20, 20, 0, 0, 0);
  grid_sizer_37->Add(btnPAutor, 0, 0, 0);
  sizer_20->Add(grid_sizer_37, 0, 0, 0);
  sizer_5->Add(sizer_20, 1, 0, 0);
  sizer_21->Add(92, 20, 0, 0, 0);
  sizer_21->Add(lstAutores, 0, 0, 0);
  sizer_5->Add(sizer_21, 0, 0, 0);
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
}

bool CfrmCadLivros::ValidaDados(bool bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->GetValue(), STR_ISBNNINF))
  	  return false;
  	if (bTodosDados) {
  	  if (Rotinas->ValidaCampo(edtDescricao->GetValue(), STR_TITNINF))
  		return false;
	  if (Rotinas->ValidaCampo(edtEditora->GetValue(), STR_EDTNINF))
		    return false;
    if (lstAssuntos->GetCount()==0) {
      wxMessageBox(STR_ASSNINF, wxT("Erro"), wxOK | wxICON_ERROR);
      return false;
    }
    if (lstAutores->GetCount()==0) {
      wxMessageBox(STR_AUTNINF, wxT("Erro"), wxOK | wxICON_ERROR);
      return false;
    }
	}
	return true;
}

void CfrmCadLivros::OnClose(wxCloseEvent& event) {
  this->GetParent()->Close();
  event.Skip();
}

void CfrmCadLivros::OnBtnNovo(wxCommandEvent& event) {
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);	
  event.Skip();
}

void CfrmCadLivros::OnBtnPesquisar(wxCommandEvent& event) {
  if (PesquisarDados(ConsSQL->Livro('S', edtCodigo->GetValue(),
    "","","","","","","","",""), STR_LIVNENC, 12)) {
    InformaLimpaDados(true);
    HabilitaDados(true);	
  }
  event.Skip();
}

void CfrmCadLivros::OnBtnAnterior(wxCommandEvent& event) {
  if (registroAnterior()) 
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadLivros::OnBtnProximo(wxCommandEvent& event) {
  if (registroProximo()) 
    InformaLimpaDados(true);
  event.Skip();
}

void CfrmCadLivros::OnBtnSalvar(wxCommandEvent& event) {
  wxString sCodIdioma, sSqlInsert, sSqlUpdate;
  int nPos;
  
  nPos = cmbIdioma->GetSelection();
  sCodIdioma = slIdiomas.col.Item(nPos);

  sSqlUpdate = ConsSQL->Livro('U', edtCodigo->GetValue(), 
    edtDescricao->GetValue(), wxString::Format("%d",edtEdicao->GetValue()), 
    wxString::Format("%d",edtAnoPubli->GetValue()), 
    wxString::Format("%d",edtVolume->GetValue()),
    edtCodEditora->GetValue(), sCodIdioma,
    wxString::Format("%d",edtNPaginas->GetValue()),
    Rotinas->VirgulaParaPonto(edtPreco->GetValue(),false),
    wxString::Format("%d",edtQtdEstoque->GetValue()));

  sSqlInsert = ConsSQL->Livro('I', edtCodigo->GetValue(), 
    edtDescricao->GetValue(), wxString::Format("%d",edtEdicao->GetValue()), 
    wxString::Format("%d",edtAnoPubli->GetValue()), 
    wxString::Format("%d",edtVolume->GetValue()),
    edtCodEditora->GetValue(), sCodIdioma,
    wxString::Format("%d",edtNPaginas->GetValue()),
    Rotinas->VirgulaParaPonto(edtPreco->GetValue(),false),
    wxString::Format("%d",edtQtdEstoque->GetValue()));

  if (SalvarDados(ValidaDados(true),
    ConsSQL->Livro('S', edtCodigo->GetValue(),"","","","","","","","",""),
    sSqlUpdate, sSqlInsert, false)) {
    SalvaLista('A');
    SalvaLista('B');
    btnLimparClick();
    InformaLimpaDados(false);
    HabilitaDados(false);	    
  }  
  event.Skip();
}

void CfrmCadLivros::OnBtnExcluir(wxCommandEvent& event) {
  if (ExcluirDados(ValidaDados(false),
    ConsSQL->Livro('D', edtCodigo->GetValue(),
    "","","","","","","","",""))) {
    InformaLimpaDados(false);
    HabilitaDados(false);	
  }  
  event.Skip();
}

void CfrmCadLivros::OnBtnFechar(wxCommandEvent& event) {
  this->Close(true);
  event.Skip();
}

void CfrmCadLivros::OnBtnLimpar(wxCommandEvent& event) {
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);	
  event.Skip();
}

void CfrmCadLivros::InformaLimpaDados(bool bInformar)
{ 
  if (bInformar) {
    edtEdicao->SetValue(lstRegistros.col[2].Item(nLinhaRegistro));
    edtAnoPubli->SetValue(lstRegistros.col[3].Item(nLinhaRegistro));
    edtVolume->SetValue(lstRegistros.col[4].Item(nLinhaRegistro));
    edtCodEditora->SetValue(lstRegistros.col[5].Item(nLinhaRegistro));
    edtEditora->SetValue(lstRegistros.col[6].Item(nLinhaRegistro));
    cmbIdioma->SetStringSelection(lstRegistros.col[8].Item(nLinhaRegistro));
    edtNPaginas->SetValue(lstRegistros.col[9].Item(nLinhaRegistro));
    edtPreco->SetValue(
      Rotinas->VirgulaParaPonto(lstRegistros.col[10].Item(nLinhaRegistro), true));
    edtQtdEstoque->SetValue(lstRegistros.col[11].Item(nLinhaRegistro));
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAss('S', 
      edtCodigo->GetValue(), wxT("")), lstAssuntos, &slAssuntos);      
    Rotinas->AdicionaValoresLista(ConsSQL->LivroAut('S',
      edtCodigo->GetValue(), wxT("")), lstAutores, &slAutores);
  } else {  
    edtEdicao->SetValue("1");
    edtAnoPubli->SetValue(Rotinas->retDataHoraStr(true,false).Mid(6,4));
    edtVolume->SetValue("1");
    edtCodEditora->Clear();
    edtEditora->Clear();
    cmbIdioma->SetSelection(0);    
    edtNPaginas->SetValue("1");
    edtPreco->SetValue("0,00");
    edtQtdEstoque->SetValue("1");
    edtCodAssunto->Clear();
    lstAssuntos->Clear();
    edtCodAutor->Clear();
    lstAutores->Clear();
    slAssuntos.col.Clear();
    slAutores.col.Clear();
  }
} 

void CfrmCadLivros::HabilitaDados(bool bHabilita)
{
  edtEdicao->Enable(bHabilita);
  edtAnoPubli->Enable(bHabilita);
  edtVolume->Enable(bHabilita);
  edtCodEditora->Enable(bHabilita);
  btnPEditora->Enable(bHabilita);
  cmbIdioma->Enable(bHabilita);
  edtNPaginas->Enable(bHabilita);
  edtPreco->Enable(bHabilita);
  edtQtdEstoque->Enable(bHabilita);
  edtCodAssunto->Enable(bHabilita);
  btnPAssunto->Enable(bHabilita);
  btnAdAssuntos->Enable(bHabilita);
  lstAssuntos->Enable(bHabilita);
  edtCodAutor->Enable(bHabilita);
  btnPAutor->Enable(bHabilita);
  btnAdAutores->Enable(bHabilita);
  lstAutores->Enable(bHabilita);
}

void CfrmCadLivros::OnEdtCodigo_Killfocus(wxFocusEvent& event)
{ wxTextCtrl *mCodigo;
 
  mCodigo = (wxTextCtrl*)event.GetEventObject();

  if (mCodigo->GetValue().Len() > 0) {
  	if (Rotinas->validaISBN(mCodigo->GetValue())==false) {      
      wxMessageBox(STR_ISBNINV, wxT("Erro"), wxOK | wxICON_ERROR);
      mCodigo->Clear();
  		mCodigo->SetFocus();
  	}
  }	
}

void CfrmCadLivros::AdicionaCombo() 
{ 

  LISTAMSTR Campos;
  unsigned long nLinha;

  if (Rotinas->ConsultaDadosLista(wxBanco, &Campos, 
    ConsSQL->Idioma('S',wxT(""),wxT("")), 2)) {
    for (nLinha = 0; nLinha < Campos.col[0].Count(); nLinha++) {
	    slIdiomas.col.Add(Campos.col[0].Item(nLinha));
	    cmbIdioma->Append(Campos.col[1].Item(nLinha));
	  }      
  }
}

void CfrmCadLivros::SalvaLista(wxChar sOpcao) 
{
wxString sISBN;
int nCont, nQtd;

  sISBN = edtCodigo->GetValue();
  if (sOpcao=='A') {
    Rotinas->AtualizaDados(wxBanco, ConsSQL->LivroAss('D',sISBN,wxT(""))); 

    nQtd = slAssuntos.col.Count();
    for (nCont=0; nCont < nQtd; nCont++)  {      
      Rotinas->AtualizaDados(wxBanco, ConsSQL->LivroAss('I', 
        sISBN, slAssuntos.col.Item(nCont)));
    }
  } else if (sOpcao=='B') {
  	Rotinas->AtualizaDados(wxBanco,ConsSQL->LivroAut('D',sISBN,wxT("")));

    nQtd = slAutores.col.Count();
    for (nCont=0; nCont < nQtd; nCont++)  {      
      Rotinas->AtualizaDados(wxBanco, ConsSQL->LivroAut('I', 
        sISBN, slAutores.col.Item(nCont)));
    }
  }
}

void CfrmCadLivros::OnEdtCodEditora_Killfocus() 
{ wxString sEditora;
  wxTextCtrl *m_EdtCodEditora, *m_EdtEditora;
  LISTAMSTR ConsCampo;

  m_EdtCodEditora = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADLIVROS_EDTCODEDITORA);
  m_EdtEditora = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADLIVROS_EDTEDITORA);

  if (m_EdtCodEditora->GetValue().Len() > 0) {
    sEditora = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Editora('S',
      m_EdtCodEditora->GetValue(),""),STR_EDTNENC, 2);    
    if (sEditora.Len() > 0) {
      m_EdtEditora->SetValue(sEditora);
    } else {
      m_EdtCodEditora->Clear();
      m_EdtCodEditora->SetFocus();
    }
  } else {
    m_EdtEditora->Clear();
  }
}

void CfrmCadLivros::OnBtnPEditora(wxCommandEvent& event) {
  CfrmConEditoras *fConEditoras = new CfrmConEditoras(this);
  fConEditoras->ShowModal();
  edtCodEditora->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodEditora_Killfocus();
  event.Skip();
}

void CfrmCadLivros::OnEdtPreco_Killfocus(wxFocusEvent& event) 
{ wxTextCtrl *mPreco;
 
  mPreco = (wxTextCtrl*)event.GetEventObject();
  if (Rotinas->ValidaFloat(
        Rotinas->VirgulaParaPonto(mPreco->GetValue(), false)))
    mPreco->SetValue(Rotinas->VirgulaParaPonto(mPreco->GetValue(), true));
  else {
    mPreco->SetValue(wxT("0,01"));
    mPreco->SetFocus();
  }
}

void CfrmCadLivros::OnEdtCodAssunto_Killfocus() 
{ wxString sAssunto;
  wxTextCtrl *m_EdtCodAssunto, *m_EdtAssunto;
  LISTAMSTR ConsCampo;

  m_EdtCodAssunto = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADLIVROS_EDTCODASSUNTO);
  m_EdtAssunto = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADLIVROS_EDTASSUNTO);

  if (m_EdtCodAssunto->GetValue().Len() > 0) {
    sAssunto = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Assunto('S',
      m_EdtCodAssunto->GetValue(),""),STR_ASSNENC, 2);    
    if (sAssunto.Len() > 0) {
      m_EdtAssunto->SetValue(sAssunto);
    } else {
      m_EdtCodAssunto->Clear();
      m_EdtCodAssunto->SetFocus();
    }
  } else {
    m_EdtAssunto->Clear();
  }
}

void CfrmCadLivros::OnBtnPAssunto(wxCommandEvent& event) {
  CfrmConAssuntos *fConAssuntos = new CfrmConAssuntos(this);
  fConAssuntos->ShowModal();
  edtCodAssunto->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodAssunto_Killfocus();
  event.Skip();
}

void CfrmCadLivros::OnEdtCodAutor_Killfocus() 
{ wxString sAutor;
  wxTextCtrl *m_EdtCodAutor, *m_EdtAutor;
  LISTAMSTR ConsCampo;

  m_EdtCodAutor = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADLIVROS_EDTCODAUTOR);
  m_EdtAutor = (wxTextCtrl*)
    wxWindow::FindWindowById(ID_FRMCADLIVROS_EDTAUTOR);

  if (m_EdtCodAutor->GetValue().Len() > 0) {
    sAutor = Rotinas->ConsultaCampoDesc(&ConsCampo, ConsSQL->Autor('S',
      m_EdtCodAutor->GetValue(),""),STR_AUTNENC, 2);    
    if (sAutor.Len() > 0) {
      m_EdtAutor->SetValue(sAutor);
    } else {
      m_EdtCodAutor->Clear();
      m_EdtCodAutor->SetFocus();
    }
  } else {
    m_EdtAutor->Clear();
  }
}

void CfrmCadLivros::OnBtnPAutor(wxCommandEvent& event) {
  CfrmConAutores *fConAutores = new CfrmConAutores(this);
  fConAutores->ShowModal();
  edtCodAutor->SetValue(Rotinas_sCodigoSelecionado);
  OnEdtCodAutor_Killfocus();
  event.Skip();
}

void CfrmCadLivros::OnBtnAdAssuntos(wxCommandEvent& event) 
{
  Rotinas->AdicionaItemLista(lstAssuntos, 
    &slAssuntos, edtCodAssunto, edtAssunto);
}

void CfrmCadLivros::OnLstAssuntos_Dblclk(wxCommandEvent& event) 
{
  Rotinas->RemoveItemLista(lstAssuntos,&slAssuntos);
}

void CfrmCadLivros::OnBtnAdAutores(wxCommandEvent& event) 
{
  Rotinas->AdicionaItemLista(lstAutores, 
    &slAutores, edtCodAutor, edtAutor);	
}

void CfrmCadLivros::OnLstAutores_Dblclk(wxCommandEvent& event) 
{
  Rotinas->RemoveItemLista(lstAutores,&slAutores);
}
