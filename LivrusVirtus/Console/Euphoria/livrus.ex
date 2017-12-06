#!/home/euphoria/bin/exu
-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem euphoria.
-- ----------------------------------------------------------------------------
-- programa Livrus
include get.e
include file.e

constant CODIGO = 1, ASSUNTO = 2
sequence tAssunto
tAssunto = {{CODIGO,""}, {ASSUNTO,""}}

constant AUTOR = 2
sequence tAutor
tAutor = {{CODIGO,""}, {AUTOR,""}}

constant EDITORA = 2
sequence tEditora
tEditora = {{CODIGO,""}, {EDITORA,""}}

constant IDIOMA = 2
sequence tIdioma
tIdioma = {{CODIGO,""}, {IDIOMA,""}}

constant LOGIN = 1, SENHA = 2
sequence tUsuario
tUsuario = {{LOGIN,""}, {SENHA,""}}

constant PAIS = 2
sequence tPais
tPais = {{CODIGO,""}, {PAIS,""}}

constant PROFISSAO = 2
sequence tProfissao
tProfissao = {{CODIGO,""}, {PROFISSAO,""}}

constant ISBN = 1, TITULO = 2, EDICAO = 3, ANOPUBLI = 4, CODEDITORA = 5,
         VOLUME = 6, CODIDIOMA = 7, NPAGINAS = 8, PRECO = 9, QTDESTOQUE = 10
sequence tLivro
tLivro = {{ISBN,""}, {TITULO,""}, {EDICAO,""}, {ANOPUBLI,""}, {CODEDITORA,""}, 
       {VOLUME,""}, {CODIDIOMA,""}, {NPAGINAS,""}, {PRECO,""}, {QTDESTOQUE,""}}

constant CODASSUNTO = 2
sequence tLivroAss
tLivroAss = {{ISBN,""}, {CODASSUNTO,""}}

constant CODAUTOR = 2
sequence tLivroAut
tLivroAut = {{ISBN,""}, {CODAUTOR,""}}

constant CPF = 1, NOME = 2, EMAIL = 3, IDENTIDADE = 4, SEXO = 5, TELEFONE = 6,
         DTNASCIMENTO = 7, CODENDERECO = 8, CODPAIS = 9, CODPROFISSAO = 10
sequence tCliente
tCliente = {{CPF,""}, {NOME,""}, {EMAIL,""}, {IDENTIDADE,""}, {SEXO,""}, 
           {TELEFONE,""}, {DTNASCIMENTO,""}, {CODENDERECO,""}, {CODPAIS,""}, 
           {CODPROFISSAO,""}}

constant LOGRADOURO = 2, BAIRRO = 3, CEP = 4, CIDADE = 5, ESTADO = 6
sequence tEndereco
tEndereco = {{CODIGO,""}, {LOGRADOURO,""}, {BAIRRO,""}, {CEP,""}, 
            {CIDADE,""}, {ESTADO,""}}

constant DTHRVENDA = 1, CPFVENDA = 2, ISBNVENDA = 3, PRECOVENDA = 4
sequence tVenda
tVenda = {{DTHRVENDA,""}, {CPFVENDA,""}, {ISBNVENDA,""}, {PRECOVENDA,""}}

-- ctTipo 
constant opTexto = 1, opNumero = 2, opData = 3, opDataHora = 4, opSenha = 5
type ctTipo(integer x)
  return x=opTexto or x=opNumero or x=opData or x=opDataHora or x=opSenha
end type

-- ctArqs 
constant opAssunto = 1, opAutor = 2, opEditora = 3, opEndereco = 4, 
         opIdioma = 5, opPais = 6, opProfissao = 7, opCliente = 8, opLivro = 9, 
         opLivroAss = 10, opLivroAut = 11, opUsuario = 12, opVenda = 13
type ctArqs(integer x)
  return x=opAssunto or x=opAutor or x=opEditora or x=opEndereco or
         x=opIdioma or x=opPais or x=opProfissao or x=opCliente or x=opLivro or
         x=opLivroAss or x=opLivroAut or x=opUsuario or x=opVenda
end type

-- ctAcao 
constant opNovo = 1, opAlterar = 2, opPesquisar = 3, opSalvarInclusao = 4,
         opSalvarAlteracao = 5, opExcluir = 6, opConfirmaExclusao = 7, 
         opListarTodos = 8
type ctAcao(integer x)
  return x=opNovo or x=opAlterar or x=opPesquisar or x=opSalvarInclusao or
         x=opSalvarAlteracao or x=opExcluir or x=opConfirmaExclusao or
         x=opListarTodos
end type

constant STDIN = 0, STDOUT = 1, STDERR = 2
constant FALSE = 0, TRUE = 1

constant CRLF = "\n" -- windows
constant TAM_CRLF = 1
-- constant CRLF = "\n"
-- constant TAM_CRLF = 1 -- unix
-- constant CRLF = "\r"
-- constant TAM_CRLF = 1 -- macintosh

constant ARQ_ABRE = "u"
constant ARQ_CRIA = "w"

constant QTD_MAX_LINHA = 18

constant MSG_PRESS = "pressione para continuar..."
constant MSG_OPCAO = "Escolha uma opção: "
constant MSG_ISBNINV = "ISBN inválido!\n"
constant MSG_CPFINV = "CPF inválido!\n"
constant MSG_SENCONFERE = "senha não confere com a senha atual!\n"
constant MSG_SENCONFIRM = "nova senha não confere com a senha confirmada!\n"
constant MSG_LOGINENCON = "login não encontrado!\n"
constant MSG_SEMESTOQUE = "livro não existe no estoque!\n"
constant MSG_NUMINV = "Número inválido ou menor do que 0.01!\n"
constant MSG_DATAINV = "Data inválida!, formato correto (dd/mm/yyyy)\n"
constant MSG_DTHRINV = 
                "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)\n"
constant MSG_ARQERRO = "Erro: O arquivo não pode ser aberto."
constant MSG_ERRO = "Erro: opção inválida digite de novo.\n"

constant MSG_REGINC = "registro incluido!\n"
constant MSG_REGNINC = "registro não incluido!\n"
constant MSG_REGALT = "registro alterado!\n"
constant MSG_REGNALT = "registro não alterado!\n"
constant MSG_REGEXC = "registro excluido!\n"
constant MSG_REGNEXC = "registro não excluido!\n"
constant MSG_REGEXST = "registro já existe!\n"

constant ARQ_ASSUNTO = "assunto.dat"
constant ARQ_AUTOR = "autor.dat"
constant ARQ_EDITORA = "editora.dat"
constant ARQ_IDIOMA = "idioma.dat"
constant ARQ_USUARIO = "usuario.dat"
constant ARQ_PAIS = "pais.dat"
constant ARQ_PROFISSAO = "profissao.dat"
constant ARQ_LIVRO = "livro.dat"
constant ARQ_LIVASS = "livroass.dat"
constant ARQ_LIVAUT = "livroaut.dat"
constant ARQ_CLIENTE = "cliente.dat"
constant ARQ_ENDERECO = "endereco.dat"
constant ARQ_VENDA = "venda.dat"

constant TAM_ASSUNTO = 40
constant TAM_AUTOR = 40
constant TAM_EDITORA = 60
constant TAM_IDIOMA = 30
constant TAM_USUARIO = 20
constant TAM_PAIS = 53
constant TAM_PROFISSAO = 60
constant TAM_LIVRO = 143
constant TAM_LIVASS = 23
constant TAM_LIVAUT = 23
constant TAM_CLIENTE = 135
constant TAM_ENDERECO = 123
constant TAM_VENDA = 56

type tarquivo(integer x)
  return x >= -1
end type

type boolean(integer x)
  return x = FALSE or x = TRUE
end type

tarquivo tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, tfPais, 
    tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente, tfUsuario, tfVenda

-- variaveis gerais

boolean bopcao
sequence opmenu
atom g_nPreco
integer g_nPosChave, g_nTamChave
integer g_SalvarInclusao

-- --- Rotinas básicas --------------------------------------------------------

-- ----------------------------------------------------------------------------
-- Função que retorna um pedaço de uma string.
-- str - indica a string
-- ini - indica a posicao inicial do pedaco
-- tam - indica o tamanho do pedaco
-- retorna - o pedaço da string
-- ----------------------------------------------------------------------------
function copy(sequence str, integer ini, integer tam)
  return str[ini..(ini+tam-1)]
end function
-- ----------------------------------------------------------------------------
-- Retira os espaços em branco antes ou depois do texto.
-- sTexto - o texto a ser retirado os espaços em branco
-- retorna - o texto sem os espaços em branco
-- ----------------------------------------------------------------------------
function trim(sequence sTexto)
integer ncont, nPosIni, nPosFim
sequence sret
integer bQuebra

nPosIni=0
nPosFim=0
ncont=1
bQuebra=FALSE
while (ncont<=length(sTexto)) and (bQuebra=FALSE) do
  if sTexto[ncont]!=' ' then
     nPosIni=ncont
     bQuebra=TRUE
  end if
  ncont=ncont+1
end while
ncont=length(sTexto)
bQuebra=FALSE
while (ncont >= 1) and (bQuebra=FALSE) do
  if sTexto[ncont]!=' ' then
     nPosFim=ncont
     bQuebra=TRUE
  end if
  ncont=ncont-1
end while
sret=copy(sTexto,nPosIni,(nPosFim-nPosIni)+1)
return sret
end function
-- ----------------------------------------------------------------------------
-- convert uma string num numero somente positivo
-- nstr - a string
-- retorna - o numero
-- ----------------------------------------------------------------------------
-- function StrToNum(sequence str)
-- atom nret
-- object num
--   num = value(str)
--   if num[1] = GET_SUCCESS then
--     nret = num[2]
--     return nret
--   else
--     return -1
--   end if
-- end function

function StrToNum(sequence str)
integer nnum, ndec, bponto
atom nret

bponto = FALSE
nret = 0
ndec = length(str)
  for ncont = 1 to length(str) do
    if str[ncont] = 48 then nnum = 0
    elsif str[ncont] = 49 then nnum = 1
    elsif str[ncont] = 50 then nnum = 2
    elsif str[ncont] = 51 then nnum = 3
    elsif str[ncont] = 52 then nnum = 4
    elsif str[ncont] = 53 then nnum = 5
    elsif str[ncont] = 54 then nnum = 6
    elsif str[ncont] = 55 then nnum = 7
    elsif str[ncont] = 56 then nnum = 8
    elsif str[ncont] = 57 then nnum = 9
    elsif str[ncont] = 46 then 
      nret = nret / power(10, ndec)
      ndec = 0 -- ponto
    else 
      nret = -1
      exit
    end if

    if str[ncont] != 46 then    
      ndec = ndec - 1
      nret = nret + (nnum * power(10, ndec))
    end if

  end for
return nret
end function
-- ----------------------------------------------------------------------------
-- converte um numero numa string
-- nstr - o numero
-- retorna - a string
-- ----------------------------------------------------------------------------
function NumToStr(atom nstr)
sequence str, sret
atom ndec, nfloat, ncont
integer nnum, ncasas, bnegativo

nfloat = nstr
if floor(nfloat) = nstr then
  ncasas = 0
else
  ncasas = 1
  while TRUE do
    ncont = nstr * power(10,ncasas)
    nfloat = nfloat * 10
    if ncont = floor(nfloat) then
      exit
    else
      ncasas = ncasas + 1 
    end if
  end while
end if
if nstr < 0 then
  nstr = nstr * (-1)
  bnegativo = TRUE
else
  bnegativo = FALSE
end if
ndec = nstr * power(10,ncasas)
str = {}
if nstr = 0 then
  str = append(str, 48)
else
  while ndec >= 1 do
    nnum = remainder(ndec, 10)
    if nnum = 0 then str = prepend(str, 48)
    elsif nnum = 1 then str = prepend(str, 49)
    elsif nnum = 2 then str = prepend(str, 50)
    elsif nnum = 3 then str = prepend(str, 51)
    elsif nnum = 4 then str = prepend(str, 52)
    elsif nnum = 5 then str = prepend(str, 53)
    elsif nnum = 6 then str = prepend(str, 54)
    elsif nnum = 7 then str = prepend(str, 55)
    elsif nnum = 8 then str = prepend(str, 56)
    elsif nnum = 9 then str = prepend(str, 57)
    end if
    ndec = ((ndec - nnum) / 10)
  end while
