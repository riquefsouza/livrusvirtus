#include "resource.h"
#include "RotinasGlobais.h"
#include "Principal.h"

#include <sql.h>
#include <sqlext.h>

CONEXAO  gConexao;
SQLHENV  henv;
SQLHDBC  hdbc;

wxString Rotinas_sBarraLogin;
wxString Rotinas_sUsuarioLogin;
wxString Rotinas_sUsuarioSenha;
wxString Rotinas_sCodigoSelecionado;
wxString Rotinas_sPreco;
wxString Rotinas_sQtdEstoque;
wxString Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
//wxString Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

CRotinasGlobais *Rotinas = (CRotinasGlobais *) NULL;

CRotinasGlobais::CRotinasGlobais() { }

CRotinasGlobais::~CRotinasGlobais() { }

bool CRotinasGlobais::ValidaFloat(wxString sNum) {
double nNum;
bool bret = false;

 if (sNum.Len() > 0) {        
   if (sNum.ToDouble(&nNum)) {
      if (nNum >= 0.01)
        bret = true;
      else {
        wxMessageBox(wxT(STR_NUMINV), wxT("Erro"), wxOK | wxICON_ERROR);
        bret = false;
      }
   } else {
      wxMessageBox(wxT(STR_NUMINV), wxT("Erro"), wxOK | wxICON_ERROR);
      bret = false;
    }
 } else
   bret = false;

 return bret;
} 

wxString CRotinasGlobais::VirgulaParaPonto(wxString sNum, bool bRevertido) {

 if (bRevertido)
   sNum.Replace(wxT("."),wxT(","),true);
 else
   sNum.Replace(wxT(","),wxT("."),true);

 return sNum;
}

