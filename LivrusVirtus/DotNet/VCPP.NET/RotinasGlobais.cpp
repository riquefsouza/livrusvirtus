#include "StdAfx.h"
#include "RotinasGlobais.h"
#include "Principal.h"

namespace Livrus
{

    RotinasGlobais::RotinasGlobais(void)
    {
    	//
    	// TODO: Add constructor logic here
    	//
    }

    //---------------------------------------------------------------------------
    Boolean RotinasGlobais::ValidaInteger(String* sNum)
    {
     if (sNum->Equals(S"")==false) {
    	try {
    	  Int32::Parse(sNum);
    	  return true;
    	} catch(Exception* e) {
    	  MessageBox::Show(S"Número inválido!", S"Erro",
    	  MessageBoxButtons::OK,MessageBoxIcon::Error);
    	  return false;
    	}
     } else
       return false;
    } 
    //---------------------------------------------------------------------------
    Boolean RotinasGlobais::ValidaFloat(String* sNum)
    {
     if (sNum->Equals(S"")==false) {
    	try {
    	  Single::Parse(sNum);
    	  return true;
    	} catch(Exception* e) {
    	  MessageBox::Show(S"Número inválido!", S"Erro",
    	  MessageBoxButtons::OK,MessageBoxIcon::Error);
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
    Boolean RotinasGlobais::ValidaCPF(String* cpf)
    {
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
    Boolean RotinasGlobais::ConsultaDados(OleDbCommand* Consulta, String* sTextoSql)
    {
    Boolean nTemLinhas = false;
    
      Consulta = frmPrincipal::fPrincipal->db->CreateCommand();
      Consulta->CommandText = sTextoSql;
    
      OleDbDataReader* Leitor = Consulta->ExecuteReader();
      nTemLinhas = Leitor->HasRows;
      Leitor->Close();
      return nTemLinhas;
    
    } 
    //---------------------------------------------------------------------------
    Boolean RotinasGlobais::ConsultaDados(DataSet* dsConsulta, ArrayList* Registros, 
								String* sTextoSql)
    {
    Boolean nTemLinhas = false;
    
      dsConsulta->Clear();
      OleDbCommand* Consulta = new OleDbCommand();
      OleDbDataAdapter* daConsulta = new OleDbDataAdapter();
    
      daConsulta->TableMappings->Add(S"Table",S"Consulta");
      Consulta = frmPrincipal::fPrincipal->db->CreateCommand();
      Consulta->CommandText=sTextoSql;
      daConsulta->SelectCommand = Consulta;
      daConsulta->Fill(dsConsulta);
    
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
    Boolean RotinasGlobais::ConsultaDados(ArrayList* Registros, String* sTextoSql)
    {
    	Boolean nTemLinhas = false;
    
      OleDbCommand* Consulta = frmPrincipal::fPrincipal->db->CreateCommand();
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
    	MessageBox::Show(sMensagemErro, S"Erro",
    	MessageBoxButtons::OK,MessageBoxIcon::Error);
    	return true;
      } else
    	return false;
    }
    //---------------------------------------------------------------------------
    String* RotinasGlobais::ConsultaCampoDesc(ArrayList* Campos,
    				String* sTextoSql, String* sMensagemErro)
    {
    
      OleDbCommand* Consulta = frmPrincipal::fPrincipal->db->CreateCommand();
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
    	MessageBox::Show(sMensagemErro, S"Erro",
    	MessageBoxButtons::OK,MessageBoxIcon::Error);
    	return "";
      }
    }
    //---------------------------------------------------------------------------
    String* RotinasGlobais::ConsultaCampoDesc(ArrayList* Campos,
    		  String* sCampoCodigo,String* sTextoSql,String* sMensagemErro)
    {
    if (ValidaInteger(sCampoCodigo))
      return ConsultaCampoDesc(Campos, sTextoSql, sMensagemErro);
    else
      return "";
    }
    //---------------------------------------------------------------------------
      String* RotinasGlobais::retDataStr(DateTime* sData, String* formato) {
    	return sData->ToString(formato);
      }
    //---------------------------------------------------------------------------
      String* RotinasGlobais::FormataDataStr(String* sData, String* formato) {
    	System::DateTime dtNasc = System::DateTime::Parse(sData);
    	return dtNasc.ToString(formato);
      }
    
    //---------------------------------------------------------------------------
    Void RotinasGlobais::AdicionaItemLista(ListBox* lstLista,
    	 ArrayList* slCodLista, TextBox* sCampoCodigo, TextBox* sCampoDesc)
    {
    String* sItems;
    
    if (sCampoDesc->Text->Equals(S"")==false) {
     sItems=String::Concat(sCampoCodigo->Text,S" - ",sCampoDesc->Text);
     if (lstLista->Items->IndexOf(sItems)==-1) {
    	slCodLista->Add(sCampoCodigo->Text);
    	lstLista->Items->Add(sItems);
     }
     sCampoCodigo->Clear();
     sCampoDesc->Clear();
    }
    }
    //---------------------------------------------------------------------------
    Void RotinasGlobais::RemoveItemLista(ListBox* lstLista, ArrayList* slCodLista)
    {
     if (lstLista->Items->Count > 0) {
       slCodLista->RemoveAt(lstLista->SelectedIndex);
       lstLista->Items->RemoveAt(lstLista->SelectedIndex);
     }
    }
    //---------------------------------------------------------------------------
     Void RotinasGlobais::AdicionaValoresLista(ArrayList* ConsLista,
    	 String* sTextoSql,ListBox* lstLista, ArrayList* slCodLista)
    {
     ConsLista->Clear();
     lstLista->Items->Clear();
     slCodLista->Clear();
    
      OleDbCommand* Consulta = frmPrincipal::fPrincipal->db->CreateCommand();
      Consulta->CommandText = sTextoSql;
    
      OleDbDataReader* Leitor = Consulta->ExecuteReader();
      while (Leitor->Read()) {
    	  slCodLista->Add(Leitor->GetValue(0)->ToString());
    	  lstLista->Items->Add(String::Concat(Leitor->GetValue(0)->ToString()," - ",
    	  Leitor->GetValue(1)->ToString()));
      }
      Leitor->Close();
    
    }
    //---------------------------------------------------------------------------

}