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
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"Autor não informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadAutores::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Autor('N',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Autor('D',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Autor('S',edtCodigo->Text.c_bstr(),""),
"Autor não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Autor('S',edtCodigo->Text.c_bstr(),""),
ConsSQL->Autor('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),
ConsSQL->Autor('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAutores::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Autores1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

