-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Programa Livrus";
   author: "Henrique F. de Souza";

class LIVRUS

creation
  make

feature
  optexto: INTEGER is 1; opnumero: INTEGER is 2; opdata: INTEGER is 3; 
  opdatahora: INTEGER is 4; opsenha: INTEGER is 5;
  cttipo: SET[INTEGER];
 
  opassunto: INTEGER is 1; opautor: INTEGER is 2; opeditora: INTEGER is 3;
  opendereco: INTEGER is 4; opidioma: INTEGER is 5; oppais: INTEGER is 6; 
  opprofissao: INTEGER is 7; opcliente: INTEGER is 8; oplivro: INTEGER is 9; 
  oplivroass: INTEGER is 10; oplivroaut: INTEGER is 11; 
  opusuario: INTEGER is 12; opvenda: INTEGER is 13;
  ctarqs: SET[INTEGER];

  opnovo: INTEGER is 1; opalterar: INTEGER is 2; oppesquisar: INTEGER is 3; 
  opsalvarinclusao: INTEGER is 4; opsalvaralteracao: INTEGER is 5; 
  opexcluir: INTEGER is 6; opconfirmaexclusao: INTEGER is 7; 
  oplistartodos: INTEGER is 8;
  ctacao: SET[INTEGER];

-- constantes
  crlf: STRING is "%N"; -- windows
  tam_crlf: INTEGER is 2;
-- crlf = "%N";
-- tam_crlf = 1; -- unix 
-- crlf = "%R";
-- tam_crlf = 1; -- macintosh 

  qtd_max_linha: INTEGER is 18;

  msg_arqerro: STRING is "Erro: O arquivo não pode ser aberto.%N";
  msg_arqcerro: STRING is "Erro: O arquivo não pode ser criado.%N";
  msg_erro: STRING is "Erro: opção inválida digite de novo.%N";
  msg_opcao: STRING is "Escolha uma opção: ";
  msg_press: STRING is "pressione para continuar...";

  msg_reginc: STRING is "registro incluido!%N";
  msg_regninc: STRING is "registro não incluido!%N";
  msg_regalt: STRING is "registro alterado!%N";
  msg_regnalt: STRING is "registro não alterado!%N";
  msg_regexc: STRING is "registro excluido!%N";
  msg_regnexc: STRING is "registro não excluido!%N";
  msg_regexst: STRING is "registro já existe!%N";

  msg_numinv: STRING is "Número inválido ou menor do que 1!%N";
  msg_datainv: STRING is "Data inválida!, formato correto (dd/mm/yyyy)%N";
  msg_dthrinv: STRING is "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)%N";
  msg_isbninv: STRING is "ISBN inválido!%N";
  msg_cpfinv: STRING is "CPF inválido!%N";
  msg_senconfere: STRING is "senha não confere com a senha atual!%N";
  msg_senconfirm: STRING is "nova senha não confere com a senha confirmada!%N";
  msg_loginencon: STRING is "login não encontrado!%N";
  msg_semestoque: STRING is "livro não existe no estoque!%N";

  arq_assunto: STRING is "c:\temp\assunto.dat";
  arq_autor: STRING is "c:\temp\autor.dat";
  arq_editora: STRING is "c:\temp\editora.dat";
  arq_idioma: STRING is "c:\temp\idioma.dat";
  arq_usuario: STRING is "c:\temp\usuario.dat";
  arq_pais: STRING is "c:\temp\pais.dat";
  arq_profissao: STRING is "c:\temp\profissao.dat";
  arq_livro: STRING is "c:\temp\livro.dat";
  arq_livass: STRING is "c:\temp\livroass.dat";
  arq_livaut: STRING is "c:\temp\livroaut.dat";
  arq_cliente: STRING is "c:\temp\cliente.dat";
  arq_endereco: STRING is "c:\temp\endereco.dat";
  arq_venda: STRING is "c:\temp\venda.dat";

  tam_assunto: INTEGER is 40;
  tam_autor: INTEGER is 40;
  tam_editora: INTEGER is 60;
  tam_idioma: INTEGER is 30;
  tam_usuario: INTEGER is 20;
  tam_pais: INTEGER is 53;
  tam_profissao: INTEGER is 60;
  tam_livro: INTEGER is 143;
  tam_livass: INTEGER is 23;
  tam_livaut: INTEGER is 23;
  tam_cliente: INTEGER is 135;
  tam_endereco: INTEGER is 123;
  tam_venda: INTEGER is 56;

-- variaveis gerais

  bopcao: BOOLEAN;
  opmenu: STRING;
  g_nposchave, g_ntamchave, g_nposreg: INTEGER;  
  g_npreco: DOUBLE;
  g_salvarinclusao, g_regexcluido: BOOLEAN;
  
  tassunto: REGASSUNTO;
  tautor: REGAUTOR;
  teditora: REGEDITORA;
  tidioma: REGIDIOMA;
  tendereco: REGENDERECO;
  tpais: REGPAIS;
  tprofissao: REGPROFISSAO;
  tlivro: REGLIVRO;
  tlivroass: REGLIVROASS;
  tlivroaut: REGLIVROAUT;
  tcliente: REGCLIENTE;
  tusuario: REGUSUARIO;
  tvenda: REGVENDA;
  
  tfassunto, tfautor, tfeditora, tfidioma, tfendereco, 
  tfpais, tfprofissao, tflivro, tflivroass, tflivroaut, 
  tfcliente, tfusuario, tfvenda: TEXT_FILE_READ_WRITE;

feature 

-- ----------------------------------------------------------------------------
-- Parte inicial do código
-- ----------------------------------------------------------------------------
make is
local
do       
  inicializa;
  if argument_count > 1 then
    if argument(1).is_equal("-cria") then
      abrecriaarqs(false);
    end;
  else
    frmsplash;
    abrecriaarqs(true);
    if frmlogin then
      from
        bopcao:=true;
      until 
        bopcao=false
      loop
        menu(1);
        opmenu:=digita;
        if (opmenu.item(1)='C') or (opmenu.item(1)='c') then usamenu(1)
        elseif (opmenu.item(1)='P') or (opmenu.item(1)='p') then usamenu(2)
        elseif (opmenu.item(1)='V') or (opmenu.item(1)='v') then usamenu(3)
        elseif (opmenu.item(1)='O') or (opmenu.item(1)='o') then usamenu(4)
        else io.put_string(msg_erro);
        end;
      end;
    else
      fechaarqs;
      die_with_code(exit_success_code);      
    end;
  end;
end;

feature -- Rotinas básicas

-- ----------------------------------------------------------------------------
-- cria todos os objetos
-- ----------------------------------------------------------------------------
inicializa is
do
  create tassunto.make;
  create tautor.make;
  create teditora.make; 
  create tidioma.make;
  create tendereco.make; 
  create tpais.make; 
  create tprofissao.make;
  create tlivro.make;
  create tlivroass.make; 
  create tlivroaut.make; 
  create tcliente.make; 
  create tusuario.make; 
  create tvenda.make;

  create tfassunto.make;
  create tfautor.make;
  create tfeditora.make; 
  create tfidioma.make;
  create tfendereco.make; 
  create tfpais.make; 
  create tfprofissao.make;
  create tflivro.make;
  create tflivroass.make; 
  create tflivroaut.make; 
  create tfcliente.make; 
  create tfusuario.make; 
  create tfvenda.make;

  create {HASHED_SET[INTEGER]} cttipo.make;
  cttipo.add(optexto);
  cttipo.add(opnumero);
  cttipo.add(opdata);
  cttipo.add(opdatahora);
  cttipo.add(opsenha);

  create {HASHED_SET[INTEGER]} ctarqs.make;
  ctarqs.add(opassunto);
  ctarqs.add(opautor);
  ctarqs.add(opeditora);
  ctarqs.add(opendereco);
  ctarqs.add(opidioma);
  ctarqs.add(oppais);
  ctarqs.add(opprofissao);
  ctarqs.add(opcliente);
  ctarqs.add(oplivro);
  ctarqs.add(oplivroass);
  ctarqs.add(oplivroaut);
  ctarqs.add(opusuario);
  ctarqs.add(opvenda);

  create {HASHED_SET[INTEGER]} ctacao.make;
  ctacao.add(opnovo);
  ctacao.add(opalterar);
  ctacao.add(oppesquisar);
  ctacao.add(opsalvarinclusao);
  ctacao.add(opsalvaralteracao);
  ctacao.add(opexcluir);
  ctacao.add(opconfirmaexclusao);
  ctacao.add(oplistartodos);

end;
-- ----------------------------------------------------------------------------
-- Função que retorna um pedaço de uma string.
-- sstr - indica a string
-- nini - indica a posicao inicial do pedaco
-- ntam - indica o tamanho do pedaco
-- retorna - o pedaço da string
--- ---------------------------------------------------------------------------
substr(sstr: STRING; nini, ntam: INTEGER): STRING is
do
 result:=sstr.substring(nini,nini+ntam-1);
end;
-- ----------------------------------------------------------------------------
-- Retira os espaços em branco antes ou depois do texto.
-- sTexto - o texto a ser retirado os espaços em branco
-- retorna - o texto sem os espaços em branco
-- ----------------------------------------------------------------------------
trim(stexto: STRING): STRING is
do
  stexto.left_adjust;
  stexto.right_adjust;
  result:=stexto;
end;
-- ----------------------------------------------------------------------------
-- Repete um texto um número determinado de vezes.
-- sTexto - o texto a ser repetido
-- nQtd - a quantidade de vezes
-- retorna - o texto repetido
-- ----------------------------------------------------------------------------
repete(stexto: CHARACTER; nqtd: INTEGER): STRING is
local
 stemp: STRING;
do
  stemp:="";
  stemp.extend_multiple(stexto,nqtd);
  result:=stemp;
end;
-- ----------------------------------------------------------------------------
-- Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
-- sTexto - o texto
-- nTam - tamanho máximo do texto
-- retorna - o texto com espaços em branco a mais
------------------------------------------------------------------------------
esp(stexto: STRING; ntam: INTEGER): STRING is
do
  result:=stexto+repete(' ',ntam-stexto.count);
end;
-- ----------------------------------------------------------------------------
-- Escreve zeros na frente de um texto.
-- stexto - o texto para receber zeros a frente
-- ntam - o tamanho da string
-- retorna - o texto com o zeros antes
-- ----------------------------------------------------------------------------
zeros(stexto:STRING; ntam:INTEGER): STRING is
local 
  ncont: INTEGER;
  saux: STRING;
do
  saux:="";
  if ntam/=stexto.count then
    from
      ncont:=1 
    until
      ncont > ntam-stexto.count
    loop
      saux:=saux + "0";
      ncont:=ncont + 1;
    end;
  end;
  result:=saux+stexto;
end;
-- ----------------------------------------------------------------------------
-- Faz uma pesquisa relativa de um texto através de um valor chave.
-- sTexto - o texto
-- sChave - a chave a ser pesquisada
-- retorna - se achou ou não a chave dentro do texto
-- ----------------------------------------------------------------------------
strrelativa(stexto, schave: STRING): BOOLEAN is
do
 result:=stexto.has_substring(schave);
end;
-- ----------------------------------------------------------------------------
-- Calcula o modulo11 de um valor qualquer.
-- svalor - a mstring com o número a ser calculado
-- ndig - dígito do valor a ser calculado
-- retorna - o dígito correto
-- ----------------------------------------------------------------------------}
modulo11(svalor: STRING; ndig: INTEGER): INTEGER is
local 
  ncont, nsoma, nvalor, npos: INTEGER;
  sres, slocal: STRING;
