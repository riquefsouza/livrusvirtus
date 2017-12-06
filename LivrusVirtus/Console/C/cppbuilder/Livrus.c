/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem C.
------------------------------------------------------------------------------*/
/* programa Livrus */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

#include <conio.h>

/* Declaração de tipos */

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

  typedef int boolean;
  typedef char* mstring;
  typedef char* tregistro;
  typedef FILE* tarquivo;
  enum ctTipo { opTexto, opNumero, opData, opDataHora, opSenha };
  enum ctArqs { opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
                opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
                opUsuario, opVenda };
  enum ctAcao { opNovo, opAlterar, opPesquisar, opSalvarInclusao,
              opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos };

const int TRUE = 1;
const int FALSE = 0;

const mstring CRLF = "\n"; /* windows */
const int TAM_CRLF = 1;
/* const mstring CRLF = "\n";
   const int TAM_CRLF = 1; */ /* unix */
/* const mstring CRLF = "\r";
   const int TAM_CRLF = 1; */ /* macintosh */

const mstring ARQ_ABRE = "rt+";
const mstring ARQ_CRIA = "wt+";

const int QTD_MAX_LINHA = 18;
const int TAM_MAX_STR = 255;
const int TAM_MAX_REG = 145;

const mstring MSG_ARQERRO = "Erro: O arquivo não pode ser aberto.";
const mstring MSG_ARQCERRO = "Erro: O arquivo não pode ser criado.";
const mstring MSG_ERRO = "Erro: opção inválida digite de novo.";
const mstring MSG_OPCAO = "Escolha uma opção: ";
const mstring MSG_PRESS = "pressione para continuar...";

mstring MSG_REGINC = "registro incluido!";
mstring MSG_REGNINC = "registro não incluido!";
mstring MSG_REGALT = "registro alterado!";
mstring MSG_REGNALT = "registro não alterado!";
mstring MSG_REGEXC = "registro excluido!";
mstring MSG_REGNEXC = "registro não excluido!";
mstring MSG_REGEXST = "registro já existe!";

const mstring MSG_NUMINV = "Número inválido ou menor do que 1!";
const mstring MSG_DATAINV = "Data inválida!, formato correto (dd/mm/yyyy)";
const mstring MSG_DTHRINV = 
                "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)";
const mstring MSG_ISBNINV = "ISBN inválido!";
const mstring MSG_CPFINV = "CPF inválido!";
const mstring MSG_SENCONFERE = "senha não confere com a senha atual!";
const mstring MSG_SENCONFIRM = "nova senha não confere com a senha confirmada!";
const mstring MSG_LOGINENCON = "login não encontrado!";
const mstring MSG_SEMESTOQUE = "livro não existe no estoque!";

const mstring ARQ_ASSUNTO = "C:/temp/assunto.dat";
const mstring ARQ_AUTOR = "C:/temp/autor.dat";
const mstring ARQ_EDITORA = "C:/temp/editora.dat";
const mstring ARQ_IDIOMA = "C:/temp/idioma.dat";
const mstring ARQ_USUARIO = "C:/temp/usuario.dat";
const mstring ARQ_PAIS = "C:/temp/pais.dat";
const mstring ARQ_PROFISSAO = "C:/temp/profissao.dat";
const mstring ARQ_LIVRO = "C:/temp/livro.dat";
const mstring ARQ_LIVASS = "C:/temp/livroass.dat";
const mstring ARQ_LIVAUT = "C:/temp/livroaut.dat";
const mstring ARQ_CLIENTE = "C:/temp/cliente.dat";
const mstring ARQ_ENDERECO = "C:/temp/endereco.dat";
const mstring ARQ_VENDA = "C:/temp/venda.dat";

const int TAM_ASSUNTO = 40;
const int TAM_AUTOR = 40;
const int TAM_EDITORA = 60;
const int TAM_IDIOMA = 30;
const int TAM_USUARIO = 20;
const int TAM_PAIS = 53;
const int TAM_PROFISSAO = 60;
const int TAM_LIVRO = 143;
const int TAM_LIVASS = 23;
const int TAM_LIVAUT = 23;
const int TAM_CLIENTE = 135;
const int TAM_ENDERECO = 123;
const int TAM_VENDA = 56;

/* variaveis gerais */

 boolean bopcao;
 char opmenu;
 int g_nPosChave, g_nTamChave;
 double g_nPreco;
 boolean g_SalvarInclusao;

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

 tarquivo tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, tfPais, 
 tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente, tfUsuario, tfVenda;

/*--- Rotinas básicas --------------------------------------------------------*/
mstring alocaString(int ntam);
mstring somastr(int num,...);
mstring copy(mstring string,int ini,int tam);
mstring trim(mstring sTexto);
mstring repete(mstring sTexto, int nQtd);
mstring esp(mstring sTexto, int nTam);
mstring zeros(mstring stexto, int ntam);
boolean strRelativa(mstring sTexto, mstring sChave);
int modulo11(mstring svalor, int ndig);
boolean validaCPF(mstring cpf);
boolean validaISBN(mstring isbn);
mstring digita(int nTam);
mstring digitaSenha(mstring sRotulo,int nTamSenha);
mstring validaNumero(mstring sRotulo, mstring sNumero);
mstring validaDataHora(mstring sRotulo, mstring sDataHora,
        boolean bSoData);
mstring itoa(int nvalor, mstring stexto, int radix);        
mstring retDataHora(void);

/*--- Rotinas de manipulação de arquivos -------------------------------------*/
long tamArq(tarquivo sArq);
void abrecriaArqs(boolean bAbre);
void fechaArqs(void);
mstring pesqArq(tarquivo sArq, mstring sChave, int nPosChave,
         int nTamChave, int nTamLinha);
void pesqLinhaExcluida(tarquivo sArq, int nTamLinha);
mstring pesqMaxCod(tarquivo sArq, int nPosChave,
        int nTamChave, int nTamLinha);
void escreveArq(tarquivo sArq, mstring sTexto,
	mstring sMsgAcerto, mstring sMsgErro);

/*--- Rotinas de implementação do sistema e de interface ---------------------*/
mstring LinhaReg(enum ctArqs sreg);
int tamReg(enum ctArqs sreg);
mstring rotulo(enum ctArqs sreg, int nNum);
boolean ContinuaSN(int nlinha, int nQtdLinha);
boolean ListarTodos(tarquivo sArq, enum ctArqs sreg, mstring sChave,
          int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
          boolean bPesqRelativa);
void ListarRegLigados(tarquivo sArq1, enum ctArqs sreg1, int nPosChave1,
          int nTamChave1, int nPosChave2, int nTamChave2, mstring sChave,
      tarquivo sArq2, enum ctArqs sreg2, int nPosChave3, int nQtdLinha);
mstring validaEntrada(tarquivo sArq, enum ctArqs sreg, int nTexto,
        mstring sEntrada, int nTentativas,
        boolean bPesqRelativa, enum ctTipo bTipoEntrada);
void frmSplash(void);
void frmSobre(void);
boolean frmLogin(void);
void menu(int num);
void frmCadastros(enum ctArqs sreg, enum ctAcao sacao);
void frmConsultas(enum ctArqs sreg, enum ctAcao sacao);
void frmAlterarSenha(void);
void btnAcao(enum ctArqs sreg, enum ctAcao sacao);
void subMenu(int nmenu, enum ctArqs sreg);
void usaMenu(int num);
void mostrarDados(enum ctArqs sreg, mstring slinha, int nOpcao);
void mostrarSubDados(enum ctArqs sreg, enum ctArqs ssubreg, boolean bSoMostrar);
void frmCadLigados(enum ctArqs sreg, enum ctAcao sacao, mstring sCodigo);
void ExcluirRegLigados(tarquivo sArq, enum ctArqs sreg, int nPosChave,
          int nTamChave, mstring sChave);


