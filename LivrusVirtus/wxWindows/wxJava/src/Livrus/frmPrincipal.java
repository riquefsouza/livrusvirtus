package Livrus;

import org.wxwindows.*;

public class frmPrincipal
    extends wxFrame {
  public static frmPrincipal fPrincipal = null;

  private wxMenu mnuCadastros;
  private wxMenu mnuPesquisas;
  private wxMenu mnuVendas;
  private wxMenu mnuOpcoes;
  public wxMenuBar barraMenu;
  private wxStatusBar barraStatus;
  private int[] nLarguras;
  public wxToolBar barraFerra;
  private wxIcon icone;

  public frmPrincipal() {
    super(null, -1, Resource.STR_TITULO, new wxPoint( -1, -1),
          new wxSize(640, 480));

    icone = new wxIcon();
    icone.CopyFromBitmap(new wxBitmap(Resource.XPM_LIVRUS, wxBITMAP_TYPE_XPM));
    SetIcon(icone);

    //Barra de Menu
    mnuCadastros = new wxMenu();
    mnuCadastros.Append(Resource.MNU_CAD_ASSUNTOS, "&Assuntos",
                        Resource.STR_CADASSUNTO);
    mnuCadastros.Append(Resource.MNU_CAD_AUTORES, "A&utores",
                        Resource.STR_CADAUTOR);
    mnuCadastros.Append(Resource.MNU_CAD_EDITORAS, "&Editoras",
                        Resource.STR_CADEDITORA);
    mnuCadastros.Append(Resource.MNU_CAD_ENDERECOS, "E&ndereços",
                        Resource.STR_CADENDERECO);
    mnuCadastros.Append(Resource.MNU_CAD_IDIOMAS, "&Idiomas",
                        Resource.STR_CADIDIOMA);
    mnuCadastros.Append(Resource.MNU_CAD_PAISES, "&Países",
                        Resource.STR_CADPAIS);
    mnuCadastros.Append(Resource.MNU_CAD_PROFISSOES, "P&rofissões",
                        Resource.STR_CADPROFISS);
    mnuCadastros.AppendSeparator();
    mnuCadastros.Append(Resource.MNU_CAD_CLIENTES, "&Clientes",
                        Resource.STR_CADCLIENTE);
    mnuCadastros.Append(Resource.MNU_CAD_LIVROS, "&Livros",
                        Resource.STR_CADLIVRO);

    mnuPesquisas = new wxMenu();
    mnuPesquisas.Append(Resource.MNU_CON_ASSUNTOS, "&Assuntos",
                        Resource.STR_CONASSUNTO);
    mnuPesquisas.Append(Resource.MNU_CON_AUTORES, "A&utores",
                        Resource.STR_CONAUTOR);
    mnuPesquisas.Append(Resource.MNU_CON_EDITORAS, "&Editoras",
                        Resource.STR_CONEDITORA);
    mnuPesquisas.Append(Resource.MNU_CON_ENDERECOS, "E&ndereços",
                        Resource.STR_CONENDERECO);
    mnuPesquisas.Append(Resource.MNU_CON_IDIOMAS, "&Idiomas",
                        Resource.STR_CONIDIOMA);
    mnuPesquisas.Append(Resource.MNU_CON_PAISES, "&Países",
                        Resource.STR_CONPAIS);
    mnuPesquisas.Append(Resource.MNU_CON_PROFISSOES, "P&rofissões",
                        Resource.STR_CONPROFISS);
    mnuPesquisas.AppendSeparator();
    mnuPesquisas.Append(Resource.MNU_CON_CLIENTES, "&Clientes",
                        Resource.STR_CONCLIENTE);
    mnuPesquisas.Append(Resource.MNU_CON_LIVROS, "&Livros",
                        Resource.STR_CONLIVRO);

    mnuVendas = new wxMenu();
    mnuVendas.Append(Resource.MNU_VEN_VENDERLIVROS, "&Vender Livros",
                     Resource.STR_VENLIVRO);
    mnuVendas.Append(Resource.MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas",
                     Resource.STR_CONVENLIVRO);

    mnuOpcoes = new wxMenu();
    mnuOpcoes.Append(Resource.MNU_OP_ALTERARSENHA, "&Alterar Senha",
                     Resource.STR_ALTSENHA);
    mnuOpcoes.AppendSeparator();
    mnuOpcoes.Append(Resource.MNU_OP_SOBRE, "&Sobre", Resource.STR_OPSOBRE);
    mnuOpcoes.Append(Resource.MNU_OP_SAIR, "Sa&ir\tCtrl-S", Resource.STR_OPSAIR);

    barraMenu = new wxMenuBar();
    barraMenu.Append(mnuCadastros, "&Cadastros");
    barraMenu.Append(mnuPesquisas, "&Pesquisas");
    barraMenu.Append(mnuVendas, "&Vendas");
    barraMenu.Append(mnuOpcoes, "&Opções");

    SetMenuBar(barraMenu);

    //Barra de ferramentas
    barraFerra = CreateToolBar(wxTB_HORIZONTAL | wxNO_BORDER);
    barraFerra.AddTool(Resource.MNU_CAD_CLIENTES, "",
                       new wxBitmap(Resource.XPM_CLIENTE,
                                    wxBITMAP_TYPE_XPM),
                       "");
    barraFerra.AddTool(Resource.MNU_CAD_LIVROS, "",
                       new wxBitmap(Resource.XPM_LIVRO,
                                    wxBITMAP_TYPE_XPM),
                       "");
    barraFerra.AddTool(Resource.MNU_VEN_VENDERLIVROS, "",
                       new wxBitmap(Resource.XPM_LIVROS,
                                    wxBITMAP_TYPE_XPM),
                       "");
    barraFerra.AddSeparator();
    barraFerra.AddTool(Resource.MNU_OP_SOBRE, "",
                       new wxBitmap(Resource.XPM_SOBRE,
                                    wxBITMAP_TYPE_XPM),
                       "");
    barraFerra.AddTool(Resource.MNU_OP_SAIR, "",
                       new wxBitmap(Resource.XPM_SAIR,
                                    wxBITMAP_TYPE_XPM),
                       "");
    barraFerra.Realize();

    barraStatus = new wxStatusBar(this, 0);
    barraStatus.SetFieldsCount(2);
    nLarguras = new int[2];
    nLarguras[0] = -1;
    nLarguras[1] = 100;
    barraStatus.SetStatusWidths(nLarguras);
    barraStatus.SetStatusText(Resource.STR_USUARIO, 1);
    SetStatusBar(barraStatus);

    FazLayout();

    EVT_MENU(Resource.MNU_CAD_ASSUNTOS, new OnMnuCadAssuntos());
    EVT_MENU(Resource.MNU_CAD_AUTORES, new OnMnuCadAutores());
    EVT_MENU(Resource.MNU_CAD_EDITORAS, new OnMnuCadEditoras());
    EVT_MENU(Resource.MNU_CAD_ENDERECOS, new OnMnuCadEnderecos());
    EVT_MENU(Resource.MNU_CAD_IDIOMAS, new OnMnuCadIdiomas());
    EVT_MENU(Resource.MNU_CAD_PAISES, new OnMnuCadPaises());
    EVT_MENU(Resource.MNU_CAD_PROFISSOES, new OnMnuCadProfissoes());
    EVT_MENU(Resource.MNU_CAD_CLIENTES, new OnMnuCadClientes());
    EVT_MENU(Resource.MNU_CAD_LIVROS, new OnMnuCadLivros());

    EVT_MENU(Resource.MNU_CON_ASSUNTOS, new OnMnuConAssuntos());
    EVT_MENU(Resource.MNU_CON_AUTORES, new OnMnuConAutores());
    EVT_MENU(Resource.MNU_CON_EDITORAS, new OnMnuConEditoras());
    EVT_MENU(Resource.MNU_CON_ENDERECOS, new OnMnuConEnderecos());
    EVT_MENU(Resource.MNU_CON_IDIOMAS, new OnMnuConIdiomas());
    EVT_MENU(Resource.MNU_CON_PAISES, new OnMnuConPaises());
    EVT_MENU(Resource.MNU_CON_PROFISSOES, new OnMnuConProfissoes());
    EVT_MENU(Resource.MNU_CON_CLIENTES, new OnMnuConClientes());
    EVT_MENU(Resource.MNU_CON_LIVROS, new OnMnuConLivros());

    EVT_MENU(Resource.MNU_VEN_VENDERLIVROS, new OnMnuVenderLivros());
    EVT_MENU(Resource.MNU_VEN_VENDASREALIZADAS,
             new OnMnuVendasRealizadas());

    EVT_MENU(Resource.MNU_OP_ALTERARSENHA, new OnMnuAlterarSenha());
    EVT_MENU(Resource.MNU_OP_SOBRE, new OnMnuSobre());
    EVT_MENU(Resource.MNU_OP_SAIR, new OnMnuSair());

    EVT_CLOSE(new OnClose());
  }

  public void FazLayout() {
    this.Layout();
    this.Centre();
  }

  class OnClose
      implements wxCloseListener {
    public void handleEvent(wxCloseEvent event) {
      if (wx.wxMessageBox(Resource.STR_SAIRSIS, "Confirma",
                          wx.wxNO_DEFAULT | wx.wxYES_NO |
                          wx.wxICON_QUESTION) == wx.wxYES) {
        RotinasGlobais.Rotinas.DisconectaBanco();
        Destroy();
        System.exit(0);
      }
    }
  }

  class OnMnuCadAssuntos
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, false);
      frmFilha fCadAssuntos = new frmFilha(frmPrincipal.fPrincipal,
                                           Resource.FRMCADASSUNTOS);
      fCadAssuntos.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadAutores
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, false);
      frmFilha fCadAutores = new frmFilha(frmPrincipal.fPrincipal,
                                          Resource.FRMCADAUTORES);
      fCadAutores.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadEditoras
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, false);
      frmFilha fCadEditoras = new frmFilha(frmPrincipal.fPrincipal,
                                           Resource.FRMCADEDITORAS);
      fCadEditoras.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadEnderecos
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, false);
      frmFilha fCadEnderecos = new frmFilha(frmPrincipal.fPrincipal,
                                            Resource.FRMCADENDERECOS);
      fCadEnderecos.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadIdiomas
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, false);
      frmFilha fCadIdiomas = new frmFilha(frmPrincipal.fPrincipal,
                                          Resource.FRMCADIDIOMAS);
      fCadIdiomas.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadPaises
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, false);
      frmFilha fCadPaises = new frmFilha(frmPrincipal.fPrincipal,
                                         Resource.FRMCADPAISES);
      fCadPaises.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadProfissoes
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, false);
      frmFilha fCadProfissoes = new frmFilha(frmPrincipal.fPrincipal,
                                             Resource.FRMCADPROFISSOES);
      fCadProfissoes.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadClientes
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraFerra.EnableTool(Resource.MNU_CAD_CLIENTES, false);
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, false);
      frmFilha fCadClientes = new frmFilha(frmPrincipal.fPrincipal,
                                           Resource.FRMCADCLIENTES);
      fCadClientes.Show(true);
      event.Skip();
    }
  }

  class OnMnuCadLivros
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraFerra.EnableTool(Resource.MNU_CAD_LIVROS, false);
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, false);
      frmFilha fCadLivros = new frmFilha(frmPrincipal.fPrincipal,
                                         Resource.FRMCADLIVROS);
      fCadLivros.Show(true);
      event.Skip();
    }
  }

  class OnMnuConAssuntos
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONASSUNTO, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_ASSUNTOS, false);
      frmConAssuntos.fConAssuntos = new frmConAssuntos(frmPrincipal.fPrincipal);
      frmConAssuntos.fConAssuntos.Show(true);
      event.Skip();
    }
  }

  class OnMnuConAutores
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONAUTOR, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_AUTORES, false);
      frmConAutores.fConAutores = new frmConAutores(frmPrincipal.fPrincipal);
      frmConAutores.fConAutores.Show(true);
      event.Skip();
    }
  }

  class OnMnuConEditoras
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONEDITORA, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_EDITORAS, false);
      frmConEditoras.fConEditoras = new frmConEditoras(frmPrincipal.fPrincipal);
      frmConEditoras.fConEditoras.Show(true);
      event.Skip();
    }
  }

  class OnMnuConEnderecos
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONENDERECO, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_ENDERECOS, false);
      frmConEnderecos.fConEnderecos = new frmConEnderecos(frmPrincipal.
          fPrincipal);
      frmConEnderecos.fConEnderecos.Show(true);
      event.Skip();
    }
  }

  class OnMnuConIdiomas
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONIDIOMA, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_IDIOMAS, false);
      frmConIdiomas.fConIdiomas = new frmConIdiomas(frmPrincipal.fPrincipal);
      frmConIdiomas.fConIdiomas.Show(true);
      event.Skip();
    }
  }

  class OnMnuConPaises
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONPAIS, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_PAISES, false);
      frmConPaises.fConPaises = new frmConPaises(frmPrincipal.fPrincipal);
      frmConPaises.fConPaises.Show(true);
      event.Skip();
    }
  }

  class OnMnuConProfissoes
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONPROFISS, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_PROFISSOES, false);
      frmConProfissoes.fConProfissoes = new frmConProfissoes(frmPrincipal.
          fPrincipal);
      frmConProfissoes.fConProfissoes.Show(true);
      event.Skip();
    }
  }

  class OnMnuConClientes
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONCLIENTE, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_CLIENTES, false);
      frmConClientes.fConClientes = new frmConClientes(frmPrincipal.fPrincipal);
      frmConClientes.fConClientes.Show(true);
      event.Skip();
    }
  }

  class OnMnuConLivros
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      GetStatusBar().SetStatusText(Resource.STR_CONLIVRO, 1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_LIVROS, false);
      frmConLivros.fConLivros = new frmConLivros(frmPrincipal.fPrincipal);
      frmConLivros.fConLivros.Show(true);
      event.Skip();
    }
  }

  class OnMnuVenderLivros
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraFerra.EnableTool(Resource.MNU_VEN_VENDERLIVROS, false);
      barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDERLIVROS, false);
      frmFilha fVenderLivros = new frmFilha(frmPrincipal.fPrincipal,
                                            Resource.FRMVENDERLIVROS);
      fVenderLivros.Show(true);
      event.Skip();
    }
  }

  class OnMnuVendasRealizadas
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDASREALIZADAS, false);
      frmFilha fConVendas = new frmFilha(frmPrincipal.fPrincipal,
                                         Resource.FRMCONVENDAS);
      fConVendas.Show(true);
      event.Skip();
    }
  }

  class OnMnuAlterarSenha
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      barraMenu.GetMenu(3).Enable(Resource.MNU_OP_ALTERARSENHA, false);
      frmFilha fAlterarSenha = new frmFilha(frmPrincipal.fPrincipal,
                                            Resource.FRMALTERARSENHA);
      fAlterarSenha.Show(true);
      event.Skip();
    }
  }

  class OnMnuSobre
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {

      frmSobre.fSobre = new frmSobre(frmPrincipal.fPrincipal);
      frmSobre.fSobre.ShowModal();
      event.Skip();
    }
  }

  class OnMnuSair
      implements wxCommandListener {
    public void handleEvent(wxCommandEvent event) {
      Close();
      event.Skip();
    }
  }

}
