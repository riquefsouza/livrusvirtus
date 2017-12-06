unit Consulta;

interface

uses
  SysUtils, WinTypes, WinProcs, Messages, Classes, Graphics, Controls,
  Forms, Dialogs, DB, Menus, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls;

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

uses RotinasG, Principa;

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
labRegistros.Caption:='Registro 0'+
' de '+inttostr(Consulta.RecordCount);
end;

end.
