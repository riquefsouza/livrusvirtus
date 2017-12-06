using System;
using System.Data;
using System.Data.OleDb;
using System.Collections;
using wx;

namespace Livrus
{
	public class RotinasGlobais
	{
		public static RotinasGlobais Rotinas;
		public string sUsuarioLogin, sUsuarioSenha, sBarraLogin;
		public string sCodigoSelecionado, sPreco, sQtdEstoque;
    public System.Data.OleDb.OleDbConnection gConexao;
    public static string sepDTHR = "#"; /* SOMENTE ACCESS */
    //public static string sepDTHR = "'"; /* OUTROS BANCOS */

		public RotinasGlobais(){
      gConexao = new System.Data.OleDb.OleDbConnection();
    }
    //---------------------------------------------------------------------------
    public Boolean ValidaFloat(string sNum)
    {
     if (sNum!="") {
    	try {
    	  float.Parse(sNum);
    	  return true;
    	} catch {
        MessageDialog.MessageBox(Resource.STR_NUMINV, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
    	  return false;
    	}
     } else
       return false;
    }
    //---------------------------------------------------------------------------
    public string VirgulaParaPonto(string sNum, Boolean revertido)
    {
     if (revertido)
       return sNum.Replace(".",",");
     else
       return sNum.Replace(",",".");
    }
    //---------------------------------------------------------------------------
    public int modulo11(string svalor, int ndig)
    {
    int ncont, nsoma, nvalor, npos;
    string slocal, sres;
    
     ncont=0;
     slocal="";
     while (ncont < 11) {
       slocal=svalor.Substring(ncont,1) + slocal;
       ncont++;
     }
     nsoma=0;
     if (ndig == 1)
       ncont=2;
     else
       ncont=1;
     npos=2;
     while (ncont < 11) {
       sres = slocal.Substring(ncont,1);
       nvalor = int.Parse(sres);
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
    public Boolean ValidaCPF(string cpf)
    {
    string scpf;
    
    if (cpf.Length==14) {
      scpf=cpf.Substring(0,3)+cpf.Substring(4,3)+cpf.Substring(8,3)+
    	cpf.Substring(12,2);
      if ( (modulo11(scpf,1)==int.Parse(cpf.Substring(12,1))) &&
      (modulo11(scpf,2)==int.Parse(cpf.Substring(13,1))) )
    	return true;
      else
    	return false;
    } else
      return false;
    }
    //---------------------------------------------------------------------------
    public Boolean ValidaISBN(string isbn)
    {
     string sisbn, sdigito, snum;
     int nvalor, nsoma, ncont;
    
    if (isbn.Length==13) {
      sdigito = isbn.Substring(isbn.Length-1, 1);
      sisbn="";
      for(ncont = 0; ncont < isbn.Length-1; ncont++)  {
        if (isbn.Substring(ncont,1)!="-")
          sisbn = sisbn + isbn.Substring(ncont,1);
      }
      if (sdigito=="X")
        nsoma = 10;
      else {
        nvalor = int.Parse(sdigito);
        nsoma = nvalor;
      }
      for(ncont = 1; ncont <= 9; ncont++)  {
        snum = sisbn.Substring(ncont-1, 1);
        nvalor = int.Parse(snum);
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
    public Boolean validaDataHora(string sDataHora, Boolean bSoData){
      Boolean bvalida, bdatavalida, bhoravalida;
      string sdia, smes, sano, shora, smin, sseg;
      int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;
    
      bvalida = false;
      bdatavalida = false;
      bhoravalida = false;
      nudiames = 0;
      if (bSoData==true) ntam=10;
      else ntam=19;
  
      if (sDataHora.Length==ntam) {
      	sdia = sDataHora.Substring(0,2);
      	ndia = int.Parse(sdia);
      	smes = sDataHora.Substring(3,2);
      	nmes = int.Parse(smes);
      	sano = sDataHora.Substring(6,4);
      	nano = int.Parse(sano);
      
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
      		  shora = sDataHora.Substring(11,2);
      		  nhora = int.Parse(shora);
      		  smin = sDataHora.Substring(14,2);
      		  nmin = int.Parse(smin);
      		  sseg = sDataHora.Substring(17,2);
      		  nseg = int.Parse(sseg);
      
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
    public string retDataHoraStr(bool bData, bool bHora) {
      string sDataHora = "";
      DateTime sTempo = DateTime.Now;
      
      if (bData && bHora)
        sDataHora = sTempo.ToString("dd/MM/yyyy hh:mm:ss");
      else if (bData)
        sDataHora = sTempo.ToString("dd/MM/yyyy");
      else if (bHora)
        sDataHora = sTempo.ToString("hh:mm:ss");
      
      return sDataHora;
    }
    //---------------------------------------------------------------------------
    public string ConverteDataHoraStr(string sData, string formato) {
    	DateTime dtNasc = DateTime.Parse(sData);
    	return dtNasc.ToString(formato);
    }
    //---------------------------------------------------------------------------
    public bool ConectaBanco(string sFonteDeDados)
    {
			gConexao.ConnectionString = sFonteDeDados;
      gConexao.Open();

      if (gConexao.State.ToString().Equals("Open"))
        return true;
      else {
        MessageDialog.MessageBox(Resource.STR_NCONBANCO, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
        return false;
      }
    }
    //---------------------------------------------------------------------------    
    public void DisconectaBanco(){
      gConexao.Close();
    }
    //---------------------------------------------------------------------------    
    public bool AtualizaDados(OleDbCommand Arquiva, string sTextoSql){
		  Arquiva = gConexao.CreateCommand();
		  Arquiva.CommandText = sTextoSql;
			if (Arquiva.ExecuteNonQuery() > 0) {
			  Arquiva.Dispose();
        return true;
      } else {
        //MessageDialog.MessageBox(Resource.STR_NCEXECSQL, "Erro", 
        //  Dialog.wxOK|Dialog.wxICON_ERROR );
        return false;
      }
    }
    //---------------------------------------------------------------------------
    public bool ConsultaDados(OleDbCommand Consulta, string sTextoSql)
    {
     bool nTemLinhas = false;
    
      Consulta = gConexao.CreateCommand();
      Consulta.CommandText = sTextoSql;
    
      OleDbDataReader Leitor = Consulta.ExecuteReader();
      nTemLinhas = Leitor.HasRows;
      Leitor.Close();

      return nTemLinhas;   
    }
    //---------------------------------------------------------------------------
    public bool ConsultaDadosLista(ArrayList Registros, string sTextoSql)
    {
    bool nTemLinhas = false;
    
      OleDbCommand Consulta = gConexao.CreateCommand();
      Consulta.CommandText = sTextoSql;
    
      Registros.Clear();
      OleDbDataReader Leitor = Consulta.ExecuteReader();
      while (Leitor.Read()) {
    	 ArrayList Campos = new ArrayList();
    	 for(int cont=0; cont < Leitor.FieldCount; cont++) {
    	   Campos.Add(Leitor.GetValue(cont).ToString());
    	 }
    	 Registros.Add(Campos);
      }
      nTemLinhas = Leitor.HasRows;
      Leitor.Close();
      return nTemLinhas;    
    }
    //---------------------------------------------------------------------------
    public Boolean ValidaCampo(string sCampo,string sMensagemErro)
    {
      if (sCampo=="") {
        MessageDialog.MessageBox(sMensagemErro, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
      	return true;
      } else
      	return false;
    }
    //---------------------------------------------------------------------------
    public string ConsultaCampoDesc(ArrayList Campos,
    				string sTextoSql, string sMensagemErro)
    {   
      OleDbCommand Consulta = gConexao.CreateCommand();
      Consulta.CommandText = sTextoSql;
    
      Campos.Clear();
      OleDbDataReader Leitor = Consulta.ExecuteReader();
      if (Leitor.Read()) {
        for(int cont=0; cont < Leitor.FieldCount; cont++) {
          Campos.Add(Leitor.GetValue(cont).ToString());
        }
      }
      bool nTemLinhas = Leitor.HasRows;
      Leitor.Close();
    
      if (nTemLinhas)
        return Campos[1].ToString();
      else {
        MessageDialog.MessageBox(sMensagemErro, "Erro", 
          Dialog.wxOK|Dialog.wxICON_ERROR );
      	return "";
      }
    }
    //---------------------------------------------------------------------------
    public int PesquisaItemLista(wx.ListBox lstLista, string sItem){
      int bret = -1;
      int nLinha;
      for (nLinha = 0; nLinha < lstLista.Count; nLinha++){
        if (lstLista.GetString(nLinha) == sItem) {
          bret = 0;
        }        
      }
      return bret;
    }
    //---------------------------------------------------------------------------
    public void AdicionaItemLista(wx.ListBox lstLista,
    	 ArrayList slCodLista, wx.TextCtrl sCampoCodigo, wx.TextCtrl sCampoDesc)
    {
      string sItems;

      if (sCampoDesc.Value.Equals("")==false) {
        sItems=sCampoCodigo.Value+" - "+sCampoDesc.Value;
        if (PesquisaItemLista(lstLista, sItems)==-1) {
          slCodLista.Add(sCampoCodigo.Value);
          lstLista.Append(sItems);
        }
        sCampoCodigo.Clear();
        sCampoDesc.Clear();
      }
    }
    //---------------------------------------------------------------------------
    public void RemoveItemLista(wx.ListBox lstLista, ArrayList slCodLista){
      int nSelIndice = 0;
      if (lstLista.Count > 0){
        nSelIndice = lstLista.Selection;
        if (lstLista.Selected(nSelIndice)) {
          slCodLista.RemoveAt(nSelIndice);
          lstLista.Delete(nSelIndice);
        }
      }
    }
    //---------------------------------------------------------------------------
    public void AdicionaValoresLista(string sTextoSql,
      wx.ListBox lstLista, ArrayList slCodLista)
    {
     lstLista.Clear();
     slCodLista.Clear();
    
      OleDbCommand Consulta = gConexao.CreateCommand();
      Consulta.CommandText = sTextoSql;
    
      OleDbDataReader Leitor = Consulta.ExecuteReader();
      while (Leitor.Read()) {
    	  slCodLista.Add(Leitor.GetValue(0).ToString());
    	  lstLista.Append(Leitor.GetValue(0).ToString()+" - "+
    	  Leitor.GetValue(1).ToString());
      }
      Leitor.Close();
    
    }
    //---------------------------------------------------------------------------
    public void AdicionaColunasGrid(wx.Grid grid, int nPosIni, int nQtdCols, 
      int[] nLargura, string[] sRotulos){
      int nPos, nCont;
      
      if (nPosIni > 0){
        grid.AppendCols(nQtdCols);
      }
      nCont = 0;
      for(nPos = nPosIni; nPos < (nPosIni+nQtdCols); nPos++){
        grid.SetColSize(nPos, nLargura[nCont]);
        grid.SetColLabelValue(nPos, sRotulos[nCont]);
        nCont = nCont + 1;
      }
    }
    //---------------------------------------------------------------------------  
    public void AdicionaLinhasGrid(wx.Grid grid, ArrayList lstLinhas, int nQtdCol){
      int nCol, nLinha;
      ArrayList lstCampos;
      
      grid.DeleteRows(0, grid.NumberRows, true);
      grid.AppendRows(lstLinhas.Count, true);
      for (nLinha = 0; nLinha < lstLinhas.Count; nLinha++){
  		  lstCampos = (ArrayList)lstLinhas[nLinha];
        for (nCol = 0; nCol < nQtdCol; nCol++){
           grid.SetCellValue(nLinha, nCol, lstCampos[nCol].ToString());
        }
      }
    }
    //---------------------------------------------------------------------------
  }
}
