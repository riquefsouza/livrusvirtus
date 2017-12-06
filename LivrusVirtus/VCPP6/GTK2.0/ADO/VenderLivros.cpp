#include "Principal.h"
#include "VenderLivros.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConClientes.h"
#include "ConLivros.h"

GtkWidget *frmVenderLivros;
GtkWidget *frmVenderLivros_edtDtHrVenda;
GtkWidget *frmVenderLivros_edtCPF;
GtkWidget *frmVenderLivros_edtISBN;
GtkWidget *frmVenderLivros_edtCliente;
GtkWidget *frmVenderLivros_btnPCliente;
GtkWidget *frmVenderLivros_edtLivro;
GtkWidget *frmVenderLivros_btnPLivro;
GtkWidget *frmVenderLivros_btnAdLivros;
GtkWidget *frmVenderLivros_lstLivros;
GtkWidget *frmVenderLivros_edtPrecoTotal;

gdouble frmVenderLivros_nPrecoTotal;

GtkWidget *frmVenderLivros_Criar(void)
{
  GdkPixbuf *frmVenderLivros_icon_pixbuf;
  GtkWidget *fixed1;
  GtkWidget *labCPF;
  GtkWidget *labISBN;
  GtkWidget *labCliente;
  GtkWidget *labLivro;
  GtkWidget *labLivros;
  GtkWidget *scrolledwindow1;
  GtkTreeSelection *frmVenderLivros_selection;
  GtkWidget *labPrecoTotal;
  GtkWidget *hbuttonbox1;
  GtkWidget *btnVender;
  GtkWidget *btnLimpar;
  GtkWidget *btnFechar;
  GtkWidget *labDtHrVenda;
  gint nLargura[1];
  GString *sRotulos[1];

  frmVenderLivros = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (frmVenderLivros, "frmVenderLivros");
  gtk_window_set_title (GTK_WINDOW (frmVenderLivros), _("Vender Livros"));
  gtk_window_set_default_size (GTK_WINDOW (frmVenderLivros), 480, 310);
  gtk_window_set_position (GTK_WINDOW (frmVenderLivros),
			   GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmVenderLivros), TRUE);
  frmVenderLivros_icon_pixbuf = gdk_pixbuf_new_from_file ("xpms/livrus.xpm", NULL);
  if (frmVenderLivros_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (frmVenderLivros),
			   frmVenderLivros_icon_pixbuf);
      gdk_pixbuf_unref (frmVenderLivros_icon_pixbuf);
    }

  fixed1 = gtk_fixed_new ();
  gtk_widget_set_name (fixed1, "fixed1");
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (frmVenderLivros), fixed1);

  frmVenderLivros_edtDtHrVenda = gtk_entry_new ();
  gtk_widget_set_name (frmVenderLivros_edtDtHrVenda,
		       "frmVenderLivros_edtDtHrVenda");
  gtk_widget_show (frmVenderLivros_edtDtHrVenda);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_edtDtHrVenda, 8, 24);
  gtk_widget_set_size_request (frmVenderLivros_edtDtHrVenda, 158, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmVenderLivros_edtDtHrVenda, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmVenderLivros_edtDtHrVenda, GTK_CAN_FOCUS);
  #endif

  labCPF = gtk_label_new (_("CPF: "));
  gtk_widget_set_name (labCPF, "labCPF");
  gtk_widget_show (labCPF);
  gtk_fixed_put (GTK_FIXED (fixed1), labCPF, 8, 56);
  gtk_widget_set_size_request (labCPF, 38, 16);

  frmVenderLivros_edtCPF = gtk_entry_new ();
  gtk_widget_set_name (frmVenderLivros_edtCPF, "frmVenderLivros_edtCPF");
  gtk_widget_show (frmVenderLivros_edtCPF);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_edtCPF, 8, 72);
  gtk_widget_set_size_request (frmVenderLivros_edtCPF, 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmVenderLivros_edtCPF), 14);

  labISBN = gtk_label_new (_("ISBN: "));
  gtk_widget_set_name (labISBN, "labISBN");
  gtk_widget_show (labISBN);
  gtk_fixed_put (GTK_FIXED (fixed1), labISBN, 8, 104);
  gtk_widget_set_size_request (labISBN, 38, 16);

  frmVenderLivros_edtISBN = gtk_entry_new ();
  gtk_widget_set_name (frmVenderLivros_edtISBN, "frmVenderLivros_edtISBN");
  gtk_widget_show (frmVenderLivros_edtISBN);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_edtISBN, 8, 120);
  gtk_widget_set_size_request (frmVenderLivros_edtISBN, 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmVenderLivros_edtISBN), 13);

  frmVenderLivros_edtCliente = gtk_entry_new ();
  gtk_widget_set_name (frmVenderLivros_edtCliente,
		       "frmVenderLivros_edtCliente");
  gtk_widget_show (frmVenderLivros_edtCliente);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_edtCliente, 168, 72);
  gtk_widget_set_size_request (frmVenderLivros_edtCliente, 344, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmVenderLivros_edtCliente, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmVenderLivros_edtCliente, GTK_CAN_FOCUS);
  #endif

  frmVenderLivros_btnPCliente = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (frmVenderLivros_btnPCliente,
		       "frmVenderLivros_btnPCliente");
  gtk_widget_show (frmVenderLivros_btnPCliente);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_btnPCliente, 512, 72);
  gtk_widget_set_size_request (frmVenderLivros_btnPCliente, 25, 25);

  labCliente = gtk_label_new (_("Cliente: "));
  gtk_widget_set_name (labCliente, "labCliente");
  gtk_widget_show (labCliente);
  gtk_fixed_put (GTK_FIXED (fixed1), labCliente, 168, 56);
  gtk_widget_set_size_request (labCliente, 56, 16);

  labLivro = gtk_label_new (_("Livro: "));
  gtk_widget_set_name (labLivro, "labLivro");
  gtk_widget_show (labLivro);
  gtk_fixed_put (GTK_FIXED (fixed1), labLivro, 168, 104);
  gtk_widget_set_size_request (labLivro, 38, 16);

  frmVenderLivros_edtLivro = gtk_entry_new ();
  gtk_widget_set_name (frmVenderLivros_edtLivro, "frmVenderLivros_edtLivro");
  gtk_widget_show (frmVenderLivros_edtLivro);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_edtLivro, 168, 120);
  gtk_widget_set_size_request (frmVenderLivros_edtLivro, 312, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmVenderLivros_edtLivro, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmVenderLivros_edtLivro, GTK_CAN_FOCUS);
  #endif

  frmVenderLivros_btnPLivro = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (frmVenderLivros_btnPLivro,
		       "frmVenderLivros_btnPLivro");
  gtk_widget_show (frmVenderLivros_btnPLivro);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_btnPLivro, 512, 120);
  gtk_widget_set_size_request (frmVenderLivros_btnPLivro, 25, 25);

  frmVenderLivros_btnAdLivros = gtk_button_new_with_mnemonic (_("+"));
  gtk_widget_set_name (frmVenderLivros_btnAdLivros,
		       "frmVenderLivros_btnAdLivros");
  gtk_widget_show (frmVenderLivros_btnAdLivros);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_btnAdLivros, 480, 120);
  gtk_widget_set_size_request (frmVenderLivros_btnAdLivros, 25, 25);

  labLivros = gtk_label_new (_("Livros para vender: "));
  gtk_widget_set_name (labLivros, "labLivros");
  gtk_widget_show (labLivros);
  gtk_fixed_put (GTK_FIXED (fixed1), labLivros, 8, 152);
  gtk_widget_set_size_request (labLivros, 128, 16);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_widget_show (scrolledwindow1);
  gtk_fixed_put (GTK_FIXED (fixed1), scrolledwindow1, 8, 168);
  gtk_widget_set_size_request (scrolledwindow1, 528, 136);
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
				       GTK_SHADOW_ETCHED_IN);

  frmVenderLivros_lstLivros = gtk_tree_view_new ();
  gtk_widget_set_name (frmVenderLivros_lstLivros,
		       "frmVenderLivros_lstLivros");
  gtk_widget_show (frmVenderLivros_lstLivros);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1),
		     frmVenderLivros_lstLivros);
  gtk_widget_set_size_request (frmVenderLivros_lstLivros, 134, 26);
  gtk_tree_view_set_headers_visible (GTK_TREE_VIEW
				     (frmVenderLivros_lstLivros), FALSE);
  gtk_tree_view_set_rules_hint(GTK_TREE_VIEW (frmVenderLivros_lstLivros), TRUE);
  frmVenderLivros_selection = gtk_tree_view_get_selection(
    GTK_TREE_VIEW (frmVenderLivros_lstLivros));
  gtk_tree_selection_set_mode(frmVenderLivros_selection, GTK_SELECTION_SINGLE);
  Rotinas_CriaModeloGrid(GTK_TREE_VIEW(frmVenderLivros_lstLivros));

  frmVenderLivros_edtPrecoTotal = gtk_entry_new ();
  gtk_widget_set_name (frmVenderLivros_edtPrecoTotal,
		       "frmVenderLivros_edtPrecoTotal");
  gtk_widget_show (frmVenderLivros_edtPrecoTotal);
  gtk_fixed_put (GTK_FIXED (fixed1), frmVenderLivros_edtPrecoTotal, 392, 312);
  gtk_widget_set_size_request (frmVenderLivros_edtPrecoTotal, 142, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmVenderLivros_edtPrecoTotal, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmVenderLivros_edtPrecoTotal, GTK_CAN_FOCUS);
  #endif

  labPrecoTotal = gtk_label_new (Rotinas_retUTF8("Preço Total: "));
  gtk_widget_set_name (labPrecoTotal, "labPrecoTotal");
  gtk_widget_show (labPrecoTotal);
  gtk_fixed_put (GTK_FIXED (fixed1), labPrecoTotal, 304, 312);
  gtk_widget_set_size_request (labPrecoTotal, 88, 16);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_set_name (hbuttonbox1, "hbuttonbox1");
  gtk_widget_show (hbuttonbox1);
  gtk_fixed_put (GTK_FIXED (fixed1), hbuttonbox1, 265, 344);
  gtk_widget_set_size_request (hbuttonbox1, 270, 32);

  btnVender = gtk_button_new_with_mnemonic (_("_Vender"));
  gtk_widget_set_name (btnVender, "btnVender");
  gtk_widget_show (btnVender);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnVender);
  GTK_WIDGET_SET_FLAGS (btnVender, GTK_CAN_DEFAULT);

  btnLimpar = gtk_button_new_with_mnemonic (_("_Limpar"));
  gtk_widget_set_name (btnLimpar, "btnLimpar");
  gtk_widget_show (btnLimpar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnLimpar);
  GTK_WIDGET_SET_FLAGS (btnLimpar, GTK_CAN_DEFAULT);

  btnFechar = gtk_button_new_with_mnemonic (_("_Fechar"));
  gtk_widget_set_name (btnFechar, "btnFechar");
  gtk_widget_show (btnFechar);
  gtk_container_add (GTK_CONTAINER (hbuttonbox1), btnFechar);
  GTK_WIDGET_SET_FLAGS (btnFechar, GTK_CAN_DEFAULT);

  labDtHrVenda = gtk_label_new (_("Data/Hora Venda: "));
  gtk_widget_set_name (labDtHrVenda, "labDtHrVenda");
  gtk_widget_show (labDtHrVenda);
  gtk_fixed_put (GTK_FIXED (fixed1), labDtHrVenda, 8, 8);
  gtk_widget_set_size_request (labDtHrVenda, 120, 16);

  g_signal_connect ((gpointer) frmVenderLivros, "destroy",
    G_CALLBACK (on_frmVenderLivros_destroy), NULL);
  g_signal_connect ((gpointer) frmVenderLivros_edtCPF, "focus_out_event",
    G_CALLBACK (on_frmVenderLivros_edtCPF_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmVenderLivros_edtISBN, "focus_out_event",
    G_CALLBACK (on_frmVenderLivros_edtISBN_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmVenderLivros_lstLivros, "button_press_event",
    G_CALLBACK (on_frmVenderLivros_lstLivros_button_press_event), NULL);
  g_signal_connect ((gpointer) btnVender, "clicked",
    G_CALLBACK (on_frmVenderLivros_btnVender_clicked), NULL);
  g_signal_connect ((gpointer) btnLimpar, "clicked",
    G_CALLBACK (on_frmVenderLivros_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) btnFechar, "clicked",
    G_CALLBACK (on_frmVenderLivros_btnFechar_clicked), NULL);
  g_signal_connect ((gpointer) frmVenderLivros_btnPCliente, "clicked",
    G_CALLBACK (on_frmVenderLivros_btnPCliente_clicked), NULL);
  g_signal_connect ((gpointer) frmVenderLivros_btnAdLivros, "clicked",
    G_CALLBACK (on_frmVenderLivros_btnAdLivros_clicked), NULL);
  g_signal_connect ((gpointer) frmVenderLivros_btnPLivro, "clicked",
    G_CALLBACK (on_frmVenderLivros_btnPLivro_clicked), NULL);

  nLargura[0] = 180;
  sRotulos[0] = g_string_new("Item");
  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmVenderLivros_lstLivros), 0, 1, 
    nLargura, sRotulos);

  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtDtHrVenda),
    Rotinas_retDataHoraStr(TRUE, TRUE)); 
  frmVenderLivros_nPrecoTotal = 0;
  return frmVenderLivros;
}

