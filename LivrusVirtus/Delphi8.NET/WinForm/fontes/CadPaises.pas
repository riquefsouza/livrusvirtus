unit CadPaises;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Cadastros;

type
  frmCadPaises = class(Cadastros.frmCadastros)
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
    procedure frmCadPaises_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnSalvar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnNovo_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
    function ValidaDados(bTodosDados: boolean): boolean; override;
  private
    { Private Declarations }
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmCadPaises))]

var fCadPaises: frmCadPaises;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmCadPaises.InitializeComponent;
begin
  // 
  // labCodigo
  // 
  Self.labCodigo.Name := 'labCodigo';
  // 
  // edtCodigo
  // 
  Self.edtCodigo.MaxLength := 3;
  Self.edtCodigo.Name := 'edtCodigo';
  // 
  // labDescricao
  // 
  Self.labDescricao.Name := 'labDescricao';
  // 
  // edtDescricao
  // 
  Self.edtDescricao.Name := 'edtDescricao';
  // 
  // btnNovo
  // 
  Self.btnNovo.Name := 'btnNovo';
  // 
  // btnPesquisar
  // 
  Self.btnPesquisar.Name := 'btnPesquisar';
  // 
  // btnAnterior
  // 
  Self.btnAnterior.Name := 'btnAnterior';
  // 
  // btnProximo
  // 
  Self.btnProximo.Name := 'btnProximo';
  // 
  // btnFechar
  // 
  Self.btnFechar.Name := 'btnFechar';
  // 
  // btnLimpar
  // 
  Self.btnLimpar.Name := 'btnLimpar';
  // 
  // btnExcluir
  // 
  Self.btnExcluir.Name := 'btnExcluir';
  // 
  // btnSalvar
  // 
  Self.btnSalvar.Name := 'btnSalvar';
  // 
  // frmCadPaises
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(336, 133);
  Self.Name := 'frmCadPaises';
  Self.Text := 'Cadastro de Países';
  Include(Self.Closing, Self.frmCadPaises_Closing);
end;
{$ENDREGION}

procedure frmCadPaises.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmCadPaises.Create;
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

function frmCadPaises.ValidaDados(bTodosDados: boolean): boolean;
begin
  result:=true;
  if (Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!')) then
    result:=false;
  if (bTodosDados) then begin
    if (Rotinas.ValidaCampo(edtDescricao.Text,'País não informado!')) then
    result:=false;
  end;
end;

procedure frmCadPaises.btnNovo_Click(sender: System.Object; e: System.EventArgs);
begin
  edtCodigo.Clear;
  edtCodigo.Enabled:=true;
  edtCodigo.Focus;
end;

procedure frmCadPaises.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Pais('S',edtCodigo.Text,''),
  'País não encontrado!');
end;

procedure frmCadPaises.btnSalvar_Click(sender: System.Object; e: System.EventArgs);
begin
  SalvarDados(ConsSQL.Pais('S',edtCodigo.Text,''),
  ConsSQL.Pais('U',edtCodigo.Text,edtDescricao.Text),
  ConsSQL.Pais('I',edtCodigo.Text,edtDescricao.Text),
  true);
end;

procedure frmCadPaises.frmCadPaises_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuCadPaises.Enabled:=true;
end;

end.
