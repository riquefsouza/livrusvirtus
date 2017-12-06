#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include "resource.h"

GtkWidget *frmPrincipal;
GtkWidget *frmPrincipal_tbClientes;
GtkWidget *frmPrincipal_tbLivros;
GtkWidget *frmPrincipal_tbVendas;
GtkWidget *frmPrincipal_tbSobre;
GtkWidget *frmPrincipal_tbSair;
GtkWidget *frmPrincipal_barraStatus1;
GtkWidget *frmPrincipal_barraStatus2;
GtkWidget *frmPrincipal_mnuCadAssuntos;
GtkWidget *frmPrincipal_mnuCadAutores;
GtkWidget *frmPrincipal_mnuCadEditoras;
GtkWidget *frmPrincipal_mnuCadEnderecos;
GtkWidget *frmPrincipal_mnuCadIdiomas;
GtkWidget *frmPrincipal_mnuCadPaises;
GtkWidget *frmPrincipal_mnuCadProfissoes;
GtkWidget *frmPrincipal_mnuCadClientes;
GtkWidget *frmPrincipal_mnuCadLivros;
GtkWidget *frmPrincipal_mnuVenderLivros;
GtkWidget *frmPrincipal_mnuVendasRealizadas;
GtkWidget *frmPrincipal_mnuAlterarsenha;

GtkWidget *frmPrincipal_Criar();
void on_frmPrincipal_mnuCadAssuntos_activate(GtkMenuItem *menuitem, 
                                             gpointer user_data);
void on_frmPrincipal_mnuCadAutores_activate(GtkMenuItem *menuitem, 
                                            gpointer user_data);
void on_frmPrincipal_mnuCadEditoras_activate(GtkMenuItem *menuitem, 
                                             gpointer user_data);
void on_frmPrincipal_mnuCadEnderecos_activate(GtkMenuItem *menuitem, 
                                              gpointer user_data);
void on_frmPrincipal_mnuCadIdiomas_activate(GtkMenuItem *menuitem, 
                                            gpointer user_data);
void on_frmPrincipal_mnuCadPaises_activate(GtkMenuItem *menuitem,
                                           gpointer user_data);
void on_frmPrincipal_mnuCadProfissoes_activate(GtkMenuItem *menuitem, 
                                               gpointer user_data);
void on_frmPrincipal_mnuCadClientes_activate(GtkMenuItem *menuitem, 
                                             gpointer user_data);
void on_frmPrincipal_mnuCadLivros_activate(GtkMenuItem *menuitem, 
                                           gpointer user_data);
void on_frmPrincipal_mnuConAssuntos_activate(GtkMenuItem *menuitem, 
                                             gpointer user_data);
void on_frmPrincipal_mnuConAutores_activate(GtkMenuItem *menuitem, 
                                            gpointer user_data);
void on_frmPrincipal_mnuConEditoras_activate(GtkMenuItem *menuitem, 
                                             gpointer user_data);
void on_frmPrincipal_mnuConEnderecos_activate(GtkMenuItem *menuitem, 
                                              gpointer user_data);
void on_frmPrincipal_mnuConIdiomas_activate(GtkMenuItem *menuitem, 
                                            gpointer user_data);
void on_frmPrincipal_mnuConPaises_activate(GtkMenuItem *menuitem, 
                                           gpointer user_data);
void on_frmPrincipal_mnuConProfissoes_activate(GtkMenuItem *menuitem, 
                                               gpointer user_data);
void on_frmPrincipal_mnuConClientes_activate(GtkMenuItem *menuitem, 
                                             gpointer user_data);
void on_frmPrincipal_mnuConLivros_activate(GtkMenuItem *menuitem, 
                                           gpointer user_data);
void on_frmPrincipal_mnuVenderLivros_activate(GtkMenuItem *menuitem, 
                                              gpointer user_data);
void on_frmPrincipal_mnuVendasRealizadas_activate(GtkMenuItem *menuitem, 
                                                  gpointer user_data);
void on_frmPrincipal_mnuAlterarsenha_activate(GtkMenuItem *menuitem, 
                                              gpointer user_data);
void on_frmPrincipal_mnuSobre_activate(GtkMenuItem *menuitem, 
                                       gpointer user_data);
void on_frmPrincipal_mnuSair_activate(GtkMenuItem *menuitem, 
                                      gpointer user_data);
void on_frmPrincipal_destroy(GtkObject *object, gpointer user_data);
gint on_frmPrincipal_delete_event(GtkWidget *widget, GdkEvent *event,
                                  gpointer data);
void on_frmPrincipal_tbClientes_clicked(GtkButton *button,
                                        gpointer user_data);
void on_frmPrincipal_tbLivros_clicked(GtkButton *button,
                                        gpointer user_data);
void on_frmPrincipal_tbVendas_clicked(GtkButton *button,
                                        gpointer user_data);
void on_frmPrincipal_tbSobre_clicked(GtkButton *button,
                                        gpointer user_data);
void on_frmPrincipal_tbSair_clicked(GtkButton *button,
                                        gpointer user_data);

gboolean frmPrincipal_DlgSair(void);
void frmPrincipal_setaBarraStatus(gchar *sTexto);

#endif

