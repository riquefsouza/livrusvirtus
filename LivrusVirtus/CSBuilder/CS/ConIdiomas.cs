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
	public class frmConIdiomas : Livrus.frmConsultas
	{
		public static frmConIdiomas fConIdiomas;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public frmConIdiomas()
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
			this.labDescricao.Text = "Idioma:";
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
			// frmConIdiomas
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(360, 237);
			this.Name = "frmConIdiomas";
			this.Text = "Consulta de Idiomas";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmConIdiomas_Closing);
			this.Load += new System.EventHandler(this.frmConIdiomas_Load);
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).EndInit();
		}
		#endregion

		private void frmConIdiomas_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			frmPrincipal.fPrincipal.mnuConIdiomas.Enabled=true;
		}

		private void btnLimpar_Click(object sender, System.EventArgs e)
		{
			LimparDados(ConsultasSQL.ConsSQL.Idioma('S',"0",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.
			Idioma('S',"", edtDescricao.Text), "Idioma não encontrado!");
		}

		private void frmConIdiomas_Load(object sender, System.EventArgs e)
		{
			   btnLimpar_Click(this, null);
		}
	}
}
