package Livrus;

import java.sql.*;
import java.util.*;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

/**
 * <p>Title: Livrus Virtus</p>
 * <p>Description: Sistema integrante do projeto Livrus Virtus, vers�o
 * programada no JBuilder 9 em Java</p>
 * <p>Copyright: Todos os direitos reservados para: Henrique F. de Souza</p>
 * <p>Company: </p>
 * @author Henrique F. de Souza
 * @version 1.0.0
 */

public class frmVenderLivros extends JInternalFrame {
  public static frmVenderLivros fVenderLivros;
  Statement Arquiva;
  ResultSet ConsTotal, ConsCampo;

  JPanel jPanel1 = new JPanel();
  JTextField edtCodigo = new JTextField();
  JButton btnVender = new JButton();
  JLabel labCPF = new JLabel();
  JPanel jPanel2 = new JPanel();
  JButton btnLimpar = new JButton();
  JPanel jPanel5 = new JPanel();
  JButton btnFechar = new JButton();
  JLabel labCodigo = new JLabel();
  JTextField edtCPF = new JTextField(30);
  BorderLayout borderLayout1 = new BorderLayout();
  JLabel labEdicao1 = new JLabel();
  JLabel labEdicao2 = new JLabel();
  JLabel labDtVenda = new JLabel();
  JLabel labISBN = new JLabel();
  JTextField edtLivro = new JTextField();
  JTextField edtISBN = new JTextField();
  JLabel labCliente = new JLabel();
  JTextField edtDtVenda = new JTextField();
  JLabel labLivro = new JLabel();
  JTextField edtCliente = new JTextField();
  JButton btnPCliente = new JButton();
  JButton btnPLivro = new JButton();
  JLabel labPrecoTotal = new JLabel();
  JTextField edtPrecoTotal = new JTextField();
  JScrollPane jScrollPane1 = new JScrollPane();
  JList lstLivros = new JList();
  Vector slLivros = new Vector();
  Vector slISBNs = new Vector();
  Vector slPrecos = new Vector();
  Vector slQtdEstoque = new Vector();
  float nPrecoTotal;
  JButton btnAdLivros = new JButton();

