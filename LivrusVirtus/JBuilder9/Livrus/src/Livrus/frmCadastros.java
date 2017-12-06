package Livrus;

import java.sql.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.border.*;

public class frmCadastros extends JInternalFrame {
  ArrayList Registros;
  ArrayList Campos;
  int nLinhaRegistro;
  ResultSet Consulta;
  Statement Arquiva;

  Component cp;
  JPanel jPanel1 = new JPanel();
  JLabel labCodigo = new JLabel();
  JLabel labDescricao = new JLabel();
  BorderLayout borderLayout2 = new BorderLayout();
  JTextField edtCodigo = new JTextField();
  JTextField edtDescricao = new JTextField(30);
  JButton btnNovo = new JButton();
  TitledBorder titledBorder1;
  JButton btnExcluir = new JButton();
  FlowLayout flowLayout1 = new FlowLayout();
  JButton btnSalvar = new JButton();
  JPanel jPanel2 = new JPanel();
  JButton btnLimpar = new JButton();
  JButton btnFechar = new JButton();
  GridBagLayout gridBagLayout2 = new GridBagLayout();
  JPanel jPanel3 = new JPanel();
  JPanel jPanel5 = new JPanel();
  JButton btnAnterior = new JButton();
  GridBagLayout gridBagLayout1 = new GridBagLayout();
  JPanel jPanel4 = new JPanel();
  JButton btnPesquisar = new JButton();
  JButton btnProximo = new JButton();
  FlowLayout flowLayout2 = new FlowLayout();

