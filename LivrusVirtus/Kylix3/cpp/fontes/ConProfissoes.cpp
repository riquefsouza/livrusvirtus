//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ConProfissoes.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma link "Consultas"
#pragma resource "*.xfm"
TfrmConProfissoes *frmConProfissoes;
//---------------------------------------------------------------------------
__fastcall TfrmConProfissoes::TfrmConProfissoes(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConProfissoes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Profissoes2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConProfissoes::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Profissao('S',"0",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConProfissoes::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Profissao('S',"", edtDescricao->Text.c_bstr()),
"Profissão não encontrada!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConProfissoes::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------

