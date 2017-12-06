IMPLEMENTATION MODULE Sistema;

FROM Rotinas IMPORT stemp, WriteLinha, ReadLinha, Ss,
SomaStr, copy, trim, repete, esp, zeros, strRelativa, 
validaCPF, validaISBN, digitaSenha, validaNumero, 
validaDataHora;
FROM Arquivos IMPORT TAM_CRLF, tfAssunto, tfAutor, tfEditora, 
tfIdioma, tfEndereco, tfPais, tfProfissao, tfLivro, tfLivroAss, 
tfLivroAut, tfCliente, tfUsuario, tfVenda,
tAssunto, tAutor, tEditora, tIdioma, tEndereco, tPais, 
tProfissao, tLivro, tLivroAss, tLivroAut, tCliente, tUsuario, tVenda,
tamArq, fimArq, lerArq, gravarArq, abrecriaArqs, fechaArqs,
pesqArq, pesqLinhaExcluida, pesqMaxCod, escreveArq, tamReg,
ctArqs, ctAcao, ctTipo, LinhaReg;
FROM Ascii IMPORT nul;
FROM CardStr IMPORT Value, Give, Alignment;
FROM RealStr IMPORT Take, ConvResults, GiveFloat; 
FROM StdStrings IMPORT String, Compare, CompareResult, Length, Assign, Append;
FROM Terminal IMPORT WriteString, GetKeyStroke, WriteLn;
FROM UxFiles IMPORT File, Open, Close, OpenMode, Create, SetPos, EndFile,
ReadByte, WriteByte, FileSize, GetPos;
FROM InOut IMPORT Read, CloseInput;

(*------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------*)
PROCEDURE rotulo(sreg: ctArqs; nNum: CARDINAL): String;
VAR sret: String;
BEGIN
sret:='';
IF sreg=opAssunto THEN 
   CASE nNum OF
   | 0: sret:='Assunto(s) não encontrado(s)!';
   | 1: sret:='Código do assunto: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Assunto: ';
        g_nPosChave:=11;
        g_nTamChave:=30;
   END;
ELSIF sreg=opAutor THEN 
   CASE nNum OF
   | 0: sret:='Autor(es) não encontrado(s)!';
   | 1: sret:='Código do autor: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Autor: ';
        g_nPosChave:=11;
        g_nTamChave:=30;
   END;
ELSIF sreg=opEditora THEN 
   CASE nNum OF
   | 0: sret:='Editora(s) não encontrada(s)!';
   | 1: sret:='Código da editora: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Editora: ';
        g_nPosChave:=11;
        g_nTamChave:=50;
   END;
ELSIF sreg=opEndereco THEN 
   CASE nNum OF
   | 0: sret:='Endereço(s) não encontrado(s)!';
   | 1: sret:='Código do endereço: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Logradouro: ';
        g_nPosChave:=11;
        g_nTamChave:=40;
   | 3: sret:='Bairro: ';
        g_nPosChave:=51;
        g_nTamChave:=15;
   | 4: sret:='CEP: ';
        g_nPosChave:=66;
        g_nTamChave:=8;
   | 5: sret:='Cidade: ';
        g_nPosChave:=74;
        g_nTamChave:=30;
   | 6: sret:='Estado: ';
        g_nPosChave:=104;
        g_nTamChave:=20;
   END;
ELSIF sreg=opIdioma THEN 
   CASE nNum OF
   | 0: sret:='Idioma(s) não encontrado(s)!';
   | 1: sret:='Código do idioma: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Idioma: ';
        g_nPosChave:=11;
        g_nTamChave:=20;
   END;
ELSIF sreg=opPais THEN 
   CASE nNum OF
   | 0: sret:='País(es) não encontrado(s)!';
   | 1: sret:='Código do país: ';
        g_nPosChave:=1;
        g_nTamChave:=3;
   | 2: sret:='País: ';
        g_nPosChave:=4;
        g_nTamChave:=50;
   END;
ELSIF sreg=opProfissao THEN 
   CASE nNum OF
   | 0: sret:='Profissão(es) não encontrada(s)!';
   | 1: sret:='Código da profissão: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Profissão: ';
        g_nPosChave:=11;
        g_nTamChave:=50;
   END;
ELSIF sreg=opUsuario THEN 
   CASE nNum OF
   | 0: sret:='login ou senha incorreta, tente de novo!';
   | 1: sret:='Login: ';
        g_nPosChave:=1;
        g_nTamChave:=10;
   | 2: sret:='Senha: ';
        g_nPosChave:=11;
        g_nTamChave:=10;
   END;
