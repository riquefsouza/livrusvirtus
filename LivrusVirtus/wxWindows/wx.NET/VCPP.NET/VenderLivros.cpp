#include "stdafx.h"
#include "VenderLivros.h"
#include "Resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConClientes.h"
#include "ConLivros.h"

namespace Livrus
{
  frmVenderLivros::frmVenderLivros( wx::Window* parent )
  	: frmCadastros(parent, TextValidatorCtrl::FILTER_NONE, false){

    slPrecos = new ArrayList();
    slISBNs = new ArrayList();
    slQtdEstoque = new ArrayList();
    btnNovo->Hide();
  
    labDtHrVenda = new wx::StaticText(this, (int)idx::ID_FRMVENDERLIVROS_LABDTHRVENDA,
      "Data/Hora Venda: ", System::Drawing::Point(8, 8), System::Drawing::Size(91, 13), 0);  
    edtDtHrVenda = new wx::TextCtrl(this, (int)idx::ID_FRMVENDERLIVROS_EDTDTHRVENDA,
      "", System::Drawing::Point(8, 24), System::Drawing::Size(128, 21), 0);
    edtDtHrVenda->Enabled = false;
  
    labCodigo->Label = "CPF: ";  
    labCodigo->SetSize(8, 48, 48, 13); 
    edtCodigo->SetSize(8, 64, 128, 21);
    edtCodigo->EVT_KILL_FOCUS(new wx::EventListener( this, OnEdtCodigo_Killfocus ));
  
    labDescricao->Label = "Cliente: ";
    labDescricao->SetSize(142, 48, 56, 13);  
    edtDescricao->SetSize(142, 64, 306, 21);
    edtDescricao->Enabled = false;
   
    btnPCliente = new wx::Button(this, (int)idx::ID_FRMVENDERLIVROS_BTNPCLIENTE,
      "...", System::Drawing::Point(448, 64), System::Drawing::Size(21, 21), 0);
    
    labISBN = new wx::StaticText(this, (int)idx::ID_FRMVENDERLIVROS_LABISBN,
      "ISBN: ", System::Drawing::Point(8, 88), System::Drawing::Size(48, 13), 0);  
    edtISBN = new wx::TextCtrl(this, (int)idx::ID_FRMVENDERLIVROS_EDTISBN,
      "", System::Drawing::Point(8, 104), System::Drawing::Size(128, 21), 0);
    edtISBN->EVT_KILL_FOCUS(new wx::EventListener( this, OnEdtISBN_Killfocus ));
    
    labLivro = new wx::StaticText(this, (int)idx::ID_FRMVENDERLIVROS_LABLIVRO,
      "Livro: ", System::Drawing::Point(142, 88), System::Drawing::Size(40, 13), 0);  
    edtLivro = new wx::TextCtrl(this, (int)idx::ID_FRMVENDERLIVROS_EDTLIVRO,
      "", System::Drawing::Point(142, 104), System::Drawing::Size(282, 21), 0);
    edtLivro->Enabled = false;
  
    btnAdLivros = new wx::Button(this, (int)idx::ID_FRMVENDERLIVROS_BTNADLIVROS,
    "+", System::Drawing::Point(424, 104), System::Drawing::Size(21, 21), 0);
    
    btnPLivro = new wx::Button(this, (int)idx::ID_FRMVENDERLIVROS_BTNPLIVRO,
      "...", System::Drawing::Point(448, 104), System::Drawing::Size(21, 21), 0);
    
    labLivros = new wx::StaticText(this, (int)idx::ID_FRMVENDERLIVROS_LABLIVROS,
      "Livros para vender: ", System::Drawing::Point(8, 128), 
      System::Drawing::Size(120, 13), 0);
    
    lstLivros = new wx::ListBox(this, (int)idx::ID_FRMVENDERLIVROS_LSTLIVROS,
      System::Drawing::Point(8, 144), System::Drawing::Size(464, 96));
    
    labPrecoTotal = new wx::StaticText(this, (int)idx::ID_FRMVENDERLIVROS_LABPRECOTOTAL,
      "Preço Total: ", System::Drawing::Point(280, 248), System::Drawing::Size(61, 13), 0);  
    edtPrecoTotal = new wx::TextCtrl(this, (int)idx::ID_FRMVENDERLIVROS_EDTPRECOTOTAL,
      "R$ 0,00", System::Drawing::Point(344, 246), System::Drawing::Size(127, 21), 0);
    edtPrecoTotal->Enabled = false;
    
    btnVender = new wx::Button(this, (int)idx::ID_FRMVENDERLIVROS_BTNVENDER,
      "&Vender", System::Drawing::Point(239, 275), System::Drawing::Size(75, 25), 0);  
    btnLimpar = new wx::Button(this, (int)idx::ID_FRMVENDERLIVROS_BTNLIMPAR,
      "&Limpar", System::Drawing::Point(319, 275), System::Drawing::Size(75, 25), 0);  
    btnFechar = new wx::Button(this, (int)idx::ID_FRMVENDERLIVROS_BTNFECHAR,
      "&Fechar", System::Drawing::Point(399, 275), System::Drawing::Size(75, 25), 0);
  
    //FazLayout();
  
    edtDtHrVenda->Value = RotinasGlobais::Rotinas->retDataHoraStr(true, true);
    edtCodigo->MaxLength = 14;
    edtISBN->MaxLength = 13;
    nPrecoTotal = 0;

    EVT_BUTTON((int)idx::ID_FRMVENDERLIVROS_BTNVENDER, 
      new wx::EventListener( this, OnBtnVender ));
    EVT_BUTTON((int)idx::ID_FRMVENDERLIVROS_BTNLIMPAR, 
      new wx::EventListener( this, OnBtnLimpar ));
    EVT_BUTTON((int)idx::ID_FRMVENDERLIVROS_BTNFECHAR, 
      new wx::EventListener( this, OnBtnFechar ));
		EVT_CLOSE( new wx::EventListener( this, OnClose ) );
    EVT_BUTTON((int)idx::ID_FRMVENDERLIVROS_BTNPCLIENTE, 
      new wx::EventListener( this, OnBtnPCliente ));
    EVT_BUTTON((int)idx::ID_FRMVENDERLIVROS_BTNPLIVRO, 
      new wx::EventListener( this, OnBtnPLivro ));
    EVT_BUTTON((int)idx::ID_FRMVENDERLIVROS_BTNADLIVROS, 
      new wx::EventListener( this, OnBtnAdLivros ));
    EVT_LISTBOX_DCLICK((int)idx::ID_FRMVENDERLIVROS_LSTLIVROS, 
      new wx::EventListener( this, OnLstLivros_Dblclk ));
  }

