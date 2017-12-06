unit Principal;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Menus, ToolWin, ComCtrls, ImgList, Db, DBTables;

type
  TfrmPrincipal = class(TForm)
    MainMenu1: TMainMenu;
    Cadastros1: TMenuItem;
    Consultar1: TMenuItem;
    Vendas1: TMenuItem;
    Opes1: TMenuItem;
    Assuntos1: TMenuItem;
    Autores1: TMenuItem;
    Editoras1: TMenuItem;
    Enderecos1: TMenuItem;
    Idiomas1: TMenuItem;
    Paises1: TMenuItem;
    Profissoes1: TMenuItem;
    N1: TMenuItem;
    Livros1: TMenuItem;
    Clientes1: TMenuItem;
    Clientes2: TMenuItem;
    Livros2: TMenuItem;
    VenderLivros1: TMenuItem;
    AlterarSenha1: TMenuItem;
    Sobre1: TMenuItem;
    Sair1: TMenuItem;
    N2: TMenuItem;
    StatusBar1: TStatusBar;
    ToolBar1: TToolBar;
    ImageList1: TImageList;
    ToolButton1: TToolButton;
    ToolButton2: TToolButton;
    ToolButton3: TToolButton;
    ToolButton5: TToolButton;
    ToolButton6: TToolButton;
    ToolButton7: TToolButton;
    ImageList2: TImageList;
    Janelas1: TMenuItem;
    Horizontal1: TMenuItem;
    Vertical1: TMenuItem;
    Cascata1: TMenuItem;
    OrganizarIcones1: TMenuItem;
    db: TDatabase;
    Assuntos2: TMenuItem;
    Autores2: TMenuItem;
    Editoras2: TMenuItem;
    Enderecos2: TMenuItem;
    Idiomas2: TMenuItem;
    Paises2: TMenuItem;
    Profissoes2: TMenuItem;
    N3: TMenuItem;
    VendasRealizadas1: TMenuItem;
    procedure Sobre1Click(Sender: TObject);
    procedure Livros1Click(Sender: TObject);
    procedure Sair1Click(Sender: TObject);
    procedure Assuntos1Click(Sender: TObject);
    procedure Horizontal1Click(Sender: TObject);
    procedure Vertical1Click(Sender: TObject);
    procedure Cascata1Click(Sender: TObject);
    procedure OrganizarIcones1Click(Sender: TObject);
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure AlterarSenha1Click(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
    procedure Clientes1Click(Sender: TObject);
    procedure VenderLivros1Click(Sender: TObject);
    procedure Clientes2Click(Sender: TObject);
    procedure Livros2Click(Sender: TObject);
    procedure Autores1Click(Sender: TObject);
    procedure Editoras1Click(Sender: TObject);
    procedure Idiomas1Click(Sender: TObject);
    procedure Paises1Click(Sender: TObject);
    procedure Profissoes1Click(Sender: TObject);
    procedure Enderecos1Click(Sender: TObject);
    procedure Assuntos2Click(Sender: TObject);
    procedure Autores2Click(Sender: TObject);
    procedure Editoras2Click(Sender: TObject);
    procedure Enderecos2Click(Sender: TObject);
    procedure Idiomas2Click(Sender: TObject);
    procedure Paises2Click(Sender: TObject);
    procedure Profissoes2Click(Sender: TObject);
    procedure VendasRealizadas1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  frmPrincipal: TfrmPrincipal;

implementation

uses Sobre, AlterarSenha, Splash, Login, ConsultasSQL, RotinasGlobais,
  CadAssuntos, ConAssuntos, CadAutores, ConAutores, CadEditoras,
  ConEditoras, CadIdiomas, ConIdiomas, CadProfissoes, ConProfissoes,
  CadPaises, ConPaises, CadEnderecos, ConEnderecos, CadClientes,
  ConClientes, ConLivros, CadLivros, ConVendas, VenderLivros;

{$R *.DFM}

procedure TfrmPrincipal.Sobre1Click(Sender: TObject);
begin
 Application.CreateForm(TfrmSobre, frmSobre);
 frmSobre.ShowModal;
end;

procedure TfrmPrincipal.Livros1Click(Sender: TObject);
begin
 ToolButton2.Enabled:=false;
 Livros1.Enabled:=false;
 Application.CreateForm(TfrmCadLivros, frmCadLivros);
end;

procedure TfrmPrincipal.Sair1Click(Sender: TObject);
begin
Close;
end;

procedure TfrmPrincipal.Assuntos1Click(Sender: TObject);
begin
  Assuntos1.Enabled:=false;
  Application.CreateForm(TfrmCadAssuntos, frmCadAssuntos);
end;

procedure TfrmPrincipal.Horizontal1Click(Sender: TObject);
begin
  TileMode := tbHorizontal;
  Tile;
end;

procedure TfrmPrincipal.Vertical1Click(Sender: TObject);
begin
  TileMode := tbVertical;
  Tile;
end;

procedure TfrmPrincipal.Cascata1Click(Sender: TObject);
begin
Cascade;
end;

procedure TfrmPrincipal.OrganizarIcones1Click(Sender: TObject);
begin
ArrangeIcons;
end;

procedure TfrmPrincipal.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
 if MessageDlg('Deseja sair do sistema?', mtConfirmation,
    [mbYes, mbNo], 0) = mrYes then begin
    ConsSQL.Free;
    Rotinas.Free;
    db.close;
    Action := caFree;
  end else
    Action := caNone;
end;

procedure TfrmPrincipal.AlterarSenha1Click(Sender: TObject);
begin
  AlterarSenha1.Enabled:=false;
  Application.CreateForm(TfrmAlterarSenha, frmAlterarSenha);
end;

procedure TfrmPrincipal.FormShow(Sender: TObject);
begin
  db.Open;

  ConsSQL:=TConsultasSQL.Create;
  Rotinas:=TRotinasGlobais.Create;

  Application.CreateForm(TfrmSplash, frmSplash);
  frmSplash.ShowModal;

  Application.CreateForm(TfrmLogin, frmLogin);
  frmLogin.ShowModal;
end;

procedure TfrmPrincipal.FormMouseMove(Sender: TObject; Shift: TShiftState;
  X, Y: Integer);
begin
StatusBar1.Panels.Items[1].Text:='';
end;

procedure TfrmPrincipal.Clientes1Click(Sender: TObject);
begin
  ToolButton1.Enabled:=false;
  Clientes1.Enabled:=false;
  Application.CreateForm(TfrmCadClientes, frmCadClientes);
end;

procedure TfrmPrincipal.VenderLivros1Click(Sender: TObject);
begin
  ToolButton3.Enabled:=false;
  VenderLivros1.Enabled:=false;
  Application.CreateForm(TfrmVenderLivros, frmVenderLivros);
end;

procedure TfrmPrincipal.Clientes2Click(Sender: TObject);
begin
  Clientes2.Enabled:=false;
  Application.CreateForm(TfrmConClientes, frmConClientes);
  frmConClientes.show;
end;

procedure TfrmPrincipal.Livros2Click(Sender: TObject);
begin
  Livros2.Enabled:=false;
  Application.CreateForm(TfrmConLivros, frmConLivros);
  frmConLivros.show;
end;

procedure TfrmPrincipal.Autores1Click(Sender: TObject);
begin
  Autores1.Enabled:=false;
  Application.CreateForm(TfrmCadAutores, frmCadAutores);
end;

procedure TfrmPrincipal.Editoras1Click(Sender: TObject);
begin
  Editoras1.Enabled:=false;
  Application.CreateForm(TfrmCadEditoras, frmCadEditoras);
end;

procedure TfrmPrincipal.Idiomas1Click(Sender: TObject);
begin
  Idiomas1.Enabled:=false;
  Application.CreateForm(TfrmCadIdiomas, frmCadIdiomas);
end;

procedure TfrmPrincipal.Paises1Click(Sender: TObject);
begin
  Paises1.Enabled:=false;
  Application.CreateForm(TfrmCadPaises, frmCadPaises);
end;

procedure TfrmPrincipal.Profissoes1Click(Sender: TObject);
begin
  Profissoes1.Enabled:=false;
  Application.CreateForm(TfrmCadProfissoes, frmCadProfissoes);
end;

procedure TfrmPrincipal.Enderecos1Click(Sender: TObject);
begin
  Enderecos1.Enabled:=false;
  Application.CreateForm(TfrmCadEnderecos, frmCadEnderecos);
end;

procedure TfrmPrincipal.Assuntos2Click(Sender: TObject);
begin
  Assuntos2.Enabled:=false;
  Application.CreateForm(TfrmConAssuntos, frmConAssuntos);
  Rotinas.ChamarTela(TForm(frmConAssuntos));
end;

procedure TfrmPrincipal.Autores2Click(Sender: TObject);
begin
  Autores2.Enabled:=false;
  Application.CreateForm(TfrmConAutores, frmConAutores);
  Rotinas.ChamarTela(TForm(frmConAutores));
end;

procedure TfrmPrincipal.Editoras2Click(Sender: TObject);
begin
  Editoras2.Enabled:=false;
  Application.CreateForm(TfrmConEditoras, frmConEditoras);
  Rotinas.ChamarTela(TForm(frmConEditoras));
end;

procedure TfrmPrincipal.Enderecos2Click(Sender: TObject);
begin
  Enderecos2.Enabled:=false;
  Application.CreateForm(TfrmConEnderecos, frmConEnderecos);
  Rotinas.ChamarTela(TForm(frmConEnderecos));
end;

procedure TfrmPrincipal.Idiomas2Click(Sender: TObject);
begin
  Idiomas2.Enabled:=false;
  Application.CreateForm(TfrmConIdiomas, frmConIdiomas);
  Rotinas.ChamarTela(TForm(frmConIdiomas));
end;

procedure TfrmPrincipal.Paises2Click(Sender: TObject);
begin
  Paises2.Enabled:=false;
  Application.CreateForm(TfrmConPaises, frmConPaises);
  Rotinas.ChamarTela(TForm(frmConPaises));
end;

procedure TfrmPrincipal.Profissoes2Click(Sender: TObject);
begin
  Profissoes2.Enabled:=false;
  Application.CreateForm(TfrmConProfissoes, frmConProfissoes);
  Rotinas.ChamarTela(TForm(frmConProfissoes));
end;

procedure TfrmPrincipal.VendasRealizadas1Click(Sender: TObject);
begin
  VendasRealizadas1.Enabled:=false;
  Application.CreateForm(TfrmConVendas, frmConVendas);
  Rotinas.ChamarTela(TForm(frmConVendas));
end;

end.
