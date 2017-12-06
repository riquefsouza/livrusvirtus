unit Cadastros;

interface

uses
  System.Drawing, wx, System.Collections, TextValidatorCtrl, System.Data.OleDb;

type
  TfrmCadastros = class(wx.Panel)
  private
    procedure FazLayout();
  protected
		Registros, Campos: ArrayList;
		nLinhaRegistro: integer;

		labCodigo: wx.StaticText;
		edtCodigo: TTextValidatorCtrl;
		labDescricao: wx.StaticText;
		edtDescricao: wx.TextCtrl;
		btnNovo: wx.Button;
		btnPesquisar: wx.Button;
		btnAnterior: wx.Button;
		btnProximo: wx.Button;
		btnFechar: wx.Button;
		btnLimpar: wx.Button;
		btnExcluir: wx.Button;
		btnSalvar: wx.Button;
		Arquiva: OleDbCommand;
    procedure IniciaBotoes();
    procedure InformaLimpaDados(bInformar: boolean); virtual;
    procedure HabilitaDados(bHabilita: boolean); virtual;
    procedure btnNovoClick();
    procedure NovoDado(sTextoSql: string);
    procedure btnLimparClick();
    function ExcluirDados(bValidaDados: boolean; sTextoSql: string): boolean;
    function PesquisarDados(sTextoSql, sMensagemErro: string): boolean;
    function registroAnterior(): boolean;
    function registroProximo(): boolean;
    function SalvarDados(bValidaDados: boolean; sTextoSql,
      sTextoUpdate, sTextoInsert: string; bLimparDados: boolean): boolean;
  public
    constructor Create(parent: wx.Window; nFiltroCodigo: integer;
      bIniciaBotoes: boolean; sLabCodigo, sLabDescricao: string);
  end;

const
  ID_FRMCADASTROS_BTNANTERIOR: integer = 400;
  ID_FRMCADASTROS_BTNEXCLUIR: integer = 401;
  ID_FRMCADASTROS_BTNFECHAR: integer = 402;
  ID_FRMCADASTROS_BTNLIMPAR: integer = 403;
  ID_FRMCADASTROS_BTNNOVO: integer = 404;
  ID_FRMCADASTROS_BTNPESQUISAR: integer = 405;
  ID_FRMCADASTROS_BTNPROXIMO: integer = 406;
  ID_FRMCADASTROS_BTNSALVAR: integer = 407;
  ID_FRMCADASTROS_EDTCODIGO: integer = 408;
  ID_FRMCADASTROS_EDTDESCRICAO: integer = 409;
  ID_FRMCADASTROS_LABCODIGO: integer = 410;
  ID_FRMCADASTROS_LABDESCRICAO: integer = 411;
  
  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmCadastros))]

implementation

uses Login, RotinasGlobais, Resource;

constructor TfrmCadastros.Create(parent: wx.Window; nFiltroCodigo: integer;
  bIniciaBotoes: boolean; sLabCodigo, sLabDescricao: string);
begin
  inherited Create( parent, -1, System.Drawing.Point.Create(0, 0),
    System.Drawing.Size.Create(330, 140));

  labCodigo := wx.StaticText.Create(self, ID_FRMCADASTROS_LABCODIGO,
    sLabCodigo, System.Drawing.Point.Create(8, 8),
    System.Drawing.Size.Create(36, 13), 0);
  edtCodigo := TTextValidatorCtrl.Create(self, ID_FRMCADASTROS_EDTCODIGO,
    '', System.Drawing.Point.Create(8, 24),
    System.Drawing.Size.Create(121, 21), 0, nFiltroCodigo);
  btnNovo := wx.Button.Create(self, ID_FRMCADASTROS_BTNNOVO,
  	'&Novo', System.Drawing.Point.Create(144, 24),
    System.Drawing.Size.Create(75, 25), 0);
  labDescricao := wx.StaticText.Create(self, ID_FRMCADASTROS_LABDESCRICAO,
    sLabDescricao, System.Drawing.Point.Create(8, 48),
    System.Drawing.Size.Create(51, 13), 0);
  edtDescricao := wx.TextCtrl.Create(self, ID_FRMCADASTROS_EDTDESCRICAO,
    '', System.Drawing.Point.Create(8, 64),
    System.Drawing.Size.Create(217, 21), 0);

  if bIniciaBotoes then begin
    IniciaBotoes();
    FazLayout();
  end;
  edtCodigo.MaxLength := 10;
  edtDescricao.MaxLength := 30;
  Registros := ArrayList.Create();
  nLinhaRegistro := 0;
