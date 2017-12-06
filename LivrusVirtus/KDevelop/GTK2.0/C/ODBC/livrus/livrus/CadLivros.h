#ifndef CADLIVROS_H
#define CADLIVROS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadLivros;
GtkWidget *frmCadLivros_edtCodigo;
GtkWidget *frmCadLivros_edtDescricao;
GtkWidget *frmCadLivros_edtCodEditora;
GtkWidget *frmCadLivros_edtEditora;
GtkWidget *frmCadLivros_edtEdicao;
GtkWidget *frmCadLivros_btnPEditora;
GtkWidget *frmCadLivros_edtAnoPubli;
GtkWidget *frmCadLivros_edtVolume;
GtkWidget *frmCadLivros_edtNPaginas;
GtkWidget *frmCadLivros_edtQtdEstoque;
GtkWidget *frmCadLivros_edtCodAssunto;
GtkWidget *frmCadLivros_edtAssunto;
GtkWidget *frmCadLivros_btnPAssunto;
GtkWidget *frmCadLivros_btnAdAssuntos;
GtkWidget *frmCadLivros_edtPreco;
GtkWidget *frmCadLivros_edtCodAutor;
GtkWidget *frmCadLivros_edtAutor;
GtkWidget *frmCadLivros_btnPAutor;
GtkWidget *frmCadLivros_btnAdAutores;
GtkWidget *frmCadLivros_lstAssuntos;
GtkWidget *frmCadLivros_lstAutores;
GtkWidget *frmCadLivros_cmbIdioma;
GtkWidget *frmCadLivros_cmbIdiomaEntrada;

GtkWidget *frmCadLivros_Criar(void);
gboolean frmCadLivros_ValidaDados(gboolean bTodosDados);
gboolean on_frmCadLivros_edtCodigo_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void on_frmCadLivros_btnNovo_clicked(GtkButton *button, 
                                     gpointer user_data);
void on_frmCadLivros_btnPesquisar_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadLivros_btnAnterior_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadLivros_btnProximo_clicked(GtkButton *button, 
                                        gpointer user_data);
void on_frmCadLivros_btnSalvar_clicked(GtkButton *button, 
                                       gpointer user_data);
void on_frmCadLivros_btnExcluir_clicked(GtkButton *button, 
                                        gpointer user_data);
void on_frmCadLivros_btnLimpar_clicked(GtkButton *button, 
                                       gpointer user_data);
void on_frmCadLivros_btnFechar_clicked(GtkButton *button, 
                                       gpointer user_data);
void on_frmCadLivros_destroy(GtkObject *object, gpointer user_data);
void frmCadLivros_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar);
void frmCadLivros_HabilitaDados(gboolean bHabilita);
void frmCadLivros_AdicionaCombo();
void frmCadLivros_SalvaLista(char sOpcao); 
void on_frmCadLivros_btnPEditora_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadLivros_btnPAssunto_clicked(GtkButton *button, 
                                         gpointer user_data);
void on_frmCadLivros_btnAdAssuntos_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmCadLivros_btnPAutor_clicked(GtkButton *button, 
                                       gpointer user_data);
void on_frmCadLivros_btnAdAutores_clicked(GtkButton *button, 
                                        gpointer user_data);
gboolean on_frmCadLivros_edtCodEditora_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
gboolean on_frmCadLivros_edtPreco_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
gboolean on_frmCadLivros_edtCodAssunto_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
gboolean on_frmCadLivros_edtCodAutor_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data);
void frmCadLivros_AtribuiIdioma(gchar *sIdioma);
gint frmCadLivros_retIdioma(G_CONST_RETURN gchar *sIdioma);
gboolean on_frmCadLivros_lstAssuntos_button_press_event(GtkWidget *widget,
				   GdkEventButton *event, gpointer user_data);
gboolean on_frmCadLivros_lstAutores_button_press_event(GtkWidget *widget,
				  GdkEventButton *event, gpointer user_data);
#endif
