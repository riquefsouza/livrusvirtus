#include "Principal.h"
#include "Cadastros.h"
#include "CadClientes.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"
#include "ConEnderecos.h"
#include "ConPaises.h"
#include "ConProfissoes.h"

LISTAMSTR lstRegClientes;
gint nRegClientes;

GtkWidget *frmCadClientes_Criar(void)
{
  GtkWidget *labEmail;
  GtkWidget *labIdentidade;
  GtkWidget *labTelefone;
  GtkWidget *labDtNascimento;
  GtkWidget *fixed2;
  GSList *rbMasculino_group = NULL;
  GtkWidget *labSexo;
  GtkWidget *labProfissao;
  GtkWidget *labPais;
  GtkWidget *fixed3;
  GtkWidget *labLogradouro;
  GtkWidget *labBairro;
  GtkWidget *labCep;
  GtkWidget *labCidade;
  GtkWidget *labEstado;
  GtkWidget *labEndereco;

  frmCadClientes = frmCadastros_Criar(FALSE, STR_CADCLIENTE, 
    &frmCadClientes_edtCodigo, &frmCadClientes_edtDescricao);
  gtk_widget_set_name(frmCadClientes, "frmCadClientes");
  gtk_window_set_default_size (GTK_WINDOW (frmCadClientes), 560, 465);

  gtk_label_set_text(GTK_LABEL(frmCadastros_labCodigo), "CPF: ");
  gtk_misc_set_alignment (GTK_MISC (frmCadastros_labCodigo), 0, 0.5);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtCodigo), 14);
  
  gtk_label_set_text(GTK_LABEL(frmCadastros_labDescricao), "Nome: ");
  gtk_misc_set_alignment (GTK_MISC (frmCadastros_labDescricao), 0, 0.5);
  gtk_widget_set_size_request(frmCadClientes_edtDescricao, 320, 24);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadClientes_edtDescricao), 30); 

  frmCadClientes_edtIdentidade = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtIdentidade, "edtIdentidade");
  gtk_widget_show (frmCadClientes_edtIdentidade);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtIdentidade, 336, 112);
  gtk_widget_set_size_request (frmCadClientes_edtIdentidade, 126, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtIdentidade), 10);
  gtk_widget_set_sensitive(frmCadClientes_edtIdentidade, FALSE);

  frmCadClientes_edtEmail = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtEmail, "edtEmail");
  gtk_widget_show (frmCadClientes_edtEmail);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtEmail, 8, 112);
  gtk_widget_set_size_request (frmCadClientes_edtEmail, 320, 24);
  gtk_widget_set_sensitive(frmCadClientes_edtEmail, FALSE);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadClientes_edtEmail), 30); 

  frmCadClientes_edtTelefone = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtTelefone, "edtTelefone");
  gtk_widget_show (frmCadClientes_edtTelefone);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtTelefone, 200, 160);
  gtk_widget_set_size_request (frmCadClientes_edtTelefone, 128, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtTelefone), 17);
  gtk_widget_set_sensitive(frmCadClientes_edtTelefone, FALSE);

  labEmail = gtk_label_new (_("E-mail:"));
  gtk_widget_set_name (labEmail, "labEmail");
  gtk_widget_show (labEmail);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labEmail, 8, 96);
  gtk_misc_set_alignment (GTK_MISC (labEmail), 0, 0.5);
  gtk_widget_set_size_request (labEmail, 55, 16);

  labIdentidade = gtk_label_new (_("Identidade:"));
  gtk_widget_set_name (labIdentidade, "labIdentidade");
  gtk_widget_show (labIdentidade);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labIdentidade, 336, 96);
  gtk_widget_set_size_request (labIdentidade, 100, 16);
  gtk_misc_set_alignment (GTK_MISC (labIdentidade), 0, 0);

  labTelefone = gtk_label_new (_("Telefone:"));
  gtk_widget_set_name (labTelefone, "labTelefone");
  gtk_widget_show (labTelefone);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labTelefone, 200, 144);
  gtk_widget_set_size_request (labTelefone, 55, 16);

  frmCadClientes_edtDtNasc = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtDtNasc, "edtDtNasc");
  gtk_widget_show (frmCadClientes_edtDtNasc);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtDtNasc, 336, 160);
  gtk_widget_set_size_request (frmCadClientes_edtDtNasc, 128, 24);
  gtk_widget_set_sensitive(frmCadClientes_edtDtNasc, FALSE);
  gtk_entry_set_max_length(GTK_ENTRY(frmCadClientes_edtDtNasc), 10); 

  labDtNascimento = gtk_label_new (_("Dt. Nascimento:"));
  gtk_widget_set_name (labDtNascimento, "labDtNascimento");
  gtk_widget_show (labDtNascimento);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labDtNascimento, 336, 144);
  gtk_widget_set_size_request (labDtNascimento, 110, 16);
  gtk_misc_set_alignment (GTK_MISC (labDtNascimento), 0, 0.5);

  frmCadClientes_grpSexo = gtk_frame_new (NULL);
  gtk_widget_set_name (frmCadClientes_grpSexo, "grpSexo");
  gtk_widget_show (frmCadClientes_grpSexo);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_grpSexo, 8, 144);
  gtk_widget_set_size_request (frmCadClientes_grpSexo, 190, 44);
  gtk_widget_set_sensitive(frmCadClientes_grpSexo, FALSE);

  fixed2 = gtk_fixed_new ();
  gtk_widget_set_name (fixed2, "fixed2");
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (frmCadClientes_grpSexo), fixed2);
  gtk_container_set_border_width (GTK_CONTAINER (fixed2), 1);

  frmCadClientes_rbMasculino = gtk_radio_button_new_with_mnemonic (NULL, _("Masculino"));
  gtk_widget_set_name (frmCadClientes_rbMasculino, "rbMasculino");
  gtk_widget_show (frmCadClientes_rbMasculino);
  gtk_fixed_put (GTK_FIXED (fixed2), frmCadClientes_rbMasculino, 8, 0);
  gtk_widget_set_size_request (frmCadClientes_rbMasculino, 87, 22);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (frmCadClientes_rbMasculino),
			      rbMasculino_group);
  rbMasculino_group =
    gtk_radio_button_get_group (GTK_RADIO_BUTTON (frmCadClientes_rbMasculino));

  frmCadClientes_rbFeminino = gtk_radio_button_new_with_mnemonic (NULL, _("Feminino"));
  gtk_widget_set_name (frmCadClientes_rbFeminino, "rbFeminino");
  gtk_widget_show (frmCadClientes_rbFeminino);
  gtk_fixed_put (GTK_FIXED (fixed2), frmCadClientes_rbFeminino, 96, 0);
  gtk_widget_set_size_request (frmCadClientes_rbFeminino, 87, 21);
  gtk_radio_button_set_group (GTK_RADIO_BUTTON (frmCadClientes_rbFeminino),
			      rbMasculino_group);
  rbMasculino_group =
    gtk_radio_button_get_group (GTK_RADIO_BUTTON (frmCadClientes_rbFeminino)); 

  labSexo = gtk_label_new (_("Sexo"));
  gtk_widget_set_name (labSexo, "labSexo");
  gtk_widget_show (labSexo);
  gtk_frame_set_label_widget (GTK_FRAME (frmCadClientes_grpSexo), labSexo);
  gtk_label_set_use_markup (GTK_LABEL (labSexo), TRUE);
  gtk_misc_set_alignment (GTK_MISC (labSexo), 0.5, 0);
  gtk_misc_set_padding (GTK_MISC (labSexo), 1, 0);

  frmCadClientes_edtCodPais = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtCodPais, "edtCodPais");
  gtk_widget_show (frmCadClientes_edtCodPais);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtCodPais, 8, 352);
  gtk_widget_set_size_request (frmCadClientes_edtCodPais, 96, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtCodPais), 10);
  gtk_widget_set_sensitive(frmCadClientes_edtCodPais, FALSE);

  frmCadClientes_edtPais = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtPais, "edtPais");
  gtk_widget_show (frmCadClientes_edtPais);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtPais, 112, 352);
  gtk_widget_set_size_request (frmCadClientes_edtPais, 232, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtPais, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtPais, GTK_CAN_FOCUS);
  #endif

  frmCadClientes_edtCodProfissao = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtCodProfissao, "edtCodProfissao");
  gtk_widget_show (frmCadClientes_edtCodProfissao);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtCodProfissao, 8, 392);
  gtk_widget_set_size_request (frmCadClientes_edtCodProfissao, 96, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtCodProfissao), 10);
  gtk_widget_set_sensitive(frmCadClientes_edtCodProfissao, FALSE);

  frmCadClientes_edtProfissao = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtProfissao, "edtProfissao");
  gtk_widget_show (frmCadClientes_edtProfissao);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), frmCadClientes_edtProfissao, 112, 392);
  gtk_widget_set_size_request (frmCadClientes_edtProfissao, 232, 24); 
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtProfissao, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtProfissao, GTK_CAN_FOCUS);
  #endif

  labProfissao = gtk_label_new (Rotinas_retUTF8("Profissão:"));
  gtk_widget_set_name (labProfissao, "labProfissao");
  gtk_widget_show (labProfissao);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labProfissao, 8, 376);
  gtk_widget_set_size_request (labProfissao, 100, 16);
  gtk_misc_set_alignment (GTK_MISC (labProfissao), 0, 0);

  labPais = gtk_label_new (Rotinas_retUTF8("País de origem:"));
  gtk_widget_set_name (labPais, "labPais");
  gtk_widget_show (labPais);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), labPais, 8, 336);
  gtk_widget_set_size_request (labPais, 100, 16);
  gtk_misc_set_alignment (GTK_MISC (labPais), 0, 0);

  frmCadClientes_btnPPais = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (frmCadClientes_btnPPais, "btnPPais");
  gtk_widget_show (frmCadClientes_btnPPais);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), 
    frmCadClientes_btnPPais, 344, 352);
  gtk_widget_set_size_request (frmCadClientes_btnPPais, 25, 25);
  gtk_widget_set_sensitive(frmCadClientes_btnPPais, FALSE);

  frmCadClientes_btnPProfissao = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (frmCadClientes_btnPProfissao, "btnPProfissao");
  gtk_widget_show (frmCadClientes_btnPProfissao);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), 
    frmCadClientes_btnPProfissao, 344, 392);
  gtk_widget_set_size_request (frmCadClientes_btnPProfissao, 25, 25);
  gtk_widget_set_sensitive(frmCadClientes_btnPProfissao, FALSE);

  frmCadClientes_grpEndereco = gtk_frame_new (NULL);
  gtk_widget_set_name (frmCadClientes_grpEndereco, "grpEndereco");
  gtk_widget_show (frmCadClientes_grpEndereco);
  gtk_fixed_put (GTK_FIXED (frmCadastros_fixed1), 
    frmCadClientes_grpEndereco, 8, 192);
  gtk_widget_set_size_request (frmCadClientes_grpEndereco, 480, 135);
  gtk_widget_set_sensitive(frmCadClientes_grpEndereco, FALSE);

  fixed3 = gtk_fixed_new ();
  gtk_widget_set_name (fixed3, "fixed3");
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (frmCadClientes_grpEndereco), fixed3);

  frmCadClientes_edtCodEndereco = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtCodEndereco, "edtCodEndereco");
  gtk_widget_show (frmCadClientes_edtCodEndereco);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_edtCodEndereco, 8, 8);
  gtk_widget_set_size_request (frmCadClientes_edtCodEndereco, 112, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtCodEndereco), 10);

  frmCadClientes_edtLogradouro = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtLogradouro, "edtLogradouro");
  gtk_widget_show (frmCadClientes_edtLogradouro);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_edtLogradouro, 8, 48);
  gtk_widget_set_size_request (frmCadClientes_edtLogradouro, 288, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtLogradouro), 50); 
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtLogradouro, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtLogradouro, GTK_CAN_FOCUS);
  #endif

  frmCadClientes_edtBairro = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtBairro, "edtBairro");
  gtk_widget_show (frmCadClientes_edtBairro);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_edtBairro, 304, 48);
  gtk_widget_set_size_request (frmCadClientes_edtBairro, 158, 24);
  gtk_entry_set_max_length (GTK_ENTRY (frmCadClientes_edtBairro), 30);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtBairro, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtBairro, GTK_CAN_FOCUS);
  #endif

  frmCadClientes_edtCep = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtCep, "edtCep");
  gtk_widget_show (frmCadClientes_edtCep);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_edtCep, 8, 88);
  gtk_widget_set_size_request (frmCadClientes_edtCep, 88, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtCep, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtCep, GTK_CAN_FOCUS);
  #endif

  frmCadClientes_edtCidade = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtCidade, "edtCidade");
  gtk_widget_show (frmCadClientes_edtCidade);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_edtCidade, 104, 88);
  gtk_widget_set_size_request (frmCadClientes_edtCidade, 192, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtCidade, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtCidade, GTK_CAN_FOCUS);
  #endif

  frmCadClientes_edtEstado = gtk_entry_new ();
  gtk_widget_set_name (frmCadClientes_edtEstado, "edtEstado");
  gtk_widget_show (frmCadClientes_edtEstado);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_edtEstado, 304, 88);
  gtk_widget_set_size_request (frmCadClientes_edtEstado, 158, 24);
  #ifdef G_OS_WIN32
    gtk_widget_set_sensitive(frmCadClientes_edtEstado, FALSE);
  #else
    GTK_WIDGET_UNSET_FLAGS(frmCadClientes_edtEstado, GTK_CAN_FOCUS);
  #endif

  labLogradouro = gtk_label_new (_("Logradouro:"));
  gtk_widget_set_name (labLogradouro, "labLogradouro");
  gtk_widget_show (labLogradouro);
  gtk_fixed_put (GTK_FIXED (fixed3), labLogradouro, 8, 32);
  gtk_widget_set_size_request (labLogradouro, 80, 16);
  gtk_misc_set_alignment (GTK_MISC (labLogradouro), 0, 0.5);

  labBairro = gtk_label_new (_("Bairro:"));
  gtk_widget_set_name (labBairro, "labBairro");
  gtk_widget_show (labBairro);
  gtk_fixed_put (GTK_FIXED (fixed3), labBairro, 304, 32);
  gtk_widget_set_size_request (labBairro, 45, 16);
  gtk_misc_set_alignment (GTK_MISC (labBairro), 0, 0);

  labCep = gtk_label_new (_("CEP:"));
  gtk_widget_set_name (labCep, "labCep");
  gtk_widget_show (labCep);
  gtk_fixed_put (GTK_FIXED (fixed3), labCep, 8, 72);
  gtk_widget_set_size_request (labCep, 38, 16);

  labCidade = gtk_label_new (_("Cidade:"));
  gtk_widget_set_name (labCidade, "labCidade");
  gtk_widget_show (labCidade);
  gtk_fixed_put (GTK_FIXED (fixed3), labCidade, 104, 72);
  gtk_widget_set_size_request (labCidade, 55, 16);

  labEstado = gtk_label_new (_("Estado:"));
  gtk_widget_set_name (labEstado, "labEstado");
  gtk_widget_show (labEstado);
  gtk_fixed_put (GTK_FIXED (fixed3), labEstado, 304, 72);
  gtk_widget_set_size_request (labEstado, 55, 16);
  gtk_misc_set_alignment (GTK_MISC (labEstado), 0, 0);

  frmCadClientes_btnPEndereco = gtk_button_new_with_mnemonic (_("..."));
  gtk_widget_set_name (frmCadClientes_btnPEndereco, "btnPEndereco");
  gtk_widget_show (frmCadClientes_btnPEndereco);
  gtk_fixed_put (GTK_FIXED (fixed3), frmCadClientes_btnPEndereco, 120, 8);
  gtk_widget_set_size_request (frmCadClientes_btnPEndereco, 25, 25);

  labEndereco = gtk_label_new (Rotinas_retUTF8("Endereço:"));
  gtk_widget_set_name (labEndereco, "labEndereco");
  gtk_widget_show (labEndereco);
  gtk_frame_set_label_widget (GTK_FRAME (frmCadClientes_grpEndereco), 
    labEndereco);
  gtk_label_set_use_markup (GTK_LABEL (labEndereco), TRUE);

  frmCadastros_IniciaBotoes(464, 10, 197, 430);

  g_signal_connect ((gpointer) frmCadClientes, "destroy",
    G_CALLBACK (on_frmCadClientes_destroy), NULL);
  g_signal_connect ((gpointer) frmCadClientes_edtCodigo, "focus_out_event",
    G_CALLBACK (on_frmCadClientes_edtCodigo_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnPesquisar, "clicked",
    G_CALLBACK (on_frmCadClientes_btnPesquisar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnAnterior, "clicked",
    G_CALLBACK (on_frmCadClientes_btnAnterior_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnProximo, "clicked",
    G_CALLBACK (on_frmCadClientes_btnProximo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnNovo, "clicked",
    G_CALLBACK (on_frmCadClientes_btnNovo_clicked), NULL);
  g_signal_connect ((gpointer) frmCadClientes_edtDtNasc, "focus_out_event", 
    G_CALLBACK(on_frmCadClientes_edtDtNasc_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadClientes_edtCodEndereco, "focus_out_event",
    G_CALLBACK (on_frmCadClientes_edtCodEndereco_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadClientes_btnPEndereco, "clicked",
    G_CALLBACK (on_frmCadClientes_btnPEndereco_clicked), NULL);
  g_signal_connect ((gpointer) frmCadClientes_edtCodPais, "focus_out_event",
    G_CALLBACK (on_frmCadClientes_edtCodPais_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadClientes_btnPPais, "clicked",
    G_CALLBACK (on_frmCadClientes_btnPPais_clicked), NULL);
  g_signal_connect ((gpointer) frmCadClientes_edtCodProfissao, "focus_out_event",
    G_CALLBACK (on_frmCadClientes_edtCodProfissao_focus_out_event), NULL);
  g_signal_connect ((gpointer) frmCadClientes_btnPProfissao, "clicked",
    G_CALLBACK (on_frmCadClientes_btnPProfissao_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnSalvar, "clicked",
    G_CALLBACK (on_frmCadClientes_btnSalvar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnExcluir, "clicked",
    G_CALLBACK (on_frmCadClientes_btnExcluir_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnLimpar, "clicked",
    G_CALLBACK (on_frmCadClientes_btnLimpar_clicked), NULL);
  g_signal_connect ((gpointer) frmCadastros_btnFechar, "clicked",
    G_CALLBACK (on_frmCadClientes_btnFechar_clicked), NULL);

  nRegClientes = 0;
  return frmCadClientes;
}

gboolean frmCadClientes_ValidaDados(gboolean bTodosDados)
{
  if (Rotinas_ValidaCampo(
    Rotinas_retTexto(frmCadClientes_edtCodigo), STR_CPFNINF))
 	  return FALSE;
  if (bTodosDados) {
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadClientes_edtDescricao), STR_CLININF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadClientes_edtEmail), STR_EMAILNINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadClientes_edtTelefone), STR_TELNINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadClientes_edtCodEndereco), STR_ENDNINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadClientes_edtCodPais), STR_PAISNINF))
  		return FALSE;
	  if (Rotinas_ValidaCampo(
        Rotinas_retTexto(frmCadClientes_edtCodProfissao), STR_PROFNINF))
  		return FALSE;
  }
  return TRUE;
}

gboolean on_frmCadClientes_edtCodigo_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodigo;
  sCodigo = Rotinas_retTexto(frmCadClientes_edtCodigo);
  if (strlen(sCodigo) > 0) {
  	if (Rotinas_ValidaCPF(sCodigo)==FALSE) {      
      Rotinas_MsgDlg(STR_CPFINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodigo), "");
      gtk_widget_grab_focus(frmCadClientes_edtCodigo);
  	}
  }
  return FALSE;
}

