      $SET ANS85 NESTCALL NOOSVS MF LINKCOUNT(100)
      *-------------------------------------------------------------
      * Sistema integrante do projeto Livrus Virtus.
      * Todos os direitos reservados para Henrique F. de Souza.
      * Versão programada na linguagem cobol.
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. Livrus IS INITIAL.
       AUTHOR. Henrique Figueiredo de Souza.
      *-------------------------------------------------------------
       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT tfAssunto ASSIGN TO "assunto.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfAutor ASSIGN TO "autor.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfEditora ASSIGN TO "editora.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfIdioma ASSIGN TO "idioma.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfUsuario ASSIGN TO "usuario.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfPais ASSIGN TO "pais.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfProfissao ASSIGN TO "profissao.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfLivro ASSIGN TO "livro.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfLivroAss ASSIGN TO "livroass.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfLivroAut ASSIGN TO "livroaut.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfCliente ASSIGN TO "cliente.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfEndereco ASSIGN TO "endereco.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
       SELECT tfVenda ASSIGN TO "venda.dat"
              ORGANIZATION IS LINE SEQUENTIAL
              ACCESS MODE IS SEQUENTIAL.
      *-------------------------------------------------------------
       DATA DIVISION.
       FILE SECTION.
       FD tfAssunto is global.
       01 regAssunto is global. 
          05 tAssunto-codigo  PIC X(10) VALUE SPACES.
          05 tAssunto-assunto PIC X(30) VALUE SPACES.
       FD tfAutor is global.
       01 regAutor is global. 
          05 tAutor-codigo  PIC X(10) VALUE SPACES.
          05 tAutor-autor   PIC X(30) VALUE SPACES.
       FD tfEditora is global.
       01 regEditora is global.
          05 tEditora-codigo  PIC X(10) VALUE SPACES.
          05 tEditora-editora PIC X(50) VALUE SPACES.
       FD tfIdioma is global.
       01 regIdioma is global.
          05 tIdioma-codigo  PIC X(10) VALUE SPACES.
          05 tIdioma-idioma  PIC X(20) VALUE SPACES.
       FD tfUsuario is global.
       01 regUsuario is global. 
          05 tUsuario-login   PIC X(10) VALUE SPACES.
          05 tUsuario-senha   PIC X(10) VALUE SPACES.
       FD tfPais is global.
       01 regPais is global. 
          05 tPais-codigo  PIC X(3) VALUE SPACES.
          05 tPais-pais    PIC X(50) VALUE SPACES.
       FD tfProfissao is global.
       01 regProfissao is global. 
          05 tProfissao-codigo    PIC X(10) VALUE SPACES.
          05 tProfissao-profissao PIC X(50) VALUE SPACES.
       FD tfLivro is global.
       01 regLivro is global.
          05 tLivro-isbn       PIC X(13) VALUE SPACES.
          05 tLivro-titulo     PIC X(50) VALUE SPACES.
          05 tLivro-edicao     PIC 9(10) VALUE ZEROS.
          05 tLivro-anopubli   PIC 9(10) VALUE ZEROS.
          05 tLivro-codeditora PIC 9(10) VALUE ZEROS.
          05 tLivro-volume     PIC 9(10) VALUE ZEROS.
          05 tLivro-codidioma  PIC 9(10) VALUE ZEROS.
          05 tLivro-npaginas   PIC 9(10) VALUE ZEROS.
          05 tLivro-preco      PIC X(10) VALUE SPACES.
          05 tLivro-qtdestoque PIC 9(10) VALUE ZEROS.
       FD tfLivroAss is global.
       01 regLivroAss is global.
          05 tLivroAss-isbn       PIC X(13) VALUE SPACES.
          05 tLivroAss-codassunto PIC X(10) VALUE SPACES.
       FD tfLivroAut is global.
       01 regLivroAut is global.
          05 tLivroAut-isbn       PIC X(13) VALUE SPACES.
          05 tLivroAut-codautor   PIC X(10) VALUE SPACES.
       FD tfCliente is global.
       01 regCliente is global.
          05 tCliente-cpf          PIC X(14) VALUE SPACES.
          05 tCliente-nome         PIC X(30) VALUE SPACES.
          05 tCliente-email        PIC X(30) VALUE SPACES.
          05 tCliente-identidade   PIC X(10) VALUE SPACES.
          05 tCliente-sexo         PIC X VALUE SPACES.
          05 tCliente-telefone     PIC X(17) VALUE SPACES.
          05 tCliente-dtnascimento PIC X(10) VALUE SPACES.
          05 tCliente-codendereco  PIC X(10) VALUE SPACES.
          05 tCliente-codpais      PIC X(3) VALUE SPACES.
          05 tCliente-codprofissao PIC X(10) VALUE SPACES.
       FD tfEndereco is global.
       01 regEndereco is global.
          05 tEndereco-codigo     PIC X(10) VALUE SPACES.
          05 tEndereco-logradouro PIC X(40) VALUE SPACES.
          05 tEndereco-bairro     PIC X(15) VALUE SPACES.
          05 tEndereco-cep        PIC X(8) VALUE SPACES.
          05 tEndereco-cidade     PIC X(30) VALUE SPACES.
          05 tEndereco-estado     PIC X(20) VALUE SPACES.
       FD tfVenda is global.
       01 regVenda is global.
      *   data/hora da venda dd/mm/yyyy hh:mm:ss
          05 tVenda-dthrvenda  PIC X(19) VALUE SPACES.
          05 tVenda-cpf        PIC X(14) VALUE SPACES.
          05 tVenda-isbn       PIC X(13) VALUE SPACES.
          05 tVenda-precovenda PIC X(10) VALUE SPACES.
      *-------------------------------------------------------------
       WORKING-STORAGE SECTION.
       01 g-false       PIC 9     VALUE 0 is global.
       01 g-true        PIC 9     VALUE 1 is global.
       
      * ctTipo 
       01 opTexto     PIC 9     VALUE 1 is global.
       01 opNumero    PIC 9     VALUE 2 is global.
       01 opData      PIC 9     VALUE 3 is global.
       01 opDataHora  PIC 9     VALUE 4 is global.
       01 opSenha     PIC 9     VALUE 5 is global.
      * ctArqs 
       01 opAssunto   PIC 99     VALUE 1 is global.
       01 opAutor     PIC 99     VALUE 2 is global.
       01 opEditora   PIC 99     VALUE 3 is global.
       01 opEndereco  PIC 99     VALUE 4 is global.
       01 opIdioma    PIC 99     VALUE 5 is global.
       01 opPais      PIC 99     VALUE 6 is global.
       01 opProfissao PIC 99     VALUE 7 is global.
       01 opCliente   PIC 99     VALUE 8 is global.
       01 opLivro     PIC 99     VALUE 9 is global.
       01 opLivroAss  PIC 99     VALUE 10 is global.
       01 opLivroAut  PIC 99     VALUE 11 is global.
       01 opUsuario   PIC 99     VALUE 12 is global.
       01 opVenda     PIC 99     VALUE 13 is global.
      * ctAcao 
       01 opNovo             PIC 9     VALUE 1 is global.
       01 opAlterar          PIC 9     VALUE 2 is global.
       01 opPesquisar        PIC 9     VALUE 3 is global.
       01 opSalvarInclusao   PIC 9     VALUE 4 is global.
       01 opSalvarAlteracao  PIC 9     VALUE 5 is global.
       01 opExcluir          PIC 9     VALUE 6 is global.
       01 opConfirmaExclusao PIC 9     VALUE 7 is global.
       01 opListarTodos      PIC 9     VALUE 8 is global.

       01 TAM-MAX-STR   PIC 9(3)  VALUE 255 is global.
       01 QTD-MAX-LINHA PIC 99    VALUE 18 is global.

       01 MSG-ERRO      PIC X(35) VALUE 
          "Erro: opção inválida digite de novo" is global.
       01 MSG-OPCAO PIC X(19) VALUE "Escolha uma opcao: " is global.
       01 MSG-PRESS PIC X(27) VALUE 
          "pressione para continuar..." is global.

       01 MSG-REGINC PIC X(18) VALUE "registro incluido!" is global.
       01 MSG-REGNINC PIC X(22) VALUE 
            "registro não incluido!" is global.
       01 MSG-REGALT PIC X(18) VALUE "registro alterado!" is global.
       01 MSG-REGNALT PIC X(22) VALUE 
            "registro não alterado!" is global.
       01 MSG-REGEXC PIC X(18) VALUE "registro excluido!" is global.
       01 MSG-REGNEXC PIC X(22) VALUE 
            "registro não excluido!" is global.
       01 MSG-REGEXST PIC X(19) VALUE 
            "registro já existe!" is global.

       01 MSG-NUMINV    PIC X(34) VALUE 
          "Numero invalido ou menor do que 1!" is global.
       01 MSG-DATAINV   PIC X(44) VALUE 
          "Data inválida!, formato correto (dd/mm/yyyy)" is global.
       01 MSG-DTHRINV   PIC X(58) VALUE 
       "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)" 
         is global.
       01 MSG-ISBNINV    PIC X(14) VALUE "ISBN inválido!" is global.
       01 MSG-CPFINV     PIC X(13) VALUE "CPF inválido!" is global.
       01 MSG-SENCONFERE PIC X(36) VALUE 
          "senha não confere com a senha atual!" is global.
       01 MSG-SENCONFIRM PIC X(46) VALUE 
        "nova senha não confere com a senha confirmada!" is global.
       01 MSG-LOGINENCON PIC X(21) VALUE 
          "login não encontrado!" is global.
       01 MSG-SEMESTOQUE PIC X(28) VALUE 
          "livro não existe no estoque!" is global.

       01 ARQ-ASSUNTO   PIC X(11) VALUE "assunto.dat" is global.
       01 ARQ-AUTOR     PIC X(9)  VALUE "autor.dat" is global.
       01 ARQ-EDITORA   PIC X(11) VALUE "editora.dat" is global.
       01 ARQ-IDIOMA    PIC X(10) VALUE "idioma.dat" is global.
       01 ARQ-USUARIO   PIC X(11) VALUE "usuario.dat" is global.
       01 ARQ-PAIS      PIC X(8)  VALUE "pais.dat" is global.
       01 ARQ-PROFISSAO PIC X(13) VALUE "profissao.dat" is global.
       01 ARQ-LIVRO     PIC X(9)  VALUE "livro.dat" is global.
       01 ARQ-LIVASS    PIC X(12) VALUE "livroass.dat" is global.
       01 ARQ-LIVAUT    PIC X(12) VALUE "livroaut.dat" is global.
       01 ARQ-CLIENTE   PIC X(11) VALUE "cliente.dat" is global.
       01 ARQ-ENDERECO  PIC X(12) VALUE "endereco.dat" is global.
       01 ARQ-VENDA     PIC X(9)  VALUE "venda.dat" is global.

       01 TAM-ASSUNTO   PIC 99   VALUE 40 is global.
       01 TAM-AUTOR     PIC 99   VALUE 40 is global.
       01 TAM-EDITORA   PIC 99   VALUE 60 is global.
       01 TAM-IDIOMA    PIC 99   VALUE 30 is global.
       01 TAM-USUARIO   PIC 99   VALUE 20 is global.
       01 TAM-PAIS      PIC 99   VALUE 53 is global.
       01 TAM-PROFISSAO PIC 99   VALUE 60 is global.
       01 TAM-LIVRO     PIC 9(3) VALUE 143 is global.
       01 TAM-LIVASS    PIC 99   VALUE 23 is global.
       01 TAM-LIVAUT    PIC 99   VALUE 23 is global.
       01 TAM-CLIENTE   PIC 9(3) VALUE 135 is global.
       01 TAM-ENDERECO  PIC 9(3) VALUE 123 is global.
       01 TAM-VENDA     PIC 99   VALUE 56 is global.

       01 bopcao        PIC 9    VALUE ZERO.
       01 opmenu        PIC X    VALUE SPACES.
       01 nparam        PIC 9(7) VALUE ZEROS.
       01 g-nPosChave   PIC 9(7) VALUE ZEROS is global.
       01 g-nTamChave   PIC 9(7) VALUE ZEROS is global.
       01 g-nPreco   PIC 9(7)V99 VALUE ZEROS is global.
       01 g-SalvarInclusao PIC 9 VALUE ZERO  is global.

       01 g-retdatahora  PIC X(19)  VALUE SPACES is global.
       01 g-nresto       PIC 9(7)   value zeros  is global.
       01 g-trim         PIC X(255) VALUE SPACES is global.
       01 g-repete       PIC X(255) VALUE SPACES is global.
       01 g-tamstr       PIC 9(7)   VALUE zeros  is global.
       01 g-esp          PIC X(255) VALUE SPACES is global.
       01 g-strRelativa  PIC 9      VALUE zero   is global.
       01 g-modulo11     PIC 9(7)   VALUE zeros  is global.
       01 g-validaCPF    PIC 9      VALUE zero   is global.
       01 g-validaISBN   PIC 9      VALUE zero   is global.
       01 g-digitaSenha  PIC X(255) VALUE SPACES is global.
       01 g-validaNumero PIC X(255) VALUE SPACES is global.
       01 g-validaDataHora PIC X(255) VALUE SPACES is global.
       01 g-pesqArq      PIC X(255) VALUE SPACES is global.
       01 g-pesqLinhaExcluida PIC X(255) VALUE SPACES is global.
       01 g-pesqMaxCod   PIC X(255) VALUE SPACES is global.
       01 g-LinhaReg     PIC X(255) VALUE SPACES is global.
       01 g-tamReg       PIC 9(3)   VALUE zeros  is global.
       01 g-rotulo       PIC X(255) VALUE SPACES is global.
       01 g-ContinuaSN   PIC 9      VALUE zero   is global.
       01 g-ListarTodos  PIC 9      VALUE zero   is global.
       01 g-validaEntrada PIC X(255) VALUE SPACES is global.
       01 g-frmLogin     PIC 9      VALUE zero   is global.

       01 g-nmax-codigo   PIC 9(7)  is global.
       01 g-npos-registro PIC 9(7)  VALUE ZEROS is global.
       01 g-tecla-return  PIC XX    VALUE X"3030" is global.

       01 teste         PIC X(255).
       01 teste2        PIC X(255).
       01 teste3        PIC X(255).
       01 nteste        PIC 9(7).
       01 nteste2       PIC 9(7).
       01 nteste3       PIC 9(7).
       01 nteste4       PIC 9(7).
       01 bteste        PIC 9.
       01 bteste2       PIC 9.
      *-------------------------------------------------------------
       SCREEN SECTION.
       01 frmSplash.
          05 BLANK SCREEN.
          05 LINE 1  COL 1  VALUE "*------------------------------".
          05 LINE 1  COL 32 VALUE "-------------------------------".
          05 LINE 1  COL 63 VALUE "---------------*".
          05 LINE 2  COL 1  VALUE "| LL    II VV   VV RRRRR  UU  U".
          05 LINE 2  COL 32 VALUE "U   SSSS VV   VV II RRRRR  TTTT".
          05 LINE 2  COL 63 VALUE " UU  UU   SSSS |".
          05 LINE 3  COL 1  VALUE "| LL    II  VV VV  RR   R UU  U".
          05 LINE 3  COL 32 VALUE "U  SS     VV VV  II RR   R  TT ".
          05 LINE 3  COL 63 VALUE " UU  UU  SS    |".
          05 LINE 4  COL 1  VALUE "| LL    II   VVV   RRRRR  UU  U".
          05 LINE 4  COL 32 VALUE "U    SS    VVV   II RRRRR   TT ".
          05 LINE 4  COL 63 VALUE " UU  UU    SS  |".
          05 LINE 5  COL 1  VALUE "| LLLLL II    V    RR   R  UUUU".
          05 LINE 5  COL 32 VALUE "  SSSS      V    II RR   R  TT ".
          05 LINE 5  COL 63 VALUE "  UUUU  SSSS   |".
          05 LINE 6  COL 1  VALUE "*------------------------------".
          05 LINE 6  COL 32 VALUE "-------------------------------".
          05 LINE 6  COL 63 VALUE "---------------*".
          05 LINE 7  COL 1  VALUE "pressione para continuar...".
      *-------------------------------------------------------------
       PROCEDURE DIVISION.

      *-------------------------------------------------------------
      * Parte inicial do código
      *-------------------------------------------------------------
       principal.
      *   if ParamStr(1)='-cria' then
      *       call "abrecriaArqs" using g-false
      *   else
           DISPLAY frmSplash
           ACCEPT g-tecla-return 
           call "abrecriaArqs" using g-true
           call "frmLogin"
           if g-frmLogin = g-true then
             move g-true to bopcao
             PERFORM UNTIL bopcao = g-false
               move 1 to nparam
               call "menu" using nparam
               ACCEPT opmenu
               evaluate true
                 when (opmenu="C") or (opmenu="c")
                   move 1 to nparam
                   call "usaMenu" using by content nparam
                 when  (opmenu="P") or (opmenu="p") 
                   move 2 to nparam
                   call "usaMenu" using by content nparam
                 when  (opmenu="V") or (opmenu="v") 
                   move 3 to nparam
                   call "usaMenu" using by content nparam
                 when  (opmenu="O") or (opmenu="o") 
                   move 4 to nparam
                   call "usaMenu" using by content nparam
                 when other 
                   DISPLAY MSG-ERRO
               end-evaluate
             END-PERFORM
           else
             call "fechaArqs"
             STOP RUN
           end-if

      *   end-if 
       STOP RUN.            
      *-------------------------------------------------------------
      * Calcula o tamanho do texto.
      * sTexto - o texto a ser calculado
      * retorna - o tamanho do texto
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. tamstr IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 conta-char PIC 9(3) VALUE ZEROS.
       LINKAGE SECTION.
         01 sTexto     PIC X(255).
       PROCEDURE DIVISION USING sTexto.
         PERFORM VARYING conta-char FROM TAM-MAX-STR BY -1
              UNTIL sTexto(conta-char:1) NOT = SPACE
         END-PERFORM       
         move conta-char to g-tamstr
       END PROGRAM tamstr.
      *-------------------------------------------------------------
      * Retira os espaços em branco antes ou depois do texto.
      * sTexto - o texto a ser retirado os espaços em branco
      * retorna - o texto sem os espaços em branco
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. trim IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 conta-char PIC 9(3) VALUE ZEROS.
       LINKAGE SECTION.
         01 sTexto     PIC X(255).
       PROCEDURE DIVISION USING sTexto.
         MOVE 1 TO conta-char.
         INSPECT sTexto TALLYING conta-char FOR LEADING SPACES
         move sTexto(conta-char: TAM-MAX-STR - conta-char) to g-trim
       END PROGRAM trim.
      *-------------------------------------------------------------
      * Repete um texto um número determinado de vezes.
      * sTexto - o texto a ser repetido
      * nQtd - a quantidade de vezes
      * retorna - o texto repetido
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. repete IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 npos 	 PIC 99 VALUE 1.
       LINKAGE SECTION.
         01 sTexto PIC X(255).
         01 nQtd   PIC 9(7).
       PROCEDURE DIVISION USING sTexto, nQtd.
         move 1 to npos
         move SPACES to g-repete
         PERFORM nQtd TIMES
           STRING sTexto DELIMITED BY SPACES 
             INTO g-repete WITH POINTER npos
           END-STRING
         END-PERFORM.
       END PROGRAM repete.
      *-------------------------------------------------------------
      * Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
      * sTexto - o texto
      * nTam - tamanho máximo do texto
      * retorna - o texto com espaços em branco a mais
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. esp.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 npos   PIC 99 VALUE 1.
         01 slocal PIC X(255) VALUE SPACE.
       LINKAGE SECTION.
         01 sTexto     PIC X(255).
         01 nTam       PIC 9(7).
       PROCEDURE DIVISION USING sTexto, nTam.
         call "tamstr" using by content sTexto
         move g-tamstr to npos
         add 1 to npos  
         SUBTRACT nTam from g-tamstr
      *   move SPACE to slocal
         call "repete" using by content slocal
                             by content g-tamstr
         STRING g-repete DELIMITED BY SIZE 
           INTO sTexto WITH POINTER npos
         END-STRING
         move sTexto to g-esp 
       END PROGRAM esp.
      *-------------------------------------------------------------
      * Faz uma pesquisa relativa de um texto através de um valor chave.
      * sTexto - o texto
      * sChave - a chave a ser pesquisada
      * retorna - se achou ou não a chave dentro do texto
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. strRelativa.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 nCont     PIC 9(3).
         01 ntotal    PIC 9(3).
         01 nTamChave PIC 9(7).
         01 nTamTexto PIC 9(7).
         01 bret      PIC 9.
         01 sPedaco   PIC X(255) VALUE SPACES.
       LINKAGE SECTION.
         01 sTexto    PIC X(255).
         01 sChave    PIC X(255).
       PROCEDURE DIVISION USING sTexto, sChave.
         set bret to g-false
         move 1 to nCont
         call "tamstr" using by content sChave
         move g-tamstr to nTamChave
         call "tamstr" using by content sTexto
         move g-tamstr to nTamTexto         
         if nTamChave <= nTamTexto then
           compute ntotal = nTamTexto - nTamChave + 2
           PERFORM UNTIL nCont >= ntotal
             move sTexto(nCont:nTamChave) to sPedaco 
             if sPedaco=sChave then
                set bret to g-true
             end-if
             add 1 to nCont
           END-PERFORM
         end-if
         move bret to g-strRelativa
       END PROGRAM strRelativa.
      *-------------------------------------------------------------
      * Calcula o modulo11 de um valor qualquer.
      * svalor - a mstring com o número a ser calculado
      * ndig - dígito do valor a ser calculado
      * bcond - condição de retorno de aninhamento
      * retorna - o dígito correto
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. modulo11 IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 ncont  PIC 9(7).
         01 nsoma  PIC 9(7).
         01 nvalor PIC 9(7).
         01 npos   PIC 9(7).
         01 nnum   PIC 9(7).
         01 nresto PIC 9(7).
         01 nres   PIC 9.
         01 slocal PIC X(255).
       LINKAGE SECTION.
         01 svalor  PIC X(255).
         01 ndig    PIC 9.
       PROCEDURE DIVISION USING svalor, ndig.
         move 11 to ncont
         move 1 to npos
         PERFORM 11 TIMES
           STRING svalor(ncont:1) DELIMITED BY SIZE 
             INTO slocal WITH POINTER npos
           END-STRING
           subtract 1 from ncont 
         END-PERFORM
         move 0 to nsoma
         if ndig=1 then
           move 3 to ncont
         else
           move 2 to ncont
         end-if 
         move 2 to npos
         PERFORM 11 TIMES
           move slocal(ncont:1) to nres 
           move nres to nvalor
           compute nsoma=nsoma + (nvalor * npos)
           add 1 to ncont
           add 1 to npos
         END-PERFORM
         DIVIDE nsoma by 11 GIVING nnum REMAINDER nresto
         compute nsoma = 11 - nresto       
         if nsoma > 9 then
           move 0 to g-modulo11
         else
           move nsoma to g-modulo11
         end-if
       END PROGRAM modulo11.
      *-------------------------------------------------------------
      * Validação de um número de CPF qualquer.
      * cpf - a mstring com o número do CPF
      * retorna - se é valido ou não
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. validaCPF IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 nvalor1  PIC 9(7).
         01 nvalor2  PIC 9(7).
         01 mod1     PIC 9(7).
         01 mod2     PIC 9(7).
         01 scpf     PIC X(255).
         01 nres     PIC 9.
       LINKAGE SECTION.
         01 cpf  PIC X(255).
       PROCEDURE DIVISION USING cpf.
         call "tamstr" using by content cpf
         if g-tamstr=14 then           
           STRING cpf(1:3) DELIMITED BY SIZE 
             cpf(5:3) DELIMITED BY SIZE 
             cpf(9:3) DELIMITED BY SIZE 
             cpf(13:2) DELIMITED BY SIZE 
             INTO scpf
           END-STRING
           move cpf(13:1) to nres 
           move nres to nvalor1
           move cpf(14:1) to nres 
           move nres to nvalor2
           move 1 to nres
           call "modulo11" using by content scpf, nres
           move g-modulo11 to mod1
           move 2 to nres
           call "modulo11" using by content scpf, nres
           move g-modulo11 to mod2
           if (mod1=nvalor1) and (mod2=nvalor2) then
             move g-true to g-validaCPF
           else
             move g-false to g-validaCPF
           end-if
         else
           move g-false to g-validaCPF
         end-if
       END PROGRAM validaCPF.
      *-------------------------------------------------------------
      * Validação de um número ISBN qualquer.
      * isbn - a mstring com o número do ISBN
      * retorna - se é valido ou não
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. validaISBN IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 nvalor   PIC 9(7).
         01 ncont    PIC 9(7).
         01 nsoma    PIC 9(7).
         01 npos     PIC 9(7).
         01 nresto   PIC 9(7).
         01 sisbn    PIC X(255).
         01 nnum     PIC 9.
         01 sdigito  PIC X.
       LINKAGE SECTION.
         01 isbn     PIC X(255).
       PROCEDURE DIVISION USING isbn.
         call "tamstr" using by content isbn
         if g-tamstr=13 then
           move isbn(g-tamstr:1) to sdigito
           move 1 to npos
           move 1 to ncont
           subtract 1 from g-tamstr
           PERFORM g-tamstr TIMES
             if isbn(ncont:1) not = "-" then
               STRING isbn(ncont:1) DELIMITED BY SIZE 
                 INTO sisbn WITH POINTER npos
               END-STRING                
             end-if
             add 1 to ncont
           END-PERFORM
           if sdigito = "X" then
             move 10 to nsoma
           else
             move sdigito to nnum
             move nnum to nsoma
           end-if
           move 1 to ncont
           PERFORM 9 TIMES
             move sisbn(ncont:1) to nnum
             move nnum to nvalor
             compute nsoma=nsoma + (nvalor * (11 - ncont))
             add 1 to ncont
           END-PERFORM
           DIVIDE nsoma by 11 GIVING ncont REMAINDER nresto
           If nresto = 0 Then
             move g-true to g-validaISBN
           else
             move g-false to g-validaISBN
           end-if
         else
           move g-false to g-validaISBN
         end-if
       END PROGRAM validaISBN.
      *-------------------------------------------------------------
      * Esconde a digitação da senha
      * retorna - a senha digitada
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. digitaSenha IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 sSenha   PIC X(255).
      *   01 sLetra   PIC X.
      *   01 ncont    PIC 9(7).
       LINKAGE SECTION.
         01 sRotulo   PIC X(255).
         01 nTamSenha PIC 9(7).
       PROCEDURE DIVISION USING sRotulo, nTamSenha.
         call "tamstr" using sRotulo
         add 1 to g-tamstr
         DISPLAY sRotulo(1:g-tamstr) WITH NO ADVANCING
         ACCEPT sSenha

      *   move 0 to ncont
      *   move SPACES sSenha
      *   move 0 sLetra
      *   PERFORM UNTIL (sLetra not = X"13") and (ncont < nTamSenha)
      *     ACCEPT sLetra
      *     STRING sSenha DELIMITED BY SIZE 
      *       sLetra DELIMITED BY SIZE 
      *       INTO sSenha
      *     END-STRING
      *     add 1 to ncont
      *   END-PERFORM  

         move sSenha to g-digitaSenha
       END PROGRAM digitaSenha.
      *-------------------------------------------------------------
      * Validação de um número qualquer.
      * sRotulo - o texto antes de se digitar o número
      * sNumero - a mstring com o valor do número
      * retorna - o sNumero
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. validaNumero IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 nStatus   PIC S9(7).
         01 nnum      PIC 9(7).
       LINKAGE SECTION.
         01 sRotulo   PIC X(255).
         01 sNumero   PIC X(7).
       PROCEDURE DIVISION USING sRotulo, sNumero.
         move -1 to nstatus
         PERFORM UNTIL nStatus=0
           call "tamstr" using sRotulo
           add 1 to g-tamstr
           DISPLAY sRotulo(1:g-tamstr) WITH NO ADVANCING
           ACCEPT sNumero
           move sNumero to nnum
           if nnum < 1 then
             DISPLAY MSG-NUMINV
           else
             move 0 to nStatus
           end-if
           move sNumero to g-validaNumero
         END-PERFORM  

       END PROGRAM validaNumero.
      *-------------------------------------------------------------
      * Validação de uma data ou data/hora qualquer.
      * sRotulo - o texto antes de se digitar a data/hora
      * sDataHora - a mstring com o valor da data/hora
      * bSoData - indica se vai validar somente uma data sem a hora
      * retorna - a sDataHora
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. validaDataHora IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bvalida     PIC 9.
         01 bdatavalida PIC 9.
         01 bhoravalida PIC 9.
         01 sdia        PIC XX.
         01 smes        PIC XX.
         01 sano        PIC X(4).
         01 shora       PIC XX.
         01 smin        PIC XX.
         01 sseg        PIC XX.
         01 ndia        PIC 99.
         01 nmes        PIC 99.
         01 nano        PIC 9(4).
         01 nhora       PIC 99.
         01 nmin        PIC 99.
         01 nseg        PIC 99.
         01 nudiames    PIC 99.
         01 ntam        PIC 9(7).
         01 nresto      PIC 9(7).
       LINKAGE SECTION.
         01 sRotulo   PIC X(255).
         01 sDataHora PIC X(19).
         01 bSoData   PIC 9.
       PROCEDURE DIVISION USING sRotulo, sDataHora, bSoData.
         move g-false to bvalida
         move g-false to bdatavalida
         move g-false to bhoravalida
         move 0 to nudiames
         if bSoData = g-true then 
           move 10 to ntam
         else 
           move 19 to ntam
         end-if
         PERFORM UNTIL bvalida not = g-false
           call "tamstr" using sRotulo
           add 1 to g-tamstr
           DISPLAY sRotulo(1:g-tamstr) WITH NO ADVANCING
           ACCEPT sDataHora
           call "tamstr" using sDataHora
           if g-tamstr = ntam then
              move sDataHora(1:2) to sdia 
              move sdia to ndia
              move sDataHora(4:2) to smes
              move smes to nmes
              move sDataHora(7:4) to sano
              move sano to nano
            
              if (nano >= 1) and (nano <= 9999) then
                if (nmes >= 1) and (nmes <= 31) then
                  EVALUATE TRUE
                    WHEN nmes=1 or nmes=3 or nmes=5 or nmes=7 or 
                         nmes=8 or nmes=10 or nmes=12
                      move 31 to nudiames
                    WHEN nmes=2
      *               ano bissexto
                      DIVIDE nano by 4 GIVING ntam REMAINDER nresto
                      if nresto=0 then 
                        move 29 to nudiames
                      else 
                        move 28 to nudiames
                      end-if
                    WHEN nmes=4 or nmes=6 or nmes=9 or nmes=11
                      move 30 to nudiames
                  END-EVALUATE
                  if (ndia >=1) and (ndia <=nudiames) then
                       move g-true to bdatavalida
                  end-if 
                end-if
              end-if
            
              if bSoData = g-true then
                 if bdatavalida=g-true then 
                   move g-true to bvalida
                 else 
                   DISPLAY MSG-DATAINV
                 end-if 
              else
                if bdatavalida = g-true then
                    move sDataHora(12:2) to shora
                    move shora to nhora
                    move sDataHora(15:2) to smin
                    move smin to nmin
                    move sDataHora(18:2) to sseg
                    move sseg to nseg
                    
                    if (nhora >= 0) and (nhora <= 23) then
                      if (nmin >= 0) and (nmin <= 59) then
                        if (nseg >= 0) and (nseg <= 59) then
                           move g-true to bhoravalida
                      end-if
                    end-if
            
                    if bhoravalida=g-true then 
                      move g-true to bvalida
                    else 
                      DISPLAY MSG-DTHRINV
                    end-if    
                else
                  DISPLAY MSG-DTHRINV
                end-if
              end-if
           else
             if bSoData=g-true then 
               DISPLAY MSG-DATAINV
             else 
               DISPLAY MSG-DTHRINV
             end-if
           end-if
         END-PERFORM
         move sDataHora to g-validaDataHora
       END PROGRAM validaDataHora.
      *-------------------------------------------------------------
      * Retorna a Data e a hora do sistema.
      * retorna - a data e a hora
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. retDataHora IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 sano PIC 9(4).
       01 data-corrente.
          05 ano        PIC 99.
          05 mes        PIC 99.
          05 dia        PIC 99.
       01 tempo-corrente.
          05 hora       PIC 99.
          05 min        PIC 99.
          05 seg        PIC 9(2).
       PROCEDURE DIVISION.
         ACCEPT data-corrente FROM DATE.   
         ACCEPT tempo-corrente FROM TIME.
      *   compute sano = ano + 2000.
         move 2000 to sano
         add ano to sano 
         STRING dia DELIMITED BY SIZE
                "/" DELIMITED BY SIZE
                mes DELIMITED BY SIZE
                "/" DELIMITED BY SIZE
                sano DELIMITED BY SIZE
                " " DELIMITED BY SIZE
                hora DELIMITED BY SIZE
                ":" DELIMITED BY SIZE
                min DELIMITED BY SIZE
                ":" DELIMITED BY SIZE
                seg DELIMITED BY SIZE
            INTO g-retdatahora
         END-STRING.
       END PROGRAM retDataHora.
      *-------------------------------------------------------------
      * Abre ou cria os arquivos do sistema.
      * bAbre - condição para abrir ou criar os arquivos do sistema
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. abrecriaArqs IS COMMON PROGRAM.
       DATA DIVISION.
       LINKAGE SECTION.
         01 bAbre   PIC 9.
       PROCEDURE DIVISION USING bAbre.
         if bAbre = g-true then
           OPEN I-O tfAssunto
           OPEN I-O tfAutor
           OPEN I-O tfEditora
           OPEN I-O tfIdioma
           OPEN I-O tfEndereco
           OPEN I-O tfPais
           OPEN I-O tfProfissao
           OPEN I-O tfLivro
           OPEN I-O tfLivroAss
           OPEN I-O tfLivroAut
           OPEN I-O tfCliente
           OPEN I-O tfUsuario
           OPEN I-O tfVenda
         else
           OPEN EXTEND tfAssunto
           OPEN EXTEND tfAutor
           OPEN EXTEND tfEditora
           OPEN EXTEND tfIdioma
           OPEN EXTEND tfEndereco
           OPEN EXTEND tfPais
           OPEN EXTEND tfProfissao
           OPEN EXTEND tfLivro
           OPEN EXTEND tfLivroAss
           OPEN EXTEND tfLivroAut
           OPEN EXTEND tfCliente
           OPEN EXTEND tfUsuario
           OPEN EXTEND tfVenda
         end-if  
       END PROGRAM abrecriaArqs.
      *-------------------------------------------------------------
      * Fecha todos os arquivos abertos.
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. fechaArqs IS COMMON PROGRAM.
       PROCEDURE DIVISION.
         CLOSE tfAssunto
         CLOSE tfAutor
         CLOSE tfEditora
         CLOSE tfIdioma
         CLOSE tfEndereco
         CLOSE tfPais
         CLOSE tfProfissao
         CLOSE tfLivro
         CLOSE tfLivroAss
         CLOSE tfLivroAut
         CLOSE tfCliente
         CLOSE tfUsuario
         CLOSE tfVenda
       END PROGRAM fechaArqs.
      *-------------------------------------------------------------
      * Pesquisa um registro através de um valor chave num arquivo.
      * sArq - o arquivo
      * sChave - a chave a ser pesquisada
      * nPosChave - a posicao inicial da chave dentro do registro
      * nTamChave - o tamanho da chave dentro do registro
      * nTamLinha - o tamanho do registro
      * retorna - o registro pesquisado
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. pesqArq IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bQuebra   PIC 9.
         01 nPosicao  PIC 9(7).
         01 nMaior    PIC 9(7).
       LINKAGE SECTION.
         01 sArq      PIC X(255).
         01 sChave    PIC X(255).
         01 nPosChave PIC 9(7).
         01 nTamChave PIC 9(7).
         01 nTamLinha PIC 9(7).
       PROCEDURE DIVISION USING sArq, sChave, nPosChave, 
                                nTamChave, nTamLinha.
         move g-false to bQuebra
         move 1 to nPosicao
         move 0 to nMaior
         move 0 to g-nmax-codigo
         if sArq="tfAssunto" then
           READ tfAssunto
              AT END MOVE HIGH-VALUES TO regAssunto
           END-READ
           PERFORM UNTIL regAssunto = HIGH-VALUES or bQuebra = g-true
             call "trim" using by content 
                regAssunto(nPosChave:nTamChave)
             if g-trim = sChave then
               move nPosicao to g-npos-registro
               move g-true to bQuebra
             else
               add 1 to nPosicao
               
               call "tamstr" using by content g-trim
               move g-trim(1:g-tamstr) to g-nmax-codigo              
               if g-nmax-codigo > nMaior then
                 move g-nmax-codigo to nMaior
               end-if

               READ tfAssunto
                  AT END MOVE HIGH-VALUES TO regAssunto
               END-READ 
             end-if
           END-PERFORM

           move nMaior to g-nmax-codigo
           add 1 to g-nmax-codigo

           move regAssunto(1:nTamLinha) to g-pesqArq
         end-if
       END PROGRAM pesqArq.
      *-------------------------------------------------------------
      * Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
      * sArq - o arquivo
      * nTamLinha - o tamanho do registro
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. pesqLinhaExcluida IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 sExcluido   PIC X(255).
         01 ntam-npos   PIC 9(7).
       LINKAGE SECTION.
         01 sArq      PIC X(255).
         01 nTamLinha PIC 9(7).
       PROCEDURE DIVISION USING sArq, nTamLinha.
         move "*" to sExcluido
         move 1 to ntam-npos
         call "pesqArq" using by content sArq
                              by content sExcluido
                              by content ntam-npos
                              by content ntam-npos
                              by content nTamLinha
         move g-pesqArq to g-pesqLinhaExcluida.
       END PROGRAM pesqLinhaExcluida.
      *-------------------------------------------------------------
      * Pesquisa o maior código num arquivo.
      * sArq - o arquivo
      * nPosChave - a posicao inicial da chave dentro do registro
      * nTamChave - o tamanho da chave dentro do registro
      * nTamLinha - o tamanho do registro
      * retorna - o maior código
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. pesqMaxCod IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 sSemChave   PIC X(255).
       LINKAGE SECTION.
         01 sArq      PIC X(255).
         01 nPosChave PIC 9(7).
         01 nTamChave PIC 9(7).
         01 nTamLinha PIC 9(7).
       PROCEDURE DIVISION USING sArq,nPosChave,nTamChave,nTamLinha.
         move "@" to sSemChave
         call "pesqArq" using by content sArq
                              by content sSemChave
                              by content nPosChave
                              by content nTamChave
                              by content nTamLinha
         move g-nmax-codigo to g-pesqMaxCod
       END PROGRAM pesqMaxCod.        
      *-------------------------------------------------------------
      * Grava os registros num determinado arquivo.
      * sArq - o arquivo
      * sTexto - o registro a ser gravado
      * sMsgAcerto - a mensagem caso o registro foi gravado
      * sMsgErro - a mensagem caso o registro não foi gravado
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. escreveArq IS COMMON PROGRAM.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
         SELECT tfTemp ASSIGN TO "temp.dat"
                ORGANIZATION IS LINE SEQUENTIAL
                ACCESS MODE IS SEQUENTIAL.
       DATA DIVISION.
       FILE SECTION.
         FD tfTemp.
         01 regTempAssunto PIC X(40) is global. 
       WORKING-STORAGE SECTION.
         01 sSemChave   PIC X(255).
         01 nPosicao    PIC 9(7).
       LINKAGE SECTION.
         01 sArq       PIC X(255).
         01 sTexto     PIC X(255).
         01 sMsgAcerto PIC X(255).
         01 sMsgErro   PIC X(255).
       PROCEDURE DIVISION USING sArq, sTexto, sMsgAcerto, sMsgErro.
         move 1 to nPosicao
         OPEN OUTPUT tfTemp
         READ tfAssunto
            AT END MOVE HIGH-VALUES TO regAssunto
         END-READ
         PERFORM UNTIL regAssunto = HIGH-VALUES
             if g-npos-registro = nPosicao then
               WRITE regTempAssunto FROM sTexto
             else
               WRITE regTempAssunto FROM regAssunto
             end-if
             add 1 to nPosicao
             READ tfAssunto
                AT END MOVE HIGH-VALUES TO regAssunto
             END-READ 
         END-PERFORM

         close tfTemp
         close tfAssunto

         OPEN INPUT tfTemp
         OPEN OUTPUT tfAssunto
         READ tfTemp
            AT END MOVE HIGH-VALUES TO regTempAssunto
         END-READ
         PERFORM UNTIL regTempAssunto = HIGH-VALUES
             WRITE regAssunto FROM regTempAssunto
             READ tfTemp
                AT END MOVE HIGH-VALUES TO regTempAssunto
             END-READ 
         END-PERFORM
         DISPLAY sMsgAcerto
       END PROGRAM escreveArq.
      *-------------------------------------------------------------
      * Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
      * sreg - o tipo de arquivo
      * retorna - o registro montado
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. LinhaReg IS COMMON PROGRAM.
       DATA DIVISION.
       LINKAGE SECTION.
         01 sreg     PIC 99.
       PROCEDURE DIVISION USING sreg.
         EVALUATE TRUE	
           WHEN sreg = opAssunto   move regAssunto   to g-LinhaReg
           WHEN sreg = opAutor     move regAutor     to g-LinhaReg
           WHEN sreg = opEditora   move regEditora   to g-LinhaReg
           WHEN sreg = opEndereco  move regEndereco  to g-LinhaReg
           WHEN sreg = opIdioma    move regIdioma    to g-LinhaReg
           WHEN sreg = opPais      move regPais      to g-LinhaReg
           WHEN sreg = opProfissao move regProfissao to g-LinhaReg
           WHEN sreg = opLivro     move regLivro     to g-LinhaReg
           WHEN sreg = opLivroAss  move regLivroAss  to g-LinhaReg
           WHEN sreg = opLivroAut  move regLivroAut  to g-LinhaReg
           WHEN sreg = opCliente   move regCliente   to g-LinhaReg
           WHEN sreg = opVenda     move regVenda     to g-LinhaReg
         END-EVALUATE
       END PROGRAM LinhaReg.
      *-------------------------------------------------------------
      * Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
      * sreg - o tipo de arquivo
      * retorna - o tamanho do registro
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. tamReg IS COMMON PROGRAM.
       DATA DIVISION.
       LINKAGE SECTION.
         01 sreg     PIC 99.
       PROCEDURE DIVISION USING sreg.
         EVALUATE TRUE	
           WHEN sreg = opAssunto   move TAM-ASSUNTO   to g-tamReg
           WHEN sreg = opAutor     move TAM-AUTOR     to g-tamReg
           WHEN sreg = opEditora   move TAM-EDITORA   to g-tamReg
           WHEN sreg = opEndereco  move TAM-ENDERECO  to g-tamReg
           WHEN sreg = opIdioma    move TAM-IDIOMA    to g-tamReg
           WHEN sreg = opPais      move TAM-PAIS      to g-tamReg
           WHEN sreg = opProfissao move TAM-PROFISSAO to g-tamReg
           WHEN sreg = opUsuario   move TAM-USUARIO   to g-tamReg
           WHEN sreg = opLivro     move TAM-LIVRO     to g-tamReg
           WHEN sreg = opLivroAss  move TAM-LIVASS    to g-tamReg
           WHEN sreg = opLivroAut  move TAM-LIVAUT    to g-tamReg
           WHEN sreg = opCliente   move TAM-CLIENTE   to g-tamReg
           WHEN sreg = opVenda     move TAM-VENDA     to g-tamReg
         END-EVALUATE
       END PROGRAM tamReg.
      *-------------------------------------------------------------
      * Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
      * sreg - o tipo de arquivo
      * nNum - indica qual rotulo será retornado
      * retorna - o rotulo
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. rotulo IS COMMON PROGRAM.
       DATA DIVISION.
       LINKAGE SECTION.
         01 sreg     PIC 99.
         01 nNum     PIC 99.
       PROCEDURE DIVISION USING sreg, nNum.
         if sreg = opAssunto then
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Assunto(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "Código do assunto: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Assunto: " to g-rotulo
               move 11 to g-nPosChave
               move 30 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opAutor then
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Autor(es) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "Código do autor: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Autor: " to g-rotulo
               move 11 to g-nPosChave
               move 30 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opEditora then   
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Editora(s) não encontrada(s)!" to g-rotulo
             WHEN nNum=1
               move "Código da editora: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Editora: " to g-rotulo
               move 11 to g-nPosChave
               move 50 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opEndereco then 
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Endereço(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "Código do endereço: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Logradouro: " to g-rotulo
               move 11 to g-nPosChave
               move 40 to g-nTamChave
             WHEN nNum=3
               move "Bairro: " to g-rotulo
               move 51 to g-nPosChave
               move 15 to g-nTamChave
             WHEN nNum=4
               move "CEP: " to g-rotulo
               move 66 to g-nPosChave
               move 8 to g-nTamChave
             WHEN nNum=5
               move "Cidade: " to g-rotulo
               move 74 to g-nPosChave
               move 30 to g-nTamChave
             WHEN nNum=6
               move "Estado: " to g-rotulo
               move 104 to g-nPosChave
               move 20 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opIdioma then   
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Idioma(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "Código do idioma: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Idioma: " to g-rotulo
               move 11 to g-nPosChave
               move 20 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opPais then     
           EVALUATE TRUE	
             WHEN nNum=0 
               move "País(es) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "Código do país: '" to g-rotulo
               move 1 to g-nPosChave
               move 3 to g-nTamChave
             WHEN nNum=2
               move "País: " to g-rotulo
               move 4 to g-nPosChave
               move 50 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opProfissao then 
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Profissão(es) não encontrada(s)!" to g-rotulo
             WHEN nNum=1
               move "Código da profissão: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Profissão: " to g-rotulo
               move 11 to g-nPosChave
               move 50 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opUsuario then    
           EVALUATE TRUE	
             WHEN nNum=0 
               move "login ou senha incorreta, tente de novo!" 
                 to g-rotulo
             WHEN nNum=1
               move "Login: '" to g-rotulo
               move 1 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=2
               move "Senha: " to g-rotulo
               move 11 to g-nPosChave
               move 10 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opLivro then    
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Livro(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "ISBN: '" to g-rotulo
               move 1 to g-nPosChave
               move 13 to g-nTamChave
             WHEN nNum=2
               move "Título: " to g-rotulo
               move 14 to g-nPosChave
               move 50 to g-nTamChave
             WHEN nNum=3
               move "Edição: " to g-rotulo
               move 64 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=4
               move "Ano de Publicação: " to g-rotulo
               move 74 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=5
               move "Código da editora: " to g-rotulo
               move 84 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=6
               move "Volume: " to g-rotulo
               move 94 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=7
               move "Código do idioma: " to g-rotulo
               move 104 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=8
               move "Número de páginas: " to g-rotulo
               move 114 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=9
               move "Preço: " to g-rotulo
               move 124 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=10
               move "Qtd. Estoque: " to g-rotulo
               move 134 to g-nPosChave
               move 10 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opLivroAss then 
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Assunto(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "ISBN: '" to g-rotulo
               move 1 to g-nPosChave
               move 13 to g-nTamChave
             WHEN nNum=2
               move "Código do assunto: " to g-rotulo
               move 14 to g-nPosChave
               move 10 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opLivroAut then 
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Autor(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "ISBN: '" to g-rotulo
               move 1 to g-nPosChave
               move 13 to g-nTamChave
             WHEN nNum=2
               move "Código do autor: " to g-rotulo
               move 14 to g-nPosChave
               move 10 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opCliente then  
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Cliente(s) não encontrado(s)!" to g-rotulo
             WHEN nNum=1
               move "CPF: '" to g-rotulo
               move 1 to g-nPosChave
               move 14 to g-nTamChave
             WHEN nNum=2
               move "Nome: " to g-rotulo
               move 15 to g-nPosChave
               move 30 to g-nTamChave
             WHEN nNum=3
               move "E-mail: " to g-rotulo
               move 45 to g-nPosChave
               move 30 to g-nTamChave
             WHEN nNum=4
               move "Identidade: " to g-rotulo
               move 75 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=5
               move "Sexo: " to g-rotulo
               move 85 to g-nPosChave
               move 1 to g-nTamChave
             WHEN nNum=6
               move "Telefone: " to g-rotulo
               move 86 to g-nPosChave
               move 17 to g-nTamChave
             WHEN nNum=7
               move "Dt. Nascimento: " to g-rotulo
               move 103 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=8
               move "Código do endereço: " to g-rotulo
               move 113 to g-nPosChave
               move 10 to g-nTamChave
             WHEN nNum=9
               move "Código do país: " to g-rotulo
               move 123 to g-nPosChave
               move 3 to g-nTamChave
             WHEN nNum=10
               move "Código da Profissão: " to g-rotulo
               move 126 to g-nPosChave
               move 10 to g-nTamChave
           END-EVALUATE
         end-if
         if sreg = opVenda then    
           EVALUATE TRUE	
             WHEN nNum=0 
               move "Venda(s) não encontrada(s)!" to g-rotulo
             WHEN nNum=1
               move "Data/Hora venda: '" to g-rotulo
               move 1 to g-nPosChave
               move 19 to g-nTamChave
             WHEN nNum=2
               move "CPF: " to g-rotulo
               move 20 to g-nPosChave
               move 14 to g-nTamChave
             WHEN nNum=3
               move "ISBN: " to g-rotulo
               move 34 to g-nPosChave
               move 13 to g-nTamChave
             WHEN nNum=4
               move "Preço de venda: " to g-rotulo
               move 47 to g-nPosChave
               move 10 to g-nTamChave
           END-EVALUATE
         end-if
       END PROGRAM rotulo.
      *-------------------------------------------------------------
      * Indica se continua ou não mostrando um número máximo de linhas.
      * nlinha - a linha a ser continuada
      * nQtdLinha - a quantidade de linhas a serem mostradas
      * retorna - se continua ou não
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. ContinuaSN IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bSOp       PIC 9.
         01 opCSubMenu PIC X(255).
         01 ntemp      PIC 9(7).
         01 nresto     PIC 9(7).
       LINKAGE SECTION.
         01 nlinha     PIC 9(7).
         01 nQtdLinha  PIC 9(7).
       PROCEDURE DIVISION USING nlinha, nQtdLinha.
         move g-false to g-ContinuaSN
         if nlinha > 0 then
           DIVIDE nlinha by nQtdLinha GIVING ntemp REMAINDER nresto
           if nresto = 0 then
             move g-true to bSOp
             PERFORM UNTIL bSOp = g-false    
               move 13 to ntemp   
               call "menu" using by content ntemp
               ACCEPT opCSubMenu
               EVALUATE TRUE	
                 WHEN (opCSubMenu="S") or (opCSubMenu="s") 
                   move g-false to bSOp
                 WHEN (opCSubMenu="N") or (opCSubMenu="n")
                   move g-true to g-ContinuaSN
                   move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           end-if
         end-if
       END PROGRAM ContinuaSN.
      *-------------------------------------------------------------
      * Lista vários registros de acordo com a pesquisa feita.
      * sArq - o arquivo
      * sreg - o tipo de arquivo
      * sChave - a chave a ser pesquisada
      * nPosChave - a posicao inicial da chave dentro do registro
      * nTamChave - o tamanho da chave dentro do registro
      * nTamLinha - o tamanho do registro
      * nQtdLinha - a quantidade de linhas a serem mostradas
      * retorna - se encontrou algum registro
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. ListarTodos IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bRet      PIC 9. 
         01 bQuebra   PIC 9.
         01 bAchou    PIC 9.
         01 bProximo  PIC 9.
         01 nCont     PIC 9(7).
         01 nparam    PIC 9(7).
         01 sparam    PIC X(255).
         01 nPosicao  PIC 9(7).
       LINKAGE SECTION.
         01 sArq      PIC X(255).
         01 sreg      PIC 99.
         01 sChave    PIC X(255).
         01 nPosChave PIC 9(7).
         01 nTamChave PIC 9(7).
         01 nTamLinha PIC 9(7).
         01 nQtdLinha PIC 9(7).
         01 bPesqRelativa PIC 9.
       PROCEDURE DIVISION USING sArq, sreg, sChave, nPosChave, 
               nTamChave, nTamLinha, nQtdLinha, bPesqRelativa.
         move g-false to bRet
         move g-false to bQuebra
         move 0 to nCont
         move "@" to sparam
         move 2 to nparam
         call "mostrarDados" using by content sreg
                                   by content sparam
                                   by content nparam 
         if sArq="tfAssunto" then
           READ tfAssunto
              AT END MOVE HIGH-VALUES TO regAssunto
           END-READ
           PERFORM UNTIL regAssunto = HIGH-VALUES or bQuebra = g-true

             if bPesqRelativa=g-true then
                call "trim" using by content 
                   regAssunto(nPosChave:nTamChave)
                call "strRelativa" using by content g-trim
                                         by content sChave
                if g-strRelativa=g-true then
                   move nPosicao to g-npos-registro
                   move g-true to bAchou
                   move g-true to bRet
                   move g-false to bProximo
                else
                   move g-false to bAchou
                   move g-true to bProximo
                end-if
             else
               move g-true to bAchou
               move g-true to bRet
               move g-true to bProximo
             end-if

             if bAchou=g-true then
               move 3 to nparam
               call "mostrarDados" using by content sreg
                                 by content regAssunto(1:nTamLinha)
                                 by content nparam
               add 1 to nCont
             end-if

             if bProximo=g-true then
               add 1 to nPosicao             
               READ tfAssunto
                  AT END MOVE HIGH-VALUES TO regAssunto
               END-READ 
             end-if
             
             call "ContinuaSN" using by content nCont 
                                     by content nQtdLinha
             move g-ContinuaSN to bQuebra
           END-PERFORM
           move bRet to g-ListarTodos
         end-if
       END PROGRAM ListarTodos.
      *-------------------------------------------------------------
      * Lista vários registros entre arquivos de acordo com a pesquisa feita.
      * sArq1 - o arquivo de ligação
      * sreg1 - o tipo de arquivo de ligação
      * nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
      * nTamChave1 - o tamanho da primeira chave no arquivo de ligação
      * nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
      * nTamChave2 - o tamanho da segunda chave do arquivo de ligação
      * sChave - a chave a ser pesquisada no arquivo de ligação
      * sArq2 - o arquivo a ser pesquisado
      * sreg2 - o tipo de arquivo a ser pesquisado
      * nPosChave3 - a posicao inicial da chave do arquivo pesquisado
      * nQtdLinha - a quantidade de linhas a serem mostradas
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. ListarRegLigados IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bRet      PIC 9. 
         01 bQuebra   PIC 9.
         01 nCont     PIC 9(7).
         01 nparam    PIC 9(7).
         01 nPosicao  PIC 9(7).
         01 sparam    PIC X(255).
         01 sCodigo1  PIC X(255).
         01 sCodigo2  PIC X(255).
       LINKAGE SECTION.
         01 sArq1      PIC X(255).
         01 sreg1      PIC 99.
         01 nPosChave1 PIC 9(7).
         01 nTamChave1 PIC 9(7).
         01 nPosChave2 PIC 9(7).
         01 nTamChave2 PIC 9(7).
         01 sChave     PIC X(255).
         01 sArq2      PIC X(255).
         01 sreg2      PIC 99.
         01 nPosChave3 PIC 9(7).
         01 nQtdLinha  PIC 9(7).
       PROCEDURE DIVISION USING sArq1,sreg1,nPosChave1,nTamChave1, 
                                nPosChave2, nTamChave2, sChave, 
                                sArq2, sreg2, nPosChave3, nQtdLinha.
         move g-false to bRet
         move 0 to nCont
         move g-false to bQuebra
         move 1 to nPosicao
         move "@" to sparam
         move 2 to nparam
         call "mostrarDados" using by content sreg2
                                   by content sparam
                                   by content nparam 
         if sArq1="tfAssunto" then
           READ tfAssunto
              AT END MOVE HIGH-VALUES TO regAssunto
           END-READ
           PERFORM UNTIL regAssunto = HIGH-VALUES or bQuebra = g-true

      *      sCodigo1:=trim(copy(slinha1,nPosChave1,nTamChave1));
             call "trim" using by content 
                regAssunto(nPosChave1:nTamChave1)

             if g-trim = sChave then
               move nPosicao to g-npos-registro
               move g-true to bQuebra

      *        sCodigo2:=trim(copy(slinha1,nPosChave2,nTamChave2));
               call "tamReg" using by content sreg2
               call "pesqArq" using by content sArq2
                                    by content sCodigo2
                                    by content nPosChave3
                                    by content nTamChave2
                                    by content g-tamReg
      *        mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
               move 3 to nparam
               call "tamReg" using by content sreg2
               call "mostrarDados" using by content sreg2
                                 by content regAssunto(1:g-tamReg)
                                 by content nparam
               move g-true to bRet
               add 1 to nCont
             else
               add 1 to nPosicao             
               READ tfAssunto
                  AT END MOVE HIGH-VALUES TO regAssunto
               END-READ 
             end-if
             call "ContinuaSN" using by content nCont 
                                     by content nQtdLinha
             move g-ContinuaSN to bQuebra
           END-PERFORM          
           if bRet=g-false then
      *        DISPLAY rotulo(sreg2,0)
              move 0 to nparam 
              call "rotulo" using by content regAssunto
                                  by content nparam
              DISPLAY g-rotulo
           end-if
         end-if
       END PROGRAM ListarRegLigados.
      *-------------------------------------------------------------
      * Valida a entrada de registros de acordo com a pesquisa feita.
      * sArq - o arquivo
      * sreg - o tipo de arquivo
      * nTexto - o numero do rótulo da entrada
      * sEntrada - a chave a ser pesquisada e validada
      * nTentativas - o número máximo de tentativas
      * bPesqRelativa - indica se vai realizar uma pesquisa relativa
      * bTipoEntrada - indica o tipo de entrada
      * retorna - o registro pesquisado e validado
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. validaEntrada IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bQuebra   PIC 9.
         01 sres      PIC X(255).
         01 sTexto    PIC X(255).
         01 sMsgErro  PIC X(255).
         01 ncont     PIC 9(7).
         01 nparam    PIC 9(7).
         01 nPosChave PIC 9(7).
         01 nTamChave PIC 9(7).
         01 nTamLinha PIC 9(7).
       LINKAGE SECTION.
         01 sArq          PIC X(255).
         01 sreg          PIC 99.
         01 nTexto        PIC 9(7).
         01 sEntrada      PIC X(255).
         01 nTentativas   PIC 9(7).
         01 bPesqRelativa PIC 9.
         01 bTipoEntrada  PIC 9.
       PROCEDURE DIVISION USING sArq, sreg, nTexto, sEntrada, 
                     nTentativas, bPesqRelativa, bTipoEntrada.
         call "tamReg" using by content sreg
         move g-tamReg to nTamLinha
         move 0 to nparam
         call "rotulo" using by content sreg
                             by content nparam
         move g-rotulo to sMsgErro
         call "rotulo" using by content sreg
                             by content nTexto
         move g-rotulo to sTexto
         move g-nPosChave to nPosChave
         move g-nTamChave to nTamChave
        
         move 1 to ncont
         move g-false to bQuebra
         PERFORM UNTIL (bQuebra = g-true) and (ncont > nTentativas)
           EVALUATE TRUE
             WHEN bTipoEntrada=opTexto
               DISPLAY sTexto WITH NO ADVANCING
               ACCEPT sEntrada
             WHEN bTipoEntrada=opNumero
               call "validaNumero" using by content sTexto 
                                         by content sEntrada
               move g-validaNumero to sEntrada
             WHEN bTipoEntrada=opData
               call "validaDataHora" using by content sTexto 
                                           by content sEntrada
                                           by content g-true
               move g-validaDataHora to sEntrada
             WHEN bTipoEntrada=opDataHora
               call "validaDataHora" using by content sTexto 
                                           by content sEntrada
                                           by content g-false
               move g-validaDataHora to sEntrada
             WHEN bTipoEntrada=opSenha
               move 10 to nparam
               call "digitaSenha" using by content sTexto
                                        by content nparam
               move g-digitaSenha to sEntrada
           END-EVALUATE

           if bPesqRelativa=g-true then
              call "ListarTodos" using by content sArq
                                       by content sreg
                                       by content sEntrada
                                       by content nPosChave
                                       by content nTamChave
                                       by content nTamLinha
                                       by content QTD-MAX-LINHA
                                       by content g-true
              if g-ListarTodos = g-true then
                 move "@" to sres
              end-if
           else
               call "pesqArq" using by content sArq
                                    by content sEntrada
                                    by content nPosChave
                                    by content nTamChave
                                    by content nTamLinha
               move g-pesqArq to sres
           end-if
           if sres="@" then
             DISPLAY sMsgErro
           else
             move g-true to bQuebra
           end-if 
           add 1 to ncont
         END-PERFORM  
         move sres to g-validaEntrada        
       END PROGRAM validaEntrada.
      *-------------------------------------------------------------
      * Mostra a tela de login do sistema.
      * retorna - se o login foi validado corretamente
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. frmLogin IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 slinha    PIC X(255).
         01 sparam    PIC X(255).
         01 nparam1   PIC 9(7).
         01 nparam2   PIC 9(7).
       PROCEDURE DIVISION.
         move g-false to g-frmLogin
         DISPLAY "*------------------------------------------------"
         "--------------*"
         DISPLAY "| Login do sistema                               "
         "              |"
         DISPLAY "*------------------------------------------------"
         "--------------*"
         move "tfUsuario" to sparam
         move 1 to nparam1
         move 3 to nparam2
         call "validaEntrada" using by content sparam
                                    by content opUsuario 
                                    by content nparam1
                                    by content tUsuario-login
                                    by content nparam2
                                    by content g-false
                                    by content opTexto
         move g-validaEntrada to slinha
         if slinha not = "@" then
            move 2 to nparam1
            call "validaEntrada" using by content sparam
                                    by content opUsuario 
                                    by content nparam1
                                    by content tUsuario-senha
                                    by content nparam2
                                    by content g-false
                                    by content opSenha
            move g-validaEntrada to slinha
            if slinha not = "@" then
               call "trim" using by content slinha(1:10)
               move g-trim to tUsuario-login
               call "trim" using by content slinha(11:10)
               move g-trim to tUsuario-senha
               move g-true to g-frmLogin
            end-if
         end-if
         DISPLAY " "
       END PROGRAM frmLogin.
      *-------------------------------------------------------------
      * Mostra os menus do sistema.
      * num - o número do menu
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. menu IS COMMON PROGRAM.
       DATA DIVISION.
       LINKAGE SECTION.
         01 num  PIC 9(7).
       PROCEDURE DIVISION USING num.
         EVALUATE TRUE
           WHEN num=1
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| (C)adastros        (P)esquisas     (V)endas"
                     "        (O)pções  |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=2
             DISPLAY "*---------------------------------*"
             DISPLAY "| 01. Cadastro de Assuntos        |"
             DISPLAY "| 02. Cadastro de Autores         |"
             DISPLAY "| 03. Cadastro de Editoras        |"
             DISPLAY "| 04. Cadastro de Endereços       |"
             DISPLAY "| 05. Cadastro de Idiomas         |"
             DISPLAY "| 06. Cadastro de Países          |"
             DISPLAY "| 07. Cadastro de Profissões      |"
             DISPLAY "| 08. Cadastro de Clientes        |"
             DISPLAY "| 09. Cadastro de Livros          |"
             DISPLAY "| 10. Voltar ao menu              |"
             DISPLAY "*---------------------------------*"
           WHEN num=3
             DISPLAY "*---------------------------------*"
             DISPLAY "| 01. Consulta de Assuntos        |"
             DISPLAY "| 02. Consulta de Autores         |"
             DISPLAY "| 03. Consulta de Editoras        |"
             DISPLAY "| 04. Consulta de Endereços       |"
             DISPLAY "| 05. Consulta de Idiomas         |"
             DISPLAY "| 06. Consulta de Países          |"
             DISPLAY "| 07. Consulta de Profissões      |"
             DISPLAY "| 08. Consulta de Clientes        |"
             DISPLAY "| 09. Consulta de Livros          |"
             DISPLAY "| 10. Voltar ao menu              |"
             DISPLAY "*---------------------------------*"
           WHEN num=4
             DISPLAY "*---------------------------------*"
             DISPLAY "| 01. Vender Livros               |"
             DISPLAY "| 02. Vendas Realizadas           |"
             DISPLAY "| 03. Voltar ao menu              |"
             DISPLAY "*---------------------------------*"
           WHEN num=5
             DISPLAY "*---------------------------------*"
             DISPLAY "| 01. Alterar senha               |"
             DISPLAY "| 02. Sobre o sistema             |"
             DISPLAY "| 03. Sair do sistema             |"
             DISPLAY "| 04. Voltar ao menu              |"
             DISPLAY "*---------------------------------*"
           WHEN num=6
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| (1) Novo  (2) Pesquisar   (3) Voltar ao men"
                     "u                 |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=7
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| (1) Salvar inclusão       (2) Voltar ao men"
                     "u                 |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=8
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| (1) Alterar       (2) Excluir     (3) Volta"
                     "r ao menu         |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=9
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| (1) Salvar alteração      (2) Voltar ao men"
                     "u                 |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=10
             DISPLAY "*--------------------------------------------"  
                     "------------------*"
             DISPLAY "| Certeza de excluir? (S/N)                  "
                     "                  |"
             DISPLAY "*--------------------------------------------" 
                     "------------------*"
           WHEN num=11
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| Deseja sair do sistema? (S/N)              "
                     "                  |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=12
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| (1) Pesquisar  (2) Listar todos   (3) Volta"
                     "r ao menu         |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=13
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| Deseja continuar? (S/N)                    "
                     "                  |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
           WHEN num=14
             DISPLAY "*--------------------------------------------"
                     "------------------*"
             DISPLAY "| Salvar inclusão (S/N)                      "
                     "                  |"
             DISPLAY "*--------------------------------------------"
                     "------------------*"
         END-EVALUATE
         DISPLAY MSG-OPCAO WITH NO ADVANCING      
       END PROGRAM menu.
      *-------------------------------------------------------------
      * Realiza os cadastros de acordo com o tipo de arquivo.
      * sreg - o tipo de arquivo
      * sacao - a ação a ser realizada
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. frmCadastros IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 slinha    PIC X(255).
         01 sparam    PIC X(255).
         01 nparam1   PIC 9(7).
         01 nparam2   PIC 9(7).
       LINKAGE SECTION.
         01 sreg  PIC 99.
         01 sacao PIC 9.
       PROCEDURE DIVISION USING sreg, sacao.
         EVALUATE TRUE
           WHEN sreg = opAssunto
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "tamReg" using by content sreg
                 move "tfAssunto" to sparam
                 move 1 to nparam1
                 move 10 to nparam2
                 call "pesqMaxCod" using sparam, nparam1, 
                                         nparam2, g-tamReg
                 move g-pesqMaxCod to tAssunto-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 7 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opPesquisar
                 move "tfAssunto" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tAssunto-codigo,nparam1,g-false,opNumero
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opAutor     
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "tamReg" using by content sreg
                 move "tfAutor" to sparam
                 move 1 to nparam1
                 move 10 to nparam2
                 call "pesqMaxCod" using sparam, nparam1, 
                                         nparam2, g-tamReg
                 move g-pesqMaxCod to tAutor-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 7 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opPesquisar
                 move "tfAutor" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tAutor-codigo,nparam1,g-false,opNumero
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opEditora   
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "tamReg" using by content sreg
                 move "tfEditora" to sparam
                 move 1 to nparam1
                 move 10 to nparam2
                 call "pesqMaxCod" using sparam, nparam1, 
                                         nparam2, g-tamReg
                 move g-pesqMaxCod to tEditora-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 7 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opPesquisar
                 move "tfEditora" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tEditora-codigo,nparam1,g-false,opNumero
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opEndereco  
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "tamReg" using by content sreg
                 move "tfEndereco" to sparam
                 move 1 to nparam1
                 move 10 to nparam2
                 call "pesqMaxCod" using sparam, nparam1, 
                                         nparam2, g-tamReg
                 move g-pesqMaxCod to tEndereco-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 7 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opPesquisar
                 move "tfEndereco" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tEndereco-codigo,nparam1,g-false,opNumero
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opIdioma    
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "tamReg" using by content sreg
                 move "tfIdioma" to sparam
                 move 1 to nparam1
                 move 10 to nparam2
                 call "pesqMaxCod" using sparam, nparam1, 
                                         nparam2, g-tamReg
                 move g-pesqMaxCod to tIdioma-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 7 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opPesquisar
                 move "tfIdioma" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tIdioma-codigo,nparam1,g-false,opNumero
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opPais      
             EVALUATE TRUE
               WHEN sacao = opNovo
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tPais-codigo
                 call "tamReg" using by content sreg
                 move "tfPais" to sparam
                 move 1 to nparam1
                 move 3 to nparam2
                 call "pesqArq" using sparam, tPais-codigo, 
                                nparam1, nparam2, g-tamReg
                 move g-pesqArq to slinha
                 if slinha = "@" then
                   move "tfPais" to sparam
                   call "tamReg" using by content sreg
                   call "pesqLinhaExcluida" using sparam, g-tamReg
                   move "@" to sparam
                   move 1 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 7 to nparam1
                   call "subMenu" using nparam1, sreg
                 else 
                   DISPLAY MSG-REGEXST
                 end-if
               WHEN sacao = opPesquisar
                 move "tfPais" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tPais-codigo,nparam1,g-false,opTexto
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo tPais-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opProfissao 
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "tamReg" using by content sreg
                 move "tfProfissao" to sparam
                 move 1 to nparam1
                 move 10 to nparam2
                 call "pesqMaxCod" using sparam, nparam1, 
                                         nparam2, g-tamReg
                 move g-pesqMaxCod to tProfissao-codigo
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 7 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opPesquisar
                 move "tfProfissao" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tProfissao-codigo,nparam1,g-false,opNumero
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE
           WHEN sreg = opLivro   
             EVALUATE TRUE
               WHEN sacao = opNovo
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tLivro-isbn
                 call "validaISBN" using by content tLivro-isbn
                 if g-validaISBN = g-true then
                   call "tamReg" using by content sreg
                   move "tfLivro" to sparam
                   move 1 to nparam1
                   move 13 to nparam2
                   call "pesqArq" using sparam, tLivro-isbn, 
                                  nparam1, nparam2, g-tamReg
                   move g-pesqArq to slinha
                   if slinha = "@" then
                     move "tfLivro" to sparam
                     call "tamReg" using by content sreg
                     call "pesqLinhaExcluida" using sparam, g-tamReg
                     move "@" to sparam
                     move 1 to nparam1
                     call "mostrarDados" using sreg, sparam, nparam1
                     move 7 to nparam1
                     call "subMenu" using nparam1, sreg
                     call "frmCadLigados" using opLivroAss, 
                                          opNovo, tLivro-isbn
                     call "frmCadLigados" using opLivroAut, 
                                          opNovo, tLivro-isbn
                   else 
                     DISPLAY MSG-REGEXST
                   end-if
                 else 
                   DISPLAY MSG-ISBNINV
                 end-if
               WHEN sacao = opPesquisar
                 move "tfLivro" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tLivro-isbn,nparam1,g-false,opTexto
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo tLivro-isbn
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
                 call "frmCadLigados" using opLivroAss, 
                                      opExcluir, tLivro-isbn
                 DISPLAY "Assuntos dos livros excluídos, inclua novos!"
                 call "frmCadLigados" using opLivroAss, 
                                      opNovo, tLivro-isbn
                 call "frmCadLigados" using opLivroAut, 
                                      opExcluir, tLivro-isbn
                 DISPLAY "Autores dos livros excluídos, inclua novos!"
                 call "frmCadLigados" using opLivroAut, 
                                      opNovo, tLivro-isbn
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
                 DISPLAY "Assuntos dos livros sendo excluídos!"
                 call "frmCadLigados" using opLivroAss, 
                                      opExcluir, tLivro-isbn
                 DISPLAY "Autores dos livros sendo excluídos!"
                 call "frmCadLigados" using opLivroAut, 
                                      opExcluir, tLivro-isbn
             END-EVALUATE  
           WHEN sreg = opCliente   
             EVALUATE TRUE
               WHEN sacao = opNovo
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tCliente-cpf
                 call "validaCPF" using by content tCliente-cpf
                 if g-validaCPF = g-true then
                   call "tamReg" using by content sreg
                   move "tfCliente" to sparam
                   move 1 to nparam1
                   move 14 to nparam2
                   call "pesqArq" using sparam, tCliente-cpf, 
                                  nparam1, nparam2, g-tamReg
                   move g-pesqArq to slinha
                   if slinha = "@" then
                     move "tfCliente" to sparam
                     call "tamReg" using by content sreg
                     call "pesqLinhaExcluida" using sparam, g-tamReg
                     move "@" to sparam
                     move 1 to nparam1
                     call "mostrarDados" using sreg, sparam, nparam1
                     move 7 to nparam1
                     call "subMenu" using nparam1, sreg
                   else 
                     DISPLAY MSG-REGEXST
                   end-if
                 else 
                   DISPLAY MSG-CPFINV
                 end-if
               WHEN sacao = opPesquisar
                 move "tfCliente" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tCliente-cpf,nparam1,g-false,opTexto
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
               WHEN sacao = opAlterar
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo tCliente-cpf
                 move "@" to sparam
                 move 1 to nparam1
                 call "mostrarDados" using sreg, sparam, nparam1
                 move 9 to nparam1
                 call "subMenu" using nparam1, sreg
               WHEN sacao = opExcluir
                 move 10 to nparam1
                 call "subMenu" using nparam1, sreg
             END-EVALUATE  
           WHEN sreg = opVenda     
             EVALUATE TRUE
               WHEN sacao = opNovo
                 call "retDataHora"
                 move g-retDataHora to tVenda-dthrvenda 
                 move 1 to nparam1
                 call "rotulo" using sreg, nparam1
                 DISPLAY g-rotulo tVenda-dthrvenda
                 call "tamReg" using by content sreg
                 move "tfVenda" to sparam
                 move 1 to nparam1
                 move 19 to nparam2
                 call "pesqArq" using sparam, tCliente-cpf, 
                                nparam1, nparam2, g-tamReg
                 move g-pesqArq to slinha
                 if slinha = "@" then
                   move "tfCliente" to sparam
                   move 1 to nparam1
                   move 3 to nparam2
                   call "validaEntrada" using sparam,opCliente,nparam1,
                          tVenda-cpf,nparam2,g-false,opTexto
                   move g-validaEntrada to slinha
                   if slinha not = "@" then
                     call "trim" using by content slinha(1:14)
                     move g-trim to tVenda-cpf
                     call "validaCPF" using by content tVenda-cpf
                     if g-validaCPF = g-true then
                       move 2 to nparam1
                       call "rotulo" using opCliente, nparam1
                       DISPLAY " " g-rotulo 
                       DISPLAY slinha(g-nPosChave:g-nTamChave)                          
                       call "frmCadLigados" using opVenda, 
                                            opNovo, tVenda-cpf
                     else 
                       DISPLAY MSG-CPFINV
                     end-if
                   end-if
                 else 
                   DISPLAY MSG-REGEXST
                 end-if
               WHEN sacao = opPesquisar
                 move "tfVenda" to sparam
                 move 1 to nparam1
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tVenda-dthrvenda,nparam1,g-false,opDataHora
                 move g-validaEntrada to slinha
                 if slinha not = "@" then
                   move "@" to sparam
                   move 2 to nparam1
                   call "mostrarDados" using sreg, sparam, nparam1
                   move 3 to nparam1
                   call "mostrarDados" using sreg, slinha, nparam1
                   move 8 to nparam1
                   call "subMenu" using nparam1, sreg
                 end-if
             END-EVALUATE  
         END-EVALUATE
       END PROGRAM frmCadastros.
      *-------------------------------------------------------------
      * Realiza as consultas de acordo com o tipo de arquivo.
      * sreg - o tipo de arquivo
      * sacao - a ação a ser realizada
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. frmConsultas IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 slinha    PIC X(255).
         01 sparam    PIC X(255).
         01 sparam2   PIC X(255).
         01 nparam1   PIC 9(7).
         01 nparam2   PIC 9(7).
       LINKAGE SECTION.
         01 sreg  PIC 99.
         01 sacao PIC 9.
       PROCEDURE DIVISION USING sreg, sacao.
         EVALUATE TRUE
           WHEN sreg = opAssunto
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfAssunto" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                        tAssunto-assunto,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfAssunto" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opAutor
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfAutor" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tAutor-autor,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfAutor" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opEditora
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfEditora" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tEditora-editora,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfEditora" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opEndereco
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfEndereco" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tEditora-editora,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfEndereco" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 move 3 to nparam2
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,nparam2,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opIdioma
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfIdioma" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tIdioma-idioma,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfIdioma" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opPais
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfPais" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tPais-pais,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfPais" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opProfissao
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfProfissao" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                      tProfissao-profissao,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfProfissao" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opLivro
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfLivro" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tLivro-titulo,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfLivro" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 move 1 to nparam2
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,nparam2,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opCliente
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfCliente" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                         tCliente-nome,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfCliente" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 move 1 to nparam2
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,nparam2,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
           WHEN sreg = opVenda
             EVALUATE TRUE
               WHEN sacao = opPesquisar
                 move "tfVenda" to sparam
                 move 2 to nparam1
                 move 1 to nparam2
                 call "validaEntrada" using sparam,sreg,nparam1,
                      tVenda-cpf,nparam2,g-true,opTexto
                 move g-validaEntrada to slinha
               WHEN sacao = opListarTodos
                 move "tfVenda" to sparam
                 move "@" to sparam2
                 move 0 to nparam1
                 call "tamReg" using by content sreg
                 call "ListarTodos" using sparam, sreg, sparam2,     
                      nparam1,nparam1,g-tamReg,QTD-MAX-LINHA,g-false
                 if g-ListarTodos = g-false then
                    call "rotulo" using sreg, nparam1
                    DISPLAY g-rotulo
                 end-if
             END-EVALUATE  
         END-EVALUATE
         if slinha = "@" then
           DISPLAY " " WITH NO ADVANCING
         end-if
       END PROGRAM frmConsultas.
      *-------------------------------------------------------------
      * Mostra a tela de alteração de senha do sistema e realiza a alteração.
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. frmAlterarSenha IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bQuebra        PIC 9.
         01 sSenhaAtual    PIC X(255).
         01 sNovaSenha     PIC X(255).
         01 sConfirmaSenha PIC X(255).
         01 nopcao         PIC 9(7).
         01 sparam1        PIC X(255).
         01 nparam1        PIC 9(7).
         01 nparam2        PIC 9(7).
       PROCEDURE DIVISION.
         move 1 to nparam1
         call "rotulo" using opUsuario, nparam1
         DISPLAY g-rotulo tUsuario-login 
         move 1 to nopcao
         move g-false to bQuebra
         PERFORM UNTIL bQuebra = g-true
           EVALUATE TRUE	
             WHEN nopcao = 1
               move "Senha Atual: " to sparam1
               move 10 to nparam1
               call "digitaSenha" using sparam1, nparam1
               move g-digitaSenha to sSenhaAtual
               if sSenhaAtual not = tUsuario-senha then
                  DISPLAY MSG-SENCONFERE
                  move g-true to bQuebra
               else 
                 move 2 to nopcao
               end-if
             WHEN nopcao = 2
               move "Nova Senha: " to sparam1
               move 10 to nparam1
               call "digitaSenha" using sparam1, nparam1
               move g-digitaSenha to sNovaSenha
               move "Confirma Senha: " to sparam1
               call "digitaSenha" using sparam1, nparam1
               move g-digitaSenha to sConfirmaSenha
               if sNovaSenha not = sConfirmaSenha then
                  DISPLAY MSG-SENCONFIRM
                  move g-true to bQuebra
               else 
                 move 3 to nopcao
               end-if
             WHEN nopcao = 3
               call "tamReg" using by content opUsuario
               move "tfUsuario" to sparam1
               move 1 to nparam1
               move 10 to nparam2
               call "pesqArq" using sparam1, tUsuario-login, 
                                 nparam1, nparam2, g-tamReg                
               if g-pesqArq="@" then
                 DISPLAY MSG-LOGINENCON
               else
                 move sConfirmaSenha to tUsuario-senha
                 move 9 to nparam1
                 call "subMenu" using nparam1, opUsuario
                 move g-true to bQuebra
               end-if
           END-EVALUATE
         END-PERFORM       
       END PROGRAM frmAlterarSenha.
      *-------------------------------------------------------------
      * Executa uma ação de gravação de acordo com o tipo de arquivo.
      * sreg - o tipo de arquivo
      * sacao - a ação a ser realizada
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. btnAcao IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 saster    PIC X(255).
         01 sparam    PIC X(255).
       LINKAGE SECTION.
         01 sreg  PIC 99.
         01 sacao PIC 9.
       PROCEDURE DIVISION USING sreg, sacao.
         move "*" to saster
         EVALUATE TRUE
           WHEN sreg = opAssunto   move "tfAssunto"   to sparam
           WHEN sreg = opAutor     move "tfAutor"     to sparam
           WHEN sreg = opEditora   move "tfEditora"   to sparam
           WHEN sreg = opEndereco  move "tfEndereco"  to sparam
           WHEN sreg = opIdioma    move "tfIdioma"    to sparam
           WHEN sreg = opPais      move "tfPais"      to sparam
           WHEN sreg = opProfissao move "tfProfissao" to sparam
           WHEN sreg = opLivro     move "tfLivro"     to sparam
           WHEN sreg = opLivroAss  move "tfLivroAss"  to sparam
           WHEN sreg = opLivroAut  move "tfLivroAut"  to sparam
           WHEN sreg = opCliente   move "tfCliente"   to sparam
           WHEN sreg = opVenda     move "tfVenda"     to sparam
         END-EVALUATE
         EVALUATE TRUE
           WHEN sacao = opSalvarInclusao
             call "LinhaReg" using sreg
             call "escreveArq" using sparam, g-LinhaReg, 
                                 MSG-REGINC, MSG-REGNINC
           WHEN sacao = opSalvarAlteracao
             call "LinhaReg" using sreg
             call "escreveArq" using sparam, g-LinhaReg, 
                                 MSG-REGALT, MSG-REGNALT
           WHEN sacao = opConfirmaExclusao
             call "tamReg" using sreg
             call "repete" using saster, g-tamReg
             call "escreveArq" using sparam, g-LinhaReg, 
                                 MSG-REGEXC, MSG-REGNEXC
         END-EVALUATE  
       END PROGRAM btnAcao.
      *-------------------------------------------------------------
      * Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
      * nmenu - o número do menu
      * sreg - o tipo de arquivo
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. subMenu IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 opSubMenu  PIC 9(7).
         01 opCSubMenu PIC X.
         01 bSOp       PIC 9.
       LINKAGE SECTION.
         01 nmenu PIC 9(7).
         01 sreg  PIC 99.
       PROCEDURE DIVISION USING nmenu, sreg.
         move g-true to bSOp
         EVALUATE TRUE
           WHEN nmenu = 6
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "frmCadastros" using sreg, opNovo
                 WHEN opSubMenu = 2  
                   call "frmCadastros" using sreg, opPesquisar
                 WHEN opSubMenu = 3 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           WHEN nmenu = 7
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "btnAcao" using sreg, opSalvarInclusao 
                   move g-false to bSOp
                 WHEN opSubMenu = 2 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           WHEN nmenu = 8
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "frmCadastros" using sreg, opAlterar
                   move g-false to bSOp
                 WHEN opSubMenu = 2  
                   call "frmCadastros" using sreg, opExcluir
                   move g-false to bSOp
                 WHEN opSubMenu = 3 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           WHEN nmenu = 9
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "btnAcao" using sreg, opSalvarAlteracao
                   move g-false to bSOp
                 WHEN opSubMenu = 3 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           WHEN nmenu = 10
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opCSubMenu
               EVALUATE TRUE
                 WHEN (opCSubMenu = "S") or (opCSubMenu="s")
                   call "btnAcao" using sreg, opConfirmaExclusao
                   move g-false to bSOp
                 WHEN (opCSubMenu='N') or (opCSubMenu='n')
                   move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           WHEN nmenu = 12
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "frmConsultas" using sreg, opPesquisar
                   move g-false to bSOp
                 WHEN opSubMenu = 2  
                   call "frmConsultas" using sreg, opListarTodos
                   move g-false to bSOp
                 WHEN opSubMenu = 3 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
           WHEN nmenu = 14
             PERFORM UNTIL bSOp = g-false
               call "menu" using nmenu
               ACCEPT opCSubMenu
               EVALUATE TRUE
                 WHEN (opCSubMenu = "S") or (opCSubMenu="s")
                   call "btnAcao" using sreg, opSalvarInclusao
                   move g-false to bSOp
                 WHEN (opCSubMenu='N') or (opCSubMenu='n')
                   move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
         END-EVALUATE
       END PROGRAM subMenu.
      *-------------------------------------------------------------
      * Seleciona o submenu e/ou a tela certa de acordo com número do menu.
      * nmenu - o número do menu
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. usaMenu IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 nparam     PIC 9(7).
         01 opSubMenu  PIC 9(7).
         01 opSair     PIC X.
         01 bSOp       PIC 9.
       LINKAGE SECTION.
         01 num PIC 9(7).
       SCREEN SECTION.
       01 frmSobre.
          05 BLANK SCREEN.
          05 LINE 1  COL 1  VALUE "*------------------------------".
          05 LINE 1  COL 32 VALUE "------------------------------*".
          05 LINE 2  COL 1  VALUE "|  LL        II  VV       VV  R".
          05 LINE 2  COL 32 VALUE "RRRRRR   UU    UU   SSSSSSS   |".
          05 LINE 3  COL 1  VALUE "|  LL        II   VV     VV   R".
          05 LINE 3  COL 32 VALUE "R     R  UU    UU  SS         |".
          05 LINE 4  COL 1  VALUE "|  LL        II    VV   VV    R".
          05 LINE 4  COL 32 VALUE "R     R  UU    UU   SSSS      |".
          05 LINE 5  COL 1  VALUE "|  LL        II     VV VV     R".
          05 LINE 5  COL 32 VALUE "RRRRRR   UU    UU     SSSS    |".
          05 LINE 6  COL 1  VALUE "|  LLLL      II      VVV      R".
          05 LINE 6  COL 32 VALUE "R RR     UU    UU        SS   |".
          05 LINE 7  COL 1  VALUE "|  LLLLLLLL  II       V       R".
          05 LINE 7  COL 32 VALUE "R   RR    UUUUUU   SSSSSSSS   |".
          05 LINE 8  COL 1  VALUE "|                              ".
          05 LINE 8  COL 32 VALUE "                              |".
          05 LINE 9  COL 1  VALUE "|  VV       VV  II  RRRRRRR   T".
          05 LINE 9  COL 32 VALUE "TTTTTTT  UU    UU   SSSSSSS   |".
          05 LINE 10 COL 1  VALUE "|   VV     VV   II  RR     R   ".
          05 LINE 10 COL 32 VALUE "  TT     UU    UU  SS         |".
          05 LINE 11 COL 1  VALUE "|    VV   VV    II  RR     R   ".
          05 LINE 11 COL 32 VALUE "  TT     UU    UU   SSSS      |".
          05 LINE 12 COL 1  VALUE "|     VV VV     II  RRRRRRR    ".
          05 LINE 12 COL 32 VALUE "  TT     UU    UU     SSSS    |".
          05 LINE 13 COL 1  VALUE "|      VVV      II  RR RR      ".
          05 LINE 13 COL 32 VALUE "  TT     UU    UU        SS   |".
          05 LINE 14 COL 1  VALUE "|       V       II  RR   RR    ".
          05 LINE 14 COL 32 VALUE "  TT      UUUUUU   SSSSSSSS   |".
          05 LINE 15 COL 1  VALUE "|                              ".
          05 LINE 15 COL 32 VALUE "                              |".
          05 LINE 16 COL 1  VALUE "|                              ".
          05 LINE 16 COL 32 VALUE "                 Versao 1.0.0 |".
          05 LINE 17 COL 1  VALUE "| Sistema integrante do projeto".
          05 LINE 17 COL 32 VALUE " Livrus Virtus.               |".
          05 LINE 18 COL 1  VALUE "| Todos os direitos reservados ".
          05 LINE 18 COL 32 VALUE "para Henrique F. de Souza.    |".
          05 LINE 19 COL 1  VALUE "| Versao programada na linguage".
          05 LINE 19 COL 32 VALUE "m cobol.                      |".
          05 LINE 20 COL 1  VALUE "*------------------------------".
          05 LINE 20 COL 32 VALUE "------------------------------*".
          05 LINE 21 COL 1  VALUE "pressione para continuar...".
       PROCEDURE DIVISION USING num.
         move g-true to bSOp
         EVALUATE TRUE
      *    Cadastros  
           WHEN num = 1
             PERFORM UNTIL bSOp = g-false
               move 2 to nparam
               call "menu" using nparam
               ACCEPT opSubMenu
               move 6 to nparam
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "subMenu" using nparam, opAssunto
                 WHEN opSubMenu = 2  
                   call "subMenu" using nparam, opAutor
                 WHEN opSubMenu = 3  
                   call "subMenu" using nparam, opEditora
                 WHEN opSubMenu = 4  
                   call "subMenu" using nparam, opEndereco
                 WHEN opSubMenu = 5  
                   call "subMenu" using nparam, opIdioma
                 WHEN opSubMenu = 6  
                   call "subMenu" using nparam, opPais
                 WHEN opSubMenu = 7  
                   call "subMenu" using nparam, opProfissao
                 WHEN opSubMenu = 8  
                   call "subMenu" using nparam, opCliente
                 WHEN opSubMenu = 9  
                   call "subMenu" using nparam, opLivro
                 WHEN opSubMenu = 10 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
      *    Pesquisas  
           WHEN num = 2
             PERFORM UNTIL bSOp = g-false
               move 3 to nparam
               call "menu" using nparam
               ACCEPT opSubMenu
               move 12 to nparam
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   call "subMenu" using nparam, opAssunto
                 WHEN opSubMenu = 2  
                   call "subMenu" using nparam, opAutor
                 WHEN opSubMenu = 3  
                   call "subMenu" using nparam, opEditora
                 WHEN opSubMenu = 4  
                   call "subMenu" using nparam, opEndereco
                 WHEN opSubMenu = 5  
                   call "subMenu" using nparam, opIdioma
                 WHEN opSubMenu = 6  
                   call "subMenu" using nparam, opPais
                 WHEN opSubMenu = 7  
                   call "subMenu" using nparam, opProfissao
                 WHEN opSubMenu = 8  
                   call "subMenu" using nparam, opCliente
                 WHEN opSubMenu = 9  
                   call "subMenu" using nparam, opLivro
                 WHEN opSubMenu = 10 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
      *    Vendas  
           WHEN num = 3
             PERFORM UNTIL bSOp = g-false
               move 4 to nparam
               call "menu" using nparam
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1  
                   move 6 to nparam
                   call "subMenu" using nparam, opVenda
                 WHEN opSubMenu = 2  
                   move 12 to nparam
                   call "subMenu" using nparam, opVenda
                 WHEN opSubMenu = 3 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
      *    Opcoes  
           WHEN num = 4
             PERFORM UNTIL bSOp = g-false
               move 5 to nparam
               call "menu" using nparam
               ACCEPT opSubMenu
               EVALUATE TRUE
                 WHEN opSubMenu = 1 call "frmAlterarSenha"
                 WHEN opSubMenu = 2 
                   DISPLAY frmSobre
                   ACCEPT g-tecla-return 
                 WHEN opSubMenu = 3 
                   move 11 to nparam
                   call "menu" using nparam
                   ACCEPT opSair
                   if (opSair='S') or (opSair='s') then
                      call "fechaArqs"
                      STOP RUN
                   end-if
                 WHEN opSubMenu = 4 move g-false to bSOp
                 WHEN OTHER DISPLAY MSG-ERRO
               END-EVALUATE
             END-PERFORM
         END-EVALUATE
       END PROGRAM usaMenu.
      *-------------------------------------------------------------
      * Mostra as entradas e as saídas do sistema.
      * sreg - o tipo de arquivo
      * slinha - o registro com os dados
      * nOpcao - indica qual opção será mostrada
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. mostrarDados IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 sparam1    PIC X(255).
         01 sparam2    PIC X(255).
         01 nparam     PIC 9(7).
         01 nparam2    PIC 9(7).
         01 nparam3    PIC 9(7).
         01 nparam4    PIC 9(7).
         01 nparam5    PIC 9(7).
       LINKAGE SECTION.
         01 sreg       PIC 99.
         01 slinha     PIC X(255).
         01 nOpcao     PIC 9(7).
       PROCEDURE DIVISION USING sreg, slinha, nOpcao.
         EVALUATE TRUE
           WHEN sreg = opAssunto
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tAssunto-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tAssunto-assunto
               WHEN nOpcao = 2
                 DISPLAY "Código     Assunto"
                 DISPLAY "------     -------"
               WHEN nOpcao = 3
                 move slinha(1:10) to tAssunto-codigo 
                 move slinha(11:30) to tAssunto-assunto 
                 DISPLAY tAssunto-codigo " " tAssunto-assunto
             END-EVALUATE
           WHEN sreg = opAutor
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tAutor-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tAutor-autor
               WHEN nOpcao = 2
                 DISPLAY "Código     Autor"
                 DISPLAY "------     -----"
               WHEN nOpcao = 3
                 move slinha(1:10) to tAutor-codigo 
                 move slinha(11:30) to tAutor-autor 
                 DISPLAY tAutor-codigo " " tAutor-autor
             END-EVALUATE
           WHEN sreg = opEditora
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEditora-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tEditora-editora
               WHEN nOpcao = 2
                 DISPLAY "Código     Editora"
                 DISPLAY "------     -------"
               WHEN nOpcao = 3
                 move slinha(1:10) to tEditora-codigo 
                 move slinha(11:50) to tEditora-editora 
                 DISPLAY tEditora-codigo " " tEditora-editora
             END-EVALUATE
           WHEN sreg = opEndereco
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tEndereco-logradouro
                 move 3 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tEndereco-bairro
                 move 4 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tEndereco-cep
                 move 5 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tEndereco-cidade
                 move 6 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tEndereco-estado
               WHEN nOpcao = 3
                 move slinha(1:10) to tEndereco-codigo 
                 move slinha(11:40) to tEndereco-logradouro
                 move slinha(51:15) to tEndereco-bairro 
                 move slinha(66:8) to tEndereco-cep
                 move slinha(74:30) to tEndereco-cidade
                 move slinha(104:20) to tEndereco-estado
                 DISPLAY "--------------------"
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-logradouro
                 move 3 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-bairro
                 move 4 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-cep
                 move 5 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-cidade
                 move 6 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tEndereco-estado
             END-EVALUATE
           WHEN sreg = opIdioma
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tIdioma-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tIdioma-idioma
               WHEN nOpcao = 2
                 DISPLAY "Código     Idioma"
                 DISPLAY "------     ------"
               WHEN nOpcao = 3
                 move slinha(1:10) to tIdioma-codigo 
                 move slinha(11:20) to tIdioma-idioma 
                 DISPLAY tIdioma-codigo " " tIdioma-idioma
             END-EVALUATE
           WHEN sreg = opPais
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tPais-pais
               WHEN nOpcao = 2
                 DISPLAY "Código País"
                 DISPLAY "------ ----"
               WHEN nOpcao = 3
                 move slinha(1:3) to tPais-codigo 
                 move slinha(4:50) to tPais-pais 
                 DISPLAY tPais-codigo " " tPais-pais
             END-EVALUATE
           WHEN sreg = opProfissao
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tProfissao-codigo
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tProfissao-profissao
               WHEN nOpcao = 2
                 DISPLAY "Código     Profissão"
                 DISPLAY "------     ---------"
               WHEN nOpcao = 3
                 move slinha(1:10) to tProfissao-codigo 
                 move slinha(11:50) to tProfissao-profissao 
                 DISPLAY tProfissao-codigo " " tProfissao-profissao
             END-EVALUATE
           WHEN sreg = opLivro
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tLivro-titulo
                 move 3 to nparam
                 call "rotulo" using sreg, nparam
                 call "validaNumero" using g-rotulo, tLivro-edicao 
                 move g-validaNumero to tLivro-edicao
                 move 4 to nparam
                 call "rotulo" using sreg, nparam
                 call "validaNumero" using g-rotulo, tLivro-anopubli
                 move g-validaNumero to tLivro-anopubli
                 call "mostrarSubDados" using opLivro, 
                                    opEditora, g-false
                 move 6 to nparam
                 call "rotulo" using sreg, nparam
                 call "validaNumero" using g-rotulo, tLivro-volume
                 move g-validaNumero to tLivro-volume
                 call "mostrarSubDados" using opLivro, 
                                        opIdioma, g-false
                 move 8 to nparam
                 call "rotulo" using sreg, nparam
                 call "validaNumero" using g-rotulo, tLivro-npaginas
                 move g-validaNumero to tLivro-npaginas
                 move 9 to nparam
                 call "rotulo" using sreg, nparam
                 call "validaNumero" using g-rotulo, tLivro-preco
                 move g-validaNumero to tLivro-preco
                 move 10 to nparam
                 call "rotulo" using sreg, nparam
                 call "validaNumero" using g-rotulo, 
                                    tLivro-qtdestoque
                 move g-validaNumero to tLivro-qtdestoque
               WHEN nOpcao = 3
                 move slinha(1:13) to tLivro-isbn 
                 move slinha(14:50) to tLivro-titulo 
                 move slinha(64:10) to tLivro-edicao 
                 move slinha(74:10) to tLivro-anopubli 
                 move slinha(84:10) to tLivro-codeditora 
                 move slinha(94:10) to tLivro-volume 
                 move slinha(104:10) to tLivro-codidioma 
                 move slinha(114:10) to tLivro-npaginas 
                 move slinha(124:10) to tLivro-preco 
                 move slinha(134:10) to tLivro-qtdestoque
                 DISPLAY "--------------------"
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-isbn
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-titulo
                 move 3 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-edicao
                 move 4 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-anopubli
                 move 5 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-codeditora
                 call "mostrarSubDados" using opLivro, 
                                      opEditora, g-true
                 move 6 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-volume
                 move 7 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-codidioma
                 call "mostrarSubDados" using opLivro, 
                                       opIdioma, g-true
                 move 8 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-npaginas
                 move 9 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-preco
                 move 10 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tLivro-qtdestoque
                 move "tfLivroAss" to sparam1
                 move "tfAssunto" to sparam2
                 move 1 to nparam
                 move 13 to nparam2
                 move 14 to nparam3
                 move 10 to nparam4
                 move 4 to nparam5
                 call "ListarRegLigados" using sparam1, opLivroAss, 
                    nparam, nparam2, nparam3, nparam4, tLivro-isbn,
                    sparam2, opAssunto, nparam, nparam5
                 move "tfLivroAut" to sparam1
                 move "tfAutor" to sparam2
                 call "ListarRegLigados" using sparam1, opLivroAut, 
                    nparam, nparam2, nparam3, nparam4, tLivro-isbn,
                    sparam2, opAutor, nparam, nparam5
             END-EVALUATE
           WHEN sreg = opCliente
             EVALUATE TRUE
               WHEN nOpcao = 1
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tCliente-nome
                 move 3 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tCliente-email
                 move 4 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tCliente-identidade
                 move 5 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tCliente-sexo
                 move 6 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo WITH NO ADVANCING
                 ACCEPT tCliente-telefone
                 move 7 to nparam
                 call "rotulo" using sreg, nparam               
                 call "validaDataHora" using g-rotulo, 
                          tCliente-dtnascimento, g-true
                 move g-validaDataHora to tCliente-dtnascimento
                 call "mostrarSubDados" using opCliente, 
                                      opEndereco, g-false
                 call "mostrarSubDados" using opCliente, 
                                      opPais, g-false
                 call "mostrarSubDados" using opCliente, 
                                      opProfissao, g-false
               WHEN nOpcao = 3
                 move slinha(1:14) to tCliente-cpf 
                 move slinha(15:30) to tCliente-nome 
                 move slinha(45:30) to tCliente-email 
                 move slinha(75:10) to tCliente-identidade 
                 move slinha(85:1) to tCliente-sexo 
                 move slinha(86:17) to tCliente-telefone 
                 move slinha(103:10) to tCliente-dtnascimento 
                 move slinha(113:10) to tCliente-codendereco 
                 move slinha(123:3) to tCliente-codpais 
                 move slinha(126:10) to tCliente-codprofissao
                 DISPLAY "--------------------"
                 move 1 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-cpf
                 move 2 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-nome
                 move 3 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-email
                 move 4 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-identidade
                 move 5 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-sexo
                 move 6 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-telefone
                 move 7 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-dtnascimento
                 move 8 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-codendereco
                 call "mostrarSubDados" using opCliente, 
                                       opEndereco, g-true
                 move 9 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-codpais
                 call "mostrarSubDados" using opCliente, 
                                       opPais, g-true
                 move 10 to nparam
                 call "rotulo" using sreg, nparam
                 DISPLAY g-rotulo tCliente-codprofissao
                 call "mostrarSubDados" using opCliente, 
                                       opProfissao, g-true
             END-EVALUATE
           WHEN sreg = opVenda
             EVALUATE TRUE
               WHEN nOpcao = 1
                 call "mostrarSubDados" using opVenda, 
                                      opVenda, g-false
               WHEN nOpcao = 2
                 DISPLAY "DataHoraVenda       CPF            ISBN"
                 "          PreçoVenda"
                 DISPLAY "-------------       ---            ----"
                 "          ----------"
               WHEN nOpcao = 3
                 move slinha(1:19) to tVenda-dthrvenda 
                 move slinha(20:14) to tVenda-cpf 
                 move slinha(34:13) to tVenda-isbn
                 move slinha(47:10) to tVenda-precovenda
                 DISPLAY tVenda-dthrvenda " " tVenda-cpf " " 
                         tVenda-isbn " " tVenda-precovenda
             END-EVALUATE
         END-EVALUATE
       END PROGRAM mostrarDados.
      *-------------------------------------------------------------
      * Mostra as sub informções de entrada e de saída.
      * sreg - o tipo de arquivo
      * ssubreg - o subtipo de arquivo
      * bSoMostrar - se vai só mostrar na saída 
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. mostrarSubDados IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 sRegistro      PIC X(255).
         01 sPreco         PIC X(255).
         01 nMaxTentativas PIC 9(7).
         01 sparam         PIC X(255).
         01 nparam1        PIC 9(7).
         01 nparam2        PIC 9(7).
       LINKAGE SECTION.
         01 sreg       PIC 99.
         01 ssubreg    PIC 99.
         01 bSoMostrar PIC 9.
       PROCEDURE DIVISION USING sreg, ssubreg, bSoMostrar.
         move 3 to nMaxTentativas
         EVALUATE TRUE
           WHEN sreg = opLivro
             EVALUATE TRUE
               WHEN ssubreg = opEditora
                 move "tfEditora" to sparam
                 move 1 to nparam1
                 if bSoMostrar=g-true then                   
                   move 10 to nparam2
                   call "tamReg" using opEditora
                   call "pesqArq" using sparam,tLivro-codeditora,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to sRegistro 
                 else                   
                   call "validaEntrada" using sparam,ssubreg,
                              nparam1,tLivro-codeditora,
                              nMaxTentativas,g-false,opNumero
                   move g-validaEntrada to sRegistro
                 end-if
                 if sRegistro not = "@" then
                   move sRegistro(1:10) to tLivro-codeditora 
                   move 2 to nparam1
                   call "rotulo" using opEditora, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                 end-if
               WHEN ssubreg = opIdioma
                 move "tfIdioma" to sparam
                 move 1 to nparam1
                 if bSoMostrar=g-true then                   
                   move 10 to nparam2
                   call "tamReg" using opIdioma
                   call "pesqArq" using sparam,tLivro-codidioma,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to sRegistro 
                 else                   
                   call "validaEntrada" using sparam,ssubreg,
                              nparam1,tLivro-codidioma,
                              nMaxTentativas,g-false,opNumero
                   move g-validaEntrada to sRegistro
                 end-if
                 if sRegistro not = "@" then
                   move sRegistro(1:10) to tLivro-codidioma 
                   move 2 to nparam1
                   call "rotulo" using opIdioma, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                 end-if
             END-EVALUATE
           WHEN sreg = opCliente
             EVALUATE TRUE
               WHEN ssubreg = opEndereco
                 move "tfEndereco" to sparam
                 move 1 to nparam1
                 if bSoMostrar=g-true then                   
                   move 10 to nparam2
                   call "tamReg" using opEndereco
                   call "pesqArq" using sparam,tCliente-codendereco,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to sRegistro 
                 else                   
                   call "validaEntrada" using sparam,ssubreg,
                              nparam1,tCliente-codendereco,
                              nMaxTentativas,g-false,opNumero
                   move g-validaEntrada to sRegistro
                 end-if
                 if sRegistro not = "@" then
                   move sRegistro(1:10) to tCliente-codendereco
                   move 2 to nparam1
                   call "rotulo" using opEndereco, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                   move 3 to nparam1
                   call "rotulo" using opEndereco, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                   move 4 to nparam1
                   call "rotulo" using opEndereco, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                   move 5 to nparam1
                   call "rotulo" using opEndereco, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                   move 6 to nparam1
                   call "rotulo" using opEndereco, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                end-if
               WHEN ssubreg = opPais
                 move "tfPais" to sparam
                 move 1 to nparam1
                 if bSoMostrar=g-true then                   
                   move 3 to nparam2
                   call "tamReg" using opPais
                   call "pesqArq" using sparam,tCliente-codpais,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to sRegistro 
                 else                   
                   call "validaEntrada" using sparam,ssubreg,
                              nparam1,tCliente-codpais,
                              nMaxTentativas,g-false,opTexto
                   move g-validaEntrada to sRegistro
                 end-if
                 if sRegistro not = "@" then
                   move sRegistro(1:3) to tCliente-codpais 
                   move 2 to nparam1
                   call "rotulo" using opPais, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                 end-if
               WHEN ssubreg = opProfissao
                 move "tfProfissao" to sparam
                 move 1 to nparam1
                 if bSoMostrar=g-true then                   
                   move 10 to nparam2
                   call "tamReg" using opProfissao
                   call "pesqArq" using sparam,tCliente-codprofissao,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to sRegistro 
                 else                   
                   call "validaEntrada" using sparam,ssubreg,
                              nparam1,tCliente-codprofissao,
                              nMaxTentativas,g-false,opNumero
                   move g-validaEntrada to sRegistro
                 end-if
                 if sRegistro not = "@" then
                   move sRegistro(1:10) to tCliente-codprofissao
                   move 2 to nparam1
                   call "rotulo" using opProfissao, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY sRegistro(g-nPosChave:g-nTamChave)
                 end-if
             END-EVALUATE
           WHEN sreg = opVenda
             move "tfLivro" to sparam
             move 1 to nparam1
             move 13 to nparam2
             call "tamReg" using opLivro
             call "pesqArq" using sparam,tVenda-isbn,
                                  nparam1,nparam2,g-tamReg
             move g-pesqArq to sRegistro 
             if sRegistro not = "@" then
               move 2 to nparam1
               call "rotulo" using opLivro, nparam1
               DISPLAY " " g-rotulo WITH NO ADVANCING
               DISPLAY sRegistro(g-nPosChave:g-nTamChave)
               move 9 to nparam1
               call "rotulo" using opLivro, nparam1
               DISPLAY " " g-rotulo WITH NO ADVANCING
               move sRegistro(g-nPosChave:g-nTamChave) to sPreco
               move sPreco to g-nPreco
               DISPLAY sPreco
             end-if
         END-EVALUATE
       END PROGRAM mostrarSubDados.
      *-------------------------------------------------------------
      * Realiza os cadastros dos arquivos que se ligam a outros arquivos.
      * sreg - o tipo de arquivo
      * sacao - a ação a ser realizada
      * sCodigo - um das chaves do arquivo de ligação
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. frmCadLigados IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 nQtd           PIC 9(7).
         01 nCont          PIC 9(7).
         01 nQtdEstoque    PIC 9(7).
         01 nTotalPreco    PIC 9(7)V9(2).
         01 slinha         PIC X(255).
         01 sTotalPreco    PIC X(255).
         01 sPreco         PIC X(255).
         01 sQtd           PIC X(255).
         01 sparam         PIC X(255).
         01 nparam1        PIC 9(7).
         01 nparam2        PIC 9(7).
       LINKAGE SECTION.
         01 sreg       PIC 99.
         01 sacao      PIC 99.
         01 sCodigo    PIC X(255).
       PROCEDURE DIVISION USING sreg, sacao, sCodigo.
         EVALUATE TRUE
           WHEN sacao = opNovo
             move 1 to nCont
             EVALUATE TRUE
               WHEN sreg = opLivroAss
                 move "Quantos assuntos quer cadastrar?: " to sparam
                 call "validaNumero" using sparam, sQtd
                 move g-validaNumero to sQtd
                 move sQtd to nQtd
      *           seek(tfLivroAss, 0);
                 PERFORM UNTIL nCont > nQtd
                   move sCodigo to tLivroAss-isbn
                   move 2 to nparam1
                   call "rotulo" using opLivroAss, nparam1
                   DISPLAY g-rotulo WITH NO ADVANCING
                   ACCEPT tLivroAss-codassunto
                   call "tamReg" using opAssunto
                   move "tfAssunto" to sparam
                   move 1 to nparam1
                   move 10 to nparam2
                   call "pesqArq" using sparam,tLivroAss-codassunto,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to slinha        
                   move 2 to nparam1
                   call "rotulo" using opAssunto, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY slinha(g-nPosChave: g-nTamChave)
                   move "tfLivroAss" to sparam
                   call "tamReg" using sreg
                   call "pesqLinhaExcluida" using sparam, g-tamReg
                   move 14 to nparam1
                   call "subMenu" using nparam1, sreg
                   add 1 to nCont
                 END-PERFORM
               WHEN sreg = opLivroAut
                 move "Quantos autores quer cadastrar?: " to sparam
                 call "validaNumero" using sparam, sQtd
                 move g-validaNumero to sQtd
                 move sQtd to nQtd
      *           seek(tfLivroAut, 0);
                 PERFORM UNTIL nCont > nQtd
                   move sCodigo to tLivroAut-isbn
                   move 2 to nparam1
                   call "rotulo" using opLivroAut, nparam1
                   DISPLAY g-rotulo WITH NO ADVANCING
                   ACCEPT tLivroAut-codautor
                   call "tamReg" using opAutor
                   move "tfAutor" to sparam
                   move 1 to nparam1
                   move 10 to nparam2
                   call "pesqArq" using sparam,tLivroAut-codautor,
                                        nparam1,nparam2,g-tamReg
                   move g-pesqArq to slinha        
                   move 2 to nparam1
                   call "rotulo" using opAutor, nparam1
                   DISPLAY " " g-rotulo WITH NO ADVANCING
                   DISPLAY slinha(g-nPosChave: g-nTamChave)
                   move "tfLivroAut" to sparam
                   call "tamReg" using sreg
                   call "pesqLinhaExcluida" using sparam, g-tamReg
                   move 14 to nparam1
                   call "subMenu" using nparam1, sreg
                   add 1 to nCont
                 END-PERFORM
               WHEN sreg = opVenda
                 move "Quantos livros quer vender?: " to sparam
                 call "validaNumero" using sparam, sQtd
                 move g-validaNumero to sQtd
                 move sQtd to nQtd
                 move 0 to nTotalPreco
                 PERFORM UNTIL nCont > nQtd
                   move "tfLivro" to sparam
                   move 1 to nparam1
                   move 3 to nparam2
                   call "validaEntrada" using sparam,opLivro,
                     nparam1,tVenda-isbn,nparam2,g-false,opTexto
                   move g-validaEntrada to slinha
                   if slinha not = "@" then
                     move slinha(1:13) to tVenda-isbn
                     call "validaISBN" using tVenda-isbn
                     if g-validaISBN = g-true then
                       move "@" to sparam
                       move 1 to nparam1
                       call "mostrarDados" using sreg, 
                                       sparam, nparam1
                       move slinha(134:10) to tLivro-qtdestoque
                       move tLivro-qtdestoque to nQtdEstoque
                       if nQtdEstoque > 0 then
                          add nTotalPreco to g-nPreco 
                                    giving nTotalPreco
      *                    move g-nPreco to sPreco
                          move sPreco to tVenda-precovenda
                          move g-false to g-SalvarInclusao
                          move 14 to nparam1
                          call "subMenu" using nparam1, sreg
                          if g-SalvarInclusao = g-true then
                             move "tfLivro" to sparam
                             move 1 to nparam1
                             move 13 to nparam2
                             call "tamReg" using opLivro
                             call "pesqArq" using sparam,tVenda-isbn,
                                     nparam1, nparam2, g-tamReg
                             move g-pesqArq to slinha
                             if slinha not = "@" then
                                add 1 to nQtdEstoque
                                move nQtdEstoque to tLivro-qtdestoque
                                STRING slinha(1:133) DELIMITED BY SIZE
      *                                 esp(tLivro.qtdestoque,10)
                                  tLivro-qtdestoque DELIMITED BY SIZE
                                  INTO slinha
                                END-STRING
                                move "tfLivro" to sparam
                                call "escreveArq" using sparam,
                                               slinha, " ", " "
                             end-if
                          end-if
                          add 1 to nCont
                       else 
                         DISPLAY MSG-SEMESTOQUE
                       end-if
                     else 
                       DISPLAY MSG-ISBNINV
                     end-if
                   end-if
                 END-PERFORM
             END-EVALUATE
           WHEN sacao = opExcluir
             EVALUATE TRUE
               WHEN sreg = opLivroAss
                 move "tfLivroAss" to sparam
                 move 1 to nparam1
                 move 13 to nparam2
                 call "ExcluirRegLigados" using sparam, sreg, 
                                    nparam1, nparam2, sCodigo
               WHEN sreg = opLivroAut
                 move "tfLivroAut" to sparam
                 move 1 to nparam1
                 move 13 to nparam2
                 call "ExcluirRegLigados" using sparam, sreg, 
                                    nparam1, nparam2, sCodigo
             END-EVALUATE
         END-EVALUATE
       END PROGRAM frmCadLigados.
      *-------------------------------------------------------------
      * Realiza a exclusão dos arquivos de ligação.
      * sArq - o arquivo de ligação
      * sreg - o tipo de arquivo de ligação
      * nPosChave - a posicao inicial da chave dentro do registro
      * nTamChave - o tamanho da chave dentro do registro
      * sChave - a chave a ser excluida
      *-------------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. ExcluirRegLigados IS COMMON PROGRAM.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
         01 bQuebra        PIC 9.
       LINKAGE SECTION.
         01 sArq       PIC X(255).
         01 sreg       PIC 99.
         01 nPosChave  PIC 9(7).
         01 nTamChave  PIC 9(7).
         01 sChave     PIC X(255).
       PROCEDURE DIVISION USING sArq, sreg, nPosChave, 
                                      nTamChave, sChave.
         move g-false to bQuebra
      *   seek(sArq, 0)
         if sArq="tfLivroAss" then
           READ tfLivroAss
              AT END MOVE HIGH-VALUES TO regLivroAss
           END-READ
           PERFORM UNTIL regAssunto = HIGH-VALUES or bQuebra = g-true
             call "trim" using by content 
                regAssunto(nPosChave:nTamChave)
             if g-trim = sChave then
               call "btnAcao" using sreg,opConfirmaExclusao
      *         move nPosicao to g-npos-registro
               move g-true to bQuebra
             else
      *         add 1 to nPosicao              
               READ tfLivroAss
                  AT END MOVE HIGH-VALUES TO regLivroAss
               END-READ 
             end-if
           END-PERFORM
         end-if
       END PROGRAM ExcluirRegLigados.

       END PROGRAM Livrus.
