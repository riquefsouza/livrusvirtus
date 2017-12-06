ID_FRMCADASTROS_BTNANTERIOR = 400
ID_FRMCADASTROS_BTNEXCLUIR = 401
ID_FRMCADASTROS_BTNFECHAR = 402
ID_FRMCADASTROS_BTNLIMPAR = 403
ID_FRMCADASTROS_BTNNOVO = 404
ID_FRMCADASTROS_BTNPESQUISAR = 405
ID_FRMCADASTROS_BTNPROXIMO = 406
ID_FRMCADASTROS_BTNSALVAR = 407
ID_FRMCADASTROS_EDTCODIGO = 408
ID_FRMCADASTROS_EDTDESCRICAO = 409
ID_FRMCADASTROS_LABCODIGO = 410
ID_FRMCADASTROS_LABDESCRICAO = 411

local frmCadastros_Registros
local frmCadastros_Campos
local frmCadastros_nLinhaRegistro

frmCadastros_labCodigo = nil
frmCadastros_edtCodigo = nil
frmCadastros_labDescricao = nil
frmCadastros_edtDescricao = nil
frmCadastros_btnNovo = nil
frmCadastros_btnPesquisar = nil
frmCadastros_btnAnterior = nil
frmCadastros_btnProximo = nil
frmCadastros_btnFechar = nil
frmCadastros_btnLimpar = nil
frmCadastros_btnExcluir = nil
frmCadastros_btnSalvar = nil
local frmCadastros_Arquiva

function frmCadastros_Criar(parent, nId, nFiltroCodigo, bIniciaBotoes)
  local fCadastros = wx.wxPanel(parent, nId, wx.wxPoint(0, 0), wx.wxSize(330, 140)) 

  frmCadastros_labCodigo = wx.wxStaticText(fCadastros, ID_FRMCADASTROS_LABCODIGO,
    "Código:", wx.wxPoint(8, 8), wx.wxSize(36, 13), 0)          
  frmCadastros_edtCodigo = wx.wxTextCtrl(fCadastros, ID_FRMCADASTROS_EDTCODIGO,
    "", wx.wxPoint(8, 24), wx.wxSize(121, 21), 0)  
  frmCadastros_btnNovo = wx.wxButton(fCadastros, ID_FRMCADASTROS_BTNNOVO,
  	"&Novo", wx.wxPoint(144, 24), wx.wxSize(75, 25), 0)
  frmCadastros_labDescricao = wx.wxStaticText(fCadastros, ID_FRMCADASTROS_LABDESCRICAO,
    "Descrição:", wx.wxPoint(8, 48), wx.wxSize(51, 13), 0)  
  frmCadastros_edtDescricao = wx.wxTextCtrl(fCadastros, ID_FRMCADASTROS_EDTDESCRICAO,
    "", wx.wxPoint(8, 64), wx.wxSize(217, 21), 0)  

  if bIniciaBotoes then
    frmCadastros_IniciaBotoes(fCadastros)
    frmCadastros_FazLayout(fCadastros)
  end
  --frmCadastros_edtCodigo.MaxLength = 10
  --frmCadastros_edtDescricao.MaxLength = 30
  --frmCadastros_Registros = new ArrayList()
  frmCadastros_nLinhaRegistro = 0

  return fCadastros
end

