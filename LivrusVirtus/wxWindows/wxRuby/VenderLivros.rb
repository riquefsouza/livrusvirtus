require 'wxruby'
require 'Cadastros'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'resource'
require 'ListaStr'
require 'ConClientes'
require 'ConLivros'

$fVenderLivros = nil

class FrmVenderLivros < FrmCadastros
  ID_FRMVENDERLIVROS_BTNADLIVROS, ID_FRMVENDERLIVROS_LSTLIVROS,
  ID_FRMVENDERLIVROS_BTNFECHAR, ID_FRMVENDERLIVROS_BTNLIMPAR, 
  ID_FRMVENDERLIVROS_BTNPCLIENTE, ID_FRMVENDERLIVROS_BTNPLIVRO, 
  ID_FRMVENDERLIVROS_BTNVENDER, ID_FRMVENDERLIVROS_EDTDTHRVENDA, 
  ID_FRMVENDERLIVROS_EDTISBN, ID_FRMVENDERLIVROS_EDTLIVRO, 
  ID_FRMVENDERLIVROS_EDTPRECOTOTAL, ID_FRMVENDERLIVROS_LABDTHRVENDA, 
  ID_FRMVENDERLIVROS_LABISBN, ID_FRMVENDERLIVROS_LABLIVRO, 
  ID_FRMVENDERLIVROS_LABLIVROS, ID_FRMVENDERLIVROS_LABPRECOTOTAL =
  9000,9001,9002,9003,9004,9005,9006,9007,9008,9009,
  9010,9011,9012,9013,9014,9015

  def initialize(parent)
    super(parent, TextValidatorCtrl::FILTER_NONE, false) 
    set_client_size(Wx::Size.new(481, 309))
    @btnNovo.hide()

  	@labDtHrVenda = Wx::StaticText.new(self, 
      ID_FRMVENDERLIVROS_LABDTHRVENDA, "Data/Hora Venda: ", 
      Wx::Point.new(8, 8), Wx::Size.new(91, 13) )
  	@edtDtHrVenda = Wx::TextCtrl.new(self, 
      ID_FRMVENDERLIVROS_EDTDTHRVENDA, "", 
      Wx::Point.new(8, 24), Wx::Size.new(128, 21) )
    @edtDtHrVenda.enable(false)
    @labCodigo.set_label("CPF: ")  
    @labCodigo.set_dimensions(8, 48, 48, 13) 

    @edtCodigo.destroy()
  	@edtCodigo = FrmVenderLivros_TextValidatorCtrl.new(self, 
      ID_FRMCADASTROS_EDTCODIGO, "", Wx::Point.new(8, 64), 
      Wx::Size.new(128, 21), 0, TextValidatorCtrl::FILTER_NONE )
 
    @labDescricao.set_label("Cliente: ")  
    @labDescricao.set_dimensions(142, 48, 56, 13)
    @edtDescricao.set_dimensions(142, 64, 306, 21)
    @edtDescricao.enable(false)
  
  	@btnPCliente = Wx::Button.new(self, ID_FRMVENDERLIVROS_BTNPCLIENTE, "...", 
      Wx::Point.new(448, 64), Wx::Size.new(21, 21) )
    evt_button(ID_FRMVENDERLIVROS_BTNPCLIENTE) {|event| OnBtnPClienteClick(event)}
  	@labISBN = Wx::StaticText.new(self, ID_FRMVENDERLIVROS_LABISBN, "ISBN: ",
      Wx::Point.new(8, 88), Wx::Size.new(48, 13) )
  	@edtISBN = FrmVenderLivros_TextValidatorCtrl.new(self, 
      ID_FRMVENDERLIVROS_EDTISBN, "",
      Wx::Point.new(8, 104), Wx::Size.new(128, 21) , 0, 
      TextValidatorCtrl::FILTER_NONE )
    evt_kill_focus {|event| OnEdtISBN_Killfocus(event)}
  	@labLivro = Wx::StaticText.new(self, ID_FRMVENDERLIVROS_LABLIVRO, 
      "Livro: ", Wx::Point.new(142, 88), Wx::Size.new(40, 13) )
  	@edtLivro = Wx::TextCtrl.new(self, ID_FRMVENDERLIVROS_EDTLIVRO, 
      "", Wx::Point.new(142, 104), Wx::Size.new(282, 21) )
    @edtLivro.enable(false)
  	@btnAdLivros = Wx::Button.new(self, ID_FRMVENDERLIVROS_BTNADLIVROS, "+",
      Wx::Point.new(424, 104), Wx::Size.new(21, 21) )
    evt_button(ID_FRMVENDERLIVROS_BTNADLIVROS) {|event| OnBtnAdLivrosClick(event)}
  	@btnPLivro = Wx::Button.new(self, ID_FRMVENDERLIVROS_BTNPLIVRO, 
      "...", Wx::Point.new(448, 104), Wx::Size.new(21, 21) )
    evt_button(ID_FRMVENDERLIVROS_BTNPLIVRO) {|event| OnBtnPLivroClick(event)}
  	@labLivros = Wx::StaticText.new(self, 
      ID_FRMVENDERLIVROS_LABLIVROS, "Livros para vender: ", 
      Wx::Point.new(8, 128), Wx::Size.new(120, 13) )
  	@lstLivros = Wx::ListBox.new(self, ID_FRMVENDERLIVROS_LSTLIVROS, 
      Wx::Point.new(8, 144), Wx::Size.new(464, 96) )
    evt_listbox_dclick(ID_FRMVENDERLIVROS_LSTLIVROS) {|event| OnLstLivros_Dblclk(event)}
  	@labPrecoTotal = Wx::StaticText.new(self, 
      ID_FRMVENDERLIVROS_LABPRECOTOTAL, "Preço Total: ", 
      Wx::Point.new(280, 248), Wx::Size.new(61, 13) )
  	@edtPrecoTotal = Wx::TextCtrl.new(self, ID_FRMVENDERLIVROS_EDTPRECOTOTAL, 
      "", Wx::Point.new(344, 246), Wx::Size.new(127, 21) )
    @edtPrecoTotal.enable(false)
  	@btnVender = Wx::Button.new(self, ID_FRMVENDERLIVROS_BTNVENDER, 
      "&Vender", Wx::Point.new(239, 275), Wx::Size.new(75, 25))
  	@btnLimpar = Wx::Button.new(self, ID_FRMVENDERLIVROS_BTNLIMPAR, 
      "&Limpar", Wx::Point.new(319, 275), Wx::Size.new(75, 25))
  	@btnFechar = Wx::Button.new(self, ID_FRMVENDERLIVROS_BTNFECHAR, 
      "&Fechar", Wx::Point.new(399, 275), Wx::Size.new(75, 25))
  
    FazLayout()
    
    evt_button(ID_FRMVENDERLIVROS_BTNVENDER) {|event| OnBtnVenderClick(event)}
    evt_button(ID_FRMVENDERLIVROS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMVENDERLIVROS_BTNFECHAR) {|event| OnBtnFecharClick(event)}

    @slPrecos = LISTASTR.new
    @slISBNs = LISTASTR.new
    @slQtdEstoque = LISTASTR.new
    @nPrecoTotal = 0.0

    @edtCodigo.set_max_length(14)
    @edtISBN.set_max_length(13)  
    LimpaDados()
  end

  def FazLayout()
    sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_6 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_8 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_7 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_5 = Wx::BoxSizer.new(Wx::VERTICAL)
    sizer_4 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_8 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_7 = Wx::GridSizer.new(2, 1, 0, 0)
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
    sizer_2.add(20, 20, 0, 0, 0)
    sizer_1.add(sizer_2, 0, 0, 0)
    grid_sizer_2.add(@labCodigo, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_2.add(@edtCodigo, 0, 0, 0)
    sizer_3.add(grid_sizer_2, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_3.add(@labDescricao, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_3.add(@edtDescricao, 0, 0, 0)
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
    grid_sizer_7.add(20, 20, 0, 0, 0)
    grid_sizer_7.add(@btnAdLivros, 0, 0, 0)
    sizer_4.add(grid_sizer_7, 1, Wx::EXPAND, 0)
    grid_sizer_8.add(20, 20, 0, 0, 0)
    grid_sizer_8.add(@btnPLivro, 0, 0, 0)
    sizer_4.add(grid_sizer_8, 0, 0, 0)
    sizer_1.add(sizer_4, 0, 0, 0)
    sizer_5.add(@labLivros, 0, Wx::ALIGN_BOTTOM, 0)
    sizer_5.add(@lstLivros, 1, Wx::ALL|Wx::EXPAND, 1)
    sizer_1.add(sizer_5, 1, Wx::EXPAND, 0)
    sizer_7.add(@labPrecoTotal, 0, Wx::ALL, 2)
    sizer_7.add(@edtPrecoTotal, 0, Wx::ALL, 2)
    sizer_6.add(sizer_7, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
    sizer_8.add(@btnVender,0,Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_8.add(@btnLimpar,0,Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_8.add(@btnFechar,0,Wx::ALL|Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 2)
    sizer_6.add(sizer_8, 0, Wx::ALL, 2)
    sizer_1.add(sizer_6, 0, Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 0)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
    sizer_1.fit(self)
    sizer_1.set_size_hints(self)
  end

  def LimpaDados()
    @edtDtHrVenda.set_value($Rotinas.retDataHoraStr(true, true))
    @edtCodigo.clear()
    @edtDescricao.clear()
    @edtISBN.clear()
    @edtLivro.clear()
    @lstLivros.clear()
    @nPrecoTotal = 0
    @slPrecos.col = []
    @slISBNs.col = []
    @slQtdEstoque.col = []
    @edtPrecoTotal.set_value("R$ 0,00")
    @edtCodigo.set_focus()
  end

  def ValidaDados()
    if $Rotinas.ValidaCampo(@edtCodigo.get_value(), Resource::STR_CPFNINF) then
      return false
    end
    if @lstLivros.get_count()==0 then
      $Rotinas.MessageErro(Resource::STR_LIVVENNINF)
      return false
    end
    return true
  end

  def SalvaLista()
    nQtd = @lstLivros.get_count()
    sCPF = @edtCodigo.get_value()
    sPrecoTotal = @nPrecoTotal.to_s
    
    sDTHR = @edtDtHrVenda.get_value()
    sDataHora = $Rotinas.ConverteDataHoraStr(sDTHR, true, 
      "%m/%d/%Y","%H:%M:%S")
    
    for nCont in (0 .. nQtd-1) do
      sISBN = @slISBNs.col[nCont]    
      
      $Rotinas.AtualizaDados($Rotinas.gConexao, $ConsSQL.Venda('I',sISBN, 
        sCPF, sDataHora, $Rotinas.VirgulaParaPonto(sPrecoTotal,false),""))
    
      nQtdEstoque = @slQtdEstoque.col[nCont].to_i
      if nQtdEstoque > 0 then
        nQtdEstoque = nQtdEstoque - 1
      end
      sQtdEstoque = nQtdEstoque.to_s
      $Rotinas.AtualizaDados($Rotinas.gConexao, $ConsSQL.Venda('U',sISBN, 
        "","","", sQtdEstoque))
    end
    return true
  end

  def retCliente()
    return @edtDescricao
  end   
  
  def OnBtnPClienteClick(event)
    fConClientes = FrmConClientes.new(self)
    fConClientes.show_modal()
    @edtCodigo.set_value($Rotinas.sCodigoSelecionado)
    @edtCodigo.on_killfocus(event)
    event.skip()
  end
  
  def retLivro()
    return @edtLivro
  end   
  
  def OnBtnAdLivrosClick(event)
    sISBN = @edtISBN.get_value()
    sEdtLivro = @edtLivro.get_value()
    if sISBN.length > 0 then
      sLivros = sISBN + " - " + sEdtLivro + " - R$ " + $Rotinas.sPreco
      if $Rotinas.PesquisaItemLista(@lstLivros, sLivros) == -1 then
        @slISBNs.col.push(sISBN)
        @slPrecos.col.push($Rotinas.sPreco)
        @slQtdEstoque.col.push($Rotinas.sQtdEstoque)
        @lstLivros.append(sLivros)
        nPreco = $Rotinas.sPreco.to_f
        @nPrecoTotal = @nPrecoTotal + nPreco
      end
      @edtISBN.clear()
      @edtLivro.clear()
      sPrecoTotal = "R$ " + @nPrecoTotal.to_s
      @edtPrecoTotal.set_value($Rotinas.VirgulaParaPonto(sPrecoTotal,true))
    end
    event.skip()
  end
  
  def OnBtnPLivroClick(event)
    fConLivros = FrmConLivros.new(self)
    fConLivros.show_modal()
    @edtISBN.set_value($Rotinas.sCodigoSelecionado)
    @edtISBN.on_killfocus(event)
    event.skip()
  end
  
  def OnLstLivros_Dblclk(event)
    if @lstLivros.get_count() > 0 then
      nSelIndice = @lstLivros.get_selection()
      if @lstLivros.is_selected(nSelIndice) then
        nPreco = @slPrecos.col[nSelIndice].to_f
        @nPrecoTotal = @nPrecoTotal - nPreco
        sPrecoTotal = "R$ " + @nPrecoTotal.to_s
        @edtPrecoTotal.set_value($Rotinas.VirgulaParaPonto(sPrecoTotal, true))
        @slISBNs.col.delete_at(nSelIndice)
        @slPrecos.col.delete_at(nSelIndice)
        @slQtdEstoque.col.delete_at(nSelIndice)
        @lstLivros.delete(nSelIndice)
      end
    end
    event.skip()
  end

  def OnBtnVenderClick(event)
    if self.ValidaDados() then
      if self.SalvaLista() then
        mens = Wx::MessageDialog.new(self, Resource::STR_VENRESUC, 
          Resource::STR_TITULO, Wx::OK | Wx::ICON_INFORMATION)
        mens.show_modal()
        self.LimpaDados()
      end
    end
    event.skip()
  end

  def OnBtnLimparClick(event)
    self.LimpaDados()
    event.skip()
  end

  def OnBtnFecharClick(event)
    self.get_parent().close(true)
    event.skip()
  end
end

class FrmVenderLivros_TextValidatorCtrl < TextValidatorCtrl

  def initialize(parent, id, valor, pos, size, estilo, nfiltro)
    super(parent, id, valor, pos, size, estilo, nfiltro)
    @local_id = id
    evt_kill_focus {|event| on_killfocus(event)}
  end

  def on_killfocus(event) 
    if @local_id == FrmVenderLivros::ID_FRMCADASTROS_EDTCODIGO then
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
            $fVenderLivros.retCliente().set_value(sCliente)
          end
        else
          $Rotinas.MessageErro(Resource::STR_CPFINV)
          self.clear()
          self.set_focus()
        end
      else
        $fVenderLivros.retCliente().clear()
      end    
    elsif @local_id == FrmVenderLivros::ID_FRMVENDERLIVROS_EDTISBN then
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
            $fVenderLivros.retLivro().set_value(sLivro)
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
        $fVenderLivros.retLivro().clear()
      end
    end
    event.skip
  end
end

  
