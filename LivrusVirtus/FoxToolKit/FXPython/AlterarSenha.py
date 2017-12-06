from FXPy.fox import *
from resource import Resource
from ConsultasSQL import ConsultasSQL
from RotinasGlobais import RotinasGlobais
import Principal

class frmAlterarSenha(FXMDIChild):
  [ID_FRMALTERARSENHA_BTNSALVAR, ID_FRMALTERARSENHA_BTNLIMPAR,
  ID_FRMALTERARSENHA_BTNFECHAR] = range(300, 303)

  def __init__(self, clienteMDI, iconeMDI, menuMDI):
    FXMDIChild.__init__(self, clienteMDI, Resource.STR_ALTSENHA, 
      iconeMDI, menuMDI, MDI_NORMAL, 0, 0, 257, 181)

    FXMAPFUNC(self, SEL_COMMAND, frmAlterarSenha.ID_FRMALTERARSENHA_BTNSALVAR, 
      frmAlterarSenha.onCmdSalvar)
    FXMAPFUNC(self, SEL_COMMAND, frmAlterarSenha.ID_FRMALTERARSENHA_BTNLIMPAR, 
      frmAlterarSenha.onCmdLimpar)
    FXMAPFUNC(self, SEL_COMMAND, frmAlterarSenha.ID_FRMALTERARSENHA_BTNFECHAR, 
      frmAlterarSenha.onCmdFechar)
    FXMAPFUNC(self, SEL_CLOSE, 0, frmAlterarSenha.onClose)

    frame = FXVerticalFrame(self, LAYOUT_FILL_X | LAYOUT_FILL_Y)
  
    frame1 = FXVerticalFrame(frame, LAYOUT_FILL_X)
    frame2 = FXHorizontalFrame(frame1, LAYOUT_TOP)
    frame2.setHSpacing(0)
    frame2.setVSpacing(0)
    frame3 = FXHorizontalFrame(frame1, LAYOUT_TOP)
    frame3.setHSpacing(0)
    frame3.setVSpacing(0)
  
    frame4 = FXVerticalFrame(frame2, LAYOUT_LEFT)
    frame4.setPadTop(0)
    frame4.setPadBottom(0)
    frame5 = FXVerticalFrame(frame2, LAYOUT_LEFT)
    frame5.setPadTop(0)
    frame5.setPadBottom(0)
  
    frame6 = FXVerticalFrame(frame3, LAYOUT_LEFT)
    frame6.setPadTop(0)
    frame6.setPadBottom(0)
    frame7 = FXVerticalFrame(frame3, LAYOUT_LEFT)
    frame7.setPadTop(0)
    frame7.setPadBottom(0)
  
    labLogin = FXLabel(frame4, "Login: ", None, LAYOUT_LEFT, 
      8, 8, 29, 13)
    self.edtLogin = FXTextField(frame4, 10, None, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK, 8, 24, 100, 21, 3, 20)
    self.edtLogin.disable()
    labSenhaAtual = FXLabel(frame5, "Senha atual:", None, LAYOUT_LEFT, 
      112, 8, 60, 13)
    self.edtSenhaAtual = FXTextField(frame5, 10, None, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 24, 100, 21, 3, 20)
    labNovaSenha = FXLabel(frame6, "Nova Senha:", None, LAYOUT_LEFT, 
      8, 48, 61, 13)
    self.edtNovaSenha = FXTextField(frame6, 10, None, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 8, 64, 100, 21, 3, 20)
    labConfirmarSenha = FXLabel(frame7, "Confirmar Senha:", None, LAYOUT_LEFT, 
      112, 48, 79, 13)
    self.edtConfirmaSenha = FXTextField(frame7, 10, None, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 64, 100, 21, 3, 20)
  
    frameBotoes = FXHorizontalFrame(frame,
      LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH)
    btnSalvar = FXButton(frameBotoes, "&Salvar", None, self, 
      frmAlterarSenha.ID_FRMALTERARSENHA_BTNSALVAR, 
      BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
      LAYOUT_LEFT, 8, 104, 75, 25, 15, 15, 3, 3 )
    btnLimpar = FXButton(frameBotoes, "&Limpar", None, self, 
      frmAlterarSenha.ID_FRMALTERARSENHA_BTNLIMPAR, 
      FRAME_RAISED|FRAME_THICK|LAYOUT_LEFT, 
      88, 104, 75, 25, 15, 15, 3, 3 )
    btnFechar = FXButton(frameBotoes, "&Fechar", None, self, 
      frmAlterarSenha.ID_FRMALTERARSENHA_BTNFECHAR, 
      FRAME_RAISED|FRAME_THICK|LAYOUT_LEFT, 
      168, 104, 75, 25, 15, 15, 3, 3 )
  
    Rotinas = RotinasGlobais.Rotinas
    self.edtLogin.setText(Rotinas.sUsuarioLogin)
    self.edtSenhaAtual.setFocus()

  def ValidaDados():
    if self.edtSenhaAtual.getText() != Rotinas.sUsuarioSenha:
      FXMessageBox.error(self, MBOX_OK, "Erro", Resource.STR_SENNCSU)
      return False    
    if Rotinas.ValidaCampo(self.edtNovaSenha.getText(),Resource.STR_NSENNINF):
   	  return False    
    if self.edtNovaSenha.getText() != self.edtConfirmaSenha.getText():
      FXMessageBox.error(self, MBOX_OK, "Erro", Resource.STR_NSENNCCON)
      return False
    
    return True  

  def onCmdSalvar(self, sender, sel, ptr):
    if ValidaDados():
      ConsSQL = ConsultasSQL.ConsSQL
      if Rotinas.AtualizaDados(Rotinas.gConexao, ConsSQL.Usuario('U', 
        self.edtLogin.getText(), self.edtConfirmaSenha.getText())):
        showModalInformationBox(self, MBOX_OK, "Erro", Resource.STR_SENALTSUC)    
    return True
  
  def onCmdLimpar(self, sender, sel, ptr):
    self.edtSenhaAtual.setText("")
    self.edtNovaSenha.setText("")
    self.edtConfirmaSenha.setText("")
    self.edtSenhaAtual.setFocus()
    return True

  def onCmdFechar(self, sender, sel, ptr):
    self.onClose(sender, sel, ptr)
    return True 

  def onClose(self, sender, sel, ptr):
    Principal.fPrincipal.habilitaMenu("AlterarSenha")
    self.destroy()
    return True