ELSIF sreg=opLivro THEN 
   CASE nNum OF
   | 0: sret:='Livro(s) não encontrado(s)!';
   | 1: sret:='ISBN: ';
        g_nPosChave:=1;
        g_nTamChave:=13;
   | 2: sret:='Título: ';
        g_nPosChave:=14;
        g_nTamChave:=50;
   | 3: sret:='Edição: ';
        g_nPosChave:=64;
        g_nTamChave:=10;
   | 4: sret:='Ano de Publicação: ';
        g_nPosChave:=74;
        g_nTamChave:=10;
   | 5: sret:='Código da editora: ';
        g_nPosChave:=84;
        g_nTamChave:=10;
   | 6: sret:='Volume: ';
        g_nPosChave:=94;
        g_nTamChave:=10;
   | 7: sret:='Código do idioma: ';
        g_nPosChave:=104;
        g_nTamChave:=10;
   | 8: sret:='Número de páginas: ';
        g_nPosChave:=114;
        g_nTamChave:=10;
   | 9: sret:='Preço: ';
        g_nPosChave:=124;
        g_nTamChave:=10;
   | 10: sret:='Qtd. Estoque: ';
         g_nPosChave:=134;
         g_nTamChave:=10;
   END;
ELSIF sreg=opLivroAss THEN 
   CASE nNum OF
   | 0: sret:='Assunto(s) não encontrado(s)!';
   | 1: sret:='ISBN: ';
        g_nPosChave:=1;
        g_nTamChave:=13;
   | 2: sret:='Código do assunto: ';
        g_nPosChave:=14;
        g_nTamChave:=10;
   END;
ELSIF sreg=opLivroAut THEN 
   CASE nNum OF
   | 0: sret:='Autor(s) não encontrado(s)!';
   | 1: sret:='ISBN: ';
        g_nPosChave:=1;
        g_nTamChave:=13;
   | 2: sret:='Código do autor: ';
        g_nPosChave:=14;
        g_nTamChave:=10;
   END;
ELSIF sreg=opCliente THEN 
   CASE nNum OF
   | 0: sret:='Cliente(s) não encontrado(s)!';
   | 1: sret:='CPF: ';
        g_nPosChave:=1;
        g_nTamChave:=14;
   | 2: sret:='Nome: ';
        g_nPosChave:=15;
        g_nTamChave:=30;
   | 3: sret:='E-mail: ';
        g_nPosChave:=45;
        g_nTamChave:=30;
   | 4: sret:='Identidade: ';
        g_nPosChave:=75;
        g_nTamChave:=10;
   | 5: sret:='Sexo: ';
        g_nPosChave:=85;
        g_nTamChave:=1;
   | 6: sret:='Telefone: ';
        g_nPosChave:=86;
        g_nTamChave:=17;
   | 7: sret:='Dt. Nascimento: ';
        g_nPosChave:=103;
        g_nTamChave:=10;
   | 8: sret:='Código do endereço: ';
        g_nPosChave:=113;
        g_nTamChave:=10;
   | 9: sret:='Código do país: ';
        g_nPosChave:=123;
        g_nTamChave:=3;
   | 10: sret:='Código da Profissão: ';
         g_nPosChave:=126;
         g_nTamChave:=10;
   END;
ELSIF sreg=opVenda THEN 
   CASE nNum OF
   | 0: sret:='Venda(s) não encontrada(s)!';
   | 1: sret:='Data/Hora venda: ';
        g_nPosChave:=1;
        g_nTamChave:=19;
   | 2: sret:='CPF: ';
        g_nPosChave:=20;
        g_nTamChave:=14;
   | 3: sret:='ISBN: ';
        g_nPosChave:=34;
        g_nTamChave:=13;
   | 4: sret:='Pre+o de venda: ';
        g_nPosChave:=47;
        g_nTamChave:=10;
   END;
END;

