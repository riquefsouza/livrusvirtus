-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem ada.
-- ----------------------------------------------------------------------------
-- program Livrus

with Interfaces, Interfaces.C, Interfaces.C.Strings, Unchecked_Conversion;
use  Interfaces, Interfaces.C, Interfaces.C.Strings;

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

procedure livrus is

  subtype ustring is unbounded_string;

  type regAssunto is record
     codigo: ustring; -- 10
     assunto: ustring; -- 30
  end record;
  type regAutor is record
   codigo: ustring; -- 10
   autor: ustring; -- 30
  end record;
  type regEditora is record
   codigo: ustring; -- 10
   editora: ustring; -- 50
  end record;
  type regIdioma is record
   codigo: ustring; -- 10
   idioma: ustring; -- 20
  end record;
  type regUsuario is record
   login: ustring; -- 10
   senha: ustring; -- 10
  end record;
  type regPais is record
   codigo: ustring; -- 3
   pais: ustring; -- 50
  end record;
  type regProfissao is record
   codigo: ustring; -- 10
   profissao: ustring; -- 50
  end record;
  type regLivro is record
   isbn: ustring; -- 13
   titulo: ustring; -- 50
   edicao: ustring; -- 10
   anopubli: ustring; -- 10
   codeditora: ustring; -- 10
   volume: ustring; -- 10
   codidioma: ustring; -- 10
   npaginas: ustring; -- 10
   preco: ustring; -- 10
   qtdestoque: ustring; -- 10
  end record;
  type regLivroAss is record
   isbn: ustring; -- 13
   codassunto: ustring; -- 10
  end record;
  type regLivroAut is record
   isbn: ustring; -- 13
   codautor: ustring; -- 10
  end record;
  type regCliente is record
   cpf: ustring; -- 14
   nome: ustring; -- 30
   email: ustring; -- 30
   identidade: ustring; -- 10
   sexo: ustring; -- 1
   telefone: ustring; -- 17
   dtnascimento: ustring; -- 10
   codendereco: ustring; -- 10
   codpais: ustring; -- 3
   codprofissao: ustring; -- 10
  end record;
  type regEndereco is record
   codigo: ustring; -- 10
   logradouro: ustring; -- 40
   bairro: ustring; -- 15
   cep: ustring; -- 8
   cidade: ustring; -- 30
   estado: ustring; -- 20
  end record;
  type regVenda is record
   dthrvenda: ustring; -- (19) data/hora da venda dd/mm/yyyy hh:mm:ss 
   cpf: ustring; -- 14
   isbn: ustring; -- 13
   precovenda: ustring; -- 10
  end record;

  type ctTipo is (opTexto, opNumero, opData, opDataHora, opSenha);
  type ctArqs is (opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
                opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
                opUsuario, opVenda);
  type ctAcao is (opNovo, opAlterar, opPesquisar, opSalvarInclusao,
              opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos);
  type ctTArqs is (taAssunto, taAutor, taEditora, taEndereco, taIdioma, taPais,
                taProfissao, taCliente, taLivro, taLivroAss, taLivroAut,
                taUsuario, taVenda);

-- constantes 

  CRLF: constant string := Character'val(13) & Character'val(10); -- windows --
  TAM_CRLF: constant integer := 2;
--  CRLF: constant string := Character'val(10);
--  TAM_CRLF: constant integer := 1; -- unix --
--  CRLF: string := constant Character'val(13);
--  TAM_CRLF: constant integer := 1; -- macintosh --

  QTD_MAX_LINHA: constant integer := 18;
  TAM_MAX_STR: constant integer := 255;

  MSG_ARQERRO: constant string := "Erro: O arquivo não pode ser aberto.";
  MSG_ERRO: constant string := "Erro: opção inválida digite de novo";
  MSG_OPCAO: constant string := "Escolha uma opção: ";
  MSG_PRESS: constant string := "pressione para continuar...";

  MSG_REGINC: constant string := "registro incluido!";
  MSG_REGNINC: constant string := "registro não incluido!";
  MSG_REGALT: constant string := "registro alterado!";
  MSG_REGNALT: constant string := "registro não alterado!";
  MSG_REGEXC: constant string := "registro excluido!";
  MSG_REGNEXC: constant string := "registro não excluido!";
  MSG_REGEXST: constant string := "registro já existe!";

  MSG_NUMINV: constant string := "Número inválido ou menor do que 1!";
  MSG_DATAINV: constant string := "Data inválida!, formato correto (dd/mm/yyyy)";
  MSG_DTHRINV: constant string := "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)";
  MSG_ISBNINV: constant string := "ISBN inválido!";
  MSG_CPFINV: constant string := "CPF inválido!";
  MSG_SENCONFERE: constant string := "senha não confere com a senha atual!";
  MSG_SENCONFIRM: constant string := "nova senha não confere com a senha confirmada!";
  MSG_LOGINENCON: constant string := "login não encontrado!";
  MSG_SEMESTOQUE: constant string := "livro não existe no estoque!";

  ARQ_ASSUNTO: constant string := "assunto.dat";
  ARQ_AUTOR: constant string := "autor.dat";
  ARQ_EDITORA: constant string := "editora.dat";
  ARQ_IDIOMA: constant string := "idioma.dat";
  ARQ_USUARIO: constant string := "usuario.dat";
  ARQ_PAIS: constant string := "pais.dat";
  ARQ_PROFISSAO: constant string := "profiss.dat";
  ARQ_LIVRO: constant string := "livro.dat";
  ARQ_LIVASS: constant string := "livroass.dat";
  ARQ_LIVAUT: constant string := "livroaut.dat";
  ARQ_CLIENTE: constant string := "cliente.dat";
  ARQ_ENDERECO: constant string := "endereco.dat";
  ARQ_VENDA: constant string := "venda.dat";

  TAM_ASSUNTO: constant integer := 40 + TAM_CRLF;
  TAM_AUTOR: constant integer := 40 + TAM_CRLF;
  TAM_EDITORA: constant integer := 60 + TAM_CRLF;
  TAM_IDIOMA: constant integer := 30 + TAM_CRLF;
  TAM_USUARIO: constant integer := 20 + TAM_CRLF;
  TAM_PAIS: constant integer := 53 + TAM_CRLF;
  TAM_PROFISSAO: constant integer := 60 + TAM_CRLF;
  TAM_LIVRO: constant integer := 143 + TAM_CRLF;
  TAM_LIVASS: constant integer := 23 + TAM_CRLF;
  TAM_LIVAUT: constant integer := 23 + TAM_CRLF;
  TAM_CLIENTE: constant integer := 135 + TAM_CRLF;
  TAM_ENDERECO: constant integer := 123 + TAM_CRLF;
  TAM_VENDA: constant integer := 56 + TAM_CRLF;

-- variaveis globais --
 bopcao: boolean:=false;
 opmenu: character;
 g_nPosChave, g_nTamChave: integer:=0;
 g_nPreco: float := 0.0;
 g_SalvarInclusao: boolean:=false;

 tAssunto: regAssunto;
 tAutor: regAutor;
 tEditora: regEditora;
 tIdioma: regIdioma;
 tEndereco: regEndereco;
 tPais: regPais;
 tProfissao: regProfissao;
 tLivro: regLivro;
 tLivroAss: regLivroAss;
 tLivroAut: regLivroAut;
 tCliente: regCliente;
 tUsuario: regUsuario;
 tVenda: regVenda;

 subtype blocoAssunto is String(1 .. TAM_ASSUNTO);
 package AssuntoIO is new Direct_IO(blocoAssunto); use AssuntoIO;
 tfAssunto : AssuntoIO.File_Type; 
 blAssunto : blocoAssunto;

 subtype blocoAutor is String(1 .. TAM_AUTOR);
 package AutorIO is new Direct_IO(blocoAutor); use AutorIO;
 tfAutor : AutorIO.File_Type; 
 blAutor : blocoAutor;

 subtype blocoEditora is String(1 .. TAM_EDITORA);
 package EditoraIO is new Direct_IO(blocoEditora); use EditoraIO;
 tfEditora : EditoraIO.File_Type;
 blEditora : blocoEditora;

 subtype blocoIdioma is String(1 .. TAM_IDIOMA);
 package IdiomaIO is new Direct_IO(blocoIdioma); use IdiomaIO;
 tfIdioma : IdiomaIO.File_Type;
 blIdioma : blocoIdioma;

 subtype blocoEndereco is String(1 .. TAM_ENDERECO);
 package EnderecoIO is new Direct_IO(blocoEndereco); use EnderecoIO;
 tfEndereco : EnderecoIO.File_Type;
 blEndereco : blocoEndereco;

 subtype blocoPais is String(1 .. TAM_PAIS);
 package PaisIO is new Direct_IO(blocoPais); use PaisIO;
 tfPais : PaisIO.File_Type;
 blPais : blocoPais;

 subtype blocoProfissao is String(1 .. TAM_PROFISSAO);
 package ProfissaoIO is new Direct_IO(blocoProfissao); use ProfissaoIO;
 tfProfissao : ProfissaoIO.File_Type;
 blProfissao : blocoProfissao;

 subtype blocoLivro is String(1 .. TAM_LIVRO);
 package LivroIO is new Direct_IO(blocoLivro); use LivroIO;
 tfLivro : LivroIO.File_Type;
 blLivro : blocoLivro;

 subtype blocoLivroAss is String(1 .. TAM_LIVASS);
 package LivroAssIO is new Direct_IO(blocoLivroAss); use LivroAssIO;
 tfLivroAss : LivroAssIO.File_Type;
 blLivroAss : blocoLivroAss;

 subtype blocoLivroAut is String(1 .. TAM_LIVAUT);
 package LivroAutIO is new Direct_IO(blocoLivroAut); use LivroAutIO;
 tfLivroAut : LivroAutIO.File_Type;
 blLivroAut : blocoLivroAut;

 subtype blocoCliente is String(1 .. TAM_CLIENTE);
 package ClienteIO is new Direct_IO(blocoCliente); use ClienteIO;
 tfCliente : ClienteIO.File_Type;
 blCliente : blocoCliente;

 subtype blocoUsuario is String(1 .. TAM_USUARIO);
 package UsuarioIO is new Direct_IO(blocoUsuario); use UsuarioIO;
 tfUsuario : UsuarioIO.File_Type;
 blUsuario : blocoUsuario;

 subtype blocoVenda is String(1 .. TAM_VENDA);
 package VendaIO is new Direct_IO(blocoVenda); use VendaIO;
 tfVenda : VendaIO.File_Type;
 blVenda : blocoVenda;

-- Rotinas importadas ---------------------------------------------------------
procedure Djgpp_itoa(valor: in integer;buffer: in Chars_Ptr;radix: in integer);
pragma Import (C, Djgpp_itoa, "itoa");

-- Rotinas básicas ------------------------------------------------------------
procedure get_line(sEntrada : out ustring);
procedure itoa(valor: in integer;S: in out string;radix: in integer);
function itam(it: in integer) return integer;
procedure itostr(num: in integer; str: in out ustring);
function Repete(sTexto: in string; nQtd: in integer) return ustring;
function copy(str: in ustring; ini,tam: in integer) return ustring;
function esp(sTexto: in ustring; nTam: in integer) return ustring;
function zeros(stexto: ustring; ntam: in integer) return ustring;
function strRelativa(sTexto, sChave: in ustring) return boolean;
function modulo11(valor: in ustring; dig: in integer; 
         cond: in boolean) return integer;
function validaCPF(cpf: in ustring) return boolean;
function validaISBN(isbn: in ustring) return boolean;
function digitaSenha(sRotulo: in ustring; nTamSenha: in integer) return ustring;
function validaFloat(sNumero: in string) return float;
function validaNumero(sRotulo, sNumero: in ustring) return ustring;
function validaDataHora(sRotulo, sDataHora: in ustring; 
         bSoData: in boolean) return ustring;
function retDataHora return ustring;

-- Rotinas de manipulação de arquivos -----------------------------------------
function tamArq(sArq: in ctTArqs) return integer;
function fimArq(sArq: in ctTArqs) return boolean;
function posArq(sArq: in ctTArqs) return integer;
procedure seekArq(sArq: in ctTArqs; npos: in integer);
function lerArq(sArq: in ctTArqs) return ustring;
procedure gravarArq(sArq: in ctTArqs; sTexto: in ustring);
procedure abrecriaArqs(bAbre: in boolean);
procedure fechaArqs;
function pesqArq(sArq: in ctTArqs; sChave: in ustring; nPosChave,
         nTamChave, nTamLinha: in integer) return ustring;
procedure pesqLinhaExcluida(sArq: in ctTArqs; nTamLinha: in integer);
function pesqMaxCod(sArq: in ctTArqs; nPosChave,
        nTamChave, nTamLinha: in integer) return ustring;
procedure escreveArq(sArq: in ctTArqs; sTexto: in ustring;
	sMsgAcerto, sMsgErro: in string);

-- Rotinas de implementação do sistema e de interface -------------------------
function LinhaReg(sreg: in ctArqs) return ustring;
function tamReg(sreg: in ctArqs) return integer;
function rotulo(sreg: in ctArqs; nNum: in integer) return ustring;
function ContinuaSN(nlinha, nQtdLinha: in integer) return boolean;
function ListarTodos(sArq: in ctTArqs; sreg: in ctArqs; sChave: in ustring;
         nPosChave, nTamChave, nTamLinha, nQtdLinha: in integer;
         bPesqRelativa: in boolean) return boolean;
procedure ListarRegLigados(sArq1: in ctTArqs; sreg1: in ctArqs; nPosChave1,
          nTamChave1, nPosChave2, nTamChave2: in integer; sChave: in ustring;
     sArq2: in ctTArqs; sreg2: in ctArqs; nPosChave3, nQtdLinha: in integer);
