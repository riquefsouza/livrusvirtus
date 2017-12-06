/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Vers�o programada na linguagem java.
------------------------------------------------------------------------------*/
/* programa Livrus */

import java.io.*;
import java.util.Date;
import java.text.*;

class clivrus {

  /* Declara��o de tipos */

  class regAssunto {
   String codigo; //10
   String assunto; //30
  }
  class regAutor {
   String codigo; //10
   String autor; //30
  }
  class regEditora {
   String codigo; //10
   String editora; //50
  }
  class regIdioma {
   String codigo; //10
   String idioma; //20
  }
  class regUsuario {
   String login; //10
   String senha; //10
  }
  class regPais {
   String codigo; //3
   String pais; //50
  }
  class regProfissao {
   String codigo; //10
   String profissao; //50
  }
  class regLivro {
   String isbn; //13
   String titulo; //50
   String edicao; //10
   String anopubli; //10
   String codeditora; //10
   String volume; //10
   String codidioma; //10
   String npaginas; //10
   String preco; //10
   String qtdestoque; //10
  }
  class regLivroAss {
   String isbn; //13
   String codassunto; //10
  }
  class regLivroAut {
   String isbn; //13
   String codautor; //10
  }
  class regCliente {
   String cpf; //14
   String nome; //30
   String email; //30
   String identidade; //10
   String sexo; //1
   String telefone; //17
   String dtnascimento; //10
   String codendereco; //10
   String codpais; //3
   String codprofissao; //10
  }
  class regEndereco {
   String codigo; //10
   String logradouro; //40
   String bairro; //15
   String cep; //8
   String cidade; //30
   String estado; //20
  }
  class regVenda {
   String dthrvenda; //19  /* data/hora da venda dd/mm/yyyy hh:mm:ss */
   String cpf; //14
   String isbn; //13
   String precovenda; //10
  }

  static int opTexto = 1, opNumero = 2, opData = 3, opDataHora = 4, opSenha = 5;
  static int opAssunto = 1, opAutor = 2, opEditora = 3, opEndereco = 4,
      opIdioma = 5, opPais = 6, opProfissao = 7, opCliente = 8, opLivro = 9,
      opLivroAss = 10, opLivroAut = 11, opUsuario = 12, opVenda = 13;
  static int opNovo = 1, opAlterar = 2, opPesquisar = 3, opSalvarInclusao = 4,
      opSalvarAlteracao = 5, opExcluir = 6, opConfirmaExclusao = 7,
      opListarTodos = 8;

  static String CRLF = "\n"; /* windows */
  static int TAM_CRLF = 1;
  /* static String CRLF = "\n";
     static int TAM_CRLF = 1; */ /* unix */
  /* static String CRLF = "\r";
     static int TAM_CRLF = 1; */ /* macintosh */

  static String ARQ_ABRE = "rw";
  static String ARQ_CRIA = "rw";

  static int QTD_MAX_LINHA = 18;
  static int TAM_MAX_STR = 255;
  static int TAM_MAX_REG = 145;

  static String MSG_ARQERRO = "Erro: O arquivo n�o pode ser aberto.";
  static String MSG_ERRO = "Erro: op��o inv�lida digite de novo.";
  static String MSG_OPCAO = "Escolha uma op��o: ";
  static String MSG_PRESS = "pressione para continuar...";

  static String MSG_REGINC = "registro incluido!";
  static String MSG_REGNINC = "registro n�o incluido!";
  static String MSG_REGALT = "registro alterado!";
  static String MSG_REGNALT = "registro n�o alterado!";
  static String MSG_REGEXC = "registro excluido!";
  static String MSG_REGNEXC = "registro n�o excluido!";
  static String MSG_REGEXST = "registro j� existe!";

  static String MSG_NUMINV = "N�mero inv�lido ou menor do que 1!";
  static String MSG_DATAINV = "Data inv�lida!, formato correto (dd/mm/yyyy)";
  static String MSG_DTHRINV =
                  "Data/hora inv�lida!, formato correto (dd/mm/yyyy hh:mm:ss)";
  static String MSG_ISBNINV = "ISBN inv�lido!";
  static String MSG_CPFINV = "CPF inv�lido!";
  static String MSG_SENCONFERE = "senha n�o confere com a senha atual!";
  static String MSG_SENCONFIRM="nova senha n�o confere com a senha confirmada!";
  static String MSG_LOGINENCON = "login n�o encontrado!";
  static String MSG_SEMESTOQUE = "livro n�o existe no estoque!";

  static String ARQ_ASSUNTO = "assunto.dat";
  static String ARQ_AUTOR = "autor.dat";
  static String ARQ_EDITORA = "editora.dat";
  static String ARQ_IDIOMA = "idioma.dat";
  static String ARQ_USUARIO = "usuario.dat";
  static String ARQ_PAIS = "pais.dat";
  static String ARQ_PROFISSAO = "profissao.dat";
  static String ARQ_LIVRO = "livro.dat";
  static String ARQ_LIVASS = "livroass.dat";
  static String ARQ_LIVAUT = "livroaut.dat";
  static String ARQ_CLIENTE = "cliente.dat";
  static String ARQ_ENDERECO = "endereco.dat";
  static String ARQ_VENDA = "venda.dat";

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

  boolean bopcao;
  char opmenu;
  int g_nPosChave, g_nTamChave;
  double g_nPreco;
  boolean g_SalvarInclusao;

  regAssunto tAssunto = new regAssunto();
  regAutor tAutor = new regAutor();
  regEditora tEditora = new regEditora();
  regIdioma tIdioma = new regIdioma();
  regEndereco tEndereco = new regEndereco();
  regPais tPais = new regPais();
  regProfissao tProfissao = new regProfissao();
  regLivro tLivro = new regLivro();
  regLivroAss tLivroAss = new regLivroAss();
  regLivroAut tLivroAut = new regLivroAut();
  regCliente tCliente = new regCliente();
  regUsuario tUsuario = new regUsuario();
  regVenda tVenda = new regVenda();

  RandomAccessFile tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco,
      tfPais, tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente,
      tfUsuario, tfVenda;

