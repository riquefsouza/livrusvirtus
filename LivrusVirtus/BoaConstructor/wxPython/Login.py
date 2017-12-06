#Boa:Dialog:frmLogin

from wxPython.wx import *
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
from resource import Resource

import Livrus
import Principal

def create(parent):
    return frmLogin(parent)

[wxID_FRMLOGIN, wxID_FRMLOGINBMPLOGIN, wxID_FRMLOGINBTNCANCELAR, 
 wxID_FRMLOGINBTNLOGIN, wxID_FRMLOGINEDTLOGIN, wxID_FRMLOGINEDTSENHA, 
 wxID_FRMLOGINLABLOGIN, wxID_FRMLOGINLABSENHA, 
] = map(lambda _init_ctrls: wxNewId(), range(8))

class frmLogin(wxDialog):
    def _init_utils(self):
        # generated method, don't edit
        pass

    def _init_ctrls(self, prnt):
        # generated method, don't edit
        wxDialog.__init__(self, id=wxID_FRMLOGIN, name=u'frmLogin', parent=prnt,
              pos=wxPoint(546, 346), size=wxSize(211, 168),
              style=wxDEFAULT_DIALOG_STYLE, title=u'Login do Sistema')
        self._init_utils()
        self.SetIcon(wxIcon(Resource.ICO_LIVRUS, wxBITMAP_TYPE_ICO))
        self.SetClientSize(wxSize(203, 141))
        self.Centre(wxBOTH)
        self.SetBackgroundColour(wxColour(212,208,200))
        EVT_CLOSE(self, self.OnFrmloginClose)

        self.bmpLogin = wxStaticBitmap(bitmap=wxBitmap(u'C:/LivrusVirtus/BoaConstructor/wxPython/Login.bmp',
              wxBITMAP_TYPE_BMP), id=wxID_FRMLOGINBMPLOGIN, name=u'bmpLogin',
              parent=self, pos=wxPoint(8, 8), size=wxSize(88, 90), style=0)

        self.labLogin = wxStaticText(id=wxID_FRMLOGINLABLOGIN, label=u'Login:',
              name=u'labLogin', parent=self, pos=wxPoint(112, 8),
              size=wxSize(29, 13), style=0)

        self.edtLogin = wxTextCtrl(id=wxID_FRMLOGINEDTLOGIN, name=u'edtLogin',
              parent=self, pos=wxPoint(112, 24), size=wxSize(80, 21), style=0,
              value=u'')
        self.edtLogin.SetMaxLength(10)
        self.labSenha = wxStaticText(id=wxID_FRMLOGINLABSENHA, label=u'Senha:',
              name=u'labSenha', parent=self, pos=wxPoint(112, 56),
              size=wxSize(34, 13), style=0)

        self.edtSenha = wxTextCtrl(id=wxID_FRMLOGINEDTSENHA, name=u'edtSenha',
              parent=self, pos=wxPoint(112, 72), size=wxSize(80, 21),
              style=wxTE_PASSWORD, value=u'')
        self.edtSenha.SetMaxLength(10)
        self.btnLogin = wxButton(id=wxID_FRMLOGINBTNLOGIN, label=u'&Login',
              name=u'btnLogin', parent=self, pos=wxPoint(24, 107),
              size=wxSize(75, 25), style=0)
        EVT_BUTTON(self.btnLogin, wxID_FRMLOGINBTNLOGIN, self.OnBtnloginButton)

        self.btnCancelar = wxButton(id=wxID_FRMLOGINBTNCANCELAR,
              label=u'&Cancelar', name=u'btnCancelar', parent=self,
              pos=wxPoint(112, 107), size=wxSize(75, 25), style=0)
        EVT_BUTTON(self.btnCancelar, wxID_FRMLOGINBTNCANCELAR,
              self.OnBtncancelarButton)

    def FazLayout(self):
        self.sizer_1 = wxBoxSizer(wxVERTICAL)
        self.sizer_4 = wxBoxSizer(wxHORIZONTAL)
        self.sizer_2 = wxBoxSizer(wxHORIZONTAL)
        self.sizer_3 = wxBoxSizer(wxVERTICAL)
        self.sizer_2.Add(self.bmpLogin, 0, wxALL, 6)
        self.sizer_3.Add(self.labLogin, 0, wxALL, 2)
        self.sizer_3.Add(self.edtLogin, 0, wxALL, 2)
        self.sizer_3.Add(self.labSenha, 0, wxALL, 2)
        self.sizer_3.Add(self.edtSenha, 0, wxALL, 2)
        self.sizer_2.Add(self.sizer_3, 0, wxALL, 6)
        self.sizer_1.Add(self.sizer_2, 0, 0, 3)
        self.sizer_4.Add(self.btnLogin, 0, wxLEFT|wxTOP|wxBOTTOM|wxALIGN_BOTTOM, 10)
        self.sizer_4.Add(self.btnCancelar, 0, wxALL|wxALIGN_BOTTOM, 10)
        self.sizer_1.Add(self.sizer_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 1)
        self.SetAutoLayout(True)
        self.SetSizer(self.sizer_1)
        self.sizer_1.Fit(self)
        self.sizer_1.SetSizeHints(self)
        self.Layout()

    def __init__(self, parent):
        self.bFechar = False;
        self._init_ctrls(parent)
        self.FazLayout()

    def OnBtnloginButton(self, event):
        Rotinas = RotinasGlobais.Rotinas
        ConsSQL = ConsultasSQL.ConsSQL
        Rotinas.sUsuarioLogin = self.edtLogin.GetValue()
        Rotinas.sUsuarioSenha = self.edtSenha.GetValue()
        gConexao = ''
        if Rotinas.ConsultaDados(Rotinas.gConexao, ConsSQL.Usuario('S',
           Rotinas.sUsuarioLogin, Rotinas.sUsuarioSenha)):
          Rotinas.sBarraLogin = Resource.STR_USUARIO + Rotinas.sUsuarioLogin
          Principal.fPrincipal.SetStatusText(Rotinas.sBarraLogin, 0)
      
          self.bFechar = False
          self.Close()
          Principal.fPrincipal.Show(True)           
        else:
          wxMessageBox(Resource.STR_LOGSENINC, "Erro", wxOK | wxICON_ERROR)

        event.Skip()
    def OnBtncancelarButton(self, event):
        self.bFechar=True
        self.Close()        event.Skip()

    def OnFrmloginClose(self, event):
        if self.bFechar:          Principal.fPrincipal.Destroy()
        self.Destroy()        

