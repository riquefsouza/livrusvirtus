unit VenderLivros;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Data.OleDb;

type
  frmVenderLivros = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
    labDtHrVenda: System.Windows.Forms.Label;
    edtDtHrVenda: System.Windows.Forms.TextBox;
    labLivrosVender: System.Windows.Forms.Label;
    lstLivros: System.Windows.Forms.ListBox;
    labLivro: System.Windows.Forms.Label;
    btnPCliente: System.Windows.Forms.Button;
    edtCliente: System.Windows.Forms.TextBox;
    btnPLivro: System.Windows.Forms.Button;
    edtLivro: System.Windows.Forms.TextBox;
    edtISBN: System.Windows.Forms.TextBox;
    labISBN: System.Windows.Forms.Label;
    labCLiente: System.Windows.Forms.Label;
    edtCPF: System.Windows.Forms.TextBox;
    btnAdLivros: System.Windows.Forms.Button;
    edtPrecoTotal: System.Windows.Forms.TextBox;
    labPrecoTotal: System.Windows.Forms.Label;
    btnVender: System.Windows.Forms.Button;
    btnLimpar: System.Windows.Forms.Button;
    btnFechar: System.Windows.Forms.Button;
    labCPF: System.Windows.Forms.Label;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure edtCPF_Leave(sender: System.Object; e: System.EventArgs);
    procedure edtISBN_Leave(sender: System.Object; e: System.EventArgs);
    procedure btnPCliente_Click(sender: System.Object; e: System.EventArgs);
    procedure btnAdLivros_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPLivro_Click(sender: System.Object; e: System.EventArgs);
    procedure lstLivros_DoubleClick(sender: System.Object; e: System.EventArgs);
    procedure btnVender_Click(sender: System.Object; e: System.EventArgs);
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnFechar_Click(sender: System.Object; e: System.EventArgs);
    procedure frmVenderLivros_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure frmVenderLivros_Load(sender: System.Object; e: System.EventArgs);
    procedure frmVenderLivros_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
  private
    { Private Declarations }
    nPrecoTotal: single;
    slISBNs, slPrecos, slQtdEstoque, ConsCampo: ArrayList;
    Arquiva: System.Data.OleDb.OleDbCommand;
    procedure LimpaDados;
    function ValidaDados: boolean;
    function SalvaLista: boolean;
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmVenderLivros))]

var fVenderLivros: frmVenderLivros;

implementation

