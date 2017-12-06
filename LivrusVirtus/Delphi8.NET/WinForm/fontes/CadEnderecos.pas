unit CadEnderecos;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Cadastros;

type
  frmCadEnderecos = class(Cadastros.frmCadastros)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
    labBairro: System.Windows.Forms.Label;
    edtBairro: System.Windows.Forms.TextBox;
    edtCEP: System.Windows.Forms.TextBox;
    labCEP: System.Windows.Forms.Label;
    edtCidade: System.Windows.Forms.TextBox;
    labCidade: System.Windows.Forms.Label;
    labEstado: System.Windows.Forms.Label;
    cmbEstado: System.Windows.Forms.ComboBox;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure frmCadEnderecos_Load(sender: System.Object; e: System.EventArgs);
    procedure frmCadEnderecos_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnNovo_Click(sender: System.Object; e: System.EventArgs);
    procedure btnExcluir_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnSalvar_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
    function ValidaDados(bTodosDados: boolean): boolean; override;
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
  private
    { Private Declarations }
    procedure AdicionaCombo;
    procedure RecuperaEstado(sEstado: string);
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmCadEnderecos))]

var fCadEnderecos: frmCadEnderecos;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmCadEnderecos.InitializeComponent;
begin
  Self.labBairro := System.Windows.Forms.Label.Create;
  Self.edtBairro := System.Windows.Forms.TextBox.Create;
  Self.edtCEP := System.Windows.Forms.TextBox.Create;
  Self.labCEP := System.Windows.Forms.Label.Create;
  Self.edtCidade := System.Windows.Forms.TextBox.Create;
  Self.labCidade := System.Windows.Forms.Label.Create;
  Self.labEstado := System.Windows.Forms.Label.Create;
  Self.cmbEstado := System.Windows.Forms.ComboBox.Create;
  Self.SuspendLayout;
  // 
  // labCodigo
  // 
  Self.labCodigo.Name := 'labCodigo';
  // 
  // edtCodigo
  // 
  Self.edtCodigo.Name := 'edtCodigo';
  // 
  // labDescricao
  // 
  Self.labDescricao.Name := 'labDescricao';
  Self.labDescricao.Text := 'Logradouro:';
  // 
  // edtDescricao
  // 
  Self.edtDescricao.Name := 'edtDescricao';
  // 
  // btnNovo
  // 
  Self.btnNovo.Name := 'btnNovo';
  Include(Self.btnNovo.Click, Self.btnNovo_Click);
  // 
  // btnPesquisar
  // 
  Self.btnPesquisar.Location := System.Drawing.Point.Create(440, 8);
  Self.btnPesquisar.Name := 'btnPesquisar';
  Include(Self.btnPesquisar.Click, Self.btnPesquisar_Click);
  // 
  // btnAnterior
  // 
  Self.btnAnterior.Location := System.Drawing.Point.Create(440, 40);
  Self.btnAnterior.Name := 'btnAnterior';
  // 
  // btnProximo
  // 
  Self.btnProximo.Location := System.Drawing.Point.Create(440, 72);
  Self.btnProximo.Name := 'btnProximo';
  // 
  // btnFechar
  // 
  Self.btnFechar.Location := System.Drawing.Point.Create(440, 136);
  Self.btnFechar.Name := 'btnFechar';
  // 
  // btnLimpar
  // 
  Self.btnLimpar.Location := System.Drawing.Point.Create(360, 136);
  Self.btnLimpar.Name := 'btnLimpar';
  // 
  // btnExcluir
  // 
  Self.btnExcluir.Location := System.Drawing.Point.Create(280, 136);
  Self.btnExcluir.Name := 'btnExcluir';
  Include(Self.btnExcluir.Click, Self.btnExcluir_Click);
  // 
  // btnSalvar
  // 
  Self.btnSalvar.Location := System.Drawing.Point.Create(200, 136);
  Self.btnSalvar.Name := 'btnSalvar';
  Include(Self.btnSalvar.Click, Self.btnSalvar_Click);
  // 
  // labBairro
  // 
  Self.labBairro.Location := System.Drawing.Point.Create(280, 48);
  Self.labBairro.Name := 'labBairro';
  Self.labBairro.Size := System.Drawing.Size.Create(64, 16);
  Self.labBairro.TabIndex := 5;
  Self.labBairro.Text := 'Bairro:';
  // 
  // edtBairro
  // 
  Self.edtBairro.Enabled := False;
  Self.edtBairro.Location := System.Drawing.Point.Create(280, 64);
  Self.edtBairro.MaxLength := 15;
  Self.edtBairro.Name := 'edtBairro';
  Self.edtBairro.Size := System.Drawing.Size.Create(152, 20);
  Self.edtBairro.TabIndex := 6;
  Self.edtBairro.Text := '';
  // 
  // edtCEP
  // 
  Self.edtCEP.Enabled := False;
  Self.edtCEP.Location := System.Drawing.Point.Create(8, 104);
  Self.edtCEP.MaxLength := 8;
  Self.edtCEP.Name := 'edtCEP';
  Self.edtCEP.Size := System.Drawing.Size.Create(72, 20);
  Self.edtCEP.TabIndex := 8;
  Self.edtCEP.Text := '';
  // 
  // labCEP
  // 
  Self.labCEP.Location := System.Drawing.Point.Create(8, 88);
  Self.labCEP.Name := 'labCEP';
  Self.labCEP.Size := System.Drawing.Size.Create(64, 16);
  Self.labCEP.TabIndex := 7;
  Self.labCEP.Text := 'CEP:';
  // 
  // edtCidade
  // 
  Self.edtCidade.Enabled := False;
  Self.edtCidade.Location := System.Drawing.Point.Create(88, 104);
  Self.edtCidade.MaxLength := 30;
  Self.edtCidade.Name := 'edtCidade';
  Self.edtCidade.Size := System.Drawing.Size.Create(184, 20);
  Self.edtCidade.TabIndex := 10;
  Self.edtCidade.Text := '';
  // 
  // labCidade
  // 
  Self.labCidade.Location := System.Drawing.Point.Create(88, 88);
  Self.labCidade.Name := 'labCidade';
  Self.labCidade.Size := System.Drawing.Size.Create(64, 16);
  Self.labCidade.TabIndex := 9;
  Self.labCidade.Text := 'Cidade:';
  // 
  // labEstado
  // 
  Self.labEstado.Location := System.Drawing.Point.Create(280, 88);
  Self.labEstado.Name := 'labEstado';
  Self.labEstado.Size := System.Drawing.Size.Create(64, 16);
  Self.labEstado.TabIndex := 11;
  Self.labEstado.Text := 'Estado:';
  // 
  // cmbEstado
  // 
  Self.cmbEstado.DropDownStyle := System.Windows.Forms.ComboBoxStyle.DropDownList;
  Self.cmbEstado.Enabled := False;
  Self.cmbEstado.Location := System.Drawing.Point.Create(280, 104);
  Self.cmbEstado.Name := 'cmbEstado';
  Self.cmbEstado.Size := System.Drawing.Size.Create(152, 21);
  Self.cmbEstado.TabIndex := 12;
  // 
  // frmCadEnderecos
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(520, 165);
  Self.Controls.Add(Self.edtCidade);
  Self.Controls.Add(Self.edtCEP);
  Self.Controls.Add(Self.edtBairro);
  Self.Controls.Add(Self.cmbEstado);
  Self.Controls.Add(Self.labEstado);
  Self.Controls.Add(Self.labCidade);
  Self.Controls.Add(Self.labCEP);
  Self.Controls.Add(Self.labBairro);
  Self.Name := 'frmCadEnderecos';
  Self.Text := 'Cadastro de Endereços';
  Include(Self.Closing, Self.frmCadEnderecos_Closing);
  Include(Self.Load, Self.frmCadEnderecos_Load);
  Self.Controls.SetChildIndex(Self.labBairro, 0);
  Self.Controls.SetChildIndex(Self.labCEP, 0);
  Self.Controls.SetChildIndex(Self.labCidade, 0);
  Self.Controls.SetChildIndex(Self.labEstado, 0);
  Self.Controls.SetChildIndex(Self.cmbEstado, 0);
  Self.Controls.SetChildIndex(Self.edtBairro, 0);
  Self.Controls.SetChildIndex(Self.edtCEP, 0);
  Self.Controls.SetChildIndex(Self.edtCidade, 0);
  Self.Controls.SetChildIndex(Self.labCodigo, 0);
  Self.Controls.SetChildIndex(Self.edtCodigo, 0);
  Self.Controls.SetChildIndex(Self.labDescricao, 0);
  Self.Controls.SetChildIndex(Self.edtDescricao, 0);
  Self.Controls.SetChildIndex(Self.btnNovo, 0);
  Self.Controls.SetChildIndex(Self.btnPesquisar, 0);
  Self.Controls.SetChildIndex(Self.btnAnterior, 0);
  Self.Controls.SetChildIndex(Self.btnProximo, 0);
  Self.Controls.SetChildIndex(Self.btnFechar, 0);
  Self.Controls.SetChildIndex(Self.btnLimpar, 0);
  Self.Controls.SetChildIndex(Self.btnExcluir, 0);
  Self.Controls.SetChildIndex(Self.btnSalvar, 0);
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmCadEnderecos.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmCadEnderecos.Create;
begin
  inherited Create;
  //
  // Required for Windows Form Designer support
  //
  InitializeComponent;
  //
  // TODO: Add any constructor code after InitializeComponent call
  //