RETURN sret;
END rotulo;
(*------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------*)
PROCEDURE menu(num: CARDINAL);
BEGIN
 IF (num=1) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| (C)adastros        (P)esquisas     (V)endas        (O)pções  |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=2) THEN 
   WriteLinha('*---------------------------------*');
   WriteLinha('| 01. Cadastro de Assuntos        |');
   WriteLinha('| 02. Cadastro de Autores         |');
   WriteLinha('| 03. Cadastro de Editoras        |');
   WriteLinha('| 04. Cadastro de Endereços       |');
   WriteLinha('| 05. Cadastro de Idiomas         |');
   WriteLinha('| 06. Cadastro de Países          |');
   WriteLinha('| 07. Cadastro de Profissões      |');
   WriteLinha('| 08. Cadastro de Clientes        |');
   WriteLinha('| 09. Cadastro de Livros          |');
   WriteLinha('| 10. Voltar ao menu              |');
   WriteLinha('*---------------------------------*');
 ELSIF (num=3) THEN 
   WriteLinha('*---------------------------------*');
   WriteLinha('| 01. Consulta de Assuntos        |');
   WriteLinha('| 02. Consulta de Autores         |');
   WriteLinha('| 03. Consulta de Editoras        |');
   WriteLinha('| 04. Consulta de Endereços       |');
   WriteLinha('| 05. Consulta de Idiomas         |');
   WriteLinha('| 06. Consulta de Países          |');
   WriteLinha('| 07. Consulta de Profissões      |');
   WriteLinha('| 08. Consulta de Clientes        |');
   WriteLinha('| 09. Consulta de Livros          |');
   WriteLinha('| 10. Voltar ao menu              |');
   WriteLinha('*---------------------------------*');
 ELSIF (num=4) THEN 
   WriteLinha('*---------------------------------*');
   WriteLinha('| 01. Vender Livros               |');
   WriteLinha('| 02. Vendas Realizadas           |');
   WriteLinha('| 03. Voltar ao menu              |');
   WriteLinha('*---------------------------------*');
 ELSIF (num=5) THEN 
   WriteLinha('*---------------------------------*');
   WriteLinha('| 01. Alterar senha               |');
   WriteLinha('| 02. Sobre o sistema             |');
   WriteLinha('| 03. Sair do sistema             |');
   WriteLinha('| 04. Voltar ao menu              |');
   WriteLinha('*---------------------------------*');
 ELSIF (num=6) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=7) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| (1) Salvar inclusão       (2) Voltar ao menu                 |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=8) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=9) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| (1) Salvar alteração      (2) Voltar ao menu                 |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=10) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| Certeza de excluir? (S/N)                                    |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=11) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| Deseja sair do sistema? (S/N)                                |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=12) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=13) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| Deseja continuar? (S/N)                                      |');
   WriteLinha('*--------------------------------------------------------------*');
 ELSIF (num=14) THEN 
   WriteLinha('*--------------------------------------------------------------*');
   WriteLinha('| Salvar inclusão (S/N)                                        |');
   WriteLinha('*--------------------------------------------------------------*');
 END;
 WriteString(MSG_OPCAO);
 CloseInput();
END menu;
(*------------------------------------------------------------------------------
Indica se continua ou não mostrando um número máximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou não
------------------------------------------------------------------------------*)
PROCEDURE ContinuaSN(nlinha, nQtdLinha: CARDINAL): BOOLEAN;
VAR bSOp, bret : BOOLEAN;
    opCSubMenu: CHAR;
BEGIN
bret:=FALSE;
IF nlinha > 0 THEN 
  IF (nlinha MOD nQtdLinha) = 0 THEN 
    bSOp:=TRUE;
    WHILE(bSOp) DO 
       menu(13);
       Read(opCSubMenu);
       IF (opCSubMenu='S') OR (opCSubMenu='s') THEN bSOp:=FALSE;
       ELSIF (opCSubMenu='N') OR (opCSubMenu='n') THEN 
          bret:=TRUE;
          bSOp:=FALSE;
       ELSE WriteLinha(MSG_ERRO);
       END;  
    END;
  END;
END;

RETURN bret;
END ContinuaSN;
(*------------------------------------------------------------------------------
Lista vários registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se encontrou algum registro
------------------------------------------------------------------------------*)
PROCEDURE ListarTodos(VAR sArq: File; sreg: ctArqs; sChave: String;
   nPosChave, nTamChave, nTamLinha, nQtdLinha: CARDINAL;
   bPesqRelativa: BOOLEAN): BOOLEAN;
VAR slinha: String;
    bQuebra, bAchou, bRet: BOOLEAN;
    nCont, ntam: CARDINAL;
    sres: String;
