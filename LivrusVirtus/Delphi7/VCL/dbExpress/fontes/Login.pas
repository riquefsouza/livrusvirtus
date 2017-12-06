unit Login;

interface

uses Windows, SysUtils, Classes, Graphics, Forms, Controls, StdCtrls,
  Buttons, ExtCtrls, Db, DBTables, Dialogs, FMTBcd, SqlExpr;

type
  TfrmLogin = class(TForm)
    Label1: TLabel;
    edtLogin: TEdit;
    BtnLogin: TButton;
    btnCancelar: TButton;
    edtSenha: TEdit;
    Label2: TLabel;
    Image1: TImage;
    Consulta: TSQLQuery;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure BtnLoginClick(Sender: TObject);
    procedure btnCancelarClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure edtSenhaKeyPress(Sender: TObject; var Key: Char);
  private
    { Private declarations }
    bFecharOuTerminar: boolean;
  public
    { Public declarations }
  end;

var
  frmLogin: TfrmLogin;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$R *.DFM}

procedure TfrmLogin.FormClose(Sender: TObject; var Action: TCloseAction);
begin
if bFecharOuTerminar then
  Action:=caFree
else
  Application.Terminate;
end;

procedure TfrmLogin.BtnLoginClick(Sender: TObject);
begin
if Rotinas.ConsultaDados(Consulta,
   ConsSql.Usuario('S',edtLogin.Text,edtSenha.Text)) then begin
 Rotinas.sUsuarioLogin:=edtLogin.Text;
 Rotinas.sUsuarioSenha:=edtSenha.Text;
 frmPrincipal.StatusBar1.Panels.Items[0].Text:='Usuário: '+edtLogin.Text;
 bFecharOuTerminar:=true;
 Close;
end else
 MessageDlg('Login ou senha incorretos!', mtInformation, [mbOk], 0);
end;

procedure TfrmLogin.btnCancelarClick(Sender: TObject);
begin
 bFecharOuTerminar:=false;
 Close;
end;

procedure TfrmLogin.FormShow(Sender: TObject);
begin
 bFecharOuTerminar:=false;
end;

procedure TfrmLogin.edtSenhaKeyPress(Sender: TObject; var Key: Char);
begin
end;

end.

