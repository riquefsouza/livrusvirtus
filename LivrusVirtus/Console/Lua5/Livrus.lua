-------------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza. 
-- Versão programada na linguagem Lua.
-------------------------------------------------------------------------------
-- programa Livrus

tAssunto = { codigo = "", assunto = "" }
tAutor = { codigo = "", autor = "" }
tEditora = { codigo = "",  editora = "" }
tIdioma = { codigo = "", idioma = "" }
tUsuario = { login = "", senha = "" }
tPais = { codigo = "", pais = "" }
tProfissao = { codigo = "", profissao = "" }
tLivro = { isbn = "", titulo = "", edicao = "", anopubli = "", 
 codeditora = "", volume = "", codidioma = "", npaginas = "", 
 preco = "", qtdestoque = "" }
tLivroAss = { isbn = "", codassunto = "" }
tLivroAut = { isbn = "", codautor = "" }
tCliente = { cpf = "", nome = "", email = "", identidade = "", sexo = "",
 telefone = "", dtnascimento = "", codendereco = "", codpais = "",
 codprofissao = "" }
tEndereco = { codigo = "", logradouro = "", bairro = "", cep = "",
 cidade = "", estado = "" }
tVenda = { dthrvenda = "", cpf = "", isbn = "", precovenda = "" }

ctTipo = { opTexto, opNumero, opData, opDataHora, opSenha }
ctArqs = { opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
              opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
              opUsuario, opVenda }
ctAcao = { opNovo, opAlterar, opPesquisar, opSalvarInclusao,
            opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos }

CRLF = '\n' -- windows 
TAM_CRLF = 1
--  CRLF = '\n'
--  TAM_CRLF = 1  -- unix
--  CRLF = '\r'
--  TAM_CRLF = 1 -- macintosh

ARQ_ABRE = 'r+'
ARQ_CRIA = 'w'

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

bopcao = false
opmenu = ''
g_nPosChave, g_nTamChave = 0, 0
g_nPreco = 0.0
g_SalvarInclusao = false

-- tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, tfPais, tfProfissao,
-- tfLivro, tfLivroAss, tfLivroAut, tfCliente, tfUsuario, tfVenda: File

-- Rotinas básicas -----------------------------------------------------------

------------------------------------------------------------------------------
-- Mostra saida de dados formatada pela tela.
------------------------------------------------------------------------------
-- printf("Hello %s from %s on %s\n",os.getenv"USER" or "there",_VERSION,os.date())
function printf(...)
 io.write(string.format(unpack(arg)))
end

------------------------------------------------------------------------------
-- Informa dados pela tela.
-- retorna os caracteres digitados.
------------------------------------------------------------------------------
function digita()
  for slinha in io.lines() do 
    return slinha
  end
end

-------------------------------------------------------------------------------
-- Retira os espaços em branco antes ou depois do texto.
-- sTexto - o texto a ser retirado os espaços em branco
-- retorna - o texto sem os espaços em branco
-------------------------------------------------------------------------------
function trim(sTexto)
  nposini = string.find(sTexto,'%a',1)
  if nposini~=nil then
     slocal = string.sub(sTexto,nposini,nposini+string.len(sTexto)-1)  
  else
     slocal = sTexto
     nposini = 1
  end

  nposfim = string.find(slocal,'%s',1)
  if nposfim~=nil then
     return string.sub(slocal,1,nposfim-1)
  else
     return string.sub(slocal,1,string.len(slocal))
  end
end

-------------------------------------------------------------------------------
-- Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
-- sTexto - o texto
-- nTam - tamanho máximo do texto
-- retorna - o texto com espaços em branco a mais
-------------------------------------------------------------------------------
function esp(sTexto, nTam)
  return sTexto..string.rep(' ',nTam-string.len(sTexto))
end

-------------------------------------------------------------------------------
-- Faz uma pesquisa relativa de um texto através de um valor chave.
-- sTexto - o texto
-- sChave - a chave a ser pesquisada
-- retorna - se achou ou não a chave dentro do texto
-------------------------------------------------------------------------------
function strRelativa(sTexto, sChave)
  if string.find(sTexto,sChave,1,true)~=nil then
    return true
  else
    return false
  end
end

-------------------------------------------------------------------------------
-- Funcao que retorna um pedaco de uma string.
-- stexto - indica a string
-- nini - indica a posicao inicial do pedaco
-- ntam - indica o tamanho do pedaco
-- retorna - o pedaco da string
-------------------------------------------------------------------------------
function copy(stexto, nini, ntam)
  if stexto~=nil then
     return string.sub(stexto, nini, nini+ntam-1)
  else
     return ''
  end
end

-------------------------------------------------------------------------------
-- Calcula o modulo11 de um valor qualquer.
-- svalor - a mstring com o número a ser calculado
-- ndig - dígito do valor a ser calculado
-- retorna - o dígito correto
-------------------------------------------------------------------------------
function modulo11(svalor, ndig)
 ncont=1
 slocal='' 
 sres=''
 while (ncont <= 11) do
   slocal=copy(svalor,ncont,1) .. slocal
   ncont=ncont+1
 end
 nsoma=0
 if ndig==1 then
   ncont=3
 else
   ncont=2
 end
 npos=2
 while (ncont <= 11) do
   sres = copy(slocal,ncont,1)
   nvalor = tonumber(sres)
   nsoma=nsoma + (nvalor * npos)
   ncont=ncont+1
   npos=npos+1
 end
 nsoma=(11 - math.mod(nsoma, 11))

 if nsoma > 9 then
   return 0
 else
   return nsoma
 end
end
-------------------------------------------------------------------------------
-- Validação de um número de CPF qualquer.
-- cpf - a mstring com o número do CPF
-- retorna - se é valido ou não
-------------------------------------------------------------------------------
function validaCPF(cpf)
  if string.len(cpf)==14 then
    scpf=copy(cpf,1,3)..copy(cpf,5,3)..copy(cpf,9,3)..copy(cpf,13,2)
    sres=copy(cpf,13,1)
    nvalor1 = tonumber(sres)
    sres=copy(cpf,14,1)
    nvalor2 = tonumber(sres)
    if (modulo11(scpf,1)==nvalor1) and 
       (modulo11(scpf,2)==nvalor2) then
      return true
    else
      return false
    end
  else
    return false
  end
end
-------------------------------------------------------------------------------
-- Validação de um número ISBN qualquer.
-- isbn - a mstring com o número do ISBN
-- retorna - se é valido ou não
-------------------------------------------------------------------------------
function validaISBN(isbn)
  if string.len(isbn)==13 then
    sdigito = copy(isbn, string.len(isbn), 1)
    sisbn=''
    for ncont = 1, string.len(isbn)-1 do
      if copy(isbn,ncont,1)~='-' then
        sisbn=sisbn..copy(isbn,ncont,1)
      end 
    end
    if sdigito == 'X' then
      nsoma = 10
    else
      nvalor = tonumber(sdigito)
      nsoma = nvalor
    end
    for ncont = 1, 9 do
      snum=copy(sisbn, ncont, 1)
      nvalor = tonumber(snum)
      nsoma=nsoma + (nvalor * (11 - ncont))
    end
    if math.mod(nsoma, 11) == 0 then
      return true
    else
      return false
    end
  else
    return false
  end
end
-------------------------------------------------------------------------------
-- Esconde a digitação da senha
-- retorna - a senha digitada
-------------------------------------------------------------------------------
function digitaSenha(sRotulo, nTamSenha)
io.write(sRotulo)
sSenha = digita()

--  ncont = 0
--  sSenha = ''
--  sLetra = '\0'
--  while (sLetra~='\r') and (ncont < nTamSenha) do
--    sLetra=readkey
--    io.write('*')
--    sSenha = sSenha..sLetra
--    ncont=ncont+1
--  end
return sSenha
end

-------------------------------------------------------------------------------
-- Validação de um número qualquer.
-- sRotulo - o texto antes de se digitar o número
-- sNumero - a mstring com o valor do número
-- retorna - o sNumero
-------------------------------------------------------------------------------
function validaNumero(sRotulo, sNumero)
nStatus=-1
  while (nStatus~=0) do
    io.write(sRotulo)
    sNumero = digita()
    nnum = tonumber(sNumero)
    if nnum == nil then
       print(MSG_NUMINV)
    elseif nnum < 1 then
       print(MSG_NUMINV)
    else
       nStatus = 0
    end
  end
return sNumero
end

