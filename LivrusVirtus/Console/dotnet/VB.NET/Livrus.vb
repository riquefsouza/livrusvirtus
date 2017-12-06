'------------------------------------------------------------------------------
' Sistema integrante do projeto Livrus Virtus.
' Todos os direitos reservados para Henrique F. de Souza.
' Versão programada na linguagem Visual Basic.Net.
'------------------------------------------------------------------------------
' programa Livrus 

Imports System
Imports System.IO
Imports System.Text
Imports Microsoft.VisualBasic

Namespace Livrus

Public Class Livrus 
       Inherits System.Object

  'Declaração de tipos

  Structure regAssunto
   public codigo As string '10
   public assunto As string '30
  End Structure
  Structure regAutor 
   public codigo As string '10
   public autor As string '30
  End Structure
  Structure regEditora 
   public codigo As string '10
   public editora As string '50
  End Structure
  Structure regIdioma 
   public codigo As string '10
   public idioma As string '20
  End Structure
  Structure regUsuario 
   public login As string '10
   public senha As string '10
  End Structure
  Structure regPais 
   public codigo As string '3
   public pais As string '50
  End Structure
  Structure regProfissao 
   public codigo As string '10
   public profissao As string '50
  End Structure
  Structure regLivro 
   public isbn As string '13
   public titulo As string '50
   public edicao As string '10
   public anopubli As string '10
   public codeditora As string '10
   public volume As string '10
   public codidioma As string '10
   public npaginas As string '10
   public preco As string '10
   public qtdestoque As string '10
  End Structure
  Structure regLivroAss 
   public isbn As string '13
   public codassunto As string '10
  End Structure
  Structure regLivroAut 
   public isbn As string '13
   public codautor As string '10
  End Structure
  Structure regCliente 
   public cpf As string '14
   public nome As string '30
   public email As string '30
   public identidade As string '10
   public sexo As string '1
   public telefone As string '17
   public dtnascimento As string '10
   public codendereco As string '10
   public codpais As string '3
   public codprofissao As string '10
  End Structure
  Structure regEndereco 
   public codigo As string '10
   public logradouro As string '40
   public bairro As string '15
   public cep As string '8
   public cidade As string '30
   public estado As string '20
  End Structure
  Structure regVenda 
   public dthrvenda As string '19  'data/hora da venda dd/mm/yyyy hh:mm:ss
   public cpf As string '14
   public isbn As string '13
   public precovenda As string '10
  End Structure

  Enum ctTipo 
    opTexto
    opNumero
    opData
    opDataHora
    opSenha
  End Enum
  Enum ctArqs 
    opAssunto
    opAutor
    opEditora
    opEndereco
    opIdioma
    opPais
    opProfissao
    opCliente
    opLivro
    opLivroAss
    opLivroAut
    opUsuario
    opVenda
  End Enum
  Enum ctAcao 
    opNovo
    opAlterar
    opPesquisar
    opSalvarInclusao
    opSalvarAlteracao
    opExcluir
    opConfirmaExclusao
    opListarTodos
  End Enum

  Dim CRLF As String = "\r\n" 'windows
  Dim TAM_CRLF As Integer = 2
  ' Dim CRLF As String = "\n"
  ' Dim TAM_CRLF As Integer = 1 'unix
  ' Dim CRLF As String = "\r"
  ' Dim TAM_CRLF As Integer = 1 'macintosh

  Dim QTD_MAX_LINHA As Integer = 18
  Dim TAM_MAX_REG As Integer = 145

  Dim MSG_ARQERRO As String = "Erro: O arquivo não pode ser aberto."
  Dim MSG_ERRO As String = "Erro: opção inválida digite de novo."
  Dim MSG_OPCAO As String = "Escolha uma opção: "
  Dim MSG_PRESS As String = "pressione para continuar..."

  Dim MSG_REGINC As String = "registro incluido!"
  Dim MSG_REGNINC As String = "registro não incluido!"
  Dim MSG_REGALT As String = "registro alterado!"
  Dim MSG_REGNALT As String = "registro não alterado!"
  Dim MSG_REGEXC As String = "registro excluido!"
  Dim MSG_REGNEXC As String = "registro não excluido!"
  Dim MSG_REGEXST As String = "registro já existe!"

  Dim MSG_NUMINV As String = "Número inválido ou menor do que 1!"
  Dim MSG_DATAINV As String = "Data inválida!, formato correto (dd/mm/yyyy)"
  Dim MSG_DTHRINV As String = _
		"Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)"
  Dim MSG_ISBNINV As String = "ISBN inválido!"
  Dim MSG_CPFINV As String = "CPF inválido!"
  Dim MSG_SENCONFERE As String = "senha não confere com a senha atual!"
  Dim MSG_SENCONFIRM="nova senha não confere com a senha confirmada!"
  Dim MSG_LOGINENCON As String = "login não encontrado!"
  Dim MSG_SEMESTOQUE As String = "livro não existe no estoque!"

  Dim ARQ_ASSUNTO As String = "assunto.dat"
  Dim ARQ_AUTOR As String = "autor.dat"
  Dim ARQ_EDITORA As String = "editora.dat"
  Dim ARQ_IDIOMA As String = "idioma.dat"
  Dim ARQ_USUARIO As String = "usuario.dat"
  Dim ARQ_PAIS As String = "pais.dat"
  Dim ARQ_PROFISSAO As String = "profissao.dat"
  Dim ARQ_LIVRO As String = "livro.dat"
  Dim ARQ_LIVASS As String = "livroass.dat"
  Dim ARQ_LIVAUT As String = "livroaut.dat"
  Dim ARQ_CLIENTE As String = "cliente.dat"
  Dim ARQ_ENDERECO As String = "endereco.dat"
  Dim ARQ_VENDA As String = "venda.dat"

  Dim TAM_ASSUNTO As Integer = 40
  Dim TAM_AUTOR As Integer = 40
  Dim TAM_EDITORA As Integer = 60
  Dim TAM_IDIOMA As Integer = 30
  Dim TAM_USUARIO As Integer = 20
  Dim TAM_PAIS As Integer = 53
  Dim TAM_PROFISSAO As Integer = 60
  Dim TAM_LIVRO As Integer = 143
  Dim TAM_LIVASS As Integer = 23
  Dim TAM_LIVAUT As Integer = 23
  Dim TAM_CLIENTE As Integer = 135
  Dim TAM_ENDERECO As Integer = 123
  Dim TAM_VENDA As Integer = 56

  'variaveis gerais

  Dim bopcao As Boolean
  Dim opmenu As Char
  Dim g_nPosChave, g_nTamChave As Integer
  Dim g_nPreco As Double
  Dim g_SalvarInclusao As Boolean

  Dim tAssunto As regAssunto
  Dim tAutor As regAutor
  Dim tEditora As regEditora
  Dim tIdioma As regIdioma
  Dim tEndereco As regEndereco
  Dim tPais As regPais
  Dim tProfissao As regProfissao
  Dim tLivro As regLivro
  Dim tLivroAss As regLivroAss
  Dim tLivroAut As regLivroAut
  Dim tCliente As regCliente
  Dim tUsuario As regUsuario
  Dim tVenda As regVenda

  Dim tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, _ 
  tfPais, tfProfissao, tfLivro, tfLivroAss, tfLivroAut, tfCliente, _ 
  tfUsuario, tfVenda As FileStream

'Public Sub New()
'    MyBase.New()
'End Sub

'--- Rotinas básicas --------------------------------------------------------

'------------------------------------------------------------------------------
'Repete um texto um número determinado de vezes.
'sTexto - o texto a ser repetido
'nQtd - a quantidade de vezes
'retorna - o texto repetido
'------------------------------------------------------------------------------
Private function repete(sTexto as string, nQtd as integer) As String
dim ncont as integer
dim sret as string = ""

  for ncont = 1 to nQtd 
    sret = sret & sTexto
  next ncont
  repete = sret
end function
'------------------------------------------------------------------------------
'Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
'sTexto - o texto
'nTam - tamanho máximo do texto
'retorna - o texto com espaços em branco a mais
'------------------------------------------------------------------------------
private function esp(sTexto as string, nTam as integer) as string
dim sret as string

sret = sTexto & repete(" ",nTam-Len(sTexto))
esp = sret
end function
'------------------------------------------------------------------------------
'Faz uma pesquisa relativa de um texto através de um valor chave.
'sTexto - o texto
'sChave - a chave a ser pesquisada
'retorna - se achou ou não a chave dentro do texto
'------------------------------------------------------------------------------
private function strRelativa(sTexto as string, sChave as string) as Boolean
dim nCont, nTamChave, nTamTexto as integer
dim bret as Boolean
dim sPedaco as string

bret = false
nCont = 1
nTamChave = Len(sChave)
  nTamTexto = Len(sTexto)
  if nTamChave <= nTamTexto then
    while nCont <= (nTamTexto-nTamChave+1)
       sPedaco = Mid(sTexto,nCont,nTamChave)
       if sPedaco = sChave then
          bret = true
       end if
       nCont = nCont + 1
    end while
  end if
  strRelativa = bret
end function

'------------------------------------------------------------------------------
'Calcula o modulo11 de um valor qualquer.
'svalor - a string com o número a ser calculado
'ndig - dígito do valor a ser calculado
'retorna - o dígito correto
'------------------------------------------------------------------------------
Private Function modulo11(svalor As String, ndig As Integer) As Integer
Dim ncont As Integer, nsoma As Integer, nstatus As Integer 
Dim nvalor As Integer, npos As Integer
Dim sres As String, slocal As String

 ncont = 0
 while ncont < 11 
   slocal = svalor.Substring(ncont,1) + slocal
   ncont = ncont+1
 end while
 nsoma = 0
 if ndig=1 then
   ncont = 2
 else
   ncont = 1
 end if
 npos = 2
 while ncont < 11
   sres = slocal.Substring(ncont,1)
   nvalor = CInt(sres)
   nsoma = nsoma + (nvalor * npos)
   ncont = ncont+1
   npos = npos+1
 end while
 nsoma = (11 - (nsoma mod 11))

if nsoma > 9 then
  modulo11 = 0
else
  modulo11 = nsoma
end if
End Function
'------------------------------------------------------------------------------
'Validação de um número de CPF qualquer.
'cpf - a mstring com o número do CPF
'retorna - se é valido ou não
'------------------------------------------------------------------------------
Public Function ValidaCPF(cpf As String) As Boolean
Dim sCPF As String

If (cpf.length = 14) Then
  sCPF = cpf.Substring(0, 3) + cpf.Substring(4, 3) + cpf.Substring(8, 3) + _
	 cpf.Substring(12, 2)
  If ((modulo11(sCPF, 1) = CInt(cpf.Substring(12, 1))) And _
     (modulo11(sCPF, 2) = CInt(cpf.Substring(13, 1)))) Then
   ValidaCPF = True
  Else
   ValidaCPF = False
  End If
Else
 ValidaCPF = False
End If
End Function
'------------------------------------------------------------------------------
'Validação de um número ISBN qualquer.
'isbn - a mstring com o número do ISBN
'retorna - se é valido ou não
'------------------------------------------------------------------------------
Public Function ValidaISBN(isbn As String) As Boolean
Dim snum  As String, sdigito As String, sisbn As String
Dim nvalor As Integer, nsoma As Integer, nstatus As Integer, ncont As Integer

