{------------------------------------------------------------------------------
 Sistema integrante do projeto Livrus Virtus.
 Todos os direitos reservados para Henrique F. de Souza.
 Versão programada na linguagem pascal.
------------------------------------------------------------------------------}
program Livrus;

uses dos, crt;

type
  regAssunto = record
   codigo: string[10];
   assunto: string[30];
  end;
  regAutor = record
   codigo: string[10];
   autor: string[30];
  end;
  regEditora = record
   codigo: string[10];
   editora: string[50];
  end;
  regIdioma = record
   codigo: string[10];
   idioma: string[20];
  end;
  regUsuario = record
   login: string[10];
   senha: string[10];
  end;
  regPais = record
   codigo: string[3];
   pais: string[50];
  end;
  regProfissao = record
   codigo: string[10];
   profissao: string[50];
  end;
  regLivro = record
   isbn: string[13];
   titulo: string[50];
   edicao: string[10];
   anopubli: string[10];
   codeditora: string[10];
   volume: string[10];
   codidioma: string[10];
   npaginas: string[10];
   preco: string[10];
   qtdestoque: string[10];
  end;
  regLivroAss = record
   isbn: string[13];
   codassunto: string[10];
  end;
  regLivroAut = record
   isbn: string[13];
   codautor: string[10];
  end;
  regCliente = record
   cpf: string[14];
   nome: string[30];
   email: string[30];
   identidade: string[10];
   sexo: string[1];
   telefone: string[17];
   dtnascimento: string[10];
   codendereco: string[10];
   codpais: string[3];
   codprofissao: string[10];
  end;
  regEndereco = record
   codigo: string[10];
   logradouro: string[40];
   bairro: string[15];
   cep: string[8];
   cidade: string[30];
   estado: string[20];
  end;
  regVenda = record
   dthrvenda: string[19];  { data/hora da venda dd/mm/yyyy hh:mm:ss }
   cpf: string[14];
   isbn: string[13];
   precovenda: string[10];
  end;

  mstring = string[255];
  tregistro = array[1..145] of Char;
  ctTipo = set of (opTexto, opNumero, opData, opDataHora, opSenha);
  ctArqs = set of (opAssunto, opAutor, opEditora, opEndereco, opIdioma, opPais,
                opProfissao, opCliente, opLivro, opLivroAss, opLivroAut,
                opUsuario, opVenda);
  ctAcao = set of (opNovo, opAlterar, opPesquisar, opSalvarInclusao,
              opSalvarAlteracao, opExcluir, opConfirmaExclusao, opListarTodos);
const
  CRLF = #13#10; { windows }
  TAM_CRLF = 2;
{  CRLF = #10;
   TAM_CRLF = 1; } { unix }
{  CRLF = #13;
   TAM_CRLF = 1; } { macintosh }

  QTD_MAX_LINHA = 18;

  MSG_ERRO = 'Erro: opção inválida digite de novo';
  MSG_OPCAO = 'Escolha uma opção: ';
  MSG_PRESS = 'pressione para continuar...';

  MSG_REGINC = 'registro incluido!';
  MSG_REGNINC = 'registro não incluido!';
  MSG_REGALT = 'registro alterado!';
  MSG_REGNALT = 'registro não alterado!';
  MSG_REGEXC = 'registro excluido!';
  MSG_REGNEXC = 'registro não excluido!';
  MSG_REGEXST = 'registro já existe!';

  MSG_NUMINV = 'Número inválido ou menor do que 1!';
  MSG_DATAINV = 'Data inválida!, formato correto (dd/mm/yyyy)';
  MSG_DTHRINV = 'Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)';
  MSG_ISBNINV = 'ISBN inválido!';
  MSG_CPFINV = 'CPF inválido!';
  MSG_SENCONFERE = 'senha não confere com a senha atual!';
  MSG_SENCONFIRM = 'nova senha não confere com a senha confirmada!';
  MSG_LOGINENCON = 'login não encontrado!';
  MSG_SEMESTOQUE = 'livro não existe no estoque!';

  ARQ_ASSUNTO = 'assunto.dat';
  ARQ_AUTOR = 'autor.dat';
  ARQ_EDITORA = 'editora.dat';
  ARQ_IDIOMA = 'idioma.dat';
  ARQ_USUARIO = 'usuario.dat';
  ARQ_PAIS = 'pais.dat';
  ARQ_PROFISSAO = 'profissao.dat';
  ARQ_LIVRO = 'livro.dat';
  ARQ_LIVASS = 'livroass.dat';
  ARQ_LIVAUT = 'livroaut.dat';
  ARQ_CLIENTE = 'cliente.dat';
  ARQ_ENDERECO = 'endereco.dat';
  ARQ_VENDA = 'venda.dat';

  TAM_ASSUNTO = 40;
  TAM_AUTOR = 40;
  TAM_EDITORA = 60;
  TAM_IDIOMA = 30;
  TAM_USUARIO = 20;
  TAM_PAIS = 53;
  TAM_PROFISSAO = 60;
  TAM_LIVRO = 143;
  TAM_LIVASS = 23;
  TAM_LIVAUT = 23;
  TAM_CLIENTE = 135;
  TAM_ENDERECO = 123;
  TAM_VENDA = 56;

var
 bopcao: boolean;
 opmenu: char;
 g_nPosChave, g_nTamChave: integer;
 g_nPreco: double;
 g_SalvarInclusao: boolean;

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

 tfAssunto, tfAutor, tfEditora, tfIdioma, tfEndereco, tfPais, tfProfissao,
 tfLivro, tfLivroAss, tfLivroAut, tfCliente, tfUsuario, tfVenda: File;

{--- Rotinas básicas ---------------------------------------------------------}
function trim(sTexto: mstring): mstring; forward;
function repete(sTexto: mstring; nQtd: integer): mstring; forward;
function esp(sTexto: mstring; nTam: integer):mstring; forward;
function zeros(stexto:mstring; ntam:integer): mstring; forward;
function strRelativa(sTexto, sChave: mstring):boolean; forward;
function modulo11(svalor: mstring; ndig: integer):integer; forward;
function validaCPF(cpf: mstring): boolean; forward;
function validaISBN(isbn: mstring): boolean; forward;
function digitaSenha(sRotulo: mstring; nTamSenha: integer): mstring; forward;
function validaNumero(sRotulo, sNumero: mstring): mstring; forward;
function validaDataHora(sRotulo, sDataHora: mstring;
         bSoData: boolean): mstring; forward;
function retDataHora: mstring; forward;

{--- Rotinas de manipulação de arquivos --------------------------------------}
function tamArq(var sArq: File): integer; forward;
procedure abrecriaArqs(bAbre: boolean); forward;
procedure fechaArqs; forward;
function pesqArq(var sArq: File; sChave: mstring; nPosChave,
         nTamChave, nTamLinha: integer): mstring; forward;
procedure pesqLinhaExcluida(var sArq: File; nTamLinha: integer); forward;
function pesqMaxCod(var sArq: File; nPosChave,
        nTamChave, nTamLinha: integer): mstring; forward;
procedure escreveArq(var sArq: File; sTexto,
	sMsgAcerto, sMsgErro: mstring); forward;

{--- Rotinas de implementação do sistema e de interface ----------------------}
function LinhaReg(sreg: ctArqs): mstring; forward;
function tamReg(sreg: ctArqs): integer; forward;
function rotulo(sreg: ctArqs; nNum: integer): mstring; forward;
function ContinuaSN(nlinha, nQtdLinha: integer): boolean; forward;
function ListarTodos(var sArq: File; sreg: ctArqs; sChave: mstring;
          nPosChave, nTamChave, nTamLinha, nQtdLinha: integer;
          bPesqRelativa: boolean): boolean; forward;
procedure ListarRegLigados(var sArq1: File; sreg1: ctArqs; nPosChave1,
          nTamChave1, nPosChave2, nTamChave2: integer; sChave: mstring;
      var sArq2: File; sreg2: ctArqs; nPosChave3, nQtdLinha: integer); forward;
function validaEntrada(var sArq: File; sreg: ctArqs; nTexto: integer;
        sEntrada: mstring; nTentativas: integer;
        bPesqRelativa: boolean; bTipoEntrada: ctTipo): mstring; forward;
procedure frmSplash; forward;
procedure frmSobre; forward;
function frmLogin: boolean; forward;
procedure menu(num: integer); forward;
procedure frmCadastros(sreg: ctArqs; sacao: ctAcao); forward;
procedure frmConsultas(sreg: ctArqs; sacao: ctAcao); forward;
procedure frmAlterarSenha; forward;
procedure btnAcao(sreg: ctArqs; sacao: ctAcao); forward;
procedure subMenu(nmenu: integer; sreg: ctArqs); forward;
procedure usaMenu(num: integer); forward;
procedure mostrarDados(sreg: ctArqs; slinha: mstring; nOpcao: integer); forward;
procedure mostrarSubDados(sreg, ssubreg: ctArqs; bSoMostrar: boolean); forward;
procedure frmCadLigados(sreg: ctArqs; sacao: ctAcao; sCodigo: mstring); forward;
procedure ExcluirRegLigados(var sArq: File; sreg: ctArqs; nPosChave,
          nTamChave: integer; sChave: mstring); forward;

{------------------------------------------------------------------------------
Retira os espaços em branco antes ou depois do texto.
sTexto - o texto a ser retirado os espaços em branco
retorna - o texto sem os espaços em branco
------------------------------------------------------------------------------}
function trim(sTexto: mstring): mstring;
var ncont, nPosIni, nPosFim: integer;
    sret: mstring;
    bQuebra: boolean;
begin
nPosIni:=0;
nPosFim:=0;
ncont:=1;
bQuebra:=false;
while (ncont<=length(sTexto)) and (bQuebra=false) do begin
  if sTexto[ncont]<>' ' then begin
     nPosIni:=ncont;
     bQuebra:=true;
  end;
  ncont:=ncont+1;
end;
ncont:=length(sTexto);
bQuebra:=false;
while (ncont >= 1) and (bQuebra=false) do begin
  if sTexto[ncont]<>' ' then begin
     nPosFim:=ncont;
     bQuebra:=true;
  end;
  ncont:=ncont-1;
end;
sret:=copy(sTexto,nPosIni,(nPosFim-nPosIni)+1);
trim:=sret;
end;
{------------------------------------------------------------------------------
Repete um texto um número determinado de vezes.
sTexto - o texto a ser repetido
nQtd - a quantidade de vezes
retorna - o texto repetido
------------------------------------------------------------------------------}
function repete(sTexto: mstring; nQtd: integer): mstring;
var ncont: integer;
    sret: mstring;
