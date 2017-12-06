unit CadAssuntos;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls, System.ComponentModel;

type
  TfrmCadAssuntos = class(TfrmCadastros)
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
  frmCadAssuntos: TfrmCadAssuntos;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.DFM}

function TfrmCadAssuntos.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'C�digo n�o informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Assunto n�o informado!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadAssuntos.btnNovoClick(Sender: TObject);
begin
  inherited;
NovoDado(ConsSQL.Assunto('N',edtCodigo.Text,''));
end;

procedure TfrmCadAssuntos.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Assunto('D',edtCodigo.Text,''));
end;

procedure TfrmCadAssuntos.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Assunto('S',edtCodigo.Text,''),
'Assunto n�o encontrado!');
end;

procedure TfrmCadAssuntos.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Assunto('S',edtCodigo.Text,''),
ConsSQL.Assunto('U',edtCodigo.Text,edtDescricao.Text),
ConsSQL.Assunto('I',edtCodigo.Text,edtDescricao.Text),true);
end;

procedure TfrmCadAssuntos.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Assuntos1.Enabled:=true;
  inherited;
end;

end.
