option explicit

Const ID_FRMCADASTROS_BTNANTERIOR = 400
Const ID_FRMCADASTROS_BTNEXCLUIR = 401
Const ID_FRMCADASTROS_BTNFECHAR = 402
Const ID_FRMCADASTROS_BTNLIMPAR = 403
Const ID_FRMCADASTROS_BTNNOVO = 404
Const ID_FRMCADASTROS_BTNPESQUISAR = 405
Const ID_FRMCADASTROS_BTNPROXIMO = 406
Const ID_FRMCADASTROS_BTNSALVAR = 407
Const ID_FRMCADASTROS_EDTCODIGO = 408
Const ID_FRMCADASTROS_EDTDESCRICAO = 409
Const ID_FRMCADASTROS_LABCODIGO = 410
Const ID_FRMCADASTROS_LABDESCRICAO = 411

dim common frmCadastros_Registros
dim common frmCadastros_Campos
dim common frmCadastros_nLinhaRegistro

dim common frmCadastros_labCodigo
dim common frmCadastros_edtCodigo
dim common frmCadastros_labDescricao
dim common frmCadastros_edtDescricao
dim common frmCadastros_btnNovo
dim common frmCadastros_btnPesquisar
dim common frmCadastros_btnAnterior
dim common frmCadastros_btnProximo
dim common frmCadastros_btnFechar
dim common frmCadastros_btnLimpar
dim common frmCadastros_btnExcluir
dim common frmCadastros_btnSalvar
dim common frmCadastros_Arquiva

function frmCadastros_Criar(parent, nFiltroCodigo, bIniciaBotoes)
  dim fCadastros = new wxPanel(parent, -1, wxPoint(0, 0), wxSize(330, 140)) 

  frmCadastros_labCodigo = new wxStaticText(fCadastros, ID_FRMCADASTROS_LABCODIGO,
    "Código:", wxPoint(8, 8), wxSize(36, 13), 0)          
  frmCadastros_edtCodigo = new wxTextCtrl(fCadastros, ID_FRMCADASTROS_EDTCODIGO,
    "", wxPoint(8, 24), wxSize(121, 21), 0)  
  frmCadastros_btnNovo = new wxButton(fCadastros, ID_FRMCADASTROS_BTNNOVO,
  	"&Novo", wxPoint(144, 24), wxSize(75, 25), 0)
  frmCadastros_labDescricao = new wxStaticText(fCadastros, ID_FRMCADASTROS_LABDESCRICAO,
    "Descrição:", wxPoint(8, 48), wxSize(51, 13), 0)  
  frmCadastros_edtDescricao = new wxTextCtrl(fCadastros, ID_FRMCADASTROS_EDTDESCRICAO,
    "", wxPoint(8, 64), wxSize(217, 21), 0)  

  if bIniciaBotoes then
    frmCadastros_IniciaBotoes(fCadastros)
    frmCadastros_FazLayout(fCadastros)
  end if
  'frmCadastros_edtCodigo.MaxLength = 10
  'frmCadastros_edtDescricao.MaxLength = 30
  'frmCadastros_Registros = new ArrayList()
  frmCadastros_nLinhaRegistro = 0

  return fCadastros
end function

