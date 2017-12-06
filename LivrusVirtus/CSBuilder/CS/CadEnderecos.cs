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
	public class frmCadEnderecos : Livrus.frmCadastros
	{
		public static frmCadEnderecos fCadEnderecos;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Label labBairro;
		private System.Windows.Forms.TextBox edtBairro;
		private System.Windows.Forms.TextBox edtCEP;
		private System.Windows.Forms.Label labCEP;
		private System.Windows.Forms.TextBox edtCidade;
		private System.Windows.Forms.Label labCidade;
		private System.Windows.Forms.Label labEstado;
		private System.Windows.Forms.ComboBox cmbEstado;

		public frmCadEnderecos()
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
			this.labBairro = new System.Windows.Forms.Label();
			this.edtBairro = new System.Windows.Forms.TextBox();
			this.edtCEP = new System.Windows.Forms.TextBox();
			this.labCEP = new System.Windows.Forms.Label();
			this.edtCidade = new System.Windows.Forms.TextBox();
			this.labCidade = new System.Windows.Forms.Label();
			this.labEstado = new System.Windows.Forms.Label();
			this.cmbEstado = new System.Windows.Forms.ComboBox();
			this.SuspendLayout();
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
			this.labDescricao.Text = "Logradouro:";
			// 
			// edtDescricao
			// 
			this.edtDescricao.MaxLength = 40;
			this.edtDescricao.Name = "edtDescricao";
			this.edtDescricao.Size = new System.Drawing.Size(264, 20);
			// 
			// btnNovo
			// 
			this.btnNovo.Name = "btnNovo";
			this.btnNovo.Click += new System.EventHandler(this.btnNovo_Click);
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Location = new System.Drawing.Point(440, 8);
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.TabIndex = 13;
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			// 
			// btnAnterior
			// 
			this.btnAnterior.Location = new System.Drawing.Point(440, 40);
			this.btnAnterior.Name = "btnAnterior";
			this.btnAnterior.TabIndex = 14;
			// 
			// btnProximo
			// 
			this.btnProximo.Location = new System.Drawing.Point(440, 72);
			this.btnProximo.Name = "btnProximo";
			this.btnProximo.TabIndex = 15;
			// 
			// btnFechar
			// 
			this.btnFechar.Location = new System.Drawing.Point(440, 136);
			this.btnFechar.Name = "btnFechar";
			this.btnFechar.TabIndex = 19;
			// 
			// btnLimpar
			// 
			this.btnLimpar.Location = new System.Drawing.Point(360, 136);
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.TabIndex = 18;
			// 
			// btnExcluir
			// 
			this.btnExcluir.Location = new System.Drawing.Point(280, 136);
			this.btnExcluir.Name = "btnExcluir";
			this.btnExcluir.TabIndex = 17;
			this.btnExcluir.Click += new System.EventHandler(this.btnExcluir_Click);
			// 
			// btnSalvar
			// 
			this.btnSalvar.Location = new System.Drawing.Point(200, 136);
			this.btnSalvar.Name = "btnSalvar";
			this.btnSalvar.TabIndex = 16;
			this.btnSalvar.Click += new System.EventHandler(this.btnSalvar_Click);
			// 
			// labBairro
			// 
			this.labBairro.Location = new System.Drawing.Point(280, 48);
			this.labBairro.Name = "labBairro";
			this.labBairro.Size = new System.Drawing.Size(64, 16);
			this.labBairro.TabIndex = 5;
			this.labBairro.Text = "Bairro:";
			// 
			// edtBairro
			// 
			this.edtBairro.Enabled = false;
			this.edtBairro.Location = new System.Drawing.Point(280, 64);
			this.edtBairro.MaxLength = 15;
			this.edtBairro.Name = "edtBairro";
			this.edtBairro.Size = new System.Drawing.Size(152, 20);
			this.edtBairro.TabIndex = 6;
			this.edtBairro.Text = "";
			// 
			// edtCEP
			// 
			this.edtCEP.Enabled = false;
			this.edtCEP.Location = new System.Drawing.Point(8, 104);
			this.edtCEP.MaxLength = 8;
			this.edtCEP.Name = "edtCEP";
			this.edtCEP.Size = new System.Drawing.Size(72, 20);
			this.edtCEP.TabIndex = 8;
			this.edtCEP.Text = "";
			// 
			// labCEP
			// 
			this.labCEP.Location = new System.Drawing.Point(8, 88);
			this.labCEP.Name = "labCEP";
			this.labCEP.Size = new System.Drawing.Size(64, 16);
			this.labCEP.TabIndex = 7;
			this.labCEP.Text = "CEP:";
			// 
			// edtCidade
			// 
			this.edtCidade.Enabled = false;
			this.edtCidade.Location = new System.Drawing.Point(88, 104);
			this.edtCidade.MaxLength = 30;
			this.edtCidade.Name = "edtCidade";
			this.edtCidade.Size = new System.Drawing.Size(184, 20);
			this.edtCidade.TabIndex = 10;
			this.edtCidade.Text = "";
			// 
			// labCidade
			// 
			this.labCidade.Location = new System.Drawing.Point(88, 88);
			this.labCidade.Name = "labCidade";
			this.labCidade.Size = new System.Drawing.Size(64, 16);
			this.labCidade.TabIndex = 9;
			this.labCidade.Text = "Cidade:";
			// 
			// labEstado
			// 
			this.labEstado.Location = new System.Drawing.Point(280, 88);
			this.labEstado.Name = "labEstado";
			this.labEstado.Size = new System.Drawing.Size(64, 16);
			this.labEstado.TabIndex = 11;
			this.labEstado.Text = "Estado:";
			// 
			// cmbEstado
			// 
			this.cmbEstado.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cmbEstado.Enabled = false;
			this.cmbEstado.Location = new System.Drawing.Point(280, 104);
			this.cmbEstado.Name = "cmbEstado";
			this.cmbEstado.Size = new System.Drawing.Size(152, 21);
			this.cmbEstado.TabIndex = 12;
			// 
			// frmCadEnderecos
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(520, 165);
			this.Controls.Add(this.cmbEstado);
			this.Controls.Add(this.labEstado);
			this.Controls.Add(this.edtCidade);
			this.Controls.Add(this.labCidade);
			this.Controls.Add(this.edtCEP);
			this.Controls.Add(this.labCEP);
			this.Controls.Add(this.edtBairro);
			this.Controls.Add(this.labBairro);
			this.Name = "frmCadEnderecos";
			this.Text = "Cadastro de Endereços";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmCadEnderecos_Closing);
			this.Load += new System.EventHandler(this.frmCadEnderecos_Load);
			this.ResumeLayout(false);
		}
		#endregion

		protected override bool ValidaDados(bool bTodosDados)
		{
			if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text,
				"Código não informado!"))
			  return false;
			if (bTodosDados) {
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text,
				"Logradouro não informado!"))
				return false;
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtBairro.Text,
				"Bairro não informado!"))
				return false;
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtCEP.Text,
				"CEP não informado!"))
				return false;
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtCidade.Text,
				"Cidade não informada!"))
				return false;
			}
			return true;
		}

		protected override void InformaLimpaDados(bool bInformar)
		{
			base.InformaLimpaDados(bInformar);

			if (bInformar) {
			  edtBairro.Text=Campos[2].ToString();
			  edtCEP.Text=Campos[3].ToString();
			  edtCidade.Text=Campos[4].ToString();
			  RecuperaEstado(Campos[5].ToString());
			} else {
			  edtBairro.Clear();
			  edtCEP.Clear();
			  edtCidade.Clear();
			  cmbEstado.SelectedIndex=0;
			}
		}

		protected override void HabilitaDados(bool bHabilita)
		{
			base.HabilitaDados(bHabilita);

			edtBairro.Enabled=bHabilita;
			edtCEP.Enabled=bHabilita;
			edtCidade.Enabled=bHabilita;
			cmbEstado.Enabled=bHabilita;
		}

		private void btnNovo_Click(object sender, System.EventArgs e)
		{
			NovoDado(ConsultasSQL.ConsSQL.Endereco('N',edtCodigo.Text,
			"","","","",""));
		}

		private void btnExcluir_Click(object sender, System.EventArgs e)
		{
			ExcluirDados(ConsultasSQL.ConsSQL.Endereco('D',edtCodigo.Text,
			"","","","",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.Endereco('S',edtCodigo.Text,
			"","","","",""),"Endereço não encontrado!");
		}

		private void btnSalvar_Click(object sender, System.EventArgs e)
		{
			SalvarDados(ConsultasSQL.ConsSQL.Endereco('S',edtCodigo.Text,
			"","","","",""),
			ConsultasSQL.ConsSQL.Endereco('U',edtCodigo.Text,edtDescricao.Text,
			edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text),
			ConsultasSQL.ConsSQL.Endereco('I',edtCodigo.Text,edtDescricao.Text,
			edtBairro.Text,edtCEP.Text,edtCidade.Text,cmbEstado.Text),
			true);
		}

		private void frmCadEnderecos_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			  frmPrincipal.fPrincipal.mnuCadEnderecos.Enabled=true;
		}

		private void AdicionaCombo()
		{
			cmbEstado.Items.Add("Pernambuco");
			cmbEstado.Items.Add("Acre");
			cmbEstado.Items.Add("Alagoas");
			cmbEstado.Items.Add("Amapá");
			cmbEstado.Items.Add("Amazonas");
			cmbEstado.Items.Add("Bahia");
			cmbEstado.Items.Add("Brasília");
			cmbEstado.Items.Add("Ceará");
			cmbEstado.Items.Add("Distrito Federal");
			cmbEstado.Items.Add("Espírito Santo");
			cmbEstado.Items.Add("Goiás");
			cmbEstado.Items.Add("Mato Grosso");
			cmbEstado.Items.Add("Mato Grosso do Sul");
			cmbEstado.Items.Add("Minas Gerais");
			cmbEstado.Items.Add("Pará");
			cmbEstado.Items.Add("Paraíba");
			cmbEstado.Items.Add("Paraná");
			cmbEstado.Items.Add("Santa Catarina");
			cmbEstado.Items.Add("Rio Grande do Norte");
			cmbEstado.Items.Add("Rio Grande do Sul");
			cmbEstado.Items.Add("Rio de Janeiro");
			cmbEstado.Items.Add("Rondônia");
			cmbEstado.Items.Add("Roraima");
			cmbEstado.Items.Add("São Paulo");
			cmbEstado.Items.Add("Sergipe");
			cmbEstado.Items.Add("Tocantins");
		}

		private void RecuperaEstado(string sEstado)
		{
		 for (int nCont=0; nCont <= cmbEstado.Items.Count-1; nCont++) {
			if (cmbEstado.Items[nCont].ToString()==sEstado) {
			   cmbEstado.SelectedIndex=nCont;
			   break;
			}
		 }
		}
		
		private void frmCadEnderecos_Load(object sender, System.EventArgs e)
		{
			AdicionaCombo();
			cmbEstado.SelectedIndex=0;
		}

	}
}
