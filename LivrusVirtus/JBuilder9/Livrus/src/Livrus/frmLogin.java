package Livrus;

import java.awt.*;
import java.sql.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class frmLogin extends JDialog {
  public static frmLogin fLogin;
  boolean bFecharOuTerminar;
  Statement Consulta;

  ImageIcon image1;
  BevelBorder borda = new BevelBorder(BevelBorder.RAISED);
  boolean bcateg = false;
  TitledBorder titledBorder1;
  TitledBorder titledBorder2;
  JPanel jPanel1 = new JPanel();
  JPanel jPanel2 = new JPanel();
  JPanel jPanel3 = new JPanel();
  JButton btnCancelar = new JButton();
  JButton btnLogin = new JButton();
  BorderLayout borderLayout2 = new BorderLayout();
  GridLayout gridLayout1 = new GridLayout();
  JPanel jPanel5 = new JPanel();
  JLabel jLabel1 = new JLabel();
  JLabel labLogin = new JLabel();
  JTextField edtLogin = new JTextField();
  JPanel jPanel4 = new JPanel();
  JPasswordField edtSenha = new JPasswordField();
  JLabel labSenha = new JLabel();
  GridBagLayout gridBagLayout1 = new GridBagLayout();
  JLabel labBitmap = new JLabel();
  Border border1;
  FlowLayout flowLayout1 = new FlowLayout();

  public frmLogin(Frame frame, String title, boolean modal) {
    super(frame, title, modal);
    enableEvents(AWTEvent.WINDOW_EVENT_MASK);
    try  {
      jbInit();
      pack();
    }
    catch (Exception ex) {
      ex.printStackTrace();
    }
  }

  public frmLogin() {
    this(null, "Login do Sistema", true);
  }

  void jbInit() throws Exception {
    image1 = new ImageIcon(getClass().getResource("Login.gif"));
    titledBorder1 = new TitledBorder("");
    titledBorder2 = new TitledBorder("");
    this.setModal(true);
    setResizable(false);
    this.setTitle("Login do Sistema");
    this.addWindowListener(new java.awt.event.WindowAdapter() {
      public void windowOpened(WindowEvent e) {
        this_windowOpened(e);
      }
    });
    jPanel3.setEnabled(true);
    jPanel3.setRequestFocusEnabled(true);
    jPanel3.setLayout(flowLayout1);
    btnCancelar.setMargin(new Insets(2, 18, 2, 18));
    btnCancelar.setMnemonic('C');
    btnCancelar.setText("Cancelar");
    btnCancelar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnCancelar_actionPerformed(e);
      }
    });
    btnLogin.setAlignmentX((float) 0.0);
    btnLogin.setActionCommand("Login");
    btnLogin.setHorizontalTextPosition(SwingConstants.CENTER);
    btnLogin.setMargin(new Insets(2, 22, 2, 22));
    btnLogin.setMnemonic('L');
    btnLogin.setText("Login");
    btnLogin.addActionListener(new ActionListener(this));
    btnLogin.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnLogin_actionPerformed(e);
      }
    });
    jPanel1.setLayout(borderLayout2);
    jPanel2.setLayout(gridLayout1);
    gridLayout1.setColumns(2);
    gridLayout1.setHgap(6);
    gridLayout1.setRows(1);
    gridLayout1.setVgap(6);
    jPanel4.setLayout(gridBagLayout1);
    edtSenha.setText("");
    labSenha.setText("Senha:");
    edtLogin.setText("");
    labLogin.setText("Login:");
    labBitmap.setIcon(image1);
    labBitmap.setText("");
    jPanel1.setMinimumSize(new Dimension(217, 148));
    jPanel1.setPreferredSize(new Dimension(217, 148));
    jPanel2.setMinimumSize(new Dimension(210, 112));
    jPanel2.setPreferredSize(new Dimension(210, 112));
    this.getContentPane().add(jPanel1, BorderLayout.CENTER);
    jPanel1.add(jPanel2,  BorderLayout.CENTER);
    jPanel2.add(jPanel5, null);
    jPanel5.add(jLabel1, null);
    jPanel5.add(labBitmap, null);
    jPanel2.add(jPanel4, null);
    jPanel4.add(labLogin, new GridBagConstraints(0, 0, 1, 1, 0.0, 0.0
     ,GridBagConstraints.WEST, GridBagConstraints.NONE,
     new Insets(5, 0, 1, 1), 27, 5));
    jPanel4.add(edtLogin, new GridBagConstraints(0, 1, 1, 1, 1.0, 0.0
     ,GridBagConstraints.WEST, GridBagConstraints.NONE,
     new Insets(6, 0, 0, 16), 80, 1));
    jPanel4.add(labSenha, new GridBagConstraints(0, 2, 1, 1, 0.0, 0.0
     ,GridBagConstraints.WEST, GridBagConstraints.NONE,
     new Insets(6, 0, 0, 0), 67, 0));
    jPanel4.add(edtSenha, new GridBagConstraints(0, 3, 1, 1, 1.0, 0.0
     ,GridBagConstraints.WEST, GridBagConstraints.NONE,
     new Insets(6, 0, 11, 0), 80, -1));
    jPanel1.add(jPanel3, BorderLayout.SOUTH);
    jPanel3.add(btnLogin, null);
    jPanel3.add(btnCancelar, null);

  }

  protected void processWindowEvent(WindowEvent e) {
    if (e.getID() == WindowEvent.WINDOW_CLOSING) {
      if (bFecharOuTerminar=false) {
        super.processWindowEvent(e);
        System.exit(0);
      }
    }
  }

  void btnCancelar_actionPerformed(ActionEvent e) {
    //bFecharOuTerminar=false;
    System.exit(0);
  }

  void btnLogin_actionPerformed(ActionEvent e) {

    if (RotinasGlobais.Rotinas.ConsultaDados(Consulta,
     ConsultasSQL.ConsSQL.Usuario('S',edtLogin.getText(),
        String.valueOf(edtSenha.getPassword()) ))) {
     RotinasGlobais.Rotinas.sUsuarioLogin=edtLogin.getText();
     RotinasGlobais.Rotinas.sUsuarioSenha=String.valueOf(edtSenha.getPassword());
       bFecharOuTerminar=true;
       dispose();
    } else
      JOptionPane.showMessageDialog(this,"Login ou senha incorretos!",
      "Livrus Virtus", JOptionPane.ERROR_MESSAGE);
  }

  void this_windowOpened(WindowEvent e) {
    bFecharOuTerminar=false;
  }

}

class ActionListener implements java.awt.event.ActionListener {
  frmLogin adaptee;

  ActionListener(frmLogin adaptee) {
    this.adaptee = adaptee;
  }
  public void actionPerformed(ActionEvent e) {
    adaptee.btnLogin_actionPerformed(e);
  }
}



