require 'wxruby'
require 'Principal'
require 'resource'
require 'RotinasGlobais'
require 'ConsultasSQL'

$fLogin = nil

class FrmLogin < Wx::Dialog
  ID_FRMLOGIN_BMPLOGIN, ID_FRMLOGIN_LABLOGIN, ID_FRMLOGIN_EDTLOGIN, 
  ID_FRMLOGIN_LABSENHA, ID_FRMLOGIN_EDTSENHA, ID_FRMLOGIN_BTNLOGIN,
  ID_FRMLOGIN_BTNCANCELAR = 2000,2001,2002,2003,2004,2005,2006,2007
  def initialize()
    super(nil, -1, "Login do Sistema", Wx::Point.new(546, 346), 
      Wx::Size.new(211, 168), Wx::DEFAULT_DIALOG_STYLE,"") 
    set_client_size(Wx::Size.new(203, 141))

    @bmpLogin = Wx::StaticBitmap.new(self, ID_FRMLOGIN_BMPLOGIN, 
      Wx::Bitmap.new('xpms\\login.xpm', Wx::BITMAP_TYPE_ANY),
      Wx::Point.new(8, 8), Wx::Size.new(88, 90))
  	@labLogin = Wx::StaticText.new(self, ID_FRMLOGIN_LABLOGIN, 
      "Login:", Wx::Point.new(112, 8), Wx::Size.new(29, 13) )
  	@edtLogin = Wx::TextCtrl.new(self, ID_FRMLOGIN_EDTLOGIN, "", 
      Wx::Point.new(112, 24), Wx::Size.new(80, 21) )
    @edtLogin.set_max_length(10)
  	@labSenha = Wx::StaticText.new(self, ID_FRMLOGIN_LABSENHA, 
      "Senha:", Wx::Point.new(112, 56), Wx::Size.new(34, 13) )
  	@edtSenha = Wx::TextCtrl.new(self, ID_FRMLOGIN_EDTSENHA, "", 
      Wx::Point.new(112, 72), Wx::Size.new(80, 21), Wx::TE_PASSWORD )
    @edtSenha.set_max_length(10)
  	@btnLogin = Wx::Button.new(self, ID_FRMLOGIN_BTNLOGIN, "&Login",
      Wx::Point.new(24, 107), Wx::Size.new(75, 25))
  	@btnCancelar = Wx::Button.new(self, ID_FRMLOGIN_BTNCANCELAR, "&Cancelar",
      Wx::Point.new(112, 107), Wx::Size.new(75, 25))
  	@btnLogin.set_default()

    @bFechar = false 
    FazLayout()
    evt_close {|event| on_close(event)}
    evt_button(ID_FRMLOGIN_BTNLOGIN) {|event| on_BtnLoginClick(event)}
    evt_button(ID_FRMLOGIN_BTNCANCELAR) {|event| on_BtnCancelarClick(event)}
  end

  def FazLayout() 
  	sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
  	sizer_4 = Wx::BoxSizer.new(Wx::HORIZONTAL)
  	sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)
  	sizer_3 = Wx::BoxSizer.new(Wx::VERTICAL)
  	sizer_2.add(@bmpLogin, 0, Wx::ALL, 6)
  	sizer_3.add(@labLogin, 0, Wx::ALL|Wx::ALIGN_BOTTOM, 2)
  	sizer_3.add(@edtLogin, 0, Wx::ALL, 2)
  	sizer_3.add(@labSenha, 0, Wx::ALL|Wx::ALIGN_BOTTOM, 2)
  	sizer_3.add(@edtSenha, 0, Wx::ALL, 2)
  	sizer_2.add(sizer_3, 0, Wx::ALL, 6)
  	sizer_1.add(sizer_2, 0, 0, 3)
  	sizer_4.add(@btnLogin, 0, Wx::DIRECTION_LEFT|Wx::DIRECTION_TOP|
      Wx::DIRECTION_BOTTOM||Wx::ALIGN_BOTTOM, 10)
  	sizer_4.add(@btnCancelar, 0, Wx::ALL|Wx::ALIGN_BOTTOM, 10)
  	sizer_1.add(sizer_4, 0, 
      Wx::ALL|Wx::ALIGN_CENTER_HORIZONTAL, 1)
  	self.set_auto_layout(true)
  	self.set_sizer(sizer_1)
  	sizer_1.fit(self)
  	sizer_1.set_size_hints(self)
  	self.layout()
  	self.centre()
  end

  def on_close(event)
    if @bFechar then
      destroy()
    else
      $fPrincipal.destroy()
      exit(0)
    end
  end

  def on_BtnLoginClick(event) 
    $Rotinas.sUsuarioLogin = @edtLogin.get_value()
    $Rotinas.sUsuarioSenha = @edtSenha.get_value()

    if $Rotinas.ConsultaDados($Rotinas.gConexao, $ConsSQL.Usuario('S',
       $Rotinas.sUsuarioLogin, $Rotinas.sUsuarioSenha)) then
      $Rotinas.sBarraLogin = Resource::STR_USUARIO + $Rotinas.sUsuarioLogin
      $fPrincipal.set_status_text($Rotinas.sBarraLogin, 0)
  
      @bFechar = true
      self.close(true)
      $fPrincipal.show(true)
    else
      $Rotinas.MessageErro(Resource::STR_LOGSENINC)
    end
    event.skip()
  end
  
  def on_BtnCancelarClick(event)
    @bFechar = false
    self.close(true)
    event.skip()
  end

end
