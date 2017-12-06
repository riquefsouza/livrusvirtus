# generated by wxGlade 0.3.1 on Mon Dec 27 07:02:32 2004

from wxPython.wx import *

# begin wxGlade: dependencies
# end wxGlade

class frmLogin(wxDialog):
    def __init__(self, *args, **kwds):
        # begin wxGlade: frmLogin.__init__
        kwds["style"] = wxDEFAULT_DIALOG_STYLE
        wxDialog.__init__(self, *args, **kwds)
        self.bmpLogin = wxStaticBitmap(self, ID_FRMLOGIN_BMPLOGIN, wxBitmap("C:\\LivrusVirtus\\VCPP6\\wxWin\\wxODBC\\xpms\\login.xpm", wxBITMAP_TYPE_ANY))
        self.labLogin = wxStaticText(self, ID_FRMLOGIN_LABLOGIN, "Login:")
        self.edtLogin = wxTextCtrl(self, ID_FRMLOGIN_EDTLOGIN, "")
        self.labSenha = wxStaticText(self, ID_FRMLOGIN_LABSENHA, "Senha:")
        self.edtSenha = wxTextCtrl(self, ID_FRMLOGIN_EDTSENHA, "")
        self.btnLogin = wxButton(self, ID_FRMLOGIN_BTNLOGIN, "&Login")
        self.btnCancelar = wxButton(self, ID_FRMLOGIN_BTNCANCELAR, "&Cancelar")

        self.__set_properties()
        self.__do_layout()
        # end wxGlade

    def __set_properties(self):
        # begin wxGlade: frmLogin.__set_properties
        self.SetTitle("Login do Sistema")
        self.edtLogin.SetSize((80, 21))
        self.edtSenha.SetSize((80, 21))
        self.btnLogin.SetSize((75, 25))
        self.btnLogin.SetDefault()
        self.btnCancelar.SetSize((75, 25))
        # end wxGlade

    def __do_layout(self):
        # begin wxGlade: frmLogin.__do_layout
        sizer_1 = wxBoxSizer(wxVERTICAL)
        sizer_4 = wxBoxSizer(wxHORIZONTAL)
        sizer_2 = wxBoxSizer(wxHORIZONTAL)
        sizer_3 = wxBoxSizer(wxVERTICAL)
        sizer_2.Add(self.bmpLogin, 0, wxALL, 6)
        sizer_3.Add(self.labLogin, 0, wxALL|wxALIGN_BOTTOM, 2)
        sizer_3.Add(self.edtLogin, 0, wxALL, 2)
        sizer_3.Add(self.labSenha, 0, wxALL|wxALIGN_BOTTOM, 2)
        sizer_3.Add(self.edtSenha, 0, wxALL, 2)
        sizer_2.Add(sizer_3, 0, wxALL, 6)
        sizer_1.Add(sizer_2, 0, 0, 3)
        sizer_4.Add(self.btnLogin, 0, wxLEFT|wxTOP|wxBOTTOM|wxALIGN_BOTTOM, 10)
        sizer_4.Add(self.btnCancelar, 0, wxALL|wxALIGN_BOTTOM, 10)
        sizer_1.Add(sizer_4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 1)
        self.SetAutoLayout(1)
        self.SetSizer(sizer_1)
        sizer_1.Fit(self)
        sizer_1.SetSizeHints(self)
        self.Layout()
        self.Centre()
        # end wxGlade

# end of class frmLogin


