#include "stdafx.h"
#include "Principal.h"

using namespace Livrus;

void __stdcall WinMain()
{
	System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;

//	Application::Run(new frmPrincipal());


//	if (frmPrincipal::fPrincipal==null) {
		frmPrincipal::fPrincipal = new frmPrincipal();

		frmPrincipal::fPrincipal->db = new OleDbConnection();		
		frmPrincipal::fPrincipal->db->ConnectionString = 
                S"File Name=c:\\livrusvirtus\\bancos\\access\\access2k_livrus.udl";

		Application::Run(frmPrincipal::fPrincipal);
//	} else
//	  MessageBox::Show(this,S"a aplicação já está sendo executada.",
//	  S"livrus virtus", MessageBoxButtons::Ok);

}