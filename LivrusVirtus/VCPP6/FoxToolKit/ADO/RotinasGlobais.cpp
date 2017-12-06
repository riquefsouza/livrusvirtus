#include "resource.h"
#include "RotinasGlobais.h"
#include "Principal.h"

CONEXAO  gConexao;

FXString Rotinas_sBarraLogin;
FXString Rotinas_sUsuarioLogin;
FXString Rotinas_sUsuarioSenha;
FXString Rotinas_sCodigoSelecionado;
FXString Rotinas_sPreco;
FXString Rotinas_sQtdEstoque;
FXString Rotinas_sepDTHR = "#"; /* SOMENTE ACCESS */
//FXString Rotinas_sepDTHR = "'"; /* OUTROS BANCOS */

CRotinasGlobais *Rotinas = (CRotinasGlobais *) NULL;

CRotinasGlobais::CRotinasGlobais(FXApp* owner) { 
  app = owner;
}

CRotinasGlobais::~CRotinasGlobais() { 
}

FXchar* CRotinasGlobais::alocaString(FXint ntam)
{ FXchar *strlocal;

 strlocal = (FXchar*) malloc(ntam);
 strlocal[0]='\0';
 return strlocal;
}

FXbool CRotinasGlobais::ValidaFloat(FXString sNum) {
FXdouble nNum;
FXbool bret = false;

 if (sNum.length() > 0) {        
    nNum = FXDoubleVal(sNum);
    if (nNum >= 0.01)
      bret = true;
    else { 
      FXMessageBox::error(app, MBOX_OK, "Erro", STR_NUMINV);
      bret = false;
    }
 } else
   bret = false;

 return bret;
} 

FXString CRotinasGlobais::VirgulaParaPonto(FXString sNum, FXbool bRevertido) {

 if (bRevertido)
   sNum.substitute(".", ",");
 else
   sNum.substitute(",", ".");

 return sNum;
}

