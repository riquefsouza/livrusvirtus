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
	public class frmConPaises : Livrus.frmConsultas
	{
		public static frmConPaises fConPaises;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public frmConPaises()
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
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).BeginInit();
			// 
			// panel1
			// 
			this.panel1.Name = "panel1";
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			// 
			// edtDescricao
			// 
			this.edtDescricao.Name = "edtDescricao";
			// 
			// labDescricao
			// 
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Text = "Pa�s:";
			// 
			// gridConsulta
			// 
			this.gridConsulta.Name = "gridConsulta";
			// 
			// panel2
			// 
			this.panel2.Name = "panel2";
			// 
			// btnLimpar
			// 
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.Click += new System.EventHandler(this.btnLimpar_Click);
			// 
			// btnFechar
			// 
			this.btnFechar.Name = "btnFechar";
			// 
			// labRegistros
			// 
			this.labRegistros.Name = "labRegistros";
			// 
			// dsConsulta
			// 
			this.dsConsulta.DataSetName = "Consulta";
			this.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR");
			// 
			// frmConPaises
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(360, 237);
			this.Name = "frmConPaises";
			this.Text = "Consulta de Pa�ses";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmConPaises_Closing);
			this.Load += new System.EventHandler(this.frmConPaises_Load);
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).EndInit();
		}
		#endregion

		private void frmConPaises_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			frmPrincipal.fPrincipal.mnuConPaises.Enabled=true;
		}

		private void btnLimpar_Click(object sender, System.EventArgs e)
		{
			LimparDados(ConsultasSQL.ConsSQL.Pais('S',"0",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.
			Pais('S',"", edtDescricao.Text), "Pa�s n�o encontrado!");
		}

		private void frmConPaises_Load(object sender, System.EventArgs e)
		{
			   btnLimpar_Click(this, null);
		}
	}
}
