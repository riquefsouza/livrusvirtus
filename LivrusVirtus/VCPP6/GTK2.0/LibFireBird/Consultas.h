#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmConsultas;
GtkWidget *frmConsultas_labDescricao;
GtkWidget *frmConsultas_edtDescricao;
GtkWidget *frmConsultas_btnPesquisar;
GtkWidget *frmConsultas_gridConsulta;
GtkTreeSelection *frmConsultas_selection;
GtkWidget *frmConsultas_labRegistros;
GtkWidget *frmConsultas_btnLimpar;
GtkWidget *frmConsultas_btnFechar;

GtkWidget *frmConsultas_Criar(gchar* sTitulo);
void frmConsultas_Fecha(GtkWidget *frmCon, gchar *sSelecionado);
void frmConsultas_LimparDados();
void frmConsultas_PesquisarDados(LISTAMSTR *lstLinhas, GString *sTextoSql, 
                                 gchar *sMensagemErro, gint nQtdCols);
void frmConsultas_setLabRegistros(LISTAMSTR *lstLinhas, gint nLinha);
void frmConsultas_setSelecionado(LISTAMSTR *lstLinhas, gchar **sSelecionado,
                                  GtkTreeSelection *selection);


#endif

