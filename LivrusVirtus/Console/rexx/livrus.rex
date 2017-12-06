#!/usr/local/bin/rexx
/*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem pascal.
------------------------------------------------------------------------------*/
/* programa Livrus */

  tAssunto.codigo = ''
  tAssunto.assunto = ''
  
  tAutor.codigo = ''
  tAutor.autor = ''
  
  tEditora.codigo = ''
  tEditora.editora = ''
  
  tIdioma.codigo = ''
  tIdioma.idioma = ''
  
  tUsuario.login = ''
  tUsuario.senha = ''
  
  tPais.codigo = ''
  tPais.pais = ''
  
  tProfissao.codigo = ''
  tProfissao.profissao = ''
  
  tLivro.isbn = ''
  tLivro.titulo = ''
  tLivro.edicao = ''
  tLivro.anopubli = ''
  tLivro.codeditora = ''
  tLivro.volume = ''
  tLivro.codidioma = ''
  tLivro.npaginas = ''
  tLivro.preco = ''
  tLivro.qtdestoque = ''
  
  tLivroAss.isbn = ''
  tLivroAss.codassunto = ''
  
  tLivroAut.isbn = ''
  tLivroAut.codautor = ''
  
  tCliente.cpf = ''
  tCliente.nome = ''
  tCliente.email = ''
  tCliente.identidade = ''
  tCliente.sexo = ''
  tCliente.telefone = ''
  tCliente.dtnascimento = ''
  tCliente.codendereco = ''
  tCliente.codpais = ''
  tCliente.codprofissao = ''
  
  tEndereco.codigo = ''
  tEndereco.logradouro = ''
  tEndereco.bairro = ''
  tEndereco.cep = ''
  tEndereco.cidade = ''
  tEndereco.estado = ''
  
  tVenda.dthrvenda = ''  /* data/hora da venda dd/mm/yyyy hh:mm:ss */
  tVenda.cpf = ''
  tVenda.isbn = ''
  tVenda.precovenda = ''

  g_nPreco = 0.0
  g_SalvarInclusao = false

/*------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------*/
call main

main: procedure

call constantes
/* if argumentostr(1)='-cria' then
     call abrecriaArqs false
 else do*/
   call frmSplash
   call abrecriaArqs true
   if frmLogin()=true then do
     bopcao=true
     do while bopcao=true
       call menu(1)
       opmenu = linein()
       if (opmenu='C') | (opmenu='c') then call usaMenu 1
       else if (opmenu='P') | (opmenu='p') then call usaMenu 2
       else if (opmenu='V') | (opmenu='v') then call usaMenu 3
       else if (opmenu='O') | (opmenu='o') then call usaMenu 4
       else say MSG_ERRO
     end
   end 
   else do
     call fechaArqs
     exit
   end
/* end */

return

constantes:
  
  /* constantes */
  
  true = 1; false = 0
  
  /* ctTipo */
  opTexto = 1; opNumero = 2; opData = 3; opDataHora = 4; opSenha = 5
  /* ctArqs */ 
  opAssunto = 1; opAutor = 2; opEditora = 3; opEndereco = 4; opIdioma = 5 
  opPais = 6; opProfissao = 7; opCliente = 8; opLivro = 9; opLivroAss = 10
  opLivroAut = 11; opUsuario = 12; opVenda = 13
  /* ctAcao */
  opNovo = 1; opAlterar = 2; opPesquisar = 3; opSalvarInclusao = 4;
  opSalvarAlteracao = 5; opExcluir = 6; opConfirmaExclusao = 7; opListarTodos = 8
  
  CRLF = '\r\n' /* windows */
  TAM_CRLF = 2
  /* CRLF = '\n'
     TAM_CRLF = 1 */ /* unix */
  /* CRLF = '\r'
     TAM_CRLF = 1 */ /* macintosh */
  
  QTD_MAX_LINHA = 18
  
  MSG_ERRO = 'Erro: opção inválida digite de novo'
  MSG_OPCAO = 'Escolha uma opção: '
  MSG_PRESS = 'pressione para continuar...'
  
  MSG_REGINC = 'registro incluido!'
  MSG_REGNINC = 'registro não incluido!'
  MSG_REGALT = 'registro alterado!'
  MSG_REGNALT = 'registro não alterado!'
  MSG_REGEXC = 'registro excluido!'
  MSG_REGNEXC = 'registro não excluido!'
  MSG_REGEXST = 'registro já existe!'
  
  MSG_NUMINV = 'Número inválido ou menor do que 1!'
  MSG_DATAINV = 'Data inválida!, formato correto (dd/mm/yyyy)'
  MSG_DTHRINV = 'Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)'
  MSG_ISBNINV = 'ISBN inválido!'
  MSG_CPFINV = 'CPF inválido!'
  MSG_SENCONFERE = 'senha não confere com a senha atual!'
  MSG_SENCONFIRM = 'nova senha não confere com a senha confirmada!'
  MSG_LOGINENCON = 'login não encontrado!'
  MSG_SEMESTOQUE = 'livro não existe no estoque!'
  
  ARQ_ASSUNTO = 'assunto.dat'
  ARQ_AUTOR = 'autor.dat'
  ARQ_EDITORA = 'editora.dat'
  ARQ_IDIOMA = 'idioma.dat'
  ARQ_USUARIO = 'usuario.dat'
  ARQ_PAIS = 'pais.dat'
  ARQ_PROFISSAO = 'profissao.dat'
  ARQ_LIVRO = 'livro.dat'
  ARQ_LIVASS = 'livroass.dat'
  ARQ_LIVAUT = 'livroaut.dat'
  ARQ_CLIENTE = 'cliente.dat'
  ARQ_ENDERECO = 'endereco.dat'
  ARQ_VENDA = 'venda.dat'
  
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
  
  tfAssunto = ARQ_ASSUNTO; tfAutor = ARQ_AUTOR; tfEditora = ARQ_EDITORA
  tfIdioma = ARQ_IDIOMA; tfEndereco = ARQ_ENDERECO; tfPais = ARQ_PAIS 
  tfProfissao = ARQ_PROFISSAO; tfLivro = ARQ_LIVRO; tfLivroAss = ARQ_LIVASS 
  tfLivroAut = ARQ_LIVAUT; tfCliente = ARQ_CLIENTE; tfUsuario = ARQ_USUARIO 
  tfVenda = ARQ_VENDA
  
return

/*--- Rotinas básicas ---------------------------------------------------------*/

/*------------------------------------------------------------------------------
Repete um texto um número determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*/
repete: procedure
  parse arg sTexto, nQtd
  sret = left(sTexto,nQtd,sTexto)
return sret

/*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*/
esp: procedure
  parse arg sTexto, nTam
  sret = left(sTexto,nTam)
return sret

/*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*/
strRelativa: procedure
  parse arg sTexto, sChave

call constantes
  if countstr(sChave,sTexto) > 0 then
     bret = true
  else
     bret = false
return bret
/*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a mstring com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*/
modulo11: procedure 
  parse arg valor, dig

call constantes  
nsoma = 0; nvalor = 0; npos = 0; nmodulo11 = 0
sres = ''; slocal = ''
ncont = 1
do while ncont <= 11
  slocal = substr(svalor,ncont,1) || slocal
  ncont = ncont + 1
end
nsoma = 0
if ndig=1 then
  ncont = 3
else
  ncont = 2

npos = 2
do while ncont <= 11
  sres=substr(slocal,ncont,1)
  nvalor = sres
  nsoma=nsoma + (nvalor * npos)
  ncont=ncont+1
  npos=npos+1
