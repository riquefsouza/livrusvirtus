#!/usr/local/bin/ruby
#------------------------------------------------------------------------------
# Sistema integrante do projeto Livrus Virtus.
# Todos os direitos reservados para Henrique F. de Souza.
# Versão programada na linguagem Ruby.
#------------------------------------------------------------------------------
#  programa Livrus

# tipos
regAssunto = { "codigo"=>"", "assunto"=>"" }
regAutor = { "codigo"=>"", "autor"=>"" }
regEditora = { "codigo"=>"", "editora"=>"" }
regIdioma = { "codigo"=>"", "idioma"=>"" }
regUsuario = { "login"=>"", "senha"=>"" }
regPais = { "codigo"=>"", "pais"=>"" }
regProfissao = { "codigo"=>"", "profissao"=>"" }
regLivro = { "isbn"=>"", "titulo"=>"", "edicao"=>"", "anopubli"=>"", 
             "codeditora"=>"", "volume"=>"", "codidioma"=>"",
             "npaginas"=>"", "preco"=>"", "qtdestoque"=>"" }
regLivroAss = { "isbn"=>"", "codassunto"=>"" }
regLivroAut = { "isbn"=>"", "codautor"=>"" }
regCliente = { "cpf"=>"", "nome"=>"", "email"=>"", "identidade"=>"",
               "sexo"=>"", "telefone"=>"", "dtnascimento"=>"",
               "codendereco"=>"", "codpais"=>"", "codprofissao"=>"" }
regEndereco = { "codigo"=>"", "logradouro"=>"", "bairro"=>"", "cep"=>"",
                "cidade"=>"", "estado"=>"" }
regVenda = { "dthrvenda"=>"", # data/hora da venda dd/mm/yyyy hh:mm:ss
             "cpf"=>"", "isbn"=>"", "precovenda"=>"" }

# Constantes

# ctTipo 
OPTEXTO, OPNUMERO, OPDATA, OPDATAHORA, OPSENHA = 1, 2, 3, 4, 5

# ctArqs
OPASSUNTO, OPAUTOR, OPEDITORA, OPENDERECO, OPIDIOMA, OPPAIS,
OPPROFISSAO, OPCLIENTE, OPLIVRO, OPLIVROASS, OPLIVROAUT,
OPUSUARIO, OPVENDA = 1, 2, 3, 4, 5, 6 , 7, 8, 9, 10, 11, 12, 13

# ctAcao
OPNOVO, OPALTERAR, OPPESQUISAR, OPSALVARINCLUSAO, OPSALVARALTERACAO, 
OPEXCLUIR, OPCONFIRMAEXCLUSAO, OPLISTARTODOS = 1, 2, 3, 4, 5, 6 , 7, 8

CRLF = "\r\n" # windows
TAM_CRLF = 2
# CRLF = "\n"
# TAM_CRLF = 1 # unix
# CRLF = "\r"
# TAM_CRLF = 1 # macintosh

QTD_MAX_LINHA = 18
TAM_MAX_STR = 255
TAM_MAX_REG = 145

MSG_ARQERRO = "Erro: O arquivo não pode ser aberto.\n"
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

ARQ_ASSUNTO = "assunto.dat"
ARQ_AUTOR = "autor.dat"
ARQ_EDITORA = "editora.dat"
ARQ_IDIOMA = "idioma.dat"
ARQ_USUARIO = "usuario.dat"
ARQ_PAIS = "pais.dat"
ARQ_PROFISSAO = "profissao.dat"
ARQ_LIVRO = "livro.dat"
ARQ_LIVASS = "livroass.dat"
ARQ_LIVAUT = "livroaut.dat"
ARQ_CLIENTE = "cliente.dat"
ARQ_ENDERECO = "endereco.dat"
ARQ_VENDA = "venda.dat"

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

TAssunto = regAssunto
TAutor = regAutor
TEditora = regEditora
TIdioma = regIdioma
TEndereco = regEndereco
TPais = regPais
TProfissao = regProfissao
TLivro = regLivro
TLivroAss = regLivroAss
TLivroAut = regLivroAut
TCliente = regCliente
TUsuario = regUsuario
TVenda = regVenda

# variaveis gerais
$bopcao = false
$opmenu = "0"
$g_nPosChave, $g_nTamChave = 0, 0
$g_nPreco = 0.0
$g_SalvarInclusao = false

$tfAssunto 
$tfAutor
$tfEditora
$tfIdioma
$tfEndereco
$tfPais
$tfProfissao
$tfLivro
$tfLivroAss
$tfLivroAut
$tfCliente
$tfUsuario
$tfVenda

#--- Rotinas básicas ---------------------------------------------------------

#------------------------------------------------------------------------------
# Função de leitura que retorna a string sem o retorno de carro.
# retorna - a string digitada
# ------------------------------------------------------------------------------
def digita()
  sret = $stdin.gets
  sret.chop!
  return sret
end

#------------------------------------------------------------------------------
# Função que retorna um pedaço de uma string.
# str - indica a string
# ini - indica a posicao inicial do pedaco
# tam - indica o tamanho do pedaco
# retorna - o pedaço da string
# ------------------------------------------------------------------------------
def copy(str,nini,ntam)
  return str.slice(nini-1,ntam)
end
#------------------------------------------------------------------------------
# Repete um texto um número determinado de vezes.
# sTexto - o texto a ser repetido
# nQtd - a quantidade de vezes
# retorna - o texto repetido
#------------------------------------------------------------------------------
def repete(sTexto, nQtd)
  return sTexto * nQtd
end
#------------------------------------------------------------------------------
# Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
# sTexto - o texto
# nTam - tamanho máximo do texto
# retorna - o texto com espaços em branco a mais
#------------------------------------------------------------------------------
def esp(sTexto, nTam)
  return sTexto.ljust(nTam)
end
#------------------------------------------------------------------------------
# Faz uma pesquisa relativa de um texto através de um valor chave.
# sTexto - o texto
# sChave - a chave a ser pesquisada
# retorna - se achou ou não a chave dentro do texto
#------------------------------------------------------------------------------
def strRelativa(sTexto, sChave)
  return sTexto.include?(sChave)
end
#------------------------------------------------------------------------------
# Calcula o modulo11 de um valor qualquer.
# svalor - a mstring com o número a ser calculado
# ndig - dígito do valor a ser calculado
# retorna - o dígito correto
#------------------------------------------------------------------------------
def modulo11(svalor, ndig)
ncont, nsoma, npos, nvalor = 0,0,0,0
sres, slocal = "", ""

  ncont=1
  while ncont <= 11 do
   slocal=copy(svalor,ncont,1) + slocal
   ncont=ncont+1
  end
  nsoma=0
  if ndig == 1 then
    ncont=3
  else
    ncont=2
  end
  npos=2
  while ncont <= 11 do
    sres=copy(slocal,ncont,1)
    nvalor = sres.to_i
    nsoma=nsoma + (nvalor * npos)
    ncont=ncont+1
    npos=npos+1
  end
  nsoma=(11 - (nsoma % 11))
  
  if nsoma > 9
    return 0
  else
    return nsoma
  end
end
#------------------------------------------------------------------------------
# Validação de um número de CPF qualquer.
# cpf - a mstring com o número do CPF
# retorna - se é valido ou não
#------------------------------------------------------------------------------
def validaCPF(cpf)
scpf, sres = "", ""
nvalor1, nvalor2 = 0,0
  
  if cpf.length==14 then
    scpf=copy(cpf,1,3)+copy(cpf,5,3)+copy(cpf,9,3)+copy(cpf,13,2)
    sres=copy(cpf,13,1)
    nvalor1 = sres.to_i
    sres=copy(cpf,14,1)
    nvalor2 = sres.to_i
    if (modulo11(scpf,1)==nvalor1) and (modulo11(scpf,2)==nvalor2)
      return true
    else
      return false
    end
  else
    return false
  end
end
#------------------------------------------------------------------------------
# Validação de um número ISBN qualquer.
# isbn - a mstring com o número do ISBN
# retorna - se é valido ou não
#------------------------------------------------------------------------------
def validaISBN(isbn)
snum, sdigito, sisbn = "", "", ""
ncont, nsoma, nvalor = 0,0,0

  if isbn.length==13 then
    sdigito=copy(isbn, isbn.length, 1)
    sisbn = ""
    for ncont in (1..isbn.length-1) do
      if copy(isbn,ncont,1)!="-" then
        sisbn=sisbn+copy(isbn,ncont,1)
      end
    end
    if sdigito == "X" then
      nsoma = 10
    else
      nvalor = sdigito.to_i
      nsoma = nvalor
    end
    for ncont in (1..9) do
      snum=copy(sisbn, ncont, 1)
      nvalor = snum.to_i
      nsoma=nsoma + (nvalor * (11 - ncont))
    end
    if (nsoma % 11) == 0
      return true
    else
      return false
    end
  else
    return false
  end
end
#------------------------------------------------------------------------------
# Esconde a digitação da senha
# retorna - a senha digitada
#------------------------------------------------------------------------------}
def digitaSenha(sRotulo, nTamSenha)
  print sRotulo
  sSenha = digita()
  #  ncont = 0
  #  sSenha=""
  #  sLetra="\0"
  #  while (sLetra!="\r") and (ncont < nTamSenha) do
  #    sLetra=readkey
  #    sSenha=sSenha+sLetra
  #    ncont++
  #  end
  return sSenha
