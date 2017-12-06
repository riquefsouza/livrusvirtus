#pragma once

namespace Livrus
{
	public __gc class frmPrincipal : public wx::MDIParentFrame
	{
    private:
      wx::Menu* mnuCadastros;
      wx::Menu* mnuPesquisas;
      wx::Menu* mnuVendas;
      wx::Menu* mnuOpcoes;
      wx::StatusBar* barraStatus;
      int nLarguras __gc[];
      System::Void FazLayout();
      System::Void OnClose( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadAssuntos( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadAutores( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadEditoras( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadEnderecos( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadIdiomas( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadPaises( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadProfissoes( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadClientes( System::Object* sender, wx::Event* e );
      System::Void OnMnuCadLivros( System::Object* sender, wx::Event* e );
      System::Void OnMnuConAssuntos( System::Object* sender, wx::Event* e );
      System::Void OnMnuConAutores( System::Object* sender, wx::Event* e );
      System::Void OnMnuConEditoras( System::Object* sender, wx::Event* e );
      System::Void OnMnuConEnderecos( System::Object* sender, wx::Event* e );
      System::Void OnMnuConIdiomas( System::Object* sender, wx::Event* e );
      System::Void OnMnuConPaises( System::Object* sender, wx::Event* e );
      System::Void OnMnuConProfissoes( System::Object* sender, wx::Event* e );
      System::Void OnMnuConClientes( System::Object* sender, wx::Event* e );
      System::Void OnMnuConLivros( System::Object* sender, wx::Event* e );
      System::Void OnMnuVenderLivros( System::Object* sender, wx::Event* e );
      System::Void OnMnuVendasRealizadas( System::Object* sender, wx::Event* e );
      System::Void OnMnuAlterarSenha( System::Object* sender, wx::Event* e );
      System::Void OnMnuSobre( System::Object* sender, wx::Event* e );

		public:	
  		static frmPrincipal* fPrincipal;
      wx::MenuBar* barraMenu;
      wx::ToolBar* barraFerra;

      frmPrincipal();
  };
}
