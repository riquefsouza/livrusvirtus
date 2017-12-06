#ifndef CONASSUNTOS_H
#define CONASSUNTOS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConAssuntos;

GtkWidget *frmConAssuntos_Criar();
void on_frmConAssuntos_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConAssuntos_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConAssuntos_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConAssuntos_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