-------------------------------------------------------------------------------
-- Validação de uma data ou data/hora qualquer.
-- sRotulo - o texto antes de se digitar a data/hora
-- sDataHora - a mstring com o valor da data/hora
-- bSoData - indica se vai validar somente uma data sem a hora
-- retorna - a sDataHora
-------------------------------------------------------------------------------
function validaDataHora(sRotulo, sDataHora, bSoData)
bvalida=false
bdatavalida=false
bhoravalida=false
nudiames=0
if bSoData==true then ntam=10
else ntam=19 end
while bvalida==false do
  io.write(sRotulo)
  sDataHora = digita()
  if string.len(sDataHora)==ntam then
    sdia=copy(sDataHora,1,2)
    ndia=tonumber(sdia)
    smes=copy(sDataHora,4,2)
    nmes=tonumber(smes)
    sano=copy(sDataHora,7,4)
    nano=tonumber(sano)
  
    if (nano >= 1) and (nano <= 9999) then
      if (nmes >= 1) and (nmes <= 31) then 
          if nmes==1 or nmes==3 or nmes==5 or nmes==7 or 
             nmes==8 or nmes==10 or nmes==12 then 
             nudiames=31
          elseif nmes==2 then
               -- ano bissexto 
               if math.mod(nano, 4)==0 then nudiames=29
               else nudiames=28 end
          elseif nmes==4 or nmes==6 or nmes==9 or nmes==11 then 
            nudiames=30
          end
          if (ndia >=1) and (ndia <=nudiames) then
             bdatavalida = true
          end 
      end
    end
  
    if bSoData==true then 
       if bdatavalida==true then bvalida=true
       else print(MSG_DATAINV) end
    else 
      if bdatavalida==true then
          shora=copy(sDataHora,12,2)
          nhora = tonumber(shora)
          smin=copy(sDataHora,15,2)
          nmin=tonumber(smin)
          sseg=copy(sDataHora,18,2)
          nseg=tonumber(sseg)
  
          if (nhora >= 0) and (nhora <= 23) then
            if (nmin >= 0) and (nmin <= 59) then
              if (nseg >= 0) and (nseg <= 59) then
                 bhoravalida=true
              end
            end
          end
      
          if bhoravalida==true then bvalida=true
          else print(MSG_DTHRINV) end
      else
        print(MSG_DTHRINV)
      end
    end
  else
    if bSoData==true then print(MSG_DATAINV)
    else print(MSG_DTHRINV) end    
  end
end
return sDataHora
end

-------------------------------------------------------------------------------
-- Retorna a Data e a hora do sistema.
-- retorna - a data e a hora
-------------------------------------------------------------------------------
function retDataHora()
  return os.date('%d/%m/%Y %H:%M:%S')
end

-- Rotinas de manipulacao de arquivos ----------------------------------------

------------------------------------------------------------------------------
-- Calcula o tamanho do arquivo.
-- sArq - o arquivo
-- retorna - o tamanho do arquivo
------------------------------------------------------------------------------
function tamArq(sArq) 
  ntam = sArq:seek('end')
  return ntam
end

-------------------------------------------------------------------------------
-- Abre ou cria os arquivos do sistema.
-- bAbre - condição para abrir ou criar os arquivos do sistema
-------------------------------------------------------------------------------
function abrecriaArqs(bAbre)
  if bAbre then
    tfAssunto = io.open(ARQ_ASSUNTO, ARQ_ABRE)
    tfAutor = io.open(ARQ_AUTOR, ARQ_ABRE)
    tfEditora = io.open(ARQ_EDITORA, ARQ_ABRE)
    tfIdioma = io.open(ARQ_IDIOMA, ARQ_ABRE)
    tfEndereco = io.open(ARQ_ENDERECO, ARQ_ABRE)
    tfPais = io.open(ARQ_PAIS, ARQ_ABRE)
    tfProfissao = io.open(ARQ_PROFISSAO, ARQ_ABRE)
    tfLivro = io.open(ARQ_LIVRO, ARQ_ABRE)
    tfLivroAss = io.open(ARQ_LIVASS, ARQ_ABRE)
    tfLivroAut = io.open(ARQ_LIVAUT, ARQ_ABRE)
    tfCliente = io.open(ARQ_CLIENTE, ARQ_ABRE)
    tfUsuario = io.open(ARQ_USUARIO, ARQ_ABRE)
    tfVenda = io.open(ARQ_VENDA, ARQ_ABRE)
  else
    tfAssunto = io.open(ARQ_ASSUNTO, ARQ_CRIA)
    tfAutor = io.open(ARQ_AUTOR, ARQ_CRIA)
    tfEditora = io.open(ARQ_EDITORA, ARQ_CRIA)
    tfIdioma = io.open(ARQ_IDIOMA, ARQ_CRIA)
    tfEndereco = io.open(ARQ_ENDERECO, ARQ_CRIA)
    tfPais = io.open(ARQ_PAIS, ARQ_CRIA)
    tfProfissao = io.open(ARQ_PROFISSAO, ARQ_CRIA)
    tfLivro = io.open(ARQ_LIVRO, ARQ_CRIA)
    tfLivroAss = io.open(ARQ_LIVASS, ARQ_CRIA)
    tfLivroAut = io.open(ARQ_LIVAUT, ARQ_CRIA)
    tfCliente = io.open(ARQ_CLIENTE, ARQ_CRIA)
    tfUsuario = io.open(ARQ_USUARIO, ARQ_CRIA)
    tfVenda = io.open(ARQ_VENDA, ARQ_CRIA)
  end
end
-------------------------------------------------------------------------------
-- Fecha todos os arquivos abertos.
-------------------------------------------------------------------------------
function fechaArqs()
 io.close(tfAssunto)
 io.close(tfAutor)
 io.close(tfEditora)
 io.close(tfIdioma)
 io.close(tfEndereco)
 io.close(tfPais)
 io.close(tfProfissao)
 io.close(tfLivro)
 io.close(tfLivroAss)
 io.close(tfLivroAut)
 io.close(tfCliente)
 io.close(tfUsuario)
 io.close(tfVenda)
end

-------------------------------------------------------------------------------
-- Pesquisa um registro através de um valor chave num arquivo.
-- sArq - o arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o registro pesquisado
-------------------------------------------------------------------------------
function pesqArq(sArq, sChave, nPosChave, nTamChave, nTamLinha)
  sArq:seek('set')
  for slinha in sArq:lines() do    
    sres=trim(copy(slinha,nPosChave,nTamChave))    
    if sres==sChave then
       slocal = slinha
       break
    end
  end
  nPosicao=sArq:seek()-(nTamLinha + TAM_CRLF)
  if nPosicao > 0 then
     sArq:seek('cur',nPosicao)
  else
     sArq:seek('set')
  end
  if sres~=sChave then
     return ''
  else
     return copy(slocal,1,nTamLinha)
  end
end

-------------------------------------------------------------------------------
-- Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
-- sArq - o arquivo
-- nTamLinha - o tamanho do registro
-------------------------------------------------------------------------------
function pesqLinhaExcluida(sArq, nTamLinha)
  sExcluido=pesqArq(sArq, '*', 1, 1, nTamLinha)
  if sExcluido=='' then
     sArq:seek('end')
  end
end

-------------------------------------------------------------------------------
-- Pesquisa o maior código num arquivo.
-- sArq - o arquivo
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o maior código
-------------------------------------------------------------------------------
function pesqMaxCod(sArq, nPosChave, nTamChave, nTamLinha)
  nMaior=0
  sArq:seek('set')
  for slinha in sArq:lines() do    
    sres=trim(copy(slinha,nPosChave,nTamChave))
    nCod = tonumber(sres)
    if nCod > nMaior then
       nMaior = nCod
    end
  end
  pesqLinhaExcluida(sArq, nTamLinha)
  sres = tostring(nMaior+1)
  return sres
end
-------------------------------------------------------------------------------
-- Grava os registros num determinado arquivo.
-- sArq - o arquivo
-- sTexto - o registro a ser gravado
-- sMsgAcerto - a mensagem caso o registro foi gravado
-- sMsgErro - a mensagem caso o registro não foi gravado
-------------------------------------------------------------------------------
function escreveArq(sArq, sTexto, sMsgAcerto, sMsgErro)
  sTexto=sTexto..CRLF
  sArq:write(sTexto)
  print(sMsgAcerto)
  -- else
  --   print(sMsgErro)
  -- end
end

-- Rotinas de implementação do sistema e de interface ------------------------

-------------------------------------------------------------------------------
-- Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o registro montado
-------------------------------------------------------------------------------
function LinhaReg(sreg)
slinha=''
if sreg==[[opAssunto]] then
   slinha=esp(tAssunto.codigo,10)..esp(tAssunto.assunto,30)
elseif sreg==[[opAutor]] then
   slinha=esp(tAutor.codigo,10)..esp(tAutor.autor,30)
elseif sreg==[[opEditora]] then
   slinha=esp(tEditora.codigo,10)..esp(tEditora.editora,50)
elseif sreg==[[opEndereco]] then
   slinha=esp(tEndereco.codigo,10)..esp(tEndereco.logradouro,40)..
   esp(tEndereco.bairro,15)..esp(tEndereco.cep,8)..esp(tEndereco.cidade,30)..
   esp(tEndereco.estado,20)
