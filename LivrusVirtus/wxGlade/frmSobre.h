// -*- C++ -*- generated by wxGlade 0.3.1 on Mon Dec 27 07:02:26 2004

#include <wx/wx.h>
#include <wx/image.h>

#ifndef FRMSOBRE_H
#define FRMSOBRE_H

// begin wxGlade: dependencies
// end wxGlade


class frmSobre: public wxDialog {
public:
    // begin wxGlade: frmSobre::ids
    // end wxGlade

    frmSobre(wxWindow* parent, int id, const wxString& title, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=wxDEFAULT_DIALOG_STYLE);

private:
    // begin wxGlade: frmSobre::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: frmSobre::attributes
    wxStaticBitmap* labBmp;
    wxStaticText* labVersao;
    wxStaticText* labDireitos;
    wxStaticText* labSistema;
    wxButton* btnOk;
    // end wxGlade
};


#endif // FRMSOBRE_H
