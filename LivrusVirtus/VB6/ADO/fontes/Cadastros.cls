VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsCadastros"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Attribute VB_Ext_KEY = "SavedWithClassBuilder6" ,"Yes"
Attribute VB_Ext_KEY = "Top_Level" ,"Yes"

Public Sub InformaLimpaDados(frmCad As Form, ByVal Consulta As ADODB.Recordset, bInformar As Boolean)
    If bInformar Then
      frmCad.edtCodigo.Text = Consulta.Fields.Item(0).Value
      frmCad.edtDescricao.Text = Consulta.Fields.Item(1).Value
    Else
      frmCad.edtCodigo.Text = ""
      frmCad.edtDescricao.Text = ""
      frmCad.edtCodigo.Enabled = True
      frmCad.edtCodigo.SetFocus
    End If
End Sub

Public Sub HabilitaDados(frmCad As Form, bHabilita As Boolean)
    frmCad.edtDescricao.Enabled = bHabilita
End Sub

Public Sub btnFechar(frmCad As Form)
    Unload frmCad
End Sub

Public Sub btnNovo(frmCad As Form, ByVal Consulta As ADODB.Recordset)
    frmCad.btnSalvar.Enabled = True
    frmCad.btnExcluir.Enabled = False
    frmCad.btnPesquisar.Enabled = False
    frmCad.btnAnterior.Enabled = False
    frmCad.btnProximo.Enabled = False
    frmCad.btnNovo.Enabled = False
    
    InformaLimpaDados frmCad, Consulta, False
    HabilitaDados frmCad, True
End Sub

Public Sub NovoDado(frmCad As Form, ByVal Consulta As ADODB.Recordset, sTextoSql As String)
    If Rotinas.ConsultaDados(Consulta, sTextoSql) Then
       frmCad.edtCodigo.Text = Consulta.Fields.Item(0).Value
       frmCad.edtCodigo.Enabled = False
       frmCad.edtDescricao.SetFocus
    End If
End Sub

Public Sub btnLimpar(frmCad As Form, ByVal Consulta As ADODB.Recordset)
    frmCad.btnSalvar.Enabled = False
    frmCad.btnExcluir.Enabled = False
    frmCad.btnPesquisar.Enabled = True
    frmCad.btnAnterior.Enabled = False
    frmCad.btnProximo.Enabled = False
    frmCad.btnNovo.Enabled = True
    
    InformaLimpaDados frmCad, Consulta, False
    HabilitaDados frmCad, False
End Sub

Public Function ExcluirDados(frmCad As Form, bValidaDados As Boolean, _
ByVal Consulta As ADODB.Recordset, sTextoSql As String) As Boolean
 On Error GoTo Erro
     If bValidaDados Then
        If MsgBox("Certeza de excluir?", vbYesNo + vbQuestion) = vbYes Then
            db.Execute sTextoSql
            btnLimpar frmCad, Consulta
            ExcluirDados = True
        Else
            ExcluirDados = False
        End If
    End If
Erro:
    If Err <> 0 Then
      MsgBox Err.Source & ": " & Err.Description, vbCritical + vbOKOnly, "Erro"
    End If
End Function

Public Function PesquisarDados(frmCad As Form, ByVal Consulta As ADODB.Recordset, _
sTextoSql As String, sMensagemErro As String) As Boolean
    If frmCad.edtCodigo.Text = "" Then
        frmCad.btnAnterior.Enabled = True
        frmCad.btnProximo.Enabled = True
    End If
    If Rotinas.ConsultaDados(Consulta, sTextoSql) Then
         InformaLimpaDados frmCad, Consulta, True
         HabilitaDados frmCad, True
        
         frmCad.btnSalvar.Enabled = True
         frmCad.btnExcluir.Enabled = True
         frmCad.btnPesquisar.Enabled = False
         PesquisarDados = True
    Else
        MsgBox sMensagemErro, vbInformation + vbOKOnly
        PesquisarDados = False
    End If
End Function

Public Function btnAnterior(frmCad As Form, ByVal Consulta As ADODB.Recordset) As Boolean
    If Consulta.AbsolutePosition > 1 Then
        Consulta.MovePrevious
        InformaLimpaDados frmCad, Consulta, True
        btnAnterior = True
    Else
        btnAnterior = False
    End If
End Function

Public Function btnProximo(frmCad As Form, ByVal Consulta As ADODB.Recordset) As Boolean
    If Consulta.AbsolutePosition < Consulta.RecordCount Then
        Consulta.MoveNext
        InformaLimpaDados frmCad, Consulta, True
        btnProximo = True
    Else
        btnProximo = False
    End If
End Function

Public Sub SalvarDados(frmCad As Form, bValidaDados As Boolean, _
ByVal Consulta As ADODB.Recordset, ByVal Arquiva As ADODB.Recordset, _
sTextoSql As String, sTextoUpdate As String, sTextoInsert As String, _
bLimparDados As Boolean)

Dim sArquiva As String

On Error GoTo Erro
    If bValidaDados Then
       If Rotinas.ConsultaDados(Arquiva, sTextoSql) Then
         Arquiva.Close
         sArquiva = sTextoUpdate
       Else
         Arquiva.Close
         sArquiva = sTextoInsert
       End If
       db.Execute sArquiva
       If bLimparDados Then
          btnLimpar frmCad, Consulta
       End If
    End If
Erro:
    If Err <> 0 Then
      MsgBox Err.Source & ": " & Err.Description, vbCritical + vbOKOnly, "Erro"
    End If
End Sub

Public Sub frmMouseMove(frmCad As Form)
    fPrincipal.sbStatusBar.Panels.Item(2).Text = frmCad.Caption
End Sub

Public Sub edtCodigoLostFocus(frmCad As Form)
    If frmCad.edtCodigo.Text <> "" Then
      If Rotinas.ValidaInteger(frmCad.edtCodigo.Text) = False Then
        frmCad.edtCodigo.Clear
        frmCad.edtCodigo.SetFocus
      End If
    End If
End Sub

Public Sub frmLoad(frmCad As Form)
    frmCad.Height = 2505
    frmCad.Width = 5055
End Sub

