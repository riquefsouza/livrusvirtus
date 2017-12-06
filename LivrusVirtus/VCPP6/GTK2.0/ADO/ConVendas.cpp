#include "Principal.h"
#include "ConVendas.h"
#include "ConsultasSQL.h"
#include "ConClientes.h"
#include "ConLivros.h"

GtkWidget *frmConVendas;
GtkWidget *frmConVendas_edtDtHrVenda;
GtkWidget *frmConVendas_edtCPF;
GtkWidget *frmConVendas_edtCliente;
GtkWidget *frmConVendas_edtISBN;
GtkWidget *frmConVendas_edtLivro;
GtkWidget *frmConVendas_gridConsulta;
GtkWidget *frmConVendas_labRegistros;
GtkWidget *frmConVendas_edtPrecoTotal;

LISTAMSTR lstLinVendas;

GtkWidget *frmConVendas_Criar(void)
{
  GdkPixbuf *frmConVendas_icon_pixbuf;
  GtkWidget *vbox1;
  GtkWidget *fixed1;
  GtkWidget *labDtHrVenda;
  GtkWidget *btnPesquisar;
  GtkWidget *labCPF;
  GtkWidget *labCliente;
  GtkWidget *btnPCliente;
  GtkWidget *labISBN;
  GtkWidget *labLivro;
  GtkWidget *btnPLivro;
  GtkWidget *scrolledwindow1;
  GtkTreeSelection *frmConVendas_selection;
  GtkWidget *hbox1;
  GtkWidget *vbox5;
  GtkWidget *fixed4;
  GtkWidget *fixed5;
  GtkWidget *vbox2;
  GtkWidget *fixed3;
  GtkWidget *labPrecoTotal;
  GtkWidget *hbuttonbox1;
  GtkWidget *btnLimpar;
  GtkWidget *btnFechar;
  gint nLargura[6];
  GString *sRotulos[6];

  frmConVendas = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (frmConVendas, "frmConVendas");
  gtk_window_set_title (GTK_WINDOW (frmConVendas), _("Vendas Realizadas"));
  gtk_window_set_default_size (GTK_WINDOW (frmConVendas), 480, 330);
  gtk_window_set_position (GTK_WINDOW (frmConVendas),
			   GTK_WIN_POS_CENTER_ALWAYS);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmConVendas), TRUE);
  frmConVendas_icon_pixbuf = gdk_pixbuf_new_from_file ("xpms/livrus.xpm", NULL);
  if (frmConVendas_icon_pixbuf)
    {
      gtk_window_set_icon (GTK_WINDOW (frmConVendas),
			   frmConVendas_icon_pixbuf);
      gdk_pixbuf_unref (frmConVendas_icon_pixbuf);
    }

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_set_name (vbox1, "vbox1");
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (frmConVendas), vbox1);

  fixed1 = gtk_fixed_new ();
  gtk_widget_set_name (fixed1, "fixed1");
  gtk_widget_show (fixed1);
  gtk_box_pack_start (GTK_BOX (vbox1), fixed1, FALSE, TRUE, 0);
  gtk_widget_set_size_request (fixed1, -1, 155);

  labDtHrVenda = gtk_label_new (_("Data/Hora Venda: "));
  gtk_widget_set_name (labDtHrVenda, "labDtHrVenda");
  gtk_widget_show (labDtHrVenda);
  gtk_fixed_put (GTK_FIXED (fixed1), labDtHrVenda, 8, 8);
  gtk_widget_set_size_request (labDtHrVenda, 120, 16);

  frmConVendas_edtDtHrVenda = gtk_entry_new ();
  gtk_widget_set_name (frmConVendas_edtDtHrVenda,
		       "frmConVendas_edtDtHrVenda");
  gtk_widget_show (frmConVendas_edtDtHrVenda);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConVendas_edtDtHrVenda, 8, 24);
  gtk_widget_set_size_request (frmConVendas_edtDtHrVenda, 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmConVendas_edtDtHrVenda), 19);

  btnPesquisar = gtk_button_new_with_mnemonic (_("_Pesquisar"));
  gtk_widget_set_name (btnPesquisar, "btnPesquisar");
  gtk_widget_show (btnPesquisar);
  gtk_fixed_put (GTK_FIXED (fixed1), btnPesquisar, 176, 24);
  gtk_widget_set_size_request (btnPesquisar, 88, 26);

  frmConVendas_edtCPF = gtk_entry_new ();
  gtk_widget_set_name (frmConVendas_edtCPF, "frmConVendas_edtCPF");
  gtk_widget_show (frmConVendas_edtCPF);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConVendas_edtCPF, 8, 72);
  gtk_widget_set_size_request (frmConVendas_edtCPF, 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmConVendas_edtCPF), 14);

  labCPF = gtk_label_new (_("CPF: "));
  gtk_widget_set_name (labCPF, "labCPF");
  gtk_widget_show (labCPF);
  gtk_fixed_put (GTK_FIXED (fixed1), labCPF, 8, 56);
  gtk_widget_set_size_request (labCPF, 40, 16);

  frmConVendas_edtCliente = gtk_entry_new ();
  gtk_widget_set_name (frmConVendas_edtCliente, "frmConVendas_edtCliente");
  gtk_widget_show (frmConVendas_edtCliente);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConVendas_edtCliente, 168, 72);
  gtk_widget_set_size_request (frmConVendas_edtCliente, 368, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmConVendas_edtCliente, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS (frmConVendas_edtCliente, GTK_CAN_FOCUS);
  #endif 

  labCliente = gtk_label_new (_("Cliente: "));
  gtk_widget_set_name (labCliente, "labCliente");
  gtk_widget_show (labCliente);
  gtk_fixed_put (GTK_FIXED (fixed1), labCliente, 168, 56);
  gtk_widget_set_size_request (labCliente, 46, 16);

  btnPCliente = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (btnPCliente, "btnPCliente");
  gtk_widget_show (btnPCliente);
  gtk_fixed_put (GTK_FIXED (fixed1), btnPCliente, 536, 72);
  gtk_widget_set_size_request (btnPCliente, 25, 25);

  frmConVendas_edtISBN = gtk_entry_new ();
  gtk_widget_set_name (frmConVendas_edtISBN, "frmConVendas_edtISBN");
  gtk_widget_show (frmConVendas_edtISBN);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConVendas_edtISBN, 8, 120);
  gtk_widget_set_size_request (frmConVendas_edtISBN, 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmConVendas_edtISBN), 13);

  labISBN = gtk_label_new (_("ISBN: "));
  gtk_widget_set_name (labISBN, "labISBN");
  gtk_widget_show (labISBN);
  gtk_fixed_put (GTK_FIXED (fixed1), labISBN, 8, 104);
  gtk_widget_set_size_request (labISBN, 40, 16);

  frmConVendas_edtLivro = gtk_entry_new ();
  gtk_widget_set_name (frmConVendas_edtLivro, "frmConVendas_edtLivro");
  gtk_widget_show (frmConVendas_edtLivro);
  gtk_fixed_put (GTK_FIXED (fixed1), frmConVendas_edtLivro, 168, 120);
  gtk_widget_set_size_request (frmConVendas_edtLivro, 368, 24);  
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmConVendas_edtLivro, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS (frmConVendas_edtLivro, GTK_CAN_FOCUS);
  #endif 

  labLivro = gtk_label_new (_("Livro: "));
  gtk_widget_set_name (labLivro, "labLivro");
  gtk_widget_show (labLivro);
  gtk_fixed_put (GTK_FIXED (fixed1), labLivro, 168, 104);
  gtk_widget_set_size_request (labLivro, 40, 16);

  btnPLivro = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (btnPLivro, "btnPLivro");
  gtk_widget_show (btnPLivro);
  gtk_fixed_put (GTK_FIXED (fixed1), btnPLivro, 536, 120);
  gtk_widget_set_size_request (btnPLivro, 25, 25);

  scrolledwindow1 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_set_name (scrolledwindow1, "scrolledwindow1");
  gtk_widget_show (scrolledwindow1);
  gtk_container_set_border_width (GTK_CONTAINER (scrolledwindow1), 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow1),
				  GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow1),
				 GTK_SHADOW_ETCHED_IN);
  gtk_box_pack_start (GTK_BOX (vbox1), scrolledwindow1, TRUE, TRUE, 0);

  frmConVendas_gridConsulta = gtk_tree_view_new ();
  gtk_tree_view_set_rules_hint(GTK_TREE_VIEW (frmConVendas_gridConsulta), TRUE);
  frmConVendas_selection = gtk_tree_view_get_selection(
    GTK_TREE_VIEW (frmConVendas_gridConsulta));
  gtk_tree_selection_set_mode(frmConVendas_selection, GTK_SELECTION_SINGLE);
  Rotinas_CriaModeloGrid(GTK_TREE_VIEW(frmConVendas_gridConsulta));

  gtk_widget_set_name (frmConVendas_gridConsulta, "frmConVendas_gridConsulta");
  gtk_widget_show (frmConVendas_gridConsulta);
  gtk_container_add (GTK_CONTAINER (scrolledwindow1), frmConVendas_gridConsulta);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_set_name (hbox1, "hbox1");
  gtk_widget_show (hbox1);
  gtk_box_pack_start (GTK_BOX (vbox1), hbox1, FALSE, FALSE, 0);
  gtk_widget_set_size_request (hbox1, -1, 70);

  vbox5 = gtk_vbox_new (TRUE, 0);
  gtk_widget_set_name (vbox5, "vbox5");
  gtk_widget_show (vbox5);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox5, TRUE, TRUE, 0);

  fixed4 = gtk_fixed_new ();
  gtk_widget_set_name (fixed4, "fixed4");
  gtk_widget_show (fixed4);
  gtk_box_pack_start (GTK_BOX (vbox5), fixed4, FALSE, FALSE, 0);

  frmConVendas_labRegistros = gtk_label_new (_("Registro 0 de 0 "));
  gtk_widget_set_name (frmConVendas_labRegistros,
		       "frmConVendas_labRegistros");
  gtk_widget_show (frmConVendas_labRegistros);
  gtk_fixed_put (GTK_FIXED (fixed4), frmConVendas_labRegistros, 8, 8);
  gtk_widget_set_size_request (frmConVendas_labRegistros, 248, 16);
  gtk_misc_set_alignment (GTK_MISC (frmConVendas_labRegistros), 0, 0.5);

  fixed5 = gtk_fixed_new ();
  gtk_widget_set_name (fixed5, "fixed5");
  gtk_widget_show (fixed5);
  gtk_box_pack_start (GTK_BOX (vbox5), fixed5, FALSE, FALSE, 0);

  vbox2 = gtk_vbox_new (TRUE, 10);
  gtk_widget_set_name (vbox2, "vbox2");
  gtk_widget_show (vbox2);
  gtk_box_pack_start (GTK_BOX (hbox1), vbox2, FALSE, FALSE, 2);
  gtk_container_set_border_width (GTK_CONTAINER (vbox2), 2);

  fixed3 = gtk_fixed_new ();
  gtk_widget_set_name (fixed3, "fixed3");
  gtk_widget_show (fixed3);
  gtk_box_pack_start (GTK_BOX (vbox2), fixed3, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (fixed3), 6);

  frmConVendas_edtPrecoTotal = gtk_entry_new ();
  gtk_widget_set_name (frmConVendas_edtPrecoTotal, "edtPrecoTotal");
  gtk_widget_show (frmConVendas_edtPrecoTotal);
  gtk_fixed_put (GTK_FIXED (fixed3), frmConVendas_edtPrecoTotal, 128, 0);
  gtk_widget_set_size_request (frmConVendas_edtPrecoTotal, 158, 24);  
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmConVendas_edtPrecoTotal, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmConVendas_edtPrecoTotal, GTK_CAN_FOCUS);
  #endif

  labPrecoTotal = gtk_label_new (Rotinas_retUTF8("Preço Total: "));
  gtk_widget_set_name (labPrecoTotal, "labPrecoTotal");
  gtk_widget_show (labPrecoTotal);
  gtk_fixed_put (GTK_FIXED (fixed3), labPrecoTotal, 48, 0);
  gtk_widget_set_size_request (labPrecoTotal, 80, 16);

  hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_set_name (hbuttonbox1, "hbuttonbox1");
  gtk_widget_show (hbuttonbox1);
  gtk_box_pack_end (GTK_BOX (vbox2), hbuttonbox1, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (hbuttonbox1), 2);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (hbuttonbox1), GTK_BUTTONBOX_END);
  gtk_box_set_spacing (GTK_BOX (hbuttonbox1), 9);

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

  g_signal_connect ((gpointer) frmConVendas, "destroy",
    G_CALLBACK (on_frmConVendas_destroy), NULL);
  g_signal_connect ((gpointer) frmConVendas_edtDtHrVenda, "focus_out_event",
    G_CALLBACK (on_frmConVendas_edtDtHrVenda_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmConVendas_edtCPF, "focus_out_event",
    G_CALLBACK (on_frmConVendas_edtCPF_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmConVendas_edtISBN, "focus_out_event",
    G_CALLBACK (on_frmConVendas_edtISBN_focus_out_event), NULL);
  g_signal_connect ((gpointer) btnPCliente, "clicked",
    G_CALLBACK (on_frmConVendas_btnPCliente_clicked), NULL);
  g_signal_connect ((gpointer) btnPLivro, "clicked",
    G_CALLBACK (on_frmConVendas_btnPLivro_clicked), NULL);
  g_signal_connect ((gpointer) btnPesquisar, "clicked",
    G_CALLBACK (on_frmConVendas_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmConVendas_selection, "changed",
		    G_CALLBACK (on_frmConVendas_gridConsulta_selection_changed), NULL);
  g_signal_connect ((gpointer) btnLimpar, "clicked",
    G_CALLBACK (on_frmConVendas_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) btnFechar, "clicked",
    G_CALLBACK (on_frmConVendas_btnFechar_clicked), NULL);

  nLargura[0] = 120;
  nLargura[1] = 100;
  nLargura[2] = 220;
  nLargura[3] = 100;
  nLargura[4] = 280;
  nLargura[5] = 80;

  sRotulos[0] = g_string_new("Data/Hora Venda");
  sRotulos[1] = g_string_new("CPF");
  sRotulos[2] = g_string_new("Cliente");
  sRotulos[3] = g_string_new("ISBN");
  sRotulos[4] = g_string_new("Livro");
  sRotulos[5] = g_string_new(Rotinas_retUTF8("Preço"));

  Rotinas_AdicionaColunasGrid(GTK_TREE_VIEW(frmConVendas_gridConsulta), 0, 6, 
    nLargura, sRotulos);

  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtDtHrVenda),
    Rotinas_retDataHoraStr(TRUE, TRUE)); 
  gtk_widget_grab_focus(frmConVendas_edtDtHrVenda);

  return frmConVendas;
}