begin
sret:='';
for ncont:=1 to nQtd do begin
    sret:=sret+sTexto;
end;
repete:=sret;
end;
{------------------------------------------------------------------------------
Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
sTexto - o texto
nTam - tamanho máximo do texto
retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------}
function esp(sTexto: mstring; nTam: integer):mstring;
begin
esp:=sTexto+repete(' ',nTam-length(sTexto));
end;
{------------------------------------------------------------------------------
Escreve zeros na frente de um texto.
stexto - o texto para receber zeros a frente
ntam - o tamanho da string
retorna - o texto com o zeros antes
------------------------------------------------------------------------------}
function zeros(stexto:mstring; ntam:integer): mstring;
var ncont: integer;
    saux: mstring;
begin
  saux:='';
  if ntam<>length(stexto) then begin
      for ncont:=1 to ntam-length(stexto) do
        saux:=saux + '0';
  end;
  zeros:=saux+stexto;
end;
{------------------------------------------------------------------------------
Faz uma pesquisa relativa de um texto através de um valor chave.
sTexto - o texto
sChave - a chave a ser pesquisada
retorna - se achou ou não a chave dentro do texto
------------------------------------------------------------------------------}
function strRelativa(sTexto, sChave: mstring):boolean;
var nCont, nTamChave, nTamTexto: integer;
    bret: boolean;
    sPedaco: mstring;
begin
bret:=false;
nCont:=1;
nTamChave:=length(sChave);
nTamTexto:=length(sTexto);
if nTamChave <= nTamTexto then begin
  while nCont <= (nTamTexto-nTamChave+1) do begin
     sPedaco:=copy(sTexto,nCont,nTamChave);
     if sPedaco=sChave then
        bret:=true;
     nCont:=nCont+1;
  end;
end;
strRelativa:=bret;
end;
{------------------------------------------------------------------------------
Calcula o modulo11 de um valor qualquer.
svalor - a mstring com o número a ser calculado
ndig - dígito do valor a ser calculado
retorna - o dígito correto
------------------------------------------------------------------------------}
function modulo11(svalor: mstring; ndig: integer): integer;
var ncont, nsoma, nstatus, nvalor, npos: integer;
    sres, slocal: mstring;
begin
 ncont:=1;
 while ncont <= 11 do begin
   slocal:=copy(svalor,ncont,1) + slocal;
   ncont:=ncont+1;
 end;
 nsoma:=0;
 if ndig=1 then
   ncont:=3
 else
   ncont:=2;
 npos:=2;
 while ncont <= 11 do begin
   sres:=copy(slocal,ncont,1);
   Val(sres,nvalor,nstatus);
   nsoma:=nsoma + (nvalor * npos);
   ncont:=ncont+1;
   npos:=npos+1;
 end;
 nsoma:=(11 - (nsoma mod 11));

if nsoma > 9 then
  modulo11:=0
else
  modulo11:=nsoma;
end;
{------------------------------------------------------------------------------
Validação de um número de CPF qualquer.
cpf - a mstring com o número do CPF
retorna - se é valido ou não
------------------------------------------------------------------------------}
function validaCPF(cpf: mstring): boolean;
var scpf, sres: mstring;
    nstatus, nvalor1, nvalor2: integer;
begin
if (length(cpf)=14) then begin
  scpf:=copy(cpf,1,3)+copy(cpf,5,3)+copy(cpf,9,3)+copy(cpf,13,2);
  sres:=copy(cpf,13,1);
  Val(sres,nvalor1,nstatus);
  sres:=copy(cpf,14,1);
  Val(sres,nvalor2,nstatus);
  if ((modulo11(scpf,1)=nvalor1) and (modulo11(scpf,2)=nvalor2)) then
    validaCPF:=true
  else
    validaCPF:=false;
end else
  validaCPF:=false;
end;
{------------------------------------------------------------------------------
Validação de um número ISBN qualquer.
isbn - a mstring com o número do ISBN
retorna - se é valido ou não
------------------------------------------------------------------------------}
function validaISBN(isbn: mstring): boolean;
var snum, sdigito, sisbn: mstring;
 nvalor, nsoma, nstatus, ncont: integer;
begin
if (length(isbn)=13) then begin
  sdigito := copy(isbn, length(isbn), 1);
  sisbn:='';
  for ncont:=1 to length(isbn)-1 do begin
    if (copy(isbn,ncont,1)<>'-') then
      sisbn:=sisbn+copy(isbn,ncont,1);
  end;
  if sdigito = 'X' then
    nsoma := 10
  else begin
    Val(sdigito,nvalor,nstatus);
    nsoma := nvalor;
  end;
  for ncont:=1 to 9 do begin
    snum:=copy(sisbn, ncont, 1);
    Val(snum,nvalor,nstatus);
    nsoma:=nsoma + (nvalor * (11 - ncont));
  end;
  If (nsoma mod 11) = 0 Then
    validaISBN:=true
  else
    validaISBN:=false;
end else
  validaISBN:=false;
end;
{------------------------------------------------------------------------------
Esconde a digitação da senha
retorna - a senha digitada
------------------------------------------------------------------------------}
function digitaSenha(sRotulo: mstring; nTamSenha: integer): mstring;
var sSenha: mstring;
{    sLetra: char;
    ncont: integer;}
