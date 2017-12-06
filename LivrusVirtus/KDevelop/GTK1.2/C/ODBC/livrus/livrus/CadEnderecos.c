#include "Principal.h"
#include "Cadastros.h"
#include "CadEnderecos.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

LISTAMSTR lstRegEnderecos;
gint nRegEnderecos;
GList *listCmbEstado = NULL;

GtkWidget *frmCadEnderecos_Criar(void)
{
  GtkWidget *labCidade;
  GtkWidget *labCep;
  GtkWidget *labBairro;
  GtkWidget *labEstado;

  frmCadEnderecos = frmCadastros_Criar(FALSE, STR_CADENDERECO,
    &frmCadEnderecos_edtCodigo, &frmCadEnderecos_edtDescricao);
  gtk_widget_set_name(frmCadEnderecos, "frmCadEnderecos");
  gtk_window_set_default_size (GTK_WINDOW (frmCadEnderecos), 560, 184);

  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), "Logradouro: ");
  gtk_widget_set_size_request(frmCadEnderecos_edtDescricao, 288, 24);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadEnderecos_edtDescricao), 50);

  frmCadEnderecos_edtBairro = gtk_entry_new ();
  gtk_widget_set_name(frmCadEnderecos_edtBairro, "edtBairro");
  gtk_widget_show(frmCadEnderecos_edtBairro);
  gtk_fixed_put(GTK_FIXED(frmCadastros_fixed1), frmCadEnderecos_edtBairro, 305, 72);
  gtk_widget_set_size_request(frmCadEnderecos_edtBairro, 158, 24);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadEnderecos_edtBairro), 30);
  gtk_widget_set_sensitive(frmCadEnderecos_edtBairro, FALSE);

  frmCadEnderecos_edtCep = gtk_entry_new ();
  gtk_widget_set_name(frmCadEnderecos_edtCep, "edtCep");
  gtk_widget_show(frmCadEnderecos_edtCep);
  gtk_fixed_put(GTK_FIXED(frmCadastros_fixed1), frmCadEnderecos_edtCep, 8, 112);
  gtk_widget_set_size_request(frmCadEnderecos_edtCep, 88, 24);
  gtk_widget_set_sensitive(frmCadEnderecos_edtCep, FALSE);

  frmCadEnderecos_edtCidade = gtk_entry_new ();
  gtk_widget_set_name(frmCadEnderecos_edtCidade, "edtCidade");
  gtk_widget_show(frmCadEnderecos_edtCidade);
  gtk_fixed_put(GTK_FIXED(frmCadastros_fixed1), frmCadEnderecos_edtCidade, 104, 112);
  gtk_widget_set_size_request(frmCadEnderecos_edtCidade, 192, 24);
  gtk_widget_set_sensitive(frmCadEnderecos_edtCidade, FALSE);

  labCidade = gtk_label_new (_("Cidade:"));
  gtk_widget_set_name(labCidade, "labCidade");
  gtk_widget_show(labCidade);
  gtk_fixed_put (GTK_FIXED(frmCadastros_fixed1), labCidade, 104, 96);
  gtk_widget_set_size_request (labCidade, 55, 16);

  labCep = gtk_label_new (_("CEP:"));
  gtk_widget_set_name (labCep, "labCep");
  gtk_widget_show (labCep);
  gtk_fixed_put (GTK_FIXED(frmCadastros_fixed1), labCep, 8, 96);
  gtk_widget_set_size_request (labCep, 38, 16);

  labBairro = gtk_label_new (_("Bairro:"));
  gtk_widget_set_name (labBairro, "labBairro");
  gtk_widget_show (labBairro);
  gtk_fixed_put (GTK_FIXED(frmCadastros_fixed1), labBairro, 305, 56);
  gtk_widget_set_size_request (labBairro, 45, 16);
  gtk_misc_set_alignment (GTK_MISC (labBairro), 0, 0);

  labEstado = gtk_label_new (_("Estado:"));
  gtk_widget_set_name (labEstado, "labEstado");
  gtk_widget_show (labEstado);
  gtk_fixed_put (GTK_FIXED(frmCadastros_fixed1), labEstado, 305, 96);
  gtk_widget_set_size_request (labEstado, 55, 16);

  frmCadEnderecos_cmbEstado = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO(frmCadEnderecos_cmbEstado)->popwin),
    "GladeParentKey", frmCadEnderecos_cmbEstado);
  gtk_widget_show (frmCadEnderecos_cmbEstado);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1),
    frmCadEnderecos_cmbEstado, 305, 112);
  gtk_widget_set_size_request (frmCadEnderecos_cmbEstado, 160, 26);
  gtk_widget_set_sensitive(frmCadEnderecos_cmbEstado, FALSE);

  frmCadEnderecos_cmbEstadoEntrada = GTK_COMBO
    (frmCadEnderecos_cmbEstado)->entry;
  gtk_widget_show (frmCadEnderecos_cmbEstadoEntrada);
  gtk_editable_set_editable(
    GTK_EDITABLE(frmCadEnderecos_cmbEstadoEntrada), FALSE);

  frmCadastros_IniciaBotoes(464, 10, 197, 152);

  g_signal_connect ((gpointer) frmCadEnderecos, "destroy",
		    G_CALLBACK (on_frmCadEnderecos_destroy), NULL);
  g_signal_connect ((gpointer) frmCadEnderecos_edtCodigo, "focus_out_event",
		    G_CALLBACK (on_frmCadEnderecos_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnNovo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadEnderecos_btnFechar_clicked), NULL);

  nRegEnderecos = 0;
  frmCadEnderecos_AdicionaCombo();
  return frmCadEnderecos;
}