do
  ncont:=1;
  slocal:="";
  from 
    ncont := 1;
  until
    ncont > 11
  loop
    slocal:=substr(svalor,ncont,1) + slocal;
    ncont:=ncont+1;
  end;
  nsoma:=0;
  npos:=2;
  from 
    if ndig=1 then
      ncont:=3;
    else
      ncont:=2;
    end; 
  until
    ncont > 11
  loop
    sres:=substr(slocal,ncont,1);
    nvalor:=sres.to_integer;
    nsoma:=nsoma + (nvalor * npos);
    ncont:=ncont+1;
    npos:=npos+1;
  end;
  nsoma:=(11 - (nsoma \\ 11));

  if nsoma > 9 then
    result:=0;
  else
    result:=nsoma;
  end;
end;
-- ----------------------------------------------------------------------------
-- Validação de um número de CPF qualquer.
-- cpf - a mstring com o número do CPF
-- retorna - se é valido ou não
-- ----------------------------------------------------------------------------
validacpf(cpf: STRING): BOOLEAN is
local 
  scpf, sres: STRING;
  nvalor1, nvalor2: INTEGER;
do
if (cpf.count=14) then 
  scpf:=substr(cpf,1,3)+substr(cpf,5,3)+substr(cpf,9,3)+substr(cpf,13,2);
  sres:=substr(cpf,13,1);
  nvalor1:=sres.to_integer;
  sres:=substr(cpf,14,1);
  nvalor2:=sres.to_integer;
  if ((modulo11(scpf,1)=nvalor1) and (modulo11(scpf,2)=nvalor2)) then
    result:=true;
  else
    result:=false;
  end;
else
  result:=false;
end;
end;
-- ----------------------------------------------------------------------------
-- Validação de um número ISBN qualquer.
-- isbn - a mstring com o número do ISBN
-- retorna - se é valido ou não
-- ----------------------------------------------------------------------------
validaisbn(isbn: STRING): BOOLEAN is
local 
  snum, sdigito, sisbn: STRING;
  nvalor, nsoma, ncont: INTEGER;
do
if (isbn.count=13) then
  sdigito := substr(isbn, isbn.count, 1);
  sisbn:="";
  from 
    ncont := 1;
  until
    ncont > isbn.count-1
  loop
    if substr(isbn,ncont,1) /= "-" then
      sisbn:=sisbn+substr(isbn,ncont,1);
    end;
    ncont:=ncont + 1;
  end;
  if sdigito = "X" then
    nsoma := 10
  else
    nvalor:=sdigito.to_integer;
    nsoma := nvalor;
  end;
  from 
    ncont := 1;
  until
    ncont > 9
  loop
    snum:=substr(sisbn, ncont, 1);
    nvalor:=snum.to_integer;
    nsoma:=nsoma + (nvalor * (11 - ncont));
    ncont:=ncont + 1;
  end;
  if (nsoma \\ 11) = 0 then
    result:=true;
  else
    result:=false;
  end;
else
  result:=false;
end;
end;
-- ----------------------------------------------------------------------------
-- realiza a digitação de algum texto
-- retorna - o texto digitado
-- ----------------------------------------------------------------------------
digita: STRING is
do
  io.read_line;
  if io.last_string.is_empty then
    io.flush;
    io.read_line;
  end
  result:=io.last_string;
end;
-- ----------------------------------------------------------------------------
-- Esconde a digitação da senha
-- retorna - a senha digitada
-- ----------------------------------------------------------------------------
digitasenha(srotulo: STRING; ntamsenha: INTEGER): STRING is
local
  ssenha: STRING;
--  sletra: CHARACTER;
--  ncont: INTEGER;
do
  io.put_string(srotulo);
  ssenha:=digita
--  ssenha:="";
--  sletra:='%U';
--  from 
--    ncont := 1;
--  until
--    (ncont > ntamsenha) and (sletra = '%R')
--  loop
--    io.read_character;
--    sletra:=io.last_character;
--    ssenha.insert_character(sletra,ncont);
--    ncont:=ncont+1;
--  end;
  result:=ssenha;
end;
-- ----------------------------------------------------------------------------
-- Validação de um número qualquer.
-- sRotulo - o texto antes de se digitar o número
-- sNumero - a mstring com o valor do número
-- retorna - o sNumero
-- ----------------------------------------------------------------------------
validanumero(srotulo, snumero: STRING): STRING is
local
  nnum: DOUBLE;
  nstatus: INTEGER;
  slocal: STRING;
do
slocal:=snumero;
from
  nstatus:=-1;
until
  nstatus = 0
loop
  io.put_string(srotulo);
  slocal:=digita;
  if slocal.is_double then
    nnum:=slocal.to_double;
    if nnum < 0.01 then
      io.put_string(msg_numinv);
    else
      nstatus:=0;
    end;
  else
    io.put_string(msg_numinv);
  end;
end;
result:=slocal;
end;
-- ----------------------------------------------------------------------------
-- Validação de uma data ou data/hora qualquer.
-- sRotulo - o texto antes de se digitar a data/hora
-- sDataHora - a mstring com o valor da data/hora
-- bSoData - indica se vai validar somente uma data sem a hora
-- retorna - a sDataHora
-- ----------------------------------------------------------------------------
validadatahora(srotulo, sdatahora: STRING; bsodata: BOOLEAN): STRING is
local
  bvalida, bdatavalida, bhoravalida: BOOLEAN;
  sdia, smes, sano, shora, smin, sseg, slocal: STRING;
  ndia, nmes, nano, nhora, nmin, nseg, nudiames, ntam: INTEGER;
do
from
  slocal:=sdatahora;
  bvalida:=false;
  bdatavalida:=false;
  bhoravalida:=false;
  nudiames:=0;
  
  if bsodata=true then
    ntam:=10;
  else 
    ntam:=19;
  end;
until
  bvalida=true
loop
  io.put_string(srotulo);
  slocal:=digita;
  if slocal.count=ntam then 
    sdia:=substr(slocal,1,2);
    ndia:=sdia.to_integer;
    smes:=substr(slocal,4,2);
    nmes:=smes.to_integer;
    sano:=substr(slocal,7,4);
    nano:=sano.to_integer;
  
    if (nano >= 1) and (nano <= 9999) then
      if (nmes >= 1) and (nmes <= 31) then
         inspect nmes
           when 1, 3, 5, 7, 8, 10, 12 then nudiames:=31;
           when 2 then
               -- ano bissexto
               if (nano \\ 4)=0 then nudiames:=29
               else nudiames:=28; 
               end;
           when 4, 6, 9, 11 then nudiames:=30;
         end;
         if (ndia >=1) and (ndia <=nudiames) then
            bdatavalida:=true;
         end;
      end;
    end;
  
    if bsodata then
       if bdatavalida then bvalida:=true
       else 
         io.put_string(msg_datainv);
         io.put_new_line;   
       end;
    else
      if bdatavalida then
          shora:=substr(slocal,12,2);
          nhora:=shora.to_integer;
          smin:=substr(slocal,15,2);
          nmin:=smin.to_integer;
          sseg:=substr(slocal,18,2);
          nseg:=sseg.to_integer;
  
          if (nhora >= 0) and (nhora <= 23) then
            if (nmin >= 0) and (nmin <= 59) then
              if (nseg >= 0) and (nseg <= 59) then
                 bhoravalida:=true;
              end;
            end;
          end;
  
          if bhoravalida then bvalida:=true
          else io.put_string(msg_dthrinv);
          end; 
      else
        io.put_string(msg_dthrinv);
      end;
    end;
  else
    if bsodata=true then io.put_string(msg_datainv)
    else io.put_string(msg_dthrinv);
    end;
  end;
end;
result:=slocal;
end;
-- ----------------------------------------------------------------------------
-- Retorna a Data e a hora do sistema.
-- retorna - a data e a hora
-- ----------------------------------------------------------------------------
retdatahora: STRING is
local 
  tempo: TIME;
  sdia,smes,sano,shora,smin,sseg: STRING;
do
  tempo.update;
  sdia:=tempo.day.to_string;
  smes:=tempo.month.to_string;
  sano:=tempo.year.to_string;
  shora:=tempo.hour.to_string;
  smin:=tempo.minute.to_string;
  sseg:=tempo.second.to_string;
  result:=zeros(sdia,2)+"/"+zeros(smes,2)+"/"+sano+" "+
  zeros(shora,2)+":"+zeros(smin,2)+":"+zeros(sseg,2);
end;
-- ----------------------------------------------------------------------------
-- Calcula o tamanho do arquivo.
-- sArq - o arquivo
-- retorna - o tamanho do arquivo
-- ----------------------------------------------------------------------------
tamarq(sarq: STRING): INTEGER is
do
  result:=file_tools.size_of(sarq);
end;
-- ----------------------------------------------------------------------------
-- Abre ou cria os arquivos do sistema.
-- bAbre - condição para abrir ou criar os arquivos do sistema
-- ----------------------------------------------------------------------------
abrecriaarqs(babre: BOOLEAN) is
do
  if babre=true then 
    tfassunto.connect_to(arq_assunto);
    if tfassunto.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_assunto);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfautor.connect_to(arq_autor);
    if tfautor.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_autor);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfeditora.connect_to(arq_editora);
    if tfeditora.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_editora);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfidioma.connect_to(arq_idioma);
    if tfidioma.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_idioma);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfendereco.connect_to(arq_endereco);
    if tfendereco.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_endereco);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfpais.connect_to(arq_pais);
    if tfpais.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_pais);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfprofissao.connect_to(arq_profissao);
    if tfprofissao.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_profissao);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tflivro.connect_to(arq_livro);
    if tflivro.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_livro);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tflivroass.connect_to(arq_livass);
    if tflivroass.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_livass);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tflivroaut.connect_to(arq_livaut);
    if tflivroaut.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_livaut);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfcliente.connect_to(arq_cliente);
    if tfcliente.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_cliente);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfusuario.connect_to(arq_usuario);
    if tfusuario.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_usuario);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfvenda.connect_to(arq_venda);
    if tfvenda.is_connected=false then
      io.put_string(msg_arqerro+" --> "+arq_venda);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
  else  
    tfassunto.connect_for_appending_to(arq_assunto);
    if tfassunto.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_assunto);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfautor.connect_for_appending_to(arq_autor);
    if tfautor.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_autor);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfeditora.connect_for_appending_to(arq_editora);
    if tfeditora.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_editora);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfidioma.connect_for_appending_to(arq_idioma);
    if tfidioma.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_idioma);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfendereco.connect_for_appending_to(arq_endereco);
    if tfendereco.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_endereco);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfpais.connect_for_appending_to(arq_pais);
    if tfpais.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_pais);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfprofissao.connect_for_appending_to(arq_profissao);
    if tfprofissao.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_profissao);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tflivro.connect_for_appending_to(arq_livro);
    if tflivro.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_livro);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tflivroass.connect_for_appending_to(arq_livass);
    if tflivroass.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_livass);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tflivroaut.connect_for_appending_to(arq_livaut);
    if tflivroaut.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_livaut);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfcliente.connect_for_appending_to(arq_cliente);
    if tfcliente.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_cliente);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfusuario.connect_for_appending_to(arq_usuario);
    if tfusuario.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_usuario);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
    tfvenda.connect_for_appending_to(arq_venda);
    if tfvenda.is_connected=false then
      io.put_string(msg_arqcerro+" --> "+arq_venda);
      io.put_new_line;
      die_with_code(exit_failure_code);
    end;
  end;
