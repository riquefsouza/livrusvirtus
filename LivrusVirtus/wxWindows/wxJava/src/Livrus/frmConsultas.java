package Livrus;

import org.wxwindows.*;
import java.sql.ResultSet;
import java.util.Vector;

public class frmConsultas
    extends wxDialog {
  protected static int ID_FRMCONSULTAS_BTNFECHAR = 500;
  protected static int ID_FRMCONSULTAS_BTNLIMPAR = 501;
  protected static int ID_FRMCONSULTAS_BTNPESQUISAR = 502;
  protected static int ID_FRMCONSULTAS_EDTDESCRICAO = 503;
  protected static int ID_FRMCONSULTAS_GRIDCONSULTA = 504;
  protected static int ID_FRMCONSULTAS_LABDESCRICAO = 505;
  protected static int ID_FRMCONSULTAS_LABREGISTRO = 506;

  ResultSet rsConsulta;
  Vector Linhas = new Vector();
  private String sSelecionado;

  protected wxStaticText labDescricao;
  protected wxTextCtrl edtDescricao;
  protected wxButton btnPesquisar;
  protected wxStaticText labRegistro;
  protected wxListCtrl gridConsulta;
  protected wxButton btnFechar;
  protected wxButton btnLimpar;

  public frmConsultas( wxWindow parent, String sTitulo ) {
    super(parent, -1, sTitulo, new wxPoint(0, 0), new wxSize(345, 263),
          wxDialog.wxDEFAULT_FRAME_STYLE);
    Centre();

    labDescricao = new wxStaticText(this, ID_FRMCONSULTAS_LABDESCRICAO,
                                    "Descrição:", new wxPoint(8, 8),
                                    new wxSize(51, 13), 0);
    edtDescricao = new wxTextCtrl(this, ID_FRMCONSULTAS_EDTDESCRICAO,
                                  "", new wxPoint(8, 24), new wxSize(257, 21),
                                  0);
    btnPesquisar = new wxButton(this, ID_FRMCONSULTAS_BTNPESQUISAR,
                                "&Pesquisar", new wxPoint(272, 24),
                                new wxSize(75, 25), 0);

    gridConsulta = new wxListCtrl(this, ID_FRMCONSULTAS_GRIDCONSULTA,
                                  new wxPoint(0, 56), new wxSize(345, 125),
                                  wxLC_REPORT | wxSUNKEN_BORDER);
    gridConsulta.InsertColumn(0, "Código", wxLIST_FORMAT_RIGHT);
    gridConsulta.InsertColumn(1, "Descrição");
    gridConsulta.SetColumnWidth(0, 80);
    gridConsulta.SetColumnWidth(1, 220);

    labRegistro = new wxStaticText(this, ID_FRMCONSULTAS_LABREGISTRO,
                                   "Registro 0 de 0", new wxPoint(8, 16),
                                   new wxSize(144, 13), 0);
    btnLimpar = new wxButton(this, ID_FRMCONSULTAS_BTNLIMPAR,
                             "&Limpar", new wxPoint(16, 13), new wxSize(75, 25),
                             0);
    btnFechar = new wxButton(this, ID_FRMCONSULTAS_BTNFECHAR,
                             "&Fechar", new wxPoint(75, 13), new wxSize(75, 25),
                             0);

    FazLayout();
    sSelecionado = "";
    edtDescricao.SetFocus();
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxGridSizer grid_sizer_2 = new wxGridSizer(1, 2, 0, 0);
    wxBoxSizer sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_4 = new wxBoxSizer(wxVERTICAL);
    wxGridSizer grid_sizer_1 = new wxGridSizer(2, 1, 0, 0);
    grid_sizer_1.Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_1.Add(edtDescricao, 0, 0, 0);
    sizer_3.Add(grid_sizer_1, 0, wxALL, 2);
    sizer_4.Add(20, 20, 0, 0, 0);
    sizer_4.Add(btnPesquisar, 0, wxLEFT |
                wxTOP | wxBOTTOM, 5);
    sizer_3.Add(sizer_4, 0, 0, 0);
    sizer_1.Add(sizer_3, 0, wxALL, 4);
    sizer_1.Add(gridConsulta, 1, wxEXPAND, 0);
    grid_sizer_2.Add(labRegistro, 0, wxALL, 10);
    sizer_2.Add(btnLimpar, 0, wxALIGN_RIGHT |
                wxALIGN_BOTTOM, 8);
    sizer_2.Add(btnFechar, 0, wxLEFT |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 8);
    grid_sizer_2.Add(sizer_2, 1, wxALL |
                     wxALIGN_RIGHT | wxALIGN_BOTTOM, 4);
    sizer_1.Add(grid_sizer_2, 0, wxALL |
                wxEXPAND | wxALIGN_BOTTOM, 0);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1.Fit(this);
    sizer_1.SetSizeHints(this);
    Layout();
  }

  protected void Fecha(int nIndMenu) {
    if (sSelecionado.length() > 0) {
      RotinasGlobais.Rotinas.sCodigoSelecionado = sSelecionado;
    }
    else {
      RotinasGlobais.Rotinas.sCodigoSelecionado = "";
    }
    if (nIndMenu == 0) {
      //if (this.GetModal()) {
      //  EndModal(0);
     // }
     // else {
        Close();
     // }
    }
    else {
      frmPrincipal.fPrincipal.barraMenu.GetMenu(1).Enable(nIndMenu, true);
    }
  }

  protected void LimparDados() {
    labRegistro.SetLabel("Registro 0 de 0");
    gridConsulta.DeleteAllItems();
    edtDescricao.Clear();
    edtDescricao.SetFocus();
  }

  protected void PesquisarDados(String sTextoSql, String sMensagemErro,
                                int nQtdCol) {
    rsConsulta = RotinasGlobais.Rotinas.ConsultaDadosLista(sTextoSql);
    if (rsConsulta != null) {
      RotinasGlobais.Rotinas.AdicionaLinhasGrid(gridConsulta, rsConsulta,
                                                nQtdCol);
      setLabRegistros(0);
    }
    else {
      wx.wxMessageBox(sMensagemErro, "Erro", wx.wxOK | wx.wxICON_ERROR);

    }
  }

  protected void setLabRegistros(int nLinha) {
    if (nLinha >= 0) {
      labRegistro.SetLabel("Registro " + Integer.toString(nLinha + 1) +
                            " de " +
                            Integer.toString(gridConsulta.GetItemCount()));
      sSelecionado = gridConsulta.GetItemText(nLinha);
    }
  }

}
