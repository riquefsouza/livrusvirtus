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
#include "Splash.h"
#include "Sobre.h"
#include "Login.h"
#include "AlterarSenha.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

GtkWidget *frmPrincipal_Criar()
{
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *mnuCadastros;
  GtkWidget *mnuCadastros_menu;
  GtkWidget *separator2;
  GtkWidget *mnuPesquisas;
  GtkWidget *mnuPesquisas_menu;
  GtkWidget *mnuConAssuntos;
  GtkWidget *mnuConAutores;
  GtkWidget *mnuConEditoras;
  GtkWidget *mnuConEnderecos;
  GtkWidget *mnuConIdiomas;
  GtkWidget *mnuConPaises;
  GtkWidget *mnuConProfissoes;
  GtkWidget *separator3;
  GtkWidget *mnuConClientes;
  GtkWidget *mnuConLivros;
  GtkWidget *mnuVendas;
  GtkWidget *mnuVendas_menu;
  GtkWidget *mnuOpcoes;
  GtkWidget *mnuOpcoes_menu;
  GtkWidget *separator1;
  GtkWidget *mnuSobre;
  GtkWidget *mnuSair;
  GtkWidget *toolbar1;
  gint tmp_toolbar_icon_size;
  GtkWidget *scrolledwindow1;
  GtkWidget *hbox2;
  GtkWidget *tmp_toolbar_icon;
  GtkWidget *vseparator1;
  
  frmPrincipal = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (frmPrincipal, "frmPrincipal");
  gtk_window_set_title (GTK_WINDOW (frmPrincipal), _("Livrus Virtus"));
  gtk_window_set_position (GTK_WINDOW (frmPrincipal), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (frmPrincipal), 500, 400);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmPrincipal), TRUE);
  gtk_window_set_skip_taskbar_hint (GTK_WINDOW (frmPrincipal), TRUE);
  gtk_window_set_skip_pager_hint (GTK_WINDOW (frmPrincipal), TRUE);

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (frmPrincipal), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_set_name (menubar1, "menubar1");
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  mnuCadastros = gtk_menu_item_new_with_mnemonic (_("_Cadastros"));
  gtk_widget_set_name (mnuCadastros, "mnuCadastros");
  gtk_widget_show (mnuCadastros);
  gtk_container_add (GTK_CONTAINER (menubar1), mnuCadastros);

  mnuCadastros_menu = gtk_menu_new ();
  gtk_widget_set_name (mnuCadastros_menu, "mnuCadastros_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mnuCadastros), mnuCadastros_menu);

  frmPrincipal_mnuCadAssuntos = gtk_menu_item_new_with_mnemonic (_("_Assuntos"));
  gtk_widget_set_name (frmPrincipal_mnuCadAssuntos, "mnuCadAssuntos");
  gtk_widget_show (frmPrincipal_mnuCadAssuntos);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadAssuntos);

  frmPrincipal_mnuCadAutores = gtk_menu_item_new_with_mnemonic (_("A_utores"));
  gtk_widget_set_name (frmPrincipal_mnuCadAutores, "mnuCadAutores");
  gtk_widget_show (frmPrincipal_mnuCadAutores);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadAutores);

  frmPrincipal_mnuCadEditoras = gtk_menu_item_new_with_mnemonic (_("_Editoras"));
  gtk_widget_set_name (frmPrincipal_mnuCadEditoras, "mnuCadEditoras");
  gtk_widget_show (frmPrincipal_mnuCadEditoras);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadEditoras);

  frmPrincipal_mnuCadEnderecos = gtk_menu_item_new_with_mnemonic(
    Rotinas_retUTF8("E_ndereços"));
  gtk_widget_set_name (frmPrincipal_mnuCadEnderecos, "mnuCadEnderecos");
  gtk_widget_show (frmPrincipal_mnuCadEnderecos);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadEnderecos);

  frmPrincipal_mnuCadIdiomas = gtk_menu_item_new_with_mnemonic (_("_Idiomas"));
  gtk_widget_set_name (frmPrincipal_mnuCadIdiomas, "mnuCadIdiomas");
  gtk_widget_show (frmPrincipal_mnuCadIdiomas);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadIdiomas);

  frmPrincipal_mnuCadPaises = gtk_menu_item_new_with_mnemonic(
    Rotinas_retUTF8("_Países"));
  gtk_widget_set_name (frmPrincipal_mnuCadPaises, "mnuCadPaises");
  gtk_widget_show (frmPrincipal_mnuCadPaises);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadPaises);

  frmPrincipal_mnuCadProfissoes = gtk_menu_item_new_with_mnemonic(
    Rotinas_retUTF8("P_rofissões"));
  gtk_widget_set_name (frmPrincipal_mnuCadProfissoes, "mnuCadProfissoes");
  gtk_widget_show (frmPrincipal_mnuCadProfissoes);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadProfissoes);

  separator2 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator2, "separator2");
  gtk_widget_show (separator2);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), separator2);
  gtk_widget_set_sensitive (separator2, FALSE);

  frmPrincipal_mnuCadClientes = gtk_menu_item_new_with_mnemonic (_("_Clientes"));
  gtk_widget_set_name (frmPrincipal_mnuCadClientes, "mnuCadClientes");
  gtk_widget_show (frmPrincipal_mnuCadClientes);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadClientes);

  frmPrincipal_mnuCadLivros = gtk_menu_item_new_with_mnemonic (_("_Livros"));
  gtk_widget_set_name (frmPrincipal_mnuCadLivros, "mnuCadLivros");
  gtk_widget_show (frmPrincipal_mnuCadLivros);
  gtk_container_add (GTK_CONTAINER (mnuCadastros_menu), frmPrincipal_mnuCadLivros);

  mnuPesquisas = gtk_menu_item_new_with_mnemonic (_("_Pesquisas"));
  gtk_widget_set_name (mnuPesquisas, "mnuPesquisas");
  gtk_widget_show (mnuPesquisas);
  gtk_container_add (GTK_CONTAINER (menubar1), mnuPesquisas);

  mnuPesquisas_menu = gtk_menu_new ();
  gtk_widget_set_name (mnuPesquisas_menu, "mnuPesquisas_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mnuPesquisas), mnuPesquisas_menu);

  mnuConAssuntos = gtk_menu_item_new_with_mnemonic (_("_Assuntos"));
  gtk_widget_set_name (mnuConAssuntos, "mnuConAssuntos");
  gtk_widget_show (mnuConAssuntos);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConAssuntos);

  mnuConAutores = gtk_menu_item_new_with_mnemonic (_("A_utores"));
  gtk_widget_set_name (mnuConAutores, "mnuConAutores");
  gtk_widget_show (mnuConAutores);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConAutores);

  mnuConEditoras = gtk_menu_item_new_with_mnemonic (_("_Editoras"));
  gtk_widget_set_name (mnuConEditoras, "mnuConEditoras");
  gtk_widget_show (mnuConEditoras);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConEditoras);

  mnuConEnderecos = gtk_menu_item_new_with_mnemonic(
    Rotinas_retUTF8("E_ndereços"));
  gtk_widget_set_name (mnuConEnderecos, "mnuConEnderecos");
  gtk_widget_show (mnuConEnderecos);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConEnderecos);

  mnuConIdiomas = gtk_menu_item_new_with_mnemonic (_("_Idiomas"));
  gtk_widget_set_name (mnuConIdiomas, "mnuConIdiomas");
  gtk_widget_show (mnuConIdiomas);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConIdiomas);

  mnuConPaises = gtk_menu_item_new_with_mnemonic(
    Rotinas_retUTF8("_Países"));
  gtk_widget_set_name (mnuConPaises, "mnuConPaises");
  gtk_widget_show (mnuConPaises);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConPaises);

  mnuConProfissoes = gtk_menu_item_new_with_mnemonic(
    Rotinas_retUTF8("P_rofissões"));
  gtk_widget_set_name (mnuConProfissoes, "mnuConProfissoes");
  gtk_widget_show (mnuConProfissoes);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConProfissoes);

  separator3 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator3, "separator3");
  gtk_widget_show (separator3);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), separator3);
  gtk_widget_set_sensitive (separator3, FALSE);

  mnuConClientes = gtk_menu_item_new_with_mnemonic (_("_Clientes"));
  gtk_widget_set_name (mnuConClientes, "mnuConClientes");
  gtk_widget_show (mnuConClientes);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConClientes);

  mnuConLivros = gtk_menu_item_new_with_mnemonic (_("_Livros"));
  gtk_widget_set_name (mnuConLivros, "mnuConLivros");
  gtk_widget_show (mnuConLivros);
  gtk_container_add (GTK_CONTAINER (mnuPesquisas_menu), mnuConLivros);

  mnuVendas = gtk_menu_item_new_with_mnemonic (_("_Vendas"));
  gtk_widget_set_name (mnuVendas, "mnuVendas");
  gtk_widget_show (mnuVendas);
  gtk_container_add (GTK_CONTAINER (menubar1), mnuVendas);

  mnuVendas_menu = gtk_menu_new ();
  gtk_widget_set_name (mnuVendas_menu, "mnuVendas_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mnuVendas), mnuVendas_menu);

  frmPrincipal_mnuVenderLivros = 
    gtk_menu_item_new_with_mnemonic (_("_Vender Livros"));
  gtk_widget_set_name (frmPrincipal_mnuVenderLivros, "mnuVenderLivros");
  gtk_widget_show (frmPrincipal_mnuVenderLivros);
  gtk_container_add (GTK_CONTAINER (mnuVendas_menu), 
    frmPrincipal_mnuVenderLivros);

  frmPrincipal_mnuVendasRealizadas =
    gtk_menu_item_new_with_mnemonic (_("Vendas _realizadas"));
  gtk_widget_set_name (frmPrincipal_mnuVendasRealizadas, 
    "mnuVendasRealizadas");
  gtk_widget_show (frmPrincipal_mnuVendasRealizadas);
  gtk_container_add (GTK_CONTAINER (mnuVendas_menu), 
    frmPrincipal_mnuVendasRealizadas);

  mnuOpcoes = gtk_menu_item_new_with_mnemonic (Rotinas_retUTF8("_Opções"));
  gtk_widget_set_name (mnuOpcoes, "mnuOpcoes");
  gtk_widget_show (mnuOpcoes);
  gtk_container_add (GTK_CONTAINER (menubar1), mnuOpcoes);

  mnuOpcoes_menu = gtk_menu_new ();
  gtk_widget_set_name (mnuOpcoes_menu, "mnuOpcoes_menu");
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (mnuOpcoes), mnuOpcoes_menu);

  frmPrincipal_mnuAlterarsenha = gtk_menu_item_new_with_mnemonic (_("_Alterar Senha"));
  gtk_widget_set_name (frmPrincipal_mnuAlterarsenha, "mnuAlterarsenha");
  gtk_widget_show (frmPrincipal_mnuAlterarsenha);
  gtk_container_add (GTK_CONTAINER (mnuOpcoes_menu), frmPrincipal_mnuAlterarsenha);

  separator1 = gtk_separator_menu_item_new ();
  gtk_widget_set_name (separator1, "separator1");
  gtk_widget_show (separator1);
  gtk_container_add (GTK_CONTAINER (mnuOpcoes_menu), separator1);
  gtk_widget_set_sensitive (separator1, FALSE);

  mnuSobre = gtk_menu_item_new_with_mnemonic (_("_Sobre"));
  gtk_widget_set_name (mnuSobre, "mnuSobre");
  gtk_widget_show (mnuSobre);
  gtk_container_add (GTK_CONTAINER (mnuOpcoes_menu), mnuSobre);

  mnuSair = gtk_menu_item_new_with_mnemonic (_("Sa_ir"));
  gtk_widget_set_name (mnuSair, "mnuSair");
  gtk_widget_show (mnuSair);
  gtk_container_add (GTK_CONTAINER (mnuOpcoes_menu), mnuSair);

  toolbar1 = gtk_toolbar_new ();
  gtk_widget_set_name (toolbar1, "toolbar1");
  gtk_widget_show (toolbar1);
  gtk_box_pack_start (GTK_BOX (vbox1), toolbar1, FALSE, FALSE, 0);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar1), GTK_TOOLBAR_ICONS);
  tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar1));

  tmp_toolbar_icon = gtk_image_new_from_file("xpms/cliente.xpm");
  frmPrincipal_tbClientes = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
    GTK_TOOLBAR_CHILD_BUTTON, NULL, "", NULL, NULL, 
    tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline(GTK_LABEL (((GtkToolbarChild*) 
    (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (frmPrincipal_tbClientes);

  tmp_toolbar_icon = gtk_image_new_from_file("xpms/livro.xpm");
  frmPrincipal_tbLivros = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
    GTK_TOOLBAR_CHILD_BUTTON, NULL, "", NULL, NULL, 
    tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) 
    (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (frmPrincipal_tbLivros);

  tmp_toolbar_icon = gtk_image_new_from_file("xpms/livros.xpm");
  frmPrincipal_tbVendas = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
    GTK_TOOLBAR_CHILD_BUTTON, NULL, "", NULL, NULL,
    tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) 
    (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (frmPrincipal_tbVendas);

  vseparator1 = gtk_vseparator_new ();
  gtk_widget_show (vseparator1);
  gtk_toolbar_append_widget (GTK_TOOLBAR (toolbar1), vseparator1, NULL, NULL);
  gtk_widget_set_size_request (vseparator1, 7, 2);

  tmp_toolbar_icon = gtk_image_new_from_file("xpms/sobre.xpm");
  frmPrincipal_tbSobre = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
    GTK_TOOLBAR_CHILD_BUTTON, NULL, "", NULL, NULL,
    tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) 
    (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (frmPrincipal_tbSobre);

  tmp_toolbar_icon = gtk_image_new_from_file("xpms/sair.xpm");
  frmPrincipal_tbSair = gtk_toolbar_append_element (GTK_TOOLBAR (toolbar1),
    GTK_TOOLBAR_CHILD_BUTTON, NULL, "", NULL, NULL,
    tmp_toolbar_icon, NULL, NULL);
  gtk_label_set_use_underline (GTK_LABEL (((GtkToolbarChild*) 
    (g_list_last (GTK_TOOLBAR (toolbar1)->children)->data))->label), TRUE);
  gtk_widget_show (frmPrincipal_tbSair);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_widget_show (scrolledwindow1);
  gtk_box_pack_start (GTK_BOX (vbox1), scrolledwindow1, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
				       GTK_SHADOW_IN);

  hbox2 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox2);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox2, FALSE, TRUE, 0);

  frmPrincipal_barraStatus1 = gtk_statusbar_new ();
  gtk_widget_show (frmPrincipal_barraStatus1);
  gtk_box_pack_start (GTK_BOX (hbox2), frmPrincipal_barraStatus1, FALSE, TRUE, 0);
  gtk_widget_set_size_request (frmPrincipal_barraStatus1, 120, 21);
  gtk_statusbar_set_has_resize_grip (GTK_STATUSBAR (frmPrincipal_barraStatus1), FALSE);

  frmPrincipal_barraStatus2 = gtk_statusbar_new();
  gtk_widget_show (frmPrincipal_barraStatus2);
  gtk_box_pack_start (GTK_BOX (hbox2), frmPrincipal_barraStatus2, TRUE, TRUE, 0);
  gtk_widget_set_size_request (frmPrincipal_barraStatus2, -1, 21);

  g_signal_connect ((gpointer) frmPrincipal, "destroy",
		    G_CALLBACK (on_frmPrincipal_destroy), NULL);
  g_signal_connect((gpointer) frmPrincipal, "delete_event",
        G_CALLBACK (on_frmPrincipal_delete_event), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadAssuntos, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadAssuntos_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadAutores, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadAutores_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadEditoras, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadEditoras_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadEnderecos, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadEnderecos_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadIdiomas, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadIdiomas_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadPaises, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadPaises_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadProfissoes, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadProfissoes_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadClientes, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadClientes_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuCadLivros, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuCadLivros_activate), NULL);
  g_signal_connect ((gpointer) mnuConAssuntos, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConAssuntos_activate), NULL);
  g_signal_connect ((gpointer) mnuConAutores, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConAutores_activate), NULL);
  g_signal_connect ((gpointer) mnuConEditoras, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConEditoras_activate), NULL);
  g_signal_connect ((gpointer) mnuConEnderecos, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConEnderecos_activate), NULL);
  g_signal_connect ((gpointer) mnuConIdiomas, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConIdiomas_activate), NULL);
  g_signal_connect ((gpointer) mnuConPaises, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConPaises_activate), NULL);
  g_signal_connect ((gpointer) mnuConProfissoes, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConProfissoes_activate), NULL);
  g_signal_connect ((gpointer) mnuConClientes, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConClientes_activate), NULL);
  g_signal_connect ((gpointer) mnuConLivros, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuConLivros_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuVenderLivros, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuVenderLivros_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuVendasRealizadas, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuVendasRealizadas_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_mnuAlterarsenha, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuAlterarsenha_activate), NULL);
  g_signal_connect ((gpointer) mnuSobre, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuSobre_activate), NULL);
  g_signal_connect ((gpointer) mnuSair, "activate",
		    G_CALLBACK (on_frmPrincipal_mnuSair_activate), NULL);
  g_signal_connect ((gpointer) frmPrincipal_tbClientes, "clicked",
		    G_CALLBACK (on_frmPrincipal_tbClientes_clicked), NULL);
  g_signal_connect ((gpointer) frmPrincipal_tbLivros, "clicked",
		    G_CALLBACK (on_frmPrincipal_tbLivros_clicked), NULL);
  g_signal_connect ((gpointer) frmPrincipal_tbVendas, "clicked",
		    G_CALLBACK (on_frmPrincipal_tbVendas_clicked), NULL);
  g_signal_connect ((gpointer) frmPrincipal_tbSobre, "clicked",
		    G_CALLBACK (on_frmPrincipal_tbSobre_clicked), NULL);
  g_signal_connect ((gpointer) frmPrincipal_tbSair, "clicked",
		    G_CALLBACK (on_frmPrincipal_tbSair_clicked), NULL);

  return frmPrincipal;
}

