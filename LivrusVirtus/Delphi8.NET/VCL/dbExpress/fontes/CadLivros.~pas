unit CadLivros;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls, FMTBcd, SqlExpr, Provider,
  DBClient, System.ComponentModel;

type
  TfrmCadLivros = class(TfrmCadastros)
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    edtEditora: TEdit;
    btnPEditora: TButton;
    edtCodEditora: TEdit;
    edtPreco: TEdit;
    edtCodAssunto: TEdit;
    edtAssunto: TEdit;
    btnPAssunto: TButton;
    lstAssuntos: TListBox;
    edtCodAutor: TEdit;
    edtAutor: TEdit;
    btnPAutor: TButton;
    lstAutores: TListBox;
    btnAdAssuntos: TButton;
    btnAdAutores: TButton;
    cmbIdioma: TComboBox;
    Label3: TLabel;
    ConsLista: TSQLQuery;
    edtEdicao: TEdit;
    edtAnoPubli: TEdit;
    edtVolume: TEdit;
    edtNPaginas: TEdit;
    edtQtdEstoque: TEdit;
    procedure btnExcluirClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure btnSalvarClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormShow(Sender: TObject);
    procedure edtCodEditoraExit(Sender: TObject);
    procedure edtPrecoExit(Sender: TObject);
    procedure edtCodigoExit(Sender: TObject);
    procedure edtCodAssuntoExit(Sender: TObject);
    procedure edtCodAutorExit(Sender: TObject);
    procedure btnPAssuntoClick(Sender: TObject);
    procedure btnAdAssuntosClick(Sender: TObject);
    procedure lstAssuntosDblClick(Sender: TObject);
    procedure lstAutoresDblClick(Sender: TObject);
    procedure btnAdAutoresClick(Sender: TObject);
    procedure btnPAutorClick(Sender: TObject);
    procedure btnPEditoraClick(Sender: TObject);
    procedure edtEdicaoExit(Sender: TObject);
    procedure edtAnoPubliExit(Sender: TObject);
    procedure edtVolumeExit(Sender: TObject);
    procedure edtQtdEstoqueExit(Sender: TObject);
    procedure edtNPaginasExit(Sender: TObject);
  private
    { Private declarations }
    slAssuntos, slAutores, slIdiomas: TStringList;
    procedure AdicionaCombo;
    procedure SalvaLista(sOpcao: char);
  protected
    { protected declarations }
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
    function ValidaDados(bTodosDados: boolean): boolean; override;
  public
    { Public declarations }
  end;

var
  frmCadLivros: TfrmCadLivros;

implementation

uses RotinasGlobais, ConsultasSQL, Principal, ConAssuntos, ConAutores,
  ConEditoras;

{$R *.DFM}

function TfrmCadLivros.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'ISBN não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Título não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtCodEditora.Text,'Editora não informada!') then begin
    result:=false;
    exit;
  end;
  if lstAssuntos.Items.Count = 0 then begin
    MessageDlg('Assunto(s) não informado(s)!', mtInformation, [mbOk], 0);
    result:=false;
    exit;
  end;
  if lstAutores.Items.Count = 0 then begin
    MessageDlg('Autore(s) não informado(s)!', mtInformation, [mbOk], 0);
    result:=false;
    exit;
  end;
end;

end;

procedure TfrmCadLivros.InformaLimpaDados(bInformar: boolean);
begin
inherited InformaLimpaDados(bInformar);
if bInformar then begin
  edtEdicao.Text:=CDSConsulta.Fields[2].AsString;
  edtAnoPubli.Text:=CDSConsulta.Fields[3].AsString;
  edtVolume.Text:=CDSConsulta.Fields[4].AsString;
  edtCodEditora.Text:=CDSConsulta.Fields[5].AsString;
  edtEditora.Text:=CDSConsulta.Fields[6].AsString;
  cmbIdioma.ItemIndex:=slIdiomas.IndexOf(CDSConsulta.Fields[7].AsString);
  edtNPaginas.Text:=CDSConsulta.Fields[9].AsString;
  edtPreco.Text:=CDSConsulta.Fields[10].AsString;
  edtQtdEstoque.Text:=CDSConsulta.Fields[11].AsString;
  Rotinas.AdicionaValoresLista(ConsLista,
  ConsSQL.LivroAss('S',edtCodigo.Text,''),lstAssuntos,slAssuntos);
  Rotinas.AdicionaValoresLista(ConsLista,
  ConsSQL.LivroAut('S',edtCodigo.Text,''),lstAutores,slAutores);
