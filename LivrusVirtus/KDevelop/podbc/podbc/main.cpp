
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <sql.h>
#include <sqlext.h>

#define QTD_MAX_COL 20
#define TAM_MAX_STR 256

SQLHSTMT hstmt;
SQLHENV  henv;
SQLHDBC  hdbc;

char *Rotinas_alocaString(int ntam)
{ char *strlocal;

 strlocal = (char*)malloc(ntam);
 return strlocal;
}

bool Rotinas_ConectaBanco(char *sFonteDeDados, char *sLogin, char *sSenha)
{
SQLRETURN rc;

hstmt = SQL_NULL_HSTMT;
henv  = SQL_NULL_HENV;
hdbc  = SQL_NULL_HDBC;

// Aloca o ambiente ODBC e salva o manuseador.
rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
  // Faz o ODBC saber que esta é uma aplicação ODBC 3.0.
  rc = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0);

  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    /* Aloca o manuseador da conexão */
    rc = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc);

    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
      /* Atribui login timeout para 5 segundos. */
      SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER) 5, 0);

      /* Conecta na fonte de dados */
      rc = SQLConnect(hdbc, (SQLTCHAR*) sFonteDeDados, SQL_NTS,
               (SQLTCHAR*) sLogin, SQL_NTS, (SQLTCHAR*) sSenha, SQL_NTS);

      if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO){
        /* Aloca manuseador do procedimento */
        rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &hstmt);

		if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
          return true;
		} else
          SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
	  } else
          SQLDisconnect(hdbc);
	} else
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  }
} else
    SQLFreeHandle(SQL_HANDLE_ENV, henv);

return false;

}

void Rotinas_DisconectaBanco()
{
  SQLFreeHandle(SQL_HANDLE_STMT, hstmt);
  SQLDisconnect(hdbc);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

bool Rotinas_ConsultaDados(SQLHSTMT hstmtlocal, char *sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql, SQL_NTS);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  //MessageBox(0, Rotinas_lerStr(STR_NCPREPSQL), "Erro", MB_ICONERROR | MB_OK);
  printf("%s\n","Não consigo preparar o SQL");
  return false;
}
rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  //MessageBox(0, Rotinas_lerStr(STR_NCEXECSQL), "Erro", MB_ICONERROR | MB_OK);
  printf("%s\n","Não consigo executar o SQL");
  return false;
}
if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
  rc = SQLFetch(hstmtlocal);
  if ( rc == SQL_NO_DATA ) {
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

bool Rotinas_ConsultaDadosLista(SQLHSTMT hstmtlocal, char *sSql)
                                //LISTAMSTR *lstLocal, LPTSTR sSql)
{
char *sLinha[QTD_MAX_COL];
SQLRETURN   rc;
SQLINTEGER  nLen;
SQLUSMALLINT  nCol, nQtdCol;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql, SQL_NTS);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  //MessageBox(0, Rotinas_lerStr(STR_NCPREPSQL), "Erro", MB_ICONERROR | MB_OK);
  printf("%s\n","Não consigo preparar o SQL");
  return false;
}

rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  //MessageBox(0, Rotinas_lerStr(STR_NCEXECSQL), "Erro", MB_ICONERROR | MB_OK);
  printf("%s\n","Não consigo executar o SQL");
  return false;
}

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {

    if (!SQL_SUCCEEDED(SQLNumResultCols(hstmtlocal, (SQLSMALLINT*) &nQtdCol)))
      return false;

	for (nCol = 0; nCol < nQtdCol; nCol++) {
	  sLinha[nCol] = Rotinas_alocaString(TAM_MAX_STR);

  	  rc = SQLBindCol(hstmtlocal, nCol+1, SQL_C_CHAR,
		  sLinha[nCol], TAM_MAX_STR, &nLen);

	  if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
	    SQLCloseCursor(hstmtlocal);
	    return false;
	  }
	}

    rc = SQLFetch(hstmtlocal);
   	if ( rc != SQL_NO_DATA ) {
    	//*lstLocal = ListaStr_iniciaM();
    	while ( rc != SQL_NO_DATA ) {
		  /*SQLGetData(hstmtlocal, nCol+1, SQL_C_CHAR,
			sLinha[nCol], TAM_MAX_STR, &nLen)*/

			//Rotinas_arrumaColunas(hstmtlocal, sLinha, nQtdCol);

			//ListaStr_insereFimM(lstLocal, sLinha);
        printf("Cod = %s, Ass = %s\n",sLinha[0], sLinha[1]);

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

int main(int argc, char* argv[])
{
 // if (Rotinas_ConectaBanco("mylivrus", "root", ""))
  if (Rotinas_ConectaBanco("pglivrus", "hfs", ""))
    Rotinas_ConsultaDadosLista(hstmt, "select * from assunto");
  else
    cout << "Nao conecta banco!" << endl;
    
  Rotinas_DisconectaBanco();

//	return 0;
  return EXIT_SUCCESS;
}