elseif sreg==[[opIdioma]] then
   slinha=esp(tIdioma.codigo,10)..esp(tIdioma.idioma,20)
elseif sreg==[[opPais]] then
   slinha=esp(tPais.codigo,3)..esp(tPais.pais,50)
elseif sreg==[[opProfissao]] then
   slinha=esp(tProfissao.codigo,10)..esp(tProfissao.profissao,50)
elseif sreg==[[opUsuario]] then
   slinha=esp(tUsuario.login,10)..esp(tUsuario.senha,10)
elseif sreg==[[opLivro]] then
   slinha=esp(tLivro.isbn,13)..esp(tLivro.titulo,50)..esp(tLivro.edicao,10)..
   esp(tLivro.anopubli,10)..esp(tLivro.codeditora,10)..esp(tLivro.volume,10)..
   esp(tLivro.codidioma,10)..esp(tLivro.npaginas,10)..esp(tLivro.preco,10)..
   esp(tLivro.qtdestoque,10)
elseif sreg==[[opLivroAss]] then
   slinha=esp(tLivroAss.isbn,13)..esp(tlivroAss.codassunto,10)
elseif sreg==[[opLivroAut]] then
   slinha=esp(tLivroAut.isbn,13)..esp(tlivroAut.codautor,10)
elseif sreg==[[opCliente]] then
   slinha=esp(tCliente.cpf,14)..esp(tCliente.nome,30)..esp(tCliente.email,30)..
   esp(tCliente.identidade,10)..esp(tCliente.sexo,1)..esp(tCliente.telefone,17)..
   esp(tCliente.dtnascimento,10)..esp(tCliente.codendereco,10)..
   esp(tCliente.codpais,3)..esp(tCliente.codprofissao,10)
elseif sreg==[[opVenda]] then
   slinha=esp(tVenda.dthrvenda,19)..esp(tVenda.cpf,14)..esp(tVenda.isbn,13)..
   esp(tVenda.precovenda,10)
end
return slinha
end
-------------------------------------------------------------------------------
-- Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o tamanho do registro
-------------------------------------------------------------------------------
function tamReg(sreg)
  nret=0
  if sreg==[[opAssunto]] then nret=TAM_ASSUNTO
  elseif sreg==[[opAutor]] then nret=TAM_AUTOR
  elseif sreg==[[opEditora]] then nret=TAM_EDITORA
  elseif sreg==[[opEndereco]] then nret=TAM_ENDERECO
  elseif sreg==[[opIdioma]] then nret=TAM_IDIOMA
  elseif sreg==[[opPais]] then nret=TAM_PAIS
  elseif sreg==[[opProfissao]] then nret=TAM_PROFISSAO
  elseif sreg==[[opUsuario]] then nret=TAM_USUARIO
  elseif sreg==[[opLivro]] then nret=TAM_LIVRO
  elseif sreg==[[opLivroAss]] then nret=TAM_LIVASS
  elseif sreg==[[opLivroAut]] then nret=TAM_LIVAUT
  elseif sreg==[[opCliente]] then nret=TAM_CLIENTE
  elseif sreg==[[opVenda]] then nret=TAM_VENDA
  end
return nret
end

-------------------------------------------------------------------------------
-- Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- nNum - indica qual rotulo será retornado
-- retorna - o rotulo
-------------------------------------------------------------------------------
function rotulo(sreg, nNum)
sret=''
if sreg==[[opAssunto]] then
   if nNum==0 then sret='Assunto(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='Código do assunto: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Assunto: '
     g_nPosChave=11
     g_nTamChave=30
   end
elseif sreg==[[opAutor]] then
   if nNum==0 then sret='Autor(es) não encontrado(s)!'
   elseif nNum==1 then
     sret='Código do autor: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Autor: '
     g_nPosChave=11
     g_nTamChave=30
   end
elseif sreg==[[opEditora]] then
   if nNum==0 then sret='Editora(s) não encontrada(s)!'
   elseif nNum==1 then
     sret='Código da editora: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Editora: '
     g_nPosChave=11
     g_nTamChave=50
   end
elseif sreg==[[opEndereco]] then
   if nNum==0 then sret='Endereço(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='Código do endereço: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Logradouro: '
     g_nPosChave=11
     g_nTamChave=40
   elseif nNum==3 then
     sret='Bairro: '
     g_nPosChave=51
     g_nTamChave=15
   elseif nNum==4 then
     sret='CEP: '
     g_nPosChave=66
     g_nTamChave=8
   elseif nNum==5 then
     sret='Cidade: '
     g_nPosChave=74
     g_nTamChave=30
   elseif nNum==6 then
     sret='Estado: '
     g_nPosChave=104
     g_nTamChave=20
   end
elseif sreg==[[opIdioma]] then
   if nNum==0 then sret='Idioma(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='Código do idioma: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Idioma: '
     g_nPosChave=11
     g_nTamChave=20
   end
elseif sreg==[[opPais]] then
   if nNum==0 then sret='País(es) não encontrado(s)!'
   elseif nNum==1 then
     sret='Código do país: '
     g_nPosChave=1
     g_nTamChave=3
   elseif nNum==2 then
     sret='País: '
     g_nPosChave=4
     g_nTamChave=50
   end
elseif sreg==[[opProfissao]] then
   if nNum==0 then sret='Profissão(es) não encontrada(s)!'
   elseif nNum==1 then
     sret='Código da profissão: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Profissão: '
     g_nPosChave=11
     g_nTamChave=50
   end
elseif sreg==[[opUsuario]] then
   if nNum==0 then sret='login ou senha incorreta, tente de novo!'
   elseif nNum==1 then
     sret='Login: '
     g_nPosChave=1
     g_nTamChave=10
   elseif nNum==2 then
     sret='Senha: '
     g_nPosChave=11
     g_nTamChave=10
   end
elseif sreg==[[opLivro]] then
   if nNum==0 then sret='Livro(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='ISBN: '
     g_nPosChave=1
     g_nTamChave=13
   elseif nNum==2 then
     sret='Título: '
     g_nPosChave=14
     g_nTamChave=50
   elseif nNum==3 then
     sret='Edição: '
     g_nPosChave=64
     g_nTamChave=10
   elseif nNum==4 then
     sret='Ano de Publicação: '
     g_nPosChave=74
     g_nTamChave=10
   elseif nNum==5 then
     sret='Código da editora: '
     g_nPosChave=84
     g_nTamChave=10
   elseif nNum==6 then
     sret='Volume: '
     g_nPosChave=94
     g_nTamChave=10
   elseif nNum==7 then
     sret='Código do idioma: '
     g_nPosChave=104
     g_nTamChave=10
   elseif nNum==8 then
     sret='Número de páginas: '
     g_nPosChave=114
     g_nTamChave=10
   elseif nNum==9 then
     sret='Preço: '
     g_nPosChave=124
     g_nTamChave=10
   elseif nNum==10 then
     sret='Qtd. Estoque: '
     g_nPosChave=134
     g_nTamChave=10
   end
elseif sreg==[[opLivroAss]] then
   if nNum==0 then sret='Assunto(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='ISBN: '
     g_nPosChave=1
     g_nTamChave=13
   elseif nNum==2 then
     sret='Código do assunto: '
     g_nPosChave=14
     g_nTamChave=10
   end
elseif sreg==[[opLivroAut]] then
   if nNum==0 then sret='Autor(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='ISBN: '
     g_nPosChave=1
     g_nTamChave=13
   elseif nNum==2 then
     sret='Código do autor: '
     g_nPosChave=14
     g_nTamChave=10
   end
elseif sreg==[[opCliente]] then
   if nNum==0 then sret='Cliente(s) não encontrado(s)!'
   elseif nNum==1 then
     sret='CPF: '
     g_nPosChave=1
     g_nTamChave=14
   elseif nNum==2 then
     sret='Nome: '
     g_nPosChave=15
     g_nTamChave=30
   elseif nNum==3 then
     sret='E-mail: '
     g_nPosChave=45
     g_nTamChave=30
   elseif nNum==4 then
     sret='Identidade: '
     g_nPosChave=75
     g_nTamChave=10
   elseif nNum==5 then
     sret='Sexo: '
     g_nPosChave=85
     g_nTamChave=1
   elseif nNum==6 then
     sret='Telefone: '
     g_nPosChave=86
     g_nTamChave=17
   elseif nNum==7 then
     sret='Dt. Nascimento: '
     g_nPosChave=103
     g_nTamChave=10
   elseif nNum==8 then
     sret='Código do endereço: '
     g_nPosChave=113
     g_nTamChave=10
   elseif nNum==9 then
     sret='Código do país: '
     g_nPosChave=123
     g_nTamChave=3
   elseif nNum==10 then
     sret='Código da Profissão: '
     g_nPosChave=126
     g_nTamChave=10
   end
