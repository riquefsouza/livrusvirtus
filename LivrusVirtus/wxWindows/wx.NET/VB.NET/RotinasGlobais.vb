Imports System
Imports System.Collections
Imports System.Data
Imports System.Data.OleDb
Imports Microsoft.VisualBasic
Imports wx

Namespace Livrus

Public Class RotinasGlobais

public shared Rotinas as RotinasGlobais
public sUsuarioLogin, sUsuarioSenha, sBarraLogin as string
public sCodigoSelecionado, sPreco, sQtdEstoque as string
public gConexao as System.Data.OleDb.OleDbConnection
public shared sepDTHR as string = "#" 'SOMENTE ACCESS 
'public shared sepDTHR as string = "'" 'OUTROS BANCOS 

Public Sub New()
  MyBase.New()
  gConexao = new System.Data.OleDb.OleDbConnection()
End Sub

Public Function ValidaFloat(sNum As String) As Boolean
 if sNum<>"" then
	try
	  single.Parse(sNum)
	  ValidaFloat = true
	catch
    MessageDialog.MessageBox(Resource.STR_NUMINV, "Erro", _
      Dialog.wxOK or Dialog.wxICON_ERROR )
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

function validaDataHora(sDataHora as string, bSoData as Boolean) as Boolean
dim bvalida, bdatavalida, bhoravalida as boolean
dim sdia, smes, sano, shora, smin, sseg as string
dim ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam as integer

bvalida = false
bdatavalida = false
bhoravalida = false
nudiames = 0
if bSoData=true then 
  ntam=10
else 
  ntam=19
end if

if len(sDataHora)=ntam then
  sdia = mid(sDataHora,1,2)
  ndia = CInt(sdia)
  smes = mid(sDataHora,4,2)
  nmes = CInt(smes)
  sano = mid(sDataHora,7,4)
  nano = CInt(sano)
  
  if (nano >= 1) and (nano <= 9999) then
    if (nmes >= 1) and (nmes <= 31) then
      select nmes
        case 1, 3, 5, 7, 8, 10, 12
          nudiames = 31
        case 2
          ' ano bissexto 
          if (nano mod 4)=0 then 
            nudiames = 29
          else 
            nudiames = 28
          end if
        case 4, 6, 9, 11
          nudiames = 30
      end select
      if (ndia >=1) and (ndia <=nudiames) then
         bdatavalida = true
      end if
    end if
  end if

  if bSoData then
    if bdatavalida then
      bvalida = true
    else
      bvalida = false
    end if
  else 
    if bdatavalida then
      shora = mid(sDataHora,12,2)
      nhora = CInt(shora)
      smin = mid(sDataHora,15,2)
      nmin = CInt(smin)
      sseg = mid(sDataHora,18,2)
      nseg = CInt(sseg)
    
      if (nhora >= 0) and (nhora <= 23) then
        if (nmin >= 0) and (nmin <= 59) then
          if (nseg >= 0) and (nseg <= 59) then
            bhoravalida = true
          end if
        end if
      end if
    
      if bhoravalida then
        bvalida = true
      else
        bvalida = false
      end if
    else
      bvalida = false
    end if
  end if
else
  bvalida = false
end if
validaDataHora = bvalida
end function

public function retDataHoraStr(bData as boolean, bHora as boolean) as string
dim sDataHora as string = ""
dim sTempo as DateTime = DateTime.Now

if bData and bHora then
  sDataHora = sTempo.ToString("dd/MM/yyyy hh:mm:ss")
else if bData then
  sDataHora = sTempo.ToString("dd/MM/yyyy")
else if bHora then
  sDataHora = sTempo.ToString("hh:mm:ss")
end if
return sDataHora
end function

public function ConverteDataHoraStr(sData As String, formato As String) As String
  dim dtNasc As DateTime = DateTime.Parse(sData)
  return dtNasc.ToString(formato)
end function

public function ConectaBanco(sFonteDeDados as String) as Boolean
	gConexao.ConnectionString = sFonteDeDados
  gConexao.Open()

  if gConexao.State.ToString().Equals("Open") then
    return true
  else 
    MessageDialog.MessageBox(Resource.STR_NCONBANCO, "Erro", _
      Dialog.wxOK or Dialog.wxICON_ERROR )
    return false
  end if
end function

public sub DisconectaBanco()
  gConexao.Close()
end sub

public function AtualizaDados(Arquiva as OleDbCommand, _
  sTextoSql as String) as Boolean
  Arquiva = gConexao.CreateCommand()
  Arquiva.CommandText = sTextoSql
	if Arquiva.ExecuteNonQuery() > 0 then
	  Arquiva.Dispose()
    return true
  else
    'MessageDialog.MessageBox(Resource.STR_NCEXECSQL, "Erro", _
    '  Dialog.wxOK or Dialog.wxICON_ERROR )
    return false
  end if
