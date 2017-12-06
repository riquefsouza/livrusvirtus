#include "Principal.h"
#include "Cadastros.h"
#include "CadLivros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConIdiomas.h"
#include "ConEditoras.h"
#include "ConAssuntos.h"
#include "ConAutores.h"

LISTAMSTR lstRegLivros;
gint nRegLivros;
LISTASTR frmCadLivros_slIdiomas;
GList *listCmbIdioma = NULL;

GtkWidget *frmCadLivros_Criar(void)
{
  GtkObject *edtEdicao_adj;
  GtkWidget *labEdicao;
  GtkWidget *labEditora;
  GtkObject *edtAnoPubli_adj;
  GtkWidget *labIdioma;
  GtkWidget *labAnoPubli;
  GtkObject *edtVolume_adj;
  GtkWidget *labVolume;
  GtkWidget *labNPaginas;
  GtkObject *edtNPaginas_adj;
  GtkWidget *labAssunto;
  GtkWidget *labPreco;
  GtkWidget *labQtdEstoque;
  GtkObject *edtQtdEstoque_adj;  
  GtkWidget *labAutor;
  GtkWidget *scrolledwindow1;
  GtkWidget *scrolledwindow2;
  GtkTreeSelection *selection;
  gint nLargura[1];
  GString *sRotulos[1];

  frmCadLivros = frmCadastros_Criar(FALSE, STR_CADLIVRO,
    &frmCadLivros_edtCodigo, &frmCadLivros_edtDescricao);
  gtk_widget_set_name(frmCadLivros, "frmCadLivros");
  gtk_window_set_default_size (GTK_WINDOW (frmCadLivros), 560, 415);

  gtk_label_set_text(GTK_LABEL(frmCadastros_labCodigo), "ISBN: ");
  gtk_misc_set_alignment (GTK_MISC (frmCadastros_labCodigo), 0, 0.5);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadLivros_edtCodigo), 13);

  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), 
                     Rotinas_retUTF8("Título: "));
  gtk_misc_set_alignment (GTK_MISC (frmCadastros_labDescricao), 0, 0.5);
  gtk_widget_set_size_request (frmCadLivros_edtDescricao, 352, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadLivros_edtDescricao), 50);

  frmCadLivros_edtCodEditora = gtk_entry_new ();
  gtk_widget_set_name (frmCadLivros_edtCodEditora, "edtCodEditora");
  gtk_widget_show (frmCadLivros_edtCodEditora);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), 
                 frmCadLivros_edtCodEditora, 112, 112);
  gtk_widget_set_size_request (frmCadLivros_edtCodEditora, 88, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadLivros_edtCodEditora), 5);
  gtk_widget_set_sensitive(frmCadLivros_edtCodEditora, FALSE);

  frmCadLivros_edtEditora = gtk_entry_new ();
  gtk_widget_set_name (frmCadLivros_edtEditora, "edtEditora");
  gtk_widget_show (frmCadLivros_edtEditora);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), 
                 frmCadLivros_edtEditora, 208, 112);
  gtk_widget_set_size_request (frmCadLivros_edtEditora, 232, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadLivros_edtEditora, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadLivros_edtEditora, GTK_CAN_FOCUS);
  #endif

  edtEdicao_adj = gtk_adjustment_new (1, 1, 9999, 1, 10, 10);
  frmCadLivros_edtEdicao = gtk_spin_button_new(
                           GTK_ADJUSTMENT (edtEdicao_adj), 1, 0);
  gtk_widget_set_name (frmCadLivros_edtEdicao, "edtEdicao");
  gtk_widget_show (frmCadLivros_edtEdicao);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1),
                frmCadLivros_edtEdicao, 368, 72);
  gtk_widget_set_size_request (frmCadLivros_edtEdicao, 96, 24);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (frmCadLivros_edtEdicao), TRUE);
  gtk_widget_set_sensitive(frmCadLivros_edtEdicao, FALSE);

  labEdicao = gtk_label_new (Rotinas_retUTF8("Edição:"));
  gtk_widget_set_name (labEdicao, "labEdicao");
  gtk_widget_show (labEdicao);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labEdicao, 368, 56);
  gtk_widget_set_size_request (labEdicao, 50, 16);
  gtk_misc_set_alignment (GTK_MISC (labEdicao), 0, 0);

  frmCadLivros_btnPEditora = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (frmCadLivros_btnPEditora, "btnPEditora");
  gtk_widget_show (frmCadLivros_btnPEditora);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_btnPEditora, 440, 112);
  gtk_widget_set_size_request (frmCadLivros_btnPEditora, 25, 25);
  gtk_widget_set_sensitive(frmCadLivros_btnPEditora, FALSE);

  labEditora = gtk_label_new (_("Editora:"));
  gtk_widget_set_name (labEditora, "labEditora");
  gtk_widget_show (labEditora);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labEditora, 112, 96);
  gtk_widget_set_size_request (labEditora, 55, 16);

  edtAnoPubli_adj = gtk_adjustment_new (1, 1, 9999, 1, 10, 10);
  frmCadLivros_edtAnoPubli = gtk_spin_button_new(
                             GTK_ADJUSTMENT (edtAnoPubli_adj), 1, 0);
  gtk_widget_set_name (frmCadLivros_edtAnoPubli, "edtAnoPubli");
  gtk_widget_show (frmCadLivros_edtAnoPubli);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtAnoPubli, 8, 112);
  gtk_widget_set_size_request(frmCadLivros_edtAnoPubli, 96, 24);
  gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(
                frmCadLivros_edtAnoPubli), TRUE);
  gtk_widget_set_sensitive(frmCadLivros_edtAnoPubli, FALSE);

  labIdioma = gtk_label_new (_("Idioma:"));
  gtk_widget_set_name (labIdioma, "labIdioma");
  gtk_widget_show (labIdioma);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labIdioma, 112, 136);
  gtk_widget_set_size_request (labIdioma, 55, 16);
  gtk_misc_set_alignment (GTK_MISC (labIdioma), 0, 0);

  labAnoPubli = gtk_label_new (Rotinas_retUTF8("Ano Publicação:"));
  gtk_widget_set_name (labAnoPubli, "labAnoPubli");
  gtk_widget_show (labAnoPubli);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labAnoPubli, 8, 96);
  gtk_widget_set_size_request (labAnoPubli, 104, 16);
  gtk_misc_set_alignment (GTK_MISC (labAnoPubli), 0, 0);

  edtVolume_adj = gtk_adjustment_new (1, 1, 9999, 1, 10, 10);
  frmCadLivros_edtVolume = gtk_spin_button_new(
                           GTK_ADJUSTMENT (edtVolume_adj), 1, 0);
  gtk_widget_set_name (frmCadLivros_edtVolume, "edtVolume");
  gtk_widget_show (frmCadLivros_edtVolume);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtVolume, 8, 152);
  gtk_widget_set_size_request(frmCadLivros_edtVolume, 96, 24);
  gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(frmCadLivros_edtVolume), TRUE);
  gtk_widget_set_sensitive(frmCadLivros_edtVolume, FALSE);

  labVolume = gtk_label_new (_("Volume:"));
  gtk_widget_set_name (labVolume, "labVolume");
  gtk_widget_show (labVolume);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labVolume, 8, 136);
  gtk_widget_set_size_request (labVolume, 80, 16);
  gtk_misc_set_alignment (GTK_MISC (labVolume), 0, 0);

  labNPaginas = gtk_label_new (Rotinas_retUTF8("Nº Páginas:"));
  gtk_widget_set_name (labNPaginas, "labNPaginas");
  gtk_widget_show (labNPaginas);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labNPaginas, 8, 176);
  gtk_widget_set_size_request (labNPaginas, 80, 16);
  gtk_misc_set_alignment (GTK_MISC (labNPaginas), 0, 0);

  edtNPaginas_adj = gtk_adjustment_new (1, 1, 9999, 1, 10, 10);
  frmCadLivros_edtNPaginas = gtk_spin_button_new(
               GTK_ADJUSTMENT (edtNPaginas_adj), 1, 0);
  gtk_widget_set_name (frmCadLivros_edtNPaginas, "edtNPaginas");
  gtk_widget_show (frmCadLivros_edtNPaginas);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtNPaginas, 8, 192);
  gtk_widget_set_size_request(frmCadLivros_edtNPaginas, 96, 24);
  gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(frmCadLivros_edtNPaginas), TRUE);
  gtk_widget_set_sensitive(frmCadLivros_edtNPaginas, FALSE);

  labAssunto = gtk_label_new (_("Assunto:"));
  gtk_widget_set_name (labAssunto, "labAssunto");
  gtk_widget_show (labAssunto);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labAssunto, 112, 176);
  gtk_widget_set_size_request (labAssunto, 80, 16);
  gtk_misc_set_alignment (GTK_MISC (labAssunto), 0, 0);

  frmCadLivros_edtCodAssunto = gtk_entry_new ();
  gtk_widget_set_name(frmCadLivros_edtCodAssunto, "edtCodAssunto");
  gtk_widget_show(frmCadLivros_edtCodAssunto);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtCodAssunto, 112, 192);
  gtk_widget_set_size_request(frmCadLivros_edtCodAssunto, 88, 24);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadLivros_edtCodAssunto), 10);
  gtk_widget_set_sensitive(frmCadLivros_edtCodAssunto, FALSE);

  frmCadLivros_edtAssunto = gtk_entry_new ();
  gtk_widget_set_name(frmCadLivros_edtAssunto, "edtAssunto");
  gtk_widget_show(frmCadLivros_edtAssunto);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtAssunto, 208, 192);
  gtk_widget_set_size_request(frmCadLivros_edtAssunto, 200, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadLivros_edtAssunto, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadLivros_edtAssunto, GTK_CAN_FOCUS);
  #endif

  frmCadLivros_btnPAssunto = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name(frmCadLivros_btnPAssunto, "btnPAssunto");
  gtk_widget_show(frmCadLivros_btnPAssunto);
  gtk_fixed_put(GTK_FIXED(frmCadastros_fixed1), 
                frmCadLivros_btnPAssunto, 440, 192);
  gtk_widget_set_size_request(frmCadLivros_btnPAssunto, 25, 25);
  gtk_widget_set_sensitive(frmCadLivros_btnPAssunto, FALSE);

  frmCadLivros_btnAdAssuntos = gtk_button_new_with_mnemonic (_("+"));
  gtk_widget_set_name(frmCadLivros_btnAdAssuntos, "btnAdAssuntos");
  gtk_widget_show(frmCadLivros_btnAdAssuntos);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_btnAdAssuntos, 408, 192);
  gtk_widget_set_size_request(frmCadLivros_btnAdAssuntos, 25, 25);
  gtk_widget_set_sensitive(frmCadLivros_btnAdAssuntos, FALSE);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
				 GTK_SHADOW_ETCHED_IN);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), scrolledwindow1, 112, 218);

  frmCadLivros_lstAssuntos = gtk_tree_view_new ();
  gtk_widget_set_name (frmCadLivros_lstAssuntos, "lstAssuntos");
  gtk_widget_show (frmCadLivros_lstAssuntos);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), frmCadLivros_lstAssuntos);
  gtk_widget_set_size_request (frmCadLivros_lstAssuntos, 296, 54);
  selection = gtk_tree_view_get_selection(
    GTK_TREE_VIEW (frmCadLivros_lstAssuntos));
  gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
  gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(frmCadLivros_lstAssuntos), TRUE);
  Rotinas_CriaModeloGrid(GTK_TREE_VIEW(frmCadLivros_lstAssuntos));

  gtk_widget_show (scrolledwindow1);

  frmCadLivros_edtPreco = gtk_entry_new ();
  gtk_widget_set_name(frmCadLivros_edtPreco, "edtPreco");
  gtk_widget_show(frmCadLivros_edtPreco);
  gtk_fixed_put(GTK_FIXED(frmCadastros_fixed1), 
                frmCadLivros_edtPreco, 8, 248);
  gtk_widget_set_size_request(frmCadLivros_edtPreco, 96, 24);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadLivros_edtPreco), 7);
  gtk_widget_set_sensitive(frmCadLivros_edtPreco, FALSE);

  labPreco = gtk_label_new (Rotinas_retUTF8("Preço:"));
  gtk_widget_set_name (labPreco, "labPreco");
  gtk_widget_show (labPreco);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labPreco, 8, 232);
  gtk_widget_set_size_request (labPreco, 80, 16);
  gtk_misc_set_alignment (GTK_MISC (labPreco), 0, 0);

  labQtdEstoque = gtk_label_new (_("Qtd.Estoque:"));
  gtk_widget_set_name (labQtdEstoque, "labQtdEstoque");
  gtk_widget_show (labQtdEstoque);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labQtdEstoque, 8, 272);
  gtk_widget_set_size_request (labQtdEstoque, 104, 16);
  gtk_misc_set_alignment (GTK_MISC (labQtdEstoque), 0, 0);

  edtQtdEstoque_adj = gtk_adjustment_new (0, 0, 9999, 1, 10, 10);
  frmCadLivros_edtQtdEstoque = gtk_spin_button_new (
    GTK_ADJUSTMENT (edtQtdEstoque_adj), 1, 0);
  gtk_widget_set_name (frmCadLivros_edtQtdEstoque, "edtQtdEstoque");
  gtk_widget_show (frmCadLivros_edtQtdEstoque);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), 
    frmCadLivros_edtQtdEstoque, 8, 288);
  gtk_widget_set_size_request (frmCadLivros_edtQtdEstoque, 96, 24);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (
    frmCadLivros_edtQtdEstoque), TRUE);
  gtk_widget_set_sensitive(frmCadLivros_edtQtdEstoque, FALSE);

  labAutor = gtk_label_new (_("Autor:"));
  gtk_widget_set_name (labAutor, "labAutor");
  gtk_widget_show (labAutor);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labAutor, 112, 272);
  gtk_widget_set_size_request (labAutor, 64, 16);
  gtk_misc_set_alignment (GTK_MISC (labAutor), 0, 0);

  frmCadLivros_edtCodAutor = gtk_entry_new ();
  gtk_widget_set_name(frmCadLivros_edtCodAutor, "edtCodAutor");
  gtk_widget_show(frmCadLivros_edtCodAutor);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtCodAutor, 112, 288);
  gtk_widget_set_size_request(frmCadLivros_edtCodAutor, 88, 24);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadLivros_edtCodAutor), 10);
  gtk_widget_set_sensitive(frmCadLivros_edtCodAutor, FALSE);

  frmCadLivros_edtAutor = gtk_entry_new ();
  gtk_widget_set_name(frmCadLivros_edtAutor, "edtAutor");
  gtk_widget_show(frmCadLivros_edtAutor);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_edtAutor, 208, 288);
  gtk_widget_set_size_request(frmCadLivros_edtAutor, 200, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadLivros_edtAutor, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadLivros_edtAutor, GTK_CAN_FOCUS);
  #endif

  frmCadLivros_btnAdAutores = gtk_button_new_with_mnemonic (_("+"));
  gtk_widget_set_name(frmCadLivros_btnAdAutores, "btnAdAutores");
  gtk_widget_show(frmCadLivros_btnAdAutores);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_btnAdAutores, 408, 288);
  gtk_widget_set_size_request(frmCadLivros_btnAdAutores, 25, 25);
  gtk_widget_set_sensitive(frmCadLivros_btnAdAutores, FALSE);

  frmCadLivros_btnPAutor = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name(frmCadLivros_btnPAutor, "btnAdAutores");
  gtk_widget_show(frmCadLivros_btnPAutor);
  gtk_fixed_put(GTK_FIXED (frmCadastros_fixed1), 
                frmCadLivros_btnPAutor, 440, 288);
  gtk_widget_set_size_request(frmCadLivros_btnPAutor, 25, 25);
  gtk_widget_set_sensitive(frmCadLivros_btnPAutor, FALSE);

  scrolledwindow2 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow2, "scrolledwindow2");
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow2), 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow2),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow2),
				 GTK_SHADOW_ETCHED_IN);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), scrolledwindow2, 112, 312);

  frmCadLivros_lstAutores = gtk_tree_view_new ();
  gtk_widget_set_name (frmCadLivros_lstAutores, "lstAutores");
  gtk_widget_show (frmCadLivros_lstAutores);
  gtk_container_add (GTK_CONTAINER (scrolledwindow2), frmCadLivros_lstAutores);
  gtk_widget_set_size_request (frmCadLivros_lstAutores, 296, 54);
  selection = gtk_tree_view_get_selection(
    GTK_TREE_VIEW (frmCadLivros_lstAutores));
  gtk_tree_selection_set_mode(selection, GTK_SELECTION_SINGLE);
  gtk_tree_view_set_rules_hint(GTK_TREE_VIEW(frmCadLivros_lstAutores), TRUE);
  Rotinas_CriaModeloGrid(GTK_TREE_VIEW(frmCadLivros_lstAutores));

  gtk_widget_show (scrolledwindow2);

  frmCadLivros_cmbIdioma = gtk_combo_new ();
  g_object_set_data (G_OBJECT (GTK_COMBO (frmCadLivros_cmbIdioma)->popwin),
                     "GladeParentKey", frmCadLivros_cmbIdioma);
  gtk_widget_show (frmCadLivros_cmbIdioma);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadLivros_cmbIdioma, 112, 152);
  gtk_widget_set_size_request (frmCadLivros_cmbIdioma, 352, 26);
  gtk_widget_set_sensitive(frmCadLivros_cmbIdioma, FALSE);

  frmCadLivros_cmbIdiomaEntrada = GTK_COMBO (frmCadLivros_cmbIdioma)->entry;
  gtk_widget_show (frmCadLivros_cmbIdiomaEntrada);
  gtk_editable_set_editable (GTK_EDITABLE (frmCadLivros_cmbIdiomaEntrada), FALSE);

  frmCadastros_IniciaBotoes(464, 10, 197, 380);

  g_signal_connect ((gpointer) frmCadLivros, "destroy",
		    G_CALLBACK (on_frmCadLivros_destroy), NULL);
  g_signal_connect ((gpointer) frmCadLivros_edtCodigo, "focus_out_event",
	    G_CALLBACK (on_frmCadLivros_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnNovo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadLivros_btnPEditora, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnPEditora_clicked), NULL);
  g_signal_connect ((gpointer) frmCadLivros_btnPAssunto, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnPAssunto_clicked), NULL);
  g_signal_connect ((gpointer) frmCadLivros_btnAdAssuntos, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnAdAssuntos_clicked), NULL);
  g_signal_connect ((gpointer) frmCadLivros_btnAdAutores, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnAdAutores_clicked), NULL);
  g_signal_connect ((gpointer) frmCadLivros_btnPAutor, "clicked",
		    G_CALLBACK (on_frmCadLivros_btnPAutor_clicked), NULL);
  g_signal_connect ((gpointer) frmCadLivros_edtCodEditora, "focus_out_event",
	    G_CALLBACK (on_frmCadLivros_edtCodEditora_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadLivros_edtPreco, "focus_out_event",
	    G_CALLBACK (on_frmCadLivros_edtPreco_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadLivros_edtCodAssunto, "focus_out_event",
	    G_CALLBACK (on_frmCadLivros_edtCodAssunto_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadLivros_edtCodAutor, "focus_out_event",
	    G_CALLBACK (on_frmCadLivros_edtCodAutor_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadLivros_lstAssuntos, "button_press_event",
      G_CALLBACK (on_frmCadLivros_lstAssuntos_button_press_event), NULL);
  g_signal_connect ((gpointer) frmCadLivros_lstAutores, "button_press_event",
	    G_CALLBACK (on_frmCadLivros_lstAutores_button_press_event), NULL);

  nLargura[0] = 180;
  sRotulos[0] = g_string_new("");
  g_string_assign(sRotulos[0], "Item");
  gtk_tree_view_set_headers_visible(
    GTK_TREE_VIEW(frmCadLivros_lstAssuntos), FALSE);
  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmCadLivros_lstAssuntos), 0, 1, 
    nLargura, sRotulos);
  gtk_tree_view_set_headers_visible(
                GTK_TREE_VIEW(frmCadLivros_lstAutores), FALSE);
  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmCadLivros_lstAutores), 0, 1, 
    nLargura, sRotulos);

  frmCadLivros_AdicionaCombo();  

  nRegLivros = 0;
  return frmCadLivros;
}

