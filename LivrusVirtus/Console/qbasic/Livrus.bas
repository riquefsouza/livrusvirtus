'------------------------------------------------------------------------------
' Sistema integrante do projeto Livrus Virtus.
' Todos os direitos reservados para Henrique F. de Souza.
' Vers∆o programada na linguagem qbasic.
'------------------------------------------------------------------------------
' programa Livrus


'--- Rotinas b†sicas ---------------------------------------------------------
DECLARE FUNCTION Trim$ (sTexto AS STRING)
DECLARE FUNCTION repete$ (sTexto AS STRING, nQtd AS INTEGER)
DECLARE FUNCTION esp$ (sTexto AS STRING, ntam AS INTEGER)
DECLARE FUNCTION zeros$ (sTexto AS STRING, ntam AS INTEGER)
DECLARE FUNCTION strRelativa! (sTexto AS STRING, sChave AS STRING)
DECLARE FUNCTION modulo11! (svalor AS STRING, ndig AS INTEGER)
DECLARE FUNCTION validaCPF! (cpf AS STRING)
DECLARE FUNCTION validaISBN! (isbn AS STRING)
DECLARE FUNCTION digitaSenha$ (sRotulo AS STRING, nTamSenha AS INTEGER)
DECLARE FUNCTION validaNumero$ (sRotulo AS STRING, sNumero AS STRING)
DECLARE FUNCTION validaDataHora$ (sRotulo AS STRING, sDataHora AS STRING, bSoData AS INTEGER)
DECLARE FUNCTION retDataHora$ ()

'--- Rotinas de manipulaá∆o de arquivos --------------------------------------
DECLARE FUNCTION tamArq! (sArq AS INTEGER)
DECLARE SUB abreArqs (bAbre AS INTEGER)
DECLARE SUB fechaArqs ()
DECLARE FUNCTION pesqArq$ (sArq AS INTEGER, sChave AS STRING, nPosChave AS INTEGER, nTamChave AS INTEGER, nTamLinha AS INTEGER)
DECLARE SUB pesqLinhaExcluida (sArq AS INTEGER, nTamLinha AS INTEGER)
DECLARE FUNCTION pesqMaxCod$ (sArq AS INTEGER, nPosChave AS INTEGER, nTamChave AS INTEGER, nTamLinha AS INTEGER)
DECLARE SUB escreveArq (sArq AS INTEGER, sTexto AS STRING, sMsgAcerto AS STRING, sMsgErro AS STRING)

'--- Rotinas de implementaá∆o do sistema e de interface ----------------------
DECLARE FUNCTION LinhaReg$ (sreg AS INTEGER)
DECLARE FUNCTION tamReg! (sreg AS INTEGER)
DECLARE FUNCTION rotulo$ (sreg AS INTEGER, nNum AS INTEGER)
DECLARE FUNCTION ContinuaSN! (nlinha AS INTEGER, nQtdLinha AS INTEGER)
DECLARE FUNCTION ListarTodos! (sArq AS INTEGER, sreg AS INTEGER, sChave AS STRING, nPosChave AS INTEGER, nTamChave AS INTEGER, nTamLinha AS INTEGER, nQtdLinha AS INTEGER, bPesqRelativa AS INTEGER)
DECLARE SUB ListarRegLigados (sArq1 AS INTEGER, sreg1 AS INTEGER, nPosChave1 AS INTEGER, nTamChave1 AS INTEGER, nPosChave2 AS INTEGER, nTamChave2 AS INTEGER, sChave AS STRING, sArq2 AS INTEGER, sreg2 AS INTEGER, nPosChave3 AS INTEGER, nQtdLinha AS  _
INTEGER)
DECLARE FUNCTION validaEntrada$ (sArq AS INTEGER, sreg AS INTEGER, nTexto AS INTEGER, sEntrada AS STRING, nTentativas AS INTEGER, bPesqRelativa AS INTEGER, bTipoEntrada AS INTEGER)
DECLARE SUB frmSplash ()
DECLARE SUB frmSobre ()
DECLARE FUNCTION frmLogin! ()
DECLARE SUB menu (num AS INTEGER)
DECLARE SUB frmCadastros (sreg AS INTEGER, sacao AS INTEGER)
DECLARE SUB frmConsultas (sreg AS INTEGER, sacao AS INTEGER)
DECLARE SUB frmAlterarSenha ()
DECLARE SUB btnAcao (sreg AS INTEGER, sacao AS INTEGER)
DECLARE SUB subMenu (nmenu AS INTEGER, sreg AS INTEGER)
DECLARE SUB usaMenu (num AS INTEGER)
DECLARE SUB mostrarDados (sreg AS INTEGER, slinha AS STRING, nOpcao AS INTEGER)
DECLARE SUB mostrarSubDados (sreg AS INTEGER, ssubreg AS INTEGER, bSoMostrar AS INTEGER)
DECLARE SUB frmCadLigados (sreg AS INTEGER, sacao AS INTEGER, sCodigo AS STRING)
DECLARE SUB ExcluirRegLigados (sArq AS INTEGER, sreg AS INTEGER, nPosChave AS INTEGER, nTamChave AS INTEGER, sChave AS STRING)

' tipos

TYPE regAssunto
   codigo AS STRING * 10
   assunto AS STRING * 30
END TYPE
TYPE regAutor
   codigo AS STRING * 10
   autor AS STRING * 30
END TYPE
TYPE regEditora
   codigo AS STRING * 10
   editora AS STRING * 50
END TYPE
TYPE regIdioma
   codigo AS STRING * 10
   idioma AS STRING * 20
END TYPE
TYPE regUsuario
   login AS STRING * 10
   senha AS STRING * 10
END TYPE
TYPE regPais
   codigo AS STRING * 3
   pais AS STRING * 50
END TYPE
TYPE regProfissao
   codigo AS STRING * 10
   profissao AS STRING * 50
END TYPE
TYPE regLivro
   isbn AS STRING * 13
   titulo AS STRING * 50
   edicao AS STRING * 10
   anopubli AS STRING * 10
   codeditora AS STRING * 10
   volume AS STRING * 10
   codidioma AS STRING * 10
   npaginas AS STRING * 10
   preco AS STRING * 10
   qtdestoque AS STRING * 10
END TYPE
TYPE regLivroAss
   isbn AS STRING * 13
   codassunto AS STRING * 10
END TYPE
TYPE regLivroAut
   isbn AS STRING * 13
   codautor AS STRING * 10
END TYPE
TYPE regCliente
   cpf AS STRING * 14
   nome AS STRING * 30
   email AS STRING * 30
   identidade AS STRING * 10
   sexo AS STRING * 1
   telefone AS STRING * 17
   dtnascimento AS STRING * 10
   codendereco AS STRING * 10
   codpais AS STRING * 3
   codprofissao AS STRING * 10
END TYPE
TYPE regEndereco
   codigo AS STRING * 10
   Logradouro AS STRING * 40
   bairro AS STRING * 15
   cep AS STRING * 8
   cidade AS STRING * 30
   estado AS STRING * 20
END TYPE
TYPE regVenda
   dthrvenda AS STRING * 19  ' data/hora da venda dd/mm/yyyy hh:mm:ss
   cpf AS STRING * 14
   isbn AS STRING * 13
   precovenda AS STRING * 10
END TYPE

' vari†veis globais
COMMON SHARED bopcao AS INTEGER
COMMON SHARED opmenu AS STRING
COMMON SHARED gnPosChave, gnTamChave AS INTEGER
COMMON SHARED gnPreco AS DOUBLE
COMMON SHARED gSalvarInclusao AS INTEGER
COMMON SHARED gnPosicao AS INTEGER

COMMON SHARED tAssunto AS regAssunto
COMMON SHARED tAutor AS regAutor
COMMON SHARED tEditora AS regEditora
COMMON SHARED tIdioma AS regIdioma
COMMON SHARED tEndereco AS regEndereco
COMMON SHARED tPais AS regPais
COMMON SHARED tProfissao AS regProfissao
COMMON SHARED tLivro AS regLivro
COMMON SHARED tLivroAss AS regLivroAss
COMMON SHARED tLivroAut AS regLivroAut
COMMON SHARED tCliente AS regCliente
COMMON SHARED tUsuario AS regUsuario
COMMON SHARED tVenda AS regVenda

COMMON SHARED CRLF AS STRING

' constantes

CONST true = 1
CONST false = 0
' ctTipo
CONST opTexto = 1, opNumero = 2, opData = 3, opDataHora = 4, opSenha = 5
' ctArqs
CONST opAssunto = 1, opAutor = 2, opEditora = 3, opEndereco = 4
CONST opIdioma = 5, opPais = 6, opProfissao = 7, opCliente = 8, opLivro = 9
CONST opLivroAss = 10, opLivroAut = 11, opUsuario = 12, opVenda = 13
' ctAcao
CONST opNovo = 1, opAlterar = 2, opPesquisar = 3, opSalvarInclusao = 4
CONST opSalvarAlteracao = 5, opExcluir = 6
CONST opConfirmaExclusao = 7, opListarTodos = 8

CRLF = CHR$(13) + CHR$(10) ' windows
CONST TAMCRLF = 2
'CONST CRLF = chr$(10)
'CONST TAMCRLF = 1  ' unix
'CONST CRLF = chr$(13)
'CONST TAMCRLF = 1  ' macintosh

CONST QTDMAXLINHA = 18

CONST MSGERRO = "Erro: opá∆o inv†lida digite de novo"
CONST MSGOPCAO = "Escolha uma opá∆o: "
CONST MSGPRESS = "pressione para continuar..."

CONST MSGREGINC = "registro incluido!"
CONST MSGREGNINC = "registro n∆o incluido!"
CONST MSGREGALT = "registro alterado!"
CONST MSGREGNALT = "registro n∆o alterado!"
CONST MSGREGEXC = "registro excluido!"
CONST MSGREGNEXC = "registro n∆o excluido!"
CONST MSGREGEXST = "registro j† existe!"

CONST MSGNUMINV = "N£mero inv†lido ou menor do que 1!"
CONST MSGDATAINV = "Data inv†lida!, formato correto (dd/mm/yyyy)"
CONST MSGDTHRINV = "Data/hora inv†lida!, formato correto (dd/mm/yyyy hh:mm:ss)"
CONST MSGISBNINV = "ISBN inv†lido!"
CONST MSGCPFINV = "CPF inv†lido!"
CONST MSGSENCONFERE = "senha n∆o confere com a senha atual!"
CONST MSGSENCONFIRM = "nova senha n∆o confere com a senha confirmada!"
CONST MSGLOGINENCON = "login n∆o encontrado!"
CONST MSGSEMESTOQUE = "livro n∆o existe no estoque!"

CONST ARQASSUNTO = "assunto.dat"
CONST ARQAUTOR = "autor.dat"
CONST ARQEDITORA = "editora.dat"
CONST ARQIDIOMA = "idioma.dat"
CONST ARQUSUARIO = "usuario.dat"
CONST ARQPAIS = "pais.dat"
CONST ARQPROFISSAO = "profissa.dat"
CONST ARQLIVRO = "livro.dat"
CONST ARQLIVASS = "livroass.dat"
CONST ARQLIVAUT = "livroaut.dat"
CONST ARQCLIENTE = "cliente.dat"
CONST ARQENDERECO = "endereco.dat"
CONST ARQVENDA = "venda.dat"

CONST TAMASSUNTO = 40
CONST TAMAUTOR = 40
CONST TAMEDITORA = 60
CONST TAMIDIOMA = 30
CONST TAMUSUARIO = 20
CONST TAMPAIS = 53
CONST TAMPROFISSAO = 60
CONST TAMLIVRO = 143
CONST TAMLIVASS = 23
CONST TAMLIVAUT = 23
CONST TAMCLIENTE = 135
CONST TAMENDERECO = 123
CONST TAMVENDA = 56

