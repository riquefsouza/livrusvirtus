unit ConPaises;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Consultas, FMTBcd, Provider, DBClient, DB, SqlExpr,
  QGrids, QDBGrids, QExtCtrls;

type
  TfrmConPaises = class(TfrmConsultas)
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
  frmConPaises: TfrmConPaises;

implementation

uses Principal, ConsultasSQL;

{$R *.xfm}

procedure TfrmConPaises.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.Paises2.Enabled:=true;
inherited;
end;

procedure TfrmConPaises.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Pais('S','0',''));
end;

procedure TfrmConPaises.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Pais('S','', edtDescricao.Text),
'País não encontrado!');
end;

procedure TfrmConPaises.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

end.
