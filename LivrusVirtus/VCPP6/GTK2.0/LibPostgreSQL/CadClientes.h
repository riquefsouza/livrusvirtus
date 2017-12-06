#ifndef CADCLIENTES_H
#define CADCLIENTES_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadClientes;
GtkWidget *frmCadClientes_edtCodigo;
GtkWidget *frmCadClientes_edtDescricao;
GtkWidget *frmCadClientes_edtIdentidade;
GtkWidget *frmCadClientes_edtEmail;
GtkWidget *frmCadClientes_edtTelefone;
GtkWidget *frmCadClientes_edtDtNasc;
GtkWidget *frmCadClientes_grpSexo;
GtkWidget *frmCadClientes_rbMasculino;
GtkWidget *frmCadClientes_rbFeminino;
GtkWidget *frmCadClientes_edtCodPais;
GtkWidget *frmCadClientes_edtPais;
GtkWidget *frmCadClientes_edtCodProfissao;
GtkWidget *frmCadClientes_edtProfissao;
GtkWidget *frmCadClientes_edtCodEndereco;
GtkWidget *frmCadClientes_edtLogradouro;
GtkWidget *frmCadClientes_edtBairro;
GtkWidget *frmCadClientes_edtCep;
GtkWidget *frmCadClientes_edtCidade;
GtkWidget *frmCadClientes_edtEstado;
GtkWidget *frmCadClientes_grpEndereco;
GtkWidget *frmCadClientes_btnPEndereco;
GtkWidget *frmCadClientes_btnPPais;
GtkWidget *frmCadClientes_btnPProfissao;

GtkWidget *frmCadClientes_Criar(void);
gboolean frmCadClientes_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadClientes_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void on_frmCadClientes_btnNovo_clicked(GtkButton *button, gpointer user_data);
void on_frmCadClientes_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data);
void on_frmCadClientes_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data);
void on_frmCadClientes_btnProximo_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadClientes_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadClientes_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadClientes_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadClientes_destroy(GtkObject *object, gpointer user_data);
void on_frmCadClientes_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data);
void frmCadClientes_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar);
void frmCadClientes_HabilitaDados(gboolean bHabilita);
gboolean on_frmCadClientes_edtDtNasc_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
gboolean on_frmCadClientes_edtCodEndereco_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void on_frmCadClientes_btnPEndereco_clicked(GtkButton *button, 
                                            gpointer user_data);
gboolean on_frmCadClientes_edtCodPais_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void on_frmCadClientes_btnPPais_clicked(GtkButton *button, 
                                        gpointer user_data);
gboolean on_frmCadClientes_edtCodProfissao_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void on_frmCadClientes_btnPProfissao_clicked(GtkButton *button, 
                                             gpointer user_data);

#endif

