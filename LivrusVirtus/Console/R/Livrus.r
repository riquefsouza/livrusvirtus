#------------------------------------------------------------------------------
# Sistema integrante do projeto Livrus Virtus.
# Todos os direitos reservados para Henrique F. de Souza.
# Versão programada na linguagem R.
#------------------------------------------------------------------------------
# programa Livrus

tAssunto <- list(codigo="", assunto="")
tAutor <- list(codigo="", autor="")
tEditora <- list(codigo="", editora="")
tIdioma <- list(codigo="", idioma="")
tUsuario <- list(login="", senha="")
tPais <- list(codigo="", pais="")
tProfissao <- list(codigo="", profissao="")
tLivro <- list(isbn="", titulo="", edicao="", anopubli="", codeditora="",
   volume="", codidioma="", npaginas="", preco="", qtdestoque="")
tLivroAss <- list(isbn="", codassunto="")
tLivroAut <- list(isbn="", codautor="")
tCliente <- list(cpf="", nome="", email="", identidade="", sexo="",
   telefone="", dtnascimento="", codendereco="", codpais="", codprofissao="")
tEndereco <- list(codigo="", logradouro="", bairro="", cep="",
   cidade="", estado="")
tVenda <- list(dthrvenda="",   # data/hora da venda dd/mm/yyyy hh:mm:ss
   cpf="", isbn="", precovenda="")

# ctTipo 
opTexto = 1; opNumero = 2; opData = 3; opDataHora = 4; opSenha = 5
# ctArqs 
opAssunto = 1; opAutor = 2; opEditora = 3; opEndereco = 4; opIdioma = 5; 
opPais = 6; opProfissao = 7; opCliente = 8; opLivro = 9; opLivroAss = 10; 
opLivroAut = 11; opUsuario = 12; opVenda = 13 
# ctAcao
opNovo = 1; opAlterar = 2; opPesquisar = 3; opSalvarInclusao = 4; 
opSalvarAlteracao = 5; opExcluir = 6; opConfirmaExclusao = 7; opListarTodos = 8

# Constantes
CRLF = "\n" # windows
TAM_CRLF = 2
# CRLF = "\n"
# TAM_CRLF = 1 # unix 
# CRLF = "\n"
# TAM_CRLF = 1 # macintosh 

ARQ_ABRE = "r+"
ARQ_CRIA = "w+"

QTD_MAX_LINHA = 18

MSG_ARQERRO = "Erro: O arquivo não pode ser aberto.\n"
MSG_ARQCERRO = "Erro: O arquivo não pode ser criado.\n"
MSG_ERRO = "Erro: opção inválida digite de novo\n"
MSG_OPCAO = "Escolha uma opção: "
MSG_PRESS = "pressione para continuar..."

MSG_REGINC = "registro incluido!\n"
MSG_REGNINC = "registro não incluido!\n"
MSG_REGALT = "registro alterado!\n"
MSG_REGNALT = "registro não alterado!\n"
MSG_REGEXC = "registro excluido!\n"
MSG_REGNEXC = "registro não excluido!\n"
MSG_REGEXST = "registro já existe!\n"

MSG_NUMINV = "Número inválido ou menor do que 1!\n"
MSG_DATAINV = "Data inválida!, formato correto (dd/mm/yyyy)\n"
MSG_DTHRINV = "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)\n"
MSG_ISBNINV = "ISBN inválido!\n"
MSG_CPFINV = "CPF inválido!\n"
MSG_SENCONFERE = "senha não confere com a senha atual!\n"
MSG_SENCONFIRM = "nova senha não confere com a senha confirmada!\n"
MSG_LOGINENCON = "login não encontrado!\n"
MSG_SEMESTOQUE = "livro não existe no estoque!\n"

ARQ_ASSUNTO = "c:\\temp\\assunto.dat"
ARQ_AUTOR = "c:\\temp\\autor.dat"
ARQ_EDITORA = "c:\\temp\\editora.dat"
ARQ_IDIOMA = "c:\\temp\\idioma.dat"
ARQ_USUARIO = "c:\\temp\\usuario.dat"
ARQ_PAIS = "c:\\temp\\pais.dat"
ARQ_PROFISSAO = "c:\\temp\\profissao.dat"
ARQ_LIVRO = "c:\\temp\\livro.dat"
ARQ_LIVASS = "c:\\temp\\livroass.dat"
ARQ_LIVAUT = "c:\\temp\\livroaut.dat"
ARQ_CLIENTE = "c:\\temp\\cliente.dat"
ARQ_ENDERECO = "c:\\temp\\endereco.dat"
ARQ_VENDA = "c:\\temp\\venda.dat"

TAM_ASSUNTO = 40
TAM_AUTOR = 40
TAM_EDITORA = 60
TAM_IDIOMA = 30
TAM_USUARIO = 20
TAM_PAIS = 53
TAM_PROFISSAO = 60
TAM_LIVRO = 143
TAM_LIVASS = 23
TAM_LIVAUT = 23
TAM_CLIENTE = 135
TAM_ENDERECO = 123
TAM_VENDA = 56

# variaveis
bopcao = FALSE
opmenu = ""
g_nPosChave = 0; g_nTamChave = 0; g_nPosicao = 0
g_nPreco = 0.0
g_SalvarInclusao = FALSE

tfAssunto = file(ARQ_ASSUNTO)
tfAutor = file(ARQ_AUTOR)
tfEditora = file(ARQ_EDITORA)
tfIdioma = file(ARQ_IDIOMA)
tfEndereco = file(ARQ_ENDERECO)
tfPais = file(ARQ_PAIS)
tfProfissao = file(ARQ_PROFISSAO)
tfLivro = file(ARQ_LIVRO)
tfLivroAss = file(ARQ_LIVASS)
tfLivroAut = file(ARQ_LIVAUT)
tfCliente = file(ARQ_CLIENTE)
tfUsuario = file(ARQ_USUARIO)
tfVenda = file(ARQ_VENDA)

#------------------------------------------------------------------------------
# Atribui uma variavel ao ambiente global.
# variavel - a variavel a ser atribuida
# valor - o valor da variavel global
#------------------------------------------------------------------------------
ag <- function(variavel,valor) {
  assign(variavel, valor, env=globalenv())
}
#------------------------------------------------------------------------------
# pega o valor de uma variavel do ambiente global.
# variavel - a variavel a ser pego o valor
# retorna - o valor da variavel global
#------------------------------------------------------------------------------
gg <- function(variavel) {
 gg = get(variavel, env=globalenv())
}
#------------------------------------------------------------------------------
# Retira os espaços em branco antes ou depois do texto.
# sTexto - o texto a ser retirado os espaços em branco
# retorna - o texto sem os espaços em branco
#------------------------------------------------------------------------------
trim <- function(sTexto) {
trim = sub(' +$', '', sTexto)
}

