VERSION 1.0 CLASS
BEGIN
  MultiUse = -1  'True
END
Attribute VB_Name = "clsConsultas"
Attribute VB_Creatable = True
Attribute VB_Exposed = False

Public Sub btnFechar(frmCon As Form)
    Unload frmCon
End Sub

Public Sub frmMouseMove(frmCon As Form)
    fPrincipal.sbStatusBar.Panels.Item(2).Text = frmCon.Caption
End Sub

Public Sub frmUnload(Consulta As Data)
    If Consulta.Recordset.RecordCount > 0 Then
       Rotinas.sCodigoSelecionado = Consulta.Recordset.Fields.Item(0).Value
    End If
End Sub

Public Sub LimparDados(frmCon As Form, _
Consulta As Data, sTextoSql As String, _
gridConsulta As DBGrid)
  frmCon.labRegistros.Caption = "Registro 0 de 0"
  Rotinas.ConsultaDadosX Consulta, sTextoSql, gridConsulta
  frmCon.btnPesquisar.Enabled = True
  frmCon.edtDescricao.Text = ""
  frmCon.edtDescricao.SetFocus
End Sub

Public Function PesquisarDados(frmCon As Form, Consulta As Data, _
sTextoSql As String, sMensagemErro As String, _
gridConsulta As DBGrid) As Boolean

  If Rotinas.ConsultaDadosX(Consulta, sTextoSql, gridConsulta) Then
     frmCon.btnPesquisar.Enabled = False
     PesquisarDados = True
  Else
     MsgBox sMensagemErro, vbInformation + vbOKOnly
     PesquisarDados = False
  End If
End Function

Public Sub ConsultaChange(frmCon As Form, Consulta As Data)
    frmCon.labRegistros.Caption = "Registro " & CStr(Consulta.Recordset.AbsolutePosition + 1) & _
    " de " & CStr(Consulta.Recordset.RecordCount)
End Sub

Public Sub frmLoad(frmCon As Form)
    frmCon.Height = 4275
    frmCon.Width = 5580
End Sub

Public Sub frmResize(frmCon As Form, gridCon As DBGrid)
  gridCon.Height = Abs(frmCon.Height + gridCon.Top - 2430)
  frmCon.btnLimpar.Left = frmCon.Width - 2420
  frmCon.btnFechar.Left = frmCon.Width - 1260
End Sub
