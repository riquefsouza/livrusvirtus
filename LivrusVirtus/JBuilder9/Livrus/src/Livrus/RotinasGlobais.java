package  Livrus;

import java.awt.*;
import java.util.*;
import java.text.*;
import javax.swing.*;
import java.sql.*;
import javax.swing.table.*;

public class RotinasGlobais {
  public static RotinasGlobais Rotinas;
  public String sUsuarioLogin, sUsuarioSenha;
  public String sCodigoSelecionado, sPreco, sQtdEstoque;

 public RotinasGlobais() {
  super();
 }
 //---------------------------------------------------------------------------
 public String rptstr(String texto, int tam) {
 int cont=1;
 String esp;

 esp="";
 while (cont <= tam) {
  esp=esp+texto;
  cont++;
 }
 return esp;
}
//---------------------------------------------------------------------------
public boolean ValidaInteger(String sNum)
{
 if (sNum.equals("")==false) {
	try {
	  Integer.parseInt(sNum);
	  return true;
	} catch(Exception e) {
          JOptionPane.showMessageDialog(null,"N�mero inv�lido!","Erro",
          JOptionPane.ERROR_MESSAGE);
	  return false;
	}
 } else
   return false;
}
//---------------------------------------------------------------------------
public boolean ValidaFloat(String sNum)
{
 if (sNum.equals("")==false) {
	try {
          sNum = VirgulaParaPonto(sNum,false);
          Float.parseFloat(sNum);
	  return true;
	} catch(Exception e) {
          JOptionPane.showMessageDialog(null,"N�mero inv�lido!","Erro",
          JOptionPane.ERROR_MESSAGE);
	  return false;
	}
 } else
   return false;
}
//---------------------------------------------------------------------------
public String VirgulaParaPonto(String sNum, boolean revertido)
{
 if (revertido)
     return sNum.replace('.',',');
 else
     return sNum.replace(',','.');
}
//---------------------------------------------------------------------------
  private int modulo11(String svalor, int ndig)
  {
    int ncont, nsoma, nvalor, npos;
    String slocal = new String();
    String sres = new String();

     ncont=0;
     slocal="";
     while (ncont < 11) {
       slocal=svalor.substring(ncont,ncont+1) + slocal;
       ncont++;
     }
     nsoma=0;
     if (ndig == 1)
       ncont=2;
     else
       ncont=1;
     npos=2;
     while (ncont < 11) {
       sres = slocal.substring(ncont,ncont+1);
       nvalor = Integer.parseInt(sres);
       nsoma=nsoma + (nvalor * npos);
       ncont++;
       npos++;
     }
     nsoma=(11 - (nsoma % 11));

     if (nsoma > 9)
       return 0;
     else
       return nsoma;
  }
//---------------------------------------------------------------------------
  public boolean ValidaISBN(String isbn)
  {
    String sisbn = new String();
    String sdigito = new String();
    String snum = new String();
    int nvalor, nsoma, ncont;

    if (isbn.length()==13) {
      sdigito = isbn.substring(isbn.length()-1,isbn.length());
      sisbn="";
      for(ncont = 0; ncont < isbn.length(); ncont++)  {
        if (isbn.substring(ncont,ncont+1).equals("-")==false)
          sisbn = sisbn + isbn.substring(ncont,ncont+1);
      }
      if (sdigito.equals("X"))
        nsoma = 10;
      else {
        nvalor = Integer.parseInt(sdigito);
        nsoma = nvalor;
      }
      for(ncont = 1; ncont <= 9; ncont++)  {
        snum = sisbn.substring(ncont-1,ncont);
        nvalor = Integer.parseInt(snum);
        nsoma=nsoma + (nvalor * (11 - ncont));
      }
      if ((nsoma % 11) == 0)
        return true;
      else
        return false;
    } else
      return false;
  }
//---------------------------------------------------------------------------
  public boolean ValidaCPF(String cpf)
  {
   String scpf = new String();

   if (cpf.length()==14)
   {
    scpf=cpf.substring(0,3)+cpf.substring(4,7)+cpf.substring(8,11)+
	cpf.substring(12,14);
    if ( (modulo11(scpf,1)==Integer.parseInt(cpf.substring(12,13))) &&
    (modulo11(scpf,2)==Integer.parseInt(cpf.substring(13))) )
     return true;
    else
     return false;
   }
   else return false;
  }
//---------------------------------------------------------------------------
  public boolean ValidaDateTime(String sData, String formato) {
   if (sData.equals("")==false) {
      try {
        Locale locale = Locale.getDefault();
        DateFormat sdf = new SimpleDateFormat(formato, locale);
        java.util.Date data = (java.util.Date)sdf.parse(sData);
        return true;
      } catch(ParseException e) {
        JOptionPane.showMessageDialog(null,"Data/Hora inv�lida!","Erro",
        JOptionPane.ERROR_MESSAGE);
        return false;
      }
   } else
     return false;
  }
 //---------------------------------------------------------------------------
  public java.util.Date retData() {
   java.util.Date dt = new java.util.Date();

   return retData(dt);
  }
//---------------------------------------------------------------------------
  public java.util.Date retData(java.util.Date dt) {
   SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
   String ds = sdf.format(dt);

   ParsePosition pos = new ParsePosition(0);
   java.util.Date dt2 = sdf.parse(ds, pos);

   return dt2;
  }
//---------------------------------------------------------------------------
  public String retDataStr(java.util.Date dt, String formato) {
   SimpleDateFormat sdf = new SimpleDateFormat(formato);
   String ds = sdf.format(dt);

   return ds;
  }
//---------------------------------------------------------------------------
  public String FormataDataStr(String sData, String formatoEntrada,
                               String formatoSaida) {
    try {
      Locale locale = Locale.getDefault();
      DateFormat sdf = new SimpleDateFormat(formatoEntrada, locale);
      java.util.Date data = (java.util.Date)sdf.parse(sData);

      DateFormat sdf2 = new SimpleDateFormat(formatoSaida, locale);

      return sdf2.format(data);
     } catch (Exception ex) {
      JOptionPane.showMessageDialog(null,ex.getMessage(),"Erro",
      JOptionPane.ERROR_MESSAGE);
     }
     return "";
  }
//---------------------------------------------------------------------------
   public void CentralizaDlg(JFrame frm1,JDialog dlg1) {
     Dimension dlgTam = dlg1.getPreferredSize();
     Dimension frmTam = frm1.getSize();
     Point loc = frm1.getLocation();
     dlg1.setLocation(((frmTam.width - dlgTam.width) / 2) + loc.x,
     ((frmTam.height - dlgTam.height) / 2) + (loc.y + (dlgTam.height / 4))  );
   }
//---------------------------------------------------------------------------
   public void CentralizaDlg(JDialog dlg1) {
     Dimension TamTela = Toolkit.getDefaultToolkit().getScreenSize();
     dlg1.setLocation((TamTela.width - dlg1.getPreferredSize().width) / 2,
     (TamTela.height - dlg1.getPreferredSize().height) / 2);
   }
//---------------------------------------------------------------------------
   public void CentralizaFrm(JFrame frm1) {
     Dimension TelaTam = Toolkit.getDefaultToolkit().getScreenSize();
     Dimension frameTam = frm1.getSize();
     if (frameTam.height > TelaTam.height)
       frameTam.height = TelaTam.height;
     if (frameTam.width > TelaTam.width)
       frameTam.width = TelaTam.width;
     frm1.setLocation((TelaTam.width - frameTam.width) / 2,
     (TelaTam.height - frameTam.height) / 2);
     frm1.setVisible(true);
   }
//---------------------------------------------------------------------------
   public void CentralizaPanel(JPanel pnl) {
     Dimension TamTela = Toolkit.getDefaultToolkit().getScreenSize();
     pnl.setLocation((TamTela.width - pnl.getPreferredSize().width) / 2,
     (TamTela.height - pnl.getPreferredSize().height) / 2);
   }
//---------------------------------------------------------------------------
   public void Conectar()  {
     String url, driver, login, senha;
     try {
       // sintaxe: jdbc:TIPO:maquina:porta/DB_NOME
       // via odbc

       url = "jdbc:odbc:ACLivrus";
       driver = "sun.jdbc.odbc.JdbcOdbcDriver";
       login = "";
       senha = "";

       // via MM driver nativo
       /*
       url = "jdbc:mysql://advance:3306/livrus";
       driver = "org.gjt.mm.mysql.Driver";
       login = "root";
       senha = "";
       */
       // via MySql Connector/J
       /*
       url = "jdbc:mysql://localhost:3306/livrus";
       driver = "com.mysql.jdbc.Driver";
       login = "root";
       senha = "";
       */
       /*
       // via PostgreSql Driver
       url = "jdbc:postgresql://localhost:5433/livrus";
       driver = "org.postgresql.Driver";
       login = "hfs";
       senha = "";
       */
       // via JDataStore Driver
        /*
       url = "jdbc:borland:dslocal:C:\\LivrusVirtus\\Bancos\\jdatastore\\livrus.jds";
       driver = "com.borland.datastore.jdbc.DataStoreDriver";
       login = "admin";
       senha = "admin";
        */

           Class.forName(driver);
           frmPrincipal.db = DriverManager.getConnection(url, login, senha);
     } catch (SQLException se) {
       JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     } catch (ClassNotFoundException cnfe) {
       JOptionPane.showMessageDialog(null,cnfe.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     }
   }
//---------------------------------------------------------------------------
   public void Desconectar(Connection conexao) {
     try {
           if (conexao != null)
             conexao.close();
     } catch (SQLException se) {
           JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
           JOptionPane.ERROR_MESSAGE);
     }
   }
//---------------------------------------------------------------------------
   public boolean ConsultaDados(Statement Consulta, String sTextoSql) {
     boolean nTemLinhas = false;
     ResultSet Leitor = null;
     try {
           Consulta = frmPrincipal.db.createStatement();
           Leitor = Consulta.executeQuery(sTextoSql);
           nTemLinhas = Leitor.next();
           Leitor.close();
     } catch (SQLException se) {
       JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     }
     return nTemLinhas;
   }
//---------------------------------------------------------------------------
   public ResultSet ConsultaDados(String sTextoSql) {
     ResultSet rsConsulta;
     try {
           Statement Consulta = frmPrincipal.db.createStatement();
           rsConsulta = Consulta.executeQuery(sTextoSql);
           return rsConsulta;
     } catch (SQLException se) {
       JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     }
     return null;
   }
//---------------------------------------------------------------------------
   public boolean ConsultaDados(ArrayList Registros, String sTextoSql, int nQtdCampos) {
     boolean nTemLinhas = false;
     ResultSet Leitor = null;
     try {
           Statement Consulta = frmPrincipal.db.createStatement();
           Registros.clear();
           Leitor = Consulta.executeQuery(sTextoSql);
           while (Leitor.next()) {
                  ArrayList Campos = new ArrayList();
                  for(int cont=1; cont <= nQtdCampos; cont++) {
                    Campos.add(Leitor.getObject(cont).toString());
                  }
                  Registros.add(Campos);
           }
           nTemLinhas = (!Registros.isEmpty());
     } catch (SQLException se) {
       JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     }
     return nTemLinhas;
   }
//---------------------------------------------------------------------------
   public Iterator ConsultaDados(String sTextoSql, int nQtdCampos) {
     boolean nTemLinhas = false;
     ArrayList Registros = new ArrayList();

     nTemLinhas = ConsultaDados(Registros, sTextoSql, nQtdCampos);
     return Registros.iterator();
   }
//---------------------------------------------------------------------------
   public boolean AtualizaDados(Statement Atualizacao, String sTextoSql) {
     int numRegistrosAlterados = 0;
     try {
           Atualizacao = frmPrincipal.db.createStatement();
           numRegistrosAlterados = Atualizacao.executeUpdate(sTextoSql);
     } catch (SQLException se) {
       JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
       JOptionPane.ERROR_MESSAGE);
     }
     return (numRegistrosAlterados > 0);
   }
