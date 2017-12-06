Imports System
Imports System.Drawing
Imports System.Collections
Imports System.ComponentModel
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class frmVenderLivros
    Inherits System.Windows.Forms.Form

#Region " Windows Form Designer generated code "

    Public Sub New()
        MyBase.New()

        'This call is required by the Windows Form Designer.
        InitializeComponent()

        'Add any initialization after the InitializeComponent() call
	slISBNs = new ArrayList()
	slPrecos = new ArrayList()
	slQtdEstoque = new ArrayList()
	ConsCampo = new ArrayList()
	Arquiva = new System.Data.OleDb.OleDbCommand()
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

    public shared withevents fVenderLivros as frmVenderLivros
    private nPrecoTotal as single
    private slISBNs, slPrecos, slQtdEstoque, ConsCampo as ArrayList
    private Arquiva As System.Data.OleDb.OleDbCommand

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer
    private labDtHrVenda As System.Windows.Forms.Label
    private edtDtHrVenda As System.Windows.Forms.TextBox 
    private labLivrosVender As System.Windows.Forms.Label 
    private WithEvents lstLivros As System.Windows.Forms.ListBox 
    private labLivro As System.Windows.Forms.Label 
    private WithEvents btnPCliente As System.Windows.Forms.Button 
    private edtCliente As System.Windows.Forms.TextBox 
    private WithEvents btnPLivro As System.Windows.Forms.Button 
    private edtLivro As System.Windows.Forms.TextBox 
    private WithEvents edtISBN As System.Windows.Forms.TextBox 
    private labISBN As System.Windows.Forms.Label 
    private labCLiente As System.Windows.Forms.Label 
    private WithEvents edtCPF As System.Windows.Forms.TextBox 
    private labCPF As System.Windows.Forms.Label 
    private WithEvents btnAdLivros As System.Windows.Forms.Button
    private edtPrecoTotal As System.Windows.Forms.TextBox 
    private labPrecoTotal As System.Windows.Forms.Label 
    private WithEvents btnVender As System.Windows.Forms.Button 
    private WithEvents btnLimpar As System.Windows.Forms.Button 
    private WithEvents btnFechar As System.Windows.Forms.Button 

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> Private Sub InitializeComponent()
        components = New System.ComponentModel.Container()
	Me.labDtHrVenda = new System.Windows.Forms.Label()
	Me.edtDtHrVenda = new System.Windows.Forms.TextBox()
	Me.labLivrosVender = new System.Windows.Forms.Label()
	Me.lstLivros = new System.Windows.Forms.ListBox()
	Me.labLivro = new System.Windows.Forms.Label()
	Me.btnPCliente = new System.Windows.Forms.Button()
	Me.edtCliente = new System.Windows.Forms.TextBox()
	Me.btnPLivro = new System.Windows.Forms.Button()
	Me.edtLivro = new System.Windows.Forms.TextBox()
	Me.edtISBN = new System.Windows.Forms.TextBox()
	Me.labISBN = new System.Windows.Forms.Label()
	Me.labCLiente = new System.Windows.Forms.Label()
	Me.edtCPF = new System.Windows.Forms.TextBox()
	Me.labCPF = new System.Windows.Forms.Label()
	Me.btnAdLivros = new System.Windows.Forms.Button()
	Me.edtPrecoTotal = new System.Windows.Forms.TextBox()
	Me.labPrecoTotal = new System.Windows.Forms.Label()
	Me.btnVender = new System.Windows.Forms.Button()
	Me.btnLimpar = new System.Windows.Forms.Button()
	Me.btnFechar = new System.Windows.Forms.Button()
	Me.SuspendLayout()
	' 
	' labDtHrVenda
	' 
	Me.labDtHrVenda.Location = new System.Drawing.Point(8, 8)
	Me.labDtHrVenda.Name = "labDtHrVenda"
	Me.labDtHrVenda.Size = new System.Drawing.Size(100, 16)
	Me.labDtHrVenda.TabIndex = 0
	Me.labDtHrVenda.Text = "Data/Hora Venda:"
	' 
	' edtDtHrVenda
	' 
	Me.edtDtHrVenda.Enabled = false
	Me.edtDtHrVenda.Location = new System.Drawing.Point(8, 24)
	Me.edtDtHrVenda.Name = "edtDtHrVenda"
	Me.edtDtHrVenda.Size = new System.Drawing.Size(120, 20)
	Me.edtDtHrVenda.TabIndex = 1
	Me.edtDtHrVenda.Text = ""
	' 
	' labLivrosVender
	' 
	Me.labLivrosVender.Location = new System.Drawing.Point(8, 128)
	Me.labLivrosVender.Name = "labLivrosVender"
	Me.labLivrosVender.Size = new System.Drawing.Size(112, 16)
	Me.labLivrosVender.TabIndex = 13
	Me.labLivrosVender.Text = "Livros para vender:"
	' 
	' lstLivros
	' 
	Me.lstLivros.Location = new System.Drawing.Point(8, 144)
	Me.lstLivros.Name = "lstLivros"
	Me.lstLivros.Size = new System.Drawing.Size(464, 108)
	Me.lstLivros.TabIndex = 14
	' 
	' labLivro
	' 
	Me.labLivro.Location = new System.Drawing.Point(144, 88)
	Me.labLivro.Name = "labLivro"
	Me.labLivro.Size = new System.Drawing.Size(52, 16)
	Me.labLivro.TabIndex = 9
	Me.labLivro.Text = "Livro:"
	' 
	' btnPCliente
	' 
	Me.btnPCliente.Location = new System.Drawing.Point(448, 64)
	Me.btnPCliente.Name = "btnPCliente"
	Me.btnPCliente.Size = new System.Drawing.Size(22, 20)
	Me.btnPCliente.TabIndex = 6
	Me.btnPCliente.Text = "..."
	' 
	' edtCliente
	' 
	Me.edtCliente.Enabled = false
	Me.edtCliente.Location = new System.Drawing.Point(144, 64)
	Me.edtCliente.MaxLength = 30
	Me.edtCliente.Name = "edtCliente"
	Me.edtCliente.Size = new System.Drawing.Size(304, 20)
	Me.edtCliente.TabIndex = 5
	Me.edtCliente.Text = ""
	' 
	' btnPLivro
	' 
	Me.btnPLivro.Location = new System.Drawing.Point(448, 104)
	Me.btnPLivro.Name = "btnPLivro"
	Me.btnPLivro.Size = new System.Drawing.Size(22, 20)
	Me.btnPLivro.TabIndex = 12
	Me.btnPLivro.Text = "..."
	' 
	' edtLivro
	' 
	Me.edtLivro.Enabled = false
	Me.edtLivro.Location = new System.Drawing.Point(144, 104)
	Me.edtLivro.MaxLength = 30
	Me.edtLivro.Name = "edtLivro"
	Me.edtLivro.Size = new System.Drawing.Size(280, 20)
	Me.edtLivro.TabIndex = 10
	Me.edtLivro.Text = ""
	' 
	' edtISBN
	' 
	Me.edtISBN.Location = new System.Drawing.Point(8, 104)
	Me.edtISBN.MaxLength = 13
	Me.edtISBN.Name = "edtISBN"
	Me.edtISBN.Size = new System.Drawing.Size(128, 20)
	Me.edtISBN.TabIndex = 8
	Me.edtISBN.Text = ""
	' 
	' labISBN
	' 
	Me.labISBN.Location = new System.Drawing.Point(8, 88)
	Me.labISBN.Name = "labISBN"
	Me.labISBN.Size = new System.Drawing.Size(52, 16)
	Me.labISBN.TabIndex = 7
	Me.labISBN.Text = "ISBN:"
	' 
	' labCLiente
	' 
	Me.labCLiente.Location = new System.Drawing.Point(144, 48)
	Me.labCLiente.Name = "labCLiente"
	Me.labCLiente.Size = new System.Drawing.Size(52, 16)
	Me.labCLiente.TabIndex = 4
	Me.labCLiente.Text = "Cliente:"
	' 
	' edtCPF
	' 
	Me.edtCPF.Location = new System.Drawing.Point(8, 64)
	Me.edtCPF.MaxLength = 14
	Me.edtCPF.Name = "edtCPF"
	Me.edtCPF.Size = new System.Drawing.Size(128, 20)
	Me.edtCPF.TabIndex = 3
	Me.edtCPF.Text = ""
	'
	' labCPF
	'
	Me.labCPF.Location = new System.Drawing.Point(8, 48)
	Me.labCPF.Name = "labCPF"
	Me.labCPF.Size = new System.Drawing.Size(52, 16)
	Me.labCPF.TabIndex = 2
	Me.labCPF.Text = "CPF:"
	' 
	' btnAdLivros
	' 
	Me.btnAdLivros.Location = new System.Drawing.Point(424, 104)
	Me.btnAdLivros.Name = "btnAdLivros"
	Me.btnAdLivros.Size = new System.Drawing.Size(22, 20)
	Me.btnAdLivros.TabIndex = 11
	Me.btnAdLivros.Text = "+"
	' 
	' edtPrecoTotal
	' 
	Me.edtPrecoTotal.Enabled = false
	Me.edtPrecoTotal.Location = new System.Drawing.Point(344, 256)
	Me.edtPrecoTotal.MaxLength = 10
	Me.edtPrecoTotal.Name = "edtPrecoTotal"
	Me.edtPrecoTotal.Size = new System.Drawing.Size(128, 20)
	Me.edtPrecoTotal.TabIndex = 16
	Me.edtPrecoTotal.Text = ""
	' 
	' labPrecoTotal
	' 
	Me.labPrecoTotal.Location = new System.Drawing.Point(272, 256)
	Me.labPrecoTotal.Name = "labPrecoTotal"
	Me.labPrecoTotal.Size = new System.Drawing.Size(64, 16)
	Me.labPrecoTotal.TabIndex = 15
	Me.labPrecoTotal.Text = "Preço total:"
	' 
	' btnVender
	' 
	Me.btnVender.Location = new System.Drawing.Point(240, 288)
	Me.btnVender.Name = "btnVender"
	Me.btnVender.TabIndex = 17
	Me.btnVender.Text = "&Vender"
	' 
	' btnLimpar
	' 
	Me.btnLimpar.Location = new System.Drawing.Point(320, 288)
	Me.btnLimpar.Name = "btnLimpar"
	Me.btnLimpar.TabIndex = 18
	Me.btnLimpar.Text = "&Limpar"
	' 
	' btnFechar
	' 
	Me.btnFechar.DialogResult = System.Windows.Forms.DialogResult.Cancel
	Me.btnFechar.Location = new System.Drawing.Point(400, 288)
	Me.btnFechar.Name = "btnFechar"
	Me.btnFechar.TabIndex = 19
	Me.btnFechar.Text = "&Fechar"
	' 
	' frmVenderLivros
	' 
	Me.AutoScaleBaseSize = new System.Drawing.Size(5, 13)
	Me.ClientSize = new System.Drawing.Size(480, 317)
	Me.Controls.Add(Me.btnVender)
	Me.Controls.Add(Me.btnLimpar)
	Me.Controls.Add(Me.btnFechar)
	Me.Controls.Add(Me.edtPrecoTotal)
	Me.Controls.Add(Me.edtCPF)
	Me.Controls.Add(Me.edtCliente)
	Me.Controls.Add(Me.edtLivro)
	Me.Controls.Add(Me.edtISBN)
	Me.Controls.Add(Me.edtDtHrVenda)
	Me.Controls.Add(Me.labPrecoTotal)
	Me.Controls.Add(Me.btnAdLivros)
	Me.Controls.Add(Me.labCPF)
	Me.Controls.Add(Me.labLivro)
	Me.Controls.Add(Me.btnPCliente)
	Me.Controls.Add(Me.btnPLivro)
	Me.Controls.Add(Me.labISBN)
	Me.Controls.Add(Me.labCLiente)
	Me.Controls.Add(Me.lstLivros)
	Me.Controls.Add(Me.labLivrosVender)
	Me.Controls.Add(Me.labDtHrVenda)
	Me.Name = "frmVenderLivros"
	Me.Text = "Vender Livros"
	Me.ResumeLayout(false)
    End Sub

