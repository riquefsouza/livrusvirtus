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
if (Rotinas->ValidaCampo(edtCodigo->Text,"Código não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Profissão não informada!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadProfissoes::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Profissao('N',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Profissao('D',edtCodigo->Text,""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Profissao('S',edtCodigo->Text,""),
"Profissão não encontrada!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Profissao('S',edtCodigo->Text,""),
ConsSQL->Profissao('U',edtCodigo->Text,edtDescricao->Text),
ConsSQL->Profissao('I',edtCodigo->Text,edtDescricao->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadProfissoes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Profissoes1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

