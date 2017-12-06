unit ConIdiomas;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls, FMTBcd,
  Borland.Vcl.Provider, Borland.Vcl.DBClient, Borland.Vcl.SqlExpr,
  System.ComponentModel;

type
  TfrmConIdiomas = class(TfrmConsultas)
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
  frmConIdiomas: TfrmConIdiomas;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConIdiomas.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Idiomas2.Enabled:=true;
inherited;
end;

procedure TfrmConIdiomas.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Idioma('S','0',''));
end;

procedure TfrmConIdiomas.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Idioma('S','', edtDescricao.Text),
'Idioma não encontrado!');
end;

procedure TfrmConIdiomas.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;


end.
