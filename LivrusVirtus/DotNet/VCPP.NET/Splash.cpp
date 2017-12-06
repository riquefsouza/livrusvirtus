#include "StdAfx.h"
#include "Splash.h"

namespace Livrus
{

  frmSplash::frmSplash()
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
  Void frmSplash::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmSplash::InitializeComponent()
  {
  	this->components = new System::ComponentModel::Container();
  	System::Resources::ResourceManager* resources = new System::Resources::ResourceManager(__typeof(frmSplash));
	//System::Resources::ResourceManager* resources = new System::Resources::ResourceManager(GetType());
  	this->timer1 = new System::Windows::Forms::Timer(this->components);
  	// 
  	// timer1
  	// 
  	this->timer1->Enabled = true;
  	this->timer1->Interval = 3000;
  	this->timer1->Tick += new System::EventHandler(this,timer1_Tick);
  	// 
  	// frmSplash
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->BackgroundImage = dynamic_cast<System::Drawing::Image*>(resources->GetObject(S"$this.BackgroundImage"));
  	this->ClientSize = System::Drawing::Size(256, 69);
  	this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
  	this->Name = S"frmSplash";
  	this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
  	this->Text = S"Splash";
  	this->TransparencyKey = System::Drawing::Color::White;
  }
  
  Void frmSplash::timer1_Tick(Object* sender, System::EventArgs* e)
  {
  	Close();
  }

}