  Void frmVenderLivros::FazLayout(){
    wx::BoxSizer *sizer_1 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer *sizer_6 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer *sizer_8 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer *sizer_7 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::BoxSizer *sizer_5 = new wx::BoxSizer(wx::Orientation::wxVERTICAL);
    wx::BoxSizer *sizer_4 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer *grid_sizer_8 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer *grid_sizer_7 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer *grid_sizer_6 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer *grid_sizer_5 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer *sizer_3 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer *grid_sizer_4 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer *grid_sizer_3 = new wx::GridSizer(2, 1, 0, 0);
    wx::GridSizer *grid_sizer_2 = new wx::GridSizer(2, 1, 0, 0);
    wx::BoxSizer *sizer_2 = new wx::BoxSizer(wx::Orientation::wxHORIZONTAL);
    wx::GridSizer *grid_sizer_1 = new wx::GridSizer(2, 1, 0, 0);
    grid_sizer_1->Add(labDtHrVenda, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_1->Add(edtDtHrVenda, 0, 0, 0);
    sizer_2->Add(grid_sizer_1, 0, wx::Direction::wxLEFT, 2);
    sizer_2->Add(20, 20, 0, 0, 0);
    sizer_1->Add(sizer_2, 0, 0, 0);
    grid_sizer_2->Add(labCodigo, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_2->Add(edtCodigo, 0, 0, 0);
    sizer_3->Add(grid_sizer_2, 0, wx::Direction::wxLEFT, 2);
    grid_sizer_3->Add(labDescricao, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    grid_sizer_3->Add(edtDescricao, 0, 0, 0);
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
    grid_sizer_7->Add(20, 20, 0, 0, 0);
    grid_sizer_7->Add(btnAdLivros, 0, 0, 0);
    sizer_4->Add(grid_sizer_7, 1, wx::Stretch::wxEXPAND, 0);
    grid_sizer_8->Add(20, 20, 0, 0, 0);
    grid_sizer_8->Add(btnPLivro, 0, 0, 0);
    sizer_4->Add(grid_sizer_8, 0, 0, 0);
    sizer_1->Add(sizer_4, 0, 0, 0);
    sizer_5->Add(labLivros, 0, wx::Alignment::wxALIGN_BOTTOM, 0);
    sizer_5->Add(lstLivros, 1, wx::Direction::wxALL|wx::Stretch::wxEXPAND, 1);
    sizer_1->Add(sizer_5, 1, wx::Stretch::wxEXPAND, 0);
    sizer_7->Add(labPrecoTotal, 0, wx::Direction::wxALL, 2);
    sizer_7->Add(edtPrecoTotal, 0, wx::Direction::wxALL, 2);
    sizer_6->Add(sizer_7, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT, 2);
    sizer_8->Add(btnVender, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_8->Add(btnLimpar, 0, wx::Direction::wxALL| 
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_8->Add(btnFechar, 0, wx::Direction::wxALL|
      wx::Alignment::wxALIGN_RIGHT|wx::Alignment::wxALIGN_BOTTOM, 2);
    sizer_6->Add(sizer_8, 0, wx::Direction::wxALL, 2);
    sizer_1->Add(sizer_6, 0, wx::Alignment::wxALIGN_RIGHT|
      wx::Alignment::wxALIGN_BOTTOM, 0);
    AutoLayout = true;
    SetSizer(sizer_1);
    sizer_1->Fit(this);
    sizer_1->SetSizeHints(this);
  }

  Void frmVenderLivros::LimpaDados() {
    edtDtHrVenda->Value = RotinasGlobais::Rotinas->retDataHoraStr(true, true);
    edtCodigo->Clear();
    edtDescricao->Clear();
    edtISBN->Clear();
    edtLivro->Clear();
    lstLivros->Clear();
    nPrecoTotal = 0;
    edtPrecoTotal->Value = "R$ 0,00";
    edtCodigo->SetFocus();
  }

	Boolean frmVenderLivros::ValidaDados(){
    if (RotinasGlobais::Rotinas->ValidaCampo(edtCodigo->Value, 
      Resource::STR_CPFNINF))
      return false;
    if (lstLivros->Count==0) {
      wx::MessageDialog::MessageBox(Resource::STR_LIVVENNINF, "Erro", 
        wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
      return false;
    }
		return true;
	}

  Boolean frmVenderLivros::SalvaLista(){
    String *sCPF, *sISBN, *sPrecoTotal, *sDataHora, *sQtdEstoque, *sDTHR;
    int nCont, nQtd, nQtdEstoque;
    OleDbCommand *Arquiva = new OleDbCommand();
  
    nQtd = lstLivros->Count;
    sCPF = edtCodigo->Value;
    sPrecoTotal = Convert::ToString(nPrecoTotal);
    
    sDTHR = edtDtHrVenda->Value;
    sDataHora = RotinasGlobais::Rotinas->ConverteDataHoraStr(sDTHR,
      "MM/dd/YYYY hh:mm:ss");
    
    for (nCont=0; nCont < nQtd; nCont++) {
      sISBN = slISBNs->Item[nCont]->ToString();
    
      RotinasGlobais::Rotinas->AtualizaDados(Arquiva, 
        ConsultasSQL::ConsSQL->Venda('I',sISBN, sCPF, sDataHora,
        RotinasGlobais::Rotinas->VirgulaParaPonto(sPrecoTotal,false),""));
    
      nQtdEstoque = Int32::Parse(slQtdEstoque->Item[nCont]->ToString());
      if (nQtdEstoque >= 0) 
        nQtdEstoque = nQtdEstoque - 1;
      sQtdEstoque = Convert::ToString(nQtdEstoque);
      RotinasGlobais::Rotinas->AtualizaDados(Arquiva, 
        ConsultasSQL::ConsSQL->Venda('U',sISBN, "","","", sQtdEstoque));
    }
    return true;
  }

  Void frmVenderLivros::OnClose( System::Object* sender, wx::Event* e ){
   this->Parent->Close();
  	e->Skip();
  } 

  Void frmVenderLivros::OnBtnFechar( System::Object* sender, wx::Event* e ){
    this->Close(true);
    e->Skip();
  }
 
  Void frmVenderLivros::OnEdtCodigo_Killfocus( System::Object* sender, wx::Event* e ){
    String *sCliente;
    ArrayList *ConsCampo = new ArrayList();    
  
    if (edtCodigo->Value->Length > 0) {
      if (RotinasGlobais::Rotinas->ValidaCPF(edtCodigo->Value)) {
        sCliente = RotinasGlobais::Rotinas->ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL::ConsSQL->Cliente('S', edtCodigo->Value,
          "","","","","","","","",""),Resource::STR_CLINENC); 
        if (sCliente->Length==0) {
          edtCodigo->Clear();
          edtCodigo->SetFocus();
        } else
           edtDescricao->Value = sCliente;
      } else {
        wx::MessageDialog::MessageBox(Resource::STR_CPFINV, "Erro", 
          wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR);
        edtCodigo->Clear();
        edtCodigo->SetFocus();
      }
    } else
       edtDescricao->Clear();
  }
  
  Void frmVenderLivros::OnBtnPCliente( System::Object* sender, wx::Event* e ){
    frmConClientes *fConClientes = new frmConClientes(this);
    fConClientes->ShowModal();
    edtCodigo->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtCodigo_Killfocus(0,0);
    e->Skip();
  }
  
  Void frmVenderLivros::OnEdtISBN_Killfocus( System::Object* sender, wx::Event* e ){
    String *sLivro;
    int nQtdEstoque;
    ArrayList *ConsCampo = new ArrayList();       
  
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
             RotinasGlobais::Rotinas->sQtdEstoque = ConsCampo->Item[3]->ToString();
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
  
  Void frmVenderLivros::OnBtnPLivro( System::Object* sender, wx::Event* e ){
    frmConLivros *fConLivros = new frmConLivros(this);
    fConLivros->ShowModal();
    edtISBN->Value = RotinasGlobais::Rotinas->sCodigoSelecionado;
    OnEdtISBN_Killfocus(0,0);
    e->Skip();
  }
  
  Void frmVenderLivros::OnBtnAdLivros( System::Object* sender, wx::Event* e ){
    double nPreco; 
    String *sLivros, *sISBN, *sEdtLivro, *sPrecoTotal;
  
   sISBN = edtISBN->Value;
   sEdtLivro = edtLivro->Value;
   if (sISBN->Length > 0) {
     sLivros = String::Concat(sISBN,S" - ",sEdtLivro,S" - R$ ", 
      RotinasGlobais::Rotinas->sPreco);
     if (RotinasGlobais::Rotinas->PesquisaItemLista(lstLivros, sLivros)==-1) {
       slISBNs->Add(sISBN);
       slPrecos->Add(RotinasGlobais::Rotinas->sPreco);
       slQtdEstoque->Add(RotinasGlobais::Rotinas->sQtdEstoque);
       lstLivros->Append(sLivros);
       nPreco = Double::Parse(RotinasGlobais::Rotinas->sPreco);
       nPrecoTotal = nPrecoTotal + nPreco;
     }
     edtISBN->Clear();
     edtLivro->Clear();
     sPrecoTotal = String::Concat("R$ ", Convert::ToString(nPrecoTotal));
     edtPrecoTotal->Value = 
       RotinasGlobais::Rotinas->VirgulaParaPonto(sPrecoTotal,true);
   }
   e->Skip();
  }
  
  Void frmVenderLivros::OnLstLivros_Dblclk( System::Object* sender, wx::Event* e ){
    String *sPrecoTotal;
    double nPreco;
    int nSelIndice;
  
    if (lstLivros->Count > 0) {   
      nSelIndice = lstLivros->Selection;
      if (lstLivros->Selected(nSelIndice)) {
        nPreco = Double::Parse(slPrecos->Item[nSelIndice]->ToString());
        nPrecoTotal = nPrecoTotal-nPreco;     
        sPrecoTotal = String::Concat("R$ ",Convert::ToString(nPrecoTotal));
        edtPrecoTotal->Value = 
          RotinasGlobais::Rotinas->VirgulaParaPonto(sPrecoTotal,true);
        slISBNs->RemoveAt(nSelIndice);
        slPrecos->RemoveAt(nSelIndice);
        slQtdEstoque->RemoveAt(nSelIndice);
        lstLivros->Delete(nSelIndice);
      }	
    }
    e->Skip();
  }    

  Void frmVenderLivros::OnBtnVender( System::Object* sender, wx::Event* e ){
    if (ValidaDados()) {
      if (SalvaLista()) {
        wx::MessageDialog::MessageBox(Resource::STR_VENRESUC, 
        Resource::STR_TITULO, wx::Dialog::wxOK | wx::Dialog::wxICON_INFORMATION);
        LimpaDados();
      }
    }	
    e->Skip();
  }   
  
  Void frmVenderLivros::OnBtnLimpar( System::Object* sender, wx::Event* e ){
    LimpaDados();
    e->Skip();
  }

}
