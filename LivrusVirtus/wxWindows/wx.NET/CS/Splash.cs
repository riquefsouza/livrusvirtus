using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmSplash : wx.SplashScreen
	{
		public static int ID_FRMSPLASH = 100;
		public static frmSplash fSplash = null;

		public frmSplash( Window parent )
			: base(new wx.Bitmap("xpms/LivrusVirtus.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), 
          wx.SplashScreen.wxSPLASH_CENTRE_ON_SCREEN | wx.SplashScreen.wxSPLASH_TIMEOUT, 
          1000, parent, ID_FRMSPLASH, wxDefaultPosition, wxDefaultSize, 
          wxSIMPLE_BORDER | wxSTAY_ON_TOP) {
      EVT_CLOSE(new EventListener( OnClose ));
		}

		public void OnClose( object sender, Event e )	{
      frmLogin.fLogin = new frmLogin(null);
      frmLogin.fLogin.Show(true);
      e.Skip();
		}
	}
}
