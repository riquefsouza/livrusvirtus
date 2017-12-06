#!/usr/bin/env python

#------------------------------------------------------------------------------
# Sistema integrante do projeto Livrus Virtus.
# Todos os direitos reservados para Henrique F. de Souza.
# Versao programada na linguagem python.
#------------------------------------------------------------------------------
# programa Livrus

import os, sys, string, getpass
from time import localtime, strftime

# Tipos

tAssunto = { 'codigo': '', 'assunto': '' }
tAutor = { 'codigo': '', 'autor': '' }
tEditora = { 'codigo': '', 'editora': '' }
tIdioma = { 'codigo': '', 'idioma': '' }
tUsuario = { 'login': '', 'senha': '' }
tPais = { 'codigo': '', 'pais': '' }
tProfissao = { 'codigo': '', 'profissao': '' }
tLivro = { 'isbn': '', 'titulo': '', 'edicao': '', 'anopubli': '', 
           'codeditora': '', 'volume': '', 'codidioma': '', 
           'npaginas': '', 'preco': '', 'qtdestoque': '' }
tLivroAss = { 'isbn': '', 'codassunto': '' }
tLivroAut = { 'isbn': '', 'codautor': '' }
tCliente = { 'cpf': '', 'nome': '', 'email': '', 'identidade': '', 
             'sexo': '', 'telefone': '', 'dtnascimento': '', 
             'codendereco': '', 'codpais': '', 'codprofissao': '' }
tEndereco = { 'codigo': '', 'logradouro': '', 'bairro': '', 
              'cep': '', 'cidade': '', 'estado': '' } 
tVenda = { 'dthrvenda': '', 'cpf': '', 'isbn': '', 'precovenda': '' }

ctTipo = ['opTexto', 'opNumero', 'opData', 'opDataHora', 'opSenha']
ctArqs = ['opAssunto', 'opAutor', 'opEditora', 'opEndereco', 'opIdioma', 'opPais',
          'opProfissao', 'opCliente', 'opLivro', 'opLivroAss', 'opLivroAut',
          'opUsuario', 'opVenda']
ctAcao = ['opNovo', 'opAlterar', 'opPesquisar', 'opSalvarInclusao',
          'opSalvarAlteracao', 'opExcluir', 'opConfirmaExclusao', 'opListarTodos']

# constantes

CRLF = '\n' # windows
TAM_CRLF = 1
# CRLF = '\n'
# TAM_CRLF = 1 # unix 
# CRLF = '\r'
# TAM_CRLF = 1 # macintosh 

ARQ_ABRE = 'r+'
ARQ_CRIA = 'w'

SEEK_SET = 0
SEEK_CUR = 1
SEEK_END = 2

QTD_MAX_LINHA = 18

MSG_ERRO = 'Erro: opcao invalida digite de novo'
MSG_OPCAO = 'Escolha uma opcao: '
MSG_PRESS = 'pressione para continuar...'

MSG_REGINC = 'registro incluido!'
MSG_REGNINC = 'registro nao incluido!'
MSG_REGALT = 'registro alterado!'
MSG_REGNALT = 'registro nao alterado!'
MSG_REGEXC = 'registro excluido!'
MSG_REGNEXC = 'registro nao excluido!'
MSG_REGEXST = 'registro ja existe!'

MSG_NUMINV = 'Numero invalido ou menor do que 1!'
MSG_DATAINV = 'Data invalida!, formato correto (dd/mm/yyyy)'
MSG_DTHRINV = 'Data/hora invalida!, formato correto (dd/mm/yyyy hh:mm:ss)'
MSG_ISBNINV = 'ISBN invalido!'
MSG_CPFINV = 'CPF invalido!'
MSG_SENCONFERE = 'senha nao confere com a senha atual!'
MSG_SENCONFIRM = 'nova senha nao confere com a senha confirmada!'
MSG_LOGINENCON = 'login nao encontrado!'
MSG_SEMESTOQUE = 'livro nao existe no estoque!'

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

# variaveis globais

bopcao = False
opmenu = ''
g_nPosChave = { 'opAssunto': [1,11], 'opAutor': [1,11], 'opEditora': [1,11], 
          'opEndereco': [1,11,51,66,74,104], 'opIdioma': [1,11], 'opPais': [1,4],
          'opProfissao': [1,11], 'opCliente': [1,15,45,75,85,86,103,113,123,126], 
          'opLivro': [1,14,64,74,84,94,104,114,124,134], 'opLivroAss': [1,14], 
          'opLivroAut': [1,14], 'opUsuario': [1,11], 'opVenda': [1,20,34,47] }
g_nTamChave = { 'opAssunto': [10,30], 'opAutor': [10,30], 'opEditora': [10,50], 
          'opEndereco': [10,40,15,8,30,20], 'opIdioma': [10,20], 'opPais': [3,50],
          'opProfissao': [10,50], 'opCliente': [14,30,30,10,1,17,10,10,3,10], 
          'opLivro': [13,50,10,10,10,10,10,10,10,10], 
          'opLivroAss': [13,10], 'opLivroAut': [13,10],
          'opUsuario': [10,10], 'opVenda': [19,14,13,10] }
g_nPreco = { 'valor': 0.0 }
g_SalvarInclusao =  { 'valor': False }

tf = { 'Assunto': None, 'Autor': None, 'Editora': None, 'Idioma': None,
       'Endereco': None, 'Pais': None, 'Profissao': None, 'Livro': None,
       'LivroAss': None, 'LivroAut': None, 'Cliente': None, 
       'Usuario': None, 'Venda': None }

#--- Rotinas basicas ---------------------------------------------------------

#------------------------------------------------------------------------------
# Repete um texto um numero determinado de vezes.
# sTexto - o texto a ser repetido
# nQtd - a quantidade de vezes
# retorna - o texto repetido
#------------------------------------------------------------------------------
def repete(sTexto, nQtd):
  sret = sTexto
  sret *= nQtd
  return sret

#------------------------------------------------------------------------------
# Coloca espacos em branco a mais de acordo com o tamanho maximo do texto.
# sTexto - o texto
# nTam - tamanho maximo do texto
# retorna - o texto com espacos em branco a mais
# ------------------------------------------------------------------------------}
def esp(sTexto, nTam):
  return string.ljust(sTexto, nTam)

#------------------------------------------------------------------------------
# Faz uma pesquisa relativa de um texto atraves de um valor chave.
# sTexto - o texto
# sChave - a chave a ser pesquisada
# retorna - se achou ou nao a chave dentro do texto
# ------------------------------------------------------------------------------
def strRelativa(sTexto, sChave):
  if string.find(sTexto, sChave)!=-1:
    return True
  else: 
    return False

#------------------------------------------------------------------------------
# Funcao que retorna um pedaco de uma string.
# stexto - indica a string
# nini - indica a posicao inicial do pedaco
# ntam - indica o tamanho do pedaco
# retorna - o pedaco da string
#------------------------------------------------------------------------------
def copy(stexto, nini, ntam):
  return stexto[nini-1:nini+ntam-1]

#------------------------------------------------------------------------------
# Calcula o modulo11 de um valor qualquer.
# svalor - a mstring com o numero a ser calculado
# ndig - digito do valor a ser calculado
# retorna - o digito correto
#------------------------------------------------------------------------------
def modulo11(svalor, ndig):
  ncont = 1
  slocal = ''
  while (ncont <= 11):
    slocal=copy(svalor,ncont,1) + slocal
    ncont=ncont+1
  nsoma=0;
  if (ndig == 1):
    ncont=3;
  else:
    ncont=2;
  npos = 2
  while (ncont <= 11):
    sres = copy(slocal,ncont,1)
    nvalor = int(sres)
    nsoma=nsoma + (nvalor * npos)
    ncont=ncont+1
    npos=npos+1

  nsoma=(11 - (nsoma % 11))
  if (nsoma > 9):
    return 0
  else:
    return nsoma

#------------------------------------------------------------------------------
# Validacao de um numero de CPF qualquer.
# cpf - a mstring com o numero do CPF
# retorna - se e valido ou nao
#------------------------------------------------------------------------------
def validaCPF(cpf):
  if len(cpf)==14:
    try:
      scpf=copy(cpf,1,3)+copy(cpf,5,3)+copy(cpf,9,3)+copy(cpf,13,2)
      sres=copy(cpf,13,1)
      nvalor1 = int(sres)
      sres=copy(cpf,14,1)
      nvalor2 = int(sres)
      if (modulo11(scpf,1)==nvalor1) and (modulo11(scpf,2)==nvalor2):
        return True
      else:
        return False
    except:
      return False
  else:
    return False

#------------------------------------------------------------------------------
# Validacao de um numero ISBN qualquer.
# isbn - a mstring com o numero do ISBN
# retorna - se e valido ou nao
#------------------------------------------------------------------------------
def validaISBN(isbn):
  if len(isbn)==13:
    sdigito = copy(isbn, len(isbn), 1)
    sisbn=''
    for ncont in range(1, len(isbn)):
      if copy(isbn,ncont,1)!='-':
        sisbn=sisbn+copy(isbn,ncont,1)

    if sdigito == 'X':
      nsoma = 10
    else:
      nvalor = int(sdigito)
      nsoma = nvalor

    for ncont in range(1, 10):
      snum = copy(sisbn, ncont, 1)
      nvalor = int(snum)
      nsoma=nsoma + (nvalor * (11 - ncont))

    if ((nsoma % 11) == 0):
      return True
    else:
      return False
  else:
    return False

