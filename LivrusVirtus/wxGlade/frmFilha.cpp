// -*- C++ -*- generated by wxGlade 0.3.1 on Mon Dec 27 07:02:26 2004

#include "frmFilha.h"


frmFilha::frmFilha(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxMDIChildFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: frmFilha::frmFilha

    set_properties();
    do_layout();
    // end wxGlade
}


void frmFilha::set_properties()
{
    // begin wxGlade: frmFilha::set_properties
    SetTitle(wxT("Cadastro de"));
    wxIcon _icon;
    _icon.CopyFromBitmap(wxBitmap(wxT("C:\\LivrusVirtus\\VCPP6\\wxWin\\wxODBC\\xpms\\livrus.xpm"), wxBITMAP_TYPE_ANY));
    SetIcon(_icon);
    SetSize(wxSize(400, 300));
    SetBackgroundColour(wxSystemSettings::GetSystemColour(wxSYS_COLOUR_BTNFACE));
    // end wxGlade
}


void frmFilha::do_layout()
{
    // begin wxGlade: frmFilha::do_layout
    Layout();
    // end wxGlade
}
