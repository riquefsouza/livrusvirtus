Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmAlterarSenha
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

    public withevents shared fAlterarSenha as frmAlterarSenha

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    private WithEvents btnSalvar As System.Windows.Forms.Button
    private WithEvents btnLimpar As System.Windows.Forms.Button
    private WithEvents btnFechar As System.Windows.Forms.Button
    private label3 As System.Windows.Forms.Label
    private edtNovaSenha As System.Windows.Forms.TextBox
    private edtLogin As System.Windows.Forms.TextBox
    private label2 As System.Windows.Forms.Label
    private label1 As System.Windows.Forms.Label
    private edtConfirmarSenha As System.Windows.Forms.TextBox
    private edtSenhaAtual As System.Windows.Forms.TextBox
    private label4 As System.Windows.Forms.Label
    private Arquiva As System.Data.OleDb.OleDbCommand

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()

        Me.btnSalvar = new System.Windows.Forms.Button()
        Me.btnLimpar = new System.Windows.Forms.Button()
        Me.btnFechar = new System.Windows.Forms.Button()
        Me.label3 = new System.Windows.Forms.Label()
        Me.edtNovaSenha = new System.Windows.Forms.TextBox()
        Me.edtLogin = new System.Windows.Forms.TextBox()
        Me.label2 = new System.Windows.Forms.Label()
        Me.label1 = new System.Windows.Forms.Label()
        Me.edtConfirmarSenha = new System.Windows.Forms.TextBox()
        Me.edtSenhaAtual = new System.Windows.Forms.TextBox()
        Me.label4 = new System.Windows.Forms.Label()
        Me.Arquiva = new System.Data.OleDb.OleDbCommand()
        Me.SuspendLayout()
        '
        ' btnSalvar
        '
        Me.btnSalvar.Location = new System.Drawing.Point(8, 104)
        Me.btnSalvar.Name = "btnSalvar"
        Me.btnSalvar.TabIndex = 8
        Me.btnSalvar.Text = "&Salvar"
        '
        ' btnLimpar
        '
        Me.btnLimpar.Location = new System.Drawing.Point(88, 104)
        Me.btnLimpar.Name = "btnLimpar"
        Me.btnLimpar.TabIndex = 9
        Me.btnLimpar.Text = "&Limpar"
        '
        ' btnFechar
        '
        Me.btnFechar.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnFechar.Location = new System.Drawing.Point(168, 104)
        Me.btnFechar.Name = "btnFechar"
        Me.btnFechar.TabIndex = 10
        Me.btnFechar.Text = "&Fechar"
        '
        ' label3
        '
        Me.label3.Location = new System.Drawing.Point(16, 56)
        Me.label3.Name = "label3"
        Me.label3.Size = new System.Drawing.Size(80, 16)
        Me.label3.TabIndex = 4
        Me.label3.Text = "Nova senha:"
        '
        ' edtNovaSenha
        '
        Me.edtNovaSenha.Location = new System.Drawing.Point(16, 72)
        Me.edtNovaSenha.MaxLength = 10
        Me.edtNovaSenha.Name = "edtNovaSenha"
        Me.edtNovaSenha.PasswordChar = "*"
        Me.edtNovaSenha.Size = new System.Drawing.Size(96, 20)
        Me.edtNovaSenha.TabIndex = 5
        Me.edtNovaSenha.Text = ""
        '
        ' edtLogin
        '
        Me.edtLogin.Enabled = false
        Me.edtLogin.Location = new System.Drawing.Point(16, 24)
        Me.edtLogin.MaxLength = 10
        Me.edtLogin.Name = "edtLogin"
        Me.edtLogin.Size = new System.Drawing.Size(96, 20)
        Me.edtLogin.TabIndex = 1
        Me.edtLogin.Text = ""
        '
        ' label2
        '
        Me.label2.Location = new System.Drawing.Point(16, 8)
        Me.label2.Name = "label2"
        Me.label2.Size = new System.Drawing.Size(64, 16)
        Me.label2.TabIndex = 0
        Me.label2.Text = "Login:"
        '
        ' label1
        '
        Me.label1.Location = new System.Drawing.Point(128, 56)
        Me.label1.Name = "label1"
        Me.label1.Size = new System.Drawing.Size(96, 16)
        Me.label1.TabIndex = 6
        Me.label1.Text = "Confirmar senha:"
        '
        ' edtConfirmarSenha
        '
        Me.edtConfirmarSenha.Location = new System.Drawing.Point(128, 72)
        Me.edtConfirmarSenha.MaxLength = 10
        Me.edtConfirmarSenha.Name = "edtConfirmarSenha"
        Me.edtConfirmarSenha.PasswordChar = "*"
        Me.edtConfirmarSenha.Size = new System.Drawing.Size(96, 20)
        Me.edtConfirmarSenha.TabIndex = 7
        Me.edtConfirmarSenha.Text = ""
        '
        ' edtSenhaAtual
        '
        Me.edtSenhaAtual.Location = new System.Drawing.Point(128, 24)
        Me.edtSenhaAtual.MaxLength = 10
        Me.edtSenhaAtual.Name = "edtSenhaAtual"
        Me.edtSenhaAtual.PasswordChar = "*"
        Me.edtSenhaAtual.Size = new System.Drawing.Size(96, 20)
        Me.edtSenhaAtual.TabIndex = 3
        Me.edtSenhaAtual.Text = ""
        '
        ' label4
        '
        Me.label4.Location = new System.Drawing.Point(128, 8)
        Me.label4.Name = "label4"
        Me.label4.Size = new System.Drawing.Size(80, 16)
        Me.label4.TabIndex = 2
        Me.label4.Text = "Senha atual:"
        '
        ' frmAlterarSenha
        '
        Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
        Me.ClientSize = new System.Drawing.Size(248, 133)
        Me.Controls.Add(Me.label1)
        Me.Controls.Add(Me.edtConfirmarSenha)
        Me.Controls.Add(Me.edtSenhaAtual)
        Me.Controls.Add(Me.label4)
        Me.Controls.Add(Me.label3)
        Me.Controls.Add(Me.edtNovaSenha)
        Me.Controls.Add(Me.edtLogin)
        Me.Controls.Add(Me.label2)
        Me.Controls.Add(Me.btnSalvar)
        Me.Controls.Add(Me.btnLimpar)
        Me.Controls.Add(Me.btnFechar)
        Me.Name = "frmAlterarSenha"
        Me.Text = "Altera��o de Senha"
        Me.ResumeLayout(false)
    End Sub