' Arquivos
CONST tfAssunto = 1
CONST tfAutor = 2
CONST tfEditora = 3
CONST tfIdioma = 4
CONST tfEndereco = 5
CONST tfPais = 6
CONST tfProfissao = 7
CONST tfLivro = 8
CONST tfLivroAss = 9
CONST tfLivroAut = 10
CONST tfCliente = 11
CONST tfUsuario = 12
CONST tfVenda = 13

'------------------------------------------------------------------------------
'Parte inicial do c¢digo
'------------------------------------------------------------------------------
'if ParamStr(1)="-cria" then
'   abreArqs (false)
'else
 frmSplash
 abreArqs (true)
 IF frmLogin THEN
   bopcao = true
   DO WHILE (bopcao)
     menu (1)
     INPUT "", opmenu
     IF (opmenu = "C") OR (opmenu = "c") THEN
       usaMenu (1)
     ELSEIF (opmenu = "P") OR (opmenu = "p") THEN usaMenu (2)
     ELSEIF (opmenu = "V") OR (opmenu = "v") THEN usaMenu (3)
     ELSEIF (opmenu = "O") OR (opmenu = "o") THEN usaMenu (4)
     ELSE PRINT MSGERRO
     END IF
   LOOP
 ELSE
   fechaArqs
   END
 END IF
'end if

'------------------------------------------------------------------------------
'Abre ou cria os arquivos do sistema.
'bAbre - condiá∆o para abrir ou criar os arquivos do sistema
'------------------------------------------------------------------------------
SUB abreArqs (bAbre AS INTEGER)
IF bAbre THEN
 OPEN ARQASSUNTO FOR INPUT AS tfAssunto
 OPEN ARQAUTOR FOR INPUT AS tfAutor
 OPEN ARQEDITORA FOR INPUT AS tfEditora
 OPEN ARQIDIOMA FOR INPUT AS tfIdioma
 OPEN ARQENDERECO FOR INPUT AS tfEndereco
 OPEN ARQPAIS FOR INPUT AS tfPais
 OPEN ARQPROFISSAO FOR INPUT AS tfProfissao
 OPEN ARQLIVRO FOR INPUT AS tfLivro
 OPEN ARQLIVASS FOR INPUT AS tfLivroAss
 OPEN ARQLIVAUT FOR INPUT AS tfLivroAut
 OPEN ARQCLIENTE FOR INPUT AS tfCliente
 OPEN ARQUSUARIO FOR INPUT AS tfUsuario
 OPEN ARQVENDA FOR INPUT AS tfVenda
ELSE
 OPEN ARQASSUNTO FOR APPEND AS tfAssunto
 OPEN ARQAUTOR FOR APPEND AS tfAutor
 OPEN ARQEDITORA FOR APPEND AS tfEditora
 OPEN ARQIDIOMA FOR APPEND AS tfIdioma
 OPEN ARQENDERECO FOR APPEND AS tfEndereco
 OPEN ARQPAIS FOR APPEND AS tfPais
 OPEN ARQPROFISSAO FOR APPEND AS tfProfissao
 OPEN ARQLIVRO FOR APPEND AS tfLivro
 OPEN ARQLIVASS FOR APPEND AS tfLivroAss
 OPEN ARQLIVAUT FOR APPEND AS tfLivroAut
 OPEN ARQCLIENTE FOR APPEND AS tfCliente
 OPEN ARQUSUARIO FOR APPEND AS tfUsuario
 OPEN ARQVENDA FOR APPEND AS tfVenda
END IF
END SUB

'------------------------------------------------------------------------------
'Executa uma aá∆o de gravaá∆o de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'sacao - a aá∆o a ser realizada
'------------------------------------------------------------------------------
SUB btnAcao (sreg AS INTEGER, sacao AS INTEGER)
DIM nlinhareg AS STRING, ntamreg AS INTEGER

nlinhareg = LinhaReg(sreg)
ntamreg = tamReg(sreg)
IF sreg = opAssunto THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfAssunto, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfAssunto, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfAssunto, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opAutor THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfAutor, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfAutor, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfAutor, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opEditora THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfEditora, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfEditora, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfEditora, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opEndereco THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfEndereco, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfEndereco, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfEndereco, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opIdioma THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfIdioma, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfIdioma, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfIdioma, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opPais THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfPais, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfPais, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfPais, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opProfissao THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfProfissao, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfProfissao, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfProfissao, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opLivro THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfLivro, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfLivro, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfLivro, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opLivroAss THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfLivroAss, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfLivroAss, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfLivroAss, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opLivroAut THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfLivroAut, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfLivroAut, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfLivroAut, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opCliente THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfCliente, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfCliente, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfCliente, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opVenda THEN
   IF sacao = opSalvarInclusao THEN
      escreveArq tfVenda, nlinhareg, MSGREGINC, MSGREGNINC
   ELSEIF sacao = opSalvarAlteracao THEN
      escreveArq tfVenda, nlinhareg, MSGREGALT, MSGREGNALT
   ELSEIF sacao = opConfirmaExclusao THEN
      escreveArq tfVenda, repete("*", ntamreg), MSGREGEXC, MSGREGNEXC
   END IF
ELSEIF sreg = opUsuario THEN
   IF sacao = opSalvarAlteracao THEN
      escreveArq tfUsuario, nlinhareg, MSGREGALT, MSGREGNALT
   END IF
END IF
END SUB

'------------------------------------------------------------------------------
'Indica se continua ou n∆o mostrando um n£mero m†ximo de linhas.
'nlinha - a linha a ser continuada
'nQtdLinha - a quantidade de linhas a serem mostradas
'retorna - se continua ou n∆o
'------------------------------------------------------------------------------
FUNCTION ContinuaSN! (nlinha AS INTEGER, nQtdLinha AS INTEGER)
DIM bSOp, bret AS INTEGER
DIM opCSubMenu AS STRING

bret = false
IF nlinha > 0 THEN
  IF (nlinha MOD nQtdLinha) = 0 THEN
     bSOp = true
     DO WHILE bSOp
       menu (13)
       INPUT "", opCSubMenu
       IF (opCSubMenu = "S") OR (opCSubMenu = "s") THEN
	 bSOp = false
       ELSEIF (opCSubMenu = "N") OR (opCSubMenu = "n") THEN
	  bret = true
	  bSOp = false
       ELSE
	 PRINT MSGERRO
       END IF
     LOOP
  END IF
END IF

ContinuaSN = bret
END FUNCTION

'------------------------------------------------------------------------------
'Esconde a digitaá∆o da senha
'retorna - a senha digitada
'------------------------------------------------------------------------------
FUNCTION digitaSenha$ (sRotulo AS STRING, nTamSenha AS INTEGER)
DIM sSenha AS STRING, sLetra AS STRING
DIM nCont AS INTEGER

PRINT sRotulo;
nCont = 0
sSenha = ""
sLetra = ""
DO
  sLetra = INKEY$
  sSenha = sSenha + sLetra
  'nCont = nCont + 1
  'IF nCont = nTamSenha THEN
  '   EXIT DO
  'END IF
LOOP UNTIL sLetra = CHR$(13)
digitaSenha = MID$(sSenha, 1, LEN(sSenha) - 1)
END FUNCTION

'------------------------------------------------------------------------------
'Grava os registros num determinado arquivo.
'sArq - o arquivo
'sTexto - o registro a ser gravado
'sMsgAcerto - a mensagem caso o registro foi gravado
'sMsgErro - a mensagem caso o registro n∆o foi gravado
'------------------------------------------------------------------------------
SUB escreveArq (sArq AS INTEGER, sTexto AS STRING, sMsgAcerto AS STRING, sMsgErro AS STRING)

CLOSE
abreArqs false
SEEK sArq, gnPosicao

'sTexto = sTexto + CRLF
PRINT #sArq, sTexto

'if nStatus > 0 then
   PRINT sMsgAcerto
'else
'   print sMsgErro
'end if

CLOSE
abreArqs true

END SUB

'------------------------------------------------------------------------------
'Coloca espaáos em branco a mais de acordo com o tamanho m†ximo do texto.
'sTexto - o texto
'nTam - tamanho m†ximo do texto
'retorna - o texto com espaáos em branco a mais
'------------------------------------------------------------------------------
FUNCTION esp$ (sTexto AS STRING, ntam AS INTEGER)
  esp = sTexto + repete$(" ", ntam - LEN(sTexto))
END FUNCTION

'------------------------------------------------------------------------------
'Realiza a exclus∆o dos arquivos de ligaá∆o.
'sArq - o arquivo de ligaá∆o
'sreg - o tipo de arquivo de ligaá∆o
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'sChave - a chave a ser excluida
'------------------------------------------------------------------------------
SUB ExcluirRegLigados (sArq AS INTEGER, sreg AS INTEGER, nPosChave AS INTEGER, nTamChave AS INTEGER, sChave AS STRING)
DIM slinha AS STRING
DIM sCodigo AS STRING

  SEEK sArq, 1
  DO WHILE NOT EOF(sArq)
    LINE INPUT #sArq, slinha
    sCodigo = Trim$(MID$(slinha, nPosChave, nTamChave))
    IF sCodigo = sChave THEN
       btnAcao sreg, opConfirmaExclusao
    END IF
  LOOP
END SUB

'------------------------------------------------------------------------------
'Fecha todos os arquivos abertos.
'------------------------------------------------------------------------------
SUB fechaArqs
 CLOSE tfAssunto
 CLOSE tfAutor
 CLOSE tfEditora
 CLOSE tfIdioma
 CLOSE tfEndereco
 CLOSE tfPais
 CLOSE tfProfissao
 CLOSE tfLivro
 CLOSE fLivroAss
 CLOSE tfLivroAut
 CLOSE tfCliente
 CLOSE tfUsuario
 CLOSE tfVenda
END SUB

'------------------------------------------------------------------------------
'Mostra a tela de alteraá∆o de senha do sistema e realiza a alteraá∆o.
'------------------------------------------------------------------------------
SUB frmAlterarSenha
DIM bQuebra AS INTEGER
DIM sres AS STRING, sSenhaAtual AS STRING
DIM sNovaSenha AS STRING, sConfirmaSenha AS STRING
DIM nOpcao AS INTEGER, ntam AS INTEGER

PRINT rotulo(opUsuario, 1) + tUsuario.login
nOpcao = 1
bQuebra = false
DO WHILE (bQuebra = false)
  SELECT CASE nOpcao
   CASE 1
       sSenhaAtual = digitaSenha("Senha Atual: ", 10)
       IF sSenhaAtual <> tUsuario.senha THEN
	  PRINT MSGSENCONFERE
	  bQuebra = true
       ELSE nOpcao = 2
       END IF
   CASE 2
       sNovaSenha = digitaSenha("Nova Senha: ", 10)
       sConfirmaSenha = digitaSenha("Confirma Senha: ", 10)
       IF sNovaSenha <> sConfirmaSenha THEN
	  PRINT MSGSENCONFIRM
	  bQuebra = true
       ELSE nOpcao = 3
       END IF
   CASE 3
       ntam = tamReg(opUsuario)
       sres = pesqArq(tfUsuario, tUsuario.login, 1, 10, ntam)
       IF sres = "" THEN
	 PRINT MSGLOGINENCON
       ELSE
	 tUsuario.senha = sConfirmaSenha
	 subMenu 9, opUsuario
	 bQuebra = true
       END IF
  END SELECT
