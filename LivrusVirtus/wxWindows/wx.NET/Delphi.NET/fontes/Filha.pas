unit Filha;

interface

uses
  System.Drawing, wx, AlterarSenha, CadAssuntos, CadAutores, CadClientes,
  CadEditoras, CadEnderecos, CadIdiomas, CadLivros, CadPaises, CadProfissoes,
  ConVendas, VenderLivros;

type
  TfrmFilha = class(wx.MDIChildFrame)
  private
    nLocalTelaAtiva: integer;
    fCadAssuntos: TfrmCadAssuntos;
    fCadAutores: TfrmCadAutores;
    fCadEditoras: TfrmCadEditoras;
    fCadEnderecos: TfrmCadEnderecos;
    fCadIdiomas: TfrmCadIdiomas;
    fCadPaises: TfrmCadPaises;
    fCadProfissoes: TfrmCadProfissoes;
    fCadClientes: TfrmCadClientes;
    fCadLivros: TfrmCadLivros;
    fVenderLivros: TfrmVenderLivros;
    fConVendas: TfrmConVendas;
    fAlterarSenha: TfrmAlterarSenha;
  public
		s_title: string;
    atitle: string;
    constructor Create(parent: wx.MDIParentFrame; nTelaAtiva: integer );
    procedure OnActivate(sender: System.Object; e: wx.Event); override;
    procedure OnClose(sender: System.Object; e: wx.Event);
  end;

  [assembly: RuntimeRequiredAttribute(TypeOf(TfrmFilha))]

implementation

uses Principal, Resource;

constructor TfrmFilha.Create(parent: wx.MDIParentFrame; nTelaAtiva: integer );
begin
  inherited Create(parent, -1, 'Cadastro de ',System.Drawing.Point.Create(0, 0), 
    System.Drawing.Size.Create(342, 219), wxDEFAULT_FRAME_STYLE,'');

  ClientSize := System.Drawing.Size.Create(330, 136);
	Icon := wx.Icon.Create( 'xpms/livrus.xpm' );
	EVT_CLOSE( OnClose );
  nLocalTelaAtiva := nTelaAtiva;

  if nTelaAtiva = Res.FRMCADASSUNTOS then begin
    fCadAssuntos := TfrmCadAssuntos.Create(self);
    Title := Res.STR_CADASSUNTO;
  end else if nTelaAtiva = Res.FRMCADAUTORES then begin
    fCadAutores := TfrmCadAutores.Create(self);
    Title := Res.STR_CADAUTOR;
  end else if nTelaAtiva = Res.FRMCADEDITORAS then begin
    fCadEditoras := TfrmCadEditoras.Create(self);
    Title := Res.STR_CADEDITORA;
  end else if nTelaAtiva = Res.FRMCADENDERECOS then begin
    fCadEnderecos := TfrmCadEnderecos.Create(self);
    Title := Res.STR_CADENDERECO;
    ClientSize := System.Drawing.Size.Create(525, 170);
  end else if nTelaAtiva = Res.FRMCADIDIOMAS then begin
    fCadIdiomas := TfrmCadIdiomas.Create(self);
    Title := Res.STR_CADIDIOMA;
  end else if nTelaAtiva = Res.FRMCADPAISES then begin
    fCadPaises := TfrmCadPaises.Create(self);
    Title := Res.STR_CADPAIS;
  end else if nTelaAtiva = Res.FRMCADPROFISSOES then begin
    fCadProfissoes := TfrmCadProfissoes.Create(self);
    Title := Res.STR_CADPROFISS;
  end else if nTelaAtiva = Res.FRMCADCLIENTES then begin
    fCadClientes := TfrmCadClientes.Create(self);
    Title := Res.STR_CADCLIENTE;
    ClientSize := System.Drawing.Size.Create(525, 440);
  end else if nTelaAtiva = Res.FRMCADLIVROS then begin
    fCadLivros := TfrmCadLivros.Create(self);
    Title := Res.STR_CADLIVRO;
    ClientSize := System.Drawing.Size.Create(510, 385);
  end else if nTelaAtiva = Res.FRMVENDERLIVROS then begin
    fVenderLivros := TfrmVenderLivros.Create(self);
    Title := Res.STR_VENLIVRO;
    ClientSize := System.Drawing.Size.Create(480, 310);
  end else if nTelaAtiva = Res.FRMCONVENDAS then begin
    fConVendas := TfrmConVendas.Create(self);
    Title := Res.STR_CONVENLIVRO;
    ClientSize := System.Drawing.Size.Create(480, 330);
  end else if nTelaAtiva = Res.FRMALTERARSENHA then begin
    fAlterarSenha := TfrmAlterarSenha.Create(self);
    Title := Res.STR_ALTSENHA;
    ClientSize := System.Drawing.Size.Create(255, 134);
  end;		
