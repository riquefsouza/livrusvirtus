require 'fox'
include Fox
require 'RotinasGlobais'
require 'resource'

class FRMSobre < FXDialogBox

  def initialize(owner)
    super(owner, Resource::STR_OPSOBRE, DECOR_TITLE | DECOR_CLOSE,
      0, 0, 0, 0, 0, 0, 0, 0, 4, 4)

    setIcon($Rotinas.lerFigura(getApp(), "Livrus.bmp"))
    
    grupo = FXGroupBox.new(self, "",
    GROUPBOX_TITLE_LEFT|FRAME_RIDGE|LAYOUT_FILL_X)

    bmpLivrusVirtus = $Rotinas.lerFigura(getApp(), "livrusvirtus.bmp")
    
    FXLabel.new(grupo, "", bmpLivrusVirtus, LAYOUT_CENTER_X)
    FXLabel.new(grupo, "Versão: 1.0.0", nil, LAYOUT_RIGHT)
    FXLabel.new(grupo, 
      "Todos os direitos reservados para: Henrique F. de Souza", 
      nil, LAYOUT_CENTER_X)
    FXLabel.new(grupo, "Sistema integrante do projeto Livrus Virtus, ", 
      nil, LAYOUT_CENTER_X)
    FXLabel.new(grupo, "versão programada em Ruby usando a FOX GUI Toolkit", 
      nil, LAYOUT_CENTER_X)
    
    frameok = FXHorizontalFrame.new(self,
      LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH)
    FXButton.new(frameok, "&Ok", nil, self, FXDialogBox::ID_CANCEL,
      LAYOUT_CENTER_X|FRAME_RAISED|FRAME_THICK, 0, 0, 0, 0, 30, 30)
  end

  def create
    super
    show(PLACEMENT_SCREEN)
  end 

end
