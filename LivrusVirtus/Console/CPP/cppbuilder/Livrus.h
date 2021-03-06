#ifndef LIVRUS_H
#define LIVRUS_H

#include <string>

using std::string;

#include <fstream>

using std::fstream;
using std::ofstream;

#define ARQ_CRIA "wt+"
#define TAM_MAX_REG 145
#define TAM_MAX_STR 255

class Livrus {
public:
  string MSG_ERRO;
  bool bopcao;
  char opmenu;
  
  Livrus();
  virtual ~Livrus();

  void abrecriaArqs(bool bAbre);
  void fechaArqs();

  void frmSplash();
  bool frmLogin();
  void menu(int num);
  void usaMenu(int num);
private:
  /* Declara��o de tipos */
  struct regAssunto {
   string codigo; //[10];
   string assunto; //[30];
  };
  struct regAutor {
   string codigo; //[10];
   string autor; //[30];
  };
  struct regEditora {
   string codigo; //[10];
   string editora; //[50];
  };
  struct regIdioma {
   string codigo; //[10];
   string idioma; //[20];
  };
  struct regUsuario {
   string login; //[10];
   string senha; //[10];
  };
  struct regPais {
   string codigo; //[3];
   string pais; //[50];
  };
  struct regProfissao {
   string codigo; //[10];
   string profissao; //[50];
  };
  struct regLivro {
   string isbn; //[13];
   string titulo; //[50];
   string edicao; //[10];
   string anopubli; //[10];
   string codeditora; //[10];
   string volume; //[10];
   string codidioma; //[10];
   string npaginas; //[10];
   string preco; //[10];
   string qtdestoque; //[10];
  };
  struct regLivroAss {
   string isbn; //[13];
   string codassunto; //[10];
  };
  struct regLivroAut {
   string isbn; //[13];
   string codautor; //[10];
  };
  struct regCliente {
   string cpf; //[14];
   string nome; //[30];
   string email; //[30];
   string identidade; //[10];
   string sexo; //[1];
   string telefone; //[17];
   string dtnascimento; //[10];
   string codendereco; //[10];
   string codpais; //[3];
   string codprofissao; //[10];
  };
  struct regEndereco {
   string codigo; //[10];
   string logradouro; //[40];
   string bairro; //[15];
   string cep; //[8];
   string cidade; //[30];
   string estado; //[20];
  };
  struct regVenda {
   string dthrvenda; //[19];  /* data/hora da venda dd/mm/yyyy hh:mm:ss */
   string cpf; //[14];
   string isbn; //[13];
   string precovenda; //[10];
  };

  enum ctTipo { opTexto, opNumero, opData, opDataHora, opSenha };
  enum ctArqs { opAssunto, opAutor, opEditora, opEndereco, opIdioma, 
	  opPais, opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
		  opUsuario, opVenda };
  enum ctAcao { opNovo, opAlterar, opPesquisar, opSalvarInclusao,
	  opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos };

  string CRLF;
  int TAM_CRLF;
  int QTD_MAX_LINHA;  

  string MSG_ARQERRO;
  string MSG_OPCAO;
  string MSG_PRESS;

  string MSG_REGINC;
  string MSG_REGNINC;
  string MSG_REGALT;
  string MSG_REGNALT;
  string MSG_REGEXC;
  string MSG_REGNEXC;
  string MSG_REGEXST;

  string MSG_NUMINV;
  string MSG_DATAINV;
  string MSG_DTHRINV;
  string MSG_ISBNINV;
  string MSG_CPFINV;
  string MSG_SENCONFERE;
  string MSG_SENCONFIRM;
  string MSG_LOGINENCON;
  string MSG_SEMESTOQUE;

  string ARQ_ASSUNTO;
  string ARQ_AUTOR;
  string ARQ_EDITORA;
  string ARQ_IDIOMA;
  string ARQ_PAIS;
  string ARQ_PROFISSAO;
  string ARQ_LIVRO;
  string ARQ_LIVASS;
  string ARQ_LIVAUT;
  string ARQ_CLIENTE;
  string ARQ_ENDERECO;
  string ARQ_USUARIO;
  string ARQ_VENDA;

