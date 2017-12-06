#include "Livrus.h"
#include "Principal.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"

string Rotinas_sUsuarioLogin;
string Rotinas_sUsuarioSenha;
string Rotinas_sCodigoSelecionado;
string Rotinas_sPreco;
string Rotinas_sQtdEstoque;
string Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
//string Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

CONEXAO gConexao;
SQLHENV  henv;
SQLHDBC  hdbc;

CRotinasGlobais *Rotinas;

CRotinasGlobais::CRotinasGlobais() {
}

char* CRotinasGlobais::alocaString(int ntam)
{ char *strlocal;

 strlocal = (char*) malloc(ntam);
 strlocal[0]='\0';
 return strlocal;
}

char* CRotinasGlobais::trim(const char *sTexto) {
int ncont, npos, nPosIni, nPosFim;
char *sret = Rotinas->alocaString(TAM_MAX_STR);

  nPosIni = 0;
  for (ncont=0; abs(ncont) < strlen(sTexto); ncont++) {
    if (sTexto[ncont]==' ')
      nPosIni++;
    else
      break;    
  }
  nPosFim = (strlen(sTexto)-1);
  for (ncont=(strlen(sTexto)-1); ncont >= 0 ; ncont--) {
    if (sTexto[ncont]==' ')
      nPosFim--;
    else
      break;
  }
  ncont = 0;
  for (npos=nPosIni; npos <= nPosFim; npos++) {
    sret[ncont] = sTexto[npos];
    ncont++;
  }
  sret[ncont]='\0';

return sret;
}

bool CRotinasGlobais::ValidaFloat(string sNum)
{
 if (sNum.length() > 0) {    
    if (atof(sNum.c_str()) >= 0.01)
      return true;
    else {
      fl_alert(STR_NUMINV);
      return false;
    }
 } else
   return false;
} 

char *CRotinasGlobais::VirgulaParaPonto(char *sNum, bool bRevertido) 
{
int ncont;
char *sret = Rotinas->alocaString(TAM_MAX_STR);
char sponto[2], svirgula[2];

if (bRevertido) {
  strcpy(sponto, ",");
  strcpy(svirgula, ".");
} else {
  strcpy(sponto, ".");
  strcpy(svirgula, ",");
}

for (ncont=0; abs(ncont) < strlen(sNum); ncont++) {
  if (sNum[ncont] == svirgula[0])
    sret[ncont] = sponto[0];
  else 
    sret[ncont] = sNum[ncont];
}
sret[strlen(sNum)]='\0';
return sret;
}