gboolean frmCadLivros_ValidaDados(gboolean bTodosDados) {
gint nQtdLinhas;

  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadLivros_edtCodigo), STR_ISBNNINF))
 	  return FALSE;
  if (bTodosDados) {
    if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadLivros_edtDescricao), STR_TITNINF))
  		return FALSE;
    if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadLivros_edtEditora), STR_EDTNINF))
  		return FALSE;

    Rotinas_PesquisaContaItemGrid(GTK_TREE_VIEW(frmCadLivros_lstAssuntos), 
      "", &nQtdLinhas);
    if (nQtdLinhas==0) {
      Rotinas_MsgDlg(STR_ASSNINF, GTK_MESSAGE_ERROR);
      return FALSE;
    }
    Rotinas_PesquisaContaItemGrid(GTK_TREE_VIEW(frmCadLivros_lstAutores), 
      "", &nQtdLinhas);
    if (nQtdLinhas==0) {
      Rotinas_MsgDlg(STR_AUTNINF, GTK_MESSAGE_ERROR);
      return FALSE;
    }
  }
  return TRUE;
}

gboolean on_frmCadLivros_edtCodigo_focus_out_event(GtkWidget* widget,
       	                   GdkEventFocus * event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodigo;
  sCodigo = Rotinas_retTexto(frmCadLivros_edtCodigo);
  if (strlen(sCodigo) > 0) {
    if (Rotinas_ValidaISBN(sCodigo)==FALSE) {      
      Rotinas_MsgDlg(STR_ISBNINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodigo), "");
      gtk_widget_grab_focus(frmCadLivros_edtCodigo);
    }
  }
  return FALSE;
}

