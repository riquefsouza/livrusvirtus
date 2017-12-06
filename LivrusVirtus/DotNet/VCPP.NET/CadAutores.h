#pragma once

namespace Livrus
{
  public __gc class frmCadAutores : public Livrus::frmCadastros
  {
  public:
	static frmCadAutores* fCadAutores;
	frmCadAutores();
  private: 
	System::ComponentModel::IContainer* components;
  	Void InitializeComponent();
  	Void btnNovo_Click(Object* sender, System::EventArgs* e);
  	Void btnExcluir_Click(Object* sender, System::EventArgs* e);
  	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
  	Void btnSalvar_Click(Object* sender, System::EventArgs* e);
        Void edtCodigo_Leave(Object* sender, System::EventArgs* e);
  	Void frmCadAutores_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  	Boolean ValidaDados(Boolean bTodosDados);
  };

}
