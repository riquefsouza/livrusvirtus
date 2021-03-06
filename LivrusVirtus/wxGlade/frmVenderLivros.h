// -*- C++ -*- generated by wxGlade 0.3.1 on Mon Dec 27 07:02:26 2004

#include <wx/wx.h>
#include <wx/image.h>

#ifndef FRMVENDERLIVROS_H
#define FRMVENDERLIVROS_H

// begin wxGlade: dependencies
// end wxGlade


class frmVenderLivros: public wxPanel {
public:
    // begin wxGlade: frmVenderLivros::ids
    // end wxGlade

    frmVenderLivros(wxWindow* parent, int id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0);

private:
    // begin wxGlade: frmVenderLivros::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: frmVenderLivros::attributes
    wxStaticText* labDtHrVenda;
    wxTextCtrl* edtDtHrVenda;
    wxStaticText* labCodigo;
    wxTextCtrl* edtCodigo;
    wxStaticText* labDescricao;
    wxTextCtrl* edtDescricao;
    wxButton* btnPCliente;
    wxStaticText* labISBN;
    wxTextCtrl* edtISBN;
    wxStaticText* labLivro;
    wxTextCtrl* edtLivro;
    wxButton* btnAdLivros;
    wxButton* btnPLivro;
    wxStaticText* labLivros;
    wxListBox* lstLivros;
    wxStaticText* labPrecoTotal;
    wxTextCtrl* edtPrecoTotal;
    wxButton* btnVender;
    wxButton* btnLimpar;
    wxButton* btnFechar;
    // end wxGlade
};


#endif // FRMVENDERLIVROS_H