BEGIN
bRet:=FALSE;
bQuebra:=FALSE;
nCont:=0;
mostrarDados(sreg, '', 2);
ntam:=tamArq(sArq);
SetPos(sArq, 0);
WHILE (NOT fimArq(sArq, ntam)) AND (bQuebra=FALSE) DO 
  slinha:=lerArq(sArq, nTamLinha, TAM_CRLF);
  IF NOT fimArq(sArq, ntam) THEN
    IF bPesqRelativa THEN 
      sres:=trim(copy(slinha,nPosChave,nTamChave));
      IF strRelativa(sres,sChave) THEN 
         bAchou:=TRUE;
         bRet:=TRUE;
      ELSE
         bAchou:=FALSE;
      END;
    ELSE 
      bAchou:=TRUE;
      bRet:=TRUE;
    END;
  
    IF bAchou THEN 
      mostrarDados(sreg, copy(slinha,1,nTamLinha), 3);
      nCont:=nCont+1;
    END;
  END;
  bQuebra:=ContinuaSN(nCont, nQtdLinha);
END;
RETURN bRet;
END ListarTodos;
(*------------------------------------------------------------------------------
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
------------------------------------------------------------------------------*)
PROCEDURE ListarRegLigados(VAR sArq1: File; sreg1: ctArqs; nPosChave1,
nTamChave1, nPosChave2, nTamChave2: CARDINAL; sChave: String;
VAR sArq2: File; sreg2: ctArqs; nPosChave3, nQtdLinha: CARDINAL);
VAR slinha1: String;
    bQuebra, bRet: BOOLEAN;
    nCont, ntam: CARDINAL;
    sCodigo1, sCodigo2, slinha2: String;
BEGIN
bRet:=FALSE;
nCont:=0;
bQuebra:=FALSE;
mostrarDados(sreg2, '', 2);
ntam:=tamArq(sArq1);
SetPos(sArq1, 0);
WHILE (NOT fimArq(sArq1, ntam)) AND (bQuebra=FALSE) DO 
  slinha1:=lerArq(sArq1, tamReg(sreg1), TAM_CRLF);
  IF NOT fimArq(sArq1, ntam) THEN
    sCodigo1:=trim(copy(slinha1,nPosChave1,nTamChave1));
    IF Compare(sCodigo1,sChave)=equal THEN 
      sCodigo2:=trim(copy(slinha1,nPosChave2,nTamChave2));
      slinha2:=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
      mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
      bRet:=TRUE;
      nCont:=nCont+1;
    END;
  END;
  bQuebra:=ContinuaSN(nCont, nQtdLinha);
END;
IF bRet=FALSE THEN
   WriteLinha(rotulo(sreg2,0));
END;
END ListarRegLigados;
(*------------------------------------------------------------------------------
Valida a entrada de registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
nTexto - o numero do rótulo da entrada
sEntrada - a chave a ser pesquisada e validada
nTentativas - o número máximo de tentativas
bPesqRelativa - indica se vai realizar uma pesquisa relativa
bTipoEntrada - indica o tipo de entrada
retorna - o registro pesquisado e validado
------------------------------------------------------------------------------*)
PROCEDURE validaEntrada(VAR sArq: File; sreg: ctArqs; nTexto: CARDINAL;
        sEntrada: String; nTentativas: CARDINAL;
        bPesqRelativa: BOOLEAN; bTipoEntrada: ctTipo): String;
VAR bQuebra: BOOLEAN;
    sres, sTexto, sMsgErro: String;
    ncont, nPosChave, nTamChave, nTamLinha: CARDINAL;
BEGIN
nTamLinha:=tamReg(sreg);
sMsgErro:=rotulo(sreg,0);
sTexto:=rotulo(sreg,nTexto);
nPosChave:=g_nPosChave;
nTamChave:=g_nTamChave;

ncont:=1;
bQuebra:=FALSE;
  WHILE (bQuebra=FALSE) AND (ncont <= nTentativas ) DO 
    IF bTipoEntrada=opTexto THEN 
      WriteString(sTexto);
      ReadLinha(sEntrada);
    ELSIF bTipoEntrada=opNumero THEN
       sEntrada:=validaNumero(sTexto,sEntrada);
    ELSIF bTipoEntrada=opData THEN
       sEntrada:=validaDataHora(sTexto,sEntrada,TRUE);
    ELSIF bTipoEntrada=opDataHora THEN
       sEntrada:=validaDataHora(sTexto,sEntrada,FALSE);
    ELSIF bTipoEntrada=opSenha THEN 
       sEntrada:=digitaSenha(sTexto, 10);
    END;

    IF bPesqRelativa THEN 
       IF ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha,
          QTD_MAX_LINHA, TRUE) THEN
          sres:=' '; 
       END;
    ELSE
       sres:=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha);
    END;  

    IF Compare(sres,'')=equal THEN
       WriteLinha(sMsgErro);
    ELSE
       bQuebra:=TRUE;
    END;
    ncont:=ncont+1;
  END;