#------------------------------------------------------------------------------
# Esconde a digitacao da senha
# retorna - a senha digitada
#------------------------------------------------------------------------------
def digitaSenha(sRotulo, nTamSenha):
  bQuebra=False
  while (bQuebra==False):
    sSenha = getpass.getpass(sRotulo)
    if len(sSenha) > nTamSenha:
       print('senha muito extensa!')
    else: bQuebra=True
  print('')
  return sSenha

#------------------------------------------------------------------------------
# Validacao de um numero qualquer.
# sRotulo - o texto antes de se digitar o numero
# sNumero - a mstring com o valor do numero
# retorna - o sNumero
#------------------------------------------------------------------------------
def validaNumero(sRotulo, sNumero):
  nStatus = -1
  while nStatus!=0:
    try:
      sNumero = raw_input(sRotulo)
      nnum = int(sNumero)
      if (nnum < 1):
        print(MSG_NUMINV)
      else:
        nStatus=0
    except:
      print(MSG_NUMINV)
  
  return sNumero

#------------------------------------------------------------------------------
# Validacao de uma data ou data/hora qualquer.
# sRotulo - o texto antes de se digitar a data/hora
# sDataHora - a mstring com o valor da data/hora
# bSoData - indica se vai validar somente uma data sem a hora
# retorna - a sDataHora
#------------------------------------------------------------------------------
def validaDataHora(sRotulo, sDataHora, bSoData):
  bvalida=False
  bdatavalida=False
  bhoravalida=False
  nudiames=0
  if bSoData==True: ntam=10
  else: ntam=19
  while bvalida==False:
    try:
      sDataHora = raw_input(sRotulo)
  
      if len(sDataHora)==ntam:
        sdia = copy(sDataHora,1,2)
        ndia = int(sdia)
        smes = copy(sDataHora,4,2)
        nmes = int(smes)
        sano = copy(sDataHora,7,4)
        nano = int(sano)
      
        if (nano >= 1) and (nano <= 9999):
          if (nmes >= 1) and (nmes <= 31):
              if nmes in [1, 3, 5, 7, 8, 10, 12]: 
                nudiames = 31
              elif nmes == 2: 
                # ano bissexto 
                if (nano % 4) == 0: 
                  nudiames = 29
                else: nudiames = 28
              elif nmes in [4, 6, 9, 11]: 
                nudiames = 30
              if (ndia >=1) and (ndia <=nudiames):
                 bdatavalida = True
      
        if bSoData:
           if bdatavalida: bvalida = True
           else: print(MSG_DATAINV)
        else:
          if bdatavalida:
              shora = copy(sDataHora,12,2)
              nhora = int(shora)
              smin = copy(sDataHora,15,2)
              nmin = int(smin)
              sseg = copy(sDataHora,18,2)
              nseg = int(sseg)
          
              if (nhora >= 0) and (nhora <= 23):
                if (nmin >= 0) and (nmin <= 59):
                  if (nseg >= 0) and (nseg <= 59):
                     bhoravalida = True
          
              if bhoravalida: bvalida = True
              else: print(MSG_DTHRINV)
          else:
            print(MSG_DTHRINV)
      else:
        if bSoData==True: print(MSG_DATAINV)
        else: print(MSG_DTHRINV)
    except:
      if bSoData==True: print(MSG_DATAINV)
      else: print(MSG_DTHRINV)

  return sDataHora

#------------------------------------------------------------------------------
# Retorna a Data e a hora do sistema.
# retorna - a data e a hora
#------------------------------------------------------------------------------
def retDataHora():
  return strftime('%d/%m/%Y %H:%M:%S', localtime())

#--- Rotinas de manipulacao de arquivos --------------------------------------

#------------------------------------------------------------------------------
# Calcula o tamanho do arquivo.
# sArq - o arquivo
# retorna - o tamanho do arquivo
#------------------------------------------------------------------------------
def tamArq(sArq):
  ntam = 0
  
  sArq.seek(0, SEEK_END)
  ntam = sArq.tell()
  sArq.seek(0, SEEK_SET)
  
  return ntam

#------------------------------------------------------------------------------
# Abre ou cria os arquivos do sistema.
# bAbre - condicao para abrir ou criar os arquivos do sistema
#------------------------------------------------------------------------------
def abrecriaArqs(bAbre):
  if bAbre:
    tf['Assunto'] = open(ARQ_ASSUNTO,ARQ_ABRE)
    tf['Autor'] = open(ARQ_AUTOR,ARQ_ABRE)
    tf['Editora'] = open(ARQ_EDITORA,ARQ_ABRE)
    tf['Idioma'] = open(ARQ_IDIOMA,ARQ_ABRE)
    tf['Endereco'] = open(ARQ_ENDERECO,ARQ_ABRE)
    tf['Pais'] = open(ARQ_PAIS,ARQ_ABRE)
    tf['Profissao'] = open(ARQ_PROFISSAO,ARQ_ABRE)
    tf['Livro'] = open(ARQ_LIVRO,ARQ_ABRE)
    tf['LivroAss'] = open(ARQ_LIVASS,ARQ_ABRE)
    tf['LivroAut'] = open(ARQ_LIVAUT,ARQ_ABRE)
    tf['Cliente'] = open(ARQ_CLIENTE,ARQ_ABRE)
    tf['Usuario'] = open(ARQ_USUARIO,ARQ_ABRE)
    tf['Venda'] = open(ARQ_VENDA,ARQ_ABRE) 
  else:
    tf['Assunto'] = open(ARQ_ASSUNTO,ARQ_CRIA)
    tf['Autor'] = open(ARQ_AUTOR,ARQ_CRIA)
    tf['Editora'] = open(ARQ_EDITORA,ARQ_CRIA)
    tf['Idioma'] = open(ARQ_IDIOMA,ARQ_CRIA)
    tf['Endereco'] = open(ARQ_ENDERECO,ARQ_CRIA)
    tf['Pais'] = open(ARQ_PAIS,ARQ_CRIA)
    tf['Profissao'] = open(ARQ_PROFISSAO,ARQ_CRIA)
    tf['Livro'] = open(ARQ_LIVRO,ARQ_CRIA)
    tf['LivroAss'] = open(ARQ_LIVASS,ARQ_CRIA)
    tf['LivroAut'] = open(ARQ_LIVAUT,ARQ_CRIA)
    tf['Cliente'] = open(ARQ_CLIENTE,ARQ_CRIA)
    tf['Usuario'] = open(ARQ_USUARIO,ARQ_CRIA)
    tf['Venda'] = open(ARQ_VENDA,ARQ_CRIA)

#------------------------------------------------------------------------------
# Fecha todos os arquivos abertos.
#------------------------------------------------------------------------------
def fechaArqs():
  tf['Assunto'].close()
  tf['Autor'].close()
  tf['Editora'].close()
  tf['Idioma'].close()
  tf['Endereco'].close()
  tf['Pais'].close()
  tf['Profissao'].close()
  tf['Livro'].close()
  tf['LivroAss'].close()
  tf['LivroAut'].close()
  tf['Cliente'].close()
  tf['Usuario'].close()
  tf['Venda'].close()

#------------------------------------------------------------------------------
# Pesquisa um registro atraves de um valor chave num arquivo.
# sArq - o arquivo
# sChave - a chave a ser pesquisada
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o registro pesquisado
#------------------------------------------------------------------------------
def pesqArq(sArq, sChave, nPosChave, nTamChave, nTamLinha):
  slinha='0'
  bQuebra = False
  sArq.seek(0, SEEK_SET)
  while (slinha!='') and (bQuebra==False): 
    slinha=sArq.readline()
    sres = string.strip(copy(slinha,nPosChave,nTamChave))
    if sres == sChave:
       bQuebra = True  
  nPosicao = sArq.tell()-(nTamLinha + TAM_CRLF)
  if nPosicao > 0:
     sArq.seek(nPosicao, SEEK_SET)
  else:
     sArq.seek(0, SEEK_SET)
  if sres != sChave:
     return ''
  else:
     return copy(slinha,1,nTamLinha)

#------------------------------------------------------------------------------
# Pesquisa se tem linha excluida senao vai para a ultima linha do arquivo.
# sArq - o arquivo
# nTamLinha - o tamanho do registro
#------------------------------------------------------------------------------
def pesqLinhaExcluida(sArq, nTamLinha):
  sExcluido=pesqArq(sArq, '*', 1, 1, nTamLinha)
  if sExcluido=='':
     sArq.seek(tamArq(sArq))

#------------------------------------------------------------------------------
# Pesquisa o maior codigo num arquivo.
# sArq - o arquivo
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o maior codigo
#------------------------------------------------------------------------------
def pesqMaxCod(sArq, nPosChave, nTamChave, nTamLinha):
  slinha='0'
  bQuebra=False
  nMaior=0
  sArq.seek(0, SEEK_SET)
  while (slinha!='') and (bQuebra==False): 
    slinha=sArq.readline()
    sres = string.strip(copy(slinha,nPosChave,nTamChave))
    if slinha!='':
      nCod = int(sres)
      if nCod > nMaior:
         nMaior=nCod
  pesqLinhaExcluida(sArq, nTamLinha)
  sres = str(nMaior+1)
  return sres

#------------------------------------------------------------------------------
# Grava os registros num determinado arquivo.
# sArq - o arquivo
# sTexto - o registro a ser gravado
# sMsgAcerto - a mensagem caso o registro foi gravado
# sMsgErro - a mensagem caso o registro nao foi gravado
#------------------------------------------------------------------------------
def escreveArq(sArq, sTexto, sMsgAcerto, sMsgErro):
  sTexto=sTexto+CRLF 
  if sArq.write(sTexto)==None:
     print(sMsgAcerto)
  else:
     print(sMsgErro)

