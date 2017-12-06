#ifndef FILHA_H
#define FILHA_H

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

class CfrmFilha: public wxMDIChildFrame {
public:
    CfrmFilha(wxMDIParentFrame *parent, int nTelaAtiva);
    ~CfrmFilha();

protected:
    CfrmCadAssuntos *frmCadAssuntos;
    CfrmCadAutores *frmCadAutores;
    CfrmCadEditoras *frmCadEditoras;
    CfrmCadEnderecos *frmCadEnderecos;
    CfrmCadIdiomas *frmCadIdiomas;
    CfrmCadPaises *frmCadPaises;
    CfrmCadProfissoes *frmCadProfissoes;
    CfrmCadClientes *frmCadClientes;
    CfrmCadLivros *frmCadLivros;
    CfrmVenderLivros *frmVenderLivros;
    CfrmConVendas *frmConVendas;
    CfrmAlterarSenha *frmAlterarSenha;    
    
    void OnClose(wxCloseEvent& event);

private:
  int nLocalTelaAtiva;
	void IniciaControles();	

  DECLARE_EVENT_TABLE();   
};

#endif


