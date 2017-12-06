#Boa:FramePanel:frmAlterarSenha

from wxPython.wx import *
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
from resource import Resource

[wxID_FRMALTERARSENHA, wxID_FRMALTERARSENHABTNFECHAR, 
 wxID_FRMALTERARSENHABTNLIMPAR, wxID_FRMALTERARSENHABTNSALVAR, 
 wxID_FRMALTERARSENHAEDTCONFIRMARSENHA, wxID_FRMALTERARSENHAEDTLOGIN, 
 wxID_FRMALTERARSENHAEDTNOVASENHA, wxID_FRMALTERARSENHAEDTSENHAATUAL, 
 wxID_FRMALTERARSENHALABCONFIRMARSENHA, wxID_FRMALTERARSENHALABLOGIN, 
 wxID_FRMALTERARSENHALABNOVASENHA, wxID_FRMALTERARSENHALABSENHAATUAL, 
] = map(lambda _init_ctrls: wxNewId(), range(12))

def create(parent):
    return frmAlterarSenha(parent)

class frmAlterarSenha(wxPanel):
    def _init_ctrls(self, prnt):
        # generated method, don't edit
        wxPanel.__init__(self, id=wxID_FRMALTERARSENHA, name=u'frmAlterarSenha',
              parent=prnt, pos=wxPoint(424, 292), size=wxSize(257, 161),
              style=wxTAB_TRAVERSAL)
        self.SetClientSize(wxSize(249, 134))
        EVT_CLOSE(self, self.OnFrmalterarsenhaClose)

        self.labLogin = wxStaticText(id=wxID_FRMALTERARSENHALABLOGIN,
              label=u'Login:', name=u'labLogin', parent=self, pos=wxPoint(8, 8),
              size=wxSize(29, 13), style=0)

        self.edtLogin = wxTextCtrl(id=wxID_FRMALTERARSENHAEDTLOGIN,
              name=u'edtLogin', parent=self, pos=wxPoint(8, 24),
              size=wxSize(100, 21), style=0, value=u'')
        self.edtLogin.Enable(False)

        self.labSenhaAtual = wxStaticText(id=wxID_FRMALTERARSENHALABSENHAATUAL,
              label=u'Senha atual:', name=u'labSenhaAtual', parent=self,
              pos=wxPoint(112, 8), size=wxSize(60, 13), style=0)

        self.edtSenhaAtual = wxTextCtrl(id=wxID_FRMALTERARSENHAEDTSENHAATUAL,
              name=u'edtSenhaAtual', parent=self, pos=wxPoint(112, 24),
              size=wxSize(100, 21), style=wxTE_PASSWORD, value=u'')

        self.labNovaSenha = wxStaticText(id=wxID_FRMALTERARSENHALABNOVASENHA,
              label=u'Nova senha:', name=u'labNovaSenha', parent=self,
              pos=wxPoint(8, 48), size=wxSize(61, 13), style=0)

        self.edtNovaSenha = wxTextCtrl(id=wxID_FRMALTERARSENHAEDTNOVASENHA,
              name=u'edtNovaSenha', parent=self, pos=wxPoint(8, 64),
              size=wxSize(100, 21), style=wxTE_PASSWORD, value=u'')

        self.labConfirmarSenha = wxStaticText(id=wxID_FRMALTERARSENHALABCONFIRMARSENHA,
              label=u'Confirmar senha:', name=u'labConfirmarSenha', parent=self,
              pos=wxPoint(112, 48), size=wxSize(79, 13), style=0)

        self.edtConfirmarSenha = wxTextCtrl(id=wxID_FRMALTERARSENHAEDTCONFIRMARSENHA,
              name=u'edtConfirmarSenha', parent=self, pos=wxPoint(112, 64),
              size=wxSize(100, 21), style=wxTE_PASSWORD, value=u'')

        self.btnSalvar = wxButton(id=wxID_FRMALTERARSENHABTNSALVAR,
              label=u'&Salvar', name=u'btnSalvar', parent=self, pos=wxPoint(8,
              104), size=wxSize(75, 23), style=0)
        EVT_BUTTON(self.btnSalvar, wxID_FRMALTERARSENHABTNSALVAR,
              self.OnBtnsalvarButton)

        self.btnLimpar = wxButton(id=wxID_FRMALTERARSENHABTNLIMPAR,
              label=u'&Limpar', name=u'btnLimpar', parent=self, pos=wxPoint(88,
              104), size=wxSize(75, 23), style=0)
        EVT_BUTTON(self.btnLimpar, wxID_FRMALTERARSENHABTNLIMPAR,
              self.OnBtnlimparButton)

        self.btnFechar = wxButton(id=wxID_FRMALTERARSENHABTNFECHAR,
              label=u'&Fechar', name=u'btnFechar', parent=self, pos=wxPoint(168,
              104), size=wxSize(75, 23), style=0)
        EVT_BUTTON(self.btnFechar, wxID_FRMALTERARSENHABTNFECHAR,
              self.OnBtnfecharButton)

        self.edtLogin.SetValue(RotinasGlobais.Rotinas.sUsuarioLogin)
        self.edtSenhaAtual.SetMaxLength(10)
        self.edtNovaSenha.SetMaxLength(10)
        self.edtConfirmarSenha.SetMaxLength(10)
        self.edtSenhaAtual.SetFocus()

    def FazLayout(self):
        self.sizer_1 = wxBoxSizer(wxVERTICAL);
        self.sizer_2 = wxBoxSizer(wxHORIZONTAL);
        self.sizer_9 = wxBoxSizer(wxHORIZONTAL);
        self.grid_sizer_10 = wxGridSizer(4, 1, 0, 0);
        self.grid_sizer_3 = wxGridSizer(4, 1, 0, 0);
        self.grid_sizer_3.Add(self.labLogin, 0, wxLEFT|wxALIGN_BOTTOM, 8);
        self.grid_sizer_3.Add(self.edtLogin, 0, wxLEFT, 8);
        self.grid_sizer_3.Add(self.labNovaSenha, 0, wxLEFT|wxALIGN_BOTTOM, 8);
        self.grid_sizer_3.Add(self.edtNovaSenha, 0, wxLEFT, 8);
        self.sizer_9.Add(self.grid_sizer_3, 0, 0, 0);
        self.grid_sizer_10.Add(self.labSenhaAtual, 0, 
          wxLEFT|wxALIGN_BOTTOM, 4);
        self.grid_sizer_10.Add(self.edtSenhaAtual, 0, wxLEFT, 4);
        self.grid_sizer_10.Add(self.labConfirmarSenha, 0, 
          wxLEFT|wxALIGN_BOTTOM, 4);
        self.grid_sizer_10.Add(self.edtConfirmarSenha, 0, wxLEFT, 4);
        self.sizer_9.Add(self.grid_sizer_10, 0, 0, 0);
        self.sizer_1.Add(self.sizer_9, 1, 0, 0);
        self.sizer_2.Add(self.btnSalvar, 0, wxALL, 2);
        self.sizer_2.Add(self.btnLimpar, 0, wxALL, 2);
        self.sizer_2.Add(self.btnFechar, 0, wxALL, 2);
        self.sizer_1.Add(self.sizer_2, 0, wxALL, 4);
        self.SetAutoLayout(True);
        self.SetSizer(self.sizer_1);
        self.sizer_1.Fit(self);
        self.sizer_1.SetSizeHints(self);

    def __init__(self, parent):
        self._init_ctrls(parent)
        self.FazLayout()

    def OnBtnsalvarButton(self, event):        
      if self.ValidaDados():
        Rotinas = RotinasGlobais.Rotinas
        ConsSQL = ConsultasSQL.ConsSQL
        if Rotinas.AtualizaDados(gConexao, ConsSQL.Usuario('U', 
          self.edtLogin.GetValue(), self.edtConfirmarSenha.GetValue())):
          wxMessageBox(Resource.STR_SENALTSUC, "Erro", wxOK | wxICON_ERROR)
      event.Skip()

    def OnBtnlimparButton(self, event):
      self.edtSenhaAtual.Clear()
      self.edtNovaSenha.Clear()
      self.edtConfirmarSenha.Clear()
      self.edtSenhaAtual.SetFocus()
      event.Skip()

    def OnBtnfecharButton(self, event):
        self.GetParent().Close(True)

    def OnFrmalterarsenhaClose(self, event):
        self.Destroy()

    def ValidaDados(self):
      Rotinas = RotinasGlobais.Rotinas
      if self.edtSenhaAtual.GetValue() != Rotinas.sUsuarioSenha:
        wxMessageBox(Resource.STR_SENNCSU, "Erro", wxOK | wxICON_ERROR)
        return False
      if Rotinas.ValidaCampo(self.edtNovaSenha.GetValue(),
         Resource.STR_NSENNINF):
        return False
      if self.edtNovaSenha.GetValue() != self.edtConfirmarSenha.GetValue():
        wxMessageBox(Resource.STR_NSENNCCON, "Erro", wxOK | wxICON_ERROR)
        return False
      return True