void on_frmCadLivros_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadLivros_edtCodigo, 
    frmCadLivros_edtDescricao);
  frmCadLivros_InformaLimpaDados(NULL, 0, FALSE);
  frmCadLivros_HabilitaDados(TRUE);	
}

void on_frmCadLivros_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  if (frmCadastros_PesquisarDados(&lstRegLivros, ConsSQL_Livro('S',
    Rotinas_retTexto(frmCadLivros_edtCodigo),
    "","","","","","","","",""), STR_LIVNENC, 
    frmCadLivros_edtCodigo, frmCadLivros_edtDescricao)) {
     frmCadLivros_InformaLimpaDados(&lstRegLivros, nRegLivros, TRUE);
     frmCadLivros_HabilitaDados(TRUE);	
  }
}

void on_frmCadLivros_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  if (frmCadastros_registroAnterior(&lstRegLivros, &nRegLivros, 
    frmCadLivros_edtCodigo, frmCadLivros_edtDescricao))
    frmCadLivros_InformaLimpaDados(&lstRegLivros, nRegLivros, TRUE);
}

void on_frmCadLivros_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  if (frmCadastros_registroProximo(&lstRegLivros, &nRegLivros, 
    frmCadLivros_edtCodigo, frmCadLivros_edtDescricao))
    frmCadLivros_InformaLimpaDados(&lstRegLivros, nRegLivros, TRUE);
}

