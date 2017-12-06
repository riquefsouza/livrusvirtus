unit CadProfissoes;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Cadastros;

type
  frmCadProfissoes = class(Cadastros.frmCadastros)
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
    procedure frmCadProfissoes_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnNovo_Click(sender: System.Object; e: System.EventArgs);
    procedure btnSalvar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnExcluir_Click(sender: System.Object; e: System.EventArgs);
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

  [assembly: RuntimeRequiredAttribute(TypeOf(frmCadProfissoes))]

var fCadProfissoes: frmCadProfissoes;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmCadProfissoes.InitializeComponent;
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
  Self.labDescricao.Text := 'Profissão:';
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
  // frmCadProfissoes
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(336, 133);
  Self.Name := 'frmCadProfissoes';
  Self.Text := 'Cadastro de Profissões';
  Include(Self.Closing, Self.frmCadProfissoes_Closing);
end;
{$ENDREGION}

procedure frmCadProfissoes.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmCadProfissoes.Create;
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

function frmCadProfissoes.ValidaDados(bTodosDados: boolean): boolean;
begin
  result:=true;
  if (Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!')) then
    result:=false;
  if (bTodosDados) then begin
    if (Rotinas.ValidaCampo(edtDescricao.Text,'Profissão não informada!')) then
    result:=false;
  end;
end;

procedure frmCadProfissoes.btnExcluir_Click(sender: System.Object; e: System.EventArgs);
begin
  ExcluirDados(ConsSQL.Profissao('D',edtCodigo.Text,''));
end;

procedure frmCadProfissoes.btnSalvar_Click(sender: System.Object; e: System.EventArgs);
begin
  SalvarDados(ConsSQL.Profissao('S',edtCodigo.Text,''),
  ConsSQL.Profissao('U',edtCodigo.Text,edtDescricao.Text),
  ConsSQL.Profissao('I',edtCodigo.Text,edtDescricao.Text),
  true);
end;

procedure frmCadProfissoes.btnNovo_Click(sender: System.Object; e: System.EventArgs);
begin
  NovoDado(ConsSQL.Profissao('N',edtCodigo.Text,''));
end;

procedure frmCadProfissoes.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Profissao('S',edtCodigo.Text,''),
  'Profissão não encontrada!');
end;

procedure frmCadProfissoes.frmCadProfissoes_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuCadProfissoes.Enabled:=true;
end;

end.
