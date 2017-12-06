#ifndef LOGIN_H
#define LOGIN_H

#include "resource.h"

GtkWidget *frmLogin;
GtkWidget *frmLogin_edtLogin;
GtkWidget *frmLogin_edtSenha;

GtkWidget *frmLogin_Criar();
void on_frmLogin_btnLogin_clicked (GtkButton * button, gpointer user_data);
void on_frmLogin_btnCancelar_clicked (GtkButton * button, gpointer user_data);

#endif

