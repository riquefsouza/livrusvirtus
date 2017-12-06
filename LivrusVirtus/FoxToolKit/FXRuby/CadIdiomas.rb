require 'fox'
require 'fox/responder'
require 'Cadastros'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'
include Fox
include Responder

class FRMCadIdiomas < FRMCadastros
  
  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_CADIDIOMA, iconeMDI, menuMDI, 
      TEXTFIELD_INTEGER, true)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNNOVO, :onBtnNovo)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNANTERIOR, :onBtnAnterior)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNPROXIMO, :onBtnProximo)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNSALVAR, :onBtnSalvar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNEXCLUIR, :onBtnExcluir)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCADASTROS_BTNFECHAR, :onBtnFechar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)

    @labDescricao.setText("Idioma: ")
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(@edtCodigo.getText(), Resource::STR_CODNINF)
    	  return false
    end
  	if bTodosDados
  	  if $Rotinas.ValidaCampo(@edtDescricao.getText(), Resource::STR_IDININF)
    		return false
      end
  	end
  	return true
  end 
  
  def onBtnNovo(sender, sel, ptr)
    btnNovoClick()
    NovoDado($ConsSQL.Idioma('N', @edtCodigo.getText(),""))	
    return true
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    PesquisarDados(
      $ConsSQL.Idioma('S', @edtCodigo.getText(),""), Resource::STR_IDINENC)
    return true
  end
  
  def onBtnAnterior(sender, sel, ptr)
    registroAnterior()	
    return true
  end
  
  def onBtnProximo(sender, sel, ptr)
    registroProximo()
    return true
  end
  
  def onBtnSalvar(sender, sel, ptr)
    SalvarDados(ValidaDados(true),
      $ConsSQL.Idioma('S', @edtCodigo.getText(),""),
      $ConsSQL.Idioma('U', @edtCodigo.getText(), @edtDescricao.getText()),
      $ConsSQL.Idioma('I', @edtCodigo.getText(), @edtDescricao.getText()), 
      true)
    return true
  end
  
  def onBtnExcluir(sender, sel, ptr)
    ExcluirDados(ValidaDados(false),
      $ConsSQL.Idioma('D', @edtCodigo.getText(),""))
    return true
  end
  
  def onBtnLimpar(sender, sel, ptr)
    btnLimparClick()
    return true
  end

  def onBtnFechar(sender, sel, ptr)
    onClose(sender, sel, ptr)
    return true
  end

  def onClose(sender, sel, ptr)
    $frmPrincipal.habilitaMenu("CadIdiomas")
    destroy()
    return true
  end 
 
end
