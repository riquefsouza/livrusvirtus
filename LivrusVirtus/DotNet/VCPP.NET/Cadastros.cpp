#include "StdAfx.h"
#include "Cadastros.h"
#include "Principal.h" 
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

namespace Livrus
{

  frmCadastros::frmCadastros()
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
  Void frmCadastros::Dispose (Boolean disposing)
  {
  	if (disposing && components)
  		components->Dispose();
  
  	__super::Dispose(disposing);

  }
  
  Void frmCadastros::InitializeComponent()
  {
  	this->labCodigo = new System::Windows::Forms::Label();
  	this->edtCodigo = new System::Windows::Forms::TextBox();
  	this->labDescricao = new System::Windows::Forms::Label();
  	this->edtDescricao = new System::Windows::Forms::TextBox();
  	this->btnNovo = new System::Windows::Forms::Button();
  	this->btnPesquisar = new System::Windows::Forms::Button();
  	this->btnAnterior = new System::Windows::Forms::Button();
  	this->btnProximo = new System::Windows::Forms::Button();
  	this->btnFechar = new System::Windows::Forms::Button();
  	this->btnLimpar = new System::Windows::Forms::Button();
  	this->btnExcluir = new System::Windows::Forms::Button();
  	this->btnSalvar = new System::Windows::Forms::Button();
  	this->Arquiva = new System::Data::OleDb::OleDbCommand();
  	this->SuspendLayout();
  	// 
  	// labCodigo
  	// 
  	this->labCodigo->Location = System::Drawing::Point(8, 8);
  	this->labCodigo->Name = S"labCodigo";
  	this->labCodigo->Size = System::Drawing::Size(56, 16);
  	this->labCodigo->TabIndex = 0;
  	this->labCodigo->Text = S"Código:";
  	// 
  	// edtCodigo
  	// 
  	this->edtCodigo->Location = System::Drawing::Point(8, 24);
  	this->edtCodigo->Name = S"edtCodigo";
	this->edtCodigo->MaxLength = 10;
  	this->edtCodigo->Size = System::Drawing::Size(128, 20);
  	this->edtCodigo->TabIndex = 1;
  	this->edtCodigo->Text = S"";
  	// 
  	// labDescricao
  	// 
  	this->labDescricao->Location = System::Drawing::Point(8, 48);
  	this->labDescricao->Name = S"labDescricao";
  	this->labDescricao->Size = System::Drawing::Size(64, 16);
  	this->labDescricao->TabIndex = 3;
  	this->labDescricao->Text = S"Descrição:";
  	// 
  	// edtDescricao
  	// 
  	this->edtDescricao->Enabled = false;
  	this->edtDescricao->Location = System::Drawing::Point(8, 64);
  	this->edtDescricao->Name = S"edtDescricao";
	this->edtDescricao->MaxLength = 30;
  	this->edtDescricao->Size = System::Drawing::Size(232, 20);
  	this->edtDescricao->TabIndex = 4;
  	this->edtDescricao->Text = S"";
  	// 
  	// btnNovo
  	// 
  	this->btnNovo->Location = System::Drawing::Point(152, 24);
  	this->btnNovo->Name = S"btnNovo";
  	this->btnNovo->TabIndex = 2;
  	this->btnNovo->Text = S"&Novo";
  	this->btnNovo->Click += new System::EventHandler(this,btnNovo_Click);
  	// 
  	// btnPesquisar
  	// 
  	this->btnPesquisar->Location = System::Drawing::Point(256, 8);
  	this->btnPesquisar->Name = S"btnPesquisar";
  	this->btnPesquisar->TabIndex = 5;
  	this->btnPesquisar->Text = S"&Pesquisar";
  	// 
  	// btnAnterior
  	// 
  	this->btnAnterior->Enabled = false;
  	this->btnAnterior->Location = System::Drawing::Point(256, 40);
  	this->btnAnterior->Name = S"btnAnterior";
  	this->btnAnterior->TabIndex = 6;
  	this->btnAnterior->Text = S"&Anterior";
  	this->btnAnterior->Click += new System::EventHandler(this,btnAnterior_Click);
  	// 
  	// btnProximo
  	// 
  	this->btnProximo->Enabled = false;
  	this->btnProximo->Location = System::Drawing::Point(256, 72);
  	this->btnProximo->Name = S"btnProximo";
  	this->btnProximo->TabIndex = 7;
  	this->btnProximo->Text = S"Próxi&mo";
  	this->btnProximo->Click += new System::EventHandler(this,btnProximo_Click);
  	// 
  	// btnFechar
  	// 
  	this->btnFechar->DialogResult = System::Windows::Forms::DialogResult::Cancel;
  	this->btnFechar->Location = System::Drawing::Point(256, 104);
  	this->btnFechar->Name = S"btnFechar";
  	this->btnFechar->TabIndex = 11;
  	this->btnFechar->Text = S"&Fechar";
  	this->btnFechar->Click += new System::EventHandler(this,btnFechar_Click);
  	// 
  	// btnLimpar
  	// 
  	this->btnLimpar->Location = System::Drawing::Point(176, 104);
  	this->btnLimpar->Name = S"btnLimpar";
  	this->btnLimpar->TabIndex = 10;
  	this->btnLimpar->Text = S"&Limpar";
  	this->btnLimpar->Click += new System::EventHandler(this,btnLimpar_Click);
  	// 
  	// btnExcluir
  	// 
  	this->btnExcluir->Enabled = false;
  	this->btnExcluir->Location = System::Drawing::Point(96, 104);
  	this->btnExcluir->Name = S"btnExcluir";
  	this->btnExcluir->TabIndex = 9;
  	this->btnExcluir->Text = S"&Excluir";
  	// 
  	// btnSalvar
  	// 
  	this->btnSalvar->Enabled = false;
  	this->btnSalvar->Location = System::Drawing::Point(16, 104);
  	this->btnSalvar->Name = S"btnSalvar";
  	this->btnSalvar->TabIndex = 8;
  	this->btnSalvar->Text = S"&Salvar";
  	// 
  	// frmCadastros
  	// 
  	this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
  	this->CancelButton = this->btnFechar;
  	this->ClientSize = System::Drawing::Size(336, 133);
  	this->Controls->Add(this->btnSalvar);
  	this->Controls->Add(this->btnExcluir);
  	this->Controls->Add(this->btnLimpar);
  	this->Controls->Add(this->btnFechar);
  	this->Controls->Add(this->btnProximo);
  	this->Controls->Add(this->btnAnterior);
  	this->Controls->Add(this->btnPesquisar);
  	this->Controls->Add(this->btnNovo);
  	this->Controls->Add(this->edtDescricao);
  	this->Controls->Add(this->labDescricao);
  	this->Controls->Add(this->edtCodigo);
  	this->Controls->Add(this->labCodigo);
  	this->Name = S"frmCadastros";
  	this->Text = S"Cadastro de";
  	this->Closing += new System::ComponentModel::CancelEventHandler(this,frmCadastros_Closing);
  	this->MouseMove += new System::Windows::Forms::MouseEventHandler(this,frmCadastros_MouseMove);
  	this->ResumeLayout(false);
  }
  
