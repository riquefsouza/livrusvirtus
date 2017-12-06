require 'wxruby'
require 'Consultas'
require 'resource'
require 'RotinasGlobais'
require 'ConsultasSQL'

class FrmConLivros < FrmConsultas
  def initialize(parent)
    super(parent) 
    set_title(Resource::STR_CONLIVRO)
    @labDescricao.set_label('Livro:')
    @gridConsulta.set_col_label_value(0, "ISBN")
    @gridConsulta.set_col_size(0, 80)
    @gridConsulta.set_col_label_value(1, "Título")
    @gridConsulta.set_col_size(1, 180)

    nLargura = [ 80,90,80,80,100,80,100,80,80,80 ]
    sRotulos = [ "Edição", "AnoPublicação", "Volume",
      "CodEditora", "Editora", "CodIdioma", "Idioma",
      "NumPáginas", "Preço", "Estoque" ]
    $Rotinas.AdicionaColunasGrid(@gridConsulta, 2, 10, nLargura, sRotulos)

    evt_button(ID_FRMCONSULTAS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNFECHAR) {|event| OnBtnFecharClick(event)}
    evt_close {|event| on_close(event)}
    evt_grid_select_cell {|event| OnGridSelectCell(event)}
    evt_grid_label_left_click {|event| OnGridLabelLeftClick(event)}
  end

  def on_close(event)
    self.Fecha(Resource::MNU_CON_LIVROS)
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    self.PesquisarDados(
      $ConsSQL.Livro('S', "", @edtDescricao.get_value(),
      "","","","","","","",""),Resource::STR_LIVNENC, 12)
    event.skip()
  end

  def OnBtnLimparClick(event)
    self.LimparDados()
    event.skip()
  end

  def OnBtnFecharClick(event)
    self.Fecha(0)
    event.skip()
  end

  def OnGridSelectCell(event)
    self.setLabRegistros(event.get_row())
    event.skip()
  end
  
  def OnGridLabelLeftClick(event)
    self.setLabRegistros(event.get_row())
    event.skip()
  end

end