end;

// Necess�rio por causa da tabula��o dos campos
procedure TfrmCadastros.IniciaBotoes();
begin
  btnPesquisar := wx.Button.Create(self, ID_FRMCADASTROS_BTNPESQUISAR,
    '&Pesquisar', System.Drawing.Point.Create(248, 8),
    System.Drawing.Size.Create(75, 25), 0);
  btnAnterior := wx.Button.Create(self, ID_FRMCADASTROS_BTNANTERIOR,
    '&Anterior', System.Drawing.Point.Create(248, 40),
    System.Drawing.Size.Create(75, 25), 0);
  btnProximo := wx.Button.Create(self, ID_FRMCADASTROS_BTNPROXIMO,
    'Pr�xi&mo', System.Drawing.Point.Create(248, 72),
    System.Drawing.Size.Create(75, 25), 0);
  btnSalvar := wx.Button.Create(self, ID_FRMCADASTROS_BTNSALVAR,
    '&Salvar', System.Drawing.Point.Create(8, 104),
    System.Drawing.Size.Create(75, 25), 0);
  btnExcluir := wx.Button.Create(self, ID_FRMCADASTROS_BTNEXCLUIR,
    '&Excluir', System.Drawing.Point.Create(88, 104),
    System.Drawing.Size.Create(75, 25), 0);
  btnLimpar := wx.Button.Create(self, ID_FRMCADASTROS_BTNLIMPAR,
    '&Limpar', System.Drawing.Point.Create(168, 104),
    System.Drawing.Size.Create(75, 25), 0);
  btnFechar := wx.Button.Create(self, ID_FRMCADASTROS_BTNFECHAR,
    '&Fechar', System.Drawing.Point.Create(248, 104),
    System.Drawing.Size.Create(75, 25), 0);

  btnLimparClick();
end;

