#include "Principal.h"
#include "Cadastros.h"
#include "CadAutores.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

GtkWidget *frmCadAutores;
GtkWidget *frmCadAutores_edtCodigo;
GtkWidget *frmCadAutores_edtDescricao;

LISTAMSTR lstRegAutores;
gint nRegAutores;

GtkWidget *frmCadAutores_Criar (void)
{
  frmCadAutores = frmCadastros_Criar(TRUE, STR_CADAUTOR, 
    &frmCadAutores_edtCodigo, &frmCadAutores_edtDescricao);
  gtk_widget_set_name(frmCadAutores, "frmCadAutores");
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), "Autor: ");

  g_signal_connect ((gpointer) frmCadAutores, "destroy",
		    G_CALLBACK (on_frmCadAutores_destroy), NULL);
  g_signal_connect ((gpointer) frmCadAutores_edtCodigo, "focus_out_event",
		    G_CALLBACK (on_frmCadAutores_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadAutores_btnNovo_clicked), NULL);

  nRegAutores = 0;

  return frmCadAutores;
}

gboolean frmCadAutores_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadAutores_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadAutores_edtDescricao), STR_AUTNINF))
  		return FALSE;
	}
	return TRUE;
}

gboolean on_frmCadAutores_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  frmCadastros_ValidaCodigo(frmCadAutores_edtCodigo);
  return FALSE;
}

void on_frmCadAutores_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadAutores_edtCodigo, 
    frmCadAutores_edtDescricao);
  frmCadastros_NovoDado(ConsSQL_Autor('N', 
    Rotinas_retTexto(frmCadAutores_edtCodigo),""),
    frmCadAutores_edtCodigo, frmCadAutores_edtDescricao);
}

void on_frmCadAutores_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  frmCadastros_PesquisarDados(&lstRegAutores, ConsSQL_Autor('S',
    Rotinas_retTexto(frmCadAutores_edtCodigo),""), STR_AUTNENC,
    frmCadAutores_edtCodigo, frmCadAutores_edtDescricao);
}

void on_frmCadAutores_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  frmCadastros_registroAnterior(&lstRegAutores, &nRegAutores,
    frmCadAutores_edtCodigo, frmCadAutores_edtDescricao);	
}

void on_frmCadAutores_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  frmCadastros_registroProximo(&lstRegAutores, &nRegAutores,
    frmCadAutores_edtCodigo, frmCadAutores_edtDescricao);	
}

void on_frmCadAutores_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  if (frmCadastros_SalvarDados(frmCadAutores_ValidaDados(TRUE),
    ConsSQL_Autor('S', Rotinas_retTexto(frmCadAutores_edtCodigo), ""),
    ConsSQL_Autor('U', Rotinas_retTexto(frmCadAutores_edtCodigo), 
      Rotinas_retTexto(frmCadAutores_edtDescricao)),
    ConsSQL_Autor('I', Rotinas_retTexto(frmCadAutores_edtCodigo), 
      Rotinas_retTexto(frmCadAutores_edtDescricao)), TRUE,
      frmCadAutores_edtCodigo, frmCadAutores_edtDescricao))
    nRegAutores = 0;
}

void on_frmCadAutores_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadAutores_ValidaDados(FALSE),
    ConsSQL_Autor('D', Rotinas_retTexto(frmCadAutores_edtCodigo),""),
    frmCadAutores_edtCodigo, frmCadAutores_edtDescricao))
    nRegAutores = 0;
}

void on_frmCadAutores_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadAutores_edtCodigo, 
    frmCadAutores_edtDescricao);
  nRegAutores = 0;
}

void on_frmCadAutores_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadAutores, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadAutores_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadAutores);
}
