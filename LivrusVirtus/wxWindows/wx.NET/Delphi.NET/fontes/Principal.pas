unit Principal;

interface

uses
  System.Drawing, System.Collections, wx;

type
  TfrmPrincipal = class(wx.MDIParentFrame)
  private
    mnuCadastros: wx.Menu;
    mnuPesquisas: wx.Menu;
    mnuVendas: wx.Menu;
    mnuOpcoes: wx.Menu;
    barraStatus: wx.StatusBar;
    nLarguras: array[0..1] of integer;
    procedure FazLayout();
    procedure OnClose(sender: System.Object; e: wx.Event);
    procedure OnMnuCadAssuntos(sender: System.Object; e: wx.Event);
    procedure OnMnuCadAutores(sender: System.Object; e: wx.Event);
    procedure OnMnuCadEditoras(sender: System.Object; e: wx.Event);
    procedure OnMnuCadEnderecos(sender: System.Object; e: wx.Event);
    procedure OnMnuCadIdiomas(sender: System.Object; e: wx.Event);
    procedure OnMnuCadPaises(sender: System.Object; e: wx.Event);
    procedure OnMnuCadProfissoes(sender: System.Object; e: wx.Event);
    procedure OnMnuCadClientes(sender: System.Object; e: wx.Event);
    procedure OnMnuCadLivros(sender: System.Object; e: wx.Event);
    procedure OnMnuConAssuntos(sender: System.Object; e: wx.Event);
    procedure OnMnuConAutores(sender: System.Object; e: wx.Event);
    procedure OnMnuConEditoras(sender: System.Object; e: wx.Event);
    procedure OnMnuConEnderecos(sender: System.Object; e: wx.Event);
    procedure OnMnuConIdiomas(sender: System.Object; e: wx.Event);
    procedure OnMnuConPaises(sender: System.Object; e: wx.Event);
    procedure OnMnuConProfissoes(sender: System.Object; e: wx.Event);
    procedure OnMnuConClientes(sender: System.Object; e: wx.Event);
    procedure OnMnuConLivros(sender: System.Object; e: wx.Event);
    procedure OnMnuVenderLivros(sender: System.Object; e: wx.Event);
    procedure OnMnuVendasRealizadas(sender: System.Object; e: wx.Event);
    procedure OnMnuAlterarSenha(sender: System.Object; e: wx.Event);
    procedure OnMnuSobre(sender: System.Object; e: wx.Event);
  public
    barraMenu: wx.MenuBar;
    barraFerra: wx.ToolBar;
    constructor Create;
  end;

var
  frmPrincipal: TfrmPrincipal;
  
  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmPrincipal))]

implementation

uses Filha, Sobre, Resource, ConAssuntos, ConAutores, ConClientes,
  ConEditoras, ConEnderecos, ConIdiomas, ConLivros, ConPaises,
  ConProfissoes;

