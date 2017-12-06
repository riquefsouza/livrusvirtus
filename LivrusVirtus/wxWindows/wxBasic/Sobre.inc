option explicit

Const ID_FRMSOBRE_LABBMP = 300
Const ID_FRMSOBRE_LABVERSAO = 301
Const ID_FRMSOBRE_LABDIREITOS = 302
Const ID_FRMSOBRE_LABSISTEMA = 303
Const ID_FRMSOBRE_BTNOK = 304

dim common frmSobre_labBmp
dim common frmSobre_labVersao
dim common frmSobre_labDireitos
dim common frmSobre_labSistema
dim common frmSobre_btnOk

function frmSobre_Criar()
  dim fSobre = new wxDialog(0, -1, STR_OPSOBRE, wxPoint(498, 310),
      wxSize(306, 240), wxDEFAULT_DIALOG_STYLE, "") 

  fSobre.Centre(wxBOTH)

  dim bmp_sobre = new wxEmptyBitmap( 0, 0 ) 
  bmp_sobre.LoadFile( "xpms/livrusvirtus.xpm", wxBITMAP_TYPE_XPM ) 

	frmSobre_labBmp = new wxStaticBitmap(fSobre, ID_FRMSOBRE_LABBMP, 
    wxPoint(24, 20), wxSize(254, 72), bmp_sobre)
	frmSobre_labVersao = new wxStaticText(fSobre, ID_FRMSOBRE_LABVERSAO,
    "Versão: 1.0.0", wxPoint(200, 96), wxSize(63, 13) )
	frmSobre_labDireitos = new wxStaticText(fSobre, ID_FRMSOBRE_LABDIREITOS,
    "Todos os diretos reservados para: Henrique F. de Souza",
    wxPoint(16, 112), wxSize(266, 13) )
	frmSobre_labSistema = new wxStaticText(fSobre, ID_FRMSOBRE_LABSISTEMA, 
    "Sistema integrante do projeto Livrus Virtus, " &
    "versão programada usando a wxBasic.",
    wxPoint(16, 131), wxSize(264, 29), wxALIGN_CENTRE)
	frmSobre_btnOk = new wxButton(fSobre, wxID_OK, "&Ok",
    wxPoint(111, 180), wxSize(75, 25))

	frmSobre_btnOk.SetDefault()
	frmSobre_FazLayout(fSobre)

  return fSobre
end function

sub frmSobre_FazLayout(parent)
	dim sizer_1 = new wxBoxSizer(wxVERTICAL)
	dim sizer_2 = new wxStaticBoxSizer(new wxStaticBox(parent, -1,""), 
    wxVERTICAL)
	sizer_2.Add(frmSobre_labBmp, 0, wxALIGN_CENTER_HORIZONTAL, 0)
	sizer_2.Add(frmSobre_labVersao, 0, wxALL + wxALIGN_RIGHT, 2)
	sizer_2.Add(frmSobre_labDireitos, 0, wxALL, 2)
	sizer_2.Add(frmSobre_labSistema, 0, wxALL + wxALIGN_CENTER_HORIZONTAL + 
    wxALIGN_CENTER_VERTICAL, 2)
	sizer_1.Add(sizer_2, 1, wxALL + wxEXPAND, 6)
	sizer_1.Add(frmSobre_btnOk, 0, wxALL + wxALIGN_CENTER_HORIZONTAL, 4)
	parent.SetSizer(sizer_1)
	sizer_1.SetSizeHints(parent)
	'sizer_1.Fit(parent)
	parent.Layout()
End Sub

dim common frmSobre = frmSobre_Criar()
