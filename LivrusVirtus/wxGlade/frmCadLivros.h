// -*- C++ -*- generated by wxGlade 0.3.1 on Mon Dec 27 07:02:26 2004

#include <wx/wx.h>
#include <wx/image.h>

#ifndef FRMCADLIVROS_H
#define FRMCADLIVROS_H

// begin wxGlade: dependencies
#include <wx/spinctrl.h>
// end wxGlade


class frmCadLivros: public wxPanel {
public:
    // begin wxGlade: frmCadLivros::ids
    // end wxGlade

    frmCadLivros(wxWindow* parent, int id, const wxPoint& pos=wxDefaultPosition, const wxSize& size=wxDefaultSize, long style=0);

private:
    // begin wxGlade: frmCadLivros::methods
    void set_properties();
    void do_layout();
    // end wxGlade

protected:
    // begin wxGlade: frmCadLivros::attributes
    wxStaticText* labCodigo;
    wxTextCtrl* edtCodigo;
    wxButton* btnNovo;
    wxStaticText* labDescricao;
    wxTextCtrl* edtDescricao;
    wxStaticText* labEdicao;
    wxSpinCtrl* edtEdicao;
    wxStaticText* labAnoPubli;
    wxSpinCtrl* edtAnoPubli;
    wxStaticText* labEditora;
    wxTextCtrl* edtCodEditora;
    wxTextCtrl* edtEditora;
    wxButton* btnPEditora;
    wxStaticText* labVolume;
    wxSpinCtrl* edtVolume;
    wxStaticText* labIdioma;
    wxChoice* cmbIdioma;
    wxStaticText* labNPaginas;
    wxSpinCtrl* edtNPaginas;
    wxStaticText* labAssunto;
    wxTextCtrl* edtCodAssunto;
    wxTextCtrl* edtAssunto;
    wxButton* btnAdAssuntos;
    wxButton* btnPAssunto;
    wxStaticText* labPreco;
    wxTextCtrl* edtPreco;
    wxListBox* lstAssuntos;
    wxStaticText* labQtdEstoque;
    wxSpinCtrl* edtQtdEstoque;
    wxStaticText* labAutor;
    wxTextCtrl* edtCodAutor;
    wxTextCtrl* edtAutor;
    wxButton* btnAdAutores;
    wxButton* btnPAutor;
    wxListBox* lstAutores;
    wxButton* btnPesquisar;
    wxButton* btnAnterior;
    wxButton* btnProximo;
    wxButton* btnSalvar;
    wxButton* btnExcluir;
    wxButton* btnLimpar;
    wxButton* btnFechar;
    // end wxGlade
};


#endif // FRMCADLIVROS_H
