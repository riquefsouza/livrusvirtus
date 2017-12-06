#pragma once

namespace Livrus
{
  /// <summary>
  /// Summary description for Class.
  /// </summary>
  public __gc class frmSplash : public System::Windows::Forms::Form
  {
  public:
	static frmSplash* fSplash;
  	/// <summary>
  	/// Required designer variable.
  	/// </summary>
  private:
	System::ComponentModel::IContainer* components;
  	System::Windows::Forms::Timer* timer1;
  public:
  	frmSplash();
  
  	/// <summary>
  	/// Clean up any resources being used.
  	/// </summary>
  protected: 
 	Void Dispose (Boolean disposing);
  
  private: 
	Void InitializeComponent();	
  	Void timer1_Tick(Object* sender, System::EventArgs* e);
  };
}
