//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Splash.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmSplash *frmSplash;
//---------------------------------------------------------------------------
__fastcall TfrmSplash::TfrmSplash(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSplash::FormClose(TObject *Sender, TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmSplash::Timer1Timer(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