elseif sreg==[[opVenda]] then
   if nNum==0 then sret='Venda(s) não encontrada(s)!'
   elseif nNum==1 then
     sret='Data/Hora venda: '
     g_nPosChave=1
     g_nTamChave=19
   elseif nNum==2 then
     sret='CPF: '
     g_nPosChave=20
     g_nTamChave=14
   elseif nNum==3 then
     sret='ISBN: '
     g_nPosChave=34
     g_nTamChave=13
   elseif nNum==4 then
     sret='Preço de venda: '
     g_nPosChave=47
     g_nTamChave=10
   end
end

return sret
end

-------------------------------------------------------------------------------
-- Indica se continua ou não mostrando um número máximo de linhas.
-- nlinha - a linha a ser continuada
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se continua ou não
-------------------------------------------------------------------------------
function ContinuaSN(nlinha, nQtdLinha)
bret=false
if nlinha > 0 then 
  if math.mod(nlinha, nQtdLinha) == 0 then
      bSOp=true
      while (bSOp==true) do
        menu(13)
        opCSubMenu = digita()
        if (opCSubMenu=='S') or (opCSubMenu=='s') then bSOp=false
        elseif (opCSubMenu=='N') or (opCSubMenu=='n') then
          bret=true
          bSOp=false
        else print(MSG_ERRO) end 
      end
  end
end

return bret
end

-------------------------------------------------------------------------------
-- Lista vários registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se encontrou algum registro
-------------------------------------------------------------------------------
function ListarTodos(sArq, sreg, sChave, nPosChave, nTamChave, 
                     nTamLinha, nQtdLinha, bPesqRelativa)
bRet=false
nCont=0
mostrarDados(sreg, '', 2)
sArq:seek('set')
for slinha in sArq:lines() do
  if bPesqRelativa==true then
    sres=trim(copy(slinha,nPosChave,nTamChave))
    if strRelativa(sres,sChave) then
       bAchou=true
       bRet=true
    else
       bAchou=false
    end
  else
    bAchou=true
    bRet=true
  end

  if bAchou then
    mostrarDados(sreg, copy(slinha,1,nTamLinha), 3)
    nCont=nCont+1
  end

  if ContinuaSN(nCont, nQtdLinha) then
     break
  end
end
return bRet
end

-------------------------------------------------------------------------------
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
-------------------------------------------------------------------------------
function ListarRegLigados(sArq1, sreg1, nPosChave1, nTamChave1, 
	 nPosChave2, nTamChave2, sChave, sArq2, sreg2, nPosChave3, nQtdLinha)
bRet=false
nCont=0
mostrarDados(sreg2, '', 2)
sArq1:seek('set')
  for slinha1 in sArq1:lines() do
    sCodigo1=trim(copy(slinha1,nPosChave1,nTamChave1))
    if sCodigo1==sChave then
      sCodigo2=trim(copy(slinha1,nPosChave2,nTamChave2))
      slinha2=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
      mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3)
      bRet=true
      nCont=nCont+1
    end
    if ContinuaSN(nCont, nQtdLinha) then
       break
    end
  end
  if bRet==false then
     print(rotulo(sreg2,0))
  end
end

-------------------------------------------------------------------------------
-- Valida a entrada de registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- nTexto - o numero do rótulo da entrada
-- sEntrada - a chave a ser pesquisada e validada
-- nTentativas - o número máximo de tentativas
-- bPesqRelativa - indica se vai realizar uma pesquisa relativa
-- bTipoEntrada - indica o tipo de entrada
-- retorna - o registro pesquisado e validado
-------------------------------------------------------------------------------
function validaEntrada(sArq, sreg, nTexto, sEntrada, nTentativas,
                       bPesqRelativa, bTipoEntrada)
nTamLinha=tamReg(sreg)
sMsgErro=rotulo(sreg,0)
sTexto=rotulo(sreg,nTexto)
nPosChave=g_nPosChave
nTamChave=g_nTamChave

sres=''
ncont=1
bQuebra=false
  while (bQuebra==false) and (ncont <= nTentativas ) do
    if bTipoEntrada==[[opTexto]] then
      io.write(sTexto)
      sEntrada = digita()
    elseif bTipoEntrada==[[opNumero]] then
       sEntrada=validaNumero(sTexto,sEntrada)
    elseif bTipoEntrada==[[opData]] then
       sEntrada=validaDataHora(sTexto,sEntrada,true)
    elseif bTipoEntrada==[[opDataHora]] then
       sEntrada=validaDataHora(sTexto,sEntrada,false)
    elseif bTipoEntrada==[[opSenha]] then
       sEntrada=digitaSenha(sTexto, 10)
    end

    if bPesqRelativa==true then
       if ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, true)==true then
         sres=' '
       end
    else
       sres=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)
    end
    if sres=='' then
       print(sMsgErro)
    else
       bQuebra=true
    end
    ncont=ncont+1
  end
return sres
end

------------------------------------------------------------------------------
-- Mostra a tela de splash do sistema.
------------------------------------------------------------------------------
function frmSplash()
 print('*---------------------------------------' .. 
 '-------------------------------------*')
 print('| LL    II VV   VV RRRRR  UU  UU   SSSS ' ..
 'VV   VV II RRRRR  TTTT UU  UU   SSSS |')
 print('| LL    II  VV VV  RR   R UU  UU  SS    ' ..
 ' VV VV  II RR   R  TT  UU  UU  SS    |')
 print('| LL    II   VVV   RRRRR  UU  UU    SS  ' ..
 '  VVV   II RRRRR   TT  UU  UU    SS  |')
 print('| LLLLL II    V    RR   R  UUUU  SSSS   ' ..
 '   V    II RR   R  TT   UUUU  SSSS   |')
 print('*---------------------------------------' ..
 '-------------------------------------*')
 for cont = 1,18 do print('') end
 io.write(MSG_PRESS)
 digita()
end

-------------------------------------------------------------------------------
-- Mostra a tela de sobre do sistema.
-------------------------------------------------------------------------------
function frmSobre()
 print('*------------------------------------------------------------*')
 print('|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |')
 print('|  LL        II   VV     VV   RR     R  UU    UU  SS         |')
 print('|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |')
 print('|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |')
 print('|  LLLL      II      VVV      RR RR     UU    UU        SS   |')
 print('|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |')
 print('|                                                            |')
 print('|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |')
 print('|   VV     VV   II  RR     R     TT     UU    UU  SS         |')
 print('|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |')
 print('|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |')
 print('|      VVV      II  RR RR        TT     UU    UU        SS   |')
 print('|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |')
 print('|                                                            |')
 print('|                                               Versao 1.0.0 |')
 print('| Sistema integrante do projeto Livrus Virtus.               |')
 print('| Todos os direitos reservados para Henrique F. de Souza.    |')
 print('| Versao programada na linguagem lua.                        |')
 print('*------------------------------------------------------------*')
 for cont = 1,4 do print('') end
 io.write(MSG_PRESS)
 digita()
end

-------------------------------------------------------------------------------
-- Mostra a tela de login do sistema.
-- retorna - se o login foi validado corretamente
-------------------------------------------------------------------------------
function frmLogin() 
  bret=false
  print('*--------------------------------------------------------------*')
  print('| Login do sistema                                             |')
  print('*--------------------------------------------------------------*')
  slinha=validaEntrada(tfUsuario, [[opUsuario]], 1, tUsuario.login, 3,
        false, [[opTexto]])
  if slinha~='' then
     slinha=validaEntrada(tfUsuario, [[opUsuario]], 2, tUsuario.senha, 3,
        false, [[opSenha]])
     if slinha~='' then
        tUsuario.login=trim(copy(slinha, 1, 10))
        tUsuario.senha=trim(copy(slinha, 11, 10))
        bret=true
     end
  end
  print('')
  return bret
end

