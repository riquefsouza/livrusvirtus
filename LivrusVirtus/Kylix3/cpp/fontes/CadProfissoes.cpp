//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadProfissoes.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadProfissoes *frmCadProfissoes;
//---------------------------------------------------------------------------
__fastcall TfrmCadProfissoes::TfrmCadProfissoes(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadProfissoes::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"Profissão não informada!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadProfissoes::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Profissao('N',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Profissao('D',edtCodigo->Text.c_bstr(),""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Profissao('S',edtCodigo->Text.c_bstr(),""),
"Profissão não encontrada!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Profissao('S',edtCodigo->Text.c_bstr(),""),
ConsSQL->Profissao('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),
ConsSQL->Profissao('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr()),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Profissoes1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

