require 'fox'
require 'fox/responder'
require 'resource'
require 'Principal'
require 'ConsultasSQL'
require 'Consultas'
include Fox
include Responder

class FRMConLivros < FRMConsultas
  
  def initialize(owner)  
    super(owner, Resource::STR_CONLIVRO)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_SELECTED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridSelected)
    FXMAPFUNC(SEL_CHANGED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridChanged)
    
    @labDescricao.setText("Livro:")
    $Rotinas.IniciaLayoutGrid(@gridConsulta, 2, 13)
    @gridConsulta.setItemText(0, 1, "ISBN")
    @gridConsulta.setColumnWidth(1, 80)
    @gridConsulta.setItemText(0, 2, "Título")
    @gridConsulta.setColumnWidth(2, 180)
  
    nLargura = [ 80,90,80,80,100,80,100,80,80,80 ]
    sRotulos = [ "Edição", "AnoPublicação", "Volume",
      "CodEditora", "Editora", "CodIdioma", "Idioma",
      "NumPáginas", "Preço", "Estoque" ]
    $Rotinas.AdicionaColunasGrid(@gridConsulta, 3, 10, nLargura, sRotulos)
  end

  def create()
    super
    show(PLACEMENT_SCREEN)
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    PesquisarDados($ConsSQL.Livro('S',"", @edtDescricao.getText(),
      "","","","","","","",""), Resource::STR_LIVNENC, 12)
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
