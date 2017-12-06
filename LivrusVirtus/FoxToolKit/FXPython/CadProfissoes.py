from FXPy.fox import *
from Cadastros import frmCadastros
from resource import Resource
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
import Principal

class frmCadProfissoes(frmCadastros):

  def __init__(self, clienteMDI, iconeMDI, menuMDI):  
    frmCadastros.__init__(self, clienteMDI, Resource.STR_CADPROFISS, 
      iconeMDI, menuMDI, TEXTFIELD_INTEGER, True)

    self.Rotinas = RotinasGlobais.Rotinas
    self.ConsSQL = ConsultasSQL.ConsSQL

    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNNOVO, 
      frmCadProfissoes.onBtnNovo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNPESQUISAR, 
      frmCadProfissoes.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNANTERIOR, 
      frmCadProfissoes.onBtnAnterior)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNPROXIMO, 
      frmCadProfissoes.onBtnProximo)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNSALVAR, 
      frmCadProfissoes.onBtnSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNEXCLUIR, 
      frmCadProfissoes.onBtnExcluir)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNLIMPAR, 
      frmCadProfissoes.onBtnLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmCadProfissoes.ID_FRMCADASTROS_BTNFECHAR, 
      frmCadProfissoes.onBtnFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmCadProfissoes.onClose)

    self.labDescricao.setText("Profiss\xe3o: ")

  def ValidaDados(self, bTodosDados):
    if self.Rotinas.ValidaCampo(self.edtCodigo.getText(), Resource.STR_CODNINF):
   	  return False
    if bTodosDados:
  	  if self.Rotinas.ValidaCampo(self.edtDescricao.getText(), Resource.STR_PROFNINF):
    		return False        	
    return True
  
  def onBtnNovo(self, sender, sel, ptr):
    self.btnNovoClick()
    self.NovoDado(self.ConsSQL.Profissao('N', self.edtCodigo.getText(),""))	
    return True  
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(
      self.ConsSQL.Profissao('S', self.edtCodigo.getText(),""), Resource.STR_PROFNENC)
    return True  
  
  def onBtnAnterior(self, sender, sel, ptr):
    self.registroAnterior()	
    return True  
  
  def onBtnProximo(self, sender, sel, ptr):
    self.registroProximo()
    return True  
  
  def onBtnSalvar(self, sender, sel, ptr):
    self.SalvarDados(self.ValidaDados(True),
      self.ConsSQL.Profissao('S', self.edtCodigo.getText(),""),
      self.ConsSQL.Profissao('U', self.edtCodigo.getText(), 
        self.edtDescricao.getText()),
      self.ConsSQL.Profissao('I', self.edtCodigo.getText(), 
        self.edtDescricao.getText()), 
      True)
    return True  
  
  def onBtnExcluir(self, sender, sel, ptr):
    self.ExcluirDados(self.ValidaDados(False),
      self.ConsSQL.Profissao('D', self.edtCodigo.getText(),""))
    return True  
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.btnLimparClick()
    return True  

  def onBtnFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True
  
  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("CadProfissoes")
    self.destroy()
    return True
