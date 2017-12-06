#ifndef CONLIVROS_H
#define CONLIVROS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmConLivros;

GtkWidget *frmConLivros_Criar();
void on_frmConLivros_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConLivros_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConLivros_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConLivros_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

