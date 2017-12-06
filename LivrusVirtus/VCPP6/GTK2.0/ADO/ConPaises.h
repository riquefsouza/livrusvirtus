#ifndef CONPAISES_H
#define CONPAISES_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConPaises;

GtkWidget *frmConPaises_Criar();
void on_frmConPaises_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConPaises_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConPaises_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConPaises_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

