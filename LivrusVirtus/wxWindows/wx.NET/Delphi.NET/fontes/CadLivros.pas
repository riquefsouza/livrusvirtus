unit CadLivros;

interface

uses
  System.Drawing, wx, Cadastros, System.Collections, System.Data.OleDb;

type
  TfrmCadLivros = class(TfrmCadastros)
  private
    slIdiomas, slAssuntos, slAutores: ArrayList;
    labEdicao: wx.StaticText;
    edtEdicao: wx.SpinCtrl;
    labAnoPubli: wx.StaticText;
    edtAnoPubli: wx.SpinCtrl;
    labEditora: wx.StaticText;
    edtCodEditora: wx.TextCtrl;
    edtEditora: wx.TextCtrl;
    btnPEditora: wx.Button;
    labVolume: wx.StaticText;
    edtVolume: wx.SpinCtrl;
    labIdioma: wx.StaticText;
    cmbIdioma: wx.Choice;
    labNPaginas: wx.StaticText;
    edtNPaginas: wx.SpinCtrl;
    labAssunto: wx.StaticText;
    edtCodAssunto: wx.TextCtrl;
    edtAssunto: wx.TextCtrl;
    btnAdAssuntos: wx.Button;
    btnPAssunto: wx.Button;
    lstAssuntos: wx.ListBox;
    labPreco: wx.StaticText;
    edtPreco: wx.TextCtrl;
    labQtdEstoque: wx.StaticText;
    edtQtdEstoque: wx.SpinCtrl;
    labAutor: wx.StaticText;
    edtCodAutor: wx.TextCtrl;
    edtAutor: wx.TextCtrl;
    btnAdAutores: wx.Button;
    btnPAutor: wx.Button;
    lstAutores: wx.ListBox;
    vsIdiomas: array of string;
    procedure FazLayout();
    function ValidaDados(bTodosDados: boolean): boolean;
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnBtnNovo(sender: System.Object; e: wx.Event);
    procedure OnBtnPesquisar(sender: System.Object; e: wx.Event);
    procedure OnBtnAnterior(sender: System.Object; e: wx.Event);
    procedure OnBtnProximo(sender: System.Object; e: wx.Event);
    procedure OnBtnSalvar(sender: System.Object; e: wx.Event);
    procedure OnBtnExcluir(sender: System.Object; e: wx.Event);
    procedure OnBtnLimpar(sender: System.Object; e: wx.Event);
    procedure OnBtnFechar(sender: System.Object; e: wx.Event);
    procedure OnEdtCodigo_Killfocus(sender: System.Object; e: wx.Event);
    procedure AdicionaCombo();
    procedure SalvaLista(sOpcao: char);
    procedure OnEdtCodEditora_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnBtnPEditora(sender: System.Object; e: wx.Event);
    procedure OnEdtPreco_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnEdtCodAssunto_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnBtnPAssunto(sender: System.Object; e: wx.Event);
    procedure OnEdtCodAutor_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnBtnPAutor(sender: System.Object; e: wx.Event);
    procedure OnBtnAdAssuntos(sender: System.Object; e: wx.Event);
    procedure OnLstAssuntos_Dblclk(sender: System.Object; e: wx.Event);
    procedure OnBtnAdAutores(sender: System.Object; e: wx.Event);
    procedure OnLstAutores_Dblclk(sender: System.Object; e: wx.Event);
  protected
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmCadLivros: TfrmCadLivros;

