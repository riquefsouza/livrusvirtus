with System.Val_Int; use System.Val_Int;
with System.Val_Real; use System.Val_Real;
with Ada.Command_Line; use Ada.Command_Line;
with Ada.Text_IO; use Ada.Text_IO;
with Text_IO; use Text_IO;
with Direct_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;
with Ada.FLoat_Text_IO; use Ada.Float_Text_IO;
with Ada.Characters; use Ada.Characters;
with Ada.Strings; use Ada.Strings;
with Ada.Strings.Unbounded; use Ada.Strings.Unbounded;
with Ada.Calendar; use Ada.Calendar;

with Ada.Numerics.Aux; use Ada.Numerics.Aux;

procedure teste is

  subtype ustring is unbounded_string;

  texto: ustring;

function U(origem : in String) return Unbounded_String
renames To_Unbounded_String;

function S(origem : in UString) return String
renames To_String;

procedure put(origem: in UString) is
begin
 put(S(origem));
end put;

procedure put_line(origem: in UString) is
begin
 put_line(S(origem));
end put_line;


function Repete(sTexto: in string; nQtd: in integer) return ustring is
 cont : integer;
 Esp : ustring;
begin
 cont:=1;
 Esp:=null_unbounded_string;
 while (cont <= nQtd) loop
    Esp:=Esp & sTexto;
    cont:=cont + 1;
 end loop;
return Esp;
end repete;

function copy(str: in ustring; ini,tam: in integer) return ustring is
 ts:integer:=0;
begin
if tam > (length(str)-ini)+1 then
   ts:=(length(str)-ini)+1;
else
   ts:=tam;
end if;
return U(slice(str,ini,ini+ts-1));
end copy;

-- ----------------------------------------------------------------------------
-- converte um numero numa string
-- nstr - o numero
-- retorna - a string
-- ----------------------------------------------------------------------------
function NumToStr(nstr: in float) return ustring is
 str, sret: ustring;
 ndec, nfloat, ncont, nlstr: float;
 nnum, ncasas: integer;
 bnegativo, bquebra: boolean;
begin
nlstr:=nstr;
nfloat:=nstr;
if integer(nfloat) = integer(nlstr) then
  ncasas:=0;
else
  ncasas:=1;
  bquebra:=false;
  while bquebra=false loop
    ncont:=nlstr * float(Pow(10.0,double(ncasas)));
    nfloat:=nfloat * 10.0;
    if integer(ncont) = integer(nfloat) then
      bquebra:=true;
    else
      ncasas:=ncasas + 1;
    end if;
  end loop;
end if;
if nlstr < 0.0 then
  nlstr := nlstr * (-1.0);
  bnegativo:=true;
else
  bnegativo:=false;
end if;
ndec:=nfloat * float(Pow(10.0,double(ncasas)));
str:=null_unbounded_string;
if nlstr = 0.0 then
  str := U("0");
else
  while ndec >= 1.0 loop
    nnum:=(integer(ndec) mod 10);
    if nnum = 0 then str:=str & Character'val(48);
    elsif nnum = 1 then str:=str & Character'val(49);
    elsif nnum = 2 then str:=str & Character'val(50);
    elsif nnum = 3 then str:=str & Character'val(51);
    elsif nnum = 4 then str:=str & Character'val(52);
    elsif nnum = 5 then str:=str & Character'val(53);
    elsif nnum = 6 then str:=str & Character'val(54);
    elsif nnum = 7 then str:=str & Character'val(55);
    elsif nnum = 8 then str:=str & Character'val(56);
    elsif nnum = 9 then str:=str & Character'val(57);
    end if;
    ndec:=((ndec - float(nnum)) / 10.0);
  end loop;
end if;
sret:=null_unbounded_string;
if ncasas > 0 then  
  nnum:=length(str)-ncasas;
  if nnum > 0 then
    sret:=copy(str, 1, nnum) & "." & copy(str, nnum+1, ncasas);
  else
    sret:="0" & "." & Repete("0",ncasas-1) & str;
  end if;
else
  sret:=str;
end if;
if bnegativo = true then
  sret:="-" & sret;
end if;
return sret;
end NumToStr;

-- ----------------------------------------------------------------------------
-- converte de um valor inteiro para uma string
-- valor - indica o inteiro
-- S - a string
-- radix - o base numerica
-- ----------------------------------------------------------------------------
procedure itoa (valor : integer; s : in out string) is
pos : integer := s'first;
nn, digit : integer;

  function log10approx (n : integer) return integer is
    nn, count : integer;
  begin
    nn := n;
    count := 0;
    while nn >= 10 loop
        count := count + 1;
        nn := nn / 10;
    end loop;
    return count;
  end log10approx;

begin
  if valor = 0 then
       s(pos) := '0';
       return;
  end if;
  
  if valor < 0 then
       s(pos) := '-';
       pos := pos + 1;
       nn := -valor;
  else
       nn := valor;
  end if;
  
  pos := log10approx(nn) + pos;
  
  if s'first+pos-1 > s'last then
       for i in s'first..s'last loop
             s(i) := '*';
       end loop;
       return;
  end if;
  
  while nn >= 1 loop
       digit := nn rem 10;
       nn := nn / 10;
       s(pos) := character'val(character'pos('0') + digit);
       pos := pos - 1;
  end loop;
end itoa;
-- ----------------------------------------------------------------------------
-- funcao que retorna o tamanho de um inteiro
-- it - indica o inteiro
-- ----------------------------------------------------------------------------
function itam(it: in integer) return integer is
 nRet:integer:=0;
begin
if it <= 9 then
  nRet:=1;
end if;
if it <= 99 and it > 9  then
  nRet:=2;
end if;
if it <= 999 and it > 99 then
  nRet:=3;
end if;
if it <= 9999 and it > 999 then
  nRet:=4;
end if;
if it <= 99999 and it > 9999 then
  nRet:=5;
end if;
if it <= 999999 and it > 99999 then
  nRet:=6;
end if;
if it <= 9999999 and it > 999999 then
  nRet:=7;
end if;
return nRet;
end itam;

-- ----------------------------------------------------------------------------
-- procedimento que converte de inteiro para ustring
-- num - indica o inteiro
-- str - indica a ustring
-- ----------------------------------------------------------------------------
procedure floattostr(num: in float; str: in out ustring; ndecimais: in integer) is
 sS:string(1..itam(integer(num))+ndecimais);
 nlocal, npos: integer;
 nnum: float;
begin
  nnum:=num;
  for ncont in 1..ndecimais loop
    nnum:=nnum * 10.0;
  end loop;
  nlocal:=integer(nnum);
  itoa(nlocal,sS);
  npos:=itam(integer(num));
  str:=copy(U(sS),1,npos);
--  str:=copy(U(sS),1,npos) & '.' & copy(U(sS),npos+1,ndecimais);
end floattostr;

begin
--  Put_Line(NumToStr(0.01));
  floattostr(0.04,texto,2);
  Put_Line(texto);
end teste;