FXint CRotinasGlobais::modulo11(FXString svalor, FXint ndig) {
FXint ncont, nsoma, npos, nvalor;
FXString slocal, sres;
FXint nret = 0;

 ncont=0;
 while (ncont < 11) {
   slocal=svalor.mid(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres = slocal.mid(ncont,1);
   nvalor = FXIntVal(sres);

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

FXbool CRotinasGlobais::validaCPF(FXString cpf) {
FXString scpf;
FXint nNum1, nNum2;
FXString sNum1, sNum2;
FXbool bret = false;

if (cpf.length()==14) {
  scpf = FXStringFormat("%s%s%s%s", cpf.mid(0,3).text(),
    cpf.mid(4,3).text(),cpf.mid(8,3).text(),cpf.mid(12,2).text());
  sNum1 = cpf.mid(12,1);
  nNum1 = FXIntVal(sNum1);
  sNum2 = cpf.mid(13,1);
  nNum2 = FXIntVal(sNum2);
  if ( (modulo11(scpf,1)==nNum1) && (modulo11(scpf,2)==nNum2) )
    bret = true;
  else
    bret = false;
} else
  bret = false;

return bret;
}

FXbool CRotinasGlobais::validaISBN(FXString isbn) {
 FXString sisbn, sdigito, snum;
 FXint nsoma, ncont, nvalor;
 FXbool bret = false;

if (isbn.length()==13) {
  sdigito = isbn.mid(isbn.length()-1, 1);
  sisbn.clear();
  for(ncont = 0; ncont < abs(isbn.length()-1); ncont++)  {
    if (compare(isbn.mid(ncont,1), "-")!=0)
      sisbn += isbn.mid(ncont,1);
  }
  if (compare(sdigito, "X")==0)
    nsoma = 10;
  else {
    nvalor = FXIntVal(sdigito);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.mid(ncont-1, 1);
    nvalor = FXIntVal(snum);
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

FXbool CRotinasGlobais::validaDataHora(FXString sDataHora, FXbool bSoData)
{ FXbool bvalida, bdatavalida, bhoravalida;
  FXString sdia, smes, sano, shora, smin, sseg;
  FXint ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==TRUE) ntam=10;
else ntam=19;

  if (sDataHora.length()==ntam) {
    sdia = sDataHora.mid(0,2);
    ndia = FXIntVal(sdia);
    smes = sDataHora.mid(3,2);
    nmes = FXIntVal(smes);
    sano = sDataHora.mid(6,4);
    nano = FXIntVal(sano);
  
    if ((nano >= 1) && (nano <= 9999)) {
      if ((nmes >= 1) && (nmes <= 31)) {
          switch(nmes) {
           case 1: case 3: case 5: case 7: case 8: 
           case 10: case 12: nudiames = 31; break;
           case 2: {
               // ano bissexto 
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
          shora = sDataHora.mid(11,2);
          nhora = FXIntVal(shora);
          smin = sDataHora.mid(14,2);
          nmin = FXIntVal(smin);
          sseg = sDataHora.mid(17,2);
          nseg = FXIntVal(sseg);

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

FXString CRotinasGlobais::FormataDataHoraStr(struct tm* sTempo, 
  FXString sFrmtData, FXString sFrmtHora) {
FXchar *sDataHora = alocaString(TAM_MAX_STR);
FXString sTemp, sret;

if (sFrmtData.length() > 0 && sFrmtHora.length() > 0)
  sTemp = sFrmtData + " " + sFrmtHora;
else if (sFrmtData.length() > 0)
  sTemp = sFrmtData;
else if (sFrmtHora.length() > 0)
  sTemp = sFrmtHora;

strftime(sDataHora, TAM_MAX_STR, sTemp.text(), sTempo);
sret.append(sDataHora);
return sret;
}

FXString CRotinasGlobais::retDataHoraStr(FXbool bData, FXbool bHora)
{ FXString sDataHora;
  time_t agora;   
  struct tm* sTempo;

  time(&agora);
  sTempo = localtime(&agora); 

if (bData && bHora)
  sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "%H:%M:%S");
else if (bData)
  sDataHora = FormataDataHoraStr(sTempo, "%d/%m/%Y", "");
else if (bHora)
  sDataHora = FormataDataHoraStr(sTempo, "", "%H:%M:%S");

return sDataHora;
}

FXString CRotinasGlobais::ConverteDataHoraStr(FXString sDTHR, 
  FXbool DMY_ou_YMD, FXString sFrmtData, FXString sFrmtHora)
{ FXString sDataHora;
  struct tm sTempo;

if (sFrmtData.length() > 0) {
  if (DMY_ou_YMD) {
    sTempo.tm_mday = FXIntVal(sDTHR.mid(0, 2));
    sTempo.tm_mon = FXIntVal(sDTHR.mid(3, 2));
    sTempo.tm_year = FXIntVal(sDTHR.mid(6, 4));
  } else {
    sTempo.tm_year = FXIntVal(sDTHR.mid(0, 4));
    sTempo.tm_mon = FXIntVal(sDTHR.mid(5, 2));
    sTempo.tm_mday = FXIntVal(sDTHR.mid(8, 2));
  }
  sTempo.tm_mon -= 1;
  sTempo.tm_year -= 1900;
}

if (sFrmtHora.length() > 0) {
  sTempo.tm_hour = FXIntVal(sDTHR.mid(11, 2));
  sTempo.tm_min = FXIntVal(sDTHR.mid(14, 2));
  sTempo.tm_sec = FXIntVal(sDTHR.mid(17, 2));
}

sDataHora = FormataDataHoraStr(&sTempo,sFrmtData,sFrmtHora);

return sDataHora;
}

FXbool CRotinasGlobais::ConectaBanco(FXString sStrConexao)
{
  FXString sTemp;

  if(FAILED(::CoInitialize(NULL)))
    return false;

  try 
  {
    if FAILED( gConexao.CreateInstance("ADODB.Connection") ) {
      FXMessageBox::error(app, MBOX_OK, "Erro", STR_NCCINST);
      return false;
    }

    gConexao->Open(sStrConexao.text(), 
      "", "", adConnectUnspecified);
  }
  catch (_com_error &e)
  {
    sTemp = FXStringFormat("%s - %s", STR_NCONBANCO, 
      e.Description().operator const char *());
    FXMessageBox::error(app, MBOX_OK, "Erro", sTemp.text());
    return false;
  } 
  return true;
}

void CRotinasGlobais::DisconectaBanco()
{
  gConexao->Close();
  ::CoUninitialize();
}

FXbool CRotinasGlobais::ConsultaDados(CONEXAO pConexao, FXString sSql)
{
  FXString sTemp;
  _RecordsetPtr pRS;

  try 
  {    
    if FAILED( pRS.CreateInstance("ADODB.Recordset") ) {
      FXMessageBox::error(app, MBOX_OK, "Erro", STR_NCCINST);
      return false;
    }

    pRS->Open(sSql.text(), _variant_t((IDispatch *) pConexao, true), 
      adOpenStatic, adLockReadOnly, adCmdText);

    if (pRS->GetRecordCount() > 0) {
      pRS->Close();
      return true;
    } else {
      pRS->Close();
      return false;
    }        
  }
  catch (_com_error &e)
  {
    sTemp = FXStringFormat("%s - %s", STR_NCEXECSQL, 
      e.Description().operator const char *());
    FXMessageBox::error(app, MBOX_OK, "Erro", sTemp.text());
    return false;
  }   
}

FXbool CRotinasGlobais::AtualizaDados(CONEXAO pConexao, FXString sSql)
{
  FXString sTemp;
  _CommandPtr  pCmnd;
  _variant_t   pRegsAfetados;

  try 
  {    
    if FAILED( pCmnd.CreateInstance("ADODB.Command") ) {
      FXMessageBox::error(app, MBOX_OK, "Erro", STR_NCCINST);
      return false;
    }
    pCmnd->ActiveConnection = pConexao;
    pCmnd->CommandText = (_bstr_t) sSql.text();
    pRegsAfetados.vt = VT_I4;
    pCmnd->Execute(&pRegsAfetados,NULL,adCmdText);
    //pConexao->Execute((_bstr_t) sSql, NULL, adExecuteNoRecords);  

    if ( V_I4(&pRegsAfetados) > 0)
      return true;
    else
      return false;
  }
  catch (_com_error &e)
  {
    sTemp = FXStringFormat("%s - %s", STR_NCEXECSQL, 
      e.Description().operator const char *());
    FXMessageBox::error(app, MBOX_OK, "Erro", sTemp.text());
    return false;
  }   
}

FXbool CRotinasGlobais::ConsultaDadosLista(CONEXAO pConexao, 
	LISTAMSTR *lstLocal, FXString sSql)
                                
{
  FXString sTemp;
  _RecordsetPtr pRS;
  long nCol, nQtdCol;
  FXString sLinha;
  
  try 
  {    
    if FAILED( pRS.CreateInstance("ADODB.Recordset") ) {
      FXMessageBox::error(app, MBOX_OK, "Erro", STR_NCCINST);
      return false;
    }
    pRS->Open(sSql.text(), _variant_t((IDispatch *) pConexao, true), 
      adOpenStatic, adLockReadOnly, adCmdText);

    if (pRS->GetRecordCount() > 0) {
      nQtdCol = pRS->GetFields()->Count;

      for (nCol = 0; nCol < nQtdCol; nCol++)
      	lstLocal->col[nCol].clear();

      while (!pRS->adoEOF) {
        for (nCol = 0; nCol < nQtdCol; nCol++) {
          sLinha = (char *) 
            ((_bstr_t) pRS->GetFields()->GetItem((LONG)nCol)->GetValue());

          if (pRS->GetFields()->Item[nCol]->Type == adDBTimeStamp)
            sLinha = Rotinas->ConverteDataHoraStr(sLinha, false, 
              "%d/%m/%Y", "%H:%M:%S");
          else if (pRS->GetFields()->Item[nCol]->Type == adSingle
            || pRS->GetFields()->Item[nCol]->Type == adDouble)
            sLinha = Rotinas->VirgulaParaPonto(sLinha, false);

          lstLocal->col[nCol].append(sLinha); 
        }  
        pRS->MoveNext();
      }

      pRS->Close();
      return true;
    } else {
      pRS->Close();
      return false;
    }        
  }
  catch (_com_error &e)
  {
    sTemp = FXStringFormat("%s - %s", STR_NCEXECSQL, 
      e.Description().operator const char *());
    FXMessageBox::error(app, MBOX_OK, "Erro", sTemp.text());
    return false;
  }   
}

FXbool CRotinasGlobais::ValidaCampo(FXString sCampo, FXString sMensagemErro) {
FXbool bret = false;
  if (sCampo.length()==0) {
    FXMessageBox::error(app, MBOX_OK, "Erro", sMensagemErro.text());
	  bret = true;
  } else
	  bret = false;

  return bret;
}

FXString CRotinasGlobais::ConsultaCampoDesc(LISTAMSTR *Campos, 
  FXString sTextoSql, FXString) {
FXString sret = "";
FXString slocal;

  if (ConsultaDadosLista(gConexao, Campos, sTextoSql)) {
    slocal = Campos->col[1][0];
    sret.append(slocal);
  } else {
    //FXMessageBox::error(app, MBOX_OK, "Erro", sMensagemErro.text());
    sret = "";
  }
 return sret;
}

void CRotinasGlobais::AdicionaItemLista(FXList *lstLista,
     LISTASTR *slCodLista, FXTextField *sCampoCodigo, FXTextField *sCampoDesc)
{
FXString sItems, sCodigo, sDesc;

if (sCampoDesc->getText().length() > 0) {

 sCodigo = sCampoCodigo->getText();
 sDesc = sCampoDesc->getText();

 sItems = FXStringFormat("%s - %s", sCodigo.text(), sDesc.text());

 if (lstLista->findItem(sItems)==-1) {   
  slCodLista->col.append(sCodigo); 
	lstLista->appendItem(sItems);
 }
 sCampoCodigo->setText("");
 sCampoDesc->setText("");
}

}

void CRotinasGlobais::RemoveItemLista(FXList *lstLista, LISTASTR *slCodLista)
{
FXint nSelIndice;

 if (lstLista->getNumItems() > 0) {   
   nSelIndice = lstLista->getCurrentItem();
   if (lstLista->isItemCurrent(nSelIndice)) {
     slCodLista->col.remove(nSelIndice);
	   lstLista->removeItem(nSelIndice);
   }	
 }
}

void CRotinasGlobais::AdicionaValoresLista(FXString sTextoSql, 
    FXList *lstLista, LISTASTR *slCodLista)
{ 
  LISTAMSTR Campos;
  FXString sItems, sCodigo, sDesc;
  FXint nLinha;

  lstLista->clearItems();
  slCodLista->col.clear();
  if (ConsultaDadosLista(gConexao, &Campos, sTextoSql)) {

	  for (nLinha = 0; nLinha < Campos.col[0].no(); nLinha++) {	
      sCodigo = Campos.col[0][nLinha];
      sDesc = Campos.col[1][nLinha];

	    slCodLista->col.append(Campos.col[0][nLinha]);
      sItems = FXStringFormat("%s - %s", sCodigo.text(), sDesc.text());
	    lstLista->appendItem(sItems);
	  }
  }
}

void CRotinasGlobais::AdicionaColunasGrid(FXTable *grid, 
  FXint nPosIni, FXint nQtdCols, FXint nLargura[], FXString sRotulos[])
{
 FXint nPos, nCont;

 if (nPosIni > 0)
   grid->insertColumns(nPosIni, nQtdCols);
 nCont = 0;
 for (nPos = nPosIni; nPos < (nPosIni+nQtdCols); nPos++) {
   grid->setColumnWidth(nPos, nLargura[nCont]);
   grid->setColumnText(nPos, sRotulos[nCont]);  
   nCont++;
 }
}

void CRotinasGlobais::AdicionaLinhasGrid(FXTable *grid, 
  LISTAMSTR lstLinhas, FXint nQtdCol)
{ 
  FXint nCol, nLinha;
  FXString sLinha;

  if (grid->getNumRows() > 1)
    grid->removeRows(0, grid->getNumRows()-1);  

  grid->insertRows(0, lstLinhas.col[0].no()-1);
  for(nLinha=0; nLinha < grid->getNumRows(); nLinha++)
    grid->setRowText(nLinha,FXStringVal(nLinha+1));

  for (nCol = 0; nCol < nQtdCol; nCol++) {
    for (nLinha = 0; nLinha < lstLinhas.col[0].no(); nLinha++) {	
      sLinha = lstLinhas.col[nCol][nLinha];
      if (nCol > 0)
        grid->setItemJustify(nLinha, nCol, FXTableItem::LEFT );
      grid->setItemText(nLinha, nCol, sLinha);
    }      
  }
}

