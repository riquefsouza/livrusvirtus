#ifndef CADASTROS_H
#define CADASTROS_H

#include "resource.h"
#include "RotinasGlobais.h"

extern GtkWidget *frmCadastros;
extern GtkWidget *frmCadastros_fixed1;
extern GtkWidget *frmCadastros_labCodigo;
extern GtkWidget *frmCadastros_btnNovo;
extern GtkWidget *frmCadastros_labDescricao;
extern GtkWidget *frmCadastros_btnPesquisar;
extern GtkWidget *frmCadastros_btnAnterior;
extern GtkWidget *frmCadastros_btnProximo;
extern GtkWidget *frmCadastros_btnSalvar;
extern GtkWidget *frmCadastros_btnExcluir;
extern GtkWidget *frmCadastros_btnLimpar;
extern GtkWidget *frmCadastros_btnFechar;

extern GtkWidget *frmCadastros_Criar(gboolean bIniciaBotoes, gchar* sTitulo,
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

