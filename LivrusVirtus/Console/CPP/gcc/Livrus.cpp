/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem C++.
------------------------------------------------------------------------------*/
/* programa Livrus */

#include "conio.h"
#include "time.h"
#include "livrus.h"

#include <cstdlib>
#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;

#include <exception>

using std::exception;

Livrus::Livrus() {
  CRLF = "\n"; /* windows */
  TAM_CRLF = 1;
  /* CRLF ="\n";
    TAM_CRLF = 1; */ /* unix */
  /* CRLF = "\r";
   TAM_CRLF = 1; */ /* macintosh */
  
  QTD_MAX_LINHA = 18;
  
  MSG_ARQERRO = "Erro: O arquivo não pode ser aberto.";
  MSG_ERRO = "Erro: opção inválida digite de novo.";
  MSG_OPCAO = "Escolha uma opção: ";
  MSG_PRESS = "pressione para continuar...";
  
  MSG_REGINC = "registro incluido!";
  MSG_REGNINC = "registro não incluido!";
  MSG_REGALT = "registro alterado!";
  MSG_REGNALT = "registro não alterado!";
  MSG_REGEXC = "registro excluido!";
  MSG_REGNEXC = "registro não excluido!";
  MSG_REGEXST = "registro já existe!";
  
  MSG_NUMINV = "Número inválido ou menor do que 1!";
  MSG_DATAINV = "Data inválida!, formato correto (dd/mm/yyyy)";
  MSG_DTHRINV = "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)";
  MSG_ISBNINV = "ISBN inválido!";
  MSG_CPFINV = "CPF inválido!";
  MSG_SENCONFERE = "senha não confere com a senha atual!";
  MSG_SENCONFIRM="nova senha não confere com a senha confirmada!";
  MSG_LOGINENCON = "login não encontrado!";
  MSG_SEMESTOQUE = "livro não existe no estoque!";
  
  ARQ_ASSUNTO = "assunto.dat";
  ARQ_AUTOR = "autor.dat";
  ARQ_EDITORA = "editora.dat";
  ARQ_IDIOMA = "idioma.dat";
  ARQ_USUARIO = "usuario.dat";
  ARQ_PAIS = "pais.dat";
  ARQ_PROFISSAO = "profissao.dat";
  ARQ_LIVRO = "livro.dat";
  ARQ_LIVASS = "livroass.dat";
  ARQ_LIVAUT = "livroaut.dat";
  ARQ_CLIENTE = "cliente.dat";
  ARQ_ENDERECO = "endereco.dat";
  ARQ_VENDA = "venda.dat";

  TAM_ASSUNTO = 40;
  TAM_AUTOR = 40;
  TAM_EDITORA = 60;
  TAM_IDIOMA = 30;
  TAM_USUARIO = 20;
  TAM_PAIS = 53;
  TAM_PROFISSAO = 60;
  TAM_LIVRO = 143;
  TAM_LIVASS = 23;
  TAM_LIVAUT = 23;
  TAM_CLIENTE = 135;
  TAM_ENDERECO = 123;
  TAM_VENDA = 56;
}

Livrus::~Livrus() {
}

