//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Splash.h"
//---------------------------------------------------------------------------
#pragma resource "*.xfm"
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
