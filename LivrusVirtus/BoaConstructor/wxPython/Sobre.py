#Boa:Dialog:frmSobre

from wxPython.wx import *
from resource import Resource

def create(parent):
    return frmSobre(parent)

[wxID_FRMSOBRE, wxID_FRMSOBREBTNOK, wxID_FRMSOBRELABBMP, 
 wxID_FRMSOBRELABDIREITOS, wxID_FRMSOBRELABSISTEMA, wxID_FRMSOBRELABVERSAO, 
 wxID_FRMSOBRESTATICBOX1, 
] = map(lambda _init_ctrls: wxNewId(), range(7))

class frmSobre(wxDialog):
    def _init_utils(self):
        # generated method, don't edit
        pass

    def _init_ctrls(self, prnt):
        # generated method, don't edit
        wxDialog.__init__(self, id=wxID_FRMSOBRE, name=u'frmSobre', parent=prnt,
              pos=wxPoint(498, 310), size=wxSize(306, 240),
              style=wxDEFAULT_DIALOG_STYLE, title=u'Sobre o Sistema')
        self._init_utils()
        self.SetIcon(wxIcon(Resource.ICO_LIVRUS, wxBITMAP_TYPE_ICO))
        self.SetClientSize(wxSize(298, 213))
        self.Centre(wxBOTH)
        self.SetModal(True)

        self.btnOk = wxButton(id=wxID_FRMSOBREBTNOK, label=u'&Ok',
              name=u'btnOk', parent=self, pos=wxPoint(111, 180), size=wxSize(75,
              25), style=0)
        EVT_BUTTON(self.btnOk, wxID_FRMSOBREBTNOK, self.OnBtnokButton)

        self.labVersao = wxStaticText(id=wxID_FRMSOBRELABVERSAO,
              label=u'Vers\xe3o: 1.0.0', name=u'labVersao', parent=self,
              pos=wxPoint(200, 96), size=wxSize(63, 13), style=0)

        self.labBmp = wxStaticBitmap(bitmap=wxBitmap(u'LivrusVirtus.bmp',
              wxBITMAP_TYPE_BMP), id=wxID_FRMSOBRELABBMP, name=u'labBmp',
              parent=self, pos=wxPoint(24, 20), size=wxSize(254, 72),
              style=wxTRANSPARENT_WINDOW)

        #self.staticBox1 = wxStaticBox(id=wxID_FRMSOBRESTATICBOX1, label=u'',
        #      name='staticBox1', parent=self, pos=wxPoint(8, 5),
        #      size=wxSize(285, 163), style=0)

        self.labDireitos = wxStaticText(id=wxID_FRMSOBRELABDIREITOS,
              label=u'Todos os diretos reservados para: Henrique F. de Souza',
              name=u'labDireitos', parent=self, pos=wxPoint(16, 112),
              size=wxSize(266, 13), style=0)

        self.labSistema = wxStaticText(id=wxID_FRMSOBRELABSISTEMA,
              label=u'Sistema integrante do projeto Livrus Virtus, '\
                u'vers\xe3o programada no Boa Constructor em wxPython.',
              name=u'labSistema', parent=self, pos=wxPoint(16, 131),
              size=wxSize(264, 29), style=wxALIGN_CENTRE)

    def FazLayout(self):
        self.sizer_1 = wxBoxSizer(wxVERTICAL)
        self.sizer_2 = wxStaticBoxSizer(wxStaticBox(self, -1, ""), wxVERTICAL)
        self.sizer_2.Add(self.labBmp, 0, wxALIGN_CENTER_HORIZONTAL, 0)
        self.sizer_2.Add(self.labVersao, 0, wxALL|wxALIGN_RIGHT, 2)
        self.sizer_2.Add(self.labDireitos, 0, wxALL, 2)
        self.sizer_2.Add(self.labSistema, 0, 
          wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2)
        self.sizer_1.Add(self.sizer_2, 1, wxALL|wxEXPAND, 6)
        self.sizer_1.Add(self.btnOk, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4)
        self.SetAutoLayout(True)
        self.SetSizer(self.sizer_1)
        self.sizer_1.Fit(self)
        self.sizer_1.SetSizeHints(self)
        self.Layout()
        self.Centre()

    def __init__(self, parent):
        self._init_ctrls(parent)
        self.FazLayout()

    def OnBtnokButton(self, event):
        self.EndModal(wxID_OK)
               
