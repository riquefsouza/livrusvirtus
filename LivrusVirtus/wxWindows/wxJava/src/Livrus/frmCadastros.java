package Livrus;

import org.wxwindows.*;
import java.sql.*;
import java.util.*;

public class frmCadastros
    extends wxPanel {
  protected static int ID_FRMCADASTROS_BTNANTERIOR = 400;
  protected static int ID_FRMCADASTROS_BTNEXCLUIR = 401;
  protected static int ID_FRMCADASTROS_BTNFECHAR = 402;
  protected static int ID_FRMCADASTROS_BTNLIMPAR = 403;
  protected static int ID_FRMCADASTROS_BTNNOVO = 404;
  protected static int ID_FRMCADASTROS_BTNPESQUISAR = 405;
  protected static int ID_FRMCADASTROS_BTNPROXIMO = 406;
  protected static int ID_FRMCADASTROS_BTNSALVAR = 407;
  protected static int ID_FRMCADASTROS_EDTCODIGO = 408;
  protected static int ID_FRMCADASTROS_EDTDESCRICAO = 408;
  protected static int ID_FRMCADASTROS_LABCODIGO = 410;
  protected static int ID_FRMCADASTROS_LABDESCRICAO = 411;

  ArrayList Registros;
  ArrayList Campos;
  int nLinhaRegistro;
  ResultSet Consulta;
  Statement Arquiva;

  protected wxStaticText labCodigo;
  protected wxTextCtrl edtCodigo;
  protected wxStaticText labDescricao;
  protected wxTextCtrl edtDescricao;
  protected wxButton btnNovo;
  protected wxButton btnPesquisar;
  protected wxButton btnAnterior;
  protected wxButton btnProximo;
  protected wxButton btnFechar;
  protected wxButton btnLimpar;
  protected wxButton btnExcluir;
  protected wxButton btnSalvar;

  public frmCadastros(wxWindow parent, int nFiltroCodigo,
                      boolean bIniciaBotoes) {
    super(parent, -1, new wxPoint(0, 0), new wxSize(330, 140), 0);

    labCodigo = new wxStaticText(this, ID_FRMCADASTROS_LABCODIGO,
                                 "Código:", new wxPoint(8, 8),
                                 new wxSize(36, 13), 0);
    edtCodigo = new wxTextCtrl(this, ID_FRMCADASTROS_EDTCODIGO,
                               "", new wxPoint(8, 24), new wxSize(121, 21), 0);
    btnNovo = new wxButton(this, ID_FRMCADASTROS_BTNNOVO,
                           "&Novo", new wxPoint(144, 24), new wxSize(75, 25), 0);
    labDescricao = new wxStaticText(this, ID_FRMCADASTROS_LABDESCRICAO,
                                    "Descrição:", new wxPoint(8, 48),
                                    new wxSize(51, 13), 0);
    edtDescricao = new wxTextCtrl(this, ID_FRMCADASTROS_EDTDESCRICAO,
                                  "", new wxPoint(8, 64), new wxSize(217, 21),
                                  0);

    if (bIniciaBotoes) {
      IniciaBotoes();
      FazLayout();
    }
    edtCodigo.SetValidator(new TextValidator(edtCodigo, nFiltroCodigo, 10));
    edtDescricao.SetValidator(new TextValidator(edtDescricao,
                                                TextValidator.FILTER_NONE, 30));
    Registros = new ArrayList();
    nLinhaRegistro = 0;
  }

  // Necessário por causa da tabulação dos campos
  protected void IniciaBotoes() {
    btnPesquisar = new wxButton(this, ID_FRMCADASTROS_BTNPESQUISAR,
                                "&Pesquisar", new wxPoint(248, 8),
                                new wxSize(75, 25), 0);
    btnAnterior = new wxButton(this, ID_FRMCADASTROS_BTNANTERIOR,
                               "&Anterior", new wxPoint(248, 40),
                               new wxSize(75, 25), 0);
    btnProximo = new wxButton(this, ID_FRMCADASTROS_BTNPROXIMO,
                              "Próxi&mo", new wxPoint(248, 72),
                              new wxSize(75, 25), 0);
    btnSalvar = new wxButton(this, ID_FRMCADASTROS_BTNSALVAR,
                             "&Salvar", new wxPoint(8, 104), new wxSize(75, 25),
                             0);
    btnExcluir = new wxButton(this, ID_FRMCADASTROS_BTNEXCLUIR,
                              "&Excluir", new wxPoint(88, 104),
                              new wxSize(75, 25), 0);
    btnLimpar = new wxButton(this, ID_FRMCADASTROS_BTNLIMPAR,
                             "&Limpar", new wxPoint(168, 104),
                             new wxSize(75, 25), 0);
    btnFechar = new wxButton(this, ID_FRMCADASTROS_BTNFECHAR,
                             "&Fechar", new wxPoint(248, 104),
                             new wxSize(75, 25), 0);

    btnLimparClick();
  }

  private void FazLayout() {
    wxBoxSizer wxSizer_1 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer wxSizer_2 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer wxSizer_3 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer wxSizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer wxSizer_5 = new wxBoxSizer(wxVERTICAL);
    wxGridSizer grid_wxSizer_2 = new wxGridSizer(2, 1, 0, 0);
    wxGridSizer grid_wxSizer_1 = new wxGridSizer(2, 2, 0, 1);
    grid_wxSizer_1.Add(labCodigo, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_1.Add(20, 10, 0, 0, 0);
    grid_wxSizer_1.Add(edtCodigo, 0, 0, 0);
    grid_wxSizer_1.Add(btnNovo, 0, wxLEFT, 6);
    wxSizer_5.Add(grid_wxSizer_1, 0, 0, 0);
    grid_wxSizer_2.Add(labDescricao, 0, wxALIGN_BOTTOM, 0);
    grid_wxSizer_2.Add(edtDescricao, 0, 0, 2);
    wxSizer_5.Add(grid_wxSizer_2, 0, 0, 0);
    wxSizer_3.Add(wxSizer_5, 1, 0, 0);
    wxSizer_4.Add(btnPesquisar, 0, wxALL |
                  wxALIGN_RIGHT, 2);
    wxSizer_4.Add(btnAnterior, 0, wxALL |
                  wxALIGN_RIGHT, 2);
    wxSizer_4.Add(btnProximo, 0, wxALL |
                  wxALIGN_RIGHT, 2);
    wxSizer_3.Add(wxSizer_4, 0, wxALIGN_RIGHT, 0);
    wxSizer_1.Add(wxSizer_3, 1, wxALL | wxEXPAND, 4);
    wxSizer_2.Add(btnSalvar, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_2.Add(btnExcluir, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_2.Add(btnLimpar, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_2.Add(btnFechar, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 2);
    wxSizer_1.Add(wxSizer_2, 0, wxALL |
                  wxALIGN_RIGHT | wxALIGN_BOTTOM, 4);
    SetAutoLayout(true);
    SetSizer(wxSizer_1);
    wxSizer_1.Fit(this);
    wxSizer_1.SetSizeHints(this);
  }

  protected void InformaLimpaDados(boolean bInformar) {
    if (bInformar) {
      Campos = (ArrayList) Registros.get(nLinhaRegistro);
      edtCodigo.SetValue(Campos.get(0).toString());
      edtDescricao.SetValue(Campos.get(1).toString());
    }
    else {
      edtCodigo.Clear();
      edtDescricao.Clear();
      edtCodigo.Enable();
      edtCodigo.SetFocus();
    }
  }

  protected void HabilitaDados(boolean bHabilita) {
    if (bHabilita) {
      edtDescricao.Enable();
    }
    else {
      edtDescricao.Disable();
    }
  }

  protected void btnNovoClick() {
    btnSalvar.Enable();
    btnExcluir.Disable();
    btnPesquisar.Disable();
    btnAnterior.Disable();
    btnProximo.Disable();
    btnNovo.Disable();

    nLinhaRegistro = 0;
    InformaLimpaDados(false);
    HabilitaDados(true);
  }

  protected void NovoDado(String sTextoSql) {
    if (RotinasGlobais.Rotinas.ConsultaDadosLista(Registros, sTextoSql, 1)) {
      Campos = (ArrayList) Registros.get(0);
      edtCodigo.SetValue(Campos.get(0).toString());
      edtCodigo.Disable();
      edtDescricao.SetFocus();
    }
  }

  protected void btnLimparClick() {
    btnSalvar.Disable();
    btnExcluir.Disable();
    btnPesquisar.Enable();
    btnAnterior.Disable();
    btnProximo.Disable();
    btnNovo.Enable();

    nLinhaRegistro = 0;
    InformaLimpaDados(false);
    HabilitaDados(false);
  }

  protected boolean ExcluirDados(boolean bValidaDados, String sTextoSql) {
    if (bValidaDados) {
      if (wx.wxMessageBox(Resource.STR_CERTEXCL, "Confirme",
                          wx.wxICON_QUESTION | wx.wxYES_NO) == wx.wxYES) {
        if (RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sTextoSql)) {
          btnLimparClick();
          return true;
        }
      }
    }
    return false;
  }

  protected boolean PesquisarDados(String sTextoSql, String sMensagemErro,
                                   int QtdCampos) {
    if (edtCodigo.GetValue().length() == 0) {
      btnAnterior.Enable();
      btnProximo.Enable();
    }

    if (RotinasGlobais.Rotinas.ConsultaDadosLista(Registros, sTextoSql,
                                                  QtdCampos)) {
      InformaLimpaDados(true);
      HabilitaDados(true);

      btnSalvar.Enable();
      btnExcluir.Enable();
      btnPesquisar.Disable();
      return true;
    }
    else {
      wx.wxMessageBox(sMensagemErro, "Erro",
                      wx.wxOK | wx.wxICON_ERROR);

    }
    return false;
  }

  protected boolean registroAnterior() {
    if (nLinhaRegistro > 0) {
      nLinhaRegistro = nLinhaRegistro - 1;
      InformaLimpaDados(true);
      return true;
    }
    else {
      return false;
    }
  }

  protected boolean registroProximo() {
    if (nLinhaRegistro < (Registros.size() - 1)) {
      nLinhaRegistro = nLinhaRegistro + 1;
      InformaLimpaDados(true);
      return true;
    }
    else {
      return false;
    }
  }

  protected boolean SalvarDados(boolean bValidaDados, String sTextoSql,
                                String sTextoUpdate, String sTextoInsert,
                                boolean bLimparDados) {
    String sArquiva;

    if (bValidaDados) {
      if (RotinasGlobais.Rotinas.ConsultaDados(Arquiva, sTextoSql)) {
        sArquiva = sTextoUpdate;
      }
      else {
        sArquiva = sTextoInsert;

      }
      if (RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sArquiva)) {
        if (bLimparDados) {
          btnLimparClick();
        }
        return true;
      }
    }
    return false;
  }
}
