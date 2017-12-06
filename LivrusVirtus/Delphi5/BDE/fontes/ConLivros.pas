unit ConLivros;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Consultas, Db, DBTables, Grids, DBGrids, StdCtrls, ExtCtrls;

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

{$R *.DFM}

procedure TfrmConLivros.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
if Consulta.RecordCount > 0 then begin
   Rotinas.sCodigoSelecionado:=Consulta.Fields[0].AsString;
   Rotinas.sPreco:=Consulta.Fields[2].AsString;
   Rotinas.sQtdEstoque:=Consulta.Fields[3].AsString;
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
