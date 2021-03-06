using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Data.OleDb;

namespace Livrus
{
	/// <summary>
	/// Summary description for WinForm.
	/// </summary>
	public class frmPrincipal : System.Windows.Forms.Form
	{
		public static frmPrincipal fPrincipal;

		public System.Windows.Forms.StatusBar statusBar1;
		public System.Data.OleDb.OleDbConnection db;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components;
		private System.Windows.Forms.MainMenu mainMenu1;
		private System.Windows.Forms.MenuItem mnuCadastros;
		public System.Windows.Forms.MenuItem mnuCadAssuntos;
		private System.Windows.Forms.StatusBarPanel statusBarPanel1;
		private System.Windows.Forms.StatusBarPanel statusBarPanel2;
		private System.Windows.Forms.ToolBar toolBar1;
		public System.Windows.Forms.ToolBarButton tlbClientes;
		public System.Windows.Forms.ToolBarButton tlbLivros;
		public System.Windows.Forms.ToolBarButton tlbVender;
		private System.Windows.Forms.ToolBarButton toolBarButton4;
		private System.Windows.Forms.ToolBarButton tlbSobre;
		private System.Windows.Forms.ToolBarButton tlbSair;
		private System.Windows.Forms.ImageList imageList1;
		public System.Windows.Forms.MenuItem mnuCadAutores;
		public System.Windows.Forms.MenuItem mnuCadEditoras;
		public System.Windows.Forms.MenuItem mnuCadEnderecos;
		public System.Windows.Forms.MenuItem mnuCadIdiomas;
		public System.Windows.Forms.MenuItem mnuCadPaises;
		public System.Windows.Forms.MenuItem mnuCadProfissoes;
		private System.Windows.Forms.MenuItem menuItem1;
		public System.Windows.Forms.MenuItem mnuCadClientes;
		public System.Windows.Forms.MenuItem mnuCadLivros;
		private System.Windows.Forms.MenuItem mnuPesquisas;
		public System.Windows.Forms.MenuItem mnuConAssuntos;
		public System.Windows.Forms.MenuItem mnuConAutores;
		public System.Windows.Forms.MenuItem mnuConEditoras;
		public System.Windows.Forms.MenuItem mnuConEnderecos;
		public System.Windows.Forms.MenuItem mnuConIdiomas;
		public System.Windows.Forms.MenuItem mnuConPaises;
		public System.Windows.Forms.MenuItem mnuConProfissoes;
		private System.Windows.Forms.MenuItem menuItem2;
		public System.Windows.Forms.MenuItem mnuConClientes;
		public System.Windows.Forms.MenuItem mnuConLivros;
		private System.Windows.Forms.MenuItem mnuVendas;
		public System.Windows.Forms.MenuItem mnuVenderLivros;
		public System.Windows.Forms.MenuItem mnuVendasRealizadas;
		private System.Windows.Forms.MenuItem mnuJanelas;
		private System.Windows.Forms.MenuItem mnuLadoALadoHorizontal;
		private System.Windows.Forms.MenuItem mnuLadoALadoVertical;
		private System.Windows.Forms.MenuItem mnuEmCascata;
		private System.Windows.Forms.MenuItem mnuOrganizarIcones;
		private System.Windows.Forms.MenuItem mnuOpcoes;
		public System.Windows.Forms.MenuItem mnuAlterarSenha;
		private System.Windows.Forms.MenuItem menuItem3;
		private System.Windows.Forms.MenuItem mnuSobre;
		private System.Windows.Forms.MenuItem mnuSair;