#--- Rotinas de implementacao do sistema e de interface ----------------------

#------------------------------------------------------------------------------
# Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o registro montado
#------------------------------------------------------------------------------
def LinhaReg(sreg):
  slinha=''
  if sreg=='opAssunto':
     slinha=esp(tAssunto['codigo'],10)+esp(tAssunto['assunto'],30)
  elif sreg=='opAutor':
     slinha=esp(tAutor['codigo'],10)+esp(tAutor['autor'],30)
  elif sreg=='opEditora':
     slinha=esp(tEditora['codigo'],10)+esp(tEditora['editora'],50)
  elif sreg=='opEndereco':
     slinha=esp(tEndereco['codigo'],10)+esp(tEndereco['logradouro'],40)+ \
     esp(tEndereco['bairro'],15)+esp(tEndereco['cep'],8)+esp(tEndereco['cidade'],30)+ \
     esp(tEndereco['estado'],20)
  elif sreg=='opIdioma':
     slinha=esp(tIdioma['codigo'],10)+esp(tIdioma['idioma'],20)
  elif sreg=='opPais':
     slinha=esp(tPais['codigo'],3)+esp(tPais['pais'],50)
  elif sreg=='opProfissao':
     slinha=esp(tProfissao['codigo'],10)+esp(tProfissao['profissao'],50)
  elif sreg=='opUsuario':
     slinha=esp(tUsuario['login'],10)+esp(tUsuario['senha'],10)
  elif sreg=='opLivro':
     slinha=esp(tLivro['isbn'],13)+esp(tLivro['titulo'],50)+esp(tLivro['edicao'],10)+ \
     esp(tLivro['anopubli'],10)+esp(tLivro['codeditora'],10)+esp(tLivro['volume'],10)+ \
     esp(tLivro['codidioma'],10)+esp(tLivro['npaginas'],10)+esp(tLivro['preco'],10)+ \
     esp(tLivro['qtdestoque'],10)
  elif sreg=='opLivroAss':
     slinha=esp(tLivroAss['isbn'],13)+esp(tlivroAss['codassunto'],10)
  elif sreg=='opLivroAut':
     slinha=esp(tLivroAut['isbn'],13)+esp(tlivroAut['codautor'],10)
  elif sreg=='opCliente':
     slinha=esp(tCliente['cpf'],14)+esp(tCliente['nome'],30)+esp(tCliente['email'],30)+ \
     esp(tCliente['identidade'],10)+esp(tCliente['sexo'],1)+esp(tCliente['telefone'],17)+ \
     esp(tCliente['dtnascimento'],10)+esp(tCliente['codendereco'],10)+ \
     esp(tCliente['codpais'],3)+esp(tCliente['codprofissao'],10)
  elif sreg=='opVenda':
     slinha=esp(tVenda['dthrvenda'],19)+esp(tVenda['cpf'],14)+esp(tVenda['isbn'],13)+ \
     esp(tVenda['precovenda'],10)
  
  return slinha

#------------------------------------------------------------------------------
# Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o tamanho do registro
#------------------------------------------------------------------------------
def tamReg(sreg):
  nret=0
  if sreg=='opAssunto': nret=TAM_ASSUNTO
  elif sreg=='opAutor': nret=TAM_AUTOR
  elif sreg=='opEditora': nret=TAM_EDITORA
  elif sreg=='opEndereco': nret=TAM_ENDERECO
  elif sreg=='opIdioma': nret=TAM_IDIOMA
  elif sreg=='opPais': nret=TAM_PAIS
  elif sreg=='opProfissao': nret=TAM_PROFISSAO
  elif sreg=='opUsuario': nret=TAM_USUARIO
  elif sreg=='opLivro': nret=TAM_LIVRO
  elif sreg=='opLivroAss': nret=TAM_LIVASS
  elif sreg=='opLivroAut': nret=TAM_LIVAUT
  elif sreg=='opCliente': nret=TAM_CLIENTE
  elif sreg=='opVenda': nret=TAM_VENDA
  
  return nret

#------------------------------------------------------------------------------
# Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# nNum - indica qual rotulo sera retornado
# retorna - o rotulo
#------------------------------------------------------------------------------
def rotulo(sreg, nNum):
  sret=''
  if sreg=='opAssunto':
     if nNum == 0: sret = 'Assunto(s) nao encontrado(s)!'
     elif nNum == 1: sret='Codigo do assunto: '
     elif nNum == 2: sret='Assunto: '
  elif sreg=='opAutor':
     if nNum == 0: sret='Autor(es) nao encontrado(s)!'
     elif nNum == 1: sret='Codigo do autor: '
     elif nNum == 2: sret='Autor: '
  elif sreg=='opEditora':
     if nNum == 0: sret='Editora(s) nao encontrada(s)!'
     elif nNum == 1: sret='Codigo da editora: '
     elif nNum == 2: sret='Editora: '
  elif sreg=='opEndereco':
     if nNum == 0: sret='Endereco(s) nao encontrado(s)!'
     elif nNum == 1: sret='Codigo do endereco: '
     elif nNum == 2: sret='Logradouro: '
     elif nNum == 3: sret='Bairro: '
     elif nNum == 4: sret='CEP: '
     elif nNum == 5: sret='Cidade: '
     elif nNum == 6: sret='Estado: '
  elif sreg=='opIdioma':
     if nNum == 0: sret='Idioma(s) nao encontrado(s)!'
     elif nNum == 1: sret='Codigo do idioma: '
     elif nNum == 2: sret='Idioma: '
  elif sreg=='opPais':
     if nNum == 0: sret='Pais(es) nao encontrado(s)!'
     elif nNum == 1: sret='Codigo do pais: '
     elif nNum == 2: sret='Pais: '
  elif sreg=='opProfissao':
     if nNum == 0: sret='Profissao(es) nao encontrada(s)!'
     elif nNum == 1: sret='Codigo da profissao: '
     elif nNum == 2: sret='Profissao: '
  elif sreg=='opUsuario':
     if nNum == 0: sret='login ou senha incorreta, tente de novo!'
     elif nNum == 1: sret='Login: '
     elif nNum == 2: sret='Senha: '
  elif sreg=='opLivro':
     if nNum == 0: sret='Livro(s) nao encontrado(s)!'
     elif nNum == 1: sret='ISBN: '
     elif nNum == 2: sret='Titulo: '
     elif nNum == 3: sret='Edicao: '
     elif nNum == 4: sret='Ano de Publicacao: '
     elif nNum == 5: sret='Codigo da editora: '
     elif nNum == 6: sret='Volume: '
     elif nNum == 7: sret='Codigo do idioma: '
     elif nNum == 8: sret='Numero de paginas: '
     elif nNum == 9: sret='Preco: '
     elif nNum == 10: sret='Qtd. Estoque: '
  elif sreg=='opLivroAss':
     if nNum == 0: sret='Assunto(s) nao encontrado(s)!'
     elif nNum == 1: sret='ISBN: '
     elif nNum == 2: sret='Codigo do assunto: '
  elif sreg=='opLivroAut':
     if nNum == 0: sret='Autor(s) nao encontrado(s)!'
     elif nNum == 1: sret='ISBN: '
     elif nNum == 2: sret='Codigo do autor: '
  elif sreg=='opCliente':
     if nNum == 0: sret='Cliente(s) nao encontrado(s)!'
     elif nNum == 1: sret='CPF: '
     elif nNum == 2: sret='Nome: '
     elif nNum == 3: sret='E-mail: '
     elif nNum == 4: sret='Identidade: '
     elif nNum == 5: sret='Sexo: '
     elif nNum == 6: sret='Telefone: '
     elif nNum == 7: sret='Dt. Nascimento: '
     elif nNum == 8: sret='Codigo do endereco: '
     elif nNum == 9: sret='Codigo do pais: '
     elif nNum == 10: sret='Codigo da Profissao: '
  elif sreg=='opVenda':
     if nNum == 0: sret='Venda(s) nao encontrada(s)!'
     elif nNum == 1: sret='Data/Hora venda: '
     elif nNum == 2: sret='CPF: '
     elif nNum == 3: sret='ISBN: '
     elif nNum == 4: sret='Pre+o de venda: '
  
  return sret

#------------------------------------------------------------------------------
# Indica se continua ou nao mostrando um numero maximo de linhas.
# nlinha - a linha a ser continuada
# nQtdLinha - a quantidade de linhas a serem mostradas
# retorna - se continua ou nao
#------------------------------------------------------------------------------
def ContinuaSN(nlinha, nQtdLinha):
  opCSubMenu=''
  bret=False
  if nlinha > 0:
    if (nlinha % nQtdLinha) == 0:
      bSOp=True
      while (bSOp):
        menu(13)
        opCSubMenu = raw_input()
        if (opCSubMenu=='S') or (opCSubMenu=='s'): bSOp=False
        elif (opCSubMenu=='N') or (opCSubMenu=='n'):
          bret=True
          bSOp=False
        else: print(MSG_ERRO)
  return bret

#------------------------------------------------------------------------------
# Lista varios registros de acordo com a pesquisa feita.
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
                nTamLinha, nQtdLinha, bPesqRelativa):
  slinha='0'
  bRet=False
  bQuebra=False
  nCont=0
  mostrarDados(sreg, '', 2)
  sArq.seek(0, SEEK_SET)
  while (slinha!='') and (bQuebra==False): 
    slinha=sArq.readline()
 
    if bPesqRelativa:
      sres=string.strip(copy(slinha,nPosChave,nTamChave))
      if strRelativa(sres,sChave):
         bAchou=True
         bRet=True
      else:
         bAchou=False
    else:
      bAchou=True
      bRet=True
  
    if bAchou:
      mostrarDados(sreg, copy(slinha,1,nTamLinha), 3)
      nCont+=1
  
    bQuebra=ContinuaSN(nCont, nQtdLinha)

  return bRet