end
#------------------------------------------------------------------------------
# Validação de um número qualquer.
# sRotulo - o texto antes de se digitar o número
# sNumero - a mstring com o valor do número
# retorna - o sNumero
#------------------------------------------------------------------------------
def validaNumero(sRotulo, sNumero)
nnum = 0.0
nStatus=-1
while (nStatus!=0) do
  print sRotulo
  sNumero = digita()
  nnum = sNumero.to_f
  if nnum < 0.01 then
     print(MSG_NUMINV)
  else
     nStatus=0
  end
end
return sNumero
end
#------------------------------------------------------------------------------
# Validação de uma data ou data/hora qualquer.
# sRotulo - o texto antes de se digitar a data/hora
# sDataHora - a mstring com o valor da data/hora
# bSoData - indica se vai validar somente uma data sem a hora
# retorna - a sDataHora
#------------------------------------------------------------------------------
def validaDataHora(sRotulo, sDataHora, bSoData)
sdia, smes, sano, shora, smin, sseg = "","","","","",""
ndia, nmes, nano, nhora, nmin, nseg, ntam = 0,0,0,0,0,0,0 

bvalida=false
bdatavalida=false
bhoravalida=false
nudiames=0

if bSoData==true then ntam=10
else ntam=19
end
while (bvalida==false) do
  print sRotulo
  sDataHora = digita()
  if sDataHora.length==ntam then
    sdia=copy(sDataHora,1,2)
    ndia=sdia.to_i
    smes=copy(sDataHora,4,2)
    nmes=smes.to_i
    sano=copy(sDataHora,7,4)
    nano=sano.to_i
  
    if (nano >= 1) and (nano <= 9999) then
      if (nmes >= 1) and (nmes <= 31) then
          case nmes
            when 1, 3, 5, 7, 8, 10, 12
              nudiames=31
            when 2
               # ano bissexto
               if (nano % 4)==0 then 
                 nudiames=29
               else 
                 nudiames=28
               end
             when 4, 6, 9, 11
               nudiames=30
          end
          if (ndia >=1) and (ndia <=nudiames) then
             bdatavalida=true
          end 
      end
    end
  
    if bSoData then
       if bdatavalida then 
         bvalida=true
       else 
         print(MSG_DATAINV)
       end 
    else
      if bdatavalida then
          shora=copy(sDataHora,12,2)
          nhora = shora.to_i
          smin=copy(sDataHora,15,2)
          nmin = smin.to_i
          sseg=copy(sDataHora,18,2)
          nseg = sseg.to_i
  
          if (nhora >= 0) and (nhora <= 23) then
            if (nmin >= 0) and (nmin <= 59) then
              if (nseg >= 0) and (nseg <= 59) then
                 bhoravalida=true
              end
            end
          end
  
          if bhoravalida then 
             bvalida=true
          else 
             print(MSG_DTHRINV)
          end
      else
        print(MSG_DTHRINV)
      end
    end
  else
    if bSoData==true then 
       print(MSG_DATAINV)
    else 
       print(MSG_DTHRINV)
    end
  end
end
return sDataHora
end
#------------------------------------------------------------------------------
# Retorna a Data e a hora do sistema.
# retorna - a data e a hora
#------------------------------------------------------------------------------
def retDataHora()
  sTempo = Time.now 
  return sTempo.strftime("%d/%m/%Y %H:%M:%S")
end

#--- Rotinas de manipulação de arquivos --------------------------------------

#------------------------------------------------------------------------------
# Calcula o tamanho do arquivo.
# sArq - o arquivo
# retorna - o tamanho do arquivo
#------------------------------------------------------------------------------
def tamArq(sArq)
  return File.size(sArq.path)
end
#------------------------------------------------------------------------------
# Abre ou cria os arquivos do sistema.
# bAbre - condição para abrir ou criar os arquivos do sistema
#------------------------------------------------------------------------------
def abrecriaArqs(bAbre)
 if bAbre then
   begin
     $tfAssunto = File.open(ARQ_ASSUNTO, File::RDWR)
     $tfAutor = File.open(ARQ_AUTOR, File::RDWR)
     $tfEditora = File.open(ARQ_EDITORA, File::RDWR)
     $tfIdioma = File.open(ARQ_IDIOMA, File::RDWR)
     $tfEndereco = File.open(ARQ_ENDERECO, File::RDWR)
     $tfPais = File.open(ARQ_PAIS, File::RDWR)
     $tfProfissao = File.open(ARQ_PROFISSAO, File::RDWR)
     $tfLivro = File.open(ARQ_LIVRO, File::RDWR)
     $tfLivroAss = File.open(ARQ_LIVASS, File::RDWR)
     $tfLivroAut = File.open(ARQ_LIVAUT, File::RDWR)
     $tfCliente = File.open(ARQ_CLIENTE, File::RDWR)
     $tfUsuario = File.open(ARQ_USUARIO, File::RDWR)
     $tfVenda = File.open(ARQ_VENDA, File::RDWR)
   rescue
     print(MSG_ARQERRO)
     exit(0)
   end
 else
   $tfAssunto = File.new(ARQ_ASSUNTO, File::CREAT|File::TRUNC|File::RDWR )
   $tfAutor = File.new(ARQ_AUTOR, File::CREAT|File::TRUNC|File::RDWR )
   $tfEditora = File.new(ARQ_EDITORA, File::CREAT|File::TRUNC|File::RDWR )
   $tfIdioma = File.new(ARQ_IDIOMA, File::CREAT|File::TRUNC|File::RDWR )
   $tfEndereco = File.new(ARQ_ENDERECO, File::CREAT|File::TRUNC|File::RDWR )
   $tfPais = File.new(ARQ_PAIS, File::CREAT|File::TRUNC|File::RDWR )
   $tfProfissao = File.new(ARQ_PROFISSAO, File::CREAT|File::TRUNC|File::RDWR )
   $tfLivro = File.new(ARQ_LIVRO, File::CREAT|File::TRUNC|File::RDWR )
   $tfLivroAss = File.new(ARQ_LIVASS, File::CREAT|File::TRUNC|File::RDWR )
   $tfLivroAut = File.new(ARQ_LIVAUT, File::CREAT|File::TRUNC|File::RDWR )
   $tfCliente = File.new(ARQ_CLIENTE, File::CREAT|File::TRUNC|File::RDWR )
   $tfUsuario = File.new(ARQ_USUARIO, File::CREAT|File::TRUNC|File::RDWR )
   $tfVenda = File.new(ARQ_VENDA, File::CREAT|File::TRUNC|File::RDWR )
 end
end
#------------------------------------------------------------------------------
# Fecha todos os arquivos abertos.
#------------------------------------------------------------------------------
def fechaArqs()
  $tfAssunto.close
  $tfAutor.close
  $tfEditora.close
  $tfIdioma.close
  $tfEndereco.close
  $tfPais.close
  $tfProfissao.close
  $tfLivro.close
  $tfLivroAss.close
  $tfLivroAut.close
  $tfCliente.close
  $tfUsuario.close
  $tfVenda.close
end
#------------------------------------------------------------------------------
# Pesquisa um registro através de um valor chave num arquivo.
# sArq - o arquivo
# sChave - a chave a ser pesquisada
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o registro pesquisado
#------------------------------------------------------------------------------
def pesqArq(sArq, sChave, nPosChave, nTamChave, nTamLinha)
slinha, sres = ""
nPosicao = 0

  bQuebra=false
  sArq.seek(0, IO::SEEK_SET)
  while (not sArq.eof) and (bQuebra==false) do
#    slinha = sArq.read(nTamLinha + TAM_CRLF)
    slinha = sArq.readline
    sres=copy(slinha,nPosChave,nTamChave).strip
    if sres==sChave then
       bQuebra=true
    end
  end
  nPosicao=sArq.pos-(nTamLinha + TAM_CRLF)
  if nPosicao > 0 then
     sArq.seek(nPosicao, IO::SEEK_SET)
  else
     sArq.seek(0, IO::SEEK_SET)
  end
  if sres!=sChave then
     return ""
  else
     return copy(slinha,1,nTamLinha)
  end
end
#------------------------------------------------------------------------------
# Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
# sArq - o arquivo
# nTamLinha - o tamanho do registro
#------------------------------------------------------------------------------
def pesqLinhaExcluida(sArq, nTamLinha)
sExcluido = ""

  sExcluido=pesqArq(sArq, "*", 1, 1, nTamLinha)
  if sExcluido=="" then
     sArq.seek(tamArq(sArq), IO::SEEK_SET)
  end
end
#------------------------------------------------------------------------------
# Pesquisa o maior código num arquivo.
# sArq - o arquivo
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o maior código
#------------------------------------------------------------------------------
def pesqMaxCod(sArq, nPosChave, nTamChave, nTamLinha)
slinha, sres = "", ""
nCod = 0
bQuebra=false
nMaior=0
sArq.seek(0, IO::SEEK_SET)
while (not sArq.eof) and (bQuebra==false) do
#  slinha = sArq.read(nTamLinha + TAM_CRLF)
  slinha = sArq.readline
  sres=copy(slinha,nPosChave,nTamChave).strip
  nCod=sres.to_i
  if nCod > nMaior then
     nMaior=nCod
  end
