#include "resource.h"
#include "RotinasGlobais.h"

#include <sql.h>
#include <sqlext.h>

CONEXAO gConexao;
SQLHENV henv;
SQLHDBC hdbc;

Glib::ustring Rotinas_sBarraLogin;
Glib::ustring Rotinas_sUsuarioLogin;
Glib::ustring Rotinas_sUsuarioSenha;
Glib::ustring Rotinas_sCodigoSelecionado;
Glib::ustring Rotinas_sPreco;
Glib::ustring Rotinas_sQtdEstoque;
char * Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
/* char* Rotinas_sepDTHR = "'"; OUTROS BANCOS */

CRotinasGlobais * Rotinas = (CRotinasGlobais *) NULL;

CRotinasGlobais::CRotinasGlobais() { }

CRotinasGlobais::~CRotinasGlobais() { }

void CRotinasGlobais::MsgDlg(Glib::ustring sMensagem, Gtk::MessageType tipo) {

  Gtk::MessageDialog dialog(retUTF8(sMensagem),
   tipo, Gtk::BUTTONS_OK, true, false);
  dialog.set_position(Gtk::WIN_POS_CENTER);
  dialog.set_has_separator(false);
  dialog.run();
}

bool CRotinasGlobais::ValidaInteger(Glib::ustring sNum) {
  int nNumero;
  bool bret = false;

  if (sNum.length() > 0) {
    nNumero = atoi(sNum.c_str());
    if (nNumero > 0)
      bret = true;
    else {
      MsgDlg(STR_NUMINV, Gtk::MESSAGE_ERROR);
      bret = false;
    }
  } else
    bret = false;

  return bret;
}

bool CRotinasGlobais::ValidaFloat(Glib::ustring sNum) {
  double nNumero;
  char * fimptr[TAM_MAX_STR];
  bool bret = false;

  if (sNum.length() > 0) {
    nNumero = g_strtod(sNum.c_str(), fimptr);
    if (nNumero >= 0.01)
      bret = true;
    else {
      MsgDlg(STR_NUMINV, Gtk::MESSAGE_ERROR);
      bret = false;
    }
  } else
    bret = false;

  return bret;
}

Glib::ustring CRotinasGlobais::VirgulaParaPonto(Glib::ustring sNum,
 bool revertido) {
   int ncont;
   Glib::ustring sret;
   char sponto[2];
   char svirgula[2];

   if (revertido) {
     strcpy(sponto, ",");
     strcpy(svirgula, ".");
   } else {
     strcpy(sponto, ".");
     strcpy(svirgula, ",");
   }

   for (ncont = 0; ncont < abs(sNum.length()); ncont++) {
     if (sNum.substr(ncont,1) == svirgula)
       sret = sponto;
     else
       sret = sNum.at(ncont);
   }
   return sret;
}

int CRotinasGlobais::modulo11(Glib::ustring svalor, int ndig) {
  int ncont, nsoma, npos;
  int nvalor = 0;
  Glib::ustring stemp, slocal, sres;
  int nret = 0;

  ncont = 0;
  while (ncont < 11) {
    slocal = svalor.at(ncont) + slocal;
    ncont++;
  }
  nsoma = 0;
  if (ndig == 1)
    ncont = 2;
  else
    ncont = 1;
  npos = 2;
  while (ncont < 11) {
    sres = slocal.at(ncont);
    nvalor = atoi(sres.c_str());
    nsoma = nsoma + (nvalor * npos);
    ncont++;
    npos++;
  }
  nsoma = (11 - (nsoma % 11));

  if (nsoma > 9)
    nret = 0;
  else
    nret = nsoma;

  return nret;
}

