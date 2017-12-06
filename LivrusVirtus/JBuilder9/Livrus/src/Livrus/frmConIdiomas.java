package Livrus;

/**
 * <p>Title: Livrus Virtus</p>
 * <p>Description: Sistema integrante do projeto Livrus Virtus, versão programada no JBuilder 9 em Java</p>
 * <p>Copyright: Todos os direitos reservados para: Henrique F. de Souza</p>
 * <p>Company: </p>
 * @author Henrique F. de Souza
 * @version 1.0.0
 */

import java.awt.event.*;

public class frmConIdiomas extends frmConsultas {
  public static frmConIdiomas fConIdiomas;
  String[] colNomes={"Código","Idioma"};

  public frmConIdiomas() {
    try  {
      jbInit();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    this.setTitle("Consulta de Idiomas");
    labDescricao.setText("Idioma: ");
    this.addWindowListener(new java.awt.event.WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        this_windowClosing(e);
      }
      public void windowOpened(WindowEvent e) {
        this_windowOpened(e);
      }
    });

    btnLimpar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnLimpar_actionPerformed(e);
      }
    });
    btnPesquisar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPesquisar_actionPerformed(e);
      }
    });
    btnFechar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnFechar_actionPerformed(e);
      }
    });
  }

  void this_windowClosing(WindowEvent e) {
    super.this_windowClosing(e);

    frmPrincipal.fPrincipal.mnuConIdiomas.setEnabled(true);
  }

  void btnLimpar_actionPerformed(ActionEvent e) {
    LimparDados(ConsultasSQL.ConsSQL.Idioma('S',"0",""),colNomes);
  }

  void btnPesquisar_actionPerformed(ActionEvent e) {
    PesquisarDados(ConsultasSQL.ConsSQL.
    Idioma('S',"", edtDescricao.getText()),"Idioma não encontrado!",colNomes);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    super.btnFechar_actionPerformed(e);

    frmPrincipal.fPrincipal.mnuConIdiomas.setEnabled(true);
  }

  void this_windowOpened(WindowEvent e) {
    btnLimpar_actionPerformed(null);
  }

}