#include "Principal.h"
#include "CadAssuntos.h"
#include "CadAutores.h"
#include "CadEditoras.h"
#include "CadEnderecos.h"
#include "CadIdiomas.h"
#include "CadPaises.h"
#include "CadProfissoes.h"
#include "CadClientes.h"
#include "CadLivros.h"
#include "ConAssuntos.h"
#include "ConAutores.h"
#include "ConEditoras.h"
#include "ConEnderecos.h"
#include "ConIdiomas.h"
#include "ConPaises.h"
#include "ConProfissoes.h"
#include "ConClientes.h"
#include "ConLivros.h"
#include "VenderLivros.h"
#include "ConVendas.h"
#include "Sobre.h"
#include "AlterarSenha.h"

CfrmPrincipal *frmPrincipal;

Fl_Pixmap image_dsair(idata_dsair);
Fl_Pixmap image_cliente(idata_cliente);
Fl_Pixmap image_dcliente(idata_dcliente);
Fl_Pixmap image_livro(idata_livro);
Fl_Pixmap image_dlivro(idata_dlivro);
Fl_Pixmap image_livros(idata_livros);
Fl_Pixmap image_dlivros(idata_dlivros);
Fl_Pixmap image_sobre(idata_sobre);
Fl_Pixmap image_dsobre(idata_dsobre);
Fl_Pixmap image_sair(idata_sair);

void frmPrincipal_mnuCadAssuntos_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadAutores_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadEditoras_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadEnderecos_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadIdiomas_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadPaises_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadProfissoes_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadClientes_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuCadLivros_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConAssuntos_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConAutores_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConEditoras_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConEnderecos_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConIdiomas_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConPaises_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConProfissoes_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConClientes_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuConLivros_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuVenVenderLivros_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuVenVendasRealizadas_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuOpAlterarSenha_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuOpSobre_cb(Fl_Widget* w, void* v);
void frmPrincipal_mnuOpSair_cb(Fl_Widget*, void*);