GString *frmConVendas_ConsVenda(gchar sOpcao) {
G_CONST_RETURN gchar *sCPF, *sISBN, *sDTHR;
GString *sret = g_string_new("");
GString *sDataHora = g_string_new("");

  sDTHR = Rotinas_retTexto(frmConVendas_edtDtHrVenda);
  if (strlen(sDTHR) > 0)
    g_string_assign(sDataHora, Rotinas_ConverteDataHoraStr(sDTHR, 
      TRUE, "%m/%d/%Y","%H:%M:%S"));
  else
    g_string_assign(sDataHora, "");

  sISBN = Rotinas_retTexto(frmConVendas_edtISBN);
  sCPF = Rotinas_retTexto(frmConVendas_edtCPF);

  if (sOpcao=='L')
    g_string_assign(sret, ConsSQL_Venda('S',"ZERO","","","","")->str);
  else
    g_string_assign(sret, ConsSQL_Venda(sOpcao, sISBN, sCPF, 
      sDataHora->str, "", "")->str);

 return sret;
}

void on_frmConVendas_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_mnuVendasRealizadas, TRUE);
  frmPrincipal_setaBarraStatus("");
}

gboolean on_frmConVendas_edtDtHrVenda_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sDTHR;
  sDTHR = Rotinas_retTexto(frmConVendas_edtDtHrVenda);
  if (strlen(sDTHR) > 0) {    
  	if (Rotinas_validaDataHora(sDTHR, FALSE)==FALSE) {      
      Rotinas_MsgDlg(STR_DTHRINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtDtHrVenda), 
        Rotinas_retDataHoraStr(TRUE,TRUE));
      gtk_widget_grab_focus(frmConVendas_edtDtHrVenda);
  	}
  }
  return FALSE;
}

