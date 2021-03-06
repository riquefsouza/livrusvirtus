//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadLivros.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConAssuntos.h"
#include "ConEditoras.h"
#include "ConAutores.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
//#pragma link "CSPIN"
#pragma resource "*.xfm"
TfrmCadLivros *frmCadLivros;
//---------------------------------------------------------------------------
__fastcall TfrmCadLivros::TfrmCadLivros(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadLivros::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"ISBN n�o informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"T�tulo n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodEditora->Text.c_bstr(),"Editora n�o informada!"))
    return false;
  if (lstAssuntos->Items->Count == 0) {
    MessageDlg("Assunto(s) n�o informado(s)!", mtInformation,
    TMsgDlgButtons() << mbOk, 0);
    return false;
  }
  if (lstAutores->Items->Count == 0) {
    MessageDlg("Autore(s) n�o informado(s)!", mtInformation,
    TMsgDlgButtons() << mbOk, 0);
    return false;
  }
}
return true;
}
//---------------------------------------------------------------------------
void TfrmCadLivros::InformaLimpaDados(Boolean bInformar)
{
TfrmCadastros::InformaLimpaDados(bInformar);
if (bInformar) {
  edtEdicao->Value=CDSConsulta->Fields->Fields[2]->AsInteger;
  edtAnoPubli->Value=CDSConsulta->Fields->Fields[3]->AsInteger;
  edtVolume->Value=CDSConsulta->Fields->Fields[4]->AsInteger;
  edtCodEditora->Text=CDSConsulta->Fields->Fields[5]->AsString;
  edtEditora->Text=CDSConsulta->Fields->Fields[6]->AsString;
  cmbIdioma->ItemIndex=slIdiomas->IndexOf(CDSConsulta->Fields->Fields[7]->AsString);
  edtNPaginas->Value=CDSConsulta->Fields->Fields[9]->AsInteger;
  edtPreco->Text=CDSConsulta->Fields->Fields[10]->AsString;
  edtQtdEstoque->Value=CDSConsulta->Fields->Fields[11]->AsInteger;
  Rotinas->AdicionaValoresLista(ConsLista,
  ConsSQL->LivroAss('S',edtCodigo->Text.c_bstr(),""),lstAssuntos,slAssuntos);
  Rotinas->AdicionaValoresLista(ConsLista,
  ConsSQL->LivroAut('S',edtCodigo->Text.c_bstr(),""),lstAutores,slAutores);
} else {
  edtEdicao->Value=1;
  edtAnoPubli->Value=StrToInt(FormatDateTime("yyyy",Now()));
  edtVolume->Value=1;
  edtCodEditora->Clear();
  edtEditora->Clear();
  edtNPaginas->Value=1;
  edtPreco->Text="0,00";
  edtQtdEstoque->Value=0;
  edtCodAssunto->Clear();
  lstAssuntos->Clear();
  edtCodAutor->Clear();
  lstAutores->Clear();
  slAssuntos->Clear();
  slAutores->Clear();
}
}
//---------------------------------------------------------------------------
void TfrmCadLivros::HabilitaDados(Boolean bHabilita)
{
TfrmCadastros::HabilitaDados(bHabilita);
edtEdicao->Enabled=bHabilita;
edtAnoPubli->Enabled=bHabilita;
edtVolume->Enabled=bHabilita;
edtCodEditora->Enabled=bHabilita;
btnPEditora->Enabled=bHabilita;
cmbIdioma->Enabled=bHabilita;
edtNPaginas->Enabled=bHabilita;
edtPreco->Enabled=bHabilita;
edtQtdEstoque->Enabled=bHabilita;
edtCodAssunto->Enabled=bHabilita;
btnPAssunto->Enabled=bHabilita;
btnAdAssuntos->Enabled=bHabilita;
lstAssuntos->Enabled=bHabilita;
edtCodAutor->Enabled=bHabilita;
btnPAutor->Enabled=bHabilita;
btnAdAutores->Enabled=bHabilita;
lstAutores->Enabled=bHabilita;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Livro('D',edtCodigo->Text.c_bstr(),"","","","","","","","",""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Livro('S',edtCodigo->Text.c_bstr(),"","","","","","","","",""),
"Livro n�o encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Livro('S',edtCodigo->Text.c_bstr(),"","","","","","","","",""),
ConsSQL->Livro('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr(),edtEdicao->Text.c_bstr(),
edtAnoPubli->Text.c_bstr(),edtVolume->Text.c_bstr(),edtCodEditora->Text.c_bstr(),
slIdiomas->Strings[cmbIdioma->ItemIndex],edtNPaginas->Text.c_bstr(),
Rotinas->VirgulaParaPonto(edtPreco->Text.c_bstr()),edtQtdEstoque->Text.c_bstr()),
ConsSQL->Livro('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr(),edtEdicao->Text.c_bstr(),
edtAnoPubli->Text.c_bstr(),edtVolume->Text.c_bstr(),edtCodEditora->Text.c_bstr(),
slIdiomas->Strings[cmbIdioma->ItemIndex],edtNPaginas->Text.c_bstr(),
Rotinas->VirgulaParaPonto(edtPreco->Text.c_bstr()),edtQtdEstoque->Text.c_bstr()),false);
SalvaLista('A');
SalvaLista('B');
btnLimparClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::FormClose(TObject *Sender,
      TCloseAction &Action)
{
slAssuntos->Free();
slAutores->Free();
slIdiomas->Free();

frmPrincipal->ToolButton2->Enabled=true;
frmPrincipal->Livros1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::FormShow(TObject *Sender)
{
slAssuntos= new TStringList();
slAutores=  new TStringList();
slIdiomas= new TStringList();

edtAnoPubli->Value=StrToInt(FormatDateTime("yyyy",Now()));
AdicionaCombo();
cmbIdioma->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodEditoraExit(TObject *Sender)
{
if (edtCodEditora->Text!="") {
  edtEditora->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodEditora->Text.c_bstr(),
  ConsSQL->Editora('S',edtCodEditora->Text.c_bstr(),""),"Editora n�o encontrada!");
  if (edtEditora->Text=="")
     edtCodEditora->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodAssuntoExit(TObject *Sender)
{
if (edtCodAssunto->Text!="") {
  edtAssunto->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodAssunto->Text.c_bstr(),
  ConsSQL->Assunto('S',edtCodAssunto->Text.c_bstr(),""),"Assunto n�o encontrado!");
  if (edtAssunto->Text=="")
     edtCodAssunto->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodAutorExit(TObject *Sender)
{
if (edtCodAutor->Text!="") {
  edtAutor->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodAutor->Text.c_bstr(),
  ConsSQL->Autor('S',edtCodAutor->Text.c_bstr(),""),"Autor n�o encontrado!");
  if (edtAutor->Text=="")
     edtCodAutor->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnPAssuntoClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConAssuntos), &frmConAssuntos);
  frmConAssuntos->ShowModal();
  edtCodAssunto->Text=Rotinas->sCodigoSelecionado;
  edtCodAssuntoExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnAdAssuntosClick(TObject *Sender)
{
Rotinas->AdicionaItemLista(lstAssuntos,slAssuntos,edtCodAssunto,edtAssunto);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::lstAssuntosDblClick(TObject *Sender)
{
Rotinas->RemoveItemLista(lstAssuntos,slAssuntos);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::lstAutoresDblClick(TObject *Sender)
{
Rotinas->RemoveItemLista(lstAutores,slAutores);        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtPrecoExit(TObject *Sender)
{
if (Rotinas->ValidaFloat(edtPreco->Text.c_bstr()))
  edtPreco->Text=FormatFloat("0.00",StrToFloat(edtPreco->Text.c_bstr()));
else
  edtPreco->Text="0,00";
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodigoExit(TObject *Sender)
{
 if (edtCodigo->Text!="") {
   if (Rotinas->ValidaISBN(edtCodigo->Text.c_bstr())==false) {
      MessageDlg("ISBN inv�lido!", mtError, TMsgDlgButtons() << mbOk, 0);
      edtCodigo->Clear();
      edtCodigo->SetFocus();
   }
 }

}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnPAutorClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConAutores), &frmConAutores);
  frmConAutores->ShowModal();
  edtCodAutor->Text=Rotinas->sCodigoSelecionado;
  edtCodAutorExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnAdAutoresClick(TObject *Sender)
{
Rotinas->AdicionaItemLista(lstAutores,slAutores,edtCodAutor,edtAutor);
}
//---------------------------------------------------------------------------

void TfrmCadLivros::SalvaLista(char sOpcao)
{
int nCont;

if (sOpcao=='A') {
 Arquiva->SQL->Text=ConsSQL->LivroAss('D',edtCodigo->Text.c_bstr(),"");
 Arquiva->ExecSQL();
 for (nCont=0; nCont <= slAssuntos->Count-1; nCont++) {
  Arquiva->SQL->Text=ConsSQL->LivroAss('I',edtCodigo->Text.c_bstr(),
  slAssuntos->Strings[nCont]);
  Arquiva->ExecSQL();
 }
} else if (sOpcao=='B') {
 Arquiva->SQL->Text=ConsSQL->LivroAut('D',edtCodigo->Text.c_bstr(),"");
 Arquiva->ExecSQL();
 for (nCont=0; nCont <= slAutores->Count-1; nCont++) {
  Arquiva->SQL->Text=ConsSQL->LivroAut('I',edtCodigo->Text.c_bstr(),
  slAutores->Strings[nCont]);
  Arquiva->ExecSQL();
 }
}

}
//---------------------------------------------------------------------------
void TfrmCadLivros::AdicionaCombo()
{
Consulta->Close();
Consulta->SQL->Text=ConsSQL->Idioma('S',"","");
Consulta->Open();
 while (!Consulta->Eof) {
  slIdiomas->Append(Consulta->Fields->Fields[0]->AsString);
  cmbIdioma->Items->Append(Consulta->Fields->Fields[1]->AsString);
  Consulta->Next();
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnPEditoraClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConEditoras), &frmConEditoras);
  frmConEditoras->ShowModal();
  edtCodEditora->Text=Rotinas->sCodigoSelecionado;
  edtCodEditoraExit(this);
}
//---------------------------------------------------------------------------

