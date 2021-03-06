//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "CadClientes.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
//---------------------------------------------------------------------------
#pragma link "Cadastros"
#pragma resource "*.xfm"
TfrmCadClientes *frmCadClientes;
//---------------------------------------------------------------------------
__fastcall TfrmCadClientes::TfrmCadClientes(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadClientes::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text.c_bstr(),"CPF n�o informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text.c_bstr(),"Nome n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtEmail->Text.c_bstr(),"E-mail n�o informado!"))
    return false;
  if (rdgSexo->ItemIndex==-1) {
    MessageDlg("Sexo n�o informado!", mtInformation,
    TMsgDlgButtons() << mbOk, 0);
    return false;
  }
  if (Rotinas->ValidaCampo(edtTelefone->Text.c_bstr(),"Telefone n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodEndereco->Text.c_bstr(),"Endere�o n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodPais->Text.c_bstr(),"Pa�s n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCodProfissao->Text.c_bstr(),"Profiss�o n�o informado!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void TfrmCadClientes::InformaLimpaDados(Boolean bInformar)
{
TfrmCadastros::InformaLimpaDados(bInformar);
if (bInformar) {
  edtEmail->Text=CDSConsulta->Fields->Fields[2]->AsString;
  edtIdentidade->Text=CDSConsulta->Fields->Fields[3]->AsString;
  if (CDSConsulta->Fields->Fields[4]->AsString=="M")
     rdgSexo->ItemIndex=0;
  else
     rdgSexo->ItemIndex=1;
  edtTelefone->Text=CDSConsulta->Fields->Fields[5]->AsString;
  edtDtNascimento->Text=CDSConsulta->Fields->Fields[6]->AsString;
  edtCodEndereco->Text=CDSConsulta->Fields->Fields[7]->AsString;
  edtLogradouro->Text=CDSConsulta->Fields->Fields[8]->AsString;
  edtBairro->Text=CDSConsulta->Fields->Fields[9]->AsString;
  edtCEP->Text=CDSConsulta->Fields->Fields[10]->AsString;
  edtCidade->Text=CDSConsulta->Fields->Fields[11]->AsString;
  edtEstado->Text=CDSConsulta->Fields->Fields[12]->AsString;
  edtCodPais->Text=CDSConsulta->Fields->Fields[13]->AsString;
  edtPais->Text=CDSConsulta->Fields->Fields[14]->AsString;
  edtCodProfissao->Text=CDSConsulta->Fields->Fields[15]->AsString;
  edtProfissao->Text=CDSConsulta->Fields->Fields[16]->AsString;
} else {
  edtEmail->Clear();
  edtIdentidade->Clear();
  rdgSexo->ItemIndex=-1;
  edtTelefone->Clear();
  edtDtNascimento->Text=FormatDateTime("dd/MM/yyyy",Now());
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
ExcluirDados(ConsSQL->Cliente('D',edtCodigo->Text.c_bstr(),"","","","","","","","",""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Cliente('S',edtCodigo->Text.c_bstr(),"","","","","","","","",""),
"Cliente n�o encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::btnSalvarClick(TObject *Sender)
{
char sSexo;

if (rdgSexo->ItemIndex==0)
   sSexo='M';
else
   sSexo='F';
SalvarDados(ConsSQL->Cliente('S',edtCodigo->Text.c_bstr(),"","","","","","","","",""),
ConsSQL->Cliente('U',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr(),
edtEmail->Text.c_bstr(),edtIdentidade->Text.c_bstr(),sSexo,edtTelefone->Text.c_bstr(),
FormatDateTime("mm/dd/yyyy",StrToDateTime(edtDtNascimento->Text)),
edtCodEndereco->Text.c_bstr(),edtCodPais->Text.c_bstr(), edtCodProfissao->Text.c_bstr()),
ConsSQL->Cliente('I',edtCodigo->Text.c_bstr(),edtDescricao->Text.c_bstr(),
edtEmail->Text.c_bstr(),edtIdentidade->Text.c_bstr(),sSexo,edtTelefone->Text.c_bstr(),
FormatDateTime("mm/dd/yyyy",StrToDateTime(edtDtNascimento->Text)),
edtCodEndereco->Text.c_bstr(),edtCodPais->Text.c_bstr(), edtCodProfissao->Text.c_bstr()),true);
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
  ConsSQL->Pais('S',edtCodPais->Text.c_bstr(),""),"Pa�s n�o encontrado!");
  if (edtPais->Text=="")
     edtCodPais->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::edtCodProfissaoExit(TObject *Sender)
{
if (edtCodProfissao->Text!="") {
  edtProfissao->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodProfissao->Text.c_bstr(),
  ConsSQL->Profissao('S',edtCodProfissao->Text.c_bstr(),""),"Profiss�o n�o encontrada!");
  if (edtProfissao->Text=="")
     edtCodProfissao->SetFocus();
}
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadClientes::edtCodEnderecoExit(TObject *Sender)
{
if (edtCodEndereco->Text!="") {
  edtLogradouro->Text=Rotinas->ConsultaCampoDesc(Consulta,edtCodEndereco->Text.c_bstr(),
  ConsSQL->Endereco('S',edtCodEndereco->Text.c_bstr(),"","","","",""),
  "Endere�o n�o encontrado!");
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
   if (Rotinas->ValidaCPF(edtCodigo->Text.c_bstr())==false) {
      MessageDlg("CPF inv�lido!", mtError, TMsgDlgButtons() << mbOk, 0);
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
void __fastcall TfrmCadClientes::edtDtNascimentoExit(TObject *Sender)
{
  if (edtDtNascimento->Text!="") {
    if (Rotinas->ValidaDateTime(edtDtNascimento->Text)==false) {
      edtDtNascimento->Clear();
      edtDtNascimento->SetFocus();
    }
  }
}
//---------------------------------------------------------------------------