#------------------------------------------------------------------------------
# Lista varios registros entre arquivos de acordo com a pesquisa feita.
# sArq1 - o arquivo de ligacao
# sreg1 - o tipo de arquivo de ligacao
# nPosChave1 - a posicao inicial da primeira chave no arquivo de ligacao
# nTamChave1 - o tamanho da primeira chave no arquivo de ligacao
# nPosChave2 - a posicao inicial da segunda chave do arquivo de ligacao
# nTamChave2 - o tamanho da segunda chave do arquivo de ligacao
# sChave - a chave a ser pesquisada no arquivo de ligacao
# sArq2 - o arquivo a ser pesquisado
# sreg2 - o tipo de arquivo a ser pesquisado
# nPosChave3 - a posicao inicial da chave do arquivo pesquisado
# nQtdLinha - a quantidade de linhas a serem mostradas
#------------------------------------------------------------------------------
def ListarRegLigados(sArq1, sreg1, nPosChave1, nTamChave1, nPosChave2, 
                     nTamChave2, sChave, sArq2, sreg2, nPosChave3, nQtdLinha):
  slinha1='0'
  bRet=False
  nCont=0
  bQuebra=False
  mostrarDados(sreg2, '', 2)
  sArq1.seek(0, SEEK_SET)
  while (slinha1!='') and (bQuebra==False): 
    slinha1=sArq1.readline()
    sCodigo1=string.strip(copy(slinha1,nPosChave1,nTamChave1))
    if sCodigo1==sChave:
      sCodigo2=string.strip(copy(slinha1,nPosChave2,nTamChave2))
      slinha2=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
      mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3)
      bRet=True
      nCont+=1
    bQuebra=ContinuaSN(nCont, nQtdLinha)

  if bRet==False:
     print(rotulo(sreg2,0))

#------------------------------------------------------------------------------
# Valida a entrada de registros de acordo com a pesquisa feita.
# sArq - o arquivo
# sreg - o tipo de arquivo
# nTexto - o numero do rotulo da entrada
# sEntrada - a chave a ser pesquisada e validada
# nTentativas - o numero maximo de tentativas
# bPesqRelativa - indica se vai realizar uma pesquisa relativa
# bTipoEntrada - indica o tipo de entrada
# retorna - o registro pesquisado e validado
#------------------------------------------------------------------------------
def validaEntrada(sArq, sreg, nTexto, sEntrada, nTentativas, 
                  bPesqRelativa, bTipoEntrada):
  nTamLinha=tamReg(sreg)
  sMsgErro=rotulo(sreg,0)
  sTexto=rotulo(sreg,nTexto)
  nPosChave=g_nPosChave[sreg][nTexto-1]
  nTamChave=g_nTamChave[sreg][nTexto-1]

  ncont=1
  bQuebra=False
  while (bQuebra==False) and (ncont <= nTentativas ):
    if 'opTexto' in bTipoEntrada:
      sEntrada = raw_input(sTexto)
    elif 'opNumero' in bTipoEntrada:
       sEntrada = validaNumero(sTexto,sEntrada)
    elif 'opData' in bTipoEntrada:
       sEntrada = validaDataHora(sTexto,sEntrada,True)
    elif 'opDataHora' in bTipoEntrada:
       sEntrada=validaDataHora(sTexto,sEntrada,False)
    elif 'opSenha' in bTipoEntrada:
       sEntrada = digitaSenha(sTexto, 10)

    sres=''
    if bPesqRelativa:
       if ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, 
         nTamLinha, QTD_MAX_LINHA, True):
         sres = ' '
    else:
       sres = pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)

    if sres=='':
       print(sMsgErro)
    else:
       bQuebra=True

    ncont+=1

  return sres

#------------------------------------------------------------------------------
# Mostra a tela de splash do sistema.
#------------------------------------------------------------------------------
def frmSplash():
  print('*---------------------------------------'+
  '-------------------------------------*')
  print('| LL    II VV   VV RRRRR  UU  UU   SSSS '+
  'VV   VV II RRRRR  TTTT UU  UU   SSSS |')
  print('| LL    II  VV VV  RR   R UU  UU  SS    '+
  ' VV VV  II RR   R  TT  UU  UU  SS    |')
  print('| LL    II   VVV   RRRRR  UU  UU    SS  '+
  '  VVV   II RRRRR   TT  UU  UU    SS  |')
  print('| LLLLL II    V    RR   R  UUUU  SSSS   '+
  '   V    II RR   R  TT   UUUU  SSSS   |')
  print('*---------------------------------------'+
  '-------------------------------------*')
  for cont in range(1, 19): print('')
  print MSG_PRESS,
  raw_input()

#------------------------------------------------------------------------------
# Mostra a tela de sobre do sistema.
#------------------------------------------------------------------------------
def frmSobre():
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
  print('| Versao programada na linguagem python.                     |')
  print('*------------------------------------------------------------*')
  for cont in range(1, 5): print('')
  print MSG_PRESS,
  raw_input()

#------------------------------------------------------------------------------
# Mostra a tela de login do sistema.
# retorna - se o login foi validado corretamente
#------------------------------------------------------------------------------
def frmLogin():
  slinha = ''
  bret = False
  print('*--------------------------------------------------------------*')
  print('| Login do sistema                                             |')
  print('*--------------------------------------------------------------*')
  slinha=validaEntrada(tf['Usuario'], 'opUsuario', 1, tUsuario['login'], 3,
         False, 'opTexto')
  if slinha!='':
     slinha=validaEntrada(tf['Usuario'], 'opUsuario', 2, tUsuario['senha'], 3,
        False, 'opSenha')
     if slinha!='':
        tUsuario['login']=string.strip(copy(slinha, 1, 10))
        tUsuario['senha']=string.strip(copy(slinha, 11, 10))
        bret = True
  return bret

#------------------------------------------------------------------------------
# Mostra os menus do sistema.
# num - o numero do menu
#------------------------------------------------------------------------------
def menu(num):
 if (num==1): 
   print('*--------------------------------------------------------------*')
   print('| (C)adastros        (P)esquisas     (V)endas        (O)pcoes  |')
   print('*--------------------------------------------------------------*')
 elif (num==2):
   print('*---------------------------------*')
   print('| 01. Cadastro de Assuntos        |')
   print('| 02. Cadastro de Autores         |')
   print('| 03. Cadastro de Editoras        |')
   print('| 04. Cadastro de Enderecos       |')
   print('| 05. Cadastro de Idiomas         |')
   print('| 06. Cadastro de Paises          |')
   print('| 07. Cadastro de Profissoes      |')
   print('| 08. Cadastro de Clientes        |')
   print('| 09. Cadastro de Livros          |')
   print('| 10. Voltar ao menu              |')
   print('*---------------------------------*')
 elif (num==3):
   print('*---------------------------------*')
   print('| 01. Consulta de Assuntos        |')
   print('| 02. Consulta de Autores         |')
   print('| 03. Consulta de Editoras        |')
   print('| 04. Consulta de Enderecos       |')
   print('| 05. Consulta de Idiomas         |')
   print('| 06. Consulta de Paises          |')
   print('| 07. Consulta de Profissoes      |')
   print('| 08. Consulta de Clientes        |')
   print('| 09. Consulta de Livros          |')
   print('| 10. Voltar ao menu              |')
   print('*---------------------------------*')
 elif (num==4):
   print('*---------------------------------*')
   print('| 01. Vender Livros               |')
   print('| 02. Vendas Realizadas           |')
   print('| 03. Voltar ao menu              |')
   print('*---------------------------------*')
 elif (num==5):
   print('*---------------------------------*')
   print('| 01. Alterar senha               |')
   print('| 02. Sobre o sistema             |')
   print('| 03. Sair do sistema             |')
   print('| 04. Voltar ao menu              |')
   print('*---------------------------------*')
 elif (num==6):
   print('*--------------------------------------------------------------*')
   print('| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |')
   print('*--------------------------------------------------------------*')
 elif (num==7):
   print('*--------------------------------------------------------------*')
   print('| (1) Salvar inclusao       (2) Voltar ao menu                 |')
   print('*--------------------------------------------------------------*')
 elif (num==8):
   print('*--------------------------------------------------------------*')
   print('| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |')
   print('*--------------------------------------------------------------*')
 elif (num==9):
   print('*--------------------------------------------------------------*')
   print('| (1) Salvar alteracao      (2) Voltar ao menu                 |')
   print('*--------------------------------------------------------------*')
 elif (num==10):
   print('*--------------------------------------------------------------*')
   print('| Certeza de excluir? (S/N)                                    |')
   print('*--------------------------------------------------------------*')
 elif (num==11):
   print('*--------------------------------------------------------------*')
   print('| Deseja sair do sistema? (S/N)                                |')
   print('*--------------------------------------------------------------*')
 elif (num==12):
   print('*--------------------------------------------------------------*')
   print('| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |')
   print('*--------------------------------------------------------------*')
 elif (num==13):
   print('*--------------------------------------------------------------*')
   print('| Deseja continuar? (S/N)                                      |')
   print('*--------------------------------------------------------------*')
 elif (num==14):
   print('*--------------------------------------------------------------*')
   print('| Salvar inclusao (S/N)                                        |')
   print('*--------------------------------------------------------------*')
 print MSG_OPCAO,

