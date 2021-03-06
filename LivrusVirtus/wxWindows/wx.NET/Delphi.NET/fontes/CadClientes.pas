unit CadClientes;

interface

uses
  System.Drawing, System.Collections, wx, Cadastros, TextValidatorCtrl;

type
  TfrmCadClientes = class(TfrmCadastros)
  private
    labEmail: wx.StaticText;
    edtEmail: wx.TextCtrl;
    labIdentidade: wx.StaticText;
    edtIdentidade: wx.TextCtrl;
    rbSexo: wx.RadioBox;
    labTelefone: wx.StaticText;
    edtTelefone: wx.TextCtrl;
    labDtNasc: wx.StaticText;
    edtDtNasc: wx.TextCtrl;
    sbEndereco: wx.StaticBox;
    edtCodEndereco: TTextValidatorCtrl;
    btnPEndereco: wx.Button;
    labLogradouro: wx.StaticText;
    edtLogradouro: wx.TextCtrl;
    labBairro: wx.StaticText;
    edtBairro: wx.TextCtrl;
    labCEP: wx.StaticText;
    edtCEP: wx.TextCtrl;
    labCidade: wx.StaticText;
    edtCidade: wx.TextCtrl;
    labEstado: wx.StaticText;
    edtEstado: wx.TextCtrl;
    labPais: wx.StaticText;
    edtCodPais: TTextValidatorCtrl;
    edtPais: wx.TextCtrl;
    btnPPais: wx.Button;
    labProfissao: wx.StaticText;
    edtCodProfissao: TTextValidatorCtrl;
    edtProfissao: wx.TextCtrl;
    btnPProfissao: wx.Button;
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
    procedure OnEdtDtNasc_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnEdtCodEndereco_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnEdtCodPais_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnEdtCodProfissao_Killfocus(sender: System.Object; e: wx.Event);
    procedure OnBtnPEndereco(sender: System.Object; e: wx.Event);
    procedure OnBtnPPais(sender: System.Object; e: wx.Event);
    procedure OnBtnPProfissao(sender: System.Object; e: wx.Event);
  protected
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmCadClientes: TfrmCadClientes;

const
  ID_FRMCADCLIENTES_BTNPENDERECO: integer = 800;
  ID_FRMCADCLIENTES_SBENDERECO: integer = 801;
  ID_FRMCADCLIENTES_BTNPPAIS: integer = 802;
  ID_FRMCADCLIENTES_BTNPPROFISSAO: integer = 803; 
  ID_FRMCADCLIENTES_EDTBAIRRO: integer = 804; 
  ID_FRMCADCLIENTES_EDTCEP: integer = 805; 
  ID_FRMCADCLIENTES_EDTCIDADE: integer = 806; 
  ID_FRMCADCLIENTES_EDTCODENDERECO: integer = 807; 
  ID_FRMCADCLIENTES_EDTCODPAIS: integer = 808; 
  ID_FRMCADCLIENTES_EDTCODPROFISSAO: integer = 809; 
  ID_FRMCADCLIENTES_EDTDTNASC: integer = 810; 
  ID_FRMCADCLIENTES_EDTEMAIL: integer = 811; 
  ID_FRMCADCLIENTES_EDTESTADO: integer = 812; 
  ID_FRMCADCLIENTES_EDTIDENTIDADE: integer = 813; 
  ID_FRMCADCLIENTES_EDTLOGRADOURO: integer = 814; 
  ID_FRMCADCLIENTES_EDTPAIS: integer = 815; 
  ID_FRMCADCLIENTES_EDTPROFISSAO: integer = 816; 
  ID_FRMCADCLIENTES_EDTTELEFONE: integer = 817; 
  ID_FRMCADCLIENTES_LABBAIRRO: integer = 818; 
  ID_FRMCADCLIENTES_LABCEP: integer = 819; 
  ID_FRMCADCLIENTES_LABCIDADE: integer = 820; 
  ID_FRMCADCLIENTES_LABDTNASC: integer = 821; 
  ID_FRMCADCLIENTES_LABEMAIL: integer = 822; 
  ID_FRMCADCLIENTES_LABESTADO: integer = 823; 
  ID_FRMCADCLIENTES_LABIDENTIDADE: integer = 824; 
  ID_FRMCADCLIENTES_LABLOGRADOURO: integer = 825; 
  ID_FRMCADCLIENTES_LABPAIS: integer = 826; 
  ID_FRMCADCLIENTES_LABPROFISSAO: integer = 827; 
  ID_FRMCADCLIENTES_LABTELEFONE: integer = 828; 
  ID_FRMCADCLIENTES_RBSEXO: integer = 829;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadClientes))]