procedure TfrmCadastros.FazLayout();
var sizer_1, sizer_2, sizer_3, sizer_4, sizer_5: wx.BoxSizer;
 grid_sizer_1, grid_sizer_2: wx.GridSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_3 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_4 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_5 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  grid_sizer_2 := wx.GridSizer.Create(2, 1, 0, 0);
  grid_sizer_1 := wx.GridSizer.Create(2, 2, 0, 1);
  grid_sizer_1.Add(labCodigo, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_1.Add(20, 10, 0, 0, 0);
  grid_sizer_1.Add(edtCodigo, 0, 0, 0);
  grid_sizer_1.Add(btnNovo, 0, wx.Direction.wxLEFT, 6);
  sizer_5.Add(grid_sizer_1, 0, 0, 0);
  grid_sizer_2.Add(labDescricao, 0, wx.Alignment.wxALIGN_BOTTOM, 0);
  grid_sizer_2.Add(edtDescricao, 0, 0, 2);
  sizer_5.Add(grid_sizer_2, 0, 0, 0);
  sizer_3.Add(sizer_5, 1, 0, 0);
  sizer_4.Add(btnPesquisar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_4.Add(btnAnterior, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_4.Add(btnProximo, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT, 2);
  sizer_3.Add(sizer_4, 0, wx.Alignment.wxALIGN_RIGHT, 0);
  sizer_1.Add(sizer_3, 1, wx.Direction.wxALL or wx.Stretch.wxEXPAND, 4);
  sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_2.Add(btnExcluir, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_2.Add(btnFechar, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 2);
  sizer_1.Add(sizer_2, 0, wx.Direction.wxALL or 
    wx.Alignment.wxALIGN_RIGHT or wx.Alignment.wxALIGN_BOTTOM, 4);
  AutoLayout := true;
  SetSizer(sizer_1);
  sizer_1.Fit(self);
  sizer_1.SetSizeHints(self);
end;

procedure TfrmCadastros.InformaLimpaDados(bInformar: boolean);
begin
	if bInformar then begin
	  Campos := ArrayList(Registros[nLinhaRegistro]);
	  edtCodigo.Value:=Campos[0].ToString();
	  edtDescricao.Value:=Campos[1].ToString();
	end else begin
	  edtCodigo.Clear();
	  edtDescricao.Clear();
	  edtCodigo.Enabled := true;
	  edtCodigo.SetFocus();
	end;
end;

procedure TfrmCadastros.HabilitaDados(bHabilita: boolean);
begin
	edtDescricao.Enabled := bHabilita;
end;

procedure TfrmCadastros.btnNovoClick();
begin
	btnSalvar.Enabled := true;
	btnExcluir.Enabled := false;
	btnPesquisar.Enabled := false;
	btnAnterior.Enabled := false;
	btnProximo.Enabled := false;
	btnNovo.Enabled := false;

  nLinhaRegistro := 0;
	InformaLimpaDados(false);
	HabilitaDados(true);
end;

procedure TfrmCadastros.NovoDado(sTextoSql: string);
begin
  if Rotinas.ConsultaDadosLista(Registros, sTextoSql) then begin
    Campos := ArrayList(Registros[0]);
    edtCodigo.Value := Campos[0].ToString();
    edtCodigo.Enabled := false;
    edtDescricao.SetFocus();
  end;
end;

procedure TfrmCadastros.btnLimparClick();
begin
	btnSalvar.Enabled := false;
	btnExcluir.Enabled := false;
	btnPesquisar.Enabled := true;
	btnAnterior.Enabled := false;
	btnProximo.Enabled := false;
	btnNovo.Enabled := true;

  nLinhaRegistro := 0;
	InformaLimpaDados(false);
	HabilitaDados(false);
end;

function TfrmCadastros.ExcluirDados(bValidaDados: boolean; 
  sTextoSql: string): boolean;
var bret: boolean;
begin
bret:=false;
  if bValidaDados then begin
    if wx.MessageDialog.MessageBox(Res.STR_CERTEXCL, 'Confirme',
     wx.Dialog.wxICON_QUESTION  or  wx.Dialog.wxYES_NO) =
     wx.Dialog.wxYES then begin
      if Rotinas.AtualizaDados(Arquiva, sTextoSql) then begin
        btnLimparClick();
        bret:=true;
      end;
    end;
  end;
  result:=bret;
end;

function TfrmCadastros.PesquisarDados(sTextoSql, 
  sMensagemErro: string): boolean;
var bret: boolean;
begin
	if length(edtCodigo.Value) = 0 then begin
	  btnAnterior.Enabled := true;
	  btnProximo.Enabled := true;
	end;

	if Rotinas.ConsultaDadosLista(Registros,sTextoSql) then begin
		 InformaLimpaDados(true);
		 HabilitaDados(true);

		 btnSalvar.Enabled := true;
		 btnExcluir.Enabled := true;
		 btnPesquisar.Enabled := false;
     bret:=true;
	end else begin
	  wx.MessageDialog.MessageBox(sMensagemErro, 'Erro',
      wx.Dialog.wxOK  or  wx.Dialog.wxICON_ERROR);
    bret:=false;
  end;

  result:=bret;
end;

function TfrmCadastros.registroAnterior(): boolean;
begin
	if nLinhaRegistro > 0 then begin
		nLinhaRegistro:=nLinhaRegistro - 1;
		InformaLimpaDados(true);
    result:=true;
  end else
    result:=false;
end;

function TfrmCadastros.registroProximo(): boolean;
begin
	if nLinhaRegistro < (Registros.Count-1) then begin
		nLinhaRegistro := nLinhaRegistro + 1;
		InformaLimpaDados(true);
    result:=true;
  end else
    result:=false;
end;

function TfrmCadastros.SalvarDados(bValidaDados: boolean; sTextoSql,
  sTextoUpdate, sTextoInsert: string; bLimparDados: boolean): boolean;
var Consulta: OleDbCommand;
  sArquiva: String;
  bret: boolean;
begin
  Consulta := OleDbCommand.Create();
  bret:=false;
	if bValidaDados then begin
	   if Rotinas.ConsultaDados(Consulta,sTextoSql) then
       sArquiva := sTextoUpdate
     else
  	   sArquiva := sTextoInsert;

     if Rotinas.AtualizaDados(Arquiva, sArquiva) then begin
  	   if bLimparDados then
         btnLimparClick();
       bret:=true;
     end;
	end;
  result:=bret;
end;

end.