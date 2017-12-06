program Livrus;

uses
  Forms,
  Rotinasg in 'ROTINASG.PAS',
  Constsql in 'CONSTSQL.PAS',
  Sobre in 'SOBRE.PAS' {frmSobre},
  Splash in 'SPLASH.PAS' {frmSplash},
  Login in 'LOGIN.PAS' {frmLogin},
  Altsenha in 'ALTSENHA.PAS' {frmAlterarSenha},
  Cadastro in 'CADASTRO.PAS' {frmCadastros},
  Consulta in 'CONSULTA.PAS' {frmConsultas},
  Principa in 'PRINCIPA.PAS' {frmPrincipal};

{$R *.RES}

begin
  Application.Title := 'Livrus Virtus';
  Application.CreateForm(TfrmPrincipal, frmPrincipal);
  Application.Run;
end.