bool CRotinasGlobais::ValidaCPF(Glib::ustring cpf) {
  Glib::ustring scpf;
  int nNum1 = 0;
  int nNum2 = 0;
  Glib::ustring sNum1, sNum2;
  bool bret = false;

  if (cpf.length() == 14) {
    scpf = cpf.substr(0, 3) + cpf.substr(4, 3) + cpf.substr(8, 3) +
     cpf.substr(12, 2);

    sNum1 = cpf.at(12);
    nNum1 = atoi(sNum1.c_str());
    sNum2 = cpf.at(13);
    nNum2 = atoi(sNum2.c_str());

    if ((modulo11(scpf, 1) == nNum1) && (modulo11(scpf, 2) == nNum2))
       bret = true;
    else
      bret = false;
  } else
    bret = false;

  return bret;
}

bool CRotinasGlobais::ValidaISBN(Glib::ustring isbn) {
  Glib::ustring sisbn, sdigito, snum;
  int nsoma, ncont;
  int nvalor = 0;
  bool bret = false;

  if (isbn.length() == 13) {
    sdigito = isbn.at(isbn.length()-1);
    sisbn.clear();
    for (ncont = 0; ncont < abs(isbn.length() - 1); ncont++) {
      if (isbn.substr(ncont,1) != "-")
        sisbn += isbn.substr(ncont,1);
    }

    if (sdigito == "X")
      nsoma = 10;
    else {
      nvalor = atoi(sdigito.c_str());
      nsoma = nvalor;
    }
    for (ncont = 1; ncont <= 9; ncont++) {
      snum = sisbn.substr(ncont-1,1);
      nvalor = atoi(snum.c_str());
      nsoma = nsoma + (nvalor * (11 - ncont));
    }
    if ((nsoma % 11) == 0)
      bret = true;
    else
      bret = false;
  } else
    bret = false;

  return bret;
}

bool CRotinasGlobais::validaDataHora(Glib::ustring sDataHora,
 bool bSoData) {
   bool bvalida, bdatavalida, bhoravalida;
   Glib::ustring sdia, smes, sano, shora, smin, sseg;
   int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

   bvalida = false;
   bdatavalida = false;
   bhoravalida = false;
   nudiames = 0;
   if (bSoData)
     ntam = 10;
   else
     ntam = 19;

   if (sDataHora.length() == ntam) {
     sdia = sDataHora.substr(0, 2);
     ndia = atoi(sdia.c_str());
     smes = sDataHora.substr(3, 2);
     nmes = atoi(smes.c_str());
     sano = sDataHora.substr(6, 4);
     nano = atoi(sano.c_str());

     if ((nano >= 1) && (nano <= 9999)) {
       if ((nmes >= 1) && (nmes <= 31)) {
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
               if ((nano % 4) == 0)
                 nudiames = 29;
               else
                 nudiames = 28;
             }
           break;
           case 4:
           case 6:
           case 9:
           case 11:
             nudiames = 30;
           break;
         }
         if ((ndia >= 1) && (ndia <= nudiames))
           bdatavalida = true;
       }
     }

     if (bSoData) {
       if (bdatavalida)
         bvalida = true; else
         bvalida = false;
     } else {
       if (bdatavalida) {
         shora = sDataHora.substr(11, 2);
         nhora = atoi(shora.c_str());
         smin = sDataHora.substr(14, 2);
         nmin = atoi(smin.c_str());
         sseg = sDataHora.substr(17, 2);
         nseg = atoi(sseg.c_str());

         if ((nhora >= 0) && (nhora <= 23)) {
           if ((nmin >= 0) && (nmin <= 59)) {
             if ((nseg >= 0) && (nseg <= 59))
               bhoravalida = true;
           }
         }

         if (bhoravalida)
           bvalida = true;
         else
           bvalida = false;
       } else
         bvalida = false;
     }
   } else
     bvalida = false;

   return bvalida;
}

