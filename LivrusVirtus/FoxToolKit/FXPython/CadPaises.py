from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadPaises(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADPAIS, 
      iconeMDI, menuMDI, TEXTFIELD_NORMAL, True)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNNOVO, 
      frmCadPaises.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadPaises.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadPaises.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadPaises.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadPaises.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadPaises.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadPaises.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadPaises.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadPaises.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadPaises.onClose)

    self.labDescricao.setText("Pa\xeds: ")

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_PAISNINF):
    		return False        	
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    return True  
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(
      self.ConsSQL.Pais('S', self.edtCodigo.getText(),""), Resource.STR_PAISNENC)
    return True  
  
  def onBtnAnterior(self, sender, sel, ptr):
    self.registroAnterior()	
    return True  
  
  def onBtnProximo(self, sender, sel, ptr):
    self.registroProximo()
    return True  
  
  def onBtnSalvar(self, sender, sel, ptr):
    self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Pais('S', self.edtCodigo.getText(),""),
      self.ConsSQL.Pais('U', self.edtCodigo.getText(), 
        self.edtDescricao.getText()),
      self.ConsSQL.Pais('I', self.edtCodigo.getText(), 
        self.edtDescricao.getText()), 
      True)
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    self.ExcluirDados(self.ValidaDados(False),
      self.ConsSQL.Pais('D', self.edtCodigo.getText(),""))
    return True  
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    return True  

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True
  
  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("CadPaises")
    self.destroy()
    return True