gboolean frmCadEnderecos_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadEnderecos_edtCodigo), STR_CODNINF))
 	  return FALSE;
	if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadEnderecos_edtDescricao), STR_ENDNINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadEnderecos_edtBairro), STR_BAIRRONINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadEnderecos_edtCep), STR_CEPNINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadEnderecos_edtCidade), STR_CIDADENINF))
  		return FALSE;
	}
	return TRUE;
}

gboolean on_frmCadEnderecos_edtCodigo_focus_out_event (GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  frmCadastros_ValidaCodigo(frmCadEnderecos_edtCodigo);
  return FALSE;
}

void on_frmCadEnderecos_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadEnderecos_edtCodigo, 
    frmCadEnderecos_edtDescricao);
  frmCadEnderecos_InformaLimpaDados(NULL, 0, FALSE);
  frmCadEnderecos_HabilitaDados(TRUE);	
  frmCadastros_NovoDado(ConsSQL_Endereco('N', 
    Rotinas_retTexto(frmCadEnderecos_edtCodigo),"","","","",""),
    frmCadEnderecos_edtCodigo, frmCadEnderecos_edtDescricao);
}

void on_frmCadEnderecos_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  if (frmCadastros_PesquisarDados(&lstRegEnderecos, ConsSQL_Endereco('S',
    Rotinas_retTexto(frmCadEnderecos_edtCodigo),"","","","",""), STR_ENDNENC, 
    frmCadEnderecos_edtCodigo, frmCadEnderecos_edtDescricao)) {
     frmCadEnderecos_InformaLimpaDados(&lstRegEnderecos, nRegEnderecos, TRUE);
     frmCadEnderecos_HabilitaDados(TRUE);	
  }
}

void on_frmCadEnderecos_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  if (frmCadastros_registroAnterior(&lstRegEnderecos, &nRegEnderecos, 
    frmCadEnderecos_edtCodigo, frmCadEnderecos_edtDescricao))
    frmCadEnderecos_InformaLimpaDados(&lstRegEnderecos, nRegEnderecos, TRUE);
}

void on_frmCadEnderecos_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  if (frmCadastros_registroProximo(&lstRegEnderecos, &nRegEnderecos, 
    frmCadEnderecos_edtCodigo, frmCadEnderecos_edtDescricao))
    frmCadEnderecos_InformaLimpaDados(&lstRegEnderecos, nRegEnderecos, TRUE);
}

