IMPLEMENTATION MODULE Telas;

FROM Rotinas IMPORT String, WriteLinha, ReadLinha, Ss,
copy, trim, esp, validaCPF, validaISBN, digitaSenha, validaNumero, 
retDataHora, equal;
FROM Arquivos IMPORT tfAssunto, tfAutor, tfEditora, 
tfIdioma, tfEndereco, tfPais, tfProfissao, tfLivro, tfLivroAss, 
tfLivroAut, tfCliente, tfUsuario, tfVenda,
tAssunto, tAutor, tEditora, tIdioma, tEndereco, tPais, 
tProfissao, tLivro, tLivroAss, tLivroAut, tCliente, tUsuario, tVenda,
fechaArqs, pesqArq, pesqLinhaExcluida, pesqMaxCod, escreveArq,
ctArqs, ctAcao, ctTipo, tamReg;
FROM Sistema IMPORT QTD_MAX_LINHA, MSG_ERRO, 
g_nPosChave, g_nTamChave, g_nPreco, rotulo, menu, 
ListarTodos, validaEntrada, mostrarDados, btnAcao, ExcluirRegLigados;

FROM NumberConversion IMPORT StringToCard, CardToString;
FROM Strings IMPORT Length, CompareStr;
FROM RealConversions IMPORT RealToString;
FROM FileSystem IMPORT SetPos;
FROM InOut IMPORT Read, ReadLine, WriteLn, ReadInt, WriteString;

(*------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------*)
PROCEDURE frmSplash();
VAR cont: CARDINAL;
    clocal: CHAR;
BEGIN
 WriteLinha('*----------------------------------------------------------------------------*');
 WriteLinha('| LL    II VV   VV RRRRR  UU  UU   SSSS VV   VV II RRRRR  TTTT UU  UU   SSSS |');
 WriteLinha('| LL    II  VV VV  RR   R UU  UU  SS     VV VV  II RR   R  TT  UU  UU  SS    |');
 WriteLinha('| LL    II   VVV   RRRRR  UU  UU    SS    VVV   II RRRRR   TT  UU  UU    SS  |');
 WriteLinha('| LLLLL II    V    RR   R  UUUU  SSSS      V    II RR   R  TT   UUUU  SSSS   |');
 WriteLinha('*----------------------------------------------------------------------------*');
 FOR cont:=1 TO 18 DO 
   WriteLn;
 END; 
 WriteString(MSG_PRESS);
 Read(clocal);
END frmSplash;
(*------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------*)
PROCEDURE frmSobre();
VAR cont: CARDINAL;
    clocal: CHAR;
BEGIN
 WriteLinha('*------------------------------------------------------------*');
 WriteLinha('|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |');
 WriteLinha('|  LL        II   VV     VV   RR     R  UU    UU  SS         |');
 WriteLinha('|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |');
 WriteLinha('|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |');
 WriteLinha('|  LLLL      II      VVV      RR RR     UU    UU        SS   |');
 WriteLinha('|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |');
 WriteLinha('|                                                            |');
 WriteLinha('|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |');
 WriteLinha('|   VV     VV   II  RR     R     TT     UU    UU  SS         |');
 WriteLinha('|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |');
 WriteLinha('|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |');
 WriteLinha('|      VVV      II  RR RR        TT     UU    UU        SS   |');
 WriteLinha('|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |');
 WriteLinha('|                                                            |');
 WriteLinha('|                                               Versao 1.0.0 |');
 WriteLinha('| Sistema integrante do projeto Livrus Virtus.               |');
 WriteLinha('| Todos os direitos reservados para Henrique F. de Souza.    |');
 WriteLinha('| Versao programada na linguagem modula 2.                   |');
 WriteLinha('*------------------------------------------------------------*');
 FOR cont:=1 TO 4 DO 
   WriteLn;
 END;
 WriteString(MSG_PRESS);
 Read(clocal);
END frmSobre;
(*------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------*)
PROCEDURE frmLogin(): BOOLEAN;
VAR bret: BOOLEAN;
    slinha: String;
BEGIN
  bret:=FALSE;
  WriteLinha('*--------------------------------------------------------------*');
  WriteLinha('| Login do sistema                                             |');
  WriteLinha('*--------------------------------------------------------------*');
  slinha:=validaEntrada(tfUsuario, opUsuario, 1, tUsuario.login, 3, FALSE, opTexto);
  IF CompareStr(slinha,'')<>equal THEN
     slinha:=validaEntrada(tfUsuario, opUsuario, 2, tUsuario.senha, 3,
        FALSE, opSenha);
     IF CompareStr(slinha,'')<>equal THEN
        tUsuario.login:=trim(copy(slinha, 1, 10));
        tUsuario.senha:=trim(copy(slinha, 11, 10));
        bret:=TRUE;
     END;
  END;
  WriteLn;
  RETURN bret;
