require 'fox'
require 'fox/responder'
require 'resource'
require 'Principal'
require 'ConsultasSQL'
require 'Consultas'
include Fox
include Responder

class FRMConEnderecos < FRMConsultas
  
  def initialize(owner)  
    super(owner, Resource::STR_CONENDERECO)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_SELECTED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridSelected)
    FXMAPFUNC(SEL_CHANGED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridChanged)

    @labDescricao.setText("Endere�o:")
    $Rotinas.IniciaLayoutGrid(@gridConsulta, 2, 7)
    @gridConsulta.setItemText(0, 2, "Logradouro")
    @gridConsulta.setColumnWidth(2, 200)

    nLargura = [ 150,80,100,80 ]
    sRotulos = [ "Bairro", "CEP", "Cidade", "Estado" ]
    $Rotinas.AdicionaColunasGrid(@gridConsulta, 3, 4, nLargura, sRotulos)
  end

  def create()
    super
    show(PLACEMENT_SCREEN)
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    PesquisarDados($ConsSQL.Endereco('S',"", 
      @edtDescricao.getText(),"","","",""), Resource::STR_ENDNENC, 6)
    return true
  end
  
  def onBtnLimpar(sender, sel, ptr)
    LimparDados()
    return true
  end
  
  def onGridSelected(sender, sel, ptr)
    setLabRegistros(ptr.fm.row)
    return true
  end
  
  def onGridChanged(sender, sel, ptr)
    setLabRegistros(ptr.row)
    return true
  end

end
