unit ConProfissoes;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls;

type
  TfrmConProfissoes = class(TfrmConsultas)
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
  frmConProfissoes: TfrmConProfissoes;

implementation

uses Principal, ConsultasSQL;

{$R *.DFM}

procedure TfrmConProfissoes.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Profissoes2.Enabled:=true;
inherited;
end;

procedure TfrmConProfissoes.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Profissao('S','0',''));
end;

procedure TfrmConProfissoes.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Profissao('S','', edtDescricao.Text),
'Profissão não encontrada!');
end;

procedure TfrmConProfissoes.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

end.
