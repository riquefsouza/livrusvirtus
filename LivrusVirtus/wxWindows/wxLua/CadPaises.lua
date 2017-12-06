ID_FRMCADPAISES = 412

local frmCadPaises

function frmCadPaises_Criar(parent)
  local fCadPaises = frmCadastros_Criar(parent, ID_FRMCADPAISES, 0, true)

  frmCadastros_labDescricao:SetLabel("País: ")

  fCadPaises:ConnectEvent(ID_FRMCADPAISES,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadPaises:GetParent():Close(true)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadastros_NovoDado(ConsSQL_Pais("N", 
        frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_PesquisarDados(ConsSQL_Pais("S", 
        frmCadastros_edtCodigo:GetValue(),""), STR_PAISNENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)	
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_SalvarDados(frmCadPaises_ValidaDados(true),
        ConsSQL_Pais("S", frmCadastros_edtCodigo:GetValue(),""),
        ConsSQL_Pais("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()),
        ConsSQL_Pais("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_ExcluirDados(frmCadPaises_ValidaDados(false),
        ConsSQL_Pais("D", frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadPaises:Close(true)
      event:Skip()
    end )

  fCadPaises:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  return fCadPaises
end

function frmCadPaises_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_PAISNINF) then
    	return false
    end
  end
	return true
end