  Leitura ler = new Leitura();

/*--- Rotinas b�sicas --------------------------------------------------------*/

/*------------------------------------------------------------------------------
Fun��o que retorna um peda�o de uma string.
str - indica a string
ini - indica a posicao inicial do pedaco
tam - indica o tamanho do pedaco
retorna - o peda�o da string
------------------------------------------------------------------------------*/
  String copy(String str,int ini,int tam) {
    return str.substring(ini-1,ini+tam-1);
  }

/*------------------------------------------------------------------------------
Repete um texto um n�mero determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*/
  private String repete(String sTexto, int nQtd)
  { int ncont;
    String sret = new String("");

    for(ncont = 1; ncont <= nQtd; ncont++) {
        sret = sret + sTexto;
    }
    return sret;
  }
/*------------------------------------------------------------------------------
Coloca espa�os em branco a mais de acordo com o tamanho m�ximo do texto.
sTexto - o texto
nTam - tamanho m�ximo do texto
retorna - o texto com espa�os em branco a mais
------------------------------------------------------------------------------*/
  private String esp(String sTexto, int nTam)
  { String sret;

    sret = sTexto + repete(" ",nTam-sTexto.length());
    return sret;
  }
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto atrav�s de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou n�o a chave dentro do texto
------------------------------------------------------------------------------*/
  private boolean strRelativa(String sTexto, String sChave)
  { int nCont, nTamChave, nTamTexto;
    boolean bret;
    String sPedaco;

    bret = false;
    nCont = 1;
    nTamChave = sChave.length();
    nTamTexto = sTexto.length();
    if (nTamChave <= nTamTexto) {
      while (nCont <= (nTamTexto-nTamChave+1)) {
         sPedaco = copy(sTexto,nCont,nTamChave);
         if (sPedaco.equals(sChave))
            bret = true;
         nCont++;
      }
    }
    return  bret;
  }
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a string com o n�mero a ser calculado
ndig - d�gito do valor a ser calculado
retorna - o d�gito correto
------------------------------------------------------------------------------*/
 private int modulo11(String svalor, int ndig)
 {
  int ncont, nsoma, nvalor, npos;
  String slocal = new String();
  String sres = new String();

   ncont=1;
   slocal="";
   while (ncont <= 11) {
     slocal=copy(svalor, ncont,1) + slocal;
     ncont++;
   }
   nsoma=0;
   if (ndig == 1)
     ncont=3;
   else
     ncont=2;
   npos=2;
   while (ncont <= 11) {
     sres = copy(slocal, ncont,1);
     nvalor = Integer.parseInt(sres);
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
Valida��o de um n�mero de CPF qualquer.
cpf - a mstring com o n�mero do CPF
retorna - se � valido ou n�o
------------------------------------------------------------------------------*/
 public boolean validaCPF(String cpf)
 {
  String scpf = new String();

  if (cpf.length()==14)
  {
   scpf=cpf.substring(0,3)+cpf.substring(4,7)+cpf.substring(8,11)+
	cpf.substring(12,14);
   if ( (modulo11(scpf,1)==Integer.parseInt(cpf.substring(12,13))) &&
   (modulo11(scpf,2)==Integer.parseInt(cpf.substring(13))) )
    return true;
   else
    return false;
  }
  else return false;
 }
/*------------------------------------------------------------------------------
Valida��o de um n�mero ISBN qualquer.
isbn - a mstring com o n�mero do ISBN
retorna - se � valido ou n�o
------------------------------------------------------------------------------*/
 public boolean validaISBN(String isbn)
 {
  String sisbn = new String();
  String sdigito = new String();
  String snum = new String();
  int nvalor, nsoma, ncont;

  if (isbn.length()==13) {
    sdigito = copy(isbn, isbn.length(), 1);
    sisbn="";
    for(ncont = 1; ncont <= isbn.length(); ncont++)  {
      if (copy(isbn, ncont,1).equals("-")==false)
        sisbn = sisbn + copy(isbn, ncont,1);
    }
    if (sdigito.equals("X"))
      nsoma = 10;
    else {
      nvalor = Integer.parseInt(sdigito);
      nsoma = nvalor;
    }
    for(ncont = 1; ncont <= 9; ncont++)  {
      snum = copy(sisbn, ncont, 1);
      nvalor = Integer.parseInt(snum);
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
Esconde a digita��o da senha
retorna - a senha digitada
------------------------------------------------------------------------------*/
String digitaSenha(String sRotulo,int nTamSenha)
{ String sSenha = new String();
 // char sLetra;
 // int ncont;

  System.out.print(sRotulo);
  sSenha = ler.LerStr();
/*
  ncont  = 0;
  sLetra = '\0';
  while((sLetra!='\r') && (ncont < nTamSenha)) {
    sLetra = getch();
    if (sLetra!='\r') {
       sSenha[ncont] = sLetra;
    }
    ncont++;
  }
sSenha[ncont-1] = '\0';  */
System.out.println();

return sSenha;
}
/*------------------------------------------------------------------------------
Valida��o de um n�mero qualquer.
sRotulo - o texto antes de se digitar o n�mero
sNumero - a String com o valor do n�mero
retorna - o sNumero
------------------------------------------------------------------------------*/
String validaNumero(String sRotulo, String sNumero)
{ double nnum;
  int nStatus;

nStatus = -1;
 while (nStatus!=0) {
  System.out.print(sRotulo);
  sNumero = ler.LerStr();
  nnum = Integer.parseInt(sNumero);
  if (nnum < 1)
     System.out.println(MSG_NUMINV);
  else
     nStatus=0;
}
return(sNumero);
}
/*------------------------------------------------------------------------------
Valida��o de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a String com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
String validaDataHora(String sRotulo, String sDataHora, boolean bSoData)
{ boolean bvalida, bdatavalida, bhoravalida;
  String sdia, smes, sano, shora, smin, sseg;
  int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;
while (bvalida==false) {
  System.out.print(sRotulo);
  sDataHora = ler.LerStr();
  if (sDataHora.length()==ntam) {
    sdia = copy(sDataHora,1,2);
    ndia = Integer.parseInt(sdia);
    smes = copy(sDataHora,4,2);
    nmes = Integer.parseInt(smes);
    sano = copy(sDataHora,7,4);
    nano = Integer.parseInt(sano);

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
  	   System.out.println(MSG_DATAINV);
    } else {
      if (bdatavalida) {
          shora = copy(sDataHora,12,2);
          nhora = Integer.parseInt(shora);
          smin = copy(sDataHora,15,2);
          nmin = Integer.parseInt(smin);
          sseg = copy(sDataHora,18,2);
          nseg = Integer.parseInt(sseg);

          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = true;
            }
          }

          if (bhoravalida)
  		   bvalida = true;
          else
  		   System.out.println(MSG_DTHRINV);
      } else
        System.out.println(MSG_DTHRINV);
    }
  } else {
    if (bSoData==true) System.out.println(MSG_DATAINV);
    else System.out.println(MSG_DTHRINV);
  }
}
return sDataHora;
}
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
private String retDataHora() {
  Date dt = new Date();
  SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");
  String ds = sdf.format(dt);

  return ds;
 }
/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
long tamArq(RandomAccessFile sArq){
  try {
    return sArq.length();
  } catch(IOException e) {
   System.out.println(e.getMessage());
  }
  return 0;
}
/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condi��o para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
void abrecriaArqs(boolean bAbre)
{
  try {
    if (bAbre) {
      tfAssunto = new RandomAccessFile(ARQ_ASSUNTO,ARQ_ABRE);
      tfAutor = new RandomAccessFile(ARQ_AUTOR,ARQ_ABRE);
      tfEditora = new RandomAccessFile(ARQ_EDITORA,ARQ_ABRE);
      tfIdioma = new RandomAccessFile(ARQ_IDIOMA,ARQ_ABRE);
      tfEndereco = new RandomAccessFile(ARQ_ENDERECO,ARQ_ABRE);
      tfPais = new RandomAccessFile(ARQ_PAIS,ARQ_ABRE);
      tfProfissao = new RandomAccessFile(ARQ_PROFISSAO,ARQ_ABRE);
      tfLivro = new RandomAccessFile(ARQ_LIVRO,ARQ_ABRE);
      tfLivroAss = new RandomAccessFile(ARQ_LIVASS,ARQ_ABRE);
      tfLivroAut = new RandomAccessFile(ARQ_LIVAUT,ARQ_ABRE);
      tfCliente = new RandomAccessFile(ARQ_CLIENTE,ARQ_ABRE);
      tfUsuario = new RandomAccessFile(ARQ_USUARIO,ARQ_ABRE);
      tfVenda = new RandomAccessFile(ARQ_VENDA,ARQ_ABRE);
    } else {
      tfAssunto = new RandomAccessFile(ARQ_ASSUNTO,ARQ_CRIA);
      tfAutor = new RandomAccessFile(ARQ_AUTOR,ARQ_CRIA);
      tfEditora = new RandomAccessFile(ARQ_EDITORA,ARQ_CRIA);
      tfIdioma = new RandomAccessFile(ARQ_IDIOMA,ARQ_CRIA);
      tfEndereco = new RandomAccessFile(ARQ_ENDERECO,ARQ_CRIA);
      tfPais = new RandomAccessFile(ARQ_PAIS,ARQ_CRIA);
      tfProfissao = new RandomAccessFile(ARQ_PROFISSAO,ARQ_CRIA);
      tfLivro = new RandomAccessFile(ARQ_LIVRO,ARQ_CRIA);
      tfLivroAss = new RandomAccessFile(ARQ_LIVASS,ARQ_CRIA);
      tfLivroAut = new RandomAccessFile(ARQ_LIVAUT,ARQ_CRIA);
      tfCliente = new RandomAccessFile(ARQ_CLIENTE,ARQ_CRIA);
      tfUsuario = new RandomAccessFile(ARQ_USUARIO,ARQ_CRIA);
      tfVenda = new RandomAccessFile(ARQ_VENDA,ARQ_CRIA);
    }

  } catch(FileNotFoundException fnfe) {
    System.out.println(MSG_ARQERRO);
  }

}
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
void fechaArqs()
{
  try {
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
  } catch(IOException e) {
   System.out.println(e.getMessage());
 }

}
/*------------------------------------------------------------------------------
Pesquisa um registro atrav�s de um valor chave num arquivo.
sArq - o arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o registro pesquisado
------------------------------------------------------------------------------*/
String pesqArq(RandomAccessFile sArq, String sChave, int nPosChave,
        int nTamChave, int nTamLinha){
  String slinha = new String();
  String sres = new String();
  boolean bQuebra;
  long nPosicao;

  try {
    bQuebra = false;
    sArq.seek(0);
    while (slinha!=null && bQuebra == false) {
      slinha = sArq.readLine();
      if (slinha!=null && slinha.length() > 0)
        sres = copy(slinha, nPosChave, nTamChave).trim();
      if (sres.equals(sChave))
        bQuebra = true;
    }
    nPosicao = sArq.getFilePointer() - (nTamLinha + TAM_CRLF);
    if (nPosicao > 0)
      sArq.seek(nPosicao);
    else
      sArq.seek(0);
    if (sres.equals(sChave) == false)
      return ("");
    else
      return (copy(slinha, 1, nTamLinha));
  } catch(IOException e) {
   System.out.println(e.getMessage());
  }
  return "";
}
/*------------------------------------------------------------------------------
Pesquisa se tem linha exclu�da sen�o vai para a �ltima linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
void pesqLinhaExcluida(RandomAccessFile sArq, int nTamLinha){
  String sExcluido;
  try {
    sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha);
    if (sExcluido.equals(""))
       sArq.seek(tamArq(sArq));
   } catch(IOException e) {
      System.out.println(e.getMessage());
   }
}
/*------------------------------------------------------------------------------
Pesquisa o maior c�digo num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior c�digo
------------------------------------------------------------------------------*/
String pesqMaxCod(RandomAccessFile sArq, int nPosChave,
        int nTamChave, int nTamLinha) {
  String slinha = new String();
  String sres = new String();
  boolean bQuebra;
  int nMaior, nCod;

  try {
    bQuebra = false;
    nMaior = 0;
    sArq.seek(0);
    while (slinha!=null && bQuebra==false) {
      if (slinha!=null && slinha.length() > 0) {
        slinha = sArq.readLine();
        sres = copy(slinha,nPosChave,nTamChave).trim();
        nCod=Integer.parseInt(sres);
        if (nCod > nMaior)
           nMaior = nCod;
      }
    }
    pesqLinhaExcluida(sArq, nTamLinha);
    sres = Integer.toString(nMaior+1);
  } catch(IOException e) {
     System.out.println(e.getMessage());
  }

return(sres);
}
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro n�o foi gravado
------------------------------------------------------------------------------*/
void escreveArq(RandomAccessFile sArq, String sTexto, String sMsgAcerto,
	String sMsgErro){
  int ntam;
  try {
    sTexto = sTexto.concat(CRLF);
    ntam = sTexto.length();
    sArq.writeChars(sTexto);
    System.out.println(sMsgAcerto);
  } catch(IOException e) {
    System.out.println(sMsgErro);
  }
}
/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
String LinhaReg(int sreg) {
String slinha = new String();

if (sreg==opAssunto) {
   slinha = esp(tAssunto.codigo,10)+esp(tAssunto.assunto,30);
} else if (sreg==opAutor)
   slinha = esp(tAutor.codigo,10)+esp(tAutor.autor,30);
else if (sreg==opEditora)
   slinha = esp(tEditora.codigo,10)+esp(tEditora.editora,50);
else if (sreg==opEndereco)
   slinha = esp(tEndereco.codigo,10)+esp(tEndereco.logradouro,40)+
   esp(tEndereco.bairro,15)+esp(tEndereco.cep,8)+esp(tEndereco.cidade,30)+
   esp(tEndereco.estado,20);
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
int tamReg(int sreg)
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
nNum - indica qual rotulo ser� retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
String rotulo(int sreg, int nNum)
{  String sret = new String();

if (sreg==opAssunto) {
   switch(nNum) {
     case 0: sret = "Assunto(s) n�o encontrado(s)!"; break;
     case 1: {
         sret = "C�digo do assunto: ";
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
     case 0: sret = "Autor(es) n�o encontrado(s)!"; break;
     case 1: {
         sret = "C�digo do autor: ";
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
     case 0: sret = "Editora(s) n�o encontrada(s)!"; break;
     case 1: {
         sret = "C�digo da editora: ";
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
     case 0: sret = "Endere�o(s) n�o encontrado(s)!"; break;
     case 1: {
         sret = "C�digo do endere�o: ";
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
     case 0: sret = "Idioma(s) n�o encontrado(s)!"; break;
     case 1: {
         sret = "C�digo do idioma: ";
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
     case 0: sret = "Pa�s(es) n�o encontrado(s)!"; break;
     case 1: {
         sret = "C�digo do pa�s: ";
         g_nPosChave = 1;
         g_nTamChave = 3;
        } break;
     case 2: {
         sret = "Pa�s: ";
         g_nPosChave = 4;
         g_nTamChave = 50;
        } break;
   }
} else if (sreg==opProfissao) {
   switch(nNum) {
     case 0: sret = "Profiss�o(es) n�o encontrada(s)!"; break;
     case 1: {
         sret = "C�digo da profiss�o: ";
         g_nPosChave = 1;
         g_nTamChave = 10;
        } break;
     case 2: {
         sret = "Profiss�o: ";
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
     case 0: sret = "Livro(s) n�o encontrado(s)!"; break;
     case 1: {
         sret = "ISBN: ";
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         sret = "T�tulo: ";
         g_nPosChave = 14;
         g_nTamChave = 50;
        } break;
     case 3: {
         sret = "Edi��o: ";
         g_nPosChave = 64;
         g_nTamChave = 10;
        } break;
     case 4: {
         sret = "Ano de Publica��o: ";
         g_nPosChave = 74;
         g_nTamChave = 10;
        } break;
     case 5: {
         sret = "C�digo da editora: ";
         g_nPosChave = 84;
         g_nTamChave = 10;
        } break;
     case 6: {
         sret = "Volume: ";
         g_nPosChave = 94;
         g_nTamChave = 10;
        } break;
     case 7: {
         sret = "C�digo do idioma: ";
         g_nPosChave = 104;
         g_nTamChave = 10;
        } break;
     case 8: {
         sret = "N�mero de p�ginas: ";
         g_nPosChave = 114;
         g_nTamChave = 10;
        } break;
     case 9: {
         sret = "Pre�o: ";
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
     case 0: sret = "Assunto(s) n�o encontrado(s)!"; break;
     case 1: {
         sret = "ISBN: ";
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         sret = "C�digo do assunto: ";
         g_nPosChave = 14;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==opLivroAut) {
   switch(nNum) {
     case 0: sret = "Autor(s) n�o encontrado(s)!"; break;
     case 1: {
         sret = "ISBN: ";
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         sret = "C�digo do autor: ";
         g_nPosChave = 14;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==opCliente) {
   switch(nNum) {
     case 0: sret = "Cliente(s) n�o encontrado(s)!"; break;
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
         sret = "C�digo do endere�o: ";
         g_nPosChave = 113;
         g_nTamChave = 10;
        } break;
     case 9: {
         sret = "C�digo do pa�s: ";
         g_nPosChave = 123;
         g_nTamChave = 3;
        } break;
     case 10: {
          sret = "C�digo da Profiss�o: ";
          g_nPosChave = 126;
          g_nTamChave = 10;
        } break;
   }
} else if (sreg==opVenda) {
   switch(nNum) {
     case 0: sret = "Venda(s) n�o encontrada(s)!"; break;
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
         sret = "Pre�o de venda: ";
         g_nPosChave = 47;
         g_nTamChave = 10;
        } break;
   }
}

return(sret);
}
/*------------------------------------------------------------------------------
Indica se continua ou n�o mostrando um n�mero m�ximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou n�o
------------------------------------------------------------------------------*/
boolean ContinuaSN(int nlinha, int nQtdLinha)
{ boolean bSOp, bret;
  char opCSubMenu;

bret = false;
if (nlinha > 0) {
  if ((nlinha % nQtdLinha) == 0) {
      bSOp = true;
      while(bSOp) {
       menu(13);
       opCSubMenu = ler.LerChar();
       if ((opCSubMenu=='S') || (opCSubMenu=='s')) bSOp = false;
       else if ((opCSubMenu=='N') || (opCSubMenu=='n')) {
          bret = true;
          bSOp = false;
       } else System.out.println(MSG_ERRO);
      }
  }
}

return(bret);
}
/*------------------------------------------------------------------------------
Lista v�rios registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se encontrou algum registro
------------------------------------------------------------------------------*/
boolean ListarTodos(RandomAccessFile sArq, int sreg, String sChave,
   int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
   boolean bPesqRelativa) {
  String slinha = new String();
  boolean bQuebra, bAchou, bRet;
  int nCont;
  String sres = new String();

  bRet = false;
  try {
    bQuebra = false;
    nCont = 0;
    mostrarDados(sreg, "", 2);
    sArq.seek(0);
    while (slinha!=null && bQuebra==false) {
      slinha = sArq.readLine();
      if (slinha!=null && slinha.length() > 0) {
        if (bPesqRelativa) {
          sres = copy(slinha,nPosChave,nTamChave).trim();
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

        if (bAchou) {
          mostrarDados(sreg, copy(slinha,1,nTamLinha), 3);
          nCont++;
        }
      }
      bQuebra = ContinuaSN(nCont, nQtdLinha);
    }
  } catch(IOException e) {
     System.out.println(e.getMessage());
  }

return bRet;
}
/*------------------------------------------------------------------------------
Lista v�rios registros entre arquivos de acordo com a pesquisa feita.
sArq1 - o arquivo de liga��o
sreg1 - o tipo de arquivo de liga��o
nPosChave1 - a posicao inicial da primeira chave no arquivo de liga��o
nTamChave1 - o tamanho da primeira chave no arquivo de liga��o
nPosChave2 - a posicao inicial da segunda chave do arquivo de liga��o
nTamChave2 - o tamanho da segunda chave do arquivo de liga��o
sChave - a chave a ser pesquisada no arquivo de liga��o
sArq2 - o arquivo a ser pesquisado
sreg2 - o tipo de arquivo a ser pesquisado
nPosChave3 - a posicao inicial da chave do arquivo pesquisado
nQtdLinha - a quantidade de linhas a serem mostradas
------------------------------------------------------------------------------*/
void ListarRegLigados(RandomAccessFile sArq1, int sreg1, int nPosChave1,
int nTamChave1, int nPosChave2, int nTamChave2, String sChave,
RandomAccessFile sArq2, int sreg2, int nPosChave3, int nQtdLinha)
{ String slinha1 = new String();
  boolean bQuebra, bRet;
  int nCont;
  String sCodigo1, sCodigo2, slinha2;

  try {
    bRet = false;
    nCont = 0;
    bQuebra = false;
    mostrarDados(sreg2, "", 2);
    sArq1.seek(0);
    while (slinha1!=null && bQuebra==false) {
      slinha1 = sArq1.readLine();
      if (slinha1!=null && slinha1.length() > 0) {
        sCodigo1 = copy(slinha1,nPosChave1,nTamChave1).trim();
        if (sCodigo1.equals(sChave)) {
          sCodigo2 = copy(slinha1,nPosChave2,nTamChave2).trim();
          slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
          mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
          bRet = true;
          nCont++;
        }
      }
      bQuebra = ContinuaSN(nCont, nQtdLinha);
    }
    if (bRet==false)
       System.out.println(rotulo(sreg2,0));
   } catch(IOException e) {
      System.out.println(e.getMessage());
   }
}
/*------------------------------------------------------------------------------
Valida a entrada de registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
nTexto - o numero do r�tulo da entrada
sEntrada - a chave a ser pesquisada e validada
nTentativas - o n�mero m�ximo de tentativas
bPesqRelativa - indica se vai realizar uma pesquisa relativa
bTipoEntrada - indica o tipo de entrada
retorna - o registro pesquisado e validado
------------------------------------------------------------------------------*/
String validaEntrada(RandomAccessFile sArq, int sreg, int nTexto,
        String sEntrada, int nTentativas,
        boolean bPesqRelativa, int bTipoEntrada)
{ boolean bQuebra;
  String sres, sTexto, sMsgErro, sLocal;
  int ncont, nPosChave, nTamChave, nTamLinha;

sres = new String();
sLocal = new String();

sLocal = sEntrada;

nTamLinha = tamReg(sreg);
sMsgErro = rotulo(sreg,0);
sTexto = rotulo(sreg,nTexto);
nPosChave = g_nPosChave;
nTamChave = g_nTamChave;

ncont = 1;
bQuebra = false;
  while ((bQuebra==false) && (ncont <= nTentativas )) {
    if (bTipoEntrada==opTexto) {
      System.out.print(sTexto);
      sLocal = ler.LerStr();
    } else if (bTipoEntrada==opNumero)
       sLocal = validaNumero(sTexto,sLocal);
    else if (bTipoEntrada==opData)
       sLocal = validaDataHora(sTexto,sLocal,true);
    else if (bTipoEntrada==opDataHora)
       sLocal = validaDataHora(sTexto,sLocal,false);
    else if (bTipoEntrada==opSenha) {
       sLocal = digitaSenha(sTexto, 10);
    }

    if (bPesqRelativa) {
       if (ListarTodos(sArq, sreg, sLocal, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, true))
        sres = " ";
    } else
       sres = pesqArq(sArq, sLocal, nPosChave, nTamChave, nTamLinha);

    if (sres.equals(""))
       System.out.println(sMsgErro);
    else
       bQuebra = true;

    ncont++;
  }
return(sres);
}
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
void frmSplash()
{ int cont;
  char lopcao;

 System.out.println("*---------------------------------------" +
 "-------------------------------------*");
 System.out.println("| LL    II VV   VV RRRRR  UU  UU   SSSS " +
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |");
 System.out.println("| LL    II  VV VV  RR   R UU  UU  SS    " +
 " VV VV  II RR   R  TT  UU  UU  SS    |");
 System.out.println("| LL    II   VVV   RRRRR  UU  UU    SS  " +
 "  VVV   II RRRRR   TT  UU  UU    SS  |");
 System.out.println("| LLLLL II    V    RR   R  UUUU  SSSS   " +
 "   V    II RR   R  TT   UUUU  SSSS   |");
 System.out.println("*---------------------------------------" +
 "-------------------------------------*");
 for(cont = 1; cont <= 18; cont++) System.out.println();
 System.out.print(MSG_PRESS);
 lopcao = ler.LerChar();
}
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
void frmSobre()
{ int cont;
  char lopcao;

 System.out.println("*------------------------------------------------------------*");
 System.out.println("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |");
 System.out.println("|  LL        II   VV     VV   RR     R  UU    UU  SS         |");
 System.out.println("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |");
 System.out.println("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |");
 System.out.println("|  LLLL      II      VVV      RR RR     UU    UU        SS   |");
 System.out.println("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |");
 System.out.println("|                                                            |");
 System.out.println("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |");
 System.out.println("|   VV     VV   II  RR     R     TT     UU    UU  SS         |");
 System.out.println("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |");
 System.out.println("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |");
 System.out.println("|      VVV      II  RR RR        TT     UU    UU        SS   |");
 System.out.println("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |");
 System.out.println("|                                                            |");
 System.out.println("|                                               Versao 1.0.0 |");
 System.out.println("| Sistema integrante do projeto Livrus Virtus.               |");
 System.out.println("| Todos os direitos reservados para Henrique F. de Souza.    |");
 System.out.println("| Versao programada na linguagem java.                       |");
 System.out.println("*------------------------------------------------------------*");
 for(cont = 1; cont <= 4; cont++) System.out.println();
 System.out.print(MSG_PRESS);
 lopcao = ler.LerChar();
}
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
boolean frmLogin()
{ boolean bret;
  String slinha;

  bret = false;
  System.out.println("*--------------------------------------------------------------*");
  System.out.println("| Login do sistema                                             |");
  System.out.println("*--------------------------------------------------------------*");
  slinha = validaEntrada(tfUsuario, opUsuario, 1, tUsuario.login, 3,
        false, opTexto);
  if (slinha.equals("")==false) {
     slinha = validaEntrada(tfUsuario, opUsuario, 2, tUsuario.senha, 3,
        false, opSenha);
     if (slinha.equals("")==false) {
        tUsuario.login = copy(slinha, 1, 10).trim();
        tUsuario.senha = copy(slinha, 11, 10).trim();
        bret = true;
     }
  }
  System.out.println();
  return(bret);
}
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o n�mero do menu
------------------------------------------------------------------------------*/
void menu(int num)
{
 if (num==1) {
  System.out.println("*--------------------------------------------------------------*");
  System.out.println("| (C)adastros        (P)esquisas     (V)endas        (O)p��es  |");
  System.out.println("*--------------------------------------------------------------*");
 } else if (num==2) {
   System.out.println("*---------------------------------*");
   System.out.println("| 01. Cadastro de Assuntos        |");
   System.out.println("| 02. Cadastro de Autores         |");
   System.out.println("| 03. Cadastro de Editoras        |");
   System.out.println("| 04. Cadastro de Endere�os       |");
   System.out.println("| 05. Cadastro de Idiomas         |");
   System.out.println("| 06. Cadastro de Pa�ses          |");
   System.out.println("| 07. Cadastro de Profiss�es      |");
   System.out.println("| 08. Cadastro de Clientes        |");
   System.out.println("| 09. Cadastro de Livros          |");
   System.out.println("| 10. Voltar ao menu              |");
   System.out.println("*---------------------------------*");
 } else if (num==3) {
   System.out.println("*---------------------------------*");
   System.out.println("| 01. Consulta de Assuntos        |");
   System.out.println("| 02. Consulta de Autores         |");
   System.out.println("| 03. Consulta de Editoras        |");
   System.out.println("| 04. Consulta de Endere�os       |");
   System.out.println("| 05. Consulta de Idiomas         |");
   System.out.println("| 06. Consulta de Pa�ses          |");
   System.out.println("| 07. Consulta de Profiss�es      |");
   System.out.println("| 08. Consulta de Clientes        |");
   System.out.println("| 09. Consulta de Livros          |");
   System.out.println("| 10. Voltar ao menu              |");
   System.out.println("*---------------------------------*");
 } else if (num==4) {
   System.out.println("*---------------------------------*");
   System.out.println("| 01. Vender Livros               |");
   System.out.println("| 02. Vendas Realizadas           |");
   System.out.println("| 03. Voltar ao menu              |");
   System.out.println("*---------------------------------*");
 } else if (num==5) {
   System.out.println("*---------------------------------*");
   System.out.println("| 01. Alterar senha               |");
   System.out.println("| 02. Sobre o sistema             |");
   System.out.println("| 03. Sair do sistema             |");
   System.out.println("| 04. Voltar ao menu              |");
   System.out.println("*---------------------------------*");
 } else if (num==6) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==7) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| (1) Salvar inclus�o       (2) Voltar ao menu                 |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==8) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==9) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| (1) Salvar altera��o      (2) Voltar ao menu                 |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==10) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| Certeza de excluir? (S/N)                                    |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==11) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| Deseja sair do sistema? (S/N)                                |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==12) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==13) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| Deseja continuar? (S/N)                                      |");
   System.out.println("*--------------------------------------------------------------*");
 } else if (num==14) {
   System.out.println("*--------------------------------------------------------------*");
   System.out.println("| Salvar inclus�o (S/N)                                        |");
   System.out.println("*--------------------------------------------------------------*");
 }
 System.out.print(MSG_OPCAO);
}
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a a��o a ser realizada
------------------------------------------------------------------------------*/
void frmCadastros(int sreg, int sacao)
{ String slinha;

if (sreg==opAssunto) {
   if (sacao==opNovo) {
      tAssunto.codigo = pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg));
      mostrarDados(sreg, "", 1);
      subMenu(7, sreg);
   } else if (sacao==opPesquisar) {
     slinha = validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,opNumero);
      if (slinha.equals("")==false) {
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
      if (slinha.equals("")==false) {
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
      if (slinha.equals("")==false) {
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
      if (slinha.equals("")==false) {
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
      if (slinha.equals("")==false) {
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
      System.out.print(rotulo(sreg, 1));
      tPais.codigo = ler.LerStr();
      slinha = pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg));
      if (slinha.equals("")) {
         pesqLinhaExcluida(tfPais, tamReg(sreg));
         mostrarDados(sreg, "", 1);
         subMenu(7, sreg);
      } else System.out.println(MSG_REGEXST);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, opTexto);
      if (slinha.equals("")==false) {
        mostrarDados(sreg, "", 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      }
   } else if (sacao==opAlterar) {
      System.out.println(rotulo(sreg, 1) + tPais.codigo);
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
      if (slinha.equals("")==false) {
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
      System.out.print(rotulo(sreg, 1));
      tLivro.isbn = ler.LerStr();
      if (validaISBN(tLivro.isbn)) {
          slinha = pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg));
          if (slinha.equals("")) {
             pesqLinhaExcluida(tfLivro, tamReg(sreg));
             mostrarDados(sreg, "", 1);
             subMenu(7, sreg);
             frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
             frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
          } else System.out.println(MSG_REGEXST);
      } else System.out.println(MSG_ISBNINV);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,opTexto);
      if (slinha.equals("")==false) {
         mostrarDados(sreg, "", 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      }
   } else if (sacao==opAlterar) {
      System.out.println(rotulo(sreg, 1) + tLivro.isbn);
      mostrarDados(sreg, "", 1);
      subMenu(9, sreg);
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      System.out.println("Assuntos dos livros exclu�dos, inclua novos!");
      frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
      System.out.println("Autores dos livros exclu�dos, inclua novos!");
      frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
   } else if (sacao==opExcluir) {
      subMenu(10, sreg);
      System.out.println("Assuntos dos livros sendo exclu�dos!");
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      System.out.println("Autores dos livros sendo exclu�dos!");
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
   }
} else if (sreg==opCliente) {
   if (sacao==opNovo) {
      System.out.print(rotulo(sreg, 1));
      tCliente.cpf = ler.LerStr();
      if (validaCPF(tCliente.cpf)) {
          slinha = pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg));
          if (slinha.equals("")) {
             pesqLinhaExcluida(tfCliente, tamReg(sreg));
             mostrarDados(sreg, "", 1);
             subMenu(7, sreg);
          } else System.out.println(MSG_REGEXST);
      } else System.out.println(MSG_CPFINV);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,opTexto);
      if (slinha.equals("")==false) {
         mostrarDados(sreg, "", 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      }
   } else if (sacao==opAlterar) {
      System.out.println(rotulo(sreg, 1) + tCliente.cpf);
      mostrarDados(sreg, "", 1);
      subMenu(9, sreg);
   } else if (sacao==opExcluir) {
      subMenu(10, sreg);
   }
} else if (sreg==opVenda) {
   if (sacao==opNovo) {
      tVenda.dthrvenda = retDataHora();
      System.out.println(rotulo(sreg, 1) + tVenda.dthrvenda);
      slinha = pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
      if (slinha.equals("")) {
         slinha = validaEntrada(tfCliente,opCliente,1,tVenda.cpf,3,
                 false,opTexto);
         if (slinha.equals("")==false) {
            tVenda.cpf = copy(slinha,1,14).trim();
            if (validaCPF(tVenda.cpf)) {
               System.out.print(" " + rotulo(opCliente, 2)); /* Nome */
               System.out.println(copy(slinha, g_nPosChave, g_nTamChave));
               frmCadLigados(opVenda, opNovo, tVenda.cpf);
            } else System.out.println(MSG_CPFINV);
         }
      } else System.out.println(MSG_REGEXST);
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
              false,opDataHora);
      if (slinha.equals("")==false) {
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
sacao - a a��o a ser realizada
------------------------------------------------------------------------------*/
void frmConsultas(int sreg, int sacao)
{ String slinha = new String();

if (sreg==opAssunto) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opAutor) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opEditora) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opEndereco) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1,
              true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
         3, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opIdioma) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opPais) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opProfissao) {
   if (sacao==opPesquisar)
     slinha = validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opLivro) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
        1, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opCliente) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
        1, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
} else if (sreg==opVenda) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,opTexto);
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false)
        System.out.println(rotulo(sreg, 0));
   }
}
if (slinha.equals(""))
   System.out.print("");
}
/*------------------------------------------------------------------------------
Mostra a tela de altera��o de senha do sistema e realiza a altera��o.
------------------------------------------------------------------------------*/
void frmAlterarSenha()
{ boolean bQuebra;
  String sres, sSenhaAtual, sNovaSenha, sConfirmaSenha;
  int nopcao;

sSenhaAtual = new String();
sNovaSenha = new String();
sConfirmaSenha = new String();

System.out.println(rotulo(opUsuario, 1) + tUsuario.login);
nopcao = 1;
bQuebra = false;
while (bQuebra==false) {
  switch(nopcao) {
   case 1: {
       sSenhaAtual = digitaSenha("Senha Atual: ", 10);
       if (sSenhaAtual.equals(tUsuario.senha)==false) {
          System.out.println(MSG_SENCONFERE);
          bQuebra = true;
       } else nopcao = 2;
      } break;
   case 2: {
       sNovaSenha = digitaSenha("Nova Senha: ", 10);
       sConfirmaSenha = digitaSenha("Confirma Senha: ", 10);
       if (sNovaSenha.equals(sConfirmaSenha)==false) {
          System.out.println(MSG_SENCONFIRM);
          bQuebra = true;
       } else nopcao = 3;
      } break;
   case 3: {
       sres = pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(opUsuario));
       if (sres.equals(""))
         System.out.println(MSG_LOGINENCON);
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
Executa uma a��o de grava��o de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a a��o a ser realizada
------------------------------------------------------------------------------*/
void btnAcao(int sreg, int sacao)
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
nmenu - o n�mero do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
void subMenu(int nmenu, int sreg)
{ int opSubMenu;
  char opCSubMenu;
  boolean bSOp;

bSOp = true;
switch(nmenu) {
 case 6:{
    while(bSOp) {
     menu(nmenu);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: frmCadastros(sreg, opNovo); break;
      case 2: frmCadastros(sreg, opPesquisar); break;
      case 3: bSOp = false; break;
	  default: System.out.println(MSG_ERRO);
     }
    }
   } break;
 case 7:{
    while(bSOp) {
     menu(nmenu);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: { btnAcao(sreg, opSalvarInclusao); bSOp = false; } break;
      case 2: bSOp = false; break;
	  default: System.out.println(MSG_ERRO);
     }
    }
   } break;
 case 8:{
    while(bSOp) {
     menu(nmenu);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: { frmCadastros(sreg, opAlterar); bSOp = false; } break;
      case 2: { frmCadastros(sreg, opExcluir); bSOp = false; } break;
      case 3: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
    }
   } break;
 case 9:{
    while(bSOp) {
     menu(nmenu);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: { btnAcao(sreg, opSalvarAlteracao); bSOp = false; } break;
      case 2: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
    }
   } break;
 case 10:{
    while(bSOp) {
     menu(nmenu);
     opCSubMenu = ler.LerChar();
     if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
        btnAcao(sreg, opConfirmaExclusao);
        bSOp = false;
     } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
     else System.out.println(MSG_ERRO);
    }
   } break;
 case 12:{
    while(bSOp) {
     menu(nmenu);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: frmConsultas(sreg, opPesquisar); break;
      case 2: frmConsultas(sreg, opListarTodos); break;
      case 3: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
    }
   } break;
 case 14:{
    while(bSOp) {
     menu(nmenu);
     opCSubMenu = ler.LerChar();
     if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
        btnAcao(sreg, opSalvarInclusao);
        bSOp = false;
        g_SalvarInclusao = true;
     } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
     else System.out.println(MSG_ERRO);
    }
   } break;
}

}
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com n�mero do menu.
nmenu - o n�mero do menu
------------------------------------------------------------------------------*/
void usaMenu(int num)
{ int opSubMenu;
  boolean bSOp;
  char opSair;

 bSOp = true;
 if (num == 1) { /* Cadastros */
   while(bSOp) {
     menu(2);
     opSubMenu = ler.LerInt();
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
      case 10: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
   }
 } else if (num == 2) { /* Pesquisas */
   while(bSOp) {
     menu(3);
     opSubMenu = ler.LerInt();
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
      case 10: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
   }
 } else if (num == 3) { /* Vendas */
   while(bSOp) {
     menu(4);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: subMenu(6, opVenda); break;
      case 2: subMenu(12, opVenda); break;
      case 3: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
   }
 } else if (num == 4) { /* Opcoes */
   while(bSOp) {
     menu(5);
     opSubMenu = ler.LerInt();
     switch(opSubMenu) {
      case 1: frmAlterarSenha(); break;
      case 2: frmSobre(); break;
      case 3: {
           menu(11);
           opSair = ler.LerChar();
           if ((opSair=='S') || (opSair=='s')) {
              fechaArqs();
              System.exit(0);
           }
         } break;
      case 4: bSOp = false; break;
      default: System.out.println(MSG_ERRO);
     }
   }
 }
}
/*------------------------------------------------------------------------------
Mostra as entradas e as sa�das do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual op��o ser� mostrada
------------------------------------------------------------------------------*/
void mostrarDados(int sreg, String slinha, int nOpcao)
{
if (sreg==opAssunto) {
   switch(nOpcao) {
    case 1: {
        System.out.println(rotulo(sreg, 1) + tAssunto.codigo);
        System.out.print(rotulo(sreg, 2));
        tAssunto.assunto = ler.LerStr();
       } break;
    case 2: {
        System.out.println("C�digo     Assunto");
        System.out.println("------     -------");
       } break;
    case 3: {
        tAssunto.codigo = copy(slinha, 1, 10).trim();
        tAssunto.assunto = copy(slinha, 11, 30).trim();
        System.out.println(esp(tAssunto.codigo,10) + " " +
                           esp(tAssunto.assunto,30));
       } break;
   }
} else if (sreg==opAutor) {
   switch(nOpcao) {
    case 1: {
        System.out.println(rotulo(sreg, 1) + tAutor.codigo);
        System.out.print(rotulo(sreg, 2));
        tAutor.autor = ler.LerStr();
       } break;
    case 2: {
        System.out.println("C�digo     Autor");
        System.out.println("------     -----");
       } break;
    case 3: {
        tAutor.codigo = copy(slinha, 1, 10).trim();
        tAutor.autor = copy(slinha, 11, 30).trim();
        System.out.println(esp(tAutor.codigo,10)+" "+esp(tAutor.autor,30));
       } break;
   }
} else if (sreg==opEditora) {
   switch(nOpcao) {
    case 1: {
        System.out.println(rotulo(sreg, 1) + tEditora.codigo);
        System.out.print(rotulo(sreg, 2));
        tEditora.editora = ler.LerStr();
       } break;
    case 2: {
        System.out.println("C�digo     Editora");
        System.out.println("------     -------");
       } break;
    case 3: {
        tEditora.codigo = copy(slinha, 1, 10).trim();
        tEditora.editora = copy(slinha, 11, 50).trim();
        System.out.println(esp(tEditora.codigo,10)+" "+
                           esp(tEditora.editora,50));
       } break;
   }
} else if (sreg==opEndereco) {
   switch(nOpcao) {
    case 1: {
        System.out.println(rotulo(sreg, 1) + tEndereco.codigo);
        System.out.print(rotulo(sreg, 2));
        tEndereco.logradouro = ler.LerStr();
        System.out.print(rotulo(sreg, 3));
        tEndereco.bairro = ler.LerStr();
        System.out.print(rotulo(sreg, 4));
        tEndereco.cep = ler.LerStr();
        System.out.print(rotulo(sreg, 5));
        tEndereco.cidade = ler.LerStr();
        System.out.print(rotulo(sreg, 6));
        tEndereco.estado = ler.LerStr();
       } break;
    case 3: {
        tEndereco.codigo = copy(slinha, 1, 10).trim();
        tEndereco.logradouro = copy(slinha, 11, 40).trim();
        tEndereco.bairro = copy(slinha, 51, 15).trim();
        tEndereco.cep = copy(slinha, 66, 8).trim();
        tEndereco.cidade = copy(slinha, 74, 30).trim();
        tEndereco.estado = copy(slinha, 104, 20).trim();
        System.out.println("--------------------");
        System.out.println(rotulo(sreg, 1) + tEndereco.codigo);
        System.out.println(rotulo(sreg, 2) + tEndereco.logradouro);
        System.out.println(rotulo(sreg, 3) + tEndereco.bairro);
        System.out.println(rotulo(sreg, 4) + tEndereco.cep);
        System.out.println(rotulo(sreg, 5) + tEndereco.cidade);
        System.out.println(rotulo(sreg, 6) + tEndereco.estado);
       } break;
   }
} else if (sreg==opIdioma) {
   switch(nOpcao) {
    case 1: {
        System.out.println(rotulo(sreg, 1) + tIdioma.codigo);
        System.out.print(rotulo(sreg, 2));
        tIdioma.idioma = ler.LerStr();
       } break;
    case 2: {
        System.out.println("C�digo     Idioma");
        System.out.println("------     ------");
       } break;
    case 3: {
        tIdioma.codigo = copy(slinha, 1, 10).trim();
        tIdioma.idioma = copy(slinha, 11, 20).trim();
        System.out.println(esp(tIdioma.codigo,10) + " " +
                           esp(tIdioma.idioma,20));
       } break;
   }
} else if (sreg==opPais) {
   switch(nOpcao) {
    case 1: {
        System.out.print(rotulo(sreg, 2));
        tPais.pais = ler.LerStr();
       } break;
    case 2: {
        System.out.println("C�digo Pa�s");
        System.out.println("------ ----");
       } break;
    case 3: {
        tPais.codigo = copy(slinha, 1, 3).trim();
        tPais.pais = copy(slinha, 4, 50).trim();
        System.out.println(esp(tPais.codigo,3)+"    "+esp(tPais.pais,50));
       } break;
   }
} else if (sreg==opProfissao) {
   switch(nOpcao) {
    case 1: {
        System.out.println(rotulo(sreg, 1) + tProfissao.codigo);
        System.out.print(rotulo(sreg, 2));
        tProfissao.profissao = ler.LerStr();
       } break;
    case 2: {
        System.out.println("C�digo     Profiss�o");
        System.out.println("------     ---------");
       } break;
    case 3: {
        tProfissao.codigo = copy(slinha, 1, 10).trim();
        tProfissao.profissao = copy(slinha, 11, 50).trim();
        System.out.println(esp(tProfissao.codigo,10)+" "+
                esp(tProfissao.profissao,50));
       } break;
   }
} else if (sreg==opLivro) {
   switch(nOpcao) {
    case 1: {
        System.out.print(rotulo(sreg, 2));
        tLivro.titulo = ler.LerStr();
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
        tLivro.isbn = copy(slinha, 1, 13).trim();
        tLivro.titulo = copy(slinha, 14, 50).trim();
        tLivro.edicao = copy(slinha, 64, 10).trim();
        tLivro.anopubli = copy(slinha, 74, 10).trim();
        tLivro.codeditora = copy(slinha, 84, 10).trim();
        tLivro.volume = copy(slinha, 94, 10).trim();
        tLivro.codidioma = copy(slinha, 104, 10).trim();
        tLivro.npaginas = copy(slinha, 114, 10).trim();
        tLivro.preco = copy(slinha, 124, 10).trim();
        tLivro.qtdestoque = copy(slinha, 134, 10).trim();
        System.out.println("--------------------");
        System.out.println(rotulo(sreg, 1) + tLivro.isbn);
        System.out.println(rotulo(sreg, 2) + tLivro.titulo);
        System.out.println(rotulo(sreg, 3) + tLivro.edicao);
        System.out.println(rotulo(sreg, 4) + tLivro.anopubli);
        System.out.println(rotulo(sreg, 5) + tLivro.codeditora);
        mostrarSubDados(opLivro, opEditora, true);
        System.out.println(rotulo(sreg, 6) + tLivro.volume);
        System.out.println(rotulo(sreg, 7) + tLivro.codidioma);
        mostrarSubDados(opLivro, opIdioma, true);
        System.out.println(rotulo(sreg, 8) + tLivro.npaginas);
        System.out.println(rotulo(sreg, 9) + tLivro.preco);
        System.out.println(rotulo(sreg, 10) + tLivro.qtdestoque);
        ListarRegLigados(tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
                         tfAssunto, opAssunto, 1, 4);
        ListarRegLigados(tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
                         tfAutor, opAutor, 1, 4);
       } break;
   }
} else if (sreg==opCliente) {
   switch(nOpcao) {
    case 1: {
        System.out.print(rotulo(sreg, 2));
        tCliente.nome = ler.LerStr();
        System.out.print(rotulo(sreg, 3));
        tCliente.email = ler.LerStr();
        System.out.print(rotulo(sreg, 4));
        tCliente.identidade = ler.LerStr();
        System.out.print(rotulo(sreg, 5));
        tCliente.sexo = ler.LerStr();
        System.out.print(rotulo(sreg, 6));
        tCliente.telefone = ler.LerStr();
        tCliente.dtnascimento =
                validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true);
        mostrarSubDados(opCliente, opEndereco, false);
        mostrarSubDados(opCliente, opPais, false);
        mostrarSubDados(opCliente, opProfissao, false);
       } break;
    case 3: {
        tCliente.cpf = copy(slinha, 1, 14).trim();
        tCliente.nome = copy(slinha, 15, 30).trim();
        tCliente.email = copy(slinha, 45, 30).trim();
        tCliente.identidade = copy(slinha, 75, 10).trim();
        tCliente.sexo = copy(slinha, 85, 1).trim();
        tCliente.telefone = copy(slinha, 86, 17).trim();
        tCliente.dtnascimento = copy(slinha, 103, 10).trim();
        tCliente.codendereco = copy(slinha, 113, 10).trim();
        tCliente.codpais = copy(slinha, 123, 3).trim();
        tCliente.codprofissao = copy(slinha, 126, 10).trim();
        System.out.println("--------------------");
        System.out.println(rotulo(sreg, 1) + tCliente.cpf);
        System.out.println(rotulo(sreg, 2) + tCliente.nome);
        System.out.println(rotulo(sreg, 3) + tCliente.email);
        System.out.println(rotulo(sreg, 4) + tCliente.identidade);
        System.out.println(rotulo(sreg, 5) + tCliente.sexo);
        System.out.println(rotulo(sreg, 6) + tCliente.telefone);
        System.out.println(rotulo(sreg, 7) + tCliente.dtnascimento);
        System.out.println(rotulo(sreg, 8) + tCliente.codendereco);
        mostrarSubDados(opCliente, opEndereco, true);
        System.out.println(rotulo(sreg, 9) + tCliente.codpais);
        mostrarSubDados(opCliente, opPais, true);
        System.out.println(rotulo(sreg, 10) + tCliente.codprofissao);
        mostrarSubDados(opCliente, opProfissao, true);
       } break;
   }
} else if (sreg==opVenda) {
   switch(nOpcao) {
    case 1: mostrarSubDados(opVenda,opVenda, false); break;
    case 2: {
        System.out.println("DataHoraVenda       CPF            ISBN          " +
        "Pre�oVenda");
        System.out.println("-------------       ---            ----          " +
        "----------");
       } break;
    case 3: {
        tVenda.dthrvenda = copy(slinha, 1, 19).trim();
        tVenda.cpf = copy(slinha, 20, 14).trim();
        tVenda.isbn = copy(slinha, 34, 13).trim();
        tVenda.precovenda = copy(slinha, 47, 10).trim();
        System.out.println(esp(tVenda.dthrvenda,19)+" "+esp(tVenda.cpf,14)+" "+
        esp(tVenda.isbn,13)+" "+esp(tVenda.precovenda,10));
       } break;
   }
}

}
/*------------------------------------------------------------------------------
Mostra as sub inform��es de entrada e de sa�da.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai s� mostrar na sa�da
------------------------------------------------------------------------------*/
void mostrarSubDados(int sreg, int ssubreg, boolean bSoMostrar)
{ String sRegistro, sPreco;
int nMaxTentativas;

nMaxTentativas = 3;
if (sreg==opLivro) {
  if (ssubreg==opEditora) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(opEditora));
    else
       sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,false,opNumero);
    if (sRegistro.equals("")==false) {
      tLivro.codeditora = copy(sRegistro,1,10).trim();
      System.out.print(" "+rotulo(opEditora, 2));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  } else if (ssubreg==opIdioma) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(opIdioma));
    else
       sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,false,opNumero);
    if (sRegistro.equals("")==false) {
      tLivro.codidioma = copy(sRegistro,1,10).trim();
      System.out.print(" "+rotulo(opIdioma, 2));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
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
    if (sRegistro.equals("")==false) {
      tCliente.codendereco = copy(sRegistro,1,10).trim();
      System.out.print(" "+rotulo(opEndereco, 2));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
      System.out.print(" "+rotulo(opEndereco, 3));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
      System.out.print(" "+rotulo(opEndereco, 4));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
      System.out.print(" "+rotulo(opEndereco, 5));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
      System.out.print(" "+rotulo(opEndereco, 6));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  } else if (ssubreg==opPais) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(opPais));
    else
       sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,false,opTexto);
    if (sRegistro.equals("")==false) {
      tCliente.codpais = copy(sRegistro,1,3).trim();
      System.out.print(" "+rotulo(opPais, 2));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  } else if (ssubreg==opProfissao) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
                  tamReg(opProfissao));
    else
       sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,false,opNumero);
    if (sRegistro.equals("")==false) {
      tCliente.codprofissao = copy(sRegistro,1,10).trim();
      System.out.print(" "+rotulo(opProfissao, 2));
      System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
    }
  }
} else if (sreg==opVenda) {
  sRegistro = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
  if (sRegistro.equals("")==false) {
    System.out.print(" "+rotulo(opLivro, 2)); /* Titulo */
    System.out.println(copy(sRegistro, g_nPosChave, g_nTamChave));
    System.out.print(" "+rotulo(opLivro, 9)); /* Preco */
    sPreco = copy(sRegistro, g_nPosChave, g_nTamChave);
    g_nPreco = Double.parseDouble(sPreco);
    System.out.println(sPreco);
  }
}
}
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a a��o a ser realizada
sCodigo - um das chaves do arquivo de liga��o
------------------------------------------------------------------------------*/
void frmCadLigados(int sreg, int sacao, String sCodigo)
{ int nQtd, nCont, nQtdEstoque;
  double nTotalPreco;
  String slinha, sTotalPreco, sPreco;
  String sQtd = new String();

try {

if (sacao==opNovo) {
  nCont = 1;
  if (sreg==opLivroAss) {
    sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",sQtd);
    nQtd = Integer.parseInt(sQtd);
    tfLivroAss.seek(0);
    while (nCont <= nQtd) {
      tLivroAss.isbn = sCodigo;
      System.out.print(rotulo(opLivroAss, 2));
      tLivroAss.codassunto = ler.LerStr();
      slinha = pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(opAssunto));
      System.out.print(" "+rotulo(opAssunto, 2));
      System.out.println(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
      subMenu(14, sreg);
      nCont++;
    }
  } else if (sreg==opLivroAut) {
    sQtd = validaNumero("Quantos autores quer cadastrar?: ",sQtd);
    nQtd = Integer.parseInt(sQtd);
    tfLivroAut.seek(0);
    while (nCont <= nQtd) {
      tLivroAut.isbn = sCodigo;
      System.out.print(rotulo(opLivroAut, 2));
      tLivroAut.codautor = ler.LerStr();
      slinha = pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(opAutor));
      System.out.print(" "+rotulo(opAutor, 2));
      System.out.println(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
      subMenu(14, sreg);
      nCont++;
    }
  } else if (sreg==opVenda) {
    sPreco = new String();
    sTotalPreco = new String();
    sQtd = validaNumero("Quantos livros quer vender?: ",sQtd);
    nQtd = Integer.parseInt(sQtd);
    nTotalPreco = 0;
    while (nCont <= nQtd) {
      slinha = validaEntrada(tfLivro,opLivro,1,tVenda.isbn,3,false,opTexto);
      if (slinha.equals("")==false) {
        tVenda.isbn = copy(slinha,1,13).trim();
        if (validaISBN(tVenda.isbn)) {
          mostrarDados(sreg, "", 1);
          tLivro.qtdestoque = copy(slinha,134,10).trim();
          nQtdEstoque = Integer.parseInt(tLivro.qtdestoque);
          if (nQtdEstoque > 0) {
             nTotalPreco = nTotalPreco + g_nPreco;
             sPreco = Double.toString(g_nPreco);
             tVenda.precovenda = sPreco;
             g_SalvarInclusao = false;
             subMenu(14, sreg);
             if (g_SalvarInclusao) {
                slinha = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
                if (slinha.equals("")==false) {
                   nQtdEstoque = nQtdEstoque-1;
                   tLivro.qtdestoque = Integer.toString(nQtdEstoque);
                   slinha=copy(slinha,1,133).concat(esp(tLivro.qtdestoque,10));
                   escreveArq(tfLivro, slinha, "", "");
                }
             }
             nCont++;
          } else System.out.println(MSG_SEMESTOQUE);
        } else System.out.println(MSG_ISBNINV);
      }
    }
    sTotalPreco = Double.toString(nTotalPreco);
    System.out.println("Total de "+rotulo(sreg,4)+sTotalPreco);
  }
} else if (sacao==opExcluir) {
  if (sreg==opLivroAss) {
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo);
  } else if (sreg==opLivroAut) {
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo);
  }
}
} catch(IOException e) {
   System.out.println(e.getMessage());
}
}
/*------------------------------------------------------------------------------
Realiza a exclus�o dos arquivos de liga��o.
sArq - o arquivo de liga��o
sreg - o tipo de arquivo de liga��o
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------*/
void ExcluirRegLigados(RandomAccessFile sArq,  int sreg, int nPosChave,
int nTamChave, String sChave)
{ String slinha = new String();
  String sCodigo;

  try {
    sArq.seek(0);
    slinha = "";
    while (slinha!=null) {
      slinha = sArq.readLine();
      if (slinha!=null && slinha.length() > 0) {
        sCodigo = copy(slinha,nPosChave,nTamChave).trim();
        if (sCodigo.equals(sChave))
           btnAcao(sreg,opConfirmaExclusao);
      }
    }
  } catch(IOException e) {
     System.out.println(e.getMessage());
  }

}

}

