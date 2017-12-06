using System;
using System.Drawing;
using System.Collections;
using System.Data.OleDb;
using wx;

namespace Livrus
{
	public class frmCadLivros: frmCadastros
	{
    private enum idx {
     ID_FRMCADLIVROS_BTNADASSUNTOS = 900, ID_FRMCADLIVROS_BTNADAUTORES, 
     ID_FRMCADLIVROS_BTNPASSUNTO, ID_FRMCADLIVROS_BTNPAUTOR, 
     ID_FRMCADLIVROS_BTNPEDITORA, ID_FRMCADLIVROS_CMBIDIOMA, 
     ID_FRMCADLIVROS_EDTANOPUBLI, ID_FRMCADLIVROS_EDTASSUNTO, 
     ID_FRMCADLIVROS_EDTAUTOR, ID_FRMCADLIVROS_EDTCODASSUNTO, 
     ID_FRMCADLIVROS_EDTCODAUTOR, ID_FRMCADLIVROS_EDTCODEDITORA, 
     ID_FRMCADLIVROS_EDTEDICAO, ID_FRMCADLIVROS_EDTEDITORA, 
     ID_FRMCADLIVROS_EDTNPAGINAS, ID_FRMCADLIVROS_EDTPRECO, 
     ID_FRMCADLIVROS_EDTQTDESTOQUE, ID_FRMCADLIVROS_EDTVOLUME, 
     ID_FRMCADLIVROS_LABANOPUBLI, ID_FRMCADLIVROS_LABASSUNTO, 
     ID_FRMCADLIVROS_LABAUTOR, ID_FRMCADLIVROS_LABEDICAO, 
     ID_FRMCADLIVROS_LABEDITORA, ID_FRMCADLIVROS_LABIDIOMA, 
     ID_FRMCADLIVROS_LABNPAGINAS, ID_FRMCADLIVROS_LABPRECO, 
     ID_FRMCADLIVROS_LABQTDESTOQUE, ID_FRMCADLIVROS_LABVOLUME, 
     ID_FRMCADLIVROS_LSTASSUNTOS, ID_FRMCADLIVROS_LSTAUTORES }

    private ArrayList slIdiomas, slAssuntos, slAutores;
    private wx.StaticText labEdicao;
    private wx.SpinCtrl edtEdicao;
    private wx.StaticText labAnoPubli;
    private wx.SpinCtrl edtAnoPubli;
    private wx.StaticText labEditora;
    private wx.TextCtrl edtCodEditora;
    private wx.TextCtrl edtEditora;
    private wx.Button btnPEditora;
    private wx.StaticText labVolume;
    private wx.SpinCtrl edtVolume;
    private wx.StaticText labIdioma;
    private wx.Choice cmbIdioma;
    private wx.StaticText labNPaginas;
    private wx.SpinCtrl edtNPaginas;
    private wx.StaticText labAssunto;
    private wx.TextCtrl edtCodAssunto;
    private wx.TextCtrl edtAssunto;
    private wx.Button btnAdAssuntos;
    private wx.Button btnPAssunto;
    private wx.ListBox lstAssuntos;
    private wx.StaticText labPreco;
    private wx.TextCtrl edtPreco;
    private wx.StaticText labQtdEstoque;
    private wx.SpinCtrl edtQtdEstoque;
    private wx.StaticText labAutor;
    private wx.TextCtrl edtCodAutor;
    private wx.TextCtrl edtAutor;
    private wx.Button btnAdAutores;
    private wx.Button btnPAutor;
    private wx.ListBox lstAutores;
    private string[] vsIdiomas;

		public frmCadLivros(wx.Window parent)
      : base(parent, TextValidatorCtrl.FILTER_NONE, false){

      slIdiomas = new ArrayList();
      slAssuntos = new ArrayList();
      slAutores = new ArrayList();

      labCodigo.Label = "ISBN: ";
      labDescricao.Label = "Título: ";
      edtDescricao.SetSize(new Size(312, 21));
      edtCodigo.EVT_KILL_FOCUS(new EventListener( OnEdtCodigo_Killfocus )); 
     
      labEdicao = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABEDICAO,
        "Edição: ", new Point(326, 48), new Size(39, 13), 0);
      edtEdicao = new wx.SpinCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTEDICAO, 
        "1", new Point(324, 64), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1);
      edtEdicao.Enabled = false;

