#include "Cadastros.h"
#include "Principal.h"

GtkWidget *frmCadastros;
GtkWidget *frmCadastros_fixed1;
GtkWidget *frmCadastros_labCodigo;
GtkWidget *frmCadastros_btnNovo;
GtkWidget *frmCadastros_labDescricao;
GtkWidget *frmCadastros_btnPesquisar;
GtkWidget *frmCadastros_btnAnterior;
GtkWidget *frmCadastros_btnProximo;
GtkWidget *frmCadastros_btnSalvar;
GtkWidget *frmCadastros_btnExcluir;
GtkWidget *frmCadastros_btnLimpar;
GtkWidget *frmCadastros_btnFechar;

GtkWidget *frmCadastros_Criar(gboolean bIniciaBotoes, gchar* sTitulo,
                              GtkWidget **edtCodigo, GtkWidget **edtDescricao)
{
  GdkPixbuf *frmCadastros_icon_pixbuf;
 
  frmCadastros = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_name (frmCadastros, "frmCadastros");
  gtk_window_set_title (GTK_WINDOW (frmCadastros), Rotinas_retUTF8(sTitulo));
  gtk_window_set_position (GTK_WINDOW (frmCadastros), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size (GTK_WINDOW (frmCadastros), 300, 150);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (frmCadastros), TRUE);
  frmCadastros_icon_pixbuf = gdk_pixbuf_new_from_file ("xpms/livrus.xpm", NULL);
  if (frmCadastros_icon_pixbuf) {
    gtk_window_set_icon (GTK_WINDOW (frmCadastros), frmCadastros_icon_pixbuf);
    gdk_pixbuf_unref (frmCadastros_icon_pixbuf);
  }
          
  frmCadastros_fixed1 = gtk_fixed_new ();
  gtk_widget_set_name (frmCadastros_fixed1, "fixed1");
  gtk_widget_show (frmCadastros_fixed1);
  gtk_container_add (GTK_CONTAINER (frmCadastros), frmCadastros_fixed1);

  frmCadastros_labCodigo = gtk_label_new (Rotinas_retUTF8("Código:"));
  gtk_widget_set_name (frmCadastros_labCodigo, "labCodigo");
  gtk_widget_show (frmCadastros_labCodigo);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadastros_labCodigo, 8, 8);
  gtk_widget_set_size_request (frmCadastros_labCodigo, 64, 16);
  gtk_misc_set_alignment (GTK_MISC (frmCadastros_labCodigo), 0, 0.5);

  (*edtCodigo) = gtk_entry_new ();
  gtk_widget_set_name ((*edtCodigo), "edtCodigo");
  gtk_widget_show ((*edtCodigo));
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), (*edtCodigo), 8, 24);
  gtk_widget_set_size_request ((*edtCodigo), 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY ((*edtCodigo)), 10);

  frmCadastros_btnNovo = gtk_button_new_with_mnemonic (_("_Novo"));
  gtk_widget_set_name (frmCadastros_btnNovo, "btnNovo");
  gtk_widget_show (frmCadastros_btnNovo);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadastros_btnNovo, 176, 24);
  gtk_widget_set_size_request (frmCadastros_btnNovo, 85, 28);

  frmCadastros_labDescricao = gtk_label_new (Rotinas_retUTF8("Descrição:"));
  gtk_widget_set_name (frmCadastros_labDescricao, "labDescricao");
  gtk_widget_show (frmCadastros_labDescricao);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadastros_labDescricao, 8, 56);
  gtk_widget_set_size_request (frmCadastros_labDescricao, 80, 16);
  gtk_misc_set_alignment (GTK_MISC (frmCadastros_labDescricao), 0, 0.5);

  (*edtDescricao) = gtk_entry_new ();
  gtk_widget_set_name ((*edtDescricao), "edtDescricao");
  gtk_widget_set_sensitive ((*edtDescricao), FALSE);
  gtk_widget_show ((*edtDescricao));
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), (*edtDescricao), 8, 72);
  gtk_widget_set_size_request ((*edtDescricao), 288, 24);
  gtk_entry_set_max_length (GTK_ENTRY ((*edtDescricao)), 30);

  if (bIniciaBotoes)
    frmCadastros_IniciaBotoes(312, 10, 45, 112);

  return frmCadastros;
}