end
pesqLinhaExcluida(sArq, nTamLinha)
sres = (nMaior+1).to_s
return sres
end
#------------------------------------------------------------------------------
# Grava os registros num determinado arquivo.
# sArq - o arquivo
# sTexto - o registro a ser gravado
# sMsgAcerto - a mensagem caso o registro foi gravado
# sMsgErro - a mensagem caso o registro não foi gravado
#------------------------------------------------------------------------------
def escreveArq(sArq, sTexto, sMsgAcerto, sMsgErro)
nStatus = 0
  begin
    sTexto=sTexto+CRLF
    nStatus = sArq.write(sTexto)
    if nStatus == sTexto.length
      print(sMsgAcerto,"\n")
    else
      print(sMsgErro,"\n")
    end 
  rescue
    print(sMsgErro,"\n")
  end
end

#--- Rotinas de implementação do sistema e de interface ----------------------

#------------------------------------------------------------------------------
# Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o registro montado
#------------------------------------------------------------------------------
def LinhaReg(sreg)
slinha=""
if sreg==OPASSUNTO then
   slinha=esp(TAssunto["codigo"],10)+esp(TAssunto["assunto"],30)
elsif sreg==OPAUTOR then
   slinha=esp(TAutor["codigo"],10)+esp(TAutor["autor"],30)
elsif sreg==OPEDITORA then
   slinha=esp(TEditora["codigo"],10)+esp(TEditora["editora"],50)
elsif sreg==OPENDERECO then
   slinha=esp(TEndereco["codigo"],10)+esp(TEndereco["logradouro"],40)+
   esp(TEndereco["bairro"],15)+esp(TEndereco["cep"],8)+esp(TEndereco["cidade"],30)+
   esp(TEndereco["estado"],20)
elsif sreg==OPIDIOMA then
   slinha=esp(TIdioma["codigo"],10)+esp(TIdioma["idioma"],20)
elsif sreg==OPPAIS then
   slinha=esp(TPais["codigo"],3)+esp(TPais["pais"],50)
elsif sreg==OPPROFISSAO then
   slinha=esp(TProfissao["codigo"],10)+esp(TProfissao["profissao"],50)
elsif sreg==OPUSUARIO then
   slinha=esp(TUsuario["login"],10)+esp(TUsuario["senha"],10)
elsif sreg==OPLIVRO then
   slinha=esp(TLivro["isbn"],13)+esp(TLivro["titulo"],50)+esp(TLivro["edicao"],10)+
   esp(TLivro["anopubli"],10)+esp(TLivro["codeditora"],10)+esp(TLivro["volume"],10)+
   esp(TLivro["codidioma"],10)+esp(TLivro["npaginas"],10)+esp(TLivro["preco"],10)+
   esp(TLivro["qtdestoque"],10)
elsif sreg==OPLIVROASS then
   slinha=esp(TLivroAss["isbn"],13)+esp(TLivroAss["codassunto"],10)
elsif sreg==OPLIVROAUT then
   slinha=esp(TLivroAut["isbn"],13)+esp(TLivroAut["codautor"],10)
elsif sreg==OPCLIENTE then
   slinha=esp(TCliente["cpf"],14)+esp(TCliente["nome"],30)+esp(TCliente["email"],30)+
   esp(TCliente["identidade"],10)+esp(TCliente["sexo"],1)+esp(TCliente["telefone"],17)+
   esp(TCliente["dtnascimento"],10)+esp(TCliente["codendereco"],10)+
   esp(TCliente["codpais"],3)+esp(TCliente["codprofissao"],10)
elsif sreg==OPVENDA then
   slinha=esp(TVenda["dthrvenda"],19)+esp(TVenda["cpf"],14)+esp(TVenda["isbn"],13)+
   esp(TVenda["precovenda"],10)
end
return slinha
end
#------------------------------------------------------------------------------
# Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o tamanho do registro
#------------------------------------------------------------------------------
def tamReg(sreg)
nret=0
  if sreg==OPASSUNTO then nret=TAM_ASSUNTO
  elsif sreg==OPAUTOR then nret=TAM_AUTOR
  elsif sreg==OPEDITORA then nret=TAM_EDITORA
  elsif sreg==OPENDERECO then nret=TAM_ENDERECO
  elsif sreg==OPIDIOMA then nret=TAM_IDIOMA
  elsif sreg==OPPAIS then nret=TAM_PAIS
  elsif sreg==OPPROFISSAO then nret=TAM_PROFISSAO
  elsif sreg==OPUSUARIO then nret=TAM_USUARIO
  elsif sreg==OPLIVRO then nret=TAM_LIVRO
  elsif sreg==OPLIVROASS then nret=TAM_LIVASS
  elsif sreg==OPLIVROAUT then nret=TAM_LIVAUT
  elsif sreg==OPCLIENTE then nret=TAM_CLIENTE
  elsif sreg==OPVENDA then nret=TAM_VENDA
  end
return nret
end
#------------------------------------------------------------------------------
# Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# nNum - indica qual rotulo será retornado
# retorna - o rotulo
#------------------------------------------------------------------------------
def rotulo(sreg, nNum)
sret=""
if sreg==OPASSUNTO then
   case nNum
     when 0 
       sret="Assunto(s) não encontrado(s)!"
     when 1
       sret="Código do assunto: "
       $g_nPosChave=1
       $g_nTamChave=10
     when 2
       sret="Assunto: "
       $g_nPosChave=11
       $g_nTamChave=30
   end
elsif sreg==OPAUTOR then
   case nNum
     when 0 
       sret="Autor(es) não encontrado(s)!"
     when 1
       sret="Código do autor: "
       $g_nPosChave=1
       $g_nTamChave=10
     when 2
       sret="Autor: "
       $g_nPosChave=11
       $g_nTamChave=30
   end
elsif sreg==OPEDITORA then
   case nNum
     when 0 
         sret="Editora(s) não encontrada(s)!"
     when 1
         sret="Código da editora: "
         $g_nPosChave=1
         $g_nTamChave=10
     when 2
         sret="Editora: "
         $g_nPosChave=11
         $g_nTamChave=50
   end
elsif sreg==OPENDERECO then
   case nNum
     when 0 
         sret="Endereço(s) não encontrado(s)!"
     when 1
         sret="Código do endereço: "
         $g_nPosChave=1
         $g_nTamChave=10
     when 2
         sret="Logradouro: "
         $g_nPosChave=11
         $g_nTamChave=40
     when 3
         sret="Bairro: "
         $g_nPosChave=51
         $g_nTamChave=15
     when 4
         sret="CEP: "
         $g_nPosChave=66
         $g_nTamChave=8
     when 5
         sret="Cidade: "
         $g_nPosChave=74
         $g_nTamChave=30
     when 6
         sret="Estado: "
         $g_nPosChave=104
         $g_nTamChave=20
   end
elsif sreg==OPIDIOMA then
   case nNum
     when 0 
         sret="Idioma(s) não encontrado(s)!"
     when 1
         sret="Código do idioma: "
         $g_nPosChave=1
         $g_nTamChave=10

     when 2
         sret="Idioma: "
         $g_nPosChave=11
         $g_nTamChave=20
   end
elsif sreg==OPPAIS then
   case nNum
     when 0 
         sret="País(es) não encontrado(s)!"
     when 1
         sret="Código do país: "
         $g_nPosChave=1
         $g_nTamChave=3
     when 2
         sret="País: "
         $g_nPosChave=4
         $g_nTamChave=50
   end
elsif sreg==OPPROFISSAO then
   case nNum
     when 0 
         sret="Profissão(es) não encontrada(s)!"
     when 1
         sret="Código da profissão: "
         $g_nPosChave=1
         $g_nTamChave=10
     when 2
         sret="Profissão: "
         $g_nPosChave=11
         $g_nTamChave=50
   end
elsif sreg==OPUSUARIO then
   case nNum
     when 0 
         sret="login ou senha incorreta, tente de novo!"
     when 1
         sret="Login: "
         $g_nPosChave=1
         $g_nTamChave=10
     when 2
         sret="Senha: "
         $g_nPosChave=11
         $g_nTamChave=10
   end
elsif sreg==OPLIVRO then
   case nNum
     when 0 
         sret="Livro(s) não encontrado(s)!"
     when 1
         sret="ISBN: "
         $g_nPosChave=1
         $g_nTamChave=13
     when 2
         sret="Título: "
         $g_nPosChave=14
         $g_nTamChave=50
     when 3
         sret="Edição: "
         $g_nPosChave=64
         $g_nTamChave=10
     when 4
         sret="Ano de Publicação: "
         $g_nPosChave=74
         $g_nTamChave=10
     when 5
         sret="Código da editora: "
         $g_nPosChave=84
         $g_nTamChave=10
     when 6
         sret="Volume: "
         $g_nPosChave=94
         $g_nTamChave=10
     when 7
         sret="Código do idioma: "
         $g_nPosChave=104
         $g_nTamChave=10
     when 8
         sret="Número de páginas: "
         $g_nPosChave=114
         $g_nTamChave=10
     when 9
         sret="Preço: "
         $g_nPosChave=124
         $g_nTamChave=10
     when 10
          sret="Qtd. Estoque: "
          $g_nPosChave=134
          $g_nTamChave=10
    end
elsif sreg==OPLIVROASS then
   case nNum
     when 0 
         sret="Assunto(s) não encontrado(s)!"
     when 1
         sret="ISBN: "
         $g_nPosChave=1
         $g_nTamChave=13
     when 2
         sret="Código do assunto: "
         $g_nPosChave=14
         $g_nTamChave=10
   end
