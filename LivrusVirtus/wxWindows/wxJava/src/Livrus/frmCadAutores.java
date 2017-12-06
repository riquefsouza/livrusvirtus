package Livrus;

import org.wxwindows.*;

public class frmCadAutores
    extends frmCadastros {
  public frmCadAutores(wxWindow parent) {
    super(parent, TextValidator.FILTER_NUMERIC, true);

    labDescricao.SetLabel("Autor: ");

    EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, new OnBtnNovoClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, new OnBtnPesquisarClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, new OnBtnAnteriorClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, new OnBtnProximoClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, new OnBtnSalvarClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, new OnBtnExcluirClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, new OnBtnLimparClick() );
    EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, new OnBtnFecharClick() );
    EVT_CLOSE(new OnClose() );
  }

  private boolean ValidaDados(boolean bTodosDados) {
    if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.GetValue(),
                                           Resource.STR_CODNINF)) {
      return false;
    }
    if (bTodosDados) {
      if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.GetValue(),
                                             Resource.STR_AUTNINF)) {
        return false;
      }
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

  class OnBtnNovoClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      btnNovoClick();
      NovoDado(ConsultasSQL.ConsSQL.Autor('N', edtCodigo.GetValue(), ""));
      event.Skip();
    }
  }

  class OnBtnPesquisarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      PesquisarDados(ConsultasSQL.ConsSQL.Autor('S',
                                                  edtCodigo.GetValue(), ""),
                     Resource.STR_AUTNENC, 2);
      event.Skip();
    }
  }

  class OnBtnAnteriorClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      registroAnterior();
      event.Skip();
    }
  }

  class OnBtnProximoClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      registroProximo();
      event.Skip();
    }
  }

  class OnBtnSalvarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      SalvarDados(ValidaDados(true),
                  ConsultasSQL.ConsSQL.Autor('S', edtCodigo.GetValue(), ""),
                  ConsultasSQL.ConsSQL.Autor('U', edtCodigo.GetValue(),
                                               edtDescricao.GetValue()),
                  ConsultasSQL.ConsSQL.Autor('I', edtCodigo.GetValue(),
                                               edtDescricao.GetValue()), true);
      event.Skip();
    }
  }

  class OnBtnExcluirClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      ExcluirDados(ValidaDados(false),
                   ConsultasSQL.ConsSQL.Autor('D', edtCodigo.GetValue(), ""));
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

  class OnBtnLimparClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      btnLimparClick();
      event.Skip();
    }
  }
}
