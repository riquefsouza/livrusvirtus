require 'wxruby'
require 'TextValidatorCtrl'
require 'ListaStr'
require 'resource'
require 'RotinasGlobais'

class FrmCadastros < Wx::Panel
  ID_FRMCADASTROS_BTNANTERIOR, ID_FRMCADASTROS_BTNEXCLUIR, 
  ID_FRMCADASTROS_BTNFECHAR, ID_FRMCADASTROS_BTNLIMPAR, 
  ID_FRMCADASTROS_BTNNOVO, ID_FRMCADASTROS_BTNPESQUISAR, 
  ID_FRMCADASTROS_BTNPROXIMO, ID_FRMCADASTROS_BTNSALVAR, 
  ID_FRMCADASTROS_EDTCODIGO, ID_FRMCADASTROS_EDTDESCRICAO, 
  ID_FRMCADASTROS_LABCODIGO, ID_FRMCADASTROS_LABDESCRICAO =
  3000,3001,3002,3003,3004,3005,3006,3007,3008,3009,3010,3011,3012

  def initialize(parent, nFiltroCodigo, bIniciaBotoes)
    super(parent, -1, Wx::Point.new(398, 295), 
      Wx::Size.new(338, 163), Wx::TAB_TRAVERSAL,"") 
    set_client_size(Wx::Size.new(330, 136))
    evt_close {|event| on_close(event)}

	  @labCodigo = Wx::StaticText.new(self, ID_FRMCADASTROS_LABCODIGO, 
      "Código:", Wx::Point.new(8, 8), Wx::Size.new(36, 13) )
  	@edtCodigo = TextValidatorCtrl.new(self, ID_FRMCADASTROS_EDTCODIGO, "", 
      Wx::Point.new(8, 24), Wx::Size.new(121, 21), 0, nFiltroCodigo )

    @edtCodigo.set_max_length(10)
		@btnNovo = Wx::Button.new(self, ID_FRMCADASTROS_BTNNOVO, "&Novo",
      Wx::Point.new(144, 24), Wx::Size.new(75, 25) )
	  @labDescricao = Wx::StaticText.new(self, ID_FRMCADASTROS_LABDESCRICAO, 
      "Descrição:", Wx::Point.new(8, 48), Wx::Size.new(51, 13) )
	  @edtDescricao = Wx::TextCtrl.new(self, ID_FRMCADASTROS_EDTDESCRICAO, "", 
      Wx::Point.new(8, 64), Wx::Size.new(217, 21) )
    @edtDescricao.enable(false)
    @edtDescricao.set_max_length(30)

    if bIniciaBotoes then
      IniciaBotoes()
      FazLayout()
    end

    @lstRegistros = LISTAMSTR.new
    @nLinhaRegistro = 0    
  end

  def IniciaBotoes()
		@btnPesquisar = Wx::Button.new(self, ID_FRMCADASTROS_BTNPESQUISAR, 
      "&Pesquisar", Wx::Point.new(248, 8), Wx::Size.new(75, 25) )
		@btnAnterior = Wx::Button.new(self, ID_FRMCADASTROS_BTNANTERIOR, 
      "&Anterior", Wx::Point.new(248, 40), Wx::Size.new(75, 25) )
    @btnAnterior.enable(false)
		@btnProximo = Wx::Button.new(self, ID_FRMCADASTROS_BTNPROXIMO, 
      "Próxi&mo", Wx::Point.new(248, 72), Wx::Size.new(75, 25) )
    @btnProximo.enable(false)
		@btnSalvar = Wx::Button.new(self, ID_FRMCADASTROS_BTNSALVAR, 
      "&Salvar", Wx::Point.new(8, 104), Wx::Size.new(75, 25) )
    @btnSalvar.enable(false)
		@btnExcluir = Wx::Button.new(self, ID_FRMCADASTROS_BTNEXCLUIR, 
      "&Excluir", Wx::Point.new(88, 104), Wx::Size.new(75, 25) )
    @btnExcluir.enable(false)
		@btnLimpar = Wx::Button.new(self, ID_FRMCADASTROS_BTNLIMPAR, 
      "&Limpar", Wx::Point.new(168, 104), Wx::Size.new(75, 25) )
		@btnFechar = Wx::Button.new(self, ID_FRMCADASTROS_BTNFECHAR, 
      "&Fechar", Wx::Point.new(248, 104), Wx::Size.new(75, 25) )
    self.btnLimparClick()
  end

  def FazLayout()
    sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_3 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_4 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_5 = Wx::BoxSizer.new(Wx::VERTICAL)
    grid_sizer_2 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_1 = Wx::GridSizer.new(2, 2, 0, 1)
    grid_sizer_1.add(@labCodigo, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_1.add(20, 10, 0, 0, 0)
    grid_sizer_1.add(@edtCodigo, 0, 0, 0)
    grid_sizer_1.add(@btnNovo, 0, Wx::DIRECTION_LEFT, 6)
    sizer_5.add(grid_sizer_1, 0, 0, 0)
    grid_sizer_2.add(@labDescricao, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_2.add(@edtDescricao, 0, 0, 2)
    sizer_5.add(grid_sizer_2, 0, 0, 0)
    sizer_3.add(sizer_5, 1, 0, 0)
    sizer_4.add(@btnPesquisar, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_4.add(@btnAnterior, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_4.add(@btnProximo, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_3.add(sizer_4, 0, Wx::ALIGN_RIGHT, 0)
    sizer_1.add(sizer_3, 1, Wx::ALL|Wx::EXPAND, 4)
    sizer_2.add(@btnSalvar, 0, Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_2.add(@btnExcluir, 0, Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_2.add(@btnLimpar, 0, Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_2.add(@btnFechar, 0, Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_1.add(sizer_2, 0, Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 4)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
  end

  def InformaLimpaDados(bInformar)
    if bInformar then
      @edtCodigo.set_value(@lstRegistros.col[@nLinhaRegistro][0])
      @edtDescricao.set_value(@lstRegistros.col[@nLinhaRegistro][1])
    else
      @edtCodigo.clear()
      @edtDescricao.clear()
      @edtCodigo.enable(true)
      @edtCodigo.set_focus()
    end
  end

  def HabilitaDados(bHabilita)
    @edtDescricao.enable(bHabilita)
  end

  def btnNovoClick()
    @btnSalvar.enable(true)
    @btnExcluir.enable(false)
    @btnPesquisar.enable(false)
    @btnAnterior.enable(false)
    @btnProximo.enable(false)
    @btnNovo.enable(false)
    
    @nLinhaRegistro = 0
    self.InformaLimpaDados(false)
    self.HabilitaDados(true)	
  end

  def NovoDado(sTextoSql)
    lstRegs = LISTAMSTR.new
  
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, lstRegs, sTextoSql) then
      @edtCodigo.set_value(lstRegs.col[0][0])
      @edtCodigo.enable(false)
      @edtDescricao.set_focus()
    end
  end

  def btnLimparClick()
    @nLinhaRegistro = 0
    @btnSalvar.enable(false)
    @btnExcluir.enable(false)
    @btnPesquisar.enable(true)
    @btnAnterior.enable(false)
    @btnProximo.enable(false)
    @btnNovo.enable(true)
  
    self.InformaLimpaDados(false)
    self.HabilitaDados(false)	
  end

  def ExcluirDados(bValidaDados, sTextoSql)
    if bValidaDados then
      mens = Wx::MessageDialog.new(self, Resource::STR_CERTEXCL, 
        "Confirme", Wx::YES_NO | Wx::ICON_QUESTION)
      if mens.show_modal() == Wx::ID_YES then
        if $Rotinas.AtualizaDados($Rotinas.gConexao, sTextoSql) then
          self.btnLimparClick()
          return true
        end
      end
    end
    return false
  end

  def PesquisarDados(sTextoSql, sMensagemErro)
    if @edtCodigo.get_value().length == 0 then
      @btnAnterior.enable(true)
      @btnProximo.enable(true)
    end
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, 
        @lstRegistros, sTextoSql) then
       self.InformaLimpaDados(true)
       self.HabilitaDados(true)	
  
       @btnSalvar.enable(true)
       @btnExcluir.enable(true)
       @btnPesquisar.enable(false)
       return true
    else
      $Rotinas.MessageErro(sMensagemErro)
    end  
    return false
  end

  def registroAnterior()
    if @nLinhaRegistro > 0 then
      @nLinhaRegistro = @nLinhaRegistro - 1
      self.InformaLimpaDados(true)
      return true
    else
      return false
    end
  end

  def registroProximo()
    if @nLinhaRegistro < (@lstRegistros.tam-1) then
      @nLinhaRegistro = @nLinhaRegistro + 1
      self.InformaLimpaDados(true)
      return true
    else
      return false
    end
  end

  def SalvarDados(bValidaDados, sTextoSql, 
    sTextoUpdate, sTextoInsert, bLimparDados)

    if bValidaDados then
      if $Rotinas.ConsultaDados($Rotinas.gConexao, sTextoSql) then
        sArquiva = sTextoUpdate
      else
        sArquiva = sTextoInsert
      end
      if $Rotinas.AtualizaDados($Rotinas.gConexao, sArquiva) then
        if bLimparDados then
          self.btnLimparClick()
        end
        return true
      end  
    end
    return false
  end

  def on_close(event)
    self.destroy
  end

end

