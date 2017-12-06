Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmCadPaises
    Inherits Livrus.frmCadastros

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

    public shared withevents fCadPaises as frmCadPaises

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
        '
        ' labCodigo
        '
        Me.labCodigo.Name = "labCodigo"
        '
        ' edtCodigo
        '
        Me.edtCodigo.Name = "edtCodigo"
        Me.edtCodigo.MaxLength = 3
        '
        ' labDescricao
        '
        Me.labDescricao.Name = "labDescricao"
	    Me.labDescricao.Text = "País:"
        '
        ' edtDescricao
        '
        Me.edtDescricao.Name = "edtDescricao"
        '
        ' btnNovo
        '
        Me.btnNovo.Name = "btnNovo"
        '
        ' btnPesquisar
        '
        Me.btnPesquisar.Name = "btnPesquisar"
        '
        ' btnAnterior
        ' 
        Me.btnAnterior.Name = "btnAnterior"
        '
        ' btnProximo
        '
        Me.btnProximo.Name = "btnProximo"
        '
        ' btnFechar
        '
        Me.btnFechar.Name = "btnFechar"
        '
        ' btnLimpar
        '
        Me.btnLimpar.Name = "btnLimpar"
        '
        ' btnExcluir
        '
        Me.btnExcluir.Name = "btnExcluir"
        '
        ' btnSalvar
        '
        Me.btnSalvar.Name = "btnSalvar"
        '
        ' frmCadPaises
        '
        Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
        Me.ClientSize = new System.Drawing.Size(336, 133)
        Me.Name = "frmCadPaises"
        Me.Text = "Cadastro de Países"
    End Sub

#End Region

    protected overrides function ValidaDados(bTodosDados as boolean) as boolean
        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text, _
            "Código não informado!")) then
          ValidaDados = false
          exit function
        end if
        if (bTodosDados) then
          if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text, _
            "País não informado!")) then
            ValidaDados = false
            exit function
           end if
        end if
        ValidaDados = true
    end function

    private sub btnNovo_Click(sender as object, e as System.EventArgs) _
        Handles btnNovo.Click

	  edtCodigo.Clear
	  edtCodigo.Enabled=true
	  edtCodigo.Focus
    end sub

    private sub btnExcluir_Click(sender as object, e as System.EventArgs) _
        Handles btnExcluir.Click

        ExcluirDados(ConsultasSQL.ConsSQL.Pais("D",edtCodigo.Text,""))
    end sub

    private sub btnPesquisar_Click(sender as object, e as System.EventArgs) _
        Handles btnPesquisar.Click

        PesquisarDados(ConsultasSQL.ConsSQL.Pais("S",edtCodigo.Text,""), _
        "País não encontrado!")
    end sub

    private sub btnSalvar_Click(sender as object, e as System.EventArgs) _
        Handles btnSalvar.Click

        SalvarDados(ConsultasSQL.ConsSQL.Pais("S",edtCodigo.Text,""), _
        ConsultasSQL.ConsSQL.Pais("U",edtCodigo.Text,edtDescricao.Text), _
        ConsultasSQL.ConsSQL.Pais("I",edtCodigo.Text,edtDescricao.Text), _
        true)
    end sub

    private sub frmCadPaises_Closing(sender as object, _
        e as System.ComponentModel.CancelEventArgs) Handles MyBase.Closing

        frmPrincipal.fPrincipal.mnuCadPaises.Enabled=true
    end sub

    protected Overrides sub edtCodigo_Leave(sender as object, e as System.EventArgs) _
	 Handles edtCodigo.Leave
     '
    end sub
    
End Class

End NameSpace