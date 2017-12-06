unit CadEnderecos;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Cadastros, Db, DBTables, StdCtrls, FMTBcd, Provider, DBClient, SqlExpr;

type
  TfrmCadEnderecos = class(TfrmCadastros)
    Label12: TLabel;
    edtBairro: TEdit;
    Label11: TLabel;
    edtCEP: TEdit;
    Label10: TLabel;
    edtCidade: TEdit;
    Label13: TLabel;
    cmbEstado: TComboBox;
    procedure btnNovoClick(Sender: TObject);
    procedure btnExcluirClick(Sender: TObject);
    procedure btnPesquisarClick(Sender: TObject);
    procedure btnSalvarClick(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure FormShow(Sender: TObject);
  private
    { Private declarations }
    procedure AdicionaCombo;
    procedure RecuperaEstado(sEstado: string);
  protected
    { protected declarations }
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
    function ValidaDados(bTodosDados: boolean): boolean; override;
  public
    { Public declarations }
  end;

var
  frmCadEnderecos: TfrmCadEnderecos;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$R *.DFM}

function TfrmCadEnderecos.ValidaDados(bTodosDados: boolean): boolean;
begin
result:=true;
if Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!') then begin
  result:=false;
  exit;
end;
if bTodosDados then begin
  if Rotinas.ValidaCampo(edtDescricao.Text,'Logradouro não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtBairro.Text,'Bairro não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtCEP.Text,'CEP não informado!') then begin
    result:=false;
    exit;
  end;
  if Rotinas.ValidaCampo(edtCidade.Text,'Cidade não informada!') then begin
    result:=false;
    exit;
  end;
end;
end;

procedure TfrmCadEnderecos.InformaLimpaDados(bInformar: boolean);
begin
inherited InformaLimpaDados(bInformar);
if bInformar then begin
  edtBairro.Text:=CDSConsulta.Fields[2].AsString;
  edtCEP.Text:=CDSConsulta.Fields[3].AsString;
  edtCidade.Text:=CDSConsulta.Fields[4].AsString;
  RecuperaEstado(CDSConsulta.Fields[5].AsString);
end else begin
  edtBairro.Clear;
  edtCEP.Clear;
  edtCidade.Clear;
  cmbEstado.itemindex:=0;
end;
end;

procedure TfrmCadEnderecos.HabilitaDados(bHabilita: boolean);
begin
inherited HabilitaDados(bHabilita);
edtBairro.Enabled:=bHabilita;
edtCEP.Enabled:=bHabilita;
edtCidade.Enabled:=bHabilita;
cmbEstado.Enabled:=bHabilita;
end;

procedure TfrmCadEnderecos.btnNovoClick(Sender: TObject);
begin
  inherited;
NovoDado(ConsSQL.Endereco('N',edtCodigo.Text,'','','','',''));
end;

procedure TfrmCadEnderecos.btnExcluirClick(Sender: TObject);
begin
  inherited;
ExcluirDados(ConsSQL.Endereco('D',edtCodigo.Text,'','','','',''));
end;

procedure TfrmCadEnderecos.btnPesquisarClick(Sender: TObject);
begin
  inherited;
PesquisarDados(ConsSQL.Endereco('S',edtCodigo.Text,'','','','',''),
'Endereço não encontrado!');
end;

procedure TfrmCadEnderecos.btnSalvarClick(Sender: TObject);
begin
  inherited;
SalvarDados(ConsSQL.Endereco('S',edtCodigo.Text,'','','','',''),
ConsSQL.Endereco('U',edtCodigo.Text,edtDescricao.Text,
edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text),
ConsSQL.Endereco('I',edtCodigo.Text,edtDescricao.Text,
edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text),true);
end;

procedure TfrmCadEnderecos.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
  frmPrincipal.Enderecos1.Enabled:=true;
  inherited;
end;

procedure TfrmCadEnderecos.AdicionaCombo;
begin
cmbEstado.Items.Append('Pernambuco');
cmbEstado.Items.Append('Acre');
cmbEstado.Items.Append('Alagoas');
cmbEstado.Items.Append('Amapá');
cmbEstado.Items.Append('Amazonas');
cmbEstado.Items.Append('Bahia');
cmbEstado.Items.Append('Brasília');
cmbEstado.Items.Append('Ceará');
cmbEstado.Items.Append('Distrito Federal');
cmbEstado.Items.Append('Espírito Santo');
cmbEstado.Items.Append('Goiás');
cmbEstado.Items.Append('Mato Grosso');
cmbEstado.Items.Append('Mato Grosso do Sul');
cmbEstado.Items.Append('Minas Gerais');
cmbEstado.Items.Append('Pará');
cmbEstado.Items.Append('Paraíba');
cmbEstado.Items.Append('Paraná');
cmbEstado.Items.Append('Santa Catarina');
cmbEstado.Items.Append('Rio Grande do Norte');
cmbEstado.Items.Append('Rio Grande do Sul');
cmbEstado.Items.Append('Rio de Janeiro');
cmbEstado.Items.Append('Rondônia');
cmbEstado.Items.Append('Roraima');
cmbEstado.Items.Append('São Paulo');
cmbEstado.Items.Append('Sergipe');
cmbEstado.Items.Append('Tocantins');
end;

procedure TfrmCadEnderecos.RecuperaEstado(sEstado: string);
var nCont: integer;
begin
 for nCont:=0 to cmbEstado.Items.Count-1 do begin
    if cmbEstado.Items.Strings[nCont]=sEstado then begin
       cmbEstado.ItemIndex:=nCont;
       break; 	
    end; 
 end;
end;

procedure TfrmCadEnderecos.FormShow(Sender: TObject);
begin
  inherited;
AdicionaCombo;
cmbEstado.ItemIndex:=0;
end;

end.
