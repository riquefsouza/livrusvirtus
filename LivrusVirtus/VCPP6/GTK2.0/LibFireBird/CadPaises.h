#ifndef CADPAISES_H
#define CADPAISES_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadPaises;
GtkWidget *frmCadPaises_edtCodigo;
GtkWidget *frmCadPaises_edtDescricao;

GtkWidget *frmCadPaises_Criar(void);
gboolean frmCadPaises_ValidaDados(gboolean bTodosDados);
void on_frmCadPaises_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadPaises_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadPaises_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadPaises_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadPaises_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadPaises_btnLimpar_clicked(GtkButton *button,   
                                         gpointer user_data);
void on_frmCadPaises_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadPaises_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadPaises_destroy(GtkObject *object, gpointer user_data);

#endif