void on_frmCadLivros_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
GString *sCodIdioma = g_string_new("");
GString *sSqlInsert = g_string_new("");
GString *sSqlUpdate = g_string_new("");
gint nPos;

  nPos = frmCadLivros_retIdioma(
    Rotinas_retTexto(frmCadLivros_cmbIdiomaEntrada));
  g_string_assign(sCodIdioma,
    Rotinas_retValorLista(frmCadLivros_slIdiomas, nPos));

  g_string_assign(sSqlUpdate,
    ConsSQL_Livro('U', Rotinas_retTexto(frmCadLivros_edtCodigo),
    Rotinas_retTexto(frmCadLivros_edtDescricao),
    Rotinas_retTexto(frmCadLivros_edtEdicao),
    Rotinas_retTexto(frmCadLivros_edtAnoPubli),
    Rotinas_retTexto(frmCadLivros_edtVolume),
    Rotinas_retTexto(frmCadLivros_edtCodEditora), sCodIdioma->str,
    Rotinas_retTexto(frmCadLivros_edtNPaginas),
    Rotinas_VirgulaParaPonto(Rotinas_retTexto(frmCadLivros_edtPreco),FALSE),
    Rotinas_retTexto(frmCadLivros_edtQtdEstoque))->str);

  g_string_assign(sSqlInsert, 
    ConsSQL_Livro('I', Rotinas_retTexto(frmCadLivros_edtCodigo), 
    Rotinas_retTexto(frmCadLivros_edtDescricao), 
    Rotinas_retTexto(frmCadLivros_edtEdicao), 
    Rotinas_retTexto(frmCadLivros_edtAnoPubli), 
    Rotinas_retTexto(frmCadLivros_edtVolume),
    Rotinas_retTexto(frmCadLivros_edtCodEditora), sCodIdioma->str,
    Rotinas_retTexto(frmCadLivros_edtNPaginas),
    Rotinas_VirgulaParaPonto(Rotinas_retTexto(frmCadLivros_edtPreco),FALSE),
    Rotinas_retTexto(frmCadLivros_edtQtdEstoque))->str);

  if (frmCadastros_SalvarDados(frmCadLivros_ValidaDados(TRUE),
    ConsSQL_Livro('S', Rotinas_retTexto(frmCadLivros_edtCodigo),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, FALSE,
      frmCadLivros_edtCodigo, frmCadLivros_edtDescricao)) {
    frmCadLivros_SalvaLista('A');
    frmCadLivros_SalvaLista('B');
    frmCadastros_btnLimparClick(frmCadLivros_edtCodigo, 
      frmCadLivros_edtDescricao);
    frmCadLivros_InformaLimpaDados(NULL, 0, FALSE);
    frmCadLivros_HabilitaDados(FALSE);	
  }
}