end else begin
  edtEdicao.Text:='1';
  edtAnoPubli.Text:=formatdatetime('yyyy',now);
  edtVolume.Text:='1';
  edtCodEditora.Clear;
  edtEditora.Clear;
  edtNPaginas.Text:='1';
  edtPreco.Text:='0,00';
  edtQtdEstoque.Text:='0';
  edtCodAssunto.Clear;
  lstAssuntos.Clear;
  edtCodAutor.Clear;
  lstAutores.Clear;
  slAssuntos.Clear;
  slAutores.Clear;
end;
end;

procedure TfrmCadLivros.HabilitaDados(bHabilita: boolean);
begin
inherited HabilitaDados(bHabilita);
edtEdicao.Enabled:=bHabilita;
edtAnoPubli.Enabled:=bHabilita;
edtVolume.Enabled:=bHabilita;
edtCodEditora.Enabled:=bHabilita;
btnPEditora.Enabled:=bHabilita;
cmbIdioma.Enabled:=bHabilita;
edtNPaginas.Enabled:=bHabilita;
edtPreco.Enabled:=bHabilita;
edtQtdEstoque.Enabled:=bHabilita;
edtCodAssunto.Enabled:=bHabilita;
btnPAssunto.Enabled:=bHabilita;
btnAdAssuntos.Enabled:=bHabilita;
lstAssuntos.Enabled:=bHabilita;
edtCodAutor.Enabled:=bHabilita;
btnPAutor.Enabled:=bHabilita;
btnAdAutores.Enabled:=bHabilita;
lstAutores.Enabled:=bHabilita;
end;

procedure TfrmCadLivros.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Livro('D',edtCodigo.Text,'','','','','','','','',''));
end;

procedure TfrmCadLivros.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Livro('S',edtCodigo.Text,'','','','','','','','',''),
'Livro não encontrado!');
end;

procedure TfrmCadLivros.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Livro('S',edtCodigo.Text,'','','','','','','','',''),
ConsSQL.Livro('U',edtCodigo.Text,edtDescricao.Text,edtEdicao.Text,
edtAnoPubli.Text,edtVolume.Text,edtCodEditora.Text,
slIdiomas.Strings[cmbIdioma.ItemIndex],edtNPaginas.Text,
Rotinas.VirgulaParaPonto(edtPreco.Text),edtQtdEstoque.Text),
ConsSQL.Livro('I',edtCodigo.Text,edtDescricao.Text,edtEdicao.Text,
edtAnoPubli.Text,edtVolume.Text,edtCodEditora.Text,
slIdiomas.Strings[cmbIdioma.ItemIndex],edtNPaginas.Text,
Rotinas.VirgulaParaPonto(edtPreco.Text),edtQtdEstoque.Text),false);
SalvaLista('A');
SalvaLista('B');
btnLimparClick(self);
end;

procedure TfrmCadLivros.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
slAssuntos.Free;
slAutores.Free;
slIdiomas.Free;

frmPrincipal.ToolButton2.Enabled:=true;
frmPrincipal.Livros1.Enabled:=true;
  inherited;
end;

procedure TfrmCadLivros.FormShow(Sender: TObject);
begin
  inherited;
slAssuntos:=TStringList.Create;
slAutores:=TStringList.Create;
slIdiomas:=TStringList.Create;

edtAnoPubli.Text:=formatdatetime('yyyy',now);
AdicionaCombo;
cmbIdioma.ItemIndex:=0;
end;

procedure TfrmCadLivros.edtCodEditoraExit(Sender: TObject);
begin
  inherited;
if edtCodEditora.Text<>'' then begin
  edtEditora.Text:=Rotinas.ConsultaCampoDesc(Consulta,edtCodEditora.Text,
  ConsSQL.Editora('S',edtCodEditora.Text,''),'Editora não encontrada!');
  if edtEditora.Text='' then
     edtCodEditora.SetFocus;
end;
end;

procedure TfrmCadLivros.edtPrecoExit(Sender: TObject);
begin
  inherited;
if Rotinas.ValidaFloat(edtPreco.Text) then
  edtPreco.Text:=FormatFloat('0.00',strtofloat(edtPreco.Text))
else
  edtPreco.Text:='0,00';
end;

procedure TfrmCadLivros.edtCodigoExit(Sender: TObject);
begin
//  inherited;
 if edtCodigo.Text<>'' then begin
   if Rotinas.ValidaISBN(edtCodigo.Text)=false then begin
      MessageDlg('ISBN inválido!', mtError, [mbOk], 0);
      edtCodigo.Clear;
      edtCodigo.SetFocus;
   end;
 end;
end;

procedure TfrmCadLivros.edtCodAssuntoExit(Sender: TObject);
begin
  inherited;
if edtCodAssunto.Text<>'' then begin
  edtAssunto.Text:=Rotinas.ConsultaCampoDesc(Consulta,edtCodAssunto.Text,
  ConsSQL.Assunto('S',edtCodAssunto.Text,''),'Assunto não encontrado!');
  if edtAssunto.Text='' then
     edtCodAssunto.SetFocus;