end if
sret = {}
if ncasas > 0 then  
  nnum = length(str)-ncasas
  if nnum > 0 then
    sret = copy(str, 1, nnum) & "." & copy(str, nnum+1, ncasas)
  else
    sret = "0" & "." & repeat('0',ncasas-1) & str
  end if
else
  sret = str
end if
if bnegativo = TRUE then
  sret = "-" & sret
end if
return sret
end function
-- ----------------------------------------------------------------------------
-- Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
-- sTexto - o texto
-- nTam - tamanho máximo do texto
-- retorna - o texto com espaços em branco a mais
-- ----------------------------------------------------------------------------
function esp(sequence sTexto, integer nTam)
  return sTexto & repeat(' ',nTam-length(sTexto))
end function
-- ----------------------------------------------------------------------------
-- Faz uma pesquisa relativa de um texto através de um valor chave.
-- sTexto - o texto
-- sChave - a chave a ser pesquisada
-- retorna - se achou ou não a chave dentro do texto
-- ----------------------------------------------------------------------------
function strRelativa(sequence sTexto, sequence sChave)
  if match(sChave, sTexto) != 0 then
    return TRUE
  else
    return FALSE
  end if
end function
-- ----------------------------------------------------------------------------
-- Calcula o modulo11 de um valor qualquer.
-- svalor - a mstring com o número a ser calculado
-- sdig - dígito do valor a ser calculado
-- retorna - o dígito correto
-- ----------------------------------------------------------------------------
function modulo11(sequence svalor, integer ndig)
integer ncont, nsoma, nvalor, npos
sequence sres, slocal

sres = ""
slocal = ""
ncont=1
while ncont <= 11 do
  slocal=copy(svalor,ncont,1) & slocal
  ncont=ncont+1
end while
nsoma=0
if ndig=1 then
  ncont=3
else
  ncont=2
end if
npos=2
while ncont <= 11 do
  sres=copy(slocal,ncont,1)
  nvalor = StrToNum(sres)
  nsoma=nsoma + (nvalor * npos)
  ncont=ncont+1
  npos=npos+1
end while
nsoma=(11 - remainder(nsoma, 11))

if nsoma > 9 then
  return 0
else
  return nsoma
end if
end function
-- ----------------------------------------------------------------------------
-- Validação de um número de CPF qualquer.
-- cpf - a mstring com o número do CPF
-- retorna - se é valido ou não
-- ----------------------------------------------------------------------------
function validaCPF(sequence cpf)
sequence scpf, sres
integer nvalor1, nvalor2

if (length(cpf)=14) then
  scpf=copy(cpf,1,3) & copy(cpf,5,3) & copy(cpf,9,3) & copy(cpf,13,2)
  sres=copy(cpf,13,1)
  nvalor1 = StrToNum(sres)
  sres=copy(cpf,14,1)
  nvalor2 = StrToNum(sres)
  if ((modulo11(scpf,1)=nvalor1) and (modulo11(scpf,2)=nvalor2)) then
    return TRUE
  else
    return FALSE
  end if
else
  return FALSE
end if
end function
-- ----------------------------------------------------------------------------
-- Validação de um número ISBN qualquer.
-- isbn - a mstring com o número do ISBN
-- retorna - se é valido ou não
-- ----------------------------------------------------------------------------
function validaISBN(sequence isbn)
sequence snum, sdigito, sisbn
integer nvalor, nsoma

if length(isbn)=13 then
  sdigito = copy(isbn, length(isbn), 1)
  sisbn=""
  for ncont=1 to length(isbn)-1 do
    if equal(copy(isbn,ncont,1),"-")=FALSE then
      sisbn=sisbn & copy(isbn,ncont,1)
    end if
  end for
  if equal(sdigito, "X") then
    nsoma = 10
  else
    nvalor = StrToNum(sdigito)
    nsoma = nvalor
  end if
  for ncont=1 to 9 do
    snum = copy(sisbn, ncont, 1)
    nvalor = StrToNum(snum)
    nsoma=nsoma + (nvalor * (11 - ncont))
  end for
  if remainder(nsoma, 11) = 0 then
    return TRUE
  else
    return FALSE
  end if
else
  return FALSE
end if
end function
------------------------------------------------------------------------------
-- digita um valor numerico ou uma string, necessário para retirar 
-- a nova linha das funções prompt_string e prompt_number
-- sRotulo - mostra o rotulo de entrada
-- bNum - se vai ser numero ou texto
-- retorna - o valor digitado
-- ----------------------------------------------------------------------------
function digita(sequence sRotulo, boolean bNum)
object linha 
  puts(STDOUT, sRotulo)
  linha = gets(STDIN)
  puts(STDOUT, "\r") 
  linha = linha[1..length(linha)-1]
  if bNum then
    linha = value(linha)
    if linha[1] = GET_SUCCESS then
      return linha[2]
    else
      return -1
    end if
  else
    return linha
  end if
end function
------------------------------------------------------------------------------
-- Esconde a digitação da senha
-- retorna - a senha digitada
-- ----------------------------------------------------------------------------
function digitaSenha(sequence sRotulo, integer nTamSenha)
sequence sSenha
integer sLetra, ncont

puts(STDOUT, sRotulo)
-- sSenha = digita(sRotulo, FALSE)
  ncont = 0
  sSenha={}
  sLetra=0
  while((sLetra!='\r') and (ncont < nTamSenha)) do
    sLetra=wait_key()
    if sLetra!='\r' then
      sSenha= append(sSenha, sLetra)
    end if
    ncont=ncont+1
  end while
return sSenha
end function
-- ----------------------------------------------------------------------------
-- Validação de um número qualquer.
-- sRotulo - o texto antes de se digitar o número
-- sNumero - a mstring com o valor do número
-- retorna - o sNumero
-- ----------------------------------------------------------------------------
function validaNumero(sequence sRotulo, sequence sNumero)
atom nnum
integer nStatus 

nStatus=-1
while (nStatus!=0) do
  nnum = digita(sRotulo, TRUE)
  if nnum < 0.01 then
    puts(STDERR, MSG_NUMINV)
  else
    nStatus = 0
  end if
end while
sNumero = NumToStr(nnum)
return sNumero
end function
-- ----------------------------------------------------------------------------
-- Validação de uma data ou data/hora qualquer.
-- sRotulo - o texto antes de se digitar a data/hora
-- sDataHora - a mstring com o valor da data/hora
-- bSoData - indica se vai validar somente uma data sem a hora
-- retorna - a sDataHora
-- ----------------------------------------------------------------------------
function validaDataHora(sequence sRotulo, sequence sDataHora, 
	boolean bSoData)
boolean bvalida, bdatavalida, bhoravalida
sequence sdia, smes, sano, shora, smin, sseg
integer ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam

bvalida=FALSE
bdatavalida=FALSE
bhoravalida=FALSE
nudiames=0

if bSoData=TRUE then ntam=10
else ntam=19
end if
while (bvalida=FALSE) do
  sDataHora = digita(sRotulo, FALSE)
  if length(sDataHora)=ntam then
    sdia=copy(sDataHora,1,2)
    ndia=StrToNum(sdia)
    smes=copy(sDataHora,4,2)
    nmes=StrToNum(smes)
    sano=copy(sDataHora,7,4)
    nano=StrToNum(sano)
  
    if (nano >= 1) and (nano <= 9999) then
      if (nmes >= 1) and (nmes <= 31) then
          if nmes=1 or nmes=3 or nmes=5 or nmes=7 or 
	     nmes=8 or nmes=10 or nmes=12 then 
             nudiames=31
          elsif nmes=2 then
             -- ano bisexto
             if remainder(nano, 4)=0 then nudiames=29
             else nudiames=28
             end if
          elsif nmes=4 or nmes=6 or nmes=9 or nmes=11 then 
             nudiames=30
          end if
          if (ndia >=1) and (ndia <=nudiames) then
             bdatavalida=TRUE
          end if
      end if
    end if
  
    if bSoData=TRUE then
       if bdatavalida=TRUE then bvalida=TRUE
       else puts(STDERR, MSG_DATAINV)
       end if
    else
      if bdatavalida=TRUE then
          shora=copy(sDataHora,12,2)
          nhora=StrToNum(shora)
          smin=copy(sDataHora,15,2)
          nmin=StrToNum(smin)
          sseg=copy(sDataHora,18,2)
          nseg=StrToNum(sseg)
  
          if (nhora >= 0) and (nhora <= 23) then
            if (nmin >= 0) and (nmin <= 59) then
              if (nseg >= 0) and (nseg <= 59) then
                 bhoravalida=TRUE
              end if
            end if
          end if
  
          if bhoravalida=TRUE then bvalida=TRUE
          else puts(STDERR, MSG_DTHRINV)
          end if 
      else
        puts(STDERR, MSG_DTHRINV)
      end if
    end if
  else
    if bSoData=TRUE then puts(STDERR, MSG_DATAINV)
    else puts(STDERR, MSG_DTHRINV)
    end if
  end if
end while
return sDataHora
end function
-- ----------------------------------------------------------------------------
-- Retorna a Data e a hora do sistema.
-- retorna - a data e a hora
-- ----------------------------------------------------------------------------
function retDataHora()
integer y, m, d, h, mn, s
sequence dia, mes, ano, hora, min, seg, stempo, sdatahora 

stempo = date()
y = stempo[1]
y = y + 1900 
ano = NumToStr(y)
m = stempo[2]
mes = NumToStr(m)
if (m < 10) then 
  mes = "0" & mes 
end if
d = stempo[3]
dia = NumToStr(d)
if (d < 10) then 
  dia = "0" & dia 
end if 
h = stempo[4]
hora = NumToStr(h)
if (h < 10) then 
  hora = "0" & hora
end if 
mn = stempo[5]
min = NumToStr(mn)
if (mn < 10) then 
  min = "0" & min
end if 
s = stempo[6]
seg = NumToStr(s)
if (s < 10) then 
  seg = "0" & seg 
end if 
sdatahora = dia & "/" & mes & "/" & ano & " " & hora & ":" & min & ":" & seg
return sdatahora
end function

-- --- Rotinas de manipulação de arquivos -------------------------------------

-- ----------------------------------------------------------------------------
-- Calcula o tamanho do arquivo.
-- sArq - o arquivo
-- retorna - o tamanho do arquivo
-- ----------------------------------------------------------------------------
function tamArq(tarquivo sArq)
integer ntam, nstatus

nstatus = seek(sArq , -1)
ntam = where(sArq)
nstatus = seek(sArq , 0)
return ntam
end function
-- ----------------------------------------------------------------------------
-- Abre ou cria os arquivos do sistema.
-- bAbre - condição para abrir ou criar os arquivos do sistema
-- ----------------------------------------------------------------------------
procedure abrecriaArqs(boolean bAbre)

if bAbre = TRUE then
  tfAssunto = open(ARQ_ASSUNTO,ARQ_ABRE)
  if tfAssunto = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_ASSUNTO & "\n")
    abort(1)
  end if
  tfAutor = open(ARQ_AUTOR,ARQ_ABRE)
  if tfAutor = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_AUTOR & "\n")
    abort(1)
  end if
  tfEditora = open(ARQ_EDITORA,ARQ_ABRE)
  if tfEditora = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_EDITORA & "\n")
    abort(1)
  end if
  tfIdioma = open(ARQ_IDIOMA,ARQ_ABRE)
  if tfIdioma = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_IDIOMA & "\n")
    abort(1)
  end if
  tfEndereco = open(ARQ_ENDERECO,ARQ_ABRE)
  if tfEndereco = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_ENDERECO & "\n")
    abort(1)
  end if
  tfPais = open(ARQ_PAIS,ARQ_ABRE)
  if tfPais = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_PAIS & "\n")
    abort(1)
  end if
  tfProfissao = open(ARQ_PROFISSAO,ARQ_ABRE)
  if tfProfissao = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_PROFISSAO & "\n")
    abort(1)
  end if
  tfLivro = open(ARQ_LIVRO,ARQ_ABRE)
  if tfLivro = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_LIVRO & "\n")
    abort(1)
  end if
  tfLivroAss = open(ARQ_LIVASS,ARQ_ABRE)
  if tfLivroAss = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_LIVASS & "\n")
    abort(1)
  end if
  tfLivroAut = open(ARQ_LIVAUT,ARQ_ABRE)
  if tfLivroAut = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_LIVAUT & "\n")
    abort(1)
  end if
  tfCliente = open(ARQ_CLIENTE,ARQ_ABRE)
  if tfCliente = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_CLIENTE & "\n")
    abort(1)
  end if
  tfUsuario = open(ARQ_USUARIO,ARQ_ABRE)
  if tfUsuario = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_USUARIO & "\n")
    abort(1)
  end if
  tfVenda = open(ARQ_VENDA,ARQ_ABRE)
  if tfVenda = -1 then
    puts(STDERR, MSG_ARQERRO & " --> " & ARQ_VENDA & "\n")
    abort(1)
  end if
