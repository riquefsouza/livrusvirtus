unit ConEnderecos;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Consultas, FMTBcd, Provider, DBClient, DB, SqlExpr,
  QGrids, QDBGrids, QExtCtrls;

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

{$R *.xfm}

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
