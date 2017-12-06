#Boa:FramePanel:frmCadIdiomas

from wxPython.wx import *
from TextValidator import TextValidator
from Cadastros import frmCadastros
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource

def create(parent):
    return frmCadIdiomas(parent)

class frmCadIdiomas(frmCadastros):
    def _init_utils(self):
        pass

    def _init_ctrls(self, prnt):
        frmCadastros._init_ctrls(self, prnt, TextValidator.FILTER_NUMERIC, True)
        self._init_utils()
        self.labDescricao.SetLabel(u'Idioma:')
        EVT_BUTTON(self.btnNovo, self.btnNovo.GetId(), self.OnBtnNovoClick)
        EVT_BUTTON(self.btnFechar, self.btnFechar.GetId(), 
          self.OnBtnFecharClick)
        EVT_BUTTON(self.btnPesquisar, self.btnPesquisar.GetId(),
              self.OnBtnPesquisarClick)
        EVT_BUTTON(self.btnAnterior, self.btnAnterior.GetId(),
              self.OnBtnAnteriorClick)
        EVT_BUTTON(self.btnProximo, self.btnProximo.GetId(),
              self.OnBtnProximoClick)
        EVT_BUTTON(self.btnSalvar, self.btnSalvar.GetId(),
              self.OnBtnSalvarClick)
        EVT_BUTTON(self.btnExcluir, self.btnExcluir.GetId(),
              self.OnBtnExcluirClick)
        EVT_BUTTON(self.btnLimpar, self.btnLimpar.GetId(),
              self.OnBtnLimparClick)
                
    def __init__(self, parent):
        self._init_ctrls(parent)
        
    def ValidaDados(self, bTodosDados):
      if RotinasGlobais.Rotinas.ValidaCampo(
        self.edtCodigo.GetValue(), Resource.STR_CODNINF):
        return False
      if bTodosDados:
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtDescricao.GetValue(), Resource.STR_IDININF):
      		return False;
      return True

    def OnBtnFecharClick(self, event):
      self.GetParent().Close(True)
    
    def OnBtnNovoClick(self, event):
      self.btnNovoClick()
      self.NovoDado(ConsultasSQL.ConsSQL.Idioma('N', 
        self.edtCodigo.GetValue(),""))
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      self.PesquisarDados(ConsultasSQL.ConsSQL.Idioma('S', 
        self.edtCodigo.GetValue(),""), Resource.STR_IDINENC)
      event.Skip()

    def OnBtnAnteriorClick(self, event):
      self.registroAnterior()
      event.Skip()

    def OnBtnProximoClick(self, event):
      self.registroProximo()
      event.Skip()

    def OnBtnSalvarClick(self, event):
      self.SalvarDados(self.ValidaDados(True),
        ConsultasSQL.ConsSQL.Idioma('S', self.edtCodigo.GetValue(),""),
        ConsultasSQL.ConsSQL.Idioma('U', self.edtCodigo.GetValue(), 
        self.edtDescricao.GetValue()),
        ConsultasSQL.ConsSQL.Idioma('I', self.edtCodigo.GetValue(), 
        self.edtDescricao.GetValue()), True)
      event.Skip()

    def OnBtnExcluirClick(self, event):
      self.ExcluirDados(self.ValidaDados(False),
        ConsultasSQL.ConsSQL.Idioma('D', self.edtCodigo.GetValue(),""))
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.btnLimparClick()
      event.Skip()

