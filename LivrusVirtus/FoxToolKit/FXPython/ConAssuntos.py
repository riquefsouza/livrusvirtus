from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
import Principal

class frmConAssuntos(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONASSUNTO)  

    FXMAPFUNC(self, SEL_COMMAND, frmConAssuntos.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConAssuntos.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConAssuntos.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConAssuntos.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConAssuntos.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConAssuntos.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConAssuntos.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConAssuntos.onGridChanged)
    
    self.labDescricao.setText("Assunto:")
    self.gridConsulta.setItemText(0, 2, "Assunto")

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Assunto('S',"", 
      self.edtDescricao.getText()), Resource.STR_ASSNENC, 2)
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
