//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadEditoras.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadEditoras *frmCadEditoras;
//---------------------------------------------------------------------------
__fastcall TfrmCadEditoras::TfrmCadEditoras(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadEditoras::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"C�digo n�o informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"Editora n�o informada!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadEditoras::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Editora('N',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEditoras::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Editora('D',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEditoras::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Editora('S',edtCodigo->Text.c_bstr(),""),
"Editora n�o encontrada!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEditoras::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Editora('S',edtCodigo->Text.c_bstr(),""),
ConsSQL->Editora('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),
ConsSQL->Editora('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEditoras::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Editoras1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

