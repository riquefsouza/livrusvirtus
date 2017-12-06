from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadAutores(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADAUTOR, 
      iconeMDI, menuMDI, TEXTFIELD_INTEGER, True)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNNOVO, 
      frmCadAutores.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadAutores.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadAutores.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadAutores.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadAutores.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadAutores.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadAutores.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAutores.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadAutores.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadAutores.onClose)

    self.labDescricao.setText("Autor: ")

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_AUTNINF):
    		return False        	
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.NovoDado(self.ConsSQL.Autor('N', self.edtCodigo.getText(),""))	
    return True  
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(
      self.ConsSQL.Autor('S', self.edtCodigo.getText(),""), Resource.STR_AUTNENC)
    return True  
  
  def onBtnAnterior(self, sender, sel, ptr):
    self.registroAnterior()	
    return True  
  
  def onBtnProximo(self, sender, sel, ptr):
    self.registroProximo()
    return True  
  
  def onBtnSalvar(self, sender, sel, ptr):
    self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Autor('S', self.edtCodigo.getText(),""),
      self.ConsSQL.Autor('U', self.edtCodigo.getText(), 
        self.edtDescricao.getText()),
      self.ConsSQL.Autor('I', self.edtCodigo.getText(), 
        self.edtDescricao.getText()), 
      True)
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    self.ExcluirDados(self.ValidaDados(False),
      self.ConsSQL.Autor('D', self.edtCodigo.getText(),""))
    return True  
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    return True  

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True
  
  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("CadAutores")
    self.destroy()
    return True
