IMPLEMENTATION MODULE Rotinas;

FROM CardStr IMPORT Value, Alignment;
FROM RealStr IMPORT Take, ConvResults; 
FROM Ascii IMPORT lf, cr, nul;
FROM AsciiTime IMPORT StructTimeToAscii; 
FROM StdStrings IMPORT String, Length, Append, 
Extract, Compare, CompareResult;
FROM Terminal IMPORT WriteString, GetKeyStroke;
FROM SysClock IMPORT GetClock, DateTime;
FROM InOut IMPORT Read, WriteLn;

(*------------------------------------------------------------------------------
Escreve uma linha na tela com retorno de carro.
sTexto - o texto a ser escrito
------------------------------------------------------------------------------*)
PROCEDURE WriteLinha(sTexto: ARRAY OF CHAR);
BEGIN
WriteString(sTexto); 
WriteLn;
END WriteLinha;

(*------------------------------------------------------------------------------
Le uma linha do prompt, foi necessário para pegar strings com espaço em branco.
sTexto - o texto a ser lido
------------------------------------------------------------------------------*)
PROCEDURE ReadLinha(VAR sTexto: ARRAY OF CHAR);
VAR sLetra: CHAR;
    ncont: CARDINAL;
BEGIN
  ncont:=0;
  sLetra:=nul;
  WHILE (sLetra<>lf) DO 
    Read(sLetra);
    IF (sLetra<>lf) OR (sLetra<>cr) THEN
       sTexto[ncont]:=sLetra;
       ncont:=ncont+1;
    END;
  END;
  sTexto[ncont-1]:=nul;
END ReadLinha;

(*------------------------------------------------------------------------------
função que concatena strings e retorna o resultado
str1 - indica a string1
str2 - indica a string2
retorna - as strings concatenadas
------------------------------------------------------------------------------*)
PROCEDURE Ss(str1,str2:ARRAY OF CHAR):String;
VAR str3:String;
BEGIN
 str3[0]:=nul;
 Append(str1,str3);
 Append(str2,str3);
 RETURN(str3);
END Ss;

(*------------------------------------------------------------------------------
Função que soma determinado número de strings.
num - indica o número de strings
strs - as strings a serem somadas
retorna - as strings somadas
------------------------------------------------------------------------------*)
PROCEDURE SomaStr(num: CARDINAL; strs: ARRAY OF String): String;
VAR str1: String; 
    cont: CARDINAL;
BEGIN
 str1[0]:=nul;
 FOR cont:=0 TO num-1 DO  
   Append(strs[cont],str1);
 END;  
 RETURN(str1);
END SomaStr;

(*------------------------------------------------------------------------------
Função que retorna um pedaço de uma string.
str - indica a string
ini - indica a posicao inicial do pedaco
tam - indica o tamanho do pedaco
retorna - o pedaço da string
------------------------------------------------------------------------------*)
PROCEDURE copy(str: String; ini,tam: CARDINAL): String;
VAR str1: String;
BEGIN
ini:=ini-1;
Extract(str,ini,tam,str1);
RETURN str1;
END copy;

(*------------------------------------------------------------------------------
Retira os espaços em branco antes ou depois do texto.
sTexto - o texto a ser retirado os espaços em branco
retorna - o texto sem os espaços em branco
------------------------------------------------------------------------------*)
PROCEDURE trim(sTexto: String): String;
VAR ncont, nPosIni, nPosFim: CARDINAL;
    sret: String;
    bQuebra: BOOLEAN;
BEGIN
IF Length(sTexto) > 1 THEN
  nPosIni:=0;
  nPosFim:=0;
  ncont:=0;
  bQuebra:=FALSE;
  WHILE (ncont<=(Length(sTexto)-1)) AND (bQuebra=FALSE) DO
    IF sTexto[ncont]<>' ' THEN
       nPosIni:=ncont;
       bQuebra:=TRUE;
    END;
    ncont:=ncont+1;
  END;
  ncont:=Length(sTexto)-1;
  bQuebra:=FALSE;
  WHILE (ncont > 0) AND (bQuebra=FALSE) DO 
    IF sTexto[ncont]<>' ' THEN 
       nPosFim:=ncont;
       bQuebra:=TRUE;
    END;  
    ncont:=ncont-1;
  END;
  sret:=copy(sTexto,nPosIni+1,(nPosFim-nPosIni)+1);