uses ConClientes, ConLivros, ConsultasSQL, RotinasGlobais, Principal;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmVenderLivros.InitializeComponent;
begin
  Self.labDtHrVenda := System.Windows.Forms.Label.Create;
  Self.edtDtHrVenda := System.Windows.Forms.TextBox.Create;
  Self.labLivrosVender := System.Windows.Forms.Label.Create;
  Self.lstLivros := System.Windows.Forms.ListBox.Create;
  Self.labLivro := System.Windows.Forms.Label.Create;
  Self.btnPCliente := System.Windows.Forms.Button.Create;
  Self.edtCliente := System.Windows.Forms.TextBox.Create;
  Self.btnPLivro := System.Windows.Forms.Button.Create;
  Self.edtLivro := System.Windows.Forms.TextBox.Create;
  Self.edtISBN := System.Windows.Forms.TextBox.Create;
  Self.labISBN := System.Windows.Forms.Label.Create;
  Self.labCLiente := System.Windows.Forms.Label.Create;
  Self.edtCPF := System.Windows.Forms.TextBox.Create;
  Self.btnAdLivros := System.Windows.Forms.Button.Create;
  Self.edtPrecoTotal := System.Windows.Forms.TextBox.Create;
  Self.labPrecoTotal := System.Windows.Forms.Label.Create;
  Self.btnVender := System.Windows.Forms.Button.Create;
  Self.btnLimpar := System.Windows.Forms.Button.Create;
  Self.btnFechar := System.Windows.Forms.Button.Create;
  Self.labCPF := System.Windows.Forms.Label.Create;
  Self.SuspendLayout;
  // 
  // labDtHrVenda
  // 
  Self.labDtHrVenda.Location := System.Drawing.Point.Create(8, 8);
  Self.labDtHrVenda.Name := 'labDtHrVenda';
  Self.labDtHrVenda.Size := System.Drawing.Size.Create(100, 16);
  Self.labDtHrVenda.TabIndex := 0;
  Self.labDtHrVenda.Text := 'Data/Hora Venda:';
  // 
  // edtDtHrVenda
  // 
  Self.edtDtHrVenda.Enabled := False;
  Self.edtDtHrVenda.Location := System.Drawing.Point.Create(8, 24);
  Self.edtDtHrVenda.Name := 'edtDtHrVenda';
  Self.edtDtHrVenda.Size := System.Drawing.Size.Create(120, 20);
  Self.edtDtHrVenda.TabIndex := 1;
  Self.edtDtHrVenda.Text := '';
  // 
  // labLivrosVender
  // 
  Self.labLivrosVender.Location := System.Drawing.Point.Create(8, 128);
  Self.labLivrosVender.Name := 'labLivrosVender';
  Self.labLivrosVender.Size := System.Drawing.Size.Create(112, 16);
  Self.labLivrosVender.TabIndex := 13;
  Self.labLivrosVender.Text := 'Livros para vender:';
  // 
  // lstLivros
  // 
  Self.lstLivros.Location := System.Drawing.Point.Create(8, 144);
  Self.lstLivros.Name := 'lstLivros';
  Self.lstLivros.Size := System.Drawing.Size.Create(464, 108);
  Self.lstLivros.TabIndex := 14;
  Include(Self.lstLivros.DoubleClick, Self.lstLivros_DoubleClick);
  // 
  // labLivro
  // 
  Self.labLivro.Location := System.Drawing.Point.Create(144, 88);
  Self.labLivro.Name := 'labLivro';
  Self.labLivro.Size := System.Drawing.Size.Create(52, 16);
  Self.labLivro.TabIndex := 9;
  Self.labLivro.Text := 'Livro:';
  // 
  // btnPCliente
  // 
  Self.btnPCliente.Location := System.Drawing.Point.Create(448, 64);
  Self.btnPCliente.Name := 'btnPCliente';
  Self.btnPCliente.Size := System.Drawing.Size.Create(22, 20);
  Self.btnPCliente.TabIndex := 6;
  Self.btnPCliente.Text := '...';
  Include(Self.btnPCliente.Click, Self.btnPCliente_Click);
  // 
  // edtCliente
  // 
  Self.edtCliente.Enabled := False;
  Self.edtCliente.Location := System.Drawing.Point.Create(144, 64);
  Self.edtCliente.MaxLength := 30;
  Self.edtCliente.Name := 'edtCliente';
  Self.edtCliente.Size := System.Drawing.Size.Create(304, 20);
  Self.edtCliente.TabIndex := 5;
  Self.edtCliente.Text := '';
  // 
  // btnPLivro
  // 
  Self.btnPLivro.Location := System.Drawing.Point.Create(448, 104);
  Self.btnPLivro.Name := 'btnPLivro';
  Self.btnPLivro.Size := System.Drawing.Size.Create(22, 20);
  Self.btnPLivro.TabIndex := 12;
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
  Self.edtLivro.TabIndex := 10;
  Self.edtLivro.Text := '';
  // 
  // edtISBN
  // 
  Self.edtISBN.Location := System.Drawing.Point.Create(8, 104);
  Self.edtISBN.MaxLength := 13;
  Self.edtISBN.Name := 'edtISBN';
  Self.edtISBN.Size := System.Drawing.Size.Create(128, 20);
  Self.edtISBN.TabIndex := 8;
  Self.edtISBN.Text := '';
  Include(Self.edtISBN.Leave, Self.edtISBN_Leave);
  // 
  // labISBN
  // 
  Self.labISBN.Location := System.Drawing.Point.Create(8, 88);
  Self.labISBN.Name := 'labISBN';
  Self.labISBN.Size := System.Drawing.Size.Create(52, 16);
  Self.labISBN.TabIndex := 7;
  Self.labISBN.Text := 'ISBN:';
  // 
  // labCLiente
  // 
  Self.labCLiente.Location := System.Drawing.Point.Create(144, 48);
  Self.labCLiente.Name := 'labCLiente';
  Self.labCLiente.Size := System.Drawing.Size.Create(52, 16);
  Self.labCLiente.TabIndex := 4;
  Self.labCLiente.Text := 'Cliente:';
  // 
  // edtCPF
  // 
  Self.edtCPF.Location := System.Drawing.Point.Create(8, 64);
  Self.edtCPF.MaxLength := 14;
  Self.edtCPF.Name := 'edtCPF';
  Self.edtCPF.Size := System.Drawing.Size.Create(128, 20);
  Self.edtCPF.TabIndex := 3;
  Self.edtCPF.Text := '';
  Include(Self.edtCPF.Leave, Self.edtCPF_Leave);
  // 
  // btnAdLivros
  // 
  Self.btnAdLivros.Location := System.Drawing.Point.Create(424, 104);
  Self.btnAdLivros.Name := 'btnAdLivros';
  Self.btnAdLivros.Size := System.Drawing.Size.Create(22, 20);
  Self.btnAdLivros.TabIndex := 11;
  Self.btnAdLivros.Text := '+';
  Include(Self.btnAdLivros.Click, Self.btnAdLivros_Click);
  // 
  // edtPrecoTotal
  // 
  Self.edtPrecoTotal.Enabled := False;
  Self.edtPrecoTotal.Location := System.Drawing.Point.Create(344, 256);
  Self.edtPrecoTotal.MaxLength := 10;
  Self.edtPrecoTotal.Name := 'edtPrecoTotal';
  Self.edtPrecoTotal.Size := System.Drawing.Size.Create(128, 20);
  Self.edtPrecoTotal.TabIndex := 16;
  Self.edtPrecoTotal.Text := '';
  // 
  // labPrecoTotal
  // 
  Self.labPrecoTotal.Location := System.Drawing.Point.Create(272, 256);
  Self.labPrecoTotal.Name := 'labPrecoTotal';
  Self.labPrecoTotal.Size := System.Drawing.Size.Create(64, 16);
  Self.labPrecoTotal.TabIndex := 15;
  Self.labPrecoTotal.Text := 'Preço total:';
  // 
  // btnVender
  // 
  Self.btnVender.Location := System.Drawing.Point.Create(240, 288);
  Self.btnVender.Name := 'btnVender';
  Self.btnVender.TabIndex := 17;
  Self.btnVender.Text := '&Vender';
  Include(Self.btnVender.Click, Self.btnVender_Click);
  // 
  // btnLimpar
  // 
  Self.btnLimpar.Location := System.Drawing.Point.Create(320, 288);
  Self.btnLimpar.Name := 'btnLimpar';
  Self.btnLimpar.TabIndex := 18;
  Self.btnLimpar.Text := '&Limpar';
  Include(Self.btnLimpar.Click, Self.btnLimpar_Click);
  // 
  // btnFechar
  // 
  Self.btnFechar.DialogResult := System.Windows.Forms.DialogResult.Cancel;
  Self.btnFechar.Location := System.Drawing.Point.Create(400, 288);
  Self.btnFechar.Name := 'btnFechar';
  Self.btnFechar.TabIndex := 19;
  Self.btnFechar.Text := '&Fechar';
  Include(Self.btnFechar.Click, Self.btnFechar_Click);
  // 
  // labCPF
  // 
  Self.labCPF.Location := System.Drawing.Point.Create(8, 48);
  Self.labCPF.Name := 'labCPF';
  Self.labCPF.Size := System.Drawing.Size.Create(100, 16);
  Self.labCPF.TabIndex := 20;
  Self.labCPF.Text := 'CPF:';
  // 
  // frmVenderLivros
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(480, 317);
  Self.Controls.Add(Self.btnVender);
  Self.Controls.Add(Self.btnLimpar);
  Self.Controls.Add(Self.btnFechar);
  Self.Controls.Add(Self.edtPrecoTotal);
  Self.Controls.Add(Self.edtCPF);
  Self.Controls.Add(Self.edtCliente);
  Self.Controls.Add(Self.edtLivro);
  Self.Controls.Add(Self.edtISBN);
  Self.Controls.Add(Self.edtDtHrVenda);
  Self.Controls.Add(Self.labPrecoTotal);
  Self.Controls.Add(Self.btnAdLivros);
  Self.Controls.Add(Self.labCPF);
  Self.Controls.Add(Self.labLivro);
  Self.Controls.Add(Self.btnPCliente);
  Self.Controls.Add(Self.btnPLivro);
  Self.Controls.Add(Self.labISBN);
  Self.Controls.Add(Self.labCLiente);
  Self.Controls.Add(Self.lstLivros);
  Self.Controls.Add(Self.labLivrosVender);
  Self.Controls.Add(Self.labDtHrVenda);
  Self.Name := 'frmVenderLivros';
  Self.Text := 'Vender Livros';
  Include(Self.Closing, Self.frmVenderLivros_Closing);
  Include(Self.Load, Self.frmVenderLivros_Load);
  Include(Self.MouseMove, Self.frmVenderLivros_MouseMove);
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmVenderLivros.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmVenderLivros.Create;
begin
  inherited Create;
  //
  // Required for Windows Form Designer support
  //
  InitializeComponent;
  //
  // TODO: Add any constructor code after InitializeComponent call
  //
	slISBNs := ArrayList.Create;
	slPrecos := ArrayList.Create;
	slQtdEstoque := ArrayList.Create;
	ConsCampo := ArrayList.Create;
	Arquiva := System.Data.OleDb.OleDbCommand.Create;