void on_frmCadClientes_btnNovo_clicked(GtkButton *button, gpointer user_data){
  frmCadastros_btnNovoClick(frmCadClientes_edtCodigo, 
    frmCadClientes_edtDescricao);
  frmCadClientes_InformaLimpaDados(NULL, 0, FALSE);
  frmCadClientes_HabilitaDados(TRUE);	
}

void on_frmCadClientes_btnPesquisar_clicked(GtkButton *button, 
                                            gpointer user_data) {
  if (frmCadastros_PesquisarDados(&lstRegClientes, ConsSQL_Cliente('S',
    Rotinas_retTexto(frmCadClientes_edtCodigo),
    "","","","","","","","",""), STR_CLINENC, 
    frmCadClientes_edtCodigo, frmCadClientes_edtDescricao)) {
     frmCadClientes_InformaLimpaDados(&lstRegClientes, nRegClientes, TRUE);
     frmCadClientes_HabilitaDados(TRUE);	
  }
}

void on_frmCadClientes_btnAnterior_clicked(GtkButton *button, 
                                           gpointer user_data) {
  if (frmCadastros_registroAnterior(&lstRegClientes, &nRegClientes, 
    frmCadClientes_edtCodigo, frmCadClientes_edtDescricao))
    frmCadClientes_InformaLimpaDados(&lstRegClientes, nRegClientes, TRUE);
}

