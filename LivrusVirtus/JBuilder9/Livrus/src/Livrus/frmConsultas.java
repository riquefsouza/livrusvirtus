package Livrus;

import java.awt.*;
import java.sql.*;
import java.util.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.table.*;


public class frmConsultas extends JDialog {
  ResultSet rsConsulta;
  Vector Linhas = new Vector();

  Component cp;
  JPanel jPanel1 = new JPanel();
  JPanel jPanel3 = new JPanel();
  JTextField edtDescricao = new JTextField();
  JLabel labDescricao = new JLabel();
  JButton btnPesquisar = new JButton();
  JScrollPane jScrollPane1 = new JScrollPane();
  JTable gridConsulta = new JTable();
  JPanel jPanel2 = new JPanel();
  JPanel jPanel4 = new JPanel();
  JLabel labRegistros = new JLabel();
  FlowLayout flowLayout1 = new FlowLayout();
  BorderLayout borderLayout1 = new BorderLayout();
  JPanel jPanel5 = new JPanel();
  JButton btnFechar = new JButton();
  JButton btnLimpar = new JButton();
  BorderLayout borderLayout2 = new BorderLayout();

  public frmConsultas() {
    enableEvents(AWTEvent.WINDOW_EVENT_MASK);
    try  {
      jbInit();
    }
    catch (Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    this.setModal(true);
    this.setSize(new Dimension(383, 264));
    this.addWindowListener(new java.awt.event.WindowAdapter() {
      public void windowClosing(WindowEvent e) {
        this_windowClosing(e);
      }
    });
    this.setTitle("Consulta de ");
    btnPesquisar.setText("Pesquisar");
    btnPesquisar.setBounds(new Rectangle(273, 23, 92, 25));
    btnPesquisar.setMaximumSize(new Dimension(92, 25));
    btnPesquisar.setMinimumSize(new Dimension(92, 25));
    btnPesquisar.setPreferredSize(new Dimension(92, 25));
    btnPesquisar.setMnemonic('P');
    edtDescricao.setPreferredSize(new Dimension(300, 19));
    edtDescricao.setText("");
    edtDescricao.setBounds(new Rectangle(8, 25, 261, 19));
    labDescricao.setText("Descri��o: ");
    labDescricao.setBounds(new Rectangle(10, 7, 92, 15));
    jPanel1.setBorder(null);
    jPanel1.setPreferredSize(new Dimension(458, 55));
    jPanel1.setLayout(null);
    jPanel3.setLayout(borderLayout1);
    jPanel4.setMinimumSize(new Dimension(80, 26));
    jPanel4.setPreferredSize(new Dimension(140, 35));
    jPanel4.setLayout(flowLayout1);
    jPanel2.setLayout(borderLayout2);
    jPanel2.setMinimumSize(new Dimension(1, 30));
    jPanel2.setPreferredSize(new Dimension(1, 35));
    labRegistros.setPreferredSize(new Dimension(110, 25));
    labRegistros.setHorizontalAlignment(SwingConstants.LEADING);
    labRegistros.setText("Registro 0 de 0 ");
    labRegistros.setVerticalAlignment(SwingConstants.CENTER);
    labRegistros.setVerticalTextPosition(SwingConstants.CENTER);
    jPanel3.setPreferredSize(new Dimension(141, 40));
    btnFechar.setText("Fechar");
    btnFechar.setBounds(new Rectangle(105, 5, 92, 25));
    btnFechar.setMaximumSize(new Dimension(92, 25));
    btnFechar.setMinimumSize(new Dimension(92, 25));
    btnFechar.setPreferredSize(new Dimension(92, 25));
    btnFechar.setHorizontalAlignment(SwingConstants.CENTER);
    btnFechar.setMnemonic('F');
    btnFechar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnFechar_actionPerformed(e);
      }
    });
    btnLimpar.setBounds(new Rectangle(8, 5, 92, 25));
    btnLimpar.setMaximumSize(new Dimension(92, 25));
    btnLimpar.setMinimumSize(new Dimension(92, 25));
    btnLimpar.setPreferredSize(new Dimension(92, 25));
    btnLimpar.setMnemonic('L');
    btnLimpar.setText("Limpar");
    jPanel5.setDebugGraphicsOptions(0);
    jPanel5.setMaximumSize(new Dimension(32767, 32767));
    jPanel5.setMinimumSize(new Dimension(205, 35));
    jPanel5.setPreferredSize(new Dimension(205, 35));
    jPanel5.setLayout(null);
    jPanel2.add(jPanel5,  BorderLayout.EAST);
    jPanel5.add(btnLimpar, null);
    jPanel5.add(btnFechar, null);
    jPanel3.add(jPanel4,  BorderLayout.WEST);
    jPanel4.add(labRegistros, null);
    jPanel3.add(jPanel2,  BorderLayout.CENTER);
    this.getContentPane().add(jPanel1, BorderLayout.NORTH);
    jPanel1.add(edtDescricao, null);
    jPanel1.add(labDescricao, null);
    jPanel1.add(btnPesquisar, null);
    this.getContentPane().add(jScrollPane1, BorderLayout.CENTER);
    this.getContentPane().add(jPanel3, BorderLayout.SOUTH);
    jScrollPane1.setBorder(null);
    jScrollPane1.getViewport().add(gridConsulta, null);
  }

  protected DefaultTableModel modeloTabela(ResultSet rsConsulta, String[] colNomes) {
    DefaultTableModel dtm = new DefaultTableModel();
    Vector ColunasNome = new Vector(colNomes.length);

    try {
      for(int coluna = 0; coluna < colNomes.length; coluna++) {
        ColunasNome.addElement(colNomes[coluna]);
      }

      Linhas.removeAllElements();

      while (rsConsulta.next()) {
       Vector novaLinha = new Vector();
         for(int coluna = 0; coluna < colNomes.length; coluna++) {
         novaLinha.addElement(rsConsulta.getObject(coluna+1));
       }
       Linhas.addElement(novaLinha);
      }
      dtm.setDataVector(Linhas,ColunasNome);

    } catch (SQLException se) {
    JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
                                  JOptionPane.ERROR_MESSAGE);
    }

    return dtm;
  }

  protected void MostraTabela(ResultSet rsConsulta, String[] colNomes) {
   DefaultTableModel dtm;

   dtm = modeloTabela(rsConsulta,colNomes);
   gridConsulta = new JTable(dtm);
   gridConsulta.setAutoResizeMode(JTable.AUTO_RESIZE_OFF);
   RotinasGlobais.Rotinas.acomodaColunas(gridConsulta, 2);
   RotinasGlobais.Rotinas.acomodaLinhas(gridConsulta, 0);

   gridConsulta.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
     public void mouseMoved(MouseEvent e) {
       gridConsulta_mouseMoved(e);
     }
   });
   gridConsulta.addMouseListener(new java.awt.event.MouseAdapter() {
     public void mouseClicked(MouseEvent e) {
       gridConsulta_mouseClicked(e);
     }
   });
   gridConsulta.addKeyListener(new java.awt.event.KeyAdapter() {
     public void keyReleased(KeyEvent e) {
       gridConsulta_keyReleased(e);
     }
   });
   jScrollPane1.getViewport().add(gridConsulta, null);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    this_windowClosing(null);
    this.dispose();
  }

  protected void LimparDados(String sTextoSql, String[] colNomes)
  {
    labRegistros.setText("Registro 0 de 0");
    rsConsulta = RotinasGlobais.Rotinas.ConsultaDados(sTextoSql);
    MostraTabela(rsConsulta,colNomes);
    btnPesquisar.setEnabled(true);
    edtDescricao.setText("");
    edtDescricao.requestFocus();
  }

  protected boolean PesquisarDados(String sTextoSql, String sMensagemErro,
                                   String[] colNomes)
  {
    rsConsulta = RotinasGlobais.Rotinas.ConsultaDados(sTextoSql);
    if (rsConsulta!=null) {
           MostraTabela(rsConsulta,colNomes);
           labRegistros.setText("Registro 0 de "+gridConsulta.getRowCount());
           btnPesquisar.setEnabled(false);
           return true;
    } else {
          JOptionPane.showMessageDialog(this,sMensagemErro,
          frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
          JOptionPane.ERROR_MESSAGE);
          return false;
    }
  }

  void gridConsulta_mouseMoved(MouseEvent e) {
    frmPrincipal.fPrincipal.statusBar2.setText(this.getTitle());
  }

  void this_windowClosing(WindowEvent e) {
      if (gridConsulta.getSelectedRowCount() > 0) {
          RotinasGlobais.Rotinas.sCodigoSelecionado =
          gridConsulta.getValueAt(gridConsulta.getSelectedRow(), 0).toString();
      }
      frmPrincipal.fPrincipal.statusBar2.setText("");

  }

  void gridConsulta_mouseClicked(MouseEvent e) {
    labRegistros.setText("Registros "+(gridConsulta.getSelectedRow()+1)+
                         " de "+gridConsulta.getRowCount());
  }

  void gridConsulta_keyReleased(KeyEvent e) {
    gridConsulta_mouseClicked(null);
  }

}