#------------------------------------------------------------------------------
# Repete um texto um número determinado de vezes.
# sTexto - o texto a ser repetido
# nQtd - a quantidade de vezes
# retorna - o texto repetido
#------------------------------------------------------------------------------
repete <- function(sTexto, nQtd) {
ncont = 0
sret=""
for (ncont in 1:nQtd) {
  sret=paste(sret,sTexto, sep = "")
}
repete = sret
}
#------------------------------------------------------------------------------
# Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
# sTexto - o texto
# nTam - tamanho máximo do texto
# retorna - o texto com espaços em branco a mais
#------------------------------------------------------------------------------
esp <- function(sTexto, nTam) {
 esp = paste(sTexto,repete(" ",nTam-nchar(sTexto)), sep="")
}
#------------------------------------------------------------------------------
# Faz uma pesquisa relativa de um texto através de um valor chave.
# sTexto - o texto
# sChave - a chave a ser pesquisada
# retorna - se achou ou não a chave dentro do texto
#------------------------------------------------------------------------------
strRelativa <- function(sTexto, sChave) {
  if (length(grep(sChave, sTexto, ignore.case = TRUE)) > 0)
    strRelativa = TRUE
  else 
    strRelativa = FALSE
}
#------------------------------------------------------------------------------
# Função que retorna um pedaço de uma string.
# str - indica a string
# nini - indica a posicao inicial do pedaco
# ntam - indica o tamanho do pedaco
# retorna - o pedaço da string
#------------------------------------------------------------------------------
copy <- function(str, nini, ntam) {
  copy = substr(str,nini,ntam+nini-1) 
}
#------------------------------------------------------------------------------
# Calcula o modulo11 de um valor qualquer.
# svalor - a mstring com o número a ser calculado
# ndig - dígito do valor a ser calculado
# retorna - o dígito correto
#------------------------------------------------------------------------------
modulo11 <- function(svalor, ndig) {
 ncont = 1
 slocal = ""
 while (ncont <= 11) {
   slocal = paste(copy(svalor,ncont,1), slocal, sep="")
   ncont = ncont + 1
 }
 nsoma=0
 if (ndig == 1)
   ncont = 3
 else
   ncont = 2
 npos = 2
 while (ncont <= 11) {
   sres=copy(slocal,ncont,1)
   nvalor = as.integer(sres)
   nsoma=nsoma + (nvalor * npos)
   ncont=ncont+1
   npos=npos+1
 }
 nsoma=(11 - (nsoma %% 11))

if (nsoma > 9)
  modulo11 = 0
else
  modulo11 = nsoma
}
#------------------------------------------------------------------------------
# Validação de um número de CPF qualquer.
# cpf - a mstring com o número do CPF
# retorna - se é valido ou não
#------------------------------------------------------------------------------
validaCPF <- function(cpf) {
  if (nchar(cpf)==14) {
    scpf=paste(copy(cpf,1,3),copy(cpf,5,3),copy(cpf,9,3),
               copy(cpf,13,2), sep="")
    sres=copy(cpf,13,1)
    nvalor1 = as.integer(sres)
    sres=copy(cpf,14,1)
    nvalor2 = as.integer(sres)
    if ((modulo11(scpf,1)==nvalor1) && (modulo11(scpf,2)==nvalor2)) 
      validaCPF = TRUE
    else
      validaCPF = FALSE
  } else
    validaCPF = FALSE
}
#------------------------------------------------------------------------------
# Validação de um número ISBN qualquer.
# isbn - a mstring com o número do ISBN
# retorna - se é valido ou não
#------------------------------------------------------------------------------
validaISBN <- function(isbn) {
  if (nchar(isbn)==13) {
    sdigito = copy(isbn, nchar(isbn), 1)
    sisbn = ""
    for (ncont in 1:(nchar(isbn)-1)) {
      if (copy(isbn,ncont,1)!="-")
        sisbn = paste(sisbn, copy(isbn,ncont,1), sep="")
    }
    if (sdigito == "X")
      nsoma = 10
    else {
      nvalor = as.integer(sdigito)
      nsoma = nvalor
    }
    for(ncont in 1:9) {
      snum=copy(sisbn, ncont, 1)
      nvalor = as.integer(snum)
      nsoma=nsoma + (nvalor * (11 - ncont))
    }
    if ((nsoma %% 11) == 0)
      validaISBN=TRUE
    else
      validaISBN=FALSE
  } else
    validaISBN=FALSE
}
#------------------------------------------------------------------------------
# Esconde a digitação da senha
# retorna - a senha digitada
#------------------------------------------------------------------------------
digitaSenha <- function(sRotulo, nTamSenha) {
  sSenha = readline(sRotulo)
  #  ncont = 0
  #  sSenha=""
  #  sLetra='\0'
  #  while ((sLetra!='\r') && (ncont < nTamSenha)) {
  #    sLetra=readkey
  #    sSenha= paste(sSenha, sLetra, sep="")
  #    ncont=ncont+1
  #  }
  digitaSenha = sSenha
}
#------------------------------------------------------------------------------
# Validação de um número qualquer.
# sRotulo - o texto antes de se digitar o número
# sNumero - a mstring com o valor do número
# retorna - o sNumero
#------------------------------------------------------------------------------
validaNumero <- function(sRotulo, sNumero) {
  nStatus=-1
  while (nStatus!=0) {
    sNumero = readline(sRotulo)
    nnum = as.real(sNumero)
    if (!is.na(nnum)) {
      if (nnum < 0.01) 
        cat(MSG_NUMINV)
      else
        nStatus = 0
    } else
        cat(MSG_NUMINV)
  }
  validaNumero = sNumero
}
#------------------------------------------------------------------------------
# Validação de uma data ou data/hora qualquer.
# sRotulo - o texto antes de se digitar a data/hora
# sDataHora - a mstring com o valor da data/hora
# bSoData - indica se vai validar somente uma data sem a hora
# retorna - a sDataHora
#------------------------------------------------------------------------------
validaDataHora <- function(sRotulo, sDataHora, bSoData) {

bvalida = FALSE
bdatavalida = FALSE
bhoravalida = FALSE
nudiames = 0
if (bSoData==TRUE) ntam=10
else ntam=19
while (bvalida==FALSE) {
  sDataHora = readline(sRotulo)
  if (nchar(sDataHora)==ntam) {
    sdia = copy(sDataHora,1,2)
    ndia = as.integer(sdia)
    smes = copy(sDataHora,4,2)
    nmes = as.integer(smes)
    sano = copy(sDataHora,7,4)
    nano = as.integer(sano)
  
    if ((nano >= 1) && (nano <= 9999)) {
      if ((nmes >= 1) && (nmes <= 31)) {
          if (nmes == 1 || nmes == 3 || nmes == 5 || nmes == 7 || 
              nmes == 8 || nmes == 10 || nmes == 12) 
             nudiames = 31
          else if (nmes == 2) {
               # ano bissexto 
               if ((nano %% 4)==0) nudiames = 29
               else nudiames = 28
          } else if (nmes == 4 || nmes == 6 || nmes == 9 || nmes == 11)
             nudiames = 30

          if ((ndia >=1) && (ndia <=nudiames))
             bdatavalida = TRUE
      }
    }
  
    if (bSoData) {
       if (bdatavalida) 
         bvalida = TRUE
       else 
  		   cat(MSG_DATAINV)
    } else {
      if (bdatavalida) {
          shora = copy(sDataHora,12,2)
          nhora = as.integer(shora)
          smin = copy(sDataHora,15,2)
          nmin = as.integer(smin)
          sseg = copy(sDataHora,18,2)
          nseg = as.integer(sseg)
  
          if ((nhora >= 0) && (nhora <= 23)) {
            if ((nmin >= 0) && (nmin <= 59)) {
              if ((nseg >= 0) && (nseg <= 59))
                 bhoravalida = TRUE
            }
          }
          
          if (bhoravalida) 
  		      bvalida = TRUE
          else 
            cat(MSG_DTHRINV)
      } else
        cat(MSG_DTHRINV)
    }
  } else {
    if (bSoData==TRUE) cat(MSG_DATAINV)
    else cat(MSG_DTHRINV)
  }
}
validaDataHora = sDataHora
}
#------------------------------------------------------------------------------
# Retorna a Data e a hora do sistema.
# retorna - a data e a hora
#------------------------------------------------------------------------------
retDataHora <- function() {
  retDataHora = format(Sys.time(), "%d/%m/%Y %H:%M:%S")
}
#------------------------------------------------------------------------------
# Calcula o tamanho do arquivo.
# sArq - o arquivo
# retorna - o tamanho do arquivo
#------------------------------------------------------------------------------
tamArq <- function(sArq) {
  tamArq = file.info(ARQ_ASSUNTO)[[1]]
}

existeArqs <- function() {
  if (file.exists(ARQ_ASSUNTO)==FALSE) file.create(ARQ_ASSUNTO)
  if (file.exists(ARQ_AUTOR)==FALSE) file.create(ARQ_AUTOR)
  if (file.exists(ARQ_EDITORA)==FALSE) file.create(ARQ_EDITORA)
  if (file.exists(ARQ_IDIOMA)==FALSE) file.create(ARQ_IDIOMA)
  if (file.exists(ARQ_ENDERECO)==FALSE) file.create(ARQ_ENDERECO)
  if (file.exists(ARQ_PAIS)==FALSE) file.create(ARQ_PAIS)
  if (file.exists(ARQ_PROFISSAO)==FALSE) file.create(ARQ_PROFISSAO)
  if (file.exists(ARQ_LIVRO)==FALSE) file.create(ARQ_LIVRO)
  if (file.exists(ARQ_LIVASS)==FALSE) file.create(ARQ_LIVASS)
  if (file.exists(ARQ_LIVAUT)==FALSE) file.create(ARQ_LIVAUT)
  if (file.exists(ARQ_CLIENTE)==FALSE) file.create(ARQ_CLIENTE)
  if (file.exists(ARQ_USUARIO)==FALSE) file.create(ARQ_USUARIO)
  if (file.exists(ARQ_VENDA)==FALSE) file.create(ARQ_VENDA)

}

#------------------------------------------------------------------------------
# Abre ou cria os arquivos do sistema.
# bAbre - condição para abrir ou criar os arquivos do sistema
#------------------------------------------------------------------------------
abrecriaArqs <- function(bAbre) {
if (bAbre) {
  open(tfAssunto, ARQ_ABRE)
  if (isOpen(tfAssunto)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_ASSUNTO))
    quit() 
  }
  open(tfAutor, ARQ_ABRE)
  if (isOpen(tfAutor)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_AUTOR))
    quit() 
  }
  open(tfEditora, ARQ_ABRE)
  if (isOpen(tfEditora)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_EDITORA))
    quit() 
  }
  open(tfIdioma, ARQ_ABRE)
  if (isOpen(tfIdioma)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_IDIOMA))
    quit() 
  }
  open(tfEndereco, ARQ_ABRE)
  if (isOpen(tfEndereco)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_ENDERECO))
    quit() 
  }
  open(tfPais, ARQ_ABRE)
  if (isOpen(tfPais)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_PAIS))
    quit() 
  }
  open(tfProfissao, ARQ_ABRE)
  if (isOpen(tfProfissao)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_PROFISSAO))
    quit() 
  }
  open(tfLivro, ARQ_ABRE)
  if (isOpen(tfLivro)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_LIVRO))
    quit() 
  }
  open(tfLivroAss, ARQ_ABRE)
  if (isOpen(tfLivroAss)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_LIVASS))
    quit() 
  }
  open(tfLivroAut, ARQ_ABRE)
  if (isOpen(tfLivroAut)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_LIVAUT))
    quit() 
  }
  open(tfCliente, ARQ_ABRE)
  if (isOpen(tfCliente)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_CLIENTE))
    quit() 
  }
  open(tfUsuario, ARQ_ABRE)
  if (isOpen(tfUsuario)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_USUARIO))
    quit() 
  }
  open(tfVenda, ARQ_ABRE)
  if (isOpen(tfVenda)==FALSE) {
    cat(sprintf("%s --> %s\n",MSG_ARQERRO,ARQ_VENDA))
    quit() 
  }
} else {
  existeArqs()
}
}
#------------------------------------------------------------------------------
# Fecha todos os arquivos abertos.
#------------------------------------------------------------------------------
fechaArqs <- function() {
  close(tfAssunto)
  close(tfAutor)
  close(tfEditora)
  close(tfIdioma)
  close(tfEndereco)
  close(tfPais)
  close(tfProfissao)
  close(tfLivro)
  close(tfLivroAss)
  close(tfLivroAut)
  close(tfCliente)
  close(tfUsuario)
  close(tfVenda)
}