LOOP

END SUB

'------------------------------------------------------------------------------
'Realiza os cadastros de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'sacao - a aá∆o a ser realizada
'------------------------------------------------------------------------------
SUB frmCadastros (sreg AS INTEGER, sacao AS INTEGER)
DIM slinha AS STRING, ntam AS INTEGER

ntam = tamReg(sreg)
IF sreg = opAssunto THEN
   IF sacao = opNovo THEN
      tAssunto.codigo = pesqMaxCod(tfAssunto, 1, 10, ntam)
      mostrarDados sreg, "", 1
      subMenu 7, sreg
   ELSEIF sacao = opPesquisar THEN
     slinha = validaEntrada(tfAssunto, sreg, 1, tAssunto.codigo, 1, false, opNumero)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opAutor THEN
   IF sacao = opNovo THEN
      tAutor.codigo = pesqMaxCod(tfAutor, 1, 10, ntam)
      mostrarDados sreg, "", 1
      subMenu 7, sreg
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfAutor, sreg, 1, tAutor.codigo, 1, false, opNumero)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opEditora THEN
   IF sacao = opNovo THEN
      tEditora.codigo = pesqMaxCod(tfEditora, 1, 10, ntam)
      mostrarDados sreg, "", 1
      subMenu 7, sreg
   ELSEIF sacao = opPesquisar THEN
     slinha = validaEntrada(tfEditora, sreg, 1, tEditora.codigo, 1, false, opNumero)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opEndereco THEN
   IF sacao = opNovo THEN
      tEndereco.codigo = pesqMaxCod(tfEndereco, 1, 10, ntam)
      mostrarDados sreg, "", 1
      subMenu 7, sreg
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfEndereco, sreg, 1, tEndereco.codigo, 1, false, opNumero)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opIdioma THEN
   IF sacao = opNovo THEN
      tIdioma.codigo = pesqMaxCod(tfIdioma, 1, 10, ntam)
      mostrarDados sreg, "", 1
      subMenu 7, sreg
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfIdioma, sreg, 1, tIdioma.codigo, 1, false, opNumero)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opPais THEN
   IF sacao = opNovo THEN
      PRINT rotulo(sreg, 1);
      INPUT "", tPais.codigo
      slinha = pesqArq(tfPais, tPais.codigo, 1, 3, ntam)
      IF slinha = "" THEN
	 pesqLinhaExcluida tfPais, ntam
	 mostrarDados sreg, "", 1
	 subMenu 7, sreg
      ELSE
	 PRINT MSGREGEXST
      END IF
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, opTexto)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      PRINT rotulo(sreg, 1) + tPais.codigo
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opProfissao THEN
   IF sacao = opNovo THEN
      tProfissao.codigo = pesqMaxCod(tfProfissao, 1, 10, ntam)
      mostrarDados sreg, "", 1
      subMenu 7, sreg
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfProfissao, sreg, 1, tProfissao.codigo, 1, false, opNumero)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opLivro THEN
   IF sacao = opNovo THEN
      PRINT rotulo(sreg, 1);
      INPUT "", tLivro.isbn
      IF validaISBN(tLivro.isbn) THEN
	  slinha = pesqArq(tfLivro, tLivro.isbn, 1, 13, ntam)
	  IF slinha = "" THEN
	     pesqLinhaExcluida tfLivro, ntam
	     mostrarDados sreg, "", 1
	     subMenu 7, sreg
	     frmCadLigados opLivroAss, opNovo, tLivro.isbn
	     frmCadLigados opLivroAut, opNovo, tLivro.isbn
	  ELSE PRINT MSGREGEXST
	  END IF
      ELSE PRINT MSGISBNINV
      END IF
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1, false, opTexto)
      IF slinha <> "" THEN
	 mostrarDados sreg, "", 2
	 mostrarDados sreg, slinha, 3
	 subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      PRINT rotulo(sreg, 1) + tLivro.isbn
      mostrarDados sreg, "", 1
      subMenu 9, sreg
      frmCadLigados opLivroAss, opExcluir, tLivro.isbn
      PRINT "Assuntos dos livros exclu°dos, inclua novos!"
      frmCadLigados opLivroAss, opNovo, tLivro.isbn
      frmCadLigados opLivroAut, opExcluir, tLivro.isbn
      PRINT "Autores dos livros exclu°dos, inclua novos!"
      frmCadLigados opLivroAut, opNovo, tLivro.isbn
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
      PRINT "Assuntos dos livros sendo exclu°dos!"
      frmCadLigados opLivroAss, opExcluir, tLivro.isbn
      PRINT "Autores dos livros sendo exclu°dos!"
      frmCadLigados opLivroAut, opExcluir, tLivro.isbn
   END IF
ELSEIF sreg = opCliente THEN
   IF sacao = opNovo THEN
      PRINT rotulo(sreg, 1);
      INPUT "", tCliente.cpf
      IF validaCPF(tCliente.cpf) THEN
	  slinha = pesqArq(tfCliente, tCliente.cpf, 1, 14, ntam)
	  IF slinha = "" THEN
	     pesqLinhaExcluida tfCliente, ntam
	     mostrarDados sreg, "", 1
	     subMenu 7, sreg
	  ELSE PRINT MSGREGEXST
	  END IF
      ELSE PRINT MSGCPFINV
      END IF
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfCliente, sreg, 1, tCliente.cpf, 1, false, opTexto)
      IF slinha <> "" THEN
	 mostrarDados sreg, "", 2
	 mostrarDados sreg, slinha, 3
	 subMenu 8, sreg
      END IF
   ELSEIF sacao = opAlterar THEN
      PRINT rotulo(sreg, 1) + tCliente.cpf
      mostrarDados sreg, "", 1
      subMenu 9, sreg
   ELSEIF sacao = opExcluir THEN
      subMenu 10, sreg
   END IF
ELSEIF sreg = opVenda THEN
   IF sacao = opNovo THEN
      tVenda.dthrvenda = retDataHora
      PRINT rotulo(sreg, 1) + tVenda.dthrvenda
      slinha = pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, ntam)
      IF slinha = "" THEN
	 slinha = validaEntrada(tfCliente, opCliente, 1, tVenda.cpf, 3, false, opTexto)
	 IF slinha <> "" THEN
	    tVenda.cpf = Trim(MID$(slinha, 1, 14))
	    IF validaCPF(tVenda.cpf) THEN
	       PRINT " " + rotulo(opCliente, 2); ' Nome
	       PRINT MID$(slinha, gnPosChave, gnTamChave)
	       frmCadLigados opVenda, opNovo, tVenda.cpf
	    ELSE PRINT MSGCPFINV
	    END IF
	 END IF
      ELSE PRINT MSGREGEXST
      END IF
   ELSEIF sacao = opPesquisar THEN
      slinha = validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda, 1, false, opDataHora)
      IF slinha <> "" THEN
	mostrarDados sreg, "", 2
	mostrarDados sreg, slinha, 3
	subMenu 8, sreg
      END IF
   END IF
END IF

END SUB

'------------------------------------------------------------------------------
'Realiza os cadastros dos arquivos que se ligam a outros arquivos.
'sreg - o tipo de arquivo
'sacao - a aá∆o a ser realizada
'sCodigo - um das chaves do arquivo de ligaá∆o
'------------------------------------------------------------------------------
SUB frmCadLigados (sreg AS INTEGER, sacao AS INTEGER, sCodigo AS STRING)
DIM nQtd AS INTEGER, nCont AS INTEGER, nQtdEstoque AS INTEGER
DIM nTotalPreco AS DOUBLE, ntam AS INTEGER
DIM slinha AS STRING, sTotalPreco AS STRING
DIM sPreco AS STRING, sQtd AS STRING

IF sacao = opNovo THEN
  nCont = 1
  IF sreg = opLivroAss THEN
    sQtd = validaNumero("Quantos assuntos quer cadastrar?: ", sQtd)
    nQtd = VAL(sQtd)
    SEEK tfLivroAss, 1
    DO WHILE nCont <= nQtd
      tLivroAss.isbn = sCodigo
      PRINT rotulo(opLivroAss, 2);
      INPUT "", tLivroAss.codassunto
      ntam = tamReg(opAssunto)
      slinha = pesqArq(tfAssunto, tLivroAss.codassunto, 1, 10, ntam)
      PRINT " " + rotulo(opAssunto, 2);
      PRINT MID$(slinha, gnPosChave, gnTamChave)
      ntam = tamReg(sreg)
      pesqLinhaExcluida tfLivroAss, ntam
      subMenu 14, sreg
      nCont = nCont + 1
    LOOP
  ELSEIF sreg = opLivroAut THEN
    sQtd = validaNumero("Quantos autores quer cadastrar?: ", sQtd)
    nQtd = VAL(sQtd)
    SEEK tfLivroAut, 1
    DO WHILE nCont <= nQtd
      tLivroAut.isbn = sCodigo
      PRINT rotulo(opLivroAut, 2);
      INPUT "", tLivroAut.codautor
      ntam = tamReg(opAutor)
      slinha = pesqArq(tfAutor, tLivroAut.codautor, 1, 10, ntam)
      PRINT " " + rotulo(opAutor, 2);
      PRINT MID$(slinha, gnPosChave, gnTamChave)
      ntam = tamReg(sreg)
      pesqLinhaExcluida tfLivroAut, ntam
      subMenu 14, sreg
      nCont = nCont + 1
    LOOP
  ELSEIF sreg = opVenda THEN
    sQtd = validaNumero("Quantos livros quer vender?: ", sQtd)
    nQtd = VAL(sQtd)
    nTotalPreco = 0
    DO WHILE nCont <= nQtd
      slinha = validaEntrada(tfLivro, opLivro, 1, tVenda.isbn, 3, false, opTexto)
      IF slinha <> "" THEN
	tVenda.isbn = Trim$(MID$(slinha, 1, 13))
	IF validaISBN(tVenda.isbn) THEN
	  mostrarDados sreg, "", 1
	  tLivro.qtdestoque = Trim$(MID$(slinha, 134, 10))
	  nQtdEstoque = VAL(tLivro.qtdestoque)
	  IF nQtdEstoque > 0 THEN
	     nTotalPreco = nTotalPreco + gnPreco
	     sPreco = STR$(gnPreco)
	     tVenda.precovenda = sPreco
	     gSalvarInclusao = false
	     subMenu 14, sreg
	     IF gSalvarInclusao THEN
		ntam = tamReg(opLivro)
		slinha = pesqArq(tfLivro, tVenda.isbn, 1, 13, ntam)
		IF slinha <> "" THEN
		   nQtdEstoque = nQtdEstoque - 1
		   tLivro.qtdestoque = STR$(nQtdEstoque)
		   slinha = MID$(slinha, 1, 133) + esp(tLivro.qtdestoque, 10)
		   escreveArq tfLivro, slinha, "", ""
		END IF
	     END IF
	     nCont = nCont + 1
	  ELSE
	    PRINT MSGSEMESTOQUE
	  END IF
	ELSE
	  PRINT MSGISBNINV
	END IF
      END IF
    LOOP
    sTotalPreco = STR$(nTotalPreco)
    PRINT "Total de " + rotulo(sreg, 4) + sTotalPreco
  END IF
ELSEIF sacao = opExcluir THEN
  IF sreg = opLivroAss THEN
     ExcluirRegLigados tfLivroAss, sreg, 1, 13, sCodigo
  ELSEIF sreg = opLivroAut THEN
     ExcluirRegLigados tfLivroAut, sreg, 1, 13, sCodigo
  END IF
END IF

END SUB