ELSE
 IF Compare(sTexto,' ')=equal THEN
    sret:='';
 ELSE
    sret:=sTexto;
 END;
END;
RETURN sret;
END trim;

(*------------------------------------------------------------------------------
Repete um texto um número determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------*)
PROCEDURE repete(sTexto: String; nQtd: INTEGER): String;
VAR ncont: INTEGER;
    sret: String;
BEGIN
sret:='';
FOR ncont:=1 TO nQtd DO 
    Append(sTexto, sret);
END;
RETURN sret;
END repete;
(*------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------*)
PROCEDURE esp(sTexto: String; nTam: CARDINAL):String;
VAR sret: String;
BEGIN
sret:=repete(' ',nTam-Length(sTexto));
Append(sret, sTexto);
RETURN sTexto;
END esp;
(*------------------------------------------------------------------------------
Escreve zeros na frente de um texto.
stexto - o texto para receber zeros a frente
ntam - o tamanho da string
retorna - o texto com o zeros antes
------------------------------------------------------------------------------*)
PROCEDURE zeros(stexto:String; ntam: CARDINAL): String;
VAR saux: String;
BEGIN  
  saux[0]:=nul;
  IF ntam > Length(stexto) THEN
     Append(repete('0',ntam - Length(stexto)), saux);
     Append(stexto, saux);
  ELSE
     saux:=stexto;
  END;
  RETURN saux;
END zeros;
(*------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------*)
PROCEDURE strRelativa(sTexto, sChave: String):BOOLEAN;
VAR nCont, nTamChave, nTamTexto: INTEGER;
    bret: BOOLEAN;
    sPedaco: String;
BEGIN
bret:=FALSE;
nCont:=1;
nTamChave:=Length(sChave);
nTamTexto:=Length(sTexto);
IF nTamChave <= nTamTexto THEN 
  WHILE nCont <= (nTamTexto-nTamChave+1) DO 
     sPedaco:=copy(sTexto,nCont,nTamChave);
     IF Compare(sPedaco,sChave)=equal THEN
        bret:=TRUE;
     END;
     nCont:=nCont+1;
  END;
END;
RETURN bret;
END strRelativa;
(*------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a String com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------*)
PROCEDURE modulo11(svalor: String; ndig: INTEGER): INTEGER;
VAR nsoma, nvalor, npos: INTEGER;
    ncont: CARDINAL; 
    sres, slocal: String;
BEGIN
 ncont:=1;
 WHILE ncont <= 11 DO
   slocal:=Ss(copy(svalor,ncont,1), slocal);
   ncont:=ncont+1;
 END;
 nsoma:=0;
 IF ndig=1 THEN
   ncont:=3
 ELSE
   ncont:=2;
 END;
 npos:=2;
 WHILE ncont <= 11 DO
   sres:=copy(slocal,ncont,1);
   nvalor:=Value(sres);
   nsoma:=nsoma + (nvalor * npos);
   ncont:=ncont+1;
   npos:=npos+1;
 END;
 nsoma:=(11 - (nsoma MOD 11));

 IF nsoma > 9 THEN
   RETURN 0
 ELSE
   RETURN nsoma;
 END;
END modulo11;
(*------------------------------------------------------------------------------
Validação de um número de CPF qualquer.
cpf - a String com o número do CPF
retorna - se é valido ou não
------------------------------------------------------------------------------*)
PROCEDURE validaCPF(cpf: String): BOOLEAN;
VAR scpf, sres: String;
    nvalor1, nvalor2: INTEGER;
