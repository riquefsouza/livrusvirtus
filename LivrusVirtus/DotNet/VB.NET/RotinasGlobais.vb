Imports System
Imports System.Collections
Imports System.Windows.Forms
Imports System.Data
Imports System.Data.OleDb

Namespace Livrus

Public Class RotinasGlobais
    Inherits System.Object

public shared Rotinas as RotinasGlobais
public sUsuarioLogin, sUsuarioSenha as string
public sCodigoSelecionado, sPreco, sQtdEstoque as string

Public Sub New()
    MyBase.New()
End Sub

public function ValidaInteger(sNum as string) as Boolean
 if sNum<>"" then
	try
	  integer.Parse(sNum)
	  ValidaInteger = true
	catch
	  MessageBox.Show("Número inválido!", "Erro", _
	  MessageBoxButtons.OK,MessageBoxIcon.Error)
	  ValidaInteger = false
	end try
 else
   ValidaInteger = false
 end if
end function

Public Function ValidaFloat(sNum As String) As Boolean
 if sNum<>"" then
	try
	  single.Parse(sNum)
	  ValidaFloat = true
	catch
	  MessageBox.Show("Número inválido!", "Erro", _
	  MessageBoxButtons.OK,MessageBoxIcon.Error)
	  ValidaFloat = false
    end try
 else
   ValidaFloat = false
 end if
End Function

Public Function VirgulaParaPonto(sNum As String, revertido as Boolean) As String
 if revertido then
   return sNum.Replace(".",",")
 else
   return sNum.Replace(",", ".")
 end if
End Function

Private Function modulo11(svalor As String, ndig As Integer)
Dim ncont As Integer, nsoma As Integer, nstatus As Integer 
Dim nvalor As Integer, npos As Integer
Dim sres As String, slocal As String

 ncont = 0
 while ncont < 11 
   slocal = svalor.Substring(ncont,1) + slocal
   ncont = ncont+1
 end while
 nsoma = 0
 if ndig=1 then
   ncont = 2
 else
   ncont = 1
 end if
 npos = 2
 while ncont < 11
   sres = slocal.Substring(ncont,1)
   nvalor = CInt(sres)
   nsoma = nsoma + (nvalor * npos)
   ncont = ncont+1
   npos = npos+1
 end while
 nsoma = (11 - (nsoma mod 11))

if nsoma > 9 then
  modulo11 = 0
else
  modulo11 = nsoma
end if
End Function

Public Function ValidaCPF(cpf As String)
Dim sCPF As String

If (cpf.length = 14) Then
  sCPF = cpf.Substring(0, 3) + cpf.Substring(4, 3) + cpf.Substring(8, 3) + _
	 cpf.Substring(12, 2)
  If ((modulo11(sCPF, 1) = CInt(cpf.Substring(12, 1))) And _
     (modulo11(sCPF, 2) = CInt(cpf.Substring(13, 1)))) Then
   ValidaCPF = True
  Else
   ValidaCPF = False
  End If
Else
 ValidaCPF = False
End If
End Function

Public Function ValidaISBN(isbn As String)
Dim snum  As String, sdigito As String, sisbn As String
Dim nvalor As Integer, nsoma As Integer
Dim nstatus As Integer, ncont As Integer

If (isbn.length = 13) Then
  sdigito = isbn.Substring(isbn.length()-1, 1)
  sisbn=""
  for ncont=0 to isbn.length()-2
    if isbn.Substring(ncont,1)<>"-" then
      sisbn=sisbn + isbn.Substring(ncont,1)
    end if
  next ncont
  if sdigito = "X" then
    nsoma = 10
  else
    nvalor = CInt(sdigito)
    nsoma = nvalor
  end if
  for ncont = 1 to 9
    snum = sisbn.Substring(ncont-1, 1)
    nvalor = CInt(snum)
    nsoma = nsoma + (nvalor * (11 - ncont))
  next ncont
  If (nsoma mod 11) = 0 Then
    validaISBN = true
  else
    validaISBN = false
  end if
Else
 ValidaISBN = False
End If
End Function

Overloads public function ConsultaDados(Consulta as OleDbCommand, sTextoSql as string) as boolean
dim nTemLinhas as boolean = false

  Consulta = frmPrincipal.fPrincipal.db.CreateCommand()
  Consulta.CommandText = sTextoSql

  dim Leitor as OleDbDataReader = Consulta.ExecuteReader()
  nTemLinhas = Leitor.HasRows
  Leitor.Close()
  ConsultaDados = nTemLinhas
end function

Overloads public function ConsultaDados(dsConsulta as DataSet, _
		Registros as ArrayList, sTextoSql as string) as boolean