end;

procedure frmVenderLivros.frmVenderLivros_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
begin
    fPrincipal.statusBar1.Panels.Item[1].Text:=Text;
end;

procedure frmVenderLivros.frmVenderLivros_Load(sender: System.Object; e: System.EventArgs);
begin
    nPrecoTotal:=0;
    edtDtHrVenda.Text:=DateTime.Now.ToString('dd/MM/yyyy hh:mm:ss');
end;

procedure frmVenderLivros.frmVenderLivros_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
    fPrincipal.tlbVender.Enabled:=true;
    fPrincipal.mnuVenderLivros.Enabled:=true;
    fPrincipal.statusBar1.Panels.Item[1].Text:='';
end;

procedure frmVenderLivros.btnFechar_Click(sender: System.Object; e: System.EventArgs);
begin
    frmVenderLivros_Closing(Self,nil);
    Close;
end;

procedure frmVenderLivros.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
    LimpaDados;
end;

procedure frmVenderLivros.btnVender_Click(sender: System.Object; e: System.EventArgs);
begin
  if ValidaDados then begin
     if SalvaLista then begin
        MessageBox.Show(Self,'Venda realizada com sucesso!',
  			fPrincipal.Text, MessageBoxButtons.OK,MessageBoxIcon.Information);
        LimpaDados;
     end;
  end;
