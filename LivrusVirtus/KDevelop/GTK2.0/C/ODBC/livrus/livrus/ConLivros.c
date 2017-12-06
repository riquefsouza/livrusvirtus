#include "Principal.h"
#include "Consultas.h"
#include "ConLivros.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinLivros;
GString *sSelLivros;

GtkWidget *frmConLivros_Criar()
{
  gint nLargura[12], nCont;
  GString *sRotulos[12];

  frmConLivros = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConLivros, "frmConLivros");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), "Livro: ");
  
  nLargura[0] = 80;
  nLargura[1] = 180;
  nLargura[2] = 80;
  nLargura[3] = 90;
  nLargura[4] = 80;
  nLargura[5] = 80;
  nLargura[6] = 100;
  nLargura[7] = 80;
  nLargura[8] = 100;
  nLargura[9] = 80;
  nLargura[10] = 80;
  nLargura[11] = 80;

  for (nCont=0; nCont < 12; nCont++)
    sRotulos[nCont] = g_string_new("");

  g_string_assign(sRotulos[0], "ISBN");
  g_string_assign(sRotulos[1], Rotinas_retUTF8("Título"));
  g_string_assign(sRotulos[2], Rotinas_retUTF8("Edição"));
  g_string_assign(sRotulos[3], Rotinas_retUTF8("AnoPublicação"));
  g_string_assign(sRotulos[4], "Volume");
  g_string_assign(sRotulos[5], "CodEditora");
  g_string_assign(sRotulos[6], "Editora");
  g_string_assign(sRotulos[7], "CodIdioma");
  g_string_assign(sRotulos[8], "Idioma");
  g_string_assign(sRotulos[9], Rotinas_retUTF8("NumPáginas")); 
  g_string_assign(sRotulos[10], Rotinas_retUTF8("Preço")); 
  g_string_assign(sRotulos[11], "Estoque");

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 12, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConLivros_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConLivros_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConLivros_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConLivros_btnFechar_clicked), NULL);

  sSelLivros = g_string_new("");

  return frmConLivros;
}

void on_frmConLivros_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinLivros, 
    &sSelLivros->str, selection);
}


void on_frmConLivros_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinLivros,
    ConsSQL_Livro('S', "", Rotinas_retTexto(frmConsultas_edtDescricao),
    "","","","","","","",""),STR_LIVNENC, 12);
}

void on_frmConLivros_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConLivros_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConLivros, sSelLivros->str);
}
