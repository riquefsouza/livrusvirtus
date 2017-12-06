//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConPaises.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Consultas"
#pragma resource "*.dfm"
TfrmConPaises *frmConPaises;
//---------------------------------------------------------------------------
__fastcall TfrmConPaises::TfrmConPaises(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConPaises::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Paises2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConPaises::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Pais('S',"0",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConPaises::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Pais('S',"", edtDescricao->Text),
"País não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConPaises::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------
