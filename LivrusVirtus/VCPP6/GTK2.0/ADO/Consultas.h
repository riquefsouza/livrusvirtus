#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmConsultas;
extern GtkWidget *frmConsultas_labDescricao;
extern GtkWidget *frmConsultas_edtDescricao;
extern GtkWidget *frmConsultas_btnPesquisar;
extern GtkWidget *frmConsultas_gridConsulta;
extern GtkTreeSelection *frmConsultas_selection;
extern GtkWidget *frmConsultas_labRegistros;
extern GtkWidget *frmConsultas_btnLimpar;
extern GtkWidget *frmConsultas_btnFechar;

GtkWidget *frmConsultas_Criar(gchar* sTitulo);
void frmConsultas_Fecha(GtkWidget *frmCon, gchar *sSelecionado);
void frmConsultas_LimparDados();
void frmConsultas_PesquisarDados(LISTAMSTR *lstLinhas, GString *sTextoSql, 
                                 gchar *sMensagemErro, gint nQtdCols);
void frmConsultas_setLabRegistros(LISTAMSTR *lstLinhas, gint nLinha);
void frmConsultas_setSelecionado(LISTAMSTR *lstLinhas, gchar **sSelecionado,
                                  GtkTreeSelection *selection);


#endif

