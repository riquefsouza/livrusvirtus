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

public class frmConAssuntos extends frmConsultas {
  public static frmConAssuntos fConAssuntos;
  String[] colNomes={"Código","Assunto"};

  public frmConAssuntos() {
    try  {
      jbInit();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    this.setTitle("Consulta de Assuntos");
    labDescricao.setText("Assunto: ");
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

    frmPrincipal.fPrincipal.mnuConAssuntos.setEnabled(true);
  }

  void btnLimpar_actionPerformed(ActionEvent e) {
    LimparDados(ConsultasSQL.ConsSQL.Assunto('S',"0",""),colNomes);
  }

  void btnPesquisar_actionPerformed(ActionEvent e) {
    PesquisarDados(ConsultasSQL.ConsSQL.
    Assunto('S',"", edtDescricao.getText()),"Assunto não encontrado!",colNomes);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    super.btnFechar_actionPerformed(e);

    frmPrincipal.fPrincipal.mnuConAssuntos.setEnabled(true);
  }

  void this_windowOpened(WindowEvent e) {
    btnLimpar_actionPerformed(null);
  }

}