package Livrus;

import org.wxwindows.*;

public class frmConLivros
    extends frmConsultas {
  public static frmConLivros fConLivros = null;

  public frmConLivros(wxWindow parent) {
    super(parent, Resource.STR_CONLIVRO);

    labDescricao.SetLabel("Livro: ");
    gridConsulta.DeleteColumn(0);
    gridConsulta.InsertColumn(0, "ISBN");
    gridConsulta.SetColumnWidth(0, 100);
    gridConsulta.DeleteColumn(1);
    gridConsulta.InsertColumn(1, "Título");
    gridConsulta.SetColumnWidth(1, 260);

    int[] nLargura = {
        80, 100, 80, 80, 100, 80, 100, 80, 80, 80};
    String[] sRotulos = {
        "Edição", "AnoPublicação",
        "Volume", "CodEditora", "Editora", "CodIdioma", "Idioma",
        "NumPáginas", "Preço", "Estoque"};
    RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 10,
                                               nLargura, sRotulos);

    EVT_BUTTON(ID_FRMCONSULTAS_BTNPESQUISAR,
               new OnBtnPesquisarClick());
    EVT_BUTTON(ID_FRMCONSULTAS_BTNLIMPAR,
               new OnBtnLimparClick());
    EVT_BUTTON(ID_FRMCONSULTAS_BTNFECHAR,
               new OnBtnFecharClick());
    EVT_CLOSE(new OnClose());
    EVT_LIST_ITEM_SELECTED(ID_FRMCONSULTAS_GRIDCONSULTA,
                           new OnListItemSelected());
    EVT_LIST_COL_RIGHT_CLICK(ID_FRMCONSULTAS_GRIDCONSULTA,
                             new OnListColRightClick());
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      Fecha(Resource.MNU_CON_LIVROS);
      event.Skip();
    }
  }

  class OnBtnFecharClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      Fecha(0);
      event.Skip();
    }
  }

  class OnBtnLimparClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      LimparDados();
      event.Skip();
    }
  }

  class OnBtnPesquisarClick
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      PesquisarDados(ConsultasSQL.ConsSQL.Livro('S', "", edtDescricao.GetValue(),
                                                "", "", "", "", "", "", "", ""),
                     Resource.STR_LIVNENC, 12);
      event.Skip();
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

}