//---------------------------------------------------------------------------
 public boolean ValidaCampo(String sCampo,String sMensagemErro)
 {
   if (sCampo.length() == 0) {
         JOptionPane.showMessageDialog(null,sMensagemErro,"Erro",
         JOptionPane.ERROR_MESSAGE);
         return true;
   } else
         return false;
 }
//---------------------------------------------------------------------------

public ResultSet ConsultaCampoDesc(String sTextoSql, String sMensagemErro) {
 ResultSet rsConsulta = ConsultaDados(sTextoSql);
 try {
    if (rsConsulta.next()==false) {
      JOptionPane.showMessageDialog(null,sMensagemErro,"Erro",
      JOptionPane.ERROR_MESSAGE);
      return null;
    }
  } catch (SQLException se) {
    JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
    JOptionPane.ERROR_MESSAGE);
  }
 return rsConsulta;
}
//---------------------------------------------------------------------------
public ResultSet ConsultaCampoDesc(
		  String sCampoCodigo,String sTextoSql,String sMensagemErro)
{
  if (RotinasGlobais.Rotinas.ValidaInteger(sCampoCodigo))
    return ConsultaCampoDesc(sTextoSql, sMensagemErro);
  else
    return null;
}
//---------------------------------------------------------------------------
public String ConsultaCampoDesc(ResultSet rsConsulta,
                  String sCampoCodigo,String sTextoSql,String sMensagemErro)
{
  try {
    if (RotinasGlobais.Rotinas.ValidaInteger(sCampoCodigo)) {
      rsConsulta = ConsultaCampoDesc(sTextoSql, sMensagemErro);
      if (rsConsulta!=null)
         return rsConsulta.getObject(2).toString();
    } else
      return "";
  } catch (SQLException se) {
    JOptionPane.showMessageDialog(null,se.getMessage(),"Erro",
    JOptionPane.ERROR_MESSAGE);
  }
  return "";
}
//---------------------------------------------------------------------------
public void preencheVetor(Iterator it,Vector vet1, Vector vet2) {
 ArrayList items = new ArrayList();

 while(it.hasNext()) {
  items = (ArrayList) it.next();
  vet1.addElement(items.get(0).toString());
  vet2.addElement(items.get(0).toString()+" - "+items.get(1).toString());
 }
}
//---------------------------------------------------------------------------
public void AdicionaItemLista(Vector slLista,
	 Vector slCodLista, JTextField sCampoCodigo, JTextField sCampoDesc)
{
  String sItems;

  if (sCampoDesc.getText().equals("")==false) {
   sItems=sCampoCodigo.getText()+" - "+sCampoDesc.getText();
   if (slLista.indexOf(sItems)==-1) {
      slCodLista.addElement(sCampoCodigo.getText());
      slLista.addElement(sItems);
   }
   sCampoCodigo.setText("");
   sCampoDesc.setText("");
  }
}
//---------------------------------------------------------------------------
public void RemoveItemLista(JList lstLista, Vector slLista, Vector slCodLista)
{
 if (slLista.size() > 0) {
   slCodLista.remove(lstLista.getSelectedIndex());
   slLista.remove(lstLista.getSelectedIndex());
 }
}
//---------------------------------------------------------------------------
public void acomodaColunas(JTable table, int margin) {
  for (int c=0; c<table.getColumnCount(); c++) {
      acomodaColuna(table, c, 2);
  }
}
//---------------------------------------------------------------------------
public void acomodaColuna(JTable table, int vColIndex, int margin) {
    TableModel model = table.getModel();
    DefaultTableColumnModel colModel = (DefaultTableColumnModel)table.getColumnModel();
    TableColumn col = colModel.getColumn(vColIndex);
    int width = 0;

    // pega a largura do cabe�alho da coluna
    TableCellRenderer renderer = col.getHeaderRenderer();
    if (renderer == null) {
        renderer = table.getTableHeader().getDefaultRenderer();
    }
    Component comp = renderer.getTableCellRendererComponent(
        table, col.getHeaderValue(), false, false, 0, 0);
    width = comp.getPreferredSize().width;

    // pega a largura maxima do dado da coluna
    for (int r=0; r<table.getRowCount(); r++) {
        renderer = table.getCellRenderer(r, vColIndex);
        comp = renderer.getTableCellRendererComponent(
            table, table.getValueAt(r, vColIndex), false, false, r, vColIndex);
        width = Math.max(width, comp.getPreferredSize().width);
    }

    // Adiciona margem
    width += 2*margin;

    // atribui a largura
    col.setPreferredWidth(width);
}
//---------------------------------------------------------------------------
// retorna a altura preferencial de uma linha.
// o resultado � igual a mais alta celula na linha.
public int AlturaLinhaPreferencial(JTable table, int rowIndex, int margin) {
    // pega a altura padrao para todas as linhas
    int height = table.getRowHeight();

    // Determina a mais alta celula na linha
    for (int c=0; c<table.getColumnCount(); c++) {
        TableCellRenderer renderer = table.getCellRenderer(rowIndex, c);
        Component comp = table.prepareRenderer(renderer, rowIndex, c);
        int h = comp.getPreferredSize().height + 2*margin;
        height = Math.max(height, h);
    }
    return height;
}
//---------------------------------------------------------------------------
// A altura da cada linha � atribuida para a altura preferencial da mais alta
// celula na linha;
public void acomodaLinhas(JTable table, int margin) {
    acomodaLinhas(table, 0, table.getRowCount(), margin);
}
//---------------------------------------------------------------------------
// Para cada linha >= ao inicio e < do que o fim, a altura de uma linha
// � atribuida para a altura preferencial da mais alta celula na linha.
public void acomodaLinhas(JTable table, int start, int end, int margin) {
    for (int r=0; r<table.getRowCount(); r++) {
        // pega a altura preferencial
        int h = AlturaLinhaPreferencial(table, r, margin);

        // atribui a altura da linha usando a altura preferencial
        if (table.getRowHeight(r) != h) {
            table.setRowHeight(r, h);
        }
    }
}

}