public class livrus {
  static clivrus cl = new clivrus();
/*------------------------------------------------------------------------------
Parte inicial do c�digo
------------------------------------------------------------------------------*/
  public static void main(String[] args) {
    if ((args.length > 0) && (args[0].equals("-cria")))
      cl.abrecriaArqs(false);
    else {
      cl.frmSplash();
      cl.abrecriaArqs(true);
      if (cl.frmLogin()) {
        cl.bopcao = true;
        while(cl.bopcao) {
          cl.menu(1);
          cl.opmenu = cl.ler.LerChar();
          if ((cl.opmenu=='C') || (cl.opmenu=='c')) cl.usaMenu(1);
          else if ((cl.opmenu=='P') || (cl.opmenu=='p')) cl.usaMenu(2);
          else if ((cl.opmenu=='V') || (cl.opmenu=='v')) cl.usaMenu(3);
          else if ((cl.opmenu=='O') || (cl.opmenu=='o')) cl.usaMenu(4);
          else System.out.println(cl.MSG_ERRO);
        }
      } else {
        cl.fechaArqs();
        System.exit(0);
      }
    }
   System.exit(0);
  }

}

class Leitura {
 private BufferedReader brentrada;

 public Leitura() {
  brentrada = new BufferedReader(new InputStreamReader(System.in));
 }