constructor TfrmPrincipal.Create;
begin
  inherited Create( nil, -1, Res.STR_TITULO, 
    System.Drawing.Point.Create( -1, -1 ),  
    System.Drawing.Size.Create(640, 480));

  Icon := wx.Icon.Create('xpms/livrus.xpm');

  {Barra de Menu}
	mnuCadastros := wx.Menu.Create();
	mnuCadastros.Append(Res.MNU_CAD_ASSUNTOS, '&Assuntos', Res.STR_CADASSUNTO);
	mnuCadastros.Append(Res.MNU_CAD_AUTORES, 'A&utores', Res.STR_CADAUTOR);
	mnuCadastros.Append(Res.MNU_CAD_EDITORAS, '&Editoras', Res.STR_CADEDITORA);
	mnuCadastros.Append(Res.MNU_CAD_ENDERECOS, 'E&ndere�os', Res.STR_CADENDERECO);
	mnuCadastros.Append(Res.MNU_CAD_IDIOMAS, '&Idiomas', Res.STR_CADIDIOMA);
	mnuCadastros.Append(Res.MNU_CAD_PAISES, '&Pa�ses', Res.STR_CADPAIS);
	mnuCadastros.Append(Res.MNU_CAD_PROFISSOES, 'P&rofiss�es', Res.STR_CADPROFISS);
	mnuCadastros.AppendSeparator();
	mnuCadastros.Append(Res.MNU_CAD_CLIENTES, '&Clientes', Res.STR_CADCLIENTE);
	mnuCadastros.Append(Res.MNU_CAD_LIVROS, '&Livros', Res.STR_CADLIVRO);

	mnuPesquisas := wx.Menu.Create();
	mnuPesquisas.Append(Res.MNU_CON_ASSUNTOS, '&Assuntos', Res.STR_CONASSUNTO);
	mnuPesquisas.Append(Res.MNU_CON_AUTORES, 'A&utores', Res.STR_CONAUTOR);
	mnuPesquisas.Append(Res.MNU_CON_EDITORAS, '&Editoras', Res.STR_CONEDITORA);
	mnuPesquisas.Append(Res.MNU_CON_ENDERECOS, 'E&ndere�os', Res.STR_CONENDERECO);
	mnuPesquisas.Append(Res.MNU_CON_IDIOMAS, '&Idiomas', Res.STR_CONIDIOMA);
	mnuPesquisas.Append(Res.MNU_CON_PAISES, '&Pa�ses', Res.STR_CONPAIS);
	mnuPesquisas.Append(Res.MNU_CON_PROFISSOES, 'P&rofiss�es', Res.STR_CONPROFISS);
	mnuPesquisas.AppendSeparator();
	mnuPesquisas.Append(Res.MNU_CON_CLIENTES, '&Clientes', Res.STR_CONCLIENTE);
	mnuPesquisas.Append(Res.MNU_CON_LIVROS, '&Livros', Res.STR_CONLIVRO);

	mnuVendas := wx.Menu.Create();
	mnuVendas.Append(Res.MNU_VEN_VENDERLIVROS, '&Vender Livros', Res.STR_VENLIVRO);
	mnuVendas.Append(Res.MNU_VEN_VENDASREALIZADAS, 'Vendas &Realizadas', Res.STR_CONVENLIVRO);

	mnuOpcoes := wx.Menu.Create();
	mnuOpcoes.Append(Res.MNU_OP_ALTERARSENHA, '&Alterar Senha', Res.STR_ALTSENHA);
	mnuOpcoes.AppendSeparator();
	mnuOpcoes.Append(Res.MNU_OP_SOBRE, '&Sobre', Res.STR_OPSOBRE);
	mnuOpcoes.Append(Res.MNU_OP_SAIR, 'Sa&ir'+chr(9)+'Ctrl-S', Res.STR_OPSAIR);

	barraMenu := wx.MenuBar.Create();
	barraMenu.Append(mnuCadastros, '&Cadastros');
	barraMenu.Append(mnuPesquisas, '&Pesquisas');
	barraMenu.Append(mnuVendas, '&Vendas');
	barraMenu.Append(mnuOpcoes, '&Op��es');

	MenuBar := barraMenu; 

  {Barra de ferramentas}
  barraFerra := wx.ToolBar.Create(self, -1, wxDefaultPosition, wxDefaultSize, 
    wx.ToolBar.wxTB_HORIZONTAL or wx.ToolBar.wxNO_BORDER);
  ToolBar := barraFerra;
  barraFerra.AddTool(Res.MNU_CAD_CLIENTES, '', 
    wx.Bitmap.Create('xpms/cliente.xpm', wx.BitmapType.wxBITMAP_TYPE_XPM), 
    '', wx.ItemKind.wxITEM_NORMAL);
	barraFerra.AddTool(Res.MNU_CAD_LIVROS, '', 
    wx.Bitmap.Create('xpms/livro.xpm', wx.BitmapType.wxBITMAP_TYPE_XPM), 
    '', wx.ItemKind.wxITEM_NORMAL);
	barraFerra.AddTool(Res.MNU_VEN_VENDERLIVROS, '', 
    wx.Bitmap.Create('xpms/livros.xpm', wx.BitmapType.wxBITMAP_TYPE_XPM), 
    '', wx.ItemKind.wxITEM_NORMAL);
  barraFerra.AddSeparator();
	barraFerra.AddTool(Res.MNU_OP_SOBRE, '', 
    wx.Bitmap.Create('xpms/sobre.xpm', wx.BitmapType.wxBITMAP_TYPE_XPM), 
    '', wx.ItemKind.wxITEM_NORMAL);
	barraFerra.AddTool(Res.MNU_OP_SAIR, '', 
    wx.Bitmap.Create('xpms/sair.xpm', wx.BitmapType.wxBITMAP_TYPE_XPM), 
    '', wx.ItemKind.wxITEM_NORMAL);
  barraFerra.Realize();

  barraStatus := CreateStatusBar(2);
  StatusBarPane := 1;
  nLarguras[0] := 100;
  nLarguras[1] := -1;
  barraStatus.StatusWidths := nLarguras;
  barraStatus.SetStatusText(Res.STR_USUARIO, 0);

	FazLayout();

  EVT_MENU(Res.MNU_CAD_ASSUNTOS, OnMnuCadAssuntos );
  EVT_MENU(Res.MNU_CAD_AUTORES, OnMnuCadAutores );
  EVT_MENU(Res.MNU_CAD_EDITORAS, OnMnuCadEditoras );
  EVT_MENU(Res.MNU_CAD_ENDERECOS, OnMnuCadEnderecos );
  EVT_MENU(Res.MNU_CAD_IDIOMAS, OnMnuCadIdiomas );
  EVT_MENU(Res.MNU_CAD_PAISES, OnMnuCadPaises );
  EVT_MENU(Res.MNU_CAD_PROFISSOES, OnMnuCadProfissoes );
  EVT_MENU(Res.MNU_CAD_CLIENTES, OnMnuCadClientes );
  EVT_MENU(Res.MNU_CAD_LIVROS, OnMnuCadLivros );

  EVT_MENU(Res.MNU_CON_ASSUNTOS, OnMnuConAssuntos );
  EVT_MENU(Res.MNU_CON_AUTORES, OnMnuConAutores );
  EVT_MENU(Res.MNU_CON_EDITORAS, OnMnuConEditoras );
  EVT_MENU(Res.MNU_CON_ENDERECOS, OnMnuConEnderecos );
  EVT_MENU(Res.MNU_CON_IDIOMAS, OnMnuConIdiomas );
  EVT_MENU(Res.MNU_CON_PAISES, OnMnuConPaises );
  EVT_MENU(Res.MNU_CON_PROFISSOES, OnMnuConProfissoes );
  EVT_MENU(Res.MNU_CON_CLIENTES, OnMnuConClientes );
  EVT_MENU(Res.MNU_CON_LIVROS, OnMnuConLivros );

  EVT_MENU(Res.MNU_VEN_VENDERLIVROS, OnMnuVenderLivros );
  EVT_MENU(Res.MNU_VEN_VENDASREALIZADAS, OnMnuVendasRealizadas );

  EVT_MENU(Res.MNU_OP_ALTERARSENHA, OnMnuAlterarSenha );
  EVT_MENU(Res.MNU_OP_SOBRE, OnMnuSobre );
  EVT_MENU(Res.MNU_OP_SAIR, OnClose );

	EVT_CLOSE( OnClose );
