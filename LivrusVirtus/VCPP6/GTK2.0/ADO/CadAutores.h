#ifndef CADAUTORES_H
#define CADAUTORES_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadAutores;
extern GtkWidget *frmCadAutores_edtCodigo;
extern GtkWidget *frmCadAutores_edtDescricao;

GtkWidget *frmCadAutores_Criar(void);
gboolean frmCadAutores_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadAutores_edtCodigo_focus_out_event(GtkWidget * widget,
			      GdkEventFocus * event, gpointer user_data);
void on_frmCadAutores_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadAutores_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadAutores_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadAutores_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadAutores_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadAutores_btnLimpar_clicked(GtkButton *button,   
                                         gpointer user_data);
void on_frmCadAutores_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadAutores_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadAutores_destroy(GtkObject *object, gpointer user_data);

#endif

