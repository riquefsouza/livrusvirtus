#include "Principal.h"
#include "Consultas.h"
#include "ConProfissoes.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinProfissoes;
GString *sSelProfissoes;

GtkWidget *frmConProfissoes_Criar()
{
  gint nLargura[2];
  GString *sRotulos[2];

  frmConProfissoes = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConProfissoes, "frmConProfissoes");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), 
    Rotinas_retUTF8("Profissão: "));

  nLargura[0] = 80;
  nLargura[1] = 180;

  sRotulos[0] = g_string_new("");
  sRotulos[1] = g_string_new("");
  g_string_assign(sRotulos[0], Rotinas_retUTF8("Código"));
  g_string_assign(sRotulos[1], Rotinas_retUTF8("Profissão") );

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 2, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConProfissoes_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConProfissoes_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConProfissoes_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConProfissoes_btnFechar_clicked), NULL);

  sSelProfissoes = g_string_new("");

  return frmConProfissoes;
}

void on_frmConProfissoes_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinProfissoes, 
    &sSelProfissoes->str, selection);
}


void on_frmConProfissoes_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinProfissoes,
    ConsSQL_Profissao('S', "", Rotinas_retTexto(frmConsultas_edtDescricao)),
    STR_PROFNENC, 2);
}

void on_frmConProfissoes_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConProfissoes_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConProfissoes, sSelProfissoes->str);
}