end;

procedure TfrmPrincipal.FazLayout();
begin
  Layout();
  Centre();
end;

procedure TfrmPrincipal.OnClose(sender: System.Object; e: wx.Event);
var mens: wx.MessageDialog;
begin
  mens := wx.MessageDialog.Create(self, Res.STR_SAIRSIS, 'Confirma',
   wx.Dialog.wxNO_DEFAULT or wx.Dialog.wxYES_NO or wx.Dialog.wxICON_QUESTION);
  if mens.ShowModal() = wx.Dialog.wxID_YES then
    Destroy();
end;

procedure TfrmPrincipal.OnMnuCadAssuntos(sender: System.Object; e: wx.Event);
var fCadAssuntos: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_ASSUNTOS, false);
  fCadAssuntos := TfrmFilha.Create(self, Res.FRMCADASSUNTOS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadAutores(sender: System.Object; e: wx.Event);
var fCadAutores: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_AUTORES, false);
  fCadAutores := TfrmFilha.Create(self, Res.FRMCADAUTORES);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadEditoras(sender: System.Object; e: wx.Event);
var fCadEditoras: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_EDITORAS, false);
  fCadEditoras := TfrmFilha.Create(self, Res.FRMCADEDITORAS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadEnderecos(sender: System.Object; e: wx.Event);
var fCadEnderecos: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_ENDERECOS, false);
  fCadEnderecos := TfrmFilha.Create(self, Res.FRMCADENDERECOS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadIdiomas(sender: System.Object; e: wx.Event);
var fCadIdiomas: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_IDIOMAS, false);
  fCadIdiomas := TfrmFilha.Create(self, Res.FRMCADIDIOMAS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadPaises(sender: System.Object; e: wx.Event);
var fCadPaises: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_PAISES, false);
  fCadPaises := TfrmFilha.Create(self, Res.FRMCADPAISES);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadProfissoes(sender: System.Object; e: wx.Event);
var fCadProfissoes: TfrmFilha;
begin
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_PROFISSOES, false);
  fCadProfissoes := TfrmFilha.Create(self, Res.FRMCADPROFISSOES);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadClientes(sender: System.Object; e: wx.Event);
var fCadClientes: TfrmFilha;
begin
  barraFerra.EnableTool(Res.MNU_CAD_CLIENTES, false);
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_CLIENTES, false);
  fCadClientes := TfrmFilha.Create(self, Res.FRMCADCLIENTES);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuCadLivros(sender: System.Object; e: wx.Event);