elsif sreg==OPLIVROAUT then
   case nNum
     when 0 
         sret="Autor(s) não encontrado(s)!"
     when 1
         sret="ISBN: "
         $g_nPosChave=1
         $g_nTamChave=13
     when 2
         sret="Código do autor: "
         $g_nPosChave=14
         $g_nTamChave=10
   end
elsif sreg==OPCLIENTE then
   case nNum
     when 0 
         sret="Cliente(s) não encontrado(s)!"
     when 1
         sret="CPF: "
         $g_nPosChave=1
         $g_nTamChave=14
     when 2
         sret="Nome: "
         $g_nPosChave=15
         $g_nTamChave=30
     when 3
         sret="E-mail: "
         $g_nPosChave=45
         $g_nTamChave=30
     when 4
         sret="Identidade: "
         $g_nPosChave=75
         $g_nTamChave=10
     when 5
         sret="Sexo: "
         $g_nPosChave=85
         $g_nTamChave=1
     when 6
         sret="Telefone: "
         $g_nPosChave=86
         $g_nTamChave=17
     when 7
         sret="Dt. Nascimento: "
         $g_nPosChave=103
         $g_nTamChave=10
     when 8
         sret="Código do endereço: "
         $g_nPosChave=113
         $g_nTamChave=10
     when 9
         sret="Código do país: "
         $g_nPosChave=123
         $g_nTamChave=3
     when 10
          sret="Código da Profissão: "
          $g_nPosChave=126
          $g_nTamChave=10
   end
elsif sreg==OPVENDA then
   case nNum
     when 0 
         sret="Venda(s) não encontrada(s)!"
     when 1
         sret="Data/Hora venda: "
         $g_nPosChave=1
         $g_nTamChave=19
     when 2
         sret="CPF: "
         $g_nPosChave=20
         $g_nTamChave=14
     when 3
         sret="ISBN: "
         $g_nPosChave=34
         $g_nTamChave=13
     when 4
         sret="Pre+o de venda: "
         $g_nPosChave=47
         $g_nTamChave=10
   end
end

return sret
end
#------------------------------------------------------------------------------
# Indica se continua ou não mostrando um número máximo de linhas.
# nlinha - a linha a ser continuada
# nQtdLinha - a quantidade de linhas a serem mostradas
# retorna - se continua ou não
#------------------------------------------------------------------------------
def ContinuaSN(nlinha, nQtdLinha)
bSOp = false
opCSubMenu = "\0"
bret=false
if nlinha > 0 then
  if (nlinha % nQtdLinha) == 0 then
     bSOp=true
     while bSOp do
       menu(13)
       opCSubMenu = digita()
       if (opCSubMenu=="S") or (opCSubMenu=="s") then bSOp=false
       elsif (opCSubMenu=="N") or (opCSubMenu=="n") then
          bret=true
          bSOp=false
       else 
         print(MSG_ERRO)
       end
     end
  end
end

return bret
end
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
def ListarTodos(sArq, sreg, sChave, nPosChave, nTamChave, 
                nTamLinha, nQtdLinha, bPesqRelativa)
slinha, sres = "",""

bRet=false
bQuebra=false
nCont=0
mostrarDados(sreg, "", 2)
sArq.seek(0, IO::SEEK_SET)
while (not sArq.eof) and (bQuebra==false) do
  slinha = sArq.readline
  if bPesqRelativa then
    sres=copy(slinha,nPosChave,nTamChave).strip
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

  bQuebra=ContinuaSN(nCont, nQtdLinha)
end
return bRet
end
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
def ListarRegLigados(sArq1, sreg1, nPosChave1, nTamChave1, 
nPosChave2, nTamChave2, sChave, sArq2, sreg2, nPosChave3, nQtdLinha)
slinha1, sCodigo1, sCodigo2, slinha2 = "","","",""
bRet=false
nCont=0
bQuebra=false
mostrarDados(sreg2, "", 2)
sArq1.seek(0, IO::SEEK_SET)
while (not sArq1.eof) and (bQuebra==false) do
  slinha1 = sArq1.readline
  sCodigo1=copy(slinha1,nPosChave1,nTamChave1).strip
  if sCodigo1==sChave then
    sCodigo2=copy(slinha1,nPosChave2,nTamChave2).strip
    slinha2=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
    mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3)
    bRet=true
    nCont=nCont+1
  end
  bQuebra=ContinuaSN(nCont, nQtdLinha)
end
if bRet==false then
   print(rotulo(sreg2,0),"\n")
end
end
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
def validaEntrada(sArq, sreg, nTexto, sEntrada, nTentativas,
        bPesqRelativa, bTipoEntrada)
sres = ""
nTamLinha=tamReg(sreg)
sMsgErro=rotulo(sreg,0)
sTexto=rotulo(sreg,nTexto)
nPosChave=$g_nPosChave
nTamChave=$g_nTamChave

ncont=1
bQuebra=false
  while (bQuebra==false) and (ncont <= nTentativas ) do
    if  bTipoEntrada==OPTEXTO then
      print(sTexto)
      sEntrada = digita()
    elsif bTipoEntrada==OPNUMERO then
       sEntrada=validaNumero(sTexto,sEntrada)
    elsif bTipoEntrada==OPDATA then
       sEntrada=validaDataHora(sTexto,sEntrada,true)
    elsif bTipoEntrada==OPDATAHORA then
       sEntrada=validaDataHora(sTexto,sEntrada,false)
    elsif bTipoEntrada==OPSENHA then
       sEntrada=digitaSenha(sTexto, 10)
    end

    if bPesqRelativa then
       if ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha,
                      QTD_MAX_LINHA, true) then
          sres=" "
       end
    else
       sres=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)
    end
    if sres=="" then
       print(sMsgErro,"\n")
    else
       bQuebra=true
    end
    ncont=ncont+1
  end
