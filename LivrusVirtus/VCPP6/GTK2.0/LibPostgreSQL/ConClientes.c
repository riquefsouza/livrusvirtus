#include "Principal.h"
#include "Consultas.h"
#include "ConClientes.h"
#include "RotinasGlobais.h"
#include "ConsultasSQL.h"

LISTAMSTR lstLinClientes;
GString *sSelClientes;

GtkWidget *frmConClientes_Criar()
{
  gint nLargura[17], nCont;
  GString *sRotulos[17];

  frmConClientes = frmConsultas_Criar(STR_CONASSUNTO);
  gtk_widget_set_name(frmConClientes, "frmConClientes");
  gtk_label_set_text(GTK_LABEL(frmConsultas_labDescricao), "Cliente: ");

  nLargura[0] = 80; nLargura[1] = 180; nLargura[2] = 180; nLargura[3] = 80;
  nLargura[4] = 40; nLargura[5] = 80; nLargura[6] = 120; nLargura[7] = 80;
  nLargura[8] = 220; nLargura[9] = 150; nLargura[10] = 80; nLargura[11] = 100;
  nLargura[12] = 100; nLargura[13] = 80; nLargura[14] = 180; nLargura[15] = 80;
  nLargura[16] = 100;

  for (nCont=0; nCont < 17; nCont++)
    sRotulos[nCont] = g_string_new("");

  g_string_assign(sRotulos[0], "CPF"); g_string_assign(sRotulos[1], "Nome" );
  g_string_assign(sRotulos[2], "Email");
  g_string_assign(sRotulos[3], "Identidade");
  g_string_assign(sRotulos[4], "Sexo"); 
  g_string_assign(sRotulos[5], "Telefone");
  g_string_assign(sRotulos[6], "DtNascimento");  
  g_string_assign(sRotulos[7], Rotinas_retUTF8("CodEndereço"));
  g_string_assign(sRotulos[8], "Logradouro");
  g_string_assign(sRotulos[9], "Bairro");
  g_string_assign(sRotulos[10], "CEP");
  g_string_assign(sRotulos[11], "Cidade");
  g_string_assign(sRotulos[12], "Estado");
  g_string_assign(sRotulos[13], Rotinas_retUTF8("CodPaís"));
  g_string_assign(sRotulos[14], Rotinas_retUTF8("País")); 
  g_string_assign(sRotulos[15], Rotinas_retUTF8("CodProfissão"));
  g_string_assign(sRotulos[16], Rotinas_retUTF8("Profissão"));

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 0, 17, 
    nLargura, sRotulos);
      
  g_signal_connect ((gpointer) frmConsultas_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmConClientes_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_selection, "changed",
		    G_CALLBACK (on_frmConClientes_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnLimpar, "clicked",
		    G_CALLBACK (on_frmConClientes_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmConsultas_btnFechar, "clicked",
		    G_CALLBACK (on_frmConClientes_btnFechar_clicked), NULL);

  sSelClientes = g_string_new("");

  return frmConClientes;
}

void on_frmConClientes_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
  frmConsultas_setSelecionado(&lstLinClientes, 
    &sSelClientes->str, selection);
}


void on_frmConClientes_btnPesquisar_clicked(GtkButton* button, 
                                            gpointer user_data)
{
  frmConsultas_PesquisarDados(&lstLinClientes,
    ConsSQL_Cliente('S', "", Rotinas_retTexto(frmConsultas_edtDescricao),
    "","","","","","","",""), STR_CLINENC, 17);
}

void on_frmConClientes_btnLimpar_clicked(GtkButton* button, 
                                         gpointer user_data) {
	frmConsultas_LimparDados();
}

void on_frmConClientes_btnFechar_clicked(GtkButton* button, 
                                         gpointer user_data) {
  frmConsultas_Fecha(frmConClientes, sSelClientes->str);
}
