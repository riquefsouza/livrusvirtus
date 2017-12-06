package Livrus;

import java.sql.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class frmCadClientes extends frmCadastros {
  public static frmCadClientes fCadClientes;
  JLabel labSexo = new JLabel();
  JButton btnPEndereco = new JButton();
  JLabel labTelefone = new JLabel();
  JLabel labIdentidade = new JLabel();
  JTextField edtProfissao = new JTextField();
  JLabel labLogradouro = new JLabel();
  JTextField edtCEP = new JTextField();
  JTextField edtPais = new JTextField();
  JButton btnPPais = new JButton();
  JTextField edtLogradouro = new JTextField();
  JTextField edtCidade = new JTextField();
  JTextField edtCodProfissao = new JTextField();
  JRadioButton rbMasculino = new JRadioButton();
  JLabel labProfissao = new JLabel();
  JTextField edtBairro = new JTextField();
  GridLayout gridLayout1 = new GridLayout();
  JLabel labPais = new JLabel();
  JLabel labEstado = new JLabel();
  JTextField edtIdentidade = new JTextField();
  JTextField edtCodEndereco = new JTextField();
  JTextField edtTelefone = new JTextField();
  JTextField edtEstado = new JTextField();
  JRadioButton rbFeminino = new JRadioButton();
  JLabel labDtNascimento = new JLabel();
  JLabel labCEP = new JLabel();
  JButton btnPProfissao = new JButton();
  JTextField edtDtNascimento = new JTextField(10);
  JPanel pnlSexo = new JPanel();
  JPanel pnlEndereco = new JPanel();
  JLabel labCidade = new JLabel();
  JLabel labEndereco = new JLabel();
  JLabel labEmail = new JLabel();
  JTextField edtEmail = new JTextField(20);
  JTextField edtCodPais = new JTextField();
  JLabel labBairro = new JLabel();
  String sSexo, sDtNascimento;

  public frmCadClientes() {
    try {
      jbInit();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    this.setSize(new Dimension(575, 503));
    edtDtNascimento.setBounds(new Rectangle(339, 161, 110, 21));
    edtDtNascimento.setText("");
    edtDtNascimento.setEnabled(false);
    edtDtNascimento.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtDtNascimento_focusLost(e);
      }
    });
    btnPProfissao.setText("...");
    btnPProfissao.setEnabled(false);
    btnPProfissao.setBounds(new Rectangle(328, 396, 21, 21));
    btnPProfissao.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPProfissao_actionPerformed(e);
      }
    });
    labCEP.setBounds(new Rectangle(8, 86, 54, 16));
    labCEP.setText("CEP:");
    labDtNascimento.setText("Dt. Nascimento:");
    labDtNascimento.setBounds(new Rectangle(338, 143, 90, 16));

    pnlSexo.setBorder(BorderFactory.createEtchedBorder());
    pnlSexo.setBounds(new Rectangle(11, 148, 201, 35));
    pnlSexo.setLayout(null);
    labSexo.setAlignmentY((float) 0.5);
    labSexo.setOpaque(true);
    labSexo.setPreferredSize(new Dimension(30, 15));
    labSexo.setText("Sexo");
    labSexo.setBounds(new Rectangle(20, 142, 32, 15));
    rbMasculino.setEnabled(false);
    rbMasculino.setSelected(false);
    rbMasculino.setText("Masculino");
    rbMasculino.setBounds(new Rectangle(2, 10, 98, 20));
    rbMasculino.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        rbMasculino_actionPerformed(e);
      }
    });
    rbFeminino.setEnabled(false);
    rbFeminino.setDoubleBuffered(false);
    rbFeminino.setText("Feminino");
    rbFeminino.setBounds(new Rectangle(100, 10, 98, 20));
    rbFeminino.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        rbFeminino_actionPerformed(e);
      }
    });
    edtEstado.setEnabled(false);
    edtEstado.setBounds(new Rectangle(290, 104, 142, 21));
    edtTelefone.setBounds(new Rectangle(224, 161, 110, 21));
    edtTelefone.setEnabled(false);
    edtCodEndereco.setBounds(new Rectangle(8, 15, 98, 21));
    edtCodEndereco.setColumns(10);
    edtCodEndereco.setText("");
    edtCodEndereco.setEnabled(false);
    edtCodEndereco.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodEndereco_focusLost(e);
      }
    });
    edtIdentidade.setBounds(new Rectangle(340, 116, 110, 21));
    labEstado.setText("Estado:");
    labEstado.setBounds(new Rectangle(292, 86, 75, 19));
    labPais.setText("Pa�s de origem:");
    labPais.setBounds(new Rectangle(12, 334, 90, 16));
    gridLayout1.setRows(1);
    gridLayout1.setHgap(0);
    gridLayout1.setColumns(2);
    edtBairro.setEnabled(false);
    edtBairro.setBounds(new Rectangle(290, 60, 142, 21));
    labProfissao.setBounds(new Rectangle(12, 378, 82, 16));
    labProfissao.setText("Profiss�o:");
    edtCodProfissao.setBounds(new Rectangle(12, 396, 80, 21));
    edtCodProfissao.setColumns(10);
    edtCodProfissao.setEnabled(false);
    edtCodProfissao.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodProfissao_focusLost(e);
      }
    });
    edtCidade.setEnabled(false);
    edtCidade.setBounds(new Rectangle(84, 104, 200, 21));
    edtLogradouro.setEnabled(false);
    edtLogradouro.setBounds(new Rectangle(8, 60, 276, 21));
    btnPPais.setEnabled(false);
    btnPPais.setBounds(new Rectangle(328, 352, 21, 21));
    btnPPais.setText("...");
    edtPais.setBounds(new Rectangle(96, 352, 228, 21));
    edtPais.setEnabled(false);
    btnPPais.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPPais_actionPerformed(e);
      }
    });
    edtCEP.setEnabled(false);
    edtCEP.setBounds(new Rectangle(8, 104, 72, 21));
    labLogradouro.setBounds(new Rectangle(8, 42, 85, 16));
    labLogradouro.setText("Logradouro:");
    edtProfissao.setBounds(new Rectangle(96, 396, 228, 21));
    edtProfissao.setEnabled(false);
    labIdentidade.setText("Identidade:");
    labIdentidade.setBounds(new Rectangle(340, 98, 69, 16));
    labTelefone.setBounds(new Rectangle(224, 143, 69, 16));
    labTelefone.setText("Telefone:");
    btnPEndereco.setText("...");
    btnPEndereco.setEnabled(false);
    btnPEndereco.setBounds(new Rectangle(111, 16, 21, 21));
    btnPEndereco.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPEndereco_actionPerformed(e);
      }
    });
    this.setTitle("Cadastro de Clientes");
    this.labCodigo.setText("CPF: ");
    this.labDescricao.setText("Nome: ");

    edtCodigo.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodigo_focusLost(e);
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
    pnlEndereco.setBorder(BorderFactory.createEtchedBorder());
    pnlEndereco.setBounds(new Rectangle(11, 195, 439, 131));
    pnlEndereco.setLayout(null);
    labCidade.setText("Cidade:");
    labCidade.setBounds(new Rectangle(84, 86, 85, 16));
    labEndereco.setOpaque(true);
    labEndereco.setText("Endere�o");
    labEndereco.setBounds(new Rectangle(19, 188, 60, 16));
    labEmail.setBounds(new Rectangle(12, 98, 47, 16));
    labEmail.setText("E-mail:");
    edtEmail.setEnabled(false);
    edtEmail.setColumns(30);
    edtEmail.setBounds(new Rectangle(12, 116, 320, 21));
    edtCodPais.setEnabled(false);
    edtCodPais.setColumns(10);
    edtCodPais.setBounds(new Rectangle(12, 352, 80, 21));
    edtCodPais.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodPais_focusLost(e);
      }
    });
    labBairro.setText("Bairro:");
    labBairro.setBounds(new Rectangle(290, 38, 69, 19));
    jPanel1.add(labEmail, null);
    jPanel1.add(edtEmail, null);
    jPanel1.add(labIdentidade, null);
    jPanel1.add(edtIdentidade, null);
    jPanel1.add(labSexo, null);
    jPanel1.add(pnlSexo, null);
    pnlSexo.add(rbMasculino, null);
    pnlSexo.add(rbFeminino, null);
    jPanel1.add(labTelefone, null);
    jPanel1.add(edtTelefone, null);
    jPanel1.add(labDtNascimento, null);
    jPanel1.add(edtDtNascimento, null);
    jPanel1.add(labEndereco, null);
    jPanel1.add(pnlEndereco, null);
    pnlEndereco.add(edtCodEndereco, null);
    pnlEndereco.add(btnPEndereco, null);
    pnlEndereco.add(labLogradouro, null);
    pnlEndereco.add(edtLogradouro, null);
    pnlEndereco.add(labBairro, null);
    pnlEndereco.add(edtBairro, null);
    pnlEndereco.add(labCEP, null);
    pnlEndereco.add(edtCEP, null);
    pnlEndereco.add(labCidade, null);
    pnlEndereco.add(edtCidade, null);
    pnlEndereco.add(labEstado, null);
    pnlEndereco.add(edtEstado, null);
    jPanel1.add(labPais, null);
    jPanel1.add(edtCodPais, null);
    jPanel1.add(edtPais, null);
    jPanel1.add(btnPPais, null);
    jPanel1.add(labProfissao, null);
    jPanel1.add(edtCodProfissao, null);
    jPanel1.add(edtProfissao, null);
    jPanel1.add(btnPProfissao, null);
  }

  protected boolean ValidaDados(boolean bTodosDados)
  {
        super.ValidaDados(bTodosDados);

        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.getText(),
                "CPF n�o informado!"))
          return false;
        if (bTodosDados) {
          if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.getText(),
                "Nome n�o informado!"))
                return false;
          if (RotinasGlobais.Rotinas.ValidaCampo(edtEmail.getText(),
                "E-mail n�o informado!"))
                return false;
          if (rbMasculino.isSelected()==false &&
              rbFeminino.isSelected()==false){
            JOptionPane.showMessageDialog(null,"Sexo n�o informado!","Erro",
                                          JOptionPane.ERROR_MESSAGE);
            return false;
          }
          if (RotinasGlobais.Rotinas.ValidaCampo(edtTelefone.getText(),
                "Telefone n�o informado!"))
                return false;
          if (RotinasGlobais.Rotinas.ValidaCampo(edtCodEndereco.getText(),
                "Endere�o n�o informado!"))
                return false;
          if (RotinasGlobais.Rotinas.ValidaCampo(edtCodPais.getText(),
                "Pa�s n�o informado!"))
                return false;
          if (RotinasGlobais.Rotinas.ValidaCampo(edtCodProfissao.getText(),
                "Profiss�o n�o informada!"))
                return false;

        }
        return true;
  }

  protected void InformaLimpaDados(boolean bInformar)
  {
    super.InformaLimpaDados(bInformar);

      if (bInformar) {
        edtEmail.setText(Campos.get(2).toString());
        edtIdentidade.setText(Campos.get(3).toString());
        if (Campos.get(4).toString().equals("M")) {
           rbMasculino.setSelected(true);
           rbFeminino.setSelected(false);
        } else {
          rbMasculino.setSelected(false);
          rbFeminino.setSelected(true);
        }
        edtTelefone.setText(Campos.get(5).toString());
        edtDtNascimento.setText(RotinasGlobais.Rotinas.FormataDataStr(
          Campos.get(6).toString(),"yyyy-MM-dd HH:mm:ss.S","dd/MM/yyyy"));
        edtCodEndereco.setText(Campos.get(7).toString());
        edtLogradouro.setText(Campos.get(8).toString());
        edtBairro.setText(Campos.get(9).toString());
        edtCEP.setText(Campos.get(10).toString());
        edtCidade.setText(Campos.get(11).toString());
        edtEstado.setText(Campos.get(12).toString());
        edtCodPais.setText(Campos.get(13).toString());
        edtPais.setText(Campos.get(14).toString());
        edtCodProfissao.setText(Campos.get(15).toString());
        edtProfissao.setText(Campos.get(16).toString());

      } else {
        edtEmail.setText("");
        edtIdentidade.setText("");
        rbMasculino.setSelected(false);
        rbFeminino.setSelected(false);
        edtTelefone.setText("");
        edtDtNascimento.setText(RotinasGlobais.Rotinas.retDataStr(
          new java.util.Date(),"dd/MM/yyyy"));
        edtCodEndereco.setText("");
        edtLogradouro.setText("");
        edtBairro.setText("");
        edtCEP.setText("");
        edtCidade.setText("");
        edtEstado.setText("");
        edtCodPais.setText("");
        edtPais.setText("");
        edtCodProfissao.setText("");
        edtProfissao.setText("");
      }
  }

  protected void HabilitaDados(boolean bHabilita)
  {
    super.HabilitaDados(bHabilita);

     edtEmail.setEnabled(bHabilita);
     edtIdentidade.setEnabled(bHabilita);
     rbMasculino.setEnabled(bHabilita);
     rbFeminino.setEnabled(bHabilita);
     edtTelefone.setEnabled(bHabilita);
     edtDtNascimento.setEnabled(bHabilita);
     edtCodEndereco.setEnabled(bHabilita);
     btnPEndereco.setEnabled(bHabilita);
     edtCodPais.setEnabled(bHabilita);
     btnPPais.setEnabled(bHabilita);
     edtCodProfissao.setEnabled(bHabilita);
     btnPProfissao.setEnabled(bHabilita);
  }

  void btnExcluir_actionPerformed(ActionEvent e) {
    ExcluirDados(ConsultasSQL.ConsSQL.Cliente('D',
    edtCodigo.getText(),"","","","","","","","",""));
  }

  void btnPesquisar_actionPerformed(ActionEvent e) {
    PesquisarDados(ConsultasSQL.ConsSQL.Cliente('S',edtCodigo.getText(),
    "","","","","","","","",""), "Cliente n�o encontrado!",17);
  }

  void btnSalvar_actionPerformed(ActionEvent e) {
      sDtNascimento = RotinasGlobais.Rotinas.FormataDataStr(
        edtDtNascimento.getText(),"dd/MM/yyyy","yyyy-MM-dd HH:mm:ss.S");

      if (rbMasculino.isSelected())
         sSexo="M";
      else
         sSexo="F";

      SalvarDados(ConsultasSQL.ConsSQL.Cliente('S',edtCodigo.getText(),
      "","","","","","","","",""),
      ConsultasSQL.ConsSQL.Cliente('U',edtCodigo.getText(),
      edtDescricao.getText(),edtEmail.getText(),edtIdentidade.getText(),sSexo,
      edtTelefone.getText(),sDtNascimento,
      edtCodEndereco.getText(),edtCodPais.getText(), edtCodProfissao.getText()),
      ConsultasSQL.ConsSQL.Cliente('I',edtCodigo.getText(),
      edtDescricao.getText(),edtEmail.getText(),edtIdentidade.getText(),sSexo,
      edtTelefone.getText(),sDtNascimento,
      edtCodEndereco.getText(),edtCodPais.getText(), edtCodProfissao.getText()),
      true);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    super.btnFechar_actionPerformed(e);

    this_internalFrameClosing(null);
  }

  void this_internalFrameClosing(InternalFrameEvent e) {
    super.this_internalFrameClosing(e);

    frmPrincipal.fPrincipal.tlbClientes.setEnabled(true);
    frmPrincipal.fPrincipal.mnuCadClientes.setEnabled(true);
  }

  void edtCodigo_focusLost(FocusEvent e) {
    if (edtCodigo.getText().equals("")==false) {
          if (RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.getText())==false) {
            JOptionPane.showMessageDialog(this,"CPF inv�lido!",
            frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
            JOptionPane.ERROR_MESSAGE);
            edtCodigo.setText("");
            edtCodigo.requestFocus();
          }
    }
  }

  void edtCodEndereco_focusLost(FocusEvent e) {
   try {
      if (edtCodEndereco.getText().equals("")==false) {
        Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
        edtCodEndereco.getText(),ConsultasSQL.ConsSQL.Endereco('S',
        edtCodEndereco.getText(),"","","","",""),"Endere�o n�o encontrado!");
        if (Consulta!=null) {
          edtLogradouro.setText(Consulta.getObject(2).toString());
          edtBairro.setText(Consulta.getObject(3).toString());
          edtCEP.setText(Consulta.getObject(4).toString());
          edtCidade.setText(Consulta.getObject(5).toString());
          edtEstado.setText(Consulta.getObject(6).toString());
        } else {
          edtCodEndereco.requestFocus();
          edtLogradouro.setText("");
          edtBairro.setText("");
          edtCEP.setText("");
          edtCidade.setText("");
          edtEstado.setText("");
        }
      } else {
          edtLogradouro.setText("");
          edtBairro.setText("");
          edtCEP.setText("");
          edtCidade.setText("");
          edtEstado.setText("");
        }
   } catch (SQLException se) {
     JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
                                   JOptionPane.ERROR_MESSAGE);
   }
  }
  void edtCodPais_focusLost(FocusEvent e) {
   try {
    if (edtCodPais.getText().equals("")==false) {
       Consulta = RotinasGlobais.Rotinas.ConsultaCampoDesc(
       ConsultasSQL.ConsSQL.Pais('S',edtCodPais.getText(),""),
       "Pa�s n�o encontrado!");
       if (Consulta!=null) {
         edtPais.setText(Consulta.getObject(2).toString());
       } else {
         edtCodPais.setText("");
         edtCodPais.requestFocus();
       }
     } else
        edtPais.setText("");
   } catch (SQLException se) {
     JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
                                   JOptionPane.ERROR_MESSAGE);
   }
  }
  void edtCodProfissao_focusLost(FocusEvent e) {
    if (edtCodProfissao.getText().equals("")==false) {
      edtProfissao.setText(RotinasGlobais.Rotinas.ConsultaCampoDesc(Consulta,
      edtCodProfissao.getText(),ConsultasSQL.ConsSQL.Profissao('S',
      edtCodProfissao.getText(),""),"Profiss�o n�o encontrado!"));
      if (edtProfissao.getText().equals(""))
         edtCodProfissao.requestFocus();
    } else
      edtProfissao.setText("");
  }
  void btnPEndereco_actionPerformed(ActionEvent e) {
    frmConEnderecos pfConEnderecos = new frmConEnderecos();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConEnderecos);
    pfConEnderecos.show();
    edtCodEndereco.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCodEndereco_focusLost(null);
  }
  void btnPPais_actionPerformed(ActionEvent e) {
    frmConPaises pfConPaises = new frmConPaises();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConPaises);
    pfConPaises.show();
    edtCodPais.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCodPais_focusLost(null);
  }
  void btnPProfissao_actionPerformed(ActionEvent e) {
    frmConProfissoes pfConProfissoes = new frmConProfissoes();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConProfissoes);
    pfConProfissoes.show();
    edtCodProfissao.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCodProfissao_focusLost(null);
  }
  void edtDtNascimento_focusLost(FocusEvent e) {
    if (edtDtNascimento.getText().equals("")==false) {
      if (RotinasGlobais.Rotinas.ValidaDateTime(
          edtDtNascimento.getText(),"dd/MM/yyyy")==false) {
        edtDtNascimento.setText("");
        edtDtNascimento.requestFocus();
      }
    }
  }
  void rbMasculino_actionPerformed(ActionEvent e) {
    rbFeminino.setSelected(false);
  }
  void rbFeminino_actionPerformed(ActionEvent e) {
    rbMasculino.setSelected(false);
  }

}