'------------------------------------------------------------------------------
'Realiza as consultas de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'sacao - a aá∆o a ser realizada
'------------------------------------------------------------------------------
SUB frmConsultas (sreg AS INTEGER, sacao AS INTEGER)
DIM slinha AS STRING, ntam AS INTEGER

ntam = tamReg(sreg)
IF sreg = opAssunto THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfAssunto, sreg, 2, tAssunto.assunto, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfAssunto, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opAutor THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfAutor, sreg, 2, tAutor.autor, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfAutor, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opEditora THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfEditora, sreg, 2, tEditora.editora, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfEditora, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opEndereco THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfEndereco, sreg, 2, tEndereco.Logradouro, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfEndereco, sreg, "", 0, 0, ntam, 3, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opIdioma THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfIdioma, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opPais THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfPais, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opProfissao THEN
   IF sacao = opPesquisar THEN
     slinha = validaEntrada(tfProfissao, sreg, 2, tProfissao.profissao, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfProfissao, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opLivro THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfLivro, sreg, "", 0, 0, ntam, 1, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opCliente THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfCliente, sreg, 2, tCliente.nome, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfCliente, sreg, "", 0, 0, ntam, 1, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
ELSEIF sreg = opVenda THEN
   IF sacao = opPesquisar THEN
      slinha = validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true, opTexto)
   ELSEIF sacao = opListarTodos THEN
      IF ListarTodos(tfVenda, sreg, "", 0, 0, ntam, QTDMAXLINHA, false) = false THEN
	PRINT rotulo(sreg, 0)
      END IF
   END IF
END IF
IF slinha = "" THEN
   PRINT "";
END IF
END SUB

'------------------------------------------------------------------------------
'Mostra a tela de login do sistema.
'retorna - se o login foi validado corretamente
'------------------------------------------------------------------------------
FUNCTION frmLogin!
DIM bret AS INTEGER
DIM slinha AS STRING

  bret = false
  PRINT "*--------------------------------------------------------------*"
  PRINT "| Login do sistema                                             |"
  PRINT "*--------------------------------------------------------------*"
  slinha = validaEntrada(tfUsuario, opUsuario, 1, tUsuario.login, 3, false, opTexto)
  IF slinha <> "" THEN
     slinha = validaEntrada(tfUsuario, opUsuario, 2, tUsuario.senha, 3, false, opSenha)
     IF slinha <> "" THEN
	tUsuario.login = Trim$(MID$(slinha, 1, 10))
	tUsuario.senha = Trim$(MID$(slinha, 11, 10))
	bret = true
     END IF
  END IF
  PRINT
  frmLogin = bret
END FUNCTION

'------------------------------------------------------------------------------
'Mostra a tela de sobre do sistema.
'------------------------------------------------------------------------------
SUB frmSobre
DIM cont AS INTEGER

 PRINT "*------------------------------------------------------------*"
 PRINT "|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |"
 PRINT "|  LL        II   VV     VV   RR     R  UU    UU  SS         |"
 PRINT "|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |"
 PRINT "|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |"
 PRINT "|  LLLL      II      VVV      RR RR     UU    UU        SS   |"
 PRINT "|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |"
 PRINT "|                                                            |"
 PRINT "|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |"
 PRINT "|   VV     VV   II  RR     R     TT     UU    UU  SS         |"
 PRINT "|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |"
 PRINT "|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |"
 PRINT "|      VVV      II  RR RR        TT     UU    UU        SS   |"
 PRINT "|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |"
 PRINT "|                                                            |"
 PRINT "|                                               Versao 1.0.0 |"
 PRINT "| Sistema integrante do projeto Livrus Virtus.               |"
 PRINT "| Todos os direitos reservados para Henrique F. de Souza.    |"
 PRINT "| Versao programada na linguagem qbasic.                     |"
 PRINT "*------------------------------------------------------------*"
 FOR cont = 1 TO 3
     PRINT ""
 NEXT cont
 PRINT MSGPRESS;
 INPUT "", cont
END SUB

'------------------------------------------------------------------------------
'Mostra a tela de splash do sistema.
'------------------------------------------------------------------------------
SUB frmSplash
DIM cont AS INTEGER

 PRINT "*----------------------------------------------------------------------------*"
 PRINT "| LL    II VV   VV RRRRR  UU  UU   SSSS VV   VV II RRRRR  TTTT UU  UU   SSSS |"
 PRINT "| LL    II  VV VV  RR   R UU  UU  SS     VV VV  II RR   R  TT  UU  UU  SS    |"
 PRINT "| LL    II   VVV   RRRRR  UU  UU    SS    VVV   II RRRRR   TT  UU  UU    SS  |"
 PRINT "| LLLLL II    V    RR   R  UUUU  SSSS      V    II RR   R  TT   UUUU  SSSS   |"
 PRINT "*----------------------------------------------------------------------------*"
 FOR cont = 1 TO 17
     PRINT ""
 NEXT cont
 PRINT MSGPRESS;
 INPUT "", cont
END SUB

'------------------------------------------------------------------------------
'Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'retorna - o registro montado
'------------------------------------------------------------------------------
FUNCTION LinhaReg$ (sreg AS INTEGER)
DIM slinha AS STRING

slinha = ""
IF sreg = opAssunto THEN
   slinha = esp(tAssunto.codigo, 10) + esp(tAssunto.assunto, 30)
ELSEIF sreg = opAutor THEN
   slinha = esp(tAutor.codigo, 10) + esp(tAutor.autor, 30)
ELSEIF sreg = opEditora THEN
   slinha = esp(tEditora.codigo, 10) + esp(tEditora.editora, 50)
ELSEIF sreg = opEndereco THEN
   slinha = esp(tEndereco.codigo, 10) + esp(tEndereco.Logradouro, 40) + esp(tEndereco.bairro, 15) + esp(tEndereco.cep, 8) + esp(tEndereco.cidade, 30) + esp(tEndereco.estado, 20)
ELSEIF sreg = opIdioma THEN
   slinha = esp(tIdioma.codigo, 10) + esp(tIdioma.idioma, 20)
ELSEIF sreg = opPais THEN
   slinha = esp(tPais.codigo, 3) + esp(tPais.pais, 50)
ELSEIF sreg = opProfissao THEN
   slinha = esp(tProfissao.codigo, 10) + esp(tProfissao.profissao, 50)
ELSEIF sreg = opUsuario THEN
   slinha = esp(tUsuario.login, 10) + esp(tUsuario.senha, 10)
ELSEIF sreg = opLivro THEN
   slinha = esp(tLivro.isbn, 13) + esp(tLivro.titulo, 50) + esp(tLivro.edicao, 10) + esp(tLivro.anopubli, 10) + esp(tLivro.codeditora, 10) + esp(tLivro.volume, 10) + esp(tLivro.codidioma, 10) + esp(tLivro.npaginas, 10) + esp(tLivro.preco, 10) + esp( _
tLivro.qtdestoque, 10)
ELSEIF sreg = opLivroAss THEN
   slinha = esp(tLivroAss.isbn, 13) + esp(tLivroAss.codassunto, 10)
ELSEIF sreg = opLivroAut THEN
   slinha = esp(tLivroAut.isbn, 13) + esp(tLivroAut.codautor, 10)
ELSEIF sreg = opCliente THEN
   slinha = esp(tCliente.cpf, 14) + esp(tCliente.nome, 30) + esp(tCliente.email, 30) + esp(tCliente.identidade, 10) + esp(tCliente.sexo, 1) + esp(tCliente.telefone, 17) + esp(tCliente.dtnascimento, 10) + esp(tCliente.codendereco, 10) + esp(tCliente. _
codpais, 3) + esp(tCliente.codprofissao, 10)
ELSEIF sreg = opVenda THEN
   slinha = esp(tVenda.dthrvenda, 19) + esp(tVenda.cpf, 14) + esp(tVenda.isbn, 13) + esp(tVenda.precovenda, 10)
END IF
LinhaReg = slinha
END FUNCTION

'------------------------------------------------------------------------------
'Lista v†rios registros entre arquivos de acordo com a pesquisa feita.
'sArq1 - o arquivo de ligaá∆o
'sreg1 - o tipo de arquivo de ligaá∆o
'nPosChave1 - a posicao inicial da primeira chave no arquivo de ligaá∆o
'nTamChave1 - o tamanho da primeira chave no arquivo de ligaá∆o
'nPosChave2 - a posicao inicial da segunda chave do arquivo de ligaá∆o
'nTamChave2 - o tamanho da segunda chave do arquivo de ligaá∆o
'sChave - a chave a ser pesquisada no arquivo de ligaá∆o
'sArq2 - o arquivo a ser pesquisado
'sreg2 - o tipo de arquivo a ser pesquisado
'nPosChave3 - a posicao inicial da chave do arquivo pesquisado
'nQtdLinha - a quantidade de linhas a serem mostradas
'------------------------------------------------------------------------------
SUB ListarRegLigados (sArq1 AS INTEGER, sreg1 AS INTEGER, nPosChave1 AS INTEGER, nTamChave1 AS INTEGER, nPosChave2 AS INTEGER, nTamChave2 AS INTEGER, sChave AS STRING, sArq2 AS INTEGER, sreg2 AS INTEGER, nPosChave3 AS INTEGER, nQtdLinha AS INTEGER)
DIM slinha1 AS STRING, ntam2 AS INTEGER
DIM bQuebra AS INTEGER, bret AS INTEGER
DIM nStatus AS INTEGER, nCont  AS INTEGER
DIM sCodigo1 AS STRING, sCodigo2 AS STRING, slinha2 AS STRING

bret = false
nCont = 0
bQuebra = false
mostrarDados sreg2, "", 2
SEEK sArq1, 1
DO WHILE (NOT EOF(sArq1)) AND (bQuebra = false)
  LINE INPUT #sArq1, slinha1
  sCodigo1 = Trim$(MID$(slinha1, nPosChave1, nTamChave1))
  IF sCodigo1 = sChave THEN
    sCodigo2 = Trim$(MID$(slinha1, nPosChave2, nTamChave2))
    ntam2 = tamReg(sreg2)
    slinha2 = pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, ntam2)
    mostrarDados sreg2, MID$(slinha2, 1, tamReg(sreg2)), 3
    bret = true
    nCont = nCont + 1
  END IF
  bQuebra = ContinuaSN(nCont, nQtdLinha)
LOOP
IF bret = false THEN
   PRINT rotulo(sreg2, 0)
END IF
END SUB

'------------------------------------------------------------------------------
'Lista v†rios registros de acordo com a pesquisa feita.
'sArq - o arquivo
'sreg - o tipo de arquivo
'sChave - a chave a ser pesquisada
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'nTamLinha - o tamanho do registro
'nQtdLinha - a quantidade de linhas a serem mostradas
'retorna - se encontrou algum registro
'------------------------------------------------------------------------------
FUNCTION ListarTodos! (sArq AS INTEGER, sreg AS INTEGER, sChave AS STRING, nPosChave AS INTEGER, nTamChave AS INTEGER, nTamLinha AS INTEGER, nQtdLinha AS INTEGER, bPesqRelativa AS INTEGER)
DIM slinha AS STRING
DIM bQuebra, bAchou, bret AS INTEGER
DIM nStatus, nCont AS INTEGER
DIM sres AS STRING

bret = false
bQuebra = false
nCont = 0
mostrarDados sreg, "", 2
SEEK sArq, 1
DO WHILE (NOT EOF(sArq)) AND (bQuebra = false)
  LINE INPUT #sArq, slinha
  IF bPesqRelativa THEN
    sres = Trim$(MID$(slinha, nPosChave, nTamChave))
    IF strRelativa(sres, sChave) THEN
       bAchou = true
       bret = true
    ELSE
       bAchou = false
    END IF
  ELSE
    bAchou = true
    bret = true
  END IF

  IF bAchou THEN
    mostrarDados sreg, MID$(slinha, 1, nTamLinha), 3
    nCont = nCont + 1
  END IF

  bQuebra = ContinuaSN(nCont, nQtdLinha)
