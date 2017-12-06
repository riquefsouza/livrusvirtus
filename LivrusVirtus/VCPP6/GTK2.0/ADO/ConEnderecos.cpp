#include "Principal.h"
#include "Consultas.h"
#include "ConEnderecos.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

GtkWidget *frmConEnderecos;

LISTAMSTR lstLinEnderecos;
GString *sSelEnderecos;

GtkWidget *frmConEnderecos_Criar()
{
  gint nLargura[6], nCont;
  GString *sRotulos[6];

  frmConEnderecos = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConEnderecos, "frmConEnderecos");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), 
    Rotinas_retUTF8("Endereço: "));

  nLargura[0] = 80;
  nLargura[1] = 180;
  nLargura[2] = 150;
  nLargura[3] = 80;
  nLargura[4] = 100;
  nLargura[5] = 80;

  for (nCont=0; nCont < 6; nCont++)
    sRotulos[nCont] = g_string_new("");

  g_string_assign(sRotulos[0], Rotinas_retUTF8("Código"));
  g_string_assign(sRotulos[1], "Logradouro" );
  g_string_assign(sRotulos[2], "Bairro" );
  g_string_assign(sRotulos[3], "CEP" );
  g_string_assign(sRotulos[4], "Cidade" );
  g_string_assign(sRotulos[5], "Estado" );

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 6, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConEnderecos_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConEnderecos_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConEnderecos_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConEnderecos_btnFechar_clicked), NULL);

  sSelEnderecos = g_string_new("");

  return frmConEnderecos;
}

void on_frmConEnderecos_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinEnderecos, 
    &sSelEnderecos->str, selection);
}


void on_frmConEnderecos_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinEnderecos,
    ConsSQL_Endereco('S', "", Rotinas_retTexto(frmConsultas_edtDescricao),
    "","","",""), STR_ENDNENC, 6);
}

void on_frmConEnderecos_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConEnderecos_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConEnderecos, sSelEnderecos->str);
}
