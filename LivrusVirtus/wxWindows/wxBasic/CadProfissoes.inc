option explicit

dim common frmCadProfissoes

function frmCadProfissoes_Criar(parent)
  dim fCadProfissoes = frmCadastros_Criar(parent, 0, True)

  frmCadastros_labDescricao.SetLabel("Profissão: ")

  Connect( fCadProfissoes, wxEVT_CLOSE_WINDOW, "frmCadProfissoes_OnClose" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNNOVO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnNovo" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNPESQUISAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnPesquisar" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNANTERIOR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnAnterior" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNPROXIMO, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnProximo" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNSALVAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnSalvar" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNEXCLUIR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnExcluir" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNFECHAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnFechar" )
  Connect( fCadProfissoes, ID_FRMCADASTROS_BTNLIMPAR, 
    wxEVT_COMMAND_BUTTON_CLICKED, "frmCadProfissoes_OnBtnLimpar" )

  return fCadProfissoes
end function

function frmCadProfissoes_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo.GetValue(),
    STR_CODNINF) then
    return False
  end if
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao.GetValue(),
      STR_PROFNINF) then
    	return False
    end if
  end if
	return True
end function

Function frmCadProfissoes_OnClose( event )
  frmCadProfissoes.GetParent().Close(True)
	event.Skip()
End Function

function frmCadProfissoes_OnBtnNovo( event )
  frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  frmCadastros_NovoDado(ConsSQL_Profissao("N", 
    frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadProfissoes_OnBtnPesquisar( event )
  frmCadastros_PesquisarDados(ConsSQL_Profissao("S", 
    frmCadastros_edtCodigo.GetValue(),""), STR_PROFNENC,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadProfissoes_OnBtnAnterior( event )
  frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)	
  event.Skip()
end function

function frmCadProfissoes_OnBtnProximo( event )
  frmCadastros_registroProximo(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao)
  event.Skip()
end function

function frmCadProfissoes_OnBtnSalvar( event )
  frmCadastros_SalvarDados(frmCadProfissoes_ValidaDados(True),
    ConsSQL_Profissao("S", frmCadastros_edtCodigo.GetValue(),""),
    ConsSQL_Profissao("U", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.Value()),
    ConsSQL_Profissao("I", frmCadastros_edtCodigo.GetValue(),
      frmCadastros_edtDescricao.GetValue()), True,
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadProfissoes_OnBtnExcluir( event )
  frmCadastros_ExcluirDados(frmCadProfissoes_ValidaDados(False),
    ConsSQL_Profissao("D", frmCadastros_edtCodigo.GetValue(),""),
    frmCadastros_edtCodigo, frmCadastros_edtDescricao, frmCadastros_btnNovo,
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
  event.Skip()
end function

function frmCadProfissoes_OnBtnFechar( event )
  frmCadProfissoes.Close(True)
  event.Skip()
end function

function frmCadProfissoes_OnBtnLimpar( event )
  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
    frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
  event.Skip()
end function