end function

public function ConsultaDados(Consulta as OleDbCommand, _
  sTextoSql as string) as boolean
dim nTemLinhas as boolean = false

  Consulta = gConexao.CreateCommand()
  Consulta.CommandText = sTextoSql

  dim Leitor as OleDbDataReader = Consulta.ExecuteReader()
  nTemLinhas = Leitor.HasRows
  Leitor.Close()
  ConsultaDados = nTemLinhas
end function

public function ConsultaDadosLista(Registros as ArrayList, _
  sTextoSql as string) as boolean
dim nTemLinhas as boolean = false

  dim Consulta as OleDbCommand = gConexao.CreateCommand()
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
  ConsultaDadosLista = nTemLinhas
end function

Public Function ValidaCampo(sCampo As String, sMensagemErro As String) As Boolean
ValidaCampo = False
  If sCampo = "" Then
    MessageDialog.MessageBox(sMensagemErro, "Erro", _
      Dialog.wxOK or Dialog.wxICON_ERROR )
    ValidaCampo = True
  End If
End Function

Public Function ConsultaCampoDesc(Campos As ArrayList, _
		sTextoSql As String, sMensagemErro As String) As String

  dim Consulta as OleDbCommand = gConexao.CreateCommand()
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
    MessageDialog.MessageBox(sMensagemErro, "Erro", _
      Dialog.wxOK or Dialog.wxICON_ERROR ) 
  	return ""
  end if
End Function

public function PesquisaItemLista(lstLista as wx.ListBox, _
  sItem as string) as integer
  dim bret as integer = -1
  dim nLinha as integer

  for nLinha = 0 to lstLista.Count-1
    if lstLista.GetString(nLinha) = sItem then
      bret = 0
    end if
  next nLinha
  return bret
end function

public Sub AdicionaItemLista(lstLista As wx.ListBox, _
  slCodLista As ArrayList, sCampoCodigo As wx.TextCtrl, sCampoDesc As wx.TextCtrl)
dim sItems As String

  if sCampoDesc.Value<>"" then
     sItems=sCampoCodigo.Value + " - " + sCampoDesc.Value
     if PesquisaItemLista(lstLista, sItems) = -1 then 
    	slCodLista.Add(sCampoCodigo.Value)
    	lstLista.Append(sItems)
     end if
     sCampoCodigo.Clear()
     sCampoDesc.Clear()
  end if
End Sub

public Sub RemoveItemLista(lstLista As ListBox, slCodLista As ArrayList)
dim nSelIndice as integer = 0
  if lstLista.Count > 0 then
    nSelIndice = lstLista.Selection
    if lstLista.Selected(nSelIndice) then
      slCodLista.RemoveAt(nSelIndice)
      lstLista.Delete(nSelIndice)
    end if
  end if
End Sub

public Sub AdicionaValoresLista(sTextoSql As String, _
  lstLista As ListBox, slCodLista As ArrayList)

 lstLista.Clear()
 slCodLista.Clear()

  dim Consulta As OleDbCommand = gConexao.CreateCommand()
  Consulta.CommandText = sTextoSql

  dim Leitor As OleDbDataReader = Consulta.ExecuteReader()
  while Leitor.Read()
    slCodLista.Add(Leitor.GetValue(0).ToString())
    lstLista.Append(Leitor.GetValue(0).ToString()+" - "+ _
    Leitor.GetValue(1).ToString())
  end while
  Leitor.Close()

End Sub

public sub AdicionaColunasGrid(grid as wx.Grid, nPosIni as integer, _
  nQtdCols as integer, nLargura as integer(), sRotulos as string())
  dim nPos, nCont as integer
  
  if nPosIni > 0 then
    grid.AppendCols(nQtdCols)
  end if
  nCont = 0
  for nPos = nPosIni to (nPosIni+nQtdCols-1)
    grid.SetColSize(nPos, nLargura(nCont))
    grid.SetColLabelValue(nPos, sRotulos(nCont))
    nCont = nCont + 1
  next nPos
end sub

public sub AdicionaLinhasGrid(grid as wx.Grid, lstLinhas as ArrayList, _
  nQtdCol as integer)
  dim nCol, nLinha as integer
  dim lstCampos as ArrayList

  grid.DeleteRows(0, grid.NumberRows, true)
  grid.AppendRows(lstLinhas.Count, true)
  for nLinha = 0 to lstLinhas.Count-1
    lstCampos = CType(lstLinhas(nLinha),ArrayList)
    for nCol = 0 to nQtdCol-1
      grid.SetCellValue(nLinha, nCol, lstCampos(nCol).ToString())
    next nCol
  next nLinha
end sub

End Class

End NameSpace

