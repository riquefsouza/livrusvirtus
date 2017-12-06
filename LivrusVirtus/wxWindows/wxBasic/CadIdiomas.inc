option explicit

dim common frmCadIdiomas

function frmCadIdiomas_Criar(parent)
  dim fCadIdiomas = frmCadastros_Criar(parent, 0, True)

  frmCadastros_labDescricao.SetLabel("Idioma: ")

  Connect( fCadIdiomas, wxEVT_CLOSE_WINDOW, "frmCadIdiomas_OnClose" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnNovo" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnPesquisar" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnAnterior" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnProximo" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnSalvar" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnExcluir" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnFechar" )
  Connect( fCadIdiomas, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadIdiomas_OnBtnLimpar" )

  return fCadIdiomas
end function

function frmCadIdiomas_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_IDININF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadIdiomas_OnClose( event )
  frmCadIdiomas.GetParent().Close(True)
	event.Skip()
End Function

function frmCadIdiomas_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadastros_NovoDado(ConsSQL_Idioma("N", 
    frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadIdiomas_OnBtnPesquisar( event )
  frmCadastros_PesquisarDados(ConsSQL_Idioma("S", 
    frmCadastros_edtCodigo.GetValue(),""), STR_IDINENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadIdiomas_OnBtnAnterior( event )
  frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)	
  event.Skip()
end function

function frmCadIdiomas_OnBtnProximo( event )
  frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadIdiomas_OnBtnSalvar( event )
  frmCadastros_SalvarDados(frmCadIdiomas_ValidaDados(True),
    ConsSQL_Idioma("S", frmCadastros_edtCodigo.GetValue(),""),
    ConsSQL_Idioma("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value()),
    ConsSQL_Idioma("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue()), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadIdiomas_OnBtnExcluir( event )
  frmCadastros_ExcluirDados(frmCadIdiomas_ValidaDados(False),
    ConsSQL_Idioma("D", frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadIdiomas_OnBtnFechar( event )
  frmCadIdiomas.Close(True)
  event.Skip()
end function

function frmCadIdiomas_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  event.Skip()
end function