void on_frmCadClientes_btnProximo_clicked(GtkButton *button,
                                          gpointer user_data) {
  if (frmCadastros_registroProximo(&lstRegClientes, &nRegClientes, 
    frmCadClientes_edtCodigo, frmCadClientes_edtDescricao))
    frmCadClientes_InformaLimpaDados(&lstRegClientes, nRegClientes, TRUE);
}

void on_frmCadClientes_btnSalvar_clicked(GtkButton *button, 
                                         gpointer user_data) {
GString *sSexo = g_string_new("");
GString *sDtNasc = g_string_new("");
GString *sSqlInsert = g_string_new("");
GString *sSqlUpdate = g_string_new("");
G_CONST_RETURN gchar *sDTHR;

  sDTHR = Rotinas_retTexto(frmCadClientes_edtDtNasc);
  g_string_assign(sDtNasc, 
    Rotinas_ConverteDataHoraStr(sDTHR, TRUE, "%m/%d/%Y", ""));

  if (gtk_toggle_button_get_active(
    GTK_TOGGLE_BUTTON(frmCadClientes_rbMasculino)))
     g_string_assign(sSexo, "M"); 
  else   
     g_string_assign(sSexo, "F");

  g_string_assign(sSqlUpdate, 
    ConsSQL_Cliente('U', Rotinas_retTexto(frmCadClientes_edtCodigo), 
    Rotinas_retTexto(frmCadClientes_edtDescricao), 
    Rotinas_retTexto(frmCadClientes_edtEmail),  
    Rotinas_retTexto(frmCadClientes_edtIdentidade), sSexo->str,  
    Rotinas_retTexto(frmCadClientes_edtTelefone), sDtNasc->str, 
    Rotinas_retTexto(frmCadClientes_edtCodEndereco), 
    Rotinas_retTexto(frmCadClientes_edtCodPais), 
    Rotinas_retTexto(frmCadClientes_edtCodProfissao))->str);

  g_string_assign(sSqlInsert, 
    ConsSQL_Cliente('I', Rotinas_retTexto(frmCadClientes_edtCodigo), 
    Rotinas_retTexto(frmCadClientes_edtDescricao), 
    Rotinas_retTexto(frmCadClientes_edtEmail),  
    Rotinas_retTexto(frmCadClientes_edtIdentidade), sSexo->str,  
    Rotinas_retTexto(frmCadClientes_edtTelefone), sDtNasc->str, 
    Rotinas_retTexto(frmCadClientes_edtCodEndereco), 
    Rotinas_retTexto(frmCadClientes_edtCodPais), 
    Rotinas_retTexto(frmCadClientes_edtCodProfissao))->str);

  if (frmCadastros_SalvarDados(frmCadClientes_ValidaDados(TRUE),
    ConsSQL_Cliente('S', Rotinas_retTexto(frmCadClientes_edtCodigo),
    "","","","","","","","",""), sSqlUpdate, sSqlInsert, TRUE,
      frmCadClientes_edtCodigo, frmCadClientes_edtDescricao)) {
    frmCadClientes_InformaLimpaDados(NULL, 0, FALSE);
    frmCadClientes_HabilitaDados(FALSE);	
  }
}