END frmLogin;

(*------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*)
PROCEDURE frmCadastros(sreg: ctArqs; sacao: ctAcao);
VAR slinha: String;
BEGIN
IF sreg=opAssunto THEN 
   IF sacao=opNovo THEN 
      tAssunto.codigo:=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   ELSIF sacao=opPesquisar THEN 
     slinha:=validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,FALSE,opNumero);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opAutor THEN 
   IF sacao=opNovo THEN 
      tAutor.codigo:=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,FALSE,opNumero);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opEditora THEN 
   IF sacao=opNovo THEN 
      tEditora.codigo:=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   ELSIF sacao=opPesquisar THEN 
     slinha:=validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,FALSE,opNumero);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opEndereco THEN 
   IF sacao=opNovo THEN 
      tEndereco.codigo:=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
              FALSE,opNumero);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opIdioma THEN 
   IF sacao=opNovo THEN 
      tIdioma.codigo:=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,FALSE,opNumero);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opPais THEN 
   IF sacao=opNovo THEN 
      WriteString(rotulo(sreg, 1));
      ReadLinha(tPais.codigo);
      slinha:=pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg));
      IF CompareStr(slinha,'')=equal THEN
         pesqLinhaExcluida(tfPais, tamReg(sreg));
         mostrarDados(sreg, '', 1);
         subMenu(7, sreg);
      ELSE WriteLinha(MSG_REGEXST);
      END;
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, FALSE, opTexto);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      WriteLinha(Ss(rotulo(sreg, 1), tPais.codigo));
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opProfissao THEN 
   IF sacao=opNovo THEN 
      tProfissao.codigo:=pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
              FALSE,opNumero);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opLivro THEN 
   IF sacao=opNovo THEN 
      WriteString(rotulo(sreg, 1));
      ReadLinha(tLivro.isbn);
      IF validaISBN(tLivro.isbn) THEN 
          slinha:=pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg));
          IF CompareStr(slinha,'')=equal THEN
             pesqLinhaExcluida(tfLivro, tamReg(sreg));
             mostrarDados(sreg, '', 1);
             subMenu(7, sreg);
             frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
             frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
          ELSE WriteLinha(MSG_REGEXST);
          END; 
      ELSE WriteLinha(MSG_ISBNINV);
      END;
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,FALSE,opTexto);
      IF CompareStr(slinha,'')<>equal THEN
         mostrarDados(sreg, '', 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      WriteLinha(Ss(rotulo(sreg, 1), tLivro.isbn));
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      WriteLinha('Assuntos dos livros excluídos, inclua novos!');
      frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
      WriteLinha('Autores dos livros excluídos, inclua novos!');
      frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
      WriteLinha('Assuntos dos livros sendo excluídos!');
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      WriteLinha('Autores dos livros sendo excluídos!');
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
   END;
ELSIF sreg=opCliente THEN 
   IF sacao=opNovo THEN 
      WriteString(rotulo(sreg, 1));
      ReadLinha(tCliente.cpf);
      IF validaCPF(tCliente.cpf) THEN 
          slinha:=pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg));
          IF CompareStr(slinha,'')=equal THEN
             pesqLinhaExcluida(tfCliente, tamReg(sreg));
             mostrarDados(sreg, '', 1);
             subMenu(7, sreg);
          ELSE WriteLinha(MSG_REGEXST);
          END;
      ELSE WriteLinha(MSG_CPFINV);
      END;
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,FALSE,opTexto);
      IF CompareStr(slinha,'')<>equal THEN
         mostrarDados(sreg, '', 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      END;
   ELSIF sacao=opAlterar THEN 
      WriteLinha(Ss(rotulo(sreg, 1), tCliente.cpf));
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   ELSIF sacao=opExcluir THEN 
      subMenu(10, sreg);
   END;
ELSIF sreg=opVenda THEN 
   IF sacao=opNovo THEN 
      tVenda.dthrvenda:=retDataHora();
      WriteLinha(Ss(rotulo(sreg, 1), tVenda.dthrvenda));
      slinha:=pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
      IF CompareStr(slinha,'')=equal THEN
         slinha:=validaEntrada(tfCliente,opCliente,1,tVenda.cpf,3,
                 FALSE,opTexto);
         IF CompareStr(slinha,'')<>equal THEN
            tVenda.cpf:=trim(copy(slinha,1,14));
            IF validaCPF(tVenda.cpf) THEN 
               WriteString(Ss(' ',rotulo(opCliente, 2))); (* Nome *)
               WriteLinha(copy(slinha, g_nPosChave, g_nTamChave));
               frmCadLigados(opVenda, opNovo, tVenda.cpf);
            ELSE WriteLinha(MSG_CPFINV);
            END; 
         END;
      ELSE WriteLinha(MSG_REGEXST);
      END;
   ELSIF sacao=opPesquisar THEN 
      slinha:=validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
              FALSE,opDataHora);
      IF CompareStr(slinha,'')<>equal THEN
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      END;
   END;
