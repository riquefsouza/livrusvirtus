#pragma once

#include "Cadastros.h"

namespace Livrus
{
	public __gc class frmVenderLivros : public frmCadastros
	{
    private:
      __value enum idx {
        ID_FRMVENDERLIVROS_BTNVENDER = 3000, ID_FRMVENDERLIVROS_BTNLIMPAR, 
        ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNPCLIENTE,
        ID_FRMVENDERLIVROS_BTNPLIVRO, ID_FRMVENDERLIVROS_LSTLIVROS,
        ID_FRMVENDERLIVROS_EDTDTHRVENDA, ID_FRMVENDERLIVROS_EDTISBN, 
        ID_FRMVENDERLIVROS_EDTLIVRO, ID_FRMVENDERLIVROS_EDTPRECOTOTAL, 
        ID_FRMVENDERLIVROS_LABDTHRVENDA, ID_FRMVENDERLIVROS_LABISBN, 
        ID_FRMVENDERLIVROS_LABLIVRO, ID_FRMVENDERLIVROS_LABLIVROS, 
        ID_FRMVENDERLIVROS_LABPRECOTOTAL, ID_FRMVENDERLIVROS_BTNADLIVROS
      };
      ArrayList *slPrecos, *slISBNs, *slQtdEstoque;
      double nPrecoTotal;
      wx::StaticText* labDtHrVenda;
      wx::TextCtrl* edtDtHrVenda;
      wx::Button* btnPCliente;
      wx::StaticText* labISBN;
      wx::TextCtrl* edtISBN;
      wx::StaticText* labLivro;
      wx::TextCtrl* edtLivro;
      wx::Button* btnAdLivros;
      wx::Button* btnPLivro;
      wx::StaticText* labLivros;
      wx::ListBox* lstLivros;
      wx::StaticText* labPrecoTotal;
      wx::TextCtrl* edtPrecoTotal;
      wx::Button* btnVender;
      Void FazLayout();
      Void LimpaDados();
      Boolean ValidaDados();
      Boolean SalvaLista();
      Void OnClose( System::Object* sender, wx::Event* e );
      Void OnBtnVender( System::Object* sender, wx::Event* e );
      Void OnBtnLimpar( System::Object* sender, wx::Event* e );
      Void OnBtnFechar( System::Object* sender, wx::Event* e );
      Void OnEdtCodigo_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPCliente( System::Object* sender, wx::Event* e );
      Void OnEdtISBN_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPLivro( System::Object* sender, wx::Event* e );
      Void OnBtnAdLivros( System::Object* sender, wx::Event* e );
      Void OnLstLivros_Dblclk( System::Object* sender, wx::Event* e );
  	public:
      frmVenderLivros( wx::Window* parent );
  };
}
