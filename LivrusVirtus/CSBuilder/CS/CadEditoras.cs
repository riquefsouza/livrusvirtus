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
	public class frmCadEditoras : Livrus.frmCadastros
	{
		public static frmCadEditoras fCadEditoras;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;

		public frmCadEditoras()
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
			// 
			// labCodigo
			// 
			this.labCodigo.Name = "labCodigo";
			// 
			// edtCodigo
			// 
			this.edtCodigo.Name = "edtCodigo";
			// 
			// labDescricao
			// 
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Text = "Editora:";
			// 
			// edtDescricao
			// 
			this.edtDescricao.Name = "edtDescricao";
			// 
			// btnNovo
			// 
			this.btnNovo.Name = "btnNovo";
			this.btnNovo.Click += new System.EventHandler(this.btnNovo_Click);
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			// 
			// btnAnterior
			// 
			this.btnAnterior.Name = "btnAnterior";
			// 
			// btnProximo
			// 
			this.btnProximo.Name = "btnProximo";
			// 
			// btnFechar
			// 
			this.btnFechar.Name = "btnFechar";
			// 
			// btnLimpar
			// 
			this.btnLimpar.Name = "btnLimpar";
			// 
			// btnExcluir
			// 
			this.btnExcluir.Name = "btnExcluir";
			this.btnExcluir.Click += new System.EventHandler(this.btnExcluir_Click);
			// 
			// btnSalvar
			// 
			this.btnSalvar.Name = "btnSalvar";
			this.btnSalvar.Click += new System.EventHandler(this.btnSalvar_Click);
			// 
			// frmCadEditoras
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(336, 133);
			this.Name = "frmCadEditoras";
			this.Text = "Cadastro de Editoras";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmCadEditoras_Closing);
		}
		#endregion

		protected override bool ValidaDados(bool bTodosDados)
		{
			if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text,
				"Código não informado!"))
			  return false;
			if (bTodosDados) {
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text,
				"Editora não informada!"))
				return false;
			}
			return true;
		}

		private void btnNovo_Click(object sender, System.EventArgs e)
		{
			NovoDado(ConsultasSQL.ConsSQL.Editora('N',edtCodigo.Text,""));
		}

		private void btnExcluir_Click(object sender, System.EventArgs e)
		{
			ExcluirDados(ConsultasSQL.ConsSQL.Editora('D',edtCodigo.Text,""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.Editora('S',edtCodigo.Text,""),
			"Editora não encontrada!");
		}

		private void btnSalvar_Click(object sender, System.EventArgs e)
		{
			SalvarDados(ConsultasSQL.ConsSQL.Editora('S',edtCodigo.Text,""),
			ConsultasSQL.ConsSQL.Editora('U',edtCodigo.Text,edtDescricao.Text),
			ConsultasSQL.ConsSQL.Editora('I',edtCodigo.Text,edtDescricao.Text),
			true);
		}

		private void frmCadEditoras_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			  frmPrincipal.fPrincipal.mnuCadEditoras.Enabled=true;
		}
	}
}
