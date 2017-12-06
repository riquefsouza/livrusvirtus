from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
import Principal

class frmConPaises(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONPAIS)  

    FXMAPFUNC(self, SEL_COMMAND, frmConPaises.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConPaises.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConPaises.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConPaises.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConPaises.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConPaises.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConPaises.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConPaises.onGridChanged)
    
    self.labDescricao.setText("Pa\xeds:")
    self.gridConsulta.setItemText(0, 2, "Pa\xeds")

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Pais('S',"", 
      self.edtDescricao.getText()), Resource.STR_PAISNENC, 2)
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
