#include "StdAfx.h"
#include "Sobre.h"
#include "Principal.h" 

namespace Livrus
{
  
  frmSobre::frmSobre()
  {
  	//
  	// Required for Windows Form Designer support
  	//
  	InitializeComponent();
  
  	//
  	// TODO: Add any constructor code after InitializeComponent call
  	//
  }
  
  /// <summary>
  /// Clean up any resources being used.
  /// </summary>
  Void frmSobre::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmSobre::InitializeComponent()
  {
  	System::Resources::ResourceManager* resources = new System::Resources::ResourceManager(__typeof(frmSobre));
  	this->groupBox1 = new System::Windows::Forms::GroupBox();
  	this->label3 = new System::Windows::Forms::Label();
  	this->label2 = new System::Windows::Forms::Label();
  	this->label1 = new System::Windows::Forms::Label();
  	this->pictureBox1 = new System::Windows::Forms::PictureBox();
  	this->btnOk = new System::Windows::Forms::Button();
  	this->groupBox1->SuspendLayout();
  	this->SuspendLayout();
  	// 
  	// groupBox1
  	// 
  	this->groupBox1->BackColor = System::Drawing::Color::Transparent;
  	this->groupBox1->Controls->Add(this->label3);
  	this->groupBox1->Controls->Add(this->label2);
  	this->groupBox1->Controls->Add(this->label1);
  	this->groupBox1->Controls->Add(this->pictureBox1);
  	this->groupBox1->Location = System::Drawing::Point(8, 8);
  	this->groupBox1->Name = S"groupBox1";
  	this->groupBox1->Size = System::Drawing::Size(312, 176);
  	this->groupBox1->TabIndex = 0;
  	this->groupBox1->TabStop = false;
  	// 
  	// label3
  	// 
  	this->label3->Location = System::Drawing::Point(24, 128);
  	this->label3->Name = S"label3";
  	this->label3->Size = System::Drawing::Size(256, 40);
  	this->label3->TabIndex = 3;
  	this->label3->Text = S"Sistema integrante do projeto Livrus Virtus, versão programada em " \
  		S"Visual C++ for the Microsoft .NET Framework.";
  	this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
  	// 
  	// label2
  	// 
  	this->label2->Location = System::Drawing::Point(8, 112);
  	this->label2->Name = S"label2";
  	this->label2->Size = System::Drawing::Size(296, 16);
  	this->label2->TabIndex = 2;
  	this->label2->Text = S"Todos os direitos reservados para: Henrique F. de Souza";
  	this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
  	// 
  	// label1
  	// 
  	this->label1->Location = System::Drawing::Point(16, 96);
  	this->label1->Name = S"label1";
  	this->label1->Size = System::Drawing::Size(280, 16);
  	this->label1->TabIndex = 1;
  	this->label1->Text = S"Versão: 1.0.0";
  	this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
  	// 
  	// pictureBox1
  	// 
  	this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
  	this->pictureBox1->Image = dynamic_cast<System::Drawing::Image*>(resources->GetObject(S"pictureBox1.Image"));
  	this->pictureBox1->Location = System::Drawing::Point(24, 16);
  	this->pictureBox1->Name = S"pictureBox1";
  	this->pictureBox1->Size = System::Drawing::Size(264, 72);
  	this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
  	this->pictureBox1->TabIndex = 0;
  	this->pictureBox1->TabStop = false;
  	// 
  	// btnOk
  	// 
  	this->btnOk->DialogResult = System::Windows::Forms::DialogResult::OK;
  	this->btnOk->Location = System::Drawing::Point(128, 192);
  	this->btnOk->Name = S"btnOk";
  	this->btnOk->TabIndex = 1;
  	this->btnOk->Text = S"OK";
  	// 
  	// frmSobre
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->ClientSize = System::Drawing::Size(328, 221);
  	this->Controls->Add(this->btnOk);
  	this->Controls->Add(this->groupBox1);
  	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
  	this->MaximizeBox = false;
  	this->MinimizeBox = false;
  	this->Name = S"frmSobre";
  	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
  	this->Text = S"Sobre o Sistema";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmSobre_Closing);
  	this->MouseMove += new System::Windows::Forms::MouseEventHandler(this,frmSobre_MouseMove);
  	this->groupBox1->ResumeLayout(false);
  	this->ResumeLayout(false);
  }
  
  Void frmSobre::frmSobre_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e)
  {
  	  frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=Text;
  }
  
  Void frmSobre::frmSobre_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text="";
  }

}