LOOP
ListarTodos = bret
END FUNCTION

'------------------------------------------------------------------------------
'Mostra os menus do sistema.
'num - o n£mero do menu
'------------------------------------------------------------------------------
SUB menu (num AS INTEGER)
 IF (num = 1) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| (C)adastros        (P)esquisas     (V)endas        (O)pá‰es  |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 2) THEN
   PRINT "*---------------------------------*"
   PRINT "| 01. Cadastro de Assuntos        |"
   PRINT "| 02. Cadastro de Autores         |"
   PRINT "| 03. Cadastro de Editoras        |"
   PRINT "| 04. Cadastro de Endereáos       |"
   PRINT "| 05. Cadastro de Idiomas         |"
   PRINT "| 06. Cadastro de Pa°ses          |"
   PRINT "| 07. Cadastro de Profiss‰es      |"
   PRINT "| 08. Cadastro de Clientes        |"
   PRINT "| 09. Cadastro de Livros          |"
   PRINT "| 10. Voltar ao menu              |"
   PRINT "*---------------------------------*"
 ELSEIF (num = 3) THEN
   PRINT "*---------------------------------*"
   PRINT "| 01. Consulta de Assuntos        |"
   PRINT "| 02. Consulta de Autores         |"
   PRINT "| 03. Consulta de Editoras        |"
   PRINT "| 04. Consulta de Endereáos       |"
   PRINT "| 05. Consulta de Idiomas         |"
   PRINT "| 06. Consulta de Pa°ses          |"
   PRINT "| 07. Consulta de Profiss‰es      |"
   PRINT "| 08. Consulta de Clientes        |"
   PRINT "| 09. Consulta de Livros          |"
   PRINT "| 10. Voltar ao menu              |"
   PRINT "*---------------------------------*"
 ELSEIF (num = 4) THEN
   PRINT "*---------------------------------*"
   PRINT "| 01. Vender Livros               |"
   PRINT "| 02. Vendas Realizadas           |"
   PRINT "| 03. Voltar ao menu              |"
   PRINT "*---------------------------------*"
 ELSEIF (num = 5) THEN
   PRINT "*---------------------------------*"
   PRINT "| 01. Alterar senha               |"
   PRINT "| 02. Sobre o sistema             |"
   PRINT "| 03. Sair do sistema             |"
   PRINT "| 04. Voltar ao menu              |"
   PRINT "*---------------------------------*"
 ELSEIF (num = 6) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 7) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| (1) Salvar inclus∆o       (2) Voltar ao menu                 |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 8) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 9) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| (1) Salvar alteraá∆o      (2) Voltar ao menu                 |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 10) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| Certeza de excluir? (S/N)                                    |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 11) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| Deseja sair do sistema? (S/N)                                |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 12) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 13) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| Deseja continuar? (S/N)                                      |"
   PRINT "*--------------------------------------------------------------*"
 ELSEIF (num = 14) THEN
   PRINT "*--------------------------------------------------------------*"
   PRINT "| Salvar inclus∆o (S/N)                                        |"
   PRINT "*--------------------------------------------------------------*"
 END IF
 PRINT MSGOPCAO;
END SUB

'------------------------------------------------------------------------------
'Calcula o modulo11 de um valor qualquer.
'svalor - a string com o n£mero a ser calculado
'ndig - d°gito do valor a ser calculado
'retorna - o d°gito correto
'------------------------------------------------------------------------------
FUNCTION modulo11! (svalor AS STRING, ndig AS INTEGER)
Dim ncont As Integer, nsoma As Integer
Dim nvalor As Integer, npos As Integer
Dim sres As String, slocal As String

 ncont = 1
 do while ncont <= 11 
   slocal = mid$(svalor, ncont,1) + slocal
   ncont = ncont+1
 loop
 nsoma = 0
 if ndig=1 then
   ncont = 3
 else
   ncont = 2
 end if
 npos = 2
 do while ncont <= 11
   sres = mid$(slocal,ncont,1)
   nvalor = Val(sres)
   nsoma = nsoma + (nvalor * npos)
   ncont = ncont+1
   npos = npos+1
 loop
 nsoma = (11 - (nsoma mod 11))

 if nsoma > 9 then
   modulo11 = 0
 else
   modulo11 = nsoma
 end if
END FUNCTION

'------------------------------------------------------------------------------
'Mostra as entradas e as sa°das do sistema.
'sreg - o tipo de arquivo
'slinha - o registro com os dados
'nOpcao - indica qual opá∆o ser† mostrada
'------------------------------------------------------------------------------
SUB mostrarDados (sreg AS INTEGER, slinha AS STRING, nOpcao AS INTEGER)
IF sreg = opAssunto THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 1) + tAssunto.codigo
	PRINT rotulo(sreg, 2);
	INPUT "", tAssunto.assunto
     CASE 2
	PRINT "C¢digo     Assunto"
	PRINT "------     -------"
     CASE 3
	tAssunto.codigo = MID$(slinha, 1, 10)
	tAssunto.assunto = MID$(slinha, 11, 30)
	PRINT tAssunto.codigo + " " + tAssunto.assunto
   END SELECT
ELSEIF sreg = opAutor THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 1) + tAutor.codigo
	PRINT rotulo(sreg, 2);
	INPUT "", tAutor.autor
     CASE 2
	PRINT "C¢digo     Autor"
	PRINT "------     -----"
     CASE 3
	tAutor.codigo = MID$(slinha, 1, 10)
	tAutor.autor = MID$(slinha, 11, 30)
	PRINT tAutor.codigo + " " + tAutor.autor
   END SELECT
ELSEIF sreg = opEditora THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 1) + tEditora.codigo
	PRINT rotulo(sreg, 2);
	INPUT "", tEditora.editora
     CASE 2
	PRINT "C¢digo     Editora"
	PRINT "------     -------"
     CASE 3
	tEditora.codigo = MID$(slinha, 1, 10)
	tEditora.editora = MID$(slinha, 11, 50)
	PRINT tEditora.codigo + " " + tEditora.editora
   END SELECT
ELSEIF sreg = opEndereco THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 1) + tEndereco.codigo
	PRINT rotulo(sreg, 2);
	INPUT "", tEndereco.Logradouro
	PRINT rotulo(sreg, 3);
	INPUT "", tEndereco.bairro
	PRINT rotulo(sreg, 4);
	INPUT "", tEndereco.cep
	PRINT rotulo(sreg, 5);
	INPUT "", tEndereco.cidade
	PRINT rotulo(sreg, 6);
	INPUT "", tEndereco.estado
     CASE 3
	tEndereco.codigo = Trim$(MID$(slinha, 1, 10))
	tEndereco.Logradouro = Trim$(MID$(slinha, 11, 40))
	tEndereco.bairro = Trim$(MID$(slinha, 51, 15))
	tEndereco.cep = Trim$(MID$(slinha, 66, 8))
	tEndereco.cidade = Trim$(MID$(slinha, 74, 30))
	tEndereco.estado = Trim$(MID$(slinha, 104, 20))
	PRINT "--------------------"
	PRINT rotulo(sreg, 1) + tEndereco.codigo
	PRINT rotulo(sreg, 2) + tEndereco.Logradouro
	PRINT rotulo(sreg, 3) + tEndereco.bairro
	PRINT rotulo(sreg, 4) + tEndereco.cep
	PRINT rotulo(sreg, 5) + tEndereco.cidade
	PRINT rotulo(sreg, 6) + tEndereco.estado
   END SELECT
ELSEIF sreg = opIdioma THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 1) + tIdioma.codigo
	PRINT rotulo(sreg, 2);
	INPUT "", tIdioma.idioma
     CASE 2
	PRINT "C¢digo     Idioma"
	PRINT "------     ------"
     CASE 3
	tIdioma.codigo = MID$(slinha, 1, 10)
	tIdioma.idioma = MID$(slinha, 11, 20)
	PRINT tIdioma.codigo + " " + tIdioma.idioma
   END SELECT
ELSEIF sreg = opPais THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 2);
	INPUT "", tPais.pais
     CASE 2
	PRINT "C¢digo Pa°s"
	PRINT "------ ----"
     CASE 3
	tPais.codigo = MID$(slinha, 1, 3)
	tPais.pais = MID$(slinha, 4, 50)
	PRINT tPais.codigo + "    " + tPais.pais
   END SELECT
ELSEIF sreg = opProfissao THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 1) + tProfissao.codigo
	PRINT rotulo(sreg, 2);
	INPUT "", tProfissao.profissao
     CASE 2
	PRINT "C¢digo     Profiss∆o"
	PRINT "------     ---------"
     CASE 3
	tProfissao.codigo = MID$(slinha, 1, 10)
	tProfissao.profissao = MID$(slinha, 11, 50)
	PRINT tProfissao.codigo + " " + tProfissao.profissao
   END SELECT
ELSEIF sreg = opLivro THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 2);
	INPUT "", tLivro.titulo
	tLivro.edicao = validaNumero(rotulo(sreg, 3), tLivro.edicao)
	tLivro.anopubli = validaNumero(rotulo(sreg, 4), tLivro.anopubli)
	mostrarSubDados opLivro, opEditora, false
	tLivro.volume = validaNumero(rotulo(sreg, 6), tLivro.volume)
	mostrarSubDados opLivro, opIdioma, false
	tLivro.npaginas = validaNumero(rotulo(sreg, 8), tLivro.npaginas)
	tLivro.preco = validaNumero(rotulo(sreg, 9), tLivro.preco)
	tLivro.qtdestoque = validaNumero(rotulo(sreg, 10), tLivro.qtdestoque)
     CASE 3
	tLivro.isbn = Trim$(MID$(slinha, 1, 13))
	tLivro.titulo = Trim$(MID$(slinha, 14, 50))
	tLivro.edicao = Trim$(MID$(slinha, 64, 10))
	tLivro.anopubli = Trim$(MID$(slinha, 74, 10))
	tLivro.codeditora = Trim$(MID$(slinha, 84, 10))
	tLivro.volume = Trim$(MID$(slinha, 94, 10))
	tLivro.codidioma = Trim$(MID$(slinha, 104, 10))
	tLivro.npaginas = Trim$(MID$(slinha, 114, 10))
	tLivro.preco = Trim$(MID$(slinha, 124, 10))
	tLivro.qtdestoque = Trim$(MID$(slinha, 134, 10))
	PRINT "--------------------"
	PRINT rotulo(sreg, 1) + tLivro.isbn
	PRINT rotulo(sreg, 2) + tLivro.titulo
	PRINT rotulo(sreg, 3) + tLivro.edicao
	PRINT rotulo(sreg, 4) + tLivro.anopubli
	PRINT rotulo(sreg, 5) + tLivro.codeditora
	mostrarSubDados opLivro, opEditora, true
	PRINT rotulo(sreg, 6) + tLivro.volume
	PRINT rotulo(sreg, 7) + tLivro.codidioma
	mostrarSubDados opLivro, opIdioma, true
	PRINT rotulo(sreg, 8) + tLivro.npaginas
	PRINT rotulo(sreg, 9) + tLivro.preco
	PRINT rotulo(sreg, 10) + tLivro.qtdestoque
	ListarRegLigados tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn, tfAssunto, opAssunto, 1, 4
	ListarRegLigados tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn, tfAutor, opAutor, 1, 4
   END SELECT
