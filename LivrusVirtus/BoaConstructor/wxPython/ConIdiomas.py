#Boa:Dialog:frmConIdiomas

from wxPython.wx import *
from wxPython.grid import *
from Consultas import frmConsultas
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource

def create(parent):
    return frmConIdiomas(parent)

class frmConIdiomas(frmConsultas):
    def _init_ctrls(self, prnt):
      frmConsultas._init_ctrls(self, prnt)
      self.SetTitle(Resource.STR_CONIDIOMA)
      self.labDescricao.SetLabel("Idioma: ")
      self.gridConsulta.SetColLabelValue(1, "Idioma")

      EVT_BUTTON(self.btnPesquisar, self.btnPesquisar.GetId(), 
        self.OnBtnPesquisarClick)
      EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(), self.OnBtnLimparClick)
      EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(), self.OnBtnFecharClick)
      EVT_CLOSE(self, self.OnFrmConIdiomasClose)
      EVT_GRID_SELECT_CELL(self, self.OnGridSelectCell)
      EVT_GRID_LABEL_LEFT_CLICK(self, self.OnGridLabelLeftClick)

    def __init__(self, parent):
      self._init_ctrls(parent)

    def OnFrmConIdiomasClose(self, event):
      self.Fecha(Resource.MNU_CON_IDIOMAS)
      event.Skip()

    def OnBtnFecharClick(self, event):
      self.Fecha(0)
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.LimparDados()
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      self.PesquisarDados(
        ConsultasSQL.ConsSQL.Idioma('S', "", self.edtDescricao.GetValue()),
        Resource.STR_IDINENC, 2)
      event.Skip()

    def OnGridSelectCell(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()

    def OnGridLabelLeftClick(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()
