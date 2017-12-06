VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsRotinas"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Public sUsuarioLogin, sUsuarioSenha As String
Public sCodigoSelecionado, sPreco, sQtdEstoque, sConexao As String

Sub ConectaBanco()
  Set db = New ADODB.Connection
  db.CursorLocation = adUseClient
  'sConexao = "FILE NAME=" & App.Path & "\Access97_Livrus.udl"
  sConexao = "FILE NAME=C:\LivrusVirtus\Bancos\access\Access2K_Livrus.udl"
  db.Open sConexao
End Sub

Public Function ConsultaDadosX(Consulta As Adodc, _
sTextoSql As String, ByVal gridConsulta As MSDataGridLib.DataGrid) As Boolean
Dim cont, numCols As Integer

  Consulta.ConnectionString = sConexao
  Consulta.RecordSource = sTextoSql
  Consulta.Refresh
  numCols = Consulta.Recordset.Fields.Count
  
  For cont = 0 To numCols - 1

    If cont >= gridConsulta.Columns.Count Then
       gridConsulta.Columns.Add cont
    End If
        
    gridConsulta.Columns(cont).DataField = Consulta.Recordset.Fields.Item(cont).Name
    gridConsulta.Columns(cont).Caption = Consulta.Recordset.Fields.Item(cont).Name
    If Consulta.Recordset.Fields.Item(cont).Type = adSmallInt Then
       gridConsulta.Columns(cont).Width = 1000
    ElseIf Consulta.Recordset.Fields.Item(cont).Type = adVarWChar Then
       If Len(Consulta.Recordset.Fields.Item(cont).Name) > Consulta.Recordset.Fields.Item(cont).DefinedSize Then
          gridConsulta.Columns(cont).Width = Len(Consulta.Recordset.Fields.Item(cont).Name) * 200
       Else
          gridConsulta.Columns(cont).Width = Consulta.Recordset.Fields.Item(cont).DefinedSize * 100
       End If
    ElseIf Consulta.Recordset.Fields.Item(cont).Type = adDate Then
       gridConsulta.Columns(cont).Width = 2000
    ElseIf Consulta.Recordset.Fields.Item(cont).Type = adSingle Then
       gridConsulta.Columns(cont).Width = 1000
    End If
  Next cont
  gridConsulta.Refresh
  
  ConsultaDadosX = (Consulta.Recordset.RecordCount > 0)
End Function

Public Function ConsultaDados(ByVal Consulta As ADODB.Recordset, sTextoSql As String) As Boolean
    If sTextoSql <> "" Then
      If Consulta.State = adStateOpen Then
         Consulta.Close
      End If
      Consulta.Open sTextoSql, db, adOpenStatic, adLockOptimistic
      If Consulta.RecordCount > 0 Then
         Consulta.MoveLast
         Consulta.MoveFirst
      End If
      ConsultaDados = (Consulta.RecordCount > 0)
    Else
      ConsultaDados = False
    End If
End Function

Public Function ColecaoIndiceDe(Colecao As Collection, sItem As String) As Integer
Dim nCont As Integer

ColecaoIndiceDe = -1

  For nCont = 1 To Colecao.Count
   If Colecao(nCont) = sItem Then
      ColecaoIndiceDe = nCont
      Exit For
   End If
  Next nCont
End Function

Public Sub LimpaColecao(Colecao As Collection)
Dim nCont As Integer

  For nCont = Colecao.Count To 1 Step -1
    Colecao.Remove nCont
  Next nCont
End Sub

Public Function ListaIndiceDe(lst As ListBox, sItem As String) As Integer
Dim nCont As Integer

ListaIndiceDe = -1
 
 For nCont = 0 To lst.ListCount - 1
   If lst.List(nCont) = sItem Then
      ListaIndiceDe = nCont
   End If
 Next nCont
 
End Function

Public Function ValidaCampo(sCampo As String, sMensagemErro As String) As Boolean
ValidaCampo = False
  If sCampo = "" Then
    MsgBox sMensagemErro, vbInformation + vbOKOnly, App.Title
    ValidaCampo = True
  End If
End Function

Public Function ValidaInteger(snum As String) As Boolean
If snum <> "" Then
      'CInteger sNum
      If IsNumeric(snum) Then
         ValidaInteger = True
      Else
         MsgBox "Número inválido!", vbCritical + vbOKOnly, "Erro"
         ValidaInteger = False
      End If
Else
   ValidaInteger = False
End If
End Function


Public Function ValidaFloat(snum As String) As Boolean
If snum <> "" Then
      'CInteger sNum
      If IsNumeric(snum) Then
         ValidaFloat = True
      Else
         MsgBox "Número inválido!", vbCritical + vbOKOnly, "Erro"
         ValidaFloat = False
      End If
Else
   ValidaFloat = False
End If
End Function

Public Function ValidaDateTime(snum As String) As Boolean
If snum <> "" Then
      If IsDate(snum) Then
         ValidaDateTime = True
      Else
         MsgBox "Data/Hora inválida!", vbCritical + vbOKOnly, "Erro"
         ValidaDateTime = False
      End If
Else
   ValidaDateTime = False
End If
End Function

Public Function VirgulaParaPonto(snum As String, bRevertido As Boolean) As String
Dim cont As Integer
Dim sPedaco, sRet, sVirgula, sPonto As String

If bRevertido Then
   sVirgula = "."
   sPonto = ","
Else
   sVirgula = ","
   sPonto = "."
End If

 For cont = 1 To Len(snum)
    sPedaco = Mid(snum, cont, 1)
    If sPedaco = sVirgula Then
       sRet = sRet & sPonto
    Else
       sRet = sRet & sPedaco
    End If
 Next cont
 VirgulaParaPonto = sRet
