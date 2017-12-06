unit CadClientes;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls, ComCtrls, ExtCtrls, FMTBcd, SqlExpr,
  Provider, DBClient, System.ComponentModel;

type
  TfrmCadClientes = class(TfrmCadastros)
    Label3: TLabel;
    Label7: TLabel;
    Label4: TLabel;
    Label6: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    edtCodPais: TEdit;
    edtPais: TEdit;
    btnPPais: TButton;
    edtCodProfissao: TEdit;
    edtProfissao: TEdit;
    btnPProfissao: TButton;
    edtEmail: TEdit;
    edtTelefone: TEdit;
    rdgSexo: TRadioGroup;
    edtDtNascimento: TDateTimePicker;
    grpEndereco: TGroupBox;
    Label5: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    edtCodEndereco: TEdit;
    edtLogradouro: TEdit;
    btnPEndereco: TButton;
    edtCidade: TEdit;
    edtCEP: TEdit;
    edtBairro: TEdit;
    edtEstado: TEdit;
    edtIdentidade: TEdit;
    procedure btnExcluirClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure btnSalvarClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure edtCodPaisExit(Sender: TObject);
    procedure edtCodProfissaoExit(Sender: TObject);
    procedure edtCodEnderecoExit(Sender: TObject);
    procedure edtCodigoExit(Sender: TObject);
    procedure btnPEnderecoClick(Sender: TObject);
    procedure btnPPaisClick(Sender: TObject);
    procedure btnPProfissaoClick(Sender: TObject);
  private
    { Private declarations }
  protected
    { protected declarations }
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
    function ValidaDados(bTodosDados: boolean): boolean; override;
  public
    { Public declarations }
  end;

var
  frmCadClientes: TfrmCadClientes;

implementation

uses RotinasGlobais, ConsultasSQL, Principal, ConEnderecos, ConPaises,
     ConProfissoes;

{$R *.DFM}

function TfrmCadClientes.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'CPF não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Nome não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtEmail.Text,'E-mail não informado!') then begin
    result:=false;
    exit;
  end;
  if rdgSexo.ItemIndex=-1 then begin
    MessageDlg('Sexo não informado!', mtInformation, [mbOk], 0);
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtTelefone.Text,'Telefone não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtCodEndereco.Text,
                         'Endereço não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtCodPais.Text,'País não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtCodProfissao.Text,
                         'Profissão não informada!') then begin
    result:=false;
    exit;
  end;
end;

end;

procedure TfrmCadClientes.InformaLimpaDados(bInformar: boolean);
begin
inherited InformaLimpaDados(bInformar);
if bInformar then begin
  edtEmail.Text:=CDSConsulta.Fields[2].AsString;
  edtIdentidade.Text:=CDSConsulta.Fields[3].AsString;
  if CDSConsulta.Fields[4].AsString='M' then
     rdgSexo.ItemIndex:=0
  else
     rdgSexo.ItemIndex:=1;
  edtTelefone.Text:=CDSConsulta.Fields[5].AsString;
  edtDtNascimento.DateTime:=CDSConsulta.Fields[6].AsDateTime;
  edtCodEndereco.Text:=CDSConsulta.Fields[7].AsString;
  edtLogradouro.Text:=CDSConsulta.Fields[8].AsString;
  edtBairro.Text:=CDSConsulta.Fields[9].AsString;
  edtCEP.Text:=CDSConsulta.Fields[10].AsString;
  edtCidade.Text:=CDSConsulta.Fields[11].AsString;
  edtEstado.Text:=CDSConsulta.Fields[12].AsString;
  edtCodPais.Text:=CDSConsulta.Fields[13].AsString;
  edtPais.Text:=CDSConsulta.Fields[14].AsString;
  edtCodProfissao.Text:=CDSConsulta.Fields[15].AsString;
  edtProfissao.Text:=CDSConsulta.Fields[16].AsString;
end else begin
  edtEmail.Clear;
  edtIdentidade.Clear;
  rdgSexo.ItemIndex:=-1;
  edtTelefone.Clear;
  edtDtNascimento.DateTime:=now;
  edtCodEndereco.Clear;
  edtLogradouro.Clear;
  edtBairro.Clear;
  edtCEP.Clear;
  edtCidade.Clear;
  edtEstado.Clear;
  edtCodPais.Clear;
  edtPais.Clear;
  edtCodProfissao.Clear;
  edtProfissao.Clear;
end;
end;

procedure TfrmCadClientes.HabilitaDados(bHabilita: boolean);
begin
inherited HabilitaDados(bHabilita);
edtEmail.Enabled:=bHabilita;
edtIdentidade.Enabled:=bHabilita;
rdgSexo.Enabled:=bHabilita;
edtTelefone.Enabled:=bHabilita;
edtDtNascimento.Enabled:=bHabilita;
edtCodEndereco.Enabled:=bHabilita;
btnPEndereco.Enabled:=bHabilita;
edtCodPais.Enabled:=bHabilita;
btnPPais.Enabled:=bHabilita;
edtCodProfissao.Enabled:=bHabilita;
btnPProfissao.Enabled:=bHabilita;
end;

