package Livrus;

import org.wxwindows.*;
import java.util.*;
import java.text.*;
import java.sql.*;
import javax.swing.table.*;

public class RotinasGlobais {
  public static RotinasGlobais Rotinas;
  public String sUsuarioLogin = "", sUsuarioSenha, sBarraLogin;
  public String sCodigoSelecionado, sPreco, sQtdEstoque;
  public static Connection gConexao;
  public static String sepDTHR = "#"; /* SOMENTE ACCESS */
  //public static String sepDTHR = "'"; /* OUTROS BANCOS */

  public RotinasGlobais() {
    super();
  }

//---------------------------------------------------------------------------
  public boolean ValidaFloat(String sNum) {
    if (sNum.equals("") == false) {
      try {
        sNum = VirgulaParaPonto(sNum, false);
        Float.parseFloat(sNum);
        return true;
      }
      catch (Exception e) {
        wx.wxMessageBox(Resource.STR_NUMINV, "Erro",
                        wx.wxOK | wx.wxICON_ERROR);
        return false;
      }
    }
    else {
      return false;
    }
  }

//---------------------------------------------------------------------------
  public String VirgulaParaPonto(String sNum, boolean revertido) {
    if (revertido) {
      return sNum.replace('.', ',');
    }
    else {
      return sNum.replace(',', '.');
    }
  }

//---------------------------------------------------------------------------
  private int modulo11(String svalor, int ndig) {
    int ncont, nsoma, nvalor, npos;
    String slocal = new String();
    String sres = new String();

    ncont = 0;
    slocal = "";
    while (ncont < 11) {
      slocal = svalor.substring(ncont, ncont + 1) + slocal;
      ncont++;
    }
    nsoma = 0;
    if (ndig == 1) {
      ncont = 2;
    }
    else {
      ncont = 1;
    }
    npos = 2;
    while (ncont < 11) {
      sres = slocal.substring(ncont, ncont + 1);
      nvalor = Integer.parseInt(sres);
      nsoma = nsoma + (nvalor * npos);
      ncont++;
      npos++;
    }
    nsoma = (11 - (nsoma % 11));

    if (nsoma > 9) {
      return 0;
    }
    else {
      return nsoma;
    }
  }

//---------------------------------------------------------------------------
  public boolean ValidaISBN(String isbn) {
    String sisbn = new String();
    String sdigito = new String();
    String snum = new String();
    int nvalor, nsoma, ncont;

    if (isbn.length() == 13) {
      sdigito = isbn.substring(isbn.length() - 1, isbn.length());
      sisbn = "";
      for (ncont = 0; ncont < isbn.length(); ncont++) {
        if (isbn.substring(ncont, ncont + 1).equals("-") == false) {
          sisbn = sisbn + isbn.substring(ncont, ncont + 1);
        }
      }
      if (sdigito.equals("X")) {
        nsoma = 10;
      }
      else {
        nvalor = Integer.parseInt(sdigito);
        nsoma = nvalor;
      }
      for (ncont = 1; ncont <= 9; ncont++) {
        snum = sisbn.substring(ncont - 1, ncont);
        nvalor = Integer.parseInt(snum);
        nsoma = nsoma + (nvalor * (11 - ncont));
      }
      if ( (nsoma % 11) == 0) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }

//---------------------------------------------------------------------------
  public boolean ValidaCPF(String cpf) {
    String scpf = new String();

    if (cpf.length() == 14) {
      scpf = cpf.substring(0, 3) + cpf.substring(4, 7) + cpf.substring(8, 11) +
          cpf.substring(12, 14);
      if ( (modulo11(scpf, 1) == Integer.parseInt(cpf.substring(12, 13))) &&
          (modulo11(scpf, 2) == Integer.parseInt(cpf.substring(13)))) {
        return true;
      }
      else {
        return false;
      }
    }
    else {
      return false;
    }
  }

//---------------------------------------------------------------------------
  boolean validaDataHora(String sDataHora, boolean bSoData) {
    boolean bvalida, bdatavalida, bhoravalida;
    String sdia, smes, sano, shora, smin, sseg;
    int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

    bvalida = false;
    bdatavalida = false;
    bhoravalida = false;
    nudiames = 0;
    if (bSoData == true) {
      ntam = 10;
    }
    else {
      ntam = 19;

    }
    if (sDataHora.length() == ntam) {
      sdia = sDataHora.substring(0, 2);
      ndia = Integer.parseInt(sdia);
      smes = sDataHora.substring(3, 5);
      nmes = Integer.parseInt(smes);
      sano = sDataHora.substring(6, 10);
      nano = Integer.parseInt(sano);

      if ( (nano >= 1) && (nano <= 9999)) {
        if ( (nmes >= 1) && (nmes <= 31)) {
          switch (nmes) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
              nudiames = 31;
              break;
            case 2: {
              /* ano bissexto */
              if ( (nano % 4) == 0) {
                nudiames = 29;
              }
              else {
                nudiames = 28;
              }
            }
            break;
            case 4:
            case 6:
            case 9:
            case 11:
              nudiames = 30;
              break;
          }
          if ( (ndia >= 1) && (ndia <= nudiames)) {
            bdatavalida = true;
          }
        }
      }

      if (bSoData) {
        if (bdatavalida) {
          bvalida = true;
        }
        else {
          bvalida = false;
        }
      }
      else {
        if (bdatavalida) {
          shora = sDataHora.substring(11, 13);
          nhora = Integer.parseInt(shora);
          smin = sDataHora.substring(14, 16);
          nmin = Integer.parseInt(smin);
          sseg = sDataHora.substring(17, 19);
          nseg = Integer.parseInt(sseg);

          if ( (nhora >= 0) && (nhora <= 23)) {
            if ( (nmin >= 0) && (nmin <= 59)) {
              if ( (nseg >= 0) && (nseg <= 59)) {
                bhoravalida = true;
              }
            }
          }
          if (bhoravalida) {
            bvalida = true;
          }
          else {
            bvalida = false;
          }
        }
        else {
          bvalida = false;
        }
      }
    }
    else {
      bvalida = false;

    }
    return bvalida;
  }

//---------------------------------------------------------------------------
  public String retDataHoraStr(boolean bData, boolean bHora) {
    SimpleDateFormat sdf = new SimpleDateFormat();
    String sDataHora;

    if (bData && bHora) {
      sdf = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");
    }
    else if (bData) {
      sdf = new SimpleDateFormat("dd/MM/yyyy");
    }
    else if (bHora) {
      sdf = new SimpleDateFormat("hh:mm:ss");

    }
    sDataHora = sdf.format(new java.util.Date());

    return sDataHora;
  }

//---------------------------------------------------------------------------
  public String ConverteDataHoraStr(String sData, String formatoEntrada,
                                    String formatoSaida) {
    try {
      Locale locale = Locale.getDefault();
      DateFormat sdf = new SimpleDateFormat(formatoEntrada, locale);
      java.util.Date data = (java.util.Date) sdf.parse(sData);

      DateFormat sdf2 = new SimpleDateFormat(formatoSaida, locale);

      return sdf2.format(data);
    }
    catch (Exception ex) {
      wx.wxMessageBox(ex.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
    return "";
  }

//---------------------------------------------------------------------------
  public boolean ConectaBanco() {
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
      gConexao = DriverManager.getConnection(url, login, senha);
      if (!gConexao.isClosed()) {
        return true;
      }
      else {
        return false;
      }
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
      return false;
    }
    catch (ClassNotFoundException cnfe) {
      wx.wxMessageBox(cnfe.getMessage(), "Erro",
                      wx.wxOK | wx.wxICON_ERROR);
      return false;
    }
  }

//---------------------------------------------------------------------------
  public void DisconectaBanco() {
    try {
      if (gConexao != null) {
        gConexao.close();
      }
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
  }

//---------------------------------------------------------------------------
  public boolean ConsultaDados(Statement Consulta, String sTextoSql) {
    boolean nTemLinhas = false;
    ResultSet Leitor = null;
    try {
      Consulta = gConexao.createStatement();
      Leitor = Consulta.executeQuery(sTextoSql);
      nTemLinhas = Leitor.next();
      Leitor.close();
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
    return nTemLinhas;
  }

//---------------------------------------------------------------------------
  public ResultSet ConsultaDadosLista(String sTextoSql) {
    ResultSet rsConsulta;
    try {
      Statement Consulta = gConexao.createStatement();
      rsConsulta = Consulta.executeQuery(sTextoSql);
      return rsConsulta;
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
    return null;
  }

//---------------------------------------------------------------------------
  public boolean ConsultaDadosLista(ArrayList Registros, String sTextoSql,
                                    int nQtdCampos) {
    boolean nTemLinhas = false;
    ResultSet Leitor = null;
    try {
      Statement Consulta = gConexao.createStatement();
      Registros.clear();
      Leitor = Consulta.executeQuery(sTextoSql);
      while (Leitor.next()) {
        ArrayList Campos = new ArrayList();
        for (int cont = 1; cont <= nQtdCampos; cont++) {
          Campos.add(Leitor.getObject(cont).toString());
        }
        Registros.add(Campos);
      }
      nTemLinhas = (!Registros.isEmpty());
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
    return nTemLinhas;
  }

//---------------------------------------------------------------------------
  public boolean AtualizaDados(Statement Atualizacao, String sTextoSql) {
    int numRegistrosAlterados = 0;
    try {
      Atualizacao = gConexao.createStatement();
      numRegistrosAlterados = Atualizacao.executeUpdate(sTextoSql);
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
    return (numRegistrosAlterados > 0);
  }

//---------------------------------------------------------------------------
  public boolean ValidaCampo(String sCampo, String sMensagemErro) {
    if (sCampo.length() == 0) {
      wx.wxMessageBox(sMensagemErro, "Erro", wx.wxOK | wx.wxICON_ERROR);
      return true;
    }
    else {
      return false;
    }
  }

//---------------------------------------------------------------------------
  public ResultSet ConsultaCampoDesc(String sTextoSql, String sMensagemErro) {
    ResultSet rsConsulta = ConsultaDadosLista(sTextoSql);
    try {
      if (rsConsulta.next() == false) {
        wx.wxMessageBox(sMensagemErro, "Erro", wx.wxOK | wx.wxICON_ERROR);
        return null;
      }
    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
    return rsConsulta;
  }

//---------------------------------------------------------------------------
  public void AdicionaItemLista(wxListBox lstLista,
           ArrayList slCodLista, wxTextCtrl sCampoCodigo, wxTextCtrl sCampoDesc)
  {
  String sItems;

    if (sCampoDesc.GetValue().length() > 0) {
     sItems=sCampoCodigo.GetValue()+" - "+sCampoDesc.GetValue();
     if (lstLista.FindString(sItems)==-1) {
              slCodLista.add(sCampoCodigo.GetValue());
              lstLista.Append(sItems);
     }
     sCampoCodigo.Clear();
     sCampoDesc.Clear();
    }
  }
  //---------------------------------------------------------------------------
  public void RemoveItemLista(wxListBox lstLista, ArrayList slCodLista){
    int nSelIndice = 0;
    if (lstLista.GetCount() > 0){
      nSelIndice = lstLista.GetSelection();
      if (lstLista.Selected(nSelIndice)) {
        slCodLista.remove(nSelIndice);
        lstLista.Delete(nSelIndice);
      }
    }
  }
  //---------------------------------------------------------------------------
  public void AdicionaValoresLista(String sTextoSql,
    wxListBox lstLista, ArrayList slCodLista){
   ArrayList lstRegistros = new ArrayList();
   ArrayList lstCampos;
   int nLinha;

   lstLista.Clear();
   slCodLista.clear();

    if (ConsultaDadosLista(lstRegistros,sTextoSql,2)){
      for (nLinha = 0; nLinha < lstRegistros.size(); nLinha++) {
        lstCampos = (ArrayList) lstRegistros.get(nLinha);
        slCodLista.add(lstCampos.get(0).toString());
        lstLista.Append(lstCampos.get(0).toString() + " - " +
                        lstCampos.get(1).toString());
      }
    }
  }
//---------------------------------------------------------------------------
  public void AdicionaColunasGrid(wxListCtrl lista, int nPosIni, int nQtdCols,
                                  int[] nLargura, String[] sRotulos) {
    int nPos, nCont;

    nCont = 0;
    for (nPos = nPosIni; nPos < (nPosIni + nQtdCols); nPos++) {
      lista.InsertColumn(nPos, sRotulos[nCont]);
      lista.SetColumnWidth(nPos, nLargura[nCont]);
      nCont = nCont + 1;
    }
  }

  //---------------------------------------------------------------------------
  public void AdicionaLinhasGrid(wxListCtrl lista, ResultSet rsConsulta,
                                 int nQtdCol) {
    int nCol, nLinha;
    String sLinha = "";

    try {
      lista.DeleteAllItems();
      nLinha = 0;
      while (rsConsulta.next()) {
        for (nCol = 0; nCol < nQtdCol; nCol++) {
          sLinha = rsConsulta.getObject(nCol + 1).toString();
          if (nCol == 0) {
            lista.InsertItem(nLinha, sLinha);
          }
          else {
            lista.SetItem(nLinha, nCol, sLinha);
          }
        }
        nLinha++;
      }

    }
    catch (SQLException se) {
      wx.wxMessageBox(se.getMessage(), "Erro", wx.wxOK | wx.wxICON_ERROR);
    }
  }

}
