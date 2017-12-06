unit Resource;

interface

type
  TResource = class
  public
    FRMCADASSUNTOS, FRMCADAUTORES, FRMCADEDITORAS, FRMCADENDERECOS, 
    FRMCADIDIOMAS, FRMCADPAISES, FRMCADPROFISSOES, FRMCADCLIENTES,
    FRMCADLIVROS, FRMVENDERLIVROS, FRMCONVENDAS, FRMALTERARSENHA: integer;
  
    MNU_CAD_ASSUNTOS, MNU_CAD_AUTORES, MNU_CAD_EDITORAS, MNU_CAD_ENDERECOS,
    MNU_CAD_IDIOMAS, MNU_CAD_PAISES, MNU_CAD_PROFISSOES, MNU_CAD_CLIENTES,
    MNU_CAD_LIVROS, MNU_CON_ASSUNTOS, MNU_CON_AUTORES, MNU_CON_EDITORAS,
    MNU_CON_ENDERECOS, MNU_CON_IDIOMAS, MNU_CON_PAISES, MNU_CON_PROFISSOES,
    MNU_CON_CLIENTES, MNU_CON_LIVROS, MNU_VEN_VENDERLIVROS, 
    MNU_VEN_VENDASREALIZADAS, MNU_OP_ALTERARSENHA, MNU_OP_SOBRE, 
    MNU_OP_SAIR: integer;
  
    TLB_CADCLIENTES, TLB_CADLIVROS, TLB_VENDERLIVROS: integer;

    STR_TITULO, STR_APPEXEC, STR_NREGJAN, STR_SEMJAN, STR_NCONBANCO,
    STR_NALOCODBC, STR_CADASSUNTO, STR_CADAUTOR, STR_CADEDITORA,
    STR_CADENDERECO, STR_CADIDIOMA, STR_CADPAIS, STR_CADPROFISS, 
    STR_CADCLIENTE, STR_CADLIVRO, STR_CONASSUNTO, STR_CONAUTOR, STR_CONEDITORA,
    STR_CONENDERECO, STR_CONIDIOMA, STR_CONPAIS, STR_CONPROFISS, 
    STR_CONCLIENTE, STR_CONLIVRO, STR_VENLIVRO, STR_CONVENLIVRO, STR_ALTSENHA,
    STR_OPSOBRE, STR_OPSAIR, STR_SAIRSIS, STR_EMAILNINF, STR_NCCRIADLG, 
    STR_CERTEXCL, STR_TELNINF, STR_NREGTELA, STR_NCCRIATELA, STR_NCPREPSQL,
    STR_NCEXECSQL, STR_DATINV, STR_SENALTSUC, STR_SENNCSU, STR_NSENNINF,
    STR_NSENNCCON, STR_DTHRINV, STR_USUARIO, STR_LOGSENINC, STR_ISBNNINF,
    STR_CODNINF, STR_ASSNENC, STR_ASSNINF, STR_AUTNENC, STR_AUTNINF, 
    STR_EDTNENC, STR_EDTNINF, STR_ENDNENC, STR_ENDNINF, STR_IDINENC, 
    STR_IDININF, STR_PAISNENC, STR_PAISNINF, STR_PROFNENC, STR_PROFNINF,
    STR_CLINENC, STR_CLININF, STR_LIVNENC, STR_LIVNINF, STR_PE, STR_AC, STR_AL,
    STR_AP, STR_AM, STR_BA, STR_BR, STR_CE, STR_DF, STR_ES, STR_GO, STR_MT, 
    STR_MS, STR_MG, STR_PA, STR_PB, STR_PR, STR_SC, STR_RN, STR_RS, STR_RJ,
    STR_RO, STR_RR, STR_SP, STR_SE, STR_TO, STR_CPFNINF, STR_SEXNINF, 
    STR_CPFINV, STR_TITNINF, STR_ISBNINV, STR_NUMINV, STR_LIVVENNINF,
    STR_LIVNEST, STR_VENRESUC, STR_VENNENC, STR_BAIRRONINF, STR_CEPNINF,
    STR_CIDADENINF: string;
    constructor Create;
  end;