If (isbn.length = 13) Then
  sdigito = isbn.Substring(isbn.length()-1, 1)
  sisbn=""
  for ncont=0 to isbn.length()-2
    if isbn.Substring(ncont,1)<>"-" then
      sisbn=sisbn + isbn.Substring(ncont,1)
    end if
  next ncont
  if sdigito = "X" then
    nsoma = 10
  else
    nvalor = CInt(sdigito)
    nsoma = nvalor
  end if
  for ncont = 1 to 9
    snum = sisbn.Substring(ncont-1, 1)
    nvalor = CInt(snum)
    nsoma = nsoma + (nvalor * (11 - ncont))
  next ncont
  If (nsoma mod 11) = 0 Then
    validaISBN = true
  else
    validaISBN = false
  end if
Else
 ValidaISBN = False
End If
End Function
'------------------------------------------------------------------------------
'Esconde a digitação da senha
'retorna - a senha digitada
'------------------------------------------------------------------------------
function digitaSenha(sRotulo as string, nTamSenha as integer) as string
 dim sSenha as string = ""
' dim sLetra as char
' dim ncont as integer

  System.Console.Write(sRotulo)
  sSenha = System.Console.In.ReadLine()

'  ncont  = 0
'  sLetra = "\0"C
'  while (sLetra<>"\r"C) and (ncont < nTamSenha) 
'	sLetra = System.Console.Read()
'	if (sLetra<>"\r"C) then
'	   sSenha = sSenha + sLetra
'	end if
'	ncont = ncont + 1
'  end while
'System.Console.WriteLine()

digitaSenha = sSenha
end function
'------------------------------------------------------------------------------
'Validação de um número qualquer.
'sRotulo - o texto antes de se digitar o número
'sNumero - a String com o valor do número
'retorna - o sNumero
'------------------------------------------------------------------------------
function validaNumero(sRotulo as string, sNumero as string) as string
dim nnum as double
dim nStatus as integer

nStatus = -1
while (nStatus<>0) 
  System.Console.Write(sRotulo)
  sNumero = System.Console.In.ReadLine()
  try
    nnum = CDbl(sNumero)
    if nnum < 1 then
      System.Console.WriteLine(MSG_NUMINV)
    else
      nStatus=0
    end if
  Catch e As Exception
    System.Console.WriteLine(MSG_NUMINV)
  end try
end while
validaNumero = sNumero
end function
'------------------------------------------------------------------------------
'Validação de uma data ou data/hora qualquer.
'sRotulo - o texto antes de se digitar a data/hora
'sDataHora - a String com o valor da data/hora
'bSoData - indica se vai validar somente uma data sem a hora
'retorna - a sDataHora
'------------------------------------------------------------------------------
function validaDataHora(sRotulo as string, sDataHora as string, _
			bSoData as Boolean) as string
dim bvalida, bdatavalida, bhoravalida as boolean
dim sdia, smes, sano, shora, smin, sseg as string
dim ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam as integer

bvalida = false
bdatavalida = false
bhoravalida = false
nudiames = 0
if bSoData=true then 
  ntam=10
else 
  ntam=19
end if
while bvalida=false
  System.Console.Write(sRotulo)
  sDataHora = System.Console.In.ReadLine()
  if len(sDataHora)=ntam then
    sdia = mid(sDataHora,1,2)
    ndia = CInt(sdia)
    smes = mid(sDataHora,4,2)
    nmes = CInt(smes)
    sano = mid(sDataHora,7,4)
    nano = CInt(sano)
    
    if (nano >= 1) and (nano <= 9999) then
      if (nmes >= 1) and (nmes <= 31) then
        select nmes
          case 1, 3, 5, 7, 8, 10, 12
            nudiames = 31
          case 2
            ' ano bissexto 
            if (nano mod 4)=0 then 
              nudiames = 29
            else 
              nudiames = 28
            end if
          case 4, 6, 9, 11
            nudiames = 30
        end select
        if (ndia >=1) and (ndia <=nudiames) then
           bdatavalida = true
        end if
      end if
    end if

    if bSoData then
      if bdatavalida then
        bvalida = true
      else
        System.Console.WriteLine(MSG_DATAINV)
      end if
    else 
      if bdatavalida then
        shora = mid(sDataHora,12,2)
        nhora = CInt(shora)
        smin = mid(sDataHora,15,2)
        nmin = CInt(smin)
        sseg = mid(sDataHora,18,2)
        nseg = CInt(sseg)
      
        if (nhora >= 0) and (nhora <= 23) then
          if (nmin >= 0) and (nmin <= 59) then
            if (nseg >= 0) and (nseg <= 59) then
              bhoravalida = true
            end if
          end if
        end if
      
        if bhoravalida then
          bvalida = true
        else
          System.Console.WriteLine(MSG_DTHRINV)
        end if
      else
        System.Console.WriteLine(MSG_DTHRINV)
      end if
    end if
  else
    if bSoData=true then 
      System.Console.WriteLine(MSG_DATAINV)
    else 
      System.Console.WriteLine(MSG_DTHRINV)
    end if
  end if
end while
validaDataHora = sDataHora
end function
'------------------------------------------------------------------------------
'Retorna a Data e a hora do sistema.
'retorna - a data e a hora
'------------------------------------------------------------------------------
function retDataHora() as string
  retDataHora = DateTime.Now.ToString("dd/MM/yyyy hh:mm:ss")
end function
'------------------------------------------------------------------------------
'Calcula o tamanho do arquivo.
'sArq - o arquivo
'retorna - o tamanho do arquivo
'------------------------------------------------------------------------------
function tamArq(sArq as FileStream) as long
  tamArq = sArq.Length
end function
'------------------------------------------------------------------------------
'Verifica se chegou ao fim do arquivo.
'sArq - o arquivo
'ntam - o tamanho do arquivo
'retorna - se chegou ao fim do arquivo
'------------------------------------------------------------------------------
function fimArq(sArq as FileStream) as Boolean
 if sArq.Position = sArq.Length then
  fimArq = true
 else
  fimArq = false
 end if
end function
'------------------------------------------------------------------------------
'Lê uma linha do arquivo.
'sArq - o arquivo
'nTamLinha - o tamanho da linha
'nTamCRLF - o tamanho do retorno da linha
'npos - posicao dentro do arquivo
'retorna - o texto lido
'------------------------------------------------------------------------------
function lerArq(sArq as FileStream, nTamLinha as integer, _
		nTamCRLF as integer) as string
dim nLidos, ncont as integer
Dim slinha(TAM_MAX_REG) As Byte
Dim slinha2(TAM_MAX_REG) As Char
dim sret as string = ""

'dim sLer as StreamReader = new StreamReader(sArq)
'sret = sLer.ReadLine()

nLidos = sArq.Read(slinha, 0,(nTamLinha + nTamCRLF))

if nLidos <> (nTamLinha + nTamCRLF) then
  sret = ""
else 
  for ncont=0 to (nLidos - nTamCRLF - 1)
    slinha2(ncont)= Convert.ToChar(slinha(ncont))
  next ncont
  sret = new String(slinha2,0,(nLidos - nTamCRLF))
end if

lerArq = sret
end function
'------------------------------------------------------------------------------
'Abre ou cria os arquivos do sistema.
'bAbre - condição para abrir ou criar os arquivos do sistema
'------------------------------------------------------------------------------
sub abrecriaArqs(bAbre as Boolean)
if bAbre then
  if File.Exists(ARQ_ASSUNTO) then
    tfAssunto = new FileStream(ARQ_ASSUNTO,FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_ASSUNTO)
  end if
  if File.Exists(ARQ_AUTOR) then
    tfAutor = new FileStream(ARQ_AUTOR, FileMode.Open, FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_AUTOR)
  end if
  if File.Exists(ARQ_EDITORA) then
    tfEditora = new FileStream(ARQ_EDITORA,FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_EDITORA)
  end if
  if File.Exists(ARQ_IDIOMA) then
    tfIdioma = new FileStream(ARQ_IDIOMA, FileMode.Open, FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_IDIOMA)
  end if
  if File.Exists(ARQ_ENDERECO) then
    tfEndereco= new FileStream(ARQ_ENDERECO,FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_ENDERECO)
  end if
  if File.Exists(ARQ_PAIS) then
    tfPais = new FileStream(ARQ_PAIS, FileMode.Open, FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_PAIS)
  end if
  if File.Exists(ARQ_PROFISSAO) then
    tfProfissao=new FileStream(ARQ_PROFISSAO,FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_PROFISSAO)
  end if
  if File.Exists(ARQ_LIVRO) then
    tfLivro = new FileStream(ARQ_LIVRO, FileMode.Open, FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_LIVRO)
  end if
  if File.Exists(ARQ_LIVASS) then
    tfLivroAss = new FileStream(ARQ_LIVASS, FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_LIVASS)
  end if
  if File.Exists(ARQ_LIVAUT) then
    tfLivroAut = new FileStream(ARQ_LIVAUT, FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_LIVAUT)
  end if
  if File.Exists(ARQ_CLIENTE) then
    tfCliente = new FileStream(ARQ_CLIENTE, FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_CLIENTE)
  end if
  if File.Exists(ARQ_USUARIO) then
    tfUsuario = new FileStream(ARQ_USUARIO, FileMode.Open,FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_USUARIO)
  end if
  if File.Exists(ARQ_VENDA) then
    tfVenda = new FileStream(ARQ_VENDA, FileMode.Open, FileAccess.ReadWrite)
  else
    System.Console.WriteLine(MSG_ARQERRO+" --> "+ARQ_VENDA)
  end if
else
  tfAssunto = new FileStream(ARQ_ASSUNTO,FileMode.Create,FileAccess.ReadWrite)
  tfAutor = new FileStream(ARQ_AUTOR,FileMode.Create,FileAccess.ReadWrite)
  tfEditora = new FileStream(ARQ_EDITORA,FileMode.Create,FileAccess.ReadWrite)
  tfIdioma = new FileStream(ARQ_IDIOMA,FileMode.Create,FileAccess.ReadWrite)
  tfEndereco= new FileStream(ARQ_ENDERECO,FileMode.Create,FileAccess.ReadWrite)
  tfPais = new FileStream(ARQ_PAIS,FileMode.Create,FileAccess.ReadWrite)
  tfProfissao=new FileStream(ARQ_PROFISSAO,FileMode.Create,FileAccess.ReadWrite)
  tfLivro = new FileStream(ARQ_LIVRO,FileMode.Create,FileAccess.ReadWrite)
  tfLivroAss = new FileStream(ARQ_LIVASS,FileMode.Create,FileAccess.ReadWrite)
  tfLivroAut = new FileStream(ARQ_LIVAUT,FileMode.Create,FileAccess.ReadWrite)
  tfCliente = new FileStream(ARQ_CLIENTE,FileMode.Create,FileAccess.ReadWrite)
  tfUsuario = new FileStream(ARQ_USUARIO,FileMode.Create,FileAccess.ReadWrite)
  tfVenda = new FileStream(ARQ_VENDA,FileMode.Create,FileAccess.ReadWrite)
end if

end sub
'------------------------------------------------------------------------------
'Fecha todos os arquivos abertos.
'------------------------------------------------------------------------------
sub fechaArqs()
  tfAssunto.Close()
  tfAutor.Close()
  tfEditora.Close()
  tfIdioma.Close()
  tfEndereco.Close()
  tfPais.Close()
  tfProfissao.Close()
  tfLivro.Close()
  tfLivroAss.Close()
  tfLivroAut.Close()
  tfCliente.Close()
  tfUsuario.Close()
  tfVenda.Close()
