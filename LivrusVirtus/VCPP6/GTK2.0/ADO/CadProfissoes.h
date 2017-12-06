#ifndef CADPROFISSOES_H
#define CADPROFISSOES_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadProfissoes;
extern GtkWidget *frmCadProfissoes_edtCodigo;
extern GtkWidget *frmCadProfissoes_edtDescricao;

GtkWidget *frmCadProfissoes_Criar(void);
gboolean frmCadProfissoes_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadProfissoes_edtCodigo_focus_out_event(GtkWidget * widget,
			      GdkEventFocus * event, gpointer user_data);
void on_frmCadProfissoes_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadProfissoes_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadProfissoes_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadProfissoes_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadProfissoes_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadProfissoes_btnLimpar_clicked(GtkButton *button,   
                                         gpointer user_data);
void on_frmCadProfissoes_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadProfissoes_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadProfissoes_destroy(GtkObject *object, gpointer user_data);

#endif

