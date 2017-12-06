#include "Principal.h"
#include "Consultas.h"
#include "ConEditoras.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinEditoras;
GString *sSelEditoras;

GtkWidget *frmConEditoras_Criar()
{
  gint nLargura[2];
  GString *sRotulos[2];

  frmConEditoras = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConEditoras, "frmConEditoras");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), "Editora: ");

  nLargura[0] = 80;
  nLargura[1] = 180;

  sRotulos[0] = g_string_new("");
  sRotulos[1] = g_string_new("");
  g_string_assign(sRotulos[0], Rotinas_retUTF8("Código"));
  g_string_assign(sRotulos[1], "Editora" );

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 2, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConEditoras_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConEditoras_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConEditoras_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConEditoras_btnFechar_clicked), NULL);

  sSelEditoras = g_string_new("");

  return frmConEditoras;
}

void on_frmConEditoras_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinEditoras, 
    &sSelEditoras->str, selection);
}

void on_frmConEditoras_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinEditoras,
    ConsSQL_Editora('S', "", Rotinas_retTexto(frmConsultas_edtDescricao)),
    STR_EDTNENC, 2);
}

void on_frmConEditoras_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConEditoras_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConEditoras, sSelEditoras->str);
}
