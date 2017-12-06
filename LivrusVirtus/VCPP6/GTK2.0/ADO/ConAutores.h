#ifndef CONAUTORES_H
#define CONAUTORES_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConAutores;

GtkWidget *frmConAutores_Criar();
void on_frmConAutores_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConAutores_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConAutores_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConAutores_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

