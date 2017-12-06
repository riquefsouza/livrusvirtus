without warning
with trace
include wxEuphoria.e
include wxGraphics.e
include wxDialog.e
include wxTimer.e

constant ID_TIMER = 100

atom frmSplash_mTimer, bmp_splash, frmSplash_labBmp

object void
global constant frmSplash = create( wxDialog,{0, -1, STR_TITULO, 100, 100,
      255, 73, wxNO_BORDER, ""} )

procedure frmSplash_IniciaControles()
  bmp_splash = create( wxBitmap, {BM_FROM_FILE, "livrusvirtus.xpm", wxBITMAP_TYPE_XPM})
  frmSplash_labBmp = create( wxPanel, {frmSplash, -1, 0, 0, 254, 72})

  frmSplash_mTimer = create( wxTimer, {frmSplash, ID_TIMER} )
end procedure

frmSplash_IniciaControles()

procedure onpaint( atom this, atom id, atom event_type, atom event )
	atom dc
	dc = create( wxPaintDC, {this})
	draw_bitmap( dc, bmp_splash,  0, 0, 1 )
	delete_instance(dc)
end procedure
set_event_handler( frmSplash_labBmp, get_id(frmSplash_labBmp), wxEVT_PAINT, 
  routine_id("onpaint"))

procedure onclose( atom this, atom id, atom event_type, atom event )
  --show_window(frmLogin, 1)
  show_window(frmSplash, 0)
end procedure
set_event_handler( frmSplash, get_id(frmSplash), wxEVT_CLOSE_WINDOW, 
  routine_id( "onclose" ))

procedure frmSplash_OnTimer( atom this, atom id, atom event_type, atom event )
  stop_timer( frmSplash_mTimer )
  --onclose(this, id, event_type, event)
  show_window(frmSplash, 0)
end procedure
set_event_handler( frmSplash, ID_TIMER, wxEVT_TIMER, routine_id( "frmSplash_OnTimer" ))

start_timer( frmSplash_mTimer, 1000, 0 )
