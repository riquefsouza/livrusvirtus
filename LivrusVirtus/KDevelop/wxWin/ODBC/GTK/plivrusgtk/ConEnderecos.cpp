#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"

BEGIN_EVENT_TABLE(CfrmConEnderecos, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConEnderecos::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConEnderecos::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConEnderecos::OnBtnFechar)
  EVT_CLOSE(CfrmConEnderecos::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConEnderecos::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConEnderecos::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConEnderecos::CfrmConEnderecos(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConEnderecos::~CfrmConEnderecos() { }

void CfrmConEnderecos::IniciaControles() {
 this->SetTitle(STR_CONENDERECO);
 this->labDescricao->SetLabel(wxT("Endereço:  "));
 this->gridConsulta->SetColLabelValue(1, wxT("Logradouro"));
 this->gridConsulta->SetColSize(1, 200);

 int nLargura[] = { 150,80,100,80 };
 wxString sRotulos[] = { "Bairro", "CEP", "Cidade", "Estado" };
 Rotinas->AdicionaColunasGrid(gridConsulta, 2, 4, nLargura, sRotulos);
}

void CfrmConEnderecos::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_ENDERECOS);
  event.Skip();
}

void CfrmConEnderecos::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConEnderecos::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConEnderecos::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Endereco('S',wxT(""), edtDescricao->GetValue(),
    "","","",""), STR_ENDNENC, 6);
  event.Skip();
}

void CfrmConEnderecos::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConEnderecos::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

