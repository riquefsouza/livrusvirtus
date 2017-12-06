#ifndef CONPROFISSOES_H
#define CONPROFISSOES_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConProfissoes;

GtkWidget *frmConProfissoes_Criar();
void on_frmConProfissoes_gridConsulta_selection_changed(
               GtkTreeSelection* selection, gpointer user_data);
void on_frmConProfissoes_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data);
void on_frmConProfissoes_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data);
void on_frmConProfissoes_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data);

#endif