RETURN sres;
END validaEntrada;
(*------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------*)
PROCEDURE mostrarDados(sreg: ctArqs; slinha: String; nOpcao: INTEGER);
BEGIN
IF sreg=opAssunto THEN 
   CASE nOpcao OF
   | 1: WriteLinha(Ss(rotulo(sreg, 1), tAssunto.codigo));
        WriteString(rotulo(sreg, 2));
        ReadLinha(tAssunto.assunto);
   | 2: WriteLinha('Código     Assunto');
        WriteLinha('------     -------');
   | 3: tAssunto.codigo:=copy(slinha, 1, 10);
        tAssunto.assunto:=copy(slinha, 11, 30);        
        WriteLinha(Ss(Ss(tAssunto.codigo,' '),tAssunto.assunto));
   END;
ELSIF sreg=opAutor THEN 
   CASE nOpcao OF
   | 1: WriteLinha(Ss(rotulo(sreg, 1), tAutor.codigo));
        WriteString(rotulo(sreg, 2));
        ReadLinha(tAutor.autor);
   | 2: WriteLinha('Código     Autor');
        WriteLinha('------     -----');
   | 3: tAutor.codigo:=copy(slinha, 1, 10);
        tAutor.autor:=copy(slinha, 11, 30);
        WriteLinha(Ss(Ss(tAutor.codigo,' '),tAutor.autor));
   END;
ELSIF sreg=opEditora THEN 
   CASE nOpcao OF
   | 1: WriteLinha(Ss(rotulo(sreg, 1), tEditora.codigo));
        WriteString(rotulo(sreg, 2));
        ReadLinha(tEditora.editora);
   | 2: WriteLinha('Código     Editora');
        WriteLinha('------     -------');
   | 3: tEditora.codigo:=copy(slinha, 1, 10);
        tEditora.editora:=copy(slinha, 11, 50);
        WriteLinha(Ss(Ss(tEditora.codigo,' '),tEditora.editora));
   END;
ELSIF sreg=opEndereco THEN 
   CASE nOpcao OF
   | 1: WriteLinha(Ss(rotulo(sreg, 1), tEndereco.codigo));
        WriteString(rotulo(sreg, 2));
        ReadLinha(tEndereco.logradouro);
        WriteString(rotulo(sreg, 3));
        ReadLinha(tEndereco.bairro);
        WriteString(rotulo(sreg, 4));
        ReadLinha(tEndereco.cep);
        WriteString(rotulo(sreg, 5));
        ReadLinha(tEndereco.cidade);
        WriteString(rotulo(sreg, 6));
        ReadLinha(tEndereco.estado);
   | 3: tEndereco.codigo:=trim(copy(slinha, 1, 10));
        tEndereco.logradouro:=trim(copy(slinha, 11, 40));
        tEndereco.bairro:=trim(copy(slinha, 51, 15));
        tEndereco.cep:=trim(copy(slinha, 66, 8));
        tEndereco.cidade:=trim(copy(slinha, 74, 30));
        tEndereco.estado:=trim(copy(slinha, 104, 20));
        WriteLinha('--------------------');
        WriteLinha(Ss(rotulo(sreg, 1), tEndereco.codigo));
        WriteLinha(Ss(rotulo(sreg, 2), tEndereco.logradouro));
        WriteLinha(Ss(rotulo(sreg, 3), tEndereco.bairro));
        WriteLinha(Ss(rotulo(sreg, 4), tEndereco.cep));
        WriteLinha(Ss(rotulo(sreg, 5), tEndereco.cidade));
        WriteLinha(Ss(rotulo(sreg, 6), tEndereco.estado));
   END;
ELSIF sreg=opIdioma THEN 
   CASE nOpcao OF
   | 1: WriteLinha(Ss(rotulo(sreg, 1), tIdioma.codigo));
        WriteString(rotulo(sreg, 2));
        ReadLinha(tIdioma.idioma);
   | 2: WriteLinha('Código     Idioma');
        WriteLinha('------     ------');
   | 3: tIdioma.codigo:=copy(slinha, 1, 10);
        tIdioma.idioma:=copy(slinha, 11, 20);
        WriteLinha(Ss(Ss(tIdioma.codigo,' '),tIdioma.idioma));
   END;
