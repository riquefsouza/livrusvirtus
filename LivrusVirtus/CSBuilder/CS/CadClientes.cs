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
	public class frmCadClientes : Livrus.frmCadastros
	{
		public static frmCadClientes fCadClientes;
		private ArrayList ConsCampo;
		private string sSexo;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Label labEmail;
		private System.Windows.Forms.TextBox edtEmail;
		private System.Windows.Forms.TextBox edtIdentidade;
		private System.Windows.Forms.Label labIdentidade;
		private System.Windows.Forms.GroupBox rdgSexo;
		private System.Windows.Forms.RadioButton rbMasculino;
		private System.Windows.Forms.RadioButton rbFeminino;
		private System.Windows.Forms.TextBox edtTelefone;
		private System.Windows.Forms.Label labTelefone;
		private System.Windows.Forms.DateTimePicker edtDtNascimento;
		private System.Windows.Forms.Label labDtNascimento;
		private System.Windows.Forms.GroupBox grpEndereco;
		private System.Windows.Forms.TextBox edtCodEndereco;
		private System.Windows.Forms.Button btnPEndereco;
		private System.Windows.Forms.TextBox edtBairro;
		private System.Windows.Forms.Label labBairro;
		private System.Windows.Forms.TextBox edtLogradouro;
		private System.Windows.Forms.Label labLogradouro;
		private System.Windows.Forms.Label labEstado;
		private System.Windows.Forms.TextBox edtCidade;
		private System.Windows.Forms.Label labCidade;
		private System.Windows.Forms.TextBox edtCEP;
		private System.Windows.Forms.Label labCEP;
		private System.Windows.Forms.TextBox edtEstado;
		private System.Windows.Forms.TextBox edtPais;
		private System.Windows.Forms.TextBox edtCodPais;
		private System.Windows.Forms.Label labPais;
		private System.Windows.Forms.Button btnPPais;
		private System.Windows.Forms.Button btnPProfissao;
		private System.Windows.Forms.TextBox edtProfissao;
		private System.Windows.Forms.TextBox edtCodProfissao;
		private System.Windows.Forms.Label labProfissao;

		public frmCadClientes()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
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
			this.labEmail = new System.Windows.Forms.Label();
			this.edtEmail = new System.Windows.Forms.TextBox();
			this.edtIdentidade = new System.Windows.Forms.TextBox();
			this.labIdentidade = new System.Windows.Forms.Label();
			this.rdgSexo = new System.Windows.Forms.GroupBox();
			this.rbFeminino = new System.Windows.Forms.RadioButton();
			this.rbMasculino = new System.Windows.Forms.RadioButton();
			this.edtTelefone = new System.Windows.Forms.TextBox();
			this.labTelefone = new System.Windows.Forms.Label();
			this.edtDtNascimento = new System.Windows.Forms.DateTimePicker();
			this.labDtNascimento = new System.Windows.Forms.Label();
			this.grpEndereco = new System.Windows.Forms.GroupBox();
			this.edtEstado = new System.Windows.Forms.TextBox();
			this.labEstado = new System.Windows.Forms.Label();
			this.edtCidade = new System.Windows.Forms.TextBox();
			this.labCidade = new System.Windows.Forms.Label();
			this.edtCEP = new System.Windows.Forms.TextBox();
			this.labCEP = new System.Windows.Forms.Label();
			this.edtBairro = new System.Windows.Forms.TextBox();
			this.labBairro = new System.Windows.Forms.Label();
			this.edtLogradouro = new System.Windows.Forms.TextBox();
			this.labLogradouro = new System.Windows.Forms.Label();
			this.btnPEndereco = new System.Windows.Forms.Button();
			this.edtCodEndereco = new System.Windows.Forms.TextBox();
			this.edtPais = new System.Windows.Forms.TextBox();
			this.edtCodPais = new System.Windows.Forms.TextBox();
			this.labPais = new System.Windows.Forms.Label();
			this.btnPPais = new System.Windows.Forms.Button();
			this.btnPProfissao = new System.Windows.Forms.Button();
			this.edtProfissao = new System.Windows.Forms.TextBox();
			this.edtCodProfissao = new System.Windows.Forms.TextBox();
			this.labProfissao = new System.Windows.Forms.Label();
			this.rdgSexo.SuspendLayout();
			this.grpEndereco.SuspendLayout();
			this.SuspendLayout();
			// 
			// labCodigo
			// 
			this.labCodigo.Name = "labCodigo";
			this.labCodigo.Text = "CPF:";
			// 
			// edtCodigo
			// 
			this.edtCodigo.MaxLength = 14;
			this.edtCodigo.Name = "edtCodigo";
			this.edtCodigo.Leave += new System.EventHandler(this.edtCodigo_Leave);
			// 
			// labDescricao
			// 
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Text = "Nome:";
			// 
			// edtDescricao
			// 
			this.edtDescricao.Name = "edtDescricao";
			this.edtDescricao.Size = new System.Drawing.Size(320, 20);
			// 
			// btnNovo
			// 
			this.btnNovo.Name = "btnNovo";
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Location = new System.Drawing.Point(440, 8);
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.TabIndex = 23;
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			// 
			// btnAnterior
			// 
			this.btnAnterior.Location = new System.Drawing.Point(440, 40);
			this.btnAnterior.Name = "btnAnterior";
			this.btnAnterior.TabIndex = 24;
			// 
			// btnProximo
			// 
			this.btnProximo.Location = new System.Drawing.Point(440, 72);
			this.btnProximo.Name = "btnProximo";
			this.btnProximo.TabIndex = 25;
			// 
			// btnFechar
			// 
			this.btnFechar.Location = new System.Drawing.Point(440, 424);
			this.btnFechar.Name = "btnFechar";
			this.btnFechar.TabIndex = 29;
			// 
			// btnLimpar
			// 
			this.btnLimpar.Location = new System.Drawing.Point(360, 424);
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.TabIndex = 28;
			// 
			// btnExcluir
			// 
			this.btnExcluir.Location = new System.Drawing.Point(280, 424);
			this.btnExcluir.Name = "btnExcluir";
			this.btnExcluir.TabIndex = 27;
			this.btnExcluir.Click += new System.EventHandler(this.btnExcluir_Click);
			// 
			// btnSalvar
			// 
			this.btnSalvar.Location = new System.Drawing.Point(200, 424);
			this.btnSalvar.Name = "btnSalvar";
			this.btnSalvar.TabIndex = 26;
			this.btnSalvar.Click += new System.EventHandler(this.btnSalvar_Click);
			// 
			// labEmail
			// 
			this.labEmail.Location = new System.Drawing.Point(8, 88);
			this.labEmail.Name = "labEmail";
			this.labEmail.Size = new System.Drawing.Size(100, 16);
			this.labEmail.TabIndex = 5;
			this.labEmail.Text = "E-mail:";
			// 
			// edtEmail
			// 
			this.edtEmail.Enabled = false;
			this.edtEmail.Location = new System.Drawing.Point(8, 104);
			this.edtEmail.MaxLength = 30;
			this.edtEmail.Name = "edtEmail";
			this.edtEmail.Size = new System.Drawing.Size(320, 20);
			this.edtEmail.TabIndex = 6;
			this.edtEmail.Text = "";
			// 
			// edtIdentidade
			// 
			this.edtIdentidade.Enabled = false;
			this.edtIdentidade.Location = new System.Drawing.Point(336, 104);
			this.edtIdentidade.MaxLength = 10;
			this.edtIdentidade.Name = "edtIdentidade";
			this.edtIdentidade.Size = new System.Drawing.Size(92, 20);
			this.edtIdentidade.TabIndex = 8;
			this.edtIdentidade.Text = "";
			// 
			// labIdentidade
			// 
			this.labIdentidade.Location = new System.Drawing.Point(336, 88);
			this.labIdentidade.Name = "labIdentidade";
			this.labIdentidade.Size = new System.Drawing.Size(68, 16);
			this.labIdentidade.TabIndex = 7;
			this.labIdentidade.Text = "Identidade:";
			// 
			// rdgSexo
			// 
			this.rdgSexo.Controls.Add(this.rbFeminino);
			this.rdgSexo.Controls.Add(this.rbMasculino);
			this.rdgSexo.Location = new System.Drawing.Point(8, 128);
			this.rdgSexo.Name = "rdgSexo";
			this.rdgSexo.Size = new System.Drawing.Size(184, 40);
			this.rdgSexo.TabIndex = 9;
			this.rdgSexo.TabStop = false;
			this.rdgSexo.Text = "Sexo";
			// 
			// rbFeminino
			// 
			this.rbFeminino.Location = new System.Drawing.Point(104, 16);
			this.rbFeminino.Name = "rbFeminino";
			this.rbFeminino.Size = new System.Drawing.Size(72, 16);
			this.rbFeminino.TabIndex = 1;
			this.rbFeminino.Text = "Feminino";
			// 
			// rbMasculino
			// 
			this.rbMasculino.Enabled = false;
			this.rbMasculino.Location = new System.Drawing.Point(16, 16);
			this.rbMasculino.Name = "rbMasculino";
			this.rbMasculino.Size = new System.Drawing.Size(80, 16);
			this.rbMasculino.TabIndex = 0;
			this.rbMasculino.Text = "Masculino";
			// 
			// edtTelefone
			// 
			this.edtTelefone.Enabled = false;
			this.edtTelefone.Location = new System.Drawing.Point(200, 144);
			this.edtTelefone.MaxLength = 17;
			this.edtTelefone.Name = "edtTelefone";
			this.edtTelefone.Size = new System.Drawing.Size(128, 20);
			this.edtTelefone.TabIndex = 11;
			this.edtTelefone.Text = "";
			// 
			// labTelefone
			// 
			this.labTelefone.Location = new System.Drawing.Point(200, 128);
			this.labTelefone.Name = "labTelefone";
			this.labTelefone.Size = new System.Drawing.Size(68, 16);
			this.labTelefone.TabIndex = 10;
			this.labTelefone.Text = "Telefone:";
			// 
			// edtDtNascimento
			// 
			this.edtDtNascimento.Enabled = false;
			this.edtDtNascimento.Format = System.Windows.Forms.DateTimePickerFormat.Short;
			this.edtDtNascimento.Location = new System.Drawing.Point(336, 144);
			this.edtDtNascimento.Name = "edtDtNascimento";
			this.edtDtNascimento.Size = new System.Drawing.Size(96, 20);
			this.edtDtNascimento.TabIndex = 13;
			// 
			// labDtNascimento
			// 
			this.labDtNascimento.Location = new System.Drawing.Point(336, 128);
			this.labDtNascimento.Name = "labDtNascimento";
			this.labDtNascimento.Size = new System.Drawing.Size(96, 16);
			this.labDtNascimento.TabIndex = 12;
			this.labDtNascimento.Text = "Dt. Nascimento:";
			// 
			// grpEndereco
			// 
			this.grpEndereco.Controls.Add(this.edtEstado);
			this.grpEndereco.Controls.Add(this.labEstado);
			this.grpEndereco.Controls.Add(this.edtCidade);
			this.grpEndereco.Controls.Add(this.labCidade);
			this.grpEndereco.Controls.Add(this.edtCEP);
			this.grpEndereco.Controls.Add(this.labCEP);
			this.grpEndereco.Controls.Add(this.edtBairro);
			this.grpEndereco.Controls.Add(this.labBairro);
			this.grpEndereco.Controls.Add(this.edtLogradouro);
			this.grpEndereco.Controls.Add(this.labLogradouro);
			this.grpEndereco.Controls.Add(this.btnPEndereco);
			this.grpEndereco.Controls.Add(this.edtCodEndereco);
			this.grpEndereco.Location = new System.Drawing.Point(8, 176);
			this.grpEndereco.Name = "grpEndereco";
			this.grpEndereco.Size = new System.Drawing.Size(424, 152);
			this.grpEndereco.TabIndex = 14;
			this.grpEndereco.TabStop = false;
			this.grpEndereco.Text = "Endere�o";
			// 
			// edtEstado
			// 
			this.edtEstado.Enabled = false;
			this.edtEstado.Location = new System.Drawing.Point(280, 120);
			this.edtEstado.MaxLength = 10;
			this.edtEstado.Name = "edtEstado";
			this.edtEstado.Size = new System.Drawing.Size(128, 20);
			this.edtEstado.TabIndex = 11;
			this.edtEstado.Text = "";
			// 
			// labEstado
			// 
			this.labEstado.Location = new System.Drawing.Point(280, 104);
			this.labEstado.Name = "labEstado";
			this.labEstado.Size = new System.Drawing.Size(64, 16);
			this.labEstado.TabIndex = 10;
			this.labEstado.Text = "Estado:";
			// 
			// edtCidade
			// 
			this.edtCidade.Enabled = false;
			this.edtCidade.Location = new System.Drawing.Point(88, 120);
			this.edtCidade.MaxLength = 30;
			this.edtCidade.Name = "edtCidade";
			this.edtCidade.Size = new System.Drawing.Size(184, 20);
			this.edtCidade.TabIndex = 9;
			this.edtCidade.Text = "";
			// 
			// labCidade
			// 
			this.labCidade.Location = new System.Drawing.Point(88, 104);
			this.labCidade.Name = "labCidade";
			this.labCidade.Size = new System.Drawing.Size(64, 16);
			this.labCidade.TabIndex = 8;
			this.labCidade.Text = "Cidade:";
			// 
			// edtCEP
			// 
			this.edtCEP.Enabled = false;
			this.edtCEP.Location = new System.Drawing.Point(8, 120);
			this.edtCEP.MaxLength = 8;
			this.edtCEP.Name = "edtCEP";
			this.edtCEP.Size = new System.Drawing.Size(72, 20);
			this.edtCEP.TabIndex = 7;
			this.edtCEP.Text = "";
			// 
			// labCEP
			// 
			this.labCEP.Location = new System.Drawing.Point(8, 104);
			this.labCEP.Name = "labCEP";
			this.labCEP.Size = new System.Drawing.Size(64, 16);
			this.labCEP.TabIndex = 6;
			this.labCEP.Text = "CEP:";
			// 
			// edtBairro
			// 
			this.edtBairro.Enabled = false;
			this.edtBairro.Location = new System.Drawing.Point(280, 74);
			this.edtBairro.MaxLength = 10;
			this.edtBairro.Name = "edtBairro";
			this.edtBairro.Size = new System.Drawing.Size(128, 20);
			this.edtBairro.TabIndex = 5;
			this.edtBairro.Text = "";
			// 
			// labBairro
			// 
			this.labBairro.Location = new System.Drawing.Point(280, 58);
			this.labBairro.Name = "labBairro";
			this.labBairro.Size = new System.Drawing.Size(68, 16);
			this.labBairro.TabIndex = 4;
			this.labBairro.Text = "Bairro:";
			// 
			// edtLogradouro
			// 
			this.edtLogradouro.Enabled = false;
			this.edtLogradouro.Location = new System.Drawing.Point(8, 74);
			this.edtLogradouro.MaxLength = 30;
			this.edtLogradouro.Name = "edtLogradouro";
			this.edtLogradouro.Size = new System.Drawing.Size(264, 20);
			this.edtLogradouro.TabIndex = 3;
			this.edtLogradouro.Text = "";
			// 
			// labLogradouro
			// 
			this.labLogradouro.Location = new System.Drawing.Point(8, 58);
			this.labLogradouro.Name = "labLogradouro";
			this.labLogradouro.Size = new System.Drawing.Size(78, 16);
			this.labLogradouro.TabIndex = 2;
			this.labLogradouro.Text = "Logradouro:";
			// 
			// btnPEndereco
			// 
			this.btnPEndereco.Enabled = false;
			this.btnPEndereco.Location = new System.Drawing.Point(104, 24);
			this.btnPEndereco.Name = "btnPEndereco";
			this.btnPEndereco.Size = new System.Drawing.Size(22, 20);
			this.btnPEndereco.TabIndex = 1;
			this.btnPEndereco.Text = "...";
			this.btnPEndereco.Click += new System.EventHandler(this.btnPEndereco_Click);
			// 
			// edtCodEndereco
			// 
			this.edtCodEndereco.Enabled = false;
			this.edtCodEndereco.Location = new System.Drawing.Point(8, 24);
			this.edtCodEndereco.MaxLength = 10;
			this.edtCodEndereco.Name = "edtCodEndereco";
			this.edtCodEndereco.Size = new System.Drawing.Size(92, 20);
			this.edtCodEndereco.TabIndex = 0;
			this.edtCodEndereco.Text = "";
			this.edtCodEndereco.Leave += new System.EventHandler(this.edtCodEndereco_Leave);
			// 
			// edtPais
			// 
			this.edtPais.Enabled = false;
			this.edtPais.Location = new System.Drawing.Point(92, 352);
			this.edtPais.MaxLength = 30;
			this.edtPais.Name = "edtPais";
			this.edtPais.Size = new System.Drawing.Size(224, 20);
			this.edtPais.TabIndex = 17;
			this.edtPais.Text = "";
			// 
			// edtCodPais
			// 
			this.edtCodPais.Enabled = false;
			this.edtCodPais.Location = new System.Drawing.Point(8, 352);
			this.edtCodPais.MaxLength = 10;
			this.edtCodPais.Name = "edtCodPais";
			this.edtCodPais.Size = new System.Drawing.Size(80, 20);
			this.edtCodPais.TabIndex = 16;
			this.edtCodPais.Text = "";
			this.edtCodPais.Leave += new System.EventHandler(this.edtCodPais_Leave);
			// 
			// labPais
			// 
			this.labPais.Location = new System.Drawing.Point(8, 336);
			this.labPais.Name = "labPais";
			this.labPais.Size = new System.Drawing.Size(88, 16);
			this.labPais.TabIndex = 15;
			this.labPais.Text = "Pa�s de origem:";
			// 
			// btnPPais
			// 
			this.btnPPais.Enabled = false;
			this.btnPPais.Location = new System.Drawing.Point(320, 352);
			this.btnPPais.Name = "btnPPais";
			this.btnPPais.Size = new System.Drawing.Size(22, 20);
			this.btnPPais.TabIndex = 18;
			this.btnPPais.Text = "...";
			this.btnPPais.Click += new System.EventHandler(this.btnPPais_Click);
			// 
			// btnPProfissao
			// 
			this.btnPProfissao.Enabled = false;
			this.btnPProfissao.Location = new System.Drawing.Point(320, 392);
			this.btnPProfissao.Name = "btnPProfissao";
			this.btnPProfissao.Size = new System.Drawing.Size(22, 20);
			this.btnPProfissao.TabIndex = 22;
			this.btnPProfissao.Text = "...";
			this.btnPProfissao.Click += new System.EventHandler(this.btnPProfissao_Click);
			// 
			// edtProfissao
			// 
			this.edtProfissao.Enabled = false;
			this.edtProfissao.Location = new System.Drawing.Point(96, 392);
			this.edtProfissao.MaxLength = 30;
			this.edtProfissao.Name = "edtProfissao";
			this.edtProfissao.Size = new System.Drawing.Size(224, 20);
			this.edtProfissao.TabIndex = 21;
			this.edtProfissao.Text = "";
			// 
			// edtCodProfissao
			// 
			this.edtCodProfissao.Enabled = false;
			this.edtCodProfissao.Location = new System.Drawing.Point(8, 392);
			this.edtCodProfissao.MaxLength = 10;
			this.edtCodProfissao.Name = "edtCodProfissao";
			this.edtCodProfissao.Size = new System.Drawing.Size(80, 20);
			this.edtCodProfissao.TabIndex = 20;
			this.edtCodProfissao.Text = "";
			this.edtCodProfissao.Leave += new System.EventHandler(this.edtCodProfissao_Leave);
			// 
			// labProfissao
			// 
			this.labProfissao.Location = new System.Drawing.Point(8, 376);
			this.labProfissao.Name = "labProfissao";
			this.labProfissao.Size = new System.Drawing.Size(88, 16);
			this.labProfissao.TabIndex = 19;
			this.labProfissao.Text = "Profiss�o:";
			// 
			// frmCadClientes
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(520, 453);
			this.Controls.Add(this.edtProfissao);
			this.Controls.Add(this.edtCodProfissao);
			this.Controls.Add(this.edtPais);
			this.Controls.Add(this.edtCodPais);
			this.Controls.Add(this.edtTelefone);
			this.Controls.Add(this.edtIdentidade);
			this.Controls.Add(this.edtEmail);
			this.Controls.Add(this.btnPProfissao);
			this.Controls.Add(this.labProfissao);
			this.Controls.Add(this.btnPPais);
			this.Controls.Add(this.labPais);
			this.Controls.Add(this.grpEndereco);
			this.Controls.Add(this.labDtNascimento);
			this.Controls.Add(this.edtDtNascimento);
			this.Controls.Add(this.labTelefone);
			this.Controls.Add(this.rdgSexo);
			this.Controls.Add(this.labIdentidade);
			this.Controls.Add(this.labEmail);
			this.Name = "frmCadClientes";
			this.Text = "Cadastro de Clientes";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmCadClientes_Closing);
			this.Controls.SetChildIndex(this.labEmail, 0);
			this.Controls.SetChildIndex(this.labIdentidade, 0);
			this.Controls.SetChildIndex(this.rdgSexo, 0);
			this.Controls.SetChildIndex(this.labTelefone, 0);
			this.Controls.SetChildIndex(this.edtDtNascimento, 0);
			this.Controls.SetChildIndex(this.labDtNascimento, 0);
			this.Controls.SetChildIndex(this.grpEndereco, 0);
			this.Controls.SetChildIndex(this.labPais, 0);
			this.Controls.SetChildIndex(this.btnPPais, 0);
			this.Controls.SetChildIndex(this.labProfissao, 0);
			this.Controls.SetChildIndex(this.btnPProfissao, 0);
			this.Controls.SetChildIndex(this.edtEmail, 0);
			this.Controls.SetChildIndex(this.edtIdentidade, 0);
			this.Controls.SetChildIndex(this.edtTelefone, 0);
			this.Controls.SetChildIndex(this.edtCodPais, 0);
			this.Controls.SetChildIndex(this.edtPais, 0);
			this.Controls.SetChildIndex(this.edtCodProfissao, 0);
			this.Controls.SetChildIndex(this.edtProfissao, 0);
			this.Controls.SetChildIndex(this.labCodigo, 0);
			this.Controls.SetChildIndex(this.labDescricao, 0);
			this.Controls.SetChildIndex(this.edtCodigo, 0);
			this.Controls.SetChildIndex(this.edtDescricao, 0);
			this.Controls.SetChildIndex(this.btnNovo, 0);
			this.Controls.SetChildIndex(this.btnPesquisar, 0);
			this.Controls.SetChildIndex(this.btnAnterior, 0);
			this.Controls.SetChildIndex(this.btnProximo, 0);
			this.Controls.SetChildIndex(this.btnFechar, 0);
			this.Controls.SetChildIndex(this.btnLimpar, 0);
			this.Controls.SetChildIndex(this.btnExcluir, 0);
			this.Controls.SetChildIndex(this.btnSalvar, 0);
			this.rdgSexo.ResumeLayout(false);
			this.grpEndereco.ResumeLayout(false);
			this.ResumeLayout(false);
		}
		#endregion

		protected override bool ValidaDados(bool bTodosDados)
		{
			if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text,
				"C�digo n�o informado!"))
			  return false;
			if (bTodosDados) {
				if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text,
					"Nome n�o informado!"))
					return false;
				if (RotinasGlobais.Rotinas.ValidaCampo(edtEmail.Text,
					"E-mail n�o informado!"))
					return false;
				if (rbMasculino.Checked==false && rbFeminino.Checked==false){
				  MessageBox.Show(this,"Sexo n�o informado!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  return false;
				}
				if (RotinasGlobais.Rotinas.ValidaCampo(edtTelefone.Text,
					"Telefone n�o informado!"))
					return false;
				if (RotinasGlobais.Rotinas.ValidaCampo(edtCodEndereco.Text,
					"Endere�o n�o informado!"))
					return false;
				if (RotinasGlobais.Rotinas.ValidaCampo(edtCodPais.Text,
					"Pa�s n�o informado!"))
					return false;
				if (RotinasGlobais.Rotinas.ValidaCampo(edtCodProfissao.Text,
					"Profiss�o n�o informada!"))
					return false;
			}
			return true;
		}
		protected override void InformaLimpaDados(bool bInformar)
		{
		  base.InformaLimpaDados(bInformar);

		  if (bInformar) {
			edtEmail.Text=Campos[2].ToString();
			edtIdentidade.Text=Campos[3].ToString();
			if (Campos[4].ToString()=="M") {
			   rbMasculino.Checked=true;
			   rbFeminino.Checked=false;
			} else {
			  rbMasculino.Checked=false;
			  rbFeminino.Checked=true;
			}
			edtTelefone.Text=Campos[5].ToString();
			edtDtNascimento.Text=RotinasGlobais.Rotinas.FormataDataStr(
								 Campos[6].ToString(),"dd/MM/yyyy");
			edtCodEndereco.Text=Campos[7].ToString();
			edtLogradouro.Text=Campos[8].ToString();
			edtBairro.Text=Campos[9].ToString();
			edtCEP.Text=Campos[10].ToString();
			edtCidade.Text=Campos[11].ToString();
			edtEstado.Text=Campos[12].ToString();
			edtCodPais.Text=Campos[13].ToString();
			edtPais.Text=Campos[14].ToString();
			edtCodProfissao.Text=Campos[15].ToString();
			edtProfissao.Text=Campos[16].ToString();
		  } else {
			edtEmail.Clear();
			edtIdentidade.Clear();
			rbMasculino.Checked=false;
			rbFeminino.Checked=false;
			edtTelefone.Clear();
			edtDtNascimento.Value=DateTime.Now;
			edtCodEndereco.Clear();
			edtLogradouro.Clear();
			edtBairro.Clear();
			edtCEP.Clear();
			edtCidade.Clear();
			edtEstado.Clear();
			edtCodPais.Clear();
			edtPais.Clear();
			edtCodProfissao.Clear();
			edtProfissao.Clear();
		  }

		}

		protected override void HabilitaDados(bool bHabilita)
		{
			 base.HabilitaDados(bHabilita);

			 edtEmail.Enabled=bHabilita;
			 edtIdentidade.Enabled=bHabilita;
			 rbMasculino.Enabled=bHabilita;
			 rbFeminino.Enabled=bHabilita;
			 edtTelefone.Enabled=bHabilita;
			 edtDtNascimento.Enabled=bHabilita;
			 edtCodEndereco.Enabled=bHabilita;
			 btnPEndereco.Enabled=bHabilita;
			 edtCodPais.Enabled=bHabilita;
			 btnPPais.Enabled=bHabilita;
			 edtCodProfissao.Enabled=bHabilita;
			 btnPProfissao.Enabled=bHabilita;
		}

		private void btnExcluir_Click(object sender, System.EventArgs e)
		{
			ExcluirDados(ConsultasSQL.ConsSQL.Cliente('D',edtCodigo.Text,
			"","","","","","","","",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S',edtCodigo.Text,
			"","","","","","","","",""),"Cliente n�o encontrado!");
		}

		private void btnSalvar_Click(object sender, System.EventArgs e)
		{
		  if (rbMasculino.Checked)
			 sSexo="M";
		  else
			 sSexo="F";

			SalvarDados(ConsultasSQL.ConsSQL.Cliente('S',edtCodigo.Text,"",
			"","","","","","","",""),
			ConsultasSQL.ConsSQL.Cliente('U',edtCodigo.Text,edtDescricao.Text,
			edtEmail.Text,edtIdentidade.Text,sSexo,edtTelefone.Text,
			edtDtNascimento.Value.ToString("MM/dd/yyyy"),
			edtCodEndereco.Text,edtCodPais.Text,edtCodProfissao.Text),
			ConsultasSQL.ConsSQL.Cliente('I',edtCodigo.Text,edtDescricao.Text,
			edtEmail.Text,edtIdentidade.Text,sSexo,edtTelefone.Text,
			edtDtNascimento.Value.ToString("MM/dd/yyyy"),
			edtCodEndereco.Text,edtCodPais.Text,edtCodProfissao.Text),
			true);
		}

		private void frmCadClientes_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			frmPrincipal.fPrincipal.tlbClientes.Enabled=true;
			frmPrincipal.fPrincipal.mnuCadClientes.Enabled=true;
		}

		protected override void edtCodigo_Leave(object sender, System.EventArgs e)
		{
			if (edtCodigo.Text.Equals("")==false) {
			  if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.Text)==false) {
				  MessageBox.Show(this,"CPF inv�lido!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  edtCodigo.Clear();
				  edtCodigo.Focus();
			  }
			}
		}

		private void edtCodEndereco_Leave(object sender, System.EventArgs e)
		{
		  if (edtCodEndereco.Text.Equals("")==false) {
			edtLogradouro.Text=
			RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
			edtCodEndereco.Text,ConsultasSQL.ConsSQL.Endereco('S',
			edtCodEndereco.Text,"","","","",""),"Endere�o n�o encontrado!");
			if (edtLogradouro.Text.Equals("")==false) {
			  edtBairro.Text=ConsCampo[2].ToString();
			  edtCEP.Text=ConsCampo[3].ToString();
			  edtCidade.Text=ConsCampo[4].ToString();
			  edtEstado.Text=ConsCampo[5].ToString();
			} else {
			  edtCodEndereco.Focus();
			  edtLogradouro.Clear();
			  edtBairro.Clear();
			  edtCEP.Clear();
			  edtCidade.Clear();
			  edtEstado.Clear();
			}
		  } else {
			  edtLogradouro.Clear();
			  edtBairro.Clear();
			  edtCEP.Clear();
			  edtCidade.Clear();
			  edtEstado.Clear();
		  }
		}
		
		private void edtCodPais_Leave(object sender, System.EventArgs e)
		{
			if (edtCodPais.Text.Equals("")==false) {
			   edtPais.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
			   ConsultasSQL.ConsSQL.Pais('S',edtCodPais.Text,""),
			   "Pa�s n�o encontrado!");
			   if (edtPais.Text.Equals("")) {
				 edtCodPais.Clear();
				 edtCodPais.Focus();
			   }
			 } else
				edtPais.Clear();

		}

		private void edtCodProfissao_Leave(object sender, System.EventArgs e)
		{
		  if (edtCodProfissao.Text.Equals("")==false) {
		   edtProfissao.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
		   edtCodProfissao.Text,ConsultasSQL.ConsSQL.Profissao('S',
		   edtCodProfissao.Text,""),"Profiss�o n�o encontrado!");
		   if (edtProfissao.Text.Equals(""))
			 edtCodProfissao.Focus();
		  } else
			edtProfissao.Clear();
		}

		private void btnPEndereco_Click(object sender, System.EventArgs e)
		{
			frmConEnderecos pfConEnderecos = new frmConEnderecos();
			pfConEnderecos.ShowDialog();
			edtCodEndereco.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtCodEndereco_Leave(this, null);
		}

		private void btnPPais_Click(object sender, System.EventArgs e)
		{
			frmConPaises pfConPaises = new frmConPaises();
			pfConPaises.ShowDialog();
			edtCodPais.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtCodPais_Leave(this,null);
		}

		private void btnPProfissao_Click(object sender, System.EventArgs e)
		{
			frmConProfissoes pfConProfissoes = new frmConProfissoes();
			pfConProfissoes.ShowDialog();
			edtCodProfissao.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtCodProfissao_Leave(this,null);
		}
	}
}
