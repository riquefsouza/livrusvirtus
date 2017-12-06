unit Consultas;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls;

type
  TfrmConsultas = class(TForm)
    Panel1: TPanel;
    Label2: TLabel;
    edtDescricao: TEdit;
    btnPesquisar: TButton;
    gridConsulta: TDBGrid;
    Panel2: TPanel;
    labRegistros: TLabel;
    btnFechar: TButton;
    btnLimpar: TButton;
    DSConsulta: TDataSource;
    Consulta: TQuery;
    procedure btnFecharClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure ConsultaAfterScroll(DataSet: TDataSet);
    procedure gridConsultaMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
  private
    { Private declarations }
  protected
    { protected declarations }
    procedure LimparDados(sTextoSql: string);
    function PesquisarDados(sTextoSql,sMensagemErro: string): boolean;
  public
    { Public declarations }
  end;

var
  frmConsultas: TfrmConsultas;

implementation

uses RotinasGlobais, Principal;

{$R *.DFM}

procedure TfrmConsultas.btnFecharClick(Sender: TObject);
begin
Close;
end;

procedure TfrmConsultas.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
if Consulta.RecordCount > 0 then
   Rotinas.sCodigoSelecionado:=Consulta.Fields[0].AsString;

Action:=CaFree;
end;

procedure TfrmConsultas.LimparDados(sTextoSql: string);
begin
  labRegistros.Caption:='Registro 0 de 0';
  Rotinas.ConsultaDados(Consulta, sTextoSql);
  btnPesquisar.Enabled:=true;
  edtDescricao.Clear;
  edtDescricao.SetFocus;
end;

function TfrmConsultas.PesquisarDados(sTextoSql,sMensagemErro: string):boolean;
begin
  if Rotinas.ConsultaDados(Consulta, sTextoSql) then begin
     btnPesquisar.Enabled:=false;
     result:=true;
  end else begin
     MessageDlg(sMensagemErro, mtInformation, [mbOk], 0);
     result:=false;
  end;
end;

procedure TfrmConsultas.ConsultaAfterScroll(DataSet: TDataSet);
begin
labRegistros.Caption:='Registro '+inttostr(Consulta.RecNo)+
' de '+inttostr(Consulta.RecordCount);
end;

procedure TfrmConsultas.gridConsultaMouseMove(Sender: TObject;
  Shift: TShiftState; X, Y: Integer);
begin
  frmPrincipal.StatusBar1.Panels.Items[1].Text:=Caption;
end;

end.