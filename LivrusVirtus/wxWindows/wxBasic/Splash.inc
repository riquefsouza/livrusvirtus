option explicit

Const ID_TIMER = 100

dim common frmSplash_mTimer

function frmSplash_Criar()
  dim fSplash = new wxDialog(0, -1, STR_TITULO, wxPoint(0, 0), 
      wxSize(255, 73), wxNO_BORDER, "") 
  fSplash.SetClientSize(wxSize(255, 73))
  fSplash.Centre()

  dim bmp_splash = new wxEmptyBitmap( 0, 0 ) 
  bmp_splash.LoadFile( "xpms/livrusvirtus.xpm", wxBITMAP_TYPE_XPM ) 

  dim	frmSplash_labBmp = new wxStaticBitmap(fSplash, -1, 
    wxPoint(0, 0), wxSize(254, 72), bmp_splash)

  frmSplash_mTimer = new wxTimer(fSplash, ID_TIMER)
  frmSplash_mTimer.Start(1000)

  return fSplash
end function

dim common frmSplash = frmSplash_Criar()

Function frmSplash_OnTimer( event )
  frmSplash_mTimer.Stop()
  frmSplash.Close()
End Function
Connect( frmSplash, ID_TIMER, wxEVT_TIMER, "frmSplash_OnTimer" )

Function frmSplash_OnClose( event )
  frmLogin.Show(True)
  frmSplash.Destroy()
  event.Skip()
End Function
Connect( frmSplash, wxEVT_CLOSE_WINDOW, "frmSplash_OnClose" )
