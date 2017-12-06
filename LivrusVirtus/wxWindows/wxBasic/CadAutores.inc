option explicit

dim common frmCadAutores

function frmCadAutores_Criar(parent)
  dim fCadAutores = frmCadastros_Criar(parent, 0, True)

  frmCadastros_labDescricao.SetLabel("Autor: ")

  Connect( fCadAutores, wxEVT_CLOSE_WINDOW, "frmCadAutores_OnClose" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnNovo" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnPesquisar" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnAnterior" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnProximo" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnSalvar" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnExcluir" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnFechar" )
  Connect( fCadAutores, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadAutores_OnBtnLimpar" )

  return fCadAutores
end function

function frmCadAutores_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_AUTNINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadAutores_OnClose( event )
  frmCadAutores.GetParent().Close(True)
	event.Skip()
End Function

function frmCadAutores_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadastros_NovoDado(ConsSQL_Autor("N", 
    frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadAutores_OnBtnPesquisar( event )
  frmCadastros_PesquisarDados(ConsSQL_Autor("S", 
    frmCadastros_edtCodigo.GetValue(),""), STR_AUTNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadAutores_OnBtnAnterior( event )
  frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)	
  event.Skip()
end function

function frmCadAutores_OnBtnProximo( event )
  frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadAutores_OnBtnSalvar( event )
  frmCadastros_SalvarDados(frmCadAutores_ValidaDados(True),
    ConsSQL_Autor("S", frmCadastros_edtCodigo.GetValue(),""),
    ConsSQL_Autor("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value()),
    ConsSQL_Autor("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue()), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadAutores_OnBtnExcluir( event )
  frmCadastros_ExcluirDados(frmCadAutores_ValidaDados(False),
    ConsSQL_Autor("D", frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadAutores_OnBtnFechar( event )
  frmCadAutores.Close(True)
  event.Skip()
end function

function frmCadAutores_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  event.Skip()
end function
