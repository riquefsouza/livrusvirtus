from FXPy.fox import *
from RotinasGlobais import RotinasGlobais
import Login

def create(parent):
  return frmSplash(parent)

class frmSplash(FXDialogBox):
  ID_FRMSPLASH_TIMER = 100
  mTimer = None

  def __init__(self, owner):
    FXDialogBox.__init__(self,owner,"Splash", DECOR_NONE,
      0, 0, 0, 0, 0, 0, 0, 0, 4, 4)

    FXMAPFUNC(self,SEL_TIMEOUT, frmSplash.ID_FRMSPLASH_TIMER, frmSplash.onTimer)

    Rotinas = RotinasGlobais.Rotinas
    bmpLivrusVirtus = Rotinas.lerFigura(self.getApp(), "livrusvirtus.bmp")
    FXLabel(self, "", bmpLivrusVirtus, LAYOUT_CENTER_X)

  def create(self):
    FXDialogBox.create(self) 

  def iniciaTimer(self):
    self.mTimer = self.getApp().addTimeout(1000, self, frmSplash.ID_FRMSPLASH_TIMER)
  
  def onTimer(self, sender, sel, ptr):
    self.mTimer = None
    Login.fLogin.show(PLACEMENT_SCREEN)
    self.destroy()
    return True
