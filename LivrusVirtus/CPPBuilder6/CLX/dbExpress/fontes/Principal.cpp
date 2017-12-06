//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop

#include "Principal.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"
#include "Splash.h"
#include "Sobre.h"
#include "Login.h"
#include "AlterarSenha.h"
#include "CadAssuntos.h"
#include "ConAssuntos.h"
#include "CadAutores.h"
#include "ConAutores.h"
#include "CadEditoras.h"
#include "ConEditoras.h"
#include "CadIdiomas.h"
#include "ConIdiomas.h"
#include "CadProfissoes.h"
#include "ConProfissoes.h"
#include "CadPaises.h"
#include "ConPaises.h"
#include "CadEnderecos.h"
#include "ConEnderecos.h"
#include "CadLivros.h"
#include "ConLivros.h"
#include "CadClientes.h"
#include "ConClientes.h"
#include "ConVendas.h"
#include "VenderLivros.h"
//---------------------------------------------------------------------------
#pragma resource "*.xfm"
TfrmPrincipal *frmPrincipal;
//---------------------------------------------------------------------------
__fastcall TfrmPrincipal::TfrmPrincipal(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if (MessageDlg("Deseja sair do sistema?", mtConfirmation,
                TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes) {
    ConsSQL->Free();
    db->Close();
    Action = caFree;
 } else
    Action = caNone;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPrincipal::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
StatusBar1->Panels->Items[1]->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Sobre1Click(TObject *Sender)
{
   Application->CreateForm(__classid(TfrmSobre), &frmSobre);
   frmSobre->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Livros1Click(TObject *Sender)
{
 ToolButton2->Enabled=false;
 Livros1->Enabled=false;
 Application->CreateForm(__classid(TfrmCadLivros), &frmCadLivros);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Sair1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Assuntos1Click(TObject *Sender)
{
  Assuntos1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadAssuntos), &frmCadAssuntos);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Horizontal1Click(TObject *Sender)
{
//    TileMode = tbHorizontal;
  Tile();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Vertical1Click(TObject *Sender)
{
//    TileMode = tbVertical;
  Tile();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Cascata1Click(TObject *Sender)
{
Cascade();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::OrganizarIcones1Click(TObject *Sender)
{
//ArrangeIcons();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::AlterarSenha1Click(TObject *Sender)
{
  AlterarSenha1->Enabled=false;
    Application->CreateForm(__classid(TfrmAlterarSenha), &frmAlterarSenha);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::FormShow(TObject *Sender)
{
  db->Open();

  ConsSQL = new TConsultasSQL();
  Rotinas = new TRotinasGlobais();

  Application->CreateForm(__classid(TfrmSplash), &frmSplash);
  frmSplash->ShowModal();

  Application->CreateForm(__classid(TfrmLogin), &frmLogin);
  frmLogin->ShowModal();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Clientes1Click(TObject *Sender)
{
  ToolButton1->Enabled=false;
  Clientes1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadClientes), &frmCadClientes);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::VenderLivros1Click(TObject *Sender)
{
  ToolButton3->Enabled=false;
  VenderLivros1->Enabled=false;
  Application->CreateForm(__classid(TfrmVenderLivros), &frmVenderLivros);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Clientes2Click(TObject *Sender)
{
  Clientes2->Enabled=false;
  Application->CreateForm(__classid(TfrmConClientes), &frmConClientes);
  Rotinas->ChamarTela(frmConClientes);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Livros2Click(TObject *Sender)
{
  Livros2->Enabled=false;
  Application->CreateForm(__classid(TfrmConLivros), &frmConLivros);
  Rotinas->ChamarTela(frmConLivros);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Autores1Click(TObject *Sender)
{
  Autores1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadAutores), &frmCadAutores);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Editoras1Click(TObject *Sender)
{
  Editoras1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadEditoras), &frmCadEditoras);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Idiomas1Click(TObject *Sender)
{
  Idiomas1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadIdiomas), &frmCadIdiomas);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Paises1Click(TObject *Sender)
{
  Paises1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadPaises), &frmCadPaises);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Profissoes1Click(TObject *Sender)
{
  Profissoes1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadProfissoes), &frmCadProfissoes);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Enderecos1Click(TObject *Sender)
{
  Enderecos1->Enabled=false;
  Application->CreateForm(__classid(TfrmCadEnderecos), &frmCadEnderecos);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Assuntos2Click(TObject *Sender)
{
  Assuntos2->Enabled=false;
  Application->CreateForm(__classid(TfrmConAssuntos), &frmConAssuntos);
  Rotinas->ChamarTela(frmConAssuntos);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Autores2Click(TObject *Sender)
{
  Autores2->Enabled=false;
  Application->CreateForm(__classid(TfrmConAutores), &frmConAutores);
  Rotinas->ChamarTela(frmConAutores);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Editoras2Click(TObject *Sender)
{
  Editoras2->Enabled=false;
  Application->CreateForm(__classid(TfrmConEditoras), &frmConEditoras);
  Rotinas->ChamarTela(frmConEditoras);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Enderecos2Click(TObject *Sender)
{
  Enderecos2->Enabled=false;
  Application->CreateForm(__classid(TfrmConEnderecos), &frmConEnderecos);
  Rotinas->ChamarTela(frmConEnderecos);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Idiomas2Click(TObject *Sender)
{
  Idiomas2->Enabled=false;
  Application->CreateForm(__classid(TfrmConIdiomas), &frmConIdiomas);
  Rotinas->ChamarTela(frmConIdiomas);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Paises2Click(TObject *Sender)
{
  Paises2->Enabled=false;
  Application->CreateForm(__classid(TfrmConPaises), &frmConPaises);
  Rotinas->ChamarTela(frmConPaises);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::Profissoes2Click(TObject *Sender)
{
  Profissoes2->Enabled=false;
  Application->CreateForm(__classid(TfrmConProfissoes), &frmConProfissoes);
  Rotinas->ChamarTela(frmConProfissoes);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPrincipal::VendasRealizadas1Click(TObject *Sender)
{
  VendasRealizadas1->Enabled=false;
  Application->CreateForm(__classid(TfrmConVendas), &frmConVendas);
  Rotinas->ChamarTela(frmConVendas);
}
//---------------------------------------------------------------------------

