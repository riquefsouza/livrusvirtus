#pragma once

#include "Cadastros.h"

namespace Livrus
{
	public __gc class frmCadLivros : public frmCadastros
	{
    private:
      __value enum idx { 
       ID_FRMCADLIVROS_BTNADASSUNTOS = 900, ID_FRMCADLIVROS_BTNADAUTORES, 
       ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_BTNPAUTOR, 
       ID_FRMCADLIVROS_BTNPEDITORA, ID_FRMCADLIVROS_CMBIDIOMA, 
       ID_FRMCADLIVROS_EDTANOPUBLI, ID_FRMCADLIVROS_EDTASSUNTO, 
       ID_FRMCADLIVROS_EDTAUTOR, ID_FRMCADLIVROS_EDTCODASSUNTO, 
       ID_FRMCADLIVROS_EDTCODAUTOR, ID_FRMCADLIVROS_EDTCODEDITORA, 
       ID_FRMCADLIVROS_EDTEDICAO, ID_FRMCADLIVROS_EDTEDITORA, 
       ID_FRMCADLIVROS_EDTNPAGINAS, ID_FRMCADLIVROS_EDTPRECO, 
       ID_FRMCADLIVROS_EDTQTDESTOQUE, ID_FRMCADLIVROS_EDTVOLUME, 
       ID_FRMCADLIVROS_LABANOPUBLI, ID_FRMCADLIVROS_LABASSUNTO, 
       ID_FRMCADLIVROS_LABAUTOR, ID_FRMCADLIVROS_LABEDICAO, 
       ID_FRMCADLIVROS_LABEDITORA, ID_FRMCADLIVROS_LABIDIOMA, 
       ID_FRMCADLIVROS_LABNPAGINAS, ID_FRMCADLIVROS_LABPRECO, 
       ID_FRMCADLIVROS_LABQTDESTOQUE, ID_FRMCADLIVROS_LABVOLUME, 
       ID_FRMCADLIVROS_LSTASSUNTOS, ID_FRMCADLIVROS_LSTAUTORES };

      ArrayList *slAssuntos, *slAutores, *slIdiomas;
      wx::StaticText *labEdicao;
      wx::SpinCtrl *edtEdicao;
      wx::StaticText *labAnoPubli;
      wx::SpinCtrl *edtAnoPubli;
      wx::StaticText *labEditora;
      wx::TextCtrl *edtCodEditora;
      wx::TextCtrl *edtEditora;
      wx::Button *btnPEditora;
      wx::StaticText *labVolume;
      wx::SpinCtrl *edtVolume;
      wx::StaticText *labIdioma;
      wx::Choice *cmbIdioma;
      wx::StaticText *labNPaginas;
      wx::SpinCtrl *edtNPaginas;
      wx::StaticText *labAssunto;
      wx::TextCtrl *edtCodAssunto;
      wx::TextCtrl *edtAssunto;
      wx::Button *btnAdAssuntos;
      wx::Button *btnPAssunto;
      wx::ListBox *lstAssuntos;
      wx::StaticText *labPreco;
      wx::TextCtrl *edtPreco;
      wx::StaticText *labQtdEstoque;
      wx::SpinCtrl *edtQtdEstoque;
      wx::StaticText *labAutor;
      wx::TextCtrl *edtCodAutor;
      wx::TextCtrl *edtAutor;
      wx::Button *btnAdAutores;
      wx::Button *btnPAutor;
      wx::ListBox *lstAutores;
      String* vsIdiomas __gc[];
    	Boolean ValidaDados(Boolean bTodosDados);
      Void OnClose( System::Object* sender, wx::Event* e );
      Void OnBtnNovo( System::Object* sender, wx::Event* e );
      Void OnBtnPesquisar( System::Object* sender, wx::Event* e );
      Void OnBtnAnterior( System::Object* sender, wx::Event* e );
      Void OnBtnProximo( System::Object* sender, wx::Event* e );
      Void OnBtnSalvar( System::Object* sender, wx::Event* e );
      Void OnBtnExcluir( System::Object* sender, wx::Event* e );
      Void OnBtnLimpar( System::Object* sender, wx::Event* e );
      Void OnBtnFechar( System::Object* sender, wx::Event* e );
      Void OnEdtCodigo_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtCodEditora_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtCodAssunto_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtCodAutor_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPEditora( System::Object* sender, wx::Event* e );
      Void OnEdtPreco_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPAssunto( System::Object* sender, wx::Event* e );
      Void OnBtnAdAssuntos( System::Object* sender, wx::Event* e );
      Void OnBtnPAutor( System::Object* sender, wx::Event* e );
      Void OnBtnAdAutores( System::Object* sender, wx::Event* e );
      Void OnLstAssuntos_Dblclk( System::Object* sender, wx::Event* e );
      Void OnLstAutores_Dblclk( System::Object* sender, wx::Event* e );
      Void FazLayout();
      Void InformaLimpaDados(Boolean bInformar);
      Void HabilitaDados(Boolean bHabilita);
      Void AdicionaCombo();
      Void SalvaLista(char sOpcao);
  	public:
      frmCadLivros( wx::Window* parent );
  };
}
