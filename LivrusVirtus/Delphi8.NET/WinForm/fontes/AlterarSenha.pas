unit AlterarSenha;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Data.OleDb;

type
  frmAlterarSenha = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
		btnSalvar: System.Windows.Forms.Button;
		btnLimpar: System.Windows.Forms.Button;
		btnFechar: System.Windows.Forms.Button;
		label3: System.Windows.Forms.Label;
		edtNovaSenha: System.Windows.Forms.TextBox;
		edtLogin: System.Windows.Forms.TextBox;
		label2: System.Windows.Forms.Label;
		label1: System.Windows.Forms.Label;
		edtConfirmarSenha: System.Windows.Forms.TextBox;
		edtSenhaAtual: System.Windows.Forms.TextBox;
		label4: System.Windows.Forms.Label;
		Arquiva: System.Data.OleDb.OleDbCommand;

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure btnSalvar_Click(sender: System.Object; e: System.EventArgs);
    procedure frmAlterarSenha_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnFechar_Click(sender: System.Object; e: System.EventArgs);
    procedure btnLimpar_Click(sender: System.Object; e: System.EventArgs);
    procedure frmAlterarSenha_Load(sender: System.Object; e: System.EventArgs);
    procedure frmAlterarSenha_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
    function ValidaDados: Boolean;
  private
    { Private Declarations }
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmAlterarSenha))]

var fAlterarSenha: frmAlterarSenha;

implementation

uses Principal, RotinasGlobais, ConsultasSQL;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmAlterarSenha.InitializeComponent;
begin
  Self.btnSalvar := System.Windows.Forms.Button.Create;
  Self.btnLimpar := System.Windows.Forms.Button.Create;
  Self.btnFechar := System.Windows.Forms.Button.Create;
  Self.label3 := System.Windows.Forms.Label.Create;
  Self.edtNovaSenha := System.Windows.Forms.TextBox.Create;
  Self.edtLogin := System.Windows.Forms.TextBox.Create;
  Self.label2 := System.Windows.Forms.Label.Create;
  Self.label1 := System.Windows.Forms.Label.Create;
  Self.edtConfirmarSenha := System.Windows.Forms.TextBox.Create;
  Self.edtSenhaAtual := System.Windows.Forms.TextBox.Create;
  Self.label4 := System.Windows.Forms.Label.Create;
  Self.Arquiva := System.Data.OleDb.OleDbCommand.Create;
  Self.SuspendLayout;
  // 
  // btnSalvar
  // 
  Self.btnSalvar.Location := System.Drawing.Point.Create(8, 104);
  Self.btnSalvar.Name := 'btnSalvar';
  Self.btnSalvar.TabIndex := 8;
  Self.btnSalvar.Text := '&Salvar';
  Include(Self.btnSalvar.Click, Self.btnSalvar_Click);
  // 
  // btnLimpar
  // 
  Self.btnLimpar.Location := System.Drawing.Point.Create(88, 104);
  Self.btnLimpar.Name := 'btnLimpar';
  Self.btnLimpar.TabIndex := 9;
  Self.btnLimpar.Text := '&Limpar';
  Include(Self.btnLimpar.Click, Self.btnLimpar_Click);
  // 
  // btnFechar
  // 
  Self.btnFechar.DialogResult := System.Windows.Forms.DialogResult.Cancel;
  Self.btnFechar.Location := System.Drawing.Point.Create(168, 104);
  Self.btnFechar.Name := 'btnFechar';
  Self.btnFechar.TabIndex := 10;
  Self.btnFechar.Text := '&Fechar';
  Include(Self.btnFechar.Click, Self.btnFechar_Click);
  // 
  // label3
  // 
  Self.label3.Location := System.Drawing.Point.Create(16, 56);
  Self.label3.Name := 'label3';
  Self.label3.Size := System.Drawing.Size.Create(80, 16);
  Self.label3.TabIndex := 4;
  Self.label3.Text := 'Nova senha:';
  // 
  // edtNovaSenha
  // 
  Self.edtNovaSenha.Location := System.Drawing.Point.Create(16, 72);
  Self.edtNovaSenha.MaxLength := 10;
  Self.edtNovaSenha.Name := 'edtNovaSenha';
  Self.edtNovaSenha.PasswordChar := '*';
  Self.edtNovaSenha.Size := System.Drawing.Size.Create(96, 20);
  Self.edtNovaSenha.TabIndex := 5;
  Self.edtNovaSenha.Text := '';
  // 
  // edtLogin
  // 
  Self.edtLogin.Enabled := False;
  Self.edtLogin.Location := System.Drawing.Point.Create(16, 24);
  Self.edtLogin.MaxLength := 10;
  Self.edtLogin.Name := 'edtLogin';
  Self.edtLogin.Size := System.Drawing.Size.Create(96, 20);
  Self.edtLogin.TabIndex := 1;
  Self.edtLogin.Text := '';
  // 
  // label2
  // 
  Self.label2.Location := System.Drawing.Point.Create(16, 8);
  Self.label2.Name := 'label2';
  Self.label2.Size := System.Drawing.Size.Create(64, 16);
  Self.label2.TabIndex := 0;
  Self.label2.Text := 'Login:';
  // 
  // label1
  // 
  Self.label1.Location := System.Drawing.Point.Create(128, 56);
  Self.label1.Name := 'label1';
  Self.label1.Size := System.Drawing.Size.Create(96, 16);
  Self.label1.TabIndex := 6;
  Self.label1.Text := 'Confirmar senha:';
  // 
  // edtConfirmarSenha
  // 
  Self.edtConfirmarSenha.Location := System.Drawing.Point.Create(128, 72);
  Self.edtConfirmarSenha.MaxLength := 10;
  Self.edtConfirmarSenha.Name := 'edtConfirmarSenha';
  Self.edtConfirmarSenha.PasswordChar := '*';
  Self.edtConfirmarSenha.Size := System.Drawing.Size.Create(96, 20);
  Self.edtConfirmarSenha.TabIndex := 7;
  Self.edtConfirmarSenha.Text := '';
  // 
  // edtSenhaAtual
  // 
  Self.edtSenhaAtual.Location := System.Drawing.Point.Create(128, 24);
  Self.edtSenhaAtual.MaxLength := 10;
  Self.edtSenhaAtual.Name := 'edtSenhaAtual';
  Self.edtSenhaAtual.PasswordChar := '*';
  Self.edtSenhaAtual.Size := System.Drawing.Size.Create(96, 20);
  Self.edtSenhaAtual.TabIndex := 3;
  Self.edtSenhaAtual.Text := '';
  // 
  // label4
  // 
  Self.label4.Location := System.Drawing.Point.Create(128, 8);
  Self.label4.Name := 'label4';
  Self.label4.Size := System.Drawing.Size.Create(80, 16);
  Self.label4.TabIndex := 2;
  Self.label4.Text := 'Senha atual:';
  // 
  // frmAlterarSenha
  // 
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.ClientSize := System.Drawing.Size.Create(248, 133);
  Self.Controls.Add(Self.label1);
  Self.Controls.Add(Self.edtConfirmarSenha);
  Self.Controls.Add(Self.edtSenhaAtual);
  Self.Controls.Add(Self.label4);
  Self.Controls.Add(Self.label3);
  Self.Controls.Add(Self.edtNovaSenha);
  Self.Controls.Add(Self.edtLogin);
  Self.Controls.Add(Self.label2);
  Self.Controls.Add(Self.btnSalvar);
  Self.Controls.Add(Self.btnLimpar);
  Self.Controls.Add(Self.btnFechar);
  Self.Name := 'frmAlterarSenha';
  Self.Text := 'Alteração de Senha';
  Include(Self.Closing, Self.frmAlterarSenha_Closing);
  Include(Self.Load, Self.frmAlterarSenha_Load);
  Include(Self.MouseMove, Self.frmAlterarSenha_MouseMove);
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmAlterarSenha.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmAlterarSenha.Create;
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

