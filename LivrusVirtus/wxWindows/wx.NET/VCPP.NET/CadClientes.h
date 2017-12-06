#pragma once

#include "Cadastros.h"

namespace Livrus
{
	public __gc class frmCadClientes : public frmCadastros
	{
    private:
     __value enum idx {
       ID_FRMCADCLIENTES_BTNPENDERECO = 800, ID_FRMCADCLIENTES_SBENDERECO,
       ID_FRMCADCLIENTES_BTNPPAIS, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
       ID_FRMCADCLIENTES_EDTBAIRRO, ID_FRMCADCLIENTES_EDTCEP, 
       ID_FRMCADCLIENTES_EDTCIDADE, ID_FRMCADCLIENTES_EDTCODENDERECO, 
       ID_FRMCADCLIENTES_EDTCODPAIS, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
       ID_FRMCADCLIENTES_EDTDTNASC, ID_FRMCADCLIENTES_EDTEMAIL, 
       ID_FRMCADCLIENTES_EDTESTADO, ID_FRMCADCLIENTES_EDTIDENTIDADE, 
       ID_FRMCADCLIENTES_EDTLOGRADOURO, ID_FRMCADCLIENTES_EDTPAIS, 
       ID_FRMCADCLIENTES_EDTPROFISSAO, ID_FRMCADCLIENTES_EDTTELEFONE, 
       ID_FRMCADCLIENTES_LABBAIRRO, ID_FRMCADCLIENTES_LABCEP, 
       ID_FRMCADCLIENTES_LABCIDADE, ID_FRMCADCLIENTES_LABDTNASC, 
       ID_FRMCADCLIENTES_LABEMAIL, ID_FRMCADCLIENTES_LABESTADO, 
       ID_FRMCADCLIENTES_LABIDENTIDADE, ID_FRMCADCLIENTES_LABLOGRADOURO, 
       ID_FRMCADCLIENTES_LABPAIS, ID_FRMCADCLIENTES_LABPROFISSAO, 
       ID_FRMCADCLIENTES_LABTELEFONE, ID_FRMCADCLIENTES_RBSEXO };

      wx::StaticText* labEmail;
      wx::TextCtrl* edtEmail;
      wx::StaticText* labIdentidade;
      wx::TextCtrl* edtIdentidade;
      wx::RadioBox* rbSexo;
      wx::StaticText* labTelefone;
      wx::TextCtrl* edtTelefone;
      wx::StaticText* labDtNasc;
      wx::TextCtrl* edtDtNasc;
      wx::StaticBox* sbEndereco;
      TextValidatorCtrl* edtCodEndereco;
      wx::Button* btnPEndereco;
      wx::StaticText* labLogradouro;
      wx::TextCtrl* edtLogradouro;
      wx::StaticText* labBairro;
      wx::TextCtrl* edtBairro;
      wx::StaticText* labCEP;
      wx::TextCtrl* edtCEP;
      wx::StaticText* labCidade;
      wx::TextCtrl* edtCidade;
      wx::StaticText* labEstado;
      wx::TextCtrl* edtEstado;
      wx::StaticText* labPais;
      TextValidatorCtrl* edtCodPais;
      wx::TextCtrl* edtPais;
      wx::Button* btnPPais;
      wx::StaticText* labProfissao;
      TextValidatorCtrl* edtCodProfissao;
      wx::TextCtrl* edtProfissao;
      wx::Button* btnPProfissao;

      Void FazLayout();
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
      Void InformaLimpaDados(Boolean bInformar);
      Void HabilitaDados(Boolean bHabilita);
      Void OnEdtCodigo_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtDtNasc_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtCodEndereco_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtCodPais_Killfocus( System::Object* sender, wx::Event* e );
      Void OnEdtCodProfissao_Killfocus( System::Object* sender, wx::Event* e );
      Void OnBtnPEndereco( System::Object* sender, wx::Event* e );
      Void OnBtnPPais( System::Object* sender, wx::Event* e );
      Void OnBtnPProfissao( System::Object* sender, wx::Event* e );
  	public:
      frmCadClientes( wx::Window* parent );
  };
}
