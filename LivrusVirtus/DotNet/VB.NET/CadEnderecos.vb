Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmCadEnderecos
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

    public shared withevents fCadEnderecos as frmCadEnderecos

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    private labBairro As System.Windows.Forms.Label 
    private edtBairro As System.Windows.Forms.TextBox 
    private edtCEP As System.Windows.Forms.TextBox 
    private labCEP As System.Windows.Forms.Label 
    private edtCidade As System.Windows.Forms.TextBox 
    private labCidade As System.Windows.Forms.Label 
    private labEstado As System.Windows.Forms.Label 
    private cmbEstado As System.Windows.Forms.ComboBox 

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
	Me.labBairro = new System.Windows.Forms.Label()
	Me.edtBairro = new System.Windows.Forms.TextBox()
	Me.edtCEP = new System.Windows.Forms.TextBox()
	Me.labCEP = new System.Windows.Forms.Label()
	Me.edtCidade = new System.Windows.Forms.TextBox()
	Me.labCidade = new System.Windows.Forms.Label()
	Me.labEstado = new System.Windows.Forms.Label()
	Me.cmbEstado = new System.Windows.Forms.ComboBox()
	Me.SuspendLayout()
	' 
	' labCodigo
	' 
	Me.labCodigo.Name = "labCodigo"
	' 
	' edtCodigo
	' 
	Me.edtCodigo.Name = "edtCodigo"
	' 
	' labDescricao
	' 
	Me.labDescricao.Name = "labDescricao"
	Me.labDescricao.Text = "Logradouro:"
	' 
	' edtDescricao
	' 
	Me.edtDescricao.MaxLength = 40
	Me.edtDescricao.Name = "edtDescricao"
	Me.edtDescricao.Size = new System.Drawing.Size(264, 20)
	' 
	' btnNovo
	' 
	Me.btnNovo.Name = "btnNovo"
	' 
	' btnPesquisar
	' 
	Me.btnPesquisar.Location = new System.Drawing.Point(440, 8)
	Me.btnPesquisar.Name = "btnPesquisar"
	Me.btnPesquisar.TabIndex = 13
	' 
	' btnAnterior
	' 
	Me.btnAnterior.Location = new System.Drawing.Point(440, 40)
	Me.btnAnterior.Name = "btnAnterior"
	Me.btnAnterior.TabIndex = 14
	' 
	' btnProximo
	' 
	Me.btnProximo.Location = new System.Drawing.Point(440, 72)
	Me.btnProximo.Name = "btnProximo"
	Me.btnProximo.TabIndex = 15
	' 
	' btnFechar
	' 
	Me.btnFechar.Location = new System.Drawing.Point(440, 136)
	Me.btnFechar.Name = "btnFechar"
	Me.btnFechar.TabIndex = 19
	' 
	' btnLimpar
	' 
	Me.btnLimpar.Location = new System.Drawing.Point(360, 136)
	Me.btnLimpar.Name = "btnLimpar"
	Me.btnLimpar.TabIndex = 18
	' 
	' btnExcluir
	' 
	Me.btnExcluir.Location = new System.Drawing.Point(280, 136)
	Me.btnExcluir.Name = "btnExcluir"
	Me.btnExcluir.TabIndex = 17
	' 
	' btnSalvar
	' 
	Me.btnSalvar.Location = new System.Drawing.Point(200, 136)
	Me.btnSalvar.Name = "btnSalvar"
	Me.btnSalvar.TabIndex = 16
	' 
	' labBairro
	' 
	Me.labBairro.Location = new System.Drawing.Point(280, 48)
	Me.labBairro.Name = "labBairro"
	Me.labBairro.Size = new System.Drawing.Size(64, 16)
	Me.labBairro.TabIndex = 5
	Me.labBairro.Text = "Bairro:"
	' 
	' edtBairro
	' 
	Me.edtBairro.Enabled = false
	Me.edtBairro.Location = new System.Drawing.Point(280, 64)
	Me.edtBairro.MaxLength = 15
	Me.edtBairro.Name = "edtBairro"
	Me.edtBairro.Size = new System.Drawing.Size(152, 20)
	Me.edtBairro.TabIndex = 6
	Me.edtBairro.Text = ""
	' 
	' edtCEP
	' 
	Me.edtCEP.Enabled = false
	Me.edtCEP.Location = new System.Drawing.Point(8, 104)
	Me.edtCEP.MaxLength = 8
	Me.edtCEP.Name = "edtCEP"
	Me.edtCEP.Size = new System.Drawing.Size(72, 20)
	Me.edtCEP.TabIndex = 8
	Me.edtCEP.Text = ""
	' 
	' labCEP
	' 
	Me.labCEP.Location = new System.Drawing.Point(8, 88)
	Me.labCEP.Name = "labCEP"
	Me.labCEP.Size = new System.Drawing.Size(64, 16)
	Me.labCEP.TabIndex = 7
	Me.labCEP.Text = "CEP:"
	' 
	' edtCidade
	' 
	Me.edtCidade.Enabled = false
	Me.edtCidade.Location = new System.Drawing.Point(88, 104)
	Me.edtCidade.MaxLength = 30
	Me.edtCidade.Name = "edtCidade"
	Me.edtCidade.Size = new System.Drawing.Size(184, 20)
	Me.edtCidade.TabIndex = 10
	Me.edtCidade.Text = ""
	' 
	' labCidade
	' 
	Me.labCidade.Location = new System.Drawing.Point(88, 88)
	Me.labCidade.Name = "labCidade"
	Me.labCidade.Size = new System.Drawing.Size(64, 16)
	Me.labCidade.TabIndex = 9
	Me.labCidade.Text = "Cidade:"
	' 
	' labEstado
	' 
	Me.labEstado.Location = new System.Drawing.Point(280, 88)
	Me.labEstado.Name = "labEstado"
	Me.labEstado.Size = new System.Drawing.Size(64, 16)
	Me.labEstado.TabIndex = 11
	Me.labEstado.Text = "Estado:"
	' 
	' cmbEstado
	' 
	Me.cmbEstado.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
	Me.cmbEstado.Enabled = false
	Me.cmbEstado.Location = new System.Drawing.Point(280, 104)
	Me.cmbEstado.Name = "cmbEstado"
	Me.cmbEstado.Size = new System.Drawing.Size(152, 21)
	Me.cmbEstado.TabIndex = 12
	' 
	' frmCadEnderecos
	' 
	Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
	Me.ClientSize = new System.Drawing.Size(520, 165)
	Me.Controls.Add(Me.cmbEstado)
	Me.Controls.Add(Me.labEstado)
	Me.Controls.Add(Me.edtCidade)
	Me.Controls.Add(Me.labCidade)
	Me.Controls.Add(Me.edtCEP)
	Me.Controls.Add(Me.labCEP)
	Me.Controls.Add(Me.edtBairro)
	Me.Controls.Add(Me.labBairro)
	Me.Name = "frmCadEnderecos"
	Me.Text = "Cadastro de Endereços"
	Me.ResumeLayout(false)
    End Sub

