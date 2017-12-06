unit ConAssuntos;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls,
  System.ComponentModel;

type
  TfrmConAssuntos = class(TfrmConsultas)
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
  frmConAssuntos: TfrmConAssuntos;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConAssuntos.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Assuntos2.Enabled:=true;
inherited;
end;

procedure TfrmConAssuntos.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Assunto('S','0',''));
end;

procedure TfrmConAssuntos.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Assunto('S','', edtDescricao.Text),
'Assunto não encontrado!');
end;

procedure TfrmConAssuntos.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

end.
