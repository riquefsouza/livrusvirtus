unit ConLivros;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Consultas, FMTBcd, Provider, DBClient, DB, SqlExpr,
  QGrids, QDBGrids, QExtCtrls;

type
  TfrmConLivros = class(TfrmConsultas)
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
  frmConLivros: TfrmConLivros;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$R *.xfm}

procedure TfrmConLivros.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
if CDSConsulta.RecordCount > 0 then begin
   Rotinas.sCodigoSelecionado:=CDSConsulta.Fields[0].AsString;
   Rotinas.sPreco:=CDSConsulta.Fields[2].AsString;
   Rotinas.sQtdEstoque:=CDSConsulta.Fields[3].AsString;
end;
frmPrincipal.Livros2.Enabled:=true;
inherited;
end;

procedure TfrmConLivros.btnLimparClick(Sender: TObject);
begin
  inherited;
LimparDados(ConsSQL.Livro('Q','ZERO','','','','','','','','',''));
end;

procedure TfrmConLivros.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Livro('Q','', edtDescricao.Text,
'','','','','','','',''), 'Livro não encontrado!');
end;

procedure TfrmConLivros.FormShow(Sender: TObject);
begin
  inherited;
btnLimparClick(self);
end;

end.