-- Necessário por causa da tabulação dos campos
function frmCadastros_IniciaBotoes(parent)
  frmCadastros_btnPesquisar = wx.wxButton(parent, ID_FRMCADASTROS_BTNPESQUISAR,
    "&Pesquisar", wx.wxPoint(248, 8), wx.wxSize(75, 25), 0)  
  frmCadastros_btnAnterior = wx.wxButton(parent, ID_FRMCADASTROS_BTNANTERIOR,
    "&Anterior", wx.wxPoint(248, 40), wx.wxSize(75, 25), 0)  
  frmCadastros_btnProximo = wx.wxButton(parent, ID_FRMCADASTROS_BTNPROXIMO,
    "Próxi&mo", wx.wxPoint(248, 72), wx.wxSize(75, 25), 0)  
  frmCadastros_btnSalvar = wx.wxButton(parent, ID_FRMCADASTROS_BTNSALVAR,
    "&Salvar", wx.wxPoint(8, 104), wx.wxSize(75, 25), 0)  
  frmCadastros_btnExcluir = wx.wxButton(parent, ID_FRMCADASTROS_BTNEXCLUIR,
    "&Excluir", wx.wxPoint(88, 104), wx.wxSize(75, 25), 0)  
  frmCadastros_btnLimpar = wx.wxButton(parent, ID_FRMCADASTROS_BTNLIMPAR,
    "&Limpar", wx.wxPoint(168, 104), wx.wxSize(75, 25), 0) 
  frmCadastros_btnFechar = wx.wxButton(parent, ID_FRMCADASTROS_BTNFECHAR,
    "&Fechar", wx.wxPoint(248, 104), wx.wxSize(75, 25), 0)  

  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao, frmCadastros_btnNovo, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
end

