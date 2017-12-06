//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadPaises.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadPaises *frmCadPaises;
//---------------------------------------------------------------------------
__fastcall TfrmCadPaises::TfrmCadPaises(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadPaises::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"País não informado!"))
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
ExcluirDados(ConsSQL->Pais('D',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Pais('S',edtCodigo->Text.c_bstr(),""),
"País não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Pais('S',edtCodigo->Text.c_bstr(),""),
ConsSQL->Pais('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),
ConsSQL->Pais('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadPaises::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Paises1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