ELSIF sreg=opPais THEN 
   CASE nOpcao OF
   | 1: WriteString(rotulo(sreg, 2));
        ReadLinha(tPais.pais);
   | 2: WriteLinha('Código País');
        WriteLinha('------ ----');
   | 3: tPais.codigo:=copy(slinha, 1, 3);
        tPais.pais:=copy(slinha, 4, 50);
        WriteLinha(Ss(Ss(tPais.codigo,'    '),tPais.pais));
   END;
ELSIF sreg=opProfissao THEN 
   CASE nOpcao OF
   | 1: WriteLinha(Ss(rotulo(sreg, 1), tProfissao.codigo));
        WriteString(rotulo(sreg, 2));
        ReadLinha(tProfissao.profissao);
   | 2: WriteLinha('Código     Profissão');
        WriteLinha('------     ---------');
   | 3: tProfissao.codigo:=copy(slinha, 1, 10);
        tProfissao.profissao:=copy(slinha, 11, 50);
        WriteLinha(Ss(Ss(tProfissao.codigo,' '),tProfissao.profissao));
   END;
ELSIF sreg=opLivro THEN 
   CASE nOpcao OF
   | 1: WriteString(rotulo(sreg, 2));
        ReadLinha(tLivro.titulo);
        tLivro.edicao:=validaNumero(rotulo(sreg, 3), tLivro.edicao);
        tLivro.anopubli:=validaNumero(rotulo(sreg, 4), tLivro.anopubli);
        mostrarSubDados(opLivro, opEditora, FALSE);
        tLivro.volume:=validaNumero(rotulo(sreg, 6), tLivro.volume);
        mostrarSubDados(opLivro, opIdioma, FALSE);
        tLivro.npaginas:=validaNumero(rotulo(sreg, 8), tLivro.npaginas);
        tLivro.preco:=validaNumero(rotulo(sreg, 9), tLivro.preco);
        tLivro.qtdestoque:=validaNumero(rotulo(sreg, 10), tLivro.qtdestoque);
   | 3: tLivro.isbn:=trim(copy(slinha, 1, 13));
        tLivro.titulo:=trim(copy(slinha, 14, 50));
        tLivro.edicao:=trim(copy(slinha, 64, 10));
        tLivro.anopubli:=trim(copy(slinha, 74, 10));
        tLivro.codeditora:=trim(copy(slinha, 84, 10));
        tLivro.volume:=trim(copy(slinha, 94, 10));
        tLivro.codidioma:=trim(copy(slinha, 104, 10));
        tLivro.npaginas:=trim(copy(slinha, 114, 10));
        tLivro.preco:=trim(copy(slinha, 124, 10));
        tLivro.qtdestoque:=trim(copy(slinha, 134, 10));
        WriteLinha('--------------------');
        WriteLinha(Ss(rotulo(sreg, 1), tLivro.isbn));
        WriteLinha(Ss(rotulo(sreg, 2), tLivro.titulo));
        WriteLinha(Ss(rotulo(sreg, 3), tLivro.edicao));
        WriteLinha(Ss(rotulo(sreg, 4), tLivro.anopubli));
        WriteLinha(Ss(rotulo(sreg, 5), tLivro.codeditora));
        mostrarSubDados(opLivro, opEditora, TRUE);
        WriteLinha(Ss(rotulo(sreg, 6), tLivro.volume));
        WriteLinha(Ss(rotulo(sreg, 7), tLivro.codidioma));
        mostrarSubDados(opLivro, opIdioma, TRUE);
        WriteLinha(Ss(rotulo(sreg, 8), tLivro.npaginas));
        WriteLinha(Ss(rotulo(sreg, 9), tLivro.preco));
        WriteLinha(Ss(rotulo(sreg, 10), tLivro.qtdestoque));
        ListarRegLigados(tfLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
                         tfAssunto, opAssunto, 1, 4);
        ListarRegLigados(tfLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
                         tfAutor, opAutor, 1, 4);
   END;
