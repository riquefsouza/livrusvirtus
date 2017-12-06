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
  STR_APPEXEC      :='A aplica��o j� est� sendo executada.';
  STR_NREGJAN      :='N�o consigo registrar a janela principal.';
  STR_SEMJAN       :='Sem janela principal';
  STR_NCONBANCO    :='N�o consigo conectar com o banco de dados!';
  STR_NALOCODBC  :='N�o foi poss�vel alocar um manuseador para o ambiente ODBC';
  STR_CADASSUNTO   :='Cadastro de Assuntos';
  STR_CADAUTOR     :='Cadastro de Autores';
  STR_CADEDITORA   :='Cadastro de Editoras';
  STR_CADENDERECO  :='Cadastro de Endere�os';
  STR_CADIDIOMA    :='Cadastro de Idiomas';
  STR_CADPAIS      :='Cadastro de Pa�ses';
  STR_CADPROFISS   :='Cadastro de Profiss�es';
  STR_CADCLIENTE   :='Cadastro de Clientes';
  STR_CADLIVRO     :='Cadastro de Livros';
  STR_CONASSUNTO   :='Consulta de Assuntos';
  STR_CONAUTOR     :='Consulta de Autores';
  STR_CONEDITORA   :='Consulta de Editoras';
  STR_CONENDERECO  :='Consulta de Endere�os';
  STR_CONIDIOMA    :='Consulta de Idiomas';
  STR_CONPAIS      :='Consulta de Pa�ses';
  STR_CONPROFISS   :='Consulta de Profiss�es';
  STR_CONCLIENTE   :='Consulta de Clientes';
  STR_CONLIVRO     :='Consulta de Livros';
  STR_VENLIVRO     :='Vender Livros';
  STR_CONVENLIVRO  :='Vendas Realizadas';
  STR_ALTSENHA     :='Altera��o de Senha';
  STR_OPSOBRE      :='Sobre o Sistema';
  STR_OPSAIR       :='Sair do Sistema';  
  STR_SAIRSIS      :='Deseja sair do sistema?';
  STR_EMAILNINF    :='E-mail n�o informado!';
  STR_NCCRIADLG    :='N�o consigo criar a dialog!';
  STR_CERTEXCL     :='Certeza de excluir?';
  STR_TELNINF      :='Telefone n�o informado!';
  STR_NREGTELA     :='N�o consigo registrar a tela!';
  STR_NCCRIATELA   :='N�o consigo criar a tela!';
  STR_NCPREPSQL    :='N�o conseguiu preparar o SQL!';
  STR_NCEXECSQL    :='N�o conseguiu executar o SQL!';
  STR_DATINV       :='Data inv�lida!';
  STR_SENALTSUC    :='Senha alterada com sucesso!';
  STR_SENNCSU      :='A Senha atual n�o confere com a senha do usu�rio!';
  STR_NSENNINF     :='Nova senha n�o informada!';
  STR_NSENNCCON    :='A Nova senha n�o confere com a senha a confirmar!';
  STR_DTHRINV      :='Data/Hora inv�lida!';
  STR_USUARIO      :='Usu�rio: ';
  STR_LOGSENINC    :='Login ou senha incorretos!';
  STR_ISBNNINF     :='ISBN n�o informado!';
  STR_CODNINF      :='C�digo n�o informado!';
  STR_ASSNENC      :='Assunto n�o encontrado!';
  STR_ASSNINF      :='Assunto n�o informado!';
  STR_AUTNENC      :='Autor n�o encontrado!';
  STR_AUTNINF      :='Autor n�o informado!';
  STR_EDTNENC      :='Editora n�o encontrada!';
  STR_EDTNINF      :='Editora n�o informada!';
  STR_ENDNENC      :='Endere�o n�o encontrado!';
  STR_ENDNINF      :='Endere�o n�o informado!';
  STR_IDINENC      :='Idioma n�o encontrado!';
  STR_IDININF      :='Idioma n�o informado!';
  STR_PAISNENC     :='Pa�s n�o encontrado!';
  STR_PAISNINF     :='Pa�s n�o informado!';
  STR_PROFNENC     :='Profiss�o n�o encontrada!';
  STR_PROFNINF     :='Profiss�o n�o informada!';
  STR_CLINENC      :='Cliente n�o encontrado!';
  STR_CLININF      :='Cliente n�o informado!';
  STR_LIVNENC      :='Livro n�o encontrado!';
  STR_LIVNINF      :='Livro n�o informado!';
  STR_PE           :='Pernambuco';
  STR_AC           :='Acre';
  STR_AL           :='Alagoas';
  STR_AP           :='Amap�';
  STR_AM           :='Amazonas';
  STR_BA           :='Bahia';
  STR_BR           :='Bras�lia';
  STR_CE           :='Cear�';
  STR_DF           :='Distrito Federal';
  STR_ES           :='Esp�rito Santo';
  STR_GO           :='Goi�s';
  STR_MT           :='Mato Grosso';
  STR_MS           :='Mato Grosso do Sul';
  STR_MG           :='Minas Gerais';
  STR_PA           :='Par�';
  STR_PB           :='Para�ba';
  STR_PR           :='Paran�';
  STR_SC           :='Santa Catarina';
  STR_RN           :='Rio Grande do Norte';
  STR_RS           :='Rio Grande do Sul';
  STR_RJ           :='Rio de Janeiro';
  STR_RO           :='Rond�nia';
  STR_RR           :='Roraima';
  STR_SP           :='S�o Paulo';
  STR_SE           :='Sergipe';
  STR_TO           :='Tocantins';
  STR_CPFNINF      :='CPF n�o informado!';
  STR_SEXNINF      :='Sexo n�o informado!';
  STR_CPFINV       :='CPF inv�lido!';
  STR_TITNINF      :='T�tulo n�o informado!';
  STR_ISBNINV      :='ISBN inv�lido!';
  STR_NUMINV       :='N�mero inv�lido!';
  STR_LIVVENNINF   :='Livro(s) para vender n�o informado(s)!';
  STR_LIVNEST      :='Livro n�o existe no estoque!';
  STR_VENRESUC     :='Venda realizada com sucesso!';
  STR_VENNENC      :='Venda n�o encontrada!';
  STR_BAIRRONINF   :='Bairro n�o informado!';
  STR_CEPNINF      :='CEP n�o informado!';
  STR_CIDADENINF   :='Cidade n�o informada!';
end;

end.
