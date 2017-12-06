#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "Filha.h"
#include "Sobre.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"

class CfrmPrincipal : public wxMDIParentFrame {
public:
	CfrmPrincipal(wxWindow *parent);
  wxMenu *mnuCadastros;
  wxMenu *mnuPesquisas;
  wxMenu *mnuVendas;
  wxMenu *mnuOpcoes;
  wxMenu *mnuJanelas;
  wxToolBar *barraFerra;
  wxMenuBar *barraMenu;

protected:	
	void OnSize(wxSizeEvent& event);
	void OnClose(wxCloseEvent& event);
	void OnCadAssuntos(wxCommandEvent& event);
  void OnCadAutores(wxCommandEvent& event);
  void OnCadEditoras(wxCommandEvent& event);
  void OnCadEnderecos(wxCommandEvent& event);
  void OnCadIdiomas(wxCommandEvent& event);
  void OnCadPaises(wxCommandEvent& event);
  void OnCadProfissoes(wxCommandEvent& event);
  void OnCadClientes(wxCommandEvent& event);
  void OnCadLivros(wxCommandEvent& event);
  void OnConAssuntos(wxCommandEvent& event);
  void OnConAutores(wxCommandEvent& event);
  void OnConEditoras(wxCommandEvent& event);
  void OnConEnderecos(wxCommandEvent& event);
  void OnConIdiomas(wxCommandEvent& event);
  void OnConPaises(wxCommandEvent& event);
  void OnConProfissoes(wxCommandEvent& event);
  void OnConClientes(wxCommandEvent& event);
  void OnConLivros(wxCommandEvent& event);
  void OnVenderLivros(wxCommandEvent& event);
  void OnVendasRealizadas(wxCommandEvent& event);
	void OnAlterarSenha(wxCommandEvent& event);
	void OnSobre(wxCommandEvent& event);
	void OnSair(wxCommandEvent& event);

private:
  CfrmFilha *frmFilha;
  CfrmSobre *frmSobre;
  CfrmConAssuntos *frmConAssuntos;
  CfrmConAutores *frmConAutores;
  CfrmConEditoras *frmConEditoras;
  CfrmConEnderecos *frmConEnderecos;
  CfrmConIdiomas *frmConIdiomas;
  CfrmConPaises *frmConPaises;
  CfrmConProfissoes *frmConProfissoes;
  CfrmConClientes *frmConClientes;
  CfrmConLivros *frmConLivros;

	void IniciaControles();
	void IniciaBarraFerramentas(wxToolBar* toolBar);

	DECLARE_EVENT_TABLE();
};

enum
{
  MNU_CAD_ASSUNTOS = 100, MNU_CAD_AUTORES, MNU_CAD_EDITORAS, 
  MNU_CAD_ENDERECOS, MNU_CAD_IDIOMAS, MNU_CAD_PAISES, MNU_CAD_PROFISSOES,
	MNU_CAD_CLIENTES, MNU_CAD_LIVROS, MNU_CON_ASSUNTOS, MNU_CON_AUTORES,
	MNU_CON_EDITORAS, MNU_CON_ENDERECOS, MNU_CON_IDIOMAS, MNU_CON_PAISES,
	MNU_CON_PROFISSOES, MNU_CON_CLIENTES, MNU_CON_LIVROS,	MNU_VEN_VENDERLIVROS,
	MNU_VEN_VENDASREALIZADAS, MNU_JAN_LADOALADO_HORZ, MNU_JAN_LADOALADO_VERT,
  MNU_JAN_EM_CASCATA, MNU_JAN_ORGANIZAR_ICONES, MNU_OP_ALTERARSENHA,
  MNU_OP_SOBRE, MNU_OP_SAIR
};

extern CfrmPrincipal *frmPrincipal;

#endif