  Void frmCadastros::btnFechar_Click(Object* sender, System::EventArgs* e)
  {
  	Close();
  }
  
  Boolean frmCadastros::ValidaDados(Boolean bTodosDados)
  {
  	return true;
  }
  
  Void frmCadastros::InformaLimpaDados(Boolean bInformar)
  {
  	if (bInformar) {
  	  Campos = dynamic_cast<ArrayList*>(Registros->Item[nLinhaRegistro]);
  	  edtCodigo->Text=Campos->Item[0]->ToString();
  	  edtDescricao->Text=Campos->Item[1]->ToString();
  	} else {
  	  edtCodigo->Text="";
  	  edtDescricao->Text="";
  	  edtCodigo->Enabled=true;
  	  edtCodigo->Focus();
  	}
  }
  
  Void frmCadastros::HabilitaDados(Boolean bHabilita)
  {
  	edtDescricao->Enabled=bHabilita;
  }
  
  Void frmCadastros::btnNovo_Click(Object* sender, System::EventArgs* e)
  {
  	btnSalvar->Enabled=true;
  	btnExcluir->Enabled=false;
  	btnPesquisar->Enabled=false;
  	btnAnterior->Enabled=false;
  	btnProximo->Enabled=false;
  	btnNovo->Enabled=false;
  
  	InformaLimpaDados(false);
  	HabilitaDados(true);
  }
  
  Void frmCadastros::NovoDado(String* sTextoSql)
  {
  	 if (RotinasGlobais::Rotinas->ConsultaDados(Registros, sTextoSql)) {
  		Campos = dynamic_cast<ArrayList*>(Registros->Item[0]);
  		edtCodigo->Text = Campos->Item[0]->ToString();
  		edtCodigo->Enabled = false;
  		edtDescricao->Focus();
  	 }
  }
  
