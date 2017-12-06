package Livrus;

import org.wxwindows.*;
import java.sql.*;
import java.util.*;

public class frmConVendas
    extends wxPanel {

  private static int ID_FRMCONVENDAS_BTNPESQUISAR = 3100;
  private static int ID_FRMCONVENDAS_BTNLIMPAR = 3101;
  private static int ID_FRMCONVENDAS_BTNFECHAR = 3102;
  private static int ID_FRMCONVENDAS_BTNPCLIENTE = 3103;
  private static int ID_FRMCONVENDAS_BTNPLIVRO = 3104;
  private static int ID_FRMCONVENDAS_GRIDVENDAS = 3105;
  private static int ID_FRMCONVENDAS_EDTDTHRVENDA = 3106;
  private static int ID_FRMCONVENDAS_EDTISBN = 3107;
  private static int ID_FRMCONVENDAS_EDTLIVRO = 3108;
  private static int ID_FRMCONVENDAS_EDTPRECOTOTAL = 3109;
  private static int ID_FRMCONVENDAS_LABDTHRVENDA = 3110;
  private static int ID_FRMCONVENDAS_LABISBN = 3111;
  private static int ID_FRMCONVENDAS_LABLIVRO = 3112;
  private static int ID_FRMCONVENDAS_LABPRECOTOTAL = 3113;
  private static int ID_FRMCONVENDAS_LABCPF = 3114;
  private static int ID_FRMCONVENDAS_EDTCPF = 3115;
  private static int ID_FRMCONVENDAS_LABCLIENTE = 3116;
  private static int ID_FRMCONVENDAS_EDTCLIENTE = 3117;
  private static int ID_FRMCONVENDAS_LABREGISTRO = 3118;

  private wxStaticText labDtHrVenda;
  private wxTextCtrl edtDtHrVenda;
  private wxStaticText labCPF;
  private wxTextCtrl edtCPF;
  private wxStaticText labCliente;
  private wxTextCtrl edtCliente;
  private wxButton btnPCliente;
  private wxStaticText labISBN;
  private wxTextCtrl edtISBN;
  private wxStaticText labLivro;
  private wxTextCtrl edtLivro;
  private wxButton btnPLivro;
  private wxStaticText labRegistro;
  private wxListCtrl gridVendas;
  private wxStaticText labPrecoTotal;
  private wxTextCtrl edtPrecoTotal;
  private wxButton btnPesquisar;
  private wxButton btnLimpar;
  private wxButton btnFechar;
  ResultSet Consulta, ConsCampo;

  public frmConVendas(wxWindow parent) {
    super(parent, -1, new wxPoint(0, 0), new wxSize(480, 310), 0);

    labDtHrVenda = new wxStaticText(this, ID_FRMCONVENDAS_LABDTHRVENDA,
                                    "Data/Hora Venda: ", new wxPoint(8, 8),
                                    new wxSize(91, 13), 0);
    edtDtHrVenda = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTDTHRVENDA,
                                  "", new wxPoint(8, 24), new wxSize(128, 21),
                                  0);
    edtDtHrVenda.EVT_KILL_FOCUS(new OnEdtDtHrVenda_Killfocus());

    btnPesquisar = new wxButton(this, ID_FRMCONVENDAS_BTNPESQUISAR,
                                "&Pesquisar", new wxPoint(144, 22),
                                new wxSize(75, 25), 0);

    labCPF = new wxStaticText(this, ID_FRMCONVENDAS_LABCPF,
                              "CPF: ", new wxPoint(8, 48), new wxSize(48, 13),
                              0);
    edtCPF = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTCPF,
                            "", new wxPoint(8, 64), new wxSize(128, 21), 0);
    edtCPF.EVT_KILL_FOCUS(new OnEdtCPF_Killfocus());

    labCliente = new wxStaticText(this, ID_FRMCONVENDAS_LABCLIENTE,
                                  "Cliente: ", new wxPoint(142, 48),
                                  new wxSize(56, 13), 0);
    edtCliente = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTCLIENTE,
                                "", new wxPoint(142, 64), new wxSize(306, 21),
                                0);
    edtCliente.Disable();

    btnPCliente = new wxButton(this, ID_FRMCONVENDAS_BTNPCLIENTE,
                               "...", new wxPoint(448, 64), new wxSize(21, 21),
                               0);

    labISBN = new wxStaticText(this, ID_FRMCONVENDAS_LABISBN,
                               "ISBN: ", new wxPoint(8, 88), new wxSize(48, 13),
                               0);
    edtISBN = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTISBN,
                             "", new wxPoint(8, 104), new wxSize(128, 21), 0);
    edtISBN.EVT_KILL_FOCUS(new OnEdtISBN_Killfocus());

    labLivro = new wxStaticText(this, ID_FRMCONVENDAS_LABLIVRO,
                                "Livro: ", new wxPoint(142, 88),
                                new wxSize(40, 13), 0);
    edtLivro = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTLIVRO,
                              "", new wxPoint(142, 104), new wxSize(306, 21), 0);
    edtLivro.Disable();

    btnPLivro = new wxButton(this, ID_FRMCONVENDAS_BTNPLIVRO,
                             "...", new wxPoint(448, 104), new wxSize(21, 21),
                             0);

    gridVendas = new wxListCtrl(this, ID_FRMCONVENDAS_GRIDVENDAS,
                                new wxPoint(0, 136), new wxSize(355, 122),
                                wxLC_REPORT | wxSUNKEN_BORDER);

    this.labRegistro = new wxStaticText(this, ID_FRMCONVENDAS_LABREGISTRO,
                                        "Registro 0 de 0", new wxPoint(8, 16),
                                        new wxSize(144, 13), 0);

    labPrecoTotal = new wxStaticText(this, ID_FRMCONVENDAS_LABPRECOTOTAL,
                                     "Preço Total: ", new wxPoint(280, 248),
                                     new wxSize(61, 13), 0);
    edtPrecoTotal = new wxTextCtrl(this, ID_FRMCONVENDAS_EDTPRECOTOTAL,
                                   "", new wxPoint(344, 246),
                                   new wxSize(127, 21), 0);
    edtPrecoTotal.Disable();

    this.btnLimpar = new wxButton(this, ID_FRMCONVENDAS_BTNLIMPAR,
                                  "&Limpar", new wxPoint(16, 13),
                                  new wxSize(75, 25), 0);
    this.btnFechar = new wxButton(this, ID_FRMCONVENDAS_BTNFECHAR,
                                  "&Fechar", new wxPoint(75, 13),
                                  new wxSize(75, 25), 0);

    FazLayout();

    int[] nLargura = {
        120, 100, 220, 100, 280, 80};
    String[] sRotulos = {
        "Data/Hora Venda", "CPF", "Cliente",
        "ISBN", "Livro", "Preço"};
    RotinasGlobais.Rotinas.AdicionaColunasGrid(gridVendas, 0, 6, nLargura,
                                               sRotulos);
    edtCPF.SetValidator(new TextValidator(edtCPF,
                                             TextValidator.FILTER_NONE, 14));
    edtISBN.SetValidator(new TextValidator(edtISBN,
                                           TextValidator.FILTER_NONE, 13));
    edtPrecoTotal.SetValue("R$ 0,00");
    edtDtHrVenda.SetValue(RotinasGlobais.Rotinas.retDataHoraStr(true, true));

    EVT_BUTTON(ID_FRMCONVENDAS_BTNPESQUISAR, new OnBtnPesquisarClick());
    EVT_BUTTON(ID_FRMCONVENDAS_BTNLIMPAR, new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMCONVENDAS_BTNFECHAR, new OnBtnFecharClick());
    EVT_CLOSE(new OnClose());
    EVT_BUTTON(ID_FRMCONVENDAS_BTNPCLIENTE, new OnBtnPCliente());
    EVT_BUTTON(ID_FRMCONVENDAS_BTNPLIVRO, new OnBtnPLivro());
    EVT_LIST_ITEM_SELECTED(ID_FRMCONVENDAS_GRIDVENDAS,
                           new OnListItemSelected());
    EVT_LIST_COL_RIGHT_CLICK(ID_FRMCONVENDAS_GRIDVENDAS,
                             new OnListColRightClick());

  }

  private void FazLayout() {
    wxBoxSizer sizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_6 = new wxBoxSizer(wxVERTICAL);
    wxGridSizer sizer_22 = new wxGridSizer(1, 2, 0, 0);
    wxBoxSizer sizer_23 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_7 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer sizer_24 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer sizer_4 = new wxBoxSizer(wxHORIZONTAL);
    wxGridSizer grid_sizer_8 = new wxGridSizer(2, 1, 0, 0);
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
    sizer_2.Add(btnPesquisar, 0, wxLEFT | wxTOP | wxALIGN_BOTTOM, 10);
    sizer_1.Add(sizer_2, 0, 0, 0);
    grid_sizer_2.Add(labCPF, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_2.Add(edtCPF, 0, 0, 0);
    sizer_3.Add(grid_sizer_2, 0, wxLEFT, 2);
    grid_sizer_3.Add(labCliente, 0, wxALIGN_BOTTOM, 0);
    grid_sizer_3.Add(edtCliente, 0, 0, 0);
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
    grid_sizer_8.Add(20, 20, 0, 0, 0);
    grid_sizer_8.Add(btnPLivro, 0, 0, 0);
    sizer_4.Add(grid_sizer_8, 0, 0, 0);
    sizer_1.Add(sizer_4, 0, 0, 0);
    sizer_1.Add(gridVendas, 1, wxALL | wxEXPAND, 2);
    sizer_24.Add(labRegistro, 0, wxALL, 4);
    sizer_24.Add(20, 20, 0, 0, 0);
    sizer_22.Add(sizer_24, 0, 0, 0);
    sizer_7.Add(labPrecoTotal, 0, wxALL, 2);
    sizer_7.Add(edtPrecoTotal, 0, wxALL, 2);
    sizer_23.Add(sizer_7, 0, wxALL | wxALIGN_RIGHT, 2);
    sizer_8.Add(btnLimpar, 0, wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_8.Add(btnFechar, 0, wxALL | wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    sizer_23.Add(sizer_8, 0, wxALL | wxALIGN_RIGHT, 2);
    sizer_22.Add(sizer_23, 1, wxALIGN_RIGHT | wxALIGN_BOTTOM, 0);
    sizer_6.Add(sizer_22, 0, wxEXPAND, 0);
    sizer_1.Add(sizer_6, 0, wxEXPAND, 0);
    SetAutoLayout(true);
    SetSizer(sizer_1);
    sizer_1.Fit(this);
    sizer_1.SetSizeHints(this);
  }

  class OnBtnLimparClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      edtCPF.Clear();
      edtCliente.Clear();
      edtISBN.Clear();
      edtLivro.Clear();
      gridVendas.DeleteAllItems();
      edtPrecoTotal.SetValue("R$ 0,00");
      edtDtHrVenda.SetValue(RotinasGlobais.Rotinas.retDataHoraStr(true, true));
      labRegistro.SetLabel("Registro 0 de 0");
      edtDtHrVenda.SetFocus();
      event.Skip();
    }
  }

  private String ConsVenda(char sOpcao) {
    String sISBN, sCPF, sDataHora, sret;

    if (edtDtHrVenda.GetValue().length() > 0) {
      sDataHora = RotinasGlobais.Rotinas.ConverteDataHoraStr(
          edtDtHrVenda.GetValue(), "MM/dd/yyyy HH:mm:ss",
          "yyyy-MM-dd HH:mm:ss.S");
    }
    else {
      sDataHora = "";

    }
    sISBN = edtISBN.GetValue();
    sCPF = edtCPF.GetValue();

    if (sOpcao == 'L') {
      sret = ConsultasSQL.ConsSQL.Venda('S', "ZERO", "", "", "", "");
    }
    else {
      sret = ConsultasSQL.ConsSQL.Venda(sOpcao, sISBN, sCPF,
                                        sDataHora, "", "");

    }
    return sret;
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

  class OnBtnPesquisarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      ArrayList ConsTotal = new ArrayList();
      ArrayList lstTotal;
      float nTemp;
      String sPrecoTotal;

      Consulta = RotinasGlobais.Rotinas.ConsultaDadosLista(ConsVenda('S'));
      if (Consulta != null) {
        RotinasGlobais.Rotinas.AdicionaLinhasGrid(gridVendas, Consulta, 6);
        setLabRegistros(0);
        if (RotinasGlobais.Rotinas.ConsultaDadosLista(ConsTotal,
            ConsVenda('P'),1)) {
          if (ConsTotal.size() > 0) {
            lstTotal = (ArrayList) ConsTotal.get(0);
            nTemp = Float.parseFloat(lstTotal.get(0).toString());
            nTemp = Math.round(nTemp);
            sPrecoTotal = Float.toString(nTemp);
            edtPrecoTotal.SetValue("R$ " + sPrecoTotal);
          }
        }
      }
      else {
        wx.wxMessageBox(Resource.STR_VENNENC, "Erro",
                        wx.wxOK | wx.wxICON_ERROR);
      }
      event.Skip();
    }
  }

  class OnEdtCPF_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      try {
        if (edtCPF.GetValue().length() > 0) {
          if (RotinasGlobais.Rotinas.ValidaCPF(edtCPF.GetValue())) {
            ConsCampo = RotinasGlobais.Rotinas.ConsultaCampoDesc(
                ConsultasSQL.ConsSQL.Cliente('S', edtCPF.GetValue(),
                                             "", "", "", "", "", "", "", "", ""),
                Resource.STR_CLINENC);
            if (ConsCampo == null) {
              edtCPF.Clear();
              edtCPF.SetFocus();
            }
            else {
              edtCliente.SetValue(ConsCampo.getObject(2).toString());
            }
          }
          else {
            wx.wxMessageBox(Resource.STR_CPFINV, "Erro",
                            wx.wxOK | wx.wxICON_ERROR);
            edtCPF.Clear();
            edtCPF.SetFocus();
          }
        }
        else {
          edtCliente.Clear();
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
      edtCPF.SetValue(RotinasGlobais.Rotinas.sCodigoSelecionado);
      OnEdtCPF_Killfocus kf = new OnEdtCPF_Killfocus();
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
            ConsCampo = RotinasGlobais.Rotinas.ConsultaCampoDesc(
                ConsultasSQL.ConsSQL.Livro('Q', edtISBN.GetValue(),
                                           "", "", "", "", "", "", "", "", ""),
                Resource.STR_LIVNENC);
            if (ConsCampo == null) {
              edtISBN.Clear();
              edtISBN.SetFocus();
            }
            else {
              edtLivro.SetValue(ConsCampo.getObject(2).toString());
              sQtdEstoque = ConsCampo.getObject(4).toString();
              nQtdEstoque = Integer.parseInt(sQtdEstoque);
              if (nQtdEstoque > 0) {
                RotinasGlobais.Rotinas.sPreco = ConsCampo.getObject(3).toString();
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

  private void setLabRegistros(int nLinha) {
    if (nLinha >= 0) {
      labRegistro.SetLabel("Registro " + Integer.toString(nLinha + 1) +
                           " de " + Integer.toString(gridVendas.GetItemCount()));
    }

  }

  class OnListItemSelected
      implements wxListListener {
    public void handleEvent(wxListEvent event) {
      setLabRegistros(event.GetIndex());
      event.Skip();
    }
  }

  class OnListColRightClick
      implements wxListListener {
    public void handleEvent(wxListEvent event) {
      setLabRegistros(event.GetIndex());
      event.Skip();
    }
  }

  class OnEdtDtHrVenda_Killfocus
      implements wxFocusListener {
    public void handleEvent(wxFocusEvent event) {
      if (edtDtHrVenda.GetValue().length() > 0) {
        if (!RotinasGlobais.Rotinas.validaDataHora(edtDtHrVenda.GetValue(), false)) {
          wx.wxMessageBox(Resource.STR_DTHRINV, "Erro",
                          wx.wxOK | wx.wxICON_ERROR);
          edtDtHrVenda.SetFocus();
        }
      }
    }
  }
}