end;

procedure TfrmFilha.OnActivate(sender: System.Object; e: wx.Event);
var ae: wx.ActivateEvent;
begin
	ae := wx.ActivateEvent(e);
	if ae.Active then begin
    if nLocalTelaAtiva = Res.FRMCADASSUNTOS then
      fCadAssuntos.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADAUTORES then
      fCadAutores.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADEDITORAS then
      fCadEditoras.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADENDERECOS then
      fCadEnderecos.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADIDIOMAS then
      fCadIdiomas.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADPAISES then
      fCadPaises.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADPROFISSOES then
      fCadProfissoes.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADCLIENTES then
      fCadClientes.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCADLIVROS then
      fCadLivros.SetFocus()
    else if nLocalTelaAtiva = Res.FRMVENDERLIVROS then
      fVenderLivros.SetFocus()
    else if nLocalTelaAtiva = Res.FRMCONVENDAS then
      fConVendas.SetFocus()
    else if nLocalTelaAtiva = Res.FRMALTERARSENHA then
      fAlterarSenha.SetFocus();
  end;
end;

procedure TfrmFilha.OnClose(sender: System.Object; e: wx.Event);
begin
  if nLocalTelaAtiva = Res.FRMCADASSUNTOS then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_ASSUNTOS, true)
  else if nLocalTelaAtiva = Res.FRMCADAUTORES then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_AUTORES, true)
  else if nLocalTelaAtiva = Res.FRMCADEDITORAS then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_EDITORAS, true)
  else if nLocalTelaAtiva = Res.FRMCADENDERECOS then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_ENDERECOS, true)
  else if nLocalTelaAtiva = Res.FRMCADIDIOMAS then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_IDIOMAS, true)
  else if nLocalTelaAtiva = Res.FRMCADPAISES then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_PAISES, true)
  else if nLocalTelaAtiva = Res.FRMCADPROFISSOES then
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_PROFISSOES, true)
  else if nLocalTelaAtiva = Res.FRMCADCLIENTES then begin
    frmPrincipal.barraFerra.EnableTool(Res.MNU_CAD_CLIENTES, true);
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_CLIENTES, true);
  end else if nLocalTelaAtiva = Res.FRMCADLIVROS then begin
    frmPrincipal.barraFerra.EnableTool(Res.MNU_CAD_LIVROS, true);
    frmPrincipal.barraMenu.GetMenu(0).enable(Res.MNU_CAD_LIVROS, true);
  end else if nLocalTelaAtiva = Res.FRMVENDERLIVROS then begin
    frmPrincipal.barraFerra.EnableTool(Res.MNU_VEN_VENDERLIVROS, true);
    frmPrincipal.barraMenu.GetMenu(2).enable(Res.MNU_VEN_VENDERLIVROS, true);
  end else if nLocalTelaAtiva = Res.FRMCONVENDAS then
    frmPrincipal.barraMenu.GetMenu(2).enable(Res.MNU_VEN_VENDASREALIZADAS, true)
  else if nLocalTelaAtiva = Res.FRMALTERARSENHA then begin
    frmPrincipal.barraMenu.GetMenu(3).enable(Res.MNU_OP_ALTERARSENHA, true);
  end;
  e.Skip();
end;

end.
