#include "Principal.h"
#include "Consultas.h"
#include "ConAssuntos.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

GtkWidget *frmConAssuntos;

LISTAMSTR lstLinAssuntos;
GString *sSelAssuntos;

GtkWidget *frmConAssuntos_Criar()
{
  gint nLargura[2];
  GString *sRotulos[2];

  frmConAssuntos = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConAssuntos, "frmConAssuntos");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), "Assunto: ");

  nLargura[0] = 80;
  nLargura[1] = 180;

  sRotulos[0] = g_string_new("");
  sRotulos[1] = g_string_new("");
  g_string_assign(sRotulos[0], Rotinas_retUTF8("Código"));
  g_string_assign(sRotulos[1], "Assunto" );

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 2, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConAssuntos_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConAssuntos_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConAssuntos_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConAssuntos_btnFechar_clicked), NULL);

  sSelAssuntos = g_string_new("");

  return frmConAssuntos;
}

void on_frmConAssuntos_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinAssuntos, 
    &sSelAssuntos->str, selection);
}


void on_frmConAssuntos_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinAssuntos,
    ConsSQL_Assunto('S', "", Rotinas_retTexto(frmConsultas_edtDescricao)),
    STR_ASSNENC, 2);
}

void on_frmConAssuntos_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConAssuntos_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConAssuntos, sSelAssuntos->str);
}