void on_frmPrincipal_mnuCadAssuntos_activate(GtkMenuItem * menuitem, 
                                             gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADASSUNTO);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadAssuntos, FALSE);
  frmCadAssuntos = frmCadAssuntos_Criar();
  gtk_widget_show(frmCadAssuntos);
}

void on_frmPrincipal_mnuCadAutores_activate(GtkMenuItem * menuitem, 
                                            gpointer user_data) { 
  frmPrincipal_setaBarraStatus(STR_CADAUTOR);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadAutores, FALSE);
  frmCadAutores = frmCadAutores_Criar();
  gtk_widget_show(frmCadAutores);
}

void on_frmPrincipal_mnuCadEditoras_activate(GtkMenuItem * menuitem, 
                                             gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADEDITORA);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadEditoras, FALSE);
  frmCadEditoras = frmCadEditoras_Criar();
  gtk_widget_show(frmCadEditoras);
}

void on_frmPrincipal_mnuCadEnderecos_activate(GtkMenuItem * menuitem, 
                                               gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADENDERECO);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadEnderecos, FALSE);
  frmCadEnderecos = frmCadEnderecos_Criar();
  gtk_widget_show(frmCadEnderecos);
}

void on_frmPrincipal_mnuCadIdiomas_activate(GtkMenuItem * menuitem, 
                                            gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADIDIOMA);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadIdiomas, FALSE);
  frmCadIdiomas = frmCadIdiomas_Criar();
  gtk_widget_show(frmCadIdiomas);
}

