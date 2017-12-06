/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem harbour.
------------------------------------------------------------------------------*/
/* programa Livrus */

#include "Inkey.ch"
#include "Fileio.ch"

/* registros */
static tAssunto_codigo /* 10 */
static tAssunto_assunto /* 30 */ 

static tAutor_codigo /* 10 */ 
static tAutor_autor /* 30 */ 

static tEditora_codigo /* 10 */ 
static tEditora_editora /* 50 */ 

static tIdioma_codigo /* 10 */ 
static tIdioma_idioma /* 20 */ 

static tUsuario_login /* 10 */ 
static tUsuario_senha /* 10 */ 

static tPais_codigo /* 3 */ 
static tPais_pais /* 50 */ 

static tProfiss_codigo /* 10 */ 
static tProfiss_profissao /* 50 */ 

static tLiv_isbn /* 13 */ 
static tLiv_titulo /* 50 */ 
static tLiv_edicao /* 10 */ 
static tLiv_anopubli /* 10 */ 
static tLiv_codeditora /* 10 */ 
static tLiv_volume /* 10 */ 
static tLiv_codidioma /* 10 */ 
static tLiv_npaginas /* 10 */ 
static tLiv_preco /* 10 */ 
static tLiv_qtdestoque /* 10 */ 

static tLivAss_isbn /* 13 */ 
static tLivAss_codassunto /* 10 */ 

static tLivAut_isbn /* 13 */ 
static tLivAut_codautor /* 10 */ 

static tCli_cpf /* 14 */ 
static tCli_nome /* 30 */ 
static tCli_email /* 30 */ 
static tCli_identidade /* 10 */ 
static tCli_sexo /* 1 */ 
static tCli_telefone /* 17 */ 
static tCli_dtnascimento /* 10 */ 
static tCli_codendereco /* 10 */ 
static tCli_codpais /* 3 */ 
static tCli_codprofissao /* 10 */ 

static tEnd_codigo /* 10 */ 
static tEnd_logradouro /* 40 */ 
static tEnd_bairro /* 15 */ 
static tEnd_cep /* 8 */ 
static tEnd_cidade /* 30 */ 
static tEnd_estado /* 20 */ 

static tVenda_dthrvenda /* 19 */   /* data/hora da venda dd/mm/yyyy hh:mm:ss */
static tVenda_cpf /* 14 */ 
static tVenda_isbn /* 13 */ 
static tVenda_precovenda /* 10 */ 

/* constantes */

/* ctTipo */ 
#define opTexto 1 
#define opNumero 2
#define opData 3
#define opDataHora 4
#define opSenha 5
/* ctArqs */
#define opAssunto 1
#define opAutor 2
#define opEditora 3
#define opEndereco 4
#define opIdioma 5
#define opPais 6
#define opProfissao 7
#define opCliente 8
#define opLivro 9
#define opLivroAss 10
#define opLivroAut 11
#define opUsuario 12
#define opVenda 13
/* ctAcao */ 
#define opNovo 1
#define opAlterar 2
#define opPesquisar 3
#define opSalvarInclusao 4
#define opSalvarAlteracao 5
#define opExcluir 6
#define opConfirmaExclusao 7
#define opListarTodos 8

#define CRLF chr(13)+chr(10) /* windows */
#define TAM_CRLF 2
/* #define CRLF chr(10)
   #define TAM_CRLF 1 */ /* unix */
/* #define CRLF chr(13)
   #define TAM_CRLF 1 */ /* macintosh */

#define QTD_MAX_LINHA 18

#define MSG_ARQERRO "Erro: O arquivo não pode ser aberto."
#define MSG_ARQCERRO "Erro: O arquivo não pode ser criado."
#define MSG_ERRO "Erro: opção inválida digite de novo"
#define MSG_OPCAO "Escolha uma opção: "
#define MSG_PRESS "pressione para continuar..."

#define MSG_REGINC "registro incluido!"
#define MSG_REGNINC "registro não incluido!"
#define MSG_REGALT "registro alterado!"
#define MSG_REGNALT "registro não alterado!"
#define MSG_REGEXC "registro excluido!"
#define MSG_REGNEXC "registro não excluido!"
#define MSG_REGEXST "registro já existe!"

#define MSG_NUMINV "Número inválido ou menor do que 1!"
#define MSG_DATAINV "Data inválida!, formato correto (dd/mm/yyyy)"
#define MSG_DTHRINV "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)"
#define MSG_ISBNINV "ISBN inválido!"
#define MSG_CPFINV "CPF inválido!"
#define MSG_SENCONFERE "senha não confere com a senha atual!"
#define MSG_SENCONFIRM "nova senha não confere com a senha confirmada!"
#define MSG_LOGINENCON "login não encontrado!"
#define MSG_SEMESTOQUE "livro não existe no estoque!"

#define ARQ_ASSUNTO "assunto.dat"
#define ARQ_AUTOR "autor.dat"
#define ARQ_EDITORA "editora.dat"
#define ARQ_IDIOMA "idioma.dat"
#define ARQ_USUARIO "usuario.dat"
#define ARQ_PAIS "pais.dat"
#define ARQ_PROFISSAO "profissao.dat"
#define ARQ_LIVRO "livro.dat"
#define ARQ_LIVASS "livroass.dat"
#define ARQ_LIVAUT "livroaut.dat"
#define ARQ_CLIENTE "cliente.dat"
#define ARQ_ENDERECO "endereco.dat"
#define ARQ_VENDA "venda.dat"

#define TAM_ASSUNTO 40
#define TAM_AUTOR 40
#define TAM_EDITORA 60
#define TAM_IDIOMA 30
#define TAM_USUARIO 20
#define TAM_PAIS 53
#define TAM_PROFISSAO 60
#define TAM_LIVRO 143
#define TAM_LIVASS 23
#define TAM_LIVAUT 23
#define TAM_CLIENTE 135
#define TAM_ENDERECO 123
#define TAM_VENDA 56

/* variáveis globais */
static bopcao
static opmenu
static g_nPosChave, g_nTamChave
static g_nPreco
static g_SalvarInclusao

static tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, tfPais, tfProfissao,;
 tfLivro, tfLivroAss, tfLivroAut, tfCliente, tfUsuario, tfVenda

/*------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------*/
Function Main() 

/* Definições do programa */

set date to british
set century on
set console on
set scoreboard off
set device to screen

/* if ParamStr(1)="-cria"
     abrecriaArqs(.f.)
 else */
   frmSplash()
   abrecriaArqs(.t.)
   if frmLogin() 
     bopcao:=.t.
     do while(bopcao)      
       accept menu(1) to opmenu
       if (opmenu="C") .or. (opmenu="c") 
         usaMenu(1)
       elseif (opmenu="P") .or. (opmenu="p") 
         usaMenu(2)
       elseif (opmenu="V") .or. (opmenu="v") 
         usaMenu(3)
       elseif (opmenu="O") .or. (opmenu="o") 
         usaMenu(4)
       else 
         qout(MSG_ERRO)
       endif 
     enddo
   else 
     fechaArqs()
     quit
   endif
/* endif*/

return(nil)

/*--- Rotinas básicas ---------------------------------------------------------*/

/*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*/
function esp(sTexto, nTam)
return(sTexto+space(nTam-len(sTexto)))
/*------------------------------------------------------------------------------
Escreve zeros na frente de um texto.
stexto - o texto para receber zeros a frente
ntam - o tamanho da string
retorna - o texto com o zeros antes
------------------------------------------------------------------------------*/
function zeros(stexto, ntam)
local ncont, saux

  saux:=""
  if ntam<>len(stexto) 
      for ncont:=1 to ntam-len(stexto)
        saux:=saux + "0"
      next  
  endif
return(saux+stexto)
/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*/
function strRelativa(sTexto, sChave)
local nCont, nTamChave, nTamTexto, bret, sPedaco

bret:=.f.
nCont:=1
nTamChave:=len(sChave)
nTamTexto:=len(sTexto)
if nTamChave <= nTamTexto 
  do while nCont <= (nTamTexto-nTamChave+1)
     sPedaco:=substr(sTexto,nCont,nTamChave)
     if sPedaco==sChave
        bret:=.t.
     endif
     nCont++
  enddo 
endif
return(bret)
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a mstring com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*/
function modulo11(svalor, ndig)
local nmodulo11, ncont, nsoma, nvalor, npos, sres, slocal

 ncont:=1
 slocal:=""
 do while ncont <= 11
   slocal:=substr(svalor,ncont,1) + slocal
   ncont:=ncont+1
 enddo
 nsoma:=0
 if ndig=1
   ncont:=3
 else
   ncont:=2
 endif
 npos:=2
 do while ncont <= 11
   sres:=substr(slocal,ncont,1)
   nvalor:=Val(sres)
   nsoma:=nsoma + (nvalor * npos)
   ncont++
   npos++
 enddo
 nsoma:=(11 - (nsoma % 11))

if nsoma > 9
  nmodulo11:=0
else
  nmodulo11:=nsoma
endif
return(nmodulo11)

/*------------------------------------------------------------------------------
Validação de um número de CPF qualquer.
cpf - a mstring com o número do CPF
retorna - se é valido ou não
------------------------------------------------------------------------------*/
function validaCPF(cpf)
local scpf, sres, bvalidaCPF
local nstatus, nvalor1, nvalor2

