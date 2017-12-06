require 'wxruby'
require 'resource'
require 'RotinasGlobais'
require 'ListaStr'
require 'Principal'

class FrmConsultas < Wx::Dialog
  ID_FRMCONSULTAS_BTNFECHAR, ID_FRMCONSULTAS_BTNLIMPAR, 
  ID_FRMCONSULTAS_BTNPESQUISAR, ID_FRMCONSULTAS_EDTDESCRICAO, 
  ID_FRMCONSULTAS_GRIDCONSULTA, ID_FRMCONSULTAS_LABDESCRICAO, 
  ID_FRMCONSULTAS_LABREGISTRO, ID_FRMCONSULTAS_PANEL1, 
  ID_FRMCONSULTAS_PANEL2, ID_FRMCONSULTAS_SCROLLEDWINDOW1 = 
  8000,8001,8002,8003,8004,8005,8006,8007,8008,8009

  def initialize(parent)
    super(parent, -1, Wx::Point.new(0, 0), 
      Wx::Size.new(355, 263), Wx::DEFAULT_DIALOG_STYLE | 
      Wx::CAPTION | Wx::RESIZE_BORDER | Wx::MINIMIZE_BOX | Wx::MAXIMIZE_BOX, "") 
    set_client_size(Wx::Size.new(355, 263))
    centre(Wx::BOTH)
    evt_close {|event| on_close(event)}
  
  	@labDescricao = Wx::StaticText.new(self, ID_FRMCONSULTAS_LABDESCRICAO, 
      "Descrição:", Wx::Point.new(8, 8), Wx::Size.new(51, 13) )
  	@edtDescricao = Wx::TextCtrl.new(self, ID_FRMCONSULTAS_EDTDESCRICAO, 
      "", Wx::Point.new(8, 24), Wx::Size.new(257, 21) )
  	@btnPesquisar = Wx::Button.new(self, ID_FRMCONSULTAS_BTNPESQUISAR, 
      "&Pesquisar", Wx::Point.new(272, 24), Wx::Size.new(75, 25) )
  	@gridConsulta = Wx::Grid.new(self, ID_FRMCONSULTAS_GRIDCONSULTA,
      Wx::Point.new(0, 56), Wx::Size.new(355, 125), Wx::SUNKEN_BORDER)
    @gridConsulta.create_grid(1, 2)
    @gridConsulta.set_col_label_value(0, 'Código')
    @gridConsulta.set_col_size(0, 80)
    @gridConsulta.set_col_label_value(1, 'Descrição')
    @gridConsulta.set_col_size(1, 180)
    @gridConsulta.enable_editing(false)
    @gridConsulta.hide_cell_edit_control()
    @gridConsulta.set_col_label_size(21)
  	@labRegistro = Wx::StaticText.new(self, ID_FRMCONSULTAS_LABREGISTRO, 
      "Registro 0 de 0", Wx::Point.new(8, 16), Wx::Size.new(144, 13) )
  	@btnLimpar = Wx::Button.new(self, ID_FRMCONSULTAS_BTNLIMPAR, 
      "&Limpar", Wx::Point.new(188, 13), Wx::Size.new(75, 25) )
  	@btnFechar = Wx::Button.new(self, ID_FRMCONSULTAS_BTNFECHAR, 
      "&Fechar", Wx::Point.new(268, 13), Wx::Size.new(75, 25) )
    evt_button(ID_FRMCONSULTAS_BTNFECHAR) {|event| OnBtnFecharClick(event)}

    FazLayout()

    @edtDescricao.set_focus()

    @lstLinhas = LISTAMSTR.new
    @sSelecionado = ''
    @nRegistro = 0
  end

  def FazLayout()
    sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
    grid_sizer_2 = Wx::GridSizer.new(1, 2, 0, 0)
    sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_3 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_4 = Wx::BoxSizer.new(Wx::VERTICAL)
    grid_sizer_1 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_1.add(@labDescricao, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_1.add(@edtDescricao, 0, 0, 0)
    sizer_3.add(grid_sizer_1, 0, Wx::ALL, 2)
    sizer_4.add(20, 20, 0, 0, 0)
    sizer_4.add(@btnPesquisar, 0, Wx::DIRECTION_LEFT|
      Wx::DIRECTION_TOP|Wx::DIRECTION_BOTTOM, 5)
    sizer_3.add(sizer_4, 0, 0, 0)
    sizer_1.add(sizer_3, 0, Wx::ALL, 4)
    sizer_1.add(@gridConsulta, 1, Wx::EXPAND, 0)
    grid_sizer_2.add(@labRegistro, 0, Wx::ALL, 10)
    sizer_2.add(@btnLimpar, 0, Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 8)
    sizer_2.add(@btnFechar, 0, 
      Wx::DIRECTION_LEFT|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 8)
    grid_sizer_2.add(sizer_2, 1, 
      Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 4)
    sizer_1.add(grid_sizer_2, 0, Wx::ALL|Wx::EXPAND|Wx::ALIGN_BOTTOM, 0)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
    self.layout()
  end

  def on_close(event)
    self.destroy()
  end

  def OnBtnFecharClick(event)
    self.Close(true)
  end

  def Fecha(nIndMenu)
    if @sSelecionado.length > 0 then
      $Rotinas.sCodigoSelecionado = @sSelecionado
    else
      $Rotinas.sCodigoSelecionado = ""
    end
    if nIndMenu == 0 then
      #if self.is_modal() then
      #  self.end_modal(true)
      #else
        self.close()
      #end
    else
      $fPrincipal.retMenu(1).enable(nIndMenu, true)
    end
  end

  def LimparDados()
    @labRegistro.set_label("Registro 0 de 0")
    @gridConsulta.clear_grid()
    @gridConsulta.delete_rows(0, @gridConsulta.get_number_rows()-1, true)
    @edtDescricao.clear()
    @edtDescricao.set_focus()
  end

  def PesquisarDados(sTextoSql, sMensagemErro, nQtdCol)
    if $Rotinas.ConsultaDadosLista(
      $Rotinas.gConexao, @lstLinhas, sTextoSql) then
      $Rotinas.AdicionaLinhasGrid(@gridConsulta, @lstLinhas, nQtdCol)
    else
      $Rotinas.MessageErro(sMensagemErro)
    end
  end

  def setLabRegistros(nLinha)
    if nLinha >= 0 then
      @labRegistro.set_label("Registro " + (nLinha+1).to_s + " de " +
        (@gridConsulta.get_number_rows()).to_s)
      @sSelecionado = @gridConsulta.get_cell_value(nLinha, 0)
    end
  end
end

