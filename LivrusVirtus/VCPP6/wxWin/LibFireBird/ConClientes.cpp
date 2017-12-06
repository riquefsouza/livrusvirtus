#include "resource.h"
#include "Consultas.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConClientes.h"

BEGIN_EVENT_TABLE(CfrmConClientes, CfrmConsultas)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR, CfrmConClientes::OnBtnPesquisar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR, CfrmConClientes::OnBtnLimpar)
  EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR, CfrmConClientes::OnBtnFechar)
  EVT_CLOSE(CfrmConClientes::OnClose)
  EVT_GRID_SELECT_CELL(CfrmConClientes::OnGridSelectCell)
  EVT_GRID_LABEL_LEFT_CLICK(CfrmConClientes::OnGridLabelLeftClick)
END_EVENT_TABLE()

CfrmConClientes::CfrmConClientes(wxWindow *parent)
       : CfrmConsultas(parent) {
	IniciaControles();
}

CfrmConClientes::~CfrmConClientes() { }

void CfrmConClientes::IniciaControles() {
 this->SetTitle(STR_CONCLIENTE);
 this->labDescricao->SetLabel(wxT("Cliente:  "));
 this->gridConsulta->SetColLabelValue(0, wxT("CPF"));
 this->gridConsulta->SetColSize(0, 90);
 this->gridConsulta->SetColLabelValue(1, wxT("Nome"));
 this->gridConsulta->SetColSize(1, 220);

 int nLargura[] = { 180,80,40,80,120,80,220,150,
          80,100,100,80,180,80,100 };

 wxString sRotulos[] = { "Email", "Identidade", "Sexo", 
   "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
   "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
   "CodProfissão", "Profissão" };

 Rotinas->AdicionaColunasGrid(gridConsulta, 2, 15, nLargura, sRotulos);

}

void CfrmConClientes::OnClose(wxCloseEvent& event) {
  Fecha(MNU_CON_CLIENTES);
  event.Skip();
}

void CfrmConClientes::OnBtnFechar(wxCommandEvent& event) {  
  Fecha(0);
  event.Skip();
}

void CfrmConClientes::OnBtnLimpar(wxCommandEvent& event) {
  LimparDados();
  event.Skip();
}

void CfrmConClientes::OnBtnPesquisar(wxCommandEvent& event) {
  PesquisarDados(
    ConsSQL->Cliente('S',wxT(""), edtDescricao->GetValue(),
    "","","","","","","",""), STR_CLINENC, 17);
  event.Skip();
}

void CfrmConClientes::OnGridSelectCell(wxGridEvent& event) {
  setLabRegistros(event.GetRow());
  event.Skip();
}

void CfrmConClientes::OnGridLabelLeftClick(wxGridEvent& event){
  setLabRegistros(event.GetRow());
  event.Skip();
}