if (len(cpf)=14) 
  scpf:=substr(cpf,1,3)+substr(cpf,5,3)+substr(cpf,9,3)+substr(cpf,13,2)
  sres:=substr(cpf,13,1)
  nvalor1:=Val(sres)
  sres:=substr(cpf,14,1)
  nvalor2:=Val(sres)
  if ((modulo11(scpf,1)=nvalor1) .and. (modulo11(scpf,2)=nvalor2))
    bvalidaCPF:=.t.
  else
    bvalidaCPF:=.f.
  endif
else
  bvalidaCPF:=.f.
endif
return(bvalidaCPF)
/*------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a mstring com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------*/
function validaISBN(isbn)
local snum, sdigito, sisbn, bvalidaISBN
local nvalor, nsoma, ncont

if (len(isbn)=13) 
  sdigito := substr(isbn, len(isbn), 1)
  sisbn:=""
  for ncont:=1 to len(isbn)-1
    if (substr(isbn,ncont,1)<>"-") 
      sisbn:=sisbn+substr(isbn,ncont,1)
    endif 
  next
  if sdigito = "X"
    nsoma := 10
  else
    nvalor:=Val(sdigito)
    nsoma:=nvalor
  endif
  for ncont:=1 to 9
    snum:=substr(sisbn, ncont, 1)
    nvalor:=Val(snum)
    nsoma:=nsoma + (nvalor * (11 - ncont))
  next
  If (nsoma % 11) = 0
    bvalidaISBN:=.t.
  else
    bvalidaISBN:=.f.
  endif
else
  bvalidaISBN:=.f.
endif
return(bvalidaISBN)
/*------------------------------------------------------------------------------
Esconde a digitação da senha
retorna - a senha digitada
------------------------------------------------------------------------------*/
function digitaSenha(sRotulo, nTamSenha)
local sSenha, ncont, nLetra
  
  qout(sRotulo)
  ncont := 0
  sSenha:=""
  nLetra:=0
  do while((nLetra<>K_ENTER) .and. (ncont < nTamSenha))    
    nLetra:=inkey(0)
    if nLetra<>K_ENTER 
      sSenha:=sSenha+chr(nLetra)
    endif
    ncont++
  enddo
return(sSenha)
/*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a mstring com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*/
function validaNumero(sRotulo, sNumero)
local nnum, nStatus

nStatus:=-1
do while (nStatus<>0)
  accept sRotulo to sNumero
  nnum:=Val(sNumero)
  if (ValType(nnum)<>"N") .or. (nnum < 1)
     qout(MSG_NUMINV)
  else
     nStatus = 0
  endif
enddo
return(sNumero)
/*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a mstring com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
function validaDataHora(sRotulo, sDataHora, bSoData)
local bvalida, bdatavalida, bhoravalida
local sdia, smes, sano, shora, smin, sseg
local ndia, nmes, nano, nhora, nmin, nseg, nudiames
local nStatus, ntam

bvalida:=.f.
bdatavalida:=.f.
bhoravalida:=.f.
nudiames:=0

if bSoData=.t. 
  ntam:=10
else 
  ntam:=19
endif
do while (bvalida=.f.)
  accept sRotulo to sDataHora
  if len(sDataHora)=ntam 
    sdia:=substr(sDataHora,1,2)
    ndia:=Val(sdia)
    smes:=substr(sDataHora,4,2)
    nmes:=Val(smes)
    sano:=substr(sDataHora,7,4)
    nano:=Val(sano)
  
    if (nano >= 1) .and. (nano <= 9999) 
      if (nmes >= 1) .and. (nmes <= 31) 
          do case 
           case nmes = 1 .or. nmes = 3 .or. nmes = 5 .or. nmes = 7 .or.;
                nmes = 8 .or. nmes = 10 .or. nmes = 12
               nudiames:=31
           case nmes = 2
               /* ano bissexto */
               if (nano % 4)=0 
                 nudiames:=29
               else 
                 nudiames:=28
               endif
           case nmes = 4 .or. nmes = 6 .or. nmes = 9 .or. nmes = 11 
              nudiames:=30
          endcase
          if (ndia >=1) .and. (ndia <=nudiames)
             bdatavalida:=.t.
          endif
      endif
    endif
  
    if bSoData 
       if bdatavalida 
          bvalida:=.t.
       else 
          qout(MSG_DATAINV)
       endif
    else 
      if bdatavalida 
          shora:=substr(sDataHora,12,2)
          nhora:=Val(shora)
          smin:=substr(sDataHora,15,2)
          nmin:=Val(smin)
          sseg:=substr(sDataHora,18,2)
          nseg:=Val(sseg)
  
          if (nhora >= 0) .and. (nhora <= 23) 
            if (nmin >= 0) .and. (nmin <= 59) 
              if (nseg >= 0) .and. (nseg <= 59)
                 bhoravalida:=.t.
              endif 
            endif
          endif
  
          if bhoravalida 
            bvalida:=.t.
          else 
            qout(MSG_DTHRINV)
          endif
      else
        qout(MSG_DTHRINV)
      endif
    endif
  else 
    if bSoData=.t. 
       qout(MSG_DATAINV)
    else 
       qout(MSG_DTHRINV)
    endif
  endif
enddo
return(sDataHora)
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
function retDataHora()
return(dtoc(date())+" "+time())

/*--- Rotinas de manipulação de arquivos --------------------------------------*/

/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
function tamArq(sArq)
local npos, ntam

npos := fseek( sArq, 0, FS_RELATIVE )
ntam := fseek( sArq, 0, FS_END )
fseek(sArq, npos)
return(ntam)

/*------------------------------------------------------------------------------
Verifica se chegou no fim do arquivo.
sArq - o arquivo
retorna - se chegou ou não o fim de arquivo
------------------------------------------------------------------------------*/
function fimArq(sArq)
local bret

if tamArq(sArq) == fseek(sArq, 0, FS_RELATIVE)
   bret:=.t.
else
   bret:=.f.
endif
return(bret)

