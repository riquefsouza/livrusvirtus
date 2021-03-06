//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConVendas.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConClientes.h"
#include "ConLivros.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Consultas"
#pragma resource "*.dfm"
TfrmConVendas *frmConVendas;
//---------------------------------------------------------------------------
__fastcall TfrmConVendas::TfrmConVendas(TComponent* Owner)
        : TfrmConsultas(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConVendas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->VendasRealizadas1->Enabled=true;
TfrmConsultas::FormClose(Sender, Action);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConVendas::btnLimparClick(TObject *Sender)
{
  edtDtVenda->DateTime=Now();
  edtDtVenda->Checked=false;
  edtHrVenda->DateTime=Now();
  edtHrVenda->Checked=false;
  edtCliente->Clear();
  edtISBN->Clear();
  edtLivro->Clear();
  edtPrecoTotal->Text="R$ 0,00";
  edtDtVenda->SetFocus();

  LimparDados(ConsVenda('L'));
}
//---------------------------------------------------------------------------
AnsiString TfrmConVendas::ConsVenda(char sOpcao)
{
AnsiString sDataVenda, sHoraVenda, sDtHrVenda;

if (edtDtVenda->Checked)
   sDataVenda=FormatDateTime("mm/dd/yyyy",edtDtVenda->DateTime);
else
   sDataVenda="";
if (edtDtVenda->Checked)
   sHoraVenda=FormatDateTime("hh:nn:ss",edtHrVenda->DateTime);
else
   sHoraVenda="";
sDtHrVenda=sDataVenda.Trim()+" "+sHoraVenda.Trim();
if (sOpcao=='L')
 return ConsSQL->Venda('S',"ZERO","","","","");
else
 return ConsSQL->Venda(sOpcao,edtISBN->Text,edtDescricao->Text,
 sDtHrVenda.Trim(),"","");
}
//---------------------------------------------------------------------------
void __fastcall TfrmConVendas::btnPesquisarClick(TObject *Sender)
{
if (PesquisarDados(ConsVenda('S'),"Venda n�o encontrada!")) {
   Rotinas->ConsultaDados(ConsTotal,ConsVenda('P'));
   edtPrecoTotal->Text=
   FormatFloat("R$ 0.00",ConsTotal->Fields->Fields[0]->AsFloat);
}
}
//---------------------------------------------------------------------------
void __fastcall TfrmConVendas::FormShow(TObject *Sender)
{
btnLimparClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TfrmConVendas::edtDescricaoExit(TObject *Sender)
{
 if (edtDescricao->Text!="") {
   if (Rotinas->ValidaCPF(edtDescricao->Text)) {
      if (Rotinas->ConsultaDados(ConsCampo,
         ConsSQL->Cliente('S',edtDescricao->Text,"","","","","","","","","")))
         edtCliente->Text=ConsCampo->Fields->Fields[1]->AsString;
      else
        MessageDlg("Cliente n�o encontrado!", mtError,
        TMsgDlgButtons() << mbOK, 0);
   } else {
     edtDescricao->Clear();
     MessageDlg("CPF inv�lido!", mtError, TMsgDlgButtons() << mbOK, 0);
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmConVendas::edtISBNExit(TObject *Sender)
{
 if (edtISBN->Text!="") {
   if (Rotinas->ValidaISBN(edtISBN->Text)) {
      if (Rotinas->ConsultaDados(ConsCampo,ConsSQL->Livro('Q',edtISBN->Text,
         "","","","","","","","",""))) {
         if (ConsCampo->Fields->Fields[3]->AsInteger > 0) {
            edtLivro->Text=ConsCampo->Fields->Fields[1]->AsString;
            Rotinas->sPreco=ConsCampo->Fields->Fields[2]->AsString;
         } else
            MessageDlg("Livro n�o existe no estoque!", mtError,
            TMsgDlgButtons() << mbOK, 0);
      } else
        MessageDlg("Livro n�o encontrado!", mtError,
        TMsgDlgButtons() << mbOK, 0);
    } else {
      edtISBN->Clear();
      MessageDlg("ISBN inv�lido!", mtError, TMsgDlgButtons() << mbOK, 0);
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmConVendas::btnPClienteClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConClientes), &frmConClientes);
  frmConClientes->ShowModal();
  edtDescricao->Text=Rotinas->sCodigoSelecionado;
  edtDescricaoExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmConVendas::btnPLivroClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConLivros), &frmConLivros);
  frmConLivros->ShowModal();
  edtISBN->Text=Rotinas->sCodigoSelecionado;
  edtISBNExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmConVendas::edtDtVendaChange(TObject *Sender)
{
edtHrVenda->Checked=edtDtVenda->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TfrmConVendas::edtHrVendaChange(TObject *Sender)
{
edtDtVenda->Checked=edtHrVenda->Checked;
}
//---------------------------------------------------------------------------

