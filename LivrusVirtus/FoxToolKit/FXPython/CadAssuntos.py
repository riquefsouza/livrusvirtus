from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadAssuntos(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADASSUNTO, 
      iconeMDI, menuMDI, TEXTFIELD_INTEGER, True)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNNOVO, 
      frmCadAssuntos.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadAssuntos.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadAssuntos.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadAssuntos.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadAssuntos.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadAssuntos.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadAssuntos.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadAssuntos.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadAssuntos.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadAssuntos.onClose)

    self.labDescricao.setText("Assunto: ")

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_ASSNINF):
    		return False        	
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.NovoDado(self.ConsSQL.Assunto('N', self.edtCodigo.getText(),""))	
    return True  
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(
      self.ConsSQL.Assunto('S', self.edtCodigo.getText(),""), Resource.STR_ASSNENC)
    return True  
  
  def onBtnAnterior(self, sender, sel, ptr):
    self.registroAnterior()	
    return True  
  
  def onBtnProximo(self, sender, sel, ptr):
    self.registroProximo()
    return True  
  
  def onBtnSalvar(self, sender, sel, ptr):
    self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Assunto('S', self.edtCodigo.getText(),""),
      self.ConsSQL.Assunto('U', self.edtCodigo.getText(), 
        self.edtDescricao.getText()),
      self.ConsSQL.Assunto('I', self.edtCodigo.getText(), 
        self.edtDescricao.getText()), 
      True)
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    self.ExcluirDados(self.ValidaDados(False),
      self.ConsSQL.Assunto('D', self.edtCodigo.getText(),""))
    return True  
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    return True  

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True
  
  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("CadAssuntos")
    self.destroy()
    return True