#End Region

  private sub LimpaDados() 
  	edtDtHrVenda.Text=DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss")
  	edtCPF.Clear()
  	edtCliente.Clear()
  	edtISBN.Clear()
  	edtLivro.Clear()
  	lstLivros.Items.Clear()
  	slPrecos.Clear()
  	nPrecoTotal=0
  	edtPrecoTotal.Text="R$ 0,00"
  	edtCPF.Focus()
  end sub
  private Function ValidaDados() as boolean
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCPF.Text, _
      		"CPF não informado!"))
        return false
      end if
      if (lstLivros.Items.Count = 0) then
        MessageBox.Show(Me,"Livro(s) para vender não informado(s)!", _
        frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
        MessageBoxIcon.Error)
        return false
      end if
      return true
  end function
  
  private Function SalvaLista() as boolean
    dim nCont, nQtdEstoque as integer
    Try  
      for nCont=0 to lstLivros.Items.Count-1 
       RotinasGlobais.Rotinas.ConsultaDados(Arquiva, _
       ConsultasSQL.ConsSQL.Venda("I",slISBNs(nCont).ToString(), _
       edtCPF.Text,RotinasGlobais.Rotinas.FormataDataStr( _
       edtDtHrVenda.Text,"MM/dd/yyyy hh:mm:ss"),RotinasGlobais.Rotinas. _
       VirgulaParaPonto(CStr(nPrecoTotal),false),""))
      
       nQtdEstoque=CInt(slQtdEstoque(nCont).ToString())
       nQtdEstoque=nQtdEstoque-1
       RotinasGlobais.Rotinas.ConsultaDados(Arquiva, _
       ConsultasSQL.ConsSQL.Venda("U",slISBNs(nCont).ToString(), _
       "","","", CStr(nQtdEstoque)))
      next nCont
      return true
    Catch e As Exception
        MessageBox.Show(Me,e.Message, frmPrincipal.fPrincipal.Text, _
	MessageBoxButtons.OK, MessageBoxIcon.Error)    
	return false
    End Try
  end Function
  
  private sub edtCPF_Leave(sender as object, e as System.EventArgs) _
	Handles edtCPF.Leave

    if edtCPF.Text<>"" then
      if (RotinasGlobais.Rotinas.ValidaCPF(edtCPF.Text)) then
            edtCliente.Text = _
            RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
            ConsultasSQL.ConsSQL.Cliente("S",edtCPF.Text, _
            "","","","","","","","",""),"Cliente não encontrado!")
            if (edtCliente.Text="") then
              edtCPF.Clear()
              edtCPF.Focus()
            end if
      else 
            MessageBox.Show(Me,"CPF inválido!", _
            frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK, _
            MessageBoxIcon.Error)
            edtCPF.Clear()
            edtCliente.Clear()
      end if
    end if
  end sub
  
  private sub btnPCliente_Click(sender as object, e as System.EventArgs) _
    Handles btnPCliente.Click

    dim pfConClientes as frmConClientes = new frmConClientes()
    pfConClientes.ShowDialog()
    edtCPF.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    edtCPF_Leave(Me,Nothing)
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
  
  private sub btnPLivro_Click(sender as object, e as System.EventArgs) _
    Handles btnPLivro.Click

    dim pfConLivros as frmConLivros = new frmConLivros()
    pfConLivros.ShowDialog()
    edtISBN.Text=RotinasGlobais.Rotinas.sCodigoSelecionado
    edtISBN_Leave(Me,Nothing)
  end sub
  
  private sub btnAdLivros_Click(sender as object, e as System.EventArgs) _
    Handles btnAdLivros.Click

     dim sLivros as String
    
     if edtISBN.Text<>"" then
     sLivros=edtISBN.Text+" - "+edtLivro.Text+" - R$ "+ _
    	 RotinasGlobais.Rotinas.sPreco
     if lstLivros.Items.IndexOf(sLivros)=-1 then
       slISBNs.Add(edtISBN.Text)
       slPrecos.Add(RotinasGlobais.Rotinas.sPreco)
       slQtdEstoque.Add(RotinasGlobais.Rotinas.sQtdEstoque)
       lstLivros.Items.Add(sLivros)
       nPrecoTotal=nPrecoTotal+Single.Parse(RotinasGlobais.Rotinas.sPreco)
     end if
     edtISBN.Clear()
     edtLivro.Clear()
     edtPrecoTotal.Text="R$ "+ RotinasGlobais.Rotinas.VirgulaParaPonto( _
    			   CStr(nPrecoTotal),true)
    end if 
  end sub
  
  private sub lstLivros_DoubleClick(sender as object, e as System.EventArgs) _
    Handles lstLivros.DoubleClick

    dim nPreco as single
    
    if (lstLivros.Items.Count > 0) then
      nPreco=Single.Parse(slPrecos(lstLivros.SelectedIndex).ToString())
      nPrecoTotal=nPrecoTotal-nPreco
      edtPrecoTotal.Text="R$ "+CStr(nPrecoTotal)
    
      slISBNs.RemoveAt(lstLivros.SelectedIndex)
      slPrecos.RemoveAt(lstLivros.SelectedIndex)
      slQtdEstoque.RemoveAt(lstLivros.SelectedIndex)
      lstLivros.Items.RemoveAt(lstLivros.SelectedIndex)
    end if
  end sub
  
  private sub btnVender_Click(sender as object, e as System.EventArgs) _
    Handles btnVender.Click

    if ValidaDados() then
       if SalvaLista() then
          MessageBox.Show(Me,"Venda realizada com sucesso!", _
          frmPrincipal.fPrincipal.Text, _
          MessageBoxButtons.OK, MessageBoxIcon.Information)    
	  LimpaDados()
       end if
    end if
  end sub
  
  private sub btnLimpar_Click(sender as object, e as System.EventArgs) _
    Handles btnLimpar.Click

    LimpaDados()
  end sub
  
  private sub btnFechar_Click(sender as object, e as System.EventArgs) _
    Handles btnFechar.Click

    frmVenderLivros_Closing(Me,Nothing)
    Close()
  end sub
  
  private sub frmVenderLivros_Closing(sender as object, e as System.ComponentModel.CancelEventArgs) _
    Handles MyBase.Closing

    frmPrincipal.fPrincipal.tlbVender.Enabled=true
    frmPrincipal.fPrincipal.mnuVenderLivros.Enabled=true
    frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=""
  end sub
  
  private sub frmVenderLivros_Load(sender as object, e as System.EventArgs) _
    Handles MyBase.Load

    nPrecoTotal=0
    edtDtHrVenda.Text=DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss")
  end sub
  
  private sub frmVenderLivros_MouseMove(sender as object, e as System.Windows.Forms.MouseEventArgs) _
    Handles MyBase.MouseMove

    frmPrincipal.fPrincipal.statusBar1.Panels(1).Text=Text
  end sub

End Class

End NameSpace