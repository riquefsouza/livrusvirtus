require 'fox'
require 'fox/responder'
require 'Cadastros'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'
include Fox
include Responder

class FRMCadEnderecos < FRMCadastros
  
  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_CADENDERECO, iconeMDI, menuMDI, 
      TEXTFIELD_INTEGER, false)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNNOVO, :onBtnNovo)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNANTERIOR, :onBtnAnterior)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNPROXIMO, :onBtnProximo)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNSALVAR, :onBtnSalvar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNEXCLUIR, :onBtnExcluir)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNFECHAR, :onBtnFechar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)

    resize(540, 225)
    @labDescricao.setText("Logradouro: ")
    @labDescricao.resize(57, 13)
    @edtDescricao.resize(264, 21)
    @edtDescricao.setNumColumns(40)
  
    frame9 = FXVerticalFrame.new(@frame7, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    frame10 = FXHorizontalFrame.new(@frame3, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame11 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame12 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
    frame13 = FXVerticalFrame.new(frame10, LAYOUT_LEFT, 0,0,0,0,0,0,0,0)
  
    labBairro = FXLabel.new(frame9, "Bairro:", nil, LAYOUT_LEFT, 
      280, 48, 48, 13)
    @edtBairro = FXTextField.new(frame9, 15, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      280, 64, 144, 21, 3, 20)
    @edtBairro.disable()
    labCEP = FXLabel.new(frame11, "CEP:", nil, LAYOUT_LEFT, 
      8, 88, 40, 13)
    @edtCEP = FXTextField.new(frame11, 8, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      8, 104, 72, 21, 3, 20)
    @edtCEP.disable()
    labCidade = FXLabel.new(frame12, "Cidade:", nil, LAYOUT_LEFT, 
      88, 88, 40, 13)
    @edtCidade = FXTextField.new(frame12, 30, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK|LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 
      88, 104, 184, 21, 3, 20)
    @edtCidade.disable()
    labEstado = FXLabel.new(frame13, "Estado:", nil, LAYOUT_LEFT, 
      280, 88, 56, 13)
    @cmbEstado = FXComboBox.new(frame13, 8, 8, nil, 0,
      COMBOBOX_INSERT_LAST|FRAME_SUNKEN|FRAME_THICK|LAYOUT_SIDE_TOP|
      LAYOUT_FIX_WIDTH|LAYOUT_FIX_HEIGHT, 280, 104, 144, 21, 3, 20)
    @cmbEstado.setEditable(false)
    @cmbEstado.setNumVisible(8)
    @cmbEstado.disable()
  
    AdicionaCombo()
    IniciaBotoes()
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(@edtCodigo.getText(), Resource::STR_CODNINF)
   	  return false
    end
  	if bTodosDados
  	  if $Rotinas.ValidaCampo(@edtDescricao.getText(), Resource::STR_ENDNINF)
    		return false
      end
  	  if $Rotinas.ValidaCampo(@edtBairro.getText(), Resource::STR_BAIRRONINF)
    		return false
      end
  	  if $Rotinas.ValidaCampo(@edtCEP.getText(), Resource::STR_CEPNINF)
    		return false
      end
  	  if $Rotinas.ValidaCampo(@edtCidade.getText(), Resource::STR_CIDADENINF)
    		return false
      end
  	end
  	return true
  end 
  
  def onBtnNovo(sender, sel, ptr)
    btnNovoClick()
    InformaLimpaDadosLocal(false)
    HabilitaDadosLocal(true)	
    NovoDado($ConsSQL.Endereco('N', @edtCodigo.getText(),"","","","",""))	
    return true
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    if PesquisarDados($ConsSQL.Endereco('S', @edtCodigo.getText(),
      "","","","",""), Resource::STR_ENDNENC)
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
    if SalvarDados(ValidaDados(true),
      $ConsSQL.Endereco('S', @edtCodigo.getText(),"","","","",""),
      $ConsSQL.Endereco('U', @edtCodigo.getText(), @edtDescricao.getText(),
        @edtBairro.getText(), @edtCEP.getText(), @edtCidade.getText(), 
        @cmbEstado.getText()),
      $ConsSQL.Endereco('I', @edtCodigo.getText(), @edtDescricao.getText(),
        @edtBairro.getText(), @edtCEP.getText(), @edtCidade.getText(), 
        @cmbEstado.getText()), true)
      InformaLimpaDadosLocal(false)
      HabilitaDadosLocal(false)
    end
    return true
  end
  
  def onBtnExcluir(sender, sel, ptr)
    if ExcluirDados(ValidaDados(false),
      $ConsSQL.Endereco('D', @edtCodigo.getText(),"","","","",""))
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
    $frmPrincipal.habilitaMenu("CadEnderecos")
    destroy()
    return true
  end 
 
  def InformaLimpaDadosLocal(bInformar)
    if bInformar
      @edtBairro.setText(@lstRegistros.col[@nLinhaRegistro][2])
      @edtCEP.setText(@lstRegistros.col[@nLinhaRegistro][3])
      @edtCidade.setText(@lstRegistros.col[@nLinhaRegistro][4])
      @cmbEstado.setText(@lstRegistros.col[@nLinhaRegistro][5])
    else
      @edtBairro.setText("")
      @edtCEP.setText("")
      @edtCidade.setText("")
      @cmbEstado.setCurrentItem(0)
    end  
  end 
  
  def HabilitaDadosLocal(bHabilita)
    if bHabilita
      @edtBairro.enable()
      @edtCEP.enable()
      @edtCidade.enable()
      @cmbEstado.enable()
    else
      @edtBairro.disable()
      @edtCEP.disable()
      @edtCidade.disable()
      @cmbEstado.disable()
    end
  end
  
  def AdicionaCombo()
    @cmbEstado.appendItem(Resource::STR_PE)
    @cmbEstado.appendItem(Resource::STR_AC)
    @cmbEstado.appendItem(Resource::STR_AL)
    @cmbEstado.appendItem(Resource::STR_AP)
    @cmbEstado.appendItem(Resource::STR_AM)
    @cmbEstado.appendItem(Resource::STR_BA)
    @cmbEstado.appendItem(Resource::STR_BR)
    @cmbEstado.appendItem(Resource::STR_CE)
    @cmbEstado.appendItem(Resource::STR_DF)
    @cmbEstado.appendItem(Resource::STR_ES)
    @cmbEstado.appendItem(Resource::STR_GO)
    @cmbEstado.appendItem(Resource::STR_MT)
    @cmbEstado.appendItem(Resource::STR_MS)
    @cmbEstado.appendItem(Resource::STR_MG)
    @cmbEstado.appendItem(Resource::STR_PA)
    @cmbEstado.appendItem(Resource::STR_PB)
    @cmbEstado.appendItem(Resource::STR_PR)
    @cmbEstado.appendItem(Resource::STR_SC)
    @cmbEstado.appendItem(Resource::STR_RN)
    @cmbEstado.appendItem(Resource::STR_RS)
    @cmbEstado.appendItem(Resource::STR_RJ)
    @cmbEstado.appendItem(Resource::STR_RO)
    @cmbEstado.appendItem(Resource::STR_RR)
    @cmbEstado.appendItem(Resource::STR_SP)
    @cmbEstado.appendItem(Resource::STR_SE)
    @cmbEstado.appendItem(Resource::STR_TO)
  end

end
