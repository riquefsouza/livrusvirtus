unit Login;

interface

uses
  System.Drawing, System.Collections, System.ComponentModel,
  System.Windows.Forms, System.Data, System.Resources, System.Data.OleDb;

type
  frmLogin = class(System.Windows.Forms.Form)
  {$REGION 'Designer Managed Code'}
  strict private
    /// <summary>
    /// Required designer variable.
    /// </summary>
    Components: System.ComponentModel.Container;
    edtLogin: System.Windows.Forms.TextBox;
    label1: System.Windows.Forms.Label;
    label2: System.Windows.Forms.Label;
    label3: System.Windows.Forms.Label;
    edtSenha: System.Windows.Forms.TextBox;
    btnLogin: System.Windows.Forms.Button;
    btnCancelar: System.Windows.Forms.Button;
    Consulta: System.Data.OleDb.OleDbCommand;

    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    procedure InitializeComponent;
    procedure frmLogin_Load(sender: System.Object; e: System.EventArgs);
    procedure frmLogin_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
    procedure btnLogin_Click(sender: System.Object; e: System.EventArgs);
    procedure btnCancelar_Click(sender: System.Object; e: System.EventArgs);
  {$ENDREGION}
  strict protected
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    procedure Dispose(Disposing: Boolean); override;
  private
    { Private Declarations }
    bFecharOuTerminar: Boolean;
  public
    constructor Create;
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(frmLogin))]

var fLogin: frmLogin;

implementation

uses RotinasGlobais, ConsultasSQL, Principal;

{$AUTOBOX ON}

{$REGION 'Windows Form Designer generated code'}
/// <summary>
/// Required method for Designer support -- do not modify
/// the contents of this method with the code editor.
/// </summary>
procedure frmLogin.InitializeComponent;
var
  resources: System.Resources.ResourceManager;
