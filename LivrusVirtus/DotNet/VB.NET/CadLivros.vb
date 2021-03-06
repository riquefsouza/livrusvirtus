Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmCadLivros
    Inherits Livrus.frmCadastros

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call
	slIdiomas = new ArrayList()
	slAssuntos = new ArrayList()
	slAutores = new ArrayList()
	ConsCampo = new ArrayList()
	ConsLista = new ArrayList()
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

    public shared withevents fCadLivros as frmCadLivros
    private slIdiomas, slAssuntos, slAutores, ConsCampo, ConsLista as ArrayList
    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    private labEdicao As System.Windows.Forms.Label 
    private edtEdicao As System.Windows.Forms.NumericUpDown 
    private edtAnoPubli As System.Windows.Forms.NumericUpDown 
    private labAnoPubli As System.Windows.Forms.Label 
    private WithEvents btnPAssunto As System.Windows.Forms.Button 
    private edtAssunto As System.Windows.Forms.TextBox 
    private WithEvents edtCodAssunto As System.Windows.Forms.TextBox 
    private labAssunto As System.Windows.Forms.Label 
    private WithEvents btnPEditora As System.Windows.Forms.Button 
    private edtEditora As System.Windows.Forms.TextBox 
    private WithEvents edtCodEditora As System.Windows.Forms.TextBox 
    private labEditora As System.Windows.Forms.Label 
    private WithEvents btnAdAssuntos As System.Windows.Forms.Button 
    private edtVolume As System.Windows.Forms.NumericUpDown 
    private labVolume As System.Windows.Forms.Label 
    private edtNPaginas As System.Windows.Forms.NumericUpDown 
    private labNPaginas As System.Windows.Forms.Label 
    private labIdioma As System.Windows.Forms.Label 
    private cmbIdioma As System.Windows.Forms.ComboBox 
    private WithEvents lstAssuntos As System.Windows.Forms.ListBox 
    private labPreco As System.Windows.Forms.Label 
    private WithEvents edtPreco As System.Windows.Forms.TextBox 
    private edtQtdEstoque As System.Windows.Forms.NumericUpDown 
    private labQtdEstoque As System.Windows.Forms.Label 
    private WithEvents lstAutores As System.Windows.Forms.ListBox 
    private WithEvents btnAdAutores As System.Windows.Forms.Button 
    private WithEvents btnPAutor As System.Windows.Forms.Button 
    private edtAutor As System.Windows.Forms.TextBox 
    private WithEvents edtCodAutor As System.Windows.Forms.TextBox 
    private labAutor As System.Windows.Forms.Label 

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
	Me.labEdicao = new System.Windows.Forms.Label()
	Me.edtEdicao = new System.Windows.Forms.NumericUpDown()
	Me.edtAnoPubli = new System.Windows.Forms.NumericUpDown()
	Me.labAnoPubli = new System.Windows.Forms.Label()
	Me.btnPAssunto = new System.Windows.Forms.Button()
	Me.edtAssunto = new System.Windows.Forms.TextBox()
	Me.edtCodAssunto = new System.Windows.Forms.TextBox()
	Me.labAssunto = new System.Windows.Forms.Label()
	Me.btnPEditora = new System.Windows.Forms.Button()
	Me.edtEditora = new System.Windows.Forms.TextBox()
	Me.edtCodEditora = new System.Windows.Forms.TextBox()
	Me.labEditora = new System.Windows.Forms.Label()
	Me.btnAdAssuntos = new System.Windows.Forms.Button()
	Me.edtVolume = new System.Windows.Forms.NumericUpDown()
	Me.labVolume = new System.Windows.Forms.Label()
	Me.edtNPaginas = new System.Windows.Forms.NumericUpDown()
	Me.labNPaginas = new System.Windows.Forms.Label()
	Me.labIdioma = new System.Windows.Forms.Label()
	Me.cmbIdioma = new System.Windows.Forms.ComboBox()
	Me.lstAssuntos = new System.Windows.Forms.ListBox()
	Me.labPreco = new System.Windows.Forms.Label()
	Me.edtPreco = new System.Windows.Forms.TextBox()
	Me.edtQtdEstoque = new System.Windows.Forms.NumericUpDown()
	Me.labQtdEstoque = new System.Windows.Forms.Label()
	Me.lstAutores = new System.Windows.Forms.ListBox()
	Me.btnAdAutores = new System.Windows.Forms.Button()
	Me.btnPAutor = new System.Windows.Forms.Button()
	Me.edtAutor = new System.Windows.Forms.TextBox()
	Me.edtCodAutor = new System.Windows.Forms.TextBox()
	Me.labAutor = new System.Windows.Forms.Label()
	CType(Me.edtEdicao,System.ComponentModel.ISupportInitialize).BeginInit()
	CType(Me.edtAnoPubli,System.ComponentModel.ISupportInitialize).BeginInit()
	CType(Me.edtVolume,System.ComponentModel.ISupportInitialize).BeginInit()
	CType(Me.edtNPaginas,System.ComponentModel.ISupportInitialize).BeginInit()
	CType(Me.edtQtdEstoque,System.ComponentModel.ISupportInitialize).BeginInit()
	Me.SuspendLayout()
	' 
	' labCodigo
	' 
	Me.labCodigo.Name = "labCodigo"
	Me.labCodigo.Text = "ISBN:"
	' 
	' edtCodigo
	' 
	Me.edtCodigo.Name = "edtCodigo"
    Me.edtCodigo.MaxLength = 13
	' 
	' labDescricao
	' 
	Me.labDescricao.Name = "labDescricao"
	Me.labDescricao.Text = "T�tulo:"
	' 
	' edtDescricao
	' 
	Me.edtDescricao.Name = "edtDescricao"
	Me.edtDescricao.Size = new System.Drawing.Size(304, 20)
	' 
	' btnNovo
	' 
	Me.btnNovo.Name = "btnNovo"
	' 
	' btnPesquisar
	' 
	Me.btnPesquisar.Location = new System.Drawing.Point(440, 8)
	Me.btnPesquisar.Name = "btnPesquisar"
	Me.btnPesquisar.TabIndex = 35
	' 
	' btnAnterior
	' 
	Me.btnAnterior.Location = new System.Drawing.Point(440, 40)
	Me.btnAnterior.Name = "btnAnterior"
	Me.btnAnterior.TabIndex = 36
	' 
	' btnProximo
	' 
	Me.btnProximo.Location = new System.Drawing.Point(440, 72)
	Me.btnProximo.Name = "btnProximo"
	Me.btnProximo.TabIndex = 37
	' 
	' btnFechar
	' 
	Me.btnFechar.Location = new System.Drawing.Point(440, 352)
	Me.btnFechar.Name = "btnFechar"
	Me.btnFechar.TabIndex = 41
	' 
	' btnLimpar
	' 
	Me.btnLimpar.Location = new System.Drawing.Point(360, 352)
	Me.btnLimpar.Name = "btnLimpar"
	Me.btnLimpar.TabIndex = 40
	' 
	' btnExcluir
	' 
	Me.btnExcluir.Location = new System.Drawing.Point(280, 352)
	Me.btnExcluir.Name = "btnExcluir"
	Me.btnExcluir.TabIndex = 39
	' 
	' btnSalvar
	' 
	Me.btnSalvar.Location = new System.Drawing.Point(200, 352)
	Me.btnSalvar.Name = "btnSalvar"
	Me.btnSalvar.TabIndex = 38
	' 
	' labEdicao
	' 
	Me.labEdicao.Location = new System.Drawing.Point(320, 48)
	Me.labEdicao.Name = "labEdicao"
	Me.labEdicao.Size = new System.Drawing.Size(48, 16)
	Me.labEdicao.TabIndex = 5
	Me.labEdicao.Text = "Edi��o"
	' 
	' edtEdicao
	' 
	Me.edtEdicao.Enabled = false
	Me.edtEdicao.Location = new System.Drawing.Point(320, 64)
	Me.edtEdicao.Maximum = new decimal(new integer() {9999,0,0,0})
	Me.edtEdicao.Minimum = new decimal(new integer() {1,0,0,0})
	Me.edtEdicao.Name = "edtEdicao"
	Me.edtEdicao.Size = new System.Drawing.Size(104, 20)
	Me.edtEdicao.TabIndex = 6
	Me.edtEdicao.Value = new decimal(new integer() {1,0,0,0})
	' 
	' edtAnoPubli
	' 
	Me.edtAnoPubli.Enabled = false
	Me.edtAnoPubli.Location = new System.Drawing.Point(8, 104)
	Me.edtAnoPubli.Maximum = new decimal(new integer() {9999,0,0,0})
	Me.edtAnoPubli.Minimum = new decimal(new integer() {1,0,0,0})
	Me.edtAnoPubli.Name = "edtAnoPubli"
	Me.edtAnoPubli.Size = new System.Drawing.Size(88, 20)
	Me.edtAnoPubli.TabIndex = 8
	Me.edtAnoPubli.Value = new decimal(new integer() {2004,0,0,0})
	' 
	' labAnoPubli
	' 
	Me.labAnoPubli.Location = new System.Drawing.Point(8, 88)
	Me.labAnoPubli.Name = "labAnoPubli"
	Me.labAnoPubli.Size = new System.Drawing.Size(88, 16)
	Me.labAnoPubli.TabIndex = 7
	Me.labAnoPubli.Text = "Ano Publica��o:"
	' 
	' btnPAssunto
	' 
	Me.btnPAssunto.Enabled = false
	Me.btnPAssunto.Location = new System.Drawing.Point(408, 184)
	Me.btnPAssunto.Name = "btnPAssunto"
	Me.btnPAssunto.Size = new System.Drawing.Size(22, 20)
	Me.btnPAssunto.TabIndex = 23
	Me.btnPAssunto.Text = "..."
	' 
	' edtAssunto
	' 
	Me.edtAssunto.Enabled = false
	Me.edtAssunto.Location = new System.Drawing.Point(184, 184)
	Me.edtAssunto.MaxLength = 30
	Me.edtAssunto.Name = "edtAssunto"
	Me.edtAssunto.Size = new System.Drawing.Size(200, 20)
	Me.edtAssunto.TabIndex = 21
	Me.edtAssunto.Text = ""
	' 
	' edtCodAssunto
	' 
	Me.edtCodAssunto.Enabled = false
	Me.edtCodAssunto.Location = new System.Drawing.Point(100, 184)
	Me.edtCodAssunto.MaxLength = 10
	Me.edtCodAssunto.Name = "edtCodAssunto"
	Me.edtCodAssunto.Size = new System.Drawing.Size(80, 20)
	Me.edtCodAssunto.TabIndex = 20
	Me.edtCodAssunto.Text = ""
	' 
	' labAssunto
	' 
	Me.labAssunto.Location = new System.Drawing.Point(100, 168)
	Me.labAssunto.Name = "labAssunto"
	Me.labAssunto.Size = new System.Drawing.Size(68, 16)
	Me.labAssunto.TabIndex = 19
	Me.labAssunto.Text = "Assunto:"
	' 
	' btnPEditora
	' 
	Me.btnPEditora.Enabled = false
	Me.btnPEditora.Location = new System.Drawing.Point(400, 104)
	Me.btnPEditora.Name = "btnPEditora"
	Me.btnPEditora.Size = new System.Drawing.Size(22, 20)
	Me.btnPEditora.TabIndex = 12
	Me.btnPEditora.Text = "..."
	' 
	' edtEditora
	' 
	Me.edtEditora.Enabled = false
	Me.edtEditora.Location = new System.Drawing.Point(184, 104)
	Me.edtEditora.MaxLength = 30
	Me.edtEditora.Name = "edtEditora"
	Me.edtEditora.Size = new System.Drawing.Size(216, 20)
	Me.edtEditora.TabIndex = 11
	Me.edtEditora.Text = ""
	' 
	' edtCodEditora
	' 
	Me.edtCodEditora.Enabled = false
	Me.edtCodEditora.Location = new System.Drawing.Point(100, 104)
	Me.edtCodEditora.MaxLength = 10
	Me.edtCodEditora.Name = "edtCodEditora"
	Me.edtCodEditora.Size = new System.Drawing.Size(80, 20)
	Me.edtCodEditora.TabIndex = 10
	Me.edtCodEditora.Text = ""
	' 
	' labEditora
	' 
	Me.labEditora.Location = new System.Drawing.Point(100, 88)
	Me.labEditora.Name = "labEditora"
	Me.labEditora.Size = new System.Drawing.Size(52, 16)
	Me.labEditora.TabIndex = 9
	Me.labEditora.Text = "Editora:"
	' 
	' btnAdAssuntos
	' 
	Me.btnAdAssuntos.Enabled = false
	Me.btnAdAssuntos.Location = new System.Drawing.Point(384, 184)
	Me.btnAdAssuntos.Name = "btnAdAssuntos"
	Me.btnAdAssuntos.Size = new System.Drawing.Size(22, 20)
	Me.btnAdAssuntos.TabIndex = 22
	Me.btnAdAssuntos.Text = "+"
	' 
	' edtVolume
	' 
	Me.edtVolume.Enabled = false
	Me.edtVolume.Location = new System.Drawing.Point(8, 144)
	Me.edtVolume.Maximum = new decimal(new integer() {9999,0,0,0})
	Me.edtVolume.Minimum = new decimal(new integer() {1,0,0,0})
	Me.edtVolume.Name = "edtVolume"
	Me.edtVolume.Size = new System.Drawing.Size(88, 20)
	Me.edtVolume.TabIndex = 14
	Me.edtVolume.Value = new decimal(new integer() {1,0,0,0})
	' 
	' labVolume
	' 
	Me.labVolume.Location = new System.Drawing.Point(8, 128)
	Me.labVolume.Name = "labVolume"
	Me.labVolume.Size = new System.Drawing.Size(56, 16)
	Me.labVolume.TabIndex = 13
	Me.labVolume.Text = "Volume:"
	' 
	' edtNPaginas
	' 
	Me.edtNPaginas.Enabled = false
	Me.edtNPaginas.Location = new System.Drawing.Point(8, 184)
	Me.edtNPaginas.Maximum = new decimal(new integer() {9999,0,0,0})
	Me.edtNPaginas.Minimum = new decimal(new integer() {1,0,0,0})
	Me.edtNPaginas.Name = "edtNPaginas"
	Me.edtNPaginas.Size = new System.Drawing.Size(88, 20)
	Me.edtNPaginas.TabIndex = 18
	Me.edtNPaginas.Value = new decimal(new integer() {1,0,0,0})
	' 
	' labNPaginas
	' 
	Me.labNPaginas.Location = new System.Drawing.Point(8, 168)
	Me.labNPaginas.Name = "labNPaginas"
	Me.labNPaginas.Size = new System.Drawing.Size(64, 16)
	Me.labNPaginas.TabIndex = 17
	Me.labNPaginas.Text = "N� P�ginas:"
	' 
	' labIdioma
	' 
	Me.labIdioma.Location = new System.Drawing.Point(100, 128)
	Me.labIdioma.Name = "labIdioma"
	Me.labIdioma.Size = new System.Drawing.Size(60, 16)
	Me.labIdioma.TabIndex = 15
	Me.labIdioma.Text = "Idioma:"
	' 
	' cmbIdioma
	' 
	Me.cmbIdioma.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
	Me.cmbIdioma.Enabled = false
	Me.cmbIdioma.Location = new System.Drawing.Point(100, 144)
	Me.cmbIdioma.Name = "cmbIdioma"
	Me.cmbIdioma.Size = new System.Drawing.Size(328, 21)
	Me.cmbIdioma.TabIndex = 16
	' 
	' lstAssuntos
	' 
	Me.lstAssuntos.Enabled = false
	Me.lstAssuntos.Location = new System.Drawing.Point(100, 208)
	Me.lstAssuntos.Name = "lstAssuntos"
	Me.lstAssuntos.Size = new System.Drawing.Size(332, 43)
	Me.lstAssuntos.TabIndex = 24
	' 
	' labPreco
	' 
	Me.labPreco.Location = new System.Drawing.Point(8, 212)
	Me.labPreco.Name = "labPreco"
	Me.labPreco.Size = new System.Drawing.Size(64, 16)
	Me.labPreco.TabIndex = 25
	Me.labPreco.Text = "Pre�o:"
	' 
	' edtPreco
	' 
	Me.edtPreco.Enabled = false
	Me.edtPreco.Location = new System.Drawing.Point(8, 231)
	Me.edtPreco.Name = "edtPreco"
	Me.edtPreco.Size = new System.Drawing.Size(88, 20)
	Me.edtPreco.TabIndex = 26
	Me.edtPreco.Text = ""
	' 
	' edtQtdEstoque
	' 
	Me.edtQtdEstoque.Enabled = false
	Me.edtQtdEstoque.Location = new System.Drawing.Point(8, 272)
	Me.edtQtdEstoque.Maximum = new decimal(new integer() {9999,0,0,0})
	Me.edtQtdEstoque.Name = "edtQtdEstoque"
	Me.edtQtdEstoque.Size = new System.Drawing.Size(88, 20)
	Me.edtQtdEstoque.TabIndex = 28
	' 
	' labQtdEstoque
	' 
	Me.labQtdEstoque.Location = new System.Drawing.Point(8, 256)
	Me.labQtdEstoque.Name = "labQtdEstoque"
	Me.labQtdEstoque.Size = new System.Drawing.Size(80, 16)
	Me.labQtdEstoque.TabIndex = 27
	Me.labQtdEstoque.Text = "Qtd. Estoque:"
	' 
	' lstAutores
	' 
	Me.lstAutores.Enabled = false
	Me.lstAutores.Location = new System.Drawing.Point(100, 296)
	Me.lstAutores.Name = "lstAutores"
	Me.lstAutores.Size = new System.Drawing.Size(332, 43)
	Me.lstAutores.TabIndex = 34
	' 
	' btnAdAutores
	' 
	Me.btnAdAutores.Enabled = false
	Me.btnAdAutores.Location = new System.Drawing.Point(384, 272)
	Me.btnAdAutores.Name = "btnAdAutores"
	Me.btnAdAutores.Size = new System.Drawing.Size(22, 20)
	Me.btnAdAutores.TabIndex = 32
	Me.btnAdAutores.Text = "+"
	' 
	' btnPAutor
	' 
	Me.btnPAutor.Enabled = false
	Me.btnPAutor.Location = new System.Drawing.Point(408, 272)
	Me.btnPAutor.Name = "btnPAutor"
	Me.btnPAutor.Size = new System.Drawing.Size(22, 20)
	Me.btnPAutor.TabIndex = 33
	Me.btnPAutor.Text = "..."
	' 
	' edtAutor
	' 
	Me.edtAutor.Enabled = false
	Me.edtAutor.Location = new System.Drawing.Point(184, 272)
	Me.edtAutor.MaxLength = 30
	Me.edtAutor.Name = "edtAutor"
	Me.edtAutor.Size = new System.Drawing.Size(200, 20)
	Me.edtAutor.TabIndex = 31
	Me.edtAutor.Text = ""
	' 
	' edtCodAutor
	' 
	Me.edtCodAutor.Enabled = false
	Me.edtCodAutor.Location = new System.Drawing.Point(100, 272)
	Me.edtCodAutor.MaxLength = 10
	Me.edtCodAutor.Name = "edtCodAutor"
	Me.edtCodAutor.Size = new System.Drawing.Size(80, 20)
	Me.edtCodAutor.TabIndex = 30
	Me.edtCodAutor.Text = ""
	' 
	' labAutor
	' 
	Me.labAutor.Location = new System.Drawing.Point(100, 256)
	Me.labAutor.Name = "labAutor"
	Me.labAutor.Size = new System.Drawing.Size(68, 16)
	Me.labAutor.TabIndex = 29
	Me.labAutor.Text = "Autor:"
	' 
	' frmCadLivros
	' 
	Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
	Me.ClientSize = new System.Drawing.Size(520, 381)
	Me.Controls.Add(Me.lstAutores)
	Me.Controls.Add(Me.btnAdAutores)
	Me.Controls.Add(Me.btnPAutor)
	Me.Controls.Add(Me.edtAutor)
	Me.Controls.Add(Me.edtCodAutor)
	Me.Controls.Add(Me.labAutor)
	Me.Controls.Add(Me.edtQtdEstoque)
	Me.Controls.Add(Me.labQtdEstoque)
	Me.Controls.Add(Me.edtPreco)
	Me.Controls.Add(Me.labPreco)
	Me.Controls.Add(Me.lstAssuntos)
	Me.Controls.Add(Me.cmbIdioma)
	Me.Controls.Add(Me.labIdioma)
	Me.Controls.Add(Me.edtNPaginas)
	Me.Controls.Add(Me.labNPaginas)
	Me.Controls.Add(Me.edtVolume)
	Me.Controls.Add(Me.labVolume)
	Me.Controls.Add(Me.btnAdAssuntos)
	Me.Controls.Add(Me.btnPAssunto)
	Me.Controls.Add(Me.edtAssunto)
	Me.Controls.Add(Me.edtCodAssunto)
	Me.Controls.Add(Me.labAssunto)
	Me.Controls.Add(Me.btnPEditora)
	Me.Controls.Add(Me.edtEditora)
	Me.Controls.Add(Me.edtCodEditora)
	Me.Controls.Add(Me.labEditora)
	Me.Controls.Add(Me.edtAnoPubli)
	Me.Controls.Add(Me.labAnoPubli)
	Me.Controls.Add(Me.edtEdicao)
	Me.Controls.Add(Me.labEdicao)
	Me.Name = "frmCadLivros"
	Me.Text = "Cadastro de Livros"
	CType(Me.edtEdicao,System.ComponentModel.ISupportInitialize).EndInit()
	CType(Me.edtAnoPubli,System.ComponentModel.ISupportInitialize).EndInit()
	CType(Me.edtVolume,System.ComponentModel.ISupportInitialize).EndInit()
	CType(Me.edtNPaginas,System.ComponentModel.ISupportInitialize).EndInit()
	CType(Me.edtQtdEstoque,System.ComponentModel.ISupportInitialize).EndInit()
	Me.ResumeLayout(false)
    End Sub