gboolean on_frmConVendas_edtCPF_focus_out_event(GtkWidget *widget,
					GdkEventFocus *event,	gpointer user_data) {
G_CONST_RETURN gchar *sCPF, *sCliente;
LISTAMSTR ConsCampo;

  sCPF = Rotinas_retTexto(frmConVendas_edtCPF);
  if (strlen(sCPF) > 0) {
  	if (Rotinas_ValidaCPF(sCPF)) {
      sCliente = Rotinas_ConsultaCampoDesc(&ConsCampo, "", FALSE, 
      ConsSQL_Cliente('S', sCPF,"","","","","","","","",""),STR_CLINENC);     
      if (strlen(sCliente)==0) {
        gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCPF), "");
        gtk_widget_grab_focus(frmConVendas_edtCPF);
      } else
        gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCliente), sCliente);
  	} else {
      Rotinas_MsgDlg(STR_CPFINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCPF), "");
      gtk_widget_grab_focus(frmConVendas_edtCPF);
    }
  } else
     gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCliente), "");

  return FALSE;
}

gboolean on_frmConVendas_edtISBN_focus_out_event(GtkWidget *widget, 
                        GdkEventFocus *event, gpointer user_data) {
G_CONST_RETURN gchar *sISBN, *sLivro, *sQtdEstoque;
gint nQtdEstoque;
LISTAMSTR ConsCampo;

  sISBN = Rotinas_retTexto(frmConVendas_edtISBN);
  if (strlen(sISBN) > 0) {
  	if (Rotinas_ValidaISBN(sISBN)) {      

      sLivro = Rotinas_ConsultaCampoDesc(&ConsCampo, "", FALSE, 
      ConsSQL_Livro('Q',sISBN,"","","","","","","","",""),STR_CLINENC); 
      if (strlen(sLivro)==0) {
        gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtISBN), "");
        gtk_widget_grab_focus(frmConVendas_edtISBN);
      } else {
         gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtLivro), sLivro);

         sQtdEstoque = Rotinas_retValorListaM(&ConsCampo, 3, 0);
         nQtdEstoque = atoi(sQtdEstoque);
         if (nQtdEstoque > 0) {
           Rotinas_sPreco = g_string_new(
             Rotinas_retValorListaM(&ConsCampo, 2, 0));
         } else
           Rotinas_MsgDlg(STR_LIVNEST, GTK_MESSAGE_ERROR);
      }
  	} else {
      Rotinas_MsgDlg(STR_ISBNINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtISBN), "");
      gtk_widget_grab_focus(frmConVendas_edtISBN);
    }
  } else
     gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtLivro), "");

  return FALSE;
}

