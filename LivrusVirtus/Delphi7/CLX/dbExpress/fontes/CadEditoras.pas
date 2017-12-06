unit CadEditoras;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms, 
  QDialogs, QStdCtrls, Cadastros, FMTBcd, DB, SqlExpr;

type
  TfrmCadEditoras = class(TfrmCadastros)
    procedure btnNovoClick(Sender: TObject);
    procedure btnExcluirClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure btnSalvarClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
  private
    { Private declarations }
  protected
    { protected declarations }
    function ValidaDados(bTodosDados: boolean): boolean; override;
  public
    { Public declarations }
  end;

var
  frmCadEditoras: TfrmCadEditoras;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.xfm}

function TfrmCadEditoras.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Editora não informada!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadEditoras.btnNovoClick(Sender: TObject);
begin
  inherited;
NovoDado(ConsSQL.Editora('N',edtCodigo.Text,''));
end;

procedure TfrmCadEditoras.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Editora('D',edtCodigo.Text,''));
end;

procedure TfrmCadEditoras.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Editora('S',edtCodigo.Text,''),
'Editora não encontrada!');
end;

procedure TfrmCadEditoras.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Editora('S',edtCodigo.Text,''),
ConsSQL.Editora('U',edtCodigo.Text,edtDescricao.Text),
ConsSQL.Editora('I',edtCodigo.Text,edtDescricao.Text),true);
end;

procedure TfrmCadEditoras.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Editoras1.Enabled:=true;
  inherited;
end;

end.
