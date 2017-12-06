//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ConAssuntos.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma link "Consultas"
#pragma resource "*.xfm"
TfrmConAssuntos *frmConAssuntos;
//---------------------------------------------------------------------------
__fastcall TfrmConAssuntos::TfrmConAssuntos(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAssuntos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Assuntos2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAssuntos::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Assunto('S',"0",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAssuntos::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Assunto('S',"", edtDescricao->Text),
"Assunto não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConAssuntos::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------

