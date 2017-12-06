unit AlterarSenha;

interface

uses
  System.Drawing, wx, System.Data.OleDb;

type
  TfrmAlterarSenha = class(wx.Panel)
  private
    labLogin: wx.StaticText;
    edtLogin: wx.TextCtrl;
    labSenhaAtual: wx.StaticText;
    edtSenhaAtual: wx.TextCtrl;
    labNovaSenha: wx.StaticText;
    edtNovaSenha: wx.TextCtrl;
    labConfirmarSenha: wx.StaticText;
    edtConfirmarSenha: wx.TextCtrl;
    btnSalvar: wx.Button;
    btnLimpar: wx.Button;
    btnFechar: wx.Button;
    procedure FazLayout();
  public
    constructor Create(parent: wx.Window);
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnBtnSalvarClick(sender: System.Object; e: wx.Event);
    procedure OnBtnLimparClick(sender: System.Object; e: wx.Event);
    procedure OnBtnFecharClick(sender: System.Object; e: wx.Event);
    function ValidaDados(): boolean;
  end;

var
  frmAlterarSenha: TfrmAlterarSenha;

const
  ID_FRMALTERARSENHA_BTNFECHAR: integer = 600;
  ID_FRMALTERARSENHA_BTNLIMPAR: integer = 601; 
  ID_FRMALTERARSENHA_BTNSALVAR: integer = 602;
  ID_FRMALTERARSENHA_EDTCONFIRMARSENHA: integer = 603;
  ID_FRMALTERARSENHA_EDTLOGIN: integer = 604;
  ID_FRMALTERARSENHA_EDTNOVASENHA: integer = 605;
  ID_FRMALTERARSENHA_EDTSENHAATUAL: integer = 606;
  ID_FRMALTERARSENHA_LABCONFIRMARSENHA: integer = 607;
  ID_FRMALTERARSENHA_LABLOGIN: integer = 608;
  ID_FRMALTERARSENHA_LABNOVASENHA: integer = 609;
  ID_FRMALTERARSENHA_LABSENHAATUAL: integer = 610;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmAlterarSenha))]

implementation

uses RotinasGlobais, ConsultasSQL, Resource;

constructor TfrmAlterarSenha.Create(parent: wx.Window);
begin
  inherited Create(parent, -1, System.Drawing.Point.Create(424, 292), 
    System.Drawing.Size.Create(257, 161), wxTAB_TRAVERSAL,'');

  ClientSize := System.Drawing.Size.Create(249, 134);
  EVT_CLOSE( OnClose );

	labLogin := wx.StaticText.Create(self, ID_FRMALTERARSENHA_LABLOGIN, 
    'Login: ', System.Drawing.Point.Create(8, 8), 
    System.Drawing.Size.Create(29, 13) );
	edtLogin := wx.TextCtrl.Create(self, ID_FRMALTERARSENHA_EDTLOGIN, '', 
    System.Drawing.Point.Create(8, 24), System.Drawing.Size.Create(100, 21) );
	edtLogin.Enable(false);
	labSenhaAtual := wx.StaticText.Create(self, ID_FRMALTERARSENHA_LABSENHAATUAL, 
    'Senha atual:', System.Drawing.Point.Create(112, 8),
    System.Drawing.Size.Create(60, 13) );
	edtSenhaAtual := wx.TextCtrl.Create(self, ID_FRMALTERARSENHA_EDTSENHAATUAL,
    '', System.Drawing.Point.Create(112, 24), 
    System.Drawing.Size.Create(100, 21), wx.TextCtrl.wxTE_PASSWORD );
	labNovaSenha := wx.StaticText.Create(self, ID_FRMALTERARSENHA_LABNOVASENHA, 
    'Nova Senha:', System.Drawing.Point.Create(8, 48), 
    System.Drawing.Size.Create(61, 13) );
	edtNovaSenha := wx.TextCtrl.Create(self, ID_FRMALTERARSENHA_EDTNOVASENHA,
    '', System.Drawing.Point.Create(8, 64), 
    System.Drawing.Size.Create(100, 21), wx.TextCtrl.wxTE_PASSWORD );
	labConfirmarSenha := wx.StaticText.Create(self, 
    ID_FRMALTERARSENHA_LABCONFIRMARSENHA, 'Confirmar senha:', 
    System.Drawing.Point.Create(112, 48), 
    System.Drawing.Size.Create(79, 13) );
	edtConfirmarSenha := wx.TextCtrl.Create(self, 
    ID_FRMALTERARSENHA_EDTCONFIRMARSENHA, '', 
    System.Drawing.Point.Create(112, 64), 
    System.Drawing.Size.Create(100, 21), wx.TextCtrl.wxTE_PASSWORD );
	btnSalvar := wx.Button.Create(self, ID_FRMALTERARSENHA_BTNSALVAR, 
    '&Salvar', System.Drawing.Point.Create(8, 104), 
    System.Drawing.Size.Create(75, 25));
	btnLimpar := wx.Button.Create(self, ID_FRMALTERARSENHA_BTNLIMPAR, 
    '&Limpar', System.Drawing.Point.Create(88, 104), 
    System.Drawing.Size.Create(75, 25));
	btnFechar := wx.Button.Create(self, ID_FRMALTERARSENHA_BTNFECHAR, 
    '&Fechar', System.Drawing.Point.Create(168, 104), 
    System.Drawing.Size.Create(75, 25));

  edtLogin.Value := Rotinas.sUsuarioLogin;
  edtSenhaAtual.MaxLength := 10;
  edtNovaSenha.MaxLength := 10;
  edtConfirmarSenha.MaxLength := 10;

  EVT_BUTTON(ID_FRMALTERARSENHA_BTNSALVAR, OnBtnSalvarClick );
  EVT_BUTTON(ID_FRMALTERARSENHA_BTNLIMPAR, OnBtnLimparClick );
  EVT_BUTTON(ID_FRMALTERARSENHA_BTNFECHAR, OnBtnFecharClick );

	FazLayout();
	edtSenhaAtual.SetFocus();