#End Region

    protected overrides function ValidaDados(bTodosDados as boolean) as boolean
	MyBase.ValidaDados(bTodosDados)

        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text, _
            "Código não informado!")) then
          ValidaDados = false
          exit function
        end if
        if (bTodosDados) then
          if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text, _
            "Logradouro não informado!")) then
            ValidaDados = false
            exit function
           end if
	  if (RotinasGlobais.Rotinas.ValidaCampo(edtBairro.Text, _
		"Bairro não informado!")) then
            ValidaDados = false
            exit function
	  end if
	  if (RotinasGlobais.Rotinas.ValidaCampo(edtCEP.Text, _
		"CEP não informado!")) then
            ValidaDados = false
            exit function
	  end if
	  if (RotinasGlobais.Rotinas.ValidaCampo(edtCidade.Text, _
		"Cidade não informada!")) then
            ValidaDados = false
            exit function
	  end if
        end if
        ValidaDados = true
    end function
    protected overrides sub InformaLimpaDados(bInformar as boolean)
    	MyBase.InformaLimpaDados(bInformar)
    
    	if (bInformar) then
    	  edtBairro.Text=Campos(2).ToString()
    	  edtCEP.Text=Campos(3).ToString()
    	  edtCidade.Text=Campos(4).ToString()
    	  RecuperaEstado(Campos(5).ToString())
    	else 
    	  edtBairro.Clear()
    	  edtCEP.Clear()
    	  edtCidade.Clear()
    	  cmbEstado.SelectedIndex=0
    	end if
    end sub
    
    protected overrides sub HabilitaDados(bHabilita as boolean)
    	MyBase.HabilitaDados(bHabilita)
    
    	edtBairro.Enabled=bHabilita
    	edtCEP.Enabled=bHabilita
    	edtCidade.Enabled=bHabilita
    	cmbEstado.Enabled=bHabilita
    end sub

    private sub btnNovo_Click(sender as object, e as System.EventArgs) _
        Handles btnNovo.Click

        NovoDado(ConsultasSQL.ConsSQL.Endereco("N",edtCodigo.Text,"","","","",""))
    end sub

    private sub btnExcluir_Click(sender as object, e as System.EventArgs) _
        Handles btnExcluir.Click

        ExcluirDados(ConsultasSQL.ConsSQL.Endereco("D",edtCodigo.Text,"","","","",""))
    end sub

    private sub btnPesquisar_Click(sender as object, e as System.EventArgs) _
        Handles btnPesquisar.Click

        PesquisarDados(ConsultasSQL.ConsSQL.Endereco("S",edtCodigo.Text, _
	"","","","",""), "Endereco não encontrado!")
    end sub

    private sub btnSalvar_Click(sender as object, e as System.EventArgs) _
        Handles btnSalvar.Click

        SalvarDados(ConsultasSQL.ConsSQL.Endereco("S",edtCodigo.Text, _
	"","","","",""), _
        ConsultasSQL.ConsSQL.Endereco("U",edtCodigo.Text,edtDescricao.Text, _
	edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text), _
        ConsultasSQL.ConsSQL.Endereco("I",edtCodigo.Text,edtDescricao.Text, _
	edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text), _
        true)
    end sub

    private sub frmCadEnderecos_Closing(sender as object, _
        e as System.ComponentModel.CancelEventArgs) Handles MyBase.Closing

        frmPrincipal.fPrincipal.mnuCadEnderecos.Enabled=true
    end sub

    private sub AdicionaCombo()
    	cmbEstado.Items.Add("Pernambuco")
    	cmbEstado.Items.Add("Acre")
    	cmbEstado.Items.Add("Alagoas")
    	cmbEstado.Items.Add("Amapá")
    	cmbEstado.Items.Add("Amazonas")
    	cmbEstado.Items.Add("Bahia")
    	cmbEstado.Items.Add("Brasília")
    	cmbEstado.Items.Add("Ceará")
    	cmbEstado.Items.Add("Distrito Federal")
    	cmbEstado.Items.Add("Espírito Santo")
    	cmbEstado.Items.Add("Goiás")
    	cmbEstado.Items.Add("Mato Grosso")
    	cmbEstado.Items.Add("Mato Grosso do Sul")
    	cmbEstado.Items.Add("Minas Gerais")
    	cmbEstado.Items.Add("Pará")
    	cmbEstado.Items.Add("Paraíba")
    	cmbEstado.Items.Add("Paraná")
    	cmbEstado.Items.Add("Santa Catarina")
    	cmbEstado.Items.Add("Rio Grande do Norte")
    	cmbEstado.Items.Add("Rio Grande do Sul")
    	cmbEstado.Items.Add("Rio de Janeiro")
    	cmbEstado.Items.Add("Rondônia")
    	cmbEstado.Items.Add("Roraima")
    	cmbEstado.Items.Add("São Paulo")
    	cmbEstado.Items.Add("Sergipe")
    	cmbEstado.Items.Add("Tocantins")
    end sub
    
    private sub RecuperaEstado(sEstado as string)
     dim nCont as integer
	
     for nCont=0 to cmbEstado.Items.Count-1
    	if cmbEstado.Items(nCont).ToString()=sEstado then
    	   cmbEstado.SelectedIndex=nCont
    	end if
     next nCont
    end sub
    
    private sub frmCadEnderecos_Load(sender as object, e as System.EventArgs) _
	 Handles MyBase.Load

    	AdicionaCombo()
    	cmbEstado.SelectedIndex=0
    end sub

End Class

End NameSpace