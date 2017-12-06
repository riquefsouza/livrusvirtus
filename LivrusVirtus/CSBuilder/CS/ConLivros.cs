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
	public class frmConLivros : Livrus.frmConsultas
	{
		public static frmConLivros fConLivros;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public frmConLivros()
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
			this.labDescricao.Text = "Livro:";
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
			// frmConLivros
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(360, 237);
			this.Name = "frmConLivros";
			this.Text = "Consulta de Livros";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmConLivros_Closing);
			this.Load += new System.EventHandler(this.frmConLivros_Load);
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).EndInit();
		}
		#endregion

		private void frmConLivros_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			if (dsConsulta.Tables[0].Rows.Count > 0) {
			  Campos = (ArrayList)Registros[gridConsulta.CurrentCell.RowNumber];
			  RotinasGlobais.Rotinas.sCodigoSelecionado=Campos[0].ToString();
                          RotinasGlobais.Rotinas.sPreco=Campos[2].ToString();
                          RotinasGlobais.Rotinas.sQtdEstoque=Campos[3].ToString();
			}  
			frmPrincipal.fPrincipal.mnuConLivros.Enabled=true;
		}

		private void btnLimpar_Click(object sender, System.EventArgs e)
		{
			LimparDados(ConsultasSQL.ConsSQL.Livro('S',"0",
			"","","","","","","","",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.Livro('S',"", edtDescricao.Text,
			"","","","","","","",""), "Livro não encontrado!");
		}

		private void frmConLivros_Load(object sender, System.EventArgs e)
		{
			   btnLimpar_Click(this, null);
		}
	}
}
