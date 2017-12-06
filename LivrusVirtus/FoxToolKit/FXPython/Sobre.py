from FXPy.fox import *
from RotinasGlobais import RotinasGlobais
from resource import Resource

def create(parent):
  return frmSobre(parent)

class frmSobre(FXDialogBox):
  def __init__(self, owner):
    FXDialogBox.__init__(self,owner, Resource.STR_OPSOBRE, 
      DECOR_TITLE | DECOR_CLOSE, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4)

    Rotinas = RotinasGlobais.Rotinas
    self.setIcon(Rotinas.lerFigura(self.getApp(), "Livrus.bmp"))
    
    grupo = FXGroupBox(self, "", GROUPBOX_TITLE_LEFT|FRAME_RIDGE|
      LAYOUT_FILL_X)

    bmpLivrusVirtus = Rotinas.lerFigura(self.getApp(), "livrusvirtus.bmp")
    
    FXLabel(grupo, "", bmpLivrusVirtus, LAYOUT_CENTER_X)
    FXLabel(grupo, "Versão: 1.0.0", None, LAYOUT_RIGHT)
    FXLabel(grupo, "Todos os direitos reservados para: Henrique F. de Souza", 
      None, LAYOUT_CENTER_X)
    FXLabel(grupo, "Sistema integrante do projeto Livrus Virtus, ", 
      None, LAYOUT_CENTER_X)
    FXLabel(grupo, "versão programada em Python usando a FOX GUI Toolkit", 
      None, LAYOUT_CENTER_X)
    
    frameok = FXHorizontalFrame(self,
      LAYOUT_BOTTOM|LAYOUT_FILL_X|PACK_UNIFORM_WIDTH)
    FXButton(frameok, "&Ok", None, self, FXDialogBox.ID_CANCEL,
      LAYOUT_CENTER_X|FRAME_RAISED|FRAME_THICK, 0, 0, 0, 0, 30, 30)

  def create(self):
    FXDialogBox.create(self) 
    self.show(PLACEMENT_SCREEN)
