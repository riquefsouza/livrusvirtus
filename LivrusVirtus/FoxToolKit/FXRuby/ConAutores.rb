require 'fox'
require 'fox/responder'
require 'resource'
require 'Principal'
require 'ConsultasSQL'
require 'Consultas'
include Fox
include Responder

class FRMConAutores < FRMConsultas
  
  def initialize(owner)  
    super(owner, Resource::STR_CONAUTOR)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_SELECTED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridSelected)
    FXMAPFUNC(SEL_CHANGED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridChanged)
    
    @labDescricao.setText("Autor:")
    @gridConsulta.setItemText(0, 2, "Autor")
  end

  def create()
    super
    show(PLACEMENT_SCREEN)
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    PesquisarDados($ConsSQL.Autor('S',"", 
      @edtDescricao.getText()), Resource::STR_AUTNENC, 2)
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
