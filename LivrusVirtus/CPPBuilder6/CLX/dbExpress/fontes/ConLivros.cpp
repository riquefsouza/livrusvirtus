//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ConLivros.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma link "Consultas"
#pragma resource "*.xfm"
TfrmConLivros *frmConLivros;
//---------------------------------------------------------------------------
__fastcall TfrmConLivros::TfrmConLivros(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConLivros::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Livros2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConLivros::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Livro('S',"0","","","","","","","","",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConLivros::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Livro('S',"", edtDescricao->Text,
"","","","","","","",""), "Livro não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConLivros::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------