ELSEIF sreg = opCliente THEN
   SELECT CASE nOpcao
     CASE 1
	PRINT rotulo(sreg, 2);
	INPUT "", tCliente.nome
	PRINT rotulo(sreg, 3);
	PRINT "", tCliente.email
	PRINT rotulo(sreg, 4);
	INPUT "", tCliente.identidade
	PRINT rotulo(sreg, 5);
	INPUT "", tCliente.sexo
	PRINT rotulo(sreg, 6);
	INPUT "", tCliente.telefone
	tCliente.dtnascimento = validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true)
	mostrarSubDados opCliente, opEndereco, false
	mostrarSubDados opCliente, opPais, false
	mostrarSubDados opCliente, opProfissao, false
     CASE 3
	tCliente.cpf = Trim$(MID$(slinha, 1, 14))
	tCliente.nome = Trim$(MID$(slinha, 15, 30))
	tCliente.email = Trim$(MID$(slinha, 45, 30))
	tCliente.identidade = Trim$(MID$(slinha, 75, 10))
	tCliente.sexo = Trim$(MID$(slinha, 85, 1))
	tCliente.telefone = Trim$(MID$(slinha, 86, 17))
	tCliente.dtnascimento = Trim$(MID$(slinha, 103, 10))
	tCliente.codendereco = Trim$(MID$(slinha, 113, 10))
	tCliente.codpais = Trim$(MID$(slinha, 123, 3))
	tCliente.codprofissao = Trim$(MID$(slinha, 126, 10))
	PRINT "--------------------"
	PRINT rotulo(sreg, 1) + tCliente.cpf
	PRINT rotulo(sreg, 2) + tCliente.nome
	PRINT rotulo(sreg, 3) + tCliente.email
	PRINT rotulo(sreg, 4) + tCliente.identidade
	PRINT rotulo(sreg, 5) + tCliente.sexo
	PRINT rotulo(sreg, 6) + tCliente.telefone
	PRINT rotulo(sreg, 7) + tCliente.dtnascimento
	PRINT rotulo(sreg, 8) + tCliente.codendereco
	mostrarSubDados opCliente, opEndereco, true
	PRINT rotulo(sreg, 9) + tCliente.codpais
	mostrarSubDados opCliente, opPais, true
	PRINT rotulo(sreg, 10) + tCliente.codprofissao
	mostrarSubDados opCliente, opProfissao, true
   END SELECT
ELSEIF sreg = opVenda THEN
   SELECT CASE nOpcao
     CASE 1
       mostrarSubDados opVenda, opVenda, false
     CASE 2
	PRINT "DataHoraVenda       CPF            ISBN          PreáoVenda"
	PRINT "-------------       ---            ----          ----------"
     CASE 3
	tVenda.dthrvenda = MID$(slinha, 1, 19)
	tVenda.cpf = MID$(slinha, 20, 14)
	tVenda.isbn = MID$(slinha, 34, 13)
	tVenda.precovenda = MID$(slinha, 47, 10)
	PRINT tVenda.dthrvenda + " " + tVenda.cpf + " " + tVenda.isbn + " " + tVenda.precovenda
   END SELECT
END IF

END SUB

'------------------------------------------------------------------------------
'Mostra as sub informá‰es de entrada e de sa°da.
'sreg - o tipo de arquivo
'ssubreg - o subtipo de arquivo
'bSoMostrar - se vai s¢ mostrar na sa°da
'------------------------------------------------------------------------------
SUB mostrarSubDados (sreg AS INTEGER, ssubreg AS INTEGER, bSoMostrar AS INTEGER)
DIM sRegistro AS STRING, sPreco AS STRING
DIM ntam AS INTEGER, nMaxTentativas AS INTEGER

nMaxTentativas = 3
IF sreg = opLivro THEN
  IF ssubreg = opEditora THEN
    IF bSoMostrar THEN
       ntam = tamReg(opEditora)
       sRegistro = pesqArq(tfEditora, tLivro.codeditora, 1, 10, ntam)
    ELSE
       sRegistro = validaEntrada(tfEditora, ssubreg, 1, tLivro.codeditora, nMaxTentativas, false, opNumero)
    END IF
    IF sRegistro <> "" THEN
      tLivro.codeditora = Trim$(MID$(sRegistro, 1, 10))
      PRINT " " + rotulo(opEditora, 2);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
    END IF
  ELSEIF ssubreg = opIdioma THEN
    IF bSoMostrar THEN
       ntam = tamReg(opIdioma)
       sRegistro = pesqArq(tfIdioma, tLivro.codidioma, 1, 10, ntam)
    ELSE
       sRegistro = validaEntrada(tfIdioma, ssubreg, 1, tLivro.codidioma, nMaxTentativas, false, opNumero)
    END IF
    IF sRegistro <> "" THEN
      tLivro.codidioma = Trim$(MID$(sRegistro, 1, 10))
      PRINT " " + rotulo(opIdioma, 2);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
    END IF
  END IF
ELSEIF sreg = opCliente THEN
  IF ssubreg = opEndereco THEN
    IF bSoMostrar THEN
       ntam = tamReg(opEndereco)
       sRegistro = pesqArq(tfEndereco, tCliente.codendereco, 1, 10, ntam)
    ELSE
       sRegistro = validaEntrada(tfEndereco, ssubreg, 1, tCliente.codendereco, nMaxTentativas, false, opNumero)
    END IF
    IF sRegistro <> "" THEN
      tCliente.codendereco = Trim$(MID$(sRegistro, 1, 10))
      PRINT " " + rotulo(opEndereco, 2);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
      PRINT " " + rotulo(opEndereco, 3);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
      PRINT " " + rotulo(opEndereco, 4);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
      PRINT " " + rotulo(opEndereco, 5);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
      PRINT " " + rotulo(opEndereco, 6);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
    END IF
  ELSEIF ssubreg = opPais THEN
    IF bSoMostrar THEN
       ntam = tamReg(opPais)
       sRegistro = pesqArq(tfPais, tCliente.codpais, 1, 3, ntam)
    ELSE
       sRegistro = validaEntrada(tfPais, ssubreg, 1, tCliente.codpais, nMaxTentativas, false, opTexto)
    END IF
    IF sRegistro <> "" THEN
      tCliente.codpais = Trim$(MID$(sRegistro, 1, 3))
      PRINT " " + rotulo(opPais, 2);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
    END IF
  ELSEIF ssubreg = opProfissao THEN
    IF bSoMostrar THEN
       ntam = tamReg(opProfissao)
       sRegistro = pesqArq(tfProfissao, tCliente.codprofissao, 1, 10, ntam)
    ELSE
       sRegistro = validaEntrada(tfProfissao, ssubreg, 1, tCliente.codprofissao, nMaxTentativas, false, opNumero)
    END IF
    IF sRegistro <> "" THEN
      tCliente.codprofissao = Trim$(MID$(sRegistro, 1, 10))
      PRINT " " + rotulo(opProfissao, 2);
      PRINT MID$(sRegistro, gnPosChave, gnTamChave)
    END IF
  END IF
ELSEIF sreg = opVenda THEN
  ntam = tamReg(opLivro)
  sRegistro = pesqArq(tfLivro, tVenda.isbn, 1, 13, ntam)
  IF sRegistro <> "" THEN
    PRINT " " + rotulo(opLivro, 2); ' Titulo
    PRINT MID$(sRegistro, gnPosChave, gnTamChave)
    PRINT " ", rotulo(opLivro, 9); ' Preco
    sPreco = MID$(sRegistro, gnPosChave, gnTamChave)
    gnPreco = VAL(sPreco)
    PRINT sPreco
  END IF
END IF
END SUB

'------------------------------------------------------------------------------
'Pesquisa um registro atravÇs de um valor chave num arquivo.
'sArq - o arquivo
'sChave - a chave a ser pesquisada
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'nTamLinha - o tamanho do registro
'retorna - o registro pesquisado
'------------------------------------------------------------------------------
FUNCTION pesqArq$ (sArq AS INTEGER, sChave AS STRING, nPosChave AS INTEGER, nTamChave AS INTEGER, nTamLinha AS INTEGER)
DIM slinha AS STRING
DIM sres AS STRING
DIM bQuebra AS INTEGER

bQuebra = false
SEEK sArq, 1
DO WHILE (NOT EOF(sArq)) AND (bQuebra = false)
  LINE INPUT #sArq, slinha
  sres = Trim$(MID$(slinha, nPosChave, nTamChave))
  IF sres = sChave THEN
     bQuebra = true
  END IF
LOOP
gnPosicao = SEEK(sArq) - (nTamLinha + TAMCRLF)
IF gnPosicao > 1 THEN
   SEEK sArq, gnPosicao
ELSE
   SEEK sArq, 1
END IF
IF sres <> sChave THEN
   pesqArq = ""
ELSE
   pesqArq = MID$(slinha, 1, nTamLinha)
END IF
END FUNCTION

'------------------------------------------------------------------------------
'Pesquisa se tem linha exclu°da sen∆o vai para a £ltima linha do arquivo.
'sArq - o arquivo
'nTamLinha - o tamanho do registro
'------------------------------------------------------------------------------
SUB pesqLinhaExcluida (sArq AS INTEGER, nTamLinha AS INTEGER)
DIM sExcluido AS STRING

sExcluido = pesqArq(sArq, "*", 1, 1, nTamLinha)
IF sExcluido = "" THEN
   SEEK sArq, tamArq(sArq)
   gnPosicao = SEEK(sArq)
END IF
END SUB

'------------------------------------------------------------------------------
'Pesquisa o maior c¢digo num arquivo.
'sArq - o arquivo
'nPosChave - a posicao inicial da chave dentro do registro
'nTamChave - o tamanho da chave dentro do registro
'nTamLinha - o tamanho do registro
'retorna - o maior c¢digo
'------------------------------------------------------------------------------
FUNCTION pesqMaxCod$ (sArq AS INTEGER, nPosChave AS INTEGER, nTamChave AS INTEGER, nTamLinha AS INTEGER)
DIM slinha AS STRING
DIM sres AS STRING
DIM bQuebra AS INTEGER
DIM nStatus, nMaior, nCod AS INTEGER

bQuebra = false
nMaior = 0
SEEK sArq, 1
DO WHILE (NOT EOF(sArq)) AND (bQuebra = false)
  LINE INPUT #sArq, slinha
  sres = Trim$(MID$(slinha, nPosChave, nTamChave))
  nCod = VAL(sres)
  IF nCod > nMaior THEN
     nMaior = nCod
  END IF
LOOP
pesqLinhaExcluida sArq, nTamLinha
sres = STR$(nMaior + 1)
pesqMaxCod = Trim$(sres)
END FUNCTION

'------------------------------------------------------------------------------
'Repete um texto um n£mero determinado de vezes.
'sTexto - o texto a ser repetido
'nQtd - a quantidade de vezes
'retorna - o texto repetido
'------------------------------------------------------------------------------
FUNCTION repete$ (sTexto AS STRING, nQtd AS INTEGER)
DIM nCont AS INTEGER
DIM sret AS STRING

sret = ""
FOR nCont = 1 TO nQtd
    sret = sret + sTexto
NEXT nCont
repete = sret
END FUNCTION

'------------------------------------------------------------------------------
'Retorna a Data e a hora do sistema.
'retorna - a data e a hora
'------------------------------------------------------------------------------
FUNCTION retDataHora$
  retDataHora = MID$(DATE$, 4, 2) + "/" + LEFT$(DATE$, 2) + "/" + MID$(DATE$, 7, 2) + " " + TIME$
END FUNCTION