end;

procedure frmVenderLivros.lstLivros_DoubleClick(sender: System.Object; e: System.EventArgs);
var nPreco: single;
begin
    if lstLivros.Items.Count > 0 then begin
      nPreco:= Convert.ToSingle(slPrecos.Item[lstLivros.SelectedIndex].ToString);
      nPrecoTotal:= nPrecoTotal-nPreco;
      edtPrecoTotal.Text:= 'R$ '+Convert.ToString(nPrecoTotal);

      slISBNs.RemoveAt(lstLivros.SelectedIndex);
      slPrecos.RemoveAt(lstLivros.SelectedIndex);
      slQtdEstoque.RemoveAt(lstLivros.SelectedIndex);
      lstLivros.Items.RemoveAt(lstLivros.SelectedIndex);
    end;
end;

procedure frmVenderLivros.btnPLivro_Click(sender: System.Object; e: System.EventArgs);
var pfConLivros: frmConLivros;
begin
  pfConLivros:=frmConLivros.Create;
  pfConLivros.ShowDialog;
  edtISBN.Text:=Rotinas.sCodigoSelecionado;
  edtISBN_Leave(Self,nil);
end;

procedure frmVenderLivros.btnAdLivros_Click(sender: System.Object; e: System.EventArgs);
var sLivros: String;
begin
   if edtISBN.Text<>'' then begin
     sLivros:=edtISBN.Text+' - '+edtLivro.Text+' - R$ '+Rotinas.sPreco;
     if lstLivros.Items.IndexOf(sLivros)=-1 then begin
       slISBNs.Add(edtISBN.Text);
       slPrecos.Add(Rotinas.sPreco);
       slQtdEstoque.Add(Rotinas.sQtdEstoque);
       lstLivros.Items.Add(sLivros);
       nPrecoTotal:=nPrecoTotal+Convert.ToSingle(Rotinas.sPreco);
     end;
     edtISBN.Clear;
     edtLivro.Clear;
     edtPrecoTotal.Text:='R$ '+ Rotinas.VirgulaParaPonto(
             Convert.ToString(nPrecoTotal),true);
  end;
