//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sobre.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
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