void frmVenderLivros_LimpaDados() {
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtDtHrVenda),
    Rotinas_retDataHoraStr(TRUE, TRUE)); 
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCPF), "");
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCliente), "");
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtISBN), "");
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtLivro), "");
  Rotinas_LimpaModeloGrid(GTK_TREE_VIEW(frmVenderLivros_lstLivros));
  frmVenderLivros_nPrecoTotal = 0;
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtPrecoTotal), "R$ 0,00");
  gtk_widget_grab_focus(frmVenderLivros_edtCPF);
}

gboolean frmVenderLivros_ValidaDados() {
gint nQtdLinhas = 0;

  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmVenderLivros_edtCPF), STR_CPFNINF))
 	  return FALSE;

  Rotinas_PesquisaContaItemGrid(GTK_TREE_VIEW(frmVenderLivros_lstLivros)
    , "", &nQtdLinhas);
  if (nQtdLinhas == 0) {   
    Rotinas_MsgDlg(STR_LIVVENNINF, GTK_MESSAGE_ERROR);
    return FALSE;
  }
	return TRUE;
}

gboolean frmVenderLivros_SalvaLista() {
GtkTreeModel *modeloGrid;
GtkTreeIter iter;
gboolean bProximo;
gchar *sDesc, *sISBN, *sPreco, *sQtdEstoque;
G_CONST_RETURN gchar *sCPF, *sDTHR;
GString *sPrecoTotal = g_string_new("");
GString *sDataHora = g_string_new("");
GString *sTemp = g_string_new("");
gint nQtdEstoque;

  sCPF = Rotinas_retTexto(frmVenderLivros_edtCPF);
  g_string_sprintf(sPrecoTotal, "%.2f", frmVenderLivros_nPrecoTotal);

  sDTHR = Rotinas_retTexto(frmVenderLivros_edtDtHrVenda);
  g_string_assign(sDataHora, Rotinas_ConverteDataHoraStr(sDTHR, TRUE, 
    "%m/%d/%Y","%H:%M:%S"));

  modeloGrid = gtk_tree_view_get_model(
    GTK_TREE_VIEW(frmVenderLivros_lstLivros));
  if ( gtk_tree_model_get_iter_first(modeloGrid, &iter) ) {
    bProximo = TRUE;
    while( bProximo ) {
      gtk_tree_model_get(modeloGrid, &iter, 1, &sDesc, 2, &sISBN, 
        3, &sPreco, 4, &sQtdEstoque, -1);
      
      Rotinas_AtualizaDados(gConexao, ConsSQL_Venda('I',sISBN, sCPF, 
        sDataHora->str,Rotinas_VirgulaParaPonto(sPrecoTotal->str,FALSE),""));

      nQtdEstoque = atoi(sQtdEstoque);
      if (nQtdEstoque > 0) {
        nQtdEstoque--;        
        g_string_sprintf(sTemp, "%d", nQtdEstoque);
        Rotinas_AtualizaDados(gConexao, ConsSQL_Venda('U',sISBN, 
          "","","", sTemp->str));
      }
      bProximo = gtk_tree_model_iter_next(modeloGrid, &iter);
    }
  }

return TRUE;
}