  public frmCadastros() {
    try  {
      jbInit();

      Registros = new ArrayList();
      nLinhaRegistro = 0;
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    titledBorder1 = new TitledBorder("");
    this.setTitle("Cadastro de ");
    this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    this.setClosable(true);
    this.setIconifiable(true);
    this.setMaximizable(true);
    this.setSize(new Dimension(405, 178));
    this.addInternalFrameListener(new javax.swing.event.InternalFrameAdapter() {
      public void internalFrameClosing(InternalFrameEvent e) {
        this_internalFrameClosing(e);
      }
    });
    this.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
      public void mouseMoved(MouseEvent e) {
        this_mouseMoved(e);
      }
    });
    jPanel1.setBorder(null);
    edtCodigo.setText("");
    edtCodigo.setColumns(10);
    edtCodigo.setBounds(new Rectangle(12, 32, 123, 21));
    edtCodigo.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodigo_focusLost(e);
      }
    });
    edtDescricao.setBounds(new Rectangle(12, 74, 262, 21));
    btnNovo.setBounds(new Rectangle(154, 31, 82, 25));
    btnNovo.setPreferredSize(new Dimension(92, 25));
    btnNovo.setMnemonic('N');
    btnNovo.setText("Novo");
    btnNovo.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnNovo_actionPerformed(e);
      }
    });
    labCodigo.setText("Código: ");
    labCodigo.setBounds(new Rectangle(12, 10, 69, 19));
    labDescricao.setText("Descrição:");
    labDescricao.setBounds(new Rectangle(12, 56, 85, 16));
    jPanel1.setLayout(null);
    btnExcluir.setText("Excluir");
    btnExcluir.setEnabled(false);
    btnExcluir.setOpaque(true);
    btnExcluir.setHorizontalAlignment(SwingConstants.CENTER);
    btnExcluir.setMnemonic('E');
    flowLayout1.setAlignment(FlowLayout.RIGHT);
    flowLayout1.setHgap(0);
    flowLayout1.setVgap(0);
    btnSalvar.setText("Salvar");
    btnSalvar.setEnabled(false);
    btnSalvar.setMnemonic('S');
    jPanel2.setAlignmentX((float) 0.0);
    jPanel2.setAlignmentY((float) 0.0);
    jPanel2.setBorder(null);
    jPanel2.setPreferredSize(new Dimension(390, 40));
    jPanel2.setLayout(gridBagLayout2);
    btnLimpar.setMnemonic('L');
    btnLimpar.setText("Limpar");
    btnLimpar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnLimpar_actionPerformed(e);
      }
    });
    btnFechar.setText("Fechar");
    btnFechar.setMnemonic('F');
    btnFechar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnFechar_actionPerformed(e);
      }
    });
    jPanel3.setLayout(flowLayout1);
    btnAnterior.setEnabled(false);
    btnAnterior.setOpaque(true);
    btnAnterior.setMnemonic('A');
    btnAnterior.setText("Anterior");
    btnAnterior.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnAnterior_actionPerformed(e);
      }
    });
    jPanel4.setLayout(gridBagLayout1);
    jPanel4.setBorder(null);
    jPanel4.setMinimumSize(new Dimension(274, 36));
    jPanel4.setPreferredSize(new Dimension(114, 96));
    btnPesquisar.setOpaque(true);
    btnPesquisar.setMnemonic('P');
    btnPesquisar.setText("Pesquisar");
    btnProximo.setEnabled(false);
    btnProximo.setMnemonic('M');
    btnProximo.setText("Próximo");
    btnProximo.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnProximo_actionPerformed(e);
      }
    });
    jPanel5.setLayout(flowLayout2);
    flowLayout2.setAlignment(FlowLayout.RIGHT);
    flowLayout2.setHgap(0);
    flowLayout2.setVgap(0);
    jPanel5.setPreferredSize(new Dimension(114, 106));
    jPanel1.add(labDescricao, null);
    jPanel1.add(edtCodigo, null);
    jPanel1.add(edtDescricao, null);
    jPanel1.add(btnNovo, null);
    jPanel1.add(labCodigo, null);
    jPanel3.add(jPanel2, null);
    jPanel2.add(btnExcluir, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0,
      GridBagConstraints.EAST, GridBagConstraints.BOTH,
      new Insets(0, 5, 0, 0), 15, 0));
    jPanel2.add(btnSalvar, new GridBagConstraints(1, 0, 1, 1, 0.0, 0.0,
      GridBagConstraints.EAST, GridBagConstraints.BOTH,
      new Insets(0, 5, 0, 0), 15, 0));
    jPanel2.add(btnLimpar, new GridBagConstraints(2, 0, 1, 1, 0.0, 0.0,
      GridBagConstraints.EAST, GridBagConstraints.BOTH,
      new Insets(0, 5, 0, 0), 15, 0));
    jPanel2.add(btnFechar, new GridBagConstraints(3, 0, 1, 1, 0.0, 0.0,
      GridBagConstraints.EAST, GridBagConstraints.BOTH,
      new Insets(0, 5, 0, 0), 15, 0));
    jPanel5.add(jPanel4, null);
    jPanel4.add(btnPesquisar, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0,
      GridBagConstraints.CENTER, GridBagConstraints.BOTH,
      new Insets(0, 0, 5, 0), 0, 0));
    jPanel4.add(btnAnterior, new GridBagConstraints(0, 1, 1, 1, 0.0, 0.0,
      GridBagConstraints.CENTER, GridBagConstraints.BOTH,
      new Insets(0, 0, 5, 0), 0, 0));
    jPanel4.add(btnProximo, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0,
      GridBagConstraints.CENTER, GridBagConstraints.BOTH,
      new Insets(0, 0, 0, 0), 0, 0));

    this.getContentPane().add(jPanel1, BorderLayout.CENTER);
    this.getContentPane().add(jPanel5,  BorderLayout.EAST);
    this.getContentPane().add(jPanel3,  BorderLayout.SOUTH);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    this.dispose();
  }

  protected boolean ValidaDados(boolean bTodosDados)
  {
      return true;
  }

  protected void InformaLimpaDados(boolean bInformar)
  {
      if (bInformar) {
        Campos = (ArrayList)Registros.get(nLinhaRegistro);
        edtCodigo.setText(Campos.get(0).toString());
        edtDescricao.setText(Campos.get(1).toString());
      } else {
        edtCodigo.setText("");
        edtDescricao.setText("");
        edtCodigo.setEnabled(true);
        edtCodigo.requestFocus();
      }
  }

  protected void HabilitaDados(boolean bHabilita)
  {
     edtDescricao.setEnabled(bHabilita);
  }

  void btnNovo_actionPerformed(ActionEvent e) {
    btnSalvar.setEnabled(true);
    btnExcluir.setEnabled(false);
    btnPesquisar.setEnabled(false);
    btnAnterior.setEnabled(false);
    btnProximo.setEnabled(false);
    btnNovo.setEnabled(false);

    InformaLimpaDados(false);
    HabilitaDados(true);
  }

  protected void NovoDado(String sTextoSql)
  {
     if (RotinasGlobais.Rotinas.ConsultaDados(Registros, sTextoSql, 1)) {
            Campos = (ArrayList)Registros.get(0);
            edtCodigo.setText(Campos.get(0).toString());
            edtCodigo.setEnabled(false);
            edtDescricao.requestFocus();
     }
  }

  void btnLimpar_actionPerformed(ActionEvent e) {
    btnSalvar.setEnabled(false);
    btnExcluir.setEnabled(false);
    btnPesquisar.setEnabled(true);
    btnAnterior.setEnabled(false);
    btnProximo.setEnabled(false);
    btnNovo.setEnabled(true);

    InformaLimpaDados(false);
    HabilitaDados(false);
  }

  protected void ExcluirDados(String sTextoSql)
  {
     if (ValidaDados(false)) {

       if (JOptionPane.showConfirmDialog(this,"Certeza de excluir?",
          frmPrincipal.fPrincipal.getTitle(), JOptionPane.YES_NO_OPTION,
          JOptionPane.QUESTION_MESSAGE) == JOptionPane.YES_OPTION) {
              RotinasGlobais.Rotinas.AtualizaDados(Arquiva,sTextoSql);
              btnLimpar_actionPerformed(null);
           }
     }
  }

  protected void PesquisarDados(String sTextoSql, String sMensagemErro, int QtdCampos)
  {
      if (edtCodigo.getText().equals("")) {
        btnAnterior.setEnabled(true);
        btnProximo.setEnabled(true);
      }

      if (RotinasGlobais.Rotinas.ConsultaDados(Registros,sTextoSql,QtdCampos)) {
           nLinhaRegistro=0;
           InformaLimpaDados(true);
           HabilitaDados(true);

           btnSalvar.setEnabled(true);
           btnExcluir.setEnabled(true);
           btnPesquisar.setEnabled(false);
      } else
        JOptionPane.showMessageDialog(this,sMensagemErro,
        frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
        JOptionPane.INFORMATION_MESSAGE);

  }

  void btnAnterior_actionPerformed(ActionEvent e) {
    if (nLinhaRegistro > 0) {
        nLinhaRegistro=nLinhaRegistro - 1;
        InformaLimpaDados(true);
    }
  }

  void btnProximo_actionPerformed(ActionEvent e) {
    if (nLinhaRegistro < (Registros.size()-1)) {
        nLinhaRegistro=nLinhaRegistro + 1;
        InformaLimpaDados(true);
    }
  }

  protected void SalvarDados(String sTextoSql,String sTextoUpdate,
                             String sTextoInsert, boolean bLimparDados)
  {
    if (ValidaDados(true)) {
       if (RotinasGlobais.Rotinas.ConsultaDados(Arquiva,sTextoSql)) {
          RotinasGlobais.Rotinas.AtualizaDados(Arquiva,sTextoUpdate);
       } else {
          RotinasGlobais.Rotinas.AtualizaDados(Arquiva,sTextoInsert);
       }
       if (bLimparDados)
          btnLimpar_actionPerformed(null);
    }
  }

  void edtCodigo_focusLost(FocusEvent e) {
    if (edtCodigo.getText().equals("")==false) {
          if (RotinasGlobais.Rotinas.ValidaInteger(edtCodigo.getText())==false) {
            edtCodigo.setText("");
            edtCodigo.requestFocus();
          }
    }
  }

  void this_mouseMoved(MouseEvent e) {
    frmPrincipal.fPrincipal.statusBar2.setText(this.getTitle());
  }

  void this_internalFrameClosing(InternalFrameEvent e) {
    frmPrincipal.fPrincipal.statusBar2.setText("");
  }

}
