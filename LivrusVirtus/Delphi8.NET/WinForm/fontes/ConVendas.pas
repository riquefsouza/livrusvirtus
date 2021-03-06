unit ConVendas;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Consultas, System.Globalization;

type
  frmConVendas = class(Consultas.frmConsultas)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
    btnPLivro: System.Windows.Forms.Button;
    edtLivro: System.Windows.Forms.TextBox;
    edtISBN: System.Windows.Forms.TextBox;
    labISBN: System.Windows.Forms.Label;
    labDtHrVenda: System.Windows.Forms.Label;
    edtDtVenda: System.Windows.Forms.DateTimePicker;
    edtHrVenda: System.Windows.Forms.DateTimePicker;
    btnPCliente: System.Windows.Forms.Button;
    edtCliente: System.Windows.Forms.TextBox;
    labCLiente: System.Windows.Forms.Label;
    labLivro: System.Windows.Forms.Label;
    edtPrecoTotal: System.Windows.Forms.TextBox;
    labPrecoTotal: System.Windows.Forms.Label;
    ConsTotal: ArrayList;
    ConsCampo: ArrayList;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure frmConVendas_Load(sender: System.Object; e: System.EventArgs);
    procedure frmConVendas_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
    procedure edtDescricao_Leave(sender: System.Object; e: System.EventArgs);
    procedure edtISBN_Leave(sender: System.Object; e: System.EventArgs);
    procedure btnPCliente_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPLivro_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
  private
    { Private Declarations }
    function ConsVenda(sOpcao: char): string;
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmConVendas))]

var fConVendas: frmConVendas;

implementation