gboolean on_frmVenderLivros_edtCPF_focus_out_event(GtkWidget *widget, 
                          GdkEventFocus *event, gpointer user_data) {
G_CONST_RETURN gchar *sCPF, *sCliente;
LISTAMSTR ConsCampo;

  sCPF = Rotinas_retTexto(frmVenderLivros_edtCPF);
  if (strlen(sCPF) > 0) {
  	if (Rotinas_ValidaCPF(sCPF)) {      
      sCliente = Rotinas_ConsultaCampoDesc(&ConsCampo, "", FALSE, 
      ConsSQL_Cliente('S', sCPF,"","","","","","","","",""),STR_CLINENC); 
      if (strlen(sCliente)==0) {
        gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCPF), "");
        gtk_widget_grab_focus(frmVenderLivros_edtCPF);
      } else
        gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCliente), sCliente);
  	} else {
      Rotinas_MsgDlg(STR_CPFINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCPF), "");
      gtk_widget_grab_focus(frmVenderLivros_edtCPF);
    }
  } else
     gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCliente), "");

  return FALSE;
}

gboolean on_frmVenderLivros_edtISBN_focus_out_event(GtkWidget *widget, 
                              GdkEventFocus *event, gpointer user_data) {
G_CONST_RETURN gchar *sISBN, *sLivro, *sQtdEstoque;
gint nQtdEstoque;
LISTAMSTR ConsCampo;

  sISBN = Rotinas_retTexto(frmVenderLivros_edtISBN);
  if (strlen(sISBN) > 0) {
  	if (Rotinas_ValidaISBN(sISBN)) {      
      sLivro = Rotinas_ConsultaCampoDesc(&ConsCampo, "", FALSE, 
      ConsSQL_Livro('Q',sISBN,"","","","","","","","",""),STR_CLINENC); 
      if (strlen(sLivro)==0) {
        gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtISBN), "");
        gtk_widget_grab_focus(frmVenderLivros_edtISBN);
      } else {
         gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtLivro), sLivro);

         sQtdEstoque = Rotinas_retValorListaM(&ConsCampo, 3, 0);
         nQtdEstoque = atoi(sQtdEstoque);
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = g_string_new(
             Rotinas_retValorListaM(&ConsCampo, 2, 0));
           Rotinas_sQtdEstoque = g_string_new(sQtdEstoque);
         } else
           Rotinas_MsgDlg(STR_LIVNEST, GTK_MESSAGE_ERROR);
      }
  	} else {
      Rotinas_MsgDlg(STR_ISBNINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtISBN), "");
      gtk_widget_grab_focus(frmVenderLivros_edtISBN);
    }
  } else
     gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtLivro), "");

  return FALSE;
}