Fl_Menu_Item CfrmPrincipal::menu_BarraDeMenu[] = {
 {"&Cadastros", 0,  0, 0, 64, 0, 0, 14, 56},
 {"&Assuntos", 0,  (Fl_Callback*)frmPrincipal_mnuCadAssuntos_cb, 0, 0, 0, 0, 14, 56},
 {"A&utores", 0,  (Fl_Callback*)frmPrincipal_mnuCadAutores_cb, 0, 0, 0, 0, 14, 56},
 {"&Editoras", 0,  (Fl_Callback*)frmPrincipal_mnuCadEditoras_cb, 0, 0, 0, 0, 14, 56},
 {"E&ndere\347os", 0,  (Fl_Callback*)frmPrincipal_mnuCadEnderecos_cb, 0, 0, 0, 0, 14, 56},
 {"&Idiomas", 0,  (Fl_Callback*)frmPrincipal_mnuCadIdiomas_cb, 0, 0, 0, 0, 14, 56},
 {"&Pa\355ses", 0,  (Fl_Callback*)frmPrincipal_mnuCadPaises_cb, 0, 0, 0, 0, 14, 56},
 {"P&rofiss\365""es", 0,  (Fl_Callback*)frmPrincipal_mnuCadProfissoes_cb, 0, 128, 0, 0, 14, 56},
 {"&Clientes", 0,  (Fl_Callback*)frmPrincipal_mnuCadClientes_cb, 0, 0, 0, 0, 14, 56},
 {"&Livros", 0,  (Fl_Callback*)frmPrincipal_mnuCadLivros_cb, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {"&Pesquisas", 0,  0, 0, 64, 0, 0, 14, 56},
 {"&Assuntos", 0,  (Fl_Callback*)frmPrincipal_mnuConAssuntos_cb, 0, 0, 0, 0, 14, 56},
 {"A&utores", 0,  (Fl_Callback*)frmPrincipal_mnuConAutores_cb, 0, 0, 0, 0, 14, 56},
 {"&Editoras", 0,  (Fl_Callback*)frmPrincipal_mnuConEditoras_cb, 0, 0, 0, 0, 14, 56},
 {"E&ndere\347os", 0,  (Fl_Callback*)frmPrincipal_mnuConEnderecos_cb, 0, 0, 0, 0, 14, 56},
 {"&Idiomas", 0,  (Fl_Callback*)frmPrincipal_mnuConIdiomas_cb, 0, 0, 0, 0, 14, 56},
 {"&Pa\355ses", 0,  (Fl_Callback*)frmPrincipal_mnuConPaises_cb, 0, 0, 0, 0, 14, 56},
 {"P&rofiss\365""es", 0,  (Fl_Callback*)frmPrincipal_mnuConProfissoes_cb, 0, 128, 0, 0, 14, 56},
 {"&Clientes", 0,  (Fl_Callback*)frmPrincipal_mnuConClientes_cb, 0, 0, 0, 0, 14, 56},
 {"&Livros", 0,  (Fl_Callback*)frmPrincipal_mnuConLivros_cb, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {"&Vendas", 0,  0, 0, 64, 0, 0, 14, 56},
 {"&Vender Livros", 0,  (Fl_Callback*)frmPrincipal_mnuVenVenderLivros_cb, 0, 0, 0, 0, 14, 56},
 {"Vendas &Realizadas", 0,  (Fl_Callback*)frmPrincipal_mnuVenVendasRealizadas_cb, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {"&Op\347\365""es", 0,  0, 0, 64, 0, 0, 14, 56},
 {"&Alterar Senha", 0,  (Fl_Callback*)frmPrincipal_mnuOpAlterarSenha_cb, 0, 128, 0, 0, 14, 56},
 {"&Sobre", 0,  (Fl_Callback*)frmPrincipal_mnuOpSobre_cb, 0, 0, 0, 0, 14, 56},
 {"Sa&ir", 0,  (Fl_Callback*)frmPrincipal_mnuOpSair_cb, 0, 0, 0, 0, 14, 56},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};

CfrmPrincipal::CfrmPrincipal()
	 : Fl_Double_Window(104, 100, 507, 390, "Livrus Virtus") {
	IniciaControles();
}

void CfrmPrincipal::IniciaControles()
{
  this->box(FL_FLAT_BOX);
  this->color(FL_BACKGROUND_COLOR);
  this->selection_color(FL_BACKGROUND_COLOR);
  this->iconlabel((const char *)idata_Livrus);  
  this->labeltype(FL_NO_LABEL);
  this->labelfont(0);
  this->labelsize(14);
  this->labelcolor(FL_BLACK);
  this->align(FL_ALIGN_TOP);
  this->when(FL_WHEN_RELEASE);

  mnuCadastros = menu_BarraDeMenu + 0;
  mnuCadAssuntos = menu_BarraDeMenu + 1;
  mnuCadAutores = menu_BarraDeMenu + 2;
  mnuCadEditoras = menu_BarraDeMenu + 3;
  mnuCadEnderecos = menu_BarraDeMenu + 4;
  mnuCadIdiomas = menu_BarraDeMenu + 5;
  mnuCadPaises = menu_BarraDeMenu + 6;
  mnuCadProfissoes = menu_BarraDeMenu + 7;
  mnuCadClientes = menu_BarraDeMenu + 8;
  mnuCadLivros = menu_BarraDeMenu + 9;
  mnuPesquisas = menu_BarraDeMenu + 11;
  mnuConAssuntos = menu_BarraDeMenu + 12;
  mnuConAutores = menu_BarraDeMenu + 13;
  mnuConEditoras = menu_BarraDeMenu + 14;
  mnuConEnderecos = menu_BarraDeMenu + 15;
  mnuConIdiomas = menu_BarraDeMenu + 16;
  mnuConPaises = menu_BarraDeMenu + 17;
  mnuConProfissoes = menu_BarraDeMenu + 18;
  mnuConClientes = menu_BarraDeMenu + 19;
  mnuConLivros = menu_BarraDeMenu + 20;
  mnuVendas = menu_BarraDeMenu + 22;
  mnuVenVenderLivros = menu_BarraDeMenu + 23;
  mnuVenVendasRealizadas = menu_BarraDeMenu + 24;
  mnuOpcoes = menu_BarraDeMenu + 25;
  mnuOpAlterarSenha = menu_BarraDeMenu + 26;
  mnuOpSobre = menu_BarraDeMenu + 27;
  mnuOpSair = menu_BarraDeMenu + 28;

  BarraDeMenu = new Fl_Menu_Bar(0, 0, 505, 25);
  BarraDeMenu->align(193);
  BarraDeMenu->menu(menu_BarraDeMenu);

  BarraDeFerra = new Fl_Group(0, 25, 505, 35);
  BarraDeFerra->box(FL_UP_BOX);

  tlbClientes = new Fl_Button(5, 30, 25, 25);
  tlbClientes->image(image_cliente);
  tlbClientes->deimage(image_dcliente);
  tlbClientes->callback((Fl_Callback*)frmPrincipal_mnuCadClientes_cb);

  tlbLivros = new Fl_Button(30, 30, 25, 25);
  tlbLivros->image(image_livro);
  tlbLivros->deimage(image_dlivro);
  tlbLivros->callback((Fl_Callback*)frmPrincipal_mnuCadLivros_cb);

  tlbVenda = new Fl_Button(55, 30, 25, 25);
  tlbVenda->image(image_livros);
  tlbVenda->deimage(image_dlivros);
  tlbVenda->callback((Fl_Callback*)frmPrincipal_mnuVenVenderLivros_cb);

  tlbSobre = new Fl_Button(85, 30, 25, 25);
  tlbSobre->image(image_sobre);
  tlbSobre->deimage(image_dsobre);
  tlbSobre->callback((Fl_Callback*)frmPrincipal_mnuOpSobre_cb);

  tlbSair = new Fl_Button(110, 30, 25, 25);
  tlbSair->image(image_sair);
  tlbSair->deimage(image_dsair);
  tlbSair->callback((Fl_Callback*)frmPrincipal_mnuOpSair_cb);

  BarraDeFerra->end();

  BarraDeStatus1 = new Fl_Box(0, 370, 125, 20, STR_USUARIO);
  BarraDeStatus1->box(FL_DOWN_BOX);
  BarraDeStatus1->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
  BarraDeStatus2 = new Fl_Box(126, 370, 380, 20);
  BarraDeStatus2->box(FL_DOWN_BOX);
  BarraDeStatus2->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);

  this->hotspot(this);
  this->user_data((void*)(this));
  this->resizable(this);
  this->end();
}

void frmPrincipal_mnuCadAssuntos_cb(Fl_Widget* w, void* v) {  
  frmPrincipal->BarraDeStatus2->label(STR_CADASSUNTO);
  frmPrincipal->mnuCadAssuntos->deactivate();
  frmCadAssuntos = new CfrmCadAssuntos();
  frmCadAssuntos->show();
}
void frmPrincipal_mnuCadAutores_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADAUTOR);
  frmPrincipal->mnuCadAutores->deactivate();
  frmCadAutores = new CfrmCadAutores();
  frmCadAutores->show();
}
void frmPrincipal_mnuCadEditoras_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADEDITORA);
  frmPrincipal->mnuCadEditoras->deactivate();
  frmCadEditoras = new CfrmCadEditoras();
  frmCadEditoras->show();
}
void frmPrincipal_mnuCadEnderecos_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADENDERECO);
  frmPrincipal->mnuCadEnderecos->deactivate();
  frmCadEnderecos = new CfrmCadEnderecos();
  frmCadEnderecos->show();
}
void frmPrincipal_mnuCadIdiomas_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADIDIOMA);
  frmPrincipal->mnuCadIdiomas->deactivate();
  frmCadIdiomas = new CfrmCadIdiomas();
  frmCadIdiomas->show();
}
void frmPrincipal_mnuCadPaises_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADPAIS);
  frmPrincipal->mnuCadPaises->deactivate();
  frmCadPaises = new CfrmCadPaises();
  frmCadPaises->show();
}
void frmPrincipal_mnuCadProfissoes_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADPROFISS);
  frmPrincipal->mnuCadProfissoes->deactivate();
  frmCadProfissoes = new CfrmCadProfissoes();
  frmCadProfissoes->show();
}
void frmPrincipal_mnuCadClientes_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADCLIENTE);
  frmPrincipal->tlbClientes->deactivate();
  frmPrincipal->mnuCadClientes->deactivate();
  frmCadClientes = new CfrmCadClientes();
  frmCadClientes->show();
}
void frmPrincipal_mnuCadLivros_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CADLIVRO);
  frmPrincipal->tlbLivros->deactivate();
  frmPrincipal->mnuCadLivros->deactivate();
  frmCadLivros = new CfrmCadLivros();
  frmCadLivros->show();
}
void frmPrincipal_mnuConAssuntos_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONASSUNTO);
  frmConAssuntos = new CfrmConAssuntos();
  frmConAssuntos->show();
}
void frmPrincipal_mnuConAutores_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONAUTOR);
  frmConAutores = new CfrmConAutores();
  frmConAutores->show();
}
void frmPrincipal_mnuConEditoras_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONEDITORA);
  frmConEditoras = new CfrmConEditoras();
  frmConEditoras->show();
}