function validaEntrada(sArq: in ctTArqs; sreg: in ctArqs; nTexto: in integer;
        sEntrada: in ustring; nTentativas: in integer;
        bPesqRelativa: in boolean; bTipoEntrada: in ctTipo) return ustring;
procedure frmSplash;
procedure frmSobre;
function frmLogin return boolean;
procedure menu(num: in integer);
procedure frmCadastros(sreg: in ctArqs; sacao: in ctAcao);
procedure frmConsultas(sreg: in ctArqs; sacao: in ctAcao);
procedure frmAlterarSenha;
procedure btnAcao(sreg: in ctArqs; sacao: in ctAcao);
procedure subMenu(nmenu: in integer; sreg: in ctArqs);
procedure usaMenu(num: in integer);
procedure mostrarDados(sreg: in ctArqs; slinha: in ustring; nOpcao: in integer);
procedure mostrarSubDados(sreg, ssubreg: in ctArqs; bSoMostrar: in boolean);
procedure frmCadLigados(sreg: in ctArqs; sacao: in ctAcao; sCodigo: in ustring);
procedure ExcluirRegLigados(sArq: in ctTArqs; sreg: in ctArqs; nPosChave,
          nTamChave: in integer; sChave: in ustring);

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

procedure get_line(sEntrada: out character) is
slocal: string(1..TAM_MAX_STR);
nultimo: Natural:=1;
begin
get_line(slocal,nultimo);
sEntrada:=slocal(1);
end;

-- ----------------------------------------------------------------------------
-- le uma ustring do teclado
-- sEntrada o valor a ser retornado
-- ----------------------------------------------------------------------------
procedure get_line(sEntrada : out ustring) is
    
  function mais_entrada return Unbounded_String is
     entrada: String(1..TAM_MAX_STR);
     nultimo: Natural;
  begin
     Get_Line(Current_Input, entrada, nultimo);
     if nultimo < entrada'Last then
        return U(entrada(1..nultimo));
     else
        return U(entrada(1..nultimo)) & mais_entrada;
     end if;
  end mais_entrada;
begin
  sEntrada := mais_entrada;
end get_line;

-- ----------------------------------------------------------------------------
-- converte de um valor inteiro para uma string
-- valor - indica o inteiro
-- S - a string
-- radix - o base numerica
-- ----------------------------------------------------------------------------
procedure itoa(valor: in integer;S: in out string;radix: in integer) is
 i : size_t;
 str : chars_ptr;
begin
  str:=new_string(S);
  djgpp_itoa(valor,str,radix);
  i:=strlen(str);
  S(1..integer(i)):=value(str);
  free(str);      
end itoa;
-- ----------------------------------------------------------------------------
-- convert uma string num numero somente positivo
-- nstr - a string
-- retorna - o numero
-- ----------------------------------------------------------------------------
function StrToNum(str: in string) return float is
 nnum, ndec, bponto: integer;
 nret: float;
begin
bponto = FALSE
nret = 0
ndec = length(str)
  for ncont = 1 to length(str) do
    if str[ncont] = 48 then nnum = 0
    elsif str[ncont] = 49 then nnum = 1
    elsif str[ncont] = 50 then nnum = 2
    elsif str[ncont] = 51 then nnum = 3
    elsif str[ncont] = 52 then nnum = 4
    elsif str[ncont] = 53 then nnum = 5
    elsif str[ncont] = 54 then nnum = 6
    elsif str[ncont] = 55 then nnum = 7
    elsif str[ncont] = 56 then nnum = 8
    elsif str[ncont] = 57 then nnum = 9
    elsif str[ncont] = 46 then 
      nret = nret / power(10, ndec)
      ndec = 0 -- ponto
    else 
      nret = -1
      exit
    end if

    if str[ncont] != 46 then    
      ndec = ndec - 1
      nret = nret + (nnum * power(10, ndec))
    end if

  end for
return nret
end function

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
procedure itostr(num: in integer;str: in out ustring) is
 sS:string(1..itam(num));
begin
 itoa(num,sS,10);
 str:=copy(U(sS),1,itam(num));
end itostr;

-- ----------------------------------------------------------------------------
-- Repete um texto um número determinado de vezes.
-- sTexto - o texto a ser repetido
-- nQtd - a quantidade de vezes
-- retorna - o texto repetido
-- ----------------------------------------------------------------------------
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

-- ----------------------------------------------------------------------------
-- Função que retorna um pedaço de uma string.
-- str - indica a string
-- ini - indica a posicao inicial do pedaco
-- tam - indica o tamanho do pedaco
-- retorna - o pedaço da string
-- ----------------------------------------------------------------------------
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
-- Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
-- sTexto - o texto
-- nTam - tamanho máximo do texto
-- retorna - o texto com espaços em branco a mais
-- ----------------------------------------------------------------------------
function esp(sTexto: in ustring; nTam: in integer) return ustring is
begin
return sTexto & repete(" ",nTam-length(sTexto));
end esp;

-- ----------------------------------------------------------------------------
-- Escreve zeros na frente de um texto.
-- stexto - o texto para receber zeros a frente
-- ntam - o tamanho da string
-- retorna - o texto com o zeros antes
-- ----------------------------------------------------------------------------
function zeros(stexto: ustring; ntam: in integer) return ustring is
ncont: integer := 0;
saux: ustring;
begin
  saux:=null_unbounded_string;
  if ntam/=length(stexto) then
      for ncont in 1..ntam-length(stexto) loop
        saux:=saux & "0";
      end loop;
  end if;
  return saux & stexto;
end zeros;

-- ----------------------------------------------------------------------------
-- Faz uma pesquisa relativa de um texto através de um valor chave.
-- sTexto - o texto
-- sChave - a chave a ser pesquisada
-- retorna - se achou ou não a chave dentro do texto
-- ----------------------------------------------------------------------------
function strRelativa(sTexto, sChave: in ustring) return boolean is
    nCont, nTamChave, nTamTexto: integer;
    bret: boolean;
    sPedaco: ustring;
begin
bret:=false;
nCont:=1;
nTamChave:=length(sChave);
nTamTexto:=length(sTexto);
if nTamChave <= nTamTexto then
  while nCont <= (nTamTexto-nTamChave+1) loop
     sPedaco:=copy(sTexto,nCont,nTamChave);
     if sPedaco=sChave then
        bret:=true;
     end if; 
     nCont:=nCont+1;
  end loop;
end if;
return bret;
end strRelativa;

-- ----------------------------------------------------------------------------
-- Calcula o modulo11 de um valor qualquer.
-- valor - a string com o número a ser calculado
-- dig - dígito do valor a ser calculado
-- cond - condição de retorno de aninhamento
-- retorna - o dígito correto
-- ----------------------------------------------------------------------------
function modulo11(valor: in ustring; dig: in integer; 
         cond: in boolean) return integer is
cont, soma, num, ret, ndig, nvalor: integer;
sres: ustring;
begin
cont:=0;
ndig:=0;
soma:=0;

case dig is
 when 1 =>
      num:=10;
      for cont in 1..length(valor) loop
        sres:=copy(valor,cont,1);
        nvalor:=Value_Integer(S(sres));
        soma:=soma+(num*nvalor);
        num:=num-1;
      end loop;
 when 2 => soma:=modulo11(valor,1,false)+(modulo11(valor,1,true)*2);
 when others => null;
end case;
if (cond=true) then
  ret:=soma mod 11;
  if (ret=0) or (ret=1) then
    ndig:=0;
  elsif (ret > 1) then
    ndig:=(11-ret);
  end if;
  return ndig;
else
  return soma;
end if;
end modulo11;
-- ----------------------------------------------------------------------------
-- Validação de um número de CPF qualquer.
-- cpf - a string com o número do CPF
-- retorna - se é valido ou não
-- ----------------------------------------------------------------------------
function validaCPF(cpf: in ustring) return boolean is
scpf, sres: ustring;
nvalor1, nvalor2: integer;
begin
if (length(cpf)=14) then
  scpf:=copy(cpf,1,3) & copy(cpf,5,3) & copy(cpf,9,3);
  sres:=copy(cpf,13,1);
  nvalor1:=Value_Integer(S(sres));
  sres:=copy(cpf,14,1);
  nvalor2:=Value_Integer(S(sres));
  if ((modulo11(scpf,1,true)=nvalor1) and (modulo11(scpf,2,true)=nvalor2)) then
    return true;
  else
    return false;
  end if;
else
  return false;
end if;
end validaCPF;

-- ----------------------------------------------------------------------------
-- Validação de um número ISBN qualquer.
-- isbn - a string com o número do ISBN
-- retorna - se é valido ou não
-- ----------------------------------------------------------------------------
function validaISBN(isbn: in ustring) return boolean is
sisbn, sres: ustring;
cont, nvalor: integer;
begin
if (length(isbn)=13) then
  sisbn:=null_unbounded_string;
  for cont in 1..length(isbn)-1 loop
    if (copy(isbn,cont,1)/="-") then
      sisbn:=sisbn & copy(isbn,cont,1);
    end if;
  end loop;
  cont:=modulo11(sisbn,1,true);
  if (cont=0) then 
    if (copy(isbn,13,1)="X") or (copy(isbn,13,1)="0") then
      return true;
    else
      return false;
    end if;
  else 
    sres:=copy(isbn,13,1);
    nvalor:=Value_Integer(S(sres));
    if (cont=nvalor) then
      return true;
    else
      return false;
    end if;
  end if;
else
  return false;
end if;
end validaISBN;

-- ----------------------------------------------------------------------------
-- Esconde a digitação da senha
-- retorna - a senha digitada
-- ----------------------------------------------------------------------------
function digitaSenha(sRotulo: in ustring; nTamSenha: in integer) 
         return ustring is