var
  Res: TResource;

implementation

constructor TResource.Create;
begin
  inherited Create;

  FRMCADASSUNTOS:=1000;
  FRMCADAUTORES	:=1001;
  FRMCADEDITORAS:=1002;
  FRMCADENDERECOS:=1003;
  FRMCADIDIOMAS	:=1004;
  FRMCADPAISES	:=1005;
  FRMCADPROFISSOES:=1006;
  FRMCADCLIENTES	:=1007;
  FRMCADLIVROS	 :=1008;
  FRMVENDERLIVROS:=1009;
  FRMCONVENDAS	 :=1010;
  FRMALTERARSENHA:=1111;

  MNU_CAD_ASSUNTOS:=2000;
  MNU_CAD_AUTORES:=2001;
  MNU_CAD_EDITORAS:=2002;
  MNU_CAD_ENDERECOS:=2003;
  MNU_CAD_IDIOMAS:=2004;
  MNU_CAD_PAISES:=2005;
  MNU_CAD_PROFISSOES:=2006;
  MNU_CAD_CLIENTES:=2007;
  MNU_CAD_LIVROS:=2008;
  MNU_CON_ASSUNTOS:=2009;
  MNU_CON_AUTORES:=2010;
  MNU_CON_EDITORAS:=2011;
  MNU_CON_ENDERECOS:=2012;
  MNU_CON_IDIOMAS:=2013;
  MNU_CON_PAISES:=2014;
  MNU_CON_PROFISSOES:=2015;
  MNU_CON_CLIENTES:=2016;
  MNU_CON_LIVROS:=2017;
  MNU_VEN_VENDERLIVROS:=2018;
  MNU_VEN_VENDASREALIZADAS:=2019;
  MNU_OP_ALTERARSENHA:=2020;
  MNU_OP_SOBRE:=2021;
  MNU_OP_SAIR:=2022;

  TLB_CADCLIENTES:=2023;
  TLB_CADLIVROS:=2024;
  TLB_VENDERLIVROS:=2025;

  STR_TITULO       :='Livrus Virtus';
  STR_APPEXEC      :='A aplicação já está sendo executada.';
  STR_NREGJAN      :='Não consigo registrar a janela principal.';
  STR_SEMJAN       :='Sem janela principal';
  STR_NCONBANCO    :='Não consigo conectar com o banco de dados!';
  STR_NALOCODBC  :='Não foi possível alocar um manuseador para o ambiente ODBC';
  STR_CADASSUNTO   :='Cadastro de Assuntos';
  STR_CADAUTOR     :='Cadastro de Autores';
  STR_CADEDITORA   :='Cadastro de Editoras';
  STR_CADENDERECO  :='Cadastro de Endereços';
  STR_CADIDIOMA    :='Cadastro de Idiomas';
  STR_CADPAIS      :='Cadastro de Países';
  STR_CADPROFISS   :='Cadastro de Profissões';
  STR_CADCLIENTE   :='Cadastro de Clientes';
  STR_CADLIVRO     :='Cadastro de Livros';
  STR_CONASSUNTO   :='Consulta de Assuntos';
  STR_CONAUTOR     :='Consulta de Autores';
  STR_CONEDITORA   :='Consulta de Editoras';
  STR_CONENDERECO  :='Consulta de Endereços';
  STR_CONIDIOMA    :='Consulta de Idiomas';
  STR_CONPAIS      :='Consulta de Países';
  STR_CONPROFISS   :='Consulta de Profissões';
  STR_CONCLIENTE   :='Consulta de Clientes';
  STR_CONLIVRO     :='Consulta de Livros';
  STR_VENLIVRO     :='Vender Livros';
  STR_CONVENLIVRO  :='Vendas Realizadas';
  STR_ALTSENHA     :='Alteração de Senha';
  STR_OPSOBRE      :='Sobre o Sistema';
  STR_OPSAIR       :='Sair do Sistema';  
  STR_SAIRSIS      :='Deseja sair do sistema?';
  STR_EMAILNINF    :='E-mail não informado!';
  STR_NCCRIADLG    :='Não consigo criar a dialog!';
  STR_CERTEXCL     :='Certeza de excluir?';
  STR_TELNINF      :='Telefone não informado!';
  STR_NREGTELA     :='Não consigo registrar a tela!';
  STR_NCCRIATELA   :='Não consigo criar a tela!';
  STR_NCPREPSQL    :='Não conseguiu preparar o SQL!';
  STR_NCEXECSQL    :='Não conseguiu executar o SQL!';
  STR_DATINV       :='Data inválida!';
  STR_SENALTSUC    :='Senha alterada com sucesso!';
  STR_SENNCSU      :='A Senha atual não confere com a senha do usuário!';
  STR_NSENNINF     :='Nova senha não informada!';
  STR_NSENNCCON    :='A Nova senha não confere com a senha a confirmar!';
  STR_DTHRINV      :='Data/Hora inválida!';
  STR_USUARIO      :='Usuário: ';
  STR_LOGSENINC    :='Login ou senha incorretos!';
  STR_ISBNNINF     :='ISBN não informado!';
  STR_CODNINF      :='Código não informado!';
  STR_ASSNENC      :='Assunto não encontrado!';
  STR_ASSNINF      :='Assunto não informado!';
  STR_AUTNENC      :='Autor não encontrado!';
  STR_AUTNINF      :='Autor não informado!';
  STR_EDTNENC      :='Editora não encontrada!';
  STR_EDTNINF      :='Editora não informada!';
  STR_ENDNENC      :='Endereço não encontrado!';
  STR_ENDNINF      :='Endereço não informado!';
  STR_IDINENC      :='Idioma não encontrado!';
  STR_IDININF      :='Idioma não informado!';
  STR_PAISNENC     :='País não encontrado!';
  STR_PAISNINF     :='País não informado!';
  STR_PROFNENC     :='Profissão não encontrada!';
  STR_PROFNINF     :='Profissão não informada!';
  STR_CLINENC      :='Cliente não encontrado!';
  STR_CLININF      :='Cliente não informado!';
  STR_LIVNENC      :='Livro não encontrado!';
  STR_LIVNINF      :='Livro não informado!';
  STR_PE           :='Pernambuco';
  STR_AC           :='Acre';
  STR_AL           :='Alagoas';
  STR_AP           :='Amapá';
  STR_AM           :='Amazonas';
  STR_BA           :='Bahia';
  STR_BR           :='Brasília';
  STR_CE           :='Ceará';
  STR_DF           :='Distrito Federal';
  STR_ES           :='Espírito Santo';
  STR_GO           :='Goiás';
  STR_MT           :='Mato Grosso';
  STR_MS           :='Mato Grosso do Sul';
  STR_MG           :='Minas Gerais';
  STR_PA           :='Pará';
  STR_PB           :='Paraíba';
  STR_PR           :='Paraná';
  STR_SC           :='Santa Catarina';
  STR_RN           :='Rio Grande do Norte';
  STR_RS           :='Rio Grande do Sul';
  STR_RJ           :='Rio de Janeiro';
  STR_RO           :='Rondônia';
  STR_RR           :='Roraima';
  STR_SP           :='São Paulo';
  STR_SE           :='Sergipe';
  STR_TO           :='Tocantins';
  STR_CPFNINF      :='CPF não informado!';
  STR_SEXNINF      :='Sexo não informado!';
  STR_CPFINV       :='CPF inválido!';
  STR_TITNINF      :='Título não informado!';
  STR_ISBNINV      :='ISBN inválido!';
  STR_NUMINV       :='Número inválido!';
  STR_LIVVENNINF   :='Livro(s) para vender não informado(s)!';
  STR_LIVNEST      :='Livro não existe no estoque!';
  STR_VENRESUC     :='Venda realizada com sucesso!';
  STR_VENNENC      :='Venda não encontrada!';
  STR_BAIRRONINF   :='Bairro não informado!';
  STR_CEPNINF      :='CEP não informado!';
  STR_CIDADENINF   :='Cidade não informada!';
end;

end.
