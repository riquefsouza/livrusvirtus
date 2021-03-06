program Livrus;

{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.dll'}
{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.Data.dll'}
{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.Drawing.dll'}
{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.Windows.Forms.dll'}
{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.XML.dll'}
{$R 'Principal.frmPrincipal.resources' 'Principal.resx'}
{%ConfigurationCompiler 'app.config'}
{%DelphiDotNetAssemblyCompiler 'c:\arquivos de programas\arquivos comuns\borland shared\bds\shared assemblies\2.0\Borland.Data.Provider.dll'}
{%DelphiDotNetAssemblyCompiler '$(SystemRoot)\microsoft.net\framework\v1.1.4322\System.Design.dll'}
{%DelphiDotNetAssemblyCompiler 'c:\arquivos de programas\arquivos comuns\borland shared\bds\shared assemblies\2.0\Borland.Data.Common.dll'}
{$R 'Splash.frmSplash.resources' 'Splash.resx'}
{$R 'Login.frmLogin.resources' 'Login.resx'}
{$R 'Sobre.frmSobre.resources' 'Sobre.resx'}
{$R 'AlterarSenha.frmAlterarSenha.resources' 'AlterarSenha.resx'}
{$R 'Cadastros.frmCadastros.resources' 'Cadastros.resx'}
{$R 'Consultas.frmConsultas.resources' 'Consultas.resx'}
{$R 'CadAssuntos.frmCadAssuntos.resources' 'CadAssuntos.resx'}
{$R 'ConAssuntos.frmConAssuntos.resources' 'ConAssuntos.resx'}
{$R 'CadAutores.frmCadAutores.resources' 'CadAutores.resx'}
{$R 'ConAutores.frmConAutores.resources' 'ConAutores.resx'}
{$R 'CadEditoras.frmCadEditoras.resources' 'CadEditoras.resx'}
{$R 'ConEditoras.frmConEditoras.resources' 'ConEditoras.resx'}
{$R 'CadEnderecos.frmCadEnderecos.resources' 'CadEnderecos.resx'}
{$R 'ConEnderecos.frmConEnderecos.resources' 'ConEnderecos.resx'}
{$R 'CadIdiomas.frmCadIdiomas.resources' 'CadIdiomas.resx'}
{$R 'ConIdiomas.frmConIdiomas.resources' 'ConIdiomas.resx'}
{$R 'CadPaises.frmCadPaises.resources' 'CadPaises.resx'}
{$R 'ConPaises.frmConPaises.resources' 'ConPaises.resx'}
{$R 'CadProfissoes.frmCadProfissoes.resources' 'CadProfissoes.resx'}
{$R 'ConProfissoes.frmConProfissoes.resources' 'ConProfissoes.resx'}
{$R 'CadClientes.frmCadClientes.resources' 'CadClientes.resx'}
{$R 'ConClientes.frmConClientes.resources' 'ConClientes.resx'}
{$R 'CadLivros.frmCadLivros.resources' 'CadLivros.resx'}
{$R 'ConLivros.frmConLivros.resources' 'ConLivros.resx'}
{$R 'ConVendas.frmConVendas.resources' 'ConVendas.resx'}
{$R 'VenderLivros.frmVenderLivros.resources' 'VenderLivros.resx'}

uses
  System.Reflection,
  System.Runtime.CompilerServices,
  System.Windows.Forms,
  System.Data,
  System.Data.OleDb,
  Principal in 'Principal.pas' {Principal.frmPrincipal: System.Windows.Forms.Form},
  Splash in 'Splash.pas' {Splash.frmSplash: System.Windows.Forms.Form},
  Login in 'Login.pas' {Login.frmLogin: System.Windows.Forms.Form},
  RotinasGlobais in 'RotinasGlobais.pas',
  ConsultasSQL in 'ConsultasSQL.pas',
  Sobre in 'Sobre.pas' {Sobre.frmSobre: System.Windows.Forms.Form},
  AlterarSenha in 'AlterarSenha.pas' {AlterarSenha.frmAlterarSenha: System.Windows.Forms.Form},
  Cadastros in 'Cadastros.pas' {Cadastros.frmCadastros: System.Windows.Forms.Form},
  Consultas in 'Consultas.pas' {Consultas.frmConsultas: System.Windows.Forms.Form},
  CadAssuntos in 'CadAssuntos.pas' {CadAssuntos.frmCadAssuntos: System.Windows.Forms.Form},
  ConAssuntos in 'ConAssuntos.pas' {ConAssuntos.frmConAssuntos: System.Windows.Forms.Form},
  CadAutores in 'CadAutores.pas' {CadAutores.frmCadAutores: System.Windows.Forms.Form},
  ConAutores in 'ConAutores.pas' {ConAutores.frmConAutores: System.Windows.Forms.Form},
  CadEditoras in 'CadEditoras.pas' {CadEditoras.frmCadEditoras: System.Windows.Forms.Form},
  ConEditoras in 'ConEditoras.pas' {ConEditoras.frmConEditoras: System.Windows.Forms.Form},
  CadEnderecos in 'CadEnderecos.pas' {CadEnderecos.frmCadEnderecos: System.Windows.Forms.Form},
  ConEnderecos in 'ConEnderecos.pas' {ConEnderecos.frmConEnderecos: System.Windows.Forms.Form},
  CadIdiomas in 'CadIdiomas.pas' {CadIdiomas.frmCadIdiomas: System.Windows.Forms.Form},
  ConIdiomas in 'ConIdiomas.pas' {ConIdiomas.frmConIdiomas: System.Windows.Forms.Form},
  CadPaises in 'CadPaises.pas' {CadPaises.frmCadPaises: System.Windows.Forms.Form},
  ConPaises in 'ConPaises.pas' {ConPaises.frmConPaises: System.Windows.Forms.Form},
  CadProfissoes in 'CadProfissoes.pas' {CadProfissoes.frmCadProfissoes: System.Windows.Forms.Form},
  ConProfissoes in 'ConProfissoes.pas' {ConProfissoes.frmConProfissoes: System.Windows.Forms.Form},
  CadClientes in 'CadClientes.pas' {CadClientes.frmCadClientes: System.Windows.Forms.Form},
  ConClientes in 'ConClientes.pas' {ConClientes.frmConClientes: System.Windows.Forms.Form},
  CadLivros in 'CadLivros.pas' {CadLivros.frmCadLivros: System.Windows.Forms.Form},
  ConLivros in 'ConLivros.pas' {ConLivros.frmConLivros: System.Windows.Forms.Form},
  ConVendas in 'ConVendas.pas' {ConVendas.frmConVendas: System.Windows.Forms.Form},
  VenderLivros in 'VenderLivros.pas' {VenderLivros.frmVenderLivros: System.Windows.Forms.Form};

{$R *.res}

{$REGION 'Program/Assembly Information'}
//
// General Information about an assembly is controlled through the following
// set of attributes. Change these attribute values to modify the information
// associated with an assembly.
//
[assembly: AssemblyDescription('')]
[assembly: AssemblyConfiguration('')]
[assembly: AssemblyCompany('')]
[assembly: AssemblyProduct('')]
[assembly: AssemblyCopyright('')]
[assembly: AssemblyTrademark('')]
[assembly: AssemblyCulture('')]

// The Delphi compiler controls the AssemblyTitleAttribute via the ExeDescription.
// You can set this in the IDE via the Project Options.
// Manually setting the AssemblyTitle attribute below will override the IDE
// setting.
// [assembly: AssemblyTitle('')]


//
// Version information for an assembly consists of the following four values:
//
//      Major Version
//      Minor Version 
//      Build Number
//      Revision
//
// You can specify all the values or you can default the Revision and Build Numbers 
// by using the '*' as shown below:

[assembly: AssemblyVersion('1.0.*')]

//
// In order to sign your assembly you must specify a key to use. Refer to the 
// Microsoft .NET Framework documentation for more information on assembly signing.
//
// Use the attributes below to control which key is used for signing. 
//
// Notes: 
//   (*) If no key is specified, the assembly is not signed.
//   (*) KeyName refers to a key that has been installed in the Crypto Service
//       Provider (CSP) on your machine. KeyFile refers to a file which contains
//       a key.
//   (*) If the KeyFile and the KeyName values are both specified, the 
//       following processing occurs:
//       (1) If the KeyName can be found in the CSP, that key is used.
//       (2) If the KeyName does not exist and the KeyFile does exist, the key 
//           in the KeyFile is installed into the CSP and used.
//   (*) In order to create a KeyFile, you can use the sn.exe (Strong Name) utility.
//       When specifying the KeyFile, the location of the KeyFile should be
//       relative to the project output directory. For example, if your KeyFile is
//       located in the project directory, you would specify the AssemblyKeyFile 
//       attribute as [assembly: AssemblyKeyFile('mykey.snk')], provided your output
//       directory is the project directory (the default).
//   (*) Delay Signing is an advanced option - see the Microsoft .NET Framework
//       documentation for more information on this.
//
[assembly: AssemblyDelaySign(false)]
[assembly: AssemblyKeyFile('')]
[assembly: AssemblyKeyName('')]
{$ENDREGION}

[STAThread]
begin
  if fPrincipal = nil then begin
    fPrincipal := frmPrincipal.Create;

    fPrincipal.db := OleDbConnection.Create;
    fPrincipal.db.ConnectionString :=
    'File Name=C:\LivrusVirtus\bancos\access\Access2k_Livrus.udl';

    Application.Run(fPrincipal);
  end else
    MessageBox.Show('A Aplica��o j� est� sendo executada.',
    'Livrus Virtus', MessageBoxButtons.OK);
end.
