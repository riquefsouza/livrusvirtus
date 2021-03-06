Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmConsultas
    Inherits System.Windows.Forms.Form

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call
	Registros = new ArrayList()
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

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    protected panel1 As System.Windows.Forms.Panel
    protected WithEvents btnPesquisar As System.Windows.Forms.Button
    protected WithEvents edtDescricao As System.Windows.Forms.TextBox
    protected labDescricao As System.Windows.Forms.Label
    protected WithEvents gridConsulta As System.Windows.Forms.DataGrid
    protected panel2 As System.Windows.Forms.Panel
    protected WithEvents btnLimpar As System.Windows.Forms.Button
    protected WithEvents btnFechar As System.Windows.Forms.Button
    protected labRegistros As System.Windows.Forms.Label
    protected dsConsulta As System.Data.DataSet
    protected Registros As ArrayList
    protected Campos As ArrayList	

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()

        Me.panel1 = new System.Windows.Forms.Panel()
        Me.btnPesquisar = new System.Windows.Forms.Button()
        Me.edtDescricao = new System.Windows.Forms.TextBox()
        Me.labDescricao = new System.Windows.Forms.Label()
        Me.gridConsulta = new System.Windows.Forms.DataGrid()
        Me.dsConsulta = new System.Data.DataSet()
        Me.panel2 = new System.Windows.Forms.Panel()
        Me.labRegistros = new System.Windows.Forms.Label()
        Me.btnLimpar = new System.Windows.Forms.Button()
        Me.btnFechar = new System.Windows.Forms.Button()
        Me.panel1.SuspendLayout()
        CType(Me.gridConsulta,System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.dsConsulta,System.ComponentModel.ISupportInitialize).BeginInit()
        Me.panel2.SuspendLayout()
        Me.SuspendLayout()
        '
        ' panel1
        '
        Me.panel1.Controls.Add(Me.btnPesquisar)
        Me.panel1.Controls.Add(Me.edtDescricao)
        Me.panel1.Controls.Add(Me.labDescricao)
        Me.panel1.Dock = System.Windows.Forms.DockStyle.Top
        Me.panel1.Location = new System.Drawing.Point(0, 0)
        Me.panel1.Name = "panel1"
        Me.panel1.Size = new System.Drawing.Size(360, 56)
        Me.panel1.TabIndex = 0
        '
        ' btnPesquisar
        '
        Me.btnPesquisar.Location = new System.Drawing.Point(280, 24)
        Me.btnPesquisar.Name = "btnPesquisar"
        Me.btnPesquisar.TabIndex = 2
        Me.btnPesquisar.Text = "&Pesquisar"
        '
        ' edtDescricao
        '
        Me.edtDescricao.Location = new System.Drawing.Point(8, 24)
        Me.edtDescricao.Name = "edtDescricao"
        Me.edtDescricao.Size = new System.Drawing.Size(264, 20)
        Me.edtDescricao.TabIndex = 1
        Me.edtDescricao.Text = ""
        '
        ' labDescricao
        '
        Me.labDescricao.Location = new System.Drawing.Point(8, 8)
        Me.labDescricao.Name = "labDescricao"
        Me.labDescricao.Size = new System.Drawing.Size(64, 16)
        Me.labDescricao.TabIndex = 0
        Me.labDescricao.Text = "Descri��o:"
        '
        ' gridConsulta
        '
        Me.gridConsulta.Anchor = CType( _
                    ((((System.Windows.Forms.AnchorStyles.Top _
                    or System.Windows.Forms.AnchorStyles.Bottom) _
                    or System.Windows.Forms.AnchorStyles.Left) _
                    or System.Windows.Forms.AnchorStyles.Right)), _
                    System.Windows.Forms.AnchorStyles)
        Me.gridConsulta.CaptionVisible = false
        Me.gridConsulta.DataMember = ""
        Me.gridConsulta.DataSource = Me.dsConsulta
        Me.gridConsulta.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.gridConsulta.Location = new System.Drawing.Point(0, 56)
        Me.gridConsulta.Name = "gridConsulta"
        Me.gridConsulta.ParentRowsVisible = false
        Me.gridConsulta.ReadOnly = true
        Me.gridConsulta.Size = new System.Drawing.Size(360, 144)
        Me.gridConsulta.TabIndex = 1
        '
        ' dsConsulta
        '
        Me.dsConsulta.DataSetName = "Consulta"
        Me.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR")
        '
        ' panel2
        '
        Me.panel2.Anchor = CType( _
                (((System.Windows.Forms.AnchorStyles.Bottom or _
                      System.Windows.Forms.AnchorStyles.Left) _
                    or System.Windows.Forms.AnchorStyles.Right)), _
                    System.Windows.Forms.AnchorStyles)
        Me.panel2.Controls.Add(Me.labRegistros)
        Me.panel2.Controls.Add(Me.btnLimpar)
        Me.panel2.Controls.Add(Me.btnFechar)
        Me.panel2.Location = new System.Drawing.Point(0, 200)
        Me.panel2.Name = "panel2"
        Me.panel2.Size = new System.Drawing.Size(360, 40)
        Me.panel2.TabIndex = 2
        '
        ' labRegistros
        '
        Me.labRegistros.Location = new System.Drawing.Point(11, 12)
        Me.labRegistros.Name = "labRegistros"
        Me.labRegistros.Size = new System.Drawing.Size(136, 16)
        Me.labRegistros.TabIndex = 0
        Me.labRegistros.Text = "Registro 0 de 0"
        '
        ' btnLimpar
        '
	Me.btnLimpar.Anchor = CType((System.Windows.Forms.AnchorStyles.Top or _
				System.Windows.Forms.AnchorStyles.Right), _
				System.Windows.Forms.AnchorStyles)
        Me.btnLimpar.Location = new System.Drawing.Point(200, 8)
        Me.btnLimpar.Name = "btnLimpar"
        Me.btnLimpar.TabIndex = 1
        Me.btnLimpar.Text = "&Limpar"
        '
        ' btnFechar
        '
	Me.btnFechar.Anchor = CType((System.Windows.Forms.AnchorStyles.Top or _
				System.Windows.Forms.AnchorStyles.Right), _ 
				System.Windows.Forms.AnchorStyles)
        Me.btnFechar.DialogResult = System.Windows.Forms.DialogResult.Cancel
        Me.btnFechar.Location = new System.Drawing.Point(280, 8)
        Me.btnFechar.Name = "btnFechar"
        Me.btnFechar.TabIndex = 2
        Me.btnFechar.Text = "&Fechar"
        '
        ' frmConsultas
        '
        Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
        Me.ClientSize = new System.Drawing.Size(360, 237)
        Me.Controls.Add(Me.panel2)
        Me.Controls.Add(Me.gridConsulta)
        Me.Controls.Add(Me.panel1)
        Me.Name = "frmConsultas"
        Me.Text = "Consulta de"
        Me.panel1.ResumeLayout(false)
        CType(Me.gridConsulta,System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.dsConsulta,System.ComponentModel.ISupportInitialize).EndInit()
        Me.panel2.ResumeLayout(false)
        Me.ResumeLayout(false)
    End Sub