end sub
'------------------------------------------------------------------------------
'Pesquisa um registro através de um valor chave num arquivo.
'sArq - o arquivo
'sChave - a chave a ser pesquisada
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'nTamLinha - o tamanho do registro
'retorna - o registro pesquisado
'------------------------------------------------------------------------------
function pesqArq(sArq as FileStream, sChave as string, nPosChave as integer, _
		nTamChave as integer, nTamLinha as integer) as string
  dim sres, slinha as string
  dim bQuebra as Boolean
  dim nPosicao as long

  sres = ""
  slinha = ""
  bQuebra = false
  sArq.Seek(0,SeekOrigin.Begin)
  while (not fimArq(sArq)) and bQuebra = false
    slinha = lerArq(sArq, nTamLinha, TAM_CRLF)
    if slinha<>"" then
  	sres = trim(mid(slinha, nPosChave, nTamChave))
    end if
    if sres=sChave
      bQuebra = true
    end if
  end while
  nPosicao = sArq.Position - (nTamLinha + TAM_CRLF)
  if nPosicao > 0 then
    sArq.Seek(nPosicao, SeekOrigin.Current)
  else
    sArq.Seek(0, SeekOrigin.Begin)
  end if
  if sres<>sChave then
    pesqArq = ""
  else
    pesqArq = mid(slinha, 1, nTamLinha)
  end if
end function
'------------------------------------------------------------------------------
'Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
'sArq - o arquivo
'nTamLinha - o tamanho do registro
'------------------------------------------------------------------------------
sub pesqLinhaExcluida(sArq as FileStream, nTamLinha as integer)
dim sExcluido as string

  sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha)
  if sExcluido="" then
    sArq.Seek(tamArq(sArq),SeekOrigin.Begin)
  end if
end sub
'------------------------------------------------------------------------------
'Pesquisa o maior código num arquivo.
'sArq - o arquivo
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'nTamLinha - o tamanho do registro
'retorna - o maior código
'------------------------------------------------------------------------------
function pesqMaxCod(sArq as FileStream, nPosChave as integer, _
		nTamChave as integer, nTamLinha as integer) as string
  dim sres, slinha as string
  dim bQuebra as Boolean
  dim nMaior, nCod as integer

  sres = ""
  slinha = ""
  bQuebra = false
  nMaior = 0
  sArq.Seek(0,SeekOrigin.Begin)
  while (not fimArq(sArq)) and bQuebra = false
    slinha = lerArq(sArq, nTamLinha, TAM_CRLF)
    if slinha<>"" then
      sres = trim(mid(slinha,nPosChave,nTamChave))
      nCod = CInt(sres)
      if nCod > nMaior then
         nMaior = nCod
      end if
    end if
  end while
  pesqLinhaExcluida(sArq, nTamLinha)
  nCod = (nMaior+1)
  sres = CStr(nCod)

pesqMaxCod = sres
end function
'------------------------------------------------------------------------------
'Grava os registros num determinado arquivo.
'sArq - o arquivo
'sTexto - o registro a ser gravado
'sMsgAcerto - a mensagem caso o registro foi gravado
'sMsgErro - a mensagem caso o registro não foi gravado
'------------------------------------------------------------------------------
sub escreveArq(sArq as FileStream, sTexto as string, sMsgAcerto as string, _
	sMsgErro as string)
  Dim slinha(TAM_MAX_REG) As Byte
  dim ntam, ncont as integer
  try 
    'dim sGravar as StreamWriter = new StreamWriter(sArq)
    sTexto = sTexto + CRLF
    ntam = Len(sTexto)
    for ncont=0 to ntam-1
    	slinha(ncont) = Convert.ToByte(GetChar(sTexto,ncont+1))
    next ncont
    sArq.Write(slinha, 0, ntam)
    'sGravar.WriteLine(sTexto)
    System.Console.WriteLine(sMsgAcerto)
  catch e As Exception
	System.Console.WriteLine(sMsgErro)
  end try
end sub
'------------------------------------------------------------------------------
'Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'retorna - o registro montado
'------------------------------------------------------------------------------
function LinhaReg(sreg as ctArqs) as string
dim slinha as string = ""

if sreg=ctArqs.opAssunto then
   slinha = esp(tAssunto.codigo,10)+esp(tAssunto.assunto,30)
elseif sreg=ctArqs.opAutor then
   slinha = esp(tAutor.codigo,10)+esp(tAutor.autor,30)
elseif sreg=ctArqs.opEditora then
   slinha = esp(tEditora.codigo,10)+esp(tEditora.editora,50)
elseif sreg=ctArqs.opEndereco then
   slinha = esp(tEndereco.codigo,10)+esp(tEndereco.logradouro,40)+ _
   esp(tEndereco.bairro,15)+esp(tEndereco.cep,8)+esp(tEndereco.cidade,30)+ _
   esp(tEndereco.estado,20)
elseif sreg=ctArqs.opIdioma then
   slinha = esp(tIdioma.codigo,10)+esp(tIdioma.idioma,20)
elseif sreg=ctArqs.opPais then 
   slinha = esp(tPais.codigo,3)+esp(tPais.pais,50)
elseif sreg=ctArqs.opProfissao then 
   slinha = esp(tProfissao.codigo,10)+esp(tProfissao.profissao,50)
elseif sreg=ctArqs.opUsuario then 
   slinha = esp(tUsuario.login,10)+esp(tUsuario.senha,10)
elseif sreg=ctArqs.opLivro then 
   slinha = esp(tLivro.isbn,13)+esp(tLivro.titulo,50)+ _
   esp(tLivro.edicao,10)+esp(tLivro.anopubli,10)+esp(tLivro.codeditora,10)+ _
   esp(tLivro.volume,10)+esp(tLivro.codidioma,10)+esp(tLivro.npaginas,10)+ _
   esp(tLivro.preco,10)+esp(tLivro.qtdestoque,10)
elseif sreg=ctArqs.opLivroAss then 
   slinha = esp(tLivroAss.isbn,13)+esp(tLivroAss.codassunto,10)
elseif sreg=ctArqs.opLivroAut then 
   slinha = esp(tLivroAut.isbn,13)+esp(tLivroAut.codautor,10)
elseif sreg=ctArqs.opCliente then 
   slinha = esp(tCliente.cpf,14)+esp(tCliente.nome,30)+ _
   esp(tCliente.email,30)+esp(tCliente.identidade,10)+esp(tCliente.sexo,1)+ _
   esp(tCliente.telefone,17)+esp(tCliente.dtnascimento,10)+ _
   esp(tCliente.codendereco,10)+esp(tCliente.codpais,3)+ _
   esp(tCliente.codprofissao,10)
elseif sreg=ctArqs.opVenda then 
   slinha = esp(tVenda.dthrvenda,19)+esp(tVenda.cpf,14)+ _
   esp(tVenda.isbn,13)+esp(tVenda.precovenda,10)
end if
LinhaReg = slinha
end function
'------------------------------------------------------------------------------
'Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'retorna - o tamanho do registro
'------------------------------------------------------------------------------
function tamReg(sreg as ctArqs) as integer
dim nret as integer = 0

if sreg=ctArqs.opAssunto then 
  nret = TAM_ASSUNTO
elseif sreg=ctArqs.opAutor then 
  nret = TAM_AUTOR
elseif sreg=ctArqs.opEditora then  
  nret = TAM_EDITORA
elseif sreg=ctArqs.opEndereco then 
  nret = TAM_ENDERECO
elseif sreg=ctArqs.opIdioma then 
  nret = TAM_IDIOMA
elseif sreg=ctArqs.opPais then  
  nret = TAM_PAIS
elseif sreg=ctArqs.opProfissao then 
  nret = TAM_PROFISSAO
elseif sreg=ctArqs.opUsuario then 
  nret = TAM_USUARIO
elseif sreg=ctArqs.opLivro then 
  nret = TAM_LIVRO
elseif sreg=ctArqs.opLivroAss then 
  nret = TAM_LIVASS
elseif sreg=ctArqs.opLivroAut then 
  nret = TAM_LIVAUT
elseif sreg=ctArqs.opCliente then 
  nret = TAM_CLIENTE
elseif sreg=ctArqs.opVenda then 
  nret = TAM_VENDA
end if
tamReg = nret
end function
'------------------------------------------------------------------------------
'Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'nNum - indica qual rotulo será retornado
'retorna - o rotulo
'------------------------------------------------------------------------------
function rotulo(sreg as ctArqs, nNum as integer) as string
dim sret as string = ""

if sreg=ctArqs.opAssunto then
  select case nNum
    case 0
      sret = "Assunto(s) não encontrado(s)!"
    case 1
      sret = "Código do assunto: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Assunto: "
      g_nPosChave = 11
      g_nTamChave = 30
  end select   
elseif sreg=ctArqs.opAutor then
  select case nNum
    case 0
      sret = "Autor(es) não encontrado(s)!"
    case 1
      sret = "Código do autor: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Autor: "
      g_nPosChave = 11
      g_nTamChave = 30
  end select   
elseif sreg=ctArqs.opEditora then
  select case nNum
    case 0
      sret = "Editora(s) não encontrada(s)!"
    case 1
      sret = "Código da editora: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Editora: "
      g_nPosChave = 11
      g_nTamChave = 50
  end select   
elseif sreg=ctArqs.opEndereco then
  select case nNum
    case 0
      sret = "Endereço(s) não encontrado(s)!"
    case 1
      sret = "Código do endereço: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Logradouro: "
      g_nPosChave = 11
      g_nTamChave = 40
    case 3
      sret = "Bairro: "
      g_nPosChave = 51
      g_nTamChave = 15
    case 4
      sret = "CEP: "
      g_nPosChave = 66
      g_nTamChave = 8
    case 5
      sret = "Cidade: "
      g_nPosChave = 74
      g_nTamChave = 30
    case 6
      sret = "Estado: "
      g_nPosChave = 104
      g_nTamChave = 20
  end select   
elseif sreg=ctArqs.opIdioma then
  select case nNum
    case 0
      sret = "Idioma(s) não encontrado(s)!"
    case 1
      sret = "Código do idioma: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Idioma: "
      g_nPosChave = 11
      g_nTamChave = 20
  end select   
elseif sreg=ctArqs.opPais then
  select case nNum
    case 0
      sret = "País(es) não encontrado(s)!"
    case 1
      sret = "Código do país: "
      g_nPosChave = 1
      g_nTamChave = 3
    case 2
      sret = "País: "
      g_nPosChave = 4
      g_nTamChave = 50
  end select   
elseif sreg=ctArqs.opProfissao then
  select case nNum
    case 0
      sret = "Profissão(es) não encontrada(s)!"
    case 1
      sret = "Código da profissão: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Profissão: "
      g_nPosChave = 11
      g_nTamChave = 50
  end select   
elseif sreg=ctArqs.opUsuario then
  select case nNum
    case 0
      sret = "login ou senha incorreta, tente de novo!"
    case 1
      sret = "Login: "
      g_nPosChave = 1
      g_nTamChave = 10
    case 2
      sret = "Senha: "
      g_nPosChave = 11
      g_nTamChave = 10
  end select   
elseif sreg=ctArqs.opLivro then
  select case nNum
    case 0
      sret = "Livro(s) não encontrado(s)!"
    case 1
      sret = "ISBN: "
      g_nPosChave = 1
      g_nTamChave = 13
    case 2
      sret = "Título: "
      g_nPosChave = 14
      g_nTamChave = 50
    case 3
      sret = "Edição: "
      g_nPosChave = 64
      g_nTamChave = 10
    case 4
      sret = "Ano de Publicação: "
      g_nPosChave = 74
      g_nTamChave = 10
    case 5
      sret = "Código da editora: "
      g_nPosChave = 84
      g_nTamChave = 10
    case 6
      sret = "Volume: "
      g_nPosChave = 94
      g_nTamChave = 10
    case 7
      sret = "Código do idioma: "
      g_nPosChave = 104
      g_nTamChave = 10
    case 8
      sret = "Número de páginas: "
      g_nPosChave = 114
      g_nTamChave = 10
    case 9
      sret = "Preço: "
      g_nPosChave = 124
      g_nTamChave = 10
    case 10
      sret = "Qtd. Estoque: "
      g_nPosChave = 134
      g_nTamChave = 10
  end select   