end;

procedure frmVenderLivros.btnPCliente_Click(sender: System.Object; e: System.EventArgs);
var pfConClientes: frmConClientes;
begin
    pfConClientes:=frmConClientes.Create;
    pfConClientes.ShowDialog;
    edtCPF.Text:=Rotinas.sCodigoSelecionado;
    edtCPF_Leave(Self,nil);
end;

procedure frmVenderLivros.edtISBN_Leave(sender: System.Object; e: System.EventArgs);
begin
  if edtISBN.Text<>'' then begin
    if Rotinas.ValidaISBN(edtISBN.Text) then begin
      edtLivro.Text:=Rotinas.ConsultaCampoDesc(ConsCampo,
      ConsSQL.Livro('Q',edtISBN.Text,
      '','','','','','','','',''),'Livro não encontrado!');
      if edtLivro.Text<>'' then begin
          if Int32.Parse(ConsCampo.Item[3].ToString()) > 0 then
            Rotinas.sPreco:=ConsCampo.Item[2].ToString
          else
            MessageBox.Show(Self,'Livro não existe no estoque!',
            fPrincipal.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
      end else begin
          edtISBN.Clear;
          edtISBN.Focus;
      end;
    end else begin
      MessageBox.Show(Self,'ISBN inválido!',
      fPrincipal.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
      edtISBN.Clear;
      edtLivro.Clear;
    end;
  end;
end;

procedure frmVenderLivros.edtCPF_Leave(sender: System.Object; e: System.EventArgs);
begin
  if edtCPF.Text<>'' then begin
    if Rotinas.ValidaCPF(edtCPF.Text) then begin
          edtCliente.Text :=
          Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Cliente('S',edtCPF.Text,
          '','','','','','','','',''),'Cliente não encontrado!');
          if edtCliente.Text='' then begin
            edtCPF.Clear;
            edtCPF.Focus;
          end;
    end else begin
          MessageBox.Show(Self,'CPF inválido!',
          fPrincipal.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
          edtCPF.Clear;
          edtCliente.Clear;
    end;
  end;
end;

procedure frmVenderLivros.LimpaDados;
begin
  edtDtHrVenda.Text:=DateTime.Now.ToString('dd/MM/yyyy hh:mm:ss');
  edtCPF.Clear;
  edtCliente.Clear;
  edtISBN.Clear;
  edtLivro.Clear;
  lstLivros.Items.Clear;
  slPrecos.Clear;
  nPrecoTotal:=0;
  edtPrecoTotal.Text:='R$ 0,00';
  edtCPF.Focus;
end;

function frmVenderLivros.ValidaDados: boolean;
begin
  result:=true;
  if (Rotinas.ValidaCampo(edtCPF.Text, 'CPF não informado!')) then
    result:=false;
  if lstLivros.Items.Count = 0 then begin
    MessageBox.Show(Self,'Livro(s) para vender não informado(s)!',
    fPrincipal.Text, MessageBoxButtons.OK, MessageBoxIcon.Error);
    result:=false;
  end;
end;

function frmVenderLivros.SalvaLista: boolean;
var nCont, nQtdEstoque: integer;
begin
try
  result:=true;
  for nCont:=0 to lstLivros.Items.Count-1 do begin
   Rotinas.ConsultaDados(Arquiva,
   ConsSQL.Venda('I',slISBNs.Item[nCont].ToString,
   edtCPF.Text, Rotinas.FormataDataStr(
   edtDtHrVenda.Text,'MM/dd/yyyy hh:mm:ss'),
   Rotinas.VirgulaParaPonto(Convert.ToString(nPrecoTotal),false),''));

   nQtdEstoque:=Int32.parse(slQtdEstoque.Item[nCont].ToString);
   nQtdEstoque:=nQtdEstoque-1;
   Rotinas.ConsultaDados(Arquiva,ConsSQL.Venda('U',slISBNs.Item[nCont].ToString,
   '','','', Convert.ToString(nQtdEstoque)));
  end;
except
 on E: Exception do begin
  MessageBox.Show(Self, E.Message, fPrincipal.Text,
  MessageBoxButtons.OK,MessageBoxIcon.Error);
  result:=false;
 end;
end;
end;

end.