// Necessário por causa da tabulação dos campos
void frmCadastros_IniciaBotoes(gint nX1, gint nY1, gint nX2, gint nY2) {

  GtkWidget *frmCadastros_vbuttonbox1;
  GtkWidget *frmCadastros_hbuttonbox1;

  frmCadastros_vbuttonbox1 = gtk_vbutton_box_new ();
  gtk_widget_set_name (frmCadastros_vbuttonbox1, "vbuttonbox1");
  gtk_widget_show (frmCadastros_vbuttonbox1);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadastros_vbuttonbox1, nX1, nY1);
  gtk_widget_set_size_request (frmCadastros_vbuttonbox1, 96, 94);

  frmCadastros_btnPesquisar = gtk_button_new_with_mnemonic (_("_Pesquisar"));
  gtk_widget_set_name (frmCadastros_btnPesquisar, "btnPesquisar");
  gtk_widget_show (frmCadastros_btnPesquisar);
  gtk_container_add (GTK_CONTAINER (frmCadastros_vbuttonbox1), frmCadastros_btnPesquisar);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnPesquisar, GTK_CAN_DEFAULT);

  frmCadastros_btnAnterior = gtk_button_new_with_mnemonic (_("_Anterior"));
  gtk_widget_set_name (frmCadastros_btnAnterior, "btnAnterior");
  gtk_widget_set_sensitive (frmCadastros_btnAnterior, FALSE);
  gtk_widget_show (frmCadastros_btnAnterior);
  gtk_container_add (GTK_CONTAINER (frmCadastros_vbuttonbox1), frmCadastros_btnAnterior);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnAnterior, GTK_CAN_DEFAULT);

  frmCadastros_btnProximo = gtk_button_new_with_mnemonic (Rotinas_retUTF8("Próxi_mo"));
  gtk_widget_set_name (frmCadastros_btnProximo, "btnProximo");
  gtk_widget_set_sensitive (frmCadastros_btnProximo, FALSE);
  gtk_widget_show (frmCadastros_btnProximo);
  gtk_container_add (GTK_CONTAINER (frmCadastros_vbuttonbox1), frmCadastros_btnProximo);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnProximo, GTK_CAN_DEFAULT);

  frmCadastros_hbuttonbox1 = gtk_hbutton_box_new ();
  gtk_widget_set_name (frmCadastros_hbuttonbox1, "hbuttonbox1");
  gtk_widget_show (frmCadastros_hbuttonbox1);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadastros_hbuttonbox1, nX2, nY2);
  gtk_widget_set_size_request (frmCadastros_hbuttonbox1, 360, 32);

  frmCadastros_btnSalvar = gtk_button_new_with_mnemonic (_("_Salvar"));
  gtk_widget_set_name (frmCadastros_btnSalvar, "btnSalvar");
  gtk_widget_set_sensitive (frmCadastros_btnSalvar, FALSE);
  gtk_widget_show (frmCadastros_btnSalvar);
  gtk_container_add (GTK_CONTAINER (frmCadastros_hbuttonbox1), frmCadastros_btnSalvar);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnSalvar, GTK_CAN_DEFAULT);

  frmCadastros_btnExcluir = gtk_button_new_with_mnemonic (_("_Excluir"));
  gtk_widget_set_name (frmCadastros_btnExcluir, "btnExcluir");
  gtk_widget_set_sensitive (frmCadastros_btnExcluir, FALSE);
  gtk_widget_show (frmCadastros_btnExcluir);
  gtk_container_add (GTK_CONTAINER (frmCadastros_hbuttonbox1), frmCadastros_btnExcluir);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnExcluir, GTK_CAN_DEFAULT);

  frmCadastros_btnLimpar = gtk_button_new_with_mnemonic (_("_Limpar"));
  gtk_widget_set_name (frmCadastros_btnLimpar, "btnLimpar");
  gtk_widget_show (frmCadastros_btnLimpar);
  gtk_container_add (GTK_CONTAINER (frmCadastros_hbuttonbox1), frmCadastros_btnLimpar);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnLimpar, GTK_CAN_DEFAULT);

  frmCadastros_btnFechar = gtk_button_new_with_mnemonic (_("_Fechar"));
  gtk_widget_set_name (frmCadastros_btnFechar, "btnFechar");
  gtk_widget_show (frmCadastros_btnFechar);
  gtk_container_add (GTK_CONTAINER (frmCadastros_hbuttonbox1), frmCadastros_btnFechar);
  GTK_WIDGET_SET_FLAGS (frmCadastros_btnFechar, GTK_CAN_DEFAULT);
}