elseif sreg=ctArqs.opLivroAss then
  select case nNum
    case 0
      sret = "Assunto(s) não encontrado(s)!"
    case 1
      sret = "ISBN: "
      g_nPosChave = 1
      g_nTamChave = 13
    case 2
      sret = "Código do assunto: "
      g_nPosChave = 14
      g_nTamChave = 10
  end select   
elseif sreg=ctArqs.opLivroAut then
  select case nNum
    case 0
      sret = "Autor(s) não encontrado(s)!"
    case 1
      sret = "ISBN: "
      g_nPosChave = 1
      g_nTamChave = 13
    case 2
      sret = "Código do autor: "
      g_nPosChave = 14
      g_nTamChave = 10
  end select   
elseif sreg=ctArqs.opCliente then
  select case nNum
    case 0
      sret = "Cliente(s) não encontrado(s)!"
    case 1
      sret = "CPF: "
      g_nPosChave = 1
      g_nTamChave = 14
    case 2
      sret = "Nome: "
      g_nPosChave = 15
      g_nTamChave = 30
    case 3
      sret = "E-mail: "
      g_nPosChave = 45
      g_nTamChave = 30
    case 4
      sret = "Identidade: "
      g_nPosChave = 75
      g_nTamChave = 10
    case 5
      sret = "Sexo: "
      g_nPosChave = 85
      g_nTamChave = 1
    case 6
      sret = "Telefone: "
      g_nPosChave = 86
      g_nTamChave = 17
    case 7
      sret = "Dt. Nascimento: "
      g_nPosChave = 103
      g_nTamChave = 10
    case 8
      sret = "Código do endereço: "
      g_nPosChave = 113
      g_nTamChave = 10
    case 9
      sret = "Código do país: "
      g_nPosChave = 123
      g_nTamChave = 3
    case 10
      sret = "Código da Profissão: "
      g_nPosChave = 126
      g_nTamChave = 10
  end select   
elseif sreg=ctArqs.opVenda then
  select case nNum
    case 0
      sret = "Venda(s) não encontrada(s)!"
    case 1
      sret = "Data/Hora venda: "
      g_nPosChave = 1
      g_nTamChave = 19
    case 2
      sret = "CPF: "
      g_nPosChave = 20
      g_nTamChave = 14
    case 3
      sret = "ISBN: "
      g_nPosChave = 34
      g_nTamChave = 13
    case 4
      sret = "Preço de venda: "
      g_nPosChave = 47
      g_nTamChave = 10
  end select   
end if

rotulo = sret
end function
'------------------------------------------------------------------------------
'Indica se continua ou não mostrando um número máximo de linhas.
'nlinha - a linha a ser continuada
'nQtdLinha - a quantidade de linhas a serem mostradas
'retorna - se continua ou não
'------------------------------------------------------------------------------
function ContinuaSN(nlinha as integer, nQtdLinha as integer) as boolean
dim bSOp, bret as Boolean
dim opCSubMenu as char

bret = false
if nlinha > 0 then
  if  (nlinha mod nQtdLinha) = 0 then
    bSOp = true
    while bSOp
      menu(13)
      opCSubMenu = GetChar(System.Console.In.ReadLine(),1)
      if (opCSubMenu="S"C) or (opCSubMenu="s"C) then 
        bSOp = false
      elseif (opCSubMenu="N"C) or (opCSubMenu="n"C) then
        bret = true
        bSOp = false
      else 
        System.Console.WriteLine(MSG_ERRO)
      end if
    end while
  end if
end if

ContinuaSN = bret
end function
'------------------------------------------------------------------------------
'Lista vários registros de acordo com a pesquisa feita.
'sArq - o arquivo
'sreg - o tipo de arquivo
'sChave - a chave a ser pesquisada
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'nTamLinha - o tamanho do registro
'nQtdLinha - a quantidade de linhas a serem mostradas
'retorna - se encontrou algum registro
'------------------------------------------------------------------------------
function ListarTodos(sArq as FileStream, sreg as ctArqs, sChave as string, _
  nPosChave as integer, nTamChave as integer, nTamLinha as integer, _
  nQtdLinha as integer, bPesqRelativa as Boolean) as boolean

  dim bQuebra, bAchou, bRet as Boolean
  dim nCont as integer
  dim sres as string = ""
  dim slinha as string = ""

  bRet = false
  bQuebra = false
  nCont = 0
  mostrarDados(sreg, "", 2)
  sArq.Seek(0,SeekOrigin.Begin)
  while (not fimArq(sArq)) and bQuebra = false
    slinha = lerArq(sArq, nTamLinha, TAM_CRLF)
    if slinha<>"" then
  	if bPesqRelativa then
  	  sres = trim(mid(slinha,nPosChave,nTamChave))
  	  if strRelativa(sres,sChave)=true then
  	    bAchou = true
  	    bRet = true
  	  else
  	    bAchou = false
  	  end if
  	else
  	  bAchou = true
  	  bRet = true
  	end if
  
  	if bAchou then
  	  mostrarDados(sreg, mid(slinha,1,nTamLinha), 3)
  	  ncont = ncont + 1
  	end if
    end if
    bQuebra = ContinuaSN(nCont, nQtdLinha)
  end while

ListarTodos = bRet
end function
'------------------------------------------------------------------------------
'Lista vários registros entre arquivos de acordo com a pesquisa feita.
'sArq1 - o arquivo de ligação
'sreg1 - o tipo de arquivo de ligação
'nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
'nTamChave1 - o tamanho da primeira chave no arquivo de ligação
'nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
'nTamChave2 - o tamanho da segunda chave do arquivo de ligação
'sChave - a chave a ser pesquisada no arquivo de ligação
'sArq2 - o arquivo a ser pesquisado
'sreg2 - o tipo de arquivo a ser pesquisado
'nPosChave3 - a posicao inicial da chave do arquivo pesquisado
'nQtdLinha - a quantidade de linhas a serem mostradas
'------------------------------------------------------------------------------
sub ListarRegLigados(sArq1 as FileStream, sreg1 as ctArqs, _
nPosChave1 as integer, nTamChave1 as integer, nPosChave2 as integer, _
nTamChave2 as integer, sChave as string, sArq2 as FileStream, _
sreg2 as ctArqs, nPosChave3 as integer, nQtdLinha as integer)
  dim slinha1 as string = ""
  dim bQuebra, bRet as Boolean
  dim nCont as integer
  dim sCodigo1, sCodigo2, slinha2 as string

  bRet = false
  nCont = 0
  bQuebra = false
  mostrarDados(sreg2, "", 2)
  sArq1.Seek(0,SeekOrigin.Begin)
  while (not fimArq(sArq1)) and bQuebra = false
    slinha1 = lerArq(sArq1, tamReg(sreg1), TAM_CRLF)
    if slinha1<>"" then
  	sCodigo1 = trim(mid(slinha1,nPosChave1,nTamChave1))
  	if sCodigo1=sChave then
  	  sCodigo2 = Trim(mid(slinha1,nPosChave2,nTamChave2))
  	  slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2))
  	  mostrarDados(sreg2, mid(slinha2, 1, tamReg(sreg2)), 3)
  	  bRet = true
  	  nCont = nCont + 1
  	end if
    end if
    bQuebra = ContinuaSN(nCont, nQtdLinha)
  end while
  if bRet=false then
     System.Console.WriteLine(rotulo(sreg2,0))
  end if
end sub

'------------------------------------------------------------------------------
'Valida a entrada de registros de acordo com a pesquisa feita.
'sArq - o arquivo
'sreg - o tipo de arquivo
'nTexto - o numero do rótulo da entrada
'sEntrada - a chave a ser pesquisada e validada
'nTentativas - o número máximo de tentativas
'bPesqRelativa - indica se vai realizar uma pesquisa relativa
'bTipoEntrada - indica o tipo de entrada
'retorna - o registro pesquisado e validado
'------------------------------------------------------------------------------
function validaEntrada(sArq as FileStream, sreg as ctArqs, nTexto as integer, _
  sEntrada as string, nTentativas as integer, _
  bPesqRelativa as Boolean, bTipoEntrada as ctTipo) as string 
dim bQuebra as Boolean
dim sres, sTexto, sMsgErro, sLocal as string
dim ncont, nPosChave, nTamChave, nTamLinha as integer

sres = ""
sLocal = sEntrada

nTamLinha = tamReg(sreg)
sMsgErro = rotulo(sreg,0)
sTexto = rotulo(sreg,nTexto)
nPosChave = g_nPosChave
nTamChave = g_nTamChave

ncont = 1
bQuebra = false
  while (bQuebra=false) and (ncont <= nTentativas)
    if bTipoEntrada=ctTipo.opTexto then
      System.Console.Write(sTexto)
      sLocal = System.Console.In.ReadLine()
    elseif bTipoEntrada=ctTipo.opNumero then
       sLocal = validaNumero(sTexto,sLocal)
    elseif bTipoEntrada=ctTipo.opData then
       sLocal = validaDataHora(sTexto,sLocal,true)
    elseif bTipoEntrada=ctTipo.opDataHora then
       sLocal = validaDataHora(sTexto,sLocal,false)
    elseif bTipoEntrada=ctTipo.opSenha then
       sLocal = digitaSenha(sTexto, 10)
    end if

    if bPesqRelativa then
       if ListarTodos(sArq, sreg, sLocal, nPosChave, nTamChave, nTamLinha, _
          QTD_MAX_LINHA, true) then
          sres = " "
       end if
    else
       sres = pesqArq(sArq, sLocal, nPosChave, nTamChave, nTamLinha)
    end if
    
    if sres = "" then
      System.Console.WriteLine(sMsgErro)
    else
      bQuebra = true
    end if

    ncont = ncont + 1
  end while
