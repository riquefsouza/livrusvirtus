#pragma once

//namespace Livrus
//{
  public __gc class Livrus: public System::Object
  {
  public:    
    /* Declaração de tipos */
  
    __gc struct regAssunto {
     String* codigo; //10
     String* assunto; //30
    };
    __gc struct regAutor {
     String* codigo; //10
     String* autor; //30
    };
    __gc struct regEditora {
     String* codigo; //10
     String* editora; //50
    };
    __gc struct regIdioma {
     String* codigo; //10
     String* idioma; //20
    };
    __gc struct regUsuario {
     String* login; //10
     String* senha; //10
    };
    __gc struct regPais {
     String* codigo; //3
     String* pais; //50
    };
    __gc struct regProfissao {
     String* codigo; //10
     String* profissao; //50
    };
    __gc struct regLivro {
     String* isbn; //13
     String* titulo; //50
     String* edicao; //10
     String* anopubli; //10
     String* codeditora; //10
     String* volume; //10
     String* codidioma; //10
     String* npaginas; //10
     String* preco; //10
     String* qtdestoque; //10
    };
    __gc struct regLivroAss {
     String* isbn; //13
     String* codassunto; //10
    };
    __gc struct regLivroAut {
     String* isbn; //13
     String* codautor; //10
    };
    __gc struct regCliente {
     String* cpf; //14
     String* nome; //30
     String* email; //30
     String* identidade; //10
     String* sexo; //1
     String* telefone; //17
     String* dtnascimento; //10
     String* codendereco; //10
     String* codpais; //3
     String* codprofissao; //10
    };
    __gc struct regEndereco {
     String* codigo; //10
     String* logradouro; //40
     String* bairro; //15
     String* cep; //8
     String* cidade; //30
     String* estado; //20
    };
    __gc struct regVenda {
     String* dthrvenda; //19  /* data/hora da venda dd/mm/yyyy hh:mm:ss */
     String* cpf; //14
     String* isbn; //13
     String* precovenda; //10
    };

    __value enum ctTipo { opTexto, opNumero, opData, opDataHora, opSenha };
    __value enum ctArqs { opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
  				opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
  				opUsuario, opVenda };
    __value enum ctAcao { opNovo, opAlterar, opPesquisar, opSalvarInclusao,
  			  opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos };
  
    static String* CRLF = S"\r\n"; /* windows */
    static int TAM_CRLF = 2;
    /* static String* CRLF = S"\n";
  	 static int TAM_CRLF = 1; */ /* unix */
    /* static String* CRLF = S"\r";
  	 static int TAM_CRLF = 1; */ /* macintosh */
  
    static int QTD_MAX_LINHA = 18;
    static int TAM_MAX_REG = 145;
  
    static String* MSG_ARQERRO = S"Erro: O arquivo não pode ser aberto.";
    static String* MSG_ERRO = S"Erro: opção inválida digite de novo.";
    static String* MSG_OPCAO = S"Escolha uma opção: ";
    static String* MSG_PRESS = S"pressione para continuar...";
  
    static String* MSG_REGINC = S"registro incluido!";
    static String* MSG_REGNINC = S"registro não incluido!";
    static String* MSG_REGALT = S"registro alterado!";
    static String* MSG_REGNALT = S"registro não alterado!";
    static String* MSG_REGEXC = S"registro excluido!";
    static String* MSG_REGNEXC = S"registro não excluido!";
    static String* MSG_REGEXST = S"registro já existe!";
  
    static String* MSG_NUMINV = S"Número inválido ou menor do que 1!";
    static String* MSG_DATAINV = S"Data inválida!, formato correto (dd/mm/yyyy)";
    static String* MSG_DTHRINV =
  				  "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)";
    static String* MSG_ISBNINV = S"ISBN inválido!";
    static String* MSG_CPFINV = S"CPF inválido!";
    static String* MSG_SENCONFERE = S"senha não confere com a senha atual!";
    static String* MSG_SENCONFIRM="nova senha não confere com a senha confirmada!";
    static String* MSG_LOGINENCON = S"login não encontrado!";
    static String* MSG_SEMESTOQUE = S"livro não existe no estoque!";
  
    static String* ARQ_ASSUNTO = S"assunto.dat";
    static String* ARQ_AUTOR = S"autor.dat";
    static String* ARQ_EDITORA = S"editora.dat";
    static String* ARQ_IDIOMA = S"idioma.dat";
    static String* ARQ_PAIS = S"pais.dat";
    static String* ARQ_PROFISSAO = S"profissao.dat";
    static String* ARQ_LIVRO = S"livro.dat";
    static String* ARQ_LIVASS = S"livroass.dat";
    static String* ARQ_LIVAUT = S"livroaut.dat";
    static String* ARQ_CLIENTE = S"cliente.dat";
    static String* ARQ_ENDERECO = S"endereco.dat";
    static String* ARQ_USUARIO = S"usuario.dat";
    static String* ARQ_VENDA = S"venda.dat";
  
    static int TAM_ASSUNTO = 40;
    static int TAM_AUTOR = 40;
    static int TAM_EDITORA = 60;
    static int TAM_IDIOMA = 30;
    static int TAM_USUARIO = 20;
    static int TAM_PAIS = 53;
    static int TAM_PROFISSAO = 60;
    static int TAM_LIVRO = 143;
    static int TAM_LIVASS = 23;
    static int TAM_LIVAUT = 23;
    static int TAM_CLIENTE = 135;
    static int TAM_ENDERECO = 123;
    static int TAM_VENDA = 56;
  
    /* variaveis gerais */
  
    Boolean bopcao;
    char opmenu;
    int g_nPosChave, g_nTamChave;
    double g_nPreco;
    Boolean g_SalvarInclusao;
  
    static regAssunto* tAssunto = new regAssunto;
    static regAutor* tAutor = new regAutor;
    static regEditora* tEditora = new regEditora;
    static regIdioma* tIdioma = new regIdioma;
    static regEndereco* tEndereco = new regEndereco;
    static regPais* tPais = new regPais;
    static regProfissao* tProfissao = new regProfissao;
    static regLivro* tLivro = new regLivro;
    static regLivroAss* tLivroAss = new regLivroAss;
    static regLivroAut* tLivroAut = new regLivroAut;
    static regCliente* tCliente = new regCliente;
    static regUsuario* tUsuario = new regUsuario;
    static regVenda* tVenda = new regVenda;
  
    FileStream* tfAssunto;
    FileStream* tfAutor;
    FileStream* tfEditora;
    FileStream* tfIdioma;
    FileStream* tfEndereco;
    FileStream* tfPais;
    FileStream* tfProfissao;
    FileStream* tfLivro;
    FileStream* tfLivroAss;
    FileStream* tfLivroAut;
    FileStream* tfCliente;
    FileStream* tfUsuario;
    FileStream* tfVenda;

    Void abrecriaArqs(Boolean bAbre);
    Void fechaArqs();
    Void frmSplash();
    Boolean frmLogin();
    Void menu(int num);
    Void usaMenu(int num);
  private:	
    String* copy(String* str,int nini,int ntam);
    String* repete(String* sTexto, int nQtd);
    String* esp(String* sTexto, int nTam);
    Boolean strRelativa(String* sTexto, String* sChave);
    int modulo11(String* svalor, int ndig);
    Boolean ValidaCPF(String* cpf);
    Boolean ValidaISBN(String* isbn);
    String* digitaSenha(String* sRotulo,int nTamSenha);
    String* validaNumero(String* sRotulo, String* sNumero);
    String* validaDataHora(String* sRotulo, String* sDataHora, Boolean bSoData);
    String* retDataHora();
    long tamArq(FileStream* sArq);
    Boolean fimArq(FileStream* sArq);
    String* lerArq(FileStream* sArq, int nTamLinha, int nTamCRLF);
    String* pesqArq(FileStream* sArq, String* sChave, int nPosChave,
		int nTamChave, int nTamLinha);
    Void pesqLinhaExcluida(FileStream* sArq, int nTamLinha);
    String* pesqMaxCod(FileStream* sArq, int nPosChave,
		int nTamChave, int nTamLinha);
    Void escreveArq(FileStream* sArq, String* sTexto, String* sMsgAcerto,
	String* sMsgErro);
    String* LinhaReg(ctArqs sreg);
    int tamReg(ctArqs sreg);
    String* rotulo(ctArqs sreg, int nNum);
    Boolean ContinuaSN(int nlinha, int nQtdLinha);
    Boolean ListarTodos(FileStream* sArq, ctArqs sreg, String* sChave,
	    int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
	    Boolean bPesqRelativa);
    Void ListarRegLigados(FileStream* sArq1, ctArqs sreg1, int nPosChave1,
    int nTamChave1, int nPosChave2, int nTamChave2, String* sChave,
    FileStream* sArq2, ctArqs sreg2, int nPosChave3, int nQtdLinha);
    String* validaEntrada(FileStream* sArq, ctArqs sreg, int nTexto,
	String* sEntrada, int nTentativas,
	Boolean bPesqRelativa, ctTipo bTipoEntrada);
    Void frmSobre();
    Void frmCadastros(ctArqs sreg, ctAcao sacao);
    Void frmConsultas(ctArqs sreg, ctAcao sacao);
    Void frmAlterarSenha();
    Void btnAcao(ctArqs sreg, ctAcao sacao);
    Void subMenu(int nmenu, ctArqs sreg);
    Void mostrarDados(ctArqs sreg, String* slinha, int nOpcao);
    Void mostrarSubDados(ctArqs sreg, ctArqs ssubreg, Boolean bSoMostrar);
    Void frmCadLigados(ctArqs sreg, ctAcao sacao, String* sCodigo);
    Void ExcluirRegLigados(FileStream* sArq, ctArqs sreg, int nPosChave,
	 int nTamChave, String* sChave);
  };
//}