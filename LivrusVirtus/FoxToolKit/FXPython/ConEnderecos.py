from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
import Principal

class frmConEnderecos(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONENDERECO)  

    FXMAPFUNC(self, SEL_COMMAND, frmConEnderecos.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConEnderecos.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConEnderecos.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConEnderecos.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConEnderecos.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConEnderecos.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConEnderecos.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConEnderecos.onGridChanged)

    self.Rotinas = RotinasGlobais.Rotinas
    self.labDescricao.setText("Endere\xe7o:")
    self.Rotinas.IniciaLayoutGrid(self.gridConsulta, 2, 7)
    self.gridConsulta.setItemText(0, 2, "Logradouro")
    self.gridConsulta.setColumnWidth(2, 200)

    self.nLargura = ( 150,80,100,80 )
    self.sRotulos = ( "Bairro", "CEP", "Cidade", "Estado" )
    self.Rotinas.AdicionaColunasGrid(self.gridConsulta, 3, 4, 
      self.nLargura, self.sRotulos)

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S',"", 
      self.edtDescricao.getText(),"","","",""), Resource.STR_ENDNENC, 6)
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