end;
-- ----------------------------------------------------------------------------
-- Fecha todos os arquivos abertos.
-- ----------------------------------------------------------------------------
fechaarqs is
do
  tfassunto.disconnect;
  tfautor.disconnect;
  tfeditora.disconnect;
  tfidioma.disconnect;
  tfendereco.disconnect;
  tfpais.disconnect;
  tfprofissao.disconnect;
  tflivro.disconnect;
  tflivroass.disconnect;
  tflivroaut.disconnect;
  tfcliente.disconnect;
  tfusuario.disconnect;
  tfvenda.disconnect;
end;
-- ----------------------------------------------------------------------------
-- Reconecta o arquivo
-- sArq - o arquivo
-- ----------------------------------------------------------------------------
reconecta(sarq: TEXT_FILE_READ_WRITE) is
local
  snomearq: STRING;
do
  snomearq:=sarq.path;
  sarq.disconnect;
  sarq.connect_to(snomearq);
end;
-- ----------------------------------------------------------------------------
-- Pesquisa um registro através de um valor chave num arquivo.
-- sArq - o arquivo
-- sChave - a chave a ser pesquisada
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o registro pesquisado
-- ----------------------------------------------------------------------------
pesqarq(sarq: TEXT_FILE_READ_WRITE; schave: STRING; nposchave,
        ntamchave, ntamlinha: INTEGER): STRING is
local
  slinha, sres: STRING;
  bquebra: BOOLEAN;
  nposicao: INTEGER;
do
  reconecta(sarq);
  from
    sres:="";
    slinha:="";
    bquebra:=false;
    nposicao:=0;
  until
    sarq.end_of_input or bquebra=true
  loop
    slinha.clear_count;
    sarq.read_line_in(slinha);
    if slinha.is_empty=false then
      sres:=trim(substr(slinha,nposchave,ntamchave));
      if sres.is_equal(schave) then
        bquebra:=true;  
      end;
      nposicao:=nposicao+1;
    end;
  end;
  g_nposreg:=nposicao;
  if sres.is_equal(schave)=false then
    result:=""
  else
    result:=substr(slinha,1,ntamlinha);
  end;
end;
-- ----------------------------------------------------------------------------
-- Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
-- sArq - o arquivo
-- nTamLinha - o tamanho do registro
-- ----------------------------------------------------------------------------
pesqlinhaexcluida(sarq: TEXT_FILE_READ_WRITE; ntamlinha: INTEGER) is
local 
  sexcluido: STRING;
do
  sexcluido:=pesqarq(sarq, "*", 1, 1, ntamlinha);
  if sexcluido.is_empty then
     -- g_nposreg:=tamarq(sarq.path);
    g_regexcluido:=false;
  else
    g_regexcluido:=true;
  end;
end;
-- ----------------------------------------------------------------------------
-- Pesquisa o maior código num arquivo.
-- sArq - o arquivo
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- nTamLinha - o tamanho do registro
-- retorna - o maior código
-- ----------------------------------------------------------------------------
pesqmaxcod(sarq: TEXT_FILE_READ_WRITE; nposchave,
           ntamchave, ntamlinha: INTEGER): STRING is
local
  slinha, sres: STRING;
  nmaior, ncod, nposicao: INTEGER;
do
  reconecta(sarq);
  from
    slinha:="";
    nmaior:=0;
    nposicao:=0;
  until
    sarq.end_of_input
  loop
    slinha.clear_count;
    sarq.read_line_in(slinha);
    if slinha.is_empty=false then
      sres:=trim(substr(slinha,nposchave,ntamchave));
      ncod:=sres.to_integer;
      if ncod > nmaior then
        nmaior:=ncod;
      end;  
      nposicao:=nposicao+1;
    end;
  end;  
  pesqlinhaexcluida(sarq, ntamlinha);
  if g_regexcluido=false then
    g_nposreg:=nposicao+1;
  end 
  sres:=(nmaior+1).to_string;
  result:=sres;
end;
-- ----------------------------------------------------------------------------
-- Grava os registros num determinado arquivo.
-- sArq - o arquivo
-- sTexto - o registro a ser gravado
-- sMsgAcerto - a mensagem caso o registro foi gravado
-- sMsgErro - a mensagem caso o registro não foi gravado
-- ----------------------------------------------------------------------------
escrevearq(sarq: TEXT_FILE_READ_WRITE; stexto, smsgacerto, 
           smsgerro: STRING) is
local
  sarqgrava: TEXT_FILE_WRITE;
  slinha, snomearq, stemparq: STRING;
  nposicao: INTEGER;
do
  reconecta(sarq);
  stemparq:="temp.dat";
  create sarqgrava.make;
  sarqgrava.connect_to(stemparq);
  if sarqgrava.is_connected then
    from
      slinha:="";
      nposicao:=1;
    until
      sarq.end_of_input
    loop
      if g_nposreg=nposicao then        
        sarqgrava.put_string(stexto + crlf);
        sarq.read_line;
      else      
        sarq.read_line;
        slinha:=sarq.last_string;
        if slinha.is_empty=false then
          sarqgrava.put_string(slinha + crlf);
        end;
      end;
      nposicao:=nposicao+1;
    end;
    if g_nposreg=nposicao then
      sarqgrava.put_string(stexto + crlf);
    end;
    sarqgrava.disconnect

    snomearq := sarq.path;
    sarq.disconnect;
    file_tools.delete(snomearq);
    file_tools.rename_to(stemparq, snomearq);
    sarq.connect_to(snomearq);

    io.put_string(smsgacerto);
  else
    io.put_string(smsgerro);
  end 
end;
-- ----------------------------------------------------------------------------
-- Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o registro montado
-- ----------------------------------------------------------------------------
linhareg(sreg: INTEGER): STRING is
local 
  slinha: STRING;
do
slinha:="";
if ctarqs.item(opassunto)=sreg then
 slinha:=esp(tassunto.codigo,10)+esp(tassunto.assunto,30)
elseif ctarqs.item(opautor)=sreg then
 slinha:=esp(tautor.codigo,10)+esp(tautor.autor,30)
elseif ctarqs.item(opeditora)=sreg then
 slinha:=esp(teditora.codigo,10)+esp(teditora.editora,50)
elseif ctarqs.item(opendereco)=sreg then
 slinha:=esp(tendereco.codigo,10)+esp(tendereco.logradouro,40)+
 esp(tendereco.bairro,15)+esp(tendereco.cep,8)+
 esp(tendereco.cidade,30)+esp(tendereco.estado,20)
elseif ctarqs.item(opidioma)=sreg then
 slinha:=esp(tidioma.codigo,10)+esp(tidioma.idioma,20)
elseif ctarqs.item(oppais)=sreg then
 slinha:=esp(tpais.codigo,3)+esp(tpais.pais,50)
elseif ctarqs.item(opprofissao)=sreg then
 slinha:=esp(tprofissao.codigo,10)+esp(tprofissao.profissao,50)
elseif ctarqs.item(opusuario)=sreg then
 slinha:=esp(tusuario.login,10)+esp(tusuario.senha,10)
elseif ctarqs.item(oplivro)=sreg then
 slinha:=esp(tlivro.isbn,13)+esp(tlivro.titulo,50)+
 esp(tlivro.edicao,10)+esp(tlivro.anopubli,10)+
 esp(tlivro.codeditora,10)+esp(tlivro.volume,10)+
 esp(tlivro.codidioma,10)+esp(tlivro.npaginas,10)+
 esp(tlivro.preco,10)+esp(tlivro.qtdestoque,10)
elseif ctarqs.item(oplivroass)=sreg then
 slinha:=esp(tlivroass.isbn,13)+esp(tlivroass.codassunto,10)
elseif ctarqs.item(oplivroaut)=sreg then
 slinha:=esp(tlivroaut.isbn,13)+esp(tlivroaut.codautor,10)
elseif ctarqs.item(opcliente)=sreg then
 slinha:=esp(tcliente.cpf,14)+esp(tcliente.nome,30)+
 esp(tcliente.email,30)+esp(tcliente.identidade,10)+
 esp(tcliente.sexo,1)+esp(tcliente.telefone,17)+
 esp(tcliente.dtnascimento,10)+esp(tcliente.codendereco,10)+
 esp(tcliente.codpais,3)+esp(tcliente.codprofissao,10)
elseif ctarqs.item(opvenda)=sreg then
 slinha:=esp(tvenda.dthrvenda,19)+esp(tvenda.cpf,14)+
 esp(tvenda.isbn,13)+esp(tvenda.precovenda,10);
end;
result:=slinha;
end;
-- ----------------------------------------------------------------------------
-- retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- retorna - o tamanho do registro
-- ----------------------------------------------------------------------------
tamreg(sreg: INTEGER): INTEGER is
local
  nret: INTEGER;
do
  nret:=0;
  if ctarqs.item(opassunto)=sreg then nret:=tam_assunto
  elseif ctarqs.item(opautor)=sreg then nret:=tam_autor
  elseif ctarqs.item(opeditora)=sreg then nret:=tam_editora
  elseif ctarqs.item(opendereco)=sreg then nret:=tam_endereco
  elseif ctarqs.item(opidioma)=sreg then nret:=tam_idioma
  elseif ctarqs.item(oppais)=sreg then nret:=tam_pais
  elseif ctarqs.item(opprofissao)=sreg then nret:=tam_profissao
  elseif ctarqs.item(opusuario)=sreg then nret:=tam_usuario
  elseif ctarqs.item(oplivro)=sreg then nret:=tam_livro
  elseif ctarqs.item(oplivroass)=sreg then nret:=tam_livass
  elseif ctarqs.item(oplivroaut)=sreg then nret:=tam_livaut
  elseif ctarqs.item(opcliente)=sreg then nret:=tam_cliente
  elseif ctarqs.item(opvenda)=sreg then nret:=tam_venda;
  end;
  result:=nret;
end;
-- ----------------------------------------------------------------------------
-- seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- nnum - indica qual rotulo será retornado
-- retorna - o rotulo
-- ----------------------------------------------------------------------------
rotulo(sreg: INTEGER; nnum: INTEGER): STRING is
local
  sret: STRING;
do
sret:="";
if ctarqs.item(opassunto)=sreg then 
   inspect nnum
     when 0 then sret:="Assunto(s) não encontrado(s)!%N";
     when 1 then
         sret:="Código do assunto: ";
         g_nposchave:=1;
         g_ntamchave:=10;
     when 2 then
         sret:="Assunto: ";
         g_nposchave:=11;
         g_ntamchave:=30;
   end;
elseif ctarqs.item(opautor)=sreg then
   inspect nnum
     when 0 then sret:="Autor(es) não encontrado(s)!%N";
     when 1 then
         sret:="Código do autor: ";
         g_nposchave:=1;
         g_ntamchave:=10;

     when 2 then
         sret:="Autor: ";
         g_nposchave:=11;
         g_ntamchave:=30;
   end;
elseif ctarqs.item(opeditora)=sreg then
   inspect nnum
     when 0 then sret:="Editora(s) não encontrada(s)!%N";
     when 1 then
         sret:="Código da editora: ";
         g_nposchave:=1;
         g_ntamchave:=10;
     when 2 then
         sret:="Editora: ";
         g_nposchave:=11;
         g_ntamchave:=50;
   end;
