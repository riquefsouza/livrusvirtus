require 'wxruby'
require 'Consultas'
require 'resource'
require 'RotinasGlobais'
require 'ConsultasSQL'

class FrmConAutores < FrmConsultas
  def initialize(parent)
    super(parent) 
    set_title(Resource::STR_CONAUTOR)
    @labDescricao.set_label('Autor:')
    @gridConsulta.set_col_label_value(1, "Autor")

    evt_button(ID_FRMCONSULTAS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNFECHAR) {|event| OnBtnFecharClick(event)}
    evt_close {|event| on_close(event)}
    evt_grid_select_cell {|event| OnGridSelectCell(event)}
    evt_grid_label_left_click {|event| OnGridLabelLeftClick(event)}
  end

  def on_close(event)
    self.Fecha(Resource::MNU_CON_AUTORES)
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    self.PesquisarDados(
      $ConsSQL.Autor('S', "", @edtDescricao.get_value()),
      Resource::STR_AUTNENC, 2)
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

