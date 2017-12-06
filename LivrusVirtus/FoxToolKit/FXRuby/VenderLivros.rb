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

class FRMVenderLivros < FRMCadastros
  
  ID_FRMVENDERLIVROS_BTNVENDER, ID_FRMVENDERLIVROS_BTNLIMPAR, 
  ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNPCLIENTE,
  ID_FRMVENDERLIVROS_BTNPLIVRO, ID_FRMVENDERLIVROS_LSTLIVROS,
  ID_FRMVENDERLIVROS_EDTISBN, ID_FRMVENDERLIVROS_BTNADLIVROS = enum(3000, 8)

  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_VENLIVRO, iconeMDI, menuMDI, 
      TEXTFIELD_NORMAL, false)

    FXMAPFUNC(SEL_COMMAND, ID_FRMVENDERLIVROS_BTNVENDER, :onBtnVender)
    FXMAPFUNC(SEL_COMMAND, ID_FRMVENDERLIVROS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMVENDERLIVROS_BTNFECHAR, :onBtnFechar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)
    FXMAPFUNC(SEL_COMMAND, ID_FRMVENDERLIVROS_BTNPCLIENTE, :onBtnPCliente)
    FXMAPFUNC(SEL_COMMAND, ID_FRMVENDERLIVROS_BTNPLIVRO, :onBtnPLivro)
    FXMAPFUNC(SEL_COMMAND, ID_FRMVENDERLIVROS_BTNADLIVROS, :onBtnAdLivros)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADASTROS_EDTCODIGO, :onEdtCodigo_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMVENDERLIVROS_EDTISBN, :onEdtISBN_Killfocus)
    FXMAPFUNC(SEL_DOUBLECLICKED, ID_FRMVENDERLIVROS_LSTLIVROS, 
      :onLstLivros_Dblclk)

    resize(500, 370)
    @btnNovo.hide()
  
    frame10 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame12 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame13 = FXVerticalFrame.new(frame12, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame.new(frame12, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame15 = FXVerticalFrame.new(frame12, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame16 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame17 = FXVerticalFrame.new(frame16, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame18 = FXVerticalFrame.new(frame16, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXHorizontalFrame.new(frame16, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
  
    frame20 = FXVerticalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame21 = FXHorizontalFrame.new(frame20, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame22 = FXHorizontalFrame.new(frame20, LAYOUT_LEFT|FRAME_THICK|
      FRAME_SUNKEN, 0,0,0,0,0,0,0,0)
  
    frame23 = FXHorizontalFrame.new(@frame3, LAYOUT_RIGHT, 0,0,0,0,0,0,0,0)
  
    frame24 = FXHorizontalFrame.new(@frame3, LAYOUT_BOTTOM|LAYOUT_RIGHT)
  
    labDtHrVenda = FXLabel.new(frame11, "Data/Hora Venda:", nil, LAYOUT_LEFT, 
      8, 8, 91, 13)
    @edtDtHrVenda = FXTextField.new(frame11, 30, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 24, 128, 21, 3, 20)
    @edtDtHrVenda.disable()
  
    @labCodigo.hide()
    labCodigo = FXLabel.new(frame13, "CPF:", nil, LAYOUT_LEFT, 
      8, 48, 48, 13)
    @edtCodigo.hide()
    @edtCodigo = FXTextField.new(frame13, 14, self, 
      ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 64, 128, 21, 3, 20)
  
    @labDescricao.hide()
    labDescricao = FXLabel.new(frame14, "Cliente:", nil, LAYOUT_LEFT, 
      142, 48, 56, 13)
    @edtDescricao.hide()
    @edtDescricao = FXTextField.new(frame14, 30, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      142, 64, 306, 21, 3, 20)
    @edtDescricao.disable()
  
    @btnPCliente = FXButton.new(frame15, "...", nil, self, 
      ID_FRMVENDERLIVROS_BTNPCLIENTE, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 64, 21, 21, 10, 10, 3, 3 )
  
    labISBN = FXLabel.new(frame17, "ISBN:", nil, LAYOUT_LEFT, 
      8, 88, 48, 13)
    @edtISBN = FXTextField.new(frame17, 13, self, 
      ID_FRMVENDERLIVROS_EDTISBN, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 104, 128, 21, 3, 20)
  
    labLivro = FXLabel.new(frame18, "Livro:", nil, LAYOUT_LEFT, 
      142, 88, 40, 13)
    @edtLivro = FXTextField.new(frame18, 30, nil, 0,
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 142, 104, 282, 21, 3, 20)
    @edtLivro.disable()
  
    @btnAdLivros = FXButton.new(frame19, "+", nil, self, 
      ID_FRMVENDERLIVROS_BTNADLIVROS, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 424, 104, 21, 21, 10, 10, 3, 3 )
    @btnPLivro = FXButton.new(frame19, "...", nil, self, 
      ID_FRMVENDERLIVROS_BTNPLIVRO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 448, 104, 21, 21, 10, 10, 3, 3 )
  
    labLivros = FXLabel.new(frame21, "Livros para vender:", nil, 
      LAYOUT_LEFT, 8, 128, 120, 13)
    @lstLivros = FXList.new(frame22, 1, self, ID_FRMVENDERLIVROS_LSTLIVROS, 
      LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 144, 464, 96)
  
    labPrecoTotal = FXLabel.new(frame23, "Preço Total:", nil, 
      LAYOUT_LEFT, 280, 248, 61, 13)
    @edtPrecoTotal = FXTextField.new(frame23, 30, nil, 0,
      TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 344, 246, 127, 21, 3, 20)
    @edtPrecoTotal.disable()
  
    @btnVender = FXButton.new(frame24, "&Vender", nil, self, 
      ID_FRMVENDERLIVROS_BTNVENDER, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 239, 275, 75, 25, 15, 15, 3, 3 )
    @btnLimpar = FXButton.new(frame24, "&Limpar", nil, self, 
      ID_FRMVENDERLIVROS_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 319, 275, 75, 25, 15, 15, 3, 3 )
    @btnFechar = FXButton.new(frame24, "&Fechar", nil, self, 
      ID_FRMVENDERLIVROS_BTNFECHAR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 399, 275, 75, 25, 15, 15, 3, 3 )
  
    @edtDtHrVenda.setText($Rotinas.retDataHoraStr(true, true))   

    @slPrecos = LISTASTR.new
    @slISBNs = LISTASTR.new
    @slQtdEstoque = LISTASTR.new
    @nPrecoTotal = 0.0
    LimpaDados()
  end

  def LimpaDados()
    @edtDtHrVenda.setText($Rotinas.retDataHoraStr(true, true))  
    @edtCodigo.setText("")
    @edtDescricao.setText("")
    @edtISBN.setText("")
    @edtLivro.setText("")
    @lstLivros.clearItems()
    @nPrecoTotal = 0.0
    @edtPrecoTotal.setText("R$ 0,00")
    @slPrecos.col = []
    @slISBNs.col = []
    @slQtdEstoque.col = []
    @edtCodigo.setFocus()
  end
  
  def ValidaDados()
    if $Rotinas.ValidaCampo(@edtCodigo.getText(), Resource::STR_CPFNINF)
      return false
    end
    if @lstLivros.getNumItems() == 0
      FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_LIVVENNINF)
      return false
    end
    return true
  end
  
  def SalvaLista()
    nQtd = @lstLivros.getNumItems()
    sCPF = @edtCodigo.getText()
    sPrecoTotal = @nPrecoTotal.to_s
    
    sDTHR = @edtDtHrVenda.getText()
    sDataHora = $Rotinas.ConverteDataHoraStr(sDTHR, true, 
      "%m/%d/%Y","%H:%M:%S")
    
    for nCont in (0..nQtd-1) do
      sISBN = slISBNs.col[nCont]
    
      $Rotinas.AtualizaDados($Rotinas.gConexao, 
        $ConsSQL.Venda('I',sISBN, sCPF, sDataHora,
        $Rotinas.VirgulaParaPonto(sPrecoTotal,false),""))
    
      nQtdEstoque = @slQtdEstoque.col[nCont].to_i
      if nQtdEstoque > 0
        nQtdEstoque = nQtdEstoque - 1
      end
      sQtdEstoque = nQtdEstoque.to_s
      $Rotinas.AtualizaDados($Rotinas.gConexao, 
        $ConsSQL.Venda('U',sISBN, "","","", sQtdEstoque))
    end
    return true
  end 

  def onBtnVender(sender, sel, ptr)
    if ValidaDados()
      if SalvaLista()
        FXMessageBox.information(self, MBOX_OK, 
          Resource::STR_TITULO, Resource::STR_VENRESUC)
        LimpaDados()
      end
    end
    return true
  end

  def onBtnLimpar(sender, sel, ptr)
    LimpaDados()
    return true
  end

  def onBtnFechar(sender, sel, ptr)
    onClose(sender, sel, ptr)
    return true
  end

  def onClose(sender, sel, ptr)
    $frmPrincipal.habilitaToolButton("tlbVenda")
    $frmPrincipal.habilitaMenu("VenderLivros")
    destroy()
    return true
  end 
 
  def onEdtCodigo_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodigo.getText().length > 0
      if $Rotinas.validaCPF(@edtCodigo.getText())
        sCliente = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Cliente('S',
        @edtCodigo.getText(),"","","","","","","","",""),Resource::STR_CLINENC) 
        if sCliente.length==0
          @edtCodigo.setText("")
          @edtCodigo.killFocus()
          FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_CLINENC)
        else
           @edtDescricao.setText(sCliente)
        end
      else
        @edtCodigo.setText("")
        @edtCodigo.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_CPFINV)
      end
    else
       @edtDescricao.setText("")
    end
    return true
  end
  
  def onEdtISBN_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtISBN.getText().length > 0
      if $Rotinas.validaISBN(@edtISBN.getText())
        sLivro = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Livro('Q',
        @edtISBN.getText(),"","","","","","","","",""),Resource::STR_LIVNENC)
        if sLivro.length==0
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
    @edtCodigo.setText($Rotinas.sCodigoSelecionado)
    onEdtCodigo_Killfocus(nil,0,nil)
    return true
  end
  
  def onBtnPLivro(sender, sel, ptr)
    fConLivros = FRMConLivros.new(self)
    fConLivros.execute()
    @edtISBN.setText($Rotinas.sCodigoSelecionado)
    onEdtISBN_Killfocus(nil,0,nil)
    return true
  end
  
  def onBtnAdLivros(sender, sel, ptr) 
    sISBN = @edtISBN.getText()
    sEdtLivro = @edtLivro.getText()
    if sISBN.length > 0
      sLivros = sISBN + " - " + sEdtLivro + " - R$ " + $Rotinas.sPreco
      if @lstLivros.findItem(sLivros)==-1
        @slISBNs.col.push(sISBN)
        @slPrecos.col.push($Rotinas.sPreco)
        @slQtdEstoque.col.push($Rotinas.sQtdEstoque)
        @lstLivros.appendItem(sLivros)
        nPreco = $Rotinas.sPreco.to_f
        @nPrecoTotal = @nPrecoTotal + nPreco
      end
      @edtISBN.setText("")
      @edtLivro.setText("")
      sPrecoTotal = "R$ " + @nPrecoTotal.to_s
      @edtPrecoTotal.setText($Rotinas.VirgulaParaPonto(sPrecoTotal,true))
    end
    return true
  end
  
  def onLstLivros_Dblclk(sender, sel, ptr) 
    if @lstLivros.getNumItems() > 0
      nSelIndice = @lstLivros.getCurrentItem()   
      if @lstLivros.isItemCurrent(nSelIndice)
        nPreco = @slPrecos.col[nSelIndice].to_f
        @nPrecoTotal = @nPrecoTotal-nPreco
        sPrecoTotal = "R$ " + @nPrecoTotal.to_s
        @edtPrecoTotal.setText($Rotinas.VirgulaParaPonto(sPrecoTotal,true))
        @slISBNs.col.delete_at(nSelIndice)
        @slPrecos.col.delete_at(nSelIndice)
        @slQtdEstoque.col.delete_at(nSelIndice)
        @lstLivros.removeItem(nSelIndice)
      end	
    end
    return true
  end  

end
