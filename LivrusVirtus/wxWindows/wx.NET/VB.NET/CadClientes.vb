Imports System
Imports System.Drawing
Imports System.Collections
Imports wx

Namespace Livrus

	Public Class frmCadClientes
		Inherits frmCadastros
		
		public shared WithEvents fCadClientes as frmCadClientes

    private enum idx
      ID_FRMCADCLIENTES_BTNPENDERECO = 800
      ID_FRMCADCLIENTES_SBENDERECO
      ID_FRMCADCLIENTES_BTNPPAIS
      ID_FRMCADCLIENTES_BTNPPROFISSAO 
      ID_FRMCADCLIENTES_EDTBAIRRO
      ID_FRMCADCLIENTES_EDTCEP 
      ID_FRMCADCLIENTES_EDTCIDADE 
      ID_FRMCADCLIENTES_EDTCODENDERECO 
      ID_FRMCADCLIENTES_EDTCODPAIS
      ID_FRMCADCLIENTES_EDTCODPROFISSAO
      ID_FRMCADCLIENTES_EDTDTNASC
      ID_FRMCADCLIENTES_EDTEMAIL 
      ID_FRMCADCLIENTES_EDTESTADO 
      ID_FRMCADCLIENTES_EDTIDENTIDADE 
      ID_FRMCADCLIENTES_EDTLOGRADOURO
      ID_FRMCADCLIENTES_EDTPAIS 
      ID_FRMCADCLIENTES_EDTPROFISSAO
      ID_FRMCADCLIENTES_EDTTELEFONE 
      ID_FRMCADCLIENTES_LABBAIRRO 
      ID_FRMCADCLIENTES_LABCEP 
      ID_FRMCADCLIENTES_LABCIDADE
      ID_FRMCADCLIENTES_LABDTNASC 
      ID_FRMCADCLIENTES_LABEMAIL
      ID_FRMCADCLIENTES_LABESTADO
      ID_FRMCADCLIENTES_LABIDENTIDADE
      ID_FRMCADCLIENTES_LABLOGRADOURO 
      ID_FRMCADCLIENTES_LABPAIS 
      ID_FRMCADCLIENTES_LABPROFISSAO 
      ID_FRMCADCLIENTES_LABTELEFONE
      ID_FRMCADCLIENTES_RBSEXO
    end enum

    private labEmail as wx.StaticText
    private edtEmail as wx.TextCtrl
    private labIdentidade as wx.StaticText
    private edtIdentidade as wx.TextCtrl
    private rbSexo as wx.RadioBox
    private labTelefone as wx.StaticText
    private edtTelefone as wx.TextCtrl
    private labDtNasc as wx.StaticText
    private edtDtNasc as wx.TextCtrl
    private sbEndereco as wx.StaticBox
    private edtCodEndereco as TextValidatorCtrl
    private btnPEndereco as wx.Button
    private labLogradouro as wx.StaticText
    private edtLogradouro as wx.TextCtrl
    private labBairro as wx.StaticText
    private edtBairro as wx.TextCtrl
    private labCEP as wx.StaticText
    private edtCEP as wx.TextCtrl
    private labCidade as wx.StaticText
    private edtCidade as wx.TextCtrl
    private labEstado as wx.StaticText
    private edtEstado as wx.TextCtrl
    private labPais as wx.StaticText
    private edtCodPais as TextValidatorCtrl
    private edtPais as wx.TextCtrl
    private btnPPais as wx.Button
    private labProfissao as wx.StaticText
    private edtCodProfissao as TextValidatorCtrl
    private edtProfissao as wx.TextCtrl
    private btnPProfissao as wx.Button

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, TextValidatorCtrl.FILTER_NONE, false)

      labDescricao.Label = "Nome: "
      edtDescricao.SetSize(new Size(312, 21))
      edtCodigo.EVT_KILL_FOCUS( new EventListener( _
        AddressOf OnEdtCodigo_Killfocus ))

      labEmail = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABEMAIL, _
                 "E-mail: ", new Point(8, 88), new Size(34, 13), 0)
      edtEmail = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTEMAIL, _
                 "", new Point(8, 104), new Size(312, 21), 0)
      edtEmail.Enabled = false
    
      labIdentidade = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABIDENTIDADE, _
                  "Identidade: ", new Point(322, 88), new Size(56, 13), 0)
      edtIdentidade = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTIDENTIDADE, _
                  "", new Point(322, 104), new Size(100, 21), 0)
      edtIdentidade.Enabled = false  

      dim sItems() as string = {"Masculino", "Feminino"}
      rbSexo = new wx.RadioBox(Me, idx.ID_FRMCADCLIENTES_RBSEXO, "Sexo", _
                  new Point(9, 128), new Size(200, 44), sItems, 2, _
                  wx.RadioBox.wxRA_SPECIFY_COLS)
      rbSexo.Enabled = false
    
      labTelefone = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABTELEFONE, _
                  "Telefone: ", new Point(216, 128), new Size(48, 13), 0)
      edtTelefone = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTTELEFONE, _
                  "", new Point(216, 144), new Size(104, 21), 0)
      edtTelefone.Enabled = false
    
      labDtNasc = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABDTNASC, _
                  "Dt. Nascimento", new Point(322, 128), new Size(73, 13), 0)
      edtDtNasc = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTDTNASC, _
                "", new Point(322, 144), new Size(100, 21), 0)
      edtDtNasc.Enabled = false
      edtDtNasc.EVT_KILL_FOCUS( new EventListener( _
        AddressOf OnEdtDtNasc_Killfocus ))

      sbEndereco = new wx.StaticBox(Me, idx.ID_FRMCADCLIENTES_SBENDERECO, _
        "Endereço", new Point(8, 176), new Size(432, 136), 0)
    
      edtCodEndereco = new TextValidatorCtrl(Me, _
        idx.ID_FRMCADCLIENTES_EDTCODENDERECO, _
        "", new Point(16, 200), new Size(88, 21), 0, _
        TextValidatorCtrl.FILTER_NUMERIC)
      edtCodEndereco.Enabled = false
      edtCodEndereco.EVT_KILL_FOCUS( new EventListener( _
        AddressOf OnEdtCodEndereco_Killfocus ))
    
      btnPEndereco = new wx.Button(Me, idx.ID_FRMCADCLIENTES_BTNPENDERECO, _
                  "...", new Point(104, 200), new Size(21, 21), 0)
      btnPEndereco.Enabled = false
    
      labLogradouro = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABLOGRADOURO, _
                  "Logradouro: ", new Point(16, 224), new Size(60, 13), 0)
      edtLogradouro = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTLOGRADOURO, _
                  "", new Point(16, 240), new Size(264, 21), 0)
      edtLogradouro.Enabled = false
    
      labBairro = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABBAIRRO, _
                  "Bairro:", new Point(284, 224), new Size(48, 13), 0)
      edtBairro = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTBAIRRO, _
                  "", new Point(284, 240), new Size(144, 21), 0)
      edtBairro.Enabled = false
    
      labCEP = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABCEP, "CEP: ", _
                  new Point(16, 264), new Size(40, 13), 0)
      edtCEP = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTCEP, "", _
                  new Point(16, 280), new Size(78, 21), 0)
      edtCEP.Enabled = false
    
      labCidade = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABCIDADE, _
                  "Cidade: ", new Point(96, 264), new Size(39, 13), 0)
      edtCidade = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTCIDADE, _
                  "", new Point(96, 280), new Size(184, 21), 0)
      edtCidade.Enabled = false
    
      labEstado = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABESTADO, _
                  "Estado: ", new Point(284, 264), new Size(56, 13), 0)
      edtEstado = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTESTADO, _
                  "", new Point(284, 280), new Size(144, 21), 0)
      edtEstado.Enabled = false
    
      labPais = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABPAIS, _
        "País de origem: ", new Point(8, 320), new Size(77, 16), 0)
      edtCodPais = new TextValidatorCtrl(Me, idx.ID_FRMCADCLIENTES_EDTCODPAIS, _
        "", new Point(8, 336), new Size(78, 21), 0, _
        TextValidatorCtrl.FILTER_ALPHA)
      edtCodPais.Enabled = false
      edtCodPais.EVT_KILL_FOCUS( new EventListener( _
        AddressOf OnEdtCodPais_Killfocus ))
      edtPais = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTPAIS, _
                  "", new Point(88, 336), new Size(240, 21), 0)
      edtPais.Enabled = false
      btnPPais = new wx.Button(Me, idx.ID_FRMCADCLIENTES_BTNPPAIS, "...", _
                   new Point(328, 336), new Size(21, 21), 0)
      btnPPais.Enabled = false
    
      labProfissao = new wx.StaticText(Me, idx.ID_FRMCADCLIENTES_LABPROFISSAO, _
                  "Profissão: ", new Point(8, 360), new Size(56, 13), 0)
      edtCodProfissao = new TextValidatorCtrl(Me, _
        idx.ID_FRMCADCLIENTES_EDTCODPROFISSAO, _
        "", new Point(8, 376), new Size(78, 21), 0, _
        TextValidatorCtrl.FILTER_NUMERIC)
      edtCodProfissao.Enabled = false
      edtCodProfissao.EVT_KILL_FOCUS( new EventListener( _
        AddressOf OnEdtCodProfissao_Killfocus ))
      edtProfissao = new wx.TextCtrl(Me, idx.ID_FRMCADCLIENTES_EDTPROFISSAO, _
                  "", new Point(88, 376), new Size(240, 21), 0)
      edtProfissao.Enabled = false
      btnPProfissao = new wx.Button(Me, idx.ID_FRMCADCLIENTES_BTNPPROFISSAO, _
                  "...", new Point(328, 376), new Size(21, 21), 0)
      btnPProfissao.Enabled = false
    
      IniciaBotoes()
      btnPesquisar.SetSize(440, 8, 75, 25)
      btnAnterior.SetSize(440, 40, 75, 25)
      btnProximo.SetSize(440, 72, 75, 25)
      btnSalvar.SetSize(200, 408, 75, 25)
      btnExcluir.SetSize(280, 408, 75, 25)
      btnLimpar.SetSize(360, 408, 75, 25)
      btnFechar.SetSize(440, 408, 75, 25)
    
      'FazLayout()
    
    	edtCodigo.MaxLength = 14
      edtDescricao.MaxLength = 30
      edtEmail.MaxLength = 30
      edtIdentidade.MaxLength = 10
      edtCodEndereco.MaxLength = 10
      edtTelefone.MaxLength = 17
      edtCodPais.MaxLength = 3
      edtCodProfissao.MaxLength = 10

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
			EVT_CLOSE( new EventListener(AddressOf OnClose ))
      EVT_BUTTON(idx.ID_FRMCADCLIENTES_BTNPENDERECO, _
        new EventListener(AddressOf OnBtnPEndereco ))
      EVT_BUTTON(idx.ID_FRMCADCLIENTES_BTNPPAIS, _
        new EventListener(AddressOf OnBtnPPais ))
      EVT_BUTTON(idx.ID_FRMCADCLIENTES_BTNPPROFISSAO, _
        new EventListener(AddressOf OnBtnPProfissao ))
    End Sub

    private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_5 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_16 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_23 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_22 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_19 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_15 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_21 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_20 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_18 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_11 as wx.StaticBoxSizer = new wx.StaticBoxSizer( _
        new wx.StaticBox(Me, -1, "Endereço"), wx.Orientation.wxVERTICAL)
      dim sizer_14 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_17 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_16 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_15 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_13 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_14 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_13 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_12 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_10 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_12 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_11 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_6 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_5 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_4 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_8 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
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
      sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0)
      grid_sizer_4.Add(labEmail, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_4.Add(edtEmail, 0, 0, 0)
      sizer_6.Add(grid_sizer_4, 0, 0, 0)
      grid_sizer_5.Add(labIdentidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_5.Add(edtIdentidade, 0, 0, 0)
      sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4)
      sizer_5.Add(sizer_6, 0, 0, 0)
      sizer_10.Add(rbSexo, 0, 0, 0)
      grid_sizer_11.Add(labTelefone, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_11.Add(edtTelefone, 0, 0, 0)
      sizer_10.Add(grid_sizer_11, 1, wx.Direction.wxLEFT or wx.Stretch.wxEXPAND, 4)
      grid_sizer_12.Add(labDtNasc, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_12.Add(edtDtNasc, 0, 0, 0)
      sizer_10.Add(grid_sizer_12, 1, wx.Direction.wxLEFT or wx.Stretch.wxEXPAND, 4)
      sizer_5.Add(sizer_10, 1, wx.Stretch.wxEXPAND, 0)
      sizer_12.Add(edtCodEndereco, 0, 0, 0)
      sizer_12.Add(btnPEndereco, 0, 0, 0)
      sizer_11.Add(sizer_12, 0, wx.Direction.wxALL, 2)
      grid_sizer_13.Add(labLogradouro, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_13.Add(edtLogradouro, 0, 0, 0)
      sizer_13.Add(grid_sizer_13, 0, 0, 0)
      grid_sizer_14.Add(labBairro, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_14.Add(edtBairro, 0, 0, 0)
      sizer_13.Add(grid_sizer_14, 0, wx.Direction.wxLEFT, 4)
      sizer_11.Add(sizer_13, 0, 0, 0)
      grid_sizer_15.Add(labCEP, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_15.Add(edtCEP, 0, 0, 0)
      sizer_14.Add(grid_sizer_15, 0, 0, 0)
      grid_sizer_16.Add(labCidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_16.Add(edtCidade, 0, 0, 0)
      sizer_14.Add(grid_sizer_16, 0, wx.Direction.wxLEFT, 4)
      grid_sizer_17.Add(labEstado, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_17.Add(edtEstado, 0, 0, 0)
      sizer_14.Add(grid_sizer_17, 0, wx.Direction.wxLEFT, 4)
      sizer_11.Add(sizer_14, 1, 0, 0)
      sizer_5.Add(sizer_11, 0, 0, 0)
      grid_sizer_18.Add(labPais, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_18.Add(edtCodPais, 0, 0, 0)
      sizer_15.Add(grid_sizer_18, 0, 0, 0)
      grid_sizer_20.Add(20, 20, 0, 0, 0)
      grid_sizer_20.Add(edtPais, 0, 0, 0)
      sizer_15.Add(grid_sizer_20, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_21.Add(20, 20, 0, 0, 0)
      grid_sizer_21.Add(btnPPais, 0, 0, 0)
      sizer_15.Add(grid_sizer_21, 0, 0, 0)
      sizer_5.Add(sizer_15, 0, 0, 0)
      grid_sizer_19.Add(labProfissao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_19.Add(edtCodProfissao, 0, 0, 0)
      sizer_16.Add(grid_sizer_19, 0, 0, 0)
      grid_sizer_22.Add(20, 20, 0, 0, 0)
      grid_sizer_22.Add(edtProfissao, 0, 0, 0)
      sizer_16.Add(grid_sizer_22, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_23.Add(20, 20, 0, 0, 0)
      grid_sizer_23.Add(btnPProfissao, 0, 0, 0)
      sizer_16.Add(grid_sizer_23, 0, 0, 0)
      sizer_5.Add(sizer_16, 0, 0, 0)
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
          Resource.STR_CLININF) then
        	return false
        end if
        if RotinasGlobais.Rotinas.ValidaCampo(edtEmail.Value, _
          Resource.STR_EMAILNINF) then
        	return false
        end if
    	  if RotinasGlobais.Rotinas.ValidaCampo(edtTelefone.Value, _
          Resource.STR_TELNINF) then
        	return false
        end if
    	  if RotinasGlobais.Rotinas.ValidaCampo(edtCodEndereco.Value, _
          Resource.STR_ENDNINF) then
        	return false
        end if
    	  if RotinasGlobais.Rotinas.ValidaCampo(edtCodPais.Value, _
          Resource.STR_PAISNINF) then
        	return false
        end if
    	  if RotinasGlobais.Rotinas.ValidaCampo(edtCodProfissao.Value, _
          Resource.STR_PROFNINF) then
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
      e.Skip()
    end sub
    
    private sub OnBtnPesquisar(ByVal sender As Object, ByVal e As wx.Event)
      if PesquisarDados(ConsultasSQL.ConsSQL.Cliente("S", edtCodigo.Value, _
        "","","","","","","","",""), Resource.STR_CLINENC) then
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
      dim sSexo, sDtNasc, sSqlInsert, sSqlUpdate as string
    
      if rbSexo.Selection = 0 then
         sSexo = "M"
      else   
         sSexo = "F"
      end if
    
      sDtNasc = RotinasGlobais.Rotinas.ConverteDataHoraStr( _
        edtDtNasc.Value,"MM/dd/yyyy")
    
      sSqlUpdate = ConsultasSQL.ConsSQL.Cliente("U", edtCodigo.Value, _
        edtDescricao.Value, edtEmail.Value,  edtIdentidade.Value, sSexo, _ 
        edtTelefone.Value, sDtNasc, edtCodEndereco.Value, _
        edtCodPais.Value, edtCodProfissao.Value)
    
      sSqlInsert = ConsultasSQL.ConsSQL.Cliente("I", edtCodigo.Value, _
        edtDescricao.Value, edtEmail.Value,  edtIdentidade.Value, sSexo, _ 
        edtTelefone.Value, sDtNasc, edtCodEndereco.Value, _
        edtCodPais.Value, edtCodProfissao.Value)
    
      if SalvarDados(ValidaDados(true), _
        ConsultasSQL.ConsSQL.Cliente("S", edtCodigo.Value, _
          "","","","","","","","",""), sSqlUpdate, sSqlInsert, true) then
        InformaLimpaDados(false)
        HabilitaDados(false)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnExcluir(ByVal sender As Object, ByVal e As wx.Event)
      if ExcluirDados(ValidaDados(false), _
        ConsultasSQL.ConsSQL.Cliente("D", edtCodigo.Value, _  
          "","","","","","","","","")) then
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
        edtEmail.Value = Campos(2).ToString()
        edtIdentidade.Value = Campos(3).ToString()
        if Campos(4).ToString() = "M" then
          rbSexo.Selection = 0
        else
          rbSexo.Selection = 1
        end if
        edtTelefone.Value = Campos(5).ToString()
        edtDtNasc.Value = Campos(6).ToString().Substring(0,10)
        edtCodEndereco.Value = Campos(7).ToString()
        edtLogradouro.Value = Campos(8).ToString()
        edtBairro.Value = Campos(9).ToString()
        edtCEP.Value = Campos(10).ToString()
        edtCidade.Value = Campos(11).ToString()
        edtEstado.Value = Campos(12).ToString()
        edtCodPais.Value = Campos(13).ToString()
        edtPais.Value = Campos(14).ToString()
        edtCodProfissao.Value = Campos(15).ToString()
        edtProfissao.Value = Campos(16).ToString()
      else
        edtEmail.Clear()
        edtIdentidade.Clear()
        rbSexo.Selection = 0
        edtTelefone.Clear()
        edtDtNasc.Clear()
        edtCodEndereco.Clear()
        edtLogradouro.Clear()
        edtBairro.Clear()
        edtCEP.Clear()
        edtCidade.Clear()
        edtEstado.Clear()
        edtCodPais.Clear()
        edtPais.Clear()
        edtCodProfissao.Clear()
        edtProfissao.Clear()
        edtCodigo.SetFocus()
      end if
    end sub 
    
    protected overrides sub HabilitaDados(bHabilita as boolean)
			MyBase.HabilitaDados(bHabilita)

      edtEmail.Enabled = bHabilita
      edtIdentidade.Enabled = bHabilita
      rbSexo.Enabled = bHabilita
      edtTelefone.Enabled = bHabilita
      edtDtNasc.Enabled = bHabilita
      edtCodEndereco.Enabled = bHabilita
      btnPEndereco.Enabled = bHabilita
      edtCodPais.Enabled = bHabilita
      btnPPais.Enabled = bHabilita
      edtCodProfissao.Enabled = bHabilita
      btnPProfissao.Enabled = bHabilita
    end sub
    
    private sub OnEdtCodigo_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      if edtCodigo.Value.Length > 0 then
      	if RotinasGlobais.Rotinas.ValidaCPF(edtCodigo.Value)=false then
          wx.MessageDialog.MessageBox(Resource.STR_CPFINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          edtCodigo.Clear()
      		edtCodigo.SetFocus()
      	end if
      end if	
    end sub

    private sub OnEdtDtNasc_Killfocus(ByVal sender As Object, ByVal e As wx.Event)   
      if edtDtNasc.Value.Length > 0 then
        if not RotinasGlobais.Rotinas.validaDataHora(edtDtNasc.Value, true) then
          wx.MessageDialog.MessageBox(Resource.STR_DTHRINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          edtDtNasc.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,false)
      		edtDtNasc.SetFocus()
        end if
      else
        edtDtNasc.Value = RotinasGlobais.Rotinas.retDataHoraStr(true,false)
      end if
      e.Skip()
    end sub
    
    private sub OnEdtCodEndereco_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sLogradouro as string
      dim ConsCampo as ArrayList = new ArrayList()
       
      if edtCodEndereco.Value.Length > 0 then
        sLogradouro = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
          ConsultasSQL.ConsSQL.Endereco("S", _
          edtCodEndereco.Value,"","","","",""),Resource.STR_ENDNENC)
        if sLogradouro.Length > 0 then
          edtLogradouro.Value = sLogradouro
          edtBairro.Value = ConsCampo(2).ToString()
          edtCEP.Value = ConsCampo(3).ToString()
          edtCidade.Value = ConsCampo(4).ToString()
          edtEstado.Value = ConsCampo(5).ToString()
        else
      	  edtCodEndereco.SetFocus()
          edtLogradouro.Clear()
          edtBairro.Clear()
          edtCEP.Clear()
      	  edtCidade.Clear()
      	  edtEstado.Clear()
        end if
      else
        edtLogradouro.Clear()
        edtBairro.Clear()
        edtCEP.Clear()
    	  edtCidade.Clear()
    	  edtEstado.Clear()
      end if
    end sub
    
    private sub OnEdtCodPais_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sPais as string
      dim ConsCampo as ArrayList = new ArrayList()  
    
      if edtCodPais.Value.Length > 0 then
        sPais = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
          ConsultasSQL.ConsSQL.Pais("S", _
          edtCodPais.Value,""),Resource.STR_PAISNENC)    
        if sPais.Length > 0 then
          edtPais.Value = sPais
        else
          edtCodPais.Clear()
          edtCodPais.SetFocus()
        end if
      else
        edtPais.Clear()
      end if
    end sub
    
    private sub OnEdtCodProfissao_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sProfissao as string
      dim ConsCampo as ArrayList = new ArrayList()   
    
      if edtCodProfissao.Value.Length > 0 then
        sProfissao = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
          ConsultasSQL.ConsSQL.Profissao("S", _
          edtCodProfissao.Value,""),Resource.STR_PROFNENC)    
    
        if sProfissao.Length > 0 then
          edtProfissao.Value = sProfissao
        else
          edtCodProfissao.Clear()
          edtCodProfissao.SetFocus()
        end if
      else
        edtProfissao.Clear()
      end if
    end sub

    private sub OnBtnPEndereco(ByVal sender As Object, ByVal e As wx.Event)
      dim fConEnderecos as frmConEnderecos = new frmConEnderecos(Me)
      fConEnderecos.ShowModal()
      edtCodEndereco.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodEndereco_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnBtnPPais(ByVal sender As Object, ByVal e As wx.Event)
      dim fConPaises as frmConPaises = new frmConPaises(Me)
      fConPaises.ShowModal()
      edtCodPais.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodPais_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnBtnPProfissao(ByVal sender As Object, ByVal e As wx.Event)
      dim fConProfissoes as frmConProfissoes = new frmConProfissoes(Me)
      fConProfissoes.ShowModal()
      edtCodProfissao.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodProfissao_Killfocus(nothing,nothing)
      e.Skip()
    end sub

	End Class

End Namespace
