#include "stdafx.h"
#include "CadEnderecos.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

namespace Livrus
{
  frmCadEnderecos::frmCadEnderecos( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NUMERIC, false){

    ClientSize = System::Drawing::Size(523, 171);
    labDescricao->Label = "Logradouro:";
    labDescricao->Size = System::Drawing::Size(57, 13);
    edtDescricao->Size = System::Drawing::Size(264, 21);
  
  	labBairro = new wx::StaticText(this, (int)idx::ID_FRMCADENDERECOS_LABBAIRRO, 
      "Bairro:", System::Drawing::Point(280, 48), System::Drawing::Size(48, 13) );
  	edtBairro = new wx::TextCtrl(this, (int)idx::ID_FRMCADENDERECOS_EDTBAIRRO,
      "", System::Drawing::Point(280, 64), System::Drawing::Size(144, 21) );
    edtBairro->Enabled = false;
  	labCEP = new wx::StaticText(this, (int)idx::ID_FRMCADENDERECOS_LABCEP, 
      "CEP: ", System::Drawing::Point(8, 88), System::Drawing::Size(40, 13) );
  	edtCEP = new wx::TextCtrl(this, (int)idx::ID_FRMCADENDERECOS_EDTCEP, 
      "", System::Drawing::Point(8, 104), System::Drawing::Size(72, 21) );
    edtCEP->Enabled = false;
  	labCidade = new wx::StaticText(this, (int)idx::ID_FRMCADENDERECOS_LABCIDADE, 
      "Cidade: ", System::Drawing::Point(88, 88), System::Drawing::Size(39, 13) );
  	edtCidade = new wx::TextCtrl(this, (int)idx::ID_FRMCADENDERECOS_EDTCIDADE, 
      "", System::Drawing::Point(88, 104), System::Drawing::Size(184, 21) );
    edtCidade->Enabled = false;
  	labEstado = new wx::StaticText(this, (int)idx::ID_FRMCADENDERECOS_LABESTADO, 
      "Estado: ", System::Drawing::Point(280, 88), System::Drawing::Size(56, 13) );
    AdicionaCombo();
  	cmbEstado = new wx::Choice(this, (int)idx::ID_FRMCADENDERECOS_CMBESTADO, 
      System::Drawing::Point(280, 104), System::Drawing::Size(144, 21), vsEstados );
    cmbEstado->Enabled = false;

    IniciaBotoes();
  
    btnPesquisar->SetSize(440, 8, 75, 25);
    btnAnterior->SetSize(440, 40, 75, 25);
    btnProximo->SetSize(440, 72, 75, 25);
    btnSalvar->SetSize(200, 136, 75, 25);
    btnExcluir->SetSize(280, 136, 75, 25);
    btnLimpar->SetSize(360, 136, 75, 25);
    btnFechar->SetSize(440, 136, 75, 25);
  
    //FazLayout();
  
    edtDescricao->MaxLength = 40;
    edtBairro->MaxLength = 15;
    edtCEP->MaxLength = 8;
    edtCidade->MaxLength = 30;

    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNNOVO, 
      new wx::EventListener( this, OnBtnNovo ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNPESQUISAR, 
      new wx::EventListener( this, OnBtnPesquisar ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNANTERIOR, 
      new wx::EventListener( this, OnBtnAnterior ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNPROXIMO, 
      new wx::EventListener( this, OnBtnProximo ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNSALVAR, 
      new wx::EventListener( this, OnBtnSalvar ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNEXCLUIR, 
      new wx::EventListener( this, OnBtnExcluir ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNLIMPAR, 
      new wx::EventListener( this, OnBtnLimpar ));
    EVT_BUTTON((int)idt::ID_FRMCADASTROS_BTNFECHAR, 
      new wx::EventListener( this, OnBtnFechar ));
  	EVT_CLOSE( new wx::EventListener( this, OnClose ) );
  }

  Void frmCadEnderecos::FazLayout(){
    wx::BoxSizer* sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_3 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_4 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_5 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_6 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_6 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_5 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_4 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_8 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_9 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_8 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_7 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_7 = new wx::GridSizer(2, 1, 0, 0);
    grid_sizer_7->Add(labCodigo, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_7->Add(edtCodigo, 0, 0, 0);
    sizer_7->Add(grid_sizer_7, 0, 0, 0);
    sizer_7->Add(btnNovo, 0, wx::Direction::wxLEFT|wx::Alignment::wxALIGN_BOTTOM, 5);
    sizer_5->Add(sizer_7, 1, 0, 0);
    grid_sizer_8->Add(labDescricao, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_8->Add(edtDescricao, 0, 0, 0);
    sizer_8->Add(grid_sizer_8, 0, 0, 0);
    grid_sizer_9->Add(labBairro, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_9->Add(edtBairro, 0, 0, 0);
    sizer_8->Add(grid_sizer_9, 0, wx::Direction::wxLEFT, 2);
    sizer_5->Add(sizer_8, 1, wx::Stretch::wxEXPAND, 0);
    grid_sizer_4->Add(labCEP, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_4->Add(edtCEP, 0, 0, 0);
    sizer_6->Add(grid_sizer_4, 0, 0, 0);
    grid_sizer_5->Add(labCidade, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_5->Add(edtCidade, 0, 0, 0);
    sizer_6->Add(grid_sizer_5, 0, wx::Direction::wxLEFT, 4);
    grid_sizer_6->Add(labEstado, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_6->Add(cmbEstado, 0, 0, 0);
    sizer_6->Add(grid_sizer_6, 0, wx::Direction::wxLEFT, 5);
    sizer_5->Add(sizer_6, 0, 0, 0);
    sizer_3->Add(sizer_5, 0, 0, 0);
    sizer_4->Add(btnPesquisar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_4->Add(btnAnterior, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_4->Add(btnProximo, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_3->Add(sizer_4, 1, 0, 0);
    sizer_1->Add(sizer_3, 1, wx::Direction::wxALL|wx::Stretch::wxEXPAND, 4);
    sizer_2->Add(btnSalvar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_2->Add(btnExcluir, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_2->Add(btnLimpar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_2->Add(btnFechar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_1->Add(sizer_2, 0, wx::Direction::wxRIGHT|wx::Direction::wxBOTTOM|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 4);
    AutoLayout = true;
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
  }

	Boolean frmCadEnderecos::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_ENDNINF))
      	return false;
      if (RotinasGlobais::Rotinas->ValidaCampo(edtBairro->Value, 
        Resource::STR_BAIRRONINF))
      	return false;
      if (RotinasGlobais::Rotinas->ValidaCampo(edtCEP->Value, 
        Resource::STR_CEPNINF))
      	return false;
      if (RotinasGlobais::Rotinas->ValidaCampo(edtCidade->Value, 
        Resource::STR_CIDADENINF))
      	return false;
    }
		return true;
	}

  Void frmCadEnderecos::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    InformaLimpaDados(false);
    HabilitaDados(true);
    NovoDado(ConsultasSQL::ConsSQL->Endereco('N', edtCodigo->Value,
      "","","","",""));	
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    if (PesquisarDados(ConsultasSQL::ConsSQL->Endereco('S', edtCodigo->Value,
      "","","","",""), Resource::STR_ENDNENC)) {
      InformaLimpaDados(true);
      HabilitaDados(true);
    }
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    if (registroAnterior())
      InformaLimpaDados(true);
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnProximo( System::Object* sender, wx::Event* e ){
    if (registroProximo())
      InformaLimpaDados(true);
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    if (SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Endereco('S', edtCodigo->Value,
        "","","","",""),
      ConsultasSQL::ConsSQL->Endereco('U', edtCodigo->Value, 
        edtDescricao->Value,edtBairro->Value,edtCEP->Value,
        edtCidade->Value,cmbEstado->StringSelection),
      ConsultasSQL::ConsSQL->Endereco('I', edtCodigo->Value, 
        edtDescricao->Value,edtBairro->Value,edtCEP->Value,
        edtCidade->Value,cmbEstado->StringSelection), true)) {
      InformaLimpaDados(false);
      HabilitaDados(false);
    }
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    if (ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Endereco('D', edtCodigo->Value,
      "","","","",""))) {
      InformaLimpaDados(false);
      HabilitaDados(false);
    }
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadEnderecos::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    InformaLimpaDados(false);
    HabilitaDados(false);
    e->Skip();
  }

  Void frmCadEnderecos::InformaLimpaDados(Boolean bInformar){
    if (bInformar) {
      edtBairro->Value = Campos->Item[2]->ToString();
      edtCEP->Value = Campos->Item[3]->ToString();
      edtCidade->Value = Campos->Item[4]->ToString();
      cmbEstado->StringSelection = Campos->Item[5]->ToString();
    } else {
      edtBairro->Clear();
      edtCEP->Clear();
      edtCidade->Clear();
      cmbEstado->Selection = 0;
    }
  }
  
  Void frmCadEnderecos::HabilitaDados(Boolean bHabilita){
    edtBairro->Enabled = bHabilita;
    edtCEP->Enabled = bHabilita;  
    edtCidade->Enabled = bHabilita;
    cmbEstado->Enabled = bHabilita;  
  }

  Void frmCadEnderecos::AdicionaCombo(){
    vsEstados = new String*[26];
    vsEstados->SetValue(Resource::STR_PE, 0);
    vsEstados->SetValue(Resource::STR_AC, 1);
    vsEstados->SetValue(Resource::STR_AL, 2);
    vsEstados->SetValue(Resource::STR_AP, 3);
    vsEstados->SetValue(Resource::STR_AM, 4);
    vsEstados->SetValue(Resource::STR_BA, 5);
    vsEstados->SetValue(Resource::STR_BR, 6);
    vsEstados->SetValue(Resource::STR_CE, 7);
    vsEstados->SetValue(Resource::STR_DF, 8);
    vsEstados->SetValue(Resource::STR_ES, 9);
    vsEstados->SetValue(Resource::STR_GO, 10);
    vsEstados->SetValue(Resource::STR_MT, 11);
    vsEstados->SetValue(Resource::STR_MS, 12);
    vsEstados->SetValue(Resource::STR_MG, 13);
    vsEstados->SetValue(Resource::STR_PA, 14);
    vsEstados->SetValue(Resource::STR_PB, 15);
    vsEstados->SetValue(Resource::STR_PR, 16);
    vsEstados->SetValue(Resource::STR_SC, 17);
    vsEstados->SetValue(Resource::STR_RN, 18);
    vsEstados->SetValue(Resource::STR_RS, 19);
    vsEstados->SetValue(Resource::STR_RJ, 20);
    vsEstados->SetValue(Resource::STR_RO, 21);
    vsEstados->SetValue(Resource::STR_RR, 22);
    vsEstados->SetValue(Resource::STR_SP, 23);
    vsEstados->SetValue(Resource::STR_SE, 24);
    vsEstados->SetValue(Resource::STR_TO, 25);
  }

}