BEGIN
IF (Length(cpf)=14) THEN   
  scpf:=Ss(Ss(Ss(copy(cpf,1,3),copy(cpf,5,3)),copy(cpf,9,3)),copy(cpf,13,2));
  sres:=copy(cpf,13,1);
  nvalor1:=Value(sres);
  sres:=copy(cpf,14,1);
  nvalor2:=Value(sres);
  IF ((modulo11(scpf,1)=nvalor1) AND (modulo11(scpf,2)=nvalor2)) THEN
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
ELSE
  RETURN FALSE;
END;
END validaCPF;
(*------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a String com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------*)
PROCEDURE validaISBN(isbn: String): BOOLEAN;
VAR sisbn, snum, sdigito: String;
    ncont, nvalor, nsoma: CARDINAL;
BEGIN
IF (Length(isbn)=13) THEN
  sdigito := copy(isbn, Length(isbn), 1);
  sisbn:='';
  FOR ncont:=1 TO Length(isbn)-1 DO
    IF (Compare(copy(isbn,ncont,1),'-')<>equal) THEN
      Append(copy(isbn,ncont,1), sisbn);
    END;
  END;
  IF Compare(sdigito, 'X')=equal THEN
    nsoma := 10
  ELSE
    nvalor:=Value(sdigito);
    nsoma := nvalor;
  END;
  FOR ncont:=1 TO 9 DO
    snum:=copy(sisbn, ncont, 1);
    nvalor:=Value(snum);
    nsoma:=nsoma + (nvalor * (11 - ncont));
  END;
  IF (nsoma MOD 11) = 0 THEN
    RETURN TRUE;
  ELSE
    RETURN FALSE;
  END;
ELSE
  RETURN FALSE;
END;
END validaISBN;
(*------------------------------------------------------------------------------
Esconde a digitação da senha
retorna - a senha digitada
------------------------------------------------------------------------------*)
PROCEDURE digitaSenha(sRotulo: String; nTamSenha: INTEGER): String;
VAR sSenha: String;
    sLetra: CHAR;
    ncont: INTEGER;
BEGIN
  WriteString(sRotulo);
  ncont := 0;
  sSenha:='';
  sLetra:=nul;
  WHILE ((sLetra<>lf) AND (ncont < nTamSenha)) DO 
    GetKeyStroke(sLetra);
    IF sLetra<>lf THEN
       sSenha[ncont]:=sLetra;
    END;
    ncont:=ncont+1;
  END;
  sSenha[ncont-1]:=nul;
  WriteLn;
  RETURN sSenha;
END digitaSenha;
(*------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a String com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------*)
PROCEDURE validaNumero(sRotulo, sNumero: String): String;
VAR nnum: REAL;
    nStatus: ConvResults;
    bQuebra: BOOLEAN;
BEGIN
bQuebra:=FALSE;
WHILE (bQuebra=FALSE) DO 
  WriteString(sRotulo);
  ReadLinha(sNumero);
  Take(sNumero,nnum,nStatus);
  IF nStatus=allRight THEN
    IF (nnum < 0.01) THEN
       WriteLinha(MSG_NUMINV);
    ELSE
       bQuebra:=TRUE;
    END;
  ELSE
    WriteLinha(MSG_NUMINV);
  END;
END;
RETURN sNumero;
END validaNumero;
(*------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a String com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------*)
PROCEDURE validaDataHora(sRotulo, sDataHora: String; bSoData: BOOLEAN): String;
VAR bvalida, bdatavalida, bhoravalida: BOOLEAN;
    sdia, smes, sano, shora, smin, sseg: String;
    ndia, nmes, nano, nhora, nmin, nseg, nudiames: INTEGER;
    ntam: CARDINAL;
BEGIN
bvalida:=FALSE;
bdatavalida:=FALSE;
bhoravalida:=FALSE;
nudiames:=0;

