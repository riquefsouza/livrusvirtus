without warning
with trace
include wxEuphoria.e
include wxGraphics.e
include wxDialog.e
include wxText.e
include wxButton.e
include wxSizer.e

--include livrusvirtus.xpm

constant ID_FRMSOBRE_LABBMP = 300
constant ID_FRMSOBRE_LABVERSAO = 301
constant ID_FRMSOBRE_LABDIREITOS = 302
constant ID_FRMSOBRE_LABSISTEMA = 303
constant ID_FRMSOBRE_BTNOK = 304

atom frmSobre_labBmp, frmSobre_labVersao, frmSobre_labDireitos, 
  frmSobre_labSistema, frmSobre_btnOk, bmp_sobre

object void
global constant frmSobre = create( wxDialog,{0, -1, STR_OPSOBRE, 498, 310,
      306, 200, wxDEFAULT_DIALOG_STYLE, ""} )

procedure frmSobre_IniciaControles()
  --bmp_sobre = create( wxBitmap, {BM_XPM, livrusvirtus_xpm}),
  bmp_sobre = create( wxBitmap, {BM_FROM_FILE, "livrusvirtus.xpm", wxBITMAP_TYPE_XPM})
  frmSobre_labBmp = create( wxPanel, {frmSobre, ID_FRMSOBRE_LABBMP, 24, 20, 254, 72})
	frmSobre_labVersao = create( wxStaticText, {frmSobre, ID_FRMSOBRE_LABVERSAO,
    "Versão: 1.0.0", 200, 96, 63, 13 })
	frmSobre_labDireitos = create( wxStaticText, {frmSobre, ID_FRMSOBRE_LABDIREITOS,
    "Todos os diretos reservados para: Henrique F. de Souza",
    16, 112, 266, 13 })
	frmSobre_labSistema = create( wxStaticText, {frmSobre, ID_FRMSOBRE_LABSISTEMA, 
    "Sistema integrante do projeto Livrus Virtus, versão programada usando a wxEuphoria.",
    16, 131, 264, 29, wxALIGN_CENTER})
	frmSobre_btnOk = create( wxButton, {frmSobre, wxID_OK, "&Ok",
    111, 180, 75, 25})
	set_default_item(frmSobre, frmSobre_btnOk)
end procedure

procedure frmSobre_FazLayout(atom parent)
atom sizer_1, sizer_2

	sizer_1 = create( wxBoxSizer, {wxVERTICAL} )
	sizer_2 = create( wxBoxSizer,{wxVERTICAL} )
  add_window_to_sizer( sizer_2, frmSobre_labBmp, 0, wxALIGN_CENTER_HORIZONTAL, 0 )
  add_window_to_sizer( sizer_2, frmSobre_labVersao, 0, wxALL + wxALIGN_RIGHT, 2 )
  add_window_to_sizer( sizer_2, frmSobre_labDireitos, 0, wxALL, 2 )
  add_window_to_sizer( sizer_2, frmSobre_labSistema, 0, wxALL + 
    wxALIGN_CENTER_HORIZONTAL +  wxALIGN_CENTER_VERTICAL, 2 )
  add_sizer_to_sizer( sizer_1, sizer_2, 1, wxALL + wxEXPAND, 6)
  add_window_to_sizer( sizer_1, frmSobre_btnOk, 0, 
    wxALL + wxALIGN_CENTER_HORIZONTAL, 4)
  set_sizer( parent, sizer_1 )
end procedure

frmSobre_IniciaControles()
frmSobre_FazLayout(frmSobre)

procedure onpaint( atom this, atom id, atom event_type, atom event )
	atom dc

	dc = create( wxPaintDC, {this})
	draw_bitmap( dc, bmp_sobre,  0, 0, 1 )
	delete_instance(dc)
end procedure
set_event_handler( frmSobre_labBmp, get_id(frmSobre_labBmp), wxEVT_PAINT, 
  routine_id("onpaint"))