END;

END frmCadastros;
(*------------------------------------------------------------------------------
Realiza as consultas de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------*)
PROCEDURE frmConsultas(sreg: ctArqs; sacao: ctAcao);
VAR slinha: String;
BEGIN
IF sreg=opAssunto THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfAssunto, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opAutor THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfAutor, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opEditora THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfEditora,sreg,2,tEditora.editora,1,TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfEditora, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opEndereco THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfEndereco,sreg,2,tEndereco.logradouro,1,
              TRUE,opTexto);
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfEndereco, sreg, '', 0, 0, tamReg(sreg),
         3, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opIdioma THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfIdioma, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opPais THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfPais, sreg, 2, tPais.pais, 1, TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfPais, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opProfissao THEN 
   IF sacao=opPesquisar THEN
     slinha:=validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfProfissao, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opLivro THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfLivro, sreg, '', 0, 0, tamReg(sreg),
        1, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opCliente THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfCliente, sreg, '', 0, 0, tamReg(sreg),
        1, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
ELSIF sreg=opVenda THEN 
   IF sacao=opPesquisar THEN
      slinha:=validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, TRUE,opTexto)
   ELSIF sacao=opListarTodos THEN 
      IF ListarTodos(tfVenda, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, FALSE) = FALSE THEN
        WriteLinha(rotulo(sreg, 0));
      END;
   END;
END;
IF CompareStr(slinha,'')=equal THEN
   WriteString('');
END;
END frmConsultas;
(*------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------*)
PROCEDURE frmAlterarSenha;
VAR bQuebra: BOOLEAN;
    sres, sSenhaAtual, sNovaSenha, sConfirmaSenha: String;
    nopcao: INTEGER;
BEGIN
WriteLinha(Ss(rotulo(opUsuario, 1), tUsuario.login));
nopcao:=1;
bQuebra:=FALSE;
WHILE (bQuebra=FALSE) DO 
  CASE nopcao OF
  | 1: sSenhaAtual:=digitaSenha('Senha Atual: ',10);
       IF CompareStr(sSenhaAtual,tUsuario.senha)<>equal THEN
          WriteLinha(MSG_SENCONFERE);
          bQuebra:=TRUE;
       ELSE nopcao:=2;
       END;
  | 2: sNovaSenha:=digitaSenha('Nova Senha: ',10);
       sConfirmaSenha:=digitaSenha('Confirma Senha: ',10);
       IF CompareStr(sNovaSenha,sConfirmaSenha)<>equal THEN
          WriteLinha(MSG_SENCONFIRM);
          bQuebra:=TRUE;
       ELSE nopcao:=3;
       END;
  | 3: sres:=pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg(opUsuario));
       IF CompareStr(sres,'')=equal THEN
         WriteLinha(MSG_LOGINENCON)
       ELSE 
         tUsuario.senha:=sConfirmaSenha;
         subMenu(9,opUsuario);
         bQuebra:=TRUE;
       END;
  END;
END;

END frmAlterarSenha;
(*------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------*)
PROCEDURE subMenu(nmenu: INTEGER; sreg: ctArqs);
VAR opSubMenu: INTEGER;
    opCSubMenu: CHAR;
    bSOp: BOOLEAN;
BEGIN
bSOp:=TRUE;
CASE nmenu OF
| 6: WHILE(bSOp) DO 
       menu(nmenu);
       ReadInt(opSubMenu);
       CASE(opSubMenu) OF
        | 1: frmCadastros(sreg, opNovo);
        | 2: frmCadastros(sreg, opPesquisar);
        | 3: bSOp:=FALSE;
        ELSE WriteLinha(MSG_ERRO);
       END;
     END;
