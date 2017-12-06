unit CadIdiomas;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, Cadastros;

type
  frmCadIdiomas = class(Cadastros.frmCadastros)
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
    procedure frmCadIdiomas_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnSalvar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnExcluir_Click(sender: System.Object; e: System.EventArgs);
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

  [assembly: RuntimeRequiredAttribute(TypeOf(frmCadIdiomas))]

var fCadIdiomas: frmCadIdiomas;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmCadIdiomas.InitializeComponent;
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
  Self.labDescricao.Text := 'Idioma:';
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
  // frmCadIdiomas
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(336, 133);
  Self.Name := 'frmCadIdiomas';
  Self.Text := 'Cadastro de Idiomas';
  Include(Self.Closing, Self.frmCadIdiomas_Closing);
end;
{$ENDREGION}

procedure frmCadIdiomas.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmCadIdiomas.Create;
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

function frmCadIdiomas.ValidaDados(bTodosDados: boolean): boolean;
begin
  result:=true;
  if (Rotinas.ValidaCampo(edtCodigo.Text,'Código não informado!')) then
    result:=false;
  if (bTodosDados) then begin
    if (Rotinas.ValidaCampo(edtDescricao.Text,'Idioma não informado!')) then
    result:=false;
  end;
end;

procedure frmCadIdiomas.btnNovo_Click(sender: System.Object; e: System.EventArgs);
begin
  NovoDado(ConsSQL.Idioma('N',edtCodigo.Text,''));
end;

procedure frmCadIdiomas.btnExcluir_Click(sender: System.Object; e: System.EventArgs);
begin
  ExcluirDados(ConsSQL.Idioma('D',edtCodigo.Text,''));
end;

procedure frmCadIdiomas.btnPesquisar_Click(sender: System.Object; e: System.EventArgs);
begin
  PesquisarDados(ConsSQL.Idioma('S',edtCodigo.Text,''),
  'Idioma não encontrado!');
end;

procedure frmCadIdiomas.btnSalvar_Click(sender: System.Object; e: System.EventArgs);
begin
  SalvarDados(ConsSQL.Idioma('S',edtCodigo.Text,''),
  ConsSQL.Idioma('U',edtCodigo.Text,edtDescricao.Text),
  ConsSQL.Idioma('I',edtCodigo.Text,edtDescricao.Text),
  true);
end;

procedure frmCadIdiomas.frmCadIdiomas_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  fPrincipal.mnuCadIdiomas.Enabled:=true;
end;

end.
