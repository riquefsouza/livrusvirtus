(*------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem modula 2.
------------------------------------------------------------------------------*)
MODULE livrus;

FROM Rotinas IMPORT String, WriteLinha, equal;
FROM Arquivos IMPORT abrecriaArqs, fechaArqs;
FROM Sistema IMPORT MSG_ERRO, menu;
FROM Telas IMPORT frmSplash, frmLogin, usaMenu;
FROM System IMPORT GetArg;
FROM Strings IMPORT CompareStr;
FROM InOut IMPORT Read;

VAR
 bopcao: BOOLEAN;
 opmenu: CHAR;
 sparam: String;
 nargs: CARDINAL;

(*------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------*)
BEGIN
 GetArg(sparam,nargs);
 IF CompareStr(sparam,'-cria')=equal THEN
    abrecriaArqs(FALSE)
 ELSE
   frmSplash();
   abrecriaArqs(TRUE);
   IF frmLogin() THEN 
     bopcao:=TRUE;
     WHILE(bopcao) DO 
       menu(1);
       Read(opmenu);
       IF (opmenu='C') OR (opmenu='c') THEN usaMenu(1);
       ELSIF (opmenu='P') OR (opmenu='p') THEN usaMenu(2);
       ELSIF (opmenu='V') OR (opmenu='v') THEN usaMenu(3);
       ELSIF (opmenu='O') OR (opmenu='o') THEN usaMenu(4);
       ELSE WriteLinha(MSG_ERRO);
       END;
     END;  
   ELSE 
     fechaArqs();
     HALT;
   END;
 END;

END livrus.