else
  tfAssunto = open(ARQ_ASSUNTO,ARQ_CRIA)
  tfAutor = open(ARQ_AUTOR,ARQ_CRIA)
  tfEditora = open(ARQ_EDITORA,ARQ_CRIA)
  tfIdioma = open(ARQ_IDIOMA,ARQ_CRIA)
  tfEndereco = open(ARQ_ENDERECO,ARQ_CRIA)
  tfPais = open(ARQ_PAIS,ARQ_CRIA)
  tfProfissao = open(ARQ_PROFISSAO,ARQ_CRIA)
  tfLivro = open(ARQ_LIVRO,ARQ_CRIA)
  tfLivroAss = open(ARQ_LIVASS,ARQ_CRIA)
  tfLivroAut = open(ARQ_LIVAUT,ARQ_CRIA)
  tfCliente = open(ARQ_CLIENTE,ARQ_CRIA)
  tfUsuario = open(ARQ_USUARIO,ARQ_CRIA)
  tfVenda = open(ARQ_VENDA,ARQ_CRIA)
end if
end procedure
-- ----------------------------------------------------------------------------
-- Fecha todos os arquivos abertos.
-- ----------------------------------------------------------------------------
procedure fechaArqs()
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
end procedure
-- ----------------------------------------------------------------------------
-- Pesquisa um registro através de um valor chave num arquivo.
-- sArq - o arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o registro pesquisado
-- ----------------------------------------------------------------------------
function pesqArq(tarquivo sArq, sequence sChave, integer nPosChave,
        integer nTamChave, integer nTamLinha)
object slinha
sequence sres, slocal
boolean bQuebra
integer nPosicao, nstatus

sres = ""
bQuebra = FALSE
nstatus = seek(sArq, 0)
while bQuebra=FALSE do
  slinha = gets(sArq)
  if atom(slinha) then
    exit 
  end if
  if length(slinha) > 0 then
    slocal = slinha
    sres = trim(copy(slocal,nPosChave,nTamChave))
    if equal(sres, sChave) then
       bQuebra = TRUE
    end if
  end if
end while
nPosicao = where(sArq)-(nTamLinha + TAM_CRLF)
if nPosicao > 0 then
  nstatus = seek(sArq, nPosicao)
else
  nstatus = seek(sArq, 0)
end if
if equal(sres, sChave)=FALSE then
   return ""
else
   return copy(slocal,1,nTamLinha)
end if
end function
-- ----------------------------------------------------------------------------
-- Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
-- sArq - o arquivo
-- nTamLinha - o tamanho do registro
-- ----------------------------------------------------------------------------
procedure pesqLinhaExcluida(tarquivo sArq, integer nTamLinha)
sequence sExcluido
integer nstatus

sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha)
if equal(sExcluido,"") then
   nstatus = seek(sArq, tamArq(sArq))
end if
end procedure
-- ----------------------------------------------------------------------------
-- Pesquisa o maior código num arquivo.
-- sArq - o arquivo
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o maior código
-- ----------------------------------------------------------------------------
function pesqMaxCod(tarquivo sArq, integer nPosChave, 
	integer nTamChave, integer nTamLinha)
object slinha
sequence sres, slocal
boolean bQuebra 
integer nstatus, nMaior, nCod 

bQuebra=FALSE
nMaior=0
nstatus = seek(sArq, 0)
while bQuebra=FALSE do
  slinha = gets(sArq)
  if atom(slinha) then
    exit 
  end if
  if length(slinha) > 0 then
    slocal = slinha
    sres=trim(copy(slocal,nPosChave,nTamChave))
    nCod = StrToNum(sres)
    if nCod > nMaior then
       nMaior=nCod
    end if
  end if
end while
pesqLinhaExcluida(sArq, nTamLinha)
sres = NumToStr(nMaior+1)
return sres
end function
-- ----------------------------------------------------------------------------
-- Grava os registros num determinado arquivo.
-- sArq - o arquivo
-- sTexto - o registro a ser gravado
-- sMsgAcerto - a mensagem caso o registro foi gravado
-- sMsgErro - a mensagem caso o registro não foi gravado
-- ----------------------------------------------------------------------------
procedure escreveArq(tarquivo sArq, sequence sTexto, sequence sMsgAcerto,
	  sequence sMsgErro)

sTexto=sTexto & CRLF
puts(sArq, sTexto)
if length(sTexto) > 0 then
  puts(STDOUT,sMsgAcerto)
else
  puts(STDERR, sMsgErro)
end if
end procedure

-- ----------------------------------------------------------------------------
-- Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o registro montado
-- ----------------------------------------------------------------------------
function LinhaReg(ctArqs sreg)
sequence slinha

slinha = {}
if sreg=opAssunto then
   slinha=esp(tAssunto[CODIGO],10) & esp(tAssunto[ASSUNTO],30)
elsif sreg=opAutor then
   slinha=esp(tAutor[CODIGO],10) & esp(tAutor[AUTOR],30)
elsif sreg=opEditora then
   slinha=esp(tEditora[CODIGO],10) & esp(tEditora[EDITORA],50)
elsif sreg=opEndereco then
   slinha=esp(tEndereco[CODIGO],10) & esp(tEndereco[LOGRADOURO],40) & 
   esp(tEndereco[BAIRRO],15) & esp(tEndereco[CEP],8) & 
   esp(tEndereco[CIDADE],30) & esp(tEndereco[ESTADO],20)
elsif sreg=opIdioma then
   slinha=esp(tIdioma[CODIGO],10) & esp(tIdioma[IDIOMA],20)
elsif sreg=opPais then
   slinha=esp(tPais[CODIGO],3) & esp(tPais[PAIS],50)
elsif sreg=opProfissao then
   slinha=esp(tProfissao[CODIGO],10) & esp(tProfissao[PROFISSAO],50)
elsif sreg=opUsuario then
   slinha=esp(tUsuario[LOGIN],10) & esp(tUsuario[SENHA],10)
elsif sreg=opLivro then
   slinha=esp(tLivro[ISBN],13) & esp(tLivro[TITULO],50) & esp(tLivro[EDICAO],10) & 
   esp(tLivro[ANOPUBLI],10) & esp(tLivro[CODEDITORA],10) & esp(tLivro[VOLUME],10) & 
   esp(tLivro[CODIDIOMA],10) & esp(tLivro[NPAGINAS],10) & esp(tLivro[PRECO],10) & 
   esp(tLivro[QTDESTOQUE],10)
elsif sreg=opLivroAss then
   slinha=esp(tLivroAss[ISBN],13) & esp(tLivroAss[CODASSUNTO],10)
elsif sreg=opLivroAut then
   slinha=esp(tLivroAut[ISBN],13) & esp(tLivroAut[CODAUTOR],10)
elsif sreg=opCliente then
   slinha=esp(tCliente[CPF],14) & esp(tCliente[NOME],30) & esp(tCliente[EMAIL],30) & 
   esp(tCliente[IDENTIDADE],10) & esp(tCliente[SEXO],1) & esp(tCliente[TELEFONE],17) & 
   esp(tCliente[DTNASCIMENTO],10) & esp(tCliente[CODENDERECO],10) & 
   esp(tCliente[CODPAIS],3) & esp(tCliente[CODPROFISSAO],10)
elsif sreg=opVenda then
   slinha=esp(tVenda[DTHRVENDA],19) & esp(tVenda[CPFVENDA],14) & esp(tVenda[ISBNVENDA],13) & 
   esp(tVenda[PRECOVENDA],10)
end if
return slinha
end function
-- ----------------------------------------------------------------------------
-- Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o tamanho do registro
-- ----------------------------------------------------------------------------
function tamReg(ctArqs sreg)
integer nret

nret=0
if sreg=opAssunto then nret=TAM_ASSUNTO
elsif sreg=opAutor then nret=TAM_AUTOR
elsif sreg=opEditora then nret=TAM_EDITORA
elsif sreg=opEndereco then nret=TAM_ENDERECO
elsif sreg=opIdioma then nret=TAM_IDIOMA
elsif sreg=opPais then nret=TAM_PAIS
elsif sreg=opProfissao then nret=TAM_PROFISSAO
elsif sreg=opUsuario then nret=TAM_USUARIO
elsif sreg=opLivro then nret=TAM_LIVRO
elsif sreg=opLivroAss then nret=TAM_LIVASS
elsif sreg=opLivroAut then nret=TAM_LIVAUT
elsif sreg=opCliente then nret=TAM_CLIENTE
elsif sreg=opVenda then nret=TAM_VENDA
end if
return nret
end function

-- --- Rotinas de implementação do sistema ------------------------------------

-- ----------------------------------------------------------------------------
-- Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- nNum - indica qual rotulo será retornado
-- retorna - o rotulo
-- ----------------------------------------------------------------------------
function rotulo(ctArqs sreg, integer nNum)
sequence sret

if sreg=opAssunto then
   if nNum = 0 then sret="Assunto(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="Código do assunto: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Assunto: "
          g_nPosChave=11
          g_nTamChave=30
   end if
elsif sreg=opAutor then
   if nNum = 0 then sret="Autor(es) não encontrado(s)!\n"
   elsif nNum = 1 then sret="Código do autor: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Autor: "
          g_nPosChave=11
          g_nTamChave=30
   end if
elsif sreg=opEditora then
   if nNum = 0 then sret="Editora(s) não encontrada(s)!\n"
   elsif nNum = 1 then sret="Código da editora: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Editora: "
          g_nPosChave=11
          g_nTamChave=50
   end if
elsif sreg=opEndereco then
   if nNum = 0 then sret="Endereço(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="Código do endereço: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Logradouro: "
          g_nPosChave=11
          g_nTamChave=40
   elsif nNum = 3 then sret="Bairro: "
          g_nPosChave=51
          g_nTamChave=15
   elsif nNum = 4 then sret="CEP: "
          g_nPosChave=66
          g_nTamChave=8
   elsif nNum = 5 then sret="Cidade: "
          g_nPosChave=74
          g_nTamChave=30
   elsif nNum = 6 then sret="Estado: "
          g_nPosChave=104
          g_nTamChave=20
   end if
elsif sreg=opIdioma then
   if nNum = 0 then sret="Idioma(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="Código do idioma: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Idioma: "
          g_nPosChave=11
          g_nTamChave=20
   end if
elsif sreg=opPais then
   if nNum = 0 then sret="País(es) não encontrado(s)!\n"
   elsif nNum = 1 then sret="Código do país: "
          g_nPosChave=1
          g_nTamChave=3
   elsif nNum = 2 then sret="País: "
          g_nPosChave=4
          g_nTamChave=50
   end if
elsif sreg=opProfissao then
   if nNum = 0 then sret="Profissão(es) não encontrada(s)!\n"
   elsif nNum = 1 then sret="Código da profissão: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Profissão: "
          g_nPosChave=11
          g_nTamChave=50
   end if
elsif sreg=opUsuario then
   if nNum = 0 then sret="login ou senha incorreta, tente de novo!\n"
   elsif nNum = 1 then sret="Login: "
          g_nPosChave=1
          g_nTamChave=10
   elsif nNum = 2 then sret="Senha: "
          g_nPosChave=11
          g_nTamChave=10
   end if
