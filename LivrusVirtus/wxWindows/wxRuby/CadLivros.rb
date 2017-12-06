require 'wxruby'
require 'Cadastros'
require 'TextValidatorCtrl'
require 'resource'
require 'RotinasGlobais'
require 'ConsultasSQL'
require 'ListaStr'
require 'ConAssuntos'
require 'ConAutores'
require 'ConEditoras'

$fCadLivros = nil

class FrmCadLivros < FrmCadastros
 ID_FRMCADLIVROS_BTNADASSUNTOS, ID_FRMCADLIVROS_BTNADAUTORES, 
 ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_LSTAUTORES,
 ID_FRMCADLIVROS_BTNPAUTOR, ID_FRMCADLIVROS_BTNPEDITORA, 
 ID_FRMCADLIVROS_CMBIDIOMA, ID_FRMCADLIVROS_EDTANOPUBLI, 
 ID_FRMCADLIVROS_EDTASSUNTO, ID_FRMCADLIVROS_EDTAUTOR, 
 ID_FRMCADLIVROS_EDTCODASSUNTO, ID_FRMCADLIVROS_EDTCODAUTOR, 
 ID_FRMCADLIVROS_EDTCODEDITORA, ID_FRMCADLIVROS_EDTEDICAO, 
 ID_FRMCADLIVROS_EDTEDITORA, ID_FRMCADLIVROS_EDTNPAGINAS, 
 ID_FRMCADLIVROS_EDTPRECO, ID_FRMCADLIVROS_EDTQTDESTOQUE, 
 ID_FRMCADLIVROS_EDTVOLUME, ID_FRMCADLIVROS_LABANOPUBLI, 
 ID_FRMCADLIVROS_LABASSUNTO, ID_FRMCADLIVROS_LABAUTOR, 
 ID_FRMCADLIVROS_LABEDICAO, ID_FRMCADLIVROS_LABEDITORA, 
 ID_FRMCADLIVROS_LABIDIOMA, ID_FRMCADLIVROS_LABNPAGINAS, 
 ID_FRMCADLIVROS_LABPRECO, ID_FRMCADLIVROS_LABQTDESTOQUE, 
 ID_FRMCADLIVROS_LABVOLUME, ID_FRMCADLIVROS_LSTASSUNTOS = 
 7000,7001,7002,7003,7004,7005,7006,7007,7008,7009,7010,7011,7012,
 7013,7014,7015,7016,7017,7018,7019,7020,7021,7022,7023,7024,7025,
 7026,7027,7028,7029,7030,7029

  def initialize(parent)
    super(parent, TextValidatorCtrl::FILTER_NONE, false) 
    set_client_size(Wx::Size.new(523, 441))
    @labCodigo.set_label('ISBN: ')
    @edtCodigo.destroy()
  	@edtCodigo = FrmCadLivros_TextValidatorCtrl.new(self, 
      ID_FRMCADASTROS_EDTCODIGO, "", Wx::Point.new(8, 24), 
      Wx::Size.new(121, 21), 0, TextValidatorCtrl::FILTER_NONE )
    @labDescricao.set_label('Título: ')
    @edtDescricao.set_size(Wx::Size.new(312, 21))
    evt_kill_focus {|event| OnEdtCodigo_Killfocus(event)} 

    @labEdicao = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABEDICAO, 
      "Edição:", Wx::Point.new(326, 48), Wx::Size.new(39, 13) )
    @edtEdicao = Wx::SpinCtrl.new(self, ID_FRMCADLIVROS_EDTEDICAO,
      "1", Wx::Point.new(324, 64), Wx::Size.new(92, 21), Wx::SP_ARROW_KEYS, 1, 9999, 1)
    @edtEdicao.enable(false)
    @labAnoPubli = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABANOPUBLI, 
      "Ano Publicação:", Wx::Point.new(8, 88), Wx::Size.new(81, 13) )
    @edtAnoPubli = Wx::SpinCtrl.new(self, ID_FRMCADLIVROS_EDTANOPUBLI, 
      "1", Wx::Point.new(8, 104), Wx::Size.new(92, 21), Wx::SP_ARROW_KEYS, 1, 9999, 1)
    @edtAnoPubli.enable(false)
    @labEditora = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABEDITORA, 
      "Editora:", Wx::Point.new(104, 88), Wx::Size.new(39, 13) )
    @edtCodEditora = FrmCadLivros_TextValidatorCtrl.new(self, 
      ID_FRMCADLIVROS_EDTCODEDITORA, "", Wx::Point.new(104, 104), 
      Wx::Size.new(78, 21), 0, TextValidatorCtrl::FILTER_NUMERIC )
    @edtCodEditora.enable(false)
    @edtEditora = Wx::TextCtrl.new(self, ID_FRMCADLIVROS_EDTEDITORA, 
      "", Wx::Point.new(184, 104), Wx::Size.new(216, 21) )
    @edtEditora.enable(false)
    @btnPEditora = Wx::Button.new(self, ID_FRMCADLIVROS_BTNPEDITORA, 
      "...", Wx::Point.new(400, 400), Wx::Size.new(21, 21) )
    @btnPEditora.enable(false)
    evt_button(ID_FRMCADLIVROS_BTNPEDITORA) {|event| OnBtnPEditoraClick(event)}
    @labVolume = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABVOLUME, 
      "Volume:", Wx::Point.new(8, 128), Wx::Size.new(41, 13) )
    @edtVolume = Wx::SpinCtrl.new(self, ID_FRMCADLIVROS_EDTVOLUME, 
      "1", Wx::Point.new(8, 144), Wx::Size.new(92, 21), Wx::SP_ARROW_KEYS, 1, 9999, 1)
    @edtVolume.enable(false)
    @labIdioma = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABIDIOMA, 
      "Idioma: ", Wx::Point.new(104, 128), Wx::Size.new(56, 13) )
    @cmbIdioma = Wx::Choice.new(self, ID_FRMCADLIVROS_CMBIDIOMA, 
      Wx::Point.new(104, 144), Wx::Size.new(320, 21)  )
    @cmbIdioma.enable(false)
    @labNPaginas = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABNPAGINAS, 
      "Nº Páginas: ", Wx::Point.new(8, 168), Wx::Size.new(59, 13) )
    @edtNPaginas = Wx::SpinCtrl.new(self, ID_FRMCADLIVROS_EDTNPAGINAS, 
      "1", Wx::Point.new(8, 184), Wx::Size.new(92, 21), Wx::SP_ARROW_KEYS, 1, 9999, 1)
    @edtNPaginas.enable(false)
    @labAssunto = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABASSUNTO, 
      "Assunto: ", Wx::Point.new(104, 168), Wx::Size.new(44, 13) )
    @edtCodAssunto = FrmCadLivros_TextValidatorCtrl.new(self, 
      ID_FRMCADLIVROS_EDTCODASSUNTO, "", Wx::Point.new(104, 184), 
      Wx::Size.new(78, 21), 0, TextValidatorCtrl::FILTER_NUMERIC )
    @edtCodAssunto.enable(false)
    @edtAssunto = Wx::TextCtrl.new(self, ID_FRMCADLIVROS_EDTASSUNTO, 
      "", Wx::Point.new(184, 184), Wx::Size.new(192, 21) )
    @edtAssunto.enable(false)
    @btnAdAssuntos = Wx::Button.new(self, ID_FRMCADLIVROS_BTNADASSUNTOS, 
      "+", Wx::Point.new(376, 184), Wx::Size.new(21, 21) )
    @btnAdAssuntos.enable(false)
    evt_button(ID_FRMCADLIVROS_BTNADASSUNTOS) {|event| OnBtnAdAssuntosClick(event)}
    @btnPAssunto = Wx::Button.new(self, ID_FRMCADLIVROS_BTNPASSUNTO, 
      "...", Wx::Point.new(400, 184), Wx::Size.new(21, 21) )
    @btnPAssunto.enable(false)
    evt_button(ID_FRMCADLIVROS_BTNPASSUNTO) {|event| OnBtnPAssuntoClick(event)}
    @labPreco = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABPRECO, 
      "Preço: ", Wx::Point.new(8, 216), Wx::Size.new(40, 13) )
    @edtPreco = FrmCadLivros_TextValidatorCtrl.new(self, ID_FRMCADLIVROS_EDTPRECO, 
      "", Wx::Point.new(7, 232), Wx::Size.new(88, 21), 
      0, TextValidatorCtrl::FILTER_NONE )
    @edtPreco.enable(false)
    @lstAssuntos = Wx::ListBox.new(self, ID_FRMCADLIVROS_LSTASSUNTOS, 
      Wx::Point.new(104, 208), Wx::Size.new(320, 48) )
    @lstAssuntos.enable(false)
    evt_listbox_dclick(ID_FRMCADLIVROS_LSTASSUNTOS) {|event| OnLstAssuntos_Dblclk(event)}
    @labQtdEstoque = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABQTDESTOQUE, 
      "Qtd. Estoque: ", Wx::Point.new(6, 256), Wx::Size.new(68, 13) )
    @edtQtdEstoque = Wx::SpinCtrl.new(self, ID_FRMCADLIVROS_EDTQTDESTOQUE, 
      "0", Wx::Point.new(8, 272), Wx::Size.new(92, 21), Wx::SP_ARROW_KEYS, 0, 9999, 0)
    @edtQtdEstoque.enable(false)
    @labAutor = Wx::StaticText.new(self, ID_FRMCADLIVROS_LABAUTOR,
      "Autor: ", Wx::Point.new(104, 256), Wx::Size.new(31, 13) )
    @edtCodAutor = FrmCadLivros_TextValidatorCtrl.new(self, 
      ID_FRMCADLIVROS_EDTCODAUTOR, "", Wx::Point.new(104, 272), 
      Wx::Size.new(78, 21), 0, TextValidatorCtrl::FILTER_NUMERIC )
    @edtCodAutor.enable(false)
    @edtAutor = Wx::TextCtrl.new(self, ID_FRMCADLIVROS_EDTAUTOR, 
      "", Wx::Point.new(184, 272), Wx::Size.new(192, 21) )
    @edtAutor.enable(false)
    @btnAdAutores = Wx::Button.new(self, ID_FRMCADLIVROS_BTNADAUTORES, 
      "+", Wx::Point.new(376, 272), Wx::Size.new(21, 21) )
    @btnAdAutores.enable(false)
    evt_button(ID_FRMCADLIVROS_BTNADAUTORES) {|event| OnBtnAdAutoresClick(event)}
    @btnPAutor = Wx::Button.new(self, ID_FRMCADLIVROS_BTNPAUTOR, 
      "...", Wx::Point.new(400, 272), Wx::Size.new(21, 21) )
    @btnPAutor.enable(false)
    evt_button(ID_FRMCADLIVROS_BTNPAUTOR) {|event| OnBtnPAutorClick(event)}
    @lstAutores = Wx::ListBox.new(self, ID_FRMCADLIVROS_LSTAUTORES, 
      Wx::Point.new(104, 296), Wx::Size.new(320, 48) )
    @lstAutores.enable(false)
    evt_listbox_dclick(ID_FRMCADLIVROS_LSTAUTORES) {|event| OnLstAutores_Dblclk(event)}

    IniciaBotoes()
  
    @btnPesquisar.set_dimensions(427, 8, 75, 25)
    @btnAnterior.set_dimensions(427, 40, 75, 25)
    @btnProximo.set_dimensions(427, 72, 75, 25)
    @btnSalvar.set_dimensions(187, 352, 75, 25)
    @btnExcluir.set_dimensions(267, 352, 75, 25)
    @btnLimpar.set_dimensions(347, 352, 75, 25)
    @btnFechar.set_dimensions(427, 352, 75, 25)
  
  	FazLayout()
  
    @edtCodigo.set_max_length(13)
    @edtDescricao.set_max_length(50)
    @edtCodEditora.set_max_length(5)
    @edtPreco.set_max_length(7)
  
    @slAssuntos = LISTASTR.new
    @slAutores = LISTASTR.new
    @slIdiomas = LISTASTR.new
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
    sizer_21 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    sizer_20 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_37 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_36 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_35 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_34 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_33 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_19 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_32 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_18 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_31 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_30 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_29 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_28 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_27 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_17 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_26 = Wx::GridSizer.new(2, 1, 0, 0)
    grid_sizer_25 = Wx::GridSizer.new(2, 1, 0, 0)
    sizer_6 = Wx::BoxSizer.new(Wx::HORIZONTAL)
    grid_sizer_24 = Wx::GridSizer.new(2, 1, 0, 0)
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
    grid_sizer_9.add(@labEdicao, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_9.add(@edtEdicao, 0, 0, 0)
    sizer_8.add(grid_sizer_9, 0, Wx::DIRECTION_LEFT, 2)
    sizer_5.add(sizer_8, 1, Wx::EXPAND, 0)
    grid_sizer_4.add(@labAnoPubli, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_4.add(@edtAnoPubli, 0, 0, 0)
    sizer_6.add(grid_sizer_4, 0, 0, 0)
    grid_sizer_5.add(@labEditora, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_5.add(@edtCodEditora, 0, 0, 0)
    sizer_6.add(grid_sizer_5, 0, Wx::DIRECTION_LEFT, 4)
    grid_sizer_6.add(20, 20, 0, 0, 0)
    grid_sizer_6.add(@edtEditora, 0, 0, 0)
    sizer_6.add(grid_sizer_6, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_24.add(20, 20, 0, 0, 0)
    grid_sizer_24.add(@btnPEditora, 0, 0, 0)
    sizer_6.add(grid_sizer_24, 0, 0, 0)
    sizer_5.add(sizer_6, 0, 0, 0)
    grid_sizer_25.add(@labVolume, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_25.add(@edtVolume, 0, 0, 0)
    sizer_17.add(grid_sizer_25, 0, Wx::EXPAND, 0)
    grid_sizer_26.add(@labIdioma, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_26.add(@cmbIdioma, 0, 0, 0)
    sizer_17.add(grid_sizer_26, 0, Wx::DIRECTION_LEFT|Wx::EXPAND, 4)
    sizer_5.add(sizer_17, 1, 0, 0)
    grid_sizer_27.add(@labNPaginas, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_27.add(@edtNPaginas, 0, 0, 0)
    sizer_18.add(grid_sizer_27, 0, 0, 0)
    grid_sizer_28.add(@labAssunto, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_28.add(@edtCodAssunto, 0, 0, 0)
    sizer_18.add(grid_sizer_28, 0, Wx::DIRECTION_LEFT, 4)
    grid_sizer_29.add(20, 20, 0, 0, 0)
    grid_sizer_29.add(@edtAssunto, 0, 0, 0)
    sizer_18.add(grid_sizer_29, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_30.add(20, 20, 0, 0, 0)
    grid_sizer_30.add(@btnAdAssuntos, 0, 0, 0)
    sizer_18.add(grid_sizer_30, 0, 0, 0)
    grid_sizer_31.add(20, 20, 0, 0, 0)
    grid_sizer_31.add(@btnPAssunto, 0, 0, 0)
    sizer_18.add(grid_sizer_31, 0, 0, 0)
    sizer_5.add(sizer_18, 1, 0, 0)
    grid_sizer_32.add(@labPreco, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_32.add(@edtPreco, 0, 0, 0)
    sizer_19.add(grid_sizer_32, 0, 0, 0)
    sizer_19.add(@lstAssuntos, 0, Wx::DIRECTION_LEFT, 4)
    sizer_5.add(sizer_19, 1, 0, 0)
    grid_sizer_33.add(@labQtdEstoque, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_33.add(@edtQtdEstoque, 0, 0, 0)
    sizer_20.add(grid_sizer_33, 0, 0, 0)
    grid_sizer_34.add(@labAutor, 0, Wx::ALIGN_BOTTOM, 0)
    grid_sizer_34.add(@edtCodAutor, 0, 0, 0)
    sizer_20.add(grid_sizer_34, 0, 0, 0)
    grid_sizer_35.add(20, 20, 0, 0, 0)
    grid_sizer_35.add(@edtAutor, 0, 0, 0)
    sizer_20.add(grid_sizer_35, 0, Wx::DIRECTION_LEFT, 2)
    grid_sizer_36.add(20, 20, 0, 0, 0)
    grid_sizer_36.add(@btnAdAutores, 0, 0, 0)
    sizer_20.add(grid_sizer_36, 0, 0, 0)
    grid_sizer_37.add(20, 20, 0, 0, 0)
    grid_sizer_37.add(@btnPAutor, 0, 0, 0)
    sizer_20.add(grid_sizer_37, 0, 0, 0)
    sizer_5.add(sizer_20, 1, 0, 0)
    sizer_21.add(92, 20, 0, 0, 0)
    sizer_21.add(@lstAutores, 0, 0, 0)
    sizer_5.add(sizer_21, 0, 0, 0)
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
    sizer_1.add(sizer_2, 0, 
      Wx::DIRECTION_RIGHT|Wx::DIRECTION_BOTTOM|
      Wx::ALIGN_RIGHT|Wx::ALIGN_BOTTOM, 4)
    self.set_auto_layout(true)
    self.set_sizer(sizer_1)
  end

  def ValidaDados(bTodosDados)
    if $Rotinas.ValidaCampo(
      @edtCodigo.get_value(), Resource::STR_ISBNNINF) then
      return false
    end
    if bTodosDados then
      if $Rotinas.ValidaCampo(
        @edtDescricao.get_value(), Resource::STR_TITNINF) then
        return false
      end
      if $Rotinas.ValidaCampo(
        @edtEditora.get_value(), Resource::STR_EDTNINF) then
        return false
      end
      if @lstAssuntos.get_count() == 0 then
        $Rotinas.MessageErro(Resource::STR_ASSNINF)
        return false
      end
      if @lstAutores.get_count()==0 then
        $Rotinas.MessageErro(Resource::STR_AUTNINF)
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
    if self.PesquisarDados($ConsSQL.Livro('S', 
      @edtCodigo.get_value(),"","","","","","","","",""),
      Resource::STR_LIVNENC) then
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
    nPos = @cmbIdioma.get_selection()
    sCodIdioma = @slIdiomas.col[nPos]
  
    sSqlUpdate = $ConsSQL.Livro('U',
      @edtCodigo.get_value(), @edtDescricao.get_value(), 
      @edtEdicao.get_value().to_s, @edtAnoPubli.get_value().to_s, 
      @edtVolume.get_value().to_s, @edtCodEditora.get_value(), 
      sCodIdioma, @edtNPaginas.get_value().to_s,
      $Rotinas.VirgulaParaPonto(
      @edtPreco.get_value(),false), @edtQtdEstoque.get_value().to_s)
  
    sSqlInsert = $ConsSQL.Livro('I', 
      @edtCodigo.get_value(), @edtDescricao.get_value(), 
      @edtEdicao.get_value().to_s, @edtAnoPubli.get_value().to_s, 
      @edtVolume.get_value().to_s, @edtCodEditora.get_value(), 
      sCodIdioma, @edtNPaginas.get_value().to_s,
      $Rotinas.VirgulaParaPonto(
      @edtPreco.get_value(),false), @edtQtdEstoque.get_value().to_s)

    if self.SalvarDados(self.ValidaDados(true),
      $ConsSQL.Livro('S', @edtCodigo.get_value(),
      "","","","","","","","",""), sSqlUpdate, sSqlInsert, false) then
      self.SalvaLista('A')
      self.SalvaLista('B')
      self.btnLimparClick()
      self.InformaLimpaDadosLocal(false)
      self.HabilitaDadosLocal(false)
    end
    event.skip()
  end

  def OnBtnExcluirClick(event)
    if self.ExcluirDados(self.ValidaDados(false),
      $ConsSQL.Livro('D', @edtCodigo.get_value(),
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
      @edtEdicao.set_value(@lstRegistros.col[@nLinhaRegistro][2].to_i)
      @edtAnoPubli.set_value(@lstRegistros.col[@nLinhaRegistro][3].to_i)
      @edtVolume.set_value(@lstRegistros.col[@nLinhaRegistro][4].to_i)
      @edtCodEditora.set_value(@lstRegistros.col[@nLinhaRegistro][5])
      @edtEditora.set_value(@lstRegistros.col[@nLinhaRegistro][6])
      @cmbIdioma.set_string_selection(@lstRegistros.col[@nLinhaRegistro][8])
      @edtNPaginas.set_value(@lstRegistros.col[@nLinhaRegistro][9].to_i)
      @edtPreco.set_value($Rotinas.VirgulaParaPonto(
        @lstRegistros.col[@nLinhaRegistro][10], true))
      @edtQtdEstoque.set_value(@lstRegistros.col[@nLinhaRegistro][11].to_i)
      $Rotinas.AdicionaValoresLista($ConsSQL.LivroAss('S', 
        @edtCodigo.get_value(), ""), @lstAssuntos, @slAssuntos)
      $Rotinas.AdicionaValoresLista($ConsSQL.LivroAut('S',
        @edtCodigo.get_value(), ""), @lstAutores, @slAutores)
    else
      @edtEdicao.set_value(1)
      @edtAnoPubli.set_value(
        $Rotinas.retDataHoraStr(true,false).slice(6,4).to_i)
      @edtVolume.set_value(1)
      @edtCodEditora.clear()
      @edtEditora.clear()
      @cmbIdioma.set_selection(0)    
      @edtNPaginas.set_value(1)
      @edtPreco.set_value("0,00")
      @edtQtdEstoque.set_value(1)
      @edtCodAssunto.clear()
      @lstAssuntos.clear()
      @edtCodAutor.clear()
      @lstAutores.clear()
      @slAssuntos.col = []
      @slAutores.col = []
    end
  end

  def HabilitaDadosLocal(bHabilita)
    @edtEdicao.enable(bHabilita)
    @edtAnoPubli.enable(bHabilita)
    @edtVolume.enable(bHabilita)
    @edtCodEditora.enable(bHabilita)
    @btnPEditora.enable(bHabilita)
    @cmbIdioma.enable(bHabilita)
    @edtNPaginas.enable(bHabilita)
    @edtPreco.enable(bHabilita)
    @edtQtdEstoque.enable(bHabilita)
    @edtCodAssunto.enable(bHabilita)
    @btnPAssunto.enable(bHabilita)
    @btnAdAssuntos.enable(bHabilita)
    @lstAssuntos.enable(bHabilita)
    @edtCodAutor.enable(bHabilita)
    @btnPAutor.enable(bHabilita)
    @btnAdAutores.enable(bHabilita)
    @lstAutores.enable(bHabilita)
  end

  def AdicionaCombo()
    @Campos = LISTAMSTR.new
    if $Rotinas.ConsultaDadosLista($Rotinas.gConexao, @Campos,
      $ConsSQL.Idioma('S',"","")) then
      @slIdiomas.col = []
      for nLinha in (0 .. @Campos.tam-1) do
  	    @slIdiomas.col.push(@Campos.col[nLinha][0])
  	    @cmbIdioma.append(@Campos.col[nLinha][1])
      end
    end
  end

  def SalvaLista(sOpcao)
    sISBN = @edtCodigo.get_value()
    if sOpcao == 'A' then
      $Rotinas.AtualizaDados($Rotinas.gConexao, 
      $ConsSQL.LivroAss('D',sISBN,"")) 
  
      nQtd = @slAssuntos.col.length - 1
      for nCont in (0 .. nQtd) do
        $Rotinas.AtualizaDados($Rotinas.gConexao, 
          $ConsSQL.LivroAss('I', sISBN, @slAssuntos.col[nCont]))
      end
    elsif sOpcao=='B' then
    	$Rotinas.AtualizaDados($Rotinas.gConexao,
      $ConsSQL.LivroAut('D', sISBN,""))
  
      nQtd = @slAutores.col.length - 1
      for nCont in (0 .. nQtd) do
        $Rotinas.AtualizaDados($Rotinas.gConexao, 
          $ConsSQL.LivroAut('I', sISBN, @slAutores.col[nCont]))
      end
    end
  end

  def retEditora()
    return @edtEditora;
  end   
 
  def OnBtnPEditoraClick(event)
    fConEditoras = FrmConEditoras.new(self)
    fConEditoras.show_modal()
    @edtCodEditora.set_value($Rotinas.sCodigoSelecionado)
    @edtCodEditora.on_killfocus(event)  
    event.skip()
  end
  
  def retAssunto()
    return @edtAssunto;
  end   
  
  def OnBtnPAssuntoClick(event)
    fConAssuntos = FrmConAssuntos.new(self)
    fConAssuntos.show_modal()
    @edtCodAssunto.set_value($Rotinas.sCodigoSelecionado)
    @edtCodAssunto.on_killfocus(event)    
    event.skip()
  end
  
  def OnBtnAdAssuntosClick(event)
    $Rotinas.AdicionaItemLista(@lstAssuntos, 
      @slAssuntos, @edtCodAssunto, @edtAssunto)
    event.skip()
  end
  
  def OnLstAssuntos_Dblclk(event)
    $Rotinas.RemoveItemLista(@lstAssuntos,@slAssuntos)
    event.skip()
  end
  
  def retAutor()
    return @edtAutor;
  end   
  
  def OnBtnPAutorClick(event)
    fConAutores = FrmConAutores.new(self)
    fConAutores.show_modal()
    @edtCodAutor.set_value($Rotinas.sCodigoSelecionado)
    @edtCodAutor.on_killfocus(event)      
    event.skip()
  end
  
  def OnBtnAdAutoresClick(event)
    $Rotinas.AdicionaItemLista(@lstAutores, 
      @slAutores, @edtCodAutor, @edtAutor)  
    event.skip()
  end
  
  def OnLstAutores_Dblclk(event)
    $Rotinas.RemoveItemLista(@lstAutores,@slAutores)
    event.skip()
  end

end

class FrmCadLivros_TextValidatorCtrl < TextValidatorCtrl

  def initialize(parent, id, valor, pos, size, estilo, nfiltro)
    super(parent, id, valor, pos, size, estilo, nfiltro)
    @local_id = id
    evt_kill_focus {|event| on_killfocus(event)}
  end

  def on_killfocus(event) 
    if @local_id == FrmCadLivros::ID_FRMCADASTROS_EDTCODIGO then
      if self.get_value().length > 0 then
      	if $Rotinas.validaISBN(self.get_value())==false then
          $Rotinas.MessageErro(Resource::STR_ISBNINV)
          self.clear()
          self.set_focus()
        end
      end
    elsif @local_id == FrmCadLivros::ID_FRMCADLIVROS_EDTCODEDITORA then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length() > 0 then
        sEditora = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
          $ConsSQL.Editora('S', self.get_value(),""),Resource::STR_EDTNENC)
        if sEditora.length() > 0 then
          $fCadLivros.retEditora().set_value(sEditora)
        else
          self.clear()
          self.set_focus()
        end
      else
        $fCadLivros.retEditora().clear()
      end    
    elsif @local_id == FrmCadLivros::ID_FRMCADLIVROS_EDTPRECO then
      if $Rotinas.ValidaFloat(
            $Rotinas.VirgulaParaPonto(self.get_value(), false)) then
        self.set_value($Rotinas.VirgulaParaPonto(self.get_value(), true))
      else
        self.set_value("0,01")
        self.set_focus()
      end
    elsif @local_id == FrmCadLivros::ID_FRMCADLIVROS_EDTCODASSUNTO then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length() > 0 then
        sAssunto = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
          $ConsSQL.Assunto('S', self.get_value(),""),Resource::STR_ASSNENC)
        if sAssunto.length() > 0 then
          $fCadLivros.retAssunto().set_value(sAssunto)
        else
          self.clear()
          self.set_focus()
        end
      else
        $fCadLivros.retAssunto().clear()
      end    
    elsif @local_id == FrmCadLivros::ID_FRMCADLIVROS_EDTCODAUTOR then
      @ConsCampo = LISTAMSTR.new
    
      if self.get_value().length() > 0 then
        sAutor = $Rotinas.ConsultaCampoDesc(@ConsCampo, 
          $ConsSQL.Autor('S', self.get_value(),""),Resource::STR_AUTNENC)
        if sAutor.length() > 0 then
          $fCadLivros.retAutor().set_value(sAutor)
        else
          self.clear()
          self.set_focus()
        end
      else
        $fCadLivros.retAutor().clear()
      end    
    end
    event.skip
  end
end