procedure frmAlterarSenha.frmAlterarSenha_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  Principal.fPrincipal.mnuAlterarSenha.Enabled:=true;
  Principal.fPrincipal.statusBar1.Panels.Item[1].Text:='';
end;

procedure frmAlterarSenha.btnFechar_Click(sender: System.Object; e: System.EventArgs);
begin
  Close;
end;

procedure frmAlterarSenha.btnLimpar_Click(sender: System.Object; e: System.EventArgs);
begin
  edtNovaSenha.Text:='';
  edtConfirmarSenha.Text:='';
  edtSenhaAtual.Focus;
end;

function frmAlterarSenha.ValidaDados: Boolean;
begin
  result:=true;

  if (edtSenhaAtual.Text.Trim <>
   RotinasGlobais.Rotinas.sUsuarioSenha.Trim) then begin
    MessageBox.Show('A Senha atual não confere com a senha do usuário!',
    Principal.fPrincipal.Text, MessageBoxButtons.OK,
    MessageBoxIcon.Error);
    result:=false;
  end;
  if (RotinasGlobais.Rotinas.ValidaCampo(edtNovaSenha.Text,
    'Nova senha não informada!')) then begin
    result:=false;
  end;
  if (edtNovaSenha.Text.Trim <> edtConfirmarSenha.Text.Trim) then begin
    MessageBox.Show('A Nova senha não confere com a senha a confirmar!',
    Principal.fPrincipal.Text, MessageBoxButtons.OK,
    MessageBoxIcon.Error);
    result:=false;
  end;
end;

procedure frmAlterarSenha.btnSalvar_Click(sender: System.Object; e: System.EventArgs);
begin
  if (ValidaDados()) then begin
    Arquiva := Principal.fPrincipal.db.CreateCommand();

    Arquiva.CommandText:=ConsultasSQL.ConsSQL.Usuario('U',
    RotinasGlobais.Rotinas.sUsuarioLogin, edtConfirmarSenha.Text);
    Arquiva.ExecuteNonQuery;
    Arquiva.Dispose;
    RotinasGlobais.Rotinas.sUsuarioSenha:=edtNovaSenha.Text;
    MessageBox.Show('Senha alterada com sucesso!',
    Principal.fPrincipal.Text, MessageBoxButtons.OK,
    MessageBoxIcon.Information);
  end;
end;

procedure frmAlterarSenha.frmAlterarSenha_Load(sender: System.Object; e: System.EventArgs);
begin
  edtLogin.Text:=RotinasGlobais.Rotinas.sUsuarioLogin;
end;

procedure frmAlterarSenha.frmAlterarSenha_MouseMove(sender: System.Object; e: System.Windows.Forms.MouseEventArgs);
begin
  Principal.fPrincipal.statusBar1.Panels.Item[1].Text:=Text;
end;

end.