begin
write(sRotulo);
readln(sSenha);
{  ncont := 0;
  sSenha:='';
  sLetra:=#0;
  while((sLetra<>#13) and (ncont < nTamSenha)) do begin
    sLetra:=readkey;
    write('*');
    sSenha:=sSenha+sLetra;
    ncont:=ncont+1;
  end;}
digitaSenha:=sSenha;
end;
{------------------------------------------------------------------------------
Validação de um número qualquer.
sRotulo - o texto antes de se digitar o número
sNumero - a mstring com o valor do número
retorna - o sNumero
------------------------------------------------------------------------------}
function validaNumero(sRotulo, sNumero: mstring): mstring;
var nnum: double;
    nStatus: integer;
begin
nStatus:=-1;
while (nStatus<>0) do begin
  write(sRotulo);
  readln(sNumero);
  Val(sNumero,nnum,nStatus);
  if (nnum < 1) or (nStatus<>0) then
     writeln(MSG_NUMINV);
end;
validaNumero:=sNumero;
end;
{------------------------------------------------------------------------------
Validação de uma data ou data/hora qualquer.
sRotulo - o texto antes de se digitar a data/hora
sDataHora - a mstring com o valor da data/hora
bSoData - indica se vai validar somente uma data sem a hora
retorna - a sDataHora
------------------------------------------------------------------------------}
function validaDataHora(sRotulo, sDataHora: mstring; bSoData: boolean): mstring;
var bvalida, bdatavalida, bhoravalida: boolean;
    sdia, smes, sano, shora, smin, sseg: mstring;
    ndia, nmes, nano, nhora, nmin, nseg, nudiames: integer;
    nStatus, ntam: integer;
begin
bvalida:=false;
bdatavalida:=false;
bhoravalida:=false;
nudiames:=0;

if bSoData=true then ntam:=10
else ntam:=19;
while (bvalida=false) do begin
  write(sRotulo);
  readln(sDataHora);
  if length(sDataHora)=ntam then begin
    sdia:=copy(sDataHora,1,2);
    Val(sdia,ndia,nStatus);
    smes:=copy(sDataHora,4,2);
    Val(smes,nmes,nStatus);
    sano:=copy(sDataHora,7,4);
    Val(sano,nano,nStatus);
  
    if (nano >= 1) and (nano <= 9999) then begin
      if (nmes >= 1) and (nmes <= 31) then begin
          case nmes of
           1, 3, 5, 7, 8, 10, 12: nudiames:=31;
           2: begin
               { ano bissexto }
               if (nano mod 4)=0 then nudiames:=29
               else nudiames:=28;
              end;
           4, 6, 9, 11: nudiames:=30;
          end;
          if (ndia >=1) and (ndia <=nudiames) then
             bdatavalida:=true;
      end;
    end;
  
    if bSoData then begin
       if bdatavalida then bvalida:=true
       else writeln(MSG_DATAINV);
    end else begin
      if bdatavalida then begin
          shora:=copy(sDataHora,12,2);
          Val(shora,nhora,nStatus);
          smin:=copy(sDataHora,15,2);
          Val(smin,nmin,nStatus);
          sseg:=copy(sDataHora,18,2);
          Val(sseg,nseg,nStatus);
  
          if (nhora >= 0) and (nhora <= 23) then begin
            if (nmin >= 0) and (nmin <= 59) then begin
              if (nseg >= 0) and (nseg <= 59) then
                 bhoravalida:=true;
            end;
          end;
  
          if bhoravalida then bvalida:=true
          else writeln(MSG_DTHRINV);
      end else
        writeln(MSG_DTHRINV);
    end;
  end else begin
    if bSoData=true then writeln(MSG_DATAINV)
    else writeln(MSG_DTHRINV);
  end;
end;
validaDataHora:=sDataHora;
end;
{------------------------------------------------------------------------------
Retorna a Data e a hora do sistema.
retorna - a data e a hora
------------------------------------------------------------------------------}
function retDataHora: mstring;
var y, m, d, dow, h, mn, s, ms: word;
    dia,mes,ano,hora,min,seg: mstring;
begin
  GetDate(y,m,d,dow);
  str(d,dia);
  str(m,mes);
  str(y,ano);
  GetTime(h,mn,s,ms);
  str(h,hora);
  str(mn,min);
  str(s,seg);
  retDataHora:=zeros(dia,2) + '/'+  zeros(mes,2) + '/'+ ano + ' '+
  zeros(hora,2)+':'+zeros(min,2)+':'+zeros(seg,2);
end;
{------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------}
function tamArq(var sArq: File): integer;
begin
tamArq:=FileSize(sArq);
end;
{------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------}
procedure abrecriaArqs(bAbre: boolean);
begin
 Assign(tfAssunto, ARQ_ASSUNTO);
 Assign(tfAutor, ARQ_AUTOR);
 Assign(tfEditora, ARQ_EDITORA);
 Assign(tfIdioma, ARQ_IDIOMA);
 Assign(tfEndereco, ARQ_ENDERECO);
 Assign(tfPais, ARQ_PAIS);
 Assign(tfProfissao, ARQ_PROFISSAO);
 Assign(tfLivro, ARQ_LIVRO);
 Assign(tfLivroAss, ARQ_LIVASS);
 Assign(tfLivroAut, ARQ_LIVAUT);
 Assign(tfCliente, ARQ_CLIENTE);
 Assign(tfUsuario, ARQ_USUARIO);
 Assign(tfVenda, ARQ_VENDA);
if bAbre then begin
 Reset(tfAssunto, 1);
 Reset(tfAutor, 1);
 Reset(tfEditora, 1);
 Reset(tfIdioma, 1);
 Reset(tfEndereco, 1);
 Reset(tfPais, 1);
 Reset(tfProfissao, 1);
 Reset(tfLivro, 1);
 Reset(tfLivroAss, 1);
 Reset(tfLivroAut, 1);
 Reset(tfCliente, 1);
 Reset(tfUsuario, 1);
 Reset(tfVenda, 1);
end else begin
 rewrite(tfAssunto, 1);
 rewrite(tfAutor, 1);
 rewrite(tfEditora, 1);
 rewrite(tfIdioma, 1);
 rewrite(tfEndereco, 1);
 rewrite(tfPais, 1);
 rewrite(tfProfissao, 1);
 rewrite(tfLivro, 1);
 rewrite(tfLivroAss, 1);
 rewrite(tfLivroAut, 1);
 rewrite(tfCliente, 1);
 rewrite(tfUsuario, 1);
 rewrite(tfVenda, 1);
end;
end;
{------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------}
procedure fechaArqs;
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
end;
{------------------------------------------------------------------------------
Pesquisa um registro através de um valor chave num arquivo.
sArq - o arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o registro pesquisado
------------------------------------------------------------------------------}
function pesqArq(var sArq: File; sChave: mstring; nPosChave,
        nTamChave, nTamLinha: integer): mstring;
var slinha: tregistro;
    sRes: mstring;
    bQuebra: boolean;
    nStatus, nPosicao: integer;
begin
bQuebra:=false;
seek(sArq, 0);
while (not Eof(sArq)) and (bQuebra=false) do begin
  BlockRead(sArq, slinha, nTamLinha + TAM_CRLF, nStatus);
  sres:=trim(copy(slinha,nPosChave,nTamChave));
  if sres=sChave then
     bQuebra:=true;
end;
nPosicao:=FilePos(sArq)-(nTamLinha + TAM_CRLF);
if nPosicao > 0 then
   seek(sArq, nPosicao)
else
   seek(sArq, 0);
if sRes<>sChave then
   pesqArq:=''
else
   pesqArq:=copy(slinha,1,nTamLinha);
end;
{------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------}
procedure pesqLinhaExcluida(var sArq: File; nTamLinha: integer);
var sExcluido: mstring;
begin
sExcluido:=pesqArq(sArq, '*', 1, 1, nTamLinha);
if sExcluido='' then
   seek(sArq, tamArq(sArq));
end;
{------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------}
function pesqMaxCod(var sArq: File; nPosChave,
        nTamChave, nTamLinha: integer): mstring;
var slinha: tregistro;
    sRes: mstring;
    bQuebra: boolean;
    nStatus, nMaior, nCod: integer;
begin
bQuebra:=false;
nMaior:=0;
seek(sArq, 0);
while (not Eof(sArq)) and (bQuebra=false) do begin
  BlockRead(sArq, slinha, nTamLinha + TAM_CRLF, nStatus);
  sres:=trim(copy(slinha,nPosChave,nTamChave));
  Val(sres,ncod,nStatus);
  if nCod > nMaior then
     nMaior:=nCod;
end;
pesqLinhaExcluida(sArq, nTamLinha);
str((nMaior+1),sres);
pesqMaxCod:=sres;
end;
{------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------}
procedure escreveArq(var sArq: File; sTexto, sMsgAcerto,
	sMsgErro: mstring);
var nStatus, ncont: integer;
    slinha: tregistro;
begin
sTexto:=sTexto+CRLF;
for ncont:=1 to length(sTexto) do begin
    slinha[ncont]:=sTexto[ncont];
end;
BlockWrite(sArq, slinha, length(sTexto), nStatus);
if nStatus > 0 then begin
   writeln(sMsgAcerto);
end else begin
   writeln(sMsgErro);
end;
end;
{------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------}
function LinhaReg(sreg: ctArqs): mstring;
var slinha: mstring;
begin
slinha:='';
if opAssunto in sreg then
   slinha:=esp(tAssunto.codigo,10)+esp(tAssunto.assunto,30)
else if opAutor in sreg then
   slinha:=esp(tAutor.codigo,10)+esp(tAutor.autor,30)
else if opEditora in sreg then
   slinha:=esp(tEditora.codigo,10)+esp(tEditora.editora,50)
else if opEndereco in sreg then
   slinha:=esp(tEndereco.codigo,10)+esp(tEndereco.logradouro,40)+
   esp(tEndereco.bairro,15)+esp(tEndereco.cep,8)+esp(tEndereco.cidade,30)+
   esp(tEndereco.estado,20)
else if opIdioma in sreg then
   slinha:=esp(tIdioma.codigo,10)+esp(tIdioma.idioma,20)
else if opPais in sreg then
   slinha:=esp(tPais.codigo,3)+esp(tPais.pais,50)
else if opProfissao in sreg then
   slinha:=esp(tProfissao.codigo,10)+esp(tProfissao.profissao,50)
else if opUsuario in sreg then
   slinha:=esp(tUsuario.login,10)+esp(tUsuario.senha,10)
else if opLivro in sreg then
   slinha:=esp(tLivro.isbn,13)+esp(tLivro.titulo,50)+esp(tLivro.edicao,10)+
   esp(tLivro.anopubli,10)+esp(tLivro.codeditora,10)+esp(tLivro.volume,10)+
   esp(tLivro.codidioma,10)+esp(tLivro.npaginas,10)+esp(tLivro.preco,10)+
   esp(tLivro.qtdestoque,10)
else if opLivroAss in sreg then
   slinha:=esp(tLivroAss.isbn,13)+esp(tlivroAss.codassunto,10)
else if opLivroAut in sreg then
   slinha:=esp(tLivroAut.isbn,13)+esp(tlivroAut.codautor,10)
else if opCliente in sreg then
   slinha:=esp(tCliente.cpf,14)+esp(tCliente.nome,30)+esp(tCliente.email,30)+
   esp(tCliente.identidade,10)+esp(tCliente.sexo,1)+esp(tCliente.telefone,17)+
   esp(tCliente.dtnascimento,10)+esp(tCliente.codendereco,10)+
   esp(tCliente.codpais,3)+esp(tCliente.codprofissao,10)
else if opVenda in sreg then
   slinha:=esp(tVenda.dthrvenda,19)+esp(tVenda.cpf,14)+esp(tVenda.isbn,13)+
   esp(tVenda.precovenda,10);

LinhaReg:=slinha;
end;
{------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------}
function tamReg(sreg: ctArqs): integer;
var nret: integer;
begin
nret:=0;
if opAssunto in sreg then nret:=TAM_ASSUNTO
else if opAutor in sreg then nret:=TAM_AUTOR
else if opEditora in sreg then nret:=TAM_EDITORA
else if opEndereco in sreg then nret:=TAM_ENDERECO
else if opIdioma in sreg then nret:=TAM_IDIOMA
else if opPais in sreg then nret:=TAM_PAIS
else if opProfissao in sreg then nret:=TAM_PROFISSAO
else if opUsuario in sreg then nret:=TAM_USUARIO
else if opLivro in sreg then nret:=TAM_LIVRO
else if opLivroAss in sreg then nret:=TAM_LIVASS
else if opLivroAut in sreg then nret:=TAM_LIVAUT
else if opCliente in sreg then nret:=TAM_CLIENTE
else if opVenda in sreg then nret:=TAM_VENDA;

tamReg:=nret;
end;
{------------------------------------------------------------------------------
Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
nNum - indica qual rotulo será retornado
retorna - o rotulo
------------------------------------------------------------------------------}
function rotulo(sreg: ctArqs; nNum: integer): mstring;
var sret: mstring;
begin
sret:='';
if opAssunto in sreg then begin
   case nNum of
     0: sret:='Assunto(s) não encontrado(s)!';
     1: begin
         sret:='Código do assunto: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Assunto: ';
         g_nPosChave:=11;
         g_nTamChave:=30;
        end;
   end;
end else if opAutor in sreg then begin
   case nNum of
     0: sret:='Autor(es) não encontrado(s)!';
     1: begin
         sret:='Código do autor: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Autor: ';
         g_nPosChave:=11;
         g_nTamChave:=30;
        end;
   end;
end else if opEditora in sreg then begin
   case nNum of
     0: sret:='Editora(s) não encontrada(s)!';
     1: begin
         sret:='Código da editora: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Editora: ';
         g_nPosChave:=11;
         g_nTamChave:=50;
        end;
   end;
end else if opEndereco in sreg then begin
   case nNum of
     0: sret:='Endereço(s) não encontrado(s)!';
     1: begin
         sret:='Código do endereço: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Logradouro: ';
         g_nPosChave:=11;
         g_nTamChave:=40;
        end;
     3: begin
         sret:='Bairro: ';
         g_nPosChave:=51;
         g_nTamChave:=15;
        end;
     4: begin
         sret:='CEP: ';
         g_nPosChave:=66;
         g_nTamChave:=8;
        end;
     5: begin
         sret:='Cidade: ';
         g_nPosChave:=74;
         g_nTamChave:=30;
        end;
     6: begin
         sret:='Estado: ';
         g_nPosChave:=104;
         g_nTamChave:=20;
        end;
   end;
end else if opIdioma in sreg then begin
   case nNum of
     0: sret:='Idioma(s) não encontrado(s)!';
     1: begin
         sret:='Código do idioma: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Idioma: ';
         g_nPosChave:=11;
         g_nTamChave:=20;
        end;
   end;
end else if opPais in sreg then begin
   case nNum of
     0: sret:='País(es) não encontrado(s)!';
     1: begin
         sret:='Código do país: ';
         g_nPosChave:=1;
         g_nTamChave:=3;
        end;
     2: begin
         sret:='País: ';
         g_nPosChave:=4;
         g_nTamChave:=50;
        end;
   end;
end else if opProfissao in sreg then begin
   case nNum of
     0: sret:='Profissão(es) não encontrada(s)!';
     1: begin
         sret:='Código da profissão: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Profissão: ';
         g_nPosChave:=11;
         g_nTamChave:=50;
        end;
   end;
end else if opUsuario in sreg then begin
   case nNum of
     0: sret:='login ou senha incorreta, tente de novo!';
     1: begin
         sret:='Login: ';
         g_nPosChave:=1;
         g_nTamChave:=10;
        end;
     2: begin
         sret:='Senha: ';
         g_nPosChave:=11;
         g_nTamChave:=10;
        end;
   end;
end else if opLivro in sreg then begin
   case nNum of
     0: sret:='Livro(s) não encontrado(s)!';
     1: begin
         sret:='ISBN: ';
         g_nPosChave:=1;
         g_nTamChave:=13;
        end;
     2: begin
         sret:='Título: ';
         g_nPosChave:=14;
         g_nTamChave:=50;
        end;
     3: begin
         sret:='Edição: ';
         g_nPosChave:=64;
         g_nTamChave:=10;
        end;
     4: begin
         sret:='Ano de Publicação: ';
         g_nPosChave:=74;
         g_nTamChave:=10;
        end;
     5: begin
         sret:='Código da editora: ';
         g_nPosChave:=84;
         g_nTamChave:=10;
        end;
     6: begin
         sret:='Volume: ';
         g_nPosChave:=94;
         g_nTamChave:=10;
        end;
     7: begin
         sret:='Código do idioma: ';
         g_nPosChave:=104;
         g_nTamChave:=10;
        end;
     8: begin
         sret:='Número de páginas: ';
         g_nPosChave:=114;
         g_nTamChave:=10;
        end;
     9: begin
         sret:='Preço: ';
         g_nPosChave:=124;
         g_nTamChave:=10;
        end;
     10: begin
          sret:='Qtd. Estoque: ';
          g_nPosChave:=134;
          g_nTamChave:=10;
         end;
   end;
end else if opLivroAss in sreg then begin
   case nNum of
     0: sret:='Assunto(s) não encontrado(s)!';
     1: begin
         sret:='ISBN: ';
         g_nPosChave:=1;
         g_nTamChave:=13;
        end;
     2: begin
         sret:='Código do assunto: ';
         g_nPosChave:=14;
         g_nTamChave:=10;
        end;
   end;
end else if opLivroAut in sreg then begin
   case nNum of
     0: sret:='Autor(s) não encontrado(s)!';
     1: begin
         sret:='ISBN: ';
         g_nPosChave:=1;
         g_nTamChave:=13;
        end;
     2: begin
         sret:='Código do autor: ';
         g_nPosChave:=14;
         g_nTamChave:=10;
        end;
   end;
end else if opCliente in sreg then begin
   case nNum of
     0: sret:='Cliente(s) não encontrado(s)!';
     1: begin
         sret:='CPF: ';
         g_nPosChave:=1;
         g_nTamChave:=14;
        end;
     2: begin
         sret:='Nome: ';
         g_nPosChave:=15;
         g_nTamChave:=30;
        end;
     3: begin
         sret:='E-mail: ';
         g_nPosChave:=45;
         g_nTamChave:=30;
        end;
     4: begin
         sret:='Identidade: ';
         g_nPosChave:=75;
         g_nTamChave:=10;
        end;
     5: begin
         sret:='Sexo: ';
         g_nPosChave:=85;
         g_nTamChave:=1;
        end;
     6: begin
         sret:='Telefone: ';
         g_nPosChave:=86;
         g_nTamChave:=17;
        end;
     7: begin
         sret:='Dt. Nascimento: ';
         g_nPosChave:=103;
         g_nTamChave:=10;
        end;
     8: begin
         sret:='Código do endereço: ';
         g_nPosChave:=113;
         g_nTamChave:=10;
        end;
     9: begin
         sret:='Código do país: ';
         g_nPosChave:=123;
         g_nTamChave:=3;
        end;
     10: begin
          sret:='Código da Profissão: ';
          g_nPosChave:=126;
          g_nTamChave:=10;
        end;
   end;
end else if opVenda in sreg then begin
   case nNum of
     0: sret:='Venda(s) não encontrada(s)!';
     1: begin
         sret:='Data/Hora venda: ';
         g_nPosChave:=1;
         g_nTamChave:=19;
        end;
     2: begin
         sret:='CPF: ';
         g_nPosChave:=20;
         g_nTamChave:=14;
        end;
     3: begin
         sret:='ISBN: ';
         g_nPosChave:=34;
         g_nTamChave:=13;
        end;
     4: begin
         sret:='Pre+o de venda: ';
         g_nPosChave:=47;
         g_nTamChave:=10;
        end;
   end;
end;

rotulo:=sret;
end;
{------------------------------------------------------------------------------
Indica se continua ou não mostrando um número máximo de linhas.
nlinha - a linha a ser continuada
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se continua ou não
------------------------------------------------------------------------------}
function ContinuaSN(nlinha, nQtdLinha: integer): boolean;
var bSOp, bret : boolean;
    opCSubMenu: char;
begin
bret:=false;
if nlinha > 0 then begin
  if (nlinha mod nQtdLinha) = 0 then begin
      bSOp:=true;
      while(bSOp) do begin
       menu(13);
       readln(opCSubMenu);
       if (opCSubMenu='S') or (opCSubMenu='s') then bSOp:=false
       else if (opCSubMenu='N') or (opCSubMenu='n') then begin
          bret:=true;
          bSOp:=false;
       end else writeln(MSG_ERRO);
      end;
  end;
end;

ContinuaSN:=bret;
end;
{------------------------------------------------------------------------------
Lista vários registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
nQtdLinha - a quantidade de linhas a serem mostradas
retorna - se encontrou algum registro
------------------------------------------------------------------------------}
function ListarTodos(var sArq: File; sreg: ctArqs; sChave: mstring;
   nPosChave, nTamChave, nTamLinha, nQtdLinha: integer;
   bPesqRelativa: boolean): boolean;
var slinha: tregistro;
    bQuebra, bAchou, bRet: boolean;
    nStatus, nCont: integer;
    sres: mstring;
begin
bRet:=false;
bQuebra:=false;
nCont:=0;
mostrarDados(sreg, '', 2);
seek(sArq, 0);
while (not Eof(sArq)) and (bQuebra=false) do begin
  BlockRead(sArq, slinha, nTamLinha + TAM_CRLF, nStatus);

  if bPesqRelativa then begin
    sres:=trim(copy(slinha,nPosChave,nTamChave));
    if strRelativa(sres,sChave) then begin
       bAchou:=true;
       bRet:=true;
    end else
       bAchou:=false;
  end else begin
    bAchou:=true;
    bRet:=true;
  end;

  if bAchou then begin
    mostrarDados(sreg, copy(slinha,1,nTamLinha), 3);
    nCont:=nCont+1;
  end;

  bQuebra:=ContinuaSN(nCont, nQtdLinha);
end;
ListarTodos:=bret;
end;
{------------------------------------------------------------------------------
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
------------------------------------------------------------------------------}
procedure ListarRegLigados(var sArq1: File; sreg1: ctArqs; nPosChave1,
nTamChave1, nPosChave2, nTamChave2: integer; sChave: mstring;
var sArq2: File; sreg2: ctArqs; nPosChave3, nQtdLinha: integer);
var slinha1: tregistro;
    bQuebra, bRet: boolean;
    nStatus, nCont: integer;
    sCodigo1, sCodigo2, slinha2: mstring;
begin
bRet:=false;
nCont:=0;
bQuebra:=false;
mostrarDados(sreg2, '', 2);
seek(sArq1, 0);
while (not Eof(sArq1)) and (bQuebra=false) do begin
  BlockRead(sArq1, slinha1, tamReg(sreg1) + TAM_CRLF, nStatus);
  sCodigo1:=trim(copy(slinha1,nPosChave1,nTamChave1));
  if sCodigo1=sChave then begin
    sCodigo2:=trim(copy(slinha1,nPosChave2,nTamChave2));
    slinha2:=pesqArq(sArq2, sCodigo2, nPosChave3, nTamChave2, tamReg(sreg2));
    mostrarDados(sreg2, copy(slinha2, 1, tamReg(sreg2)), 3);
    bRet:=true;
    nCont:=nCont+1;
  end;
  bQuebra:=ContinuaSN(nCont, nQtdLinha);
end;
if bRet=false then
   writeln(rotulo(sreg2,0));
end;
{------------------------------------------------------------------------------
Valida a entrada de registros de acordo com a pesquisa feita.
sArq - o arquivo
sreg - o tipo de arquivo
nTexto - o numero do rótulo da entrada
sEntrada - a chave a ser pesquisada e validada
nTentativas - o número máximo de tentativas
bPesqRelativa - indica se vai realizar uma pesquisa relativa
bTipoEntrada - indica o tipo de entrada
retorna - o registro pesquisado e validado
------------------------------------------------------------------------------}
function validaEntrada(var sArq: File; sreg: ctArqs; nTexto: integer;
        sEntrada: mstring; nTentativas: integer;
        bPesqRelativa: boolean; bTipoEntrada: ctTipo): mstring;
var bQuebra: boolean;
    sres, sTexto, sMsgErro: mstring;
    ncont, nPosChave, nTamChave, nTamLinha: integer;
begin
nTamLinha:=tamReg(sreg);
sMsgErro:=rotulo(sreg,0);
sTexto:=rotulo(sreg,nTexto);
nPosChave:=g_nPosChave;
nTamChave:=g_nTamChave;

ncont:=1;
bQuebra:=false;
  while (bQuebra=false) and (ncont <= nTentativas ) do begin
    if opTexto in bTipoEntrada then begin
      write(sTexto);
      readln(sEntrada);
    end else if opNumero in bTipoEntrada then
       sEntrada:=validaNumero(sTexto,sEntrada)
    else if opData in bTipoEntrada then
       sEntrada:=validaDataHora(sTexto,sEntrada,true)
    else if opDataHora in bTipoEntrada then
       sEntrada:=validaDataHora(sTexto,sEntrada,false)
    else if opSenha in bTipoEntrada then begin
       sEntrada:=digitaSenha(sTexto, 10);
    end;

    if bPesqRelativa then begin
       if ListarTodos(sArq, sreg, sEntrada, nPosChave, nTamChave, nTamLinha,
       QTD_MAX_LINHA, true) then
        sres:=' ';
    end else
       sres:=pesqArq(sArq, sEntrada, nPosChave, nTamChave, nTamLinha);

    if sres='' then
       writeln(sMsgErro)
    else
       bQuebra:=true;

    ncont:=ncont+1;
  end;
validaEntrada:=sres;
end;
{------------------------------------------------------------------------------
Mostra a tela de splash do sistema.
------------------------------------------------------------------------------}
procedure frmSplash;
var cont: integer;
begin
 writeln('*---------------------------------------'+
 '-------------------------------------*');
 writeln('| LL    II VV   VV RRRRR  UU  UU   SSSS '+
 'VV   VV II RRRRR  TTTT UU  UU   SSSS |');
 writeln('| LL    II  VV VV  RR   R UU  UU  SS    '+
 ' VV VV  II RR   R  TT  UU  UU  SS    |');
 writeln('| LL    II   VVV   RRRRR  UU  UU    SS  '+
 '  VVV   II RRRRR   TT  UU  UU    SS  |');
 writeln('| LLLLL II    V    RR   R  UUUU  SSSS   '+
 '   V    II RR   R  TT   UUUU  SSSS   |');
 writeln('*---------------------------------------'+
 '-------------------------------------*');
 for cont:=1 to 18 do writeln;
 write(MSG_PRESS);
 readln;
end;
{------------------------------------------------------------------------------
Mostra a tela de sobre do sistema.
------------------------------------------------------------------------------}
procedure frmSobre;
var cont: integer;
begin
 writeln('*------------------------------------------------------------*');
 writeln('|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |');
 writeln('|  LL        II   VV     VV   RR     R  UU    UU  SS         |');
 writeln('|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |');
 writeln('|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |');
 writeln('|  LLLL      II      VVV      RR RR     UU    UU        SS   |');
 writeln('|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |');
 writeln('|                                                            |');
 writeln('|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |');
 writeln('|   VV     VV   II  RR     R     TT     UU    UU  SS         |');
 writeln('|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |');
 writeln('|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |');
 writeln('|      VVV      II  RR RR        TT     UU    UU        SS   |');
 writeln('|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |');
 writeln('|                                                            |');
 writeln('|                                               Versao 1.0.0 |');
 writeln('| Sistema integrante do projeto Livrus Virtus.               |');
 writeln('| Todos os direitos reservados para Henrique F. de Souza.    |');
 writeln('| Versao programada na linguagem pascal.                     |');
 writeln('*------------------------------------------------------------*');
 for cont:=1 to 4 do writeln;
 write(MSG_PRESS);
 readln;
end;
{------------------------------------------------------------------------------
Mostra a tela de login do sistema.
retorna - se o login foi validado corretamente
------------------------------------------------------------------------------}
function frmLogin: boolean;
var bret: boolean;
    slinha: mstring;
begin
  bret:=false;
  writeln('*--------------------------------------------------------------*');
  writeln('| Login do sistema                                             |');
  writeln('*--------------------------------------------------------------*');
  slinha:=validaEntrada(tfUsuario, [opUsuario], 1, tUsuario.login, 3,
        false, [opTexto]);
  if slinha<>'' then begin
     slinha:=validaEntrada(tfUsuario, [opUsuario], 2, tUsuario.senha, 3,
        false, [opSenha]);
     if slinha<>'' then begin
        tUsuario.login:=trim(copy(slinha, 1, 10));
        tUsuario.senha:=trim(copy(slinha, 11, 10));
        bret:=true;
     end;
  end;
  writeln;
  frmLogin:=bret;
end;
{------------------------------------------------------------------------------
Mostra os menus do sistema.
num - o número do menu
------------------------------------------------------------------------------}
procedure menu(num: integer);
begin
 if (num=1) then begin
  writeln('*--------------------------------------------------------------*');
  writeln('| (C)adastros        (P)esquisas     (V)endas        (O)pções  |');
  writeln('*--------------------------------------------------------------*');
 end else if (num=2) then begin
   writeln('*---------------------------------*');
   writeln('| 01. Cadastro de Assuntos        |');
   writeln('| 02. Cadastro de Autores         |');
   writeln('| 03. Cadastro de Editoras        |');
   writeln('| 04. Cadastro de Endereços       |');
   writeln('| 05. Cadastro de Idiomas         |');
   writeln('| 06. Cadastro de Países          |');
   writeln('| 07. Cadastro de Profissões      |');
   writeln('| 08. Cadastro de Clientes        |');
   writeln('| 09. Cadastro de Livros          |');
   writeln('| 10. Voltar ao menu              |');
   writeln('*---------------------------------*');
 end else if (num=3) then begin
   writeln('*---------------------------------*');
   writeln('| 01. Consulta de Assuntos        |');
   writeln('| 02. Consulta de Autores         |');
   writeln('| 03. Consulta de Editoras        |');
   writeln('| 04. Consulta de Endereços       |');
   writeln('| 05. Consulta de Idiomas         |');
   writeln('| 06. Consulta de Países          |');
   writeln('| 07. Consulta de Profissões      |');
   writeln('| 08. Consulta de Clientes        |');
   writeln('| 09. Consulta de Livros          |');
   writeln('| 10. Voltar ao menu              |');
   writeln('*---------------------------------*');
 end else if (num=4) then begin
   writeln('*---------------------------------*');
   writeln('| 01. Vender Livros               |');
   writeln('| 02. Vendas Realizadas           |');
   writeln('| 03. Voltar ao menu              |');
   writeln('*---------------------------------*');
 end else if (num=5) then begin
   writeln('*---------------------------------*');
   writeln('| 01. Alterar senha               |');
   writeln('| 02. Sobre o sistema             |');
   writeln('| 03. Sair do sistema             |');
   writeln('| 04. Voltar ao menu              |');
   writeln('*---------------------------------*');
 end else if (num=6) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=7) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| (1) Salvar inclusão       (2) Voltar ao menu                 |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=8) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=9) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| (1) Salvar alteração      (2) Voltar ao menu                 |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=10) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| Certeza de excluir? (S/N)                                    |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=11) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| Deseja sair do sistema? (S/N)                                |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=12) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=13) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| Deseja continuar? (S/N)                                      |');
   writeln('*--------------------------------------------------------------*');
 end else if (num=14) then begin
   writeln('*--------------------------------------------------------------*');
   writeln('| Salvar inclusão (S/N)                                        |');
   writeln('*--------------------------------------------------------------*');
 end;
 write(MSG_OPCAO);
