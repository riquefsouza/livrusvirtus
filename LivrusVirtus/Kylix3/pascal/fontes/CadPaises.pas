unit CadPaises;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Cadastros, FMTBcd, Provider, DBClient, DB, SqlExpr;

type
  TfrmCadPaises = class(TfrmCadastros)
    procedure btnNovoClick(Sender: TObject);
    procedure btnExcluirClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure btnSalvarClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure edtCodigoExit(Sender: TObject);
  private
    { Private declarations }
  protected
    { protected declarations }
    function ValidaDados(bTodosDados: boolean): boolean; override;
  public
    { Public declarations }
  end;

var
  frmCadPaises: TfrmCadPaises;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.xfm}

function TfrmCadPaises.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'País não informado!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadPaises.btnNovoClick(Sender: TObject);
begin
  inherited;
  edtCodigo.Text := '';
  edtCodigo.Enabled := true;
  edtCodigo.SetFocus;
end;

procedure TfrmCadPaises.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Pais('D',edtCodigo.Text,''));
end;

procedure TfrmCadPaises.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Pais('S',edtCodigo.Text,''),
'País não encontrado!');
end;

procedure TfrmCadPaises.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Pais('S',edtCodigo.Text,''),
ConsSQL.Pais('U',edtCodigo.Text,edtDescricao.Text),
ConsSQL.Pais('I',edtCodigo.Text,edtDescricao.Text),true);
end;

procedure TfrmCadPaises.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Paises1.Enabled:=true;
  inherited;
end;

procedure TfrmCadPaises.edtCodigoExit(Sender: TObject);
begin
//  inherited;
end;

end.
