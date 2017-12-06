unit Splash;

interface

uses
  System.Drawing, wx;

type
  TfrmSplash = class(wx.SplashScreen)
  private
    { Private Declarations }
  public
    constructor Create(parent: wx.Window);
    procedure OnClose(sender: System.Object; e: wx.Event);
  end;

var
  frmSplash: TfrmSplash;

const
  ID_FRMSPLASH: integer = 100;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmSplash))]

implementation

uses Login;

constructor TfrmSplash.Create(parent: wx.Window);
begin
  inherited Create( wx.Bitmap.create('xpms/LivrusVirtus.xpm',
    wx.BitmapType.wxBITMAP_TYPE_XPM),
    wx.SplashScreen.wxSPLASH_CENTRE_ON_SCREEN or
    wx.SplashScreen.wxSPLASH_TIMEOUT, 1000, parent, ID_FRMSPLASH,
    wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER or wxSTAY_ON_TOP );

	EVT_CLOSE( OnClose );
end;

procedure TfrmSplash.OnClose(sender: System.Object; e: wx.Event);
begin
  frmLogin := TfrmLogin.Create(nil);
  frmLogin.show(true);
	e.Skip();
end;

end.
