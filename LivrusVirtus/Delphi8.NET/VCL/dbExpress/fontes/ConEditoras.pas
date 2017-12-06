unit ConEditoras;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls, FMTBcd,
  Borland.Vcl.Provider, Borland.Vcl.DBClient, Borland.Vcl.SqlExpr,
  System.ComponentModel;

type
  TfrmConEditoras = class(TfrmConsultas)
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btnLimparClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmConEditoras: TfrmConEditoras;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConEditoras.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Editoras2.Enabled:=true;
inherited;
end;

procedure TfrmConEditoras.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Editora('S','0',''));
end;

procedure TfrmConEditoras.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Editora('S','', edtDescricao.Text),
'Editora não encontrada!');
end;

procedure TfrmConEditoras.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;


end.
