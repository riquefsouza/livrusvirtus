//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CadEnderecos.h"
#include "ConsultasSQL.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Cadastros"
#pragma resource "*.dfm"
TfrmCadEnderecos *frmCadEnderecos;
//---------------------------------------------------------------------------
__fastcall TfrmCadEnderecos::TfrmCadEnderecos(TComponent* Owner)
        : TfrmCadastros(Owner)
{
}
//---------------------------------------------------------------------------
Boolean TfrmCadEnderecos::ValidaDados(Boolean bTodosDados)
{
if (Rotinas->ValidaCampo(edtCodigo->Text,"C�digo n�o informado!"))
  return false;
if (bTodosDados) {
  if (Rotinas->ValidaCampo(edtDescricao->Text,"Logradouro n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtBairro->Text,"Bairro n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCEP->Text,"CEP n�o informado!"))
    return false;
  if (Rotinas->ValidaCampo(edtCidade->Text,"Cidade n�o informada!"))
    return false;
}
return true;
}
//---------------------------------------------------------------------------
void TfrmCadEnderecos::InformaLimpaDados(Boolean bInformar)
{
TfrmCadastros::InformaLimpaDados(bInformar);
if (bInformar) {
  edtBairro->Text=Consulta->Fields->Fields[2]->AsString;
  edtCEP->Text=Consulta->Fields->Fields[3]->AsString;
  edtCidade->Text=Consulta->Fields->Fields[4]->AsString;
  RecuperaEstado(Consulta->Fields->Fields[5]->AsString);
} else {
  edtBairro->Clear();
  edtCEP->Clear();
  edtCidade->Clear();
  cmbEstado->ItemIndex=0;
}
}
//---------------------------------------------------------------------------

void TfrmCadEnderecos::HabilitaDados(Boolean bHabilita)
{
TfrmCadastros::HabilitaDados(bHabilita);
edtBairro->Enabled=bHabilita;
edtCEP->Enabled=bHabilita;
edtCidade->Enabled=bHabilita;
cmbEstado->Enabled=bHabilita;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCadEnderecos::btnNovoClick(TObject *Sender)
{
TfrmCadastros::btnNovoClick(Sender);
NovoDado(ConsSQL->Endereco('N',edtCodigo->Text,"","","","",""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEnderecos::btnExcluirClick(TObject *Sender)
{
ExcluirDados(ConsSQL->Endereco('D',edtCodigo->Text,"","","","",""));
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEnderecos::btnPesquisarClick(TObject *Sender)
{
PesquisarDados(ConsSQL->Endereco('S',edtCodigo->Text,"","","","",""),
"Endere�o n�o encontrado!");
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEnderecos::btnSalvarClick(TObject *Sender)
{
SalvarDados(ConsSQL->Endereco('S',edtCodigo->Text,"","","","",""),
ConsSQL->Endereco('U',edtCodigo->Text,edtDescricao->Text,
edtBairro->Text,edtCEP->Text,edtCidade->Text,cmbEstado->Text),
ConsSQL->Endereco('I',edtCodigo->Text,edtDescricao->Text,
edtBairro->Text,edtCEP->Text,edtCidade->Text,cmbEstado->Text),true);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCadEnderecos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  frmPrincipal->Enderecos1->Enabled=true;
  TfrmCadastros::FormClose(Sender,Action);
}
//---------------------------------------------------------------------------
void TfrmCadEnderecos::AdicionaCombo()
{
cmbEstado->Items->Append("Pernambuco");
cmbEstado->Items->Append("Acre");
cmbEstado->Items->Append("Alagoas");
cmbEstado->Items->Append("Amap�");
cmbEstado->Items->Append("Amazonas");
cmbEstado->Items->Append("Bahia");
cmbEstado->Items->Append("Bras�lia");
cmbEstado->Items->Append("Cear�");
cmbEstado->Items->Append("Distrito Federal");
cmbEstado->Items->Append("Esp�rito Santo");
cmbEstado->Items->Append("Goi�s");
cmbEstado->Items->Append("Mato Grosso");
cmbEstado->Items->Append("Mato Grosso do Sul");
cmbEstado->Items->Append("Minas Gerais");
cmbEstado->Items->Append("Par�");
cmbEstado->Items->Append("Para�ba");
cmbEstado->Items->Append("Paran�");
cmbEstado->Items->Append("Santa Catarina");
cmbEstado->Items->Append("Rio Grande do Norte");
cmbEstado->Items->Append("Rio Grande do Sul");
cmbEstado->Items->Append("Rio de Janeiro");
cmbEstado->Items->Append("Rond�nia");
cmbEstado->Items->Append("Roraima");
cmbEstado->Items->Append("S�o Paulo");
cmbEstado->Items->Append("Sergipe");
cmbEstado->Items->Append("Tocantins");
}
//---------------------------------------------------------------------------
void TfrmCadEnderecos::RecuperaEstado(AnsiString sEstado)
{
int nCont;

 for(nCont=0; nCont <= cmbEstado->Items->Count-1; nCont++) {
    if (cmbEstado->Items->Strings[nCont]==sEstado) {
       cmbEstado->ItemIndex=nCont;
       break;
    }
 }
}

void __fastcall TfrmCadEnderecos::FormShow(TObject *Sender)
{
AdicionaCombo();
cmbEstado->ItemIndex=0;
}
//---------------------------------------------------------------------------