elseif ctarqs.item(opendereco)=sreg then
   inspect nnum
     when 0 then sret:="Endereço(s) não encontrado(s)!%N";
     when 1 then
         sret:="Código do endereço: ";
         g_nposchave:=1;
         g_ntamchave:=10;
     when 2 then
         sret:="Logradouro: ";
         g_nposchave:=11;
         g_ntamchave:=40;
     when 3 then
         sret:="Bairro: ";
         g_nposchave:=51;
         g_ntamchave:=15;
     when 4 then
         sret:="CEP: ";
         g_nposchave:=66;
         g_ntamchave:=8;
     when 5 then
         sret:="Cidade: ";
         g_nposchave:=74;
         g_ntamchave:=30;
     when 6 then
         sret:="Estado: ";
         g_nposchave:=104;
         g_ntamchave:=20;
   end;
elseif ctarqs.item(opidioma)=sreg then
   inspect nnum
     when 0 then sret:="Idioma(s) não encontrado(s)!%N";
     when 1 then
         sret:="Código do idioma: ";
         g_nposchave:=1;
         g_ntamchave:=10;
     when 2 then
         sret:="Idioma: ";
         g_nposchave:=11;
         g_ntamchave:=20;
   end;
elseif ctarqs.item(oppais)=sreg then
   inspect nnum
     when 0 then sret:="País(es) não encontrado(s)!%N";
     when 1 then
         sret:="Código do país: ";
         g_nposchave:=1;
         g_ntamchave:=3;
     when 2 then
         sret:="País: ";
         g_nposchave:=4;
         g_ntamchave:=50;
   end;
elseif ctarqs.item(opprofissao)=sreg then
   inspect nnum
     when 0 then sret:="Profissão(es) não encontrada(s)!%N";
     when 1 then
         sret:="Código da profissão: ";
         g_nposchave:=1;
         g_ntamchave:=10;
     when 2 then
         sret:="Profissão: ";
         g_nposchave:=11;
         g_ntamchave:=50;
   end;
elseif ctarqs.item(opusuario)=sreg then
   inspect nnum
     when 0 then sret:="login ou senha incorreta, tente de novo!%N";
     when 1 then
         sret:="Login: ";
         g_nposchave:=1;
         g_ntamchave:=10;
     when 2 then
         sret:="Senha: ";
         g_nposchave:=11;
         g_ntamchave:=10;
   end;
elseif ctarqs.item(oplivro)=sreg then
   inspect nnum
     when 0 then sret:="Livro(s) não encontrado(s)!%N";
     when 1 then
         sret:="ISBN: ";
         g_nposchave:=1;
         g_ntamchave:=13;
     when 2 then
         sret:="Título: ";
         g_nposchave:=14;
         g_ntamchave:=50;
     when 3 then
         sret:="Edição: ";
         g_nposchave:=64;
         g_ntamchave:=10;
     when 4 then
         sret:="Ano de Publicação: ";
         g_nposchave:=74;
         g_ntamchave:=10;
     when 5 then
         sret:="Código da editora: ";
         g_nposchave:=84;
         g_ntamchave:=10;
     when 6 then
         sret:="Volume: ";
         g_nposchave:=94;
         g_ntamchave:=10;
     when 7 then
         sret:="Código do idioma: ";
         g_nposchave:=104;
         g_ntamchave:=10;
     when 8 then
         sret:="Número de páginas: ";
         g_nposchave:=114;
         g_ntamchave:=10;
     when 9 then
         sret:="Preço: ";
         g_nposchave:=124;
         g_ntamchave:=10;
     when 10 then
          sret:="Qtd. Estoque: ";
          g_nposchave:=134;
          g_ntamchave:=10;
   end;
elseif ctarqs.item(oplivroass)=sreg then
   inspect nnum
     when 0 then sret:="Assunto(s) não encontrado(s)!%N";
     when 1 then
         sret:="ISBN: ";
         g_nposchave:=1;
         g_ntamchave:=13;
     when 2 then
         sret:="Código do assunto: ";
         g_nposchave:=14;
         g_ntamchave:=10;
   end;
elseif ctarqs.item(oplivroaut)=sreg then
   inspect nnum
     when 0 then sret:="Autor(s) não encontrado(s)!%N";
     when 1 then
         sret:="ISBN: ";
         g_nposchave:=1;
         g_ntamchave:=13;
     when 2 then
         sret:="Código do autor: ";
         g_nposchave:=14;
         g_ntamchave:=10;
   end;
elseif ctarqs.item(opcliente)=sreg then
   inspect nnum
     when 0 then sret:="Cliente(s) não encontrado(s)!%N";
     when 1 then
         sret:="CPF: ";
         g_nposchave:=1;
         g_ntamchave:=14;
     when 2 then
         sret:="Nome: ";
         g_nposchave:=15;
         g_ntamchave:=30;
     when 3 then
         sret:="E-mail: ";
         g_nposchave:=45;
         g_ntamchave:=30;
     when 4 then
         sret:="Identidade: ";
         g_nposchave:=75;
         g_ntamchave:=10;
     when 5 then
         sret:="Sexo: ";
         g_nposchave:=85;
         g_ntamchave:=1;
     when 6 then
         sret:="Telefone: ";
         g_nposchave:=86;
         g_ntamchave:=17;
     when 7 then
         sret:="Dt. Nascimento: ";
         g_nposchave:=103;
         g_ntamchave:=10;
     when 8 then
         sret:="Código do endereço: ";
         g_nposchave:=113;
         g_ntamchave:=10;
     when 9 then
         sret:="Código do país: ";
         g_nposchave:=123;
         g_ntamchave:=3;
     when 10 then
          sret:="Código da Profissão: ";
          g_nposchave:=126;
          g_ntamchave:=10;
   end;
elseif ctarqs.item(opvenda)=sreg then
   inspect nnum
     when 0 then sret:="Venda(s) não encontrada(s)!%N";
     when 1 then
         sret:="Data/Hora venda: ";
         g_nposchave:=1;
         g_ntamchave:=19;
     when 2 then
         sret:="CPF: ";
         g_nposchave:=20;
         g_ntamchave:=14;
     when 3 then
         sret:="ISBN: ";
         g_nposchave:=34;
         g_ntamchave:=13;
     when 4 then
         sret:="Preço de venda: ";
         g_nposchave:=47;
         g_ntamchave:=10;
   end;
end;

result:=sret;
end;
-- ----------------------------------------------------------------------------
-- Indica se continua ou não mostrando um número máximo de linhas.
-- nlinha - a linha a ser continuada
-- nQtdLinha - a quantidade de linhas a serem mostradas
-- retorna - se continua ou não
-- ----------------------------------------------------------------------------
continuasn(nlinha, nqtdlinha: INTEGER): BOOLEAN is
local
  bsop, bret: BOOLEAN;
  opcsubmenu: STRING;
do
bret:=false;
if nlinha > 0 then
  if (nlinha \\ nqtdlinha) = 0 then
     from      
       bsop:=true;
     until 
       bsop=false
     loop
       menu(13);
       opcsubmenu:=digita;
       if (opcsubmenu.item(1)='s') or (opcsubmenu.item(1)='s') then 
         bsop:=false
       elseif (opcsubmenu.item(1)='n') or (opcsubmenu.item(1)='n') then
         bret:=true;
         bsop:=false;
       else 
         io.put_string(msg_erro);
       end;
     end;
  end;
end;
result:=bret;
end;
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
listartodos(sarq: TEXT_FILE_READ_WRITE; sreg: INTEGER; schave: STRING;
   nposchave, ntamchave, ntamlinha, nqtdlinha: INTEGER;
   bpesqrelativa: BOOLEAN): BOOLEAN is
local 
  slinha, sres: STRING;
  bquebra, bachou, bret: BOOLEAN;
  ncont: INTEGER;
do
  reconecta(sarq);
  bret:=false;
  mostrardados(sreg, "", 2);
  from
    sres:="";
    slinha:="";
    bquebra:=false;
    ncont:=0;
  until
    sarq.end_of_input or bquebra=true
  loop
    slinha.clear_count;
    sarq.read_line_in(slinha);
    if slinha.is_empty=false then
      if bpesqrelativa=true then
        sres:=trim(substr(slinha,nposchave,ntamchave));

        if strrelativa(sres,schave) then
          bachou:=true;
          bret:=true;
        else
          bachou:=false;
        end;
      else
        bachou:=true;
        bret:=true;
      end;
    
      if bachou then
        mostrardados(sreg, substr(slinha,1,ntamlinha), 3);
        ncont:=ncont+1;
      end;
    
      bquebra:=continuasn(ncont, nqtdlinha);
    end;
  end;
result:=bret;
end;
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
listarregligados(sarq1: TEXT_FILE_READ_WRITE; sreg1, nposchave1,
  ntamchave1, nposchave2, ntamchave2: INTEGER; schave: STRING;
  sarq2: TEXT_FILE_READ_WRITE; sreg2, nposchave3, nqtdlinha: INTEGER) is
local
  bquebra, bret: BOOLEAN;
  ncont: INTEGER;
  slinha1, scodigo1, scodigo2, slinha2: STRING;
do
  reconecta(sarq1);
  bret:=false;
  mostrardados(sreg2, "", 2);
  from
    slinha1:="";
    bquebra:=false;
    ncont:=0;
  until
    sarq1.end_of_input or bquebra=true
  loop
    slinha1.clear_count;
    sarq1.read_line_in(slinha1);
    if slinha1.is_empty=false then
      scodigo1:=trim(substr(slinha1,nposchave1,ntamchave1));
      if scodigo1.is_equal(schave) then
        scodigo2:=trim(substr(slinha1,nposchave2,ntamchave2));
        slinha2:=pesqarq(sarq2,scodigo2,nposchave3,ntamchave2,tamreg(sreg2));
        mostrardados(sreg2, substr(slinha2, 1, tamreg(sreg2)), 3);
        bret:=true;
        ncont:=ncont+1;
      end;
      bquebra:=continuasn(ncont, nqtdlinha);
    end;
  end;
  if bret=false then
     io.put_string(rotulo(sreg2,0));
  end;
end;
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
validaentrada(sarq: TEXT_FILE_READ_WRITE; sreg, ntexto: INTEGER;
        sentrada: STRING; ntentativas: INTEGER;
        bpesqrelativa: BOOLEAN; btipoentrada: INTEGER): STRING is
local
  bquebra: BOOLEAN;
  slocal, sres, stexto, smsgerro: STRING;
  ncont, nposchave, ntamchave, ntamlinha: INTEGER;
do
  ntamlinha:=tamreg(sreg);
  smsgerro:=rotulo(sreg,0);
  stexto:=rotulo(sreg,ntexto);
  nposchave:=g_nposchave;
  ntamchave:=g_ntamchave;
  slocal:=sentrada;
  sres:="";
  from
    ncont:=1;
    bquebra:=false;
  until
    bquebra=true or ncont > ntentativas
  loop
    if cttipo.item(optexto) = btipoentrada then
      io.put_string(stexto);
      slocal:=digita;
    elseif cttipo.item(opnumero) = btipoentrada then
       slocal:=validanumero(stexto,sentrada)
    elseif cttipo.item(opdata) = btipoentrada then
       slocal:=validadatahora(stexto,sentrada,true)
    elseif cttipo.item(opdatahora) = btipoentrada then
       slocal:=validadatahora(stexto,sentrada,false)
    elseif cttipo.item(opsenha) = btipoentrada then
       slocal:=digitasenha(stexto, 10);
    end;
 
    if bpesqrelativa then
      if listartodos(sarq, sreg, slocal, nposchave, ntamchave, ntamlinha,
                    qtd_max_linha, true) then
        sres:=" ";
      end;
    else
      sres:=pesqarq(sarq, slocal, nposchave, ntamchave, ntamlinha);
    end;
    if sres.is_empty then
       io.put_string(smsgerro);
    else
       bquebra:=true;
    end;
    ncont:=ncont+1;
  end;
