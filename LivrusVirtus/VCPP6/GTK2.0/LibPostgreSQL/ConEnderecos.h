#ifndef CONENDERECOS_H
#define CONENDERECOS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmConEnderecos;

GtkWidget *frmConEnderecos_Criar();
void on_frmConEnderecos_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConEnderecos_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConEnderecos_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConEnderecos_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

