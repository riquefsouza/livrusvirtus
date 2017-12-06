#Boa:Dialog:frmConEnderecos

from wxPython.wx import *
from wxPython.grid import *
from Consultas import frmConsultas
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource

def create(parent):
    return frmConEnderecos(parent)

class frmConEnderecos(frmConsultas):
    def _init_ctrls(self, prnt):
      frmConsultas._init_ctrls(self, prnt)
      self.SetTitle(Resource.STR_CONENDERECO)
      self.labDescricao.SetLabel("Endere\xe7o:  ")
      self.gridConsulta.SetColLabelValue(1, "Logradouro")
      self.gridConsulta.SetColSize(1, 200)

      self.nLargura = ( 150,80,100,80 )
      self.sRotulos = ( "Bairro", "CEP", "Cidade", "Estado" )
      RotinasGlobais.Rotinas.AdicionaColunasGrid(
        self.gridConsulta, 2, 4, self.nLargura, self.sRotulos)

      EVT_BUTTON(self.btnPesquisar, self.btnPesquisar.GetId(), 
        self.OnBtnPesquisarClick)
      EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(), self.OnBtnLimparClick)
      EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(), self.OnBtnFecharClick)
      EVT_CLOSE(self, self.OnFrmConEnderecosClose)
      EVT_GRID_SELECT_CELL(self, self.OnGridSelectCell)
      EVT_GRID_LABEL_LEFT_CLICK(self, self.OnGridLabelLeftClick)

    def __init__(self, parent):
      self._init_ctrls(parent)

    def OnFrmConEnderecosClose(self, event):
      self.Fecha(Resource.MNU_CON_ENDERECOS)
      event.Skip()

    def OnBtnFecharClick(self, event):
      self.Fecha(0)
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.LimparDados()
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      self.PesquisarDados(
        ConsultasSQL.ConsSQL.Endereco('S', "", self.edtDescricao.GetValue(),
        "","","",""), Resource.STR_ENDNENC, 6)
      event.Skip()

    def OnGridSelectCell(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()

    def OnGridLabelLeftClick(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()
