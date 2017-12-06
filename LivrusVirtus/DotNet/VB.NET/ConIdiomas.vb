Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmConIdiomas
    Inherits Livrus.frmConsultas

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

    public shared withevents fConIdiomas as frmConIdiomas

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    private dataGridTableStyle1 as System.Windows.Forms.DataGridTableStyle
    private dataGridTextBoxColumn1 as System.Windows.Forms.DataGridTextBoxColumn
    private dataGridTextBoxColumn2 as System.Windows.Forms.DataGridTextBoxColumn

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()

        Me.dataGridTableStyle1 = new System.Windows.Forms.DataGridTableStyle()
        Me.dataGridTextBoxColumn1 = new System.Windows.Forms.DataGridTextBoxColumn()
        Me.dataGridTextBoxColumn2 = new System.Windows.Forms.DataGridTextBoxColumn()
        CType(Me.gridConsulta,System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.dsConsulta,System.ComponentModel.ISupportInitialize).BeginInit()
        '
        ' btnPesquisar
        '
        Me.btnPesquisar.Name = "btnPesquisar"
        '
        ' labDescricao
        '
	Me.labDescricao.Name = "labDescricao"
	Me.labDescricao.Text = "Idioma:"
        '
        ' edtDescricao
        '
        Me.edtDescricao.Name = "edtDescricao"
        '
        ' gridConsulta
        '
        Me.gridConsulta.Name = "gridConsulta"
        Me.gridConsulta.TableStyles.AddRange( _
                    new System.Windows.Forms.DataGridTableStyle() { _
                    Me.dataGridTableStyle1})
        '
        ' btnLimpar
        '
        Me.btnLimpar.Name = "btnLimpar"
        '
        ' dsConsulta
        '
        Me.dsConsulta.DataSetName = "Consulta"
        Me.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR")
        '
        ' dataGridTableStyle1
        '
        Me.dataGridTableStyle1.DataGrid = Me.gridConsulta
        Me.dataGridTableStyle1.GridColumnStyles.AddRange( _
                    new System.Windows.Forms.DataGridColumnStyle() { _
                    Me.dataGridTextBoxColumn1, _
                    Me.dataGridTextBoxColumn2})
        Me.dataGridTableStyle1.HeaderForeColor = System.Drawing.SystemColors.ControlText
        Me.dataGridTableStyle1.MappingName = ""
        Me.dataGridTableStyle1.ReadOnly = true
        '
        ' dataGridTextBoxColumn1
        '
        Me.dataGridTextBoxColumn1.Format = ""
        Me.dataGridTextBoxColumn1.FormatInfo = nothing
        Me.dataGridTextBoxColumn1.HeaderText = "Código"
        Me.dataGridTextBoxColumn1.MappingName = ""
        Me.dataGridTextBoxColumn1.Width = 75
        '
        ' dataGridTextBoxColumn2
        '
        Me.dataGridTextBoxColumn2.Format = ""
        Me.dataGridTextBoxColumn2.FormatInfo = nothing
        Me.dataGridTextBoxColumn2.HeaderText = "Idioma"
        Me.dataGridTextBoxColumn2.MappingName = ""
        Me.dataGridTextBoxColumn2.Width = 75
        '
        ' frmConIdiomas
        '
        Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
        Me.ClientSize = new System.Drawing.Size(360, 237)
        Me.Name = "frmConIdiomas"
        Me.Text = "Consulta de Idiomas"
        CType(Me.gridConsulta,System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.dsConsulta,System.ComponentModel.ISupportInitialize).EndInit()
    End Sub

#End Region

		private sub frmConIdiomas_Closing(sender as object, _
            e as System.ComponentModel.CancelEventArgs) Handles MyBase.Closing

			frmPrincipal.fPrincipal.mnuConIdiomas.Enabled=true
		end sub

		private sub btnLimpar_Click(sender as object, e as System.EventArgs) _
            Handles btnLimpar.Click

			LimparDados(ConsultasSQL.ConsSQL.Idioma("S","0",""))
		end sub

		private sub btnPesquisar_Click(sender as object, _
            e as System.EventArgs) Handles btnPesquisar.Click

			PesquisarDados(ConsultasSQL.ConsSQL. _
			Idioma("S","", edtDescricao.Text),"Idioma não encontrado!")
		end sub

		private sub frmConIdiomas_Load(sender as object, _
            e as System.EventArgs) Handles MyBase.Load

	           btnLimpar_Click(Me, nothing)
		end sub

End Class

End Namespace
