require 'wxruby'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'resource'
require 'ListaStr'
require 'ConClientes'
require 'ConLivros'

$fConVendas = nil

class FrmConVendas < Wx::Panel
  ID_FRMCONVENDAS_BTNFECHAR, ID_FRMCONVENDAS_BTNLIMPAR, 
  ID_FRMCONVENDAS_BTNPCLIENTE, ID_FRMCONVENDAS_BTNPESQUISAR, 
  ID_FRMCONVENDAS_BTNPLIVRO, ID_FRMCONVENDAS_EDTCLIENTE, 
  ID_FRMCONVENDAS_EDTCPF, ID_FRMCONVENDAS_EDTDTHRVENDA, 
  ID_FRMCONVENDAS_EDTISBN, ID_FRMCONVENDAS_EDTLIVRO, 
  ID_FRMCONVENDAS_EDTPRECOTOTAL, ID_FRMCONVENDAS_GRIDVENDAS, 
  ID_FRMCONVENDAS_LABCLIENTE, ID_FRMCONVENDAS_LABCPF, 
  ID_FRMCONVENDAS_LABDTHRVENDA, ID_FRMCONVENDAS_LABISBN, 
  ID_FRMCONVENDAS_LABLIVRO, ID_FRMCONVENDAS_LABPRECOTOTAL, 
  ID_FRMCONVENDAS_LABREGISTRO = 
  9100,9101,9102,9103,9104,9105,9106,9107,9108,9109,9110,
  9111,9112,9113,9114,9115,9116,9117,9118,9119

  def initialize(parent)
    super(parent, -1, Wx::Point.new(379, 218), 
      Wx::Size.new(480, 310), Wx::TAB_TRAVERSAL, "") 
    set_client_size(Wx::Size.new(475, 306))
    evt_close {|event| on_close(event)}

    @labDtHrVenda = Wx::StaticText.new(self, 
      ID_FRMCONVENDAS_LABDTHRVENDA, "Data/Hora Venda: ", 
      Wx::Point.new(8, 8), Wx::Size.new(91, 13) )
    @edtDtHrVenda = FrmConVendas_TextValidatorCtrl.new(self, 
      ID_FRMCONVENDAS_EDTDTHRVENDA, "", Wx::Point.new(8, 24), 
      Wx::Size.new(128, 21), 0, TextValidatorCtrl::FILTER_NONE )
    evt_kill_focus {|event| OnEdtDtHrVendaKillfocus(event)}
    @btnPesquisar = Wx::Button.new(self, ID_FRMCONVENDAS_BTNPESQUISAR, 
      "&Pesquisar", Wx::Point.new(144, 22), Wx::Size.new(75, 25))
    @labCPF = Wx::StaticText.new(self, ID_FRMCONVENDAS_LABCPF, "CPF: ", 
      Wx::Point.new(8, 48), Wx::Size.new(23, 13) )
    @edtCPF = FrmConVendas_TextValidatorCtrl.new(self, ID_FRMCONVENDAS_EDTCPF, 
      "", Wx::Point.new(8, 64), Wx::Size.new(128, 21), 
      0, TextValidatorCtrl::FILTER_NONE )
    @labCliente = Wx::StaticText.new(self, 
      ID_FRMCONVENDAS_LABCLIENTE, "Cliente: ", 
      Wx::Point.new(142, 48), Wx::Size.new(35, 13) )
    @edtCliente = Wx::TextCtrl.new(self, ID_FRMCONVENDAS_EDTCLIENTE, 
      "", Wx::Point.new(142, 64), Wx::Size.new(306, 21) )
    @edtCliente.enable(false)
    @btnPCliente = Wx::Button.new(self, ID_FRMCONVENDAS_BTNPCLIENTE, 
      "...", Wx::Point.new(448, 64), Wx::Size.new(21, 21))
    evt_button(ID_FRMCONVENDAS_BTNPCLIENTE) {|event| OnBtnPClienteClick(event)}
    @labISBN = Wx::StaticText.new(self, ID_FRMCONVENDAS_LABISBN, 
      "ISBN: ", Wx::Point.new(8, 88), Wx::Size.new(31, 13) )
    @edtISBN = FrmConVendas_TextValidatorCtrl.new(self, 
      ID_FRMCONVENDAS_EDTISBN, "", Wx::Point.new(8, 104), 
      Wx::Size.new(128, 21), 0, TextValidatorCtrl::FILTER_NONE )
    evt_kill_focus {|event| OnEdtISBNKillfocus(event)}
    @labLivro = Wx::StaticText.new(self, ID_FRMCONVENDAS_LABLIVRO, 
      "Livro: ", Wx::Point.new(142, 82), Wx::Size.new(29, 13) )
    @edtLivro = Wx::TextCtrl.new(self, ID_FRMCONVENDAS_EDTLIVRO, 
      "", Wx::Point.new(142, 104), Wx::Size.new(306, 21) )
    @edtLivro.enable(false)
    @btnPLivro = Wx::Button.new(self, ID_FRMCONVENDAS_BTNPLIVRO, 
      "...", Wx::Point.new(448, 104), Wx::Size.new(21, 21))
    evt_button(ID_FRMCONVENDAS_BTNPLIVRO) {|event| OnBtnPLivroClick(event)}
    @gridVendas = Wx::Grid.new(self, ID_FRMCONVENDAS_GRIDVENDAS, 
      Wx::Point.new(0, 136), Wx::Size.new(472, 104), Wx::SUNKEN_BORDER)
    @gridVendas.create_grid(1, 6)
    @gridVendas.hide_cell_edit_control()
    @gridVendas.set_col_label_size(21)
    evt_grid_select_cell {|event| OnGridSelectCell(event)}
    evt_grid_label_left_click {|event| OnGridLabelLeftClick(event)}
    @labRegistro = Wx::StaticText.new(self, 
      ID_FRMCONVENDAS_LABREGISTRO, "Registro 0 de 0", 
      Wx::Point.new(8, 248), Wx::Size.new(144, 13) )
    @labPrecoTotal = Wx::StaticText.new(self, 
      ID_FRMCONVENDAS_LABPRECOTOTAL, "Preço Total: ", 
      Wx::Point.new(280, 248), Wx::Size.new(61, 13) )
    @edtPrecoTotal = Wx::TextCtrl.new(self, ID_FRMCONVENDAS_EDTPRECOTOTAL, 
      "", Wx::Point.new(344, 246), Wx::Size.new(127, 21) )
    @edtPrecoTotal.enable(false)
    @btnLimpar = Wx::Button.new(self, ID_FRMCONVENDAS_BTNLIMPAR, 
      "&Limpar", Wx::Point.new(312, 272), Wx::Size.new(75, 25))
    @btnFechar = Wx::Button.new(self, ID_FRMCONVENDAS_BTNFECHAR, 
      "&Fechar", Wx::Point.new(392, 272), Wx::Size.new(75, 25))

    FazLayout()

    evt_button(ID_FRMCONVENDAS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCONVENDAS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCONVENDAS_BTNFECHAR) {|event| OnBtnFecharClick(event)}

    nLargura = [ 120, 100, 220, 100, 280, 80 ]
    sRotulos = [ "Data/Hora Venda", "CPF", "Cliente", 
     "ISBN", "Livro", "Preço" ]
  
    $Rotinas.AdicionaColunasGrid(@gridVendas, 0, 6, nLargura, sRotulos)
    @gridVendas.enable_editing(false)
    @edtCPF.set_max_length(14)
    @edtISBN.set_max_length(13)  
    @edtPrecoTotal.set_value("R$ 0,00")
    @edtDtHrVenda.set_value($Rotinas.retDataHoraStr(true,true))
    @edtDtHrVenda.set_focus()

    @lstLinhas = LISTAMSTR.new
  end

  def FazLayout()
    sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_6 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_22 = Wx::GridSizer.new(1, 2, 0, 0)
    sizer_23 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_8 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_7 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_24 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_4 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_8 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_6 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_5 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_3 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_4 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_3 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_2 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_2 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_1 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_1.add(@labDtHrVenda, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_1.add(@edtDtHrVenda, 0, 0, 0)
    sizer_2.add(grid_sizer_1, 0, Wx::DIRECTION_LEFT, 2)
    sizer_2.add(@btnPesquisar, 0, 
      Wx::DIRECTION_LEFT|Wx::DIRECTION_TOP|Wx::ALIGN_BOTTOM, 10)
    sizer_1.add(sizer_2, 0, 0, 0)
    grid_sizer_2.add(@labCPF, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_2.add(@edtCPF, 0, 0, 0)
    sizer_3.add(grid_sizer_2, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_3.add(@labCliente, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_3.add(@edtCliente, 0, 0, 0)
    sizer_3.add(grid_sizer_3, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_4.add(20, 20, 0, 0, 0)
    grid_sizer_4.add(@btnPCliente, 0, 0, 0)
    sizer_3.add(grid_sizer_4, 0, 0, 0)
    sizer_1.add(sizer_3, 0, 0, 0)
    grid_sizer_5.add(@labISBN, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_5.add(@edtISBN, 0, 0, 0)
    sizer_4.add(grid_sizer_5, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_6.add(@labLivro, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_6.add(@edtLivro, 0, 0, 0)
    sizer_4.add(grid_sizer_6, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_8.add(20, 20, 0, 0, 0)
    grid_sizer_8.add(@btnPLivro, 0, 0, 0)
    sizer_4.add(grid_sizer_8, 0, 0, 0)
    sizer_1.add(sizer_4, 0, 0, 0)
    sizer_1.add(@gridVendas, 1, Wx::ALL|Wx::EXPAND, 2)
    sizer_24.add(@labRegistro, 0, Wx::ALL, 4)
    sizer_24.add(20, 20, 0, 0, 0)
    sizer_22.add(sizer_24, 0, 0, 0)
    sizer_7.add(@labPrecoTotal, 0, Wx::ALL, 2)
    sizer_7.add(@edtPrecoTotal, 0, Wx::ALL, 2)
    sizer_23.add(sizer_7, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_8.add(@btnLimpar,0,Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_8.add(@btnFechar,0,Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_23.add(sizer_8, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_22.add(sizer_23, 1, Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 0)
    sizer_6.add(sizer_22, 0, Wx::EXPAND, 0)
    sizer_1.add(sizer_6, 0, Wx::EXPAND, 0)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
  end

  def ConsVenda(sOpcao)
    sret = ''

    if @edtDtHrVenda.get_value().length > 0 then
      sDataHora = $Rotinas.ConverteDataHoraStr(
        @edtDtHrVenda.get_value(), true, "%m/%d/%Y","%H:%M:%S")
    else
      sDataHora = ""
    end
    sISBN = @edtISBN.get_value()
    sCPF = @edtCPF.get_value()
  
    if sOpcao=='L' then
      sret = $ConsSQL.Venda('S',"ZERO","","","","")
    else
      sret = $ConsSQL.Venda(sOpcao, sISBN, sCPF, sDataHora, "", "")
    end
    return sret
  end

  def OnBtnPesquisarClick(event)
    @ConsTotal = LISTAMSTR.new 
  
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, 
      @lstLinhas, self.ConsVenda('S')) then
      $Rotinas.AdicionaLinhasGrid(@gridVendas, @lstLinhas, 6)
  
      if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, @ConsTotal, 
         self.ConsVenda('P')) then
        if @ConsTotal.col.length > 0 then
          nTemp = @ConsTotal.col[0][0].to_f
          sPrecoTotal = "R$ " + nTemp.to_s
          @edtPrecoTotal.set_value(sPrecoTotal)
        end
      end
    else
      $Rotinas.MessageErro(Resource::STR_VENNENC)
    end
    event.skip()
  end 
 
  def retLivro()
    return @edtLivro
  end   
  
  def OnBtnPLivroClick(event)
    fConLivros = FrmConLivros.new(self)
    fConLivros.show_modal()
    @edtISBN.set_value($Rotinas.sCodigoSelecionado)
    @edtISBN.on_killfocus(event)
    event.skip()
  end

  def retCliente()
    return @edtCliente
  end   
  
  def OnBtnPClienteClick(event)
    fConClientes = FrmConClientes.new(self)
    fConClientes.show_modal()
    @edtCPF.set_value($Rotinas.sCodigoSelecionado)
    @edtCPF.on_killfocus(event)
    event.skip()
  end
  
  def setLabRegistros(nLinha)
    if nLinha >= 0 then
      @labRegistro.set_label("Registro " + (nLinha+1).to_s + " de " +
        @gridVendas.get_number_rows().to_s)
    end
  end

  def OnGridSelectCell(event)
    self.setLabRegistros(event.get_row())
    event.skip()
  end
  
  def OnGridLabelLeftClick(event)
    self.setLabRegistros(event.get_row())
    event.skip()
  end

  def OnBtnLimparClick(event)
    @edtCPF.clear()
    @edtCliente.clear()
    @edtISBN.clear()
    @edtLivro.clear()
    @gridVendas.clear_grid()
    @gridVendas.delete_rows(0, @gridVendas.get_number_rows()-1,true)
    @edtPrecoTotal.set_value("R$ 0,00")
    @edtDtHrVenda.set_value($Rotinas.retDataHoraStr(true,true))
    @edtDtHrVenda.set_focus()
    event.skip()
  end

  def OnBtnFecharClick(event)
    self.get_parent().close()
    event.skip()
  end 

  def on_close(event)
    self.destroy()
  end
end

class FrmConVendas_TextValidatorCtrl < TextValidatorCtrl

  def initialize(parent, id, valor, pos, size, estilo, nfiltro)
    super(parent, id, valor, pos, size, estilo, nfiltro)
    @local_id = id
    evt_kill_focus {|event| on_killfocus(event)}
  end

  def on_killfocus(event)     
    if @local_id == FrmConVendas::ID_FRMCONVENDAS_EDTDTHRVENDA then
      if self.get_value().length > 0 then
        if not $Rotinas.validaDataHora(self.get_value(), false) then
          $Rotinas.MessageErro(Resource::STR_DTHRINV)
          self.set_focus()
        end
      end
    elsif @local_id == FrmConVendas::ID_FRMCONVENDAS_EDTCPF then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length() > 0 then
        if $Rotinas.validaCPF(self.get_value()) then
          sCliente = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
            $ConsSQL.Cliente('S', self.get_value(),
            "","","","","","","","",""), Resource::STR_CLINENC)
          if sCliente.length() == 0 then
            self.clear()
            self.set_focus()
          else
            $fConVendas.retCliente().set_value(sCliente)
          end
        else
          $Rotinas.MessageErro(Resource::STR_CPFINV)
          self.clear()
          self.set_focus()
        end
      else
        $fConVendas.retCliente().clear()
      end    
    elsif @local_id == FrmConVendas::ID_FRMCONVENDAS_EDTISBN then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length() > 0 then
        if $Rotinas.validaISBN(self.get_value()) then
          sLivro = $Rotinas.ConsultaCampoDesc(@ConsCampo, $ConsSQL.Livro('Q',
          self.get_value(),"","","","","","","","",""),
          Resource::STR_LIVNENC)
          if sLivro.length==0 then
            self.clear()
            self.set_focus()
          else
            $fConVendas.retLivro().set_value(sLivro)
            nQtdEstoque = @ConsCampo.col[0][3].to_i
            if nQtdEstoque > 0 then
              $Rotinas.sPreco = @ConsCampo.col[0][2]
              $Rotinas.sQtdEstoque = @ConsCampo.col[0][3]
            else
              $Rotinas.MessageErro(Resource::STR_LIVNEST)
            end
          end
        else
          $Rotinas.MessageErro(Resource::STR_ISBNINV)
          self.clear()
          self.set_focus()
        end
      else
        $fConVendas.retLivro().clear()
      end
    end
    event.skip
  end
end
