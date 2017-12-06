using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;

namespace Livrus
{
	/// <summary>
	/// Summary description for WinForm.
	/// </summary>
	public class frmConVendas : Livrus.frmConsultas
	{
		public static frmConVendas fConVendas;
		ArrayList ConsTotal, ConsCampo;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Button btnPLivro;
		private System.Windows.Forms.TextBox edtLivro;
		private System.Windows.Forms.TextBox edtISBN;
		private System.Windows.Forms.Label labISBN;
		private System.Windows.Forms.Label labDtHrVenda;
		private System.Windows.Forms.DateTimePicker edtDtVenda;
		private System.Windows.Forms.DateTimePicker edtHrVenda;
		private System.Windows.Forms.Button btnPCliente;
		private System.Windows.Forms.TextBox edtCliente;
		private System.Windows.Forms.Label labCLiente;
		private System.Windows.Forms.Label labLivro;
		private System.Windows.Forms.TextBox edtPrecoTotal;
		private System.Windows.Forms.Label labPrecoTotal;

		public frmConVendas()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
			ConsTotal = new ArrayList();
			ConsCampo = new ArrayList();
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
			this.btnPLivro = new System.Windows.Forms.Button();
			this.edtLivro = new System.Windows.Forms.TextBox();
			this.edtISBN = new System.Windows.Forms.TextBox();
			this.labISBN = new System.Windows.Forms.Label();
			this.labDtHrVenda = new System.Windows.Forms.Label();
			this.edtDtVenda = new System.Windows.Forms.DateTimePicker();
			this.edtHrVenda = new System.Windows.Forms.DateTimePicker();
			this.btnPCliente = new System.Windows.Forms.Button();
			this.edtCliente = new System.Windows.Forms.TextBox();
			this.labCLiente = new System.Windows.Forms.Label();
			this.labLivro = new System.Windows.Forms.Label();
			this.edtPrecoTotal = new System.Windows.Forms.TextBox();
			this.labPrecoTotal = new System.Windows.Forms.Label();
			this.panel1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).BeginInit();
			this.panel2.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).BeginInit();
			this.SuspendLayout();
			//
			// panel1
			// 
			this.panel1.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
						| System.Windows.Forms.AnchorStyles.Right)));
			this.panel1.Controls.Add(this.labLivro);
			this.panel1.Controls.Add(this.btnPCliente);
			this.panel1.Controls.Add(this.edtCliente);
			this.panel1.Controls.Add(this.edtHrVenda);
			this.panel1.Controls.Add(this.labDtHrVenda);
			this.panel1.Controls.Add(this.edtDtVenda);
			this.panel1.Controls.Add(this.btnPLivro);
			this.panel1.Controls.Add(this.edtLivro);
			this.panel1.Controls.Add(this.edtISBN);
			this.panel1.Controls.Add(this.labISBN);
			this.panel1.Controls.Add(this.labCLiente);
			this.panel1.Dock = System.Windows.Forms.DockStyle.None;
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(1128, 136);
			//
			// btnPesquisar
			//
			this.btnPesquisar.Location = new System.Drawing.Point(232, 24);
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.TabIndex = 3;
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			//
			// edtDescricao
			//
			this.edtDescricao.Location = new System.Drawing.Point(8, 64);
			this.edtDescricao.Name = "edtDescricao";
			this.edtDescricao.Size = new System.Drawing.Size(128, 20);
			this.edtDescricao.TabIndex = 5;
			this.edtDescricao.MaxLength = 14;
			this.edtDescricao.Leave += new System.EventHandler(this.edtDescricao_Leave);
			// 
			// labDescricao
			// 
			this.labDescricao.Location = new System.Drawing.Point(8, 48);
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.TabIndex = 4;
			this.labDescricao.Text = "CPF:";
			//
			// gridConsulta
			//
			this.gridConsulta.Location = new System.Drawing.Point(0, 136);
			this.gridConsulta.Name = "gridConsulta";
			this.gridConsulta.Size = new System.Drawing.Size(456, 136);
			//
			// panel2
			//
			this.panel2.Controls.Add(this.edtPrecoTotal);
			this.panel2.Controls.Add(this.labPrecoTotal);
			this.panel2.Location = new System.Drawing.Point(0, 272);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size(464, 72);
			//
			// btnLimpar
			//
			this.btnLimpar.Location = new System.Drawing.Point(296, 40);
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.TabIndex = 3;
			this.btnLimpar.Click += new System.EventHandler(this.btnLimpar_Click);
			//
			// btnFechar
			//
			this.btnFechar.Location = new System.Drawing.Point(376, 40);
			this.btnFechar.Name = "btnFechar";
			this.btnFechar.TabIndex = 4;
			//
			// labRegistros
			//
			this.labRegistros.Location = new System.Drawing.Point(11, 40);
			this.labRegistros.Name = "labRegistros";
			this.labRegistros.TabIndex = 2;
			//
			// dsConsulta
			//
			this.dsConsulta.DataSetName = "Consulta";
			this.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR");
			//
			// btnPLivro
			//
			this.btnPLivro.Location = new System.Drawing.Point(424, 104);
			this.btnPLivro.Name = "btnPLivro";
			this.btnPLivro.Size = new System.Drawing.Size(22, 20);
			this.btnPLivro.TabIndex = 13;
			this.btnPLivro.Text = "...";
			this.btnPLivro.Click += new System.EventHandler(this.btnPLivro_Click);
			//
			// edtLivro
			//
			this.edtLivro.Enabled = false;
			this.edtLivro.Location = new System.Drawing.Point(144, 104);
			this.edtLivro.MaxLength = 30;
			this.edtLivro.Name = "edtLivro";
			this.edtLivro.Size = new System.Drawing.Size(280, 20);
			this.edtLivro.TabIndex = 12;
			this.edtLivro.Text = "";
			//
			// edtISBN
			//
			this.edtISBN.Location = new System.Drawing.Point(8, 104);
			this.edtISBN.MaxLength = 13;
			this.edtISBN.Name = "edtISBN";
			this.edtISBN.Size = new System.Drawing.Size(128, 20);
			this.edtISBN.TabIndex = 10;
			this.edtISBN.Text = "";
			this.edtISBN.Leave += new System.EventHandler(this.edtISBN_Leave);
			// 
			// labISBN
			// 
			this.labISBN.Location = new System.Drawing.Point(8, 88);
			this.labISBN.Name = "labISBN";
			this.labISBN.Size = new System.Drawing.Size(52, 16);
			this.labISBN.TabIndex = 9;
			this.labISBN.Text = "ISBN:";
			// 
			// labDtHrVenda
			// 
			this.labDtHrVenda.Location = new System.Drawing.Point(8, 8);
			this.labDtHrVenda.Name = "labDtHrVenda";
			this.labDtHrVenda.Size = new System.Drawing.Size(96, 16);
			this.labDtHrVenda.TabIndex = 0;
			this.labDtHrVenda.Text = "Data/Hora Venda:";
			//
			// edtDtVenda
			// 
			this.edtDtVenda.Checked = false;
			this.edtDtVenda.Format = System.Windows.Forms.DateTimePickerFormat.Short;
			this.edtDtVenda.Location = new System.Drawing.Point(8, 24);
			this.edtDtVenda.Name = "edtDtVenda";
			this.edtDtVenda.ShowCheckBox = true;
			this.edtDtVenda.Size = new System.Drawing.Size(104, 20);
			this.edtDtVenda.TabIndex = 1;
			// 
			// edtHrVenda
			// 
			this.edtHrVenda.Checked = false;
			this.edtHrVenda.Format = System.Windows.Forms.DateTimePickerFormat.Time;
			this.edtHrVenda.Location = new System.Drawing.Point(120, 24);
			this.edtHrVenda.Name = "edtHrVenda";
			this.edtHrVenda.ShowCheckBox = true;
			this.edtHrVenda.ShowUpDown = true;
			this.edtHrVenda.Size = new System.Drawing.Size(104, 20);
			this.edtHrVenda.TabIndex = 2;
			// 
			// btnPCliente
			//
			this.btnPCliente.Location = new System.Drawing.Point(424, 62);
			this.btnPCliente.Name = "btnPCliente";
			this.btnPCliente.Size = new System.Drawing.Size(22, 20);
			this.btnPCliente.TabIndex = 8;
			this.btnPCliente.Text = "...";
			this.btnPCliente.Click += new System.EventHandler(this.btnPCliente_Click);
			// 
			// edtCliente
			// 
			this.edtCliente.Enabled = false;
			this.edtCliente.Location = new System.Drawing.Point(144, 62);
			this.edtCliente.MaxLength = 30;
			this.edtCliente.Name = "edtCliente";
			this.edtCliente.Size = new System.Drawing.Size(280, 20);
			this.edtCliente.TabIndex = 7;
			this.edtCliente.Text = "";
			// 
			// labCLiente
			// 
			this.labCLiente.Location = new System.Drawing.Point(144, 48);
			this.labCLiente.Name = "labCLiente";
			this.labCLiente.Size = new System.Drawing.Size(52, 16);
			this.labCLiente.TabIndex = 6;
			this.labCLiente.Text = "Cliente:";
			// 
			// labLivro
			// 
			this.labLivro.Location = new System.Drawing.Point(144, 88);
			this.labLivro.Name = "labLivro";
			this.labLivro.Size = new System.Drawing.Size(52, 16);
			this.labLivro.TabIndex = 11;
			this.labLivro.Text = "Livro:";
			//
			// edtPrecoTotal
			// 
			this.edtPrecoTotal.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.edtPrecoTotal.Enabled = false;
			this.edtPrecoTotal.Location = new System.Drawing.Point(320, 8);
			this.edtPrecoTotal.MaxLength = 10;
			this.edtPrecoTotal.Name = "edtPrecoTotal";
			this.edtPrecoTotal.Size = new System.Drawing.Size(128, 20);
			this.edtPrecoTotal.TabIndex = 1;
			this.edtPrecoTotal.Text = "";
			// 
			// labPrecoTotal
			// 
			this.labPrecoTotal.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.labPrecoTotal.Location = new System.Drawing.Point(248, 8);
			this.labPrecoTotal.Name = "labPrecoTotal";
			this.labPrecoTotal.Size = new System.Drawing.Size(64, 16);
			this.labPrecoTotal.TabIndex = 0;
			this.labPrecoTotal.Text = "Preço total:";
			// 
			// frmConVendas
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(456, 341);
			this.Name = "frmConVendas";
			this.Text = "Consulta de Vendas Realizadas";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmConVendas_Closing);
			this.Load += new System.EventHandler(this.frmConVendas_Load);
			this.panel1.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).EndInit();
			this.panel2.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).EndInit();
			this.ResumeLayout(false);
		}
		#endregion

		private void btnLimpar_Click(object sender, System.EventArgs e)
		{
			edtDtVenda.Value=DateTime.Now;
			edtHrVenda.Value=DateTime.Now;
			edtDtVenda.Checked=false;
			edtHrVenda.Checked=false;
			edtCliente.Clear();
			edtISBN.Clear();
			edtLivro.Clear();
			edtPrecoTotal.Text="R$ 0,00";
			edtDtVenda.Focus();

			LimparDados(ConsVenda('L'));

		}

		private string ConsVenda(char sOpcao)  {
		  string sDataVenda, sHoraVenda, sDtHrVenda;

		  if (edtDtVenda.Checked)
			sDataVenda=edtDtVenda.Value.ToString("dd/MM/yyyy");
		  else
			 sDataVenda="";
		  if (edtHrVenda.Checked)
			sHoraVenda=edtHrVenda.Value.ToString("hh:mm:ss");
		  else
			 sHoraVenda="";
		  sDtHrVenda=sDataVenda.Trim()+" "+sHoraVenda.Trim();
		  if (sOpcao=='L')
		   return ConsultasSQL.ConsSQL.Venda('S',"ZERO","","","","");
		  else
		   return ConsultasSQL.ConsSQL.Venda(sOpcao,edtISBN.Text,
		   edtDescricao.Text, sDtHrVenda.Trim(),"","");
		  
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
		  ArrayList linhas = new ArrayList();
		  if (PesquisarDados(ConsVenda('S'),"Venda não encontrada!")) {
			 RotinasGlobais.Rotinas.ConsultaDados(ConsTotal,ConsVenda('P'));
			 if (ConsTotal.Count > 0) {
				linhas = (ArrayList) ConsTotal[0];
				edtPrecoTotal.Text="R$ "+linhas[0].ToString();
			 }
			}

		}

		private void frmConVendas_Load(object sender, System.EventArgs e)
		{
		  btnLimpar_Click(this,null);
		}

		private void edtDescricao_Leave(object sender, System.EventArgs e)
		{
			if (edtDescricao.Text.Equals("")==false) {
			  if (RotinasGlobais.Rotinas.ValidaCPF(edtDescricao.Text)) {

				  edtCliente.Text =
				  RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
				  ConsultasSQL.ConsSQL.Cliente('S',edtDescricao.Text,
				  "","","","","","","","",""),"Cliente não encontrado!");
				  if (edtCliente.Text.Equals("")) {
					edtDescricao.Clear();
					edtDescricao.Focus();
				  }
			  } else {
				  MessageBox.Show(this,"CPF inválido!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  edtDescricao.Clear();
				  edtCliente.Clear();
			  }
			}
		}

		private void edtISBN_Leave(object sender, System.EventArgs e)
		{
			if (edtISBN.Text.Equals("")==false) {
			  if (RotinasGlobais.Rotinas.ValidaISBN(edtISBN.Text)) {
				  edtLivro.Text=
				  RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
				  ConsultasSQL.ConsSQL.Livro('Q',edtISBN.Text,
				  "","","","","","","","",""),"Livro não encontrado!");
				  if (edtLivro.Text.Equals("")==false) {
				   if (Int32.Parse(ConsCampo[3].ToString()) > 0) {
					 RotinasGlobais.Rotinas.sPreco=ConsCampo[2].ToString();
				   } else
					  MessageBox.Show(this,"Livro não existe no estoque!",
					  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
					  MessageBoxIcon.Error);
				  } else {
					edtISBN.Clear();
					edtISBN.Focus();
				  }
			  } else {
				  MessageBox.Show(this,"ISBN inválido!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  edtISBN.Clear();
				  edtLivro.Clear();
			  }
			}
		}

		private void btnPCliente_Click(object sender, System.EventArgs e)
		{
			frmConClientes pfConClientes = new frmConClientes();
			pfConClientes.ShowDialog();
			edtDescricao.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtDescricao_Leave(this,null);
		}

		private void btnPLivro_Click(object sender, System.EventArgs e)
		{
			frmConLivros pfConLivros = new frmConLivros();
			pfConLivros.ShowDialog();
			edtISBN.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtISBN_Leave(this,null);
		}
		
		private void frmConVendas_Closing(object sender,
										System.ComponentModel.CancelEventArgs e)
		{
		   frmPrincipal.fPrincipal.mnuVendasRealizadas.Enabled=true;
		}
	}
}
