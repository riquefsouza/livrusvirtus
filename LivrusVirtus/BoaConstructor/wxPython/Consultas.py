#Boa:Dialog:frmConsultas

from wxPython.wx import *
from wxPython.grid import *
from RotinasGlobais import RotinasGlobais
from resource import Resource
from ListaStr import LISTAMSTR
import Principal

def create(parent):
    return frmConsultas(parent)

[wxID_FRMCONSULTAS, wxID_FRMCONSULTASBTNFECHAR, wxID_FRMCONSULTASBTNLIMPAR, 
 wxID_FRMCONSULTASBTNPESQUISAR, wxID_FRMCONSULTASEDTDESCRICAO, 
 wxID_FRMCONSULTASGRIDCONSULTA, wxID_FRMCONSULTASLABDESCRICAO, 
 wxID_FRMCONSULTASLABREGISTRO, wxID_FRMCONSULTASPANEL1, 
 wxID_FRMCONSULTASPANEL2, wxID_FRMCONSULTASSCROLLEDWINDOW1, 
] = map(lambda _init_ctrls: wxNewId(), range(11))

class frmConsultas(wxDialog):
    lstLinhas = LISTAMSTR()
    sSelecionado = ''
    nRegistro = 0

    def _init_ctrls(self, prnt):
        wxDialog.__init__(self, id=wxID_FRMCONSULTAS, name=u'frmConsultas',
              parent=prnt, pos=wxPoint(0, 0), size=wxSize(355, 263),
              style=wxDEFAULT_DIALOG_STYLE | wxCAPTION | wxRESIZE_BORDER | 
              wxMINIMIZE_BOX | wxMAXIMIZE_BOX, title=u'Consulta de ')
        self.SetIcon(wxIcon(Resource.ICO_LIVRUS, wxBITMAP_TYPE_ICO))
        self.SetClientSize(wxSize(355, 263))
        self.Centre(wxBOTH)
        EVT_CLOSE(self, self.OnFrmConsultasClose)

        self.labDescricao = wxStaticText(id=wxID_FRMCONSULTASLABDESCRICAO,
              label=u'Descri\xe7\xe3o:', name=u'labDescricao',
              parent=self, pos=wxPoint(8, 8), size=wxSize(51, 13),
              style=0)

        self.edtDescricao = wxTextCtrl(id=wxID_FRMCONSULTASEDTDESCRICAO,
              name=u'edtDescricao', parent=self, pos=wxPoint(8, 24),
              size=wxSize(257, 21), style=0, value=u'')

        self.btnPesquisar = wxButton(id=wxID_FRMCONSULTASBTNPESQUISAR,
              label=u'&Pesquisar', name=u'btnPesquisar', parent=self,
              pos=wxPoint(272, 24), size=wxSize(75, 25), style=0)

        self.gridConsulta = wxGrid(id=wxID_FRMCONSULTASGRIDCONSULTA,
              name='gridConsulta', parent=self, pos=wxPoint(0, 56), 
              size=wxSize(355, 125), style=wxSUNKEN_BORDER)
        self.gridConsulta.CreateGrid(1, 2, wxGrid.wxGridSelectRows)
        self.gridConsulta.SetColLabelValue(0, u'C\xf3digo')
        self.gridConsulta.SetColSize(0, 80)
        self.gridConsulta.SetColLabelValue(1, u'Descri\xe7\xe3o')
        self.gridConsulta.SetColSize(1, 180)
        self.gridConsulta.EnableEditing(false)
        self.gridConsulta.HideCellEditControl()
        self.gridConsulta.SetColLabelSize(21)

        self.labRegistro = wxStaticText(id=wxID_FRMCONSULTASLABREGISTRO,
              label=u'Registro 0 de 0', name=u'labRegistro', parent=self,
              pos=wxPoint(8, 16), size=wxSize(144, 13), style=0)

        self.btnLimpar = wxButton(id=wxID_FRMCONSULTASBTNLIMPAR,
              label=u'&Limpar', name=u'btnLimpar', parent=self,
              pos=wxPoint(188, 13), size=wxSize(75, 25), style=0)

        self.btnFechar = wxButton(id=wxID_FRMCONSULTASBTNFECHAR,
              label=u'&Fechar', name=u'btnFechar', parent=self,
              pos=wxPoint(268, 13), size=wxSize(75, 25), style=0)
        EVT_BUTTON(self.btnFechar, wxID_FRMCONSULTASBTNFECHAR,
              self.OnBtnFecharClick)

        self.FazLayout()
      
        self.edtDescricao.SetFocus()
        self.nRegistro = 0

    def __init__(self, parent):
        self._init_ctrls(parent)

    def FazLayout(self):
      self.sizer_1 = wxBoxSizer(wxVERTICAL)
      self.gird_sizer_2 = wxGridSizer(1, 2, 0, 0)
      self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_3 = wxBoxSizer(wxHORIZONTAL)
      self.sizer_4 = wxBoxSizer(wxVERTICAL)
      self.grid_sizer_1 = wxGridSizer(2, 1, 0, 0)
      self.grid_sizer_1.Add(self.labDescricao, 0, wxALIGN_BOTTOM, 0)
      self.grid_sizer_1.Add(self.edtDescricao, 0, 0, 0)
      self.sizer_3.Add(self.grid_sizer_1, 0, wxALL, 2)
      self.sizer_4.Add(20, 20, 0, 0, 0)
      self.sizer_4.Add(self.btnPesquisar, 0, wxLEFT|wxTOP|wxBOTTOM, 5)
      self.sizer_3.Add(self.sizer_4, 0, 0, 0)
      self.sizer_1.Add(self.sizer_3, 0, wxALL, 4)
      self.sizer_1.Add(self.gridConsulta, 1, wxEXPAND, 0)
      self.gird_sizer_2.Add(self.labRegistro, 0, wxALL, 10)
      self.sizer_2.Add(self.btnLimpar, 0, wxALIGN_RIGHT|wxALIGN_BOTTOM, 8)
      self.sizer_2.Add(self.btnFechar, 0, 
        wxLEFT|wxALIGN_RIGHT|wxALIGN_BOTTOM, 8)
      self.gird_sizer_2.Add(self.sizer_2, 1, 
        wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 4)
      self.sizer_1.Add(self.gird_sizer_2, 0, wxALL|wxEXPAND|wxALIGN_BOTTOM, 0)
      self.SetAutoLayout(true)
      self.SetSizer(self.sizer_1)
      self.sizer_1.Fit(self)
      self.sizer_1.SetSizeHints(self)
      self.Layout()

    def OnBtnFecharClick(self, event):
        self.Close(True)

    def OnFrmConsultasClose(self, event):
        self.Destroy()

    def Fecha(self, nIndMenu):
      if len(self.sSelecionado) > 0:
        RotinasGlobais.Rotinas.sCodigoSelecionado = self.sSelecionado
      else:
        RotinasGlobais.Rotinas.sCodigoSelecionado = ""
    
      if nIndMenu == 0:
        if self.IsModal():
          self.EndModal(True)
        else:
          self.Close()
      else:
        Principal.fPrincipal.BarraDeMenu.GetMenu(1).Enable(nIndMenu, True)

    def LimparDados(self):
      self.labRegistro.SetLabel("Registro 0 de 0")
      self.gridConsulta.ClearGrid()
      self.gridConsulta.DeleteRows(0, self.gridConsulta.GetNumberRows()-1, True)
      self.edtDescricao.Clear()
      self.edtDescricao.SetFocus()

    def PesquisarDados(self, sTextoSql, sMensagemErro, nQtdCol):
      Rotinas = RotinasGlobais.Rotinas
      if Rotinas.ConsultaDadosLista(
        Rotinas.gConexao, self.lstLinhas, sTextoSql):
        Rotinas.AdicionaLinhasGrid(self.gridConsulta, self.lstLinhas, nQtdCol)
      else:
        wxMessageBox(sMensagemErro, "Erro", wxOK | wxICON_ERROR)

    def setLabRegistros(self, nLinha):
      if nLinha >= 0:
        self.labRegistro.SetLabel("Registro " + str(nLinha+1) + " de " +\
          str(self.gridConsulta.GetNumberRows()))
        self.sSelecionado = self.gridConsulta.GetCellValue(nLinha, 0)

