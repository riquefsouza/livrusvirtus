#include "Principal.h"
#include "Cadastros.h"
#include "CadIdiomas.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

LISTAMSTR lstRegIdiomas;
gint nRegIdiomas;

GtkWidget *frmCadIdiomas_Criar (void)
{
  frmCadIdiomas = frmCadastros_Criar(TRUE, STR_CADIDIOMA, 
    &frmCadIdiomas_edtCodigo, &frmCadIdiomas_edtDescricao);
  gtk_widget_set_name(frmCadIdiomas, "frmCadIdiomas");
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), "Idioma: ");

  g_signal_connect ((gpointer) frmCadIdiomas, "destroy",
		    G_CALLBACK (on_frmCadIdiomas_destroy), NULL);
  g_signal_connect ((gpointer) frmCadIdiomas_edtCodigo, "focus_out_event",
		    G_CALLBACK (on_frmCadIdiomas_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadIdiomas_btnNovo_clicked), NULL);

  nRegIdiomas = 0;

  return frmCadIdiomas;
}

gboolean frmCadIdiomas_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadIdiomas_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadIdiomas_edtDescricao), STR_IDININF))
  		return FALSE;
	}
	return TRUE;
}

gboolean on_frmCadIdiomas_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  frmCadastros_ValidaCodigo(frmCadIdiomas_edtCodigo);
  return FALSE;
}

void on_frmCadIdiomas_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadIdiomas_edtCodigo, 
    frmCadIdiomas_edtDescricao);
  frmCadastros_NovoDado(ConsSQL_Idioma('N', 
    Rotinas_retTexto(frmCadIdiomas_edtCodigo),""),
    frmCadIdiomas_edtCodigo, frmCadIdiomas_edtDescricao);
}

void on_frmCadIdiomas_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  frmCadastros_PesquisarDados(&lstRegIdiomas, ConsSQL_Idioma('S',
    Rotinas_retTexto(frmCadIdiomas_edtCodigo),""), STR_IDINENC, 
    frmCadIdiomas_edtCodigo, frmCadIdiomas_edtDescricao);
}

void on_frmCadIdiomas_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  frmCadastros_registroAnterior(&lstRegIdiomas, &nRegIdiomas, 
    frmCadIdiomas_edtCodigo, frmCadIdiomas_edtDescricao);
}

void on_frmCadIdiomas_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  frmCadastros_registroProximo(&lstRegIdiomas, &nRegIdiomas, 
    frmCadIdiomas_edtCodigo, frmCadIdiomas_edtDescricao);
}

void on_frmCadIdiomas_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  if (frmCadastros_SalvarDados(frmCadIdiomas_ValidaDados(TRUE),
    ConsSQL_Idioma('S', Rotinas_retTexto(frmCadIdiomas_edtCodigo), ""),
    ConsSQL_Idioma('U', Rotinas_retTexto(frmCadIdiomas_edtCodigo), 
      Rotinas_retTexto(frmCadIdiomas_edtDescricao)),
    ConsSQL_Idioma('I', Rotinas_retTexto(frmCadIdiomas_edtCodigo), 
      Rotinas_retTexto(frmCadIdiomas_edtDescricao)), TRUE,
      frmCadIdiomas_edtCodigo, frmCadIdiomas_edtDescricao))
    nRegIdiomas = 0;
}

void on_frmCadIdiomas_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadIdiomas_ValidaDados(FALSE),
    ConsSQL_Idioma('D', Rotinas_retTexto(frmCadIdiomas_edtCodigo),""),
    frmCadIdiomas_edtCodigo, frmCadIdiomas_edtDescricao))
    nRegIdiomas = 0;
}

void on_frmCadIdiomas_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadIdiomas_edtCodigo, 
    frmCadIdiomas_edtDescricao);
  nRegIdiomas = 0;
}

void on_frmCadIdiomas_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadIdiomas, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadIdiomas_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadIdiomas);
}
