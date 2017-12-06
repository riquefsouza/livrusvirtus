#include "resource.h"
#include "RotinasGlobais.h"
#include "Principal.h"

wxDb *wxBanco;

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
    cpf.Mid(4,3).c_str(), cpf.Mid(8,3).c_str(),cpf.Mid(12,2).c_str());
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

bool CRotinasGlobais::ConectaBanco(wxString sFonteDeDados, 
                                   wxString sLogin, wxString sSenha) {
bool bret = false;
wxDbConnectInf *DbConnectInf = NULL;

DbConnectInf = new wxDbConnectInf(NULL, sFonteDeDados, sLogin, sSenha);

  if (!DbConnectInf || !DbConnectInf->GetHenv()) {
    wxMessageBox(wxT(STR_NALOCODBC),wxT("Erro"), wxOK | wxICON_ERROR);
    bret = false;
  } 
  wxBanco = wxDbGetConnection(DbConnectInf);
  if (wxBanco == 0) 
    bret = false;
  else
    bret = true;     

 return bret;
}

void CRotinasGlobais::DisconectaBanco()
{
  wxBanco->Close();
  delete wxBanco;
}

bool CRotinasGlobais::AtualizaDados(wxDb* dbBanco, wxString sSql) {  
bool bret = false;

  if (dbBanco->IsOpen()) {
    if (dbBanco->ExecSql(sSql.c_str()))
       bret = true;
    else
       bret = false;
  } else
      bret = false;

  return bret;
} 

bool CRotinasGlobais::ConsultaDados(wxDb* dbBanco, wxString sSql) {  
SDWORD cb;
char sLinha[TAM_MAX_STR];
bool bRet = false;

  if (dbBanco->IsOpen()) {
    if (dbBanco->ExecSql(sSql.c_str())) {
      if (dbBanco->GetNext()) {
        if (dbBanco->GetData(1, SQL_C_CHAR, &sLinha, TAM_MAX_STR, &cb))
           bRet = true;            
        if (cb == SQL_NULL_DATA)
          bRet = false;

      } else
        bRet = false;
    } else {       
       wxMessageBox(wxT(STR_NCEXECSQL),wxT("Erro"), wxOK | wxICON_ERROR);
       bRet = false;
    }
  } 
  return bRet;
} 

bool CRotinasGlobais::ConsultaDadosLista(wxDb* dbBanco, 
  LISTAMSTR *lstLocal, wxString sSql, unsigned long nQtdCol) {
SDWORD cb;
char sLinha[TAM_MAX_STR];
bool bRet = false;
unsigned long nCol;

  if (dbBanco->IsOpen()) {

    if (dbBanco->ExecSql(sSql.c_str())) {

      for (nCol=0; nCol < nQtdCol; nCol++)
        (*lstLocal).col[nCol].Clear();

      while (dbBanco->GetNext()) {

        for (nCol=0; nCol < nQtdCol; nCol++) {
          dbBanco->GetData(nCol+1, SQL_C_CHAR, &sLinha, TAM_MAX_STR, &cb);

          if (cb == SQL_NULL_DATA)
            return false;

          (*lstLocal).col[nCol].Add(sLinha);
        }
        bRet = true;
      } 
      
    } else {       
       wxMessageBox(wxT(STR_NCEXECSQL),wxT("Erro"), wxOK | wxICON_ERROR);
       bRet = false;
    }
  } 
  return bRet;

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
  wxString sTextoSql, wxString sMensagemErro, unsigned long nQtdCol) {
wxString sret = "";

  if (ConsultaDadosLista(wxBanco, Campos, sTextoSql, nQtdCol)) {
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
  if (ConsultaDadosLista(wxBanco, &Campos, sTextoSql, 2)) {
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

