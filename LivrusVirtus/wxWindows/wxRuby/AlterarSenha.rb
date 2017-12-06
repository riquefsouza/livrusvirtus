require 'wxruby'
require 'RotinasGlobais'

class FrmAlterarSenha < Wx::Panel
 ID_FRMALTERARSENHA_BTNFECHAR, ID_FRMALTERARSENHA_BTNLIMPAR, 
 ID_FRMALTERARSENHA_BTNSALVAR, ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, 
 ID_FRMALTERARSENHA_EDTLOGIN, ID_FRMALTERARSENHA_EDTNOVASENHA, 
 ID_FRMALTERARSENHA_EDTSENHAATUAL, ID_FRMALTERARSENHA_LABCONFIRMARSENHA, 
 ID_FRMALTERARSENHA_LABLOGIN, ID_FRMALTERARSENHA_LABNOVASENHA, 
 ID_FRMALTERARSENHA_LABSENHAATUAL = 
 4000,4001,4002,4003,4004,4005,4006,4007,4008,4009,4010

  def initialize(parent)
    super(parent, -1, Wx::Point.new(424, 292), 
      Wx::Size.new(257, 161), Wx::TAB_TRAVERSAL,"") 
    set_client_size(Wx::Size.new(249, 134))
    evt_close {|event| on_close(event)}

  	@labLogin = Wx::StaticText.new(self, ID_FRMALTERARSENHA_LABLOGIN, 
      "Login: ", Wx::Point.new(8, 8), Wx::Size.new(29, 13) )
  	@edtLogin = Wx::TextCtrl.new(self, ID_FRMALTERARSENHA_EDTLOGIN, "", 
      Wx::Point.new(8, 24), Wx::Size.new(100, 21) )
  	@edtLogin.enable(false)
  	@labSenhaAtual = Wx::StaticText.new(self, ID_FRMALTERARSENHA_LABSENHAATUAL, 
      "Senha atual:", Wx::Point.new(112, 8), Wx::Size.new(60, 13) )
  	@edtSenhaAtual = Wx::TextCtrl.new(self, ID_FRMALTERARSENHA_EDTSENHAATUAL, 
      "", Wx::Point.new(112, 24), Wx::Size.new(100, 21), Wx::TE_PASSWORD )
  	@labNovaSenha = Wx::StaticText.new(self, ID_FRMALTERARSENHA_LABNOVASENHA, 
      "Nova Senha:", Wx::Point.new(8, 48), Wx::Size.new(61, 13) )
  	@edtNovaSenha = Wx::TextCtrl.new(self, ID_FRMALTERARSENHA_EDTNOVASENHA,
      "", Wx::Point.new(8, 64), Wx::Size.new(100, 21), Wx::TE_PASSWORD )
  	@labConfirmarSenha = Wx::StaticText.new(self, 
      ID_FRMALTERARSENHA_LABCONFIRMARSENHA, "Confirmar senha:", 
      Wx::Point.new(112, 48), Wx::Size.new(79, 13) )
  	@edtConfirmarSenha = Wx::TextCtrl.new(self, 
      ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, "", 
      Wx::Point.new(112, 64), Wx::Size.new(100, 21), Wx::TE_PASSWORD )
  	@btnSalvar = Wx::Button.new(self, ID_FRMALTERARSENHA_BTNSALVAR, 
      "&Salvar", Wx::Point.new(8, 104), Wx::Size.new(75, 25))
  	@btnLimpar = Wx::Button.new(self, ID_FRMALTERARSENHA_BTNLIMPAR, 
      "&Limpar", Wx::Point.new(88, 104), Wx::Size.new(75, 25))
  	@btnFechar = Wx::Button.new(self, ID_FRMALTERARSENHA_BTNFECHAR, 
      "&Fechar", Wx::Point.new(168, 104), Wx::Size.new(75, 25)) 

    @edtLogin.set_value($Rotinas.sUsuarioLogin)
    @edtSenhaAtual.set_max_length(10)
    @edtNovaSenha.set_max_length(10)
    @edtConfirmarSenha.set_max_length(10)

    evt_button(ID_FRMALTERARSENHA_BTNSALVAR) {|event| OnBtnSalvarClick(event)}
    evt_button(ID_FRMALTERARSENHA_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMALTERARSENHA_BTNFECHAR) {|event| OnBtnFecharClick(event)}

  	FazLayout()
  	@edtSenhaAtual.set_focus()
  end

  def FazLayout()
    sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_9 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_10 = Wx::GridSizer.new(4, 1, 0, 0)
    grid_sizer_3 = Wx::GridSizer.new(4, 1, 0, 0)
    grid_sizer_3.add(@labLogin, 0, 
      Wx::DIRECTION_LEFT|Wx::ALIGN_BOTTOM, 8)
    grid_sizer_3.add(@edtLogin, 0, Wx::DIRECTION_LEFT, 8)
    grid_sizer_3.add(@labNovaSenha, 0, 
      Wx::DIRECTION_LEFT|Wx::ALIGN_BOTTOM, 8)
    grid_sizer_3.add(@edtNovaSenha, 0, Wx::DIRECTION_LEFT, 8)
    sizer_9.add(grid_sizer_3, 0, 0, 0)
    grid_sizer_10.add(@labSenhaAtual, 0, 
      Wx::DIRECTION_LEFT|Wx::ALIGN_BOTTOM, 4)
    grid_sizer_10.add(@edtSenhaAtual, 0, Wx::DIRECTION_LEFT, 4)
    grid_sizer_10.add(@labConfirmarSenha, 0, 
      Wx::DIRECTION_LEFT|Wx::ALIGN_BOTTOM, 4)
    grid_sizer_10.add(@edtConfirmarSenha, 0, Wx::DIRECTION_LEFT, 4)
    sizer_9.add(grid_sizer_10, 0, 0, 0)
    sizer_1.add(sizer_9, 1, 0, 0)
    sizer_2.add(@btnSalvar, 0, Wx::ALL, 2)
    sizer_2.add(@btnLimpar, 0, Wx::ALL, 2)
    sizer_2.add(@btnFechar, 0, Wx::ALL, 2)
    sizer_1.add(sizer_2, 0, Wx::ALL, 4)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
  end

  def on_close(event)
    destroy()
  end

  def OnBtnSalvarClick(event)
    if ValidaDados() then
      if $Rotinas.AtualizaDados($Rotinas.gConexao, $ConsSQL.Usuario('U', 
        @edtLogin.get_value(), @edtConfirmarSenha.get_value())) then
        $Rotinas.MessageErro(Resource::STR_SENALTSUC)
      end
    end
    event.skip()
  end

  def OnBtnLimparClick(event)
    @edtSenhaAtual.clear()
    @edtNovaSenha.clear()
    @edtConfirmarSenha.clear()
    @edtSenhaAtual.set_focus()
    event.skip()
  end

  def OnBtnFecharClick(event)
    self.get_parent().close(true)
    event.skip()
  end

  def ValidaDados()
    if @edtSenhaAtual.get_value() != $Rotinas.sUsuarioSenha then
      $Rotinas.MessageErro(Resource::STR_SENNCSU)
      return false
    end
    if $Rotinas.ValidaCampo(@edtNovaSenha.get_value(),
       Resource::STR_NSENNINF) then
      return false
    end
    if @edtNovaSenha.get_value() != @edtConfirmarSenha.get_value() then
      $Rotinas.MessageErro(Resource::STR_NSENNCCON)
      return false
    end
    return true
  end
end