void on_frmCadLivros_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadLivros_ValidaDados(FALSE),
    ConsSQL_Livro('D', Rotinas_retTexto(frmCadLivros_edtCodigo),
    "","","","","","","","",""),frmCadLivros_edtCodigo, 
    frmCadLivros_edtDescricao)) {
    frmCadLivros_InformaLimpaDados(NULL, 0, FALSE);
    frmCadLivros_HabilitaDados(FALSE);	
  }
}

void on_frmCadLivros_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadLivros_edtCodigo, 
    frmCadLivros_edtDescricao);
  frmCadLivros_InformaLimpaDados(NULL, 0, FALSE);
  frmCadLivros_HabilitaDados(FALSE);	
}

void on_frmCadLivros_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_tbLivros, TRUE);  
  gtk_widget_set_sensitive(frmPrincipal_mnuCadLivros, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadLivros_btnFechar_clicked(GtkButton *button, 
                                       gpointer user_data) {
  gtk_widget_destroy(frmCadLivros); 
}

void frmCadLivros_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar)
{ 
  if (bInformar) {
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtEdicao),
      Rotinas_retValorListaM(lstRegistros, 2, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtAnoPubli), 
      Rotinas_retValorListaM(lstRegistros, 3, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtVolume), 
      Rotinas_retValorListaM(lstRegistros, 4, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodEditora), 
      Rotinas_retValorListaM(lstRegistros, 5, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtEditora), 
      Rotinas_retValorListaM(lstRegistros, 6, nLinhaRegistro));
    frmCadLivros_AtribuiIdioma(
      Rotinas_retValorListaM(lstRegistros, 7, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtNPaginas), 
      Rotinas_retValorListaM(lstRegistros, 9, nLinhaRegistro));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtPreco), 
      Rotinas_VirgulaParaPonto( 
        Rotinas_retValorListaM(lstRegistros, 10, nLinhaRegistro), TRUE));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtQtdEstoque), 
      Rotinas_retValorListaM(lstRegistros, 11, nLinhaRegistro));
    Rotinas_AdicionaValoresLista(ConsSQL_LivroAss('S', 
      Rotinas_retTexto(frmCadLivros_edtCodigo), ""), 
      GTK_TREE_VIEW(frmCadLivros_lstAssuntos));
    Rotinas_AdicionaValoresLista(ConsSQL_LivroAut('S',
      Rotinas_retTexto(frmCadLivros_edtCodigo), ""), 
      GTK_TREE_VIEW(frmCadLivros_lstAutores));
  } else {
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtEdicao), "1");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtAnoPubli), 
      Rotinas_substr(Rotinas_retDataHoraStr(TRUE,FALSE),6,4));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtVolume), "1");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodEditora), "");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtEditora), "");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_cmbIdiomaEntrada), 
      g_list_nth_data(listCmbIdioma, 0));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtNPaginas), "1");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtPreco), "0,00");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtQtdEstoque), "1");
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodAssunto), "");
    Rotinas_LimpaModeloGrid(GTK_TREE_VIEW(frmCadLivros_lstAssuntos));
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodAutor), "");
    Rotinas_LimpaModeloGrid(GTK_TREE_VIEW(frmCadLivros_lstAutores));
    nRegLivros = 0;
  }
} 

