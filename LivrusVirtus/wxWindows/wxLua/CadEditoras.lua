ID_FRMCADEDITORAS = 412

local frmCadEditoras

function frmCadEditoras_Criar(parent)
  local fCadEditoras = frmCadastros_Criar(parent, ID_FRMCADEDITORAS, 0, true)

  frmCadastros_labDescricao:SetLabel("Editora: ")

  fCadEditoras:ConnectEvent(ID_FRMCADEDITORAS,wx.wxEVT_CLOSE_WINDOW,
    function (event)
      fCadEditoras:GetParent():Close(true)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNNOVO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnNovoClick(frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo, frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, frmCadastros_btnExcluir)
      frmCadastros_NovoDado(ConsSQL_Editora("N", 
        frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNPESQUISAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_PesquisarDados(ConsSQL_Editora("S", 
        frmCadastros_edtCodigo:GetValue(),""), STR_EDTNENC,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNANTERIOR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroAnterior(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)	
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNPROXIMO,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_registroProximo(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNSALVAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_SalvarDados(frmCadEditoras_ValidaDados(true),
        ConsSQL_Editora("S", frmCadastros_edtCodigo:GetValue(),""),
        ConsSQL_Editora("U", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()),
        ConsSQL_Editora("I", frmCadastros_edtCodigo:GetValue(),
          frmCadastros_edtDescricao:GetValue()), true,
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNEXCLUIR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_ExcluirDados(frmCadEditoras_ValidaDados(false),
        ConsSQL_Editora("D", frmCadastros_edtCodigo:GetValue(),""),
        frmCadastros_edtCodigo, frmCadastros_edtDescricao, 
        frmCadastros_btnNovo,
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNFECHAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      fCadEditoras:Close(true)
      event:Skip()
    end )

  fCadEditoras:ConnectEvent(ID_FRMCADASTROS_BTNLIMPAR,
    wx.wxEVT_COMMAND_BUTTON_CLICKED,
    function (event)
      frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
        frmCadastros_edtDescricao, frmCadastros_btnNovo, 
        frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
        frmCadastros_btnProximo, frmCadastros_btnSalvar, 
        frmCadastros_btnExcluir)
      event:Skip()
    end )

  return fCadEditoras
end

function frmCadEditoras_ValidaDados(bTodosDados)
  if Rotinas_ValidaCampo(frmCadastros_edtCodigo:GetValue(),
    STR_CODNINF) then
    return false
  end
  if bTodosDados then
    if Rotinas_ValidaCampo(frmCadastros_edtDescricao:GetValue(),
      STR_EDTNINF) then
    	return false
    end
  end
	return true
end
