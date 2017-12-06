require 'fox'
require 'fox/responder'
require 'Cadastros'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'ConEnderecos'
require 'ConPaises'
require 'ConProfissoes'
include Fox
include Responder

class FRMCadClientes < FRMCadastros

  ID_FRMCADCLIENTES_BTNPENDERECO, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
  ID_FRMCADCLIENTES_BTNPPAIS, ID_FRMCADCLIENTES_EDTCODENDERECO, 
  ID_FRMCADCLIENTES_EDTCODPAIS, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
  ID_FRMCADCLIENTES_EDTDTNASC, ID_FRMCADCLIENTES_RBMASCULINO, 
  ID_FRMCADCLIENTES_RBFEMININO = enum(1000,9)
  
  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_CADCLIENTE, iconeMDI, menuMDI, 
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
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADCLIENTES_RBMASCULINO, :onCmdSexoMasc)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADCLIENTES_RBFEMININO, :onCmdSexoFem)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADASTROS_EDTCODIGO, 
      :onEdtCodigo_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADCLIENTES_EDTDTNASC, 
      :onEdtDtNasc_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADCLIENTES_EDTCODENDERECO, 
      :onEdtCodEndereco_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADCLIENTES_EDTCODPAIS, 
      :onEdtCodPais_Killfocus)
    FXMAPFUNC(SEL_FOCUSOUT, ID_FRMCADCLIENTES_EDTCODPROFISSAO, 
      :onEdtCodProfissao_Killfocus)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADCLIENTES_BTNPENDERECO, :onBtnPEndereco)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADCLIENTES_BTNPPAIS, :onBtnPPais)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADCLIENTES_BTNPPROFISSAO, :onBtnPProfissao)

    resize(558, 515)
    @labCodigo.setText("CPF:")
    @edtCodigo.hide()
    @edtCodigo = FXTextField.new(@frame5, 14, self, 
      ID_FRMCADASTROS_EDTCODIGO, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 8, 24, 121, 21, 3, 20)
    @labDescricao.setText("Nome: ")  
    @edtDescricao.resize(312, 21)
    @edtDescricao.setNumColumns(30)
  
    frame10 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame13 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame14 = FXVerticalFrame.new(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame15 = FXVerticalFrame.new(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame16 = FXVerticalFrame.new(frame13, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    labEmail = FXLabel.new(frame11, "Bairro:", nil, LAYOUT_LEFT, 
      8, 88, 34, 13)
    @edtEmail = FXTextField.new(frame11, 30, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 104, 312, 21, 3, 20)
    @edtEmail.disable()
  
    labIdentidade = FXLabel.new(frame12, "Identidade:", nil, LAYOUT_LEFT, 
      322, 88, 56, 13)
    @edtIdentidade = FXTextField.new(frame12, 10, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      322, 104, 100, 21, 3, 20)
    @edtIdentidade.disable()

    @gpSexo = FXGroupBox.new(frame14,"Sexo",LAYOUT_LEFT|FRAME_GROOVE|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 9, 128, 200, 44)
    frameSexo = FXHorizontalFrame.new(@gpSexo, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    @rbMasculino = FXRadioButton.new(frameSexo,"Masculino",self,
      ID_FRMCADCLIENTES_RBMASCULINO, ICON_BEFORE_TEXT|LAYOUT_LEFT)
    @rbMasculino.disable()
    @rbMasculino.setCheck(true)
    @rbFeminino = FXRadioButton.new(frameSexo,"Feminino",self,
      ID_FRMCADCLIENTES_RBFEMININO, ICON_BEFORE_TEXT|LAYOUT_LEFT)
    @rbFeminino.disable()
    @gpSexo.disable()
  
    labTelefone = FXLabel.new(frame15, "Telefone:", nil, LAYOUT_LEFT, 
      216, 128, 48, 13)
    @edtTelefone = FXTextField.new(frame15, 17, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      216, 144, 104, 21, 3, 20)
    @edtTelefone.disable()
  
    labDtNasc = FXLabel.new(frame16, "Dt. Nascimento:", nil, LAYOUT_LEFT, 
      216, 128, 48, 13)
    @edtDtNasc = FXTextField.new(frame16, 10, self, 
      ID_FRMCADCLIENTES_EDTDTNASC, TEXTFIELD_LIMITED|FRAME_SUNKEN|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 216, 144, 104, 21, 3, 20)
    @edtDtNasc.disable()
  
    gpEndereco = FXGroupBox.new(@frame3,"Endereço",LAYOUT_SIDE_TOP|FRAME_GROOVE|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 9, 128, 430, 145)
  
    frame17 = FXHorizontalFrame.new(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame18 = FXHorizontalFrame.new(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame19 = FXVerticalFrame.new(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame20 = FXVerticalFrame.new(frame18, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame21 = FXHorizontalFrame.new(gpEndereco, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame22 = FXVerticalFrame.new(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame23 = FXVerticalFrame.new(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame24 = FXVerticalFrame.new(frame21, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    @edtCodEndereco = FXTextField.new(frame17, 10, self, 
      ID_FRMCADCLIENTES_EDTCODENDERECO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      16, 200, 88, 21, 3, 20)
    @edtCodEndereco.disable()
  
    @btnPEndereco = FXButton.new(frame17, "...", nil, self, 
      ID_FRMCADCLIENTES_BTNPENDERECO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|
      LAYOUT_LEFT, 104, 200, 21, 21, 10, 10, 3, 3 )
    @btnPEndereco.disable()
  
    labLogradouro = FXLabel.new(frame19, "Logradouro:", nil, LAYOUT_LEFT, 
      16, 224, 60, 13)
    @edtLogradouro = FXTextField.new(frame19, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      16, 240, 264, 21, 3, 20)
    @edtLogradouro.disable()
  
    labBairro = FXLabel.new(frame20, "Bairro:", nil, LAYOUT_LEFT, 
      284, 224, 48, 13)
    @edtBairro = FXTextField.new(frame20, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      284, 240, 144, 21, 3, 20)
    @edtBairro.disable()
  
    labCEP = FXLabel.new(frame22, "CEP:", nil, LAYOUT_LEFT, 
      16, 264, 40, 13)
    @edtCEP = FXTextField.new(frame22, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      16, 280, 78, 21, 3, 20)
    @edtCEP.disable()
  
    labCidade = FXLabel.new(frame23, "Cidade:", nil, LAYOUT_LEFT, 
      96, 264, 39, 13)
    @edtCidade = FXTextField.new(frame23, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      96, 280, 184, 21, 3, 20)
    @edtCidade.disable()
  
    labEstado = FXLabel.new(frame24, "Estado:", nil, LAYOUT_LEFT, 
      284, 264, 56, 13)
    @edtEstado = FXTextField.new(frame24, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      284, 280, 144, 21, 3, 20)
    @edtEstado.disable()
  
    frame25 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame26 = FXVerticalFrame.new(frame25, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame27 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame28 = FXVerticalFrame.new(frame27, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    labPais = FXLabel.new(frame26, "País de origem:", nil, LAYOUT_LEFT, 
      8, 320, 77, 16)
    
    @edtCodPais = FXTextField.new(frame26, 3, self, 
      ID_FRMCADCLIENTES_EDTCODPAIS, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 336, 78, 21, 3, 20)
    @edtCodPais.disable()
  
    @edtPais = FXTextField.new(frame25, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      88, 336, 240, 21, 3, 20)
    @edtPais.disable()
    @btnPPais = FXButton.new(frame25, "...", nil, self, 
      ID_FRMCADCLIENTES_BTNPPAIS, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 328, 336, 21, 21, 10, 10, 3, 3 )
    @btnPPais.disable()
  
    labProfissao = FXLabel.new(frame28, "Profissão:", nil, LAYOUT_LEFT, 
      8, 360, 56, 13)
    @edtCodProfissao = FXTextField.new(frame28, 10, self, 
      ID_FRMCADCLIENTES_EDTCODPROFISSAO, TEXTFIELD_LIMITED|TEXTFIELD_INTEGER|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 376, 78, 21, 3, 20)
    @edtCodProfissao.disable()
    @edtProfissao = FXTextField.new(frame27, 50, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM, 
      88, 376, 240, 21, 3, 20)
    @edtProfissao.disable()
    @btnPProfissao = FXButton.new(frame27, "...", nil, self, 
      ID_FRMCADCLIENTES_BTNPPROFISSAO, FRAME_RAISED|FRAME_THICK|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT|LAYOUT_BOTTOM|
      LAYOUT_LEFT, 328, 376, 21, 21, 10, 10, 3, 3 )
    @btnPProfissao.disable()
  
    IniciaBotoes()
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(@edtCodigo.getText(), Resource::STR_CPFNINF)
    	  return false
    end
  	if bTodosDados
  	  if $Rotinas.ValidaCampo(@edtDescricao.getText(), Resource::STR_CLININF)
    		return false
      end
      if $Rotinas.ValidaCampo(@edtEmail.getText(), Resource::STR_EMAILNINF)
        return false
      end
      if $Rotinas.ValidaCampo(@edtTelefone.getText(), Resource::STR_TELNINF)
        return false
      end
      if $Rotinas.ValidaCampo(@edtCodEndereco.getText(), Resource::STR_ENDNINF)
        return false
      end
      if $Rotinas.ValidaCampo(@edtCodPais.getText(), Resource::STR_PAISNINF)
        return false
      end
      if $Rotinas.ValidaCampo(@edtCodProfissao.getText(), Resource::STR_PROFNINF)
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
    if PesquisarDados($ConsSQL.Cliente('S', @edtCodigo.getText(),
      "","","","","","","","",""), Resource::STR_CLINENC)
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
    sSexo = ''
  
    if @rbMasculino.getCheck()
       sSexo = "M" 
    else   
       sSexo = "F"
    end  
    sDtNasc = $Rotinas.ConverteDataHoraStr(@edtDtNasc.getText(), 
      true, "%Y/%m/%d", "")
  
    sSqlUpdate = $ConsSQL.Cliente('U', @edtCodigo.getText(), 
      @edtDescricao.getText(), @edtEmail.getText(),  @edtIdentidade.getText(), 
      sSexo, @edtTelefone.getText(), sDtNasc, @edtCodEndereco.getText(), 
      @edtCodPais.getText(), @edtCodProfissao.getText())
  
    sSqlInsert = $ConsSQL.Cliente('I', @edtCodigo.getText(), 
      @edtDescricao.getText(), @edtEmail.getText(),  @edtIdentidade.getText(), 
      sSexo, @edtTelefone.getText(), sDtNasc, @edtCodEndereco.getText(), 
      @edtCodPais.getText(), @edtCodProfissao.getText())
  
    if SalvarDados(ValidaDados(true),
      $ConsSQL.Cliente('S', @edtCodigo.getText(),"","","","","","","","",""),
      sSqlUpdate, sSqlInsert, true) 
      InformaLimpaDadosLocal(false)
      HabilitaDadosLocal(false)	
    end
    return true
  end
  
  def onBtnExcluir(sender, sel, ptr)
    if ExcluirDados(ValidaDados(false),$ConsSQL.Cliente('D', 
      @edtCodigo.getText(),"","","","","","","","",""))
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
    $frmPrincipal.habilitaToolButton("tlbCliente")
    $frmPrincipal.habilitaMenu("CadClientes")
    destroy()
    return true
  end 
 
  def InformaLimpaDadosLocal(bInformar) 
    if (bInformar)
      @edtCodigo.setText(@lstRegistros.col[@nLinhaRegistro][0])
      @edtEmail.setText(@lstRegistros.col[@nLinhaRegistro][2])
      @edtIdentidade.setText(@lstRegistros.col[@nLinhaRegistro][3])
      if @lstRegistros.col[@nLinhaRegistro][4] == "M"
        @rbMasculino.setCheck(true)
        @rbFeminino.setCheck(false)
      else
        @rbMasculino.setCheck(false)
        @rbFeminino.setCheck(true)
      end
      @edtTelefone.setText(@lstRegistros.col[@nLinhaRegistro][5])
      sTemp = @lstRegistros.col[@nLinhaRegistro][6]
      @edtDtNasc.setText(sTemp.slice(0,10))
      @edtCodEndereco.setText(@lstRegistros.col[@nLinhaRegistro][7])
      @edtLogradouro.setText(@lstRegistros.col[@nLinhaRegistro][8])
      @edtBairro.setText(@lstRegistros.col[@nLinhaRegistro][9])
      @edtCEP.setText(@lstRegistros.col[@nLinhaRegistro][10])
      @edtCidade.setText(@lstRegistros.col[@nLinhaRegistro][11])
      @edtEstado.setText(@lstRegistros.col[@nLinhaRegistro][12])
      @edtCodPais.setText(@lstRegistros.col[@nLinhaRegistro][13])
      @edtPais.setText(@lstRegistros.col[@nLinhaRegistro][14])
      @edtCodProfissao.setText(@lstRegistros.col[@nLinhaRegistro][15])
      @edtProfissao.setText(@lstRegistros.col[@nLinhaRegistro][16])
    else
      @edtEmail.setText("")
      @edtIdentidade.setText("")
      @rbMasculino.setCheck(true)
      @rbFeminino.setCheck(false)
      @edtTelefone.setText("")
      @edtDtNasc.setText("")
      @edtCodEndereco.setText("")
      @edtLogradouro.setText("")
      @edtBairro.setText("")
      @edtCEP.setText("")
      @edtCidade.setText("")
      @edtEstado.setText("")
      @edtCodPais.setText("")
      @edtPais.setText("")
      @edtCodProfissao.setText("")
      @edtProfissao.setText("")
      @edtCodigo.setFocus()
    end
  end 
  
  def HabilitaDadosLocal(bHabilita)
    if (bHabilita)
      @edtEmail.enable()
      @edtIdentidade.enable()
      @gpSexo.enable()
      @rbMasculino.enable()
      @rbFeminino.enable()
      @edtTelefone.enable()
      @edtDtNasc.enable()
      @edtCodEndereco.enable()
      @btnPEndereco.enable()
      @edtCodPais.enable()
      @btnPPais.enable()
      @edtCodProfissao.enable()
      @btnPProfissao.enable()
    else
      @edtEmail.disable()
      @edtIdentidade.disable()
      @gpSexo.disable()
      @rbMasculino.disable()
      @rbFeminino.disable()
      @edtTelefone.disable()
      @edtDtNasc.disable()
      @edtCodEndereco.disable()
      @btnPEndereco.disable()
      @edtCodPais.disable()
      @btnPPais.disable()
      @edtCodProfissao.disable()
      @btnPProfissao.disable()
    end
  end

  def onCmdSexoMasc(sender, sel, ptr)
    @rbMasculino.setCheck(true)
    @rbFeminino.setCheck(false)
    return true
  end

  def onCmdSexoFem(sender, sel, ptr)
    @rbMasculino.setCheck(false)
    @rbFeminino.setCheck(true)
    return true
  end
  
  def onEdtCodigo_Killfocus(sender, sel, ptr)
    if @edtCodigo.getText().length > 0
  	  if $Rotinas.validaCPF(@edtCodigo.getText())==false
        @edtCodigo.setText("")
  		  @edtCodigo.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_CPFINV)
  	  end
    end	
    return true
  end
  
  def onEdtDtNasc_Killfocus(sender, sel, ptr)
    if @edtDtNasc.getText().length > 0
      if $Rotinas.validaDataHora(@edtDtNasc.getText(), true)==false
        @edtDtNasc.setText($Rotinas.retDataHoraStr(true,false))
  		  @edtDtNasc.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_DTHRINV)
      end
    else
      @edtDtNasc.setText($Rotinas.retDataHoraStr(true,false))
    end
    return true
  end
  
  def onEdtCodEndereco_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodEndereco.getText().length() > 0
      sLogradouro = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Endereco('S',
      @edtCodEndereco.getText(),"","","","",""),Resource::STR_ENDNENC)
      if sLogradouro.length > 0
        @edtLogradouro.setText(sLogradouro)
        @edtBairro.setText(@ConsCampo.col[0][2])
        @edtCEP.setText(@ConsCampo.col[0][3])
        @edtCidade.setText(@ConsCampo.col[0][4])
        @edtEstado.setText(@ConsCampo.col[0][5])
      else	    
        @edtCodEndereco.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_ENDNENC)
        @edtLogradouro.setText("")
        @edtBairro.setText("")
        @edtCEP.setText("")
  	    @edtCidade.setText("")
  	    @edtEstado.setText("")      
      end
    else
      @edtLogradouro.setText("")
      @edtBairro.setText("")
      @edtCEP.setText("")
      @edtCidade.setText("")
      @edtEstado.setText("")
    end
    return true
  end
  
  def onEdtCodPais_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodPais.getText().length > 0
      sPais = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Pais('S',
        @edtCodPais.getText(),""),Resource::STR_PAISNENC)    
      if sPais.length > 0
        @edtPais.setText(sPais)
      else      
        @edtCodPais.killFocus()
        FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_PAISNENC)
        @edtCodPais.setText("")
        @edtPais.setText("")
      end
    else
      @edtPais.setText("")
    end
    return true
  end
  
  def onEdtCodProfissao_Killfocus(sender, sel, ptr)
    @ConsCampo = LISTAMSTR.new
  
    if @edtCodProfissao.getText().length > 0
      sProfissao = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Profissao('S',
        @edtCodProfissao.getText(),""),Resource::STR_PROFNENC)    
  
      if sProfissao.length > 0
        @edtProfissao.setText(sProfissao)
      else
         @edtCodProfissao.killFocus()
         FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_PROFNENC)
         @edtCodProfissao.setText("")
         @edtProfissao.setText("")
      end
    else
      @edtProfissao.setText("")
    end
    return true
  end
  
  def onBtnPEndereco(sender, sel, ptr)
    fConEnderecos = FRMConEnderecos.new(self)
    fConEnderecos.execute()
    @edtCodEndereco.setText($Rotinas.sCodigoSelecionado)
    onEdtCodEndereco_Killfocus(nil,0,nil)
    return true
  end
  
  def onBtnPPais(sender, sel, ptr)
    fConPaises = FRMConPaises.new(self)
    fConPaises.execute()
    @edtCodPais.setText($Rotinas.sCodigoSelecionado)
    onEdtCodPais_Killfocus(nil,0,nil)
    return true
  end
  
  def onBtnPProfissao(sender, sel, ptr)
    fConProfissoes = FRMConProfissoes.new(self)
    fConProfissoes.execute()
    @edtCodProfissao.setText($Rotinas.sCodigoSelecionado)
    onEdtCodProfissao_Killfocus(nil,0,nil)
    return true
  end
  
end
