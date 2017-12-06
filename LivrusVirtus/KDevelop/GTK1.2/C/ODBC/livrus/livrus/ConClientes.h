#ifndef CONCLIENTES_H
#define CONCLIENTES_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmConClientes;

GtkWidget *frmConClientes_Criar();
void on_frmConClientes_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConClientes_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConClientes_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConClientes_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