#------------------------------------------------------------------------------
# Realiza os cadastros de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a acao a ser realizada
#------------------------------------------------------------------------------
def frmCadastros(sreg, sacao):
  slinha = ''
  
  if sreg=='opAssunto':
     if sacao=='opNovo':
        tAssunto['codigo']=pesqMaxCod(tf['Assunto'], 1, 10, tamReg(sreg))
        mostrarDados(sreg, '', 1)
        subMenu(7, sreg)
     elif sacao=='opPesquisar':
       slinha=validaEntrada(tf['Assunto'],sreg,1,tAssunto['codigo'],1,False,'opNumero')
       if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opAutor':
     if sacao=='opNovo':
        tAutor['codigo']=pesqMaxCod(tf['Autor'], 1, 10, tamReg(sreg))
        mostrarDados(sreg, '', 1)
        subMenu(7, sreg)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Autor'], sreg, 1, tAutor['codigo'],1,False,'opNumero')
        if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opEditora':
     if sacao=='opNovo':
        tEditora['codigo']=pesqMaxCod(tf['Editora'], 1, 10, tamReg(sreg))
        mostrarDados(sreg, '', 1)
        subMenu(7, sreg)
     elif sacao=='opPesquisar':
       slinha=validaEntrada(tf['Editora'],sreg,1,tEditora['codigo'],1,False,'opNumero')
       if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opEndereco':
     if sacao=='opNovo':
        tEndereco['codigo']=pesqMaxCod(tf['Endereco'], 1, 10, tamReg(sreg))
        mostrarDados(sreg, '', 1)
        subMenu(7, sreg)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Endereco'],sreg,1,tEndereco['codigo'],1,
                False,'opNumero')
        if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opIdioma':
     if sacao=='opNovo':
        tIdioma['codigo']=pesqMaxCod(tf['Idioma'], 1, 10, tamReg(sreg))
        mostrarDados(sreg, '', 1)
        subMenu(7, sreg)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Idioma'],sreg,1,tIdioma['codigo'],1,False,'opNumero')
        if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opPais':
     if sacao=='opNovo':
        tPais['codigo'] = raw_input(rotulo(sreg, 1))
        slinha=pesqArq(tf['Pais'], tPais['codigo'], 1, 3, tamReg(sreg))
        if slinha=='':
           pesqLinhaExcluida(tf['Pais'], tamReg(sreg))
           mostrarDados(sreg, '', 1)
           subMenu(7, sreg)
        else: print(MSG_REGEXST)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Pais'], sreg, 1, tPais['codigo'], 1, False, 'opTexto')
        if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        print(rotulo(sreg, 1) + tPais['codigo'])
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opProfissao':
     if sacao=='opNovo':
        tProfissao['codigo']=pesqMaxCod(tf['Profissao'], 1, 10, tamReg(sreg))
        mostrarDados(sreg, '', 1)
        subMenu(7, sreg)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Profissao'],sreg,1,tProfissao['codigo'],1,
                False,'opNumero')
        if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        
     elif sacao=='opAlterar':
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opLivro':
     if sacao=='opNovo':
        tLivro['isbn'] = raw_input(rotulo(sreg, 1))        
        if validaISBN(tLivro['isbn']):
            slinha=pesqArq(tf['Livro'], tLivro['isbn'], 1, 13, tamReg(sreg))
            if slinha=='':
               pesqLinhaExcluida(tf['Livro'], tamReg(sreg))
               mostrarDados(sreg, '', 1)
               subMenu(7, sreg)
               frmCadLigados('opLivroAss', 'opNovo', tLivro['isbn'])
               frmCadLigados('opLivroAut', 'opNovo', tLivro['isbn'])
            else: print(MSG_REGEXST)
        else: print(MSG_ISBNINV)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Livro'], sreg, 1, tLivro['isbn'], 1,False,'opTexto')
        if slinha!='':
           mostrarDados(sreg, '', 2)
           mostrarDados(sreg, slinha, 3)
           subMenu(8, sreg)        
     elif sacao=='opAlterar':
        print(rotulo(sreg, 1) + tLivro['isbn'])
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
        frmCadLigados('opLivroAss', 'opExcluir', tLivro['isbn'])
        print('Assuntos dos livros excluidos, inclua novos!')
        frmCadLigados('opLivroAss', 'opNovo', tLivro['isbn'])
        frmCadLigados('opLivroAut', 'opExcluir', tLivro['isbn'])
        print('Autores dos livros excluidos, inclua novos!')
        frmCadLigados('opLivroAut', 'opNovo', tLivro['isbn'])
     elif sacao=='opExcluir':
        subMenu(10, sreg)
        print('Assuntos dos livros sendo excluidos!')
        frmCadLigados('opLivroAss', 'opExcluir', tLivro['isbn'])
        print('Autores dos livros sendo excluidos!')
        frmCadLigados('opLivroAut', 'opExcluir', tLivro['isbn'])     
  elif sreg=='opCliente':
     if sacao=='opNovo':
        tCliente['cpf'] = raw_input(rotulo(sreg, 1))        
        if validaCPF(tCliente['cpf']):
            slinha=pesqArq(tf['Cliente'], tCliente['cpf'], 1, 14, tamReg(sreg))
            if slinha=='':
               pesqLinhaExcluida(tf['Cliente'], tamReg(sreg))
               mostrarDados(sreg, '', 1)
               subMenu(7, sreg)
            else: print(MSG_REGEXST)
        else: print(MSG_CPFINV)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Cliente'], sreg, 1, tCliente['cpf'],1,False,'opTexto')
        if slinha!='':
           mostrarDados(sreg, '', 2)
           mostrarDados(sreg, slinha, 3)
           subMenu(8, sreg)        
     elif sacao=='opAlterar':
        print(rotulo(sreg, 1) + tCliente['cpf'])
        mostrarDados(sreg, '', 1)
        subMenu(9, sreg)
     elif sacao=='opExcluir':
        subMenu(10, sreg)     
  elif sreg=='opVenda':
     if sacao=='opNovo':
        tVenda['dthrvenda']=retDataHora()
        print(rotulo(sreg, 1) + tVenda['dthrvenda'])
        slinha=pesqArq(tf['Venda'], tVenda['dthrvenda'], 1, 19, tamReg(sreg))
        if slinha=='':
           slinha=validaEntrada(tf['Cliente'],'opCliente',1,tVenda['cpf'],3,
                   False,'opTexto')
           if slinha!='':
              tVenda['cpf']=string.strip(copy(slinha,1,14))
              if validaCPF(tVenda['cpf']):
                 print ' '+rotulo('opCliente', 2), # Nome 
                 print(copy(slinha, g_nPosChave['opCliente'][1], g_nTamChave['opCliente'][1]))
                 frmCadLigados('opVenda', 'opNovo', tVenda['cpf'])
              else: print(MSG_CPFINV)           
        else: print(MSG_REGEXST)
     elif sacao=='opPesquisar':
        slinha=validaEntrada(tf['Venda'], sreg, 1, tVenda['dthrvenda'],1,
                False,'opDataHora')
        if slinha!='':
          mostrarDados(sreg, '', 2)
          mostrarDados(sreg, slinha, 3)
          subMenu(8, sreg)        

#------------------------------------------------------------------------------
# Realiza as consultas de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a acao a ser realizada
#------------------------------------------------------------------------------
def frmConsultas(sreg, sacao):
  slinha = ''
  
  if sreg=='opAssunto':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Assunto'],sreg,2,tAssunto['assunto'],1,True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Assunto'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opAutor':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Autor'],sreg, 2, tAutor['autor'], 1, True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Autor'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opEditora':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Editora'],sreg,2,tEditora['editora'],1,True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Editora'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opEndereco':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Endereco'],sreg,2,tEndereco['Logradouro'],1,
                True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Endereco'], sreg, '', 0, 0, tamReg(sreg),
           3, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opIdioma':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Idioma'], sreg, 2, tIdioma['idioma'],1,True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Idioma'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opPais':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Pais'], sreg, 2, tPais['pais'], 1, True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Pais'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opProfissao':
     if sacao=='opPesquisar':
       slinha=validaEntrada(tf['Profissao'],sreg,2,tProfissao['profissao'],1,
               True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Profissao'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opLivro':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Livro'], sreg, 2, tLivro['titulo'], 1, True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Livro'], sreg, '', 0, 0, tamReg(sreg),
          1, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opCliente':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Cliente'], sreg, 2, tCliente['nome'],1,True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Cliente'], sreg, '', 0, 0, tamReg(sreg),
          1, False) == False:
          print(rotulo(sreg, 0))     
  elif sreg=='opVenda':
     if sacao=='opPesquisar':
        slinha=validaEntrada(tf['Venda'], sreg, 2, tVenda['cpf'], 1, True,'opTexto')
     elif sacao=='opListarTodos':
        if ListarTodos(tf['Venda'], sreg, '', 0, 0, tamReg(sreg),
          QTD_MAX_LINHA, False) == False:
          print(rotulo(sreg, 0))     
  
  if slinha=='':
     print '',

