option explicit

dim common frmCadPaises

function frmCadPaises_Criar(parent)
  dim fCadPaises = frmCadastros_Criar(parent, 0, True)

  frmCadastros_labDescricao.SetLabel("País: ")

  Connect( fCadPaises, wxEVT_CLOSE_WINDOW, "frmCadPaises_OnClose" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnNovo" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnPesquisar" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnAnterior" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnProximo" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnSalvar" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnExcluir" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnFechar" )
  Connect( fCadPaises, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadPaises_OnBtnLimpar" )

  return fCadPaises
end function

function frmCadPaises_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_PAISNINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadPaises_OnClose( event )
  frmCadPaises.GetParent().Close(True)
	event.Skip()
End Function

function frmCadPaises_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadastros_NovoDado(ConsSQL_Pais("N", 
    frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadPaises_OnBtnPesquisar( event )
  frmCadastros_PesquisarDados(ConsSQL_Pais("S", 
    frmCadastros_edtCodigo.GetValue(),""), STR_PAISNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadPaises_OnBtnAnterior( event )
  frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)	
  event.Skip()
end function

function frmCadPaises_OnBtnProximo( event )
  frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadPaises_OnBtnSalvar( event )
  frmCadastros_SalvarDados(frmCadPaises_ValidaDados(True),
    ConsSQL_Pais("S", frmCadastros_edtCodigo.GetValue(),""),
    ConsSQL_Pais("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value()),
    ConsSQL_Pais("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue()), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadPaises_OnBtnExcluir( event )
  frmCadastros_ExcluirDados(frmCadPaises_ValidaDados(False),
    ConsSQL_Pais("D", frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadPaises_OnBtnFechar( event )
  frmCadPaises.Close(True)
  event.Skip()
end function

function frmCadPaises_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  event.Skip()
end function
