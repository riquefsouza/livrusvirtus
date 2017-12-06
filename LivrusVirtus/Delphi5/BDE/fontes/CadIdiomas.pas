unit CadIdiomas;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls;

type
  TfrmCadIdiomas = class(TfrmCadastros)
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
  frmCadIdiomas: TfrmCadIdiomas;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.DFM}

function TfrmCadIdiomas.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Idioma não informado!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadIdiomas.btnNovoClick(Sender: TObject);
begin
  inherited;
NovoDado(ConsSQL.Idioma('N',edtCodigo.Text,''));
end;

procedure TfrmCadIdiomas.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Idioma('D',edtCodigo.Text,''));
end;

procedure TfrmCadIdiomas.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Idioma('S',edtCodigo.Text,''),
'Idioma não encontrado!');
end;

procedure TfrmCadIdiomas.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Idioma('S',edtCodigo.Text,''),
ConsSQL.Idioma('U',edtCodigo.Text,edtDescricao.Text),
ConsSQL.Idioma('I',edtCodigo.Text,edtDescricao.Text),true);
end;

procedure TfrmCadIdiomas.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Idiomas1.Enabled:=true;
  inherited;
end;


end.
