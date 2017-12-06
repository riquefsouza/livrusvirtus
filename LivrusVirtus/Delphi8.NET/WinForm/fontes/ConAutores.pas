unit ConAutores;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Consultas, System.Globalization;

type
  frmConAutores = class(Consultas.frmConsultas)
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
    procedure frmConAutores_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure frmConAutores_Load(sender: System.Object; e: System.EventArgs);
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

  [assembly: RuntimeRequiredAttribute(TypeOf(frmConAutores))]

var fConAutores: frmConAutores;

implementation

uses ConsultasSQL, Principal;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmConAutores.InitializeComponent;
begin
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).BeginInit;
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).BeginInit;
  // 
  // btnPesquisar
  // 
  Self.btnPesquisar.Name := 'btnPesquisar';
  Include(Self.btnPesquisar.Click, Self.btnPesquisar_Click);
  // 
  // labDescricao
  // 
  Self.labDescricao.Name := 'labDescricao';
  Self.labDescricao.Text := 'Autor:';
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
  // frmConAutores
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(360, 237);
  Self.Name := 'frmConAutores';
  Self.Text := 'Consulta de Autores';
  Include(Self.Closing, Self.frmConAutores_Closing);
  Include(Self.Load, Self.frmConAutores_Load);
  (System.ComponentModel.ISupportInitialize(Self.gridConsulta)).EndInit;
  (System.ComponentModel.ISupportInitialize(Self.dsConsulta)).EndInit;
end;
{$ENDREGION}

procedure frmConAutores.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmConAutores.Create;
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

procedure frmConAutores.frmConAutores_Load(sender: System.Object; e: System.EventArgs);
begin
  btnLimpar_Click(Self, nil);
end;

procedure frmConAutores.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Autor('S','', edtDescricao.Text),
  'Autor não encontrado!');
end;

procedure frmConAutores.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
  LimparDados(ConsSQL.Autor('S','0',''));
end;

procedure frmConAutores.frmConAutores_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuConAutores.Enabled:=true;
end;

end.
