#include "resource.h"
#include "Sobre.h"

#ifndef __WXMOTIF__
  #include "xpms/livrus.xpm"
#endif  
#include "xpms/livrusvirtus.xpm"

BEGIN_EVENT_TABLE(CfrmSobre, wxDialog)
    EVT_BUTTON(ID_FRMSOBRE_BTNOK, CfrmSobre::OnBtnOk)
END_EVENT_TABLE()

CfrmSobre::CfrmSobre(wxWindow *parent) 
	: wxDialog(parent, -1, wxT("Sobre o Sistema"), wxPoint(498, 310), 
	wxSize(306, 240), wxDEFAULT_DIALOG_STYLE, wxT("frmSobre"))
{
	IniciaControles();
}

CfrmSobre::~CfrmSobre() { }

void CfrmSobre::IniciaControles() {

#ifdef __WXMSW__
  this->SetIcon(wxIcon(ICO_LIVRUS));
#else
  #ifndef __WXMOTIF__
    this->SetIcon(wxIcon( Livrus_xpm ));
  #endif
#endif

  this->SetClientSize(wxSize(298, 213));
  this->Centre(wxBOTH);
  this->btnOk = new wxButton(this, ID_FRMSOBRE_BTNOK, wxT("&Ok"), 
		wxPoint(111, 180), wxSize(75, 25), 0);
  this->labVersao = new wxStaticText(this, ID_FRMSOBRE_LABVERSAO, 
	  wxT("Versão: 1.0.0"), wxPoint(200, 96), wxSize(63, 13), 0);
  this->labBmp = new wxStaticBitmap(this, ID_FRMSOBRE_LABBMP, 
  	//wxBitmap(BMP_LIVRUSVIRTUS, wxBITMAP_TYPE_BMP), 
    wxBitmap(livrusvirtus_xpm),
    wxPoint(24, 20), wxSize(254, 72), wxTRANSPARENT_WINDOW);
  this->labDireitos = new wxStaticText(this, ID_FRMSOBRE_LABDIREITOS, 
	  wxT("Todos os diretos reservados para: Henrique F. de Souza"), 
	  wxPoint(16, 112), wxSize(266, 13), 0);
  wxString sSistema = wxT("Sistema integrante do projeto Livrus Virtus, versão ");
  sSistema.Append(wxT("programada no Visual C++ 6.0 em wxWindows."));
  this->labSistema = new wxStaticText(this, ID_FRMSOBRE_LABSISTEMA, 
    sSistema, wxPoint(32, 131), wxSize(240, 29), 0);

  FazLayout();
}

void CfrmSobre::FazLayout()
{
  wxBoxSizer* sizer_1 = new wxBoxSizer(wxVERTICAL);
  wxStaticBoxSizer* sizer_2 = 
    new wxStaticBoxSizer(new wxStaticBox(this, -1, wxT("")), wxVERTICAL);
  sizer_2->Add(labBmp, 0, wxALIGN_CENTER_HORIZONTAL, 0);
  sizer_2->Add(labVersao, 0, wxALL|wxALIGN_RIGHT, 2);
  sizer_2->Add(labDireitos, 0, wxALL, 2);
  sizer_2->Add(labSistema, 0,
    wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
  sizer_1->Add(sizer_2, 1, wxALL|wxEXPAND, 6);
  sizer_1->Add(btnOk, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
  SetAutoLayout(true);
  SetSizer(sizer_1);
  sizer_1->Fit(this);
  sizer_1->SetSizeHints(this);
  Layout();
  Centre();
}

void CfrmSobre::OnBtnOk(wxCommandEvent& WXUNUSED(event))
{
    this->EndModal(wxID_OK);
}

