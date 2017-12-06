option explicit

dim common frmCadEditoras

function frmCadEditoras_Criar(parent)
  dim fCadEditoras = frmCadastros_Criar(parent, 0, True)

  frmCadastros_labDescricao.SetLabel("Editora: ")

  Connect( fCadEditoras, wxEVT_CLOSE_WINDOW, "frmCadEditoras_OnClose" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnNovo" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnPesquisar" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnAnterior" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnProximo" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnSalvar" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnExcluir" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnFechar" )
  Connect( fCadEditoras, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadEditoras_OnBtnLimpar" )

  return fCadEditoras
end function

function frmCadEditoras_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_EDTNINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadEditoras_OnClose( event )
  frmCadEditoras.GetParent().Close(True)
	event.Skip()
End Function

function frmCadEditoras_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadastros_NovoDado(ConsSQL_Editora("N", 
    frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadEditoras_OnBtnPesquisar( event )
  frmCadastros_PesquisarDados(ConsSQL_Editora("S", 
    frmCadastros_edtCodigo.GetValue(),""), STR_EDTNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadEditoras_OnBtnAnterior( event )
  frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)	
  event.Skip()
end function

function frmCadEditoras_OnBtnProximo( event )
  frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadEditoras_OnBtnSalvar( event )
  frmCadastros_SalvarDados(frmCadEditoras_ValidaDados(True),
    ConsSQL_Editora("S", frmCadastros_edtCodigo.GetValue(),""),
    ConsSQL_Editora("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value()),
    ConsSQL_Editora("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue()), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadEditoras_OnBtnExcluir( event )
  frmCadastros_ExcluirDados(frmCadEditoras_ValidaDados(False),
    ConsSQL_Editora("D", frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadEditoras_OnBtnFechar( event )
  frmCadEditoras.Close(True)
  event.Skip()
end function

function frmCadEditoras_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  event.Skip()
end function
