Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmCadClientes
    Inherits Livrus.frmCadastros

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call
	ConsCampo = new ArrayList()
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

    public shared withevents fCadClientes as frmCadClientes
    private ConsCampo as ArrayList
    private sSexo as String

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    Private labEmail As System.Windows.Forms.Label
    Private edtEmail As System.Windows.Forms.TextBox
    Private edtIdentidade As System.Windows.Forms.TextBox
    Private labIdentidade As System.Windows.Forms.Label
    Private rdgSexo As System.Windows.Forms.GroupBox
    Private rbMasculino As System.Windows.Forms.RadioButton
    Private rbFeminino As System.Windows.Forms.RadioButton
    Private edtTelefone As System.Windows.Forms.TextBox
    Private labTelefone As System.Windows.Forms.Label
    Private edtDtNascimento As System.Windows.Forms.DateTimePicker
    Private labDtNascimento As System.Windows.Forms.Label
    Private grpEndereco As System.Windows.Forms.GroupBox
    Private WithEvents edtCodEndereco As System.Windows.Forms.TextBox
    Private WithEvents btnPEndereco As System.Windows.Forms.Button
    Private edtBairro As System.Windows.Forms.TextBox
    Private labBairro As System.Windows.Forms.Label
    Private edtLogradouro As System.Windows.Forms.TextBox
    Private labLogradouro As System.Windows.Forms.Label
    Private labEstado As System.Windows.Forms.Label
    Private edtCidade As System.Windows.Forms.TextBox
    Private labCidade As System.Windows.Forms.Label
    Private edtCEP As System.Windows.Forms.TextBox
    Private labCEP As System.Windows.Forms.Label
    Private edtEstado As System.Windows.Forms.TextBox
    Private edtPais As System.Windows.Forms.TextBox
    Private WithEvents edtCodPais As System.Windows.Forms.TextBox
    Private labPais As System.Windows.Forms.Label
    Private WithEvents btnPPais As System.Windows.Forms.Button
    Private WithEvents btnPProfissao As System.Windows.Forms.Button
    Private edtProfissao As System.Windows.Forms.TextBox
    Private WithEvents edtCodProfissao As System.Windows.Forms.TextBox
    Private labProfissao As System.Windows.Forms.Label

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
	Me.labEmail = new System.Windows.Forms.Label()
	Me.edtEmail = new System.Windows.Forms.TextBox()
	Me.edtIdentidade = new System.Windows.Forms.TextBox()
	Me.labIdentidade = new System.Windows.Forms.Label()
	Me.rdgSexo = new System.Windows.Forms.GroupBox()
	Me.rbFeminino = new System.Windows.Forms.RadioButton()
	Me.rbMasculino = new System.Windows.Forms.RadioButton()
	Me.edtTelefone = new System.Windows.Forms.TextBox()
	Me.labTelefone = new System.Windows.Forms.Label()
	Me.edtDtNascimento = new System.Windows.Forms.DateTimePicker()
	Me.labDtNascimento = new System.Windows.Forms.Label()
	Me.grpEndereco = new System.Windows.Forms.GroupBox()
	Me.edtEstado = new System.Windows.Forms.TextBox()
	Me.labEstado = new System.Windows.Forms.Label()
	Me.edtCidade = new System.Windows.Forms.TextBox()
	Me.labCidade = new System.Windows.Forms.Label()
	Me.edtCEP = new System.Windows.Forms.TextBox()
	Me.labCEP = new System.Windows.Forms.Label()
	Me.edtBairro = new System.Windows.Forms.TextBox()
	Me.labBairro = new System.Windows.Forms.Label()
	Me.edtLogradouro = new System.Windows.Forms.TextBox()
	Me.labLogradouro = new System.Windows.Forms.Label()
	Me.btnPEndereco = new System.Windows.Forms.Button()
	Me.edtCodEndereco = new System.Windows.Forms.TextBox()
	Me.edtPais = new System.Windows.Forms.TextBox()
	Me.edtCodPais = new System.Windows.Forms.TextBox()
	Me.labPais = new System.Windows.Forms.Label()
	Me.btnPPais = new System.Windows.Forms.Button()
	Me.btnPProfissao = new System.Windows.Forms.Button()
	Me.edtProfissao = new System.Windows.Forms.TextBox()
	Me.edtCodProfissao = new System.Windows.Forms.TextBox()
	Me.labProfissao = new System.Windows.Forms.Label()
	Me.rdgSexo.SuspendLayout()
	Me.grpEndereco.SuspendLayout()
	Me.SuspendLayout()
	' 
	' labCodigo
	' 
	Me.labCodigo.Name = "labCodigo"
	Me.labCodigo.Text = "CPF:"
	' 
	' edtCodigo
	' 
	Me.edtCodigo.Name = "edtCodigo"
    Me.edtCodigo.MaxLength = 14
	' 
	' labDescricao
	' 
	Me.labDescricao.Name = "labDescricao"
	Me.labDescricao.Text = "Nome:"
	' 
	' edtDescricao
	' 
	Me.edtDescricao.Name = "edtDescricao"
	Me.edtDescricao.Size = new System.Drawing.Size(320, 20)
	' 
	' btnNovo
	' 
	Me.btnNovo.Name = "btnNovo"
	' 
	' btnPesquisar
	' 
	Me.btnPesquisar.Location = new System.Drawing.Point(440, 8)
	Me.btnPesquisar.Name = "btnPesquisar"
	Me.btnPesquisar.TabIndex = 23
	' 
	' btnAnterior
	' 
	Me.btnAnterior.Location = new System.Drawing.Point(440, 40)
	Me.btnAnterior.Name = "btnAnterior"
	Me.btnAnterior.TabIndex = 24
	' 
	' btnProximo
	' 
	Me.btnProximo.Location = new System.Drawing.Point(440, 72)
	Me.btnProximo.Name = "btnProximo"
	Me.btnProximo.TabIndex = 25
	' 
	' btnFechar
	' 
	Me.btnFechar.Location = new System.Drawing.Point(440, 424)
	Me.btnFechar.Name = "btnFechar"
	Me.btnFechar.TabIndex = 29
	' 
	' btnLimpar
	' 
	Me.btnLimpar.Location = new System.Drawing.Point(360, 424)
	Me.btnLimpar.Name = "btnLimpar"
	Me.btnLimpar.TabIndex = 28
	' 
	' btnExcluir
	' 
	Me.btnExcluir.Location = new System.Drawing.Point(280, 424)
	Me.btnExcluir.Name = "btnExcluir"
	Me.btnExcluir.TabIndex = 27
	' 
	' btnSalvar
	' 
	Me.btnSalvar.Location = new System.Drawing.Point(200, 424)
	Me.btnSalvar.Name = "btnSalvar"
	Me.btnSalvar.TabIndex = 26
	' 
	' labEmail
	' 
	Me.labEmail.Location = new System.Drawing.Point(8, 88)
	Me.labEmail.Name = "labEmail"
	Me.labEmail.Size = new System.Drawing.Size(100, 16)
	Me.labEmail.TabIndex = 5
	Me.labEmail.Text = "E-mail:"
	' 
	' edtEmail
	' 
	Me.edtEmail.Enabled = false
	Me.edtEmail.Location = new System.Drawing.Point(8, 104)
	Me.edtEmail.MaxLength = 30
	Me.edtEmail.Name = "edtEmail"
	Me.edtEmail.Size = new System.Drawing.Size(320, 20)
	Me.edtEmail.TabIndex = 6
	Me.edtEmail.Text = ""
	' 
	' edtIdentidade
	' 
	Me.edtIdentidade.Enabled = false
	Me.edtIdentidade.Location = new System.Drawing.Point(336, 104)
	Me.edtIdentidade.MaxLength = 10
	Me.edtIdentidade.Name = "edtIdentidade"
	Me.edtIdentidade.Size = new System.Drawing.Size(92, 20)
	Me.edtIdentidade.TabIndex = 8
	Me.edtIdentidade.Text = ""
	' 
	' labIdentidade
	' 
	Me.labIdentidade.Location = new System.Drawing.Point(336, 88)
	Me.labIdentidade.Name = "labIdentidade"
	Me.labIdentidade.Size = new System.Drawing.Size(68, 16)
	Me.labIdentidade.TabIndex = 7
	Me.labIdentidade.Text = "Identidade:"
	' 
	' rdgSexo
	' 
	Me.rdgSexo.Controls.Add(Me.rbFeminino)
	Me.rdgSexo.Controls.Add(Me.rbMasculino)
	Me.rdgSexo.Location = new System.Drawing.Point(8, 128)
	Me.rdgSexo.Name = "rdgSexo"
	Me.rdgSexo.Size = new System.Drawing.Size(184, 40)
	Me.rdgSexo.TabIndex = 9
	Me.rdgSexo.TabStop = false
	Me.rdgSexo.Text = "Sexo"
	' 
	' rbFeminino
	' 
	Me.rbFeminino.Location = new System.Drawing.Point(104, 16)
	Me.rbFeminino.Name = "rbFeminino"
	Me.rbFeminino.Size = new System.Drawing.Size(72, 16)
	Me.rbFeminino.TabIndex = 1
	Me.rbFeminino.Text = "Feminino"
	' 
	' rbMasculino
	' 
	Me.rbMasculino.Enabled = false
	Me.rbMasculino.Location = new System.Drawing.Point(16, 16)
	Me.rbMasculino.Name = "rbMasculino"
	Me.rbMasculino.Size = new System.Drawing.Size(80, 16)
	Me.rbMasculino.TabIndex = 0
	Me.rbMasculino.Text = "Masculino"
	' 
	' edtTelefone
	' 
	Me.edtTelefone.Enabled = false
	Me.edtTelefone.Location = new System.Drawing.Point(200, 144)
	Me.edtTelefone.MaxLength = 17
	Me.edtTelefone.Name = "edtTelefone"
	Me.edtTelefone.Size = new System.Drawing.Size(128, 20)
	Me.edtTelefone.TabIndex = 11
	Me.edtTelefone.Text = ""
	' 
	' labTelefone
	' 
	Me.labTelefone.Location = new System.Drawing.Point(200, 128)
	Me.labTelefone.Name = "labTelefone"
	Me.labTelefone.Size = new System.Drawing.Size(68, 16)
	Me.labTelefone.TabIndex = 10
	Me.labTelefone.Text = "Telefone:"
	' 
	' edtDtNascimento
	' 
	Me.edtDtNascimento.Enabled = false
	Me.edtDtNascimento.Format = System.Windows.Forms.DateTimePickerFormat.Short
	Me.edtDtNascimento.Location = new System.Drawing.Point(336, 144)
	Me.edtDtNascimento.Name = "edtDtNascimento"
	Me.edtDtNascimento.Size = new System.Drawing.Size(96, 20)
	Me.edtDtNascimento.TabIndex = 13
	' 
	' labDtNascimento
	' 
	Me.labDtNascimento.Location = new System.Drawing.Point(336, 128)
	Me.labDtNascimento.Name = "labDtNascimento"
	Me.labDtNascimento.Size = new System.Drawing.Size(96, 16)
	Me.labDtNascimento.TabIndex = 12
	Me.labDtNascimento.Text = "Dt. Nascimento:"
	' 
	' grpEndereco
	' 
	Me.grpEndereco.Controls.Add(Me.edtEstado)
	Me.grpEndereco.Controls.Add(Me.labEstado)
	Me.grpEndereco.Controls.Add(Me.edtCidade)
	Me.grpEndereco.Controls.Add(Me.labCidade)
	Me.grpEndereco.Controls.Add(Me.edtCEP)
	Me.grpEndereco.Controls.Add(Me.labCEP)
	Me.grpEndereco.Controls.Add(Me.edtBairro)
	Me.grpEndereco.Controls.Add(Me.labBairro)
	Me.grpEndereco.Controls.Add(Me.edtLogradouro)
	Me.grpEndereco.Controls.Add(Me.labLogradouro)
	Me.grpEndereco.Controls.Add(Me.btnPEndereco)
	Me.grpEndereco.Controls.Add(Me.edtCodEndereco)
	Me.grpEndereco.Location = new System.Drawing.Point(8, 176)
	Me.grpEndereco.Name = "grpEndereco"
	Me.grpEndereco.Size = new System.Drawing.Size(424, 152)
	Me.grpEndereco.TabIndex = 14
	Me.grpEndereco.TabStop = false
	Me.grpEndereco.Text = "Endereço"
	' 
	' edtEstado
	' 
	Me.edtEstado.Enabled = false
	Me.edtEstado.Location = new System.Drawing.Point(280, 120)
	Me.edtEstado.MaxLength = 10
	Me.edtEstado.Name = "edtEstado"
	Me.edtEstado.Size = new System.Drawing.Size(128, 20)
	Me.edtEstado.TabIndex = 11
	Me.edtEstado.Text = ""
	' 
	' labEstado
	' 
	Me.labEstado.Location = new System.Drawing.Point(280, 104)
	Me.labEstado.Name = "labEstado"
	Me.labEstado.Size = new System.Drawing.Size(64, 16)
	Me.labEstado.TabIndex = 10
	Me.labEstado.Text = "Estado:"
	' 
	' edtCidade
	' 
	Me.edtCidade.Enabled = false
	Me.edtCidade.Location = new System.Drawing.Point(88, 120)
	Me.edtCidade.MaxLength = 30
	Me.edtCidade.Name = "edtCidade"
	Me.edtCidade.Size = new System.Drawing.Size(184, 20)
	Me.edtCidade.TabIndex = 9
	Me.edtCidade.Text = ""
	' 
	' labCidade
	' 
	Me.labCidade.Location = new System.Drawing.Point(88, 104)
	Me.labCidade.Name = "labCidade"
	Me.labCidade.Size = new System.Drawing.Size(64, 16)
	Me.labCidade.TabIndex = 8
	Me.labCidade.Text = "Cidade:"
	' 
	' edtCEP
	' 
	Me.edtCEP.Enabled = false
	Me.edtCEP.Location = new System.Drawing.Point(8, 120)
	Me.edtCEP.MaxLength = 8
	Me.edtCEP.Name = "edtCEP"
	Me.edtCEP.Size = new System.Drawing.Size(72, 20)
	Me.edtCEP.TabIndex = 7
	Me.edtCEP.Text = ""
	' 
	' labCEP
	' 
	Me.labCEP.Location = new System.Drawing.Point(8, 104)
	Me.labCEP.Name = "labCEP"
	Me.labCEP.Size = new System.Drawing.Size(64, 16)
	Me.labCEP.TabIndex = 6
	Me.labCEP.Text = "CEP:"
	' 
	' edtBairro
	' 
	Me.edtBairro.Enabled = false
	Me.edtBairro.Location = new System.Drawing.Point(280, 74)
	Me.edtBairro.MaxLength = 10
	Me.edtBairro.Name = "edtBairro"
	Me.edtBairro.Size = new System.Drawing.Size(128, 20)
	Me.edtBairro.TabIndex = 5
	Me.edtBairro.Text = ""
	' 
	' labBairro
	' 
	Me.labBairro.Location = new System.Drawing.Point(280, 58)
	Me.labBairro.Name = "labBairro"
	Me.labBairro.Size = new System.Drawing.Size(68, 16)
	Me.labBairro.TabIndex = 4
	Me.labBairro.Text = "Bairro:"
	' 
	' edtLogradouro
	' 
	Me.edtLogradouro.Enabled = false
	Me.edtLogradouro.Location = new System.Drawing.Point(8, 74)
	Me.edtLogradouro.MaxLength = 30
	Me.edtLogradouro.Name = "edtLogradouro"
	Me.edtLogradouro.Size = new System.Drawing.Size(264, 20)
	Me.edtLogradouro.TabIndex = 3
	Me.edtLogradouro.Text = ""
	' 
	' labLogradouro
	' 
	Me.labLogradouro.Location = new System.Drawing.Point(8, 58)
	Me.labLogradouro.Name = "labLogradouro"
	Me.labLogradouro.Size = new System.Drawing.Size(78, 16)
	Me.labLogradouro.TabIndex = 2
	Me.labLogradouro.Text = "Logradouro:"
	' 
	' btnPEndereco
	' 
	Me.btnPEndereco.Enabled = false
	Me.btnPEndereco.Location = new System.Drawing.Point(104, 24)
	Me.btnPEndereco.Name = "btnPEndereco"
	Me.btnPEndereco.Size = new System.Drawing.Size(22, 20)
	Me.btnPEndereco.TabIndex = 1
	Me.btnPEndereco.Text = "..."
	' 
	' edtCodEndereco
	' 
	Me.edtCodEndereco.Enabled = false
	Me.edtCodEndereco.Location = new System.Drawing.Point(8, 24)
	Me.edtCodEndereco.MaxLength = 10
	Me.edtCodEndereco.Name = "edtCodEndereco"
	Me.edtCodEndereco.Size = new System.Drawing.Size(92, 20)
	Me.edtCodEndereco.TabIndex = 0
	Me.edtCodEndereco.Text = ""
	' 
	' edtPais
	' 
	Me.edtPais.Enabled = false
	Me.edtPais.Location = new System.Drawing.Point(92, 352)
	Me.edtPais.MaxLength = 30
	Me.edtPais.Name = "edtPais"
	Me.edtPais.Size = new System.Drawing.Size(224, 20)
	Me.edtPais.TabIndex = 17
	Me.edtPais.Text = ""
	' 
	' edtCodPais
	' 
	Me.edtCodPais.Enabled = false
	Me.edtCodPais.Location = new System.Drawing.Point(8, 352)
	Me.edtCodPais.MaxLength = 10
	Me.edtCodPais.Name = "edtCodPais"
	Me.edtCodPais.Size = new System.Drawing.Size(80, 20)
	Me.edtCodPais.TabIndex = 16
	Me.edtCodPais.Text = ""
	' 
	' labPais
	' 
	Me.labPais.Location = new System.Drawing.Point(8, 336)
	Me.labPais.Name = "labPais"
	Me.labPais.Size = new System.Drawing.Size(88, 16)
	Me.labPais.TabIndex = 15
	Me.labPais.Text = "País de origem:"
	' 
	' btnPPais
	' 
	Me.btnPPais.Enabled = false
	Me.btnPPais.Location = new System.Drawing.Point(320, 352)
	Me.btnPPais.Name = "btnPPais"
	Me.btnPPais.Size = new System.Drawing.Size(22, 20)
	Me.btnPPais.TabIndex = 18
	Me.btnPPais.Text = "..."
	' 
	' btnPProfissao
	' 
	Me.btnPProfissao.Enabled = false
	Me.btnPProfissao.Location = new System.Drawing.Point(320, 392)
	Me.btnPProfissao.Name = "btnPProfissao"
	Me.btnPProfissao.Size = new System.Drawing.Size(22, 20)
	Me.btnPProfissao.TabIndex = 22
	Me.btnPProfissao.Text = "..."
	' 
	' edtProfissao
	' 
	Me.edtProfissao.Enabled = false
	Me.edtProfissao.Location = new System.Drawing.Point(96, 392)
	Me.edtProfissao.MaxLength = 30
	Me.edtProfissao.Name = "edtProfissao"
	Me.edtProfissao.Size = new System.Drawing.Size(224, 20)
	Me.edtProfissao.TabIndex = 21
	Me.edtProfissao.Text = ""
	' 
	' edtCodProfissao
	' 
	Me.edtCodProfissao.Enabled = false
	Me.edtCodProfissao.Location = new System.Drawing.Point(8, 392)
	Me.edtCodProfissao.MaxLength = 10
	Me.edtCodProfissao.Name = "edtCodProfissao"
	Me.edtCodProfissao.Size = new System.Drawing.Size(80, 20)
	Me.edtCodProfissao.TabIndex = 20
	Me.edtCodProfissao.Text = ""
	' 
	' labProfissao
	' 
	Me.labProfissao.Location = new System.Drawing.Point(8, 376)
	Me.labProfissao.Name = "labProfissao"
	Me.labProfissao.Size = new System.Drawing.Size(88, 16)
	Me.labProfissao.TabIndex = 19
	Me.labProfissao.Text = "Profissão:"
	' 
	' frmCadClientes
	' 
	Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
	Me.ClientSize = new System.Drawing.Size(520, 453)
	Me.Controls.Add(Me.btnPProfissao)
	Me.Controls.Add(Me.edtProfissao)
	Me.Controls.Add(Me.edtCodProfissao)
	Me.Controls.Add(Me.labProfissao)
	Me.Controls.Add(Me.btnPPais)
	Me.Controls.Add(Me.edtPais)
	Me.Controls.Add(Me.edtCodPais)
	Me.Controls.Add(Me.labPais)
	Me.Controls.Add(Me.grpEndereco)
	Me.Controls.Add(Me.labDtNascimento)
	Me.Controls.Add(Me.edtDtNascimento)
	Me.Controls.Add(Me.edtTelefone)
	Me.Controls.Add(Me.labTelefone)
	Me.Controls.Add(Me.rdgSexo)
	Me.Controls.Add(Me.edtIdentidade)
	Me.Controls.Add(Me.labIdentidade)
	Me.Controls.Add(Me.edtEmail)
	Me.Controls.Add(Me.labEmail)
	Me.Name = "frmCadClientes"
	Me.Text = "Cadastro de Clientes"
	Me.rdgSexo.ResumeLayout(false)
	Me.grpEndereco.ResumeLayout(false)
	Me.ResumeLayout(false)
    End Sub

