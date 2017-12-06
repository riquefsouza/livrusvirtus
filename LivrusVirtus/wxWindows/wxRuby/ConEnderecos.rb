require 'wxruby'
require 'Consultas'
require 'resource'
require 'RotinasGlobais'
require 'ConsultasSQL'

class FrmConEnderecos < FrmConsultas
  def initialize(parent)
    super(parent) 
    set_title(Resource::STR_CONENDERECO)
    @labDescricao.set_label('Endereço:')
    @gridConsulta.set_col_label_value(1, "Logradouro")
    @gridConsulta.set_col_size(1, 200)

    nLargura = [ 150,80,100,80 ]
    sRotulos = [ "Bairro", "CEP", "Cidade", "Estado" ]
    $Rotinas.AdicionaColunasGrid(@gridConsulta, 2, 4, nLargura, sRotulos)

    evt_button(ID_FRMCONSULTAS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNFECHAR) {|event| OnBtnFecharClick(event)}
    evt_close {|event| on_close(event)}
    evt_grid_select_cell {|event| OnGridSelectCell(event)}
    evt_grid_label_left_click {|event| OnGridLabelLeftClick(event)}
  end

  def on_close(event)
    self.Fecha(Resource::MNU_CON_ENDERECOS)
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    self.PesquisarDados(
      $ConsSQL.Endereco('S', "", @edtDescricao.get_value(),"","","",""),
      Resource::STR_ENDNENC, 6)
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