validaEntrada = sres
end function
'------------------------------------------------------------------------------
'Mostra a tela de splash do sistema.
'------------------------------------------------------------------------------
sub frmSplash()
dim cont as integer

 System.Console.WriteLine("*---------------------------------------" + _
 "-------------------------------------*")
 System.Console.WriteLine("| LL    II VV   VV RRRRR  UU  UU   SSSS " + _
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |")
 System.Console.WriteLine("| LL    II  VV VV  RR   R UU  UU  SS    " + _
 " VV VV  II RR   R  TT  UU  UU  SS    |")
 System.Console.WriteLine("| LL    II   VVV   RRRRR  UU  UU    SS  " + _
 "  VVV   II RRRRR   TT  UU  UU    SS  |")
 System.Console.WriteLine("| LLLLL II    V    RR   R  UUUU  SSSS   " + _
 "   V    II RR   R  TT   UUUU  SSSS   |")
 System.Console.WriteLine("*---------------------------------------" + _
 "-------------------------------------*")
 for cont = 1 to 18
   System.Console.WriteLine()
 next cont
 System.Console.Write(MSG_PRESS)
 System.Console.In.ReadLine()
end sub
'------------------------------------------------------------------------------
'Mostra a tela de sobre do sistema.
'------------------------------------------------------------------------------
sub frmSobre()
dim cont as integer

 System.Console.WriteLine("*------------------------------------------------------------*")
 System.Console.WriteLine("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |")
 System.Console.WriteLine("|  LL        II   VV     VV   RR     R  UU    UU  SS         |")
 System.Console.WriteLine("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |")
 System.Console.WriteLine("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |")
 System.Console.WriteLine("|  LLLL      II      VVV      RR RR     UU    UU        SS   |")
 System.Console.WriteLine("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |")
 System.Console.WriteLine("|                                                            |")
 System.Console.WriteLine("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |")
 System.Console.WriteLine("|   VV     VV   II  RR     R     TT     UU    UU  SS         |")
 System.Console.WriteLine("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |")
 System.Console.WriteLine("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |")
 System.Console.WriteLine("|      VVV      II  RR RR        TT     UU    UU        SS   |")
 System.Console.WriteLine("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |")
 System.Console.WriteLine("|                                                            |")
 System.Console.WriteLine("|                                               Versao 1.0.0 |")
 System.Console.WriteLine("| Sistema integrante do projeto Livrus Virtus.               |")
 System.Console.WriteLine("| Todos os direitos reservados para Henrique F. de Souza.    |")
 System.Console.WriteLine("| Versao programada na linguagem Visual Basic.NET.           |")
 System.Console.WriteLine("*------------------------------------------------------------*")
 for cont = 1 to 4 
   System.Console.WriteLine()
 next cont
 System.Console.Write(MSG_PRESS)
 System.Console.In.ReadLine()
end sub
'------------------------------------------------------------------------------
'Mostra a tela de login do sistema.
'retorna - se o login foi validado corretamente
'------------------------------------------------------------------------------
function frmLogin() as Boolean
dim bret as Boolean
dim slinha as string

  bret = false
  System.Console.WriteLine("*--------------------------------------------------------------*")
  System.Console.WriteLine("| Login do sistema                                             |")
  System.Console.WriteLine("*--------------------------------------------------------------*")
  slinha = validaEntrada(tfUsuario, ctArqs.opUsuario, 1, tUsuario.login, 3, _
		false, ctTipo.opTexto)
  if slinha<>"" then
    slinha = validaEntrada(tfUsuario, ctArqs.opUsuario, 2, tUsuario.senha, 3, _
             false, ctTipo.opSenha)
    if slinha<>"" then
      tUsuario.login = Trim(mid(slinha, 1, 10))
      tUsuario.senha = Trim(mid(slinha, 11, 10))
      bret = true
    end if
  end if
  System.Console.WriteLine()
  frmLogin = bret
end function
'------------------------------------------------------------------------------
'Mostra os menus do sistema.
'num - o número do menu
'------------------------------------------------------------------------------
sub menu(num as integer)
 if num=1 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=2 then
   System.Console.WriteLine("*---------------------------------*")
   System.Console.WriteLine("| 01. Cadastro de Assuntos        |")
   System.Console.WriteLine("| 02. Cadastro de Autores         |")
   System.Console.WriteLine("| 03. Cadastro de Editoras        |")
   System.Console.WriteLine("| 04. Cadastro de Endereços       |")
   System.Console.WriteLine("| 05. Cadastro de Idiomas         |")
   System.Console.WriteLine("| 06. Cadastro de Países          |")
   System.Console.WriteLine("| 07. Cadastro de Profissões      |")
   System.Console.WriteLine("| 08. Cadastro de Clientes        |")
   System.Console.WriteLine("| 09. Cadastro de Livros          |")
   System.Console.WriteLine("| 10. Voltar ao menu              |")
   System.Console.WriteLine("*---------------------------------*")
 elseif num=3 then
   System.Console.WriteLine("*---------------------------------*")
   System.Console.WriteLine("| 01. Consulta de Assuntos        |")
   System.Console.WriteLine("| 02. Consulta de Autores         |")
   System.Console.WriteLine("| 03. Consulta de Editoras        |")
   System.Console.WriteLine("| 04. Consulta de Endereços       |")
   System.Console.WriteLine("| 05. Consulta de Idiomas         |")
   System.Console.WriteLine("| 06. Consulta de Países          |")
   System.Console.WriteLine("| 07. Consulta de Profissões      |")
   System.Console.WriteLine("| 08. Consulta de Clientes        |")
   System.Console.WriteLine("| 09. Consulta de Livros          |")
   System.Console.WriteLine("| 10. Voltar ao menu              |")
   System.Console.WriteLine("*---------------------------------*")
 elseif num=4 then
   System.Console.WriteLine("*---------------------------------*")
   System.Console.WriteLine("| 01. Vender Livros               |")
   System.Console.WriteLine("| 02. Vendas Realizadas           |")
   System.Console.WriteLine("| 03. Voltar ao menu              |")
   System.Console.WriteLine("*---------------------------------*")
 elseif num=5 then
   System.Console.WriteLine("*---------------------------------*")
   System.Console.WriteLine("| 01. Alterar senha               |")
   System.Console.WriteLine("| 02. Sobre o sistema             |")
   System.Console.WriteLine("| 03. Sair do sistema             |")
   System.Console.WriteLine("| 04. Voltar ao menu              |")
   System.Console.WriteLine("*---------------------------------*")
 elseif num=6 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=7 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| (1) Salvar inclusão       (2) Voltar ao menu                 |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=8 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=9 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| (1) Salvar alteração      (2) Voltar ao menu                 |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=10 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| Certeza de excluir? (S/N)                                    |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=11 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| Deseja sair do sistema? (S/N)                                |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=12 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=13 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| Deseja continuar? (S/N)                                      |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 elseif num=14 then
   System.Console.WriteLine("*--------------------------------------------------------------*")
   System.Console.WriteLine("| Salvar inclusão (S/N)                                        |")
   System.Console.WriteLine("*--------------------------------------------------------------*")
 end if
 System.Console.Write(MSG_OPCAO)
end sub
'------------------------------------------------------------------------------
'Realiza os cadastros de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'sacao - a ação a ser realizada
'------------------------------------------------------------------------------
sub frmCadastros(sreg as ctArqs, sacao as ctAcao)
dim slinha as string = ""

if sreg=ctArqs.opAssunto then
   if sacao=ctAcao.opNovo then
     tAssunto.codigo = pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg))
     mostrarDados(sreg, "", 1)
     subMenu(7, sreg)
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,ctTipo.opNumero)
      if slinha<>"" then
    	mostrarDados(sreg, "", 2)
    	mostrarDados(sreg, slinha, 3)
    	subMenu(8, sreg)
      end if
   elseif sacao=ctAcao.opAlterar then
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opAutor then
   if sacao=ctAcao.opNovo then
     tAutor.codigo = pesqMaxCod(tfAutor, 1, 10, tamReg(sreg))
     mostrarDados(sreg, "", 1)
     subMenu(7, sreg)
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,false,ctTipo.opNumero)
     if slinha<>"" then
       mostrarDados(sreg, "", 2)
       mostrarDados(sreg, slinha, 3)
       subMenu(8, sreg)
     end if
   elseif sacao=ctAcao.opAlterar then
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opEditora then
   if sacao=ctAcao.opNovo then
     tEditora.codigo = pesqMaxCod(tfEditora, 1, 10, tamReg(sreg))
     mostrarDados(sreg, "", 1)
     subMenu(7, sreg)
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,false,ctTipo.opNumero)
     if slinha<>"" then
       mostrarDados(sreg, "", 2)
       mostrarDados(sreg, slinha, 3)
       subMenu(8, sreg)
     end if
   elseif sacao=ctAcao.opAlterar then
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opEndereco then
   if sacao=ctAcao.opNovo then
     tEndereco.codigo = pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg))
     mostrarDados(sreg, "", 1)
     subMenu(7, sreg)
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1, _
              false,ctTipo.opNumero)
     if slinha<>"" then
       mostrarDados(sreg, "", 2)
       mostrarDados(sreg, slinha, 3)
       subMenu(8, sreg)
     end if
   elseif sacao=ctAcao.opAlterar then
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opIdioma then
   if sacao=ctAcao.opNovo then
     tIdioma.codigo = pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg))
     mostrarDados(sreg, "", 1)
     subMenu(7, sreg)
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,false,ctTipo.opNumero)
     if slinha<>"" then
       mostrarDados(sreg, "", 2)
       mostrarDados(sreg, slinha, 3)
       subMenu(8, sreg)
     end if
   elseif sacao=ctAcao.opAlterar then
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opPais then
   if sacao=ctAcao.opNovo then
     System.Console.Write(rotulo(sreg, 1))
     tPais.codigo = System.Console.In.ReadLine()
     slinha = pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg))
     if slinha<>"" then
       pesqLinhaExcluida(tfPais, tamReg(sreg))
       mostrarDados(sreg, "", 1)
       subMenu(7, sreg)
     else 
       System.Console.WriteLine(MSG_REGEXST)
     end if 
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, ctTipo.opTexto)
     if slinha<>"" then
       mostrarDados(sreg, "", 2)
       mostrarDados(sreg, slinha, 3)
       subMenu(8, sreg)
     end if 
   elseif sacao=ctAcao.opAlterar then
     System.Console.WriteLine(rotulo(sreg, 1) + tPais.codigo)
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opProfissao then
   if sacao=ctAcao.opNovo then
     tProfissao.codigo = pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg))
     mostrarDados(sreg, "", 1)
     subMenu(7, sreg)
   elseif sacao=ctAcao.opPesquisar then
     slinha = validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1, _
              false,ctTipo.opNumero)
     if slinha<>"" then
       mostrarDados(sreg, "", 2)
       mostrarDados(sreg, slinha, 3)
       subMenu(8, sreg)
     end if
   elseif sacao=ctAcao.opAlterar then
     mostrarDados(sreg, "", 1)
     subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
     subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opLivro then
   if sacao=ctAcao.opNovo then
      System.Console.Write(rotulo(sreg, 1))
      tLivro.isbn = System.Console.In.ReadLine()
      if ValidaISBN(tLivro.isbn) then
        slinha = pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg))
        if slinha="" then
          pesqLinhaExcluida(tfLivro, tamReg(sreg))
          mostrarDados(sreg, "", 1)
          subMenu(7, sreg)
          frmCadLigados(ctArqs.opLivroAss, ctAcao.opNovo, tLivro.isbn)
          frmCadLigados(ctArqs.opLivroAut, ctAcao.opNovo, tLivro.isbn)
        else 
          System.Console.WriteLine(MSG_REGEXST)
        end if
      else 
        System.Console.WriteLine(MSG_ISBNINV)
      end if
   elseif sacao=ctAcao.opPesquisar then
      slinha = validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,ctTipo.opTexto)
      if slinha<>"" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end if
   elseif sacao=ctAcao.opAlterar then
      System.Console.WriteLine(rotulo(sreg, 1) + tLivro.isbn)
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
      frmCadLigados(ctArqs.opLivroAss, ctAcao.opExcluir, tLivro.isbn)
      System.Console.WriteLine("Assuntos dos livros excluídos, inclua novos!")
      frmCadLigados(ctArqs.opLivroAss, ctAcao.opNovo, tLivro.isbn)
      frmCadLigados(ctArqs.opLivroAut, ctAcao.opExcluir, tLivro.isbn)
      System.Console.WriteLine("Autores dos livros excluídos, inclua novos!")
      frmCadLigados(ctArqs.opLivroAut, ctAcao.opNovo, tLivro.isbn)
   elseif sacao=ctAcao.opExcluir then
      subMenu(10, sreg)
      System.Console.WriteLine("Assuntos dos livros sendo excluídos!")
      frmCadLigados(ctArqs.opLivroAss, ctAcao.opExcluir, tLivro.isbn)
      System.Console.WriteLine("Autores dos livros sendo excluídos!")
      frmCadLigados(ctArqs.opLivroAut, ctAcao.opExcluir, tLivro.isbn)
   end if