result:=sres;
end;
-- ----------------------------------------------------------------------------
-- Mostra a tela de splash do sistema.
-- ----------------------------------------------------------------------------
frmsplash is
local
  ncont: INTEGER;
do
 io.put_string("*---------------------------------------"+
 "-------------------------------------*%N");
 io.put_string("| LL    II VV   VV RRRRR  UU  UU   SSSS "+
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |%N");
 io.put_string("| LL    II  VV VV  RR   R UU  UU  SS    "+
 " VV VV  II RR   R  TT  UU  UU  SS    |%N");
 io.put_string("| LL    II   VVV   RRRRR  UU  UU    SS  "+
 "  VVV   II RRRRR   TT  UU  UU    SS  |%N");
 io.put_string("| LLLLL II    V    RR   R  UUUU  SSSS   "+
 "   V    II RR   R  TT   UUUU  SSSS   |%N");
 io.put_string("*---------------------------------------"+
 "-------------------------------------*%N");
 from
   ncont:=1 
 until
   ncont > 18 
 loop
   io.put_new_line;
   ncont:=ncont + 1;
 end 
 io.put_string(msg_press);
 io.read_character;
 io.put_new_line;
end;
-- ----------------------------------------------------------------------------
-- Mostra a tela de sobre do sistema.
-- ----------------------------------------------------------------------------
frmsobre is
local
  ncont: INTEGER;
  stemp: STRING;
do
 io.put_string("*------------------------------------------------------------*%N");
 io.put_string("|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |%N");
 io.put_string("|  LL        II   VV     VV   RR     R  UU    UU  SS         |%N");
 io.put_string("|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |%N");
 io.put_string("|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |%N");
 io.put_string("|  LLLL      II      VVV      RR RR     UU    UU        SS   |%N");
 io.put_string("|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |%N");
 io.put_string("|                                                            |%N");
 io.put_string("|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |%N");
 io.put_string("|   VV     VV   II  RR     R     TT     UU    UU  SS         |%N");
 io.put_string("|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |%N");
 io.put_string("|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |%N");
 io.put_string("|      VVV      II  RR RR        TT     UU    UU        SS   |%N");
 io.put_string("|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |%N");
 io.put_string("|                                                            |%N");
 io.put_string("|                                               Versao 1.0.0 |%N");
 io.put_string("| Sistema integrante do projeto Livrus Virtus.               |%N");
 io.put_string("| Todos os direitos reservados para Henrique F. de Souza.    |%N");
 io.put_string("| Versao programada na linguagem Eiffel.                     |%N");
 io.put_string("*------------------------------------------------------------*%N");
 from
   ncont:=1 
 until
   ncont > 4 
 loop
   io.put_new_line;
   ncont:=ncont + 1;
 end 
 io.put_string(msg_press);
 stemp:=digita;
 io.put_new_line;
end;
-- ----------------------------------------------------------------------------
-- Mostra a tela de login do sistema.
-- retorna - se o login foi validado corretamente
-- ----------------------------------------------------------------------------
frmlogin: BOOLEAN is
local
  bret: BOOLEAN;
  slinha: STRING;
do
  bret:=false;
  io.put_string("*----------------------------------------------------"+
  "----------*%N");
  io.put_string("| Login do sistema                                   "+
  "          |%N");
  io.put_string("*----------------------------------------------------"+
  "----------*%N");
  slinha:=validaentrada(tfusuario, opusuario, 1, tusuario.login, 3,
        false, optexto);
  if slinha.is_empty=false then
     slinha:=validaentrada(tfusuario, opusuario, 2, tusuario.senha, 3,
        false, opsenha);
     if slinha.is_empty=false then
        tusuario.set_login(trim(substr(slinha, 1, 10)));
        tusuario.set_senha(trim(substr(slinha, 11, 10)));
        bret:=true;
     end;
  end;
  io.put_new_line;
  result:=bret;
end;
-- ----------------------------------------------------------------------------
-- Mostra os menus do sistema.
-- num - o número do menu
-- ----------------------------------------------------------------------------
menu(num: INTEGER) is
do
 if (num=1) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=2) then
   io.put_string("*---------------------------------*%N");
   io.put_string("| 01. Cadastro de Assuntos        |%N");
   io.put_string("| 02. Cadastro de Autores         |%N");
   io.put_string("| 03. Cadastro de Editoras        |%N");
   io.put_string("| 04. Cadastro de Endereços       |%N");
   io.put_string("| 05. Cadastro de Idiomas         |%N");
   io.put_string("| 06. Cadastro de Países          |%N");
   io.put_string("| 07. Cadastro de Profissões      |%N");
   io.put_string("| 08. Cadastro de Clientes        |%N");
   io.put_string("| 09. Cadastro de Livros          |%N");
   io.put_string("| 10. Voltar ao menu              |%N");
   io.put_string("*---------------------------------*%N");
 elseif (num=3) then
   io.put_string("*---------------------------------*%N");
   io.put_string("| 01. Consulta de Assuntos        |%N");
   io.put_string("| 02. Consulta de Autores         |%N");
   io.put_string("| 03. Consulta de Editoras        |%N");
   io.put_string("| 04. Consulta de Endereços       |%N");
   io.put_string("| 05. Consulta de Idiomas         |%N");
   io.put_string("| 06. Consulta de Países          |%N");
   io.put_string("| 07. Consulta de Profissões      |%N");
   io.put_string("| 08. Consulta de Clientes        |%N");
   io.put_string("| 09. Consulta de Livros          |%N");
   io.put_string("| 10. Voltar ao menu              |%N");
   io.put_string("*---------------------------------*%N");
 elseif (num=4) then
   io.put_string("*---------------------------------*%N");
   io.put_string("| 01. Vender Livros               |%N");
   io.put_string("| 02. Vendas Realizadas           |%N");
   io.put_string("| 03. Voltar ao menu              |%N");
   io.put_string("*---------------------------------*%N");
 elseif (num=5) then
   io.put_string("*---------------------------------*%N");
   io.put_string("| 01. Alterar senha               |%N");
   io.put_string("| 02. Sobre o sistema             |%N");
   io.put_string("| 03. Sair do sistema             |%N");
   io.put_string("| 04. Voltar ao menu              |%N");
   io.put_string("*---------------------------------*%N");
 elseif (num=6) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=7) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| (1) Salvar inclusão       (2) Voltar ao menu                 |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=8) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=9) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| (1) Salvar alteração      (2) Voltar ao menu                 |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=10) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| Certeza de excluir? (S/N)                                    |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=11) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| Deseja sair do sistema? (S/N)                                |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=12) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=13) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| Deseja continuar? (S/N)                                      |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 elseif (num=14) then
   io.put_string("*--------------------------------------------------------------*%N");
   io.put_string("| Salvar inclusão (S/N)                                        |%N");
   io.put_string("*--------------------------------------------------------------*%N");
 end;
 io.put_string(msg_opcao);
end;
-- ----------------------------------------------------------------------------
-- Realiza os cadastros de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
frmcadastros(sreg, sacao: INTEGER) is
local
  slinha: STRING;
do
if ctarqs.item(opassunto)=sreg then
   if ctacao.item(opnovo) = sacao then
      tassunto.set_codigo(pesqmaxcod(tfassunto, 1, 10, tamreg(sreg)));
      mostrardados(sreg, "", 1);
      submenu(7, sreg);
   elseif ctacao.item(oppesquisar) = sacao then
     slinha:=validaentrada(tfassunto,sreg,1,tassunto.codigo,1,false,opnumero);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(opautor) = sreg then
   if ctacao.item(opnovo) = sacao then
      tautor.set_codigo(pesqmaxcod(tfautor, 1, 10, tamreg(sreg)));
      mostrardados(sreg, "", 1);
      submenu(7, sreg);
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfautor, sreg, 1, tautor.codigo,1,false,opnumero);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(opeditora) = sreg then
   if ctacao.item(opnovo) = sacao then
      teditora.set_codigo(pesqmaxcod(tfeditora, 1, 10, tamreg(sreg)));
      mostrardados(sreg, "", 1);
      submenu(7, sreg);
   elseif ctacao.item(oppesquisar) = sacao then
     slinha:=validaentrada(tfeditora,sreg,1,teditora.codigo,1,false,opnumero);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(opendereco) = sreg then
   if ctacao.item(opnovo) = sacao then
      tendereco.set_codigo(pesqmaxcod(tfendereco, 1, 10, tamreg(sreg)));
      mostrardados(sreg, "", 1);
      submenu(7, sreg);
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfendereco,sreg,1,tendereco.codigo,1,
              false,opnumero);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(opidioma) = sreg then
   if ctacao.item(opnovo) = sacao then
      tidioma.set_codigo(pesqmaxcod(tfidioma, 1, 10, tamreg(sreg)));
      mostrardados(sreg, "", 1);
      submenu(7, sreg);
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfidioma,sreg,1,tidioma.codigo,1,false,opnumero);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(oppais) = sreg then
   if ctacao.item(opnovo) = sacao then
      io.put_string(rotulo(sreg, 1));
      tpais.set_codigo(digita);
      slinha:=pesqarq(tfpais, tpais.codigo, 1, 3, tamreg(sreg));
      if slinha.is_empty then
         pesqlinhaexcluida(tfpais, tamreg(sreg));
         mostrardados(sreg, "", 1);
         submenu(7, sreg);
      else 
        io.put_string(msg_regexst);
      end;
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfpais, sreg, 1, tpais.codigo, 1, false, optexto);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      io.put_string(rotulo(sreg, 1) + tpais.codigo + crlf);
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(opprofissao) = sreg then
   if ctacao.item(opnovo) = sacao then
      tprofissao.set_codigo(pesqmaxcod(tfprofissao, 1, 10, tamreg(sreg)));
      mostrardados(sreg, "", 1);
      submenu(7, sreg);
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfprofissao,sreg,1,tprofissao.codigo,1,
              false,opnumero);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(oplivro) = sreg then
   if ctacao.item(opnovo) = sacao then
      io.put_string(rotulo(sreg, 1));
      tlivro.set_isbn(digita);
      if validaisbn(tlivro.isbn) then
          slinha:=pesqarq(tflivro, tlivro.isbn, 1, 13, tamreg(sreg));
          if slinha.is_empty then
             pesqlinhaexcluida(tflivro, tamreg(sreg));
             mostrardados(sreg, "", 1);
             submenu(7, sreg);
             frmcadligados(oplivroass, opnovo, tlivro.isbn);
             frmcadligados(oplivroaut, opnovo, tlivro.isbn);
          else 
             io.put_string(msg_regexst);
          end;
      else 
        io.put_string(msg_isbninv);
      end; 
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tflivro, sreg, 1, tlivro.isbn, 1,false,optexto);
      if slinha.is_empty=false then
         mostrardados(sreg, "", 2);
         mostrardados(sreg, slinha, 3);
         submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      io.put_string(rotulo(sreg, 1) + tlivro.isbn + crlf);
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
      frmcadligados(oplivroass, opexcluir, tlivro.isbn);
      io.put_string("assuntos dos livros excluídos, inclua novos!%N");
      frmcadligados(oplivroass, opnovo, tlivro.isbn);
      frmcadligados(oplivroaut, opexcluir, tlivro.isbn);
      io.put_string("autores dos livros excluídos, inclua novos!%N");
      frmcadligados(oplivroaut, opnovo, tlivro.isbn);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
      io.put_string("assuntos dos livros sendo excluídos!%N");
      frmcadligados(oplivroass, opexcluir, tlivro.isbn);
      io.put_string("autores dos livros sendo excluídos!%N");
      frmcadligados(oplivroaut, opexcluir, tlivro.isbn);
   end;
