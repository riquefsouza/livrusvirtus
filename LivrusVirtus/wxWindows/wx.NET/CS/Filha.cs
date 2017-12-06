using System;
using System.Drawing;
using wx;

namespace Livrus
{
	public class frmFilha : wx.MDIChildFrame {
    private int nLocalTelaAtiva;

    private frmCadAssuntos fCadAssuntos;
    private frmCadAutores fCadAutores;
    private frmCadEditoras fCadEditoras;
    private frmCadEnderecos fCadEnderecos;
    private frmCadIdiomas fCadIdiomas;
    private frmCadPaises fCadPaises;
    private frmCadProfissoes fCadProfissoes;
    private frmCadClientes fCadClientes;
    private frmCadLivros fCadLivros;
    private frmVenderLivros fVenderLivros;
    private frmConVendas fConVendas;
    private frmAlterarSenha fAlterarSenha;

		public frmFilha( MDIParentFrame parent, int nTelaAtiva )
			: base(parent, -1, "Cadastro de ", new Point(0, 0), 
      new Size(342, 219), wxDEFAULT_FRAME_STYLE,""){

      ClientSize = new Size(330, 136);
			Icon = new wx.Icon( "xpms/livrus.xpm" );
			EVT_CLOSE( new EventListener( OnClose ) );
      nLocalTelaAtiva = nTelaAtiva;

      if (nTelaAtiva == Resource.FRMCADASSUNTOS) {
        fCadAssuntos = new frmCadAssuntos(this);
        Title = Resource.STR_CADASSUNTO;
      } else if (nTelaAtiva == Resource.FRMCADAUTORES) {
        fCadAutores = new frmCadAutores(this);
        Title = Resource.STR_CADAUTOR;
      } else if (nTelaAtiva == Resource.FRMCADEDITORAS) {
        fCadEditoras = new frmCadEditoras(this);
        Title = Resource.STR_CADEDITORA;
      } else if (nTelaAtiva == Resource.FRMCADENDERECOS) {
        fCadEnderecos = new frmCadEnderecos(this);
        Title = Resource.STR_CADENDERECO;
        ClientSize = new Size(525, 170);
      } else if (nTelaAtiva == Resource.FRMCADIDIOMAS) {
        fCadIdiomas = new frmCadIdiomas(this);
        Title = Resource.STR_CADIDIOMA;
      } else if (nTelaAtiva == Resource.FRMCADPAISES) {
        fCadPaises = new frmCadPaises(this);
        Title = Resource.STR_CADPAIS;
      } else if (nTelaAtiva == Resource.FRMCADPROFISSOES) {
        fCadProfissoes = new frmCadProfissoes(this);
        Title = Resource.STR_CADPROFISS;
      } else if (nTelaAtiva == Resource.FRMCADCLIENTES) {
        fCadClientes = new frmCadClientes(this);
        Title = Resource.STR_CADCLIENTE;
        ClientSize = new Size(525, 440);
      } else if (nTelaAtiva == Resource.FRMCADLIVROS) {
        fCadLivros = new frmCadLivros(this);
        Title = Resource.STR_CADLIVRO;
        ClientSize = new Size(510, 385);
      } else if (nTelaAtiva == Resource.FRMVENDERLIVROS) {
        fVenderLivros = new frmVenderLivros(this);
        Title = Resource.STR_VENLIVRO;
        ClientSize = new Size(480, 310);
      } else if (nTelaAtiva == Resource.FRMCONVENDAS) {
        fConVendas = new frmConVendas(this);
        Title = Resource.STR_CONVENLIVRO;
        ClientSize = new Size(480, 330);
      } else if (nTelaAtiva == Resource.FRMALTERARSENHA) {
        fAlterarSenha = new frmAlterarSenha(this);
        Title = Resource.STR_ALTSENHA;
        ClientSize = new Size(255, 134);
      }		
		}

		public override void OnActivate( object sender, Event e ){
			ActivateEvent ae = (ActivateEvent) e;
			if ( ae.Active ) {      
        if (nLocalTelaAtiva == Resource.FRMCADASSUNTOS)
          fCadAssuntos.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADAUTORES) 
          fCadAutores.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADEDITORAS)
          fCadEditoras.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADENDERECOS)
          fCadEnderecos.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADIDIOMAS)
          fCadIdiomas.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADPAISES) 
          fCadPaises.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADPROFISSOES) 
          fCadProfissoes.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADCLIENTES)
          fCadClientes.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCADLIVROS)
          fCadLivros.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMVENDERLIVROS)
          fVenderLivros.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMCONVENDAS) 
          fConVendas.SetFocus();
        else if (nLocalTelaAtiva == Resource.FRMALTERARSENHA)
          fAlterarSenha.SetFocus();
      }
		}

		public void OnClose( object sender, Event e ){
      if (nLocalTelaAtiva == Resource.FRMCADASSUNTOS)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ASSUNTOS, true);
      else if (nLocalTelaAtiva == Resource.FRMCADAUTORES) 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_AUTORES, true);
      else if (nLocalTelaAtiva == Resource.FRMCADEDITORAS)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_EDITORAS, true);    
      else if (nLocalTelaAtiva == Resource.FRMCADENDERECOS)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_ENDERECOS, true);    
      else if (nLocalTelaAtiva == Resource.FRMCADIDIOMAS)
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_IDIOMAS, true);
      else if (nLocalTelaAtiva == Resource.FRMCADPAISES) 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PAISES, true);    
      else if (nLocalTelaAtiva == Resource.FRMCADPROFISSOES) 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_PROFISSOES, true);
      else if (nLocalTelaAtiva == Resource.FRMCADCLIENTES) {
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_CAD_CLIENTES, true);
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_CLIENTES, true);
      } else if (nLocalTelaAtiva == Resource.FRMCADLIVROS) {
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_CAD_LIVROS, true);
        frmPrincipal.fPrincipal.barraMenu.GetMenu(0).Enable(Resource.MNU_CAD_LIVROS, true);
      } else if (nLocalTelaAtiva == Resource.FRMVENDERLIVROS) {
        frmPrincipal.fPrincipal.barraFerra.EnableTool(Resource.MNU_VEN_VENDERLIVROS, true);
        frmPrincipal.fPrincipal.barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDERLIVROS, true);  
      } else if (nLocalTelaAtiva == Resource.FRMCONVENDAS) 
        frmPrincipal.fPrincipal.barraMenu.GetMenu(2).Enable(Resource.MNU_VEN_VENDASREALIZADAS, true);
      else if (nLocalTelaAtiva == Resource.FRMALTERARSENHA) {
        frmPrincipal.fPrincipal.barraMenu.GetMenu(3).Enable(Resource.MNU_OP_ALTERARSENHA, true);
      }
      e.Skip();
		}		
	}
}
