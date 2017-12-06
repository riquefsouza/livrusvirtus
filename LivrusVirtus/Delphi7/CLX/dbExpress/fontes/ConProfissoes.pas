unit ConProfissoes;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Consultas, FMTBcd, Provider, DBClient, DB, SqlExpr,
  QGrids, QDBGrids, QExtCtrls;

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

{$R *.xfm}

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
