//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ConEnderecos.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma link "Consultas"
#pragma resource "*.xfm"
TfrmConEnderecos *frmConEnderecos;
//---------------------------------------------------------------------------
__fastcall TfrmConEnderecos::TfrmConEnderecos(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEnderecos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Enderecos2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEnderecos::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Endereco('S',"0","","","","",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEnderecos::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Endereco('S',"", edtDescricao->Text.c_bstr(),"","","",""),
"Endereço não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConEnderecos::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------
