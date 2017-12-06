using System;
using System.Drawing;
using System.Collections;
using wx;

namespace Livrus
{
	public class frmPrincipal : wx.MDIParentFrame
	{
  	public static frmPrincipal fPrincipal = null;

    private wx.Menu mnuCadastros;
    private wx.Menu mnuPesquisas;
    private wx.Menu mnuVendas;
    private wx.Menu mnuOpcoes;
    public wx.MenuBar barraMenu;
    private wx.StatusBar barraStatus;
    private int[] nLarguras;
    public wx.ToolBar barraFerra;

		public frmPrincipal()
			: base( null, -1, Resource.STR_TITULO, new Point( -1, -1 ),  
        new Size(640, 480), wx.MDIParentFrame.wxDEFAULT_MDI_FRAME_STYLE){

      Icon = new wx.Icon("xpms/livrus.xpm");

      //Barra de Menu
    	mnuCadastros = new wx.Menu();
    	mnuCadastros.Append((int)Resource.MNU_CAD_ASSUNTOS, "&Assuntos", Resource.STR_CADASSUNTO);
    	mnuCadastros.Append((int)Resource.MNU_CAD_AUTORES, "A&utores", Resource.STR_CADAUTOR);
    	mnuCadastros.Append((int)Resource.MNU_CAD_EDITORAS, "&Editoras", Resource.STR_CADEDITORA);
    	mnuCadastros.Append((int)Resource.MNU_CAD_ENDERECOS, "E&ndereços", Resource.STR_CADENDERECO);
    	mnuCadastros.Append((int)Resource.MNU_CAD_IDIOMAS, "&Idiomas", Resource.STR_CADIDIOMA);
    	mnuCadastros.Append((int)Resource.MNU_CAD_PAISES, "&Países", Resource.STR_CADPAIS);
    	mnuCadastros.Append((int)Resource.MNU_CAD_PROFISSOES, "P&rofissões", Resource.STR_CADPROFISS);
    	mnuCadastros.AppendSeparator();
    	mnuCadastros.Append((int)Resource.MNU_CAD_CLIENTES, "&Clientes", Resource.STR_CADCLIENTE);
    	mnuCadastros.Append((int)Resource.MNU_CAD_LIVROS, "&Livros", Resource.STR_CADLIVRO);
  
    	mnuPesquisas = new wx.Menu();
    	mnuPesquisas.Append((int)Resource.MNU_CON_ASSUNTOS, "&Assuntos", Resource.STR_CONASSUNTO);
    	mnuPesquisas.Append((int)Resource.MNU_CON_AUTORES, "A&utores", Resource.STR_CONAUTOR);
    	mnuPesquisas.Append((int)Resource.MNU_CON_EDITORAS, "&Editoras", Resource.STR_CONEDITORA);
    	mnuPesquisas.Append((int)Resource.MNU_CON_ENDERECOS, "E&ndereços", Resource.STR_CONENDERECO);
    	mnuPesquisas.Append((int)Resource.MNU_CON_IDIOMAS, "&Idiomas", Resource.STR_CONIDIOMA);
    	mnuPesquisas.Append((int)Resource.MNU_CON_PAISES, "&Países", Resource.STR_CONPAIS);
    	mnuPesquisas.Append((int)Resource.MNU_CON_PROFISSOES, "P&rofissões", Resource.STR_CONPROFISS);
    	mnuPesquisas.AppendSeparator();
    	mnuPesquisas.Append((int)Resource.MNU_CON_CLIENTES, "&Clientes", Resource.STR_CONCLIENTE);
    	mnuPesquisas.Append((int)Resource.MNU_CON_LIVROS, "&Livros", Resource.STR_CONLIVRO);
    
    	mnuVendas = new wx.Menu();
    	mnuVendas.Append((int)Resource.MNU_VEN_VENDERLIVROS, "&Vender Livros", Resource.STR_VENLIVRO);
    	mnuVendas.Append((int)Resource.MNU_VEN_VENDASREALIZADAS, "Vendas &Realizadas", Resource.STR_CONVENLIVRO);
    
    	mnuOpcoes = new wx.Menu();
    	mnuOpcoes.Append((int)Resource.MNU_OP_ALTERARSENHA, "&Alterar Senha", Resource.STR_ALTSENHA);
    	mnuOpcoes.AppendSeparator();
    	mnuOpcoes.Append((int)Resource.MNU_OP_SOBRE, "&Sobre", Resource.STR_OPSOBRE);
    	mnuOpcoes.Append((int)Resource.MNU_OP_SAIR, "Sa&ir\tCtrl-S", Resource.STR_OPSAIR);
    
    	barraMenu = new wx.MenuBar();
    	barraMenu.Append(mnuCadastros, "&Cadastros");
    	barraMenu.Append(mnuPesquisas, "&Pesquisas");
    	barraMenu.Append(mnuVendas, "&Vendas");
    	barraMenu.Append(mnuOpcoes, "&Opções");
    
    	MenuBar = barraMenu; 
    
      //Barra de ferramentas    
      barraFerra = new wx.ToolBar(this, -1, wxDefaultPosition, wxDefaultSize, 
        wx.ToolBar.wxTB_HORIZONTAL | wx.ToolBar.wxNO_BORDER);
      ToolBar = barraFerra;
      barraFerra.AddTool((int)Resource.MNU_CAD_CLIENTES, "", 
        new wx.Bitmap("xpms/cliente.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), 
        "", wx.ItemKind.wxITEM_NORMAL);
    	barraFerra.AddTool((int)Resource.MNU_CAD_LIVROS, "", 
        new wx.Bitmap("xpms/livro.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), 
        "", wx.ItemKind.wxITEM_NORMAL);
    	barraFerra.AddTool((int)Resource.MNU_VEN_VENDERLIVROS, "", 
        new wx.Bitmap("xpms/livros.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), 
        "", wx.ItemKind.wxITEM_NORMAL);
      barraFerra.AddSeparator();
    	barraFerra.AddTool((int)Resource.MNU_OP_SOBRE, "", 
        new wx.Bitmap("xpms/sobre.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), 
        "", wx.ItemKind.wxITEM_NORMAL);
    	barraFerra.AddTool((int)Resource.MNU_OP_SAIR, "", 
        new wx.Bitmap("xpms/sair.xpm", wx.BitmapType.wxBITMAP_TYPE_XPM), 
        "", wx.ItemKind.wxITEM_NORMAL);
      barraFerra.Realize();

      barraStatus = CreateStatusBar(2);
      StatusBarPane = 1;
      nLarguras = new int[2];
      nLarguras[0] = 100;
      nLarguras[1] = -1;
      barraStatus.StatusWidths = nLarguras;
      barraStatus.SetStatusText(Resource.STR_USUARIO, 0);
  
    	FazLayout();

      EVT_MENU((int)Resource.MNU_CAD_ASSUNTOS, new EventListener( OnMnuCadAssuntos ));
      EVT_MENU((int)Resource.MNU_CAD_AUTORES, new EventListener( OnMnuCadAutores ));
      EVT_MENU((int)Resource.MNU_CAD_EDITORAS, new EventListener( OnMnuCadEditoras ));
      EVT_MENU((int)Resource.MNU_CAD_ENDERECOS, new EventListener( OnMnuCadEnderecos ));
      EVT_MENU((int)Resource.MNU_CAD_IDIOMAS, new EventListener( OnMnuCadIdiomas ));
      EVT_MENU((int)Resource.MNU_CAD_PAISES, new EventListener( OnMnuCadPaises ));
      EVT_MENU((int)Resource.MNU_CAD_PROFISSOES, new EventListener( OnMnuCadProfissoes ));
      EVT_MENU((int)Resource.MNU_CAD_CLIENTES, new EventListener( OnMnuCadClientes ));
      EVT_MENU((int)Resource.MNU_CAD_LIVROS, new EventListener( OnMnuCadLivros ));
  
      EVT_MENU((int)Resource.MNU_CON_ASSUNTOS, new EventListener( OnMnuConAssuntos ));
      EVT_MENU((int)Resource.MNU_CON_AUTORES, new EventListener( OnMnuConAutores ));
      EVT_MENU((int)Resource.MNU_CON_EDITORAS, new EventListener( OnMnuConEditoras ));
      EVT_MENU((int)Resource.MNU_CON_ENDERECOS, new EventListener( OnMnuConEnderecos ));
      EVT_MENU((int)Resource.MNU_CON_IDIOMAS, new EventListener( OnMnuConIdiomas ));
      EVT_MENU((int)Resource.MNU_CON_PAISES, new EventListener( OnMnuConPaises ));
      EVT_MENU((int)Resource.MNU_CON_PROFISSOES, new EventListener( OnMnuConProfissoes ));
      EVT_MENU((int)Resource.MNU_CON_CLIENTES, new EventListener( OnMnuConClientes ));
      EVT_MENU((int)Resource.MNU_CON_LIVROS, new EventListener( OnMnuConLivros ));
  
      EVT_MENU((int)Resource.MNU_VEN_VENDERLIVROS, new EventListener( OnMnuVenderLivros ));
      EVT_MENU((int)Resource.MNU_VEN_VENDASREALIZADAS, new EventListener( OnMnuVendasRealizadas ));
  
      EVT_MENU((int)Resource.MNU_OP_ALTERARSENHA, new EventListener( OnMnuAlterarSenha ));
      EVT_MENU((int)Resource.MNU_OP_SOBRE, new EventListener( OnMnuSobre ));
      EVT_MENU((int)Resource.MNU_OP_SAIR, new EventListener( OnClose ));

			EVT_CLOSE( new EventListener( OnClose ) );
		}

    public void FazLayout(){
      this.Layout();
      this.Centre();
    }

		public void OnClose( object sender, Event e ){
      wx.MessageDialog mens;
      mens = new wx.MessageDialog(this, Resource.STR_SAIRSIS, "Confirma",
       wx.Dialog.wxNO_DEFAULT | wx.Dialog.wxYES_NO | wx.Dialog.wxICON_QUESTION);
      if (mens.ShowModal() == wx.Dialog.wxID_YES)
        Destroy();      
		}

    public void OnMnuCadAssuntos( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, false);
      frmFilha fCadAssuntos = new frmFilha(this, Resource.FRMCADASSUNTOS);
      e.Skip();
    }
  
    public void OnMnuCadAutores( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, false);
      frmFilha fCadAutores = new frmFilha(this, Resource.FRMCADAUTORES);
      e.Skip();
    }
  
    public void OnMnuCadEditoras( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, false);
      frmFilha fCadEditoras = new frmFilha(this, Resource.FRMCADEDITORAS);
      e.Skip();
    }
  
    public void OnMnuCadEnderecos( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, false);
      frmFilha fCadEnderecos = new frmFilha(this, Resource.FRMCADENDERECOS);
      e.Skip();
    }
  