elseif sreg=ctArqs.opCliente then
   if sacao=ctAcao.opNovo then
      System.Console.Write(rotulo(sreg, 1))
      tCliente.cpf = System.Console.In.ReadLine()
      if ValidaCPF(tCliente.cpf) then
        slinha = pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg))
        if slinha="" then
          pesqLinhaExcluida(tfCliente, tamReg(sreg))
          mostrarDados(sreg, "", 1)
          subMenu(7, sreg)
        else 
          System.Console.WriteLine(MSG_REGEXST)
        end if 
      else 
        System.Console.WriteLine(MSG_CPFINV)
      end if 
   elseif sacao=ctAcao.opPesquisar then
      slinha = validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,ctTipo.opTexto)
      if slinha<>"" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end if
   elseif sacao=ctAcao.opAlterar then
      System.Console.WriteLine(rotulo(sreg, 1) + tCliente.cpf)
      mostrarDados(sreg, "", 1)
      subMenu(9, sreg)
   elseif sacao=ctAcao.opExcluir then
      subMenu(10, sreg)
   end if
elseif sreg=ctArqs.opVenda then
   if sacao=ctAcao.opNovo then
      tVenda.dthrvenda = retDataHora()
      System.Console.WriteLine(rotulo(sreg, 1) + tVenda.dthrvenda)
      slinha = pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg))
      if slinha="" then
        slinha = validaEntrada(tfCliente,ctArqs.opCliente,1,tVenda.cpf,3, _
        	 false,ctTipo.opTexto)
        if slinha<>"" then
          tVenda.cpf = mid(slinha,1,14).Trim()
          if ValidaCPF(tVenda.cpf) then
             System.Console.Write(" " + rotulo(ctArqs.opCliente, 2)) 'Nome
             System.Console.WriteLine(mid(slinha, g_nPosChave, g_nTamChave))
             frmCadLigados(ctArqs.opVenda, ctAcao.opNovo, tVenda.cpf)
          else 
             System.Console.WriteLine(MSG_CPFINV)
          end if
        end if
      else 
        System.Console.WriteLine(MSG_REGEXST)
      end if 
   elseif sacao=ctAcao.opPesquisar then
      slinha = validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1, _
      	  false,ctTipo.opDataHora)
      if slinha<>"" then
        mostrarDados(sreg, "", 2)
        mostrarDados(sreg, slinha, 3)
        subMenu(8, sreg)
      end if
   end if
end if

end sub
'------------------------------------------------------------------------------
'Realiza as consultas de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'sacao - a ação a ser realizada
'------------------------------------------------------------------------------
sub frmConsultas(sreg as ctArqs, sacao as ctAcao)
 dim slinha as string = ""

if sreg=ctArqs.opAssunto then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfAssunto, sreg, "", 0, 0, tamReg(sreg), _
                   QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opAutor then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfAutor, sreg, "", 0, 0, tamReg(sreg), _
                   QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opEditora then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfEditora, sreg, "", 0, 0, tamReg(sreg), _
                   QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opEndereco then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1, _
    	  true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfEndereco, sreg, "", 0, 0, tamReg(sreg), _
       3, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opIdioma then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfIdioma, sreg, "", 0, 0, tamReg(sreg), _
       QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opPais then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfPais, sreg, "", 0, 0, tamReg(sreg), _
                   QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if 
  end if
elseif sreg=ctArqs.opProfissao then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1, _
    	 true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfProfissao, sreg, "", 0, 0, tamReg(sreg), _
                   QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opLivro then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfLivro, sreg, "", 0, 0, tamReg(sreg), _
                  1, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opCliente then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfCliente, sreg, "", 0, 0, tamReg(sreg), _
                   1, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
elseif sreg=ctArqs.opVenda then
  if sacao=ctAcao.opPesquisar then
    slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,ctTipo.opTexto)
  elseif sacao=ctAcao.opListarTodos then
    if ListarTodos(tfVenda, sreg, "", 0, 0, tamReg(sreg), _
                   QTD_MAX_LINHA, false) = false then
      System.Console.WriteLine(rotulo(sreg, 0))
    end if
  end if
end if
if slinha="" then
   System.Console.Write("")
end if
end sub
'------------------------------------------------------------------------------
'Mostra a tela de alteração de senha do sistema e realiza a alteração.
'------------------------------------------------------------------------------
sub frmAlterarSenha()
dim bQuebra as Boolean
dim sres, sSenhaAtual, sNovaSenha, sConfirmaSenha as string
dim nopcao as integer

sSenhaAtual = ""
sNovaSenha = ""
sConfirmaSenha = ""

System.Console.WriteLine(rotulo(ctArqs.opUsuario, 1) + tUsuario.login)
nopcao = 1
bQuebra = false
while bQuebra=false
  select case nopcao
   case 1
      sSenhaAtual = digitaSenha("Senha Atual: ", 10)
      if sSenhaAtual<>tUsuario.senha then
        System.Console.WriteLine(MSG_SENCONFERE)
        bQuebra = true
      else 
        nopcao = 2
      end if
   case 2
      sNovaSenha = digitaSenha("Nova Senha: ", 10)
      sConfirmaSenha = digitaSenha("Confirma Senha: ", 10)
      if sNovaSenha<>sConfirmaSenha then
        System.Console.WriteLine(MSG_SENCONFIRM)
        bQuebra = true
      else 
        nopcao = 3
      end if
   case 3
      sres = pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(ctArqs.opUsuario))
      if sres="" then
        System.Console.WriteLine(MSG_LOGINENCON)
      else 
        tUsuario.senha = sConfirmaSenha
        subMenu(9,ctArqs.opUsuario)
        bQuebra = true
      end if  
  end select
end while
end sub
'------------------------------------------------------------------------------
'Executa uma ação de gravação de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'sacao - a ação a ser realizada
'------------------------------------------------------------------------------
sub btnAcao(sreg as ctArqs, sacao as ctAcao)
if sreg=ctArqs.opAssunto then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opAutor then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opEditora then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opEndereco then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opIdioma then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opPais then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opProfissao then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	 escreveArq(tfProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opLivro then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opLivroAss then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opLivroAut then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opCliente then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opVenda then
   if sacao=ctAcao.opSalvarInclusao then
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   elseif sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   elseif sacao=ctAcao.opConfirmaExclusao then
	  escreveArq(tfVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC)
   end if
elseif sreg=ctArqs.opUsuario then
   if sacao=ctAcao.opSalvarAlteracao then
	  escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   end if
end if
end sub
'------------------------------------------------------------------------------
'Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
'nmenu - o número do menu
'sreg - o tipo de arquivo
'------------------------------------------------------------------------------
sub subMenu(nmenu as integer, sreg as ctArqs)
dim opSubMenu as string
dim opCSubMenu as char
dim bSOp as Boolean

bSOp = true
select case nmenu
 case 6
    while bSOp
      menu(nmenu)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
        case "1"
          frmCadastros(sreg, ctAcao.opNovo)
        case "2" 
          frmCadastros(sreg, ctAcao.opPesquisar)
        case "3" 
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
    end while
 case 7
    while bSOp
      menu(nmenu)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
        case "1"
          btnAcao(sreg, ctAcao.opSalvarInclusao) 
          bSOp = false 
        case "2"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
    end while
 case 8
    while bSOp
      menu(nmenu)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
	case "1"
          frmCadastros(sreg, ctAcao.opAlterar) 
          bSOp = false 
	case "2"
          frmCadastros(sreg, ctAcao.opExcluir) 
          bSOp = false 
	case "3"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
    end while
 case 9
    while bSOp
      menu(nmenu)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
        case "1"
          btnAcao(sreg, ctAcao.opSalvarAlteracao) 
          bSOp = false 
        case "2"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
    end while
 case 10
    while bSOp
      menu(nmenu)
      opCSubMenu = GetChar(System.Console.In.ReadLine(),1)
      if (opCSubMenu="S"C) or (opCSubMenu="s"C) then
        btnAcao(sreg, ctAcao.opConfirmaExclusao)
        bSOp = false
      elseif (opCSubMenu="N"C) or (opCSubMenu="n"C) then
        bSOp = false
      else 
        System.Console.WriteLine(MSG_ERRO)
      end if
    end while
 case 12
    while bSOp
      menu(nmenu)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
        case "1"
          frmConsultas(sreg, ctAcao.opPesquisar)
        case "2"
          frmConsultas(sreg, ctAcao.opListarTodos)
        case "3"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
    end while
 case 14
    while bSOp
      menu(nmenu)
      opCSubMenu = GetChar(System.Console.In.ReadLine(),1)
      if (opCSubMenu="S"C) or (opCSubMenu="s"C) then
        btnAcao(sreg, ctAcao.opSalvarInclusao)
        bSOp = false
        g_SalvarInclusao = true
      elseif (opCSubMenu="N"C) or (opCSubMenu="n"C) then
        bSOp = false
      else 
        System.Console.WriteLine(MSG_ERRO)
      end if 
    end while
end select

end sub
'------------------------------------------------------------------------------
'Seleciona o submenu e/ou a tela certa de acordo com número do menu.
'nmenu - o número do menu
'------------------------------------------------------------------------------
sub usaMenu(num as integer)
dim opSubMenu as string
dim bSOp as Boolean
dim opSair as char

 bSOp = true
 if num = 1 then 'Cadastros
   while bSOp
      menu(2)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
        case "1"
          subMenu(6, ctArqs.opAssunto)
        case "2"
          subMenu(6, ctArqs.opAutor)
        case "3"
          subMenu(6, ctArqs.opEditora)
        case "4"
          subMenu(6, ctArqs.opEndereco)
        case "5"
          subMenu(6, ctArqs.opIdioma)
        case "6"
          subMenu(6, ctArqs.opPais)
        case "7"
          subMenu(6, ctArqs.opProfissao)
        case "8"
          subMenu(6, ctArqs.opCliente)
        case "9"
          subMenu(6, ctArqs.opLivro)
        case "10"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
   end while
 elseif num = 2 then 'Pesquisas
   while bSOp
      menu(3)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
        case "1"
          subMenu(12, ctArqs.opAssunto)
        case "2"
          subMenu(12, ctArqs.opAutor)
        case "3"
          subMenu(12, ctArqs.opEditora)
        case "4"
          subMenu(12, ctArqs.opEndereco)
        case "5"
          subMenu(12, ctArqs.opIdioma)
        case "6"
          subMenu(12, ctArqs.opPais)
        case "7"
          subMenu(12, ctArqs.opProfissao)
        case "8"
          subMenu(12, ctArqs.opCliente)
        case "9"
          subMenu(12, ctArqs.opLivro)
        case "10"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
   end while
 elseif num = 3 then 'Vendas
   while bSOp
      menu(4)
      opSubMenu = System.Console.In.ReadLine()
      select case opSubMenu
	case "1"
          subMenu(6, ctArqs.opVenda)
        case "2"
          subMenu(12, ctArqs.opVenda)
        case "3"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
      end select
   end while
 elseif num = 4 then 'Opcoes
   while bSOp
     menu(5)
     opSubMenu = System.Console.In.ReadLine()
     select case opSubMenu
        case "1"
          frmAlterarSenha()
        case "2"
          frmSobre()
        case "3"
          menu(11)
          opSair = GetChar(System.Console.In.ReadLine(),1)
          if (opSair="S"C) or (opSair="s"C) then
            fechaArqs()
            System.Environment.Exit(0)
          end if
        case "4"
          bSOp = false
        case else 
          System.Console.WriteLine(MSG_ERRO)
     end select
   end while
 end if
end sub
'------------------------------------------------------------------------------
'Mostra as entradas e as saídas do sistema.
'sreg - o tipo de arquivo
'slinha - o registro com os dados
'nOpcao - indica qual opção será mostrada
'------------------------------------------------------------------------------
sub mostrarDados(sreg as ctArqs, slinha as string, nOpcao as integer)
if sreg=ctArqs.opAssunto then
  select case nOpcao
    case 1
    	System.Console.WriteLine(rotulo(sreg, 1) + tAssunto.codigo)
    	System.Console.Write(rotulo(sreg, 2))
    	tAssunto.assunto = System.Console.In.ReadLine()
    case 2
    	System.Console.WriteLine("Código     Assunto")
    	System.Console.WriteLine("------     -------")
    case 3
    	tAssunto.codigo = Trim(mid(slinha, 1, 10))
    	tAssunto.assunto = Trim(mid(slinha, 11, 30))
    	System.Console.WriteLine(esp(tAssunto.codigo,10) + " " + _
    					   esp(tAssunto.assunto,30))
  end select
elseif sreg=ctArqs.opAutor then
  select case nOpcao
      case 1
      	System.Console.WriteLine(rotulo(sreg, 1) + tAutor.codigo)
      	System.Console.Write(rotulo(sreg, 2))
      	tAutor.autor = System.Console.In.ReadLine()
      case 2
      	System.Console.WriteLine("Código     Autor")
      	System.Console.WriteLine("------     -----")
      case 3
      	tAutor.codigo = Trim(mid(slinha, 1, 10))
      	tAutor.autor = Trim(mid(slinha, 11, 30))
      	System.Console.WriteLine(esp(tAutor.codigo,10)+" "+esp(tAutor.autor,30))
  end select
elseif sreg=ctArqs.opEditora then
  select case nOpcao
    case 1
    	System.Console.WriteLine(rotulo(sreg, 1) + tEditora.codigo)
    	System.Console.Write(rotulo(sreg, 2))
    	tEditora.editora = System.Console.In.ReadLine()
    case 2
    	System.Console.WriteLine("Código     Editora")
    	System.Console.WriteLine("------     -------")
    case 3
    	tEditora.codigo = Trim(mid(slinha, 1, 10))
    	tEditora.editora = Trim(mid(slinha, 11, 50))
    	System.Console.WriteLine(esp(tEditora.codigo,10)+" "+ _
    					   esp(tEditora.editora,50))
  end select
elseif sreg=ctArqs.opEndereco then
  select case nOpcao
    case 1
    	System.Console.WriteLine(rotulo(sreg, 1) + tEndereco.codigo)
    	System.Console.Write(rotulo(sreg, 2))
    	tEndereco.logradouro = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 3))
    	tEndereco.bairro = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 4))
    	tEndereco.cep = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 5))
    	tEndereco.cidade = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 6))
    	tEndereco.estado = System.Console.In.ReadLine()
    case 3
    	tEndereco.codigo = Trim(mid(slinha, 1, 10))
    	tEndereco.logradouro = Trim(mid(slinha, 11, 40))
    	tEndereco.bairro = Trim(mid(slinha, 51, 15))
    	tEndereco.cep = Trim(mid(slinha, 66, 8))
    	tEndereco.cidade = Trim(mid(slinha, 74, 30))
    	tEndereco.estado = Trim(mid(slinha, 104, 20))
    	System.Console.WriteLine("--------------------")
    	System.Console.WriteLine(rotulo(sreg, 1) + tEndereco.codigo)
    	System.Console.WriteLine(rotulo(sreg, 2) + tEndereco.logradouro)
    	System.Console.WriteLine(rotulo(sreg, 3) + tEndereco.bairro)
    	System.Console.WriteLine(rotulo(sreg, 4) + tEndereco.cep)
    	System.Console.WriteLine(rotulo(sreg, 5) + tEndereco.cidade)
    	System.Console.WriteLine(rotulo(sreg, 6) + tEndereco.estado)
  end select