const
  ID_FRMCADLIVROS_BTNADASSUNTOS: integer = 900;
  ID_FRMCADLIVROS_BTNADAUTORES: integer = 901;
  ID_FRMCADLIVROS_BTNPASSUNTO: integer = 902;
  ID_FRMCADLIVROS_BTNPAUTOR: integer = 903;
  ID_FRMCADLIVROS_BTNPEDITORA: integer = 904;
  ID_FRMCADLIVROS_CMBIDIOMA: integer = 905;
  ID_FRMCADLIVROS_EDTANOPUBLI: integer = 906;
  ID_FRMCADLIVROS_EDTASSUNTO: integer = 907;
  ID_FRMCADLIVROS_EDTAUTOR: integer = 908;
  ID_FRMCADLIVROS_EDTCODASSUNTO: integer = 909;
  ID_FRMCADLIVROS_EDTCODAUTOR: integer = 910;
  ID_FRMCADLIVROS_EDTCODEDITORA: integer = 911;
  ID_FRMCADLIVROS_EDTEDICAO: integer = 912;
  ID_FRMCADLIVROS_EDTEDITORA: integer = 913;
  ID_FRMCADLIVROS_EDTNPAGINAS: integer = 914;
  ID_FRMCADLIVROS_EDTPRECO: integer = 915;
  ID_FRMCADLIVROS_EDTQTDESTOQUE: integer = 916;
  ID_FRMCADLIVROS_EDTVOLUME: integer = 917;
  ID_FRMCADLIVROS_LABANOPUBLI: integer = 918;
  ID_FRMCADLIVROS_LABASSUNTO: integer = 919;
  ID_FRMCADLIVROS_LABAUTOR: integer = 920;
  ID_FRMCADLIVROS_LABEDICAO: integer = 921;
  ID_FRMCADLIVROS_LABEDITORA: integer = 922;
  ID_FRMCADLIVROS_LABIDIOMA: integer = 923;
  ID_FRMCADLIVROS_LABNPAGINAS: integer = 924;
  ID_FRMCADLIVROS_LABPRECO: integer = 925;
  ID_FRMCADLIVROS_LABQTDESTOQUE: integer = 926;
  ID_FRMCADLIVROS_LABVOLUME: integer = 927;
  ID_FRMCADLIVROS_LSTASSUNTOS: integer = 928;
  ID_FRMCADLIVROS_LSTAUTORES: integer = 930;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadLivros))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL,
  ConEditoras, ConAssuntos, ConAutores;