end;

procedure TfrmAlterarSenha.FazLayout();
var sizer_1, sizer_2, sizer_9: wx.BoxSizer;
  grid_sizer_3, grid_sizer_10: wx.GridSizer;
begin
  sizer_1 := wx.BoxSizer.Create(wx.Orientation.wxVERTICAL);
  sizer_2 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  sizer_9 := wx.BoxSizer.Create(wx.Orientation.wxHORIZONTAL);
  grid_sizer_10 := wx.GridSizer.Create(4, 1, 0, 0);
  grid_sizer_3 := wx.GridSizer.Create(4, 1, 0, 0);
  grid_sizer_3.Add(labLogin, 0, 
    wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 8);
  grid_sizer_3.Add(edtLogin, 0, wx.Direction.wxLEFT, 8);
  grid_sizer_3.Add(labNovaSenha, 0, 
    wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 8);
  grid_sizer_3.Add(edtNovaSenha, 0, wx.Direction.wxLEFT, 8);
  sizer_9.Add(grid_sizer_3, 0, 0, 0);
  grid_sizer_10.Add(labSenhaAtual, 0, 
    wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 4);
  grid_sizer_10.Add(edtSenhaAtual, 0, wx.Direction.wxLEFT, 4);
  grid_sizer_10.Add(labConfirmarSenha, 0, 
    wx.Direction.wxLEFT or wx.Alignment.wxALIGN_BOTTOM, 4);
  grid_sizer_10.Add(edtConfirmarSenha, 0, wx.Direction.wxLEFT, 4);
  sizer_9.Add(grid_sizer_10, 0, 0, 0);
  sizer_1.Add(sizer_9, 1, 0, 0);
  sizer_2.Add(btnSalvar, 0, wx.Direction.wxALL, 2);
  sizer_2.Add(btnLimpar, 0, wx.Direction.wxALL, 2);
  sizer_2.Add(btnFechar, 0, wx.Direction.wxALL, 2);
  sizer_1.Add(sizer_2, 0, wx.Direction.wxALL, 4);
  self.AutoLayout := true;
  self.SetSizer(sizer_1);
  sizer_1.Fit(self);
  sizer_1.SetSizeHints(self);
end;

procedure TfrmAlterarSenha.OnClose(sender: System.Object; e: wx.Event);
begin
  Destroy();
end;

procedure TfrmAlterarSenha.OnBtnSalvarClick(sender: System.Object; e: wx.Event);
var Arquiva: OleDbCommand;
begin
  Arquiva:= OleDbCommand.create;
  if ValidaDados() then begin
    if Rotinas.AtualizaDados(Arquiva, ConsSQL.Usuario('U',
      edtLogin.Value, edtConfirmarSenha.Value)) then begin
      MessageDialog.MessageBox(Res.STR_SENALTSUC, 'Erro', 
        Dialog.wxOK or Dialog.wxICON_ERROR );
    end;
  end;
  e.Skip();
end;

procedure TfrmAlterarSenha.OnBtnLimparClick(sender: System.Object; e: wx.Event);
begin
  edtSenhaAtual.Clear();
  edtNovaSenha.Clear();
  edtConfirmarSenha.Clear();
  edtSenhaAtual.SetFocus();
  e.Skip();
end;

procedure TfrmAlterarSenha.OnBtnFecharClick(sender: System.Object; e: wx.Event);
begin
  self.Parent.Close(true);
  e.Skip();
end;

function TfrmAlterarSenha.ValidaDados(): boolean;
begin
  result := true;
  if edtSenhaAtual.Value <> Rotinas.sUsuarioSenha then begin
    MessageDialog.MessageBox(Res.STR_SENNCSU, 'Erro',
      Dialog.wxOK or Dialog.wxICON_ERROR );
    result:=false;
  end;
  if Rotinas.ValidaCampo(edtNovaSenha.Value,
     Res.STR_NSENNINF) then begin
    result:=false;
  end;
  if edtNovaSenha.Value <> edtConfirmarSenha.Value then begin
    MessageDialog.MessageBox(Res.STR_NSENNCCON, 'Erro',
      Dialog.wxOK or Dialog.wxICON_ERROR );
    result:=false;
  end;
end;

end.