elsif sreg=opLivro then
   if nNum = 0 then sret="Livro(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="ISBN: "
          g_nPosChave=1
          g_nTamChave=13
   elsif nNum = 2 then sret="Título: "
          g_nPosChave=14
          g_nTamChave=50
   elsif nNum = 3 then sret="Edição: "
          g_nPosChave=64
          g_nTamChave=10
   elsif nNum = 4 then sret="Ano de Publicação: "
          g_nPosChave=74
          g_nTamChave=10
   elsif nNum = 5 then sret="Código da editora: "
          g_nPosChave=84
          g_nTamChave=10
   elsif nNum = 6 then sret="Volume: "
          g_nPosChave=94
          g_nTamChave=10
   elsif nNum = 7 then sret="Código do idioma: "
          g_nPosChave=104
          g_nTamChave=10
   elsif nNum = 8 then sret="Número de páginas: "
          g_nPosChave=114
          g_nTamChave=10
   elsif nNum = 9 then sret="Preço: "
          g_nPosChave=124
          g_nTamChave=10
   elsif nNum = 10 then sret="Qtd. Estoque: "
           g_nPosChave=134
           g_nTamChave=10
   end if
elsif sreg=opLivroAss then
   if nNum = 0 then sret="Assunto(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="ISBN: "
          g_nPosChave=1
          g_nTamChave=13
   elsif nNum = 2 then sret="Código do assunto: "
          g_nPosChave=14
          g_nTamChave=10
   end if
elsif sreg=opLivroAut then
   if nNum = 0 then sret="Autor(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="ISBN: "
          g_nPosChave=1
          g_nTamChave=13
   elsif nNum = 2 then sret="Código do autor: "
          g_nPosChave=14
          g_nTamChave=10
   end if
elsif sreg=opCliente then
   if nNum = 0 then sret="Cliente(s) não encontrado(s)!\n"
   elsif nNum = 1 then sret="CPF: "
          g_nPosChave=1
          g_nTamChave=14
   elsif nNum = 2 then sret="Nome: "
          g_nPosChave=15
          g_nTamChave=30
   elsif nNum = 3 then sret="E-mail: "
          g_nPosChave=45
          g_nTamChave=30
   elsif nNum = 4 then sret="Identidade: "
          g_nPosChave=75
          g_nTamChave=10
   elsif nNum = 5 then sret="Sexo: "
          g_nPosChave=85
          g_nTamChave=1
   elsif nNum = 6 then sret="Telefone: "
          g_nPosChave=86
          g_nTamChave=17
   elsif nNum = 7 then sret="Dt. Nascimento: "
          g_nPosChave=103
          g_nTamChave=10
   elsif nNum = 8 then sret="Código do endereço: "
          g_nPosChave=113
          g_nTamChave=10
   elsif nNum = 9 then sret="Código do país: "
          g_nPosChave=123
          g_nTamChave=3
   elsif nNum = 10 then sret="Código da Profissão: "
          g_nPosChave=126
          g_nTamChave=10
   end if
elsif sreg=opVenda then
   if nNum = 0 then sret="Venda(s) não encontrada(s)!\n"
   elsif nNum = 1 then sret="Data/Hora venda: "
          g_nPosChave=1
          g_nTamChave=19
   elsif nNum = 2 then sret="CPF: "
          g_nPosChave=20
          g_nTamChave=14
   elsif nNum = 3 then sret="ISBN: "
          g_nPosChave=34
          g_nTamChave=13
   elsif nNum = 4 then sret="Preço de venda: "
          g_nPosChave=47
          g_nTamChave=10
   end if
end if

return sret
end function
-- ----------------------------------------------------------------------------
-- Mostra os menus do sistema.
-- num - o número do menu
-- ----------------------------------------------------------------------------
function menu(integer num)

 if (num=1) then
 puts(STDOUT, "*--------------------------------------------------------------*\n")
 puts(STDOUT, "| (C)adastros        (P)esquisas     (V)endas        (O)pções  |\n")
 puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=2) then
  puts(STDOUT, "*---------------------------------*\n")
  puts(STDOUT, "| 01. Cadastro de Assuntos        |\n")
  puts(STDOUT, "| 02. Cadastro de Autores         |\n")
  puts(STDOUT, "| 03. Cadastro de Editoras        |\n")
  puts(STDOUT, "| 04. Cadastro de Endereços       |\n")
  puts(STDOUT, "| 05. Cadastro de Idiomas         |\n")
  puts(STDOUT, "| 06. Cadastro de Países          |\n")
  puts(STDOUT, "| 07. Cadastro de Profissões      |\n")
  puts(STDOUT, "| 08. Cadastro de Clientes        |\n")
  puts(STDOUT, "| 09. Cadastro de Livros          |\n")
  puts(STDOUT, "| 10. Voltar ao menu              |\n")
  puts(STDOUT, "*---------------------------------*\n")
 elsif (num=3) then
  puts(STDOUT, "*---------------------------------*\n")
  puts(STDOUT, "| 01. Consulta de Assuntos        |\n")
  puts(STDOUT, "| 02. Consulta de Autores         |\n")
  puts(STDOUT, "| 03. Consulta de Editoras        |\n")
  puts(STDOUT, "| 04. Consulta de Endereços       |\n")
  puts(STDOUT, "| 05. Consulta de Idiomas         |\n")
  puts(STDOUT, "| 06. Consulta de Países          |\n")
  puts(STDOUT, "| 07. Consulta de Profissões      |\n")
  puts(STDOUT, "| 08. Consulta de Clientes        |\n")
  puts(STDOUT, "| 09. Consulta de Livros          |\n")
  puts(STDOUT, "| 10. Voltar ao menu              |\n")
  puts(STDOUT, "*---------------------------------*\n")
 elsif (num=4) then
  puts(STDOUT, "*---------------------------------*\n")
  puts(STDOUT, "| 01. Vender Livros               |\n")
  puts(STDOUT, "| 02. Vendas Realizadas           |\n")
  puts(STDOUT, "| 03. Voltar ao menu              |\n")
  puts(STDOUT, "*---------------------------------*\n")
 elsif (num=5) then
  puts(STDOUT, "*---------------------------------*\n")
  puts(STDOUT, "| 01. Alterar senha               |\n")
  puts(STDOUT, "| 02. Sobre o sistema             |\n")
  puts(STDOUT, "| 03. Sair do sistema             |\n")
  puts(STDOUT, "| 04. Voltar ao menu              |\n")
  puts(STDOUT, "*---------------------------------*\n")
 elsif (num=6) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=7) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| (1) Salvar inclusão       (2) Voltar ao menu                 |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=8) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=9) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| (1) Salvar alteração      (2) Voltar ao menu                 |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=10) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| Certeza de excluir? (S/N)                                    |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=11) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| Deseja sair do sistema? (S/N)                                |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=12) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=13) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| Deseja continuar? (S/N)                                      |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 elsif (num=14) then
  puts(STDOUT, "*--------------------------------------------------------------*\n")
  puts(STDOUT, "| Salvar inclusão (S/N)                                        |\n")
  puts(STDOUT, "*--------------------------------------------------------------*\n")
 end if
-- puts(STDOUT, MSG_OPCAO)
 return MSG_OPCAO
end function
-- ----------------------------------------------------------------------------
-- Indica se continua ou não mostrando um número máximo de linhas.
-- nlinha - a linha a ser continuada
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se continua ou não
-- ----------------------------------------------------------------------------
function ContinuaSN(integer nlinha, integer nQtdLinha)
boolean bSOp, bret 
sequence opCSubMenu

bret=FALSE
if nlinha > 0 then
  if remainder(nlinha, nQtdLinha) = 0 then
      bSOp=TRUE
      while bSOp=TRUE do        
        opCSubMenu = digita(menu(13), FALSE)
        if equal(opCSubMenu,"S") or equal(opCSubMenu,"s") then bSOp=FALSE
        elsif equal(opCSubMenu,"N") or equal(opCSubMenu,"n") then
          bret=TRUE
          bSOp=FALSE
        else puts(STDERR, MSG_ERRO)
        end if 
      end while
  end if
end if

return bret
end function
-- ----------------------------------------------------------------------------
-- Necessário para retirar a referência circular
-- Valida a entrada de registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- nTexto - o numero do rótulo da entrada
-- sEntrada - a chave a ser pesquisada e validada
-- nTentativas - o número máximo de tentativas
-- bTipoEntrada - indica o tipo de entrada
-- retorna - o registro pesquisado e validado
-- ----------------------------------------------------------------------------
function validaEntrada2(tarquivo sArq, ctArqs sreg, integer nTexto,
        sequence sEntrada, integer nTentativas, ctTipo bTipoEntrada)
boolean bQuebra
sequence sres, sTexto, sMsgErro
integer ncont, nPosChave, nTamChave, nTamLinha

nTamLinha=tamReg(sreg)
sMsgErro=rotulo(sreg,0)
sTexto=rotulo(sreg,nTexto)
nPosChave=g_nPosChave
nTamChave=g_nTamChave

ncont=1
bQuebra=FALSE
  while (bQuebra=FALSE) and (ncont <= nTentativas ) do
    if bTipoEntrada=opTexto then
      sEntrada = digita(sTexto, FALSE)
    elsif bTipoEntrada=opNumero then
       sEntrada=validaNumero(sTexto, sEntrada)
    elsif bTipoEntrada=opData then
       sEntrada=validaDataHora(sTexto, sEntrada, TRUE)
    elsif bTipoEntrada=opDataHora then
       sEntrada=validaDataHora(sTexto, sEntrada, FALSE)
    elsif bTipoEntrada=opSenha then
       sEntrada=digitaSenha(sTexto, 10)
    end if

    sres=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)

    if equal(sres,"") then
       puts(STDERR, sMsgErro)
    else
       bQuebra=TRUE
    end if

    ncont=ncont+1
  end while
return sres
end function

-- ----------------------------------------------------------------------------
-- Mostra as sub informções de entrada e de saída.
-- sreg - o tipo de arquivo
-- ssubreg - o subtipo de arquivo
-- bSoMostrar - se vai só mostrar na saída 
-- ----------------------------------------------------------------------------
procedure mostrarSubDados(ctArqs sreg, ctArqs ssubreg, boolean bSoMostrar)
sequence sRegistro, sPreco
integer nMaxTentativas

nMaxTentativas=3
if sreg=opLivro then
  if ssubreg=opEditora then
    if bSoMostrar then
       sRegistro=pesqArq(tfEditora,tLivro[CODEDITORA],1,10,tamReg(opEditora))
    else
       sRegistro=validaEntrada2(tfEditora,ssubreg,1,tLivro[CODEDITORA],
                  nMaxTentativas,opNumero)
    end if
    if equal(sRegistro,"")=FALSE then
      tLivro[CODEDITORA]=trim(copy(sRegistro,1,10))
      puts(STDOUT, " " & rotulo(opEditora, 2))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
    end if
  elsif ssubreg=opIdioma then
    if bSoMostrar then
       sRegistro=pesqArq(tfIdioma, tLivro[CODIDIOMA], 1, 10,tamReg(opIdioma))
    else
       sRegistro=validaEntrada2(tfIdioma,ssubreg,1,tLivro[CODIDIOMA],
                  nMaxTentativas,opNumero)
    end if
    if equal(sRegistro,"")=FALSE then
      tLivro[CODIDIOMA]=trim(copy(sRegistro,1,10))
      puts(STDOUT, " " & rotulo(opIdioma, 2))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
    end if
  end if
elsif sreg=opCliente then
  if ssubreg=opEndereco then
    if bSoMostrar then
       sRegistro=pesqArq(tfEndereco, tCliente[CODENDERECO], 1, 10,
                  tamReg(opEndereco))
    else
       sRegistro=validaEntrada2(tfEndereco,ssubreg,1,tCliente[CODENDERECO],
                  nMaxTentativas,opNumero)
    end if
    if equal(sRegistro,"")=FALSE then
      tCliente[CODENDERECO]=trim(copy(sRegistro,1,10))
      puts(STDOUT," " & rotulo(opEndereco, 2))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
      puts(STDOUT," " & rotulo(opEndereco, 3))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
      puts(STDOUT," " & rotulo(opEndereco, 4))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
      puts(STDOUT," " & rotulo(opEndereco, 5))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
      puts(STDOUT," " & rotulo(opEndereco, 6))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
    end if
  elsif ssubreg=opPais then
    if bSoMostrar then
       sRegistro=pesqArq(tfPais, tCliente[CODPAIS], 1, 3, tamReg(opPais))
    else
       sRegistro=validaEntrada2(tfPais,ssubreg,1,tCliente[CODPAIS],
                  nMaxTentativas,opTexto)
    end if
    if equal(sRegistro,"")=FALSE then
      tCliente[CODPAIS]=trim(copy(sRegistro,1,3))
      puts(STDOUT," " & rotulo(opPais, 2))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
    end if
  elsif ssubreg=opProfissao then
    if bSoMostrar then
       sRegistro=pesqArq(tfProfissao, tCliente[CODPROFISSAO], 1, 10,
                  tamReg(opProfissao))
    else
       sRegistro=validaEntrada2(tfProfissao,ssubreg,1,tCliente[CODPROFISSAO],
                  nMaxTentativas,opNumero)
    end if
    if equal(sRegistro,"")=FALSE then
      tCliente[CODPROFISSAO]=trim(copy(sRegistro,1,10))
      puts(STDOUT," " & rotulo(opProfissao, 2))
      puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
    end if
  end if
