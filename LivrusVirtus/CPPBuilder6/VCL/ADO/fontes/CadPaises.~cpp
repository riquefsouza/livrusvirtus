//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CadPaises.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Cadastros"
#pragma resource "*.dfm"
TfrmCadPaises *frmCadPaises;
//---------------------------------------------------------------------------
__fastcall TfrmCadPaises::TfrmCadPaises(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadPaises::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"País não informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadPaises::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
//NovoDado(ConsSQL->Pais('N',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Pais('D',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Pais('S',edtCodigo->Text,""),
"País não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Pais('S',edtCodigo->Text,""),
ConsSQL->Pais('U',edtCodigo->Text,edtDescricao->Text),
ConsSQL->Pais('I',edtCodigo->Text,edtDescricao->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Paises1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

