#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConLivros.h"

BEGIN_EVENT_TABLE(CfrmConLivros, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConLivros::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConLivros::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConLivros::OnBtnFechar)
  EVT_CLOSE(CfrmConLivros::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConLivros::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConLivros::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConLivros::CfrmConLivros(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConLivros::~CfrmConLivros() { }

void CfrmConLivros::IniciaControles() {
 this->SetTitle(STR_CONLIVRO);
 this->labDescricao->SetLabel(wxT("Livro:  "));
 this->gridConsulta->SetColLabelValue(0, wxT("ISBN"));
 this->gridConsulta->SetColSize(0, 80);
 this->gridConsulta->SetColLabelValue(1, wxT("Título"));
 this->gridConsulta->SetColSize(1, 180);

 int nLargura[] = { 80,90,80,80,100,80,100,80,80,80 };
 wxString sRotulos[] = { "Edição", "AnoPublicação", "Volume",
  "CodEditora", "Editora", "CodIdioma", "Idioma",
  "NumPáginas", "Preço", "Estoque" };
 Rotinas->AdicionaColunasGrid(gridConsulta, 2, 10, nLargura, sRotulos);

}

void CfrmConLivros::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_LIVROS);
  event.Skip();
}

void CfrmConLivros::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConLivros::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConLivros::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Livro('S',wxT(""), edtDescricao->GetValue(),
    "","","","","","","",""), STR_LIVNENC, 12);
  event.Skip();
}

void CfrmConLivros::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConLivros::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

