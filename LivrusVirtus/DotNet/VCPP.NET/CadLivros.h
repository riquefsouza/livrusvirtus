#pragma once

namespace Livrus
{
  public __gc class frmCadLivros : public Livrus::frmCadastros
  {
  public:
	static frmCadLivros* fCadLivros;
	frmCadLivros();
  private: 
        ArrayList* slIdiomas;
        ArrayList* slAssuntos;
        ArrayList* slAutores;
        ArrayList* ConsCampo;
        ArrayList* ConsLista;
	System::ComponentModel::IContainer* components;
	System::Windows::Forms::Label* labEdicao;
	System::Windows::Forms::NumericUpDown* edtEdicao;
	System::Windows::Forms::NumericUpDown* edtAnoPubli;
	System::Windows::Forms::Label* labAnoPubli;
	System::Windows::Forms::Button* btnPAssunto;
	System::Windows::Forms::TextBox* edtAssunto;
	System::Windows::Forms::TextBox* edtCodAssunto;
	System::Windows::Forms::Label* labAssunto;
	System::Windows::Forms::Button* btnPEditora;
	System::Windows::Forms::TextBox* edtEditora;
	System::Windows::Forms::TextBox* edtCodEditora;
	System::Windows::Forms::Label* labEditora;
	System::Windows::Forms::Button* btnAdAssuntos;
	System::Windows::Forms::NumericUpDown* edtVolume;
	System::Windows::Forms::Label* labVolume;
	System::Windows::Forms::NumericUpDown* edtNPaginas;
	System::Windows::Forms::Label* labNPaginas;
	System::Windows::Forms::Label* labIdioma;
	System::Windows::Forms::ComboBox* cmbIdioma;
	System::Windows::Forms::ListBox* lstAssuntos;
	System::Windows::Forms::Label* labPreco;
	System::Windows::Forms::TextBox* edtPreco;
	System::Windows::Forms::NumericUpDown* edtQtdEstoque;
	System::Windows::Forms::Label* labQtdEstoque;
	System::Windows::Forms::ListBox* lstAutores;
	System::Windows::Forms::Button* btnAdAutores;
	System::Windows::Forms::Button* btnPAutor;
	System::Windows::Forms::TextBox* edtAutor;
	System::Windows::Forms::TextBox* edtCodAutor;
	System::Windows::Forms::Label* labAutor;
  	Void InitializeComponent();
        Void btnLimpar_Click(Object* sender, System::EventArgs* e);
  	Void btnExcluir_Click(Object* sender, System::EventArgs* e);
  	Void btnPesquisar_Click(Object* sender, System::EventArgs* e);
  	Void btnAnterior_Click(Object* sender, System::EventArgs* e);
  	Void btnProximo_Click(Object* sender, System::EventArgs* e); 
  	Void btnSalvar_Click(Object* sender, System::EventArgs* e);
  	Void frmCadLivros_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
	Void btnFechar_Click(Object* sender, System::EventArgs* e);
	Void frmCadLivros_Load(Object* sender, System::EventArgs* e);
	Void AdicionaCombo();
	Void SalvaLista(char sOpcao);
	Void edtCodEditora_Leave(Object* sender, System::EventArgs* e);
	Void btnPEditora_Click(Object* sender, System::EventArgs* e);
	Void edtPreco_Leave(Object* sender, System::EventArgs* e);
	Void edtCodAssunto_Leave(Object* sender, System::EventArgs* e);
	Void edtCodAutor_Leave(Object* sender, System::EventArgs* e);
	Void btnPAssunto_Click(Object* sender, System::EventArgs* e);
	Void btnPAutor_Click(Object* sender, System::EventArgs* e);
	Void btnAdAssuntos_Click(Object* sender, System::EventArgs* e);
	Void lstAssuntos_DoubleClick(Object* sender, System::EventArgs* e);
	Void btnAdAutores_Click(Object* sender, System::EventArgs* e);
	Void lstAutores_DoubleClick(Object* sender, System::EventArgs* e);
  protected: 
	Void Dispose (Boolean disposing);
  	Boolean ValidaDados(Boolean bTodosDados);
	Void InformaLimpaDados(Boolean bInformar);
	Void HabilitaDados(Boolean bHabilita);
	Void edtCodigo_Leave(Object* sender, System::EventArgs* e);
	Void btnNovo_Click(Object* sender, System::EventArgs* e);
  };

}