      labAnoPubli = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABANOPUBLI,
        "Ano Publicação: ", new Point(8, 88), new Size(81, 13), 0);  
      edtAnoPubli = new wx.SpinCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTANOPUBLI,
        "1", new Point(8, 104), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1);
      edtAnoPubli.Enabled = false;
      
      labEditora = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABEDITORA,
        "Editora: ", new Point(104, 88), new Size(39, 13), 0);  
      edtCodEditora = new TextValidatorCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTCODEDITORA,
        "", new Point(104, 104), new Size(78, 21), 0, TextValidatorCtrl.FILTER_NUMERIC );
      edtCodEditora.Enabled = false;
      edtCodEditora.EVT_KILL_FOCUS(
        new EventListener( OnEdtCodEditora_Killfocus ));
      
      edtEditora = new wx.TextCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTEDITORA,
         "", new Point(184, 104), new Size(216, 21), 0);
      edtEditora.Enabled = false;
      
      btnPEditora = new wx.Button(this, (int)idx.ID_FRMCADLIVROS_BTNPEDITORA,
        "...", new Point(400, 104), new Size(21, 21), 0);
      btnPEditora.Enabled = false;
      
      labVolume = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABVOLUME,
        "Volume: ", new Point(8, 128), new Size(41, 13), 0);  
      edtVolume = new wx.SpinCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTVOLUME, 
        "1", new Point(8, 144), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1);
      edtVolume.Enabled = false;
      
      labIdioma = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABIDIOMA,
        "Idioma: ", new Point(104, 128), new Size(56, 13), 0);

      AdicionaCombo();        
      cmbIdioma = new wx.Choice(this, (int)idx.ID_FRMCADLIVROS_CMBIDIOMA,
        new Point(104, 144), new Size(320, 21), vsIdiomas);
      cmbIdioma.Enabled = false;
      
      labNPaginas = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABNPAGINAS,
        "Nº Páginas: ", new Point(8, 168), new Size(59, 13), 0);
      
      edtNPaginas = new wx.SpinCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTNPAGINAS,
        "1", new Point(8, 184), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1);
      edtNPaginas.Enabled = false;
      
      labAssunto = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABASSUNTO,
        "Assunto: ", new Point(104, 168), new Size(44, 13), 0);
      
      edtCodAssunto = new TextValidatorCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTCODASSUNTO,
        "", new Point(104, 184), new Size(78, 21), 0,
        TextValidatorCtrl.FILTER_NUMERIC);
      edtCodAssunto.Enabled = false;
      edtCodAssunto.EVT_KILL_FOCUS(
        new EventListener( OnEdtCodAssunto_Killfocus ));
      
      edtAssunto = new wx.TextCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTASSUNTO,
        "", new Point(184, 184), new Size(192, 21), 0);
      edtAssunto.Enabled = false;
      
      btnAdAssuntos = new wx.Button(this, (int)idx.ID_FRMCADLIVROS_BTNADASSUNTOS,
        "+", new Point(376, 184), new Size(21, 21), 0);
      btnAdAssuntos.Enabled = false;
      
      btnPAssunto = new wx.Button(this, (int)idx.ID_FRMCADLIVROS_BTNPASSUNTO,
        "...", new Point(400, 184), new Size(21, 21), 0);
      btnPAssunto.Enabled = false;

      lstAssuntos = new wx.ListBox(this, (int)idx.ID_FRMCADLIVROS_LSTASSUNTOS,
        new Point(104, 208), new Size(320, 48));
      lstAssuntos.Enabled = false;
      
      labPreco = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABPRECO,
        "Preço: ", new Point(8, 216), new Size(40, 13), 0);
      
      edtPreco = new wx.TextCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTPRECO,
        "", new Point(7, 232), new Size(92, 21), 0);
      edtPreco.Enabled = false;
      edtPreco.EVT_KILL_FOCUS(
        new EventListener( OnEdtPreco_Killfocus )); 
      
      labQtdEstoque = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABQTDESTOQUE,
        "Qtd. Estoque: ", new Point(6, 256), new Size(68, 13), 0);
      
      edtQtdEstoque = new wx.SpinCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTQTDESTOQUE,
        "0", new Point(8, 272), new Size(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 0, 9999, 0);
      edtQtdEstoque.Enabled = false;
      
      labAutor = new wx.StaticText(this, (int)idx.ID_FRMCADLIVROS_LABAUTOR,
        "Autor: ", new Point(104, 256), new Size(31, 13), 0);  
      edtCodAutor = new TextValidatorCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTCODAUTOR,
        "", new Point(104, 272), new Size(78, 21), 0,
        TextValidatorCtrl.FILTER_NUMERIC);
      edtCodAutor.Enabled = false;
      edtCodAutor.EVT_KILL_FOCUS(
        new EventListener( OnEdtCodAutor_Killfocus ));
      
      edtAutor = new wx.TextCtrl(this, (int)idx.ID_FRMCADLIVROS_EDTAUTOR,
        "", new Point(184, 272), new Size(192, 21), 0);
      edtAutor.Enabled = false;
      
      btnAdAutores = new wx.Button(this, (int)idx.ID_FRMCADLIVROS_BTNADAUTORES,
        "+", new Point(376, 272), new Size(21, 21), 0);
      btnAdAutores.Enabled = false;
      
      btnPAutor = new wx.Button(this, (int)idx.ID_FRMCADLIVROS_BTNPAUTOR, "...",
        new Point(400, 272), new Size(21, 21), 0);
      btnPAutor.Enabled = false;

      lstAutores = new wx.ListBox(this, (int)idx.ID_FRMCADLIVROS_LSTAUTORES,
        new Point(104, 296), new Size(320, 48));
      lstAutores.Enabled = false;
    
      IniciaBotoes();
      btnPesquisar.SetSize(427, 8, 75, 25);
      btnAnterior.SetSize(427, 40, 75, 25);
      btnProximo.SetSize(427, 72, 75, 25);
      btnSalvar.SetSize(187, 352, 75, 25);
      btnExcluir.SetSize(267, 352, 75, 25);
      btnLimpar.SetSize(347, 352, 75, 25);
      btnFechar.SetSize(427, 352, 75, 25);
    
      //FazLayout();
    
    	edtCodigo.MaxLength = 13;
      edtDescricao.MaxLength = 50;
      edtCodEditora.MaxLength = 5;
      edtPreco.MaxLength = 7;

      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNNOVO, 
        new EventListener( OnBtnNovo ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNPESQUISAR, 
        new EventListener( OnBtnPesquisar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNANTERIOR, 
        new EventListener( OnBtnAnterior ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNPROXIMO, 
        new EventListener( OnBtnProximo ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNSALVAR, 
        new EventListener( OnBtnSalvar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNEXCLUIR, 
        new EventListener( OnBtnExcluir ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNLIMPAR, 
        new EventListener( OnBtnLimpar ));
      EVT_BUTTON((int)idt.ID_FRMCADASTROS_BTNFECHAR, 
        new EventListener( OnBtnFechar ));
			EVT_CLOSE( new EventListener( OnClose ) );
      EVT_BUTTON((int)idx.ID_FRMCADLIVROS_BTNPEDITORA, 
        new EventListener( OnBtnPEditora ));
      EVT_BUTTON((int)idx.ID_FRMCADLIVROS_BTNPASSUNTO, 
        new EventListener( OnBtnPAssunto ));
      EVT_BUTTON((int)idx.ID_FRMCADLIVROS_BTNADASSUNTOS, 
        new EventListener( OnBtnAdAssuntos ));
      EVT_BUTTON((int)idx.ID_FRMCADLIVROS_BTNPAUTOR, 
        new EventListener( OnBtnPAutor ));
      EVT_BUTTON((int)idx.ID_FRMCADLIVROS_BTNADAUTORES, 
        new EventListener( OnBtnAdAutores ));
      EVT_LISTBOX_DCLICK((int)idx.ID_FRMCADLIVROS_LSTASSUNTOS, 
        new EventListener( OnLstAssuntos_Dblclk ));
      EVT_LISTBOX_DCLICK((int)idx.ID_FRMCADLIVROS_LSTAUTORES, 
        new EventListener( OnLstAutores_Dblclk ));
    }

    private void FazLayout(){
      wx.BoxSizer sizer_1 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_2 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_3 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_4 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_5 = new wx.BoxSizer(wx.Orientation.wxVERTICAL);
      wx.BoxSizer sizer_21 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.BoxSizer sizer_20 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_37 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_36 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_35 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_34 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_33 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_19 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_32 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_18 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_31 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_30 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_29 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_28 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_27 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_17 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_26 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_25 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_6 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_24 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_6 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_5 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_4 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_8 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_9 = new wx.GridSizer(2, 1, 0, 0);
      wx.GridSizer grid_sizer_8 = new wx.GridSizer(2, 1, 0, 0);
      wx.BoxSizer sizer_7 = new wx.BoxSizer(wx.Orientation.wxHORIZONTAL);
      wx.GridSizer grid_sizer_7 = new wx.GridSizer(2, 1, 0, 0);
      grid_sizer_7.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_7.Add(edtCodigo, 0, 0, 0);
      sizer_7.Add(grid_sizer_7, 0, 0, 0);
      sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT|wx.Alignment.wxALIGN_BOTTOM, 5);
      sizer_5.Add(sizer_7, 1, 0, 0);
      grid_sizer_8.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_8.Add(edtDescricao, 0, 0, 0);
      sizer_8.Add(grid_sizer_8, 0, 0, 0);
      grid_sizer_9.Add(labEdicao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_9.Add(edtEdicao, 0, 0, 0);
      sizer_8.Add(grid_sizer_9, 0, wx.Direction.wxLEFT, 2);
      sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0);
      grid_sizer_4.Add(labAnoPubli, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_4.Add(edtAnoPubli, 0, 0, 0);
      sizer_6.Add(grid_sizer_4, 0, 0, 0);
      grid_sizer_5.Add(labEditora, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_5.Add(edtCodEditora, 0, 0, 0);
      sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4);
      grid_sizer_6.Add(20, 20, 0, 0, 0);
      grid_sizer_6.Add(edtEditora, 0, 0, 0);
      sizer_6.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 2);
      grid_sizer_24.Add(20, 20, 0, 0, 0);
      grid_sizer_24.Add(btnPEditora, 0, 0, 0);
      sizer_6.Add(grid_sizer_24, 0, 0, 0);
      sizer_5.Add(sizer_6, 0, 0, 0);
      grid_sizer_25.Add(labVolume, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_25.Add(edtVolume, 0, 0, 0);
      sizer_17.Add(grid_sizer_25, 0, wx.Stretch.wxEXPAND, 0);
      grid_sizer_26.Add(labIdioma, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_26.Add(cmbIdioma, 0, 0, 0);
      sizer_17.Add(grid_sizer_26, 0, wx.Direction.wxLEFT|wx.Stretch.wxEXPAND, 4);
      sizer_5.Add(sizer_17, 1, 0, 0);
      grid_sizer_27.Add(labNPaginas, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_27.Add(edtNPaginas, 0, 0, 0);
      sizer_18.Add(grid_sizer_27, 0, 0, 0);
      grid_sizer_28.Add(labAssunto, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_28.Add(edtCodAssunto, 0, 0, 0);
      sizer_18.Add(grid_sizer_28, 0, wx.Direction.wxLEFT, 4);
      grid_sizer_29.Add(20, 20, 0, 0, 0);
      grid_sizer_29.Add(edtAssunto, 0, 0, 0);
      sizer_18.Add(grid_sizer_29, 0, wx.Direction.wxLEFT, 2);
      grid_sizer_30.Add(20, 20, 0, 0, 0);
      grid_sizer_30.Add(btnAdAssuntos, 0, 0, 0);
      sizer_18.Add(grid_sizer_30, 0, 0, 0);
      grid_sizer_31.Add(20, 20, 0, 0, 0);
      grid_sizer_31.Add(btnPAssunto, 0, 0, 0);
      sizer_18.Add(grid_sizer_31, 0, 0, 0);
      sizer_5.Add(sizer_18, 1, 0, 0);
      grid_sizer_32.Add(labPreco, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_32.Add(edtPreco, 0, 0, 0);
      sizer_19.Add(grid_sizer_32, 0, 0, 0);
      sizer_19.Add(lstAssuntos, 0, wx.Direction.wxLEFT, 4);
      sizer_5.Add(sizer_19, 1, 0, 0);
      grid_sizer_33.Add(labQtdEstoque, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_33.Add(edtQtdEstoque, 0, 0, 0);
      sizer_20.Add(grid_sizer_33, 0, 0, 0);
      grid_sizer_34.Add(labAutor, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
      grid_sizer_34.Add(edtCodAutor, 0, 0, 0);
      sizer_20.Add(grid_sizer_34, 0, 0, 0);
      grid_sizer_35.Add(20, 20, 0, 0, 0);
      grid_sizer_35.Add(edtAutor, 0, 0, 0);
      sizer_20.Add(grid_sizer_35, 0, wx.Direction.wxLEFT, 2);
      grid_sizer_36.Add(20, 20, 0, 0, 0);
      grid_sizer_36.Add(btnAdAutores, 0, 0, 0);
      sizer_20.Add(grid_sizer_36, 0, 0, 0);
      grid_sizer_37.Add(20, 20, 0, 0, 0);
      grid_sizer_37.Add(btnPAutor, 0, 0, 0);
      sizer_20.Add(grid_sizer_37, 0, 0, 0);
      sizer_5.Add(sizer_20, 1, 0, 0);
      sizer_21.Add(92, 20, 0, 0, 0);
      sizer_21.Add(lstAutores, 0, 0, 0);
      sizer_5.Add(sizer_21, 0, 0, 0);
      sizer_3.Add(sizer_5, 0, 0, 0);
      sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_4.Add(btnProximo, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT, 2);
      sizer_3.Add(sizer_4, 1, 0, 0);
      sizer_1.Add(sizer_3, 1, wx.Direction.wxALL|wx.Stretch.wxEXPAND, 4);
      sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_2.Add(btnFechar, 0, wx.Direction.wxALL|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 2);
      sizer_1.Add(sizer_2, 0, wx.Direction.wxRIGHT|wx.Direction.wxBOTTOM|
        wx.Alignment.wxALIGN_RIGHT|wx.Alignment.wxALIGN_BOTTOM, 4);
      AutoLayout = true;
      SetSizer(sizer_1);
    }

		private bool ValidaDados(bool bTodosDados){
      if (RotinasGlobais.Rotinas.ValidaCampo(edtCodigo.Value, 
        Resource.STR_CODNINF))
        return false;
      if (bTodosDados) {
        if (RotinasGlobais.Rotinas.ValidaCampo(edtDescricao.Value, 
          Resource.STR_TITNINF))
        	return false;
    	  if (RotinasGlobais.Rotinas.ValidaCampo(edtEditora.Value, 
          Resource.STR_EDTNINF))
    		    return false;
        if (lstAssuntos.Count==0) {
          wx.MessageDialog.MessageBox(Resource.STR_ASSNINF, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          return false;
        }
        if (lstAutores.Count==0) {
          wx.MessageDialog.MessageBox(Resource.STR_AUTNINF, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          return false;
        }
      }
			return true;
		}

    private void OnClose( object sender, Event e ){
      this.Parent.Close();
      e.Skip();
    }
    
    private void OnBtnNovo( object sender, Event e ){
      btnNovoClick();
      InformaLimpaDados(false);
      HabilitaDados(true);
      e.Skip();
    }
    
    private void OnBtnPesquisar( object sender, Event e ){
      if (PesquisarDados(ConsultasSQL.ConsSQL.Livro('S', edtCodigo.Value,
        "","","","","","","","",""), Resource.STR_LIVNENC)) {
        InformaLimpaDados(true);
        HabilitaDados(true);	
      }
      e.Skip();
    }
    
    private void OnBtnAnterior( object sender, Event e ){
      if (registroAnterior())
        InformaLimpaDados(true);
      e.Skip();
    }
    
    private void OnBtnProximo( object sender, Event e ){
      if (registroProximo())
        InformaLimpaDados(true);
      e.Skip();
    }
    
    private void OnBtnSalvar( object sender, Event e ){
      string sCodIdioma, sSqlInsert, sSqlUpdate;
      int nPos;
      
      nPos = cmbIdioma.Selection;
      sCodIdioma = slIdiomas[nPos].ToString();
    
      sSqlUpdate = ConsultasSQL.ConsSQL.Livro('U', edtCodigo.Value, 
        edtDescricao.Value, edtEdicao.Value.ToString(), 
        edtAnoPubli.Value.ToString(), edtVolume.Value.ToString(),
        edtCodEditora.Value, sCodIdioma, edtNPaginas.Value.ToString(),
        RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value,false),
        edtQtdEstoque.Value.ToString());
    
      sSqlInsert = ConsultasSQL.ConsSQL.Livro('I', edtCodigo.Value, 
        edtDescricao.Value, edtEdicao.Value.ToString(), 
        edtAnoPubli.Value.ToString(), edtVolume.Value.ToString(),
        edtCodEditora.Value, sCodIdioma, edtNPaginas.Value.ToString(),
        RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value,false),
        edtQtdEstoque.Value.ToString());
    
      if (SalvarDados(ValidaDados(true),
        ConsultasSQL.ConsSQL.Livro('S', edtCodigo.Value,
          "","","","","","","","",""),
          sSqlUpdate, sSqlInsert, false)) {
        SalvaLista('A');
        SalvaLista('B');
        btnLimparClick();
        InformaLimpaDados(false);
        HabilitaDados(false);	    
      }  
      e.Skip();
    }
    
    private void OnBtnExcluir( object sender, Event e ){
      if (ExcluirDados(ValidaDados(false),
        ConsultasSQL.ConsSQL.Livro('D', edtCodigo.Value,
        "","","","","","","","",""))) {
        InformaLimpaDados(false);
        HabilitaDados(false);	
      }  
      e.Skip();
    }
    
    private void OnBtnFechar( object sender, Event e ){
      this.Close(true);
      e.Skip();
    }
    
    private void OnBtnLimpar( object sender, Event e ){
      btnLimparClick();
      InformaLimpaDados(false);
      HabilitaDados(false);	
      e.Skip();
    }

    protected override void InformaLimpaDados(bool bInformar){ 
      base.InformaLimpaDados(bInformar);

      if (bInformar) {
        edtEdicao.SetValue(Campos[2].ToString());
        edtAnoPubli.SetValue(Campos[3].ToString());
        edtVolume.SetValue(Campos[4].ToString());
        edtCodEditora.Value = Campos[5].ToString();
        edtEditora.Value = Campos[6].ToString();
        cmbIdioma.StringSelection = Campos[8].ToString();
        edtNPaginas.SetValue(Campos[9].ToString());
        edtPreco.Value = RotinasGlobais.Rotinas.VirgulaParaPonto(
          Campos[10].ToString(), true);
        edtQtdEstoque.SetValue(Campos[11].ToString());
        RotinasGlobais.Rotinas.AdicionaValoresLista(
          ConsultasSQL.ConsSQL.LivroAss('S', 
          edtCodigo.Value, ""), lstAssuntos, slAssuntos);      
        RotinasGlobais.Rotinas.AdicionaValoresLista(
          ConsultasSQL.ConsSQL.LivroAut('S',
          edtCodigo.Value, ""), lstAutores, slAutores);
      } else {  
        edtEdicao.SetValue("1");
        edtAnoPubli.SetValue(
          RotinasGlobais.Rotinas.retDataHoraStr(true,false).Substring(6,4));
        edtVolume.SetValue("1");
        edtCodEditora.Clear();
        edtEditora.Clear();
        cmbIdioma.Selection = 0;
        edtNPaginas.SetValue("1");
        edtPreco.Value = "0,00";
        edtQtdEstoque.SetValue("1");
        edtCodAssunto.Clear();
        lstAssuntos.Clear();
        edtCodAutor.Clear();
        lstAutores.Clear();
        slAssuntos.Clear();
        slAutores.Clear();
      }
    } 
    
    protected override void HabilitaDados(bool bHabilita){
			base.HabilitaDados(bHabilita);

      edtEdicao.Enabled = bHabilita;
      edtAnoPubli.Enabled = bHabilita;
      edtVolume.Enabled = bHabilita;
      edtCodEditora.Enabled = bHabilita;
      btnPEditora.Enabled = bHabilita;
      cmbIdioma.Enabled = bHabilita;
      edtNPaginas.Enabled = bHabilita;
      edtPreco.Enabled = bHabilita;
      edtQtdEstoque.Enabled = bHabilita;
      edtCodAssunto.Enabled = bHabilita;
      btnPAssunto.Enabled = bHabilita;
      btnAdAssuntos.Enabled = bHabilita;
      lstAssuntos.Enabled = bHabilita;
      edtCodAutor.Enabled = bHabilita;
      btnPAutor.Enabled = bHabilita;
      btnAdAutores.Enabled = bHabilita;
      lstAutores.Enabled = bHabilita;
    }
    
    private void OnEdtCodigo_Killfocus( object sender, Event e ){   
      if (edtCodigo.Value.Length > 0) {
      	if (RotinasGlobais.Rotinas.ValidaISBN(edtCodigo.Value)==false) {      
          wx.MessageDialog.MessageBox(Resource.STR_ISBNINV, "Erro", 
            wx.Dialog.wxOK | wx.Dialog.wxICON_ERROR);
          edtCodigo.Clear();
      		edtCodigo.SetFocus();
      	}
      }	
    }
    
    private void AdicionaCombo(){ 
      ArrayList lstLinhas = new ArrayList();
      ArrayList Campos;
      int nLinha;
    
      if (RotinasGlobais.Rotinas.ConsultaDadosLista(lstLinhas, 
        ConsultasSQL.ConsSQL.Idioma('S',"",""))) {
        vsIdiomas = new string[lstLinhas.Count];
        for (nLinha = 0; nLinha < lstLinhas.Count; nLinha++) {
          Campos = (ArrayList)lstLinhas[nLinha];
    	    slIdiomas.Add(Campos[0].ToString());
          vsIdiomas[nLinha] = Campos[1].ToString();
    	    //cmbIdioma.Append(Campos[1].ToString());
    	  }      
      }
    }
    
    private void SalvaLista(char sOpcao){
      string sISBN;
      int nCont, nQtd;
      OleDbCommand Arquiva = new OleDbCommand();
    
      sISBN = edtCodigo.Value;
      if (sOpcao=='A') {
        RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
          ConsultasSQL.ConsSQL.LivroAss('D',sISBN,"")); 
    
        nQtd = slAssuntos.Count;
        for (nCont=0; nCont < nQtd; nCont++)  {      
          RotinasGlobais.Rotinas.AtualizaDados(Arquiva, 
            ConsultasSQL.ConsSQL.LivroAss('I', 
            sISBN, slAssuntos[nCont].ToString()));
        }
      } else if (sOpcao=='B') {
      	RotinasGlobais.Rotinas.AtualizaDados(Arquiva,
          ConsultasSQL.ConsSQL.LivroAut('D',sISBN,""));
    
        nQtd = slAutores.Count;
        for (nCont=0; nCont < nQtd; nCont++)  {      
          RotinasGlobais.Rotinas.AtualizaDados(Arquiva, 
            ConsultasSQL.ConsSQL.LivroAut('I', 
            sISBN, slAutores[nCont].ToString()));
        }
      }
    }
    
    private void OnEdtCodEditora_Killfocus( object sender, Event e ){
      string sEditora;
      ArrayList ConsCampo = new ArrayList();   
   
      if (edtCodEditora.Value.Length > 0) {
        sEditora = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Editora('S',
          edtCodEditora.Value,""),Resource.STR_EDTNENC);    
        if (sEditora.Length > 0) {
          edtEditora.Value = sEditora;
        } else {
          edtCodEditora.Clear();
          edtCodEditora.SetFocus();
        }
      } else {
        edtEditora.Clear();
      }
    }
    
    private void OnBtnPEditora( object sender, Event e ){
      frmConEditoras fConEditoras = new frmConEditoras(this);
      fConEditoras.ShowModal();
      edtCodEditora.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodEditora_Killfocus(null,null);
      e.Skip();
    }
    
    private void OnEdtPreco_Killfocus( object sender, Event e ){
      if (RotinasGlobais.Rotinas.ValidaFloat(
            RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value, false)))
        edtPreco.Value = 
          RotinasGlobais.Rotinas.VirgulaParaPonto(edtPreco.Value, true);
      else {
        edtPreco.Value = "0,01";
        edtPreco.SetFocus();
      }
    }
    
    private void OnEdtCodAssunto_Killfocus( object sender, Event e ){
      string sAssunto;
      ArrayList ConsCampo = new ArrayList();   
    
      if (edtCodAssunto.Value.Length > 0) {
        sAssunto = RotinasGlobais.Rotinas.ConsultaCampoDesc(
          ConsCampo, ConsultasSQL.ConsSQL.Assunto('S',
          edtCodAssunto.Value,""),Resource.STR_ASSNENC);    
        if (sAssunto.Length > 0) {
          edtAssunto.Value = sAssunto;
        } else {
          edtCodAssunto.Clear();
          edtCodAssunto.SetFocus();
        }
      } else {
        edtAssunto.Clear();
      }
    }
    
    private void OnBtnPAssunto( object sender, Event e ){
      frmConAssuntos fConAssuntos = new frmConAssuntos(this);
      fConAssuntos.ShowModal();
      edtCodAssunto.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodAssunto_Killfocus(null,null);
      e.Skip();
    }
    
    private void OnEdtCodAutor_Killfocus( object sender, Event e ){
      string sAutor;
      ArrayList ConsCampo = new ArrayList();   
    
      if (edtCodAutor.Value.Length > 0) {
        sAutor = RotinasGlobais.Rotinas.ConsultaCampoDesc(ConsCampo, 
          ConsultasSQL.ConsSQL.Autor('S',
          edtCodAutor.Value,""),Resource.STR_AUTNENC);    
        if (sAutor.Length > 0) {
          edtAutor.Value = sAutor;
        } else {
          edtCodAutor.Clear();
          edtCodAutor.SetFocus();
        }
      } else {
        edtAutor.Clear();
      }
    }
    
    private void OnBtnPAutor( object sender, Event e ){
      frmConAutores fConAutores = new frmConAutores(this);
      fConAutores.ShowModal();
      edtCodAutor.Value = RotinasGlobais.Rotinas.sCodigoSelecionado;
      OnEdtCodAutor_Killfocus(null,null);
      e.Skip();
    }
    
    private void OnBtnAdAssuntos( object sender, Event e ){
      RotinasGlobais.Rotinas.AdicionaItemLista(lstAssuntos, 
        slAssuntos, edtCodAssunto, edtAssunto);
    }
    
    private void OnLstAssuntos_Dblclk( object sender, Event e ){
      RotinasGlobais.Rotinas.RemoveItemLista(lstAssuntos,slAssuntos);
    }
    
    private void OnBtnAdAutores( object sender, Event e ){
      RotinasGlobais.Rotinas.AdicionaItemLista(lstAutores, 
        slAutores, edtCodAutor, edtAutor);	
    }
    
    private void OnLstAutores_Dblclk( object sender, Event e ){
      RotinasGlobais.Rotinas.RemoveItemLista(lstAutores,slAutores);
    }

	}
}
