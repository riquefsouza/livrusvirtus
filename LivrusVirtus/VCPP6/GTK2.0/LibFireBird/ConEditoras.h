#ifndef CONEDITORAS_H
#define CONEDITORAS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmConEditoras;

GtkWidget *frmConEditoras_Criar();
void on_frmConEditoras_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConEditoras_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConEditoras_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConEditoras_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

