#ifndef FRMPRINCIPAL_H
#define FRMPRINCIPAL_H

#include "resource.h"

extern GtkWidget *frmPrincipal;
extern GtkWidget *frmPrincipal_tbClientes;
extern GtkWidget *frmPrincipal_tbLivros;
extern GtkWidget *frmPrincipal_tbVendas;
extern GtkWidget *frmPrincipal_tbSobre;
extern GtkWidget *frmPrincipal_tbSair;
extern GtkWidget *frmPrincipal_barraStatus1;
extern GtkWidget *frmPrincipal_barraStatus2;
extern GtkWidget *frmPrincipal_mnuCadAssuntos;
extern GtkWidget *frmPrincipal_mnuCadAutores;
extern GtkWidget *frmPrincipal_mnuCadEditoras;
extern GtkWidget *frmPrincipal_mnuCadEnderecos;
extern GtkWidget *frmPrincipal_mnuCadIdiomas;
extern GtkWidget *frmPrincipal_mnuCadPaises;
extern GtkWidget *frmPrincipal_mnuCadProfissoes;
extern GtkWidget *frmPrincipal_mnuCadClientes;
extern GtkWidget *frmPrincipal_mnuCadLivros;
extern GtkWidget *frmPrincipal_mnuVenderLivros;
extern GtkWidget *frmPrincipal_mnuVendasRealizadas;
extern GtkWidget *frmPrincipal_mnuAlterarsenha;

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

