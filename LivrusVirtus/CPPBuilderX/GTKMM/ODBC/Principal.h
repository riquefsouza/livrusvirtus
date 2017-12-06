#ifndef PRINCIPAL_H
  #define PRINCIPAL_H

  #include "resource.h"

  class CfrmPrincipal : public Gtk::Window {
  public:
    CfrmPrincipal();
    ~CfrmPrincipal();
    Gtk::MenuItem * mnuCadAssuntos;
    Gtk::MenuItem * mnuCadAutores;
    Gtk::MenuItem * mnuCadEditoras;
    Gtk::MenuItem * mnuCadEnderecos;
    Gtk::MenuItem * mnuCadIdiomas;
    Gtk::MenuItem * mnuCadPaises;
    Gtk::MenuItem * mnuCadProfissoes;
    Gtk::MenuItem * mnuCadClientes;
    Gtk::MenuItem * mnuCadLivros;
    Gtk::MenuItem * mnuVenderLivros;
    Gtk::MenuItem * mnuVendasRealizadas;
    Gtk::MenuItem * mnuAlterarsenha;
    Gtk::Statusbar * BarraStatus1;
    Gtk::Button * tlbCliente;
    Gtk::Button * tlbLivro;
    Gtk::Button * tlbVenda;

    void setaBarraStatus(gchar *sTexto);

  private:
    Gtk::MenuItem * separator2;
    Gtk::Menu * mnuCadastros_menu;
    Gtk::MenuItem * mnuCadastros;
    Gtk::MenuItem * mnuConAssuntos;
    Gtk::MenuItem * mnuConAutores;
    Gtk::MenuItem * mnuConEditoras;
    Gtk::MenuItem * mnuConEnderecos;
    Gtk::MenuItem * mnuConIdiomas;
    Gtk::MenuItem * mnuConPaises;
    Gtk::MenuItem * mnuConProfissoes;
    Gtk::MenuItem * separator3;
    Gtk::MenuItem * mnuConClientes;
    Gtk::MenuItem * mnuConLivros;
    Gtk::Menu * mnuPesquisas_menu;
    Gtk::MenuItem * mnuPesquisas;
    Gtk::Menu * mnuVendas_menu;
    Gtk::MenuItem * mnuVendas;
    Gtk::MenuItem * separator1;
    Gtk::MenuItem * mnuSobre;
    Gtk::MenuItem * mnuSair;
    Gtk::Menu * mnuOpcoes_menu;
    Gtk::MenuItem * mnuOpcoes;

    Gtk::MenuBar * barraMenu;
    Gtk::VSeparator * vseparador1;
    Gtk::Toolbar * barraFerra;
    Gtk::Fixed * fixed1;
    Gtk::Statusbar * BarraStatus2;
    Gtk::HBox * hbox1;
    Gtk::VBox * vbox1;

    Gtk::Image *xpm_cliente;
    Gtk::Image *xpm_livro;
    Gtk::Image *xpm_venda;
    Gtk::Image *xpm_sobre;
    Gtk::Image *xpm_sair;

    Gtk::Button * tlbSobre;
    Gtk::Button * tlbSair;

    void on_mnuCadAssuntos_activate();
    void on_mnuCadAutores_activate();
    void on_mnuCadEditoras_activate();
    void on_mnuCadEnderecos_activate();
    void on_mnuCadIdiomas_activate();
    void on_mnuCadPaises_activate();
    void on_mnuCadProfissoes_activate();
    void on_mnuCadClientes_activate();
    void on_mnuCadLivros_activate();
    void on_mnuConAssuntos_activate();
    void on_mnuConAutores_activate();
    void on_mnuConEditoras_activate();
    void on_mnuConEnderecos_activate();
    void on_mnuConIdiomas_activate();
    void on_mnuConPaises_activate();
    void on_mnuConProfissoes_activate();
    void on_mnuConClientes_activate();
    void on_mnuConLivros_activate();
    void on_mnuVenderLivros_activate();
    void on_mnuVendasRealizadas_activate();
    void on_mnuAlterarsenha_activate();
    void on_mnuSobre_activate();
    void on_mnuSair_activate();
    gboolean DlgSair();
    bool on_delete_event(GdkEventAny* event);
  };

  extern CfrmPrincipal * frmPrincipal;

#endif