#End Region

    protected overrides function ValidaDados(bTodosDados as boolean) as boolean
        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text, _
            "ISBN n�o informado!")) then
          ValidaDados = false
          exit function
        end if
        if (bTodosDados) then
          if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text, _
            "T�tulo n�o informado!")) then
            ValidaDados = false
            exit function
          end if
          if (RotinasGlobais.Rotinas.ValidaCampo(edtEditora.Text, _
          	"Editora n�o informada!")) then
            ValidaDados = false
            exit function
	  end if
          if (lstAssuntos.Items.Count = 0) then
            MessageBox.Show(Me,"Assunto(s) n�o informado(s)!", _
            frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
            MessageBoxIcon.Error)
            ValidaDados = false
            exit function
	  end if
          if (lstAutores.Items.Count = 0) then
            MessageBox.Show(Me,"Autor(es) n�o informado(s)!", _
            frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
            MessageBoxIcon.Error)
            ValidaDados = false
            exit function
	  end if
        end if
        ValidaDados = true
    end function

    protected overrides sub InformaLimpaDados(bInformar as boolean)
      MyBase.InformaLimpaDados(bInformar)
    
      if bInformar then
        edtEdicao.Text=Campos(2).ToString()
        edtAnoPubli.Text=Campos(3).ToString()
        edtVolume.Text=Campos(4).ToString()
        edtCodEditora.Text=Campos(5).ToString()
        edtEditora.Text=Campos(6).ToString()
        cmbIdioma.SelectedIndex=slIdiomas.IndexOf(Campos(7).ToString())
        edtNPaginas.Text=Campos(9).ToString()
        edtPreco.Text=RotinasGlobais.Rotinas. _
			 VirgulaParaPonto(Campos(10).ToString(),true)
        edtQtdEstoque.Text=Campos(11).ToString()
        RotinasGlobais.Rotinas.AdicionaValoresLista(ConsLista,ConsultasSQL. _
        ConsSQL.LivroAss("S",edtCodigo.Text,""),lstAssuntos,slAssuntos)
        RotinasGlobais.Rotinas.AdicionaValoresLista(ConsLista,ConsultasSQL. _
        ConsSQL.LivroAut("S",edtCodigo.Text,""),lstAutores,slAutores)
      else
        edtEdicao.Value=1
        edtAnoPubli.Text=DateTime.Now.ToString("yyyy")
        edtVolume.Value=1
        edtCodEditora.Clear()
        edtEditora.Clear()
        edtNPaginas.Value=1
        edtPreco.Text="0,00"
        edtQtdEstoque.Value=1
        edtCodAssunto.Clear()
        lstAssuntos.Items.Clear()
        edtCodAutor.Clear()
        lstAutores.Items.Clear()
        slAssuntos.Clear()
        slAutores.Clear()
      end if
    
    end sub
    
    protected overrides sub HabilitaDados(bHabilita as boolean)
    	 MyBase.HabilitaDados(bHabilita)
    
      edtEdicao.Enabled=bHabilita
      edtAnoPubli.Enabled=bHabilita
      edtVolume.Enabled=bHabilita
      edtCodEditora.Enabled=bHabilita
      btnPEditora.Enabled=bHabilita
      cmbIdioma.Enabled=bHabilita
      edtNPaginas.Enabled=bHabilita
      edtPreco.Enabled=bHabilita
      edtQtdEstoque.Enabled=bHabilita
      edtCodAssunto.Enabled=bHabilita
      btnPAssunto.Enabled=bHabilita
      btnAdAssuntos.Enabled=bHabilita
      lstAssuntos.Enabled=bHabilita
      edtCodAutor.Enabled=bHabilita
      btnPAutor.Enabled=bHabilita
      btnAdAutores.Enabled=bHabilita
      lstAutores.Enabled=bHabilita
    end sub

    private sub btnExcluir_Click(sender as object, e as System.EventArgs) _
        Handles btnExcluir.Click

        ExcluirDados(ConsultasSQL.ConsSQL.Livro("D",edtCodigo.Text, _
	"","","","","","","","",""))
    end sub

    private sub btnPesquisar_Click(sender as object, e as System.EventArgs) _
        Handles btnPesquisar.Click

        PesquisarDados(ConsultasSQL.ConsSQL.Livro("S",edtCodigo.Text, _
	"","","","","","","","",""), "Livro n�o encontrado!")
    end sub

    private sub btnSalvar_Click(sender as object, e as System.EventArgs) _
        Handles btnSalvar.Click

        SalvarDados(ConsultasSQL.ConsSQL.Livro("S",edtCodigo.Text, _
	"","","","","","","","",""), _
        ConsultasSQL.ConsSQL.Livro("U",edtCodigo.Text,edtDescricao.Text, _
	edtEdicao.Text,edtAnoPubli.Text,edtVolume.Text,edtCodEditora.Text, _
	slIdiomas(cmbIdioma.SelectedIndex).ToString(),edtNPaginas.Text, _
	RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Text,false), _
	edtQtdEstoque.Text), _
        ConsultasSQL.ConsSQL.Livro("I",edtCodigo.Text,edtDescricao.Text, _
	edtEdicao.Text,edtAnoPubli.Text,edtVolume.Text,edtCodEditora.Text, _
	slIdiomas(cmbIdioma.SelectedIndex).ToString(),edtNPaginas.Text, _
	RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Text,false), _
	edtQtdEstoque.Text), true)
	SalvaLista("A")
	SalvaLista("B")
	btnLimpar_Click(Me,Nothing)
    end sub

    private sub frmCadLivros_Closing(sender as object, _
        e as System.ComponentModel.CancelEventArgs) Handles MyBase.Closing
	
	frmPrincipal.fPrincipal.tlbLivros.Enabled=true
        frmPrincipal.fPrincipal.mnuCadLivros.Enabled=true
    end sub

    private sub btnFechar_Click(sender as object, e as System.EventArgs) _
	Handles btnFechar.Click
    
    	frmCadLivros_Closing(Me,Nothing)
    end sub
    
    private sub frmCadLivros_Load(sender as object, e as System.EventArgs) _
	Handles MyBase.Load
    
      edtAnoPubli.Text=DateTime.Now.ToString("yyyy")
      AdicionaCombo()
      cmbIdioma.SelectedIndex=0
    end sub
    
    private sub AdicionaCombo() 
	dim cont as integer
    	dim linhas as ArrayList = new ArrayList()
    	dim regs as ArrayList = new ArrayList()
    
    	RotinasGlobais.Rotinas.ConsultaDados(regs, _
    		ConsultasSQL.ConsSQL.Idioma("S","",""))
    
    	for cont=0 to regs.Count-1
    	  linhas = CType(regs(cont),ArrayList)
    	  slIdiomas.Add(linhas(0).ToString())
    	  cmbIdioma.Items.Add(linhas(1).ToString())
    	next cont
    end sub

    private sub SalvaLista(sOpcao as string) 
	dim nCont as integer

    	if sOpcao="A" then
    	 RotinasGlobais.Rotinas.ConsultaDados(Arquiva, _
    	 ConsultasSQL.ConsSQL.LivroAss("D",edtCodigo.Text,""))
    
    	 for nCont=0 to slAssuntos.Count-1
    	  RotinasGlobais.Rotinas.ConsultaDados(Arquiva, _
    	  ConsultasSQL.ConsSQL.LivroAss("I", _
    			edtCodigo.Text,slAssuntos(nCont).ToString()))
    	 next nCont
    	else if sOpcao="B" then 
    	  RotinasGlobais.Rotinas.ConsultaDados(Arquiva, _
    	  ConsultasSQL.ConsSQL.LivroAut("D",edtCodigo.Text,""))
    
    	  for nCont=0 to slAutores.Count-1
    	   RotinasGlobais.Rotinas.ConsultaDados(Arquiva, _
    	   ConsultasSQL.ConsSQL.LivroAut("I", _
    			 edtCodigo.Text,slAssuntos(nCont).ToString()))
    	  next nCont
    	end if
    end sub
    
    protected Overrides sub edtCodigo_Leave(sender as object, e as System.EventArgs) _
	Handles edtCodigo.Leave
    
    	if edtCodigo.Text<>"" then
    	  if RotinasGlobais.Rotinas.ValidaISBN(edtCodigo.Text)=false then
              MessageBox.Show(Me,"ISBN inv�lido!", _
              frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
              MessageBoxIcon.Error)
              edtCodigo.Clear()
              edtCodigo.Focus()
    	  end if
    	end if
    end sub
    
    private sub edtCodEditora_Leave(sender as object, e as System.EventArgs) _
	Handles edtCodEditora.Leave
    
      if edtCodEditora.Text<>"" then
         edtEditora.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
         edtCodEditora.Text,ConsultasSQL.ConsSQL.Editora("S", _
         edtCodEditora.Text,""),"Editora n�o encontrada!")
         if edtEditora.Text="" then
            edtCodEditora.Focus()
         end if
      else
    	edtEditora.Clear()
      end if
    end sub
    
    private sub btnPEditora_Click(sender as object, e as System.EventArgs) _
	Handles btnPEditora.Click
    
    	dim pfConEditoras as frmConEditoras = new frmConEditoras()
    	pfConEditoras.ShowDialog()
    	edtCodEditora.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    	edtCodEditora_Leave(Me,Nothing)
    end sub
    
    private sub edtPreco_Leave(sender as object, e as System.EventArgs) _
	Handles edtPreco.Leave
    
    	if RotinasGlobais.Rotinas.ValidaFloat(edtPreco.Text) then
    	  edtPreco.Text=RotinasGlobais.Rotinas.VirgulaParaPonto( _
    		  edtPreco.Text,true)
    	else
    	  edtPreco.Text="0,00"
	end if
    end sub
    
    private sub edtCodAssunto_Leave(sender as object, e as System.EventArgs) _
	Handles edtCodAssunto.Leave
    
      if edtCodAssunto.Text<>"" then
         edtAssunto.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
         edtCodAssunto.Text,ConsultasSQL.ConsSQL.Assunto("S", _
         edtCodAssunto.Text,""),"Assunto n�o encontrado!")
         if edtAssunto.Text="" then
            edtCodAssunto.Focus()
         end if	
      else
    	edtAssunto.Clear()
      end if
    end sub
    
    private sub edtCodAutor_Leave(sender as object, e as System.EventArgs) _
	Handles edtCodAutor.Leave
    
      if edtCodAutor.Text<>"" then
         edtAutor.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
         edtCodAutor.Text,ConsultasSQL.ConsSQL.Autor("S", _
         edtCodAutor.Text,""),"Autor n�o encontrado!")
         if edtAutor.Text="" then
            edtCodAutor.Focus()
         end if
      else
    	edtAutor.Clear()
      end if
    end sub
    
    private sub btnPAssunto_Click(sender as object, e as System.EventArgs) _
	Handles btnPAssunto.Click
    
    	dim pfConAssuntos as frmConAssuntos = new frmConAssuntos()
    	pfConAssuntos.ShowDialog()
    	edtCodAssunto.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    	edtCodAssunto_Leave(Me,Nothing)
    end sub
    
    private sub btnPAutor_Click(sender as object, e as System.EventArgs) _
	Handles btnPAutor.Click
    
    	dim pfConAutores as frmConAutores = new frmConAutores()
    	pfConAutores.ShowDialog()
    	edtCodAutor.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    	edtCodAutor_Leave(Me,Nothing)
    end sub
    
    private sub btnAdAssuntos_Click(sender as object, e as System.EventArgs) _
	Handles btnAdAssuntos.Click
    
    	RotinasGlobais.Rotinas.AdicionaItemLista( _
    	lstAssuntos,slAssuntos,edtCodAssunto,edtAssunto)
    end sub
    
    private sub lstAssuntos_DoubleClick(sender as object, e as System.EventArgs) _
	Handles lstAssuntos.DoubleClick
    
    	RotinasGlobais.Rotinas.RemoveItemLista(lstAssuntos,slAssuntos)
    end sub
    
    private sub btnAdAutores_Click(sender as object, e as System.EventArgs) _
	Handles btnAdAutores.Click
    
    	RotinasGlobais.Rotinas.AdicionaItemLista( _
    	lstAutores,slAutores,edtCodAutor,edtAutor)
    end sub
    
    private sub lstAutores_DoubleClick(sender as object, e as System.EventArgs) _
	Handles lstAutores.DoubleClick
    
            RotinasGlobais.Rotinas.RemoveItemLista(lstAutores,slAutores)
    end sub

End Class

End NameSpace