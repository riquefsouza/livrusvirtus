unit CadEnderecos;

interface

uses
  System.Drawing, wx, Cadastros;

type
  TfrmCadEnderecos = class(TfrmCadastros)
  private
		labBairro: wx.StaticText;
		edtBairro: wx.TextCtrl;
		edtCEP: wx.TextCtrl;
		labCEP: wx.StaticText;
		edtCidade: wx.TextCtrl;
		labCidade: wx.StaticText;
		labEstado: wx.StaticText;
		cmbEstado: wx.Choice;
    vsEstados: array[0..25] of string;

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
    procedure AdicionaCombo();
  protected
    procedure InformaLimpaDados(bInformar: boolean); override;
    procedure HabilitaDados(bHabilita: boolean); override;
  public
    constructor Create(parent: wx.Window);
  end;

var
  frmCadEnderecos: TfrmCadEnderecos;

const
  ID_FRMCADENDERECOS_CMBESTADO: integer = 700;
  ID_FRMCADENDERECOS_EDTBAIRRO: integer = 701;
  ID_FRMCADENDERECOS_EDTCEP: integer = 702;
  ID_FRMCADENDERECOS_EDTCIDADE: integer = 703;
  ID_FRMCADENDERECOS_LABBAIRRO: integer = 704;
  ID_FRMCADENDERECOS_LABCEP: integer = 705;
  ID_FRMCADENDERECOS_LABCIDADE: integer = 706;
  ID_FRMCADENDERECOS_LABESTADO: integer = 707;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadEnderecos))]

implementation

uses Login, TextValidatorCtrl, RotinasGlobais, Resource, ConsultasSQL;

constructor TfrmCadEnderecos.Create(parent: wx.Window);
begin
  inherited Create(parent, FILTER_NUMERIC, false, 'C�digo:', 'Logradouro:');

  ClientSize := System.Drawing.Size.Create(523, 171);
  labDescricao.Size := System.Drawing.Size.Create(57, 13);
  edtDescricao.Size := System.Drawing.Size.Create(264, 21);

	labBairro := wx.StaticText.Create(self, ID_FRMCADENDERECOS_LABBAIRRO, 
    'Bairro:', System.Drawing.Point.Create(280, 48), 
    System.Drawing.Size.Create(48, 13) );
	edtBairro := wx.TextCtrl.Create(self, ID_FRMCADENDERECOS_EDTBAIRRO,
    '', System.Drawing.Point.Create(280, 64), 
    System.Drawing.Size.Create(144, 21) );
  edtBairro.Enabled := false;
	labCEP := wx.StaticText.Create(self, ID_FRMCADENDERECOS_LABCEP, 
    'CEP: ', System.Drawing.Point.Create(8, 88), 
    System.Drawing.Size.Create(40, 13) );
	edtCEP := wx.TextCtrl.Create(self, ID_FRMCADENDERECOS_EDTCEP, 
    '', System.Drawing.Point.Create(8, 104), 
    System.Drawing.Size.Create(72, 21) );
  edtCEP.Enabled := false;
	labCidade := wx.StaticText.Create(self, ID_FRMCADENDERECOS_LABCIDADE, 
    'Cidade: ', System.Drawing.Point.Create(88, 88), 
    System.Drawing.Size.Create(39, 13) );
	edtCidade := wx.TextCtrl.Create(self, ID_FRMCADENDERECOS_EDTCIDADE, 
    '', System.Drawing.Point.Create(88, 104), 
    System.Drawing.Size.Create(184, 21) );
  edtCidade.Enabled := false;
	labEstado := wx.StaticText.Create(self, ID_FRMCADENDERECOS_LABESTADO, 
    'Estado: ', System.Drawing.Point.Create(280, 88), 
    System.Drawing.Size.Create(56, 13) );
  AdicionaCombo();
	cmbEstado := wx.Choice.Create(self, ID_FRMCADENDERECOS_CMBESTADO, 
    System.Drawing.Point.Create(280, 104), 
    System.Drawing.Size.Create(144, 21), vsEstados );
  cmbEstado.Enabled := false;

  IniciaBotoes();

  btnPesquisar.SetSize(440, 8, 75, 25);
  btnAnterior.SetSize(440, 40, 75, 25);
  btnProximo.SetSize(440, 72, 75, 25);
  btnSalvar.SetSize(200, 136, 75, 25);
  btnExcluir.SetSize(280, 136, 75, 25);
  btnLimpar.SetSize(360, 136, 75, 25);
  btnFechar.SetSize(440, 136, 75, 25);

  //FazLayout();

  edtDescricao.MaxLength := 40;
  edtBairro.MaxLength := 15;
  edtCEP.MaxLength := 8;
  edtCidade.MaxLength := 30;

  EVT_BUTTON(ID_FRMCADASTROS_BTNNOVO, OnBtnNovo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPESQUISAR, OnBtnPesquisar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNANTERIOR, OnBtnAnterior );
  EVT_BUTTON(ID_FRMCADASTROS_BTNPROXIMO, OnBtnProximo );
  EVT_BUTTON(ID_FRMCADASTROS_BTNSALVAR, OnBtnSalvar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNEXCLUIR, OnBtnExcluir );
  EVT_BUTTON(ID_FRMCADASTROS_BTNLIMPAR, OnBtnLimpar );
  EVT_BUTTON(ID_FRMCADASTROS_BTNFECHAR, OnBtnFechar );
	EVT_CLOSE( OnClose );
