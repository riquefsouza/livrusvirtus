#pragma once

namespace Livrus
{
  public __gc class frmCadastros : public System::Windows::Forms::Form
  {
  private:
	System::ComponentModel::IContainer* components;
  protected:
	ArrayList* Registros;
  	ArrayList* Campos;
  	int nLinhaRegistro;
	System::Windows::Forms::Label* labCodigo;
  	System::Windows::Forms::TextBox* edtCodigo;
  	System::Windows::Forms::Label* labDescricao;
  	System::Windows::Forms::TextBox* edtDescricao;
  	System::Windows::Forms::Button* btnNovo;
  	System::Windows::Forms::Button* btnPesquisar;
  	System::Windows::Forms::Button* btnAnterior;
  	System::Windows::Forms::Button* btnProximo;
  	System::Windows::Forms::Button* btnFechar;
  	System::Windows::Forms::Button* btnLimpar;
  	System::Windows::Forms::Button* btnExcluir;
  	System::Windows::Forms::Button* btnSalvar;
  	System::Data::OleDb::OleDbCommand* Arquiva;
  
  public: 
	frmCadastros();
  protected: 
  	Void btnLimpar_Click(Object* sender, System::EventArgs* e);
	Void Dispose(Boolean disposing);
	Boolean ValidaDados(Boolean bTodosDados);
  	Void InformaLimpaDados(Boolean bInformar);
  	Void HabilitaDados(Boolean bHabilita);
	Void NovoDado(String* sTextoSql);
	Boolean ExcluirDados(String* sTextoSql);
	Boolean PesquisarDados(String* sTextoSql, String* sMensagemErro);
  	Boolean SalvarDados(String* sTextoSql,String* sTextoUpdate,
  	 		 String* sTextoInsert, Boolean bLimparDados);
  	Void edtCodigoLeave();
	Void btnNovo_Click(Object* sender, System::EventArgs* e);
        Void registroAnterior();
        Void registroProximo();
  private: 
	Void InitializeComponent();
  	Void btnFechar_Click(Object* sender, System::EventArgs* e);
 	Void frmCadastros_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e);
  	Void frmCadastros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e); 
  	Void btnAnterior_Click(Object* sender, System::EventArgs* e);
  	Void btnProximo_Click(Object* sender, System::EventArgs* e); 
  };
}