IF bSoData=TRUE THEN ntam:=10;
ELSE ntam:=19;
END;
WHILE (bvalida=FALSE) DO 
  WriteString(sRotulo);
  ReadLinha(sDataHora);
  IF Length(sDataHora)=ntam THEN 
    sdia:=copy(sDataHora,1,2);
    ndia:=Value(sdia);
    smes:=copy(sDataHora,4,2);
    nmes:=Value(smes);
    sano:=copy(sDataHora,7,4);
    nano:=Value(sano);
  
    IF (nano >= 1) AND (nano <= 9999) THEN 
      IF (nmes >= 1) AND (nmes <= 31) THEN 
          CASE nmes OF
          | 1, 3, 5, 7, 8, 10, 12: nudiames:=31;
          | 2: (* ano bissexto *)
               IF (nano MOD 4)=0 THEN nudiames:=29;
               ELSE nudiames:=28;
               END;
          | 4, 6, 9, 11: nudiames:=30;
          END;
          IF (ndia >=1) AND (ndia <=nudiames) THEN
             bdatavalida:=TRUE;
          END;
      END;
    END;
  
    IF bSoData THEN 
       IF bdatavalida THEN bvalida:=TRUE;
       ELSE WriteLinha(MSG_DATAINV);
       END;
    ELSE 
      IF bdatavalida THEN 
          shora:=copy(sDataHora,12,2);
          nhora:=Value(shora);
          smin:=copy(sDataHora,15,2);
          nmin:=Value(smin);
          sseg:=copy(sDataHora,18,2);
          nseg:=Value(sseg);
  
          IF (nhora >= 0) AND (nhora <= 23) THEN 
            IF (nmin >= 0) AND (nmin <= 59) THEN 
              IF (nseg >= 0) AND (nseg <= 59) THEN
                 bhoravalida:=TRUE;
              END;
            END;
          END;
  
          IF bhoravalida THEN bvalida:=TRUE;
          ELSE WriteLinha(MSG_DTHRINV);
          END;
      ELSE
        WriteLinha(MSG_DTHRINV);
      END;
    END;
  ELSE 
    IF bSoData=TRUE THEN WriteLinha(MSG_DATAINV);
    ELSE WriteLinha(MSG_DTHRINV);
    END; 
  END;
END;
RETURN sDataHora;
END validaDataHora;
(*------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------*)
PROCEDURE retDataHora(): String;
VAR datahora: DateTime;
    dia,mes,ano,hora,strdh: String; 
BEGIN
  GetClock(datahora);
  StructTimeToAscii(strdh,datahora);
  dia:=copy(strdh,10,2);
  mes:=copy(strdh,6,3);
  ano:=copy(strdh,1,4);
  hora:=copy(strdh,13,8);
  
  IF Compare(mes,"Jan")=equal THEN mes:="01";
  ELSIF Compare(mes,"Feb")=equal THEN mes:="02";
  ELSIF Compare(mes,"Mar")=equal THEN mes:="03";
  ELSIF Compare(mes,"Apr")=equal THEN mes:="04";
  ELSIF Compare(mes,"May")=equal THEN mes:="05";
  ELSIF Compare(mes,"Jun")=equal THEN mes:="06";
  ELSIF Compare(mes,"Jul")=equal THEN mes:="07";
  ELSIF Compare(mes,"Aug")=equal THEN mes:="08";
  ELSIF Compare(mes,"Sep")=equal THEN mes:="09";
  ELSIF Compare(mes,"Oct")=equal THEN mes:="10";
  ELSIF Compare(mes,"Nov")=equal THEN mes:="11";
  ELSIF Compare(mes,"Dez")=equal THEN mes:="12";
  END;

  stemp[0]:=zeros(trim(dia),2);
  stemp[1]:='/';
  stemp[2]:=zeros(trim(mes),2);
  stemp[3]:='/';
  stemp[4]:=zeros(trim(ano),4);
  stemp[5]:=' ';
  stemp[6]:=zeros(trim(hora),2);

  RETURN SomaStr(7, stemp); 
END retDataHora;

END Rotinas.
