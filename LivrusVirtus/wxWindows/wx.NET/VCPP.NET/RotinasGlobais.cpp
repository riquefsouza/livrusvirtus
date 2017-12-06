#include "StdAfx.h"
#include "RotinasGlobais.h"
#include "Principal.h"
#include "Resource.h"

namespace Livrus
{
  RotinasGlobais::RotinasGlobais(void){
    gConexao = new System::Data::OleDb::OleDbConnection();
  }
  //---------------------------------------------------------------------------
  Boolean RotinasGlobais::ValidaFloat(String* sNum)
  {
   if (sNum->Equals(S"")==false) {
  	try {
  	  Single::Parse(sNum);
  	  return true;
  	} catch(Exception* e) {
      wx::MessageDialog::MessageBox(Resource::STR_NUMINV, "Erro", 
        wx::Dialog::wxOK | wx::Dialog::wxICON_ERROR );
  	  return false;
  	}
   } else
     return false;
  } 
  //---------------------------------------------------------------------------
  String* RotinasGlobais::VirgulaParaPonto(String* sNum, Boolean revertido)
  {
   if (revertido)
     return sNum->Replace(S".",S",");
   else
     return sNum->Replace(S",",S".");
  }
  //---------------------------------------------------------------------------
  int RotinasGlobais::modulo11(String* svalor, int ndig)
  {
    int ncont, nsoma, nvalor, npos;
    String *slocal, *sres;
    
     ncont=0;
     slocal="";
     while (ncont < 11) {
       slocal=String::Concat(svalor->Substring(ncont,1), slocal);
       ncont++;
     }
     nsoma=0;
     if (ndig == 1)
       ncont=2;
     else
       ncont=1;
     npos=2;
     while (ncont < 11) {
       sres = slocal->Substring(ncont,1);
       nvalor = Int32::Parse(sres);
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
  Boolean RotinasGlobais::ValidaCPF(String* cpf){
    String* scpf;
  
    if (cpf->Length==14) {
      scpf=String::Concat(cpf->Substring(0,3),cpf->Substring(4,3),
        cpf->Substring(8,3),cpf->Substring(12,2));
      if ( (modulo11(scpf,1)==Int32::Parse(cpf->Substring(12,1))) &&
      (modulo11(scpf,2)==Int32::Parse(cpf->Substring(13,1))) )
      	return true;
      else
      	return false;
    } else
      return false;
  }
  //---------------------------------------------------------------------------
  Boolean RotinasGlobais::ValidaISBN(String* isbn)
  {
    String *sisbn, *sdigito, *snum;
    int nvalor, nsoma, ncont;
    
    if (isbn->Length==13) {
      sdigito = isbn->Substring(isbn->Length-1, 1);
      sisbn="";
      for(ncont = 0; ncont < isbn->Length-1; ncont++)  {
        if (isbn->Substring(ncont,1)->Equals(S"-")==false)
          sisbn = String::Concat(sisbn, isbn->Substring(ncont,1));
      }
      if (sdigito->Equals(S"X"))
        nsoma = 10;
      else {
        nvalor = Int32::Parse(sdigito);
        nsoma = nvalor;
      }
      for(ncont = 1; ncont <= 9; ncont++)  {
        snum = sisbn->Substring(ncont-1, 1);
        nvalor = Int32::Parse(snum);
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
  Boolean RotinasGlobais::validaDataHora(String* sDataHora, Boolean bSoData) {
    Boolean bvalida, bdatavalida, bhoravalida;
    String *sdia, *smes, *sano, *shora, *smin, *sseg;
    int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;
  
    bvalida = false;
    bdatavalida = false;
    bhoravalida = false;
    nudiames = 0;
    if (bSoData==true) ntam=10;
    else ntam=19;

    if (sDataHora->Length==ntam) {
  	sdia = sDataHora->Substring(0,2);
  	ndia = Int32::Parse(sdia);
  	smes = sDataHora->Substring(3,2);
  	nmes = Int32::Parse(smes);
  	sano = sDataHora->Substring(6,4);
  	nano = Int32::Parse(sano);
  
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
  		  shora = sDataHora->Substring(11,2);
  		  nhora = Int32::Parse(shora);
  		  smin = sDataHora->Substring(14,2);
  		  nmin = Int32::Parse(smin);
  		  sseg = sDataHora->Substring(17,2);
  		  nseg = Int32::Parse(sseg);
  
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
  //---------------------------------------------------------------------------
  String* RotinasGlobais::retDataHoraStr(Boolean bData, Boolean bHora) {
    String* sDataHora = "";
    
    if (bData && bHora)
      sDataHora = DateTime::Now.ToString("dd/MM/yyyy hh:mm:ss");
    else if (bData)
      sDataHora = DateTime::Now.ToString("dd/MM/yyyy");
    else if (bHora)
      sDataHora = DateTime::Now.ToString("hh:mm:ss");
      
    return sDataHora;
  }
  //---------------------------------------------------------------------------
  String* RotinasGlobais::ConverteDataHoraStr(String* sData, String* formato) {
  	System::DateTime dtNasc = System::DateTime::Parse(sData);
  	return dtNasc.ToString(formato);
  }
  //---------------------------------------------------------------------------
  Boolean RotinasGlobais::ConectaBanco(String* sFonteDeDados){
		gConexao->ConnectionString = sFonteDeDados;
    gConexao->Open();

    if (gConexao->get_State() == ConnectionState::Open)
      return true;
    else {
      MessageDialog::MessageBox(Resource::STR_NCONBANCO, "Erro", 
        Dialog::wxOK|Dialog::wxICON_ERROR );
      return false;
    }
  }
  //---------------------------------------------------------------------------    
  Void RotinasGlobais::DisconectaBanco(){
    gConexao->Close();
  }
  //---------------------------------------------------------------------------    
  Boolean RotinasGlobais::AtualizaDados(OleDbCommand* Arquiva, String* sTextoSql){
	  Arquiva = gConexao->CreateCommand();
	  Arquiva->CommandText = sTextoSql;
		if (Arquiva->ExecuteNonQuery() > 0) {
		  Arquiva->Dispose();
      return true;
    } else {
      //MessageDialog::MessageBox(Resource::STR_NCEXECSQL, "Erro", 
      //  Dialog::wxOK|Dialog::wxICON_ERROR );
      return false;
    }
  }
  //---------------------------------------------------------------------------
  Boolean RotinasGlobais::ConsultaDados(OleDbCommand* Consulta, String* sTextoSql)
  {
  Boolean nTemLinhas = false;
  
    Consulta = gConexao->CreateCommand();
    Consulta->CommandText = sTextoSql;
  
    OleDbDataReader* Leitor = Consulta->ExecuteReader();
    nTemLinhas = Leitor->HasRows;
    Leitor->Close();
    return nTemLinhas;  
  } 
  //---------------------------------------------------------------------------
  Boolean RotinasGlobais::ConsultaDadosLista(ArrayList* Registros, String* sTextoSql)
  {
  	Boolean nTemLinhas = false;
  
    OleDbCommand* Consulta = gConexao->CreateCommand();
    Consulta->CommandText = sTextoSql;
  
    Registros->Clear();
    OleDbDataReader* Leitor = Consulta->ExecuteReader();
    while (Leitor->Read()) {
  	 ArrayList* Campos = new ArrayList();
  	 for(int cont=0; cont < Leitor->FieldCount; cont++) {
  	   Campos->Add(Leitor->GetValue(cont)->ToString());
  	 }
  	 Registros->Add(Campos);
    }
    nTemLinhas = Leitor->HasRows;
    Leitor->Close();
    return nTemLinhas;
  
  }  
  //---------------------------------------------------------------------------
  Boolean RotinasGlobais::ValidaCampo(String* sCampo,String* sMensagemErro)
  {
    if (sCampo->Equals(S"")) {
      MessageDialog::MessageBox(sMensagemErro, S"Erro", 
        Dialog::wxOK|Dialog::wxICON_ERROR );
    	return true;
    } else
    	return false;
  }
  //---------------------------------------------------------------------------
  String* RotinasGlobais::ConsultaCampoDesc(ArrayList* Campos,
  				String* sTextoSql, String* sMensagemErro)
  {  
    OleDbCommand* Consulta = gConexao->CreateCommand();
    Consulta->CommandText = sTextoSql;
  
    Campos->Clear();
    OleDbDataReader* Leitor = Consulta->ExecuteReader();
    if (Leitor->Read()) {
  	 for(int cont=0; cont < Leitor->FieldCount; cont++) {
  	   Campos->Add(Leitor->GetValue(cont)->ToString());
  	 }
    }
    bool nTemLinhas = Leitor->HasRows;
    Leitor->Close();
  
    if (nTemLinhas)
      return Campos->Item[1]->ToString();
    else {
      MessageDialog::MessageBox(sMensagemErro, S"Erro", 
        Dialog::wxOK|Dialog::wxICON_ERROR );
    	return "";
    }
  } 
  //---------------------------------------------------------------------------
  int RotinasGlobais::PesquisaItemLista(wx::ListBox* lstLista, String* sItem){
    int bret = -1;
    int nLinha;
    for (nLinha = 0; nLinha < lstLista->Count; nLinha++){
      if (lstLista->GetString(nLinha) == sItem) {
        bret = 0;
      }        
    }
    return bret;
  }
  //---------------------------------------------------------------------------
  Void RotinasGlobais::AdicionaItemLista(wx::ListBox* lstLista,
  	 ArrayList* slCodLista, wx::TextCtrl* sCampoCodigo, wx::TextCtrl* sCampoDesc)
  {
    String* sItems;
  
    if (sCampoDesc->Value->Equals(S"")==false) {
      sItems=String::Concat(sCampoCodigo->Value,S" - ",sCampoDesc->Value);
      if (PesquisaItemLista(lstLista, sItems)==-1) {
        slCodLista->Add(sCampoCodigo->Value);
        lstLista->Append(sItems);
      }
      sCampoCodigo->Clear();
      sCampoDesc->Clear();
    }
  }
  //---------------------------------------------------------------------------
  Void RotinasGlobais::RemoveItemLista(wx::ListBox* lstLista, ArrayList* slCodLista)
  {
    int nSelIndice = 0;
    if (lstLista->Count > 0){
      nSelIndice = lstLista->Selection;
      if (lstLista->Selected(nSelIndice)) {
        slCodLista->RemoveAt(nSelIndice);
        lstLista->Delete(nSelIndice);
      }
    }
  }
  //---------------------------------------------------------------------------
   Void RotinasGlobais::AdicionaValoresLista(String* sTextoSql,
     wx::ListBox* lstLista, ArrayList* slCodLista){
    lstLista->Clear();
    slCodLista->Clear();
  
    OleDbCommand* Consulta = gConexao->CreateCommand();
    Consulta->CommandText = sTextoSql;
  
    OleDbDataReader* Leitor = Consulta->ExecuteReader();
    while (Leitor->Read()) {
  	  slCodLista->Add(Leitor->GetValue(0)->ToString());
  	  lstLista->Append(String::Concat(Leitor->GetValue(0)->ToString()," - ",
  	  Leitor->GetValue(1)->ToString()));
    }
    Leitor->Close();
  
  }
  //---------------------------------------------------------------------------
  Void RotinasGlobais::AdicionaColunasGrid(wx::Grid* grid, int nPosIni, 
    int nQtdCols, int nLargura __gc[], String* sRotulos __gc[]){
    int nPos, nCont;
    
    if (nPosIni > 0){
      grid->AppendCols(nQtdCols);
    }
    nCont = 0;
    for(nPos = nPosIni; nPos < (nPosIni+nQtdCols); nPos++){
      grid->SetColSize(nPos, nLargura[nCont]);
      grid->SetColLabelValue(nPos, sRotulos[nCont]);
      nCont = nCont + 1;
    }
  }
  //---------------------------------------------------------------------------  
  Void RotinasGlobais::AdicionaLinhasGrid(wx::Grid* grid, ArrayList* lstLinhas, 
    int nQtdCol){
    int nCol, nLinha;
    ArrayList *lstCampos;

    grid->DeleteRows(0, grid->NumberRows, true);
    grid->AppendRows(lstLinhas->Count, true);
    for (nLinha = 0; nLinha < lstLinhas->Count; nLinha++){
		  lstCampos = dynamic_cast<ArrayList*>(lstLinhas->Item[nLinha]);
      for (nCol = 0; nCol < nQtdCol; nCol++){
        grid->SetCellValue(nLinha, nCol, lstCampos->Item[nCol]->ToString());
      }
    }
  }
  //---------------------------------------------------------------------------
}