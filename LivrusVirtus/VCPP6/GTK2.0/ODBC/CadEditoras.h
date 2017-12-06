#ifndef CADEDITORAS_H
#define CADEDITORAS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadEditoras;
GtkWidget *frmCadEditoras_edtCodigo;
GtkWidget *frmCadEditoras_edtDescricao;

GtkWidget *frmCadEditoras_Criar(void);
gboolean frmCadEditoras_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadEditoras_edtCodigo_focus_out_event(GtkWidget * widget,
			      GdkEventFocus * event, gpointer user_data);
void on_frmCadEditoras_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadEditoras_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadEditoras_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadEditoras_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadEditoras_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadEditoras_btnLimpar_clicked(GtkButton *button,   
                                         gpointer user_data);
void on_frmCadEditoras_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadEditoras_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEditoras_destroy(GtkObject *object, gpointer user_data);

#endif

