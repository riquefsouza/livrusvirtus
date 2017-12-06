#ifndef ALTERARSENHA_H
#define ALTERARSENHA_H

#include "resource.h"

extern GtkWidget *frmAlterarSenha;
extern GtkWidget *frmAlterarSenha_edtLogin;
extern GtkWidget *frmAlterarSenha_edtSenhaAtual;
extern GtkWidget *frmAlterarSenha_edtNovaSenha;
extern GtkWidget *frmAlterarSenha_edtConfirmaSenha;

GtkWidget *frmAlterarSenha_Criar(void);
void on_frmAlterarSenha_destroy(GtkObject *object, gpointer user_data);
void on_frmAlterarSenha_btnSalvar_clicked (GtkButton * button, gpointer user_data);
void on_frmAlterarSenha_btnLimpar_clicked (GtkButton * button, gpointer user_data);
void on_frmAlterarSenha_btnFechar_clicked (GtkButton * button, gpointer user_data);
gboolean frmAlterarSenha_ValidaDados();

#endif

