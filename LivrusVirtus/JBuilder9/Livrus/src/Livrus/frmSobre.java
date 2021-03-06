package Livrus;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class frmSobre extends JDialog {
  public static frmSobre fSobre;

  JPanel panel1 = new JPanel();
  BorderLayout borderLayout1 = new BorderLayout();
  JPanel jPanel1 = new JPanel();
  ImageIcon image1;
  JPanel jPanel3 = new JPanel();
  JPanel jPanel2 = new JPanel();
  JButton btnOk = new JButton();
  BorderLayout borderLayout2 = new BorderLayout();
  JPanel jPanel4 = new JPanel();
  JTextArea jTextArea1 = new JTextArea();
  JLabel jLabel6 = new JLabel();
  JLabel jLabel4 = new JLabel();

  public frmSobre(Frame frame, String title, boolean modal) {
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


  public frmSobre() {
    this(null, "Sobre o Sistema", true);
  }

  void jbInit() throws Exception {
    image1 = new ImageIcon(getClass().getResource("LivrusVirtus.gif"));
    setResizable(false);
    this.addWindowListener(new java.awt.event.WindowAdapter() {
      public void windowOpened(WindowEvent e) {
        this_windowOpened(e);
      }
    });
    panel1.setLayout(borderLayout1);
    panel1.setBorder(null);
    panel1.setPreferredSize(new Dimension(349, 264));
    panel1.setSize(new Dimension(415, 196));
    jPanel1.setPreferredSize(new Dimension(415, 156));
    jPanel1.setLayout(borderLayout2);
    jPanel3.setLayout(null);
    btnOk.setText("Ok");
    btnOk.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnOk_actionPerformed(e);
      }
    });
    btnOk.setMargin(new Insets(2, 25, 2, 25));
    btnOk.setMnemonic('O');
    jPanel4.setBorder(BorderFactory.createEtchedBorder());
    jPanel4.setBounds(new Rectangle(10, 10, 323, 204));
    jPanel3.setBorder(null);
    jTextArea1.setBackground(UIManager.getColor("InternalFrame.borderColor"));
    jTextArea1.setEnabled(true);
    jTextArea1.setFont(new java.awt.Font("Dialog", 1, 12));
    jTextArea1.setPreferredSize(new Dimension(310, 86));
    jTextArea1.setEditable(false);
    jTextArea1.setMargin(new Insets(0, 10, 0, 0));
    jTextArea1.setText("Todos os direitos reservados para: \n"+
    "Henrique F. de Souza \n\n" +
    "Sistema integrante do projeto Livrus Virtus,\n"+
    "vers�o programada no JBuilder 9.0 em Java");
    jTextArea1.setLineWrap(true);
    jTextArea1.setRows(0);
    jTextArea1.setWrapStyleWord(false);
    jLabel6.setPreferredSize(new Dimension(310, 16));
    jLabel6.setHorizontalAlignment(SwingConstants.RIGHT);
    jLabel6.setText("Vers�o: 1.0.0");
    jLabel4.setIcon(image1);
    getContentPane().add(panel1);
    panel1.add(jPanel1, BorderLayout.CENTER);
    jPanel1.add(jPanel3, BorderLayout.CENTER);
    jPanel3.add(jPanel4, null);
    jPanel1.add(jPanel2,  BorderLayout.SOUTH);
    jPanel2.add(btnOk, null);
    jPanel4.add(jLabel4, null);
    jPanel4.add(jLabel6, null);
    jPanel4.add(jTextArea1, null);
  }

  protected void processWindowEvent(WindowEvent e) {
  if (e.getID() == WindowEvent.WINDOW_CLOSING) {
    dispose();
  }
   super.processWindowEvent(e);
  }

  void btnOk_actionPerformed(ActionEvent e) {
    dispose();
  }

  void this_windowOpened(WindowEvent e) {
      RotinasGlobais.Rotinas.CentralizaDlg(this);
  }

}