int CRotinasGlobais::modulo11(string svalor, int ndig) {
int ncont, nsoma, nvalor, npos;
string slocal, sres;

 ncont=0;
 while (ncont < 11) {
   slocal=svalor.substr(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres = slocal.substr(ncont,1);
   nvalor = atoi(sres.c_str());
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

bool CRotinasGlobais::validaCPF(string cpf) {
string scpf;
  
if (cpf.length()==14) {	
  scpf=cpf.substr(0,3) + cpf.substr(4,3)+cpf.substr(8,3)+cpf.substr(12,2);
  if ( (modulo11(scpf,1)==atoi(cpf.substr(12,1).c_str())) &&
  (modulo11(scpf,2)==atoi(cpf.substr(13,1).c_str())) )
    return true;
  else
  	return false;
} else
  return false;
}

bool CRotinasGlobais::validaISBN(string isbn) {
 string sisbn, sdigito, snum;
 int nvalor, nsoma, ncont;

if (isbn.length()==13) {
  sdigito = isbn.substr(isbn.length()-1, 1);
  sisbn="";
  for(ncont = 0; ncont < abs(isbn.length()-1); ncont++)  {
    if (isbn.substr(ncont,1)!="-")
      sisbn = sisbn + isbn.substr(ncont,1);
  }
  if (sdigito=="X")
    nsoma = 10;
  else {
    nvalor = atoi(sdigito.c_str());
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.substr(ncont-1, 1);
    nvalor = atoi(snum.c_str());
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    return true;
  else
    return false;
} else
  return false;
}

bool CRotinasGlobais::validaDataHora(string sDataHora, bool bSoData)
{ bool bvalida, bdatavalida, bhoravalida;
  string sdia, smes, sano, shora, smin, sseg;
  int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;

  if (sDataHora.length()==abs(ntam)) {
    sdia = sDataHora.substr(0,2);
    ndia = atoi(sdia.c_str());
    smes = sDataHora.substr(3,2);
    nmes = atoi(smes.c_str());
    sano = sDataHora.substr(6,4);
    nano = atoi(sano.c_str());
  
    if ((nano >= 1) && (nano <= 9999)) {
      if ((nmes >= 1) && (nmes <= 31)) {
          switch(nmes) {
           case 1: case 3: case 5: case 7: case 8: 
           case 10: case 12: nudiames = 31; break;
           case 2: {
               /* ano bissexto */
               if ((nano % 4)==0) nudiames = 29;
               else nudiames = 28;
              } break;
           case 4: case 6: case 9: case 11: nudiames = 30; break;
          }
          if ((ndia >=1) && (ndia <=nudiames))
             bdatavalida = true;
      }
    }
  
    if (bSoData) {
       if (bdatavalida) 
         bvalida = true;
       else 
         bvalida = false;
    } else {
      if (bdatavalida) {
          shora = sDataHora.substr(11,2);
          nhora = atoi(shora.c_str());
          smin = sDataHora.substr(14,2);
          nmin = atoi(smin.c_str());
          sseg = sDataHora.substr(17,2);
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

char* CRotinasGlobais::FormataDataHoraStr(struct tm* sTempo, 
  string sFrmtData, string sFrmtHora) {
char *sDataHora = alocaString(TAM_MAX_STR);
string sTemp;

if (sFrmtData.length() > 0 && sFrmtHora.length() > 0)
  sTemp = sFrmtData + " " + sFrmtHora;
else if (sFrmtData.length() > 0)
  sTemp = sFrmtData;
else if (sFrmtHora.length() > 0)
  sTemp = sFrmtHora;

strftime(sDataHora, TAM_MAX_STR, sTemp.c_str(), sTempo);
return sDataHora;
}

char* CRotinasGlobais::retDataHoraStr(bool bData, bool bHora)
{ char* sDataHora = alocaString(TAM_MAX_STR);
  time_t agora;   
  struct tm* sTempo;

  time(&agora);
  sTempo = localtime(&agora); 

if (bData && bHora)
  strcpy(sDataHora, FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S"));
else if (bData)
  strcpy(sDataHora, FormataDataHoraStr(sTempo, "%d/%m/%Y", ""));
else if (bHora)
  strcpy(sDataHora, FormataDataHoraStr(sTempo, "", "%H:%M:%S"));

return sDataHora;
}

char* CRotinasGlobais::ConverteDataHoraStr(string sDTHR, 
  bool DMY_ou_YMD, string sFrmtData, string sFrmtHora)
{ char* sDataHora = alocaString(TAM_MAX_STR);
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

sDataHora = FormataDataHoraStr(&sTempo,sFrmtData,sFrmtHora);

return sDataHora;
}

bool CRotinasGlobais::ConectaBanco(string sFonteDeDados, string sLogin, string sSenha)
{
SQLRETURN rc;

gConexao = SQL_NULL_HSTMT;
henv  = SQL_NULL_HENV;
hdbc  = SQL_NULL_HDBC;

// Aloca o ambiente ODBC e salva o manuseador.
rc = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &henv);

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
  // Faz o ODBC saber que esta � uma aplica��o ODBC 3.0.
  rc = SQLSetEnvAttr(henv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER) SQL_OV_ODBC3, 0); 

  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    /* Aloca o manuseador da conex�o */
    rc = SQLAllocHandle(SQL_HANDLE_DBC, henv, &hdbc); 

    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
      /* Atribui login timeout para 5 segundos. */
      SQLSetConnectAttr(hdbc, SQL_LOGIN_TIMEOUT, (SQLPOINTER) 5, 0);

      /* Conecta na fonte de dados */
      rc = SQLConnect(hdbc, (SQLTCHAR*) sFonteDeDados.c_str(), SQL_NTS,
      (SQLTCHAR*) sLogin.c_str(), SQL_NTS, (SQLCHAR*) sSenha.c_str(), SQL_NTS);

      if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO){
        /* Aloca manuseador do procedimento */
        rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &gConexao); 
	
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

void CRotinasGlobais::DisconectaBanco()
{
  SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
  SQLDisconnect(hdbc);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

bool CRotinasGlobais::ConsultaDados(CONEXAO hstmtlocal, string sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.c_str(), SQL_NTS);   
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  fl_alert(STR_NCPREPSQL);
  return false;
}   
rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  fl_alert(STR_NCEXECSQL);
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

void CRotinasGlobais::arrumaColunas(CONEXAO  hstmtlocal, char *sLinha[],
				 SQLUSMALLINT nQtdCol)
{
SQLUSMALLINT  nCol;
SQLRETURN   rc;
SQLCHAR   sColNome[TAM_MAX_STR];
SWORD     nColTipo;
SWORD     nColEscala;
SWORD     nColNula;
SWORD     nColTam = TAM_MAX_STR;
UDWORD    nColPrecisao;

   for (nCol = 0; nCol < nQtdCol; nCol++) {	
	  rc = SQLDescribeCol(hstmtlocal, nCol+1, sColNome, TAM_MAX_STR, 
	  &nColTam, &nColTipo, &nColPrecisao, &nColEscala, &nColNula);
		  	  
	  if (nColTipo == SQL_TYPE_TIMESTAMP) {
      strcpy(sLinha[nCol], ConverteDataHoraStr(sLinha[nCol], false, 
                                      "%d/%m/%Y", "%H:%M:%S"));
	 }
	  /*
	 else if (nColTipo == SQL_DECIMAL || nColTipo == SQL_DOUBLE 
		 || nColTipo == SQL_FLOAT)
		 sLinha[nCol] = VirgulaParaPonto(sLinha[nCol], false);*/
   }
}

bool CRotinasGlobais::ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, string sSql)
{
char *sLinha[QTD_MAX_COL];
SQLRETURN   rc;
SQLINTEGER  nLen;
SQLUSMALLINT  nCol, nQtdCol;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.c_str(), SQL_NTS);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  fl_alert(STR_NCPREPSQL);
  return false;
}   

rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  fl_alert(STR_NCEXECSQL);
  return false;
}

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {

  if (!SQL_SUCCEEDED(SQLNumResultCols(hstmtlocal, (SQLSMALLINT*) &nQtdCol)))
      return false;
  
	for (nCol = 0; nCol < QTD_MAX_COL; nCol++)
  	  sLinha[nCol] = alocaString(TAM_MAX_STR);

  for (nCol = 0; nCol < nQtdCol; nCol++) {	  
  	  rc = SQLBindCol(hstmtlocal, nCol+1, SQL_C_CHAR, 
		  sLinha[nCol], TAM_MAX_STR, &nLen);

	  if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
	    SQLCloseCursor(hstmtlocal);
	    return false;
	  }
	}
	
    rc = SQLFetch(hstmtlocal);
   	if ( rc != SQL_NO_DATA ) {	
    	*lstLocal = ListaStr->iniciaM();      
    	while ( rc != SQL_NO_DATA ) {				
        /*SQLGetData(hstmtlocal, nCol+1, SQL_C_CHAR, 
        sLinha[nCol], TAM_MAX_STR, &nLen)*/

        arrumaColunas(hstmtlocal, sLinha, nQtdCol);        
        ListaStr->insereFimM(lstLocal, sLinha);

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


bool CRotinasGlobais::AtualizaDados(CONEXAO hstmtlocal, string sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.c_str(), SQL_NTS);
  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    rc = SQLExecute(hstmtlocal);
    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
      return true;
    else {
     //fl_alert(STR_NCEXECSQL);
     return false;      
    }  
  } else {
    fl_alert(STR_NCPREPSQL);
    return false;
  }   
}

bool CRotinasGlobais::ValidaCampo(string sCampo, string sMensagemErro)
{
  if (sCampo.length()==0) {
    fl_alert(sMensagemErro.c_str());
  	return true;
  } else
	  return false;
}

string CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR *Campos, 
            string sTextoSql, string sMensagemErro)
{
  if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {  	
    return ListaStr->pesquisaItemOrdM((*Campos),1,0);
  } else {
	  fl_alert(sMensagemErro.c_str());
    return "";
  }
}

bool CRotinasGlobais::VerificaItemLista(Fl_Browser *lstLista, string sItem) {
int nLinha;
bool bret = false;

  for (nLinha = 1; nLinha <= lstLista->size(); nLinha++) {
    if (strcmp(lstLista->text(nLinha), sItem.c_str())==0)
      bret = true;
    else
      bret = false;
  }
  return bret;
}

void CRotinasGlobais::AdicionaItemLista(Fl_Browser *lstLista,
     LISTASTR *slCodLista, Fl_Input *sCampoCodigo, Fl_Input *sCampoDesc)
{
string sItems, sCodigo, sDesc;

if (strlen(sCampoDesc->value()) > 0) {

 sCodigo = sCampoCodigo->value();
 sDesc = sCampoDesc->value();

 sItems = sCodigo + " - " + sDesc;

 if (VerificaItemLista(lstLista, sItems)==false) { 
 	 ListaStr->insereFim(slCodLista, (char*)sCodigo.c_str()); 
   sItems = "@f" + sItems;
   lstLista->add(sItems.c_str());
 }
 sCampoCodigo->value("");
 sCampoDesc->value("");
}

}

void CRotinasGlobais::RemoveItemLista(Fl_Browser *lstLista, 
                                      LISTASTR *slCodLista)
{
int nSelIndice;

 if (lstLista->size() > 0) {   
   nSelIndice = lstLista->value();
   if (nSelIndice > 0) {
	   ListaStr->removeItemOrd(slCodLista, nSelIndice, true);
	   lstLista->remove(nSelIndice);
   }	
 }
}

void CRotinasGlobais::AdicionaValoresLista(string sTextoSql, 
                      Fl_Browser *lstLista, LISTASTR *slCodLista)
{
  LISTAMSTR Campos, local;
  string sItems, sCodigo;

  lstLista->clear();
  (*slCodLista) = ListaStr->inicia();

  if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
	  for (local = Campos; local != NULL; local = local->proximo) {	
	    ListaStr->insereFim(slCodLista, local->str[0]);
	    sItems = "@f";
      sItems = sItems + local->str[0] + " - " + local->str[1];
      lstLista->add(sItems.c_str());
      sItems = "";
	  }      
    ListaStr->liberaM(Campos);
    ListaStr->liberaM(local);   
    lstLista->select(1);
  }
}

string CRotinasGlobais::setLargura(string sTexto, int nTam) {
unsigned int ncont;
string sret = "";

  if ((nTam-sTexto.length()) > 0) {
    for(ncont = 0; ncont < nTam-sTexto.length(); ncont++)
      sret = sret + " ";
  }
  sret = sTexto + sret;
  return sret;
}

void CRotinasGlobais::AdicionaLinhasBrowser(Fl_Browser *browser, 
  LISTAMSTR sLinhas, int nQtdCol, int nLarguras[], string sRotulos[]) {
LISTAMSTR local;
string sTemp;
int nCol;

  browser->clear();
  for (nCol = 0; nCol < nQtdCol; nCol++) {
    if (nCol == 0)
      sTemp = setLargura(sRotulos[nCol], nLarguras[nCol]);
    else
      sTemp = sTemp + "|" + setLargura(sRotulos[nCol], nLarguras[nCol]);
  }
  sTemp = "@f@b@_" + sTemp;
  browser->add(sTemp.c_str());

  for (local = sLinhas; local != NULL; local = local->proximo) {
    for (nCol = 0; nCol < nQtdCol; nCol++) {
      if (nCol == 0)
        sTemp = setLargura(local->str[nCol], nLarguras[nCol]);
      else
        sTemp = sTemp + "|" + setLargura(local->str[nCol], nLarguras[nCol]);
    }
    sTemp = "@f" + sTemp;
    browser->add(sTemp.c_str());
  }
  browser->select(2);
}