-------------------------------------------------------------------------------
-- Mostra os menus do sistema.
-- num - o número do menu
-------------------------------------------------------------------------------
function menu(num)
 if (num==1) then
   print('*--------------------------------------------------------------*')
   print('| (C)adastros        (P)esquisas     (V)endas        (O)pções  |')
   print('*--------------------------------------------------------------*')
 elseif (num==2) then 
   print('*---------------------------------*')
   print('| 01. Cadastro de Assuntos        |')
   print('| 02. Cadastro de Autores         |')
   print('| 03. Cadastro de Editoras        |')
   print('| 04. Cadastro de Endereços       |')
   print('| 05. Cadastro de Idiomas         |')
   print('| 06. Cadastro de Países          |')
   print('| 07. Cadastro de Profissões      |')
   print('| 08. Cadastro de Clientes        |')
   print('| 09. Cadastro de Livros          |')
   print('| 10. Voltar ao menu              |')
   print('*---------------------------------*')
 elseif (num==3) then 
   print('*---------------------------------*')
   print('| 01. Consulta de Assuntos        |')
   print('| 02. Consulta de Autores         |')
   print('| 03. Consulta de Editoras        |')
   print('| 04. Consulta de Endereços       |')
   print('| 05. Consulta de Idiomas         |')
   print('| 06. Consulta de Países          |')
   print('| 07. Consulta de Profissões      |')
   print('| 08. Consulta de Clientes        |')
   print('| 09. Consulta de Livros          |')
   print('| 10. Voltar ao menu              |')
   print('*---------------------------------*')
 elseif (num==4) then 
   print('*---------------------------------*')
   print('| 01. Vender Livros               |')
   print('| 02. Vendas Realizadas           |')
   print('| 03. Voltar ao menu              |')
   print('*---------------------------------*')
 elseif (num==5) then 
   print('*---------------------------------*')
   print('| 01. Alterar senha               |')
   print('| 02. Sobre o sistema             |')
   print('| 03. Sair do sistema             |')
   print('| 04. Voltar ao menu              |')
   print('*---------------------------------*')
 elseif (num==6) then 
   print('*--------------------------------------------------------------*')
   print('| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |')
   print('*--------------------------------------------------------------*')
 elseif (num==7) then 
   print('*--------------------------------------------------------------*')
   print('| (1) Salvar inclusão       (2) Voltar ao menu                 |')
   print('*--------------------------------------------------------------*')
 elseif (num==8) then 
   print('*--------------------------------------------------------------*')
   print('| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |')
   print('*--------------------------------------------------------------*')
 elseif (num==9) then 
   print('*--------------------------------------------------------------*')
   print('| (1) Salvar alteração      (2) Voltar ao menu                 |')
   print('*--------------------------------------------------------------*')
 elseif (num==10) then 
   print('*--------------------------------------------------------------*')
   print('| Certeza de excluir? (S/N)                                    |')
   print('*--------------------------------------------------------------*')
 elseif (num==11) then 
   print('*--------------------------------------------------------------*')
   print('| Deseja sair do sistema? (S/N)                                |')
   print('*--------------------------------------------------------------*')
 elseif (num==12) then 
   print('*--------------------------------------------------------------*')
   print('| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |')
   print('*--------------------------------------------------------------*')
 elseif (num==13) then 
   print('*--------------------------------------------------------------*')
   print('| Deseja continuar? (S/N)                                      |')
   print('*--------------------------------------------------------------*')
 elseif (num==14) then 
   print('*--------------------------------------------------------------*')
   print('| Salvar inclusão (S/N)                                        |')
   print('*--------------------------------------------------------------*')
 end
 io.write(MSG_OPCAO)
end

-------------------------------------------------------------------------------
-- Realiza os cadastros de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-------------------------------------------------------------------------------
function frmCadastros(sreg, sacao)
if sreg==[[opAssunto]] then
   if sacao==[[opNovo]] then
      tAssunto.codigo=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg))
      mostrarDados(sreg, '', 1)
      subMenu(7, sreg)
   elseif sacao==[[opPesquisar]] then
     slinha=validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,[[opNumero]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opAutor]] then
   if sacao==[[opNovo]] then
      tAutor.codigo=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg))
      mostrarDados(sreg, '', 1)
      subMenu(7, sreg)
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,false,[[opNumero]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opEditora]] then
   if sacao==[[opNovo]] then
      tEditora.codigo=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg))
      mostrarDados(sreg, '', 1)
      subMenu(7, sreg)
   elseif sacao==[[opPesquisar]] then
     slinha=validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,false,[[opNumero]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opEndereco]] then
   if sacao==[[opNovo]] then
      tEndereco.codigo=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg))
      mostrarDados(sreg, '', 1)
      subMenu(7, sreg)
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
              false,[[opNumero]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opIdioma]] then
   if sacao==[[opNovo]] then
      tIdioma.codigo=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg))
      mostrarDados(sreg, '', 1)
      subMenu(7, sreg)
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,false,[[opNumero]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opPais]] then
   if sacao==[[opNovo]] then
      io.write(rotulo(sreg, 1))
      tPais.codigo = digita()
      slinha=pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg))
      if slinha=='' then 
         pesqLinhaExcluida(tfPais, tamReg(sreg))
         mostrarDados(sreg, '', 1)
         subMenu(7, sreg)
      else print(MSG_REGEXST) end
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, [[opTexto]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      print(rotulo(sreg, 1)..tPais.codigo)
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opProfissao]] then
   if sacao==[[opNovo]] then
      tProfissao.codigo=pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg))
      mostrarDados(sreg, '', 1)
      subMenu(7, sreg)
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
              false,[[opNumero]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opLivro]] then
   if sacao==[[opNovo]] then
      io.write(rotulo(sreg, 1))
      tLivro.isbn = digita()
      if validaISBN(tLivro.isbn) then 
          slinha=pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg))
          if slinha=='' then 
             pesqLinhaExcluida(tfLivro, tamReg(sreg))
             mostrarDados(sreg, '', 1)
             subMenu(7, sreg)
             frmCadLigados([[opLivroAss]], [[opNovo]], tLivro.isbn)
             frmCadLigados([[opLivroAut]], [[opNovo]], tLivro.isbn)
          else print(MSG_REGEXST) end
      else print(MSG_ISBNINV) end
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,[[opTexto]])
      if slinha~='' then 
         mostrarDados(sreg, '', 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      print(rotulo(sreg, 1)..tLivro.isbn)
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
      frmCadLigados([[opLivroAss]], [[opExcluir]], tLivro.isbn)
      print('Assuntos dos livros excluídos, inclua novos!')
      frmCadLigados([[opLivroAss]], [[opNovo]], tLivro.isbn)
      frmCadLigados([[opLivroAut]], [[opExcluir]], tLivro.isbn)
      print('Autores dos livros excluídos, inclua novos!')
      frmCadLigados([[opLivroAut]], [[opNovo]], tLivro.isbn)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
      print('Assuntos dos livros sendo excluídos!')
      frmCadLigados([[opLivroAss]], [[opExcluir]], tLivro.isbn)
      print('Autores dos livros sendo excluídos!')
      frmCadLigados([[opLivroAut]], [[opExcluir]], tLivro.isbn)
   end
elseif sreg==[[opCliente]] then
   if sacao==[[opNovo]] then
      io.write(rotulo(sreg, 1))
      tCliente.cpf = digita()
      if validaCPF(tCliente.cpf) then 
          slinha=pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg))
          if slinha=='' then 
             pesqLinhaExcluida(tfCliente, tamReg(sreg))
             mostrarDados(sreg, '', 1)
             subMenu(7, sreg)
          else print(MSG_REGEXST) end
      else print(MSG_CPFINV) end
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,[[opTexto]])
      if slinha~='' then 
         mostrarDados(sreg, '', 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      end
   elseif sacao==[[opAlterar]] then
      print(rotulo(sreg, 1)..tCliente.cpf)
      mostrarDados(sreg, '', 1)
      subMenu(9, sreg)
   elseif sacao==[[opExcluir]] then
      subMenu(10, sreg)
   end
elseif sreg==[[opVenda]] then
   if sacao==[[opNovo]] then
      tVenda.dthrvenda=retDataHora()
      print(rotulo(sreg, 1)..tVenda.dthrvenda)
      slinha=pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg))
      if slinha=='' then 
         slinha=validaEntrada(tfCliente,[[opCliente]],1,tVenda.cpf,3,
                 false,[[opTexto]])
         if slinha~='' then 
            tVenda.cpf=trim(copy(slinha,1,14))
            if validaCPF(tVenda.cpf) then 
               io.write(' '..rotulo([[opCliente]], 2)) -- Nome 
               print(copy(slinha, g_nPosChave, g_nTamChave))
               frmCadLigados([[opVenda]], [[opNovo]], tVenda.cpf)
            else print(MSG_CPFINV) end
         end
      else print(MSG_REGEXST) end
   elseif sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
              false,[[opDataHora]])
      if slinha~='' then 
        mostrarDados(sreg, '', 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   end
end

end

-------------------------------------------------------------------------------
-- Realiza as consultas de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-------------------------------------------------------------------------------
function frmConsultas(sreg, sacao)
slinha=''
if sreg==[[opAssunto]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfAssunto, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opAutor]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfAutor, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opEditora]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfEditora, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opEndereco]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfEndereco,sreg,2,tEndereco.Logradouro,1,
              true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfEndereco, sreg, '', 0, 0, tamReg(sreg),
         3, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opIdioma]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfIdioma, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opPais]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfPais, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opProfissao]] then
   if sacao==[[opPesquisar]] then
     slinha=validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfProfissao, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opLivro]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfLivro, sreg, '', 0, 0, tamReg(sreg),
        1, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opCliente]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfCliente, sreg, '', 0, 0, tamReg(sreg),
        1, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
elseif sreg==[[opVenda]] then
   if sacao==[[opPesquisar]] then
      slinha=validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,[[opTexto]])
   elseif sacao==[[opListarTodos]] then 
      if ListarTodos(tfVenda, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0))
      end  
   end