int CRotinasGlobais::modulo11(wxString svalor, int ndig) {
int ncont, nsoma, npos;
long nvalor = 0;
wxString slocal, sres;
int nret = 0;

 ncont=0;
 while (ncont < 11) {
   slocal=svalor.Mid(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres = slocal.Mid(ncont,1);
   sres.ToLong(&nvalor,10);

   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   nret = 0;
 else
   nret = nsoma;

 return nret;
}

bool CRotinasGlobais::validaCPF(wxString cpf) {
wxString scpf;
long nNum1 = 0;
long nNum2 = 0;
wxString sNum1, sNum2;
bool bret = false;

if (cpf.Length()==14) {
  scpf = wxString::Format("%s%s%s%s", cpf.Mid(0,3).c_str(),
    cpf.Mid(4,3).c_str(),cpf.Mid(8,3).c_str(),cpf.Mid(12,2).c_str());
  sNum1 = cpf.Mid(12,1);
  sNum1.ToLong(&nNum1, 10);
  sNum2 = cpf.Mid(13,1);
  sNum2.ToLong(&nNum2, 10);
  if ( (modulo11(scpf,1)==nNum1) && (modulo11(scpf,2)==nNum2) )
    bret = true;
  else
    bret = false;
} else
  bret = false;

return bret;
}

bool CRotinasGlobais::validaISBN(wxString isbn) {
 wxString sisbn, sdigito, snum;
 int nsoma, ncont;
 long nvalor = 0;
 bool bret = false;

if (isbn.Length()==13) {
  sdigito = isbn.substr(isbn.Length()-1, 1);
  sisbn.Clear();
  for(ncont = 0; ncont < abs(isbn.length()-1); ncont++)  {
    if (isbn.Mid(ncont,1).Cmp(wxT("-"))!=0)
      sisbn += isbn.Mid(ncont,1);
  }
  if (sdigito.Cmp(wxT("X"))==0)
    nsoma = 10;
  else {
    sdigito.ToLong(&nvalor,10);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.Mid(ncont-1, 1);
    snum.ToLong(&nvalor,10);
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    bret = true;
  else
    bret = false;
} else
  bret = false;

 return bret;
}

bool CRotinasGlobais::validaDataHora(wxString sDataHora, bool bSoData)
{ bool bvalida, bdatavalida, bhoravalida;
  wxString sdia, smes, sano, shora, smin, sseg;
  unsigned long ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;

  if (sDataHora.Len()==ntam) {
    sdia = sDataHora.Mid(0,2);
    sdia.ToULong(&ndia);
    smes = sDataHora.Mid(3,2);
    smes.ToULong(&nmes);
    sano = sDataHora.Mid(6,4);
    sano.ToULong(&nano);
  
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
          shora = sDataHora.Mid(11,2);
          shora.ToULong(&nhora);
          smin = sDataHora.Mid(14,2);
          smin.ToULong(&nmin);
          sseg = sDataHora.Mid(17,2);
          sseg.ToULong(&nseg);
  
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

wxString CRotinasGlobais::FormataDataHoraStr(wxDateTime sTempo, 
  wxString sFrmtData, wxString sFrmtHora)
{ wxString sDataHora;

if (sFrmtData.Len() > 0 && sFrmtHora.Len() > 0)
  sDataHora = sTempo.Format(sFrmtData + " " + sFrmtHora);
else if (sFrmtData.Len() > 0)
  sDataHora = sTempo.Format(sFrmtData);
else if (sFrmtHora.Len() > 0)
  sDataHora = sTempo.Format(sFrmtHora);

  return sDataHora;
}

wxString CRotinasGlobais::retDataHoraStr(bool bData, bool bHora)
{ wxString sDataHora;
  wxDateTime sTempo = wxDateTime::Now();

if (bData && bHora)
  sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S");
else if (bData)
  sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "");
else if (bHora)
  sDataHora = FormataDataHoraStr(sTempo, "", "%H:%M:%S");

return sDataHora;
}

wxString CRotinasGlobais::ConverteDataHoraStr(wxString sDTHR, bool DMY_ou_YMD, 
  wxString sFrmtData, wxString sFrmtHora)
{ wxString sDataHora;
  wxDateTime mTempo;
  unsigned long ndia = 1, nmes = 0, nano = 1, nhora = 0, nmin = 0, nseg = 0;

if (sFrmtData.Len() > 0) {
  if (DMY_ou_YMD) {
    sDTHR.Mid(0,2).ToULong(&ndia,10);
    sDTHR.Mid(3,2).ToULong(&nmes,10);
    sDTHR.Mid(6,4).ToULong(&nano,10);
  } else {
    sDTHR.Mid(0,4).ToULong(&nano,10);
    sDTHR.Mid(5,2).ToULong(&nmes,10);
    sDTHR.Mid(8,2).ToULong(&ndia,10);
  }
}
if (sFrmtHora.Len() > 0) {
  sDTHR.Mid(11,2).ToULong(&nhora,10);
  sDTHR.Mid(14,2).ToULong(&nmin,10);
  sDTHR.Mid(17,2).ToULong(&nseg,10);
}
mTempo.Set(ndia, wxDateTime::Month(nmes-1), nano, nhora, nmin, nseg, 0);
sDataHora = FormataDataHoraStr(mTempo,sFrmtData,sFrmtHora);
return sDataHora;
}

bool CRotinasGlobais::ConectaBanco(wxString sFonteDeDados, wxString sLogin, wxString sSenha)
{
SQLRETURN rc;

gConexao = SQL_NULL_HSTMT;
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
      rc = SQLConnect(hdbc, (SQLTCHAR*) sFonteDeDados.c_str(), SQL_NTS,
               (SQLTCHAR*) sLogin.c_str(), SQL_NTS, 
               (SQLCHAR*) sSenha.c_str(), SQL_NTS);

      if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO){
        /* Aloca manuseador do procedimento */
        rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, &gConexao); 
	
        if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
          return TRUE; 
	} else
          SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
      } else
          SQLDisconnect(hdbc);
    } else
        SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  }
} else
    SQLFreeHandle(SQL_HANDLE_ENV, henv);

return FALSE;

}

void CRotinasGlobais::DisconectaBanco()
{
  SQLFreeHandle(SQL_HANDLE_STMT, gConexao);
  SQLDisconnect(hdbc);
  SQLFreeHandle(SQL_HANDLE_DBC, hdbc);
  SQLFreeHandle(SQL_HANDLE_ENV, henv);
}