void frmCadLivros_HabilitaDados(gboolean bHabilita) {
  gtk_widget_set_sensitive(frmCadLivros_edtEdicao, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtAnoPubli, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtVolume, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtCodEditora, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_btnPEditora, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_cmbIdioma, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtNPaginas, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtPreco, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtQtdEstoque, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtCodAssunto, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_btnPAssunto, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_btnAdAssuntos, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_lstAssuntos, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_edtCodAutor, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_btnPAutor, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_btnAdAutores, bHabilita);
  gtk_widget_set_sensitive(frmCadLivros_lstAutores, bHabilita);
}

void frmCadLivros_AdicionaCombo() 
{ 
  LISTAMSTR Campos;
  gchar sValor[TAM_MAX_STR];
  gint nLinha;

  frmCadLivros_slIdiomas.col = g_array_new(TRUE, TRUE, TAM_MAX_STR);
  if (Rotinas_ConsultaDadosLista(gConexao, &Campos, ConsSQL_Idioma('S',"",""))) {
    for (nLinha = 0; nLinha < abs(Campos.col[0]->len); nLinha++) {
      strcpy(sValor, Rotinas_retValorListaM(&Campos, 0, nLinha));
	    g_array_append_val(frmCadLivros_slIdiomas.col, sValor);
      listCmbIdioma = g_list_append(listCmbIdioma, 
        Rotinas_retValorListaM(&Campos, 1, nLinha));
	  }
    gtk_combo_set_popdown_strings (GTK_COMBO (frmCadLivros_cmbIdioma), 
      listCmbIdioma);
  }
}

