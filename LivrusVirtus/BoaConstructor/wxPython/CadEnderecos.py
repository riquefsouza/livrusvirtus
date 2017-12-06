#Boa:FramePanel:frmCadEnderecos

from wxPython.wx import *
from TextValidator import TextValidator
from Cadastros import frmCadastros
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource

[wxID_FRMCADENDERECOS, wxID_FRMCADENDERECOSCMBESTADO, 
 wxID_FRMCADENDERECOSEDTBAIRRO, wxID_FRMCADENDERECOSEDTCEP, 
 wxID_FRMCADENDERECOSEDTCIDADE, wxID_FRMCADENDERECOSLABBAIRRO, 
 wxID_FRMCADENDERECOSLABCEP, wxID_FRMCADENDERECOSLABCIDADE, 
 wxID_FRMCADENDERECOSLABESTADO, 
] = map(lambda _init_ctrls: wxNewId(), range(9))

def create(parent):
    return frmCadEnderecos(parent)

class frmCadEnderecos(frmCadastros):
    def _init_utils(self):
        pass

    def _init_ctrls(self, prnt):
        frmCadastros._init_ctrls(self, prnt, TextValidator.FILTER_NUMERIC, False)
        self._init_utils()
        self.SetClientSize(wxSize(523, 171))
        self.labDescricao.SetLabel('Logradouro: ')
        self.labDescricao.SetSize(wxSize(57, 13))
        self.edtDescricao.SetSize(wxSize(264, 21))

        self.labBairro = wxStaticText(id=wxID_FRMCADENDERECOSLABBAIRRO,
              label=u'Bairro:', name=u'labBairro', parent=self, pos=wxPoint(280,
              48), size=wxSize(48, 13), style=0)

        self.edtBairro = wxTextCtrl(id=wxID_FRMCADENDERECOSEDTBAIRRO,
              name=u'edtBairro', parent=self, pos=wxPoint(280, 64),
              size=wxSize(144, 21), style=0, value=u'')
        self.edtBairro.Enable(False)

        self.labCEP = wxStaticText(id=wxID_FRMCADENDERECOSLABCEP,
              label=u'CEP: ', name=u'labCEP', parent=self, pos=wxPoint(8, 88),
              size=wxSize(40, 13), style=0)

        self.edtCEP = wxTextCtrl(id=wxID_FRMCADENDERECOSEDTCEP, name=u'edtCEP',
              parent=self, pos=wxPoint(8, 104), size=wxSize(72, 21), style=0,
              value=u'')
        self.edtCEP.Enable(False)

        self.labCidade = wxStaticText(id=wxID_FRMCADENDERECOSLABCIDADE,
              label=u'Cidade: ', name=u'labCidade', parent=self, pos=wxPoint(88,
              88), size=wxSize(39, 13), style=0)

        self.edtCidade = wxTextCtrl(id=wxID_FRMCADENDERECOSEDTCIDADE,
              name=u'edtCidade', parent=self, pos=wxPoint(88, 104),
              size=wxSize(184, 21), style=0, value=u'')
        self.edtCidade.Enable(False)

        self.labEstado = wxStaticText(id=wxID_FRMCADENDERECOSLABESTADO,
              label=u'Estado: ', name=u'labEstado', parent=self,
              pos=wxPoint(280, 88), size=wxSize(56, 13), style=0)

        self.cmbEstado = wxChoice(choices=[], id=wxID_FRMCADENDERECOSCMBESTADO,
              name=u'cmbEstado', parent=self, pos=wxPoint(280, 104),
              size=wxSize(144, 21), style=0, validator=wxDefaultValidator)
        self.cmbEstado.Enable(False)

        self.IniciaBotoes()
      
        self.btnPesquisar.SetDimensions(440, 8, 75, 25)
        self.btnAnterior.SetDimensions(440, 40, 75, 25)
        self.btnProximo.SetDimensions(440, 72, 75, 25)
        self.btnSalvar.SetDimensions(200, 136, 75, 25)
        self.btnExcluir.SetDimensions(280, 136, 75, 25)
        self.btnLimpar.SetDimensions(360, 136, 75, 25)
        self.btnFechar.SetDimensions(440, 136, 75, 25)
      
        self.FazLayout()
      
        self.edtDescricao.SetMaxLength(40)
        self.edtBairro.SetMaxLength(15)
        self.edtCEP.SetMaxLength(8)
        self.edtCidade.SetMaxLength(30)
        self.AdicionaCombo()

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

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_3 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_4 = wxBoxSizer(wxVERTICAL)
      self.sizer_5 = wxBoxSizer(wxVERTICAL)
      self.sizer_6 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_6 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_5 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_4 = wxGridSizer(2, 1, 0, 0)
      self.sizer_8 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_9 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_8 = wxGridSizer(2, 1, 0, 0)
      self.sizer_7 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_7 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_7.Add(self.labCodigo, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_7.Add(self.edtCodigo, 0, 0, 0)
      self.sizer_7.Add(self.grid_sizer_7, 0, 0, 0)
      self.sizer_7.Add(self.btnNovo, 0, wxLEFT|wxALIGN_BOTTOM, 5)
      self.sizer_5.Add(self.sizer_7, 1, 0, 0)
      self.grid_sizer_8.Add(self.labDescricao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_8.Add(self.edtDescricao, 0, 0, 0)
      self.sizer_8.Add(self.grid_sizer_8, 0, 0, 0)
      self.grid_sizer_9.Add(self.labBairro, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_9.Add(self.edtBairro, 0, 0, 0)
      self.sizer_8.Add(self.grid_sizer_9, 0, wxLEFT, 2)
      self.sizer_5.Add(self.sizer_8, 1, wxEXPAND, 0)
      self.grid_sizer_4.Add(self.labCEP, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_4.Add(self.edtCEP, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_4, 0, 0, 0)
      self.grid_sizer_5.Add(self.labCidade, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_5.Add(self.edtCidade, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_5, 0, wxLEFT, 4)
      self.grid_sizer_6.Add(self.labEstado, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_6.Add(self.cmbEstado, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_6, 0, wxLEFT, 5)
      self.sizer_5.Add(self.sizer_6, 0, 0, 0)
      self.sizer_3.Add(self.sizer_5, 0, 0, 0)
      self.sizer_4.Add(self.btnPesquisar, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_4.Add(self.btnAnterior, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_4.Add(self.btnProximo, 0, wxALL|wxALIGN_RIGHT, 2)
      self.sizer_3.Add(self.sizer_4, 1, 0, 0)
      self.sizer_1.Add(self.sizer_3, 1, wxALL|wxEXPAND, 4)
      self.sizer_2.Add(self.btnSalvar, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnExcluir, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnLimpar, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_2.Add(self.btnFechar, 0, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 2)
      self.sizer_1.Add(self.sizer_2, 0, 
        wxRIGHT|wxBOTTOM|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4)
      self.SetAutoLayout(true)
      self.SetSizer(self.sizer_1)
      self.sizer_1.Fit(self)
      self.sizer_1.SetSizeHints(self)

    def ValidaDados(self, bTodosDados):
      if RotinasGlobais.Rotinas.ValidaCampo(
        self.edtCodigo.GetValue(), Resource.STR_CODNINF):
        return False
      if bTodosDados:
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtDescricao.GetValue(), Resource.STR_ENDNINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtBairro.GetValue(), Resource.STR_BAIRRONINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtCEP.GetValue(), Resource.STR_CEPNINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtCidade.GetValue(), Resource.STR_CIDADENINF):
      		return False
      return True

    def OnBtnFecharClick(self, event):
      self.GetParent().Close(True)
    
    def OnBtnNovoClick(self, event):
      self.btnNovoClick()
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(True)
      self.NovoDado(ConsultasSQL.ConsSQL.Endereco('N', 
        self.edtCodigo.GetValue(),"","","","",""))
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      if self.PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S', 
        self.edtCodigo.GetValue(),"","","","",""), Resource.STR_ENDNENC):
        self.InformaLimpaDadosLocal(True)
        self.HabilitaDadosLocal(True)
      event.Skip()

    def OnBtnAnteriorClick(self, event):
      if self.registroAnterior():
        self.InformaLimpaDadosLocal(True)
      event.Skip()

    def OnBtnProximoClick(self, event):
      if self.registroProximo():
        self.InformaLimpaDadosLocal(True)
      event.Skip()

    def OnBtnSalvarClick(self, event):
      if self.SalvarDados(self.ValidaDados(True),
        ConsultasSQL.ConsSQL.Endereco('S', self.edtCodigo.GetValue(),
        "","","","",""),
        ConsultasSQL.ConsSQL.Endereco('U', self.edtCodigo.GetValue(), 
        self.edtDescricao.GetValue(),self.edtBairro.GetValue(),
        self.edtCEP.GetValue(),self.edtCidade.GetValue(), 
        self.cmbEstado.GetStringSelection()),
        ConsultasSQL.ConsSQL.Endereco('I', self.edtCodigo.GetValue(), 
        self.edtDescricao.GetValue(),self.edtBairro.GetValue(),
        self.edtCEP.GetValue(),self.edtCidade.GetValue(), 
        self.cmbEstado.GetStringSelection()), True):
        self.InformaLimpaDadosLocal(False)
        self.HabilitaDadosLocal(False)
      event.Skip()

    def OnBtnExcluirClick(self, event):
      if self.ExcluirDados(self.ValidaDados(False),
        ConsultasSQL.ConsSQL.Endereco('D', self.edtCodigo.GetValue(),
        "","","","","")):
        self.InformaLimpaDadosLocal(False)
        self.HabilitaDadosLocal(False)
      event.Skip()

    def OnBtnLimparClick(self, event):
      self.btnLimparClick()
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(False)
      event.Skip()

    def InformaLimpaDadosLocal(self, bInformar):
      if bInformar:
        self.edtBairro.SetValue(self.lstRegistros.col[self.nLinhaRegistro][2])
        self.edtCEP.SetValue(self.lstRegistros.col[self.nLinhaRegistro][3])
        self.edtCidade.SetValue(self.lstRegistros.col[self.nLinhaRegistro][4])
        self.cmbEstado.SetStringSelection(
          self.lstRegistros.col[self.nLinhaRegistro][5])
      else:
        self.edtBairro.Clear()
        self.edtCEP.Clear()
        self.edtCidade.Clear()
        self.cmbEstado.SetSelection(0)
    
    def HabilitaDadosLocal(self, bHabilita):
      self.edtBairro.Enable(bHabilita)
      self.edtCEP.Enable(bHabilita)  
      self.edtCidade.Enable(bHabilita)
      self.cmbEstado.Enable(bHabilita)  

    def AdicionaCombo(self):
      self.cmbEstado.Append(Resource.STR_PE)
      self.cmbEstado.Append(Resource.STR_AC)
      self.cmbEstado.Append(Resource.STR_AL)
      self.cmbEstado.Append(Resource.STR_AP)
      self.cmbEstado.Append(Resource.STR_AM)
      self.cmbEstado.Append(Resource.STR_BA)
      self.cmbEstado.Append(Resource.STR_BR)
      self.cmbEstado.Append(Resource.STR_CE)
      self.cmbEstado.Append(Resource.STR_DF)
      self.cmbEstado.Append(Resource.STR_ES)
      self.cmbEstado.Append(Resource.STR_GO)
      self.cmbEstado.Append(Resource.STR_MT)
      self.cmbEstado.Append(Resource.STR_MS)
      self.cmbEstado.Append(Resource.STR_MG)
      self.cmbEstado.Append(Resource.STR_PA)
      self.cmbEstado.Append(Resource.STR_PB)
      self.cmbEstado.Append(Resource.STR_PR)
      self.cmbEstado.Append(Resource.STR_SC)
      self.cmbEstado.Append(Resource.STR_RN)
      self.cmbEstado.Append(Resource.STR_RS)
      self.cmbEstado.Append(Resource.STR_RJ)
      self.cmbEstado.Append(Resource.STR_RO)
      self.cmbEstado.Append(Resource.STR_RR)
      self.cmbEstado.Append(Resource.STR_SP)
      self.cmbEstado.Append(Resource.STR_SE)
      self.cmbEstado.Append(Resource.STR_TO)

