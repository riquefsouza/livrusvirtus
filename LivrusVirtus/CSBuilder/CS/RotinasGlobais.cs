using System;
using System.Windows.Forms;
using System.Data;
using System.Data.OleDb;
using System.Collections;

namespace Livrus
{
	/// <summary>
	/// Summary description for Class.
	/// </summary>
	public class RotinasGlobais
	{
		public static RotinasGlobais Rotinas;
		public string sUsuarioLogin, sUsuarioSenha;
		public string sCodigoSelecionado, sPreco, sQtdEstoque;

		public RotinasGlobais()
		{
			//
			// TODO: Add constructor logic here
			//
		}

//---------------------------------------------------------------------------
public Boolean ValidaInteger(string sNum)
{
 if (sNum!="") {
	try {
	  int.Parse(sNum);
	  return true;
	} catch {
	  MessageBox.Show("Número inválido!", "Erro",
	  MessageBoxButtons.OK,MessageBoxIcon.Error);
	  return false;
	}
 } else
   return false;
}
//---------------------------------------------------------------------------
public Boolean ValidaFloat(string sNum)
{
 if (sNum!="") {
	try {
	  float.Parse(sNum);
	  return true;
	} catch {
	  MessageBox.Show("Número inválido!", "Erro",
	  MessageBoxButtons.OK,MessageBoxIcon.Error);
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
public bool ConsultaDados(OleDbCommand Consulta, string sTextoSql)
{
bool nTemLinhas = false;

  Consulta = frmPrincipal.fPrincipal.db.CreateCommand();
  Consulta.CommandText = sTextoSql;

  OleDbDataReader Leitor = Consulta.ExecuteReader();
  nTemLinhas = Leitor.HasRows;
  Leitor.Close();
  return nTemLinhas;

}
//---------------------------------------------------------------------------
public bool ConsultaDados(DataSet dsConsulta, ArrayList Registros,
						  string sTextoSql)
{
bool nTemLinhas = false;

  dsConsulta.Clear();
  OleDbCommand Consulta = new OleDbCommand();
  OleDbDataAdapter daConsulta = new OleDbDataAdapter();

  daConsulta.TableMappings.Add("Table","Consulta");
  Consulta = frmPrincipal.fPrincipal.db.CreateCommand();
  Consulta.CommandText=sTextoSql;
  daConsulta.SelectCommand = Consulta;
  daConsulta.Fill(dsConsulta);

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
public bool ConsultaDados(ArrayList Registros, string sTextoSql)
{
bool nTemLinhas = false;

  OleDbCommand Consulta = frmPrincipal.fPrincipal.db.CreateCommand();
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
	MessageBox.Show(sMensagemErro, "Erro",
	MessageBoxButtons.OK,MessageBoxIcon.Error);
	return true;
  } else
	return false;
}
//---------------------------------------------------------------------------
public string ConsultaCampoDesc(ArrayList Campos,
				string sTextoSql, string sMensagemErro)
{

  OleDbCommand Consulta = frmPrincipal.fPrincipal.db.CreateCommand();
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
	MessageBox.Show(sMensagemErro, "Erro",
	MessageBoxButtons.OK,MessageBoxIcon.Error);
	return "";
  }
}
//---------------------------------------------------------------------------
public string ConsultaCampoDesc(ArrayList Campos,
		  string sCampoCodigo,string sTextoSql,string sMensagemErro)
{
if (ValidaInteger(sCampoCodigo))
  return ConsultaCampoDesc(Campos, sTextoSql, sMensagemErro);
else
  return "";
}
//---------------------------------------------------------------------------
  public string retDataStr(DateTime sData, string formato) {
	return sData.ToString(formato);
  }
//---------------------------------------------------------------------------
  public string FormataDataStr(string sData, string formato) {
	DateTime dtNasc = DateTime.Parse(sData);
	return dtNasc.ToString(formato);
  }

//---------------------------------------------------------------------------
public void AdicionaItemLista(ListBox lstLista,
	 ArrayList slCodLista, TextBox sCampoCodigo, TextBox sCampoDesc)
{
string sItems;

if (sCampoDesc.Text.Equals("")==false) {
 sItems=sCampoCodigo.Text+" - "+sCampoDesc.Text;
 if (lstLista.Items.IndexOf(sItems)==-1) {
	slCodLista.Add(sCampoCodigo.Text);
	lstLista.Items.Add(sItems);
 }
 sCampoCodigo.Clear();
 sCampoDesc.Clear();
}
}
//---------------------------------------------------------------------------
public void RemoveItemLista(ListBox lstLista, ArrayList slCodLista)
{
 if (lstLista.Items.Count > 0) {
   slCodLista.RemoveAt(lstLista.SelectedIndex);
   lstLista.Items.RemoveAt(lstLista.SelectedIndex);
 }
}
//---------------------------------------------------------------------------
public void AdicionaValoresLista(ArrayList ConsLista,
	 string sTextoSql,ListBox lstLista, ArrayList slCodLista)
{
 ConsLista.Clear();
 lstLista.Items.Clear();
 slCodLista.Clear();

  OleDbCommand Consulta = frmPrincipal.fPrincipal.db.CreateCommand();
  Consulta.CommandText = sTextoSql;

  OleDbDataReader Leitor = Consulta.ExecuteReader();
  while (Leitor.Read()) {
	  slCodLista.Add(Leitor.GetValue(0).ToString());
	  lstLista.Items.Add(Leitor.GetValue(0).ToString()+" - "+
	  Leitor.GetValue(1).ToString());
  }
  Leitor.Close();

}
//---------------------------------------------------------------------------
}
}