void on_frmCadClientes_btnExcluir_clicked(GtkButton *button, 
                                          gpointer user_data) {
  if (frmCadastros_ExcluirDados(frmCadClientes_ValidaDados(FALSE),
    ConsSQL_Cliente('D', Rotinas_retTexto(frmCadClientes_edtCodigo),
    "","","","","","","","",""),frmCadClientes_edtCodigo, 
    frmCadClientes_edtDescricao)) {
    frmCadClientes_InformaLimpaDados(NULL, 0, FALSE);
    frmCadClientes_HabilitaDados(FALSE);	
  }
}

void on_frmCadClientes_btnLimpar_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmCadastros_btnLimparClick(frmCadClientes_edtCodigo, 
    frmCadClientes_edtDescricao);
  frmCadClientes_InformaLimpaDados(NULL, 0, FALSE);
  frmCadClientes_HabilitaDados(FALSE);	
}

void on_frmCadClientes_destroy(GtkObject *object, gpointer user_data) {
  gtk_widget_set_sensitive(frmPrincipal_tbClientes, TRUE);  
  gtk_widget_set_sensitive(frmPrincipal_mnuCadClientes, TRUE);
  frmPrincipal_setaBarraStatus("");
}

void on_frmCadClientes_btnFechar_clicked(GtkButton *button, gpointer user_data)
{
  gtk_widget_destroy(frmCadClientes);
}

