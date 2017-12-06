from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadEditoras(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADEDITORA, 
      iconeMDI, menuMDI, TEXTFIELD_INTEGER, True)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNNOVO, 
      frmCadEditoras.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadEditoras.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadEditoras.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadEditoras.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadEditoras.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadEditoras.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadEditoras.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadEditoras.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadEditoras.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadEditoras.onClose)

    self.labDescricao.setText("Editora: ")

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_EDTNINF):
    		return False        	
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.NovoDado(self.ConsSQL.Editora('N', self.edtCodigo.getText(),""))	
    return True  
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(
      self.ConsSQL.Editora('S', self.edtCodigo.getText(),""), Resource.STR_EDTNENC)
    return True  
  
  def onBtnAnterior(self, sender, sel, ptr):
    self.registroAnterior()	
    return True  
  
  def onBtnProximo(self, sender, sel, ptr):
    self.registroProximo()
    return True  
  
  def onBtnSalvar(self, sender, sel, ptr):
    self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Editora('S', self.edtCodigo.getText(),""),
      self.ConsSQL.Editora('U', self.edtCodigo.getText(), 
        self.edtDescricao.getText()),
      self.ConsSQL.Editora('I', self.edtCodigo.getText(), 
        self.edtDescricao.getText()), 
      True)
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    self.ExcluirDados(self.ValidaDados(False),
      self.ConsSQL.Editora('D', self.edtCodigo.getText(),""))
    return True  
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    return True  

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True
  
  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("CadEditoras")
    self.destroy()
    return True
