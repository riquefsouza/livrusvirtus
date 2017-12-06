require 'fox'
require 'fox/responder'
require 'Cadastros'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'ConClientes'
require 'ConLivros'
include Fox
include Responder

class FRMConVendas < FRMCadastros

  ID_FRMCONVENDAS_BTNPESQUISAR, ID_FRMCONVENDAS_BTNLIMPAR, 
  ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNPCLIENTE,
  ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_GRIDVENDAS,
  ID_FRMCONVENDAS_EDTDTHRVENDA, ID_FRMCONVENDAS_EDTISBN, 
  ID_FRMCONVENDAS_EDTCPF = enum(4000,9)
  
  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_CONVENLIVRO, iconeMDI, menuMDI, 
      TEXTFIELD_NORMAL, false)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCONVENDAS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONVENDAS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONVENDAS_BTNFECHAR, :onBtnFechar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONVENDAS_BTNPCLIENTE, :onBtnPCliente)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONVENDAS_BTNPLIVRO, :onBtnPLivro)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCONVENDAS_EDTDTHRVENDA, 
      :onEdtDtHrVenda_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCONVENDAS_EDTISBN, :onEdtISBN_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCONVENDAS_EDTCPF, :onEdtCPF_Killfocus)
    FXMAPFUNC(SEL_SELECTED, ID_FRMCONVENDAS_GRIDVENDAS, :onGridSelected)
    FXMAPFUNC(SEL_CHANGED, ID_FRMCONVENDAS_GRIDVENDAS, :onGridChanged)

    resize(500, 370)
    @labCodigo.hide()
    @edtCodigo.hide()
    @labDescricao.hide()
    @edtDescricao.hide()
    @btnNovo.hide()
  
    frame10 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame.new(frame10, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame13 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame.new(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame15 = FXVerticalFrame.new(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame16 = FXVerticalFrame.new(frame13, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame17 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame18 = FXVerticalFrame.new(frame17, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXVerticalFrame.new(frame17, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame20 = FXHorizontalFrame.new(frame17, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame21 = FXVerticalFrame.new(@frame, LAYOUT_LEFT|LAYOUT_FILL_X|
      LAYOUT_FILL_Y, 0,0,0,0,0,0,0,0)
  
    frame22 = FXHorizontalFrame.new(@frame, LAYOUT_FILL_X, 0,0,0,0,0,0,0,0)
    frame23 = FXHorizontalFrame.new(frame22, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame24 = FXHorizontalFrame.new(frame22, LAYOUT_RIGHT, 0,0,0,0,0,0,0,0)
  
    frame25 = FXHorizontalFrame.new(@frame, LAYOUT_BOTTOM|LAYOUT_RIGHT)
  
    labDtHrVenda = FXLabel.new(frame11, "Data/Hora Venda:", nil, LAYOUT_LEFT, 
      8, 8, 91, 13)
    @edtDtHrVenda = FXTextField.new(frame11, 19, self, 
      ID_FRMCONVENDAS_EDTDTHRVENDA, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 24, 128, 21, 3, 20)
  
    @btnPesquisar = FXButton.new(frame12, "&Pesquisar", nil, self, 
      ID_FRMCONVENDAS_BTNPESQUISAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 144, 22, 75, 25, 15, 15, 3, 3 )
  
    labCPF = FXLabel.new(frame14, "CPF:", nil, LAYOUT_LEFT, 
      8, 48, 48, 13)
    @edtCPF = FXTextField.new(frame14, 14, self, 
      ID_FRMCONVENDAS_EDTCPF, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 64, 128, 21, 3, 20)
  
    labCliente = FXLabel.new(frame15, "Cliente:", nil, LAYOUT_LEFT, 
      142, 48, 56, 13)
    @edtDescricao.hide()
    @edtCliente = FXTextField.new(frame15, 30, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      142, 64, 306, 21, 3, 20)
    @edtCliente.disable()
    @btnPCliente = FXButton.new(frame16, "...", nil, self, 
      ID_FRMCONVENDAS_BTNPCLIENTE, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 64, 21, 21, 10, 10, 3, 3 )
  
    labISBN = FXLabel.new(frame18, "ISBN:", nil, LAYOUT_LEFT, 
      8, 88, 48, 13)
    @edtISBN = FXTextField.new(frame18, 13, self, 
      ID_FRMCONVENDAS_EDTISBN, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 104, 128, 21, 3, 20)
  
    labLivro = FXLabel.new(frame19, "Livro:", nil, LAYOUT_LEFT, 
      142, 88, 40, 13)
    @edtLivro = FXTextField.new(frame19, 30, nil, 0, 
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 142, 104, 306, 21, 3, 20)
    @edtLivro.disable()
    @btnPLivro = FXButton.new(frame20, "...", nil, self, 
      ID_FRMCONVENDAS_BTNPLIVRO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 104, 21, 21, 10, 10, 3, 3 )
  
    @gridVendas = FXTable.new(frame21, 2, 7, self, ID_FRMCONVENDAS_GRIDVENDAS, 
      TABLE_COL_SIZABLE|LAYOUT_FILL_X|LAYOUT_FILL_Y, 0, 136, 355, 122)
    $Rotinas.IniciaLayoutGrid(@gridVendas, 2, 7)
  
    @labRegistro = FXLabel.new(frame23, "Registro 0 de 0", nil, LAYOUT_LEFT, 
      8, 16, 144, 13)
    labPrecoTotal = FXLabel.new(frame24, "Preço Total:", nil, LAYOUT_LEFT, 
      280, 248, 61, 13)
    @edtPrecoTotal = FXTextField.new(frame24, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      344, 246, 127, 21, 3, 20)
    @edtPrecoTotal.disable()
  
    @btnFechar = FXButton.new(frame25, "&Fechar", nil, self, 
      ID_FRMCONVENDAS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 75, 13, 75, 25, 15, 15, 3, 3 )
    @btnLimpar = FXButton.new(frame25, "&Limpar", nil, self, 
      ID_FRMCONVENDAS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_RIGHT, 16, 13, 75, 25, 15, 15, 3, 3 )
    
    nLargura = [ 120, 100, 220, 100, 280, 80 ]
    sRotulos = [ "Data/Hora Venda", "CPF", "Cliente", 
     "ISBN", "Livro", "Preço" ]
  
    $Rotinas.AdicionaColunasGrid(@gridVendas, 1, 6, nLargura, sRotulos)
    @edtPrecoTotal.setText("R$ 0,00")
    @edtDtHrVenda.setText($Rotinas.retDataHoraStr(true,true))
    @edtDtHrVenda.setFocus()

    @lstLinhas = LISTAMSTR.new
  end

  def ConsVenda(sOpcao)
    sret = ""
  
    if @edtDtHrVenda.getText().length() > 0
      sDataHora = $Rotinas.ConverteDataHoraStr(@edtDtHrVenda.getText(), 
        true, "%m/%d/%Y","%H:%M:%S")
    else
      sDataHora = ""
    end  
    sISBN = @edtISBN.getText()
    sCPF = @edtCPF.getText()
  
    if sOpcao == 'L'
      sret = $ConsSQL.Venda('S',"ZERO","","","","")
    else
      sret = $ConsSQL.Venda(sOpcao, sISBN, sCPF, sDataHora, "", "")
    end
    return sret
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    @ConsTotal = LISTAMSTR.new
 
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, 
      @lstLinhas, ConsVenda('S'))
      $Rotinas.AdicionaLinhasGrid(@gridVendas, @lstLinhas, 6)
  
      if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, 
        @ConsTotal, ConsVenda('P'))
        if @ConsTotal.tam > 0
          nTemp = @ConsTotal.col[0][0].to_f
          sPrecoTotal = "R$ " + nTemp.to_s
          @edtPrecoTotal.setText(sPrecoTotal)
        end
        setLabRegistros(1)
      end  
    else
      FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_VENNENC)
    end
    return true
  end
  
  def onBtnLimpar(sender, sel, ptr)
    @edtCPF.setText("")
    @edtCliente.setText("")
    @edtISBN.setText("")
    @edtLivro.setText("")
    if @gridVendas.getNumRows() > 0
      @gridVendas.removeRows(1, @gridVendas.getNumRows()-2)
      @gridVendas.setItemText(1, 0, "1")
      for nCol in (1..(@gridVendas.getNumCols()-1)) do
        @gridVendas.setItemText(1, nCol, "")
      end
    end
    @edtPrecoTotal.setText("R$ 0,00")
    @edtDtHrVenda.setText($Rotinas.retDataHoraStr(true,true))
    @edtDtHrVenda.setFocus()
    return true
  end

  def onBtnFechar(sender, sel, ptr)
    onClose(sender, sel, ptr)
    return true
  end

  def onClose(sender, sel, ptr)
    $frmPrincipal.habilitaMenu("VendasRealizadas")
    destroy()
    return true
  end 

  def onEdtCPF_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCPF.getText().length > 0
      if $Rotinas.validaCPF(@edtCPF.getText())
        sCliente = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Cliente('S',
        @edtCPF.getText(),"","","","","","","","",""),Resource::STR_CLINENC) 
        if sCliente.length == 0
          @edtCPF.setText("")
          @edtCPF.killFocus()
          FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_CLINENC)
        else
          @edtCliente.setText(sCliente)
        end
      else
        @edtCPF.setText("")
        @edtCPF.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_CPFINV)
      end
    else
      @edtCliente.setText("")
    end
    return true
  end
  
  def onEdtISBN_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtISBN.getText().length > 0
      if $Rotinas.validaISBN(@edtISBN.getText())
        sLivro = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Livro('Q',
        @edtISBN.getText(),"","","","","","","","",""),Resource::STR_LIVNENC)
        if sLivro.length == 0
          @edtISBN.setText("")
        	@edtISBN.killFocus()
          FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_LIVNENC)
        else
           @edtLivro.setText(sLivro)
           nQtdEstoque = @ConsCampo.col[0][3].to_i
           if nQtdEstoque > 0
             $Rotinas.sPreco = @ConsCampo.col[0][2]
             $Rotinas.sQtdEstoque = @ConsCampo.col[0][3]
           else
             FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_LIVNEST)
           end
        end
      else
        @edtISBN.setText("")
        @edtISBN.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_ISBNINV)
      end
    else
      @edtLivro.setText("")
    end
    return true
  end
  
  def onBtnPCliente(sender, sel, ptr)
    fConClientes = FRMConClientes.new(self)
    fConClientes.execute()
    @edtCPF.setText($Rotinas.sCodigoSelecionado)
    onEdtCPF_Killfocus(nil,0,nil)
    return true
  end
  
  def onBtnPLivro(sender, sel, ptr)
    fConLivros = FRMConLivros.new(self)
    fConLivros.execute()
    @edtISBN.setText($Rotinas.sCodigoSelecionado)
    onEdtISBN_Killfocus(nil,0,nil)
    return true
  end
  
  def setLabRegistros(nLinha)
    if nLinha >= 1
      @labRegistro.setText("Registro " + nLinha.to_s + " de " +
        (@gridVendas.getNumRows()-1).to_s)
    end
  end
  
  def onGridSelected(sender, sel, ptr)
    setLabRegistros(ptr.fm.row)
    return true
  end
  
  def onGridChanged(sender, sel, ptr)
    setLabRegistros(ptr.row)
    return true
  end
  
  def onEdtDtHrVenda_Killfocus(sender, sel, ptr)
    if @edtDtHrVenda.getText().length > 0
      if $Rotinas.validaDataHora(@edtDtHrVenda.getText(), false)==false
    		@edtDtHrVenda.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_DTHRINV)
      end
    end 
    return true
  end
 
end