  public frmVenderLivros() {
    try {
      jbInit();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }
  private void jbInit() throws Exception {
    this.setTitle("Vender Livros");
    this.setSize(new Dimension(480, 334));
    this.addInternalFrameListener(new javax.swing.event.InternalFrameAdapter() {
      public void internalFrameClosing(InternalFrameEvent e) {
        this_internalFrameClosing(e);
      }
      public void internalFrameOpened(InternalFrameEvent e) {
        this_internalFrameOpened(e);
      }
    });
    this.setDefaultCloseOperation(WindowConstants.DISPOSE_ON_CLOSE);
    this.setClosable(true);
    this.setIconifiable(true);
    this.setMaximizable(true);
    this.addMouseMotionListener(new java.awt.event.MouseMotionAdapter() {
      public void mouseMoved(MouseEvent e) {
        this_mouseMoved(e);
      }
    });
    jPanel1.setLayout(null);
    jPanel1.setBorder(null);
    jPanel1.setPreferredSize(new Dimension(1, 150));
    btnVender.setText("Vender");
    btnVender.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnVender_actionPerformed(e);
      }
    });
    btnVender.setBounds(new Rectangle(0, 37, 75, 25));
    btnVender.setEnabled(true);
    btnVender.setPreferredSize(new Dimension(75, 25));
    btnVender.setMnemonic('V');
    labCPF.setText("CPF:");
    labCPF.setBounds(new Rectangle(6, 56, 85, 16));
    jPanel2.setBorder(null);
    jPanel2.setPreferredSize(new Dimension(239, 70));
    jPanel2.setLayout(borderLayout1);
    btnLimpar.setBounds(new Rectangle(80, 37, 75, 25));
    btnLimpar.setPreferredSize(new Dimension(75, 25));
    btnLimpar.setHorizontalAlignment(SwingConstants.CENTER);
    btnLimpar.setMnemonic('L');
    btnLimpar.setText("Limpar");
    btnLimpar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnLimpar_actionPerformed(e);
      }
    });
    btnFechar.setText("Fechar");
    btnFechar.setBounds(new Rectangle(160, 37, 75, 25));
    btnFechar.setPreferredSize(new Dimension(75, 25));
    btnFechar.setMnemonic('F');
    btnFechar.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnFechar_actionPerformed(e);
      }
    });
    labCodigo.setText("C�digo: ");
    labCodigo.setBounds(new Rectangle(162, 196, 69, 19));
    edtCPF.setEnabled(true);
    edtCPF.setBounds(new Rectangle(8, 74, 131, 21));
    edtCPF.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCPF_focusLost(e);
      }
    });
    edtISBN.setColumns(10);
    edtISBN.setBounds(new Rectangle(8, 115, 131, 21));
    edtISBN.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtISBN_focusLost(e);
      }
    });
    edtLivro.setEnabled(false);
    edtLivro.setBounds(new Rectangle(142, 115, 270, 21));
    btnPLivro.setBounds(new Rectangle(440, 115, 21, 21));
    btnPLivro.setEnabled(true);
    btnPLivro.setText("...");
    btnPLivro.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPLivro_actionPerformed(e);
      }
    });
    btnPCliente.setBounds(new Rectangle(444, 74, 21, 21));
    btnPCliente.setEnabled(false);
    labDtVenda.setText("Data/Hora Venda:");
    labDtVenda.setBounds(new Rectangle(6, 13, 102, 16));
    btnPCliente.setBounds(new Rectangle(440, 74, 21, 21));
    btnPCliente.setEnabled(true);
    btnPCliente.setText("...");
    btnPCliente.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPCliente_actionPerformed(e);
      }
    });
    labISBN.setText("ISBN:");
    labISBN.setBounds(new Rectangle(8, 98, 82, 16));
    edtISBN.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtISBN_focusLost(e);
      }
    });
    labCliente.setText("Cliente:");
    labCliente.setBounds(new Rectangle(140, 56, 58, 15));
    edtDtVenda.setEnabled(false);
    edtDtVenda.setBounds(new Rectangle(6, 32, 131, 21));
    labLivro.setBounds(new Rectangle(140, 98, 58, 15));
    labLivro.setText("Livro:");
    edtCliente.setBounds(new Rectangle(142, 74, 295, 21));
    edtCliente.setEnabled(false);
    jPanel5.setLayout(null);
    jPanel5.setMinimumSize(new Dimension(240, 10));
    jPanel5.setPreferredSize(new Dimension(240, 10));
    labPrecoTotal.setText("Pre�o Total:");
    labPrecoTotal.setBounds(new Rectangle(34, 10, 72, 15));
    edtPrecoTotal.setEnabled(false);
    edtPrecoTotal.setText("");
    edtPrecoTotal.setBounds(new Rectangle(109, 10, 124, 21));
    jScrollPane1.setBounds(new Rectangle(7, 143, 453, 94));
    btnAdLivros.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnAdLivros_actionPerformed(e);
      }
    });
    btnAdLivros.setText("+");
    btnAdLivros.setMargin(new Insets(2, 5, 2, 4));
    btnAdLivros.setBounds(new Rectangle(414, 115, 21, 21));
    this.getContentPane().add(jPanel1,  BorderLayout.CENTER);
    jPanel1.add(labDtVenda, null);
    jPanel1.add(edtDtVenda, null);
    jPanel1.add(labCPF, null);
    jPanel1.add(edtCPF, null);
    jPanel1.add(labCliente, null);
    jPanel1.add(edtCliente, null);
    jPanel1.add(btnPCliente, null);
    jPanel1.add(labISBN, null);
    jPanel1.add(edtISBN, null);
    jPanel1.add(labLivro, null);
    jPanel1.add(edtLivro, null);
    jPanel1.add(btnAdLivros, null);
    jPanel1.add(btnPLivro, null);
    jPanel1.add(jScrollPane1, null);
    jScrollPane1.getViewport().add(lstLivros, null);
    this.getContentPane().add(jPanel2,  BorderLayout.SOUTH);
    jPanel2.add(jPanel5, BorderLayout.EAST);
    jPanel5.add(labPrecoTotal, null);
    jPanel5.add(edtPrecoTotal, null);
    jPanel5.add(btnVender, null);
    jPanel5.add(btnLimpar, null);
    jPanel5.add(btnFechar, null);
  }

  void this_internalFrameOpened(InternalFrameEvent e) {
    nPrecoTotal=0;
    edtDtVenda.setText(RotinasGlobais.Rotinas.retDataStr(new java.util.Date(),
        "dd/MM/yyyy hh:mm:ss"));
  }

  private void LimpaDados() {
    edtDtVenda.setText(RotinasGlobais.Rotinas.retDataStr(new java.util.Date(),
        "dd/MM/yyyy hh:mm:ss"));
    edtCPF.setText("");
    edtCliente.setText("");
    edtISBN.setText("");
    edtLivro.setText("");
    lstLivros.removeAll();
    slLivros.removeAllElements();
    slPrecos.removeAllElements();
    nPrecoTotal=0;
    edtPrecoTotal.setText("R$ 0,00");
    edtCPF.requestFocus();
  }
  private boolean ValidaDados()
  {
    if (RotinasGlobais.Rotinas.ValidaCampo(edtCPF.getText(),
            "CPF n�o informado!"))
      return false;
    if (lstLivros.getVisibleRowCount() == 0){
       JOptionPane.showMessageDialog(this,
       "Livro(s) para vender n�o informado(s)!",
       "Erro",JOptionPane.ERROR_MESSAGE);
       return false;
    }
    return true;
  }
  private boolean SalvaLista() {
    try {
       String sDtHrVenda = RotinasGlobais.Rotinas.FormataDataStr(
       edtDtVenda.getText(),"dd/MM/yyyy HH:mm:ss","yyyy-MM-dd HH:mm:ss:S");

       for (int nCont=0; nCont <= slLivros.size()-1; nCont++) {
         RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
         ConsultasSQL.ConsSQL.Venda('I',slLivros.get(nCont).toString(),
         edtCPF.getText(),sDtHrVenda,RotinasGlobais.Rotinas.
         VirgulaParaPonto(Double.toString(nPrecoTotal),false),""));

         int nQtdEstoque=new Integer(slQtdEstoque.get(nCont).toString()).intValue();
         nQtdEstoque=nQtdEstoque-1;
         RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
         ConsultasSQL.ConsSQL.Venda('U',slLivros.get(nCont).toString(),"","","",
         Integer.toString(nQtdEstoque)));
       }
      return true;
    } catch(Exception e) {
      JOptionPane.showMessageDialog(this,e.getMessage(),"Erro",
      JOptionPane.ERROR_MESSAGE);
      return false;
    }

  }

  void btnVender_actionPerformed(ActionEvent e) {
   if (ValidaDados()) {
      if (SalvaLista()) {
        JOptionPane.showMessageDialog(this,"Venda realizada com sucesso!",
        frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
        JOptionPane.INFORMATION_MESSAGE);
        LimpaDados();
      }
   }
  }
  void btnLimpar_actionPerformed(ActionEvent e) {
    LimpaDados();
  }
  void btnFechar_actionPerformed(ActionEvent e) {
    this_internalFrameClosing(null);
    this.dispose();
  }
  void edtCPF_focusLost(FocusEvent e) {
    try {
      if (edtCPF.getText().equals("")==false) {
        if (RotinasGlobais.Rotinas.ValidaCPF(edtCPF.getText())) {

          ConsCampo = RotinasGlobais.Rotinas.ConsultaCampoDesc(
                     ConsultasSQL.ConsSQL.Cliente('S',edtCPF.getText(),
                     "","","","","","","","",""),"Cliente n�o encontrado!");
          if (ConsCampo!=null) {
             edtCliente.setText(ConsCampo.getObject(2).toString());
          } else {
            edtCPF.setText("");
            edtCPF.requestFocus();
          }
        } else {
          JOptionPane.showMessageDialog(this,"CPF inv�lido!",
          frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
          JOptionPane.ERROR_MESSAGE);
          edtCPF.setText("");
          edtCliente.setText("");
        }
      } else
         edtCliente.setText("");
    } catch (SQLException se) {
      JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
      JOptionPane.ERROR_MESSAGE);
    }
  }
  void btnPCliente_actionPerformed(ActionEvent e) {
    frmConClientes pfConClientes = new frmConClientes();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConClientes);
    pfConClientes.show();
    edtCPF.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCPF_focusLost(null);
  }
  void edtISBN_focusLost(FocusEvent e) {
    try {
      if (edtISBN.getText().equals("")==false) {
        if (RotinasGlobais.Rotinas.ValidaISBN(edtISBN.getText())) {
          ConsCampo = RotinasGlobais.Rotinas.ConsultaCampoDesc(
              ConsultasSQL.ConsSQL.Livro('Q',edtISBN.getText(),
              "","","","","","","","",""),"Livro n�o encontrado!");
          if (ConsCampo!=null) {
           if (Integer.parseInt(ConsCampo.getObject(4).toString()) > 0) {
             edtLivro.setText(ConsCampo.getObject(2).toString());
             RotinasGlobais.Rotinas.sPreco=ConsCampo.getObject(3).toString();
           } else
             JOptionPane.showMessageDialog(this,"Livro n�o existe no estoque!",
             frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
             JOptionPane.ERROR_MESSAGE);
          } else {
            edtISBN.setText("");
            edtISBN.requestFocus();
          }
        } else {
          JOptionPane.showMessageDialog(this,"ISBN inv�lido!",
          frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
          JOptionPane.ERROR_MESSAGE);
          edtISBN.setText("");
          edtLivro.setText("");
        }
      } else
          edtLivro.setText("");
    } catch (SQLException se) {
      JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
      JOptionPane.ERROR_MESSAGE);
    }
  }
  void btnPLivro_actionPerformed(ActionEvent e) {
    frmConLivros pfConLivros = new frmConLivros();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConLivros);
    pfConLivros.show();
    edtISBN.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtISBN_focusLost(null);
  }

  void this_mouseMoved(MouseEvent e) {
    frmPrincipal.fPrincipal.statusBar2.setText(this.getTitle());
  }

  void this_internalFrameClosing(InternalFrameEvent e) {
    frmPrincipal.fPrincipal.tlbVender.setEnabled(true);
    frmPrincipal.fPrincipal.mnuVenderLivros.setEnabled(true);
    frmPrincipal.fPrincipal.statusBar2.setText("");
  }
  private void adicionaListaLivros(Vector sLivros) {
    lstLivros = new JList(sLivros);
    lstLivros.setSelectedIndex(0);
    lstLivros.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

    lstLivros.addMouseListener(new java.awt.event.MouseAdapter() {
      public void mouseClicked(MouseEvent e) {
        lstLivros_mouseClicked(e);
      }
    });
    redesenhaListaLivros();
  }
  private void redesenhaListaLivros() {
    jScrollPane1.getViewport().add(lstLivros, null);
    jPanel1.remove(jScrollPane1);
    jPanel1.add(jScrollPane1, null);
    jPanel1.validate();
  }
  void btnAdLivros_actionPerformed(ActionEvent e) {
    String sLivros;

    if (edtISBN.getText().equals("")==false) {
     sLivros=edtISBN.getText()+" - "+edtLivro.getText()+" - R$ "+
         RotinasGlobais.Rotinas.sPreco;
     if (slLivros.indexOf(sLivros)==-1) {
       slISBNs.addElement(edtISBN.getText());
       slPrecos.addElement(RotinasGlobais.Rotinas.sPreco);
       slQtdEstoque.addElement(RotinasGlobais.Rotinas.sQtdEstoque);
       slLivros.addElement(sLivros);
       nPrecoTotal=nPrecoTotal+Float.parseFloat(RotinasGlobais.Rotinas.sPreco);

       adicionaListaLivros(slLivros);
     }
     edtISBN.setText("");
     edtLivro.setText("");
     edtPrecoTotal.setText("R$ "+ RotinasGlobais.Rotinas.VirgulaParaPonto(
                           Float.toString(nPrecoTotal),true));
    }

  }
  void lstLivros_mouseClicked(MouseEvent e) {
    if (slLivros.size() > 0) {

      float nPreco=Float.parseFloat(slPrecos.get(
          lstLivros.getSelectedIndex()).toString());
      nPrecoTotal=nPrecoTotal-nPreco;
      edtPrecoTotal.setText("R$ "+Float.toString(nPrecoTotal));

      slISBNs.remove(lstLivros.getSelectedIndex());
      slPrecos.remove(lstLivros.getSelectedIndex());
      slQtdEstoque.remove(lstLivros.getSelectedIndex());
      slLivros.remove(lstLivros.getSelectedIndex());
    }

    redesenhaListaLivros();
  }





}