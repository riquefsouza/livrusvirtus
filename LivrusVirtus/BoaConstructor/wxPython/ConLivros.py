#Boa:Dialog:frmConLivros

from wxPython.wx import *
from wxPython.grid import *
from Consultas import frmConsultas
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource

def create(parent):
    return frmConLivros(parent)

class frmConLivros(frmConsultas):
    def _init_ctrls(self, prnt):
      frmConsultas._init_ctrls(self, prnt)
      self.SetTitle(Resource.STR_CONLIVRO)
      self.labDescricao.SetLabel("Livro: ")
      self.gridConsulta.SetColLabelValue(0, "ISBN")
      self.gridConsulta.SetColSize(0, 80)
      self.gridConsulta.SetColLabelValue(1, "T\xedtulo")
      self.gridConsulta.SetColSize(1, 180)

      self.nLargura = ( 80,90,80,80,100,80,100,80,80,80 )
      self.sRotulos = ( "Edi\xe7\xe3o", "AnoPublica\xe7\xe3o", "Volume",
        "CodEditora", "Editora", "CodIdioma", "Idioma",
        "NumP\xe1ginas", "Pre\xe7o", "Estoque" )
      RotinasGlobais.Rotinas.AdicionaColunasGrid(
        self.gridConsulta, 2, 10, self.nLargura, self.sRotulos)

      EVT_BUTTON(self.btnPesquisar, self.btnPesquisar.GetId(), 
        self.OnBtnPesquisarClick)
      EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(), self.OnBtnLimparClick)
      EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(), self.OnBtnFecharClick)
      EVT_CLOSE(self, self.OnFrmConLivrosClose)
      EVT_GRID_SELECT_CELL(self, self.OnGridSelectCell)
      EVT_GRID_LABEL_LEFT_CLICK(self, self.OnGridLabelLeftClick)

    def __init__(self, parent):
      self._init_ctrls(parent)

    def OnFrmConLivrosClose(self, event):
      self.Fecha(Resource.MNU_CON_LIVROS)
      event.Skip()

    def OnBtnFecharClick(self, event):
      self.Fecha(0)
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.LimparDados()
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      self.PesquisarDados(
        ConsultasSQL.ConsSQL.Livro('S', "", self.edtDescricao.GetValue(),
        "","","","","","","",""), Resource.STR_LIVNENC, 12)
      event.Skip()

    def OnGridSelectCell(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()

    def OnGridLabelLeftClick(self, event):
      self.setLabRegistros(event.GetRow())
      event.Skip()