void frmPrincipal_mnuConEnderecos_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONENDERECO);
  frmConEnderecos = new CfrmConEnderecos();
  frmConEnderecos->show();
}
void frmPrincipal_mnuConIdiomas_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONIDIOMA);
  frmConIdiomas = new CfrmConIdiomas();
  frmConIdiomas->show();
}
void frmPrincipal_mnuConPaises_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONPAIS);
  frmConPaises = new CfrmConPaises();
  frmConPaises->show();
}
void frmPrincipal_mnuConProfissoes_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONPROFISS);
  frmConProfissoes = new CfrmConProfissoes();
  frmConProfissoes->show();
}
void frmPrincipal_mnuConClientes_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONCLIENTE);
  frmConClientes = new CfrmConClientes();
  frmConClientes->show();
}
void frmPrincipal_mnuConLivros_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONLIVRO);
  frmConLivros = new CfrmConLivros();
  frmConLivros->show();
}
void frmPrincipal_mnuVenVenderLivros_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_VENLIVRO);
  frmPrincipal->tlbVenda->deactivate();
  frmPrincipal->mnuVenVenderLivros->deactivate();
  frmVenderLivros = new CfrmVenderLivros();
  frmVenderLivros->show();
}
void frmPrincipal_mnuVenVendasRealizadas_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_CONVENLIVRO);
  frmPrincipal->mnuVenVendasRealizadas->deactivate();
  frmConVendas = new CfrmConVendas();
  frmConVendas->show();
}
void frmPrincipal_mnuOpAlterarSenha_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_ALTSENHA);
  frmPrincipal->mnuOpAlterarSenha->activate();
  frmAlterarSenha = new CfrmAlterarSenha();
  frmAlterarSenha->show();
}
void frmPrincipal_mnuOpSobre_cb(Fl_Widget* w, void* v){
  frmPrincipal->BarraDeStatus2->label(STR_OPSOBRE);
  frmSobre = new CfrmSobre();
  frmSobre->show();
}
void frmPrincipal_mnuOpSair_cb(Fl_Widget*, void*) {
  //frmPrincipal->hide();
  //frmPrincipal->handle(FL_HIDE);
  if (fl_ask(STR_SAIRSIS)==1)
    exit(0);
}

int CfrmPrincipal::handle(int event) {
  if (event == FL_HIDE) {
    if (fl_ask(STR_SAIRSIS)==1) 
      exit(0);
    else
      return -1;
  }
  return Fl_Double_Window::handle(event);
}

