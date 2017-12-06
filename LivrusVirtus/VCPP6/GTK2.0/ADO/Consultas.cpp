#include "Principal.h"
#include "Consultas.h"

GtkWidget *frmConsultas;
GtkWidget *frmConsultas_labDescricao;
GtkWidget *frmConsultas_edtDescricao;
GtkWidget *frmConsultas_btnPesquisar;
GtkWidget *frmConsultas_gridConsulta;
GtkTreeSelection *frmConsultas_selection;
GtkWidget *frmConsultas_labRegistros;
GtkWidget *frmConsultas_btnLimpar;
GtkWidget *frmConsultas_btnFechar;

GtkWidget *frmConsultas_Criar(gchar* sTitulo)
{
  GdkPixbuf *frmConsultas_icon_pixbuf;
  GtkWidget *vbox1;
  GtkWidget *fixed1;
  GtkWidget *scrolledwindow1;
  GtkWidget *hbox1;
  GtkWidget *fixed3;
  GtkWidget *vbox2;
  GtkWidget *fixed4;
  GtkWidget *hbuttonbox1;

  frmConsultas = gtk_dialog_new ();
  gtk_widget_set_name (frmConsultas, "frmConsultas");
  gtk_window_set_title (GTK_WINDOW (frmConsultas), Rotinas_retUTF8(sTitulo));
  gtk_window_set_position (GTK_WINDOW (frmConsultas), GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_modal (GTK_WINDOW (frmConsultas), TRUE);
  gtk_window_set_resizable (GTK_WINDOW (frmConsultas), TRUE);
  gtk_window_set_default_size (GTK_WINDOW (frmConsultas), 400, 300);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmConsultas), TRUE);
  frmConsultas_icon_pixbuf = gdk_pixbuf_new_from_file ("xpms/livrus.xpm", NULL);
  if (frmConsultas_icon_pixbuf) {
    gtk_window_set_icon (GTK_WINDOW (frmConsultas), frmConsultas_icon_pixbuf);
    gdk_pixbuf_unref (frmConsultas_icon_pixbuf);
  }
  gtk_dialog_set_has_separator(GTK_DIALOG(frmConsultas), FALSE); 
  gtk_window_set_type_hint (GTK_WINDOW (frmConsultas), GDK_WINDOW_TYPE_HINT_DIALOG);

  vbox1 = GTK_DIALOG (frmConsultas)->vbox;
  gtk_widget_show (vbox1);

  fixed1 = gtk_fixed_new ();
  gtk_widget_set_name (fixed1, "fixed1");
  gtk_widget_show (fixed1);
  gtk_box_pack_start (GTK_BOX (vbox1), fixed1, FALSE, TRUE, 0);
  gtk_widget_set_size_request (fixed1, -1, 60);

  frmConsultas_edtDescricao = gtk_entry_new ();
  gtk_widget_set_name(frmConsultas_edtDescricao, "edtDescricao");
  gtk_widget_show(frmConsultas_edtDescricao);
  gtk_fixed_put(GTK_FIXED (fixed1), frmConsultas_edtDescricao, 8, 24);
  gtk_widget_set_size_request(frmConsultas_edtDescricao, 312, 24);

  frmConsultas_labDescricao = gtk_label_new (Rotinas_retUTF8("Descrição:"));
  gtk_widget_set_name (frmConsultas_labDescricao, "labDescricao");
  gtk_widget_show (frmConsultas_labDescricao);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConsultas_labDescricao, 8, 8);
  gtk_widget_set_size_request(frmConsultas_labDescricao, 80, 16);
  gtk_misc_set_alignment(GTK_MISC (frmConsultas_labDescricao), 0, 0.5);

  frmConsultas_btnPesquisar = gtk_button_new_with_mnemonic (_("_Pesquisar"));
  gtk_widget_set_name (frmConsultas_btnPesquisar, "btnPesquisar");
  gtk_widget_show (frmConsultas_btnPesquisar);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConsultas_btnPesquisar, 328, 24);
  gtk_widget_set_size_request (frmConsultas_btnPesquisar, 85, 28);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
				 GTK_SHADOW_ETCHED_IN);
  gtk_box_pack_start (GTK_BOX (vbox1), scrolledwindow1, TRUE, TRUE, 0);

  frmConsultas_gridConsulta = gtk_tree_view_new();
  gtk_tree_view_set_rules_hint(GTK_TREE_VIEW (frmConsultas_gridConsulta), TRUE);
  frmConsultas_selection = gtk_tree_view_get_selection(
    GTK_TREE_VIEW (frmConsultas_gridConsulta));
  gtk_tree_selection_set_mode(frmConsultas_selection, GTK_SELECTION_SINGLE);
  Rotinas_CriaModeloGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta));

  gtk_widget_set_name (frmConsultas_gridConsulta, "gridConsulta");
  gtk_widget_show (frmConsultas_gridConsulta);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), frmConsultas_gridConsulta);

  gtk_widget_show (scrolledwindow1);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox1, "hbox1");
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, FALSE, TRUE, 0);

  fixed3 = gtk_fixed_new ();
  gtk_widget_set_name (fixed3, "fixed3");
  gtk_widget_show (fixed3);
  gtk_box_pack_start (GTK_BOX (hbox1), fixed3, TRUE, TRUE, 0);
  gtk_widget_set_size_request (fixed3, -1, 60);

  frmConsultas_labRegistros = gtk_label_new (_("Registro 0 de 0"));
  gtk_widget_set_name (frmConsultas_labRegistros, "labRegistros");
  gtk_widget_show (frmConsultas_labRegistros);
  gtk_fixed_put (GTK_FIXED (fixed3), frmConsultas_labRegistros, 8, 24);
  gtk_widget_set_size_request (frmConsultas_labRegistros, 200, 16);
  gtk_misc_set_alignment (GTK_MISC (frmConsultas_labRegistros), 0, 0.5);

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox2, "vbox2");
  gtk_widget_show (vbox2);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox2, FALSE, TRUE, 0);

  fixed4 = gtk_fixed_new ();
  gtk_widget_set_name (fixed4, "fixed4");
  gtk_widget_show (fixed4);
  gtk_box_pack_start (GTK_BOX (vbox2), fixed4, TRUE, TRUE, 0);
  gtk_widget_set_size_request (fixed4, -1, 8);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_set_name (hbuttonbox1, "hbuttonbox1");
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_start (GTK_BOX (vbox2), hbuttonbox1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox1), 4);
  gtk_box_set_spacing (GTK_BOX (hbuttonbox1), 6);

  frmConsultas_btnLimpar = gtk_button_new_with_mnemonic (_("_Limpar"));
  gtk_widget_set_name (frmConsultas_btnLimpar, "btnLimpar");
  gtk_widget_show (frmConsultas_btnLimpar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), frmConsultas_btnLimpar);
  GTK_WIDGET_SET_FLAGS (frmConsultas_btnLimpar, GTK_CAN_DEFAULT);

  frmConsultas_btnFechar = gtk_button_new_with_mnemonic (_("_Fechar"));
  gtk_widget_set_name (frmConsultas_btnFechar, "btnFechar");
  gtk_widget_show (frmConsultas_btnFechar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), frmConsultas_btnFechar);
  GTK_WIDGET_SET_FLAGS (frmConsultas_btnFechar, GTK_CAN_DEFAULT);

  return frmConsultas;
}