'------------------------------------------------------------------------------
'Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'nNum - indica qual rotulo ser† retornado
'retorna - o rotulo
'------------------------------------------------------------------------------
FUNCTION rotulo$ (sreg AS INTEGER, nNum AS INTEGER)
DIM sret AS STRING

sret = ""
IF sreg = opAssunto THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Assunto(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "C¢digo do assunto: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Assunto: "
	 gnPosChave = 11
	 gnTamChave = 30
   END SELECT
ELSEIF sreg = opAutor THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Autor(es) n∆o encontrado(s)!"
     CASE 1
	 sret = "C¢digo do autor: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Autor: "
	 gnPosChave = 11
	 gnTamChave = 30
   END SELECT
ELSEIF sreg = opEditora THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Editora(s) n∆o encontrada(s)!"
     CASE 1
	 sret = "C¢digo da editora: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Editora: "
	 gnPosChave = 11
	 gnTamChave = 50
   END SELECT
ELSEIF sreg = opEndereco THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Endereáo(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "C¢digo do endereáo: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Logradouro: "
	 gnPosChave = 11
	 gnTamChave = 40
     CASE 3
	 sret = "Bairro: "
	 gnPosChave = 51
	 gnTamChave = 15
     CASE 4
	 sret = "CEP: "
	 gnPosChave = 66
	 gnTamChave = 8
     CASE 5
	 sret = "Cidade: "
	 gnPosChave = 74
	 gnTamChave = 30
     CASE 6
	 sret = "Estado: "
	 gnPosChave = 104
	 gnTamChave = 20
   END SELECT
ELSEIF sreg = opIdioma THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Idioma(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "C¢digo do idioma: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Idioma: "
	 gnPosChave = 11
	 gnTamChave = 20
   END SELECT
ELSEIF sreg = opPais THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Pa°s(es) n∆o encontrado(s)!"
     CASE 1
	 sret = "C¢digo do pa°s: "
	 gnPosChave = 1
	 gnTamChave = 3
     CASE 2
	 sret = "Pa°s: "
	 gnPosChave = 4
	 gnTamChave = 50
   END SELECT
ELSEIF sreg = opProfissao THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Profiss∆o(es) n∆o encontrada(s)!"
     CASE 1
	 sret = "C¢digo da profiss∆o: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Profiss∆o: "
	 gnPosChave = 11
	 gnTamChave = 50
   END SELECT
ELSEIF sreg = opUsuario THEN
   SELECT CASE nNum
     CASE 0
	 sret = "login ou senha incorreta, tente de novo!"
     CASE 1
	 sret = "Login: "
	 gnPosChave = 1
	 gnTamChave = 10
     CASE 2
	 sret = "Senha: "
	 gnPosChave = 11
	 gnTamChave = 10
   END SELECT
ELSEIF sreg = opLivro THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Livro(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "ISBN: "
	 gnPosChave = 1
	 gnTamChave = 13
     CASE 2
	 sret = "T°tulo: "
	 gnPosChave = 14
	 gnTamChave = 50
     CASE 3
	 sret = "Ediá∆o: "
	 gnPosChave = 64
	 gnTamChave = 10
     CASE 4
	 sret = "Ano de Publicaá∆o: "
	 gnPosChave = 74
	 gnTamChave = 10
     CASE 5
	 sret = "C¢digo da editora: "
	 gnPosChave = 84
	 gnTamChave = 10
     CASE 6
	 sret = "Volume: "
	 gnPosChave = 94
	 gnTamChave = 10
     CASE 7
	 sret = "C¢digo do idioma: "
	 gnPosChave = 104
	 gnTamChave = 10
     CASE 8
	 sret = "N£mero de p†ginas: "
	 gnPosChave = 114
	 gnTamChave = 10
     CASE 9
	 sret = "Preáo: "
	 gnPosChave = 124
	 gnTamChave = 10
     CASE 10
	  sret = "Qtd. Estoque: "
	  gnPosChave = 134
	  gnTamChave = 10
   END SELECT
ELSEIF sreg = opLivroAss THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Assunto(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "ISBN: "
	 gnPosChave = 1
	 gnTamChave = 13
     CASE 2
	 sret = "C¢digo do assunto: "
	 gnPosChave = 14
	 gnTamChave = 10
   END SELECT
ELSEIF sreg = opLivroAut THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Autor(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "ISBN: "
	 gnPosChave = 1
	 gnTamChave = 13
     CASE 2
	 sret = "C¢digo do autor: "
	 gnPosChave = 14
	 gnTamChave = 10
   END SELECT
ELSEIF sreg = opCliente THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Cliente(s) n∆o encontrado(s)!"
     CASE 1
	 sret = "CPF: "
	 gnPosChave = 1
	 gnTamChave = 14
     CASE 2
	 sret = "Nome: "
	 gnPosChave = 15
	 gnTamChave = 30
     CASE 3
	 sret = "E-mail: "
	 gnPosChave = 45
	 gnTamChave = 30
     CASE 4
	 sret = "Identidade: "
	 gnPosChave = 75
	 gnTamChave = 10
     CASE 5
	 sret = "Sexo: "
	 gnPosChave = 85
	 gnTamChave = 1
     CASE 6
	 sret = "Telefone: "
	 gnPosChave = 86
	 gnTamChave = 17
     CASE 7
	 sret = "Dt. Nascimento: "
	 gnPosChave = 103
	 gnTamChave = 10
     CASE 8
	 sret = "C¢digo do endereáo: "
	 gnPosChave = 113
	 gnTamChave = 10
     CASE 9
	 sret = "C¢digo do pa°s: "
	 gnPosChave = 123
	 gnTamChave = 3
     CASE 10
	  sret = "C¢digo da Profiss∆o: "
	  gnPosChave = 126
	  gnTamChave = 10
   END SELECT
ELSEIF sreg = opVenda THEN
   SELECT CASE nNum
     CASE 0
	 sret = "Venda(s) n∆o encontrada(s)!"
     CASE 1
	 sret = "Data/Hora venda: "
	 gnPosChave = 1
	 gnTamChave = 19
     CASE 2
	 sret = "CPF: "
	 gnPosChave = 20
	 gnTamChave = 14
     CASE 3
	 sret = "ISBN: "
	 gnPosChave = 34
	 gnTamChave = 13
     CASE 4
	 sret = "Pre+o de venda: "
	 gnPosChave = 47
	 gnTamChave = 10
   END SELECT
END IF

rotulo = sret
END FUNCTION

'------------------------------------------------------------------------------
'Faz uma pesquisa relativa de um texto atravÇs de um valor chave.
'sTexto - o texto
'sChave - a chave a ser pesquisada
'retorna - se achou ou n∆o a chave dentro do texto
'------------------------------------------------------------------------------
FUNCTION strRelativa! (sTexto AS STRING, sChave AS STRING)
DIM nCont, nTamChave, nTamTexto AS INTEGER
DIM bret AS INTEGER
DIM sPedaco AS STRING

bret = false
nCont = 1
nTamChave = LEN(sChave)
nTamTexto = LEN(sTexto)
IF nTamChave <= nTamTexto THEN
  DO WHILE nCont <= (nTamTexto - nTamChave + 1)
     sPedaco = MID$(sTexto, nCont, nTamChave)
     IF sPedaco = sChave THEN
	bret = true
     END IF
     nCont = nCont + 1
  LOOP
END IF
strRelativa = bret
END FUNCTION

'------------------------------------------------------------------------------
'Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
'nmenu - o n£mero do menu
'sreg - o tipo de arquivo
'------------------------------------------------------------------------------
SUB subMenu (nmenu AS INTEGER, sreg AS INTEGER)
DIM opSubMenu AS INTEGER
DIM opCSubMenu AS STRING
DIM bSOp AS INTEGER

bSOp = true
SELECT CASE nmenu
 CASE 6
    DO WHILE bSOp
     menu (nmenu)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 frmCadastros sreg, opNovo
       CASE 2
	 frmCadastros sreg, opPesquisar
       CASE 3
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
    LOOP
 CASE 7
    DO WHILE bSOp
     menu (nmenu)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 btnAcao sreg, opSalvarInclusao
	 bSOp = false
       CASE 2
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
    LOOP
 CASE 8
    DO WHILE bSOp
     menu (nmenu)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 frmCadastros sreg, opAlterar
	 bSOp = false
       CASE 2
	 frmCadastros sreg, opExcluir
	 bSOp = false
       CASE 3
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
    LOOP
 CASE 9
    DO WHILE bSOp
     menu nmenu
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 btnAcao sreg, opSalvarAlteracao
	 bSOp = false
       CASE 2
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
    LOOP
 CASE 10
    DO WHILE bSOp
     menu (nmenu)
     INPUT "", opCSubMenu
     IF (opCSubMenu = "S") OR (opCSubMenu = "s") THEN
	btnAcao sreg, opConfirmaExclusao
	bSOp = false
     ELSEIF (opCSubMenu = "N") OR (opCSubMenu = "n") THEN bSOp = false
     ELSE PRINT MSGERRO
     END IF
    LOOP
 CASE 12
    DO WHILE bSOp
     menu (nmenu)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 frmConsultas sreg, opPesquisar
       CASE 2
	 frmConsultas sreg, opListarTodos
       CASE 3
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
    LOOP
 CASE 14
    DO WHILE bSOp
     menu (nmenu)
     INPUT "", opCSubMenu
     IF (opCSubMenu = "S") OR (opCSubMenu = "s") THEN
	btnAcao sreg, opSalvarInclusao
	bSOp = false
	gSalvarInclusao = true
     ELSEIF (opCSubMenu = "N") OR (opCSubMenu = "n") THEN
	bSOp = false
     ELSE
	PRINT MSGERRO
     END IF
    LOOP
END SELECT

END SUB

'------------------------------------------------------------------------------
'Calcula o tamanho do arquivo.
'sArq - o arquivo
'retorna - o tamanho do arquivo
'------------------------------------------------------------------------------
FUNCTION tamArq! (sArq AS INTEGER)
tamArq = LOF(sArq)
END FUNCTION

'------------------------------------------------------------------------------
'Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
'sreg - o tipo de arquivo
'retorna - o tamanho do registro
'------------------------------------------------------------------------------
FUNCTION tamReg! (sreg AS INTEGER)
DIM nret AS INTEGER

nret = 0
IF sreg = opAssunto THEN
  nret = TAMASSUNTO
ELSEIF sreg = opAutor THEN
  nret = TAMAUTOR
ELSEIF sreg = opEditora THEN
  nret = TAMEDITORA
ELSEIF sreg = opEndereco THEN
  nret = TAMENDERECO
ELSEIF sreg = opIdioma THEN
  nret = TAMIDIOMA
ELSEIF sreg = opPais THEN
  nret = TAMPAIS
ELSEIF sreg = opProfissao THEN
  nret = TAMPROFISSAO
ELSEIF sreg = opUsuario THEN
  nret = TAMUSUARIO
ELSEIF sreg = opLivro THEN
  nret = TAMLIVRO
ELSEIF sreg = opLivroAss THEN
  nret = TAMLIVASS
ELSEIF sreg = opLivroAut THEN
  nret = TAMLIVAUT
ELSEIF sreg = opCliente THEN
  nret = TAMCLIENTE
ELSEIF sreg = opVenda THEN
  nret = TAMVENDA
END IF
tamReg = nret
END FUNCTION

'------------------------------------------------------------------------------
'Retira os espaáos em branco antes ou depois do texto.
'sTexto - o texto a ser retirado os espaáos em branco
'retorna - o texto sem os espaáos em branco
'------------------------------------------------------------------------------
FUNCTION Trim$ (sTexto AS STRING)
DIM slocal AS STRING
  slocal = LTRIM$(sTexto)
  slocal = RTRIM$(slocal)
  Trim$ = slocal
END FUNCTION

'------------------------------------------------------------------------------
'Seleciona o submenu e/ou a tela certa de acordo com n£mero do menu.
'nmenu - o n£mero do menu
'------------------------------------------------------------------------------
SUB usaMenu (num AS INTEGER)
DIM opSubMenu AS INTEGER
DIM bSOp AS INTEGER
DIM opSair AS STRING

 bSOp = true
 IF num = 1 THEN  ' Cadastros
   DO WHILE bSOp
     menu (2)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 subMenu 6, opAssunto
       CASE 2
	 subMenu 6, opAutor
       CASE 3
	 subMenu 6, opEditora
       CASE 4
	 subMenu 6, opEndereco
       CASE 5
	 subMenu 6, opIdioma
       CASE 6
	 subMenu 6, opPais
       CASE 7
	 subMenu 6, opProfissao
       CASE 8
	 subMenu 6, opCliente
       CASE 9
	 subMenu 6, opLivro
       CASE 10
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
   LOOP
 ELSEIF num = 2 THEN  ' Pesquisas
   DO WHILE bSOp
     menu (3)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 subMenu 12, opAssunto
       CASE 2
	 subMenu 12, opAutor
       CASE 3
	 subMenu 12, opEditora
       CASE 4
	 subMenu 12, opEndereco
       CASE 5
	 subMenu 12, opIdioma
       CASE 6
	 subMenu 12, opPais
       CASE 7
	 subMenu 12, opProfissao
       CASE 8
	 subMenu 12, opCliente
       CASE 9
	 subMenu 12, opLivro
       CASE 10
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
   LOOP
 ELSEIF num = 3 THEN  ' Vendas
   DO WHILE bSOp
     menu (4)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 subMenu 6, opVenda
       CASE 2
	 subMenu 12, opVenda
       CASE 3
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
   LOOP
 ELSEIF num = 4 THEN  ' Opcoes
   DO WHILE bSOp
     menu (5)
     INPUT "", opSubMenu
     SELECT CASE opSubMenu
       CASE 1
	 frmAlterarSenha
       CASE 2
	 frmSobre
       CASE 3
	   menu (11)
	   INPUT "", opSair
	   IF (opSair = "S") OR (opSair = "s") THEN
	      fechaArqs
	      END
	   END IF
       CASE 4
	 bSOp = false
       CASE ELSE
	 PRINT MSGERRO
     END SELECT
   LOOP
 END IF
END SUB

'------------------------------------------------------------------------------
'Validaá∆o de um n£mero de CPF qualquer.
'cpf - a string com o n£mero do CPF
'retorna - se Ç valido ou n∆o
'------------------------------------------------------------------------------
FUNCTION validaCPF! (cpf AS STRING)
DIM scpf AS STRING, sres AS STRING
DIM nvalor1, nvalor2 AS INTEGER

IF (LEN(cpf) = 14) THEN
  scpf = MID$(cpf, 1, 3) + MID$(cpf, 5, 3) + MID$(cpf, 9, 3) + MID$(cpf, 13, 2)
  sres = MID$(cpf, 13, 1)
  nvalor1 = VAL(sres)
  sres = MID$(cpf, 14, 1)
  nvalor2 = VAL(sres)
  IF ((modulo11(scpf, 1) = nvalor1) AND (modulo11(scpf, 2) = nvalor2)) THEN
    validaCPF = true
  ELSE
    validaCPF = false
  END IF
ELSE
  validaCPF = false
END IF
END FUNCTION

'------------------------------------------------------------------------------
'Validaá∆o de uma data ou data/hora qualquer.
'sRotulo - o texto antes de se digitar a data/hora
'sDataHora - a string com o valor da data/hora
'bSoData - indica se vai validar somente uma data sem a hora
'retorna - a sDataHora
'------------------------------------------------------------------------------
FUNCTION validaDataHora$ (sRotulo AS STRING, sDataHora AS STRING, bSoData AS INTEGER)
DIM bvalida AS INTEGER, bdatavalida  AS INTEGER, bhoravalida AS INTEGER
DIM sdia AS STRING, smes AS STRING, sano AS STRING
DIM shora AS STRING, smin AS STRING, slseg AS STRING
DIM ndia AS INTEGER, nmes AS INTEGER, nano AS INTEGER
DIM nhora AS INTEGER, nmin AS INTEGER, nseg AS INTEGER, nudiames AS INTEGER
DIM ntam AS INTEGER

bvalida = false
bdatavalida = false
bhoravalida = false
nudiames = 0

IF bSoData = true THEN
  ntam = 10
ELSE
  ntam = 19
END IF
DO WHILE (bvalida = false)
  PRINT sRotulo;
  INPUT "", sDataHora
  IF LEN(sDataHora) = ntam THEN
    sdia = MID$(sDataHora, 1, 2)
    ndia = VAL(sdia)
    smes = MID$(sDataHora, 4, 2)
    nmes = VAL(smes)
    sano = MID$(sDataHora, 7, 4)
    nano = VAL(sano)
  
    IF (nano >= 1) AND (nano <= 9999) THEN
      IF (nmes >= 1) AND (nmes <= 31) THEN
	  SELECT CASE nmes
	     CASE 1, 3, 5, 7, 8, 10, 12
	       nudiames = 31
	     CASE 2
		 ' ano bissexto
		 IF (nano MOD 4) = 0 THEN
		   nudiames = 29
		 ELSE
		   nudiames = 28
		 END IF
	     CASE 4, 6, 9, 11
		 nudiames = 30
	  END SELECT
	  IF (ndia >= 1) AND (ndia <= nudiames) THEN
	     bdatavalida = true
	  END IF
      END IF
    END IF
  
    IF bSoData THEN
       IF bdatavalida THEN
	  bvalida = true
       ELSE
	  PRINT MSGDATAINV
       END IF
    ELSE
      IF bdatavalida THEN
	  shora = MID$(sDataHora, 12, 2)
	  nhora = VAL(shora)
	  smin = MID$(sDataHora, 15, 2)
	  nmin = VAL(smin)
	  slseg = MID$(sDataHora, 18, 2)
	  nseg = VAL(slseg)
  
	  IF (nhora >= 0) AND (nhora <= 23) THEN
	    IF (nmin >= 0) AND (nmin <= 59) THEN
	      IF (nseg >= 0) AND (nseg <= 59) THEN
		 bhoravalida = true
	      END IF
	    END IF
	  END IF
  
	  IF bhoravalida THEN
	    bvalida = true
	  ELSE
	    PRINT MSGDTHRINV
	  END IF
      ELSE
	PRINT MSGDTHRINV
      END IF
    END IF
  ELSE
    IF bSoData = true THEN
      PRINT MSGDATAINV
    ELSE
      PRINT MSGDTHRINV
    END IF
  END IF
LOOP
validaDataHora = sDataHora

END FUNCTION

'------------------------------------------------------------------------------
'Valida a entrada de registros de acordo com a pesquisa feita.
'sArq - o arquivo
'sreg - o tipo de arquivo
'nTexto - o numero do r¢tulo da entrada
'sEntrada - a chave a ser pesquisada e validada
'nTentativas - o n£mero m†ximo de tentativas
'bPesqRelativa - indica se vai realizar uma pesquisa relativa
'bTipoEntrada - indica o tipo de entrada
'retorna - o registro pesquisado e validado
'------------------------------------------------------------------------------
FUNCTION validaEntrada$ (sArq AS INTEGER, sreg AS INTEGER, nTexto AS INTEGER, sEntrada AS STRING, nTentativas AS INTEGER, bPesqRelativa AS INTEGER, bTipoEntrada AS INTEGER)
DIM bQuebra AS INTEGER
DIM sres AS STRING, sTexto AS STRING, sMsgErro AS STRING
DIM nCont AS INTEGER, nPosChave AS INTEGER
DIM nTamChave AS INTEGER, nTamLinha AS INTEGER

nTamLinha = tamReg(sreg)
sMsgErro = rotulo(sreg, 0)
sTexto = rotulo(sreg, nTexto)
nPosChave = gnPosChave
nTamChave = gnTamChave

nCont = 1
bQuebra = false
  DO WHILE (bQuebra = false) AND (nCont <= nTentativas)
    IF bTipoEntrada = opTexto THEN
      PRINT sTexto;
      INPUT "", sEntrada
    ELSEIF bTipoEntrada = opNumero THEN
       sEntrada = validaNumero(sTexto, sEntrada)
    ELSEIF bTipoEntrada = opData THEN
       sEntrada = validaDataHora(sTexto, sEntrada, true)
    ELSEIF bTipoEntrada = opDataHora THEN
       sEntrada = validaDataHora(sTexto, sEntrada, false)
    ELSEIF bTipoEntrada = opSenha THEN
       sEntrada = digitaSenha(sTexto, 10)
    END IF

    IF bPesqRelativa THEN
       IF ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha, QTDMAXLINHA, true) THEN
	  sres = " "
       END IF
    ELSE
	sres = pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha)
    END IF

    IF sres = "" THEN
       PRINT sMsgErro
    ELSE
       bQuebra = true
    END IF

    nCont = nCont + 1
  LOOP
validaEntrada = sres
END FUNCTION

'------------------------------------------------------------------------------
'Validaá∆o de um n£mero ISBN qualquer.
'isbn - a string com o n£mero do ISBN
'retorna - se Ç valido ou n∆o
'------------------------------------------------------------------------------
FUNCTION validaISBN! (isbn AS STRING)
Dim snum  As String, sdigito As String, sisbn As String
Dim nvalor As Integer, nsoma As Integer, ncont As Integer

If len(isbn) = 13 Then
  sdigito = mid$(isbn,len(isbn), 1)
  sisbn=""
  for ncont=1 to len(isbn)-1
    if mid$(isbn, ncont, 1)<>"-" then
      sisbn=sisbn + mid$(isbn, ncont,1)
    end if
  next ncont
  if sdigito = "X" then
    nsoma = 10
  else
    nvalor = val(sdigito)
    nsoma = nvalor
  end if
  for ncont = 1 to 9
    snum = mid$(sisbn, ncont, 1)
    nvalor = val(snum)
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
END FUNCTION

'------------------------------------------------------------------------------
'Validaá∆o de um n£mero qualquer.
'sRotulo - o texto antes de se digitar o n£mero
'sNumero - a string com o valor do n£mero
'retorna - o sNumero
'------------------------------------------------------------------------------
FUNCTION validaNumero$ (sRotulo AS STRING, sNumero AS STRING)
DIM nNum AS DOUBLE
DIM nStatus AS INTEGER

nStatus = -1
DO WHILE (nStatus <> 0)
  PRINT sRotulo;
  INPUT "", sNumero
  nNum = VAL(sNumero)
  IF nNum < 1 THEN
     PRINT MSGNUMINV
  ELSE
     nStatus = 0
  END IF
LOOP
validaNumero = sNumero
END FUNCTION

'------------------------------------------------------------------------------
'Escreve zeros na frente de um texto.
'stexto - o texto para receber zeros a frente
'ntam - o tamanho da string
'retorna - o texto com o zeros antes
'------------------------------------------------------------------------------
FUNCTION zeros$ (sTexto AS STRING, ntam AS INTEGER)
DIM nCont AS INTEGER
DIM saux AS STRING

  saux = ""
  IF ntam <> LEN(sTexto) THEN
      FOR nCont = 1 TO ntam - LEN(sTexto)
	saux = saux + "0"
      NEXT nCont
  END IF
  zeros = saux + sTexto
END FUNCTION

