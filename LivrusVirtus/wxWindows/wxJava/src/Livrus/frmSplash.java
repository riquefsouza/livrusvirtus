package Livrus;

import org.wxwindows.*;

public class frmSplash extends wxSplashScreen
{
  public static frmSplash fSplash = null;

  public frmSplash(){
    super(new wxBitmap(Resource.XPM_LIVRUSVIRTUS, wxBITMAP_TYPE_XPM),
          wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT,
          1000, null, -1, wxDefaultPosition, wxDefaultSize,
          wxSIMPLE_BORDER | wxFRAME_NO_TASKBAR | wxSTAY_ON_TOP);

    EVT_CLOSE( new OnClose() );
  }

  class OnClose implements wxCloseListener{
    public void handleEvent(wxCloseEvent event){
      frmLogin.fLogin = new frmLogin(null);
      frmLogin.fLogin.Show(true);
      event.Skip();
    }
  }
}