elseif sreg=ctArqs.opIdioma then
   select case nOpcao
    case 1
    	System.Console.WriteLine(rotulo(sreg, 1) + tIdioma.codigo)
    	System.Console.Write(rotulo(sreg, 2))
    	tIdioma.idioma = System.Console.In.ReadLine()
    case 2
    	System.Console.WriteLine("Código     Idioma")
    	System.Console.WriteLine("------     ------")
    case 3
    	tIdioma.codigo = Trim(mid(slinha, 1, 10))
    	tIdioma.idioma = Trim(mid(slinha, 11, 20))
    	System.Console.WriteLine(esp(tIdioma.codigo,10) + " " + _
    					   esp(tIdioma.idioma,20))
  end select
elseif sreg=ctArqs.opPais then
  select case nOpcao
    case 1
    	System.Console.Write(rotulo(sreg, 2))
    	tPais.pais = System.Console.In.ReadLine()
    case 2
    	System.Console.WriteLine("Código País")
    	System.Console.WriteLine("------ ----")
    case 3
    	tPais.codigo = Trim(mid(slinha, 1, 3))
    	tPais.pais = Trim(mid(slinha, 4, 50))
    	System.Console.WriteLine(esp(tPais.codigo,3)+"    "+esp(tPais.pais,50))
  end select
elseif sreg=ctArqs.opProfissao then
  select case nOpcao
    case 1
    	System.Console.WriteLine(rotulo(sreg, 1) + tProfissao.codigo)
    	System.Console.WriteLine(rotulo(sreg, 2))
    	tProfissao.profissao = System.Console.In.ReadLine()
    case 2
    	System.Console.WriteLine("Código     Profissão")
    	System.Console.WriteLine("------     ---------")
    case 3
    	tProfissao.codigo = Trim(mid(slinha, 1, 10))
    	tProfissao.profissao = Trim(mid(slinha, 11, 50))
    	System.Console.WriteLine(esp(tProfissao.codigo,10)+" "+ _
    			esp(tProfissao.profissao,50))
  end select
elseif sreg=ctArqs.opLivro then
  select case nOpcao
    case 1
    	System.Console.Write(rotulo(sreg, 2))
    	tLivro.titulo = System.Console.In.ReadLine()
    	tLivro.edicao = validaNumero(rotulo(sreg, 3), tLivro.edicao)
    	tLivro.anopubli = validaNumero(rotulo(sreg, 4), tLivro.anopubli)
    	mostrarSubDados(ctArqs.opLivro, ctArqs.opEditora, false)
    	tLivro.volume = validaNumero(rotulo(sreg, 6), tLivro.volume)
    	mostrarSubDados(ctArqs.opLivro, ctArqs.opIdioma, false)
    	tLivro.npaginas = validaNumero(rotulo(sreg, 8), tLivro.npaginas)
    	tLivro.preco = validaNumero(rotulo(sreg, 9), tLivro.preco)
    	tLivro.qtdestoque = validaNumero(rotulo(sreg, 10), tLivro.qtdestoque)
    case 3
    	tLivro.isbn = Trim(mid(slinha, 1, 13))
    	tLivro.titulo = Trim(mid(slinha, 14, 50))
    	tLivro.edicao = Trim(mid(slinha, 64, 10))
    	tLivro.anopubli = Trim(mid(slinha, 74, 10))
    	tLivro.codeditora = Trim(mid(slinha, 84, 10))
    	tLivro.volume = Trim(mid(slinha, 94, 10))
    	tLivro.codidioma = Trim(mid(slinha, 104, 10))
    	tLivro.npaginas = Trim(mid(slinha, 114, 10))
    	tLivro.preco = Trim(mid(slinha, 124, 10))
    	tLivro.qtdestoque = Trim(mid(slinha, 134, 10))
    	System.Console.WriteLine("--------------------")
    	System.Console.WriteLine(rotulo(sreg, 1) + tLivro.isbn)
    	System.Console.WriteLine(rotulo(sreg, 2) + tLivro.titulo)
    	System.Console.WriteLine(rotulo(sreg, 3) + tLivro.edicao)
    	System.Console.WriteLine(rotulo(sreg, 4) + tLivro.anopubli)
    	System.Console.WriteLine(rotulo(sreg, 5) + tLivro.codeditora)
    	mostrarSubDados(ctArqs.opLivro, ctArqs.opEditora, true)
    	System.Console.WriteLine(rotulo(sreg, 6) + tLivro.volume)
    	System.Console.WriteLine(rotulo(sreg, 7) + tLivro.codidioma)
    	mostrarSubDados(ctArqs.opLivro, ctArqs.opIdioma, true)
    	System.Console.WriteLine(rotulo(sreg, 8) + tLivro.npaginas)
    	System.Console.WriteLine(rotulo(sreg, 9) + tLivro.preco)
    	System.Console.WriteLine(rotulo(sreg, 10) + tLivro.qtdestoque)
    	ListarRegLigados(tfLivroAss, ctArqs.opLivroAss, 1, 13, 14, 10, _
               tLivro.isbn, tfAssunto, ctArqs.opAssunto, 1, 4)
    	ListarRegLigados(tfLivroAut, ctArqs.opLivroAut, 1, 13, 14, 10, _
               tLivro.isbn, tfAutor, ctArqs.opAutor, 1, 4)
  end select
elseif sreg=ctArqs.opCliente then
  select case nOpcao
    case 1
    	System.Console.Write(rotulo(sreg, 2))
    	tCliente.nome = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 3))
    	tCliente.email = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 4))
    	tCliente.identidade = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 5))
    	tCliente.sexo = System.Console.In.ReadLine()
    	System.Console.Write(rotulo(sreg, 6))
    	tCliente.telefone = System.Console.In.ReadLine()
    	tCliente.dtnascimento = _
		validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true)
    	mostrarSubDados(ctArqs.opCliente, ctArqs.opEndereco, false)
    	mostrarSubDados(ctArqs.opCliente, ctArqs.opPais, false)
    	mostrarSubDados(ctArqs.opCliente, ctArqs.opProfissao, false)
    case 3
    	tCliente.cpf = Trim(mid(slinha, 1, 14))
    	tCliente.nome = Trim(mid(slinha, 15, 30))
    	tCliente.email = Trim(mid(slinha, 45, 30))
    	tCliente.identidade = Trim(mid(slinha, 75, 10))
    	tCliente.sexo = Trim(mid(slinha, 85, 1))
    	tCliente.telefone = Trim(mid(slinha, 86, 17))
    	tCliente.dtnascimento = Trim(mid(slinha, 103, 10))
    	tCliente.codendereco = Trim(mid(slinha, 113, 10))
    	tCliente.codpais = Trim(mid(slinha, 123, 3))
    	tCliente.codprofissao = Trim(mid(slinha, 126, 10))
    	System.Console.WriteLine("--------------------")
    	System.Console.WriteLine(rotulo(sreg, 1) + tCliente.cpf)
    	System.Console.WriteLine(rotulo(sreg, 2) + tCliente.nome)
    	System.Console.WriteLine(rotulo(sreg, 3) + tCliente.email)
    	System.Console.WriteLine(rotulo(sreg, 4) + tCliente.identidade)
    	System.Console.WriteLine(rotulo(sreg, 5) + tCliente.sexo)
    	System.Console.WriteLine(rotulo(sreg, 6) + tCliente.telefone)
    	System.Console.WriteLine(rotulo(sreg, 7) + tCliente.dtnascimento)
    	System.Console.WriteLine(rotulo(sreg, 8) + tCliente.codendereco)
    	mostrarSubDados(ctArqs.opCliente, ctArqs.opEndereco, true)
    	System.Console.WriteLine(rotulo(sreg, 9) + tCliente.codpais)
    	mostrarSubDados(ctArqs.opCliente, ctArqs.opPais, true)
    	System.Console.WriteLine(rotulo(sreg, 10) + tCliente.codprofissao)
    	mostrarSubDados(ctArqs.opCliente, ctArqs.opProfissao, true)
  end select
