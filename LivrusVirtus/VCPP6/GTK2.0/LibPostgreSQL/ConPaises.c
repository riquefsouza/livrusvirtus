#include "Principal.h"
#include "Consultas.h"
#include "ConPaises.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinPaises;
GString *sSelPaises;

GtkWidget *frmConPaises_Criar()
{
  gint nLargura[2];
  GString *sRotulos[2];

  frmConPaises = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConPaises, "frmConPaises");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), Rotinas_retUTF8("Pa�s: "));

  nLargura[0] = 80;
  nLargura[1] = 180;

  sRotulos[0] = g_string_new("");
  sRotulos[1] = g_string_new("");
  g_string_assign(sRotulos[0], Rotinas_retUTF8("C�digo"));
  g_string_assign(sRotulos[1], Rotinas_retUTF8("Pa�s") );

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 2, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConPaises_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConPaises_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConPaises_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConPaises_btnFechar_clicked), NULL);

  sSelPaises = g_string_new("");

  return frmConPaises;
}

void on_frmConPaises_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinPaises, 
    &sSelPaises->str, selection);
}

void on_frmConPaises_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinPaises,
    ConsSQL_Pais('S', "", Rotinas_retTexto(frmConsultas_edtDescricao)),
    STR_PAISNENC, 2);
}

void on_frmConPaises_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConPaises_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConPaises, sSelPaises->str);
}