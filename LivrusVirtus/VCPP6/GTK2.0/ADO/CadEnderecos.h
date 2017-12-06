#ifndef CADENDERECOS_H
#define CADENDERECOS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadEnderecos;
extern GtkWidget *frmCadEnderecos_edtCodigo;
extern GtkWidget *frmCadEnderecos_edtDescricao;
extern GtkWidget *frmCadEnderecos_edtBairro;
extern GtkWidget *frmCadEnderecos_edtCep;
extern GtkWidget *frmCadEnderecos_edtCidade;
extern GtkWidget *frmCadEnderecos_cmbEstado;
extern GtkWidget *frmCadEnderecos_cmbEstadoEntrada;

GtkWidget *frmCadEnderecos_Criar(void);
gboolean on_frmCadEnderecos_edtCodigo_focus_out_event (GtkWidget * widget,
			      GdkEventFocus * event, gpointer user_data);
void on_frmCadEnderecos_btnPesquisar_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnAnterior_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnProximo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnSalvar_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnExcluir_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnLimpar_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnFechar_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadEnderecos_destroy(GtkObject *object, gpointer user_data);
void frmCadEnderecos_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar);
void frmCadEnderecos_HabilitaDados(gboolean bHabilita);
void frmCadEnderecos_AdicionaCombo();
void frmCadEnderecos_AtribuiEstado(gchar *sEstado);

#endif