return sres
end
#------------------------------------------------------------------------------
# Mostra a tela de splash do sistema.
#------------------------------------------------------------------------------
def frmSplash()
 print("*---------------------------------------"+
 "-------------------------------------*\n")
 print("| LL    II VV   VV RRRRR  UU  UU   SSSS "+
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |\n")
 print("| LL    II  VV VV  RR   R UU  UU  SS    "+
 " VV VV  II RR   R  TT  UU  UU  SS    |\n")
 print("| LL    II   VVV   RRRRR  UU  UU    SS  "+
 "  VVV   II RRRRR   TT  UU  UU    SS  |\n")
 print("| LLLLL II    V    RR   R  UUUU  SSSS   "+
 "   V    II RR   R  TT   UUUU  SSSS   |\n")
 print("*---------------------------------------"+
 "-------------------------------------*\n")
 for cont in (1..18) do 
   print("\n")
 end
 print(MSG_PRESS)
 $stdin.getc
end
#------------------------------------------------------------------------------
# Mostra a tela de sobre do sistema.
#------------------------------------------------------------------------------
def frmSobre()
 print("*------------------------------------------------------------*\n")
 print("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |\n")
 print("|  LL        II   VV     VV   RR     R  UU    UU  SS         |\n")
 print("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |\n")
 print("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |\n")
 print("|  LLLL      II      VVV      RR RR     UU    UU        SS   |\n")
 print("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |\n")
 print("|                                                            |\n")
 print("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |\n")
 print("|   VV     VV   II  RR     R     TT     UU    UU  SS         |\n")
 print("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |\n")
 print("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |\n")
 print("|      VVV      II  RR RR        TT     UU    UU        SS   |\n")
 print("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |\n")
 print("|                                                            |\n")
 print("|                                               Versao 1.0.0 |\n")
 print("| Sistema integrante do projeto Livrus Virtus.               |\n")
 print("| Todos os direitos reservados para Henrique F. de Souza.    |\n")
 print("| Versao programada na linguagem ruby.                       |\n")
 print("*------------------------------------------------------------*\n")
 for cont in (1..4) do 
   print("\n")
 end
 print(MSG_PRESS)
 $stdin.getc
end
#------------------------------------------------------------------------------
# Mostra a tela de login do sistema.
# retorna - se o login foi validado corretamente
#------------------------------------------------------------------------------
def frmLogin()
slinha = ""

  bret=false
  print("*--------------------------------------------------------------*\n")
  print("| Login do sistema                                             |\n")
  print("*--------------------------------------------------------------*\n")
  slinha=validaEntrada($tfUsuario, OPUSUARIO, 1, TUsuario["login"], 3,
        false, OPTEXTO)
  if slinha!="" then
     slinha=validaEntrada($tfUsuario, OPUSUARIO, 2, TUsuario["senha"], 3,
        false, OPSENHA)
     if slinha!="" then
        TUsuario["login"]=copy(slinha, 1, 10).strip
        TUsuario["senha"]=copy(slinha, 11, 10).strip
        bret=true
     end
  end
  print("\n")
  return bret
end
#------------------------------------------------------------------------------
# Mostra os menus do sistema.
# num - o número do menu
#------------------------------------------------------------------------------
def menu(num)
 if (num==1) then
   print("*--------------------------------------------------------------*\n")
   print("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==2) then
   print("*---------------------------------*\n")
   print("| 01. Cadastro de Assuntos        |\n")
   print("| 02. Cadastro de Autores         |\n")
   print("| 03. Cadastro de Editoras        |\n")
   print("| 04. Cadastro de Endereços       |\n")
   print("| 05. Cadastro de Idiomas         |\n")
   print("| 06. Cadastro de Países          |\n")
   print("| 07. Cadastro de Profissões      |\n")
   print("| 08. Cadastro de Clientes        |\n")
   print("| 09. Cadastro de Livros          |\n")
   print("| 10. Voltar ao menu              |\n")
   print("*---------------------------------*\n")
 elsif (num==3) then
   print("*---------------------------------*\n")
   print("| 01. Consulta de Assuntos        |\n")
   print("| 02. Consulta de Autores         |\n")
   print("| 03. Consulta de Editoras        |\n")
   print("| 04. Consulta de Endereços       |\n")
   print("| 05. Consulta de Idiomas         |\n")
   print("| 06. Consulta de Países          |\n")
   print("| 07. Consulta de Profissões      |\n")
   print("| 08. Consulta de Clientes        |\n")
   print("| 09. Consulta de Livros          |\n")
   print("| 10. Voltar ao menu              |\n")
   print("*---------------------------------*\n")
 elsif (num==4) then
   print("*---------------------------------*\n")
   print("| 01. Vender Livros               |\n")
   print("| 02. Vendas Realizadas           |\n")
   print("| 03. Voltar ao menu              |\n")
   print("*---------------------------------*\n")
 elsif (num==5) then
   print("*---------------------------------*\n")
   print("| 01. Alterar senha               |\n")
   print("| 02. Sobre o sistema             |\n")
   print("| 03. Sair do sistema             |\n")
   print("| 04. Voltar ao menu              |\n")
   print("*---------------------------------*\n")
 elsif (num==6) then
   print("*--------------------------------------------------------------*\n")
   print("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==7) then
   print("*--------------------------------------------------------------*\n")
   print("| (1) Salvar inclusão       (2) Voltar ao menu                 |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==8) then
   print("*--------------------------------------------------------------*\n")
   print("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==9) then
   print("*--------------------------------------------------------------*\n")
   print("| (1) Salvar alteração      (2) Voltar ao menu                 |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==10) then
   print("*--------------------------------------------------------------*\n")
   print("| Certeza de excluir? (S/N)                                    |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==11) then
   print("*--------------------------------------------------------------*\n")
   print("| Deseja sair do sistema? (S/N)                                |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==12) then
   print("*--------------------------------------------------------------*\n")
   print("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==13) then
   print("*--------------------------------------------------------------*\n")
   print("| Deseja continuar? (S/N)                                      |\n")
   print("*--------------------------------------------------------------*\n")
 elsif (num==14) then
   print("*--------------------------------------------------------------*\n")
   print("| Salvar inclusão (S/N)                                        |\n")
   print("*--------------------------------------------------------------*\n")
 end
 print(MSG_OPCAO)
end
#------------------------------------------------------------------------------
# Realiza os cadastros de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
def frmCadastros(sreg, sacao)
slinha = ""
if sreg==OPASSUNTO then
   if sacao==OPNOVO then
      TAssunto["codigo"]=pesqMaxCod($tfAssunto, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elsif sacao==OPPESQUISAR then
     slinha=validaEntrada($tfAssunto,sreg,1,TAssunto["codigo"],1,false,OPNUMERO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPAUTOR then
   if sacao==opNovo then
      TAutor["codigo"]=pesqMaxCod($tfAutor, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfAutor, sreg, 1, TAutor["codigo"],1,false,OPNUMERO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPEDITORA then
   if sacao==OPNOVO then
      TEditora["codigo"]=pesqMaxCod($tfEditora, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elsif sacao==OPPESQUISAR then
     slinha=validaEntrada($tfEditora,sreg,1,TEditora["codigo"],1,false,OPNUMERO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPENDERECO then
   if sacao==OPNOVO then
      TEndereco["codigo"]=pesqMaxCod($tfEndereco, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfEndereco,sreg,1,TEndereco["codigo"],1,
              false,OPNUMERO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPIDIOMA then
   if sacao==OPNOVO then
      TIdioma["codigo"]=pesqMaxCod($tfIdioma, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfIdioma,sreg,1,TIdioma["codigo"],1,false,OPNUMERO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPPAIS then
   if sacao==OPNOVO then
      print(rotulo(sreg, 1))
      TPais["codigo"] = digita()
      slinha=pesqArq($tfPais, TPais["codigo"], 1, 3, tamReg(sreg))
      if slinha=="" then
         pesqLinhaExcluida($tfPais, tamReg(sreg))
         mostrarDados(sreg, "", 1)
         subMenu(7, sreg)
      else 
         print(MSG_REGEXST)
      end
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfPais, sreg, 1, TPais["codigo"], 1, false, OPTEXTO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==opAlterar then
      print(rotulo(sreg, 1), TPais["codigo"], "\n")
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==opExcluir then
      subMenu(10, sreg)
   end
elsif sreg==OPPROFISSAO then
   if sacao==OPNOVO then
      TProfissao["codigo"]=pesqMaxCod($tfProfissao, 1, 10, tamReg(sreg))
      mostrarDados(sreg, "", 1)
      subMenu(7, sreg)
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfProfissao,sreg,1,TProfissao["codigo"],1,
              false,OPNUMERO)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPLIVRO then
   if sacao==OPNOVO then
      print(rotulo(sreg, 1))
      TLivro["isbn"] = digita()
      if validaISBN(TLivro["isbn"]) then
          slinha=pesqArq($tfLivro, TLivro["isbn"], 1, 13, tamReg(sreg))
          if slinha=="" then
             pesqLinhaExcluida($tfLivro, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu(7, sreg)
             frmCadLigados(OPLIVROASS, OPNOVO, TLivro["isbn"])
             frmCadLigados(OPLIVROAUT, OPNOVO, TLivro["isbn"])
          else 
            print(MSG_REGEXST)
          end
      else 
        print(MSG_ISBNINV)
      end
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfLivro, sreg, 1, TLivro["isbn"], 1,false,OPTEXTO)
      if slinha!="" then
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      print(rotulo(sreg, 1), TLivro["isbn"], "\n")
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
      frmCadLigados(OPLIVROASS, OPEXCLUIR, TLivro["isbn"])
      print("Assuntos dos livros excluídos, inclua novos!\n")
      frmCadLigados(OPLIVROASS, OPNOVO, TLivro["isbn"])
      frmCadLigados(OPLIVROAUT, OPEXCLUIR, TLivro["isbn"])
      print("Autores dos livros excluídos, inclua novos!\n")
      frmCadLigados(OPLIVROAUT, OPNOVO, TLivro["isbn"])
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
      print("Assuntos dos livros sendo excluídos!\n")
      frmCadLigados(OPLIVROASS, OPEXCLUIR, TLivro["isbn"])
      print("Autores dos livros sendo excluídos!\n")
      frmCadLigados(OPLIVROAUT, OPEXCLUIR, TLivro["isbn"])
   end
elsif sreg==OPCLIENTE then
   if sacao==OPNOVO then
      print(rotulo(sreg, 1))
      TCliente["cpf"] = digita()
      if validaCPF(TCliente["cpf"]) then
          slinha=pesqArq($tfCliente, TCliente["cpf"], 1, 14, tamReg(sreg))
          if slinha=="" then
             pesqLinhaExcluida($tfCliente, tamReg(sreg))
             mostrarDados(sreg, "", 1)
             subMenu(7, sreg)
          else 
            print(MSG_REGEXST)
          end
      else 
        print(MSG_CPFINV)
      end
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfCliente, sreg, 1, TCliente["cpf"],1,false,OPTEXTO)
      if slinha!="" then
         mostrarDados(sreg, "", 2)
         mostrarDados(sreg, slinha, 3)
         subMenu(8, sreg)
      end
   elsif sacao==OPALTERAR then
      print(rotulo(sreg, 1), TCliente["cpf"], "\n")
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elsif sacao==OPEXCLUIR then
      subMenu(10, sreg)
   end
elsif sreg==OPVENDA then
   if sacao==OPNOVO then
      TVenda["dthrvenda"] = retDataHora()
      print(rotulo(sreg, 1), TVenda["dthrvenda"], "\n")
      slinha=pesqArq($tfVenda, TVenda["dthrvenda"], 1, 19, tamReg(sreg))
      if slinha=="" then
         slinha=validaEntrada($tfCliente,OPCLIENTE,1,TVenda["cpf"],3,
                 false,OPTEXTO)
         if slinha!="" then
            TVenda["cpf"]=copy(slinha,1,14).strip
            if validaCPF(TVenda["cpf"]) then
               print(" ",rotulo(OPCLIENTE, 2)) # Nome
               print(copy(slinha, $g_nPosChave, $g_nTamChave),"\n")
               frmCadLigados(OPVENDA, OPNOVO, TVenda["cpf"])
            else 
              print(MSG_CPFINV)
            end
         end
      else 
        print(MSG_REGEXST)
      end
   elsif sacao==OPPESQUISAR then
      slinha=validaEntrada($tfVenda, sreg, 1, TVenda["dthrvenda"],1,
              false,OPDATAHORA)
      if slinha!="" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end
   end
end

end
#------------------------------------------------------------------------------
# Realiza as consultas de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
def frmConsultas(sreg, sacao)
slinha = ""

if sreg==OPASSUNTO then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfAssunto,sreg,2,TAssunto["assunto"],1,true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfAssunto, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPAUTOR then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfAutor,sreg, 2, TAutor["autor"], 1, true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfAutor, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPEDITORA then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfEditora,sreg,2,TEditora["editora"],1,true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfEditora, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPENDERECO then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfEndereco,sreg,2,TEndereco["logradouro"],1,
              true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfEndereco, sreg, "", 0, 0, tamReg(sreg),
         3, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPIDIOMA then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfIdioma, sreg, 2, TIdioma["idioma"],1,true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfIdioma, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPPAIS then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfPais, sreg, 2, TPais["pais"], 1, true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfPais, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPPROFISSAO then
   if sacao==OPPESQUISAR then
     slinha=validaEntrada($tfProfissao,sreg,2,TProfissao["profissao"],1,
             true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfProfissao, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPLIVRO then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfLivro, sreg, 2, TLivro["titulo"], 1, true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfLivro, sreg, "", 0, 0, tamReg(sreg),
        1, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPCLIENTE then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfCliente, sreg, 2, TCliente["nome"],1,true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfCliente, sreg, "", 0, 0, tamReg(sreg),
        1, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
elsif sreg==OPVENDA then
   if sacao==OPPESQUISAR then
      slinha=validaEntrada($tfVenda, sreg, 2, TVenda["cpf"], 1, true,OPTEXTO)
   elsif sacao==OPLISTARTODOS then
      if ListarTodos($tfVenda, sreg, "", 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) == false then
        print(rotulo(sreg, 0),"\n")
      end
   end
end
if slinha=="" then
   print("")
end
end
#------------------------------------------------------------------------------
# Mostra a tela de alteração de senha do sistema e realiza a alteração.
#------------------------------------------------------------------------------
def frmAlterarSenha()
sres, sSenhaAtual, sNovaSenha, sConfirmaSenha = "","","",""

print(rotulo(OPUSUARIO, 1), TUsuario["login"])
nopcao=1
bQuebra=false
while (bQuebra==false) do
  case nopcao
   when 1
       sSenhaAtual=digitaSenha("Senha Atual: ",10)
       if sSenhaAtual!=TUsuario["senha"] then
          print(MSG_SENCONFERE)
          bQuebra=true
       else nopcao=2
       end
   when 2
       sNovaSenha=digitaSenha("Nova Senha: ",10)
       sConfirmaSenha=digitaSenha("Confirma Senha: ",10)
       if sNovaSenha!=sConfirmaSenha then
          print(MSG_SENCONFIRM)
          bQuebra=true
       else nopcao=3
       end
   when 3
       sres=pesqArq($tfUsuario, TUsuario["login"], 1, 10, tamReg(OPUSUARIO))
       if sres=="" then
         print(MSG_LOGINENCON)
       else
         TUsuario["senha"]=sConfirmaSenha
         subMenu(9,OPUSUARIO)
         bQuebra=true
       end
  end
end

end
#------------------------------------------------------------------------------
# Executa uma ação de gravação de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
def btnAcao(sreg, sacao)

if sreg==OPASSUNTO then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPAUTOR then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPEDITORA then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPENDERECO then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPIDIOMA then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPPAIS then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPPROFISSAO then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPLIVRO then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPLIVROASS then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPLIVROAUT then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPCLIENTE then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPVENDA then
   if sacao==OPSALVARINCLUSAO then
      escreveArq($tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elsif sacao==OPSALVARALTERACAO then
      escreveArq($tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elsif sacao==OPCONFIRMAEXCLUSAO then
      escreveArq($tfVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end
elsif sreg==OPUSUARIO then
   if sacao==OPSALVARALTERACAO then
      escreveArq($tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   end
end
end
#------------------------------------------------------------------------------
# Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
# nmenu - o número do menu
# sreg - o tipo de arquivo
#------------------------------------------------------------------------------
def subMenu(nmenu, sreg)
opSubMenu = 0
opCSubMenu = ""
bSOp=true
case nmenu
 when 6
   while bSOp do
     menu(nmenu)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         frmCadastros(sreg, OPNOVO)
       when 2 
         frmCadastros(sreg, OPPESQUISAR)
       when 3 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 when 7
   while bSOp do
     menu(nmenu)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         btnAcao(sreg, OPSALVARINCLUSAO) 
         bSOp=false
       when 2 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 when 8
   while bSOp do
     menu(nmenu)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         frmCadastros(sreg, OPALTERAR) 
         bSOp=false
       when 2 
         frmCadastros(sreg, OPEXCLUIR) 
         bSOp=false
       when 3 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 when 9
   while bSOp do
     menu(nmenu)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         btnAcao(sreg, OPSALVARALTERACAO) 
         bSOp=false
       when 2 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 when 10
   while bSOp do
     menu(nmenu)
     opCSubMenu = digita()
     if (opCSubMenu=="S") or (opCSubMenu=="s") then
        btnAcao(sreg, OPCONFIRMAEXCLUSAO)
        bSOp=false
     elsif (opCSubMenu=="N") or (opCSubMenu=="n") then 
        bSOp=false
     else print(MSG_ERRO)
     end
   end
 when 12
   while bSOp do
     menu(nmenu)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         frmConsultas(sreg, OPPESQUISAR)
       when 2 
         frmConsultas(sreg, OPLISTARTODOS)
       when 3 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 when 14
   while bSOp do
     menu(nmenu)
     opCSubMenu = digita()
     if (opCSubMenu=="S") or (opCSubMenu=="s") then
        btnAcao(sreg, OPSALVARINCLUSAO)
        bSOp=false
        $g_SalvarInclusao=true
     elsif (opCSubMenu=="N") or (opCSubMenu=="n") then 
        bSOp=false
     else print(MSG_ERRO)
     end
   end
end

end
#------------------------------------------------------------------------------
# Seleciona o submenu e/ou a tela certa de acordo com número do menu.
# nmenu - o número do menu
#------------------------------------------------------------------------------
def usaMenu(num)
opSubMenu = 0
opSair = ""

 bSOp=true
 if num == 1 then # Cadastros
   while bSOp do
     menu(2)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         subMenu(6, OPASSUNTO)
       when 2 
         subMenu(6, OPAUTOR)
       when 3 
         subMenu(6, OPEDITORA)
       when 4 
         subMenu(6, OPENDERECO)
       when 5   
         subMenu(6, OPIDIOMA)
       when 6 
         subMenu(6, OPPAIS)
       when 7 
         subMenu(6, OPPROFISSAO)
       when 8 
         subMenu(6, OPCLIENTE)
       when 9 
         subMenu(6, OPLIVRO)
       when 10 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 elsif num == 2 then # Pesquisas
   while bSOp do
     menu(3)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         subMenu(12, OPASSUNTO)
       when 2 
         subMenu(12, OPAUTOR)
       when 3 
         subMenu(12, OPEDITORA)
       when 4 
         subMenu(12, OPENDERECO)
       when 5 
         subMenu(12, OPIDIOMA)
       when 6 
         subMenu(12, OPPAIS)
       when 7 
         subMenu(12, OPPROFISSAO)
       when 8 
         subMenu(12, OPCLIENTE)
       when 9 
         subMenu(12, OPLIVRO)
       when 10 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 elsif num == 3 then # Vendas
   while bSOp do
     menu(4)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         subMenu(6, OPVENDA)
       when 2 
         subMenu(12, OPVENDA)
       when 3 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 elsif num == 4 then # Opcoes
   while bSOp do
     menu(5)
     opSubMenu = digita().to_i
     case opSubMenu
       when 1 
         frmAlterarSenha()
       when 2 
         frmSobre()
       when 3 
         menu(11)
         opSair = digita()
         if (opSair=="S") or (opSair=="s") then
            fechaArqs()
            exit(0)
         end
       when 4 
         bSOp=false
       else 
         print(MSG_ERRO)
     end
   end
 end
end
#------------------------------------------------------------------------------
# Mostra as entradas e as saídas do sistema.
# sreg - o tipo de arquivo
# slinha - o registro com os dados
# nOpcao - indica qual opção será mostrada
#------------------------------------------------------------------------------
def mostrarDados(sreg, slinha, nOpcao)
if sreg==OPASSUNTO then
   case nOpcao
     when 1
        print(rotulo(sreg, 1), TAssunto["codigo"], "\n")
        print(rotulo(sreg, 2))
        TAssunto["assunto"] = digita()
     when 2
        print("Código     Assunto\n")
        print("------     -------\n")
     when 3
        TAssunto["codigo"]=copy(slinha, 1, 10)
        TAssunto["assunto"]=copy(slinha, 11, 30)
        print(TAssunto["codigo"]," ",TAssunto["assunto"],"\n")
   end
elsif sreg==OPAUTOR then
   case nOpcao
     when 1
        print(rotulo(sreg, 1), TAutor["codigo"], "\n")
        print(rotulo(sreg, 2))
        TAutor["autor"] = digita()
     when 2
        print("Código     Autor\n")
        print("------     -----\n")
     when 3
        TAutor["codigo"]=copy(slinha, 1, 10)
        TAutor["autor"]=copy(slinha, 11, 30)
        print(TAutor["codigo"]," ",TAutor["autor"],"\n")
   end
elsif sreg==OPEDITORA then
   case nOpcao
     when 1
        print(rotulo(sreg, 1), TEditora["codigo"], "\n")
        print(rotulo(sreg, 2))
        TEditora["editora"] = digita()
     when 2
        print("Código     Editora\n")
        print("------     -------\n")
     when 3
        TEditora["codigo"]=copy(slinha, 1, 10)
        TEditora["editora"]=copy(slinha, 11, 50)
        print(TEditora["codigo"]," ",TEditora["editora"], "\n")
   end
elsif sreg==OPENDERECO then
   case nOpcao
     when 1
        print(rotulo(sreg, 1), TEndereco["codigo"], "\n")
        print(rotulo(sreg, 2))
        TEndereco["logradouro"] = digita()
        print(rotulo(sreg, 3))
        TEndereco["bairro"] = digita()
        print(rotulo(sreg, 4))
        TEndereco["cep"] = digita()
        print(rotulo(sreg, 5))
        TEndereco["cidade"] = digita()
        print(rotulo(sreg, 6))
        TEndereco["estado"] = digita()
     when 3
        TEndereco["codigo"]=copy(slinha, 1, 10).strip
        TEndereco["logradouro"]=copy(slinha, 11, 40).strip
        TEndereco["bairro"]=copy(slinha, 51, 15).strip
        TEndereco["cep"]=copy(slinha, 66, 8).strip
        TEndereco["cidade"]=copy(slinha, 74, 30).strip
        TEndereco["estado"]=copy(slinha, 104, 20).strip
        print("--------------------\n")
        print(rotulo(sreg, 1), TEndereco["codigo"], "\n")
        print(rotulo(sreg, 2), TEndereco["logradouro"], "\n")
        print(rotulo(sreg, 3), TEndereco["bairro"], "\n")
        print(rotulo(sreg, 4), TEndereco["cep"], "\n")
        print(rotulo(sreg, 5), TEndereco["cidade"], "\n")
        print(rotulo(sreg, 6), TEndereco["estado"], "\n")
   end
elsif sreg==OPIDIOMA then
   case nOpcao
     when 1
        print(rotulo(sreg, 1), TIdioma["codigo"], "\n")
        print(rotulo(sreg, 2))
        TIdioma["idioma"] = digita()
     when 2
        print("Código     Idioma\n")
        print("------     ------\n")
     when 3
        TIdioma["codigo"]=copy(slinha, 1, 10)
        TIdioma["idioma"]=copy(slinha, 11, 20)
        print(TIdioma["codigo"]," ",TIdioma["idioma"], "\n")
   end
elsif sreg==OPPAIS then
   case nOpcao
     when 1
        print(rotulo(sreg, 2))
        TPais["pais"] = digita()
     when 2
        print("Código País\n")
        print("------ ----\n")
     when 3
        TPais["codigo"]=copy(slinha, 1, 3)
        TPais["pais"]=copy(slinha, 4, 50)
        print(TPais["codigo"],"    ",TPais["pais"], "\n")
   end
elsif sreg==OPPROFISSAO then
   case nOpcao
     when 1
        print(rotulo(sreg, 1), TProfissao["codigo"], "\n")
        print(rotulo(sreg, 2))
        TProfissao["profissao"] = digita()
     when 2
        print("Código     Profissão\n")
        print("------     ---------\n")
     when 3
        TProfissao["codigo"]=copy(slinha, 1, 10)
        TProfissao["profissao"]=copy(slinha, 11, 50)
        print(TProfissao["codigo"]," ",TProfissao["profissao"], "\n")
   end
elsif sreg==OPLIVRO then
   case nOpcao
     when 1
        print(rotulo(sreg, 2))
        TLivro["titulo"] = digita()
        TLivro["edicao"]=validaNumero(rotulo(sreg, 3), TLivro["edicao"])
        TLivro["anopubli"]=validaNumero(rotulo(sreg, 4), TLivro["anopubli"])
        mostrarSubDados(OPLIVRO, OPEDITORA, false)
        TLivro["volume"]=validaNumero(rotulo(sreg, 6), TLivro["volume"])
        mostrarSubDados(OPLIVRO, OPIDIOMA, false)
        TLivro["npaginas"]=validaNumero(rotulo(sreg, 8), TLivro["npaginas"])
        TLivro["preco"]=validaNumero(rotulo(sreg, 9), TLivro["preco"])
        TLivro["qtdestoque"]=validaNumero(rotulo(sreg, 10), TLivro["qtdestoque"])
     when 3
        TLivro["isbn"]=copy(slinha, 1, 13).strip
        TLivro["titulo"]=copy(slinha, 14, 50).strip
        TLivro["edicao"]=copy(slinha, 64, 10).strip
        TLivro["anopubli"]=copy(slinha, 74, 10).strip
        TLivro["codeditora"]=copy(slinha, 84, 10).strip
        TLivro["volume"]=copy(slinha, 94, 10).strip
        TLivro["codidioma"]=copy(slinha, 104, 10).strip
        TLivro["npaginas"]=copy(slinha, 114, 10).strip
        TLivro["preco"]=copy(slinha, 124, 10).strip
        TLivro["qtdestoque"]=copy(slinha, 134, 10).strip
        print("--------------------\n")
        print(rotulo(sreg, 1), TLivro["isbn"], "\n")
        print(rotulo(sreg, 2), TLivro["titulo"], "\n")
        print(rotulo(sreg, 3), TLivro["edicao"], "\n")
        print(rotulo(sreg, 4), TLivro["anopubli"], "\n")
        print(rotulo(sreg, 5), TLivro["codeditora"], "\n")
        mostrarSubDados(OPLIVRO, OPEDITORA, true)
        print(rotulo(sreg, 6), TLivro["volume"], "\n")
        print(rotulo(sreg, 7), TLivro["codidioma"], "\n")
        mostrarSubDados(OPLIVRO, OPIDIOMA, true)
        print(rotulo(sreg, 8), TLivro["npaginas"], "\n")
        print(rotulo(sreg, 9), TLivro["preco"], "\n")
        print(rotulo(sreg, 10), TLivro["qtdestoque"], "\n")
        ListarRegLigados($tfLivroAss, OPLIVROASS, 1, 13, 14, 10, TLivro["isbn"],
                         $tfAssunto, OPASSUNTO, 1, 4)
        ListarRegLigados($tfLivroAut, OPLIVROAUT, 1, 13, 14, 10, TLivro["isbn"],
                         $tfAutor, OPAUTOR, 1, 4)
   end
elsif sreg==OPCLIENTE then
   case nOpcao
     when 1
        print(rotulo(sreg, 2))
        TCliente["nome"] = digita()
        print(rotulo(sreg, 3))
        TCliente["email"] = digita()
        print(rotulo(sreg, 4))
        TCliente["identidade"] = digita()
        print(rotulo(sreg, 5))
        TCliente["sexo"] = digita()
        print(rotulo(sreg, 6))
        TCliente["telefone"] = digita()
        TCliente["dtnascimento"]=
                validaDataHora(rotulo(sreg, 7), TCliente["dtnascimento"], true)
        mostrarSubDados(OPCLIENTE, OPENDERECO, false)
        mostrarSubDados(OPCLIENTE, OPPAIS, false)
        mostrarSubDados(OPCLIENTE, OPPROFISSAO, false)
     when 3
        TCliente["cpf"]=copy(slinha, 1, 14).strip
        TCliente["nome"]=copy(slinha, 15, 30).strip
        TCliente["email"]=copy(slinha, 45, 30).strip
        TCliente["identidade"]=copy(slinha, 75, 10).strip
        TCliente["sexo"]=copy(slinha, 85, 1).strip
        TCliente["telefone"]=copy(slinha, 86, 17).strip
        TCliente["dtnascimento"]=copy(slinha, 103, 10).strip
        TCliente["codendereco"]=copy(slinha, 113, 10).strip
        TCliente["codpais"]=copy(slinha, 123, 3).strip
        TCliente["codprofissao"]=copy(slinha, 126, 10).strip
        print("--------------------\n")
        print(rotulo(sreg, 1), TCliente["cpf"], "\n")
        print(rotulo(sreg, 2), TCliente["nome"], "\n")
        print(rotulo(sreg, 3), TCliente["email"], "\n")
        print(rotulo(sreg, 4), TCliente["identidade"], "\n")
        print(rotulo(sreg, 5), TCliente["sexo"], "\n")
        print(rotulo(sreg, 6), TCliente["telefone"], "\n")
        print(rotulo(sreg, 7), TCliente["dtnascimento"], "\n")
        print(rotulo(sreg, 8), TCliente["codendereco"], "\n")
        mostrarSubDados(OPCLIENTE, OPENDERECO, true)
        print(rotulo(sreg, 9), TCliente["codpais"], "\n")
        mostrarSubDados(OPCLIENTE, OPPAIS, true)
        print(rotulo(sreg, 10), TCliente["codprofissao"], "\n")
        mostrarSubDados(OPCLIENTE, OPPROFISSAO, true)
   end
elsif sreg==OPVENDA then
   case nOpcao
     when 1 
        mostrarSubDados(OPVENDA,OPVENDA, false)
     when 2
        print("DataHoraVenda       CPF            ISBN          "+
        "PreçoVenda\n")
        print("-------------       ---            ----          "+
        "----------\n")
     when 3
        TVenda["dthrvenda"]=copy(slinha, 1, 19)
        TVenda["cpf"]=copy(slinha, 20, 14)
        TVenda["isbn"]=copy(slinha, 34, 13)
        TVenda["precovenda"]=copy(slinha, 47, 10)
        print(TVenda["dthrvenda"]," ",TVenda["cpf"]," ",TVenda["isbn"]," ",
        TVenda["precovenda"], "\n")
   end
end

end
#------------------------------------------------------------------------------
# Mostra as sub informções de entrada e de saída.
# sreg - o tipo de arquivo
# ssubreg - o subtipo de arquivo
# bSoMostrar - se vai só mostrar na saída 
#------------------------------------------------------------------------------
def mostrarSubDados(sreg, ssubreg, bSoMostrar)
sRegistro, sPreco = "", ""
nMaxTentativas=3
if sreg==OPLIVRO then
  if ssubreg==OPEDITORA then
    if bSoMostrar then
       sRegistro=pesqArq($tfEditora,TLivro["codeditora"],1,10,tamReg(OPEDITORA))
    else
       sRegistro=validaEntrada($tfEditora,ssubreg,1,TLivro["codeditora"],
                  nMaxTentativas,false,OPNUMERO)
    end
    if sRegistro!="" then
      TLivro["codeditora"]=copy(sRegistro,1,10).strip
      print(" ",rotulo(OPEDITORA, 2))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
    end
  elsif ssubreg==OPIDIOMA then
    if bSoMostrar then
       sRegistro=pesqArq($tfIdioma, TLivro["codidioma"], 1, 10,tamReg(OPIDIOMA))
    else
       sRegistro=validaEntrada($tfIdioma,ssubreg,1,TLivro["codidioma"],
                  nMaxTentativas,false,OPNUMERO)
    end
    if sRegistro!="" then
      TLivro["codidioma"]=copy(sRegistro,1,10).strip
      print(" ",rotulo(OPIDIOMA, 2))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
    end
  end
elsif sreg==OPCLIENTE then
  if ssubreg==OPENDERECO then
    if bSoMostrar then
       sRegistro=pesqArq($tfEndereco, TCliente["codendereco"], 1, 10,
                  tamReg(OPENDERECO))
    else
       sRegistro=validaEntrada($tfEndereco,ssubreg,1,TCliente["codendereco"],
                  nMaxTentativas,false,OPNUMERO)
    end
    if sRegistro!="" then
      TCliente["codendereco"]=copy(sRegistro,1,10).strip
      print(" ",rotulo(OPENDERECO, 2))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
      print(" ",rotulo(OPENDERECO, 3))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
      print(" ",rotulo(OPENDERECO, 4))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
      print(" ",rotulo(OPENDERECO, 5))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
      print(" ",rotulo(OPENDERECO, 6))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
    end
  elsif ssubreg==OPPAIS then
    if bSoMostrar then
       sRegistro=pesqArq($tfPais, TCliente["codpais"], 1, 3, tamReg(OPPAIS))
    else
       sRegistro=validaEntrada($tfPais,ssubreg,1,TCliente["codpais"],
                  nMaxTentativas,false,OPTEXTO)
    end
    if sRegistro!="" then
      TCliente["codpais"]=copy(sRegistro,1,3).strip
      print(" ",rotulo(OPPAIS, 2))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
    end
  elsif ssubreg==OPPROFISSAO then
    if bSoMostrar then
       sRegistro=pesqArq($tfProfissao, TCliente["codprofissao"], 1, 10,
                  tamReg(OPPROFISSAO))
    else
       sRegistro=validaEntrada($tfProfissao,ssubreg,1,TCliente["codprofissao"],
                  nMaxTentativas,false,OPNUMERO)
    end
    if sRegistro!="" then
      TCliente["codprofissao"]=copy(sRegistro,1,10).strip
      print(" ",rotulo(OPPROFISSAO, 2))
      print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
    end
  end
elsif sreg==OPVENDA then
  sRegistro=pesqArq($tfLivro, TVenda["isbn"], 1, 13, tamReg(OPLIVRO))
  if sRegistro!="" then
    print(" ",rotulo(OPLIVRO, 2)) # Titulo 
    print(copy(sRegistro, $g_nPosChave, $g_nTamChave), "\n")
    print(" ",rotulo(OPLIVRO, 9)) # Preco 
    sPreco=copy(sRegistro, $g_nPosChave, $g_nTamChave)
    $g_nPreco = sPreco.to_f
    print(sPreco, "\n")
  end
end
end
#------------------------------------------------------------------------------
# Realiza os cadastros dos arquivos que se ligam a outros arquivos.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
# sCodigo - um das chaves do arquivo de ligação
#------------------------------------------------------------------------------
def frmCadLigados(sreg, sacao, sCodigo)
nQtd, nCont, nQtdEstoque = 0,0,0
nTotalPreco = 0.0
slinha, sTotalPreco, sPreco, sQtd = "","","",""

if sacao==OPNOVO then
  nCont=1
  if sreg==OPLIVROASS then
    sQtd=validaNumero("Quantos assuntos quer cadastrar?: ", sQtd)
    nQtd = sQtd.to_i
    $tfLivroAss.seek(0, IO::SEEK_SET)
    while nCont <= nQtd do
      TLivroAss["isbn"]=sCodigo
      print(rotulo(OPLIVROASS, 2))
      TLivroAss["codassunto"] = digita()
      slinha=pesqArq($tfAssunto, TLivroAss["codassunto"],1,10,tamReg(OPASSUNTO))
      print(" ",rotulo(OPASSUNTO, 2))
      print(copy(slinha, $g_nPosChave, $g_nTamChave), "\n")
      pesqLinhaExcluida($tfLivroAss, tamReg(sreg))
      subMenu(14, sreg)
      nCont=nCont+1
    end
  elsif sreg==OPLIVROAUT then
    sQtd=validaNumero("Quantos autores quer cadastrar?: ",sQtd)
    nQtd = sQtd.to_i
    $tfLivroAut.seek(0, IO::SEEK_SET)
    while nCont <= nQtd do
      TLivroAut["isbn"]=sCodigo
      print(rotulo(OPLIVROAUT, 2))
      TLivroAut["codautor"] = digita()
      slinha=pesqArq($tfAutor, TLivroAut["codautor"],1,10,tamReg(OPAUTOR))
      print(" ",rotulo(OPAUTOR, 2))
      print(copy(slinha, $g_nPosChave, $g_nTamChave), "\n")
      pesqLinhaExcluida($tfLivroAut, tamReg(sreg))
      subMenu(14, sreg)
      nCont=nCont+1
    end
  elsif sreg==OPVENDA then
    sQtd=validaNumero("Quantos livros quer vender?: ",sQtd)
    nQtd = sQtd.to_i
    nTotalPreco=0
    while nCont <= nQtd do
      slinha=validaEntrada($tfLivro,OPLIVRO,1,TVenda["isbn"],3,false,OPTEXTO)
      if slinha!="" then
        TVenda["isbn"]=copy(slinha,1,13).strip
        if validaISBN(TVenda["isbn"]) then
          mostrarDados(sreg, "", 1)
          TLivro["qtdestoque"]=copy(slinha,134,10).strip
          nQtdEstoque = TLivro["qtdestoque"].to_i
          if nQtdEstoque > 0 then
             nTotalPreco=nTotalPreco + $g_nPreco
             sPreco=$g_nPreco.to_s
             TVenda["precovenda"]=sPreco
             $g_SalvarInclusao=false
             subMenu(14, sreg)
             if $g_SalvarInclusao then
                slinha=pesqArq($tfLivro, TVenda["isbn"], 1, 13, tamReg(OPLIVRO))
                if slinha!="" then
                   nQtdEstoque=nQtdEstoque-1
                   TLivro["qtdestoque"] = nQtdEstoque.to_s
                   slinha=copy(slinha,1,133)+esp(TLivro["qtdestoque"],10)
                   escreveArq($tfLivro, slinha, "", "")
                end
             end
             nCont=nCont+1
          else 
            print(MSG_SEMESTOQUE)
          end 
        else 
          print(MSG_ISBNINV)
        end
      end
    end
    sTotalPreco = nTotalPreco.to_s
    print("Total de ",rotulo(sreg,4),sTotalPreco, "\n")
  end
elsif sacao==OPEXCLUIR then
  if sreg==OPLIVROASS then
     ExcluirRegLigados($tfLivroAss, sreg, 1, 13, sCodigo)
  elsif sreg==OPLIVROAUT then
     ExcluirRegLigados($tfLivroAut, sreg, 1, 13, sCodigo)
  end
end

end
#------------------------------------------------------------------------------
# Realiza a exclusão dos arquivos de ligação.
# sArq - o arquivo de ligação
# sreg - o tipo de arquivo de ligação
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# sChave - a chave a ser excluida
#------------------------------------------------------------------------------
def ExcluirRegLigados(sArq, sreg, nPosChave, nTamChave, sChave)
slinha, sCodigo = "", ""

  sArq.seek(0, IO::SEEK_SET)
  while (not sArq.eof) do
    slinha = sArq.readline
    sCodigo=copy(slinha,nPosChave,nTamChave).strip
    if sCodigo==sChave then
       btnAcao(sreg,OPCONFIRMAEXCLUSAO)
    end
  end
end

#------------------------------------------------------------------------------
# Parte inicial do código
#------------------------------------------------------------------------------
def Main()
 if (ARGV.length > 0) and (ARGV[0]=="-cria") then
   abrecriaArqs(false)
 else
   frmSplash()
   abrecriaArqs(true)
   if frmLogin() then
     $bopcao=true
     while $bopcao do
       menu(1)
       $opmenu = digita()
       if ($opmenu=="C") or ($opmenu=="c") then usaMenu(1)
       elsif ($opmenu=="P") or ($opmenu=="p") then usaMenu(2)
       elsif ($opmenu=="V") or ($opmenu=="v") then usaMenu(3)
       elsif ($opmenu=="O") or ($opmenu=="o") then usaMenu(4)
       else 
         print(MSG_ERRO)
       end
     end
   else
     fechaArqs()
     exit(0)
   end
 end
end

Main()
