#include "Principal.h"
#include "Cadastros.h"
#include "CadEditoras.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

LISTAMSTR lstRegEditoras;
gint nRegEditoras;

GtkWidget *frmCadEditoras_Criar (void)
{
  frmCadEditoras = frmCadastros_Criar(TRUE, STR_CADEDITORA, 
    &frmCadEditoras_edtCodigo, &frmCadEditoras_edtDescricao);
  gtk_widget_set_name(frmCadEditoras, "frmCadEditoras");
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), "Editora: ");

  g_signal_connect ((gpointer) frmCadEditoras, "destroy",
		    G_CALLBACK (on_frmCadEditoras_destroy), NULL);
  g_signal_connect ((gpointer) frmCadEditoras_edtCodigo, "focus_out_event",
		    G_CALLBACK (on_frmCadEditoras_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadEditoras_btnNovo_clicked), NULL);

  nRegEditoras = 0;

  return frmCadEditoras;
}

gboolean frmCadEditoras_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadEditoras_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadEditoras_edtDescricao), STR_EDTNINF))
  		return FALSE;
	}
	return TRUE;
}

gboolean on_frmCadEditoras_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  frmCadastros_ValidaCodigo(frmCadEditoras_edtCodigo);
  return FALSE;
}

void on_frmCadEditoras_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadEditoras_edtCodigo, 
    frmCadEditoras_edtDescricao);
  frmCadastros_NovoDado(ConsSQL_Editora('N', 
    Rotinas_retTexto(frmCadEditoras_edtCodigo),""),
    frmCadEditoras_edtCodigo, frmCadEditoras_edtDescricao);
}

void on_frmCadEditoras_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  frmCadastros_PesquisarDados(&lstRegEditoras, ConsSQL_Editora('S',
    Rotinas_retTexto(frmCadEditoras_edtCodigo),""), STR_EDTNENC,
    frmCadEditoras_edtCodigo, frmCadEditoras_edtDescricao);
}

void on_frmCadEditoras_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  frmCadastros_registroAnterior(&lstRegEditoras, &nRegEditoras,
    frmCadEditoras_edtCodigo, frmCadEditoras_edtDescricao);
}

void on_frmCadEditoras_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  frmCadastros_registroProximo(&lstRegEditoras, &nRegEditoras,
    frmCadEditoras_edtCodigo, frmCadEditoras_edtDescricao);
}

void on_frmCadEditoras_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  if (frmCadastros_SalvarDados(frmCadEditoras_ValidaDados(TRUE),
    ConsSQL_Editora('S', Rotinas_retTexto(frmCadEditoras_edtCodigo), ""),
    ConsSQL_Editora('U', Rotinas_retTexto(frmCadEditoras_edtCodigo), 
      Rotinas_retTexto(frmCadEditoras_edtDescricao)),
    ConsSQL_Editora('I', Rotinas_retTexto(frmCadEditoras_edtCodigo), 
      Rotinas_retTexto(frmCadEditoras_edtDescricao)), TRUE,
      frmCadEditoras_edtCodigo, frmCadEditoras_edtDescricao))
    nRegEditoras = 0;
}

void on_frmCadEditoras_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadEditoras_ValidaDados(FALSE),
    ConsSQL_Editora('D', Rotinas_retTexto(frmCadEditoras_edtCodigo),""),
    frmCadEditoras_edtCodigo, frmCadEditoras_edtDescricao))
    nRegEditoras = 0;
}

void on_frmCadEditoras_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadEditoras_edtCodigo, 
    frmCadEditoras_edtDescricao);
  nRegEditoras = 0;
}

void on_frmCadEditoras_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadEditoras, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadEditoras_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadEditoras);
}