void frmCadLivros_AtribuiIdioma(gchar *sIdioma) {
gint nCont;

 for (nCont=0; nCont < abs(frmCadLivros_slIdiomas.col->len); nCont++) {
   if (strcmp(Rotinas_retValorLista(frmCadLivros_slIdiomas, nCont),
       sIdioma)==0) {
     gtk_entry_set_text(GTK_ENTRY(frmCadLivros_cmbIdiomaEntrada), 
      g_list_nth_data(listCmbIdioma, nCont));
     break;
   }
 }
}

gint frmCadLivros_retIdioma(G_CONST_RETURN gchar *sIdioma) {
gint nCont = -1;

 for (nCont=0; nCont < abs(g_list_length(listCmbIdioma)); nCont++) {
   if (strcmp(g_list_nth_data(listCmbIdioma, nCont), sIdioma)==0)
     break;
 }
 return nCont;
}

void frmCadLivros_SalvaLista(char sOpcao)
{
GtkTreeModel *modeloGrid;
GtkTreeIter iter;
gboolean bProximo;
gchar *sCod, *sDesc;
G_CONST_RETURN gchar *sISBN;

  sISBN = Rotinas_retTexto(frmCadLivros_edtCodigo);
  if (sOpcao=='A') {
    Rotinas_AtualizaDados(gConexao, ConsSQL_LivroAss('D',sISBN,"")); 

    modeloGrid = gtk_tree_view_get_model(
      GTK_TREE_VIEW(frmCadLivros_lstAssuntos));
    if ( gtk_tree_model_get_iter_first(modeloGrid, &iter) ) {
      bProximo = TRUE;
      while( bProximo ) {
        gtk_tree_model_get(modeloGrid, &iter, 1, &sDesc, 2, &sCod, -1);
        Rotinas_AtualizaDados(gConexao, ConsSQL_LivroAss('I', sISBN, sCod));
        bProximo = gtk_tree_model_iter_next(modeloGrid, &iter);
      }
    }
  } else if (sOpcao=='B') {
  	Rotinas_AtualizaDados(gConexao,ConsSQL_LivroAut('D',sISBN,""));

    modeloGrid = gtk_tree_view_get_model(
      GTK_TREE_VIEW(frmCadLivros_lstAutores));
    if ( gtk_tree_model_get_iter_first(modeloGrid, &iter) ) {
      bProximo = TRUE;
      while( bProximo ) {
        gtk_tree_model_get(modeloGrid, &iter, 1, &sDesc, 2, &sCod, -1);
        Rotinas_AtualizaDados(gConexao, ConsSQL_LivroAut('I', sISBN, sCod));
        bProximo = gtk_tree_model_iter_next(modeloGrid, &iter);
      }
    }
  }
}

gboolean on_frmCadLivros_edtPreco_focus_out_event(GtkWidget* widget,
       	                   GdkEventFocus * event, gpointer user_data) {
  G_CONST_RETURN gchar *sPreco;
  sPreco = Rotinas_retTexto(frmCadLivros_edtPreco);
  if (strlen(sPreco) > 0) {
    if (Rotinas_ValidaFloat(
          Rotinas_VirgulaParaPonto(sPreco,FALSE)))
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtPreco), 
        Rotinas_VirgulaParaPonto(sPreco, TRUE));
    else {
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtPreco), "0,01");
      gtk_widget_grab_focus(frmCadLivros_edtPreco);
    }
  }
  return FALSE;
}