#End Region

    private sub btnFechar_Click(sender as object, e as System.EventArgs) _
        Handles btnFechar.Click
        Close()
    end sub

    private sub frmConsultas_Closing(sender as object, _
        e as System.ComponentModel.CancelEventArgs) Handles MyBase.Closing

        if (dsConsulta.Tables(0).Rows.Count > 0) then
	   Campos = CType(Registros(gridConsulta.CurrentCell.RowNumber),ArrayList)	
           RotinasGlobais.Rotinas.sCodigoSelecionado= Campos(0).ToString()
        end if
        frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=""
    end sub

    protected sub LimparDados(sTextoSql as string)
      labRegistros.Text="Registro 0 de 0"
      RotinasGlobais.Rotinas.ConsultaDados(dsConsulta, Registros, sTextoSql)
      btnPesquisar.Enabled=true
      edtDescricao.Text=""
      edtDescricao.Focus()
    end sub

    protected function PesquisarDados(sTextoSql as string, sMensagemErro as string) as boolean
      if RotinasGlobais.Rotinas.ConsultaDados(dsConsulta, Registros, sTextoSql) then
         gridConsulta.SetDataBinding(dsConsulta,"Consulta")
         gridConsulta_CurrentCellChanged(Me,nothing)
         btnPesquisar.Enabled=false
         PesquisarDados = true
      else
         MessageBox.Show(sMensagemErro, frmPrincipal.fPrincipal.Text, _
         MessageBoxButtons.OK, MessageBoxIcon.Error)
         PesquisarDados = false
      end if
    end function

    private sub gridConsulta_CurrentCellChanged(sender as object, _
        e as System.EventArgs) Handles gridConsulta.CurrentCellChanged

        labRegistros.Text="Registro " & _
        (gridConsulta.CurrentCell.RowNumber+1) & _
        " de " & dsConsulta.Tables("Consulta").Rows.Count.ToString()
    end sub

    private sub gridConsulta_MouseMove(sender as object, _
       e as System.Windows.Forms.MouseEventArgs) Handles gridConsulta.MouseMove

        frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=Text
    end sub

End Class

End NameSpace