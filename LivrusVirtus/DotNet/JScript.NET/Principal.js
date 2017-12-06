import System;
import System.Collections;
import System.ComponentModel;
import System.Drawing;
import System.Windows.Forms;
import System.Data;
import System.Data.OleDb;

package Livrus {

public class frmPrincipal extends System.Windows.Forms.Form
{
    public static var fPrincipal: frmPrincipal;   
    /// <summary>
    /// Required designer variable.
    /// </summary>
    private var components: System.ComponentModel.Container;
    private var mainMenu1: System.Windows.Forms.MainMenu;
    private var mnuCadastros: System.Windows.Forms.MenuItem;
    private var mnuPesquisas: System.Windows.Forms.MenuItem;
    private var mnuVendas: System.Windows.Forms.MenuItem;
    private var mnuJanelas: System.Windows.Forms.MenuItem;
    private var mnuOpcoes: System.Windows.Forms.MenuItem;
    private var menuItem1: System.Windows.Forms.MenuItem;
    private var menuItem2: System.Windows.Forms.MenuItem;
    public var mnuLadoALadoHorizontal: System.Windows.Forms.MenuItem;
    private var menuItem3: System.Windows.Forms.MenuItem;
    public var mnuSobre: System.Windows.Forms.MenuItem;
    public var mnuSair: System.Windows.Forms.MenuItem;
    public var mnuLadoALadoVertical: System.Windows.Forms.MenuItem;
    public var mnuEmCascata: System.Windows.Forms.MenuItem;
    public var mnuOrganizarIcones: System.Windows.Forms.MenuItem;
    public var toolBar1: System.Windows.Forms.ToolBar;
    private var statusBarPanel1: System.Windows.Forms.StatusBarPanel;
    private var statusBarPanel2: System.Windows.Forms.StatusBarPanel;
    private var toolBarButton4: System.Windows.Forms.ToolBarButton;
    private var tlbSobre: System.Windows.Forms.ToolBarButton;
    private var tlbSair: System.Windows.Forms.ToolBarButton;
    private var imageList1: System.Windows.Forms.ImageList;

    public var db: System.Data.OleDb.OleDbConnection;
    public var statusBar1: System.Windows.Forms.StatusBar;
    public var tlbClientes: System.Windows.Forms.ToolBarButton;
    public var tlbLivros: System.Windows.Forms.ToolBarButton;
    public var tlbVender: System.Windows.Forms.ToolBarButton;
    public var mnuCadAssuntos: System.Windows.Forms.MenuItem;
    public var mnuConAssuntos: System.Windows.Forms.MenuItem;
    public var mnuCadAutores: System.Windows.Forms.MenuItem;
    public var mnuCadEditoras: System.Windows.Forms.MenuItem;
    public var mnuCadEnderecos: System.Windows.Forms.MenuItem;
    public var mnuCadIdiomas: System.Windows.Forms.MenuItem;
    public var mnuCadPaises: System.Windows.Forms.MenuItem;
    public var mnuCadProfissoes: System.Windows.Forms.MenuItem;
    public var mnuCadClientes: System.Windows.Forms.MenuItem;
    public var mnuCadLivros: System.Windows.Forms.MenuItem;
    public var mnuConAutores: System.Windows.Forms.MenuItem;
    public var mnuConEditoras: System.Windows.Forms.MenuItem;
    public var mnuConEnderecos: System.Windows.Forms.MenuItem;
    public var mnuConIdiomas: System.Windows.Forms.MenuItem;
    public var mnuConPaises: System.Windows.Forms.MenuItem;
    public var mnuConProfissoes: System.Windows.Forms.MenuItem;
    public var mnuConClientes: System.Windows.Forms.MenuItem;
    public var mnuConLivros: System.Windows.Forms.MenuItem;
    public var mnuVenderLivros: System.Windows.Forms.MenuItem;
    public var mnuVendasRealizadas: System.Windows.Forms.MenuItem;
    public var mnuAlterarSenha: System.Windows.Forms.MenuItem;


    public function frmPrincipal()
    {
        //
        // Required for Windows Form Designer support
        //
        InitializeComponent();
    }

    /**
     * Clean up any resources being used.
     */
    protected function Dispose(disposing: boolean): void
    {
        if ( disposing )
        {
            if ( components  != null )
            {
                components.Dispose();
            }
        }
        super.Dispose(disposing);
    }

    /**
     * Required method for Designer support - do not modify
     * the contents of this method with the code editor.
    */
    private function InitializeComponent(): void
    {
	this.components = new System.ComponentModel.Container();
	var resources: System.Resources.ResourceManager = 
		new System.Resources.ResourceManager(GetType());
	this.mainMenu1 = new System.Windows.Forms.MainMenu();
	this.mnuCadastros = new System.Windows.Forms.MenuItem();
	this.mnuCadAssuntos = new System.Windows.Forms.MenuItem();
	this.mnuCadAutores = new System.Windows.Forms.MenuItem();
	this.mnuCadEditoras = new System.Windows.Forms.MenuItem();
	this.mnuCadEnderecos = new System.Windows.Forms.MenuItem();
	this.mnuCadIdiomas = new System.Windows.Forms.MenuItem();
	this.mnuCadPaises = new System.Windows.Forms.MenuItem();
	this.mnuCadProfissoes = new System.Windows.Forms.MenuItem();
	this.menuItem1 = new System.Windows.Forms.MenuItem();
	this.mnuCadClientes = new System.Windows.Forms.MenuItem();
	this.mnuCadLivros = new System.Windows.Forms.MenuItem();
	this.mnuPesquisas = new System.Windows.Forms.MenuItem();
	this.mnuConAssuntos = new System.Windows.Forms.MenuItem();
	this.mnuConAutores = new System.Windows.Forms.MenuItem();
	this.mnuConEditoras = new System.Windows.Forms.MenuItem();
	this.mnuConEnderecos = new System.Windows.Forms.MenuItem();
	this.mnuConIdiomas = new System.Windows.Forms.MenuItem();
	this.mnuConPaises = new System.Windows.Forms.MenuItem();
	this.mnuConProfissoes = new System.Windows.Forms.MenuItem();
	this.menuItem2 = new System.Windows.Forms.MenuItem();
	this.mnuConClientes = new System.Windows.Forms.MenuItem();
	this.mnuConLivros = new System.Windows.Forms.MenuItem();
	this.mnuVendas = new System.Windows.Forms.MenuItem();
	this.mnuVenderLivros = new System.Windows.Forms.MenuItem();
	this.mnuVendasRealizadas = new System.Windows.Forms.MenuItem();
	this.mnuJanelas = new System.Windows.Forms.MenuItem();
	this.mnuLadoALadoHorizontal = new System.Windows.Forms.MenuItem();
	this.mnuLadoALadoVertical = new System.Windows.Forms.MenuItem();
	this.mnuEmCascata = new System.Windows.Forms.MenuItem();
	this.mnuOrganizarIcones = new System.Windows.Forms.MenuItem();
	this.mnuOpcoes = new System.Windows.Forms.MenuItem();
	this.mnuAlterarSenha = new System.Windows.Forms.MenuItem();
	this.menuItem3 = new System.Windows.Forms.MenuItem();
	this.mnuSobre = new System.Windows.Forms.MenuItem();
	this.mnuSair = new System.Windows.Forms.MenuItem();
	this.statusBar1 = new System.Windows.Forms.StatusBar();
	this.statusBarPanel1 = new System.Windows.Forms.StatusBarPanel();
	this.statusBarPanel2 = new System.Windows.Forms.StatusBarPanel();
	this.toolBar1 = new System.Windows.Forms.ToolBar();
	this.tlbClientes = new System.Windows.Forms.ToolBarButton();
	this.tlbLivros = new System.Windows.Forms.ToolBarButton();
	this.tlbVender = new System.Windows.Forms.ToolBarButton();
	this.toolBarButton4 = new System.Windows.Forms.ToolBarButton();
	this.tlbSobre = new System.Windows.Forms.ToolBarButton();
	this.tlbSair = new System.Windows.Forms.ToolBarButton();
	this.imageList1 = new System.Windows.Forms.ImageList(this.components);
	this.db = new System.Data.OleDb.OleDbConnection();
	this.SuspendLayout();
	// 
	// mainMenu1
	// 
	var mainTemp: System.Windows.Forms.MenuItem[] = new System.Windows.Forms.MenuItem[5];
	mainTemp[0] = this.mnuCadastros;
	mainTemp[1] = this.mnuPesquisas;
	mainTemp[2] = this.mnuVendas;
	mainTemp[3] = this.mnuJanelas;
	mainTemp[4] = this.mnuOpcoes;
	this.mainMenu1.MenuItems.AddRange(mainTemp);
	// 
	// mnuCadastros
	// 
	this.mnuCadastros.Index = 0;
	var cadTemp: System.Windows.Forms.MenuItem[] = new System.Windows.Forms.MenuItem[10];
	cadTemp[0] = this.mnuCadAssuntos;
	cadTemp[1] = this.mnuCadAutores;
	cadTemp[2] = this.mnuCadEditoras;
	cadTemp[3] = this.mnuCadEnderecos;
	cadTemp[4] = this.mnuCadIdiomas;
	cadTemp[5] = this.mnuCadPaises;
	cadTemp[6] = this.mnuCadProfissoes;
	cadTemp[7] = this.menuItem1;
	cadTemp[8] = this.mnuCadClientes;
	cadTemp[9] = this.mnuCadLivros;
	this.mnuCadastros.MenuItems.AddRange(cadTemp);
	this.mnuCadastros.Text = "&Cadastros";
	// 
	// mnuCadAssuntos
	// 
	this.mnuCadAssuntos.Index = 0;
	this.mnuCadAssuntos.Text = "&Assuntos";
	// 
	// mnuCadAutores
	// 
	this.mnuCadAutores.Index = 1;
	this.mnuCadAutores.Text = "Au&tores";
	// 
	// mnuCadEditoras
	// 
	this.mnuCadEditoras.Index = 2;
	this.mnuCadEditoras.Text = "&Editoras";
	// 
	// mnuCadEnderecos
	// 
	this.mnuCadEnderecos.Index = 3;
	this.mnuCadEnderecos.Text = "E&ndereços";
	// 
	// mnuCadIdiomas
	// 
	this.mnuCadIdiomas.Index = 4;
	this.mnuCadIdiomas.Text = "&Idiomas";
	// 
	// mnuCadPaises
	// 
	this.mnuCadPaises.Index = 5;
	this.mnuCadPaises.Text = "&Países";
	// 
	// mnuCadProfissoes
	// 
	this.mnuCadProfissoes.Index = 6;
	this.mnuCadProfissoes.Text = "P&rofissões";
	// 
	// menuItem1
	// 
	this.menuItem1.Index = 7;
	this.menuItem1.Text = "-";
	// 
	// mnuCadClientes
	// 
	this.mnuCadClientes.Index = 8;
	this.mnuCadClientes.Text = "&Clientes";
	// 
	// mnuCadLivros
	// 
	this.mnuCadLivros.Index = 9;
	this.mnuCadLivros.Text = "&Livros";
	// 
	// mnuPesquisas
	// 
	this.mnuPesquisas.Index = 1;
	var pesTemp: System.Windows.Forms.MenuItem[] = new System.Windows.Forms.MenuItem[10];
	pesTemp[0] = this.mnuConAssuntos;
	pesTemp[1] = this.mnuConAutores;
	pesTemp[2] = this.mnuConEditoras;
	pesTemp[3] = this.mnuConEnderecos;
	pesTemp[4] = this.mnuConIdiomas;
	pesTemp[5] = this.mnuConPaises;
	pesTemp[6] = this.mnuConProfissoes;
	pesTemp[7] = this.menuItem2;
	pesTemp[8] = this.mnuConClientes;
	pesTemp[9] = this.mnuConLivros;
	this.mnuPesquisas.MenuItems.AddRange(pesTemp);
	this.mnuPesquisas.Text = "&Pesquisas";
	// 
	// mnuConAssuntos
	// 
	this.mnuConAssuntos.Index = 0;
	this.mnuConAssuntos.Text = "&Assuntos";
	// 
	// mnuConAutores
	// 
	this.mnuConAutores.Index = 1;
	this.mnuConAutores.Text = "Au&tores";
	// 
	// mnuConEditoras
	// 
	this.mnuConEditoras.Index = 2;
	this.mnuConEditoras.Text = "&Editoras";
	// 
	// mnuConEnderecos
	// 
	this.mnuConEnderecos.Index = 3;
	this.mnuConEnderecos.Text = "E&ndereços";
	// 
	// mnuConIdiomas
	// 
	this.mnuConIdiomas.Index = 4;
	this.mnuConIdiomas.Text = "&Idiomas";
	// 
	// mnuConPaises
	// 
	this.mnuConPaises.Index = 5;
	this.mnuConPaises.Text = "&Países";
	// 
	// mnuConProfissoes
	// 
	this.mnuConProfissoes.Index = 6;
	this.mnuConProfissoes.Text = "P&rofissões";
	// 
	// menuItem2
	// 
	this.menuItem2.Index = 7;
	this.menuItem2.Text = "-";
	// 
	// mnuConClientes
	// 
	this.mnuConClientes.Index = 8;
	this.mnuConClientes.Text = "&Clientes";
	// 
	// mnuConLivros
	// 
	this.mnuConLivros.Index = 9;
	this.mnuConLivros.Text = "&Livros";
	// 
	// mnuVendas
	// 
	this.mnuVendas.Index = 2;
	var venTemp: System.Windows.Forms.MenuItem[] = new System.Windows.Forms.MenuItem[2];
	venTemp[0] = this.mnuVenderLivros;
	venTemp[1] = this.mnuVendasRealizadas;
	this.mnuVendas.MenuItems.AddRange(venTemp);
	this.mnuVendas.Text = "&Vendas";
	// 
	// mnuVenderLivros
	// 
	this.mnuVenderLivros.Index = 0;
	this.mnuVenderLivros.Text = "&Vender Livros";
	// 
	// mnuVendasRealizadas
	// 
	this.mnuVendasRealizadas.Index = 1;
	this.mnuVendasRealizadas.Text = "Vendas &Realizadas";
	// 
	// mnuJanelas
	// 
	this.mnuJanelas.Index = 3;
	this.mnuJanelas.MdiList = true;
	var janTemp: System.Windows.Forms.MenuItem[] = new System.Windows.Forms.MenuItem[4];
	janTemp[0] = this.mnuLadoALadoHorizontal;
	janTemp[1] = this.mnuLadoALadoVertical;
	janTemp[2] = this.mnuEmCascata;
	janTemp[3] = this.mnuOrganizarIcones;
	this.mnuJanelas.MenuItems.AddRange(janTemp);
	this.mnuJanelas.Text = "&Janelas";
	// 
	// mnuLadoALadoHorizontal
	// 
	this.mnuLadoALadoHorizontal.Index = 0;
	this.mnuLadoALadoHorizontal.Text = "Lado a lado &horizontal";
	// 
	// mnuLadoALadoVertical
	// 
	this.mnuLadoALadoVertical.Index = 1;
	this.mnuLadoALadoVertical.Text = "Lado a lado &vertical";
	// 
	// mnuEmCascata
	// 
	this.mnuEmCascata.Index = 2;
	this.mnuEmCascata.Text = "Em &cascata";
	// 
	// mnuOrganizarIcones
	// 
	this.mnuOrganizarIcones.Index = 3;
	this.mnuOrganizarIcones.Text = "&Organizar ícones";
	// 
	// mnuOpcoes
	// 
	this.mnuOpcoes.Index = 4;
	var opcTemp: System.Windows.Forms.MenuItem[] = new System.Windows.Forms.MenuItem[4];
	opcTemp[0] = this.mnuAlterarSenha;
	opcTemp[1] = this.menuItem3;
	opcTemp[2] = this.mnuSobre;
	opcTemp[3] = this.mnuSair
	this.mnuOpcoes.MenuItems.AddRange(opcTemp);
	this.mnuOpcoes.Text = "&Opções";
	// 
	// mnuAlterarSenha
	// 
	this.mnuAlterarSenha.Index = 0;
	this.mnuAlterarSenha.Text = "&Alterar Senha";
	// 
	// menuItem3
	// 
	this.menuItem3.Index = 1;
	this.menuItem3.Text = "-";
	// 
	// mnuSobre
	// 
	this.mnuSobre.Index = 2;
	this.mnuSobre.Text = "&Sobre";
	// 
	// mnuSair
	// 
	this.mnuSair.Index = 3;
	this.mnuSair.Text = "Sa&ir";
	// 
	// statusBar1
	// 
	this.statusBar1.Location = new System.Drawing.Point(0, 428);
	this.statusBar1.Name = "statusBar1";
	var stbTemp: System.Windows.Forms.StatusBarPanel[] = new System.Windows.Forms.StatusBarPanel[2];
	stbTemp[0] = this.statusBarPanel1;
	stbTemp[1] = this.statusBarPanel2;
	this.statusBar1.Panels.AddRange(stbTemp);
	this.statusBar1.ShowPanels = true;
	this.statusBar1.Size = new System.Drawing.Size(544, 22);
	this.statusBar1.TabIndex = 1;
	// 
	// statusBarPanel1
	// 
	this.statusBarPanel1.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Contents;
	this.statusBarPanel1.Text = "Usuário:";
	this.statusBarPanel1.Width = 56;
	// 
	// statusBarPanel2
	// 
	this.statusBarPanel2.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Spring;
	this.statusBarPanel2.Width = 472;
	// 
	// toolBar1
	// 
	var tlbTemp: System.Windows.Forms.ToolBarButton[] = new System.Windows.Forms.ToolBarButton[6];
	tlbTemp[0] = this.tlbClientes;
	tlbTemp[1] = this.tlbLivros;
	tlbTemp[2] = this.tlbVender;
	tlbTemp[3] = this.toolBarButton4;
	tlbTemp[4] = this.tlbSobre;
	tlbTemp[5] = this.tlbSair;
	this.toolBar1.Buttons.AddRange(tlbTemp);
	this.toolBar1.DropDownArrows = true;
	this.toolBar1.ImageList = this.imageList1;
	this.toolBar1.Location = new System.Drawing.Point(0, 0);
	this.toolBar1.Name = "toolBar1";
	this.toolBar1.ShowToolTips = true;
	this.toolBar1.Size = new System.Drawing.Size(544, 28);
	this.toolBar1.TabIndex = 2;
	// 
	// tlbClientes
	// 
	this.tlbClientes.ImageIndex = 0;
	// 
	// tlbLivros
	// 
	this.tlbLivros.ImageIndex = 1;
	// 
	// tlbVender
	// 
	this.tlbVender.ImageIndex = 2;
	// 
	// toolBarButton4
	// 
	this.toolBarButton4.Style = System.Windows.Forms.ToolBarButtonStyle.Separator;
	// 
	// tlbSobre
	// 
	this.tlbSobre.ImageIndex = 3;
	// 
	// tlbSair
	// 
	this.tlbSair.ImageIndex = 4;
	// 
	// imageList1
	// 
	this.imageList1.ImageSize = new System.Drawing.Size(16, 16);
//	this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
	this.imageList1.TransparentColor = System.Drawing.Color.Olive;
	// 
	// frmPrincipal
	// 
	this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
	this.ClientSize = new System.Drawing.Size(480, 370);
	this.Controls.Add(this.toolBar1);
	this.Controls.Add(this.statusBar1);
//	this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));	
	this.IsMdiContainer = true;
	this.Menu = this.mainMenu1;
	this.Name = "frmPrincipal";
	this.Text = "Livrus Virtus";
	this.ResumeLayout(false);
    }

    protected function OnClosing(e: System.ComponentModel.CancelEventArgs) {   
    	var res: System.Windows.Forms.DialogResult;
    	res = MessageBox.Show(this, "Deseja sair do sistema?",
    	frmPrincipal.fPrincipal.Text, MessageBoxButtons.YesNo,
    	MessageBoxIcon.Question,MessageBoxDefaultButton.Button2);
    
    	if (res == System.Windows.Forms.DialogResult.Yes) {
    		db.Close();
    		e.Cancel=false;
    	 } else
    		e.Cancel=true;
    
    }
   
    protected function OnLoad(e: System.EventArgs)
    {
      db.Open();
    
      //ConsultasSQL.ConsSQL = new ConsultasSQL();
      //RotinasGlobais.Rotinas = new RotinasGlobais();
    
      //frmSplash.fSplash = new frmSplash();
      //frmSplash.fSplash.ShowDialog();
    
      //frmLogin.fLogin = new frmLogin();
      //frmLogin.fLogin.ShowDialog();
    
    }

    protected function OnMouseMove(e: System.Windows.Forms.MouseEventArgs)
    {
    	this.statusBar1.Panels(1).Text(" ");
    }   
      
/*    
    private function mnuSobre_Click(Object sender, System.EventArgs e): void
    {
    	frmSobre.fSobre = new frmSobre();
    	frmSobre.fSobre.ShowDialog();
    }
    
    private function mnuAlterarSenha_Click(Object sender, System.EventArgs e): void {
	mnuAlterarSenha.set_Enabled(false);    
	frmAlterarSenha.fAlterarSenha = new frmAlterarSenha();
    	frmAlterarSenha.fAlterarSenha.set_MdiParent(this);
    	frmAlterarSenha.fAlterarSenha.Show();
    }   
    private function mnuCadAssuntos_Click(Object sender, System.EventArgs e): void {
	mnuCadAssuntos.set_Enabled(false);
    	frmCadAssuntos.fCadAssuntos = new frmCadAssuntos();
    	frmCadAssuntos.fCadAssuntos.set_MdiParent(this);
    	frmCadAssuntos.fCadAssuntos.Show();
    }
    private function mnuConAssuntos_Click(Object sender, System.EventArgs e): void {
	mnuConAssuntos.set_Enabled(false);
   	frmConAssuntos.fConAssuntos = new frmConAssuntos();
    	frmConAssuntos.fConAssuntos.set_MdiParent(this);
    	frmConAssuntos.fConAssuntos.Show();
    }
    private function mnuCadAutores_Click(Object sender, System.EventArgs e): void {
	mnuCadAutores.set_Enabled(false);
    	frmCadAutores.fCadAutores = new frmCadAutores();
    	frmCadAutores.fCadAutores.set_MdiParent(this);
    	frmCadAutores.fCadAutores.Show();
    }
    private function mnuConAutores_Click(Object sender, System.EventArgs e): void {
	mnuConAutores.set_Enabled(false);
   	frmConAutores.fConAutores = new frmConAutores();
    	frmConAutores.fConAutores.set_MdiParent(this);
    	frmConAutores.fConAutores.Show();
    }
    private function mnuCadEditoras_Click(Object sender, System.EventArgs e): void {
	mnuCadEditoras.set_Enabled(false);
    	frmCadEditoras.fCadEditoras = new frmCadEditoras();
    	frmCadEditoras.fCadEditoras.set_MdiParent(this);
    	frmCadEditoras.fCadEditoras.Show();
    }
    private function mnuConEditoras_Click(Object sender, System.EventArgs e): void {
	mnuConEditoras.set_Enabled(false);
   	frmConEditoras.fConEditoras = new frmConEditoras();
    	frmConEditoras.fConEditoras.set_MdiParent(this);
    	frmConEditoras.fConEditoras.Show();
    }
    private function mnuCadEnderecos_Click(Object sender, System.EventArgs e): void {
	mnuCadEnderecos.set_Enabled(false);
    	frmCadEnderecos.fCadEnderecos = new frmCadEnderecos();
    	frmCadEnderecos.fCadEnderecos.set_MdiParent(this);
    	frmCadEnderecos.fCadEnderecos.Show();
    }
    private function mnuConEnderecos_Click(Object sender, System.EventArgs e): void {
	mnuConEnderecos.set_Enabled(false);
   	frmConEnderecos.fConEnderecos = new frmConEnderecos();
    	frmConEnderecos.fConEnderecos.set_MdiParent(this);
    	frmConEnderecos.fConEnderecos.Show();
    }
    private function mnuCadIdiomas_Click(Object sender, System.EventArgs e): void {
	mnuCadIdiomas.set_Enabled(false);
    	frmCadIdiomas.fCadIdiomas = new frmCadIdiomas();
    	frmCadIdiomas.fCadIdiomas.set_MdiParent(this);
    	frmCadIdiomas.fCadIdiomas.Show();
    }
    private function mnuConIdiomas_Click(Object sender, System.EventArgs e): void {
	mnuConIdiomas.set_Enabled(false);
   	frmConIdiomas.fConIdiomas = new frmConIdiomas();
    	frmConIdiomas.fConIdiomas.set_MdiParent(this);
    	frmConIdiomas.fConIdiomas.Show();
    }
    private function mnuCadPaises_Click(Object sender, System.EventArgs e): void {
	mnuCadPaises.set_Enabled(false);
    	frmCadPaises.fCadPaises = new frmCadPaises();
    	frmCadPaises.fCadPaises.set_MdiParent(this);
    	frmCadPaises.fCadPaises.Show();
    }
    private function mnuConPaises_Click(Object sender, System.EventArgs e): void {
	mnuConPaises.set_Enabled(false);
   	frmConPaises.fConPaises = new frmConPaises();
    	frmConPaises.fConPaises.set_MdiParent(this);
    	frmConPaises.fConPaises.Show();
    }
    private function mnuCadProfissoes_Click(Object sender, System.EventArgs e): void {
	mnuCadProfissoes.set_Enabled(false);
    	frmCadProfissoes.fCadProfissoes = new frmCadProfissoes();
    	frmCadProfissoes.fCadProfissoes.set_MdiParent(this);
    	frmCadProfissoes.fCadProfissoes.Show();
    }
    private function mnuConProfissoes_Click(Object sender, System.EventArgs e): void {
	mnuConProfissoes.set_Enabled(false);
   	frmConProfissoes.fConProfissoes = new frmConProfissoes();
    	frmConProfissoes.fConProfissoes.set_MdiParent(this);
    	frmConProfissoes.fConProfissoes.Show();
    }
    private function mnuCadClientes_Click(Object sender, System.EventArgs e): void {
	mnuCadClientes.set_Enabled(false);
	tlbClientes.set_Enabled(false);
    	frmCadClientes.fCadClientes = new frmCadClientes();
    	frmCadClientes.fCadClientes.set_MdiParent(this);
    	frmCadClientes.fCadClientes.Show();
    }
    private function mnuConClientes_Click(Object sender, System.EventArgs e): void {
	mnuConClientes.set_Enabled(false);
   	frmConClientes.fConClientes = new frmConClientes();
    	frmConClientes.fConClientes.set_MdiParent(this);
    	frmConClientes.fConClientes.Show();
    }
    private function mnuCadLivros_Click(Object sender, System.EventArgs e): void {
	mnuCadLivros.set_Enabled(false);
	tlbLivros.set_Enabled(false);
    	frmCadLivros.fCadLivros = new frmCadLivros();
    	frmCadLivros.fCadLivros.set_MdiParent(this);
    	frmCadLivros.fCadLivros.Show();
    }
    private function mnuConLivros_Click(Object sender, System.EventArgs e): void {
	mnuConLivros.set_Enabled(false);
   	frmConLivros.fConLivros = new frmConLivros();
    	frmConLivros.fConLivros.set_MdiParent(this);
    	frmConLivros.fConLivros.Show();
    }
    private function mnuVenderLivros_Click(Object sender, System.EventArgs e): void {
	mnuVenderLivros.set_Enabled(false);
	tlbVender.set_Enabled(false);
    	frmVenderLivros.fVenderLivros = new frmVenderLivros();
    	frmVenderLivros.fVenderLivros.set_MdiParent(this);
    	frmVenderLivros.fVenderLivros.Show();
    }
    private function mnuVendasRealizadas_Click(Object sender, System.EventArgs e): void {
	mnuVendasRealizadas.set_Enabled(false);
   	frmConVendas.fConVendas = new frmConVendas();
    	frmConVendas.fConVendas.set_MdiParent(this);
    	frmConVendas.fConVendas.Show();
    }   
*/
}
 
};
/*
    function frmPrincipal.fPrincipal.mnuSair.OnClick(e: System.EventArgs)
    {
    	frmPrincipal.fPrincipal.Close();
    }

    

    	
    function frmPrincipal.fPrincipal.toolBar1.OnButtonClick(e: System.Windows.Forms.ToolBarButtonClickEventArgs) {

       switch(frmPrincipal.fPrincipal.toolBar1.Buttons.IndexOf(e.Button))
       {
    	  case 0:
    		 //mnuCadClientes_Click(this,null);
    		 break;
    	  case 1:
    		 //mnuCadLivros_Click(this,null);
    		 break;
    	  case 2:
    		 //mnuVenderLivros_Click(this,null);
    		 break;
    	  case 4:
    		 //mnuSobre_Click(this,null);
    		 break;
    	  case 5:
    		 //frmPrincipal.fPrincipal.mnuSair.OnClick(null);
    		 break;
    	}
    }

    function frmPrincipal.fPrincipal.mnuLadoALadoHorizontal.OnClick(e: System.EventArgs)
    {
    	frmPrincipal.fPrincipal.LayoutMdi(MdiLayout.TileHorizontal);
    }
    
    function frmPrincipal.fPrincipal.mnuLadoALadoVertical.OnClick(e: System.EventArgs)
    {
    	frmPrincipal.fPrincipal.LayoutMdi(MdiLayout.TileVertical);
    }
    
    function frmPrincipal.fPrincipal.mnuEmCascata.OnClick(e: System.EventArgs)
    {
    	frmPrincipal.fPrincipal.LayoutMdi(MdiLayout.Cascade);
    }
    
    function frmPrincipal.fPrincipal.mnuOrganizarIcones.OnClick(e: System.EventArgs)
    {
    	frmPrincipal.fPrincipal.LayoutMdi(MdiLayout.ArrangeIcons);
    }

*/