' Necessário por causa da tabulação dos campos
sub frmCadastros_IniciaBotoes(parent)
  frmCadastros_btnPesquisar = new wxButton(parent, ID_FRMCADASTROS_BTNPESQUISAR,
    "&Pesquisar", wxPoint(248, 8), wxSize(75, 25), 0)  
  frmCadastros_btnAnterior = new wxButton(parent, ID_FRMCADASTROS_BTNANTERIOR,
    "&Anterior", wxPoint(248, 40), wxSize(75, 25), 0)  
  frmCadastros_btnProximo = new wxButton(parent, ID_FRMCADASTROS_BTNPROXIMO,
    "Próxi&mo", wxPoint(248, 72), wxSize(75, 25), 0)  
  frmCadastros_btnSalvar = new wxButton(parent, ID_FRMCADASTROS_BTNSALVAR,
    "&Salvar", wxPoint(8, 104), wxSize(75, 25), 0)  
  frmCadastros_btnExcluir = new wxButton(parent, ID_FRMCADASTROS_BTNEXCLUIR,
    "&Excluir", wxPoint(88, 104), wxSize(75, 25), 0)  
  frmCadastros_btnLimpar = new wxButton(parent, ID_FRMCADASTROS_BTNLIMPAR,
    "&Limpar", wxPoint(168, 104), wxSize(75, 25), 0) 
  frmCadastros_btnFechar = new wxButton(parent, ID_FRMCADASTROS_BTNFECHAR,
    "&Fechar", wxPoint(248, 104), wxSize(75, 25), 0)  

  frmCadastros_btnLimparClick(frmCadastros_edtCodigo, 
    frmCadastros_edtDescricao, frmCadastros_btnNovo, 
    frmCadastros_btnPesquisar, frmCadastros_btnAnterior, 
    frmCadastros_btnProximo, frmCadastros_btnSalvar, 
    frmCadastros_btnExcluir)
end sub

