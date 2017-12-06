#include "stdafx.h"
#include "CadClientes.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConProfissoes.h"
#include "ConPaises.h"

namespace Livrus
{
  frmCadClientes::frmCadClientes( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NONE, false){

    labDescricao->Label = "Nome: ";
    edtDescricao->SetSize(System::Drawing::Size(312, 21));
    edtCodigo->EVT_KILL_FOCUS( 
      new EventListener( this, OnEdtCodigo_Killfocus ));

    labEmail = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABEMAIL,
      "E-mail: ", System::Drawing::Point(8, 88), System::Drawing::Size(34, 13), 0);
    edtEmail = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTEMAIL,
      "", System::Drawing::Point(8, 104), System::Drawing::Size(312, 21), 0);
    edtEmail->Enabled = false;
  
    labIdentidade = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABIDENTIDADE,
      "Identidade: ", System::Drawing::Point(322, 88), System::Drawing::Size(56, 13), 0);
    edtIdentidade = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTIDENTIDADE,
      "", System::Drawing::Point(322, 104), System::Drawing::Size(100, 21), 0);
    edtIdentidade->Enabled = false;  

    String* sItems __gc[] = { "Masculino", "Feminino" };
    rbSexo = new wx::RadioBox(this, (int)idx::ID_FRMCADCLIENTES_RBSEXO, "Sexo",
      System::Drawing::Point(9, 128), System::Drawing::Size(200, 44), sItems, 2, 
      wx::RadioBox::wxRA_SPECIFY_COLS);
    rbSexo->Enabled = false;
  
    labTelefone = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABTELEFONE,
      "Telefone: ", System::Drawing::Point(216, 128), System::Drawing::Size(48, 13), 0);
    edtTelefone = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTTELEFONE,
      "", System::Drawing::Point(216, 144), System::Drawing::Size(104, 21), 0);
    edtTelefone->Enabled = false;
  
    labDtNasc = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABDTNASC,
      "Dt. Nascimento", System::Drawing::Point(322, 128), System::Drawing::Size(73, 13), 0);
    edtDtNasc = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTDTNASC,
      "", System::Drawing::Point(322, 144), System::Drawing::Size(100, 21), 0);
    edtDtNasc->Enabled = false;
    edtDtNasc->EVT_KILL_FOCUS( 
      new EventListener( this, OnEdtDtNasc_Killfocus ));

    sbEndereco = new wx::StaticBox(this, (int)idx::ID_FRMCADCLIENTES_SBENDERECO,
      "Endereço", System::Drawing::Point(8, 176), System::Drawing::Size(432, 136), 0);
  
    edtCodEndereco = new TextValidatorCtrl(this, 
      (int)idx::ID_FRMCADCLIENTES_EDTCODENDERECO,
      "", System::Drawing::Point(16, 200), System::Drawing::Size(88, 21), 0, 
      TextValidatorCtrl::FILTER_NUMERIC);
    edtCodEndereco->Enabled = false;
    edtCodEndereco->EVT_KILL_FOCUS( 
      new EventListener( this, OnEdtCodEndereco_Killfocus ));
  
    btnPEndereco = new wx::Button(this, (int)idx::ID_FRMCADCLIENTES_BTNPENDERECO,
      "...", System::Drawing::Point(104, 200), System::Drawing::Size(21, 21), 0);
    btnPEndereco->Enabled = false;
  
    labLogradouro = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABLOGRADOURO,
      "Logradouro: ", System::Drawing::Point(16, 224), System::Drawing::Size(60, 13), 0);
    edtLogradouro = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTLOGRADOURO,
      "", System::Drawing::Point(16, 240), System::Drawing::Size(264, 21), 0);
    edtLogradouro->Enabled = false;
  
    labBairro = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABBAIRRO,
      "Bairro:", System::Drawing::Point(284, 224), System::Drawing::Size(48, 13), 0);
    edtBairro = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTBAIRRO,
      "", System::Drawing::Point(284, 240), System::Drawing::Size(144, 21), 0);
    edtBairro->Enabled = false;
  
    labCEP = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABCEP, "CEP: ",
      System::Drawing::Point(16, 264), System::Drawing::Size(40, 13), 0);
    edtCEP = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTCEP, "",
      System::Drawing::Point(16, 280), System::Drawing::Size(78, 21), 0);
    edtCEP->Enabled = false;
  
    labCidade = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABCIDADE,
      "Cidade: ", System::Drawing::Point(96, 264), System::Drawing::Size(39, 13), 0);
    edtCidade = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTCIDADE,
      "", System::Drawing::Point(96, 280), System::Drawing::Size(184, 21), 0);
    edtCidade->Enabled = false;
  
    labEstado = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABESTADO,
      "Estado: ", System::Drawing::Point(284, 264), System::Drawing::Size(56, 13), 0);
    edtEstado = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTESTADO,
      "", System::Drawing::Point(284, 280), System::Drawing::Size(144, 21), 0);
    edtEstado->Enabled = false;
  
    labPais = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABPAIS,
      "País de origem: ", System::Drawing::Point(8, 320), System::Drawing::Size(77, 16), 0);
    edtCodPais = new TextValidatorCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTCODPAIS,
      "", System::Drawing::Point(8, 336), System::Drawing::Size(78, 21), 0, 
      TextValidatorCtrl::FILTER_ALPHA);
    edtCodPais->Enabled = false;
    edtCodPais->EVT_KILL_FOCUS( 
      new EventListener( this, OnEdtCodPais_Killfocus ));
    edtPais = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTPAIS,
      "", System::Drawing::Point(88, 336), System::Drawing::Size(240, 21), 0);
    edtPais->Enabled = false;
    btnPPais = new wx::Button(this, (int)idx::ID_FRMCADCLIENTES_BTNPPAIS, "...",
      System::Drawing::Point(328, 336), System::Drawing::Size(21, 21), 0);
    btnPPais->Enabled = false;
  
    labProfissao = new wx::StaticText(this, (int)idx::ID_FRMCADCLIENTES_LABPROFISSAO,
      "Profissão: ", System::Drawing::Point(8, 360), System::Drawing::Size(56, 13), 0);
    edtCodProfissao = new TextValidatorCtrl(this, 
      (int)idx::ID_FRMCADCLIENTES_EDTCODPROFISSAO,
      "", System::Drawing::Point(8, 376), System::Drawing::Size(78, 21), 0, 
      TextValidatorCtrl::FILTER_NUMERIC);
    edtCodProfissao->Enabled = false;
    edtCodProfissao->EVT_KILL_FOCUS( 
      new EventListener( this, OnEdtCodProfissao_Killfocus ));
    edtProfissao = new wx::TextCtrl(this, (int)idx::ID_FRMCADCLIENTES_EDTPROFISSAO,
      "", System::Drawing::Point(88, 376), System::Drawing::Size(240, 21), 0);
    edtProfissao->Enabled = false;
    btnPProfissao = new wx::Button(this, (int)idx::ID_FRMCADCLIENTES_BTNPPROFISSAO,
      "...", System::Drawing::Point(328, 376), System::Drawing::Size(21, 21), 0);
    btnPProfissao->Enabled = false;
  
    IniciaBotoes();
    btnPesquisar->SetSize(440, 8, 75, 25);
    btnAnterior->SetSize(440, 40, 75, 25);
    btnProximo->SetSize(440, 72, 75, 25);
    btnSalvar->SetSize(200, 408, 75, 25);
    btnExcluir->SetSize(280, 408, 75, 25);
    btnLimpar->SetSize(360, 408, 75, 25);
    btnFechar->SetSize(440, 408, 75, 25);
  
    //FazLayout();
  
  	edtCodigo->MaxLength = 14;
    edtDescricao->MaxLength = 30;
    edtEmail->MaxLength = 30;
    edtIdentidade->MaxLength = 10;
    edtCodEndereco->MaxLength = 10;
    edtTelefone->MaxLength = 17;
    edtCodPais->MaxLength = 3;
    edtCodProfissao->MaxLength = 10;

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
    EVT_BUTTON((int)idx::ID_FRMCADCLIENTES_BTNPENDERECO, 
      new EventListener( this, OnBtnPEndereco ));
    EVT_BUTTON((int)idx::ID_FRMCADCLIENTES_BTNPPAIS, 
      new EventListener( this, OnBtnPPais ));
    EVT_BUTTON((int)idx::ID_FRMCADCLIENTES_BTNPPROFISSAO, 
      new EventListener( this, OnBtnPProfissao ));
  }

  Void frmCadClientes::FazLayout(){
    wx::BoxSizer* sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_3 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_4 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_5 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_16 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_23 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_22 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_19 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_15 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_21 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_20 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_18 = new wx::GridSizer(2, 1, 0, 0);
    wx::StaticBoxSizer* sizer_11 = new wx::StaticBoxSizer(
      new wx::StaticBox(this, -1, "Endereço"), wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_14 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_17 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_16 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_15 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_13 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_14 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_13 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_12 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_10 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_12 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_11 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_6 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_5 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_4 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_8 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
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
    sizer_5->Add(sizer_8, 1, wx::Stretch::wxEXPAND, 0);
    grid_sizer_4->Add(labEmail, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_4->Add(edtEmail, 0, 0, 0);
    sizer_6->Add(grid_sizer_4, 0, 0, 0);
    grid_sizer_5->Add(labIdentidade, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_5->Add(edtIdentidade, 0, 0, 0);
    sizer_6->Add(grid_sizer_5, 0, wx::Direction::wxLEFT, 4);
    sizer_5->Add(sizer_6, 0, 0, 0);
    sizer_10->Add(rbSexo, 0, 0, 0);
    grid_sizer_11->Add(labTelefone, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_11->Add(edtTelefone, 0, 0, 0);
    sizer_10->Add(grid_sizer_11, 1, wx::Direction::wxLEFT|wx::Stretch::wxEXPAND, 4);
    grid_sizer_12->Add(labDtNasc, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_12->Add(edtDtNasc, 0, 0, 0);
    sizer_10->Add(grid_sizer_12, 1, wx::Direction::wxLEFT|wx::Stretch::wxEXPAND, 4);
    sizer_5->Add(sizer_10, 1, wx::Stretch::wxEXPAND, 0);
    sizer_12->Add(edtCodEndereco, 0, 0, 0);
    sizer_12->Add(btnPEndereco, 0, 0, 0);
    sizer_11->Add(sizer_12, 0, wx::Direction::wxALL, 2);
    grid_sizer_13->Add(labLogradouro, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_13->Add(edtLogradouro, 0, 0, 0);
    sizer_13->Add(grid_sizer_13, 0, 0, 0);
    grid_sizer_14->Add(labBairro, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_14->Add(edtBairro, 0, 0, 0);
    sizer_13->Add(grid_sizer_14, 0, wx::Direction::wxLEFT, 4);
    sizer_11->Add(sizer_13, 0, 0, 0);
    grid_sizer_15->Add(labCEP, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_15->Add(edtCEP, 0, 0, 0);
    sizer_14->Add(grid_sizer_15, 0, 0, 0);
    grid_sizer_16->Add(labCidade, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_16->Add(edtCidade, 0, 0, 0);
    sizer_14->Add(grid_sizer_16, 0, wx::Direction::wxLEFT, 4);
    grid_sizer_17->Add(labEstado, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_17->Add(edtEstado, 0, 0, 0);
    sizer_14->Add(grid_sizer_17, 0, wx::Direction::wxLEFT, 4);
    sizer_11->Add(sizer_14, 1, 0, 0);
    sizer_5->Add(sizer_11, 0, 0, 0);
    grid_sizer_18->Add(labPais, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_18->Add(edtCodPais, 0, 0, 0);
    sizer_15->Add(grid_sizer_18, 0, 0, 0);
    grid_sizer_20->Add(20, 20, 0, 0, 0);
    grid_sizer_20->Add(edtPais, 0, 0, 0);
    sizer_15->Add(grid_sizer_20, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_21->Add(20, 20, 0, 0, 0);
    grid_sizer_21->Add(btnPPais, 0, 0, 0);
    sizer_15->Add(grid_sizer_21, 0, 0, 0);
    sizer_5->Add(sizer_15, 0, 0, 0);
    grid_sizer_19->Add(labProfissao, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_19->Add(edtCodProfissao, 0, 0, 0);
    sizer_16->Add(grid_sizer_19, 0, 0, 0);
    grid_sizer_22->Add(20, 20, 0, 0, 0);
    grid_sizer_22->Add(edtProfissao, 0, 0, 0);
    sizer_16->Add(grid_sizer_22, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_23->Add(20, 20, 0, 0, 0);
    grid_sizer_23->Add(btnPProfissao, 0, 0, 0);
    sizer_16->Add(grid_sizer_23, 0, 0, 0);
    sizer_5->Add(sizer_16, 0, 0, 0);
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

	Boolean frmCadClientes::ValidaDados(Boolean bTodosDados){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CODNINF))
      return false;
    if (bTodosDados) {
      if (RotinasGlobais::Rotinas->ValidaCampo(edtDescricao->Value, 
        Resource::STR_CLININF))
      	return false;
      if (RotinasGlobais::Rotinas->ValidaCampo(edtEmail->Value, 
        Resource::STR_EMAILNINF))
        return false;
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtTelefone->Value, 
        Resource::STR_TELNINF))
  		  return false;
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtCodEndereco->Value, 
        Resource::STR_ENDNINF))
  		  return false;
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtCodPais->Value, 
        Resource::STR_PAISNINF))
  		  return false;
  	  if (RotinasGlobais::Rotinas->ValidaCampo(edtCodProfissao->Value, 
        Resource::STR_PROFNINF))
  		  return false;
    }
		return true;
	}

  Void frmCadClientes::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  }
  
  Void frmCadClientes::OnBtnNovo( System::Object* sender, wx::Event* e ){
    btnNovoClick();
    InformaLimpaDados(false);
    HabilitaDados(true);
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    if (PesquisarDados(ConsultasSQL::ConsSQL->Cliente('S', edtCodigo->Value,
      "","","","","","","","",""),Resource::STR_CLINENC)) {
        InformaLimpaDados(true);
        HabilitaDados(true);	
      }
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnAnterior( System::Object* sender, wx::Event* e ){
    if (registroAnterior())
      InformaLimpaDados(true);
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnProximo( System::Object* sender, wx::Event* e ){
    if (registroProximo())
      InformaLimpaDados(true);
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnSalvar( System::Object* sender, wx::Event* e ){
    String *sSexo, *sDtNasc, *sSqlInsert, *sSqlUpdate;
  
    if (rbSexo->Selection == 0)
       sSexo = "M"; 
    else   
       sSexo = "F";
  
    sDtNasc = RotinasGlobais::Rotinas->ConverteDataHoraStr(
      edtDtNasc->Value,"MM/dd/yyyy");
  
    sSqlUpdate = ConsultasSQL::ConsSQL->Cliente('U', edtCodigo->Value, 
      edtDescricao->Value, edtEmail->Value,  edtIdentidade->Value, sSexo,  
      edtTelefone->Value, sDtNasc, edtCodEndereco->Value, 
      edtCodPais->Value, edtCodProfissao->Value);
  
    sSqlInsert = ConsultasSQL::ConsSQL->Cliente('I', edtCodigo->Value, 
      edtDescricao->Value, edtEmail->Value,  edtIdentidade->Value, sSexo,  
      edtTelefone->Value, sDtNasc, edtCodEndereco->Value, 
      edtCodPais->Value, edtCodProfissao->Value);
  
    if (SalvarDados(ValidaDados(true),
      ConsultasSQL::ConsSQL->Cliente('S', edtCodigo->Value,
        "","","","","","","","",""), sSqlUpdate, sSqlInsert, true)) {
      InformaLimpaDados(false);
      HabilitaDados(false);	
    }
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnExcluir( System::Object* sender, wx::Event* e ){
    if (ExcluirDados(ValidaDados(false),
      ConsultasSQL::ConsSQL->Cliente('D', edtCodigo->Value,
      "","","","","","","","",""))){
      InformaLimpaDados(false);
      HabilitaDados(false);	
    }  
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    btnLimparClick();
    InformaLimpaDados(false);
    HabilitaDados(false);	
    e->Skip();
  }

  Void frmCadClientes::InformaLimpaDados(Boolean bInformar){
    if (bInformar) {
      edtEmail->Value = Campos->Item[2]->ToString();
      edtIdentidade->Value = Campos->Item[3]->ToString();
      if (Campos->Item[4]->ToString() == "M")
        rbSexo->Selection = 0;
      else
        rbSexo->Selection = 1;
      edtTelefone->Value = Campos->Item[5]->ToString();
      edtDtNasc->Value = Campos->Item[6]->ToString()->Substring(0,10);
      edtCodEndereco->Value = Campos->Item[7]->ToString();
      edtLogradouro->Value = Campos->Item[8]->ToString();
      edtBairro->Value = Campos->Item[9]->ToString();
      edtCEP->Value = Campos->Item[10]->ToString();
      edtCidade->Value = Campos->Item[11]->ToString();
      edtEstado->Value = Campos->Item[12]->ToString();
      edtCodPais->Value = Campos->Item[13]->ToString();
      edtPais->Value = Campos->Item[14]->ToString();
      edtCodProfissao->Value = Campos->Item[15]->ToString();
      edtProfissao->Value = Campos->Item[16]->ToString();
    } else {
      edtEmail->Clear();
      edtIdentidade->Clear();
      rbSexo->Selection = 0;
      edtTelefone->Clear();
      edtDtNasc->Clear();
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
  
  Void frmCadClientes::HabilitaDados(Boolean bHabilita){
    edtEmail->Enabled = bHabilita;
    edtIdentidade->Enabled = bHabilita;
    rbSexo->Enabled = bHabilita;
    edtTelefone->Enabled = bHabilita;
    edtDtNasc->Enabled = bHabilita;
    edtCodEndereco->Enabled = bHabilita;
    btnPEndereco->Enabled = bHabilita;
    edtCodPais->Enabled = bHabilita;
    btnPPais->Enabled = bHabilita;
    edtCodProfissao->Enabled = bHabilita;
    btnPProfissao->Enabled = bHabilita;
  }
  
  Void frmCadClientes::OnEdtCodigo_Killfocus( System::Object* sender, 
    wx::Event* e ){   
    if (edtCodigo->Value->Length > 0) {
    	if (RotinasGlobais::Rotinas->ValidaCPF(edtCodigo->Value)==false) {
        wx::MessageDialog::MessageBox(Resource::STR_CPFINV, "Erro", 
          wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
        edtCodigo->Clear();
    		edtCodigo->SetFocus();
    	}
    }	
  }

  Void frmCadClientes::OnEdtDtNasc_Killfocus( System::Object* sender, 
    wx::Event* e ){   
    if (edtDtNasc->Value->Length > 0) {
      if (!RotinasGlobais::Rotinas->validaDataHora(edtDtNasc->Value, true)) {
        wx::MessageDialog::MessageBox(Resource::STR_DTHRINV, "Erro", 
          wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
        edtDtNasc->Value = RotinasGlobais::Rotinas->retDataHoraStr(true,false);
    		edtDtNasc->SetFocus();
      }
    } else
        edtDtNasc->Value = RotinasGlobais::Rotinas->retDataHoraStr(true,false);
    e->Skip();
  }
  
  Void frmCadClientes::OnEdtCodEndereco_Killfocus( System::Object* sender, 
    wx::Event* e ){
    String* sLogradouro;
    ArrayList* ConsCampo = new ArrayList();
     
    if (edtCodEndereco->Value->Length > 0) {
      sLogradouro = RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo, 
        ConsultasSQL::ConsSQL->Endereco('S',
        edtCodEndereco->Value,"","","","",""),Resource::STR_ENDNENC);
      if (sLogradouro->Length > 0) {
        edtLogradouro->Value = sLogradouro;
        edtBairro->Value = ConsCampo->Item[2]->ToString();
        edtCEP->Value = ConsCampo->Item[3]->ToString();
        edtCidade->Value = ConsCampo->Item[4]->ToString();
        edtEstado->Value = ConsCampo->Item[5]->ToString();
      } else {
    	  edtCodEndereco->SetFocus();
        edtLogradouro->Clear();
        edtBairro->Clear();
        edtCEP->Clear();
    	  edtCidade->Clear();
    	  edtEstado->Clear();
      }
    } else {
      edtLogradouro->Clear();
      edtBairro->Clear();
      edtCEP->Clear();
  	  edtCidade->Clear();
  	  edtEstado->Clear();
    }
  }
  
  Void frmCadClientes::OnEdtCodPais_Killfocus( System::Object* sender, 
    wx::Event* e ){
    String* sPais;
    ArrayList* ConsCampo = new ArrayList();  
  
    if (edtCodPais->Value->Length > 0) {
      sPais = RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo, 
        ConsultasSQL::ConsSQL->Pais('S',
        edtCodPais->Value,""),Resource::STR_PAISNENC);    
      if (sPais->Length > 0) {
        edtPais->Value = sPais;
      } else {
        edtCodPais->Clear();
        edtCodPais->SetFocus();
      }
    } else {
      edtPais->Clear();
    }
  }
  
  Void frmCadClientes::OnEdtCodProfissao_Killfocus( System::Object* sender, 
    wx::Event* e ){
    String* sProfissao;
    ArrayList* ConsCampo = new ArrayList();   
  
    if (edtCodProfissao->Value->Length > 0) {
      sProfissao = RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo, 
        ConsultasSQL::ConsSQL->Profissao('S',
        edtCodProfissao->Value,""),Resource::STR_PROFNENC);    
  
      if (sProfissao->Length > 0) {
        edtProfissao->Value = sProfissao;
      } else {
        edtCodProfissao->Clear();
        edtCodProfissao->SetFocus();
      }
    } else {
      edtProfissao->Clear();
    }
  }

  Void frmCadClientes::OnBtnPEndereco( System::Object* sender, wx::Event* e ){
    frmConEnderecos* fConEnderecos = new frmConEnderecos(this);
    fConEnderecos->ShowModal();
    edtCodEndereco->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtCodEndereco_Killfocus(0,0);
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnPPais( System::Object* sender, wx::Event* e ){
    frmConPaises* fConPaises = new frmConPaises(this);
    fConPaises->ShowModal();
    edtCodPais->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtCodPais_Killfocus(0,0);
    e->Skip();
  }
  
  Void frmCadClientes::OnBtnPProfissao( System::Object* sender, wx::Event* e ){
    frmConProfissoes* fConProfissoes = new frmConProfissoes(this);
    fConProfissoes->ShowModal();
    edtCodProfissao->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtCodProfissao_Killfocus(0,0);
    e->Skip();
  }

}
