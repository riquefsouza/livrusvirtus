#Boa:SplashScreen:frmSplash

from wxPython.wx import *

import Login

def create(parent):
    return frmSplash(parent)

[wxID_FRMSPLASH] = map(lambda _init_ctrls: wxNewId(), range(1))

class frmSplash(wxSplashScreen):
    def _init_utils(self):
        pass
    
    def _init_ctrls(self, prnt):
        wxSplashScreen.__init__(self, bitmap=wxBitmap(u'LivrusVirtus.bmp',
          wxBITMAP_TYPE_BMP), splashStyle=wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT,
          milliseconds=1000, parent=prnt, id=wxID_FRMSPLASH, 
          pos=wxDefaultPosition, size=wxDefaultSize,
          style=wxSIMPLE_BORDER | wxSTAY_ON_TOP)
        EVT_CLOSE(self, self.OnFrmsplashClose)
        
    def __init__(self, parent):
        self._init_ctrls(parent)

    def OnFrmsplashClose(self, event):        
        fLogin = Login.create(None)
        fLogin.Show()
        event.Skip()