implementation

uses RotinasGlobais, Resource, ConsultasSQL, ConEnderecos, ConPaises,
  ConProfissoes;

constructor TfrmCadClientes.Create(parent: wx.Window);
const sItems: array[0..1] of string = ('Masculino', 'Feminino');
begin
  inherited Create(parent, FILTER_NONE, false, 'C�digo:', 'Nome:');

  edtDescricao.SetSize(System.Drawing.Size.Create(312, 21));
  edtCodigo.EVT_KILL_FOCUS( OnEdtCodigo_Killfocus );

  labEmail := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABEMAIL,'E-mail: ', 
    System.Drawing.Point.Create(8, 88), System.Drawing.Size.Create(34, 13), 0);
  edtEmail := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTEMAIL,'', 
    System.Drawing.Point.Create(8, 104), System.Drawing.Size.Create(312, 21), 0);
  edtEmail.Enabled := false;

  labIdentidade := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABIDENTIDADE,
    'Identidade: ', System.Drawing.Point.Create(322, 88), 
    System.Drawing.Size.Create(56, 13), 0);
  edtIdentidade := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTIDENTIDADE,'', 
    System.Drawing.Point.Create(322, 104), 
    System.Drawing.Size.Create(100, 21), 0);
  edtIdentidade.Enabled := false;  
  
  rbSexo := wx.RadioBox.Create(self, ID_FRMCADCLIENTES_RBSEXO, 'Sexo',
    System.Drawing.Point.Create(9, 128), System.Drawing.Size.Create(200, 44), 
    sItems, 2, wx.RadioBox.wxRA_SPECIFY_COLS);
  rbSexo.Enabled := false;

  labTelefone := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABTELEFONE,
    'Telefone: ', System.Drawing.Point.Create(216, 128), 
    System.Drawing.Size.Create(48, 13), 0);
  edtTelefone := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTTELEFONE,'', 
    System.Drawing.Point.Create(216, 144), 
    System.Drawing.Size.Create(104, 21), 0);
  edtTelefone.Enabled := false;

  labDtNasc := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABDTNASC,
    'Dt. Nascimento', System.Drawing.Point.Create(322, 128), 
    System.Drawing.Size.Create(73, 13), 0);
  edtDtNasc := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTDTNASC,'', 
    System.Drawing.Point.Create(322, 144), 
    System.Drawing.Size.Create(100, 21), 0);
  edtDtNasc.Enabled := false;
  edtDtNasc.EVT_KILL_FOCUS( OnEdtDtNasc_Killfocus );

  sbEndereco := wx.StaticBox.Create(self, ID_FRMCADCLIENTES_SBENDERECO,
    'Endere�o', System.Drawing.Point.Create(8, 176), 
    System.Drawing.Size.Create(432, 136), 0);

  edtCodEndereco := TTextValidatorCtrl.Create(self,
    ID_FRMCADCLIENTES_EDTCODENDERECO,'', System.Drawing.Point.Create(16, 200),
    System.Drawing.Size.Create(88, 21), 0, FILTER_NUMERIC);
  edtCodEndereco.Enabled := false;
  edtCodEndereco.EVT_KILL_FOCUS( OnEdtCodEndereco_Killfocus );

  btnPEndereco := wx.Button.Create(self, ID_FRMCADCLIENTES_BTNPENDERECO,'...',
    System.Drawing.Point.Create(104, 200),
    System.Drawing.Size.Create(21, 21), 0);
  btnPEndereco.Enabled := false;

  labLogradouro := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABLOGRADOURO,
    'Logradouro: ', System.Drawing.Point.Create(16, 224),
    System.Drawing.Size.Create(60, 13), 0);
  edtLogradouro := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTLOGRADOURO,'',
    System.Drawing.Point.Create(16, 240),
    System.Drawing.Size.Create(264, 21), 0);
  edtLogradouro.Enabled := false;

  labBairro := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABBAIRRO,'Bairro:',
    System.Drawing.Point.Create(284, 224),
    System.Drawing.Size.Create(48, 13), 0);
  edtBairro := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTBAIRRO,'',
    System.Drawing.Point.Create(284, 240),
    System.Drawing.Size.Create(144, 21), 0);
  edtBairro.Enabled := false;

  labCEP := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABCEP, 'CEP: ',
    System.Drawing.Point.Create(16, 264),
    System.Drawing.Size.Create(40, 13), 0);
  edtCEP := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTCEP, '',
    System.Drawing.Point.Create(16, 280), 
    System.Drawing.Size.Create(78, 21), 0);
  edtCEP.Enabled := false;

  labCidade := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABCIDADE,'Cidade: ', 
    System.Drawing.Point.Create(96, 264), 
    System.Drawing.Size.Create(39, 13), 0);
  edtCidade := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTCIDADE,'', 
    System.Drawing.Point.Create(96, 280), 
    System.Drawing.Size.Create(184, 21), 0);
  edtCidade.Enabled := false;

  labEstado := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABESTADO,'Estado: ', 
    System.Drawing.Point.Create(284, 264), 
    System.Drawing.Size.Create(56, 13), 0);
  edtEstado := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTESTADO,'', 
    System.Drawing.Point.Create(284, 280), 
    System.Drawing.Size.Create(144, 21), 0);
  edtEstado.Enabled := false;

  labPais := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABPAIS,
    'Pa�s de origem: ', System.Drawing.Point.Create(8, 320), 
    System.Drawing.Size.Create(77, 16), 0);
  edtCodPais := TTextValidatorCtrl.Create(self, ID_FRMCADCLIENTES_EDTCODPAIS,'', 
    System.Drawing.Point.Create(8, 336),
    System.Drawing.Size.Create(78, 21), 0, FILTER_ALPHA);
  edtCodPais.Enabled := false;
  edtCodPais.EVT_KILL_FOCUS( OnEdtCodPais_Killfocus );
  edtPais := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTPAIS,'',
    System.Drawing.Point.Create(88, 336),
    System.Drawing.Size.Create(240, 21), 0);
  edtPais.Enabled := false;
  btnPPais := wx.Button.Create(self, ID_FRMCADCLIENTES_BTNPPAIS, '...',
    System.Drawing.Point.Create(328, 336),
    System.Drawing.Size.Create(21, 21), 0);
  btnPPais.Enabled := false;

  labProfissao := wx.StaticText.Create(self, ID_FRMCADCLIENTES_LABPROFISSAO,
    'Profiss�o: ', System.Drawing.Point.Create(8, 360),
    System.Drawing.Size.Create(56, 13), 0);
  edtCodProfissao := TTextValidatorCtrl.Create(self,
    ID_FRMCADCLIENTES_EDTCODPROFISSAO,'', System.Drawing.Point.Create(8, 376),
    System.Drawing.Size.Create(78, 21), 0, FILTER_NUMERIC);
  edtCodProfissao.Enabled := false;
  edtCodProfissao.EVT_KILL_FOCUS( OnEdtCodProfissao_Killfocus );
  edtProfissao := wx.TextCtrl.Create(self, ID_FRMCADCLIENTES_EDTPROFISSAO,'', 
    System.Drawing.Point.Create(88, 376), 
    System.Drawing.Size.Create(240, 21), 0);
  edtProfissao.Enabled := false;
  btnPProfissao := wx.Button.Create(self, ID_FRMCADCLIENTES_BTNPPROFISSAO,
    '...', System.Drawing.Point.Create(328, 376), 
    System.Drawing.Size.Create(21, 21), 0);
  btnPProfissao.Enabled := false;

  IniciaBotoes();
  btnPesquisar.SetSize(440, 8, 75, 25);
  btnAnterior.SetSize(440, 40, 75, 25);
  btnProximo.SetSize(440, 72, 75, 25);
  btnSalvar.SetSize(200, 408, 75, 25);
  btnExcluir.SetSize(280, 408, 75, 25);
  btnLimpar.SetSize(360, 408, 75, 25);
  btnFechar.SetSize(440, 408, 75, 25);

  //FazLayout();

	edtCodigo.MaxLength := 14;
  edtDescricao.MaxLength := 30;
  edtEmail.MaxLength := 30;
  edtIdentidade.MaxLength := 10;
  edtCodEndereco.MaxLength := 10;
  edtTelefone.MaxLength := 17;
  edtCodPais.MaxLength := 3;
  edtCodProfissao.MaxLength := 10;

  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, OnBtnNovo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, OnBtnAnterior );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, OnBtnProximo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, OnBtnSalvar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, OnBtnExcluir );
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, OnBtnFechar );
	EVT_CLOSE( OnClose );
  EVT_BUTTON(ID_FRMCADCLIENTES_BTNPENDERECO, OnBtnPEndereco );
  EVT_BUTTON(ID_FRMCADCLIENTES_BTNPPAIS, OnBtnPPais );
  EVT_BUTTON(ID_FRMCADCLIENTES_BTNPPROFISSAO, OnBtnPProfissao );
