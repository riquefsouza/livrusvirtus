using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Data.OleDb;

namespace Livrus
{
	/// <summary>
	/// Summary description for WinForm.
	/// </summary>
	public class frmLogin : System.Windows.Forms.Form
	{
		public static frmLogin fLogin;
		private bool bFecharOuTerminar;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.Container components = null;
		private System.Windows.Forms.TextBox edtLogin;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.Label label3;
		private System.Windows.Forms.TextBox edtSenha;
		private System.Windows.Forms.Button btnLogin;
		private System.Windows.Forms.Button btnCancelar;
		private System.Data.OleDb.OleDbCommand Consulta;

		public frmLogin()
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
			System.Resources.ResourceManager resources = new System.Resources.ResourceManager(typeof(frmLogin));
			this.edtLogin = new System.Windows.Forms.TextBox();
			this.label1 = new System.Windows.Forms.Label();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.edtSenha = new System.Windows.Forms.TextBox();
			this.btnLogin = new System.Windows.Forms.Button();
			this.btnCancelar = new System.Windows.Forms.Button();
			this.Consulta = new System.Data.OleDb.OleDbCommand();
			this.SuspendLayout();
			// 
			// edtLogin
			// 
			this.edtLogin.Location = new System.Drawing.Point(112, 32);
			this.edtLogin.MaxLength = 10;
			this.edtLogin.Name = "edtLogin";
			this.edtLogin.Size = new System.Drawing.Size(80, 20);
			this.edtLogin.TabIndex = 2;
			this.edtLogin.Text = "";
			// 
			// label1
			// 
			this.label1.BackColor = System.Drawing.Color.Transparent;
			this.label1.Image = ((System.Drawing.Image)(resources.GetObject("label1.Image")));
			this.label1.Location = new System.Drawing.Point(8, 8);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(96, 96);
			this.label1.TabIndex = 0;
			// 
			// label2
			// 
			this.label2.Location = new System.Drawing.Point(112, 16);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(64, 16);
			this.label2.TabIndex = 1;
			this.label2.Text = "Login:";
			// 
			// label3
			// 
			this.label3.Location = new System.Drawing.Point(112, 64);
			this.label3.Name = "label3";
			this.label3.Size = new System.Drawing.Size(64, 16);
			this.label3.TabIndex = 3;
			this.label3.Text = "Senha:";
			// 
			// edtSenha
			// 
			this.edtSenha.Location = new System.Drawing.Point(112, 80);
			this.edtSenha.MaxLength = 10;
			this.edtSenha.Name = "edtSenha";
			this.edtSenha.PasswordChar = '*';
			this.edtSenha.Size = new System.Drawing.Size(80, 20);
			this.edtSenha.TabIndex = 4;
			this.edtSenha.Text = "";
			// 
			// btnLogin
			// 
			this.btnLogin.Location = new System.Drawing.Point(24, 112);
			this.btnLogin.Name = "btnLogin";
			this.btnLogin.TabIndex = 5;
			this.btnLogin.Text = "&Login";
			this.btnLogin.Click += new System.EventHandler(this.btnLogin_Click);
			// 
			// btnCancelar
			// 
			this.btnCancelar.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.btnCancelar.Location = new System.Drawing.Point(104, 112);
			this.btnCancelar.Name = "btnCancelar";
			this.btnCancelar.TabIndex = 6;
			this.btnCancelar.Text = "&Cancelar";
			this.btnCancelar.Click += new System.EventHandler(this.btnCancelar_Click);
			// 
			// frmLogin
			// 
			this.AcceptButton = this.btnLogin;
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.CancelButton = this.btnCancelar;
			this.ClientSize = new System.Drawing.Size(202, 143);
			this.Controls.Add(this.btnCancelar);
			this.Controls.Add(this.btnLogin);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.edtSenha);
			this.Controls.Add(this.edtLogin);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "frmLogin";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Login do sistema";
			this.Closing += new System.ComponentModel.CancelEventHandler(this.frmLogin_Closing);
			this.Load += new System.EventHandler(this.frmLogin_Load);
			this.ResumeLayout(false);
		}
		#endregion

		private void frmLogin_Load(object sender, System.EventArgs e)
		{
			bFecharOuTerminar=false;
		}

		private void frmLogin_Closing(object sender, System.ComponentModel.CancelEventArgs e)
		{
			if (bFecharOuTerminar)
			  e.Cancel=false;
			else
			  Application.Exit();

		}
		
		private void btnLogin_Click(object sender, System.EventArgs e)
		{
			if (RotinasGlobais.Rotinas.ConsultaDados(Consulta,
			 ConsultasSQL.ConsSQL.Usuario('S',edtLogin.Text,edtSenha.Text))) {
			 RotinasGlobais.Rotinas.sUsuarioLogin=edtLogin.Text;
			 RotinasGlobais.Rotinas.sUsuarioSenha=edtSenha.Text;
			 frmPrincipal.fPrincipal.statusBar1.Panels[0].Text=
				"Usuário: "+edtLogin.Text;
			 bFecharOuTerminar=true;
			 Close();
			} else
			  MessageBox.Show("Login ou senha incorretos!",
			  frmPrincipal.fPrincipal.Text, MessageBoxButtons.OK,
			  MessageBoxIcon.Information);

		}

		private void btnCancelar_Click(object sender, System.EventArgs e)
		{
			bFecharOuTerminar=false;
			Close();
		}
	}
}