bool CRotinasGlobais::ConsultaDados(CONEXAO hstmtlocal, wxString sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.c_str(), SQL_NTS);   
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  wxMessageBox(STR_NCPREPSQL, wxT("Erro"), wxOK | wxICON_ERROR);
  return FALSE;
}   
rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  wxMessageBox(STR_NCEXECSQL, wxT("Erro"), wxOK | wxICON_ERROR);
  return FALSE;
}
if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
  rc = SQLFetch(hstmtlocal);
  if ( rc == SQL_NO_DATA ) {
  	SQLCloseCursor(hstmtlocal); 
  	return FALSE;
  } else {
  	SQLCloseCursor(hstmtlocal); 
    return TRUE;
  }
} else {
  SQLCloseCursor(hstmtlocal); 
  return FALSE;
} 
}

void CRotinasGlobais::arrumaColunas(CONEXAO hstmtlocal, wxString sLinha[],
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
      sLinha[nCol] = Rotinas->ConverteDataHoraStr(sLinha[nCol], FALSE, 
        "%d/%m/%Y", "%H:%M:%S");
    }
   }
}

bool CRotinasGlobais::ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, wxString sSql)
{
char* sLinha[QTD_MAX_COL];
SQLRETURN   rc;
SQLINTEGER  nLen;
SQLUSMALLINT  nCol, nQtdCol;
wxString sTemp[QTD_MAX_COL];

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.c_str(), SQL_NTS);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  wxMessageBox(STR_NCPREPSQL, wxT("Erro"), wxOK | wxICON_ERROR);
  return FALSE;
}   

rc = SQLExecute(hstmtlocal);
if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
  wxMessageBox(STR_NCEXECSQL, wxT("Erro"), wxOK | wxICON_ERROR);
  return FALSE;
}

if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {

    if (!SQL_SUCCEEDED(SQLNumResultCols(hstmtlocal, (SQLSMALLINT*) &nQtdCol)))
      return FALSE;
	
	for (nCol = 0; nCol < nQtdCol; nCol++) {
      sLinha[nCol] = (char*) malloc(TAM_MAX_STR);

  	  rc = SQLBindCol(hstmtlocal, nCol+1, SQL_C_CHAR, 
		  sLinha[nCol], TAM_MAX_STR, &nLen);

	  if (!(rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)) {
	    SQLCloseCursor(hstmtlocal);
	    return FALSE;
	  }
	}

  
    rc = SQLFetch(hstmtlocal);
   	if ( rc != SQL_NO_DATA ) {	
      
        for (nCol = 0; nCol < nQtdCol; nCol++)
          (*lstLocal).col[nCol].Clear();

    	  while ( rc != SQL_NO_DATA ) {				
	        //SQLGetData(hstmtlocal, nCol+1, SQL_C_CHAR, 
           //sLinha[nCol], TAM_MAX_STR, &nLen)
          
          for (nCol = 0; nCol < nQtdCol; nCol++) {
            sTemp[nCol] = sLinha[nCol];
          }        
          arrumaColunas(hstmtlocal, sTemp, nQtdCol);

	        for (nCol = 0; nCol < nQtdCol; nCol++) {
	          (*lstLocal).col[nCol].Add(sTemp[nCol]); 
	        }

	     rc = SQLFetch(hstmtlocal);
    	}
    	SQLCloseCursor(hstmtlocal);
    	return TRUE;
    } else {
       SQLCloseCursor(hstmtlocal);
       return FALSE;     	
    }   
 } else
    return FALSE; 
}


bool CRotinasGlobais::AtualizaDados(CONEXAO hstmtlocal, wxString sSql)
{
SQLRETURN   rc;

rc = SQLPrepare(hstmtlocal, (SQLTCHAR*) sSql.c_str(), SQL_NTS);
  if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO) {
    rc = SQLExecute(hstmtlocal);
    if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
      return TRUE;
    else {
     //wxMessageBox(STR_NCEXECSQL, wxT("Erro"), wxOK | wxICON_ERROR);
     return FALSE;      
    }  
  } else {
    wxMessageBox(STR_NCPREPSQL, wxT("Erro"), wxOK | wxICON_ERROR);
    return FALSE;
  }   
}

