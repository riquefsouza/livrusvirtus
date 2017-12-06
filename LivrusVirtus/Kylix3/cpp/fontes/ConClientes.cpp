//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "ConClientes.h"
#include "ConsultasSQL.h"
#include "Principal.h"
//---------------------------------------------------------------------------
#pragma link "Consultas"
#pragma resource "*.xfm"
TfrmConClientes *frmConClientes;
//---------------------------------------------------------------------------
__fastcall TfrmConClientes::TfrmConClientes(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConClientes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->Clientes2->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConClientes::btnLimparClick(TObject *Sender)
{
LimparDados(ConsSQL->Cliente('S',"0","","","","","","","","",""));
}
//---------------------------------------------------------------------------
void __fastcall TfrmConClientes::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Cliente('S',"", edtDescricao->Text.c_bstr(),
"","","","","","","",""),"Cliente não encontrado!");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConClientes::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------
