/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem Objective-C.
------------------------------------------------------------------------------*/
// programa Livrus

#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include "objc/Object.h"

@interface Livrus : Object
{
 @private 
  struct regAssunto {
   char codigo[10];
   char assunto[30];
  };
  struct regAutor {
   char codigo[10];
   char autor[30];
  };
  struct regEditora {
   char codigo[10];
   char editora[50];
  };
  struct regIdioma {
   char codigo[10];
   char idioma[20];
  };
  struct regUsuario {
   char login[10];
   char senha[10];
  };
  struct regPais {
   char codigo[3];
   char pais[50];
  };
  struct regProfissao {
   char codigo[10];
   char profissao[50];
  };
  struct regLivro {
   char isbn[13];
   char titulo[50];
   char edicao[10];
   char anopubli[10];
   char codeditora[10];
   char volume[10];
   char codidioma[10];
   char npaginas[10];
   char preco[10];
   char qtdestoque[10];
  };
  struct regLivroAss {
   char isbn[13];
   char codassunto[10];
  };
  struct regLivroAut {
   char isbn[13];
   char codautor[10];
  };
  struct regCliente {
   char cpf[14];
   char nome[30];
   char email[30];
   char identidade[10];
   char sexo[1];
   char telefone[17];
   char dtnascimento[10];
   char codendereco[10];
   char codpais[3];
   char codprofissao[10];
  };
  struct regEndereco {
   char codigo[10];
   char logradouro[40];
   char bairro[15];
   char cep[8];
   char cidade[30];
   char estado[20];
  };
  struct regVenda {
   char dthrvenda[19];  /* data/hora da venda dd/mm/yyyy hh:mm:ss */
   char cpf[14];
   char isbn[13];
   char precovenda[10];
  };

  enum ctTipo { opTexto, opNumero, opData, opDataHora, opSenha };
  enum ctArqs { opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
                opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
                opUsuario, opVenda };
  enum ctAcao { opNovo, opAlterar, opPesquisar, opSalvarInclusao,
              opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos };

  STR CRLF;
  int TAM_CRLF;

  STR ARQ_ABRE;
  STR ARQ_CRIA;

  int QTD_MAX_LINHA;
  int TAM_MAX_STR;
  int TAM_MAX_REG;

  STR MSG_ARQERRO;
  STR MSG_ARQCERRO;
  STR MSG_OPCAO;
  STR MSG_PRESS;

  STR MSG_REGINC;
  STR MSG_REGNINC;
  STR MSG_REGALT;
  STR MSG_REGNALT;
  STR MSG_REGEXC;
  STR MSG_REGNEXC;
  STR MSG_REGEXST;

  STR MSG_NUMINV;
  STR MSG_DATAINV;
  STR MSG_DTHRINV;
  STR MSG_ISBNINV;
  STR MSG_CPFINV;
  STR MSG_SENCONFERE;
  STR MSG_SENCONFIRM;
  STR MSG_LOGINENCON;
  STR MSG_SEMESTOQUE;

  STR ARQ_ASSUNTO;
  STR ARQ_AUTOR;
  STR ARQ_EDITORA;
  STR ARQ_IDIOMA;
  STR ARQ_USUARIO;
  STR ARQ_PAIS;
  STR ARQ_PROFISSAO;
  STR ARQ_LIVRO;
  STR ARQ_LIVASS;
  STR ARQ_LIVAUT;
  STR ARQ_CLIENTE;
  STR ARQ_ENDERECO;
  STR ARQ_VENDA;

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

  int g_nPosChave, g_nTamChave;
  double g_nPreco;
  BOOL g_SalvarInclusao;

  struct regAssunto tAssunto;
  struct regAutor tAutor;
  struct regEditora tEditora;
  struct regIdioma tIdioma;
  struct regEndereco tEndereco;
  struct regPais tPais;
  struct regProfissao tProfissao;
  struct regLivro tLivro;
  struct regLivroAss tLivroAss;
  struct regLivroAut tLivroAut;
  struct regCliente tCliente;
  struct regUsuario tUsuario;
  struct regVenda tVenda;

  FILE *tfAssunto, *tfAutor, *tfEditora, *tfIdioma, *tfEndereco, *tfPais, 
  *tfProfissao, *tfLivro, *tfLivroAss, *tfLivroAut, 
  *tfCliente, *tfUsuario, *tfVenda;

 @public 
   STR MSG_ERRO;
}

+ new;
- free;
- constantes;
- (STR) retMSGERRO;

/*--- Rotinas básicas --------------------------------------------------------*/
- (STR) alocaString: (int) ntam;
- (STR) somastr: (int) num, ...;
- (STR) copy: (STR) string, ...;
- (STR) trim: (STR) sTexto;
- (STR) repete: (STR) sTexto, ...;
- (STR) esp: (STR) sTexto, ...;
- (STR) zeros: (STR) sTexto, ...;
- (BOOL) strRelativa: (STR) sTexto, ...;
- (int) modulo11: (STR) svalor, ...;
- (BOOL) validaCPF: (STR) cpf;
- (BOOL) validaISBN: (STR) isbn;
- (STR) digita: (int) nTam;
- (STR) digitaSenha: (STR) sRotulo, ...;
- (STR) validaNumero: (STR) sRotulo, ...;
- (STR) validaDataHora: (STR) sRotulo, ...;
- (STR) itoa: (int) nvalor, ...;
- (STR) retDataHora;

/*--- Rotinas de manipulação de arquivos -------------------------------------*/
- (long) tamArq: (FILE*) sArq;
- abrecriaArqs: (BOOL) bAbre;
- fechaArqs;
- (STR) pesqArq: (FILE*) sArq, ...;
- pesqLinhaExcluida: (FILE*) sArq, ...;
- (STR) pesqMaxCod: (FILE*) sArq, ...;
- escreveArq: (FILE*) sArq, ...;

/*--- Rotinas de implementação do sistema e de interface ---------------------*/
- (STR) LinhaReg: (enum ctArqs) sreg;
- (int) tamReg: (enum ctArqs) sreg;
- (STR) rotulo: (enum ctArqs) sreg, ...;
- (BOOL) ContinuaSN: (int) nlinha, ...;
- (BOOL) ListarTodos: (FILE*) sArq, ...;
- ListarRegLigados: (FILE*) sArq1, ...;
- (STR) validaEntrada: (FILE*) sArq, ...;
- frmSplash;
- frmSobre;
- (BOOL) frmLogin;
- menu: (int) num;
- frmCadastros: (enum ctArqs) sreg, ...; 
- frmConsultas: (enum ctArqs) sreg, ...;
- frmAlterarSenha;
- btnAcao: (enum ctArqs) sreg, ...;
- subMenu: (int) nmenu, ...;
- usaMenu: (int) num;
- mostrarDados: (enum ctArqs) sreg, ...;
- mostrarSubDados: (enum ctArqs) sreg, ...;
- frmCadLigados: (enum ctArqs) sreg, ...;
- ExcluirRegLigados: (FILE*) sArq, ...;

@end

@implementation Livrus

/*------------------------------------------------------------------------------
método de criação da classe.
------------------------------------------------------------------------------*/
+ new
{
  self = [super new];
  return self;
}

/*------------------------------------------------------------------------------
método de destruição e liberação da memória da classe.
------------------------------------------------------------------------------*/
- free
{
  return [super free];
}

/*------------------------------------------------------------------------------
método que inicia todas as constantes.
------------------------------------------------------------------------------*/
- constantes
{
  CRLF = "\n"; /* windows */
  TAM_CRLF = 1;
/* CRLF = "\n";
   TAM_CRLF = 1; */ /* unix */
/* CRLF = "\r";
   TAM_CRLF = 1; */ /* macintosh */

  ARQ_ABRE = "rt+";
  ARQ_CRIA = "wt+";

  QTD_MAX_LINHA = 18;
  TAM_MAX_STR = 255;
  TAM_MAX_REG = 145;

  MSG_ARQERRO = "Erro: O arquivo não pode ser aberto.";
  MSG_ARQCERRO = "Erro: O arquivo não pode ser criado.";
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
  MSG_SENCONFIRM = "nova senha não confere com a senha confirmada!";
  MSG_LOGINENCON = "login não encontrado!";
  MSG_SEMESTOQUE = "livro não existe no estoque!";

  ARQ_ASSUNTO = "C:/temp/assunto.dat";
  ARQ_AUTOR = "C:/temp/autor.dat";
  ARQ_EDITORA = "C:/temp/editora.dat";
  ARQ_IDIOMA = "C:/temp/idioma.dat";
  ARQ_USUARIO = "C:/temp/usuario.dat";
  ARQ_PAIS = "C:/temp/pais.dat";
  ARQ_PROFISSAO = "C:/temp/profissao.dat";
  ARQ_LIVRO = "C:/temp/livro.dat";
  ARQ_LIVASS = "C:/temp/livroass.dat";
  ARQ_LIVAUT = "C:/temp/livroaut.dat";
  ARQ_CLIENTE = "C:/temp/cliente.dat";
  ARQ_ENDERECO = "C:/temp/endereco.dat";
  ARQ_VENDA = "C:/temp/venda.dat";

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
  
  return self;
}
/*------------------------------------------------------------------------------
método que retorna a constante de MSGERRO
------------------------------------------------------------------------------*/
- (STR) retMSGERRO
{
 return MSG_ERRO;
}