#------------------------------------------------------------------------------
# Pesquisa um registro através de um valor chave num arquivo.
# sArq - o arquivo
# sChave - a chave a ser pesquisada
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o registro pesquisado
#------------------------------------------------------------------------------
pesqArq <- function(sArq, sChave, nPosChave, nTamChave, nTamLinha) {
  bQuebra = FALSE
  sres = ""
  stemp = ""
  slinha = ""
  nPosicao = -1
  seek(sArq, 0, "start", "read")
  while ((length(slinha)!=0) && (bQuebra==FALSE)) {
    slinha = readLines(sArq, 1)
    if (length(slinha)!=0) {
      nPosicao = nPosicao + 1
      stemp = slinha
      sres = trim(copy(slinha,nPosChave,nTamChave))
      if (sres == sChave)
         bQuebra = TRUE
    }
  }
  nPosicao = nPosicao * (nTamLinha + TAM_CRLF)
  ag("g_nPosicao", nPosicao)

  if (nPosicao > 0)
     seek(sArq, nPosicao, "start", "read")
  else
     seek(sArq, 0, "start", "read")

  if (sres != sChave) 
     pesqArq = ""
  else 
     pesqArq = copy(stemp,1,nTamLinha)
}
#------------------------------------------------------------------------------
# Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
# sArq - o arquivo
# nTamLinha - o tamanho do registro
#------------------------------------------------------------------------------
pesqLinhaExcluida <- function(sArq, nTamLinha) {
  sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha)
  if (nchar(sExcluido)==0) {
    nPosicao = seek(sArq, 0, "end")
    nPosicao = nPosicao + (nTamLinha + TAM_CRLF)
    ag("g_nPosicao", nPosicao)
  }
}
#------------------------------------------------------------------------------
# Pesquisa o maior código num arquivo.
# sArq - o arquivo
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o maior código
#------------------------------------------------------------------------------
pesqMaxCod <- function(sArq, nPosChave, nTamChave, nTamLinha) {
slinha = ""
bQuebra = FALSE
nMaior = 0
seek(sArq, 0, "start", "read")
while ((length(slinha)!=0) && (bQuebra==FALSE)) {
  slinha = readLines(sArq, 1)
  if (length(slinha)!=0) {
    sres = trim(copy(slinha,nPosChave,nTamChave))
    nCod=as.integer(sres)
    if (nCod > nMaior)
       nMaior = nCod
  }
}
pesqLinhaExcluida(sArq, nTamLinha)
sres = as.character(nMaior+1)

pesqMaxCod = sres
}
#------------------------------------------------------------------------------
# Grava os registros num determinado arquivo.
# sArq - o arquivo
# sTexto - o registro a ser gravado
# sMsgAcerto - a mensagem caso o registro foi gravado
# sMsgErro - a mensagem caso o registro não foi gravado
#------------------------------------------------------------------------------
escreveArq <- function(sArq, sTexto, sMsgAcerto, sMsgErro) {

seek(sArq, gg("g_nPosicao"), "start", "write")
writeLines(sTexto, sArq)
#cat(sTexto,file=sArq)
cat(sMsgAcerto)

#cat(sMsgErro)
}
#------------------------------------------------------------------------------
# Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o registro montado
#------------------------------------------------------------------------------
LinhaReg <- function(sreg) {
slinha = ""

if (sreg==opAssunto) 
   slinha = paste(esp(gg("tAssunto$codigo"),10),esp(gg("tAssunto$assunto"),30), sep="")
else if (sreg==opAutor)
   slinha = paste(esp(gg("tAutor$codigo"),10),esp(gg("tAutor$autor"),30), sep="")
else if (sreg==opEditora)
   slinha = paste(esp(gg("tEditora$codigo"),10),esp(gg("tEditora$editora"),50), sep="")
else if (sreg==opEndereco)
   slinha = paste(esp(gg("tEndereco$codigo"),10),esp(gg("tEndereco$logradouro"),40),
   esp(gg("tEndereco$bairro"),15),esp(gg("tEndereco$cep"),8),esp(gg("tEndereco$cidade"),30),
   esp(gg("tEndereco$estado"),20), sep="")
else if (sreg==opIdioma)
   slinha = paste(esp(gg("tIdioma$codigo"),10),esp(gg("tIdioma$idioma"),20), sep="")
else if (sreg==opPais)
   slinha = paste(esp(gg("tPais$codigo"),3),esp(gg("tPais$pais"),50), sep="")
else if (sreg==opProfissao)
   slinha = paste(esp(gg("tProfissao$codigo"),10),esp(gg("tProfissao$profissao"),50), sep="")
else if (sreg==opUsuario)
   slinha = paste(esp(gg("tUsuario$login"),10),esp(gg("tUsuario$senha"),10), sep="")
else if (sreg==opLivro)
   slinha = paste(esp(gg("tLivro$isbn"),13),esp(gg("tLivro$titulo"),50),
   esp(gg("tLivro$edicao"),10),esp(gg("tLivro$anopubli"),10),esp(gg("tLivro$codeditora"),10),
   esp(gg("tLivro$volume"),10),esp(gg("tLivro$codidioma"),10),esp(gg("tLivro$npaginas"),10),
   esp(gg("tLivro$preco"),10),esp(gg("tLivro$qtdestoque"),10), sep="")
else if (sreg==opLivroAss)
   slinha = paste(esp(gg("tLivroAss$isbn"),13),esp(gg("tLivroAss$codassunto"),10), sep="")
else if (sreg==opLivroAut)
   slinha = paste(esp(gg("tLivroAut$isbn"),13),esp(gg("tLivroAut$codautor"),10), sep="")
else if (sreg==opCliente)
   slinha = paste(esp(gg("tCliente$cpf"),14),esp(gg("tCliente$nome"),30),
   esp(gg("tCliente$email"),30),esp(gg("tCliente$identidade"),10),esp(gg("tCliente$sexo"),1),
   esp(gg("tCliente$telefone"),17),esp(gg("tCliente$dtnascimento"),10),
   esp(gg("tCliente$codendereco"),10),esp(gg("tCliente$codpais"),3),
   esp(gg("tCliente$codprofissao"),10), sep="")
else if (sreg==opVenda)
   slinha = paste(esp(gg("tVenda$dthrvenda"),19),esp(gg("tVenda$cpf"),14),
   esp(gg("tVenda$isbn"),13),esp(gg("tVenda$precovenda"),10), sep="")

LinhaReg = slinha
}
#------------------------------------------------------------------------------
# Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o tamanho do registro
#------------------------------------------------------------------------------
tamReg <- function(sreg) {
nret = 0

if (sreg==opAssunto) nret = TAM_ASSUNTO
else if (sreg==opAutor) nret = TAM_AUTOR
else if (sreg==opEditora) nret = TAM_EDITORA
else if (sreg==opEndereco) nret = TAM_ENDERECO
else if (sreg==opIdioma) nret = TAM_IDIOMA
else if (sreg==opPais) nret = TAM_PAIS
else if (sreg==opProfissao) nret = TAM_PROFISSAO
else if (sreg==opUsuario) nret = TAM_USUARIO
else if (sreg==opLivro) nret = TAM_LIVRO
else if (sreg==opLivroAss) nret = TAM_LIVASS
else if (sreg==opLivroAut) nret = TAM_LIVAUT
else if (sreg==opCliente) nret = TAM_CLIENTE
else if (sreg==opVenda) nret = TAM_VENDA

tamReg = nret
}
#------------------------------------------------------------------------------
# Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# nNum - indica qual rotulo será retornado
# retorna - o rotulo
#------------------------------------------------------------------------------
rotulo <- function(sreg, nNum) {
sret = ""

if (sreg==opAssunto) {   
   if (nNum == 0) sret = "Assunto(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "Código do assunto: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 2) {
      sret = "Assunto: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 30)
   }
} else if (sreg==opAutor) {
   if (nNum == 0) sret = "Autor(es) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "Código do autor: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   } 
   else if (nNum == 2) {
      sret = "Autor: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 30)
   }
} else if (sreg==opEditora) {
   if (nNum == 0) sret = "Editora(s) não encontrada(s)!\n"
   else if (nNum == 1) {
      sret = "Código da editora: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 2) {
      sret = "Editora: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 50)
   }
} else if (sreg==opEndereco) {
   if (nNum == 0) sret = "Endereço(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "Código do endereço: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 2) {
      sret = "Logradouro: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 40)
   }
   else if (nNum == 3) {
      sret = "Bairro: "
      ag("g_nPosChave", 51)
      ag("g_nTamChave", 15)
   }
   else if (nNum == 4) {
      sret = "CEP: "
      ag("g_nPosChave", 66)
      ag("g_nTamChave", 8)
   }
   else if (nNum == 5) {
      sret = "Cidade: "
      ag("g_nPosChave", 74)
      ag("g_nTamChave", 30)
   }
   else if (nNum == 6) {
      sret = "Estado: "
      ag("g_nPosChave", 104)
      ag("g_nTamChave", 20)
   }
} else if (sreg==opIdioma) {
   if (nNum == 0) sret = "Idioma(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "Código do idioma: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 2) {
      sret = "Idioma: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 20)
   }
} else if (sreg==opPais) {
   if (nNum == 0) sret = "País(es) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "Código do país: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 3)
   }
   else if (nNum == 2) {
      sret = "País: "
      ag("g_nPosChave", 4)
      ag("g_nTamChave", 50)
   }
} else if (sreg==opProfissao) {
   if (nNum == 0) sret = "Profissão(es) não encontrada(s)!\n"
   else if (nNum == 1) {
      sret = "Código da profissão: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 2) {
      sret = "Profissão: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 50)
   }
} else if (sreg==opUsuario) {
   if (nNum == 0) sret = "login ou senha incorreta, tente de novo!\n"
   else if (nNum == 1) {
      sret = "Login: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 2) {
      sret = "Senha: "
      ag("g_nPosChave", 11)
      ag("g_nTamChave", 10)
   }
} else if (sreg==opLivro) {
   if (nNum == 0) sret = "Livro(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "ISBN: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 13)
   }
   else if (nNum == 2) {
      sret = "Título: "
      ag("g_nPosChave", 14)
      ag("g_nTamChave", 50)
   }
   else if (nNum == 3) {
      sret = "Edição: "
      ag("g_nPosChave", 64)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 4) {
      sret = "Ano de Publicação: "
      ag("g_nPosChave", 74)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 5) {
      sret = "Código da editora: "
      ag("g_nPosChave", 84)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 6) {
      sret = "Volume: "
      ag("g_nPosChave", 94)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 7) {
      sret = "Código do idioma: "
      ag("g_nPosChave", 104)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 8) {
      sret = "Número de páginas: "
      ag("g_nPosChave", 114)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 9) {
      sret = "Preço: "
      ag("g_nPosChave", 124)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 10) {
      sret = "Qtd. Estoque: "
      ag("g_nPosChave", 134)
      ag("g_nTamChave", 10)
   }
} else if (sreg==opLivroAss) {
   if (nNum == 0) sret = "Assunto(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "ISBN: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 13)
   }
   else if (nNum == 2) {
      sret = "Código do assunto: "
      ag("g_nPosChave", 14)
      ag("g_nTamChave", 10)
   }
} else if (sreg==opLivroAut) {
   if (nNum == 0) sret = "Autor(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "ISBN: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 13)
   }
   else if (nNum == 2) {
      sret = "Código do autor: "
      ag("g_nPosChave", 14)
      ag("g_nTamChave", 10)
   }
} else if (sreg==opCliente) {
   if (nNum == 0) sret = "Cliente(s) não encontrado(s)!\n"
   else if (nNum == 1) {
      sret = "CPF: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 14)
   }
   else if (nNum == 2) {
      sret = "Nome: "
      ag("g_nPosChave", 15)
      ag("g_nTamChave", 30)
   }
   else if (nNum == 3) {
      sret = "E-mail: "
      ag("g_nPosChave", 45)
      ag("g_nTamChave", 30)
   }
   else if (nNum == 4) {
      sret = "Identidade: "
      ag("g_nPosChave", 75)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 5) {
      sret = "Sexo: "
      ag("g_nPosChave", 85)
      ag("g_nTamChave", 1)
   }
   else if (nNum == 6) {
      sret = "Telefone: "
      ag("g_nPosChave", 86)
      ag("g_nTamChave", 17)
   }
   else if (nNum == 7) {
      sret = "Dt. Nascimento: "
      ag("g_nPosChave", 103)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 8) {
      sret = "Código do endereço: "
      ag("g_nPosChave", 113)
      ag("g_nTamChave", 10)
   }
   else if (nNum == 9) {
      sret = "Código do país: "
      ag("g_nPosChave", 123)
      ag("g_nTamChave", 3)
   }
   else if (nNum == 10) {
      sret = "Código da Profissão: "
      ag("g_nPosChave", 126)
      ag("g_nTamChave", 10)
   }
} else if (sreg==opVenda) {
   if (nNum == 0) sret = "Venda(s) não encontrada(s)!\n"
   else if (nNum == 1) {
      sret = "Data/Hora venda: "
      ag("g_nPosChave", 1)
      ag("g_nTamChave", 19)
   }
   else if (nNum == 2) {
      sret = "CPF: "
      ag("g_nPosChave", 20)
      ag("g_nTamChave", 14)
   }
   else if (nNum == 3) {
      sret = "ISBN: "
      ag("g_nPosChave", 34)
      ag("g_nTamChave", 13)
   }
   else if (nNum == 4) {
      sret = "Preço de venda: "
      ag("g_nPosChave", 47)
      ag("g_nTamChave", 10)
   }
}
rotulo = sret
}
#------------------------------------------------------------------------------
# Indica se continua ou não mostrando um número máximo de linhas.
# nlinha - a linha a ser continuada
# nQtdLinha - a quantidade de linhas a serem mostradas
# retorna - se continua ou não
#------------------------------------------------------------------------------
ContinuaSN <- function(nlinha, nQtdLinha) {
bret = FALSE
if (nlinha > 0) {
  if ((nlinha %% nQtdLinha) == 0) {
      bSOp = TRUE
      while(bSOp) {
       menu(13)       
       opCSubMenu = readline()
       if ((opCSubMenu=="S") || (opCSubMenu=="s")) bSOp = FALSE
       else if ((opCSubMenu=="N") || (opCSubMenu=="n")) {
          bret = TRUE
          bSOp = FALSE
       } else cat(MSG_ERRO)
      }
  }
}
ContinuaSN = bret
}
#------------------------------------------------------------------------------
# Lista vários registros de acordo com a pesquisa feita.
# sArq - o arquivo
# sreg - o tipo de arquivo
# sChave - a chave a ser pesquisada
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# nQtdLinha - a quantidade de linhas a serem mostradas
# retorna - se encontrou algum registro
#------------------------------------------------------------------------------
ListarTodos <- function(sArq, sreg, sChave, 
    nPosChave, nTamChave, nTamLinha, nQtdLinha, bPesqRelativa) {
slinha = ""
bRet = FALSE
bQuebra = FALSE
nCont = 0
mostrarDados(sreg, "", 2)
seek(sArq, 0, "start", "read")
while ((length(slinha)!=0) && (bQuebra==FALSE)) {
  slinha = readLines(sArq, 1)
  if (length(slinha)!=0) {
    if (bPesqRelativa) {
      sres = trim(copy(slinha,nPosChave,nTamChave))
      if (strRelativa(sres,sChave)==TRUE) {
         bAchou = TRUE
         bRet = TRUE
      } else {
         bAchou = FALSE
      }   
    } else {
      bAchou = TRUE
      bRet = TRUE
    }
  
    if (bAchou && (length(slinha)!=0)) {
      mostrarDados(sreg, copy(slinha,1,nTamLinha), 3)
      nCont = nCont + 1
    }

    bQuebra = ContinuaSN(nCont, nQtdLinha)
  }
}

ListarTodos = bRet
}
#------------------------------------------------------------------------------
# Lista vários registros entre arquivos de acordo com a pesquisa feita.
# sArq1 - o arquivo de ligação
# sreg1 - o tipo de arquivo de ligação
# nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
# nTamChave1 - o tamanho da primeira chave no arquivo de ligação
# nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
# nTamChave2 - o tamanho da segunda chave do arquivo de ligação
# sChave - a chave a ser pesquisada no arquivo de ligação
# sArq2 - o arquivo a ser pesquisado
# sreg2 - o tipo de arquivo a ser pesquisado
# nPosChave3 - a posicao inicial da chave do arquivo pesquisado
# nQtdLinha - a quantidade de linhas a serem mostradas
#------------------------------------------------------------------------------
ListarRegLigados <- function(sArq1, sreg1, nPosChave1, nTamChave1, 
nPosChave2, nTamChave2, sChave, sArq2, sreg2, nPosChave3, nQtdLinha) {

slinha1 = ""
bRet = FALSE
nCont = 0
bQuebra = FALSE
mostrarDados(sreg2, "", 2)
seek(sArq1, 0, "start", "read")
while ((length(slinha1)!=0) && (bQuebra==FALSE)) {
  slinha1 = readLines(sArq1, 1)
  if (length(slinha1)!=0) {
    sCodigo1 = trim(copy(slinha1,nPosChave1,nTamChave1))
    if (sCodigo1 == sChave) {
      sCodigo2 = trim(copy(slinha1,nPosChave2,nTamChave2))
      slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
      mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3)
      bRet = TRUE
      nCont = nCont + 1
    }
    bQuebra = ContinuaSN(nCont, nQtdLinha)
  }
}
if (bRet==FALSE)
   cat(rotulo(sreg2,0))
}
#------------------------------------------------------------------------------
# Valida a entrada de registros de acordo com a pesquisa feita.
# sArq - o arquivo
# sreg - o tipo de arquivo
# nTexto - o numero do rótulo da entrada
# sEntrada - a chave a ser pesquisada e validada
# nTentativas - o número máximo de tentativas
# bPesqRelativa - indica se vai realizar uma pesquisa relativa
# bTipoEntrada - indica o tipo de entrada
# retorna - o registro pesquisado e validado
#------------------------------------------------------------------------------
validaEntrada <- function(sArq, sreg, nTexto, sEntrada, nTentativas,
       bPesqRelativa, bTipoEntrada) {

nTamLinha = tamReg(sreg)
sMsgErro = rotulo(sreg,0)
sTexto = rotulo(sreg,nTexto)
nPosChave = gg("g_nPosChave")
nTamChave = gg("g_nTamChave")

ncont = 1
bQuebra = FALSE
  while ((bQuebra==FALSE) && (ncont <= nTentativas )) {
    if (bTipoEntrada==opTexto) 
      sEntrada = readline(sTexto)
    else if (bTipoEntrada==opNumero)
       sEntrada = validaNumero(sTexto,sEntrada)
    else if (bTipoEntrada==opData)
       sEntrada = validaDataHora(sTexto,sEntrada,TRUE)
    else if (bTipoEntrada==opDataHora)
       sEntrada = validaDataHora(sTexto,sEntrada,FALSE)
    else if (bTipoEntrada==opSenha) 
       sEntrada = digitaSenha(sTexto, 10)

    if (bPesqRelativa) {
       if (ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha,
           QTD_MAX_LINHA, TRUE))
         sres = " "
    } else
       sres = pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)

    if (nchar(sres)==0)
       cat(sMsgErro)
    else
       bQuebra = TRUE

    ncont = ncont + 1
  }