end
if slinha=='' then
   io.write('')
end
end

-------------------------------------------------------------------------------
-- Mostra a tela de alteração de senha do sistema e realiza a alteração.
-------------------------------------------------------------------------------
function frmAlterarSenha()
print(rotulo([[opUsuario]], 1)..tUsuario.login)
nopcao=1
bQuebra=false
  while (bQuebra==false) do
    if nopcao==1 then
      sSenhaAtual=digitaSenha('Senha Atual: ',10)
      if sSenhaAtual~=tUsuario.senha then
         print(MSG_SENCONFERE)
         bQuebra=true
      else 
         nopcao=2 
      end
    elseif nopcao==2 then
      sNovaSenha=digitaSenha('Nova Senha: ',10)
      sConfirmaSenha=digitaSenha('Confirma Senha: ',10)
      if sNovaSenha~=sConfirmaSenha then
         print(MSG_SENCONFIRM)
         bQuebra=true
      else 
         nopcao=3
      end
    elseif nopcao==3 then
      sres=pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg([[opUsuario]]))
      if sres=='' then
         print(MSG_LOGINENCON)
      else
         tUsuario.senha=sConfirmaSenha
         subMenu(9,[[opUsuario]])
         bQuebra=true
      end
    end
  end
end

-------------------------------------------------------------------------------
-- Executa uma ação de gravação de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-------------------------------------------------------------------------------
function btnAcao(sreg, sacao)
if sreg==[[opAssunto]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfAssunto, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opAutor]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfAutor, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opEditora]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfEditora, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opEndereco]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfEndereco, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opIdioma]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfIdioma, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opPais]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfPais, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opProfissao]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfProfissao, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opLivro]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfLivro, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opLivroAss]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfLivroAss, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opLivroAut]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfLivroAut, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opCliente]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfCliente, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opVenda]] then
   if sacao==[[opSalvarInclusao]] then
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao==[[opSalvarAlteracao]] then
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao==[[opConfirmaExclusao]] then
      escreveArq(tfVenda, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elseif sreg==[[opUsuario]] then
   if sacao==[[opSalvarAlteracao]] then
      escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   end
end
end

-------------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-------------------------------------------------------------------------------
function subMenu(nmenu, sreg)
bSOp=true
if nmenu==6 then
  while(bSOp) do
    menu(nmenu)
    opSubMenu = digita()
    if opSubMenu=='1' then frmCadastros(sreg, [[opNovo]])
    elseif opSubMenu=='2' then frmCadastros(sreg, [[opPesquisar]])
    elseif opSubMenu=='3' then bSOp=false
    else print(MSG_ERRO) end
  end
elseif nmenu==7 then
  while(bSOp) do 
    menu(nmenu)
    opSubMenu = digita()
    if opSubMenu=='1' then 
      btnAcao(sreg, [[opSalvarInclusao]]) 
      bSOp=false 
    elseif opSubMenu=='2' then bSOp=false
    else print(MSG_ERRO) end
  end
elseif nmenu==8 then
  while(bSOp) do 
    menu(nmenu)
    opSubMenu = digita()
    if opSubMenu=='1' then 
      frmCadastros(sreg, [[opAlterar]]) 
      bSOp=false
    elseif opSubMenu=='2' then 
      frmCadastros(sreg, [[opExcluir]]) 
      bSOp=false
    elseif opSubMenu=='3' then bSOp=false
    else print(MSG_ERRO) end
  end
elseif nmenu==9 then
  while(bSOp) do 
    menu(nmenu)
    opSubMenu = digita()
    if opSubMenu=='1' then 
      btnAcao(sreg, [[opSalvarAlteracao]]) 
      bSOp=false
    elseif opSubMenu=='2' then bSOp=false
    else print(MSG_ERRO) end
  end
elseif nmenu==10 then
  while(bSOp) do 
    menu(nmenu)
    opCSubMenu = digita()
    if (opCSubMenu=='S') or (opCSubMenu=='s') then 
      btnAcao(sreg, [[opConfirmaExclusao]])
      bSOp=false
    elseif (opCSubMenu=='N') or (opCSubMenu=='n') then bSOp=false
    else print(MSG_ERRO) end
  end
elseif nmenu==12 then
  while(bSOp) do 
    menu(nmenu)
    opSubMenu = digita()
    if opSubMenu=='1' then frmConsultas(sreg, [[opPesquisar]])
    elseif opSubMenu=='2' then frmConsultas(sreg, [[opListarTodos]])
    elseif opSubMenu=='3' then bSOp=false
    else print(MSG_ERRO) end
  end
elseif nmenu==14 then
  while(bSOp) do 
    menu(nmenu)
    opCSubMenu = digita()
    if (opCSubMenu=='S') or (opCSubMenu=='s') then 
       btnAcao(sreg, [[opSalvarInclusao]])
       bSOp=false
       g_SalvarInclusao=true
    elseif (opCSubMenu=='N') or (opCSubMenu=='n') then bSOp=false
    else print(MSG_ERRO) end
  end
end

end

-------------------------------------------------------------------------------
-- Seleciona o submenu e/ou a tela certa de acordo com número do menu.
-- nmenu - o número do menu
-------------------------------------------------------------------------------
function usaMenu(num)
 bSOp=true
 if num == 1 then -- Cadastros 
   while(bSOp) do 
     menu(2)
     opSubMenu = digita()
     if opSubMenu=='1' then subMenu(6, [[opAssunto]])
     elseif opSubMenu=='2' then subMenu(6, [[opAutor]])
     elseif opSubMenu=='3' then subMenu(6, [[opEditora]])
     elseif opSubMenu=='4' then subMenu(6, [[opEndereco]])
     elseif opSubMenu=='5' then subMenu(6, [[opIdioma]])
     elseif opSubMenu=='6' then subMenu(6, [[opPais]])
     elseif opSubMenu=='7' then subMenu(6, [[opProfissao]])
     elseif opSubMenu=='8' then subMenu(6, [[opCliente]])
     elseif opSubMenu=='9' then subMenu(6, [[opLivro]])
     elseif opSubMenu=='10' then bSOp=false
     else print(MSG_ERRO) end
   end
 elseif num == 2 then  -- Pesquisas 
   while(bSOp) do 
     menu(3)
     opSubMenu = digita()
     if opSubMenu=='1' then subMenu(12, [[opAssunto]])
     elseif opSubMenu=='2' then subMenu(12, [[opAutor]])
     elseif opSubMenu=='3' then subMenu(12, [[opEditora]])
     elseif opSubMenu=='4' then subMenu(12, [[opEndereco]])
     elseif opSubMenu=='5' then subMenu(12, [[opIdioma]])
     elseif opSubMenu=='6' then subMenu(12, [[opPais]])
     elseif opSubMenu=='7' then subMenu(12, [[opProfissao]])
     elseif opSubMenu=='8' then subMenu(12, [[opCliente]])
     elseif opSubMenu=='9' then subMenu(12, [[opLivro]])
     elseif opSubMenu=='10' then bSOp=false
     else print(MSG_ERRO) end
   end
 elseif num == 3 then  -- Vendas 
   while(bSOp) do 
     menu(4)
     opSubMenu = digita()
     if opSubMenu=='1' then subMenu(6, [[opVenda]])
     elseif opSubMenu=='2' then subMenu(12, [[opVenda]])
     elseif opSubMenu=='3' then bSOp=false
     else print(MSG_ERRO) end
   end
 elseif num == 4 then  -- Opcoes 
   while(bSOp) do 
     menu(5)
     opSubMenu = digita()
     if opSubMenu=='1' then frmAlterarSenha()
     elseif opSubMenu=='2' then frmSobre()
     elseif opSubMenu=='3' then
       menu(11)
       opSair = digita()
       if (opSair=='S') or (opSair=='s') then 
          fechaArqs()
          os.exit(0)
       end
     elseif opSubMenu=='4' then bSOp=false
     else print(MSG_ERRO) end
   end
 end
end

-------------------------------------------------------------------------------
-- Mostra as entradas e as saídas do sistema.
-- sreg - o tipo de arquivo
-- slinha - o registro com os dados
-- nOpcao - indica qual opção será mostrada
-------------------------------------------------------------------------------
function mostrarDados(sreg, slinha, nOpcao)
if sreg==[[opAssunto]] then
  if nOpcao==1 then
    print(rotulo(sreg, 1)..tAssunto.codigo)
    io.write(rotulo(sreg, 2))
    tAssunto.assunto = digita()
  elseif nOpcao==2 then
    print('Código     Assunto')
    print('------     -------')
  elseif nOpcao==3 then
    tAssunto.codigo=copy(slinha, 1, 10)
    tAssunto.assunto=copy(slinha, 11, 30)
    print(tAssunto.codigo..' '..tAssunto.assunto)
  end
elseif sreg==[[opAutor]] then
  if nOpcao==1 then
    print(rotulo(sreg, 1)..tAutor.codigo)
    io.write(rotulo(sreg, 2))
    tAutor.autor = digita()
  elseif nOpcao==2 then
    print('Código     Autor')
    print('------     -----')
  elseif nOpcao==3 then
    tAutor.codigo=copy(slinha, 1, 10)
    tAutor.autor=copy(slinha, 11, 30)
    print(tAutor.codigo..' '..tAutor.autor)
  end
elseif sreg==[[opEditora]] then
  if nOpcao==1 then
    print(rotulo(sreg, 1)..tEditora.codigo)
    io.write(rotulo(sreg, 2))
    tEditora.editora = digita()
  elseif nOpcao==2 then
    print('Código     Editora')
    print('------     -------')
  elseif nOpcao==3 then
    tEditora.codigo=copy(slinha, 1, 10)
    tEditora.editora=copy(slinha, 11, 50)
    print(tEditora.codigo..' '..tEditora.editora)
  end
elseif sreg==[[opEndereco]] then
  if nOpcao==1 then
    print(rotulo(sreg, 1)..tEndereco.codigo)
    io.write(rotulo(sreg, 2))
    tEndereco.Logradouro = digita()
    io.write(rotulo(sreg, 3))
    tEndereco.bairro = digita()
    io.write(rotulo(sreg, 4))
    tEndereco.cep = digita()
    io.write(rotulo(sreg, 5))
    tEndereco.cidade = digita()
    io.write(rotulo(sreg, 6))
    tEndereco.estado = digita()
  elseif nOpcao==3 then
    tEndereco.codigo=trim(copy(slinha, 1, 10))
    tEndereco.logradouro=trim(copy(slinha, 11, 40))
    tEndereco.bairro=trim(copy(slinha, 51, 15))
    tEndereco.cep=trim(copy(slinha, 66, 8))
    tEndereco.cidade=trim(copy(slinha, 74, 30))
    tEndereco.estado=trim(copy(slinha, 104, 20))
    print('--------------------')
    print(rotulo(sreg, 1)..tEndereco.codigo)
    print(rotulo(sreg, 2)..tEndereco.Logradouro)
    print(rotulo(sreg, 3)..tEndereco.bairro)
    print(rotulo(sreg, 4)..tEndereco.cep)
    print(rotulo(sreg, 5)..tEndereco.cidade)
    print(rotulo(sreg, 6)..tEndereco.estado)
  end
elseif sreg==[[opIdioma]] then
  if nOpcao==1 then
    print(rotulo(sreg, 1)..tIdioma.codigo)
    io.write(rotulo(sreg, 2))
    tIdioma.idioma = digita()
  elseif nOpcao==2 then
    print('Código     Idioma')
    print('------     ------')
  elseif nOpcao==3 then
    tIdioma.codigo=copy(slinha, 1, 10)
    tIdioma.idioma=copy(slinha, 11, 20)
    print(tIdioma.codigo..' '..tIdioma.idioma)
  end
elseif sreg==[[opPais]] then
  if nOpcao==1 then
    io.write(rotulo(sreg, 2))
    tPais.pais = digita()
  elseif nOpcao==2 then
    print('Código País')
    print('------ ----')
  elseif nOpcao==3 then
    tPais.codigo=copy(slinha, 1, 3)
    tPais.pais=copy(slinha, 4, 50)
    print(tPais.codigo..'    '..tPais.pais)
  end
elseif sreg==[[opProfissao]] then
  if nOpcao==1 then
    print(rotulo(sreg, 1)..tProfissao.codigo)
    io.write(rotulo(sreg, 2))
    tProfissao.profissao = digita()
  elseif nOpcao==2 then
    print('Código     Profissão')
    print('------     ---------')
  elseif nOpcao==3 then
    tProfissao.codigo=copy(slinha, 1, 10)
    tProfissao.profissao=copy(slinha, 11, 50)
    print(tProfissao.codigo..' '..tProfissao.profissao)
  end
elseif sreg==[[opLivro]] then
  if nOpcao==1 then
    io.write(rotulo(sreg, 2))
    tLivro.titulo = digita()
    tLivro.edicao=validaNumero(rotulo(sreg, 3), tLivro.edicao)
    tLivro.anopubli=validaNumero(rotulo(sreg, 4), tLivro.anopubli)
    mostrarSubDados([[opLivro]], [[opEditora]], false)
    tLivro.volume=validaNumero(rotulo(sreg, 6), tLivro.volume)
    mostrarSubDados([[opLivro]], [[opIdioma]], false)
    tLivro.npaginas=validaNumero(rotulo(sreg, 8), tLivro.npaginas)
    tLivro.preco=validaNumero(rotulo(sreg, 9), tLivro.preco)
    tLivro.qtdestoque=validaNumero(rotulo(sreg, 10), tLivro.qtdestoque)
  elseif nOpcao==3 then
    tLivro.isbn=trim(copy(slinha, 1, 13))
    tLivro.titulo=trim(copy(slinha, 14, 50))
    tLivro.edicao=trim(copy(slinha, 64, 10))
    tLivro.anopubli=trim(copy(slinha, 74, 10))
    tLivro.codeditora=trim(copy(slinha, 84, 10))
    tLivro.volume=trim(copy(slinha, 94, 10))
    tLivro.codidioma=trim(copy(slinha, 104, 10))
    tLivro.npaginas=trim(copy(slinha, 114, 10))
    tLivro.preco=trim(copy(slinha, 124, 10))
    tLivro.qtdestoque=trim(copy(slinha, 134, 10))
    print('--------------------')
    print(rotulo(sreg, 1)..tLivro.isbn)
    print(rotulo(sreg, 2)..tLivro.titulo)
    print(rotulo(sreg, 3)..tLivro.edicao)
    print(rotulo(sreg, 4)..tLivro.anopubli)
    print(rotulo(sreg, 5)..tLivro.codeditora)
    mostrarSubDados([[opLivro]], [[opEditora]], true)
    print(rotulo(sreg, 6)..tLivro.volume)
    print(rotulo(sreg, 7)..tLivro.codidioma)
    mostrarSubDados([[opLivro]], [[opIdioma]], true)
    print(rotulo(sreg, 8)..tLivro.npaginas)
    print(rotulo(sreg, 9)..tLivro.preco)
    print(rotulo(sreg, 10)..tLivro.qtdestoque)
    ListarRegLigados(tfLivroAss, [[opLivroAss]], 1, 13, 14, 10, tLivro.isbn,
                     tfAssunto, [[opAssunto]], 1, 4)
    ListarRegLigados(tfLivroAut, [[opLivroAut]], 1, 13, 14, 10, tLivro.isbn,
                     tfAutor, [[opAutor]], 1, 4)
  end
elseif sreg==[[opCliente]] then
  if nOpcao==1 then
    io.write(rotulo(sreg, 2))
    tCliente.nome = digita()
    io.write(rotulo(sreg, 3))
    tCliente.email = digita()
    io.write(rotulo(sreg, 4))
    tCliente.identidade = digita()
    io.write(rotulo(sreg, 5))
    tCliente.sexo = digita()
    io.write(rotulo(sreg, 6))
    tCliente.telefone = digita()
    tCliente.dtnascimento=
            validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true)
    mostrarSubDados([[opCliente]], [[opEndereco]], false)
    mostrarSubDados([[opCliente]], [[opPais]], false)
    mostrarSubDados([[opCliente]], [[opProfissao]], false)
  elseif nOpcao==3 then
    tCliente.cpf=trim(copy(slinha, 1, 14))
    tCliente.nome=trim(copy(slinha, 15, 30))
    tCliente.email=trim(copy(slinha, 45, 30))
    tCliente.identidade=trim(copy(slinha, 75, 10))
    tCliente.sexo=trim(copy(slinha, 85, 1))
    tCliente.telefone=trim(copy(slinha, 86, 17))
    tCliente.dtnascimento=trim(copy(slinha, 103, 10))
    tCliente.codendereco=trim(copy(slinha, 113, 10))
    tCliente.codpais=trim(copy(slinha, 123, 3))
    tCliente.codprofissao=trim(copy(slinha, 126, 10))
    print('--------------------')
    print(rotulo(sreg, 1)..tCliente.cpf)
    print(rotulo(sreg, 2)..tCliente.nome)
    print(rotulo(sreg, 3)..tCliente.email)
    print(rotulo(sreg, 4)..tCliente.identidade)
    print(rotulo(sreg, 5)..tCliente.sexo)
    print(rotulo(sreg, 6)..tCliente.telefone)
    print(rotulo(sreg, 7)..tCliente.dtnascimento)
    print(rotulo(sreg, 8)..tCliente.codendereco)
    mostrarSubDados([[opCliente]], [[opEndereco]], true)
    print(rotulo(sreg, 9)..tCliente.codpais)
    mostrarSubDados([[opCliente]], [[opPais]], true)
    print(rotulo(sreg, 10)..tCliente.codprofissao)
    mostrarSubDados([[opCliente]], [[opProfissao]], true)
  end