  Void frmCadastros::btnLimpar_Click(Object* sender, System::EventArgs* e)
  {
  	btnSalvar->Enabled=false;
  	btnExcluir->Enabled=false;
  	btnPesquisar->Enabled=true;
  	btnAnterior->Enabled=false;
  	btnProximo->Enabled=false;
  	btnNovo->Enabled=true;
  
  	InformaLimpaDados(false);
  	HabilitaDados(false);
  }
  
  Boolean frmCadastros::ExcluirDados(String* sTextoSql)
  {
     if (ValidaDados(false)) {
  
  	 System::Windows::Forms::DialogResult res;
  	 res = MessageBox::Show(this, "Certeza de excluir?",
  	 frmPrincipal::fPrincipal->Text, MessageBoxButtons::YesNo,
  	 MessageBoxIcon::Question, MessageBoxDefaultButton::Button2);
  
  	 if (res == System::Windows::Forms::DialogResult::Yes) {
  		  Arquiva = frmPrincipal::fPrincipal->db->CreateCommand();
  		  Arquiva->CommandText = sTextoSql;
  		  Arquiva->ExecuteNonQuery();
  		  Arquiva->Dispose();
  		  btnLimpar_Click(this,System::EventArgs::Empty);
                  return true;
  	 } else
            return false;
     } else
         return false;
  }
  
  Boolean frmCadastros::PesquisarDados(String* sTextoSql, String* sMensagemErro)
  {
  	if (edtCodigo->Text->Equals(S"")) {
  	  btnAnterior->Enabled=true;
  	  btnProximo->Enabled=true;
  	}
  
  	if (RotinasGlobais::Rotinas->ConsultaDados(Registros,sTextoSql)) {
  	     nLinhaRegistro=0;
  		 InformaLimpaDados(true);
  		 HabilitaDados(true);
  
  		 btnSalvar->Enabled=true;
  		 btnExcluir->Enabled=true;
  		 btnPesquisar->Enabled=false;
             return true;
  	} else {
  	  MessageBox::Show(sMensagemErro, frmPrincipal::fPrincipal->Text,
  	  MessageBoxButtons::OK, MessageBoxIcon::Information);
          return false;
        }
  
  }
  
  Void frmCadastros::registroAnterior()
  {
  	if (nLinhaRegistro > 0) {
          nLinhaRegistro=nLinhaRegistro - 1;
          InformaLimpaDados(true);
  	}
  }

  Void frmCadastros::btnAnterior_Click(Object* sender, System::EventArgs* e)
  {
        registroAnterior();
  }

  Void frmCadastros::registroProximo()
  {
  	if (nLinhaRegistro < (Registros->Count-1)) {
          nLinhaRegistro=nLinhaRegistro + 1;
          InformaLimpaDados(true);
  	}
  }
  
  Void frmCadastros::btnProximo_Click(Object* sender, System::EventArgs* e)
  {
        registroProximo();
  }
  
  Boolean frmCadastros::SalvarDados(String* sTextoSql,String* sTextoUpdate,
  			   String* sTextoInsert, Boolean bLimparDados)
  {
  	if (ValidaDados(true)) {
  	   Arquiva = frmPrincipal::fPrincipal->db->CreateCommand();
  	   if (RotinasGlobais::Rotinas->ConsultaDados(Arquiva,sTextoSql)) {
  		 Arquiva->CommandText = sTextoUpdate;
  	   } else {
  		 Arquiva->CommandText = sTextoInsert;
  	   }
  	   Arquiva->ExecuteNonQuery();
  	   Arquiva->Dispose();
  	   if (bLimparDados) {
 		btnLimpar_Click(this,System::EventArgs::Empty);
                return true;
           } else 
               return false;
  	} else
            return false;
  }
  
  Void frmCadastros::edtCodigoLeave()
  {
    if (edtCodigo->Text!="") {
  	if (RotinasGlobais::Rotinas->ValidaInteger(edtCodigo->Text)==false) {
  	  edtCodigo->Text="";
  	  edtCodigo->Focus();
  	}
    }
  }
  
  Void frmCadastros::frmCadastros_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e)
  {
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text=Text;
  }
  
  Void frmCadastros::frmCadastros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e)
  {
  	frmPrincipal::fPrincipal->statusBar1->Panels->Item[1]->Text="";
  }

}
