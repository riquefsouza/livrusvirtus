//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadAssuntos.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadAssuntos *frmCadAssuntos;
//---------------------------------------------------------------------------
__fastcall TfrmCadAssuntos::TfrmCadAssuntos(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadAssuntos::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"C�digo n�o informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"Assunto n�o informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadAssuntos::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Assunto('N',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Assunto('D',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Assunto('S',edtCodigo->Text.c_bstr(),""),
"Assunto n�o encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Assunto('S',edtCodigo->Text.c_bstr(),""),
ConsSQL->Assunto('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),
ConsSQL->Assunto('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadAssuntos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Assuntos1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------