end;
{------------------------------------------------------------------------------
Realiza os cadastros de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------}
procedure frmCadastros(sreg: ctArqs; sacao: ctAcao);
var slinha: mstring;
begin
if opAssunto in sreg then begin
   if opNovo in sacao then begin
      tAssunto.codigo:=pesqMaxCod(tfAssunto, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   end else if opPesquisar in sacao then begin
     slinha:=validaEntrada(tfAssunto,sreg,1,tAssunto.codigo,1,false,[opNumero]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opAutor in sreg then begin
   if opNovo in sacao then begin
      tAutor.codigo:=pesqMaxCod(tfAutor, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfAutor, sreg, 1, tAutor.codigo,1,false,[opNumero]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opEditora in sreg then begin
   if opNovo in sacao then begin
      tEditora.codigo:=pesqMaxCod(tfEditora, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   end else if opPesquisar in sacao then begin
     slinha:=validaEntrada(tfEditora,sreg,1,tEditora.codigo,1,false,[opNumero]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opEndereco in sreg then begin
   if opNovo in sacao then begin
      tEndereco.codigo:=pesqMaxCod(tfEndereco, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfEndereco,sreg,1,tEndereco.codigo,1,
              false,[opNumero]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opIdioma in sreg then begin
   if opNovo in sacao then begin
      tIdioma.codigo:=pesqMaxCod(tfIdioma, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfIdioma,sreg,1,tIdioma.codigo,1,false,[opNumero]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opPais in sreg then begin
   if opNovo in sacao then begin
      write(rotulo(sreg, 1));
      readln(tPais.codigo);
      slinha:=pesqArq(tfPais, tPais.codigo, 1, 3, tamReg(sreg));
      if slinha='' then begin
         pesqLinhaExcluida(tfPais, tamReg(sreg));
         mostrarDados(sreg, '', 1);
         subMenu(7, sreg);
      end else writeln(MSG_REGEXST);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfPais, sreg, 1, tPais.codigo, 1, false, [opTexto]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      writeln(rotulo(sreg, 1), tPais.codigo);
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opProfissao in sreg then begin
   if opNovo in sacao then begin
      tProfissao.codigo:=pesqMaxCod(tfProfissao, 1, 10, tamReg(sreg));
      mostrarDados(sreg, '', 1);
      subMenu(7, sreg);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfProfissao,sreg,1,tProfissao.codigo,1,
              false,[opNumero]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opLivro in sreg then begin
   if opNovo in sacao then begin
      write(rotulo(sreg, 1));
      readln(tLivro.isbn);
      if validaISBN(tLivro.isbn) then begin
          slinha:=pesqArq(tfLivro, tLivro.isbn, 1, 13, tamReg(sreg));
          if slinha='' then begin
             pesqLinhaExcluida(tfLivro, tamReg(sreg));
             mostrarDados(sreg, '', 1);
             subMenu(7, sreg);
             frmCadLigados([opLivroAss], [opNovo], tLivro.isbn);
             frmCadLigados([opLivroAut], [opNovo], tLivro.isbn);
          end else writeln(MSG_REGEXST);
      end else writeln(MSG_ISBNINV);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfLivro, sreg, 1, tLivro.isbn, 1,false,[opTexto]);
      if slinha<>'' then begin
         mostrarDados(sreg, '', 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      writeln(rotulo(sreg, 1), tLivro.isbn);
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
      frmCadLigados([opLivroAss], [opExcluir], tLivro.isbn);
      writeln('Assuntos dos livros excluídos, inclua novos!');
      frmCadLigados([opLivroAss], [opNovo], tLivro.isbn);
      frmCadLigados([opLivroAut], [opExcluir], tLivro.isbn);
      writeln('Autores dos livros excluídos, inclua novos!');
      frmCadLigados([opLivroAut], [opNovo], tLivro.isbn);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
      writeln('Assuntos dos livros sendo excluídos!');
      frmCadLigados([opLivroAss], [opExcluir], tLivro.isbn);
      writeln('Autores dos livros sendo excluídos!');
      frmCadLigados([opLivroAut], [opExcluir], tLivro.isbn);
   end;
end else if opCliente in sreg then begin
   if opNovo in sacao then begin
      write(rotulo(sreg, 1));
      readln(tCliente.cpf);
      if validaCPF(tCliente.cpf) then begin
          slinha:=pesqArq(tfCliente, tCliente.cpf, 1, 14, tamReg(sreg));
          if slinha='' then begin
             pesqLinhaExcluida(tfCliente, tamReg(sreg));
             mostrarDados(sreg, '', 1);
             subMenu(7, sreg);
          end else writeln(MSG_REGEXST);
      end else writeln(MSG_CPFINV);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfCliente, sreg, 1, tCliente.cpf,1,false,[opTexto]);
      if slinha<>'' then begin
         mostrarDados(sreg, '', 2);
         mostrarDados(sreg, slinha, 3);
         subMenu(8, sreg);
      end;
   end else if opAlterar in sacao then begin
      writeln(rotulo(sreg, 1), tCliente.cpf);
      mostrarDados(sreg, '', 1);
      subMenu(9, sreg);
   end else if opExcluir in sacao then begin
      subMenu(10, sreg);
   end;
end else if opVenda in sreg then begin
   if opNovo in sacao then begin
      tVenda.dthrvenda:=retDataHora;
      writeln(rotulo(sreg, 1), tVenda.dthrvenda);
      slinha:=pesqArq(tfVenda, tVenda.dthrvenda, 1, 19, tamReg(sreg));
      if slinha='' then begin
         slinha:=validaEntrada(tfCliente,[opCliente],1,tVenda.cpf,3,
                 false,[opTexto]);
         if slinha<>'' then begin
            tVenda.cpf:=trim(copy(slinha,1,14));
            if validaCPF(tVenda.cpf) then begin
               write(' ',rotulo([opCliente], 2)); { Nome }
               writeln(copy(slinha, g_nPosChave, g_nTamChave));
               frmCadLigados([opVenda], [opNovo], tVenda.cpf);
            end else writeln(MSG_CPFINV);
         end;
      end else writeln(MSG_REGEXST);
   end else if opPesquisar in sacao then begin
      slinha:=validaEntrada(tfVenda, sreg, 1, tVenda.dthrvenda,1,
              false,[opDataHora]);
      if slinha<>'' then begin
        mostrarDados(sreg, '', 2);
        mostrarDados(sreg, slinha, 3);
        subMenu(8, sreg);
      end;
   end;
end;

end;
{------------------------------------------------------------------------------
Realiza as consultas de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------}
procedure frmConsultas(sreg: ctArqs; sacao: ctAcao);
var slinha: mstring;
begin
if opAssunto in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfAssunto,sreg,2,tAssunto.assunto,1,true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfAssunto, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opAutor in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfAutor,sreg, 2, tAutor.autor, 1, true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfAutor, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opEditora in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfEditora,sreg,2,tEditora.editora,1,true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfEditora, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opEndereco in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfEndereco,sreg,2,tEndereco.Logradouro,1,
              true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfEndereco, sreg, '', 0, 0, tamReg(sreg),
         3, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opIdioma in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfIdioma, sreg, 2, tIdioma.idioma,1,true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfIdioma, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opPais in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfPais, sreg, 2, tPais.pais, 1, true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfPais, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opProfissao in sreg then begin
   if opPesquisar in sacao then
     slinha:=validaEntrada(tfProfissao,sreg,2,tProfissao.profissao,1,
             true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfProfissao, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opLivro in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfLivro, sreg, 2, tLivro.titulo, 1, true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfLivro, sreg, '', 0, 0, tamReg(sreg),
        1, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opCliente in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfCliente, sreg, 2, tCliente.nome,1,true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfCliente, sreg, '', 0, 0, tamReg(sreg),
        1, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end else if opVenda in sreg then begin
   if opPesquisar in sacao then
      slinha:=validaEntrada(tfVenda, sreg, 2, tVenda.cpf, 1, true,[opTexto])
   else if opListarTodos in sacao then begin
      if ListarTodos(tfVenda, sreg, '', 0, 0, tamReg(sreg),
        QTD_MAX_LINHA, false) = false then
        writeln(rotulo(sreg, 0));
   end;
end;
if slinha='' then
   write('');
end;
{------------------------------------------------------------------------------
Mostra a tela de alteração de senha do sistema e realiza a alteração.
------------------------------------------------------------------------------}
procedure frmAlterarSenha;
var bQuebra: boolean;
    sres, sSenhaAtual, sNovaSenha, sConfirmaSenha: mstring;
    nopcao: integer;
begin
writeln(rotulo([opUsuario], 1), tUsuario.login);
nopcao:=1;
bQuebra:=false;
while (bQuebra=false) do begin
  case nopcao of
   1: begin
       sSenhaAtual:=digitaSenha('Senha Atual: ',10);
       if sSenhaAtual<>tUsuario.senha then begin
          writeln(MSG_SENCONFERE);
          bQuebra:=true;
       end else nopcao:=2;
      end;
   2: begin
       sNovaSenha:=digitaSenha('Nova Senha: ',10);
       sConfirmaSenha:=digitaSenha('Confirma Senha: ',10);
       if sNovaSenha<>sConfirmaSenha then begin
          writeln(MSG_SENCONFIRM);
          bQuebra:=true;
       end else nopcao:=3;
      end;
   3: begin
       sres:=pesqArq(tfUsuario, tUsuario.login, 1, 10, tamReg([opUsuario]));
       if sres='' then
         writeln(MSG_LOGINENCON)
       else begin
         tUsuario.senha:=sConfirmaSenha;
         subMenu(9,[opUsuario]);
         bQuebra:=true;
       end;
      end;
  end;
end;

end;
{------------------------------------------------------------------------------
Executa uma ação de gravação de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
------------------------------------------------------------------------------}
procedure btnAcao(sreg: ctArqs; sacao: ctAcao);
begin
if opAssunto in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfAssunto, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfAssunto, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opAutor in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfAutor, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfAutor, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opEditora in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfEditora, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfEditora, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opEndereco in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfEndereco, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfEndereco, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opIdioma in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfIdioma, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfIdioma, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opPais in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfPais, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfPais, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opProfissao in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfProfissao, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfProfissao, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opLivro in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfLivro, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfLivro, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opLivroAss in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfLivroAss, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfLivroAss, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opLivroAut in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfLivroAut, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfLivroAut, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opCliente in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfCliente, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfCliente, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opVenda in sreg then begin
   if opSalvarInclusao in sacao then
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGINC, MSG_REGNINC)
   else if opSalvarAlteracao in sacao then
      escreveArq(tfVenda, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT)
   else if opConfirmaExclusao in sacao then
      escreveArq(tfVenda, repete('*',tamReg(sreg)), MSG_REGEXC, MSG_REGNEXC);
end else if opUsuario in sreg then begin
   if opSalvarAlteracao in sacao then
      escreveArq(tfUsuario, LinhaReg(sreg), MSG_REGALT, MSG_REGNALT);
end;
end;
{------------------------------------------------------------------------------
Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
nmenu - o número do menu
sreg - o tipo de arquivo
------------------------------------------------------------------------------}
procedure subMenu(nmenu: integer; sreg: ctArqs);
var opSubMenu: integer;
    opCSubMenu: char;
    bSOp: boolean;
begin
bSOp:=true;
case nmenu of
 6:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opSubMenu);
     case(opSubMenu) of
      1: frmCadastros(sreg, [opNovo]);
      2: frmCadastros(sreg, [opPesquisar]);
      3: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
    end;
   end;
 7:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opSubMenu);
     case(opSubMenu) of
      1: begin btnAcao(sreg, [opSalvarInclusao]); bSOp:=false; end;
      2: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
    end;
   end;
 8:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opSubMenu);
     case(opSubMenu) of
      1: begin frmCadastros(sreg, [opAlterar]); bSOp:=false; end;
      2: begin frmCadastros(sreg, [opExcluir]); bSOp:=false; end;
      3: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
    end;
   end;
 9:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opSubMenu);
     case(opSubMenu) of
      1: begin btnAcao(sreg, [opSalvarAlteracao]); bSOp:=false; end;
      2: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
    end;
   end;
 10:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opCSubMenu);
     if (opCSubMenu='S') or (opCSubMenu='s') then begin
        btnAcao(sreg, [opConfirmaExclusao]);
        bSOp:=false;
     end else if (opCSubMenu='N') or (opCSubMenu='n') then bSOp:=false
     else writeln(MSG_ERRO);
    end;
   end;
 12:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opSubMenu);
     case(opSubMenu) of
      1: frmConsultas(sreg, [opPesquisar]);
      2: frmConsultas(sreg, [opListarTodos]);
      3: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
    end;
   end;
 14:begin
    while(bSOp) do begin
     menu(nmenu);
     readln(opCSubMenu);
     if (opCSubMenu='S') or (opCSubMenu='s') then begin
        btnAcao(sreg, [opSalvarInclusao]);
        bSOp:=false;
        g_SalvarInclusao:=true;
     end else if (opCSubMenu='N') or (opCSubMenu='n') then bSOp:=false
     else writeln(MSG_ERRO);
    end;
   end;
