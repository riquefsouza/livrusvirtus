#include "Principal.h"
#include "Consultas.h"
#include "ConIdiomas.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

GtkWidget *frmConIdiomas;

LISTAMSTR lstLinIdiomas;
GString *sSelIdiomas;

GtkWidget *frmConIdiomas_Criar()
{
  gint nLargura[2];
  GString *sRotulos[2];

  frmConIdiomas = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConIdiomas, "frmConIdiomas");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), "Idioma: ");

  nLargura[0] = 80;
  nLargura[1] = 180;

  sRotulos[0] = g_string_new("");
  sRotulos[1] = g_string_new("");
  g_string_assign(sRotulos[0], Rotinas_retUTF8("Código"));
  g_string_assign(sRotulos[1], "Idioma" );

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 2, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConIdiomas_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConIdiomas_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConIdiomas_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConIdiomas_btnFechar_clicked), NULL);

  sSelIdiomas = g_string_new("");

  return frmConIdiomas;
}

void on_frmConIdiomas_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinIdiomas, 
    &sSelIdiomas->str, selection);
}


void on_frmConIdiomas_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinIdiomas,
    ConsSQL_Idioma('S', "", Rotinas_retTexto(frmConsultas_edtDescricao)),
    STR_IDINENC, 2);
}

void on_frmConIdiomas_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConIdiomas_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConIdiomas, sSelIdiomas->str);
}
