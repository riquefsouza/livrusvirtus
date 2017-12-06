/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem Visual C++ .NET.
------------------------------------------------------------------------------*/
/* programa Livrus */

#using <mscorlib.dll>
#using <System.dll>
using namespace System;
using namespace System::IO;
using namespace System::Text;

#include "Livrus.h"

//namespace Livrus 
//{

/*--- Rotinas básicas --------------------------------------------------------*/

/*------------------------------------------------------------------------------
Função que retorna um pedaço de uma string.
str - indica a string
nini - indica a posicao inicial do pedaco
ntam - indica o tamanho do pedaco
retorna - o pedaço da string
------------------------------------------------------------------------------*/
  String* Livrus::copy(String* str,int nini,int ntam) {
	return str->Substring(nini-1,ntam);
  }

/*------------------------------------------------------------------------------
Repete um texto um número determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*/
  String* Livrus::repete(String* sTexto, int nQtd)
  { int ncont;
	String* sret = S"";

    for(ncont = 1; ncont <= nQtd; ncont++) {
		sret = String::Concat(sret, sTexto);
    }
    return sret;
  }
/*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*/
  String* Livrus::esp(String* sTexto, int nTam) {
   String* sret;

	sret = String::Concat(sTexto, repete(S" ",nTam-sTexto->Length));
	return sret;
  }
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*/
  Boolean Livrus::strRelativa(String* sTexto, String* sChave) {
	int nCont, nTamChave, nTamTexto;
	Boolean bret;
	String* sPedaco;

	bret = false;
	nCont = 1;
	nTamChave = sChave->Length;
    nTamTexto = sTexto->Length;
    if (nTamChave <= nTamTexto) {
      while (nCont <= (nTamTexto-nTamChave+1)) {
         sPedaco = copy(sTexto,nCont,nTamChave);
         if (sPedaco->Equals(sChave))
            bret = true;
         nCont++;
      }
    }
    return  bret;
  }
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a string com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*/
  int Livrus::modulo11(String* svalor, int ndig)
  {
  int ncont, nsoma, nvalor, npos;
  String *slocal, *sres;
  
   ncont=0;
   slocal="";
   while (ncont < 11) {
     slocal=String::Concat(svalor->Substring(ncont,1), slocal);
     ncont++;
   }
   nsoma=0;
   if (ndig == 1)
     ncont=2;
   else
     ncont=1;
   npos=2;
   while (ncont < 11) {
     sres = slocal->Substring(ncont,1);
     nvalor = Int32::Parse(sres);
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
  Boolean Livrus::ValidaCPF(String* cpf)
  {
  String* scpf;
  
  if (cpf->Length==14) {
    scpf=String::Concat(cpf->Substring(0,3),cpf->Substring(4,3),
	 cpf->Substring(8,3),cpf->Substring(12,2));
    if ( (modulo11(scpf,1)==Int32::Parse(cpf->Substring(12,1))) &&
    (modulo11(scpf,2)==Int32::Parse(cpf->Substring(13,1))) )
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
  Boolean Livrus::ValidaISBN(String* isbn)
  {
   String *sisbn, *sdigito, *snum;
   int nvalor, nsoma, ncont;
  
  if (isbn->Length==13) {
    sdigito = isbn->Substring(isbn->Length-1, 1);
    sisbn="";
    for(ncont = 0; ncont < isbn->Length-1; ncont++)  {
      if (isbn->Substring(ncont,1)->Equals(S"-")==false)
        sisbn = String::Concat(sisbn, isbn->Substring(ncont,1));
    }
    if (sdigito->Equals(S"X"))
      nsoma = 10;
    else {
      nvalor = Int32::Parse(sdigito);
      nsoma = nvalor;
    }
    for(ncont = 1; ncont <= 9; ncont++)  {
      snum = sisbn->Substring(ncont-1, 1);
      nvalor = Int32::Parse(snum);
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
String* Livrus::digitaSenha(String* sRotulo,int nTamSenha) {
 String* sSenha = "";
// char sLetra;
// int ncont;

  System::Console::Write(sRotulo);
  sSenha = System::Console::In->ReadLine();
/*
  ncont  = 0;
  sLetra = '\0';
  while((sLetra!='\r') && (ncont < nTamSenha)) {
	sLetra = (char) System::Console::Read();
	if (sLetra!='\r') {
	   sSenha = sSenha + sLetra;
	}
	ncont++;
  }
System::Console::WriteLine();
*/
return sSenha;
}
/*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a String com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*/
String* Livrus::validaNumero(String* sRotulo, String* sNumero) {
  double nnum;
  int nStatus;

nStatus = -1;
 while (nStatus!=0) {
  System::Console::Write(sRotulo);
  sNumero = System::Console::In->ReadLine();
  try {
	  nnum = Single::Parse(sNumero);
	  if (nnum < 1)
		 System::Console::WriteLine(MSG_NUMINV);
	  else
		 nStatus=0;
  } catch(System::Exception* e) {
	System::Console::WriteLine(MSG_NUMINV);
  }
}
return sNumero;
}
/*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a String com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
String* Livrus::validaDataHora(String* sRotulo, String* sDataHora, Boolean bSoData) {
  Boolean bvalida, bdatavalida, bhoravalida;
  String *sdia, *smes, *sano, *shora, *smin, *sseg;
  int ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam;

bvalida = false;
bdatavalida = false;
bhoravalida = false;
nudiames = 0;
if (bSoData==true) ntam=10;
else ntam=19;
while (bvalida==false) {
  System::Console::Write(sRotulo);
  sDataHora = System::Console::In->ReadLine();
  if (sDataHora->Length==ntam) {
	sdia = copy(sDataHora,1,2);
	ndia = Int32::Parse(sdia);
	smes = copy(sDataHora,4,2);
	nmes = Int32::Parse(smes);
	sano = copy(sDataHora,7,4);
	nano = Int32::Parse(sano);

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
	   System::Console::WriteLine(MSG_DATAINV);
	} else {
	  if (bdatavalida) {
		  shora = copy(sDataHora,12,2);
		  nhora = Int32::Parse(shora);
		  smin = copy(sDataHora,15,2);
		  nmin = Int32::Parse(smin);
		  sseg = copy(sDataHora,18,2);
		  nseg = Int32::Parse(sseg);

		  if ((nhora >= 0) && (nhora <= 23)) {
			if ((nmin >= 0) && (nmin <= 59)) {
			  if ((nseg >= 0) && (nseg <= 59))
				 bhoravalida = true;
			}
		  }

		  if (bhoravalida)
		   bvalida = true;
		  else
		   System::Console::WriteLine(MSG_DTHRINV);
	  } else
        System::Console::WriteLine(MSG_DTHRINV);
    }
  } else {
	if (bSoData==true) System::Console::WriteLine(MSG_DATAINV);
	else System::Console::WriteLine(MSG_DTHRINV);
  }
}
return sDataHora;
}
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
String* Livrus::retDataHora() {
  return DateTime::Now.ToString(S"dd/MM/yyyy hh:mm:ss");
}
/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
long Livrus::tamArq(FileStream* sArq){
  return sArq->Length;
}
/*------------------------------------------------------------------------------
Verifica se chegou ao fim do arquivo.
sArq - o arquivo
ntam - o tamanho do arquivo
retorna - se chegou ao fim do arquivo
------------------------------------------------------------------------------*/
Boolean Livrus::fimArq(FileStream* sArq) {
 if (sArq->Position == sArq->Length)
	return true;
 else
	return false;
}
/*------------------------------------------------------------------------------
Lê uma linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho da linha
nTamCRLF - o tamanho do retorno da linha
npos - posicao dentro do arquivo
retorna - o texto lido
------------------------------------------------------------------------------*/
String* Livrus::lerArq(FileStream* sArq, int nTamLinha, int nTamCRLF) {
int nLidos, ncont;
Byte slinha[] = new Byte[TAM_MAX_REG];
Char slinha2[] = new Char[TAM_MAX_REG];
String* sret = S"";

//StreamReader sLer = new StreamReader(sArq);
//sret = sLer->ReadLine();

nLidos = sArq->Read(slinha, 0,(nTamLinha + nTamCRLF));

if (nLidos != (nTamLinha + nTamCRLF))
  sret = S"";
else {
  for(ncont=0; ncont < (nLidos - nTamCRLF); ncont++)
	slinha2[ncont]=(Char)slinha[ncont];
  sret = new String(slinha2,0,(nLidos - nTamCRLF));
}

return sret;
}
/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
Void Livrus::abrecriaArqs(Boolean bAbre)
{
if (bAbre) {
  if (File::Exists(ARQ_ASSUNTO))
	tfAssunto = new FileStream(ARQ_ASSUNTO,FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_ASSUNTO));
  if (File::Exists(ARQ_AUTOR))
	tfAutor = new FileStream(ARQ_AUTOR, FileMode::Open, FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_AUTOR));
  if (File::Exists(ARQ_EDITORA))
	tfEditora = new FileStream(ARQ_EDITORA,FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_EDITORA));
  if (File::Exists(ARQ_IDIOMA))
	tfIdioma = new FileStream(ARQ_IDIOMA, FileMode::Open, FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_IDIOMA));
  if (File::Exists(ARQ_ENDERECO))
	tfEndereco= new FileStream(ARQ_ENDERECO,FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_ENDERECO));
  if (File::Exists(ARQ_PAIS))
	tfPais = new FileStream(ARQ_PAIS, FileMode::Open, FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_PAIS));
  if (File::Exists(ARQ_PROFISSAO))
   tfProfissao=new FileStream(ARQ_PROFISSAO,FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_PROFISSAO));
  if (File::Exists(ARQ_LIVRO))
	tfLivro = new FileStream(ARQ_LIVRO, FileMode::Open, FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_LIVRO));
  if (File::Exists(ARQ_LIVASS))
	tfLivroAss = new FileStream(ARQ_LIVASS, FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_LIVASS));
  if (File::Exists(ARQ_LIVAUT))
	tfLivroAut = new FileStream(ARQ_LIVAUT, FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_LIVAUT));
  if (File::Exists(ARQ_CLIENTE))
	tfCliente = new FileStream(ARQ_CLIENTE, FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_CLIENTE));
  if (File::Exists(ARQ_USUARIO))
	tfUsuario = new FileStream(ARQ_USUARIO, FileMode::Open,FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_USUARIO));
  if (File::Exists(ARQ_VENDA))
	tfVenda = new FileStream(ARQ_VENDA, FileMode::Open, FileAccess::ReadWrite);
  else
	System::Console::WriteLine(String::Concat(MSG_ARQERRO," --> ",ARQ_VENDA));
} else {
  tfAssunto = new FileStream(ARQ_ASSUNTO,FileMode::Create,FileAccess::ReadWrite);
  tfAutor = new FileStream(ARQ_AUTOR,FileMode::Create,FileAccess::ReadWrite);
  tfEditora = new FileStream(ARQ_EDITORA,FileMode::Create,FileAccess::ReadWrite);
  tfIdioma = new FileStream(ARQ_IDIOMA,FileMode::Create,FileAccess::ReadWrite);
  tfEndereco= new FileStream(ARQ_ENDERECO,FileMode::Create,FileAccess::ReadWrite);
  tfPais = new FileStream(ARQ_PAIS,FileMode::Create,FileAccess::ReadWrite);
  tfProfissao=new FileStream(ARQ_PROFISSAO,FileMode::Create,FileAccess::ReadWrite);
  tfLivro = new FileStream(ARQ_LIVRO,FileMode::Create,FileAccess::ReadWrite);
  tfLivroAss = new FileStream(ARQ_LIVASS,FileMode::Create,FileAccess::ReadWrite);
  tfLivroAut = new FileStream(ARQ_LIVAUT,FileMode::Create,FileAccess::ReadWrite);
  tfCliente = new FileStream(ARQ_CLIENTE,FileMode::Create,FileAccess::ReadWrite);
  tfUsuario = new FileStream(ARQ_USUARIO,FileMode::Create,FileAccess::ReadWrite);
  tfVenda = new FileStream(ARQ_VENDA,FileMode::Create,FileAccess::ReadWrite);
}

}
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
Void Livrus::fechaArqs()
{
   tfAssunto->Close();
   tfAutor->Close();
   tfEditora->Close();
   tfIdioma->Close();
   tfEndereco->Close();
   tfPais->Close();
   tfProfissao->Close();
   tfLivro->Close();
   tfLivroAss->Close();
   tfLivroAut->Close();
   tfCliente->Close();
   tfUsuario->Close();
   tfVenda->Close();
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
String* Livrus::pesqArq(FileStream* sArq, String* sChave, int nPosChave,
		int nTamChave, int nTamLinha){
  String *sres = S"", *slinha = S"";
  Boolean bQuebra;
  long nPosicao;

	bQuebra = false;
	sArq->Seek(0,SeekOrigin::Begin);
	while (!fimArq(sArq) && bQuebra == false) {
	  slinha = lerArq(sArq, nTamLinha, TAM_CRLF);
	  if (slinha->Equals(S"")==false)
		sres = copy(slinha, nPosChave, nTamChave)->Trim();
	  if (sres->Equals(sChave))
		bQuebra = true;
	}
	nPosicao = sArq->Position - (nTamLinha + TAM_CRLF);
	if (nPosicao > 0)
	  sArq->Seek(nPosicao, SeekOrigin::Current);
	else
	  sArq->Seek(0, SeekOrigin::Begin);
	if (sres->Equals(sChave) == false)
	  return (S"");
	else
	  return (copy(slinha, 1, nTamLinha));

}
/*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
Void Livrus::pesqLinhaExcluida(FileStream* sArq, int nTamLinha){
String* sExcluido;

  sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha);
  if (sExcluido->Equals(""))
	 sArq->Seek(tamArq(sArq),SeekOrigin::Begin);
}
/*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*/
String* Livrus::pesqMaxCod(FileStream* sArq, int nPosChave,
		int nTamChave, int nTamLinha) {
  String *sres = "", *slinha = "";
  Boolean bQuebra;
  int nMaior, nCod;

	bQuebra = false;
	nMaior = 0;
	sArq->Seek(0,SeekOrigin::Begin);
	while (!fimArq(sArq) && bQuebra == false) {
	  slinha = lerArq(sArq, nTamLinha, TAM_CRLF);
	  if (slinha->Equals("")==false) {
		sres = copy(slinha,nPosChave,nTamChave)->Trim();
		nCod = Int32::Parse(sres);
		if (nCod > nMaior)
		   nMaior = nCod;
	  }
	}
	pesqLinhaExcluida(sArq, nTamLinha);
	nCod = (nMaior+1);
	sres = Convert::ToString(nCod);

return(sres);
}
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*/
Void Livrus::escreveArq(FileStream* sArq, String* sTexto, String* sMsgAcerto,
	String* sMsgErro){
  Byte slinha[] = new Byte[TAM_MAX_REG];
  int ntam, ncont;
  try {
//	StreamWriter* sGravar = new StreamWriter(sArq);
	sTexto = String::Concat(sTexto, CRLF);
	ntam = sTexto->Length;
	for (ncont=0; ncont < ntam; ncont++)
		slinha[ncont] = Convert::ToByte(sTexto->get_Chars(ncont));
	sArq->Write(slinha, 0, ntam);
//	sGravar->WriteLine(sTexto);
	System::Console::WriteLine(sMsgAcerto);
  } catch(System::Exception* e) {
	System::Console::WriteLine(sMsgErro);
  }
}
/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
String* Livrus::LinhaReg(ctArqs sreg) {
String* slinha = "";

if (sreg==ctArqs::opAssunto) {
   slinha = String::Concat(esp(tAssunto->codigo,10),esp(tAssunto->assunto,30));
} else if (sreg==ctArqs::opAutor)
   slinha = String::Concat(esp(tAutor->codigo,10),esp(tAutor->autor,30));
else if (sreg==ctArqs::opEditora)
   slinha = String::Concat(esp(tEditora->codigo,10),esp(tEditora->editora,50));
else if (sreg==ctArqs::opEndereco)
   slinha = String::Concat(esp(tEndereco->codigo,10),
   esp(tEndereco->logradouro,40),esp(tEndereco->bairro,15),esp(tEndereco->cep,8),
   esp(tEndereco->cidade,30), esp(tEndereco->estado,20));
else if (sreg==ctArqs::opIdioma)
   slinha = String::Concat(esp(tIdioma->codigo,10),esp(tIdioma->idioma,20));
else if (sreg==ctArqs::opPais)
   slinha = String::Concat(esp(tPais->codigo,3),esp(tPais->pais,50));
else if (sreg==ctArqs::opProfissao)
   slinha = String::Concat(esp(tProfissao->codigo,10),esp(tProfissao->profissao,50));
else if (sreg==ctArqs::opUsuario)
   slinha = String::Concat(esp(tUsuario->login,10),esp(tUsuario->senha,10));
else if (sreg==ctArqs::opLivro)
   slinha = String::Concat(esp(tLivro->isbn,13),esp(tLivro->titulo,50),
   esp(tLivro->edicao,10),esp(tLivro->anopubli,10),esp(tLivro->codeditora,10),
   esp(tLivro->volume,10),esp(tLivro->codidioma,10),esp(tLivro->npaginas,10),
   esp(tLivro->preco,10),esp(tLivro->qtdestoque,10));
else if (sreg==ctArqs::opLivroAss)
   slinha = String::Concat(esp(tLivroAss->isbn,13),esp(tLivroAss->codassunto,10));
else if (sreg==ctArqs::opLivroAut)
   slinha = String::Concat(esp(tLivroAut->isbn,13),esp(tLivroAut->codautor,10));
else if (sreg==ctArqs::opCliente)
   slinha = String::Concat(esp(tCliente->cpf,14),esp(tCliente->nome,30),
   esp(tCliente->email,30),esp(tCliente->identidade,10),esp(tCliente->sexo,1),
   esp(tCliente->telefone,17),esp(tCliente->dtnascimento,10),
   esp(tCliente->codendereco,10),esp(tCliente->codpais,3),
   esp(tCliente->codprofissao,10));
else if (sreg==ctArqs::opVenda)
   slinha = String::Concat(esp(tVenda->dthrvenda,19),esp(tVenda->cpf,14),
   esp(tVenda->isbn,13),esp(tVenda->precovenda,10));

return(slinha);
}
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
int Livrus::tamReg(ctArqs sreg)
{ int nret = 0;

if (sreg==ctArqs::opAssunto) nret = TAM_ASSUNTO;
else if (sreg==ctArqs::opAutor) nret = TAM_AUTOR;
else if (sreg==ctArqs::opEditora) nret = TAM_EDITORA;
else if (sreg==ctArqs::opEndereco) nret = TAM_ENDERECO;
else if (sreg==ctArqs::opIdioma) nret = TAM_IDIOMA;
else if (sreg==ctArqs::opPais) nret = TAM_PAIS;
else if (sreg==ctArqs::opProfissao) nret = TAM_PROFISSAO;
else if (sreg==ctArqs::opUsuario) nret = TAM_USUARIO;
else if (sreg==ctArqs::opLivro) nret = TAM_LIVRO;
else if (sreg==ctArqs::opLivroAss) nret = TAM_LIVASS;
else if (sreg==ctArqs::opLivroAut) nret = TAM_LIVAUT;
else if (sreg==ctArqs::opCliente) nret = TAM_CLIENTE;
else if (sreg==ctArqs::opVenda) nret = TAM_VENDA;

return(nret);
}
/*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
String* Livrus::rotulo(ctArqs sreg, int nNum)
{  String* sret = "";

if (sreg==ctArqs::opAssunto) {
   switch(nNum) {
     case 0: sret = S"Assunto(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"Código do assunto: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = S"Assunto: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 30;
    	} break;
   }
} else if (sreg==ctArqs::opAutor) {
   switch(nNum) {
     case 0: sret = S"Autor(es) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"Código do autor: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = S"Autor: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 30;
    	} break;
   }
} else if (sreg==ctArqs::opEditora) {
   switch(nNum) {
     case 0: sret = S"Editora(s) não encontrada(s)!"; break;
     case 1: {
    	 sret = S"Código da editora: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = S"Editora: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 50;
    	} break;
   }
} else if (sreg==ctArqs::opEndereco) {
   switch(nNum) {
     case 0: sret = S"Endereço(s) não encontrado(s)!"; break;
     case 1: {
         sret = S"Código do endereço: ";
         g_nPosChave = 1;
		 g_nTamChave = 10;
        } break;
     case 2: {
         sret = S"Logradouro: ";
         g_nPosChave = 11;
		 g_nTamChave = 40;
        } break;
     case 3: {
         sret = S"Bairro: ";
         g_nPosChave = 51;
		 g_nTamChave = 15;
		} break;
     case 4: {
         sret = S"CEP: ";
         g_nPosChave = 66;
         g_nTamChave = 8;
        } break;
     case 5: {
         sret = S"Cidade: ";
         g_nPosChave = 74;
         g_nTamChave = 30;
		} break;
	 case 6: {
         sret = S"Estado: ";
         g_nPosChave = 104;
         g_nTamChave = 20;
        } break;
   }
} else if (sreg==ctArqs::opIdioma) {
   switch(nNum) {
     case 0: sret = S"Idioma(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"Código do idioma: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = S"Idioma: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 20;
    	} break;
   }
} else if (sreg==ctArqs::opPais) {
   switch(nNum) {
     case 0: sret = S"País(es) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"Código do país: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 3;
    	} break;
     case 2: {
    	 sret = S"País: ";
    	 g_nPosChave = 4;
    	 g_nTamChave = 50;
    	} break;
   }
} else if (sreg==ctArqs::opProfissao) {
   switch(nNum) {
     case 0: sret = S"Profissão(es) não encontrada(s)!"; break;
     case 1: {
    	 sret = S"Código da profissão: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = S"Profissão: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 50;
    	} break;
   }
} else if (sreg==ctArqs::opUsuario) {
   switch(nNum) {
     case 0: sret = S"login ou senha incorreta, tente de novo!"; break;
     case 1: {
    	 sret = S"Login: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 10;
    	} break;
     case 2: {
    	 sret = S"Senha: ";
    	 g_nPosChave = 11;
    	 g_nTamChave = 10;
    	} break;
   }
} else if (sreg==ctArqs::opLivro) {
   switch(nNum) {
     case 0: sret = S"Livro(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"ISBN: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 13;
    	} break;
     case 2: {
    	 sret = S"Título: ";
    	 g_nPosChave = 14;
    	 g_nTamChave = 50;
    	} break;
     case 3: {
    	 sret = S"Edição: ";
    	 g_nPosChave = 64;
    	 g_nTamChave = 10;
    	} break;
     case 4: {
    	 sret = S"Ano de Publicação: ";
    	 g_nPosChave = 74;
    	 g_nTamChave = 10;
    	} break;
     case 5: {
         sret = S"Código da editora: ";
         g_nPosChave = 84;
         g_nTamChave = 10;
        } break;
	 case 6: {
         sret = S"Volume: ";
         g_nPosChave = 94;
         g_nTamChave = 10;
        } break;
	 case 7: {
         sret = S"Código do idioma: ";
         g_nPosChave = 104;
         g_nTamChave = 10;
        } break;
	 case 8: {
	 sret = S"Número de páginas: ";
         g_nPosChave = 114;
         g_nTamChave = 10;
        } break;
     case 9: {
         sret = S"Preço: ";
         g_nPosChave = 124;
         g_nTamChave = 10;
        } break;
     case 10: {
          sret = S"Qtd. Estoque: ";
          g_nPosChave = 134;
          g_nTamChave = 10;
         } break;
   }
} else if (sreg==ctArqs::opLivroAss) {
   switch(nNum) {
     case 0: sret = S"Assunto(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"ISBN: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 13;
    	} break;
     case 2: {
    	 sret = S"Código do assunto: ";
    	 g_nPosChave = 14;
    	 g_nTamChave = 10;
    	} break;
   }
} else if (sreg==ctArqs::opLivroAut) {
   switch(nNum) {
     case 0: sret = S"Autor(s) não encontrado(s)!"; break;
     case 1: {
         sret = S"ISBN: ";
         g_nPosChave = 1;
         g_nTamChave = 13;
        } break;
     case 2: {
         sret = S"Código do autor: ";
         g_nPosChave = 14;
         g_nTamChave = 10;
        } break;
   }
} else if (sreg==ctArqs::opCliente) {
   switch(nNum) {
     case 0: sret = S"Cliente(s) não encontrado(s)!"; break;
     case 1: {
    	 sret = S"CPF: ";
    	 g_nPosChave = 1;
    	 g_nTamChave = 14;
    	} break;
     case 2: {
    	 sret = S"Nome: ";
    	 g_nPosChave = 15;
    	 g_nTamChave = 30;
    	} break;
     case 3: {
    	 sret = S"E-mail: ";
    	 g_nPosChave = 45;
           g_nTamChave = 30;
        } break;
     case 4: {
         sret = S"Identidade: ";
         g_nPosChave = 75;
         g_nTamChave = 10;
        } break;
     case 5: {
         sret = S"Sexo: ";
         g_nPosChave = 85;
         g_nTamChave = 1;
        } break;
	 case 6: {
         sret = S"Telefone: ";
	 g_nPosChave = 86;
         g_nTamChave = 17;
        } break;
     case 7: {
         sret = S"Dt. Nascimento: ";
	 g_nPosChave = 103;
         g_nTamChave = 10;
        } break;
     case 8: {
         sret = S"Código do endereço: ";
	 g_nPosChave = 113;
	 g_nTamChave = 10;
        } break;
     case 9: {
         sret = S"Código do país: ";
         g_nPosChave = 123;
         g_nTamChave = 3;
        } break;
     case 10: {
          sret = S"Código da Profissão: ";
          g_nPosChave = 126;
          g_nTamChave = 10;
        } break;
   }
} else if (sreg==ctArqs::opVenda) {
   switch(nNum) {
	 case 0: sret = S"Venda(s) não encontrada(s)!"; break;
     case 1: {
	 sret = S"Data/Hora venda: ";
         g_nPosChave = 1;
         g_nTamChave = 19;
        } break;
     case 2: {
	 sret = S"CPF: ";
         g_nPosChave = 20;
         g_nTamChave = 14;
        } break;
     case 3: {
	 sret = S"ISBN: ";
	 g_nPosChave = 34;
         g_nTamChave = 13;
        } break;
     case 4: {
         sret = S"Preço de venda: ";
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
Boolean Livrus::ContinuaSN(int nlinha, int nQtdLinha) {
  Boolean bSOp, bret;
  char opCSubMenu;

bret = false;
if (nlinha > 0) {
  if ((nlinha % nQtdLinha) == 0) {
	  bSOp = true;
	  while(bSOp) {
	   menu(13);
	   opCSubMenu = System::Console::In->ReadLine()->get_Chars(0);
	   if ((opCSubMenu=='S') || (opCSubMenu=='s')) bSOp = false;
	   else if ((opCSubMenu=='N') || (opCSubMenu=='n')) {
		  bret = true;
		  bSOp = false;
	   } else System::Console::WriteLine(MSG_ERRO);
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
Boolean Livrus::ListarTodos(FileStream* sArq, ctArqs sreg, String* sChave,
   int nPosChave, int nTamChave, int nTamLinha, int nQtdLinha,
   Boolean bPesqRelativa) {
  Boolean bQuebra, bAchou, bRet;
  int nCont;
  String *sres = "", *slinha = "";

  bRet = false;

	bQuebra = false;
	nCont = 0;
	mostrarDados(sreg, "", 2);
	sArq->Seek(0,SeekOrigin::Begin);
	while (!fimArq(sArq) && bQuebra == false) {
	  slinha = lerArq(sArq, nTamLinha, TAM_CRLF);
	  if (slinha->Equals("")==false) {
		if (bPesqRelativa) {
		  sres = copy(slinha,nPosChave,nTamChave)->Trim();
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
Void Livrus::ListarRegLigados(FileStream* sArq1, ctArqs sreg1, int nPosChave1,
int nTamChave1, int nPosChave2, int nTamChave2, String* sChave,
FileStream* sArq2, ctArqs sreg2, int nPosChave3, int nQtdLinha) {
  String* slinha1 = "";
  Boolean bQuebra, bRet;
  int nCont;
  String *sCodigo1, *sCodigo2, *slinha2;

  bRet = false;
  nCont = 0;
  bQuebra = false;
  mostrarDados(sreg2, "", 2);
  sArq1->Seek(0,SeekOrigin::Begin);
  while (!fimArq(sArq1) && bQuebra == false) {
    slinha1 = lerArq(sArq1, tamReg(sreg1), TAM_CRLF);
    if (slinha1->Equals("")==false) {
  	sCodigo1 = copy(slinha1,nPosChave1,nTamChave1)->Trim();
  	if (sCodigo1->Equals(sChave)) {
  	  sCodigo2 = copy(slinha1,nPosChave2,nTamChave2)->Trim();
  	  slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
  	  mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
  	  bRet = true;
  	  nCont++;
  	}
    }
    bQuebra = ContinuaSN(nCont, nQtdLinha);
  }
  if (bRet==false)
     System::Console::WriteLine(rotulo(sreg2,0));
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
String* Livrus::validaEntrada(FileStream* sArq, ctArqs sreg, int nTexto,
		String* sEntrada, int nTentativas,
		Boolean bPesqRelativa, ctTipo bTipoEntrada) {
  Boolean bQuebra;
  String *sres, *sTexto, *sMsgErro, *sLocal;
  int ncont, nPosChave, nTamChave, nTamLinha;

sres = S"";
//sLocal = sEntrada;
sLocal = S"";

nTamLinha = tamReg(sreg);
sMsgErro = rotulo(sreg,0);
sTexto = rotulo(sreg,nTexto);
nPosChave = g_nPosChave;
nTamChave = g_nTamChave;

ncont = 1;
bQuebra = false;
  while ((bQuebra==false) && (ncont <= nTentativas )) {
      if (bTipoEntrada==ctTipo::opTexto) {
        System::Console::Write(sTexto);
        sLocal = System::Console::In->ReadLine();
      } else if (bTipoEntrada==ctTipo::opNumero)
         sLocal = validaNumero(sTexto,sLocal);
      else if (bTipoEntrada==ctTipo::opData)
         sLocal = validaDataHora(sTexto,sLocal,true);
      else if (bTipoEntrada==ctTipo::opDataHora)
         sLocal = validaDataHora(sTexto,sLocal,false);
      else if (bTipoEntrada==ctTipo::opSenha) {
         sLocal = digitaSenha(sTexto, 10);
      }

    if (bPesqRelativa) {
       if (ListarTodos(sArq, sreg, sLocal, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, true))
        sres = " ";
    } else
       sres = pesqArq(sArq, sLocal, nPosChave, nTamChave, nTamLinha);

	if (sres->Equals(""))
	   System::Console::WriteLine(sMsgErro);
	else
	   bQuebra = true;

    ncont++;
  }
return(sres);
}
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
Void Livrus::frmSplash()
{ int cont;

 System::Console::WriteLine("*---------------------------------------" \
 "-------------------------------------*");
 System::Console::WriteLine("| LL    II VV   VV RRRRR  UU  UU   SSSS " \
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |");
 System::Console::WriteLine("| LL    II  VV VV  RR   R UU  UU  SS    " \
 " VV VV  II RR   R  TT  UU  UU  SS    |");
 System::Console::WriteLine("| LL    II   VVV   RRRRR  UU  UU    SS  " \
 "  VVV   II RRRRR   TT  UU  UU    SS  |");
 System::Console::WriteLine("| LLLLL II    V    RR   R  UUUU  SSSS   " \
 "   V    II RR   R  TT   UUUU  SSSS   |");
 System::Console::WriteLine("*---------------------------------------" \
 "-------------------------------------*");
 for(cont = 1; cont <= 18; cont++) System::Console::WriteLine();
 System::Console::Write(MSG_PRESS);
 System::Console::In->ReadLine();
}
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
Void Livrus::frmSobre()
{ int cont;

 System::Console::WriteLine("*------------------------------------------------------------*");
 System::Console::WriteLine("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |");
 System::Console::WriteLine("|  LL        II   VV     VV   RR     R  UU    UU  SS         |");
 System::Console::WriteLine("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |");
 System::Console::WriteLine("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |");
 System::Console::WriteLine("|  LLLL      II      VVV      RR RR     UU    UU        SS   |");
 System::Console::WriteLine("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |");
 System::Console::WriteLine("|                                                            |");
 System::Console::WriteLine("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |");
 System::Console::WriteLine("|   VV     VV   II  RR     R     TT     UU    UU  SS         |");
 System::Console::WriteLine("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |");
 System::Console::WriteLine("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |");
 System::Console::WriteLine("|      VVV      II  RR RR        TT     UU    UU        SS   |");
 System::Console::WriteLine("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |");
 System::Console::WriteLine("|                                                            |");
 System::Console::WriteLine("|                                               Versao 1.0.0 |");
 System::Console::WriteLine("| Sistema integrante do projeto Livrus Virtus.               |");
 System::Console::WriteLine("| Todos os direitos reservados para Henrique F. de Souza.    |");
 System::Console::WriteLine("| Versao programada na linguagem Visual C++ .NET.            |");
 System::Console::WriteLine("*------------------------------------------------------------*");
 for(cont = 1; cont <= 4; cont++) System::Console::WriteLine();
 System::Console::Write(MSG_PRESS);
 System::Console::In->ReadLine();
}
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
Boolean Livrus::frmLogin()
{ Boolean bret;
  String* slinha = S"";

  bret = false;
  System::Console::WriteLine("*--------------------------------------------------------------*");
  System::Console::WriteLine("| Login do sistema                                             |");
  System::Console::WriteLine("*--------------------------------------------------------------*");
//  tUsuario->login = String::Empty;
  slinha = validaEntrada(tfUsuario, ctArqs::opUsuario, 1, tUsuario->login, 3,
		false, ctTipo::opTexto);
  if (slinha->Equals(S"")==false) {
//         tUsuario->senha = S"";
	 slinha = validaEntrada(tfUsuario, ctArqs::opUsuario, 2, tUsuario->senha, 3,
		false, ctTipo::opSenha);
	 if (slinha->Equals(S"")==false) {
		tUsuario->login = copy(slinha, 1, 10)->Trim();
		tUsuario->senha = copy(slinha, 11, 10)->Trim();
        bret = true;
     }
  }
  System::Console::WriteLine();
  return(bret);
}
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*/
Void Livrus::menu(int num)
{
 if (num==1) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==2) {
   System::Console::WriteLine("*---------------------------------*");
   System::Console::WriteLine("| 01. Cadastro de Assuntos        |");
   System::Console::WriteLine("| 02. Cadastro de Autores         |");
   System::Console::WriteLine("| 03. Cadastro de Editoras        |");
   System::Console::WriteLine("| 04. Cadastro de Endereços       |");
   System::Console::WriteLine("| 05. Cadastro de Idiomas         |");
   System::Console::WriteLine("| 06. Cadastro de Países          |");
   System::Console::WriteLine("| 07. Cadastro de Profissões      |");
   System::Console::WriteLine("| 08. Cadastro de Clientes        |");
   System::Console::WriteLine("| 09. Cadastro de Livros          |");
   System::Console::WriteLine("| 10. Voltar ao menu              |");
   System::Console::WriteLine("*---------------------------------*");
 } else if (num==3) {
   System::Console::WriteLine("*---------------------------------*");
   System::Console::WriteLine("| 01. Consulta de Assuntos        |");
   System::Console::WriteLine("| 02. Consulta de Autores         |");
   System::Console::WriteLine("| 03. Consulta de Editoras        |");
   System::Console::WriteLine("| 04. Consulta de Endereços       |");
   System::Console::WriteLine("| 05. Consulta de Idiomas         |");
   System::Console::WriteLine("| 06. Consulta de Países          |");
   System::Console::WriteLine("| 07. Consulta de Profissões      |");
   System::Console::WriteLine("| 08. Consulta de Clientes        |");
   System::Console::WriteLine("| 09. Consulta de Livros          |");
   System::Console::WriteLine("| 10. Voltar ao menu              |");
   System::Console::WriteLine("*---------------------------------*");
 } else if (num==4) {
   System::Console::WriteLine("*---------------------------------*");
   System::Console::WriteLine("| 01. Vender Livros               |");
   System::Console::WriteLine("| 02. Vendas Realizadas           |");
   System::Console::WriteLine("| 03. Voltar ao menu              |");
   System::Console::WriteLine("*---------------------------------*");
 } else if (num==5) {
   System::Console::WriteLine("*---------------------------------*");
   System::Console::WriteLine("| 01. Alterar senha               |");
   System::Console::WriteLine("| 02. Sobre o sistema             |");
   System::Console::WriteLine("| 03. Sair do sistema             |");
   System::Console::WriteLine("| 04. Voltar ao menu              |");
   System::Console::WriteLine("*---------------------------------*");
 } else if (num==6) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==7) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| (1) Salvar inclusão       (2) Voltar ao menu                 |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==8) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==9) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| (1) Salvar alteração      (2) Voltar ao menu                 |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==10) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| Certeza de excluir? (S/N)                                    |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==11) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| Deseja sair do sistema? (S/N)                                |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==12) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==13) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| Deseja continuar? (S/N)                                      |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 } else if (num==14) {
   System::Console::WriteLine("*--------------------------------------------------------------*");
   System::Console::WriteLine("| Salvar inclusão (S/N)                                        |");
   System::Console::WriteLine("*--------------------------------------------------------------*");
 }
 System::Console::Write(MSG_OPCAO);
}
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
Void Livrus::frmCadastros(ctArqs sreg, ctAcao sacao) {
String* slinha = S"";

if (sreg==ctArqs::opAssunto) {
   if (sacao==ctAcao::opNovo) {
	  tAssunto->codigo = pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao::opPesquisar) {
	 slinha = validaEntrada(tfAssunto,sreg,1,tAssunto->codigo,1,false,ctTipo::opNumero);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opAutor) {
   if (sacao==ctAcao::opNovo) {
	  tAutor->codigo = pesqMaxCod(tfAutor, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfAutor, sreg, 1, tAutor->codigo,1,false,ctTipo::opNumero);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opEditora) {
   if (sacao==ctAcao::opNovo) {
	  tEditora->codigo = pesqMaxCod(tfEditora, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfEditora,sreg,1,tEditora->codigo,1,false,ctTipo::opNumero);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opEndereco) {
   if (sacao==ctAcao::opNovo) {
	  tEndereco->codigo = pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfEndereco,sreg,1,tEndereco->codigo,1,
			  false,ctTipo::opNumero);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opIdioma) {
   if (sacao==ctAcao::opNovo) {
	  tIdioma->codigo = pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfIdioma,sreg,1,tIdioma->codigo,1,false,ctTipo::opNumero);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opPais) {
   if (sacao==ctAcao::opNovo) {
	  System::Console::Write(rotulo(sreg, 1));
	  tPais->codigo = System::Console::In->ReadLine();
	  slinha = pesqArq(tfPais, tPais->codigo, 1, 3, tamReg(sreg));
	  if (slinha->Equals("")) {
		 pesqLinhaExcluida(tfPais, tamReg(sreg));
		 mostrarDados(sreg, "", 1);
		 subMenu(7, sreg);
	  } else System::Console::WriteLine(MSG_REGEXST);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfPais, sreg, 1, tPais->codigo, 1, false, ctTipo::opTexto);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tPais->codigo));
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opProfissao) {
   if (sacao==ctAcao::opNovo) {
	  tProfissao->codigo = pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg));
	  mostrarDados(sreg, "", 1);
	  subMenu(7, sreg);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfProfissao,sreg,1,tProfissao->codigo,1,
			  false,ctTipo::opNumero);
	  if (slinha->Equals("")==false) {
		mostrarDados(sreg, "", 2);
		mostrarDados(sreg, slinha, 3);
		subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opLivro) {
   if (sacao==ctAcao::opNovo) {
	  System::Console::Write(rotulo(sreg, 1));
	  tLivro->isbn = System::Console::In->ReadLine();
	  if (ValidaISBN(tLivro->isbn)) {
		  slinha = pesqArq(tfLivro, tLivro->isbn, 1, 13, tamReg(sreg));
		  if (slinha->Equals("")) {
			 pesqLinhaExcluida(tfLivro, tamReg(sreg));
			 mostrarDados(sreg, "", 1);
			 subMenu(7, sreg);
			 frmCadLigados(ctArqs::opLivroAss, ctAcao::opNovo, tLivro->isbn);
			 frmCadLigados(ctArqs::opLivroAut, ctAcao::opNovo, tLivro->isbn);
		  } else System::Console::WriteLine(MSG_REGEXST);
	  } else System::Console::WriteLine(MSG_ISBNINV);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfLivro, sreg, 1, tLivro->isbn, 1,false,ctTipo::opTexto);
	  if (slinha->Equals("")==false) {
		 mostrarDados(sreg, "", 2);
		 mostrarDados(sreg, slinha, 3);
		 subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tLivro->isbn));
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
	  frmCadLigados(ctArqs::opLivroAss, ctAcao::opExcluir, tLivro->isbn);
	  System::Console::WriteLine("Assuntos dos livros excluídos, inclua novos!");
	  frmCadLigados(ctArqs::opLivroAss, ctAcao::opNovo, tLivro->isbn);
	  frmCadLigados(ctArqs::opLivroAut, ctAcao::opExcluir, tLivro->isbn);
	  System::Console::WriteLine("Autores dos livros excluídos, inclua novos!");
	  frmCadLigados(ctArqs::opLivroAut, ctAcao::opNovo, tLivro->isbn);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
	  System::Console::WriteLine("Assuntos dos livros sendo excluídos!");
	  frmCadLigados(ctArqs::opLivroAss, ctAcao::opExcluir, tLivro->isbn);
	  System::Console::WriteLine("Autores dos livros sendo excluídos!");
	  frmCadLigados(ctArqs::opLivroAut, ctAcao::opExcluir, tLivro->isbn);
   }
} else if (sreg==ctArqs::opCliente) {
   if (sacao==ctAcao::opNovo) {
	  System::Console::Write(rotulo(sreg, 1));
	  tCliente->cpf = System::Console::In->ReadLine();
	  if (ValidaCPF(tCliente->cpf)) {
		  slinha = pesqArq(tfCliente, tCliente->cpf, 1, 14, tamReg(sreg));
		  if (slinha->Equals("")) {
			 pesqLinhaExcluida(tfCliente, tamReg(sreg));
			 mostrarDados(sreg, "", 1);
			 subMenu(7, sreg);
		  } else System::Console::WriteLine(MSG_REGEXST);
	  } else System::Console::WriteLine(MSG_CPFINV);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfCliente, sreg, 1, tCliente->cpf,1,false,ctTipo::opTexto);
	  if (slinha->Equals("")==false) {
		 mostrarDados(sreg, "", 2);
		 mostrarDados(sreg, slinha, 3);
		 subMenu(8, sreg);
	  }
   } else if (sacao==ctAcao::opAlterar) {
	  System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tCliente->cpf));
	  mostrarDados(sreg, "", 1);
	  subMenu(9, sreg);
   } else if (sacao==ctAcao::opExcluir) {
	  subMenu(10, sreg);
   }
} else if (sreg==ctArqs::opVenda) {
   if (sacao==ctAcao::opNovo) {
	  tVenda->dthrvenda = retDataHora();
	  System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tVenda->dthrvenda));
	  slinha = pesqArq(tfVenda, tVenda->dthrvenda, 1, 19, tamReg(sreg));
	  if (slinha->Equals("")) {
		 slinha = validaEntrada(tfCliente,ctArqs::opCliente,1,tVenda->cpf,3,
				 false,ctTipo::opTexto);
		 if (slinha->Equals("")==false) {
			tVenda->cpf = copy(slinha,1,14)->Trim();
			if (ValidaCPF(tVenda->cpf)) {
			   System::Console::Write(String::Concat(" ", rotulo(ctArqs::opCliente, 2))); /* Nome */
			   System::Console::WriteLine(copy(slinha, g_nPosChave, g_nTamChave));
			   frmCadLigados(ctArqs::opVenda, ctAcao::opNovo, tVenda->cpf);
			} else System::Console::WriteLine(MSG_CPFINV);
		 }
	  } else System::Console::WriteLine(MSG_REGEXST);
   } else if (sacao==ctAcao::opPesquisar) {
	  slinha = validaEntrada(tfVenda, sreg, 1, tVenda->dthrvenda,1,
			  false,ctTipo::opDataHora);
	  if (slinha->Equals(S"")==false) {
		mostrarDados(sreg, S"", 2);
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
Void Livrus::frmConsultas(ctArqs sreg, ctAcao sacao) {
 String* slinha = S"";

if (sreg==ctArqs::opAssunto) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfAssunto,sreg,2,tAssunto->assunto,1,true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opAutor) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfAutor,sreg, 2, tAutor->autor, 1, true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opEditora) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfEditora,sreg,2,tEditora->editora,1,true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opEndereco) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfEndereco,sreg,2,tEndereco->logradouro,1,
			  true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
		 3, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opIdioma) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma->idioma,1,true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opPais) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfPais, sreg, 2, tPais->pais, 1, true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opProfissao) {
   if (sacao==ctAcao::opPesquisar)
	 slinha = validaEntrada(tfProfissao,sreg,2,tProfissao->profissao,1,
			 true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opLivro) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfLivro, sreg, 2, tLivro->titulo, 1, true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
		1, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opCliente) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfCliente, sreg, 2, tCliente->nome,1,true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
		1, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
} else if (sreg==ctArqs::opVenda) {
   if (sacao==ctAcao::opPesquisar)
	  slinha = validaEntrada(tfVenda, sreg, 2, tVenda->cpf, 1, true,ctTipo::opTexto);
   else if (sacao==ctAcao::opListarTodos) {
	  if (ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
		QTD_MAX_LINHA, false) == false)
		System::Console::WriteLine(rotulo(sreg, 0));
   }
}
if (slinha->Equals(""))
   System::Console::Write("");
}
/*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*/
Void Livrus::frmAlterarSenha() {
  Boolean bQuebra;
  String *sres, *sSenhaAtual, *sNovaSenha, *sConfirmaSenha;
  int nopcao;

sSenhaAtual = S"";
sNovaSenha = S"";
sConfirmaSenha = S"";

System::Console::WriteLine(String::Concat(rotulo(ctArqs::opUsuario, 1), tUsuario->login));
nopcao = 1;
bQuebra = false;
while (bQuebra==false) {
  switch(nopcao) {
   case 1: {
       sSenhaAtual = digitaSenha("Senha Atual: ", 10);
	   if (sSenhaAtual->Equals(tUsuario->senha)==false) {
		  System::Console::WriteLine(MSG_SENCONFERE);
		  bQuebra = true;
	   } else nopcao = 2;
	  } break;
   case 2: {
	   sNovaSenha = digitaSenha("Nova Senha: ", 10);
	   sConfirmaSenha = digitaSenha("Confirma Senha: ", 10);
	   if (sNovaSenha->Equals(sConfirmaSenha)==false) {
		  System::Console::WriteLine(MSG_SENCONFIRM);
		  bQuebra = true;
	   } else nopcao = 3;
	  } break;
   case 3: {
	   sres = pesqArq(tfUsuario, tUsuario->login, 1, 10, tamReg(ctArqs::opUsuario));
	   if (sres->Equals(""))
		 System::Console::WriteLine(MSG_LOGINENCON);
	   else {
		 tUsuario->senha = sConfirmaSenha;
		 subMenu(9,ctArqs::opUsuario);
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
Void Livrus::btnAcao(ctArqs sreg, ctAcao sacao) {
if (sreg==ctArqs::opAssunto) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opAutor) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opEditora) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opEndereco) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opIdioma) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opPais) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opProfissao) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	 escreveArq(tfProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opLivro) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opLivroAss) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opLivroAut) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opCliente) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opVenda) {
   if (sacao==ctAcao::opSalvarInclusao)
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   else if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   else if (sacao==ctAcao::opConfirmaExclusao)
	  escreveArq(tfVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
} else if (sreg==ctArqs::opUsuario) {
   if (sacao==ctAcao::opSalvarAlteracao)
	  escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
}
}
/*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
Void Livrus::subMenu(int nmenu, ctArqs sreg) {
  String *opSubMenu;
  char opCSubMenu;
  Boolean bSOp;

bSOp = true;
switch(nmenu) {
 case 6:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System::Console::In->ReadLine();
	 if (opSubMenu->Equals("1")) frmCadastros(sreg, ctAcao::opNovo);
	 else if (opSubMenu->Equals("2")) frmCadastros(sreg, ctAcao::opPesquisar);
	 else if (opSubMenu->Equals("3")) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
 case 7:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System::Console::In->ReadLine();
	 if (opSubMenu->Equals("1")) { btnAcao(sreg, ctAcao::opSalvarInclusao); bSOp = false; }
	 else if (opSubMenu->Equals("2")) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
 case 8:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System::Console::In->ReadLine();
	 if (opSubMenu->Equals("1")) { frmCadastros(sreg, ctAcao::opAlterar); bSOp = false; }
	 else if (opSubMenu->Equals("2")) { frmCadastros(sreg, ctAcao::opExcluir); bSOp = false; }
	 else if (opSubMenu->Equals("3")) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
 case 9:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System::Console::In->ReadLine();
	 if (opSubMenu->Equals("1")) { btnAcao(sreg, ctAcao::opSalvarAlteracao); bSOp = false; }
	 else if (opSubMenu->Equals("2")) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
 case 10:{
	while(bSOp) {
	 menu(nmenu);
	 opCSubMenu = System::Console::In->ReadLine()->get_Chars(0);
	 if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
		btnAcao(sreg, ctAcao::opConfirmaExclusao);
		bSOp = false;
	 } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
 case 12:{
	while(bSOp) {
	 menu(nmenu);
	 opSubMenu = System::Console::In->ReadLine();
	 if (opSubMenu->Equals("1")) frmConsultas(sreg, ctAcao::opPesquisar);
	 else if (opSubMenu->Equals("2")) frmConsultas(sreg, ctAcao::opListarTodos);
	 else if (opSubMenu->Equals("3")) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
 case 14:{
	while(bSOp) {
	 menu(nmenu);
	 opCSubMenu = System::Console::In->ReadLine()->get_Chars(0);
	 if ((opCSubMenu=='S') || (opCSubMenu=='s')) {
		btnAcao(sreg, ctAcao::opSalvarInclusao);
		bSOp = false;
		g_SalvarInclusao = true;
	 } else if ((opCSubMenu=='N') || (opCSubMenu=='n')) bSOp = false;
	 else System::Console::WriteLine(MSG_ERRO);
	}
   } break;
}

}
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*/
Void Livrus::usaMenu(int num) {
  String* opSubMenu;
  Boolean bSOp;
  char opSair;

 bSOp = true;
 if (num == 1) { /* Cadastros */
   while(bSOp) {
      menu(2);
      opSubMenu = System::Console::In->ReadLine();
      if (opSubMenu->Equals("1")) subMenu(6, ctArqs::opAssunto);
      else if (opSubMenu->Equals("2")) subMenu(6, ctArqs::opAutor);
      else if (opSubMenu->Equals("3")) subMenu(6, ctArqs::opEditora);
      else if (opSubMenu->Equals("4")) subMenu(6, ctArqs::opEndereco);
      else if (opSubMenu->Equals("5")) subMenu(6, ctArqs::opIdioma);
      else if (opSubMenu->Equals("6")) subMenu(6, ctArqs::opPais);
      else if (opSubMenu->Equals("7")) subMenu(6, ctArqs::opProfissao);
      else if (opSubMenu->Equals("8")) subMenu(6, ctArqs::opCliente);
      else if (opSubMenu->Equals("9")) subMenu(6, ctArqs::opLivro);
      else if (opSubMenu->Equals("10")) bSOp = false;
      else System::Console::WriteLine(MSG_ERRO);
   }
 } else if (num == 2) { /* Pesquisas */
   while(bSOp) {
      menu(3);
      opSubMenu = System::Console::In->ReadLine();
      if (opSubMenu->Equals("1")) subMenu(12, ctArqs::opAssunto);
      else if (opSubMenu->Equals("2")) subMenu(12, ctArqs::opAutor);
      else if (opSubMenu->Equals("3")) subMenu(12, ctArqs::opEditora);
      else if (opSubMenu->Equals("4")) subMenu(12, ctArqs::opEndereco);
      else if (opSubMenu->Equals("5")) subMenu(12, ctArqs::opIdioma);
      else if (opSubMenu->Equals("6")) subMenu(12, ctArqs::opPais);
      else if (opSubMenu->Equals("7")) subMenu(12, ctArqs::opProfissao);
      else if (opSubMenu->Equals("8")) subMenu(12, ctArqs::opCliente);
      else if (opSubMenu->Equals("9")) subMenu(12, ctArqs::opLivro);
      else if (opSubMenu->Equals("10")) bSOp = false;
      else System::Console::WriteLine(MSG_ERRO);
   }
 } else if (num == 3) { /* Vendas */
   while(bSOp) {
      menu(4);
      opSubMenu = System::Console::In->ReadLine();
      if (opSubMenu->Equals("1")) subMenu(6, ctArqs::opVenda);
      else if (opSubMenu->Equals("2")) subMenu(12, ctArqs::opVenda);
      else if (opSubMenu->Equals("3")) bSOp = false;
      else System::Console::WriteLine(MSG_ERRO);
   }
 } else if (num == 4) { /* Opcoes */
   while(bSOp) {
      menu(5);
      opSubMenu = System::Console::In->ReadLine();
      if (opSubMenu->Equals("1")) frmAlterarSenha();
      else if (opSubMenu->Equals("2")) frmSobre();
      else if (opSubMenu->Equals("3")) {
	   menu(11);
	   opSair = System::Console::In->ReadLine()->get_Chars(0);
	   if ((opSair=='S') || (opSair=='s')) {
		  fechaArqs();
		  System::Environment::Exit(0);
	   }
	 }
      else if (opSubMenu->Equals("4")) bSOp = false;
      else System::Console::WriteLine(MSG_ERRO);
   }
 }
}
/*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*/
Void Livrus::mostrarDados(ctArqs sreg, String* slinha, int nOpcao) {
if (sreg==ctArqs::opAssunto) {
   switch(nOpcao) {
	case 1: {
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1),tAssunto->codigo));
		System::Console::Write(rotulo(sreg, 2));
		tAssunto->assunto = System::Console::In->ReadLine();
	   } break;
	case 2: {
		System::Console::WriteLine("Código     Assunto");
		System::Console::WriteLine("------     -------");
	   } break;
	case 3: {
		tAssunto->codigo = copy(slinha, 1, 10)->Trim();
		tAssunto->assunto = copy(slinha, 11, 30)->Trim();
		System::Console::WriteLine(
		String::Concat(esp(tAssunto->codigo,10), " ",
				esp(tAssunto->assunto,30)));
	   } break;
   }
} else if (sreg==ctArqs::opAutor) {
   switch(nOpcao) {
	case 1: {
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), 
		tAutor->codigo));
		System::Console::Write(rotulo(sreg, 2));
		tAutor->autor = System::Console::In->ReadLine();
	   } break;
	case 2: {
		System::Console::WriteLine("Código     Autor");
		System::Console::WriteLine("------     -----");
	   } break;
	case 3: {
		tAutor->codigo = copy(slinha, 1, 10)->Trim();
		tAutor->autor = copy(slinha, 11, 30)->Trim();
		System::Console::WriteLine(String::Concat(esp(tAutor->codigo,10),
		" ",esp(tAutor->autor,30)));
	   } break;
   }
} else if (sreg==ctArqs::opEditora) {
   switch(nOpcao) {
	case 1: {
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), 
		tEditora->codigo));
		System::Console::Write(rotulo(sreg, 2));
		tEditora->editora = System::Console::In->ReadLine();
	   } break;
	case 2: {
		System::Console::WriteLine("Código     Editora");
		System::Console::WriteLine("------     -------");
	   } break;
	case 3: {
		tEditora->codigo = copy(slinha, 1, 10)->Trim();
		tEditora->editora = copy(slinha, 11, 50)->Trim();
		System::Console::WriteLine(String::Concat(
		esp(tEditora->codigo,10)," ", esp(tEditora->editora,50)));
       } break;
   }
} else if (sreg==ctArqs::opEndereco) {
   switch(nOpcao) {
	case 1: {
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), 
		tEndereco->codigo));
		System::Console::Write(rotulo(sreg, 2));
		tEndereco->logradouro = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 3));
		tEndereco->bairro = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 4));
		tEndereco->cep = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 5));
		tEndereco->cidade = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 6));
		tEndereco->estado = System::Console::In->ReadLine();
	   } break;
	case 3: {
		tEndereco->codigo = copy(slinha, 1, 10)->Trim();
		tEndereco->logradouro = copy(slinha, 11, 40)->Trim();
		tEndereco->bairro = copy(slinha, 51, 15)->Trim();
		tEndereco->cep = copy(slinha, 66, 8)->Trim();
		tEndereco->cidade = copy(slinha, 74, 30)->Trim();
		tEndereco->estado = copy(slinha, 104, 20)->Trim();
		System::Console::WriteLine("--------------------");
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), 
			tEndereco->codigo));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 2), 
			tEndereco->logradouro));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 3), 
			tEndereco->bairro));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 4), 
			tEndereco->cep));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 5), 
			tEndereco->cidade));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 6), 
			tEndereco->estado));
	   } break;
   }
} else if (sreg==ctArqs::opIdioma) {
   switch(nOpcao) {
	case 1: {
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tIdioma->codigo));
		System::Console::Write(rotulo(sreg, 2));
		tIdioma->idioma = System::Console::In->ReadLine();
	   } break;
	case 2: {
		System::Console::WriteLine("Código     Idioma");
		System::Console::WriteLine("------     ------");
	   } break;
	case 3: {
		tIdioma->codigo = copy(slinha, 1, 10)->Trim();
		tIdioma->idioma = copy(slinha, 11, 20)->Trim();
		System::Console::WriteLine(String::Concat(esp(tIdioma->codigo,10)," ",
						   esp(tIdioma->idioma,20)));
	   } break;
   }
} else if (sreg==ctArqs::opPais) {
   switch(nOpcao) {
	case 1: {
		System::Console::Write(rotulo(sreg, 2));
		tPais->pais = System::Console::In->ReadLine();
	   } break;
	case 2: {
		System::Console::WriteLine("Código País");
		System::Console::WriteLine("------ ----");
	   } break;
	case 3: {
		tPais->codigo = copy(slinha, 1, 3)->Trim();
		tPais->pais = copy(slinha, 4, 50)->Trim();
		System::Console::WriteLine(String::Concat(esp(tPais->codigo,3),
		"    ",esp(tPais->pais,50)));
	   } break;
   }
} else if (sreg==ctArqs::opProfissao) {
   switch(nOpcao) {
	case 1: {
		System::Console::WriteLine(
		String::Concat(rotulo(sreg, 1), tProfissao->codigo));
		System::Console::WriteLine(rotulo(sreg, 2));
		tProfissao->profissao = System::Console::In->ReadLine();
	   } break;
	case 2: {
		System::Console::WriteLine("Código     Profissão");
		System::Console::WriteLine("------     ---------");
	   } break;
	case 3: {
		tProfissao->codigo = copy(slinha, 1, 10)->Trim();
		tProfissao->profissao = copy(slinha, 11, 50)->Trim();
		System::Console::WriteLine(String::Concat(esp(tProfissao->codigo,10),
		" ",esp(tProfissao->profissao,50)));
	   } break;
   }
} else if (sreg==ctArqs::opLivro) {
   switch(nOpcao) {
	case 1: {
		System::Console::Write(rotulo(sreg, 2));
		tLivro->titulo = System::Console::In->ReadLine();
		tLivro->edicao = validaNumero(rotulo(sreg, 3), tLivro->edicao);
		tLivro->anopubli = validaNumero(rotulo(sreg, 4), tLivro->anopubli);
		mostrarSubDados(ctArqs::opLivro, ctArqs::opEditora, false);
		tLivro->volume = validaNumero(rotulo(sreg, 6), tLivro->volume);
		mostrarSubDados(ctArqs::opLivro, ctArqs::opIdioma, false);
		tLivro->npaginas = validaNumero(rotulo(sreg, 8), tLivro->npaginas);
		tLivro->preco = validaNumero(rotulo(sreg, 9), tLivro->preco);
		tLivro->qtdestoque = validaNumero(rotulo(sreg, 10),
		tLivro->qtdestoque);
	   } break;
	case 3: {
		tLivro->isbn = copy(slinha, 1, 13)->Trim();
		tLivro->titulo = copy(slinha, 14, 50)->Trim();
		tLivro->edicao = copy(slinha, 64, 10)->Trim();
		tLivro->anopubli = copy(slinha, 74, 10)->Trim();
		tLivro->codeditora = copy(slinha, 84, 10)->Trim();
		tLivro->volume = copy(slinha, 94, 10)->Trim();
		tLivro->codidioma = copy(slinha, 104, 10)->Trim();
		tLivro->npaginas = copy(slinha, 114, 10)->Trim();
		tLivro->preco = copy(slinha, 124, 10)->Trim();
		tLivro->qtdestoque = copy(slinha, 134, 10)->Trim();
		System::Console::WriteLine("--------------------");
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tLivro->isbn));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 2), tLivro->titulo));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 3), tLivro->edicao));
		System::Console::WriteLine(rotulo(sreg, 4), tLivro->anopubli);
		System::Console::WriteLine(String::Concat(rotulo(sreg, 5), tLivro->codeditora));
		mostrarSubDados(ctArqs::opLivro, ctArqs::opEditora, true);
		System::Console::WriteLine(String::Concat(rotulo(sreg, 6), tLivro->volume));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 7), tLivro->codidioma));
		mostrarSubDados(ctArqs::opLivro, ctArqs::opIdioma, true);
		System::Console::WriteLine(String::Concat(rotulo(sreg, 8), tLivro->npaginas));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 9), tLivro->preco));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 10), tLivro->qtdestoque));
		ListarRegLigados(tfLivroAss, ctArqs::opLivroAss, 1, 13, 14, 10, tLivro->isbn,
						 tfAssunto, ctArqs::opAssunto, 1, 4);
		ListarRegLigados(tfLivroAut, ctArqs::opLivroAut, 1, 13, 14, 10, tLivro->isbn,
						 tfAutor, ctArqs::opAutor, 1, 4);
	   } break;
   }
} else if (sreg==ctArqs::opCliente) {
   switch(nOpcao) {
	case 1: {
		System::Console::Write(rotulo(sreg, 2));
		tCliente->nome = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 3));
		tCliente->email = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 4));
		tCliente->identidade = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 5));
		tCliente->sexo = System::Console::In->ReadLine();
		System::Console::Write(rotulo(sreg, 6));
		tCliente->telefone = System::Console::In->ReadLine();
		tCliente->dtnascimento =
				validaDataHora(rotulo(sreg, 7), tCliente->dtnascimento, true);
		mostrarSubDados(ctArqs::opCliente, ctArqs::opEndereco, false);
		mostrarSubDados(ctArqs::opCliente, ctArqs::opPais, false);
		mostrarSubDados(ctArqs::opCliente, ctArqs::opProfissao, false);
	   } break;
	case 3: {
		tCliente->cpf = copy(slinha, 1, 14)->Trim();
		tCliente->nome = copy(slinha, 15, 30)->Trim();
		tCliente->email = copy(slinha, 45, 30)->Trim();
		tCliente->identidade = copy(slinha, 75, 10)->Trim();
		tCliente->sexo = copy(slinha, 85, 1)->Trim();
		tCliente->telefone = copy(slinha, 86, 17)->Trim();
		tCliente->dtnascimento = copy(slinha, 103, 10)->Trim();
		tCliente->codendereco = copy(slinha, 113, 10)->Trim();
		tCliente->codpais = copy(slinha, 123, 3)->Trim();
		tCliente->codprofissao = copy(slinha, 126, 10)->Trim();
		System::Console::WriteLine("--------------------");
		System::Console::WriteLine(String::Concat(rotulo(sreg, 1), tCliente->cpf));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 2), tCliente->nome));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 3), tCliente->email));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 4), tCliente->identidade));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 5), tCliente->sexo));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 6), tCliente->telefone));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 7), tCliente->dtnascimento));
		System::Console::WriteLine(String::Concat(rotulo(sreg, 8), tCliente->codendereco));
		mostrarSubDados(ctArqs::opCliente, ctArqs::opEndereco, true);
		System::Console::WriteLine(String::Concat(rotulo(sreg, 9), tCliente->codpais));
		mostrarSubDados(ctArqs::opCliente, ctArqs::opPais, true);
		System::Console::WriteLine(String::Concat(rotulo(sreg, 10), tCliente->codprofissao));
		mostrarSubDados(ctArqs::opCliente, ctArqs::opProfissao, true);
	   } break;
   }
} else if (sreg==ctArqs::opVenda) {
   switch(nOpcao) {
    case 1: mostrarSubDados(ctArqs::opVenda,ctArqs::opVenda, false); break;
    case 2: {
		System::Console::WriteLine(
		S"DataHoraVenda       CPF            ISBN          PreçoVenda");
		System::Console::WriteLine(
		S"-------------       ---            ----          ----------");
	   } break;
	case 3: {
		tVenda->dthrvenda = copy(slinha, 1, 19)->Trim();
		tVenda->cpf = copy(slinha, 20, 14)->Trim();
		tVenda->isbn = copy(slinha, 34, 13)->Trim();
		tVenda->precovenda = copy(slinha, 47, 10)->Trim();
		System::Console::WriteLine(String::Concat(esp(tVenda->dthrvenda,19),S" ",
		esp(tVenda->cpf,14),S" ",esp(tVenda->isbn,13),S" ",esp(tVenda->precovenda,10)));
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
Void Livrus::mostrarSubDados(ctArqs sreg, ctArqs ssubreg, Boolean bSoMostrar) {
String *sRegistro, *sPreco;
int nMaxTentativas;

nMaxTentativas = 3;
if (sreg==ctArqs::opLivro) {
  if (ssubreg==ctArqs::opEditora) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfEditora,tLivro->codeditora,1,10,tamReg(ctArqs::opEditora));
	else
	   sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro->codeditora,
				  nMaxTentativas,false,ctTipo::opNumero);
	if (sRegistro->Equals("")==false) {
	  tLivro->codeditora = copy(sRegistro,1,10)->Trim();
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opEditora, 2)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  } else if (ssubreg==ctArqs::opIdioma) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfIdioma, tLivro->codidioma, 1, 10,tamReg(ctArqs::opIdioma));
	else
	   sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro->codidioma,
				  nMaxTentativas,false,ctTipo::opNumero);
	if (sRegistro->Equals("")==false) {
	  tLivro->codidioma = copy(sRegistro,1,10)->Trim();
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opIdioma, 2)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  }
} else if (sreg==ctArqs::opCliente) {
  if (ssubreg==ctArqs::opEndereco) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfEndereco, tCliente->codendereco, 1, 10,
				  tamReg(ctArqs::opEndereco));
	else
	   sRegistro = validaEntrada(tfEndereco,ssubreg,1,tCliente->codendereco,
				  nMaxTentativas,false,ctTipo::opNumero);
	if (sRegistro->Equals("")==false) {
	  tCliente->codendereco = copy(sRegistro,1,10)->Trim();
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opEndereco, 2)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opEndereco, 3)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opEndereco, 4)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opEndereco, 5)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opEndereco, 6)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  } else if (ssubreg==ctArqs::opPais) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfPais, tCliente->codpais, 1, 3, tamReg(ctArqs::opPais));
	else
	   sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente->codpais,
				  nMaxTentativas,false,ctTipo::opTexto);
	if (sRegistro->Equals("")==false) {
	  tCliente->codpais = copy(sRegistro,1,3)->Trim();
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opPais, 2)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  } else if (ssubreg==ctArqs::opProfissao) {
	if (bSoMostrar)
	   sRegistro = pesqArq(tfProfissao, tCliente->codprofissao, 1, 10,
				  tamReg(ctArqs::opProfissao));
	else
	   sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente->codprofissao,
				  nMaxTentativas,false,ctTipo::opNumero);
	if (sRegistro->Equals("")==false) {
	  tCliente->codprofissao = copy(sRegistro,1,10)->Trim();
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opProfissao, 2)));
	  System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	}
  }
} else if (sreg==ctArqs::opVenda) {
  sRegistro = pesqArq(tfLivro, tVenda->isbn, 1, 13, tamReg(ctArqs::opLivro));
  if (sRegistro->Equals("")==false) {
	System::Console::Write(String::Concat(" ",rotulo(ctArqs::opLivro, 2))); /* Titulo */
	System::Console::WriteLine(copy(sRegistro, g_nPosChave, g_nTamChave));
	System::Console::Write(String::Concat(" ",rotulo(ctArqs::opLivro, 9))); /* Preco */
	sPreco = copy(sRegistro, g_nPosChave, g_nTamChave);
	g_nPreco = Single::Parse(sPreco);
	System::Console::WriteLine(sPreco);
  }
}
}
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*/
Void Livrus::frmCadLigados(ctArqs sreg, ctAcao sacao, String* sCodigo) {
  int nQtd, nCont, nQtdEstoque;
  double nTotalPreco;
  String *slinha, *sTotalPreco, *sPreco;
  String* sQtd = "";

if (sacao==ctAcao::opNovo) {
  nCont = 1;
  if (sreg==ctArqs::opLivroAss) {
	sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",sQtd);
	nQtd = Int32::Parse(sQtd);
	tfLivroAss->Seek(0, SeekOrigin::Begin);
	while (nCont <= nQtd) {
	  tLivroAss->isbn = sCodigo;
	  System::Console::Write(rotulo(ctArqs::opLivroAss, 2));
	  tLivroAss->codassunto = System::Console::In->ReadLine();
	  slinha = pesqArq(tfAssunto, tLivroAss->codassunto,1,10,tamReg(ctArqs::opAssunto));
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opAssunto, 2)));
	  System::Console::WriteLine(copy(slinha, g_nPosChave, g_nTamChave));
	  pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
	  subMenu(14, sreg);
	  nCont++;
	}
  } else if (sreg==ctArqs::opLivroAut) {
	sQtd = validaNumero("Quantos autores quer cadastrar?: ",sQtd);
	nQtd = Int32::Parse(sQtd);
	tfLivroAut->Seek(0, SeekOrigin::Begin);
	while (nCont <= nQtd) {
	  tLivroAut->isbn = sCodigo;
	  System::Console::Write(rotulo(ctArqs::opLivroAut, 2));
	  tLivroAut->codautor = System::Console::In->ReadLine();
	  slinha = pesqArq(tfAutor, tLivroAut->codautor,1,10,tamReg(ctArqs::opAutor));
	  System::Console::Write(String::Concat(" ",rotulo(ctArqs::opAutor, 2)));
	  System::Console::WriteLine(copy(slinha, g_nPosChave, g_nTamChave));
	  pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
	  subMenu(14, sreg);
	  nCont++;
	}
  } else if (sreg==ctArqs::opVenda) {
	sPreco = "";
	sTotalPreco = "";
	sQtd = validaNumero("Quantos livros quer vender?: ",sQtd);
	nQtd = Int32::Parse(sQtd);
	nTotalPreco = 0;
	while (nCont <= nQtd) {
	  slinha = validaEntrada(tfLivro,ctArqs::opLivro,1,tVenda->isbn,3,false,ctTipo::opTexto);
	  if (slinha->Equals("")==false) {
		tVenda->isbn = copy(slinha,1,13)->Trim();
		if (ValidaISBN(tVenda->isbn)) {
		  mostrarDados(sreg, "", 1);
		  tLivro->qtdestoque = copy(slinha,134,10)->Trim();
		  nQtdEstoque = Int32::Parse(tLivro->qtdestoque);
		  if (nQtdEstoque > 0) {
			 nTotalPreco = nTotalPreco + g_nPreco;
			 sPreco = Convert::ToString(g_nPreco);
			 tVenda->precovenda = sPreco;
			 g_SalvarInclusao = false;
			 subMenu(14, sreg);
			 if (g_SalvarInclusao) {
				slinha = pesqArq(tfLivro, tVenda->isbn, 1, 13, tamReg(ctArqs::opLivro));
				if (slinha->Equals("")==false) {
				   nQtdEstoque = nQtdEstoque-1;
				   tLivro->qtdestoque = Convert::ToString(nQtdEstoque);
				   slinha=String::Concat(copy(slinha,1,133), esp(tLivro->qtdestoque,10));
				   escreveArq(tfLivro, slinha, "", "");
				}
			 }
			 nCont++;
		  } else System::Console::WriteLine(MSG_SEMESTOQUE);
		} else System::Console::WriteLine(MSG_ISBNINV);
	  }
	}
	sTotalPreco = Convert::ToString(nTotalPreco);
	System::Console::WriteLine(String::Concat("Total de ",rotulo(sreg,4),sTotalPreco));
  }
} else if (sacao==ctAcao::opExcluir) {
  if (sreg==ctArqs::opLivroAss) {
	 ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo);
  } else if (sreg==ctArqs::opLivroAut) {
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
Void Livrus::ExcluirRegLigados(FileStream* sArq, ctArqs sreg, int nPosChave,
int nTamChave, String* sChave) {
  String* slinha = "";
  String* sCodigo;

	sArq->Seek(0, SeekOrigin::Begin);
	while (!fimArq(sArq)) {
	  slinha = lerArq(sArq, tamReg(sreg), TAM_CRLF);
	  if (slinha->Equals("")==false) {
		sCodigo = copy(slinha,nPosChave,nTamChave)->Trim();
		if (sCodigo->Equals(sChave))
		   btnAcao(sreg,ctAcao::opConfirmaExclusao);
	  }
	}

}

//}

int main(int argc, char *args[])
{
  System::Threading::Thread::CurrentThread->ApartmentState = System::Threading::ApartmentState::STA;
  Livrus* cl = new Livrus(); 
  
  String* arg0 = new String(args[0]);
  
  if ((argc > 0) && (arg0->Equals("-cria")))
    cl->abrecriaArqs(false);
  else {
    cl->frmSplash();
    cl->abrecriaArqs(true);
    if (cl->frmLogin()) {
  	cl->bopcao = true;
  	while(cl->bopcao) {
  	  cl->menu(1);
  	  cl->opmenu = System::Console::In->ReadLine()->get_Chars(0);
  	  if ((cl->opmenu=='C') || (cl->opmenu=='c')) cl->usaMenu(1);
  	  else if ((cl->opmenu=='P') || (cl->opmenu=='p')) cl->usaMenu(2);
  	  else if ((cl->opmenu=='V') || (cl->opmenu=='v')) cl->usaMenu(3);
  	  else if ((cl->opmenu=='O') || (cl->opmenu=='o')) cl->usaMenu(4);
  	  else System::Console::WriteLine(cl->MSG_ERRO);
  	}
    } else {
  	cl->fechaArqs();
  	System::Environment::Exit(0);
    }
  }
  System::Environment::Exit(0);
}