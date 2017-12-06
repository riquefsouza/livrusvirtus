#pragma once

namespace Livrus
{
  public __gc class frmSobre : public System::Windows::Forms::Form
  {
  public: 
  	static frmSobre* fSobre;
  private: 
  	System::ComponentModel::IContainer* components;
  	System::Windows::Forms::GroupBox* groupBox1;
  	System::Windows::Forms::Button* btnOk;
  	System::Windows::Forms::PictureBox* pictureBox1;
  	System::Windows::Forms::Label* label1;
  	System::Windows::Forms::Label* label2;
  	System::Windows::Forms::Label* label3;
  
  public: 
  	frmSobre(void);
  
  protected: 
  	Void Dispose (Boolean disposing);
  
  private: 
  	Void InitializeComponent();
  	Void frmSobre_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e);
  	Void frmSobre_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
  };
}
