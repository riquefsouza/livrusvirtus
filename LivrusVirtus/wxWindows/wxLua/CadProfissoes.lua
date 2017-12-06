ID_FRMCADPROFISSOES = 412

local frmCadProfissoes

function frmCadProfissoes_Criar(parent)
  local fCadProfissoes = frmCadastros_Criar(parent, ID_FRMCADPROFISSOES, 0, true)

  frmCadastros_labDescricao:SetLabel("Profissão: ")

  fCadProfissoes:ConnectEvent(ID_FRMCADPROFISSOES,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadProfissoes:GetParent():Close(true)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadastros_NovoDado(ConsSQL_Profissao("N", 
        frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_PesquisarDados(ConsSQL_Profissao("S", 
        frmCadastros_edtCodigo:GetValue(),""), STR_PROFNENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)	
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_SalvarDados(frmCadProfissoes_ValidaDados(true),
        ConsSQL_Profissao("S", frmCadastros_edtCodigo:GetValue(),""),
        ConsSQL_Profissao("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()),
        ConsSQL_Profissao("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_ExcluirDados(frmCadProfissoes_ValidaDados(false),
        ConsSQL_Profissao("D", frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadProfissoes:Close(true)
      event:Skip()
    end )

  fCadProfissoes:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  return fCadProfissoes
end

function frmCadProfissoes_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_PROFNINF) then
    	return false
    end
  end
	return true
end
