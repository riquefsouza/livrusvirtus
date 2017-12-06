/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Vers�o programada na linguagem JScript.NET.
------------------------------------------------------------------------------*/
/* programa Livrus */

import System;
import System.IO;
import System.Text;

package Livrus {

public class Livrus extends System.Object {

  class regAssunto {
   var codigo: String; //10
   var assunto: String; //30
  }
  class regAutor {
   var codigo: String; //10
   var autor: String; //30
  }
  class regEditora {
   var codigo: String; //10
   var editora: String; //50
  }
  class regIdioma {
   var codigo: String; //10
   var idioma: String; //20
  }
  class regUsuario {
   var login: String; //10
   var senha: String; //10
  }
  class regPais {
   var codigo: String; //3
   var pais: String; //50
  }
  class regProfissao {
   var codigo: String; //10
   var profissao: String; //50
  }
  class regLivro {
   var isbn: String; //13
   var titulo: String; //50
   var edicao: String; //10
   var anopubli: String; //10
   var codeditora: String; //10
   var volume: String; //10
   var codidioma: String; //10
   var npaginas: String; //10
   var preco: String; //10
   var qtdestoque: String; //10
  }
  class regLivroAss {
   var isbn: String; //13
   var codassunto: String; //10
  }
  class regLivroAut {
   var isbn: String; //13
   var codautor: String; //10
  }
  class regCliente {
   var cpf: String; //14
   var nome: String; //30
   var email: String; //30
   var identidade: String; //10
   var sexo: String; //1
   var telefone: String; //17
   var dtnascimento: String; //10
   var codendereco: String; //10
   var codpais: String; //3
   var codprofissao: String; //10
  }
  class regEndereco {
   var codigo: String; //10
   var logradouro: String; //40
   var bairro: String; //15
   var cep: String; //8
   var cidade: String; //30
   var estado: String; //20
  }
  class regVenda {
   var dthrvenda: String; //19  /* data/hora da venda dd/mm/yyyy hh:mm:ss */
   var cpf: String; //14
   var isbn: String; //13
   var precovenda: String; //10
  }

  enum ctTipo { opTexto, opNumero, opData, opDataHora, opSenha };
  enum ctArqs { opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
				opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
				opUsuario, opVenda };
  enum ctAcao { opNovo, opAlterar, opPesquisar, opSalvarInclusao,
			  opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos };

  static var CRLF: String = "\r\n"; /* windows */
  static var TAM_CRLF: int = 2;
  /* static var CRLF: String = "\n";
     static var TAM_CRLF: int = 1; */ /* unix */
  /* static var CRLF: String = "\r";
     static var TAM_CRLF: int = 1; */ /* macintosh */

  static var QTD_MAX_LINHA: int = 18;
  static var TAM_MAX_REG: int = 145;

  static var MSG_ARQERRO: String = "Erro: O arquivo n�o pode ser aberto.";
  static var MSG_ERRO: String = "Erro: op��o inv�lida digite de novo.";
  static var MSG_OPCAO: String = "Escolha uma op��o: ";
  static var MSG_PRESS: String = "pressione para continuar...";

  static var MSG_REGINC: String = "registro incluido!";
  static var MSG_REGNINC: String = "registro n�o incluido!";
  static var MSG_REGALT: String = "registro alterado!";
  static var MSG_REGNALT: String = "registro n�o alterado!";
  static var MSG_REGEXC: String = "registro excluido!";
  static var MSG_REGNEXC: String = "registro n�o excluido!";
  static var MSG_REGEXST: String = "registro j� existe!";

  static var MSG_NUMINV: String = "N�mero inv�lido ou menor do que 1!";
  static var MSG_DATAINV: String = "Data inv�lida!, formato correto (dd/mm/yyyy)";
  static var MSG_DTHRINV =
                  "Data/hora inv�lida!, formato correto (dd/mm/yyyy hh:mm:ss)";
  static var MSG_ISBNINV: String = "ISBN inv�lido!";
  static var MSG_CPFINV: String = "CPF inv�lido!";
  static var MSG_SENCONFERE: String = "senha n�o confere com a senha atual!";
  static var MSG_SENCONFIRM="nova senha n�o confere com a senha confirmada!";
  static var MSG_LOGINENCON: String = "login n�o encontrado!";
  static var MSG_SEMESTOQUE: String = "livro n�o existe no estoque!";

  static var ARQ_ASSUNTO: String = "assunto.dat";
  static var ARQ_AUTOR: String = "autor.dat";
  static var ARQ_EDITORA: String = "editora.dat";
  static var ARQ_IDIOMA: String = "idioma.dat";
  static var ARQ_USUARIO: String = "usuario.dat";
  static var ARQ_PAIS: String = "pais.dat";
  static var ARQ_PROFISSAO: String = "profissao.dat";
  static var ARQ_LIVRO: String = "livro.dat";
  static var ARQ_LIVASS: String = "livroass.dat";
  static var ARQ_LIVAUT: String = "livroaut.dat";
  static var ARQ_CLIENTE: String = "cliente.dat";
  static var ARQ_ENDERECO: String = "endereco.dat";
  static var ARQ_VENDA: String = "venda.dat";

  static var TAM_ASSUNTO: int = 40;
  static var TAM_AUTOR: int = 40;
  static var TAM_EDITORA: int = 60;
  static var TAM_IDIOMA: int = 30;
  static var TAM_USUARIO: int = 20;
  static var TAM_PAIS: int = 53;
  static var TAM_PROFISSAO: int = 60;
  static var TAM_LIVRO: int = 143;
  static var TAM_LIVASS: int = 23;
  static var TAM_LIVAUT: int = 23;
  static var TAM_CLIENTE: int = 135;
  static var TAM_ENDERECO: int = 123;
  static var TAM_VENDA: int = 56;

  /* variaveis gerais */

  var bopcao: boolean;
  var opmenu: char;
  var g_nPosChave, g_nTamChave: int;
  var g_nPreco: double;
  var g_SalvarInclusao: boolean;

  var tAssunto: regAssunto = new regAssunto();
  var tAutor: regAutor = new regAutor();
  var tEditora: regEditora = new regEditora();
  var tIdioma: regIdioma = new regIdioma();
  var tEndereco: regEndereco = new regEndereco();
  var tPais: regPais = new regPais();
  var tProfissao: regProfissao = new regProfissao();
  var tLivro: regLivro = new regLivro();
  var tLivroAss: regLivroAss = new regLivroAss();
  var tLivroAut: regLivroAut = new regLivroAut();
  var tCliente: regCliente = new regCliente();
  var tUsuario: regUsuario = new regUsuario();
  var tVenda: regVenda = new regVenda();

  var tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco,
      tfPais, tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente,
      tfUsuario, tfVenda: FileStream;

  public function Livrus() {     
  }

/*--- Rotinas b�sicas --------------------------------------------------------*/

/*------------------------------------------------------------------------------
Fun��o que retorna um peda�o de uma string.
str - indica a string
nini - indica a posicao inicial do pedaco
ntam - indica o tamanho do pedaco
retorna - o peda�o da string
------------------------------------------------------------------------------*/
  function copy(str: String, nini: int, ntam: int): String {
	return str.Substring(nini-1,ntam);
  }

/*------------------------------------------------------------------------------
Repete um texto um n�mero determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*/
  private function repete(sTexto: String, nQtd: int): String
  { var ncont: int;
    var	sret: String = "";

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
  private function esp(sTexto: String, nTam: int): String {
   var sret: String;

	sret = sTexto + repete(" ",nTam-sTexto.Length);
	return sret;
  }
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto atrav�s de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou n�o a chave dentro do texto
------------------------------------------------------------------------------*/
  private function strRelativa(sTexto: String, sChave: String): boolean {
    var nCont, nTamChave, nTamTexto: int;
    var bret: boolean;
    var sPedaco: String;
    
    bret = false;
    nCont = 1;
    nTamChave = sChave.Length;
    nTamTexto = sTexto.Length;
    if (nTamChave <= nTamTexto) {
      while (nCont <= (nTamTexto-nTamChave+1)) {
         sPedaco = copy(sTexto,nCont,nTamChave);
         if (sPedaco.Equals(sChave))
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
cond - condi��o de retorno de aninhamento
retorna - o d�gito correto
------------------------------------------------------------------------------*/
  public function modulo11(svalor: String, ndig: int): int {
  var ncont, nsoma, nvalor, npos: int;
  var slocal, sres: String;
  
   ncont=0;
   slocal="";
   while (ncont < 11) {
     slocal=svalor.Substring(ncont,1) + slocal;
     ncont++;
   }
   nsoma=0;
   if (ndig == 1)
     ncont=2;
   else
     ncont=1;
   npos=2;
   while (ncont < 11) {
     sres = slocal.Substring(ncont,1);
     nvalor = int.Parse(sres);
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
  public function ValidaCPF(cpf: String): boolean {
  var scpf: String;

  if (cpf.Length==14) {
    scpf=cpf.Substring(0,3)+cpf.Substring(4,3)+cpf.Substring(8,3)+
	cpf.Substring(12,2);
	if ( (modulo11(scpf,1)==int.Parse(cpf.Substring(12,1))) &&
    (modulo11(scpf,2)==int.Parse(cpf.Substring(13,1))) )
  	return true;
	else
  	return false;
  } else
    return false;
  }
/*------------------------------------------------------------------------------
Valida��o de um n�mero ISBN qualquer.
isbn - a mstring com o n�mero do ISBN
retorna - se � valido ou n�o
------------------------------------------------------------------------------*/
  public function ValidaISBN(isbn: String): boolean {
   var sisbn, sdigito, snum: String;
   var nvalor, nsoma, ncont: int;
  
  if (isbn.Length==13) {
    sdigito = isbn.Substring(isbn.Length-1, 1);
    sisbn="";
    for(ncont = 0; ncont < isbn.Length-1; ncont++)  {
      if (isbn.Substring(ncont,1)!="-")
        sisbn = sisbn + isbn.Substring(ncont,1);
    }
    if (sdigito=="X")
      nsoma = 10;
    else {
      nvalor = int.Parse(sdigito);
      nsoma = nvalor;
    }
    for(ncont = 1; ncont <= 9; ncont++)  {
      snum = sisbn.Substring(ncont-1, 1);
      nvalor = int.Parse(snum);
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
function digitaSenha(sRotulo: String, nTamSenha: int): String {
 var sSenha: String = "";
// var sLetra: char;
// var ncont: int;

  System.Console.Write(sRotulo);
  sSenha = System.Console.In.ReadLine();
/*
  ncont  = 0;
  sLetra = '\0';
  while((sLetra!='\r') && (ncont < nTamSenha)) {
	sLetra = (char) System.Console.Read();
	if (sLetra!='\r') {
	   sSenha = sSenha + sLetra;
	}
	ncont++;
  }
System.Console.WriteLine();
*/
return sSenha;
}
/*------------------------------------------------------------------------------
Valida��o de um n�mero qualquer.
sRotulo - o texto antes de se digitar o n�mero
sNumero - a String com o valor do n�mero
retorna - o sNumero
------------------------------------------------------------------------------*/
function validaNumero(sRotulo: String, sNumero: String): String
{ var nnum: double;
  var nStatus: int;

nStatus = -1;
 while (nStatus!=0) {
  System.Console.Write(sRotulo);
  sNumero = System.Console.In.ReadLine();
  try {
	  nnum = float.Parse(sNumero);
	  if (nnum < 1)
		 System.Console.WriteLine(MSG_NUMINV);
	  else
		 nStatus=0;
  } catch(e: System.Exception) {
	System.Console.WriteLine(MSG_NUMINV);
  }
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
function validaDataHora(sRotulo: String, sDataHora: String, bSoData: boolean): String
{ var bvalida, bdatavalida, bhoravalida: boolean;
  var sdia, smes, sano, shora, smin, sseg: String;
  var ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam: int;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;
while (bvalida==false) {
  System.Console.Write(sRotulo);
  sDataHora = System.Console.In.ReadLine();
  if (sDataHora.Length==ntam) {
	sdia = copy(sDataHora,1,2);
	ndia = int.Parse(sdia);
	smes = copy(sDataHora,4,2);
	nmes = int.Parse(smes);
	sano = copy(sDataHora,7,4);
	nano = int.Parse(sano);

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
	   System.Console.WriteLine(MSG_DATAINV);
	} else {
	  if (bdatavalida) {
		  shora = copy(sDataHora,12,2);
		  nhora = int.Parse(shora);
		  smin = copy(sDataHora,15,2);
		  nmin = int.Parse(smin);
		  sseg = copy(sDataHora,18,2);
		  nseg = int.Parse(sseg);

		  if ((nhora >= 0) && (nhora <= 23)) {
			if ((nmin >= 0) && (nmin <= 59)) {
			  if ((nseg >= 0) && (nseg <= 59))
				 bhoravalida = true;
			}
		  }

		  if (bhoravalida)
		   bvalida = true;
		  else
		   System.Console.WriteLine(MSG_DTHRINV);
	  } else
        System.Console.WriteLine(MSG_DTHRINV);
    }
  } else {
	if (bSoData==true) System.Console.WriteLine(MSG_DATAINV);
	else System.Console.WriteLine(MSG_DTHRINV);
  }
}
return sDataHora;
}
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
private function retDataHora(): String {
  return DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss");
}
/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
function tamArq(sArq: FileStream): long {
  return sArq.Length;
}
/*------------------------------------------------------------------------------
Verifica se chegou ao fim do arquivo.
sArq - o arquivo
ntam - o tamanho do arquivo
retorna - se chegou ao fim do arquivo
------------------------------------------------------------------------------*/
function fimArq(sArq: FileStream): boolean {
 if (sArq.Position == sArq.Length)
	return true;
 else
	return false;
}
/*------------------------------------------------------------------------------
L� uma linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho da linha
nTamCRLF - o tamanho do retorno da linha
npos - posicao dentro do arquivo
retorna - o texto lido
------------------------------------------------------------------------------*/
function lerArq(sArq: FileStream, nTamLinha: int, nTamCRLF: int): String {
var nLidos, ncont: int;
var slinha: Byte[] = new Byte[TAM_MAX_REG];
var sret: String = "";

//StreamReader sLer = new StreamReader(sArq);
//sret = sLer.ReadLine();

nLidos = sArq.Read(slinha, 0,(nTamLinha + nTamCRLF));

if (nLidos != (nTamLinha + nTamCRLF))
  sret = "";
else {
  for(ncont=0; ncont < (nLidos - nTamCRLF); ncont++)
	sret = sret + Convert.ToChar(slinha[ncont]);
}

return sret;
}
/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condi��o para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
function abrecriaArqs(bAbre: boolean): void
{
if (bAbre) {
  if (File.Exists(ARQ_ASSUNTO))
	tfAssunto = new FileStream(ARQ_ASSUNTO,FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_ASSUNTO);
  if (File.Exists(ARQ_AUTOR))
	tfAutor = new FileStream(ARQ_AUTOR, FileMode.Open, FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_AUTOR);
  if (File.Exists(ARQ_EDITORA))
	tfEditora = new FileStream(ARQ_EDITORA,FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_EDITORA);
  if (File.Exists(ARQ_IDIOMA))
	tfIdioma = new FileStream(ARQ_IDIOMA, FileMode.Open, FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_IDIOMA);
  if (File.Exists(ARQ_ENDERECO))
	tfEndereco= new FileStream(ARQ_ENDERECO,FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_ENDERECO);
  if (File.Exists(ARQ_PAIS))
	tfPais = new FileStream(ARQ_PAIS, FileMode.Open, FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_PAIS);
  if (File.Exists(ARQ_PROFISSAO))
   tfProfissao=new FileStream(ARQ_PROFISSAO,FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_PROFISSAO);
  if (File.Exists(ARQ_LIVRO))
	tfLivro = new FileStream(ARQ_LIVRO, FileMode.Open, FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_LIVRO);
  if (File.Exists(ARQ_LIVASS))
	tfLivroAss = new FileStream(ARQ_LIVASS, FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_LIVASS);
  if (File.Exists(ARQ_LIVAUT))
	tfLivroAut = new FileStream(ARQ_LIVAUT, FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_LIVAUT);
  if (File.Exists(ARQ_CLIENTE))
	tfCliente = new FileStream(ARQ_CLIENTE, FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_CLIENTE);
  if (File.Exists(ARQ_USUARIO))
	tfUsuario = new FileStream(ARQ_USUARIO, FileMode.Open,FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_USUARIO);
  if (File.Exists(ARQ_VENDA))
	tfVenda = new FileStream(ARQ_VENDA, FileMode.Open, FileAccess.ReadWrite);
  else
	System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_VENDA);
} else {
  tfAssunto = new FileStream(ARQ_ASSUNTO,FileMode.Create,FileAccess.ReadWrite);
  tfAutor = new FileStream(ARQ_AUTOR,FileMode.Create,FileAccess.ReadWrite);
  tfEditora = new FileStream(ARQ_EDITORA,FileMode.Create,FileAccess.ReadWrite);
  tfIdioma = new FileStream(ARQ_IDIOMA,FileMode.Create,FileAccess.ReadWrite);
  tfEndereco= new FileStream(ARQ_ENDERECO,FileMode.Create,FileAccess.ReadWrite);
  tfPais = new FileStream(ARQ_PAIS,FileMode.Create,FileAccess.ReadWrite);
  tfProfissao=new FileStream(ARQ_PROFISSAO,FileMode.Create,FileAccess.ReadWrite);
  tfLivro = new FileStream(ARQ_LIVRO,FileMode.Create,FileAccess.ReadWrite);
  tfLivroAss = new FileStream(ARQ_LIVASS,FileMode.Create,FileAccess.ReadWrite);
  tfLivroAut = new FileStream(ARQ_LIVAUT,FileMode.Create,FileAccess.ReadWrite);
  tfCliente = new FileStream(ARQ_CLIENTE,FileMode.Create,FileAccess.ReadWrite);
  tfUsuario = new FileStream(ARQ_USUARIO,FileMode.Create,FileAccess.ReadWrite);
  tfVenda = new FileStream(ARQ_VENDA,FileMode.Create,FileAccess.ReadWrite);
}

}
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
function fechaArqs(): void
{
   tfAssunto.Close();
   tfAutor.Close();
   tfEditora.Close();
   tfIdioma.Close();
   tfEndereco.Close();
   tfPais.Close();
   tfProfissao.Close();
   tfLivro.Close();
   tfLivroAss.Close();
   tfLivroAut.Close();
   tfCliente.Close();
   tfUsuario.Close();
   tfVenda.Close();
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
function pesqArq(sArq: FileStream, sChave: String, nPosChave: int,
		nTamChave: int, nTamLinha: int): String {
  var sres = "", slinha: String = "";
  var bQuebra: boolean;
  var nPosicao: long;

	bQuebra = false;
	sArq.Seek(0,SeekOrigin.Begin);
	while (!fimArq(sArq) && bQuebra == false) {
	  slinha = lerArq(sArq, nTamLinha, TAM_CRLF);
	  if (slinha.Equals("")==false)
		sres = copy(slinha, nPosChave, nTamChave).Trim();
	  if (sres.Equals(sChave))
		bQuebra = true;
	}
	nPosicao = sArq.Position - (nTamLinha + TAM_CRLF);
	if (nPosicao > 0)
	  sArq.Seek(nPosicao, SeekOrigin.Current);
	else
	  sArq.Seek(0, SeekOrigin.Begin);
	if (sres.Equals(sChave) == false)
	  return ("");
	else
	  return (copy(slinha, 1, nTamLinha));

}
/*------------------------------------------------------------------------------
Pesquisa se tem linha exclu�da sen�o vai para a �ltima linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
function pesqLinhaExcluida(sArq: FileStream, nTamLinha: int): void {
var sExcluido: String;

  sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha);
  if (sExcluido.Equals(""))
	 sArq.Seek(tamArq(sArq),SeekOrigin.Begin);
}
/*------------------------------------------------------------------------------
Pesquisa o maior c�digo num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior c�digo
------------------------------------------------------------------------------*/
function pesqMaxCod(sArq: FileStream, nPosChave: int,
		nTamChave: int, nTamLinha: int): String {
  var sres, slinha: String = "";
  var bQuebra: boolean;
  var nMaior, nCod: int;

	bQuebra = false;
	nMaior = 0;
	sArq.Seek(0,SeekOrigin.Begin);
	while (!fimArq(sArq) && bQuebra == false) {
	  slinha = lerArq(sArq, nTamLinha, TAM_CRLF);
	  if (slinha.Equals("")==false) {
		sres = copy(slinha,nPosChave,nTamChave).Trim();
		nCod = int.Parse(sres);
		if (nCod > nMaior)
		   nMaior = nCod;
	  }
	}
	pesqLinhaExcluida(sArq, nTamLinha);
	nCod = (nMaior+1);
	sres = nCod.ToString();

return(sres);
}
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro n�o foi gravado
------------------------------------------------------------------------------*/
function escreveArq(sArq: FileStream, sTexto: String, sMsgAcerto: String,
	sMsgErro: String): void {
  var slinha: Byte[] = new Byte[TAM_MAX_REG];
  var ntam, ncont: int;
  try {
//	StreamWriter sGravar = new StreamWriter(sArq);
	sTexto = sTexto + CRLF;
	ntam = sTexto.Length;
	for (ncont=0; ncont < ntam; ncont++)
		slinha[ncont] = Convert.ToByte(sTexto[ncont]);
	sArq.Write(slinha, 0, ntam);
//	sGravar.WriteLine(sTexto);
	System.Console.WriteLine(sMsgAcerto);
  } catch(e: System.Exception) {
	System.Console.WriteLine(sMsgErro);
  }
}
/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
function LinhaReg(sreg: ctArqs): String {
var slinha: String = "";

if (sreg==ctArqs.opAssunto) {
   slinha = esp(tAssunto.codigo,10)+esp(tAssunto.assunto,30);
} else if (sreg==ctArqs.opAutor)
   slinha = esp(tAutor.codigo,10)+esp(tAutor.autor,30);
else if (sreg==ctArqs.opEditora)
   slinha = esp(tEditora.codigo,10)+esp(tEditora.editora,50);
else if (sreg==ctArqs.opEndereco)
   slinha = esp(tEndereco.codigo,10)+esp(tEndereco.logradouro,40)+
   esp(tEndereco.bairro,15)+esp(tEndereco.cep,8)+esp(tEndereco.cidade,30)+
   esp(tEndereco.estado,20);
else if (sreg==ctArqs.opIdioma)
   slinha = esp(tIdioma.codigo,10)+esp(tIdioma.idioma,20);
else if (sreg==ctArqs.opPais)
   slinha = esp(tPais.codigo,3)+esp(tPais.pais,50);
else if (sreg==ctArqs.opProfissao)
   slinha = esp(tProfissao.codigo,10)+esp(tProfissao.profissao,50);
else if (sreg==ctArqs.opUsuario)
   slinha = esp(tUsuario.login,10)+esp(tUsuario.senha,10);
else if (sreg==ctArqs.opLivro)
   slinha = esp(tLivro.isbn,13)+esp(tLivro.titulo,50)+
   esp(tLivro.edicao,10)+esp(tLivro.anopubli,10)+esp(tLivro.codeditora,10)+
   esp(tLivro.volume,10)+esp(tLivro.codidioma,10)+esp(tLivro.npaginas,10)+
   esp(tLivro.preco,10)+esp(tLivro.qtdestoque,10);
else if (sreg==ctArqs.opLivroAss)
   slinha = esp(tLivroAss.isbn,13)+esp(tLivroAss.codassunto,10);
else if (sreg==ctArqs.opLivroAut)
   slinha = esp(tLivroAut.isbn,13)+esp(tLivroAut.codautor,10);
else if (sreg==ctArqs.opCliente)
   slinha = esp(tCliente.cpf,14)+esp(tCliente.nome,30)+
   esp(tCliente.email,30)+esp(tCliente.identidade,10)+esp(tCliente.sexo,1)+
   esp(tCliente.telefone,17)+esp(tCliente.dtnascimento,10)+
   esp(tCliente.codendereco,10)+esp(tCliente.codpais,3)+
   esp(tCliente.codprofissao,10);
else if (sreg==ctArqs.opVenda)
   slinha = esp(tVenda.dthrvenda,19)+esp(tVenda.cpf,14)+
   esp(tVenda.isbn,13)+esp(tVenda.precovenda,10);

return(slinha);
}
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
function tamReg(sreg: ctArqs): int {
var nret: int = 0;

if (sreg==ctArqs.opAssunto) nret = TAM_ASSUNTO;
else if (sreg==ctArqs.opAutor) nret = TAM_AUTOR;
else if (sreg==ctArqs.opEditora) nret = TAM_EDITORA;
else if (sreg==ctArqs.opEndereco) nret = TAM_ENDERECO;
else if (sreg==ctArqs.opIdioma) nret = TAM_IDIOMA;
else if (sreg==ctArqs.opPais) nret = TAM_PAIS;
else if (sreg==ctArqs.opProfissao) nret = TAM_PROFISSAO;
else if (sreg==ctArqs.opUsuario) nret = TAM_USUARIO;
else if (sreg==ctArqs.opLivro) nret = TAM_LIVRO;
else if (sreg==ctArqs.opLivroAss) nret = TAM_LIVASS;
else if (sreg==ctArqs.opLivroAut) nret = TAM_LIVAUT;
else if (sreg==ctArqs.opCliente) nret = TAM_CLIENTE;
else if (sreg==ctArqs.opVenda) nret = TAM_VENDA;

return(nret);
}
/*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo ser� retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
function rotulo(sreg: ctArqs, nNum: int): String {
var sret: String = "";

if (sreg==ctArqs.opAssunto) {
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
} else if (sreg==ctArqs.opAutor) {
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
} else if (sreg==ctArqs.opEditora) {
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
} else if (sreg==ctArqs.opEndereco) {
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
} else if (sreg==ctArqs.opIdioma) {
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
} else if (sreg==ctArqs.opPais) {
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
} else if (sreg==ctArqs.opProfissao) {
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
} else if (sreg==ctArqs.opUsuario) {
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
} else if (sreg==ctArqs.opLivro) {
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
} else if (sreg==ctArqs.opLivroAss) {
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
} else if (sreg==ctArqs.opLivroAut) {
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
} else if (sreg==ctArqs.opCliente) {
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
} else if (sreg==ctArqs.opVenda) {
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
function ContinuaSN(nlinha: int, nQtdLinha: int): boolean {
 var bSOp, bret: boolean;
 var opCSubMenu: char;

bret = false;
if (nlinha > 0) {
  if ((nlinha % nQtdLinha) == 0) {
	  bSOp = true;
	  while(bSOp) {
	   menu(13);
	   opCSubMenu = System.Console.In.ReadLine()[0];
	   if ((opCSubMenu=='S') || (opCSubMenu=='s')) bSOp = false;
	   else if ((opCSubMenu=='N') || (opCSubMenu=='n')) {
		  bret = true;
		  bSOp = false;
	   } else System.Console.WriteLine(MSG_ERRO);
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
function ListarTodos(sArq: FileStream, sreg: ctArqs, sChave: String,
   nPosChave: int, nTamChave: int, nTamLinha: int, nQtdLinha: int,
   bPesqRelativa: boolean): boolean {
  var bQuebra, bAchou, bRet: boolean;
  var nCont: int;
  var sres: String = "";
  var slinha: String  = "";

  bRet = false;

	bQuebra = false;
	nCont = 0;
	mostrarDados(sreg, "", 2);
	sArq.Seek(0,SeekOrigin.Begin);
	while (!fimArq(sArq) && bQuebra == false) {
	  slinha = lerArq(sArq, nTamLinha, TAM_CRLF);
	  if (slinha.Equals("")==false) {
		if (bPesqRelativa) {
		  sres = copy(slinha,nPosChave,nTamChave).Trim();
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
function ListarRegLigados(sArq1: FileStream, sreg1: ctArqs, nPosChave1: int,
nTamChave1: int, nPosChave2: int, nTamChave2: int, sChave: String,
sArq2: FileStream, sreg2: ctArqs, nPosChave3: int, nQtdLinha: int): void {
  var slinha1: String = "";
  var bQuebra, bRet: boolean;
  var nCont: int;
  var sCodigo1, sCodigo2, slinha2: String;

	bRet = false;
	nCont = 0;
	bQuebra = false;
	mostrarDados(sreg2, "", 2);
	sArq1.Seek(0,SeekOrigin.Begin);
	while (!fimArq(sArq1) && bQuebra == false) {
	  slinha1 = lerArq(sArq1, tamReg(sreg1), TAM_CRLF);
	  if (slinha1.Equals("")==false) {
		sCodigo1 = copy(slinha1,nPosChave1,nTamChave1).Trim();
		if (sCodigo1.Equals(sChave)) {
		  sCodigo2 = copy(slinha1,nPosChave2,nTamChave2).Trim();
		  slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
		  mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
		  bRet = true;
		  nCont++;
		}
	  }
	  bQuebra = ContinuaSN(nCont, nQtdLinha);
	}
	if (bRet==false)
	   System.Console.WriteLine(rotulo(sreg2,0));
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
function validaEntrada(sArq: FileStream, sreg: ctArqs, nTexto: int,
		sEntrada: String, nTentativas: int,
		bPesqRelativa: boolean, bTipoEntrada: ctTipo): String {
  var bQuebra: boolean;
  var sres, sTexto, sMsgErro, sLocal: String;
  var ncont, nPosChave, nTamChave, nTamLinha: int;

sres = "";
sLocal = sEntrada;

nTamLinha = tamReg(sreg);
sMsgErro = rotulo(sreg,0);
sTexto = rotulo(sreg,nTexto);
nPosChave = g_nPosChave;
nTamChave = g_nTamChave;

ncont = 1;
bQuebra = false;
  while ((bQuebra==false) && (ncont <= nTentativas )) {
	if (bTipoEntrada==ctTipo.opTexto) {
	  System.Console.Write(sTexto);
	  sLocal = System.Console.In.ReadLine();
	} else if (bTipoEntrada==ctTipo.opNumero)
	   sLocal = validaNumero(sTexto,sLocal);
	else if (bTipoEntrada==ctTipo.opData)
	   sLocal = validaDataHora(sTexto,sLocal,true);
	else if (bTipoEntrada==ctTipo.opDataHora)
	   sLocal = validaDataHora(sTexto,sLocal,false);
	else if (bTipoEntrada==ctTipo.opSenha) {
	   sLocal = digitaSenha(sTexto, 10);
	}

    if (bPesqRelativa) {
       if (ListarTodos(sArq, sreg, sLocal, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, true))
        sres = " ";
    } else
       sres = pesqArq(sArq, sLocal, nPosChave, nTamChave, nTamLinha);

	if (sres.Equals(""))
	   System.Console.WriteLine(sMsgErro);
	else
	   bQuebra = true;

    ncont++;
  }
return(sres);
}
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
function frmSplash(): void {
var cont: int;

 System.Console.WriteLine("*---------------------------------------" +
 "-------------------------------------*");
 System.Console.WriteLine("| LL    II VV   VV RRRRR  UU  UU   SSSS " +
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |");
 System.Console.WriteLine("| LL    II  VV VV  RR   R UU  UU  SS    " +
 " VV VV  II RR   R  TT  UU  UU  SS    |");
 System.Console.WriteLine("| LL    II   VVV   RRRRR  UU  UU    SS  " +
 "  VVV   II RRRRR   TT  UU  UU    SS  |");
 System.Console.WriteLine("| LLLLL II    V    RR   R  UUUU  SSSS   " +
 "   V    II RR   R  TT   UUUU  SSSS   |");
 System.Console.WriteLine("*---------------------------------------" +
 "-------------------------------------*");
 for(cont = 1; cont <= 18; cont++) System.Console.WriteLine();
 System.Console.Write(MSG_PRESS);
 System.Console.In.ReadLine();
}
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
function frmSobre(): void {
 var cont: int;

 System.Console.WriteLine("*------------------------------------------------------------*");
 System.Console.WriteLine("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |");
 System.Console.WriteLine("|  LL        II   VV     VV   RR     R  UU    UU  SS         |");
 System.Console.WriteLine("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |");
 System.Console.WriteLine("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |");
 System.Console.WriteLine("|  LLLL      II      VVV      RR RR     UU    UU        SS   |");
 System.Console.WriteLine("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |");
 System.Console.WriteLine("|                                                            |");
 System.Console.WriteLine("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |");
 System.Console.WriteLine("|   VV     VV   II  RR     R     TT     UU    UU  SS         |");
 System.Console.WriteLine("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |");
 System.Console.WriteLine("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |");
 System.Console.WriteLine("|      VVV      II  RR RR        TT     UU    UU        SS   |");
 System.Console.WriteLine("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |");
 System.Console.WriteLine("|                                                            |");
 System.Console.WriteLine("|                                               Versao 1.0.0 |");
 System.Console.WriteLine("| Sistema integrante do projeto Livrus Virtus.               |");
 System.Console.WriteLine("| Todos os direitos reservados para Henrique F. de Souza.    |");
 System.Console.WriteLine("| Versao programada na linguagem JScript.NET.                |");
 System.Console.WriteLine("*------------------------------------------------------------*");
 for(cont = 1; cont <= 4; cont++) System.Console.WriteLine();
 System.Console.Write(MSG_PRESS);
 System.Console.In.ReadLine();
}
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
function frmLogin(): boolean {
  var bret: boolean;
  var slinha: String;

  bret = false;
  System.Console.WriteLine("*--------------------------------------------------------------*");
  System.Console.WriteLine("| Login do sistema                                             |");
  System.Console.WriteLine("*--------------------------------------------------------------*");
  slinha = validaEntrada(tfUsuario, ctArqs.opUsuario, 1, tUsuario.login, 3,
		false, ctTipo.opTexto);
  if (slinha.Equals("")==false) {
	 slinha = validaEntrada(tfUsuario, ctArqs.opUsuario, 2, tUsuario.senha, 3,
		false, ctTipo.opSenha);
	 if (slinha.Equals("")==false) {
		tUsuario.login = copy(slinha, 1, 10).Trim();
		tUsuario.senha = copy(slinha, 11, 10).Trim();
        bret = true;
     }
  }
  System.Console.WriteLine();
  return(bret);
}
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o n�mero do menu
------------------------------------------------------------------------------*/
function menu(num: int): void {
 if (num==1) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| (C)adastros        (P)esquisas     (V)endas        (O)p��es  |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==2) {
   System.Console.WriteLine("*---------------------------------*");
   System.Console.WriteLine("| 01. Cadastro de Assuntos        |");
   System.Console.WriteLine("| 02. Cadastro de Autores         |");
   System.Console.WriteLine("| 03. Cadastro de Editoras        |");
   System.Console.WriteLine("| 04. Cadastro de Endere�os       |");
   System.Console.WriteLine("| 05. Cadastro de Idiomas         |");
   System.Console.WriteLine("| 06. Cadastro de Pa�ses          |");
   System.Console.WriteLine("| 07. Cadastro de Profiss�es      |");
   System.Console.WriteLine("| 08. Cadastro de Clientes        |");
   System.Console.WriteLine("| 09. Cadastro de Livros          |");
   System.Console.WriteLine("| 10. Voltar ao menu              |");
   System.Console.WriteLine("*---------------------------------*");
 } else if (num==3) {
   System.Console.WriteLine("*---------------------------------*");
   System.Console.WriteLine("| 01. Consulta de Assuntos        |");
   System.Console.WriteLine("| 02. Consulta de Autores         |");
   System.Console.WriteLine("| 03. Consulta de Editoras        |");
   System.Console.WriteLine("| 04. Consulta de Endere�os       |");
   System.Console.WriteLine("| 05. Consulta de Idiomas         |");
   System.Console.WriteLine("| 06. Consulta de Pa�ses          |");
   System.Console.WriteLine("| 07. Consulta de Profiss�es      |");
   System.Console.WriteLine("| 08. Consulta de Clientes        |");
   System.Console.WriteLine("| 09. Consulta de Livros          |");
   System.Console.WriteLine("| 10. Voltar ao menu              |");
   System.Console.WriteLine("*---------------------------------*");
 } else if (num==4) {
   System.Console.WriteLine("*---------------------------------*");
   System.Console.WriteLine("| 01. Vender Livros               |");
   System.Console.WriteLine("| 02. Vendas Realizadas           |");
   System.Console.WriteLine("| 03. Voltar ao menu              |");
   System.Console.WriteLine("*---------------------------------*");
 } else if (num==5) {
   System.Console.WriteLine("*---------------------------------*");
   System.Console.WriteLine("| 01. Alterar senha               |");
   System.Console.WriteLine("| 02. Sobre o sistema             |");
   System.Console.WriteLine("| 03. Sair do sistema             |");
   System.Console.WriteLine("| 04. Voltar ao menu              |");
   System.Console.WriteLine("*---------------------------------*");
 } else if (num==6) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==7) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| (1) Salvar inclus�o       (2) Voltar ao menu                 |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==8) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==9) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| (1) Salvar altera��o      (2) Voltar ao menu                 |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==10) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| Certeza de excluir? (S/N)                                    |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==11) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| Deseja sair do sistema? (S/N)                                |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==12) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==13) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| Deseja continuar? (S/N)                                      |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 } else if (num==14) {
   System.Console.WriteLine("*--------------------------------------------------------------*");
   System.Console.WriteLine("| Salvar inclus�o (S/N)                                        |");
   System.Console.WriteLine("*--------------------------------------------------------------*");
 }
 System.Console.Write(MSG_OPCAO);
}

/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a a��o a ser realizada
------------------------------------------------------------------------------*/
function frmCadastros(sreg: ctArqs, sacao: ctAcao): void {
var slinha: String = "";

if (sreg==ctArqs.opAssunto) {
   if (sacao==ctAcao.opNovo) {
	  tAssunto.codigo = pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao.opPesquisar) {
	 slinha = validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,ctTipo.opNumero);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opAutor) {
   if (sacao==ctAcao.opNovo) {
	  tAutor.codigo = pesqMaxCod(tfAutor, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,false,ctTipo.opNumero);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opEditora) {
   if (sacao==ctAcao.opNovo) {
	  tEditora.codigo = pesqMaxCod(tfEditora, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,false,ctTipo.opNumero);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opEndereco) {
   if (sacao==ctAcao.opNovo) {
	  tEndereco.codigo = pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
			  false,ctTipo.opNumero);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opIdioma) {
   if (sacao==ctAcao.opNovo) {
	  tIdioma.codigo = pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,false,ctTipo.opNumero);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opPais) {
   if (sacao==ctAcao.opNovo) {
	  System.Console.Write(rotulo(sreg, 1));
	  tPais.codigo = System.Console.In.ReadLine();
	  slinha = pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg));
	  if (slinha.Equals("")) {
		 pesqLinhaExcluida(tfPais, tamReg(sreg));
		 mostrarDados(sreg, "", 1);
		 subMenu(7, sreg);
	  } else System.Console.WriteLine(MSG_REGEXST);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, ctTipo.opTexto);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  System.Console.WriteLine(rotulo(sreg, 1) + tPais.codigo);
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opProfissao) {
   if (sacao==ctAcao.opNovo) {
	  tProfissao.codigo = pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
			  false,ctTipo.opNumero);
	  if (slinha.Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opLivro) {
   if (sacao==ctAcao.opNovo) {
	  System.Console.Write(rotulo(sreg, 1));
	  tLivro.isbn = System.Console.In.ReadLine();
	  if (ValidaISBN(tLivro.isbn)) {
		  slinha = pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg));
		  if (slinha.Equals("")) {
			 pesqLinhaExcluida(tfLivro, tamReg(sreg));
			 mostrarDados(sreg, "", 1);
			 subMenu(7, sreg);
			 frmCadLigados(ctArqs.opLivroAss, ctAcao.opNovo, tLivro.isbn);
			 frmCadLigados(ctArqs.opLivroAut, ctAcao.opNovo, tLivro.isbn);
		  } else System.Console.WriteLine(MSG_REGEXST);
	  } else System.Console.WriteLine(MSG_ISBNINV);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,ctTipo.opTexto);
	  if (slinha.Equals("")==false) {
		 mostrarDados(sreg, "", 2);
		 mostrarDados(sreg, slinha, 3);
		 subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  System.Console.WriteLine(rotulo(sreg, 1) + tLivro.isbn);
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
	  frmCadLigados(ctArqs.opLivroAss, ctAcao.opExcluir, tLivro.isbn);
	  System.Console.WriteLine("Assuntos dos livros exclu�dos, inclua novos!");
	  frmCadLigados(ctArqs.opLivroAss, ctAcao.opNovo, tLivro.isbn);
	  frmCadLigados(ctArqs.opLivroAut, ctAcao.opExcluir, tLivro.isbn);
	  System.Console.WriteLine("Autores dos livros exclu�dos, inclua novos!");
	  frmCadLigados(ctArqs.opLivroAut, ctAcao.opNovo, tLivro.isbn);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
	  System.Console.WriteLine("Assuntos dos livros sendo exclu�dos!");
	  frmCadLigados(ctArqs.opLivroAss, ctAcao.opExcluir, tLivro.isbn);
	  System.Console.WriteLine("Autores dos livros sendo exclu�dos!");
	  frmCadLigados(ctArqs.opLivroAut, ctAcao.opExcluir, tLivro.isbn);
   }
} else if (sreg==ctArqs.opCliente) {
   if (sacao==ctAcao.opNovo) {
	  System.Console.Write(rotulo(sreg, 1));
	  tCliente.cpf = System.Console.In.ReadLine();
	  if (ValidaCPF(tCliente.cpf)) {
		  slinha = pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg));
		  if (slinha.Equals("")) {
			 pesqLinhaExcluida(tfCliente, tamReg(sreg));
			 mostrarDados(sreg, "", 1);
			 subMenu(7, sreg);
		  } else System.Console.WriteLine(MSG_REGEXST);
	  } else System.Console.WriteLine(MSG_CPFINV);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,ctTipo.opTexto);
	  if (slinha.Equals("")==false) {
		 mostrarDados(sreg, "", 2);
		 mostrarDados(sreg, slinha, 3);
		 subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao.opAlterar) {
	  System.Console.WriteLine(rotulo(sreg, 1) + tCliente.cpf);
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao.opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs.opVenda) {
   if (sacao==ctAcao.opNovo) {
	  tVenda.dthrvenda = retDataHora();
	  System.Console.WriteLine(rotulo(sreg, 1) + tVenda.dthrvenda);
	  slinha = pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
	  if (slinha.Equals("")) {
		 slinha = validaEntrada(tfCliente,ctArqs.opCliente,1,tVenda.cpf,3,
				 false,ctTipo.opTexto);
		 if (slinha.Equals("")==false) {
			tVenda.cpf = copy(slinha,1,14).Trim();
			if (ValidaCPF(tVenda.cpf)) {
			   System.Console.Write(" " + rotulo(ctArqs.opCliente, 2)); /* Nome */
			   System.Console.WriteLine(copy(slinha, g_nPosChave, g_nTamChave));
			   frmCadLigados(ctArqs.opVenda, ctAcao.opNovo, tVenda.cpf);
			} else System.Console.WriteLine(MSG_CPFINV);
		 }
	  } else System.Console.WriteLine(MSG_REGEXST);
   } else if (sacao==ctAcao.opPesquisar) {
	  slinha = validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
			  false,ctTipo.opDataHora);
	  if (slinha.Equals("")==false) {
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
function frmConsultas(sreg: ctArqs, sacao: ctAcao): void {
 var slinha: String = "";

if (sreg==ctArqs.opAssunto) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opAutor) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opEditora) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opEndereco) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1,
			  true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
		 3, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opIdioma) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opPais) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opProfissao) {
   if (sacao==ctAcao.opPesquisar)
	 slinha = validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
			 true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opLivro) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
		1, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opCliente) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
		1, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs.opVenda) {
   if (sacao==ctAcao.opPesquisar)
	  slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,ctTipo.opTexto);
   else if (sacao==ctAcao.opListarTodos) {
	  if (ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System.Console.WriteLine(rotulo(sreg, 0));
   }
}
if (slinha.Equals(""))
   System.Console.Write("");
}
/*------------------------------------------------------------------------------
Mostra a tela de altera��o de senha do sistema e realiza a altera��o.
------------------------------------------------------------------------------*/
function frmAlterarSenha(): void {
 var bQuebra: boolean;
 var sres, sSenhaAtual, sNovaSenha, sConfirmaSenha: String;
 var nopcao: int;

sSenhaAtual = "";
sNovaSenha = "";
sConfirmaSenha = "";

System.Console.WriteLine(rotulo(ctArqs.opUsuario, 1) + tUsuario.login);
nopcao = 1;
bQuebra = false;
while (bQuebra==false) {
  switch(nopcao) {
   case 1: {
       sSenhaAtual = digitaSenha("Senha Atual: ", 10);
	   if (sSenhaAtual.Equals(tUsuario.senha)==false) {
		  System.Console.WriteLine(MSG_SENCONFERE);
		  bQuebra = true;
	   } else nopcao = 2;
	  } break;
   case 2: {
	   sNovaSenha = digitaSenha("Nova Senha: ", 10);
	   sConfirmaSenha = digitaSenha("Confirma Senha: ", 10);
	   if (sNovaSenha.Equals(sConfirmaSenha)==false) {
		  System.Console.WriteLine(MSG_SENCONFIRM);
		  bQuebra = true;
	   } else nopcao = 3;
	  } break;
   case 3: {
	   sres = pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(ctArqs.opUsuario));
	   if (sres.Equals(""))
		 System.Console.WriteLine(MSG_LOGINENCON);
	   else {
		 tUsuario.senha = sConfirmaSenha;
		 subMenu(9,ctArqs.opUsuario);
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
function btnAcao(sreg: ctArqs, sacao: ctAcao): void {
if (sreg==ctArqs.opAssunto) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opAutor) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opEditora) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opEndereco) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opIdioma) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opPais) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opProfissao) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	 escreveArq(tfProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opLivro) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opLivroAss) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opLivroAut) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opCliente) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opVenda) {
   if (sacao==ctAcao.opSalvarInclusao)
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao.opConfirmaExclusao)
	  escreveArq(tfVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs.opUsuario) {
   if (sacao==ctAcao.opSalvarAlteracao)
	  escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
}
}
/*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o n�mero do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
function subMenu(nmenu: int, sreg: ctArqs): void {
 var opSubMenu: String;
 var opCSubMenu: char;
 var bSOp: boolean;

bSOp = true;
switch(nmenu) {
 case 6:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": frmCadastros(sreg, ctAcao.opNovo); break;
	  case "2": frmCadastros(sreg, ctAcao.opPesquisar); break;
	  case "3": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
	}
   } break;
 case 7:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": { btnAcao(sreg, ctAcao.opSalvarInclusao); bSOp = false; } break;
	  case "2": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
	}
   } break;
 case 8:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": { frmCadastros(sreg, ctAcao.opAlterar); bSOp = false; } break;
	  case "2": { frmCadastros(sreg, ctAcao.opExcluir); bSOp = false; } break;
	  case "3": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
	}
   } break;
 case 9:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": { btnAcao(sreg, ctAcao.opSalvarAlteracao); bSOp = false; } break;
	  case "2": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
	}
   } break;
 case 10:{
	while(bSOp) {
	 menu(nmenu);
	 opCSubMenu = System.Console.In.ReadLine()[0];
	 if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
		btnAcao(sreg, ctAcao.opConfirmaExclusao);
		bSOp = false;
	 } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
	 else System.Console.WriteLine(MSG_ERRO);
	}
   } break;
 case 12:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": frmConsultas(sreg, ctAcao.opPesquisar); break;
	  case "2": frmConsultas(sreg, ctAcao.opListarTodos); break;
	  case "3": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
	}
   } break;
 case 14:{
	while(bSOp) {
	 menu(nmenu);
	 opCSubMenu = System.Console.In.ReadLine()[0];
	 if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
		btnAcao(sreg, ctAcao.opSalvarInclusao);
		bSOp = false;
		g_SalvarInclusao = true;
	 } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
	 else System.Console.WriteLine(MSG_ERRO);
	}
   } break;
}

}
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com n�mero do menu.
nmenu - o n�mero do menu
------------------------------------------------------------------------------*/
function usaMenu(num: int): void {
  var opSubMenu: String;
  var bSOp: boolean;
  var opSair: char;

 bSOp = true;
 if (num == 1) { /* Cadastros */
   while(bSOp) {
	 menu(2);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": subMenu(6, ctArqs.opAssunto); break;
	  case "2": subMenu(6, ctArqs.opAutor); break;
	  case "3": subMenu(6, ctArqs.opEditora); break;
	  case "4": subMenu(6, ctArqs.opEndereco); break;
	  case "5": subMenu(6, ctArqs.opIdioma); break;
	  case "6": subMenu(6, ctArqs.opPais); break;
	  case "7": subMenu(6, ctArqs.opProfissao); break;
	  case "8": subMenu(6, ctArqs.opCliente); break;
	  case "9": subMenu(6, ctArqs.opLivro); break;
	  case "10": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
   }
 } else if (num == 2) { /* Pesquisas */
   while(bSOp) {
	 menu(3);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": subMenu(12, ctArqs.opAssunto); break;
	  case "2": subMenu(12, ctArqs.opAutor); break;
	  case "3": subMenu(12, ctArqs.opEditora); break;
	  case "4": subMenu(12, ctArqs.opEndereco); break;
	  case "5": subMenu(12, ctArqs.opIdioma); break;
	  case "6": subMenu(12, ctArqs.opPais); break;
	  case "7": subMenu(12, ctArqs.opProfissao); break;
	  case "8": subMenu(12, ctArqs.opCliente); break;
	  case "9": subMenu(12, ctArqs.opLivro); break;
	  case "10": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
   }
 } else if (num == 3) { /* Vendas */
   while(bSOp) {
	 menu(4);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": subMenu(6, ctArqs.opVenda); break;
	  case "2": subMenu(12, ctArqs.opVenda); break;
	  case "3": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
	 }
   }
 } else if (num == 4) { /* Opcoes */
   while(bSOp) {
	 menu(5);
	 opSubMenu = System.Console.In.ReadLine();
	 switch(opSubMenu) {
	  case "1": frmAlterarSenha(); break;
	  case "2": frmSobre(); break;
	  case "3": {
		   menu(11);
		   opSair = System.Console.In.ReadLine()[0];
		   if ((opSair=='S') || (opSair=='s')) {
			  fechaArqs();
			  System.Environment.Exit(0);
		   }
		 } break;
	  case "4": bSOp = false; break;
	  default: System.Console.WriteLine(MSG_ERRO); break;
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
function mostrarDados(sreg: ctArqs, slinha: String, nOpcao: int): void 
{
if (sreg==ctArqs.opAssunto) {
   switch(nOpcao) {
	case 1: {
		System.Console.WriteLine(rotulo(sreg, 1) + tAssunto.codigo);
		System.Console.Write(rotulo(sreg, 2));
		tAssunto.assunto = System.Console.In.ReadLine();
	   } break;
	case 2: {
		System.Console.WriteLine("C�digo     Assunto");
		System.Console.WriteLine("------     -------");
	   } break;
	case 3: {
		tAssunto.codigo = copy(slinha, 1, 10).Trim();
		tAssunto.assunto = copy(slinha, 11, 30).Trim();
		System.Console.WriteLine(esp(tAssunto.codigo,10) + " " +
						   esp(tAssunto.assunto,30));
	   } break;
   }
} else if (sreg==ctArqs.opAutor) {
   switch(nOpcao) {
	case 1: {
		System.Console.WriteLine(rotulo(sreg, 1) + tAutor.codigo);
		System.Console.Write(rotulo(sreg, 2));
		tAutor.autor = System.Console.In.ReadLine();
	   } break;
	case 2: {
		System.Console.WriteLine("C�digo     Autor");
		System.Console.WriteLine("------     -----");
	   } break;
	case 3: {
		tAutor.codigo = copy(slinha, 1, 10).Trim();
		tAutor.autor = copy(slinha, 11, 30).Trim();
		System.Console.WriteLine(esp(tAutor.codigo,10)+" "+esp(tAutor.autor,30));
	   } break;
   }
} else if (sreg==ctArqs.opEditora) {
   switch(nOpcao) {
	case 1: {
		System.Console.WriteLine(rotulo(sreg, 1) + tEditora.codigo);
		System.Console.Write(rotulo(sreg, 2));
		tEditora.editora = System.Console.In.ReadLine();
	   } break;
	case 2: {
		System.Console.WriteLine("C�digo     Editora");
		System.Console.WriteLine("------     -------");
	   } break;
	case 3: {
		tEditora.codigo = copy(slinha, 1, 10).Trim();
		tEditora.editora = copy(slinha, 11, 50).Trim();
		System.Console.WriteLine(esp(tEditora.codigo,10)+" "+
						   esp(tEditora.editora,50));
       } break;
   }
} else if (sreg==ctArqs.opEndereco) {
   switch(nOpcao) {
	case 1: {
		System.Console.WriteLine(rotulo(sreg, 1) + tEndereco.codigo);
		System.Console.Write(rotulo(sreg, 2));
		tEndereco.logradouro = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 3));
		tEndereco.bairro = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 4));
		tEndereco.cep = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 5));
		tEndereco.cidade = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 6));
		tEndereco.estado = System.Console.In.ReadLine();
	   } break;
	case 3: {
		tEndereco.codigo = copy(slinha, 1, 10).Trim();
		tEndereco.logradouro = copy(slinha, 11, 40).Trim();
		tEndereco.bairro = copy(slinha, 51, 15).Trim();
		tEndereco.cep = copy(slinha, 66, 8).Trim();
		tEndereco.cidade = copy(slinha, 74, 30).Trim();
		tEndereco.estado = copy(slinha, 104, 20).Trim();
		System.Console.WriteLine("--------------------");
		System.Console.WriteLine(rotulo(sreg, 1) + tEndereco.codigo);
		System.Console.WriteLine(rotulo(sreg, 2) + tEndereco.logradouro);
		System.Console.WriteLine(rotulo(sreg, 3) + tEndereco.bairro);
		System.Console.WriteLine(rotulo(sreg, 4) + tEndereco.cep);
		System.Console.WriteLine(rotulo(sreg, 5) + tEndereco.cidade);
		System.Console.WriteLine(rotulo(sreg, 6) + tEndereco.estado);
	   } break;
   }
} else if (sreg==ctArqs.opIdioma) {
   switch(nOpcao) {
	case 1: {
		System.Console.WriteLine(rotulo(sreg, 1) + tIdioma.codigo);
		System.Console.Write(rotulo(sreg, 2));
		tIdioma.idioma = System.Console.In.ReadLine();
	   } break;
	case 2: {
		System.Console.WriteLine("C�digo     Idioma");
		System.Console.WriteLine("------     ------");
	   } break;
	case 3: {
		tIdioma.codigo = copy(slinha, 1, 10).Trim();
		tIdioma.idioma = copy(slinha, 11, 20).Trim();
		System.Console.WriteLine(esp(tIdioma.codigo,10) + " " +
						   esp(tIdioma.idioma,20));
	   } break;
   }
} else if (sreg==ctArqs.opPais) {
   switch(nOpcao) {
	case 1: {
		System.Console.Write(rotulo(sreg, 2));
		tPais.pais = System.Console.In.ReadLine();
	   } break;
	case 2: {
		System.Console.WriteLine("C�digo Pa�s");
		System.Console.WriteLine("------ ----");
	   } break;
	case 3: {
		tPais.codigo = copy(slinha, 1, 3).Trim();
		tPais.pais = copy(slinha, 4, 50).Trim();
		System.Console.WriteLine(esp(tPais.codigo,3)+"    "+esp(tPais.pais,50));
	   } break;
   }
} else if (sreg==ctArqs.opProfissao) {
   switch(nOpcao) {
	case 1: {
		System.Console.WriteLine(rotulo(sreg, 1) + tProfissao.codigo);
		System.Console.WriteLine(rotulo(sreg, 2));
		tProfissao.profissao = System.Console.In.ReadLine();
	   } break;
	case 2: {
		System.Console.WriteLine("C�digo     Profiss�o");
		System.Console.WriteLine("------     ---------");
	   } break;
	case 3: {
		tProfissao.codigo = copy(slinha, 1, 10).Trim();
		tProfissao.profissao = copy(slinha, 11, 50).Trim();
		System.Console.WriteLine(esp(tProfissao.codigo,10)+" "+
				esp(tProfissao.profissao,50));
	   } break;
   }
} else if (sreg==ctArqs.opLivro) {
   switch(nOpcao) {
	case 1: {
		System.Console.Write(rotulo(sreg, 2));
		tLivro.titulo = System.Console.In.ReadLine();
		tLivro.edicao = validaNumero(rotulo(sreg, 3), tLivro.edicao);
		tLivro.anopubli = validaNumero(rotulo(sreg, 4), tLivro.anopubli);
		mostrarSubDados(ctArqs.opLivro, ctArqs.opEditora, false);
		tLivro.volume = validaNumero(rotulo(sreg, 6), tLivro.volume);
		mostrarSubDados(ctArqs.opLivro, ctArqs.opIdioma, false);
		tLivro.npaginas = validaNumero(rotulo(sreg, 8), tLivro.npaginas);
		tLivro.preco = validaNumero(rotulo(sreg, 9), tLivro.preco);
		tLivro.qtdestoque = validaNumero(rotulo(sreg, 10),
		tLivro.qtdestoque);
	   } break;
	case 3: {
		tLivro.isbn = copy(slinha, 1, 13).Trim();
		tLivro.titulo = copy(slinha, 14, 50).Trim();
		tLivro.edicao = copy(slinha, 64, 10).Trim();
		tLivro.anopubli = copy(slinha, 74, 10).Trim();
		tLivro.codeditora = copy(slinha, 84, 10).Trim();
		tLivro.volume = copy(slinha, 94, 10).Trim();
		tLivro.codidioma = copy(slinha, 104, 10).Trim();
		tLivro.npaginas = copy(slinha, 114, 10).Trim();
		tLivro.preco = copy(slinha, 124, 10).Trim();
		tLivro.qtdestoque = copy(slinha, 134, 10).Trim();
		System.Console.WriteLine("--------------------");
		System.Console.WriteLine(rotulo(sreg, 1) + tLivro.isbn);
		System.Console.WriteLine(rotulo(sreg, 2) + tLivro.titulo);
		System.Console.WriteLine(rotulo(sreg, 3) + tLivro.edicao);
		System.Console.WriteLine(rotulo(sreg, 4) + tLivro.anopubli);
		System.Console.WriteLine(rotulo(sreg, 5) + tLivro.codeditora);
		mostrarSubDados(ctArqs.opLivro, ctArqs.opEditora, true);
		System.Console.WriteLine(rotulo(sreg, 6) + tLivro.volume);
		System.Console.WriteLine(rotulo(sreg, 7) + tLivro.codidioma);
		mostrarSubDados(ctArqs.opLivro, ctArqs.opIdioma, true);
		System.Console.WriteLine(rotulo(sreg, 8) + tLivro.npaginas);
		System.Console.WriteLine(rotulo(sreg, 9) + tLivro.preco);
		System.Console.WriteLine(rotulo(sreg, 10) + tLivro.qtdestoque);
		ListarRegLigados(tfLivroAss, ctArqs.opLivroAss, 1, 13, 14, 10, tLivro.isbn,
						 tfAssunto, ctArqs.opAssunto, 1, 4);
		ListarRegLigados(tfLivroAut, ctArqs.opLivroAut, 1, 13, 14, 10, tLivro.isbn,
						 tfAutor, ctArqs.opAutor, 1, 4);
	   } break;
   }
} else if (sreg==ctArqs.opCliente) {
   switch(nOpcao) {
	case 1: {
		System.Console.Write(rotulo(sreg, 2));
		tCliente.nome = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 3));
		tCliente.email = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 4));
		tCliente.identidade = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 5));
		tCliente.sexo = System.Console.In.ReadLine();
		System.Console.Write(rotulo(sreg, 6));
		tCliente.telefone = System.Console.In.ReadLine();
		tCliente.dtnascimento =
				validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true);
		mostrarSubDados(ctArqs.opCliente, ctArqs.opEndereco, false);
		mostrarSubDados(ctArqs.opCliente, ctArqs.opPais, false);
		mostrarSubDados(ctArqs.opCliente, ctArqs.opProfissao, false);
	   } break;
	case 3: {
		tCliente.cpf = copy(slinha, 1, 14).Trim();
		tCliente.nome = copy(slinha, 15, 30).Trim();
		tCliente.email = copy(slinha, 45, 30).Trim();
		tCliente.identidade = copy(slinha, 75, 10).Trim();
		tCliente.sexo = copy(slinha, 85, 1).Trim();
		tCliente.telefone = copy(slinha, 86, 17).Trim();
		tCliente.dtnascimento = copy(slinha, 103, 10).Trim();
		tCliente.codendereco = copy(slinha, 113, 10).Trim();
		tCliente.codpais = copy(slinha, 123, 3).Trim();
		tCliente.codprofissao = copy(slinha, 126, 10).Trim();
		System.Console.WriteLine("--------------------");
		System.Console.WriteLine(rotulo(sreg, 1) + tCliente.cpf);
		System.Console.WriteLine(rotulo(sreg, 2) + tCliente.nome);
		System.Console.WriteLine(rotulo(sreg, 3) + tCliente.email);
		System.Console.WriteLine(rotulo(sreg, 4) + tCliente.identidade);
		System.Console.WriteLine(rotulo(sreg, 5) + tCliente.sexo);
		System.Console.WriteLine(rotulo(sreg, 6) + tCliente.telefone);
		System.Console.WriteLine(rotulo(sreg, 7) + tCliente.dtnascimento);
		System.Console.WriteLine(rotulo(sreg, 8) + tCliente.codendereco);
		mostrarSubDados(ctArqs.opCliente, ctArqs.opEndereco, true);
		System.Console.WriteLine(rotulo(sreg, 9) + tCliente.codpais);
		mostrarSubDados(ctArqs.opCliente, ctArqs.opPais, true);
		System.Console.WriteLine(rotulo(sreg, 10) + tCliente.codprofissao);
		mostrarSubDados(ctArqs.opCliente, ctArqs.opProfissao, true);
	   } break;
   }
} else if (sreg==ctArqs.opVenda) {
   switch(nOpcao) {
    case 1: mostrarSubDados(ctArqs.opVenda,ctArqs.opVenda, false); break;
    case 2: {
		System.Console.WriteLine("DataHoraVenda       CPF            ISBN          " +
		"Pre�oVenda");
		System.Console.WriteLine("-------------       ---            ----          " +
		"----------");
	   } break;
	case 3: {
		tVenda.dthrvenda = copy(slinha, 1, 19).Trim();
		tVenda.cpf = copy(slinha, 20, 14).Trim();
		tVenda.isbn = copy(slinha, 34, 13).Trim();
		tVenda.precovenda = copy(slinha, 47, 10).Trim();
		System.Console.WriteLine(esp(tVenda.dthrvenda,19)+" "+esp(tVenda.cpf,14)+" "+
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
function mostrarSubDados(sreg: ctArqs, ssubreg: ctArqs, 
         bSoMostrar: boolean): void {
var sRegistro, sPreco: String;
var nMaxTentativas: int;

nMaxTentativas = 3;
if (sreg==ctArqs.opLivro) {
  if (ssubreg==ctArqs.opEditora) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(ctArqs.opEditora));
	else
	   sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
				  nMaxTentativas,false,ctTipo.opNumero);
	if (sRegistro.Equals("")==false) {
	  tLivro.codeditora = copy(sRegistro,1,10).Trim();
	  System.Console.Write(" "+rotulo(ctArqs.opEditora, 2));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  } else if (ssubreg==ctArqs.opIdioma) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(ctArqs.opIdioma));
	else
	   sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
				  nMaxTentativas,false,ctTipo.opNumero);
	if (sRegistro.Equals("")==false) {
	  tLivro.codidioma = copy(sRegistro,1,10).Trim();
	  System.Console.Write(" "+rotulo(ctArqs.opIdioma, 2));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  }
} else if (sreg==ctArqs.opCliente) {
  if (ssubreg==ctArqs.opEndereco) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
				  tamReg(ctArqs.opEndereco));
	else
	   sRegistro = validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
				  nMaxTentativas,false,ctTipo.opNumero);
	if (sRegistro.Equals("")==false) {
	  tCliente.codendereco = copy(sRegistro,1,10).Trim();
	  System.Console.Write(" "+rotulo(ctArqs.opEndereco, 2));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System.Console.Write(" "+rotulo(ctArqs.opEndereco, 3));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System.Console.Write(" "+rotulo(ctArqs.opEndereco, 4));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System.Console.Write(" "+rotulo(ctArqs.opEndereco, 5));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System.Console.Write(" "+rotulo(ctArqs.opEndereco, 6));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  } else if (ssubreg==ctArqs.opPais) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(ctArqs.opPais));
	else
	   sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
				  nMaxTentativas,false,ctTipo.opTexto);
	if (sRegistro.Equals("")==false) {
	  tCliente.codpais = copy(sRegistro,1,3).Trim();
	  System.Console.Write(" "+rotulo(ctArqs.opPais, 2));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  } else if (ssubreg==ctArqs.opProfissao) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
				  tamReg(ctArqs.opProfissao));
	else
	   sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
				  nMaxTentativas,false,ctTipo.opNumero);
	if (sRegistro.Equals("")==false) {
	  tCliente.codprofissao = copy(sRegistro,1,10).Trim();
	  System.Console.Write(" "+rotulo(ctArqs.opProfissao, 2));
	  System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  }
} else if (sreg==ctArqs.opVenda) {
  sRegistro = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(ctArqs.opLivro));
  if (sRegistro.Equals("")==false) {
	System.Console.Write(" "+rotulo(ctArqs.opLivro, 2)); /* Titulo */
	System.Console.WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	System.Console.Write(" "+rotulo(ctArqs.opLivro, 9)); /* Preco */
	sPreco = copy(sRegistro, g_nPosChave, g_nTamChave);
	g_nPreco = double.Parse(sPreco);
	System.Console.WriteLine(sPreco);
  }
}
}
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a a��o a ser realizada
sCodigo - um das chaves do arquivo de liga��o
------------------------------------------------------------------------------*/
function frmCadLigados(sreg: ctArqs, sacao: ctAcao, sCodigo: String): void {
  var nQtd, nCont, nQtdEstoque: int;
  var nTotalPreco: double;
  var slinha, sTotalPreco, sPreco: String;
  var sQtd: String = "";

if (sacao==ctAcao.opNovo) {
  nCont = 1;
  if (sreg==ctArqs.opLivroAss) {
	sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",sQtd);
	nQtd = int.Parse(sQtd);
	tfLivroAss.Seek(0, SeekOrigin.Begin);
	while (nCont <= nQtd) {
	  tLivroAss.isbn = sCodigo;
	  System.Console.Write(rotulo(ctArqs.opLivroAss, 2));
	  tLivroAss.codassunto = System.Console.In.ReadLine();
	  slinha = pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(ctArqs.opAssunto));
	  System.Console.Write(" "+rotulo(ctArqs.opAssunto, 2));
	  System.Console.WriteLine(copy(slinha, g_nPosChave, g_nTamChave));
	  pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
	  subMenu(14, sreg);
	  nCont++;
	}
  } else if (sreg==ctArqs.opLivroAut) {
	sQtd = validaNumero("Quantos autores quer cadastrar?: ",sQtd);
	nQtd = int.Parse(sQtd);
	tfLivroAut.Seek(0, SeekOrigin.Begin);
	while (nCont <= nQtd) {
	  tLivroAut.isbn = sCodigo;
	  System.Console.Write(rotulo(ctArqs.opLivroAut, 2));
	  tLivroAut.codautor = System.Console.In.ReadLine();
	  slinha = pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(ctArqs.opAutor));
	  System.Console.Write(" "+rotulo(ctArqs.opAutor, 2));
	  System.Console.WriteLine(copy(slinha, g_nPosChave, g_nTamChave));
	  pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
	  subMenu(14, sreg);
	  nCont++;
	}
  } else if (sreg==ctArqs.opVenda) {
	sPreco = "";
	sTotalPreco = "";
	sQtd = validaNumero("Quantos livros quer vender?: ",sQtd);
	nQtd = int.Parse(sQtd);
	nTotalPreco = 0;
	while (nCont <= nQtd) {
	  slinha = validaEntrada(tfLivro,ctArqs.opLivro,1,tVenda.isbn,3,false,ctTipo.opTexto);
	  if (slinha.Equals("")==false) {
		tVenda.isbn = copy(slinha,1,13).Trim();
		if (ValidaISBN(tVenda.isbn)) {
		  mostrarDados(sreg, "", 1);
		  tLivro.qtdestoque = copy(slinha,134,10).Trim();
		  nQtdEstoque = int.Parse(tLivro.qtdestoque);
		  if (nQtdEstoque > 0) {
			 nTotalPreco = nTotalPreco + g_nPreco;
			 sPreco = g_nPreco.ToString();
			 tVenda.precovenda = sPreco;
			 g_SalvarInclusao = false;
			 subMenu(14, sreg);
			 if (g_SalvarInclusao) {
				slinha = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(ctArqs.opLivro));
				if (slinha.Equals("")==false) {
				   nQtdEstoque = nQtdEstoque-1;
				   tLivro.qtdestoque = nQtdEstoque.ToString();
				   slinha=copy(slinha,1,133) + esp(tLivro.qtdestoque,10);
				   escreveArq(tfLivro, slinha, "", "");
				}
			 }
			 nCont++;
		  } else System.Console.WriteLine(MSG_SEMESTOQUE);
		} else System.Console.WriteLine(MSG_ISBNINV);
	  }
	}
	sTotalPreco = nTotalPreco.ToString();
	System.Console.WriteLine("Total de "+rotulo(sreg,4)+sTotalPreco);
  }
} else if (sacao==ctAcao.opExcluir) {
  if (sreg==ctArqs.opLivroAss) {
	 ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo);
  } else if (sreg==ctArqs.opLivroAut) {
	 ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo);
  }
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
function ExcluirRegLigados(sArq: FileStream, sreg: ctArqs, nPosChave: int,
nTamChave: int, sChave: String): void {
  var slinha: String = "";
  var sCodigo: String;

	sArq.Seek(0, SeekOrigin.Begin);
	while (!fimArq(sArq)) {
	  slinha = lerArq(sArq, tamReg(sreg), TAM_CRLF);
	  if (slinha.Equals("")==false) {
		sCodigo = copy(slinha,nPosChave,nTamChave).Trim();
		if (sCodigo.Equals(sChave))
		   btnAcao(sreg,ctAcao.opConfirmaExclusao);
	  }
	}

}

}
};

