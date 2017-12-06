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
	public class frmConsultas : System.Windows.Forms.Form
	{
		protected ArrayList Registros, Campos;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		protected System.Windows.Forms.Panel panel1;
		protected System.Windows.Forms.Button btnPesquisar;
		protected System.Windows.Forms.TextBox edtDescricao;
		protected System.Windows.Forms.Label labDescricao;
		protected System.Windows.Forms.DataGrid gridConsulta;
		protected System.Windows.Forms.Panel panel2;
		protected System.Windows.Forms.Button btnLimpar;
		protected System.Windows.Forms.Button btnFechar;
		protected System.Windows.Forms.Label labRegistros;
		protected System.Data.DataSet dsConsulta;

		public frmConsultas()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
			Registros = new ArrayList();
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
			this.panel1 = new System.Windows.Forms.Panel();
			this.btnPesquisar = new System.Windows.Forms.Button();
			this.edtDescricao = new System.Windows.Forms.TextBox();
			this.labDescricao = new System.Windows.Forms.Label();
			this.gridConsulta = new System.Windows.Forms.DataGrid();
			this.dsConsulta = new System.Data.DataSet();
			this.panel2 = new System.Windows.Forms.Panel();
			this.labRegistros = new System.Windows.Forms.Label();
			this.btnLimpar = new System.Windows.Forms.Button();
			this.btnFechar = new System.Windows.Forms.Button();
			this.panel1.SuspendLayout();
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).BeginInit();
			this.panel2.SuspendLayout();
			this.SuspendLayout();
			// 
			// panel1
			// 
			this.panel1.Controls.Add(this.btnPesquisar);
			this.panel1.Controls.Add(this.edtDescricao);
			this.panel1.Controls.Add(this.labDescricao);
			this.panel1.Dock = System.Windows.Forms.DockStyle.Top;
			this.panel1.Location = new System.Drawing.Point(0, 0);
			this.panel1.Name = "panel1";
			this.panel1.Size = new System.Drawing.Size(360, 56);
			this.panel1.TabIndex = 0;
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Location = new System.Drawing.Point(280, 24);
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.TabIndex = 2;
			this.btnPesquisar.Text = "&Pesquisar";
			// 
			// edtDescricao
			// 
			this.edtDescricao.Location = new System.Drawing.Point(8, 24);
			this.edtDescricao.Name = "edtDescricao";
			this.edtDescricao.Size = new System.Drawing.Size(264, 20);
			this.edtDescricao.TabIndex = 1;
			this.edtDescricao.Text = "";
			// 
			// labDescricao
			// 
			this.labDescricao.Location = new System.Drawing.Point(8, 8);
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Size = new System.Drawing.Size(64, 16);
			this.labDescricao.TabIndex = 0;
			this.labDescricao.Text = "Descrição:";
			// 
			// gridConsulta
			// 
			this.gridConsulta.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
						| System.Windows.Forms.AnchorStyles.Left) 
						| System.Windows.Forms.AnchorStyles.Right)));
			this.gridConsulta.CaptionVisible = false;
			this.gridConsulta.DataMember = "";
			this.gridConsulta.DataSource = this.dsConsulta;
			this.gridConsulta.HeaderForeColor = System.Drawing.SystemColors.ControlText;
			this.gridConsulta.Location = new System.Drawing.Point(0, 56);
			this.gridConsulta.Name = "gridConsulta";
			this.gridConsulta.ParentRowsVisible = false;
			this.gridConsulta.ReadOnly = true;
			this.gridConsulta.Size = new System.Drawing.Size(360, 144);
			this.gridConsulta.TabIndex = 1;
			this.gridConsulta.CurrentCellChanged += new System.EventHandler(this.gridConsulta_CurrentCellChanged);
			this.gridConsulta.MouseMove += new System.Windows.Forms.MouseEventHandler(this.gridConsulta_MouseMove);
			// 
			// dsConsulta
			// 
			this.dsConsulta.DataSetName = "Consulta";
			this.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR");
			// 
			// panel2
			// 
			this.panel2.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left) 
						| System.Windows.Forms.AnchorStyles.Right)));
			this.panel2.Controls.Add(this.labRegistros);
			this.panel2.Controls.Add(this.btnLimpar);
			this.panel2.Controls.Add(this.btnFechar);
			this.panel2.Location = new System.Drawing.Point(0, 200);
			this.panel2.Name = "panel2";
			this.panel2.Size = new System.Drawing.Size(360, 40);
			this.panel2.TabIndex = 2;
			// 
			// labRegistros
			// 
			this.labRegistros.Location = new System.Drawing.Point(11, 12);
			this.labRegistros.Name = "labRegistros";
			this.labRegistros.Size = new System.Drawing.Size(136, 16);
			this.labRegistros.TabIndex = 0;
			this.labRegistros.Text = "Registro 0 de 0";
			// 
			// btnLimpar
			// 
			this.btnLimpar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.btnLimpar.Location = new System.Drawing.Point(200, 8);
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.TabIndex = 1;
			this.btnLimpar.Text = "&Limpar";
			// 
			// btnFechar
			// 
			this.btnFechar.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
			this.btnFechar.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btnFechar.Location = new System.Drawing.Point(280, 8);
			this.btnFechar.Name = "btnFechar";
			this.btnFechar.TabIndex = 2;
			this.btnFechar.Text = "&Fechar";
			this.btnFechar.Click += new System.EventHandler(this.btnFechar_Click);
			// 
			// frmConsultas
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(360, 237);
			this.Controls.Add(this.panel2);
			this.Controls.Add(this.gridConsulta);
			this.Controls.Add(this.panel1);
			this.Name = "frmConsultas";
			this.Text = "Consulta de";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmConsultas_Closing);
			this.panel1.ResumeLayout(false);
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).EndInit();
			this.panel2.ResumeLayout(false);
			this.ResumeLayout(false);
		}
		#endregion

		private void btnFechar_Click(object sender, System.EventArgs e)
		{
			Close();
		}

		private void frmConsultas_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			if (dsConsulta.Tables[0].Rows.Count > 0) {
			  Campos = (ArrayList)Registros[gridConsulta.CurrentCell.RowNumber];
			  RotinasGlobais.Rotinas.sCodigoSelecionado=Campos[0].ToString();
			}  
			frmPrincipal.fPrincipal.statusBar1.Panels[1].Text="";
		}

		protected void LimparDados(string sTextoSql)
		{
		 labRegistros.Text="Registro 0 de 0";
		 RotinasGlobais.Rotinas.ConsultaDados(dsConsulta, Registros, sTextoSql);
		 btnPesquisar.Enabled=true;
		 edtDescricao.Text="";
	     edtDescricao.Focus();

		}

		protected bool PesquisarDados(string sTextoSql, string sMensagemErro)
		{
		  if (RotinasGlobais.Rotinas.
					ConsultaDados(dsConsulta, Registros, sTextoSql)) {
			 gridConsulta.SetDataBinding(dsConsulta,"Consulta");
			 gridConsulta_CurrentCellChanged(this,null);
			 btnPesquisar.Enabled=false;
			 return true;
		  } else {
			 MessageBox.Show(sMensagemErro, frmPrincipal.fPrincipal.Text,
			 MessageBoxButtons.OK, MessageBoxIcon.Error);
			 return false;
		  }
		}

		private void gridConsulta_CurrentCellChanged(object sender, System.EventArgs e)
		{
			labRegistros.Text="Registro "+
			(gridConsulta.CurrentCell.RowNumber+1)+
			" de "+dsConsulta.Tables["Consulta"].Rows.Count.ToString();
		}

		private void gridConsulta_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			frmPrincipal.fPrincipal.statusBar1.Panels[1].Text=Text;
		}


	}
}