elseif ctarqs.item(opcliente) = sreg then
   if ctacao.item(opnovo) = sacao then
      io.put_string(rotulo(sreg, 1));
      tcliente.set_cpf(digita);
      if validacpf(tcliente.cpf) then
          slinha:=pesqarq(tfcliente, tcliente.cpf, 1, 14, tamreg(sreg));
          if slinha.is_empty then
             pesqlinhaexcluida(tfcliente, tamreg(sreg));
             mostrardados(sreg, "", 1);
             submenu(7, sreg);
          else 
            io.put_string(msg_regexst);
          end;
      else 
        io.put_string(msg_cpfinv);
      end;
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfcliente, sreg, 1, tcliente.cpf,1,false,optexto);
      if slinha.is_empty=false then
         mostrardados(sreg, "", 2);
         mostrardados(sreg, slinha, 3);
         submenu(8, sreg);
      end;
   elseif ctacao.item(opalterar) = sacao then
      io.put_string(rotulo(sreg, 1) + tcliente.cpf + crlf);
      mostrardados(sreg, "", 1);
      submenu(9, sreg);
   elseif ctacao.item(opexcluir) = sacao then
      submenu(10, sreg);
   end;
elseif ctarqs.item(opvenda) = sreg then
   if ctacao.item(opnovo) = sacao then
      tvenda.set_dthrvenda(retdatahora);
      io.put_string(rotulo(sreg, 1) + tvenda.dthrvenda + crlf);
      slinha:=pesqarq(tfvenda, tvenda.dthrvenda, 1, 19, tamreg(sreg));
      if slinha.is_empty then
         slinha:=validaentrada(tfcliente,opcliente,1,tvenda.cpf,3,
                 false,optexto);
         if slinha.is_empty=false then
            tvenda.set_cpf(trim(substr(slinha,1,14)));
            if validacpf(tvenda.cpf) then
               io.put_string(" " + rotulo(opcliente, 2)); -- nome
               io.put_string(substr(slinha, g_nposchave, g_ntamchave) + crlf);
               frmcadligados(opvenda, opnovo, tvenda.cpf);
            else 
               io.put_string(msg_cpfinv);
            end;
         end;
      else 
        io.put_string(msg_regexst);
      end;
   elseif ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfvenda, sreg, 1, tvenda.dthrvenda,1,
              false,opdatahora);
      if slinha.is_empty=false then
        mostrardados(sreg, "", 2);
        mostrardados(sreg, slinha, 3);
        submenu(8, sreg);
      end;
   end;
end;

end;
-- ----------------------------------------------------------------------------
-- realiza as consultas de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
frmconsultas(sreg, sacao: INTEGER) is
local
  slinha: STRING;
do
slinha:="";
if ctarqs.item(opassunto) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfassunto,sreg,2,tassunto.assunto,1,true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfassunto, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opautor) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfautor,sreg, 2, tautor.autor, 1, true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfautor, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opeditora) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfeditora,sreg,2,teditora.editora,1,true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfeditora, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opendereco) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfendereco,sreg,2,tendereco.logradouro,1,
              true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfendereco, sreg, "", 0, 0, tamreg(sreg),
         3, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opidioma) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfidioma, sreg, 2, tidioma.idioma,1,true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfidioma, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(oppais) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfpais, sreg, 2, tpais.pais, 1, true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfpais, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opprofissao) = sreg then
   if ctacao.item(oppesquisar) = sacao then
     slinha:=validaentrada(tfprofissao,sreg,2,tprofissao.profissao,1,
             true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfprofissao, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(oplivro) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tflivro, sreg, 2, tlivro.titulo, 1, true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tflivro, sreg, "", 0, 0, tamreg(sreg),
        1, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opcliente) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfcliente, sreg, 2, tcliente.nome,1,true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfcliente, sreg, "", 0, 0, tamreg(sreg),
        1, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
elseif ctarqs.item(opvenda) = sreg then
   if ctacao.item(oppesquisar) = sacao then
      slinha:=validaentrada(tfvenda, sreg, 2, tvenda.cpf, 1, true,optexto)
   elseif ctacao.item(oplistartodos) = sacao then
      if listartodos(tfvenda, sreg, "", 0, 0, tamreg(sreg),
        qtd_max_linha, false) = false then
        io.put_string(rotulo(sreg, 0));
      end;
   end;
end;
if slinha.is_empty then
   io.put_string("");
end;
end;
-- ----------------------------------------------------------------------------
-- mostra a tela de alteração de senha do sistema e realiza a alteração.
-- ----------------------------------------------------------------------------
frmalterarsenha is
local
  bquebra: BOOLEAN;
  sres, ssenhaatual, snovasenha, sconfirmasenha: STRING;
  nopcao: INTEGER;
do
io.put_string(rotulo(opusuario, 1) + tusuario.login + crlf);
from
  nopcao:=1;
  bquebra:=false;
until
  bquebra=true
loop
  inspect nopcao
    when 1 then
       ssenhaatual:=digitasenha("Senha Atual: ",10);
       if ssenhaatual.is_equal(tusuario.senha)=false then
          io.put_string(msg_senconfere);
          bquebra:=true;
       else 
          nopcao:=2;
       end;
    when 2 then
       snovasenha:=digitasenha("Nova Senha: ",10);
       sconfirmasenha:=digitasenha("Confirma Senha: ",10);
       if snovasenha.is_equal(sconfirmasenha)=false then
          io.put_string(msg_senconfirm);
          bquebra:=true;
       else 
          nopcao:=3;
       end;
    when 3 then
       sres:=pesqarq(tfusuario, tusuario.login, 1, 10, tamreg(opusuario));
       if sres.is_empty then
         io.put_string(msg_loginencon)
       else
         tusuario.set_senha(sconfirmasenha);
         submenu(9,opusuario);
         bquebra:=true;
       end;
  end;
end;

end;
-- ----------------------------------------------------------------------------
-- Executa uma ação de gravação de acordo com o tipo de arquivo.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- ----------------------------------------------------------------------------
btnacao(sreg, sacao: INTEGER) is
do
if ctarqs.item(opassunto) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfassunto, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfassunto, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfassunto, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opautor) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfautor, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfautor, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfautor, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opeditora) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfeditora, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfeditora, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfeditora, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opendereco) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfendereco, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfendereco, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfendereco, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opidioma) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfidioma, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfidioma, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfidioma, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(oppais) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfpais, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfpais, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfpais, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opprofissao) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfprofissao, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfprofissao, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfprofissao, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(oplivro) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tflivro, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tflivro, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tflivro, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(oplivroass) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tflivroass, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tflivroass, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tflivroass, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(oplivroaut) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tflivroaut, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tflivroaut, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tflivroaut, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opcliente) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfcliente, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfcliente, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfcliente, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opvenda) = sreg then
  if ctacao.item(opsalvarinclusao) = sacao then
    escrevearq(tfvenda, linhareg(sreg), msg_reginc, msg_regninc)
  elseif ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfvenda, linhareg(sreg), msg_regalt, msg_regnalt)
  elseif ctacao.item(opconfirmaexclusao) = sacao then
    escrevearq(tfvenda, repete('*',tamreg(sreg)), msg_regexc, msg_regnexc);
  end;
elseif ctarqs.item(opusuario) = sreg then
  if ctacao.item(opsalvaralteracao) = sacao then
    escrevearq(tfusuario, linhareg(sreg), msg_regalt, msg_regnalt);
  end;
end;
end;
-- ----------------------------------------------------------------------------
-- Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
-- nmenu - o número do menu
-- sreg - o tipo de arquivo
-- ----------------------------------------------------------------------------
submenu(nmenu, sreg: INTEGER) is
local
  opsubmenu: INTEGER;
  opcsubmenu: STRING;
  bsop: BOOLEAN;
do
inspect nmenu
  when 6 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      io.read_integer
      opsubmenu:=io.last_integer;
      inspect opsubmenu
        when 1 then frmcadastros(sreg, opnovo);
        when 2 then frmcadastros(sreg, oppesquisar);
        when 3 then bsop:=false;
        else io.put_string(msg_erro);
      end;
    end;
  when 7 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      io.read_integer
      opsubmenu:=io.last_integer;
      inspect opsubmenu
        when 1 then 
          btnacao(sreg, opsalvarinclusao); 
          bsop:=false;
        when 2 then bsop:=false;
        else io.put_string(msg_erro);
      end;
    end;
  when 8 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      io.read_integer
      opsubmenu:=io.last_integer;
      inspect opsubmenu
        when 1 then 
          frmcadastros(sreg, opalterar); 
          bsop:=false;
        when 2 then 
          frmcadastros(sreg, opexcluir); 
          bsop:=false;
        when 3 then bsop:=false;
        else io.put_string(msg_erro);
      end;
    end;
  when 9 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      io.read_integer
      opsubmenu:=io.last_integer;
      inspect opsubmenu
        when 1 then 
          btnacao(sreg, opsalvaralteracao); 
          bsop:=false;
        when 2 then bsop:=false;
        else io.put_string(msg_erro);
      end;
    end;
  when 10 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      opcsubmenu:=digita;
      if (opcsubmenu.item(1)='s') or (opcsubmenu.item(1)='s') then
        btnacao(sreg, opconfirmaexclusao);
        bsop:=false;
      elseif (opcsubmenu.item(1)='n') or (opcsubmenu.item(1)='n') then 
        bsop:=false
      else io.put_string(msg_erro);
      end;
    end;
  when 12 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      io.read_integer
      opsubmenu:=io.last_integer;
      inspect opsubmenu
        when 1 then frmconsultas(sreg, oppesquisar);
        when 2 then frmconsultas(sreg, oplistartodos);
        when 3 then bsop:=false;
        else io.put_string(msg_erro);
      end;
    end;
  when 14 then
    from bsop:=true; 
    until bsop=false 
    loop
      menu(nmenu);
      opcsubmenu:=digita;
      if (opcsubmenu.item(1)='s') or (opcsubmenu.item(1)='s') then
        btnacao(sreg, opsalvarinclusao);
        bsop:=false;
        g_salvarinclusao:=true;
      elseif (opcsubmenu.item(1)='n') or (opcsubmenu.item(1)='n') then 
        bsop:=false
      else io.put_string(msg_erro);
      end;
    end;
end;

end;
-- ----------------------------------------------------------------------------
-- Seleciona o submenu e/ou a tela certa de acordo com número do menu.
-- nmenu - o número do menu
-- ----------------------------------------------------------------------------
usamenu(num: INTEGER) is
local
  opsubmenu: INTEGER;
  bsop: BOOLEAN;
  opsair: STRING;
