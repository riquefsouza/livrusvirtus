#pragma once

namespace Livrus
{
  public __gc class frmConsultas : public System::Windows::Forms::Form
  {
    private: 
          System::ComponentModel::IContainer* components;
    protected:
	  ArrayList* Registros;
	  ArrayList* Campos;
          System::Windows::Forms::Panel* panel1;
          System::Windows::Forms::Label* labDescricao;    
          System::Windows::Forms::Panel* panel2;    
          System::Windows::Forms::Button* btnFechar;
          System::Windows::Forms::Label* labRegistros;
          System::Windows::Forms::Button* btnPesquisar;
          System::Windows::Forms::TextBox* edtDescricao;
          System::Windows::Forms::DataGrid* gridConsulta;
          System::Windows::Forms::Button* btnLimpar;
          System::Data::DataSet* dsConsulta;   
    public: 
          frmConsultas();
    protected: 
          Void Dispose (Boolean disposing);
          Void LimparDados(String* sTextoSql);
          Boolean PesquisarDados(String* sTextoSql, String* sMensagemErro);
    private:
          Void InitializeComponent();
          Void btnFechar_Click(Object* sender, System::EventArgs* e);
          Void frmConsultas_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
          Void gridConsulta_CurrentCellChanged(Object* sender, System::EventArgs* e);
          Void gridConsulta_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e);
  };
}
