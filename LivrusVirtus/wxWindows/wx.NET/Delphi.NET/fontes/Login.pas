unit Login;

interface

uses
  System.Drawing, wx, System.Data.OleDb;

type
  TfrmLogin = class(wx.Dialog)
  private
    bmpLogin: wx.StaticBitmap;
    labLogin: wx.StaticText;
    edtLogin: wx.TextCtrl;
    labSenha: wx.StaticText;
    edtSenha: wx.TextCtrl;
    btnLogin: wx.Button;
    btnCancelar: wx.Button;
    bFechar: boolean;
    procedure FazLayout();
  public
    constructor Create(parent: wx.Window);
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnBtnLoginClick(sender: System.Object; e: wx.Event);
    procedure OnBtnCancelarClick(sender: System.Object; e: wx.Event);
  end;

var
  frmLogin: TfrmLogin;

const
  ID_FRMLOGIN_BMPLOGIN: integer = 200;
  ID_FRMLOGIN_LABLOGIN: integer = 201;
  ID_FRMLOGIN_EDTLOGIN: integer = 202; 
  ID_FRMLOGIN_LABSENHA: integer = 203;
  ID_FRMLOGIN_EDTSENHA: integer = 204;
  ID_FRMLOGIN_BTNLOGIN: integer = 205;
  ID_FRMLOGIN_BTNCANCELAR: integer = 206;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmLogin))]

implementation

uses Principal, RotinasGlobais, ConsultasSQL, Resource;

constructor TfrmLogin.Create(parent: wx.Window);
begin
  inherited Create(parent, -1, 'Login do Sistema', 
    System.Drawing.Point.Create(546, 346), 
    System.Drawing.Size.Create(211, 168), wxDEFAULT_DIALOG_STYLE,'');

  SetIcon(wx.Icon.create( 'xpms/livrus.xpm' ));
  Centre(wx.Orientation.wxBOTH);

  bmpLogin := wx.StaticBitmap.create(self, ID_FRMLOGIN_BMPLOGIN, 
    wx.Bitmap.create('xpms/login.xpm', wx.BitmapType.wxBITMAP_TYPE_XPM),
    System.Drawing.Point.Create(8, 8), System.Drawing.Size.Create(90, 90));
	labLogin := wx.StaticText.create(self, ID_FRMLOGIN_LABLOGIN, 
    'Login:', System.Drawing.Point.Create(112, 8),
    System.Drawing.Size.Create(29, 13) );
	edtLogin := wx.TextCtrl.create(self, ID_FRMLOGIN_EDTLOGIN, '',
    System.Drawing.Point.Create(112, 24), System.Drawing.Size.Create(80, 21) );
  edtLogin.MaxLength := 10;
	labSenha := wx.StaticText.create(self, ID_FRMLOGIN_LABSENHA,
    'Senha:', System.Drawing.Point.Create(112, 56),
    System.Drawing.Size.Create(34, 13) );
	edtSenha := wx.TextCtrl.create(self, ID_FRMLOGIN_EDTSENHA, '',
    System.Drawing.Point.Create(112, 72), System.Drawing.Size.Create(80, 21),
    wx.TextCtrl.wxTE_PASSWORD );
  edtSenha.MaxLength := 10;
	btnLogin := wx.Button.create(self, ID_FRMLOGIN_BTNLOGIN, '&Login',
    System.Drawing.Point.Create(24, 107), System.Drawing.Size.Create(75, 25));
	btnCancelar := wx.Button.create(self, ID_FRMLOGIN_BTNCANCELAR, '&Cancelar',
    System.Drawing.Point.Create(112, 107), System.Drawing.Size.Create(75, 25));
	btnLogin.SetDefault();

  bFechar := false;
  FazLayout();

	EVT_CLOSE( OnClose );
  EVT_BUTTON(ID_FRMLOGIN_BTNLOGIN, OnBtnLoginClick );
  EVT_BUTTON(ID_FRMLOGIN_BTNCANCELAR, OnBtnCancelarClick );
end;

procedure TfrmLogin.FazLayout();
var sizer_1, sizer_2, sizer_3, sizer_4: wx.BoxSizer;
begin
	sizer_1 := wx.BoxSizer.create(wx.Orientation.wxVERTICAL);
	sizer_4 := wx.BoxSizer.create(wx.Orientation.wxHORIZONTAL);
	sizer_2 := wx.BoxSizer.create(wx.Orientation.wxHORIZONTAL);
	sizer_3 := wx.BoxSizer.create(wx.Orientation.wxVERTICAL);
	sizer_2.Add(bmpLogin, 0, wx.Direction.wxALL, 6);
	sizer_3.Add(labLogin, 0, wx.Direction.wxALL or wx.Alignment.wxALIGN_BOTTOM, 2);
	sizer_3.Add(edtLogin, 0, wx.Direction.wxALL, 2);
	sizer_3.Add(labSenha, 0, wx.Direction.wxALL or wx.Alignment.wxALIGN_BOTTOM, 2);
	sizer_3.Add(edtSenha, 0, wx.Direction.wxALL, 2);
	sizer_2.Add(sizer_3, 0, wx.Direction.wxALL, 6);
	sizer_1.Add(sizer_2, 0, 0, 3);
	sizer_4.Add(btnLogin, 0, wx.Direction.wxLEFT or wx.Direction.wxTOP or 
    wx.Direction.wxBOTTOM or wx.Alignment.wxALIGN_BOTTOM, 10);
	sizer_4.Add(btnCancelar, 0, wx.Direction.wxALL or
    wx.Alignment.wxALIGN_BOTTOM, 10);
	sizer_1.Add(sizer_4, 0,
    wx.Direction.wxALL or wx.Alignment.wxALIGN_CENTER_HORIZONTAL, 1);
	self.SetSizer(sizer_1);
	sizer_1.Fit(self);
	sizer_1.SetSizeHints(self);
	self.Layout();
	self.Centre();
end;

procedure TfrmLogin.OnClose(sender: System.Object; e: wx.Event);
begin
  if bFechar then
    Destroy()
  else begin
    Destroy();
    frmPrincipal.Destroy();
  end
end;

procedure TfrmLogin.OnBtnLoginClick(sender: System.Object; e: wx.Event);
var Consulta: OleDbCommand;
begin
  Consulta:= OleDbCommand.create;
  Rotinas.sUsuarioLogin := edtLogin.Value;
  Rotinas.sUsuarioSenha := edtSenha.Value;

  if Rotinas.ConsultaDados(Consulta, ConsSQL.Usuario('S',
     Rotinas.sUsuarioLogin, Rotinas.sUsuarioSenha)) then begin
    Rotinas.sBarraLogin := Res.STR_USUARIO + Rotinas.sUsuarioLogin;
    frmPrincipal.SetStatusText(Rotinas.sBarraLogin, 0);
    bFechar := true;
    self.Close(true);
		frmPrincipal.Show( true );
  end else
    MessageDialog.MessageBox(Res.STR_LOGSENINC, 'Erro', 
      Dialog.wxOK or Dialog.wxICON_ERROR );

  e.Skip();
end;

procedure TfrmLogin.OnBtnCancelarClick(sender: System.Object; e: wx.Event);
begin
  bFechar := false;
  self.Close(true);
  e.Skip();
end;

end.