end;

procedure frmCadEnderecos.btnSalvar_Click(sender: System.Object; e: System.EventArgs);
begin
  SalvarDados(ConsSQL.Endereco('S',edtCodigo.Text,
  '','','','',''),
  ConsSQL.Endereco('U',edtCodigo.Text,edtDescricao.Text,
  edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text),
  ConsSQL.Endereco('I',edtCodigo.Text,edtDescricao.Text,
  edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text),
  true);
end;

procedure frmCadEnderecos.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Endereco('S',edtCodigo.Text,
  '','','','',''),'Endereço não encontrado!');
end;

procedure frmCadEnderecos.btnExcluir_Click(sender: System.Object; e: System.EventArgs);
begin
  ExcluirDados(ConsSQL.Endereco('D',edtCodigo.Text,'','','','',''));
end;

procedure frmCadEnderecos.btnNovo_Click(sender: System.Object; e: System.EventArgs);
begin
  NovoDado(ConsSQL.Endereco('N',edtCodigo.Text,'','','','',''));
end;

procedure frmCadEnderecos.frmCadEnderecos_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuCadEnderecos.Enabled:=true;
end;

procedure frmCadEnderecos.frmCadEnderecos_Load(sender: System.Object; e: System.EventArgs);
begin
  AdicionaCombo;
  cmbEstado.SelectedIndex:=0;