/*------------------------------------------------------------------------------
Função que aloca uma string na memória.
ntam - indica o tamanho de caracteres a serem alocados na memória
retorna - a string alocada
------------------------------------------------------------------------------*/
- (STR) alocaString: (int) ntam
{ 
 STR strlocal;

 strlocal=(STR) malloc(ntam);
 if (!strlocal) exit(1);
 else strlocal[0]='\0';
 
 return strlocal;
}
/*------------------------------------------------------------------------------
método que soma determinado número de strings.
num - indica o número de strings
... - as strings a serem somadas
retorna - o pedaço da string
------------------------------------------------------------------------------*/
- (STR) somastr: (int) num, ...
{
 int ig,j,t;
 STR lstr, soma;
 va_list argptr;

 lstr = [self alocaString: TAM_MAX_STR * 2];
 soma = [self alocaString: TAM_MAX_STR * 4];

 va_start(argptr,num);

 j=0; t=0;
 for(;num;num--){
   lstr = va_arg(argptr,char*);
   for(ig=j; ig < abs(j+strlen(lstr)); ig++){
      soma[ig]=lstr[t];
      t++;
    }
   soma[ig]='\0';
   j=strlen(soma);
   t=0;
 }
 va_end(argptr);

 return soma;
}
/*------------------------------------------------------------------------------
Função que retorna um pedaço de uma string.
string - indica a string
ini - indica a posicao inicial do pedaco
tam - indica o tamanho do pedaco
retorna - o pedaço da string
------------------------------------------------------------------------------*/
- (STR) copy: (STR) string, ...
{ 
 STR str1, slocal;
 int i, j, ini, tam;

va_list lparams;
va_start(lparams, string);
ini = va_arg(lparams,int);
tam = va_arg(lparams,int);
va_end(lparams);

str1 = [self alocaString: TAM_MAX_STR];
slocal = [self alocaString: TAM_MAX_STR];
  
strcpy(slocal, string);
j=0;
ini--;
for(i=ini;i<(ini+tam);i++)
 {
   str1[j]=slocal[i];
   j++;
 }
str1[j]='\0';
free(slocal);
return str1;
}
/*------------------------------------------------------------------------------
Retira os espaços em branco antes ou depois do texto.
sTexto - o texto a ser retirado os espaços em branco
retorna - o texto sem os espaços em branco
------------------------------------------------------------------------------*/
- (STR) trim: (STR) sTexto
{
 int ncont, nPosIni, nPosFim;
 STR sret, slocal;
 BOOL bQuebra;

nPosIni = 0;
nPosFim = 0;
ncont = 0;
bQuebra = NO;
slocal = sTexto;
while ((ncont<=abs(strlen(slocal))) && (bQuebra==NO))  {
  if (slocal[ncont]!=' ') {
     nPosIni = ncont + 1;
     bQuebra = YES;
  }
  ncont++;
}

ncont = strlen(slocal)-1;
bQuebra = NO;
while ((ncont >= 0) && (bQuebra==NO)) {
  if (slocal[ncont]!=' ') {
     nPosFim = ncont + 1;
     bQuebra = YES;
  }
  ncont--;
}
nPosFim=(nPosFim-nPosIni)+1;
sret = [self copy: slocal,nPosIni,nPosFim]; 

return sret;
}
/*------------------------------------------------------------------------------
Repete um texto um número determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*/
- (STR) repete: (STR) sTexto, ...
{ 
  int ncont, nQtd;
  STR sret;

va_list lparams;
va_start(lparams, sTexto);
nQtd = va_arg(lparams,int);
va_end(lparams);

sret = [self alocaString: TAM_MAX_STR];

for(ncont = 1; ncont <= nQtd; ncont++) {
  sret = (STR) strcat(sret,sTexto);
}

return sret;
}
/*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*/
- (STR) esp: (STR) sTexto, ...
{ 
  int nTam;
  STR sret, slocal;

va_list lparams;
va_start(lparams, sTexto);
nTam = va_arg(lparams,int);
va_end(lparams);

slocal=[self alocaString: TAM_MAX_STR];

strcpy(slocal, sTexto);
sret = [self repete: " ",nTam-strlen(slocal)];
strcat(slocal,sret);

free(sret);
return slocal;
}
/*------------------------------------------------------------------------------
Escreve zeros na frente de um texto.
stexto - o texto para receber zeros a frente
ntam - o tamanho da string
retorna - o texto com o zeros antes
------------------------------------------------------------------------------*/
- (STR) zeros: (STR) sTexto, ...
{ 
  int ncont, ntam;
  STR saux;

  va_list lparams;
  va_start(lparams, sTexto);
  ntam = va_arg(lparams,int);
  va_end(lparams);
  
  saux = [self alocaString: TAM_MAX_STR];

  if (ntam!=abs(strlen(sTexto))) {
      for(ncont = 1; ncont <= (ntam-strlen(sTexto)); ncont++)
        saux = (STR) strcat(saux, "0");
  }
  return (STR) strcat(saux, sTexto);
}
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*/
- (BOOL) strRelativa: (STR) sTexto, ...
{
  STR sChave;

  va_list lparams;
  va_start(lparams, sTexto);
  sChave = va_arg(lparams,STR);
  va_end(lparams);

  if (strstr(sTexto,sChave)!=NULL)
    return YES;
  else
    return NO;
}
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a mstring com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*/
- (int) modulo11: (STR) svalor, ...
{ 
  int ndig, ncont, nsoma, nvalor, npos;
  STR slocal, sres;

  va_list lparams;
  va_start(lparams, svalor);
  ndig = va_arg(lparams,int);
  va_end(lparams);

 slocal=[self alocaString: TAM_MAX_STR];

 ncont=1;
 while (ncont <= 11) {
   slocal= (STR) strcat([self copy: svalor,ncont,1],slocal);
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=3;
 else
   ncont=2;
 npos=2;
 while (ncont <= 11) {
   sres = [self copy: slocal,ncont,1];
   nvalor = atoi(sres);
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 free(sres);
 free(slocal);

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
- (BOOL) validaCPF: (STR) cpf
{ 
  STR scpf, sres;
  int nvalor1, nvalor2;

if (strlen(cpf)==14) {
  scpf = [self somastr: 4,[self copy: cpf,1,3],[self copy: cpf,5,3],
          [self copy: cpf,9,3],[self copy: cpf,13,2]];
  sres = [self copy: cpf,13,1];
  nvalor1 = atoi(sres);
  strcpy(sres, [self copy: cpf,14,1]);
  nvalor2 = atoi(sres);
  if (([self modulo11: scpf,1]==nvalor1) && 
     ([self modulo11: scpf,2]==nvalor2)) {
    return YES;
  } else {
    return NO;
  }
} else
  return NO;
}
/*------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a mstring com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------*/
- (BOOL) validaISBN: (STR) isbn
{ 
  STR sisbn, sdigito, snum;
  int nvalor, nsoma, ncont;

if (strlen(isbn)==13) {
  sisbn = [self alocaString: TAM_MAX_STR];

  sdigito = [self copy: isbn, strlen(isbn), 1];
  sisbn[0]='\0';
  for(ncont = 1; ncont <= abs(strlen(isbn)-1); ncont++)  {
    if (strcmp([self copy: isbn,ncont,1],"-")!=0)
      sisbn = (STR) strcat(sisbn, [self copy: isbn,ncont,1]);
  }
  if (strcmp(sdigito, "X")==0)
    nsoma = 10;
  else {
    nvalor = atoi(sdigito);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = [self copy: sisbn, ncont, 1];
    nvalor = atoi(snum);
    nsoma=nsoma + (nvalor * (11 - ncont));
  }

  free(sisbn);
  free(sdigito);
  free(snum);

  if ((nsoma % 11) == 0)
    return YES;
  else
    return NO;
} else
  return NO;
}
/*------------------------------------------------------------------------------
Realiza a digitação de algum texto
nTam - o tamanho maximo do texto a ser digitado
retorna - o texto digitado.
------------------------------------------------------------------------------*/
- (STR) digita: (int) nTam
{ STR sTexto; 

  sTexto = [self alocaString: TAM_MAX_STR]; 
  fgets(sTexto, nTam, stdin);
  sTexto[strlen(sTexto)-1]='\0';
  if (strlen(sTexto)==0) {
    fflush(stdin);
    fgets(sTexto, nTam, stdin);
    sTexto[strlen(sTexto)-1]='\0';    
  }    
  return sTexto;
}
/*------------------------------------------------------------------------------
Esconde a digitação da senha
retorna - a senha digitada
------------------------------------------------------------------------------*/
- (STR) digitaSenha: (STR) sRotulo, ...
{ 
  STR sSenha;
  char sLetra;
  int ncont, nTamSenha;

  va_list lparams;
  va_start(lparams, sRotulo);
  nTamSenha = va_arg(lparams,int);
  va_end(lparams);

  sSenha = [self alocaString: TAM_MAX_STR];

  printf(sRotulo);
/*strcpy(sSenha, [self digita: TAM_MAX_STR]);*/
  ncont  = 0;
  sLetra = '\0';
  while((sLetra!='\r') && (ncont < nTamSenha)) {
    sLetra = getch();
    if (sLetra!='\r') {
       sSenha[ncont] = sLetra;
    }
    ncont++;
  }
sSenha[ncont-1] = '\0';  
printf("\n");
fflush(stdin);

return sSenha;
}
/*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a mstring com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*/
- (STR) validaNumero: (STR) sRotulo, ...
{ 
  double nnum;
  int nStatus;
  STR sNumero;

  va_list lparams;
  va_start(lparams, sRotulo);
  sNumero = va_arg(lparams,STR);
  va_end(lparams);

 nStatus = -1;
 while (nStatus!=0) {
  printf(sRotulo);
  strcpy(sNumero, [self digita: TAM_MAX_STR]);
  nnum = atof(sNumero);
  if (nnum < 0.01)
     printf("%s\n",MSG_NUMINV);
  else
     nStatus=0;
}
return sNumero;
}
/*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a mstring com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
- (STR) validaDataHora: (STR) sRotulo, ...
{ 
  BOOL bSoData, bvalida, bdatavalida, bhoravalida;
  STR sDataHora, sdia, smes, sano, shora, smin, sseg;
  int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

  va_list lparams;
  va_start(lparams, sRotulo);
  sDataHora = va_arg(lparams,STR);
  bSoData = va_arg(lparams,int);
  va_end(lparams);

bvalida = NO;
bdatavalida = NO;
bhoravalida = NO;
nudiames = 0;
if (bSoData==YES) ntam=10;
else ntam=19;
while (bvalida==NO) {
  printf(sRotulo);
  strcpy(sDataHora, [self digita: TAM_MAX_STR]);
  if (strlen(sDataHora)==ntam) {
    sdia = [self copy: sDataHora,1,2];
    ndia = atoi(sdia);
    smes = [self copy: sDataHora,4,2];
    nmes = atoi(smes);
    sano = [self copy: sDataHora,7,4];
    nano = atoi(sano);

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
             bdatavalida = YES;
      }
    } 

    if (bSoData==YES) {
       if (bdatavalida==YES) 
           bvalida = YES;
       else 
      		 printf("%s\n",MSG_DATAINV);
    } else {
      if (bdatavalida==YES) {
          shora = [self copy: sDataHora,12,2];
          nhora = atoi(shora);
          smin = [self copy: sDataHora,15,2];
          nmin = atoi(smin);
          sseg = [self copy: sDataHora,18,2];
          nseg = atoi(sseg);
  
          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = YES;
            }
          }

        if (bhoravalida==YES) 
     	    bvalida = YES;
        else 
  		    printf("%s\n",MSG_DTHRINV);
      } else
        printf("%s\n",MSG_DTHRINV);
    }
  } else {
    if (bSoData==YES) printf("%s\n",MSG_DATAINV);
    else printf("%s\n",MSG_DTHRINV);
  }
}
return sDataHora;
}
/*------------------------------------------------------------------------------
Converte de inteiro para string, não existente em alguns compiladores.
nvalor - o valor do número inteiro
stexto - a string com o número inteiro
radix - numeral radix
retorna - a string com o número inteiro
------------------------------------------------------------------------------*/
- (STR) itoa: (int) nvalor, ...
{ 
 STR stexto; 
 int radix;

 va_list lparams;
 va_start(lparams, nvalor);
 stexto = va_arg(lparams,STR);
 radix = va_arg(lparams,int);
 va_end(lparams);

 gcvt(nvalor, radix, stexto); 
 strncpy(stexto, stexto, strlen(stexto)-1);
 return stexto;
}
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
- (STR) retDataHora
{ 
  STR sdatahora;
  time_t agora;   
  struct tm * tempo;

  sdatahora = [self alocaString: TAM_MAX_STR];

  time(&agora);
  tempo = localtime(&agora); 
  strftime(sdatahora, TAM_MAX_STR, "%d/%m/%Y %H:%M:%S", tempo);

  return sdatahora;
}
/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
- (long) tamArq: (FILE*) sArq
{ long ntam;

fseek(sArq , 0, SEEK_END);
ntam = ftell(sArq);
rewind(sArq);

return ntam;
}
/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
- abrecriaArqs: (BOOL) bAbre
{
if (bAbre==YES) {
  if ((tfAssunto = fopen(ARQ_ASSUNTO,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_ASSUNTO);
    exit(1);
  }
  if ((tfAutor = fopen(ARQ_AUTOR,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_AUTOR);
    exit(1);
  }
  if ((tfEditora=fopen(ARQ_EDITORA,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_EDITORA);
    exit(1);
  }
  if ((tfIdioma=fopen(ARQ_IDIOMA,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_IDIOMA);
    exit(1);
  }
  if ((tfEndereco=fopen(ARQ_ENDERECO,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_ENDERECO);
    exit(1);
  }
  if ((tfPais=fopen(ARQ_PAIS,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_PAIS);
    exit(1);
  }
  if ((tfProfissao=fopen(ARQ_PROFISSAO,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_PROFISSAO);
    exit(1);
  }
  if ((tfLivro=fopen(ARQ_LIVRO,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_LIVRO);
    exit(1);
  }
  if ((tfLivroAss=fopen(ARQ_LIVASS,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_LIVASS);
    exit(1);
  }
  if ((tfLivroAut=fopen(ARQ_LIVAUT,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_LIVAUT);
    exit(1);
  }
  if ((tfCliente=fopen(ARQ_CLIENTE,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_CLIENTE);
    exit(1);
  }
  if ((tfUsuario=fopen(ARQ_USUARIO,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_USUARIO);
    exit(1);
  }
  if ((tfVenda=fopen(ARQ_VENDA,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_VENDA);
    exit(1);
  }
} else {
  if ((tfAssunto=fopen(ARQ_ASSUNTO,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_ASSUNTO);
    exit(1);
  }
  if ((tfAutor=fopen(ARQ_AUTOR,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_AUTOR);
    exit(1);
  }
  if ((tfEditora=fopen(ARQ_EDITORA,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_EDITORA);
    exit(1);
  }
  if ((tfIdioma=fopen(ARQ_IDIOMA,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_IDIOMA);
    exit(1);
  }
  if ((tfEndereco=fopen(ARQ_ENDERECO,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_ENDERECO);
    exit(1);
  }
  if ((tfPais=fopen(ARQ_PAIS,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_PAIS);
    exit(1);
  }
  if ((tfProfissao=fopen(ARQ_PROFISSAO,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_PROFISSAO);
    exit(1);
  }
  if ((tfLivro=fopen(ARQ_LIVRO,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_LIVRO);
    exit(1);
  }
  if ((tfLivroAss=fopen(ARQ_LIVASS,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_LIVASS);
    exit(1);
  }
  if ((tfLivroAut=fopen(ARQ_LIVAUT,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_LIVAUT);
    exit(1);
  }
  if ((tfCliente=fopen(ARQ_CLIENTE,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_CLIENTE);
    exit(1);
  }
  if ((tfUsuario=fopen(ARQ_USUARIO,ARQ_CRIA))==NULL) {
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_USUARIO);
    exit(1);
  }
  if ((tfVenda=fopen(ARQ_VENDA,ARQ_CRIA))==NULL) { 
    printf("%s --> %s\n",MSG_ARQCERRO,ARQ_VENDA);
    exit(1);
  }
}
  return self;
}
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
- fechaArqs
{
 fclose(tfAssunto);
 fclose(tfAutor);
 fclose(tfEditora);
 fclose(tfIdioma);
 fclose(tfEndereco);
 fclose(tfPais);
 fclose(tfProfissao);
 fclose(tfLivro);
 fclose(tfLivroAss);
 fclose(tfLivroAut);
 fclose(tfCliente);
 fclose(tfUsuario);
 fclose(tfVenda);
 
 return self;
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
- (STR) pesqArq: (FILE*) sArq, ...
{ 
  STR sChave, slinha, sres;
  BOOL bQuebra;
  int nPosChave, nTamChave, nTamLinha, nPosicao;

va_list lparams;
va_start(lparams, sArq);
sChave = va_arg(lparams,STR);
nPosChave = va_arg(lparams,int);
nTamChave = va_arg(lparams,int);
nTamLinha = va_arg(lparams,int);
va_end(lparams);

slinha = [self alocaString: TAM_MAX_STR];

bQuebra = NO;
fseek(sArq, 0, SEEK_SET);
while ((!feof(sArq)) && (bQuebra==NO)) {
  fread(slinha,1,(nTamLinha + TAM_CRLF),sArq);
  sres = [self trim: [self copy: slinha,nPosChave,nTamChave]];
  if (strcmp(sres, sChave)==0)
     bQuebra = YES;
}
nPosicao = ftell(sArq)-(nTamLinha + TAM_CRLF);
if (nPosicao > 0)
   fseek(sArq, nPosicao, SEEK_SET);
else
   fseek(sArq, 0, SEEK_SET);
if (strcmp(sres, sChave)!=0) 
   return "";
else {
   sres = [self copy: slinha,1,nTamLinha];
   return sres;
}
}
/*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
- pesqLinhaExcluida: (FILE*) sArq, ...
{ 
  int nTamLinha;
  STR sExcluido;
 
va_list lparams;
va_start(lparams, sArq);
nTamLinha = va_arg(lparams,int);
va_end(lparams);

sExcluido = [self pesqArq: sArq, "*", 1, 1, nTamLinha];
if (strcmp(sExcluido,"")==0)
   fseek(sArq, [self tamArq: sArq], SEEK_SET);
 
return self;
}
/*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*/
- (STR) pesqMaxCod: (FILE*) sArq, ...
{ 
  STR slinha, sres;
  BOOL bQuebra;
  int nPosChave, nTamChave, nTamLinha, nMaior, nCod;

va_list lparams;
va_start(lparams, sArq);
nPosChave = va_arg(lparams,int);
nTamChave = va_arg(lparams,int);
nTamLinha = va_arg(lparams,int);
va_end(lparams);

slinha = [self alocaString: TAM_MAX_STR];
bQuebra = NO;
nMaior = 0;
fseek(sArq, 0, SEEK_SET);
while ((!feof(sArq)) && (bQuebra==NO)) {
  fread(slinha,1,(nTamLinha + TAM_CRLF),sArq);
  sres = [self trim: [self copy: slinha,nPosChave,nTamChave]];
  nCod=atoi(sres);
  if (nCod > nMaior)
     nMaior = nCod;
}
[self pesqLinhaExcluida: sArq, nTamLinha];
sres = [self itoa: (nMaior+1),sres,10];
free(slinha);
return sres;
}
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*/
- escreveArq: (FILE*) sArq, ...
{ 
  STR sTexto, sMsgAcerto, sMsgErro;
  int ntam;

va_list lparams;
va_start(lparams, sArq);
sTexto = va_arg(lparams,STR);
sMsgAcerto = va_arg(lparams,STR);
sMsgErro = va_arg(lparams,STR);
va_end(lparams);

strcpy(sTexto, (STR) strcat(sTexto,CRLF));
ntam = strlen(sTexto);
if (fwrite(sTexto, 1, ntam, sArq) == ntam)
   printf("%s\n",sMsgAcerto);
else 
   printf("%s\n",sMsgErro);

return self;
}
/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
- (STR) LinhaReg: (enum ctArqs) sreg
{ 
  STR slinha;

if (sreg==opAssunto) {
   slinha = [self somastr: 2,[self esp: tAssunto.codigo,10],
            [self esp: tAssunto.assunto,30]];
} else if (sreg==opAutor)
   slinha = [self somastr: 2,[self esp: tAutor.codigo,10],
            [self esp: tAutor.autor,30]];
else if (sreg==opEditora)
   slinha = [self somastr: 2,[self esp: tEditora.codigo,10],
            [self esp: tEditora.editora,50]];
else if (sreg==opEndereco)
   slinha = [self somastr: 6,[self esp: tEndereco.codigo,10],
   [self esp: tEndereco.logradouro,40], [self esp: tEndereco.bairro,15],
   [self esp: tEndereco.cep,8],[self esp: tEndereco.cidade,30],
   [self esp: tEndereco.estado,20]];
else if (sreg==opIdioma)
   slinha = [self somastr: 2,[self esp: tIdioma.codigo,10],
            [self esp: tIdioma.idioma,20]];
else if (sreg==opPais)
   slinha = [self somastr: 2,[self esp: tPais.codigo,3],
            [self esp: tPais.pais,50]];
else if (sreg==opProfissao)
   slinha = [self somastr: 2,[self esp: tProfissao.codigo,10],
            [self esp: tProfissao.profissao,50]];
else if (sreg==opUsuario)
   slinha = [self somastr: 2,[self esp: tUsuario.login,10],
            [self esp: tUsuario.senha,10]];
else if (sreg==opLivro)
   slinha = [self somastr: 10,[self esp: tLivro.isbn,13],
   [self esp: tLivro.titulo,50], [self esp: tLivro.edicao,10],
   [self esp: tLivro.anopubli,10],[self esp: tLivro.codeditora,10],
   [self esp: tLivro.volume,10],[self esp: tLivro.codidioma,10],
   [self esp: tLivro.npaginas,10], [self esp: tLivro.preco,10],
   [self esp: tLivro.qtdestoque,10]];
else if (sreg==opLivroAss)
   slinha = [self somastr: 2,[self esp: tLivroAss.isbn,13],
            [self esp: tLivroAss.codassunto,10]];
else if (sreg==opLivroAut)
   slinha = [self somastr: 2,[self esp: tLivroAut.isbn,13],
            [self esp: tLivroAut.codautor,10]];
else if (sreg==opCliente)
   slinha = [self somastr: 10,[self esp: tCliente.cpf,14],
   [self esp: tCliente.nome,30], [self esp: tCliente.email,30],
   [self esp: tCliente.identidade,10],[self esp: tCliente.sexo,1],
   [self esp: tCliente.telefone,17],[self esp: tCliente.dtnascimento,10],
   [self esp: tCliente.codendereco,10],[self esp: tCliente.codpais,3],
   [self esp: tCliente.codprofissao,10]];
else if (sreg==opVenda)
   slinha = [self somastr: 4,[self esp: tVenda.dthrvenda,19],
   [self esp: tVenda.cpf,14], [self esp: tVenda.isbn,13],
   [self esp: tVenda.precovenda,10]];

return slinha;
}
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
- (int) tamReg: (enum ctArqs) sreg
{ 
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

return nret;
}
/*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
- (STR) rotulo: (enum ctArqs) sreg, ...
{  
  STR sret; 
  int nNum;

va_list lparams;
va_start(lparams, sreg);
nNum = va_arg(lparams,int);
va_end(lparams);

sret = [self alocaString: TAM_MAX_STR];

if (sreg==opAssunto) {
   switch(nNum) {
     case 0: strcpy(sret, "Assunto(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "Código do assunto: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Assunto: ");
         g_nPosChave = 11;
         g_nTamChave = 30;
        } break;
   }
} else if (sreg==opAutor) {
   switch(nNum) {
     case 0: strcpy(sret, "Autor(es) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "Código do autor: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Autor: ");
         g_nPosChave = 11;
         g_nTamChave = 30;
        } break;
   }
} else if (sreg==opEditora) {
   switch(nNum) {
     case 0: strcpy(sret, "Editora(s) não encontrada(s)!"); break;
     case 1: {
         strcpy(sret, "Código da editora: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Editora: ");
         g_nPosChave = 11;
         g_nTamChave = 50;
        } break;
   }
} else if (sreg==opEndereco) {
   switch(nNum) {
     case 0: strcpy(sret, "Endereço(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "Código do endereço: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Logradouro: ");
         g_nPosChave = 11;
         g_nTamChave = 40;
        } break;
     case 3: {
         strcpy(sret, "Bairro: ");
         g_nPosChave = 51;
         g_nTamChave = 15;
        } break;
     case 4: {
         strcpy(sret, "CEP: ");
         g_nPosChave = 66;
         g_nTamChave = 8;
        } break;
     case 5: {
         strcpy(sret, "Cidade: ");
         g_nPosChave = 74;
         g_nTamChave = 30;
        } break;
     case 6: {
         strcpy(sret, "Estado: ");
         g_nPosChave = 104;
         g_nTamChave = 20;
        } break;
   }
} else if (sreg==opIdioma) {
   switch(nNum) {
     case 0: strcpy(sret, "Idioma(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "Código do idioma: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Idioma: ");
         g_nPosChave = 11;
         g_nTamChave = 20;
        } break;
   }
} else if (sreg==opPais) {
   switch(nNum) {
     case 0: strcpy(sret, "País(es) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "Código do país: ");
         g_nPosChave = 1;
         g_nTamChave = 3;
        } break;
     case 2: {
         strcpy(sret, "País: ");
         g_nPosChave = 4;
         g_nTamChave = 50;
        } break;
   }
} else if (sreg==opProfissao) {
   switch(nNum) {
     case 0: strcpy(sret, "Profissão(es) não encontrada(s)!"); break;
     case 1: {
         strcpy(sret, "Código da profissão: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Profissão: ");
         g_nPosChave = 11;
         g_nTamChave = 50;
        } break;
   }
} else if (sreg==opUsuario) {
   switch(nNum) {
     case 0: strcpy(sret, "login ou senha incorreta, tente de novo!"); break;
     case 1: {
         strcpy(sret, "Login: ");
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         strcpy(sret, "Senha: ");
         g_nPosChave = 11;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==opLivro) {
   switch(nNum) {
     case 0: strcpy(sret, "Livro(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "ISBN: ");
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         strcpy(sret, "Título: ");
         g_nPosChave = 14;
         g_nTamChave = 50;
        } break;
     case 3: {
         strcpy(sret, "Edição: ");
         g_nPosChave = 64;
         g_nTamChave = 10;
        } break;
     case 4: {
         strcpy(sret, "Ano de Publicação: ");
         g_nPosChave = 74;
         g_nTamChave = 10;
        } break;
     case 5: {
         strcpy(sret, "Código da editora: ");
         g_nPosChave = 84;
         g_nTamChave = 10;
        } break;
     case 6: {
         strcpy(sret, "Volume: ");
         g_nPosChave = 94;
         g_nTamChave = 10;
        } break;
     case 7: {
         strcpy(sret, "Código do idioma: ");
         g_nPosChave = 104;
         g_nTamChave = 10;
        } break;
     case 8: {
         strcpy(sret, "Número de páginas: ");
         g_nPosChave = 114;
         g_nTamChave = 10;
        } break;
     case 9: {
         strcpy(sret, "Preço: ");
         g_nPosChave = 124;
         g_nTamChave = 10;
        } break;
     case 10: {
          strcpy(sret, "Qtd. Estoque: ");
          g_nPosChave = 134;
          g_nTamChave = 10;
         } break;
   }
} else if (sreg==opLivroAss) {
   switch(nNum) {
     case 0: strcpy(sret, "Assunto(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "ISBN: ");
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         strcpy(sret, "Código do assunto: ");
         g_nPosChave = 14;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==opLivroAut) {
   switch(nNum) {
     case 0: strcpy(sret, "Autor(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "ISBN: ");
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         strcpy(sret, "Código do autor: ");
         g_nPosChave = 14;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==opCliente) {
   switch(nNum) {
     case 0: strcpy(sret, "Cliente(s) não encontrado(s)!"); break;
     case 1: {
         strcpy(sret, "CPF: ");
         g_nPosChave = 1;
         g_nTamChave = 14;
        } break;
     case 2: {
         strcpy(sret, "Nome: ");
         g_nPosChave = 15;
         g_nTamChave = 30;
        } break;
     case 3: {
         strcpy(sret, "E-mail: ");
         g_nPosChave = 45;
         g_nTamChave = 30;
        } break;
     case 4: {
         strcpy(sret, "Identidade: ");
         g_nPosChave = 75;
         g_nTamChave = 10;
        } break;
     case 5: {
         strcpy(sret, "Sexo: ");
         g_nPosChave = 85;
         g_nTamChave = 1;
        } break;
     case 6: {
         strcpy(sret, "Telefone: ");
         g_nPosChave = 86;
         g_nTamChave = 17;
        } break;
     case 7: {
         strcpy(sret, "Dt. Nascimento: ");
         g_nPosChave = 103;
         g_nTamChave = 10;
        } break;
     case 8: {
         strcpy(sret, "Código do endereço: ");
         g_nPosChave = 113;
         g_nTamChave = 10;
        } break;
     case 9: {
         strcpy(sret, "Código do país: ");
         g_nPosChave = 123;
         g_nTamChave = 3;
        } break;
     case 10: {
          strcpy(sret, "Código da Profissão: ");
          g_nPosChave = 126;
          g_nTamChave = 10;
        } break;
   }
} else if (sreg==opVenda) {
   switch(nNum) {
     case 0: strcpy(sret, "Venda(s) não encontrada(s)!"); break;
     case 1: {
         strcpy(sret, "Data/Hora venda: ");
         g_nPosChave = 1;
         g_nTamChave = 19;
        } break;
     case 2: {
         strcpy(sret, "CPF: ");
         g_nPosChave = 20;
         g_nTamChave = 14;
        } break;
     case 3: {
         strcpy(sret, "ISBN: ");
         g_nPosChave = 34;
         g_nTamChave = 13;
        } break;
     case 4: {
         strcpy(sret, "Preço de venda: ");
         g_nPosChave = 47;
         g_nTamChave = 10;
        } break;
   }
}
return sret;
}
/*------------------------------------------------------------------------------
Indica se continua ou não mostrando um número máximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou não
------------------------------------------------------------------------------*/
- (BOOL) ContinuaSN: (int) nlinha, ...
{ 
  BOOL bSOp, bret;
  char opCSubMenu;
  int nQtdLinha;

va_list lparams;
va_start(lparams, nlinha);
nQtdLinha = va_arg(lparams,int);
va_end(lparams);

bret = NO;
if (nlinha > 0) {
  if ((nlinha % nQtdLinha) == 0) {
      bSOp = YES;
      while(bSOp) {
       [self menu: 13];
       fflush(stdin);
       fscanf(stdin, "%s", &opCSubMenu);
       if ((opCSubMenu=='S') || (opCSubMenu=='s')) bSOp = NO;
       else if ((opCSubMenu=='N') || (opCSubMenu=='n')) {
          bret = YES;
          bSOp = NO;
       } else printf("%s\n",MSG_ERRO);
      }
  }
}
return bret;
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
- (BOOL) ListarTodos: (FILE*) sArq, ...
{ 
  enum ctArqs sreg;
  STR sChave, slinha, sres;
  BOOL bPesqRelativa, bQuebra, bAchou, bRet;
  int nPosChave, nTamChave, nTamLinha, nQtdLinha, nCont;

va_list lparams;
va_start(lparams, sArq);
sreg = va_arg(lparams,enum ctArqs);
sChave = va_arg(lparams,STR);
nPosChave = va_arg(lparams,int); 
nTamChave = va_arg(lparams,int); 
nTamLinha = va_arg(lparams,int); 
nQtdLinha = va_arg(lparams,int); 
bPesqRelativa = va_arg(lparams,int);
va_end(lparams);
  
slinha = [self alocaString: TAM_MAX_STR];
bRet = NO;
bQuebra = NO;
nCont = 0;
[self mostrarDados: sreg, "", 2];
fseek(sArq, 0, SEEK_SET);
while ((!feof(sArq)) && (bQuebra==NO)) {
  fread(slinha,1,(nTamLinha + TAM_CRLF),sArq);

  if (bPesqRelativa==YES) {
    sres = [self trim: [self copy: slinha,nPosChave,nTamChave]];
    if ([self strRelativa: sres,sChave]==YES) {
       bAchou = YES;
       bRet = YES;
       free(sres);
    } else {
       bAchou = NO;
       free(sres);
    }   
  } else {
    bAchou = YES;
    bRet = YES;
  }

  if (bAchou==YES && (!feof(sArq))) {
    [self mostrarDados: sreg, [self copy: slinha,1,nTamLinha], 3];
    nCont++;
  }

  bQuebra = [self ContinuaSN: nCont, nQtdLinha];
}
free(slinha);
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
- ListarRegLigados: (FILE*) sArq1, ...
{ 
  enum ctArqs sreg1, sreg2;
  FILE* sArq2;
  STR sChave, slinha1, sCodigo1, sCodigo2, slinha2;
  BOOL bQuebra, bRet;
  int nPosChave1, nTamChave1, nPosChave2, nTamChave2, 
      nPosChave3, nQtdLinha, nCont;
  
va_list lparams;
va_start(lparams, sArq1);
sreg1 = va_arg(lparams,enum ctArqs);
nPosChave1 = va_arg(lparams,int); 
nTamChave1 = va_arg(lparams,int); 
nPosChave2 = va_arg(lparams,int); 
nTamChave2 = va_arg(lparams,int); 
sChave = va_arg(lparams,STR);
sArq2 = va_arg(lparams,FILE*);
sreg2 = va_arg(lparams,enum ctArqs);
nPosChave3 = va_arg(lparams,int); 
nQtdLinha = va_arg(lparams,int); 
va_end(lparams);

slinha1 = [self alocaString: TAM_MAX_STR];
bRet = NO;
nCont = 0;
bQuebra = NO;
[self mostrarDados: sreg2, "", 2];
fseek(sArq1, 0, SEEK_SET);
while ((!feof(sArq1)) && (bQuebra==NO)) {
  fread(slinha1,1,([self tamReg: sreg1] + TAM_CRLF),sArq1);
  sCodigo1 = [self trim: [self copy: slinha1,nPosChave1,nTamChave1]];
  if (strcmp(sCodigo1,sChave)==0) {
    sCodigo2 = [self trim: [self copy: slinha1,nPosChave2,nTamChave2]];
    slinha2 = [self pesqArq: sArq2, sCodigo2, nPosChave3, nTamChave2, 
              [self tamReg: sreg2]];
    [self mostrarDados: sreg2, 
          [self copy: slinha2, 1, [self tamReg :sreg2] ], 3];
    bRet = YES;
    nCont++;
  }
  bQuebra = [self ContinuaSN: nCont, nQtdLinha];
}
if (bRet==NO)
   printf("%s\n",[self rotulo: sreg2,0]);
free(slinha1);   
return self;
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
- (STR) validaEntrada: (FILE*) sArq, ...
{ 
  enum ctArqs sreg;
  enum ctTipo bTipoEntrada;
  BOOL bPesqRelativa, bQuebra;
  STR sEntrada, sres, sTexto, sMsgErro, sLocal;
  int nTexto, nTentativas, ncont, nPosChave, nTamChave, nTamLinha;

va_list lparams;
va_start(lparams, sArq);
sreg = va_arg(lparams,enum ctArqs);
nTexto = va_arg(lparams,int); 
sEntrada = va_arg(lparams,STR);
nTentativas = va_arg(lparams,int); 
bPesqRelativa = va_arg(lparams,int); 
bTipoEntrada = va_arg(lparams,enum ctTipo);
va_end(lparams);

sres = [self alocaString: TAM_MAX_STR];
sLocal = [self alocaString: TAM_MAX_STR];

strcpy(sLocal, sEntrada);

nTamLinha = [self tamReg: sreg];
sMsgErro = [self rotulo: sreg,0];
sTexto = [self rotulo: sreg,nTexto];
nPosChave = g_nPosChave;
nTamChave = g_nTamChave;

ncont = 1;
bQuebra = NO;
  while ((bQuebra==NO) && (ncont <= nTentativas )) {
    if (bTipoEntrada==opTexto) {
      printf(sTexto);
      strcpy(sLocal, [self digita: TAM_MAX_STR]);
    } else if (bTipoEntrada==opNumero)
       strcpy(sLocal, [self validaNumero: sTexto,sLocal]);
    else if (bTipoEntrada==opData)
       strcpy(sLocal, [self validaDataHora: sTexto,sLocal,YES]);
    else if (bTipoEntrada==opDataHora)
       strcpy(sLocal, [self validaDataHora: sTexto,sLocal,NO]);
    else if (bTipoEntrada==opSenha) {
       strcpy(sLocal, [self digitaSenha: sTexto, 10]);
    }

    if (bPesqRelativa==YES) {
       if ([self ListarTodos: sArq, sreg, sLocal, 
            nPosChave, nTamChave, nTamLinha, QTD_MAX_LINHA, YES]==YES)
        strcpy(sres, " ");
    } else
       sres = [self pesqArq: sArq, sLocal, nPosChave, nTamChave, nTamLinha];

    if (strcmp(sres,"")==0)
       printf("%s\n",sMsgErro);
    else
       bQuebra = YES;

    ncont++;
  }
return sres;
}
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
- frmSplash
{ int cont;

 printf("*---------------------------------------" \
 "-------------------------------------*\n");
 printf("| LL    II VV   VV RRRRR  UU  UU   SSSS " \
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |\n");
 printf("| LL    II  VV VV  RR   R UU  UU  SS    " \
 " VV VV  II RR   R  TT  UU  UU  SS    |\n");
 printf("| LL    II   VVV   RRRRR  UU  UU    SS  " \
 "  VVV   II RRRRR   TT  UU  UU    SS  |\n");
 printf("| LLLLL II    V    RR   R  UUUU  SSSS   " \
 "   V    II RR   R  TT   UUUU  SSSS   |\n");
 printf("*---------------------------------------" \
 "-------------------------------------*\n");
 for(cont = 1; cont <= 18; cont++) printf("\n");
 printf(MSG_PRESS);
 fgetc(stdin);
 return self;
}
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
- frmSobre
{ int cont;
  char opcao;

 printf("*------------------------------------------------------------*\n");
 printf("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |\n");
 printf("|  LL        II   VV     VV   RR     R  UU    UU  SS         |\n");
 printf("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |\n");
 printf("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |\n");
 printf("|  LLLL      II      VVV      RR RR     UU    UU        SS   |\n");
 printf("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |\n");
 printf("|                                                            |\n");
 printf("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |\n");
 printf("|   VV     VV   II  RR     R     TT     UU    UU  SS         |\n");
 printf("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |\n");
 printf("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |\n");
 printf("|      VVV      II  RR RR        TT     UU    UU        SS   |\n");
 printf("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |\n");
 printf("|                                                            |\n");
 printf("|                                               Versao 1.0.0 |\n");
 printf("| Sistema integrante do projeto Livrus Virtus.               |\n");
 printf("| Todos os direitos reservados para Henrique F. de Souza.    |\n");
 printf("| Versao programada na linguagem Objective-C.                |\n");
 printf("*------------------------------------------------------------*\n");
 for(cont = 1; cont <= 4; cont++) printf("\n");
 printf(MSG_PRESS);
 fscanf(stdin, "%c%c", &opcao, &opcao);
 return self; 
}
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
- (BOOL) frmLogin
{ BOOL bret;
  STR slinha;

  bret = NO;
  printf("*--------------------------------------------------------------*\n");
  printf("| Login do sistema                                             |\n");
  printf("*--------------------------------------------------------------*\n");
  slinha = [self validaEntrada: tfUsuario, opUsuario, 1, tUsuario.login, 3,
        NO, opTexto];
  if (strcmp(slinha,"")!=0) {
     strcpy(slinha, [self validaEntrada: tfUsuario, opUsuario, 2, 
        tUsuario.senha, 3, NO, opSenha]);
     if (strcmp(slinha,"")!=0) {
        strcpy(tUsuario.login, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tUsuario.senha, [self trim: [self copy: slinha, 11, 10]]);
        bret = YES;
     }
  }
  printf("\n");
  return bret;
}
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*/
- menu: (int) num
{
 if (num==1) {
  printf("*--------------------------------------------------------------*\n");
  printf("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |\n");
  printf("*--------------------------------------------------------------*\n");
 } else if (num==2) {
   printf("*---------------------------------*\n");
   printf("| 01. Cadastro de Assuntos        |\n");
   printf("| 02. Cadastro de Autores         |\n");
   printf("| 03. Cadastro de Editoras        |\n");
   printf("| 04. Cadastro de Endereços       |\n");
   printf("| 05. Cadastro de Idiomas         |\n");
   printf("| 06. Cadastro de Países          |\n");
   printf("| 07. Cadastro de Profissões      |\n");
   printf("| 08. Cadastro de Clientes        |\n");
   printf("| 09. Cadastro de Livros          |\n");
   printf("| 10. Voltar ao menu              |\n");
   printf("*---------------------------------*\n");
 } else if (num==3) {
   printf("*---------------------------------*\n");
   printf("| 01. Consulta de Assuntos        |\n");
   printf("| 02. Consulta de Autores         |\n");
   printf("| 03. Consulta de Editoras        |\n");
   printf("| 04. Consulta de Endereços       |\n");
   printf("| 05. Consulta de Idiomas         |\n");
   printf("| 06. Consulta de Países          |\n");
   printf("| 07. Consulta de Profissões      |\n");
   printf("| 08. Consulta de Clientes        |\n");
   printf("| 09. Consulta de Livros          |\n");
   printf("| 10. Voltar ao menu              |\n");
   printf("*---------------------------------*\n");
 } else if (num==4) {
   printf("*---------------------------------*\n");
   printf("| 01. Vender Livros               |\n");
   printf("| 02. Vendas Realizadas           |\n");
   printf("| 03. Voltar ao menu              |\n");
   printf("*---------------------------------*\n");
 } else if (num==5) {
   printf("*---------------------------------*\n");
   printf("| 01. Alterar senha               |\n");
   printf("| 02. Sobre o sistema             |\n");
   printf("| 03. Sair do sistema             |\n");
   printf("| 04. Voltar ao menu              |\n");
   printf("*---------------------------------*\n");
 } else if (num==6) {
   printf("*--------------------------------------------------------------*\n");
   printf("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==7) {
   printf("*--------------------------------------------------------------*\n");
   printf("| (1) Salvar inclusão       (2) Voltar ao menu                 |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==8) {
   printf("*--------------------------------------------------------------*\n");
   printf("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==9) {
   printf("*--------------------------------------------------------------*\n");
   printf("| (1) Salvar alteração      (2) Voltar ao menu                 |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==10) {
   printf("*--------------------------------------------------------------*\n");
   printf("| Certeza de excluir? (S/N)                                    |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==11) {
   printf("*--------------------------------------------------------------*\n");
   printf("| Deseja sair do sistema? (S/N)                                |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==12) {
   printf("*--------------------------------------------------------------*\n");
   printf("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==13) {
   printf("*--------------------------------------------------------------*\n");
   printf("| Deseja continuar? (S/N)                                      |\n");
   printf("*--------------------------------------------------------------*\n");
 } else if (num==14) {
   printf("*--------------------------------------------------------------*\n");
   printf("| Salvar inclusão (S/N)                                        |\n");
   printf("*--------------------------------------------------------------*\n");
 }
 printf(MSG_OPCAO);
 return self;
}
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
- frmCadastros: (enum ctArqs) sreg, ... 
{ 
  enum ctAcao sacao;
  STR slinha;

va_list lparams;
va_start(lparams, sreg);
sacao = va_arg(lparams,enum ctAcao);
va_end(lparams);

if (sreg==opAssunto) {
   if (sacao==opNovo) {
      strcpy(tAssunto.codigo, [self pesqMaxCod: tfAssunto, 1, 10, [self tamReg: sreg]]);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 7, sreg];
   } else if (sacao==opPesquisar) {
     slinha = [self validaEntrada: tfAssunto,sreg,1,tAssunto.codigo,1,NO,opNumero];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opAutor) {
   if (sacao==opNovo) {
      strcpy(tAutor.codigo, [self pesqMaxCod: tfAutor, 1, 10, [self tamReg: sreg]]);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 7, sreg];
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfAutor, sreg, 1, tAutor.codigo,1,NO,opNumero];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opEditora) {
   if (sacao==opNovo) {
      strcpy(tEditora.codigo, [self pesqMaxCod: tfEditora, 1, 10, [self tamReg: sreg]]);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 7, sreg];
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfEditora,sreg,1,tEditora.codigo,1,NO,opNumero];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opEndereco) {
   if (sacao==opNovo) {
      strcpy(tEndereco.codigo, [self pesqMaxCod: tfEndereco, 1, 10, [self tamReg: sreg]]);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 7, sreg];
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfEndereco,sreg,1,tEndereco.codigo,1,
              NO,opNumero];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opIdioma) {
   if (sacao==opNovo) {
      strcpy(tIdioma.codigo, [self pesqMaxCod: tfIdioma, 1, 10, [self tamReg: sreg]]);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 7, sreg];
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfIdioma,sreg,1,tIdioma.codigo,1,NO,opNumero];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opPais) {
   if (sacao==opNovo) {
      printf([self rotulo: sreg, 1]);
      strcpy(tPais.codigo, [self digita: sizeof(tPais.codigo)]);
      slinha = [self pesqArq: tfPais, tPais.codigo, 1, 3, [self tamReg: sreg]];
      if (strcmp(slinha,"")==0) {
         [self pesqLinhaExcluida: tfPais, [self tamReg: sreg]];
         [self mostrarDados: sreg, "", 1];
         [self subMenu: 7, sreg];
      } else printf("%s\n",MSG_REGEXST);
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfPais, sreg, 1, tPais.codigo, 1, NO, opTexto];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      printf("%s%s\n",[self rotulo: sreg, 1], tPais.codigo);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opProfissao) {
   if (sacao==opNovo) {
      strcpy(tProfissao.codigo, [self pesqMaxCod: tfProfissao, 1, 10, [self tamReg: sreg]]);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 7, sreg];
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfProfissao,sreg,1,tProfissao.codigo,1,
              NO,opNumero];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opLivro) {
   if (sacao==opNovo) {
      printf([self rotulo: sreg, 1]);
      strcpy(tLivro.isbn, [self digita: sizeof(tLivro.isbn)]);
      if ([self validaISBN: tLivro.isbn]==YES) {
          slinha = [self pesqArq: tfLivro, tLivro.isbn, 1, 13, [self tamReg: sreg]];
          if (strcmp(slinha,"")==0) {
             [self pesqLinhaExcluida: tfLivro, [self tamReg: sreg]];
             [self mostrarDados: sreg, "", 1];
             [self subMenu: 7, sreg];
             [self frmCadLigados: opLivroAss, opNovo, tLivro.isbn];
             [self frmCadLigados: opLivroAut, opNovo, tLivro.isbn];
          } else printf("%s\n",MSG_REGEXST);
      } else printf("%s\n",MSG_ISBNINV);
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfLivro, sreg, 1, tLivro.isbn, 1,NO,opTexto];
      if (strcmp(slinha,"")!=0) {
         [self mostrarDados: sreg, "", 2];
         [self mostrarDados: sreg, slinha, 3];
         [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      printf("%s%s\n",[self rotulo: sreg, 1], tLivro.isbn);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
      [self frmCadLigados: opLivroAss, opExcluir, tLivro.isbn];
      printf("%s\n","Assuntos dos livros excluídos, inclua novos!");
      [self frmCadLigados: opLivroAss, opNovo, tLivro.isbn];
      [self frmCadLigados: opLivroAut, opExcluir, tLivro.isbn];
      printf("%s\n","Autores dos livros excluídos, inclua novos!");
      [self frmCadLigados: opLivroAut, opNovo, tLivro.isbn];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
      printf("%s\n","Assuntos dos livros sendo excluídos!");
      [self frmCadLigados: opLivroAss, opExcluir, tLivro.isbn];
      printf("%s\n","Autores dos livros sendo excluídos!");
      [self frmCadLigados: opLivroAut, opExcluir, tLivro.isbn];
   }
} else if (sreg==opCliente) {
   if (sacao==opNovo) {
      printf([self rotulo: sreg, 1]);
      strcpy(tCliente.cpf, [self digita: sizeof(tCliente.cpf)]);
      if ([self validaCPF: tCliente.cpf]==YES) {
          slinha = [self pesqArq: tfCliente, tCliente.cpf, 1, 14, [self tamReg: sreg]];
          if (strcmp(slinha,"")==0) {
             [self pesqLinhaExcluida: tfCliente, [self tamReg: sreg]];
             [self mostrarDados: sreg, "", 1];
             [self subMenu: 7, sreg];
          } else printf("%s\n",MSG_REGEXST);
      } else printf("%s\n",MSG_CPFINV);
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfCliente, sreg, 1, tCliente.cpf,1,NO,opTexto];
      if (strcmp(slinha,"")!=0) {
         [self mostrarDados: sreg, "", 2];
         [self mostrarDados: sreg, slinha, 3];
         [self subMenu: 8, sreg];
      }
   } else if (sacao==opAlterar) {
      printf("%s%s\n",[self rotulo: sreg, 1], tCliente.cpf);
      [self mostrarDados: sreg, "", 1];
      [self subMenu: 9, sreg];
   } else if (sacao==opExcluir) {
      [self subMenu: 10, sreg];
   }
} else if (sreg==opVenda) {
   if (sacao==opNovo) {
      strcpy(tVenda.dthrvenda, [self retDataHora]);
      printf("%s%s\n",[self rotulo: sreg, 1], tVenda.dthrvenda);
      slinha = [self pesqArq: tfVenda, tVenda.dthrvenda, 1, 19, [self tamReg: sreg]];
      if (strcmp(slinha,"")==0) {
         slinha = [self validaEntrada: tfCliente,opCliente,1,tVenda.cpf,3,
                 NO,opTexto];
         if (strcmp(slinha,"")!=0) {
            strcpy(tVenda.cpf, [self trim: [self copy: slinha,1,14]]);
            if ([self validaCPF: tVenda.cpf]==YES) {
               printf(" %s",[self rotulo: opCliente, 2]); /* Nome */
               printf("%s\n",[self copy: slinha, g_nPosChave, g_nTamChave]);
               [self frmCadLigados: opVenda, opNovo, tVenda.cpf];
            } else printf("%s\n",MSG_CPFINV);
         }
      } else printf("%s\n",MSG_REGEXST);
   } else if (sacao==opPesquisar) {
      slinha = [self validaEntrada: tfVenda, sreg, 1, tVenda.dthrvenda,1,
              NO,opDataHora];
      if (strcmp(slinha,"")!=0) {
        [self mostrarDados: sreg, "", 2];
        [self mostrarDados: sreg, slinha, 3];
        [self subMenu: 8, sreg];
      }
   }
}
return self;
}
/*------------------------------------------------------------------------------
Realiza as consultas de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
- frmConsultas: (enum ctArqs) sreg, ...
{ 
 enum ctAcao sacao;
 STR slinha;

va_list lparams;
va_start(lparams, sreg);
sacao = va_arg(lparams,enum ctAcao);
va_end(lparams);

slinha = [self alocaString: TAM_MAX_STR];

if (sreg==opAssunto) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfAssunto,sreg,2,tAssunto.assunto,1,YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfAssunto, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opAutor) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfAutor,sreg, 2, tAutor.autor, 1, YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfAutor, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opEditora) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfEditora,sreg,2,tEditora.editora,1,YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfEditora, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opEndereco) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfEndereco,sreg,2,tEndereco.logradouro,1,
              YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfEndereco, sreg, "", 0, 0, [self tamReg: sreg],
         3, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opIdioma) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfIdioma, sreg, 2, tIdioma.idioma,1,YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfIdioma, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opPais) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfPais, sreg, 2, tPais.pais, 1, YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfPais, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opProfissao) {
   if (sacao==opPesquisar)
     slinha = [self validaEntrada: tfProfissao,sreg,2,tProfissao.profissao,1,
             YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfProfissao, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opLivro) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfLivro, sreg, 2, tLivro.titulo, 1, YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfLivro, sreg, "", 0, 0, [self tamReg: sreg],
        1, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opCliente) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfCliente, sreg, 2, tCliente.nome,1,YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfCliente, sreg, "", 0, 0, [self tamReg: sreg],
        1, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
} else if (sreg==opVenda) {
   if (sacao==opPesquisar)
      slinha = [self validaEntrada: tfVenda, sreg, 2, tVenda.cpf, 1, YES,opTexto];
   else if (sacao==opListarTodos) {
      if ([self ListarTodos: tfVenda, sreg, "", 0, 0, [self tamReg: sreg],
        QTD_MAX_LINHA, NO] == NO)
        printf("%s\n",[self rotulo: sreg, 0]);
   }
}
return self;
}
/*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*/
- frmAlterarSenha
{ 
  BOOL bQuebra;
  STR sres, sSenhaAtual, sNovaSenha, sConfirmaSenha;
  int nopcao;

sSenhaAtual = [self alocaString: TAM_MAX_STR];
sNovaSenha = [self alocaString: TAM_MAX_STR];
sConfirmaSenha = [self alocaString: TAM_MAX_STR];

printf("%s%s\n",[self rotulo: opUsuario, 1], tUsuario.login);
nopcao = 1;
bQuebra = NO;
while (bQuebra==NO) {
  switch(nopcao) {
   case 1: {
       strcpy(sSenhaAtual, [self digitaSenha: "Senha Atual: ", 10]);
       if (strcmp(sSenhaAtual,tUsuario.senha)!=0) {
          printf("%s\n",MSG_SENCONFERE);
          bQuebra = YES;
       } else nopcao = 2;
      } break;
   case 2: {
       strcpy(sNovaSenha, [self digitaSenha: "Nova Senha: ", 10]);
       strcpy(sConfirmaSenha, [self digitaSenha: "Confirma Senha: ", 10]);
       if (strcmp(sNovaSenha,sConfirmaSenha)!=0) {
          printf("%s\n",MSG_SENCONFIRM);
          bQuebra = YES;
       } else nopcao = 3;
      } break;
   case 3: {
       sres = [self pesqArq: tfUsuario, tUsuario.login, 1, 10, [self tamReg: opUsuario]];
       if (strcmp(sres,"")==0)
         printf("%s\n",MSG_LOGINENCON);
       else {
         strcpy(tUsuario.senha, sConfirmaSenha);
         [self subMenu: 9,opUsuario];
         bQuebra = YES;
       }
       free(sres);
      } break;
  }
}
free(sSenhaAtual);
free(sNovaSenha);
free(sConfirmaSenha);
return self;
}
/*------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
- btnAcao: (enum ctArqs) sreg, ...
{
  enum ctAcao sacao;

va_list lparams;
va_start(lparams, sreg);
sacao = va_arg(lparams,enum ctAcao);
va_end(lparams);

if (sreg==opAssunto) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfAssunto, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfAssunto, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfAssunto, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opAutor) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfAutor, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfAutor, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfAutor, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opEditora) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfEditora, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfEditora, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfEditora, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opEndereco) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfEndereco, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfEndereco, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfEndereco, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opIdioma) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfIdioma, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfIdioma, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfIdioma, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opPais) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfPais, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfPais, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfPais, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opProfissao) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfProfissao, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfProfissao, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
     [self escreveArq: tfProfissao, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opLivro) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfLivro, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfLivro, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfLivro, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opLivroAss) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfLivroAss, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfLivroAss, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfLivroAss, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opLivroAut) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfLivroAut, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfLivroAut, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfLivroAut, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opCliente) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfCliente, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfCliente, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfCliente, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opVenda) {
   if (sacao==opSalvarInclusao)
      [self escreveArq: tfVenda, [self LinhaReg: sreg], MSG_REGINC, MSG_REGNINC];
   else if (sacao==opSalvarAlteracao)
      [self escreveArq: tfVenda, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
   else if (sacao==opConfirmaExclusao)
      [self escreveArq: tfVenda, [self repete: "*",[self tamReg: sreg]], MSG_REGEXC, MSG_REGNEXC];
} else if (sreg==opUsuario) {
   if (sacao==opSalvarAlteracao)
      [self escreveArq: tfUsuario, [self LinhaReg: sreg], MSG_REGALT, MSG_REGNALT];
}
return self;
}
/*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
- subMenu: (int) nmenu, ...
{ 
  enum ctArqs sreg;
  int opSubMenu;
  char opCSubMenu;
  BOOL bSOp;

va_list lparams;
va_start(lparams, nmenu);
sreg = va_arg(lparams,enum ctArqs);
va_end(lparams);

bSOp = YES;
switch(nmenu) {
 case 6:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%d", &opSubMenu);
     switch(opSubMenu) {
      case 1: [self frmCadastros: sreg, opNovo]; break;
      case 2: [self frmCadastros: sreg, opPesquisar]; break;
      case 3: bSOp = NO; break;
	  default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 7:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%d", &opSubMenu);
     switch(opSubMenu) {
      case 1: { [self btnAcao: sreg, opSalvarInclusao]; bSOp = NO; } break;
      case 2: bSOp = NO; break;
	  default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 8:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: { [self frmCadastros: sreg, opAlterar]; bSOp = NO; } break;
      case 2: { [self frmCadastros: sreg, opExcluir]; bSOp = NO; } break;
      case 3: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 9:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: { [self btnAcao: sreg, opSalvarAlteracao]; bSOp = NO; } break;
      case 2: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 10:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%s", &opCSubMenu);     
     if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
        [self btnAcao: sreg, opConfirmaExclusao];
        bSOp = NO;
     } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = NO;
     else printf("%s\n",MSG_ERRO);
    }
   } break;
 case 12:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: [self frmConsultas: sreg, opPesquisar]; break;
      case 2: [self frmConsultas: sreg, opListarTodos]; break;
      case 3: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 14:{
    while(bSOp) {
     [self menu: nmenu];
     fscanf(stdin, "%s", &opCSubMenu);     
     if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
        [self btnAcao: sreg, opSalvarInclusao];
        bSOp = NO;
        g_SalvarInclusao = YES;
     } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = NO;
     else printf("%s\n",MSG_ERRO);
    }
   } break;
}
return self;
}
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*/
- usaMenu: (int) num
{ int opSubMenu;
  BOOL bSOp;
  char opSair;

 bSOp = YES;
 if (num == 1) { /* Cadastros */
   while(bSOp) {
     [self menu: 2];
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: [self subMenu: 6, opAssunto]; break;
      case 2: [self subMenu: 6, opAutor]; break;
      case 3: [self subMenu: 6, opEditora]; break;
      case 4: [self subMenu: 6, opEndereco]; break;
      case 5: [self subMenu: 6, opIdioma]; break;
      case 6: [self subMenu: 6, opPais]; break;
      case 7: [self subMenu: 6, opProfissao]; break;
      case 8: [self subMenu: 6, opCliente]; break;
      case 9: [self subMenu: 6, opLivro]; break;
      case 10: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 } else if (num == 2) { /* Pesquisas */
   while(bSOp) {
     [self menu: 3];
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: [self subMenu: 12, opAssunto]; break;
      case 2: [self subMenu: 12, opAutor]; break;
      case 3: [self subMenu: 12, opEditora]; break;
      case 4: [self subMenu: 12, opEndereco]; break;
      case 5: [self subMenu: 12, opIdioma]; break;
      case 6: [self subMenu: 12, opPais]; break;
      case 7: [self subMenu: 12, opProfissao]; break;
      case 8: [self subMenu: 12, opCliente]; break;
      case 9: [self subMenu: 12, opLivro]; break;
      case 10: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 } else if (num == 3) { /* Vendas */
   while(bSOp) {
     [self menu: 4];
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: [self subMenu: 6, opVenda]; break;
      case 2: [self subMenu: 12, opVenda]; break;
      case 3: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 } else if (num == 4) { /* Opcoes */
   while(bSOp) {
     [self menu: 5];
     fscanf(stdin, "%d", &opSubMenu);
     fflush(stdin);     
     switch(opSubMenu) {
      case 1: [self frmAlterarSenha]; break;
      case 2: [self frmSobre]; break;
      case 3: {
           [self menu: 11];
           fscanf(stdin, "%s", &opSair);           
           if ((opSair=='S') || (opSair=='s')) {
              [self fechaArqs];
              exit(0);
           }
         } break;
      case 4: bSOp = NO; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 }
return self;
}
/*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*/
- mostrarDados: (enum ctArqs) sreg, ...
{ 
 STR slinha; 
 int nOpcao;

va_list lparams;
va_start(lparams, sreg);
slinha = va_arg(lparams,STR);
nOpcao = va_arg(lparams,int);
va_end(lparams);

if (sreg==opAssunto) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",[self rotulo: sreg, 1], tAssunto.codigo);
        printf([self rotulo: sreg, 2]);
        strcpy(tAssunto.assunto, [self digita: sizeof(tAssunto.assunto)]);
       } break;
    case 2: {
        printf("Código     Assunto\n");
        printf("------     -------\n");
       } break;
    case 3: {
        strcpy(tAssunto.codigo, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tAssunto.assunto, [self trim: [self copy: slinha, 11, 30]]);
        printf("%s %s\n",[self esp: tAssunto.codigo,10],[self esp: tAssunto.assunto,30]);
       } break;
   }
} else if (sreg==opAutor) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",[self rotulo: sreg, 1], tAutor.codigo);
        printf([self rotulo: sreg, 2]);
        strcpy(tAutor.autor, [self digita: sizeof(tAutor.autor)]);
       } break;
    case 2: {
        printf("Código     Autor\n");
        printf("------     -----\n");
       } break;
    case 3: {
        strcpy(tAutor.codigo, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tAutor.autor, [self trim: [self copy: slinha, 11, 30]]);
        printf("%s %s\n",[self esp: tAutor.codigo,10],[self esp: tAutor.autor,30]);
       } break;
   }
} else if (sreg==opEditora) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",[self rotulo: sreg, 1], tEditora.codigo);
        printf([self rotulo: sreg, 2]);
        strcpy(tEditora.editora, [self digita: sizeof(tEditora.editora)]);
       } break;
    case 2: {
        printf("Código     Editora\n");
        printf("------     -------\n");
       } break;
    case 3: {
        strcpy(tEditora.codigo, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tEditora.editora, [self trim: [self copy: slinha, 11, 50]]);
        printf("%s %s\n",[self esp: tEditora.codigo,10],[self esp: tEditora.editora,50]);
       } break;
   }
} else if (sreg==opEndereco) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s",[self rotulo: sreg, 1], tEndereco.codigo);
        printf([self rotulo: sreg, 2]);
        strcpy(tEndereco.logradouro, [self digita: sizeof(tEndereco.logradouro)]);
        printf([self rotulo: sreg, 3]);
        strcpy(tEndereco.bairro, [self digita: sizeof(tEndereco.bairro)]);
        printf([self rotulo: sreg, 4]);
        strcpy(tEndereco.cep, [self digita: sizeof(tEndereco.cep)]);
        printf([self rotulo: sreg, 5]);
        strcpy(tEndereco.cidade, [self digita: sizeof(tEndereco.cidade)]);
        printf([self rotulo: sreg, 6]);
        strcpy(tEndereco.estado, [self digita: sizeof(tEndereco.estado)]);
       } break;
    case 3: {
        strcpy(tEndereco.codigo, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tEndereco.logradouro, [self trim: [self copy: slinha, 11, 40]]);
        strcpy(tEndereco.bairro, [self trim: [self copy: slinha, 51, 15]]);
        strcpy(tEndereco.cep, [self trim: [self copy: slinha, 66, 8]]);
        strcpy(tEndereco.cidade, [self trim: [self copy: slinha, 74, 30]]);
        strcpy(tEndereco.estado, [self trim: [self copy: slinha, 104, 20]]);
        printf("--------------------\n");
        printf("%s%s\n",[self rotulo: sreg, 1], tEndereco.codigo);
        printf("%s%s\n",[self rotulo: sreg, 2], tEndereco.logradouro);
        printf("%s%s\n",[self rotulo: sreg, 3], tEndereco.bairro);
        printf("%s%s\n",[self rotulo: sreg, 4], tEndereco.cep);
        printf("%s%s\n",[self rotulo: sreg, 5], tEndereco.cidade);
        printf("%s%s\n",[self rotulo: sreg, 6], tEndereco.estado);
       } break;
   }
} else if (sreg==opIdioma) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",[self rotulo: sreg, 1], tIdioma.codigo);
        printf([self rotulo: sreg, 2]);
        strcpy(tIdioma.idioma, [self digita: sizeof(tIdioma.idioma)]);
       } break; 
    case 2: {
        printf("Código     Idioma\n");
        printf("------     ------\n");
       } break;
    case 3: {
        strcpy(tIdioma.codigo, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tIdioma.idioma, [self trim: [self copy: slinha, 11, 20]]);
        printf("%s %s\n",[self esp: tIdioma.codigo,10],[self esp: tIdioma.idioma,20]);
       } break;
   }
} else if (sreg==opPais) {
   switch(nOpcao) {
    case 1: {
        printf([self rotulo: sreg, 2]);
        strcpy(tPais.pais, [self digita: sizeof(tPais.pais)]);
       } break;
    case 2: {
        printf("Código País\n");
        printf("------ ----\n");
       } break;
    case 3: {
        strcpy(tPais.codigo, [self trim: [self copy: slinha, 1, 3]]);
        strcpy(tPais.pais, [self trim: [self copy: slinha, 4, 50]]);
        printf("%s    %s\n",[self esp: tPais.codigo,3],[self esp: tPais.pais,50]);
       } break;
   }
} else if (sreg==opProfissao) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",[self rotulo: sreg, 1], tProfissao.codigo);
        printf([self rotulo: sreg, 2]);
        strcpy(tProfissao.profissao, [self digita: sizeof(tProfissao.profissao)]);
       } break;
    case 2: {
        printf("Código     Profissão\n");
        printf("------     ---------\n");
       } break;
    case 3: {
        strcpy(tProfissao.codigo, [self trim: [self copy: slinha, 1, 10]]);
        strcpy(tProfissao.profissao, [self trim: [self copy: slinha, 11, 50]]);
        printf("%s %s\n",[self esp: tProfissao.codigo,10],
                [self esp: tProfissao.profissao,50]);
       } break;
   }
} else if (sreg==opLivro) {
   switch(nOpcao) {
    case 1: {
        printf([self rotulo: sreg, 2]);
        strcpy(tLivro.titulo, [self digita: sizeof(tLivro.titulo)]);
        strcpy(tLivro.edicao, [self validaNumero: [self rotulo: sreg, 3], tLivro.edicao]);
        strcpy(tLivro.anopubli, [self validaNumero: [self rotulo: sreg, 4], tLivro.anopubli]);
        [self mostrarSubDados: opLivro, opEditora, NO];
        strcpy(tLivro.volume, [self validaNumero: [self rotulo: sreg, 6], tLivro.volume]);
        [self mostrarSubDados: opLivro, opIdioma, NO];
        strcpy(tLivro.npaginas, [self validaNumero: [self rotulo: sreg, 8], tLivro.npaginas]);
        strcpy(tLivro.preco, [self validaNumero: [self rotulo: sreg, 9], tLivro.preco]);
        strcpy(tLivro.qtdestoque, [self validaNumero: [self rotulo: sreg, 10], 
        tLivro.qtdestoque]);
       } break;
    case 3: {
        strcpy(tLivro.isbn, [self trim: [self copy: slinha, 1, 13]]);
        strcpy(tLivro.titulo, [self trim: [self copy: slinha, 14, 50]]);
        strcpy(tLivro.edicao, [self trim: [self copy: slinha, 64, 10]]);
        strcpy(tLivro.anopubli, [self trim: [self copy: slinha, 74, 10]]);
        strcpy(tLivro.codeditora, [self trim: [self copy: slinha, 84, 10]]);
        strcpy(tLivro.volume, [self trim: [self copy: slinha, 94, 10]]);
        strcpy(tLivro.codidioma, [self trim: [self copy: slinha, 104, 10]]);
        strcpy(tLivro.npaginas, [self trim: [self copy: slinha, 114, 10]]);
        strcpy(tLivro.preco, [self trim: [self copy: slinha, 124, 10]]);
        strcpy(tLivro.qtdestoque, [self trim: [self copy: slinha, 134, 10]]);
        printf("--------------------\n");
        printf("%s%s\n",[self rotulo: sreg, 1], tLivro.isbn);
        printf("%s%s\n",[self rotulo: sreg, 2], tLivro.titulo);
        printf("%s%s\n",[self rotulo: sreg, 3], tLivro.edicao);
        printf("%s%s\n",[self rotulo: sreg, 4], tLivro.anopubli);
        printf("%s%s\n",[self rotulo: sreg, 5], tLivro.codeditora);
        [self mostrarSubDados: opLivro, opEditora, YES];
        printf("%s%s\n",[self rotulo: sreg, 6], tLivro.volume);
        printf("%s%s\n",[self rotulo: sreg, 7], tLivro.codidioma);
        [self mostrarSubDados: opLivro, opIdioma, YES];
        printf("%s%s\n",[self rotulo: sreg, 8], tLivro.npaginas);
        printf("%s%s\n",[self rotulo: sreg, 9], tLivro.preco);
        printf("%s%s\n",[self rotulo: sreg, 10], tLivro.qtdestoque);
        [self ListarRegLigados: tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
                         tfAssunto, opAssunto, 1, 4];
        [self ListarRegLigados: tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
                         tfAutor, opAutor, 1, 4];
       } break;
   }
} else if (sreg==opCliente) {
   switch(nOpcao) {
    case 1: {
        printf([self rotulo: sreg, 2]);
        strcpy(tCliente.nome, [self digita: sizeof(tCliente.nome)]);
        printf([self rotulo: sreg, 3]);
        strcpy(tCliente.email, [self digita: sizeof(tCliente.email)]);
        printf([self rotulo: sreg, 4]);
        strcpy(tCliente.identidade, [self digita: sizeof(tCliente.identidade)]);
        printf([self rotulo: sreg, 5]);
        strcpy(tCliente.sexo, [self digita: sizeof(tCliente.sexo)]);
        printf([self rotulo: sreg, 6]);
        strcpy(tCliente.telefone, [self digita: sizeof(tCliente.telefone)]);
        strcpy(tCliente.dtnascimento, [self validaDataHora: 
              [self rotulo: sreg, 7], tCliente.dtnascimento, YES]);
        [self mostrarSubDados: opCliente, opEndereco, NO];
        [self mostrarSubDados: opCliente, opPais, NO];
        [self mostrarSubDados: opCliente, opProfissao, NO];
       } break;
    case 3: {
        strcpy(tCliente.cpf, [self trim: [self copy: slinha, 1, 14]]);
        strcpy(tCliente.nome, [self trim: [self copy: slinha, 15, 30]]);
        strcpy(tCliente.email, [self trim: [self copy: slinha, 45, 30]]);
        strcpy(tCliente.identidade, [self trim: [self copy: slinha, 75, 10]]);
        strcpy(tCliente.sexo, [self trim: [self copy: slinha, 85, 1]]);
        strcpy(tCliente.telefone, [self trim: [self copy: slinha, 86, 17]]);
        strcpy(tCliente.dtnascimento, [self trim: [self copy: slinha, 103, 10]]);
        strcpy(tCliente.codendereco, [self trim: [self copy: slinha, 113, 10]]);
        strcpy(tCliente.codpais, [self trim: [self copy: slinha, 123, 3]]);
        strcpy(tCliente.codprofissao, [self trim: [self copy: slinha, 126, 10]]);
        printf("--------------------\n");
        printf("%s%s\n",[self rotulo: sreg, 1], tCliente.cpf);
        printf("%s%s\n",[self rotulo: sreg, 2], tCliente.nome);
        printf("%s%s\n",[self rotulo: sreg, 3], tCliente.email);
        printf("%s%s\n",[self rotulo: sreg, 4], tCliente.identidade);
        printf("%s%s\n",[self rotulo: sreg, 5], tCliente.sexo);
        printf("%s%s\n",[self rotulo: sreg, 6], tCliente.telefone);
        printf("%s%s\n",[self rotulo: sreg, 7], tCliente.dtnascimento);
        printf("%s%s\n",[self rotulo: sreg, 8], tCliente.codendereco);
        [self mostrarSubDados: opCliente, opEndereco, YES];
        printf("%s%s\n",[self rotulo: sreg, 9], tCliente.codpais);
        [self mostrarSubDados: opCliente, opPais, YES];
        printf("%s%s\n",[self rotulo: sreg, 10], tCliente.codprofissao);
        [self mostrarSubDados: opCliente, opProfissao, YES];
       } break;
   }
} else if (sreg==opVenda) {
   switch(nOpcao) {
    case 1: [self mostrarSubDados: opVenda,opVenda, NO]; break;
    case 2: {
        printf("DataHoraVenda       CPF            ISBN          " \
        "PreçoVenda\n");
        printf("-------------       ---            ----          " \
        "----------\n");
       } break;
    case 3: {
        strcpy(tVenda.dthrvenda, [self trim: [self copy: slinha, 1, 19]]);
        strcpy(tVenda.cpf, [self trim: [self copy: slinha, 20, 14]]);
        strcpy(tVenda.isbn, [self trim: [self copy: slinha, 34, 13]]);
        strcpy(tVenda.precovenda, [self trim: [self copy: slinha, 47, 10]]);
        printf("%s %s %s %s\n",[self esp: tVenda.dthrvenda,19],[self esp: tVenda.cpf,14],
        [self esp: tVenda.isbn,13],[self esp: tVenda.precovenda,10]);
       } break;
   }
}
return self;
}
/*------------------------------------------------------------------------------
Mostra as sub informções de entrada e de saída.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai só mostrar na saída
------------------------------------------------------------------------------*/
- mostrarSubDados: (enum ctArqs) sreg, ...
{ 
 enum ctArqs ssubreg;
 BOOL bSoMostrar;
 STR sRegistro, sPreco;
 int nMaxTentativas;

va_list lparams;
va_start(lparams, sreg);
ssubreg = va_arg(lparams,enum ctArqs);
bSoMostrar = va_arg(lparams,int);
va_end(lparams);

nMaxTentativas = 3;
if (sreg==opLivro) {
  if (ssubreg==opEditora) {
    if (bSoMostrar==YES)
       sRegistro = [self pesqArq: tfEditora,tLivro.codeditora,1,10,[self tamReg: opEditora]];
    else
       sRegistro = [self validaEntrada: tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,NO,opNumero];
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tLivro.codeditora, [self trim: [self copy: sRegistro,1,10]]);
      printf(" %s",[self rotulo: opEditora, 2]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
    }
  } else if (ssubreg==opIdioma) {
    if (bSoMostrar==YES)
       sRegistro = [self pesqArq: tfIdioma, tLivro.codidioma, 1, 10,[self tamReg: opIdioma]];
    else
       sRegistro = [self validaEntrada: tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,NO,opNumero];
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tLivro.codidioma, [self trim: [self copy: sRegistro,1,10]]);
      printf(" %s",[self rotulo: opIdioma, 2]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
    }
  }
} else if (sreg==opCliente) {
  if (ssubreg==opEndereco) {
    if (bSoMostrar==YES)
       sRegistro = [self pesqArq: tfEndereco, tCliente.codendereco, 1, 10,
                  [self tamReg: opEndereco]];
    else
       sRegistro = [self validaEntrada: tfEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,NO,opNumero];
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tCliente.codendereco, [self trim: [self copy: sRegistro,1,10]]);
      printf(" %s",[self rotulo: opEndereco, 2]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
      printf(" %s",[self rotulo: opEndereco, 3]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
      printf(" %s",[self rotulo: opEndereco, 4]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
      printf(" %s",[self rotulo: opEndereco, 5]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
      printf(" %s",[self rotulo: opEndereco, 6]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
    }
  } else if (ssubreg==opPais) {
    if (bSoMostrar==YES)
       sRegistro = [self pesqArq: tfPais, tCliente.codpais, 1, 3, [self tamReg: opPais]];
    else
       sRegistro = [self validaEntrada: tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,NO,opTexto];
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tCliente.codpais, [self trim: [self copy: sRegistro,1,3]]);
      printf(" %s",[self rotulo: opPais, 2]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
    }
  } else if (ssubreg==opProfissao) {
    if (bSoMostrar==YES)
       sRegistro = [self pesqArq: tfProfissao, tCliente.codprofissao, 1, 10,
                  [self tamReg: opProfissao]];
    else
       sRegistro = [self validaEntrada: tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,NO,opNumero];
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tCliente.codprofissao, [self trim: [self copy: sRegistro,1,10]]);
      printf(" %s",[self rotulo: opProfissao, 2]);
      printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
    }
  }
} else if (sreg==opVenda) {
  sRegistro = [self pesqArq: tfLivro, tVenda.isbn, 1, 13, [self tamReg: opLivro]];
  if (strcmp(sRegistro,"")!=0) {
    printf(" %s",[self rotulo: opLivro, 2]); /* Titulo */
    printf("%s\n",[self copy: sRegistro, g_nPosChave, g_nTamChave]);
    printf(" %s",[self rotulo: opLivro, 9]); /* Preco */
    sPreco = [self copy: sRegistro, g_nPosChave, g_nTamChave];
    g_nPreco = atof(sPreco);
    printf("%s\n",sPreco);
  }
}
return self;
}
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*/
- frmCadLigados: (enum ctArqs) sreg, ...
{ 
  enum ctAcao sacao;
  int nQtd, nCont, nQtdEstoque;
  double nTotalPreco;
  STR sCodigo, slinha, sTotalPreco, sPreco, sQtd;

va_list lparams;
va_start(lparams, sreg);
sacao = va_arg(lparams,enum ctAcao);
sCodigo = va_arg(lparams,STR);
va_end(lparams);

sQtd = [self alocaString: TAM_MAX_STR];

if (sacao==opNovo) {
  nCont = 1;
  if (sreg==opLivroAss) {
    strcpy(sQtd, [self validaNumero: "Quantos assuntos quer cadastrar?: ",sQtd]);
    nQtd = atoi(sQtd);
    fseek(tfLivroAss, 0, SEEK_SET);
    while (nCont <= nQtd) {
      strcpy(tLivroAss.isbn, sCodigo);
      printf([self rotulo: opLivroAss, 2]);
      strcpy(tLivroAss.codassunto, [self digita: sizeof(tLivroAss.codassunto)]);
      slinha = [self pesqArq: tfAssunto, tLivroAss.codassunto,1,10,[self tamReg: opAssunto]];
      printf(" %s",[self rotulo: opAssunto, 2]);
      printf("%s\n",[self copy: slinha, g_nPosChave, g_nTamChave]);
      [self pesqLinhaExcluida: tfLivroAss, [self tamReg: sreg]];
      [self subMenu: 14, sreg];
      nCont++;
    }
  } else if (sreg==opLivroAut) {
    strcpy(sQtd, [self validaNumero: "Quantos autores quer cadastrar?: ",sQtd]);
    nQtd = atoi(sQtd);
    fseek(tfLivroAut, 0, SEEK_SET);
    while (nCont <= nQtd) {
      strcpy(tLivroAut.isbn, sCodigo);
      printf([self rotulo: opLivroAut, 2]);
      strcpy(tLivroAut.codautor, [self digita: sizeof(tLivroAut.codautor)]);
      slinha = [self pesqArq: tfAutor, tLivroAut.codautor,1,10,[self tamReg: opAutor]];
      printf(" %s",[self rotulo: opAutor, 2]);
      printf("%s\n",[self copy: slinha, g_nPosChave, g_nTamChave]);
      [self pesqLinhaExcluida: tfLivroAut, [self tamReg: sreg]];
      [self subMenu: 14, sreg];
      nCont++;
    }
  } else if (sreg==opVenda) {
    sPreco = [self alocaString: TAM_MAX_STR];
    sTotalPreco = [self alocaString: TAM_MAX_STR];    
    strcpy(sQtd, [self validaNumero: "Quantos livros quer vender?: ",sQtd]);
    nQtd = atoi(sQtd);
    nTotalPreco = 0;
    while (nCont <= nQtd) {
      slinha = [self validaEntrada: tfLivro,opLivro,1,tVenda.isbn,3,NO,opTexto];
      if (strcmp(slinha,"")!=0) {
        strcpy(tVenda.isbn, [self trim: [self copy: slinha,1,13]]);
        if ([self validaISBN: tVenda.isbn]==YES) {
          [self mostrarDados: sreg, "", 1];
          strcpy(tLivro.qtdestoque, [self trim: [self copy: slinha,134,10]]);
          nQtdEstoque = atoi(tLivro.qtdestoque);
          if (nQtdEstoque > 0) {
             nTotalPreco = nTotalPreco + g_nPreco;
             /* sPreco = fcvt(g_nPreco, 7, &decimal, &sinal); */  
             gcvt(g_nPreco, 7, sPreco);
             strcpy(tVenda.precovenda, sPreco);
             g_SalvarInclusao = NO;
             [self subMenu: 14, sreg];
             if (g_SalvarInclusao==YES) {
                slinha = [self pesqArq: tfLivro, tVenda.isbn, 1, 13, 
                            [self tamReg: opLivro]];
                if (strcmp(slinha,"")!=0) {
                   nQtdEstoque = nQtdEstoque-1;
                   strcpy(tLivro.qtdestoque, 
                          [self itoa: nQtdEstoque,tLivro.qtdestoque, 10]);
                   slinha= (STR) strcat([self copy: slinha,1,133],
                                        [self esp: tLivro.qtdestoque,10]);
                   [self escreveArq: tfLivro, slinha, "", ""];
                }
             }
             nCont++;
          } else printf("%s\n",MSG_SEMESTOQUE);
        } else printf("%s\n",MSG_ISBNINV);
      }
    }
    nTotalPreco = atof(sTotalPreco);
    printf("Total de %s%f\n",[self rotulo: sreg,4],nTotalPreco);
    free(sTotalPreco);
    free(sPreco);
  }
} else if (sacao==opExcluir) {
  if (sreg==opLivroAss) {
     [self ExcluirRegLigados: tfLivroAss, sreg, 1, 13, sCodigo];
  } else if (sreg==opLivroAut) {
     [self ExcluirRegLigados: tfLivroAut, sreg, 1, 13, sCodigo];
  }
}
return self;
}
/*------------------------------------------------------------------------------
Realiza a exclusão dos arquivos de ligação.
sArq - o arquivo de ligação
sreg - o tipo de arquivo de ligação
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------*/
- ExcluirRegLigados: (FILE*) sArq, ...
{ 
  enum ctArqs sreg;
  int nPosChave, nTamChave;
  STR sChave, slinha, sCodigo;

va_list lparams;
va_start(lparams, sArq);
sreg = va_arg(lparams,enum ctArqs);
nPosChave = va_arg(lparams,int);
nTamChave = va_arg(lparams,int);
sChave = va_arg(lparams,STR);
va_end(lparams);

slinha = [self alocaString: TAM_MAX_REG];

  fseek(sArq, 0, SEEK_SET);
  while (!feof(sArq)) {
    fread(slinha,1,([self tamReg: sreg] + TAM_CRLF),sArq);
    sCodigo = [self trim: [self copy: slinha,nPosChave,nTamChave]];
    if (strcmp(sCodigo,sChave)==0)
       [self btnAcao: sreg,opConfirmaExclusao];
  }
free(slinha);
return self;
}
@end
/*------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {
  id livrus;
  BOOL bopcao;
  char opmenu;
 
  //Livrus *livrus = [[Livrus alloc] init];
 livrus = [Livrus new];
 [livrus constantes];

 if ((argc > 0) && (strcmp(argv[0],"-cria")==0))
   [livrus abrecriaArqs: NO];
 else {
   [livrus frmSplash];
   [livrus abrecriaArqs: YES];
   if ([livrus frmLogin]==YES) {
     bopcao = YES;
     while(bopcao==YES) {
       [livrus menu: 1];
       fscanf(stdin, "%s", &opmenu);
       if ((opmenu=='C') || (opmenu=='c')) [livrus usaMenu: 1];
       else if ((opmenu=='P') || (opmenu=='p')) [livrus usaMenu: 2];
       else if ((opmenu=='V') || (opmenu=='v')) [livrus usaMenu: 3];
       else if ((opmenu=='O') || (opmenu=='o')) [livrus usaMenu: 4];
       else printf("%s\n",[livrus retMSGERRO]);
       fflush(stdin);
       bopcao = YES;
     }
   } else {
     [livrus fechaArqs];
     [livrus free];
     exit(0);
   }
 }
 [livrus free];
 return 0;
}
