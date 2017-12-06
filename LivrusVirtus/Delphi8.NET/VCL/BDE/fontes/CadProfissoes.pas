unit CadProfissoes;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls, System.ComponentModel;

type
  TfrmCadProfissoes = class(TfrmCadastros)
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
  frmCadProfissoes: TfrmCadProfissoes;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.DFM}

function TfrmCadProfissoes.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Profissão não informada!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadProfissoes.btnNovoClick(Sender: TObject);
begin
  inherited;
NovoDado(ConsSQL.Profissao('N',edtCodigo.Text,''));
end;

procedure TfrmCadProfissoes.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Profissao('D',edtCodigo.Text,''));
end;

procedure TfrmCadProfissoes.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Profissao('S',edtCodigo.Text,''),
'Profissão não encontrada!');
end;

procedure TfrmCadProfissoes.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Profissao('S',edtCodigo.Text,''),
ConsSQL.Profissao('U',edtCodigo.Text,edtDescricao.Text),
ConsSQL.Profissao('I',edtCodigo.Text,edtDescricao.Text),true);
end;

procedure TfrmCadProfissoes.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Profissoes1.Enabled:=true;
  inherited;
end;

end.
