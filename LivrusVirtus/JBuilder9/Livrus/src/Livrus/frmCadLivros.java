package Livrus;

import java.sql.*;
import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;

public class frmCadLivros extends frmCadastros {
  public static frmCadLivros fCadLivros;
  JTextField edtCodAutor = new JTextField();
  JButton btnAdAssuntos = new JButton();
  JList lstAssuntos = new JList();
  JButton btnPAssunto = new JButton();
  JTextField edtAutor = new JTextField();
  JLabel labAssunto = new JLabel();
  JLabel labAutor = new JLabel();
  JLabel labPreco = new JLabel();
  JButton btnPAutor = new JButton();
  JButton btnAdAutores = new JButton();
  JSpinner edtNPaginas = new JSpinner();
  JSpinner edtQtdEstoque = new JSpinner();
  JLabel labIdioma = new JLabel();
  JLabel labQtdEstoque = new JLabel();
  JTextField edtEditora = new JTextField();
  JSpinner edtAnoPubli = new JSpinner();
  JLabel labNPaginas = new JLabel();
  JLabel labEditora = new JLabel();
  JSpinner edtVolume = new JSpinner();
  JComboBox cmbIdioma = new JComboBox();
  JButton btnPEditora = new JButton();
  JTextField edtCodEditora = new JTextField();
  JList lstAutores = new JList();
  JLabel labAnoPubli = new JLabel();
  JLabel labVolume = new JLabel();
  JTextField edtAssunto = new JTextField();
  JSpinner edtEdicao = new JSpinner();
  JTextField edtPreco = new JTextField();
  JTextField edtCodAssunto = new JTextField();
  JLabel labEdicao = new JLabel();
  JScrollPane jScrollPane1 = new JScrollPane();
  JScrollPane jScrollPane2 = new JScrollPane();
  Vector slAssuntos = new Vector();
  Vector vtAssuntosDesc = new Vector();
  Vector slAutores = new Vector();
  Vector vtAutoresDesc = new Vector();
  ArrayList slIdiomas = new ArrayList();


  public frmCadLivros() {
    try {
      jbInit();
    }
    catch(Exception e) {
      e.printStackTrace();
    }
  }

