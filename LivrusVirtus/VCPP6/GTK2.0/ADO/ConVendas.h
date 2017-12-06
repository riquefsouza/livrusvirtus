#ifndef CONVENDAS_H
#define CONVENDAS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConVendas;
extern GtkWidget *frmConVendas_edtDtHrVenda;
extern GtkWidget *frmConVendas_edtCPF;
extern GtkWidget *frmConVendas_edtCliente;
extern GtkWidget *frmConVendas_edtISBN;
extern GtkWidget *frmConVendas_edtLivro;
extern GtkWidget *frmConVendas_gridConsulta;
extern GtkWidget *frmConVendas_labRegistros;
extern GtkWidget *frmConVendas_edtPrecoTotal;

GtkWidget *frmConVendas_Criar(void);
GString *frmConVendas_ConsVenda(gchar sOpcao);
void on_frmConVendas_destroy(GtkObject *object, gpointer user_data);
gboolean on_frmConVendas_edtDtHrVenda_focus_out_event(GtkWidget *widget,
					GdkEventFocus *event,	gpointer user_data);
gboolean on_frmConVendas_edtCPF_focus_out_event(GtkWidget *widget,
					GdkEventFocus *event,	gpointer user_data);
gboolean on_frmConVendas_edtISBN_focus_out_event(GtkWidget *widget, 
                        GdkEventFocus *event, gpointer user_data);
void on_frmConVendas_btnPCliente_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmConVendas_btnPLivro_clicked(GtkButton *button, 
                                       gpointer user_data);
void on_frmConVendas_btnPesquisar_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmConVendas_btnLimpar_clicked(GtkButton *button, 
                                       gpointer user_data);
void on_frmConVendas_btnFechar_clicked(GtkButton *button, 
                                       gpointer user_data);
void frmConVendas_setLabRegistros(gint nLinha);
void on_frmConVendas_gridConsulta_selection_changed(
  GtkTreeSelection* selection, gpointer user_data);

#endif
