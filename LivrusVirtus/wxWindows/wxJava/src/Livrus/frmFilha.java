package Livrus;

import org.wxwindows.*;

public class frmFilha
    extends wxFrame {
  private int nLocalTelaAtiva;
  private wxIcon icone;

  public frmFilha(wxWindow parent, int nTelaAtiva) {
    super(parent, -1, "Cadastro de ", new wxPoint(0, 0),
          new wxSize(342, 165), wxDEFAULT_FRAME_STYLE);

    icone = new wxIcon();
    icone.CopyFromBitmap(new wxBitmap(Resource.XPM_LIVRUS, wxBITMAP_TYPE_XPM));
    SetIcon(icone);
    EVT_CLOSE(new OnClose());
    nLocalTelaAtiva = nTelaAtiva;
    Center(wxBOTH);

    if (nTelaAtiva == Resource.FRMCADASSUNTOS) {
      new frmCadAssuntos(this);
      SetTitle(Resource.STR_CADASSUNTO);
    }
    else if (nTelaAtiva == Resource.FRMCADAUTORES) {
      new frmCadAutores(this);
      SetTitle(Resource.STR_CADAUTOR);
    }
    else if (nTelaAtiva == Resource.FRMCADEDITORAS) {
      new frmCadEditoras(this);
      SetTitle(Resource.STR_CADEDITORA);
    }
    else if (nTelaAtiva == Resource.FRMCADENDERECOS) {
      new frmCadEnderecos(this);
      SetTitle(Resource.STR_CADENDERECO);
      SetSize(new wxSize(525, 195));
    }
    else if (nTelaAtiva == Resource.FRMCADIDIOMAS) {
      new frmCadIdiomas(this);
      SetTitle(Resource.STR_CADIDIOMA);
    }
    else if (nTelaAtiva == Resource.FRMCADPAISES) {
      new frmCadPaises(this);
      SetTitle(Resource.STR_CADPAIS);
    }
    else if (nTelaAtiva == Resource.FRMCADPROFISSOES) {
      new frmCadProfissoes(this);
      SetTitle(Resource.STR_CADPROFISS);
    }
    else if (nTelaAtiva == Resource.FRMCADCLIENTES) {
      new frmCadClientes(this);
      SetTitle(Resource.STR_CADCLIENTE);
      SetSize(new wxSize(525, 465));
    }
    else if (nTelaAtiva == Resource.FRMCADLIVROS) {
      new frmCadLivros(this);
      SetTitle(Resource.STR_CADLIVRO);
      SetSize(new wxSize(510, 445));
    }
    else if (nTelaAtiva == Resource.FRMVENDERLIVROS) {
      new frmVenderLivros(this);
      SetTitle(Resource.STR_VENLIVRO);
      SetSize(new wxSize(480, 310));
    }
    else if (nTelaAtiva == Resource.FRMCONVENDAS) {
      new frmConVendas(this);
      SetTitle(Resource.STR_CONVENLIVRO);
      SetSize(new wxSize(480, 330));
    }
    else if (nTelaAtiva == Resource.FRMALTERARSENHA) {
      new frmAlterarSenha(this);
      SetTitle(Resource.STR_ALTSENHA);
      SetSize(new wxSize(255, 161));
    }
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      if (nLocalTelaAtiva == Resource.FRMCADASSUNTOS) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_ASSUNTOS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADAUTORES) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_AUTORES, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADEDITORAS) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_EDITORAS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADENDERECOS) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_ENDERECOS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADIDIOMAS) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_IDIOMAS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADPAISES) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_PAISES, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADPROFISSOES) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_PROFISSOES, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADCLIENTES) {
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_CAD_CLIENTES, true);
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_CLIENTES, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCADLIVROS) {
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_CAD_LIVROS, true);
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.
            MNU_CAD_LIVROS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMVENDERLIVROS) {
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.
            MNU_VEN_VENDERLIVROS, true);
        frmPrincipal.fPrincipal.barraMenu.GetMenu(2).Enable(Resource.
            MNU_VEN_VENDERLIVROS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMCONVENDAS) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(2).Enable(Resource.
            MNU_VEN_VENDASREALIZADAS, true);
      }
      else if (nLocalTelaAtiva == Resource.FRMALTERARSENHA) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(3).Enable(Resource.
            MNU_OP_ALTERARSENHA, true);
      }
      event.Skip();
    }
  }
}