void frmCadClientes_InformaLimpaDados(LISTAMSTR *lstRegistros, 
  gint nLinhaRegistro, gboolean bInformar)
{ 
  GString *sDtNasc = g_string_new("");

  if (bInformar) {
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEmail), 
      Rotinas_retValorListaM(lstRegistros, 2, nLinhaRegistro));   
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtIdentidade), 
      Rotinas_retValorListaM(lstRegistros, 3, nLinhaRegistro));   
    if (strcmp(Rotinas_retValorListaM(
                  lstRegistros, 4, nLinhaRegistro), "M")==0)
      gtk_toggle_button_set_active(
        GTK_TOGGLE_BUTTON(frmCadClientes_rbMasculino), TRUE);
    else
      gtk_toggle_button_set_active(
        GTK_TOGGLE_BUTTON(frmCadClientes_rbFeminino), TRUE);
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtTelefone), 
      Rotinas_retValorListaM(lstRegistros, 5, nLinhaRegistro));   
    g_string_assign(sDtNasc, Rotinas_substr(
      Rotinas_retValorListaM(lstRegistros, 6, nLinhaRegistro), 1, 10));
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtDtNasc), sDtNasc->str);
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodEndereco), 
      Rotinas_retValorListaM(lstRegistros, 7, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtLogradouro), 
      Rotinas_retValorListaM(lstRegistros, 8, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtBairro), 
      Rotinas_retValorListaM(lstRegistros, 9, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCep), 
      Rotinas_retValorListaM(lstRegistros, 10, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCidade), 
      Rotinas_retValorListaM(lstRegistros, 11, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEstado), 
      Rotinas_retValorListaM(lstRegistros, 12, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodPais), 
      Rotinas_retValorListaM(lstRegistros, 13, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtPais), 
      Rotinas_retValorListaM(lstRegistros, 14, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodProfissao), 
      Rotinas_retValorListaM(lstRegistros, 15, nLinhaRegistro));  
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtProfissao), 
      Rotinas_retValorListaM(lstRegistros, 16, nLinhaRegistro));  
  } else {
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEmail),""); 
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtIdentidade),""); 
    gtk_toggle_button_set_active(
      GTK_TOGGLE_BUTTON(frmCadClientes_rbMasculino), TRUE);
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtTelefone),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtDtNasc),
      Rotinas_retDataHoraStr(TRUE, FALSE)); 
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodEndereco),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtLogradouro),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtBairro),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCep),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCidade),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEstado),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodPais),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtPais),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodProfissao),"");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtProfissao),"");
    nRegClientes = 0;
  }
} 