Glib::ustring CRotinasGlobais::FormataDataHoraStr(struct tm * sTempo,
 Glib::ustring sFrmtData, Glib::ustring sFrmtHora) {
   char * sDataHora = (char *) malloc(TAM_MAX_STR);
   Glib::ustring sTemp;

   if (sFrmtData.length() > 0 && sFrmtHora.length() > 0)
     sTemp = sFrmtData + " " + sFrmtHora;
   else if (sFrmtData.length() > 0)
     sTemp = sFrmtData;
   else if (sFrmtHora.length() > 0)
     sTemp = sFrmtHora;

   strftime(sDataHora, TAM_MAX_STR, sTemp.c_str(), sTempo);
   sTemp = sDataHora;
   return sTemp;
}

Glib::ustring CRotinasGlobais::retDataHoraStr(bool bData, bool bHora) {
  Glib::ustring sDataHora;
  time_t agora;
  struct tm * sTempo;

  time(& agora);
  sTempo = localtime(& agora);

  if (bData && bHora)
    sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S");
  else if (bData)
    sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "");
  else if (bHora)
    sDataHora = FormataDataHoraStr(sTempo, "", "%H:%M:%S");

  return sDataHora;
}

Glib::ustring CRotinasGlobais::ConverteDataHoraStr(Glib::ustring sDTHR,
 bool DMY_ou_YMD, Glib::ustring sFrmtData, Glib::ustring sFrmtHora) {
   Glib::ustring sDataHora;
   struct tm sTempo;

   if (sFrmtData.length() > 0) {
     if (DMY_ou_YMD) {
       sTempo.tm_mday = atoi(sDTHR.substr(0, 2).c_str());
       sTempo.tm_mon = atoi(sDTHR.substr(3, 2).c_str());
       sTempo.tm_year = atoi(sDTHR.substr(6, 4).c_str());
     } else {
       sTempo.tm_year = atoi(sDTHR.substr(0, 4).c_str());
       sTempo.tm_mon = atoi(sDTHR.substr(5, 2).c_str());
       sTempo.tm_mday = atoi(sDTHR.substr(8, 2).c_str());
     }
     sTempo.tm_mon -= 1;
     sTempo.tm_year -= 1900;
   }

   if (sFrmtHora.length() > 0) {
     sTempo.tm_hour = atoi(sDTHR.substr(11, 2).c_str());
     sTempo.tm_min = atoi(sDTHR.substr(14, 2).c_str());
     sTempo.tm_sec = atoi(sDTHR.substr(17, 2).c_str());
   }

   sDataHora = FormataDataHoraStr(&sTempo, sFrmtData, sFrmtHora);
   return sDataHora;
}

Glib::ustring CRotinasGlobais::retLocale(Glib::ustring sTexto) {
  return Glib::locale_from_utf8(sTexto);
}

Glib::ustring CRotinasGlobais::retUTF8(Glib::ustring sTexto) {
  return Glib::locale_to_utf8(sTexto);
}

bool CRotinasGlobais::ConectaBanco(Glib::ustring sFonteDeDados,
 Glib::ustring sLogin, Glib::ustring sSenha) {
   SQLRETURN rc;

   gConexao = SQL_NULL_HSTMT;
   henv = SQL_NULL_HENV;
   hdbc = SQL_NULL_HDBC;

   // Aloca o ambiente ODBC e salva o manuseador.
   rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, & henv);

   if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
     // Faz o ODBC saber que esta é uma aplicação ODBC 3.0.
     rc = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION,
      (SQLPOINTER)SQL_OV_ODBC3, 0);

     if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
       /* Aloca o manuseador da conexão */
       rc = SQLAllocHandle(SQL_HANDLE_DBC, henv, & hdbc);

       if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
         /* Atribui login timeout para 5 segundos. */
         SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER)5, 0);

         /* Conecta na fonte de dados */
         rc = SQLConnect(hdbc, (SQLTCHAR *) sFonteDeDados.c_str(), SQL_NTS,
          (SQLTCHAR *) sLogin.c_str(), SQL_NTS, (SQLTCHAR *) sSenha.c_str(), SQL_NTS);

         if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
           /* Aloca manuseador do procedimento */
           rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, & gConexao);

           if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
             return true;
           } else
             SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
         } else
           SQLDisconnect(hdbc);
       } else
         SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
     }
   } else
     SQLFreeHandle(SQL_HANDLE_ENV, henv);

   return false;

}

