//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "AlterarSenha.h"
#include "Principal.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma resource "*.xfm"
TfrmAlterarSenha *frmAlterarSenha;
//---------------------------------------------------------------------------
__fastcall TfrmAlterarSenha::TfrmAlterarSenha(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlterarSenha::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->AlterarSenha1->Enabled=true;
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlterarSenha::btnFecharClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlterarSenha::btnLimparClick(TObject *Sender)
{
edtNovaSenha->Clear();
edtConfirmarSenha->Clear();
edtSenhaAtual->SetFocus();
}
//---------------------------------------------------------------------------
Boolean TfrmAlterarSenha::ValidaDados()
{
if (Trim(edtSenhaAtual->Text) != Trim(Rotinas->sUsuarioSenha)) {
 MessageDlg("A Senha atual n�o confere com a senha do usu�rio!", mtError,
 TMsgDlgButtons() << mbOk, 0);
 return false;
}
if (Rotinas->ValidaCampo(edtNovaSenha->Text.c_bstr(),"Nova senha n�o informada!")) {
 return false;
}
if (Trim(edtNovaSenha->Text) != Trim(edtConfirmarSenha->Text)) {
 MessageDlg("A Nova senha n�o confere com a senha a confirmar!", mtError,
 TMsgDlgButtons() << mbOk, 0);
 return false;
}

return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlterarSenha::btnSalvarClick(TObject *Sender)
{
if (ValidaDados()) {
  Arquiva->SQL->Text=ConsSQL->Usuario('U',Rotinas->sUsuarioLogin,
  edtConfirmarSenha->Text.c_bstr());
  Arquiva->ExecSQL();
  Rotinas->sUsuarioSenha=edtNovaSenha->Text;
  MessageDlg("Senha alterada com sucesso!", mtInformation,
  TMsgDlgButtons() << mbOk, 0);
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlterarSenha::FormShow(TObject *Sender)
{
edtLogin->Text=Rotinas->sUsuarioLogin;
}
//---------------------------------------------------------------------------
void __fastcall TfrmAlterarSenha::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  frmPrincipal->StatusBar1->Panels->Items[1]->Text=Caption;
}
//---------------------------------------------------------------------------