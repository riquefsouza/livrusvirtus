#Boa:FramePanel:frmCadClientes

from wxPython.wx import *
from TextValidator import TextValidator
from Cadastros import frmCadastros
from RotinasGlobais import RotinasGlobais
from ConsultasSQL import ConsultasSQL
from resource import Resource
from DateCtrl import DateCtrl
from ListaStr import LISTAMSTR
import ConEnderecos
import ConPaises
import ConProfissoes

[wxID_FRMCADCLIENTES, wxID_FRMCADCLIENTESBTNPENDERECO, 
 wxID_FRMCADCLIENTESBTNPPAIS, wxID_FRMCADCLIENTESBTNPPROFISSAO, 
 wxID_FRMCADCLIENTESBTNPROXIMO, wxID_FRMCADCLIENTESEDTBAIRRO, 
 wxID_FRMCADCLIENTESEDTCEP, wxID_FRMCADCLIENTESEDTCODPAIS, 
 wxID_FRMCADCLIENTESEDTCIDADE, wxID_FRMCADCLIENTESEDTCODENDERECO,  
 wxID_FRMCADCLIENTESEDTCODPROFISSAO, wxID_FRMCADCLIENTESEDTDTNASC, 
 wxID_FRMCADCLIENTESEDTEMAIL, wxID_FRMCADCLIENTESEDTESTADO, 
 wxID_FRMCADCLIENTESEDTIDENTIDADE, wxID_FRMCADCLIENTESEDTLOGRADOURO, 
 wxID_FRMCADCLIENTESEDTPAIS, wxID_FRMCADCLIENTESEDTPROFISSAO, 
 wxID_FRMCADCLIENTESEDTTELEFONE, wxID_FRMCADCLIENTESLABBAIRRO, 
 wxID_FRMCADCLIENTESLABCEP, wxID_FRMCADCLIENTESLABCIDADE,  
 wxID_FRMCADCLIENTESLABDTNASC, wxID_FRMCADCLIENTESLABEMAIL, 
 wxID_FRMCADCLIENTESLABESTADO, wxID_FRMCADCLIENTESLABIDENTIDADE, 
 wxID_FRMCADCLIENTESLABLOGRADOURO, wxID_FRMCADCLIENTESLABPAIS, 
 wxID_FRMCADCLIENTESLABPROFISSAO, wxID_FRMCADCLIENTESLABTELEFONE, 
 wxID_FRMCADCLIENTESRBSEXO, wxID_FRMCADCLIENTESSBENDERECO, 
] = map(lambda _init_ctrls: wxNewId(), range(32))

def create(parent):
    return frmCadClientes(parent)

