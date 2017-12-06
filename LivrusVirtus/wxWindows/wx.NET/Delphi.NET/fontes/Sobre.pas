unit Sobre;

interface

uses
  System.Drawing, wx;

type
  TfrmSobre = class(wx.Dialog)
  private
    labBmp: wx.StaticBitmap;
    labVersao: wx.StaticText;
    labDireitos: wx.StaticText;
    labSistema: wx.StaticText;
    btnOk: wx.Button;
    procedure FazLayout();
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmSobre: TfrmSobre;

const
  ID_FRMSOBRE_LABBMP: integer = 300;
  ID_FRMSOBRE_LABVERSAO: integer = 301;
  ID_FRMSOBRE_LABDIREITOS: integer = 302;
  ID_FRMSOBRE_LABSISTEMA: integer = 303;
  ID_FRMSOBRE_BTNOK: integer = 304;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmSobre))]

implementation

constructor TfrmSobre.Create(parent: wx.Window);
begin
  inherited Create(parent, -1, 'Sobre o Sistema', 
    System.Drawing.Point.Create(498, 310), 
    System.Drawing.Size.Create(306, 240), wxDEFAULT_DIALOG_STYLE,'');

  SetIcon(wx.Icon.create( 'xpms/livrus.xpm' ));
  Centre(wx.Orientation.wxBOTH);

	labBmp := wx.StaticBitmap.create(self, ID_FRMSOBRE_LABBMP, 
    wx.Bitmap.create('xpms/livrusvirtus.xpm'),
    System.Drawing.Point.Create(24, 20), System.Drawing.Size.Create(254, 72));
	labVersao := wx.StaticText.create(self, ID_FRMSOBRE_LABVERSAO, 
    'Versão: 1.0.0', System.Drawing.Point.Create(200, 96), 
    System.Drawing.Size.Create(63, 13) );
	labDireitos := wx.StaticText.create(self, ID_FRMSOBRE_LABDIREITOS, 
    'Todos os diretos reservados para: Henrique F. de Souza', 
    System.Drawing.Point.Create(16, 112), System.Drawing.Size.Create(266, 13));
	labSistema := wx.StaticText.create(self, 
    ID_FRMSOBRE_LABSISTEMA, 'Sistema integrante do projeto Livrus Virtus, ' +
    'versão programada no Delphi.NET usando a wx.NET.', 
    System.Drawing.Point.Create(16, 131), System.Drawing.Size.Create(264, 29), 
    wx.Alignment.wxALIGN_CENTRE);
	btnOk := wx.Button.create(self, wxID_OK, '&Ok', 
    System.Drawing.Point.Create(111, 180), System.Drawing.Size.Create(75, 25));

	btnOk.SetDefault();
	FazLayout();
end;

procedure TfrmSobre.FazLayout();
var sizer_1: wx.BoxSizer;
    sizer_2: wx.StaticBoxSizer;
begin
	sizer_1 := wx.BoxSizer.create(wx.Orientation.wxVERTICAL);
	sizer_2 := wx.StaticBoxSizer.create(wx.StaticBox.create(self, -1,''), 
    wx.Orientation.wxVERTICAL);
	sizer_2.Add(labBmp, 0, wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 0);
	sizer_2.Add(labVersao, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
	sizer_2.Add(labDireitos, 0, wx.Direction.wxALL, 2);
	sizer_2.Add(labSistema, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_CENTER_HORIZONTAL or 
    wx.Alignment.wxALIGN_CENTER_VERTICAL, 2);
	sizer_1.Add(sizer_2, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 6);
	sizer_1.Add(btnOk, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 4);
	self.SetSizer(sizer_1);
	sizer_1.SetSizeHints(self);
	sizer_1.Fit(self);
	self.Layout();
end;

end.
