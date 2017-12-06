Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmLogin
    Inherits System.Windows.Forms.Form

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call

    End Sub

    'Form overrides dispose to clean up the component list.
    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        If disposing Then
            If Not (components Is Nothing) Then
                components.Dispose()
            End If
        End If
        MyBase.Dispose(disposing)
    End Sub

	public WithEvents Shared fLogin as frmLogin
	private bFecharOuTerminar as Boolean

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    private edtLogin as System.Windows.Forms.TextBox
    private label1 as System.Windows.Forms.Label
    private label2 as System.Windows.Forms.Label
    private label3 as System.Windows.Forms.Label
    private edtSenha as System.Windows.Forms.TextBox
    private WithEvents btnLogin as System.Windows.Forms.Button
    private WithEvents btnCancelar as System.Windows.Forms.Button
    private Consulta as System.Data.OleDb.OleDbCommand 

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
     	Dim resources as System.Resources.ResourceManager = new _
        System.Resources.ResourceManager(GetType(frmLogin))
        Me.edtLogin = new System.Windows.Forms.TextBox()
        Me.label1 = new System.Windows.Forms.Label()
        Me.label2 = new System.Windows.Forms.Label()
        Me.label3 = new System.Windows.Forms.Label()
        Me.edtSenha = new System.Windows.Forms.TextBox()
        Me.btnLogin = new System.Windows.Forms.Button()
        Me.btnCancelar = new System.Windows.Forms.Button()
        Me.Consulta = new System.Data.OleDb.OleDbCommand()
        Me.SuspendLayout()
        '
        ' edtLogin
        '
        Me.edtLogin.Location = new System.Drawing.Point(112, 32)
        Me.edtLogin.MaxLength = 10
        Me.edtLogin.Name = "edtLogin"
        Me.edtLogin.Size = new System.Drawing.Size(80, 20)
        Me.edtLogin.TabIndex = 2
        Me.edtLogin.Text = ""
        '
        ' label1
        '
        Me.label1.BackColor = System.Drawing.Color.Transparent
        Me.label1.Image = resources.GetObject("label1.Image")
        Me.label1.Location = new System.Drawing.Point(8, 8)
        Me.label1.Name = "label1"
        Me.label1.Size = new System.Drawing.Size(96, 96)
        Me.label1.TabIndex = 0
        '
        ' label2
        '
        Me.label2.Location = new System.Drawing.Point(112, 16)
        Me.label2.Name = "label2"
        Me.label2.Size = new System.Drawing.Size(64, 16)
        Me.label2.TabIndex = 1
        Me.label2.Text = "Login:"
        '
        ' label3
        '
        Me.label3.Location = new System.Drawing.Point(112, 64)
        Me.label3.Name = "label3"
        Me.label3.Size = new System.Drawing.Size(64, 16)
        Me.label3.TabIndex = 3
        Me.label3.Text = "Senha:"
        '
        ' edtSenha
        '
        Me.edtSenha.Location = new System.Drawing.Point(112, 80)
        Me.edtSenha.MaxLength = 10
        Me.edtSenha.Name = "edtSenha"
        Me.edtSenha.PasswordChar = "*"
        Me.edtSenha.Size = new System.Drawing.Size(80, 20)
        Me.edtSenha.TabIndex = 4
        Me.edtSenha.Text = ""
        '
        ' btnLogin
        '
        Me.btnLogin.Location = new System.Drawing.Point(24, 112)
        Me.btnLogin.Name = "btnLogin"
        Me.btnLogin.TabIndex = 5
        Me.btnLogin.Text = "&Login"
        '
        ' btnCancelar
        '
        Me.btnCancelar.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnCancelar.Location = new System.Drawing.Point(104, 112)
        Me.btnCancelar.Name = "btnCancelar"
        Me.btnCancelar.TabIndex = 6
        Me.btnCancelar.Text = "&Cancelar"
        '
        ' frmLogin
        '
        Me.AcceptButton = Me.btnLogin
        Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
        Me.CancelButton = Me.btnCancelar
        Me.ClientSize = new System.Drawing.Size(202, 143)
        Me.Controls.Add(Me.btnCancelar)
        Me.Controls.Add(Me.btnLogin)
        Me.Controls.Add(Me.label3)
        Me.Controls.Add(Me.edtSenha)
        Me.Controls.Add(Me.edtLogin)
        Me.Controls.Add(Me.label2)
        Me.Controls.Add(Me.label1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
        Me.MaximizeBox = false
        Me.MinimizeBox = false
        Me.Name = "frmLogin"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen
        Me.Text = "Login do sistema"
        Me.ResumeLayout(false)
    End Sub

#End Region

		private sub frmLogin_Load(sender as object, e as System.EventArgs) _
            Handles MyBase.Load

			bFecharOuTerminar=false
		end sub

		private sub frmLogin_Closing(sender as object, e as System.ComponentModel.CancelEventArgs) _
            Handles MyBase.Closing

			if bFecharOuTerminar then
			  e.Cancel=false
			else
			  Application.Exit()
            end if
		end sub

		private sub btnLogin_Click(sender as object, e as System.EventArgs) _
            Handles btnLogin.Click

			if (RotinasGlobais.Rotinas.ConsultaDados(Consulta, _
			 ConsultasSQL.ConsSQL.Usuario("S",edtLogin.Text,edtSenha.Text))) then
			 RotinasGlobais.Rotinas.sUsuarioLogin=edtLogin.Text
			 RotinasGlobais.Rotinas.sUsuarioSenha=edtSenha.Text
			 frmPrincipal.fPrincipal.statusBar1.Panels(0).Text= _
				"Usuário: "+edtLogin.Text
			 bFecharOuTerminar=true
			 Close()
			else
			  MessageBox.Show("Login ou senha incorretos!", _
			  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
			  MessageBoxIcon.Information)
            end if
		end sub

		private sub btnCancelar_Click(sender as object, e as System.EventArgs) _
            Handles btnCancelar.Click

			bFecharOuTerminar=false
			Close()
		end sub

End Class

End NameSpace