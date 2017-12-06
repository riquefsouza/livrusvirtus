unit CadAutores;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls;

type
  TfrmCadAutores = class(TfrmCadastros)
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
  frmCadAutores: TfrmCadAutores;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.DFM}

function TfrmCadAutores.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Autor não informado!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadAutores.btnNovoClick(Sender: TObject);
begin
  inherited;
NovoDado(ConsSQL.Autor('N',edtCodigo.Text,''));
end;

procedure TfrmCadAutores.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Autor('D',edtCodigo.Text,''));
end;

procedure TfrmCadAutores.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Autor('S',edtCodigo.Text,''),
'Autor não encontrado!');
end;

procedure TfrmCadAutores.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Autor('S',edtCodigo.Text,''),
ConsSQL.Autor('U',edtCodigo.Text,edtDescricao.Text),
ConsSQL.Autor('I',edtCodigo.Text,edtDescricao.Text),true);
end;

procedure TfrmCadAutores.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Autores1.Enabled:=true;
  inherited;
end;

end.