| 7: WHILE(bSOp) DO 
       menu(nmenu);
       ReadInt(opSubMenu);
       CASE(opSubMenu) OF
       | 1:  btnAcao(sreg, opSalvarInclusao); bSOp:=FALSE;
       | 2: bSOp:=FALSE;
       ELSE WriteLinha(MSG_ERRO);
       END;
     END;
| 8: WHILE(bSOp) DO 
       menu(nmenu);
       ReadInt(opSubMenu);
       CASE(opSubMenu) OF
        | 1:  frmCadastros(sreg, opAlterar); bSOp:=FALSE;
        | 2:  frmCadastros(sreg, opExcluir); bSOp:=FALSE;
        | 3: bSOp:=FALSE;
        ELSE WriteLinha(MSG_ERRO);
       END;
     END;
| 9: WHILE(bSOp) DO 
       menu(nmenu);
       ReadInt(opSubMenu);
       CASE(opSubMenu) OF
        | 1:  btnAcao(sreg, opSalvarAlteracao); bSOp:=FALSE;
        | 2: bSOp:=FALSE;
        ELSE WriteLinha(MSG_ERRO);
       END;
     END;
| 10: WHILE(bSOp) DO 
        menu(nmenu);
        Read(opCSubMenu);
        IF (opCSubMenu='S') OR (opCSubMenu='s') THEN 
          btnAcao(sreg, opConfirmaExclusao);
          bSOp:=FALSE;
        ELSIF (opCSubMenu='N') OR (opCSubMenu='n') THEN bSOp:=FALSE;
        ELSE WriteLinha(MSG_ERRO);
        END;
      END;
| 12: WHILE(bSOp) DO 
        menu(nmenu);
        ReadInt(opSubMenu);
        CASE(opSubMenu) OF
        | 1: frmConsultas(sreg, opPesquisar);
        | 2: frmConsultas(sreg, opListarTodos);
        | 3: bSOp:=FALSE;
        ELSE WriteLinha(MSG_ERRO);
        END;
      END;
| 14: WHILE(bSOp) DO 
        menu(nmenu);
        Read(opCSubMenu);
        IF (opCSubMenu='S') OR (opCSubMenu='s') THEN 
          btnAcao(sreg, opSalvarInclusao);
          bSOp:=FALSE;
          g_SalvarInclusao:=TRUE;
        ELSIF (opCSubMenu='N') OR (opCSubMenu='n') THEN bSOp:=FALSE;
        ELSE WriteLinha(MSG_ERRO);
        END;
      END;
END;

END subMenu;
(*------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------*)
PROCEDURE usaMenu(num: INTEGER);
VAR opSubMenu: INTEGER;
    bSOp: BOOLEAN;
    opSair: CHAR;
BEGIN
 bSOp:=TRUE;
 IF num = 1 THEN  (* Cadastros *)
   WHILE(bSOp) DO 
     menu(2);
     ReadInt(opSubMenu);
     CASE opSubMenu OF
      | 1: subMenu(6, opAssunto);
      | 2: subMenu(6, opAutor);
      | 3: subMenu(6, opEditora);
      | 4: subMenu(6, opEndereco);
      | 5: subMenu(6, opIdioma);
      | 6: subMenu(6, opPais);
      | 7: subMenu(6, opProfissao);
      | 8: subMenu(6, opCliente);
      | 9: subMenu(6, opLivro);
      | 10: bSOp:=FALSE;
      ELSE WriteLinha(MSG_ERRO);
     END;
   END;
 ELSIF num = 2 THEN  (* Pesquisas *)
   WHILE(bSOp) DO 
     menu(3);
     ReadInt(opSubMenu);
     CASE opSubMenu OF
      | 1: subMenu(12, opAssunto);
      | 2: subMenu(12, opAutor);
      | 3: subMenu(12, opEditora);
      | 4: subMenu(12, opEndereco);
      | 5: subMenu(12, opIdioma);
      | 6: subMenu(12, opPais);
      | 7: subMenu(12, opProfissao);
      | 8: subMenu(12, opCliente);
      | 9: subMenu(12, opLivro);
      | 10: bSOp:=FALSE;
      ELSE WriteLinha(MSG_ERRO);
     END;
   END;
 ELSIF num = 3 THEN  (* Vendas *)
   WHILE(bSOp) DO 
     menu(4);
     ReadInt(opSubMenu);
     CASE(opSubMenu) OF
      | 1: subMenu(6, opVenda);
      | 2: subMenu(12, opVenda);
      | 3: bSOp:=FALSE;
      ELSE WriteLinha(MSG_ERRO);
     END;
   END;
 ELSIF num = 4 THEN  (* Opcoes *)
   WHILE(bSOp) DO 
     menu(5);
     ReadInt(opSubMenu);
     CASE(opSubMenu) OF
      | 1: frmAlterarSenha;
      | 2: frmSobre;
      | 3: menu(11);
           Read(opSair);
           IF (opSair='S') OR (opSair='s') THEN 
              fechaArqs();
              HALT;
           END;
      | 4: bSOp:=FALSE;
      ELSE WriteLinha(MSG_ERRO);
     END;
   END;
 END;
