ID_FRMCADASSUNTOS = 412

local frmCadAssuntos

function frmCadAssuntos_Criar(parent)
  local fCadAssuntos = frmCadastros_Criar(parent, ID_FRMCADASSUNTOS, 0, true)

  frmCadastros_labDescricao:SetLabel("Assunto: ")

  fCadAssuntos:ConnectEvent(ID_FRMCADASSUNTOS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadAssuntos:GetParent():Close(true)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadastros_NovoDado(ConsSQL_Assunto("N", 
        frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_PesquisarDados(ConsSQL_Assunto("S", 
        frmCadastros_edtCodigo:GetValue(),""), STR_ASSNENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)	
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_SalvarDados(frmCadAssuntos_ValidaDados(true),
        ConsSQL_Assunto("S", frmCadastros_edtCodigo:GetValue(),""),
        ConsSQL_Assunto("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()),
        ConsSQL_Assunto("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_ExcluirDados(frmCadAssuntos_ValidaDados(false),
        ConsSQL_Assunto("D", frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadAssuntos:Close(true)
      event:Skip()
    end )

  fCadAssuntos:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  return fCadAssuntos
end

function frmCadAssuntos_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_ASSNINF) then
    	return false
    end
  end
	return true
end
