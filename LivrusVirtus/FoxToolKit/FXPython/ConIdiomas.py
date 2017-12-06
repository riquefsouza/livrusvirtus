from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
import Principal

class frmConIdiomas(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONIDIOMA)  

    FXMAPFUNC(self, SEL_COMMAND, frmConIdiomas.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConIdiomas.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConIdiomas.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConIdiomas.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConIdiomas.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConIdiomas.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConIdiomas.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConIdiomas.onGridChanged)
    
    self.labDescricao.setText("Idioma:")
    self.gridConsulta.setItemText(0, 2, "Idioma")

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Idioma('S',"", 
      self.edtDescricao.getText()), Resource.STR_IDINENC, 2)
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
