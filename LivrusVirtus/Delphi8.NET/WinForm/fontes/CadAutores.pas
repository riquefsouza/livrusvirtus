unit CadAutores;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Cadastros;

type
  frmCadAutores = class(Cadastros.frmCadastros)
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
    procedure btnNovo_Click(sender: System.Object; e: System.EventArgs);
    procedure btnExcluir_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnSalvar_Click(sender: System.Object; e: System.EventArgs);
    procedure frmCadAutores_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
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

  [assembly: RuntimeRequiredAttribute(TypeOf(frmCadAutores))]

var fCadAutores: frmCadAutores;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmCadAutores.InitializeComponent;
begin
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
  Self.labDescricao.Text := 'Autor:';
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
  Self.btnPesquisar.Name := 'btnPesquisar';
  Include(Self.btnPesquisar.Click, Self.btnPesquisar_Click);
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
  Include(Self.btnExcluir.Click, Self.btnExcluir_Click);
  // 
  // btnSalvar
  // 
  Self.btnSalvar.Name := 'btnSalvar';
  Include(Self.btnSalvar.Click, Self.btnSalvar_Click);
  // 
  // frmCadAutores
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(336, 133);
  Self.Name := 'frmCadAutores';
  Self.Text := 'Cadastro de Autores';
  Include(Self.Closing, Self.frmCadAutores_Closing);
end;
{$ENDREGION}

procedure frmCadAutores.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmCadAutores.Create;
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

procedure frmCadAutores.frmCadAutores_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuCadAutores.Enabled:=true;
end;

procedure frmCadAutores.btnSalvar_Click(sender: System.Object; e: System.EventArgs);
begin
  SalvarDados(ConsSQL.Autor('S',edtCodigo.Text,''),
  ConsSQL.Autor('U',edtCodigo.Text,edtDescricao.Text),
  ConsSQL.Autor('I',edtCodigo.Text,edtDescricao.Text),
  true);
end;

procedure frmCadAutores.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Autor('S',edtCodigo.Text,''),'Autor não encontrado!');
end;

procedure frmCadAutores.btnExcluir_Click(sender: System.Object; e: System.EventArgs);
begin
  ExcluirDados(ConsSQL.Autor('D',edtCodigo.Text,''));
end;

procedure frmCadAutores.btnNovo_Click(sender: System.Object; e: System.EventArgs);
begin
  NovoDado(ConsSQL.Autor('N',edtCodigo.Text,''));
end;

function frmCadAutores.ValidaDados(bTodosDados: boolean): boolean;
begin
  result:=true;
  if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text,
    'Código não informado!')) then
    result:=false;
  if (bTodosDados) then begin
    if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text,
    'Autor não informado!')) then
    result:=false;
  end;
end;


end.
