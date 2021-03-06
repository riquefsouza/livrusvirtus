unit ConClientes;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls;

type
  TfrmConClientes = class(TfrmConsultas)
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
  frmConClientes: TfrmConClientes;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConClientes.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Clientes2.Enabled:=true;
inherited;
end;

procedure TfrmConClientes.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Cliente('S','0','','','','','','','','',''));
end;

procedure TfrmConClientes.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Cliente('S','', edtDescricao.Text,
'','','','','','','',''), 'Cliente n�o encontrado!');
end;

procedure TfrmConClientes.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;


end.
