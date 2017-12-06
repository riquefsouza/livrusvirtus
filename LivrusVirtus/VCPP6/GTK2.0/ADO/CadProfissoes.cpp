#include "Principal.h"
#include "Cadastros.h"
#include "CadProfissoes.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadProfissoes;
GtkWidget *frmCadProfissoes_edtCodigo;
GtkWidget *frmCadProfissoes_edtDescricao;

LISTAMSTR lstRegProfissoes;
gint nRegProfissoes;

GtkWidget *frmCadProfissoes_Criar (void)
{
  frmCadProfissoes = frmCadastros_Criar(TRUE, STR_CADPROFISS, 
    &frmCadProfissoes_edtCodigo, &frmCadProfissoes_edtDescricao);
  gtk_widget_set_name(frmCadProfissoes, "frmCadProfissoes");
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), 
    Rotinas_retUTF8("Profissão: "));

  g_signal_connect ((gpointer) frmCadProfissoes, "destroy",
		    G_CALLBACK (on_frmCadProfissoes_destroy), NULL);
  g_signal_connect ((gpointer) frmCadProfissoes_edtCodigo, "focus_out_event",
		    G_CALLBACK (on_frmCadProfissoes_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadProfissoes_btnNovo_clicked), NULL);

  nRegProfissoes = 0;

  return frmCadProfissoes;
}

gboolean frmCadProfissoes_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadProfissoes_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadProfissoes_edtDescricao), STR_PROFNINF))
  		return FALSE;
	}
	return TRUE;
}

gboolean on_frmCadProfissoes_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  frmCadastros_ValidaCodigo(frmCadProfissoes_edtCodigo);
  return FALSE;
}

void on_frmCadProfissoes_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadProfissoes_edtCodigo, 
    frmCadProfissoes_edtDescricao);
  frmCadastros_NovoDado(ConsSQL_Profissao('N', 
    Rotinas_retTexto(frmCadProfissoes_edtCodigo),""),
    frmCadProfissoes_edtCodigo, frmCadProfissoes_edtDescricao);
}

void on_frmCadProfissoes_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  frmCadastros_PesquisarDados(&lstRegProfissoes, ConsSQL_Profissao('S',
    Rotinas_retTexto(frmCadProfissoes_edtCodigo),""), STR_PROFNENC, 
    frmCadProfissoes_edtCodigo, frmCadProfissoes_edtDescricao);
}

void on_frmCadProfissoes_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  frmCadastros_registroAnterior(&lstRegProfissoes, &nRegProfissoes, 
    frmCadProfissoes_edtCodigo, frmCadProfissoes_edtDescricao);
}

void on_frmCadProfissoes_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  frmCadastros_registroProximo(&lstRegProfissoes, &nRegProfissoes, 
    frmCadProfissoes_edtCodigo, frmCadProfissoes_edtDescricao);
}

void on_frmCadProfissoes_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  if (frmCadastros_SalvarDados(frmCadProfissoes_ValidaDados(TRUE),
    ConsSQL_Profissao('S', Rotinas_retTexto(frmCadProfissoes_edtCodigo), ""),
    ConsSQL_Profissao('U', Rotinas_retTexto(frmCadProfissoes_edtCodigo), 
      Rotinas_retTexto(frmCadProfissoes_edtDescricao)),
    ConsSQL_Profissao('I', Rotinas_retTexto(frmCadProfissoes_edtCodigo), 
      Rotinas_retTexto(frmCadProfissoes_edtDescricao)), TRUE,
      frmCadProfissoes_edtCodigo, frmCadProfissoes_edtDescricao))
    nRegProfissoes = 0;
}

void on_frmCadProfissoes_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadProfissoes_ValidaDados(FALSE),
    ConsSQL_Profissao('D', Rotinas_retTexto(frmCadProfissoes_edtCodigo),""),
    frmCadProfissoes_edtCodigo, frmCadProfissoes_edtDescricao))
    nRegProfissoes = 0;
}

void on_frmCadProfissoes_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadProfissoes_edtCodigo, 
    frmCadProfissoes_edtDescricao);
  nRegProfissoes = 0;
}

void on_frmCadProfissoes_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadProfissoes, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadProfissoes_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadProfissoes);
}