		public frmPrincipal()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose (bool disposing)
		{
			if (disposing)
			{
				if (components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(frmPrincipal));
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
			((System.ComponentModel.ISupportInitialize)(this.statusBarPanel1)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.statusBarPanel2)).BeginInit();
			this.SuspendLayout();
			// 
			// mainMenu1
			// 
			this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
						this.mnuCadastros,
						this.mnuPesquisas,
						this.mnuVendas,
						this.mnuJanelas,
						this.mnuOpcoes});
			// 
			// mnuCadastros
			// 
			this.mnuCadastros.Index = 0;
			this.mnuCadastros.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
						this.mnuCadAssuntos,
						this.mnuCadAutores,
						this.mnuCadEditoras,
						this.mnuCadEnderecos,
						this.mnuCadIdiomas,
						this.mnuCadPaises,
						this.mnuCadProfissoes,
						this.menuItem1,
						this.mnuCadClientes,
						this.mnuCadLivros});
			this.mnuCadastros.Text = "&Cadastros";
			// 
			// mnuCadAssuntos
			// 
			this.mnuCadAssuntos.Index = 0;
			this.mnuCadAssuntos.Text = "&Assuntos";
			this.mnuCadAssuntos.Click += new System.EventHandler(this.mnuCadAssuntos_Click);
			// 
			// mnuCadAutores
			// 
			this.mnuCadAutores.Index = 1;
			this.mnuCadAutores.Text = "Au&tores";
			this.mnuCadAutores.Click += new System.EventHandler(this.mnuCadAutores_Click);
			// 
			// mnuCadEditoras
			// 
			this.mnuCadEditoras.Index = 2;
			this.mnuCadEditoras.Text = "&Editoras";
			this.mnuCadEditoras.Click += new System.EventHandler(this.mnuCadEditoras_Click);
			// 
			// mnuCadEnderecos
			// 
			this.mnuCadEnderecos.Index = 3;
			this.mnuCadEnderecos.Text = "E&ndere�os";
			this.mnuCadEnderecos.Click += new System.EventHandler(this.mnuCadEnderecos_Click);
			// 
			// mnuCadIdiomas
			// 
			this.mnuCadIdiomas.Index = 4;
			this.mnuCadIdiomas.Text = "&Idiomas";
			this.mnuCadIdiomas.Click += new System.EventHandler(this.mnuCadIdiomas_Click);
			// 
			// mnuCadPaises
			// 
			this.mnuCadPaises.Index = 5;
			this.mnuCadPaises.Text = "&Pa�ses";
			this.mnuCadPaises.Click += new System.EventHandler(this.mnuCadPaises_Click);
			// 
			// mnuCadProfissoes
			// 
			this.mnuCadProfissoes.Index = 6;
			this.mnuCadProfissoes.Text = "P&rofiss�es";
			this.mnuCadProfissoes.Click += new System.EventHandler(this.mnuCadProfissoes_Click);
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
			this.mnuCadClientes.Click += new System.EventHandler(this.mnuCadClientes_Click);
			// 
			// mnuCadLivros
			// 
			this.mnuCadLivros.Index = 9;
			this.mnuCadLivros.Text = "&Livros";
			this.mnuCadLivros.Click += new System.EventHandler(this.mnuCadLivros_Click);
			// 
			// mnuPesquisas
			// 
			this.mnuPesquisas.Index = 1;
			this.mnuPesquisas.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
						this.mnuConAssuntos,
						this.mnuConAutores,
						this.mnuConEditoras,
						this.mnuConEnderecos,
						this.mnuConIdiomas,
						this.mnuConPaises,
						this.mnuConProfissoes,
						this.menuItem2,
						this.mnuConClientes,
						this.mnuConLivros});
			this.mnuPesquisas.Text = "&Pesquisas";
			// 
			// mnuConAssuntos
			// 
			this.mnuConAssuntos.Index = 0;
			this.mnuConAssuntos.Text = "&Assuntos";
			this.mnuConAssuntos.Click += new System.EventHandler(this.mnuConAssuntos_Click);
			// 
			// mnuConAutores
			// 
			this.mnuConAutores.Index = 1;
			this.mnuConAutores.Text = "Au&tores";
			this.mnuConAutores.Click += new System.EventHandler(this.mnuConAutores_Click);
			// 
			// mnuConEditoras
			// 
			this.mnuConEditoras.Index = 2;
			this.mnuConEditoras.Text = "&Editoras";
			this.mnuConEditoras.Click += new System.EventHandler(this.mnuConEditoras_Click);
			// 
			// mnuConEnderecos
			// 
			this.mnuConEnderecos.Index = 3;
			this.mnuConEnderecos.Text = "E&ndere�os";
			this.mnuConEnderecos.Click += new System.EventHandler(this.mnuConEnderecos_Click);
			// 
			// mnuConIdiomas
			// 
			this.mnuConIdiomas.Index = 4;
			this.mnuConIdiomas.Text = "&Idiomas";
			this.mnuConIdiomas.Click += new System.EventHandler(this.mnuConIdiomas_Click);
			// 
			// mnuConPaises
			// 
			this.mnuConPaises.Index = 5;
			this.mnuConPaises.Text = "&Pa�ses";
			this.mnuConPaises.Click += new System.EventHandler(this.mnuConPaises_Click);
			// 
			// mnuConProfissoes
			// 
			this.mnuConProfissoes.Index = 6;
			this.mnuConProfissoes.Text = "P&rofiss�es";
			this.mnuConProfissoes.Click += new System.EventHandler(this.mnuConProfissoes_Click);
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
			this.mnuConClientes.Click += new System.EventHandler(this.mnuConClientes_Click);
			// 
			// mnuConLivros
			// 
			this.mnuConLivros.Index = 9;
			this.mnuConLivros.Text = "&Livros";
			this.mnuConLivros.Click += new System.EventHandler(this.mnuConLivros_Click);
			// 
			// mnuVendas
			// 
			this.mnuVendas.Index = 2;
			this.mnuVendas.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
						this.mnuVenderLivros,
						this.mnuVendasRealizadas});
			this.mnuVendas.Text = "&Vendas";
			// 
			// mnuVenderLivros
			// 
			this.mnuVenderLivros.Index = 0;
			this.mnuVenderLivros.Text = "&Vender Livros";
			this.mnuVenderLivros.Click += new System.EventHandler(this.mnuVenderLivros_Click);
			// 
			// mnuVendasRealizadas
			// 
			this.mnuVendasRealizadas.Index = 1;
			this.mnuVendasRealizadas.Text = "Vendas &Realizadas";
			this.mnuVendasRealizadas.Click += new System.EventHandler(this.mnuVendasRealizadas_Click);
			// 
			// mnuJanelas
			// 
			this.mnuJanelas.Index = 3;
			this.mnuJanelas.MdiList = true;
			this.mnuJanelas.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
						this.mnuLadoALadoHorizontal,
						this.mnuLadoALadoVertical,
						this.mnuEmCascata,
						this.mnuOrganizarIcones});
			this.mnuJanelas.Text = "&Janelas";
			// 
			// mnuLadoALadoHorizontal
			// 
			this.mnuLadoALadoHorizontal.Index = 0;
			this.mnuLadoALadoHorizontal.Text = "Lado a lado &horizontal";
			this.mnuLadoALadoHorizontal.Click += new System.EventHandler(this.mnuLadoALadoHorizontal_Click);
			// 
			// mnuLadoALadoVertical
			// 
			this.mnuLadoALadoVertical.Index = 1;
			this.mnuLadoALadoVertical.Text = "Lado a lado &vertical";
			this.mnuLadoALadoVertical.Click += new System.EventHandler(this.mnuLadoALadoVertical_Click);
			// 
			// mnuEmCascata
			// 
			this.mnuEmCascata.Index = 2;
			this.mnuEmCascata.Text = "Em &cascata";
			this.mnuEmCascata.Click += new System.EventHandler(this.mnuEmCascata_Click);
			// 
			// mnuOrganizarIcones
			// 
			this.mnuOrganizarIcones.Index = 3;
			this.mnuOrganizarIcones.Text = "&Organizar �cones";
			this.mnuOrganizarIcones.Click += new System.EventHandler(this.mnuOrganizarIcones_Click);
			// 
			// mnuOpcoes
			// 
			this.mnuOpcoes.Index = 4;
			this.mnuOpcoes.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
						this.mnuAlterarSenha,
						this.menuItem3,
						this.mnuSobre,
						this.mnuSair});
			this.mnuOpcoes.Text = "&Op��es";
			// 
			// mnuAlterarSenha
			// 
			this.mnuAlterarSenha.Index = 0;
			this.mnuAlterarSenha.Text = "&Alterar Senha";
			this.mnuAlterarSenha.Click += new System.EventHandler(this.mnuAlterarSenha_Click);
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
			this.mnuSobre.Click += new System.EventHandler(this.mnuSobre_Click);
			// 
			// mnuSair
			// 
			this.mnuSair.Index = 3;
			this.mnuSair.Text = "Sa&ir";
			this.mnuSair.Click += new System.EventHandler(this.mnuSair_Click);
			// 
			// statusBar1
			// 
			this.statusBar1.Location = new System.Drawing.Point(0, 428);
			this.statusBar1.Name = "statusBar1";
			this.statusBar1.Panels.AddRange(new System.Windows.Forms.StatusBarPanel[] {
						this.statusBarPanel1,
						this.statusBarPanel2});
			this.statusBar1.ShowPanels = true;
			this.statusBar1.Size = new System.Drawing.Size(544, 22);
			this.statusBar1.TabIndex = 1;
			// 
			// statusBarPanel1
			// 
			this.statusBarPanel1.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Contents;
			this.statusBarPanel1.Text = "Usu�rio:";
			this.statusBarPanel1.Width = 56;
			// 
			// statusBarPanel2
			// 
			this.statusBarPanel2.AutoSize = System.Windows.Forms.StatusBarPanelAutoSize.Spring;
			this.statusBarPanel2.Width = 472;
			// 
			// toolBar1
			// 
			this.toolBar1.Buttons.AddRange(new System.Windows.Forms.ToolBarButton[] {
						this.tlbClientes,
						this.tlbLivros,
						this.tlbVender,
						this.toolBarButton4,
						this.tlbSobre,
						this.tlbSair});
			this.toolBar1.DropDownArrows = true;
			this.toolBar1.ImageList = this.imageList1;
			this.toolBar1.Location = new System.Drawing.Point(0, 0);
			this.toolBar1.Name = "toolBar1";
			this.toolBar1.ShowToolTips = true;
			this.toolBar1.Size = new System.Drawing.Size(544, 28);
			this.toolBar1.TabIndex = 2;
			this.toolBar1.ButtonClick += new System.Windows.Forms.ToolBarButtonClickEventHandler(this.toolBar1_ButtonClick);
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
			this.imageList1.ImageStream = ((System.Windows.Forms.ImageListStreamer)(resources.GetObject("imageList1.ImageStream")));
			this.imageList1.TransparentColor = System.Drawing.Color.Olive;
			// 
			// frmPrincipal
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(544, 450);
			this.Controls.Add(this.toolBar1);
			this.Controls.Add(this.statusBar1);
			this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
			this.IsMdiContainer = true;
			this.Menu = this.mainMenu1;
			this.Name = "frmPrincipal";
			this.Text = "Livrus Virtus";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmPrincipal_Closing);
			this.Load += new System.EventHandler(this.frmPrincipal_Load);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.frmPrincipal_MouseMove);
			((System.ComponentModel.ISupportInitialize)(this.statusBarPanel1)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.statusBarPanel2)).EndInit();
			this.ResumeLayout(false);
		}
		#endregion

		/// <summary>
		/// The main entry point for the application.
		/// </summary>
		[STAThread]
		static void Main()
		{
			if (frmPrincipal.fPrincipal==null) {
				frmPrincipal.fPrincipal = new frmPrincipal();

				frmPrincipal.fPrincipal.db = new OleDbConnection();
				frmPrincipal.fPrincipal.db.ConnectionString =
				"File Name=C:\\LivrusVirtus\\bancos\\access\\Access2k_Livrus.udl";

				Application.Run(frmPrincipal.fPrincipal);
			} else
			  MessageBox.Show("A Aplica��o j� est� sendo executada.",
			  "Livrus Virtus", MessageBoxButtons.OK);
		}

		private void frmPrincipal_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{

			DialogResult res;
			res = MessageBox.Show(this, "Deseja sair do sistema?",
			frmPrincipal.fPrincipal.Text, MessageBoxButtons.YesNo,
			MessageBoxIcon.Question,MessageBoxDefaultButton.Button2);

			if (res == DialogResult.Yes) {
				db.Close();
				e.Cancel=false;
			 } else
				e.Cancel=true;

		}

		private void toolBar1_ButtonClick(object sender, System.Windows.Forms.ToolBarButtonClickEventArgs e)
		{
		   switch(toolBar1.Buttons.IndexOf(e.Button))
		   {
			  case 0:
				 mnuCadClientes_Click(this,null);
				 break;
			  case 1:
				 mnuCadLivros_Click(this,null);
				 break;
			  case 2:
				 mnuVenderLivros_Click(this,null);
				 break;
			  case 4:
				 mnuSobre_Click(this,null);
				 break;
			  case 5:
				 mnuSair_Click(this,null);
				 break;
			}
		}

		private void frmPrincipal_Load(object sender, System.EventArgs e)
		{
		  db.Open();

		  ConsultasSQL.ConsSQL = new ConsultasSQL();
		  RotinasGlobais.Rotinas = new RotinasGlobais();

		  frmSplash.fSplash = new frmSplash();
		  frmSplash.fSplash.ShowDialog();

		  frmLogin.fLogin = new frmLogin();
		  frmLogin.fLogin.ShowDialog();

		}

		private void mnuSair_Click(object sender, System.EventArgs e)
		{
			Close();
		}

		private void mnuLadoALadoHorizontal_Click(object sender, System.EventArgs e)
		{
			this.LayoutMdi(MdiLayout.TileHorizontal);
		}

		private void mnuLadoALadoVertical_Click(object sender, System.EventArgs e)
		{
			this.LayoutMdi(MdiLayout.TileVertical);
		}
		
		private void mnuEmCascata_Click(object sender, System.EventArgs e)
		{
			this.LayoutMdi(MdiLayout.Cascade);
		}
		
		private void mnuOrganizarIcones_Click(object sender, System.EventArgs e)
		{
			this.LayoutMdi(MdiLayout.ArrangeIcons);
		}

		private void mnuSobre_Click(object sender, System.EventArgs e)
		{
			frmSobre.fSobre = new frmSobre();
			frmSobre.fSobre.ShowDialog();
		}

		private void frmPrincipal_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			fPrincipal.statusBar1.Panels[1].Text=" ";
		}

		private void mnuCadAssuntos_Click(object sender, System.EventArgs e)
		{
			mnuCadAssuntos.Enabled=false;
			frmCadAssuntos.fCadAssuntos = new frmCadAssuntos();
			frmCadAssuntos.fCadAssuntos.MdiParent=this;
			frmCadAssuntos.fCadAssuntos.Show();
		}

		private void mnuAlterarSenha_Click(object sender, System.EventArgs e)
		{
			mnuAlterarSenha.Enabled=false;
			frmAlterarSenha.fAlterarSenha = new frmAlterarSenha();
			frmAlterarSenha.fAlterarSenha.MdiParent=this;
			frmAlterarSenha.fAlterarSenha.Show();
		}

		private void mnuConAssuntos_Click(object sender, System.EventArgs e)
		{
			mnuConAssuntos.Enabled=false;
			frmConAssuntos.fConAssuntos = new frmConAssuntos();
			frmConAssuntos.fConAssuntos.MdiParent=this;
			frmConAssuntos.fConAssuntos.Show();
		}

		private void mnuCadAutores_Click(object sender, System.EventArgs e)
		{
			mnuCadAutores.Enabled=false;
			frmCadAutores.fCadAutores = new frmCadAutores();
			frmCadAutores.fCadAutores.MdiParent=this;
			frmCadAutores.fCadAutores.Show();
		}

		private void mnuConAutores_Click(object sender, System.EventArgs e)
		{
			mnuConAutores.Enabled=false;
			frmConAutores.fConAutores = new frmConAutores();
			frmConAutores.fConAutores.MdiParent=this;
			frmConAutores.fConAutores.Show();
		}

		private void mnuCadEditoras_Click(object sender, System.EventArgs e)
		{
			mnuCadEditoras.Enabled=false;
			frmCadEditoras.fCadEditoras = new frmCadEditoras();
			frmCadEditoras.fCadEditoras.MdiParent=this;
			frmCadEditoras.fCadEditoras.Show();
		}

		private void mnuConEditoras_Click(object sender, System.EventArgs e)
		{
			mnuConEditoras.Enabled=false;
			frmConEditoras.fConEditoras = new frmConEditoras();
			frmConEditoras.fConEditoras.MdiParent=this;
			frmConEditoras.fConEditoras.Show();
		}

		private void mnuCadEnderecos_Click(object sender, System.EventArgs e)
		{
			mnuCadEnderecos.Enabled=false;
			frmCadEnderecos.fCadEnderecos = new frmCadEnderecos();
			frmCadEnderecos.fCadEnderecos.MdiParent=this;
			frmCadEnderecos.fCadEnderecos.Show();
		}

		private void mnuConEnderecos_Click(object sender, System.EventArgs e)
		{
			mnuConEnderecos.Enabled=false;
			frmConEnderecos.fConEnderecos = new frmConEnderecos();
			frmConEnderecos.fConEnderecos.MdiParent=this;
			frmConEnderecos.fConEnderecos.Show();
		}

		private void mnuCadIdiomas_Click(object sender, System.EventArgs e)
		{
			mnuCadIdiomas.Enabled=false;
			frmCadIdiomas.fCadIdiomas = new frmCadIdiomas();
			frmCadIdiomas.fCadIdiomas.MdiParent=this;
			frmCadIdiomas.fCadIdiomas.Show();
		}

		private void mnuConIdiomas_Click(object sender, System.EventArgs e)
		{
			mnuConIdiomas.Enabled=false;
			frmConIdiomas.fConIdiomas = new frmConIdiomas();
			frmConIdiomas.fConIdiomas.MdiParent=this;
			frmConIdiomas.fConIdiomas.Show();
		}

		private void mnuCadPaises_Click(object sender, System.EventArgs e)
		{
			mnuCadPaises.Enabled=false;
			frmCadPaises.fCadPaises = new frmCadPaises();
			frmCadPaises.fCadPaises.MdiParent=this;
			frmCadPaises.fCadPaises.Show();
		}

		private void mnuConPaises_Click(object sender, System.EventArgs e)
		{
			mnuConPaises.Enabled=false;
			frmConPaises.fConPaises = new frmConPaises();
			frmConPaises.fConPaises.MdiParent=this;
			frmConPaises.fConPaises.Show();
		}

		private void mnuCadProfissoes_Click(object sender, System.EventArgs e)
		{
			mnuCadProfissoes.Enabled=false;
			frmCadProfissoes.fCadProfissoes = new frmCadProfissoes();
			frmCadProfissoes.fCadProfissoes.MdiParent=this;
			frmCadProfissoes.fCadProfissoes.Show();
		}

		private void mnuConProfissoes_Click(object sender, System.EventArgs e)
		{
			mnuConProfissoes.Enabled=false;
			frmConProfissoes.fConProfissoes = new frmConProfissoes();
			frmConProfissoes.fConProfissoes.MdiParent=this;
			frmConProfissoes.fConProfissoes.Show();
		}

		private void mnuCadClientes_Click(object sender, System.EventArgs e)
		{
			mnuCadClientes.Enabled=false;
			tlbClientes.Enabled=false;
			frmCadClientes.fCadClientes = new frmCadClientes();
			frmCadClientes.fCadClientes.MdiParent=this;
			frmCadClientes.fCadClientes.Show();
		}

		private void mnuConClientes_Click(object sender, System.EventArgs e)
		{
			mnuConClientes.Enabled=false;
			frmConClientes.fConClientes = new frmConClientes();
			frmConClientes.fConClientes.MdiParent=this;
			frmConClientes.fConClientes.Show();
		}

		private void mnuCadLivros_Click(object sender, System.EventArgs e)
		{
			mnuCadLivros.Enabled=false;
			tlbLivros.Enabled=false;
			frmCadLivros.fCadLivros = new frmCadLivros();
			frmCadLivros.fCadLivros.MdiParent=this;
			frmCadLivros.fCadLivros.Show();
		}

		private void mnuConLivros_Click(object sender, System.EventArgs e)
		{
			mnuConLivros.Enabled=false;
			frmConLivros.fConLivros = new frmConLivros();
			frmConLivros.fConLivros.MdiParent=this;
			frmConLivros.fConLivros.Show();
		}

		private void mnuVenderLivros_Click(object sender, System.EventArgs e)
		{
			mnuVenderLivros.Enabled=false;
            		tlbVender.Enabled=false;
			frmVenderLivros.fVenderLivros = new frmVenderLivros();
			frmVenderLivros.fVenderLivros.MdiParent=this;
			frmVenderLivros.fVenderLivros.Show();
		}

		private void mnuVendasRealizadas_Click(object sender, System.EventArgs e)
		{
			mnuVendasRealizadas.Enabled=false;
			frmConVendas.fConVendas = new frmConVendas();
			frmConVendas.fConVendas.MdiParent=this;
			frmConVendas.fConVendas.Show();
		}

	}
}