elseif sreg=ctArqs.opVenda then
  select case nOpcao
    case 1 
      mostrarSubDados(ctArqs.opVenda,ctArqs.opVenda, false)
    case 2
      System.Console.WriteLine( _
      "DataHoraVenda       CPF            ISBN          PreçoVenda")
      System.Console.WriteLine( _
      "-------------       ---            ----          ----------")
    case 3
      tVenda.dthrvenda = Trim(mid(slinha, 1, 19))
      tVenda.cpf = Trim(mid(slinha, 20, 14))
      tVenda.isbn = Trim(mid(slinha, 34, 13))
      tVenda.precovenda = Trim(mid(slinha, 47, 10))
      System.Console.WriteLine(esp(tVenda.dthrvenda,19)+" "+ _
      esp(tVenda.cpf,14)+" "+esp(tVenda.isbn,13)+" "+esp(tVenda.precovenda,10))
  end select
end if

end sub
'------------------------------------------------------------------------------
'Mostra as sub informções de entrada e de saída.
'sreg - o tipo de arquivo
'ssubreg - o subtipo de arquivo
'bSoMostrar - se vai só mostrar na saída
'------------------------------------------------------------------------------
Sub mostrarSubDados(sreg as ctArqs, ssubreg as ctArqs, bSoMostrar as Boolean)
Dim sRegistro, sPreco As string
dim nMaxTentativas as integer

nMaxTentativas = 3
if sreg=ctArqs.opLivro then
  if ssubreg=ctArqs.opEditora then
    if bSoMostrar then
       sRegistro = pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(ctArqs.opEditora))
    else
       sRegistro = validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora, _
    			  nMaxTentativas,false,ctTipo.opNumero)
    end if
    if sRegistro<>"" then
      tLivro.codeditora = Trim(mid(sRegistro,1,10))
      System.Console.Write(" "+rotulo(ctArqs.opEditora, 2))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
    end if
  elseif ssubreg=ctArqs.opIdioma then
    if bSoMostrar then
       sRegistro = pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(ctArqs.opIdioma))
    else
       sRegistro = validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma, _
    			  nMaxTentativas,false,ctTipo.opNumero)
    end if
    if sRegistro<>"" then
      tLivro.codidioma = Trim(mid(sRegistro,1,10))
      System.Console.Write(" "+rotulo(ctArqs.opIdioma, 2))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
    end if
  end if
elseif sreg=ctArqs.opCliente then
  if ssubreg=ctArqs.opEndereco then
    if bSoMostrar then
       sRegistro = pesqArq(tfEndereco, tCliente.codendereco, 1, 10, _
    			  tamReg(ctArqs.opEndereco))
    else
       sRegistro = validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco, _
    			  nMaxTentativas,false,ctTipo.opNumero)
    end if
    if sRegistro<>"" then
      tCliente.codendereco = Trim(mid(sRegistro,1,10))
      System.Console.Write(" "+rotulo(ctArqs.opEndereco, 2))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
      System.Console.Write(" "+rotulo(ctArqs.opEndereco, 3))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
      System.Console.Write(" "+rotulo(ctArqs.opEndereco, 4))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
      System.Console.Write(" "+rotulo(ctArqs.opEndereco, 5))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
      System.Console.Write(" "+rotulo(ctArqs.opEndereco, 6))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
    end if
  elseif ssubreg=ctArqs.opPais then
    if bSoMostrar then
       sRegistro = pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(ctArqs.opPais))
    else
       sRegistro = validaEntrada(tfPais,ssubreg,1,tCliente.codpais, _
    			  nMaxTentativas,false,ctTipo.opTexto)
    end if
    if sRegistro<>"" then
      tCliente.codpais = Trim(mid(sRegistro,1,3))
      System.Console.Write(" "+rotulo(ctArqs.opPais, 2))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
    end if
  elseif ssubreg=ctArqs.opProfissao then
    if bSoMostrar then
       sRegistro = pesqArq(tfProfissao, tCliente.codprofissao, 1, 10, _
    			  tamReg(ctArqs.opProfissao))
    else
       sRegistro = validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao, _
    			  nMaxTentativas,false,ctTipo.opNumero)
    end if
    if sRegistro<>"" then
      tCliente.codprofissao = Trim(mid(sRegistro,1,10))
      System.Console.Write(" "+rotulo(ctArqs.opProfissao, 2))
      System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
    end if
  end if
elseif sreg=ctArqs.opVenda then
  sRegistro = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(ctArqs.opLivro))
  if sRegistro<>"" then
    System.Console.Write(" "+rotulo(ctArqs.opLivro, 2)) 'Titulo
    System.Console.WriteLine(mid(sRegistro, g_nPosChave, g_nTamChave))
    System.Console.Write(" "+rotulo(ctArqs.opLivro, 9)) 'Preco
    sPreco = mid(sRegistro, g_nPosChave, g_nTamChave)
    g_nPreco = CDbl(sPreco)
    System.Console.WriteLine(sPreco)
  end if
end if
end sub
'------------------------------------------------------------------------------
'Realiza os cadastros dos arquivos que se ligam a outros arquivos.
'sreg - o tipo de arquivo
'sacao - a ação a ser realizada
'sCodigo - um das chaves do arquivo de ligação
'------------------------------------------------------------------------------
sub frmCadLigados(sreg as ctArqs, sacao as ctAcao, sCodigo as String)
dim nQtd, nCont, nQtdEstoque as integer
dim nTotalPreco as double
dim slinha, sTotalPreco, sPreco as string
dim sQtd as string = ""

if sacao=ctAcao.opNovo then
  nCont = 1
  if sreg=ctArqs.opLivroAss then
    sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",sQtd)
    nQtd = CInt(sQtd)
    tfLivroAss.Seek(0, SeekOrigin.Begin)
    while (nCont <= nQtd) 
      tLivroAss.isbn = sCodigo
      System.Console.Write(rotulo(ctArqs.opLivroAss, 2))
      tLivroAss.codassunto = System.Console.In.ReadLine()
      slinha = pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(ctArqs.opAssunto))
      System.Console.Write(" "+rotulo(ctArqs.opAssunto, 2))
      System.Console.WriteLine(mid(slinha, g_nPosChave, g_nTamChave))
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg))
      subMenu(14, sreg)
      nCont = nCont + 1
    end while
  elseif sreg=ctArqs.opLivroAut then
    sQtd = validaNumero("Quantos autores quer cadastrar?: ",sQtd)
    nQtd = CInt(sQtd)
    tfLivroAut.Seek(0, SeekOrigin.Begin)
    while (nCont <= nQtd) 
      tLivroAut.isbn = sCodigo
      System.Console.Write(rotulo(ctArqs.opLivroAut, 2))
      tLivroAut.codautor = System.Console.In.ReadLine()
      slinha = pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(ctArqs.opAutor))
      System.Console.Write(" "+rotulo(ctArqs.opAutor, 2))
      System.Console.WriteLine(mid(slinha, g_nPosChave, g_nTamChave))
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg))
      subMenu(14, sreg)
      nCont = nCont + 1
    end while
  elseif sreg=ctArqs.opVenda then
    sPreco = ""
    sTotalPreco = ""
    sQtd = validaNumero("Quantos livros quer vender?: ",sQtd)
    nQtd = CInt(sQtd)
    nTotalPreco = 0
    while (nCont <= nQtd) 
      slinha = validaEntrada(tfLivro,ctArqs.opLivro,1,tVenda.isbn,3,false,ctTipo.opTexto)
      if slinha<>"" then
    	tVenda.isbn = Trim(mid(slinha,1,13))
    	if ValidaISBN(tVenda.isbn) then
    	  mostrarDados(sreg, "", 1)
    	  tLivro.qtdestoque = mid(slinha,134,10).Trim()
    	  nQtdEstoque = CInt(tLivro.qtdestoque)
    	  if nQtdEstoque > 0 then
            nTotalPreco = nTotalPreco + g_nPreco
            sPreco = CStr(g_nPreco)
            tVenda.precovenda = sPreco
            g_SalvarInclusao = false
            subMenu(14, sreg)
            if g_SalvarInclusao then
              slinha = pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(ctArqs.opLivro))
              if slinha<>"" then
                 nQtdEstoque = nQtdEstoque-1
                 tLivro.qtdestoque = nQtdEstoque.ToString()
                 slinha=mid(slinha,1,133) + esp(tLivro.qtdestoque,10)
                 escreveArq(tfLivro, slinha, "", "")
              end if
            end if
            nCont = nCont + 1
    	  else 
            System.Console.WriteLine(MSG_SEMESTOQUE)
          end if
    	else 
          System.Console.WriteLine(MSG_ISBNINV)
        end if
      end if
    end while
    sTotalPreco = CStr(nTotalPreco)
    System.Console.WriteLine("Total de "+rotulo(sreg,4)+sTotalPreco)
  end if
elseif sacao=ctAcao.opExcluir then
  if sreg=ctArqs.opLivroAss then
    ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo)
  elseif sreg=ctArqs.opLivroAut then
    ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo)
  end if
end if

end sub
'------------------------------------------------------------------------------
'Realiza a exclusão dos arquivos de ligação.
'sArq - o arquivo de ligação
'sreg - o tipo de arquivo de ligação
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'sChave - a chave a ser excluida
'------------------------------------------------------------------------------
sub ExcluirRegLigados(sArq as FileStream, sreg as ctArqs, _
    nPosChave as integer, nTamChave as integer, sChave as string) 
  dim slinha as string = ""
  dim sCodigo as string

  sArq.Seek(0, SeekOrigin.Begin)
  while (not fimArq(sArq))
    slinha = lerArq(sArq, tamReg(sreg), TAM_CRLF)
    if slinha<>"" then
      sCodigo = Trim(mid(slinha,nPosChave,nTamChave))
      if sCodigo=sChave then
        btnAcao(sreg,ctAcao.opConfirmaExclusao)
      end if 
    end if
  end while

end sub

<STAThread()> Shared Sub Main(ByVal CmdArgs() As String)
  Dim cl As New Livrus()

  If CmdArgs.Length > 0 then
    If CmdArgs(0)="-cria" Then
      cl.abrecriaArqs(false)
    End If 
  else
    cl.frmSplash()
    cl.abrecriaArqs(true)
    if cl.frmLogin() then
      cl.bopcao = true
      while cl.bopcao
        cl.menu(1)
        cl.opmenu = GetChar(System.Console.In.ReadLine(),1)
        if (cl.opmenu="C"C) or (cl.opmenu="c"C) then
          cl.usaMenu(1)
        elseif (cl.opmenu="P"C) or (cl.opmenu="p"C) then
          cl.usaMenu(2)
        elseif (cl.opmenu="V"C) or (cl.opmenu="v"C) then
          cl.usaMenu(3)
        elseif (cl.opmenu="O"C) or (cl.opmenu="o"C) then
          cl.usaMenu(4)
        else 
          System.Console.WriteLine(cl.MSG_ERRO)
        end if
      end while
    else
      cl.fechaArqs()
      System.Environment.Exit(0)
    end if
  End If
  System.Environment.Exit(0)
End Sub

End Class

End NameSpace