ELSIF sreg=opCliente THEN 
   CASE nOpcao OF
   | 1: WriteString(rotulo(sreg, 2));
        ReadLinha(tCliente.nome);
        WriteString(rotulo(sreg, 3));
        ReadLinha(tCliente.email);
        WriteString(rotulo(sreg, 4));
        ReadLinha(tCliente.identidade);
        WriteString(rotulo(sreg, 5));
        ReadLinha(tCliente.sexo);
        WriteString(rotulo(sreg, 6));
        ReadLinha(tCliente.telefone);
        tCliente.dtnascimento:=
                validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, TRUE);
        mostrarSubDados(opCliente, opEndereco, FALSE);
        mostrarSubDados(opCliente, opPais, FALSE);
        mostrarSubDados(opCliente, opProfissao, FALSE);
   | 3: tCliente.cpf:=trim(copy(slinha, 1, 14));
        tCliente.nome:=trim(copy(slinha, 15, 30));
        tCliente.email:=trim(copy(slinha, 45, 30));
        tCliente.identidade:=trim(copy(slinha, 75, 10));
        tCliente.sexo:=trim(copy(slinha, 85, 1));
        tCliente.telefone:=trim(copy(slinha, 86, 17));
        tCliente.dtnascimento:=trim(copy(slinha, 103, 10));
        tCliente.codendereco:=trim(copy(slinha, 113, 10));
        tCliente.codpais:=trim(copy(slinha, 123, 3));
        tCliente.codprofissao:=trim(copy(slinha, 126, 10));
        WriteLinha('--------------------');
        WriteLinha(Ss(rotulo(sreg, 1), tCliente.cpf));
        WriteLinha(Ss(rotulo(sreg, 2), tCliente.nome));
        WriteLinha(Ss(rotulo(sreg, 3), tCliente.email));
        WriteLinha(Ss(rotulo(sreg, 4), tCliente.identidade));
        WriteLinha(Ss(rotulo(sreg, 5), tCliente.sexo));
        WriteLinha(Ss(rotulo(sreg, 6), tCliente.telefone));
        WriteLinha(Ss(rotulo(sreg, 7), tCliente.dtnascimento));
        WriteLinha(Ss(rotulo(sreg, 8), tCliente.codendereco));
        mostrarSubDados(opCliente, opEndereco, TRUE);
        WriteLinha(Ss(rotulo(sreg, 9), tCliente.codpais));
        mostrarSubDados(opCliente, opPais, TRUE);
        WriteLinha(Ss(rotulo(sreg, 10), tCliente.codprofissao));
        mostrarSubDados(opCliente, opProfissao, TRUE);
   END;
ELSIF sreg=opVenda THEN 
   CASE nOpcao OF
   | 1: mostrarSubDados(opVenda,opVenda, FALSE);
   | 2: WriteLinha('DataHoraVenda       CPF            ISBN          '+
        'PreçoVenda');
        WriteLinha('-------------       ---            ----          '+
        '----------');
   | 3: tVenda.dthrvenda:=copy(slinha, 1, 19);
        tVenda.cpf:=copy(slinha, 20, 14);
        tVenda.isbn:=copy(slinha, 34, 13);
        tVenda.precovenda:=copy(slinha, 47, 10);
        stemp[0]:=tVenda.dthrvenda;
        stemp[1]:=' ';
        stemp[2]:=tVenda.cpf;
        stemp[3]:=' ';
        stemp[4]:=tVenda.isbn;
        stemp[5]:=' ';
        stemp[6]:=tVenda.precovenda;
        WriteLinha(SomaStr(7,stemp));
   END;
END;

END mostrarDados;
(*------------------------------------------------------------------------------
Mostra as sub informções de entrada e de saída.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai só mostrar na saída 
------------------------------------------------------------------------------*)
PROCEDURE mostrarSubDados(sreg, ssubreg: ctArqs; bSoMostrar: BOOLEAN);
VAR sRegistro, sPreco: String;
    nStatus, nMaxTentativas: INTEGER;
