//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Sobre.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma resource "*.xfm"
TfrmSobre *frmSobre;
//---------------------------------------------------------------------------
__fastcall TfrmSobre::TfrmSobre(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSobre::FormActivate(TObject *Sender)
{
frmPrincipal->StatusBar1->Panels->Items[1]->Text=Caption;
}
//---------------------------------------------------------------------------