end;
end;

procedure TfrmCadLivros.edtCodAutorExit(Sender: TObject);
begin
  inherited;
if edtCodAutor.Text<>'' then begin
  edtAutor.Text:=Rotinas.ConsultaCampoDesc(Consulta,edtCodAutor.Text,
  ConsSQL.Autor('S',edtCodAutor.Text,''),'Autor não encontrado!');
  if edtAutor.Text='' then
     edtCodAutor.SetFocus;
end;
end;

procedure TfrmCadLivros.btnPAssuntoClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConAssuntos, frmConAssuntos);
  frmConAssuntos.ShowModal;
  edtCodAssunto.Text:=Rotinas.sCodigoSelecionado;
  edtCodAssuntoExit(self);
end;

procedure TfrmCadLivros.btnAdAssuntosClick(Sender: TObject);
begin
  inherited;
Rotinas.AdicionaItemLista(lstAssuntos,slAssuntos,edtCodAssunto,edtAssunto);
end;

procedure TfrmCadLivros.lstAssuntosDblClick(Sender: TObject);
begin
  inherited;
Rotinas.RemoveItemLista(lstAssuntos,slAssuntos);
end;

procedure TfrmCadLivros.lstAutoresDblClick(Sender: TObject);
begin
  inherited;
Rotinas.RemoveItemLista(lstAutores,slAutores);
end;

procedure TfrmCadLivros.btnAdAutoresClick(Sender: TObject);
begin
  inherited;
Rotinas.AdicionaItemLista(lstAutores,slAutores,edtCodAutor,edtAutor);
end;

procedure TfrmCadLivros.SalvaLista(sOpcao: char);
var nCont: integer;
begin
if sOpcao='A' then begin
 Arquiva.Sql.Text:=ConsSQL.LivroAss('D',edtCodigo.Text,'');
 Arquiva.ExecSql;
 for nCont:=0 to slAssuntos.Count-1 do begin
  Arquiva.Sql.Text:=ConsSQL.LivroAss('I',edtCodigo.Text,
  slAssuntos.Strings[nCont]);
  Arquiva.ExecSql;
 end;
end else if sOpcao='B' then begin
 Arquiva.Sql.Text:=ConsSQL.LivroAut('D',edtCodigo.Text,'');
 Arquiva.ExecSql;
 for nCont:=0 to slAutores.Count-1 do begin
  Arquiva.Sql.Text:=ConsSQL.LivroAut('I',edtCodigo.Text,
  slAutores.Strings[nCont]);
  Arquiva.ExecSql;
 end;
end;

end;

procedure TfrmCadLivros.btnPAutorClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConAutores, frmConAutores);
  frmConAutores.ShowModal;
  edtCodAutor.Text:=Rotinas.sCodigoSelecionado;
  edtCodAutorExit(self);
end;

procedure TfrmCadLivros.btnPEditoraClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConEditoras, frmConEditoras);
  frmConEditoras.ShowModal;
  edtCodEditora.Text:=Rotinas.sCodigoSelecionado;
  edtCodEditoraExit(self);
end;

procedure TfrmCadLivros.AdicionaCombo;
begin
Consulta.Close;
Consulta.Sql.Text:=ConsSQL.Idioma('S','','');
Consulta.Open;
 while not Consulta.eof do begin
  slIdiomas.Append(Consulta.Fields[0].AsString);
  cmbIdioma.Items.Append(Consulta.Fields[1].AsString);
  Consulta.Next;
 end;
end;

procedure TfrmCadLivros.edtEdicaoExit(Sender: TObject);
begin
  inherited;
  if Rotinas.ValidaInteger(edtEdicao.Text)=false then
    edtEdicao.Text:='1';
end;

procedure TfrmCadLivros.edtAnoPubliExit(Sender: TObject);
begin
  inherited;
  if Rotinas.ValidaInteger(edtAnoPubli.Text)=false then
    edtAnoPubli.Text:=FormatDateTime('yyyy',now);
end;

procedure TfrmCadLivros.edtVolumeExit(Sender: TObject);
begin
  inherited;
  if Rotinas.ValidaInteger(edtVolume.Text)=false then
    edtVolume.Text:='1';
end;

procedure TfrmCadLivros.edtQtdEstoqueExit(Sender: TObject);
begin
  inherited;
  if Rotinas.ValidaInteger(edtQtdEstoque.Text)=false then
    edtQtdEstoque.Text:='0';
end;

procedure TfrmCadLivros.edtNPaginasExit(Sender: TObject);
begin
  inherited;
  if Rotinas.ValidaInteger(edtNPaginas.Text)=false then
    edtNPaginas.Text:='1';
end;

end.
