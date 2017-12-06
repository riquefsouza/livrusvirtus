//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ConAutores.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma link "Consultas"
#pragma resource "*.xfm"
TfrmConAutores *frmConAutores;
//---------------------------------------------------------------------------
__fastcall TfrmConAutores::TfrmConAutores(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAutores::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Autores2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAutores::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Autor('S',"0",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAutores::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Autor('S',"", edtDescricao->Text),
"Autor não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAutores::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------