void frmCadClientes_HabilitaDados(gboolean bHabilita) {
  gtk_widget_set_sensitive(frmCadClientes_edtEmail, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_edtIdentidade, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_grpSexo, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_edtTelefone, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_edtDtNasc, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_grpEndereco, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_edtCodPais, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_btnPPais, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_edtCodProfissao, bHabilita);
  gtk_widget_set_sensitive(frmCadClientes_btnPProfissao, bHabilita);
}

gboolean on_frmCadClientes_edtDtNasc_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sDtNasc;
  sDtNasc = Rotinas_retTexto(frmCadClientes_edtDtNasc);
  if (strlen(sDtNasc) > 0) {    
  	if (Rotinas_validaDataHora(sDtNasc, TRUE)==FALSE) {      
      Rotinas_MsgDlg(STR_DATINV, GTK_MESSAGE_ERROR);
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtDtNasc), 
        Rotinas_retDataHoraStr(TRUE,FALSE));
      gtk_widget_grab_focus(frmCadClientes_edtDtNasc);
  	}
  }
  return FALSE;
}

gboolean on_frmCadClientes_edtCodEndereco_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data)
{
  G_CONST_RETURN gchar *sLogradouro, *sCodEndereco;
  LISTAMSTR ConsCampo;

  sCodEndereco = Rotinas_retTexto(frmCadClientes_edtCodEndereco);
  if (strlen(sCodEndereco) > 0) {
    sLogradouro = Rotinas_ConsultaCampoDesc(&ConsCampo, sCodEndereco, TRUE,
      ConsSQL_Endereco('S',sCodEndereco,"","","","",""),STR_ENDNENC);
    if (strlen(sLogradouro) > 0) {
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtLogradouro), sLogradouro);
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtBairro), 
        Rotinas_retValorListaM(&ConsCampo, 2, 0));   
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCep), 
        Rotinas_retValorListaM(&ConsCampo, 3, 0));   
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCidade), 
        Rotinas_retValorListaM(&ConsCampo, 4, 0));   
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEstado), 
        Rotinas_retValorListaM(&ConsCampo, 5, 0));
    } else {
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtLogradouro), "");
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtBairro), "");
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCep), "");
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCidade), "");
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEstado), "");
      gtk_widget_grab_focus(frmCadClientes_edtCodEndereco);
    }
  } else {
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtLogradouro), "");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtBairro), "");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCep), "");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCidade), "");
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtEstado), "");
  }
  return FALSE;
}