void CRotinasGlobais::DisconectaBanco() {
  SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
  SQLDisconnect(hdbc);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

bool CRotinasGlobais::ConsultaDados(CONEXAO hstmtlocal, Glib::ustring sSql) {
  SQLRETURN rc;

  rc = SQLPrepare(hstmtlocal, (SQLTCHAR *) sSql.c_str(), SQL_NTS);
  if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
    MsgDlg(STR_NCPREPSQL, Gtk::MESSAGE_ERROR);
    return false;
  }
  rc = SQLExecute(hstmtlocal);
  if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
    MsgDlg(STR_NCEXECSQL, Gtk::MESSAGE_ERROR);
    return false;
  }
  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    rc = SQLFetch(hstmtlocal);
    if (rc == SQL_NO_DATA) {
      SQLCloseCursor(hstmtlocal);
      return false;
    } else {
      SQLCloseCursor(hstmtlocal);
      return true;
    }
  } else {
    SQLCloseCursor(hstmtlocal);
    return false;
  }
}

void CRotinasGlobais::arrumaColunas(CONEXAO hstmtlocal, char * sLinha[],
 SQLUSMALLINT nQtdCol) {
   SQLUSMALLINT nCol;
   SQLRETURN rc;
   SQLTCHAR sColNome[TAM_MAX_STR];
   SQLSMALLINT nColTipo;
   SQLSMALLINT nColEscala;
   SQLSMALLINT nColNula;
   SQLSMALLINT nColTam = TAM_MAX_STR;
   SQLUINTEGER nColPrecisao;

   for (nCol = 0; nCol < nQtdCol; nCol++) {
     rc = SQLDescribeCol(hstmtlocal, nCol + 1, sColNome, TAM_MAX_STR,
      & nColTam, & nColTipo, & nColPrecisao, & nColEscala, & nColNula);

     if (nColTipo == SQL_TYPE_TIMESTAMP) {
       strcpy(sLinha[nCol],
        ConverteDataHoraStr(sLinha[nCol], false, "%d/%m/%Y",
        "%H:%M:%S").c_str());
     }
   }
}

bool CRotinasGlobais::ConsultaDadosLista(CONEXAO hstmtlocal,
 LISTAMSTR * lstLocal, Glib::ustring sSql) {
   char * sLinha[QTD_MAX_COL];
   char sAux[TAM_MAX_STR];
   SQLRETURN rc;
   SQLINTEGER nLen;
   SQLUSMALLINT nCol, nQtdCol;

   rc = SQLPrepare(hstmtlocal, (SQLTCHAR *) sSql.c_str(), SQL_NTS);
   if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
     MsgDlg(STR_NCPREPSQL, Gtk::MESSAGE_ERROR);
     return false;
   }

   rc = SQLExecute(hstmtlocal);
   if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
     MsgDlg(STR_NCEXECSQL, Gtk::MESSAGE_ERROR);
     return false;
   }

   if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {

     if (!SQL_SUCCEEDED(SQLNumResultCols(hstmtlocal,
      (SQLSMALLINT *) & nQtdCol)))
        return false;

     for (nCol = 0; nCol < nQtdCol; nCol++) {
       sLinha[nCol] = (char *) malloc(TAM_MAX_STR);

       rc = SQLBindCol(hstmtlocal, nCol + 1, SQL_C_CHAR, sLinha[nCol],
        TAM_MAX_STR, & nLen);

       if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
         SQLCloseCursor(hstmtlocal);
         return false;
       }
     }

     rc = SQLFetch(hstmtlocal);
     if (rc != SQL_NO_DATA) {

       for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
         lstLocal->col[nCol].clear();

       while (rc != SQL_NO_DATA) {
         //SQLGetData(hstmtlocal, nCol+1, SQL_C_CHAR,
         //sLinha[nCol], TAM_MAX_STR, &nLen)

         arrumaColunas(hstmtlocal, sLinha, nQtdCol);
         for (nCol = 0; nCol < nQtdCol; nCol++) {
           strcpy(sAux, retUTF8(sLinha[nCol]).c_str());
           lstLocal->col[nCol].push_back(sAux);
         }
         rc = SQLFetch(hstmtlocal);
       }
       SQLCloseCursor(hstmtlocal);
       return true;
     } else {
       SQLCloseCursor(hstmtlocal);
       return false;
     }
   } else
     return false;
}

