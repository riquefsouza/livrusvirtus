package Livrus;

import org.wxwindows.*;

public class frmConEnderecos
    extends frmConsultas {
  public static frmConEnderecos fConEnderecos = null;

  public frmConEnderecos(wxWindow parent) {
    super(parent, Resource.STR_CONENDERECO);

    labDescricao.SetLabel("Endereco: ");
    gridConsulta.DeleteColumn(1);
    gridConsulta.InsertColumn(1,"Logradouro");
    gridConsulta.SetColumnWidth(1, 220);

    int[] nLargura = { 150,80,100,80 };
    String[] sRotulos = { "Bairro", "CEP", "Cidade", "Estado" };
    RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 4, 
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
      Fecha(Resource.MNU_CON_ENDERECOS);
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
      PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S', "",
                                                  edtDescricao.GetValue(),"","","",""),
                     Resource.STR_ENDNENC, 6);
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