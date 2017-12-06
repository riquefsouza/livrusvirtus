Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms

Namespace Livrus

Public Class frmSobre
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

    public withevents shared fSobre as frmSobre 

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    private groupBox1 as System.Windows.Forms.GroupBox
    private WithEvents btnOk as System.Windows.Forms.Button
    private pictureBox1 as System.Windows.Forms.PictureBox
    private label1 as System.Windows.Forms.Label
    private label2 as System.Windows.Forms.Label
    private label3 as System.Windows.Forms.Label

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()

       	Dim resources as System.Resources.ResourceManager = new _
        System.Resources.ResourceManager(GetType(frmSobre))
        Me.groupBox1 = new System.Windows.Forms.GroupBox()
        Me.label3 = new System.Windows.Forms.Label()
        Me.label2 = new System.Windows.Forms.Label()
        Me.label1 = new System.Windows.Forms.Label()
        Me.pictureBox1 = new System.Windows.Forms.PictureBox()
        Me.btnOk = new System.Windows.Forms.Button()
        Me.groupBox1.SuspendLayout()
        Me.SuspendLayout()
        '
        ' groupBox1
        '
        Me.groupBox1.BackColor = System.Drawing.Color.Transparent
        Me.groupBox1.Controls.Add(Me.label3)
        Me.groupBox1.Controls.Add(Me.label2)
        Me.groupBox1.Controls.Add(Me.label1)
        Me.groupBox1.Controls.Add(Me.pictureBox1)
        Me.groupBox1.Location = new System.Drawing.Point(8, 8)
        Me.groupBox1.Name = "groupBox1"
        Me.groupBox1.Size = new System.Drawing.Size(312, 176)
        Me.groupBox1.TabIndex = 0
        Me.groupBox1.TabStop = false
        '
        ' label3
        '
        Me.label3.Location = new System.Drawing.Point(24, 128)
        Me.label3.Name = "label3"
        Me.label3.Size = new System.Drawing.Size(256, 40)
        Me.label3.TabIndex = 3
        Me.label3.Text = "Sistema integrante do projeto Livrus Virtus, vers�o programada no " & _
            "Borland C#Builder for the Microsoft .NET Framework em VB.NET."
        Me.label3.TextAlign = System.Drawing.ContentAlignment.MiddleCenter
        '
        ' label2
        '
        Me.label2.Location = new System.Drawing.Point(8, 112)
        Me.label2.Name = "label2"
        Me.label2.Size = new System.Drawing.Size(296, 16)
        Me.label2.TabIndex = 2
        Me.label2.Text = "Todos os direitos reservados para: Henrique F. de Souza"
        Me.label2.TextAlign = System.Drawing.ContentAlignment.MiddleLeft
        '
        ' label1
        '
        Me.label1.Location = new System.Drawing.Point(16, 96)
        Me.label1.Name = "label1"
        Me.label1.Size = new System.Drawing.Size(280, 16)
        Me.label1.TabIndex = 1
        Me.label1.Text = "Vers�o: 1.0.0"
        Me.label1.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        '
        ' pictureBox1
        '
        Me.pictureBox1.BackColor = System.Drawing.Color.Transparent
        Me.pictureBox1.Image = CType(resources.GetObject("pictureBox1.Image"), _
                        System.Drawing.Image)
        Me.pictureBox1.Location = new System.Drawing.Point(24, 16)
        Me.pictureBox1.Name = "pictureBox1"
        Me.pictureBox1.Size = new System.Drawing.Size(264, 72)
        Me.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.pictureBox1.TabIndex = 0
        Me.pictureBox1.TabStop = false
        '
        ' btnOk
        '
        Me.btnOk.DialogResult = System.Windows.Forms.DialogResult.OK
        Me.btnOk.Location = new System.Drawing.Point(128, 192)
        Me.btnOk.Name = "btnOk"
        Me.btnOk.TabIndex = 1
        Me.btnOk.Text = "OK"
        '
        ' frmSobre
        '
        Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
        Me.ClientSize = new System.Drawing.Size(328, 221)
        Me.Controls.Add(Me.btnOk)
        Me.Controls.Add(Me.groupBox1)
        Me.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog
        Me.MaximizeBox = false
        Me.MinimizeBox = false
        Me.Name = "frmSobre"
        Me.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent
        Me.Text = "Sobre o Sistema"
        Me.groupBox1.ResumeLayout(false)
        Me.ResumeLayout(false)
    End Sub

#End Region

    private sub frmSobre_MouseMove(sender as object, e as System.Windows.Forms.MouseEventArgs) _
        Handles MyBase.MouseMove

          frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=Text
    end sub

    private sub frmSobre_Closing(sender as object, e as System.ComponentModel.CancelEventArgs) _
        Handles MyBase.Closing

        frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=""
    end sub

End Class

End Namespace