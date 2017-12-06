require 'fox'
require 'fox/responder'

require 'resource'
require 'Principal'
require 'RotinasGlobais'
require 'ConsultasSQL'

include Fox
include Responder

class FRMAlterarSenha < FXMDIChild

  ID_FRMALTERARSENHA_BTNSALVAR, ID_FRMALTERARSENHA_BTNLIMPAR, 
    ID_FRMALTERARSENHA_BTNFECHAR = enum(FXMainWindow::ID_LAST, 3)
        
  def initialize(clienteMDI, iconeMDI, menuMDI)  
    super(clienteMDI, Resource::STR_ALTSENHA, iconeMDI, menuMDI, 
      MDI_NORMAL, 0, 0, 257, 181)

    FXMAPFUNC(SEL_COMMAND, ID_FRMALTERARSENHA_BTNSALVAR, :onCmdSalvar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMALTERARSENHA_BTNLIMPAR, :onCmdLimpar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMALTERARSENHA_BTNFECHAR, :onCmdFechar)
    FXMAPFUNC(SEL_CLOSE, 0, :onClose)

    frame = FXVerticalFrame.new(self, LAYOUT_FILL_X | LAYOUT_FILL_Y)
  
    frame1 = FXVerticalFrame.new(frame, LAYOUT_FILL_X)
    frame2 = FXHorizontalFrame.new(frame1, LAYOUT_TOP)
    frame2.setHSpacing(0)
    frame2.setVSpacing(0)
    frame3 = FXHorizontalFrame.new(frame1, LAYOUT_TOP)
    frame3.setHSpacing(0)
    frame3.setVSpacing(0)
  
    frame4 = FXVerticalFrame.new(frame2, LAYOUT_LEFT)
    frame4.setPadTop(0)
    frame4.setPadBottom(0)
    frame5 = FXVerticalFrame.new(frame2, LAYOUT_LEFT)
    frame5.setPadTop(0)
    frame5.setPadBottom(0)
  
    frame6 = FXVerticalFrame.new(frame3, LAYOUT_LEFT)
    frame6.setPadTop(0)
    frame6.setPadBottom(0)
    frame7 = FXVerticalFrame.new(frame3, LAYOUT_LEFT)
    frame7.setPadTop(0)
    frame7.setPadBottom(0)
  
    labLogin = FXLabel.new(frame4, "Login: ", nil, LAYOUT_LEFT, 
      8, 8, 29, 13)
    @edtLogin = FXTextField.new(frame4, 10, nil, 0, TEXTFIELD_LIMITED|
      FRAME_SUNKEN|FRAME_THICK, 8, 24, 100, 21, 3, 20)
    @edtLogin.disable()
    labSenhaAtual = FXLabel.new(frame5, "Senha atual:", nil, LAYOUT_LEFT, 
      112, 8, 60, 13)
    @edtSenhaAtual = FXTextField.new(frame5, 10, nil, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 24, 100, 21, 3, 20)
    labNovaSenha = FXLabel.new(frame6, "Nova Senha:", nil, LAYOUT_LEFT, 
      8, 48, 61, 13)
    @edtNovaSenha = FXTextField.new(frame6, 10, nil, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 8, 64, 100, 21, 3, 20)
    labConfirmarSenha = FXLabel.new(frame7, "Confirmar Senha:", nil, LAYOUT_LEFT, 
      112, 48, 79, 13)
    @edtConfirmaSenha = FXTextField.new(frame7, 10, nil, 0, TEXTFIELD_LIMITED|
      TEXTFIELD_PASSWD|FRAME_SUNKEN|FRAME_THICK, 112, 64, 100, 21, 3, 20)
  
    frameBotoes = FXHorizontalFrame.new(frame,
      LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH)
    btnSalvar = FXButton.new(frameBotoes, "&Salvar", nil, self, 
      ID_FRMALTERARSENHA_BTNSALVAR, BUTTON_DEFAULT|FRAME_RAISED|FRAME_THICK|
      LAYOUT_LEFT, 8, 104, 75, 25, 15, 15, 3, 3 )
    btnLimpar = FXButton.new(frameBotoes, "&Limpar", nil, self, 
      ID_FRMALTERARSENHA_BTNLIMPAR, FRAME_RAISED|FRAME_THICK|LAYOUT_LEFT, 
      88, 104, 75, 25, 15, 15, 3, 3 )
    btnFechar = FXButton.new(frameBotoes, "&Fechar", nil, self, 
      ID_FRMALTERARSENHA_BTNFECHAR, FRAME_RAISED|FRAME_THICK|LAYOUT_LEFT, 
      168, 104, 75, 25, 15, 15, 3, 3 )
  
    @edtLogin.setText($Rotinas.sUsuarioLogin)
    @edtSenhaAtual.setFocus()
  end

  def ValidaDados()
    if @edtSenhaAtual.getText() != $Rotinas.sUsuarioSenha
       FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_SENNCSU)
       return false
    end
    if $Rotinas.ValidaCampo(@edtNovaSenha.getText(),Resource::STR_NSENNINF)
    	  return false
    end
    if @edtNovaSenha.getText() != @edtConfirmaSenha.getText()
       FXMessageBox.error(self, MBOX_OK, "Erro", Resource::STR_NSENNCCON)
       return false
    end
    return true    
  end

  def onCmdSalvar(sender, sel, ptr)
    if ValidaDados()
      if $Rotinas.AtualizaDados($Rotinas.gConexao, $ConsSQL.Usuario('U', 
        @edtLogin.getText(), @edtConfirmaSenha.getText()))
        FXMessageBox.information(self, MBOX_OK, "Erro", 
          Resource::STR_SENALTSUC)
      end         
    end
    return true
  end
  
  def onCmdLimpar(sender, sel, ptr)
    @edtSenhaAtual.setText("")
    @edtNovaSenha.setText("")
    @edtConfirmaSenha.setText("")
    @edtSenhaAtual.setFocus()
    return true
  end

  def onCmdFechar(sender, sel, ptr)
    onClose(sender, sel, ptr)
    return true
  end

  def onClose(sender, sel, ptr)
    $frmPrincipal.habilitaMenu("AlterarSenha")
    destroy()
    return true
  end 
end
