Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmConVendas
    Inherits Livrus.frmConsultas

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'Me call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call
	ConsTotal = new ArrayList()
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

    public shared withevents fConVendas as frmConVendas
    private ConsTotal as ArrayList
    private ConsCampo as ArrayList

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    private WithEvents btnPLivro As System.Windows.Forms.Button
    private edtLivro As System.Windows.Forms.TextBox 
    private WithEvents edtISBN As System.Windows.Forms.TextBox 
    private labISBN As System.Windows.Forms.Label 
    private labDtHrVenda As System.Windows.Forms.Label 
    private edtDtVenda As System.Windows.Forms.DateTimePicker 
    private edtHrVenda As System.Windows.Forms.DateTimePicker 
    private WithEvents btnPCliente As System.Windows.Forms.Button 
    private edtCliente As System.Windows.Forms.TextBox 
    private labCLiente As System.Windows.Forms.Label 
    private labLivro As System.Windows.Forms.Label 
    private edtPrecoTotal As System.Windows.Forms.TextBox 
    private labPrecoTotal As System.Windows.Forms.Label 

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
	Me.btnPLivro = new System.Windows.Forms.Button()
	Me.edtLivro = new System.Windows.Forms.TextBox()
	Me.edtISBN = new System.Windows.Forms.TextBox()
	Me.labISBN = new System.Windows.Forms.Label()
	Me.labDtHrVenda = new System.Windows.Forms.Label()
	Me.edtDtVenda = new System.Windows.Forms.DateTimePicker()
	Me.edtHrVenda = new System.Windows.Forms.DateTimePicker()
	Me.btnPCliente = new System.Windows.Forms.Button()
	Me.edtCliente = new System.Windows.Forms.TextBox()
	Me.labCLiente = new System.Windows.Forms.Label()
	Me.labLivro = new System.Windows.Forms.Label()
	Me.edtPrecoTotal = new System.Windows.Forms.TextBox()
	Me.labPrecoTotal = new System.Windows.Forms.Label()
	Me.panel1.SuspendLayout()
        CType(Me.gridConsulta,System.ComponentModel.ISupportInitialize).BeginInit()
	Me.panel2.SuspendLayout()
        CType(Me.dsConsulta,System.ComponentModel.ISupportInitialize).BeginInit()
	Me.SuspendLayout()
	'
	' panel1
	' 
	Me.panel1.Anchor = CType(((System.Windows.Forms.AnchorStyles.Top  _
				or System.Windows.Forms.AnchorStyles.Left) _ 
				or System.Windows.Forms.AnchorStyles.Right), _
				System.Windows.Forms.AnchorStyles)
	Me.panel1.Controls.Add(Me.labLivro)
	Me.panel1.Controls.Add(Me.btnPCliente)
	Me.panel1.Controls.Add(Me.edtCliente)
	Me.panel1.Controls.Add(Me.edtHrVenda)
	Me.panel1.Controls.Add(Me.labDtHrVenda)
	Me.panel1.Controls.Add(Me.edtDtVenda)
	Me.panel1.Controls.Add(Me.btnPLivro)
	Me.panel1.Controls.Add(Me.edtLivro)
	Me.panel1.Controls.Add(Me.edtISBN)
	Me.panel1.Controls.Add(Me.labISBN)
	Me.panel1.Controls.Add(Me.labCLiente)
	Me.panel1.Dock = System.Windows.Forms.DockStyle.None
	Me.panel1.Name = "panel1"
	Me.panel1.Size = new System.Drawing.Size(1128, 136)
	'
	' btnPesquisar
	'
	Me.btnPesquisar.Location = new System.Drawing.Point(232, 24)
	Me.btnPesquisar.Name = "btnPesquisar"
	Me.btnPesquisar.TabIndex = 3
	'
	' edtDescricao
	'
	Me.edtDescricao.Location = new System.Drawing.Point(8, 64)
	Me.edtDescricao.Name = "edtDescricao"
	Me.edtDescricao.Size = new System.Drawing.Size(128, 20)
	Me.edtDescricao.TabIndex = 5
	Me.edtDescricao.MaxLength = 14
	' 
	' labDescricao
	' 
	Me.labDescricao.Location = new System.Drawing.Point(8, 48)
	Me.labDescricao.Name = "labDescricao"
	Me.labDescricao.TabIndex = 4
	Me.labDescricao.Text = "CPF:"
	'
	' gridConsulta
	'
	Me.gridConsulta.Location = new System.Drawing.Point(0, 136)
	Me.gridConsulta.Name = "gridConsulta"
	Me.gridConsulta.Size = new System.Drawing.Size(456, 136)
	'
	' panel2
	'
	Me.panel2.Controls.Add(Me.edtPrecoTotal)
	Me.panel2.Controls.Add(Me.labPrecoTotal)
	Me.panel2.Location = new System.Drawing.Point(0, 272)
	Me.panel2.Name = "panel2"
	Me.panel2.Size = new System.Drawing.Size(464, 72)
	'
	' btnLimpar
	'
	Me.btnLimpar.Location = new System.Drawing.Point(296, 40)
	Me.btnLimpar.Name = "btnLimpar"
	Me.btnLimpar.TabIndex = 3
	'
	' btnFechar
	'
	Me.btnFechar.Location = new System.Drawing.Point(376, 40)
	Me.btnFechar.Name = "btnFechar"
	Me.btnFechar.TabIndex = 4
	'
	' labRegistros
	'
	Me.labRegistros.Location = new System.Drawing.Point(11, 40)
	Me.labRegistros.Name = "labRegistros"
	Me.labRegistros.TabIndex = 2
	'
	' dsConsulta
	'
	Me.dsConsulta.DataSetName = "Consulta"
	Me.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR")
	'
	' btnPLivro
	'
	Me.btnPLivro.Location = new System.Drawing.Point(424, 104)
	Me.btnPLivro.Name = "btnPLivro"
	Me.btnPLivro.Size = new System.Drawing.Size(22, 20)
	Me.btnPLivro.TabIndex = 13
	Me.btnPLivro.Text = "..."
	'
	' edtLivro
	'
	Me.edtLivro.Enabled = false
	Me.edtLivro.Location = new System.Drawing.Point(144, 104)
	Me.edtLivro.MaxLength = 30
	Me.edtLivro.Name = "edtLivro"
	Me.edtLivro.Size = new System.Drawing.Size(280, 20)
	Me.edtLivro.TabIndex = 12
	Me.edtLivro.Text = ""
	'
	' edtISBN
	'
	Me.edtISBN.Location = new System.Drawing.Point(8, 104)
	Me.edtISBN.MaxLength = 13
	Me.edtISBN.Name = "edtISBN"
	Me.edtISBN.Size = new System.Drawing.Size(128, 20)
	Me.edtISBN.TabIndex = 10
	Me.edtISBN.Text = ""
	' 
	' labISBN
	' 
	Me.labISBN.Location = new System.Drawing.Point(8, 88)
	Me.labISBN.Name = "labISBN"
	Me.labISBN.Size = new System.Drawing.Size(52, 16)
	Me.labISBN.TabIndex = 9
	Me.labISBN.Text = "ISBN:"
	' 
	' labDtHrVenda
	' 
	Me.labDtHrVenda.Location = new System.Drawing.Point(8, 8)
	Me.labDtHrVenda.Name = "labDtHrVenda"
	Me.labDtHrVenda.Size = new System.Drawing.Size(96, 16)
	Me.labDtHrVenda.TabIndex = 0
	Me.labDtHrVenda.Text = "Data/Hora Venda:"
	'
	' edtDtVenda
	' 
	Me.edtDtVenda.Checked = false
	Me.edtDtVenda.Format = System.Windows.Forms.DateTimePickerFormat.Short
	Me.edtDtVenda.Location = new System.Drawing.Point(8, 24)
	Me.edtDtVenda.Name = "edtDtVenda"
	Me.edtDtVenda.ShowCheckBox = true
	Me.edtDtVenda.Size = new System.Drawing.Size(104, 20)
	Me.edtDtVenda.TabIndex = 1
	' 
	' edtHrVenda
	' 
	Me.edtHrVenda.Checked = false
	Me.edtHrVenda.Format = System.Windows.Forms.DateTimePickerFormat.Time
	Me.edtHrVenda.Location = new System.Drawing.Point(120, 24)
	Me.edtHrVenda.Name = "edtHrVenda"
	Me.edtHrVenda.ShowCheckBox = true
	Me.edtHrVenda.ShowUpDown = true
	Me.edtHrVenda.Size = new System.Drawing.Size(104, 20)
	Me.edtHrVenda.TabIndex = 2
	' 
	' btnPCliente
	'
	Me.btnPCliente.Location = new System.Drawing.Point(424, 62)
	Me.btnPCliente.Name = "btnPCliente"
	Me.btnPCliente.Size = new System.Drawing.Size(22, 20)
	Me.btnPCliente.TabIndex = 8
	Me.btnPCliente.Text = "..."
	' 
	' edtCliente
	' 
	Me.edtCliente.Enabled = false
	Me.edtCliente.Location = new System.Drawing.Point(144, 62)
	Me.edtCliente.MaxLength = 30
	Me.edtCliente.Name = "edtCliente"
	Me.edtCliente.Size = new System.Drawing.Size(280, 20)
	Me.edtCliente.TabIndex = 7
	Me.edtCliente.Text = ""
	' 
	' labCLiente
	' 
	Me.labCLiente.Location = new System.Drawing.Point(144, 48)
	Me.labCLiente.Name = "labCLiente"
	Me.labCLiente.Size = new System.Drawing.Size(52, 16)
	Me.labCLiente.TabIndex = 6
	Me.labCLiente.Text = "Cliente:"
	' 
	' labLivro
	' 
	Me.labLivro.Location = new System.Drawing.Point(144, 88)
	Me.labLivro.Name = "labLivro"
	Me.labLivro.Size = new System.Drawing.Size(52, 16)
	Me.labLivro.TabIndex = 11
	Me.labLivro.Text = "Livro:"
	'
	' edtPrecoTotal
	' 
	Me.edtPrecoTotal.Anchor = CType((System.Windows.Forms.AnchorStyles.Top _
				or System.Windows.Forms.AnchorStyles.Right), _
				System.Windows.Forms.AnchorStyles)
	Me.edtPrecoTotal.Enabled = false
	Me.edtPrecoTotal.Location = new System.Drawing.Point(320, 8)
	Me.edtPrecoTotal.MaxLength = 10
	Me.edtPrecoTotal.Name = "edtPrecoTotal"
	Me.edtPrecoTotal.Size = new System.Drawing.Size(128, 20)
	Me.edtPrecoTotal.TabIndex = 1
	Me.edtPrecoTotal.Text = ""
	' 
	' labPrecoTotal
	' 
	Me.labPrecoTotal.Anchor = CType((System.Windows.Forms.AnchorStyles.Top  _
				or System.Windows.Forms.AnchorStyles.Right), _
				System.Windows.Forms.AnchorStyles)
	Me.labPrecoTotal.Location = new System.Drawing.Point(248, 8)
	Me.labPrecoTotal.Name = "labPrecoTotal"
	Me.labPrecoTotal.Size = new System.Drawing.Size(64, 16)
	Me.labPrecoTotal.TabIndex = 0
	Me.labPrecoTotal.Text = "Preço total:"
	' 
	' frmConVendas
	' 
	Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
	Me.ClientSize = new System.Drawing.Size(456, 341)
	Me.Name = "frmConVendas"
	Me.Text = "Consulta de Vendas Realizadas"
	Me.panel1.ResumeLayout(false)
        CType(Me.gridConsulta,System.ComponentModel.ISupportInitialize).EndInit()        
	Me.panel2.ResumeLayout(false)
	CType(Me.dsConsulta,System.ComponentModel.ISupportInitialize).EndInit()
	Me.ResumeLayout(false)
    End Sub