void on_frmPrincipal_mnuCadPaises_activate(GtkMenuItem * menuitem, 
                                            gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADPAIS);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadPaises, FALSE);
  frmCadPaises = frmCadPaises_Criar();
  gtk_widget_show(frmCadPaises);
}

void on_frmPrincipal_mnuCadProfissoes_activate(GtkMenuItem * menuitem, 
                                                gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADPROFISS);
  gtk_widget_set_sensitive(frmPrincipal_mnuCadProfissoes, FALSE);
  frmCadProfissoes = frmCadProfissoes_Criar();
  gtk_widget_show(frmCadProfissoes);
}

void on_frmPrincipal_mnuCadClientes_activate(GtkMenuItem * menuitem, 
                                              gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADCLIENTE);
  gtk_widget_set_sensitive(frmPrincipal_tbClientes, FALSE);  
  gtk_widget_set_sensitive(frmPrincipal_mnuCadClientes, FALSE);
  frmCadClientes = frmCadClientes_Criar();
  gtk_widget_show(frmCadClientes);
}

void on_frmPrincipal_mnuCadLivros_activate(GtkMenuItem * menuitem, 
                                            gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CADLIVRO);
  gtk_widget_set_sensitive(frmPrincipal_tbLivros, FALSE);  
  gtk_widget_set_sensitive(frmPrincipal_mnuCadLivros, FALSE);
  frmCadLivros = frmCadLivros_Criar();
  gtk_widget_show(frmCadLivros);
}

