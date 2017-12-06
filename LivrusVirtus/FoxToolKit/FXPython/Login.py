from FXPy.fox import *
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
from resource import Resource

import Livrus
import Principal

def create(parent):
    return frmLogin(parent)

class frmLogin(FXDialogBox):
  [ID_FRMLOGIN_BTNLOGIN, ID_FRMLOGIN_BTNCANCELAR] = range(200, 202)

  def __init__(self, owner):
    FXDialogBox.__init__(self,owner,"Login do Sistema", 
    DECOR_TITLE | DECOR_CLOSE, 546, 346, 211, 148, 0, 0, 0, 0, 4, 4)

    FXMAPFUNC(self, SEL_COMMAND, frmLogin.ID_FRMLOGIN_BTNLOGIN, 
      frmLogin.onBtnLogin)
    FXMAPFUNC(self, SEL_COMMAND, frmLogin.ID_FRMLOGIN_BTNCANCELAR, 
      frmLogin.onBtnCancelar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmLogin.onClose)

    Rotinas = RotinasGlobais.Rotinas
    self.setIcon(Rotinas.lerFigura(self.getApp(), "Livrus.bmp"))

    frame1 = FXHorizontalFrame(self, LAYOUT_FILL_X)
    frame2 = FXHorizontalFrame(frame1, LAYOUT_LEFT)
    frame3 = FXVerticalFrame(frame1, LAYOUT_LEFT)
  
    bmpLoginIcon = Rotinas.lerFigura(self.getApp(), "Login.bmp")
    bmpLogin = FXLabel(frame2, "", bmpLoginIcon, 
      LAYOUT_LEFT, 8, 8, 88, 90) 
    labLogin = FXLabel(frame3, "Login: ", None, LAYOUT_LEFT, 
      112, 8, 29, 13)
    self.edtLogin = FXTextField(frame3, 10, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK, 112, 24, 80, 21, 3, 10)
    labSenha = FXLabel(frame3, "Senha:", None, LAYOUT_LEFT, 
      112, 56, 34, 13)
    self.edtSenha = FXTextField(frame3, 10, None, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 72, 80, 21, 3, 10)
  
    frameBotoes = FXHorizontalFrame(self,
      LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH)
    btnLogin = FXButton(frameBotoes, "&Login", None, self, 
      frmLogin.ID_FRMLOGIN_BTNLOGIN, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
      LAYOUT_CENTER_X, 24, 107, 75, 25, 15, 15, 3, 3 )
    btnCancelar = FXButton(frameBotoes, "&Cancelar", None, self, 
      frmLogin.ID_FRMLOGIN_BTNCANCELAR, FRAME_RAISED|FRAME_THICK|LAYOUT_CENTER_X, 
      112, 107, 75, 25, 15, 15, 3, 3 )
    self.edtLogin.setFocus()

    self.bFechar = False

  def create(self):
    FXDialogBox.create(self) 

  def onBtnLogin(self, sender, sel, ptr):
    Rotinas = RotinasGlobais.Rotinas
    ConsSQL = ConsultasSQL.ConsSQL
    Rotinas.sUsuarioLogin = self.edtLogin.getText()
    Rotinas.sUsuarioSenha = self.edtSenha.getText()

    if Rotinas.ConsultaDados(Rotinas.gConexao, ConsSQL.Usuario('S',
       Rotinas.sUsuarioLogin, Rotinas.sUsuarioSenha)):
      Rotinas.sBarraLogin = Resource.STR_USUARIO + Rotinas.sUsuarioLogin
      Principal.fPrincipal.setLabStatus(Rotinas.sBarraLogin)

      self.bFechar = False
      Principal.fPrincipal.show(PLACEMENT_SCREEN)
      self.destroy()	
    else:
      showModalErrorBox(self, MBOX_OK, 'Erro', Resource.STR_LOGSENINC)
 
    return True
  
  def onBtnCancelar(self, sender, sel, ptr):
    self.bFechar = True
    self.getApp().exit(0)
    return True
  
  def onClose(self, sender, sel, ptr):
    self.destroy()
    if self.bFechar:
      Principal.fPrincipal.destroy()
      self.getApp().exit(0)

    return True
