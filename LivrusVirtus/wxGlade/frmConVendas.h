// -*- C++ -*- generated by wxGlade 0.3.1 on Mon Dec 27 07:02:26 2004

#include <wx/wx.h>
#include <wx/image.h>

#ifndef FRMCONVENDAS_H
#define FRMCONVENDAS_H

// begin wxGlade: dependencies
#include <wx/grid.h>
// end wxGlade


class frmConVendas: public wxPanel {
public:
    // begin wxGlade: frmConVendas::ids
    // end wxGlade

    frmConVendas(wxWindow* parent, int id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0);

private:
    // begin wxGlade: frmConVendas::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: frmConVendas::attributes
    wxStaticText* labDtHrVenda;
    wxTextCtrl* edtDtHrVenda;
    wxButton* btnPesquisar;
    wxStaticText* labCPF;
    wxTextCtrl* edtCPF;
    wxStaticText* labCliente;
    wxTextCtrl* edtCliente;
    wxButton* btnPCliente;
    wxStaticText* labISBN;
    wxTextCtrl* edtISBN;
    wxStaticText* labLivro;
    wxTextCtrl* edtLivro;
    wxButton* btnPLivro;
    wxGrid* gridVendas;
    wxStaticText* labRegistro;
    wxStaticText* labPrecoTotal;
    wxTextCtrl* edtPrecoTotal;
    wxButton* btnLimpar;
    wxButton* btnFechar;
    // end wxGlade
};


#endif // FRMCONVENDAS_H
