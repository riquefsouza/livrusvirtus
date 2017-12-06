unit ConLivros;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Consultas, System.Globalization;

type
  frmConLivros = class(Consultas.frmConsultas)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure frmConLivros_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
    procedure frmConLivros_Load(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
  private
    { Private Declarations }
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmConLivros))]

var fConLivros: frmConLivros;

implementation

uses ConsultasSQL, Principal, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmConLivros.InitializeComponent;
begin
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).BeginInit;
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).BeginInit;
  // 
  // panel1
  // 
  Self.panel1.Name := 'panel1';
  // 
  // panel2
  // 
  Self.panel2.Name := 'panel2';
  // 
  // btnFechar
  // 
  Self.btnFechar.Name := 'btnFechar';
  // 
  // labRegistros
  // 
  Self.labRegistros.Name := 'labRegistros';
  // 
  // btnPesquisar
  // 
  Self.btnPesquisar.Name := 'btnPesquisar';
  Include(Self.btnPesquisar.Click, Self.btnPesquisar_Click);
  // 
  // labDescricao
  // 
  Self.labDescricao.Name := 'labDescricao';
  Self.labDescricao.Text := 'Livro:';
  // 
  // edtDescricao
  // 
  Self.edtDescricao.Name := 'edtDescricao';
  // 
  // gridConsulta
  // 
  Self.gridConsulta.Name := 'gridConsulta';
  // 
  // btnLimpar
  // 
  Self.btnLimpar.Name := 'btnLimpar';
  Include(Self.btnLimpar.Click, Self.btnLimpar_Click);
  // 
  // dsConsulta
  // 
  Self.dsConsulta.DataSetName := 'Consulta';
  Self.dsConsulta.Locale := System.Globalization.CultureInfo.Create('pt-BR');
  // 
  // frmConLivros
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(360, 237);
  Self.Name := 'frmConLivros';
  Self.Text := 'Consulta de Livros';
  Include(Self.Closing, Self.frmConLivros_Closing);
  Include(Self.Load, Self.frmConLivros_Load);
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).EndInit;
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).EndInit;
end;
{$ENDREGION}

procedure frmConLivros.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmConLivros.Create;
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

procedure frmConLivros.frmConLivros_Load(sender: System.Object; e: System.EventArgs);
begin
    btnLimpar_Click(self, nil);
end;

procedure frmConLivros.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
  LimparDados(ConsSQL.Livro('S','0','','','','','','','','',''));
end;

procedure frmConLivros.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Livro('S','', edtDescricao.Text,
  '','','','','','','',''),'Livro n�o encontrado!');
end;

procedure frmConLivros.frmConLivros_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  if (dsConsulta.Tables.Item[0].Rows.Count > 0) then begin
   Campos := (ArrayList(Registros.Item[gridConsulta.CurrentCell.RowNumber]));
   Rotinas.sCodigoSelecionado:=Campos.Item[0].ToString;
   Rotinas.sPreco:=Campos.Item[2].ToString;
   Rotinas.sQtdEstoque:=Campos.Item[3].ToString;
  end;
  fPrincipal.mnuConLivros.Enabled:=true;
end;

end.
