unit ConProfissoes;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Consultas, System.Globalization;

type
  frmConProfissoes = class(Consultas.frmConsultas)
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
    procedure frmConProfissoes_Load(sender: System.Object; e: System.EventArgs);
    procedure frmConProfissoes_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
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

  [assembly: RuntimeRequiredAttribute(TypeOf(frmConProfissoes))]

var fConProfissoes: frmConProfissoes;

implementation

uses ConsultasSQL, Principal;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmConProfissoes.InitializeComponent;
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
  Self.labDescricao.Text := 'Profissão:';
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
  // frmConProfissoes
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(360, 237);
  Self.Name := 'frmConProfissoes';
  Self.Text := 'Consulta de Profissões';
  Include(Self.Closing, Self.frmConProfissoes_Closing);
  Include(Self.Load, Self.frmConProfissoes_Load);
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).EndInit;
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).EndInit;
end;
{$ENDREGION}

procedure frmConProfissoes.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmConProfissoes.Create;
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

procedure frmConProfissoes.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
  LimparDados(ConsSQL.Profissao('S','0',''));
end;

procedure frmConProfissoes.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.
	Profissao('S','', edtDescricao.Text),	'Profissão não encontrada!');
end;

procedure frmConProfissoes.frmConProfissoes_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuConProfissoes.Enabled:=true;
end;

procedure frmConProfissoes.frmConProfissoes_Load(sender: System.Object; e: System.EventArgs);
begin
  btnLimpar_Click(self, nil);
end;

end.