function frmCadastros_FazLayout(parent)
  sizer_1 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_2 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_3 = wx.wxBoxSizer(wx.wxHORIZONTAL)
  sizer_4 = wx.wxBoxSizer(wx.wxVERTICAL)
  sizer_5 = wx.wxBoxSizer(wx.wxVERTICAL)
  grid_sizer_2 = wx.wxGridSizer(2, 1, 0, 0)
  grid_sizer_1 = wx.wxGridSizer(2, 2, 0, 1)
  grid_sizer_1:AddWindow(frmCadastros_labCodigo, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_1:Add(20, 10, 0, 0, 0)
  grid_sizer_1:AddWindow(frmCadastros_edtCodigo, 0, 0, 0)
  grid_sizer_1:AddWindow(frmCadastros_btnNovo, 0, wx.wxLEFT, 6)
  sizer_5:AddSizer(grid_sizer_1, 0, 0, 0)
  grid_sizer_2:AddWindow(frmCadastros_labDescricao, 0, wx.wxALIGN_BOTTOM, 0)
  grid_sizer_2:AddWindow(frmCadastros_edtDescricao, 0, 0, 2)
  sizer_5:AddSizer(grid_sizer_2, 0, 0, 0)
  sizer_3:AddSizer(sizer_5, 1, 0, 0)
  sizer_4:AddWindow(frmCadastros_btnPesquisar, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnAnterior, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_4:AddWindow(frmCadastros_btnProximo, 0, wx.wxALL + wx.wxALIGN_RIGHT, 2)
  sizer_3:AddSizer(sizer_4, 0, wx.wxALIGN_RIGHT, 0)
  sizer_1:AddSizer(sizer_3, 1, wx.wxALL + wx.wxEXPAND, 4)
  sizer_2:AddWindow(frmCadastros_btnSalvar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnExcluir, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnLimpar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_2:AddWindow(frmCadastros_btnFechar, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 2)
  sizer_1:AddSizer(sizer_2, 0, wx.wxALL + wx.wxALIGN_RIGHT + wx.wxALIGN_BOTTOM, 4)
  parent:SetAutoLayout(wx.TRUE)
  parent:SetSizer(sizer_1)
  sizer_1:Fit(parent)
  sizer_1:SetSizeHints(parent)
end

function frmCadastros_InformaLimpaDados( bInformar, edtCodigo, edtDescricao )
	if bInformar then
	  edtCodigo:SetValue("0")
	  edtDescricao:SetValue("1")
	else
	  edtCodigo:Clear()
	  edtDescricao:Clear()
	  edtCodigo:Enable(true)
	  edtCodigo:SetFocus()
	end
end

function frmCadastros_HabilitaDados(bHabilita, edtDescricao)
	edtDescricao:Enable(bHabilita)
end

function frmCadastros_btnNovoClick(edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
	btnSalvar:Enable(true)
	btnExcluir:Enable(false)
	btnPesquisar:Enable(false)
	btnAnterior:Enable(false)
  btnProximo:Enable(false)
	btnNovo:Enable(false)

  frmCadastros_nLinhaRegistro = 0
	frmCadastros_InformaLimpaDados(false, edtCodigo, edtDescricao)
	frmCadastros_HabilitaDados(true, edtDescricao)
end

function frmCadastros_NovoDado(sTextoSql, edtCodigo, edtDescricao)
  --if Rotinas.ConsultaDadosLista(Registros, sTextoSql) then
    frmCadastros_edtCodigo:SetValue("0")
    frmCadastros_edtCodigo:Enable(false)
    frmCadastros_edtDescricao:SetFocus()
  --end
end

function frmCadastros_btnLimparClick(edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
	btnSalvar:Enable(false)
	btnExcluir:Enable(false)
	btnPesquisar:Enable(true)
	btnAnterior:Enable(false)
	btnProximo:Enable(false)
	btnNovo:Enable(true)

  frmCadastros_nLinhaRegistro = 0
	frmCadastros_InformaLimpaDados(false, edtCodigo, edtDescricao)
	frmCadastros_HabilitaDados(false, edtDescricao)
end

function frmCadastros_ExcluirDados(bValidaDados, sTextoSql, 
  edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
  if bValidaDados then
    if wx.wxMessageBox(STR_CERTEXCL, "Confirme",
     wx.wxICON_QUESTION + wx.wxYES_NO) == wx.wxYES then
      --if Rotinas.AtualizaDados(Arquiva, sTextoSql) then
         frmCadastros_btnLimparClick(edtCodigo, edtDescricao, btnNovo, 
          btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
         return true
      --end
    end
  end
  return false
end

function frmCadastros_PesquisarDados(sTextoSql, sMensagemErro, 
  edtCodigo, edtDescricao, btnPesquisar, btnAnterior, 
  btnProximo, btnSalvar, btnExcluir)
	if string.len(edtCodigo:GetValue()) == 0 then
	  btnAnterior:Enable(true)
	  btnProximo:Enable(true)
	end

	--if Rotinas.ConsultaDadosLista(Registros,sTextoSql) then
   	 frmCadastros_InformaLimpaDados(true, edtCodigo, edtDescricao)
  	 frmCadastros_HabilitaDados(true, edtDescricao)

		 btnSalvar:Enable(true)
		 btnExcluir:Enable(true)
		 btnPesquisar:Enable(false)
     --return true
	--else
	  --wx.wxMessageBox(sMensagemErro, "Erro", wx.wxOK + wx.wxICON_ERROR)
  --end
  return false
end

function frmCadastros_registroAnterior(edtCodigo, edtDescricao)
	if frmCadastros_nLinhaRegistro > 0 then
		frmCadastros_nLinhaRegistro=frmCadastros_nLinhaRegistro - 1
		frmCadastros_InformaLimpaDados(true, edtCodigo, edtDescricao)
    return true
  else
    return false
  end
end

function frmCadastros_registroProximo(edtCodigo, edtDescricao)
	--if nLinhaRegistro < (Registros.Count-1) then
		frmCadastros_nLinhaRegistro=frmCadastros_nLinhaRegistro + 1
		frmCadastros_InformaLimpaDados(true, edtCodigo, edtDescricao)
    return true
  --else
  --  return false
  --end
end

function frmCadastros_SalvarDados(bValidaDados, sTextoSql, sTextoUpdate, 
  sTextoInsert, bLimparDados, edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
  Consulta = ""
  sArquiva = "" 

	if bValidaDados then 
	   --if RotinasGlobais.Rotinas.ConsultaDados(Consulta,sTextoSql) then
     --  sArquiva = sTextoUpdate
     --else
  	 --  sArquiva = sTextoInsert	  	     
     --end
     --if RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sArquiva) then
  	   if bLimparDados then
         frmCadastros_btnLimparClick(edtCodigo, edtDescricao, btnNovo, 
          btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
       end
       return true
     --end
	end
  return false
end