void on_frmVenderLivros_btnVender_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmVenderLivros_ValidaDados()) {
    if (frmVenderLivros_SalvaLista()) {
      Rotinas_MsgDlg(STR_VENRESUC, GTK_MESSAGE_INFO);
      frmVenderLivros_LimpaDados();
    }
  }	
}

void on_frmVenderLivros_btnLimpar_clicked(GtkButton *button, 
                                          gpointer user_data) {
  frmVenderLivros_LimpaDados();
}

void on_frmVenderLivros_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_tbVendas, TRUE);  
  gtk_widget_set_sensitive(frmPrincipal_mnuVenderLivros, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmVenderLivros_btnFechar_clicked(GtkButton *button, 
                                          gpointer user_data) {
  gtk_widget_destroy(frmVenderLivros);
}

void on_frmVenderLivros_btnPCliente_clicked(GtkButton *button,
                                            gpointer user_data) {
  frmConClientes = frmConClientes_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConClientes));
  gtk_widget_destroy(frmConClientes);
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtCPF), 
    Rotinas_sCodigoSelecionado->str);
  on_frmVenderLivros_edtCPF_focus_out_event(NULL, NULL, NULL);
}

void on_frmVenderLivros_btnPLivro_clicked(GtkButton *button, 
                                          gpointer user_data) {
  frmConLivros = frmConLivros_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConLivros));
  gtk_widget_destroy(frmConLivros);
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtISBN), 
    Rotinas_sCodigoSelecionado->str);
  on_frmVenderLivros_edtISBN_focus_out_event(NULL, NULL, NULL);
}

