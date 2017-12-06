//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "VenderLivros.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConClientes.h"
#include "ConLivros.h"
//---------------------------------------------------------------------------
#pragma resource "*.xfm"
TfrmVenderLivros *frmVenderLivros;
//---------------------------------------------------------------------------
__fastcall TfrmVenderLivros::TfrmVenderLivros(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmVenderLivros::FormClose(TObject *Sender,
      TCloseAction &Action)
{
slLivros->Free();
slPrecos->Free();
slQtdEstoque->Free();

frmPrincipal->ToolButton3->Enabled=true;
frmPrincipal->VenderLivros1->Enabled=true;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::btnFecharClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  frmPrincipal->StatusBar1->Panels->Items[1]->Text=Caption;
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::FormShow(TObject *Sender)
{
nPrecoTotal=0;
edtDtVenda->Text=FormatDateTime("dd/mm/yyyy hh:nn:ss",Now());
slLivros= new TStringList();
slPrecos= new TStringList();
slQtdEstoque= new TStringList();
}
//---------------------------------------------------------------------------

void TfrmVenderLivros::LimpaDados()
{
  edtDtVenda->Text=FormatDateTime("dd/mm/yyyy hh:nn:ss",Now());
  edtCPF->Clear();
  edtCliente->Clear();
  edtISBN->Clear();
  edtLivro->Clear();
  lstLivros->Clear();
  slLivros->Clear();
  slPrecos->Clear();
  nPrecoTotal=0;
  edtPrecoTotal->Text="R$ 0,00";
  edtCPF->SetFocus();
}
//---------------------------------------------------------------------------

Boolean TfrmVenderLivros::ValidaDados()
{
if (Rotinas->ValidaCampo(edtCPF->Text.c_bstr(),"CPF não informado!")) {
  return false;
}
if (lstLivros->Items->Count == 0) {
  MessageDlg("Livro(s) para vender não informado(s)!", mtInformation,
  TMsgDlgButtons() << mbOk, 0);
  return false;
}
return true;
}
//---------------------------------------------------------------------------

Boolean TfrmVenderLivros::SalvaLista()
{
int nCont, nQtdEstoque;
try {
 for (nCont=0; nCont <= slLivros->Count-1; nCont++) {
    Arquiva->SQL->Text=ConsSQL->Venda('I',slLivros->Strings[nCont],edtCPF->Text.c_bstr(),
    FormatDateTime("mm/dd/yyyy hh:nn:ss",StrToDateTime(edtDtVenda->Text.c_bstr())),
    Rotinas->VirgulaParaPonto(FormatFloat("0.00",nPrecoTotal)),"");
    Arquiva->ExecSQL();

    nQtdEstoque=StrToInt(slQtdEstoque->Strings[nCont]);
    nQtdEstoque=nQtdEstoque-1;
    Arquiva->SQL->Text=ConsSQL->Venda('U',slLivros->Strings[nCont],"","","",
    IntToStr(nQtdEstoque));
    Arquiva->ExecSQL();
 }
 return true;
} catch (Exception &E) {
  MessageDlg(E.Message, mtError, TMsgDlgButtons() << mbOk, 0);
  return false;
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::edtISBNExit(TObject *Sender)
{
 if (edtISBN->Text!="") {
   if (Rotinas->ValidaISBN(edtISBN->Text.c_bstr())) {
      if (Rotinas->ConsultaDados(Consulta, ConsSQL->Livro('Q',edtISBN->Text.c_bstr(),
         "","","","","","","","",""))) {
         if (Consulta->Fields->Fields[3]->AsInteger > 0) {
            edtLivro->Text=Consulta->Fields->Fields[1]->AsString;
            Rotinas->sPreco=Consulta->Fields->Fields[2]->AsString;
         } else {
            edtISBN->Clear();
            MessageDlg("O livro não existe no estoque!", mtError,
            TMsgDlgButtons() << mbOk, 0);
         }
      } else
        MessageDlg("Livro não encontrado!", mtError,
        TMsgDlgButtons() << mbOk, 0);
   } else {
      edtISBN->Clear();
      MessageDlg("ISBN inválido!", mtError,
      TMsgDlgButtons() << mbOk, 0);
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::edtCPFExit(TObject *Sender)
{
 if (edtCPF->Text!="") {
   if (Rotinas->ValidaCPF(edtCPF->Text.c_bstr())) {
      if (Rotinas->ConsultaDados(Consulta, ConsSQL->Cliente('S',edtCPF->Text.c_bstr(),
         "","","","","","","","","")))
         edtCliente->Text=Consulta->Fields->Fields[1]->AsString;
      else
        MessageDlg("Cliente não encontrado!", mtError,
        TMsgDlgButtons() << mbOk, 0);
   } else {
     edtCPF->Clear();
     MessageDlg("CPF inválido!", mtError, TMsgDlgButtons() << mbOk, 0);
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::btnPClienteClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConClientes), &frmConClientes);
  frmConClientes->ShowModal();
  edtCPF->Text=Rotinas->sCodigoSelecionado;
  edtCPFExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::btnPLivroClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConLivros), &frmConLivros);
  frmConLivros->ShowModal();
  edtISBN->Text=Rotinas->sCodigoSelecionado;
  edtISBNExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::btnAdLivrosClick(TObject *Sender)
{
AnsiString sLivros;

if (edtISBN->Text!="") {
 sLivros=edtISBN->Text+" - "+edtLivro->Text+" - R$ "+Rotinas->sPreco;
 if (lstLivros->Items->IndexOf(sLivros)==-1)
  {
    slLivros->Append(edtISBN->Text.c_bstr());
    slPrecos->Append(Rotinas->sPreco);
    slQtdEstoque->Append(Rotinas->sQtdEstoque);
    lstLivros->Items->Append(sLivros);
    nPrecoTotal=nPrecoTotal+StrToFloat(Rotinas->sPreco);
  }
 edtISBN->Clear();
 edtLivro->Clear();
 edtPrecoTotal->Text=FormatFloat("R$ 0.00",nPrecoTotal);
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::lstLivrosDblClick(TObject *Sender)
{
float nPreco;

 if (lstLivros->Items->Count > 0) {
   nPreco=StrToFloat(slPrecos->Strings[lstLivros->ItemIndex]);
   nPrecoTotal=nPrecoTotal-nPreco;
   edtPrecoTotal->Text="R$ "+FloatToStr(nPrecoTotal);
   slLivros->Delete(lstLivros->ItemIndex);
   slPrecos->Delete(lstLivros->ItemIndex);
   slQtdEstoque->Delete(lstLivros->ItemIndex);
   lstLivros->Items->Delete(lstLivros->ItemIndex);
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::btnLimparClick(TObject *Sender)
{
LimpaDados();
}
//---------------------------------------------------------------------------

void __fastcall TfrmVenderLivros::btnVenderClick(TObject *Sender)
{
 if (ValidaDados()) {
    if (SalvaLista()) {
       MessageDlg("Venda realizada com sucesso!", 
       mtInformation, TMsgDlgButtons() << mbOk, 0);
       LimpaDados();
    }
 }
}
//---------------------------------------------------------------------------

