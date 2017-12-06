VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
  Persistable = 0  'NotPersistable
  DataBindingBehavior = 0  'vbNone
  DataSourceBehavior  = 0  'vbNone
  MTSTransactionMode  = 0  'NotAnMTSObject
END
Attribute VB_Name = "clsConsultas"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = True
Attribute VB_PredeclaredId = False
Attribute VB_Exposed = False
Public Sub btnFechar(frmCon As Form)
    Unload frmCon
End Sub

Public Sub frmMouseMove(frmCon As Form)
    fPrincipal.sbStatusBar.Panels.Item(2).Text = frmCon.Caption
End Sub

Public Sub frmUnload(Consulta As Adodc)
    If Consulta.Recordset.RecordCount > 0 Then
       Rotinas.sCodigoSelecionado = Consulta.Recordset.Fields.Item(0).Value
    End If
End Sub

Public Sub LimparDados(frmCon As Form, Consulta As Adodc, sTextoSql As String, _
ByVal gridConsulta As MSDataGridLib.DataGrid)
  frmCon.labRegistros.Caption = "Registro 0 de 0"
  Rotinas.ConsultaDadosX Consulta, sTextoSql, gridConsulta
  frmCon.btnPesquisar.Enabled = True
  frmCon.edtDescricao.Text = ""
  frmCon.edtDescricao.SetFocus
End Sub

Public Function PesquisarDados(frmCon As Form, Consulta As Adodc, _
sTextoSql As String, sMensagemErro As String, _
ByVal gridConsulta As MSDataGridLib.DataGrid) As Boolean

  If Rotinas.ConsultaDadosX(Consulta, sTextoSql, gridConsulta) Then
     frmCon.btnPesquisar.Enabled = False
     PesquisarDados = True
  Else
     MsgBox sMensagemErro, vbInformation + vbOKOnly
     PesquisarDados = False
  End If
End Function

Public Sub ConsultaChange(frmCon As Form, Consulta As Adodc)
    frmCon.labRegistros.Caption = "Registro " & CStr(Consulta.Recordset.AbsolutePosition) & _
    " de " & CStr(Consulta.Recordset.RecordCount)
End Sub

Public Sub frmLoad(frmCon As Form)
    frmCon.Height = 4275
    frmCon.Width = 5580
End Sub

Public Sub frmResize(frmCon As Form, gridCon As MSDataGridLib.DataGrid)
  gridCon.Height = Abs(frmCon.Height + gridCon.Top - 2430)
  frmCon.btnLimpar.Left = frmCon.Width - 2420
  frmCon.btnFechar.Left = frmCon.Width - 1260
End Sub

