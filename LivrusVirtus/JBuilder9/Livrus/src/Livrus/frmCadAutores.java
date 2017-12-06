package Livrus;

import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;

/**
 * <p>Title: Livrus Virtus</p>
 * <p>Description: Sistema integrante do projeto Livrus Virtus, versão programada no JBuilder 9 em Java</p>
 * <p>Copyright: Todos os direitos reservados para: Henrique F. de Souza</p>
 * <p>Company: </p>
 * @author Henrique F. de Souza
 * @version 1.0.0
 */

public class frmCadAutores extends frmCadastros {
  public static frmCadAutores fCadAutores;

  public frmCadAutores() {
    try {
      jbInit();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    this.setTitle("Cadastro de Autores");
    this.labDescricao.setText("Autor: ");
    this.setPreferredSize(new Dimension(347, 164));
    btnNovo.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnNovo_actionPerformed(e);
      }
    });
    btnExcluir.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnExcluir_actionPerformed(e);
      }
    });
    btnPesquisar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPesquisar_actionPerformed(e);
      }
    });
    btnSalvar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnSalvar_actionPerformed(e);
      }
    });
    btnFechar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnFechar_actionPerformed(e);
      }
    });
    this.addInternalFrameListener(new javax.swing.event.InternalFrameAdapter() {
      public void internalFrameClosing(InternalFrameEvent e) {
        this_internalFrameClosing(e);
      }
    });
  }

  protected boolean ValidaDados(boolean bTodosDados)
  {
        super.ValidaDados(bTodosDados);

        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.getText(),
                "Código não informado!"))
          return false;
        if (bTodosDados) {
          if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.getText(),
                "Autor não informado!"))
                return false;
        }
        return true;
  }

  void btnNovo_actionPerformed(ActionEvent e) {
    super.btnNovo_actionPerformed(e);

    NovoDado(ConsultasSQL.ConsSQL.Autor('N',edtCodigo.getText(),""));
  }

  void btnExcluir_actionPerformed(ActionEvent e) {
    ExcluirDados(ConsultasSQL.ConsSQL.Autor('D',edtCodigo.getText(),""));
  }

  void btnPesquisar_actionPerformed(ActionEvent e) {
    PesquisarDados(ConsultasSQL.ConsSQL.Autor('S',edtCodigo.getText(),""),
    "Autor não encontrado!",2);
  }

  void btnSalvar_actionPerformed(ActionEvent e) {
    SalvarDados(ConsultasSQL.ConsSQL.Autor('S',edtCodigo.getText(),""),
    ConsultasSQL.ConsSQL.Autor('U',edtCodigo.getText(),edtDescricao.getText()),
    ConsultasSQL.ConsSQL.Autor('I',edtCodigo.getText(),edtDescricao.getText()),
    true);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    super.btnFechar_actionPerformed(e);

    this_internalFrameClosing(null);
  }

  void this_internalFrameClosing(InternalFrameEvent e) {
    super.this_internalFrameClosing(e);

    frmPrincipal.fPrincipal.mnuCadAutores.setEnabled(true);
  }

}