end;

end;
{------------------------------------------------------------------------------
Seleciona o submenu e/ou a tela certa de acordo com número do menu.
nmenu - o número do menu
------------------------------------------------------------------------------}
procedure usaMenu(num: integer);
var opSubMenu: integer;
    bSOp: boolean;
    opSair: char;
begin
 bSOp:=true;
 if num = 1 then begin { Cadastros }
   while(bSOp) do begin
     menu(2);
     readln(opSubMenu);
     case(opSubMenu) of
      1: subMenu(6, [opAssunto]);
      2: subMenu(6, [opAutor]);
      3: subMenu(6, [opEditora]);
      4: subMenu(6, [opEndereco]);
      5: subMenu(6, [opIdioma]);
      6: subMenu(6, [opPais]);
      7: subMenu(6, [opProfissao]);
      8: subMenu(6, [opCliente]);
      9: subMenu(6, [opLivro]);
      10: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
   end;
 end else if num = 2 then begin { Pesquisas }
   while(bSOp) do begin
     menu(3);
     readln(opSubMenu);
     case(opSubMenu) of
      1: subMenu(12, [opAssunto]);
      2: subMenu(12, [opAutor]);
      3: subMenu(12, [opEditora]);
      4: subMenu(12, [opEndereco]);
      5: subMenu(12, [opIdioma]);
      6: subMenu(12, [opPais]);
      7: subMenu(12, [opProfissao]);
      8: subMenu(12, [opCliente]);
      9: subMenu(12, [opLivro]);
      10: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
   end;
 end else if num = 3 then begin { Vendas }
   while(bSOp) do begin
     menu(4);
     readln(opSubMenu);
     case(opSubMenu) of
      1: subMenu(6, [opVenda]);
      2: subMenu(12, [opVenda]);
      3: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
   end;
 end else if num = 4 then begin { Opcoes }
   while(bSOp) do begin
     menu(5);
     readln(opSubMenu);
     case(opSubMenu) of
      1: frmAlterarSenha;
      2: frmSobre;
      3: begin
           menu(11);
           read(opSair);
           if (opSair='S') or (opSair='s') then begin
              fechaArqs;
              halt;
           end;
         end;
      4: bSOp:=false;
      else writeln(MSG_ERRO);
     end;
   end;
 end;
