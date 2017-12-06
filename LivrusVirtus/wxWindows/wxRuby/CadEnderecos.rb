require 'wxruby'
require 'Cadastros'
require 'TextValidatorCtrl'

class FrmCadEnderecos < FrmCadastros
  ID_FRMCADENDERECOS_CMBESTADO, ID_FRMCADENDERECOS_EDTBAIRRO, 
  ID_FRMCADENDERECOS_EDTCEP, ID_FRMCADENDERECOS_EDTCIDADE, 
  ID_FRMCADENDERECOS_LABBAIRRO, ID_FRMCADENDERECOS_LABCEP, 
  ID_FRMCADENDERECOS_LABCIDADE, ID_FRMCADENDERECOS_LABESTADO = 
  5000,5001,5002,5003,5004,5005,5006,5007

  def initialize(parent)
    super(parent, TextValidatorCtrl::FILTER_NUMERIC, false) 
    set_client_size(Wx::Size.new(523, 171))
    @labDescricao.set_label('Logradouro:')
    @labDescricao.set_size(Wx::Size.new(57, 13))
    @edtDescricao.set_size(Wx::Size.new(264, 21))
  
  	@labBairro = Wx::StaticText.new(self, ID_FRMCADENDERECOS_LABBAIRRO, 
      "Bairro:", Wx::Point.new(280, 48), Wx::Size.new(48, 13) )
  	@edtBairro = Wx::TextCtrl.new(self, ID_FRMCADENDERECOS_EDTBAIRRO,
      "", Wx::Point.new(280, 64), Wx::Size.new(144, 21) )
    @edtBairro.enable(false)
  	@labCEP = Wx::StaticText.new(self, ID_FRMCADENDERECOS_LABCEP, 
      "CEP: ", Wx::Point.new(80, 88), Wx::Size.new(40, 13) )
  	@edtCEP = Wx::TextCtrl.new(self, ID_FRMCADENDERECOS_EDTCEP, 
      "", Wx::Point.new(8, 104), Wx::Size.new(72, 21) )
    @edtCEP.enable(false)
  	@labCidade = Wx::StaticText.new(self, ID_FRMCADENDERECOS_LABCIDADE, 
      "Cidade: ", Wx::Point.new(88, 88), Wx::Size.new(39, 13) )
  	@edtCidade = Wx::TextCtrl.new(self, ID_FRMCADENDERECOS_EDTCIDADE, 
      "", Wx::Point.new(88, 104), Wx::Size.new(184, 21) )
    @edtCidade.enable(false)
  	@labEstado = Wx::StaticText.new(self, ID_FRMCADENDERECOS_LABESTADO, 
      "Estado: ", Wx::Point.new(280, 88), Wx::Size.new(56, 13) )
  	@cmbEstado = Wx::Choice.new(self, ID_FRMCADENDERECOS_CMBESTADO, 
      Wx::Point.new(280, 104), Wx::Size.new(144, 21) )
    @cmbEstado.enable(false)

    IniciaBotoes()
  
    @btnPesquisar.set_dimensions(440, 8, 75, 25)
    @btnAnterior.set_dimensions(440, 40, 75, 25)
    @btnProximo.set_dimensions(440, 72, 75, 25)
    @btnSalvar.set_dimensions(200, 136, 75, 25)
    @btnExcluir.set_dimensions(280, 136, 75, 25)
    @btnLimpar.set_dimensions(360, 136, 75, 25)
    @btnFechar.set_dimensions(440, 136, 75, 25)
  
    FazLayout()
  
    @edtDescricao.set_max_length(40)
    @edtBairro.set_max_length(15)
    @edtCEP.set_max_length(8)
    @edtCidade.set_max_length(30)
    AdicionaCombo()

    evt_button(ID_FRMCADASTROS_BTNNOVO) {|event| OnBtnNovoClick(event)}
    evt_button(ID_FRMCADASTROS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCADASTROS_BTNANTERIOR) {|event| OnBtnAnteriorClick(event)}
    evt_button(ID_FRMCADASTROS_BTNPROXIMO) {|event| OnBtnProximoClick(event)}
    evt_button(ID_FRMCADASTROS_BTNSALVAR) {|event| OnBtnSalvarClick(event)}
    evt_button(ID_FRMCADASTROS_BTNEXCLUIR) {|event| OnBtnExcluirClick(event)}
    evt_button(ID_FRMCADASTROS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCADASTROS_BTNFECHAR) {|event| OnBtnFecharClick(event)}
  end

  def FazLayout()
    sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_3 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_4 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_5 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_6 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_6 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_5 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_4 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_8 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_9 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_8 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_7 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_7 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_7.add(@labCodigo, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_7.add(@edtCodigo, 0, 0, 0)
    sizer_7.add(grid_sizer_7, 0, 0, 0)
    sizer_7.add(@btnNovo, 0, Wx::DIRECTION_LEFT|Wx::ALIGN_BOTTOM, 5)
    sizer_5.add(sizer_7, 1, 0, 0)
    grid_sizer_8.add(@labDescricao, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_8.add(@edtDescricao, 0, 0, 0)
    sizer_8.add(grid_sizer_8, 0, 0, 0)
    grid_sizer_9.add(@labBairro, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_9.add(@edtBairro, 0, 0, 0)
    sizer_8.add(grid_sizer_9, 0, Wx::DIRECTION_LEFT, 2)
    sizer_5.add(sizer_8, 1, Wx::EXPAND, 0)
    grid_sizer_4.add(@labCEP, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_4.add(@edtCEP, 0, 0, 0)
    sizer_6.add(grid_sizer_4, 0, 0, 0)
    grid_sizer_5.add(@labCidade, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_5.add(@edtCidade, 0, 0, 0)
    sizer_6.add(grid_sizer_5, 0, Wx::DIRECTION_LEFT, 4)
    grid_sizer_6.add(@labEstado, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_6.add(@cmbEstado, 0, 0, 0)
    sizer_6.add(grid_sizer_6, 0, Wx::DIRECTION_LEFT, 5)
    sizer_5.add(sizer_6, 0, 0, 0)
    sizer_3.add(sizer_5, 0, 0, 0)
    sizer_4.add(@btnPesquisar, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_4.add(@btnAnterior, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_4.add(@btnProximo, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_3.add(sizer_4, 1, 0, 0)
    sizer_1.add(sizer_3, 1, Wx::ALL|Wx::EXPAND, 4)
    sizer_2.add(@btnSalvar, 0, 
      Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_2.add(@btnExcluir, 0, 
      Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_2.add(@btnLimpar, 0, 
      Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_2.add(@btnFechar, 0, 
      Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_1.add(sizer_2, 0, Wx::DIRECTION_RIGHT|Wx::DIRECTION_BOTTOM|
      Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 4)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(
      @edtCodigo.get_value(), Resource::STR_CODNINF) then
      return false
    end
    if bTodosDados then
  	  if $Rotinas.ValidaCampo(
        @edtDescricao.get_value(), Resource::STR_ENDNINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtBairro.get_value(), Resource::STR_BAIRRONINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtCEP.get_value(), Resource::STR_CEPNINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtCidade.get_value(), Resource::STR_CIDADENINF) then
    		return false
      end
    end
    return true
  end

  def OnBtnNovoClick(event)
    self.btnNovoClick()
    self.InformaLimpaDadosLocal(false)
    self.HabilitaDadosLocal(true)
    self.NovoDado($ConsSQL.Endereco('N', 
      @edtCodigo.get_value(),"","","","",""))
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    if self.PesquisarDados($ConsSQL.Endereco('S', 
      @edtCodigo.get_value(),"","","","",""), Resource::STR_ENDNENC) then
      self.InformaLimpaDadosLocal(true)
      self.HabilitaDadosLocal(true)
    end
    event.skip()
  end

  def OnBtnAnteriorClick(event)
    if self.registroAnterior() then
      self.InformaLimpaDadosLocal(true)
    end
    event.skip()
  end

  def OnBtnProximoClick(event)
    if self.registroProximo() then
      self.InformaLimpaDadosLocal(true)
    end
    event.skip()
  end

  def OnBtnSalvarClick(event)
    if self.SalvarDados(self.ValidaDados(true),
      $ConsSQL.Endereco('S', @edtCodigo.get_value(),
      "","","","",""),
      $ConsSQL.Endereco('U', @edtCodigo.get_value(), 
      @edtDescricao.get_value(),@edtBairro.get_value(),
      @edtCEP.get_value(),@edtCidade.get_value(), 
      @cmbEstado.get_string_selection()),
      $ConsSQL.Endereco('I', @edtCodigo.get_value(), 
      @edtDescricao.get_value(),@edtBairro.get_value(),
      @edtCEP.get_value(),@edtCidade.get_value(), 
      @cmbEstado.get_string_selection()), true) then
      self.InformaLimpaDadosLocal(false)
      self.HabilitaDadosLocal(false)
    end
    event.skip()
  end

  def OnBtnExcluirClick(event)
    if self.ExcluirDados(self.ValidaDados(false),
      $ConsSQL.Endereco('D', @edtCodigo.get_value(),
      "","","","","")) then
      self.InformaLimpaDadosLocal(false)
      self.HabilitaDadosLocal(false)
    end
    event.skip()
  end

  def OnBtnLimparClick(event)
    self.btnLimparClick()
    self.InformaLimpaDadosLocal(false)
    self.HabilitaDadosLocal(false)
    event.skip()
  end

  def OnBtnFecharClick(event)
    self.get_parent().close(true)
    event.skip()
  end

  def InformaLimpaDadosLocal(bInformar)
    if bInformar then
      @edtBairro.set_value(@lstRegistros.col[@nLinhaRegistro][2])
      @edtCEP.set_value(@lstRegistros.col[@nLinhaRegistro][3])
      @edtCidade.set_value(@lstRegistros.col[@nLinhaRegistro][4])
      @cmbEstado.set_string_selection(
        @lstRegistros.col[@nLinhaRegistro][5])
    else
      @edtBairro.clear()
      @edtCEP.clear()
      @edtCidade.clear()
      @cmbEstado.set_selection(0)
    end
  end
  
  def HabilitaDadosLocal(bHabilita)
    @edtBairro.enable(bHabilita)
    @edtCEP.enable(bHabilita)  
    @edtCidade.enable(bHabilita)
    @cmbEstado.enable(bHabilita)  
  end

  def AdicionaCombo()
    @cmbEstado.append(Resource::STR_PE)
    @cmbEstado.append(Resource::STR_AC)
    @cmbEstado.append(Resource::STR_AL)
    @cmbEstado.append(Resource::STR_AP)
    @cmbEstado.append(Resource::STR_AM)
    @cmbEstado.append(Resource::STR_BA)
    @cmbEstado.append(Resource::STR_BR)
    @cmbEstado.append(Resource::STR_CE)
    @cmbEstado.append(Resource::STR_DF)
    @cmbEstado.append(Resource::STR_ES)
    @cmbEstado.append(Resource::STR_GO)
    @cmbEstado.append(Resource::STR_MT)
    @cmbEstado.append(Resource::STR_MS)
    @cmbEstado.append(Resource::STR_MG)
    @cmbEstado.append(Resource::STR_PA)
    @cmbEstado.append(Resource::STR_PB)
    @cmbEstado.append(Resource::STR_PR)
    @cmbEstado.append(Resource::STR_SC)
    @cmbEstado.append(Resource::STR_RN)
    @cmbEstado.append(Resource::STR_RS)
    @cmbEstado.append(Resource::STR_RJ)
    @cmbEstado.append(Resource::STR_RO)
    @cmbEstado.append(Resource::STR_RR)
    @cmbEstado.append(Resource::STR_SP)
    @cmbEstado.append(Resource::STR_SE)
    @cmbEstado.append(Resource::STR_TO)
  end
end
