unit AlterarSenha;

interface

uses
  SysUtils, Types, Classes, Variants, QTypes, QGraphics, QControls, QForms,
  QDialogs, QStdCtrls, FMTBcd, DB, SqlExpr;

type
  TfrmAlterarSenha = class(TForm)
    btnSalvar: TButton;
    btnLimpar: TButton;
    btnFechar: TButton;
    edtLogin: TEdit;
    Label1: TLabel;
    Label2: TLabel;
    edtNovaSenha: TEdit;
    edtConfirmarSenha: TEdit;
    Label3: TLabel;
    Label4: TLabel;
    edtSenhaAtual: TEdit;
    Arquiva: TSQLQuery;
    procedure FormClose(Sender: TObject; var Action: TCloseAction);
    procedure btnFecharClick(Sender: TObject);
    procedure btnLimparClick(Sender: TObject);
    procedure btnSalvarClick(Sender: TObject);
    procedure FormShow(Sender: TObject);
    procedure FormMouseMove(Sender: TObject; Shift: TShiftState; X,
      Y: Integer);
  private
    { Private declarations }
    function ValidaDados: boolean;
  public
    { Public declarations }
  end;

var
  frmAlterarSenha: TfrmAlterarSenha;

implementation

uses Principal, ConsultasSQL, RotinasGlobais;

{$R *.xfm}

procedure TfrmAlterarSenha.FormClose(Sender: TObject;
  var Action: TCloseAction);
begin
frmPrincipal.AlterarSenha1.Enabled:=true;
Action:=caFree;
end;

procedure TfrmAlterarSenha.btnFecharClick(Sender: TObject);
begin
Close;
end;

procedure TfrmAlterarSenha.btnLimparClick(Sender: TObject);
begin
edtNovaSenha.Clear;
edtConfirmarSenha.Clear;
edtSenhaAtual.SetFocus;
end;


function TfrmAlterarSenha.ValidaDados: boolean;
begin
result:=true;
if Trim(edtSenhaAtual.Text) <> Trim(Rotinas.sUsuarioSenha) then begin
 MessageDlg('A Senha atual não confere com a senha do usuário!', mtError,
 [mbOk], 0);
 result:=false;
 exit;
end;
if Rotinas.ValidaCampo(edtNovaSenha.Text,
   'Nova senha não informada!') then begin
  result:=false;
  exit;
end;
if Trim(edtNovaSenha.Text) <> Trim(edtConfirmarSenha.Text) then begin
 MessageDlg('A Nova senha não confere com a senha a confirmar!', mtError,
 [mbOk], 0);
 result:=false;
 exit;
end;

end;

procedure TfrmAlterarSenha.btnSalvarClick(Sender: TObject);
begin
if ValidaDados then begin
Arquiva.Sql.Text:=ConsSQL.Usuario('U',Rotinas.sUsuarioLogin,
edtConfirmarSenha.Text);
Arquiva.ExecSQL;
Rotinas.sUsuarioSenha:=edtNovaSenha.Text;
MessageDlg('Senha alterada com sucesso!', mtInformation, [mbOk], 0);
end;
end;

procedure TfrmAlterarSenha.FormShow(Sender: TObject);
begin
edtLogin.Text:=Rotinas.sUsuarioLogin;
end;

procedure TfrmAlterarSenha.FormMouseMove(Sender: TObject;
  Shift: TShiftState; X, Y: Integer);
begin
  frmPrincipal.StatusBar1.Panels.Items[1].Text:=Caption;
end;

end.