begin
  resources := System.Resources.ResourceManager.Create(TypeOf(frmLogin));
  Self.edtLogin := System.Windows.Forms.TextBox.Create;
  Self.label1 := System.Windows.Forms.Label.Create;
  Self.label2 := System.Windows.Forms.Label.Create;
  Self.label3 := System.Windows.Forms.Label.Create;
  Self.edtSenha := System.Windows.Forms.TextBox.Create;
  Self.btnLogin := System.Windows.Forms.Button.Create;
  Self.btnCancelar := System.Windows.Forms.Button.Create;
  Self.Consulta := System.Data.OleDb.OleDbCommand.Create;
  Self.SuspendLayout;
  // 
  // edtLogin
  // 
  Self.edtLogin.Location := System.Drawing.Point.Create(112, 32);
  Self.edtLogin.MaxLength := 10;
  Self.edtLogin.Name := 'edtLogin';
  Self.edtLogin.Size := System.Drawing.Size.Create(80, 20);
  Self.edtLogin.TabIndex := 2;
  Self.edtLogin.Text := '';
  // 
  // label1
  // 
  Self.label1.BackColor := System.Drawing.Color.Transparent;
  Self.label1.Image := (System.Drawing.Image(resources.GetObject('label1.Image')));
  Self.label1.Location := System.Drawing.Point.Create(8, 8);
  Self.label1.Name := 'label1';
  Self.label1.Size := System.Drawing.Size.Create(96, 96);
  Self.label1.TabIndex := 0;
  // 
  // label2
  // 
  Self.label2.Location := System.Drawing.Point.Create(112, 16);
  Self.label2.Name := 'label2';
  Self.label2.Size := System.Drawing.Size.Create(64, 16);
  Self.label2.TabIndex := 1;
  Self.label2.Text := 'Login:';
  // 
  // label3
  // 
  Self.label3.Location := System.Drawing.Point.Create(112, 64);
  Self.label3.Name := 'label3';
  Self.label3.Size := System.Drawing.Size.Create(64, 16);
  Self.label3.TabIndex := 3;
  Self.label3.Text := 'Senha:';
  // 
  // edtSenha
  // 
  Self.edtSenha.Location := System.Drawing.Point.Create(112, 80);
  Self.edtSenha.MaxLength := 10;
  Self.edtSenha.Name := 'edtSenha';
  Self.edtSenha.PasswordChar := '*';
  Self.edtSenha.Size := System.Drawing.Size.Create(80, 20);
  Self.edtSenha.TabIndex := 4;
  Self.edtSenha.Text := '';
  // 
  // btnLogin
  // 
  Self.btnLogin.Location := System.Drawing.Point.Create(24, 112);
  Self.btnLogin.Name := 'btnLogin';
  Self.btnLogin.TabIndex := 5;
  Self.btnLogin.Text := '&Login';
  Include(Self.btnLogin.Click, Self.btnLogin_Click);
  // 
  // btnCancelar
  // 
  Self.btnCancelar.DialogResult := System.Windows.Forms.DialogResult.Cancel;
  Self.btnCancelar.Location := System.Drawing.Point.Create(104, 112);
  Self.btnCancelar.Name := 'btnCancelar';
  Self.btnCancelar.TabIndex := 6;
  Self.btnCancelar.Text := '&Cancelar';
  Include(Self.btnCancelar.Click, Self.btnCancelar_Click);
  // 
  // frmLogin
  // 
  Self.AcceptButton := Self.btnLogin;
  Self.AutoScaleBaseSize := System.Drawing.Size.Create(5, 13);
  Self.CancelButton := Self.btnCancelar;
  Self.ClientSize := System.Drawing.Size.Create(202, 143);
  Self.Controls.Add(Self.btnCancelar);
  Self.Controls.Add(Self.btnLogin);
  Self.Controls.Add(Self.label3);
  Self.Controls.Add(Self.edtSenha);
  Self.Controls.Add(Self.edtLogin);
  Self.Controls.Add(Self.label2);
  Self.Controls.Add(Self.label1);
  Self.FormBorderStyle := System.Windows.Forms.FormBorderStyle.FixedDialog;
  Self.MaximizeBox := False;
  Self.MinimizeBox := False;
  Self.Name := 'frmLogin';
  Self.StartPosition := System.Windows.Forms.FormStartPosition.CenterScreen;
  Self.Text := 'Login do sistema';
  Include(Self.Closing, Self.frmLogin_Closing);
  Include(Self.Load, Self.frmLogin_Load);
  Self.ResumeLayout(False);
end;
{$ENDREGION}

procedure frmLogin.Dispose(Disposing: Boolean);
begin
  if Disposing then
  begin
    if Components <> nil then
      Components.Dispose();
  end;
  inherited Dispose(Disposing);
end;

constructor frmLogin.Create;
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

procedure frmLogin.btnCancelar_Click(sender: System.Object; e: System.EventArgs);
begin
  bFecharOuTerminar:=false;
  Close;
end;

procedure frmLogin.btnLogin_Click(sender: System.Object; e: System.EventArgs);
begin
			if (RotinasGlobais.Rotinas.ConsultaDados(Consulta, 
			 ConsultasSQL.ConsSQL.Usuario('S',edtLogin.Text,edtSenha.Text))) then begin
			 RotinasGlobais.Rotinas.sUsuarioLogin:=edtLogin.Text;
			 RotinasGlobais.Rotinas.sUsuarioSenha:=edtSenha.Text;
			 fPrincipal.statusBar1.Panels[0].Text:='Usuário: '+edtLogin.Text;
			 bFecharOuTerminar:=true;
			 Close;
			end else begin
			  MessageBox.Show('Login ou senha incorretos!',
			  fPrincipal.Text, MessageBoxButtons.OK,
			  MessageBoxIcon.Information);
      end;

end;

procedure frmLogin.frmLogin_Closing(sender: System.Object; e: System.ComponentModel.CancelEventArgs);
begin
  if bFecharOuTerminar then
    e.Cancel:=false
  else
    Application.Exit();
end;

procedure frmLogin.frmLogin_Load(sender: System.Object; e: System.EventArgs);
begin
  bFecharOuTerminar:=false;
end;

end.