void on_frmCadLivros_btnPEditora_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmConEditoras = frmConEditoras_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConEditoras));
  gtk_widget_destroy(frmConEditoras);
  gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodEditora), 
    Rotinas_sCodigoSelecionado->str);
  on_frmCadLivros_edtCodEditora_focus_out_event(NULL, NULL, NULL);
}

void on_frmCadLivros_btnPAssunto_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmConAssuntos = frmConAssuntos_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConAssuntos));
  gtk_widget_destroy(frmConAssuntos);
  gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodAssunto), 
    Rotinas_sCodigoSelecionado->str);
  on_frmCadLivros_edtCodAssunto_focus_out_event(NULL, NULL, NULL);
}

void on_frmCadLivros_btnAdAssuntos_clicked(GtkButton *button, 
                                          gpointer user_data) {
  Rotinas_AdicionaItemLista(GTK_TREE_VIEW(frmCadLivros_lstAssuntos), 
    frmCadLivros_edtCodAssunto, frmCadLivros_edtAssunto);
}

void on_frmCadLivros_btnPAutor_clicked(GtkButton *button, 
                                       gpointer user_data) {
  frmConAutores = frmConAutores_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConAutores));
  gtk_widget_destroy(frmConAutores);
  gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodAutor), 
    Rotinas_sCodigoSelecionado->str);
  on_frmCadLivros_edtCodAutor_focus_out_event(NULL, NULL, NULL);
}

void on_frmCadLivros_btnAdAutores_clicked(GtkButton *button, 
                                        gpointer user_data) {
  Rotinas_AdicionaItemLista(GTK_TREE_VIEW(frmCadLivros_lstAutores), 
    frmCadLivros_edtCodAutor, frmCadLivros_edtAutor);
}

gboolean on_frmCadLivros_edtCodEditora_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodEditora, *sEditora;
  LISTAMSTR ConsCampo;

  sCodEditora = Rotinas_retTexto(frmCadLivros_edtCodEditora);
  if (strlen(sCodEditora) > 0) {
    sEditora = Rotinas_ConsultaCampoDesc(&ConsCampo, sCodEditora, TRUE,
      ConsSQL_Editora('S',sCodEditora,""),STR_EDTNENC);    
    if (strlen(sEditora) > 0)
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtEditora), sEditora);
    else {
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodEditora), "");
      gtk_widget_grab_focus(frmCadLivros_edtCodEditora);
    }
  } else
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtEditora), "");
  
  return FALSE;
}

gboolean on_frmCadLivros_edtCodAssunto_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodAssunto, *sAssunto;
  LISTAMSTR ConsCampo;

  sCodAssunto = Rotinas_retTexto(frmCadLivros_edtCodAssunto);
  if (strlen(sCodAssunto) > 0) {
    sAssunto = Rotinas_ConsultaCampoDesc(&ConsCampo, sCodAssunto, TRUE,
      ConsSQL_Assunto('S',sCodAssunto,""),STR_ASSNENC);    
    if (strlen(sAssunto) > 0)
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtAssunto), sAssunto);
    else {
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodAssunto), "");
      gtk_widget_grab_focus(frmCadLivros_edtCodAssunto);
    }
  } else
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtAssunto), "");

  return FALSE;
}

gboolean on_frmCadLivros_edtCodAutor_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodAutor, *sAutor;
  LISTAMSTR ConsCampo;

  sCodAutor = Rotinas_retTexto(frmCadLivros_edtCodAutor);
  if (strlen(sCodAutor) > 0) {
    sAutor = Rotinas_ConsultaCampoDesc(&ConsCampo, sCodAutor, TRUE,
      ConsSQL_Autor('S',sCodAutor,""),STR_AUTNENC);    
    if (strlen(sAutor) > 0)
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtAutor), sAutor);
    else {
      gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtCodAutor), "");
      gtk_widget_grab_focus(frmCadLivros_edtCodAutor);
    }
  } else
    gtk_entry_set_text(GTK_ENTRY(frmCadLivros_edtAutor), "");

  return FALSE;
}

gboolean on_frmCadLivros_lstAssuntos_button_press_event(GtkWidget *widget,
				   GdkEventButton *event, gpointer user_data)
{
  if (event->type==GDK_2BUTTON_PRESS)
    Rotinas_RemoveItemLista(GTK_TREE_VIEW(frmCadLivros_lstAssuntos));
  return FALSE;
}


gboolean on_frmCadLivros_lstAutores_button_press_event(GtkWidget *widget,
				  GdkEventButton *event, gpointer user_data)
{
  if (event->type==GDK_2BUTTON_PRESS)
    Rotinas_RemoveItemLista(GTK_TREE_VIEW(frmCadLivros_lstAutores));
  return FALSE;
}
