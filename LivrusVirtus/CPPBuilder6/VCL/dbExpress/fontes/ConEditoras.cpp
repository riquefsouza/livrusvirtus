//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConEditoras.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Consultas"
#pragma resource "*.dfm"
TfrmConEditoras *frmConEditoras;
//---------------------------------------------------------------------------
__fastcall TfrmConEditoras::TfrmConEditoras(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEditoras::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Editoras2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEditoras::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Editora('S',"0",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEditoras::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Editora('S',"", edtDescricao->Text),
"Editora n�o encontrada!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEditoras::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------