#End Region

    protected overrides function ValidaDados(bTodosDados as boolean) as boolean
        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text, _
            "CPF não informado!")) then
          ValidaDados = false
          exit function
        end if
        if (bTodosDados) then
           if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text, _
               "Nome não informado!")) then
               ValidaDados = false
               exit function
           end if
           if (RotinasGlobais.Rotinas.ValidaCampo(edtEmail.Text, _
            	"E-mail não informado!")) then
               ValidaDados = false
               exit function
           end if           
           if (rbMasculino.Checked=false and rbFeminino.Checked=false) then
              MessageBox.Show(Me,"Sexo não informado!", _
              frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
              MessageBoxIcon.Error)
              ValidaDados = false
              exit function
           end if
           if (RotinasGlobais.Rotinas.ValidaCampo(edtTelefone.Text, _
            	"Telefone não informado!")) then
              ValidaDados = false
              exit function
           end if
           if (RotinasGlobais.Rotinas.ValidaCampo(edtCodEndereco.Text, _
            	"Endereço não informado!")) then
              ValidaDados = false
              exit function
           end if
           if (RotinasGlobais.Rotinas.ValidaCampo(edtCodPais.Text, _
            	"País não informado!")) then
              ValidaDados = false
              exit function
           end if
           if (RotinasGlobais.Rotinas.ValidaCampo(edtCodProfissao.Text, _
            	"Profissão não informada!")) then
              ValidaDados = false
              exit function
           end if
        end if
        ValidaDados = true
    end function

    protected overrides sub InformaLimpaDados(bInformar as boolean)
      MyBase.InformaLimpaDados(bInformar)
    
      if bInformar then
    	edtEmail.Text=Campos(2).ToString()
    	edtIdentidade.Text=Campos(3).ToString()
    	if Campos(4).ToString()="M" then
    	   rbMasculino.Checked=true
    	   rbFeminino.Checked=false
    	else 
    	  rbMasculino.Checked=false
    	  rbFeminino.Checked=true
    	end if
    	edtTelefone.Text=Campos(5).ToString()
    	edtDtNascimento.Text=RotinasGlobais.Rotinas.FormataDataStr( _
    						 Campos(6).ToString(),"dd/MM/yyyy")
    	edtCodEndereco.Text=Campos(7).ToString()
    	edtLogradouro.Text=Campos(8).ToString()
    	edtBairro.Text=Campos(9).ToString()
    	edtCEP.Text=Campos(10).ToString()
    	edtCidade.Text=Campos(11).ToString()
    	edtEstado.Text=Campos(12).ToString()
    	edtCodPais.Text=Campos(13).ToString()
    	edtPais.Text=Campos(14).ToString()
    	edtCodProfissao.Text=Campos(15).ToString()
    	edtProfissao.Text=Campos(16).ToString()
      else
    	edtEmail.Clear()
    	edtIdentidade.Clear()
    	rbMasculino.Checked=false
    	rbFeminino.Checked=false
    	edtTelefone.Clear()
    	edtDtNascimento.Value=DateTime.Now
    	edtCodEndereco.Clear()
    	edtLogradouro.Clear()
    	edtBairro.Clear()
    	edtCEP.Clear()
    	edtCidade.Clear()
    	edtEstado.Clear()
    	edtCodPais.Clear()
    	edtPais.Clear()
    	edtCodProfissao.Clear()
    	edtProfissao.Clear()
      end if
    
    end sub
    
    protected overrides sub HabilitaDados(bHabilita as boolean)
    	 MyBase.HabilitaDados(bHabilita)
    
    	 edtEmail.Enabled=bHabilita
    	 edtIdentidade.Enabled=bHabilita
    	 rbMasculino.Enabled=bHabilita
    	 rbFeminino.Enabled=bHabilita
    	 edtTelefone.Enabled=bHabilita
    	 edtDtNascimento.Enabled=bHabilita
    	 edtCodEndereco.Enabled=bHabilita
    	 btnPEndereco.Enabled=bHabilita
    	 edtCodPais.Enabled=bHabilita
    	 btnPPais.Enabled=bHabilita
    	 edtCodProfissao.Enabled=bHabilita
    	 btnPProfissao.Enabled=bHabilita
    end sub


    private sub btnExcluir_Click(sender as object, e as System.EventArgs) _
        Handles btnExcluir.Click

        ExcluirDados(ConsultasSQL.ConsSQL.Cliente("D",edtCodigo.Text, _
	"","","","","","","","",""))
    end sub

    private sub btnPesquisar_Click(sender as object, e as System.EventArgs) _
        Handles btnPesquisar.Click

        PesquisarDados(ConsultasSQL.ConsSQL.Cliente("S",edtCodigo.Text, _
	"","","","","","","","",""), "Cliente não encontrado!")
    end sub

    private sub btnSalvar_Click(sender as object, e as System.EventArgs) _
        Handles btnSalvar.Click
      
        if rbMasculino.Checked then
            sSexo="M"
        else
            sSexo="F"
	end if

        SalvarDados(ConsultasSQL.ConsSQL.Cliente("S",edtCodigo.Text, _
	"","","","","","","","",""), _
	ConsultasSQL.ConsSQL.Cliente("U",edtCodigo.Text,edtDescricao.Text, _
	edtEmail.Text,edtIdentidade.Text,sSexo,edtTelefone.Text, _
	edtDtNascimento.Value.ToString("MM/dd/yyyy"), _
	edtCodEndereco.Text,edtCodPais.Text,edtCodProfissao.Text), _
	ConsultasSQL.ConsSQL.Cliente("I",edtCodigo.Text,edtDescricao.Text, _
	edtEmail.Text,edtIdentidade.Text,sSexo,edtTelefone.Text, _
	edtDtNascimento.Value.ToString("MM/dd/yyyy"), _
	edtCodEndereco.Text,edtCodPais.Text,edtCodProfissao.Text), _
        true)
    end sub

    private sub frmCadClientes_Closing(sender as object, _
        e as System.ComponentModel.CancelEventArgs) Handles MyBase.Closing

        frmPrincipal.fPrincipal.tlbClientes.Enabled=true
        frmPrincipal.fPrincipal.mnuCadClientes.Enabled=true
    end sub

    protected Overrides sub edtCodigo_Leave(sender as object, e as System.EventArgs) _
	 Handles edtCodigo.Leave

    	if (edtCodigo.Text<>"") then
    	  if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.Text)=false) then
              MessageBox.Show(Me,"CPF inválido!", _
              frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
              MessageBoxIcon.Error)
              edtCodigo.Clear()
              edtCodigo.Focus()
    	  end if
    	end if
    end sub
    
    private sub edtCodEndereco_Leave(sender as object, e as System.EventArgs) _
	 Handles edtCodEndereco.Leave

      if (edtCodEndereco.Text<>"") then
    	edtLogradouro.Text= _
    	RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
    	edtCodEndereco.Text,ConsultasSQL.ConsSQL.Endereco("S", _
    	edtCodEndereco.Text,"","","","",""),"Endereço não encontrado!")
    	if (edtLogradouro.Text<>"") then
    	  edtBairro.Text=ConsCampo(2).ToString()
    	  edtCEP.Text=ConsCampo(3).ToString()
    	  edtCidade.Text=ConsCampo(4).ToString()
    	  edtEstado.Text=ConsCampo(5).ToString()
    	else 
    	  edtCodEndereco.Focus()
    	  edtLogradouro.Clear()
    	  edtBairro.Clear()
    	  edtCEP.Clear()
    	  edtCidade.Clear()
    	  edtEstado.Clear()
    	end if
      else 
    	  edtLogradouro.Clear()
    	  edtBairro.Clear()
    	  edtCEP.Clear()
    	  edtCidade.Clear()
    	  edtEstado.Clear()
      end if
    end sub
    
    private sub edtCodPais_Leave(sender as object, e as System.EventArgs) _
	 Handles edtCodPais.Leave

    	if (edtCodPais.Text<>"") then
    	   edtPais.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
    	   ConsultasSQL.ConsSQL.Pais("S",edtCodPais.Text,""), _
    	   "País não encontrado!")
    	   if (edtPais.Text="") then
    		 edtCodPais.Clear()
    		 edtCodPais.Focus()
    	   end if
    	 else
    		edtPais.Clear()
    	 end if
    end sub
    
    private sub edtCodProfissao_Leave(sender as object, e as System.EventArgs) _
	 Handles edtCodProfissao.Leave

      if (edtCodProfissao.Text<>"") then
         edtProfissao.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
         edtCodProfissao.Text,ConsultasSQL.ConsSQL.Profissao("S", _
         edtCodProfissao.Text,""),"Profissão não encontrado!")
         if (edtProfissao.Text="") then
            edtCodProfissao.Clear()
            edtCodProfissao.Focus()
         end if
       else
           edtProfissao.Clear()
       end if	
    end sub
    
    private sub btnPEndereco_Click(sender as object, e as System.EventArgs) _
	 Handles btnPEndereco.Click

    	dim pfConEnderecos as frmConEnderecos = new frmConEnderecos()
    	pfConEnderecos.ShowDialog()
    	edtCodEndereco.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    	edtCodEndereco_Leave(Me, Nothing)
    end sub
    
    private sub btnPPais_Click(sender as object, e as System.EventArgs) _
	 Handles btnPPais.Click

    	dim pfConPaises as frmConPaises = new frmConPaises()
    	pfConPaises.ShowDialog()
    	edtCodPais.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    	edtCodPais_Leave(Me,Nothing)
    end sub
    
    private sub btnPProfissao_Click(sender as object, e as System.EventArgs) _
	 Handles btnPProfissao.Click

    	dim pfConProfissoes as frmConProfissoes = new frmConProfissoes()
    	pfConProfissoes.ShowDialog()
    	edtCodProfissao.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    	edtCodProfissao_Leave(Me,Nothing)
    end sub

End Class

End NameSpace