gboolean on_frmVenderLivros_lstLivros_button_press_event(GtkWidget *widget,
                      				 GdkEventButton *event, gpointer user_data) {
GtkTreeView *lstLista;
GtkTreeSelection *selection;
GtkListStore *gListaGrid;
GtkTreeModel *modeloGrid;
GtkTreeIter iter;
gint nQtdLinhas = 0;
gchar *sDesc, *sISBN, *sPreco, *sQtdEstoque;
gdouble nPreco;
gchar* fimptr[TAM_MAX_STR];
GString *sPrecoTotal = g_string_new("");

  if (event->type==GDK_2BUTTON_PRESS) {
    lstLista = GTK_TREE_VIEW(frmVenderLivros_lstLivros);
    gListaGrid = GTK_LIST_STORE( gtk_tree_view_get_model(lstLista));
    Rotinas_PesquisaContaItemGrid(lstLista, "", &nQtdLinhas);
    if (nQtdLinhas > 0) {   
      selection = gtk_tree_view_get_selection(lstLista);
      if (gtk_tree_selection_get_selected (selection, &modeloGrid, &iter)) {
        gtk_tree_model_get(modeloGrid, &iter, 1, &sDesc, 2, &sISBN, 
          3, &sPreco, 4, &sQtdEstoque, -1);
        nPreco = g_strtod(sPreco, fimptr);
        frmVenderLivros_nPrecoTotal = frmVenderLivros_nPrecoTotal - nPreco;
        g_string_sprintf(sPrecoTotal, "R$ %.2f", frmVenderLivros_nPrecoTotal);
        gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtPrecoTotal),
          Rotinas_VirgulaParaPonto(sPrecoTotal->str,TRUE));
        gtk_list_store_remove(gListaGrid, &iter);
      }
    }
  }  
  return FALSE;
}