do
 if num = 1 then -- cadastros
   from bsop:=true; 
   until bsop=false 
   loop
     menu(2);
     io.read_integer
     opsubmenu:=io.last_integer;
     inspect opsubmenu
       when 1 then submenu(6, opassunto);
       when 2 then submenu(6, opautor);
       when 3 then submenu(6, opeditora);
       when 4 then submenu(6, opendereco);
       when 5 then submenu(6, opidioma);
       when 6 then submenu(6, oppais);
       when 7 then submenu(6, opprofissao);
       when 8 then submenu(6, opcliente);
       when 9 then submenu(6, oplivro);
       when 10 then bsop:=false;
       else io.put_string(msg_erro);
     end;
   end;
 elseif num = 2 then -- pesquisas
   from bsop:=true; 
   until bsop=false 
   loop
     menu(3);
     io.read_integer
     opsubmenu:=io.last_integer;
     inspect opsubmenu
       when 1 then submenu(12, opassunto);
       when 2 then submenu(12, opautor);
       when 3 then submenu(12, opeditora);
       when 4 then submenu(12, opendereco);
       when 5 then submenu(12, opidioma);
       when 6 then submenu(12, oppais);
       when 7 then submenu(12, opprofissao);
       when 8 then submenu(12, opcliente);
       when 9 then submenu(12, oplivro);
       when 10 then bsop:=false;
       else io.put_string(msg_erro);
     end;
   end;
 elseif num = 3 then -- vendas
   from bsop:=true; 
   until bsop=false 
   loop
     menu(4);
     io.read_integer
     opsubmenu:=io.last_integer;
     inspect opsubmenu
       when 1 then submenu(6, opvenda);
       when 2 then submenu(12, opvenda);
       when 3 then bsop:=false;
       else io.put_string(msg_erro);
     end;
   end;
 elseif num = 4 then -- opcoes
   from bsop:=true; 
   until bsop=false 
   loop
     menu(5);
     io.read_integer
     opsubmenu:=io.last_integer;
     inspect opsubmenu
       when 1 then frmalterarsenha;
       when 2 then frmsobre;
       when 3 then
         menu(11);
         opsair:=digita;
         if (opsair.item(1)='s') or (opsair.item(1)='s') then
            fechaarqs;
            die_with_code(exit_success_code);
         end;
       when 4 then bsop:=false;
       else io.put_string(msg_erro);
     end;
   end;
 end;
end;
-- ----------------------------------------------------------------------------
-- Mostra as entradas e as saídas do sistema.
-- sreg - o tipo de arquivo
-- slinha - o registro com os dados
-- nOpcao - indica qual opção será mostrada
-- ----------------------------------------------------------------------------
mostrardados(sreg: INTEGER; slinha: STRING; nopcao: INTEGER) is
do
if ctarqs.item(opassunto) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 1) + tassunto.codigo + crlf);
      io.put_string(rotulo(sreg, 2));
      tassunto.set_assunto(digita);
    when 2 then
      io.put_string("Código     Assunto%N");
      io.put_string("------     -------%N");
    when 3 then
      tassunto.set_codigo(substr(slinha, 1, 10));
      tassunto.set_assunto(substr(slinha, 11, 30));
      io.put_string(tassunto.codigo+" "+tassunto.assunto+crlf);
  end;
elseif ctarqs.item(opautor) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 1) + tautor.codigo + crlf);
      io.put_string(rotulo(sreg, 2));
      tautor.set_autor(digita);
    when 2 then
      io.put_string("Código     Autor%N");
      io.put_string("------     -----%N");
    when 3 then
      tautor.set_codigo(substr(slinha, 1, 10));
      tautor.set_autor(substr(slinha, 11, 30));
      io.put_string(tautor.codigo+" "+tautor.autor+crlf);
  end;
elseif ctarqs.item(opeditora) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 1) + teditora.codigo + crlf);
      io.put_string(rotulo(sreg, 2));
      teditora.set_editora(digita);
    when 2 then
      io.put_string("Código     Editora%N");
      io.put_string("------     -------%N");
    when 3 then
      teditora.set_codigo(substr(slinha, 1, 10));
      teditora.set_editora(substr(slinha, 11, 50));
      io.put_string(teditora.codigo + " " + teditora.editora + crlf);
  end;
elseif ctarqs.item(opendereco) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 1) + tendereco.codigo + crlf);
      io.put_string(rotulo(sreg, 2));
      tendereco.set_logradouro(digita);
      io.put_string(rotulo(sreg, 3));
      tendereco.set_bairro(digita);
      io.put_string(rotulo(sreg, 4));
      tendereco.set_cep(digita);
      io.put_string(rotulo(sreg, 5));
      tendereco.set_cidade(digita);
      io.put_string(rotulo(sreg, 6));
      tendereco.set_estado(digita);
    when 2 then 
      io.put_string("");
    when 3 then
      tendereco.set_codigo(trim(substr(slinha, 1, 10)));
      tendereco.set_logradouro(trim(substr(slinha, 11, 40)));
      tendereco.set_bairro(trim(substr(slinha, 51, 15)));
      tendereco.set_cep(trim(substr(slinha, 66, 8)));
      tendereco.set_cidade(trim(substr(slinha, 74, 30)));
      tendereco.set_estado(trim(substr(slinha, 104, 20)));
      io.put_string("--------------------%N");
      io.put_string(rotulo(sreg, 1) + tendereco.codigo + crlf);
      io.put_string(rotulo(sreg, 2) + tendereco.logradouro + crlf);
      io.put_string(rotulo(sreg, 3) + tendereco.bairro + crlf);
      io.put_string(rotulo(sreg, 4) + tendereco.cep + crlf);
      io.put_string(rotulo(sreg, 5) + tendereco.cidade + crlf);
      io.put_string(rotulo(sreg, 6) + tendereco.estado + crlf);
  end;
elseif ctarqs.item(opidioma) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 1) + tidioma.codigo + crlf);
      io.put_string(rotulo(sreg, 2));
      tidioma.set_idioma(digita);
    when 2 then
      io.put_string("Código     Idioma%N");
      io.put_string("------     ------%N");
    when 3 then
      tidioma.set_codigo(substr(slinha, 1, 10));
      tidioma.set_idioma(substr(slinha, 11, 20));
      io.put_string(tidioma.codigo+" "+tidioma.idioma+crlf);
  end;
elseif ctarqs.item(oppais) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 2));
      tpais.set_pais(digita);
    when 2 then
      io.put_string("Código País%N");
      io.put_string("------ ----%N");
    when 3 then
      tpais.set_codigo(substr(slinha, 1, 3));
      tpais.set_pais(substr(slinha, 4, 50));
      io.put_string(tpais.codigo+"    "+tpais.pais+crlf);
  end;
elseif ctarqs.item(opprofissao) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 1) + tprofissao.codigo+crlf);
      io.put_string(rotulo(sreg, 2));
      tprofissao.set_profissao(digita);
    when 2 then
      io.put_string("Código     Profissão%N");
      io.put_string("------     ---------%N");
    when 3 then
      tprofissao.set_codigo(substr(slinha, 1, 10));
      tprofissao.set_profissao(substr(slinha, 11, 50));
      io.put_string(tprofissao.codigo+" "+tprofissao.profissao+crlf);
  end;
elseif ctarqs.item(oplivro) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 2));
      tlivro.set_titulo(digita);
      tlivro.set_edicao(validanumero(rotulo(sreg, 3), tlivro.edicao));
      tlivro.set_anopubli(validanumero(rotulo(sreg, 4), tlivro.anopubli));
      mostrarsubdados(oplivro, opeditora, false);
      tlivro.set_volume(validanumero(rotulo(sreg, 6), tlivro.volume));
      mostrarsubdados(oplivro, opidioma, false);
      tlivro.set_npaginas(validanumero(rotulo(sreg, 8), tlivro.npaginas));
      tlivro.set_preco(validanumero(rotulo(sreg, 9), tlivro.preco));
      tlivro.set_qtdestoque(validanumero(rotulo(sreg, 10), tlivro.qtdestoque));
    when 2 then 
      io.put_string("");
    when 3 then
      tlivro.set_isbn(trim(substr(slinha, 1, 13)));
      tlivro.set_titulo(trim(substr(slinha, 14, 50)));
      tlivro.set_edicao(trim(substr(slinha, 64, 10)));
      tlivro.set_anopubli(trim(substr(slinha, 74, 10)));
      tlivro.set_codeditora(trim(substr(slinha, 84, 10)));
      tlivro.set_volume(trim(substr(slinha, 94, 10)));
      tlivro.set_codidioma(trim(substr(slinha, 104, 10)));
      tlivro.set_npaginas(trim(substr(slinha, 114, 10)));
      tlivro.set_preco(trim(substr(slinha, 124, 10)));
      tlivro.set_qtdestoque(trim(substr(slinha, 134, 10)));
      io.put_string("--------------------%N");
      io.put_string(rotulo(sreg, 1) + tlivro.isbn + crlf);
      io.put_string(rotulo(sreg, 2) + tlivro.titulo + crlf);
      io.put_string(rotulo(sreg, 3) + tlivro.edicao + crlf);
      io.put_string(rotulo(sreg, 4) + tlivro.anopubli + crlf);
      io.put_string(rotulo(sreg, 5) + tlivro.codeditora + crlf);
      mostrarsubdados(oplivro, opeditora, true);
      io.put_string(rotulo(sreg, 6) + tlivro.volume + crlf);
      io.put_string(rotulo(sreg, 7) + tlivro.codidioma + crlf);
      mostrarsubdados(oplivro, opidioma, true);
      io.put_string(rotulo(sreg, 8) + tlivro.npaginas + crlf);
      io.put_string(rotulo(sreg, 9) + tlivro.preco + crlf);
      io.put_string(rotulo(sreg, 10) + tlivro.qtdestoque + crlf);
      listarregligados(tflivroass, oplivroass, 1, 13, 14, 10, tlivro.isbn,
                       tfassunto, opassunto, 1, 4);
      listarregligados(tflivroaut, oplivroaut, 1, 13, 14, 10, tlivro.isbn,
                       tfautor, opautor, 1, 4);
   end;
elseif ctarqs.item(opcliente) = sreg then
  inspect nopcao
    when 1 then
      io.put_string(rotulo(sreg, 2));
      tcliente.set_nome(digita);
      io.put_string(rotulo(sreg, 3));
      tcliente.set_email(digita);
      io.put_string(rotulo(sreg, 4));
      tcliente.set_identidade(digita);
      io.put_string(rotulo(sreg, 5));
      tcliente.set_sexo(digita);
      io.put_string(rotulo(sreg, 6));
      tcliente.set_telefone(digita);
      tcliente.set_dtnascimento(
              validadatahora(rotulo(sreg, 7), tcliente.dtnascimento, true));
      mostrarsubdados(opcliente, opendereco, false);
      mostrarsubdados(opcliente, oppais, false);
      mostrarsubdados(opcliente, opprofissao, false);
    when 2 then 
      io.put_string("");
    when 3 then
      tcliente.set_cpf(trim(substr(slinha, 1, 14)));
      tcliente.set_nome(trim(substr(slinha, 15, 30)));
      tcliente.set_email(trim(substr(slinha, 45, 30)));
      tcliente.set_identidade(trim(substr(slinha, 75, 10)));
      tcliente.set_sexo(trim(substr(slinha, 85, 1)));
      tcliente.set_telefone(trim(substr(slinha, 86, 17)));
      tcliente.set_dtnascimento(trim(substr(slinha, 103, 10)));
      tcliente.set_codendereco(trim(substr(slinha, 113, 10)));
      tcliente.set_codpais(trim(substr(slinha, 123, 3)));
      tcliente.set_codprofissao(trim(substr(slinha, 126, 10)));
      io.put_string("--------------------%N");
      io.put_string(rotulo(sreg, 1) + tcliente.cpf + crlf);
      io.put_string(rotulo(sreg, 2) + tcliente.nome + crlf);
      io.put_string(rotulo(sreg, 3) + tcliente.email + crlf);
      io.put_string(rotulo(sreg, 4) + tcliente.identidade + crlf);
      io.put_string(rotulo(sreg, 5) + tcliente.sexo + crlf);
      io.put_string(rotulo(sreg, 6) + tcliente.telefone + crlf);
      io.put_string(rotulo(sreg, 7) + tcliente.dtnascimento + crlf);
      io.put_string(rotulo(sreg, 8) + tcliente.codendereco + crlf);
      mostrarsubdados(opcliente, opendereco, true);
      io.put_string(rotulo(sreg, 9) + tcliente.codpais + crlf);
      mostrarsubdados(opcliente, oppais, true);
      io.put_string(rotulo(sreg, 10) + tcliente.codprofissao + crlf);
      mostrarsubdados(opcliente, opprofissao, true);
   end;