bool CRotinasGlobais::ValidaCampo(wxString sCampo, wxString sMensagemErro) {
bool bret = false;
  if (sCampo.Len()==0) {
    wxMessageBox(sMensagemErro, wxT("Erro"), wxOK | wxICON_ERROR);
	  bret = true;
  } else
	  bret = false;

  return bret;
}

wxString CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR *Campos, 
  wxString sTextoSql, wxString sMensagemErro) {
wxString sret = "";

  if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {
    sret = Campos->col[1].Item(0);
  } else {
    wxMessageBox(sMensagemErro, wxT("Erro"), wxOK | wxICON_ERROR);
    sret = "";
  }
 return sret;
}

void CRotinasGlobais::AdicionaItemLista(wxListBox *lstLista,
     LISTASTR *slCodLista, wxTextCtrl *sCampoCodigo, wxTextCtrl *sCampoDesc)
{
wxString sItems, sCodigo, sDesc;

if (sCampoDesc->GetValue().Len() > 0) {

 sCodigo = sCampoCodigo->GetValue();
 sDesc = sCampoDesc->GetValue();

 sItems = wxString::Format("%s - %s", sCodigo.c_str(), sDesc.c_str());

 if (lstLista->FindString(sItems)==-1) {   
	slCodLista->col.Add(sCodigo);
	lstLista->Append(sItems);
 }
 sCampoCodigo->Clear();
 sCampoDesc->Clear();
}

}

void CRotinasGlobais::RemoveItemLista(wxListBox *lstLista, LISTASTR *slCodLista)
{
int nSelIndice;

 if (lstLista->GetCount() > 0) {   
   nSelIndice = lstLista->GetSelection();
   if (lstLista->Selected(nSelIndice)) {
	   slCodLista->col.Remove(nSelIndice);
	   lstLista->Delete(nSelIndice);
   }	
 }
}

void CRotinasGlobais::AdicionaValoresLista(wxString sTextoSql, 
    wxListBox *lstLista, LISTASTR *slCodLista)
{ 
  LISTAMSTR Campos;
  wxString sItems, sCodigo, sDesc;
  unsigned long nLinha;

  lstLista->Clear();
  slCodLista->col.Clear();
  if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {
    for (nLinha = 0; nLinha < Campos.col[0].Count(); nLinha++) {
      sCodigo = Campos.col[0].Item(nLinha);
      sDesc = Campos.col[1].Item(nLinha);

	    slCodLista->col.Add(sCodigo);
      sItems = wxString::Format("%s - %s", sCodigo.c_str(), sDesc.c_str());
	    lstLista->Append(sItems);
	  }      
  }
}

void CRotinasGlobais::AdicionaColunasGrid(wxGrid *grid, 
  int nPosIni, int nQtdCols, int nLargura[], wxString sRotulos[])
{
 int nPos, nCont;

 if (nPosIni > 0)
   grid->AppendCols(nQtdCols);
 nCont = 0;
 for (nPos = nPosIni; nPos < (nPosIni+nQtdCols); nPos++) {
   grid->SetColSize(nPos, nLargura[nCont]);
   grid->SetColLabelValue(nPos, sRotulos[nCont]);
   nCont++;
 }
}

void CRotinasGlobais::AdicionaLinhasGrid(wxGrid *grid, 
  LISTAMSTR lstLinhas, unsigned long nQtdCol)
{
  unsigned long nCol, nLinha;

  grid->DeleteRows(0,grid->GetNumberRows(),true);  
  grid->AppendRows(lstLinhas.col[0].Count(), true);
  for (nCol = 0; nCol < nQtdCol; nCol++) {
    for (nLinha = 0; nLinha < lstLinhas.col[nCol].Count(); nLinha++) {
      grid->SetCellValue(nLinha, nCol, lstLinhas.col[nCol].Item(nLinha));
    }      
  }
}

