DEFINE CLASS Cadastros AS CUSTOM
*------------------------------------------------------------------------------------
Function ValidaDados()
LParameters frmCad, bTodosDados, sDesc

If Rotinas.ValidaCampo(frmCad.edtCodigo.Value, "C�digo n�o informado!")
    Return .F.
EndIf
If bTodosDados
  If Rotinas.ValidaCampo(frmCad.edtDescricao.Value, sDesc + " n�o informado!")
    Return .F.
  EndIf
EndIf

Return .T.
EndFunc
*------------------------------------------------------------------------------------
Procedure LimpaDados()
LParameters frmCad

    *If bInformar
      *frmCad.edtCodigo.Value = LTrim(Str(curConsulta.Codigo))
      *frmCad.edtDescricao.Value = curConsulta.Assunto
    *Else
      frmCad.edtCodigo.Value = ""
      frmCad.edtDescricao.Value = ""
      frmCad.edtCodigo.Enabled = .T.
      frmCad.edtCodigo.SetFocus
    *EndIf
EndProc
*------------------------------------------------------------------------------------
Procedure HabilitaDados()
LParameters frmCad, bHabilita

    frmCad.edtDescricao.Enabled = bHabilita
EndProc
*------------------------------------------------------------------------------------
Procedure btnFechar()
LParameters frmCad

    frmCad.release
EndProc
*------------------------------------------------------------------------------------
Procedure frmUnload()
LParameters Consulta
    
  Rotinas.FecharCursor(Consulta)     
EndProc
*------------------------------------------------------------------------------------
Procedure btnNovo()
LParameters frmCad

    frmCad.btnSalvar.Enabled = .T.
    frmCad.btnExcluir.Enabled = .F.
    frmCad.btnPesquisar.Enabled = .F.
    frmCad.btnAnterior.Enabled = .F.
    frmCad.btnProximo.Enabled = .F.
    frmCad.btnNovo.Enabled = .F.
    
    *This.InformaLimpaDados(frmCad, Consulta, .F.)
    This.LimpaDados(frmCad)
    This.HabilitaDados(frmCad, .T.)
EndProc
*------------------------------------------------------------------------------------
Function NovoDado()
LParameters frmCad, Consulta, sTextoSql

    If Rotinas.ConsultaDados(Consulta, sTextoSql)   
       *frmCad.edtCodigo.Value = LTrim(Str(curConsulta.Codigo))
       *copy to array vetConsulta
       *frmCad.edtCodigo.Value = LTrim(Str(vetConsulta[1,1]))
       frmCad.edtCodigo.Enabled = .F.
       frmCad.edtDescricao.SetFocus
       Return .T.
    Else
       Return .F.	   
    EndIf
EndFunc
*------------------------------------------------------------------------------------
Procedure btnLimpar()
LParameters frmCad

    frmCad.btnSalvar.Enabled = .F.
    frmCad.btnExcluir.Enabled = .F.
    frmCad.btnPesquisar.Enabled = .T.
    frmCad.btnAnterior.Enabled = .F.
    frmCad.btnProximo.Enabled = .F.
    frmCad.btnNovo.Enabled = .T.
    
    *This.InformaLimpaDados(frmCad, Consulta, .F.)
    This.LimpaDados(frmCad)
    This.HabilitaDados(frmCad, .F.)
EndProc
*------------------------------------------------------------------------------------
Function ExcluirDados()
LParameters frmCad, bValidaDados,Consulta, sTextoSql

     If bValidaDados
     	IF MESSAGEBOX("Certeza de excluir?", 36, "Exclus�o") = 6
            Rotinas.AtualizaDados(Consulta, sTextoSql)
            This.btnLimpar(frmCad)
            Return .T.
        Else
            Return .F.
        EndIf
    EndIf
EndFunc
*------------------------------------------------------------------------------------
Function PesquisarDados()
LParameters frmCad, Consulta, sTextoSql, sMensagemErro

    If frmCad.edtCodigo.Value = ""
        frmCad.btnAnterior.Enabled = .T.
        frmCad.btnProximo.Enabled = .T.
    EndIf
    If Rotinas.ConsultaDados(Consulta, sTextoSql)
         *This.InformaLimpaDados(frmCad, Consulta, .T.)
         This.HabilitaDados(frmCad, .T.)
        
         frmCad.btnSalvar.Enabled = .T.
         frmCad.btnExcluir.Enabled = .T.
         frmCad.btnPesquisar.Enabled = .F.
         Return .T.
    Else
        MESSAGEBOX(sMensagemErro, 64, "Livrus Virtus")
        Return .F.
    EndIf
EndFunc
*------------------------------------------------------------------------------------
Function btnAnterior()
LParameters frmCad, Consulta

	select &Consulta

    If RecNo() > 1
        goto record (RecNo()-1)
        *This.InformaLimpaDados(frmCad, Consulta, .T.)
        Return .T.
    Else
        Return .F.
    EndIf
EndFunc
*------------------------------------------------------------------------------------
Function btnProximo()
LParameters frmCad, Consulta

	select &Consulta
	
    If RecNo() < RecCount() 
        goto record (RecNo()+1)
        *This.InformaLimpaDados(frmCad, Consulta, .T.)        
        Return .T.
    Else
        Return .F.
    EndIf
EndFunc
*------------------------------------------------------------------------------------
Function SalvarDados()
LParameters frmCad, bValidaDados, Consulta, Arquiva,;
sTextoSql, sTextoUpdate, sTextoInsert, bLimparDados

Local sArquiva

    If bValidaDados 
       If Rotinas.ConsultaDados(Arquiva, sTextoSql)
         sArquiva = sTextoUpdate
       Else
         sArquiva = sTextoInsert
       EndIf
       Rotinas.AtualizaDados(Consulta, sArquiva)
       If bLimparDados 
          This.btnLimpar(frmCad)
       EndIf
       Return .T.
    else
       Return .F.
    EndIf    
EndFunc
*------------------------------------------------------------------------------------
Procedure frmMouseMove()
LParameters frmCad

	set message to frmCad.Caption
EndProc
*------------------------------------------------------------------------------------
Procedure frmLoad()
LParameters frmCad

    frmCad.Height = 136
    frmCad.Width = 330
EndProc
*------------------------------------------------------------------------------------
Procedure edtCodigoLostFocus()
LParameters frmCad

    If alltrim(frmCad.edtCodigo.Value) <> ""
      If Rotinas.ValidaInteger(alltrim(frmCad.edtCodigo.Value)) = .F.
        frmCad.edtCodigo.Value = ""
        frmCad.edtCodigo.SetFocus
      Endif
    EndIf
EndProc
*------------------------------------------------------------------------------------
ENDDEFINE
