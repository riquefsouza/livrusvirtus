//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CadIdiomas.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Cadastros"
#pragma resource "*.dfm"
TfrmCadIdiomas *frmCadIdiomas;
//---------------------------------------------------------------------------
__fastcall TfrmCadIdiomas::TfrmCadIdiomas(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadIdiomas::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Idioma não informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadIdiomas::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Idioma('N',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Idioma('D',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Idioma('S',edtCodigo->Text,""),
"Idioma não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Idioma('S',edtCodigo->Text,""),
ConsSQL->Idioma('U',edtCodigo->Text,edtDescricao->Text),
ConsSQL->Idioma('I',edtCodigo->Text,edtDescricao->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadIdiomas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Idiomas1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