BEGIN
nMaxTentativas:=3;
IF sreg=opLivro THEN 
  IF ssubreg=opEditora THEN 
    IF bSoMostrar THEN
       sRegistro:=pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg(opEditora));
    ELSE
       sRegistro:=validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,FALSE,opNumero);
    END;
    IF Compare(sRegistro,'')<>equal THEN 
      tLivro.codeditora:=trim(copy(sRegistro,1,10));
      WriteString(Ss(' ',rotulo(opEditora, 2)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
    END;
  ELSIF ssubreg=opIdioma THEN
    IF bSoMostrar THEN
       sRegistro:=pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg(opIdioma));
    ELSE
       sRegistro:=validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,FALSE,opNumero);
    END;
    IF Compare(sRegistro,'')<>equal THEN 
      tLivro.codidioma:=trim(copy(sRegistro,1,10));
      WriteString(Ss(' ',rotulo(opIdioma, 2)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
    END;
  END;
ELSIF sreg=opCliente THEN 
  IF ssubreg=opEndereco THEN 
    IF bSoMostrar THEN
       sRegistro:=pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
                  tamReg(opEndereco));
    ELSE
       sRegistro:=validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,FALSE,opNumero);
    END;
    IF Compare(sRegistro,'')<>equal THEN 
      tCliente.codendereco:=trim(copy(sRegistro,1,10));
      WriteString(Ss(' ',rotulo(opEndereco, 2)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
      WriteString(Ss(' ',rotulo(opEndereco, 3)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
      WriteString(Ss(' ',rotulo(opEndereco, 4)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
      WriteString(Ss(' ',rotulo(opEndereco, 5)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
      WriteString(Ss(' ',rotulo(opEndereco, 6)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
    END;
  ELSIF ssubreg=opPais THEN 
    IF bSoMostrar THEN
       sRegistro:=pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg(opPais));
    ELSE
       sRegistro:=validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,FALSE,opTexto);
    END;
    IF Compare(sRegistro,'')<>equal THEN 
      tCliente.codpais:=trim(copy(sRegistro,1,3));
      WriteString(Ss(' ',rotulo(opPais, 2)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
    END;
  ELSIF ssubreg=opProfissao THEN 
    IF bSoMostrar THEN
       sRegistro:=pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
                  tamReg(opProfissao));
    ELSE
       sRegistro:=validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,FALSE,opNumero);
    END;
    IF Compare(sRegistro,'')<>equal THEN 
      tCliente.codprofissao:=trim(copy(sRegistro,1,10));
      WriteString(Ss(' ',rotulo(opProfissao, 2)));
      WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
    END;
  END;
ELSIF sreg=opVenda THEN 
  sRegistro:=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
  IF Compare(sRegistro,'')<>equal THEN 
    WriteString(Ss(' ',rotulo(opLivro, 2))); (* Titulo *)
    WriteLinha(copy(sRegistro, g_nPosChave, g_nTamChave));
    WriteString(Ss(' ',rotulo(opLivro, 9))); (* Preco *)
    sPreco:=copy(sRegistro, g_nPosChave, g_nTamChave);
    GiveFloat(sPreco,g_nPreco,7,10,left);
    WriteLinha(sPreco);
  END;
END;
END mostrarSubDados;

(*------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*)
PROCEDURE btnAcao(sreg: ctArqs; sacao: ctAcao);
BEGIN
IF sreg=opAssunto THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfAssunto, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opAutor THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfAutor, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opEditora THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfEditora, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opEndereco THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfEndereco, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opIdioma THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfIdioma, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opPais THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfPais, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opProfissao THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfProfissao, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opLivro THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfLivro, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opLivroAss THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfLivroAss, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opLivroAut THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfLivroAut, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opCliente THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfCliente, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opVenda THEN 
   IF sacao=opSalvarInclusao THEN
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   ELSIF sacao=opSalvarAlteracao THEN
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   ELSIF sacao=opConfirmaExclusao THEN
      escreveArq(tfVenda, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   END;
ELSIF sreg=opUsuario THEN 
   IF sacao=opSalvarAlteracao THEN
      escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   END;
END;
END btnAcao;

(*------------------------------------------------------------------------------
Realiza a exclusão dos arquivos de ligação.
sArq - o arquivo de ligação
sreg - o tipo de arquivo de ligação
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------*)
PROCEDURE ExcluirRegLigados(VAR sArq: File; sreg: ctArqs; nPosChave,
nTamChave: INTEGER; sChave: String);
VAR slinha, sCodigo: String;
    ntam: CARDINAL;    
BEGIN
  ntam:=tamArq(sArq);
  SetPos(sArq, 0);
  WHILE (NOT fimArq(sArq, ntam)) DO 
    slinha:=lerArq(sArq, tamReg(sreg), TAM_CRLF);
    IF NOT fimArq(sArq, ntam) THEN
      sCodigo:=trim(copy(slinha,nPosChave,nTamChave));
      IF Compare(sCodigo,sChave)=equal THEN
         btnAcao(sreg,opConfirmaExclusao);
      END;
    END;
  END;
END ExcluirRegLigados;

END Sistema.