elseif sreg==[[opVenda]] then
  if nOpcao==1 then 
    mostrarSubDados([[opVenda]],[[opVenda]], false)
  elseif nOpcao==2 then
    print('DataHoraVenda       CPF            ISBN          '..
    'PreçoVenda')
    print('-------------       ---            ----          '..
    '----------')
  elseif nOpcao==3 then
    tVenda.dthrvenda=copy(slinha, 1, 19)
    tVenda.cpf=copy(slinha, 20, 14)
    tVenda.isbn=copy(slinha, 34, 13)
    tVenda.precovenda=copy(slinha, 47, 10)
    print(tVenda.dthrvenda..' '..tVenda.cpf..' '..tVenda.isbn..' '..
    tVenda.precovenda)
  end
end

end

-------------------------------------------------------------------------------
-- Mostra as sub informções de entrada e de saída.
-- sreg - o tipo de arquivo
-- ssubreg - o subtipo de arquivo
-- bSoMostrar - se vai só mostrar na saída 
-------------------------------------------------------------------------------
function mostrarSubDados(sreg, ssubreg, bSoMostrar)
nMaxTentativas=3
if sreg==[[opLivro]] then
  if ssubreg==[[opEditora]] then
    if bSoMostrar then
       sRegistro=pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg([[opEditora]]))
    else
       sRegistro=validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,false,[[opNumero]])
    end
    if sRegistro~='' then
      tLivro.codeditora=trim(copy(sRegistro,1,10))
      io.write(' '..rotulo([[opEditora]], 2))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
    end
  elseif ssubreg==[[opIdioma]] then 
    if bSoMostrar then
       sRegistro=pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg([[opIdioma]]))
    else
       sRegistro=validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,false,[[opNumero]])
    end
    if sRegistro~='' then 
      tLivro.codidioma=trim(copy(sRegistro,1,10))
      io.write(' '..rotulo([[opIdioma]], 2))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
    end
  end