#------------------------------------------------------------------------------
# Mostra a tela de alteracao de senha do sistema e realiza a alteracao.
#------------------------------------------------------------------------------
def frmAlterarSenha():
  print(rotulo('opUsuario', 1) + tUsuario['login'])
  nopcao=1
  bQuebra=False
  while (bQuebra==False):
    if nopcao==1:
         sSenhaAtual = digitaSenha('Senha Atual: ', 10)
         if sSenhaAtual!=tUsuario['senha']:
            print(MSG_SENCONFERE)
            bQuebra=True
         else: nopcao=2        
    elif nopcao==2:
         sNovaSenha = digitaSenha('Nova Senha: ', 10)
         sConfirmaSenha = digitaSenha('Confirma Senha: ', 10)
         if sNovaSenha!=sConfirmaSenha:
            print(MSG_SENCONFIRM)
            bQuebra=True
         else: nopcao=3        
    elif nopcao==3:
         sres=pesqArq(tf['Usuario'], tUsuario['login'], 1, 10, tamReg('opUsuario'))
         if sres=='':
           print(MSG_LOGINENCON)
         else: 
           tUsuario['senha']=sConfirmaSenha
           subMenu(9,'opUsuario')
           bQuebra=True

#------------------------------------------------------------------------------
# Executa uma acao de gravacao de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a acao a ser realizada
# ------------------------------------------------------------------------------
def btnAcao(sreg, sacao):
  if sreg=='opAssunto':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Assunto'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Assunto'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Assunto'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opAutor':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Autor'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Autor'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Autor'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opEditora':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Editora'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Editora'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Editora'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opEndereco':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Endereco'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Endereco'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Endereco'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opIdioma':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Idioma'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Idioma'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Idioma'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opPais':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Pais'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Pais'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Pais'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opProfissao':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Profissao'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Profissao'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Profissao'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opLivro':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Livro'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Livro'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Livro'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opLivroAss':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['LivroAss'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['LivroAss'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['LivroAss'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opLivroAut':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['LivroAut'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['LivroAut'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['LivroAut'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opCliente':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Cliente'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Cliente'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Cliente'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opVenda':
     if sacao=='opSalvarInclusao':
        escreveArq(tf['Venda'], LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
     elif sacao=='opSalvarAlteracao':
        escreveArq(tf['Venda'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
     elif sacao=='opConfirmaExclusao':
        escreveArq(tf['Venda'], repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
  elif sreg=='opUsuario':
     if sacao=='opSalvarAlteracao':
        escreveArq(tf['Usuario'], LinhaReg(sreg), MSG_REGALT, MSG_REGNALT) 

#------------------------------------------------------------------------------
# Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
# nmenu - o numero do menu
# sreg - o tipo de arquivo
#------------------------------------------------------------------------------
def subMenu(nmenu, sreg):
  bSOp=True
  if nmenu == 6:
      while(bSOp):
       menu(nmenu)
       opSubMenu = raw_input()
       if opSubMenu == '1': frmCadastros(sreg, 'opNovo')
       elif opSubMenu == '2': frmCadastros(sreg, 'opPesquisar')
       elif opSubMenu == '3': bSOp=False
       else: print(MSG_ERRO)
  elif nmenu == 7:
      while(bSOp):
       menu(nmenu)
       opSubMenu = raw_input()
       if opSubMenu == '1': 
           btnAcao(sreg, 'opSalvarInclusao') 
           bSOp=False
       elif opSubMenu == '2': bSOp=False
       else: print(MSG_ERRO)
  elif nmenu == 8:
      while(bSOp):
       menu(nmenu)
       opSubMenu = raw_input()
       if opSubMenu == '1': 
          frmCadastros(sreg, 'opAlterar') 
          bSOp=False
       elif opSubMenu == '2': 
          frmCadastros(sreg, 'opExcluir') 
          bSOp=False
       elif opSubMenu == '3': bSOp=False
       else: print(MSG_ERRO)
  elif nmenu == 9:
      while(bSOp):
       menu(nmenu)
       opSubMenu = raw_input()
       if opSubMenu == '1': 
          btnAcao(sreg, 'opSalvarAlteracao') 
          bSOp=False
       elif opSubMenu == '2': bSOp=False
       else: print(MSG_ERRO)
  elif nmenu == 10:
      while(bSOp):
       menu(nmenu)
       opCSubMenu = raw_input()
       if (opCSubMenu=='S') or (opCSubMenu=='s'):
          btnAcao(sreg, 'opConfirmaExclusao')
          bSOp=False
       elif (opCSubMenu=='N') or (opCSubMenu=='n'): bSOp=False
       else: print(MSG_ERRO)
  elif nmenu == 12:
      while(bSOp):
       menu(nmenu)
       opSubMenu = raw_input()
       if opSubMenu == '1': frmConsultas(sreg, 'opPesquisar')
       elif opSubMenu == '2': frmConsultas(sreg, 'opListarTodos')
       elif opSubMenu == '3': bSOp=False
       else: print(MSG_ERRO)
  elif nmenu == 14:
      while(bSOp):
       menu(nmenu)
       opCSubMenu = raw_input()
       if (opCSubMenu=='S') or (opCSubMenu=='s'):
          btnAcao(sreg, 'opSalvarInclusao')
          bSOp=False
          g_SalvarInclusao['valor']=True
       elif (opCSubMenu=='N') or (opCSubMenu=='n'): bSOp=False
       else: print(MSG_ERRO)

#------------------------------------------------------------------------------
# Seleciona o submenu e/ou a tela certa de acordo com numero do menu.
# nmenu - o numero do menu
#------------------------------------------------------------------------------
def usaMenu(num):
  bSOp=True
  if num == 1: # Cadastros 
   while(bSOp):
     menu(2)
     opSubMenu = raw_input()
     if opSubMenu == '1': subMenu(6, 'opAssunto')
     elif opSubMenu == '2': subMenu(6, 'opAutor')
     elif opSubMenu == '3': subMenu(6, 'opEditora')
     elif opSubMenu == '4': subMenu(6, 'opEndereco')
     elif opSubMenu == '5': subMenu(6, 'opIdioma')
     elif opSubMenu == '6': subMenu(6, 'opPais')
     elif opSubMenu == '7': subMenu(6, 'opProfissao')
     elif opSubMenu == '8': subMenu(6, 'opCliente')
     elif opSubMenu == '9': subMenu(6, 'opLivro')
     elif opSubMenu == '10': bSOp=False
     else: print(MSG_ERRO)
  elif num == 2: # Pesquisas 
   while(bSOp):
     menu(3)
     opSubMenu = raw_input()
     if opSubMenu == '1': subMenu(12, 'opAssunto')
     elif opSubMenu == '2': subMenu(12, 'opAutor')
     elif opSubMenu == '3': subMenu(12, 'opEditora')
     elif opSubMenu == '4': subMenu(12, 'opEndereco')
     elif opSubMenu == '5': subMenu(12, 'opIdioma')
     elif opSubMenu == '6': subMenu(12, 'opPais')
     elif opSubMenu == '7': subMenu(12, 'opProfissao')
     elif opSubMenu == '8': subMenu(12, 'opCliente')
     elif opSubMenu == '9': subMenu(12, 'opLivro')
     elif opSubMenu == '10': bSOp=False
     else: print(MSG_ERRO)
  elif num == 3: # Vendas 
   while(bSOp):
     menu(4)
     opSubMenu = raw_input()
     if opSubMenu == '1': subMenu(6, 'opVenda')
     elif opSubMenu == '2': subMenu(12, 'opVenda')
     elif opSubMenu == '3': bSOp=False
     else: print(MSG_ERRO)
  elif num == 4: # Opcoes 
   while(bSOp):
     menu(5)
     opSubMenu = raw_input()
     if opSubMenu == '1': frmAlterarSenha()
     elif opSubMenu == '2': frmSobre()
     elif opSubMenu == '3':
           menu(11)
           opSair = raw_input()
           if (opSair=='S') or (opSair=='s'):
              fechaArqs()
              sys.exit()
     elif opSubMenu == 4: bSOp=False
     else: print(MSG_ERRO)

#------------------------------------------------------------------------------
# Mostra as entradas e as saidas do sistema.
# sreg - o tipo de arquivo
# slinha - o registro com os dados
# nOpcao - indica qual opcao sera mostrada
#------------------------------------------------------------------------------
def mostrarDados(sreg, slinha, nOpcao):
  if sreg=='opAssunto':
     if nOpcao == 1:
          print(rotulo(sreg, 1) + tAssunto['codigo'])
          tAssunto['assunto'] = raw_input(rotulo(sreg, 2))                 
     elif nOpcao == 2:
          print('Codigo     Assunto')
          print('------     -------')         
     elif nOpcao == 3:
          tAssunto['codigo']=copy(slinha, 1, 10)
          tAssunto['assunto']=copy(slinha, 11, 30)
          print(tAssunto['codigo'] + ' ' + tAssunto['assunto'])
  elif sreg=='opAutor':
     if nOpcao == 1:
          print(rotulo(sreg, 1) + tAutor['codigo'])
          tAutor['autor'] = raw_input(rotulo(sreg, 2))                 
     elif nOpcao == 2:
          print('Codigo     Autor')
          print('------     -----')         
     elif nOpcao == 3:
          tAutor['codigo']=copy(slinha, 1, 10)
          tAutor['autor']=copy(slinha, 11, 30)
          print(tAutor['codigo'] + ' ' + tAutor['autor'])
  elif sreg=='opEditora':
     if nOpcao == 1:
          print(rotulo(sreg, 1) + tEditora['codigo'])
          tEditora['editora'] = raw_input(rotulo(sreg, 2))               
     elif nOpcao == 2:
          print('Codigo     Editora')
          print('------     -------')
     elif nOpcao == 3:
          tEditora['codigo']=copy(slinha, 1, 10)
          tEditora['editora']=copy(slinha, 11, 50)
          print(tEditora['codigo'] + ' ' + tEditora['editora'])
  elif sreg=='opEndereco':
     if nOpcao == 1:
          print(rotulo(sreg, 1) + tEndereco['codigo'])
          tEndereco['Logradouro'] = raw_input(rotulo(sreg, 2))       
          tEndereco['bairro'] = raw_input(rotulo(sreg, 3))       
          tEndereco['cep'] = raw_input(rotulo(sreg, 4))       
          tEndereco['cidade'] = raw_input(rotulo(sreg, 5))
          tEndereco['estado'] = raw_input(rotulo(sreg, 6))        
     elif nOpcao == 3: 
          tEndereco['codigo']=string.strip(copy(slinha, 1, 10))
          tEndereco['logradouro']=string.strip(copy(slinha, 11, 40))
          tEndereco['bairro']=string.strip(copy(slinha, 51, 15))
          tEndereco['cep']=string.strip(copy(slinha, 66, 8))
          tEndereco['cidade']=string.strip(copy(slinha, 74, 30))
          tEndereco['estado']=string.strip(copy(slinha, 104, 20))
          print('--------------------')
          print(rotulo(sreg, 1) + tEndereco['codigo'])
          print(rotulo(sreg, 2) + tEndereco['Logradouro'])
          print(rotulo(sreg, 3) + tEndereco['bairro'])
          print(rotulo(sreg, 4) + tEndereco['cep'])
          print(rotulo(sreg, 5) + tEndereco['cidade'])
          print(rotulo(sreg, 6) + tEndereco['estado'])
  elif sreg=='opIdioma':
     if nOpcao == 1:
          print(rotulo(sreg, 1) + tIdioma['codigo'])
          tIdioma['idioma'] = raw_input(rotulo(sreg, 2))        
     elif nOpcao == 2:
          print('Codigo     Idioma')
          print('------     ------')
     elif nOpcao == 3:
          tIdioma['codigo']=copy(slinha, 1, 10)
          tIdioma['idioma']=copy(slinha, 11, 20)
          print(tIdioma['codigo'] + ' ' + tIdioma['idioma'])
  elif sreg=='opPais':
     if nOpcao == 1:
          tPais['pais'] = raw_input(rotulo(sreg, 2))        
     elif nOpcao == 2: 
          print('Codigo Pais')
          print('------ ----')         
     elif nOpcao == 3:
          tPais['codigo']=copy(slinha, 1, 3)
          tPais['pais']=copy(slinha, 4, 50)
          print(tPais['codigo'] + '    ' + tPais['pais'])
  elif sreg=='opProfissao':
     if nOpcao == 1:
          print(rotulo(sreg, 1) + tProfissao['codigo'])
          tProfissao['profissao'] = raw_input(rotulo(sreg, 2))        
     elif nOpcao == 2: 
          print('Codigo     Profissao')
          print('------     ---------')         
     elif nOpcao == 3: 
          tProfissao['codigo']=copy(slinha, 1, 10)
          tProfissao['profissao']=copy(slinha, 11, 50)
          print(tProfissao['codigo'] + ' ' + tProfissao['profissao'])
  elif sreg=='opLivro':
     if nOpcao == 1: 
          tLivro['titulo'] = raw_input(rotulo(sreg, 2))        
          tLivro['edicao']=validaNumero(rotulo(sreg, 3), tLivro['edicao'])
          tLivro['anopubli']=validaNumero(rotulo(sreg, 4), tLivro['anopubli'])
          mostrarSubDados('opLivro', 'opEditora', False)
          tLivro['volume']=validaNumero(rotulo(sreg, 6), tLivro['volume'])
          mostrarSubDados('opLivro', 'opIdioma', False)
          tLivro['npaginas']=validaNumero(rotulo(sreg, 8), tLivro['npaginas'])
          tLivro['preco']=validaNumero(rotulo(sreg, 9), tLivro['preco'])
          tLivro['qtdestoque']=validaNumero(rotulo(sreg, 10), tLivro['qtdestoque'])
     elif nOpcao == 3: 
          tLivro['isbn']=string.strip(copy(slinha, 1, 13))
          tLivro['titulo']=string.strip(copy(slinha, 14, 50))
          tLivro['edicao']=string.strip(copy(slinha, 64, 10))
          tLivro['anopubli']=string.strip(copy(slinha, 74, 10))
          tLivro['codeditora']=string.strip(copy(slinha, 84, 10))
          tLivro['volume']=string.strip(copy(slinha, 94, 10))
          tLivro['codidioma']=string.strip(copy(slinha, 104, 10))
          tLivro['npaginas']=string.strip(copy(slinha, 114, 10))
          tLivro['preco']=string.strip(copy(slinha, 124, 10))
          tLivro['qtdestoque']=string.strip(copy(slinha, 134, 10))
          print('--------------------')
          print(rotulo(sreg, 1) + tLivro['isbn'])
          print(rotulo(sreg, 2) + tLivro['titulo'])
          print(rotulo(sreg, 3) + tLivro['edicao'])
          print(rotulo(sreg, 4) + tLivro['anopubli'])
          print(rotulo(sreg, 5) + tLivro['codeditora'])
          mostrarSubDados('opLivro', 'opEditora', True)
          print(rotulo(sreg, 6) + tLivro['volume'])
          print(rotulo(sreg, 7) + tLivro['codidioma'])
          mostrarSubDados('opLivro', 'opIdioma', True)
          print(rotulo(sreg, 8) + tLivro['npaginas'])
          print(rotulo(sreg, 9) + tLivro['preco'])
          print(rotulo(sreg, 10) + tLivro['qtdestoque'])
          ListarRegLigados(tf['LivroAss'], 'opLivroAss', 1, 13, 14, 10, tLivro['isbn'],
                           tf['Assunto'], 'opAssunto', 1, 4)
          ListarRegLigados(tf['LivroAut'], 'opLivroAut', 1, 13, 14, 10, tLivro['isbn'],
                           tf['Autor'], 'opAutor', 1, 4)
  elif sreg=='opCliente':
     if nOpcao == 1: 
          tCliente['nome'] = raw_input(rotulo(sreg, 2))        
          tCliente['email'] = raw_input(rotulo(sreg, 3))        
          tCliente['identidade'] = raw_input(rotulo(sreg, 4))        
          tCliente['sexo'] = raw_input(rotulo(sreg, 5))        
          tCliente['telefone'] = raw_input(rotulo(sreg, 6))        
          tCliente['dtnascimento']= \
                  validaDataHora(rotulo(sreg, 7), tCliente['dtnascimento'], True)
          mostrarSubDados('opCliente', 'opEndereco', False)
          mostrarSubDados('opCliente', 'opPais', False)
          mostrarSubDados('opCliente', 'opProfissao', False)
     elif nOpcao == 3: 
          tCliente['cpf']=string.strip(copy(slinha, 1, 14))
          tCliente['nome']=string.strip(copy(slinha, 15, 30))
          tCliente['email']=string.strip(copy(slinha, 45, 30))
          tCliente['identidade']=string.strip(copy(slinha, 75, 10))
          tCliente['sexo']=string.strip(copy(slinha, 85, 1))
          tCliente['telefone']=string.strip(copy(slinha, 86, 17))
          tCliente['dtnascimento']=string.strip(copy(slinha, 103, 10))
          tCliente['codendereco']=string.strip(copy(slinha, 113, 10))
          tCliente['codpais']=string.strip(copy(slinha, 123, 3))
          tCliente['codprofissao']=string.strip(copy(slinha, 126, 10))
          print('--------------------')
          print(rotulo(sreg, 1) + tCliente['cpf'])
          print(rotulo(sreg, 2) + tCliente['nome'])
          print(rotulo(sreg, 3) + tCliente['email'])
          print(rotulo(sreg, 4) + tCliente['identidade'])
          print(rotulo(sreg, 5) + tCliente['sexo'])
          print(rotulo(sreg, 6) + tCliente['telefone'])
          print(rotulo(sreg, 7) + tCliente['dtnascimento'])
          print(rotulo(sreg, 8) + tCliente['codendereco'])
          mostrarSubDados('opCliente', 'opEndereco', True)
          print(rotulo(sreg, 9) + tCliente['codpais'])
          mostrarSubDados('opCliente', 'opPais', True)
          print(rotulo(sreg, 10) + tCliente['codprofissao'])
          mostrarSubDados('opCliente', 'opProfissao', True)
  elif sreg=='opVenda':
     if nOpcao == 1: mostrarSubDados('opVenda','opVenda', False)
     elif nOpcao == 2:
          print('DataHoraVenda       CPF            ISBN          '+
          'PrecoVenda')
          print('-------------       ---            ----          '+
          '----------')
     elif nOpcao == 3:
          tVenda['dthrvenda']=copy(slinha, 1, 19)
          tVenda['cpf']=copy(slinha, 20, 14)
          tVenda['isbn']=copy(slinha, 34, 13)
          tVenda['precovenda']=copy(slinha, 47, 10)
          print(tVenda['dthrvenda'] + ' ' + tVenda['cpf'] + ' ' + tVenda['isbn'] + ' ' + 
          tVenda['precovenda'])

#------------------------------------------------------------------------------
# Mostra as sub informcoes de entrada e de saida.
# sreg - o tipo de arquivo
# ssubreg - o subtipo de arquivo
# bSoMostrar - se vai so mostrar na saida 
#------------------------------------------------------------------------------
def mostrarSubDados(sreg, ssubreg, bSoMostrar):
  nMaxTentativas=3
  if sreg=='opLivro':
    if ssubreg=='opEditora':
      if bSoMostrar:
         sRegistro=pesqArq(tf['Editora'],tLivro['codeditora'],1,10,tamReg('opEditora'))
      else:
         sRegistro=validaEntrada(tf['Editora'],ssubreg,1,tLivro['codeditora'],
                    nMaxTentativas,False,'opNumero')
      if sRegistro!='':
        tLivro['codeditora']=string.strip(copy(sRegistro,1,10))
        print ' '+rotulo('opEditora', 2),
        print(copy(sRegistro, g_nPosChave['opEditora'][1], g_nTamChave['opEditora'][1]))
    elif ssubreg=='opIdioma':
      if bSoMostrar:
         sRegistro=pesqArq(tf['Idioma'], tLivro['codidioma'], 1, 10,tamReg('opIdioma'))
      else:
         sRegistro=validaEntrada(tf['Idioma'],ssubreg,1,tLivro['codidioma'],
                    nMaxTentativas,False,'opNumero')
      if sRegistro!='':
        tLivro['codidioma']=string.strip(copy(sRegistro,1,10))
        print ' '+rotulo('opIdioma', 2),
        print(copy(sRegistro, g_nPosChave['opIdioma'][1], g_nTamChave['opIdioma'][1]))
  elif sreg=='opCliente':
    if ssubreg=='opEndereco':
      if bSoMostrar:
         sRegistro=pesqArq(tf['Endereco'], tCliente['codendereco'], 1, 10,
                    tamReg('opEndereco'))
      else:
         sRegistro=validaEntrada(tf['Endereco'],ssubreg,1,tCliente['codendereco'],
                    nMaxTentativas,False,'opNumero')
      if sRegistro!='':
        tCliente['codendereco']=string.strip(copy(sRegistro,1,10))
        print ' '+rotulo('opEndereco', 2),
        print(copy(sRegistro, g_nPosChave['opEndereco'][1], g_nTamChave['opEndereco'][1]))
        print ' '+rotulo('opEndereco', 3),
        print(copy(sRegistro, g_nPosChave['opEndereco'][2], g_nTamChave['opEndereco'][2]))
        print ' '+rotulo('opEndereco', 4),
        print(copy(sRegistro, g_nPosChave['opEndereco'][3], g_nTamChave['opEndereco'][3]))
        print ' '+rotulo('opEndereco', 5),
        print(copy(sRegistro, g_nPosChave['opEndereco'][4], g_nTamChave['opEndereco'][4]))
        print ' '+rotulo('opEndereco', 6),
        print(copy(sRegistro, g_nPosChave['opEndereco'][5], g_nTamChave['opEndereco'][5]))
    elif ssubreg=='opPais':
      if bSoMostrar:
         sRegistro=pesqArq(tf['Pais'], tCliente['codpais'], 1, 3, tamReg('opPais'))
      else:
         sRegistro=validaEntrada(tf['Pais'],ssubreg,1,tCliente['codpais'],
                    nMaxTentativas,False,'opTexto')
      if sRegistro!='':
        tCliente['codpais']=string.strip(copy(sRegistro,1,3))
        print ' '+rotulo('opPais', 2),
        print(copy(sRegistro, g_nPosChave['opPais'][1], g_nTamChave['opPais'][1]))
    elif ssubreg=='opProfissao':
      if bSoMostrar:
         sRegistro=pesqArq(tf['Profissao'], tCliente['codprofissao'], 1, 10,
                    tamReg('opProfissao'))
      else:
         sRegistro=validaEntrada(tf['Profissao'],ssubreg,1,tCliente['codprofissao'],
                    nMaxTentativas,False,'opNumero')
      if sRegistro!='':
        tCliente['codprofissao']=string.strip(copy(sRegistro,1,10))
        print ' '+rotulo('opProfissao', 2),
        print(copy(sRegistro, g_nPosChave['opProfissao'][1], g_nTamChave['opProfissao'][1]))
  elif sreg=='opVenda':
    sRegistro=pesqArq(tf['Livro'], tVenda['isbn'], 1, 13, tamReg('opLivro'))
    if sRegistro!='':
      print ' '+rotulo('opLivro', 2), # Titulo 
      print(copy(sRegistro, g_nPosChave['opLivro'][1], g_nTamChave['opLivro'][1]))
      print ' '+rotulo('opLivro', 9), # Preco 
      sPreco=copy(sRegistro, g_nPosChave['opLivro'][8], g_nTamChave['opLivro'][8])
      g_nPreco['valor'] = float(sPreco)
      print(sPreco)

#------------------------------------------------------------------------------
# Realiza os cadastros dos arquivos que se ligam a outros arquivos.
# sreg - o tipo de arquivo
# sacao - a acao a ser realizada
# sCodigo - um das chaves do arquivo de ligacao
#------------------------------------------------------------------------------
def frmCadLigados(sreg, sacao, sCodigo):
  if sacao=='opNovo':
    nCont=1
    if sreg=='opLivroAss':
      nQtd = int(validaNumero('Quantos assuntos quer cadastrar?: ','0'))
      tf['LivroAss'].seek(0, SEEK_SET)
      while nCont <= nQtd:
        tLivroAss['isbn']=sCodigo
        tLivroAss['codassunto'] = raw_input(rotulo('opLivroAss', 2))      
        slinha=pesqArq(tf['Assunto'], tLivroAss['codassunto'],1,10,tamReg('opAssunto'))
        print ' '+rotulo('opAssunto', 2),
        print(copy(slinha, g_nPosChave['opAssunto'][1], g_nTamChave['opAssunto'][1]))
        pesqLinhaExcluida(tf['LivroAss'], tamReg(sreg))
        subMenu(14, sreg)
        nCont+=1
    elif sreg=='opLivroAut':
      nQtd = int(validaNumero('Quantos autores quer cadastrar?: ','0'))
      tf['LivroAut'].seek(0, SEEK_SET)
      while nCont <= nQtd:
        tLivroAut['isbn']=sCodigo
        tLivroAut['codautor'] = raw_input(rotulo('opLivroAut', 2))
        slinha=pesqArq(tf['Autor'], tLivroAut['codautor'],1,10,tamReg('opAutor'))
        print ' '+rotulo('opAutor', 2),
        print(copy(slinha, g_nPosChave['opAutor'][1], g_nTamChave['opAutor'][1]))
        pesqLinhaExcluida(tf['LivroAut'], tamReg(sreg))
        subMenu(14, sreg)
        nCont+=1
    elif sreg=='opVenda':
      nQtd = int(validaNumero('Quantos livros quer vender?: ','0'))
      nTotalPreco=0
      while nCont <= nQtd:
        slinha=validaEntrada(tf['Livro'],'opLivro',1,tVenda['isbn'],3,False,'opTexto')
        if slinha!='':
          tVenda['isbn']=string.strip(copy(slinha,1,13))
          if validaISBN(tVenda['isbn']):
            mostrarDados(sreg, '', 1)
            tLivro['qtdestoque']=string.strip(copy(slinha,134,10))
            nQtdEstoque = int(tLivro['qtdestoque'])
            if nQtdEstoque > 0:
               nTotalPreco=nTotalPreco + g_nPreco['valor']
               sPreco = str(g_nPreco['valor'])
               tVenda['precovenda']=sPreco
               g_SalvarInclusao['valor']=False
               subMenu(14, sreg)
               if g_SalvarInclusao['valor']:
                  slinha=pesqArq(tf['Livro'], tVenda['isbn'], 1, 13, tamReg('opLivro'))
                  if slinha!='':
                     nQtdEstoque=nQtdEstoque-1
                     tLivro['qtdestoque'] = str(nQtdEstoque)
                     slinha=copy(slinha,1,133)+esp(tLivro['qtdestoque'],10)
                     escreveArq(tf['Livro'], slinha, '', '')
               nCont+=1
            else: print(MSG_SEMESTOQUE)
          else: print(MSG_ISBNINV)
      sTotalPreco = str(nTotalPreco)
      print('Total de ' + rotulo(sreg,4) + sTotalPreco)
  elif sacao=='opExcluir':
    if sreg=='opLivroAss':
       ExcluirRegLigados(tf['LivroAss'], sreg, 1, 13, sCodigo)
    elif sreg=='opLivroAut':
       ExcluirRegLigados(tf['LivroAut'], sreg, 1, 13, sCodigo)

#------------------------------------------------------------------------------
# Realiza a exclusao dos arquivos de ligacao.
# sArq - o arquivo de ligacao
# sreg - o tipo de arquivo de ligacao
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# sChave - a chave a ser excluida
#------------------------------------------------------------------------------
def ExcluirRegLigados(sArq, sreg, nPosChave, nTamChave, sChave):
  slinha='0'
  sArq.seek(0, SEEK_SET)
  while slinha!='':
    slinha = sArq.readline()
    sCodigo=string.strip(copy(slinha,nPosChave,nTamChave))
    if sCodigo==sChave:
       btnAcao(sreg,'opConfirmaExclusao')

#------------------------------------------------------------------------------
# Parte inicial do codigo
#------------------------------------------------------------------------------
def main():     
  if (len(sys.argv) > 1) and (sys.argv[1]=='-cria'):
    abrecriaArqs(False)
  else:
    frmSplash()
    abrecriaArqs(True)
    if frmLogin():
     bopcao = True
     while(bopcao):
       menu(1)
       opmenu = raw_input()
       if (opmenu=='C') or (opmenu=='c'): usaMenu(1)
       elif (opmenu=='P') or (opmenu=='p'): usaMenu(2)
       elif (opmenu=='V') or (opmenu=='v'): usaMenu(3)
       elif (opmenu=='O') or (opmenu=='o'): usaMenu(4)
       else: print(MSG_ERRO)
    else:
     fechaArqs()
     sys.exit()

if __name__ == '__main__':
    main()
