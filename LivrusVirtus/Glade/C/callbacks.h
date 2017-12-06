#include <gtk/gtk.h>


void on_mnuCadAssuntos_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadAutores_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadEditoras_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadEnderecos_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadIdiomas_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadPaises_activate (GtkMenuItem * menuitem, gpointer user_data);

void
on_mnuCadProfissoes_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadClientes_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuCadLivros_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConAssuntos_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConAutores_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConEditoras_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConEnderecos_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConIdiomas_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConPaises_activate (GtkMenuItem * menuitem, gpointer user_data);

void
on_mnuConProfissoes_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConClientes_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuConLivros_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuVendas_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuVenderLivros_activate (GtkMenuItem * menuitem, gpointer user_data);

void
on_mnuVendasRealizadas_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuJanelas_activate (GtkMenuItem * menuitem, gpointer user_data);

void
on_mnuJanHorizontal_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuJanVertical_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuJanCascata_activate (GtkMenuItem * menuitem, gpointer user_data);

void
on_mnuJanOrganizarIcones_activate (GtkMenuItem * menuitem,
				   gpointer user_data);

void on_mnuAlterarsenha_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuSobre_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_mnuSair_activate (GtkMenuItem * menuitem, gpointer user_data);

void on_frmPrincipal_show (GtkWidget * widget, gpointer user_data);

void on_frmPrincipal_destroy (GtkObject * object, gpointer user_data);

void on_tbClientes_clicked (GtkToolButton * toolbutton, gpointer user_data);

void on_tbLivros_clicked (GtkToolButton * toolbutton, gpointer user_data);

void on_tbVendas_clicked (GtkToolButton * toolbutton, gpointer user_data);

void on_tbSobre_clicked (GtkToolButton * toolbutton, gpointer user_data);

void on_tbSair_clicked (GtkToolButton * toolbutton, gpointer user_data);

void on_frmCadastros_show (GtkWidget * widget, gpointer user_data);

void on_frmCadastros_destroy (GtkObject * object, gpointer user_data);

gboolean
on_edtCodigo_focus_out_event (GtkWidget * widget,
			      GdkEventFocus * event, gpointer user_data);

void on_btnPesquisar_clicked (GtkButton * button, gpointer user_data);

void on_btnAnterior_clicked (GtkButton * button, gpointer user_data);

void on_btnProximo_clicked (GtkButton * button, gpointer user_data);

void on_btnSalvar_clicked (GtkButton * button, gpointer user_data);

void on_btnExcluir_clicked (GtkButton * button, gpointer user_data);

void on_btnLimpar_clicked (GtkButton * button, gpointer user_data);

void on_btnFechar_clicked (GtkButton * button, gpointer user_data);

void on_btnNovo_clicked (GtkButton * button, gpointer user_data);

void on_frmConsultas_show (GtkWidget * widget, gpointer user_data);

void on_frmConsultas_destroy (GtkObject * object, gpointer user_data);

void
on_gridConsulta_cursor_changed (GtkTreeView * treeview, gpointer user_data);

void on_frmLogin_show (GtkWidget * widget, gpointer user_data);

void on_frmLogin_destroy (GtkObject * object, gpointer user_data);

void on_btnLogin_clicked (GtkButton * button, gpointer user_data);

void on_btnCancelar_clicked (GtkButton * button, gpointer user_data);

void on_frmSplash_show (GtkWidget * widget, gpointer user_data);

void on_frmSplash_destroy (GtkObject * object, gpointer user_data);

void on_btnOk_clicked (GtkButton * button, gpointer user_data);

gboolean
on_lstAssuntos_button_press_event (GtkWidget * widget,
				   GdkEventButton * event,
				   gpointer user_data);

gboolean
on_lstAutores_button_press_event (GtkWidget * widget,
				  GdkEventButton * event, gpointer user_data);

gboolean
on_lstAssuntos_button_press_event (GtkWidget * widget,
				   GdkEventButton * event,
				   gpointer user_data);

gboolean
on_lstAutores_button_press_event (GtkWidget * widget,
				  GdkEventButton * event, gpointer user_data);

gboolean
on_frmVenderLivros_destroy_event (GtkWidget * widget,
				  GdkEvent * event, gpointer user_data);

gboolean
on_lstVendas_button_press_event (GtkWidget * widget,
				 GdkEventButton * event, gpointer user_data);

gboolean
on_frmVenderLivros_destroy_event (GtkWidget * widget,
				  GdkEvent * event, gpointer user_data);

gboolean
  on_frmVenderLivros_edtCPF_focus_out_event
  (GtkWidget * widget, GdkEventFocus * event, gpointer user_data);

gboolean
  on_frmVenderLivros_edtISBN_focus_out_event
  (GtkWidget * widget, GdkEventFocus * event, gpointer user_data);

gboolean
on_lstVendas_button_press_event (GtkWidget * widget,
				 GdkEventButton * event, gpointer user_data);

void on_btnVender_clicked (GtkButton * button, gpointer user_data);

void on_btnLimpar_clicked (GtkButton * button, gpointer user_data);

void on_btnFechar_clicked (GtkButton * button, gpointer user_data);

void
on_frmVenderLivros_btnPCliente_clicked (GtkButton * button,
					gpointer user_data);

void
on_frmVenderLivros_btnAdLivros_clicked (GtkButton * button,
					gpointer user_data);

void
on_frmVenderLivros_btnPLivro_clicked (GtkButton * button, gpointer user_data);

gboolean
on_frmConVendas_destroy_event (GtkWidget * widget,
			       GdkEvent * event, gpointer user_data);

gboolean
on_frmConVendas_edtCPF_focus_out_event (GtkWidget * widget,
					GdkEventFocus * event,
					gpointer user_data);

gboolean
  on_frmConVendas_edtISBN_focus_out_event
  (GtkWidget * widget, GdkEventFocus * event, gpointer user_data);

void on_btnPCliente_clicked (GtkButton * button, gpointer user_data);

void on_btnPLivro_clicked (GtkButton * button, gpointer user_data);

void on_btnPesquisar_clicked (GtkButton * button, gpointer user_data);

gboolean
  on_frmConVendas_lstVendas_button_press_event
  (GtkWidget * widget, GdkEventButton * event, gpointer user_data);
