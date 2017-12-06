#include "stdafx.h"
#include "ConVendas.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConClientes.h"
#include "ConLivros.h"

namespace Livrus
{
  frmConVendas::frmConVendas( wx::Window* parent )
  	: wx::Panel(parent, -1, System::Drawing::Point(0, 0), 
      System::Drawing::Size(480, 310)){

    labDtHrVenda = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABDTHRVENDA,
      "Data/Hora Venda: ", System::Drawing::Point(8, 8), System::Drawing::Size(91, 13), 0);  
    edtDtHrVenda = new wx::TextCtrl(this, (int)idx::ID_FRMCONVENDAS_EDTDTHRVENDA,
      "", System::Drawing::Point(8, 24), System::Drawing::Size(128, 21), 0);
    edtDtHrVenda->EVT_KILL_FOCUS(new wx::EventListener( this, OnEdtDtHrVenda_Killfocus ));
  
    btnPesquisar = new wx::Button(this, (int)idx::ID_FRMCONVENDAS_BTNPESQUISAR,
      "&Pesquisar", System::Drawing::Point(144, 22), System::Drawing::Size(75, 25), 0);
  
    labCPF = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABCPF,
      "CPF: ", System::Drawing::Point(8, 48), System::Drawing::Size(48, 13), 0);  
    edtCPF = new wx::TextCtrl(this, (int)idx::ID_FRMCONVENDAS_EDTCPF,
      "", System::Drawing::Point(8, 64), System::Drawing::Size(128, 21), 0);
    edtCPF->EVT_KILL_FOCUS(new wx::EventListener( this, OnEdtCPF_Killfocus ));
  
    labCliente = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABCLIENTE,
      "Cliente: ", System::Drawing::Point(142, 48), System::Drawing::Size(56, 13), 0);  
    edtCliente = new wx::TextCtrl(this, (int)idx::ID_FRMCONVENDAS_EDTCLIENTE,
      "", System::Drawing::Point(142, 64), System::Drawing::Size(306, 21), 0);
    edtCliente->Enabled = false;
   
    btnPCliente = new wx::Button(this, (int)idx::ID_FRMCONVENDAS_BTNPCLIENTE,
      "...", System::Drawing::Point(448, 64), System::Drawing::Size(21, 21), 0);
    
    labISBN = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABISBN,
      "ISBN: ", System::Drawing::Point(8, 88), System::Drawing::Size(48, 13), 0);  
    edtISBN = new wx::TextCtrl(this, (int)idx::ID_FRMCONVENDAS_EDTISBN,
      "", System::Drawing::Point(8, 104), System::Drawing::Size(128, 21), 0);
    edtISBN->EVT_KILL_FOCUS(new wx::EventListener( this, OnEdtISBN_Killfocus ));
    
    labLivro = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABLIVRO,
      "Livro: ", System::Drawing::Point(142, 88), System::Drawing::Size(40, 13), 0);  
    edtLivro = new wx::TextCtrl(this, (int)idx::ID_FRMCONVENDAS_EDTLIVRO,
      "", System::Drawing::Point(142, 104), System::Drawing::Size(306, 21), 0);
    edtLivro->Enabled = false;
  
    btnPLivro = new wx::Button(this, (int)idx::ID_FRMCONVENDAS_BTNPLIVRO,
      "...", System::Drawing::Point(448, 104), System::Drawing::Size(21, 21), 0);
  
    this->gridVendas = new wx::Grid(this, (int)idx::ID_FRMCONVENDAS_GRIDVENDAS, 
      System::Drawing::Point(0, 136), System::Drawing::Size(355, 122), wxSUNKEN_BORDER);
    this->gridVendas->CreateGrid(1, 6, wx::GridSelectionMode::wxGridSelectRows);
    this->gridVendas->HideCellEditControl();
    this->gridVendas->ColLabelSize = 21;
  
    this->labRegistro = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABREGISTRO,
      "Registro 0 de 0", System::Drawing::Point(8, 16), System::Drawing::Size(144, 13), 0);
  
    labPrecoTotal = new wx::StaticText(this, (int)idx::ID_FRMCONVENDAS_LABPRECOTOTAL,
      "Preço Total: ", System::Drawing::Point(280, 248), System::Drawing::Size(61, 13), 0);  
    edtPrecoTotal = new wx::TextCtrl(this, (int)idx::ID_FRMCONVENDAS_EDTPRECOTOTAL,
      "", System::Drawing::Point(344, 246), System::Drawing::Size(127, 21), 0);
    edtPrecoTotal->Enabled = false;
  
    this->btnLimpar = new wx::Button(this, (int)idx::ID_FRMCONVENDAS_BTNLIMPAR,
      "&Limpar", System::Drawing::Point(16, 13), System::Drawing::Size(75, 25), 0);
    this->btnFechar = new wx::Button(this, (int)idx::ID_FRMCONVENDAS_BTNFECHAR,
      "&Fechar", System::Drawing::Point(75, 13), System::Drawing::Size(75, 25), 0);
  
    FazLayout();
  
    int nLargura __gc[] = { 120, 100, 220, 100, 280, 80 };
    String* sRotulos __gc[] = { "Data/Hora Venda", "CPF", "Cliente", 
     "ISBN", "Livro", "Preço" };
    RotinasGlobais::Rotinas->AdicionaColunasGrid(gridVendas, 0, 6, nLargura, sRotulos);
    gridVendas->Editable = false;
    edtCPF->MaxLength = 14;
    edtISBN->MaxLength = 13;
    edtPrecoTotal->Value = "R$ 0,00";
    edtDtHrVenda->Value = RotinasGlobais::Rotinas->retDataHoraStr(true,true);

    EVT_BUTTON((int)idx::ID_FRMCONVENDAS_BTNPESQUISAR, 
      new wx::EventListener( this, OnBtnPesquisar ));
    EVT_BUTTON((int)idx::ID_FRMCONVENDAS_BTNLIMPAR, 
      new wx::EventListener( this, OnBtnLimpar ));
    EVT_BUTTON((int)idx::ID_FRMCONVENDAS_BTNFECHAR, 
      new wx::EventListener( this, OnBtnFechar ));
    EVT_CLOSE( new wx::EventListener( this, OnClose ));
    EVT_BUTTON((int)idx::ID_FRMCONVENDAS_BTNPCLIENTE, 
      new wx::EventListener( this, OnBtnPCliente ));
    EVT_BUTTON((int)idx::ID_FRMCONVENDAS_BTNPLIVRO, 
      new wx::EventListener( this, OnBtnPLivro ));
    EVT_GRID_SELECT_CELL( new wx::EventListener( this, OnGridSelectCell ));
    EVT_GRID_LABEL_LEFT_CLICK( new wx::EventListener( this, 
      OnGridLabelLeftClick ));
  }

  Void frmConVendas::FazLayout(){
    wx::BoxSizer* sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_6 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::GridSizer* sizer_22 = new wx::GridSizer(1, 2, 0, 0);
    wx::BoxSizer* sizer_23 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_8 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_7 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer* sizer_24 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer* sizer_4 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_8 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_6 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_5 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_3 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_4 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_3 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer* grid_sizer_2 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer* sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer* grid_sizer_1 = new wx::GridSizer(2, 1, 0, 0);
    grid_sizer_1->Add(labDtHrVenda, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_1->Add(edtDtHrVenda, 0, 0, 0);
    sizer_2->Add(grid_sizer_1, 0, wx::Direction::wxLEFT, 2);
    sizer_2->Add(btnPesquisar, 0, wx::Direction::wxLEFT|
      wx::Direction::wxTOP|wx::Alignment::wxALIGN_BOTTOM, 10);
    sizer_1->Add(sizer_2, 0, 0, 0);
    grid_sizer_2->Add(labCPF, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_2->Add(edtCPF, 0, 0, 0);
    sizer_3->Add(grid_sizer_2, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_3->Add(labCliente, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_3->Add(edtCliente, 0, 0, 0);
    sizer_3->Add(grid_sizer_3, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_4->Add(20, 20, 0, 0, 0);
    grid_sizer_4->Add(btnPCliente, 0, 0, 0);
    sizer_3->Add(grid_sizer_4, 0, 0, 0);
    sizer_1->Add(sizer_3, 0, 0, 0);
    grid_sizer_5->Add(labISBN, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_5->Add(edtISBN, 0, 0, 0);
    sizer_4->Add(grid_sizer_5, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_6->Add(labLivro, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_6->Add(edtLivro, 0, 0, 0);
    sizer_4->Add(grid_sizer_6, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_8->Add(20, 20, 0, 0, 0);
    grid_sizer_8->Add(btnPLivro, 0, 0, 0);
    sizer_4->Add(grid_sizer_8, 0, 0, 0);
    sizer_1->Add(sizer_4, 0, 0, 0);
    sizer_1->Add(gridVendas, 1, wx::Direction::wxALL|wx::Stretch::wxEXPAND, 2);
    sizer_24->Add(labRegistro, 0, wx::Direction::wxALL, 4);
    sizer_24->Add(20, 20, 0, 0, 0);
    sizer_22->Add(sizer_24, 0, 0, 0);
    sizer_7->Add(labPrecoTotal, 0, wx::Direction::wxALL, 2);
    sizer_7->Add(edtPrecoTotal, 0, wx::Direction::wxALL, 2);
    sizer_23->Add(sizer_7, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_8->Add(btnLimpar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_8->Add(btnFechar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_23->Add(sizer_8, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_22->Add(sizer_23, 1, wx::Alignment::wxALIGN_RIGHT|
      wx::Alignment::wxALIGN_BOTTOM, 0);
    sizer_6->Add(sizer_22, 0, wx::Stretch::wxEXPAND, 0);
    sizer_1->Add(sizer_6, 0, wx::Stretch::wxEXPAND, 0);
    AutoLayout = true;
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
  }

  Void frmConVendas::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    edtCPF->Clear();
    edtCliente->Clear();
    edtISBN->Clear();
    edtLivro->Clear();
    gridVendas->ClearGrid();
    gridVendas->DeleteRows(0, gridVendas->NumberRows-1,true);
    edtPrecoTotal->Value = "R$ 0,00";
    edtDtHrVenda->Value = RotinasGlobais::Rotinas->retDataHoraStr(true,true);
    labRegistro->Label = "Registro 0 de 0";
    edtDtHrVenda->SetFocus();
    e->Skip();
  }

  String* frmConVendas::ConsVenda(char sOpcao){
    String *sISBN, *sCPF, *sDataHora, *sret;
  
    if (edtDtHrVenda->Value->Length > 0)
      sDataHora = RotinasGlobais::Rotinas->ConverteDataHoraStr(
        edtDtHrVenda->Value, "MM/dd/yyyy hh:mm:ss");
    else
      sDataHora = "";
  
    sISBN = edtISBN->Value;
    sCPF = edtCPF->Value;
  
    if (sOpcao=='L')
      sret = ConsultasSQL::ConsSQL->Venda('S',"ZERO","","","","");
    else
      sret = ConsultasSQL::ConsSQL->Venda(sOpcao, sISBN, sCPF, sDataHora, "", "");
  
   return sret;
  }

  Void frmConVendas::OnClose( System::Object* sender, wx::Event* e ){
    this->Parent->Close();
  	e->Skip();
  }

  Void frmConVendas::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
  
  Void frmConVendas::OnBtnPesquisar( System::Object* sender, wx::Event* e ){
    ArrayList* ConsTotal = new ArrayList();
    ArrayList* lstLinhas = new ArrayList();
    ArrayList* lstTotal;
    String* sPrecoTotal;
    double nTemp;
  
    if (RotinasGlobais::Rotinas->ConsultaDadosLista(lstLinhas, ConsVenda('S'))) {
      RotinasGlobais::Rotinas->AdicionaLinhasGrid(gridVendas, lstLinhas, 6);
  
      if (RotinasGlobais::Rotinas->ConsultaDadosLista(ConsTotal, ConsVenda('P'))) {
        if (ConsTotal->Count > 0) {
         lstTotal = dynamic_cast<ArrayList*>(ConsTotal->Item[0]);
          nTemp = Double::Parse(lstTotal->Item[0]->ToString()); 
          sPrecoTotal = nTemp.ToString("C"); 
          edtPrecoTotal->Value = sPrecoTotal;
        }
      }    
    } else {
       wx::MessageDialog::MessageBox(Resource::STR_VENNENC, "Erro", 
        wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
    }
  }
  
  Void frmConVendas::OnEdtCPF_Killfocus( System::Object* sender, wx::Event* e ){
    String* sCliente;
    ArrayList* ConsCampo = new ArrayList();    
  
    if (edtCPF->Value->Length > 0) {
      if (RotinasGlobais::Rotinas->ValidaCPF(edtCPF->Value)) {      
        sCliente = RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL::ConsSQL->Cliente('S',edtCPF->Value,
          "","","","","","","","",""),Resource::STR_CLINENC); 
        if (sCliente->Length==0) {
          edtCPF->Clear();
          edtCPF->SetFocus();
        } else
           edtCliente->Value = sCliente;
      } else {
        wx::MessageDialog::MessageBox(Resource::STR_CPFINV, "Erro", 
          wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
        edtCPF->Clear();
        edtCPF->SetFocus();
      }
    } else
       edtCliente->Clear();
  }
  
  Void frmConVendas::OnBtnPCliente( System::Object* sender, wx::Event* e ){
    frmConClientes *fConClientes = new frmConClientes(this);
    fConClientes->ShowModal();
    edtCPF->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtCPF_Killfocus(0,0);	
    e->Skip();
  }
  
  Void frmConVendas::OnEdtISBN_Killfocus( System::Object* sender, wx::Event* e ){
    String* sLivro;
    int nQtdEstoque;
    ArrayList* ConsCampo = new ArrayList();
  
    if (edtISBN->Value->Length > 0) {
      if (RotinasGlobais::Rotinas->ValidaISBN(edtISBN->Value)) {      
        sLivro = RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL::ConsSQL->Livro('Q',edtISBN->Value,
          "","","","","","","","",""),Resource::STR_LIVNENC);
        if (sLivro->Length==0) {
          edtISBN->Clear();
        	edtISBN->SetFocus();
        } else {
           edtLivro->Value = sLivro;
           nQtdEstoque = Int32::Parse(ConsCampo->Item[3]->ToString());
           if (nQtdEstoque > 0) {
             RotinasGlobais::Rotinas->sPreco = ConsCampo->Item[2]->ToString();
           } else
             wx::MessageDialog::MessageBox(Resource::STR_LIVNEST, "Erro", 
               wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
        }
      } else {
        wx::MessageDialog::MessageBox(Resource::STR_ISBNINV, "Erro", 
          wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
        edtISBN->Clear();
        edtISBN->SetFocus();
      }
    } else
       edtLivro->Clear();
  }
  
  Void frmConVendas::OnBtnPLivro( System::Object* sender, wx::Event* e ){
    frmConLivros *fConLivros = new frmConLivros(this);
    fConLivros->ShowModal();
    edtISBN->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtISBN_Killfocus(0,0);	
    e->Skip();
  }
  
  Void frmConVendas::setLabRegistros(int nLinha) {
    if (nLinha >= 0) {
      labRegistro->Label = String::Concat("Registro ",Convert::ToString(nLinha+1), 
        " de ",Convert::ToString(gridVendas->NumberRows));
    }
  }
  
  Void frmConVendas::OnGridSelectCell( System::Object* sender, wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConVendas::OnGridLabelLeftClick( System::Object* sender, wx::Event* e ){
    wx::GridEvent* evt = dynamic_cast<wx::GridEvent*>(e);
    setLabRegistros(evt->Row);
    e->Skip();
  }
  
  Void frmConVendas::OnEdtDtHrVenda_Killfocus( System::Object* sender, wx::Event* e ){
    if (edtDtHrVenda->Value->Length > 0) {
      if (!RotinasGlobais::Rotinas->validaDataHora(edtDtHrVenda->Value, false)) {
        wx::MessageDialog::MessageBox(Resource::STR_DTHRINV, "Erro", 
          wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
    		edtDtHrVenda->SetFocus();
      }
    } 
  }

}