void on_frmCadEnderecos_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {

  if (frmCadastros_SalvarDados(frmCadEnderecos_ValidaDados(TRUE),
    ConsSQL_Endereco('S', Rotinas_retTexto(frmCadEnderecos_edtCodigo),
    "","","","",""),
    ConsSQL_Endereco('U', Rotinas_retTexto(frmCadEnderecos_edtCodigo),
      Rotinas_retTexto(frmCadEnderecos_edtDescricao),
      Rotinas_retTexto(frmCadEnderecos_edtBairro),
      Rotinas_retTexto(frmCadEnderecos_edtCep),
      Rotinas_retTexto(frmCadEnderecos_edtCidade),
      Rotinas_retTexto(frmCadEnderecos_cmbEstadoEntrada)),
    ConsSQL_Endereco('I', Rotinas_retTexto(frmCadEnderecos_edtCodigo),
      Rotinas_retTexto(frmCadEnderecos_edtDescricao),
      Rotinas_retTexto(frmCadEnderecos_edtBairro),
      Rotinas_retTexto(frmCadEnderecos_edtCep),
      Rotinas_retTexto(frmCadEnderecos_edtCidade),
      Rotinas_retTexto(frmCadEnderecos_cmbEstadoEntrada)),TRUE,
      frmCadEnderecos_edtCodigo, frmCadEnderecos_edtDescricao)) {
    frmCadEnderecos_InformaLimpaDados(NULL, 0, FALSE);
    frmCadEnderecos_HabilitaDados(FALSE);	
  }
}

void on_frmCadEnderecos_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadEnderecos_ValidaDados(FALSE),
    ConsSQL_Endereco('D', Rotinas_retTexto(frmCadEnderecos_edtCodigo),
    "","","","",""),frmCadEnderecos_edtCodigo, 
    frmCadEnderecos_edtDescricao)) {
    frmCadEnderecos_InformaLimpaDados(NULL, 0, FALSE);
    frmCadEnderecos_HabilitaDados(FALSE);	
  }
}

void on_frmCadEnderecos_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadEnderecos_edtCodigo, 
    frmCadEnderecos_edtDescricao);
  frmCadEnderecos_InformaLimpaDados(NULL, 0, FALSE);
  frmCadEnderecos_HabilitaDados(FALSE);	
}

void on_frmCadEnderecos_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuCadEnderecos, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadEnderecos_btnFechar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  gtk_widget_destroy(frmCadEnderecos); 
}

void frmCadEnderecos_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar)
{
  if (bInformar) {
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_edtBairro), 
      Rotinas_retValorListaM(lstRegistros, 2, nLinhaRegistro));   
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_edtCep), 
      Rotinas_retValorListaM(lstRegistros, 3, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_edtCidade), 
      Rotinas_retValorListaM(lstRegistros, 4, nLinhaRegistro));
    frmCadEnderecos_AtribuiEstado(
      Rotinas_retValorListaM(lstRegistros, 5, nLinhaRegistro));
  } else {
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_edtBairro),""); 
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_edtCep),""); 
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_edtCidade),""); 
    gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_cmbEstadoEntrada), 
      g_list_nth_data(listCmbEstado, 0));
    nRegEnderecos = 0;
  }

}

void frmCadEnderecos_HabilitaDados(gboolean bHabilita) {
  gtk_widget_set_sensitive(frmCadEnderecos_edtBairro, bHabilita);
  gtk_widget_set_sensitive(frmCadEnderecos_edtCep, bHabilita);
  gtk_widget_set_sensitive(frmCadEnderecos_edtCidade, bHabilita);
  gtk_widget_set_sensitive(frmCadEnderecos_cmbEstado, bHabilita);
}

void frmCadEnderecos_AdicionaCombo()
{ 
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_PE));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_AC));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_AL));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_AP));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_AM));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_BA));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_BR));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_CE));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_DF));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_ES));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_GO));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_MT));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_MS));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_MG));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_PA));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_PB));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_PR));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_SC));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_RN));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_RS));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_RJ));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_RO));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_RR));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_SP));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_SE));
  listCmbEstado = g_list_append(listCmbEstado, Rotinas_retUTF8(STR_TO));

  gtk_combo_set_popdown_strings (GTK_COMBO (frmCadEnderecos_cmbEstado), 
    listCmbEstado);
}

void frmCadEnderecos_AtribuiEstado(gchar *sEstado) {
gint nCont;

 for (nCont=0; nCont < 26; nCont++) {
    if (strcmp(g_list_nth_data(listCmbEstado, nCont), sEstado)==0) {
       gtk_entry_set_text(GTK_ENTRY(frmCadEnderecos_cmbEstadoEntrada), 
         g_list_nth_data(listCmbEstado, nCont));
       break;
    }
 } 
}
