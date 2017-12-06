#include "stdafx.h"
#include "Cadastros.h"
#include "Resource.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadastros::frmCadastros( wx::Window* parent, int nFiltroCodigo, 
    Boolean bIniciaBotoes ): wx::Panel(parent, -1, 
    System::Drawing::Point(0, 0), System::Drawing::Size(330, 140)) {

    labCodigo = new wx::StaticText(this, (int)idt::ID_FRMCADASTROS_LABCODIGO,
      "Código:", System::Drawing::Point(8, 8), System::Drawing::Size(36, 13), 0);          
    edtCodigo = new TextValidatorCtrl(this, (int)idt::ID_FRMCADASTROS_EDTCODIGO,
      "", System::Drawing::Point(8, 24), System::Drawing::Size(121, 21), 0, 
      nFiltroCodigo);
    btnNovo = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNNOVO, 
    	"&Novo", System::Drawing::Point(144, 24), System::Drawing::Size(75, 25), 0);
    labDescricao = new wx::StaticText(this, (int)idt::ID_FRMCADASTROS_LABDESCRICAO,
      "Descrição:", System::Drawing::Point(8, 48), System::Drawing::Size(51, 13), 0);  
    edtDescricao = new wx::TextCtrl(this, (int)idt::ID_FRMCADASTROS_EDTDESCRICAO,
      "", System::Drawing::Point(8, 64), System::Drawing::Size(217, 21), 0);  
  
    if (bIniciaBotoes) {
      IniciaBotoes();
      FazLayout();
    }
    edtCodigo->MaxLength = 10;
    edtDescricao->MaxLength = 30;
    Registros = new ArrayList();
    nLinhaRegistro = 0;
  }

  // Necessário por causa da tabulação dos campos
  Void frmCadastros::IniciaBotoes() {
    btnPesquisar = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNPESQUISAR,
      "&Pesquisar", System::Drawing::Point(248, 8), System::Drawing::Size(75, 25), 0);  
    btnAnterior = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNANTERIOR,
      "&Anterior", System::Drawing::Point(248, 40), System::Drawing::Size(75, 25), 0);  
    btnProximo = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNPROXIMO,
      "Próxi&mo", System::Drawing::Point(248, 72), System::Drawing::Size(75, 25), 0);  
    btnSalvar = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNSALVAR,
      "&Salvar", System::Drawing::Point(8, 104), System::Drawing::Size(75, 25), 0);  
    btnExcluir = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNEXCLUIR,
      "&Excluir", System::Drawing::Point(88, 104), System::Drawing::Size(75, 25), 0);  
    btnLimpar = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNLIMPAR,
      "&Limpar", System::Drawing::Point(168, 104), System::Drawing::Size(75, 25), 0); 
    btnFechar = new wx::Button(this, (int)idt::ID_FRMCADASTROS_BTNFECHAR,
      "&Fechar", System::Drawing::Point(248, 104), System::Drawing::Size(75, 25), 0);  
  
    btnLimparClick();
  }
  
  Void frmCadastros::FazLayout(){
    wx::BoxSizer* sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_3 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_4 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_5 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::GridSizer* grid_sizer_2 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_1 = new wx::GridSizer(2, 2, 0, 1);
    grid_sizer_1->Add(labCodigo, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_1->Add(20, 10, 0, 0, 0);
    grid_sizer_1->Add(edtCodigo, 0, 0, 0);
    grid_sizer_1->Add(btnNovo, 0, wx::Direction::wxLEFT, 6);
    sizer_5->Add(grid_sizer_1, 0, 0, 0);
    grid_sizer_2->Add(labDescricao, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_2->Add(edtDescricao, 0, 0, 2);
    sizer_5->Add(grid_sizer_2, 0, 0, 0);
    sizer_3->Add(sizer_5, 1, 0, 0);
    sizer_4->Add(btnPesquisar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_4->Add(btnAnterior, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_4->Add(btnProximo, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_3->Add(sizer_4, 0, wx::Alignment::wxALIGN_RIGHT, 0);
    sizer_1->Add(sizer_3, 1, wx::Direction::wxALL|wx::Stretch::wxEXPAND, 4);
    sizer_2->Add(btnSalvar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_2->Add(btnExcluir, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_2->Add(btnLimpar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_2->Add(btnFechar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_1->Add(sizer_2, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 4);
    AutoLayout = true;
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
  }

	Void frmCadastros::InformaLimpaDados(Boolean bInformar){
		if (bInformar) {
      Campos = dynamic_cast<ArrayList*>(Registros->Item[nLinhaRegistro]);
		  edtCodigo->Value=Campos->Item[0]->ToString();
		  edtDescricao->Value=Campos->Item[1]->ToString();
		} else {
		  edtCodigo->Clear();
		  edtDescricao->Clear();
		  edtCodigo->Enabled = true;
		  edtCodigo->SetFocus();
		}
	}

	Void frmCadastros::HabilitaDados(Boolean bHabilita){
		edtDescricao->Enabled = bHabilita;
	}

	Void frmCadastros::btnNovoClick(){
		btnSalvar->Enabled = true;
		btnExcluir->Enabled = false;
		btnPesquisar->Enabled = false;
		btnAnterior->Enabled = false;
		btnProximo->Enabled = false;
		btnNovo->Enabled = false;

    nLinhaRegistro = 0;
		InformaLimpaDados(false);
		HabilitaDados(true);
	}

	Void frmCadastros::NovoDado(String* sTextoSql){
    if (RotinasGlobais::Rotinas->ConsultaDadosLista(Registros, sTextoSql)) {
      Campos = dynamic_cast<ArrayList*>(Registros->Item[0]);
      edtCodigo->Value = Campos->Item[0]->ToString();
      edtCodigo->Enabled = false;
      edtDescricao->SetFocus();
    }
	}

	Void frmCadastros::btnLimparClick(){
		btnSalvar->Enabled = false;
		btnExcluir->Enabled = false;
		btnPesquisar->Enabled = true;
		btnAnterior->Enabled = false;
		btnProximo->Enabled = false;
		btnNovo->Enabled = true;

    nLinhaRegistro = 0;
		InformaLimpaDados(false);
		HabilitaDados(false);
	}

	Boolean frmCadastros::ExcluirDados(Boolean bValidaDados, String* sTextoSql){
    if (bValidaDados) {      
      if ( wx::MessageDialog::MessageBox(Resource::STR_CERTEXCL, "Confirme",
       wx::Dialog::wxICON_QUESTION | wx::Dialog::wxYES_NO) == wx::Dialog::wxYES ) {
        if (RotinasGlobais::Rotinas->AtualizaDados(Arquiva, sTextoSql)) {
           btnLimparClick();
           return true;
        }      
      }
    }
    return false;
	}

	Boolean frmCadastros::PesquisarDados(String* sTextoSql, String* sMensagemErro){
		if (edtCodigo->Value->Length==0) {
		  btnAnterior->Enabled = true;
		  btnProximo->Enabled = true;
		}

		if (RotinasGlobais::Rotinas->ConsultaDadosLista(Registros,sTextoSql)) {
			 InformaLimpaDados(true);
			 HabilitaDados(true);

			 btnSalvar->Enabled = true;
			 btnExcluir->Enabled = true;
			 btnPesquisar->Enabled = false;
       return true;
		} else
		  wx::MessageDialog::MessageBox(sMensagemErro, "Erro", 
        wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);

    return false;
	}

	Boolean frmCadastros::registroAnterior(){
		if (nLinhaRegistro > 0) {
			nLinhaRegistro=nLinhaRegistro - 1;
			InformaLimpaDados(true);
      return true;
    } else
      return false;
	}

	Boolean frmCadastros::registroProximo(){
		if (nLinhaRegistro < (Registros->Count-1)) {
			nLinhaRegistro=nLinhaRegistro + 1;
			InformaLimpaDados(true);
      return true;
    } else
      return false;
	}

	Boolean frmCadastros::SalvarDados(Boolean bValidaDados, String* sTextoSql,
    String* sTextoUpdate, String* sTextoInsert, Boolean bLimparDados){
    OleDbCommand* Consulta = new OleDbCommand();
    String* sArquiva;
  
  	if (bValidaDados) {    
  	   if (RotinasGlobais::Rotinas->ConsultaDados(Consulta,sTextoSql))
         sArquiva = sTextoUpdate;
       else
    	   sArquiva = sTextoInsert;	  	     
  
       if (RotinasGlobais::Rotinas->AtualizaDados(Arquiva, sArquiva)) {
    	   if (bLimparDados)
           btnLimparClick();
         return true;
       }
  	}
    return false;
	}
}
