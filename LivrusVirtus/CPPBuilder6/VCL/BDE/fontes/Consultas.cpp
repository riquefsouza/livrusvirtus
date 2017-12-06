//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Consultas.h"
#include "Principal.h"
#include "RotinasGlobais.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmConsultas *frmConsultas;
//---------------------------------------------------------------------------
__fastcall TfrmConsultas::TfrmConsultas(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsultas::btnFecharClick(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsultas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (Consulta->RecordCount > 0)
   Rotinas->sCodigoSelecionado=Consulta->Fields->Fields[0]->AsString;

Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TfrmConsultas::ConsultaAfterScroll(TDataSet *DataSet)
{
labRegistros->Caption="Registro "+IntToStr(Consulta->RecNo)+
" de "+IntToStr(Consulta->RecordCount);
}
//---------------------------------------------------------------------------
void TfrmConsultas::LimparDados(AnsiString sTextoSql)
{
  labRegistros->Caption="Registro 0 de 0";
  Rotinas->ConsultaDados(Consulta, sTextoSql);
  btnPesquisar->Enabled=true;
  edtDescricao->Clear();
  edtDescricao->SetFocus();
}
//---------------------------------------------------------------------------
Boolean TfrmConsultas::PesquisarDados(AnsiString sTextoSql,
AnsiString sMensagemErro)
{
  if (Rotinas->ConsultaDados(Consulta, sTextoSql)) {
     btnPesquisar->Enabled=false;
     return true;
  } else {
     MessageDlg(sMensagemErro, mtInformation, TMsgDlgButtons() << mbOK, 0);
     return false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsultas::gridConsultaMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
  frmPrincipal->StatusBar1->Panels->Items[1]->Text=Caption;        
}
//---------------------------------------------------------------------------

