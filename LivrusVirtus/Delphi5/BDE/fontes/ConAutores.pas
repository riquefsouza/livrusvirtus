unit ConAutores;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls;

type
  TfrmConAutores = class(TfrmConsultas)
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
  frmConAutores: TfrmConAutores;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConAutores.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Autores2.Enabled:=true;
inherited;
end;

procedure TfrmConAutores.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Autor('S','0',''));
end;

procedure TfrmConAutores.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Autor('S','', edtDescricao.Text),
'Autor não encontrado!');
end;

procedure TfrmConAutores.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;


end.
