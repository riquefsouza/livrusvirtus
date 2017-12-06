#ifndef VENDERLIVROS_H
#define VENDERLIVROS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmVenderLivros;
extern GtkWidget *frmVenderLivros_edtDtHrVenda;
extern GtkWidget *frmVenderLivros_edtCPF;
extern GtkWidget *frmVenderLivros_edtISBN;
extern GtkWidget *frmVenderLivros_edtCliente;
extern GtkWidget *frmVenderLivros_btnPCliente;
extern GtkWidget *frmVenderLivros_edtLivro;
extern GtkWidget *frmVenderLivros_btnPLivro;
extern GtkWidget *frmVenderLivros_btnAdLivros;
extern GtkWidget *frmVenderLivros_lstLivros;
extern GtkWidget *frmVenderLivros_edtPrecoTotal;

GtkWidget *frmVenderLivros_Criar(void);
void frmVenderLivros_LimpaDados();
gboolean frmVenderLivros_ValidaDados();
gboolean frmVenderLivros_SalvaLista();
void on_frmVenderLivros_destroy(GtkObject *object, gpointer user_data);
gboolean on_frmVenderLivros_edtCPF_focus_out_event(GtkWidget *widget, 
                          GdkEventFocus *event, gpointer user_data);
gboolean on_frmVenderLivros_edtISBN_focus_out_event(GtkWidget *widget, 
                              GdkEventFocus *event, gpointer user_data);
gboolean on_frmVenderLivros_lstLivros_button_press_event(GtkWidget *widget,
      				 GdkEventButton *event, gpointer user_data);
void on_frmVenderLivros_btnVender_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmVenderLivros_btnLimpar_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmVenderLivros_btnFechar_clicked(GtkButton *button, 
                                          gpointer user_data);
void on_frmVenderLivros_btnPCliente_clicked(GtkButton *button,
                                            gpointer user_data);
void on_frmVenderLivros_btnAdLivros_clicked(GtkButton *button,
               				gpointer user_data);
void on_frmVenderLivros_btnPLivro_clicked(GtkButton *button, 
                                          gpointer user_data);
#endif
