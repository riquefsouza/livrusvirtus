program Livrus;

uses
  QForms,
  Principal in 'Principal.pas' {frmPrincipal},
  ConsultasSQL in 'ConsultasSQL.pas',
  Sobre in 'Sobre.pas' {frmSobre},
  Splash in 'Splash.pas' {frmSplash},
  Login in 'Login.pas' {frmLogin},
  RotinasGlobais in 'RotinasGlobais.pas',
  AlterarSenha in 'AlterarSenha.pas' {frmAlterarSenha},
  Cadastros in 'Cadastros.pas' {frmCadastros},
  Consultas in 'Consultas.pas' {frmConsultas},
  CadAssuntos in 'CadAssuntos.pas' {frmCadAssuntos},
  ConAssuntos in 'ConAssuntos.pas' {frmConAssuntos},
  CadAutores in 'CadAutores.pas' {frmCadAutores},
  ConAutores in 'ConAutores.pas' {frmConAutores},
  CadEditoras in 'CadEditoras.pas' {frmCadEditoras},
  ConEditoras in 'ConEditoras.pas' {frmConEditoras},
  CadEnderecos in 'CadEnderecos.pas' {frmCadEnderecos},
  ConEnderecos in 'ConEnderecos.pas' {frmConEnderecos},
  CadIdiomas in 'CadIdiomas.pas' {frmCadIdiomas},
  ConIdiomas in 'ConIdiomas.pas' {frmConIdiomas},
  CadPaises in 'CadPaises.pas' {frmCadPaises},
  ConPaises in 'ConPaises.pas' {frmConPaises},
  CadProfissoes in 'CadProfissoes.pas' {frmCadProfissoes},
  ConProfissoes in 'ConProfissoes.pas' {frmConProfissoes},
  CadClientes in 'CadClientes.pas' {frmCadClientes},
  ConClientes in 'ConClientes.pas' {frmConClientes},
  CadLivros in 'CadLivros.pas' {frmCadLivros},
  ConLivros in 'ConLivros.pas' {frmConLivros},
  ConVendas in 'ConVendas.pas' {frmConVendas},
  VenderLivros in 'VenderLivros.pas' {frmVenderLivros};

{$R *.res}

begin
  Application.Initialize;
  Application.Title := 'Livrus Virtus';
  Application.CreateForm(TfrmPrincipal, frmPrincipal);
  Application.Run;
end.
