//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadIdiomas.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadIdiomas *frmCadIdiomas;
//---------------------------------------------------------------------------
__fastcall TfrmCadIdiomas::TfrmCadIdiomas(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadIdiomas::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"Idioma não informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadIdiomas::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Idioma('N',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Idioma('D',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Idioma('S',edtCodigo->Text.c_bstr(),""),
"Idioma não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Idioma('S',edtCodigo->Text.c_bstr(),""),
ConsSQL->Idioma('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),
ConsSQL->Idioma('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Idiomas1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

