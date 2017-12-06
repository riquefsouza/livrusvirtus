#ifndef CADASSUNTOS_H
#define CADASSUNTOS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadAssuntos;
GtkWidget *frmCadAssuntos_edtCodigo;
GtkWidget *frmCadAssuntos_edtDescricao;

GtkWidget *frmCadAssuntos_Criar(void);
gboolean frmCadAssuntos_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadAssuntos_edtCodigo_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void on_frmCadAssuntos_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadAssuntos_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadAssuntos_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadAssuntos_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadAssuntos_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadAssuntos_btnLimpar_clicked(GtkButton *button,   
                                         gpointer user_data);
void on_frmCadAssuntos_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadAssuntos_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadAssuntos_destroy(GtkObject *object, gpointer user_data);

#endif

