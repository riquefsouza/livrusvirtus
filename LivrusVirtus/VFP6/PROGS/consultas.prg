DEFINE CLASS Consultas AS CUSTOM
*------------------------------------------------------------------------------------
Procedure btnFechar()
LParameters frmCon

    frmCon.release
EndProc
*------------------------------------------------------------------------------------
Procedure frmMouseMove()
LParameters frmCon

	set message to frmCon.Caption
EndProc
*------------------------------------------------------------------------------------
Function frmUnload()
LParameters Consulta
	
	select &Consulta

    If reccount() > 0
       Return .T.
    Else
       Return .F.    
    EndIf   
EndFunc
*------------------------------------------------------------------------------------
Procedure frmLoad()
LParameters frmCon

    frmCon.Height = 238
    frmCon.Width = 354
EndProc
*------------------------------------------------------------------------------------
Procedure LimparDados()
LParameters frmCon, Consulta, sTextoSql, gridConsulta

  frmCon.labRegistros.Caption = "Registro 0 de 0"
  Rotinas.ConsultaDadosX(Consulta, sTextoSql, gridConsulta)
  frmCon.btnPesquisar.Enabled = .T.
  frmCon.edtDescricao.Value = ""
  frmCon.edtDescricao.SetFocus
EndProc
*------------------------------------------------------------------------------------
Function PesquisarDados()
LParameters frmCon, Consulta, sTextoSql, sMensagemErro, gridConsulta

  If Rotinas.ConsultaDadosX(Consulta, sTextoSql, gridConsulta)
     frmCon.btnPesquisar.Enabled = .F.
     this.ConsultaChange(frmCon, Consulta)
     Return .T.
  Else
     MESSAGEBOX(sMensagemErro, 64, "Livrus Virtus")
     Return .F.
  EndIf
EndFunc
*------------------------------------------------------------------------------------
Procedure ConsultaChange()
LParameters frmCon, Consulta

	select &Consulta

    frmCon.labRegistros.Caption = "Registro " + alltrim(Str(RecNo())) +;
     " de " + alltrim(Str(RecCount()))
EndProc
*------------------------------------------------------------------------------------
Procedure frmResize()
LParameters frmCon, gridConsulta

  gridConsulta.Height = Abs(frmCon.Height - 90)
  gridConsulta.Width = frmCon.Width
  frmCon.btnLimpar.Left = frmCon.Width - 158
  frmCon.btnLimpar.Top = frmCon.Height - 28
  frmCon.btnFechar.Left = frmCon.Width - 78
  frmCon.btnFechar.Top = frmCon.Height - 28
  frmCon.LabRegistros.Top = frmCon.Height - 23
EndProc
*------------------------------------------------------------------------------------
ENDDEFINE
