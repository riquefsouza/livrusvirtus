program Livrus;

{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.Drawing.dll'}
{%DelphiDotNetAssemblyCompiler 'c:\arquivos de programas\arquivos comuns\borland shared\bds\shared assemblies\2.0\Borland.Vcl.dll'}
{%DelphiDotNetAssemblyCompiler 'c:\arquivos de programas\arquivos comuns\borland shared\bds\shared assemblies\2.0\Borland.Delphi.dll'}
{%DelphiDotNetAssemblyCompiler 'c:\arquivos de programas\arquivos comuns\borland shared\bds\shared assemblies\2.0\Borland.VclRtl.dll'}
{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\Microsoft.NET\Framework\v1.1.4322\System.dll'}

uses
  Windows,
  Dialogs,
  Forms,
  Sobre in 'Sobre.pas' {frmSobre},
  Login in 'Login.pas' {frmLogin},
  Splash in 'Splash.pas' {frmSplash},
  AlterarSenha in 'AlterarSenha.pas' {frmAlterarSenha},
  ConsultasSQL in 'ConsultasSQL.pas',
  Principal in 'Principal.pas' {frmPrincipal},
  Cadastros in 'Cadastros.pas' {frmCadastros},
  RotinasGlobais in 'RotinasGlobais.pas',
  CadAssuntos in 'CadAssuntos.pas' {frmCadAssuntos},
  Consultas in 'Consultas.pas' {frmConsultas},
  ConAssuntos in 'ConAssuntos.pas' {frmConAssuntos},
  CadAutores in 'CadAutores.pas' {frmCadAutores},
  ConAutores in 'ConAutores.pas' {frmConAutores},
  CadEditoras in 'CadEditoras.pas' {frmCadEditoras},
  ConEditoras in 'ConEditoras.pas' {frmConEditoras},
  CadIdiomas in 'CadIdiomas.pas' {frmCadIdiomas},
  ConIdiomas in 'ConIdiomas.pas' {frmConIdiomas},
  CadProfissoes in 'CadProfissoes.pas' {frmCadProfissoes},
  ConProfissoes in 'ConProfissoes.pas' {frmConProfissoes},
  CadPaises in 'CadPaises.pas' {frmCadPaises},
  ConPaises in 'ConPaises.pas' {frmConPaises},
  CadEnderecos in 'CadEnderecos.pas' {frmCadEnderecos},
  ConEnderecos in 'ConEnderecos.pas' {frmConEnderecos},
  CadClientes in 'CadClientes.pas' {frmCadClientes},
  ConClientes in 'ConClientes.pas' {frmConClientes},
  ConLivros in 'ConLivros.pas' {frmConLivros},
  CadLivros in 'CadLivros.pas' {frmCadLivros},
  ConVendas in 'ConVendas.pas' {frmConVendas},
  VenderLivros in 'VenderLivros.pas' {frmVenderLivros};

{$R *.RES}

begin
//if FindWindow('TfrmPrincipal',nil)=0 then
// begin
  Application.Initialize;
  Application.Title := 'Livrus Virtus';
  Application.CreateForm(TfrmPrincipal, frmPrincipal);
  Application.Run;
// end
//else
//   ShowMessage('A Aplica��o j� est� sendo executada.');
end.