bool CRotinasGlobais::AtualizaDados(CONEXAO hstmtlocal, Glib::ustring sSql) {
  SQLRETURN rc;

  rc = SQLPrepare(hstmtlocal, (SQLTCHAR *) retLocale(sSql).c_str(), SQL_NTS);
  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    rc = SQLExecute(hstmtlocal);
    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
      return true;
    else {
      //MsgDlg(STR_NCEXECSQL, Gtk::MESSAGE_ERROR);
      return false;
    }
  } else {
    MsgDlg(STR_NCPREPSQL, Gtk::MESSAGE_ERROR);
    return false;
  }
}

bool CRotinasGlobais::ValidaCampo(Glib::ustring sCampo,
 Glib::ustring sMensagemErro) {
   if (sCampo.length() == 0) {
     MsgDlg(sMensagemErro, Gtk::MESSAGE_ERROR);
     return true;
   } else
     return false;
}

Glib::ustring CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR * Campos,
 Glib::ustring sCampoCodigo, bool bValidaInt, Glib::ustring sTextoSql,
 Glib::ustring sMensagemErro) {
   if (bValidaInt) {
     if (!ValidaInteger(sCampoCodigo))
       return "";
   }
   if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {
     return Campos->col[1][0];
   } else {
     MsgDlg(sMensagemErro, Gtk::MESSAGE_ERROR);
     return "";
   }
}

Glib::RefPtr<Gtk::ListStore> CRotinasGlobais::CriaModeloGrid(
  Gtk::TreeView * grid) {
  Glib::RefPtr<Gtk::ListStore> gListaGrid;

  gListaGrid = Gtk::ListStore::create(modeloGrid);
  grid->set_model(gListaGrid);
  return gListaGrid;
}

void CRotinasGlobais::LimpaModeloGrid(Glib::RefPtr<Gtk::ListStore> gListaGrid) {
  gListaGrid->clear();
}

void CRotinasGlobais::AdicionaLinhasGrid(Glib::RefPtr<Gtk::ListStore> gListaGrid,
 LISTAMSTR * lstLinhas, int nQtdCols, bool bLimparGrid) {
   Gtk::TreeIter iter;
   Gtk::TreeRow tLinha;
   int nCol, nLinha, nQtdLinhas;

   if (bLimparGrid)
     gListaGrid->clear();

   nQtdLinhas = lstLinhas->col[0].size();
   for (nLinha = 0; nLinha < nQtdLinhas; nLinha++) {

     tLinha = *(gListaGrid->append());
     tLinha[modeloGrid.nCol] = nLinha + 1;

     for (nCol = 0; nCol < nQtdCols; nCol++) {
       if (nCol > (nQtdCols - 1))
         tLinha[modeloGrid.sCol[nCol]] = "";
       else
         tLinha[modeloGrid.sCol[nCol]] = lstLinhas->col[nCol][nLinha];
     }
   }
}

