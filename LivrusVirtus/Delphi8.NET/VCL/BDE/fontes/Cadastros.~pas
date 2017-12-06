unit Cadastros;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Db, DBTables, StdCtrls, System.ComponentModel;

type
  TfrmCadastros = class(TForm)
    Label1: TLabel;
    Label2: TLabel;
    btnSalvar: TButton;
    btnExcluir: TButton;
    btnLimpar: TButton;
    btnFechar: TButton;
    btnPesquisar: TButton;
    btnAnterior: TButton;
    btnProximo: TButton;
    btnNovo: TButton;
    edtCodigo: TEdit;
    edtDescricao: TEdit;
    Consulta: TQuery;
    Arquiva: TQuery;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btnFecharClick(Sender: TObject);
    procedure btnNovoClick(Sender: TObject);
    procedure btnLimparClick(Sender: TObject);
    procedure btnAnteriorClick(Sender: TObject);
    procedure btnProximoClick(Sender: TObject);
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure edtCodigoExit(Sender: TObject);
  private
    { Private declarations }
  protected
    { protected declarations }
    procedure NovoDado(sTextoSql: string);
    procedure InformaLimpaDados(bInformar: boolean); virtual;
    procedure HabilitaDados(bHabilita: boolean); virtual;
    function ValidaDados(bTodosDados: boolean): boolean; virtual;
    procedure ExcluirDados(sTextoSql: string);
    procedure PesquisarDados(sTextoSql,sMensagemErro: string);
    procedure SalvarDados(sTextoSql,sTextoUpdate,sTextoInsert: string;
                          bLimparDados: boolean);
  public
    { Public declarations }
  end;

var
  frmCadastros: TfrmCadastros;

implementation

uses Principal, RotinasGlobais;

{$R *.DFM}

procedure TfrmCadastros.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
Action:=caFree;
end;

procedure TfrmCadastros.btnFecharClick(Sender: TObject);
begin
Close;
end;

procedure TfrmCadastros.InformaLimpaDados(bInformar: boolean);
begin
if bInformar then begin
  edtCodigo.Text:=Consulta.Fields[0].AsString;
  edtDescricao.Text:=Consulta.Fields[1].AsString;
end else begin
  edtCodigo.Clear;
  edtDescricao.Clear;
  edtCodigo.Enabled:=True;
  edtCodigo.SetFocus;
end;
end;

function TfrmCadastros.ValidaDados(bTodosDados: boolean): boolean; 
begin
result:=true;
end;

procedure TfrmCadastros.HabilitaDados(bHabilita: boolean);
begin
edtDescricao.Enabled:=bHabilita;
end;

procedure TfrmCadastros.btnNovoClick(Sender: TObject);
begin
btnSalvar.Enabled:=true;
btnExcluir.Enabled:=false;
btnPesquisar.Enabled:=false;
btnAnterior.Enabled:=false;
btnProximo.Enabled:=false;
btnNovo.Enabled:=false;

InformaLimpaDados(false);
HabilitaDados(true);

end;

procedure TfrmCadastros.NovoDado(sTextoSql: string);
begin
 If Rotinas.ConsultaDados(Consulta, sTextoSql) Then begin
    edtCodigo.Text := Consulta.Fields[0].AsString;
    edtCodigo.Enabled := false;
    edtDescricao.SetFocus;
 end;
end;

procedure TfrmCadastros.btnLimparClick(Sender: TObject);
begin
btnSalvar.Enabled:=false;
btnExcluir.Enabled:=false;
btnPesquisar.Enabled:=true;
btnAnterior.Enabled:=false;
btnProximo.Enabled:=false;
btnNovo.Enabled:=true;

InformaLimpaDados(false);
HabilitaDados(false);
end;

procedure TfrmCadastros.ExcluirDados(sTextoSql: string);
begin
if ValidaDados(false) then begin
 if MessageDlg('Certeza de excluir?', mtConfirmation,
    [mbYes, mbNo], 0) = mrYes then begin
    Arquiva.Close;
    Arquiva.Sql.Text:=sTextoSql;
    Arquiva.ExecSQL;
    btnLimparClick(self);
 end;
end;
end;

procedure TfrmCadastros.PesquisarDados(sTextoSql,sMensagemErro: string);
begin
if edtCodigo.Text='' then begin
  btnAnterior.Enabled:=true;
  btnProximo.Enabled:=true;
end;

if Rotinas.ConsultaDados(Consulta,sTextoSql) then begin
 InformaLimpaDados(true);
 HabilitaDados(true);

 btnSalvar.Enabled:=true;
 btnExcluir.Enabled:=true;
 btnPesquisar.Enabled:=false;
end else
 MessageDlg(sMensagemErro, mtInformation, [mbOk], 0);
end;

procedure TfrmCadastros.btnAnteriorClick(Sender: TObject);
begin
Consulta.Prior;
InformaLimpaDados(true);
end;

procedure TfrmCadastros.btnProximoClick(Sender: TObject);
begin
Consulta.Next;
InformaLimpaDados(true);
end;

procedure TfrmCadastros.SalvarDados(sTextoSql,sTextoUpdate,sTextoInsert: string;
bLimparDados: boolean);
begin
if ValidaDados(true) then begin
   if Rotinas.ConsultaDados(Arquiva,sTextoSql) then begin
     Arquiva.Close;
     Arquiva.Sql.Text:=sTextoUpdate;
   end else begin
     Arquiva.Close;
     Arquiva.Sql.Text:=sTextoInsert;
   end;
   Arquiva.ExecSQL;
   if bLimparDados then
      btnLimparClick(self);
end;
end;

procedure TfrmCadastros.FormMouseMove(Sender: TObject; Shift: TShiftState;
  X, Y: Integer);
begin
  frmPrincipal.StatusBar1.Panels.Items[1].Text:=Caption;
end;

procedure TfrmCadastros.edtCodigoExit(Sender: TObject);
begin
if edtCodigo.Text<>'' then begin
  if Rotinas.ValidaInteger(edtCodigo.Text)=false then begin
    edtCodigo.Clear;
    edtCodigo.SetFocus;
  end;
end;  
end;

end.
