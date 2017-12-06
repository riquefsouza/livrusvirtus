#ifndef CADASTROS_H
#define CADASTROS_H

#include "resource.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadastros;
GtkWidget *frmCadastros_fixed1;
GtkWidget *frmCadastros_labCodigo;
GtkWidget *frmCadastros_btnNovo;
GtkWidget *frmCadastros_labDescricao;
GtkWidget *frmCadastros_btnPesquisar;
GtkWidget *frmCadastros_btnAnterior;
GtkWidget *frmCadastros_btnProximo;
GtkWidget *frmCadastros_btnSalvar;
GtkWidget *frmCadastros_btnExcluir;
GtkWidget *frmCadastros_btnLimpar;
GtkWidget *frmCadastros_btnFechar;

GtkWidget *frmCadastros_Criar(gboolean bIniciaBotoes, gchar* sTitulo,
                              GtkWidget **edtCodigo, GtkWidget **edtDescricao);
void frmCadastros_IniciaBotoes(gint nX1, gint nY1, gint nX2, gint nY2);
void frmCadastros_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar, 
  GtkWidget *edtCodigo, GtkWidget *edtDescricao);
void frmCadastros_HabilitaDados(gboolean bHabilita, GtkWidget *edtDescricao);
void frmCadastros_btnNovoClick(GtkWidget *edtCodigo, GtkWidget *edtDescricao);
void frmCadastros_NovoDado(GString *sTextoSql,
                           GtkWidget *edtCodigo, GtkWidget *edtDescricao);
void frmCadastros_btnLimparClick(GtkWidget *edtCodigo, GtkWidget *edtDescricao);
gboolean frmCadastros_ExcluirDados(gboolean bValidaDados, GString *sTextoSql,
                               GtkWidget *edtCodigo, GtkWidget *edtDescricao);
gboolean frmCadastros_PesquisarDados(LISTAMSTR *lstRegistros, 
  GString *sTextoSql, gchar *sMensagemErro,
  GtkWidget *edtCodigo, GtkWidget *edtDescricao);
gboolean frmCadastros_registroAnterior(LISTAMSTR *lstRegistros, 
  gint *nLinhaRegistro, GtkWidget *edtCodigo, GtkWidget *edtDescricao);
gboolean frmCadastros_registroProximo(LISTAMSTR *lstRegistros, 
  gint *nLinhaRegistro, GtkWidget *edtCodigo, GtkWidget *edtDescricao);
gboolean frmCadastros_SalvarDados(gboolean bValidaDados, GString *sTextoSql, 
  GString *sTextoUpdate, GString *sTextoInsert, gboolean bLimparDados,
  GtkWidget *edtCodigo, GtkWidget *edtDescricao);
void frmCadastros_ValidaCodigo(GtkWidget *edtCodigo);

#endif

