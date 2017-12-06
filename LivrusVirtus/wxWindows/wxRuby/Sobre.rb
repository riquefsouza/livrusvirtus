require 'wxruby'

class FrmSobre < Wx::Dialog
  ID_FRMSOBRE_LABBMP, ID_FRMSOBRE_LABVERSAO, ID_FRMSOBRE_LABDIREITOS, 
  ID_FRMSOBRE_LABSISTEMA, ID_FRMSOBRE_BTNOK = 1000,1001,1002,1003,1004,1005
  def initialize(parent)
    super(parent, -1, "Sobre o Sistema", Wx::Point.new(498, 310), 
      Wx::Size.new(306, 240), Wx::DEFAULT_DIALOG_STYLE,"") 
    set_client_size(Wx::Size.new(298, 213))
    evt_close {|event| on_close(event)}

    #staticBox1 = Wx::StaticBox.new(self, -1, '', 
    #  Wx::Point.new(8, 5), Wx::Size.new(285, 163), 0)
  	@labBmp = Wx::StaticBitmap.new(self, ID_FRMSOBRE_LABBMP, 
      Wx::Bitmap.new("xpms\\livrusvirtus.xpm", Wx::BITMAP_TYPE_ANY),
      Wx::Point.new(24, 20), Wx::Size.new(254, 72))
  	@labVersao = Wx::StaticText.new(self, ID_FRMSOBRE_LABVERSAO, 
      "Versão: 1.0.0", Wx::Point.new(200, 96), Wx::Size.new(63, 13) )
  	@labDireitos = Wx::StaticText.new(self, ID_FRMSOBRE_LABDIREITOS, 
      "Todos os diretos reservados para: Henrique F. de Souza", 
      Wx::Point.new(16, 112), Wx::Size.new(266, 13) )
  	@labSistema = Wx::StaticText.new(self, ID_FRMSOBRE_LABSISTEMA, 
      "Sistema integrante do projeto Livrus Virtus, " +
      "versão programada no wxGlade em wxRuby.", 
      Wx::Point.new(16, 131), Wx::Size.new(264, 29), Wx::ALIGN_CENTRE)
  	@btnOk = Wx::Button.new(self, Wx::ID_OK, "&Ok", Wx::Point.new(111, 180), 
      Wx::Size.new(75, 25))
  
  	@btnOk.set_default()
  	self.centre(Wx::BOTH)
  	FazLayout()
  end

  def on_close(event)
    destroy()
  end

  def FazLayout() 
  	sizer_1 = Wx::BoxSizer.new(Wx::VERTICAL)
  	sizer_2= Wx::StaticBoxSizer.new(Wx::StaticBox.new(self, -1,""), 
      Wx::VERTICAL)
  	sizer_2.add(@labBmp, 0, Wx::ALIGN_CENTER_HORIZONTAL, 0)
  	sizer_2.add(@labVersao, 0, Wx::ALL|Wx::ALIGN_RIGHT, 2)
  	sizer_2.add(@labDireitos, 0, Wx::ALL, 2)
  	sizer_2.add(@labSistema, 0, 
      Wx::ALL|Wx::ALIGN_CENTER_HORIZONTAL|Wx::ALIGN_CENTER_VERTICAL, 2)
  	sizer_1.add(sizer_2, 1, Wx::ALL|Wx::EXPAND, 6)
  	sizer_1.add(@btnOk, 0, Wx::ALL|Wx::ALIGN_CENTER_HORIZONTAL, 4)
  	self.set_auto_layout(true)
  	self.set_sizer(sizer_1)
  	sizer_1.set_size_hints(self)
  	sizer_1.fit(self)
  	self.layout()
  end

end
