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
	public class frmConAssuntos : Livrus.frmConsultas
	{
		public static frmConAssuntos fConAssuntos;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.DataGridTableStyle dataGridTableStyle1;
		private System.Windows.Forms.DataGridTextBoxColumn dataGridTextBoxColumn1;
		private System.Windows.Forms.DataGridTextBoxColumn dataGridTextBoxColumn2;

		public frmConAssuntos()
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
			this.dataGridTableStyle1 = new System.Windows.Forms.DataGridTableStyle();
			this.dataGridTextBoxColumn1 = new System.Windows.Forms.DataGridTextBoxColumn();
			this.dataGridTextBoxColumn2 = new System.Windows.Forms.DataGridTextBoxColumn();
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).BeginInit();
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			// 
			// labDescricao
			// 
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Text = "Assunto:";
			//
			// edtDescricao
			// 
			this.edtDescricao.Name = "edtDescricao";
			// 
			// gridConsulta
			// 
			this.gridConsulta.Name = "gridConsulta";
			this.gridConsulta.TableStyles.AddRange(new System.Windows.Forms.DataGridTableStyle[] {
						this.dataGridTableStyle1});
			// 
			// btnLimpar
			// 
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.Click += new System.EventHandler(this.btnLimpar_Click);
			// 
			// dsConsulta
			// 
			this.dsConsulta.DataSetName = "Consulta";
			this.dsConsulta.Locale = new System.Globalization.CultureInfo("pt-BR");
			// 
			// dataGridTableStyle1
			// 
			this.dataGridTableStyle1.DataGrid = this.gridConsulta;
			this.dataGridTableStyle1.GridColumnStyles.AddRange(new System.Windows.Forms.DataGridColumnStyle[] {
						this.dataGridTextBoxColumn1,
						this.dataGridTextBoxColumn2});
			this.dataGridTableStyle1.HeaderForeColor = System.Drawing.SystemColors.ControlText;
			this.dataGridTableStyle1.MappingName = "";
			this.dataGridTableStyle1.ReadOnly = true;
			// 
			// dataGridTextBoxColumn1
			// 
			this.dataGridTextBoxColumn1.Format = "";
			this.dataGridTextBoxColumn1.FormatInfo = null;
			this.dataGridTextBoxColumn1.HeaderText = "Código";
			this.dataGridTextBoxColumn1.MappingName = "";
			this.dataGridTextBoxColumn1.Width = 75;
			// 
			// dataGridTextBoxColumn2
			// 
			this.dataGridTextBoxColumn2.Format = "";
			this.dataGridTextBoxColumn2.FormatInfo = null;
			this.dataGridTextBoxColumn2.HeaderText = "Assunto";
			this.dataGridTextBoxColumn2.MappingName = "";
			this.dataGridTextBoxColumn2.Width = 75;
			// 
			// frmConAssuntos
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(360, 237);
			this.Name = "frmConAssuntos";
			this.Text = "Consulta de Assuntos";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmConAssuntos_Closing);
			this.Load += new System.EventHandler(this.frmConAssuntos_Load);
			((System.ComponentModel.ISupportInitialize)(this.gridConsulta)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.dsConsulta)).EndInit();
		}
		#endregion

		private void frmConAssuntos_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			frmPrincipal.fPrincipal.mnuConAssuntos.Enabled=true;
		}

		private void btnLimpar_Click(object sender, System.EventArgs e)
		{
			LimparDados(ConsultasSQL.ConsSQL.Assunto('S',"0",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.
			Assunto('S',"", edtDescricao.Text),	"Assunto não encontrado!");
		}

		private void frmConAssuntos_Load(object sender, System.EventArgs e)
		{
	           btnLimpar_Click(this, null);
		}
	}
}