sSenha: ustring;
sLetra: character;
ncont: integer;
begin
put(sRotulo);
ncont:= 0;
sSenha:=null_unbounded_string;
sLetra:=Character'val(0);
while (sLetra/=Character'val(13)) and (ncont < nTamSenha) loop
  get_immediate(sLetra);
  if sLetra/=Character'val(13) then
     sSenha:=sSenha & sLetra;
  end if;
  ncont:=ncont+1;
end loop;
return sSenha;
end digitaSenha;

-- ----------------------------------------------------------------------------
-- Validação de um número com ponto flutuante.
-- sNumero - a string com o valor do número
-- retorna - o numero ou 0.0 se errado
-- ----------------------------------------------------------------------------
function validaFloat(sNumero: in string) return float is
-- nnum: integer;
nnum: float;
begin
  -- nnum:=Value_Integer(sNumero);
  nnum:=float(Value_Real(sNumero));
  return nnum;
exception
  when Program_Error | Constraint_Error => return 0.0;	 
  when others => return 0.0; 
end validaFloat;

-- ----------------------------------------------------------------------------
-- Validação de um número qualquer.
-- sRotulo - o texto antes de se digitar o número
-- sNumero - a string com o valor do número
-- retorna - o sNumero
-- ----------------------------------------------------------------------------
function validaNumero(sRotulo, sNumero: in ustring) return ustring is
nnum: float;
nStatus: integer;
slNumero: ustring;
begin
nStatus:=-1;
while (nStatus/=0) loop
  put(sRotulo);
  get_line(slNumero);
  nnum:=validaFloat(S(slNumero));
  if (nnum < 0.01) then
     put_line(MSG_NUMINV);
  else
     nStatus:=0;
  end if;
end loop;

return slNumero;
end validaNumero;

-- ----------------------------------------------------------------------------
-- Validação de uma data ou data/hora qualquer.
-- sRotulo - o texto antes de se digitar a data/hora
-- sDataHora - a string com o valor da data/hora
-- bSoData - indica se vai validar somente uma data sem a hora
-- retorna - a sDataHora
-- ----------------------------------------------------------------------------
function validaDataHora(sRotulo, sDataHora: in ustring; 
         bSoData: in boolean) return ustring is
bvalida, bdatavalida, bhoravalida: boolean;
sdia, smes, sano, shora, smin, sseg: ustring;
ndia, nmes, nano, nhora, nmin, nseg, nudiames: integer;
ntam: integer;
slDataHora: ustring;
begin
bvalida:=false;
bdatavalida:=false;
bhoravalida:=false;
nudiames:=0;

if bSoData=true then ntam:=10;
else ntam:=19;
end if;
while (bvalida=false) loop
  put(sRotulo);
  get_line(slDataHora);
  if length(slDataHora)=ntam then
    sdia:=copy(slDataHora,1,2);
    ndia:=Value_Integer(S(sdia));
    smes:=copy(slDataHora,4,2);
    nmes:=Value_Integer(S(smes));
    sano:=copy(slDataHora,7,4);
    nano:=Value_Integer(S(sano));
  
    if (nano >= 1) and (nano <= 9999) then
      if (nmes >= 1) and (nmes <= 31) then
          case nmes is
            when 1 | 3 | 5 | 7 | 8 | 10 | 12 => nudiames:=31;
            when 2 =>
               -- ano bissexto --
               if (nano mod 4)=0 then nudiames:=29;
               else nudiames:=28;              
               end if;
            when 4 | 6 | 9 | 11 => nudiames:=30;
            when others => null;  
          end case;
          if (ndia >=1) and (ndia <=nudiames) then
             bdatavalida:=true;
          end if;
      end if;
    end if;
  
    if bSoData then
       if bdatavalida then bvalida:=true;
       else put_line(MSG_DATAINV);
       end if;
    else
      if bdatavalida then
          shora:=copy(slDataHora,12,2);
          nhora:=Value_Integer(S(shora));
          smin:=copy(slDataHora,15,2);
          nmin:=Value_Integer(S(smin));
          sseg:=copy(slDataHora,18,2);
          nseg:=Value_Integer(S(sseg));
  
          if (nhora >= 0) and (nhora <= 23) then
            if (nmin >= 0) and (nmin <= 59) then
              if (nseg >= 0) and (nseg <= 59) then
                 bhoravalida:=true;
              end if;
            end if;
          end if; 
  
          if bhoravalida then bvalida:=true;
          else put_line(MSG_DTHRINV);
          end if;
      else
        put_line(MSG_DTHRINV);
      end if;
    end if;
  else
    if bSoData=true then put_line(MSG_DATAINV);
    else put_line(MSG_DTHRINV);
    end if;
  end if;
end loop;
return slDataHora;
end validaDataHora;

-- ----------------------------------------------------------------------------
-- Retorna a Data e a hora do sistema.
-- retorna - a data e a hora
-- ----------------------------------------------------------------------------
function retDataHora return ustring is
y : year_number;
m : month_number;
d : day_number;
h, mn, s, dd, dh : natural;
dia,mes,ano,hora,min,seg: ustring;
begin
  d:=integer(day(clock));
  m:=integer(month(clock));
  y:=integer(year(clock));
  itostr(d,dia);
  itostr(m,mes);
  itostr(y,ano);

  dd:=natural(seconds(clock));
  dh:=natural(dd/60);
  s:=natural(dd rem 60);
  mn:=dh rem 60;
  h:=dh / 60;

  itostr(s,seg);
  itostr(mn,min);
  itostr(h,hora);

  return zeros(dia,2) & "/" & zeros(mes,2) & "/" & zeros(ano,4) & " " &
  zeros(hora,2) & ":" & zeros(min,2) & ":" & zeros(seg,2);
end retDataHora;

-- ----------------------------------------------------------------------------
-- Calcula o tamanho do arquivo.
-- sArq - o arquivo
-- retorna - o tamanho do arquivo
-- ----------------------------------------------------------------------------
function tamArq(sArq: in ctTArqs) return integer is
ntam: integer:=0;
begin
case sArq is
  when taAssunto => ntam:=integer(AssuntoIO.size(tfAssunto));
  when taAutor => ntam:=integer(AutorIO.size(tfAutor));
  when taEditora => ntam:=integer(EditoraIO.size(tfEditora));
  when taIdioma => ntam:=integer(IdiomaIO.size(tfIdioma));
  when taEndereco => ntam:=integer(EnderecoIO.size(tfEndereco));
  when taPais => ntam:=integer(PaisIO.size(tfPais));
  when taProfissao => ntam:=integer(ProfissaoIO.size(tfProfissao));
  when taLivro => ntam:=integer(LivroIO.size(tfLivro));
  when taLivroAss => ntam:=integer(LivroAssIO.size(tfLivroAss));
  when taLivroAut => ntam:=integer(LivroAutIO.size(tfLivroAut));
  when taCliente => ntam:=integer(ClienteIO.size(tfCliente));
  when taUsuario => ntam:=integer(UsuarioIO.size(tfUsuario));
  when taVenda => ntam:=integer(VendaIO.size(tfVenda));
  when others => ntam:=0;  
end case;
return ntam;
end tamArq;

-- ----------------------------------------------------------------------------
-- verifica se chegou ao fim do arquivo.
-- sArq - o arquivo
-- retorna - se chegou ao fim
-- ----------------------------------------------------------------------------
function fimArq(sArq: in ctTArqs) return boolean is
bfim: boolean:=false;
begin
case sArq is
  when taAssunto => bfim:=AssuntoIO.End_of_file(tfAssunto);
  when taAutor => bfim:=AutorIO.End_of_file(tfAutor);
  when taEditora => bfim:=EditoraIO.End_of_file(tfEditora);
  when taIdioma => bfim:=IdiomaIO.End_of_file(tfIdioma);
  when taEndereco => bfim:=EnderecoIO.End_of_file(tfEndereco);
  when taPais => bfim:=PaisIO.End_of_file(tfPais);
  when taProfissao => bfim:=ProfissaoIO.End_of_file(tfProfissao);
  when taLivro => bfim:=LivroIO.End_of_file(tfLivro);
  when taLivroAss => bfim:=LivroAssIO.End_of_file(tfLivroAss);
  when taLivroAut => bfim:=LivroAutIO.End_of_file(tfLivroAut);
  when taCliente => bfim:=ClienteIO.End_of_file(tfCliente);
  when taUsuario => bfim:=UsuarioIO.End_of_file(tfUsuario);
  when taVenda => bfim:=VendaIO.End_of_file(tfVenda);
  when others => bfim:=false;  
end case;
return bfim;
end fimArq;

-- ----------------------------------------------------------------------------
-- retorna a posicao dentro do arquivo.
-- sArq - o arquivo
-- retorna - a posicao dentro do arquivo
-- ----------------------------------------------------------------------------
function posArq(sArq: in ctTArqs) return integer is
npos: integer:=0;
begin
case sArq is
  when taAssunto => npos:=integer(AssuntoIO.index(tfAssunto));
  when taAutor => npos:=integer(AutorIO.index(tfAutor));
  when taEditora => npos:=integer(EditoraIO.index(tfEditora));
  when taIdioma => npos:=integer(IdiomaIO.index(tfIdioma));
  when taEndereco => npos:=integer(EnderecoIO.index(tfEndereco));
  when taPais => npos:=integer(PaisIO.index(tfPais));
  when taProfissao => npos:=integer(ProfissaoIO.index(tfProfissao));
  when taLivro => npos:=integer(LivroIO.index(tfLivro));
  when taLivroAss => npos:=integer(LivroAssIO.index(tfLivroAss));
  when taLivroAut => npos:=integer(LivroAutIO.index(tfLivroAut));
  when taCliente => npos:=integer(ClienteIO.index(tfCliente));
  when taUsuario => npos:=integer(UsuarioIO.index(tfUsuario));
  when taVenda => npos:=integer(VendaIO.index(tfVenda));
  when others => npos:=0;  
end case;
return npos;
end posArq;

-- ----------------------------------------------------------------------------
-- realiza a operacao de posicionar dentro do arquivo o ponteiro de pesquisa.
-- sArq - o arquivo
-- npos - a posicao do ponteiro
-- ----------------------------------------------------------------------------
procedure seekArq(sArq: in ctTArqs; npos: in integer) is
begin
case sArq is
  when taAssunto => AssuntoIO.set_index(tfAssunto,
                    AssuntoIO.Positive_Count(npos));
  when taAutor => AutorIO.set_index(tfAutor, AutorIO.Positive_Count(npos));
  when taEditora => EditoraIO.set_index(tfEditora,
                    EditoraIO.Positive_Count(npos));
  when taIdioma => IdiomaIO.set_index(tfIdioma,IdiomaIO.Positive_Count(npos));
  when taEndereco => EnderecoIO.set_index(tfEndereco,
                     EnderecoIO.Positive_Count(npos));
  when taPais => PaisIO.set_index(tfPais, PaisIO.Positive_Count(npos));
  when taProfissao => ProfissaoIO.set_index(tfProfissao,
                      ProfissaoIO.Positive_Count(npos));
  when taLivro => LivroIO.set_index(tfLivro, LivroIO.Positive_Count(npos));
  when taLivroAss => LivroAssIO.set_index(tfLivroAss, 
                     LivroAssIO.Positive_Count(npos));
  when taLivroAut => LivroAutIO.set_index(tfLivroAut, 
                     LivroAutIO.Positive_Count(npos));
  when taCliente => ClienteIO.set_index(tfCliente, 
                    ClienteIO.Positive_Count(npos));
  when taUsuario => UsuarioIO.set_index(tfUsuario, 
                    UsuarioIO.Positive_Count(npos));
  when taVenda => VendaIO.set_index(tfVenda, VendaIO.Positive_Count(npos));
  when others => null;  
end case;
end seekArq;

-- ----------------------------------------------------------------------------
-- realiza a leitura de um registro no arquivo.
-- sArq - o arquivo
-- ----------------------------------------------------------------------------
function lerArq(sArq: in ctTArqs) return ustring is
sret: ustring:=U("");
begin
case sArq is
  when taAssunto => AssuntoIO.read(tfAssunto,blAssunto); sret:=U(blAssunto);
  when taAutor => AutorIO.read(tfAutor, blAutor); sret:=U(blAutor);
  when taEditora => EditoraIO.read(tfEditora, blEditora); sret:=U(blEditora);
  when taIdioma => IdiomaIO.read(tfIdioma, blIdioma); sret:=U(blIdioma);
  when taEndereco => EnderecoIO.read(tfEndereco, blEndereco); 
                     sret:=U(blEndereco);
  when taPais => PaisIO.read(tfPais, blPais); sret:=U(blPais);
  when taProfissao => ProfissaoIO.read(tfProfissao, blProfissao); 
                      sret:=U(blProfissao);
  when taLivro => LivroIO.read(tfLivro, blLivro); sret:=U(blLivro);
  when taLivroAss => LivroAssIO.read(tfLivroAss, blLivroAss); 
                     sret:=U(blLivroAss);
  when taLivroAut => LivroAutIO.read(tfLivroAut, blLivroAut);
	             sret:=U(blLivroAut);
  when taCliente => ClienteIO.read(tfCliente, blCliente); sret:=U(blCliente);
  when taUsuario => UsuarioIO.read(tfUsuario, blUsuario); sret:=U(blUsuario);
  when taVenda => VendaIO.read(tfVenda, blVenda); sret:=U(blVenda);
  when others => sret:=U("");  
end case;
return sret;
end lerArq;
     
-- ----------------------------------------------------------------------------
-- realiza a escrita de um registro no arquivo.
-- sArq - o arquivo
-- ----------------------------------------------------------------------------
procedure gravarArq(sArq: in ctTArqs; sTexto: in ustring) is
begin
case sArq is
  when taAssunto => blAssunto:=S(sTexto) & CRLF;
                    AssuntoIO.write(tfAssunto,blAssunto);
  when taAutor => blAutor:=S(sTexto) & CRLF;
                  AutorIO.write(tfAutor, blAutor);
  when taEditora => blEditora:=S(sTexto) & CRLF;
                    EditoraIO.write(tfEditora, blEditora);
  when taIdioma => blIdioma:=S(sTexto) & CRLF;
                   IdiomaIO.write(tfIdioma, blIdioma);
  when taEndereco => blEndereco:=S(sTexto) & CRLF;
                     EnderecoIO.write(tfEndereco, blEndereco);
  when taPais => blPais:=S(sTexto) & CRLF;
                 PaisIO.write(tfPais, blPais);
  when taProfissao => blProfissao:=S(sTexto) & CRLF;
                      ProfissaoIO.write(tfProfissao, blProfissao);
  when taLivro => blLivro:=S(sTexto) & CRLF;
                  LivroIO.write(tfLivro, blLivro);
  when taLivroAss => blLivroAss:=S(sTexto) & CRLF;
                     LivroAssIO.write(tfLivroAss, blLivroAss);
  when taLivroAut => blLivroAut:=S(sTexto) & CRLF;
                     LivroAutIO.write(tfLivroAut, blLivroAut);
  when taCliente => blCliente:=S(sTexto) & CRLF;
                    ClienteIO.write(tfCliente, blCliente);
  when taUsuario => blUsuario:=S(sTexto) & CRLF;
                    UsuarioIO.write(tfUsuario, blUsuario);
  when taVenda => blVenda:=S(sTexto) & CRLF;
                  VendaIO.write(tfVenda, blVenda);
  when others => null;  
end case;
end gravarArq;

-- ----------------------------------------------------------------------------
-- Abre ou cria os arquivos do sistema.
-- bAbre - condição para abrir ou criar os arquivos do sistema
-- ----------------------------------------------------------------------------
procedure abrecriaArqs(bAbre: in boolean) is
begin
if bAbre then
  if AssuntoIO.is_open(tfAssunto)=false then
    AssuntoIO.open(tfAssunto,AssuntoIO.Inout_File,ARQ_ASSUNTO);
  else put_line(MSG_ARQERRO & " --> " & ARQ_ASSUNTO);
  end if; 
  if AutorIO.is_open(tfAutor)=false then
    AutorIO.open(tfAutor,AutorIO.Inout_File,ARQ_AUTOR);
  else put_line(MSG_ARQERRO & " --> " & ARQ_AUTOR);
  end if; 
  if EditoraIO.is_open(tfEditora)=false then
    EditoraIO.open(tfEditora,EditoraIO.Inout_File,ARQ_EDITORA);
  else put_line(MSG_ARQERRO & " --> " & ARQ_EDITORA);
  end if; 
  if IdiomaIO.is_open(tfIdioma)=false then
    IdiomaIO.open(tfIdioma,IdiomaIO.Inout_File,ARQ_IDIOMA);
  else put_line(MSG_ARQERRO & " --> " & ARQ_IDIOMA);
  end if; 
  if EnderecoIO.is_open(tfEndereco)=false then
    EnderecoIO.open(tfEndereco,EnderecoIO.Inout_File,ARQ_ENDERECO);
  else put_line(MSG_ARQERRO & " --> " & ARQ_ENDERECO);
  end if; 
  if PaisIO.is_open(tfPais)=false then
    PaisIO.open(tfPais,PaisIO.Inout_File,ARQ_PAIS);
  else put_line(MSG_ARQERRO & " --> " & ARQ_PAIS);
  end if; 
  if ProfissaoIO.is_open(tfProfissao)=false then
    ProfissaoIO.open(tfProfissao,ProfissaoIO.Inout_File,ARQ_PROFISSAO);
  else put_line(MSG_ARQERRO & " --> " & ARQ_PROFISSAO);
  end if; 
  if LivroIO.is_open(tfLivro)=false then
    LivroIO.open(tfLivro,LivroIO.Inout_File,ARQ_LIVRO);
  else put_line(MSG_ARQERRO & " --> " & ARQ_LIVRO);
  end if; 
  if LivroAssIO.is_open(tfLivroAss)=false then
    LivroAssIO.open(tfLivroAss,LivroAssIO.Inout_File,ARQ_LIVASS);
  else put_line(MSG_ARQERRO & " --> " & ARQ_LIVASS);
  end if; 
  if LivroAutIO.is_open(tfLivroAut)=false then
    LivroAutIO.open(tfLivroAut,LivroAutIO.Inout_File,ARQ_LIVAUT);
  else put_line(MSG_ARQERRO & " --> " & ARQ_LIVAUT);
  end if; 
  if ClienteIO.is_open(tfCliente)=false then
    ClienteIO.open(tfCliente,ClienteIO.Inout_File,ARQ_CLIENTE);
  else put_line(MSG_ARQERRO & " --> " & ARQ_CLIENTE);
  end if; 
  if UsuarioIO.is_open(tfUsuario)=false then
    UsuarioIO.open(tfUsuario,UsuarioIO.Inout_File,ARQ_USUARIO);
  else put_line(MSG_ARQERRO & " --> " & ARQ_USUARIO);
  end if; 
  if VendaIO.is_open(tfVenda)=false then
    VendaIO.open(tfVenda,VendaIO.Inout_File,ARQ_VENDA);
  else put_line(MSG_ARQERRO & " --> " & ARQ_VENDA);
  end if; 
else
  AssuntoIO.create(tfAssunto,AssuntoIO.Inout_File,ARQ_ASSUNTO);
  AutorIO.create(tfAutor,AutorIO.Inout_File,ARQ_AUTOR);
  EditoraIO.create(tfEditora,EditoraIO.Inout_File,ARQ_EDITORA);
  IdiomaIO.create(tfIdioma,IdiomaIO.Inout_File,ARQ_IDIOMA);
  EnderecoIO.create(tfEndereco,EnderecoIO.Inout_File,ARQ_ENDERECO);
  PaisIO.create(tfPais,PaisIO.Inout_File,ARQ_PAIS);
  ProfissaoIO.create(tfProfissao,ProfissaoIO.Inout_File,ARQ_PROFISSAO);
  LivroIO.create(tfLivro,LivroIO.Inout_File,ARQ_LIVRO);
  LivroAssIO.create(tfLivroAss,LivroAssIO.Inout_File,ARQ_LIVASS);
  LivroAutIO.create(tfLivroAut,LivroAutIO.Inout_File,ARQ_LIVAUT);
  ClienteIO.create(tfCliente,ClienteIO.Inout_File,ARQ_CLIENTE);
  UsuarioIO.create(tfUsuario,UsuarioIO.Inout_File,ARQ_USUARIO);
  VendaIO.create(tfVenda,VendaIO.Inout_File,ARQ_VENDA);
end if;
end abrecriaArqs;

-- ----------------------------------------------------------------------------
-- Fecha todos os arquivos abertos.
-- ----------------------------------------------------------------------------
procedure fechaArqs is
begin
 close(tfAssunto);
 close(tfAutor);
 close(tfEditora);
 close(tfIdioma);
 close(tfEndereco);
 close(tfPais);
 close(tfProfissao);
 close(tfLivro);
 close(tfLivroAss);
 close(tfLivroAut);
 close(tfCliente);
 close(tfUsuario);
 close(tfVenda);
end fechaArqs;

-- ----------------------------------------------------------------------------
-- Pesquisa um registro através de um valor chave num arquivo.
-- sArq - o arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o registro pesquisado
-- ----------------------------------------------------------------------------
function pesqArq(sArq: in ctTArqs; sChave: in ustring; nPosChave,
        nTamChave, nTamLinha: in integer) return ustring is
slinha: ustring;
sRes: ustring;
bQuebra: boolean;
nPosicao: integer;
begin
bQuebra:=false;
seekArq(sArq, 1);
while (not fimArq(sArq)) and (bQuebra=false) loop
  slinha:=lerArq(sArq);
  sres:=trim(copy(slinha,nPosChave,nTamChave), Both);
  if sres=sChave then
     bQuebra:=true;
  end if;
end loop;
nPosicao:=posArq(sArq)-(nTamLinha + TAM_CRLF);
if nPosicao > 0 then
   seekArq(sArq, nPosicao);
else
   seekArq(sArq, 1);
end if;
if sRes/=sChave then
   return U("");
else
   return copy(slinha,1,nTamLinha);
end if;
end pesqArq;

-- ----------------------------------------------------------------------------
-- Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
-- sArq - o arquivo
-- nTamLinha - o tamanho do registro
-- ----------------------------------------------------------------------------
procedure pesqLinhaExcluida(sArq: in ctTArqs; nTamLinha: in integer) is
sExcluido: ustring;
begin
sExcluido:=pesqArq(sArq, U("*"), 1, 1, nTamLinha);
if sExcluido=U("") then
   seekArq(sArq, tamArq(sArq));
end if;
end pesqLinhaExcluida;

-- ----------------------------------------------------------------------------
-- Pesquisa o maior código num arquivo.
-- sArq - o arquivo
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o maior código
-- ----------------------------------------------------------------------------
function pesqMaxCod(sArq: in ctTArqs; nPosChave,
        nTamChave, nTamLinha: in integer) return ustring is
slinha, sRes: ustring;
bQuebra: boolean;
nMaior, nCod: integer;
begin
bQuebra:=false;
nMaior:=0;
seekArq(sArq, 1);
while (not fimArq(sArq)) and (bQuebra=false) loop
  slinha:=lerArq(sArq);
  sres:=trim(copy(slinha,nPosChave,nTamChave), Both);
  ncod:=Value_Integer(S(sres));
  if nCod > nMaior then
     nMaior:=nCod;
  end if;
end loop;
pesqLinhaExcluida(sArq, nTamLinha);
itostr((nMaior+1),sres);
return sres;
end pesqMaxCod;

-- ----------------------------------------------------------------------------
-- Grava os registros num determinado arquivo.
-- sArq - o arquivo
-- sTexto - o registro a ser gravado
-- sMsgAcerto - a mensagem caso o registro foi gravado
-- sMsgErro - a mensagem caso o registro não foi gravado
-- ----------------------------------------------------------------------------
procedure escreveArq(sArq: in ctTArqs; sTexto: in ustring; sMsgAcerto,
	sMsgErro: in string) is
begin
gravarArq(sArq, sTexto);
-- if nStatus > 0 then
   put_line(sMsgAcerto);
-- else
--   put_line(sMsgErro);
-- end if;
end escreveArq;

-- ----------------------------------------------------------------------------
-- Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o registro montado
-- ----------------------------------------------------------------------------
function LinhaReg(sreg: in ctArqs) return ustring is
slinha: ustring;
begin
slinha:=U("");
if sreg=opAssunto then
   slinha:=esp(tAssunto.codigo,10) & esp(tAssunto.assunto,30);
elsif sreg=opAutor then
   slinha:=esp(tAutor.codigo,10) & esp(tAutor.autor,30);
elsif sreg=opEditora then
   slinha:=esp(tEditora.codigo,10) & esp(tEditora.editora,50);
elsif sreg=opEndereco then
   slinha:=esp(tEndereco.codigo,10) & esp(tEndereco.logradouro,40) & 
   esp(tEndereco.bairro,15) & esp(tEndereco.cep,8) & 
   esp(tEndereco.cidade,30) & esp(tEndereco.estado,20);
elsif sreg=opIdioma then
   slinha:=esp(tIdioma.codigo,10) & esp(tIdioma.idioma,20);
elsif sreg=opPais then
   slinha:=esp(tPais.codigo,3) & esp(tPais.pais,50);
elsif sreg=opProfissao then
   slinha:=esp(tProfissao.codigo,10) & esp(tProfissao.profissao,50);
elsif sreg=opUsuario then
   slinha:=esp(tUsuario.login,10) & esp(tUsuario.senha,10);
elsif sreg=opLivro then
   slinha:=esp(tLivro.isbn,13) & esp(tLivro.titulo,50) & esp(tLivro.edicao,10) & 
   esp(tLivro.anopubli,10) & esp(tLivro.codeditora,10) & esp(tLivro.volume,10) & 
   esp(tLivro.codidioma,10) & esp(tLivro.npaginas,10) & esp(tLivro.preco,10) & 
   esp(tLivro.qtdestoque,10);
elsif sreg=opLivroAss then
   slinha:=esp(tLivroAss.isbn,13) & esp(tlivroAss.codassunto,10);
elsif sreg=opLivroAut then
   slinha:=esp(tLivroAut.isbn,13) & esp(tlivroAut.codautor,10);
elsif sreg=opCliente then
   slinha:=esp(tCliente.cpf,14) & esp(tCliente.nome,30) & esp(tCliente.email,30) & 
   esp(tCliente.identidade,10) & esp(tCliente.sexo,1) & esp(tCliente.telefone,17) & 
   esp(tCliente.dtnascimento,10) & esp(tCliente.codendereco,10) & 
   esp(tCliente.codpais,3) & esp(tCliente.codprofissao,10);
elsif sreg=opVenda then
   slinha:=esp(tVenda.dthrvenda,19) & esp(tVenda.cpf,14) & esp(tVenda.isbn,13) & 
   esp(tVenda.precovenda,10);
end if;
return slinha;
end LinhaReg;

-- ----------------------------------------------------------------------------
-- Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o tamanho do registro
-- ----------------------------------------------------------------------------
function tamReg(sreg: in ctArqs) return integer is
nret: integer;
begin
nret:=0;
if sreg=opAssunto then nret:=TAM_ASSUNTO;
elsif sreg=opAutor then nret:=TAM_AUTOR;
elsif sreg=opEditora then nret:=TAM_EDITORA;
elsif sreg=opEndereco then nret:=TAM_ENDERECO;
elsif sreg=opIdioma then nret:=TAM_IDIOMA;
elsif sreg=opPais then nret:=TAM_PAIS;
elsif sreg=opProfissao then nret:=TAM_PROFISSAO;
elsif sreg=opUsuario then nret:=TAM_USUARIO;
elsif sreg=opLivro then nret:=TAM_LIVRO;
elsif sreg=opLivroAss then nret:=TAM_LIVASS;
elsif sreg=opLivroAut then nret:=TAM_LIVAUT;
elsif sreg=opCliente then nret:=TAM_CLIENTE;
elsif sreg=opVenda then nret:=TAM_VENDA;
end if;
return nret;
end tamReg;

-- ----------------------------------------------------------------------------
-- Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- nNum - indica qual rotulo será retornado
-- retorna - o rotulo
-- ----------------------------------------------------------------------------
function rotulo(sreg: in ctArqs; nNum: in integer) return ustring is
sret: ustring;
begin
if sreg=opAssunto then
   case nNum is
     when 0 => sret:=U("Assunto(s) não encontrado(s)!");
     when 1 => sret:=U("Código do assunto: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Assunto: ");
          g_nPosChave:=11;
          g_nTamChave:=30;
     when others => null;
   end case;
elsif sreg=opAutor then
   case nNum is
     when 0 => sret:=U("Autor(es) não encontrado(s)!");
     when 1 => sret:=U("Código do autor: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Autor: ");
          g_nPosChave:=11;
          g_nTamChave:=30;
     when others => null;
   end case;
elsif sreg=opEditora then
   case nNum is
     when 0 => sret:=U("Editora(s) não encontrada(s)!");
     when 1 => sret:=U("Código da editora: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Editora: ");
          g_nPosChave:=11;
          g_nTamChave:=50;
     when others => null;
   end case;
elsif sreg=opEndereco then
   case nNum is
     when 0 => sret:=U("Endereço(s) não encontrado(s)!");
     when 1 => sret:=U("Código do endereço: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Logradouro: ");
          g_nPosChave:=11;
          g_nTamChave:=40;
     when 3 => sret:=U("Bairro: ");
          g_nPosChave:=51;
          g_nTamChave:=15;
     when 4 => sret:=U("CEP: ");
          g_nPosChave:=66;
          g_nTamChave:=8;
     when 5 => sret:=U("Cidade: ");
          g_nPosChave:=74;
          g_nTamChave:=30;
     when 6 => sret:=U("Estado: ");
          g_nPosChave:=104;
          g_nTamChave:=20;
     when others => null;
   end case;
elsif sreg=opIdioma then
   case nNum is
     when 0 => sret:=U("Idioma(s) não encontrado(s)!");
     when 1 => sret:=U("Código do idioma: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Idioma: ");
          g_nPosChave:=11;
          g_nTamChave:=20;
     when others => null;
   end case;
elsif sreg=opPais then
   case nNum is
     when 0 => sret:=U("País(es) não encontrado(s)!");
     when 1 => sret:=U("Código do país: ");
          g_nPosChave:=1;
          g_nTamChave:=3;
     when 2 => sret:=U("País: ");
          g_nPosChave:=4;
          g_nTamChave:=50;
     when others => null;
   end case;
elsif sreg=opProfissao then
   case nNum is
     when 0 => sret:=U("Profissão(es) não encontrada(s)!");
     when 1 => sret:=U("Código da profissão: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Profissão: ");
          g_nPosChave:=11;
          g_nTamChave:=50;
     when others => null;
   end case;
elsif sreg=opUsuario then
   case nNum is
     when 0 => sret:=U("login ou senha incorreta, tente de novo!");
     when 1 => sret:=U("Login: ");
          g_nPosChave:=1;
          g_nTamChave:=10;
     when 2 => sret:=U("Senha: ");
          g_nPosChave:=11;
          g_nTamChave:=10;
     when others => null;
   end case;
elsif sreg=opLivro then
   case nNum is
     when 0 => sret:=U("Livro(s) não encontrado(s)!");
     when 1 => sret:=U("ISBN: ");
          g_nPosChave:=1;
          g_nTamChave:=13;
     when 2 => sret:=U("Título: ");
          g_nPosChave:=14;
          g_nTamChave:=50;
     when 3 => sret:=U("Edição: ");
          g_nPosChave:=64;
          g_nTamChave:=10;
     when 4 => sret:=U("Ano de Publicação: ");
          g_nPosChave:=74;
          g_nTamChave:=10;
     when 5 => sret:=U("Código da editora: ");
          g_nPosChave:=84;
          g_nTamChave:=10;
     when 6 => sret:=U("Volume: ");
          g_nPosChave:=94;
          g_nTamChave:=10;
     when 7 => sret:=U("Código do idioma: ");
          g_nPosChave:=104;
          g_nTamChave:=10;
     when 8 => sret:=U("Número de páginas: ");
          g_nPosChave:=114;
          g_nTamChave:=10;
     when 9 => sret:=U("Preço: ");
          g_nPosChave:=124;
          g_nTamChave:=10;
     when 10 => sret:=U("Qtd. Estoque: ");
           g_nPosChave:=134;
           g_nTamChave:=10;
     when others => null;
   end case;
elsif sreg=opLivroAss then
   case nNum is
     when 0 => sret:=U("Assunto(s) não encontrado(s)!");
     when 1 => sret:=U("ISBN: ");
          g_nPosChave:=1;
          g_nTamChave:=13;
     when 2 => sret:=U("Código do assunto: ");
          g_nPosChave:=14;
          g_nTamChave:=10;
     when others => null;
   end case;
elsif sreg=opLivroAut then
   case nNum is
     when 0 => sret:=U("Autor(s) não encontrado(s)!");
     when 1 => sret:=U("ISBN: ");
          g_nPosChave:=1;
          g_nTamChave:=13;
     when 2 => sret:=U("Código do autor: ");
          g_nPosChave:=14;
          g_nTamChave:=10;
     when others => null;
   end case;
elsif sreg=opCliente then
   case nNum is
     when 0 => sret:=U("Cliente(s) não encontrado(s)!");
     when 1 => sret:=U("CPF: ");
          g_nPosChave:=1;
          g_nTamChave:=14;
     when 2 => sret:=U("Nome: ");
          g_nPosChave:=15;
          g_nTamChave:=30;
     when 3 => sret:=U("E-mail: ");
          g_nPosChave:=45;
          g_nTamChave:=30;
     when 4 => sret:=U("Identidade: ");
          g_nPosChave:=75;
          g_nTamChave:=10;
     when 5 => sret:=U("Sexo: ");
          g_nPosChave:=85;
          g_nTamChave:=1;
     when 6 => sret:=U("Telefone: ");
          g_nPosChave:=86;
          g_nTamChave:=17;
     when 7 => sret:=U("Dt. Nascimento: ");
          g_nPosChave:=103;
          g_nTamChave:=10;
     when 8 => sret:=U("Código do endereço: ");
          g_nPosChave:=113;
          g_nTamChave:=10;
     when 9 => sret:=U("Código do país: ");
          g_nPosChave:=123;
          g_nTamChave:=3;
     when 10 => sret:=U("Código da Profissão: ");
           g_nPosChave:=126;
           g_nTamChave:=10;
     when others => null;
   end case;
elsif sreg=opVenda then
   case nNum is
     when 0 => sret:=U("Venda(s) não encontrada(s)!");
     when 1 => sret:=U("Data/Hora venda: ");
          g_nPosChave:=1;
          g_nTamChave:=19;
     when 2 => sret:=U("CPF: ");
          g_nPosChave:=20;
          g_nTamChave:=14;
     when 3 => sret:=U("ISBN: ");
          g_nPosChave:=34;
          g_nTamChave:=13;
     when 4 => sret:=U("Preço de venda: ");
          g_nPosChave:=47;
          g_nTamChave:=10;
     when others => null;
   end case;
end if;

return sret;
end rotulo;

-- ----------------------------------------------------------------------------
-- Indica se continua ou não mostrando um número máximo de linhas.
-- nlinha - a linha a ser continuada
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se continua ou não
-- ----------------------------------------------------------------------------
function ContinuaSN(nlinha, nQtdLinha: in integer) return boolean is
bSOp, bret: boolean;
opCSubMenu: character;
begin
bret:=false;
if nlinha > 0 then
  if (nlinha mod nQtdLinha) = 0 then
      bSOp:=true;
      while(bSOp) loop
        menu(13);
        get_line(opCSubMenu);
        if (opCSubMenu='S') or (opCSubMenu='s') then bSOp:=false;
        elsif (opCSubMenu='N') or (opCSubMenu='n') then
          bret:=true;
          bSOp:=false;
        else put_line(MSG_ERRO);
        end if; 
      end loop;
  end if;
end if;

return bret;
end ContinuaSN;
-- ----------------------------------------------------------------------------
-- Lista vários registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se encontrou algum registro
-- ----------------------------------------------------------------------------
function ListarTodos(sArq: in ctTArqs; sreg: in ctArqs; sChave: in ustring;
   nPosChave, nTamChave, nTamLinha, nQtdLinha: in integer;
   bPesqRelativa: in boolean) return boolean is
slinha: ustring;
bQuebra, bAchou, bRet: boolean;
nCont: integer;
sres: ustring;
begin
bRet:=false;
bQuebra:=false;
nCont:=0;
mostrarDados(sreg, U(""), 2);
seekArq(sArq, 1);
while (not fimArq(sArq)) and (bQuebra=false) loop
  slinha:=lerArq(sArq);

  if bPesqRelativa then
    sres:=trim(copy(slinha,nPosChave,nTamChave), Both);
    if strRelativa(sres,sChave) then 
       bAchou:=true;
       bRet:=true;
    else
       bAchou:=false;
    end if;
  else
    bAchou:=true;
    bRet:=true;
  end if;

  if bAchou then
    mostrarDados(sreg, copy(slinha,1,nTamLinha), 3);
    nCont:=nCont+1;
  end if;

  bQuebra:=ContinuaSN(nCont, nQtdLinha);
end loop;
return bret;
end ListarTodos;

-- ----------------------------------------------------------------------------
-- Lista vários registros entre arquivos de acordo com a pesquisa feita.
-- sArq1 - o arquivo de ligação
-- sreg1 - o tipo de arquivo de ligação
-- nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
-- nTamChave1 - o tamanho da primeira chave no arquivo de ligação
-- nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
-- nTamChave2 - o tamanho da segunda chave do arquivo de ligação
-- sChave - a chave a ser pesquisada no arquivo de ligação
-- sArq2 - o arquivo a ser pesquisado
-- sreg2 - o tipo de arquivo a ser pesquisado
-- nPosChave3 - a posicao inicial da chave do arquivo pesquisado
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- ----------------------------------------------------------------------------
procedure ListarRegLigados(sArq1: in ctTArqs; sreg1: in ctArqs; nPosChave1,
nTamChave1, nPosChave2, nTamChave2: in integer; sChave: ustring;
sArq2: in ctTArqs; sreg2: in ctArqs; nPosChave3, nQtdLinha: in integer) is
slinha1: ustring;
bQuebra, bRet: boolean;
nCont: integer;
sCodigo1, sCodigo2, slinha2: ustring;
begin
bRet:=false;
nCont:=0;
bQuebra:=false;
mostrarDados(sreg2, U(""), 2);
seekArq(sArq1, 1);
while (not fimArq(sArq1)) and (bQuebra=false) loop
  slinha1:=lerArq(sArq1);
  sCodigo1:=trim(copy(slinha1,nPosChave1,nTamChave1), Both);
  if sCodigo1=sChave then
    sCodigo2:=trim(copy(slinha1,nPosChave2,nTamChave2), Both);
    slinha2:=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
    mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
    bRet:=true;
    nCont:=nCont+1;
  end if;
  bQuebra:=ContinuaSN(nCont, nQtdLinha);
end loop;
if bRet=false then
   put_line(rotulo(sreg2,0));
end if;
end ListarRegLigados;

-- ----------------------------------------------------------------------------
-- Valida a entrada de registros de acordo com a pesquisa feita.
-- sArq - o arquivo
-- sreg - o tipo de arquivo
-- nTexto - o numero do rótulo da entrada
-- sEntrada - a chave a ser pesquisada e validada
-- nTentativas - o número máximo de tentativas
-- bPesqRelativa - indica se vai realizar uma pesquisa relativa
-- bTipoEntrada - indica o tipo de entrada
-- retorna - o registro pesquisado e validado
-- ----------------------------------------------------------------------------
function validaEntrada(sArq: in ctTArqs; sreg: in ctArqs; nTexto: in integer;
        sEntrada: in ustring; nTentativas: in integer;
        bPesqRelativa: in boolean; bTipoEntrada: in ctTipo) return ustring is
bQuebra: boolean;
sres, sTexto, sMsgErro: ustring;
ncont, nPosChave, nTamChave, nTamLinha: integer;
slocal: ustring;
begin
nTamLinha:=tamReg(sreg);
sMsgErro:=rotulo(sreg,0);
sTexto:=rotulo(sreg,nTexto);
nPosChave:=g_nPosChave;
nTamChave:=g_nTamChave;

ncont:=1;
bQuebra:=false;
  while (bQuebra=false) and (ncont <= nTentativas ) loop
    if bTipoEntrada=opTexto then
      put(sTexto);
      get_line(slocal);
    elsif bTipoEntrada=opNumero then
       slocal:=validaNumero(sTexto, sEntrada);
    elsif bTipoEntrada=opData then
       slocal:=validaDataHora(sTexto, sEntrada, true);
    elsif bTipoEntrada=opDataHora then
       slocal:=validaDataHora(sTexto, sEntrada, false);
    elsif bTipoEntrada=opSenha then
       slocal:=digitaSenha(sTexto, 10);
    end if;

    if bPesqRelativa then
       if ListarTodos(sArq, sreg, slocal, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, true) then
         sres:=U(" ");
       end if;
    else
       sres:=pesqArq(sArq, slocal, nPosChave, nTamChave, nTamLinha);
    end if;

    if sres=U("") then
       put_line(sMsgErro);
    else
       bQuebra:=true;
    end if;

    ncont:=ncont+1;
  end loop;
return sres;
end validaEntrada;

-- ----------------------------------------------------------------------------
-- Mostra a tela de splash do sistema.
-- ----------------------------------------------------------------------------
procedure frmSplash is
 cont: integer := 0;
 ch: character;
begin
 Put_Line("*---------------------------------------" &
 "-------------------------------------*");
 Put_Line("| LL    II VV   VV RRRRR  UU  UU   SSSS " &
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |");
 Put_Line("| LL    II  VV VV  RR   R UU  UU  SS    " &
 " VV VV  II RR   R  TT  UU  UU  SS    |");
 Put_Line("| LL    II   VVV   RRRRR  UU  UU    SS  " &
 "  VVV   II RRRRR   TT  UU  UU    SS  |");
 Put_Line("| LLLLL II    V    RR   R  UUUU  SSSS   " &
 "   V    II RR   R  TT   UUUU  SSSS   |");
 Put_Line("*---------------------------------------" &
 "-------------------------------------*");
 for cont in 1..18 loop 
   Put_Line("");
 end loop;
 Put(MSG_PRESS);
 get_immediate(ch);
 Put_Line("");
end frmSplash;

-- ----------------------------------------------------------------------------
-- Mostra a tela de sobre do sistema.
-- ----------------------------------------------------------------------------
procedure frmSobre is
cont: integer:=0;
ch: character;
begin
 put_line("*------------------------------------------------------------*");
 put_line("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |");
 put_line("|  LL        II   VV     VV   RR     R  UU    UU  SS         |");
 put_line("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |");
 put_line("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |");
 put_line("|  LLLL      II      VVV      RR RR     UU    UU        SS   |");
 put_line("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |");
 put_line("|                                                            |");
 put_line("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |");
 put_line("|   VV     VV   II  RR     R     TT     UU    UU  SS         |");
 put_line("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |");
 put_line("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |");
 put_line("|      VVV      II  RR RR        TT     UU    UU        SS   |");
 put_line("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |");
 put_line("|                                                            |");
 put_line("|                                               Versao 1.0.0 |");
 put_line("| Sistema integrante do projeto Livrus Virtus.               |");
 put_line("| Todos os direitos reservados para Henrique F. de Souza.    |");
 put_line("| Versao programada na linguagem ada.                        |");
 put_line("*------------------------------------------------------------*");
 for cont in 1..4 loop 
   put_line("");
 end loop; 
 put(MSG_PRESS);
 get_immediate(ch);
 Put_Line("");
end frmSobre;

-- ----------------------------------------------------------------------------
-- Mostra a tela de login do sistema.
-- retorna - se o login foi validado corretamente
-- ----------------------------------------------------------------------------
function frmLogin return boolean is
bret: boolean;
slinha: ustring;
begin
  bret:=false;
  put_line("*--------------------------------------------------------------*");
  put_line("| Login do sistema                                             |");
  put_line("*--------------------------------------------------------------*");
  slinha:=validaEntrada(taUsuario, opUsuario, 1, tUsuario.login, 3,
        false, opTexto);
  if slinha/=U("") then
     slinha:=validaEntrada(taUsuario, opUsuario, 2, tUsuario.senha, 3,
        false, opSenha);
     if slinha/=U("") then
        tUsuario.login:=trim(copy(slinha, 1, 10), Both);
        tUsuario.senha:=trim(copy(slinha, 11, 10), Both);
        bret:=true;
     end if;
  end if;
  put_line("");
  return bret;
end frmLogin;

-- ----------------------------------------------------------------------------
-- Mostra os menus do sistema.
-- num - o número do menu
-- ----------------------------------------------------------------------------
procedure menu(num: in integer) is
begin
 if (num=1) then
  put_line("*--------------------------------------------------------------*");
  put_line("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |");
  put_line("*--------------------------------------------------------------*");
 elsif (num=2) then
   put_line("*---------------------------------*");
   put_line("| 01. Cadastro de Assuntos        |");
   put_line("| 02. Cadastro de Autores         |");
   put_line("| 03. Cadastro de Editoras        |");
   put_line("| 04. Cadastro de Endereços       |");
   put_line("| 05. Cadastro de Idiomas         |");
   put_line("| 06. Cadastro de Países          |");
   put_line("| 07. Cadastro de Profissões      |");
   put_line("| 08. Cadastro de Clientes        |");
   put_line("| 09. Cadastro de Livros          |");
   put_line("| 10. Voltar ao menu              |");
   put_line("*---------------------------------*");
 elsif (num=3) then
   put_line("*---------------------------------*");
   put_line("| 01. Consulta de Assuntos        |");
   put_line("| 02. Consulta de Autores         |");
   put_line("| 03. Consulta de Editoras        |");
   put_line("| 04. Consulta de Endereços       |");
   put_line("| 05. Consulta de Idiomas         |");
   put_line("| 06. Consulta de Países          |");
   put_line("| 07. Consulta de Profissões      |");
   put_line("| 08. Consulta de Clientes        |");
   put_line("| 09. Consulta de Livros          |");
   put_line("| 10. Voltar ao menu              |");
   put_line("*---------------------------------*");
 elsif (num=4) then
   put_line("*---------------------------------*");
   put_line("| 01. Vender Livros               |");
   put_line("| 02. Vendas Realizadas           |");
   put_line("| 03. Voltar ao menu              |");
   put_line("*---------------------------------*");
 elsif (num=5) then
   put_line("*---------------------------------*");
   put_line("| 01. Alterar senha               |");
   put_line("| 02. Sobre o sistema             |");
   put_line("| 03. Sair do sistema             |");
   put_line("| 04. Voltar ao menu              |");
   put_line("*---------------------------------*");
 elsif (num=6) then
   put_line("*--------------------------------------------------------------*");
   put_line("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=7) then
   put_line("*--------------------------------------------------------------*");
   put_line("| (1) Salvar inclusão       (2) Voltar ao menu                 |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=8) then
   put_line("*--------------------------------------------------------------*");
   put_line("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=9) then
   put_line("*--------------------------------------------------------------*");
   put_line("| (1) Salvar alteração      (2) Voltar ao menu                 |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=10) then
   put_line("*--------------------------------------------------------------*");
   put_line("| Certeza de excluir? (S/N)                                    |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=11) then
   put_line("*--------------------------------------------------------------*");
   put_line("| Deseja sair do sistema? (S/N)                                |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=12) then
   put_line("*--------------------------------------------------------------*");
   put_line("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=13) then
   put_line("*--------------------------------------------------------------*");
   put_line("| Deseja continuar? (S/N)                                      |");
   put_line("*--------------------------------------------------------------*");
 elsif (num=14) then
   put_line("*--------------------------------------------------------------*");
   put_line("| Salvar inclusão (S/N)                                        |");
   put_line("*--------------------------------------------------------------*");
 end if;
 put(MSG_OPCAO);
end menu;

-- ----------------------------------------------------------------------------
-- Realiza os cadastros de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure frmCadastros(sreg: in ctArqs; sacao: in ctAcao) is
slinha: ustring;
begin
if sreg=opAssunto then
   if sacao=opNovo then
      tAssunto.codigo:=pesqMaxCod(taAssunto, 1, 10, tamReg(sreg));
      mostrarDados(sreg, U(""), 1);
      subMenu(7, sreg);
   elsif sacao=opPesquisar then
     slinha:=validaEntrada(taAssunto,sreg,1,tAssunto.codigo,1,false,opNumero);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opAutor then
   if sacao=opNovo then
      tAutor.codigo:=pesqMaxCod(taAutor, 1, 10, tamReg(sreg));
      mostrarDados(sreg, U(""), 1);
      subMenu(7, sreg);
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taAutor, sreg, 1, tAutor.codigo,1,false,opNumero);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opEditora then
   if sacao=opNovo then
      tEditora.codigo:=pesqMaxCod(taEditora, 1, 10, tamReg(sreg));
      mostrarDados(sreg, U(""), 1);
      subMenu(7, sreg);
   elsif sacao=opPesquisar then
     slinha:=validaEntrada(taEditora,sreg,1,tEditora.codigo,1,false,opNumero);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opEndereco then
   if sacao=opNovo then
      tEndereco.codigo:=pesqMaxCod(taEndereco, 1, 10, tamReg(sreg));
      mostrarDados(sreg, U(""), 1);
      subMenu(7, sreg);
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taEndereco,sreg,1,tEndereco.codigo,1,
              false,opNumero);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opIdioma then
   if sacao=opNovo then
      tIdioma.codigo:=pesqMaxCod(taIdioma, 1, 10, tamReg(sreg));
      mostrarDados(sreg, U(""), 1);
      subMenu(7, sreg);
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taIdioma,sreg,1,tIdioma.codigo,1,false,opNumero);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opPais then
   if sacao=opNovo then
      put(rotulo(sreg, 1));
      get_line(tPais.codigo);
      slinha:=pesqArq(taPais, tPais.codigo, 1, 3, tamReg(sreg));
      if slinha=U("") then
         pesqLinhaExcluida(taPais, tamReg(sreg));
         mostrarDados(sreg, U(""), 1);
         subMenu(7, sreg);
      else put_line(MSG_REGEXST);
      end if;
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taPais, sreg, 1, tPais.codigo, 1, false, opTexto);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      put_line(rotulo(sreg, 1) & tPais.codigo);
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opProfissao then
   if sacao=opNovo then
      tProfissao.codigo:=pesqMaxCod(taProfissao, 1, 10, tamReg(sreg));
      mostrarDados(sreg, U(""), 1);
      subMenu(7, sreg);
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taProfissao,sreg,1,tProfissao.codigo,1,
              false,opNumero);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opLivro then
   if sacao=opNovo then
      put(rotulo(sreg, 1));
      get_line(tLivro.isbn);
      if validaISBN(tLivro.isbn) then
          slinha:=pesqArq(taLivro, tLivro.isbn, 1, 13, tamReg(sreg));
          if slinha=U("") then
             pesqLinhaExcluida(taLivro, tamReg(sreg));
             mostrarDados(sreg, U(""), 1);
             subMenu(7, sreg);
             frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
             frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
          else put_line(MSG_REGEXST);
          end if;
      else put_line(MSG_ISBNINV);
      end if; 
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taLivro, sreg, 1, tLivro.isbn, 1,false,opTexto);
      if slinha/=U("") then
         mostrarDados(sreg, U(""), 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      put_line(rotulo(sreg, 1) & tLivro.isbn);
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      put_line("Assuntos dos livros excluídos, inclua novos!");
      frmCadLigados(opLivroAss, opNovo, tLivro.isbn);
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
      put_line("Autores dos livros excluídos, inclua novos!");
      frmCadLigados(opLivroAut, opNovo, tLivro.isbn);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
      put_line("Assuntos dos livros sendo excluídos!");
      frmCadLigados(opLivroAss, opExcluir, tLivro.isbn);
      put_line("Autores dos livros sendo excluídos!");
      frmCadLigados(opLivroAut, opExcluir, tLivro.isbn);
   end if;
elsif sreg=opCliente then
   if sacao=opNovo then
      put(rotulo(sreg, 1));
      get_line(tCliente.cpf);
      if validaCPF(tCliente.cpf) then
          slinha:=pesqArq(taCliente, tCliente.cpf, 1, 14, tamReg(sreg));
          if slinha=U("") then
             pesqLinhaExcluida(taCliente, tamReg(sreg));
             mostrarDados(sreg, U(""), 1);
             subMenu(7, sreg);
          else put_line(MSG_REGEXST);
          end if; 
      else put_line(MSG_CPFINV);
      end if;
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taCliente, sreg, 1, tCliente.cpf,1,false,opTexto);
      if slinha/=U("") then
         mostrarDados(sreg, U(""), 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      end if;
   elsif sacao=opAlterar then
      put_line(rotulo(sreg, 1) & tCliente.cpf);
      mostrarDados(sreg, U(""), 1);
      subMenu(9, sreg);
   elsif sacao=opExcluir then
      subMenu(10, sreg);
   end if;
elsif sreg=opVenda then
   if sacao=opNovo then
      tVenda.dthrvenda:=retDataHora;
      put_line(rotulo(sreg, 1) & tVenda.dthrvenda);
      slinha:=pesqArq(taVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
      if slinha=U("") then
         slinha:=validaEntrada(taCliente,opCliente,1,tVenda.cpf,3,
                 false,opTexto);
         if slinha/=U("") then
            tVenda.cpf:=trim(copy(slinha,1,14), Both);
            if validaCPF(tVenda.cpf) then
               put(" " & rotulo(opCliente, 2)); -- Nome --
               put_line(copy(slinha, g_nPosChave, g_nTamChave));
               frmCadLigados(opVenda, opNovo, tVenda.cpf);
            else put_line(MSG_CPFINV);
            end if;
         end if;
      else put_line(MSG_REGEXST);
      end if;
   elsif sacao=opPesquisar then
      slinha:=validaEntrada(taVenda, sreg, 1, tVenda.dthrvenda,1,
              false,opDataHora);
      if slinha/=U("") then
        mostrarDados(sreg, U(""), 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end if;
   end if;
end if;

end frmCadastros;

-- ----------------------------------------------------------------------------
-- Realiza as consultas de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure frmConsultas(sreg: in ctArqs; sacao: in ctAcao) is
slinha: ustring;
begin
if sreg=opAssunto then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taAssunto,sreg,2,tAssunto.assunto,1,true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taAssunto, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opAutor then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taAutor,sreg, 2, tAutor.autor, 1, true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taAutor, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opEditora then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taEditora,sreg,2,tEditora.editora,1,true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taEditora, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opEndereco then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taEndereco,sreg,2,tEndereco.Logradouro,1,
              true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taEndereco, sreg, U(""), 0, 0, tamReg(sreg),
         3, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opIdioma then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taIdioma, sreg, 2, tIdioma.idioma,1,true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taIdioma, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opPais then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taPais, sreg, 2, tPais.pais, 1, true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taPais, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opProfissao then
   if sacao=opPesquisar then
     slinha:=validaEntrada(taProfissao,sreg,2,tProfissao.profissao,1,
             true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taProfissao, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opLivro then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taLivro, sreg, 2, tLivro.titulo, 1, true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taLivro, sreg, U(""), 0, 0, tamReg(sreg),
        1, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opCliente then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taCliente, sreg, 2, tCliente.nome,1,true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taCliente, sreg, U(""), 0, 0, tamReg(sreg),
        1, false) = false then
        put_line(rotulo(sreg, 0));
      end if;
   end if;
elsif sreg=opVenda then
   if sacao=opPesquisar then
      slinha:=validaEntrada(taVenda, sreg, 2, tVenda.cpf, 1, true,opTexto);
   elsif sacao=opListarTodos then
      if ListarTodos(taVenda, sreg, U(""), 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        put_line(rotulo(sreg, 0));
      end if; 
   end if;
end if;
if slinha=U("") then
   put("");
end if;
end frmConsultas;

-- ----------------------------------------------------------------------------
-- Mostra a tela de alteração de senha do sistema e realiza a alteração.
-- ----------------------------------------------------------------------------
procedure frmAlterarSenha is
bQuebra: boolean;
sres, sSenhaAtual, sNovaSenha, sConfirmaSenha: ustring;
nopcao: integer;
begin
put_line(rotulo(opUsuario, 1) & tUsuario.login);
nopcao:=1;
bQuebra:=false;
while (bQuebra=false) loop
  case nopcao is
     when 1 =>
       sSenhaAtual:=digitaSenha(U("Senha Atual: "),10);
       if sSenhaAtual/=tUsuario.senha then
          put_line(MSG_SENCONFERE);
          bQuebra:=true;
       else nopcao:=2;
       end if;
   when 2 =>
       sNovaSenha:=digitaSenha(U("Nova Senha: "),10);
       sConfirmaSenha:=digitaSenha(U("Confirma Senha: "),10);
       if sNovaSenha/=sConfirmaSenha then
          put_line(MSG_SENCONFIRM);
          bQuebra:=true;
       else nopcao:=3;
       end if;
   when 3 =>
       sres:=pesqArq(taUsuario, tUsuario.login, 1, 10, tamReg(opUsuario));
       if sres=U("") then
         put_line(MSG_LOGINENCON);
       else
         tUsuario.senha:=sConfirmaSenha;
         subMenu(9,opUsuario);
         bQuebra:=true;
       end if;
   when others => null;
  end case;
end loop;

end frmAlterarSenha;
-- ----------------------------------------------------------------------------
-- Executa uma ação de gravação de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
procedure btnAcao(sreg: in ctArqs; sacao: in ctAcao) is
begin
if sreg=opAssunto then
   if sacao=opSalvarInclusao then
      escreveArq(taAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taAssunto, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opAutor then
   if sacao=opSalvarInclusao then
      escreveArq(taAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taAutor, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opEditora then
   if sacao=opSalvarInclusao then
      escreveArq(taEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taEditora, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opEndereco then
   if sacao=opSalvarInclusao then
      escreveArq(taEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taEndereco, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opIdioma then
   if sacao=opSalvarInclusao then
      escreveArq(taIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taIdioma, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opPais then
   if sacao=opSalvarInclusao then
      escreveArq(taPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taPais, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opProfissao then
   if sacao=opSalvarInclusao then
      escreveArq(taProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taProfissao, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opLivro then
   if sacao=opSalvarInclusao then
      escreveArq(taLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taLivro, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opLivroAss then
   if sacao=opSalvarInclusao then
      escreveArq(taLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taLivroAss, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opLivroAut then
   if sacao=opSalvarInclusao then
      escreveArq(taLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taLivroAut, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opCliente then
   if sacao=opSalvarInclusao then
      escreveArq(taCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taCliente, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opVenda then
   if sacao=opSalvarInclusao then
      escreveArq(taVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC);
   elsif sacao=opSalvarAlteracao then
      escreveArq(taVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   elsif sacao=opConfirmaExclusao then
      escreveArq(taVenda, repete("*",tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
   end if;
elsif sreg=opUsuario then
   if sacao=opSalvarAlteracao then
      escreveArq(taUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
   end if;
end if;
end btnAcao;
-- ----------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-- ----------------------------------------------------------------------------
procedure subMenu(nmenu: in integer; sreg: in ctArqs) is
opSubMenu: character;
opCSubMenu: character;
bSOp: boolean;
begin
bSOp:=true;
case nmenu is
 when 6 =>
    while(bSOp) loop
       menu(nmenu);
       get_line(opSubMenu);
       case(opSubMenu) is
          when '1' => frmCadastros(sreg, opNovo);
          when '2' => frmCadastros(sreg, opPesquisar);
          when '3' => bSOp:=false;
          when others => put_line(MSG_ERRO);
       end case;
    end loop;
 when 7 =>
    while(bSOp) loop
       menu(nmenu);
       get_line(opSubMenu);
       case(opSubMenu) is
          when '1' => btnAcao(sreg, opSalvarInclusao); bSOp:=false;
          when '2' => bSOp:=false;
          when others => put_line(MSG_ERRO);
       end case;
    end loop;
 when 8 =>
    while(bSOp) loop
     menu(nmenu);
     get_line(opSubMenu);
     case(opSubMenu) is
      when '1' => frmCadastros(sreg, opAlterar); bSOp:=false;
      when '2' => frmCadastros(sreg, opExcluir); bSOp:=false;
      when '3' => bSOp:=false;
      when others => put_line(MSG_ERRO);
     end case;
    end loop;
 when 9 =>
    while(bSOp) loop
       menu(nmenu);
       get_line(opSubMenu);
       case(opSubMenu) is
          when '1' => btnAcao(sreg, opSalvarAlteracao); bSOp:=false;
          when '2' => bSOp:=false;
          when others => put_line(MSG_ERRO);
       end case;
    end loop;
 when 10 =>
    while(bSOp) loop
       menu(nmenu);
       get_line(opCSubMenu);
       if (opCSubMenu='S') or (opCSubMenu='s') then
          btnAcao(sreg, opConfirmaExclusao);
          bSOp:=false;
       elsif (opCSubMenu='N') or (opCSubMenu='n') then bSOp:=false;
       else put_line(MSG_ERRO);
       end if;
    end loop;
 when 12 =>
    while(bSOp) loop
       menu(nmenu);
       get_line(opSubMenu);
       case(opSubMenu) is
          when '1' => frmConsultas(sreg, opPesquisar);
          when '2' => frmConsultas(sreg, opListarTodos);
          when '3' => bSOp:=false;
          when others => put_line(MSG_ERRO);
       end case;
    end loop;
 when 14 =>
    while(bSOp) loop
       menu(nmenu);
       get_line(opCSubMenu);
       if (opCSubMenu='S') or (opCSubMenu='s') then
          btnAcao(sreg, opSalvarInclusao);
          bSOp:=false;
          g_SalvarInclusao:=true;
       elsif (opCSubMenu='N') or (opCSubMenu='n') then bSOp:=false;
       else put_line(MSG_ERRO);
       end if;
    end loop;
 when others => null;
end case;

end subMenu;
-- ----------------------------------------------------------------------------
-- Seleciona o submenu e/ou a tela certa de acordo com número do menu.
-- nmenu - o número do menu
-- ----------------------------------------------------------------------------
procedure usaMenu(num: in integer) is
opSubMenu: ustring;
bSOp: boolean;
opSair: character;
begin
 bSOp:=true;
 if num = 1 then --  Cadastros --
   while(bSOp) loop
     menu(2);
     get_line(opSubMenu);
     if opSubMenu = U("1") then subMenu(6, opAssunto);
     elsif opSubMenu = U("2") then subMenu(6, opAutor);
     elsif opSubMenu = U("3") then subMenu(6, opEditora);
     elsif opSubMenu = U("4") then subMenu(6, opEndereco);
     elsif opSubMenu = U("5") then subMenu(6, opIdioma);
     elsif opSubMenu = U("6") then subMenu(6, opPais);
     elsif opSubMenu = U("7") then subMenu(6, opProfissao);
     elsif opSubMenu = U("8") then subMenu(6, opCliente);
     elsif opSubMenu = U("9") then subMenu(6, opLivro);
     elsif opSubMenu = U("10") then bSOp:=false;
     else put_line(MSG_ERRO);
     end if;
   end loop;
 elsif num = 2 then --  Pesquisas --
   while(bSOp) loop
     menu(3);
     get_line(opSubMenu);
     if opSubMenu = U("1") then subMenu(12, opAssunto);
     elsif opSubMenu = U("2") then subMenu(12, opAutor);
     elsif opSubMenu = U("3") then subMenu(12, opEditora);
     elsif opSubMenu = U("4") then subMenu(12, opEndereco);
     elsif opSubMenu = U("5") then subMenu(12, opIdioma);
     elsif opSubMenu = U("6") then subMenu(12, opPais);
     elsif opSubMenu = U("7") then subMenu(12, opProfissao);
     elsif opSubMenu = U("8") then subMenu(12, opCliente);
     elsif opSubMenu = U("9") then subMenu(12, opLivro);
     elsif opSubMenu = U("10") then bSOp:=false;
     else put_line(MSG_ERRO);
     end if;
   end loop;
 elsif num = 3 then --  Vendas --
   while(bSOp) loop
     menu(4);
     get_line(opSubMenu);
     if opSubMenu = U("1") then subMenu(6, opVenda);
     elsif opSubMenu = U("2") then subMenu(12, opVenda);
     elsif opSubMenu = U("3") then bSOp:=false;
     else put_line(MSG_ERRO);
     end if;
   end loop;
 elsif num = 4 then --  Opcoes --
   while(bSOp) loop
     menu(5);
     get_line(opSubMenu);
     if opSubMenu = U("1") then frmAlterarSenha;
     elsif opSubMenu = U("2") then frmSobre;
     elsif opSubMenu = U("3") then
         menu(11);
         get_line(opSair);
         if (opSair='S') or (opSair='s') then
            fechaArqs;
            bopcao:=false;
            bSOp:=false;
         end if;
     elsif opSubMenu = U("4") then bSOp:=false;
     else put_line(MSG_ERRO);
     end if;
   end loop;
 end if;
end usaMenu;

-- ----------------------------------------------------------------------------
-- Mostra as entradas e as saídas do sistema.
-- sreg - o tipo de arquivo
-- slinha - o registro com os dados
-- nOpcao - indica qual opção será mostrada
-- ----------------------------------------------------------------------------
procedure mostrarDados(sreg: in ctArqs; slinha: in ustring; 
          nOpcao: in integer) is
begin
if sreg=opAssunto then
   case nOpcao is
    when 1 =>
        put_line(rotulo(sreg, 1) & tAssunto.codigo);
        put(rotulo(sreg, 2));
        get_line(tAssunto.assunto);
    when 2 =>
        put_line("Código     Assunto");
        put_line("------     -------");
    when 3 =>
        tAssunto.codigo:=copy(slinha, 1, 10);
        tAssunto.assunto:=copy(slinha, 11, 30);
        put_line(tAssunto.codigo & " " & tAssunto.assunto);
    when others => null;
   end case;
elsif sreg=opAutor then
   case nOpcao is
    when 1 =>
        put_line(rotulo(sreg, 1) & tAutor.codigo);
        put(rotulo(sreg, 2));
        get_line(tAutor.autor);
    when 2 =>
        put_line("Código     Autor");
        put_line("------     -----");
    when 3 =>
        tAutor.codigo:=copy(slinha, 1, 10);
        tAutor.autor:=copy(slinha, 11, 30);
        put_line(tAutor.codigo & " " & tAutor.autor);
    when others => null;
   end case;
elsif sreg=opEditora then
   case nOpcao is
    when 1 =>
        put_line(rotulo(sreg, 1) & tEditora.codigo);
        put(rotulo(sreg, 2));
        get_line(tEditora.editora);
    when 2 =>
        put_line("Código     Editora");
        put_line("------     -------");
    when 3 =>
        tEditora.codigo:=copy(slinha, 1, 10);
        tEditora.editora:=copy(slinha, 11, 50);
        put_line(tEditora.codigo & " " & tEditora.editora);
    when others => null;
   end case;
elsif sreg=opEndereco then
   case nOpcao is
    when 1 =>
        put_line(rotulo(sreg, 1) & tEndereco.codigo);
        put(rotulo(sreg, 2));
        get_line(tEndereco.Logradouro);
        put(rotulo(sreg, 3));
        get_line(tEndereco.bairro);
        put(rotulo(sreg, 4));
        get_line(tEndereco.cep);
        put(rotulo(sreg, 5));
        get_line(tEndereco.cidade);
        put(rotulo(sreg, 6));
        get_line(tEndereco.estado);
    when 3 =>
        tEndereco.codigo:=trim(copy(slinha, 1, 10), Both);
        tEndereco.logradouro:=trim(copy(slinha, 11, 40), Both);
        tEndereco.bairro:=trim(copy(slinha, 51, 15), Both);
        tEndereco.cep:=trim(copy(slinha, 66, 8), Both);
        tEndereco.cidade:=trim(copy(slinha, 74, 30), Both);
        tEndereco.estado:=trim(copy(slinha, 104, 20), Both);
        put_line("--------------------");
        put_line(rotulo(sreg, 1) & tEndereco.codigo);
        put_line(rotulo(sreg, 2) & tEndereco.Logradouro);
        put_line(rotulo(sreg, 3) & tEndereco.bairro);
        put_line(rotulo(sreg, 4) & tEndereco.cep);
        put_line(rotulo(sreg, 5) & tEndereco.cidade);
        put_line(rotulo(sreg, 6) & tEndereco.estado);
    when others => null;
   end case;
elsif sreg=opIdioma then
   case nOpcao is
    when 1 =>
        put_line(rotulo(sreg, 1) & tIdioma.codigo);
        put(rotulo(sreg, 2));
        get_line(tIdioma.idioma);
    when 2 =>
        put_line("Código     Idioma");
        put_line("------     ------");
    when 3 =>
        tIdioma.codigo:=copy(slinha, 1, 10);
        tIdioma.idioma:=copy(slinha, 11, 20);
        put_line(tIdioma.codigo & " " & tIdioma.idioma);
    when others => null;
   end case;
elsif sreg=opPais then
   case nOpcao is
    when 1 =>
        put(rotulo(sreg, 2));
        get_line(tPais.pais);
    when 2 =>
        put_line("Código País");
        put_line("------ ----");
    when 3 =>
        tPais.codigo:=copy(slinha, 1, 3);
        tPais.pais:=copy(slinha, 4, 50);
        put_line(tPais.codigo & "    " & tPais.pais);
    when others => null;
   end case;
elsif sreg=opProfissao then
   case nOpcao is
    when 1 =>
        put_line(rotulo(sreg, 1) & tProfissao.codigo);
        put(rotulo(sreg, 2));
        get_line(tProfissao.profissao);
    when 2 =>
        put_line("Código     Profissão");
        put_line("------     ---------");
    when 3 =>
        tProfissao.codigo:=copy(slinha, 1, 10);
        tProfissao.profissao:=copy(slinha, 11, 50);
        put_line(tProfissao.codigo & " " & tProfissao.profissao);
    when others => null;
   end case;
elsif sreg=opLivro then
   case nOpcao is
    when 1 =>
        put(rotulo(sreg, 2));
        get_line(tLivro.titulo);
        tLivro.edicao:=validaNumero(rotulo(sreg, 3), tLivro.edicao);
        tLivro.anopubli:=validaNumero(rotulo(sreg, 4), tLivro.anopubli);
        mostrarSubDados(opLivro, opEditora, false);
        tLivro.volume:=validaNumero(rotulo(sreg, 6), tLivro.volume);
        mostrarSubDados(opLivro, opIdioma, false);
        tLivro.npaginas:=validaNumero(rotulo(sreg, 8), tLivro.npaginas);
        tLivro.preco:=validaNumero(rotulo(sreg, 9), tLivro.preco);
        tLivro.qtdestoque:=validaNumero(rotulo(sreg, 10), tLivro.qtdestoque);
    when 3 =>
        tLivro.isbn:=trim(copy(slinha, 1, 13), Both);
        tLivro.titulo:=trim(copy(slinha, 14, 50), Both);
        tLivro.edicao:=trim(copy(slinha, 64, 10), Both);
        tLivro.anopubli:=trim(copy(slinha, 74, 10), Both);
        tLivro.codeditora:=trim(copy(slinha, 84, 10), Both);
        tLivro.volume:=trim(copy(slinha, 94, 10), Both);
        tLivro.codidioma:=trim(copy(slinha, 104, 10), Both);
        tLivro.npaginas:=trim(copy(slinha, 114, 10), Both);
        tLivro.preco:=trim(copy(slinha, 124, 10), Both);
        tLivro.qtdestoque:=trim(copy(slinha, 134, 10), Both);
        put_line("--------------------");
        put_line(rotulo(sreg, 1) & tLivro.isbn);
        put_line(rotulo(sreg, 2) & tLivro.titulo);
        put_line(rotulo(sreg, 3) & tLivro.edicao);
        put_line(rotulo(sreg, 4) & tLivro.anopubli);
        put_line(rotulo(sreg, 5) & tLivro.codeditora);
        mostrarSubDados(opLivro, opEditora, true);
        put_line(rotulo(sreg, 6) & tLivro.volume);
        put_line(rotulo(sreg, 7) & tLivro.codidioma);
        mostrarSubDados(opLivro, opIdioma, true);
        put_line(rotulo(sreg, 8) & tLivro.npaginas);
        put_line(rotulo(sreg, 9) & tLivro.preco);
        put_line(rotulo(sreg, 10) & tLivro.qtdestoque);
        ListarRegLigados(taLivroAss, opLivroAss, 1, 13, 14, 10, tLivro.isbn,
                         taAssunto, opAssunto, 1, 4);
        ListarRegLigados(taLivroAut, opLivroAut, 1, 13, 14, 10, tLivro.isbn,
                         taAutor, opAutor, 1, 4);
    when others => null;
   end case;
elsif sreg=opCliente then
   case nOpcao is
    when 1 =>
        put(rotulo(sreg, 2));
        get_line(tCliente.nome);
        put(rotulo(sreg, 3));
        get_line(tCliente.email);
        put(rotulo(sreg, 4));
        get_line(tCliente.identidade);
        put(rotulo(sreg, 5));
        get_line(tCliente.sexo);
        put(rotulo(sreg, 6));
        get_line(tCliente.telefone);
        tCliente.dtnascimento:=
                validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true);
        mostrarSubDados(opCliente, opEndereco, false);
        mostrarSubDados(opCliente, opPais, false);
        mostrarSubDados(opCliente, opProfissao, false);
    when 3 =>
        tCliente.cpf:=trim(copy(slinha, 1, 14), Both);
        tCliente.nome:=trim(copy(slinha, 15, 30), Both);
        tCliente.email:=trim(copy(slinha, 45, 30), Both);
        tCliente.identidade:=trim(copy(slinha, 75, 10), Both);
        tCliente.sexo:=trim(copy(slinha, 85, 1), Both);
        tCliente.telefone:=trim(copy(slinha, 86, 17), Both);
        tCliente.dtnascimento:=trim(copy(slinha, 103, 10), Both);
        tCliente.codendereco:=trim(copy(slinha, 113, 10), Both);
        tCliente.codpais:=trim(copy(slinha, 123, 3), Both);
        tCliente.codprofissao:=trim(copy(slinha, 126, 10), Both);
        put_line("--------------------");
        put_line(rotulo(sreg, 1) & tCliente.cpf);
        put_line(rotulo(sreg, 2) & tCliente.nome);
        put_line(rotulo(sreg, 3) & tCliente.email);
        put_line(rotulo(sreg, 4) & tCliente.identidade);
        put_line(rotulo(sreg, 5) & tCliente.sexo);
        put_line(rotulo(sreg, 6) & tCliente.telefone);
        put_line(rotulo(sreg, 7) & tCliente.dtnascimento);
        put_line(rotulo(sreg, 8) & tCliente.codendereco);
        mostrarSubDados(opCliente, opEndereco, true);
        put_line(rotulo(sreg, 9) & tCliente.codpais);
        mostrarSubDados(opCliente, opPais, true);
        put_line(rotulo(sreg, 10) & tCliente.codprofissao);
        mostrarSubDados(opCliente, opProfissao, true);
    when others => null;
   end case;
elsif sreg=opVenda then
   case nOpcao is
    when 1 => mostrarSubDados(opVenda,opVenda, false);
    when 2 =>
        put_line("DataHoraVenda       CPF            ISBN          " &
        "PreçoVenda");
        put_line("-------------       ---            ----          " &
        "----------");
    when 3 =>
        tVenda.dthrvenda:=copy(slinha, 1, 19);
        tVenda.cpf:=copy(slinha, 20, 14);
        tVenda.isbn:=copy(slinha, 34, 13);
        tVenda.precovenda:=copy(slinha, 47, 10);
        put_line(tVenda.dthrvenda & " " & tVenda.cpf & " " & 
        tVenda.isbn & " " & tVenda.precovenda);
    when others => null;
   end case;
end if;

end mostrarDados;
-- ----------------------------------------------------------------------------
-- Mostra as sub informções de entrada e de saída.
-- sreg - o tipo de arquivo
-- ssubreg - o subtipo de arquivo
-- bSoMostrar - se vai só mostrar na saída 
-- ----------------------------------------------------------------------------
procedure mostrarSubDados(sreg, ssubreg: in ctArqs; bSoMostrar: in boolean) is
sRegistro, sPreco: ustring;
nMaxTentativas: integer;
begin
nMaxTentativas:=3;
if sreg=opLivro then
  if ssubreg=opEditora then
    if bSoMostrar then
       sRegistro:=pesqArq(taEditora,tLivro.codeditora,1,10,tamReg(opEditora));
    else
       sRegistro:=validaEntrada(taEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,false,opNumero);
    end if;
    if sRegistro/=U("") then
      tLivro.codeditora:=trim(copy(sRegistro,1,10), Both);
      put(" " & rotulo(opEditora, 2));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
    end if;
  elsif ssubreg=opIdioma then
    if bSoMostrar then
       sRegistro:=pesqArq(taIdioma, tLivro.codidioma, 1, 10,tamReg(opIdioma));
    else
       sRegistro:=validaEntrada(taIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,false,opNumero);
    end if;
    if sRegistro/=U("") then
      tLivro.codidioma:=trim(copy(sRegistro,1,10), Both);
      put(" " & rotulo(opIdioma, 2));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
    end if;
  end if;
elsif sreg=opCliente then
  if ssubreg=opEndereco then
    if bSoMostrar then
       sRegistro:=pesqArq(taEndereco, tCliente.codendereco, 1, 10,
                  tamReg(opEndereco));
    else
       sRegistro:=validaEntrada(taEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,false,opNumero);
    end if;
    if sRegistro/=U("") then
      tCliente.codendereco:=trim(copy(sRegistro,1,10), Both);
      put(" " & rotulo(opEndereco, 2));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
      put(" " & rotulo(opEndereco, 3));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
      put(" " & rotulo(opEndereco, 4));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
      put(" " & rotulo(opEndereco, 5));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
      put(" " & rotulo(opEndereco, 6));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
    end if;
  elsif ssubreg=opPais then
    if bSoMostrar then
       sRegistro:=pesqArq(taPais, tCliente.codpais, 1, 3, tamReg(opPais));
    else
       sRegistro:=validaEntrada(taPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,false,opTexto);
    end if;
    if sRegistro/=U("") then
      tCliente.codpais:=trim(copy(sRegistro,1,3), Both);
      put(" " & rotulo(opPais, 2));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
    end if;
  elsif ssubreg=opProfissao then
    if bSoMostrar then
       sRegistro:=pesqArq(taProfissao, tCliente.codprofissao, 1, 10,
                  tamReg(opProfissao));
    else
       sRegistro:=validaEntrada(taProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,false,opNumero);
    end if;
    if sRegistro/=U("") then
      tCliente.codprofissao:=trim(copy(sRegistro,1,10), Both);
      put(" " & rotulo(opProfissao, 2));
      put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
    end if;
  end if;
elsif sreg=opVenda then
  sRegistro:=pesqArq(taLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
  if sRegistro/=U("") then
    put(" " & rotulo(opLivro, 2)); -- Titulo -- 
    put_line(copy(sRegistro, g_nPosChave, g_nTamChave));
    put(" " & rotulo(opLivro, 9)); -- Preco --
    sPreco:=copy(sRegistro, g_nPosChave, g_nTamChave);
    g_nPreco:=float(Value_Real(S(sPreco)));
    put_line(sPreco);
  end if;
end if;
end mostrarSubDados;
-- ----------------------------------------------------------------------------
-- Realiza os cadastros dos arquivos que se ligam a outros arquivos.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- sCodigo - um das chaves do arquivo de ligação
-- ----------------------------------------------------------------------------
procedure frmCadLigados(sreg: in ctArqs; sacao: in ctAcao; sCodigo: in ustring) is
nQtd, nCont, nQtdEstoque: integer;
nTotalPreco: float;
slinha, sTotalPreco, sPreco, sQtd: ustring;
begin
if sacao=opNovo then
  nCont:=1;
  if sreg=opLivroAss then
    sQtd:=validaNumero(U("Quantos assuntos quer cadastrar?: "), sQtd);
    nQtd:=Value_Integer(S(sQtd));
    seekArq(taLivroAss, 1);
    while nCont <= nQtd loop
      tLivroAss.isbn:=sCodigo;
      put(rotulo(opLivroAss, 2));
      get_line(tLivroAss.codassunto);
      slinha:=pesqArq(taAssunto, tLivroAss.codassunto,1,10,tamReg(opAssunto));
      put(" " & rotulo(opAssunto, 2));
      put_line(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(taLivroAss, tamReg(sreg));
      subMenu(14, sreg);
      nCont:=nCont+1;
    end loop;
  elsif sreg=opLivroAut then
    sQtd:=validaNumero(U("Quantos autores quer cadastrar?: "),sQtd);
    nQtd:=Value_Integer(S(sQtd));
    seekArq(taLivroAut, 1);
    while nCont <= nQtd loop
      tLivroAut.isbn:=sCodigo;
      put(rotulo(opLivroAut, 2));
      get_line(tLivroAut.codautor);
      slinha:=pesqArq(taAutor, tLivroAut.codautor,1,10,tamReg(opAutor));
      put(" " & rotulo(opAutor, 2));
      put_line(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(taLivroAut, tamReg(sreg));
      subMenu(14, sreg);
      nCont:=nCont+1;
    end loop;
  elsif sreg=opVenda then
    sQtd:=validaNumero(U("Quantos livros quer vender?: "),sQtd);
    nQtd:=Value_Integer(S(sQtd));
    nTotalPreco:=0.0;
    while nCont <= nQtd loop
      slinha:=validaEntrada(taLivro,opLivro,1,tVenda.isbn,3,false,opTexto);
      if slinha/=U("") then
        tVenda.isbn:=trim(copy(slinha,1,13), Both);
        if validaISBN(tVenda.isbn) then
          mostrarDados(sreg, U(""), 1);
          tLivro.qtdestoque:=trim(copy(slinha,134,10), Both);
          nQtdEstoque:=Value_Integer(S(tLivro.qtdestoque));
          if nQtdEstoque > 0 then
             nTotalPreco:=nTotalPreco + g_nPreco;
             -- sPreco:=floattostr(g_nPreco);
             tVenda.precovenda:=sPreco;
             g_SalvarInclusao:=false;
             subMenu(14, sreg);
             if g_SalvarInclusao then
                slinha:=pesqArq(taLivro, tVenda.isbn, 1, 13, tamReg(opLivro));
                if slinha/=U("") then
                   nQtdEstoque:=nQtdEstoque-1;
                   itostr(nQtdEstoque, tLivro.qtdestoque);
                   slinha:=copy(slinha,1,133) & esp(tLivro.qtdestoque,10);
                   escreveArq(taLivro, slinha, "", "");
                end if;
             end if;
             nCont:=nCont+1;
          else put_line(MSG_SEMESTOQUE);
          end if;
        else put_line(MSG_ISBNINV);
        end if;
      end if;
    end loop;
--    sTotalPreco:=floattostr(nTotalPreco);
    put_line("Total de " & rotulo(sreg,4) & sTotalPreco);
  end if;
elsif sacao=opExcluir then
  if sreg=opLivroAss then
     ExcluirRegLigados(taLivroAss, sreg, 1, 13, sCodigo);
  elsif sreg=opLivroAut then
     ExcluirRegLigados(taLivroAut, sreg, 1, 13, sCodigo);
  end if;
end if;

end frmCadLigados;
-- ----------------------------------------------------------------------------
-- Realiza a exclusão dos arquivos de ligação.
-- sArq - o arquivo de ligação
-- sreg - o tipo de arquivo de ligação
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- sChave - a chave a ser excluida
-- ----------------------------------------------------------------------------
procedure ExcluirRegLigados(sArq: in ctTArqs; sreg: in ctArqs; nPosChave,
nTamChave: in integer; sChave: in ustring) is
slinha: ustring;
sCodigo: ustring;
begin
  seekArq(sArq, 1);
  while (not fimArq(sArq)) loop
    slinha:=lerArq(sArq);
    sCodigo:=trim(copy(slinha,nPosChave,nTamChave), Both);
    if sCodigo=sChave then
       btnAcao(sreg, opConfirmaExclusao);
    end if;
  end loop;
end ExcluirRegLigados;

-- ----------------------------------------------------------------------------
-- Parte inicial do código
-- ----------------------------------------------------------------------------
begin
 if (Argument_Count > 0) then
    if (Argument(1)="-cria") then
      abrecriaArqs(false);
    end if;
 else
   frmSplash;
   abrecriaArqs(true);
   if frmLogin then
     bopcao:=true;
     while(bopcao) loop
       menu(1);
       get_line(opmenu);
       if (opmenu='C') or (opmenu='c') then usaMenu(1);
       elsif (opmenu='P') or (opmenu='p') then usaMenu(2);
       elsif (opmenu='V') or (opmenu='v') then usaMenu(3);
       elsif (opmenu='O') or (opmenu='o') then usaMenu(4);
       else Put_Line(MSG_ERRO);
       end if;
     end loop;
   else
     fechaArqs;
   end if;
 end if;

end livrus;