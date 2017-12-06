MODULE teste;

FROM Strings IMPORT Length, Append, 
Extract, Compare, CompareResults, Assign;
FROM SYSTEM IMPORT CAST, ADR, BYTE;
FROM Terminal IMPORT WriteString, GetKeyStroke;
FROM SysClock IMPORT GetClock, DateTime;
FROM InOut IMPORT Read, ReadLn, ReadString, Write, WriteCard,
WriteLn, ReadCard, ReadInt;
(* FROM UxFiles IMPORT File, Open, Close, OpenMode, Create, SetPos, EndFile,
ReadByte, WriteByte, FileSize, GetPos, Reset; *)
FROM Ascii IMPORT lf, cr, nul;

(*
IMPORT IOLink;
FROM IOChan IMPORT ChanId;
FROM RndFile IMPORT FlagSet, OpenResults, OpenOld, OpenClean, 
FilePos, StartPos, CurrentPos, EndPos, SetPos, Close, 
read, write, old, text;
FROM IOConsts IMPORT ReadResults;
FROM IOChan IMPORT TextRead, TextWrite; *)

FROM AsciiTime IMPORT StructTimeToAscii; 

TYPE
 tregistro = ARRAY[0..145] OF CHAR;
 String = ARRAY[0..255] OF CHAR;

VAR
 st1, st2, stexto: String;
(* tfAssunto: ChanId; *)
 bStatus, bQuebra: BOOLEAN;
 npos: CARDINAL;
(* res: OpenResults; *)
 stemp: ARRAY[0..10] OF String;

(*
PROCEDURE fimArq(VAR sArq: ChanId): BOOLEAN;
BEGIN
 IF CurrentPos(sArq) = EndPos(sArq) THEN
    RETURN TRUE;
 ELSE
    RETURN FALSE;
 END;
END fimArq;

PROCEDURE lerArq(VAR sArq: ChanId; nTamLinha, nTamCRLF: CARDINAL; 
VAR npos: CARDINAL): String;
VAR nLidos: CARDINAL;
    slinha: tregistro;
BEGIN
TextRead(sArq, ADR(slinha), nTamLinha, nLidos);
IF nLidos <> nTamLinha THEN
   slinha:='';
ELSE
  slinha[nTamLinha]:=nul;
  npos:=npos + (nTamLinha + nTamCRLF);
  SetPos(tfAssunto, npos);
END;
RETURN CAST(String,slinha);
END lerArq;

PROCEDURE gravarArq(VAR sArq: ChanId; nTamLinha, nTamCRLF: CARDINAL; slinha: String);
BEGIN
TextWrite(sArq, ADR(slinha), (nTamLinha + nTamCRLF));
END gravarArq;

PROCEDURE copy(str: String; ini,tam: CARDINAL): String;
VAR str1: String;
BEGIN
ini:=ini-1;
Extract(str,ini,tam,str1);
RETURN str1;
END copy;

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
*)

BEGIN

WriteString('oi tudo bom!');
WriteLn;
(*

bQuebra:=FALSE;

OpenClean(tfAssunto,'teste.dat',(read + write + text), res);


OpenOld(tfAssunto,'assunto.dat',(read + write + old + text), res);

Assign('12        teste                         ',st1);
st2[0]:=cr;
st2[1]:=lf;
st2[2]:=nul;
Append(st2,st1);

WriteString(st1);
WriteLn;
WriteCard(Length(st1),2);
WriteLn;
ReadLn;


SetPos(tfAssunto, 0);
gravarArq(tfAssunto, 40, 2, st1);

SetPos(tfAssunto, EndPos(tfAssunto));
gravarArq(tfAssunto, 40, 2, st1);

WriteString('gravou');
WriteLn;
ReadLn;

npos:=0;
SetPos(tfAssunto, 0);
WHILE (NOT fimArq(tfAssunto)) AND (bQuebra=FALSE) DO  
  stexto:=lerArq(tfAssunto, 40, 2, npos);
 
     WriteString(stexto);     
     WriteLn;
     WriteCard(Length(stexto),2);
     WriteLn;
     WriteCard(CurrentPos(tfAssunto),2);
     WriteLn;
     WriteCard(EndPos(tfAssunto), 2);
     WriteLn;
 
END; 
WriteString('Fim parte UM');
WriteLn;

ReadLn;

npos:=0;
SetPos(tfAssunto, 0);
WHILE (NOT fimArq(tfAssunto)) AND (bQuebra=FALSE) DO  
  slinha:=lerArq(tfAssunto, 40, 2, npos);

     WriteString(slinha);     
     WriteLn;
     WriteCard(Length(slinha),2);
     WriteLn;
     WriteCard(CurrentPos(tfAssunto),2);
     WriteLn;
     WriteCard(EndPos(tfAssunto), 2);
     WriteLn;

END; 

WriteString('Fim parte DOIS');
WriteLn;

ReadLn;

npos:=0;
SetPos(tfAssunto, 0);
WHILE (NOT fimArq(tfAssunto)) AND (bQuebra=FALSE) DO  
  slinha:=lerArq(tfAssunto, 40, 2, npos);

     WriteString(slinha);     
     WriteLn;
     WriteCard(Length(slinha),2);
     WriteLn;
     WriteCard(CurrentPos(tfAssunto),2);
     WriteLn;
     WriteCard(EndPos(tfAssunto), 2);
     WriteLn;
     ReadLn;

END; 

WriteString('Fim parte DOIS');
WriteLn;

Close(tfAssunto);
*)
END teste.