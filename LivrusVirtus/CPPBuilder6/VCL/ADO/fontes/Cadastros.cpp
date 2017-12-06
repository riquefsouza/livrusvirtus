//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Cadastros.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCadastros *frmCadastros;
//---------------------------------------------------------------------------
__fastcall TfrmCadastros::TfrmCadastros(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadastros::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadastros::btnFecharClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
Boolean TfrmCadastros::ValidaDados(Boolean bTodosDados)
{
return true;
}
//---------------------------------------------------------------------------
void TfrmCadastros::InformaLimpaDados(Boolean bInformar)
{
if (bInformar) {
  edtCodigo->Text=Consulta->Fields->Fields[0]->AsString;
  edtDescricao->Text=Consulta->Fields->Fields[1]->AsString;
} else {
  edtCodigo->Clear();
  edtDescricao->Clear();
  edtCodigo->Enabled=True;
  edtCodigo->SetFocus();
}
}
//---------------------------------------------------------------------------
void TfrmCadastros::HabilitaDados(Boolean bHabilita)
{
edtDescricao->Enabled=bHabilita;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadastros::btnNovoClick(TObject *Sender)
{
btnSalvar->Enabled=true;
btnExcluir->Enabled=false;
btnPesquisar->Enabled=false;
btnAnterior->Enabled=false;
btnProximo->Enabled=false;
btnNovo->Enabled=false;

InformaLimpaDados(false);
HabilitaDados(true);
}
//---------------------------------------------------------------------------

void TfrmCadastros::NovoDado(AnsiString sTextoSql)
{
 if (Rotinas->ConsultaDados(Consulta, sTextoSql)) {
    edtCodigo->Text = Consulta->Fields->Fields[0]->AsString;
    edtCodigo->Enabled = false;
    edtDescricao->SetFocus();
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadastros::btnLimparClick(TObject *Sender)
{
btnSalvar->Enabled=false;
btnExcluir->Enabled=false;
btnPesquisar->Enabled=true;
btnAnterior->Enabled=false;
btnProximo->Enabled=false;
btnNovo->Enabled=true;

InformaLimpaDados(false);
HabilitaDados(false);
}
//---------------------------------------------------------------------------
void TfrmCadastros::ExcluirDados(AnsiString sTextoSql)
{
if (ValidaDados(false)) {
 if (MessageDlg("Certeza de excluir?", mtConfirmation,
     TMsgDlgButtons() << mbYes << mbNo, 0)==mrYes) {
    Arquiva->Close();
    Arquiva->SQL->Text=sTextoSql;
    Arquiva->ExecSQL();
    btnLimparClick(this);
 }
}
}
//---------------------------------------------------------------------------

void TfrmCadastros::PesquisarDados(AnsiString sTextoSql,
AnsiString sMensagemErro)
{
if (edtCodigo->Text=="") {
  btnAnterior->Enabled=true;
  btnProximo->Enabled=true;
}

if (Rotinas->ConsultaDados(Consulta,sTextoSql)) {
 InformaLimpaDados(true);
 HabilitaDados(true);

 btnSalvar->Enabled=true;
 btnExcluir->Enabled=true;
 btnPesquisar->Enabled=false;
} else
 MessageDlg(sMensagemErro, mtInformation, TMsgDlgButtons() << mbOK, 0);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadastros::btnAnteriorClick(TObject *Sender)
{
Consulta->Prior();
InformaLimpaDados(true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadastros::btnProximoClick(TObject *Sender)
{
Consulta->Next();
InformaLimpaDados(true);
}
//---------------------------------------------------------------------------

void TfrmCadastros::SalvarDados(AnsiString sTextoSql,AnsiString sTextoUpdate,
AnsiString sTextoInsert, Boolean bLimparDados)
{
if (ValidaDados(true)) {
   if (Rotinas->ConsultaDados(Arquiva,sTextoSql)) {
     Arquiva->Close();
     Arquiva->SQL->Text=sTextoUpdate;
   } else {
     Arquiva->Close();
     Arquiva->SQL->Text=sTextoInsert;
   }
   Arquiva->ExecSQL();
   if (bLimparDados)
      btnLimparClick(this);
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadastros::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  frmPrincipal->StatusBar1->Panels->Items[1]->Text=Caption;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadastros::edtCodigoExit(TObject *Sender)
{
if (edtCodigo->Text!="") {
  if (Rotinas->ValidaInteger(edtCodigo->Text)==false) {
    edtCodigo->Clear();
    edtCodigo->SetFocus();
  }
 }
}
//---------------------------------------------------------------------------