end;

function frmCadEnderecos.ValidaDados(bTodosDados: boolean): boolean;
begin
  if (Rotinas.ValidaCampo(edtCodigo.Text, 'Código não informado!')) then
    result:=false;
  if (bTodosDados) then begin
    if (Rotinas.ValidaCampo(edtDescricao.Text, 'Logradouro não informado!')) then
  	result:=false;
    if (Rotinas.ValidaCampo(edtBairro.Text, 'Bairro não informado!')) then
  	result:=false;
    if (Rotinas.ValidaCampo(edtCEP.Text, 'CEP não informado!')) then
  	result:=false;
    if (Rotinas.ValidaCampo(edtCidade.Text, 'Cidade não informada!')) then
  	result:=false;
  end;
  result:=true;
end;

procedure frmCadEnderecos.InformaLimpaDados(bInformar: boolean);
begin
  inherited InformaLimpaDados(bInformar);
  
  if bInformar then begin
    edtBairro.Text:=Campos.Item[2].ToString;
    edtCEP.Text:=Campos.Item[3].ToString;
    edtCidade.Text:=Campos.Item[4].ToString;
    RecuperaEstado(Campos.Item[5].ToString);
  end else begin
    edtBairro.Clear;
    edtCEP.Clear;
    edtCidade.Clear;
    cmbEstado.SelectedIndex:=0;
  end;
end;

procedure frmCadEnderecos.HabilitaDados(bHabilita: boolean);
begin
  inherited HabilitaDados(bHabilita);
  
  edtBairro.Enabled:=bHabilita;
  edtCEP.Enabled:=bHabilita;
  edtCidade.Enabled:=bHabilita;
  cmbEstado.Enabled:=bHabilita;
end;

procedure frmCadEnderecos.AdicionaCombo;
begin
  cmbEstado.Items.Add('Pernambuco');
  cmbEstado.Items.Add('Acre');
  cmbEstado.Items.Add('Alagoas');
  cmbEstado.Items.Add('Amapá');
  cmbEstado.Items.Add('Amazonas');
  cmbEstado.Items.Add('Bahia');
  cmbEstado.Items.Add('Brasília');
  cmbEstado.Items.Add('Ceará');
  cmbEstado.Items.Add('Distrito Federal');
  cmbEstado.Items.Add('Espírito Santo');
  cmbEstado.Items.Add('Goiás');
  cmbEstado.Items.Add('Mato Grosso');
  cmbEstado.Items.Add('Mato Grosso do Sul');
  cmbEstado.Items.Add('Minas Gerais');
  cmbEstado.Items.Add('Pará');
  cmbEstado.Items.Add('Paraíba');
  cmbEstado.Items.Add('Paraná');
  cmbEstado.Items.Add('Santa Catarina');
  cmbEstado.Items.Add('Rio Grande do Norte');
  cmbEstado.Items.Add('Rio Grande do Sul');
  cmbEstado.Items.Add('Rio de Janeiro');
  cmbEstado.Items.Add('Rondônia');
  cmbEstado.Items.Add('Roraima');
  cmbEstado.Items.Add('São Paulo');
  cmbEstado.Items.Add('Sergipe');
  cmbEstado.Items.Add('Tocantins');
end;

procedure frmCadEnderecos.RecuperaEstado(sEstado: string);
var nCont: integer;
begin
 for nCont:=0 to cmbEstado.Items.Count-1 do begin
    if cmbEstado.Items[nCont].ToString=sEstado then begin
       cmbEstado.SelectedIndex:=nCont;
       break;
    end;
 end;
end;

end.
