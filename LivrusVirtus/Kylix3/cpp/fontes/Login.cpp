//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Login.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma resource "*.xfm"
TfrmLogin *frmLogin;
//---------------------------------------------------------------------------
__fastcall TfrmLogin::TfrmLogin(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmLogin::FormShow(TObject *Sender)
{
 bFecharOuTerminar=false;
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogin::FormClose(TObject *Sender, TCloseAction &Action)
{
if (bFecharOuTerminar)
  Action=caFree;
else
  Application->Terminate();
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogin::BtnLoginClick(TObject *Sender)
{
if (Rotinas->ConsultaDados(Consulta,
   ConsSQL->Usuario('S',edtLogin->Text.c_bstr(),edtSenha->Text.c_bstr()))) {
 Rotinas->sUsuarioLogin=edtLogin->Text;
 Rotinas->sUsuarioSenha=edtSenha->Text;
 frmPrincipal->StatusBar1->Panels->Items[0]->Text="Usuário: "+edtLogin->Text;
 bFecharOuTerminar=true;
 Close();
} else
 MessageDlg("Login ou senha incorretos!", mtInformation, TMsgDlgButtons() << mbOk, 0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmLogin::btnCancelarClick(TObject *Sender)
{
 bFecharOuTerminar=false;
 Close();
}
//---------------------------------------------------------------------------
