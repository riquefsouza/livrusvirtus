//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadAutores.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadAutores *frmCadAutores;
//---------------------------------------------------------------------------
__fastcall TfrmCadAutores::TfrmCadAutores(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadAutores::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Autor não informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadAutores::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Autor('N',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Autor('D',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Autor('S',edtCodigo->Text,""),
"Autor não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Autor('S',edtCodigo->Text,""),
ConsSQL->Autor('U',edtCodigo->Text,edtDescricao->Text),
ConsSQL->Autor('I',edtCodigo->Text,edtDescricao->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Autores1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