void on_frmVenderLivros_btnAdLivros_clicked(GtkButton *button,
                                    				gpointer user_data) {
LISTAMSTR lstLinhas;
gchar sTemp[TAM_MAX_STR];
GString *sItems = g_string_new("");
G_CONST_RETURN gchar *sISBN, *sLivro; 
gint nQtdLinhas = 0, nCol;
GString *sPrecoTotal = g_string_new("");
gdouble nPreco;
gchar* fimptr[TAM_MAX_STR];

sISBN = Rotinas_retTexto(frmVenderLivros_edtISBN);
sLivro = Rotinas_retTexto(frmVenderLivros_edtLivro);

if (strlen(sLivro) > 0) {
  g_string_sprintf(sItems, "%s - %s - R$ %s", sISBN, sLivro, 
    Rotinas_sPreco->str);

  if (Rotinas_PesquisaContaItemGrid(GTK_TREE_VIEW(frmVenderLivros_lstLivros), 
      sItems->str, &nQtdLinhas)==FALSE) {

    for (nCol = 0; nCol < 4; nCol++)
      lstLinhas.col[nCol] = g_array_new(TRUE, TRUE, TAM_MAX_STR);

    strcpy(sTemp, sItems->str);
    g_array_append_val(lstLinhas.col[0], sTemp);

    strcpy(sTemp, sISBN);
    g_array_append_val(lstLinhas.col[1], sTemp);

    strcpy(sTemp, Rotinas_sPreco->str);
    g_array_append_val(lstLinhas.col[2], sTemp);

    strcpy(sTemp, Rotinas_sQtdEstoque->str);
    g_array_append_val(lstLinhas.col[3], sTemp);

    Rotinas_AdicionaLinhasGrid(GTK_TREE_VIEW(frmVenderLivros_lstLivros), 
      &lstLinhas, 4, FALSE);

    nPreco = g_strtod(Rotinas_sPreco->str, fimptr);
    frmVenderLivros_nPrecoTotal = frmVenderLivros_nPrecoTotal + nPreco;
  }
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtISBN),""); 
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtLivro),""); 
  g_string_sprintf(sPrecoTotal, "R$ %.2f", frmVenderLivros_nPrecoTotal);
  gtk_entry_set_text(GTK_ENTRY(frmVenderLivros_edtPrecoTotal),
    Rotinas_VirgulaParaPonto(sPrecoTotal->str,TRUE));

}

}