procedure TfrmCadClientes.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Cliente('D',edtCodigo.Text,'','','','','','','','',''));
end;

procedure TfrmCadClientes.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Cliente('S',edtCodigo.Text,
'','','','','','','','',''), 'Cliente não encontrado!');
end;

procedure TfrmCadClientes.btnSalvarClick(Sender: TObject);
var sSexo: char;
begin
  inherited;
 if rdgSexo.ItemIndex=0 then
    sSexo:='M'
 else
    sSexo:='F';

SalvarDados(ConsSQL.Cliente('S',edtCodigo.Text,'','','','','','','','',''),
ConsSQL.Cliente('U',edtCodigo.Text,edtDescricao.Text,
edtEmail.Text,edtIdentidade.Text,sSexo,edtTelefone.Text,
FormatDateTime('mm/dd/yyyy',edtDtNascimento.DateTime),edtCodEndereco.Text,
edtCodPais.Text, edtCodProfissao.Text),
ConsSQL.Cliente('I',edtCodigo.Text,edtDescricao.Text,
edtEmail.Text,edtIdentidade.Text,sSexo,edtTelefone.Text,
FormatDateTime('mm/dd/yyyy',edtDtNascimento.DateTime),edtCodEndereco.Text,
edtCodPais.Text, edtCodProfissao.Text),true);
end;

procedure TfrmCadClientes.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.ToolButton1.Enabled:=true;
frmPrincipal.Clientes1.Enabled:=true;
  inherited;
end;

procedure TfrmCadClientes.edtCodPaisExit(Sender: TObject);
begin
  inherited;
if edtCodPais.Text<>'' then begin
  edtPais.Text:=Rotinas.ConsultaCampoDesc(Consulta,
  ConsSQL.Pais('S',edtCodPais.Text,''),'País não encontrado!');
  if edtPais.Text='' then
     edtCodPais.SetFocus;
end;
end;

procedure TfrmCadClientes.edtCodProfissaoExit(Sender: TObject);
begin
  inherited;
if edtCodProfissao.Text<>'' then begin
  edtProfissao.Text:=Rotinas.ConsultaCampoDesc(Consulta,edtCodProfissao.Text,
  ConsSQL.Profissao('S',edtCodProfissao.Text,''),'Profissão não encontrada!');
  if edtProfissao.Text='' then
     edtCodProfissao.SetFocus;
end;
end;

procedure TfrmCadClientes.edtCodEnderecoExit(Sender: TObject);
begin
  inherited;
if edtCodEndereco.Text<>'' then begin
  edtLogradouro.Text:=Rotinas.ConsultaCampoDesc(Consulta,edtCodEndereco.Text,
  ConsSQL.Endereco('S',edtCodEndereco.Text,'','','','',''),
  'Endereço não encontrado!');
  if edtLogradouro.Text='' then begin
     edtCodEndereco.SetFocus;
     edtLogradouro.Clear;
     edtBairro.Clear;
     edtCEP.Clear;
     edtCidade.Clear;
     edtEstado.Clear;
  end else begin
     edtBairro.Text:=Consulta.Fields[2].AsString;
     edtCEP.Text:=Consulta.Fields[3].AsString;
     edtCidade.Text:=Consulta.Fields[4].AsString;
     edtEstado.Text:=Consulta.Fields[5].AsString;
  end;
end;

end;

procedure TfrmCadClientes.edtCodigoExit(Sender: TObject);
begin
//  inherited;
 if edtCodigo.Text<>'' then begin
   if Rotinas.ValidaCPF(edtCodigo.Text)=false then begin
      MessageDlg('CPF inválido!', mtError, [mbOk], 0);
      edtCodigo.Clear;
      edtCodigo.SetFocus;
   end;
 end;

end;

procedure TfrmCadClientes.btnPEnderecoClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConEnderecos, frmConEnderecos);
  frmConEnderecos.ShowModal;
  edtCodEndereco.Text:=Rotinas.sCodigoSelecionado;
  edtCodEnderecoExit(self);
end;

procedure TfrmCadClientes.btnPPaisClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConPaises, frmConPaises);
  frmConPaises.ShowModal;
  edtCodPais.Text:=Rotinas.sCodigoSelecionado;
  edtCodPaisExit(self);
end;

procedure TfrmCadClientes.btnPProfissaoClick(Sender: TObject);
begin
  inherited;
  Application.CreateForm(TfrmConProfissoes, frmConProfissoes);
  frmConProfissoes.ShowModal;
  edtCodProfissao.Text:=Rotinas.sCodigoSelecionado;
  edtCodProfissaoExit(self);
end;

end.