elseif ctarqs.item(opvenda) = sreg then
  inspect nopcao
    when 1 then 
      mostrarsubdados(opvenda,opvenda, false);
    when 2 then
      io.put_string("DataHoraVenda       CPF            ISBN          "+
      "PreçoVenda%N");
      io.put_string("-------------       ---            ----          "+
      "----------%N");
    when 3 then
      tvenda.set_dthrvenda(substr(slinha, 1, 19));
      tvenda.set_cpf(substr(slinha, 20, 14));
      tvenda.set_isbn(substr(slinha, 34, 13));
      tvenda.set_precovenda(substr(slinha, 47, 10));
      io.put_string(tvenda.dthrvenda+" "+tvenda.cpf+" "+tvenda.isbn+" "+
      tvenda.precovenda + crlf);
  end;
end;

end;
-- ----------------------------------------------------------------------------
-- Mostra as sub informções de entrada e de saída.
-- sreg - o tipo de arquivo
-- ssubreg - o subtipo de arquivo
-- bSoMostrar - se vai só mostrar na saída 
-- ----------------------------------------------------------------------------
mostrarsubdados(sreg, ssubreg: INTEGER; bsomostrar: BOOLEAN) is
local 
  sregistro, spreco: STRING;
  nmaxtentativas: INTEGER;
do
nmaxtentativas:=3;
if ctarqs.item(oplivro) = sreg then
  if ctarqs.item(opeditora) = ssubreg then
    if bsomostrar then
       sregistro:=pesqarq(tfeditora,tlivro.codeditora,1,10,tamreg(opeditora))
    else
       sregistro:=validaentrada(tfeditora,ssubreg,1,tlivro.codeditora,
                  nmaxtentativas,false,opnumero);
    end;
    if sregistro.is_empty=false then
      tlivro.set_codeditora(trim(substr(sregistro,1,10)));
      io.put_string(" " + rotulo(opeditora, 2));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
    end;
  elseif ctarqs.item(opidioma) = ssubreg then
    if bsomostrar then
       sregistro:=pesqarq(tfidioma, tlivro.codidioma, 1, 10,tamreg(opidioma))
    else
       sregistro:=validaentrada(tfidioma,ssubreg,1,tlivro.codidioma,
                  nmaxtentativas,false,opnumero);
    end;
    if sregistro.is_empty=false then
      tlivro.set_codidioma(trim(substr(sregistro,1,10)));
      io.put_string(" " + rotulo(opidioma, 2));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
    end;
  end;
elseif ctarqs.item(opcliente) = sreg then
  if ctarqs.item(opendereco) = ssubreg then
    if bsomostrar then
       sregistro:=pesqarq(tfendereco, tcliente.codendereco, 1, 10,
                  tamreg(opendereco))
    else
       sregistro:=validaentrada(tfendereco,ssubreg,1,tcliente.codendereco,
                  nmaxtentativas,false,opnumero);
    end;
    if sregistro.is_empty=false then
      tcliente.set_codendereco(trim(substr(sregistro,1,10)));
      io.put_string(" " + rotulo(opendereco, 2));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
      io.put_string(" " + rotulo(opendereco, 3));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
      io.put_string(" " + rotulo(opendereco, 4));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
      io.put_string(" " + rotulo(opendereco, 5));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
      io.put_string(" " + rotulo(opendereco, 6));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
    end;
  elseif ctarqs.item(oppais) = ssubreg then
    if bsomostrar then
       sregistro:=pesqarq(tfpais, tcliente.codpais, 1, 3, tamreg(oppais))
    else
       sregistro:=validaentrada(tfpais,ssubreg,1,tcliente.codpais,
                  nmaxtentativas,false,optexto);
    end;
    if sregistro.is_empty=false then
      tcliente.set_codpais(trim(substr(sregistro,1,3)));
      io.put_string(" " + rotulo(oppais, 2));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
    end;
  elseif ctarqs.item(opprofissao) = ssubreg then
    if bsomostrar then
       sregistro:=pesqarq(tfprofissao, tcliente.codprofissao, 1, 10,
                  tamreg(opprofissao))
    else
       sregistro:=validaentrada(tfprofissao,ssubreg,1,tcliente.codprofissao,
                  nmaxtentativas,false,opnumero);
    end;
    if sregistro.is_empty=false then
      tcliente.set_codprofissao(trim(substr(sregistro,1,10)));
      io.put_string(" " + rotulo(opprofissao, 2));
      io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
    end;
  end;
elseif ctarqs.item(opvenda) = sreg then
  sregistro:=pesqarq(tflivro, tvenda.isbn, 1, 13, tamreg(oplivro));
  if sregistro.is_empty=false then
    io.put_string(" " + rotulo(oplivro, 2)); -- titulo
    io.put_string(substr(sregistro, g_nposchave, g_ntamchave)+crlf);
    io.put_string(" " + rotulo(oplivro, 9)); -- preco 
    spreco:=substr(sregistro, g_nposchave, g_ntamchave);
    g_npreco:=spreco.to_double;
    io.put_string(spreco + crlf);
  end;
end;
end;
-- ----------------------------------------------------------------------------
-- realiza os cadastros dos arquivos que se ligam a outros arquivos.
-- sreg - o tipo de arquivo
-- sacao - a ação a ser realizada
-- scodigo - um das chaves do arquivo de ligação
-- ----------------------------------------------------------------------------
frmcadligados(sreg, sacao: INTEGER; scodigo: STRING) is
local
  nqtd, ncont, nqtdestoque: INTEGER;
  ntotalpreco: DOUBLE;
  slinha, stotalpreco, spreco, sqtd: STRING;
do
if ctacao.item(opnovo) = sacao then
  if ctarqs.item(oplivroass) = sreg then
    sqtd:=validanumero("Quantos assuntos quer cadastrar?: ", sqtd);
    nqtd:=sqtd.to_integer;
    from  ncont:=1; 
    until ncont > nqtd
    loop
      tlivroass.set_isbn(scodigo);
      io.put_string(rotulo(oplivroass, 2));
      tlivroass.set_codassunto(digita);
      slinha:=pesqarq(tfassunto, tlivroass.codassunto,1,10,tamreg(opassunto));
      io.put_string(" " + rotulo(opassunto, 2));
      io.put_string(substr(slinha, g_nposchave, g_ntamchave)+crlf);
      pesqlinhaexcluida(tflivroass, tamreg(sreg));
      submenu(14, sreg);
      ncont:=ncont+1;
    end;
  elseif ctarqs.item(oplivroaut) = sreg then
    sqtd:=validanumero("Quantos autores quer cadastrar?: ",sqtd);
    nqtd:=sqtd.to_integer;
    from  ncont:=1; 
    until ncont > nqtd
    loop
      tlivroaut.set_isbn(scodigo);
      io.put_string(rotulo(oplivroaut, 2));
      tlivroaut.set_codautor(digita);
      slinha:=pesqarq(tfautor, tlivroaut.codautor,1,10,tamreg(opautor));
      io.put_string(" " + rotulo(opautor, 2));
      io.put_string(substr(slinha, g_nposchave, g_ntamchave)+crlf);
      pesqlinhaexcluida(tflivroaut, tamreg(sreg));
      submenu(14, sreg);
      ncont:=ncont+1;
    end;
  elseif ctarqs.item(opvenda) = sreg then
    sqtd:=validanumero("Quantos livros quer vender?: ",sqtd);
    nqtd:=sqtd.to_integer;
    ntotalpreco:=0;
    from  ncont:=1; 
    until ncont > nqtd
    loop
      slinha:=validaentrada(tflivro,oplivro,1,tvenda.isbn,3,false,optexto);
      if slinha.is_empty=false then
        tvenda.set_isbn(trim(substr(slinha,1,13)));
        if validaisbn(tvenda.isbn) then
          mostrardados(sreg, "", 1);
          tlivro.set_qtdestoque(trim(substr(slinha,134,10)));
          nqtdestoque:=tlivro.qtdestoque.to_integer
          if nqtdestoque > 0 then
             ntotalpreco:=ntotalpreco + g_npreco;
             spreco:=g_npreco.to_string
             tvenda.set_precovenda(spreco);
             g_salvarinclusao:=false;
             submenu(14, sreg);
             if g_salvarinclusao then
                slinha:=pesqarq(tflivro, tvenda.isbn, 1, 13, tamreg(oplivro));
                if slinha.is_empty=false then
                   nqtdestoque:=nqtdestoque-1;
                   tlivro.set_qtdestoque(nqtdestoque.to_string)
                   slinha:=substr(slinha,1,133)+esp(tlivro.qtdestoque,10);
                   escrevearq(tflivro, slinha, "", "");
                end;
             end;
             ncont:=ncont+1;
          else 
            io.put_string(msg_semestoque);
          end;
        else 
          io.put_string(msg_isbninv);
        end;
      end;
    end;
    stotalpreco:=ntotalpreco.to_string
    io.put_string("Total de " + rotulo(sreg,4) + stotalpreco + crlf);
  end;
elseif ctacao.item(opexcluir) = sacao then
  if ctarqs.item(oplivroass) = sreg then
     excluirregligados(tflivroass, sreg, 1, 13, scodigo);
  elseif ctarqs.item(oplivroaut) = sreg then
     excluirregligados(tflivroaut, sreg, 1, 13, scodigo);
  end;
end;

end;
-- ----------------------------------------------------------------------------
-- Realiza a exclusão dos arquivos de ligação.
-- sArq - o arquivo de ligação
-- sreg - o tipo de arquivo de ligação
-- nPosChave - a posicao inicial da chave dentro do registro
-- nTamChave - o tamanho da chave dentro do registro
-- sChave - a chave a ser excluida
-- ----------------------------------------------------------------------------
excluirregligados(sarq: TEXT_FILE_READ_WRITE; sreg, nposchave,
                  ntamchave: INTEGER; schave: STRING) is
local
  slinha, scodigo: STRING;
do
  reconecta(sarq);
  from
    slinha:="";
  until
    sarq.end_of_input
  loop
    slinha.clear_count;
    sarq.read_line_in(slinha);
    if slinha.is_empty=false then
      scodigo:=trim(substr(slinha,nposchave,ntamchave));
      if scodigo.is_equal(schave) then
         btnacao(sreg,opconfirmaexclusao);
      end;
    end;
  end;
end;

end