void on_frmConVendas_btnPCliente_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmConClientes = frmConClientes_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConClientes));
  gtk_widget_destroy(frmConClientes);
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCPF), 
    Rotinas_sCodigoSelecionado->str);
  on_frmConVendas_edtCPF_focus_out_event(NULL, NULL, NULL);
}

void on_frmConVendas_btnPLivro_clicked(GtkButton *button, 
                                       gpointer user_data) {

  frmConLivros = frmConLivros_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConLivros));
  gtk_widget_destroy(frmConLivros);
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtISBN), 
    Rotinas_sCodigoSelecionado->str);
  on_frmConVendas_edtISBN_focus_out_event(NULL, NULL, NULL);
}

void on_frmConVendas_btnPesquisar_clicked(GtkButton *button, 
                                          gpointer user_data) {
LISTAMSTR ConsTotal;  
GString *sPrecoTotal = g_string_new("");
gdouble nPreco;
gchar* fimptr[TAM_MAX_STR];

  if (Rotinas_ConsultaDadosLista(gConexao, &lstLinVendas, 
    frmConVendas_ConsVenda('S'))) {
    Rotinas_AdicionaLinhasGrid(GTK_TREE_VIEW(frmConVendas_gridConsulta), 
      &lstLinVendas, 6, TRUE);

    if (Rotinas_ConsultaDadosLista(gConexao, &ConsTotal, 
        frmConVendas_ConsVenda('P'))) {
      if (ConsTotal.col[0]->len > 0) {     
        nPreco = g_strtod(Rotinas_retValorListaM(&ConsTotal, 0, 0), fimptr);
        g_string_sprintf(sPrecoTotal, "R$ %.2f", nPreco);
        gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtPrecoTotal),
          sPrecoTotal->str);
      }
    }

  } else
     Rotinas_MsgDlg(STR_VENNENC, GTK_MESSAGE_ERROR);

}