#End Region

    private sub frmAlterarSenha_Closing(sender as object, e as System.ComponentModel.CancelEventArgs) _
        Handles MyBase.Closing

        frmPrincipal.fPrincipal.mnuAlterarSenha.Enabled=true
        frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=""
    end sub

    private sub btnFechar_Click(sender as object, e as System.EventArgs) _
        Handles btnFechar.Click

        Close()
    end sub

    private sub btnLimpar_Click(sender as object, e as System.EventArgs) _
        Handles btnLimpar.Click

        edtNovaSenha.Text=""
        edtConfirmarSenha.Text=""
        edtSenhaAtual.Focus()
    end sub

    private function ValidaDados() as boolean
      if (edtSenhaAtual.Text.Trim() <> _
         RotinasGlobais.Rotinas.sUsuarioSenha.Trim()) then
        MessageBox.Show("A Senha atual n�o confere com a senha do usu�rio!", _
        frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
        MessageBoxIcon.Error)
        ValidaDados = false
        Exit Function
      end if
      if (RotinasGlobais.Rotinas.ValidaCampo(edtNovaSenha.Text, _
            "Nova senha n�o informada!")) then
        ValidaDados = false
        Exit Function
      end if
      if (edtNovaSenha.Text.Trim() <> edtConfirmarSenha.Text.Trim()) then
        MessageBox.Show("A Nova senha n�o confere com a senha a confirmar!", _
        frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
        MessageBoxIcon.Error)
        ValidaDados = false
        Exit Function
      end if

      ValidaDados = true
    end function

    private sub btnSalvar_Click(sender as object, e as System.EventArgs) _
        Handles btnSalvar.Click

        if ValidaDados() then
          Arquiva = frmPrincipal.fPrincipal.db.CreateCommand()

          Arquiva.CommandText=ConsultasSQL.ConsSQL.Usuario("U", _
          RotinasGlobais.Rotinas.sUsuarioLogin, edtConfirmarSenha.Text)
          Arquiva.ExecuteNonQuery()
          Arquiva.Dispose()
          RotinasGlobais.Rotinas.sUsuarioSenha=edtNovaSenha.Text
          MessageBox.Show("Senha alterada com sucesso!", _
          frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
          MessageBoxIcon.Information)
        end if
    end sub

    private sub frmAlterarSenha_Load(sender as object, e as System.EventArgs) _
        Handles MyBase.Load

        edtLogin.Text=RotinasGlobais.Rotinas.sUsuarioLogin
    end sub

    private sub frmAlterarSenha_MouseMove(sender as object, _
        e as System.Windows.Forms.MouseEventArgs) Handles MyBase.MouseMove

        frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=Text
    end sub

End Class

End NameSpace