#End Region

  private sub btnLimpar_Click(sender as object, e as System.EventArgs) _
	Handles btnLimpar.Click

  	edtDtVenda.Value=DateTime.Now
  	edtHrVenda.Value=DateTime.Now
  	edtDtVenda.Checked=false
  	edtHrVenda.Checked=false
  	edtCliente.Clear()
  	edtISBN.Clear()
  	edtLivro.Clear()
  	edtPrecoTotal.Text="R$ 0,00"
  	edtDtVenda.Focus()
  
  	LimparDados(ConsVenda("L"))
  
  end sub
  
  private function ConsVenda(sOpcao as string) as string
    dim sDataVenda, sHoraVenda, sDtHrVenda as string
  
    if edtDtVenda.Checked then
  	sDataVenda=edtDtVenda.Value.ToString("dd/MM/yyyy")
    else
  	 sDataVenda=""
    end if	
    if edtHrVenda.Checked then
  	sHoraVenda=edtHrVenda.Value.ToString("hh:mm:ss")
    else
  	 sHoraVenda=""
    end if
    sDtHrVenda=sDataVenda.Trim()+" "+sHoraVenda.Trim()
    if sOpcao="L" then
     return ConsultasSQL.ConsSQL.Venda("S","ZERO","","","","")
    else
     return ConsultasSQL.ConsSQL.Venda(sOpcao,edtISBN.Text, _
     edtDescricao.Text, sDtHrVenda.Trim(),"","")
    end if	
  end function
  
  private sub btnPesquisar_Click(sender as object, e as System.EventArgs) _
	Handles btnPesquisar.Click

    dim linhas as ArrayList = new ArrayList()
    if PesquisarDados(ConsVenda("S"),"Venda não encontrada!") then 
  	 RotinasGlobais.Rotinas.ConsultaDados(ConsTotal,ConsVenda("P"))
  	 if ConsTotal.Count > 0 then
  		linhas = CType(ConsTotal(0),ArrayList)
  		edtPrecoTotal.Text="R$ "+linhas(0).ToString()
  	 end if
    end if
  
  end sub
  
  private sub frmConVendas_Load(sender as object, e as System.EventArgs) _
	Handles MyBase.Load

    btnLimpar_Click(Me,Nothing)
  end sub
  
  private sub edtDescricao_Leave(sender as object, e as System.EventArgs) _
	Handles edtDescricao.Leave

    if edtDescricao.Text<>"" then
      if RotinasGlobais.Rotinas.ValidaCPF(edtDescricao.Text) then
    		  edtCliente.Text = _
    	  RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
    	  ConsultasSQL.ConsSQL.Cliente("S",edtDescricao.Text, _
    	  "","","","","","","","",""),"Cliente não encontrado!")
    	  if edtCliente.Text="" then
    		edtDescricao.Clear()
    		edtDescricao.Focus()
    	  end if
      else
    	  MessageBox.Show(Me,"CPF inválido!", _
    	  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
    	  MessageBoxIcon.Error)
    	  edtDescricao.Clear()
    	  edtCliente.Clear()
      end if
    end if
  end sub
  
  private sub edtISBN_Leave(sender as object, e as System.EventArgs) _
	Handles edtISBN.Leave

    if edtISBN.Text<>"" then
      if RotinasGlobais.Rotinas.ValidaISBN(edtISBN.Text) then
    	  edtLivro.Text= _
    	  RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
    	  ConsultasSQL.ConsSQL.Livro("Q",edtISBN.Text, _
    	  "","","","","","","","",""),"Livro não encontrado!")
    	  if edtLivro.Text<>"" then
            if integer.Parse(ConsCampo(3).ToString()) > 0 then
              RotinasGlobais.Rotinas.sPreco=ConsCampo(2).ToString()
            else
              MessageBox.Show(Me,"Livro não existe no estoque!", _
              frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
              MessageBoxIcon.Error)
            end if  
    	  else 
            edtISBN.Clear()
            edtISBN.Focus()
    	  end if
      else 
        MessageBox.Show(Me,"ISBN inválido!", _
        frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
        MessageBoxIcon.Error)
        edtISBN.Clear()
        edtLivro.Clear()
      end if
    end if
  end sub
  
  private sub btnPCliente_Click(sender as object, e as System.EventArgs) _
	Handles btnPCliente.Click

    dim pfConClientes as frmConClientes = new frmConClientes()
    pfConClientes.ShowDialog()
    edtDescricao.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    edtDescricao_Leave(Me,Nothing)
  end sub
  
  private sub btnPLivro_Click(sender as object, e as System.EventArgs) _
	Handles btnPLivro.Click

    dim pfConLivros as frmConLivros = new frmConLivros()
    pfConLivros.ShowDialog()
    edtISBN.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    edtISBN_Leave(Me,Nothing)
  end sub
  
  private sub frmConVendas_Closing(sender as object, e as System.ComponentModel.CancelEventArgs) _
	Handles MyBase.Closing

     frmPrincipal.fPrincipal.mnuVendasRealizadas.Enabled=true
  end sub

End Class

End Namespace