/*------------------------------------------------------------------------------
Função que aloca uma string na memória.
ntam - indica o tamanho de caracteres a serem alocados na memória
retorna - a string alocada
------------------------------------------------------------------------------*/
mstring alocaString(int ntam)
{ mstring strlocal;

 strlocal=(mstring) malloc(ntam);
 if (!strlocal) exit(1);
 else strlocal[0]='\0';
 
 return(strlocal);
}
/*------------------------------------------------------------------------------
Função que soma determinado número de strings.
num - indica o número de strings
... - as strings a serem somadas
retorna - o pedaço da string
------------------------------------------------------------------------------*/
mstring somastr(int num,...)
{
 int ig,j,t;
 mstring str, soma;
 va_list argptr;

 va_start(argptr,num);

 str=alocaString(TAM_MAX_STR * 2);
 soma=alocaString(TAM_MAX_STR * 4);

 j=0; t=0;
 for(;num;num--){
   str = va_arg(argptr,char*);
   for(ig=j; ig < abs(j+strlen(str)); ig++){
      soma[ig]=str[t];
      t++;
    }
   soma[ig]='\0';
   j=strlen(soma);
   t=0;
 }
 va_end(argptr);
 
 free(str);
 return(soma);
}
/*------------------------------------------------------------------------------
Função que retorna um pedaço de uma string.
str - indica a string
ini - indica a posicao inicial do pedaco
tam - indica o tamanho do pedaco
retorna - o pedaço da string
------------------------------------------------------------------------------*/
mstring copy(mstring string,int ini,int tam)
{
mstring str1 = alocaString(TAM_MAX_STR);
mstring slocal = alocaString(TAM_MAX_STR);
int i,j;
  
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
return(str1);
}
/*------------------------------------------------------------------------------
Retira os espaços em branco antes ou depois do texto.
sTexto - o texto a ser retirado os espaços em branco
retorna - o texto sem os espaços em branco
------------------------------------------------------------------------------*/
mstring trim(mstring sTexto) 
{
 int ncont, nPosIni, nPosFim;
 mstring sret;
 boolean bQuebra;

nPosIni = 0;
nPosFim = 0;
ncont = 0;
bQuebra = FALSE;
while ((ncont<=abs(strlen(sTexto))) && (bQuebra==FALSE))  {
  if (sTexto[ncont]!=' ') {
     nPosIni = ncont + 1;
     bQuebra = TRUE;
  }
  ncont++;
}
ncont = strlen(sTexto)-1;
bQuebra = FALSE;
while ((ncont >= 0) && (bQuebra==FALSE)) {
  if (sTexto[ncont]!=' ') {
     nPosFim = ncont + 1;
     bQuebra = TRUE;
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
mstring repete(mstring sTexto, int nQtd)
{ int ncont;
  mstring sret = alocaString(TAM_MAX_STR); 

for(ncont = 1; ncont <= nQtd; ncont++) {
    sret = strcat(sret,sTexto);
}
return(sret);
}
/*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*/
mstring esp(mstring sTexto, int nTam) 
{ mstring sret; 
  mstring slocal = alocaString(TAM_MAX_STR);
  
strcpy(slocal, sTexto);   
sret = repete(" ",nTam-strlen(slocal));
strcat(slocal,sret);
free(sret);
return(slocal);
}
/*------------------------------------------------------------------------------
Escreve zeros na frente de um texto.
stexto - o texto para receber zeros a frente
ntam - o tamanho da string
retorna - o texto com o zeros antes
------------------------------------------------------------------------------*/
mstring zeros(mstring stexto, int ntam)
{ unsigned int ncont;
  mstring saux = alocaString(TAM_MAX_STR);

  if (ntam!=abs(strlen(stexto))) {
      for(ncont = 1; ncont <= (ntam-strlen(stexto)); ncont++)
        saux = strcat(saux, "0");
  }
  return( strcat(saux, stexto) );
}
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*/
boolean strRelativa(mstring sTexto, mstring sChave)
{
  if (strstr(sTexto,sChave)!=NULL)
    return TRUE;
  else
    return FALSE;
}
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a mstring com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*/
int modulo11(mstring svalor, int ndig)
{ int ncont, nsoma, nvalor, npos;
  mstring slocal = alocaString(TAM_MAX_STR);
  mstring sres;

 ncont=1;
 while (ncont <= 11) {
   slocal=strcat(copy(svalor,ncont,1),slocal);
   ncont++;
 }
 nsoma=0;
 if (ndig == 1)
   ncont=3;
 else
   ncont=2;
 npos=2;
 while (ncont <= 11) {
   sres = copy(slocal,ncont,1);
   nvalor = atoi(sres);
   nsoma=nsoma + (nvalor * npos);
   ncont++;
   npos++;
 }
 nsoma=(11 - (nsoma % 11));

 if (nsoma > 9)
   return(0);
 else
   return(nsoma);
}
/*------------------------------------------------------------------------------
Validação de um número de CPF qualquer.
cpf - a mstring com o número do CPF
retorna - se é valido ou não
------------------------------------------------------------------------------*/
boolean validaCPF(mstring cpf)
{ mstring scpf, sres;
  int nvalor1, nvalor2;

if (strlen(cpf)==14) {
  scpf = somastr(4,copy(cpf,1,3),copy(cpf,5,3),copy(cpf,9,3),copy(cpf,13,2));
  sres = copy(cpf,13,1);
  nvalor1 = atoi(sres);
  strcpy(sres, copy(cpf,14,1));
  nvalor2 = atoi(sres);
  if ((modulo11(scpf,1)==nvalor1) && (modulo11(scpf,2)==nvalor2))
    return(TRUE);
  else
    return(FALSE);
} else
  return(FALSE);
}
/*------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a mstring com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------*/
boolean validaISBN(mstring isbn)
{ mstring sisbn = alocaString(TAM_MAX_STR);
  mstring sdigito, snum;
  int nvalor, nsoma, ncont;

if (strlen(isbn)==13) {
  sdigito = copy(isbn, strlen(isbn), 1);
  sisbn[0]='\0';
  for(ncont = 1; ncont <= abs(strlen(isbn)-1); ncont++)  {
    if (strcmp(copy(isbn,ncont,1),"-")!=0)
      sisbn = strcat(sisbn, copy(isbn,ncont,1));
  }
  if (strcmp(sdigito, "X")==0)
    nsoma = 10;
  else {
    nvalor = atoi(sdigito);
    nsoma = nvalor;
  }
  for(ncont = 1; ncont <= 9; ncont++)  {
    snum = copy(sisbn, ncont, 1);
    nvalor = atoi(snum);
    nsoma=nsoma + (nvalor * (11 - ncont));
  }
  if ((nsoma % 11) == 0)
    return(TRUE);
  else
    return(FALSE);
} else
  return(FALSE);
}
/*------------------------------------------------------------------------------
Realiza a digitação de algum texto
nTam - o tamanho maximo do texto a ser digitado
retorna - o texto digitado.
------------------------------------------------------------------------------*/
mstring digita(int nTam)
{ mstring sTexto = alocaString(TAM_MAX_STR);
  
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
mstring digitaSenha(mstring sRotulo,int nTamSenha)
{ mstring sSenha = alocaString(TAM_MAX_STR);
  char sLetra;
  int ncont;
 
  printf(sRotulo);
/*strcpy(sSenha, digita(TAM_MAX_STR));*/
  ncont  = 0;
  sLetra = '\0';
  while((sLetra!='\r') && (ncont < nTamSenha)) {
    sLetra = getch();
    if (sLetra!='\r') {
       /*printf("*");*/
       sSenha[ncont] = sLetra;
    }
    ncont++;
  }
sSenha[ncont-1] = '\0';  
printf("\n");
fflush(stdin);

return(sSenha);
}
/*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a mstring com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*/
mstring validaNumero(mstring sRotulo, mstring sNumero)
{ double nnum;
  int nStatus;

nStatus = -1;
 while (nStatus!=0) {
  printf(sRotulo);
  strcpy(sNumero, digita(TAM_MAX_STR));
  nnum = atof(sNumero);
  if (nnum < 1)
     printf("%s\n",MSG_NUMINV);
  else
     nStatus=0;
}
return(sNumero);
}
/*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a mstring com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
mstring validaDataHora(mstring sRotulo, mstring sDataHora, boolean bSoData)
{ boolean bvalida, bdatavalida, bhoravalida;
  mstring sdia, smes, sano, shora, smin, sseg;
  int ndia, nmes, nano, nhora, nmin, nseg, nudiames;
  unsigned int ntam;

bvalida = FALSE;
bdatavalida = FALSE;
bhoravalida = FALSE;
nudiames = 0;
if (bSoData==TRUE) ntam=10;
else ntam=19;
while (bvalida==FALSE) {
  printf(sRotulo);
  strcpy(sDataHora, digita(TAM_MAX_STR));
  if (strlen(sDataHora)==ntam) {
    sdia = copy(sDataHora,1,2);
    ndia = atoi(sdia);
    smes = copy(sDataHora,4,2);
    nmes = atoi(smes);
    sano = copy(sDataHora,7,4);
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
             bdatavalida = TRUE;
      }
    }
  
    if (bSoData) {
       if (bdatavalida) 
           bvalida = TRUE;
       else 
  		 printf("%s\n",MSG_DATAINV);
    } else {
      if (bdatavalida) {
          shora = copy(sDataHora,12,2);
          nhora = atoi(shora);
          smin = copy(sDataHora,15,2);
          nmin = atoi(smin);
          sseg = copy(sDataHora,18,2);
          nseg = atoi(sseg);
  
          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = TRUE;
            }
          }
  
          if (bhoravalida) 
  		   bvalida = TRUE;
          else 
  		   printf("%s\n",MSG_DTHRINV);
      } else
        printf("%s\n",MSG_DTHRINV);
    }
  } else {
    if (bSoData==TRUE) printf("%s\n",MSG_DATAINV);
    else printf("%s\n",MSG_DTHRINV);
  }
}
return(sDataHora);
}
/*------------------------------------------------------------------------------
Converte de inteiro para string, não existente em alguns compiladores.
nvalor - o valor do número inteiro
stexto - a string com o número inteiro
radix - numeral radix
retorna - a string com o número inteiro
------------------------------------------------------------------------------*/
mstring itoa(int nvalor, mstring stexto, int radix) {
 gcvt(nvalor, radix, stexto); 
 strncpy(stexto, stexto, strlen(stexto)-1);
 return(stexto);
}
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
mstring retDataHora(void)
{ mstring sdatahora = alocaString(TAM_MAX_STR);
  time_t agora;   
  struct tm * tempo;

  time(&agora);
  tempo = localtime(&agora); 
  strftime(sdatahora, TAM_MAX_STR, "%d/%m/%Y %H:%M:%S", tempo);
  return(sdatahora);
}
/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
long tamArq(tarquivo sArq)
{ long ntam;

fseek(sArq , 0 , SEEK_END);
ntam = ftell(sArq);
rewind(sArq);

return(ntam);
}
/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
void abrecriaArqs(boolean bAbre)
{
if (bAbre) {
  if ((tfAssunto=fopen(ARQ_ASSUNTO,ARQ_ABRE))==NULL) {
    printf("%s --> %s\n",MSG_ARQERRO,ARQ_ASSUNTO);
    exit(1);
  }
  if ((tfAutor=fopen(ARQ_AUTOR,ARQ_ABRE))==NULL) {
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
}
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
void fechaArqs(void)
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
mstring pesqArq(tarquivo sArq, mstring sChave, int nPosChave,
        int nTamChave, int nTamLinha)
{ tregistro slinha = alocaString(TAM_MAX_REG);
  mstring sres;
  boolean bQuebra;
  int nPosicao;

bQuebra = FALSE;
fseek(sArq, 0, SEEK_SET);
while ((!feof(sArq)) && (bQuebra==FALSE)) {
  fread(slinha,1,(nTamLinha + TAM_CRLF),sArq);
  sres = trim(copy(slinha,nPosChave,nTamChave));
  if (strcmp(sres, sChave)==0)
     bQuebra = TRUE;
}
nPosicao = ftell(sArq)-(nTamLinha + TAM_CRLF);
if (nPosicao > 0)
   fseek(sArq, nPosicao, SEEK_SET);
else
   fseek(sArq, 0, SEEK_SET);
if (strcmp(sres, sChave)!=0)
   return("");
else
   return(copy(slinha,1,nTamLinha));
}
/*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
void pesqLinhaExcluida(tarquivo sArq, int nTamLinha)
{ mstring sExcluido;

sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha);
if (strcmp(sExcluido,"")==0)
   fseek(sArq, tamArq(sArq), SEEK_SET);
}
/*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*/
mstring pesqMaxCod(tarquivo sArq, int nPosChave,
        int nTamChave, int nTamLinha)
{ tregistro slinha = alocaString(TAM_MAX_REG);
  mstring sres;
  boolean bQuebra;
  int nMaior, nCod;

bQuebra = FALSE;
nMaior = 0;
fseek(sArq, 0, SEEK_SET);
while ((!feof(sArq)) && (bQuebra==FALSE)) {
  fread(slinha,1,(nTamLinha + TAM_CRLF),sArq);
  sres = trim(copy(slinha,nPosChave,nTamChave));
  nCod=atoi(sres);
  if (nCod > nMaior)
     nMaior = nCod;
}
pesqLinhaExcluida(sArq, nTamLinha);
sres = itoa((nMaior+1),sres,10);
free(slinha);

return(sres);
}
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*/
void escreveArq(tarquivo sArq, mstring sTexto, mstring sMsgAcerto,
	mstring sMsgErro)
{ unsigned int ntam;

strcpy(sTexto, strcat(sTexto,CRLF));
ntam = strlen(sTexto);
if (fwrite(sTexto, 1, ntam, sArq) == ntam)
   printf("%s\n",sMsgAcerto);
else 
   printf("%s\n",sMsgErro);
}
/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
mstring LinhaReg(enum ctArqs sreg)
{ mstring slinha;

if (sreg==opAssunto) {
   slinha = somastr(2,esp(tAssunto.codigo,10),esp(tAssunto.assunto,30));
} else if (sreg==opAutor)
   slinha = somastr(2,esp(tAutor.codigo,10),esp(tAutor.autor,30));
else if (sreg==opEditora)
   slinha = somastr(2,esp(tEditora.codigo,10),esp(tEditora.editora,50));
else if (sreg==opEndereco)
   slinha = somastr(6,esp(tEndereco.codigo,10),esp(tEndereco.logradouro,40),
   esp(tEndereco.bairro,15),esp(tEndereco.cep,8),esp(tEndereco.cidade,30),
   esp(tEndereco.estado,20));
else if (sreg==opIdioma)
   slinha = somastr(2,esp(tIdioma.codigo,10),esp(tIdioma.idioma,20));
else if (sreg==opPais)
   slinha = somastr(2,esp(tPais.codigo,3),esp(tPais.pais,50));
else if (sreg==opProfissao)
   slinha = somastr(2,esp(tProfissao.codigo,10),esp(tProfissao.profissao,50));
else if (sreg==opUsuario)
   slinha = somastr(2,esp(tUsuario.login,10),esp(tUsuario.senha,10));
else if (sreg==opLivro)
   slinha = somastr(10,esp(tLivro.isbn,13),esp(tLivro.titulo,50),
   esp(tLivro.edicao,10),esp(tLivro.anopubli,10),esp(tLivro.codeditora,10),
   esp(tLivro.volume,10),esp(tLivro.codidioma,10),esp(tLivro.npaginas,10),
   esp(tLivro.preco,10),esp(tLivro.qtdestoque,10));
else if (sreg==opLivroAss)
   slinha = somastr(2,esp(tLivroAss.isbn,13),esp(tLivroAss.codassunto,10));
else if (sreg==opLivroAut)
   slinha = somastr(2,esp(tLivroAut.isbn,13),esp(tLivroAut.codautor,10));
else if (sreg==opCliente)
   slinha = somastr(10,esp(tCliente.cpf,14),esp(tCliente.nome,30),
   esp(tCliente.email,30),esp(tCliente.identidade,10),esp(tCliente.sexo,1),
   esp(tCliente.telefone,17),esp(tCliente.dtnascimento,10),
   esp(tCliente.codendereco,10),esp(tCliente.codpais,3),
   esp(tCliente.codprofissao,10));
else if (sreg==opVenda)
   slinha = somastr(4,esp(tVenda.dthrvenda,19),esp(tVenda.cpf,14),
   esp(tVenda.isbn,13),esp(tVenda.precovenda,10));

return(slinha);
}
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
int tamReg(enum ctArqs sreg)
{ int nret = 0;

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
mstring rotulo(enum ctArqs sreg, int nNum)
{  mstring sret = alocaString(TAM_MAX_STR);

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
         strcpy(sret, "Pre+o de venda: ");
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
boolean ContinuaSN(int nlinha, int nQtdLinha)
{ boolean bSOp, bret;
  char opCSubMenu;

bret = FALSE;
if (nlinha > 0) {
  if ((nlinha % nQtdLinha) == 0) {
      bSOp = TRUE;
      while(bSOp) {
       menu(13);
       fflush(stdin);
       fscanf(stdin, "%s", &opCSubMenu);
       if ((opCSubMenu=='S') || (opCSubMenu=='s')) bSOp = FALSE;
       else if ((opCSubMenu=='N') || (opCSubMenu=='n')) {
          bret = TRUE;
          bSOp = FALSE;
       } else printf("%s\n",MSG_ERRO);
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
boolean ListarTodos(tarquivo sArq, enum ctArqs sreg, mstring sChave,
   int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
   boolean bPesqRelativa)
{ tregistro slinha = alocaString(TAM_MAX_REG);
  boolean bQuebra, bAchou, bRet;
  int nCont;
  mstring sres;

bRet = FALSE;
bQuebra = FALSE;
nCont = 0;
mostrarDados(sreg, "", 2);
fseek(sArq, 0, SEEK_SET);
while ((!feof(sArq)) && (bQuebra==FALSE)) {
  fread(slinha,1,(nTamLinha + TAM_CRLF),sArq);

  if (bPesqRelativa) {
    sres = trim(copy(slinha,nPosChave,nTamChave));
    if (strRelativa(sres,sChave)==TRUE) {
       bAchou = TRUE;
       bRet = TRUE;
       free(sres);
    } else {
       bAchou = FALSE;
       free(sres);
    }   
  } else {
    bAchou = TRUE;
    bRet = TRUE;
  }

  if (bAchou && (!feof(sArq))) {
    mostrarDados(sreg, copy(slinha,1,nTamLinha), 3);
    nCont++;
  }

  bQuebra = ContinuaSN(nCont, nQtdLinha);
}
free(slinha);
return(bRet);
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
void ListarRegLigados(tarquivo sArq1, enum ctArqs sreg1, int nPosChave1,
int nTamChave1, int nPosChave2, int nTamChave2, mstring sChave,
tarquivo sArq2, enum ctArqs sreg2, int nPosChave3, int nQtdLinha)
{ tregistro slinha1 = alocaString(TAM_MAX_REG);
  boolean bQuebra, bRet;
  int nCont;
  mstring sCodigo1, sCodigo2, slinha2;

bRet = FALSE;
nCont = 0;
bQuebra = FALSE;
mostrarDados(sreg2, "", 2);
fseek(sArq1, 0, SEEK_SET);
while ((!feof(sArq1)) && (bQuebra==FALSE)) {
  fread(slinha1,1,(tamReg(sreg1) + TAM_CRLF),sArq1);
  sCodigo1 = trim(copy(slinha1,nPosChave1,nTamChave1));
  if (strcmp(sCodigo1,sChave)==0) {
    sCodigo2 = trim(copy(slinha1,nPosChave2,nTamChave2));
    slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
    mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
    bRet = TRUE;
    nCont++;
  }
  bQuebra = ContinuaSN(nCont, nQtdLinha);
}
if (bRet==FALSE)
   printf("%s\n",rotulo(sreg2,0));
free(slinha1);   
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
mstring validaEntrada(tarquivo sArq, enum ctArqs sreg, int nTexto,
        mstring sEntrada, int nTentativas,
        boolean bPesqRelativa, enum ctTipo bTipoEntrada)
{ boolean bQuebra;
  mstring sres, sTexto, sMsgErro, sLocal;
  int ncont, nPosChave, nTamChave, nTamLinha;

sres = alocaString(TAM_MAX_STR);
sLocal = alocaString(TAM_MAX_STR);

strcpy(sLocal, sEntrada);

nTamLinha = tamReg(sreg);
sMsgErro = rotulo(sreg,0);
sTexto = rotulo(sreg,nTexto);
nPosChave = g_nPosChave;
nTamChave = g_nTamChave;

ncont = 1;
bQuebra = FALSE;
  while ((bQuebra==FALSE) && (ncont <= nTentativas )) {
    if (bTipoEntrada==opTexto) {
      printf(sTexto);
      strcpy(sLocal, digita(TAM_MAX_STR));
    } else if (bTipoEntrada==opNumero)
       strcpy(sLocal, validaNumero(sTexto,sLocal));
    else if (bTipoEntrada==opData)
       strcpy(sLocal, validaDataHora(sTexto,sLocal,TRUE));
    else if (bTipoEntrada==opDataHora)
       strcpy(sLocal, validaDataHora(sTexto,sLocal,FALSE));
    else if (bTipoEntrada==opSenha) {
       strcpy(sLocal, digitaSenha(sTexto, 10));
    }

    if (bPesqRelativa) {
       if (ListarTodos(sArq, sreg, sLocal, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, TRUE))
        strcpy(sres, " ");
    } else
       sres = pesqArq(sArq, sLocal, nPosChave, nTamChave, nTamLinha);

    if (strcmp(sres,"")==0)
       printf("%s\n",sMsgErro);
    else
       bQuebra = TRUE;

    ncont++;
  }
return(sres);
}
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
void frmSplash(void)
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
}
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
void frmSobre(void)
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
 printf("| Versao programada na linguagem C.                          |\n");
 printf("*------------------------------------------------------------*\n");
 for(cont = 1; cont <= 4; cont++) printf("\n");
 printf(MSG_PRESS);
 fscanf(stdin, "%c%c", &opcao, &opcao);
}
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
boolean frmLogin(void)
{ boolean bret;
  mstring slinha;

  bret = FALSE;
  printf("*--------------------------------------------------------------*\n");
  printf("| Login do sistema                                             |\n");
  printf("*--------------------------------------------------------------*\n");
  slinha = validaEntrada(tfUsuario, opUsuario, 1, tUsuario.login, 3,
        FALSE, opTexto);
  if (strcmp(slinha,"")!=0) {
     strcpy(slinha, validaEntrada(tfUsuario, opUsuario, 2, tUsuario.senha, 3,
        FALSE, opSenha));
     if (strcmp(slinha,"")!=0) {
        strcpy(tUsuario.login, trim(copy(slinha, 1, 10)));
        strcpy(tUsuario.senha, trim(copy(slinha, 11, 10)));
        bret = TRUE;
     }
  }
  printf("\n");
  return(bret);
}
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*/
void menu(int num)
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
}
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
void frmCadastros(enum ctArqs sreg, enum ctAcao sacao)
{ mstring slinha;

if (sreg==opAssunto) {
   if (sacao==opNovo) {
      strcpy(tAssunto.codigo, pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg)));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
     slinha = validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,FALSE,opNumero);
      if (strcmp(slinha,"")!=0) {
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
      strcpy(tAutor.codigo, pesqMaxCod(tfAutor, 1, 10, tamReg(sreg)));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,FALSE,opNumero);
      if (strcmp(slinha,"")!=0) {
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
      strcpy(tEditora.codigo, pesqMaxCod(tfEditora, 1, 10, tamReg(sreg)));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,FALSE,opNumero);
      if (strcmp(slinha,"")!=0) {
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
      strcpy(tEndereco.codigo, pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg)));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
              FALSE,opNumero);
      if (strcmp(slinha,"")!=0) {
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
      strcpy(tIdioma.codigo, pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg)));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,FALSE,opNumero);
      if (strcmp(slinha,"")!=0) {
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
      printf(rotulo(sreg, 1));
      strcpy(tPais.codigo, digita(sizeof(tPais.codigo)));
      slinha = pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg));
      if (strcmp(slinha,"")==0) {
         pesqLinhaExcluida(tfPais, tamReg(sreg));
         mostrarDados(sreg, "", 1);
         subMenu(7, sreg);
      } else printf("%s\n",MSG_REGEXST);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, FALSE, opTexto);
      if (strcmp(slinha,"")!=0) {
        mostrarDados(sreg, "", 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      }
   } else if (sacao==opAlterar) {
      printf("%s%s\n",rotulo(sreg, 1), tPais.codigo);
      mostrarDados(sreg, "", 1);
      subMenu(9, sreg);
   } else if (sacao==opExcluir) {
      subMenu(10, sreg);
   }
} else if (sreg==opProfissao) {
   if (sacao==opNovo) {
      strcpy(tProfissao.codigo, pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg)));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
              FALSE,opNumero);
      if (strcmp(slinha,"")!=0) {
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
      printf(rotulo(sreg, 1));
      strcpy(tLivro.isbn, digita(sizeof(tLivro.isbn)));
      if (validaISBN(tLivro.isbn)) {
          slinha = pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg));
          if (strcmp(slinha,"")==0) {
             pesqLinhaExcluida(tfLivro, tamReg(sreg));
             mostrarDados(sreg, "", 1);
             subMenu(7, sreg);
             frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
             frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
          } else printf("%s\n",MSG_REGEXST);
      } else printf("%s\n",MSG_ISBNINV);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,FALSE,opTexto);
      if (strcmp(slinha,"")!=0) {
         mostrarDados(sreg, "", 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      }
   } else if (sacao==opAlterar) {
      printf("%s%s\n",rotulo(sreg, 1), tLivro.isbn);
      mostrarDados(sreg, "", 1);
      subMenu(9, sreg);
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      printf("%s\n","Assuntos dos livros excluídos, inclua novos!");
      frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
      printf("%s\n","Autores dos livros excluídos, inclua novos!");
      frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
   } else if (sacao==opExcluir) {
      subMenu(10, sreg);
      printf("%s\n","Assuntos dos livros sendo excluídos!");
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      printf("%s\n","Autores dos livros sendo excluídos!");
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
   }
} else if (sreg==opCliente) {
   if (sacao==opNovo) {
      printf(rotulo(sreg, 1));
      strcpy(tCliente.cpf, digita(sizeof(tCliente.cpf)));
      if (validaCPF(tCliente.cpf)) {
          slinha = pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg));
          if (strcmp(slinha,"")==0) {
             pesqLinhaExcluida(tfCliente, tamReg(sreg));
             mostrarDados(sreg, "", 1);
             subMenu(7, sreg);
          } else printf("%s\n",MSG_REGEXST);
      } else printf("%s\n",MSG_CPFINV);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,FALSE,opTexto);
      if (strcmp(slinha,"")!=0) {
         mostrarDados(sreg, "", 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      }
   } else if (sacao==opAlterar) {
      printf("%s%s\n",rotulo(sreg, 1), tCliente.cpf);
      mostrarDados(sreg, "", 1);
      subMenu(9, sreg);
   } else if (sacao==opExcluir) {
      subMenu(10, sreg);
   }
} else if (sreg==opVenda) {
   if (sacao==opNovo) {
      strcpy(tVenda.dthrvenda, retDataHora());
      printf("%s%s\n",rotulo(sreg, 1), tVenda.dthrvenda);
      slinha = pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
      if (strcmp(slinha,"")==0) {
         slinha = validaEntrada(tfCliente,opCliente,1,tVenda.cpf,3,
                 FALSE,opTexto);
         if (strcmp(slinha,"")!=0) {
            strcpy(tVenda.cpf, trim(copy(slinha,1,14)));
            if (validaCPF(tVenda.cpf)) {
               printf(" %s",rotulo(opCliente, 2)); /* Nome */
               printf("%s\n",copy(slinha, g_nPosChave, g_nTamChave));
               frmCadLigados(opVenda, opNovo, tVenda.cpf);
            } else printf("%s\n",MSG_CPFINV);
         }
      } else printf("%s\n",MSG_REGEXST);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
              FALSE,opDataHora);
      if (strcmp(slinha,"")!=0) {
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
void frmConsultas(enum ctArqs sreg, enum ctAcao sacao)
{ mstring slinha = alocaString(TAM_MAX_STR);

if (sreg==opAssunto) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opAutor) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opEditora) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfEditora,sreg,2,tEditora.editora,1,TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opEndereco) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1,
              TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
         3, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opIdioma) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opPais) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opProfissao) {
   if (sacao==opPesquisar)
     slinha = validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opLivro) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
        1, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opCliente) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
        1, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
} else if (sreg==opVenda) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, TRUE,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        printf("%s\n",rotulo(sreg, 0));
   }
}
if (strcmp(slinha,"")==0)
   printf(" ");
}
/*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*/
void frmAlterarSenha(void)
{ boolean bQuebra;
  mstring sres, sSenhaAtual, sNovaSenha, sConfirmaSenha;
  int nopcao;

sSenhaAtual = alocaString(TAM_MAX_STR);
sNovaSenha = alocaString(TAM_MAX_STR);
sConfirmaSenha = alocaString(TAM_MAX_STR);

printf("%s%s\n",rotulo(opUsuario, 1), tUsuario.login);
nopcao = 1;
bQuebra = FALSE;
while (bQuebra==FALSE) {
  switch(nopcao) {
   case 1: {
       strcpy(sSenhaAtual, digitaSenha("Senha Atual: ", 10));
       if (strcmp(sSenhaAtual,tUsuario.senha)!=0) {
          printf("%s\n",MSG_SENCONFERE);
          bQuebra = TRUE;
       } else nopcao = 2;
      } break;
   case 2: {
       strcpy(sNovaSenha, digitaSenha("Nova Senha: ", 10));
       strcpy(sConfirmaSenha, digitaSenha("Confirma Senha: ", 10));
       if (strcmp(sNovaSenha,sConfirmaSenha)!=0) {
          printf("%s\n",MSG_SENCONFIRM);
          bQuebra = TRUE;
       } else nopcao = 3;
      } break;
   case 3: {
       sres = pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(opUsuario));
       if (strcmp(sres,"")==0)
         printf("%s\n",MSG_LOGINENCON);
       else {
         strcpy(tUsuario.senha, sConfirmaSenha);
         subMenu(9,opUsuario);
         bQuebra = TRUE;
       }
       free(sres);
      } break;
  }
}
free(sSenhaAtual);
free(sNovaSenha);
free(sConfirmaSenha);
}
/*------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
void btnAcao(enum ctArqs sreg, enum ctAcao sacao)
{
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
void subMenu(int nmenu, enum ctArqs sreg)
{ int opSubMenu;
  char opCSubMenu;
  boolean bSOp;

bSOp = TRUE;
switch(nmenu) {
 case 6:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%d", &opSubMenu);
     switch(opSubMenu) {
      case 1: frmCadastros(sreg, opNovo); break;
      case 2: frmCadastros(sreg, opPesquisar); break;
      case 3: bSOp = FALSE; break;
	  default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 7:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%d", &opSubMenu);
     switch(opSubMenu) {
      case 1: { btnAcao(sreg, opSalvarInclusao); bSOp = FALSE; } break;
      case 2: bSOp = FALSE; break;
	  default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 8:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: { frmCadastros(sreg, opAlterar); bSOp = FALSE; } break;
      case 2: { frmCadastros(sreg, opExcluir); bSOp = FALSE; } break;
      case 3: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 9:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: { btnAcao(sreg, opSalvarAlteracao); bSOp = FALSE; } break;
      case 2: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 10:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%s", &opCSubMenu);     
     if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
        btnAcao(sreg, opConfirmaExclusao);
        bSOp = FALSE;
     } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = FALSE;
     else printf("%s\n",MSG_ERRO);
    }
   } break;
 case 12:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: frmConsultas(sreg, opPesquisar); break;
      case 2: frmConsultas(sreg, opListarTodos); break;
      case 3: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
    }
   } break;
 case 14:{
    while(bSOp) {
     menu(nmenu);
     fscanf(stdin, "%s", &opCSubMenu);     
     if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
        btnAcao(sreg, opSalvarInclusao);
        bSOp = FALSE;
        g_SalvarInclusao = TRUE;
     } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = FALSE;
     else printf("%s\n",MSG_ERRO);
    }
   } break;
}

}
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*/
void usaMenu(int num)
{ int opSubMenu;
  boolean bSOp;
  char opSair;

 bSOp = TRUE;
 if (num == 1) { /* Cadastros */
   while(bSOp) {
     menu(2);
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: subMenu(6, opAssunto); break;
      case 2: subMenu(6, opAutor); break;
      case 3: subMenu(6, opEditora); break;
      case 4: subMenu(6, opEndereco); break;
      case 5: subMenu(6, opIdioma); break;
      case 6: subMenu(6, opPais); break;
      case 7: subMenu(6, opProfissao); break;
      case 8: subMenu(6, opCliente); break;
      case 9: subMenu(6, opLivro); break;
      case 10: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 } else if (num == 2) { /* Pesquisas */
   while(bSOp) {
     menu(3);
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: subMenu(12, opAssunto); break;
      case 2: subMenu(12, opAutor); break;
      case 3: subMenu(12, opEditora); break;
      case 4: subMenu(12, opEndereco); break;
      case 5: subMenu(12, opIdioma); break;
      case 6: subMenu(12, opPais); break;
      case 7: subMenu(12, opProfissao); break;
      case 8: subMenu(12, opCliente); break;
      case 9: subMenu(12, opLivro); break;
      case 10: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 } else if (num == 3) { /* Vendas */
   while(bSOp) {
     menu(4);
     fscanf(stdin, "%d", &opSubMenu);     
     switch(opSubMenu) {
      case 1: subMenu(6, opVenda); break;
      case 2: subMenu(12, opVenda); break;
      case 3: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 } else if (num == 4) { /* Opcoes */
   while(bSOp) {
     menu(5);
     fscanf(stdin, "%d", &opSubMenu);
     fflush(stdin);     
     switch(opSubMenu) {
      case 1: frmAlterarSenha(); break;
      case 2: frmSobre(); break;
      case 3: {
           menu(11);
           fscanf(stdin, "%s", &opSair);           
           if ((opSair=='S') || (opSair=='s')) {
              fechaArqs();
              exit(0);
           }
         } break;
      case 4: bSOp = FALSE; break;
      default: printf("%s\n",MSG_ERRO);
     }
   }
 }
}
/*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*/
void mostrarDados(enum ctArqs sreg, mstring slinha, int nOpcao)
{ 
if (sreg==opAssunto) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",rotulo(sreg, 1), tAssunto.codigo);
        printf(rotulo(sreg, 2));
        strcpy(tAssunto.assunto, digita(sizeof(tAssunto.assunto)));
       } break;
    case 2: {
        printf("Código     Assunto\n");
        printf("------     -------\n");
       } break;
    case 3: {
        strcpy(tAssunto.codigo, trim(copy(slinha, 1, 10)));
        strcpy(tAssunto.assunto, trim(copy(slinha, 11, 30)));
        printf("%s %s\n",esp(tAssunto.codigo,10),esp(tAssunto.assunto,30));
       } break;
   }
} else if (sreg==opAutor) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",rotulo(sreg, 1), tAutor.codigo);
        printf(rotulo(sreg, 2));
        strcpy(tAutor.autor, digita(sizeof(tAutor.autor)));
       } break;
    case 2: {
        printf("Código     Autor\n");
        printf("------     -----\n");
       } break;
    case 3: {
        strcpy(tAutor.codigo, trim(copy(slinha, 1, 10)));
        strcpy(tAutor.autor, trim(copy(slinha, 11, 30)));
        printf("%s %s\n",esp(tAutor.codigo,10),esp(tAutor.autor,30));
       } break;
   }
} else if (sreg==opEditora) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",rotulo(sreg, 1), tEditora.codigo);
        printf(rotulo(sreg, 2));
        strcpy(tEditora.editora, digita(sizeof(tEditora.editora)));
       } break;
    case 2: {
        printf("Código     Editora\n");
        printf("------     -------\n");
       } break;
    case 3: {
        strcpy(tEditora.codigo, trim(copy(slinha, 1, 10)));
        strcpy(tEditora.editora, trim(copy(slinha, 11, 50)));
        printf("%s %s\n",esp(tEditora.codigo,10),esp(tEditora.editora,50));
       } break;
   }
} else if (sreg==opEndereco) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s",rotulo(sreg, 1), tEndereco.codigo);
        printf(rotulo(sreg, 2));
        strcpy(tEndereco.logradouro, digita(sizeof(tEndereco.logradouro)));
        printf(rotulo(sreg, 3));
        strcpy(tEndereco.bairro, digita(sizeof(tEndereco.bairro)));
        printf(rotulo(sreg, 4));
        strcpy(tEndereco.cep, digita(sizeof(tEndereco.cep)));
        printf(rotulo(sreg, 5));
        strcpy(tEndereco.cidade, digita(sizeof(tEndereco.cidade)));
        printf(rotulo(sreg, 6));
        strcpy(tEndereco.estado, digita(sizeof(tEndereco.estado)));
       } break;
    case 3: {
        strcpy(tEndereco.codigo, trim(copy(slinha, 1, 10)));
        strcpy(tEndereco.logradouro, trim(copy(slinha, 11, 40)));
        strcpy(tEndereco.bairro, trim(copy(slinha, 51, 15)));
        strcpy(tEndereco.cep, trim(copy(slinha, 66, 8)));
        strcpy(tEndereco.cidade, trim(copy(slinha, 74, 30)));
        strcpy(tEndereco.estado, trim(copy(slinha, 104, 20)));
        printf("--------------------\n");
        printf("%s%s\n",rotulo(sreg, 1), tEndereco.codigo);
        printf("%s%s\n",rotulo(sreg, 2), tEndereco.logradouro);
        printf("%s%s\n",rotulo(sreg, 3), tEndereco.bairro);
        printf("%s%s\n",rotulo(sreg, 4), tEndereco.cep);
        printf("%s%s\n",rotulo(sreg, 5), tEndereco.cidade);
        printf("%s%s\n",rotulo(sreg, 6), tEndereco.estado);
       } break;
   }
} else if (sreg==opIdioma) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",rotulo(sreg, 1), tIdioma.codigo);
        printf(rotulo(sreg, 2));
        strcpy(tIdioma.idioma, digita(sizeof(tIdioma.idioma)));
       } break; 
    case 2: {
        printf("Código     Idioma\n");
        printf("------     ------\n");
       } break;
    case 3: {
        strcpy(tIdioma.codigo, trim(copy(slinha, 1, 10)));
        strcpy(tIdioma.idioma, trim(copy(slinha, 11, 20)));
        printf("%s %s\n",esp(tIdioma.codigo,10),esp(tIdioma.idioma,20));
       } break;
   }
} else if (sreg==opPais) {
   switch(nOpcao) {
    case 1: {
        printf(rotulo(sreg, 2));
        strcpy(tPais.pais, digita(sizeof(tPais.pais)));
       } break;
    case 2: {
        printf("Código País\n");
        printf("------ ----\n");
       } break;
    case 3: {
        strcpy(tPais.codigo, trim(copy(slinha, 1, 3)));
        strcpy(tPais.pais, trim(copy(slinha, 4, 50)));
        printf("%s    %s\n",esp(tPais.codigo,3),esp(tPais.pais,50));
       } break;
   }
} else if (sreg==opProfissao) {
   switch(nOpcao) {
    case 1: {
        printf("%s%s\n",rotulo(sreg, 1), tProfissao.codigo);
        printf(rotulo(sreg, 2));
        strcpy(tProfissao.profissao, digita(sizeof(tProfissao.profissao)));
       } break;
    case 2: {
        printf("Código     Profissão\n");
        printf("------     ---------\n");
       } break;
    case 3: {
        strcpy(tProfissao.codigo, trim(copy(slinha, 1, 10)));
        strcpy(tProfissao.profissao, trim(copy(slinha, 11, 50)));
        printf("%s %s\n",esp(tProfissao.codigo,10),
                esp(tProfissao.profissao,50));
       } break;
   }
} else if (sreg==opLivro) {
   switch(nOpcao) {
    case 1: {
        printf(rotulo(sreg, 2));
        strcpy(tLivro.titulo, digita(sizeof(tLivro.titulo)));
        strcpy(tLivro.edicao, validaNumero(rotulo(sreg, 3), tLivro.edicao));
        strcpy(tLivro.anopubli, validaNumero(rotulo(sreg, 4), tLivro.anopubli));
        mostrarSubDados(opLivro, opEditora, FALSE);
        strcpy(tLivro.volume, validaNumero(rotulo(sreg, 6), tLivro.volume));
        mostrarSubDados(opLivro, opIdioma, FALSE);
        strcpy(tLivro.npaginas, validaNumero(rotulo(sreg, 8), tLivro.npaginas));
        strcpy(tLivro.preco, validaNumero(rotulo(sreg, 9), tLivro.preco));
        strcpy(tLivro.qtdestoque, validaNumero(rotulo(sreg, 10), 
        tLivro.qtdestoque));
       } break;
    case 3: {
        strcpy(tLivro.isbn, trim(copy(slinha, 1, 13)));
        strcpy(tLivro.titulo, trim(copy(slinha, 14, 50)));
        strcpy(tLivro.edicao, trim(copy(slinha, 64, 10)));
        strcpy(tLivro.anopubli, trim(copy(slinha, 74, 10)));
        strcpy(tLivro.codeditora, trim(copy(slinha, 84, 10)));
        strcpy(tLivro.volume, trim(copy(slinha, 94, 10)));
        strcpy(tLivro.codidioma, trim(copy(slinha, 104, 10)));
        strcpy(tLivro.npaginas, trim(copy(slinha, 114, 10)));
        strcpy(tLivro.preco, trim(copy(slinha, 124, 10)));
        strcpy(tLivro.qtdestoque, trim(copy(slinha, 134, 10)));
        printf("--------------------\n");
        printf("%s%s\n",rotulo(sreg, 1), tLivro.isbn);
        printf("%s%s\n",rotulo(sreg, 2), tLivro.titulo);
        printf("%s%s\n",rotulo(sreg, 3), tLivro.edicao);
        printf("%s%s\n",rotulo(sreg, 4), tLivro.anopubli);
        printf("%s%s\n",rotulo(sreg, 5), tLivro.codeditora);
        mostrarSubDados(opLivro, opEditora, TRUE);
        printf("%s%s\n",rotulo(sreg, 6), tLivro.volume);
        printf("%s%s\n",rotulo(sreg, 7), tLivro.codidioma);
        mostrarSubDados(opLivro, opIdioma, TRUE);
        printf("%s%s\n",rotulo(sreg, 8), tLivro.npaginas);
        printf("%s%s\n",rotulo(sreg, 9), tLivro.preco);
        printf("%s%s\n",rotulo(sreg, 10), tLivro.qtdestoque);
        ListarRegLigados(tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
                         tfAssunto, opAssunto, 1, 4);
        ListarRegLigados(tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
                         tfAutor, opAutor, 1, 4);
       } break;
   }
} else if (sreg==opCliente) {
   switch(nOpcao) {
    case 1: {
        printf(rotulo(sreg, 2));
        strcpy(tCliente.nome, digita(sizeof(tCliente.nome)));
        printf(rotulo(sreg, 3));
        strcpy(tCliente.email, digita(sizeof(tCliente.email)));
        printf(rotulo(sreg, 4));
        strcpy(tCliente.identidade, digita(sizeof(tCliente.identidade)));
        printf(rotulo(sreg, 5));
        strcpy(tCliente.sexo, digita(sizeof(tCliente.sexo)));
        printf(rotulo(sreg, 6));
        strcpy(tCliente.telefone, digita(sizeof(tCliente.telefone)));
        strcpy(tCliente.dtnascimento, 
                validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, TRUE));
        mostrarSubDados(opCliente, opEndereco, FALSE);
        mostrarSubDados(opCliente, opPais, FALSE);
        mostrarSubDados(opCliente, opProfissao, FALSE);
       } break;
    case 3: {
        strcpy(tCliente.cpf, trim(copy(slinha, 1, 14)));
        strcpy(tCliente.nome, trim(copy(slinha, 15, 30)));
        strcpy(tCliente.email, trim(copy(slinha, 45, 30)));
        strcpy(tCliente.identidade, trim(copy(slinha, 75, 10)));
        strcpy(tCliente.sexo, trim(copy(slinha, 85, 1)));
        strcpy(tCliente.telefone, trim(copy(slinha, 86, 17)));
        strcpy(tCliente.dtnascimento, trim(copy(slinha, 103, 10)));
        strcpy(tCliente.codendereco, trim(copy(slinha, 113, 10)));
        strcpy(tCliente.codpais, trim(copy(slinha, 123, 3)));
        strcpy(tCliente.codprofissao, trim(copy(slinha, 126, 10)));
        printf("--------------------\n");
        printf("%s%s\n",rotulo(sreg, 1), tCliente.cpf);
        printf("%s%s\n",rotulo(sreg, 2), tCliente.nome);
        printf("%s%s\n",rotulo(sreg, 3), tCliente.email);
        printf("%s%s\n",rotulo(sreg, 4), tCliente.identidade);
        printf("%s%s\n",rotulo(sreg, 5), tCliente.sexo);
        printf("%s%s\n",rotulo(sreg, 6), tCliente.telefone);
        printf("%s%s\n",rotulo(sreg, 7), tCliente.dtnascimento);
        printf("%s%s\n",rotulo(sreg, 8), tCliente.codendereco);
        mostrarSubDados(opCliente, opEndereco, TRUE);
        printf("%s%s\n",rotulo(sreg, 9), tCliente.codpais);
        mostrarSubDados(opCliente, opPais, TRUE);
        printf("%s%s\n",rotulo(sreg, 10), tCliente.codprofissao);
        mostrarSubDados(opCliente, opProfissao, TRUE);
       } break;
   }
} else if (sreg==opVenda) {
   switch(nOpcao) {
    case 1: mostrarSubDados(opVenda,opVenda, FALSE); break;
    case 2: {
        printf("DataHoraVenda       CPF            ISBN          " \
        "PreçoVenda\n");
        printf("-------------       ---            ----          " \
        "----------\n");
       } break;
    case 3: {
        strcpy(tVenda.dthrvenda, trim(copy(slinha, 1, 19)));
        strcpy(tVenda.cpf, trim(copy(slinha, 20, 14)));
        strcpy(tVenda.isbn, trim(copy(slinha, 34, 13)));
        strcpy(tVenda.precovenda, trim(copy(slinha, 47, 10)));
        printf("%s %s %s %s\n",esp(tVenda.dthrvenda,19),esp(tVenda.cpf,14),
        esp(tVenda.isbn,13),esp(tVenda.precovenda,10));
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
void mostrarSubDados(enum ctArqs sreg, enum ctArqs ssubreg, boolean bSoMostrar)
{ mstring sRegistro, sPreco;
int nMaxTentativas;

nMaxTentativas = 3;
if (sreg==opLivro) {
  if (ssubreg==opEditora) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(opEditora));
    else
       sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,FALSE,opNumero);
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tLivro.codeditora, trim(copy(sRegistro,1,10)));
      printf(" %s",rotulo(opEditora, 2));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  } else if (ssubreg==opIdioma) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(opIdioma));
    else
       sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,FALSE,opNumero);
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tLivro.codidioma, trim(copy(sRegistro,1,10)));
      printf(" %s",rotulo(opIdioma, 2));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  }
} else if (sreg==opCliente) {
  if (ssubreg==opEndereco) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
                  tamReg(opEndereco));
    else
       sRegistro = validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,FALSE,opNumero);
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tCliente.codendereco, trim(copy(sRegistro,1,10)));
      printf(" %s",rotulo(opEndereco, 2));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
      printf(" %s",rotulo(opEndereco, 3));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
      printf(" %s",rotulo(opEndereco, 4));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
      printf(" %s",rotulo(opEndereco, 5));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
      printf(" %s",rotulo(opEndereco, 6));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  } else if (ssubreg==opPais) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(opPais));
    else
       sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,FALSE,opTexto);
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tCliente.codpais, trim(copy(sRegistro,1,3)));
      printf(" %s",rotulo(opPais, 2));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  } else if (ssubreg==opProfissao) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
                  tamReg(opProfissao));
    else
       sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,FALSE,opNumero);
    if (strcmp(sRegistro,"")!=0) {
      strcpy(tCliente.codprofissao, trim(copy(sRegistro,1,10)));
      printf(" %s",rotulo(opProfissao, 2));
      printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  }
} else if (sreg==opVenda) {
  sRegistro = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
  if (strcmp(sRegistro,"")!=0) {
    printf(" %s",rotulo(opLivro, 2)); /* Titulo */
    printf("%s\n",copy(sRegistro, g_nPosChave, g_nTamChave));
    printf(" %s",rotulo(opLivro, 9)); /* Preco */
    sPreco = copy(sRegistro, g_nPosChave, g_nTamChave);
    g_nPreco = atof(sPreco);
    printf("%s\n",sPreco);
  }
}
}
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*/
void frmCadLigados(enum ctArqs sreg, enum ctAcao sacao, mstring sCodigo)
{ int nQtd, nCont, nQtdEstoque;
  double nTotalPreco;
  mstring slinha, sTotalPreco, sPreco;
  mstring sQtd = alocaString(TAM_MAX_STR);

if (sacao==opNovo) {
  nCont = 1;
  if (sreg==opLivroAss) {
    strcpy(sQtd, validaNumero("Quantos assuntos quer cadastrar?: ",sQtd));
    nQtd = atoi(sQtd);
    fseek(tfLivroAss, 0, SEEK_SET);
    while (nCont <= nQtd) {
      strcpy(tLivroAss.isbn, sCodigo);
      printf(rotulo(opLivroAss, 2));
      strcpy(tLivroAss.codassunto, digita(sizeof(tLivroAss.codassunto)));
      slinha = pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(opAssunto));
      printf(" %s",rotulo(opAssunto, 2));
      printf("%s\n",copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
      subMenu(14, sreg);
      nCont++;
    }
  } else if (sreg==opLivroAut) {
    strcpy(sQtd, validaNumero("Quantos autores quer cadastrar?: ",sQtd));
    nQtd = atoi(sQtd);
    fseek(tfLivroAut, 0, SEEK_SET);
    while (nCont <= nQtd) {
      strcpy(tLivroAut.isbn, sCodigo);
      printf(rotulo(opLivroAut, 2));
      strcpy(tLivroAut.codautor, digita(sizeof(tLivroAut.codautor)));
      slinha = pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(opAutor));
      printf(" %s",rotulo(opAutor, 2));
      printf("%s\n",copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
      subMenu(14, sreg);
      nCont++;
    }
  } else if (sreg==opVenda) {
    sPreco = alocaString(TAM_MAX_STR);
    sTotalPreco = alocaString(TAM_MAX_STR);    
    strcpy(sQtd, validaNumero("Quantos livros quer vender?: ",sQtd));
    nQtd = atoi(sQtd);
    nTotalPreco = 0;
    while (nCont <= nQtd) {
      slinha = validaEntrada(tfLivro,opLivro,1,tVenda.isbn,3,FALSE,opTexto);
      if (strcmp(slinha,"")!=0) {
        strcpy(tVenda.isbn, trim(copy(slinha,1,13)));
        if (validaISBN(tVenda.isbn)) {
          mostrarDados(sreg, "", 1);
          strcpy(tLivro.qtdestoque, trim(copy(slinha,134,10)));
          nQtdEstoque = atoi(tLivro.qtdestoque);
          if (nQtdEstoque > 0) {
             nTotalPreco = nTotalPreco + g_nPreco;
             /* sPreco = fcvt(g_nPreco, 7, &decimal, &sinal); */  
             gcvt(g_nPreco, 7, sPreco);
             strcpy(tVenda.precovenda, sPreco);
             g_SalvarInclusao = FALSE;
             subMenu(14, sreg);
             if (g_SalvarInclusao) {
                slinha = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
                if (strcmp(slinha,"")!=0) {
                   nQtdEstoque = nQtdEstoque-1;
                   strcpy(tLivro.qtdestoque, 
                          itoa(nQtdEstoque,tLivro.qtdestoque, 10));
                   slinha=strcat(copy(slinha,1,133),esp(tLivro.qtdestoque,10));
                   escreveArq(tfLivro, slinha, "", "");
                }
             }
             nCont++;
          } else printf("%s\n",MSG_SEMESTOQUE);
        } else printf("%s\n",MSG_ISBNINV);
      }
    }
    nTotalPreco = atof(sTotalPreco);
    printf("Total de %s%f\n",rotulo(sreg,4),nTotalPreco);
    free(sTotalPreco);
    free(sPreco);
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
void ExcluirRegLigados(tarquivo sArq, enum ctArqs sreg, int nPosChave,
int nTamChave, mstring sChave)
{ tregistro slinha = alocaString(TAM_MAX_REG);
  mstring sCodigo;

  fseek(sArq, 0, SEEK_SET);
  while (!feof(sArq)) {
    fread(slinha,1,(tamReg(sreg) + TAM_CRLF),sArq);
    sCodigo = trim(copy(slinha,nPosChave,nTamChave));
    if (strcmp(sCodigo,sChave)==0)
       btnAcao(sreg,opConfirmaExclusao);
  }
free(slinha);
}
/*------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
 if ((argc > 0) && (strcmp(argv[0],"-cria")==0))
   abrecriaArqs(FALSE);
 else {
   frmSplash();
   abrecriaArqs(TRUE);
   if (frmLogin()) {
     bopcao = TRUE;
     while(bopcao) {
       menu(1);
       fscanf(stdin, "%s", &opmenu);
       if ((opmenu=='C') || (opmenu=='c')) usaMenu(1);
       else if ((opmenu=='P') || (opmenu=='p')) usaMenu(2);
       else if ((opmenu=='V') || (opmenu=='v')) usaMenu(3);
       else if ((opmenu=='O') || (opmenu=='o')) usaMenu(4);
       else printf("%s\n",MSG_ERRO);
       fflush(stdin);
     }
   } else {
     fechaArqs();
     exit(0);
   }
 }
 return 0;
}