  private void jbInit() throws Exception {
    this.setTitle("Cadastro de Livros");
    this.labDescricao.setText("T�tulo: ");
    edtDescricao.setBounds(new Rectangle(12, 74, 335, 21));
    this.setSize(new Dimension(570, 441));
    labEdicao.setText("Edi��o:");
    labEdicao.setBounds(new Rectangle(352, 56, 52, 16));
    edtCodAssunto.setBounds(new Rectangle(106, 205, 80, 21));
    edtCodAssunto.setEnabled(false);
    edtCodAssunto.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodAssunto_focusLost(e);
      }
    });
    edtPreco.setBounds(new Rectangle(14, 250, 91, 21));
    edtPreco.setEnabled(false);
    edtPreco.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtPreco_focusLost(e);
      }
    });
    edtEdicao.setBounds(new Rectangle(352, 74, 91, 22));
    edtEdicao.setBorder(null);
    edtEdicao.setEnabled(false);
    edtAssunto.setBounds(new Rectangle(190, 205, 204, 21));
    edtAssunto.setEnabled(false);
    labVolume.setBounds(new Rectangle(12, 144, 52, 16));
    labVolume.setText("Volume:");
    labAnoPubli.setBounds(new Rectangle(12, 100, 95, 16));
    labAnoPubli.setText("Ano Publica��o:");
    jScrollPane1.setBounds(new Rectangle(106, 228, 339, 43));
    jScrollPane2.setBounds(new Rectangle(106, 315, 339, 43));
    lstAutores.setEnabled(false);
    edtCodEditora.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodEditora_focusLost(e);
      }
    });
    edtCodEditora.setBounds(new Rectangle(106, 116, 80, 21));
    edtCodEditora.setColumns(10);
    edtCodEditora.setEnabled(false);
    btnPEditora.setEnabled(false);
    btnPEditora.setBounds(new Rectangle(422, 116, 21, 21));
    btnPEditora.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPEditora_actionPerformed(e);
      }
    });
    btnPEditora.setText("...");
    cmbIdioma.setBounds(new Rectangle(106, 161, 341, 21));
    cmbIdioma.setEditable(false);
    cmbIdioma.setEnabled(false);
    edtVolume.setBorder(null);
    edtVolume.setBounds(new Rectangle(12, 161, 91, 22));
    edtVolume.setEnabled(false);
    labEditora.setText("Editora:");
    labEditora.setBounds(new Rectangle(106, 98, 82, 16));
    labNPaginas.setBounds(new Rectangle(14, 188, 71, 16));
    labNPaginas.setText("N� P�ginas:");
    edtAnoPubli.setBorder(null);
    edtAnoPubli.setBounds(new Rectangle(12, 117, 91, 22));
    edtAnoPubli.setEnabled(false);
    edtEditora.setBounds(new Rectangle(190, 116, 228, 21));
    edtEditora.setEnabled(false);
    labQtdEstoque.setText("Qtd.Estoque:");
    labQtdEstoque.setBounds(new Rectangle(14, 274, 79, 16));
    labIdioma.setBounds(new Rectangle(106, 144, 69, 16));
    labIdioma.setText("Idioma:");
    edtQtdEstoque.setBounds(new Rectangle(14, 291, 91, 22));
    edtQtdEstoque.setBorder(null);
    edtQtdEstoque.setEnabled(false);
    edtNPaginas.setBorder(null);
    edtNPaginas.setEnabled(false);
    edtNPaginas.setBounds(new Rectangle(14, 205, 91, 22));
    btnAdAutores.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnAdAutores_actionPerformed(e);
      }
    });
    btnAdAutores.setMargin(new Insets(2, 5, 2, 4));
    btnAdAutores.setText("+");
    btnAdAutores.setEnabled(false);
    btnAdAutores.setBounds(new Rectangle(396, 292, 21, 21));
    btnPAutor.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPAutor_actionPerformed(e);
      }
    });
    btnPAutor.setText("...");
    btnPAutor.setEnabled(false);
    btnPAutor.setBounds(new Rectangle(424, 292, 21, 21));
    labPreco.setText("Pre�o:");
    labPreco.setBounds(new Rectangle(14, 232, 69, 16));
    labAutor.setBounds(new Rectangle(108, 274, 82, 16));
    labAutor.setText("Autor:");
    labAssunto.setBounds(new Rectangle(106, 188, 82, 16));
    labAssunto.setText("Assunto:");
    edtAutor.setBounds(new Rectangle(190, 292, 204, 21));
    edtAutor.setEnabled(false);
    btnPAssunto.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnPAssunto_actionPerformed(e);
      }
    });
    btnPAssunto.setText("...");
    btnPAssunto.setEnabled(false);
    btnPAssunto.setBounds(new Rectangle(422, 205, 21, 21));
    lstAssuntos.setEnabled(false);
    btnAdAssuntos.setBounds(new Rectangle(396, 205, 21, 21));
    btnAdAssuntos.setEnabled(false);
    btnAdAssuntos.addActionListener(new java.awt.event.ActionListener() {
      public void actionPerformed(ActionEvent e) {
        btnAdAssuntos_actionPerformed(e);
      }
    });
    btnAdAssuntos.setMargin(new Insets(2, 5, 2, 4));
    btnAdAssuntos.setText("+");
    edtCodAutor.addFocusListener(new java.awt.event.FocusAdapter() {
      public void focusLost(FocusEvent e) {
        edtCodAutor_focusLost(e);
      }
    });
    edtCodAutor.setBounds(new Rectangle(106, 292, 80, 21));
    edtCodAutor.setColumns(10);
    edtCodAutor.setEnabled(false);
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
      public void internalFrameOpened(InternalFrameEvent e) {
        this_internalFrameOpened(e);
      }
    });
    jPanel1.add(labEdicao, null);
    jPanel1.add(edtEdicao, null);
    jPanel1.add(labAnoPubli, null);
    jPanel1.add(edtAnoPubli, null);
    jPanel1.add(labEditora, null);
    jPanel1.add(edtCodEditora, null);
    jPanel1.add(edtEditora, null);
    jPanel1.add(btnPEditora, null);
    jPanel1.add(labVolume, null);
    jPanel1.add(edtVolume, null);
    jPanel1.add(labIdioma, null);
    jPanel1.add(cmbIdioma, null);
    jPanel1.add(labNPaginas, null);
    jPanel1.add(edtNPaginas, null);
    jPanel1.add(labAssunto, null);
    jPanel1.add(edtCodAssunto, null);
    jPanel1.add(edtAssunto, null);
    jPanel1.add(btnAdAssuntos, null);
    jPanel1.add(btnPAssunto, null);
    jPanel1.add(labPreco, null);
    jPanel1.add(edtPreco, null);
    jPanel1.add(labQtdEstoque, null);
    jPanel1.add(edtQtdEstoque, null);
    jPanel1.add(labAutor, null);
    jPanel1.add(edtCodAutor, null);
    jPanel1.add(edtAutor, null);
    jPanel1.add(btnAdAutores, null);
    jPanel1.add(btnPAutor, null);
    jPanel1.add(jScrollPane1, null);
    jPanel1.add(jScrollPane2, null);
    jScrollPane1.getViewport().add(lstAssuntos, null);
    jScrollPane2.getViewport().add(lstAutores, null);
  }

  private void adicionaListaAssuntos(Iterator it) {
    RotinasGlobais.Rotinas.preencheVetor(it, slAssuntos, vtAssuntosDesc);
    lstAssuntos = new JList(vtAssuntosDesc);
    lstAssuntos.setSelectedIndex(0);
    lstAssuntos.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

    lstAssuntos.addMouseListener(new java.awt.event.MouseAdapter() {
      public void mouseClicked(MouseEvent e) {
        lstAssuntos_mouseClicked(e);
      }
    });
    redesenhaListaAssuntos();
  }

  private void redesenhaListaAssuntos() {
    jScrollPane1.getViewport().add(lstAssuntos, null);
    jPanel1.remove(jScrollPane1);
    jPanel1.add(jScrollPane1, null);
    jPanel1.validate();
  }

  private void adicionaListaAutores(Iterator it) {
    RotinasGlobais.Rotinas.preencheVetor(it,slAutores,vtAutoresDesc);
    lstAutores = new JList(vtAutoresDesc);
    lstAutores.setSelectedIndex(0);
    lstAutores.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);

    lstAutores.addMouseListener(new java.awt.event.MouseAdapter() {
      public void mouseClicked(MouseEvent e) {
        lstAutores_mouseClicked(e);
      }
    });

    redesenhaListaAutores();
  }
  private void redesenhaListaAutores() {
    jScrollPane2.getViewport().add(lstAutores, null);
    jPanel1.remove(jScrollPane2);
    jPanel1.add(jScrollPane2, null);
    jPanel1.validate();
  }

  protected boolean ValidaDados(boolean bTodosDados)
  {
        super.ValidaDados(bTodosDados);

        if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.getText(),
                "ISBN n�o informado!"))
          return false;
        if (bTodosDados) {
          if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.getText(),
                "T�tulo n�o informado!"))
                return false;
          if (RotinasGlobais.Rotinas.ValidaCampo(edtEditora.getText(),
                "Editora n�o informada!"))
                return false;
          if (lstAssuntos.getVisibleRowCount() == 0){
             JOptionPane.showMessageDialog(this,"Assunto(s) n�o informado(s)!",
             "Erro",JOptionPane.ERROR_MESSAGE);
             return false;
          }
          if (lstAutores.getVisibleRowCount() == 0){
             JOptionPane.showMessageDialog(this,"Autor(es) n�o informado(s)!",
             "Erro",JOptionPane.ERROR_MESSAGE);
             return false;
          }
        }
        return true;
  }

  protected void InformaLimpaDados(boolean bInformar)
  {
    super.InformaLimpaDados(bInformar);
      if (bInformar) {
        edtEdicao.setValue(new Integer(Campos.get(2).toString()));
        edtAnoPubli.setValue(new Integer(Campos.get(3).toString()));
        edtVolume.setValue(new Integer(Campos.get(4).toString()));
        edtCodEditora.setText(Campos.get(5).toString());
        edtEditora.setText(Campos.get(6).toString());
        cmbIdioma.setSelectedIndex(slIdiomas.indexOf(Campos.get(7).toString()));
        edtNPaginas.setValue(new Integer(Campos.get(9).toString()));
        edtPreco.setText(RotinasGlobais.Rotinas.
                         VirgulaParaPonto(Campos.get(10).toString(),true));
        edtQtdEstoque.setValue(new Integer(Campos.get(11).toString()));
        adicionaListaAssuntos(RotinasGlobais.Rotinas.ConsultaDados(
          ConsultasSQL.ConsSQL.LivroAss('S',edtCodigo.getText(),""),2));
        adicionaListaAutores(RotinasGlobais.Rotinas.ConsultaDados(
          ConsultasSQL.ConsSQL.LivroAut('S',edtCodigo.getText(),""),2));
      } else {
        edtEdicao.setValue(new Integer(1));
        edtAnoPubli.setValue(new Integer(
          RotinasGlobais.Rotinas.retDataStr(new java.util.Date(),"yyyy")));
        edtVolume.setValue(new Integer(1));
        edtCodEditora.setText("");
        edtEditora.setText("");
        edtNPaginas.setValue(new Integer(1));
        edtPreco.setText("0,00");
        edtQtdEstoque.setValue(new Integer(1));
        edtCodAssunto.setText("");
        lstAssuntos.removeAll();
        edtCodAutor.setText("");
        lstAutores.removeAll();
        slAssuntos.removeAllElements();
        slAutores.removeAllElements();
      }
  }

  protected void HabilitaDados(boolean bHabilita)
  {
    super.HabilitaDados(bHabilita);

     edtEdicao.setEnabled(bHabilita);
     edtAnoPubli.setEnabled(bHabilita);
     edtVolume.setEnabled(bHabilita);
     edtCodEditora.setEnabled(bHabilita);
     btnPEditora.setEnabled(bHabilita);
     cmbIdioma.setEnabled(bHabilita);
     edtNPaginas.setEnabled(bHabilita);
     edtPreco.setEnabled(bHabilita);
     edtQtdEstoque.setEnabled(bHabilita);
     edtCodAssunto.setEnabled(bHabilita);
     btnPAssunto.setEnabled(bHabilita);
     btnAdAssuntos.setEnabled(bHabilita);
     lstAssuntos.setEnabled(bHabilita);
     edtCodAutor.setEnabled(bHabilita);
     btnPAutor.setEnabled(bHabilita);
     btnAdAutores.setEnabled(bHabilita);
     lstAutores.setEnabled(bHabilita);
  }

  void btnExcluir_actionPerformed(ActionEvent e) {
    ExcluirDados(ConsultasSQL.ConsSQL.Livro('D',edtCodigo.getText(),
    "","","","","","","","",""));
  }

  void btnPesquisar_actionPerformed(ActionEvent e) {
    PesquisarDados(ConsultasSQL.ConsSQL.Livro('S',edtCodigo.getText(),
    "","","","","","","","",""),"Livro n�o encontrado!",12);
  }

  void btnSalvar_actionPerformed(ActionEvent e) {

    SalvarDados(ConsultasSQL.ConsSQL.Livro('S',
    edtCodigo.getText(),"","","","","","","","",""),
    ConsultasSQL.ConsSQL.Livro('U',edtCodigo.getText(),edtDescricao.getText(),
    edtEdicao.getValue().toString(),edtAnoPubli.getValue().toString(),
    edtVolume.getValue().toString(),edtCodEditora.getText(),
    slIdiomas.get(cmbIdioma.getSelectedIndex()).toString(),
    edtNPaginas.getValue().toString(),RotinasGlobais.Rotinas.
    VirgulaParaPonto(edtPreco.getText(),false),
    edtQtdEstoque.getValue().toString()),
    ConsultasSQL.ConsSQL.Livro('I',edtCodigo.getText(),edtDescricao.getText(),
    edtEdicao.getValue().toString(),edtAnoPubli.getValue().toString(),
    edtVolume.getValue().toString(),edtCodEditora.getText(),
    slIdiomas.get(cmbIdioma.getSelectedIndex()).toString(),
    edtNPaginas.getValue().toString(),RotinasGlobais.Rotinas.
    VirgulaParaPonto(edtPreco.getText(),false),
    edtQtdEstoque.getValue().toString()),
    true);
    SalvaLista('A');
    SalvaLista('B');
    btnLimpar_actionPerformed(null);
  }

  void btnFechar_actionPerformed(ActionEvent e) {
    super.btnFechar_actionPerformed(e);

    this_internalFrameClosing(null);
  }

  void this_internalFrameClosing(InternalFrameEvent e) {
    super.this_internalFrameClosing(e);
    frmPrincipal.fPrincipal.tlbLivros.setEnabled(true);
    frmPrincipal.fPrincipal.mnuCadLivros.setEnabled(true);
  }
  void this_internalFrameOpened(InternalFrameEvent e) {
    edtAnoPubli.setValue(new Integer(
      RotinasGlobais.Rotinas.retDataStr(new java.util.Date(),"yyyy")));
    AdicionaCombo();
    cmbIdioma.setSelectedIndex(0);
  }

  private void AdicionaCombo() {
    try {
        Consulta = RotinasGlobais.Rotinas.ConsultaDados(
            ConsultasSQL.ConsSQL.Idioma('S',"",""));

         while (Consulta.next()){
          slIdiomas.add(Consulta.getObject(1).toString());
          cmbIdioma.addItem(Consulta.getObject(2).toString());
         }
     } catch (SQLException se) {
       JOptionPane.showMessageDialog(this,se.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     }
  }

  private void SalvaLista(char sOpcao) {
    if (sOpcao=='A') {
     RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
     ConsultasSQL.ConsSQL.LivroAss('D',edtCodigo.getText(),""));

     for (int nCont=0; nCont <= slAssuntos.size()-1; nCont++)  {
      RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
      ConsultasSQL.ConsSQL.LivroAss('I',
            edtCodigo.getText(),slAssuntos.get(nCont).toString()));
     }
    } else if (sOpcao=='B') {
      RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
      ConsultasSQL.ConsSQL.LivroAut('D',edtCodigo.getText(),""));

      for (int nCont=0; nCont <= slAutores.size()-1; nCont++)  {
       RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
       ConsultasSQL.ConsSQL.LivroAut('I',
             edtCodigo.getText(),slAssuntos.get(nCont).toString()));
      }
    }
  }
  void edtCodigo_focusLost(FocusEvent e) {
    if (edtCodigo.getText().equals("")==false) {
          if (RotinasGlobais.Rotinas.ValidaISBN(edtCodigo.getText())==false) {
            JOptionPane.showMessageDialog(this,"ISBN inv�lido!",
            frmPrincipal.fPrincipal.getTitle(), JOptionPane.OK_OPTION |
            JOptionPane.ERROR_MESSAGE);
            edtCodigo.setText("");
            edtCodigo.requestFocus();
          }
    }
  }
  void edtCodEditora_focusLost(FocusEvent e) {
    if (edtCodEditora.getText().equals("")==false) {
      edtEditora.setText(RotinasGlobais.Rotinas.ConsultaCampoDesc(Consulta,
      edtCodEditora.getText(),ConsultasSQL.ConsSQL.Editora('S',
      edtCodEditora.getText(),""),"Editora n�o encontrada!"));
      if (edtEditora.getText().equals(""))
         edtCodEditora.requestFocus();
    }
  }
  void btnPEditora_actionPerformed(ActionEvent e) {
    frmConEditoras pfConEditoras = new frmConEditoras();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConEditoras);
    pfConEditoras.show();
    edtCodEditora.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCodEditora_focusLost(null);
  }
  void edtPreco_focusLost(FocusEvent e) {
    if (RotinasGlobais.Rotinas.ValidaFloat(edtPreco.getText()))
      edtPreco.setText(RotinasGlobais.Rotinas.VirgulaParaPonto(
          edtPreco.getText(),true));
    else
      edtPreco.setText("0,00");
  }
  void edtCodAssunto_focusLost(FocusEvent e) {
    if (edtCodAssunto.getText().equals("")==false) {
      edtAssunto.setText(RotinasGlobais.Rotinas.ConsultaCampoDesc(Consulta,
      edtCodAssunto.getText(),ConsultasSQL.ConsSQL.Assunto('S',
      edtCodAssunto.getText(),""),"Assunto n�o encontrado!"));
      if (edtAssunto.getText().equals(""))
         edtCodAssunto.requestFocus();
    }
  }
  void edtCodAutor_focusLost(FocusEvent e) {
    if (edtCodAutor.getText().equals("")==false) {
      edtAutor.setText(RotinasGlobais.Rotinas.ConsultaCampoDesc(Consulta,
      edtCodAutor.getText(),ConsultasSQL.ConsSQL.Autor('S',
      edtCodAutor.getText(),""),"Autor n�o encontrado!"));
      if (edtAutor.getText().equals(""))
         edtCodAutor.requestFocus();
    }
  }
  void btnPAssunto_actionPerformed(ActionEvent e) {
    frmConAssuntos pfConAssuntos = new frmConAssuntos();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConAssuntos);
    pfConAssuntos.show();
    edtCodAssunto.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCodAssunto_focusLost(null);
  }
  void btnAdAssuntos_actionPerformed(ActionEvent e) {
    RotinasGlobais.Rotinas.AdicionaItemLista(vtAssuntosDesc,slAssuntos,
                                             edtCodAssunto,edtAssunto);
    redesenhaListaAssuntos();
  }
  void lstAssuntos_mouseClicked(MouseEvent e) {
    RotinasGlobais.Rotinas.RemoveItemLista(lstAssuntos,
                                           vtAssuntosDesc,slAssuntos);
    redesenhaListaAssuntos();
  }
  void btnPAutor_actionPerformed(ActionEvent e) {
    frmConAutores pfConAutores = new frmConAutores();
    RotinasGlobais.Rotinas.CentralizaDlg(pfConAutores);
    pfConAutores.show();
    edtCodAutor.setText(RotinasGlobais.Rotinas.sCodigoSelecionado);
    edtCodAutor_focusLost(null);
  }
  void btnAdAutores_actionPerformed(ActionEvent e) {
    RotinasGlobais.Rotinas.AdicionaItemLista(vtAutoresDesc,slAutores,
                                             edtCodAutor,edtAutor);
    redesenhaListaAutores();
  }
  void lstAutores_mouseClicked(MouseEvent e) {
    RotinasGlobais.Rotinas.RemoveItemLista(lstAutores,
                                           vtAutoresDesc,slAutores);
    redesenhaListaAutores();
  }

}