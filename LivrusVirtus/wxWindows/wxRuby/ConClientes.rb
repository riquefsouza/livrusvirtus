require 'wxruby'
require 'Consultas'
require 'resource'
require 'RotinasGlobais'
require 'ConsultasSQL'

class FrmConClientes < FrmConsultas
  def initialize(parent)
    super(parent) 
    set_title(Resource::STR_CONCLIENTE)
    @labDescricao.set_label('Cliente:')
    @gridConsulta.set_col_label_value(0, "CPF")
    @gridConsulta.set_col_size(0, 90)
    @gridConsulta.set_col_label_value(1, "Nome")
    @gridConsulta.set_col_size(1, 220)

    nLargura = [ 180,80,40,80,120,80,220,150,
                      80,100,100,80,180,80,100 ]
    sRotulos = [ "Email", "Identidade", "Sexo", 
     "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
     "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
     "CodProfissão", "Profissão" ]
    $Rotinas.AdicionaColunasGrid(@gridConsulta, 2, 15, nLargura, sRotulos)

    evt_button(ID_FRMCONSULTAS_BTNPESQUISAR) {|event| OnBtnPesquisarClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNLIMPAR) {|event| OnBtnLimparClick(event)}
    evt_button(ID_FRMCONSULTAS_BTNFECHAR) {|event| OnBtnFecharClick(event)}
    evt_close {|event| on_close(event)}
    evt_grid_select_cell {|event| OnGridSelectCell(event)}
    evt_grid_label_left_click {|event| OnGridLabelLeftClick(event)}
  end

  def on_close(event)
    self.Fecha(Resource::MNU_CON_CLIENTES)
    event.skip()
  end

  def OnBtnPesquisarClick(event)
    self.PesquisarDados(
      $ConsSQL.Cliente('S', "", @edtDescricao.get_value(),
      "","","","","","","",""),Resource::STR_CLINENC, 17)
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

