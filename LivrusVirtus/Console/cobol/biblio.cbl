      $set ans85 nestcall noosvs mf
      * ---------------------------------------------------
      * Nome : Sistema de Automacao de Biblioteca (Biblio)
      * Autor : Henrique Figueiredo de Souza
      * Linguagem : Cobol
      * Compilador : Microsoft Cobol
      * Data de Realizacao : 24 de outubro de 2002
      * Ultima Atualizacao : 25 de outubro de 2002
      * Versao do Sistema : 1.0
      * Nome do(s) Arquivo(s) e Como Compilar (nesta ordem) :
      * 1. Biblio.cbl --> "xcobol biblio.cbl"
      * 2. Biblio.obj --> "link biblio.obj"
      *
      * Descricao :
      * O Sistema e composto dos seguintes modulos:
      * 1.Modulo de Acervos da Biblioteca
      *   Onde se realiza a manutencao dos livros da biblioteca
      * 2.Modulo de Usuarios da Bilioteca
      *   Onde se realiza a manutencao dos usuarios da biblioteca
      * 3.Modulo de Emprestimos e Devolucoes da Biblioteca
      *   Onde se efetua os emprestimos e devolucoes da biblioteca
      * 4.Modulo de Opcoes do sistema
      *   Onde e possivel ver sobre o sistema e sair dele
      * -----------------------------------------------------------
       IDENTIFICATION DIVISION.
       PROGRAM-ID. Biblio.
       AUTHOR. Henrique F de Souza.
      * -----------------------------------------------------------
       ENVIRONMENT DIVISION.
       INPUT-OUTPUT SECTION.
       FILE-CONTROL.
       SELECT arq-livros ASSIGN TO "livros.dat"
              ORGANIZATION IS LINE SEQUENTIAL.
       SELECT arq-usuarios ASSIGN TO "usuarios.dat"
              ORGANIZATION IS LINE SEQUENTIAL.
       SELECT arq-emprestimos ASSIGN TO "empresti.dat"
              ORGANIZATION IS LINE SEQUENTIAL.

       DATA DIVISION.
       FILE SECTION.
       FD arq-livros.
       01 livros-rec.
          05 ninsc      PIC 9(5).
          05 titulo     PIC X(30).
          05 autor      PIC X(30).
          05 arealr     PIC X(30).
          05 pchave     PIC X(10).
          05 edicao     PIC 9(4).
          05 anopubli   PIC 9(4).
          05 editora    PIC X(30).
          05 volume     PIC 9(4).
          05 estado     PIC X.

       FD arq-usuarios.
       01 usuarios-rec. 
          05 ninsc      PIC 9(5)  VALUE ZEROS.
          05 nome       PIC X(30) VALUE SPACES.
          05 ident      PIC X(10) VALUE SPACES.
          05 endereco.
             10 logra   PIC X(30) VALUE SPACES.
             10 numero  PIC 9(5)  VALUE ZEROS.
             10 compl   PIC X(10) VALUE SPACES.
             10 bairro  PIC X(20) VALUE SPACES.
             10 cep     PIC X(8)  VALUE SPACES.
          05 telefone   PIC X(11) VALUE SPACES.
          05 categoria  PIC X     VALUE SPACES.
          05 situacao   PIC 9     VALUE ZEROS.

       FD arq-emprestimos.
       01 emprestimos-rec. 
          05 ninsc-usuario PIC 9(5)  VALUE ZEROS.
          05 ninsc-livro   PIC 9(5)  VALUE ZEROS.
          05 dt-emprestimo PIC X(10) VALUE SPACES.
          05 dt-devolucao  PIC X(10) VALUE SPACES.
          05 removido      PIC X     VALUE "N".

      * -----------------------------------------------------------
       WORKING-STORAGE SECTION.
       01 tecla-return  PIC XX    VALUE X"3030".
       01 opcao-menu    PIC X     VALUE SPACES.
       01 data-corrente.
          05 ano        PIC 99.
          05 mes        PIC 99.
          05 dia        PIC 99.
       01 tempo-corrente.
          05 hora       PIC 99.
          05 min        PIC 99.
          05 FILLER     PIC 9(4).
      * -----------------------------------------------------------
       SCREEN SECTION.
       01 form-splash.
          05 BLANK SCREEN.
          05 LINE 1  COL 1  VALUE "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 1  COL 32 VALUE "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿".
          05 LINE 2  COL 1  VALUE "³  ²²²²²²²     ²    ²²²²²²²    ".
          05 LINE 2  COL 32 VALUE "²       ²    ²²²²²²       ³".
          05 LINE 3  COL 1  VALUE "³ ²²²    ²²²   ²²  ²²²    ²²²  ".
          05 LINE 3  COL 32 VALUE "²²      ²²  ²²²  ²²²      ³".
          05 LINE 4  COL 1  VALUE "³ ²²²²²²²²²    ²²  ²²²²²²²²²   ".
          05 LINE 4  COL 32 VALUE "²²      ²²  ²²    ²²      ³".
          05 LINE 5  COL 1  VALUE "³ ²²²    ²²²   ²²  ²²²    ²²²  ".
          05 LINE 5  COL 32 VALUE "²²²     ²²  ²²    ²²      ³".
          05 LINE 6  COL 1  VALUE "³ ²²²²   ²²²   ²²  ²²²²   ²²²  ".
          05 LINE 6  COL 32 VALUE "²²²²    ²²  ²²²  ²²²      ³".
          05 LINE 7  COL 1  VALUE "³  ²²²²²²²²²   ²²   ²²²²²²²²²  ".
          05 LINE 7  COL 32 VALUE "²²²²²²  ²²   ²²²²²²       ³".
          05 LINE 8  COL 1  VALUE "³ Programa Desenvolvido por Hen".
          05 LINE 8  COL 32 VALUE "rique Figueiredo de Souza ³".
          05 LINE 9  COL 1  VALUE "³ Todos os Direitos Reservados ".
          05 LINE 9  COL 32 VALUE "- 2002   Versao 1.0       ³".
          05 LINE 10 COL 1  VALUE "³ Linguagem Usada Nesta Versao ".
          05 LINE 10 COL 32 VALUE "<< COBOL >>               ³".
          05 LINE 11 COL 1  VALUE "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 11 COL 32 VALUE "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ".
          05 LINE 12 COL 1  VALUE SPACES.
          05 LINE 13 COL 1  VALUE "pressione para continuar...".
       01 cabecalho.
          05 BLANK SCREEN.
          05 LINE 1  COL 1  VALUE "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 1  COL 32 VALUE "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿".
          05 LINE 2  COL 1  VALUE "³ Sistema de Automacao de Biblio".
          05 LINE 2  COL 32 VALUE "teca ".
          05 LINE 2  COL 39 PIC 99 USING dia.
          05 LINE 2  COL 41 VALUE "/".
          05 LINE 2  COL 42 PIC 99 USING mes.
          05 LINE 2  COL 44 VALUE "/".
          05 LINE 2  COL 45 PIC 99 USING ano.
          05 LINE 2  COL 50 VALUE " ".
          05 LINE 2  COL 51 PIC 99 USING hora.
          05 LINE 2  COL 53 VALUE ":".
          05 LINE 2  COL 54 PIC 99 USING min.
          05 LINE 2  COL 57 VALUE " ³".
          05 LINE 3  COL 1  VALUE "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 3  COL 32 VALUE "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ".
       01 menu.
          05 LINE 4  COL 1  VALUE "ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 4  COL 32 VALUE "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 4  COL 63 VALUE "ÄÄÄÄÄÄÄ¿".
          05 LINE 5  COL 1  VALUE "³ (A)cervo  (U)suarios  (E)mpre".
          05 LINE 5  COL 32 VALUE "stimos e Devolucoes  (O)pcoes  ".
          05 LINE 5  COL 63 VALUE "(S)air ³".
          05 LINE 6  COL 1  VALUE "ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 6  COL 32 VALUE "ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ".
          05 LINE 6  COL 63 VALUE "ÄÄÄÄÄÄÄÙ".
          05 LINE 7  COL 1  VALUE "Escolha uma opcao > ".
      * -----------------------------------------------------------
       PROCEDURE DIVISION.
        principal.
         ACCEPT data-corrente FROM DATE.
         ACCEPT tempo-corrente FROM TIME.
         DISPLAY form-splash
         ACCEPT tecla-return 
         PERFORM WITH TEST AFTER UNTIL opcao-menu = "S"
                                       OR opcao-menu = "s"
          DISPLAY cabecalho
          DISPLAY menu
          ACCEPT opcao-menu
          IF opcao-menu = "A" OR opcao-menu = "a" THEN
             CALL "ctrlmenu" USING BY CONTENT "1"
          ELSE IF opcao-menu = "U" OR opcao-menu = "u" THEN
             CALL "ctrlmenu" USING BY CONTENT "2"
          ELSE IF opcao-menu = "E" OR opcao-menu = "e" THEN
             CALL "ctrlmenu" USING BY CONTENT "3"
          ELSE IF opcao-menu = "O" OR opcao-menu = "o" THEN
             CALL "ctrlmenu" USING BY CONTENT "4"
          END-IF
         END-PERFORM.

       STOP RUN.            

       END PROGRAM Biblio.
