from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadIdiomas(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADIDIOMA, 
      iconeMDI, menuMDI, TEXTFIELD_INTEGER, True)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNNOVO, 
      frmCadIdiomas.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadIdiomas.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadIdiomas.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadIdiomas.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadIdiomas.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadIdiomas.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadIdiomas.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadIdiomas.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadIdiomas.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadIdiomas.onClose)

    self.labDescricao.setText("Idioma: ")

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_IDININF):
    		return False        	
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.NovoDado(self.ConsSQL.Idioma('N', self.edtCodigo.getText(),""))	
    return True  
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(
      self.ConsSQL.Idioma('S', self.edtCodigo.getText(),""), Resource.STR_IDINENC)
    return True  
  
  def onBtnAnterior(self, sender, sel, ptr):
    self.registroAnterior()	
    return True  
  
  def onBtnProximo(self, sender, sel, ptr):
    self.registroProximo()
    return True  
  
  def onBtnSalvar(self, sender, sel, ptr):
    self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Idioma('S', self.edtCodigo.getText(),""),
      self.ConsSQL.Idioma('U', self.edtCodigo.getText(), 
        self.edtDescricao.getText()),
      self.ConsSQL.Idioma('I', self.edtCodigo.getText(), 
        self.edtDescricao.getText()), 
      True)
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    self.ExcluirDados(self.ValidaDados(False),
      self.ConsSQL.Idioma('D', self.edtCodigo.getText(),""))
    return True  
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    return True  

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True
  
  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("CadIdiomas")
    self.destroy()
    return True
