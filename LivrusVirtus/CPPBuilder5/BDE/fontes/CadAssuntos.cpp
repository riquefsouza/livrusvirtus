//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CadAssuntos.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Cadastros"
#pragma resource "*.dfm"
TfrmCadAssuntos *frmCadAssuntos;
//---------------------------------------------------------------------------
__fastcall TfrmCadAssuntos::TfrmCadAssuntos(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadAssuntos::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"C�digo n�o informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Assunto n�o informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadAssuntos::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Assunto('N',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Assunto('D',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Assunto('S',edtCodigo->Text,""),
"Assunto n�o encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Assunto('S',edtCodigo->Text,""),
ConsSQL->Assunto('U',edtCodigo->Text,edtDescricao->Text),
ConsSQL->Assunto('I',edtCodigo->Text,edtDescricao->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Assuntos1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------