void frmConsultas_Fecha(GtkWidget *frmCon, gchar *sSelecionado) {
Rotinas_sCodigoSelecionado = g_string_new("");

  if (strlen(sSelecionado) > 0)
    g_string_assign(Rotinas_sCodigoSelecionado, sSelecionado);
  else
    g_string_assign(Rotinas_sCodigoSelecionado, ""); 

  gtk_dialog_response(GTK_DIALOG(frmCon), GTK_RESPONSE_CANCEL);
}

void frmConsultas_LimparDados() {
  Rotinas_LimpaModeloGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta));
  gtk_label_set_text(GTK_LABEL(frmConsultas_labRegistros), "Registro 0 de 0");
  gtk_entry_set_text(GTK_ENTRY(frmConsultas_edtDescricao),""); 
  gtk_widget_grab_focus(frmConsultas_edtDescricao);
}

void frmConsultas_PesquisarDados(LISTAMSTR *lstLinhas, GString *sTextoSql, 
                                 gchar *sMensagemErro, gint nQtdCols) {

  if (Rotinas_ConsultaDadosLista(gConexao, lstLinhas, sTextoSql)) {
    Rotinas_AdicionaLinhasGrid(GTK_TREE_VIEW(frmConsultas_gridConsulta), 
                             lstLinhas, nQtdCols, TRUE);
    frmConsultas_setLabRegistros(lstLinhas, 0);
  } else
    Rotinas_MsgDlg(sMensagemErro, GTK_MESSAGE_ERROR);
}

void frmConsultas_setLabRegistros(LISTAMSTR *lstLinhas, gint nLinha) {
GString *sTemp = g_string_new("");

  g_string_sprintf(sTemp, "Registro %d de %d", nLinha, 
    lstLinhas->col[0]->len);
  gtk_label_set_text(GTK_LABEL(frmConsultas_labRegistros), sTemp->str);
}

void frmConsultas_setSelecionado(LISTAMSTR *lstLinhas, gchar **sSelecionado, 
                                  GtkTreeSelection *selection) {
GtkTreeModel *modeloGrid;
GtkTreeIter iter;
gint nLinha;

  if (gtk_tree_selection_get_selected (selection, &modeloGrid, &iter)) {
    gtk_tree_model_get(modeloGrid, &iter, 0, &nLinha, 1, sSelecionado, -1);
    frmConsultas_setLabRegistros(lstLinhas, nLinha);
  }
}

