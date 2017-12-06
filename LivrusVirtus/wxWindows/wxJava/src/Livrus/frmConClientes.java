package Livrus;

import org.wxwindows.*;

public class frmConClientes
    extends frmConsultas {
  public static frmConClientes fConClientes = null;

  public frmConClientes(wxWindow parent) {
    super(parent, Resource.STR_CONCLIENTE);

    labDescricao.SetLabel("Cliente: ");
    gridConsulta.DeleteColumn(0);
    gridConsulta.InsertColumn(0,"CPF");
    gridConsulta.SetColumnWidth(0, 100);
    gridConsulta.DeleteColumn(1);
    gridConsulta.InsertColumn(1,"Nome");
    gridConsulta.SetColumnWidth(1, 220);

    int[] nLargura = { 180,80,40,80,140,100,220,150,
      80,100,100,80,180,100,100 };
    String[] sRotulos = { "Email", "Identidade", "Sexo",
     "Telefone", "DtNascimento", "CodEndereço", "Logradouro",
     "Bairro", "CEP", "Cidade", "Estado", "CodPaís", "País",
     "CodProfissão", "Profissão" };
    RotinasGlobais.Rotinas.AdicionaColunasGrid(gridConsulta, 2, 15,
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
      Fecha(Resource.MNU_CON_CLIENTES);
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
      PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S', "",
                                                  edtDescricao.GetValue(),"","","","","","","",""),
                     Resource.STR_CLINENC, 17);
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