 public String LerStr() {
  String sret = new String();
   try {
     sret = brentrada.readLine();
   } catch(Exception e) {
     System.out.println("Erro: " + e);
   }
  return sret;
 }

 public int LerInt() {
  String sret = new String();
  int nret = 0;
   try {
     sret = brentrada.readLine();
     nret = Integer.parseInt(sret);
   } catch(Exception e) {
     System.out.println("Erro: " + e);
   }
  return nret;
 }

 public float LerFloat() {
  String sret = new String();
  float nret = 0;
   try {
     sret = brentrada.readLine();
     nret = Float.parseFloat(sret);
   } catch(Exception e) {
     System.out.println("Erro: " + e);
   }
  return nret;
 }

 public double LerDouble() {
  String sret = new String();
  double nret = 0;
   try {
     sret = brentrada.readLine();
     nret = Double.parseDouble(sret);
   } catch(Exception e) {
     System.out.println("Erro: " + e);
   }
  return nret;
 }

 public char LerChar() {
  String sret = new String();
   try {
     sret = brentrada.readLine();
   } catch(Exception e) {
     System.out.println("Erro: " + e);
   }
   if (sret.length() > 0)
     return sret.charAt(0);
   else
     return ' ';
 }

 public Date LerData() {
  String sret = new String();
  DateFormat dtf = null;
  Date dret = new Date();
   try {
     sret = brentrada.readLine();
     dret = dtf.parse(sret);
   } catch(Exception e) {
     System.out.println("Erro: " + e);
   }
  return dret;
 }

}