void CRotinasGlobais::AdicionaColunasGrid(Gtk::TreeView * grid, int nPosIni,
 int nQtdCols, int nLargura[], Glib::ustring sRotulos[]) {
   Gtk::TreeViewColumn * gColuna;
   int nCol;

   gColuna = new Gtk::TreeViewColumn("", modeloGrid.nCol);
   gColuna->set_visible(false);
   grid->append_column(*gColuna);

   for (nCol = nPosIni; nCol < QTD_MAX_COL; nCol++) {
     if (nCol > (nPosIni + nQtdCols - 1)) {
       gColuna = new Gtk::TreeViewColumn("", modeloGrid.sCol[nCol]);
       gColuna->set_visible(false);
     } else {
       gColuna = new Gtk::TreeViewColumn(sRotulos[nCol], modeloGrid.sCol[nCol]);
       gColuna->set_resizable(true);
       gColuna->set_fixed_width(nLargura[nCol]);
       gColuna->set_sort_column_id(nCol);
     }
     grid->append_column(*gColuna);
   }
}

bool CRotinasGlobais::PesquisaContaItemGrid(
  Glib::RefPtr<Gtk::ListStore> gListaGrid, Glib::ustring sItem,
  int * nQtdLinhas) {
   int nCont;
   Glib::ustring sSelecionado;
   bool bret = false;

   (* nQtdLinhas) = gListaGrid->children().size();
   if (!gListaGrid->children().empty()) {
     for (nCont=0; nCont < gListaGrid->children().size(); nCont++) {
       gListaGrid->children()[nCont].get_value(1, sSelecionado);
       if ( sItem == sSelecionado)
         bret = true;
     }
   }
   return bret;
}

void CRotinasGlobais::AdicionaItemLista(Glib::RefPtr<Gtk::ListStore> gListaGrid,
 Gtk::Entry * sCampoCodigo, Gtk::Entry * sCampoDesc) {
   LISTAMSTR lstLinhas;
   char sTemp[TAM_MAX_STR];
   Glib::ustring sItems, sCodigo, sDesc;
   int nQtdLinhas = 0;

   sCodigo = sCampoCodigo->get_text();
   sDesc = sCampoDesc->get_text();

   if (sDesc.length() > 0) {
     sItems = sCodigo + " - " + sDesc;

     if (PesquisaContaItemGrid(gListaGrid, sItems, &nQtdLinhas) == false) {

        strcpy(sTemp, sItems.c_str());
        lstLinhas.col[0].push_back(sTemp);

        strcpy(sTemp, sCodigo.c_str());
        lstLinhas.col[1].push_back(sTemp);

        AdicionaLinhasGrid(gListaGrid, &lstLinhas, 2, false);
     }
     sCampoCodigo->set_text("");
     sCampoDesc->set_text("");
   }
}

void CRotinasGlobais::RemoveItemLista(Gtk::TreeView * lstLista,
  Glib::RefPtr<Gtk::ListStore> gListaGrid) {
  Glib::RefPtr<Gtk::TreeSelection> selection = lstLista->get_selection();

  if (const Gtk::TreeIter iter = selection->get_selected()) {
    gListaGrid->erase(iter);
  }
}

void CRotinasGlobais::AdicionaValoresLista(Glib::ustring sTextoSql,
 Glib::RefPtr<Gtk::ListStore> gListaGrid) {
   char sTemp[TAM_MAX_STR];
   LISTAMSTR Campos, lstLinhas;
   Glib::ustring sItems, sCodigo, sDesc;
   int nLinha;

   LimpaModeloGrid(gListaGrid);
   if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
     for (nLinha = 0; nLinha < abs(Campos.col[0].size()); nLinha++) {
       sCodigo = Campos.col[0][nLinha];
       sDesc = Campos.col[1][nLinha];

       strcpy(sTemp, sCodigo.c_str());
       lstLinhas.col[1].push_back(sTemp);

       sItems =  sCodigo + " - " + sDesc;
       strcpy(sTemp, sItems.c_str());
       lstLinhas.col[0].push_back(sTemp);
     }
     AdicionaLinhasGrid(gListaGrid, &lstLinhas, 2, true);
   }
}

