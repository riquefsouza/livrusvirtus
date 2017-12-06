//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConIdiomas.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Consultas"
#pragma resource "*.dfm"
TfrmConIdiomas *frmConIdiomas;
//---------------------------------------------------------------------------
__fastcall TfrmConIdiomas::TfrmConIdiomas(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConIdiomas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Idiomas2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConIdiomas::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Idioma('S',"0",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConIdiomas::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Idioma('S',"", edtDescricao->Text),
"Idioma não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConIdiomas::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------