elsif sreg=opVenda then
  sRegistro=pesqArq(tfLivro, tVenda[ISBNVENDA], 1, 13, tamReg(opLivro))
  if equal(sRegistro,"")=FALSE then
    puts(STDOUT," " & rotulo(opLivro, 2)) -- Titulo -- 
    puts(STDOUT,copy(sRegistro, g_nPosChave, g_nTamChave) & "\n")
    puts(STDOUT," " & rotulo(opLivro, 9)) -- Preco --
    sPreco=trim(copy(sRegistro, g_nPosChave, g_nTamChave))
    g_nPreco=StrToNum(sPreco)
    puts(STDOUT, sPreco & "\n")
  end if
end if
end procedure
-- ----------------------------------------------------------------------------
-- Lista vários registros entre arquivos de acordo com a pesquisa feita.
-- sArq1 - o arquivo de ligação
-- sreg1 - o tipo de arquivo de ligação
-- nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
-- nTamChave1 - o tamanho da primeira chave no arquivo de ligação
-- nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
-- nTamChave2 - o tamanho da segunda chave do arquivo de ligação
-- sChave - a chave a ser pesquisada no arquivo de ligação
-- sArq2 - o arquivo a ser pesquisado
-- sreg2 - o tipo de arquivo a ser pesquisado
-- nPosChave3 - a posicao inicial da chave do arquivo pesquisado
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- ----------------------------------------------------------------------------
procedure ListarRegLigados(tarquivo sArq1, integer nPosChave1,
integer nTamChave1, integer nPosChave2, integer nTamChave2, sequence sChave,
tarquivo sArq2, ctArqs sreg2, integer nPosChave3, integer nQtdLinha)
object slinha1
boolean bQuebra, bRet 
integer nCont, nstatus
sequence slocal1, sCodigo1, sCodigo2, slinha2, slinha

bRet=FALSE
nCont=0
bQuebra=FALSE

-- necessário para retirar a referência circular
-- mostrarDados(sreg2, "", 2)
if sreg2 = opAssunto then
  puts(STDOUT, "Código     Assunto\n")
  puts(STDOUT, "------     -------\n")
elsif sreg2 = opAutor then
  puts(STDOUT, "Código     Autor\n")
  puts(STDOUT, "------     -----\n")
end if

nstatus = seek(sArq1, 0)
while bQuebra=FALSE do
  slinha1 = gets(sArq1)
  if atom(slinha1) then
    exit 
  end if
  if length(slinha1) > 0 then
    slocal1 = slinha1
    sCodigo1=trim(copy(slocal1,nPosChave1,nTamChave1))
    if equal(sCodigo1,sChave) then
      sCodigo2=trim(copy(slocal1,nPosChave2,nTamChave2))
      slinha2=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
  
  --  necessário para retirar a referência circular
  --  mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3)
      slinha = copy(slinha2, 1, tamReg(sreg2))
      if sreg2 = opAssunto then
        tAssunto[CODIGO]=copy(slinha, 1, 10)
        tAssunto[ASSUNTO]=copy(slinha, 11, 30)
        puts(STDOUT, tAssunto[CODIGO] & " " & tAssunto[ASSUNTO] & "\n")
      elsif sreg2 = opAutor then
        tAutor[CODIGO]=copy(slinha, 1, 10)
        tAutor[AUTOR]=copy(slinha, 11, 30)
        puts(STDOUT, tAutor[CODIGO] & " " & tAutor[AUTOR] & "\n")
      end if
  
      bRet=TRUE
      nCont=nCont+1
    end if
    bQuebra=ContinuaSN(nCont, nQtdLinha)
  end if
end while
if bRet=FALSE then
   puts(STDOUT, rotulo(sreg2,0))
end if
end procedure
-- ----------------------------------------------------------------------------
-- Mostra as entradas e as saídas do sistema.
-- sreg - o tipo de arquivo
-- slinha - o registro com os dados
-- nOpcao - indica qual opção será mostrada
-- ----------------------------------------------------------------------------
procedure mostrarDados(ctArqs sreg, sequence slinha, integer nOpcao)
if sreg=opAssunto then
   if nOpcao = 1 then
        puts(STDOUT, rotulo(sreg, 1) & tAssunto[CODIGO] & "\n")
        tAssunto[ASSUNTO] = digita(rotulo(sreg, 2), FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "Código     Assunto\n")
        puts(STDOUT, "------     -------\n")
   elsif nOpcao = 3 then
        tAssunto[CODIGO]=copy(slinha, 1, 10)
        tAssunto[ASSUNTO]=copy(slinha, 11, 30)
        puts(STDOUT, tAssunto[CODIGO] & " " & tAssunto[ASSUNTO] & "\n")
   end if
elsif sreg=opAutor then
   if nOpcao = 1 then
        puts(STDOUT, rotulo(sreg, 1) & tAutor[CODIGO] & "\n")
        tAutor[AUTOR] = digita(rotulo(sreg, 2), FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "Código     Autor\n")
        puts(STDOUT, "------     -----\n")
   elsif nOpcao = 3 then
        tAutor[CODIGO]=copy(slinha, 1, 10)
        tAutor[AUTOR]=copy(slinha, 11, 30)
        puts(STDOUT, tAutor[CODIGO] & " " & tAutor[AUTOR] & "\n")
   end if
elsif sreg=opEditora then
   if nOpcao = 1 then
        puts(STDOUT, rotulo(sreg, 1) & tEditora[CODIGO] & "\n")
        tEditora[EDITORA] = digita(rotulo(sreg, 2), FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "Código     Editora\n")
        puts(STDOUT, "------     -------\n")
   elsif nOpcao = 3 then
        tEditora[CODIGO]=copy(slinha, 1, 10)
        tEditora[EDITORA]=copy(slinha, 11, 50)
        puts(STDOUT, tEditora[CODIGO] & " " & tEditora[EDITORA] & "\n")
   end if
elsif sreg=opEndereco then
   if nOpcao = 1 then
        puts(STDOUT, rotulo(sreg, 1) & tEndereco[CODIGO] & "\n")
        tEndereco[LOGRADOURO] = digita(rotulo(sreg, 2), FALSE)
        tEndereco[BAIRRO] = digita(rotulo(sreg, 3), FALSE)
        tEndereco[CEP] = digita(rotulo(sreg, 4), FALSE)
        tEndereco[CIDADE] = digita(rotulo(sreg, 5), FALSE)
        tEndereco[ESTADO] = digita(rotulo(sreg, 6), FALSE)
   elsif nOpcao = 3 then
        tEndereco[CODIGO]=trim(copy(slinha, 1, 10))
        tEndereco[LOGRADOURO]=trim(copy(slinha, 11, 40))
        tEndereco[BAIRRO]=trim(copy(slinha, 51, 15))
        tEndereco[CEP]=trim(copy(slinha, 66, 8))
        tEndereco[CIDADE]=trim(copy(slinha, 74, 30))
        tEndereco[ESTADO]=trim(copy(slinha, 104, 20))
        puts(STDOUT, "--------------------\n")
        puts(STDOUT, rotulo(sreg, 1) & tEndereco[CODIGO] & "\n")
        puts(STDOUT, rotulo(sreg, 2) & tEndereco[LOGRADOURO] & "\n")
        puts(STDOUT, rotulo(sreg, 3) & tEndereco[BAIRRO] & "\n")
        puts(STDOUT, rotulo(sreg, 4) & tEndereco[CEP] & "\n")
        puts(STDOUT, rotulo(sreg, 5) & tEndereco[CIDADE] & "\n")
        puts(STDOUT, rotulo(sreg, 6) & tEndereco[ESTADO] & "\n")
   end if
elsif sreg=opIdioma then
   if nOpcao = 1 then
        puts(STDOUT, rotulo(sreg, 1) & tIdioma[CODIGO] & "\n")
        tIdioma[IDIOMA] = digita(rotulo(sreg, 2), FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "Código     Idioma\n")
        puts(STDOUT, "------     ------\n")
   elsif nOpcao = 3 then
        tIdioma[CODIGO]=copy(slinha, 1, 10)
        tIdioma[IDIOMA]=copy(slinha, 11, 20)
        puts(STDOUT, tIdioma[CODIGO] & " " & tIdioma[IDIOMA] & "\n")
   end if
elsif sreg=opPais then
   if nOpcao = 1 then
        tPais[PAIS] = digita(rotulo(sreg, 2), FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "Código País\n")
        puts(STDOUT, "------ ----\n")
   elsif nOpcao = 3 then
        tPais[CODIGO]=copy(slinha, 1, 3)
        tPais[PAIS]=copy(slinha, 4, 50)
        puts(STDOUT, tPais[CODIGO] & "    " & tPais[PAIS] & "\n")
   end if
elsif sreg=opProfissao then
   if nOpcao = 1 then
        puts(STDOUT, rotulo(sreg, 1) & tProfissao[CODIGO] & "\n")
        tProfissao[PROFISSAO] = digita(rotulo(sreg, 2), FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "Código     Profissão\n")
        puts(STDOUT, "------     ---------\n")
   elsif nOpcao = 3 then
        tProfissao[CODIGO]=copy(slinha, 1, 10)
        tProfissao[PROFISSAO]=copy(slinha, 11, 50)
        puts(STDOUT, tProfissao[CODIGO] & " " & tProfissao[PROFISSAO] & "\n")
   end if
elsif sreg=opLivro then
   if nOpcao = 1 then
        tLivro[TITULO] = digita(rotulo(sreg, 2), FALSE)
        tLivro[EDICAO]=validaNumero(rotulo(sreg, 3), tLivro[EDICAO])
        tLivro[ANOPUBLI]=validaNumero(rotulo(sreg, 4), tLivro[ANOPUBLI])
        mostrarSubDados(opLivro, opEditora, FALSE)
        tLivro[VOLUME]=validaNumero(rotulo(sreg, 6), tLivro[VOLUME])
        mostrarSubDados(opLivro, opIdioma, FALSE)
        tLivro[NPAGINAS]=validaNumero(rotulo(sreg, 8), tLivro[NPAGINAS])
        tLivro[PRECO]=validaNumero(rotulo(sreg, 9), tLivro[PRECO])
        tLivro[QTDESTOQUE]=validaNumero(rotulo(sreg, 10), tLivro[QTDESTOQUE])
   elsif nOpcao = 3 then
        tLivro[ISBN]=trim(copy(slinha, 1, 13))
        tLivro[TITULO]=trim(copy(slinha, 14, 50))
        tLivro[EDICAO]=trim(copy(slinha, 64, 10))
        tLivro[ANOPUBLI]=trim(copy(slinha, 74, 10))
        tLivro[CODEDITORA]=trim(copy(slinha, 84, 10))
        tLivro[VOLUME]=trim(copy(slinha, 94, 10))
        tLivro[CODIDIOMA]=trim(copy(slinha, 104, 10))
        tLivro[NPAGINAS]=trim(copy(slinha, 114, 10))
        tLivro[PRECO]=trim(copy(slinha, 124, 10))
        tLivro[QTDESTOQUE]=trim(copy(slinha, 134, 10))
        puts(STDOUT, "--------------------\n")
        puts(STDOUT, rotulo(sreg, 1) & tLivro[ISBN] & "\n")
        puts(STDOUT, rotulo(sreg, 2) & tLivro[TITULO] & "\n")
        puts(STDOUT, rotulo(sreg, 3) & tLivro[EDICAO] & "\n")
        puts(STDOUT, rotulo(sreg, 4) & tLivro[ANOPUBLI] & "\n")
        puts(STDOUT, rotulo(sreg, 5) & tLivro[CODEDITORA] & "\n")
        mostrarSubDados(opLivro, opEditora, TRUE)
        puts(STDOUT, rotulo(sreg, 6) & tLivro[VOLUME] & "\n")
        puts(STDOUT, rotulo(sreg, 7) & tLivro[CODIDIOMA] & "\n")
        mostrarSubDados(opLivro, opIdioma, TRUE)
        puts(STDOUT, rotulo(sreg, 8) & tLivro[NPAGINAS] & "\n")
        puts(STDOUT, rotulo(sreg, 9) & tLivro[PRECO] & "\n")
        puts(STDOUT, rotulo(sreg, 10) & tLivro[QTDESTOQUE] & "\n")
        ListarRegLigados(tfLivroAss, 1, 13, 14, 10, tLivro[ISBN],
                         tfAssunto, opAssunto, 1, 4)
        ListarRegLigados(tfLivroAut, 1, 13, 14, 10, tLivro[ISBN],
                         tfAutor, opAutor, 1, 4)
   end if
