//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CadLivros.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Cadastros"
#pragma link "CSPIN"
#pragma resource "*.dfm"
TfrmCadLivros *frmCadLivros;
//---------------------------------------------------------------------------
__fastcall TfrmCadLivros::TfrmCadLivros(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadLivros::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"ISBN não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Título não informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodEditora->Text,"Editora não informada!"))
    return false;
  if (lstAssuntos->Items->Count == 0) {
    MessageDlg("Assunto(s) não informado(s)!", mtInformation,
    TMsgDlgButtons() << mbOK, 0);
    return false;
  }
  if (lstAutores->Items->Count == 0) {
    MessageDlg("Autore(s) não informado(s)!", mtInformation,
    TMsgDlgButtons() << mbOK, 0);
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
  edtEdicao->Text=CDSConsulta->Fields->Fields[2]->AsString;
  edtAnoPubli->Text=CDSConsulta->Fields->Fields[3]->AsString;
  edtVolume->Text=CDSConsulta->Fields->Fields[4]->AsString;
  edtCodEditora->Text=CDSConsulta->Fields->Fields[5]->AsString;
  edtEditora->Text=CDSConsulta->Fields->Fields[6]->AsString;
  cmbIdioma->ItemIndex=slIdiomas->IndexOf(CDSConsulta->Fields->Fields[7]->AsString);
  edtNPaginas->Text=CDSConsulta->Fields->Fields[9]->AsString;
  edtPreco->Text=CDSConsulta->Fields->Fields[10]->AsString;
  edtQtdEstoque->Text=CDSConsulta->Fields->Fields[11]->AsString;
  Rotinas->AdicionaValoresLista(ConsLista,
  ConsSQL->LivroAss('S',edtCodigo->Text,""),lstAssuntos,slAssuntos);
  Rotinas->AdicionaValoresLista(ConsLista,
  ConsSQL->LivroAut('S',edtCodigo->Text,""),lstAutores,slAutores);
} else {
  edtEdicao->Text="1";
  edtAnoPubli->Text=FormatDateTime("yyyy",Now());
  edtVolume->Text="1";
  edtCodEditora->Clear();
  edtEditora->Clear();
  edtNPaginas->Text="1";
  edtPreco->Text="0,00";
  edtQtdEstoque->Text="0";
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
ExcluirDados(ConsSQL->Livro('D',edtCodigo->Text,"","","","","","","","",""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Livro('S',edtCodigo->Text,"","","","","","","","",""),
"Livro não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Livro('S',edtCodigo->Text,"","","","","","","","",""),
ConsSQL->Livro('U',edtCodigo->Text,edtDescricao->Text,edtEdicao->Text,
edtAnoPubli->Text,edtVolume->Text,edtCodEditora->Text,
slIdiomas->Strings[cmbIdioma->ItemIndex],edtNPaginas->Text,
Rotinas->VirgulaParaPonto(edtPreco->Text),edtQtdEstoque->Text),
ConsSQL->Livro('I',edtCodigo->Text,edtDescricao->Text,edtEdicao->Text,
edtAnoPubli->Text,edtVolume->Text,edtCodEditora->Text,
slIdiomas->Strings[cmbIdioma->ItemIndex],edtNPaginas->Text,
Rotinas->VirgulaParaPonto(edtPreco->Text),edtQtdEstoque->Text),false);
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

edtAnoPubli->Text=FormatDateTime("yyyy",Now());
AdicionaCombo();
cmbIdioma->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodEditoraExit(TObject *Sender)
{
if (edtCodEditora->Text!="") {
  edtEditora->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodEditora->Text,
  ConsSQL->Editora('S',edtCodEditora->Text,""),"Editora não encontrada!");
  if (edtEditora->Text=="") 
     edtCodEditora->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodAssuntoExit(TObject *Sender)
{
if (edtCodAssunto->Text!="") {
  edtAssunto->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodAssunto->Text,
  ConsSQL->Assunto('S',edtCodAssunto->Text,""),"Assunto não encontrado!");
  if (edtAssunto->Text=="")
     edtCodAssunto->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodAutorExit(TObject *Sender)
{
if (edtCodAutor->Text!="") {
  edtAutor->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodAutor->Text,
  ConsSQL->Autor('S',edtCodAutor->Text,""),"Autor não encontrado!");
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
if (Rotinas->ValidaFloat(edtPreco->Text)) 
  edtPreco->Text=FormatFloat("0.00",StrToFloat(edtPreco->Text));
else
  edtPreco->Text="0,00";
        
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadLivros::edtCodigoExit(TObject *Sender)
{
 if (edtCodigo->Text!="") {
   if (Rotinas->ValidaISBN(edtCodigo->Text)==false) {
      MessageDlg("ISBN inválido!", mtError, TMsgDlgButtons() << mbOK, 0);
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
 Arquiva->SQL->Text=ConsSQL->LivroAss('D',edtCodigo->Text,"");
 Arquiva->ExecSQL();
 for (nCont=0; nCont <= slAssuntos->Count-1; nCont++) {
  Arquiva->SQL->Text=ConsSQL->LivroAss('I',edtCodigo->Text,
  slAssuntos->Strings[nCont]);
  Arquiva->ExecSQL();
 }
} else if (sOpcao=='B') {
 Arquiva->SQL->Text=ConsSQL->LivroAut('D',edtCodigo->Text,"");
 Arquiva->ExecSQL();
 for (nCont=0; nCont <= slAutores->Count-1; nCont++) {
  Arquiva->SQL->Text=ConsSQL->LivroAut('I',edtCodigo->Text,
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