  int TAM_ASSUNTO;
  int TAM_AUTOR;
  int TAM_EDITORA;
  int TAM_IDIOMA;
  int TAM_USUARIO;
  int TAM_PAIS;
  int TAM_PROFISSAO;
  int TAM_LIVRO;
  int TAM_LIVASS;
  int TAM_LIVAUT;
  int TAM_CLIENTE;
  int TAM_ENDERECO;
  int TAM_VENDA;

  /* variaveis gerais */
  int g_nPosChave, g_nTamChave, g_nPosReg;
  double g_nPreco;
  bool g_SalvarInclusao;

  regAssunto tAssunto;
  regAutor tAutor;
  regEditora tEditora;
  regIdioma tIdioma;
  regEndereco tEndereco;
  regPais tPais;
  regProfissao tProfissao;
  regLivro tLivro;
  regLivroAss tLivroAss;
  regLivroAut tLivroAut;
  regCliente tCliente;
  regUsuario tUsuario;
  regVenda tVenda;

  fstream tfAssunto;
  fstream tfAutor;
  fstream tfEditora;
  fstream tfIdioma;
  fstream tfEndereco;
  fstream tfPais;
  fstream tfProfissao;
  fstream tfLivro;
  fstream tfLivroAss;
  fstream tfLivroAut;
  fstream tfCliente;
  fstream tfUsuario;
  fstream tfVenda;
  
  /*--- Rotinas b�sicas -----------------------------------------------------*/
  string copy(string str,int nini,int ntam);
  string trim(string sTexto);
  string repete(string sTexto, int nQtd);
  string esp(string sTexto, int nTam);
  bool strRelativa(string sTexto, string sChave);
  int modulo11(string svalor, int ndig);
  bool ValidaCPF(string cpf);
  bool ValidaISBN(string isbn);
  string digitaSenha(string sRotulo,int nTamSenha);
  string validaNumero(string sRotulo, string sNumero);
  string validaDataHora(string sRotulo, string sDataHora, bool bSoData);
  string retDataHora();
  
  /*--- Rotinas de manipula��o de arquivos ----------------------------------*/
  string pesqArq(fstream &sArq, string sChave, int nPosChave,
                 int nTamChave, int nTamLinha);
  void pesqLinhaExcluida(fstream &sArq, int nTamLinha);
  string pesqMaxCod(fstream &sArq, int nPosChave,
	int nTamChave, int nTamLinha);
  void escreveArq(fstream &sArq, string sTexto, string sMsgAcerto,
		string sMsgErro);

  /*--- Rotinas de implementa��o do sistema e de interface ------------------*/
  string LinhaReg(ctArqs sreg);
  int tamReg(ctArqs sreg);
  string rotulo(ctArqs sreg, int nNum);
  bool ContinuaSN(int nlinha, int nQtdLinha);
  bool ListarTodos(fstream &sArq, ctArqs sreg, string sChave,
    int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
    bool bPesqRelativa);
  void ListarRegLigados(fstream &sArq1, ctArqs sreg1, int nPosChave1,
  int nTamChave1, int nPosChave2, int nTamChave2, string sChave,
  fstream &sArq2, ctArqs sreg2, int nPosChave3, int nQtdLinha);
  string validaEntrada(fstream &sArq, ctArqs sreg, int nTexto,
  string sEntrada, int nTentativas, bool bPesqRelativa, ctTipo bTipoEntrada);
  void frmSobre();
  void frmCadastros(ctArqs sreg, ctAcao sacao);
  void frmConsultas(ctArqs sreg, ctAcao sacao);
  void frmAlterarSenha();
  void btnAcao(ctArqs sreg, ctAcao sacao);
  void subMenu(int nmenu, ctArqs sreg);
  void mostrarDados(ctArqs sreg, string slinha, int nOpcao);
  void mostrarSubDados(ctArqs sreg, ctArqs ssubreg, bool bSoMostrar);
  void frmCadLigados(ctArqs sreg, ctAcao sacao, string sCodigo);
  void ExcluirRegLigados(fstream &sArq, ctArqs sreg, int nPosChave,
       int nTamChave, string sChave); 
};

#endif
