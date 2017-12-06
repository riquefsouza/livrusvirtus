#ifndef CONIDIOMAS_H
#define CONIDIOMAS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConIdiomas;

GtkWidget *frmConIdiomas_Criar();
void on_frmConIdiomas_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConIdiomas_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConIdiomas_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConIdiomas_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