constructor TfrmCadLivros.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_NONE, false, 'ISBN:', 'T�tulo:');

  slIdiomas := ArrayList.Create();
  slAssuntos := ArrayList.Create();
  slAutores := ArrayList.Create();

  edtDescricao.SetSize(System.Drawing.Size.Create(312, 21));
  edtCodigo.EVT_KILL_FOCUS( OnEdtCodigo_Killfocus ); 
 
  labEdicao := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABEDICAO,
    'Edi��o: ', System.Drawing.Point.Create(326, 48), 
    System.Drawing.Size.Create(39, 13), 0);
  edtEdicao := wx.SpinCtrl.Create(self, ID_FRMCADLIVROS_EDTEDICAO, 
    '1', System.Drawing.Point.Create(324, 64), 
    System.Drawing.Size.Create(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 
    1, 9999, 1);
  edtEdicao.Enabled := false;

  labAnoPubli := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABANOPUBLI,
    'Ano Publica��o: ', System.Drawing.Point.Create(8, 88), 
    System.Drawing.Size.Create(81, 13), 0);  
  edtAnoPubli := wx.SpinCtrl.Create(self, ID_FRMCADLIVROS_EDTANOPUBLI,
    '1', System.Drawing.Point.Create(8, 104), 
    System.Drawing.Size.Create(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 
    1, 9999, 1);
  edtAnoPubli.Enabled := false;
  
  labEditora := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABEDITORA,
    'Editora: ', System.Drawing.Point.Create(104, 88), 
    System.Drawing.Size.Create(39, 13), 0);  
  edtCodEditora := TTextValidatorCtrl.Create(self, 
    ID_FRMCADLIVROS_EDTCODEDITORA, '', System.Drawing.Point.Create(104, 104), 
    System.Drawing.Size.Create(78, 21), 0, FILTER_NUMERIC );
  edtCodEditora.Enabled := false;
  edtCodEditora.EVT_KILL_FOCUS( OnEdtCodEditora_Killfocus );
  
  edtEditora := wx.TextCtrl.Create(self, ID_FRMCADLIVROS_EDTEDITORA,
    '', System.Drawing.Point.Create(184, 104), 
    System.Drawing.Size.Create(216, 21), 0);
  edtEditora.Enabled := false;
  
  btnPEditora := wx.Button.Create(self, ID_FRMCADLIVROS_BTNPEDITORA,
    '...', System.Drawing.Point.Create(400, 104), 
    System.Drawing.Size.Create(21, 21), 0);
  btnPEditora.Enabled := false;
  
  labVolume := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABVOLUME,
    'Volume: ', System.Drawing.Point.Create(8, 128), 
    System.Drawing.Size.Create(41, 13), 0);  
  edtVolume := wx.SpinCtrl.Create(self, ID_FRMCADLIVROS_EDTVOLUME, 
    '1', System.Drawing.Point.Create(8, 144), 
    System.Drawing.Size.Create(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 
    1, 9999, 1);
  edtVolume.Enabled := false;

  labIdioma := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABIDIOMA,
    'Idioma: ', System.Drawing.Point.Create(104, 128),
    System.Drawing.Size.Create(56, 13), 0);

  AdicionaCombo();
  cmbIdioma := wx.Choice.Create(self, ID_FRMCADLIVROS_CMBIDIOMA,
    System.Drawing.Point.Create(104, 144),
    System.Drawing.Size.Create(320, 21), vsIdiomas);
  cmbIdioma.Enabled := false;

  labNPaginas := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABNPAGINAS,
    'N� P�ginas: ', System.Drawing.Point.Create(8, 168),
    System.Drawing.Size.Create(59, 13), 0);

  edtNPaginas := wx.SpinCtrl.Create(self, ID_FRMCADLIVROS_EDTNPAGINAS,'1',
    System.Drawing.Point.Create(8, 184), System.Drawing.Size.Create(92, 21),
    wx.SpinCtrl.wxSP_ARROW_KEYS, 1, 9999, 1);
  edtNPaginas.Enabled := false;

  labAssunto := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABASSUNTO,
    'Assunto: ', System.Drawing.Point.Create(104, 168),
    System.Drawing.Size.Create(44, 13), 0);

  edtCodAssunto := TTextValidatorCtrl.Create(self,
    ID_FRMCADLIVROS_EDTCODASSUNTO,'', System.Drawing.Point.Create(104, 184),
    System.Drawing.Size.Create(78, 21), 0, FILTER_NUMERIC);
  edtCodAssunto.Enabled := false;
  edtCodAssunto.EVT_KILL_FOCUS( OnEdtCodAssunto_Killfocus );
  
  edtAssunto := wx.TextCtrl.Create(self, ID_FRMCADLIVROS_EDTASSUNTO,
    '', System.Drawing.Point.Create(184, 184), 
    System.Drawing.Size.Create(192, 21), 0);
  edtAssunto.Enabled := false;
  
  btnAdAssuntos := wx.Button.Create(self, ID_FRMCADLIVROS_BTNADASSUNTOS,
    '+', System.Drawing.Point.Create(376, 184), 
    System.Drawing.Size.Create(21, 21), 0);
  btnAdAssuntos.Enabled := false;
  
  btnPAssunto := wx.Button.Create(self, ID_FRMCADLIVROS_BTNPASSUNTO,
    '...', System.Drawing.Point.Create(400, 184), 
    System.Drawing.Size.Create(21, 21), 0);
  btnPAssunto.Enabled := false;

  lstAssuntos := wx.ListBox.Create(self, ID_FRMCADLIVROS_LSTASSUNTOS,
    System.Drawing.Point.Create(104, 208), 
    System.Drawing.Size.Create(320, 48));
  lstAssuntos.Enabled := false;
  
  labPreco := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABPRECO,
    'Pre�o: ', System.Drawing.Point.Create(8, 216), 
    System.Drawing.Size.Create(40, 13), 0);
  
  edtPreco := wx.TextCtrl.Create(self, ID_FRMCADLIVROS_EDTPRECO,
    '', System.Drawing.Point.Create(7, 232), 
    System.Drawing.Size.Create(92, 21), 0);
  edtPreco.Enabled := false;
  edtPreco.EVT_KILL_FOCUS( OnEdtPreco_Killfocus ); 
  
  labQtdEstoque := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABQTDESTOQUE,
    'Qtd. Estoque: ', System.Drawing.Point.Create(6, 256), 
    System.Drawing.Size.Create(68, 13), 0);
  
  edtQtdEstoque := wx.SpinCtrl.Create(self, ID_FRMCADLIVROS_EDTQTDESTOQUE,
    '0', System.Drawing.Point.Create(8, 272), 
    System.Drawing.Size.Create(92, 21), wx.SpinCtrl.wxSP_ARROW_KEYS, 
    0, 9999, 0);
  edtQtdEstoque.Enabled := false;
  
  labAutor := wx.StaticText.Create(self, ID_FRMCADLIVROS_LABAUTOR,
    'Autor: ', System.Drawing.Point.Create(104, 256),
    System.Drawing.Size.Create(31, 13), 0);  
  edtCodAutor := TTextValidatorCtrl.Create(self, ID_FRMCADLIVROS_EDTCODAUTOR,
    '', System.Drawing.Point.Create(104, 272), 
    System.Drawing.Size.Create(78, 21), 0, FILTER_NUMERIC);
  edtCodAutor.Enabled := false;
  edtCodAutor.EVT_KILL_FOCUS( OnEdtCodAutor_Killfocus );
  
  edtAutor := wx.TextCtrl.Create(self, ID_FRMCADLIVROS_EDTAUTOR,
    '', System.Drawing.Point.Create(184, 272), 
    System.Drawing.Size.Create(192, 21), 0);
  edtAutor.Enabled := false;
  
  btnAdAutores := wx.Button.Create(self, ID_FRMCADLIVROS_BTNADAUTORES,
    '+', System.Drawing.Point.Create(376, 272), 
    System.Drawing.Size.Create(21, 21), 0);
  btnAdAutores.Enabled := false;
  
  btnPAutor := wx.Button.Create(self, ID_FRMCADLIVROS_BTNPAUTOR, '...',
    System.Drawing.Point.Create(400, 272), 
    System.Drawing.Size.Create(21, 21), 0);
  btnPAutor.Enabled := false;

  lstAutores := wx.ListBox.Create(self, ID_FRMCADLIVROS_LSTAUTORES,
    System.Drawing.Point.Create(104, 296),
    System.Drawing.Size.Create(320, 48));
  lstAutores.Enabled := false;

  IniciaBotoes();
  btnPesquisar.SetSize(427, 8, 75, 25);
  btnAnterior.SetSize(427, 40, 75, 25);
  btnProximo.SetSize(427, 72, 75, 25);
  btnSalvar.SetSize(187, 352, 75, 25);
  btnExcluir.SetSize(267, 352, 75, 25);
  btnLimpar.SetSize(347, 352, 75, 25);
  btnFechar.SetSize(427, 352, 75, 25);

  //FazLayout();

	edtCodigo.MaxLength := 13;
  edtDescricao.MaxLength := 50;
  edtCodEditora.MaxLength := 5;
  edtPreco.MaxLength := 7;

  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, OnBtnNovo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, OnBtnAnterior );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, OnBtnProximo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, OnBtnSalvar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, OnBtnExcluir );
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, OnBtnFechar );
	EVT_CLOSE( OnClose );
  EVT_BUTTON(ID_FRMCADLIVROS_BTNPEDITORA, OnBtnPEditora );
  EVT_BUTTON(ID_FRMCADLIVROS_BTNPASSUNTO, OnBtnPAssunto );
  EVT_BUTTON(ID_FRMCADLIVROS_BTNADASSUNTOS, OnBtnAdAssuntos );
  EVT_BUTTON(ID_FRMCADLIVROS_BTNPAUTOR, OnBtnPAutor );
  EVT_BUTTON(ID_FRMCADLIVROS_BTNADAUTORES, OnBtnAdAutores );
  EVT_LISTBOX_DCLICK(ID_FRMCADLIVROS_LSTASSUNTOS, OnLstAssuntos_Dblclk );
  EVT_LISTBOX_DCLICK(ID_FRMCADLIVROS_LSTAUTORES, OnLstAutores_Dblclk );
