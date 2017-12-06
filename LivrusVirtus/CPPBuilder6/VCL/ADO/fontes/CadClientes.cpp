//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CadClientes.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Cadastros"
#pragma resource "*.dfm"
TfrmCadClientes *frmCadClientes;
//---------------------------------------------------------------------------
__fastcall TfrmCadClientes::TfrmCadClientes(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadClientes::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"CPF não informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Nome não informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtEmail->Text,"E-mail não informado!"))
    return false;
  if (rdgSexo->ItemIndex==-1) {
    MessageDlg("Sexo não informado!", mtInformation,
    TMsgDlgButtons() << mbOK, 0);
    return false;
  }
  if (Rotinas->ValidaCampo(edtTelefone->Text,"Telefone não informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodEndereco->Text,"Endereço não informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodPais->Text,"País não informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodProfissao->Text,"Profissão não informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void TfrmCadClientes::InformaLimpaDados(Boolean bInformar)
{
TfrmCadastros::InformaLimpaDados(bInformar);
if (bInformar) {
  edtEmail->Text=Consulta->Fields->Fields[2]->AsString;
  edtIdentidade->Text=Consulta->Fields->Fields[3]->AsString;
  if (Consulta->Fields->Fields[4]->AsString=="M")
     rdgSexo->ItemIndex=0;
  else
     rdgSexo->ItemIndex=1;
  edtTelefone->Text=Consulta->Fields->Fields[5]->AsString;
  edtDtNascimento->DateTime=Consulta->Fields->Fields[6]->AsDateTime;
  edtCodEndereco->Text=Consulta->Fields->Fields[7]->AsString;
  edtLogradouro->Text=Consulta->Fields->Fields[8]->AsString;
  edtBairro->Text=Consulta->Fields->Fields[9]->AsString;
  edtCEP->Text=Consulta->Fields->Fields[10]->AsString;
  edtCidade->Text=Consulta->Fields->Fields[11]->AsString;
  edtEstado->Text=Consulta->Fields->Fields[12]->AsString;
  edtCodPais->Text=Consulta->Fields->Fields[13]->AsString;
  edtPais->Text=Consulta->Fields->Fields[14]->AsString;
  edtCodProfissao->Text=Consulta->Fields->Fields[15]->AsString;
  edtProfissao->Text=Consulta->Fields->Fields[16]->AsString;
} else {
  edtEmail->Clear();
  edtIdentidade->Clear();
  rdgSexo->ItemIndex=-1;
  edtTelefone->Clear();
  edtDtNascimento->DateTime=Now();
  edtCodEndereco->Clear();
  edtLogradouro->Clear();
  edtBairro->Clear();
  edtCEP->Clear();
  edtCidade->Clear();
  edtEstado->Clear();
  edtCodPais->Clear();
  edtPais->Clear();
  edtCodProfissao->Clear();
  edtProfissao->Clear();
}
}
//---------------------------------------------------------------------------
void TfrmCadClientes::HabilitaDados(Boolean bHabilita)
{
TfrmCadastros::HabilitaDados(bHabilita);
edtEmail->Enabled=bHabilita;
edtIdentidade->Enabled=bHabilita;
rdgSexo->Enabled=bHabilita;
edtTelefone->Enabled=bHabilita;
edtDtNascimento->Enabled=bHabilita;
edtCodEndereco->Enabled=bHabilita;
btnPEndereco->Enabled=bHabilita;
edtCodPais->Enabled=bHabilita;
btnPPais->Enabled=bHabilita;
edtCodProfissao->Enabled=bHabilita;
btnPProfissao->Enabled=bHabilita;
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Cliente('D',edtCodigo->Text,"","","","","","","","",""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Cliente('S',edtCodigo->Text,"","","","","","","","",""),
"Cliente não encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnSalvarClick(TObject *Sender)
{
char sSexo;

if (rdgSexo->ItemIndex==0)
   sSexo='M';
else
   sSexo='F';
SalvarDados(ConsSQL->Cliente('S',edtCodigo->Text,"","","","","","","","",""),
ConsSQL->Cliente('U',edtCodigo->Text,edtDescricao->Text,
edtEmail->Text,edtIdentidade->Text,sSexo,edtTelefone->Text,
FormatDateTime("mm/dd/yyyy",edtDtNascimento->DateTime),edtCodEndereco->Text,
edtCodPais->Text, edtCodProfissao->Text),
ConsSQL->Cliente('I',edtCodigo->Text,edtDescricao->Text,
edtEmail->Text,edtIdentidade->Text,sSexo,edtTelefone->Text,
FormatDateTime("mm/dd/yyyy",edtDtNascimento->DateTime),edtCodEndereco->Text,
edtCodPais->Text, edtCodProfissao->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
frmPrincipal->ToolButton1->Enabled=true;
frmPrincipal->Clientes1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::edtCodPaisExit(TObject *Sender)
{
if (edtCodPais->Text!="") {
  edtPais->Text=Rotinas->ConsultaCampoDesc(Consulta,
  ConsSQL->Pais('S',edtCodPais->Text,""),"País não encontrado!");
  if (edtPais->Text=="")
     edtCodPais->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::edtCodProfissaoExit(TObject *Sender)
{
if (edtCodProfissao->Text!="") {
  edtProfissao->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodProfissao->Text,
  ConsSQL->Profissao('S',edtCodProfissao->Text,""),"Profissão não encontrada!");
  if (edtProfissao->Text=="")
     edtCodProfissao->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::edtCodEnderecoExit(TObject *Sender)
{
if (edtCodEndereco->Text!="") {
  edtLogradouro->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodEndereco->Text,
  ConsSQL->Endereco('S',edtCodEndereco->Text,"","","","",""),
  "Endereço não encontrado!");
  if (edtLogradouro->Text=="") {
     edtCodEndereco->SetFocus();
     edtLogradouro->Clear();
     edtBairro->Clear();
     edtCEP->Clear();
     edtCidade->Clear();
     edtEstado->Clear();
  } else {
     edtBairro->Text=Consulta->Fields->Fields[2]->AsString;
     edtCEP->Text=Consulta->Fields->Fields[3]->AsString;
     edtCidade->Text=Consulta->Fields->Fields[4]->AsString;
     edtEstado->Text=Consulta->Fields->Fields[5]->AsString;
  }
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::edtCodigoExit(TObject *Sender)
{
 if (edtCodigo->Text!="") {
   if (Rotinas->ValidaCPF(edtCodigo->Text)==false) {
      MessageDlg("CPF inválido!", mtError, TMsgDlgButtons() << mbOK, 0);
      edtCodigo->Clear();
      edtCodigo->SetFocus();
   }
 }
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnPEnderecoClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConEnderecos), &frmConEnderecos);
  frmConEnderecos->ShowModal();
  edtCodEndereco->Text=Rotinas->sCodigoSelecionado;
  edtCodEnderecoExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnPPaisClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConPaises), &frmConPaises);
  frmConPaises->ShowModal();
  edtCodPais->Text=Rotinas->sCodigoSelecionado;
  edtCodPaisExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnPProfissaoClick(TObject *Sender)
{
  Application->CreateForm(__classid(TfrmConProfissoes), &frmConProfissoes);
  frmConProfissoes->ShowModal();
  edtCodProfissao->Text=Rotinas->sCodigoSelecionado;
  edtCodProfissaoExit(this);
}
//---------------------------------------------------------------------------

