#include "Principal.h"
#include "Cadastros.h"
#include "CadPaises.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

LISTAMSTR lstRegPaises;
gint nRegPaises;

GtkWidget *frmCadPaises_Criar (void)
{
  frmCadPaises = frmCadastros_Criar(TRUE, STR_CADPAIS, 
    &frmCadPaises_edtCodigo, &frmCadPaises_edtDescricao);
  gtk_widget_set_name(frmCadPaises, "frmCadPaises");
  gtk_entry_set_max_length (GTK_ENTRY (frmCadPaises_edtCodigo), 3);
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), 
    Rotinas_retUTF8("País: "));

  g_signal_connect ((gpointer) frmCadPaises, "destroy",
		    G_CALLBACK (on_frmCadPaises_destroy), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadPaises_btnNovo_clicked), NULL);

  nRegPaises = 0;

  return frmCadPaises;
}

gboolean frmCadPaises_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadPaises_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadPaises_edtDescricao), STR_PAISNINF))
  		return FALSE;
	}
	return TRUE;
}

void on_frmCadPaises_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadPaises_edtCodigo, 
    frmCadPaises_edtDescricao);
}

void on_frmCadPaises_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  frmCadastros_PesquisarDados(&lstRegPaises, ConsSQL_Pais('S',
    Rotinas_retTexto(frmCadPaises_edtCodigo),""), STR_PAISNENC, 
    frmCadPaises_edtCodigo, frmCadPaises_edtDescricao);
}

void on_frmCadPaises_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  frmCadastros_registroAnterior(&lstRegPaises, &nRegPaises, 
    frmCadPaises_edtCodigo, frmCadPaises_edtDescricao);
}

void on_frmCadPaises_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  frmCadastros_registroProximo(&lstRegPaises, &nRegPaises, 
    frmCadPaises_edtCodigo, frmCadPaises_edtDescricao);
}

void on_frmCadPaises_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  if (frmCadastros_SalvarDados(frmCadPaises_ValidaDados(TRUE),
    ConsSQL_Pais('S', Rotinas_retTexto(frmCadPaises_edtCodigo), ""),
    ConsSQL_Pais('U', Rotinas_retTexto(frmCadPaises_edtCodigo), 
      Rotinas_retTexto(frmCadPaises_edtDescricao)),
    ConsSQL_Pais('I', Rotinas_retTexto(frmCadPaises_edtCodigo), 
      Rotinas_retTexto(frmCadPaises_edtDescricao)), TRUE,
      frmCadPaises_edtCodigo, frmCadPaises_edtDescricao))
    nRegPaises = 0;
}

void on_frmCadPaises_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadPaises_ValidaDados(FALSE),
    ConsSQL_Pais('D', Rotinas_retTexto(frmCadPaises_edtCodigo),""),
    frmCadPaises_edtCodigo, frmCadPaises_edtDescricao))
    nRegPaises = 0;
}

void on_frmCadPaises_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadPaises_edtCodigo, 
    frmCadPaises_edtDescricao);
  nRegPaises = 0;
}

void on_frmCadPaises_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadPaises, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadPaises_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadPaises);
}