elsif sreg=opCliente then
   if nOpcao = 1 then
        tCliente[NOME] = digita(rotulo(sreg, 2), FALSE)
        tCliente[EMAIL] = digita(rotulo(sreg, 3), FALSE)
        tCliente[IDENTIDADE] = digita(rotulo(sreg, 4), FALSE)
        tCliente[SEXO] = digita(rotulo(sreg, 5), FALSE)
        tCliente[TELEFONE] = digita(rotulo(sreg, 6), FALSE)
        tCliente[DTNASCIMENTO]=
                validaDataHora(rotulo(sreg, 7), tCliente[DTNASCIMENTO], TRUE)
        mostrarSubDados(opCliente, opEndereco, FALSE)
        mostrarSubDados(opCliente, opPais, FALSE)
        mostrarSubDados(opCliente, opProfissao, FALSE)
   elsif nOpcao = 3 then
        tCliente[CPF]=trim(copy(slinha, 1, 14))
        tCliente[NOME]=trim(copy(slinha, 15, 30))
        tCliente[EMAIL]=trim(copy(slinha, 45, 30))
        tCliente[IDENTIDADE]=trim(copy(slinha, 75, 10))
        tCliente[SEXO]=trim(copy(slinha, 85, 1))
        tCliente[TELEFONE]=trim(copy(slinha, 86, 17))
        tCliente[DTNASCIMENTO]=trim(copy(slinha, 103, 10))
        tCliente[CODENDERECO]=trim(copy(slinha, 113, 10))
        tCliente[CODPAIS]=trim(copy(slinha, 123, 3))
        tCliente[CODPROFISSAO]=trim(copy(slinha, 126, 10))
        puts(STDOUT, "--------------------\n")
        puts(STDOUT, rotulo(sreg, 1) & tCliente[CPF] & "\n")
        puts(STDOUT, rotulo(sreg, 2) & tCliente[NOME] & "\n")
        puts(STDOUT, rotulo(sreg, 3) & tCliente[EMAIL] & "\n")
        puts(STDOUT, rotulo(sreg, 4) & tCliente[IDENTIDADE] & "\n")
        puts(STDOUT, rotulo(sreg, 5) & tCliente[SEXO] & "\n")
        puts(STDOUT, rotulo(sreg, 6) & tCliente[TELEFONE] & "\n")
        puts(STDOUT, rotulo(sreg, 7) & tCliente[DTNASCIMENTO] & "\n")
        puts(STDOUT, rotulo(sreg, 8) & tCliente[CODENDERECO] & "\n")
        mostrarSubDados(opCliente, opEndereco, TRUE)
        puts(STDOUT, rotulo(sreg, 9) & tCliente[CODPAIS] & "\n")
        mostrarSubDados(opCliente, opPais, TRUE)
        puts(STDOUT, rotulo(sreg, 10) & tCliente[CODPROFISSAO] & "\n")
        mostrarSubDados(opCliente, opProfissao, TRUE)
   end if
elsif sreg=opVenda then
   if nOpcao = 1 then mostrarSubDados(opVenda,opVenda, FALSE)
   elsif nOpcao = 2 then
        puts(STDOUT, "DataHoraVenda       CPF            ISBN          " &
        "PreçoVenda\n")
        puts(STDOUT, "-------------       ---            ----          " &
        "----------\n")
   elsif nOpcao = 3 then
        tVenda[DTHRVENDA]=copy(slinha, 1, 19)
        tVenda[CPFVENDA]=copy(slinha, 20, 14)
        tVenda[ISBNVENDA]=copy(slinha, 34, 13)
        tVenda[PRECOVENDA]=copy(slinha, 47, 10)
        puts(STDOUT, tVenda[DTHRVENDA] & " " & tVenda[CPFVENDA] & " " & 
        tVenda[ISBNVENDA] & " " & tVenda[PRECOVENDA] & "\n")
   end if
end if
end procedure
-- ----------------------------------------------------------------------------
-- Lista vários registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se encontrou algum registro
-- ----------------------------------------------------------------------------
function ListarTodos(tarquivo sArq, ctArqs sreg, sequence sChave,
   integer nPosChave, integer nTamChave, integer nTamLinha, integer nQtdLinha,
   boolean bPesqRelativa)
object slinha
boolean bQuebra, bAchou, bRet 
integer nCont, nstatus
sequence sres, slocal

bRet=FALSE
bQuebra=FALSE
nCont=0
mostrarDados(sreg, "", 2)
nstatus = seek(sArq, 0)
while bQuebra=FALSE do
  slinha = gets(sArq)
  if atom(slinha) then
    exit 
  end if
  if length(slinha) > 0 then
    slocal = slinha
    if bPesqRelativa=TRUE then
      sres=trim(copy(slocal,nPosChave,nTamChave))
      if strRelativa(sres,sChave)=TRUE then 
         bAchou=TRUE
         bRet=TRUE
      else
         bAchou=FALSE
      end if
    else
      bAchou=TRUE
      bRet=TRUE
    end if
  
    if bAchou=TRUE then
      mostrarDados(sreg, copy(slocal,1,nTamLinha), 3)
      nCont=nCont+1
    end if
  
    bQuebra=ContinuaSN(nCont, nQtdLinha)
  end if
end while
return bRet
end function
-- ----------------------------------------------------------------------------
-- Valida a entrada de registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- nTexto - o numero do rótulo da entrada
-- sEntrada - a chave a ser pesquisada e validada
-- nTentativas - o número máximo de tentativas
-- bPesqRelativa - indica se vai realizar uma pesquisa relativa
-- bTipoEntrada - indica o tipo de entrada
-- retorna - o registro pesquisado e validado
-- ----------------------------------------------------------------------------
function validaEntrada(tarquivo sArq, ctArqs sreg, integer nTexto,
        sequence sEntrada, integer nTentativas,
        boolean bPesqRelativa, ctTipo bTipoEntrada)
boolean bQuebra
sequence sres, sTexto, sMsgErro
integer ncont, nPosChave, nTamChave, nTamLinha

nTamLinha=tamReg(sreg)
sMsgErro=rotulo(sreg,0)
sTexto=rotulo(sreg,nTexto)
nPosChave=g_nPosChave
nTamChave=g_nTamChave

ncont=1
bQuebra=FALSE
  while (bQuebra=FALSE) and (ncont <= nTentativas ) do
    if bTipoEntrada=opTexto then
      sEntrada = digita(sTexto, FALSE)
    elsif bTipoEntrada=opNumero then
       sEntrada=validaNumero(sTexto, sEntrada)
    elsif bTipoEntrada=opData then
       sEntrada=validaDataHora(sTexto, sEntrada, TRUE)
    elsif bTipoEntrada=opDataHora then
       sEntrada=validaDataHora(sTexto, sEntrada, FALSE)
    elsif bTipoEntrada=opSenha then
       sEntrada=digitaSenha(sTexto, 10)
    end if

    if bPesqRelativa=TRUE then
       if ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha,
          QTD_MAX_LINHA, TRUE) = TRUE then
          sres=" "
       end if
    else
       sres=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)
    end if

    if equal(sres,"") then
       puts(STDERR, sMsgErro)
    else
       bQuebra=TRUE
    end if

    ncont=ncont+1
  end while
return sres
end function

