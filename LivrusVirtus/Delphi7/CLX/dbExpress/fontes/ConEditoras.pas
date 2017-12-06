unit ConEditoras;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Consultas, FMTBcd, Provider, DBClient, DB, SqlExpr,
  QGrids, QDBGrids, QExtCtrls;

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

{$R *.xfm}

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
'Editora n�o encontrada!');
end;

procedure TfrmConEditoras.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

end.