validaEntrada = sres
}
#------------------------------------------------------------------------------
# Mostra a tela de splash do sistema.
#------------------------------------------------------------------------------
frmSplash <- function() {
 cat("*---------------------------------------")
 cat("-------------------------------------*\n")
 cat("| LL    II VV   VV RRRRR  UU  UU   SSSS ")
 cat("VV   VV II RRRRR  TTTT UU  UU   SSSS |\n")
 cat("| LL    II  VV VV  RR   R UU  UU  SS    ")
 cat(" VV VV  II RR   R  TT  UU  UU  SS    |\n")
 cat("| LL    II   VVV   RRRRR  UU  UU    SS  ")
 cat("  VVV   II RRRRR   TT  UU  UU    SS  |\n")
 cat("| LLLLL II    V    RR   R  UUUU  SSSS   ")
 cat("   V    II RR   R  TT   UUUU  SSSS   |\n")
 cat("*---------------------------------------")
 cat("-------------------------------------*\n")
 for (cont in 1:18) cat("\n")
 cat(MSG_PRESS)
 readline()
}
#------------------------------------------------------------------------------
# Mostra a tela de sobre do sistema.
#------------------------------------------------------------------------------
frmSobre <- function() {
 cat("*------------------------------------------------------------*\n")
 cat("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |\n")
 cat("|  LL        II   VV     VV   RR     R  UU    UU  SS         |\n")
 cat("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |\n")
 cat("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |\n")
 cat("|  LLLL      II      VVV      RR RR     UU    UU        SS   |\n")
 cat("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |\n")
 cat("|                                                            |\n")
 cat("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |\n")
 cat("|   VV     VV   II  RR     R     TT     UU    UU  SS         |\n")
 cat("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |\n")
 cat("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |\n")
 cat("|      VVV      II  RR RR        TT     UU    UU        SS   |\n")
 cat("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |\n")
 cat("|                                                            |\n")
 cat("|                                               Versao 1.0.0 |\n")
 cat("| Sistema integrante do projeto Livrus Virtus.               |\n")
 cat("| Todos os direitos reservados para Henrique F. de Souza.    |\n")
 cat("| Versao programada na linguagem R.                          |\n")
 cat("*------------------------------------------------------------*\n")
 for (cont in 1:4) cat("\n")
 cat(MSG_PRESS)
 readline()
}
#------------------------------------------------------------------------------
# Mostra a tela de login do sistema.
# retorna - se o login foi validado corretamente
#------------------------------------------------------------------------------
frmLogin <- function() {
  bret = FALSE
  cat("*--------------------------------------------------------------*\n")
  cat("| Login do sistema                                             |\n")
  cat("*--------------------------------------------------------------*\n")
  slinha = validaEntrada(tfUsuario, opUsuario, 1, tUsuario$login, 3,
        FALSE, opTexto)
  if (nchar(slinha) > 0) {
     slinha = validaEntrada(tfUsuario, opUsuario, 2, tUsuario$senha, 3,
        FALSE, opSenha)
     if (nchar(slinha) > 0) {
        ag("tUsuario$login", trim(copy(slinha, 1, 10)))
        ag("tUsuario$senha", trim(copy(slinha, 11, 10)))
        bret = TRUE
     }
  }
  cat("\n")
  frmLogin = bret
}
#------------------------------------------------------------------------------
# Mostra os menus do sistema.
# num - o número do menu
#------------------------------------------------------------------------------
menu <- function(num)
{
 if (num==1) {
  cat("*--------------------------------------------------------------*\n")
  cat("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |\n")
  cat("*--------------------------------------------------------------*\n")
 } else if (num==2) {
   cat("*---------------------------------*\n")
   cat("| 01. Cadastro de Assuntos        |\n")
   cat("| 02. Cadastro de Autores         |\n")
   cat("| 03. Cadastro de Editoras        |\n")
   cat("| 04. Cadastro de Endereços       |\n")
   cat("| 05. Cadastro de Idiomas         |\n")
   cat("| 06. Cadastro de Países          |\n")
   cat("| 07. Cadastro de Profissões      |\n")
   cat("| 08. Cadastro de Clientes        |\n")
   cat("| 09. Cadastro de Livros          |\n")
   cat("| 10. Voltar ao menu              |\n")
   cat("*---------------------------------*\n")
 } else if (num==3) {
   cat("*---------------------------------*\n")
   cat("| 01. Consulta de Assuntos        |\n")
   cat("| 02. Consulta de Autores         |\n")
   cat("| 03. Consulta de Editoras        |\n")
   cat("| 04. Consulta de Endereços       |\n")
   cat("| 05. Consulta de Idiomas         |\n")
   cat("| 06. Consulta de Países          |\n")
   cat("| 07. Consulta de Profissões      |\n")
   cat("| 08. Consulta de Clientes        |\n")
   cat("| 09. Consulta de Livros          |\n")
   cat("| 10. Voltar ao menu              |\n")
   cat("*---------------------------------*\n")
 } else if (num==4) {
   cat("*---------------------------------*\n")
   cat("| 01. Vender Livros               |\n")
   cat("| 02. Vendas Realizadas           |\n")
   cat("| 03. Voltar ao menu              |\n")
   cat("*---------------------------------*\n")
 } else if (num==5) {
   cat("*---------------------------------*\n")
   cat("| 01. Alterar senha               |\n")
   cat("| 02. Sobre o sistema             |\n")
   cat("| 03. Sair do sistema             |\n")
   cat("| 04. Voltar ao menu              |\n")
   cat("*---------------------------------*\n")
 } else if (num==6) {
   cat("*--------------------------------------------------------------*\n")
   cat("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==7) {
   cat("*--------------------------------------------------------------*\n")
   cat("| (1) Salvar inclusão       (2) Voltar ao menu                 |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==8) {
   cat("*--------------------------------------------------------------*\n")
   cat("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==9) {
   cat("*--------------------------------------------------------------*\n")
   cat("| (1) Salvar alteração      (2) Voltar ao menu                 |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==10) {
   cat("*--------------------------------------------------------------*\n")
   cat("| Certeza de excluir? (S/N)                                    |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==11) {
   cat("*--------------------------------------------------------------*\n")
   cat("| Deseja sair do sistema? (S/N)                                |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==12) {
   cat("*--------------------------------------------------------------*\n")
   cat("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==13) {
   cat("*--------------------------------------------------------------*\n")
   cat("| Deseja continuar? (S/N)                                      |\n")
   cat("*--------------------------------------------------------------*\n")
 } else if (num==14) {
   cat("*--------------------------------------------------------------*\n")
   cat("| Salvar inclusão (S/N)                                        |\n")
   cat("*--------------------------------------------------------------*\n")
 }
 cat(MSG_OPCAO)
}
#------------------------------------------------------------------------------
# Realiza os cadastros de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
frmCadastros <- function(sreg, sacao) {
slinha = ""

if (sreg==opAssunto) {
   if (sacao==opNovo) {
      ag("tAssunto$codigo", pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg)))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   } else if (sacao==opPesquisar) {
     slinha = validaEntrada(tfAssunto,sreg,1,tAssunto$codigo,1,FALSE,opNumero)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opAutor) {
   if (sacao==opNovo) {
      ag("tAutor$codigo", pesqMaxCod(tfAutor, 1, 10, tamReg(sreg)))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfAutor, sreg, 1, tAutor$codigo,1,FALSE,opNumero)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opEditora) {
   if (sacao==opNovo) {
      ag("tEditora$codigo", pesqMaxCod(tfEditora, 1, 10, tamReg(sreg)))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfEditora,sreg,1,tEditora$codigo,1,FALSE,opNumero)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opEndereco) {
   if (sacao==opNovo) {
      ag("tEndereco$codigo", pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg)))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfEndereco,sreg,1,tEndereco$codigo,1,
              FALSE,opNumero)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opIdioma) {
   if (sacao==opNovo) {
      ag("tIdioma$codigo", pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg)))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfIdioma,sreg,1,tIdioma$codigo,1,FALSE,opNumero)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opPais) {
   if (sacao==opNovo) {
      ag("tPais$codigo", readline(rotulo(sreg, 1)))
      slinha = pesqArq(tfPais, gg("tPais$codigo"), 1, 3, tamReg(sreg))
      if (nchar(slinha)==0) {
         pesqLinhaExcluida(tfPais, tamReg(sreg))
         mostrarDados(sreg, "", 1)
         subMenu(7, sreg)
      } else cat(MSG_REGEXST)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfPais, sreg, 1, tPais$codigo, 1, FALSE, opTexto)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      cat(sprintf("%s%s\n", rotulo(sreg, 1), gg("tPais$codigo")))
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opProfissao) {
   if (sacao==opNovo) {
      ag("tProfissao$codigo", pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg)))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfProfissao,sreg,1,tProfissao$codigo,1,
              FALSE,opNumero)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opLivro) {
   if (sacao==opNovo) {
      ag("tLivro$isbn", readline(rotulo(sreg, 1)))
      if (validaISBN(gg("tLivro$isbn"))) {
          slinha = pesqArq(tfLivro, gg("tLivro$isbn"), 1, 13, tamReg(sreg))
          if (nchar(slinha)==0) {
             pesqLinhaExcluida(tfLivro, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu(7, sreg)
             frmCadLigados(opLivroAss, opNovo, gg("tLivro$isbn"))
             frmCadLigados(opLivroAut, opNovo, gg("tLivro$isbn"))
          } else cat(MSG_REGEXST)
      } else cat(MSG_ISBNINV)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfLivro, sreg, 1, tLivro$isbn, 1,FALSE,opTexto)
      if (nchar(slinha) > 0) {
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tLivro$isbn")))
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
      frmCadLigados(opLivroAss, opExcluir, gg("tLivro$isbn"))
      cat("Assuntos dos livros excluídos, inclua novos!\n")
      frmCadLigados(opLivroAss, opNovo, gg("tLivro$isbn"))
      frmCadLigados(opLivroAut, opExcluir, gg("tLivro$isbn"))
      cat("Autores dos livros excluídos, inclua novos!\n")
      frmCadLigados(opLivroAut, opNovo, gg("tLivro$isbn"))
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
      cat("Assuntos dos livros sendo excluídos!\n")
      frmCadLigados(opLivroAss, opExcluir, gg("tLivro$isbn"))
      cat("Autores dos livros sendo excluídos!\n")
      frmCadLigados(opLivroAut, opExcluir, gg("tLivro$isbn"))
   }
} else if (sreg==opCliente) {
   if (sacao==opNovo) {
      ag("tCliente$cpf", readline(rotulo(sreg, 1)))
      if (validaCPF(gg("tCliente$cpf"))) {
          slinha = pesqArq(tfCliente, gg("tCliente$cpf"), 1, 14, tamReg(sreg))
          if (nchar(slinha)==0) {
             pesqLinhaExcluida(tfCliente, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu(7, sreg)
          } else cat(MSG_REGEXST)
      } else cat(MSG_CPFINV)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfCliente, sreg, 1, tCliente$cpf,1,FALSE,opTexto)
      if (nchar(slinha) > 0) {
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      }
   } else if (sacao==opAlterar) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tCliente$cpf")))
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   } else if (sacao==opExcluir) {
      subMenu(10, sreg)
   }
} else if (sreg==opVenda) {
   if (sacao==opNovo) {
      ag("tVenda$dthrvenda", retDataHora())
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tVenda$dthrvenda")))
      slinha = pesqArq(tfVenda, gg("tVenda$dthrvenda"), 1, 19, tamReg(sreg))
      if (nchar(slinha)==0) {
         slinha = validaEntrada(tfCliente,opCliente,1,tVenda$cpf,3,
                 FALSE,opTexto)
         if (nchar(slinha) > 0) {
            ag("tVenda$cpf", trim(copy(slinha,1,14)))
            if (validaCPF(gg("tVenda$cpf"))) {
               cat(sprintf(" %s",rotulo(opCliente, 2))) # Nome
               cat(sprintf("%s\n", copy(slinha, gg("g_nPosChave"), gg("g_nTamChave"))))
               frmCadLigados(opVenda, opNovo, gg("tVenda$cpf"))
            } else cat(MSG_CPFINV)
         }
      } else cat(MSG_REGEXST)
   } else if (sacao==opPesquisar) {
      slinha = validaEntrada(tfVenda, sreg, 1, tVenda$dthrvenda,1,
              FALSE,opDataHora)
      if (nchar(slinha) > 0) {
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      }
   }
}

}
#------------------------------------------------------------------------------
# Realiza as consultas de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
frmConsultas <- function(sreg, sacao) {
slinha = ""

if (sreg==opAssunto) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opAutor) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opEditora) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfEditora,sreg,2,tEditora.editora,1,TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opEndereco) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1,
              TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
         3, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opIdioma) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opPais) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opProfissao) {
   if (sacao==opPesquisar)
     slinha = validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opLivro) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
        1, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opCliente) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
        1, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
} else if (sreg==opVenda) {
   if (sacao==opPesquisar)
      slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, TRUE,opTexto)
   else if (sacao==opListarTodos) {
      if (ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) == FALSE)
        cat(sprintf("%s\n",rotulo(sreg, 0)))
   }
}
}
#------------------------------------------------------------------------------
# Mostra a tela de alteração de senha do sistema e realiza a alteração.
#------------------------------------------------------------------------------
frmAlterarSenha <- function() {

cat(sprintf("%s%s\n",rotulo(opUsuario, 1), gg("tUsuario$login")))
nopcao = 1
bQuebra = FALSE
while (bQuebra==FALSE) {
   if (nopcao==1) {
       sSenhaAtual = digitaSenha("Senha Atual: ", 10)
       if (sSenhaAtual != gg("tUsuario$senha")) {
          cat(MSG_SENCONFERE)
          bQuebra = TRUE
       } else nopcao = 2
   } 
   else if (nopcao==2) {
       sNovaSenha = digitaSenha("Nova Senha: ", 10)
       sConfirmaSenha = digitaSenha("Confirma Senha: ", 10)
       if (sNovaSenha != sConfirmaSenha) {
          cat(MSG_SENCONFIRM)
          bQuebra = TRUE
       } else nopcao = 3
   } 
   else if (nopcao==3) {
       sres = pesqArq(tfUsuario, gg("tUsuario$login"), 1, 10, tamReg(opUsuario))
       if (sres == "")
         cat(MSG_LOGINENCON)
       else {
         ag("tUsuario$senha", sConfirmaSenha)
         subMenu(9,opUsuario)
         bQuebra = TRUE
       }
   } 
}
}
#------------------------------------------------------------------------------
# Executa uma ação de gravação de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
btnAcao <- function(sreg, sacao)
{
if (sreg==opAssunto) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opAutor) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opEditora) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opEndereco) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opIdioma) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opPais) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opProfissao) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
     escreveArq(tfProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opLivro) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opLivroAss) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opLivroAut) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opCliente) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opVenda) {
   if (sacao==opSalvarInclusao)
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if (sacao==opSalvarAlteracao)
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if (sacao==opConfirmaExclusao)
      escreveArq(tfVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
} else if (sreg==opUsuario) {
   if (sacao==opSalvarAlteracao)
      escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
}
}
#------------------------------------------------------------------------------
# Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
# nmenu - o número do menu
# sreg - o tipo de arquivo
#------------------------------------------------------------------------------
subMenu <- function(nmenu, sreg) {

bSOp = TRUE

 if (nmenu == 6) {
   while(bSOp) {
     menu(nmenu)
     opSubMenu = readline()
     if (opSubMenu=="1") frmCadastros(sreg, opNovo) 
     else if (opSubMenu=="2") frmCadastros(sreg, opPesquisar) 
     else if (opSubMenu=="3") bSOp = FALSE 
	   else cat(MSG_ERRO)
   }
 } 
 else if (nmenu == 7) {
   while(bSOp) {
     menu(nmenu)
     opSubMenu = readline()
     if (opSubMenu=="1") { 
       btnAcao(sreg, opSalvarInclusao) 
       bSOp = FALSE 
     } 
     else if (opSubMenu=="2") bSOp = FALSE 
	   else cat(MSG_ERRO)
   }
 } 
 else if (nmenu == 8) {
   while(bSOp) {
     menu(nmenu)
     opSubMenu = readline()     
     if (opSubMenu=="1") { 
       frmCadastros(sreg, opAlterar) 
       bSOp = FALSE 
     } 
     else if (opSubMenu=="2") { 
       frmCadastros(sreg, opExcluir) 
       bSOp = FALSE 
     } 
     else if (opSubMenu=="3") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 } 
 else if (nmenu == 9) {
   while(bSOp) {
     menu(nmenu)
     opSubMenu = readline()     
     if (opSubMenu=="1") { 
       btnAcao(sreg, opSalvarAlteracao) 
       bSOp = FALSE 
     } 
     else if (opSubMenu=="2") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 } 
 else if (nmenu == 10) {
   while(bSOp) {
     menu(nmenu)
     opCSubMenu = readline()     
     if ((opCSubMenu=="S") || (opCSubMenu=="s")) {
        btnAcao(sreg, opConfirmaExclusao)
        bSOp = FALSE
     } else if ((opCSubMenu=="N") || (opCSubMenu=="n")) bSOp = FALSE
     else cat(MSG_ERRO)
   }
 } 
 else if (nmenu == 12) {
   while(bSOp) {
     menu(nmenu)
     opSubMenu = readline()     
     if (opSubMenu=="1") frmConsultas(sreg, opPesquisar) 
     else if (opSubMenu=="2") frmConsultas(sreg, opListarTodos) 
     else if (opSubMenu=="3") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 } 
 else if (nmenu == 14) {
   while(bSOp) {
     menu(nmenu)
     opCSubMenu = readline()     
     if ((opCSubMenu=="S") || (opCSubMenu=="s")) {
        btnAcao(sreg, opSalvarInclusao)
        bSOp = FALSE
        ag("g_SalvarInclusao", TRUE)
     } else if ((opCSubMenu=="N") || (opCSubMenu=="n")) bSOp = FALSE
     else cat(MSG_ERRO)
   }
 } 
}
#------------------------------------------------------------------------------
# Seleciona o submenu e/ou a tela certa de acordo com número do menu.
# nmenu - o número do menu
#------------------------------------------------------------------------------
usaMenu <- function(num) {
 bSOp = TRUE
 if (num == 1) { # Cadastros
   while(bSOp) {
     menu(2)
     opSubMenu = readline()
     if (opSubMenu=="1") subMenu(6, opAssunto) 
     else if (opSubMenu=="2") subMenu(6, opAutor) 
     else if (opSubMenu=="3") subMenu(6, opEditora) 
     else if (opSubMenu=="4") subMenu(6, opEndereco) 
     else if (opSubMenu=="5") subMenu(6, opIdioma) 
     else if (opSubMenu=="6") subMenu(6, opPais) 
     else if (opSubMenu=="7") subMenu(6, opProfissao) 
     else if (opSubMenu=="8") subMenu(6, opCliente) 
     else if (opSubMenu=="9") subMenu(6, opLivro) 
     else if (opSubMenu=="10") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 } else if (num == 2) { # Pesquisas 
   while(bSOp) {
     menu(3)
     opSubMenu = readline()
     if (opSubMenu=="1") subMenu(12, opAssunto) 
     else if (opSubMenu=="2") subMenu(12, opAutor) 
     else if (opSubMenu=="3") subMenu(12, opEditora) 
     else if (opSubMenu=="4") subMenu(12, opEndereco) 
     else if (opSubMenu=="5") subMenu(12, opIdioma) 
     else if (opSubMenu=="6") subMenu(12, opPais) 
     else if (opSubMenu=="7") subMenu(12, opProfissao) 
     else if (opSubMenu=="8") subMenu(12, opCliente) 
     else if (opSubMenu=="9") subMenu(12, opLivro) 
     else if (opSubMenu=="10") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 } else if (num == 3) { # Vendas
   while(bSOp) {
     menu(4)
     opSubMenu = readline()
     if (opSubMenu=="1") subMenu(6, opVenda) 
     else if (opSubMenu=="2") subMenu(12, opVenda) 
     else if (opSubMenu=="3") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 } else if (num == 4) { # Opcoes
   while(bSOp) {
     menu(5)
     opSubMenu = readline()
     if (opSubMenu=="1") frmAlterarSenha() 
     else if (opSubMenu=="2") frmSobre() 
     else if (opSubMenu=="3") {
       menu(11)
       opSair = readline()
       if ((opSair=="S") || (opSair=="s")) {
          fechaArqs()
          quit()
       }
     } 
     else if (opSubMenu=="4") bSOp = FALSE 
     else cat(MSG_ERRO)
   }
 }
}
#------------------------------------------------------------------------------
# Mostra as entradas e as saídas do sistema.
# sreg - o tipo de arquivo
# slinha - o registro com os dados
# nOpcao - indica qual opção será mostrada
#------------------------------------------------------------------------------
mostrarDados <- function(sreg, slinha, nOpcao)
{ 
if (sreg==opAssunto) {
   if (nOpcao==1) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tAssunto$codigo")))
      ag("tAssunto$assunto", readline(rotulo(sreg, 2)))
   } 
   else if (nOpcao==2) {
      cat("Código     Assunto\n")
      cat("------     -------\n")
   } 
   else if (nOpcao==3) {
      ag("tAssunto$codigo", trim(copy(slinha, 1, 10)))
      ag("tAssunto$assunto", trim(copy(slinha, 11, 30)))
      cat(sprintf("%s %s\n",esp(gg("tAssunto$codigo"),10),esp(gg("tAssunto$assunto"),30)))
   } 
} else if (sreg==opAutor) {
   if (nOpcao==1) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tAutor$codigo")))
      ag("tAutor$autor", readline(rotulo(sreg, 2)))
   } 
   else if (nOpcao==2) {
      cat("Código     Autor\n")
      cat("------     -----\n")
   } 
   else if (nOpcao==3) {
      ag("tAutor$codigo", trim(copy(slinha, 1, 10)))
      ag("tAutor$autor", trim(copy(slinha, 11, 30)))
      cat(sprintf("%s %s\n",esp(gg("tAutor$codigo"),10),esp(gg("tAutor$autor"),30)))
   } 
} else if (sreg==opEditora) {
   if (nOpcao==1) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tEditora$codigo")))
      ag("tEditora$editora", readline(rotulo(sreg, 2)))
   } 
   else if (nOpcao==2) {
      cat("Código     Editora\n")
      cat("------     -------\n")
   } 
   else if (nOpcao==3) {
      ag("tEditora$codigo", trim(copy(slinha, 1, 10)))
      ag("tEditora$editora", trim(copy(slinha, 11, 50)))
      cat(sprintf("%s %s\n",esp(gg("tEditora$codigo"),10),esp(gg("tEditora$editora"),50)))
   }
} else if (sreg==opEndereco) {
   if (nOpcao==1) {
      cat(sprintf("%s%s",rotulo(sreg, 1), gg("tEndereco$codigo")))
      ag("tEndereco$logradouro", readline(rotulo(sreg, 2)))
      ag("tEndereco$bairro", readline(rotulo(sreg, 3)))
      ag("tEndereco$cep", readline(rotulo(sreg, 4)))
      ag("tEndereco$cidade", readline(rotulo(sreg, 5)))
      ag("tEndereco$estado", readline(rotulo(sreg, 6)))
   } 
   else if (nOpcao==3) {
      ag("tEndereco$codigo", trim(copy(slinha, 1, 10)))
      ag("tEndereco$logradouro", trim(copy(slinha, 11, 40)))
      ag("tEndereco$bairro", trim(copy(slinha, 51, 15)))
      ag("tEndereco$cep", trim(copy(slinha, 66, 8)))
      ag("tEndereco$cidade", trim(copy(slinha, 74, 30)))
      ag("tEndereco$estado", trim(copy(slinha, 104, 20)))
      cat("--------------------\n")
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tEndereco$codigo")))
      cat(sprintf("%s%s\n",rotulo(sreg, 2), gg("tEndereco$logradouro")))
      cat(sprintf("%s%s\n",rotulo(sreg, 3), gg("tEndereco$bairro")))
      cat(sprintf("%s%s\n",rotulo(sreg, 4), gg("tEndereco$cep")))
      cat(sprintf("%s%s\n",rotulo(sreg, 5), gg("tEndereco$cidade")))
      cat(sprintf("%s%s\n",rotulo(sreg, 6), gg("tEndereco$estado")))
   }
} else if (sreg==opIdioma) {
   if (nOpcao==1) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tIdioma$codigo")))
      ag("tIdioma$idioma", readline(rotulo(sreg, 2)))
   }  
   else if (nOpcao==2) {
      cat("Código     Idioma\n")
      cat("------     ------\n")
   } 
   else if (nOpcao==3) {
      ag("tIdioma$codigo", trim(copy(slinha, 1, 10)))
      ag("tIdioma$idioma", trim(copy(slinha, 11, 20)))
      cat(sprintf("%s %s\n",esp(gg("tIdioma$codigo"),10),esp(gg("tIdioma$idioma"),20)))
   }
} else if (sreg==opPais) {
   if (nOpcao==1) {
      ag("tPais$pais", readline(rotulo(sreg, 2)))
   } 
   else if (nOpcao==2) {
      cat("Código País\n")
      cat("------ ----\n")
   } 
   else if (nOpcao==3) {
      ag("tPais$codigo", trim(copy(slinha, 1, 3)))
      ag("tPais$pais", trim(copy(slinha, 4, 50)))
      cat(sprintf("%s    %s\n",esp(gg("tPais$codigo"),3),esp(gg("tPais$pais"),50)))
   }
} else if (sreg==opProfissao) {
   if (nOpcao==1) {
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tProfissao$codigo")))
      ag("tProfissao$profissao", readline(rotulo(sreg, 2)))
   } 
   else if (nOpcao==2) {
      cat("Código     Profissão\n")
      cat("------     ---------\n")
   } 
   else if (nOpcao==3) {
      ag("tProfissao$codigo", trim(copy(slinha, 1, 10)))
      ag("tProfissao$profissao", trim(copy(slinha, 11, 50)))
      cat(sprintf("%s %s\n",esp(gg("tProfissao$codigo"),10),
              esp(gg("tProfissao$profissao"),50)))
   }
} else if (sreg==opLivro) {
   if (nOpcao==1) {
      ag("tLivro$titulo", readline(rotulo(sreg, 2)))
      ag("tLivro$edicao", validaNumero(rotulo(sreg, 3), tLivro$edicao))
      ag("tLivro$anopubli", validaNumero(rotulo(sreg, 4), tLivro$anopubli))
      mostrarSubDados(opLivro, opEditora, FALSE)
      ag("tLivro$volume", validaNumero(rotulo(sreg, 6), tLivro$volume))
      mostrarSubDados(opLivro, opIdioma, FALSE)
      ag("tLivro$npaginas", validaNumero(rotulo(sreg, 8), tLivro$npaginas))
      ag("tLivro$preco", validaNumero(rotulo(sreg, 9), tLivro$preco))
      ag("tLivro$qtdestoque", validaNumero(rotulo(sreg, 10), tLivro$qtdestoque))
   } 
   else if (nOpcao==3) {
      ag("tLivro$isbn", trim(copy(slinha, 1, 13)))
      ag("tLivro$titulo", trim(copy(slinha, 14, 50)))
      ag("tLivro$edicao", trim(copy(slinha, 64, 10)))
      ag("tLivro$anopubli", trim(copy(slinha, 74, 10)))
      ag("tLivro$codeditora", trim(copy(slinha, 84, 10)))
      ag("tLivro$volume", trim(copy(slinha, 94, 10)))
      ag("tLivro$codidioma", trim(copy(slinha, 104, 10)))
      ag("tLivro$npaginas", trim(copy(slinha, 114, 10)))
      ag("tLivro$preco", trim(copy(slinha, 124, 10)))
      ag("tLivro$qtdestoque", trim(copy(slinha, 134, 10)))
      cat("--------------------\n")
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tLivro$isbn")))
      cat(sprintf("%s%s\n",rotulo(sreg, 2), gg("tLivro$titulo")))
      cat(sprintf("%s%s\n",rotulo(sreg, 3), gg("tLivro$edicao")))
      cat(sprintf("%s%s\n",rotulo(sreg, 4), gg("tLivro$anopubli")))
      cat(sprintf("%s%s\n",rotulo(sreg, 5), gg("tLivro$codeditora")))
      mostrarSubDados(opLivro, opEditora, TRUE)
      cat(sprintf("%s%s\n",rotulo(sreg, 6), gg("tLivro$volume")))
      cat(sprintf("%s%s\n",rotulo(sreg, 7), gg("tLivro$codidioma")))
      mostrarSubDados(opLivro, opIdioma, TRUE)
      cat(sprintf("%s%s\n",rotulo(sreg, 8), gg("tLivro$npaginas")))
      cat(sprintf("%s%s\n",rotulo(sreg, 9), gg("tLivro$preco")))
      cat(sprintf("%s%s\n",rotulo(sreg, 10), gg("tLivro$qtdestoque")))
      ListarRegLigados(tfLivroAss, opLivroAss, 1, 13, 14, 10, gg("tLivro$isbn"),
                       tfAssunto, opAssunto, 1, 4)
      ListarRegLigados(tfLivroAut, opLivroAut, 1, 13, 14, 10, gg("tLivro$isbn"),
                       tfAutor, opAutor, 1, 4)
  }
} else if (sreg==opCliente) {
   if (nOpcao==1) {
      ag("tCliente$nome", readline(rotulo(sreg, 2)))
      ag("tCliente$email", readline(rotulo(sreg, 3)))
      ag("tCliente$identidade", readline(rotulo(sreg, 4)))
      ag("tCliente$sexo", readline(rotulo(sreg, 5)))
      ag("tCliente$telefone", readline(rotulo(sreg, 6)))
      ag("tCliente$dtnascimento", 
          validaDataHora(rotulo(sreg, 7), tCliente$dtnascimento, TRUE))
      mostrarSubDados(opCliente, opEndereco, FALSE)
      mostrarSubDados(opCliente, opPais, FALSE)
      mostrarSubDados(opCliente, opProfissao, FALSE)
   } 
   else if (nOpcao==3) {
      ag("tCliente$cpf", trim(copy(slinha, 1, 14)))
      ag("tCliente$nome", trim(copy(slinha, 15, 30)))
      ag("tCliente$email", trim(copy(slinha, 45, 30)))
      ag("tCliente$identidade", trim(copy(slinha, 75, 10)))
      ag("tCliente$sexo", trim(copy(slinha, 85, 1)))
      ag("tCliente$telefone", trim(copy(slinha, 86, 17)))
      ag("tCliente$dtnascimento", trim(copy(slinha, 103, 10)))
      ag("tCliente$codendereco", trim(copy(slinha, 113, 10)))
      ag("tCliente$codpais", trim(copy(slinha, 123, 3)))
      ag("tCliente$codprofissao", trim(copy(slinha, 126, 10)))
      cat("--------------------\n")
      cat(sprintf("%s%s\n",rotulo(sreg, 1), gg("tCliente$cpf")))
      cat(sprintf("%s%s\n",rotulo(sreg, 2), gg("tCliente$nome")))
      cat(sprintf("%s%s\n",rotulo(sreg, 3), gg("tCliente$email")))
      cat(sprintf("%s%s\n",rotulo(sreg, 4), gg("tCliente$identidade")))
      cat(sprintf("%s%s\n",rotulo(sreg, 5), gg("tCliente$sexo")))
      cat(sprintf("%s%s\n",rotulo(sreg, 6), gg("tCliente$telefone")))
      cat(sprintf("%s%s\n",rotulo(sreg, 7), gg("tCliente$dtnascimento")))
      cat(sprintf("%s%s\n",rotulo(sreg, 8), gg("tCliente$codendereco")))
      mostrarSubDados(opCliente, opEndereco, TRUE)
      cat(sprintf("%s%s\n",rotulo(sreg, 9), gg("tCliente$codpais")))
      mostrarSubDados(opCliente, opPais, TRUE)
      cat(sprintf("%s%s\n",rotulo(sreg, 10), gg("tCliente$codprofissao")))
      mostrarSubDados(opCliente, opProfissao, TRUE)
  }
} else if (sreg==opVenda) {
   if (nOpcao==1) mostrarSubDados(opVenda,opVenda, FALSE) 
   else if (nOpcao==2) {
      cat("DataHoraVenda       CPF            ISBN          PreçoVenda\n")
      cat("-------------       ---            ----          ----------\n")
   } 
   else if (nOpcao==3) {
      ag("tVenda$dthrvenda", trim(copy(slinha, 1, 19)))
      ag("tVenda$cpf", trim(copy(slinha, 20, 14)))
      ag("tVenda$isbn", trim(copy(slinha, 34, 13)))
      ag("tVenda$precovenda", trim(copy(slinha, 47, 10)))
      cat(sprintf("%s %s %s %s\n",esp(gg("tVenda$dthrvenda"),19),esp(gg("tVenda$cpf"),14),
      esp(gg("tVenda$isbn"),13),esp(gg("tVenda$precovenda"),10)))
   }
}
}
#------------------------------------------------------------------------------
# Mostra as sub informções de entrada e de saída.
# sreg - o tipo de arquivo
# ssubreg - o subtipo de arquivo
# bSoMostrar - se vai só mostrar na saída
#------------------------------------------------------------------------------
mostrarSubDados <- function(sreg, ssubreg, bSoMostrar) {

nMaxTentativas = 3
if (sreg==opLivro) {
  if (ssubreg==opEditora) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfEditora,gg("tLivro$codeditora"),1,10,tamReg(opEditora))
    else
       sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro$codeditora,
                  nMaxTentativas,FALSE,opNumero)
    if (nchar(sRegistro) > 0) {
      ag("tLivro$codeditora", trim(copy(sRegistro,1,10)))
      cat(sprintf(" %s",rotulo(opEditora, 2)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
    }
  } else if (ssubreg==opIdioma) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfIdioma, gg("tLivro$codidioma"), 1, 10,tamReg(opIdioma))
    else
       sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro$codidioma,
                  nMaxTentativas,FALSE,opNumero)
    if (nchar(sRegistro) > 0) {
      ag("tLivro$codidioma", trim(copy(sRegistro,1,10)))
      cat(sprintf(" %s",rotulo(opIdioma, 2)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
    }
  }
} else if (sreg==opCliente) {
  if (ssubreg==opEndereco) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfEndereco, gg("tCliente$codendereco"), 1, 10,
                  tamReg(opEndereco))
    else
       sRegistro = validaEntrada(tfEndereco,ssubreg,1,tCliente$codendereco,
                  nMaxTentativas,FALSE,opNumero)
    if (nchar(sRegistro) > 0) {
      ag("tCliente$codendereco", trim(copy(sRegistro,1,10)))
      cat(sprintf(" %s",rotulo(opEndereco, 2)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
      cat(sprintf(" %s",rotulo(opEndereco, 3)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
      cat(sprintf(" %s",rotulo(opEndereco, 4)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
      cat(sprintf(" %s",rotulo(opEndereco, 5)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
      cat(sprintf(" %s",rotulo(opEndereco, 6)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
    }
  } else if (ssubreg==opPais) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfPais, gg("tCliente$codpais"), 1, 3, tamReg(opPais))
    else
       sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente$codpais,
                  nMaxTentativas,FALSE,opTexto)
    if (nchar(sRegistro) > 0) {
      ag("tCliente$codpais", trim(copy(sRegistro,1,3)))
      cat(sprintf(" %s",rotulo(opPais, 2)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
    }
  } else if (ssubreg==opProfissao) {
    if (bSoMostrar)
       sRegistro = pesqArq(tfProfissao, gg("tCliente$codprofissao"), 1, 10,
                  tamReg(opProfissao))
    else
       sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente$codprofissao,
                  nMaxTentativas,FALSE,opNumero)
    if (nchar(sRegistro) > 0) {
      ag("tCliente$codprofissao", trim(copy(sRegistro,1,10)))
      cat(sprintf(" %s",rotulo(opProfissao, 2)))
      cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
    }
  }
} else if (sreg==opVenda) {
  sRegistro = pesqArq(tfLivro, gg("tVenda$isbn"), 1, 13, tamReg(opLivro))
  if (nchar(sRegistro) > 0) {
    cat(sprintf(" %s",rotulo(opLivro, 2))) # Titulo 
    cat(sprintf("%s\n",copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))))
    cat(sprintf(" %s",rotulo(opLivro, 9))) # Preco 
    sPreco = copy(sRegistro, gg("g_nPosChave"), gg("g_nTamChave"))
    ag("g_nPreco", as.real(sPreco))
    cat(sprintf("%s\n",sPreco))
  }
}
}
#------------------------------------------------------------------------------
# Realiza os cadastros dos arquivos que se ligam a outros arquivos.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
# sCodigo - um das chaves do arquivo de ligação
#------------------------------------------------------------------------------
frmCadLigados <- function(sreg, sacao, sCodigo) {

if (sacao==opNovo) {
  nCont = 1
  if (sreg==opLivroAss) {
    sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",sQtd)
    nQtd = as.integer(sQtd)
    seek(tfLivroAss, 0, "start", "read")
    while (nCont <= nQtd) {
      ag("tLivroAss$isbn", sCodigo)
      ag("tLivroAss$codassunto", readline(rotulo(opLivroAss, 2)))
      slinha = pesqArq(tfAssunto, gg("tLivroAss$codassunto"),1,10,tamReg(opAssunto))
      cat(sprintf(" %s",rotulo(opAssunto, 2)))
      cat(sprintf("%s\n",copy(slinha, gg("g_nPosChave"), gg("g_nTamChave"))))
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg))
      subMenu(14, sreg)
      nCont = nCont + 1
    }
  } else if (sreg==opLivroAut) {
    sQtd = validaNumero("Quantos autores quer cadastrar?: ",sQtd)
    nQtd = as.integer(sQtd)
    seek(tfLivroAut, 0, "start", "read")
    while (nCont <= nQtd) {
      ag("tLivroAut$isbn", sCodigo)
      ag("tLivroAut$codautor", readline(rotulo(opLivroAut, 2)))
      slinha = pesqArq(tfAutor, gg("tLivroAut$codautor"),1,10,tamReg(opAutor))
      cat(sprintf(" %s",rotulo(opAutor, 2)))
      cat(sprintf("%s\n",copy(slinha, gg("g_nPosChave"), gg("g_nTamChave"))))
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg))
      subMenu(14, sreg)
      nCont = nCont + 1
    }
  } else if (sreg==opVenda) {
    sQtd = validaNumero("Quantos livros quer vender?: ",sQtd)
    nQtd = as.integer(sQtd)
    nTotalPreco = 0
    while (nCont <= nQtd) {
      slinha = validaEntrada(tfLivro,opLivro,1,tVenda.isbn,3,FALSE,opTexto)
      if (nchar(slinha) > 0) {
        ag("tVenda$isbn", trim(copy(slinha,1,13)))
        if (validaISBN(gg("tVenda$isbn"))) {
          mostrarDados(sreg, "", 1)
          ag("tLivro$qtdestoque", trim(copy(slinha,134,10)))
          nQtdEstoque = as.integer(gg("tLivro$qtdestoque"))
          if (nQtdEstoque > 0) {
             nTotalPreco = nTotalPreco + gg("g_nPreco")
             sPreco = as.character(gg("g_nPreco"))
             ag("tVenda$precovenda", sPreco)
             ag("g_SalvarInclusao", FALSE)
             subMenu(14, sreg)
             if (gg("g_SalvarInclusao")==TRUE) {
                slinha = pesqArq(tfLivro, gg("tVenda$isbn"), 1, 13, tamReg(opLivro))
                if (nchar(slinha) > 0) {
                   nQtdEstoque = nQtdEstoque-1
                   ag("tLivro$qtdestoque", as.character(nQtdEstoque))
                   slinha=paste(copy(slinha,1,133),esp(gg("tLivro$qtdestoque"),10),sep="")
                   escreveArq(tfLivro, slinha, "", "")
                }
             }
             nCont = nCont + 1
          } else cat(MSG_SEMESTOQUE)
        } else cat(MSG_ISBNINV)
      }
    }
    nTotalPreco = as.real(sTotalPreco)
    cat(sprintf("Total de %s%f\n",rotulo(sreg,4),nTotalPreco))
  }
} else if (sacao==opExcluir) {
  if (sreg==opLivroAss) 
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo)
  else if (sreg==opLivroAut) 
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo)
}
}
#------------------------------------------------------------------------------
# Realiza a exclusão dos arquivos de ligação.
# sArq - o arquivo de ligação
# sreg - o tipo de arquivo de ligação
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# sChave - a chave a ser excluida
#------------------------------------------------------------------------------
ExcluirRegLigados <- function(sArq, sreg, nPosChave, nTamChave, sChave) {
  slinha = "" 
  seek(sArq, 0, "start", "read")
  while (length(slinha)!=0) {
    slinha = readLines(sArq, 1)
    if (length(slinha)!=0) {
      sCodigo = trim(copy(slinha,nPosChave,nTamChave))
      if (sCodigo==sChave)
         btnAcao(sreg,opConfirmaExclusao)
    }
  }
}
#------------------------------------------------------------------------------
# Parte inicial do código
#------------------------------------------------------------------------------
main <- function()
{
# if ((argc > 0) && (strcmp(argv[0],"-cria")==0))
#   abrecriaArqs(FALSE)
# else {
   frmSplash()
   abrecriaArqs(TRUE)
   if (frmLogin()) {
     bopcao = TRUE
     while(bopcao) {
       menu(1)
       opmenu = readline()
       if ((opmenu=="C") || (opmenu=="c")) usaMenu(1)
       else if ((opmenu=="P") || (opmenu=="p")) usaMenu(2)
       else if ((opmenu=="V") || (opmenu=="v")) usaMenu(3)
       else if ((opmenu=="O") || (opmenu=="o")) usaMenu(4)
       else cat(MSG_ERRO)
     }
   } else {
     fechaArqs()
     quit()
   }
# }
}

main()