End Function

Private Function modulo11(sValor As String, ndig As Integer)
Dim nCont As Integer, nsoma As Integer
Dim nvalor As Integer, npos As Integer
Dim sres As String, slocal As String

 nCont = 1
 Do While nCont <= 11
   slocal = Mid(sValor, nCont, 1) + slocal
   nCont = nCont + 1
 Loop
 nsoma = 0
 If ndig = 1 Then
   nCont = 3
 Else
   nCont = 2
 End If
 npos = 2
 Do While nCont <= 11
   sres = Mid(slocal, nCont, 1)
   nvalor = Val(sres)
   nsoma = nsoma + (nvalor * npos)
   nCont = nCont + 1
   npos = npos + 1
 Loop
 nsoma = (11 - (nsoma Mod 11))

 If nsoma > 9 Then
   modulo11 = 0
 Else
   modulo11 = nsoma
 End If
End Function

Public Function ValidaCPF(cpf As String)
Dim sCPF As String

If (Len(cpf) = 14) Then
  sCPF = Mid(cpf, 1, 3) + Mid(cpf, 5, 3) + Mid(cpf, 9, 3) + Mid(cpf, 13, 2)
  If ((modulo11(sCPF, 1) = CInt(Mid(cpf, 13, 1))) _
     And (modulo11(sCPF, 2) = CInt(Mid(cpf, 14, 1)))) Then
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
Dim nvalor As Integer, nsoma As Integer, nCont As Integer

If Len(isbn) = 13 Then
  sdigito = Mid(isbn, Len(isbn), 1)
  sisbn = ""
  For nCont = 1 To Len(isbn) - 1
    If Mid(isbn, nCont, 1) <> "-" Then
      sisbn = sisbn + Mid(isbn, nCont, 1)
    End If
  Next nCont
  If sdigito = "X" Then
    nsoma = 10
  Else
    nvalor = CInt(sdigito)
    nsoma = nvalor
  End If
  For nCont = 1 To 9
    snum = Mid(sisbn, nCont, 1)
    nvalor = Val(snum)
    nsoma = nsoma + (nvalor * (11 - nCont))
  Next nCont
  If (nsoma Mod 11) = 0 Then
    ValidaISBN = True
  Else
    ValidaISBN = False
  End If
Else
 ValidaISBN = False
End If
End Function

Public Function ConsultaCampoDesc(ByVal Consulta As ADODB.Recordset, _
sCampoCodigo As String, sTextoSql As String, sMensagemErro As String) As String

If ValidaInteger(sCampoCodigo) Then
  ConsultaCampoDesc = ConsultaCampoDescX(Consulta, sTextoSql, sMensagemErro)
Else
  ConsultaCampoDesc = ""
End If
End Function

Public Function ConsultaCampoDescX(ByVal Consulta As ADODB.Recordset, _
sTextoSql As String, sMensagemErro As String) As String
  If ConsultaDados(Consulta, sTextoSql) Then
     ConsultaCampoDescX = Consulta.Fields(1).Value
  Else
    MsgBox sMensagemErro, vbCritical + vbOKOnly, "Erro"
    result = ""
  End If
End Function

Private Function AchaValorLista(ByVal lstLista As ListBox, sValor As String) As Boolean
Dim nCont As Integer
    AchaValorLista = False
    For nCont = 0 To lstLista.ListCount - 1
        If lstLista.List(nCont) = sValor Then
            AchaValorLista = True
            Exit For
        End If
    Next nCont
End Function

Public Sub AdicionaItemLista(ByVal lstLista As ListBox, _
ByVal slCodLista As Collection, ByVal sCampoCodigo As TextBox, _
ByVal sCampoDesc As TextBox)
Dim sItems As String
If sCampoDesc.Text <> "" Then
 sItems = sCampoCodigo.Text & " - " & sCampoDesc.Text
 If AchaValorLista(lstLista, sItems) = False Then
    slCodLista.Add sCampoCodigo.Text
    lstLista.AddItem sItems
  End If
 sCampoCodigo.Text = ""
 sCampoDesc.Text = ""
End If
End Sub

Public Sub RemoveItemLista(ByVal lstLista As ListBox, ByVal slCodLista As Collection)
 If lstLista.ListCount > 0 Then
   slCodLista.Remove lstLista.ListIndex + 1
   lstLista.RemoveItem lstLista.ListIndex
 End If
End Sub

Public Sub AdicionaValoresLista(ByVal ConsLista As ADODB.Recordset, _
sTextoSql As String, ByVal lstLista As ListBox, ByVal slCodLista As Collection)
 lstLista.Clear
 'slCodLista.Clear
 
  ConsultaDados ConsLista, sTextoSql
 
 Do While Not ConsLista.EOF
  slCodLista.Add ConsLista.Fields.Item(0).Value
  lstLista.AddItem ConsLista.Fields.Item(0).Value & " - " & _
  ConsLista.Fields.Item(1).Value
  ConsLista.MoveNext
 Loop
End Sub

Public Sub ChamarTela(Tela As Form)
  CentralizaFrm Tela
  Tela.Show vbModal
End Sub

Public Sub CentralizaFrm(frm As Form)
  If (frm.Height > Screen.Height) Then
    frme.Height = Screen.Height
  End If
  If (frm.Width > Screen.Width) Then
    frm.Width = Screen.Width
  End If
  frm.Left = (Screen.Width - frm.Width) / 2
  frm.Top = (Screen.Height - frm.Height) / 2
End Sub



