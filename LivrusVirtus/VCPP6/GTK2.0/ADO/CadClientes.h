#ifndef CADCLIENTES_H
#define CADCLIENTES_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadClientes;
extern GtkWidget *frmCadClientes_edtCodigo;
extern GtkWidget *frmCadClientes_edtDescricao;
extern GtkWidget *frmCadClientes_edtIdentidade;
extern GtkWidget *frmCadClientes_edtEmail;
extern GtkWidget *frmCadClientes_edtTelefone;
extern GtkWidget *frmCadClientes_edtDtNasc;
extern GtkWidget *frmCadClientes_grpSexo;
extern GtkWidget *frmCadClientes_rbMasculino;
extern GtkWidget *frmCadClientes_rbFeminino;
extern GtkWidget *frmCadClientes_edtCodPais;
extern GtkWidget *frmCadClientes_edtPais;
extern GtkWidget *frmCadClientes_edtCodProfissao;
extern GtkWidget *frmCadClientes_edtProfissao;
extern GtkWidget *frmCadClientes_edtCodEndereco;
extern GtkWidget *frmCadClientes_edtLogradouro;
extern GtkWidget *frmCadClientes_edtBairro;
extern GtkWidget *frmCadClientes_edtCep;
extern GtkWidget *frmCadClientes_edtCidade;
extern GtkWidget *frmCadClientes_edtEstado;
extern GtkWidget *frmCadClientes_grpEndereco;
extern GtkWidget *frmCadClientes_btnPEndereco;
extern GtkWidget *frmCadClientes_btnPPais;
extern GtkWidget *frmCadClientes_btnPProfissao;

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

