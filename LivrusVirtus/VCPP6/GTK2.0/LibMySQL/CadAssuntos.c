#include "Principal.h"
#include "Cadastros.h"
#include "CadAssuntos.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

LISTAMSTR lstRegAssuntos;
gint nRegAssuntos;

GtkWidget *frmCadAssuntos_Criar (void)
{
  frmCadAssuntos = frmCadastros_Criar(TRUE, STR_CADASSUNTO, 
    &frmCadAssuntos_edtCodigo, &frmCadAssuntos_edtDescricao);
  gtk_widget_set_name(frmCadAssuntos, "frmCadAssuntos");
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), "Assunto: ");

  g_signal_connect ((gpointer) frmCadAssuntos, "destroy",
		    G_CALLBACK (on_frmCadAssuntos_destroy), NULL);
  g_signal_connect ((gpointer) frmCadAssuntos_edtCodigo, "focus_out_event",
		    G_CALLBACK (on_frmCadAssuntos_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadAssuntos_btnNovo_clicked), NULL);

  nRegAssuntos = 0;

  return frmCadAssuntos;
}

gboolean frmCadAssuntos_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadAssuntos_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadAssuntos_edtDescricao), STR_ASSNINF))
  		return FALSE;
	}
	return TRUE;
}

gboolean on_frmCadAssuntos_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  frmCadastros_ValidaCodigo(frmCadAssuntos_edtCodigo);
  return FALSE;
}

void on_frmCadAssuntos_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadAssuntos_edtCodigo, 
    frmCadAssuntos_edtDescricao);
  frmCadastros_NovoDado(ConsSQL_Assunto('N', 
    Rotinas_retTexto(frmCadAssuntos_edtCodigo),""),
    frmCadAssuntos_edtCodigo, frmCadAssuntos_edtDescricao);
}

void on_frmCadAssuntos_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  frmCadastros_PesquisarDados(&lstRegAssuntos, ConsSQL_Assunto('S',
    Rotinas_retTexto(frmCadAssuntos_edtCodigo),""), STR_ASSNENC,
    frmCadAssuntos_edtCodigo, frmCadAssuntos_edtDescricao);
}

void on_frmCadAssuntos_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  frmCadastros_registroAnterior(&lstRegAssuntos, &nRegAssuntos,
    frmCadAssuntos_edtCodigo, frmCadAssuntos_edtDescricao);	
}

void on_frmCadAssuntos_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  frmCadastros_registroProximo(&lstRegAssuntos, &nRegAssuntos,
    frmCadAssuntos_edtCodigo, frmCadAssuntos_edtDescricao);	
}

void on_frmCadAssuntos_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  if (frmCadastros_SalvarDados(frmCadAssuntos_ValidaDados(TRUE),
    ConsSQL_Assunto('S', Rotinas_retTexto(frmCadAssuntos_edtCodigo), ""),
    ConsSQL_Assunto('U', Rotinas_retTexto(frmCadAssuntos_edtCodigo), 
      Rotinas_retTexto(frmCadAssuntos_edtDescricao)),
    ConsSQL_Assunto('I', Rotinas_retTexto(frmCadAssuntos_edtCodigo), 
      Rotinas_retTexto(frmCadAssuntos_edtDescricao)), TRUE,
      frmCadAssuntos_edtCodigo, frmCadAssuntos_edtDescricao))
    nRegAssuntos = 0;
}

void on_frmCadAssuntos_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadAssuntos_ValidaDados(FALSE),
    ConsSQL_Assunto('D', Rotinas_retTexto(frmCadAssuntos_edtCodigo),""),
    frmCadAssuntos_edtCodigo, frmCadAssuntos_edtDescricao))
    nRegAssuntos = 0;
}

void on_frmCadAssuntos_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadAssuntos_edtCodigo, 
    frmCadAssuntos_edtDescricao);
  nRegAssuntos = 0;
}

void on_frmCadAssuntos_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadAssuntos, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadAssuntos_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadAssuntos);
}
