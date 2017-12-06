require 'fox'
require 'fox/responder'
require 'Cadastros'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'ConEditoras'
require 'ConAssuntos'
require 'ConAutores'
require 'ListaStr'
include Fox
include Responder

class FRMCadLivros < FRMCadastros

  ID_FRMCADLIVROS_BTNADASSUNTOS, ID_FRMCADLIVROS_BTNADAUTORES, 
  ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_BTNPAUTOR, 
  ID_FRMCADLIVROS_BTNPEDITORA, ID_FRMCADLIVROS_LSTASSUNTOS, 
  ID_FRMCADLIVROS_LSTAUTORES, ID_FRMCADLIVROS_EDTCODASSUNTO, 
  ID_FRMCADLIVROS_EDTCODAUTOR, ID_FRMCADLIVROS_EDTCODEDITORA = enum(2000,10)
  
  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_CADLIVRO, iconeMDI, menuMDI, 
      TEXTFIELD_NORMAL, false)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNNOVO, :onBtnNovo)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNANTERIOR, :onBtnAnterior)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNPROXIMO, :onBtnProximo)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNSALVAR, :onBtnSalvar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNEXCLUIR, :onBtnExcluir)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNFECHAR, :onBtnFechar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADASTROS_EDTCODIGO, 
      :onEdtCodigo_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADLIVROS_EDTCODEDITORA, 
      :onEdtCodEditora_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADLIVROS_EDTCODASSUNTO, 
      :onEdtCodAssunto_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADLIVROS_EDTCODAUTOR, 
      :onEdtCodAutor_Killfocus)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADLIVROS_BTNPEDITORA, :onBtnPEditora)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADLIVROS_BTNPASSUNTO, :onBtnPAssunto)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADLIVROS_BTNADASSUNTOS, :onBtnAdAssuntos)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADLIVROS_BTNPAUTOR, :onBtnPAutor)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADLIVROS_BTNADAUTORES, :onBtnAdAutores)
    FXMAPFUNC(SEL_DOUBLECLICKED, ID_FRMCADLIVROS_LSTASSUNTOS, 
      :onLstAssuntos_Dblclk)
    FXMAPFUNC(SEL_DOUBLECLICKED, ID_FRMCADLIVROS_LSTAUTORES, 
      :onLstAutores_Dblclk)

    resize(548, 475)
    @labCodigo.setText("ISBN:")
    @edtCodigo.hide()
    @edtCodigo = FXTextField.new(@frame5, 13, self, 
      ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 24, 121, 21, 3, 20)
    @labDescricao.setText("Título:")  
    @edtDescricao.resize(312, 21)
    @edtDescricao.setNumColumns(50)
  
    frame10 = FXVerticalFrame.new(@frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame11 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame.new(frame11, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame13 = FXHorizontalFrame.new(frame11, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame.new(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame15 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame16 = FXVerticalFrame.new(frame15, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame17 = FXVerticalFrame.new(frame15, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame18 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXVerticalFrame.new(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame20 = FXHorizontalFrame.new(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame21 = FXVerticalFrame.new(frame20, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame22 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame23 = FXVerticalFrame.new(frame22, LAYOUT_LEFT|LAYOUT_BOTTOM, 
      0,0,0,0,0,0,0,0)
    frame24 = FXHorizontalFrame.new(frame22, LAYOUT_LEFT|FRAME_THICK|
      FRAME_SUNKEN, 0,0,0,0,0,0,0,0)
  
    frame25 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame26 = FXVerticalFrame.new(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame27 = FXHorizontalFrame.new(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame28 = FXVerticalFrame.new(frame27, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame29 = FXHorizontalFrame.new(@frame3, LAYOUT_RIGHT|FRAME_THICK|
      FRAME_SUNKEN, 0,0,0,0,0,0,0,0)
  
    labEdicao = FXLabel.new(frame10, "Edição:", nil, LAYOUT_LEFT, 
      326, 48, 39, 13)
    @edtEdicao = FXSpinner.new(frame10, 10, nil, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      324, 64, 92, 21)
    @edtEdicao.range = 1..9999
    @edtEdicao.disable()
  
    labAnoPubli = FXLabel.new(frame12, "Ano Publicação:", nil, LAYOUT_LEFT, 
      8, 88, 81, 13)
    @edtAnoPubli = FXSpinner.new(frame12, 10, nil, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 104, 92, 21)
    @edtAnoPubli.range = 1..9999
    @edtAnoPubli.disable()
  
    labEditora = FXLabel.new(frame14, "Editora:", nil, LAYOUT_LEFT, 
      104, 88, 39, 13)
    @edtCodEditora = FXTextField.new(frame14, 5, self, 
      ID_FRMCADLIVROS_EDTCODEDITORA, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      104, 104, 78, 21, 3, 20)
    @edtCodEditora.disable()
    @edtEditora = FXTextField.new(frame13, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      184, 104, 216, 21, 3, 20)
    @edtEditora.disable()
    @btnPEditora = FXButton.new(frame13, "...", nil, self, 
      ID_FRMCADLIVROS_BTNPEDITORA, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 400, 104, 21, 21, 10, 10, 3, 3 )
    @btnPEditora.disable()
  
    labVolume = FXLabel.new(frame16, "Volume:", nil, LAYOUT_LEFT, 
      8, 128, 41, 13)
    @edtVolume = FXSpinner.new(frame16, 10, nil, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 144, 92, 21)
    @edtVolume.range = 1..9999
    @edtVolume.disable()
  
    labIdioma = FXLabel.new(frame17, "Volume:", nil, LAYOUT_LEFT, 
      104, 128, 56, 13)
    @cmbIdioma = FXComboBox.new(frame17,8,8,nil,0,
      COMBOBOX_INSERT_LAST|FRAME_SUNKEN|FRAME_THICK|LAYOUT_SIDE_TOP|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 144, 320, 21, 3, 20)
    @cmbIdioma.setEditable(false)
    @cmbIdioma.setNumVisible(8)
    @cmbIdioma.disable()
    
    labNPaginas = FXLabel.new(frame19, "Nº Páginas:", nil, LAYOUT_LEFT, 
      8, 168, 59, 13)
    @edtNPaginas = FXSpinner.new(frame19, 10, nil, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 184, 92, 21)
    @edtNPaginas.range = 1..9999
    @edtNPaginas.disable()
  
    labAssunto = FXLabel.new(frame21, "Assunto:", nil, LAYOUT_LEFT, 
      104, 168, 44, 13)
    @edtCodAssunto = FXTextField.new(frame21, 10, self, 
      ID_FRMCADLIVROS_EDTCODASSUNTO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      104, 184, 78, 21, 3, 20)
    @edtCodAssunto.disable()
    @edtAssunto = FXTextField.new(frame20, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      184, 184, 192, 21, 3, 20)
    @edtAssunto.disable()
    @btnAdAssuntos = FXButton.new(frame20, "+", nil, self, 
      ID_FRMCADLIVROS_BTNADASSUNTOS, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 376, 184, 21, 21, 10, 10, 3, 3 )
    @btnAdAssuntos.disable()
    @btnPAssunto = FXButton.new(frame20, "...", nil, self, 
      ID_FRMCADLIVROS_BTNPASSUNTO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 400, 184, 21, 21, 10, 10, 3, 3 )
    @btnPAssunto.disable()
  
    labPreco = FXLabel.new(frame23, "Preço:", nil, LAYOUT_LEFT, 
      8, 216, 40, 13)
    @edtPreco = FXTextField.new(frame23, 7, nil, 
      ID_FRMCADLIVROS_EDTCODEDITORA, TEXTFIELD_LIMITED|TEXTFIELD_REAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      7, 232, 92, 21, 3, 20)
    @edtPreco.disable()

    @lstAssuntos = FXList.new(frame24, 1, self, ID_FRMCADLIVROS_LSTASSUNTOS, 
      LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 208, 320, 48)
    @lstAssuntos.disable()
  
    labQtdEstoque = FXLabel.new(frame26, "Qtd. Estoque:", nil, LAYOUT_LEFT, 
      6, 256, 68, 13)
    @edtQtdEstoque = FXSpinner.new(frame26, 10, nil, 0, SPIN_NORMAL|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT,
      8, 272, 92, 21)
    @edtQtdEstoque.range = 0..9999
    @edtQtdEstoque.disable()
  
    labAutor = FXLabel.new(frame28, "Autor:", nil, LAYOUT_LEFT, 
      104, 256, 31, 13)
    @edtCodAutor = FXTextField.new(frame28, 10, self, 
      ID_FRMCADLIVROS_EDTCODAUTOR, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      104, 272, 78, 21, 3, 20)
    @edtCodAutor.disable()
    @edtAutor = FXTextField.new(frame27, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      184, 272, 192, 21, 3, 20)
    @edtAutor.disable()
    @btnAdAutores = FXButton.new(frame27, "+", nil, self, 
      ID_FRMCADLIVROS_BTNADAUTORES, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 376, 272, 21, 21, 10, 10, 3, 3 )
    @btnAdAutores.disable()
    @btnPAutor = FXButton.new(frame27, "...", nil, self, 
      ID_FRMCADLIVROS_BTNPAUTOR, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 400, 272, 21, 21, 10, 10, 3, 3 )
    @btnPAutor.disable()
  
    @lstAutores = FXList.new(frame29, 1, self, ID_FRMCADLIVROS_LSTAUTORES, 
      LIST_SINGLESELECT|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 104, 296, 320, 48)
    @lstAutores.disable()

    @slAssuntos = LISTASTR.new
    @slAutores = LISTASTR.new
    @slIdiomas = LISTASTR.new
   
    AdicionaCombo()
    IniciaBotoes()
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(@edtCodigo.getText(), Resource::STR_ISBNNINF)
    	  return false
    end
  	if bTodosDados
  	  if $Rotinas.ValidaCampo(@edtDescricao.getText(), Resource::STR_TITNINF)
    		return false
      end
  	  if $Rotinas.ValidaCampo(@edtEditora.getText(), Resource::STR_EDTNINF)
		    return false
      end
      if @lstAssuntos.getNumItems() == 0
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_ASSNINF)
        return false
      end
      if @lstAutores.getNumItems()==0
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_AUTNINF)
        return false
      end
  	end
  	return true
  end 
  
  def onBtnNovo(sender, sel, ptr)
    btnNovoClick()
    InformaLimpaDadosLocal(false)
    HabilitaDadosLocal(true)
    return true
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    if PesquisarDados($ConsSQL.Livro('S', @edtCodigo.getText(),
      "","","","","","","","",""), Resource::STR_LIVNENC)
      InformaLimpaDadosLocal(true)
      HabilitaDadosLocal(true)
    end
    return true
  end
  
  def onBtnAnterior(sender, sel, ptr)
    if registroAnterior()	
      InformaLimpaDadosLocal(true)
    end
    return true
  end
  
  def onBtnProximo(sender, sel, ptr)
    if registroProximo()
      InformaLimpaDadosLocal(true)
    end
    return true
  end
  
  def onBtnSalvar(sender, sel, ptr)
    nPos = @cmbIdioma.getCurrentItem()
    sCodIdioma = @slIdiomas.col[nPos]
  
    sSqlUpdate = $ConsSQL.Livro('U', @edtCodigo.getText(), 
      @edtDescricao.getText(), @edtEdicao.getValue().to_s, 
      @edtAnoPubli.getValue().to_s, @edtVolume.getValue().to_s,
      @edtCodEditora.getText(), sCodIdioma, @edtNPaginas.getValue().to_s,
      $Rotinas.VirgulaParaPonto(@edtPreco.getText(),false),
      @edtQtdEstoque.getValue().to_s)
  
    sSqlInsert = $ConsSQL.Livro('I', @edtCodigo.getText(), 
      @edtDescricao.getText(), @edtEdicao.getValue().to_s, 
      @edtAnoPubli.getValue().to_s, @edtVolume.getValue().to_s,
      @edtCodEditora.getText(), sCodIdioma, @edtNPaginas.getValue().to_s,
      $Rotinas.VirgulaParaPonto(@edtPreco.getText(),false),
      @edtQtdEstoque.getValue().to_s)
  
    if SalvarDados(ValidaDados(true), $ConsSQL.Livro('S', 
      @edtCodigo.getText(),"","","","","","","","",""),
      sSqlUpdate, sSqlInsert, false)
      SalvaLista('A')
      SalvaLista('B')
      btnLimparClick()
      InformaLimpaDadosLocal(false)
      HabilitaDadosLocal(false)	    
    end  
    return true
  end
  
  def onBtnExcluir(sender, sel, ptr)
    if ExcluirDados(ValidaDados(false), $ConsSQL.Livro('D', 
      @edtCodigo.getText(), "","","","","","","","",""))
      InformaLimpaDadosLocal(false)
      HabilitaDadosLocal(false)
    end  
    return true
  end
  
  def onBtnLimpar(sender, sel, ptr)
    btnLimparClick()
    InformaLimpaDadosLocal(false)
    HabilitaDadosLocal(false)
    return true
  end

  def onBtnFechar(sender, sel, ptr)
    onClose(sender, sel, ptr)
    return true
  end

  def onClose(sender, sel, ptr)
    $frmPrincipal.habilitaToolButton("tlbLivro")
    $frmPrincipal.habilitaMenu("CadLivros")
    destroy()
    return true
  end 
 
  def InformaLimpaDadosLocal(bInformar)
    if (bInformar)
      @edtEdicao.setValue(@lstRegistros.col[@nLinhaRegistro][2].to_i)
      @edtAnoPubli.setValue(@lstRegistros.col[@nLinhaRegistro][3].to_i)
      @edtVolume.setValue(@lstRegistros.col[@nLinhaRegistro][4].to_i)
      @edtCodEditora.setText(@lstRegistros.col[@nLinhaRegistro][5])
      @edtEditora.setText(@lstRegistros.col[@nLinhaRegistro][6])
      @cmbIdioma.setText(@lstRegistros.col[@nLinhaRegistro][8])
      @edtNPaginas.setValue(@lstRegistros.col[@nLinhaRegistro][9].to_i)
      @edtPreco.setText(
        $Rotinas.VirgulaParaPonto(@lstRegistros.col[@nLinhaRegistro][10], true))
      @edtQtdEstoque.setValue(@lstRegistros.col[@nLinhaRegistro][11].to_i)
      $Rotinas.AdicionaValoresLista($ConsSQL.LivroAss('S', 
        @edtCodigo.getText(), ""), @lstAssuntos, @slAssuntos)      
      $Rotinas.AdicionaValoresLista($ConsSQL.LivroAut('S',
        @edtCodigo.getText(), ""), @lstAutores, @slAutores)
    else  
      @edtEdicao.setValue(1)
      @edtAnoPubli.setValue(
        $Rotinas.retDataHoraStr(true,false).slice(6,4).to_i)
      @edtVolume.setValue(1)
      @edtCodEditora.setText("")
      @edtEditora.setText("")
      @cmbIdioma.setCurrentItem(0)    
      @edtNPaginas.setValue(1)
      @edtPreco.setText("0,00")
      @edtQtdEstoque.setValue(1)
      @edtCodAssunto.setText("")
      @lstAssuntos.clearItems()
      @edtCodAutor.setText("")
      @lstAutores.clearItems()
      @slAssuntos.col = []
      @slAutores.col = []
    end
  end 
  
  def HabilitaDadosLocal(bHabilita)
    bHabilita ? @edtEdicao.enable() : @edtEdicao.disable()
    bHabilita ? @edtAnoPubli.enable() : @edtAnoPubli.disable()
    bHabilita ? @edtVolume.enable() : @edtVolume.disable()
    bHabilita ? @edtCodEditora.enable() : @edtCodEditora.disable()
    bHabilita ? @btnPEditora.enable() : @btnPEditora.disable()
    bHabilita ? @cmbIdioma.enable() : @cmbIdioma.disable()
    bHabilita ? @edtNPaginas.enable() : @edtNPaginas.disable()
    bHabilita ? @edtPreco.enable() : @edtPreco.disable()
    bHabilita ? @edtQtdEstoque.enable() : @edtQtdEstoque.disable()
    bHabilita ? @edtCodAssunto.enable() : @edtCodAssunto.disable()
    bHabilita ? @btnPAssunto.enable() : @btnPAssunto.disable()
    bHabilita ? @btnAdAssuntos.enable() : @btnAdAssuntos.disable()
    bHabilita ? @lstAssuntos.enable() : @lstAssuntos.disable()
    bHabilita ? @edtCodAutor.enable() : @edtCodAutor.disable()
    bHabilita ? @btnPAutor.enable() : @btnPAutor.disable()
    bHabilita ? @btnAdAutores.enable() : @btnAdAutores.disable()
    bHabilita ? @lstAutores.enable() : @lstAutores.disable()
  end
  
  def AdicionaCombo() 
    @ConsCampos = LISTAMSTR.new
  
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, @ConsCampos, 
      $ConsSQL.Idioma('S',"",""))
      @slIdiomas.col = []
      for nLinha in (0..(@ConsCampos.tam-1)) do
  	    @slIdiomas.col.push(@ConsCampos.col[nLinha][0])
  	    @cmbIdioma.appendItem(@ConsCampos.col[nLinha][1])
  	  end      
    end
    if @ConsCampos.tam < 8
      @cmbIdioma.setNumVisible(@ConsCampos.tam)
    end
  end
  
  def SalvaLista(sOpcao) 
    sISBN = @edtCodigo.getText()
    if sOpcao=='A'
      $Rotinas.AtualizaDados($Rotinas.gConexao, 
        $ConsSQL.LivroAss('D',sISBN,"")) 
  
      nQtd = @slAssuntos.tam-1
      for nCont in (0..nQtd) do
        $Rotinas.AtualizaDados($Rotinas.gConexao, $ConsSQL.LivroAss('I', 
          sISBN, @slAssuntos.col[nCont]))
      end
    elsif sOpcao=='B'
    	$Rotinas.AtualizaDados($Rotinas.gConexao,
        $ConsSQL.LivroAut('D',sISBN,""))
  
      nQtd = @slAutores.tam-1
      for nCont in (0..nQtd) do
        $Rotinas.AtualizaDados($Rotinas.gConexao, $ConsSQL.LivroAut('I', 
          sISBN, @slAutores.col[nCont]))
      end
    end
  end
  
  def onEdtCodigo_Killfocus(sender, sel, ptr)
    if @edtCodigo.getText().length > 0
  	  if $Rotinas.validaISBN(@edtCodigo.getText())==false
        @edtCodigo.setText("")
  		  @edtCodigo.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_ISBNINV)
  	  end
    end	
    return true
  end
  
  def onEdtCodEditora_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodEditora.getText().length > 0
      sEditora = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Editora('S',
        @edtCodEditora.getText(),""),Resource::STR_EDTNENC)    
      if sEditora.length() > 0
        @edtEditora.setText(sEditora)
      else
        @edtCodEditora.setText("")
        @edtEditora.setText("")
        @edtCodEditora.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_EDTNENC)
      end
    else
      @edtEditora.setText("")
    end
    return true
  end
  
  def onEdtCodAssunto_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodAssunto.getText().length > 0
      sAssunto = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Assunto('S',
        @edtCodAssunto.getText(),""),Resource::STR_ASSNENC)    
  
      if sAssunto.length > 0
        @edtAssunto.setText(sAssunto)
      else
        @edtCodAssunto.setText("")
        @edtAssunto.setText("")
        @edtCodAssunto.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_ASSNENC)
      end
    else
      @edtAssunto.setText("")
    end
    return true
  end
  
  def onEdtCodAutor_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodAutor.getText().length > 0
      sAutor = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Autor('S',
        @edtCodAutor.getText(),""),Resource::STR_AUTNENC)    
  
      if sAutor.length > 0
        @edtAutor.setText(sAutor)
      else
        @edtCodAutor.setText("")
        @edtAutor.setText("")
        @edtCodAutor.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_AUTNENC)
      end
    else
      @edtAutor.setText("")
    end
    return true
  end
  
  def onBtnPEditora(sender, sel, ptr)
    fConEditoras = FRMConEditoras.new(self)
    fConEditoras.execute()
    @edtCodEditora.setText($Rotinas.sCodigoSelecionado)
    onEdtCodEditora_Killfocus(nil,0,nil)
    return true
  end
  
  def onBtnPAssunto(sender, sel, ptr)
    fConAssuntos = FRMConAssuntos.new(self)
    fConAssuntos.execute()
    @edtCodAssunto.setText($Rotinas.sCodigoSelecionado)
    onEdtCodAssunto_Killfocus(@edtCodAssunto,0,nil)
    return true
  end
  
  def onBtnAdAssuntos(sender, sel, ptr)
    $Rotinas.AdicionaItemLista(@lstAssuntos, 
      @slAssuntos, @edtCodAssunto, @edtAssunto)
    return true
  end
  
  def onBtnPAutor(sender, sel, ptr)
    fConAutores = FRMConAutores.new(self)
    fConAutores.execute()
    @edtCodAutor.setText($Rotinas.sCodigoSelecionado)
    onEdtCodAutor_Killfocus(@edtCodAutor,0,nil)
    return true
  end
  
  def onBtnAdAutores(sender, sel, ptr)
    $Rotinas.AdicionaItemLista(@lstAutores, 
      @slAutores, @edtCodAutor, @edtAutor)	
    return true
  end
  
  def onLstAssuntos_Dblclk(sender, sel, ptr)
    $Rotinas.RemoveItemLista(@lstAssuntos,@slAssuntos)
    return true
  end
  
  def onLstAutores_Dblclk(sender, sel, ptr)
    $Rotinas.RemoveItemLista(@lstAutores,@slAutores)
    return true
  end
end