void frmCadastros_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar, 
  GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{
  if (bInformar) {
    gtk_entry_set_text(GTK_ENTRY(edtCodigo), 
      Rotinas_retValorListaM(lstRegistros, 0, nLinhaRegistro));   
    gtk_entry_set_text(GTK_ENTRY(edtDescricao), 
      Rotinas_retValorListaM(lstRegistros, 1, nLinhaRegistro));
  } else {
    gtk_entry_set_text(GTK_ENTRY(edtCodigo),""); 
    gtk_entry_set_text(GTK_ENTRY(edtDescricao),""); 
    gtk_widget_set_sensitive(edtCodigo, TRUE);
    gtk_widget_grab_focus(edtCodigo);
  }
} 

void frmCadastros_HabilitaDados(gboolean bHabilita, GtkWidget *edtDescricao)
{
  gtk_widget_set_sensitive(edtDescricao, bHabilita);
}

void frmCadastros_btnNovoClick(GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{ 
  gtk_widget_set_sensitive(frmCadastros_btnSalvar, TRUE);
  gtk_widget_set_sensitive(frmCadastros_btnExcluir, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnPesquisar, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnAnterior, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnProximo, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnNovo, FALSE);
  
  frmCadastros_InformaLimpaDados(NULL, 0, FALSE, edtCodigo, edtDescricao);
  frmCadastros_HabilitaDados(TRUE, edtDescricao);	
}

void frmCadastros_NovoDado(GString *sTextoSql,
                           GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{ 
  LISTAMSTR lstRegs;

  if (Rotinas_ConsultaDadosLista(gConexao, &lstRegs, sTextoSql)) {
    gtk_entry_set_text(GTK_ENTRY(edtCodigo), 
      Rotinas_retValorListaM(&lstRegs, 0, 0));   
    #ifdef G_OS_WIN32
      gtk_widget_set_sensitive(edtCodigo, FALSE);
    #else
      GTK_WIDGET_UNSET_FLAGS (edtCodigo, GTK_CAN_FOCUS);
    #endif
    gtk_widget_grab_focus(edtDescricao);
  }
}

void frmCadastros_btnLimparClick(GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{
  gtk_widget_set_sensitive(frmCadastros_btnSalvar, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnExcluir, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnPesquisar, TRUE);
  gtk_widget_set_sensitive(frmCadastros_btnAnterior, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnProximo, FALSE);
  gtk_widget_set_sensitive(frmCadastros_btnNovo, TRUE);

  frmCadastros_InformaLimpaDados(NULL, 0, FALSE, edtCodigo, edtDescricao);
  frmCadastros_HabilitaDados(FALSE, edtDescricao);	
}

gboolean frmCadastros_ExcluirDados(gboolean bValidaDados, GString *sTextoSql,
                               GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{
  GtkWidget *dialog;

   if (bValidaDados) {
      dialog = gtk_message_dialog_new(GTK_WINDOW(frmPrincipal),
        GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_QUESTION,
        GTK_BUTTONS_YES_NO, "%s", STR_CERTEXCL);
      gtk_window_set_position(GTK_WINDOW(dialog), GTK_WIN_POS_CENTER);
      if (gtk_dialog_run(GTK_DIALOG (dialog))==GTK_RESPONSE_YES) {
        gtk_widget_destroy (dialog);
      
        if (Rotinas_AtualizaDados(gConexao, sTextoSql)) {
           frmCadastros_btnLimparClick(edtCodigo, edtDescricao);
           return TRUE;
        }
      } else
         gtk_widget_destroy (dialog);
   }
  return FALSE;
}

gboolean frmCadastros_PesquisarDados(LISTAMSTR *lstRegistros, 
  GString *sTextoSql, gchar *sMensagemErro,
  GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{  
	if ( strlen(Rotinas_retTexto(edtCodigo)) == 0) {
    gtk_widget_set_sensitive(frmCadastros_btnAnterior, TRUE);
    gtk_widget_set_sensitive(frmCadastros_btnProximo, TRUE);
	}

  if (Rotinas_ConsultaDadosLista(gConexao, lstRegistros, sTextoSql)) {
     frmCadastros_InformaLimpaDados(lstRegistros, 0, TRUE, 
       edtCodigo, edtDescricao);
     frmCadastros_HabilitaDados(TRUE, edtDescricao);	

     gtk_widget_set_sensitive(frmCadastros_btnSalvar, TRUE);
     gtk_widget_set_sensitive(frmCadastros_btnExcluir, TRUE);
     gtk_widget_set_sensitive(frmCadastros_btnPesquisar, FALSE);

     return TRUE;
	} else
    Rotinas_MsgDlg(sMensagemErro, GTK_MESSAGE_ERROR);

  return FALSE;
}

gboolean frmCadastros_registroAnterior(LISTAMSTR *lstRegistros, 
  gint *nLinhaRegistro, GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{
	if (*nLinhaRegistro > 0) {
    (*nLinhaRegistro)--;
    frmCadastros_InformaLimpaDados(lstRegistros, *nLinhaRegistro, TRUE, 
      edtCodigo, edtDescricao);
    return TRUE;
	} else
    return FALSE;
}

gboolean frmCadastros_registroProximo(LISTAMSTR *lstRegistros, 
  gint *nLinhaRegistro, GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{
	if (*nLinhaRegistro < abs(lstRegistros->col[0]->len-1)) {
    (*nLinhaRegistro)++;
    frmCadastros_InformaLimpaDados(lstRegistros, *nLinhaRegistro, TRUE,
      edtCodigo, edtDescricao);
    return TRUE;
	} else
    return FALSE;
}

gboolean frmCadastros_SalvarDados(gboolean bValidaDados, GString *sTextoSql, 
  GString *sTextoUpdate, GString *sTextoInsert, gboolean bLimparDados,
  GtkWidget *edtCodigo, GtkWidget *edtDescricao)
{
GString *sArquiva = g_string_new("");

	if (bValidaDados) {    
	   if (Rotinas_ConsultaDados(gConexao,sTextoSql))
         g_string_assign(sArquiva, sTextoUpdate->str);
     else
         g_string_assign(sArquiva, sTextoInsert->str);

     if (Rotinas_AtualizaDados(gConexao, sArquiva)) {
  	   if (bLimparDados)
         frmCadastros_btnLimparClick(edtCodigo, edtDescricao);
       return TRUE;
     }
	}
  return FALSE;
}

void frmCadastros_ValidaCodigo(GtkWidget *edtCodigo) {
  G_CONST_RETURN gchar *sCodigo;
  sCodigo = Rotinas_retTexto(edtCodigo);
  if (strlen(sCodigo) > 0) {
  	if (Rotinas_ValidaInteger(sCodigo)==FALSE) {      
      gtk_entry_set_text(GTK_ENTRY(edtCodigo), "");
      gtk_widget_grab_focus(edtCodigo);
  	}
  }
}

