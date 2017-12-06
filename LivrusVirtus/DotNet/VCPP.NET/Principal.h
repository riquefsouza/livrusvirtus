#pragma once

namespace Livrus
{
	public __gc class frmPrincipal : public System::Windows::Forms::Form
	{
	public:
		static frmPrincipal* fPrincipal;

		System::Windows::Forms::StatusBar* statusBar1;
		System::Data::OleDb::OleDbConnection* db;

		System::Windows::Forms::ToolBarButton* tlbClientes;
		System::Windows::Forms::ToolBarButton* tlbLivros;
		System::Windows::Forms::ToolBarButton* tlbVender;
		System::Windows::Forms::MenuItem* mnuCadAssuntos;
		System::Windows::Forms::MenuItem* mnuCadAutores;
		System::Windows::Forms::MenuItem* mnuCadEditoras;
		System::Windows::Forms::MenuItem* mnuCadEnderecos;
		System::Windows::Forms::MenuItem* mnuCadIdiomas;
		System::Windows::Forms::MenuItem* mnuCadPaises;
		System::Windows::Forms::MenuItem* mnuCadProfissoes;
		System::Windows::Forms::MenuItem* mnuCadClientes;
		System::Windows::Forms::MenuItem* mnuCadLivros;
		System::Windows::Forms::MenuItem* mnuConAssuntos;
		System::Windows::Forms::MenuItem* mnuConAutores;
		System::Windows::Forms::MenuItem* mnuConEditoras;
		System::Windows::Forms::MenuItem* mnuConEnderecos;
		System::Windows::Forms::MenuItem* mnuConIdiomas;
		System::Windows::Forms::MenuItem* mnuConPaises;
		System::Windows::Forms::MenuItem* mnuConProfissoes;
		System::Windows::Forms::MenuItem* mnuConClientes;
		System::Windows::Forms::MenuItem* mnuConLivros;
		System::Windows::Forms::MenuItem* mnuVenderLivros;
		System::Windows::Forms::MenuItem* mnuVendasRealizadas;
		System::Windows::Forms::MenuItem* mnuAlterarSenha;
	private:	
		System::ComponentModel::IContainer* components;
		System::Windows::Forms::MainMenu* mainMenu1;
		System::Windows::Forms::MenuItem* mnuCadastros;
		System::Windows::Forms::StatusBarPanel* statusBarPanel1;
		System::Windows::Forms::StatusBarPanel* statusBarPanel2;
		System::Windows::Forms::ToolBar* toolBar1;
		System::Windows::Forms::ToolBarButton* toolBarButton4;
		System::Windows::Forms::ToolBarButton* tlbSobre;
		System::Windows::Forms::ToolBarButton* tlbSair;
		System::Windows::Forms::ImageList* imageList1;
		System::Windows::Forms::MenuItem* menuItem1;
		System::Windows::Forms::MenuItem* mnuPesquisas;
		System::Windows::Forms::MenuItem* menuItem2;
		System::Windows::Forms::MenuItem* mnuVendas;
		System::Windows::Forms::MenuItem* mnuJanelas;
		System::Windows::Forms::MenuItem* mnuLadoALadoHorizontal;
		System::Windows::Forms::MenuItem* mnuLadoALadoVertical;
		System::Windows::Forms::MenuItem* mnuEmCascata;
		System::Windows::Forms::MenuItem* mnuOrganizarIcones;
		System::Windows::Forms::MenuItem* mnuOpcoes;
		System::Windows::Forms::MenuItem* menuItem3;
		System::Windows::Forms::MenuItem* mnuSobre;
		System::Windows::Forms::MenuItem* mnuSair;

	public:
		frmPrincipal(void);
	protected:
		// Form overrides dispose to clean up the component list.
		System::Void Dispose(System::Boolean disposing);
	private:
		System::Void InitializeComponent();
		System::Void frmPrincipal_Closing(Object* sender, System::ComponentModel::CancelEventArgs* e);
		System::Void toolBar1_ButtonClick(Object* sender, System::Windows::Forms::ToolBarButtonClickEventArgs* e);
		System::Void frmPrincipal_Load(Object* sender, System::EventArgs* e);
		System::Void mnuSair_Click(Object* sender, System::EventArgs* e);
		System::Void mnuLadoALadoHorizontal_Click(Object* sender, System::EventArgs* e);
		System::Void mnuLadoALadoVertical_Click(Object* sender, System::EventArgs* e);
		System::Void mnuEmCascata_Click(Object* sender, System::EventArgs* e);
		System::Void mnuOrganizarIcones_Click(Object* sender, System::EventArgs* e);
		System::Void mnuSobre_Click(Object* sender, System::EventArgs* e);
		System::Void frmPrincipal_MouseMove(Object* sender, System::Windows::Forms::MouseEventArgs* e);
		System::Void mnuAlterarSenha_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadAssuntos_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConAssuntos_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadAutores_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConAutores_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadEditoras_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConEditoras_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadEnderecos_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConEnderecos_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadIdiomas_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConIdiomas_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadPaises_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConPaises_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadProfissoes_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConProfissoes_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadClientes_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConClientes_Click(Object* sender, System::EventArgs* e);
		System::Void mnuCadLivros_Click(Object* sender, System::EventArgs* e);
		System::Void mnuConLivros_Click(Object* sender, System::EventArgs* e);
		System::Void mnuVenderLivros_Click(Object* sender, System::EventArgs* e);
		System::Void mnuVendasRealizadas_Click(Object* sender, System::EventArgs* e);

	};
}