sub frmCadastros_FazLayout(parent)
  dim sizer_1 = new wxBoxSizer(wxVERTICAL)
  dim sizer_2 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_3 = new wxBoxSizer(wxHORIZONTAL)
  dim sizer_4 = new wxBoxSizer(wxVERTICAL)
  dim sizer_5 = new wxBoxSizer(wxVERTICAL)
  dim grid_sizer_2 = new wxGridSizer(2, 1, 0, 0)
  dim grid_sizer_1 = new wxGridSizer(2, 2, 0, 1)
  grid_sizer_1.Add(frmCadastros_labCodigo, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_1.Add(20, 10, 0, 0, 0)
  grid_sizer_1.Add(frmCadastros_edtCodigo, 0, 0, 0)
  grid_sizer_1.Add(frmCadastros_btnNovo, 0, wxLEFT, 6)
  sizer_5.Add(grid_sizer_1, 0, 0, 0)
  grid_sizer_2.Add(frmCadastros_labDescricao, 0, wxALIGN_BOTTOM, 0)
  grid_sizer_2.Add(frmCadastros_edtDescricao, 0, 0, 2)
  sizer_5.Add(grid_sizer_2, 0, 0, 0)
  sizer_3.Add(sizer_5, 1, 0, 0)
  sizer_4.Add(frmCadastros_btnPesquisar, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_4.Add(frmCadastros_btnAnterior, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_4.Add(frmCadastros_btnProximo, 0, wxALL + wxALIGN_RIGHT, 2)
  sizer_3.Add(sizer_4, 0, wxALIGN_RIGHT, 0)
  sizer_1.Add(sizer_3, 1, wxALL + wxEXPAND, 4)
  sizer_2.Add(frmCadastros_btnSalvar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnExcluir, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnLimpar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_2.Add(frmCadastros_btnFechar, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 2)
  sizer_1.Add(sizer_2, 0, wxALL + wxALIGN_RIGHT + wxALIGN_BOTTOM, 4)
  parent.SetAutoLayout(True)
  parent.SetSizer(sizer_1)
  sizer_1.Fit(parent)
  sizer_1.SetSizeHints(parent)
end sub

sub frmCadastros_InformaLimpaDados( bInformar, edtCodigo, edtDescricao )
	if bInformar then
	  edtCodigo.SetValue("0")
	  edtDescricao.SetValue("1")
	else
	  edtCodigo.Clear()
	  edtDescricao.Clear()
	  edtCodigo.Enable(True)
	  edtCodigo.SetFocus()
	end if
end sub

sub frmCadastros_HabilitaDados(bHabilita, edtDescricao)
	edtDescricao.Enable(bHabilita)
end sub

sub frmCadastros_btnNovoClick(edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
	btnSalvar.Enable(True)
	btnExcluir.Enable(False)
	btnPesquisar.Enable(False)
	btnAnterior.Enable(False)
  btnProximo.Enable(False)
	btnNovo.Enable(False)

  frmCadastros_nLinhaRegistro = 0
	frmCadastros_InformaLimpaDados(False, edtCodigo, edtDescricao)
	frmCadastros_HabilitaDados(True, edtDescricao)
end sub

sub frmCadastros_NovoDado(sTextoSql, edtCodigo, edtDescricao)
  'if Rotinas.ConsultaDadosLista(Registros, sTextoSql) then
    frmCadastros_edtCodigo.SetValue("0")
    frmCadastros_edtCodigo.Enable(False)
    frmCadastros_edtDescricao.SetFocus()
  'end if
end sub

sub frmCadastros_btnLimparClick(edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
	btnSalvar.Enable(False)
	btnExcluir.Enable(False)
	btnPesquisar.Enable(True)
	btnAnterior.Enable(False)
	btnProximo.Enable(False)
	btnNovo.Enable(True)

  frmCadastros_nLinhaRegistro = 0
	frmCadastros_InformaLimpaDados(False, edtCodigo, edtDescricao)
	frmCadastros_HabilitaDados(False, edtDescricao)
end sub

function frmCadastros_ExcluirDados(bValidaDados, sTextoSql, 
  edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
  if bValidaDados then
    if wxMessageBox(STR_CERTEXCL, "Confirme",
     wxICON_QUESTION + wxYES_NO) = wxYES then
      'if Rotinas.AtualizaDados(Arquiva, sTextoSql) then
         frmCadastros_btnLimparClick(edtCodigo, edtDescricao, btnNovo, 
          btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
         return True
      'end if
    end if
  end if
  return False
end function

function frmCadastros_PesquisarDados(sTextoSql, sMensagemErro, 
  edtCodigo, edtDescricao, btnPesquisar, btnAnterior, 
  btnProximo, btnSalvar, btnExcluir)
	if Length(edtCodigo.GetValue()) = 0 then
	  btnAnterior.Enable(True)
	  btnProximo.Enable(True)
	end if

	'if Rotinas.ConsultaDadosLista(Registros,sTextoSql) then
   	 frmCadastros_InformaLimpaDados(True, edtCodigo, edtDescricao)
  	 frmCadastros_HabilitaDados(True, edtDescricao)

		 btnSalvar.Enable(True)
		 btnExcluir.Enable(True)
		 btnPesquisar.Enable(False)
     return True
	'else
	  'wxMessageBox(sMensagemErro, "Erro", wxOK + wxICON_ERROR)
  'end if
  return False
end function

function frmCadastros_registroAnterior(edtCodigo, edtDescricao)
	if frmCadastros_nLinhaRegistro > 0 then
		frmCadastros_nLinhaRegistro=frmCadastros_nLinhaRegistro - 1
		frmCadastros_InformaLimpaDados(True, edtCodigo, edtDescricao)
    return True
  else
    return False
  end if
end function

function frmCadastros_registroProximo(edtCodigo, edtDescricao)
	'if nLinhaRegistro < (Registros.Count-1) then
		frmCadastros_nLinhaRegistro=frmCadastros_nLinhaRegistro + 1
		frmCadastros_InformaLimpaDados(True, edtCodigo, edtDescricao)
    return True
  'else
  '  return False
  'end if
end function

function frmCadastros_SalvarDados(bValidaDados, sTextoSql, sTextoUpdate, 
  sTextoInsert, bLimparDados, edtCodigo, edtDescricao, btnNovo, 
  btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
  dim Consulta = ""
  dim sArquiva = "" 

	if bValidaDados then 
	   'if RotinasGlobais.Rotinas.ConsultaDados(Consulta,sTextoSql) then
     '  sArquiva = sTextoUpdate
     'else
  	 '  sArquiva = sTextoInsert	  	     
     'end if
     'if RotinasGlobais.Rotinas.AtualizaDados(Arquiva, sArquiva) then
  	   if bLimparDados then
         frmCadastros_btnLimparClick(edtCodigo, edtDescricao, btnNovo, 
          btnPesquisar, btnAnterior, btnProximo, btnSalvar, btnExcluir)
       end if
       return True
     'end if
	end if
  return False
end function
