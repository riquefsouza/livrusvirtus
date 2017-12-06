Imports System
Imports System.Drawing
Imports System.Collections
Imports System.Data.OleDb
Imports Microsoft.VisualBasic
Imports wx

Namespace Livrus

	Public Class frmCadLivros
		Inherits frmCadastros
		
		public shared WithEvents fCadLivros as frmCadLivros

    private Enum idx
      ID_FRMCADLIVROS_BTNADASSUNTOS = 900 
      ID_FRMCADLIVROS_BTNADAUTORES 
      ID_FRMCADLIVROS_BTNPASSUNTO 
      ID_FRMCADLIVROS_BTNPAUTOR 
      ID_FRMCADLIVROS_BTNPEDITORA 
      ID_FRMCADLIVROS_CMBIDIOMA 
      ID_FRMCADLIVROS_EDTANOPUBLI 
      ID_FRMCADLIVROS_EDTASSUNTO 
      ID_FRMCADLIVROS_EDTAUTOR 
      ID_FRMCADLIVROS_EDTCODASSUNTO 
      ID_FRMCADLIVROS_EDTCODAUTOR 
      ID_FRMCADLIVROS_EDTCODEDITORA 
      ID_FRMCADLIVROS_EDTEDICAO 
      ID_FRMCADLIVROS_EDTEDITORA 
      ID_FRMCADLIVROS_EDTNPAGINAS 
      ID_FRMCADLIVROS_EDTPRECO 
      ID_FRMCADLIVROS_EDTQTDESTOQUE 
      ID_FRMCADLIVROS_EDTVOLUME 
      ID_FRMCADLIVROS_LABANOPUBLI 
      ID_FRMCADLIVROS_LABASSUNTO 
      ID_FRMCADLIVROS_LABAUTOR 
      ID_FRMCADLIVROS_LABEDICAO 
      ID_FRMCADLIVROS_LABEDITORA 
      ID_FRMCADLIVROS_LABIDIOMA 
      ID_FRMCADLIVROS_LABNPAGINAS 
      ID_FRMCADLIVROS_LABPRECO 
      ID_FRMCADLIVROS_LABQTDESTOQUE 
      ID_FRMCADLIVROS_LABVOLUME 
      ID_FRMCADLIVROS_LSTASSUNTOS 
      ID_FRMCADLIVROS_LSTAUTORES
    end enum

    private slIdiomas, slAssuntos, slAutores as ArrayList
    private labEdicao as wx.StaticText
    private edtEdicao as wx.SpinCtrl
    private labAnoPubli as wx.StaticText
    private edtAnoPubli as wx.SpinCtrl
    private labEditora as wx.StaticText
    private edtCodEditora as wx.TextCtrl
    private edtEditora as wx.TextCtrl
    private btnPEditora as wx.Button
    private labVolume as wx.StaticText
    private edtVolume as wx.SpinCtrl
    private labIdioma as wx.StaticText
    private cmbIdioma as wx.Choice
    private labNPaginas as wx.StaticText
    private edtNPaginas as wx.SpinCtrl
    private labAssunto as wx.StaticText
    private edtCodAssunto as wx.TextCtrl
    private edtAssunto as wx.TextCtrl
    private btnAdAssuntos as wx.Button
    private btnPAssunto as wx.Button
    private lstAssuntos as wx.ListBox
    private labPreco as wx.StaticText
    private edtPreco as wx.TextCtrl
    private labQtdEstoque as wx.StaticText
    private edtQtdEstoque as wx.SpinCtrl
    private labAutor as wx.StaticText
    private edtCodAutor as wx.TextCtrl
    private edtAutor as wx.TextCtrl
    private btnAdAutores as wx.Button
    private btnPAutor as wx.Button
    private lstAutores as wx.ListBox
    private vsIdiomas() as string

    Public Sub New(ByVal parent as Window)
      MyBase.New(parent, TextValidatorCtrl.FILTER_NONE, false)

      slIdiomas = new ArrayList()
      slAssuntos = new ArrayList()
      slAutores = new ArrayList()

      labCodigo.Label = "ISBN: "
      labDescricao.Label = "Título: "
      edtDescricao.SetSize(new Size(312, 21))
      edtCodigo.EVT_KILL_FOCUS(new EventListener( _
        AddressOf OnEdtCodigo_Killfocus )) 
     
      labEdicao = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABEDICAO, _
        "Edição: ", new Point(326, 48), new Size(39, 13), 0)
      edtEdicao = new wx.SpinCtrl(Me, idx.ID_FRMCADLIVROS_EDTEDICAO, _ 
        "1", new Point(324, 64), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1)
      edtEdicao.Enabled = false

      labAnoPubli = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABANOPUBLI, _
        "Ano Publicação: ", new Point(8, 88), new Size(81, 13), 0)  
      edtAnoPubli = new wx.SpinCtrl(Me, idx.ID_FRMCADLIVROS_EDTANOPUBLI, _
        "1", new Point(8, 104), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1)
      edtAnoPubli.Enabled = false
      
      labEditora = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABEDITORA, _
        "Editora: ", new Point(104, 88), new Size(39, 13), 0)  
      edtCodEditora = new TextValidatorCtrl(Me, idx.ID_FRMCADLIVROS_EDTCODEDITORA, _
        "", new Point(104, 104), new Size(78, 21), 0, TextValidatorCtrl.FILTER_NUMERIC )
      edtCodEditora.Enabled = false
      edtCodEditora.EVT_KILL_FOCUS( _
        new EventListener(AddressOf OnEdtCodEditora_Killfocus ))
      
      edtEditora = new wx.TextCtrl(Me, idx.ID_FRMCADLIVROS_EDTEDITORA, _
         "", new Point(184, 104), new Size(216, 21), 0)
      edtEditora.Enabled = false
      
      btnPEditora = new wx.Button(Me, idx.ID_FRMCADLIVROS_BTNPEDITORA, _
        "...", new Point(400, 104), new Size(21, 21), 0)
      btnPEditora.Enabled = false
      
      labVolume = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABVOLUME, _
        "Volume: ", new Point(8, 128), new Size(41, 13), 0)  
      edtVolume = new wx.SpinCtrl(Me, idx.ID_FRMCADLIVROS_EDTVOLUME, _
        "1", new Point(8, 144), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, _
        1, 9999, 1)
      edtVolume.Enabled = false
      
      labIdioma = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABIDIOMA, _
        "Idioma: ", new Point(104, 128), new Size(56, 13), 0)

      AdicionaCombo()        
      cmbIdioma = new wx.Choice(Me, idx.ID_FRMCADLIVROS_CMBIDIOMA, _
        new Point(104, 144), new Size(320, 21), vsIdiomas)
      cmbIdioma.Enabled = false
      
      labNPaginas = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABNPAGINAS, _
        "Nº Páginas: ", new Point(8, 168), new Size(59, 13), 0)
      
      edtNPaginas = new wx.SpinCtrl(Me, idx.ID_FRMCADLIVROS_EDTNPAGINAS, _
        "1", new Point(8, 184), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, _
        1, 9999, 1)
      edtNPaginas.Enabled = false
      
      labAssunto = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABASSUNTO, _
        "Assunto: ", new Point(104, 168), new Size(44, 13), 0)
      
      edtCodAssunto = new TextValidatorCtrl(Me, idx.ID_FRMCADLIVROS_EDTCODASSUNTO, _
        "", new Point(104, 184), new Size(78, 21), 0, _
        TextValidatorCtrl.FILTER_NUMERIC)
      edtCodAssunto.Enabled = false
      edtCodAssunto.EVT_KILL_FOCUS( _
        new EventListener(AddressOf OnEdtCodAssunto_Killfocus ))
      
      edtAssunto = new wx.TextCtrl(Me, idx.ID_FRMCADLIVROS_EDTASSUNTO, _
        "", new Point(184, 184), new Size(192, 21), 0)
      edtAssunto.Enabled = false
      
      btnAdAssuntos = new wx.Button(Me, idx.ID_FRMCADLIVROS_BTNADASSUNTOS, _
        "+", new Point(376, 184), new Size(21, 21), 0)
      btnAdAssuntos.Enabled = false
      
      btnPAssunto = new wx.Button(Me, idx.ID_FRMCADLIVROS_BTNPASSUNTO, _
        "...", new Point(400, 184), new Size(21, 21), 0)
      btnPAssunto.Enabled = false

      lstAssuntos = new wx.ListBox(Me, idx.ID_FRMCADLIVROS_LSTASSUNTOS, _
        new Point(104, 208), new Size(320, 48))
      lstAssuntos.Enabled = false
      
      labPreco = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABPRECO, _
        "Preço: ", new Point(8, 216), new Size(40, 13), 0)
      
      edtPreco = new wx.TextCtrl(Me, idx.ID_FRMCADLIVROS_EDTPRECO, _
        "", new Point(7, 232), new Size(92, 21), 0)
      edtPreco.Enabled = false
      edtPreco.EVT_KILL_FOCUS( _
        new EventListener(AddressOf OnEdtPreco_Killfocus )) 
      
      labQtdEstoque = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABQTDESTOQUE, _
        "Qtd. Estoque: ", new Point(6, 256), new Size(68, 13), 0)
      
      edtQtdEstoque = new wx.SpinCtrl(Me, idx.ID_FRMCADLIVROS_EDTQTDESTOQUE, _
        "0", new Point(8, 272), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, _
        0, 9999, 0)
      edtQtdEstoque.Enabled = false
      
      labAutor = new wx.StaticText(Me, idx.ID_FRMCADLIVROS_LABAUTOR, _
        "Autor: ", new Point(104, 256), new Size(31, 13), 0)  
      edtCodAutor = new TextValidatorCtrl(Me, idx.ID_FRMCADLIVROS_EDTCODAUTOR, _
        "", new Point(104, 272), new Size(78, 21), 0, _
        TextValidatorCtrl.FILTER_NUMERIC)
      edtCodAutor.Enabled = false
      edtCodAutor.EVT_KILL_FOCUS( _
        new EventListener(AddressOf OnEdtCodAutor_Killfocus ))
      
      edtAutor = new wx.TextCtrl(Me, idx.ID_FRMCADLIVROS_EDTAUTOR, _
        "", new Point(184, 272), new Size(192, 21), 0)
      edtAutor.Enabled = false
      
      btnAdAutores = new wx.Button(Me, idx.ID_FRMCADLIVROS_BTNADAUTORES, _
        "+", new Point(376, 272), new Size(21, 21), 0)
      btnAdAutores.Enabled = false
      
      btnPAutor = new wx.Button(Me, idx.ID_FRMCADLIVROS_BTNPAUTOR, "...", _
        new Point(400, 272), new Size(21, 21), 0)
      btnPAutor.Enabled = false

      lstAutores = new wx.ListBox(Me, idx.ID_FRMCADLIVROS_LSTAUTORES, _
        new Point(104, 296), new Size(320, 48))
      lstAutores.Enabled = false
    
      IniciaBotoes()
      btnPesquisar.SetSize(427, 8, 75, 25)
      btnAnterior.SetSize(427, 40, 75, 25)
      btnProximo.SetSize(427, 72, 75, 25)
      btnSalvar.SetSize(187, 352, 75, 25)
      btnExcluir.SetSize(267, 352, 75, 25)
      btnLimpar.SetSize(347, 352, 75, 25)
      btnFechar.SetSize(427, 352, 75, 25)
    
      'FazLayout()
    
    	edtCodigo.MaxLength = 13
      edtDescricao.MaxLength = 50
      edtCodEditora.MaxLength = 5
      edtPreco.MaxLength = 7

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
      EVT_BUTTON(idx.ID_FRMCADLIVROS_BTNPEDITORA, _
        new EventListener(AddressOf OnBtnPEditora ))
      EVT_BUTTON(idx.ID_FRMCADLIVROS_BTNPASSUNTO, _
        new EventListener(AddressOf OnBtnPAssunto ))
      EVT_BUTTON(idx.ID_FRMCADLIVROS_BTNADASSUNTOS, _ 
        new EventListener(AddressOf OnBtnAdAssuntos ))
      EVT_BUTTON(idx.ID_FRMCADLIVROS_BTNPAUTOR, _
        new EventListener(AddressOf OnBtnPAutor ))
      EVT_BUTTON(idx.ID_FRMCADLIVROS_BTNADAUTORES, _
        new EventListener(AddressOf OnBtnAdAutores ))
      EVT_LISTBOX_DCLICK(idx.ID_FRMCADLIVROS_LSTASSUNTOS, _
        new EventListener(AddressOf OnLstAssuntos_Dblclk ))
      EVT_LISTBOX_DCLICK(idx.ID_FRMCADLIVROS_LSTAUTORES, _
        new EventListener(AddressOf OnLstAutores_Dblclk ))
    End Sub

    private sub FazLayout()
      dim sizer_1 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_2 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_3 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_4 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_5 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxVERTICAL)
      dim sizer_21 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim sizer_20 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_37 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_36 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_35 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_34 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_33 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_19 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_32 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_18 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_31 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_30 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_29 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_28 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_27 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_17 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_26 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim grid_sizer_25 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
      dim sizer_6 as wx.BoxSizer = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL)
      dim grid_sizer_24 as wx.GridSizer = new wx.GridSizer(2, 1, 0, 0)
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
      sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT or _
        wx.Alignment.wxALIGN_BOTTOM, 5)
      sizer_5.Add(sizer_7, 1, 0, 0)
      grid_sizer_8.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_8.Add(edtDescricao, 0, 0, 0)
      sizer_8.Add(grid_sizer_8, 0, 0, 0)
      grid_sizer_9.Add(labEdicao, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_9.Add(edtEdicao, 0, 0, 0)
      sizer_8.Add(grid_sizer_9, 0, wx.Direction.wxLEFT, 2)
      sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0)
      grid_sizer_4.Add(labAnoPubli, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_4.Add(edtAnoPubli, 0, 0, 0)
      sizer_6.Add(grid_sizer_4, 0, 0, 0)
      grid_sizer_5.Add(labEditora, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_5.Add(edtCodEditora, 0, 0, 0)
      sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4)
      grid_sizer_6.Add(20, 20, 0, 0, 0)
      grid_sizer_6.Add(edtEditora, 0, 0, 0)
      sizer_6.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_24.Add(20, 20, 0, 0, 0)
      grid_sizer_24.Add(btnPEditora, 0, 0, 0)
      sizer_6.Add(grid_sizer_24, 0, 0, 0)
      sizer_5.Add(sizer_6, 0, 0, 0)
      grid_sizer_25.Add(labVolume, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_25.Add(edtVolume, 0, 0, 0)
      sizer_17.Add(grid_sizer_25, 0, wx.Stretch.wxEXPAND, 0)
      grid_sizer_26.Add(labIdioma, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_26.Add(cmbIdioma, 0, 0, 0)
      sizer_17.Add(grid_sizer_26, 0, wx.Direction.wxLEFT or _
        wx.Stretch.wxEXPAND, 4)
      sizer_5.Add(sizer_17, 1, 0, 0)
      grid_sizer_27.Add(labNPaginas, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_27.Add(edtNPaginas, 0, 0, 0)
      sizer_18.Add(grid_sizer_27, 0, 0, 0)
      grid_sizer_28.Add(labAssunto, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_28.Add(edtCodAssunto, 0, 0, 0)
      sizer_18.Add(grid_sizer_28, 0, wx.Direction.wxLEFT, 4)
      grid_sizer_29.Add(20, 20, 0, 0, 0)
      grid_sizer_29.Add(edtAssunto, 0, 0, 0)
      sizer_18.Add(grid_sizer_29, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_30.Add(20, 20, 0, 0, 0)
      grid_sizer_30.Add(btnAdAssuntos, 0, 0, 0)
      sizer_18.Add(grid_sizer_30, 0, 0, 0)
      grid_sizer_31.Add(20, 20, 0, 0, 0)
      grid_sizer_31.Add(btnPAssunto, 0, 0, 0)
      sizer_18.Add(grid_sizer_31, 0, 0, 0)
      sizer_5.Add(sizer_18, 1, 0, 0)
      grid_sizer_32.Add(labPreco, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_32.Add(edtPreco, 0, 0, 0)
      sizer_19.Add(grid_sizer_32, 0, 0, 0)
      sizer_19.Add(lstAssuntos, 0, wx.Direction.wxLEFT, 4)
      sizer_5.Add(sizer_19, 1, 0, 0)
      grid_sizer_33.Add(labQtdEstoque, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_33.Add(edtQtdEstoque, 0, 0, 0)
      sizer_20.Add(grid_sizer_33, 0, 0, 0)
      grid_sizer_34.Add(labAutor, 0, wx.Alignment.wxALIGN_BOTTOM, 0)
      grid_sizer_34.Add(edtCodAutor, 0, 0, 0)
      sizer_20.Add(grid_sizer_34, 0, 0, 0)
      grid_sizer_35.Add(20, 20, 0, 0, 0)
      grid_sizer_35.Add(edtAutor, 0, 0, 0)
      sizer_20.Add(grid_sizer_35, 0, wx.Direction.wxLEFT, 2)
      grid_sizer_36.Add(20, 20, 0, 0, 0)
      grid_sizer_36.Add(btnAdAutores, 0, 0, 0)
      sizer_20.Add(grid_sizer_36, 0, 0, 0)
      grid_sizer_37.Add(20, 20, 0, 0, 0)
      grid_sizer_37.Add(btnPAutor, 0, 0, 0)
      sizer_20.Add(grid_sizer_37, 0, 0, 0)
      sizer_5.Add(sizer_20, 1, 0, 0)
      sizer_21.Add(92, 20, 0, 0, 0)
      sizer_21.Add(lstAutores, 0, 0, 0)
      sizer_5.Add(sizer_21, 0, 0, 0)
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
    end sub

		private function ValidaDados(bTodosDados as boolean)
      if RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, _
        Resource.STR_CODNINF) then
        return false
      end if
      if bTodosDados then
        if RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, _
          Resource.STR_LIVNINF) then
        	return false
        end if
    	  if RotinasGlobais.Rotinas.ValidaCampo(edtEditora.Value, _
          Resource.STR_EDTNINF) then
  		    return false
        end if
        if lstAssuntos.Count = 0 then
          wx.MessageDialog.MessageBox(Resource.STR_ASSNINF, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          return false
        end if
        if lstAutores.Count = 0 then
          wx.MessageDialog.MessageBox(Resource.STR_AUTNINF, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
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
      if PesquisarDados(ConsultasSQL.ConsSQL.Livro("S", edtCodigo.Value, _ 
        "","","","","","","","",""), Resource.STR_LIVNENC) then
        InformaLimpaDados(true)
        HabilitaDados(true)
      end if
      e.Skip()
    end sub
    
    private sub OnBtnAnterior(ByVal sender As Object, ByVal e As wx.Event)
      if registroAnterior()	then
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
      dim sCodIdioma, sSqlInsert, sSqlUpdate as string
      dim nPos as integer
      
      nPos = cmbIdioma.Selection
      sCodIdioma = slIdiomas(nPos).ToString()
    
      sSqlUpdate = ConsultasSQL.ConsSQL.Livro("U", edtCodigo.Value, _
        edtDescricao.Value, edtEdicao.Value.ToString(), _
        edtAnoPubli.Value.ToString(), edtVolume.Value.ToString(), _
        edtCodEditora.Value, sCodIdioma, edtNPaginas.Value.ToString(), _
        RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value,false), _
        edtQtdEstoque.Value.ToString())
    
      sSqlInsert = ConsultasSQL.ConsSQL.Livro("I", edtCodigo.Value, _
        edtDescricao.Value, edtEdicao.Value.ToString(), _
        edtAnoPubli.Value.ToString(), edtVolume.Value.ToString(), _
        edtCodEditora.Value, sCodIdioma, edtNPaginas.Value.ToString(), _
        RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value,false), _
        edtQtdEstoque.Value.ToString())
    
      if SalvarDados(ValidaDados(true), _
        ConsultasSQL.ConsSQL.Livro("S", edtCodigo.Value, _
        "","","","","","","","",""), sSqlUpdate, sSqlInsert, false) then
        SalvaLista("A")
        SalvaLista("B")
        btnLimparClick()
        InformaLimpaDados(false)
        HabilitaDados(false)	    
      end if
      e.Skip()
    end sub
    
    private sub OnBtnExcluir(ByVal sender As Object, ByVal e As wx.Event)
      if ExcluirDados(ValidaDados(false), _
        ConsultasSQL.ConsSQL.Livro("D", edtCodigo.Value, _
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
        edtEdicao.SetValue(Campos(2).ToString())
        edtAnoPubli.SetValue(Campos(3).ToString())
        edtVolume.SetValue(Campos(4).ToString())
        edtCodEditora.Value = Campos(5).ToString()
        edtEditora.Value = Campos(6).ToString()
        cmbIdioma.StringSelection = Campos(8).ToString()
        edtNPaginas.SetValue(Campos(9).ToString())
        edtPreco.Value = RotinasGlobais.Rotinas.VirgulaParaPonto( _
          Campos(10).ToString(), true)
        edtQtdEstoque.SetValue(Campos(11).ToString())
        RotinasGlobais.Rotinas.AdicionaValoresLista( _
          ConsultasSQL.ConsSQL.LivroAss("S", _
          edtCodigo.Value, ""), lstAssuntos, slAssuntos)      
        RotinasGlobais.Rotinas.AdicionaValoresLista( _
          ConsultasSQL.ConsSQL.LivroAut("S", _
          edtCodigo.Value, ""), lstAutores, slAutores)
      else  
        edtEdicao.SetValue("1")
        edtAnoPubli.SetValue( _
          RotinasGlobais.Rotinas.retDataHoraStr(true,false).Substring(6,4))
        edtVolume.SetValue("1")
        edtCodEditora.Clear()
        edtEditora.Clear()
        cmbIdioma.Selection = 0
        edtNPaginas.SetValue("1")
        edtPreco.Value = "0,00"
        edtQtdEstoque.SetValue("1")
        edtCodAssunto.Clear()
        lstAssuntos.Clear()
        edtCodAutor.Clear()
        lstAutores.Clear()
        slAssuntos.Clear()
        slAutores.Clear()
      end if
    end sub 
    
    protected overrides sub HabilitaDados(bHabilita as boolean)
			MyBase.HabilitaDados(bHabilita)

      edtEdicao.Enabled = bHabilita
      edtAnoPubli.Enabled = bHabilita
      edtVolume.Enabled = bHabilita
      edtCodEditora.Enabled = bHabilita
      btnPEditora.Enabled = bHabilita
      cmbIdioma.Enabled = bHabilita
      edtNPaginas.Enabled = bHabilita
      edtPreco.Enabled = bHabilita
      edtQtdEstoque.Enabled = bHabilita
      edtCodAssunto.Enabled = bHabilita
      btnPAssunto.Enabled = bHabilita
      btnAdAssuntos.Enabled = bHabilita
      lstAssuntos.Enabled = bHabilita
      edtCodAutor.Enabled = bHabilita
      btnPAutor.Enabled = bHabilita
      btnAdAutores.Enabled = bHabilita
      lstAutores.Enabled = bHabilita
    end sub
    
    private sub OnEdtCodigo_Killfocus(ByVal sender As Object, ByVal e As wx.Event)   
      if Len(edtCodigo.Value) > 0 then
      	if RotinasGlobais.Rotinas.ValidaISBN(edtCodigo.Value)=false then
          wx.MessageDialog.MessageBox(Resource.STR_ISBNINV, "Erro", _
            wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR)
          edtCodigo.Clear()
      		edtCodigo.SetFocus()
      	end if
      end if	
    end sub
    
    private sub AdicionaCombo() 
      dim lstLinhas as ArrayList = new ArrayList()
      dim Campos as ArrayList
      dim nLinha as integer
    
      if RotinasGlobais.Rotinas.ConsultaDadosLista(lstLinhas, _
        ConsultasSQL.ConsSQL.Idioma("S","","")) then
        ReDim vsIdiomas(lstLinhas.Count-1)
        for nLinha = 0 to lstLinhas.Count-1
          Campos = CType(lstLinhas(nLinha),ArrayList)
    	    slIdiomas.Add(Campos(0).ToString())
          vsIdiomas(nLinha) = Campos(1).ToString()
    	    'cmbIdioma.Append(Campos(1).ToString())
    	  next nLinha
      end if
    end sub
    
    private sub SalvaLista(sOpcao as string)
      dim sISBN as string
      dim nCont, nQtd as integer
      dim Arquiva as OleDbCommand = new OleDbCommand()
    
      sISBN = edtCodigo.Value
      if sOpcao = "A" then
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
          ConsultasSQL.ConsSQL.LivroAss("D",sISBN,"")) 
    
        nQtd = slAssuntos.Count-1
        for nCont=0 to nQtd
          RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
            ConsultasSQL.ConsSQL.LivroAss("I", _
            sISBN, slAssuntos(nCont).ToString()))
        next nCont
      else if sOpcao = "B" then
      	RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
          ConsultasSQL.ConsSQL.LivroAut("D",sISBN,""))
    
        nQtd = slAutores.Count-1
        for nCont=0 to nQtd
          RotinasGlobais.Rotinas.AtualizaDados(Arquiva, _
            ConsultasSQL.ConsSQL.LivroAut("I", _
            sISBN, slAutores(nCont).ToString()))
        next nCont
      end if
    end sub
    
    private sub OnEdtCodEditora_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sEditora as string
      dim ConsCampo as ArrayList = new ArrayList()   
   
      if Len(edtCodEditora.Value) > 0 then
        sEditora = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
          ConsultasSQL.ConsSQL.Editora("S", _
          edtCodEditora.Value,""),Resource.STR_EDTNENC)    
        if Len(sEditora) > 0 then
          edtEditora.Value = sEditora
        else
          edtCodEditora.Clear()
          edtCodEditora.SetFocus()
        end if
      else
        edtEditora.Clear()
      end if
    end sub
    
    private sub OnBtnPEditora(ByVal sender As Object, ByVal e As wx.Event)
      dim fConEditoras as frmConEditoras = new frmConEditoras(Me)
      fConEditoras.ShowModal()
      edtCodEditora.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodEditora_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnEdtPreco_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      if RotinasGlobais.Rotinas.ValidaFloat( _
            RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value, false)) then
        edtPreco.Value = _
          RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value, true)
      else 
        edtPreco.Value = "0,01"
        edtPreco.SetFocus()
      end if
    end sub
    
    private sub OnEdtCodAssunto_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sAssunto as string
      dim ConsCampo as ArrayList = new ArrayList()   
    
      if Len(edtCodAssunto.Value) > 0 then
        sAssunto = RotinasGlobais.Rotinas.ConsultaCampoDesc( _
          ConsCampo, ConsultasSQL.ConsSQL.Assunto("S", _
          edtCodAssunto.Value,""),Resource.STR_ASSNENC)    
        if Len(sAssunto) > 0 then
          edtAssunto.Value = sAssunto
        else
          edtCodAssunto.Clear()
          edtCodAssunto.SetFocus()
        end if
      else
        edtAssunto.Clear()
      end if
    end sub
    
    private sub OnBtnPAssunto(ByVal sender As Object, ByVal e As wx.Event)
      dim fConAssuntos as frmConAssuntos = new frmConAssuntos(Me)
      fConAssuntos.ShowModal()
      edtCodAssunto.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodAssunto_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnEdtCodAutor_Killfocus(ByVal sender As Object, ByVal e As wx.Event)
      dim sAutor as string
      dim ConsCampo as ArrayList = new ArrayList()   
    
      if Len(edtCodAutor.Value) > 0 then
        sAutor = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, _
          ConsultasSQL.ConsSQL.Autor("S", _
          edtCodAutor.Value,""),Resource.STR_AUTNENC)    
        if Len(sAutor) > 0 then
          edtAutor.Value = sAutor
        else
          edtCodAutor.Clear()
          edtCodAutor.SetFocus()
        end if
      else
        edtAutor.Clear()
      end if
    end sub
    
    private sub OnBtnPAutor(ByVal sender As Object, ByVal e As wx.Event)
      dim fConAutores as frmConAutores = new frmConAutores(Me)
      fConAutores.ShowModal()
      edtCodAutor.Value = RotinasGlobais.Rotinas.sCodigoSelecionado
      OnEdtCodAutor_Killfocus(nothing,nothing)
      e.Skip()
    end sub
    
    private sub OnBtnAdAssuntos(ByVal sender As Object, ByVal e As wx.Event)
      RotinasGlobais.Rotinas.AdicionaItemLista(lstAssuntos, _
        slAssuntos, edtCodAssunto, edtAssunto)
    end sub
    
    private sub OnLstAssuntos_Dblclk(ByVal sender As Object, ByVal e As wx.Event)
      RotinasGlobais.Rotinas.RemoveItemLista(lstAssuntos,slAssuntos)
    end sub
    
    private sub OnBtnAdAutores(ByVal sender As Object, ByVal e As wx.Event)
      RotinasGlobais.Rotinas.AdicionaItemLista(lstAutores, _
        slAutores, edtCodAutor, edtAutor)	
    end sub
    
    private sub OnLstAutores_Dblclk(ByVal sender As Object, ByVal e As wx.Event)
      RotinasGlobais.Rotinas.RemoveItemLista(lstAutores,slAutores)
    end sub

	End Class

End Namespace