end
nsoma=(11 - (nsoma // 11))

if nsoma > 9 then
  nmodulo11=0
else
  nmodulo11=nsoma

return nmodulo11
/*------------------------------------------------------------------------------
Validação de um número de CPF qualquer.
cpf - a mstring com o número do CPF
retorna - se é valido ou não
------------------------------------------------------------------------------*/
validaCPF: procedure
  parse arg cpf

call constantes
scpf = ''; sres = ''
nvalor1 = 0; nvalor2 = 0
bvalidaCPF=false

if length(cpf)=14 then do
  scpf=substr(cpf,1,3) || substr(cpf,5,3) || substr(cpf,9,3) || substr(cpf,13,2)
  sres=substr(cpf,13,1)
  nvalor1 = sres
  sres=substr(cpf,14,1)
  nvalor2 = sres
  if ((modulo11(scpf,1)=nvalor1) & (modulo11(scpf,2)=nvalor2)) then
    bvalidaCPF=true
  else
    bvalidaCPF=false
end 
else do
  bvalidaCPF=false
end
return bvalidaCPF
/*------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a mstring com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------*/
validaISBN: procedure
  parse arg isbn

call constantes
sisbn = ''; snum = ''; sdigito = ''; bvalidaISBN = false
ncont = 0; nsoma = 0; nvalor = 0;

if length(isbn)=13 then do
  sdigito=substr(isbn, length(isbn), 1)
  sisbn=''
  do cont=1 to length(isbn)-1
    if substr(isbn,cont,1)<>'-' then
      sisbn = sisbn || substr(isbn,cont,1)
  end
  if sdigito = 'X' then
    nsoma = 10
  else do
    nvalor = sdigito
    nsoma = nvalor
  end
  do ncont=1 to 9
    snum = substr(sisbn, ncont, 1)
    nvalor = snum
    nsoma = nsoma + (nvalor * (11 - ncont))
  end
  if (nsoma // 11) = 0 then
    bvalidaISBN=true
  else
    bvalidaISBN=false
end 
else do
  bvalidaISBN=false
end
return bvalidaISBN
/*------------------------------------------------------------------------------
Esconde a digitação da senha
retorna - a senha digitada
------------------------------------------------------------------------------*/
digitaSenha: procedure 
  parse arg sRotulo, nTamSenha

call charout ,sRotulo
sSenha = linein()
/*  ncont = 0
  sSenha=''
  sLetra='\0'
  do while (sLetra<>'\r') & (ncont < nTamSenha)
    sLetra=readkey
    sSenha=sSenha || sLetra
    ncont=ncont+1
  end */
return sSenha

/*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a mstring com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*/
validaNumero: procedure
  parse arg sRotulo, sNumero

call constantes
nnum = 0.0
sNumero = ''
nStatus=-1
do while nStatus<>0
  call charout ,sRotulo
  sNumero = linein()
  /* nnum = strtoint(sNumero) */
  nnum = sNumero
  if datatype(nnum)='NUM' then
    if nnum < 1 then
      say MSG_NUMINV
    else
      nStatus = 0
  else
    say MSG_NUMINV
end
return sNumero
/*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a mstring com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*/
validaDataHora: procedure
  parse arg sRotulo, sDataHora, bSoData

call constantes
sdia = ''; smes = ''; sano = ''; shora = ''; smin = ''; sseg = ''
ndia = 0; nmes = 0; nano = 0; nhora = 0; nmin = 0; nseg = 0; ntam = 0

bvalida=false
bdatavalida=false
bhoravalida=false
nudiames=0

if bSoData=true then ntam=10
else ntam=19
do while bvalida=false
  call charout ,sRotulo
  sDataHora = linein()
  if length(sDataHora)=ntam then do
    sdia=substr(sDataHora,1,2)
    ndia=sdia
    smes=substr(sDataHora,4,2)
    nmes=smes
    sano=substr(sDataHora,7,4)
    nano=sano
  
    if (nano >= 1) & (nano <= 9999) then do
      if (nmes >= 1) & (nmes <= 31) then do
          select
            when nmes=1 | nmes=3 | nmes=5 | nmes=7 | nmes=8 then nudiames=31
            when nmes=10 | nmes=12 then nudiames=31
            when nmes=2 then do
                /* ano bissexto */
                if (nano // 4)=0 then nudiames=29
                else nudiames=28
            end
            when nmes=4 | nmes=6 | nmes=9 | nmes=11 then nudiames=30
          end
          if (ndia >=1) & (ndia <=nudiames) then
             bdatavalida=true
      end
    end
  
    if bSoData=true then do
       if bdatavalida=true then bvalida=true
       else say MSG_DATAINV
    end 
    else do
      if bdatavalida then do
          shora=substr(sDataHora,12,2)
          nhora=shora
          smin=substr(sDataHora,15,2)
          nmin=smin
          sseg=substr(sDataHora,18,2)
          nseg=sseg
     
          if (nhora >= 0) & (nhora <= 23) then do
            if (nmin >= 0) & (nmin <= 59) then do
              if (nseg >= 0) & (nseg <= 59) then
                 bhoravalida=true
            end
          end
  
          if bhoravalida=true then bvalida=true
          else say MSG_DTHRINV
      end 
      else do
        say MSG_DTHRINV
      end
    end
  end 
  else do
    if bSoData=true then say MSG_DATAINV
    else say MSG_DTHRINV
  end
end
return sDataHora
/*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*/
retDataHora: procedure
  sdia = substr(date('S'),7,2) 
  smes = substr(date('S'),5,2) 
  sano = substr(date('S'),1,4)
  sdata = sdia'/'smes'/'sano
  stempo = sdata time('N')
return stempo

/*--- Rotinas de manipulação de arquivos --------------------------------------*/

/*------------------------------------------------------------------------------
Verifica se chegou ao fim do arquivo.
sArq - o arquivo
retorna - se chegou ao fim do arquivo
------------------------------------------------------------------------------*/
fimArq: procedure
  parse arg sArq

call constantes
npos = stream(sArq,'C','QUERY SEEK READ CHAR')
ntam = stream(sArq,'C','QUERY SIZE')
if npos = (ntam+1) then
  bret = true
else
  bret = false
return bret
/*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*/
tamArq: procedure
  parse arg sArq

  nret = stream(sArq,'C','QUERY SIZE')
return nret

/*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*/
abrecriaArqs: procedure
  parse arg bAbre

call constantes
if bAbre then do
  if stream(ARQ_ASSUNTO, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_ASSUNTO,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_ASSUNTO
  if stream(ARQ_AUTOR, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_AUTOR,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_AUTOR
  if stream(ARQ_EDITORA, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_EDITORA,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_EDITORA
  if stream(ARQ_IDIOMA, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_IDIOMA,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_IDIOMA
  if stream(ARQ_ENDERECO, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_ENDERECO,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_ENDERECO
  if stream(ARQ_PAIS, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_PAIS,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_PAIS
  if stream(ARQ_PROFISSAO, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_PROFISSAO,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_PROFISSAO
  if stream(ARQ_LIVRO, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_LIVRO,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_LIVRO
  if stream(ARQ_LIVASS, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_LIVASS,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_LIVASS
  if stream(ARQ_LIVAUT, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_LIVAUT,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_LIVAUT
  if stream(ARQ_CLIENTE, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_CLIENTE,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_CLIENTE
  if stream(ARQ_USUARIO, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_USUARIO,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_USUARIO
  if stream(ARQ_VENDA, 'C', 'QUERY EXISTS')<>'' then
    call stream ARQ_VENDA,'C','OPEN BOTH'
  else
    say MSG_ARQERRO' --> 'ARQ_VENDA
end 
else do
  call stream ARQ_ASSUNTO,'C','OPEN WRITE REPLACE'
  call stream ARQ_AUTOR,'C','OPEN WRITE REPLACE'
  call stream ARQ_EDITORA,'C','OPEN WRITE REPLACE'
  call stream ARQ_IDIOMA,'C','OPEN WRITE REPLACE'
  call stream ARQ_ENDERECO,'C','OPEN WRITE REPLACE'
  call stream ARQ_PAIS,'C','OPEN WRITE REPLACE'
  call stream ARQ_PROFISSAO,'C','OPEN WRITE REPLACE'
  call stream ARQ_LIVRO,'C','OPEN WRITE REPLACE'
  call stream ARQ_LIVASS,'C','OPEN WRITE REPLACE'
  call stream ARQ_LIVAUT,'C','OPEN WRITE REPLACE'
  call stream ARQ_CLIENTE,'C','OPEN WRITE REPLACE'
  call stream ARQ_USUARIO,'C','OPEN WRITE REPLACE'
  call stream ARQ_VENDA,'C','OPEN WRITE REPLACE'
end
return
/*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*/
fechaArqs : procedure
 call constantes
 call stream ARQ_ASSUNTO,'C','CLOSE'
 call stream ARQ_AUTOR,'C','CLOSE'
 call stream ARQ_EDITORA,'C','CLOSE'
 call stream ARQ_IDIOMA,'C','CLOSE'
 call stream ARQ_ENDERECO,'C','CLOSE'
 call stream ARQ_PAIS,'C','CLOSE'
 call stream ARQ_PROFISSAO,'C','CLOSE'
 call stream ARQ_LIVRO,'C','CLOSE'
 call stream ARQ_LIVASS,'C','CLOSE'
 call stream ARQ_LIVAUT,'C','CLOSE'
 call stream ARQ_CLIENTE,'C','CLOSE'
 call stream ARQ_USUARIO,'C','CLOSE'
 call stream ARQ_VENDA,'C','CLOSE'
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
pesqArq: procedure
  parse arg sArq, sChave, nPosChave, nTamChave, nTamLinha

call constantes
slinha = ''; sres = ''; sret = ''
nPosicao = 0
bQuebra=false
call stream sArq, 'C', 'SEEK =0 READ LINE'
do while (fimArq(sArq)=false) & (bQuebra=false)
  slinha = linein(sArq)
  sres=strip(substr(slinha,nPosChave,nTamChave))
  if sres=sChave then
     bQuebra=true
end
nPosicao = stream(sArq,'C','QUERY SEEK READ')
if nPosicao<>'' then
  nPosicao=nPosicao-(nTamLinha + TAM_CRLF)
else
  nPosicao = 0 
if nPosicao > 0 then
  call stream sArq, 'C', 'SEEK =' || nPosicao || ' READ LINE'
else
  call stream sArq, 'C', 'SEEK =0 READ LINE'
if sres<>sChave then
   sret=''
else
   sret=substr(slinha,1,nTamLinha)

return sret
/*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*/
pesqLinhaExcluida: procedure
  parse arg sArq, nTamLinha

sExcluido=pesqArq(sArq, '*', 1, 1, nTamLinha)
if sExcluido='' then
  call stream sArq, 'C', 'SEEK =' || tamArq(sArq) || ' READ LINE'
return
/*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*/
pesqMaxCod: procedure
  parse arg sArq, nPosChave, nTamChave, nTamLinha

call constantes
slinha = ''; sres = ''
nCod = 0
bQuebra=false
nMaior=0
call stream sArq, 'C', 'SEEK =0 READ LINE'
do while (fimArq(sArq)=false) & (bQuebra=false)
  slinha = linein(sArq)
  sres=strip(substr(slinha,nPosChave,nTamChave))
  nCod = sres
  if nCod > nMaior then
     nMaior=nCod
end
call pesqLinhaExcluida sArq, nTamLinha
sres = (nMaior+1)
return sres
/*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*/
escreveArq: procedure
  parse arg sArq, sTexto, sMsgAcerto, sMsgErro

/* call constantes
sTexto=sTexto || CRLF */
call lineout sArq, sTexto
say sMsgAcerto

/*say sMsgErro*/
return

/*--- Rotinas de implementação do sistema e de interface ----------------------*/

/*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*/
LinhaReg: procedure expose tAssunto.codigo tAssunto.assunto tAutor.codigo,
 tAutor.autor tEditora.codigo tEditora.editora tEndereco.codigo,
 tEndereco.logradouro tEndereco.bairro tEndereco.cep tEndereco.cidade,
 tEndereco.estado tIdioma.codigo tIdioma.idioma tPais.codigo tPais.pais,
 tProfissao.codigo tProfissao.profissao tUsuario.login tUsuario.senha,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tLivroAss.isbn tlivroAss.codassunto tLivroAut.isbn tlivroAut.codautor,
 tCliente.cpf tCliente.nome tCliente.email tCliente.identidade tCliente.sexo,
 tCliente.telefone tCliente.dtnascimento tCliente.codendereco tCliente.codpais,
 tCliente.codprofissao tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg sreg

call constantes
slinha=''
if sreg=opAssunto then
   slinha=esp(tAssunto.codigo,10) || esp(tAssunto.assunto,30)
else if sreg=opAutor then
   slinha=esp(tAutor.codigo,10) || esp(tAutor.autor,30)
else if sreg=opEditora then
   slinha=esp(tEditora.codigo,10) || esp(tEditora.editora,50)
else if sreg=opEndereco then do
   slinha=esp(tEndereco.codigo,10) || esp(tEndereco.logradouro,40)
   slinha=slinha || esp(tEndereco.bairro,15) || esp(tEndereco.cep,8) 
   slinha=slinha || esp(tEndereco.cidade,30) || esp(tEndereco.estado,20)
end
else if sreg=opIdioma then
   slinha=esp(tIdioma.codigo,10) || esp(tIdioma.idioma,20)
else if sreg=opPais then
   slinha=esp(tPais.codigo,3) || esp(tPais.pais,50)
else if sreg=opProfissao then
   slinha=esp(tProfissao.codigo,10) || esp(tProfissao.profissao,50)
else if sreg=opUsuario then
   slinha=esp(tUsuario.login,10) || esp(tUsuario.senha,10)
else if sreg=opLivro then do
   slinha=esp(tLivro.isbn,13) || esp(tLivro.titulo,50)
   slinha=slinha || esp(tLivro.edicao,10) ||  esp(tLivro.anopubli,10) 
   slinha=slinha || esp(tLivro.codeditora,10) || esp(tLivro.volume,10)
   slinha=slinha || esp(tLivro.codidioma,10) || esp(tLivro.npaginas,10)
   slinha=slinha || esp(tLivro.preco,10) || esp(tLivro.qtdestoque,10)
end
else if sreg=opLivroAss then
   slinha=esp(tLivroAss.isbn,13) || esp(tlivroAss.codassunto,10)
else if sreg=opLivroAut then
   slinha=esp(tLivroAut.isbn,13) || esp(tlivroAut.codautor,10)
else if sreg=opCliente then do
   slinha=esp(tCliente.cpf,14) || esp(tCliente.nome,30) 
   slinha=slinha || esp(tCliente.email,30) || esp(tCliente.identidade,10) 
   slinha=slinha || esp(tCliente.sexo,1) || esp(tCliente.telefone,17) 
   slinha=slinha || esp(tCliente.dtnascimento,10) || esp(tCliente.codendereco,10)
   slinha=slinha || esp(tCliente.codpais,3) || esp(tCliente.codprofissao,10)
end
else if sreg=opVenda then do
   slinha=esp(tVenda.dthrvenda,19) || esp(tVenda.cpf,14) 
   slinha=slinha || esp(tVenda.isbn,13) || esp(tVenda.precovenda,10)
end

return slinha
/*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*/
tamReg: procedure
  parse arg sreg

call constantes
if sreg=opAssunto then nret=TAM_ASSUNTO
else if sreg=opAutor then nret=TAM_AUTOR
else if sreg=opEditora then nret=TAM_EDITORA
else if sreg=opEndereco then nret=TAM_ENDERECO
else if sreg=opIdioma then nret=TAM_IDIOMA
else if sreg=opPais then nret=TAM_PAIS
else if sreg=opProfissao then nret=TAM_PROFISSAO
else if sreg=opUsuario then nret=TAM_USUARIO
else if sreg=opLivro then nret=TAM_LIVRO
else if sreg=opLivroAss then nret=TAM_LIVASS
else if sreg=opLivroAut then nret=TAM_LIVAUT
else if sreg=opCliente then nret=TAM_CLIENTE
else if sreg=opVenda then nret=TAM_VENDA

return nret
/*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------*/
rotulo: procedure
  parse arg sreg, nNum

call constantes
sret=''
if sreg=opAssunto then do
   select
     when nNum = 0 then sret='Assunto(s) não encontrado(s)!'
     when nNum = 1 then sret='Código do assunto: '
     when nNum = 2 then sret='Assunto: '
   end
end 
else if sreg=opAutor then do
   select
     when nNum = 0 then sret='Autor(es) não encontrado(s)!'
     when nNum = 1 then sret='Código do autor: '
     when nNum = 2 then sret='Autor: '
   end
end 
else if sreg=opEditora then do
   select
     when nNum = 0 then sret='Editora(s) não encontrada(s)!'
     when nNum = 1 then sret='Código da editora: '
     when nNum = 2 then sret='Editora: '
   end
end 
else if sreg=opEndereco then do
   select
     when nNum = 0 then sret='Endereço(s) não encontrado(s)!'
     when nNum = 1 then sret='Código do endereço: '
     when nNum = 2 then sret='Logradouro: '
     when nNum = 3 then sret='Bairro: '
     when nNum = 4 then sret='CEP: '
     when nNum = 5 then sret='Cidade: '
     when nNum = 6 then sret='Estado: '
   end
end 
else if sreg=opIdioma then do
   select
     when nNum = 0 then sret='Idioma(s) não encontrado(s)!'
     when nNum = 1 then sret='Código do idioma: '
     when nNum = 2 then sret='Idioma: '
   end
end 
else if sreg=opPais then do
   select
     when nNum = 0 then sret='País(es) não encontrado(s)!'
     when nNum = 1 then sret='Código do país: '
     when nNum = 2 then sret='País: '
   end
end 
else if sreg=opProfissao then do
   select
     when nNum = 0 then sret='Profissão(es) não encontrada(s)!'
     when nNum = 1 then sret='Código da profissão: '
     when nNum = 2 then sret='Profissão: '
   end
end 
else if sreg=opUsuario then do
   select
     when nNum = 0 then sret='login ou senha incorreta, tente de novo!'
     when nNum = 1 then sret='Login: '
     when nNum = 2 then sret='Senha: '
   end
end 
else if sreg=opLivro then do
   select
     when nNum = 0 then sret='Livro(s) não encontrado(s)!'
     when nNum = 1 then sret='ISBN: '
     when nNum = 2 then sret='Título: '
     when nNum = 3 then sret='Edição: '
     when nNum = 4 then sret='Ano de Publicação: '
     when nNum = 5 then sret='Código da editora: '
     when nNum = 6 then sret='Volume: '
     when nNum = 7 then sret='Código do idioma: '
     when nNum = 8 then sret='Número de páginas: '
     when nNum = 9 then sret='Preço: '
     when nNum = 10 then sret='Qtd. Estoque: '
   end
end 
else if sreg=opLivroAss then do
   select
     when nNum = 0 then sret='Assunto(s) não encontrado(s)!'
     when nNum = 1 then sret='ISBN: '
     when nNum = 2 then sret='Código do assunto: '
   end
end 
else if sreg=opLivroAut then do
   select
     when nNum = 0 then sret='Autor(s) não encontrado(s)!'
     when nNum = 1 then sret='ISBN: '
     when nNum = 2 then sret='Código do autor: '
   end
end 
else if sreg=opCliente then do
   select
     when nNum = 0 then sret='Cliente(s) não encontrado(s)!'
     when nNum = 1 then sret='CPF: '
     when nNum = 2 then sret='Nome: '
     when nNum = 3 then sret='E-mail: '
     when nNum = 4 then sret='Identidade: '
     when nNum = 5 then sret='Sexo: '
     when nNum = 6 then sret='Telefone: '
     when nNum = 7 then sret='Dt. Nascimento: '
     when nNum = 8 then sret='Código do endereço: '
     when nNum = 9 then sret='Código do país: '
     when nNum = 10 then sret='Código da Profissão: '
   end
end 
else if sreg=opVenda then do
   select
     when nNum = 0 then sret='Venda(s) não encontrada(s)!'
     when nNum = 1 then sret='Data/Hora venda: '
     when nNum = 2 then sret='CPF: '
     when nNum = 3 then sret='ISBN: '
     when nNum = 4 then sret='Preço de venda: '
   end
end

return sret
/*------------------------------------------------------------------------------
Seleciona a posicao da chave de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - a posicao da chave 
------------------------------------------------------------------------------*/
gnPosChave: procedure
  parse arg sreg, nNum

call constantes
sret=''
if sreg=opAssunto then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
end
else if sreg=opAutor then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
end 
else if sreg=opEditora then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
end 
else if sreg=opEndereco then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
   else if nNum = 3 then g_nPosChave=51
   else if nNum = 4 then g_nPosChave=66
   else if nNum = 5 then g_nPosChave=74
   else if nNum = 6 then g_nPosChave=104
end 
else if sreg=opIdioma then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
end 
else if sreg=opPais then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=4
end 
else if sreg=opProfissao then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
end 
else if sreg=opUsuario then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=11
end 
else if sreg=opLivro then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=14
   else if nNum = 3 then g_nPosChave=64
   else if nNum = 4 then g_nPosChave=74
   else if nNum = 5 then g_nPosChave=84
   else if nNum = 6 then g_nPosChave=94
   else if nNum = 7 then g_nPosChave=104
   else if nNum = 8 then g_nPosChave=114
   else if nNum = 9 then g_nPosChave=124
   else if nNum = 10 then g_nPosChave=134
end 
else if sreg=opLivroAss then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=14
end 
else if sreg=opLivroAut then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=14
end 
else if sreg=opCliente then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=15
   else if nNum = 3 then g_nPosChave=45
   else if nNum = 4 then g_nPosChave=75
   else if nNum = 5 then g_nPosChave=85
   else if nNum = 6 then g_nPosChave=86
   else if nNum = 7 then g_nPosChave=103
   else if nNum = 8 then g_nPosChave=113
   else if nNum = 9 then g_nPosChave=123
   else if nNum = 10 then g_nPosChave=126
end 
else if sreg=opVenda then do
   if nNum = 1 then g_nPosChave=1
   else if nNum = 2 then g_nPosChave=20
   else if nNum = 3 then g_nPosChave=34
   else if nNum = 4 then g_nPosChave=47
end

return g_nPosChave
/*------------------------------------------------------------------------------
Seleciona o tamanho da chave de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho da chave 
------------------------------------------------------------------------------*/
gnTamChave: procedure
  parse arg sreg, nNum

call constantes
sret=''
if sreg=opAssunto then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=30
end
else if sreg=opAutor then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=30
end 
else if sreg=opEditora then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=50
end 
else if sreg=opEndereco then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=40
   else if nNum = 3 then g_nTamChave=15
   else if nNum = 4 then g_nTamChave=8
   else if nNum = 5 then g_nTamChave=30
   else if nNum = 6 then g_nTamChave=20
end 
else if sreg=opIdioma then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=20
end 
else if sreg=opPais then do
   if nNum = 1 then g_nTamChave=3
   else if nNum = 2 then g_nTamChave=50
end 
else if sreg=opProfissao then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=50
end 
else if sreg=opUsuario then do
   if nNum = 1 then g_nTamChave=10
   else if nNum = 2 then g_nTamChave=10
end 
else if sreg=opLivro then do
   if nNum = 1 then g_nTamChave=13
   else if nNum = 2 then g_nTamChave=50
   else if nNum = 3 then g_nTamChave=10
   else if nNum = 4 then g_nTamChave=10
   else if nNum = 5 then g_nTamChave=10
   else if nNum = 6 then g_nTamChave=10
   else if nNum = 7 then g_nTamChave=10
   else if nNum = 8 then g_nTamChave=10
   else if nNum = 9 then g_nTamChave=10
   else if nNum = 10 then g_nTamChave=10
end 
else if sreg=opLivroAss then do
   if nNum = 1 then g_nTamChave=13
   else if nNum = 2 then g_nTamChave=10
end 
else if sreg=opLivroAut then do
   if nNum = 1 then g_nTamChave=13
   else if nNum = 2 then g_nTamChave=10
end 
else if sreg=opCliente then do
   if nNum = 1 then g_nTamChave=14
   else if nNum = 2 then g_nTamChave=30
   else if nNum = 3 then g_nTamChave=30
   else if nNum = 4 then g_nTamChave=10
   else if nNum = 5 then g_nTamChave=1
   else if nNum = 6 then g_nTamChave=17
   else if nNum = 7 then g_nTamChave=10
   else if nNum = 8 then g_nTamChave=10
   else if nNum = 9 then g_nTamChave=3
   else if nNum = 10 then g_nTamChave=10
end 
else if sreg=opVenda then do
   if nNum = 1 then g_nTamChave=19
   else if nNum = 2 then g_nTamChave=14
   else if nNum = 3 then g_nTamChave=13
   else if nNum = 4 then g_nTamChave=10
end

return g_nTamChave
/*------------------------------------------------------------------------------
Indica se continua ou não mostrando um número máximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou não
------------------------------------------------------------------------------*/
ContinuaSN: procedure
  parse arg nlinha, nQtdLinha

call constantes
bSOp=false
opCSubMenu = ''
bret=false
if nlinha > 0 then do
  if (nlinha // nQtdLinha) = 0 then do
    bSOp=true
    do while bSOp
      menu(13)
      opCSubMenu = linein()
      if (opCSubMenu='S') | (opCSubMenu='s') then bSOp=false
      else if (opCSubMenu='N') | (opCSubMenu='n') then do
        bret=true
        bSOp=false
      end 
      else say MSG_ERRO
    end 
  end
end

return bret
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
ListarTodos: procedure
  parse arg sArq, sreg, sChave, nPosChave, nTamChave, nTamLinha, 
            nQtdLinha, bPesqRelativa

call constantes
slinha = ''; sres = ''
bAchou = false
bRet=false
bQuebra=false
nCont=0
call mostrarDados sreg, '', 2
call stream sArq, 'C', 'SEEK =0 READ LINE'
do while (fimArq(sArq)=false) & (bQuebra=false)
  slinha = linein(sArq)
  if bPesqRelativa=true then do
    sres=strip(substr(slinha,nPosChave,nTamChave))
    if strRelativa(sres,sChave) then do
       bAchou=true
       bRet=true
    end 
    else
       bAchou=false
  end 
  else do
    bAchou=true
    bRet=true
  end

  if bAchou then do
    call mostrarDados sreg, substr(slinha,1,nTamLinha), 3
    nCont=nCont+1
  end

  bQuebra=ContinuaSN(nCont, nQtdLinha)
end
return bRet
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
ListarRegLigados: procedure
 parse arg sArq1, sreg1, nPosChave1, nTamChave1, nPosChave2, nTamChave2, sChave,
 sArq2, sreg2, nPosChave3, nQtdLinha

call constantes
slinha1 = ''; sCodigo1 = ''; sCodigo2 = ''; slinha2 = ''
bRet=false
nCont=0
bQuebra=false
mostrarDados(sreg2, '', 2)
call stream sArq1, 'C', 'SEEK =0 READ LINE'
do while (fimArq(sArq1)=false) & (bQuebra=false)
  slinha1 = linein(sArq1)
  sCodigo1=strip(substr(slinha1,nPosChave1,nTamChave1))
  if sCodigo1=sChave then do
    sCodigo2=strip(substr(slinha1,nPosChave2,nTamChave2))
    slinha2=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
    mostrarDados(sreg2, substr(slinha2, 1, tamReg(sreg2)), 3)
    bRet=true
    nCont=nCont+1
  end
  bQuebra=ContinuaSN(nCont, nQtdLinha)
end
if bRet=false then
   say rotulo(sreg2,0)
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
validaEntrada: procedure
  parse arg sArq,sreg,nTexto,sEntrada,nTentativas,bPesqRelativa,bTipoEntrada

call constantes
sres = '' 
nTamLinha=tamReg(sreg)
sMsgErro=rotulo(sreg,0)
sTexto=rotulo(sreg,nTexto)
nPosChave=gnPosChave(sreg,nTexto)
nTamChave=gnTamChave(sreg,nTexto)

ncont=1
bQuebra=false
  do while (bQuebra=false) & (ncont <= nTentativas )
    if bTipoEntrada=opTexto then do
      call charout ,sTexto
      sEntrada = linein()
    end 
    else if bTipoEntrada=opNumero then
       sEntrada=validaNumero(sTexto,sEntrada)
    else if bTipoEntrada=opData then
       sEntrada=validaDataHora(sTexto,sEntrada,true)
    else if bTipoEntrada=opDataHora then
       sEntrada=validaDataHora(sTexto,sEntrada,false)
    else if bTipoEntrada=opSenha then 
       sEntrada=digitaSenha(sTexto, 10)

    if bPesqRelativa=true then do
       if ListarTodos(sArq,sreg,sEntrada,nPosChave,nTamChave,nTamLinha,
          QTD_MAX_LINHA,true)=true then
          sres=' '
    end 
    else
      sres=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)   

    if sres='' then
       say sMsgErro
    else
       bQuebra=true

    ncont=ncont+1
  end
return sres
/*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*/
frmSplash: procedure

call constantes
cont = 0
 say '*---------------------------------------',
 '-------------------------------------*'
 say '| LL    II VV   VV RRRRR  UU  UU   SSSS ',
 'VV   VV II RRRRR  TTTT UU  UU   SSSS |'
 say '| LL    II  VV VV  RR   R UU  UU  SS    ',
 ' VV VV  II RR   R  TT  UU  UU  SS    |'
 say '| LL    II   VVV   RRRRR  UU  UU    SS  ',
 '  VVV   II RRRRR   TT  UU  UU    SS  |'
 say '| LLLLL II    V    RR   R  UUUU  SSSS   ',
 '   V    II RR   R  TT   UUUU  SSSS   |'
 say '*---------------------------------------',
 '-------------------------------------*'
 do cont=1 to 18 
   say ''
 end
 call charout ,MSG_PRESS
 cont = linein()
return
/*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*/
frmSobre: procedure

call constantes
cont = 0
 say '*------------------------------------------------------------*'
 say '|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |'
 say '|  LL        II   VV     VV   RR     R  UU    UU  SS         |'
 say '|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |'
 say '|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |'
 say '|  LLLL      II      VVV      RR RR     UU    UU        SS   |'
 say '|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |'
 say '|                                                            |'
 say '|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |'
 say '|   VV     VV   II  RR     R     TT     UU    UU  SS         |'
 say '|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |'
 say '|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |'
 say '|      VVV      II  RR RR        TT     UU    UU        SS   |'
 say '|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |'
 say '|                                                            |'
 say '|                                               Versao 1.0.0 |'
 say '| Sistema integrante do projeto Livrus Virtus.               |'
 say '| Todos os direitos reservados para Henrique F. de Souza.    |'
 say '| Versao programada na linguagem rexx.                       |'
 say '*------------------------------------------------------------*'
 do cont=1 to 4
   say ''
 end
 call charout ,MSG_PRESS
 cont = linein()
return
/*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*/
frmLogin: procedure

call constantes
slinha = ''
bret=false
say '*--------------------------------------------------------------*'
say '| Login do sistema                                             |'
say '*--------------------------------------------------------------*'
slinha=validaEntrada(tfUsuario, opUsuario, 1, tUsuario.login, 3, false, opTexto)
if slinha<>'' then do
   slinha=validaEntrada(tfUsuario, opUsuario, 2, tUsuario.senha, 3, false, opSenha)
   if slinha<>'' then do
      tUsuario.login=strip(substr(slinha, 1, 10))
      tUsuario.senha=strip(substr(slinha, 11, 10))
      bret=true
   end
end
say ''
return bret
/*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*/
menu: procedure
  parse arg num

call constantes
 if (num=1) then do
  say '*--------------------------------------------------------------*'
  say '| (C)adastros        (P)esquisas     (V)endas        (O)pções  |'
  say '*--------------------------------------------------------------*'
 end 
 else if (num=2) then do
   say '*---------------------------------*'
   say '| 01. Cadastro de Assuntos        |'
   say '| 02. Cadastro de Autores         |'
   say '| 03. Cadastro de Editoras        |'
   say '| 04. Cadastro de Endereços       |'
   say '| 05. Cadastro de Idiomas         |'
   say '| 06. Cadastro de Países          |'
   say '| 07. Cadastro de Profissões      |'
   say '| 08. Cadastro de Clientes        |'
   say '| 09. Cadastro de Livros          |'
   say '| 10. Voltar ao menu              |'
   say '*---------------------------------*'
 end 
 else if (num=3) then do
   say '*---------------------------------*'
   say '| 01. Consulta de Assuntos        |'
   say '| 02. Consulta de Autores         |'
   say '| 03. Consulta de Editoras        |'
   say '| 04. Consulta de Endereços       |'
   say '| 05. Consulta de Idiomas         |'
   say '| 06. Consulta de Países          |'
   say '| 07. Consulta de Profissões      |'
   say '| 08. Consulta de Clientes        |'
   say '| 09. Consulta de Livros          |'
   say '| 10. Voltar ao menu              |'
   say '*---------------------------------*'
 end 
 else if (num=4) then do
   say '*---------------------------------*'
   say '| 01. Vender Livros               |'
   say '| 02. Vendas Realizadas           |'
   say '| 03. Voltar ao menu              |'
   say '*---------------------------------*'
 end 
 else if (num=5) then do
   say '*---------------------------------*'
   say '| 01. Alterar senha               |'
   say '| 02. Sobre o sistema             |'
   say '| 03. Sair do sistema             |'
   say '| 04. Voltar ao menu              |'
   say '*---------------------------------*'
 end 
 else if (num=6) then do
   say '*--------------------------------------------------------------*'
   say '| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=7) then do
   say '*--------------------------------------------------------------*'
   say '| (1) Salvar inclusão       (2) Voltar ao menu                 |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=8) then do
   say '*--------------------------------------------------------------*'
   say '| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=9) then do
   say '*--------------------------------------------------------------*'
   say '| (1) Salvar alteração      (2) Voltar ao menu                 |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=10) then do
   say '*--------------------------------------------------------------*'
   say '| Certeza de excluir? (S/N)                                    |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=11) then do
   say '*--------------------------------------------------------------*'
   say '| Deseja sair do sistema? (S/N)                                |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=12) then do
   say '*--------------------------------------------------------------*'
   say '| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=13) then do
   say '*--------------------------------------------------------------*'
   say '| Deseja continuar? (S/N)                                      |'
   say '*--------------------------------------------------------------*'
 end 
 else if (num=14) then do
   say '*--------------------------------------------------------------*'
   say '| Salvar inclusão (S/N)                                        |'
   say '*--------------------------------------------------------------*'
 end
 call charout ,MSG_OPCAO
return
/*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
frmCadastros: procedure expose g_SalvarInclusao g_nPreco, 
 tAssunto.codigo tAssunto.assunto tAutor.codigo,
 tAutor.autor tEditora.codigo tEditora.editora tEndereco.codigo,
 tEndereco.logradouro tEndereco.bairro tEndereco.cep tEndereco.cidade,
 tEndereco.estado tIdioma.codigo tIdioma.idioma tPais.codigo tPais.pais,
 tProfissao.codigo tProfissao.profissao tUsuario.login tUsuario.senha,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tLivroAss.isbn tlivroAss.codassunto tLivroAut.isbn tlivroAut.codautor,
 tCliente.cpf tCliente.nome tCliente.email tCliente.identidade tCliente.sexo,
 tCliente.telefone tCliente.dtnascimento tCliente.codendereco tCliente.codpais,
 tCliente.codprofissao tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg sreg, sacao

call constantes
slinha = ''
if sreg=opAssunto then do
   if sacao=opNovo then do
      tAssunto.codigo=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg))
      call mostrarDados sreg, '', 1
      call submenu 7, sreg
   end 
   else if sacao=opPesquisar then do
     slinha=validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,opNumero)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opAutor then do
   if sacao=opNovo then do
      tAutor.codigo=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg))
      call mostrarDados sreg, '', 1
      call submenu 7, sreg
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,false,opNumero)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opEditora then do
   if sacao=opNovo then do
      tEditora.codigo=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg))
      call mostrarDados sreg, '', 1
      call submenu 7, sreg
   end 
   else if sacao=opPesquisar then do
     slinha=validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,false,opNumero)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opEndereco then do
   if sacao=opNovo then do
      tEndereco.codigo=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg))
      call mostrarDados sreg, '', 1
      call submenu 7, sreg
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
              false,opNumero)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opIdioma then do
   if sacao=opNovo then do
      tIdioma.codigo=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg))
      call mostrarDados sreg, '', 1
      call submenu 7, sreg
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,false,opNumero)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opPais then do
   if sacao=opNovo then do
      call charout ,rotulo(sreg, 1)
      tPais.codigo = linein()
      slinha=pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg))
      if slinha='' then do
         call pesqLinhaExcluida tfPais, tamReg(sreg)
         call mostrarDados sreg, '', 1
         call submenu 7, sreg
      end  
      else say MSG_REGEXST
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, opTexto)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      say rotulo(sreg, 1) || tPais.codigo
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opProfissao then do
   if sacao=opNovo then do
      tProfissao.codigo=pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg))
      call mostrarDados sreg, '', 1
      call submenu 7, sreg
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
              false,opNumero)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opLivro then do
   if sacao=opNovo then do
      call charout ,rotulo(sreg, 1)
      tLivro.isbn = linein()
      if validaISBN(tLivro.isbn) then do
          slinha=pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg))
          if slinha='' then do
             call pesqLinhaExcluida tfLivro, tamReg(sreg)
             call mostrarDados sreg, '', 1
             call submenu 7, sreg
             call frmCadLigados opLivroAss, opNovo, tLivro.isbn
             call frmCadLigados opLivroAut, opNovo, tLivro.isbn
          end 
          else say MSG_REGEXST
      end 
      else say MSG_ISBNINV
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,opTexto)
      if slinha<>'' then do
         call mostrarDados sreg, '', 2
         call mostrarDados sreg, slinha, 3
         call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      say rotulo(sreg, 1) || tLivro.isbn
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn)
      say 'Assuntos dos livros excluídos, inclua novos!'
      frmCadLigados(opLivroAss, opNovo, tLivro.isbn)
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn)
      say 'Autores dos livros excluídos, inclua novos!'
      frmCadLigados(opLivroAut, opNovo, tLivro.isbn)
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
      say 'Assuntos dos livros sendo excluídos!'
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn)
      say 'Autores dos livros sendo excluídos!'
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn)
   end
end 
else if sreg=opCliente then do
   if sacao=opNovo then do
      call charout ,rotulo(sreg, 1)
      tCliente.cpf = linein()
      if validaCPF(tCliente.cpf) then do
          slinha=pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg))
          if slinha='' then do
             call pesqLinhaExcluida tfCliente, tamReg(sreg)
             call mostrarDados sreg, '', 1
             call submenu 7, sreg
          end 
          else say MSG_REGEXST
      end 
      else say MSG_CPFINV
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,opTexto)
      if slinha<>'' then do
         call mostrarDados sreg, '', 2
         call mostrarDados sreg, slinha, 3
         call submenu 8, sreg
      end
   end 
   else if sacao=opAlterar then do
      say rotulo(sreg, 1) || tCliente.cpf
      call mostrarDados sreg, '', 1
      call submenu 9, sreg
   end 
   else if sacao=opExcluir then do
      call submenu 10, sreg
   end
end 
else if sreg=opVenda then do
   if sacao=opNovo then do
      tVenda.dthrvenda=retDataHora()
      say rotulo(sreg, 1) || tVenda.dthrvenda
      slinha=pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg))
      if slinha='' then do
         slinha=validaEntrada(tfCliente,opCliente,1,tVenda.cpf,3,false,opTexto)
         if slinha<>'' then do
            tVenda.cpf=strip(substr(slinha,1,14))
            if validaCPF(tVenda.cpf) then do
               call charout ,' 'rotulo(opCliente, 2) /* Nome */
               say substr(slinha, gnPosChave(opCliente, 2), gnTamChave(opCliente, 2))
               frmCadLigados(opVenda, opNovo, tVenda.cpf)
            end 
            else say MSG_CPFINV
         end
      end 
      else say MSG_REGEXST
   end 
   else if sacao=opPesquisar then do
      slinha=validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
              false,opDataHora)
      if slinha<>'' then do
        call mostrarDados sreg, '', 2
        call mostrarDados sreg, slinha, 3
        call submenu 8, sreg
      end
   end
end
return
/*------------------------------------------------------------------------------
Realiza as consultas de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
frmConsultas: procedure
  parse arg sreg, sacao

call constantes
slinha = ''
if sreg=opAssunto then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfAssunto, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opAutor then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfAutor, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opEditora then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfEditora, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opEndereco then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfEndereco,sreg,2,tEndereco.Logradouro,1,
              true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfEndereco, sreg, '', 0, 0, tamReg(sreg),
         3, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opIdioma then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfIdioma, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opPais then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfPais, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opProfissao then do
   if sacao=opPesquisar then
     slinha=validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfProfissao, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opLivro then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfLivro, sreg, '', 0, 0, tamReg(sreg),
        1, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opCliente then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfCliente, sreg, '', 0, 0, tamReg(sreg),
        1, false) = false then
        say rotulo(sreg, 0)
   end
end 
else if sreg=opVenda then do
   if sacao=opPesquisar then
      slinha=validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,opTexto)
   else if sacao=opListarTodos then do
      if ListarTodos(tfVenda, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        say rotulo(sreg, 0)
   end
end
if slinha='' then
   call charout ,''
return
/*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*/
frmAlterarSenha: procedure

call constantes
sres = ''; sSenhaAtual = ''; sNovaSenha = ''; sConfirmaSenha = ''

say rotulo(opUsuario, 1) || tUsuario.login
nopcao=1
bQuebra=false
do while bQuebra=false
  select
    when nopcao=1 then do
       sSenhaAtual=digitaSenha('Senha Atual: ',10)
       if sSenhaAtual<>tUsuario.senha then do
          say MSG_SENCONFERE
          bQuebra=true
       end 
       else nopcao=2
     end
    when nopcao=2 then do
       sNovaSenha=digitaSenha('Nova Senha: ',10)
       sConfirmaSenha=digitaSenha('Confirma Senha: ',10)
       if sNovaSenha<>sConfirmaSenha then do
          say MSG_SENCONFIRM
          bQuebra=true
       end 
       else nopcao=3
     end
    when nopcao=3 then do
       sres=pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(opUsuario))
       if sres='' then
         say MSG_LOGINENCON
       else do
         tUsuario.senha=sConfirmaSenha
         call submenu 9,opUsuario
         bQuebra=true
       end
     end
  end
end
return
/*------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*/
btnAcao: procedure expose tAssunto.codigo tAssunto.assunto tAutor.codigo,
 tAutor.autor tEditora.codigo tEditora.editora tEndereco.codigo,
 tEndereco.logradouro tEndereco.bairro tEndereco.cep tEndereco.cidade,
 tEndereco.estado tIdioma.codigo tIdioma.idioma tPais.codigo tPais.pais,
 tProfissao.codigo tProfissao.profissao tUsuario.login tUsuario.senha,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tLivroAss.isbn tlivroAss.codassunto tLivroAut.isbn tlivroAut.codautor,
 tCliente.cpf tCliente.nome tCliente.email tCliente.identidade tCliente.sexo,
 tCliente.telefone tCliente.dtnascimento tCliente.codendereco tCliente.codpais,
 tCliente.codprofissao tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg sreg, sacao

call constantes
if sreg=opAssunto then do
   if sacao=opSalvarInclusao then
      call escreveArq tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfAssunto, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opAutor then do
   if sacao=opSalvarInclusao then
      call escreveArq tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfAutor, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opEditora then do
   if sacao=opSalvarInclusao then
      call escreveArq tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfEditora, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opEndereco then do
   if sacao=opSalvarInclusao then
      call escreveArq tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfEndereco, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opIdioma then do
   if sacao=opSalvarInclusao then
      call escreveArq tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfIdioma, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opPais then do
   if sacao=opSalvarInclusao then
      call escreveArq tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfPais, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opProfissao then do
   if sacao=opSalvarInclusao then
      call escreveArq tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfProfissao, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opLivro then do
   if sacao=opSalvarInclusao then
      call escreveArq tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfLivro, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opLivroAss then do
   if sacao=opSalvarInclusao then
      call escreveArq tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfLivroAss, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opLivroAut then do
   if sacao=opSalvarInclusao then
      call escreveArq tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfLivroAut, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opCliente then do
   if sacao=opSalvarInclusao then
      call escreveArq tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfCliente, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opVenda then do
   if sacao=opSalvarInclusao then
      call escreveArq tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC
   else if sacao=opSalvarAlteracao then
      call escreveArq tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
   else if sacao=opConfirmaExclusao then
      call escreveArq tfVenda, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC
end 
else if sreg=opUsuario then do
   if sacao=opSalvarAlteracao then
      call escreveArq tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT
end
return
/*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*/
submenu: procedure expose g_SalvarInclusao tAssunto.codigo tAssunto.assunto, 
 tAutor.codigo tAutor.autor tEditora.codigo tEditora.editora tEndereco.codigo,
 tEndereco.logradouro tEndereco.bairro tEndereco.cep tEndereco.cidade,
 tEndereco.estado tIdioma.codigo tIdioma.idioma tPais.codigo tPais.pais,
 tProfissao.codigo tProfissao.profissao tUsuario.login tUsuario.senha,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tLivroAss.isbn tlivroAss.codassunto tLivroAut.isbn tlivroAut.codautor,
 tCliente.cpf tCliente.nome tCliente.email tCliente.identidade tCliente.sexo,
 tCliente.telefone tCliente.dtnascimento tCliente.codendereco tCliente.codpais,
 tCliente.codprofissao tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg nmenu, sreg

call constantes
opSubMenu = 0; 
opCSubMenu = ''
bSOp=true
select
  when nmenu = 6 then do
    do while bSOp=true
      call menu nmenu
      opSubMenu = linein()
      select 
        when opSubMenu=1 then call frmCadastros sreg, opNovo
        when opSubMenu=2 then call frmCadastros sreg, opPesquisar
        when opSubMenu=3 then bSOp=false
        otherwise say MSG_ERRO
      end
    end
  end
  when nmenu = 7 then do
    do while bSOp=true
      call menu nmenu
      opSubMenu = linein()
      select 
        when opSubMenu=1 then do 
          call btnAcao sreg, opSalvarInclusao
          bSOp=false 
        end
        when opSubMenu=2 then bSOp=false
        otherwise say MSG_ERRO
      end
    end
  end
  when nmenu = 8 then do
    do while bSOp=true
      call menu nmenu
      opSubMenu = linein()
      select 
        when opSubMenu=1 then do 
          call frmCadastros sreg, opAlterar
          bSOp=false 
        end
        when opSubMenu=2 then do 
          call frmCadastros sreg, opExcluir
          bSOp=false 
        end
        when opSubMenu=3 then bSOp=false
        otherwise say MSG_ERRO
      end
    end
  end
  when nmenu = 9 then do
    do while bSOp=true
      call menu nmenu
      opSubMenu = linein()
      select 
        when opSubMenu=1 then do 
          call btnAcao sreg, opSalvarAlteracao
          bSOp=false 
        end
        when opSubMenu=2 then bSOp=false
        otherwise say MSG_ERRO
      end
    end
  end
  when nmenu = 10 then do
    do while bSOp = true
      call menu nmenu
      opCSubMenu = linein()
      if (opCSubMenu='S') | (opCSubMenu='s') then do
         call btnAcao sreg, opConfirmaExclusao
         bSOp=false
      end 
      else if (opCSubMenu='N') | (opCSubMenu='n') then bSOp=false
      else say MSG_ERRO
    end
   end
  when nmenu = 12 then do
    do while bSOp=true
      call menu nmenu
      opSubMenu = linein()
      select 
        when opSubMenu=1 then call frmConsultas sreg, opPesquisar
        when opSubMenu=2 then call frmConsultas sreg, opListarTodos
        when opSubMenu=3 then bSOp=false
        otherwise say MSG_ERRO
      end
    end
  end
  when nmenu = 14 then do
    do while bSOp=true
      call menu nmenu
      opCSubMenu = linein()
      if (opCSubMenu='S') | (opCSubMenu='s') then do
        call btnAcao sreg, opSalvarInclusao
        bSOp=false
        g_SalvarInclusao=true
      end 
      else if (opCSubMenu='N') | (opCSubMenu='n') then bSOp=false
      else say MSG_ERRO
    end
   end
end
return
/*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*/
usaMenu: procedure
  parse arg num

call constantes
opSubMenu = 0
opSair = ''
bSOp=true
 if num = 1 then do /* Cadastros */
   do while bSOp=true
     call menu 2
     opSubMenu = linein()
     select
       when opSubMenu = 1 then call submenu 6, opAssunto
       when opSubMenu = 2 then call submenu 6, opAutor
       when opSubMenu = 3 then call submenu 6, opEditora
       when opSubMenu = 4 then call submenu 6, opEndereco
       when opSubMenu = 5 then call submenu 6, opIdioma
       when opSubMenu = 6 then call submenu 6, opPais
       when opSubMenu = 7 then call submenu 6, opProfissao
       when opSubMenu = 8 then call submenu 6, opCliente
       when opSubMenu = 9 then call submenu 6, opLivro
       when opSubMenu = 10 then bSOp=false
       otherwise say MSG_ERRO
     end
   end
 end 
 else if num = 2 then do /* Pesquisas */
   do while bSOp=true
     call menu 3
     opSubMenu = linein()
     select
       when opSubMenu = 1 then call submenu 12, opAssunto
       when opSubMenu = 2 then call submenu 12, opAutor
       when opSubMenu = 3 then call submenu 12, opEditora
       when opSubMenu = 4 then call submenu 12, opEndereco
       when opSubMenu = 5 then call submenu 12, opIdioma
       when opSubMenu = 6 then call submenu 12, opPais
       when opSubMenu = 7 then call submenu 12, opProfissao
       when opSubMenu = 8 then call submenu 12, opCliente
       when opSubMenu = 9 then call submenu 12, opLivro
       when opSubMenu = 10 then bSOp=false
       otherwise say MSG_ERRO
     end
   end
 end 
 else if num = 3 then do /* Vendas */
   do while bSOp=true
     call menu 4
     opSubMenu = linein()
     select
       when opSubMenu = 1 then call submenu 6, opVenda
       when opSubMenu = 2 then call submenu 12, opVenda
       when opSubMenu = 3 then bSOp=false
       otherwise say MSG_ERRO
     end
   end
 end 
 else if num = 4 then do /* Opcoes */
   do while bSOp=true
     call menu 5
     opSubMenu = linein()
     select
       when opSubMenu = 1 then call frmAlterarSenha
       when opSubMenu = 2 then call frmSobre
       when opSubMenu = 3 then do
           call menu 11
           opSair = linein()
           if (opSair='S') | (opSair='s') then do
              call fechaArqs
              exit
           end
        end
       when opSubMenu = 4 then bSOp=false
       otherwise say MSG_ERRO
     end
   end
 end
return
/*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*/
mostrarDados: procedure expose g_nPreco tAssunto.codigo tAssunto.assunto, 
 tAutor.codigo tAutor.autor tEditora.codigo tEditora.editora tEndereco.codigo,
 tEndereco.logradouro tEndereco.bairro tEndereco.cep tEndereco.cidade,
 tEndereco.estado tIdioma.codigo tIdioma.idioma tPais.codigo tPais.pais,
 tProfissao.codigo tProfissao.profissao tUsuario.login tUsuario.senha,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tLivroAss.isbn tlivroAss.codassunto tLivroAut.isbn tlivroAut.codautor,
 tCliente.cpf tCliente.nome tCliente.email tCliente.identidade tCliente.sexo,
 tCliente.telefone tCliente.dtnascimento tCliente.codendereco tCliente.codpais,
 tCliente.codprofissao tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg sreg, slinha, nOpcao

call constantes
if sreg=opAssunto then do
   select
     when nOpcao = 1 then do
        say rotulo(sreg, 1) || tAssunto.codigo
        call charout ,rotulo(sreg, 2)
        tAssunto.assunto = linein()
       end
    when nOpcao = 2 then do
        say 'Código     Assunto'
        say '------     -------'
       end
    when nOpcao = 3 then do
        tAssunto.codigo=substr(slinha, 1, 10)
        tAssunto.assunto=substr(slinha, 11, 30)
        say tAssunto.codigo' 'tAssunto.assunto
       end
   end
end 
else if sreg=opAutor then do
   select
    when nOpcao = 1 then do
        say rotulo(sreg, 1) || tAutor.codigo
        call charout ,rotulo(sreg, 2)
        tAutor.autor = linein()
       end
    when nOpcao = 2 then do
        say 'Código     Autor'
        say '------     -----'
       end
    when nOpcao = 3 then do
        tAutor.codigo=substr(slinha, 1, 10)
        tAutor.autor=substr(slinha, 11, 30)
        say tAutor.codigo' 'tAutor.autor
       end
   end
end 
else if sreg=opEditora then do
   select
    when nOpcao = 1 then do
        say rotulo(sreg, 1) || tEditora.codigo
        call charout ,rotulo(sreg, 2)
        tEditora.editora = linein()
       end
    when nOpcao = 2 then do
        say 'Código     Editora'
        say '------     -------'
       end
    when nOpcao = 3 then do
        tEditora.codigo=substr(slinha, 1, 10)
        tEditora.editora=substr(slinha, 11, 50)
        say tEditora.codigo' 'tEditora.editora
       end
   end
end 
else if sreg=opEndereco then do
   select
    when nOpcao = 1 then do
        say rotulo(sreg, 1) || tEndereco.codigo
        call charout ,rotulo(sreg, 2)
        tEndereco.Logradouro = linein()
        call charout ,rotulo(sreg, 3)
        tEndereco.bairro = linein()
        call charout ,rotulo(sreg, 4)
        tEndereco.cep = linein()
        call charout ,rotulo(sreg, 5)
        tEndereco.cidade = linein()
        call charout ,rotulo(sreg, 6)
        tEndereco.estado = linein()
       end
    when nOpcao = 3 then do
        tEndereco.codigo=strip(substr(slinha, 1, 10))
        tEndereco.logradouro=strip(substr(slinha, 11, 40))
        tEndereco.bairro=strip(substr(slinha, 51, 15))
        tEndereco.cep=strip(substr(slinha, 66, 8))
        tEndereco.cidade=strip(substr(slinha, 74, 30))
        tEndereco.estado=strip(substr(slinha, 104, 20))
        say '--------------------'
        say rotulo(sreg, 1) || tEndereco.codigo
        say rotulo(sreg, 2) || tEndereco.Logradouro
        say rotulo(sreg, 3) || tEndereco.bairro
        say rotulo(sreg, 4) || tEndereco.cep
        say rotulo(sreg, 5) || tEndereco.cidade
        say rotulo(sreg, 6) || tEndereco.estado
       end
   end
end 
else if sreg=opIdioma then do
   select
    when nOpcao = 1 then do
        say rotulo(sreg, 1) || tIdioma.codigo
        call charout ,rotulo(sreg, 2)
        tIdioma.idioma = linein()
       end
    when nOpcao = 2 then do
        say 'Código     Idioma'
        say '------     ------'
       end
    when nOpcao = 3 then do
        tIdioma.codigo=substr(slinha, 1, 10)
        tIdioma.idioma=substr(slinha, 11, 20)
        say tIdioma.codigo' 'tIdioma.idioma
       end
   end
end 
else if sreg=opPais then do
   select
    when nOpcao = 1 then do
        call charout ,rotulo(sreg, 2)
        tPais.pais = linein()
       end
    when nOpcao = 2 then do
        say 'Código País'
        say '------ ----'
       end
    when nOpcao = 3 then do
        tPais.codigo=substr(slinha, 1, 3)
        tPais.pais=substr(slinha, 4, 50)
        say tPais.codigo'    'tPais.pais
       end
   end
end 
else if sreg=opProfissao then do
   select
    when nOpcao = 1 then do
        say rotulo(sreg, 1) || tProfissao.codigo
        call charout ,rotulo(sreg, 2)
        tProfissao.profissao = linein()
       end
    when nOpcao = 2 then do
        say 'Código     Profissão'
        say '------     ---------'
       end
    when nOpcao = 3 then do
        tProfissao.codigo=substr(slinha, 1, 10)
        tProfissao.profissao=substr(slinha, 11, 50)
        say tProfissao.codigo' 'tProfissao.profissao
       end
   end
end 
else if sreg=opLivro then do
   select
    when nOpcao = 1 then do
        call charout ,rotulo(sreg, 2)
        tLivro.titulo = linein()
        tLivro.edicao=validaNumero(rotulo(sreg, 3), tLivro.edicao)
        tLivro.anopubli=validaNumero(rotulo(sreg, 4), tLivro.anopubli)
        call mostrarSubDados opLivro, opEditora, false
        tLivro.volume=validaNumero(rotulo(sreg, 6), tLivro.volume)
        call mostrarSubDados opLivro, opIdioma, false
        tLivro.npaginas=validaNumero(rotulo(sreg, 8), tLivro.npaginas)
        tLivro.preco=validaNumero(rotulo(sreg, 9), tLivro.preco)
        tLivro.qtdestoque=validaNumero(rotulo(sreg, 10), tLivro.qtdestoque)
       end
    when nOpcao = 3 then do
        tLivro.isbn=strip(substr(slinha, 1, 13))
        tLivro.titulo=strip(substr(slinha, 14, 50))
        tLivro.edicao=strip(substr(slinha, 64, 10))
        tLivro.anopubli=strip(substr(slinha, 74, 10))
        tLivro.codeditora=strip(substr(slinha, 84, 10))
        tLivro.volume=strip(substr(slinha, 94, 10))
        tLivro.codidioma=strip(substr(slinha, 104, 10))
        tLivro.npaginas=strip(substr(slinha, 114, 10))
        tLivro.preco=strip(substr(slinha, 124, 10))
        tLivro.qtdestoque=strip(substr(slinha, 134, 10))
        say '--------------------'
        say rotulo(sreg, 1) || tLivro.isbn
        say rotulo(sreg, 2) || tLivro.titulo
        say rotulo(sreg, 3) || tLivro.edicao
        say rotulo(sreg, 4) || tLivro.anopubli
        say rotulo(sreg, 5) || tLivro.codeditora
        call mostrarSubDados opLivro, opEditora, true
        say rotulo(sreg, 6) || tLivro.volume
        say rotulo(sreg, 7) || tLivro.codidioma
        call mostrarSubDados opLivro, opIdioma, true
        say rotulo(sreg, 8) || tLivro.npaginas
        say rotulo(sreg, 9) || tLivro.preco
        say rotulo(sreg, 10) || tLivro.qtdestoque
        call ListarRegLigados tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
                         tfAssunto, opAssunto, 1, 4
        call ListarRegLigados tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
                         tfAutor, opAutor, 1, 4
       end
   end
end 
else if sreg=opCliente then do
   select
    when nOpcao = 1 then do
        call charout ,rotulo(sreg, 2)
        tCliente.nome = linein()
        call charout ,rotulo(sreg, 3)
        tCliente.email = linein()
        call charout ,rotulo(sreg, 4)
        tCliente.identidade = linein()
        call charout ,rotulo(sreg, 5)
        tCliente.sexo = linein()
        call charout ,rotulo(sreg, 6)
        tCliente.telefone = linein()
        tCliente.dtnascimento=
                validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true)
        call mostrarSubDados opCliente, opEndereco, false
        call mostrarSubDados opCliente, opPais, false
        call mostrarSubDados opCliente, opProfissao, false
       end
    when nOpcao = 3 then do
        tCliente.cpf=strip(substr(slinha, 1, 14))
        tCliente.nome=strip(substr(slinha, 15, 30))
        tCliente.email=strip(substr(slinha, 45, 30))
        tCliente.identidade=strip(substr(slinha, 75, 10))
        tCliente.sexo=strip(substr(slinha, 85, 1))
        tCliente.telefone=strip(substr(slinha, 86, 17))
        tCliente.dtnascimento=strip(substr(slinha, 103, 10))
        tCliente.codendereco=strip(substr(slinha, 113, 10))
        tCliente.codpais=strip(substr(slinha, 123, 3))
        tCliente.codprofissao=strip(substr(slinha, 126, 10))
        say '--------------------'
        say rotulo(sreg, 1) || tCliente.cpf
        say rotulo(sreg, 2) || tCliente.nome
        say rotulo(sreg, 3) || tCliente.email
        say rotulo(sreg, 4) || tCliente.identidade
        say rotulo(sreg, 5) || tCliente.sexo
        say rotulo(sreg, 6) || tCliente.telefone
        say rotulo(sreg, 7) || tCliente.dtnascimento
        say rotulo(sreg, 8) || tCliente.codendereco
        call mostrarSubDados opCliente, opEndereco, true
        say rotulo(sreg, 9) || tCliente.codpais
        call mostrarSubDados opCliente, opPais, true
        say rotulo(sreg, 10) || tCliente.codprofissao
        call mostrarSubDados opCliente, opProfissao, true
       end
   end
end 
else if sreg=opVenda then do
   select
    when nOpcao = 1 then call mostrarSubDados opVenda,opVenda, false
    when nOpcao = 2 then do
        say 'DataHoraVenda       CPF            ISBN          PreçoVenda'
        say '-------------       ---            ----          ----------'
       end
    when nOpcao = 3 then do
        tVenda.dthrvenda=substr(slinha, 1, 19)
        tVenda.cpf=substr(slinha, 20, 14)
        tVenda.isbn=substr(slinha, 34, 13)
        tVenda.precovenda=substr(slinha, 47, 10)
        say tVenda.dthrvenda' 'tVenda.cpf' 'tVenda.isbn' 'tVenda.precovenda
       end
   end
end
return
/*------------------------------------------------------------------------------
Mostra as sub informções de entrada e de saída.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai só mostrar na saída 
------------------------------------------------------------------------------*/
mostrarSubDados: procedure expose g_nPreco
 tEditora.codigo tEditora.editora tEndereco.codigo,
 tEndereco.logradouro tEndereco.bairro tEndereco.cep tEndereco.cidade,
 tEndereco.estado tIdioma.codigo tIdioma.idioma tPais.codigo tPais.pais,
 tProfissao.codigo tProfissao.profissao tUsuario.login tUsuario.senha,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tCliente.cpf tCliente.nome tCliente.email tCliente.identidade tCliente.sexo,
 tCliente.telefone tCliente.dtnascimento tCliente.codendereco tCliente.codpais,
 tCliente.codprofissao tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg sreg, ssubreg, bSoMostrar

call constantes
sRegistro = ''; sPreco = ''
nMaxTentativas=3
if sreg=opLivro then do
  if ssubreg=opEditora then do
    if bSoMostrar then
       sRegistro=pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(opEditora))
    else
       sRegistro=validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,false,opNumero)
    if sRegistro<>'' then do
      tLivro.codeditora=strip(substr(sRegistro,1,10))
      call charout ,' 'rotulo(opEditora, 2)
      say substr(sRegistro, gnPosChave(opEditora, 2), gnTamChave(opEditora, 2))
    end
  end 
  else if ssubreg=opIdioma then do
    if bSoMostrar then
       sRegistro=pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(opIdioma))
    else
       sRegistro=validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,false,opNumero)
    if sRegistro<>'' then do
      tLivro.codidioma=strip(substr(sRegistro,1,10))
      call charout ,' 'rotulo(opIdioma, 2)
      say substr(sRegistro, gnPosChave(opIdioma, 2), gnTamChave(opIdioma, 2))
    end
  end
end 
else if sreg=opCliente then do
  if ssubreg=opEndereco then do
    if bSoMostrar then
       sRegistro=pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
                  tamReg(opEndereco))
    else
       sRegistro=validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,false,opNumero)
    if sRegistro<>'' then do
      tCliente.codendereco=strip(substr(sRegistro,1,10))
      call charout ,' 'rotulo(opEndereco, 2)
      say substr(sRegistro, gnPosChave(opEndereco, 2), gnTamChave(opEndereco, 2))
      call charout ,' 'rotulo(opEndereco, 3)
      say substr(sRegistro, gnPosChave(opEndereco, 3), gnTamChave(opEndereco, 3))
      call charout ,' 'rotulo(opEndereco, 4)
      say substr(sRegistro, gnPosChave(opEndereco, 4), gnTamChave(opEndereco, 4))
      call charout ,' 'rotulo(opEndereco, 5)
      say substr(sRegistro, gnPosChave(opEndereco, 5), gnTamChave(opEndereco, 5))
      call charout ,' 'rotulo(opEndereco, 6)
      say substr(sRegistro, gnPosChave(opEndereco, 6), gnTamChave(opEndereco, 6))
    end
  end 
  else if ssubreg=opPais then do
    if bSoMostrar then
       sRegistro=pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(opPais))
    else
       sRegistro=validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,false,opTexto)
    if sRegistro<>'' then do
      tCliente.codpais=strip(substr(sRegistro,1,3))
      call charout ,' 'rotulo(opPais, 2)
      say substr(sRegistro, gnPosChave(opPais, 2), gnTamChave(opPais, 2))
    end
  end 
  else if ssubreg=opProfissao then do
    if bSoMostrar then
       sRegistro=pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
                  tamReg(opProfissao))
    else
       sRegistro=validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,false,opNumero)
    if sRegistro<>'' then do
      tCliente.codprofissao=strip(substr(sRegistro,1,10))
      call charout ,' 'rotulo(opProfissao, 2)
      say substr(sRegistro, gnPosChave(opProfissao, 2), gnTamChave(opProfissao, 2))
    end
  end
end 
else if sreg=opVenda then do
  sRegistro=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro))
  if sRegistro<>'' then do
    call charout ,' 'rotulo(opLivro, 2) /* Titulo */
    say substr(sRegistro, gnPosChave(opLivro, 2), gnTamChave(opLivro, 2))
    call charout ,' 'rotulo(opLivro, 9) /* Preco */
    sPreco=substr(sRegistro, gnPosChave(opLivro, 9), gnTamChave(opLivro, 9))
    g_nPreco = sPreco
    say sPreco
  end
end
return
/*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*/
frmCadLigados: procedure expose g_SalvarInclusao g_nPreco
 tAssunto.codigo tAssunto.assunto tAutor.codigo tAutor.autor,
 tLivro.isbn tLivro.titulo tLivro.edicao tLivro.anopubli tLivro.codeditora,
 tLivro.volume tLivro.codidioma tLivro.npaginas tLivro.preco tLivro.qtdestoque,
 tLivroAss.isbn tlivroAss.codassunto tLivroAut.isbn tlivroAut.codautor,
 tVenda.dthrvenda tVenda.cpf tVenda.isbn tVenda.precovenda

  parse arg sreg, sacao, sCodigo

call constantes
nQtd = 0; nCont = 0; nQtdEstoque = 0
nTotalPreco = 0.0
slinha = ''; sTotalPreco = ''; sPreco = ''; sQtd = ''

if sacao=opNovo then do
  nCont=1
  if sreg=opLivroAss then do
    sQtd=validaNumero('Quantos assuntos quer cadastrar?: ', sQtd)
    nQtd = sQtd
    call stream tfLivroAss, 'C', 'SEEK =0 READ LINE'
    do while nCont <= nQtd
      tLivroAss.isbn=sCodigo
      call charout ,rotulo(opLivroAss, 2)
      tLivroAss.codassunto = linein()
      slinha=pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(opAssunto))
      call charout ,' 'rotulo(opAssunto, 2)
      say substr(slinha, gnPosChave(opAssunto, 2), gnTamChave(opAssunto, 2))
      call pesqLinhaExcluida tfLivroAss, tamReg(sreg)
      call submenu 14, sreg
      nCont=nCont+1
    end
  end 
  else if sreg=opLivroAut then do
    sQtd=validaNumero('Quantos autores quer cadastrar?: ',sQtd)
    nQtd = sQtd
    call stream tfLivroAut, 'C', 'SEEK =0 READ LINE'
    do while nCont <= nQtd
      tLivroAut.isbn=sCodigo
      call charout ,rotulo(opLivroAut, 2)
      tLivroAut.codautor = linein()
      slinha=pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(opAutor))
      call charout ,' 'rotulo(opAutor, 2)
      say substr(slinha, gnPosChave(opAutor, 2), gnTamChave(opAutor, 2))
      call pesqLinhaExcluida tfLivroAut, tamReg(sreg)
      call submenu 14, sreg
      nCont=nCont+1
    end
  end 
  else if sreg=opVenda then do
    sQtd=validaNumero('Quantos livros quer vender?: ',sQtd)
    nQtd = sQtd
    nTotalPreco=0
    do while nCont <= nQtd
      slinha=validaEntrada(tfLivro,opLivro,1,tVenda.isbn,3,false,opTexto)
      if slinha<>'' then do
        tVenda.isbn=strip(substr(slinha,1,13))
        if validaISBN(tVenda.isbn) then do
          call mostrarDados sreg, '', 1
          tLivro.qtdestoque=strip(substr(slinha,134,10))
          nQtdEstoque = tLivro.qtdestoque
          if nQtdEstoque > 0 then do
             nTotalPreco=nTotalPreco + g_nPreco
             sPreco = g_nPreco
             tVenda.precovenda=sPreco
             g_SalvarInclusao=false
             call submenu 14, sreg
             if g_SalvarInclusao then do
                slinha=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro))
                if slinha<>'' then do
                   nQtdEstoque=nQtdEstoque-1
                   tLivro.qtdestoque = nQtdEstoque
                   slinha=substr(slinha,1,133)+esp(tLivro.qtdestoque,10)
                   call escreveArq tfLivro, slinha, '', ''
                end
             end
             nCont=nCont+1
          end 
          else say MSG_SEMESTOQUE
        end 
        else say MSG_ISBNINV
      end
    end
    sTotalPreco = nTotalPreco
    say 'Total de ' || rotulo(sreg,4) || sTotalPreco
  end
end 
else if sacao=opExcluir then do
  if sreg=opLivroAss then
     call ExcluirRegLigados tfLivroAss, sreg, 1, 13, sCodigo
  else if sreg=opLivroAut then
     call ExcluirRegLigados tfLivroAut, sreg, 1, 13, sCodigo
end

return
/*------------------------------------------------------------------------------
Realiza a exclusão dos arquivos de ligação.
sArq - o arquivo de ligação
sreg - o tipo de arquivo de ligação
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------*/
ExcluirRegLigados: procedure
  parse arg sArq, sreg, nPosChave, nTamChave, sChave

call constantes
slinha = ''; sCodigo = ''

  call stream sArq, 'C', 'SEEK =0 READ LINE'
  do while (fimArq(sArq)=false)
    slinha = linein(sArq)
    sCodigo=strip(substr(slinha,nPosChave,nTamChave))
    if sCodigo=sChave then
       call btnAcao sreg,opConfirmaExclusao
  end
return
