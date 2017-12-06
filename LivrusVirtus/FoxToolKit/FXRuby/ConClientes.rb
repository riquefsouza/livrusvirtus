require 'fox'
require 'fox/responder'
require 'resource'
require 'Principal'
require 'ConsultasSQL'
require 'Consultas'
include Fox
include Responder

class FRMConClientes < FRMConsultas
  
  def initialize(owner)  
    super(owner, Resource::STR_CONCLIENTE)

    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNPESQUISAR, :onBtnPesquisar)
    FXMAPFUNC(SEL_COMMAND, ID_FRMCONSULTAS_BTNLIMPAR, :onBtnLimpar)
    FXMAPFUNC(SEL_SELECTED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridSelected)
    FXMAPFUNC(SEL_CHANGED, ID_FRMCONSULTAS_GRIDCONSULTA, :onGridChanged)
    
    @labDescricao.setText("Cliente:")
    $Rotinas.IniciaLayoutGrid(@gridConsulta, 2, 18)
    @gridConsulta.setItemText(0, 1, "CPF")
    @gridConsulta.setColumnWidth(1, 90)
    @gridConsulta.setItemText(0, 2, "Nome")
    @gridConsulta.setColumnWidth(2, 220)
  
    nLargura = [ 180,80,40,80,120,80,220,150,
            80,100,100,80,180,80,100 ]
    sRotulos = [ "Email", "Identidade", "Sexo", 
     "Telefone", "DtNascimento", "CodEndereço", "Logradouro", 
     "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País", 
     "CodProfissão", "Profissão" ]
    $Rotinas.AdicionaColunasGrid(@gridConsulta, 3, 15, nLargura, sRotulos)
  end

  def create()
    super
    show(PLACEMENT_SCREEN)
  end
  
  def onBtnPesquisar(sender, sel, ptr)
    PesquisarDados($ConsSQL.Cliente('S',"", @edtDescricao.getText(),
      "","","","","","","",""), Resource::STR_CLINENC, 17)
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
