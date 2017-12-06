#ifndef CADIDIOMAS_H
#define CADIDIOMAS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadIdiomas;
extern GtkWidget *frmCadIdiomas_edtCodigo;
extern GtkWidget *frmCadIdiomas_edtDescricao;

GtkWidget *frmCadIdiomas_Criar(void);
gboolean frmCadIdiomas_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadIdiomas_edtCodigo_focus_out_event(GtkWidget * widget,
			      GdkEventFocus * event, gpointer user_data);
void on_frmCadIdiomas_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadIdiomas_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadIdiomas_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadIdiomas_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadIdiomas_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadIdiomas_btnLimpar_clicked(GtkButton *button,   
                                         gpointer user_data);
void on_frmCadIdiomas_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadIdiomas_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadIdiomas_destroy(GtkObject *object, gpointer user_data);

#endif