elseif sreg==[[opCliente]] then 
  if ssubreg==[[opEndereco]]  then 
    if bSoMostrar then
       sRegistro=pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
                  tamReg([[opEndereco]]))
    else
       sRegistro=validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,false,[[opNumero]])
    end
    if sRegistro~='' then 
      tCliente.codendereco=trim(copy(sRegistro,1,10))
      io.write(' '..rotulo([[opEndereco]], 2))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
      io.write(' '..rotulo([[opEndereco]], 3))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
      io.write(' '..rotulo([[opEndereco]], 4))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
      io.write(' '..rotulo([[opEndereco]], 5))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
      io.write(' '..rotulo([[opEndereco]], 6))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
    end
  elseif ssubreg==[[opPais]] then 
    if bSoMostrar then
       sRegistro=pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg([[opPais]]))
    else
       sRegistro=validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,false,[[opTexto]])
    end
    if sRegistro~='' then 
      tCliente.codpais=trim(copy(sRegistro,1,3))
      io.write(' '..rotulo([[opPais]], 2))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
    end
  elseif ssubreg==[[opProfissao]] then 
    if bSoMostrar then
       sRegistro=pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
                  tamReg([[opProfissao]]))
    else
       sRegistro=validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,false,[[opNumero]])
    end
    if sRegistro~='' then 
      tCliente.codprofissao=trim(copy(sRegistro,1,10))
      io.write(' '..rotulo([[opProfissao]], 2))
      print(copy(sRegistro, g_nPosChave, g_nTamChave))
    end
  end
elseif sreg==[[opVenda]] then 
  sRegistro=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg([[opLivro]]))
  if sRegistro~='' then 
    io.write(' '..rotulo([[opLivro]], 2)) -- Titulo 
    print(copy(sRegistro, g_nPosChave, g_nTamChave))
    io.write(' '..rotulo([[opLivro]], 9)) -- Preco 
    sPreco=copy(sRegistro, g_nPosChave, g_nTamChave)
    g_nPreco = tonumber(sPreco)
    print(sPreco)
  end
end
end
-------------------------------------------------------------------------------
-- Realiza os cadastros dos arquivos que se ligam a outros arquivos.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- sCodigo - um das chaves do arquivo de ligação
-------------------------------------------------------------------------------
function frmCadLigados(sreg, sacao, sCodigo)
if sacao==[[opNovo]] then 
  nCont=1
  if sreg==[[opLivroAss]] then 
    sQtd=validaNumero('Quantos assuntos quer cadastrar?: ', sQtd)
    nQtd = tonumber(sQtd)
    tfLivroAss:seek('set')
    while nCont <= nQtd do 
      tLivroAss.isbn=sCodigo
      io.write(rotulo([[opLivroAss]], 2))
      tLivroAss.codassunto = digita()
      slinha=pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg([[opAssunto]]))
      io.write(' '..rotulo([[opAssunto]], 2))
      print(copy(slinha, g_nPosChave, g_nTamChave))
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg))
      subMenu(14, sreg)
      nCont=nCont+1
    end
  elseif sreg==[[opLivroAut]] then 
    sQtd=validaNumero('Quantos autores quer cadastrar?: ',sQtd)
    nQtd = tonumber(sQtd)
    tfLivroAut:seek('set')
    while nCont <= nQtd do 
      tLivroAut.isbn=sCodigo
      io.write(rotulo([[opLivroAut]], 2))
      tLivroAut.codautor = digita()
      slinha=pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg([[opAutor]]))
      io.write(' '..rotulo([[opAutor]], 2))
      print(copy(slinha, g_nPosChave, g_nTamChave))
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg))
      subMenu(14, sreg)
      nCont=nCont+1
    end
  elseif sreg==[[opVenda]] then 
    sQtd=validaNumero('Quantos livros quer vender?: ',sQtd)
    nQtd=tonumber(sQtd)
    nTotalPreco=0
    while nCont <= nQtd do 
      slinha=validaEntrada(tfLivro,[[opLivro]],1,tVenda.isbn,3,false,[[opTexto]])
      if slinha~='' then 
        tVenda.isbn=trim(copy(slinha,1,13))
        if validaISBN(tVenda.isbn) then 
          mostrarDados(sreg, '', 1)
          tLivro.qtdestoque=trim(copy(slinha,134,10))
          nQtdEstoque = tonumber(tLivro.qtdestoque)
          if nQtdEstoque > 0 then 
             nTotalPreco=nTotalPreco + g_nPreco
             sPreco=tostring(g_nPreco)
             tVenda.precovenda=sPreco
             g_SalvarInclusao=false
             subMenu(14, sreg)
             if g_SalvarInclusao then 
                slinha=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg([[opLivro]]))
                if slinha~='' then 
                   nQtdEstoque=nQtdEstoque-1
                   tLivro.qtdestoque=tostring(nQtdEstoque)
                   slinha=copy(slinha,1,133)..esp(tLivro.qtdestoque,10)
                   escreveArq(tfLivro, slinha, '', '')
                end
             end
             nCont=nCont+1
          else print(MSG_SEMESTOQUE) end
        else print(MSG_ISBNINV) end
      end
    end
    sTotalPreco = tostring(nTotalPreco)
    print('Total de '..rotulo(sreg,4)..sTotalPreco)
  end
elseif sacao==[[opExcluir]] then 
  if sreg==[[opLivroAss]] then 
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo)
  elseif sreg==[[opLivroAut]] then 
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo)
  end
end

end

-------------------------------------------------------------------------------
-- Realiza a exclusão dos arquivos de ligação.
-- sArq - o arquivo de ligação
-- sreg - o tipo de arquivo de ligação
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- sChave - a chave a ser excluida
-------------------------------------------------------------------------------
function ExcluirRegLigados(sArq, sreg, nPosChave, nTamChave, sChave)
  sArq:seek('set')
  for slinha in sArq:lines() do
    sCodigo=trim(copy(slinha,nPosChave,nTamChave))
    if sCodigo==sChave then
       btnAcao(sreg,[[opConfirmaExclusao]])
    end
  end
end

------------------------------------------------------------------------------
-- Parte inicial do código
------------------------------------------------------------------------------
do
-- if ParamStr(1)='-cria' then
--   abrecriaArqs(false)
-- else 
   frmSplash()
   abrecriaArqs(true)
   if frmLogin() then
     bopcao=true
     while(bopcao) do
       menu(1)
       opmenu = digita()
       if (opmenu=='C') or (opmenu=='c') then usaMenu(1)
       elseif (opmenu=='P') or (opmenu=='p') then usaMenu(2)
       elseif (opmenu=='V') or (opmenu=='v') then usaMenu(3)
       elseif (opmenu=='O') or (opmenu=='o') then usaMenu(4)
       else print(MSG_ERRO) end
     end
   else 
     fechaArqs()
     os.exit(0)
   end
-- end 
end