END usaMenu;

(*------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------*)
PROCEDURE frmCadLigados(sreg: ctArqs; sacao: ctAcao; sCodigo: String);
VAR nQtd, nCont, nQtdEstoque: CARDINAL;
    nTotalPreco: REAL;
    slinha, sTotalPreco, sPreco, sQtd: String;
    bStatus: BOOLEAN;
BEGIN
IF sacao=opNovo THEN 
  nCont:=1;
  IF sreg=opLivroAss THEN 
    sQtd:=validaNumero('Quantos assuntos quer cadastrar?: ', sQtd);
    StringToCard(sQtd, nQtd, bStatus);
    SetPos(tfLivroAss, 0, 0);
    WHILE nCont <= nQtd DO 
      tLivroAss.isbn:=sCodigo;
      WriteString(rotulo(opLivroAss, 2));
      ReadLinha(tLivroAss.codassunto);
      slinha:=pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg(opAssunto));
      WriteString(Ss(' ',rotulo(opAssunto, 2)));
      WriteLinha(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
      subMenu(14, sreg);
      nCont:=nCont+1;
    END;
  ELSIF sreg=opLivroAut THEN 
    sQtd:=validaNumero('Quantos autores quer cadastrar?: ',sQtd);
    StringToCard(sQtd, nQtd, bStatus);
    SetPos(tfLivroAut, 0, 0);
    WHILE nCont <= nQtd DO 
      tLivroAut.isbn:=sCodigo;
      WriteString(rotulo(opLivroAut, 2));
      ReadLinha(tLivroAut.codautor);
      slinha:=pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg(opAutor));
      WriteString(Ss(' ',rotulo(opAutor, 2)));
      WriteLinha(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
      subMenu(14, sreg);
      nCont:=nCont+1;
    END;
  ELSIF sreg=opVenda THEN 
    sQtd:=validaNumero('Quantos livros quer vender?: ',sQtd);
    StringToCard(sQtd, nQtd, bStatus);
    nTotalPreco:=0.0;
    WHILE nCont <= nQtd DO 
      slinha:=validaEntrada(tfLivro,opLivro,1,tVenda.isbn,3,FALSE,opTexto);
      IF CompareStr(slinha,'')<>equal THEN
        tVenda.isbn:=trim(copy(slinha,1,13));
        IF validaISBN(tVenda.isbn) THEN 
          mostrarDados(sreg, '', 1);
          tLivro.qtdestoque:=trim(copy(slinha,134,10));
          StringToCard(tLivro.qtdestoque, nQtdEstoque, bStatus);
          IF nQtdEstoque > 0 THEN 
             nTotalPreco:=nTotalPreco + g_nPreco;
             RealToString(g_nPreco,7,2,sPreco,bStatus);
             tVenda.precovenda:=sPreco;
             g_SalvarInclusao:=FALSE;
             subMenu(14, sreg);
             IF g_SalvarInclusao THEN 
                slinha:=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
                IF CompareStr(slinha,'')<>equal THEN
                   nQtdEstoque:=nQtdEstoque-1;
                   CardToString(nQtdEstoque,tLivro.qtdestoque,7);
                   slinha:=Ss(copy(slinha,1,133),esp(tLivro.qtdestoque,10));
                   escreveArq(tfLivro, slinha, '', '');
                END;
             END;
             nCont:=nCont+1;
          ELSE WriteLinha(MSG_SEMESTOQUE);
          END;
        ELSE WriteLinha(MSG_ISBNINV);
        END; 
      END;
    END;
    RealToString(nTotalPreco, 7, 2,sTotalPreco, bStatus);
    WriteLinha(Ss(Ss('Total de ',rotulo(sreg,4)),sTotalPreco));
  END;
ELSIF sacao=opExcluir THEN 
  IF sreg=opLivroAss THEN 
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo);
  ELSIF sreg=opLivroAut THEN 
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo);
  END;
END;

END frmCadLigados;

END Telas.
