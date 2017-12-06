from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
import Principal

class frmConLivros(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONLIVRO)  

    FXMAPFUNC(self, SEL_COMMAND, frmConLivros.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConLivros.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConLivros.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConLivros.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConLivros.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConLivros.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConLivros.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConLivros.onGridChanged)
    
    self.Rotinas = RotinasGlobais.Rotinas
    self.labDescricao.setText("Livro:")
    self.Rotinas.IniciaLayoutGrid(self.gridConsulta, 2, 13)
    self.gridConsulta.setItemText(0, 1, "ISBN")
    self.gridConsulta.setColumnWidth(1, 80)
    self.gridConsulta.setItemText(0, 2, "Título")
    self.gridConsulta.setColumnWidth(2, 180)
  
    self.nLargura = ( 80,90,80,80,100,80,100,80,80,80 )
    self.sRotulos = ( "Edi\xe7\xe3o", "AnoPublica\xe7\xe3o", "Volume",
      "CodEditora", "Editora", "CodIdioma", "Idioma",
      "NumP\xe1ginas", "Pre\xe7o", "Estoque" )
    self.Rotinas.AdicionaColunasGrid(self.gridConsulta, 3, 10, 
      self.nLargura, self.sRotulos)

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Livro('S',"", 
      self.edtDescricao.getText(),"","","","","","","",""), 
      Resource.STR_LIVNENC, 12)
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
