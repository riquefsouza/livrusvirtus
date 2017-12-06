require 'wxruby'
require 'Cadastros'
require 'TextValidatorCtrl'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'resource'
require 'ListaStr'
require 'ConEnderecos'
require 'ConPaises'
require 'ConProfissoes'

$fCadClientes = nil

class FrmCadClientes < FrmCadastros
  ID_FRMCADCLIENTES_BTNPENDERECO, ID_FRMCADCLIENTES_BTNPPAIS, 
  ID_FRMCADCLIENTES_BTNPPROFISSAO, ID_FRMCADCLIENTES_EDTBAIRRO, 
  ID_FRMCADCLIENTES_EDTCEP, ID_FRMCADCLIENTES_EDTCODPAIS, 
  ID_FRMCADCLIENTES_EDTCIDADE, ID_FRMCADCLIENTES_EDTCODENDERECO,  
  ID_FRMCADCLIENTES_EDTCODPROFISSAO, ID_FRMCADCLIENTES_EDTDTNASC, 
  ID_FRMCADCLIENTES_EDTEMAIL, ID_FRMCADCLIENTES_EDTESTADO, 
  ID_FRMCADCLIENTES_EDTIDENTIDADE, ID_FRMCADCLIENTES_EDTLOGRADOURO, 
  ID_FRMCADCLIENTES_EDTPAIS, ID_FRMCADCLIENTES_EDTPROFISSAO, 
  ID_FRMCADCLIENTES_EDTTELEFONE, ID_FRMCADCLIENTES_LABBAIRRO, 
  ID_FRMCADCLIENTES_LABCEP, ID_FRMCADCLIENTES_LABCIDADE,  
  ID_FRMCADCLIENTES_LABDTNASC, ID_FRMCADCLIENTES_LABEMAIL, 
  ID_FRMCADCLIENTES_LABESTADO, ID_FRMCADCLIENTES_LABIDENTIDADE, 
  ID_FRMCADCLIENTES_LABLOGRADOURO, ID_FRMCADCLIENTES_LABPAIS, 
  ID_FRMCADCLIENTES_LABPROFISSAO, ID_FRMCADCLIENTES_LABTELEFONE, 
  ID_FRMCADCLIENTES_RBSEXO, ID_FRMCADCLIENTES_SBENDERECO =
  6000,6001,6002,6003,6004,6005,6006,6007,6008,6009,6010,6011,6012,
  6013,6014,6015,6016,6017,6018,6019,6020,6021,6022,6023,6024,6025,
  6026,6027,6028,6029,6030,6031

  def initialize(parent)
    super(parent, TextValidatorCtrl::FILTER_NONE, false) 
    set_client_size(Wx::Size.new(523, 441))
    @labCodigo.set_label('CPF: ')
    @edtCodigo.destroy()
  	@edtCodigo = FrmCadClientes_TextValidatorCtrl.new(self, 
      ID_FRMCADASTROS_EDTCODIGO, "", Wx::Point.new(8, 24), 
      Wx::Size.new(121, 21), 0, TextValidatorCtrl::FILTER_NONE )
    @labDescricao.set_label('Nome: ')
    @edtDescricao.set_size(Wx::Size.new(312, 21))
    
  	@labEmail = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABEMAIL, 
      "E-mail:", Wx::Point.new(8, 88), Wx::Size.new(34, 13) )
  	@edtEmail = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTEMAIL, 
      "", Wx::Point.new(8, 104), Wx::Size.new(312, 21) )
    @edtEmail.enable(false)
  	@labIdentidade = Wx::StaticText.new(self, 
      ID_FRMCADCLIENTES_LABIDENTIDADE, "Identidade: ", 
      Wx::Point.new(322, 88), Wx::Size.new(56, 13) )
  	@edtIdentidade = Wx::TextCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTIDENTIDADE, "", Wx::Point.new(322, 104), Wx::Size.new(100, 21) )
    @edtIdentidade.enable(false)
  	@rbSexo = Wx::RadioBox.new(self, ID_FRMCADCLIENTES_RBSEXO, 
      "Sexo", Wx::Point.new(9, 128), Wx::Size.new(200, 44), ["Masculino", "Feminino"], 2, 
      Wx::RA_SPECIFY_COLS)
    @rbSexo.enable(false)
  	@labTelefone = Wx::StaticText.new(self, 
      ID_FRMCADCLIENTES_LABTELEFONE, "Telefone: ", 
      Wx::Point.new(216, 128), Wx::Size.new(48, 13) )
  	@edtTelefone = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTTELEFONE,
      "", Wx::Point.new(216, 144), Wx::Size.new(104, 21) )
    @edtTelefone.enable(false)
  	@labDtNasc = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABDTNASC, 
      "Dt. Nascimento", Wx::Point.new(322, 128), Wx::Size.new(73, 13) )
  	@edtDtNasc = FrmCadClientes_TextValidatorCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTDTNASC, "", Wx::Point.new(322, 144), 
      Wx::Size.new(100, 21), 0, TextValidatorCtrl::FILTER_NONE )
    @edtDtNasc.enable(false)
  	@edtCodEndereco = FrmCadClientes_TextValidatorCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTCODENDERECO, "", Wx::Point.new(16, 200), 
      Wx::Size.new(88, 21), 0, TextValidatorCtrl::FILTER_NUMERIC )
    @edtCodEndereco.enable(false)
  	@btnPEndereco = Wx::Button.new(self, 
      ID_FRMCADCLIENTES_BTNPENDERECO, "...", Wx::Point.new(104, 200), Wx::Size.new(21, 21))
    @btnPEndereco.enable(false)
    evt_button(ID_FRMCADCLIENTES_BTNPENDERECO) {|event| OnBtnPEnderecoClick(event)}
  	@labLogradouro = Wx::StaticText.new(self, 
      ID_FRMCADCLIENTES_LABLOGRADOURO, "Logradouro: ", 
      Wx::Point.new(16, 224), Wx::Size.new(60, 13) )
  	@edtLogradouro = Wx::TextCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTLOGRADOURO, "", Wx::Point.new(16, 240), Wx::Size.new(264, 21) )
    @edtLogradouro.enable(false)
  	@labBairro = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABBAIRRO,
      "Bairro:", Wx::Point.new(284, 224), Wx::Size.new(48, 13) )
  	@edtBairro = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTBAIRRO, 
      "", Wx::Point.new(280, 240), Wx::Size.new(144, 21) )
    @edtBairro.enable(false)
  	@labCEP = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABCEP, 
      "CEP:", Wx::Point.new(16, 264), Wx::Size.new(40, 13) )
  	@edtCEP = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTCEP, 
      "", Wx::Point.new(16, 280), Wx::Size.new(78, 21) )
    @edtCEP.enable(false)
  	@labCidade = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABCIDADE, 
      "Cidade: ", Wx::Point.new(96, 264), Wx::Size.new(39, 13) )
  	@edtCidade = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTCIDADE, 
      "", Wx::Point.new(96,280), Wx::Size.new(184, 21) )
    @edtCidade.enable(false)
  	@labEstado = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABESTADO, 
      "Estado: ", Wx::Point.new(284, 264), Wx::Size.new(56, 13) )
  	@edtEstado = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTESTADO, 
      "", Wx::Point.new(284, 280), Wx::Size.new(144, 21) )
    @edtEstado.enable(false)
  	@labPais = Wx::StaticText.new(self, ID_FRMCADCLIENTES_LABPAIS, 
      "País de origem: ", Wx::Point.new(8, 320), Wx::Size.new(77, 16) )
  	@edtCodPais = FrmCadClientes_TextValidatorCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTCODPAIS, "", Wx::Point.new(8, 336), 
      Wx::Size.new(78, 21), 0, TextValidatorCtrl::FILTER_ALPHA )
    @edtCodPais.enable(false)
  	@edtPais = Wx::TextCtrl.new(self, ID_FRMCADCLIENTES_EDTPAIS, 
      "", Wx::Point.new(88, 336), Wx::Size.new(240, 21) )
    @edtPais.enable(false)
  	@btnPPais = Wx::Button.new(self, ID_FRMCADCLIENTES_BTNPPAIS, 
      "...", Wx::Point.new(328, 336), Wx::Size.new(21, 21))
    @btnPPais.enable(false)
    evt_button(ID_FRMCADCLIENTES_BTNPPAIS) {|event| OnBtnPPaisClick(event)}
  	@labProfissao = Wx::StaticText.new(self, 
      ID_FRMCADCLIENTES_LABPROFISSAO, "Profissão: ", 
      Wx::Point.new(8, 360), Wx::Size.new(56, 13) )
  	@edtCodProfissao = FrmCadClientes_TextValidatorCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTCODPROFISSAO, "", Wx::Point.new(8, 376), 
      Wx::Size.new(78, 21), 0, TextValidatorCtrl::FILTER_NUMERIC )
    @edtCodProfissao.enable(false)
  	@edtProfissao = Wx::TextCtrl.new(self, 
      ID_FRMCADCLIENTES_EDTPROFISSAO, "", Wx::Point.new(88, 376), Wx::Size.new(240, 21) )
    @edtProfissao.enable(false)
    @btnPProfissao = Wx::Button.new(self, ID_FRMCADCLIENTES_BTNPPROFISSAO, 
      "...", Wx::Point.new(328, 376), Wx::Size.new(21, 21))
    @btnPProfissao.enable(false)
    evt_button(ID_FRMCADCLIENTES_BTNPPROFISSAO) {|event| OnBtnPProfissaoClick(event)}

    IniciaBotoes() 
    @btnPesquisar.set_dimensions(440, 8, 75, 25)
    @btnAnterior.set_dimensions(440, 40, 75, 25)
    @btnProximo.set_dimensions(440, 72, 75, 25)
    @btnSalvar.set_dimensions(200, 408, 75, 25)
    @btnExcluir.set_dimensions(280, 408, 75, 25)
    @btnLimpar.set_dimensions(360, 408, 75, 25)
    @btnFechar.set_dimensions(440, 408, 75, 25)

    FazLayout()
  
  	@edtCodigo.set_max_length(14)
    @edtDescricao.set_max_length(30)
    @edtEmail.set_max_length(30)
    @edtIdentidade.set_max_length(10)
    @edtCodEndereco.set_max_length(10)
    @edtTelefone.set_max_length(17)
    @edtCodPais.set_max_length(3)
    @edtCodProfissao.set_max_length(10)

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
    sizer_16 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_23 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_22 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_19 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_15 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_21 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_20 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_18 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_11 = Wx::StaticBoxSizer.new(
      Wx::StaticBox.new(self, -1, "Endereço"), Wx::VERTICAL)
    sizer_14 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_17 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_16 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_15 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_13 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_14 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_13 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_12 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_10 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_12 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_11 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_6 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_5 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_4 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_8 = Wx::BoxSizer.new(Wx::HORIZONTAL)
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
    sizer_5.add(sizer_8, 1, Wx::EXPAND, 0)
    grid_sizer_4.add(@labEmail, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_4.add(@edtEmail, 0, 0, 0)
    sizer_6.add(grid_sizer_4, 0, 0, 0)
    grid_sizer_5.add(@labIdentidade, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_5.add(@edtIdentidade, 0, 0, 0)
    sizer_6.add(grid_sizer_5, 0, Wx::DIRECTION_LEFT, 4)
    sizer_5.add(sizer_6, 0, 0, 0)
    sizer_10.add(@rbSexo, 0, 0, 0)
    grid_sizer_11.add(@labTelefone, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_11.add(@edtTelefone, 0, 0, 0)
    sizer_10.add(grid_sizer_11, 1, Wx::DIRECTION_LEFT|Wx::EXPAND, 4)
    grid_sizer_12.add(@labDtNasc, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_12.add(@edtDtNasc, 0, 0, 0)
    sizer_10.add(grid_sizer_12, 1, Wx::DIRECTION_LEFT|Wx::EXPAND, 4)
    sizer_5.add(sizer_10, 1, Wx::EXPAND, 0)
    sizer_12.add(@edtCodEndereco, 0, 0, 0)
    sizer_12.add(@btnPEndereco, 0, 0, 0)
    sizer_11.add(sizer_12, 0, Wx::ALL, 2)
    grid_sizer_13.add(@labLogradouro, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_13.add(@edtLogradouro, 0, 0, 0)
    sizer_13.add(grid_sizer_13, 0, 0, 0)
    grid_sizer_14.add(@labBairro, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_14.add(@edtBairro, 0, 0, 0)
    sizer_13.add(grid_sizer_14, 0, Wx::DIRECTION_LEFT, 4)
    sizer_11.add(sizer_13, 0, 0, 0)
    grid_sizer_15.add(@labCEP, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_15.add(@edtCEP, 0, 0, 0)
    sizer_14.add(grid_sizer_15, 0, 0, 0)
    grid_sizer_16.add(@labCidade, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_16.add(@edtCidade, 0, 0, 0)
    sizer_14.add(grid_sizer_16, 0, Wx::DIRECTION_LEFT, 4)
    grid_sizer_17.add(@labEstado, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_17.add(@edtEstado, 0, 0, 0)
    sizer_14.add(grid_sizer_17, 0, Wx::DIRECTION_LEFT, 4)
    sizer_11.add(sizer_14, 1, 0, 0)
    sizer_5.add(sizer_11, 0, 0, 0)
    grid_sizer_18.add(@labPais, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_18.add(@edtCodPais, 0, 0, 0)
    sizer_15.add(grid_sizer_18, 0, 0, 0)
    grid_sizer_20.add(20, 20, 0, 0, 0)
    grid_sizer_20.add(@edtPais, 0, 0, 0)
    sizer_15.add(grid_sizer_20, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_21.add(20, 20, 0, 0, 0)
    grid_sizer_21.add(@btnPPais, 0, 0, 0)
    sizer_15.add(grid_sizer_21, 0, 0, 0)
    sizer_5.add(sizer_15, 0, 0, 0)
    grid_sizer_19.add(@labProfissao, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_19.add(@edtCodProfissao, 0, 0, 0)
    sizer_16.add(grid_sizer_19, 0, 0, 0)
    grid_sizer_22.add(20, 20, 0, 0, 0)
    grid_sizer_22.add(@edtProfissao, 0, 0, 0)
    sizer_16.add(grid_sizer_22, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_23.add(20, 20, 0, 0, 0)
    grid_sizer_23.add(@btnPProfissao, 0, 0, 0)
    sizer_16.add(grid_sizer_23, 0, 0, 0)
    sizer_5.add(sizer_16, 0, 0, 0)
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
    sizer_1.add(sizer_2, 0, Wx::DIRECTION_RIGHT|
      Wx::DIRECTION_BOTTOM|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 4)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(
      @edtCodigo.get_value(), Resource::STR_CPFNINF) then
      return false
    end
    if bTodosDados then
  	  if $Rotinas.ValidaCampo(
        @edtDescricao.get_value(), Resource::STR_CLININF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtEmail.get_value(), Resource::STR_EMAILNINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtTelefone.get_value(), Resource::STR_TELNINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtCodEndereco.get_value(), Resource::STR_ENDNINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtCodPais.get_value(), Resource::STR_PAISNINF) then
    		return false
      end
  	  if $Rotinas.ValidaCampo(
        @edtCodProfissao.get_value(), Resource::STR_PROFNINF) then
    		return false
      end
    end
    return true
  end

  def OnBtnNovoClick(event)
    self.btnNovoClick()
    self.InformaLimpaDadosLocal(false)
    self.HabilitaDadosLocal(true)
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    if self.PesquisarDados($ConsSQL.Cliente('S', 
      @edtCodigo.get_value(),"","","","","","","","",""), 
      Resource::STR_CLINENC) then
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
    if @rbSexo.get_string_selection() == "Masculino" then
       sSexo = "M"
    else
       sSexo = "F"
    end
    sDtNasc = $Rotinas.ConverteDataHoraStr(
      @edtDtNasc.get_value(), true, '%Y/%m/%d', '')
  
    sSqlUpdate = $ConsSQL.Cliente('U', 
      @edtCodigo.get_value(), @edtDescricao.get_value(), 
      @edtEmail.get_value(),  @edtIdentidade.get_value(), sSexo,  
      @edtTelefone.get_value(), sDtNasc, 
      @edtCodEndereco.get_value(), 
      @edtCodPais.get_value(), @edtCodProfissao.get_value())
  
    sSqlInsert = $ConsSQL.Cliente('I', 
      @edtCodigo.get_value(), @edtDescricao.get_value(), 
      @edtEmail.get_value(),  @edtIdentidade.get_value(), sSexo,  
      @edtTelefone.get_value(), sDtNasc, 
      @edtCodEndereco.get_value(), 
      @edtCodPais.get_value(), @edtCodProfissao.get_value())
  
    if self.SalvarDados(self.ValidaDados(true),
      $ConsSQL.Cliente('S', @edtCodigo.get_value(),
      "","","","","","","","",""), sSqlUpdate, sSqlInsert, true) then
      self.InformaLimpaDadosLocal(false)
      self.HabilitaDadosLocal(false)
    end
    event.skip()
  end

  def OnBtnExcluirClick(event)
    if self.ExcluirDados(self.ValidaDados(false),
      $ConsSQL.Cliente('D', @edtCodigo.get_value(),
      "","","","","","","","","")) then
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
      @edtEmail.set_value(@lstRegistros.col[@nLinhaRegistro][2])
      @edtIdentidade.set_value(@lstRegistros.col[@nLinhaRegistro][3])
      if @lstRegistros.col[@nLinhaRegistro][4] == "M" then
        @rbSexo.set_selection(0)
      else
        @rbSexo.set_selection(1)
      end
      @edtTelefone.set_value(@lstRegistros.col[@nLinhaRegistro][5])
      @edtDtNasc.set_value(@lstRegistros.col[@nLinhaRegistro][6].slice(0,10))
      @edtCodEndereco.set_value(@lstRegistros.col[@nLinhaRegistro][7])
      @edtLogradouro.set_value(@lstRegistros.col[@nLinhaRegistro][8])
      @edtBairro.set_value(@lstRegistros.col[@nLinhaRegistro][9])
      @edtCEP.set_value(@lstRegistros.col[@nLinhaRegistro][10])
      @edtCidade.set_value(@lstRegistros.col[@nLinhaRegistro][11])
      @edtEstado.set_value(@lstRegistros.col[@nLinhaRegistro][12])
      @edtCodPais.set_value(@lstRegistros.col[@nLinhaRegistro][13])
      @edtPais.set_value(@lstRegistros.col[@nLinhaRegistro][14])
      @edtCodProfissao.set_value(@lstRegistros.col[@nLinhaRegistro][15])
      @edtProfissao.set_value(@lstRegistros.col[@nLinhaRegistro][16])
    else
      @edtEmail.clear()
      @edtIdentidade.clear()
      @rbSexo.set_selection(0)
      @edtTelefone.clear()
      @edtDtNasc.clear()
      @edtCodEndereco.clear()
      @edtLogradouro.clear()
      @edtBairro.clear()
      @edtCEP.clear()
      @edtCidade.clear()
      @edtEstado.clear()
      @edtCodPais.clear()
      @edtPais.clear()
      @edtCodProfissao.clear()
      @edtProfissao.clear()
      @edtCodigo.set_focus()
    end
  end

  def HabilitaDadosLocal(bHabilita)
    @edtEmail.enable(bHabilita)
    @edtIdentidade.enable(bHabilita)
    @rbSexo.enable(bHabilita)
    @edtTelefone.enable(bHabilita)
    @edtDtNasc.enable(bHabilita)
    @edtCodEndereco.enable(bHabilita)
    @btnPEndereco.enable(bHabilita)
    @edtCodPais.enable(bHabilita)
    @btnPPais.enable(bHabilita)
    @edtCodProfissao.enable(bHabilita)
    @btnPProfissao.enable(bHabilita)
  end

  def retLogradouro()
    return @edtLogradouro
  end   

  def retBairro()
    return @edtBairro
  end   

  def retCEP()
    return @edtCEP
  end   

  def retCidade()
    return @edtCidade
  end   

  def retEstado()
    return @edtEstado
  end   
   
  def OnBtnPEnderecoClick(event)
    fConEnderecos = FrmConEnderecos.new(self)
    fConEnderecos.show_modal()
    @edtCodEndereco.set_value($Rotinas.sCodigoSelecionado)
    @edtCodEndereco.on_killfocus(event)
    event.skip()
  end

  def retPais()
    return @edtPais
  end   

  def OnBtnPPaisClick(event)
    fConPaises = FrmConPaises.new(self)
    fConPaises.show_modal()
    @edtCodPais.set_value($Rotinas.sCodigoSelecionado)
    @edtCodPais.on_killfocus(event)
    event.skip()
  end

  def retProfissao()
    return @edtProfissao
  end   
  
  def OnBtnPProfissaoClick(event) 
    fConProfissoes = FrmConProfissoes.new(self)
    fConProfissoes.show_modal()
    @edtCodProfissao.set_value($Rotinas.sCodigoSelecionado)
    @edtCodProfissao.on_killfocus(event)
    event.skip()
  end

end

class FrmCadClientes_TextValidatorCtrl < TextValidatorCtrl

  def initialize(parent, id, valor, pos, size, estilo, nfiltro)
    super(parent, id, valor, pos, size, estilo, nfiltro)
    @local_id = id
    evt_kill_focus {|event| on_killfocus(event)}
  end

  def on_killfocus(event) 
    if @local_id == FrmCadClientes::ID_FRMCADASTROS_EDTCODIGO then
      if self.get_value().length > 0 then
      	if $Rotinas.validaCPF(self.get_value())==false then
          $Rotinas.MessageErro(Resource::STR_CPFINV)
          self.clear()
          self.set_focus()
        end
      end
    elsif @local_id == FrmCadClientes::ID_FRMCADCLIENTES_EDTDTNASC then
      if self.get_value().length() > 0 then
        if not $Rotinas.validaDataHora(self.get_value(), true) then
          $Rotinas.MessageErro(Resource::STR_DTHRINV)
          self.set_value($Rotinas.retDataHoraStr(true,false))
          self.set_focus()
        end
      else
        self.set_value($Rotinas.retDataHoraStr(true,false))
      end
    elsif @local_id == FrmCadClientes::ID_FRMCADCLIENTES_EDTCODENDERECO then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length > 0 then
        sLogradouro = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
        $ConsSQL.Endereco('S', self.get_value(),
        "","","","",""),Resource::STR_ENDNENC)
        if sLogradouro.length > 0 then
          $fCadClientes.retLogradouro().set_value(sLogradouro)
          $fCadClientes.retBairro().set_value(@ConsCampo.col[0][2])
          $fCadClientes.retCEP().set_value(@ConsCampo.col[0][3])
          $fCadClientes.retCidade().set_value(@ConsCampo.col[0][4])
          $fCadClientes.retEstado().set_value(@ConsCampo.col[0][5])
        else
      	  self.set_focus()
          $fCadClientes.retLogradouro().clear()
          $fCadClientes.retBairro().clear()
          $fCadClientes.retCEP().clear()
      	  $fCadClientes.retCidade().clear()
      	  $fCadClientes.retEstado().clear()
        end
      else
        $fCadClientes.retLogradouro().clear()
        $fCadClientes.retBairro().clear()
        $fCadClientes.retCEP().clear()
        $fCadClientes.retCidade().clear()
        $fCadClientes.retEstado().clear()
      end
    elsif @local_id == FrmCadClientes::ID_FRMCADCLIENTES_EDTCODPAIS then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length() > 0 then
        sPais = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
          $ConsSQL.Pais('S', self.get_value(),""),Resource::STR_PAISNENC)
        if sPais.length() > 0 then
          $fCadClientes.retPais().set_value(sPais)
        else
          self.clear()
          self.set_focus()
        end
      else
        $fCadClientes.retPais().clear()
      end    
    elsif @local_id == FrmCadClientes::ID_FRMCADCLIENTES_EDTCODPROFISSAO then
      @ConsCampo = LISTAMSTR.new
  
      if self.get_value().length > 0 then
        sProfissao = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
          $ConsSQL.Profissao('S',
          self.get_value(),""),Resource::STR_PROFNENC)
        if sProfissao.length > 0 then
          $fCadClientes.retProfissao().set_value(sProfissao)
        else
          self.clear()
          self.set_focus()
        end
      else
        $fCadClientes.retProfissao().clear()
      end
    end
    event.skip
  end
end