/*------------------------------------------------------------------------------
Parte inicial do c�digo
------------------------------------------------------------------------------*/
function main(args: String[]): void {
  var cl: Livrus.Livrus;
  cl = new Livrus.Livrus();

    if ((args.Length > 0) && (args[0].Equals("-cria")))
      cl.abrecriaArqs(false);
    else {
      cl.frmSplash();
      cl.abrecriaArqs(true);
      if (cl.frmLogin()) {
    	cl.bopcao = true;
    	while(cl.bopcao) {
    	  cl.menu(1);
    	  cl.opmenu = System.Console.In.ReadLine()[0];
    	  if ((cl.opmenu=='C') || (cl.opmenu=='c')) cl.usaMenu(1);
    	  else if ((cl.opmenu=='P') || (cl.opmenu=='p')) cl.usaMenu(2);
    	  else if ((cl.opmenu=='V') || (cl.opmenu=='v')) cl.usaMenu(3);
    	  else if ((cl.opmenu=='O') || (cl.opmenu=='o')) cl.usaMenu(4);
    	  else System.Console.WriteLine(Livrus.Livrus.MSG_ERRO);
    	}
      } else {
    	cl.fechaArqs();
    	System.Environment.Exit(0);
      }
    }
    System.Environment.Exit(0);
}

main(System.Environment.GetCommandLineArgs());
