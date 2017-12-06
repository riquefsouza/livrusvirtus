from FXPy.fox import *
from Consultas import frmConsultas
from resource import Resource
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
import Principal

class frmConClientes(frmConsultas):

  def __init__(self, owner):
    frmConsultas.__init__(self, owner, Resource.STR_CONCLIENTE)  

    FXMAPFUNC(self, SEL_COMMAND, frmConClientes.ID_FRMCONSULTAS_BTNPESQUISAR, 
      frmConClientes.onBtnPesquisar)
    FXMAPFUNC(self, SEL_COMMAND, frmConClientes.ID_FRMCONSULTAS_BTNLIMPAR, 
      frmConClientes.onBtnLimpar)
    FXMAPFUNC(self, SEL_SELECTED, frmConClientes.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConClientes.onGridSelected)
    FXMAPFUNC(self, SEL_CHANGED, frmConClientes.ID_FRMCONSULTAS_GRIDCONSULTA, 
      frmConClientes.onGridChanged)

    self.Rotinas = RotinasGlobais.Rotinas
    self.labDescricao.setText("Cliente:")
    self.Rotinas.IniciaLayoutGrid(self.gridConsulta, 2, 18)
    self.gridConsulta.setItemText(0, 1, "CPF")
    self.gridConsulta.setColumnWidth(1, 90)
    self.gridConsulta.setItemText(0, 2, "Nome")
    self.gridConsulta.setColumnWidth(2, 220)  

    self.nLargura = ( 180,80,40,80,120,80,220,150,
                      80,100,100,80,180,80,100 )
    self.sRotulos = ( "Email", "Identidade", "Sexo", 
     "Telefone", "DtNascimento", "CodEndere\xe7o", "Logradouro", 
     "Bairro", "CEP", "Cidade", "Estado", "CodPa\xeds", "Pa\xeds", 
     "CodProfiss\xe3o", "Profiss\xe3o" )
    self.Rotinas.AdicionaColunasGrid(self.gridConsulta, 3, 15, 
      self.nLargura, self.sRotulos)

  def create(self):
    frmConsultas.create(self)
  
  def onBtnPesquisar(self, sender, sel, ptr):
    self.PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S',"", 
      self.edtDescricao.getText(),"","","","","","","",""), 
      Resource.STR_CLINENC, 17)
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