void frmPrincipal_setaBarraStatus(gchar *sTexto) {
  gtk_statusbar_push(GTK_STATUSBAR(frmPrincipal_barraStatus2),
    gtk_statusbar_get_context_id(
    GTK_STATUSBAR(frmPrincipal_barraStatus2), "contexto2"), 
    Rotinas_retUTF8(sTexto));
}

void on_frmPrincipal_mnuConAssuntos_activate(GtkMenuItem * menuitem, 
                                             gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONASSUNTO);
  frmConAssuntos = frmConAssuntos_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConAssuntos));
  gtk_widget_destroy(frmConAssuntos);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConAutores_activate(GtkMenuItem * menuitem, 
                                             gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONAUTOR);
  frmConAutores = frmConAutores_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConAutores));
  gtk_widget_destroy(frmConAutores);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConEditoras_activate(GtkMenuItem * menuitem, 
                                              gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONEDITORA);
  frmConEditoras = frmConEditoras_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConEditoras));
  gtk_widget_destroy(frmConEditoras);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConEnderecos_activate(GtkMenuItem * menuitem, 
                                               gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONENDERECO);
  frmConEnderecos = frmConEnderecos_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConEnderecos));
  gtk_widget_destroy(frmConEnderecos);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConIdiomas_activate(GtkMenuItem * menuitem, 
                                             gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONIDIOMA);
  frmConIdiomas = frmConIdiomas_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConIdiomas));
  gtk_widget_destroy(frmConIdiomas);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConPaises_activate (GtkMenuItem * menuitem, 
                                            gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONPAIS);
  frmConPaises = frmConPaises_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConPaises));
  gtk_widget_destroy(frmConPaises);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConProfissoes_activate(GtkMenuItem * menuitem, 
                                                gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONPROFISS);
  frmConProfissoes = frmConProfissoes_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConProfissoes));
  gtk_widget_destroy(frmConProfissoes);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConClientes_activate (GtkMenuItem * menuitem, 
                                              gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONCLIENTE);
  frmConClientes = frmConClientes_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConClientes));
  gtk_widget_destroy(frmConClientes);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuConLivros_activate (GtkMenuItem * menuitem, 
                                            gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONLIVRO);
  frmConLivros = frmConLivros_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConLivros));
  gtk_widget_destroy(frmConLivros);
  frmPrincipal_setaBarraStatus("");
}

