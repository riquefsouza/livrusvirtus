#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include "resource.h"

class CfrmPrincipal : public Fl_Double_Window {
public:
	CfrmPrincipal();
  Fl_Menu_Item *mnuCadAssuntos;
  Fl_Menu_Item *mnuCadAutores;
  Fl_Menu_Item *mnuCadEditoras;
  Fl_Menu_Item *mnuCadEnderecos;
  Fl_Menu_Item *mnuCadIdiomas;
  Fl_Menu_Item *mnuCadPaises;
  Fl_Menu_Item *mnuCadProfissoes;
  Fl_Menu_Item *mnuCadClientes;
  Fl_Menu_Item *mnuCadLivros;
  Fl_Menu_Item *mnuConAssuntos;
  Fl_Menu_Item *mnuConAutores;
  Fl_Menu_Item *mnuConEditoras;
  Fl_Menu_Item *mnuConEnderecos;
  Fl_Menu_Item *mnuConIdiomas;
  Fl_Menu_Item *mnuConPaises;
  Fl_Menu_Item *mnuConProfissoes;
  Fl_Menu_Item *mnuConClientes;
  Fl_Menu_Item *mnuConLivros;
  Fl_Menu_Item *mnuVenVenderLivros;
  Fl_Menu_Item *mnuVenVendasRealizadas;
  Fl_Menu_Item *mnuOpAlterarSenha;
  Fl_Button *tlbClientes;
  Fl_Button *tlbLivros;
  Fl_Button *tlbVenda;
  //Fl_Text_Display *BarraDeStatus;
  Fl_Box *BarraDeStatus1;
  Fl_Box *BarraDeStatus2;
  static Fl_Menu_Item menu_BarraDeMenu[];
  void OnSair();
  int handle(int event);

protected:	
  Fl_Menu_Bar *BarraDeMenu;
  Fl_Menu_Item *mnuCadastros;
  Fl_Menu_Item *mnuPesquisas;
  Fl_Menu_Item *mnuVendas;
  Fl_Menu_Item *mnuOpcoes;
  Fl_Menu_Item *mnuOpSobre;
  Fl_Menu_Item *mnuOpSair;

  Fl_Group *BarraDeFerra;
  Fl_Button *tlbSobre;
  Fl_Button *tlbSair;

private:
	void IniciaControles();

};

extern CfrmPrincipal *frmPrincipal;

#endif
