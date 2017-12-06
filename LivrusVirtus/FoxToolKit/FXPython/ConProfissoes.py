from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
import Principal

class frmConProfissoes(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONPROFISS)  

    FXMAPFUNC(self, SEL_COMMAND, frmConProfissoes.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConProfissoes.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConProfissoes.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConProfissoes.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConProfissoes.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConProfissoes.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConProfissoes.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConProfissoes.onGridChanged)
    
    self.labDescricao.setText("Profissão:")
    self.gridConsulta.setItemText(0, 2, "Profissão")

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Profissao('S',"", 
      self.edtDescricao.getText()), Resource.STR_PROFNENC, 2)
    return True
  
  def onBtnLimpar(self, sender, sel, ptr):
    self.LimparDados()
    return True
  
  def onGridSelected(self, sender, sel, ptr):
    self.setLabRegistros(sender.getCurrentRow())
    return True
  
  def onGridChanged(self, sender, sel, ptr):
    self.setLabRegistros(sender.getCurrentRow())
    return True
