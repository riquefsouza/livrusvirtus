#Boa:Dialog:frmConClientes

from wxPython.wx import *
from wxPython.grid import *
from Consultas import frmConsultas
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource

def create(parent):
    return frmConClientes(parent)

class frmConClientes(frmConsultas):
    def _init_ctrls(self, prnt):
      frmConsultas._init_ctrls(self, prnt)
      self.SetTitle(Resource.STR_CONCLIENTE)
      self.labDescricao.SetLabel("Cliente:  ")
      self.gridConsulta.SetColLabelValue(0, "CPF")
      self.gridConsulta.SetColSize(0, 90)
      self.gridConsulta.SetColLabelValue(1, "Nome")
      self.gridConsulta.SetColSize(1, 220)

      self.nLargura = ( 180,80,40,80,120,80,220,150,
                        80,100,100,80,180,80,100 )

      self.sRotulos = ( "Email", "Identidade", "Sexo", 
       "Telefone", "DtNascimento", "CodEndere\xe7o", "Logradouro", 
       "Bairro", "CEP", "Cidade", "Estado", "CodPa\xeds", "Pa\xeds", 
       "CodProfiss\xe3o", "Profiss\xe3o" )

      RotinasGlobais.Rotinas.AdicionaColunasGrid(
        self.gridConsulta, 2, 15, self.nLargura, self.sRotulos)

      EVT_BUTTON(self.btnPesquisar, self.btnPesquisar.GetId(), 
        self.OnBtnPesquisarClick)
      EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(), self.OnBtnLimparClick)
      EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(), self.OnBtnFecharClick)
      EVT_CLOSE(self, self.OnFrmConClientesClose)
      EVT_GRID_SELECT_CELL(self, self.OnGridSelectCell)
      EVT_GRID_LABEL_LEFT_CLICK(self, self.OnGridLabelLeftClick)

    def __init__(self, parent):
      self._init_ctrls(parent)

    def OnFrmConClientesClose(self, event):
      self.Fecha(Resource.MNU_CON_CLIENTES)
      event.Skip()

    def OnBtnFecharClick(self, event):
      self.Fecha(0)
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.LimparDados()
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      self.PesquisarDados(
        ConsultasSQL.ConsSQL.Cliente('S', "", self.edtDescricao.GetValue(),
        "","","","","","","",""), Resource.STR_CLINENC, 17)
      event.Skip()

    def OnGridSelectCell(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()

    def OnGridLabelLeftClick(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()