/*------------------------------------------------------------------------------
Função que retorna um pedaço de uma string.
str - indica a string
nini - indica a posicao inicial do pedaco
ntam - indica o tamanho do pedaco
retorna - o pedaço da string
------------------------------------------------------------------------------*/
string Livrus::copy(string str,int nini,int ntam) {
  return str.substr(nini-1,ntam);
}
/*------------------------------------------------------------------------------
Retira os espaços em branco antes ou depois do texto.
sTexto - o texto a ser retirado os espaços em branco
retorna - o texto sem os espaços em branco
------------------------------------------------------------------------------*/
string Livrus::trim(string sTexto) {
int ncont, nPosIni, nPosFim;
string sret;
bool bQuebra;

nPosIni = 0;
nPosFim = 0;
ncont = 0;
bQuebra = false;
while ((ncont<=abs((int)sTexto.length())) && (bQuebra==false))  {
  if (sTexto.at(ncont)!=' ') {
     nPosIni = ncont + 1;
     bQuebra = true;
  }
  ncont++;
}
ncont = sTexto.length()-1;
bQuebra = false;
while ((ncont >= 0) && (bQuebra==false)) {
  if (sTexto.at(ncont)!=' ') {
     nPosFim = ncont + 1;
     bQuebra = true;
  }
  ncont--;
}
sret = copy(sTexto,nPosIni,(nPosFim-nPosIni)+1);
return(sret);
}
/*------------------------------------------------------------------------------
Repete um texto um número determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*/
string Livrus::repete(string sTexto, int nQtd){
int ncont;
string sret = "";

  for(ncont = 1; ncont <= nQtd; ncont++)
    sret = sret + sTexto;

  return sret;
}
/*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*/
string Livrus::esp(string sTexto, int nTam) {
string sret;

  sret = sTexto + repete(" ",nTam-sTexto.length());
  return sret;
}
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*/
bool Livrus::strRelativa(string sTexto, string sChave) {
  if (strstr(sTexto.c_str(),sChave.c_str())!=NULL)
    return true;
  else
    return false;
}
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a string com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*/
int Livrus::modulo11(string svalor, int ndig) {
int ncont, nsoma, nvalor, npos;
string slocal, sres;

 ncont=0;
 while (ncont < 11) {
   slocal=svalor.substr(ncont,1) + slocal;
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=2;
 else
   ncont=1;
 npos=2;
 while (ncont < 11) {
   sres = slocal.substr(ncont,1);
   nvalor = atoi(sres.c_str());
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   return 0;
 else
   return nsoma;
}
/*------------------------------------------------------------------------------
Validação de um número de CPF qualquer.
cpf - a mstring com o número do CPF
retorna - se é valido ou não
------------------------------------------------------------------------------*/
bool Livrus::ValidaCPF(string cpf) {
string scpf;
  
if (cpf.length()==14) {	
  scpf=cpf.substr(0,3) + cpf.substr(4,3)+cpf.substr(8,3)+cpf.substr(12,2);
  if ( (modulo11(scpf,1)==atoi(cpf.substr(12,1).c_str())) &&
  (modulo11(scpf,2)==atoi(cpf.substr(13,1).c_str())) )
    return true;
  else
  	return false;
} else
  return false;
}
/*------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a mstring com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------*/
bool Livrus::ValidaISBN(string isbn) {
 string sisbn, sdigito, snum;
 int nvalor, nsoma, ncont;

if (isbn.length()==13) {
  sdigito = isbn.substr(isbn.length()-1, 1);
  sisbn="";
  for(ncont = 0; ncont < abs(isbn.length()-1); ncont++)  {
    if (isbn.substr(ncont,1)!="-")
      sisbn = sisbn + isbn.substr(ncont,1);
  }
  if (sdigito=="X")
    nsoma = 10;
  else {
    nvalor = atoi(sdigito.c_str());
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = sisbn.substr(ncont-1, 1);
    nvalor = atoi(snum.c_str());
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    return true;
  else
    return false;
} else
  return false;
}
/*------------------------------------------------------------------------------
Esconde a digitação da senha
retorna - a senha digitada
------------------------------------------------------------------------------*/
string Livrus::digitaSenha(string sRotulo,int nTamSenha) {
string sSenha = "";
char sLetra;
int ncont;

cout << sRotulo;
//  cin >> sSenha;

ncont = 0;
sLetra = '\0';
while((sLetra!='\r') && (ncont < nTamSenha)) {
  sLetra = getch();
  if (sLetra!='\r') {
    sSenha = sSenha + sLetra;
  }
  ncont++;
}
cout << endl;

return sSenha;
}
/*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a string com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*/
string Livrus::validaNumero(string sRotulo, string sNumero) {
double nnum;
int nStatus;

nStatus = -1;
 while (nStatus!=0) {
  cout << sRotulo;
  cin >> sNumero;
  try {
	  nnum = atof(sNumero.c_str());
	  if (nnum < 0.01)
		 cerr << MSG_NUMINV << endl;
	  else
		 nStatus=0;
  } catch(exception e) {
	cerr << MSG_NUMINV << endl;
  }
}
return sNumero;
}
/*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a string com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
string Livrus::validaDataHora(string sRotulo, string sDataHora, bool bSoData) {
bool bvalida, bdatavalida, bhoravalida;
string sdia, smes, sano, shora, smin, sseg;
int ndia, nmes, nano, nhora, nmin, nseg, nudiames;
unsigned int ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;
while (bvalida==false) {
  cout << sRotulo;
  cin >> sDataHora; 
  if (sDataHora.length()==ntam) {
	sdia = copy(sDataHora,1,2);
	ndia = atoi(sdia.c_str());
	smes = copy(sDataHora,4,2);
	nmes = atoi(smes.c_str());
	sano = copy(sDataHora,7,4);
	nano = atoi(sano.c_str());

	if ((nano >= 1) && (nano <= 9999)) {
	  if ((nmes >= 1) && (nmes <= 31)) {
		  switch(nmes) {
		   case 1: case 3: case 5: case 7: case 8:
		   case 10: case 12: nudiames = 31; break;
		   case 2: {
			   /* ano bissexto */
               if ((nano % 4)==0) nudiames = 29;
               else nudiames = 28;
			  } break;
           case 4: case 6: case 9: case 11: nudiames = 30; break;
          }
		  if ((ndia >=1) && (ndia <=nudiames))
             bdatavalida = true;
      }
    }

    if (bSoData) {
	   if (bdatavalida)
		   bvalida = true;
       else
	   cerr << MSG_DATAINV << endl;
	} else {
	  if (bdatavalida) {
		  shora = copy(sDataHora,12,2);
		  nhora = atoi(shora.c_str());
		  smin = copy(sDataHora,15,2);
		  nmin = atoi(smin.c_str());
		  sseg = copy(sDataHora,18,2);
		  nseg = atoi(sseg.c_str());

		  if ((nhora >= 0) && (nhora <= 23)) {
			if ((nmin >= 0) && (nmin <= 59)) {
			  if ((nseg >= 0) && (nseg <= 59))
				 bhoravalida = true;
			}
		  }

		  if (bhoravalida)
		   bvalida = true;
		  else
		   cerr << MSG_DTHRINV << endl;
	  } else
        cerr << MSG_DTHRINV << endl;
    }
  } else {
	if (bSoData==true) cerr << MSG_DATAINV << endl;
	else cerr << MSG_DTHRINV << endl;
  }
}
return sDataHora;
}
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
string Livrus::retDataHora() {
string sret;
char sdatahora[TAM_MAX_STR];
time_t agora;
struct tm * tempo;

  time(&agora);
  tempo = localtime(&agora); 
  strftime(sdatahora, TAM_MAX_STR, "%d/%m/%Y %H:%M:%S", tempo);
  sret.assign(sdatahora);
  return(sret);
}
/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
void Livrus::abrecriaArqs(bool bAbre)
{
if (bAbre) {
  tfAssunto.open(ARQ_ASSUNTO.c_str(), ios::in | ios::out);
  if (!tfAssunto) {
    cerr << MSG_ARQERRO << " -->" << ARQ_ASSUNTO << endl;
    exit(1);
  }
  tfAutor.open(ARQ_AUTOR.c_str(), ios::in | ios::out);
  if (!tfAutor.is_open()) {
    cerr << MSG_ARQERRO << " -->" << ARQ_AUTOR << endl;
	exit(1);
  }
  tfEditora.open(ARQ_EDITORA.c_str(), ios::in | ios::out);
  if (!tfEditora.is_open()) {
    cerr << MSG_ARQERRO << " -->" << ARQ_EDITORA << endl;
	exit(1);
  }
  tfIdioma.open(ARQ_IDIOMA.c_str(), ios::in | ios::out);
  if (!tfIdioma.is_open()) {
    cerr << MSG_ARQERRO << " -->" << ARQ_IDIOMA << endl;
	exit(1);
  }
  tfEndereco.open(ARQ_ENDERECO.c_str(), ios::in | ios::out);
  if (!tfEndereco.is_open()) {
    cerr << MSG_ARQERRO << " -->" << ARQ_ENDERECO << endl;
	exit(1);
  }
  tfPais.open(ARQ_PAIS.c_str(), ios::in | ios::out);
  if (!tfPais.is_open()) { 
    cerr << MSG_ARQERRO << " -->" << ARQ_PAIS << endl;
	exit(1);
  }
  tfProfissao.open(ARQ_PROFISSAO.c_str(), ios::in | ios::out);
  if (!tfProfissao.is_open()) { 
    cerr << MSG_ARQERRO << " -->" << ARQ_PROFISSAO << endl;
	exit(1);
  }
  tfLivro.open(ARQ_LIVRO.c_str(), ios::in | ios::out);
  if (!tfLivro.is_open()) { 
    cerr << MSG_ARQERRO << " -->" << ARQ_LIVRO << endl;
	exit(1);
  }
  tfLivroAss.open(ARQ_LIVASS.c_str(), ios::in | ios::out);
  if (!tfLivroAss.is_open()) { 
    cerr << MSG_ARQERRO << " -->" << ARQ_LIVASS << endl;
	exit(1);
  }
  tfLivroAut.open(ARQ_LIVAUT.c_str(), ios::in | ios::out);
  if (!tfLivroAut.is_open()) { 
    cerr << MSG_ARQERRO << " -->" << ARQ_LIVAUT << endl;
	exit(1);
  }
  tfCliente.open(ARQ_CLIENTE.c_str(), ios::in | ios::out);
  if (!tfCliente.is_open()) {
    cerr << MSG_ARQERRO << " -->" << ARQ_CLIENTE << endl;
	exit(1);
  }
  tfUsuario.open(ARQ_USUARIO.c_str(), ios::in | ios::out);
  if (!tfUsuario.is_open()) { 
    cerr << MSG_ARQERRO << " -->" << ARQ_USUARIO << endl;
	exit(1);
  }
  tfVenda.open(ARQ_VENDA.c_str(), ios::in | ios::out);
  if (!tfVenda.is_open()) {
    cerr << MSG_ARQERRO << " -->" << ARQ_VENDA << endl;
	exit(1);
  }
} else {
  tfAssunto.open(ARQ_ASSUNTO.c_str(), ios::in | ios::out | ios::trunc);
  tfAutor.open(ARQ_AUTOR.c_str(), ios::in | ios::out | ios::trunc);
  tfEditora.open(ARQ_EDITORA.c_str(), ios::in | ios::out | ios::trunc);
  tfIdioma.open(ARQ_IDIOMA.c_str(), ios::in | ios::out | ios::trunc);
  tfEndereco.open(ARQ_ENDERECO.c_str(), ios::in | ios::out | ios::trunc);
  tfPais.open(ARQ_PAIS.c_str(), ios::in | ios::out | ios::trunc);
  tfProfissao.open(ARQ_PROFISSAO.c_str(), ios::in | ios::out | ios::trunc);
  tfLivro.open(ARQ_LIVRO.c_str(), ios::in | ios::out | ios::trunc);
  tfLivroAss.open(ARQ_LIVASS.c_str(), ios::in | ios::out | ios::trunc);
  tfLivroAut.open(ARQ_LIVAUT.c_str(), ios::in | ios::out | ios::trunc);
  tfCliente.open(ARQ_CLIENTE.c_str(), ios::in | ios::out | ios::trunc);
  tfUsuario.open(ARQ_USUARIO.c_str(), ios::in | ios::out | ios::trunc);
  tfVenda.open(ARQ_VENDA.c_str(), ios::in | ios::out | ios::trunc);
}
}
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
void Livrus::fechaArqs(void) {
 tfAssunto.close();
 tfAutor.close();
 tfEditora.close();
 tfIdioma.close();
 tfEndereco.close();
 tfPais.close();
 tfProfissao.close();
 tfLivro.close();
 tfLivroAss.close();
 tfLivroAut.close();
 tfCliente.close();
 tfUsuario.close();
 tfVenda.close();
}
/*------------------------------------------------------------------------------
Pesquisa um registro através de um valor chave num arquivo.
sArq - o arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o registro pesquisado
------------------------------------------------------------------------------*/
string Livrus::pesqArq(fstream &sArq, string sChave, int nPosChave,
		int nTamChave, int nTamLinha){
string sres, slocal = "";
char slinha[TAM_MAX_REG];
bool bQuebra;

bQuebra = false;
sArq.clear();
sArq.seekg(0);
while (!sArq.eof() && bQuebra == false) {
  sArq.read(slinha, nTamLinha + TAM_CRLF);
  slocal.assign(slinha);
  if (slocal!="") {
    sres = trim(copy(slocal, nPosChave, nTamChave));
    if (sres==sChave) {
      bQuebra = true;
    }
  }

}
g_nPosReg = sArq.tellg().operator long() - (nTamLinha + TAM_CRLF + 1);
if (sres!=sChave)
  return "";
else
  return copy(slocal, 1, nTamLinha);
}
/*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
void Livrus::pesqLinhaExcluida(fstream &sArq, int nTamLinha) {
string sExcluido;

  sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha);
/*if (sExcluido=="")
    sArq.seekp(0, ios::end); */
}
/*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*/
string Livrus::pesqMaxCod(fstream &sArq, int nPosChave,
		int nTamChave, int nTamLinha) {
string sres, slocal = "";
char slinha[TAM_MAX_REG];
char *resto;
bool bQuebra;
int nMaior, nCod;
long npos;

bQuebra = false;
nMaior = 0;
npos = 0;
sArq.clear();
sArq.seekg(0);
while (!sArq.eof() && bQuebra == false) {
  sArq.read(slinha, nTamLinha + TAM_CRLF);
  slocal.assign(slinha);
  if (slocal!="") {
    sres = trim(copy(slocal,nPosChave,nTamChave));
    nCod = strtol(sres.c_str(), &resto, 0);
    if (nCod > nMaior) {
       nMaior = nCod;
       npos = npos + 1; 
    }
  }
}
npos = npos * (nTamLinha + TAM_CRLF + 1);
pesqLinhaExcluida(sArq, nTamLinha);
nCod = (nMaior+1);
sres = itoa(nCod, resto, 10);
if (g_nPosReg < 0)
  g_nPosReg = npos;
return(sres);
}
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*/
void Livrus::escreveArq(fstream &sArq, string sTexto, string sMsgAcerto,
	string sMsgErro){
  try {
    sTexto = sTexto; // + CRLF;

    sArq.clear();
    if (g_nPosReg > 0)
      sArq.seekp(g_nPosReg);
    else
      sArq.seekp(0);

    sArq << sTexto << endl;
    cout << sMsgAcerto << endl;
  } catch(exception e) {
    cerr << sMsgErro << endl;
  }
}
/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
string Livrus::LinhaReg(ctArqs sreg) {
string slinha = "";

if (sreg==opAssunto) {
   slinha = esp(tAssunto.codigo,10)+esp(tAssunto.assunto,30);
} else if (sreg==opAutor)
   slinha = esp(tAutor.codigo,10)+esp(tAutor.autor,30);
else if (sreg==opEditora)
   slinha = esp(tEditora.codigo,10)+esp(tEditora.editora,50);
else if (sreg==opEndereco)
   slinha = esp(tEndereco.codigo,10)+esp(tEndereco.logradouro,40)+
   esp(tEndereco.bairro,15)+esp(tEndereco.cep,8)+
   esp(tEndereco.cidade,30)+esp(tEndereco.estado,20);
else if (sreg==opIdioma)
   slinha = esp(tIdioma.codigo,10)+esp(tIdioma.idioma,20);
else if (sreg==opPais)
   slinha = esp(tPais.codigo,3)+esp(tPais.pais,50);
else if (sreg==opProfissao)
   slinha = esp(tProfissao.codigo,10)+esp(tProfissao.profissao,50);
else if (sreg==opUsuario)
   slinha = esp(tUsuario.login,10)+esp(tUsuario.senha,10);
else if (sreg==opLivro)
   slinha = esp(tLivro.isbn,13)+esp(tLivro.titulo,50)+
   esp(tLivro.edicao,10)+esp(tLivro.anopubli,10)+esp(tLivro.codeditora,10)+
   esp(tLivro.volume,10)+esp(tLivro.codidioma,10)+esp(tLivro.npaginas,10)+
   esp(tLivro.preco,10)+esp(tLivro.qtdestoque,10);
else if (sreg==opLivroAss)
   slinha = esp(tLivroAss.isbn,13)+esp(tLivroAss.codassunto,10);
else if (sreg==opLivroAut)
   slinha = esp(tLivroAut.isbn,13)+esp(tLivroAut.codautor,10);
else if (sreg==opCliente)
   slinha = esp(tCliente.cpf,14)+esp(tCliente.nome,30)+
   esp(tCliente.email,30)+esp(tCliente.identidade,10)+esp(tCliente.sexo,1)+
   esp(tCliente.telefone,17)+esp(tCliente.dtnascimento,10)+
   esp(tCliente.codendereco,10)+esp(tCliente.codpais,3)+
   esp(tCliente.codprofissao,10);
else if (sreg==opVenda)
   slinha = esp(tVenda.dthrvenda,19)+esp(tVenda.cpf,14)+
   esp(tVenda.isbn,13)+esp(tVenda.precovenda,10);

return(slinha);
}
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
int Livrus::tamReg(ctArqs sreg) {
int nret = 0;

if (sreg==opAssunto) nret = TAM_ASSUNTO;
else if (sreg==opAutor) nret = TAM_AUTOR;
else if (sreg==opEditora) nret = TAM_EDITORA;
else if (sreg==opEndereco) nret = TAM_ENDERECO;
else if (sreg==opIdioma) nret = TAM_IDIOMA;
else if (sreg==opPais) nret = TAM_PAIS;
else if (sreg==opProfissao) nret = TAM_PROFISSAO;
else if (sreg==opUsuario) nret = TAM_USUARIO;
else if (sreg==opLivro) nret = TAM_LIVRO;
else if (sreg==opLivroAss) nret = TAM_LIVASS;
else if (sreg==opLivroAut) nret = TAM_LIVAUT;
else if (sreg==opCliente) nret = TAM_CLIENTE;
else if (sreg==opVenda) nret = TAM_VENDA;

return(nret);
}
/*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
string Livrus::rotulo(ctArqs sreg, int nNum) {
string sret = "";

if (sreg==opAssunto) {
   switch(nNum) {
     case 0: sret = "Assunto(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = "Código do assunto: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = "Assunto: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 30;
    	} break;
   }
} else if (sreg==opAutor) {
   switch(nNum) {
     case 0: sret = "Autor(es) não encontrado(s)!"; break;
     case 1: {
    	 sret = "Código do autor: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = "Autor: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 30;
    	} break;
   }
} else if (sreg==opEditora) {
   switch(nNum) {
     case 0: sret = "Editora(s) não encontrada(s)!"; break;
     case 1: {
    	 sret = "Código da editora: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = "Editora: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 50;
    	} break;
   }
} else if (sreg==opEndereco) {
   switch(nNum) {
     case 0: sret = "Endereço(s) não encontrado(s)!"; break;
     case 1: {
         sret = "Código do endereço: ";
         g_nPosChave = 1;
		 g_nTamChave = 10;
        } break;
     case 2: {
         sret = "Logradouro: ";
         g_nPosChave = 11;
		 g_nTamChave = 40;
        } break;
     case 3: {
         sret = "Bairro: ";
         g_nPosChave = 51;
		 g_nTamChave = 15;
		} break;
     case 4: {
         sret = "CEP: ";
         g_nPosChave = 66;
         g_nTamChave = 8;
        } break;
     case 5: {
         sret = "Cidade: ";
         g_nPosChave = 74;
         g_nTamChave = 30;
		} break;
	 case 6: {
         sret = "Estado: ";
         g_nPosChave = 104;
         g_nTamChave = 20;
        } break;
   }
} else if (sreg==opIdioma) {
   switch(nNum) {
     case 0: sret = "Idioma(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = "Código do idioma: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = "Idioma: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 20;
    	} break;
   }
} else if (sreg==opPais) {
   switch(nNum) {
     case 0: sret = "País(es) não encontrado(s)!"; break;
     case 1: {
    	 sret = "Código do país: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 3;
    	} break;
     case 2: {
    	 sret = "País: ";
    	 g_nPosChave = 4;
    	 g_nTamChave = 50;
    	} break;
   }
} else if (sreg==opProfissao) {
   switch(nNum) {
     case 0: sret = "Profissão(es) não encontrada(s)!"; break;
     case 1: {
    	 sret = "Código da profissão: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = "Profissão: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 50;
    	} break;
   }
} else if (sreg==opUsuario) {
   switch(nNum) {
     case 0: sret = "login ou senha incorreta, tente de novo!"; break;
     case 1: {
    	 sret = "Login: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = "Senha: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 10;
    	} break;
   }
} else if (sreg==opLivro) {
   switch(nNum) {
     case 0: sret = "Livro(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = "ISBN: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 13;
    	} break;
     case 2: {
    	 sret = "Título: ";
    	 g_nPosChave = 14;
    	 g_nTamChave = 50;
    	} break;
     case 3: {
    	 sret = "Edição: ";
    	 g_nPosChave = 64;
    	 g_nTamChave = 10;
    	} break;
     case 4: {
    	 sret = "Ano de Publicação: ";
    	 g_nPosChave = 74;
    	 g_nTamChave = 10;
    	} break;
     case 5: {
         sret = "Código da editora: ";
         g_nPosChave = 84;
         g_nTamChave = 10;
        } break;
	 case 6: {
         sret = "Volume: ";
         g_nPosChave = 94;
         g_nTamChave = 10;
        } break;
	 case 7: {
         sret = "Código do idioma: ";
         g_nPosChave = 104;
         g_nTamChave = 10;
        } break;
	 case 8: {
	 sret = "Número de páginas: ";
         g_nPosChave = 114;
         g_nTamChave = 10;
        } break;
     case 9: {
         sret = "Preço: ";
         g_nPosChave = 124;
         g_nTamChave = 10;
        } break;
     case 10: {
          sret = "Qtd. Estoque: ";
          g_nPosChave = 134;
          g_nTamChave = 10;
         } break;
   }
} else if (sreg==opLivroAss) {
   switch(nNum) {
     case 0: sret = "Assunto(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = "ISBN: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 13;
    	} break;
     case 2: {
    	 sret = "Código do assunto: ";
    	 g_nPosChave = 14;
    	 g_nTamChave = 10;
    	} break;
   }
} else if (sreg==opLivroAut) {
   switch(nNum) {
     case 0: sret = "Autor(s) não encontrado(s)!"; break;
     case 1: {
         sret = "ISBN: ";
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         sret = "Código do autor: ";
         g_nPosChave = 14;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==opCliente) {
   switch(nNum) {
     case 0: sret = "Cliente(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = "CPF: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 14;
    	} break;
     case 2: {
    	 sret = "Nome: ";
    	 g_nPosChave = 15;
    	 g_nTamChave = 30;
    	} break;
     case 3: {
    	 sret = "E-mail: ";
    	 g_nPosChave = 45;
           g_nTamChave = 30;
        } break;
     case 4: {
         sret = "Identidade: ";
         g_nPosChave = 75;
         g_nTamChave = 10;
        } break;
     case 5: {
         sret = "Sexo: ";
         g_nPosChave = 85;
         g_nTamChave = 1;
        } break;
	 case 6: {
         sret = "Telefone: ";
	 g_nPosChave = 86;
         g_nTamChave = 17;
        } break;
     case 7: {
         sret = "Dt. Nascimento: ";
	 g_nPosChave = 103;
         g_nTamChave = 10;
        } break;
     case 8: {
         sret = "Código do endereço: ";
	 g_nPosChave = 113;
	 g_nTamChave = 10;
        } break;
     case 9: {
         sret = "Código do país: ";
         g_nPosChave = 123;
         g_nTamChave = 3;
        } break;
     case 10: {
          sret = "Código da Profissão: ";
          g_nPosChave = 126;
          g_nTamChave = 10;
        } break;
   }
} else if (sreg==opVenda) {
   switch(nNum) {
	 case 0: sret = "Venda(s) não encontrada(s)!"; break;
     case 1: {
	 sret = "Data/Hora venda: ";
         g_nPosChave = 1;
         g_nTamChave = 19;
        } break;
     case 2: {
	 sret = "CPF: ";
         g_nPosChave = 20;
         g_nTamChave = 14;
        } break;
     case 3: {
	 sret = "ISBN: ";
	 g_nPosChave = 34;
         g_nTamChave = 13;
        } break;
     case 4: {
         sret = "Preço de venda: ";
         g_nPosChave = 47;
         g_nTamChave = 10;
        } break;
   }
}

return(sret);
}
/*------------------------------------------------------------------------------
Indica se continua ou não mostrando um número máximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou não
------------------------------------------------------------------------------*/
bool Livrus::ContinuaSN(int nlinha, int nQtdLinha) {
bool bSOp, bret;
char opCSubMenu;

bret = false;
if (nlinha > 0) {
  if ((nlinha % nQtdLinha) == 0) {
    bSOp = true;
    while(bSOp) {
       menu(13);
       cin >> opCSubMenu;
       if ((opCSubMenu=='S') || (opCSubMenu=='s')) bSOp = false;
       else if ((opCSubMenu=='N') || (opCSubMenu=='n')) {
         bret = true;
         bSOp = false;
       } else
         cerr << MSG_ERRO << endl;
    }
  }
}

return(bret);
}
/*------------------------------------------------------------------------------
Lista vários registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se encontrou algum registro
------------------------------------------------------------------------------*/
bool Livrus::ListarTodos(fstream &sArq, ctArqs sreg, string sChave,
   int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
   bool bPesqRelativa) {
bool bQuebra, bAchou, bRet;
int nCont;
string sres, slocal = "";
char slinha[TAM_MAX_REG];

bRet = false;
bQuebra = false;
nCont = 0;
mostrarDados(sreg, "", 2);
sArq.clear();
sArq.seekg(0);
while (!sArq.eof() && bQuebra == false) {
  sArq.read(slinha, nTamLinha + TAM_CRLF);
  slocal.assign(slinha);
  if (slocal!="") {
    if (bPesqRelativa) {
      sres = trim(copy(slocal,nPosChave,nTamChave));
      if (strRelativa(sres,sChave)==true) {
         bAchou = true;
         bRet = true;
      } else {
         bAchou = false;
      }
    } else {
      bAchou = true;
      bRet = true;
    }

    if (bAchou && (!sArq.eof())) {
      mostrarDados(sreg, copy(slocal,1,nTamLinha), 3);
      nCont++;
    }
  }
  bQuebra = ContinuaSN(nCont, nQtdLinha);
}

return bRet;
}
/*------------------------------------------------------------------------------
Lista vários registros entre arquivos de acordo com a pesquisa feita.
sArq1 - o arquivo de ligação
sreg1 - o tipo de arquivo de ligação
nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
nTamChave1 - o tamanho da primeira chave no arquivo de ligação
nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
nTamChave2 - o tamanho da segunda chave do arquivo de ligação
sChave - a chave a ser pesquisada no arquivo de ligação
sArq2 - o arquivo a ser pesquisado
sreg2 - o tipo de arquivo a ser pesquisado
nPosChave3 - a posicao inicial da chave do arquivo pesquisado
nQtdLinha - a quantidade de linhas a serem mostradas
------------------------------------------------------------------------------*/
void Livrus::ListarRegLigados(fstream &sArq1, ctArqs sreg1, int nPosChave1,
int nTamChave1, int nPosChave2, int nTamChave2, string sChave,
fstream &sArq2, ctArqs sreg2, int nPosChave3, int nQtdLinha) {
char slinha1[TAM_MAX_REG];
bool bQuebra, bRet;
int nCont;
string sres, sCodigo1, sCodigo2, slinha2;

bRet = false;
nCont = 0;
bQuebra = false;
mostrarDados(sreg2, "", 2);
sArq1.clear();
sArq1.seekg(0);
while (!sArq1.eof() && bQuebra == false) {
  sArq1.read(slinha1, tamReg(sreg1) + TAM_CRLF);
  sres.assign(slinha1);
  if (sres!="") {
    sCodigo1 = trim(copy(sres,nPosChave1,nTamChave1));
    if (sCodigo1==sChave) {
      sCodigo2 = trim(copy(slinha1,nPosChave2,nTamChave2));
      slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
      mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
      bRet = true;
      nCont++;
    }
  }
  bQuebra = ContinuaSN(nCont, nQtdLinha);
}
if (bRet==false)
   cout << rotulo(sreg2,0) << endl;
}
/*------------------------------------------------------------------------------
Valida a entrada de registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
nTexto - o numero do rótulo da entrada
sEntrada - a chave a ser pesquisada e validada
nTentativas - o número máximo de tentativas
bPesqRelativa - indica se vai realizar uma pesquisa relativa
bTipoEntrada - indica o tipo de entrada
retorna - o registro pesquisado e validado
------------------------------------------------------------------------------*/
string Livrus::validaEntrada(fstream &sArq, ctArqs sreg, int nTexto,
  string sEntrada, int nTentativas, bool bPesqRelativa, ctTipo bTipoEntrada) {
bool bQuebra;
string sres, sTexto, sMsgErro, sLocal;
int ncont, nPosChave, nTamChave, nTamLinha;

sres = "";
sLocal = "";

nTamLinha = tamReg(sreg);
sMsgErro = rotulo(sreg,0);
sTexto = rotulo(sreg,nTexto);
nPosChave = g_nPosChave;
nTamChave = g_nTamChave;

ncont = 1;
bQuebra = false;
while ((bQuebra==false) && (ncont <= nTentativas )) {
  if (bTipoEntrada==opTexto) {
    cout << sTexto;
    cin >> sLocal;
  } else if (bTipoEntrada==opNumero)
     sLocal = validaNumero(sTexto,sLocal);
  else if (bTipoEntrada==opData)
     sLocal = validaDataHora(sTexto,sLocal,true);
  else if (bTipoEntrada==opDataHora)
     sLocal = validaDataHora(sTexto,sLocal,false);
  else if (bTipoEntrada==opSenha)
     sLocal = digitaSenha(sTexto, 10);

  if (bPesqRelativa) {
     if (ListarTodos(sArq, sreg, sLocal, nPosChave, nTamChave, nTamLinha,
         QTD_MAX_LINHA, true))
      sres = " ";
  } else
     sres = pesqArq(sArq, sLocal, nPosChave, nTamChave, nTamLinha);

  if (sres=="")
     cerr << sMsgErro << endl;
  else
     bQuebra = true;

  ncont++;
}
return(sres);
}
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
void Livrus::frmSplash() {
int cont;

 cout << "*---------------------------------------"
      << "-------------------------------------*" << endl;
 cout << "| LL    II VV   VV RRRRR  UU  UU   SSSS "
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |" << endl;
 cout << "| LL    II  VV VV  RR   R UU  UU  SS    "
 " VV VV  II RR   R  TT  UU  UU  SS    |" << endl;
 cout << "| LL    II   VVV   RRRRR  UU  UU    SS  "
 "  VVV   II RRRRR   TT  UU  UU    SS  |" << endl;
 cout << "| LLLLL II    V    RR   R  UUUU  SSSS   "
 "   V    II RR   R  TT   UUUU  SSSS   |" << endl;
 cout << "*---------------------------------------"
 "-------------------------------------*" << endl;
 for(cont = 1; cont <= 18; cont++) cout << endl;
 cout << MSG_PRESS;
 cin.get();
}
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
void Livrus::frmSobre() {
 int cont;

 cout << "*------------------------------------------------------------*" << endl;
 cout << "|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |" << endl;
 cout << "|  LL        II   VV     VV   RR     R  UU    UU  SS         |" << endl;
 cout << "|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |" << endl;
 cout << "|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |" << endl;
 cout << "|  LLLL      II      VVV      RR RR     UU    UU        SS   |" << endl;
 cout << "|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |" << endl;
 cout << "|                                                            |" << endl;
 cout << "|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |" << endl;
 cout << "|   VV     VV   II  RR     R     TT     UU    UU  SS         |" << endl;
 cout << "|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |" << endl;
 cout << "|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |" << endl;
 cout << "|      VVV      II  RR RR        TT     UU    UU        SS   |" << endl;
 cout << "|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |" << endl;
 cout << "|                                                            |" << endl;
 cout << "|                                               Versao 1.0.0 |" << endl;
 cout << "| Sistema integrante do projeto Livrus Virtus.               |" << endl;
 cout << "| Todos os direitos reservados para Henrique F. de Souza.    |" << endl;
 cout << "| Versao programada na linguagem C++.                        |" << endl;
 cout << "*------------------------------------------------------------*" << endl;
 for(cont = 1; cont <= 4; cont++) cout << endl;
 cout << MSG_PRESS;
 cin.get();
 cin.get();
}
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
bool Livrus::frmLogin() {
bool bret;
string slinha = "";

bret = false;
cout << "*--------------------------------------------------------------*"
<< endl;
cout << "| Login do sistema                                             |"
<< endl;
cout << "*--------------------------------------------------------------*"
<< endl;
slinha = validaEntrada(tfUsuario, opUsuario, 1, tUsuario.login, 3,
              false, opTexto);
if (slinha!="") {
  slinha = validaEntrada(tfUsuario, opUsuario, 2, tUsuario.senha, 3,
        false, opSenha);
  if (slinha!="") {
        tUsuario.login = trim(copy(slinha, 1, 10));
        tUsuario.senha = trim(copy(slinha, 11, 10));
        bret = true;
  }
}
cout << endl;
return(bret);
}
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*/
void Livrus::menu(int num) {
 if (num==1) {
   cout << "*--------------------------------------------------------------*"
   << endl;
   cout << "| (C)adastros        (P)esquisas     (V)endas        (O)pções  |"
   << endl;
   cout << "*--------------------------------------------------------------*"
   << endl;
 } else if (num==2) {
   cout << "*---------------------------------*" << endl;
   cout << "| 01. Cadastro de Assuntos        |" << endl;
   cout << "| 02. Cadastro de Autores         |" << endl;
   cout << "| 03. Cadastro de Editoras        |" << endl;
   cout << "| 04. Cadastro de Endereços       |" << endl;
   cout << "| 05. Cadastro de Idiomas         |" << endl;
   cout << "| 06. Cadastro de Países          |" << endl;
   cout << "| 07. Cadastro de Profissões      |" << endl;
   cout << "| 08. Cadastro de Clientes        |" << endl;
   cout << "| 09. Cadastro de Livros          |" << endl;
   cout << "| 10. Voltar ao menu              |" << endl;
   cout << "*---------------------------------*" << endl;
 } else if (num==3) {
   cout << "*---------------------------------*" << endl;
   cout << "| 01. Consulta de Assuntos        |" << endl;
   cout << "| 02. Consulta de Autores         |" << endl;
   cout << "| 03. Consulta de Editoras        |" << endl;
   cout << "| 04. Consulta de Endereços       |" << endl;
   cout << "| 05. Consulta de Idiomas         |" << endl;
   cout << "| 06. Consulta de Países          |" << endl;
   cout << "| 07. Consulta de Profissões      |" << endl;
   cout << "| 08. Consulta de Clientes        |" << endl;
   cout << "| 09. Consulta de Livros          |" << endl;
   cout << "| 10. Voltar ao menu              |" << endl;
   cout << "*---------------------------------*" << endl;
 } else if (num==4) {
   cout << "*---------------------------------*" << endl;
   cout << "| 01. Vender Livros               |" << endl;
   cout << "| 02. Vendas Realizadas           |" << endl;
   cout << "| 03. Voltar ao menu              |" << endl;
   cout << "*---------------------------------*" << endl;
 } else if (num==5) {
   cout << "*---------------------------------*" << endl;
   cout << "| 01. Alterar senha               |" << endl;
   cout << "| 02. Sobre o sistema             |" << endl;
   cout << "| 03. Sair do sistema             |" << endl;
   cout << "| 04. Voltar ao menu              |" << endl;
   cout << "*---------------------------------*" << endl;
 } else if (num==6) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==7) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| (1) Salvar inclusão       (2) Voltar ao menu                 |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==8) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==9) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| (1) Salvar alteração      (2) Voltar ao menu                 |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==10) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| Certeza de excluir? (S/N)                                    |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==11) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| Deseja sair do sistema? (S/N)                                |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==12) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==13) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| Deseja continuar? (S/N)                                      |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 } else if (num==14) {
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "| Salvar inclusão (S/N)                                        |" << endl;
   cout << "*--------------------------------------------------------------*" << endl;
 }
 cout << MSG_OPCAO;
}
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
void Livrus::frmCadastros(ctArqs sreg, ctAcao sacao) {
string slinha = "";

if (sreg==opAssunto) {
   if (sacao==opNovo) {
	  tAssunto.codigo = pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
	 slinha = validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,opNumero);
	  if (slinha!="") {
            mostrarDados(sreg, "", 2);
            mostrarDados(sreg, slinha, 3);
            subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opAutor) {
   if (sacao==opNovo) {
	  tAutor.codigo = pesqMaxCod(tfAutor, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,false,opNumero);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opEditora) {
   if (sacao==opNovo) {
	  tEditora.codigo = pesqMaxCod(tfEditora, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,false,opNumero);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opEndereco) {
   if (sacao==opNovo) {
	  tEndereco.codigo = pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
			  false,opNumero);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opIdioma) {
   if (sacao==opNovo) {
	  tIdioma.codigo = pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,false,opNumero);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opPais) {
   if (sacao==opNovo) {
	  cout << rotulo(sreg, 1);
	  cin >> tPais.codigo;
	  slinha = pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg));
	  if (slinha=="") {
		 pesqLinhaExcluida(tfPais, tamReg(sreg));
		 mostrarDados(sreg, "", 1);
		 subMenu(7, sreg);
	  } else cerr << MSG_REGEXST << endl;
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, opTexto);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  cout << rotulo(sreg, 1) << tPais.codigo << endl;
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opProfissao) {
   if (sacao==opNovo) {
	  tProfissao.codigo = pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
			  false,opNumero);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opLivro) {
   if (sacao==opNovo) {
	  cout << rotulo(sreg, 1);
	  cin >> tLivro.isbn;
	  if (ValidaISBN(tLivro.isbn)) {
		  slinha = pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg));
		  if (slinha=="") {
			 pesqLinhaExcluida(tfLivro, tamReg(sreg));
			 mostrarDados(sreg, "", 1);
			 subMenu(7, sreg);
			 frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
			 frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
		  } else cerr << MSG_REGEXST << endl;
	  } else cerr << MSG_ISBNINV << endl;
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,opTexto);
	  if (slinha!="") {
		 mostrarDados(sreg, "", 2);
		 mostrarDados(sreg, slinha, 3);
		 subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  cout << rotulo(sreg, 1) << tLivro.isbn << endl;
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
	  frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
	  cout << "Assuntos dos livros excluídos, inclua novos!" << endl;
	  frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
	  frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
	  cout << "Autores dos livros excluídos, inclua novos!" << endl;
	  frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
	  cout << "Assuntos dos livros sendo excluídos!" << endl;
	  frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
	  cout << "Autores dos livros sendo excluídos!" << endl;
	  frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
   }
} else if (sreg==opCliente) {
   if (sacao==opNovo) {
	  cout << rotulo(sreg, 1);
	  cin >> tCliente.cpf;
	  if (ValidaCPF(tCliente.cpf)) {
		  slinha = pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg));
		  if (slinha=="") {
			 pesqLinhaExcluida(tfCliente, tamReg(sreg));
			 mostrarDados(sreg, "", 1);
			 subMenu(7, sreg);
		  } else cerr << MSG_REGEXST << endl;
	  } else cerr << MSG_CPFINV << endl;
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,opTexto);
	  if (slinha!="") {
		 mostrarDados(sreg, "", 2);
		 mostrarDados(sreg, slinha, 3);
		 subMenu(8, sreg);
	  }
   } else if (sacao==opAlterar) {
	  cout << rotulo(sreg, 1) << tCliente.cpf << endl;
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==opVenda) {
   if (sacao==opNovo) {
	  tVenda.dthrvenda = retDataHora();
	  cout << rotulo(sreg, 1) << tVenda.dthrvenda << endl;
	  slinha = pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
	  if (slinha=="") {
		 slinha = validaEntrada(tfCliente,opCliente,1,tVenda.cpf,3,
				 false,opTexto);
		 if (slinha!="") {
			tVenda.cpf = trim(copy(slinha,1,14));
			if (ValidaCPF(tVenda.cpf)) {
			   cout << " " << rotulo(opCliente, 2); /* Nome */
			   cout << copy(slinha, g_nPosChave, g_nTamChave) << endl;
			   frmCadLigados(opVenda, opNovo, tVenda.cpf);
			} else cerr << MSG_CPFINV << endl;
		 }
	  } else cerr << MSG_REGEXST << endl;
   } else if (sacao==opPesquisar) {
	  slinha = validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
			  false,opDataHora);
	  if (slinha!="") {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   }
}

}
/*------------------------------------------------------------------------------
Realiza as consultas de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
void Livrus::frmConsultas(ctArqs sreg, ctAcao sacao) {
 string slinha = "";

if (sreg==opAssunto) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opAutor) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opEditora) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opEndereco) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1,
			  true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
		 3, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opIdioma) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opPais) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opProfissao) {
   if (sacao==opPesquisar)
	 slinha = validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
			 true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opLivro) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
		1, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opCliente) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
		1, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
} else if (sreg==opVenda) {
   if (sacao==opPesquisar)
	  slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,opTexto);
   else if (sacao==opListarTodos) {
	  if (ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		cout << rotulo(sreg, 0) << endl;
   }
}
if (slinha=="")
   cout << "";
}
/*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*/
void Livrus::frmAlterarSenha() {
  bool bQuebra;
  string sres, sSenhaAtual, sNovaSenha, sConfirmaSenha;
  int nopcao;

sSenhaAtual = "";
sNovaSenha = "";
sConfirmaSenha = "";

cout << rotulo(opUsuario, 1) << tUsuario.login << endl;
nopcao = 1;
bQuebra = false;
while (bQuebra==false) {
  switch(nopcao) {
   case 1: {
       sSenhaAtual = digitaSenha("Senha Atual: ", 10);
	   if (sSenhaAtual!=tUsuario.senha) {
		  cerr << MSG_SENCONFERE << endl;
		  bQuebra = true;
	   } else nopcao = 2;
	  } break;
   case 2: {
	   sNovaSenha = digitaSenha("Nova Senha: ", 10);
	   sConfirmaSenha = digitaSenha("Confirma Senha: ", 10);
	   if (sNovaSenha!=sConfirmaSenha) {
		  cerr << MSG_SENCONFIRM << endl;
		  bQuebra = true;
	   } else nopcao = 3;
	  } break;
   case 3: {
	   sres = pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(opUsuario));
	   if (sres=="")
		 cerr << MSG_LOGINENCON << endl;
	   else {
		 tUsuario.senha = sConfirmaSenha;
		 subMenu(9,opUsuario);
		 bQuebra = true;
	   }
	  } break;
  }
}
}
/*------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
void Livrus::btnAcao(ctArqs sreg, ctAcao sacao) {
if (sreg==opAssunto) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opAutor) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opEditora) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opEndereco) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opIdioma) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opPais) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opProfissao) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	 escreveArq(tfProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opLivro) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opLivroAss) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opLivroAut) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opCliente) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opVenda) {
   if (sacao==opSalvarInclusao)
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==opSalvarAlteracao)
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==opConfirmaExclusao)
	  escreveArq(tfVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==opUsuario) {
   if (sacao==opSalvarAlteracao)
	  escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
}
}
/*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
void Livrus::subMenu(int nmenu, ctArqs sreg) {
  string opSubMenu;
  char opCSubMenu;
  bool bSOp;

bSOp = true;
switch(nmenu) {
 case 6:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opSubMenu;
	 if (opSubMenu=="1") frmCadastros(sreg, opNovo);
	 else if (opSubMenu=="2") frmCadastros(sreg, opPesquisar);
	 else if (opSubMenu=="3") bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
 case 7:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opSubMenu;
	 if (opSubMenu=="1") { btnAcao(sreg, opSalvarInclusao); bSOp = false; }
	 else if (opSubMenu=="2") bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
 case 8:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opSubMenu;
	 if (opSubMenu=="1") { frmCadastros(sreg, opAlterar); bSOp = false; }
	 else if (opSubMenu=="2") { frmCadastros(sreg, opExcluir); bSOp = false; }
	 else if (opSubMenu=="3") bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
 case 9:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opSubMenu;
	 if (opSubMenu=="1") { btnAcao(sreg, opSalvarAlteracao); bSOp = false; }
	 else if (opSubMenu=="2") bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
 case 10:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opCSubMenu;
	 if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
		btnAcao(sreg, opConfirmaExclusao);
		bSOp = false;
	 } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
 case 12:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opSubMenu;
	 if (opSubMenu=="1") frmConsultas(sreg, opPesquisar);
	 else if (opSubMenu=="2") frmConsultas(sreg, opListarTodos);
	 else if (opSubMenu=="3") bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
 case 14:{
	while(bSOp) {
	 menu(nmenu);
	 cin >> opCSubMenu;
	 if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
		btnAcao(sreg, opSalvarInclusao);
		bSOp = false;
		g_SalvarInclusao = true;
	 } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
	 else cerr << MSG_ERRO << endl;
	}
   } break;
}

}
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*/
void Livrus::usaMenu(int num) {
  string opSubMenu;
  bool bSOp;
  char opSair;

 bSOp = true;
 if (num == 1) { /* Cadastros */
   while(bSOp) {
      menu(2);
      cin >> opSubMenu;
      if (opSubMenu=="1") subMenu(6, opAssunto);
      else if (opSubMenu=="2") subMenu(6, opAutor);
      else if (opSubMenu=="3") subMenu(6, opEditora);
      else if (opSubMenu=="4") subMenu(6, opEndereco);
      else if (opSubMenu=="5") subMenu(6, opIdioma);
      else if (opSubMenu=="6") subMenu(6, opPais);
      else if (opSubMenu=="7") subMenu(6, opProfissao);
      else if (opSubMenu=="8") subMenu(6, opCliente);
      else if (opSubMenu=="9") subMenu(6, opLivro);
      else if (opSubMenu=="10") bSOp = false;
      else cerr << MSG_ERRO << endl;
   }
 } else if (num == 2) { /* Pesquisas */
   while(bSOp) {
      menu(3);
      cin >> opSubMenu;
      if (opSubMenu=="1") subMenu(12, opAssunto);
      else if (opSubMenu=="2") subMenu(12, opAutor);
      else if (opSubMenu=="3") subMenu(12, opEditora);
      else if (opSubMenu=="4") subMenu(12, opEndereco);
      else if (opSubMenu=="5") subMenu(12, opIdioma);
      else if (opSubMenu=="6") subMenu(12, opPais);
      else if (opSubMenu=="7") subMenu(12, opProfissao);
      else if (opSubMenu=="8") subMenu(12, opCliente);
      else if (opSubMenu=="9") subMenu(12, opLivro);
      else if (opSubMenu=="10") bSOp = false;
      else cerr << MSG_ERRO << endl;
   }
 } else if (num == 3) { /* Vendas */
   while(bSOp) {
      menu(4);
      cin >> opSubMenu;
      if (opSubMenu=="1") subMenu(6, opVenda);
      else if (opSubMenu=="2") subMenu(12, opVenda);
      else if (opSubMenu=="3") bSOp = false;
      else cerr << MSG_ERRO << endl;
   }
 } else if (num == 4) { /* Opcoes */
   while(bSOp) {
      menu(5);
      cin >> opSubMenu;
      if (opSubMenu=="1") frmAlterarSenha();
      else if (opSubMenu=="2") frmSobre();
      else if (opSubMenu=="3") {
	   menu(11);
	   cin >> opSair;
	   if ((opSair=='S') || (opSair=='s')) {
		  fechaArqs();
		  exit(0);
	   }
	 }
      else if (opSubMenu=="4") bSOp = false;
      else cerr << MSG_ERRO << endl;
   }
 }
}
/*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*/
void Livrus::mostrarDados(ctArqs sreg, string slinha, int nOpcao) {
if (sreg==opAssunto) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 1) << tAssunto.codigo << endl;
		cout << rotulo(sreg, 2);
		cin >> tAssunto.assunto;
	   } break;
	case 2: {
		cout << "Código     Assunto" << endl;
		cout << "------     -------" << endl;
	   } break;
	case 3: {
		tAssunto.codigo = trim(copy(slinha, 1, 10));
		tAssunto.assunto = trim(copy(slinha, 11, 30));
		cout << esp(tAssunto.codigo,10) << " "
		     <<	esp(tAssunto.assunto,30) << endl;
	   } break;
   }
} else if (sreg==opAutor) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 1) << tAutor.codigo << endl;
		cout << rotulo(sreg, 2);
		cin >> tAutor.autor;
	   } break;
	case 2: {
		cout << "Código     Autor" << endl;
		cout << "------     -----" << endl;
	   } break;
	case 3: {
		tAutor.codigo = trim(copy(slinha, 1, 10));
		tAutor.autor = trim(copy(slinha, 11, 30));
		cout << esp(tAutor.codigo,10) << " "
		     << esp(tAutor.autor,30) << endl;
	   } break;
   }
} else if (sreg==opEditora) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 1) << tEditora.codigo << endl;
		cout << rotulo(sreg, 2);
		cin >> tEditora.editora;
	   } break;
	case 2: {
		cout << "Código     Editora" << endl;
		cout << "------     -------" << endl;
	   } break;
	case 3: {
		tEditora.codigo = trim(copy(slinha, 1, 10));
		tEditora.editora = trim(copy(slinha, 11, 50));
		cout << esp(tEditora.codigo,10) << " "
		     << esp(tEditora.editora,50) << endl;
       } break;
   }
} else if (sreg==opEndereco) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 1) << tEndereco.codigo << endl;
		cout << rotulo(sreg, 2);
		cin >> tEndereco.logradouro;
		cout << rotulo(sreg, 3);
		cin >> tEndereco.bairro;
		cout << rotulo(sreg, 4);
		cin >> tEndereco.cep;
		cout << rotulo(sreg, 5);
		cin >> tEndereco.cidade;
		cout << rotulo(sreg, 6);
		cin >> tEndereco.estado;
	   } break;
	case 3: {
		tEndereco.codigo = trim(copy(slinha, 1, 10));
		tEndereco.logradouro = trim(copy(slinha, 11, 40));
		tEndereco.bairro = trim(copy(slinha, 51, 15));
		tEndereco.cep = trim(copy(slinha, 66, 8));
		tEndereco.cidade = trim(copy(slinha, 74, 30));
		tEndereco.estado = trim(copy(slinha, 104, 20));
		cout << "--------------------" << endl;
		cout << rotulo(sreg, 1) << tEndereco.codigo << endl;
		cout << rotulo(sreg, 2) << tEndereco.logradouro << endl;
		cout << rotulo(sreg, 3) << tEndereco.bairro << endl;
		cout << rotulo(sreg, 4) << tEndereco.cep << endl;
		cout << rotulo(sreg, 5) << tEndereco.cidade << endl;
		cout << rotulo(sreg, 6) << tEndereco.estado << endl;
	   } break;
   }
} else if (sreg==opIdioma) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 1) << tIdioma.codigo << endl;
		cout << rotulo(sreg, 2);
		cin >> tIdioma.idioma;
	   } break;
	case 2: {
		cout << "Código     Idioma" << endl;
		cout << "------     ------" << endl;
	   } break;
	case 3: {
		tIdioma.codigo = trim(copy(slinha, 1, 10));
		tIdioma.idioma = trim(copy(slinha, 11, 20));
		cout << esp(tIdioma.codigo,10) << " "
		     << esp(tIdioma.idioma,20) << endl;
	   } break;
   }
} else if (sreg==opPais) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 2);
		cin >> tPais.pais;
	   } break;
	case 2: {
		cout << "Código País" << endl;
		cout << "------ ----" << endl;
	   } break;
	case 3: {
		tPais.codigo = trim(copy(slinha, 1, 3));
		tPais.pais = trim(copy(slinha, 4, 50));
		cout << esp(tPais.codigo,3) << "    "
		     << esp(tPais.pais,50) << endl;
	   } break;
   }
} else if (sreg==opProfissao) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 1) << tProfissao.codigo << endl;
		cout << rotulo(sreg, 2) << endl;
		cin >> tProfissao.profissao;
	   } break;
	case 2: {
		cout << "Código     Profissão" << endl;
		cout << "------     ---------" << endl;
	   } break;
	case 3: {
		tProfissao.codigo = trim(copy(slinha, 1, 10));
		tProfissao.profissao = trim(copy(slinha, 11, 50));
		cout << esp(tProfissao.codigo,10) << " "
		     << esp(tProfissao.profissao,50) << endl;
	   } break;
   }
} else if (sreg==opLivro) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 2);
		cin >> tLivro.titulo;
		tLivro.edicao = validaNumero(rotulo(sreg, 3), tLivro.edicao);
		tLivro.anopubli = validaNumero(rotulo(sreg, 4), tLivro.anopubli);
		mostrarSubDados(opLivro, opEditora, false);
		tLivro.volume = validaNumero(rotulo(sreg, 6), tLivro.volume);
		mostrarSubDados(opLivro, opIdioma, false);
		tLivro.npaginas = validaNumero(rotulo(sreg, 8), tLivro.npaginas);
		tLivro.preco = validaNumero(rotulo(sreg, 9), tLivro.preco);
		tLivro.qtdestoque = validaNumero(rotulo(sreg, 10),
		tLivro.qtdestoque);
	   } break;
	case 3: {
		tLivro.isbn = trim(copy(slinha, 1, 13));
		tLivro.titulo = trim(copy(slinha, 14, 50));
		tLivro.edicao = trim(copy(slinha, 64, 10));
		tLivro.anopubli = trim(copy(slinha, 74, 10));
		tLivro.codeditora = trim(copy(slinha, 84, 10));
		tLivro.volume = trim(copy(slinha, 94, 10));
		tLivro.codidioma = trim(copy(slinha, 104, 10));
		tLivro.npaginas = trim(copy(slinha, 114, 10));
		tLivro.preco = trim(copy(slinha, 124, 10));
		tLivro.qtdestoque = trim(copy(slinha, 134, 10));
		cout << "--------------------" << endl;
		cout << rotulo(sreg, 1) << tLivro.isbn << endl;
		cout << rotulo(sreg, 2) << tLivro.titulo << endl;
		cout << rotulo(sreg, 3) << tLivro.edicao << endl;
		cout << rotulo(sreg, 4) << tLivro.anopubli << endl;
		cout << rotulo(sreg, 5) << tLivro.codeditora << endl;
		mostrarSubDados(opLivro, opEditora, true);
		cout << rotulo(sreg, 6) << tLivro.volume << endl;
		cout << rotulo(sreg, 7) << tLivro.codidioma << endl;
		mostrarSubDados(opLivro, opIdioma, true);
		cout << rotulo(sreg, 8) << tLivro.npaginas << endl;
		cout << rotulo(sreg, 9) << tLivro.preco << endl;
		cout << rotulo(sreg, 10) << tLivro.qtdestoque << endl;
		ListarRegLigados(tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
						 tfAssunto, opAssunto, 1, 4);
		ListarRegLigados(tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
						 tfAutor, opAutor, 1, 4);
	   } break;
   }
} else if (sreg==opCliente) {
   switch(nOpcao) {
	case 1: {
		cout << rotulo(sreg, 2);
		cin >> tCliente.nome;
		cout << rotulo(sreg, 3);
		cin >> tCliente.email;
		cout << rotulo(sreg, 4);
		cin >> tCliente.identidade;
		cout << rotulo(sreg, 5);
		cin >> tCliente.sexo;
		cout << rotulo(sreg, 6);
		cin >> tCliente.telefone;
		tCliente.dtnascimento =
				validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true);
		mostrarSubDados(opCliente, opEndereco, false);
		mostrarSubDados(opCliente, opPais, false);
		mostrarSubDados(opCliente, opProfissao, false);
	   } break;
	case 3: {
		tCliente.cpf = trim(copy(slinha, 1, 14));
		tCliente.nome = trim(copy(slinha, 15, 30));
		tCliente.email = trim(copy(slinha, 45, 30));
		tCliente.identidade = trim(copy(slinha, 75, 10));
		tCliente.sexo = trim(copy(slinha, 85, 1));
		tCliente.telefone = trim(copy(slinha, 86, 17));
		tCliente.dtnascimento = trim(copy(slinha, 103, 10));
		tCliente.codendereco = trim(copy(slinha, 113, 10));
		tCliente.codpais = trim(copy(slinha, 123, 3));
		tCliente.codprofissao = trim(copy(slinha, 126, 10));
		cout << "--------------------" << endl;
		cout << rotulo(sreg, 1) << tCliente.cpf << endl;
		cout << rotulo(sreg, 2) << tCliente.nome << endl;
		cout << rotulo(sreg, 3) << tCliente.email << endl;
		cout << rotulo(sreg, 4) << tCliente.identidade << endl;
		cout << rotulo(sreg, 5) << tCliente.sexo << endl;
		cout << rotulo(sreg, 6) << tCliente.telefone << endl;
		cout << rotulo(sreg, 7) << tCliente.dtnascimento << endl;
		cout << rotulo(sreg, 8) << tCliente.codendereco << endl;
		mostrarSubDados(opCliente, opEndereco, true);
		cout << rotulo(sreg, 9) << tCliente.codpais << endl;
		mostrarSubDados(opCliente, opPais, true);
		cout << rotulo(sreg, 10) << tCliente.codprofissao << endl;
		mostrarSubDados(opCliente, opProfissao, true);
	   } break;
   }
} else if (sreg==opVenda) {
   switch(nOpcao) {
    case 1: mostrarSubDados(opVenda,opVenda, false); break;
    case 2: {
	     cout << 
	     "DataHoraVenda       CPF            ISBN          PreçoVenda" << endl;
	     cout << 
	     "-------------       ---            ----          ----------" << endl;
	   } break;
	case 3: {
		tVenda.dthrvenda = trim(copy(slinha, 1, 19));
		tVenda.cpf = trim(copy(slinha, 20, 14));
		tVenda.isbn = trim(copy(slinha, 34, 13));
		tVenda.precovenda = trim(copy(slinha, 47, 10));
		cout << esp(tVenda.dthrvenda,19) << " " 
		     << esp(tVenda.cpf,14) << " " << esp(tVenda.isbn,13) 
                     << " " << esp(tVenda.precovenda,10) << endl;
	   } break;
   }
}

}
/*------------------------------------------------------------------------------
Mostra as sub informções de entrada e de saída.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai só mostrar na saída
------------------------------------------------------------------------------*/
void Livrus::mostrarSubDados(ctArqs sreg, ctArqs ssubreg, bool bSoMostrar) {
string sRegistro, sPreco;
char *resto;
int nMaxTentativas;

nMaxTentativas = 3;
if (sreg==opLivro) {
  if (ssubreg==opEditora) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(opEditora));
	else
	   sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
				  nMaxTentativas,false,opNumero);
	if (sRegistro!="") {
	  tLivro.codeditora = trim(copy(sRegistro,1,10));
	  cout << " " << rotulo(opEditora, 2);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	}
  } else if (ssubreg==opIdioma) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(opIdioma));
	else
	   sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
				  nMaxTentativas,false,opNumero);
	if (sRegistro!="") {
	  tLivro.codidioma = trim(copy(sRegistro,1,10));
	  cout << " " << rotulo(opIdioma, 2);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	}
  }
} else if (sreg==opCliente) {
  if (ssubreg==opEndereco) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
				  tamReg(opEndereco));
	else
	   sRegistro = validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
				  nMaxTentativas,false,opNumero);
	if (sRegistro!="") {
	  tCliente.codendereco = trim(copy(sRegistro,1,10));
	  cout << " " << rotulo(opEndereco, 2);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	  cout << " " << rotulo(opEndereco, 3);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	  cout << " " << rotulo(opEndereco, 4);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	  cout << " " << rotulo(opEndereco, 5);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	  cout << " " << rotulo(opEndereco, 6);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	}
  } else if (ssubreg==opPais) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(opPais));
	else
	   sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
				  nMaxTentativas,false,opTexto);
	if (sRegistro!="") {
	  tCliente.codpais = trim(copy(sRegistro,1,3));
	  cout << " " << rotulo(opPais, 2);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	}
  } else if (ssubreg==opProfissao) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
				  tamReg(opProfissao));
	else
	   sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
				  nMaxTentativas,false,opNumero);
	if (sRegistro!="") {
	  tCliente.codprofissao = trim(copy(sRegistro,1,10));
	  cout << " " << rotulo(opProfissao, 2);
	  cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	}
  }
} else if (sreg==opVenda) {
  sRegistro = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
  if (sRegistro!="") {
	cout << " " << rotulo(opLivro, 2); /* Titulo */
	cout << copy(sRegistro, g_nPosChave, g_nTamChave) << endl;
	cout << " " << rotulo(opLivro, 9); /* Preco */
	sPreco = copy(sRegistro, g_nPosChave, g_nTamChave);
	g_nPreco = strtod(sPreco.c_str(), &resto);
	cout << sPreco << endl;
  }
}
}
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*/
void Livrus::frmCadLigados(ctArqs sreg, ctAcao sacao, string sCodigo) {
  int nQtd, nCont, nQtdEstoque;
  double nTotalPreco;
  string slinha, sTotalPreco, sPreco;
//  char scTotalPreco[TAM_MAX_STR];
  char scPreco[TAM_MAX_STR];
  string sQtd = "";

if (sacao==opNovo) {
  nCont = 1;
  if (sreg==opLivroAss) {
	sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",sQtd);
	nQtd = atoi(sQtd.c_str());
	tfLivroAss.seekg(0, ios::beg);
	while (nCont <= nQtd) {
	  tLivroAss.isbn = sCodigo;
	  cout << rotulo(opLivroAss, 2);
	  cin >> tLivroAss.codassunto;
	  slinha = pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(opAssunto));
	  cout << " " << rotulo(opAssunto, 2);
	  cout << copy(slinha, g_nPosChave, g_nTamChave) << endl;
	  pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
	  subMenu(14, sreg);
	  nCont++;
	}
  } else if (sreg==opLivroAut) {
	sQtd = validaNumero("Quantos autores quer cadastrar?: ",sQtd);
	nQtd = atoi(sQtd.c_str());
	tfLivroAut.seekg(0, ios::beg);
	while (nCont <= nQtd) {
	  tLivroAut.isbn = sCodigo;
	  cout << rotulo(opLivroAut, 2);
	  cin >> tLivroAut.codautor;
	  slinha = pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(opAutor));
	  cout << " " << rotulo(opAutor, 2);
	  cout << copy(slinha, g_nPosChave, g_nTamChave) << endl;
	  pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
	  subMenu(14, sreg);
	  nCont++;
	}
  } else if (sreg==opVenda) {
	sPreco = "";
	sTotalPreco = "";
	sQtd = validaNumero("Quantos livros quer vender?: ",sQtd);
	nQtd = atoi(sQtd.c_str());
	nTotalPreco = 0;
	while (nCont <= nQtd) {
	  slinha = validaEntrada(tfLivro,opLivro,1,tVenda.isbn,3,false,opTexto);
	  if (slinha!="") {
		tVenda.isbn = trim(copy(slinha,1,13));
		if (ValidaISBN(tVenda.isbn)) {
		  mostrarDados(sreg, "", 1);
		  tLivro.qtdestoque = trim(copy(slinha,134,10));
		  nQtdEstoque = atoi(tLivro.qtdestoque.c_str());
		  if (nQtdEstoque > 0) {
			 nTotalPreco = nTotalPreco + g_nPreco;
			 gcvt(g_nPreco, 7, scPreco);
			 sPreco.assign(scPreco);
			 tVenda.precovenda = sPreco;
			 g_SalvarInclusao = false;
			 subMenu(14, sreg);
			 if (g_SalvarInclusao) {
				slinha = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
				if (slinha!="") {
				   nQtdEstoque = nQtdEstoque-1;
				   tLivro.qtdestoque = nQtdEstoque;
				   slinha=copy(slinha,1,133) + esp(tLivro.qtdestoque,10);
				   escreveArq(tfLivro, slinha, "", "");
				}
			 }
			 nCont++;
		  } else cerr << MSG_SEMESTOQUE << endl;
		} else cerr << MSG_ISBNINV << endl;
	  }
	}
   // gcvt(nTotalPreco, 7, scTotalPreco);
   // sTotalPreco.assign(scTotalPreco);
	cout << "Total de " << rotulo(sreg,4) << nTotalPreco << endl;
  }
} else if (sacao==opExcluir) {
  if (sreg==opLivroAss) {
	 ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo);
  } else if (sreg==opLivroAut) {
	 ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo);
  }
}

}
/*------------------------------------------------------------------------------
Realiza a exclusão dos arquivos de ligação.
sArq - o arquivo de ligação
sreg - o tipo de arquivo de ligação
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------*/
void Livrus::ExcluirRegLigados(fstream &sArq, ctArqs sreg, int nPosChave,
int nTamChave, string sChave) {
char slinha[TAM_MAX_REG];
string sCodigo, slocal = "";

sArq.clear();
sArq.seekg(0, ios::beg);
while (!sArq.eof()) {
  sArq.read(slinha, tamReg(sreg) + TAM_CRLF);
  slocal.assign(slinha);
  if (slocal!="") {
	sCodigo = trim(copy(slocal,nPosChave,nTamChave));
	if (sCodigo==sChave)
	   btnAcao(sreg,opConfirmaExclusao);
  }
}

}
/*------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------*/
int main(int argc, char *args[]) {
  Livrus* cl = new Livrus();

  if ((argc > 1) && (strcmp(args[1],"-cria")==0))
    cl->abrecriaArqs(false);
  else {
    cl->frmSplash();
    cl->abrecriaArqs(true);
    if (cl->frmLogin()) {
  	cl->bopcao = true;
  	while(cl->bopcao) {
  	  cl->menu(1);
  	  cin >> cl->opmenu;
  	  if ((cl->opmenu=='C') || (cl->opmenu=='c')) cl->usaMenu(1);
  	  else if ((cl->opmenu=='P') || (cl->opmenu=='p')) cl->usaMenu(2);
  	  else if ((cl->opmenu=='V') || (cl->opmenu=='v')) cl->usaMenu(3);
  	  else if ((cl->opmenu=='O') || (cl->opmenu=='o')) cl->usaMenu(4);
  	  else cerr << cl->MSG_ERRO << endl;
  	}
    } else {
  	cl->fechaArqs();
  	exit(0);
    }
  }
  return 0;
}