uses ConsultasSQL, Principal, ConLivros, ConClientes, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmConVendas.InitializeComponent;
begin
  Self.btnPLivro := System.Windows.Forms.Button.Create;
  Self.edtLivro := System.Windows.Forms.TextBox.Create;
  Self.edtISBN := System.Windows.Forms.TextBox.Create;
  Self.labISBN := System.Windows.Forms.Label.Create;
  Self.labDtHrVenda := System.Windows.Forms.Label.Create;
  Self.edtDtVenda := System.Windows.Forms.DateTimePicker.Create;
  Self.edtHrVenda := System.Windows.Forms.DateTimePicker.Create;
  Self.btnPCliente := System.Windows.Forms.Button.Create;
  Self.edtCliente := System.Windows.Forms.TextBox.Create;
  Self.labCLiente := System.Windows.Forms.Label.Create;
  Self.labLivro := System.Windows.Forms.Label.Create;
  Self.edtPrecoTotal := System.Windows.Forms.TextBox.Create;
  Self.labPrecoTotal := System.Windows.Forms.Label.Create;
  Self.panel1.SuspendLayout;
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).BeginInit;
  Self.panel2.SuspendLayout;
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).BeginInit;
  Self.SuspendLayout;
  // 
  // panel1
  // 
  Self.panel1.Anchor := (System.Windows.Forms.AnchorStyles(((System.Windows.Forms.AnchorStyles.Top 
    or System.Windows.Forms.AnchorStyles.Left) or System.Windows.Forms.AnchorStyles.Right)));
  Self.panel1.Controls.Add(Self.labLivro);
  Self.panel1.Controls.Add(Self.btnPCliente);
  Self.panel1.Controls.Add(Self.edtCliente);
  Self.panel1.Controls.Add(Self.edtHrVenda);
  Self.panel1.Controls.Add(Self.labDtHrVenda);
  Self.panel1.Controls.Add(Self.edtDtVenda);
  Self.panel1.Controls.Add(Self.btnPLivro);
  Self.panel1.Controls.Add(Self.edtLivro);
  Self.panel1.Controls.Add(Self.edtISBN);
  Self.panel1.Controls.Add(Self.labISBN);
  Self.panel1.Controls.Add(Self.labCLiente);
  Self.panel1.Dock := System.Windows.Forms.DockStyle.None;
  Self.panel1.Name := 'panel1';
  Self.panel1.Size := System.Drawing.Size.Create(1512, 136);
  Self.panel1.Controls.SetChildIndex(Self.labCLiente, 0);
  Self.panel1.Controls.SetChildIndex(Self.labISBN, 0);
  Self.panel1.Controls.SetChildIndex(Self.edtISBN, 0);
  Self.panel1.Controls.SetChildIndex(Self.edtLivro, 0);
  Self.panel1.Controls.SetChildIndex(Self.btnPLivro, 0);
  Self.panel1.Controls.SetChildIndex(Self.edtDtVenda, 0);
  Self.panel1.Controls.SetChildIndex(Self.labDtHrVenda, 0);
  Self.panel1.Controls.SetChildIndex(Self.edtHrVenda, 0);
  Self.panel1.Controls.SetChildIndex(Self.edtCliente, 0);
  Self.panel1.Controls.SetChildIndex(Self.btnPCliente, 0);
  Self.panel1.Controls.SetChildIndex(Self.labLivro, 0);
  Self.panel1.Controls.SetChildIndex(Self.labDescricao, 0);
  Self.panel1.Controls.SetChildIndex(Self.edtDescricao, 0);
  Self.panel1.Controls.SetChildIndex(Self.btnPesquisar, 0);
  // 
  // panel2
  // 
  Self.panel2.Controls.Add(Self.edtPrecoTotal);
  Self.panel2.Controls.Add(Self.labPrecoTotal);
  Self.panel2.Location := System.Drawing.Point.Create(0, 272);
  Self.panel2.Name := 'panel2';
  Self.panel2.Size := System.Drawing.Size.Create(456, 72);
  Self.panel2.Controls.SetChildIndex(Self.labPrecoTotal, 0);
  Self.panel2.Controls.SetChildIndex(Self.edtPrecoTotal, 0);
  Self.panel2.Controls.SetChildIndex(Self.btnFechar, 0);
  Self.panel2.Controls.SetChildIndex(Self.btnLimpar, 0);
  Self.panel2.Controls.SetChildIndex(Self.labRegistros, 0);
  // 
  // btnFechar
  // 
  Self.btnFechar.Anchor := (System.Windows.Forms.AnchorStyles((System.Windows.Forms.AnchorStyles.Bottom 
    or System.Windows.Forms.AnchorStyles.Right)));
  Self.btnFechar.Location := System.Drawing.Point.Create(376, 40);
  Self.btnFechar.Name := 'btnFechar';
  Self.btnFechar.TabIndex := 4;
  // 
  // labRegistros
  // 
  Self.labRegistros.Location := System.Drawing.Point.Create(11, 40);
  Self.labRegistros.Name := 'labRegistros';
  Self.labRegistros.TabIndex := 2;
  //
  // btnPesquisar
  // 
  Self.btnPesquisar.Location := System.Drawing.Point.Create(232, 24);
  Self.btnPesquisar.Name := 'btnPesquisar';
  Self.btnPesquisar.TabIndex := 3;
  Include(Self.btnPesquisar.Click, Self.btnPesquisar_Click);
  // 
  // labDescricao
  // 
  Self.labDescricao.Location := System.Drawing.Point.Create(8, 48);
  Self.labDescricao.Name := 'labDescricao';
  Self.labDescricao.TabIndex := 4;
  Self.labDescricao.Text := 'CPF:';
  // 
  // edtDescricao
  // 
  Self.edtDescricao.Location := System.Drawing.Point.Create(8, 64);
  Self.edtDescricao.MaxLength := 14;
  Self.edtDescricao.Name := 'edtDescricao';
  Self.edtDescricao.Size := System.Drawing.Size.Create(128, 20);
  Self.edtDescricao.TabIndex := 5;
  Include(Self.edtDescricao.Leave, Self.edtDescricao_Leave);
  //
  // gridConsulta
  //
  Self.gridConsulta.Location := System.Drawing.Point.Create(0, 136);
  Self.gridConsulta.Name := 'gridConsulta';
  Self.gridConsulta.Size := System.Drawing.Size.Create(456, 136);
  //
  // btnLimpar
  //
  Self.btnLimpar.Anchor := (System.Windows.Forms.AnchorStyles((System.Windows.Forms.AnchorStyles.Bottom
    or System.Windows.Forms.AnchorStyles.Right)));
  Self.btnLimpar.Location := System.Drawing.Point.Create(296, 40);
  Self.btnLimpar.Name := 'btnLimpar';
  Self.btnLimpar.TabIndex := 3;
  Include(Self.btnLimpar.Click, Self.btnLimpar_Click);
  // 
  // dsConsulta
  // 
  Self.dsConsulta.DataSetName := 'Consulta';
  Self.dsConsulta.Locale := System.Globalization.CultureInfo.Create('pt-BR');
  // 
  // btnPLivro
  // 
  Self.btnPLivro.Location := System.Drawing.Point.Create(424, 104);
  Self.btnPLivro.Name := 'btnPLivro';
  Self.btnPLivro.Size := System.Drawing.Size.Create(22, 20);
  Self.btnPLivro.TabIndex := 13;
  Self.btnPLivro.Text := '...';
  Include(Self.btnPLivro.Click, Self.btnPLivro_Click);
  // 
  // edtLivro
  // 
  Self.edtLivro.Enabled := False;
  Self.edtLivro.Location := System.Drawing.Point.Create(144, 104);
  Self.edtLivro.MaxLength := 30;
  Self.edtLivro.Name := 'edtLivro';
  Self.edtLivro.Size := System.Drawing.Size.Create(280, 20);
  Self.edtLivro.TabIndex := 12;
  Self.edtLivro.Text := '';
  // 
  // edtISBN
  // 
  Self.edtISBN.Location := System.Drawing.Point.Create(8, 104);
  Self.edtISBN.MaxLength := 13;
  Self.edtISBN.Name := 'edtISBN';
  Self.edtISBN.Size := System.Drawing.Size.Create(128, 20);
  Self.edtISBN.TabIndex := 10;
  Self.edtISBN.Text := '';
  Include(Self.edtISBN.Leave, Self.edtISBN_Leave);
  //
  // labISBN
  // 
  Self.labISBN.Location := System.Drawing.Point.Create(8, 88);
  Self.labISBN.Name := 'labISBN';
  Self.labISBN.Size := System.Drawing.Size.Create(52, 16);
  Self.labISBN.TabIndex := 9;
  Self.labISBN.Text := 'ISBN:';
  // 
  // labDtHrVenda
  // 
  Self.labDtHrVenda.Location := System.Drawing.Point.Create(8, 8);
  Self.labDtHrVenda.Name := 'labDtHrVenda';
  Self.labDtHrVenda.Size := System.Drawing.Size.Create(96, 16);
  Self.labDtHrVenda.TabIndex := 0;
  Self.labDtHrVenda.Text := 'Data/Hora Venda:';
  // 
  // edtDtVenda
  // 
  Self.edtDtVenda.Checked := False;
  Self.edtDtVenda.Format := System.Windows.Forms.DateTimePickerFormat.Short;
  Self.edtDtVenda.Location := System.Drawing.Point.Create(8, 24);
  Self.edtDtVenda.Name := 'edtDtVenda';
  Self.edtDtVenda.ShowCheckBox := True;
  Self.edtDtVenda.Size := System.Drawing.Size.Create(104, 20);
  Self.edtDtVenda.TabIndex := 1;
  // 
  // edtHrVenda
  // 
  Self.edtHrVenda.Checked := False;
  Self.edtHrVenda.Format := System.Windows.Forms.DateTimePickerFormat.Time;
  Self.edtHrVenda.Location := System.Drawing.Point.Create(120, 24);
  Self.edtHrVenda.Name := 'edtHrVenda';
  Self.edtHrVenda.ShowCheckBox := True;
  Self.edtHrVenda.ShowUpDown := True;
  Self.edtHrVenda.Size := System.Drawing.Size.Create(104, 20);
  Self.edtHrVenda.TabIndex := 2;
  // 
  // btnPCliente
  // 
  Self.btnPCliente.Location := System.Drawing.Point.Create(424, 62);
  Self.btnPCliente.Name := 'btnPCliente';
  Self.btnPCliente.Size := System.Drawing.Size.Create(22, 20);
  Self.btnPCliente.TabIndex := 8;
  Self.btnPCliente.Text := '...';
  Include(Self.btnPCliente.Click, Self.btnPCliente_Click);
  // 
  // edtCliente
  // 
  Self.edtCliente.Enabled := False;
  Self.edtCliente.Location := System.Drawing.Point.Create(144, 62);
  Self.edtCliente.MaxLength := 30;
  Self.edtCliente.Name := 'edtCliente';
  Self.edtCliente.Size := System.Drawing.Size.Create(280, 20);
  Self.edtCliente.TabIndex := 7;
  Self.edtCliente.Text := '';
  // 
  // labCLiente
  // 
  Self.labCLiente.Location := System.Drawing.Point.Create(144, 48);
  Self.labCLiente.Name := 'labCLiente';
  Self.labCLiente.Size := System.Drawing.Size.Create(52, 16);
  Self.labCLiente.TabIndex := 6;
  Self.labCLiente.Text := 'Cliente:';
  // 
  // labLivro
  // 
  Self.labLivro.Location := System.Drawing.Point.Create(144, 88);
  Self.labLivro.Name := 'labLivro';
  Self.labLivro.Size := System.Drawing.Size.Create(52, 16);
  Self.labLivro.TabIndex := 11;
  Self.labLivro.Text := 'Livro:';
  //
  // edtPrecoTotal
  // 
  Self.edtPrecoTotal.Anchor := (System.Windows.Forms.AnchorStyles((System.Windows.Forms.AnchorStyles.Top 
    or System.Windows.Forms.AnchorStyles.Right)));
  Self.edtPrecoTotal.Enabled := False;
  Self.edtPrecoTotal.Location := System.Drawing.Point.Create(312, 8);
  Self.edtPrecoTotal.MaxLength := 10;
  Self.edtPrecoTotal.Name := 'edtPrecoTotal';
  Self.edtPrecoTotal.Size := System.Drawing.Size.Create(128, 20);
  Self.edtPrecoTotal.TabIndex := 1;
  Self.edtPrecoTotal.Text := '';
  // 
  // labPrecoTotal
  // 
  Self.labPrecoTotal.Anchor := (System.Windows.Forms.AnchorStyles((System.Windows.Forms.AnchorStyles.Top 
    or System.Windows.Forms.AnchorStyles.Right)));
  Self.labPrecoTotal.Location := System.Drawing.Point.Create(240, 8);
  Self.labPrecoTotal.Name := 'labPrecoTotal';
  Self.labPrecoTotal.Size := System.Drawing.Size.Create(64, 16);
  Self.labPrecoTotal.TabIndex := 0;
  Self.labPrecoTotal.Text := 'Pre�o total:';
  // 
  // frmConVendas
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(456, 341);
  Self.Name := 'frmConVendas';
  Self.Text := 'Consulta de Vendas Realizadas';
  Include(Self.Click, Self.btnLimpar_Click);
  Include(Self.Closing, Self.frmConVendas_Closing);
  Include(Self.Load, Self.frmConVendas_Load);
  Self.panel1.ResumeLayout(False);
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).EndInit;
  Self.panel2.ResumeLayout(False);
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).EndInit;
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmConVendas.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmConVendas.Create;
begin
  inherited Create;
  //
  // Required for Windows Form Designer support
  //
  InitializeComponent;
  //
  // TODO: Add any constructor code after InitializeComponent call
  //
	ConsTotal := ArrayList.Create;
	ConsCampo := ArrayList.Create;
