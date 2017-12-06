from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
import Principal

class frmConEditoras(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONEDITORA)  

    FXMAPFUNC(self, SEL_COMMAND, frmConEditoras.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConEditoras.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConEditoras.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConEditoras.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConEditoras.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConEditoras.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConEditoras.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConEditoras.onGridChanged)
    
    self.labDescricao.setText("Editora:")
    self.gridConsulta.setItemText(0, 2, "Editora")

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Editora('S',"", 
      self.edtDescricao.getText()), Resource.STR_EDTNENC, 2)
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