end;
{------------------------------------------------------------------------------
Mostra as entradas e as saídas do sistema.
sreg - o tipo de arquivo
slinha - o registro com os dados
nOpcao - indica qual opção será mostrada
------------------------------------------------------------------------------}
procedure mostrarDados(sreg: ctArqs; slinha: mstring; nOpcao: integer);
begin
if opAssunto in sreg then begin
   case nOpcao of
    1: begin
        writeln(rotulo(sreg, 1), tAssunto.codigo);
        write(rotulo(sreg, 2));
        readln(tAssunto.assunto);
       end;
    2: begin
        writeln('Código     Assunto');
        writeln('------     -------');
       end;
    3: begin
        tAssunto.codigo:=copy(slinha, 1, 10);
        tAssunto.assunto:=copy(slinha, 11, 30);
        writeln(tAssunto.codigo,' ',tAssunto.assunto);
       end;
   end;
end else if opAutor in sreg then begin
   case nOpcao of
    1: begin
        writeln(rotulo(sreg, 1), tAutor.codigo);
        write(rotulo(sreg, 2));
        readln(tAutor.autor);
       end;
    2: begin
        writeln('Código     Autor');
        writeln('------     -----');
       end;
    3: begin
        tAutor.codigo:=copy(slinha, 1, 10);
        tAutor.autor:=copy(slinha, 11, 30);
        writeln(tAutor.codigo,' ',tAutor.autor);
       end;
   end;