end;

procedure frmConVendas.btnPLivro_Click(sender: System.Object; e: System.EventArgs);
var pfConLivros: frmConLivros;
begin
  pfConLivros:=frmConLivros.Create;
  pfConLivros.ShowDialog;
  edtISBN.Text:=Rotinas.sCodigoSelecionado;
  edtISBN_Leave(Self,nil);
end;

procedure frmConVendas.btnPCliente_Click(sender: System.Object; e: System.EventArgs);
var pfConClientes: frmConClientes;
begin
    pfConClientes:=frmConClientes.Create;
    pfConClientes.ShowDialog;
    edtDescricao.Text:=Rotinas.sCodigoSelecionado;
    edtDescricao_Leave(Self,nil);
end;

procedure frmConVendas.edtISBN_Leave(sender: System.Object; e: System.EventArgs);
begin
  if edtISBN.Text<>'' then begin
    if Rotinas.ValidaISBN(edtISBN.Text) then begin
      edtLivro.Text:=Rotinas.ConsultaCampoDesc(ConsCampo,
      ConsSQL.Livro('Q',edtISBN.Text,
      '','','','','','','','',''),'Livro n�o encontrado!');
      if edtLivro.Text<>'' then begin
          if Int32.Parse(ConsCampo.Item[3].ToString) > 0 then
            Rotinas.sPreco:=ConsCampo.Item[2].ToString
          else
            MessageBox.Show(Self,'Livro n�o existe no estoque!',
            fPrincipal.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
      end else begin
          edtISBN.Clear;
          edtISBN.Focus;
      end;
    end else begin
      MessageBox.Show(Self,'ISBN inv�lido!', fPrincipal.Text,
      MessageBoxButtons.OK, MessageBoxIcon.Error);
      edtISBN.Clear;
      edtLivro.Clear;
    end;
  end;
end;

procedure frmConVendas.edtDescricao_Leave(sender: System.Object; e: System.EventArgs);
begin
  if edtDescricao.Text<>'' then begin
    if Rotinas.ValidaCPF(edtDescricao.Text) then begin
        edtCliente.Text := Rotinas.ConsultaCampoDesc(ConsCampo,
      ConsultasSQL.ConsSQL.Cliente('S',edtDescricao.Text,
      '','','','','','','','',''),'Cliente n�o encontrado!');
      if edtCliente.Text='' then begin
        edtDescricao.Clear;
        edtDescricao.Focus;
      end;
    end else begin
      MessageBox.Show(Self,'CPF inv�lido!', fPrincipal.Text,
      MessageBoxButtons.OK, MessageBoxIcon.Error);
      edtDescricao.Clear;
      edtCliente.Clear;
    end;
  end;
end;

procedure frmConVendas.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
  	edtDtVenda.Value:=DateTime.Now;
  	edtHrVenda.Value:=DateTime.Now;
  	edtDtVenda.Checked:=false;
  	edtHrVenda.Checked:=false;
  	edtCliente.Clear;
  	edtISBN.Clear;
  	edtLivro.Clear;
  	edtPrecoTotal.Text:='R$ 0,00';
  	edtDtVenda.Focus;

  	LimparDados(ConsVenda('L'));
end;

function frmConVendas.ConsVenda(sOpcao: char): string;
var sDataVenda, sHoraVenda, sDtHrVenda: string;
begin
  if edtDtVenda.Checked then
    sDataVenda:=edtDtVenda.Value.ToString('dd/MM/yyyy')
  else
    sDataVenda:='';

  if edtHrVenda.Checked then
    sHoraVenda:=edtHrVenda.Value.ToString('hh:mm:ss')
  else
    sHoraVenda:='';

  sDtHrVenda:=sDataVenda.Trim+' '+sHoraVenda.Trim;
  if sOpcao='L' then
   result:=ConsSQL.Venda('S','ZERO','','','','')
  else
   result:=ConsSQL.Venda(sOpcao,edtISBN.Text,
   edtDescricao.Text, sDtHrVenda.Trim,'','');

end;

procedure frmConVendas.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
var linhas: ArrayList;
begin
 linhas:=ArrayList.Create;

  if PesquisarDados(ConsVenda('S'),'Venda n�o encontrada!') then begin
  	 Rotinas.ConsultaDados(ConsTotal,ConsVenda('P'));
  	 if ConsTotal.Count > 0 then begin
  		linhas:= ArrayList(ConsTotal.Item[0]);
  		edtPrecoTotal.Text:='R$ '+linhas.Item[0].ToString;
  	 end;
  end;
end;

procedure frmConVendas.frmConVendas_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuVendasRealizadas.Enabled:=true;
end;

procedure frmConVendas.frmConVendas_Load(sender: System.Object; e: System.EventArgs);
begin
  btnLimpar_Click(self, nil);
end;

end.