dim nTemLinhas as boolean = false

  dsConsulta.Clear()
  dim Consulta as OleDbCommand = new OleDbCommand()
  dim daConsulta as OleDbDataAdapter = new OleDbDataAdapter()

  daConsulta.TableMappings.Add("Table","Consulta")
  Consulta = frmPrincipal.fPrincipal.db.CreateCommand()
  Consulta.CommandText=sTextoSql
  daConsulta.SelectCommand = Consulta
  daConsulta.Fill(dsConsulta)

  Registros.Clear()
  dim Leitor as OleDbDataReader = Consulta.ExecuteReader()
  while Leitor.Read()
	 dim Campos as ArrayList = new ArrayList()
	 for cont as integer = 0 to (Leitor.FieldCount - 1)
	   Campos.Add(Leitor.GetValue(cont).ToString())
	 next cont
	 Registros.Add(Campos)
  end while

  nTemLinhas = Leitor.HasRows
  Leitor.Close()
  ConsultaDados = nTemLinhas
end function

Overloads public function ConsultaDados(Registros as ArrayList, sTextoSql as string) as boolean
dim nTemLinhas as boolean = false

  dim Consulta as OleDbCommand = frmPrincipal.fPrincipal.db.CreateCommand()
  Consulta.CommandText = sTextoSql

  Registros.Clear()
  dim Leitor as OleDbDataReader = Consulta.ExecuteReader()
  while Leitor.Read()
	 dim Campos as ArrayList = new ArrayList()
	 for cont as integer = 0 to (Leitor.FieldCount - 1)
	   Campos.Add(Leitor.GetValue(cont).ToString())
	 next cont
	 Registros.Add(Campos)
  end while
  nTemLinhas = Leitor.HasRows
  Leitor.Close()
  ConsultaDados = nTemLinhas

end function

Public Function ValidaCampo(sCampo As String, sMensagemErro As String) As Boolean
ValidaCampo = False
  If sCampo = "" Then
	MessageBox.Show(sMensagemErro, "Erro", _
    MessageBoxButtons.OK,MessageBoxIcon.Error)
    ValidaCampo = True
  End If
End Function

Public Function ConsultaCampoDesc(Campos As ArrayList, _
		sTextoSql As String, sMensagemErro As String) As String

  dim Consulta as OleDbCommand = frmPrincipal.fPrincipal.db.CreateCommand()
  Consulta.CommandText = sTextoSql
 
  Campos.Clear()
  dim Leitor as OleDbDataReader = Consulta.ExecuteReader()
  if Leitor.Read() then
	 for cont as integer = 0 to (Leitor.FieldCount - 1)
	   Campos.Add(Leitor.GetValue(cont).ToString())
	 next cont
  end if
  dim nTemLinhas as boolean = Leitor.HasRows
  Leitor.Close()

  if nTemLinhas then
	 return Campos(1).ToString()
  else 
	MessageBox.Show(sMensagemErro, "Erro", _
	MessageBoxButtons.OK,MessageBoxIcon.Error)
	return ""
  end if
End Function

public Function ConsultaCampoDesc(Campos As ArrayList,sCampoCodigo As String, _
			sTextoSql As String, sMensagemErro As String) As String
  if ValidaInteger(sCampoCodigo) then
    return ConsultaCampoDesc(Campos, sTextoSql, sMensagemErro)
  else
    return ""
  End if
End Function

public function retDataStr(sData As DateTime, formato as string) as String
  return sData.ToString(formato)
end function

public function FormataDataStr(sData As String, formato As String) As String
  dim dtNasc As DateTime = DateTime.Parse(sData)
  return dtNasc.ToString(formato)
end function

public Sub AdicionaItemLista(lstLista As ListBox, _
	 slCodLista As ArrayList, sCampoCodigo As TextBox, sCampoDesc As TextBox)

dim sItems As String

  if sCampoDesc.Text<>"" then
     sItems=sCampoCodigo.Text + " - " + sCampoDesc.Text
     if lstLista.Items.IndexOf(sItems)=-1 then 
    	slCodLista.Add(sCampoCodigo.Text)
    	lstLista.Items.Add(sItems)
     end if
     sCampoCodigo.Clear()
     sCampoDesc.Clear()
  end if
End Sub

public Sub RemoveItemLista(lstLista As ListBox, slCodLista As ArrayList)
 if lstLista.Items.Count > 0 then
   slCodLista.RemoveAt(lstLista.SelectedIndex)
   lstLista.Items.RemoveAt(lstLista.SelectedIndex)
 end if
End Sub

public Sub AdicionaValoresLista(ConsLista As ArrayList, _
	 sTextoSql As String,lstLista As ListBox, slCodLista As ArrayList)

 ConsLista.Clear()
 lstLista.Items.Clear()
 slCodLista.Clear()

  dim Consulta As OleDbCommand = frmPrincipal.fPrincipal.db.CreateCommand()
  Consulta.CommandText = sTextoSql

  dim Leitor As OleDbDataReader = Consulta.ExecuteReader()
  while Leitor.Read()
    slCodLista.Add(Leitor.GetValue(0).ToString())
    lstLista.Items.Add(Leitor.GetValue(0).ToString()+" - "+ _
    Leitor.GetValue(1).ToString())
  end while
  Leitor.Close()

End Sub

End Class

End NameSpace

