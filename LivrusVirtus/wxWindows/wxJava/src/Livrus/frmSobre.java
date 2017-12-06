package Livrus;

import org.wxwindows.*;

public class frmSobre extends wxDialog
{
  public static frmSobre fSobre = null;

  private static int ID_FRMSOBRE_LABBMP = 300;
  private static int ID_FRMSOBRE_LABVERSAO = 301;
  private static int ID_FRMSOBRE_LABDIREITOS = 302;
  private static int ID_FRMSOBRE_LABSISTEMA = 303;
  private static int ID_FRMSOBRE_BTNOK	= 304;

  private wxStaticBitmap labBmp;
  private wxStaticText labVersao;
  private wxStaticText labDireitos;
  private wxStaticText labSistema;
  private wxButton btnOk;

  public frmSobre( wxWindow parent ) {
    super(parent, -1, "Sobre o Sistema");

    Center();
    labBmp = new wxStaticBitmap(this, ID_FRMSOBRE_LABBMP,
      new wxBitmap(Resource.XPM_LIVRUSVIRTUS, wxBITMAP_TYPE_XPM),
      new wxPoint(24, 20), new wxSize(254, 72),0);
    labVersao = new wxStaticText(this, ID_FRMSOBRE_LABVERSAO,
      "Versão: 1.0.0", new wxPoint(200, 96), new wxSize(63, 13) );
          labDireitos = new wxStaticText(this, ID_FRMSOBRE_LABDIREITOS,
      "Todos os diretos reservados para: Henrique F. de Souza",
      new wxPoint(16, 112), new wxSize(266, 13) );
    labSistema = new wxStaticText(this, ID_FRMSOBRE_LABSISTEMA,
      "Sistema integrante do projeto Livrus Virtus, " +
      "versão programada em Java usando a wx4J",
      new wxPoint(16, 131), new wxSize(264, 29), wxALIGN_CENTRE);
    btnOk = new wxButton(this, wxID_OK, "&Ok",
      new wxPoint(111, 180), new wxSize(75, 25));

    btnOk.SetDefault();
    FazLayout();
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer sizer_2 = new wxStaticBoxSizer(
        new wxStaticBox(this, -1,""), wxVERTICAL);
    sizer_2.Add(labBmp, 0, wxALIGN_CENTER_HORIZONTAL, 0);
    sizer_2.Add(labVersao, 0, wxALL|wxALIGN_RIGHT, 2);
    sizer_2.Add(labDireitos, 0, wxALL, 2);
    sizer_2.Add(labSistema, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|
                wxALIGN_CENTER_VERTICAL, 2);
    sizer_1.Add(sizer_2, 1, wxALL|wxEXPAND, 6);
    sizer_1.Add(btnOk, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 4);
    this.SetSizer(sizer_1);
    sizer_1.SetSizeHints(this);
    sizer_1.Fit(this);
    this.Layout();
  }
}
