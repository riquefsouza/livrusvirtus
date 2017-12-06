from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
import Principal

class frmConAutores(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONAUTOR)  

    FXMAPFUNC(self, SEL_COMMAND, frmConAutores.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConAutores.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConAutores.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConAutores.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConAutores.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConAutores.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConAutores.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConAutores.onGridChanged)
    
    self.labDescricao.setText("Autor:")
    self.gridConsulta.setItemText(0, 2, "Autor")

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Autor('S',"", 
      self.edtDescricao.getText()), Resource.STR_AUTNENC, 2)
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
