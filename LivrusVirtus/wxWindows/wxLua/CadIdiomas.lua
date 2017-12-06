ID_FRMCADIDIOMAS = 412

local frmCadIdiomas

function frmCadIdiomas_Criar(parent)
  local fCadIdiomas = frmCadastros_Criar(parent, ID_FRMCADIDIOMAS, 0, true)

  frmCadastros_labDescricao:SetLabel("Idioma: ")

  fCadIdiomas:ConnectEvent(ID_FRMCADIDIOMAS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadIdiomas:GetParent():Close(true)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadastros_NovoDado(ConsSQL_Idioma("N", 
        frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_PesquisarDados(ConsSQL_Idioma("S", 
        frmCadastros_edtCodigo:GetValue(),""), STR_IDINENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)	
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_SalvarDados(frmCadIdiomas_ValidaDados(true),
        ConsSQL_Idioma("S", frmCadastros_edtCodigo:GetValue(),""),
        ConsSQL_Idioma("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()),
        ConsSQL_Idioma("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_ExcluirDados(frmCadIdiomas_ValidaDados(false),
        ConsSQL_Idioma("D", frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadIdiomas:Close(true)
      event:Skip()
    end )

  fCadIdiomas:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  return fCadIdiomas
end

function frmCadIdiomas_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_IDININF) then
    	return false
    end
  end
	return true
end
