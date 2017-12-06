unit ConEnderecos;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls,
  System.ComponentModel;

type
  TfrmConEnderecos = class(TfrmConsultas)
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
  frmConEnderecos: TfrmConEnderecos;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConEnderecos.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Enderecos2.Enabled:=true;
inherited;
end;

procedure TfrmConEnderecos.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Endereco('S','0','','','','',''));
end;

procedure TfrmConEnderecos.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Endereco('S','', edtDescricao.Text,'','','',''),
'Logradouro não encontrado!');
end;

procedure TfrmConEnderecos.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

end.
