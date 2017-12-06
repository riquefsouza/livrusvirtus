#pragma once

#include "CadAssuntos.h"
#include "CadAutores.h"
#include "CadEditoras.h"
#include "CadEnderecos.h"
#include "CadIdiomas.h"
#include "CadPaises.h"
#include "CadProfissoes.h"
#include "CadClientes.h"
#include "CadLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"
#include "AlterarSenha.h"

namespace Livrus
{
	public __gc class frmFilha : public wx::MDIChildFrame
	{
    public:	
      frmFilha( wx::MDIParentFrame* parent, int nTelaAtiva );
      System::Void OnActivate( System::Object* sender, wx::Event* e );
      System::Void OnClose( System::Object* sender, wx::Event* e );
    private:
      int nLocalTelaAtiva;
      frmCadAssuntos* fCadAssuntos;
      frmCadAutores* fCadAutores;
      frmCadEditoras* fCadEditoras;
      frmCadEnderecos* fCadEnderecos;
      frmCadIdiomas* fCadIdiomas;
      frmCadPaises* fCadPaises;
      frmCadProfissoes* fCadProfissoes;
      frmCadClientes* fCadClientes;
      frmCadLivros* fCadLivros;
      frmVenderLivros* fVenderLivros;
      frmConVendas* fConVendas;
      frmAlterarSenha* fAlterarSenha;
  };
}