end;

procedure TfrmCadClientes.FazLayout();
var sizer_1, sizer_2, sizer_3, sizer_4, sizer_5, sizer_6, sizer_7, sizer_8, 
  sizer_10, sizer_12, sizer_13, sizer_14, sizer_15, sizer_16: wx.BoxSizer;
  grid_sizer_4, grid_sizer_5, grid_sizer_7, grid_sizer_8, grid_sizer_11, 
  grid_sizer_12, grid_sizer_13, grid_sizer_14, grid_sizer_15, grid_sizer_16, 
  grid_sizer_17, grid_sizer_18, grid_sizer_19, grid_sizer_20, grid_sizer_21, 
  grid_sizer_22, grid_sizer_23: wx.GridSizer;
  sizer_11: wx.StaticBoxSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_3 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_4 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_5 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_16 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_23 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_22 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_19 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_15 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_21 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_20 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_18 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_11 := wx.StaticBoxSizer.Create(
    wx.StaticBox.Create(self, -1, 'Endere�o'), wx.Orientation.wxVERTICAL);
  sizer_14 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_17 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_16 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_15 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_13 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_14 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_13 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_12 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_10 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_12 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_11 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_6 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_5 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_4 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_8 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_8 := wx.GridSizer.Create(2, 1, 0, 0);
  sizer_7 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_7 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_7.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_7.Add(edtCodigo, 0, 0, 0);
  sizer_7.Add(grid_sizer_7, 0, 0, 0);
  sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 5);
  sizer_5.Add(sizer_7, 1, 0, 0);
  grid_sizer_8.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_8.Add(edtDescricao, 0, 0, 0);
  sizer_8.Add(grid_sizer_8, 0, 0, 0);
  sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0);
  grid_sizer_4.Add(labEmail, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_4.Add(edtEmail, 0, 0, 0);
  sizer_6.Add(grid_sizer_4, 0, 0, 0);
  grid_sizer_5.Add(labIdentidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_5.Add(edtIdentidade, 0, 0, 0);
  sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4);
  sizer_5.Add(sizer_6, 0, 0, 0);
  sizer_10.Add(rbSexo, 0, 0, 0);
  grid_sizer_11.Add(labTelefone, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_11.Add(edtTelefone, 0, 0, 0);
  sizer_10.Add(grid_sizer_11, 1, wx.Direction.wxLEFT or wx.Stretch.wxEXPAND, 4);
  grid_sizer_12.Add(labDtNasc, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_12.Add(edtDtNasc, 0, 0, 0);
  sizer_10.Add(grid_sizer_12, 1, wx.Direction.wxLEFT or wx.Stretch.wxEXPAND, 4);
  sizer_5.Add(sizer_10, 1, wx.Stretch.wxEXPAND, 0);
  sizer_12.Add(edtCodEndereco, 0, 0, 0);
  sizer_12.Add(btnPEndereco, 0, 0, 0);
  sizer_11.Add(sizer_12, 0, wx.Direction.wxALL, 2);
  grid_sizer_13.Add(labLogradouro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_13.Add(edtLogradouro, 0, 0, 0);
  sizer_13.Add(grid_sizer_13, 0, 0, 0);
  grid_sizer_14.Add(labBairro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_14.Add(edtBairro, 0, 0, 0);
  sizer_13.Add(grid_sizer_14, 0, wx.Direction.wxLEFT, 4);
  sizer_11.Add(sizer_13, 0, 0, 0);
  grid_sizer_15.Add(labCEP, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_15.Add(edtCEP, 0, 0, 0);
  sizer_14.Add(grid_sizer_15, 0, 0, 0);
  grid_sizer_16.Add(labCidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_16.Add(edtCidade, 0, 0, 0);
  sizer_14.Add(grid_sizer_16, 0, wx.Direction.wxLEFT, 4);
  grid_sizer_17.Add(labEstado, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_17.Add(edtEstado, 0, 0, 0);
  sizer_14.Add(grid_sizer_17, 0, wx.Direction.wxLEFT, 4);
  sizer_11.Add(sizer_14, 1, 0, 0);
  sizer_5.Add(sizer_11, 0, 0, 0);
  grid_sizer_18.Add(labPais, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_18.Add(edtCodPais, 0, 0, 0);
  sizer_15.Add(grid_sizer_18, 0, 0, 0);
  grid_sizer_20.Add(20, 20, 0, 0, 0);
  grid_sizer_20.Add(edtPais, 0, 0, 0);
  sizer_15.Add(grid_sizer_20, 0, wx.Direction.wxLEFT, 2);
  grid_sizer_21.Add(20, 20, 0, 0, 0);
  grid_sizer_21.Add(btnPPais, 0, 0, 0);
  sizer_15.Add(grid_sizer_21, 0, 0, 0);
  sizer_5.Add(sizer_15, 0, 0, 0);
  grid_sizer_19.Add(labProfissao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_19.Add(edtCodProfissao, 0, 0, 0);
  sizer_16.Add(grid_sizer_19, 0, 0, 0);
  grid_sizer_22.Add(20, 20, 0, 0, 0);
  grid_sizer_22.Add(edtProfissao, 0, 0, 0);
  sizer_16.Add(grid_sizer_22, 0, wx.Direction.wxLEFT, 2);
  grid_sizer_23.Add(20, 20, 0, 0, 0);
  grid_sizer_23.Add(btnPProfissao, 0, 0, 0);
  sizer_16.Add(grid_sizer_23, 0, 0, 0);
  sizer_5.Add(sizer_16, 0, 0, 0);
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
  sizer_1.Fit(self);
  sizer_1.SetSizeHints(self);
end;

function TfrmCadClientes.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_CLININF) then
    	result:=false;
    if Rotinas.ValidaCampo(edtEmail.Value, Res.STR_EMAILNINF) then
      result:=false;
	  if Rotinas.ValidaCampo(edtTelefone.Value, Res.STR_TELNINF) then
		  result:=false;
	  if Rotinas.ValidaCampo(edtCodEndereco.Value, Res.STR_ENDNINF) then
		  result:=false;
	  if Rotinas.ValidaCampo(edtCodPais.Value, Res.STR_PAISNINF) then
		  result:=false;
	  if Rotinas.ValidaCampo(edtCodProfissao.Value, Res.STR_PROFNINF) then
		  result:=false;
  end;
end;

procedure TfrmCadClientes.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadClientes.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  if PesquisarDados(ConsSQL.Cliente('S', edtCodigo.Value,
    '','','','','','','','',''), Res.STR_CLINENC) then begin
    InformaLimpaDados(true);
    HabilitaDados(true);	
  end;
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  if registroAnterior() then
    InformaLimpaDados(true);
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  if registroProximo() then
    InformaLimpaDados(true);
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnSalvar(sender: System.Object; e: wx.Event);
var sSexo, sDtNasc, sSqlInsert, sSqlUpdate: string;
begin
  if rbSexo.Selection = 0 then
     sSexo := 'M'
  else   
     sSexo := 'F';

  sDtNasc := Rotinas.ConverteDataHoraStr(edtDtNasc.Value,'MM/dd/yyyy');

  sSqlUpdate := ConsSQL.Cliente('U', edtCodigo.Value, 
    edtDescricao.Value, edtEmail.Value,  edtIdentidade.Value, sSexo,  
    edtTelefone.Value, sDtNasc, edtCodEndereco.Value, 
    edtCodPais.Value, edtCodProfissao.Value);

  sSqlInsert := ConsSQL.Cliente('I', edtCodigo.Value, 
    edtDescricao.Value, edtEmail.Value,  edtIdentidade.Value, sSexo,  
    edtTelefone.Value, sDtNasc, edtCodEndereco.Value, 
    edtCodPais.Value, edtCodProfissao.Value);

  if SalvarDados(ValidaDados(true),
    ConsSQL.Cliente('S', edtCodigo.Value,
      '','','','','','','','',''), sSqlUpdate, sSqlInsert, true) then begin
    InformaLimpaDados(false);
    HabilitaDados(false);	
  end;
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  if ExcluirDados(ValidaDados(false), ConsSQL.Cliente('D', 
    edtCodigo.Value,'','','','','','','','','')) then begin
    InformaLimpaDados(false);
    HabilitaDados(false);	
  end;  
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);	
  e.Skip();
end;

procedure TfrmCadClientes.InformaLimpaDados(bInformar: boolean);
begin
  inherited InformaLimpaDados(bInformar);

  if bInformar then begin
    edtEmail.Value := Campos[2].ToString();
    edtIdentidade.Value := Campos[3].ToString();
    if Campos[4].ToString() = 'M' then
      rbSexo.Selection := 0
    else
      rbSexo.Selection := 1;
    edtTelefone.Value := Campos[5].ToString();
    edtDtNasc.Value := Copy(Campos[6].ToString(),1,10);
    edtCodEndereco.Value := Campos[7].ToString();
    edtLogradouro.Value := Campos[8].ToString();
    edtBairro.Value := Campos[9].ToString();
    edtCEP.Value := Campos[10].ToString();
    edtCidade.Value := Campos[11].ToString();
    edtEstado.Value := Campos[12].ToString();
    edtCodPais.Value := Campos[13].ToString();
    edtPais.Value := Campos[14].ToString();
    edtCodProfissao.Value := Campos[15].ToString();
    edtProfissao.Value := Campos[16].ToString();
  end else begin
    edtEmail.Clear();
    edtIdentidade.Clear();
    rbSexo.Selection := 0;
    edtTelefone.Clear();
    edtDtNasc.Clear();
    edtCodEndereco.Clear();
    edtLogradouro.Clear();
    edtBairro.Clear();
    edtCEP.Clear();
    edtCidade.Clear();
    edtEstado.Clear();
    edtCodPais.Clear();
    edtPais.Clear();
    edtCodProfissao.Clear();
    edtProfissao.Clear();
    edtCodigo.SetFocus();
  end;
end;

procedure TfrmCadClientes.HabilitaDados(bHabilita: boolean);
begin
  inherited HabilitaDados(bHabilita);

  edtEmail.Enabled := bHabilita;
  edtIdentidade.Enabled := bHabilita;
  rbSexo.Enabled := bHabilita;
  edtTelefone.Enabled := bHabilita;
  edtDtNasc.Enabled := bHabilita;
  edtCodEndereco.Enabled := bHabilita;
  btnPEndereco.Enabled := bHabilita;
  edtCodPais.Enabled := bHabilita;
  btnPPais.Enabled := bHabilita;
  edtCodProfissao.Enabled := bHabilita;
  btnPProfissao.Enabled := bHabilita;
end;

procedure TfrmCadClientes.OnEdtCodigo_Killfocus(sender: System.Object; 
  e: wx.Event);
begin
  if edtCodigo.Value.Length > 0 then begin
  	if Rotinas.ValidaCPF(edtCodigo.Value) = false then begin
      wx.MessageDialog.MessageBox(Res.STR_CPFINV, 'Erro', 
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      edtCodigo.Clear();
  		edtCodigo.SetFocus();
  	end;
  end;	
end;

procedure TfrmCadClientes.OnEdtDtNasc_Killfocus(sender: System.Object; 
  e: wx.Event);
begin
  if Length(edtDtNasc.Value) > 0 then begin
    if not Rotinas.validaDataHora(edtDtNasc.Value, true) then begin
      wx.MessageDialog.MessageBox(Res.STR_DTHRINV, 'Erro', 
        wx.Dialog.wxOK or wx.Dialog.wxICON_ERROR);
      edtDtNasc.Value := Rotinas.retDataHoraStr(true,false);
  		edtDtNasc.SetFocus();
    end;
  end else
    edtDtNasc.Value := Rotinas.retDataHoraStr(true,false);
  e.Skip();
end;

procedure TfrmCadClientes.OnEdtCodEndereco_Killfocus(sender: System.Object; 
  e: wx.Event);
var sLogradouro: string;
  ConsCampo: ArrayList;
begin 
  ConsCampo := ArrayList.Create();
   
  if Length(edtCodEndereco.Value) > 0 then begin
    sLogradouro := Rotinas.ConsultaCampoDesc(ConsCampo, ConsSQL.Endereco('S',
      edtCodEndereco.Value,'','','','',''),Res.STR_ENDNENC);
    if Length(sLogradouro) > 0 then begin
      edtLogradouro.Value := sLogradouro;
      edtBairro.Value := ConsCampo[2].ToString();
      edtCEP.Value := ConsCampo[3].ToString();
      edtCidade.Value := ConsCampo[4].ToString();
      edtEstado.Value := ConsCampo[5].ToString();
    end else begin
  	  edtCodEndereco.SetFocus();
      edtLogradouro.Clear();
      edtBairro.Clear();
      edtCEP.Clear();
  	  edtCidade.Clear();
  	  edtEstado.Clear();
    end;
  end else begin
    edtLogradouro.Clear();
    edtBairro.Clear();
    edtCEP.Clear();
	  edtCidade.Clear();
	  edtEstado.Clear();
  end;
end;

procedure TfrmCadClientes.OnEdtCodPais_Killfocus(sender: System.Object; 
  e: wx.Event);
var sPais: string;
  ConsCampo: ArrayList;
begin 
  ConsCampo := ArrayList.Create();

  if Length(edtCodPais.Value) > 0 then begin
    sPais := Rotinas.ConsultaCampoDesc(ConsCampo, 
      ConsSQL.Pais('S',edtCodPais.Value,''),Res.STR_PAISNENC);
    if Length(sPais) > 0 then begin
      edtPais.Value := sPais;
    end else begin
      edtCodPais.Clear();
      edtCodPais.SetFocus();
    end;
  end else begin
    edtPais.Clear();
  end;
end;

procedure TfrmCadClientes.OnEdtCodProfissao_Killfocus(sender: System.Object; 
  e: wx.Event);
var sProfissao: string;
  ConsCampo: ArrayList;
begin
  ConsCampo := ArrayList.Create();

  if Length(edtCodProfissao.Value) > 0 then begin
    sProfissao := Rotinas.ConsultaCampoDesc(ConsCampo, 
      ConsSQL.Profissao('S', edtCodProfissao.Value,''),Res.STR_PROFNENC);    

    if Length(sProfissao) > 0 then begin
      edtProfissao.Value := sProfissao;
    end else begin
      edtCodProfissao.Clear();
      edtCodProfissao.SetFocus();
    end;
  end else begin
    edtProfissao.Clear();
  end;
end;

procedure TfrmCadClientes.OnBtnPEndereco(sender: System.Object; e: wx.Event);
var fConEnderecos: TfrmConEnderecos;
begin
  fConEnderecos := TfrmConEnderecos.Create(self);
  fConEnderecos.ShowModal();
  edtCodEndereco.Value := Rotinas.sCodigoSelecionado;
  OnEdtCodEndereco_Killfocus(nil,nil);
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnPPais(sender: System.Object; e: wx.Event);
var fConPaises: TfrmConPaises;
begin
  fConPaises := TfrmConPaises.Create(self);
  fConPaises.ShowModal();
  edtCodPais.Value := Rotinas.sCodigoSelecionado;
  OnEdtCodPais_Killfocus(nil,nil);
  e.Skip();
end;

procedure TfrmCadClientes.OnBtnPProfissao(sender: System.Object; e: wx.Event);
var fConProfissoes: TfrmConProfissoes;
begin
  fConProfissoes := TfrmConProfissoes.Create(self);
  fConProfissoes.ShowModal();
  edtCodProfissao.Value := Rotinas.sCodigoSelecionado;
  OnEdtCodProfissao_Killfocus(nil,nil);
  e.Skip();
end;

end.