void on_frmCadClientes_btnPEndereco_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmConEnderecos = frmConEnderecos_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConEnderecos));
  gtk_widget_destroy(frmConEnderecos);
  gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodEndereco), 
    Rotinas_sCodigoSelecionado->str);
  on_frmCadClientes_edtCodEndereco_focus_out_event(NULL, NULL, NULL);
}

gboolean on_frmCadClientes_edtCodPais_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodPais, *sPais;
  LISTAMSTR ConsCampo;

  sCodPais = Rotinas_retTexto(frmCadClientes_edtCodPais);
  if (strlen(sCodPais) > 0) {
    sPais = Rotinas_ConsultaCampoDesc(&ConsCampo, sCodPais, FALSE,
      ConsSQL_Pais('S',sCodPais,""),STR_PAISNENC);    
    if (strlen(sPais) > 0)
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtPais), sPais);
    else {
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodPais), "");
      gtk_widget_grab_focus(frmCadClientes_edtCodPais);
    }
  } else
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtPais), "");
  
  return FALSE;
}

void on_frmCadClientes_btnPPais_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmConPaises = frmConPaises_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConPaises));
  gtk_widget_destroy(frmConPaises);
  gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodPais), 
    Rotinas_sCodigoSelecionado->str);
  on_frmCadClientes_edtCodPais_focus_out_event(NULL, NULL, NULL);
}

