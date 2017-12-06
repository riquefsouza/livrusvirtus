Imports System
Imports System.Drawing
Imports wx

Namespace Livrus

	Public Class frmCadEnderecos
		Inherits frmCadastros
		
		public shared WithEvents fCadEnderecos as frmCadEnderecos

		private Enum idx
      ID_FRMCADENDERECOS_CMBESTADO = 700
      ID_FRMCADENDERECOS_EDTBAIRRO
      ID_FRMCADENDERECOS_EDTCEP
      ID_FRMCADENDERECOS_EDTCIDADE
      ID_FRMCADENDERECOS_LABBAIRRO
      ID_FRMCADENDERECOS_LABCEP
      ID_FRMCADENDERECOS_LABCIDADE
      ID_FRMCADENDERECOS_LABESTADO
    end Enum

		private labBairro as wx.StaticText
		private edtBairro as wx.TextCtrl
		private edtCEP as wx.TextCtrl
		private labCEP as wx.StaticText
		private edtCidade as wx.TextCtrl
		private labCidade as wx.StaticText
		private labEstado as wx.StaticText
		private cmbEstado as wx.Choice
    private vsEstados(26) as string

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, TextValidatorCtrl.FILTER_NUMERIC, false)

      ClientSize = new Size(523, 171)
      labDescricao.Label = "Logradouro:"
      labDescricao.Size = new Size(57, 13)
      edtDescricao.Size = new Size(264, 21)
    
    	labBairro = new wx.StaticText(Me, idx.ID_FRMCADENDERECOS_LABBAIRRO, _
        "Bairro:", new Point(280, 48), new Size(48, 13) )
    	edtBairro = new wx.TextCtrl(Me, idx.ID_FRMCADENDERECOS_EDTBAIRRO, _
        "", new Point(280, 64), new Size(144, 21) )
      edtBairro.Enabled = false
    	labCEP = new wx.StaticText(Me, idx.ID_FRMCADENDERECOS_LABCEP, _
        "CEP: ", new Point(8, 88), new Size(40, 13) )
    	edtCEP = new wx.TextCtrl(Me, idx.ID_FRMCADENDERECOS_EDTCEP, _
        "", new Point(8, 104), new Size(72, 21) )
      edtCEP.Enabled = false
    	labCidade = new wx.StaticText(Me, idx.ID_FRMCADENDERECOS_LABCIDADE, _
        "Cidade: ", new Point(88, 88), new Size(39, 13) )
    	edtCidade = new wx.TextCtrl(Me, idx.ID_FRMCADENDERECOS_EDTCIDADE, _
        "", new Point(88, 104), new Size(184, 21) )
      edtCidade.Enabled = false
    	labEstado = new wx.StaticText(Me, idx.ID_FRMCADENDERECOS_LABESTADO, _ 
        "Estado: ", new Point(280, 88), new Size(56, 13) )
      AdicionaCombo()
    	cmbEstado = new wx.Choice(Me, idx.ID_FRMCADENDERECOS_CMBESTADO, _
        new Point(280, 104), new Size(144, 21), vsEstados )
      cmbEstado.Enabled = false
  
      IniciaBotoes()
    
      btnPesquisar.SetSize(440, 8, 75, 25)
      btnAnterior.SetSize(440, 40, 75, 25)
      btnProximo.SetSize(440, 72, 75, 25)
      btnSalvar.SetSize(200, 136, 75, 25)
      btnExcluir.SetSize(280, 136, 75, 25)
      btnLimpar.SetSize(360, 136, 75, 25)
      btnFechar.SetSize(440, 136, 75, 25)
    
      'FazLayout()
    
      edtDescricao.MaxLength = 40
      edtBairro.MaxLength = 15
      edtCEP.MaxLength = 8
      edtCidade.MaxLength = 30

      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNNOVO, _
        new EventListener(AddressOf OnBtnNovo ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNPESQUISAR, _
        new EventListener(AddressOf OnBtnPesquisar ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNANTERIOR, _
        new EventListener(AddressOf OnBtnAnterior ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNPROXIMO, _
        new EventListener(AddressOf OnBtnProximo ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNSALVAR, _
        new EventListener(AddressOf OnBtnSalvar ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNEXCLUIR, _
        new EventListener(AddressOf OnBtnExcluir ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNLIMPAR, _
        new EventListener(AddressOf OnBtnLimpar ))
      EVT_BUTTON(idt.ID_FRMCADASTROS_BTNFECHAR, _
        new EventListener(AddressOf OnBtnFechar ))
			EVT_CLOSE( new EventListener(AddressOf OnClose ) )
    End Sub

    private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_5 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_6 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_6 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_5 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_4 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_8 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_9 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_8 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_7 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_7 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      grid_sizer_7.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_7.Add(edtCodigo, 0, 0, 0)
      sizer_7.Add(grid_sizer_7, 0, 0, 0)
      sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 5)
      sizer_5.Add(sizer_7, 1, 0, 0)
      grid_sizer_8.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_8.Add(edtDescricao, 0, 0, 0)
      sizer_8.Add(grid_sizer_8, 0, 0, 0)
      grid_sizer_9.Add(labBairro, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_9.Add(edtBairro, 0, 0, 0)
      sizer_8.Add(grid_sizer_9, 0, wx.Direction.wxLEFT, 2)
      sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0)
      grid_sizer_4.Add(labCEP, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_4.Add(edtCEP, 0, 0, 0)
      sizer_6.Add(grid_sizer_4, 0, 0, 0)
      grid_sizer_5.Add(labCidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_5.Add(edtCidade, 0, 0, 0)
      sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4)
      grid_sizer_6.Add(labEstado, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_6.Add(cmbEstado, 0, 0, 0)
      sizer_6.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 5)
      sizer_5.Add(sizer_6, 0, 0, 0)
      sizer_3.Add(sizer_5, 0, 0, 0)
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_4.Add(btnProximo, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT, 2)
      sizer_3.Add(sizer_4, 1, 0, 0)
      sizer_1.Add(sizer_3, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 4)
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2)
      sizer_1.Add(sizer_2, 0, wx.Direction.wxRIGHT or wx.Direction.wxBOTTOM or _
        wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 4)
      AutoLayout = true
      SetSizer(sizer_1)
      sizer_1.Fit(Me)
      sizer_1.SetSizeHints(Me)
    end sub

		private function ValidaDados(bTodosDados as boolean)
      if RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, _
        Resource.STR_CODNINF) then
        return false
      end if
      if bTodosDados then
        if RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, _
          Resource.STR_ENDNINF) then
        	return false
        end if
        if RotinasGlobais.Rotinas.ValidaCampo(edtBairro.Value, _
          Resource.STR_BAIRRONINF) then
        	return false
        end if
        if RotinasGlobais.Rotinas.ValidaCampo(edtCEP.Value, _
          Resource.STR_CEPNINF) then
        	return false
        end if
        if RotinasGlobais.Rotinas.ValidaCampo(edtCidade.Value, _
          Resource.STR_CIDADENINF) then
        	return false
        end if
      end if
			return true
		end function

		private sub OnClose(ByVal sender As Object, ByVal e As wx.Event)
      Me.Parent.Close()
			e.Skip()
		End Sub
    
    private sub OnBtnNovo(ByVal sender As Object, ByVal e As wx.Event)
      btnNovoClick()
      InformaLimpaDados(false)
      HabilitaDados(true)
      NovoDado(ConsultasSQL.ConsSQL.Endereco("N", edtCodigo.Value, _
        "","","","",""))
      e.Skip()
    end sub
    
    private sub OnBtnPesquisar(ByVal sender As Object, ByVal e As wx.Event)
      if PesquisarDados(ConsultasSQL.ConsSQL.Endereco("S", edtCodigo.Value, _
        "","","","",""), Resource.STR_ENDNENC) then
        InformaLimpaDados(true)
        HabilitaDados(true)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnAnterior(ByVal sender As Object, ByVal e As wx.Event)
      if registroAnterior() then
        InformaLimpaDados(true)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnProximo(ByVal sender As Object, ByVal e As wx.Event)
      if registroProximo() then
        InformaLimpaDados(true)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnSalvar(ByVal sender As Object, ByVal e As wx.Event)
      if SalvarDados(ValidaDados(true), _
        ConsultasSQL.ConsSQL.Endereco("S", edtCodigo.Value, _
          "","","","",""), _
        ConsultasSQL.ConsSQL.Endereco("U", edtCodigo.Value, _
          edtDescricao.Value,"","","",""), _
        ConsultasSQL.ConsSQL.Endereco("I", edtCodigo.Value, _
          edtDescricao.Value,"","","",""), true) then
        InformaLimpaDados(false)
        HabilitaDados(false)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnExcluir(ByVal sender As Object, ByVal e As wx.Event)
      if ExcluirDados(ValidaDados(false), _
        ConsultasSQL.ConsSQL.Endereco("D", edtCodigo.Value, _
        "","","","","")) then
        InformaLimpaDados(false)
        HabilitaDados(false)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnFechar(ByVal sender As Object, ByVal e As wx.Event)
      Me.Close(true)
      e.Skip()
    end sub
    
    private sub OnBtnLimpar(ByVal sender As Object, ByVal e As wx.Event)
      btnLimparClick()
      InformaLimpaDados(false)
      HabilitaDados(false)
      e.Skip()
    end sub

    protected overrides sub InformaLimpaDados(bInformar as boolean)
    	MyBase.InformaLimpaDados(bInformar)

      if bInformar then
        edtBairro.Value = Campos(2).ToString()
        edtCEP.Value = Campos(3).ToString()
        edtCidade.Value = Campos(4).ToString()
        cmbEstado.StringSelection = Campos(5).ToString()
      else
        edtBairro.Clear()
        edtCEP.Clear()
        edtCidade.Clear()
        cmbEstado.Selection = 0
      end if
    end sub
    
    protected overrides sub HabilitaDados(bHabilita as boolean)
			MyBase.HabilitaDados(bHabilita)

      edtBairro.Enabled = bHabilita
      edtCEP.Enabled = bHabilita  
      edtCidade.Enabled = bHabilita
      cmbEstado.Enabled = bHabilita  
    end sub
  
    private sub AdicionaCombo()
      vsEstados.SetValue(Resource.STR_PE, 0)
      vsEstados.SetValue(Resource.STR_AC, 1)
      vsEstados.SetValue(Resource.STR_AL, 2)
      vsEstados.SetValue(Resource.STR_AP, 3)
      vsEstados.SetValue(Resource.STR_AM, 4)
      vsEstados.SetValue(Resource.STR_BA, 5)
      vsEstados.SetValue(Resource.STR_BR, 6)
      vsEstados.SetValue(Resource.STR_CE, 7)
      vsEstados.SetValue(Resource.STR_DF, 8)
      vsEstados.SetValue(Resource.STR_ES, 9)
      vsEstados.SetValue(Resource.STR_GO, 10)
      vsEstados.SetValue(Resource.STR_MT, 11)
      vsEstados.SetValue(Resource.STR_MS, 12)
      vsEstados.SetValue(Resource.STR_MG, 13)
      vsEstados.SetValue(Resource.STR_PA, 14)
      vsEstados.SetValue(Resource.STR_PB, 15)
      vsEstados.SetValue(Resource.STR_PR, 16)
      vsEstados.SetValue(Resource.STR_SC, 17)
      vsEstados.SetValue(Resource.STR_RN, 18)
      vsEstados.SetValue(Resource.STR_RS, 19)
      vsEstados.SetValue(Resource.STR_RJ, 20)
      vsEstados.SetValue(Resource.STR_RO, 21)
      vsEstados.SetValue(Resource.STR_RR, 22)
      vsEstados.SetValue(Resource.STR_SP, 23)
      vsEstados.SetValue(Resource.STR_SE, 24)
      vsEstados.SetValue(Resource.STR_TO, 25)
    end sub

	End Class

End Namespace
