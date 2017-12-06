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
	public class frmCadastros : System.Windows.Forms.Form
	{
		protected ArrayList Registros;
		protected ArrayList Campos;
		protected int nLinhaRegistro;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		protected System.Windows.Forms.Label labCodigo;
		protected System.Windows.Forms.TextBox edtCodigo;
		protected System.Windows.Forms.Label labDescricao;
		protected System.Windows.Forms.TextBox edtDescricao;
		protected System.Windows.Forms.Button btnNovo;
		protected System.Windows.Forms.Button btnPesquisar;
		protected System.Windows.Forms.Button btnAnterior;
		protected System.Windows.Forms.Button btnProximo;
		protected System.Windows.Forms.Button btnFechar;
		protected System.Windows.Forms.Button btnLimpar;
		protected System.Windows.Forms.Button btnExcluir;
		protected System.Windows.Forms.Button btnSalvar;
		protected System.Data.OleDb.OleDbCommand Arquiva;

		public frmCadastros()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
			Registros = new ArrayList();
			nLinhaRegistro = 0;
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
			this.labCodigo = new System.Windows.Forms.Label();
			this.edtCodigo = new System.Windows.Forms.TextBox();
			this.labDescricao = new System.Windows.Forms.Label();
			this.edtDescricao = new System.Windows.Forms.TextBox();
			this.btnNovo = new System.Windows.Forms.Button();
			this.btnPesquisar = new System.Windows.Forms.Button();
			this.btnAnterior = new System.Windows.Forms.Button();
			this.btnProximo = new System.Windows.Forms.Button();
			this.btnFechar = new System.Windows.Forms.Button();
			this.btnLimpar = new System.Windows.Forms.Button();
			this.btnExcluir = new System.Windows.Forms.Button();
			this.btnSalvar = new System.Windows.Forms.Button();
			this.Arquiva = new System.Data.OleDb.OleDbCommand();
			this.SuspendLayout();
			// 
			// labCodigo
			// 
			this.labCodigo.Location = new System.Drawing.Point(8, 8);
			this.labCodigo.Name = "labCodigo";
			this.labCodigo.Size = new System.Drawing.Size(56, 16);
			this.labCodigo.TabIndex = 0;
			this.labCodigo.Text = "Código:";
			// 
			// edtCodigo
			// 
			this.edtCodigo.Location = new System.Drawing.Point(8, 24);
			this.edtCodigo.MaxLength = 10;
			this.edtCodigo.Name = "edtCodigo";
			this.edtCodigo.Size = new System.Drawing.Size(128, 20);
			this.edtCodigo.TabIndex = 1;
			this.edtCodigo.Text = "";
			this.edtCodigo.Leave += new System.EventHandler(this.edtCodigo_Leave);
			// 
			// labDescricao
			// 
			this.labDescricao.Location = new System.Drawing.Point(8, 48);
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Size = new System.Drawing.Size(64, 16);
			this.labDescricao.TabIndex = 3;
			this.labDescricao.Text = "Descrição:";
			// 
			// edtDescricao
			// 
			this.edtDescricao.Enabled = false;
			this.edtDescricao.Location = new System.Drawing.Point(8, 64);
			this.edtDescricao.MaxLength = 30;
			this.edtDescricao.Name = "edtDescricao";
			this.edtDescricao.Size = new System.Drawing.Size(232, 20);
			this.edtDescricao.TabIndex = 4;
			this.edtDescricao.Text = "";
			// 
			// btnNovo
			// 
			this.btnNovo.Location = new System.Drawing.Point(152, 24);
			this.btnNovo.Name = "btnNovo";
			this.btnNovo.TabIndex = 2;
			this.btnNovo.Text = "&Novo";
			this.btnNovo.Click += new System.EventHandler(this.btnNovo_Click);
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Location = new System.Drawing.Point(256, 8);
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.TabIndex = 5;
			this.btnPesquisar.Text = "&Pesquisar";
			// 
			// btnAnterior
			// 
			this.btnAnterior.Enabled = false;
			this.btnAnterior.Location = new System.Drawing.Point(256, 40);
			this.btnAnterior.Name = "btnAnterior";
			this.btnAnterior.TabIndex = 6;
			this.btnAnterior.Text = "&Anterior";
			this.btnAnterior.Click += new System.EventHandler(this.btnAnterior_Click);
			// 
			// btnProximo
			// 
			this.btnProximo.Enabled = false;
			this.btnProximo.Location = new System.Drawing.Point(256, 72);
			this.btnProximo.Name = "btnProximo";
			this.btnProximo.TabIndex = 7;
			this.btnProximo.Text = "Próxi&mo";
			this.btnProximo.Click += new System.EventHandler(this.btnProximo_Click);
			// 
			// btnFechar
			// 
			this.btnFechar.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btnFechar.Location = new System.Drawing.Point(256, 104);
			this.btnFechar.Name = "btnFechar";
			this.btnFechar.TabIndex = 11;
			this.btnFechar.Text = "&Fechar";
			this.btnFechar.Click += new System.EventHandler(this.btnFechar_Click);
			// 
			// btnLimpar
			// 
			this.btnLimpar.Location = new System.Drawing.Point(176, 104);
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.TabIndex = 10;
			this.btnLimpar.Text = "&Limpar";
			this.btnLimpar.Click += new System.EventHandler(this.btnLimpar_Click);
			// 
			// btnExcluir
			// 
			this.btnExcluir.Enabled = false;
			this.btnExcluir.Location = new System.Drawing.Point(96, 104);
			this.btnExcluir.Name = "btnExcluir";
			this.btnExcluir.TabIndex = 9;
			this.btnExcluir.Text = "&Excluir";
			// 
			// btnSalvar
			// 
			this.btnSalvar.Enabled = false;
			this.btnSalvar.Location = new System.Drawing.Point(16, 104);
			this.btnSalvar.Name = "btnSalvar";
			this.btnSalvar.TabIndex = 8;
			this.btnSalvar.Text = "&Salvar";
			// 
			// frmCadastros
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.CancelButton = this.btnFechar;
			this.ClientSize = new System.Drawing.Size(336, 133);
			this.Controls.Add(this.btnSalvar);
			this.Controls.Add(this.btnExcluir);
			this.Controls.Add(this.btnLimpar);
			this.Controls.Add(this.btnFechar);
			this.Controls.Add(this.btnProximo);
			this.Controls.Add(this.btnAnterior);
			this.Controls.Add(this.btnPesquisar);
			this.Controls.Add(this.btnNovo);
			this.Controls.Add(this.edtDescricao);
			this.Controls.Add(this.edtCodigo);
			this.Controls.Add(this.labDescricao);
			this.Controls.Add(this.labCodigo);
			this.Name = "frmCadastros";
			this.Text = "Cadastro de";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmCadastros_Closing);
			this.MouseMove += new System.Windows.Forms.MouseEventHandler(this.frmCadastros_MouseMove);
			this.ResumeLayout(false);
		}
		#endregion

		private void btnFechar_Click(object sender, System.EventArgs e)
		{
			Close();
		}

		protected virtual bool ValidaDados(bool bTodosDados)
		{
			return true;
		}

		protected virtual void InformaLimpaDados(bool bInformar)
		{
			if (bInformar) {
			  Campos = (ArrayList)Registros[nLinhaRegistro];
			  edtCodigo.Text=Campos[0].ToString();
			  edtDescricao.Text=Campos[1].ToString();
			} else {
			  edtCodigo.Text="";
			  edtDescricao.Text="";
			  edtCodigo.Enabled=true;
			  edtCodigo.Focus();
			}
		}

		protected virtual void HabilitaDados(bool bHabilita)
		{
			edtDescricao.Enabled=bHabilita;
		}

		private void btnNovo_Click(object sender, System.EventArgs e)
		{
			btnSalvar.Enabled=true;
			btnExcluir.Enabled=false;
			btnPesquisar.Enabled=false;
			btnAnterior.Enabled=false;
			btnProximo.Enabled=false;
			btnNovo.Enabled=false;

			InformaLimpaDados(false);
			HabilitaDados(true);
		}

		protected void NovoDado(string sTextoSql)
		{
			 if (RotinasGlobais.Rotinas.ConsultaDados(Registros, sTextoSql)) {
				Campos = (ArrayList)Registros[0];
				edtCodigo.Text = Campos[0].ToString();
				edtCodigo.Enabled = false;
				edtDescricao.Focus();
			 }
		}

		protected void btnLimpar_Click(object sender, System.EventArgs e)
		{
			btnSalvar.Enabled=false;
			btnExcluir.Enabled=false;
			btnPesquisar.Enabled=true;
			btnAnterior.Enabled=false;
			btnProximo.Enabled=false;
			btnNovo.Enabled=true;

			InformaLimpaDados(false);
			HabilitaDados(false);
		}

		protected void ExcluirDados(string sTextoSql)
		{
		   if (ValidaDados(false)) {

			 DialogResult res;
			 res = MessageBox.Show(this, "Certeza de excluir?",
			 frmPrincipal.fPrincipal.Text, MessageBoxButtons.YesNo,
			 MessageBoxIcon.Question, MessageBoxDefaultButton.Button2);

			 if (res == DialogResult.Yes) {
				  Arquiva = frmPrincipal.fPrincipal.db.CreateCommand();
				  Arquiva.CommandText = sTextoSql;
				  Arquiva.ExecuteNonQuery();
				  Arquiva.Dispose();
				  btnLimpar_Click(this,null);
			 }
		   }
		}

		protected void PesquisarDados(string sTextoSql, string sMensagemErro)
		{
			if (edtCodigo.Text=="") {
			  btnAnterior.Enabled=true;
			  btnProximo.Enabled=true;
			}

			if (RotinasGlobais.Rotinas.ConsultaDados(Registros,sTextoSql)) {
			     nLinhaRegistro=0;
				 InformaLimpaDados(true);
				 HabilitaDados(true);

				 btnSalvar.Enabled=true;
				 btnExcluir.Enabled=true;
				 btnPesquisar.Enabled=false;
			} else
			  MessageBox.Show(sMensagemErro, frmPrincipal.fPrincipal.Text,
			  MessageBoxButtons.OK, MessageBoxIcon.Information);

		}

		private void btnAnterior_Click(object sender, System.EventArgs e)
		{
			if (nLinhaRegistro > 0) {
				nLinhaRegistro=nLinhaRegistro - 1;
				InformaLimpaDados(true);
			}
		}

		private void btnProximo_Click(object sender, System.EventArgs e)
		{
			if (nLinhaRegistro < (Registros.Count-1)) {
				nLinhaRegistro=nLinhaRegistro + 1;
				InformaLimpaDados(true);
			}
		}

		protected void SalvarDados(string sTextoSql,string sTextoUpdate,
										string sTextoInsert, bool bLimparDados)
		{
			if (ValidaDados(true)) {
			   Arquiva = frmPrincipal.fPrincipal.db.CreateCommand();
			   if (RotinasGlobais.Rotinas.ConsultaDados(Arquiva,sTextoSql)) {
				 Arquiva.CommandText = sTextoUpdate;
			   } else {
				 Arquiva.CommandText = sTextoInsert;
			   }
			   Arquiva.ExecuteNonQuery();
			   Arquiva.Dispose();
			   if (bLimparDados)
				  btnLimpar_Click(this,null);
			}
		}

		protected virtual void edtCodigo_Leave(object sender, System.EventArgs e)
		{
		  if (edtCodigo.Text!="") {
			if (RotinasGlobais.Rotinas.ValidaInteger(edtCodigo.Text)==false) {
			  edtCodigo.Text="";
			  edtCodigo.Focus();
			}
		  }
		}

		private void frmCadastros_MouseMove(object sender, System.Windows.Forms.MouseEventArgs e)
		{
			frmPrincipal.fPrincipal.statusBar1.Panels[1].Text=Text;
		}
		
		private void frmCadastros_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			frmPrincipal.fPrincipal.statusBar1.Panels[1].Text="";
		}

	}
}