gboolean on_frmCadClientes_edtCodProfissao_focus_out_event(GtkWidget *widget,
			      GdkEventFocus *event, gpointer user_data) {
  G_CONST_RETURN gchar *sCodProfissao, *sProfissao;
  LISTAMSTR ConsCampo;

  sCodProfissao = Rotinas_retTexto(frmCadClientes_edtCodProfissao);
  if (strlen(sCodProfissao) > 0) {
    sProfissao = Rotinas_ConsultaCampoDesc(&ConsCampo, sCodProfissao, TRUE,
      ConsSQL_Profissao('S',sCodProfissao,""),STR_PROFNENC);    
    if (strlen(sProfissao) > 0)
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtProfissao), sProfissao);
    else {
      gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodProfissao), "");
      gtk_widget_grab_focus(frmCadClientes_edtCodProfissao);
    }
  } else
    gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtProfissao), "");

  return FALSE;
}

void on_frmCadClientes_btnPProfissao_clicked(GtkButton *button, 
                                         gpointer user_data) {
  frmConProfissoes = frmConProfissoes_Criar();
	gtk_dialog_run(GTK_DIALOG(frmConProfissoes));
  gtk_widget_destroy(frmConProfissoes);
  gtk_entry_set_text(GTK_ENTRY(frmCadClientes_edtCodProfissao), 
    Rotinas_sCodigoSelecionado->str);
  on_frmCadClientes_edtCodProfissao_focus_out_event(NULL, NULL, NULL);
}