end else if opEditora in sreg then begin
   case nOpcao of
    1: begin
        writeln(rotulo(sreg, 1), tEditora.codigo);
        write(rotulo(sreg, 2));
        readln(tEditora.editora);
       end;
    2: begin
        writeln('Código     Editora');
        writeln('------     -------');
       end;
    3: begin
        tEditora.codigo:=copy(slinha, 1, 10);
        tEditora.editora:=copy(slinha, 11, 50);
        writeln(tEditora.codigo,' ',tEditora.editora);
       end;
   end;
end else if opEndereco in sreg then begin
   case nOpcao of
    1: begin
        writeln(rotulo(sreg, 1), tEndereco.codigo);
        write(rotulo(sreg, 2));
        readln(tEndereco.Logradouro);
        write(rotulo(sreg, 3));
        readln(tEndereco.bairro);
        write(rotulo(sreg, 4));
        readln(tEndereco.cep);
        write(rotulo(sreg, 5));
        readln(tEndereco.cidade);
        write(rotulo(sreg, 6));
        readln(tEndereco.estado);
       end;
    3: begin
        tEndereco.codigo:=trim(copy(slinha, 1, 10));
        tEndereco.logradouro:=trim(copy(slinha, 11, 40));
        tEndereco.bairro:=trim(copy(slinha, 51, 15));
        tEndereco.cep:=trim(copy(slinha, 66, 8));
        tEndereco.cidade:=trim(copy(slinha, 74, 30));
        tEndereco.estado:=trim(copy(slinha, 104, 20));
        writeln('--------------------');
        writeln(rotulo(sreg, 1), tEndereco.codigo);
        writeln(rotulo(sreg, 2), tEndereco.Logradouro);
        writeln(rotulo(sreg, 3), tEndereco.bairro);
        writeln(rotulo(sreg, 4), tEndereco.cep);
        writeln(rotulo(sreg, 5), tEndereco.cidade);
        writeln(rotulo(sreg, 6), tEndereco.estado);
       end;
   end;
end else if opIdioma in sreg then begin
   case nOpcao of
    1: begin
        writeln(rotulo(sreg, 1), tIdioma.codigo);
        write(rotulo(sreg, 2));
        readln(tIdioma.idioma);
       end;
    2: begin
        writeln('Código     Idioma');
        writeln('------     ------');
       end;
    3: begin
        tIdioma.codigo:=copy(slinha, 1, 10);
        tIdioma.idioma:=copy(slinha, 11, 20);
        writeln(tIdioma.codigo,' ',tIdioma.idioma);
       end;
   end;
end else if opPais in sreg then begin
   case nOpcao of
    1: begin
        write(rotulo(sreg, 2));
        readln(tPais.pais);
       end;
    2: begin
        writeln('Código País');
        writeln('------ ----');
       end;
    3: begin
        tPais.codigo:=copy(slinha, 1, 3);
        tPais.pais:=copy(slinha, 4, 50);
        writeln(tPais.codigo,'    ',tPais.pais);
       end;
   end;
end else if opProfissao in sreg then begin
   case nOpcao of
    1: begin
        writeln(rotulo(sreg, 1), tProfissao.codigo);
        write(rotulo(sreg, 2));
        readln(tProfissao.profissao);
       end;
    2: begin
        writeln('Código     Profissão');
        writeln('------     ---------');
       end;
    3: begin
        tProfissao.codigo:=copy(slinha, 1, 10);
        tProfissao.profissao:=copy(slinha, 11, 50);
        writeln(tProfissao.codigo,' ',tProfissao.profissao);
       end;
   end;
end else if opLivro in sreg then begin
   case nOpcao of
    1: begin
        write(rotulo(sreg, 2));
        readln(tLivro.titulo);
        tLivro.edicao:=validaNumero(rotulo(sreg, 3), tLivro.edicao);
        tLivro.anopubli:=validaNumero(rotulo(sreg, 4), tLivro.anopubli);
        mostrarSubDados([opLivro], [opEditora], false);
        tLivro.volume:=validaNumero(rotulo(sreg, 6), tLivro.volume);
        mostrarSubDados([opLivro], [opIdioma], false);
        tLivro.npaginas:=validaNumero(rotulo(sreg, 8), tLivro.npaginas);
        tLivro.preco:=validaNumero(rotulo(sreg, 9), tLivro.preco);
        tLivro.qtdestoque:=validaNumero(rotulo(sreg, 10), tLivro.qtdestoque);
       end;
    3: begin
        tLivro.isbn:=trim(copy(slinha, 1, 13));
        tLivro.titulo:=trim(copy(slinha, 14, 50));
        tLivro.edicao:=trim(copy(slinha, 64, 10));
        tLivro.anopubli:=trim(copy(slinha, 74, 10));
        tLivro.codeditora:=trim(copy(slinha, 84, 10));
        tLivro.volume:=trim(copy(slinha, 94, 10));
        tLivro.codidioma:=trim(copy(slinha, 104, 10));
        tLivro.npaginas:=trim(copy(slinha, 114, 10));
        tLivro.preco:=trim(copy(slinha, 124, 10));
        tLivro.qtdestoque:=trim(copy(slinha, 134, 10));
        writeln('--------------------');
        writeln(rotulo(sreg, 1), tLivro.isbn);
        writeln(rotulo(sreg, 2), tLivro.titulo);
        writeln(rotulo(sreg, 3), tLivro.edicao);
        writeln(rotulo(sreg, 4), tLivro.anopubli);
        writeln(rotulo(sreg, 5), tLivro.codeditora);
        mostrarSubDados([opLivro], [opEditora], true);
        writeln(rotulo(sreg, 6), tLivro.volume);
        writeln(rotulo(sreg, 7), tLivro.codidioma);
        mostrarSubDados([opLivro], [opIdioma], true);
        writeln(rotulo(sreg, 8), tLivro.npaginas);
        writeln(rotulo(sreg, 9), tLivro.preco);
        writeln(rotulo(sreg, 10), tLivro.qtdestoque);
        ListarRegLigados(tfLivroAss, [opLivroAss], 1, 13, 14, 10, tLivro.isbn,
                         tfAssunto, [opAssunto], 1, 4);
        ListarRegLigados(tfLivroAut, [opLivroAut], 1, 13, 14, 10, tLivro.isbn,
                         tfAutor, [opAutor], 1, 4);
       end;
   end;
end else if opCliente in sreg then begin
   case nOpcao of
    1: begin
        write(rotulo(sreg, 2));
        readln(tCliente.nome);
        write(rotulo(sreg, 3));
        readln(tCliente.email);
        write(rotulo(sreg, 4));
        readln(tCliente.identidade);
        write(rotulo(sreg, 5));
        readln(tCliente.sexo);
        write(rotulo(sreg, 6));
        readln(tCliente.telefone);
        tCliente.dtnascimento:=
                validaDataHora(rotulo(sreg, 7), tCliente.dtnascimento, true);
        mostrarSubDados([opCliente], [opEndereco], false);
        mostrarSubDados([opCliente], [opPais], false);
        mostrarSubDados([opCliente], [opProfissao], false);
       end;
    3: begin
        tCliente.cpf:=trim(copy(slinha, 1, 14));
        tCliente.nome:=trim(copy(slinha, 15, 30));
        tCliente.email:=trim(copy(slinha, 45, 30));
        tCliente.identidade:=trim(copy(slinha, 75, 10));
        tCliente.sexo:=trim(copy(slinha, 85, 1));
        tCliente.telefone:=trim(copy(slinha, 86, 17));
        tCliente.dtnascimento:=trim(copy(slinha, 103, 10));
        tCliente.codendereco:=trim(copy(slinha, 113, 10));
        tCliente.codpais:=trim(copy(slinha, 123, 3));
        tCliente.codprofissao:=trim(copy(slinha, 126, 10));
        writeln('--------------------');
        writeln(rotulo(sreg, 1), tCliente.cpf);
        writeln(rotulo(sreg, 2), tCliente.nome);
        writeln(rotulo(sreg, 3), tCliente.email);
        writeln(rotulo(sreg, 4), tCliente.identidade);
        writeln(rotulo(sreg, 5), tCliente.sexo);
        writeln(rotulo(sreg, 6), tCliente.telefone);
        writeln(rotulo(sreg, 7), tCliente.dtnascimento);
        writeln(rotulo(sreg, 8), tCliente.codendereco);
        mostrarSubDados([opCliente], [opEndereco], true);
        writeln(rotulo(sreg, 9), tCliente.codpais);
        mostrarSubDados([opCliente], [opPais], true);
        writeln(rotulo(sreg, 10), tCliente.codprofissao);
        mostrarSubDados([opCliente], [opProfissao], true);
       end;
   end;