class frmCadClientes(frmCadastros):
    def _init_utils(self):
        pass

    def _init_ctrls(self, prnt):
        frmCadastros._init_ctrls(self, prnt, TextValidator.FILTER_NONE, False)
        self._init_utils()
        self.SetClientSize(wxSize(523, 441))
        self.labCodigo.SetLabel("CPF: ")
        self.labDescricao.SetLabel("Nome: ")
        self.edtDescricao.SetSize(wxSize(312, 21))     
        EVT_KILL_FOCUS(self.edtCodigo, self.OnEdtCodigo_Killfocus)

        self.labEmail = wxStaticText(id=wxID_FRMCADCLIENTESLABEMAIL,
              label=u'E-mail: ', name=u'labEmail', parent=self, pos=wxPoint(8,
              88), size=wxSize(34, 13), style=0)

        self.edtEmail = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTEMAIL,
              name=u'edtEmail', parent=self, pos=wxPoint(8, 104),
              size=wxSize(312, 21), style=0, value=u'')
        self.edtEmail.Enable(False)

        self.labIdentidade = wxStaticText(id=wxID_FRMCADCLIENTESLABIDENTIDADE,
              label=u'Identidade: ', name=u'labIdentidade', parent=self,
              pos=wxPoint(322, 88), size=wxSize(56, 13), style=0)

        self.edtIdentidade = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTIDENTIDADE,
              name=u'edtIdentidade', parent=self, pos=wxPoint(322, 104),
              size=wxSize(100, 21), style=0, value=u'')
        self.edtIdentidade.Enable(False)

        self.rbSexo = wxRadioBox(choices=['Masculino', 'Feminino'],
              id=wxID_FRMCADCLIENTESRBSEXO, label=u'Sexo', majorDimension=2,
              name=u'rbSexo', parent=self, point=wxPoint(9, 128),
              size=wxSize(200, 44), style=wxRA_SPECIFY_COLS,
              validator=wxDefaultValidator)
        self.rbSexo.SetStringSelection(u'asd asd')

        self.labTelefone = wxStaticText(id=wxID_FRMCADCLIENTESLABTELEFONE,
              label=u'Telefone: ', name=u'labTelefone', parent=self,
              pos=wxPoint(216, 128), size=wxSize(48, 13), style=0)

        self.edtTelefone = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTTELEFONE,
              name=u'edtTelefone', parent=self, pos=wxPoint(216, 144),
              size=wxSize(104, 21), style=0, value=u'')
        self.edtTelefone.Enable(False)

        self.labDtNasc = wxStaticText(id=wxID_FRMCADCLIENTESLABDTNASC,
              label=u'Dt. Nascimento', name=u'labDtNasc', parent=self,
              pos=wxPoint(322, 128), size=wxSize(73, 13), style=0)

        self.edtDtNasc = DateCtrl(parent=self, 
              id=wxID_FRMCADCLIENTESEDTDTNASC, pos=wxPoint(322, 144),
              size=wxSize(100, 21))
        self.edtDtNasc.Enable(False)
        EVT_KILL_FOCUS(self.edtDtNasc, self.OnEdtDtNasc_Killfocus)

        #self.sbEndereco = wxStaticBox(id=wxID_FRMCADCLIENTESSBENDERECO,
        #      label=u'Endere\xe7o', name=u'sbEndereco', parent=self,
        #      pos=wxPoint(8, 176), size=wxSize(432, 136), style=0)

        self.edtCodEndereco = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTCODENDERECO,
              name=u'edtCodEndereco', parent=self, pos=wxPoint(16, 200),
              size=wxSize(88, 21), style=0, 
              validator=TextValidator(TextValidator.FILTER_NUMERIC), value=u'')
        self.edtCodEndereco.Enable(False)
        EVT_KILL_FOCUS(self.edtCodEndereco, self.OnEdtCodEndereco_Killfocus)

        self.btnPEndereco = wxButton(id=wxID_FRMCADCLIENTESBTNPENDERECO,
              label=u'...', name=u'btnPEndereco', parent=self, pos=wxPoint(104,
              200), size=wxSize(21, 21), style=0)
        self.btnPEndereco.Enable(False)
        EVT_BUTTON(self.btnPEndereco, self.btnPEndereco.GetId(),
              self.OnBtnPEnderecoClick)

        self.labLogradouro = wxStaticText(id=wxID_FRMCADCLIENTESLABLOGRADOURO,
              label=u'Logradouro: ', name=u'labLogradouro', parent=self,
              pos=wxPoint(16, 224), size=wxSize(60, 13), style=0)

        self.edtLogradouro = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTLOGRADOURO,
              name=u'edtLogradouro', parent=self, pos=wxPoint(16, 240),
              size=wxSize(264, 21), style=0, value=u'')
        self.edtLogradouro.Enable(False)

        self.labBairro = wxStaticText(id=wxID_FRMCADCLIENTESLABBAIRRO,
              label=u'Bairro:', name=u'labBairro', parent=self, pos=wxPoint(284,
              224), size=wxSize(48, 13), style=0)

        self.edtBairro = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTBAIRRO,
              name=u'edtBairro', parent=self, pos=wxPoint(284, 240),
              size=wxSize(144, 21), style=0, value=u'')
        self.edtBairro.Enable(False)

        self.labCEP = wxStaticText(id=wxID_FRMCADCLIENTESLABCEP, label=u'CEP: ',
              name=u'labCEP', parent=self, pos=wxPoint(16, 264), size=wxSize(40,
              13), style=0)

        self.edtCEP = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTCEP, name=u'edtCEP',
              parent=self, pos=wxPoint(16, 280), size=wxSize(78, 21), style=0,
              value=u'')
        self.edtCEP.Enable(False)

        self.labCidade = wxStaticText(id=wxID_FRMCADCLIENTESLABCIDADE,
              label=u'Cidade: ', name=u'labCidade', parent=self, pos=wxPoint(96,
              264), size=wxSize(39, 13), style=0)

        self.edtCidade = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTCIDADE,
              name=u'edtCidade', parent=self, pos=wxPoint(96, 280),
              size=wxSize(184, 21), style=0, value=u'')
        self.edtCidade.Enable(False)

        self.labEstado = wxStaticText(id=wxID_FRMCADCLIENTESLABESTADO,
              label=u'Estado: ', name=u'labEstado', parent=self,
              pos=wxPoint(284, 264), size=wxSize(56, 13), style=0)

        self.edtEstado = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTESTADO,
              name=u'edtEstado', parent=self, pos=wxPoint(284, 280),
              size=wxSize(144, 21), style=0, value=u'')
        self.edtEstado.Enable(False)

        self.labPais = wxStaticText(id=wxID_FRMCADCLIENTESLABPAIS,
              label=u'Pa\xeds de origem: ', name=u'labPais', parent=self,
              pos=wxPoint(8, 320), size=wxSize(77, 16), style=0)

        self.edtCodPais = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTCODPAIS,
              name=u'edtCodPais', parent=self, pos=wxPoint(8, 336),
              size=wxSize(78, 21), style=0,
              validator=TextValidator(TextValidator.FILTER_ALPHA), value=u'')
        self.edtCodPais.Enable(False)
        EVT_KILL_FOCUS(self.edtCodPais, self.OnEdtCodPais_Killfocus)

        self.edtPais = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTPAIS,
              name=u'edtPais', parent=self, pos=wxPoint(88, 336),
              size=wxSize(240, 21), style=0, value=u'')
        self.edtPais.Enable(False)

        self.btnPPais = wxButton(id=wxID_FRMCADCLIENTESBTNPPAIS, label=u'...',
              name=u'btnPPais', parent=self, pos=wxPoint(328, 336),
              size=wxSize(21, 21), style=0)
        self.btnPPais.Enable(False)
        EVT_BUTTON(self.btnPPais, self.btnPPais.GetId(), self.OnBtnPPaisClick)

        self.labProfissao = wxStaticText(id=wxID_FRMCADCLIENTESLABPROFISSAO,
              label=u'Profiss\xe3o: ', name=u'labProfissao', parent=self,
              pos=wxPoint(8, 360), size=wxSize(56, 13), style=0)

        self.edtCodProfissao = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTCODPROFISSAO,
              name=u'edtCodProfissao', parent=self, pos=wxPoint(8, 376),
              size=wxSize(78, 21), style=0, 
              validator=TextValidator(TextValidator.FILTER_NUMERIC), value=u'')
        self.edtCodProfissao.Enable(False)
        EVT_KILL_FOCUS(self.edtCodProfissao, self.OnEdtCodProfissao_Killfocus)

        self.edtProfissao = wxTextCtrl(id=wxID_FRMCADCLIENTESEDTPROFISSAO,
              name=u'edtProfissao', parent=self, pos=wxPoint(88, 376),
              size=wxSize(240, 21), style=0, value=u'')
        self.edtProfissao.Enable(False)

        self.btnPProfissao = wxButton(id=wxID_FRMCADCLIENTESBTNPPROFISSAO,
              label=u'...', name=u'btnPProfissao', parent=self, pos=wxPoint(328,
              376), size=wxSize(21, 21), style=0)
        self.btnPProfissao.Enable(False)
        EVT_BUTTON(self.btnPProfissao, self.btnPProfissao.GetId(),
              self.OnBtnPProfissaoClick)

        self.IniciaBotoes()
        self.btnPesquisar.SetDimensions(440, 8, 75, 25)
        self.btnAnterior.SetDimensions(440, 40, 75, 25)
        self.btnProximo.SetDimensions(440, 72, 75, 25)
        self.btnSalvar.SetDimensions(200, 408, 75, 25)
        self.btnExcluir.SetDimensions(280, 408, 75, 25)
        self.btnLimpar.SetDimensions(360, 408, 75, 25)
        self.btnFechar.SetDimensions(440, 408, 75, 25)
      
        self.FazLayout()
      
      	self.edtCodigo.SetMaxLength(14)
        self.edtDescricao.SetMaxLength(30)
        self.edtEmail.SetMaxLength(30)
        self.edtIdentidade.SetMaxLength(10)
        self.edtCodEndereco.SetMaxLength(10)
        self.edtTelefone.SetMaxLength(17)
        self.edtCodPais.SetMaxLength(3)
        self.edtCodProfissao.SetMaxLength(10)

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

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_3 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_4 = wxBoxSizer(wxVERTICAL)
      self.sizer_5 = wxBoxSizer(wxVERTICAL)
      self.sizer_16 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_23 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_22 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_19 = wxGridSizer(2, 1, 0, 0)
      self.sizer_15 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_21 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_20 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_18 = wxGridSizer(2, 1, 0, 0)
      self.sizer_11 = wxStaticBoxSizer(
        wxStaticBox(self, -1, "Endere\xe7o"), wxVERTICAL)
      self.sizer_14 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_17 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_16 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_15 = wxGridSizer(2, 1, 0, 0)
      self.sizer_13 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_14 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_13 = wxGridSizer(2, 1, 0, 0)
      self.sizer_12 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_10 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_12 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_11 = wxGridSizer(2, 1, 0, 0)
      self.sizer_6 = wxBoxSizer(wxHORIZONTAL)
      self.grid_sizer_5 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_4 = wxGridSizer(2, 1, 0, 0)
      self.sizer_8 = wxBoxSizer(wxHORIZONTAL)
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
      self.sizer_5.Add(self.sizer_8, 1, wxEXPAND, 0)
      self.grid_sizer_4.Add(self.labEmail, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_4.Add(self.edtEmail, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_4, 0, 0, 0)
      self.grid_sizer_5.Add(self.labIdentidade, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_5.Add(self.edtIdentidade, 0, 0, 0)
      self.sizer_6.Add(self.grid_sizer_5, 0, wxLEFT, 4)
      self.sizer_5.Add(self.sizer_6, 0, 0, 0)
      self.sizer_10.Add(self.rbSexo, 0, 0, 0)
      self.grid_sizer_11.Add(self.labTelefone, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_11.Add(self.edtTelefone, 0, 0, 0)
      self.sizer_10.Add(self.grid_sizer_11, 1, wxLEFT|wxEXPAND, 4)
      self.grid_sizer_12.Add(self.labDtNasc, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_12.Add(self.edtDtNasc, 0, 0, 0)
      self.sizer_10.Add(self.grid_sizer_12, 1, wxLEFT|wxEXPAND, 4)
      self.sizer_5.Add(self.sizer_10, 1, wxEXPAND, 0)
      self.sizer_12.Add(self.edtCodEndereco, 0, 0, 0)
      self.sizer_12.Add(self.btnPEndereco, 0, 0, 0)
      self.sizer_11.Add(self.sizer_12, 0, wxALL, 2)
      self.grid_sizer_13.Add(self.labLogradouro, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_13.Add(self.edtLogradouro, 0, 0, 0)
      self.sizer_13.Add(self.grid_sizer_13, 0, 0, 0)
      self.grid_sizer_14.Add(self.labBairro, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_14.Add(self.edtBairro, 0, 0, 0)
      self.sizer_13.Add(self.grid_sizer_14, 0, wxLEFT, 4)
      self.sizer_11.Add(self.sizer_13, 0, 0, 0)
      self.grid_sizer_15.Add(self.labCEP, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_15.Add(self.edtCEP, 0, 0, 0)
      self.sizer_14.Add(self.grid_sizer_15, 0, 0, 0)
      self.grid_sizer_16.Add(self.labCidade, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_16.Add(self.edtCidade, 0, 0, 0)
      self.sizer_14.Add(self.grid_sizer_16, 0, wxLEFT, 4)
      self.grid_sizer_17.Add(self.labEstado, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_17.Add(self.edtEstado, 0, 0, 0)
      self.sizer_14.Add(self.grid_sizer_17, 0, wxLEFT, 4)
      self.sizer_11.Add(self.sizer_14, 1, 0, 0)
      self.sizer_5.Add(self.sizer_11, 0, 0, 0)
      self.grid_sizer_18.Add(self.labPais, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_18.Add(self.edtCodPais, 0, 0, 0)
      self.sizer_15.Add(self.grid_sizer_18, 0, 0, 0)
      self.grid_sizer_20.Add(20, 20, 0, 0, 0)
      self.grid_sizer_20.Add(self.edtPais, 0, 0, 0)
      self.sizer_15.Add(self.grid_sizer_20, 0, wxLEFT, 2)
      self.grid_sizer_21.Add(20, 20, 0, 0, 0)
      self.grid_sizer_21.Add(self.btnPPais, 0, 0, 0)
      self.sizer_15.Add(self.grid_sizer_21, 0, 0, 0)
      self.sizer_5.Add(self.sizer_15, 0, 0, 0)
      self.grid_sizer_19.Add(self.labProfissao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_19.Add(self.edtCodProfissao, 0, 0, 0)
      self.sizer_16.Add(self.grid_sizer_19, 0, 0, 0)
      self.grid_sizer_22.Add(20, 20, 0, 0, 0)
      self.grid_sizer_22.Add(self.edtProfissao, 0, 0, 0)
      self.sizer_16.Add(self.grid_sizer_22, 0, wxLEFT, 2)
      self.grid_sizer_23.Add(20, 20, 0, 0, 0)
      self.grid_sizer_23.Add(self.btnPProfissao, 0, 0, 0)
      self.sizer_16.Add(self.grid_sizer_23, 0, 0, 0)
      self.sizer_5.Add(self.sizer_16, 0, 0, 0)
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

    def __init__(self, parent):
        self._init_ctrls(parent)

    def ValidaDados(self, bTodosDados):
      if RotinasGlobais.Rotinas.ValidaCampo(
        self.edtCodigo.GetValue(), Resource.STR_CPFNINF):
        return False
      if bTodosDados:
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtDescricao.GetValue(), Resource.STR_CLININF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtEmail.GetValue(), Resource.STR_EMAILNINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtTelefone.GetValue(), Resource.STR_TELNINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtCodEndereco.GetValue(), Resource.STR_ENDNINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtCodPais.GetValue(), Resource.STR_PAISNINF):
      		return False
    	  if RotinasGlobais.Rotinas.ValidaCampo(
          self.edtCodProfissao.GetValue(), Resource.STR_PROFNINF):
      		return False
      return True

    def OnBtnFecharClick(self, event):
      self.GetParent().Close(True)
    
    def OnBtnNovoClick(self, event):
      self.btnNovoClick()
      self.InformaLimpaDadosLocal(False)
      self.HabilitaDadosLocal(True)
      event.Skip()

    def OnBtnPesquisarClick(self, event):
      if self.PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S', 
        self.edtCodigo.GetValue(),"","","","","","","","",""), 
        Resource.STR_CLINENC):
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
      if self.rbSexo.GetSelection() == 0:
         self.sSexo = "M"
      else:
         self.sSexo = "F"
    
      self.sDtNasc = RotinasGlobais.Rotinas.ConverteDataHoraStr(
        self.edtDtNasc.GetValue(), True, '%Y/%m/%d', '')
    
      self.sSqlUpdate = ConsultasSQL.ConsSQL.Cliente('U', 
        self.edtCodigo.GetValue(), self.edtDescricao.GetValue(), 
        self.edtEmail.GetValue(),  self.edtIdentidade.GetValue(), self.sSexo,  
        self.edtTelefone.GetValue(), self.sDtNasc, 
        self.edtCodEndereco.GetValue(), 
        self.edtCodPais.GetValue(), self.edtCodProfissao.GetValue())
    
      self.sSqlInsert = ConsultasSQL.ConsSQL.Cliente('I', 
        self.edtCodigo.GetValue(), self.edtDescricao.GetValue(), 
        self.edtEmail.GetValue(),  self.edtIdentidade.GetValue(), self.sSexo,  
        self.edtTelefone.GetValue(), self.sDtNasc, 
        self.edtCodEndereco.GetValue(), 
        self.edtCodPais.GetValue(), self.edtCodProfissao.GetValue())

      if self.SalvarDados(self.ValidaDados(True),
        ConsultasSQL.ConsSQL.Cliente('S', self.edtCodigo.GetValue(),
        "","","","","","","","",""), self.sSqlUpdate, self.sSqlInsert, True):
        self.InformaLimpaDadosLocal(False)
        self.HabilitaDadosLocal(False)
      event.Skip()

    def OnBtnExcluirClick(self, event):
      if self.ExcluirDados(self.ValidaDados(False),
        ConsultasSQL.ConsSQL.Cliente('D', self.edtCodigo.GetValue(),
        "","","","","","","","","")):
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
        self.edtEmail.SetValue(self.lstRegistros.col[self.nLinhaRegistro][2])
        self.edtIdentidade.SetValue(self.lstRegistros.col[self.nLinhaRegistro][3])
        if self.lstRegistros.col[self.nLinhaRegistro][4] == "M":
          self.rbSexo.SetSelection(0)
        else:
          self.rbSexo.SetSelection(1)
        self.edtTelefone.SetValue(self.lstRegistros.col[self.nLinhaRegistro][5])
        self.edtDtNasc.SetValue(RotinasGlobais.Rotinas.substr(
          self.lstRegistros.col[self.nLinhaRegistro][6],1,10))
        self.edtCodEndereco.SetValue(self.lstRegistros.col[self.nLinhaRegistro][7])
        self.edtLogradouro.SetValue(self.lstRegistros.col[self.nLinhaRegistro][8])
        self.edtBairro.SetValue(self.lstRegistros.col[self.nLinhaRegistro][9])
        self.edtCEP.SetValue(self.lstRegistros.col[self.nLinhaRegistro][10])
        self.edtCidade.SetValue(self.lstRegistros.col[self.nLinhaRegistro][11])
        self.edtEstado.SetValue(self.lstRegistros.col[self.nLinhaRegistro][12])
        self.edtCodPais.SetValue(self.lstRegistros.col[self.nLinhaRegistro][13])
        self.edtPais.SetValue(self.lstRegistros.col[self.nLinhaRegistro][14])
        self.edtCodProfissao.SetValue(self.lstRegistros.col[self.nLinhaRegistro][15])
        self.edtProfissao.SetValue(self.lstRegistros.col[self.nLinhaRegistro][16])
      else:
        self.edtEmail.Clear()
        self.edtIdentidade.Clear()
        self.rbSexo.SetSelection(0)
        self.edtTelefone.Clear()
        self.edtDtNasc.Clear()
        self.edtCodEndereco.Clear()
        self.edtLogradouro.Clear()
        self.edtBairro.Clear()
        self.edtCEP.Clear()
        self.edtCidade.Clear()
        self.edtEstado.Clear()
        self.edtCodPais.Clear()
        self.edtPais.Clear()
        self.edtCodProfissao.Clear()
        self.edtProfissao.Clear()
        self.edtCodigo.SetFocus()

    def HabilitaDadosLocal(self, bHabilita):
      self.edtEmail.Enable(bHabilita)
      self.edtIdentidade.Enable(bHabilita)
      self.rbSexo.Enable(bHabilita)
      self.edtTelefone.Enable(bHabilita)
      self.edtDtNasc.Enable(bHabilita)
      self.edtCodEndereco.Enable(bHabilita)
      self.btnPEndereco.Enable(bHabilita)
      self.edtCodPais.Enable(bHabilita)
      self.btnPPais.Enable(bHabilita)
      self.edtCodProfissao.Enable(bHabilita)
      self.btnPProfissao.Enable(bHabilita)

    def OnEdtCodigo_Killfocus(self, event):
      if len(self.edtCodigo.GetValue()) > 0:
      	if RotinasGlobais.Rotinas.validaCPF(self.edtCodigo.GetValue())==False:
          wxMessageBox(Resource.STR_CPFINV, "Erro", wxOK | wxICON_ERROR)
          self.edtCodigo.Clear()
          self.edtCodigo.SetFocus()
      event.Skip()

    def OnEdtDtNasc_Killfocus(self, event):
      if len(self.edtDtNasc.GetValue()) > 0:
        if not RotinasGlobais.Rotinas.validaDataHora(
            self.edtDtNasc.GetValue(), True):
          wxMessageBox(Resource.STR_DTHRINV, "Erro", wxOK | wxICON_ERROR)
          self.edtDtNasc.SetValue(
            RotinasGlobais.Rotinas.retDataHoraStr(True,False))
          self.edtDtNasc.SetFocus()
      else:
        self.edtDtNasc.SetValue(
          RotinasGlobais.Rotinas.retDataHoraStr(True,False))
      event.Skip()

    def OnEdtCodEndereco_Killfocus(self, event):
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodEndereco.GetValue()) > 0:
        sLogradouro = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
        ConsultasSQL.ConsSQL.Endereco('S', self.edtCodEndereco.GetValue(),
        "","","","",""),Resource.STR_ENDNENC)
        if len(sLogradouro) > 0:
          self.edtLogradouro.SetValue(sLogradouro)
          self.edtBairro.SetValue(ConsCampo.col[0][2])
          self.edtCEP.SetValue(ConsCampo.col[0][3])
          self.edtCidade.SetValue(ConsCampo.col[0][4])
          self.edtEstado.SetValue(ConsCampo.col[0][5])
        else:
      	  self.edtCodEnd.SetFocus()
          self.edtLogradouro.Clear()
          self.edtBairro.Clear()
          self.edtCEP.Clear()
      	  self.edtCidade.Clear()
      	  self.edtEstado.Clear()
      else:
        self.edtLogradouro.Clear()
        self.edtBairro.Clear()
        self.edtCEP.Clear()
        self.edtCidade.Clear()
        self.edtEstado.Clear()
      event.Skip()

    def OnEdtCodPais_Killfocus(self, event):
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodPais.GetValue()) > 0:
        sPais = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Pais('S',
          self.edtCodPais.GetValue(),""),Resource.STR_PAISNENC)    
        if len(sPais) > 0:
          self.edtPais.SetValue(sPais)
        else:
          self.edtCodPais.Clear()
          self.edtCodPais.SetFocus()
      else:
        self.edtPais.Clear()
      event.Skip()

    def OnEdtCodProfissao_Killfocus(self, event):
      ConsCampo = LISTAMSTR()
    
      if len(self.edtCodProfissao.GetValue()) > 0:
        sProfissao = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Profissao('S',
          self.edtCodProfissao.GetValue(),""),Resource.STR_PROFNENC)    
        if len(sProfissao) > 0:
          self.edtProfissao.SetValue(sProfissao)
        else:
          self.edtCodProfissao.Clear()
          self.edtCodProfissao.SetFocus()
      else:
        self.edtProfissao.Clear()
      event.Skip()

    def OnBtnPEnderecoClick(self, event):
      fConEnderecos = ConEnderecos.create(self)
      fConEnderecos.ShowModal()
      self.edtCodEndereco.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodEndereco_Killfocus(event)
      event.Skip()

    def OnBtnPPaisClick(self, event):
      fConPaises = ConPaises.create(self)
      fConPaises.ShowModal()
      self.edtCodPais.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodPais_Killfocus(event)
      event.Skip()

    def OnBtnPProfissaoClick(self, event):
      fConProfissoes = ConProfissoes.create(self)
      fConProfissoes.ShowModal()
      self.edtCodProfissao.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado)
      self.OnEdtCodProfissao_Killfocus(event)
      event.Skip()

