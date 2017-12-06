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
	public class frmCadLivros : Livrus.frmCadastros
	{
		public static frmCadLivros fCadLivros;
		private ArrayList slIdiomas, slAssuntos, slAutores, ConsCampo, ConsLista;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.Label labEdicao;
		private System.Windows.Forms.NumericUpDown edtEdicao;
		private System.Windows.Forms.NumericUpDown edtAnoPubli;
		private System.Windows.Forms.Label labAnoPubli;
		private System.Windows.Forms.Button btnPAssunto;
		private System.Windows.Forms.TextBox edtAssunto;
		private System.Windows.Forms.TextBox edtCodAssunto;
		private System.Windows.Forms.Label labAssunto;
		private System.Windows.Forms.Button btnPEditora;
		private System.Windows.Forms.TextBox edtEditora;
		private System.Windows.Forms.TextBox edtCodEditora;
		private System.Windows.Forms.Label labEditora;
		private System.Windows.Forms.Button btnAdAssuntos;
		private System.Windows.Forms.NumericUpDown edtVolume;
		private System.Windows.Forms.Label labVolume;
		private System.Windows.Forms.NumericUpDown edtNPaginas;
		private System.Windows.Forms.Label labNPaginas;
		private System.Windows.Forms.Label labIdioma;
		private System.Windows.Forms.ComboBox cmbIdioma;
		private System.Windows.Forms.ListBox lstAssuntos;
		private System.Windows.Forms.Label labPreco;
		private System.Windows.Forms.TextBox edtPreco;
		private System.Windows.Forms.NumericUpDown edtQtdEstoque;
		private System.Windows.Forms.Label labQtdEstoque;
		private System.Windows.Forms.ListBox lstAutores;
		private System.Windows.Forms.Button btnAdAutores;
		private System.Windows.Forms.Button btnPAutor;
		private System.Windows.Forms.TextBox edtAutor;
		private System.Windows.Forms.TextBox edtCodAutor;
		private System.Windows.Forms.Label labAutor;

		public frmCadLivros()
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			//
			// TODO: Add any constructor code after InitializeComponent call
			//
			slIdiomas = new ArrayList();
			slAssuntos = new ArrayList();
			slAutores = new ArrayList();
			ConsCampo = new ArrayList();
			ConsLista = new ArrayList();
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
			this.labEdicao = new System.Windows.Forms.Label();
			this.edtEdicao = new System.Windows.Forms.NumericUpDown();
			this.edtAnoPubli = new System.Windows.Forms.NumericUpDown();
			this.labAnoPubli = new System.Windows.Forms.Label();
			this.btnPAssunto = new System.Windows.Forms.Button();
			this.edtAssunto = new System.Windows.Forms.TextBox();
			this.edtCodAssunto = new System.Windows.Forms.TextBox();
			this.labAssunto = new System.Windows.Forms.Label();
			this.btnPEditora = new System.Windows.Forms.Button();
			this.edtEditora = new System.Windows.Forms.TextBox();
			this.edtCodEditora = new System.Windows.Forms.TextBox();
			this.labEditora = new System.Windows.Forms.Label();
			this.btnAdAssuntos = new System.Windows.Forms.Button();
			this.edtVolume = new System.Windows.Forms.NumericUpDown();
			this.labVolume = new System.Windows.Forms.Label();
			this.edtNPaginas = new System.Windows.Forms.NumericUpDown();
			this.labNPaginas = new System.Windows.Forms.Label();
			this.labIdioma = new System.Windows.Forms.Label();
			this.cmbIdioma = new System.Windows.Forms.ComboBox();
			this.lstAssuntos = new System.Windows.Forms.ListBox();
			this.labPreco = new System.Windows.Forms.Label();
			this.edtPreco = new System.Windows.Forms.TextBox();
			this.edtQtdEstoque = new System.Windows.Forms.NumericUpDown();
			this.labQtdEstoque = new System.Windows.Forms.Label();
			this.lstAutores = new System.Windows.Forms.ListBox();
			this.btnAdAutores = new System.Windows.Forms.Button();
			this.btnPAutor = new System.Windows.Forms.Button();
			this.edtAutor = new System.Windows.Forms.TextBox();
			this.edtCodAutor = new System.Windows.Forms.TextBox();
			this.labAutor = new System.Windows.Forms.Label();
			((System.ComponentModel.ISupportInitialize)(this.edtEdicao)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.edtAnoPubli)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.edtVolume)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.edtNPaginas)).BeginInit();
			((System.ComponentModel.ISupportInitialize)(this.edtQtdEstoque)).BeginInit();
			this.SuspendLayout();
			// 
			// labCodigo
			// 
			this.labCodigo.Name = "labCodigo";
			this.labCodigo.Text = "ISBN:";
			// 
			// edtCodigo
			// 
			this.edtCodigo.MaxLength = 13;
			this.edtCodigo.Name = "edtCodigo";
			this.edtCodigo.Leave += new System.EventHandler(this.edtCodigo_Leave);
			// 
			// labDescricao
			// 
			this.labDescricao.Name = "labDescricao";
			this.labDescricao.Text = "Título:";
			// 
			// edtDescricao
			// 
			this.edtDescricao.Name = "edtDescricao";
			this.edtDescricao.Size = new System.Drawing.Size(304, 20);
			// 
			// btnNovo
			// 
			this.btnNovo.Name = "btnNovo";
			// 
			// btnPesquisar
			// 
			this.btnPesquisar.Location = new System.Drawing.Point(440, 8);
			this.btnPesquisar.Name = "btnPesquisar";
			this.btnPesquisar.TabIndex = 35;
			this.btnPesquisar.Click += new System.EventHandler(this.btnPesquisar_Click);
			// 
			// btnAnterior
			// 
			this.btnAnterior.Location = new System.Drawing.Point(440, 40);
			this.btnAnterior.Name = "btnAnterior";
			this.btnAnterior.TabIndex = 36;
			// 
			// btnProximo
			// 
			this.btnProximo.Location = new System.Drawing.Point(440, 72);
			this.btnProximo.Name = "btnProximo";
			this.btnProximo.TabIndex = 37;
			// 
			// btnFechar
			// 
			this.btnFechar.Location = new System.Drawing.Point(440, 352);
			this.btnFechar.Name = "btnFechar";
			this.btnFechar.TabIndex = 41;
			this.btnFechar.Click += new System.EventHandler(this.btnFechar_Click);
			// 
			// btnLimpar
			// 
			this.btnLimpar.Location = new System.Drawing.Point(360, 352);
			this.btnLimpar.Name = "btnLimpar";
			this.btnLimpar.TabIndex = 40;
			// 
			// btnExcluir
			// 
			this.btnExcluir.Location = new System.Drawing.Point(280, 352);
			this.btnExcluir.Name = "btnExcluir";
			this.btnExcluir.TabIndex = 39;
			this.btnExcluir.Click += new System.EventHandler(this.btnExcluir_Click);
			// 
			// btnSalvar
			// 
			this.btnSalvar.Location = new System.Drawing.Point(200, 352);
			this.btnSalvar.Name = "btnSalvar";
			this.btnSalvar.TabIndex = 38;
			this.btnSalvar.Click += new System.EventHandler(this.btnSalvar_Click);
			// 
			// labEdicao
			// 
			this.labEdicao.Location = new System.Drawing.Point(320, 48);
			this.labEdicao.Name = "labEdicao";
			this.labEdicao.Size = new System.Drawing.Size(48, 16);
			this.labEdicao.TabIndex = 5;
			this.labEdicao.Text = "Edição";
			// 
			// edtEdicao
			// 
			this.edtEdicao.Enabled = false;
			this.edtEdicao.Location = new System.Drawing.Point(320, 64);
			this.edtEdicao.Maximum = new decimal(new int[] {
						9999,
						0,
						0,
						0});
			this.edtEdicao.Minimum = new decimal(new int[] {
						1,
						0,
						0,
						0});
			this.edtEdicao.Name = "edtEdicao";
			this.edtEdicao.Size = new System.Drawing.Size(104, 20);
			this.edtEdicao.TabIndex = 6;
			this.edtEdicao.Value = new decimal(new int[] {
						1,
						0,
						0,
						0});
			// 
			// edtAnoPubli
			// 
			this.edtAnoPubli.Enabled = false;
			this.edtAnoPubli.Location = new System.Drawing.Point(8, 104);
			this.edtAnoPubli.Maximum = new decimal(new int[] {
						9999,
						0,
						0,
						0});
			this.edtAnoPubli.Minimum = new decimal(new int[] {
						1,
						0,
						0,
						0});
			this.edtAnoPubli.Name = "edtAnoPubli";
			this.edtAnoPubli.Size = new System.Drawing.Size(88, 20);
			this.edtAnoPubli.TabIndex = 8;
			this.edtAnoPubli.Value = new decimal(new int[] {
						2004,
						0,
						0,
						0});
			// 
			// labAnoPubli
			// 
			this.labAnoPubli.Location = new System.Drawing.Point(8, 88);
			this.labAnoPubli.Name = "labAnoPubli";
			this.labAnoPubli.Size = new System.Drawing.Size(88, 16);
			this.labAnoPubli.TabIndex = 7;
			this.labAnoPubli.Text = "Ano Publicação:";
			// 
			// btnPAssunto
			// 
			this.btnPAssunto.Enabled = false;
			this.btnPAssunto.Location = new System.Drawing.Point(408, 184);
			this.btnPAssunto.Name = "btnPAssunto";
			this.btnPAssunto.Size = new System.Drawing.Size(22, 20);
			this.btnPAssunto.TabIndex = 23;
			this.btnPAssunto.Text = "...";
			this.btnPAssunto.Click += new System.EventHandler(this.btnPAssunto_Click);
			// 
			// edtAssunto
			// 
			this.edtAssunto.Enabled = false;
			this.edtAssunto.Location = new System.Drawing.Point(184, 184);
			this.edtAssunto.MaxLength = 30;
			this.edtAssunto.Name = "edtAssunto";
			this.edtAssunto.Size = new System.Drawing.Size(200, 20);
			this.edtAssunto.TabIndex = 21;
			this.edtAssunto.Text = "";
			// 
			// edtCodAssunto
			// 
			this.edtCodAssunto.Enabled = false;
			this.edtCodAssunto.Location = new System.Drawing.Point(100, 184);
			this.edtCodAssunto.MaxLength = 10;
			this.edtCodAssunto.Name = "edtCodAssunto";
			this.edtCodAssunto.Size = new System.Drawing.Size(80, 20);
			this.edtCodAssunto.TabIndex = 20;
			this.edtCodAssunto.Text = "";
			this.edtCodAssunto.Leave += new System.EventHandler(this.edtCodAssunto_Leave);
			// 
			// labAssunto
			// 
			this.labAssunto.Location = new System.Drawing.Point(100, 168);
			this.labAssunto.Name = "labAssunto";
			this.labAssunto.Size = new System.Drawing.Size(68, 16);
			this.labAssunto.TabIndex = 19;
			this.labAssunto.Text = "Assunto:";
			// 
			// btnPEditora
			// 
			this.btnPEditora.Enabled = false;
			this.btnPEditora.Location = new System.Drawing.Point(400, 104);
			this.btnPEditora.Name = "btnPEditora";
			this.btnPEditora.Size = new System.Drawing.Size(22, 20);
			this.btnPEditora.TabIndex = 12;
			this.btnPEditora.Text = "...";
			this.btnPEditora.Click += new System.EventHandler(this.btnPEditora_Click);
			// 
			// edtEditora
			// 
			this.edtEditora.Enabled = false;
			this.edtEditora.Location = new System.Drawing.Point(184, 104);
			this.edtEditora.MaxLength = 30;
			this.edtEditora.Name = "edtEditora";
			this.edtEditora.Size = new System.Drawing.Size(216, 20);
			this.edtEditora.TabIndex = 11;
			this.edtEditora.Text = "";
			// 
			// edtCodEditora
			// 
			this.edtCodEditora.Enabled = false;
			this.edtCodEditora.Location = new System.Drawing.Point(100, 104);
			this.edtCodEditora.MaxLength = 10;
			this.edtCodEditora.Name = "edtCodEditora";
			this.edtCodEditora.Size = new System.Drawing.Size(80, 20);
			this.edtCodEditora.TabIndex = 10;
			this.edtCodEditora.Text = "";
			this.edtCodEditora.Leave += new System.EventHandler(this.edtCodEditora_Leave);
			// 
			// labEditora
			// 
			this.labEditora.Location = new System.Drawing.Point(100, 88);
			this.labEditora.Name = "labEditora";
			this.labEditora.Size = new System.Drawing.Size(52, 16);
			this.labEditora.TabIndex = 9;
			this.labEditora.Text = "Editora:";
			// 
			// btnAdAssuntos
			// 
			this.btnAdAssuntos.Enabled = false;
			this.btnAdAssuntos.Location = new System.Drawing.Point(384, 184);
			this.btnAdAssuntos.Name = "btnAdAssuntos";
			this.btnAdAssuntos.Size = new System.Drawing.Size(22, 20);
			this.btnAdAssuntos.TabIndex = 22;
			this.btnAdAssuntos.Text = "+";
			this.btnAdAssuntos.Click += new System.EventHandler(this.btnAdAssuntos_Click);
			// 
			// edtVolume
			// 
			this.edtVolume.Enabled = false;
			this.edtVolume.Location = new System.Drawing.Point(8, 144);
			this.edtVolume.Maximum = new decimal(new int[] {
						9999,
						0,
						0,
						0});
			this.edtVolume.Minimum = new decimal(new int[] {
						1,
						0,
						0,
						0});
			this.edtVolume.Name = "edtVolume";
			this.edtVolume.Size = new System.Drawing.Size(88, 20);
			this.edtVolume.TabIndex = 14;
			this.edtVolume.Value = new decimal(new int[] {
						1,
						0,
						0,
						0});
			// 
			// labVolume
			// 
			this.labVolume.Location = new System.Drawing.Point(8, 128);
			this.labVolume.Name = "labVolume";
			this.labVolume.Size = new System.Drawing.Size(56, 16);
			this.labVolume.TabIndex = 13;
			this.labVolume.Text = "Volume:";
			// 
			// edtNPaginas
			// 
			this.edtNPaginas.Enabled = false;
			this.edtNPaginas.Location = new System.Drawing.Point(8, 184);
			this.edtNPaginas.Maximum = new decimal(new int[] {
						9999,
						0,
						0,
						0});
			this.edtNPaginas.Minimum = new decimal(new int[] {
						1,
						0,
						0,
						0});
			this.edtNPaginas.Name = "edtNPaginas";
			this.edtNPaginas.Size = new System.Drawing.Size(88, 20);
			this.edtNPaginas.TabIndex = 18;
			this.edtNPaginas.Value = new decimal(new int[] {
						1,
						0,
						0,
						0});
			// 
			// labNPaginas
			// 
			this.labNPaginas.Location = new System.Drawing.Point(8, 168);
			this.labNPaginas.Name = "labNPaginas";
			this.labNPaginas.Size = new System.Drawing.Size(64, 16);
			this.labNPaginas.TabIndex = 17;
			this.labNPaginas.Text = "Nº Páginas:";
			// 
			// labIdioma
			// 
			this.labIdioma.Location = new System.Drawing.Point(100, 128);
			this.labIdioma.Name = "labIdioma";
			this.labIdioma.Size = new System.Drawing.Size(60, 16);
			this.labIdioma.TabIndex = 15;
			this.labIdioma.Text = "Idioma:";
			// 
			// cmbIdioma
			// 
			this.cmbIdioma.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.cmbIdioma.Enabled = false;
			this.cmbIdioma.Location = new System.Drawing.Point(100, 144);
			this.cmbIdioma.Name = "cmbIdioma";
			this.cmbIdioma.Size = new System.Drawing.Size(328, 21);
			this.cmbIdioma.TabIndex = 16;
			// 
			// lstAssuntos
			// 
			this.lstAssuntos.Enabled = false;
			this.lstAssuntos.Location = new System.Drawing.Point(100, 208);
			this.lstAssuntos.Name = "lstAssuntos";
			this.lstAssuntos.Size = new System.Drawing.Size(332, 43);
			this.lstAssuntos.TabIndex = 24;
			this.lstAssuntos.DoubleClick += new System.EventHandler(this.lstAssuntos_DoubleClick);
			// 
			// labPreco
			// 
			this.labPreco.Location = new System.Drawing.Point(8, 212);
			this.labPreco.Name = "labPreco";
			this.labPreco.Size = new System.Drawing.Size(64, 16);
			this.labPreco.TabIndex = 25;
			this.labPreco.Text = "Preço:";
			// 
			// edtPreco
			// 
			this.edtPreco.Enabled = false;
			this.edtPreco.Location = new System.Drawing.Point(8, 231);
			this.edtPreco.Name = "edtPreco";
			this.edtPreco.Size = new System.Drawing.Size(88, 20);
			this.edtPreco.TabIndex = 26;
			this.edtPreco.Text = "";
			this.edtPreco.Leave += new System.EventHandler(this.edtPreco_Leave);
			// 
			// edtQtdEstoque
			// 
			this.edtQtdEstoque.Enabled = false;
			this.edtQtdEstoque.Location = new System.Drawing.Point(8, 272);
			this.edtQtdEstoque.Maximum = new decimal(new int[] {
						9999,
						0,
						0,
						0});
			this.edtQtdEstoque.Name = "edtQtdEstoque";
			this.edtQtdEstoque.Size = new System.Drawing.Size(88, 20);
			this.edtQtdEstoque.TabIndex = 28;
			// 
			// labQtdEstoque
			// 
			this.labQtdEstoque.Location = new System.Drawing.Point(8, 256);
			this.labQtdEstoque.Name = "labQtdEstoque";
			this.labQtdEstoque.Size = new System.Drawing.Size(80, 16);
			this.labQtdEstoque.TabIndex = 27;
			this.labQtdEstoque.Text = "Qtd. Estoque:";
			// 
			// lstAutores
			// 
			this.lstAutores.Enabled = false;
			this.lstAutores.Location = new System.Drawing.Point(100, 296);
			this.lstAutores.Name = "lstAutores";
			this.lstAutores.Size = new System.Drawing.Size(332, 43);
			this.lstAutores.TabIndex = 34;
			this.lstAutores.DoubleClick += new System.EventHandler(this.lstAutores_DoubleClick);
			// 
			// btnAdAutores
			// 
			this.btnAdAutores.Enabled = false;
			this.btnAdAutores.Location = new System.Drawing.Point(384, 272);
			this.btnAdAutores.Name = "btnAdAutores";
			this.btnAdAutores.Size = new System.Drawing.Size(22, 20);
			this.btnAdAutores.TabIndex = 32;
			this.btnAdAutores.Text = "+";
			this.btnAdAutores.Click += new System.EventHandler(this.btnAdAutores_Click);
			// 
			// btnPAutor
			// 
			this.btnPAutor.Enabled = false;
			this.btnPAutor.Location = new System.Drawing.Point(408, 272);
			this.btnPAutor.Name = "btnPAutor";
			this.btnPAutor.Size = new System.Drawing.Size(22, 20);
			this.btnPAutor.TabIndex = 33;
			this.btnPAutor.Text = "...";
			this.btnPAutor.Click += new System.EventHandler(this.btnPAutor_Click);
			// 
			// edtAutor
			// 
			this.edtAutor.Enabled = false;
			this.edtAutor.Location = new System.Drawing.Point(184, 272);
			this.edtAutor.MaxLength = 30;
			this.edtAutor.Name = "edtAutor";
			this.edtAutor.Size = new System.Drawing.Size(200, 20);
			this.edtAutor.TabIndex = 31;
			this.edtAutor.Text = "";
			// 
			// edtCodAutor
			// 
			this.edtCodAutor.Enabled = false;
			this.edtCodAutor.Location = new System.Drawing.Point(100, 272);
			this.edtCodAutor.MaxLength = 10;
			this.edtCodAutor.Name = "edtCodAutor";
			this.edtCodAutor.Size = new System.Drawing.Size(80, 20);
			this.edtCodAutor.TabIndex = 30;
			this.edtCodAutor.Text = "";
			this.edtCodAutor.Leave += new System.EventHandler(this.edtCodAutor_Leave);
			// 
			// labAutor
			// 
			this.labAutor.Location = new System.Drawing.Point(100, 256);
			this.labAutor.Name = "labAutor";
			this.labAutor.Size = new System.Drawing.Size(68, 16);
			this.labAutor.TabIndex = 29;
			this.labAutor.Text = "Autor:";
			// 
			// frmCadLivros
			// 
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(520, 381);
			this.Controls.Add(this.edtAutor);
			this.Controls.Add(this.edtCodAutor);
			this.Controls.Add(this.edtPreco);
			this.Controls.Add(this.edtAssunto);
			this.Controls.Add(this.edtCodAssunto);
			this.Controls.Add(this.edtEditora);
			this.Controls.Add(this.edtCodEditora);
			this.Controls.Add(this.lstAutores);
			this.Controls.Add(this.btnAdAutores);
			this.Controls.Add(this.btnPAutor);
			this.Controls.Add(this.labAutor);
			this.Controls.Add(this.edtQtdEstoque);
			this.Controls.Add(this.labQtdEstoque);
			this.Controls.Add(this.labPreco);
			this.Controls.Add(this.lstAssuntos);
			this.Controls.Add(this.cmbIdioma);
			this.Controls.Add(this.labIdioma);
			this.Controls.Add(this.edtNPaginas);
			this.Controls.Add(this.labNPaginas);
			this.Controls.Add(this.edtVolume);
			this.Controls.Add(this.labVolume);
			this.Controls.Add(this.btnAdAssuntos);
			this.Controls.Add(this.btnPAssunto);
			this.Controls.Add(this.labAssunto);
			this.Controls.Add(this.btnPEditora);
			this.Controls.Add(this.labEditora);
			this.Controls.Add(this.edtAnoPubli);
			this.Controls.Add(this.labAnoPubli);
			this.Controls.Add(this.edtEdicao);
			this.Controls.Add(this.labEdicao);
			this.Name = "frmCadLivros";
			this.Text = "Cadastro de Livros";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmCadLivros_Closing);
			this.Load += new System.EventHandler(this.frmCadLivros_Load);
			this.Controls.SetChildIndex(this.labEdicao, 0);
			this.Controls.SetChildIndex(this.edtEdicao, 0);
			this.Controls.SetChildIndex(this.labAnoPubli, 0);
			this.Controls.SetChildIndex(this.edtAnoPubli, 0);
			this.Controls.SetChildIndex(this.labEditora, 0);
			this.Controls.SetChildIndex(this.btnPEditora, 0);
			this.Controls.SetChildIndex(this.labAssunto, 0);
			this.Controls.SetChildIndex(this.btnPAssunto, 0);
			this.Controls.SetChildIndex(this.btnAdAssuntos, 0);
			this.Controls.SetChildIndex(this.labVolume, 0);
			this.Controls.SetChildIndex(this.edtVolume, 0);
			this.Controls.SetChildIndex(this.labNPaginas, 0);
			this.Controls.SetChildIndex(this.edtNPaginas, 0);
			this.Controls.SetChildIndex(this.labIdioma, 0);
			this.Controls.SetChildIndex(this.cmbIdioma, 0);
			this.Controls.SetChildIndex(this.lstAssuntos, 0);
			this.Controls.SetChildIndex(this.labPreco, 0);
			this.Controls.SetChildIndex(this.labQtdEstoque, 0);
			this.Controls.SetChildIndex(this.edtQtdEstoque, 0);
			this.Controls.SetChildIndex(this.labAutor, 0);
			this.Controls.SetChildIndex(this.btnPAutor, 0);
			this.Controls.SetChildIndex(this.btnAdAutores, 0);
			this.Controls.SetChildIndex(this.lstAutores, 0);
			this.Controls.SetChildIndex(this.edtCodEditora, 0);
			this.Controls.SetChildIndex(this.edtEditora, 0);
			this.Controls.SetChildIndex(this.edtCodAssunto, 0);
			this.Controls.SetChildIndex(this.edtAssunto, 0);
			this.Controls.SetChildIndex(this.edtPreco, 0);
			this.Controls.SetChildIndex(this.edtCodAutor, 0);
			this.Controls.SetChildIndex(this.edtAutor, 0);
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
			((System.ComponentModel.ISupportInitialize)(this.edtEdicao)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.edtAnoPubli)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.edtVolume)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.edtNPaginas)).EndInit();
			((System.ComponentModel.ISupportInitialize)(this.edtQtdEstoque)).EndInit();
			this.ResumeLayout(false);
		}
		#endregion

		protected override bool ValidaDados(bool bTodosDados)
		{
			if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Text,
				"ISBN não informado!"))
			  return false;
			if (bTodosDados) {
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Text,
				"Título não informado!"))
				return false;
			  if (RotinasGlobais.Rotinas.ValidaCampo(edtEditora.Text,
					"Editora não informada!"))
					return false;
			  if (lstAssuntos.Items.Count == 0){
				  MessageBox.Show(this,"Assunto(s) não informado(s)!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  return false;
			  }
			  if (lstAutores.Items.Count == 0){
				  MessageBox.Show(this,"Autor(es) não informado(s)!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  return false;
			  }

			}
			return true;
		}
	  protected override void InformaLimpaDados(bool bInformar)
	  {
		  base.InformaLimpaDados(bInformar);
		  if (bInformar) {
			edtEdicao.Text=Campos[2].ToString();
			edtAnoPubli.Text=Campos[3].ToString();
			edtVolume.Text=Campos[4].ToString();
			edtCodEditora.Text=Campos[5].ToString();
			edtEditora.Text=Campos[6].ToString();
			cmbIdioma.SelectedIndex=slIdiomas.IndexOf(Campos[7].ToString());
			edtNPaginas.Text=Campos[9].ToString();
			edtPreco.Text=RotinasGlobais.Rotinas.
							 VirgulaParaPonto(Campos[10].ToString(),true);
			edtQtdEstoque.Text=Campos[11].ToString();
			RotinasGlobais.Rotinas.AdicionaValoresLista(ConsLista,ConsultasSQL.
			ConsSQL.LivroAss('S',edtCodigo.Text,""),lstAssuntos,slAssuntos);
			RotinasGlobais.Rotinas.AdicionaValoresLista(ConsLista,ConsultasSQL.
			ConsSQL.LivroAut('S',edtCodigo.Text,""),lstAutores,slAutores);
		  } else {
			edtEdicao.Value=1;
			edtAnoPubli.Text=DateTime.Now.ToString("yyyy");
			edtVolume.Value=1;
			edtCodEditora.Clear();
			edtEditora.Clear();
			edtNPaginas.Value=1;
			edtPreco.Text="0,00";
			edtQtdEstoque.Value=1;
			edtCodAssunto.Clear();
			lstAssuntos.Items.Clear();
			edtCodAutor.Clear();
			lstAutores.Items.Clear();
			slAssuntos.Clear();
			slAutores.Clear();
		  }
	  }

	  protected override void HabilitaDados(bool bHabilita)
	  {
		 base.HabilitaDados(bHabilita);

		 edtEdicao.Enabled=bHabilita;
		 edtAnoPubli.Enabled=bHabilita;
		 edtVolume.Enabled=bHabilita;
		 edtCodEditora.Enabled=bHabilita;
		 btnPEditora.Enabled=bHabilita;
		 cmbIdioma.Enabled=bHabilita;
		 edtNPaginas.Enabled=bHabilita;
		 edtPreco.Enabled=bHabilita;
		 edtQtdEstoque.Enabled=bHabilita;
		 edtCodAssunto.Enabled=bHabilita;
		 btnPAssunto.Enabled=bHabilita;
		 btnAdAssuntos.Enabled=bHabilita;
		 lstAssuntos.Enabled=bHabilita;
		 edtCodAutor.Enabled=bHabilita;
		 btnPAutor.Enabled=bHabilita;
		 btnAdAutores.Enabled=bHabilita;
		 lstAutores.Enabled=bHabilita;
	  }


		private void btnExcluir_Click(object sender, System.EventArgs e)
		{
			ExcluirDados(ConsultasSQL.ConsSQL.Livro('D',edtCodigo.Text,
			"","","","","","","","",""));
		}

		private void btnPesquisar_Click(object sender, System.EventArgs e)
		{
			PesquisarDados(ConsultasSQL.ConsSQL.Livro('S',edtCodigo.Text,
			"","","","","","","","",""),"Livro não encontrado!");
		}

		private void btnSalvar_Click(object sender, System.EventArgs e)
		{
			SalvarDados(ConsultasSQL.ConsSQL.Livro('S',edtCodigo.Text,
			"","","","","","","","",""),
			ConsultasSQL.ConsSQL.Livro('U',edtCodigo.Text,edtDescricao.Text,
			edtEdicao.Text,edtAnoPubli.Text,edtVolume.Text,edtCodEditora.Text,
			slIdiomas[cmbIdioma.SelectedIndex].ToString(),edtNPaginas.Text,
			RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Text,false),
			edtQtdEstoque.Text),
			ConsultasSQL.ConsSQL.Livro('I',edtCodigo.Text,edtDescricao.Text,
			edtEdicao.Text,edtAnoPubli.Text,edtVolume.Text,edtCodEditora.Text,
			slIdiomas[cmbIdioma.SelectedIndex].ToString(),edtNPaginas.Text,
			RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Text,false),
			edtQtdEstoque.Text), true);
			SalvaLista('A');
			SalvaLista('B');
			btnLimpar_Click(this,null);
		}

		private void frmCadLivros_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			frmPrincipal.fPrincipal.tlbLivros.Enabled=true;
			frmPrincipal.fPrincipal.mnuCadLivros.Enabled=true;
		}

		private void btnFechar_Click(object sender, System.EventArgs e)
		{
			frmCadLivros_Closing(this,null);
		}

		private void frmCadLivros_Load(object sender, System.EventArgs e)
		{
		  edtAnoPubli.Text=DateTime.Now.ToString("yyyy");
		  AdicionaCombo();
		  cmbIdioma.SelectedIndex=0;
		}

		private void AdicionaCombo() {
			ArrayList linhas = new ArrayList();
			ArrayList regs = new ArrayList();

			RotinasGlobais.Rotinas.ConsultaDados(regs,
				ConsultasSQL.ConsSQL.Idioma('S',"",""));

			for(int cont=0; cont < regs.Count; cont++) {
			  linhas = (ArrayList) regs[cont];
			  slIdiomas.Add(linhas[0].ToString());
			  cmbIdioma.Items.Add(linhas[1].ToString());
			}
		}
		private void SalvaLista(char sOpcao) {
			if (sOpcao=='A') {
			 RotinasGlobais.Rotinas.ConsultaDados(Arquiva,
			 ConsultasSQL.ConsSQL.LivroAss('D',edtCodigo.Text,""));

			 for (int nCont=0; nCont < slAssuntos.Count; nCont++)  {
			  RotinasGlobais.Rotinas.ConsultaDados(Arquiva,
			  ConsultasSQL.ConsSQL.LivroAss('I',
					edtCodigo.Text,slAssuntos[nCont].ToString()));
			 }
			} else if (sOpcao=='B') {
			  RotinasGlobais.Rotinas.ConsultaDados(Arquiva,
			  ConsultasSQL.ConsSQL.LivroAut('D',edtCodigo.Text,""));

			  for (int nCont=0; nCont < slAutores.Count; nCont++)  {
			   RotinasGlobais.Rotinas.ConsultaDados(Arquiva,
			   ConsultasSQL.ConsSQL.LivroAut('I',
					 edtCodigo.Text,slAssuntos[nCont].ToString()));
			  }
			}
		}

		protected override void edtCodigo_Leave(object sender, System.EventArgs e)
		{
			if (edtCodigo.Text.Equals("")==false) {
			  if (RotinasGlobais.Rotinas.ValidaISBN(edtCodigo.Text)==false) {
				  MessageBox.Show(this,"ISBN inválido!",
				  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
				  MessageBoxIcon.Error);
				  edtCodigo.Clear();
				  edtCodigo.Focus();
			  }
			}
		}

		private void edtCodEditora_Leave(object sender, System.EventArgs e)
		{
		  if (edtCodEditora.Text.Equals("")==false) {
		   edtEditora.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
		   edtCodEditora.Text,ConsultasSQL.ConsSQL.Editora('S',
		   edtCodEditora.Text,""),"Editora não encontrada!");
		   if (edtEditora.Text.Equals(""))
			 edtCodEditora.Focus();
		  } else
			edtEditora.Clear();
		}

		private void btnPEditora_Click(object sender, System.EventArgs e)
		{
			frmConEditoras pfConEditoras = new frmConEditoras();
			pfConEditoras.ShowDialog();
			edtCodEditora.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtCodEditora_Leave(this,null);
		}

		private void edtPreco_Leave(object sender, System.EventArgs e)
		{
			if (RotinasGlobais.Rotinas.ValidaFloat(edtPreco.Text))
			  edtPreco.Text=RotinasGlobais.Rotinas.VirgulaParaPonto(
				  edtPreco.Text,true);
			else
			  edtPreco.Text="0,00";
		}

		private void edtCodAssunto_Leave(object sender, System.EventArgs e)
		{
		  if (edtCodAssunto.Text.Equals("")==false) {
		   edtAssunto.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
		   edtCodAssunto.Text,ConsultasSQL.ConsSQL.Assunto('S',
		   edtCodAssunto.Text,""),"Assunto não encontrado!");
		   if (edtAssunto.Text.Equals(""))
			 edtCodAssunto.Focus();
		  } else
			edtAssunto.Clear();
		}

		private void edtCodAutor_Leave(object sender, System.EventArgs e)
		{
		  if (edtCodAutor.Text.Equals("")==false) {
		   edtAutor.Text=RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo,
		   edtCodAutor.Text,ConsultasSQL.ConsSQL.Autor('S',
		   edtCodAutor.Text,""),"Autor não encontrado!");
		   if (edtAutor.Text.Equals(""))
			 edtCodAutor.Focus();
		  } else
			edtAutor.Clear();
		}

		private void btnPAssunto_Click(object sender, System.EventArgs e)
		{
			frmConAssuntos pfConAssuntos = new frmConAssuntos();
			pfConAssuntos.ShowDialog();
			edtCodAssunto.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtCodAssunto_Leave(this,null);
		}

		private void btnPAutor_Click(object sender, System.EventArgs e)
		{
			frmConAutores pfConAutores = new frmConAutores();
			pfConAutores.ShowDialog();
			edtCodAutor.Text=RotinasGlobais.Rotinas.sCodigoSelecionado;
			edtCodAutor_Leave(this,null);
		}

		private void btnAdAssuntos_Click(object sender, System.EventArgs e)
		{
			RotinasGlobais.Rotinas.AdicionaItemLista(
			lstAssuntos,slAssuntos,edtCodAssunto,edtAssunto);
		}

		private void lstAssuntos_DoubleClick(object sender, System.EventArgs e)
		{
			RotinasGlobais.Rotinas.RemoveItemLista(lstAssuntos,slAssuntos);
		}

		private void btnAdAutores_Click(object sender, System.EventArgs e)
		{
			RotinasGlobais.Rotinas.AdicionaItemLista(
			lstAutores,slAutores,edtCodAutor,edtAutor);
		}

		private void lstAutores_DoubleClick(object sender, System.EventArgs e)
		{
            RotinasGlobais.Rotinas.RemoveItemLista(lstAutores,slAutores);
		}

	}
}