var fCadLivros: TfrmFilha;
begin
  barraFerra.EnableTool(Res.MNU_CAD_LIVROS, false);
  barraMenu.GetMenu(0).Enable(Res.MNU_CAD_LIVROS, false);
  fCadLivros := TfrmFilha.Create(self, Res.FRMCADLIVROS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuConAssuntos(sender: System.Object; e: wx.Event);
var fConAssuntos: TfrmConAssuntos;
begin
  self.StatusBar.SetStatusText(Res.STR_CONASSUNTO,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_ASSUNTOS, false);
  fConAssuntos := TfrmConAssuntos.Create(self);
  fConAssuntos.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConAutores(sender: System.Object; e: wx.Event);
var fConAutores: TfrmConAutores;
begin
  self.StatusBar.SetStatusText(Res.STR_CONAUTOR,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_AUTORES, false);
  fConAutores := TfrmConAutores.Create(self);
  fConAutores.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConEditoras(sender: System.Object; e: wx.Event);
var fConEditoras: TfrmConEditoras;
begin
  self.StatusBar.SetStatusText(Res.STR_CONEDITORA,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_EDITORAS, false);
  fConEditoras := TfrmConEditoras.Create(self);
  fConEditoras.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConEnderecos(sender: System.Object; e: wx.Event);
var fConEnderecos: TfrmConEnderecos;
begin
  self.StatusBar.SetStatusText(Res.STR_CONENDERECO,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_ENDERECOS, false);
  fConEnderecos := TfrmConEnderecos.Create(self);
  fConEnderecos.Show(true);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuConIdiomas(sender: System.Object; e: wx.Event);
var fConIdiomas: TfrmConIdiomas;
begin
  self.StatusBar.SetStatusText(Res.STR_CONIDIOMA,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_IDIOMAS, false);
  fConIdiomas := TfrmConIdiomas.Create(self);
  fConIdiomas.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConPaises(sender: System.Object; e: wx.Event);
var fConPaises: TfrmConPaises;
begin
  self.StatusBar.SetStatusText(Res.STR_CONPAIS,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_PAISES, false);
  fConPaises := TfrmConPaises.Create(self);
  fConPaises.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConProfissoes(sender: System.Object; e: wx.Event);
var fConProfissoes: TfrmConProfissoes;
begin
  self.StatusBar.SetStatusText(Res.STR_CONPROFISS,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_PROFISSOES, false);
  fConProfissoes := TfrmConProfissoes.Create(self);
  fConProfissoes.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConClientes(sender: System.Object; e: wx.Event);
var fConClientes: TfrmConClientes;
begin
  self.StatusBar.SetStatusText(Res.STR_CONCLIENTE,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_CLIENTES, false);
  fConClientes := TfrmConClientes.Create(self);
  fConClientes.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuConLivros(sender: System.Object; e: wx.Event);
var fConLivros: TfrmConLivros;
begin
  self.StatusBar.SetStatusText(Res.STR_CONLIVRO,1);
  barraMenu.GetMenu(1).Enable(Res.MNU_CON_LIVROS, false);
  fConLivros := TfrmConLivros.Create(self);
  fConLivros.Show(true);
	e.Skip();
end;

procedure TfrmPrincipal.OnMnuVenderLivros(sender: System.Object; e: wx.Event);
var fVenderLivros: TfrmFilha;
begin
  barraFerra.EnableTool(Res.MNU_VEN_VENDERLIVROS, false);
  barraMenu.GetMenu(2).Enable(Res.MNU_VEN_VENDERLIVROS, false);
  fVenderLivros := TfrmFilha.Create(self, Res.FRMVENDERLIVROS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuVendasRealizadas(sender: System.Object; e: wx.Event);
var fVendasRealizadas: TfrmFilha;
begin
  barraMenu.GetMenu(2).Enable(Res.MNU_VEN_VENDASREALIZADAS, false);
  fVendasRealizadas := TfrmFilha.Create(self, Res.FRMCONVENDAS);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuAlterarSenha(sender: System.Object; e: wx.Event);
var fAlterarSenha: TfrmFilha;
begin
  barraMenu.GetMenu(3).Enable(Res.MNU_OP_ALTERARSENHA, false);
  fAlterarSenha := TfrmFilha.Create(self, Res.FRMALTERARSENHA);
  e.Skip();
end;

procedure TfrmPrincipal.OnMnuSobre(sender: System.Object; e: wx.Event);
begin
  frmSobre := TfrmSobre.Create(self);
  frmSobre.ShowModal();
  e.Skip();
end;	

end.
