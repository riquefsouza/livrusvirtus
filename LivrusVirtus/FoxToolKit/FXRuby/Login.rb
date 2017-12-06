require 'fox'
include Fox
require 'resource'
require 'Login'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'

$frmLogin = nil

class FRMLogin < FXDialogBox

  ID_FRMLOGIN_BTNLOGIN, ID_FRMLOGIN_BTNCANCELAR = 
    enum(FXMainWindow::ID_LAST, 2)

  def initialize(owner)
    super(owner, "Login do Sistema", DECOR_TITLE | DECOR_CLOSE, 
    546, 346, 211, 148, 0, 0, 0, 0, 4, 4)

    FXMAPFUNC(SEL_COMMAND, ID_FRMLOGIN_BTNLOGIN, :onBtnLogin)
    FXMAPFUNC(SEL_COMMAND, ID_FRMLOGIN_BTNCANCELAR, :onBtnCancelar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)

    setIcon($Rotinas.lerFigura(getApp(), "Livrus.bmp"))
  
    frame1 = FXHorizontalFrame.new(self, LAYOUT_FILL_X)
    frame2 = FXHorizontalFrame.new(frame1, LAYOUT_LEFT)
    frame3 = FXVerticalFrame.new(frame1, LAYOUT_LEFT)
  
    bmpLoginIcon = $Rotinas.lerFigura(getApp(), "Login.bmp")
    bmpLogin = FXLabel.new(frame2, "", bmpLoginIcon, 
      LAYOUT_LEFT, 8, 8, 88, 90) 
    labLogin = FXLabel.new(frame3, "Login: ", nil, LAYOUT_LEFT, 
      112, 8, 29, 13)
    @edtLogin = FXTextField.new(frame3, 10, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK, 112, 24, 80, 21, 3, 10)
    labSenha = FXLabel.new(frame3, "Senha:", nil, LAYOUT_LEFT, 
      112, 56, 34, 13)
    @edtSenha = FXTextField.new(frame3, 10, nil, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 72, 80, 21, 3, 10)
  
    frameBotoes = FXHorizontalFrame.new(self,
      LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH)
    btnLogin = FXButton.new(frameBotoes, "&Login", nil, self, 
      ID_FRMLOGIN_BTNLOGIN, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
      LAYOUT_CENTER_X, 24, 107, 75, 25, 15, 15, 3, 3 )
    btnCancelar = FXButton.new(frameBotoes, "&Cancelar", nil, self, 
      ID_FRMLOGIN_BTNCANCELAR, FRAME_RAISED|FRAME_THICK|LAYOUT_CENTER_X, 
      112, 107, 75, 25, 15, 15, 3, 3 )
    @edtLogin.setFocus()

    @bFechar = false
  end
  
  def create
    super
  end 
  
  def onTimer(sender, sel, ptr)
    return true
  end

  def onBtnLogin(sender, sel, ptr)
    $Rotinas.sUsuarioLogin = @edtLogin.getText()
    $Rotinas.sUsuarioSenha = @edtSenha.getText()
  
    if ($Rotinas.ConsultaDados($Rotinas.gConexao, 
       $ConsSQL.Usuario('S',$Rotinas.sUsuarioLogin, $Rotinas.sUsuarioSenha)) )
                  
       $Rotinas.sBarraLogin = Resource::STR_USUARIO + $Rotinas.sUsuarioLogin
  
       $frmPrincipal.setLabStatus($Rotinas.sBarraLogin)
  
       @bFechar = false
       $frmPrincipal.show(PLACEMENT_SCREEN)
       self.destroy()	
    else
       FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_LOGSENINC)
    end
    return true
  end
  
  def onBtnCancelar(sender, sel, ptr)
    @bFechar = true
    getApp().exit(0)
    return true
  end
  
  def onClose(sender, sel, ptr)
    self.destroy()
    if @bFechar
      $frmPrincipal.destroy()
      getApp().exit(0)
    end
    return true
  end

end