    public void OnMnuCadIdiomas( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, false);
      frmFilha fCadIdiomas = new frmFilha(this, Resource.FRMCADIDIOMAS);
      e.Skip();
    }
  
    public void OnMnuCadPaises( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, false);
      frmFilha fCadPaises = new frmFilha(this, Resource.FRMCADPAISES);
      e.Skip();
    }
  
    public void OnMnuCadProfissoes( object sender, Event e ){
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, false);
      frmFilha fCadProfissoes = new frmFilha(this, Resource.FRMCADPROFISSOES);
      e.Skip();
    }
  
    public void OnMnuCadClientes( object sender, Event e ){
      barraFerra.EnableTool(Resource.MNU_CAD_CLIENTES, false);
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, false);
      frmFilha fCadClientes = new frmFilha(this, Resource.FRMCADCLIENTES);
      e.Skip();
    }
  
    public void OnMnuCadLivros( object sender, Event e ){
      barraFerra.EnableTool(Resource.MNU_CAD_LIVROS, false);
      barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, false);
      frmFilha fCadLivros = new frmFilha(this, Resource.FRMCADLIVROS);
      e.Skip();
    }
  
    public void OnMnuConAssuntos( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONASSUNTO,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_ASSUNTOS, false);
      frmConAssuntos.fConAssuntos = new frmConAssuntos(this);
      frmConAssuntos.fConAssuntos.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConAutores( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONAUTOR,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_AUTORES, false);
      frmConAutores.fConAutores = new frmConAutores(this);
      frmConAutores.fConAutores.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConEditoras( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONEDITORA,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_EDITORAS, false);
      frmConEditoras.fConEditoras = new frmConEditoras(this);
      frmConEditoras.fConEditoras.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConEnderecos( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONENDERECO,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_ENDERECOS, false);
      frmConEnderecos.fConEnderecos = new frmConEnderecos(this);
      frmConEnderecos.fConEnderecos.Show(true);
      e.Skip();
    }
  
    public void OnMnuConIdiomas( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONIDIOMA,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_IDIOMAS, false);
      frmConIdiomas.fConIdiomas = new frmConIdiomas(this);
      frmConIdiomas.fConIdiomas.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConPaises( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONPAIS,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_PAISES, false);
      frmConPaises.fConPaises = new frmConPaises(this);
      frmConPaises.fConPaises.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConProfissoes( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONPROFISS,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_PROFISSOES, false);
      frmConProfissoes.fConProfissoes = new frmConProfissoes(this);
      frmConProfissoes.fConProfissoes.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConClientes( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONCLIENTE,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_CLIENTES, false);
      frmConClientes.fConClientes = new frmConClientes(this);
      frmConClientes.fConClientes.Show(true);
    	e.Skip();
    }
  
    public void OnMnuConLivros( object sender, Event e ){
      this.StatusBar.SetStatusText(Resource.STR_CONLIVRO,1);
      barraMenu.GetMenu(1).Enable(Resource.MNU_CON_LIVROS, false);
      frmConLivros.fConLivros = new frmConLivros(this);
      frmConLivros.fConLivros.Show(true);
    	e.Skip();
    }
  
    public void OnMnuVenderLivros( object sender, Event e ){
      barraFerra.EnableTool(Resource.MNU_VEN_VENDERLIVROS, false);
      barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDERLIVROS, false);
      frmFilha fVenderLivros = new frmFilha(this, Resource.FRMVENDERLIVROS);
      e.Skip();
    }
  
    public void OnMnuVendasRealizadas( object sender, Event e ){
      barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDASREALIZADAS, false);
      frmFilha fVendasRealizadas = new frmFilha(this, Resource.FRMCONVENDAS);
      e.Skip();
    }
  
    public void OnMnuAlterarSenha( object sender, Event e ){
      barraMenu.GetMenu(3).Enable(Resource.MNU_OP_ALTERARSENHA, false);
      frmFilha fAlterarSenha = new frmFilha(this, Resource.FRMALTERARSENHA);
      e.Skip();
    }
   
    public void OnMnuSobre( object sender, Event e ){
      frmSobre.fSobre = new frmSobre(this);
      frmSobre.fSobre.ShowModal();
      e.Skip();
		}	
	}
}