-- ----------------------------------------------------------------------------
-- Executa uma ação de gravação de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure btnAcao(ctArqs sreg, ctAcao sacao)
if sreg=opAssunto then
   if sacao=opSalvarInclusao then
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfAssunto, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opAutor then
   if sacao=opSalvarInclusao then
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfAutor, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opEditora then
   if sacao=opSalvarInclusao then
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfEditora, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opEndereco then
   if sacao=opSalvarInclusao then
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfEndereco, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opIdioma then
   if sacao=opSalvarInclusao then
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfIdioma, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opPais then
   if sacao=opSalvarInclusao then
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfPais, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opProfissao then
   if sacao=opSalvarInclusao then
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfProfissao, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opLivro then
   if sacao=opSalvarInclusao then
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfLivro, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opLivroAss then
   if sacao=opSalvarInclusao then
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfLivroAss, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opLivroAut then
   if sacao=opSalvarInclusao then
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfLivroAut, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opCliente then
   if sacao=opSalvarInclusao then
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfCliente, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opVenda then
   if sacao=opSalvarInclusao then
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao=opSalvarAlteracao then
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao=opConfirmaExclusao then
      escreveArq(tfVenda, repeat("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elsif sreg=opUsuario then
   if sacao=opSalvarAlteracao then
      escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   end if
end if
end procedure
-- ----------------------------------------------------------------------------
-- Realiza a exclusão dos arquivos de ligação.
-- sArq - o arquivo de ligação
-- sreg - o tipo de arquivo de ligação
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- sChave - a chave a ser excluida
-- ----------------------------------------------------------------------------
procedure ExcluirRegLigados(tarquivo sArq, ctArqs sreg, integer nPosChave,
	  integer nTamChave, sequence sChave)
object slinha
sequence sCodigo, slocal
integer nstatus

nstatus = seek(sArq, 0)
while TRUE do
  slinha = gets(sArq)
  if atom(slinha) then
    exit 
  end if
  if length(slinha) > 0 then
    slocal = slinha
    sCodigo=trim(copy(slocal,nPosChave,nTamChave))
    if equal(sCodigo, sChave) then
       btnAcao(sreg, opConfirmaExclusao)
    end if
  end if
end while
end procedure

-- --- Rotinas de implementação da interface ----------------------------------

-- ----------------------------------------------------------------------------
-- Mostra a tela de splash do sistema.
-- ----------------------------------------------------------------------------
procedure frmSplash()
integer cont

puts(STDOUT, "*---------------------------------------" &
 "-------------------------------------*\n")
puts(STDOUT, "| LL    II VV   VV RRRRR  UU  UU   SSSS " &
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |\n")
puts(STDOUT, "| LL    II  VV VV  RR   R UU  UU  SS    " &
 " VV VV  II RR   R  TT  UU  UU  SS    |\n")
puts(STDOUT, "| LL    II   VVV   RRRRR  UU  UU    SS  " &
 "  VVV   II RRRRR   TT  UU  UU    SS  |\n")
puts(STDOUT, "| LLLLL II    V    RR   R  UUUU  SSSS   " &
 "   V    II RR   R  TT   UUUU  SSSS   |\n")
puts(STDOUT, "*---------------------------------------" &
 "-------------------------------------*\n")
 for ncont = 1 to 18 do
   puts(STDOUT,"\n")
 end for
 puts(STDOUT, MSG_PRESS)
 cont = wait_key()
 puts(STDOUT,"\n")
end procedure
-- ----------------------------------------------------------------------------
-- Mostra a tela de sobre do sistema.
-- ----------------------------------------------------------------------------
procedure frmSobre()
integer cont

puts(STDOUT, "*------------------------------------------------------------*\n")
puts(STDOUT, "|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |\n")
puts(STDOUT, "|  LL        II   VV     VV   RR     R  UU    UU  SS         |\n")
puts(STDOUT, "|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |\n")
puts(STDOUT, "|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |\n")
puts(STDOUT, "|  LLLL      II      VVV      RR RR     UU    UU        SS   |\n")
puts(STDOUT, "|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |\n")
puts(STDOUT, "|                                                            |\n")
puts(STDOUT, "|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |\n")
puts(STDOUT, "|   VV     VV   II  RR     R     TT     UU    UU  SS         |\n")
puts(STDOUT, "|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |\n")
puts(STDOUT, "|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |\n")
puts(STDOUT, "|      VVV      II  RR RR        TT     UU    UU        SS   |\n")
puts(STDOUT, "|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |\n")
puts(STDOUT, "|                                                            |\n")
puts(STDOUT, "|                                               Versao 1.0.0 |\n")
puts(STDOUT, "| Sistema integrante do projeto Livrus Virtus.               |\n")
puts(STDOUT, "| Todos os direitos reservados para Henrique F. de Souza.    |\n")
puts(STDOUT, "| Versao programada na linguagem euphoria.                   |\n")
puts(STDOUT, "*------------------------------------------------------------*\n")
 for ncont = 1 to 4 do
  puts(STDOUT, "\n")
 end for
 puts(STDOUT, MSG_PRESS)
 cont = wait_key()
 puts(STDOUT,"\n")
end procedure
-- ----------------------------------------------------------------------------
-- Mostra a tela de login do sistema.
-- retorna - se o login foi validado corretamente
-- ----------------------------------------------------------------------------
function frmLogin()
boolean bret
sequence slinha

 bret=FALSE
 puts(STDOUT, "*--------------------------------------------------------------*\n")
 puts(STDOUT, "| Login do sistema                                             |\n")
 puts(STDOUT, "*--------------------------------------------------------------*\n")
  slinha=validaEntrada(tfUsuario, opUsuario, 1, tUsuario[LOGIN], 3,
        FALSE, opTexto)
  if equal(slinha, "")=FALSE then
     slinha=validaEntrada(tfUsuario, opUsuario, 2, tUsuario[SENHA], 3,
        FALSE, opSenha)
     if equal(slinha, "")=FALSE then
        tUsuario[LOGIN]=trim(copy(slinha, 1, 10))
        tUsuario[SENHA]=trim(copy(slinha, 11, 10))
        bret=TRUE
     end if
  end if
 puts(STDOUT, "\n")
return bret
end function

-- ----------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-- ----------------------------------------------------------------------------
procedure subMenu3(integer nmenu, ctArqs sreg)
integer opSubMenu
sequence opCSubMenu
boolean bSOp

bSOp=TRUE
if nmenu = 9 then
    while bSOp do      
      opSubMenu = digita(menu(nmenu), TRUE)
      if opSubMenu = 1 then 
        btnAcao(sreg, opSalvarAlteracao) 
        bSOp=FALSE
      elsif opSubMenu = 2 then bSOp=FALSE
      else puts(STDOUT, MSG_ERRO)
      end if
    end while
elsif nmenu = 10 then
    while bSOp do      
      opCSubMenu = digita(menu(nmenu), FALSE)
      if equal(opCSubMenu,"S") or equal(opCSubMenu,"s") then
         btnAcao(sreg, opConfirmaExclusao)
         bSOp=FALSE
      elsif equal(opCSubMenu,"N") or equal(opCSubMenu,"n") then bSOp=FALSE
      else puts(STDOUT, MSG_ERRO)
      end if
    end while
end if
end procedure
-- ----------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-- ----------------------------------------------------------------------------
procedure subMenu4(integer nmenu, ctArqs sreg)
sequence opCSubMenu
boolean bSOp

bSOp=TRUE
if nmenu = 14 then
    while bSOp do      
      opCSubMenu = digita(menu(nmenu), FALSE)
      if equal(opCSubMenu,"S") or equal(opCSubMenu,"s") then
         btnAcao(sreg, opSalvarInclusao)
         bSOp=FALSE
         g_SalvarInclusao=TRUE
      elsif equal(opCSubMenu,"N") or equal(opCSubMenu,"n") then bSOp=FALSE
      else puts(STDOUT, MSG_ERRO)
      end if
    end while
end if
end procedure
-- ----------------------------------------------------------------------------
-- Realiza os cadastros dos arquivos que se ligam a outros arquivos.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- sCodigo - um das chaves do arquivo de ligação
-- ----------------------------------------------------------------------------
procedure frmCadLigados(ctArqs sreg, ctAcao sacao, sequence sCodigo)
integer nQtd, nCont, nQtdEstoque, nstatus 
atom nTotalPreco
sequence slinha, sTotalPreco, sPreco, sQtd

sQtd = ""
if sacao=opNovo then
  nCont=1
  if sreg=opLivroAss then
    sQtd=validaNumero("Quantos assuntos quer cadastrar?: ", sQtd)
    nQtd=StrToNum(sQtd)
    nstatus = seek(tfLivroAss, 0)
    while nCont <= nQtd do
      tLivroAss[ISBN]=sCodigo
      tLivroAss[CODASSUNTO] = digita(rotulo(opLivroAss, 2), FALSE)
      slinha=pesqArq(tfAssunto, tLivroAss[CODASSUNTO],1,10,tamReg(opAssunto))
      puts(STDOUT, " " & rotulo(opAssunto, 2))
      puts(STDOUT,copy(slinha, g_nPosChave, g_nTamChave) & "\n")
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg))
      subMenu4(14, sreg)
      nCont=nCont+1
    end while
  elsif sreg=opLivroAut then
    sQtd=validaNumero("Quantos autores quer cadastrar?: ",sQtd)
    nQtd=StrToNum(sQtd)
    nstatus = seek(tfLivroAut, 0)
    while nCont <= nQtd do
      tLivroAut[ISBN]=sCodigo
      tLivroAut[CODAUTOR] = digita(rotulo(opLivroAut, 2), FALSE)
      slinha=pesqArq(tfAutor, tLivroAut[CODAUTOR],1,10,tamReg(opAutor))
      puts(STDOUT," " & rotulo(opAutor, 2))
      puts(STDOUT,copy(slinha, g_nPosChave, g_nTamChave) & "\n")
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg))
      subMenu4(14, sreg)
      nCont=nCont+1
    end while
  elsif sreg=opVenda then
    sQtd=validaNumero("Quantos livros quer vender?: ",sQtd)
    nQtd=StrToNum(sQtd)
    nTotalPreco=0.0
    while nCont <= nQtd do
      slinha=validaEntrada(tfLivro,opLivro,1,tVenda[ISBNVENDA],3,FALSE,opTexto)
      if equal(slinha, "")=FALSE then
        tVenda[ISBNVENDA]=trim(copy(slinha,1,13))
        if validaISBN(tVenda[ISBNVENDA]) then
          mostrarDados(sreg, "", 1)
          tLivro[QTDESTOQUE]=trim(copy(slinha,134,10))
          nQtdEstoque=StrToNum(tLivro[QTDESTOQUE])
          if nQtdEstoque > 0 then
             nTotalPreco=nTotalPreco + g_nPreco
             sPreco=NumToStr(g_nPreco)
             tVenda[PRECOVENDA]=sPreco
             g_SalvarInclusao=FALSE
             subMenu4(14, sreg)
             if g_SalvarInclusao then
                slinha=pesqArq(tfLivro, tVenda[ISBNVENDA], 1, 13, tamReg(opLivro))
                if equal(slinha, "")=FALSE then
                   nQtdEstoque=nQtdEstoque-1
                   tLivro[QTDESTOQUE] = NumToStr(nQtdEstoque)
                   slinha=copy(slinha,1,133) & esp(tLivro[QTDESTOQUE],10)
                   escreveArq(tfLivro, slinha, "", "")
                end if
             end if
             nCont=nCont+1
          else puts(STDOUT, MSG_SEMESTOQUE)
          end if
        else puts(STDOUT, MSG_ISBNINV)
        end if
      end if
    end while
    sTotalPreco=NumToStr(nTotalPreco)
    puts(STDOUT, "Total de " & rotulo(sreg,4) & sTotalPreco & "\n")
  end if
elsif sacao=opExcluir then
  if sreg=opLivroAss then
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo)
  elsif sreg=opLivroAut then
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo)
  end if
end if

end procedure
-- ----------------------------------------------------------------------------
-- Realiza os cadastros de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure frmCadastros2(ctArqs sreg, ctAcao sacao)
if sreg=opAssunto then
   if sacao=opAlterar then
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opAutor then
   if sacao=opAlterar then
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opEditora then
   if sacao=opAlterar then
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opEndereco then
   if sacao=opAlterar then
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opIdioma then
   if sacao=opAlterar then
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opPais then
   if sacao=opAlterar then
      puts(STDOUT, rotulo(sreg, 1) & tPais[CODIGO])
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opProfissao then
   if sacao=opAlterar then
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
elsif sreg=opLivro then
   if sacao=opAlterar then
      puts(STDOUT, rotulo(sreg, 1) & tLivro[ISBN])
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
      frmCadLigados(opLivroAss, opExcluir, tLivro[ISBN])
      puts(STDOUT, "Assuntos dos livros excluídos, inclua novos!\n")
      frmCadLigados(opLivroAss, opNovo, tLivro[ISBN])
      frmCadLigados(opLivroAut, opExcluir, tLivro[ISBN])
      puts(STDOUT, "Autores dos livros excluídos, inclua novos!\n")
      frmCadLigados(opLivroAut, opNovo, tLivro[ISBN])
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
      puts(STDOUT, "Assuntos dos livros sendo excluídos!\n")
      frmCadLigados(opLivroAss, opExcluir, tLivro[ISBN])
      puts(STDOUT, "Autores dos livros sendo excluídos!\n")
      frmCadLigados(opLivroAut, opExcluir, tLivro[ISBN])
   end if
elsif sreg=opCliente then
   if sacao=opAlterar then
      puts(STDOUT, rotulo(sreg, 1) & tCliente[CPF])
      mostrarDados(sreg, "", 1)
      subMenu3(9, sreg)
   elsif sacao=opExcluir then
      subMenu3(10, sreg)
   end if
end if
end procedure
-- ----------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-- ----------------------------------------------------------------------------
procedure subMenu2(integer nmenu, ctArqs sreg)
integer opSubMenu
boolean bSOp

bSOp=TRUE
if nmenu = 7 then
    while bSOp do       
       opSubMenu = digita(menu(nmenu), TRUE)
       if opSubMenu = 1 then 
         btnAcao(sreg, opSalvarInclusao) 
         bSOp=FALSE
       elsif opSubMenu = 2 then bSOp=FALSE
       else puts(STDOUT, MSG_ERRO)
       end if
    end while
elsif nmenu = 8 then
    while bSOp do      
      opSubMenu = digita(menu(nmenu), TRUE)
      if opSubMenu = 1 then 
        frmCadastros2(sreg, opAlterar)
        bSOp=FALSE
      elsif opSubMenu = 2 then 
        frmCadastros2(sreg, opExcluir) 
        bSOp=FALSE
      elsif opSubMenu = 3 then bSOp=FALSE
      else puts(STDOUT, MSG_ERRO)
      end if
    end while
end if
end procedure

-- ----------------------------------------------------------------------------
-- Realiza os cadastros de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure frmCadastros(ctArqs sreg, ctAcao sacao)
sequence slinha

if sreg=opAssunto then
   if sacao=opNovo then
      tAssunto[CODIGO]=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu2(7, sreg)
   elsif sacao=opPesquisar then
     slinha=validaEntrada(tfAssunto,sreg,1,tAssunto[CODIGO],1,FALSE,opNumero)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opAutor then
   if sacao=opNovo then
      tAutor[CODIGO]=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu2(7, sreg)
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfAutor, sreg, 1, tAutor[CODIGO],1,FALSE,opNumero)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opEditora then
   if sacao=opNovo then
      tEditora[CODIGO]=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu2(7, sreg)
   elsif sacao=opPesquisar then
     slinha=validaEntrada(tfEditora,sreg,1,tEditora[CODIGO],1,FALSE,opNumero)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opEndereco then
   if sacao=opNovo then
      tEndereco[CODIGO]=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu2(7, sreg)
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfEndereco,sreg,1,tEndereco[CODIGO],1,
              FALSE,opNumero)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opIdioma then
   if sacao=opNovo then
      tIdioma[CODIGO]=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu2(7, sreg)
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfIdioma,sreg,1,tIdioma[CODIGO],1,FALSE,opNumero)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opPais then
   if sacao=opNovo then
      tPais[CODIGO] = digita(rotulo(sreg, 1), FALSE)
      slinha=pesqArq(tfPais, tPais[CODIGO], 1, 3, tamReg(sreg))
      if slinha="" then
         pesqLinhaExcluida(tfPais, tamReg(sreg))
         mostrarDados(sreg, "", 1)
         subMenu2(7, sreg)
      else puts(STDOUT, MSG_REGEXST)
      end if
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfPais, sreg, 1, tPais[CODIGO], 1, FALSE, opTexto)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opProfissao then
   if sacao=opNovo then
      tProfissao[CODIGO]=pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu2(7, sreg)
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfProfissao,sreg,1,tProfissao[CODIGO],1,
              FALSE,opNumero)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
