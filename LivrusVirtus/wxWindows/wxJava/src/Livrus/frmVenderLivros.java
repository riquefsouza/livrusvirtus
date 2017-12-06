package Livrus;

import org.wxwindows.*;
import java.sql.*;
import java.util.*;

public class frmVenderLivros
    extends frmCadastros {

  private static int ID_FRMVENDERLIVROS_BTNVENDER = 3000;
  private static int ID_FRMVENDERLIVROS_BTNLIMPAR = 3001;
  private static int ID_FRMVENDERLIVROS_BTNFECHAR = 3002;
  private static int ID_FRMVENDERLIVROS_BTNPCLIENTE = 3003;
  private static int ID_FRMVENDERLIVROS_BTNPLIVRO = 3004;
  private static int ID_FRMVENDERLIVROS_LSTLIVROS = 3005;
  private static int ID_FRMVENDERLIVROS_EDTDTHRVENDA = 3006;
  private static int ID_FRMVENDERLIVROS_EDTISBN = 3007;
  private static int ID_FRMVENDERLIVROS_EDTLIVRO = 3008;
  private static int ID_FRMVENDERLIVROS_EDTPRECOTOTAL = 3009;
  private static int ID_FRMVENDERLIVROS_LABDTHRVENDA = 3010;
  private static int ID_FRMVENDERLIVROS_LABISBN = 3011;
  private static int ID_FRMVENDERLIVROS_LABLIVRO = 3012;
  private static int ID_FRMVENDERLIVROS_LABLIVROS = 3013;
  private static int ID_FRMVENDERLIVROS_LABPRECOTOTAL = 3014;
  private static int ID_FRMVENDERLIVROS_BTNADLIVROS = 3015;

  private ArrayList slPrecos, slISBNs, slQtdEstoque;
  private float nPrecoTotal;
  private wxStaticText labDtHrVenda;
  private wxTextCtrl edtDtHrVenda;
  private wxButton btnPCliente;
  private wxStaticText labISBN;
  private wxTextCtrl edtISBN;
  private wxStaticText labLivro;
  private wxTextCtrl edtLivro;
  private wxButton btnAdLivros;
  private wxButton btnPLivro;
  private wxStaticText labLivros;
  private wxListBox lstLivros;
  private wxStaticText labPrecoTotal;
  private wxTextCtrl edtPrecoTotal;
  private wxButton btnVender;

  public frmVenderLivros(wxWindow parent) {
    super(parent, TextValidator.FILTER_NONE, false);

    slPrecos = new ArrayList();
    slISBNs = new ArrayList();
    slQtdEstoque = new ArrayList();
    btnNovo.Show(false);

    labDtHrVenda = new wxStaticText(this, ID_FRMVENDERLIVROS_LABDTHRVENDA,
                                    "Data/Hora Venda: ", new wxPoint(8, 8),
                                    new wxSize(91, 13), 0);
    edtDtHrVenda = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTDTHRVENDA,
                                  "", new wxPoint(8, 24), new wxSize(128, 21),
                                  0);
    edtDtHrVenda.Disable();

    labCodigo.SetLabel("CPF: ");
    labCodigo.SetSize(8, 48, 48, 13);
    edtCodigo.SetSize(8, 64, 128, 21);
    edtCodigo.EVT_KILL_FOCUS(new OnEdtCodigo_Killfocus());

    labDescricao.SetLabel("Cliente: ");
    labDescricao.SetSize(142, 48, 56, 13);
    edtDescricao.SetSize(142, 64, 306, 21);
    edtDescricao.Disable();

    btnPCliente = new wxButton(this, ID_FRMVENDERLIVROS_BTNPCLIENTE,
                               "...", new wxPoint(448, 64), new wxSize(21, 21),
                               0);

    labISBN = new wxStaticText(this, ID_FRMVENDERLIVROS_LABISBN,
                               "ISBN: ", new wxPoint(8, 88), new wxSize(48, 13),
                               0);
    edtISBN = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTISBN,
                             "", new wxPoint(8, 104), new wxSize(128, 21), 0);
    edtISBN.EVT_KILL_FOCUS(new OnEdtISBN_Killfocus());

    labLivro = new wxStaticText(this, ID_FRMVENDERLIVROS_LABLIVRO,
                                "Livro: ", new wxPoint(142, 88),
                                new wxSize(40, 13), 0);
    edtLivro = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTLIVRO,
                              "", new wxPoint(142, 104), new wxSize(282, 21), 0);
    edtLivro.Disable();

    btnAdLivros = new wxButton(this, ID_FRMVENDERLIVROS_BTNADLIVROS,
                               "+", new wxPoint(424, 104), new wxSize(21, 21),
                               0);

    btnPLivro = new wxButton(this, ID_FRMVENDERLIVROS_BTNPLIVRO,
                             "...", new wxPoint(448, 104), new wxSize(21, 21),
                             0);

    labLivros = new wxStaticText(this, ID_FRMVENDERLIVROS_LABLIVROS,
                                 "Livros para vender: ", new wxPoint(8, 128),
                                 new wxSize(120, 13), 0);

    lstLivros = new wxListBox(this, ID_FRMVENDERLIVROS_LSTLIVROS,
                              new wxPoint(8, 144), new wxSize(464, 96));

    labPrecoTotal = new wxStaticText(this, ID_FRMVENDERLIVROS_LABPRECOTOTAL,
                                     "Preço Total: ", new wxPoint(280, 248),
                                     new wxSize(61, 13), 0);
    edtPrecoTotal = new wxTextCtrl(this, ID_FRMVENDERLIVROS_EDTPRECOTOTAL,
                                   "R$ 0,00", new wxPoint(344, 246),
                                   new wxSize(127, 21), 0);
    edtPrecoTotal.Disable();

    btnVender = new wxButton(this, ID_FRMVENDERLIVROS_BTNVENDER,
                             "&Vender", new wxPoint(239, 275),
                             new wxSize(75, 25), 0);
    btnLimpar = new wxButton(this, ID_FRMVENDERLIVROS_BTNLIMPAR,
                             "&Limpar", new wxPoint(319, 275),
                             new wxSize(75, 25), 0);
    btnFechar = new wxButton(this, ID_FRMVENDERLIVROS_BTNFECHAR,
                             "&Fechar", new wxPoint(399, 275),
                             new wxSize(75, 25), 0);

    FazLayout();

    edtDtHrVenda.SetValue(RotinasGlobais.Rotinas.retDataHoraStr(true, true));
    edtCodigo.SetValidator(new TextValidator(edtCodigo,
                                             TextValidator.FILTER_NONE, 14));
    edtISBN.SetValidator(new TextValidator(edtISBN,
                                           TextValidator.FILTER_NONE, 13));
    nPrecoTotal = 0;

    EVT_BUTTON(ID_FRMVENDERLIVROS_BTNVENDER, new OnBtnVenderClick());
    EVT_BUTTON(ID_FRMVENDERLIVROS_BTNLIMPAR, new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMVENDERLIVROS_BTNFECHAR, new OnBtnFecharClick());
    EVT_CLOSE(new OnClose());
    EVT_BUTTON(ID_FRMVENDERLIVROS_BTNPCLIENTE,
               new OnBtnPCliente());
    EVT_BUTTON(ID_FRMVENDERLIVROS_BTNPLIVRO, new OnBtnPLivro());
    EVT_BUTTON(ID_FRMVENDERLIVROS_BTNADLIVROS,
               new OnBtnAdLivros());
    EVT_LISTBOX_DCLICK(ID_FRMVENDERLIVROS_LSTLIVROS,
                       new OnLstLivros_Dblclk());
  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_6 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_7 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_5 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_8 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_7 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_6 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_5 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_4 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_3 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_sizer_2 = new wxGridSizer(2, 1, 0, 0);
    wxBoxSizer sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_1 = new wxGridSizer(2, 1, 0, 0);
    grid_sizer_1.Add(labDtHrVenda, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_1.Add(edtDtHrVenda, 0, 0, 0);
    sizer_2.Add(grid_sizer_1, 0, wxLEFT, 2);
    sizer_2.Add(20, 20, 0, 0, 0);
    sizer_1.Add(sizer_2, 0, 0, 0);
    grid_sizer_2.Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_2.Add(edtCodigo, 0, 0, 0);
    sizer_3.Add(grid_sizer_2, 0, wxLEFT, 2);
    grid_sizer_3.Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_3.Add(edtDescricao, 0, 0, 0);
    sizer_3.Add(grid_sizer_3, 0, wxLEFT, 2);
    grid_sizer_4.Add(20, 20, 0, 0, 0);
    grid_sizer_4.Add(btnPCliente, 0, 0, 0);
    sizer_3.Add(grid_sizer_4, 0, 0, 0);
    sizer_1.Add(sizer_3, 0, 0, 0);
    grid_sizer_5.Add(labISBN, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_5.Add(edtISBN, 0, 0, 0);
    sizer_4.Add(grid_sizer_5, 0, wxLEFT, 2);
    grid_sizer_6.Add(labLivro, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_6.Add(edtLivro, 0, 0, 0);
    sizer_4.Add(grid_sizer_6, 0, wxLEFT, 2);
    grid_sizer_7.Add(20, 20, 0, 0, 0);
    grid_sizer_7.Add(btnAdLivros, 0, 0, 0);
    sizer_4.Add(grid_sizer_7, 1, wxEXPAND, 0);
    grid_sizer_8.Add(20, 20, 0, 0, 0);
    grid_sizer_8.Add(btnPLivro, 0, 0, 0);
    sizer_4.Add(grid_sizer_8, 0, 0, 0);
    sizer_1.Add(sizer_4, 0, 0, 0);
    sizer_5.Add(labLivros, 0, wxALIGN_BOTTOM, 0);
    sizer_5.Add(lstLivros, 1, wxALL | wxEXPAND, 1);
    sizer_1.Add(sizer_5, 1, wxEXPAND, 0);
    sizer_7.Add(labPrecoTotal, 0, wxALL, 2);
    sizer_7.Add(edtPrecoTotal, 0, wxALL, 2);
    sizer_6.Add(sizer_7, 0, wxALL |
                wxALIGN_RIGHT, 2);
    sizer_8.Add(btnVender, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_8.Add(btnLimpar, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_8.Add(btnFechar, 0, wxALL |
                wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_6.Add(sizer_8, 0, wxALL, 2);
    sizer_1.Add(sizer_6, 0, wxALIGN_RIGHT |
                wxALIGN_BOTTOM, 0);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1.Fit(this);
    sizer_1.SetSizeHints(this);
  }

  private void LimpaDados() {
    edtDtHrVenda.SetValue(RotinasGlobais.Rotinas.retDataHoraStr(true, true));
    edtCodigo.Clear();
    edtDescricao.Clear();
    edtISBN.Clear();
    edtLivro.Clear();
    lstLivros.Clear();
    nPrecoTotal = 0;
    edtPrecoTotal.SetValue("R$ 0,00");
    edtCodigo.SetFocus();
  }

  private boolean ValidaDados() {
    if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.GetValue(),
                                           Resource.STR_CPFNINF)) {
      return false;
    }
    if (lstLivros.GetCount() == 0) {
      wx.wxMessageBox(Resource.STR_LIVVENNINF, "Erro",
                      wx.wxOK | wx.wxICON_ERROR);
      return false;
    }
    return true;
  }

  private boolean SalvaLista() {
    String sCPF, sISBN, sPrecoTotal, sDataHora, sQtdEstoque, sDTHR;
    int nCont, nQtd, nQtdEstoque;

    nQtd = lstLivros.GetCount();
    sCPF = edtCodigo.GetValue();
    sPrecoTotal = Float.toString(nPrecoTotal);

    sDTHR = edtDtHrVenda.GetValue();
    sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr(sDTHR,
        "dd/MM/YYYY hh:mm:ss", "MM/dd/YYYY hh:mm:ss");

    for (nCont = 0; nCont < nQtd; nCont++) {
      sISBN = slISBNs.get(nCont).toString();

      RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                           ConsultasSQL.ConsSQL.Venda('I',
          sISBN, sCPF, sDataHora,
          RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal, false), ""));

      nQtdEstoque = Integer.parseInt(slQtdEstoque.get(nCont).toString());
      if (nQtdEstoque >= 0) {
        nQtdEstoque = nQtdEstoque - 1;
      }
      sQtdEstoque = Integer.toString(nQtdEstoque);
      RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
                                           ConsultasSQL.ConsSQL.Venda('U',
          sISBN, "", "", "", sQtdEstoque));
    }
    return true;
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      GetParent().Close();
      event.Skip();
    }
  }

  class OnBtnFecharClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      Close(true);
      event.Skip();
    }
  }

  class OnEdtCodigo_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCodigo.GetValue().length() > 0) {
          if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.GetValue())) {
            Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
                ConsultasSQL.ConsSQL.Cliente('S', edtCodigo.GetValue(),
                                             "", "", "", "", "", "", "", "", ""),
                Resource.STR_CLINENC);
            if (Consulta == null) {
              edtCodigo.Clear();
              edtCodigo.SetFocus();
            }
            else {
              edtDescricao.SetValue(Consulta.getObject(2).toString());
            }
          }
          else {
            wx.wxMessageBox(Resource.STR_CPFINV, "Erro",
                            wx.wxOK | wx.wxICON_ERROR);
            edtCodigo.Clear();
            edtCodigo.SetFocus();
          }
        }
        else {
          edtDescricao.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      }
    }
  }

  class OnBtnPCliente
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      frmConClientes fConClientes = new frmConClientes(null);
      fConClientes.ShowModal();
      edtCodigo.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCodigo_Killfocus kf = new OnEdtCodigo_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnEdtISBN_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      int nQtdEstoque;
      String sQtdEstoque;
      try {
        if (edtISBN.GetValue().length() > 0) {
          if (RotinasGlobais.Rotinas.ValidaISBN(edtISBN.GetValue())) {
            Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
                ConsultasSQL.ConsSQL.Livro('Q', edtISBN.GetValue(),
                                           "", "", "", "", "", "", "", "", ""),
                Resource.STR_LIVNENC);
            if (Consulta == null) {
              edtISBN.Clear();
              edtISBN.SetFocus();
            }
            else {
              edtLivro.SetValue(Consulta.getObject(2).toString());
              sQtdEstoque = Consulta.getObject(4).toString();
              nQtdEstoque = Integer.parseInt(sQtdEstoque);
              if (nQtdEstoque > 0) {
                RotinasGlobais.Rotinas.sPreco = Consulta.getObject(3).toString();
                RotinasGlobais.Rotinas.sQtdEstoque = sQtdEstoque;
              }
              else {
                wx.wxMessageBox(Resource.STR_LIVNEST, "Erro",
                                wx.wxOK | wx.wxICON_ERROR);
              }
            }
          }
          else {
            wx.wxMessageBox(Resource.STR_ISBNINV, "Erro",
                            wx.wxOK | wx.wxICON_ERROR);
            edtISBN.Clear();
            edtISBN.SetFocus();
          }
        }
        else {
          edtLivro.Clear();
        }
      }
      catch (SQLException se) {
        wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      }
    }
  }

  class OnBtnPLivro
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      frmConLivros fConLivros = new frmConLivros(null);
      fConLivros.ShowModal();
      edtISBN.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtISBN_Killfocus kf = new OnEdtISBN_Killfocus();
      kf.handleEvent(null);
      event.Skip();
    }
  }

  class OnBtnAdLivros
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      float nPreco;
      String sLivros, sISBN, sEdtLivro, sPrecoTotal;

      sISBN = edtISBN.GetValue();
      sEdtLivro = edtLivro.GetValue();
      if (sISBN.length() > 0) {
        sLivros = sISBN + " - " + sEdtLivro + " - R$ " +
            RotinasGlobais.Rotinas.sPreco;
        if (lstLivros.FindString(sLivros) == -1) {
          slISBNs.add(sISBN);
          slPrecos.add(RotinasGlobais.Rotinas.sPreco);
          slQtdEstoque.add(RotinasGlobais.Rotinas.sQtdEstoque);
          lstLivros.Append(sLivros);
          nPreco = Float.parseFloat(RotinasGlobais.Rotinas.sPreco);
          nPrecoTotal = nPrecoTotal + nPreco;
        }
        edtISBN.Clear();
        edtLivro.Clear();
        sPrecoTotal = "R$ " + Float.toString(nPrecoTotal);
        edtPrecoTotal.SetValue(
            RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal, true));
      }
      event.Skip();
    }
  }

  class OnLstLivros_Dblclk
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      String sPrecoTotal;
      float nPreco;
      int nSelIndice;

      if (lstLivros.GetCount() > 0) {
        nSelIndice = lstLivros.GetSelection();
        if (lstLivros.Selected(nSelIndice)) {
          nPreco = Float.parseFloat(slPrecos.get(nSelIndice).toString());
          nPrecoTotal = nPrecoTotal - nPreco;
          sPrecoTotal = "R$ " + Float.toString(nPrecoTotal);
          edtPrecoTotal.SetValue(
              RotinasGlobais.Rotinas.VirgulaParaPonto(sPrecoTotal, true));
          slISBNs.remove(nSelIndice);
          slPrecos.remove(nSelIndice);
          slQtdEstoque.remove(nSelIndice);
          lstLivros.Delete(nSelIndice);
        }
      }
      event.Skip();
    }
  }

  class OnBtnVenderClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      if (ValidaDados()) {
        if (SalvaLista()) {
          wx.wxMessageBox(Resource.STR_VENRESUC,
                          Resource.STR_TITULO, wx.wxOK | wx.wxICON_INFORMATION);
          LimpaDados();
        }
      }
      event.Skip();
    }
  }

  class OnBtnLimparClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      LimpaDados();
      event.Skip();
    }
  }
}