end else if opVenda in sreg then begin
   case nOpcao of
    1: mostrarSubDados([opVenda],[opVenda], false);
    2: begin
        writeln('DataHoraVenda       CPF            ISBN          '+
        'PreçoVenda');
        writeln('-------------       ---            ----          '+
        '----------');
       end;
    3: begin
        tVenda.dthrvenda:=copy(slinha, 1, 19);
        tVenda.cpf:=copy(slinha, 20, 14);
        tVenda.isbn:=copy(slinha, 34, 13);
        tVenda.precovenda:=copy(slinha, 47, 10);
        writeln(tVenda.dthrvenda,' ',tVenda.cpf,' ',tVenda.isbn,' ',
        tVenda.precovenda);
       end;
   end;
end;

end;
{------------------------------------------------------------------------------
Mostra as sub informções de entrada e de saída.
sreg - o tipo de arquivo
ssubreg - o subtipo de arquivo
bSoMostrar - se vai só mostrar na saída 
------------------------------------------------------------------------------}
procedure mostrarSubDados(sreg, ssubreg: ctArqs; bSoMostrar: boolean);
var sRegistro, sPreco: mstring;
    nStatus, nMaxTentativas: integer;
begin
nMaxTentativas:=3;
if opLivro in sreg then begin
  if opEditora in ssubreg then begin
    if bSoMostrar then
       sRegistro:=pesqArq(tfEditora,tLivro.codeditora,1,10,tamReg([opEditora]))
    else
       sRegistro:=validaEntrada(tfEditora,ssubreg,1,tLivro.codeditora,
                  nMaxTentativas,false,[opNumero]);
    if sRegistro<>'' then begin
      tLivro.codeditora:=trim(copy(sRegistro,1,10));
      write(' ',rotulo([opEditora], 2));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
    end;
  end else if opIdioma in ssubreg then begin
    if bSoMostrar then
       sRegistro:=pesqArq(tfIdioma, tLivro.codidioma, 1, 10,tamReg([opIdioma]))
    else
       sRegistro:=validaEntrada(tfIdioma,ssubreg,1,tLivro.codidioma,
                  nMaxTentativas,false,[opNumero]);
    if sRegistro<>'' then begin
      tLivro.codidioma:=trim(copy(sRegistro,1,10));
      write(' ',rotulo([opIdioma], 2));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
    end;
  end;
end else if opCliente in sreg then begin
  if opEndereco in ssubreg then begin
    if bSoMostrar then
       sRegistro:=pesqArq(tfEndereco, tCliente.codendereco, 1, 10,
                  tamReg([opEndereco]))
    else
       sRegistro:=validaEntrada(tfEndereco,ssubreg,1,tCliente.codendereco,
                  nMaxTentativas,false,[opNumero]);
    if sRegistro<>'' then begin
      tCliente.codendereco:=trim(copy(sRegistro,1,10));
      write(' ',rotulo([opEndereco], 2));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
      write(' ',rotulo([opEndereco], 3));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
      write(' ',rotulo([opEndereco], 4));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
      write(' ',rotulo([opEndereco], 5));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
      write(' ',rotulo([opEndereco], 6));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
    end;
  end else if opPais in ssubreg then begin
    if bSoMostrar then
       sRegistro:=pesqArq(tfPais, tCliente.codpais, 1, 3, tamReg([opPais]))
    else
       sRegistro:=validaEntrada(tfPais,ssubreg,1,tCliente.codpais,
                  nMaxTentativas,false,[opTexto]);
    if sRegistro<>'' then begin
      tCliente.codpais:=trim(copy(sRegistro,1,3));
      write(' ',rotulo([opPais], 2));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
    end;
  end else if opProfissao in ssubreg then begin
    if bSoMostrar then
       sRegistro:=pesqArq(tfProfissao, tCliente.codprofissao, 1, 10,
                  tamReg([opProfissao]))
    else
       sRegistro:=validaEntrada(tfProfissao,ssubreg,1,tCliente.codprofissao,
                  nMaxTentativas,false,[opNumero]);
    if sRegistro<>'' then begin
      tCliente.codprofissao:=trim(copy(sRegistro,1,10));
      write(' ',rotulo([opProfissao], 2));
      writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
    end;
  end;
end else if opVenda in sreg then begin
  sRegistro:=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg([opLivro]));
  if sRegistro<>'' then begin
    write(' ',rotulo([opLivro], 2)); { Titulo }
    writeln(copy(sRegistro, g_nPosChave, g_nTamChave));
    write(' ',rotulo([opLivro], 9)); { Preco }
    sPreco:=copy(sRegistro, g_nPosChave, g_nTamChave);
    val(sPreco,g_nPreco,nStatus);
    writeln(sPreco);
  end;
end;
end;
{------------------------------------------------------------------------------
Realiza os cadastros dos arquivos que se ligam a outros arquivos.
sreg - o tipo de arquivo
sacao - a ação a ser realizada
sCodigo - um das chaves do arquivo de ligação
------------------------------------------------------------------------------}
procedure frmCadLigados(sreg: ctArqs; sacao: ctAcao; sCodigo: mstring);
var nQtd, nCont, nQtdEstoque, nStatus: integer;
    nTotalPreco: double;
    slinha, sTotalPreco, sPreco, sQtd: mstring;
begin
if opNovo in sacao then begin
  nCont:=1;
  if opLivroAss in sreg then begin
    sQtd:=validaNumero('Quantos assuntos quer cadastrar?: ', sQtd);
    Val(sQtd,nQtd,nStatus);
    seek(tfLivroAss, 0);
    while nCont <= nQtd do begin
      tLivroAss.isbn:=sCodigo;
      write(rotulo([opLivroAss], 2));
      readln(tLivroAss.codassunto);
      slinha:=pesqArq(tfAssunto, tLivroAss.codassunto,1,10,tamReg([opAssunto]));
      write(' ',rotulo([opAssunto], 2));
      writeln(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAss, tamReg(sreg));
      subMenu(14, sreg);
      nCont:=nCont+1;
    end;
  end else if opLivroAut in sreg then begin
    sQtd:=validaNumero('Quantos autores quer cadastrar?: ',sQtd);
    Val(sQtd,nQtd,nStatus);
    seek(tfLivroAut, 0);
    while nCont <= nQtd do begin
      tLivroAut.isbn:=sCodigo;
      write(rotulo([opLivroAut], 2));
      readln(tLivroAut.codautor);
      slinha:=pesqArq(tfAutor, tLivroAut.codautor,1,10,tamReg([opAutor]));
      write(' ',rotulo([opAutor], 2));
      writeln(copy(slinha, g_nPosChave, g_nTamChave));
      pesqLinhaExcluida(tfLivroAut, tamReg(sreg));
      subMenu(14, sreg);
      nCont:=nCont+1;
    end;
  end else if opVenda in sreg then begin
    sQtd:=validaNumero('Quantos livros quer vender?: ',sQtd);
    Val(sQtd,nQtd,nStatus);
    nTotalPreco:=0;
    while nCont <= nQtd do begin
      slinha:=validaEntrada(tfLivro,[opLivro],1,tVenda.isbn,3,false,[opTexto]);
      if slinha<>'' then begin
        tVenda.isbn:=trim(copy(slinha,1,13));
        if validaISBN(tVenda.isbn) then begin
          mostrarDados(sreg, '', 1);
          tLivro.qtdestoque:=trim(copy(slinha,134,10));
          val(tLivro.qtdestoque,nQtdEstoque,nStatus);
          if nQtdEstoque > 0 then begin
             nTotalPreco:=nTotalPreco + g_nPreco;
             str(g_nPreco:7:2,sPreco);
             tVenda.precovenda:=sPreco;
             g_SalvarInclusao:=false;
             subMenu(14, sreg);
             if g_SalvarInclusao then begin
                slinha:=pesqArq(tfLivro, tVenda.isbn, 1, 13, tamReg([opLivro]));
                if slinha<>'' then begin
                   nQtdEstoque:=nQtdEstoque-1;
                   str(nQtdEstoque,tLivro.qtdestoque);
                   slinha:=copy(slinha,1,133)+esp(tLivro.qtdestoque,10);
                   escreveArq(tfLivro, slinha, '', '');
                end;
             end;
             nCont:=nCont+1;
          end else writeln(MSG_SEMESTOQUE);
        end else writeln(MSG_ISBNINV);
      end;
    end;
    str(nTotalPreco:7:2, sTotalPreco);
    writeln('Total de ',rotulo(sreg,4),sTotalPreco);
  end;
end else if opExcluir in sacao then begin
  if opLivroAss in sreg then begin
     ExcluirRegLigados(tfLivroAss, sreg, 1, 13, sCodigo);
  end else if opLivroAut in sreg then begin
     ExcluirRegLigados(tfLivroAut, sreg, 1, 13, sCodigo);
  end;
end;

end;
{------------------------------------------------------------------------------
Realiza a exclusão dos arquivos de ligação.
sArq - o arquivo de ligação
sreg - o tipo de arquivo de ligação
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
sChave - a chave a ser excluida
------------------------------------------------------------------------------}
procedure ExcluirRegLigados(var sArq: File; sreg: ctArqs; nPosChave,
nTamChave: integer; sChave: mstring);
var slinha: tregistro;
    sCodigo: mstring;
    nStatus: integer;
begin
  seek(sArq, 0);
  while (not Eof(sArq)) do begin
    BlockRead(sArq, slinha, tamReg(sreg) + TAM_CRLF, nStatus);
    sCodigo:=trim(copy(slinha,nPosChave,nTamChave));
    if sCodigo=sChave then
       btnAcao(sreg,[opConfirmaExclusao]);
  end;
end;
{------------------------------------------------------------------------------
Parte inicial do código
------------------------------------------------------------------------------}
begin
 if ParamStr(1)='-cria' then
     abrecriaArqs(false)
 else begin
   frmSplash;
   abrecriaArqs(true);
   if frmLogin then begin
     bopcao:=true;
     while(bopcao) do begin
       menu(1);
       readln(opmenu);
       if (opmenu='C') or (opmenu='c') then usaMenu(1)
       else if (opmenu='P') or (opmenu='p') then usaMenu(2)
       else if (opmenu='V') or (opmenu='v') then usaMenu(3)
       else if (opmenu='O') or (opmenu='o') then usaMenu(4)
       else writeln(MSG_ERRO);
     end;
   end else begin
     fechaArqs;
     halt;
   end;
 end;
end.