elsif sreg=opLivro then
   if sacao=opNovo then
      tLivro[ISBN] = digita(rotulo(sreg, 1), FALSE)
      if validaISBN(tLivro[ISBN]) then
          slinha=pesqArq(tfLivro, tLivro[ISBN], 1, 13, tamReg(sreg))
          if slinha="" then
             pesqLinhaExcluida(tfLivro, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu2(7, sreg)
             frmCadLigados(opLivroAss, opNovo, tLivro[ISBN])
             frmCadLigados(opLivroAut, opNovo, tLivro[ISBN])
          else puts(STDOUT, MSG_REGEXST)
          end if
      else puts(STDOUT, MSG_ISBNINV)
      end if 
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfLivro, sreg, 1, tLivro[ISBN], 1,FALSE,opTexto)
      if equal(slinha,"")=FALSE then
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu2(8, sreg)
      end if
   end if
elsif sreg=opCliente then
   if sacao=opNovo then
      tCliente[CPF] = digita(rotulo(sreg, 1), FALSE)
      if validaCPF(tCliente[CPF]) then
          slinha=pesqArq(tfCliente, tCliente[CPF], 1, 14, tamReg(sreg))
          if equal(slinha,"") then
             pesqLinhaExcluida(tfCliente, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu2(7, sreg)
          else puts(STDOUT, MSG_REGEXST)
          end if 
      else puts(STDOUT, MSG_CPFINV)
      end if
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfCliente, sreg, 1, tCliente[CPF],1,FALSE,opTexto)
      if equal(slinha,"")=FALSE then
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu2(8, sreg)
      end if
   end if
elsif sreg=opVenda then
   if sacao=opNovo then
      tVenda[DTHRVENDA]=retDataHora()
      puts(STDOUT, rotulo(sreg, 1) & tVenda[DTHRVENDA] & "\n")
      slinha=pesqArq(tfVenda, tVenda[DTHRVENDA], 1, 19, tamReg(sreg))
      if equal(slinha,"") then
         slinha=validaEntrada(tfCliente,opCliente,1,tVenda[CPFVENDA],3,
                 FALSE,opTexto)
         if equal(slinha,"")=FALSE then
            tVenda[CPFVENDA]=trim(copy(slinha,1,14))
            if validaCPF(tVenda[CPFVENDA]) then
               puts(STDOUT, " " & rotulo(opCliente, 2)) -- Nome --
               puts(STDOUT, copy(slinha, g_nPosChave, g_nTamChave) & "\n")
               frmCadLigados(opVenda, opNovo, tVenda[CPFVENDA])
            else puts(STDOUT, MSG_CPFINV)
            end if
         end if
      else puts(STDOUT, MSG_REGEXST)
      end if
   elsif sacao=opPesquisar then
      slinha=validaEntrada(tfVenda, sreg, 1, tVenda[DTHRVENDA],1,
              FALSE,opDataHora)
      if equal(slinha,"")=FALSE then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu2(8, sreg)
      end if
   end if
end if
end procedure

-- ----------------------------------------------------------------------------
-- Realiza as consultas de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure frmConsultas(ctArqs sreg, ctAcao sacao)
sequence slinha
slinha = ""
if sreg=opAssunto then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfAssunto,sreg,2,tAssunto[ASSUNTO],1,TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opAutor then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfAutor,sreg, 2, tAutor[AUTOR], 1, TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opEditora then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfEditora,sreg,2,tEditora[EDITORA],1,TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opEndereco then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfEndereco,sreg,2,tEndereco[LOGRADOURO],1,
              TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg),
         3, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opIdioma then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfIdioma, sreg, 2, tIdioma[IDIOMA],1,TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opPais then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfPais, sreg, 2, tPais[PAIS], 1, TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opProfissao then
   if sacao=opPesquisar then
     slinha=validaEntrada(tfProfissao,sreg,2,tProfissao[PROFISSAO],1,
             TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opLivro then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfLivro, sreg, 2, tLivro[TITULO], 1, TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg),
        1, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opCliente then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfCliente, sreg, 2, tCliente[NOME],1,TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg),
        1, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if
   end if
elsif sreg=opVenda then
   if sacao=opPesquisar then
      slinha=validaEntrada(tfVenda, sreg, 2, tVenda[CPFVENDA], 1, TRUE,opTexto)
   elsif sacao=opListarTodos then
      if ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE then
        puts(STDOUT, rotulo(sreg, 0))
      end if 
   end if
end if
if equal(slinha,"") then
   puts(STDOUT, "")
end if
end procedure
-- ----------------------------------------------------------------------------
-- Mostra a tela de alteração de senha do sistema e realiza a alteração.
-- ----------------------------------------------------------------------------
procedure frmAlterarSenha()
boolean bQuebra
sequence sres, sSenhaAtual, sNovaSenha, sConfirmaSenha
integer nopcao

puts(STDOUT, rotulo(opUsuario, 1) & tUsuario[LOGIN])
nopcao=1
bQuebra=FALSE
while (bQuebra=FALSE) do
  if nopcao = 1 then
       sSenhaAtual=digitaSenha("Senha Atual: ",10)
       if equal(sSenhaAtual, tUsuario[SENHA])=FALSE then
          puts(STDOUT, MSG_SENCONFERE)
          bQuebra=TRUE
       else nopcao=2
       end if
  elsif nopcao = 2 then
       sNovaSenha=digitaSenha("Nova Senha: ",10)
       sConfirmaSenha=digitaSenha("Confirma Senha: ",10)
       if equal(sNovaSenha, sConfirmaSenha)=FALSE then
          puts(STDOUT, MSG_SENCONFIRM)
          bQuebra=TRUE
       else nopcao=3
       end if
  elsif nopcao = 3 then
       sres=pesqArq(tfUsuario, tUsuario[LOGIN], 1, 10, tamReg(opUsuario))
       if equal(sres,"") then
         puts(STDOUT, MSG_LOGINENCON)
       else
         tUsuario[SENHA]=sConfirmaSenha
         subMenu3(9,opUsuario)
         bQuebra=TRUE
       end if
  end if
end while
end procedure
-- ----------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-- ----------------------------------------------------------------------------
procedure subMenu(integer nmenu, ctArqs sreg)
integer opSubMenu
sequence opCSubMenu
boolean bSOp

bSOp=TRUE
if nmenu = 6 then
    while bSOp do       
       opSubMenu = digita(menu(nmenu), TRUE)
       if opSubMenu = 1 then frmCadastros(sreg, opNovo)
       elsif opSubMenu = 2 then frmCadastros(sreg, opPesquisar)
       elsif opSubMenu = 3 then bSOp=FALSE
       else puts(STDOUT, MSG_ERRO)
       end if
    end while
elsif nmenu = 12 then
    while bSOp do      
      opSubMenu = digita(menu(nmenu), TRUE)
      if opSubMenu = 1 then frmConsultas(sreg, opPesquisar)
      elsif opSubMenu = 2 then frmConsultas(sreg, opListarTodos)
      elsif opSubMenu = 3 then bSOp=FALSE
      else puts(STDOUT, MSG_ERRO)
      end if
    end while
elsif nmenu = 14 then
    while bSOp do      
      opCSubMenu = digita(menu(nmenu), FALSE)
      if equal(opCSubMenu,"S") or equal(opCSubMenu,"s") then
         btnAcao(sreg, opSalvarInclusao)
         bSOp=FALSE
         g_SalvarInclusao=TRUE
      elsif equal(opCSubMenu,"N") or equal(opCSubMenu,"n") then bSOp=FALSE
      else puts(STDOUT, MSG_ERRO)
      end if
    end while
end if
end procedure
-- ----------------------------------------------------------------------------
-- Seleciona o submenu e/ou a tela certa de acordo com número do menu.
-- nmenu - o número do menu
-- ----------------------------------------------------------------------------
procedure usaMenu(integer num)
integer opSubMenu
boolean bSOp
sequence opSair

 bSOp=TRUE
 if num = 1 then -- Cadastros --
   while bSOp do     
     opSubMenu = digita(menu(2), TRUE)
     if opSubMenu = 1 then subMenu(6, opAssunto)
     elsif opSubMenu = 2 then subMenu(6, opAutor)
     elsif opSubMenu = 3 then subMenu(6, opEditora)
     elsif opSubMenu = 4 then subMenu(6, opEndereco)
     elsif opSubMenu = 5 then subMenu(6, opIdioma)
     elsif opSubMenu = 6 then subMenu(6, opPais)
     elsif opSubMenu = 7 then subMenu(6, opProfissao)
     elsif opSubMenu = 8 then subMenu(6, opCliente)
     elsif opSubMenu = 9 then subMenu(6, opLivro)
     elsif opSubMenu = 10 then bSOp=FALSE
     else puts(STDOUT, MSG_ERRO)
     end if
   end while
 elsif num = 2 then --  Pesquisas --
   while bSOp do     
     opSubMenu = digita(menu(3), TRUE)
     if opSubMenu = 1 then subMenu(12, opAssunto)
     elsif opSubMenu = 2 then subMenu(12, opAutor)
     elsif opSubMenu = 3 then subMenu(12, opEditora)
     elsif opSubMenu = 4 then subMenu(12, opEndereco)
     elsif opSubMenu = 5 then subMenu(12, opIdioma)
     elsif opSubMenu = 6 then subMenu(12, opPais)
     elsif opSubMenu = 7 then subMenu(12, opProfissao)
     elsif opSubMenu = 8 then subMenu(12, opCliente)
     elsif opSubMenu = 9 then subMenu(12, opLivro)
     elsif opSubMenu = 10 then bSOp=FALSE
     else puts(STDOUT, MSG_ERRO)
     end if
   end while
 elsif num = 3 then --  Vendas --
   while bSOp do     
     opSubMenu = digita(menu(4), TRUE)
     if opSubMenu = 1 then subMenu(6, opVenda)
     elsif opSubMenu = 2 then subMenu(12, opVenda)
     elsif opSubMenu = 3 then bSOp=FALSE
     else puts(STDOUT, MSG_ERRO)
     end if
   end while
 elsif num = 4 then --  Opcoes --
   while bSOp do     
     opSubMenu = digita(menu(5), TRUE)
     if opSubMenu = 1 then frmAlterarSenha()
     elsif opSubMenu = 2 then frmSobre()
     elsif opSubMenu = 3 then         
         opSair = digita(menu(11), FALSE)
         if equal(opSair,"S") or equal(opSair,"s") then
            fechaArqs()
            abort(0)
         end if
     elsif opSubMenu = 4 then bSOp=FALSE
     else puts(STDOUT, MSG_ERRO)
     end if
   end while
 end if
end procedure

-- ----------------------------------------------------------------------------
-- Parte inicial do código
-- ----------------------------------------------------------------------------
procedure main()
--  if (Argument_Count > 0) then
--     if (Argument(1)="-cria") then
--       abrecriaArqs(FALSE)
--     end if
--  else
   frmSplash()
   abrecriaArqs(TRUE)
   if frmLogin() then
     bopcao=TRUE
     while bopcao do       
       opmenu = digita(menu(1), FALSE)
       if equal(opmenu,"C") or equal(opmenu,"c") then usaMenu(1)
       elsif equal(opmenu,"P") or equal(opmenu,"p") then usaMenu(2)
       elsif equal(opmenu,"V") or equal(opmenu,"v") then usaMenu(3)
       elsif equal(opmenu,"O") or equal(opmenu,"o") then usaMenu(4)
       else puts(STDERR, MSG_ERRO)
       end if
     end while
   else
     fechaArqs()
     abort(0)
   end if
--  end if
end procedure

main()