void on_frmPrincipal_mnuVenderLivros_activate (GtkMenuItem * menuitem, 
                                               gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_VENLIVRO);
  gtk_widget_set_sensitive(frmPrincipal_tbVendas, FALSE);  
  gtk_widget_set_sensitive(frmPrincipal_mnuVenderLivros, FALSE);
  frmVenderLivros = frmVenderLivros_Criar();
  gtk_widget_show(frmVenderLivros);
}

void on_frmPrincipal_mnuVendasRealizadas_activate(GtkMenuItem * menuitem, 
                                                   gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_CONVENLIVRO);
  gtk_widget_set_sensitive(frmPrincipal_mnuVendasRealizadas, FALSE);
  frmConVendas = frmConVendas_Criar();
  gtk_widget_show(frmConVendas);
}

void on_frmPrincipal_mnuAlterarsenha_activate(GtkMenuItem * menuitem, 
                                               gpointer user_data) {
  frmPrincipal_setaBarraStatus(STR_ALTSENHA);
  gtk_widget_set_sensitive(frmPrincipal_mnuAlterarsenha, FALSE);
  frmAlterarSenha = frmAlterarSenha_Criar();
	gtk_widget_set_name(frmAlterarSenha, "frmAlterarSenha");
  gtk_widget_show(frmAlterarSenha);
}

