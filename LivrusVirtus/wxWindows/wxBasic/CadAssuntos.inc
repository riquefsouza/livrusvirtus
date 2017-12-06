option explicit

dim common frmCadAssuntos

function frmCadAssuntos_Criar(parent)
  dim fCadAssuntos = frmCadastros_Criar(parent, 0, True)

  frmCadastros_labDescricao.SetLabel("Assunto: ")

  Connect( fCadAssuntos, wxEVT_CLOSE_WINDOW, "frmCadAssuntos_OnClose" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnNovo" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnPesquisar" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnAnterior" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnProximo" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnSalvar" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnExcluir" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnFechar" )
  Connect( fCadAssuntos, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAssuntos_OnBtnLimpar" )

  return fCadAssuntos
end function

function frmCadAssuntos_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_ASSNINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadAssuntos_OnClose( event )
  frmCadAssuntos.GetParent().Close(True)
	event.Skip()
End Function

function frmCadAssuntos_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadastros_NovoDado(ConsSQL_Assunto("N", 
    frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadAssuntos_OnBtnPesquisar( event )
  frmCadastros_PesquisarDados(ConsSQL_Assunto("S", 
    frmCadastros_edtCodigo.GetValue(),""), STR_ASSNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadAssuntos_OnBtnAnterior( event )
  frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)	
  event.Skip()
end function

function frmCadAssuntos_OnBtnProximo( event )
  frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadAssuntos_OnBtnSalvar( event )
  frmCadastros_SalvarDados(frmCadAssuntos_ValidaDados(True),
    ConsSQL_Assunto("S", frmCadastros_edtCodigo.GetValue(),""),
    ConsSQL_Assunto("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value()),
    ConsSQL_Assunto("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue()), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadAssuntos_OnBtnExcluir( event )
  frmCadastros_ExcluirDados(frmCadAssuntos_ValidaDados(False),
    ConsSQL_Assunto("D", frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadAssuntos_OnBtnFechar( event )
  frmCadAssuntos.Close(True)
  event.Skip()
end function

function frmCadAssuntos_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  event.Skip()
end function