end;

procedure TfrmCadLivros.FazLayout();
var sizer_1, sizer_2, sizer_3, sizer_4, sizer_5, sizer_6, sizer_7, sizer_8, 
  sizer_17, sizer_18, sizer_19, sizer_21, sizer_20: wx.BoxSizer;
  grid_sizer_4, grid_sizer_5, grid_sizer_6, grid_sizer_7, grid_sizer_8,
  grid_sizer_9, grid_sizer_24, grid_sizer_25, grid_sizer_26, grid_sizer_27,
  grid_sizer_28, grid_sizer_29, grid_sizer_30, grid_sizer_31, grid_sizer_32,
  grid_sizer_33, grid_sizer_34, grid_sizer_35, grid_sizer_36,
  grid_sizer_37: wx.GridSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_3 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_4 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_5 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_21 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_20 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_37 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_36 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_35 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_34 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_33 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_19 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_32 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_18 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_31 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_30 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_29 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_28 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_27 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_17 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_26 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_25 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_6 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_24 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_6 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_5 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_4 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_8 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_9 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_8 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_7 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_7 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_7.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_7.Add(edtCodigo, 0, 0, 0);
  sizer_7.Add(grid_sizer_7, 0, 0, 0);
  sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT or
    wx.Alignment.wxALIGN_BOTTOM, 5);
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
  sizer_17.Add(grid_sizer_26, 0, wx.Direction.wxLEFT or wx.Stretch.wxEXPAND, 4);
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
  sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_4.Add(btnProximo, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_3.Add(sizer_4, 1, 0, 0);
  sizer_1.Add(sizer_3, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 4);
  sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_2.Add(btnFechar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_1.Add(sizer_2, 0, wx.Direction.wxRIGHT or wx.Direction.wxBOTTOM or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 4);
  AutoLayout := true;
  SetSizer(sizer_1);
end;

function TfrmCadLivros.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_TITNINF) then
    	result:=false;
	  if Rotinas.ValidaCampo(edtEditora.Value, Res.STR_EDTNINF) then
      result:=false;
    if lstAssuntos.Count = 0 then begin
      wx.MessageDialog.MessageBox(Res.STR_ASSNINF, 'Erro',
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      result:=false;
    end;
    if lstAutores.Count = 0 then begin
      wx.MessageDialog.MessageBox(Res.STR_AUTNINF, 'Erro',
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      result:=false;
    end;
  end;
end;

procedure TfrmCadLivros.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadLivros.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  if PesquisarDados(ConsSQL.Livro('S', edtCodigo.Value,
    '','','','','','','','',''), Res.STR_LIVNENC) then begin
    InformaLimpaDados(true);
    HabilitaDados(true);	
  end;  
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  if registroAnterior() then
    InformaLimpaDados(true);
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  if registroProximo() then
    InformaLimpaDados(true);
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnSalvar(sender: System.Object; e: wx.Event);
var sCodIdioma, sSqlInsert, sSqlUpdate: string;
  nPos: integer;
begin 
  nPos := cmbIdioma.Selection;
  sCodIdioma := slIdiomas[nPos].ToString();

  sSqlUpdate := ConsSQL.Livro('U', edtCodigo.Value, 
    edtDescricao.Value, edtEdicao.Value.ToString(), 
    edtAnoPubli.Value.ToString(), edtVolume.Value.ToString(),
    edtCodEditora.Value, sCodIdioma, edtNPaginas.Value.ToString(),
    Rotinas.VirgulaParaPonto(edtPreco.Value,false),
    edtQtdEstoque.Value.ToString());

  sSqlInsert := ConsSQL.Livro('I', edtCodigo.Value, 
    edtDescricao.Value, edtEdicao.Value.ToString(), 
    edtAnoPubli.Value.ToString(), edtVolume.Value.ToString(),
    edtCodEditora.Value, sCodIdioma, edtNPaginas.Value.ToString(),
    Rotinas.VirgulaParaPonto(edtPreco.Value,false),
    edtQtdEstoque.Value.ToString());

  if SalvarDados(ValidaDados(true),ConsSQL.Livro('S', edtCodigo.Value,
      '','','','','','','','',''),sSqlUpdate, sSqlInsert, false) then begin
    SalvaLista('A');
    SalvaLista('B');
    btnLimparClick();
    InformaLimpaDados(false);
    HabilitaDados(false);	    
  end;
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  if ExcluirDados(ValidaDados(false),ConsSQL.Livro('D', edtCodigo.Value,
    '','','','','','','','','')) then begin
    InformaLimpaDados(false);
    HabilitaDados(false);	
  end;
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);	
  e.Skip();
end;

procedure TfrmCadLivros.InformaLimpaDados(bInformar: boolean);
begin
  inherited InformaLimpaDados(bInformar);

  if bInformar then begin
    edtEdicao.SetValue(Campos[2].ToString());
    edtAnoPubli.SetValue(Campos[3].ToString());
    edtVolume.SetValue(Campos[4].ToString());
    edtCodEditora.Value := Campos[5].ToString();
    edtEditora.Value := Campos[6].ToString();
    cmbIdioma.StringSelection := Campos[8].ToString();
    edtNPaginas.SetValue(Campos[9].ToString());
    edtPreco.Value := Rotinas.VirgulaParaPonto(Campos[10].ToString(), true);
    edtQtdEstoque.SetValue(Campos[11].ToString());
    Rotinas.AdicionaValoresLista(ConsSQL.LivroAss('S', 
      edtCodigo.Value, ''), lstAssuntos, slAssuntos);      
    Rotinas.AdicionaValoresLista(ConsSQL.LivroAut('S',
      edtCodigo.Value, ''), lstAutores, slAutores);
  end else begin
    edtEdicao.SetValue('1');
    edtAnoPubli.SetValue(Copy(Rotinas.retDataHoraStr(true,false),7,4));
    edtVolume.SetValue('1');
    edtCodEditora.Clear();
    edtEditora.Clear();
    cmbIdioma.Selection := 0;
    edtNPaginas.SetValue('1');
    edtPreco.Value := '0,00';
    edtQtdEstoque.SetValue('1');
    edtCodAssunto.Clear();
    lstAssuntos.Clear();
    edtCodAutor.Clear();
    lstAutores.Clear();
    slAssuntos.Clear();
    slAutores.Clear();
  end;
end;

procedure TfrmCadLivros.HabilitaDados(bHabilita: boolean);
begin
	inherited HabilitaDados(bHabilita);

  edtEdicao.Enabled := bHabilita;
  edtAnoPubli.Enabled := bHabilita;
  edtVolume.Enabled := bHabilita;
  edtCodEditora.Enabled := bHabilita;
  btnPEditora.Enabled := bHabilita;
  cmbIdioma.Enabled := bHabilita;
  edtNPaginas.Enabled := bHabilita;
  edtPreco.Enabled := bHabilita;
  edtQtdEstoque.Enabled := bHabilita;
  edtCodAssunto.Enabled := bHabilita;
  btnPAssunto.Enabled := bHabilita;
  btnAdAssuntos.Enabled := bHabilita;
  lstAssuntos.Enabled := bHabilita;
  edtCodAutor.Enabled := bHabilita;
  btnPAutor.Enabled := bHabilita;
  btnAdAutores.Enabled := bHabilita;
  lstAutores.Enabled := bHabilita;
end;

procedure TfrmCadLivros.OnEdtCodigo_Killfocus(sender: System.Object;
  e: wx.Event);
begin   
  if Length(edtCodigo.Value) > 0 then begin
  	if Rotinas.ValidaISBN(edtCodigo.Value) = false then begin
      wx.MessageDialog.MessageBox(Res.STR_ISBNINV, 'Erro', 
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      edtCodigo.Clear();
  		edtCodigo.SetFocus();
  	end;
  end;	
end;

procedure TfrmCadLivros.AdicionaCombo();
var lstLinhas, Campos: ArrayList;
  nLinha: integer;
begin
  lstLinhas := ArrayList.Create();

  if Rotinas.ConsultaDadosLista(lstLinhas, 
    ConsSQL.Idioma('S','','')) then begin
    SetLength(vsIdiomas, lstLinhas.Count);
    for nLinha := 0 to lstLinhas.Count-1 do begin
      Campos := ArrayList(lstLinhas[nLinha]);
	    slIdiomas.Add(Campos[0].ToString());
      vsIdiomas[nLinha] := Campos[1].ToString();
	    //cmbIdioma.Append(Campos[1].ToString());
	  end;      
  end;
end;

procedure TfrmCadLivros.SalvaLista(sOpcao: char);
var sISBN: string;
  nCont, nQtd: integer;
  Arquiva: OleDbCommand;
begin
  Arquiva := OleDbCommand.Create();

  sISBN := edtCodigo.Value;
  if sOpcao = 'A' then begin
    Rotinas.AtualizaDados(Arquiva,
      ConsSQL.LivroAss('D',sISBN,'')); 

    nQtd := slAssuntos.Count;
    for nCont:=0 to nQtd-1 do begin
      Rotinas.AtualizaDados(Arquiva, ConsSQL.LivroAss('I', 
        sISBN, slAssuntos[nCont].ToString()));
    end;
  end else if sOpcao = 'B' then begin
  	Rotinas.AtualizaDados(Arquiva,
      ConsSQL.LivroAut('D',sISBN,''));

    nQtd := slAutores.Count;
    for nCont:=0 to nQtd-1 do begin
      Rotinas.AtualizaDados(Arquiva, ConsSQL.LivroAut('I', 
        sISBN, slAutores[nCont].ToString()));
    end;
  end;
end;

procedure TfrmCadLivros.OnEdtCodEditora_Killfocus(sender: System.Object;
  e: wx.Event);
var sEditora: string;
  ConsCampo: ArrayList;
begin
  ConsCampo := ArrayList.Create();   

  if Length(edtCodEditora.Value) > 0 then begin
    sEditora := Rotinas.ConsultaCampoDesc(ConsCampo, 
      ConsSQL.Editora('S', edtCodEditora.Value,''),Res.STR_EDTNENC);    
    if Length(sEditora) > 0 then
      edtEditora.Value := sEditora
    else begin
      edtCodEditora.Clear();
      edtCodEditora.SetFocus();
    end;
  end else 
    edtEditora.Clear();
end;

procedure TfrmCadLivros.OnBtnPEditora(sender: System.Object; e: wx.Event);
var fConEditoras: TfrmConEditoras;
begin
  fConEditoras := TfrmConEditoras.Create(self);
  fConEditoras.ShowModal();
  edtCodEditora.Value := Rotinas.sCodigoSelecionado;
  OnEdtCodEditora_Killfocus(nil,nil);
  e.Skip();
end;

procedure TfrmCadLivros.OnEdtPreco_Killfocus(sender: System.Object;
  e: wx.Event);
begin
  if Rotinas.ValidaFloat(Rotinas.VirgulaParaPonto(edtPreco.Value, false)) then
    edtPreco.Value := Rotinas.VirgulaParaPonto(edtPreco.Value, true)
  else begin
    edtPreco.Value := '0,01';
    edtPreco.SetFocus();
  end;
end;

procedure TfrmCadLivros.OnEdtCodAssunto_Killfocus(sender: System.Object;
  e: wx.Event);
var sAssunto: string;
  ConsCampo: ArrayList;
begin
  ConsCampo := ArrayList.Create();

  if Length(edtCodAssunto.Value) > 0 then begin
    sAssunto := Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Assunto('S',
      edtCodAssunto.Value,''),Res.STR_ASSNENC);    
    if Length(sAssunto) > 0 then
      edtAssunto.Value := sAssunto
    else begin
      edtCodAssunto.Clear();
      edtCodAssunto.SetFocus();
    end;
  end else 
    edtAssunto.Clear();
end;

procedure TfrmCadLivros.OnBtnPAssunto(sender: System.Object; e: wx.Event);
var fConAssuntos: TfrmConAssuntos;
begin
  fConAssuntos := TfrmConAssuntos.Create(self);
  fConAssuntos.ShowModal();
  edtCodAssunto.Value := Rotinas.sCodigoSelecionado;
  OnEdtCodAssunto_Killfocus(nil,nil);
  e.Skip();
end;

procedure TfrmCadLivros.OnEdtCodAutor_Killfocus(sender: System.Object;
  e: wx.Event);
var sAutor: string;
  ConsCampo: ArrayList;
begin
  ConsCampo := ArrayList.Create();

  if Length(edtCodAutor.Value) > 0 then begin
    sAutor := Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Autor('S',
      edtCodAutor.Value,''),Res.STR_AUTNENC);
    if Length(sAutor) > 0 then
      edtAutor.Value := sAutor
    else begin
      edtCodAutor.Clear();
      edtCodAutor.SetFocus();
    end;
  end else 
    edtAutor.Clear();
end;

procedure TfrmCadLivros.OnBtnPAutor(sender: System.Object; e: wx.Event);
var fConAutores: TfrmConAutores;
begin
  fConAutores := TfrmConAutores.Create(self);
  fConAutores.ShowModal();
  edtCodAutor.Value := Rotinas.sCodigoSelecionado;
  OnEdtCodAutor_Killfocus(nil,nil);
  e.Skip();
end;

procedure TfrmCadLivros.OnBtnAdAssuntos(sender: System.Object; e: wx.Event);
begin
  Rotinas.AdicionaItemLista(lstAssuntos, slAssuntos, 
    edtCodAssunto, edtAssunto);
end;

procedure TfrmCadLivros.OnLstAssuntos_Dblclk(sender: System.Object;
  e: wx.Event);
begin
  Rotinas.RemoveItemLista(lstAssuntos,slAssuntos);
end;

procedure TfrmCadLivros.OnBtnAdAutores(sender: System.Object; e: wx.Event);
begin
  Rotinas.AdicionaItemLista(lstAutores, slAutores, edtCodAutor, edtAutor);
end;

procedure TfrmCadLivros.OnLstAutores_Dblclk(sender: System.Object; e: wx.Event);
begin
  Rotinas.RemoveItemLista(lstAutores,slAutores);
end;

end.