void on_frmConVendas_btnLimpar_clicked(GtkButton *button, 
                                       gpointer user_data) {
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCPF), "");
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtCliente), "");
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtISBN), "");
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtLivro), "");
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtDtHrVenda),
    Rotinas_retDataHoraStr(TRUE, TRUE)); 
  Rotinas_LimpaModeloGrid(GTK_TREE_VIEW(frmConVendas_gridConsulta));
  gtk_entry_set_text(GTK_ENTRY(frmConVendas_edtPrecoTotal), "R$ 0,00");
  gtk_widget_grab_focus(frmConVendas_edtDtHrVenda);
}

void on_frmConVendas_btnFechar_clicked(GtkButton *button, 
                                       gpointer user_data) {
  gtk_widget_destroy(frmConVendas);
}

void frmConVendas_setLabRegistros(gint nLinha) {
GString *sTemp = g_string_new("");

  g_string_sprintf(sTemp, "Registro %d de %d", nLinha, 
    lstLinVendas.col[0]->len);
  gtk_label_set_text(GTK_LABEL(frmConVendas_labRegistros), sTemp->str);
}

void on_frmConVendas_gridConsulta_selection_changed(
      GtkTreeSelection* selection, gpointer user_data) {
gint nLinha;
GtkTreeModel *modeloGrid;
GtkTreeIter iter;

  if (gtk_tree_selection_get_selected (selection, &modeloGrid, &iter)) {
    gtk_tree_model_get(modeloGrid, &iter, 0, &nLinha, -1);
    frmConVendas_setLabRegistros(nLinha);
  }
}
