require 'fox'
include Fox
require 'Login'

$frmSplash = nil

class FRMSplash < FXDialogBox

  ID_FRMSPLASH_TIMER = 100

  def initialize(owner)
    super(owner, "Splash", DECOR_NONE,
      0, 0, 0, 0, 0, 0, 0, 0, 4, 4)

    FXMAPFUNC(SEL_TIMEOUT, ID_FRMSPLASH_TIMER, :onTimer)

    bmpLivrusVirtus = $Rotinas.lerFigura(getApp(), "livrusvirtus.bmp")
    FXLabel.new(self, "", bmpLivrusVirtus, LAYOUT_CENTER_X)
  end
  
  def create
    super
  end 

  def iniciaTimer()
    @mTimer = getApp().addTimeout(1000, self, ID_FRMSPLASH_TIMER)
  end
  
  def onTimer(sender, sel, ptr)
    @mTimer = nil
    $frmLogin.show(PLACEMENT_SCREEN)
    self.destroy()
    return true
  end

end
