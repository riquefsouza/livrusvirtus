#ifndef CADLIVROS_H
#define CADLIVROS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadLivros;
extern GtkWidget *frmCadLivros_edtCodigo;
extern GtkWidget *frmCadLivros_edtDescricao;
extern GtkWidget *frmCadLivros_edtCodEditora;
extern GtkWidget *frmCadLivros_edtEditora;
extern GtkWidget *frmCadLivros_edtEdicao;
extern GtkWidget *frmCadLivros_btnPEditora;
extern GtkWidget *frmCadLivros_edtAnoPubli;
extern GtkWidget *frmCadLivros_edtVolume;
extern GtkWidget *frmCadLivros_edtNPaginas;
extern GtkWidget *frmCadLivros_edtQtdEstoque;
extern GtkWidget *frmCadLivros_edtCodAssunto;
extern GtkWidget *frmCadLivros_edtAssunto;
extern GtkWidget *frmCadLivros_btnPAssunto;
extern GtkWidget *frmCadLivros_btnAdAssuntos;
extern GtkWidget *frmCadLivros_edtPreco;
extern GtkWidget *frmCadLivros_edtCodAutor;
extern GtkWidget *frmCadLivros_edtAutor;
extern GtkWidget *frmCadLivros_btnPAutor;
extern GtkWidget *frmCadLivros_btnAdAutores;
extern GtkWidget *frmCadLivros_lstAssuntos;
extern GtkWidget *frmCadLivros_lstAutores;
extern GtkWidget *frmCadLivros_cmbIdioma;
extern GtkWidget *frmCadLivros_cmbIdiomaEntrada;

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
