#pragma once

namespace Livrus
{
	public __gc class frmConVendas : public wx::Panel
	{
    private:
      __value enum idx {
        ID_FRMCONVENDAS_BTNPESQUISAR = 3100, ID_FRMCONVENDAS_BTNLIMPAR, 
        ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNPCLIENTE,
        ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_GRIDVENDAS,
        ID_FRMCONVENDAS_EDTDTHRVENDA, ID_FRMCONVENDAS_EDTISBN, 
        ID_FRMCONVENDAS_EDTLIVRO, ID_FRMCONVENDAS_EDTPRECOTOTAL, 
        ID_FRMCONVENDAS_LABDTHRVENDA, ID_FRMCONVENDAS_LABISBN, 
        ID_FRMCONVENDAS_LABLIVRO, ID_FRMCONVENDAS_LABPRECOTOTAL,
        ID_FRMCONVENDAS_LABCPF, ID_FRMCONVENDAS_EDTCPF, 
        ID_FRMCONVENDAS_LABCLIENTE, ID_FRMCONVENDAS_EDTCLIENTE, 
        ID_FRMCONVENDAS_LABREGISTRO
      };
      wx::StaticText* labDtHrVenda;
      wx::TextCtrl* edtDtHrVenda;
      wx::StaticText* labCPF;
      wx::TextCtrl* edtCPF;
      wx::StaticText* labCliente;
      wx::TextCtrl* edtCliente;
      wx::Button* btnPCliente;
      wx::StaticText* labISBN;
      wx::TextCtrl* edtISBN;
      wx::StaticText* labLivro;
      wx::TextCtrl* edtLivro;
      wx::Button* btnPLivro;
      wx::StaticText* labRegistro;
      wx::Grid* gridVendas;
      wx::StaticText* labPrecoTotal;
      wx::TextCtrl* edtPrecoTotal;
      wx::Button* btnPesquisar;
      wx::Button* btnLimpar;
      wx::Button* btnFechar;
      Void FazLayout();
      String* ConsVenda(char sOpcao);
      Void OnClose( System::Object* sender, wx::Event* e );
      Void OnBtnPesquisar( System::Object* sender, wx::Event* e );
      Void OnBtnLimpar( System::Object* sender, wx::Event* e );
      Void OnBtnFechar( System::Object* sender, wx::Event* e );
      Void OnEdtCPF_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPCliente( System::Object* sender, wx::Event* e );
      Void OnEdtISBN_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPLivro( System::Object* sender, wx::Event* e );
      Void setLabRegistros(int nLinha);
      Void OnGridSelectCell( System::Object* sender, wx::Event* e );
      Void OnGridLabelLeftClick( System::Object* sender, wx::Event* e );
      Void OnEdtDtHrVenda_Killfocus( System::Object* sender, wx::Event* e );
  	public:
      frmConVendas( wx::Window* parent );
  };
}