void on_frmPrincipal_mnuSobre_activate (GtkMenuItem * menuitem, 
                                        gpointer user_data)
{	
  frmPrincipal_setaBarraStatus(STR_OPSOBRE);
  frmSobre = frmSobre_Criar();
	gtk_widget_set_name(frmSobre, "frmSobre");
	gtk_dialog_run(GTK_DIALOG(frmSobre));
  frmPrincipal_setaBarraStatus("");
  gtk_widget_destroy(frmSobre);
}

void on_frmPrincipal_mnuSair_activate(GtkMenuItem * menuitem, 
                                      gpointer user_data) {
  if (frmPrincipal_DlgSair())
    gtk_widget_destroy(frmPrincipal);
}

void on_frmPrincipal_destroy (GtkObject * object, 
                              gpointer user_data) {
  gtk_main_quit();
}

gboolean frmPrincipal_DlgSair(void) {
  GtkWidget *dialog;
  dialog = gtk_message_dialog_new (GTK_WINDOW(frmPrincipal),
  GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION,
  GTK_BUTTONS_YES_NO, "%s", STR_SAIRSIS);
  if (gtk_dialog_run(GTK_DIALOG (dialog))==GTK_RESPONSE_YES) {
    gtk_widget_destroy (dialog);
    return(TRUE);
  } else {
    gtk_widget_destroy (dialog);
    return(FALSE);
  }
}

gint on_frmPrincipal_delete_event(GtkWidget *widget, 
                                  GdkEvent *event, gpointer data ) {
  if (frmPrincipal_DlgSair())
    return(FALSE);
  else
    return(TRUE);
}

void on_frmPrincipal_tbClientes_clicked(GtkButton *button,
                                        gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_tbClientes, FALSE);
  on_frmPrincipal_mnuCadClientes_activate(NULL, user_data);
}

void on_frmPrincipal_tbLivros_clicked(GtkButton *button,
                                        gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_tbLivros, FALSE);
  on_frmPrincipal_mnuCadLivros_activate(NULL, user_data);
}

void on_frmPrincipal_tbVendas_clicked(GtkButton *button,
                                        gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_tbVendas, FALSE);
  on_frmPrincipal_mnuVenderLivros_activate(NULL, user_data);
}

void on_frmPrincipal_tbSobre_clicked(GtkButton *button,
                                        gpointer user_data) {
  on_frmPrincipal_mnuSobre_activate(NULL, user_data);
}

void on_frmPrincipal_tbSair_clicked(GtkButton *button,
                                        gpointer user_data) {
  on_frmPrincipal_mnuSair_activate(NULL, user_data);
}

