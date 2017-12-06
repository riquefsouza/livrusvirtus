require 'wxruby'
require 'Login'

$fSplash = nil

class FrmSplash < Wx::Dialog
  ID_TIMER = 1000
  def initialize()
    super(nil, -1, "Livrus Virtus", Wx::Point.new(0, 0), 
      Wx::Size.new(255, 73), Wx::THICK_FRAME, "") 
    set_client_size(Wx::Size.new(255, 73))
    centre()
    
    @labBmp = Wx::StaticBitmap.new(self, -1, 
      Wx::Bitmap.new("xpms\\livrusvirtus.xpm", Wx::BITMAP_TYPE_ANY),
      Wx::Point.new(0, 0), Wx::Size.new(254, 72))

    @mTimer = Wx::Timer.new(self, ID_TIMER)
    @mTimer.start(1000)

    evt_close {|event| on_close(event)}
    evt_timer(ID_TIMER) {onTimer}
  end

  def onTimer
    @mTimer.stop()
    self.close()
  end

  def on_close(event)
    fLogin = FrmLogin.new
    fLogin.show(true)
    self.destroy()
    event.skip()
  end

end