end;

procedure TfrmCadEnderecos.FazLayout();
var sizer_1, sizer_2, sizer_3, sizer_4, sizer_5, sizer_6, 
    sizer_7, sizer_8: wx.BoxSizer; 
    grid_sizer_4, grid_sizer_5, grid_sizer_6, grid_sizer_7, 
    grid_sizer_8, grid_sizer_9: wx.GridSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_3 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_4 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_5 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_6 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
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
  sizer_7.Add(btnNovo, 0, wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 5);
  sizer_5.Add(sizer_7, 1, 0, 0);
  grid_sizer_8.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_8.Add(edtDescricao, 0, 0, 0);
  sizer_8.Add(grid_sizer_8, 0, 0, 0);
  grid_sizer_9.Add(labBairro, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_9.Add(edtBairro, 0, 0, 0);
  sizer_8.Add(grid_sizer_9, 0, wx.Direction.wxLEFT, 2);
  sizer_5.Add(sizer_8, 1, wx.Stretch.wxEXPAND, 0);
  grid_sizer_4.Add(labCEP, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_4.Add(edtCEP, 0, 0, 0);
  sizer_6.Add(grid_sizer_4, 0, 0, 0);
  grid_sizer_5.Add(labCidade, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_5.Add(edtCidade, 0, 0, 0);
  sizer_6.Add(grid_sizer_5, 0, wx.Direction.wxLEFT, 4);
  grid_sizer_6.Add(labEstado, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_6.Add(cmbEstado, 0, 0, 0);
  sizer_6.Add(grid_sizer_6, 0, wx.Direction.wxLEFT, 5);
  sizer_5.Add(sizer_6, 0, 0, 0);
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

function TfrmCadEnderecos.ValidaDados(bTodosDados: boolean): boolean;
begin
	result:=true;
  if Rotinas.ValidaCampo(edtCodigo.Value, Res.STR_CODNINF) then
    result:=false;
  if bTodosDados then begin
    if Rotinas.ValidaCampo(edtDescricao.Value, Res.STR_ENDNINF) then
    	result:=false;
    if Rotinas.ValidaCampo(edtBairro.Value, Res.STR_BAIRRONINF) then
    	result:=false;
    if Rotinas.ValidaCampo(edtCEP.Value, Res.STR_CEPNINF) then
    	result:=false;
    if Rotinas.ValidaCampo(edtCidade.Value, Res.STR_CIDADENINF) then
    	result:=false;
  end;
end;

procedure TfrmCadEnderecos.OnClose(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close();
	e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnNovo(sender: System.Object; e: wx.Event);
begin
  btnNovoClick();
  InformaLimpaDados(false);
  HabilitaDados(true);
  NovoDado(ConsSQL.Endereco('N', edtCodigo.Value,'','','','',''));	
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnPesquisar(sender: System.Object; e: wx.Event);
begin
  if PesquisarDados(ConsSQL.Endereco('S', edtCodigo.Value,'','','','',''), 
    Res.STR_ENDNENC) then begin
    InformaLimpaDados(true);
    HabilitaDados(true);
  end;
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnAnterior(sender: System.Object; e: wx.Event);
begin
  if registroAnterior() then
    InformaLimpaDados(true);
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnProximo(sender: System.Object; e: wx.Event);
begin
  if registroProximo() then
    InformaLimpaDados(true);
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnSalvar(sender: System.Object; e: wx.Event);
begin
  if SalvarDados(ValidaDados(true),
    ConsSQL.Endereco('S', edtCodigo.Value,'','','','',''),
    ConsSQL.Endereco('U', edtCodigo.Value, edtDescricao.Value, 
      edtBairro.Value, edtCEP.Value, edtCidade.Value,
      cmbEstado.StringSelection),
    ConsSQL.Endereco('I', edtCodigo.Value, edtDescricao.Value,
      edtBairro.Value, edtCEP.Value, edtCidade.Value,
      cmbEstado.StringSelection), true) then begin
    InformaLimpaDados(false);
    HabilitaDados(false);
  end;
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnExcluir(sender: System.Object; e: wx.Event);
begin
  if ExcluirDados(ValidaDados(false),
    ConsSQL.Endereco('D', edtCodigo.Value,'','','','','')) then begin
    InformaLimpaDados(false);
    HabilitaDados(false);
  end;
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnFechar(sender: System.Object; e: wx.Event);
begin
  self.Close(true);
  e.Skip();
end;

procedure TfrmCadEnderecos.OnBtnLimpar(sender: System.Object; e: wx.Event);
begin
  btnLimparClick();
  InformaLimpaDados(false);
  HabilitaDados(false);
  e.Skip();
end;

procedure TfrmCadEnderecos.InformaLimpaDados(bInformar: boolean);
begin
  inherited InformaLimpaDados(bInformar);

  if bInformar then begin
    edtBairro.Value := Campos[2].ToString();
    edtCEP.Value := Campos[3].ToString();
    edtCidade.Value := Campos[4].ToString();
    cmbEstado.StringSelection := Campos[5].ToString();
  end else begin
    edtBairro.Clear();
    edtCEP.Clear();
    edtCidade.Clear();
    cmbEstado.Selection := 0;
  end;
end;

procedure TfrmCadEnderecos.HabilitaDados(bHabilita: boolean);
begin
  inherited HabilitaDados(bHabilita);

  edtBairro.Enabled := bHabilita;
  edtCEP.Enabled := bHabilita;  
  edtCidade.Enabled := bHabilita;
  cmbEstado.Enabled := bHabilita;  
end;

procedure TfrmCadEnderecos.AdicionaCombo();
begin
  vsEstados[0] := Res.STR_PE;
  vsEstados[1] := Res.STR_AC;
  vsEstados[2] := Res.STR_AL;
  vsEstados[3] := Res.STR_AP;
  vsEstados[4] := Res.STR_AM;
  vsEstados[5] := Res.STR_BA;
  vsEstados[6] := Res.STR_BR;
  vsEstados[7] := Res.STR_CE;
  vsEstados[8] := Res.STR_DF;
  vsEstados[9] := Res.STR_ES;
  vsEstados[10] := Res.STR_GO;
  vsEstados[11] := Res.STR_MT;
  vsEstados[12] := Res.STR_MS;
  vsEstados[13] := Res.STR_MG;
  vsEstados[14] := Res.STR_PA;
  vsEstados[15] := Res.STR_PB;
  vsEstados[16] := Res.STR_PR;
  vsEstados[17] := Res.STR_SC;
  vsEstados[18] := Res.STR_RN;
  vsEstados[19] := Res.STR_RS;
  vsEstados[20] := Res.STR_RJ;
  vsEstados[21] := Res.STR_RO;
  vsEstados[22] := Res.STR_RR;
  vsEstados[23] := Res.STR_SP;
  vsEstados[24] := Res.STR_SE;
  vsEstados[25] := Res.STR_TO;
end;

end.