/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
procedure abrecriaArqs(bAbre)
if bAbre 
    if (tfAssunto:=fopen(ARQ_ASSUNTO,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_ASSUNTO)
    endif
    if (tfAutor:=fopen(ARQ_AUTOR,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_AUTOR)
    endif
    if (tfEditora:=fopen(ARQ_EDITORA,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_EDITORA)
    endif
    if (tfIdioma:=fopen(ARQ_IDIOMA,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_IDIOMA)
    endif
    if (tfEndereco:=fopen(ARQ_ENDERECO,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_ENDERECO)
    endif
    if (tfPais:=fopen(ARQ_PAIS,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_PAIS)
    endif
    if (tfProfissao:=fopen(ARQ_PROFISSAO,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_PROFISSAO)
    endif
    if (tfLivro:=fopen(ARQ_LIVRO,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_LIVRO)
    endif
    if (tfLivroAss:=fopen(ARQ_LIVASS,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_LIVASS)
    endif
    if (tfLivroAut:=fopen(ARQ_LIVAUT,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_LIVAUT)
    endif
    if (tfCliente:=fopen(ARQ_CLIENTE,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_CLIENTE)
    endif
    if (tfUsuario:=fopen(ARQ_USUARIO,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_USUARIO)
    endif
    if (tfVenda:=fopen(ARQ_VENDA,FO_READWRITE)) = -1
     qout(MSG_ARQERRO+" --> "+ARQ_VENDA)
    endif
else 
    if (tfAssunto:=fcreate(ARQ_ASSUNTO,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_ASSUNTO)
    endif 
    if (tfAutor:=fcreate(ARQ_AUTOR,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_AUTOR)
    endif
    if (tfEditora:=fcreate(ARQ_EDITORA,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_EDITORA)
    endif
    if (tfIdioma:=fcreate(ARQ_IDIOMA,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_IDIOMA)
    endif 
    if (tfEndereco:=fcreate(ARQ_ENDERECO,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_ENDERECO)
    endif 
    if (tfPais:=fcreate(ARQ_PAIS,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_PAIS)
    endif 
    if (tfProfissao:=fcreate(ARQ_PROFISSAO,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_PROFISSAO)
    endif 
    if (tfLivro:=fcreate(ARQ_LIVRO,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_LIVRO)
    endif 
    if (tfLivroAss:=fcreate(ARQ_LIVASS,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_LIVASS)
    endif 
    if (tfLivroAut:=fcreate(ARQ_LIVAUT,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_LIVAUT)
    endif
    if (tfCliente:=fcreate(ARQ_CLIENTE,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_CLIENTE)
    endif 
    if (tfUsuario:=fcreate(ARQ_USUARIO,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_USUARIO)
    endif 
    if (tfVenda:=fcreate(ARQ_VENDA,FC_NORMAL)) = -1
     qout(MSG_ARQCERRO+" --> "+ARQ_VENDA)
    endif
endif
return
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
procedure fechaArqs()
  fclose(tfAssunto)
  fclose(tfAutor)
  fclose(tfEditora)
  fclose(tfIdioma)
  fclose(tfEndereco)
  fclose(tfPais)
  fclose(tfProfissao)
  fclose(tfLivro)
  fclose(tfLivroAss)
  fclose(tfLivroAut)
  fclose(tfCliente)
  fclose(tfUsuario)
  fclose(tfVenda)
return
/*------------------------------------------------------------------------------
Pesquisa um registro através de um valor chave num arquivo.
sArq - o arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o registro pesquisado
------------------------------------------------------------------------------*/
function pesqArq(sArq, sChave, nPosChave, nTamChave, nTamLinha)
local spesqArq, sres, bQuebra, nStatus, nPosicao, nler, slinha

nler:=nTamLinha + TAM_CRLF
slinha:=space(nler)
bQuebra:=.f.
fseek(sArq, 0, FS_SET)
do while (!fimArq(sArq)) .and. (bQuebra=.f.) 
  fread(sArq, @slinha, nler)
  sres:=alltrim(substr(slinha,nPosChave,nTamChave))
  if sres == sChave
     bQuebra:=.t.
  endif
enddo
nPosicao:=fseek(sArq,0,FS_RELATIVE)-(nTamLinha + TAM_CRLF)
if nPosicao > 0
   fseek(sArq, nPosicao, FS_SET)
else
   fseek(sArq, 0, FS_SET)
endif
if sres==sChave
   spesqArq:=substr(slinha,1,nTamLinha)
else
   spesqArq:=""
endif
return(spesqArq)
/*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
procedure pesqLinhaExcluida(sArq, nTamLinha)
local sExcluido

sExcluido:=pesqArq(sArq, "*", 1, 1, nTamLinha)
if empty(sExcluido)
   fseek(sArq, tamArq(sArq), FS_SET)
endif
return
/*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*/
function pesqMaxCod(sArq, nPosChave, nTamChave, nTamLinha)
local slinha, sRes, nler
local bQuebra, nStatus, nMaior, nCod

nler:=nTamLinha + TAM_CRLF
slinha:=space(nler)
bQuebra:=.f.
nMaior:=0
fseek(sArq, 0, FS_SET)
do while (!fimArq(sArq)) .and. (bQuebra=.f.) 
  fread(sArq, @slinha, nler)
  sres:=alltrim(substr(slinha,nPosChave,nTamChave))
  ncod:=Val(sres)
  if nCod > nMaior
     nMaior:=nCod
  endif
enddo
pesqLinhaExcluida(sArq, nTamLinha)
sres:=alltrim(str(nMaior+1))
return(sres)
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*/
procedure escreveArq(sArq,sTexto, sMsgAcerto, sMsgErro)

sTexto:=sTexto+CRLF
if fwrite(sArq, sTexto, len(sTexto)) = len(sTexto)
   qout(sMsgAcerto)
else 
   qout(sMsgErro)
endif
return

/*--- Rotinas de implementação do sistema e de interface ----------------------*/

/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
function LinhaReg(sreg)
local slinha

slinha:=""
if sreg = opAssunto
   slinha:=esp(tAssunto_codigo,10)+esp(tAssunto_assunto,30)
elseif sreg = opAutor
   slinha:=esp(tAutor_codigo,10)+esp(tAutor_autor,30)
elseif sreg = opEditora
   slinha:=esp(tEditora_codigo,10)+esp(tEditora_editora,50)
elseif sreg = opEndereco
   slinha:=esp(tEnd_codigo,10)+esp(tEnd_logradouro,40)+;
   esp(tEnd_bairro,15)+esp(tEnd_cep,8)+esp(tEnd_cidade,30)+;
   esp(tEnd_estado,20)
elseif sreg = opIdioma
   slinha:=esp(tIdioma_codigo,10)+esp(tIdioma_idioma,20)
elseif sreg = opPais
   slinha:=esp(tPais_codigo,3)+esp(tPais_pais,50)
elseif sreg = opProfissao
   slinha:=esp(tProfiss_codigo,10)+esp(tProfiss_profissao,50)
elseif sreg = opUsuario
   slinha:=esp(tUsuario_login,10)+esp(tUsuario_senha,10)
elseif sreg = opLivro
   slinha:=esp(tLiv_isbn,13)+esp(tLiv_titulo,50)+esp(tLiv_edicao,10)+;
   esp(tLiv_anopubli,10)+esp(tLiv_codeditora,10)+esp(tLiv_volume,10)+;
   esp(tLiv_codidioma,10)+esp(tLiv_npaginas,10)+esp(tLiv_preco,10)+;
   esp(tLiv_qtdestoque,10)
elseif sreg = opLivroAss
   slinha:=esp(tLivAss_isbn,13)+esp(tLivAss_codassunto,10)
elseif sreg = opLivroAut
   slinha:=esp(tLivAut_isbn,13)+esp(tLivAut_codautor,10)
elseif sreg = opCliente
   slinha:=esp(tCli_cpf,14)+esp(tCli_nome,30)+esp(tCli_email,30)+;
   esp(tCli_identidade,10)+esp(tCli_sexo,1)+esp(tCli_telefone,17)+;
   esp(tCli_dtnascimento,10)+esp(tCli_codendereco,10)+;
   esp(tCli_codpais,3)+esp(tCli_codprofissao,10)
elseif sreg = opVenda
   slinha:=esp(tVenda_dthrvenda,19)+esp(tVenda_cpf,14)+esp(tVenda_isbn,13)+;
   esp(tVenda_precovenda,10)
endif
return(slinha)
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
function tamReg(sreg)
local nret

nret:=0
if sreg = opAssunto 
   nret:=TAM_ASSUNTO
elseif sreg = opAutor 
   nret:=TAM_AUTOR
elseif sreg = opEditora 
   nret:=TAM_EDITORA
elseif sreg = opEndereco 
   nret:=TAM_ENDERECO
elseif sreg = opIdioma 
   nret:=TAM_IDIOMA
elseif sreg = opPais 
   nret:=TAM_PAIS
elseif sreg = opProfissao 
   nret:=TAM_PROFISSAO
elseif sreg = opUsuario 
   nret:=TAM_USUARIO
elseif sreg = opLivro 
   nret:=TAM_LIVRO
elseif sreg = opLivroAss 
   nret:=TAM_LIVASS
elseif sreg = opLivroAut 
   nret:=TAM_LIVAUT
elseif sreg = opCliente 
   nret:=TAM_CLIENTE
elseif sreg = opVenda 
   nret:=TAM_VENDA
endif
return(nret)
/*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
function rotulo(sreg, nNum)
local sret

sret:=""
if sreg = opAssunto 
   do case
     case nNum = 0 
       sret:="Assunto(s) não encontrado(s)!"
     case nNum = 1
         sret:="Código do assunto: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2
         sret:="Assunto: "
         g_nPosChave:=11
         g_nTamChave:=30
   endcase
elseif sreg = opAutor 
   do case
     case nNum = 0 
        sret:="Autor(es) não encontrado(s)!"
     case nNum = 1 
         sret:="Código do autor: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2
         sret:="Autor: "
         g_nPosChave:=11
         g_nTamChave:=30
   endcase
elseif sreg = opEditora 
   do case
     case nNum = 0 
         sret:="Editora(s) não encontrada(s)!"
     case nNum = 1 
         sret:="Código da editora: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2 
         sret:="Editora: "
         g_nPosChave:=11
         g_nTamChave:=50
   endcase
elseif sreg = opEndereco 
   do case
     case nNum = 0 
       sret:="Endereço(s) não encontrado(s)!"
     case nNum = 1
         sret:="Código do endereço: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2
         sret:="Logradouro: "
         g_nPosChave:=11
         g_nTamChave:=40
     case nNum = 3
         sret:="Bairro: "
         g_nPosChave:=51
         g_nTamChave:=15
     case nNum = 4
         sret:="CEP: "
         g_nPosChave:=66
         g_nTamChave:=8
     case nNum = 5
         sret:="Cidade: "
         g_nPosChave:=74
         g_nTamChave:=30
     case nNum = 6
         sret:="Estado: "
         g_nPosChave:=104
         g_nTamChave:=20
   endcase
elseif sreg = opIdioma 
   do case
     case nNum = 0
         sret:="Idioma(s) não encontrado(s)!"
     case nNum = 1 
         sret:="Código do idioma: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2 
         sret:="Idioma: "
         g_nPosChave:=11
         g_nTamChave:=20
   endcase
elseif sreg = opPais 
   do case
     case nNum = 0
         sret:="País(es) não encontrado(s)!"
     case nNum = 1 
         sret:="Código do país: "
         g_nPosChave:=1
         g_nTamChave:=3
     case nNum = 2 
         sret:="País: "
         g_nPosChave:=4
         g_nTamChave:=50
   endcase
elseif sreg = opProfissao 
   do case
     case nNum = 0
         sret:="Profissão(es) não encontrada(s)!"
     case nNum = 1 
         sret:="Código da profissão: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2 
         sret:="Profissão: "
         g_nPosChave:=11
         g_nTamChave:=50
   endcase
elseif sreg = opUsuario 
   do case
     case nNum = 0
         sret:="login ou senha incorreta, tente de novo!"
     case nNum = 1
         sret:="Login: "
         g_nPosChave:=1
         g_nTamChave:=10
     case nNum = 2 
         sret:="Senha: "
         g_nPosChave:=11
         g_nTamChave:=10
   endcase
elseif sreg = opLivro 
   do case
     case nNum = 0
         sret:="Livro(s) não encontrado(s)!"
     case nNum = 1 
         sret:="ISBN: "
         g_nPosChave:=1
         g_nTamChave:=13
     case nNum = 2
         sret:="Título: "
         g_nPosChave:=14
         g_nTamChave:=50
     case nNum = 3
         sret:="Edição: "
         g_nPosChave:=64
         g_nTamChave:=10
     case nNum = 4 
         sret:="Ano de Publicação: "
         g_nPosChave:=74
         g_nTamChave:=10
     case nNum = 5 
         sret:="Código da editora: "
         g_nPosChave:=84
         g_nTamChave:=10
     case nNum = 6 
         sret:="Volume: "
         g_nPosChave:=94
         g_nTamChave:=10
     case nNum = 7 
         sret:="Código do idioma: "
         g_nPosChave:=104
         g_nTamChave:=10
     case nNum = 8 
         sret:="Número de páginas: "
         g_nPosChave:=114
         g_nTamChave:=10
     case nNum = 9 
         sret:="Preço: "
         g_nPosChave:=124
         g_nTamChave:=10
     case nNum = 10 
          sret:="Qtd. Estoque: "
          g_nPosChave:=134
          g_nTamChave:=10
   endcase
elseif sreg = opLivroAss 
   do case
     case nNum = 0
         sret:="Assunto(s) não encontrado(s)!"
     case nNum = 1 
         sret:="ISBN: "
         g_nPosChave:=1
         g_nTamChave:=13
     case nNum = 2 
         sret:="Código do assunto: "
         g_nPosChave:=14
         g_nTamChave:=10
   endcase
elseif sreg = opLivroAut
   do case
     case nNum = 0
         sret:="Autor(s) não encontrado(s)!"
     case nNum = 1 
         sret:="ISBN: "
         g_nPosChave:=1
         g_nTamChave:=13
     case nNum = 2 
         sret:="Código do autor: "
         g_nPosChave:=14
         g_nTamChave:=10
   endcase
elseif sreg = opCliente 
   do case
     case nNum = 0
         sret:="Cliente(s) não encontrado(s)!"
     case nNum = 1 
         sret:="CPF: "
         g_nPosChave:=1
         g_nTamChave:=14
     case nNum = 2 
         sret:="Nome: "
         g_nPosChave:=15
         g_nTamChave:=30
     case nNum = 3
         sret:="E-mail: "
         g_nPosChave:=45
         g_nTamChave:=30
     case nNum = 4 
         sret:="Identidade: "
         g_nPosChave:=75
         g_nTamChave:=10
     case nNum = 5 
         sret:="Sexo: "
         g_nPosChave:=85
         g_nTamChave:=1
     case nNum = 6 
         sret:="Telefone: "
         g_nPosChave:=86
         g_nTamChave:=17
     case nNum = 7 
         sret:="Dt. Nascimento: "
         g_nPosChave:=103
         g_nTamChave:=10
     case nNum = 8 
         sret:="Código do endereço: "
         g_nPosChave:=113
         g_nTamChave:=10
     case nNum = 9 
         sret:="Código do país: "
         g_nPosChave:=123
         g_nTamChave:=3
     case nNum = 10 
          sret:="Código da Profissão: "
          g_nPosChave:=126
          g_nTamChave:=10
   endcase
elseif sreg = opVenda 
   do case
     case nNum = 0
         sret:="Venda(s) não encontrada(s)!"
     case nNum = 1
         sret:="Data/Hora venda: "
         g_nPosChave:=1
         g_nTamChave:=19
     case nNum = 2
         sret:="CPF: "
         g_nPosChave:=20
         g_nTamChave:=14
     case nNum = 3
         sret:="ISBN: "
         g_nPosChave:=34
         g_nTamChave:=13
     case nNum = 4
         sret:="Pre+o de venda: "
         g_nPosChave:=47
         g_nTamChave:=10
   endcase
endif

return(sret)
/*------------------------------------------------------------------------------
Indica se continua ou não mostrando um número máximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou não
------------------------------------------------------------------------------*/
function ContinuaSN(nlinha, nQtdLinha)
local bSOp, bret, opCSubMenu

bret:=.f.
if nlinha > 0 
  if (nlinha % nQtdLinha) = 0 
    bSOp:=.t.
    do while(bSOp)      
       accept menu(13) to opCSubMenu
       if (opCSubMenu="S") .or. (opCSubMenu="s") 
          bSOp:=.f.
       elseif (opCSubMenu="N") .or. (opCSubMenu="n") 
          bret:=.t.
          bSOp:=.f.
       else 
          qout(MSG_ERRO)
       endif
    enddo
  endif
endif

return(bret)
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
function ListarTodos(sArq, sreg, sChave,;
   nPosChave, nTamChave, nTamLinha, nQtdLinha, bPesqRelativa)
local slinha, bQuebra, bAchou, bRet
local nStatus, nCont, sres, nler

nler:=nTamLinha + TAM_CRLF
slinha:=space(nler)
bRet:=.f.
bQuebra:=.f.
nCont:=0
mostrarDados(sreg, "", 2)
fseek(sArq, 0, FS_SET)
do while (!fimArq(sArq)) .and. (bQuebra=.f.) 
  fread(sArq, @slinha, nler)
  if bPesqRelativa 
    sres:=alltrim(substr(slinha,nPosChave,nTamChave))
    if strRelativa(sres,sChave) 
       bAchou:=.t.
       bRet:=.t.
    else
       bAchou:=.f.
    endif 
  else 
    bAchou:=.t.
    bRet:=.t.
  endif

  if bAchou
    mostrarDados(sreg, substr(slinha,1,nTamLinha), 3)
    nCont++
  endif

  bQuebra:=ContinuaSN(nCont, nQtdLinha)
enddo
return(bret)
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
procedure ListarRegLigados(sArq1, sreg1, nPosChave1,;
nTamChave1, nPosChave2, nTamChave2, sChave,;
sArq2, sreg2, nPosChave3, nQtdLinha)
local slinha1, bQuebra, bRet, nler
local nStatus, nCont, sCodigo1, sCodigo2, slinha2

nler:=tamReg(sreg1) + TAM_CRLF
slinha1:=space(nler)
bRet:=.f.
nCont:=0
bQuebra:=.f.
mostrarDados(sreg2, "", 2)
fseek(sArq1, 0, FS_SET)
do while (!fimArq(sArq1)) .and. (bQuebra=.f.) 
  fread(sArq1, @slinha1, nler)
  sCodigo1:=alltrim(substr(slinha1,nPosChave1,nTamChave1))
  if sCodigo1==sChave 
    sCodigo2:=alltrim(substr(slinha1,nPosChave2,nTamChave2))
    slinha2:=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
    mostrarDados(sreg2, substr(slinha2, 1, tamReg(sreg2)), 3)
    bRet:=.t.
    nCont++
  endif
  bQuebra:=ContinuaSN(nCont, nQtdLinha)
enddo
if bRet=.f.
   qout(rotulo(sreg2,0))
endif
return
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
function validaEntrada(sArq, sreg, nTexto,;
        sEntrada, nTentativas, bPesqRelativa, bTipoEntrada)
local bQuebra, sres, sTexto, sMsgErro
local ncont, nPosChave, nTamChave, nTamLinha

nTamLinha:=tamReg(sreg)
sMsgErro:=rotulo(sreg,0)
sTexto:=rotulo(sreg,nTexto)
nPosChave:=g_nPosChave
nTamChave:=g_nTamChave

ncont:=1
bQuebra:=.f.
  do while (bQuebra=.f.) .and. (ncont <= nTentativas )
    if bTipoEntrada = opTexto 
      accept sTexto to sEntrada
    elseif bTipoEntrada = opNumero
       sEntrada:=validaNumero(sTexto,sEntrada)
    elseif bTipoEntrada = opData
       sEntrada:=validaDataHora(sTexto,sEntrada,.t.)
    elseif bTipoEntrada = opDataHora
       sEntrada:=validaDataHora(sTexto,sEntrada,.f.)
    elseif bTipoEntrada = opSenha
       sEntrada:=digitaSenha(sTexto, 10)
    endif

    if bPesqRelativa 
       if ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave,;
          nTamLinha, QTD_MAX_LINHA, .t.)
          sres:="0"
       endif
    else
       sres:=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)
    endif

    if empty(sres)
       qout(sMsgErro)
    else
       bQuebra:=.t.
    endif
     
    ncont++
  enddo
return(sres)
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
procedure frmSplash()
local cont

 qout("*---------------------------------------"+;
 "-------------------------------------*")
 qout("| LL    II VV   VV RRRRR  UU  UU   SSSS "+;
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |")
 qout("| LL    II  VV VV  RR   R UU  UU  SS    "+;
 " VV VV  II RR   R  TT  UU  UU  SS    |")
 qout("| LL    II   VVV   RRRRR  UU  UU    SS  "+;
 "  VVV   II RRRRR   TT  UU  UU    SS  |")
 qout("| LLLLL II    V    RR   R  UUUU  SSSS   "+;
 "   V    II RR   R  TT   UUUU  SSSS   |")
 qout("*---------------------------------------"+;
 "-------------------------------------*")
 for cont:=1 to 18 
   qout()
 next
 qqout(MSG_PRESS)
 inkey(0)
return
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
procedure frmSobre()
local cont

 qout("*------------------------------------------------------------*")
 qout("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |")
 qout("|  LL        II   VV     VV   RR     R  UU    UU  SS         |")
 qout("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |")
 qout("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |")
 qout("|  LLLL      II      VVV      RR RR     UU    UU        SS   |")
 qout("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |")
 qout("|                                                            |")
 qout("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |")
 qout("|   VV     VV   II  RR     R     TT     UU    UU  SS         |")
 qout("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |")
 qout("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |")
 qout("|      VVV      II  RR RR        TT     UU    UU        SS   |")
 qout("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |")
 qout("|                                                            |")
 qout("|                                               Versao 1.0.0 |")
 qout("| Sistema integrante do projeto Livrus Virtus.               |")
 qout("| Todos os direitos reservados para Henrique F. de Souza.    |")
 qout("| Versao programada na linguagem harbour.                    |")
 qout("*------------------------------------------------------------*")
 for cont:=1 to 4 
   qout()
 next
 qqout(MSG_PRESS)
 inkey(0)
return
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
function frmLogin()
local bret, slinha

  bret:=.f.
  qout("*--------------------------------------------------------------*")
  qout("| Login do sistema                                             |")
  qout("*--------------------------------------------------------------*")
  slinha:=validaEntrada(tfUsuario, opUsuario, 1, tUsuario_login, 3,;
        .f., opTexto)
  if !empty(slinha)
     slinha:=validaEntrada(tfUsuario, opUsuario, 2, tUsuario_senha, 3,;
        .f., opSenha)
     if !empty(slinha)
        tUsuario_login:=alltrim(substr(slinha, 1, 10))
        tUsuario_senha:=alltrim(substr(slinha, 11, 10))
        bret:=.t.
     endif
  endif
  qout()
return(bret)
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*/
function menu(num)

 if (num=1) 
  qout("*--------------------------------------------------------------*")
  qout("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |")
  qout("*--------------------------------------------------------------*")
 elseif (num=2) 
   qout("*---------------------------------*")
   qout("| 01. Cadastro de Assuntos        |")
   qout("| 02. Cadastro de Autores         |")
   qout("| 03. Cadastro de Editoras        |")
   qout("| 04. Cadastro de Endereços       |")
   qout("| 05. Cadastro de Idiomas         |")
   qout("| 06. Cadastro de Países          |")
   qout("| 07. Cadastro de Profissões      |")
   qout("| 08. Cadastro de Clientes        |")
   qout("| 09. Cadastro de Livros          |")
   qout("| 10. Voltar ao menu              |")
   qout("*---------------------------------*")
 elseif (num=3) 
   qout("*---------------------------------*")
   qout("| 01. Consulta de Assuntos        |")
   qout("| 02. Consulta de Autores         |")
   qout("| 03. Consulta de Editoras        |")
   qout("| 04. Consulta de Endereços       |")
   qout("| 05. Consulta de Idiomas         |")
   qout("| 06. Consulta de Países          |")
   qout("| 07. Consulta de Profissões      |")
   qout("| 08. Consulta de Clientes        |")
   qout("| 09. Consulta de Livros          |")
   qout("| 10. Voltar ao menu              |")
   qout("*---------------------------------*")
 elseif (num=4) 
   qout("*---------------------------------*")
   qout("| 01. Vender Livros               |")
   qout("| 02. Vendas Realizadas           |")
   qout("| 03. Voltar ao menu              |")
   qout("*---------------------------------*")
 elseif (num=5) 
   qout("*---------------------------------*")
   qout("| 01. Alterar senha               |")
   qout("| 02. Sobre o sistema             |")
   qout("| 03. Sair do sistema             |")
   qout("| 04. Voltar ao menu              |")
   qout("*---------------------------------*")
 elseif (num=6) 
   qout("*--------------------------------------------------------------*")
   qout("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |")
   qout("*--------------------------------------------------------------*")
 elseif (num=7) 
   qout("*--------------------------------------------------------------*")
   qout("| (1) Salvar inclusão       (2) Voltar ao menu                 |")
   qout("*--------------------------------------------------------------*")
 elseif (num=8) 
   qout("*--------------------------------------------------------------*")
   qout("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |")
   qout("*--------------------------------------------------------------*")
 elseif (num=9) 
   qout("*--------------------------------------------------------------*")
   qout("| (1) Salvar alteração      (2) Voltar ao menu                 |")
   qout("*--------------------------------------------------------------*")
 elseif (num=10) 
   qout("*--------------------------------------------------------------*")
   qout("| Certeza de excluir? (S/N)                                    |")
   qout("*--------------------------------------------------------------*")
 elseif (num=11) 
   qout("*--------------------------------------------------------------*")
   qout("| Deseja sair do sistema? (S/N)                                |")
   qout("*--------------------------------------------------------------*")
 elseif (num=12) 
   qout("*--------------------------------------------------------------*")
   qout("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |")
   qout("*--------------------------------------------------------------*")
 elseif (num=13) 
   qout("*--------------------------------------------------------------*")
   qout("| Deseja continuar? (S/N)                                      |")
   qout("*--------------------------------------------------------------*")
 elseif (num=14) 
   qout("*--------------------------------------------------------------*")
   qout("| Salvar inclusão (S/N)                                        |")
   qout("*--------------------------------------------------------------*")
 endif
return(MSG_OPCAO)
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
procedure frmCadastros(sreg, sacao)
local slinha

if sreg = opAssunto 
   if sacao = opNovo 
      tAssunto_codigo:=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elseif sacao = opPesquisar 
     slinha:=validaEntrada(tfAssunto,sreg,1,tAssunto_codigo,1,.f.,opNumero)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opAutor 
   if sacao = opNovo 
      tAutor_codigo:=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfAutor, sreg, 1, tAutor_codigo,1,.f.,opNumero)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opEditora 
   if sacao = opNovo 
      tEditora_codigo:=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elseif sacao = opPesquisar 
     slinha:=validaEntrada(tfEditora,sreg,1,tEditora_codigo,1,.f.,opNumero)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opEndereco 
   if sacao = opNovo 
      tEnd_codigo:=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfEndereco,sreg,1,tEnd_codigo,1,;
              .f.,opNumero)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opIdioma 
   if sacao = opNovo 
      tIdioma_codigo:=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfIdioma,sreg,1,tIdioma_codigo,1,.f.,opNumero)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opPais 
   if sacao = opNovo 
      accept rotulo(sreg, 1) to tPais_codigo
      slinha:=pesqArq(tfPais, tPais_codigo, 1, 3, tamReg(sreg))
      if empty(slinha)
         pesqLinhaExcluida(tfPais, tamReg(sreg))
         mostrarDados(sreg, "", 1)
         subMenu(7, sreg)
      else 
         qout(MSG_REGEXST)
      endif
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfPais, sreg, 1, tPais_codigo, 1, .f., opTexto)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      qout(rotulo(sreg, 1)+ tPais_codigo)
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opProfissao 
   if sacao = opNovo 
      tProfiss_codigo:=pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfProfissao,sreg,1,tProfiss_codigo,1,;
              .f.,opNumero)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opLivro 
   if sacao = opNovo 
      accept rotulo(sreg, 1) to tLiv_isbn
      if validaISBN(tLiv_isbn) 
          slinha:=pesqArq(tfLivro, tLiv_isbn, 1, 13, tamReg(sreg))
          if empty(slinha)
             pesqLinhaExcluida(tfLivro, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu(7, sreg)
             frmCadLigados(opLivroAss, opNovo, tLiv_isbn)
             frmCadLigados(opLivroAut, opNovo, tLiv_isbn)
          else 
             qout(MSG_REGEXST)
          endif
      else 
        qout(MSG_ISBNINV)
      endif
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfLivro, sreg, 1, tLiv_isbn, 1,.f.,opTexto)
      if !empty(slinha) 
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      qout(rotulo(sreg, 1)+ tLiv_isbn)
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
      frmCadLigados(opLivroAss, opExcluir, tLiv_isbn)
      qout("Assuntos dos livros excluídos, inclua novos!")
      frmCadLigados(opLivroAss, opNovo, tLiv_isbn)
      frmCadLigados(opLivroAut, opExcluir, tLiv_isbn)
      qout("Autores dos livros excluídos, inclua novos!")
      frmCadLigados(opLivroAut, opNovo, tLiv_isbn)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
      qout("Assuntos dos livros sendo excluídos!")
      frmCadLigados(opLivroAss, opExcluir, tLiv_isbn)
      qout("Autores dos livros sendo excluídos!")
      frmCadLigados(opLivroAut, opExcluir, tLiv_isbn)
   endif
elseif sreg = opCliente 
   if sacao = opNovo 
      accept rotulo(sreg, 1) to tCli_cpf
      if validaCPF(tCli_cpf) 
          slinha:=pesqArq(tfCliente, tCli_cpf, 1, 14, tamReg(sreg))
          if empty(slinha)
             pesqLinhaExcluida(tfCliente, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu(7, sreg)
          else 
            qout(MSG_REGEXST)
          endif
      else 
        qout(MSG_CPFINV)
      endif 
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfCliente, sreg, 1, tCli_cpf,1,.f.,opTexto)
      if !empty(slinha) 
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      endif
   elseif sacao = opAlterar 
      qout(rotulo(sreg, 1)+ tCli_cpf)
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao = opExcluir 
      subMenu(10, sreg)
   endif
elseif sreg = opVenda 
   if sacao = opNovo 
      tVenda_dthrvenda:=retDataHora()
      qout(rotulo(sreg, 1)+ tVenda_dthrvenda)
      slinha:=pesqArq(tfVenda, tVenda_dthrvenda, 1, 19, tamReg(sreg))
      if empty(slinha) 
         slinha:=validaEntrada(tfCliente,opCliente,1,tVenda_cpf,3,;
                 .f.,opTexto)
         if !empty(slinha) 
            tVenda_cpf:=alltrim(substr(slinha,1,14))
            if validaCPF(tVenda_cpf) 
               qout(" "+rotulo(opCliente, 2)) /* Nome */
               qqout(substr(slinha, g_nPosChave, g_nTamChave))
               frmCadLigados(opVenda, opNovo, tVenda_cpf)
            else 
               qout(MSG_CPFINV)
            endif
         endif
      else 
         qout(MSG_REGEXST)
      endif
   elseif sacao = opPesquisar 
      slinha:=validaEntrada(tfVenda, sreg, 1, tVenda_dthrvenda,1,;
              .f.,opDataHora)
      if !empty(slinha) 
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      endif
   endif
endif

return
/*------------------------------------------------------------------------------
Realiza as consultas de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
procedure frmConsultas(sreg, sacao)
local slinha

if sreg = opAssunto 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfAssunto,sreg,2,tAssunto_assunto,1,.t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opAutor 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfAutor,sreg, 2, tAutor_autor, 1, .t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opEditora 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfEditora,sreg,2,tEditora_editora,1,.t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opEndereco 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfEndereco,sreg,2,tEnd_Logradouro,1,;
              .t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),;
         3, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opIdioma 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfIdioma, sreg, 2, tIdioma_idioma,1,.t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opPais 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfPais, sreg, 2, tPais_pais, 1, .t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opProfissao 
   if sacao = opPesquisar
     slinha:=validaEntrada(tfProfissao,sreg,2,tProfiss_profissao,1,;
             .t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opLivro 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfLivro, sreg, 2, tLiv_titulo, 1, .t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),;
        1, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opCliente 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfCliente, sreg, 2, tCli_nome,1,.t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),;
        1, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
elseif sreg = opVenda 
   if sacao = opPesquisar
      slinha:=validaEntrada(tfVenda, sreg, 2, tVenda_cpf, 1, .t.,opTexto)
   elseif sacao = opListarTodos 
      if ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),;
        QTD_MAX_LINHA, .f.) = .f.
        qout(rotulo(sreg, 0))
      endif
   endif
endif
if empty(slinha)
   qqout("")
endif
return
/*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*/
procedure frmAlterarSenha()
local bQuebra, sres, sSenhaAtual, sNovaSenha, sConfirmaSenha, nopcao

qout(rotulo(opUsuario, 1)+ tUsuario_login)
nopcao:=1
bQuebra:=.f.
do while (bQuebra=.f.)
  do case
   case nopcao = 1 
       sSenhaAtual:=digitaSenha("Senha Atual: ",10)
       if sSenhaAtual<>tUsuario_senha 
          qout(MSG_SENCONFERE)
          bQuebra:=.t.
       else 
          nopcao:=2
       endif
   case nopcao = 2
       sNovaSenha:=digitaSenha("Nova Senha: ",10)
       sConfirmaSenha:=digitaSenha("Confirma Senha: ",10)
       if sNovaSenha<>sConfirmaSenha 
          qout(MSG_SENCONFIRM)
          bQuebra:=.t.
       else 
          nopcao:=3
       endif
   case nopcao = 3
       sres:=pesqArq(tfUsuario, tUsuario_login, 1, 10, tamReg(opUsuario))
       if empty(sres)
         qout(MSG_LOGINENCON)
       else 
         tUsuario_senha:=sConfirmaSenha
         subMenu(9,opUsuario)
         bQuebra:=.t.
       endif
  endcase
enddo

return
/*------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
procedure btnAcao(sreg, sacao)

if sreg = opAssunto 
   if sacao = opSalvarInclusao
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfAssunto, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opAutor 
   if sacao = opSalvarInclusao
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfAutor, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opEditora 
   if sacao = opSalvarInclusao
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfEditora, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opEndereco 
   if sacao = opSalvarInclusao
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfEndereco, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opIdioma 
   if sacao = opSalvarInclusao
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfIdioma, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opPais 
   if sacao = opSalvarInclusao
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfPais, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opProfissao 
   if sacao = opSalvarInclusao
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfProfissao, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opLivro 
   if sacao = opSalvarInclusao
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfLivro, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opLivroAss 
   if sacao = opSalvarInclusao
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfLivroAss, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opLivroAut 
   if sacao = opSalvarInclusao
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfLivroAut, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opCliente 
   if sacao = opSalvarInclusao
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfCliente, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opVenda 
   if sacao = opSalvarInclusao
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao = opSalvarAlteracao
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao = opConfirmaExclusao
      escreveArq(tfVenda, replicate("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   endif
elseif sreg = opUsuario 
   if sacao = opSalvarAlteracao
      escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   endif
endif
return
/*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
procedure subMenu(nmenu, sreg)
local opSubMenu, opCSubMenu, bSOp

bSOp:=.t.
do case
 case nmenu = 6
    do while(bSOp)    
     accept menu(nmenu) to opSubMenu
     do case
        case opSubMenu = "1" 
          frmCadastros(sreg, opNovo)
        case opSubMenu = "2" 
          frmCadastros(sreg, opPesquisar)
        case opSubMenu = "3" 
          bSOp:=.f.
        otherwise 
          qout(MSG_ERRO)
     endcase
    enddo
 case nmenu = 7
    do while(bSOp)    
     accept menu(nmenu) to opSubMenu
     do case
        case opSubMenu = "1"  
          btnAcao(sreg, opSalvarInclusao) 
          bSOp:=.f.
        case opSubMenu = "2"
          bSOp:=.f.
        otherwise
          qout(MSG_ERRO)
     endcase
    enddo
 case nmenu = 8
    do while(bSOp)    
     accept menu(nmenu) to opSubMenu
     do case
        case opSubMenu = "1"  
          frmCadastros(sreg, opAlterar) 
          bSOp:=.f.
        case opSubMenu = "2" 
          frmCadastros(sreg, opExcluir) 
          bSOp:=.f.
        case opSubMenu = "3" 
          bSOp:=.f.
        otherwise 
          qout(MSG_ERRO)
     endcase
    enddo
 case nmenu = 9
    do while(bSOp)    
     accept menu(nmenu) to opSubMenu
     do case
        case opSubMenu = "1"  
          btnAcao(sreg, opSalvarAlteracao) 
          bSOp:=.f.
        case opSubMenu = "2" 
          bSOp:=.f.
        otherwise 
          qout(MSG_ERRO)
     endcase
    enddo
 case nmenu = 10
    do while(bSOp)      
       accept menu(nmenu) to opCSubMenu
       if (opCSubMenu="S") .or. (opCSubMenu="s") 
          btnAcao(sreg, opConfirmaExclusao)
          bSOp:=.f.
       elseif (opCSubMenu="N") .or. (opCSubMenu="n") 
          bSOp:=.f.
       else 
          qout(MSG_ERRO)
       endif
    enddo
 case nmenu = 12
    do while(bSOp)    
     accept menu(nmenu) to opSubMenu
     do case
        case opSubMenu = "1" 
          frmConsultas(sreg, opPesquisar)
        case opSubMenu = "2"
          frmConsultas(sreg, opListarTodos)
        case opSubMenu = "3" 
          bSOp:=.f.
        otherwise 
          qout(MSG_ERRO)
     endcase
    enddo
 case nmenu = 14
    do while(bSOp)    
     accept menu(nmenu) to opCSubMenu
     if (opCSubMenu="S") .or. (opCSubMenu="s") 
        btnAcao(sreg, opSalvarInclusao)
        bSOp:=.f.
        g_SalvarInclusao:=.t.
     elseif (opCSubMenu="N") .or. (opCSubMenu="n") 
       bSOp:=.f.
     else 
       qout(MSG_ERRO)
     endif 
    enddo
endcase

return
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*/
procedure usaMenu(num)
local opSubMenu, bSOp, opSair

 bSOp:=.t.
 if num = 1  /* Cadastros */
   do while(bSOp)    
     accept menu(2) to opSubMenu
     do case
      case opSubMenu == "1" 
        subMenu(6, opAssunto)
      case opSubMenu == "2" 
        subMenu(6, opAutor)
      case opSubMenu == "3" 
        subMenu(6, opEditora)
      case opSubMenu == "4" 
        subMenu(6, opEndereco)
      case opSubMenu == "5" 
        subMenu(6, opIdioma)
      case opSubMenu == "6" 
        subMenu(6, opPais)
      case opSubMenu == "7" 
        subMenu(6, opProfissao)
      case opSubMenu == "8" 
        subMenu(6, opCliente)
      case opSubMenu == "9" 
        subMenu(6, opLivro)
      case opSubMenu == "10" 
        bSOp:=.f.
      otherwise 
        qout(MSG_ERRO)
     endcase
   enddo
 elseif num = 2  /* Pesquisas */
   do while(bSOp)    
     accept menu(3) to opSubMenu
     do case
      case opSubMenu == "1" 
        subMenu(12, opAssunto)
      case opSubMenu == "2" 
        subMenu(12, opAutor)
      case opSubMenu == "3" 
        subMenu(12, opEditora)
      case opSubMenu == "4" 
        subMenu(12, opEndereco)
      case opSubMenu == "5" 
        subMenu(12, opIdioma)
      case opSubMenu == "6" 
        subMenu(12, opPais)
      case opSubMenu == "7" 
        subMenu(12, opProfissao)
      case opSubMenu == "8" 
        subMenu(12, opCliente)
      case opSubMenu == "9" 
        subMenu(12, opLivro)
      case opSubMenu == "10" 
        bSOp:=.f.
      otherwise 
        qout(MSG_ERRO)
     endcase
   enddo
 elseif num = 3  /* Vendas */
   do while(bSOp)    
     accept menu(4) to opSubMenu
     do case
      case opSubMenu == "1" 
        subMenu(6, opVenda)
      case opSubMenu == "2" 
        subMenu(12, opVenda)
      case opSubMenu == "3"
        bSOp:=.f.
      otherwise
        qout(MSG_ERRO)
     endcase
   enddo
 elseif num = 4  /* Opcoes */
   do while(bSOp)    
     accept menu(5) to opSubMenu
     do case
      case opSubMenu == "1"
        frmAlterarSenha()
      case opSubMenu == "2"
        frmSobre()
      case opSubMenu == "3"          
           accept menu(11) to opSair
           if (opSair="S") .or. (opSair="s") 
              fechaArqs()
              quit
           endif
      case opSubMenu == "4"
        bSOp:=.f.
      otherwise 
        qout(MSG_ERRO)
     endcase
   enddo
 endif
return
/*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*/
procedure mostrarDados(sreg, slinha, nOpcao)

if sreg = opAssunto 
   do case
    case nOpcao = 1
        qout(rotulo(sreg, 1)+ tAssunto_codigo)
        accept rotulo(sreg, 2) to tAssunto_assunto
    case nOpcao = 2
        qout("Código     Assunto")
        qout("------     -------")
    case nOpcao = 3
        tAssunto_codigo:=substr(slinha, 1, 10)
        tAssunto_assunto:=substr(slinha, 11, 30)
        qout(tAssunto_codigo+" "+tAssunto_assunto)
   endcase
elseif sreg = opAutor 
   do case
    case nOpcao = 1 
        qout(rotulo(sreg, 1)+ tAutor_codigo)
        accept rotulo(sreg, 2) to tAutor_autor
    case nOpcao = 2
        qout("Código     Autor")
        qout("------     -----")
    case nOpcao = 3
        tAutor_codigo:=substr(slinha, 1, 10)
        tAutor_autor:=substr(slinha, 11, 30)
        qout(tAutor_codigo+" "+tAutor_autor)
   endcase
elseif sreg = opEditora 
   do case
    case nOpcao = 1 
        qout(rotulo(sreg, 1)+ tEditora_codigo)
        accept rotulo(sreg, 2) to tEditora_editora
    case nOpcao = 2 
        qout("Código     Editora")
        qout("------     -------")
    case nOpcao = 3 
        tEditora_codigo:=substr(slinha, 1, 10)
        tEditora_editora:=substr(slinha, 11, 50)
        qout(tEditora_codigo+" "+tEditora_editora)     
   endcase
elseif sreg = opEndereco 
   do case
    case nOpcao = 1 
        qout(rotulo(sreg, 1)+ tEnd_codigo)
        accept rotulo(sreg, 2) to tEnd_Logradouro
        accept rotulo(sreg, 3) to tEnd_bairro
        input rotulo(sreg, 4) to tEnd_cep
        accept rotulo(sreg, 5) to tEnd_cidade
        accept rotulo(sreg, 6) to tEnd_estado
    case nOpcao = 3 
        tEnd_codigo:=alltrim(substr(slinha, 1, 10))
        tEnd_logradouro:=alltrim(substr(slinha, 11, 40))
        tEnd_bairro:=alltrim(substr(slinha, 51, 15))
        tEnd_cep:=alltrim(substr(slinha, 66, 8))
        tEnd_cidade:=alltrim(substr(slinha, 74, 30))
        tEnd_estado:=alltrim(substr(slinha, 104, 20))
        qout("--------------------")
        qout(rotulo(sreg, 1)+ tEnd_codigo)
        qout(rotulo(sreg, 2)+ tEnd_Logradouro)
        qout(rotulo(sreg, 3)+ tEnd_bairro)
        qout(rotulo(sreg, 4)+ tEnd_cep)
        qout(rotulo(sreg, 5)+ tEnd_cidade)
        qout(rotulo(sreg, 6)+ tEnd_estado)
   endcase
elseif sreg = opIdioma 
   do case
    case nOpcao = 1 
        qout(rotulo(sreg, 1)+ tIdioma_codigo)
        accept rotulo(sreg, 2) to tIdioma_idioma
    case nOpcao = 2 
        qout("Código     Idioma")
        qout("------     ------")
    case nOpcao = 3
        tIdioma_codigo:=substr(slinha, 1, 10)
        tIdioma_idioma:=substr(slinha, 11, 20)
        qout(tIdioma_codigo+" "+tIdioma_idioma)
   endcase
elseif sreg = opPais 
   do case
    case nOpcao = 1 
        accept rotulo(sreg, 2) to tPais_pais
    case nOpcao = 2 
        qout("Código País")
        qout("------ ----")
    case nOpcao = 3 
        tPais_codigo:=substr(slinha, 1, 3)
        tPais_pais:=substr(slinha, 4, 50)
        qout(tPais_codigo+"    "+tPais_pais)
   endcase
elseif sreg = opProfissao 
   do case
    case nOpcao = 1 
        qout(rotulo(sreg, 1)+ tProfiss_codigo)
        accept rotulo(sreg, 2) to tProfiss_profissao
    case nOpcao = 2 
        qout("Código     Profissão")
        qout("------     ---------")
    case nOpcao = 3 
        tProfiss_codigo:=substr(slinha, 1, 10)
        tProfiss_profissao:=substr(slinha, 11, 50)
        qout(tProfiss_codigo+" "+tProfiss_profissao)
   endcase
elseif sreg = opLivro 
   do case
    case nOpcao = 1 
        accept rotulo(sreg, 2) to tLiv_titulo
        tLiv_edicao:=validaNumero(rotulo(sreg, 3), tLiv_edicao)
        tLiv_anopubli:=validaNumero(rotulo(sreg, 4), tLiv_anopubli)
        mostrarSubDados(opLivro, opEditora, .f.)
        tLiv_volume:=validaNumero(rotulo(sreg, 6), tLiv_volume)
        mostrarSubDados(opLivro, opIdioma, .f.)
        tLiv_npaginas:=validaNumero(rotulo(sreg, 8), tLiv_npaginas)
        tLiv_preco:=validaNumero(rotulo(sreg, 9), tLiv_preco)
        tLiv_qtdestoque:=validaNumero(rotulo(sreg, 10), tLiv_qtdestoque)
    case nOpcao = 3 
        tLiv_isbn:=alltrim(substr(slinha, 1, 13))
        tLiv_titulo:=alltrim(substr(slinha, 14, 50))
        tLiv_edicao:=alltrim(substr(slinha, 64, 10))
        tLiv_anopubli:=alltrim(substr(slinha, 74, 10))
        tLiv_codeditora:=alltrim(substr(slinha, 84, 10))
        tLiv_volume:=alltrim(substr(slinha, 94, 10))
        tLiv_codidioma:=alltrim(substr(slinha, 104, 10))
        tLiv_npaginas:=alltrim(substr(slinha, 114, 10))
        tLiv_preco:=alltrim(substr(slinha, 124, 10))
        tLiv_qtdestoque:=alltrim(substr(slinha, 134, 10))
        qout("--------------------")
        qout(rotulo(sreg, 1)+ tLiv_isbn)
        qout(rotulo(sreg, 2)+ tLiv_titulo)
        qout(rotulo(sreg, 3)+ tLiv_edicao)
        qout(rotulo(sreg, 4)+ tLiv_anopubli)
        qout(rotulo(sreg, 5)+ tLiv_codeditora)
        mostrarSubDados(opLivro, opEditora, .t.)
        qout(rotulo(sreg, 6)+ tLiv_volume)
        qout(rotulo(sreg, 7)+ tLiv_codidioma)
        mostrarSubDados(opLivro, opIdioma, .t.)
        qout(rotulo(sreg, 8)+ tLiv_npaginas)
        qout(rotulo(sreg, 9)+ tLiv_preco)
        qout(rotulo(sreg, 10)+ tLiv_qtdestoque)
        ListarRegLigados(tfLivroAss, opLivroAss, 1, 13, 14, 10, tLiv_isbn,;
                         tfAssunto, opAssunto, 1, 4)
        ListarRegLigados(tfLivroAut, opLivroAut, 1, 13, 14, 10, tLiv_isbn,;
                         tfAutor, opAutor, 1, 4)
   endcase
elseif sreg = opCliente 
   do case
    case nOpcao = 1 
        accept rotulo(sreg, 2) to tCli_nome
        accept rotulo(sreg, 3) to tCli_email 
        accept rotulo(sreg, 4) to tCli_identidade
        accept rotulo(sreg, 5) to tCli_sexo
        accept rotulo(sreg, 6) to tCli_telefone
        tCli_dtnascimento:=;
                validaDataHora(rotulo(sreg, 7), tCli_dtnascimento, .t.)
        mostrarSubDados(opCliente, opEndereco, .f.)
        mostrarSubDados(opCliente, opPais, .f.)
        mostrarSubDados(opCliente, opProfissao, .f.)
    case nOpcao = 3 
        tCli_cpf:=alltrim(substr(slinha, 1, 14))
        tCli_nome:=alltrim(substr(slinha, 15, 30))
        tCli_email:=alltrim(substr(slinha, 45, 30))
        tCli_identidade:=alltrim(substr(slinha, 75, 10))
        tCli_sexo:=alltrim(substr(slinha, 85, 1))
        tCli_telefone:=alltrim(substr(slinha, 86, 17))
        tCli_dtnascimento:=alltrim(substr(slinha, 103, 10))
        tCli_codendereco:=alltrim(substr(slinha, 113, 10))
        tCli_codpais:=alltrim(substr(slinha, 123, 3))
        tCli_codprofissao:=alltrim(substr(slinha, 126, 10))
        qout("--------------------")
        qout(rotulo(sreg, 1)+ tCli_cpf)
        qout(rotulo(sreg, 2)+ tCli_nome)
        qout(rotulo(sreg, 3)+ tCli_email)
        qout(rotulo(sreg, 4)+ tCli_identidade)
        qout(rotulo(sreg, 5)+ tCli_sexo)
        qout(rotulo(sreg, 6)+ tCli_telefone)
        qout(rotulo(sreg, 7)+ tCli_dtnascimento)
        qout(rotulo(sreg, 8)+ tCli_codendereco)
        mostrarSubDados(opCliente, opEndereco, .t.)
        qout(rotulo(sreg, 9)+ tCli_codpais)
        mostrarSubDados(opCliente, opPais, .t.)
        qout(rotulo(sreg, 10)+ tCli_codprofissao)
        mostrarSubDados(opCliente, opProfissao, .t.)
   endcase
elseif sreg = opVenda 
   do case
    case nOpcao = 1
        mostrarSubDados(opVenda,opVenda, .f.)
    case nOpcao = 2
        qout("DataHoraVenda       CPF            ISBN          "+;
        "PreçoVenda")
        qout("-------------       ---            ----          "+;
        "----------")
    case nOpcao = 3 
        tVenda_dthrvenda:=substr(slinha, 1, 19)
        tVenda_cpf:=substr(slinha, 20, 14)
        tVenda_isbn:=substr(slinha, 34, 13)
        tVenda_precovenda:=substr(slinha, 47, 10)
        qout(tVenda_dthrvenda+" "+tVenda_cpf+" "+tVenda_isbn+" "+;
        tVenda_precovenda)
   endcase
endif

return
/*------------------------------------------------------------------------------
Mostra as sub informções de entrada e de saída.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai só mostrar na saída 
------------------------------------------------------------------------------*/
procedure mostrarSubDados(sreg, ssubreg, bSoMostrar)
local sRegistro, sPreco, nStatus, nMaxTentativas

nMaxTentativas:=3
if sreg = opLivro 
  if ssubreg = opEditora
    if bSoMostrar
       sRegistro:=pesqArq(tfEditora,tLiv_codeditora,1,10,tamReg(opEditora))
    else
       sRegistro:=validaEntrada(tfEditora,ssubreg,1,tLiv_codeditora,;
                  nMaxTentativas,.f.,opNumero)
    endif
    if !empty(sRegistro) 
      tLiv_codeditora:=alltrim(substr(sRegistro,1,10))
      qout(" "+rotulo(opEditora, 2))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
    endif
  elseif ssubreg = opIdioma
    if bSoMostrar
       sRegistro:=pesqArq(tfIdioma, tLiv_codidioma, 1, 10,tamReg(opIdioma))
    else
       sRegistro:=validaEntrada(tfIdioma,ssubreg,1,tLiv_codidioma,;
                  nMaxTentativas,.f.,opNumero)
    endif
    if !empty(sRegistro) 
      tLiv_codidioma:=alltrim(substr(sRegistro,1,10))
      qout(" "+rotulo(opIdioma, 2))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
    endif
  endif
elseif sreg = opCliente 
  if ssubreg = opEndereco
    if bSoMostrar
       sRegistro:=pesqArq(tfEndereco, tCli_codendereco, 1, 10,;
                  tamReg(opEndereco))
    else
       sRegistro:=validaEntrada(tfEndereco,ssubreg,1,tCli_codendereco,;
                  nMaxTentativas,.f.,opNumero)
    endif
    if !empty(sRegistro) 
      tCli_codendereco:=alltrim(substr(sRegistro,1,10))
      qout(" "+rotulo(opEndereco, 2))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
      qout(" "+rotulo(opEndereco, 3))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
      qout(" "+rotulo(opEndereco, 4))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
      qout(" "+rotulo(opEndereco, 5))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
      qout(" "+rotulo(opEndereco, 6))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
    endif
  elseif ssubreg = opPais
    if bSoMostrar
       sRegistro:=pesqArq(tfPais, tCli_codpais, 1, 3, tamReg(opPais))
    else
       sRegistro:=validaEntrada(tfPais,ssubreg,1,tCli_codpais,;
                  nMaxTentativas,.f.,opTexto)
    endif
    if !empty(sRegistro) 
      tCli_codpais:=alltrim(substr(sRegistro,1,3))
      qout(" "+rotulo(opPais, 2))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
    endif
  elseif ssubreg = opProfissao
    if bSoMostrar
       sRegistro:=pesqArq(tfProfissao, tCli_codprofissao, 1, 10,;
                  tamReg(opProfissao))
    else
       sRegistro:=validaEntrada(tfProfissao,ssubreg,1,tCli_codprofissao,;
                  nMaxTentativas,.f.,opNumero)
    endif
    if !empty(sRegistro) 
      tCli_codprofissao:=alltrim(substr(sRegistro,1,10))
      qout(" "+rotulo(opProfissao, 2))
      qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
    endif
  endif
elseif sreg = opVenda 
  sRegistro:=pesqArq(tfLivro, tVenda_isbn, 1, 13, tamReg(opLivro))
  if !empty(sRegistro) 
    qout(" "+rotulo(opLivro, 2)) /* Titulo */
    qqout(substr(sRegistro, g_nPosChave, g_nTamChave))
    qout(" "+rotulo(opLivro, 9)) /* Preco */
    sPreco:=substr(sRegistro, g_nPosChave, g_nTamChave)
    g_nPreco:=val(sPreco)
    qqout(sPreco)
  endif
endif
return
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*/
procedure frmCadLigados(sreg, sacao, sCodigo)
local nQtd, nCont, nQtdEstoque, nStatus
local nTotalPreco, slinha, sTotalPreco, sPreco, sQtd

if sacao = opNovo 
  nCont:=1
  if sreg = opLivroAss 
    sQtd:=validaNumero("Quantos assuntos quer cadastrar?: ", sQtd)
    nQtd:=Val(sQtd)
    fseek(tfLivroAss, 0, FS_SET)
    do while nCont <= nQtd
      tLivAss_isbn:=sCodigo
      accept rotulo(opLivroAss, 2) to tLivAss_codassunto
      slinha:=pesqArq(tfAssunto, tLivAss_codassunto,1,10,tamReg(opAssunto))
      qqout(" "+rotulo(opAssunto, 2))
      qout(substr(slinha, g_nPosChave, g_nTamChave))
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg))
      subMenu(14, sreg)
      nCont++
    enddo
  elseif sreg = opLivroAut 
    sQtd:=validaNumero("Quantos autores quer cadastrar?: ",sQtd)
    nQtd:=Val(sQtd)
    fseek(tfLivroAut, 0, FS_SET)
    do while nCont <= nQtd
      tLivAut_isbn:=sCodigo
      accept rotulo(opLivroAut, 2) to tLivAut_codautor
      slinha:=pesqArq(tfAutor, tLivAut_codautor,1,10,tamReg(opAutor))
      qqout(" "+rotulo(opAutor, 2))
      qout(substr(slinha, g_nPosChave, g_nTamChave))
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg))
      subMenu(14, sreg)
      nCont++
    enddo
  elseif sreg = opVenda 
    sQtd:=validaNumero("Quantos livros quer vender?: ",sQtd)
    nQtd:=Val(sQtd)
    nTotalPreco:=0
    do while nCont <= nQtd
      slinha:=validaEntrada(tfLivro,opLivro,1,tVenda_isbn,3,.f.,opTexto)
      if !empty(slinha) 
        tVenda_isbn:=alltrim(substr(slinha,1,13))
        if validaISBN(tVenda_isbn) 
          mostrarDados(sreg, "", 1)
          tLiv_qtdestoque:=alltrim(substr(slinha,134,10))
          nQtdEstoque:=val(tLiv_qtdestoque)
          if nQtdEstoque > 0 
             nTotalPreco:=nTotalPreco + g_nPreco
             sPreco:=alltrim(str(g_nPreco,7,2))
             tVenda_precovenda:=sPreco
             g_SalvarInclusao:=.f.
             subMenu(14, sreg)
             if g_SalvarInclusao 
                slinha:=pesqArq(tfLivro, tVenda_isbn, 1, 13, tamReg(opLivro))
                if !empty(slinha) 
                   nQtdEstoque:=nQtdEstoque-1
                   tLiv_qtdestoque:=alltrim(str(nQtdEstoque))
                   slinha:=substr(slinha,1,133)+esp(tLiv_qtdestoque,10)
                   escreveArq(tfLivro, slinha, "", "")
                endif
             endif
             nCont++
          else 
            qout(MSG_SEMESTOQUE)
          endif
        else 
          qout(MSG_ISBNINV)
        endif    
      endif
    enddo
    sTotalPreco:=alltrim(str(nTotalPreco,7,2))
    qout("Total de "+rotulo(sreg,4)+sTotalPreco)
  endif
elseif sacao = opExcluir 
  if sreg = opLivroAss 
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo)
  elseif sreg = opLivroAut 
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo)
  endif
endif

return
/*------------------------------------------------------------------------------
Realiza a exclusão dos arquivos de ligação.
sArq - o arquivo de ligação
sreg - o tipo de arquivo de ligação
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------*/
procedure ExcluirRegLigados(sArq, sreg, nPosChave, nTamChave, sChave)
local slinha, sCodigo, nStatus, nler

  nler := tamReg(sreg) + TAM_CRLF
  slinha:=space(nler)
  fseek(sArq, 0, FS_SET)
  do while !fimArq(sArq)
    fread(sArq, @slinha, nler)
    sCodigo:=alltrim(substr(slinha,nPosChave,nTamChave))
    if sCodigo==sChave
       btnAcao(sreg,opConfirmaExclusao)
    endif
  enddo
return
