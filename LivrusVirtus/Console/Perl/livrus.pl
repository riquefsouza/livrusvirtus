#!/usr/bin/perl
#------------------------------------------------------------------------------
# Sistema integrante do projeto Livrus Virtus.
# Todos os direitos reservados para Henrique F. de Souza.
# Versão programada na linguagem Perl.
#------------------------------------------------------------------------------
# programa Livrus

#use strict;
use warnings;

our %tAssunto = ( codigo => "", assunto => "" );
our %tAutor = ( codigo => "", autor => "" );
our %tEditora = ( codigo => "", editora => "" );
our %tIdioma = ( codigo => "", idioma => "" );
our %tUsuario = ( login => "", senha => "" );
our %tPais = ( codigo => "", pais => "" );
our %tProfissao = ( codigo => "", profissao => "" );
our %tLivro = ( isbn => "", titulo => "", edicao => "", anopubli => "",
   codeditora => "", volume => "", codidioma => "", npaginas => "", 
   preco => "", qtdestoque => "" );
our %tLivroAss = ( isbn => "", codassunto => "" );
our %tLivroAut = ( isbn => "", codautor => "" );
our %tCliente = ( cpf => "", nome => "", email => "", identidade => "",
   sexo => "", telefone => "", dtnascimento => "", codendereco => "",
   codpais => "", codprofissao => "" );
our %tEndereco = ( codigo => "", logradouro => "", bairro => "", cep => "", 
   cidade => "", estado => "" );
our %tVenda = ( dthrvenda => "", cpf => "", isbn => "", precovenda => "" );

# ctTipo 
our $opTexto = 1; our $opNumero = 2; our $opData = 3; our $opDataHora = 4; 
our $opSenha = 5;
# ctArqs 
our $opAssunto = 1; our $opAutor = 2; our $opEditora = 3; our $opEndereco = 4; 
our $opIdioma = 5; our $opPais = 6; our $opProfissao = 7; our $opCliente = 8; 
our $opLivro = 9; our $opLivroAss = 10; our $opLivroAut = 11; 
our $opUsuario = 12; our $opVenda = 13;
# ctAcao 
our $opNovo = 1; our $opAlterar = 2; our $opPesquisar = 3; 
our $opSalvarInclusao = 4; our $opSalvarAlteracao = 4; our $opExcluir = 5; 
our $opConfirmaExclusao = 6; our $opListarTodos = 7;

# constantes
our $false = 0;
our $true = 1;

our $CRLF = "\n"; # windows 
our $TAM_CRLF = 2;
# our $CRLF = "\n";
# our $TAM_CRLF = 1; # unix
# our $CRLF = "\r";
# our $TAM_CRLF = 1; # macintosh 

our $SEEK_SET = 0;
# our $SEEK_CUR = 1;
our $SEEK_END = 2;

our $ARQ_ABRE = "+<";
our $ARQ_CRIA = "+>";

our $QTD_MAX_LINHA = 18;
our $TAM_MAX_STR = 255;

our $MSG_ARQERRO = "Erro: O arquivo não pode ser aberto.";
our $MSG_ERRO = "Erro: opção inválida digite de novo.\n";
our $MSG_OPCAO = "Escolha uma opção: ";
our $MSG_PRESS = "pressione para continuar...";

our $MSG_REGINC = "registro incluido!\n";
our $MSG_REGNINC = "registro não incluido!\n";
our $MSG_REGALT = "registro alterado!\n";
our $MSG_REGNALT = "registro não alterado!\n";
our $MSG_REGEXC = "registro excluido!\n";
our $MSG_REGNEXC = "registro não excluido!\n";
our $MSG_REGEXST = "registro já existe!\n";

our $MSG_NUMINV = "Número inválido ou menor do que 1!\n";
our $MSG_DATAINV = "Data inválida!, formato correto (dd/mm/yyyy)\n";
our $MSG_DTHRINV = "Data/hora inválida!, formato correto (dd/mm/yyyy hh:mm:ss)\n";
our $MSG_ISBNINV = "ISBN inválido!\n";
our $MSG_CPFINV = "CPF inválido!\n";
our $MSG_SENCONFERE = "senha não confere com a senha atual!\n";
our $MSG_SENCONFIRM = "nova senha não confere com a senha confirmada!\n";
our $MSG_LOGINENCON = "login não encontrado!\n";
our $MSG_SEMESTOQUE = "livro não existe no estoque!\n";

our $ARQ_ASSUNTO = "assunto.dat";
our $ARQ_AUTOR = "autor.dat";
our $ARQ_EDITORA = "editora.dat";
our $ARQ_IDIOMA = "idioma.dat";
our $ARQ_USUARIO = "usuario.dat";
our $ARQ_PAIS = "pais.dat";
our $ARQ_PROFISSAO = "profissao.dat";
our $ARQ_LIVRO = "livro.dat";
our $ARQ_LIVASS = "livroass.dat";
our $ARQ_LIVAUT = "livroaut.dat";
our $ARQ_CLIENTE = "cliente.dat";
our $ARQ_ENDERECO = "endereco.dat";
our $ARQ_VENDA = "venda.dat";

our $TAM_ASSUNTO = 40;
our $TAM_AUTOR = 40;
our $TAM_EDITORA = 60;
our $TAM_IDIOMA = 30;
our $TAM_USUARIO = 20;
our $TAM_PAIS = 53;
our $TAM_PROFISSAO = 60;
our $TAM_LIVRO = 143;
our $TAM_LIVASS = 23;
our $TAM_LIVAUT = 23;
our $TAM_CLIENTE = 135;
our $TAM_ENDERECO = 123;
our $TAM_VENDA = 56;

# variaveis gerais

our $bopcao = $false;
our $opmenu = "";
our $g_nPosChave = 0;
our $g_nTamChave = 0;
our $g_nPreco = 0.0;
our $g_SalvarInclusao = $false;

# our $tfAssunto = 1; our $tfAutor = 2; our $tfEditora = 3; our $tfIdioma = 4; 
# our $tfEndereco = 5; our $tfPais = 6; our $tfProfissao = 7; our $tfLivro = 8; 
# our $tfLivroAss = 9; our $tfLivroAut = 10; our $tfCliente = 11; 
# our $tfUsuario = 12; our $tfVenda = 13;


#--- Rotinas básicas --------------------------------------------------------

#------------------------------------------------------------------------------
# Faz uma comparação exata de duas strings.
# sTexto1 - a primeira string
# sTexto2 - a segunda string
# retorna - se uma string é igual ou não a outra.
#------------------------------------------------------------------------------
sub strcmp {
  my $sTexto1 = $_[0];
  my $sTexto2 = $_[1];

   if ((index($sTexto1, $sTexto2) == 0) && 
       (length($sTexto1) == length($sTexto2))) {
      return $true;
   } else {
      return $false;
   }
}  
#------------------------------------------------------------------------------
# Função que retorna uma string digitada do teclado
# retorna - a string digitada
#------------------------------------------------------------------------------
sub digita {
  my $sret;
  chomp( $sret = <STDIN> );
  return $sret;
}
#------------------------------------------------------------------------------
# Função que retorna um pedaço de uma string.
# str - indica a string
# ini - indica a posicao inicial do pedaco
# tam - indica o tamanho do pedaco
# retorna - o pedaço da string
#------------------------------------------------------------------------------
sub copy {
my $str = $_[0];
my $ini = $_[1];
my $tam = $_[2];
  return substr($str,$ini-1,$tam);
}
#------------------------------------------------------------------------------
# Retira os espaços em branco antes ou depois do texto.
# sTexto - o texto a ser retirado os espaços em branco
# retorna - o texto sem os espaços em branco
#------------------------------------------------------------------------------
sub trim {
my $sTexto = shift();  
  $sTexto =~ s/\s+//;
  $sTexto =~ s/\s+//;
  return $sTexto;
}
#------------------------------------------------------------------------------
# Repete um texto um número determinado de vezes.
# sTexto - o texto a ser repetido
# nQtd - a quantidade de vezes
# retorna - o texto repetido
#------------------------------------------------------------------------------
sub repete {
my $sTexto = $_[0];
my $nQtd = $_[1];

  my $sret;
  my $ncont;
  for($ncont = 1; $ncont <= $nQtd; $ncont++) {
    $sret = $sret . $sTexto;
  }
  return $sret;
}
#------------------------------------------------------------------------------
# Coloca espaços em branco a mais de acordo com o tamanho máximo do texto.
# sTexto - o texto
# nTam - tamanho máximo do texto
# retorna - o texto com espaços em branco a mais
#------------------------------------------------------------------------------
sub esp {
my $sTexto = $_[0];
my $nTam = $_[1]; 

return $sTexto.repete(" ",$nTam-length($sTexto));
}
#------------------------------------------------------------------------------
# Faz uma pesquisa relativa de um texto através de um valor chave.
# sTexto - o texto
# sChave - a chave a ser pesquisada
# retorna - se achou ou não a chave dentro do texto
#------------------------------------------------------------------------------
sub strRelativa {
  my $sTexto = $_[0];
  my $sChave = $_[1];

   if (index($sTexto, $sChave) >= 0) {
      return $true;
   } else {
      return $false;
   }
}  
#------------------------------------------------------------------------------
# Calcula o modulo11 de um valor qualquer.
# svalor - a mstring com o número a ser calculado
# ndig - dígito do valor a ser calculado
# retorna - o dígito correto
#------------------------------------------------------------------------------
sub modulo11 {
 my $svalor = $_[0];
 my $ndig = $_[1];

my $ncont; my $nsoma; my $nvalor; my $npos;
my $sres; my $slocal;

 $ncont=1;
 $slocal="";
 while ($ncont <= 11) {
   $slocal=copy($svalor,$ncont,1).$slocal;
   $ncont++;
 }
 $nsoma=0;
 if ($ndig == 1) {
   $ncont=3;
 } else {
   $ncont=2;
 }
 $npos=2;
 while ($ncont <= 11) {
   $sres = copy($slocal,$ncont,1);
   $nvalor = $sres;
   $nsoma=$nsoma + ($nvalor * $npos);
   $ncont++;
   $npos++;
 }
 $nsoma=(11 - ($nsoma % 11));

 if ($nsoma > 9) {
   return 0;
 } else {
   return $nsoma;
 }
}
#------------------------------------------------------------------------------
# Validação de um número de CPF qualquer.
# cpf - a mstring com o número do CPF
# retorna - se é valido ou não
#------------------------------------------------------------------------------
sub validaCPF {
my $cpf = shift();

my $scpf; my $sres;
my $nvalor1; my $nvalor2;

if (length($cpf)==14) {
  $scpf = copy($cpf,1,3).copy($cpf,5,3).copy($cpf,9,3).copy($cpf,13,2);
  $sres = copy($cpf,13,1);
  $nvalor1 = $sres;
  $sres = copy($cpf,14,1);
  $nvalor2 = $sres;
  if ((modulo11($scpf,1)==$nvalor1) && 
      (modulo11($scpf,2)==$nvalor2)) {
    return $true;
  } else {
    return $false;
  }
} else {
    return $false;
  }
}
#------------------------------------------------------------------------------
# Validação de um número ISBN qualquer.
# isbn - a mstring com o número do ISBN
# retorna - se é valido ou não
#------------------------------------------------------------------------------
sub validaISBN {
my $isbn = shift();

my $sisbn; my $sdigito; my $snum;
my $nvalor; my $nsoma; my $ncont;

if (length($isbn)==13) {
  $sdigito = copy($isbn, length($isbn), 1);
  $sisbn="";
  for($ncont = 1; $ncont <= length($isbn)-1; $ncont++)  {
    if (strcmp(copy($isbn,$ncont,1),"-")==$false) {
      $sisbn = $sisbn . copy($isbn,$ncont,1);
    }
  }
  if (strcmp($sdigito, "X")==$true) {
    $nsoma = 10;
  } else {
    $nvalor = $sdigito;
    $nsoma = $nvalor;
  }
  for($ncont = 1; $ncont <= 9; $ncont++)  {
    $snum = copy($sisbn, $ncont, 1);
    $nvalor = $snum;
    $nsoma = $nsoma + ($nvalor * (11 - $ncont));
  }
  if (($nsoma % 11) == 0) {
    return $true;
  } else {
    return $false;
  }
} else {
  return $false;
 }
}
#------------------------------------------------------------------------------
# Esconde a digitação da senha
# retorna - a senha digitada
#------------------------------------------------------------------------------
sub digitaSenha {
my $sRotulo = $_[0];
my $nTamSenha = $_[1];

my $sSenha; my $sLetra; my $ncont;
 
print($sRotulo);
$sSenha = digita();
  
# $ncont  = 0;
# $sLetra = '\0';
# while(($sLetra!~'\r') && ($ncont < $nTamSenha)) {
#   $sLetra = getch();
#   if ($sLetra!~'\r') {
#      $sSenha = $sSenha . $sLetra;
#   }
#   $ncont++;
# }
# print("\n");

return $sSenha;
}
#------------------------------------------------------------------------------
# Validação de um número qualquer.
# sRotulo - o texto antes de se digitar o número
# sNumero - a mstring com o valor do número
# retorna - o sNumero
#------------------------------------------------------------------------------
sub validaNumero {
my $sRotulo = $_[0];
my $sNumero = $_[1];

my $nnum; my $nStatus;

$nStatus = -1;
 while ($nStatus!=0) {
  print($sRotulo);
  $sNumero = digita();
  $nnum = $sNumero;
  if ( $nnum =~ /[0-9]/ ) {
    if ($nnum < 1) {
       print($MSG_NUMINV);
    } else {
      $nStatus=0;
    }
  } else {
    print($MSG_NUMINV);
  }
}
return $sNumero;
}
#------------------------------------------------------------------------------
# Validação de uma data ou data/hora qualquer.
# sRotulo - o texto antes de se digitar a data/hora
# sDataHora - a mstring com o valor da data/hora
# bSoData - indica se vai validar somente uma data sem a hora
# retorna - a sDataHora
#------------------------------------------------------------------------------
sub validaDataHora {
my $sRotulo = $_[0];
my $sDataHora = $_[1];
my $bSoData = $_[2];

my $sdia; my $smes; my $sano; my $shora; my $smin; my $sseg;
my $ndia; my $nmes; my $nano; my $nhora; my $nmin; my $nseg;
my $ntam;

my $bvalida = $false;
my $bdatavalida = $false;
my $bhoravalida = $false;
my $nudiames = 0;
if ($bSoData==$true) { 
  $ntam=10; 
} else { 
  $ntam=19;
}
while ($bvalida==$false) {
  print($sRotulo);
  $sDataHora = digita();
  if (length($sDataHora)==$ntam) {
    $sdia = copy($sDataHora,1,2);
    $ndia = $sdia;
    $smes = copy($sDataHora,4,2);
    $nmes = $smes;
    $sano = copy($sDataHora,7,4);
    $nano = $sano;
  
    if (($nano >= 1) && ($nano <= 9999)) {
      if (($nmes >= 1) && ($nmes <= 31)) {
          SWITCH: {
          	if ($nmes==1 || $nmes==3 || $nmes==5 || $nmes==7 || 
                $nmes==8 || $nmes==10 || $nmes==12) { 
              $nudiames = 31;
              last SWITCH;
            }
          	if ($nmes==2) { 
               # ano bissexto 
               if (($nano % 4)==0) { 
                 $nudiames = 29;
               } else {
                 $nudiames = 28;
               }
              last SWITCH;
            }
          	if ($nmes==4 || $nmes==6 || $nmes==9 || $nmes==11) { 
              $nudiames = 30;
              last SWITCH;
            }
          }
          if (($ndia >=1) && ($ndia <= $nudiames)) {
             $bdatavalida = $true;
          }
      }
    }
  
    if ($bSoData==$true) {
       if ($bdatavalida==$true) {
           $bvalida = $true;
       } else {
  		   print($MSG_DATAINV);
       }
    } else {
      if ($bdatavalida==$true) {
          $shora = copy($sDataHora,12,2);
          $nhora = $shora;
          $smin = copy($sDataHora,15,2);
          $nmin = $smin;
          $sseg = copy($sDataHora,18,2);
          $nseg = $sseg;
  
          if (($nhora >= 0) && ($nhora <= 23)) {
            if (($nmin >= 0) && ($nmin <= 59)) {
              if (($nseg >= 0) && ($nseg <= 59)) {
                 $bhoravalida = $true;
              } 
            }
          }
  
          if ($bhoravalida==$true) {
  		      $bvalida = $true;
          } else {
  		      print($MSG_DTHRINV);
          }
      } else {
        print($MSG_DTHRINV);
      }
    }
  } else {
    if ($bSoData==$true) { 
      print($MSG_DATAINV);
    } else {
      print($MSG_DTHRINV);
    } 
  }
}
return $sDataHora;
}
#------------------------------------------------------------------------------
# Retorna a Data e a hora do sistema.
# retorna - a data e a hora
#------------------------------------------------------------------------------
sub retDataHora {
my $sdatahora;

my @stempo=localtime(time);
my $seg = $stempo[0];
my $min = $stempo[1];
my $hora = $stempo[2];
my $dia = $stempo[3];
if ($dia < 10) { $dia = '0'.$dia; }
my $mes = $stempo[4];
if ($mes < 10) { $mes = '0'.$mes; }
my $ano = $stempo[5];
$ano += 1900; 
$sdatahora = $dia."/".$mes."/".$ano." ".$hora.":".$min.":".$seg;
return $sdatahora;
}
#--- Rotinas de manipulação de arquivos -------------------------------------

#------------------------------------------------------------------------------
# Calcula o tamanho do arquivo.
# sArq - o arquivo
# retorna - o tamanho do arquivo
#------------------------------------------------------------------------------
sub tamArq {
my $sArq = shift();
my $ntam;

seek($sArq, 0, $SEEK_END);
$ntam = tell($sArq);
seek($sArq, 0, $SEEK_SET);
return $ntam;
}
#------------------------------------------------------------------------------
# Abre ou cria os arquivos do sistema.
# bAbre - condição para abrir ou criar os arquivos do sistema
#------------------------------------------------------------------------------
sub abrecriaArqs {
my $bAbre = shift();

if ($bAbre) {
  open tfAssunto, $ARQ_ABRE, $ARQ_ASSUNTO
    or die $MSG_ARQERRO." --> ".$ARQ_ASSUNTO."\n";
  open tfAutor, $ARQ_ABRE, $ARQ_AUTOR
    or die $MSG_ARQERRO." --> ".$ARQ_AUTOR."\n";
  open tfEditora, $ARQ_ABRE, $ARQ_EDITORA
    or die $MSG_ARQERRO." --> ".$ARQ_EDITORA."\n";
  open tfIdioma, $ARQ_ABRE, $ARQ_IDIOMA
    or die $MSG_ARQERRO." --> ".$ARQ_IDIOMA."\n";
  open tfEndereco, $ARQ_ABRE, $ARQ_ENDERECO
    or die $MSG_ARQERRO." --> ".$ARQ_ENDERECO."\n";
  open tfPais, $ARQ_ABRE, $ARQ_PAIS
    or die $MSG_ARQERRO." --> ".$ARQ_PAIS."\n";
  open tfProfissao, $ARQ_ABRE, $ARQ_PROFISSAO
    or die $MSG_ARQERRO." --> ".$ARQ_PROFISSAO."\n";
  open tfLivro, $ARQ_ABRE, $ARQ_LIVRO
    or die $MSG_ARQERRO." --> ".$ARQ_LIVRO."\n";
  open tfLivroAss, $ARQ_ABRE, $ARQ_LIVASS
    or die $MSG_ARQERRO." --> ".$ARQ_LIVASS."\n";
  open tfLivroAut, $ARQ_ABRE, $ARQ_LIVAUT
    or die $MSG_ARQERRO." --> ".$ARQ_LIVAUT."\n";
  open tfCliente, $ARQ_ABRE, $ARQ_CLIENTE
    or die $MSG_ARQERRO." --> ".$ARQ_CLIENTE."\n";
  open tfUsuario, $ARQ_ABRE, $ARQ_USUARIO
    or die $MSG_ARQERRO." --> ".$ARQ_USUARIO."\n";
  open tfVenda, $ARQ_ABRE, $ARQ_VENDA
    or die $MSG_ARQERRO." --> ".$ARQ_VENDA."\n";
} else {
  open tfAssunto, $ARQ_CRIA, $ARQ_ASSUNTO;
  open tfAutor, $ARQ_CRIA, $ARQ_AUTOR;
  open tfEditora, $ARQ_CRIA, $ARQ_EDITORA;
  open tfIdioma, $ARQ_CRIA, $ARQ_IDIOMA;
  open tfEndereco, $ARQ_CRIA, $ARQ_ENDERECO;
  open tfPais, $ARQ_CRIA, $ARQ_PAIS;
  open tfProfissao, $ARQ_CRIA, $ARQ_PROFISSAO;
  open tfLivro, $ARQ_CRIA, $ARQ_LIVRO;
  open tfLivroAss, $ARQ_CRIA, $ARQ_LIVASS;
  open tfLivroAut, $ARQ_CRIA, $ARQ_LIVAUT;
  open tfCliente, $ARQ_CRIA, $ARQ_CLIENTE;
  open tfUsuario, $ARQ_CRIA, $ARQ_USUARIO;
  open tfVenda, $ARQ_CRIA, $ARQ_VENDA;
}
}
#------------------------------------------------------------------------------
# Fecha todos os arquivos abertos.
#------------------------------------------------------------------------------
sub fechaArqs {
 close tfAssunto;
 close tfAutor;
 close tfEditora;
 close tfIdioma;
 close tfEndereco;
 close tfPais;
 close tfProfissao;
 close tfLivro;
 close tfLivroAss;
 close tfLivroAut;
 close tfCliente;
 close tfUsuario;
 close tfVenda;
}
#------------------------------------------------------------------------------
# Pesquisa um registro através de um valor chave num arquivo.
# sArq - o arquivo
# sChave - a chave a ser pesquisada
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o registro pesquisado
#------------------------------------------------------------------------------
sub pesqArq {
my $sArq = $_[0];
my $sChave = $_[1];
my $nPosChave = $_[2];
my $nTamChave = $_[3];
my $nTamLinha = $_[4];

my $slinha; my $sres; my $nPosicao;
my $bQuebra = $false;
seek($sArq, 0, $SEEK_SET);
while ((!eof($sArq)) && ($bQuebra==$false)) {
  $slinha = <$sArq>;
  $sres = trim(copy($slinha, $nPosChave, $nTamChave));
  if (strcmp($sres,$sChave)==$true) {
     $bQuebra = $true;
  }
}
$nPosicao = tell($sArq)-($nTamLinha + $TAM_CRLF);
if ($nPosicao > 0) {
   seek($sArq, $nPosicao, $SEEK_SET);
} else {
   seek($sArq, 0, $SEEK_SET);
}
if (strcmp($sres,$sChave)==$false) {
   return "";  
} else {
   return copy($slinha,1,$nTamLinha);
} 
}
#------------------------------------------------------------------------------
# Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
# sArq - o arquivo
# nTamLinha - o tamanho do registro
#------------------------------------------------------------------------------
sub pesqLinhaExcluida {
my $sArq = $_[0];
my $nTamLinha = $_[1];

my $sExcluido = pesqArq($sArq, "*", 1, 1, $nTamLinha);
if (length($sExcluido)==0) {
   seek($sArq, tamArq($sArq), $SEEK_SET);
}
}
#------------------------------------------------------------------------------
# Pesquisa o maior código num arquivo.
# sArq - o arquivo
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# retorna - o maior código
#------------------------------------------------------------------------------
sub pesqMaxCod {
my $sArq = $_[0];
my $nPosChave = $_[1];
my $nTamChave = $_[2];
my $nTamLinha = $_[3];

my $slinha; my $sres; my $nCod;
my $bQuebra = $false;
my $nMaior = 0;
seek($sArq, 0, $SEEK_SET);
while ((!eof($sArq)) && ($bQuebra==$false)) {
  $slinha = <$sArq>;
  $sres = trim(copy($slinha,$nPosChave,$nTamChave));
  $nCod = $sres;
  if ($nCod > $nMaior) {
     $nMaior = $nCod;
  }
}
pesqLinhaExcluida($sArq, $nTamLinha);
$sres = $nMaior+1;
return $sres;
}
#------------------------------------------------------------------------------
# Grava os registros num determinado arquivo.
# sArq - o arquivo
# sTexto - o registro a ser gravado
# sMsgAcerto - a mensagem caso o registro foi gravado
# sMsgErro - a mensagem caso o registro não foi gravado
#------------------------------------------------------------------------------
sub escreveArq {
my $sArq = $_[0];
my $sTexto = $_[1];
my $sMsgAcerto = $_[2];
my $sMsgErro = $_[3];

$sTexto = $sTexto . $CRLF;
print $sArq $sTexto;
print($sMsgAcerto."\n");
#else 
#   print($sMsgErro."\n");
}

#--- Rotinas de implementação do sistema e de interface ---------------------

#------------------------------------------------------------------------------
# Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o registro montado
#------------------------------------------------------------------------------
sub LinhaReg {
my $sreg = shift();
my $slinha;

if ($sreg==$opAssunto) {
   $slinha=esp($tAssunto{"codigo"},10).esp($tAssunto{"assunto"},30);
} elsif ($sreg==$opAutor) {
   $slinha=esp($tAutor{"codigo"},10).esp($tAutor{"autor"},30);
} elsif ($sreg==$opEditora) {
   $slinha=esp($tEditora{"codigo"},10).esp($tEditora{"editora"},50);
} elsif ($sreg==$opEndereco) {
   $slinha=esp($tEndereco{"codigo"},10).esp($tEndereco{"logradouro"},40).
   esp($tEndereco{"bairro"},15).esp($tEndereco{"cep"},8).esp($tEndereco{"cidade"},30).
   esp($tEndereco{"estado"},20);
} elsif ($sreg==$opIdioma) {
   $slinha=esp($tIdioma{"codigo"},10).esp($tIdioma{"idioma"},20);
} elsif ($sreg==$opPais) {
   $slinha=esp($tPais{"codigo"},3).esp($tPais{"pais"},50);
} elsif ($sreg==$opProfissao) {
   $slinha=esp($tProfissao{"codigo"},10).esp($tProfissao{"profissao"},50);
} elsif ($sreg==$opUsuario) {
   $slinha=esp($tUsuario{"login"},10).esp($tUsuario{"senha"},10);
} elsif ($sreg==$opLivro) {
   $slinha=esp($tLivro{"isbn"},13).esp($tLivro{"titulo"},50).
   esp($tLivro{"edicao"},10).esp($tLivro{"anopubli"},10).esp($tLivro{"codeditora"},10).
   esp($tLivro{"volume"},10).esp($tLivro{"codidioma"},10).esp($tLivro{"npaginas"},10).
   esp($tLivro{"preco"},10).esp($tLivro{"qtdestoque"},10);
} elsif ($sreg==$opLivroAss) {
   $slinha=esp($tLivroAss{"isbn"},13).esp($tLivroAss{"codassunto"},10);
} elsif ($sreg==$opLivroAut) {
   $slinha =esp($tLivroAut{"isbn"},13).esp($tLivroAut{"codautor"},10);
} elsif ($sreg==$opCliente) {
   $slinha=esp($tCliente{"cpf"},14).esp($tCliente{"nome"},30).
   esp($tCliente{"email"},30).esp($tCliente{"identidade"},10).esp($tCliente{"sexo"},1).
   esp($tCliente{"telefone"},17).esp($tCliente{"dtnascimento"},10).
   esp($tCliente{"codendereco"},10).esp($tCliente{"codpais"},3).
   esp($tCliente{"codprofissao"},10);
} elsif ($sreg==$opVenda) {
   $slinha=esp($tVenda{"dthrvenda"},19).esp($tVenda{"cpf"},14).
   esp($tVenda{"isbn"},13).esp($tVenda{"precovenda"},10);
}
return $slinha;
}
#------------------------------------------------------------------------------
# Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# retorna - o tamanho do registro
#------------------------------------------------------------------------------
sub tamReg {
my $sreg = shift();
my $nret = 0;

if ($sreg==$opAssunto) { $nret = $TAM_ASSUNTO;
} elsif ($sreg==$opAutor) { $nret = $TAM_AUTOR;
} elsif ($sreg==$opEditora) { $nret = $TAM_EDITORA;
} elsif ($sreg==$opEndereco) { $nret = $TAM_ENDERECO;
} elsif ($sreg==$opIdioma) { $nret = $TAM_IDIOMA;
} elsif ($sreg==$opPais) { $nret = $TAM_PAIS;
} elsif ($sreg==$opProfissao) { $nret = $TAM_PROFISSAO;
} elsif ($sreg==$opUsuario) { $nret = $TAM_USUARIO;
} elsif ($sreg==$opLivro) { $nret = $TAM_LIVRO;
} elsif ($sreg==$opLivroAss) { $nret = $TAM_LIVASS;
} elsif ($sreg==$opLivroAut) { $nret = $TAM_LIVAUT;
} elsif ($sreg==$opCliente) { $nret = $TAM_CLIENTE;
} elsif ($sreg==$opVenda) { $nret = $TAM_VENDA;
}
return $nret;
}
#------------------------------------------------------------------------------
# Seleciona o rotulo de cada campo de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# nNum - indica qual rotulo será retornado
# retorna - o rotulo
#------------------------------------------------------------------------------
sub rotulo {
my $sreg = $_[0];
my $nNum = $_[1];
my $sret;
if ($sreg==$opAssunto) {
   SWITCH: {
     if ($nNum == 0) { 
       $sret="Assunto(s) não encontrado(s)!";
       last SWITCH;
     }
     if ($nNum == 1) {
         $sret="Código do assunto: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Assunto: ";
         $g_nPosChave = 11;
         $g_nTamChave = 30;
         last SWITCH;
     }
   }
} elsif ($sreg==$opAutor) {
   SWITCH: {
     if ($nNum == 0) { $sret="Autor(es) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="Código do autor: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Autor: ";
         $g_nPosChave = 11;
         $g_nTamChave = 30;
         last SWITCH;
     }
   }
} elsif ($sreg==$opEditora) {
   SWITCH: {
     if ($nNum == 0) { $sret="Editora(s) não encontrada(s)!"; }
     if ($nNum == 1) {
         $sret="Código da editora: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Editora: ";
         $g_nPosChave = 11;
         $g_nTamChave = 50;
         last SWITCH;
     }
   }
} elsif ($sreg==$opEndereco) {
   SWITCH: {
     if ($nNum == 0) { $sret="Endereço(s) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="Código do endereço: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Logradouro: ";
         $g_nPosChave = 11;
         $g_nTamChave = 40;
         last SWITCH;
     }
     if ($nNum == 3) {
         $sret="Bairro: ";
         $g_nPosChave = 51;
         $g_nTamChave = 15;
         last SWITCH;
     }
     if ($nNum == 4) {
         $sret="CEP: ";
         $g_nPosChave = 66;
         $g_nTamChave = 8;
         last SWITCH;
     }
     if ($nNum == 5) {
         $sret="Cidade: ";
         $g_nPosChave = 74;
         $g_nTamChave = 30;
         last SWITCH;
     }
     if ($nNum == 6) {
         $sret="Estado: ";
         $g_nPosChave = 104;
         $g_nTamChave = 20;
         last SWITCH;
     }
   }
} elsif ($sreg==$opIdioma) {
   SWITCH: {
     if ($nNum == 0) { $sret="Idioma(s) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="Código do idioma: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Idioma: ";
         $g_nPosChave = 11;
         $g_nTamChave = 20;
         last SWITCH;
     }
   }
} elsif ($sreg==$opPais) {
   SWITCH: {
     if ($nNum == 0) { $sret="País(es) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="Código do país: ";
         $g_nPosChave = 1;
         $g_nTamChave = 3;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="País: ";
         $g_nPosChave = 4;
         $g_nTamChave = 50;
         last SWITCH;
     }
   }
} elsif ($sreg==$opProfissao) {
   SWITCH: {
     if ($nNum == 0) { $sret="Profissão(es) não encontrada(s)!"; }
     if ($nNum == 1) {
         $sret="Código da profissão: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Profissão: ";
         $g_nPosChave = 11;
         $g_nTamChave = 50;
         last SWITCH;
     }
   }
} elsif ($sreg==$opUsuario) {
   SWITCH: {
     if ($nNum == 0) { $sret="login ou senha incorreta, tente de novo!"; }
     if ($nNum == 1) {
         $sret="Login: ";
         $g_nPosChave = 1;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Senha: ";
         $g_nPosChave = 11;
         $g_nTamChave = 10;
         last SWITCH;
     }
   }
} elsif ($sreg==$opLivro) {
   SWITCH: {
     if ($nNum == 0) { $sret="Livro(s) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="ISBN: ";
         $g_nPosChave = 1;
         $g_nTamChave = 13;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Título: ";
         $g_nPosChave = 14;
         $g_nTamChave = 50;
         last SWITCH;
     }
     if ($nNum == 3) {
         $sret="Edição: ";
         $g_nPosChave = 64;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 4) {
         $sret="Ano de Publicação: ";
         $g_nPosChave = 74;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 5) {
         $sret="Código da editora: ";
         $g_nPosChave = 84;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 6) {
         $sret="Volume: ";
         $g_nPosChave = 94;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 7) {
         $sret="Código do idioma: ";
         $g_nPosChave = 104;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 8) {
         $sret="Número de páginas: ";
         $g_nPosChave = 114;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 9) {
         $sret="Preço: ";
         $g_nPosChave = 124;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 10) {
          $sret="Qtd. Estoque: ";
          $g_nPosChave = 134;
          $g_nTamChave = 10;
          last SWITCH;
     }
   }
} elsif ($sreg==$opLivroAss) {
   SWITCH: {
     if ($nNum == 0) { $sret="Assunto(s) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="ISBN: ";
         $g_nPosChave = 1;
         $g_nTamChave = 13;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Código do assunto: ";
         $g_nPosChave = 14;
         $g_nTamChave = 10;
         last SWITCH;
     }
   }
} elsif ($sreg==$opLivroAut) {
   SWITCH: {
     if ($nNum == 0) { $sret="Autor(s) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="ISBN: ";
         $g_nPosChave = 1;
         $g_nTamChave = 13;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Código do autor: ";
         $g_nPosChave = 14;
         $g_nTamChave = 10;
          last SWITCH;
}
   }
} elsif ($sreg==$opCliente) {
   SWITCH: {
     if ($nNum == 0) { $sret="Cliente(s) não encontrado(s)!"; }
     if ($nNum == 1) {
         $sret="CPF: ";
         $g_nPosChave = 1;
         $g_nTamChave = 14;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="Nome: ";
         $g_nPosChave = 15;
         $g_nTamChave = 30;
         last SWITCH;
     }
     if ($nNum == 3) {
         $sret="E-mail: ";
         $g_nPosChave = 45;
         $g_nTamChave = 30;
         last SWITCH;
     }
     if ($nNum == 4) {
         $sret="Identidade: ";
         $g_nPosChave = 75;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 5) {
         $sret="Sexo: ";
         $g_nPosChave = 85;
         $g_nTamChave = 1;
         last SWITCH;
     }
     if ($nNum == 6) {
         $sret="Telefone: ";
         $g_nPosChave = 86;
         $g_nTamChave = 17;
         last SWITCH;
     }
     if ($nNum == 7) {
         $sret="Dt. Nascimento: ";
         $g_nPosChave = 103;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 8) {
         $sret="Código do endereço: ";
         $g_nPosChave = 113;
         $g_nTamChave = 10;
         last SWITCH;
     }
     if ($nNum == 9) {
         $sret="Código do país: ";
         $g_nPosChave = 123;
         $g_nTamChave = 3;
         last SWITCH;
     }
     if ($nNum == 10) {
          $sret="Código da Profissão: ";
          $g_nPosChave = 126;
          $g_nTamChave = 10;
         last SWITCH;
     }
   }
} elsif ($sreg==$opVenda) {
   SWITCH: {
     if ($nNum == 0) { $sret="Venda(s) não encontrada(s)!"; }
     if ($nNum == 1) {
         $sret="Data/Hora venda: ";
         $g_nPosChave = 1;
         $g_nTamChave = 19;
         last SWITCH;
     }
     if ($nNum == 2) {
         $sret="CPF: ";
         $g_nPosChave = 20;
         $g_nTamChave = 14;
         last SWITCH;
     }
     if ($nNum == 3) {
         $sret="ISBN: ";
         $g_nPosChave = 34;
         $g_nTamChave = 13;
         last SWITCH;
     }
     if ($nNum == 4) {
         $sret="Preço de venda: ";
         $g_nPosChave = 47;
         $g_nTamChave = 10;
         last SWITCH;
     }
   }
}

return $sret;
}
#------------------------------------------------------------------------------
# Indica se continua ou não mostrando um número máximo de linhas.
# nlinha - a linha a ser continuada
# nQtdLinha - a quantidade de linhas a serem mostradas
# retorna - se continua ou não
#------------------------------------------------------------------------------
sub ContinuaSN {
my $nlinha = $_[0];
my $nQtdLinha = $_[1];

my $bSOp; my $opCSubMenu;
my $bret = $false;
if ($nlinha > 0) {
  if (($nlinha % $nQtdLinha) == 0) {
      $bSOp = $true;
      while($bSOp==$true) {
       menu(13);
       $opCSubMenu = digita();
       if (($opCSubMenu=~'S') || ($opCSubMenu=~'s')) { $bSOp = $false; }
       elsif (($opCSubMenu=~'N') || ($opCSubMenu=~'n')) {
          $bret = $true;
          $bSOp = $false;
       } else { print(MSG_ERRO); }
      }
  }
}

return $bret;
}
#------------------------------------------------------------------------------
# Lista vários registros de acordo com a pesquisa feita.
# sArq - o arquivo
# sreg - o tipo de arquivo
# sChave - a chave a ser pesquisada
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# nTamLinha - o tamanho do registro
# nQtdLinha - a quantidade de linhas a serem mostradas
# retorna - se encontrou algum registro
#------------------------------------------------------------------------------
sub ListarTodos { 
my $sArq = $_[0]; my $sreg = $_[1]; my $sChave = $_[2]; my $nPosChave = $_[3];
my $nTamChave = $_[4]; my $nTamLinha = $_[5]; my $nQtdLinha = $_[6];
my $bPesqRelativa = $_[7];

my $slinha; my $bAchou; my $sres;

my $bRet = $false;
my $bQuebra = $false;
my $nCont = 0;
mostrarDados($sreg, "", 2);
seek($sArq, 0, $SEEK_SET);
while ((!eof($sArq)) && ($bQuebra==$false)) {
  $slinha = <$sArq>;

  if ($bPesqRelativa==$true) {
    $sres = trim(copy($slinha,$nPosChave,$nTamChave));
    if (strRelativa($sres,$sChave)==$true) {
       $bAchou = $true;
       $bRet = $true;
    } else {
       $bAchou = $false;
    }   
  } else {
    $bAchou = $true;
    $bRet = $true;
  }

  if ($bAchou==$true) {
    mostrarDados($sreg, copy($slinha,1,$nTamLinha), 3);
    $nCont++;
  }

  $bQuebra = ContinuaSN($nCont, $nQtdLinha);
}
return $bRet;
}
#------------------------------------------------------------------------------
# Lista vários registros entre arquivos de acordo com a pesquisa feita.
# sArq1 - o arquivo de ligação
# sreg1 - o tipo de arquivo de ligação
# nPosChave1 - a posicao inicial da primeira chave no arquivo de ligação
# nTamChave1 - o tamanho da primeira chave no arquivo de ligação
# nPosChave2 - a posicao inicial da segunda chave do arquivo de ligação
# nTamChave2 - o tamanho da segunda chave do arquivo de ligação
# sChave - a chave a ser pesquisada no arquivo de ligação
# sArq2 - o arquivo a ser pesquisado
# sreg2 - o tipo de arquivo a ser pesquisado
# nPosChave3 - a posicao inicial da chave do arquivo pesquisado
# nQtdLinha - a quantidade de linhas a serem mostradas
#------------------------------------------------------------------------------
sub ListarRegLigados {
my $sArq1 = $_[0]; my $sreg1 = $_[1]; my $nPosChave1 = $_[2]; 
my $nTamChave1 = $_[3]; my $nPosChave2 = $_[4]; my $nTamChave2 = $_[5]; 
my $sChave = $_[6]; my $sArq2 = $_[7]; my $sreg2 = $_[8]; 
my $nPosChave3 = $_[9]; my $nQtdLinha = $_[10];

my $slinha1; my $sCodigo1; my $sCodigo2; my $slinha2;
my $bRet = $false;
my $nCont = 0;
my $bQuebra = $false;
mostrarDados($sreg2, "", 2);
seek($sArq1, 0, $SEEK_SET);
while ((!eof($sArq1)) && ($bQuebra==$false)) {
  $slinha1 = <$sArq1>;
  $sCodigo1 = trim(copy($slinha1,$nPosChave1,$nTamChave1));
  if (strcmp($sCodigo1, $sChave)==$true) {
    $sCodigo2 = trim(copy($slinha1,$nPosChave2,$nTamChave2));
    $slinha2 = pesqArq($sArq2, $sCodigo2, $nPosChave3, 
               $nTamChave2, tamReg($sreg2));
    mostrarDados($sreg2, copy($slinha2, 1, tamReg($sreg2)), 3);
    $bRet = $true;
    $nCont++;
  }
  $bQuebra = ContinuaSN($nCont, $nQtdLinha);
}
if ($bRet==$false) {
   print(rotulo($sreg2,0)."\n");
}
}
#------------------------------------------------------------------------------
# Valida a entrada de registros de acordo com a pesquisa feita.
# sArq - o arquivo
# sreg - o tipo de arquivo
# nTexto - o numero do rótulo da entrada
# sEntrada - a chave a ser pesquisada e validada
# nTentativas - o número máximo de tentativas
# bPesqRelativa - indica se vai realizar uma pesquisa relativa
# bTipoEntrada - indica o tipo de entrada
# retorna - o registro pesquisado e validado
#------------------------------------------------------------------------------
sub validaEntrada {
my $sArq = $_[0]; my $sreg = $_[1]; my $nTexto = $_[2]; my $sEntrada = $_[3]; 
my $nTentativas = $_[4]; my $bPesqRelativa = $_[5]; my $bTipoEntrada = $_[6];

my $sres;
my $nTamLinha = tamReg($sreg);
my $sMsgErro = rotulo($sreg,0);
my $sTexto = rotulo($sreg,$nTexto);
my $nPosChave = $g_nPosChave;
my $nTamChave = $g_nTamChave;

my $ncont = 1;
my $bQuebra = $false;
  while (($bQuebra==$false) && ($ncont <= $nTentativas )) {
    if ($bTipoEntrada==$opTexto) {
      print($sTexto);
      $sEntrada = digita();
    } elsif ($bTipoEntrada==$opNumero) {
       $sEntrada = validaNumero($sTexto,$sEntrada);
    } elsif ($bTipoEntrada==$opData) {
       $sEntrada = validaDataHora($sTexto,$sEntrada,$true);
    } elsif ($bTipoEntrada==$opDataHora) {
       $sEntrada = validaDataHora($sTexto,$sEntrada,$false);
    } elsif ($bTipoEntrada==$opSenha) {
       $sEntrada = digitaSenha($sTexto, 10);
    }

    if ($bPesqRelativa==$true) {
       if (ListarTodos($sArq, $sreg, $sEntrada, $nPosChave, $nTamChave, $nTamLinha,
           $QTD_MAX_LINHA, $true)) {
         $sres = " ";
       }  
    } else {
       $sres = pesqArq($sArq, $sEntrada, $nPosChave, $nTamChave, $nTamLinha);
    }
    if (length($sres) == 0) {
       print($sMsgErro."\n");
    } else {
       $bQuebra = $true;
    }
    $ncont++;
  }
return $sres;
}
#------------------------------------------------------------------------------
# Mostra a tela de splash do sistema.
#------------------------------------------------------------------------------
sub frmSplash {
my $cont;

 print("*---------------------------------------".
 "-------------------------------------*\n");
 print("| LL    II VV   VV RRRRR  UU  UU   SSSS ".
 "VV   VV II RRRRR  TTTT UU  UU   SSSS |\n");
 print("| LL    II  VV VV  RR   R UU  UU  SS    ".
 " VV VV  II RR   R  TT  UU  UU  SS    |\n");
 print("| LL    II   VVV   RRRRR  UU  UU    SS  ".
 "  VVV   II RRRRR   TT  UU  UU    SS  |\n");
 print("| LLLLL II    V    RR   R  UUUU  SSSS   ".
 "   V    II RR   R  TT   UUUU  SSSS   |\n");
 print("*---------------------------------------".
 "-------------------------------------*\n");
 for($cont = 1; $cont <= 18; $cont++) { print("\n"); }
 print($MSG_PRESS);
 $cont = digita();
}
#------------------------------------------------------------------------------
# Mostra a tela de sobre do sistema.
#------------------------------------------------------------------------------
sub frmSobre {
my $cont;

my $tela = <<'FRMSOBRE';
*------------------------------------------------------------*
|  LL        II  VV       VV  RRRRRRR   UU    UU   SSSSSSS   |
|  LL        II   VV     VV   RR     R  UU    UU  SS         |
|  LL        II    VV   VV    RR     R  UU    UU   SSSS      |
|  LL        II     VV VV     RRRRRRR   UU    UU     SSSS    |
|  LLLL      II      VVV      RR RR     UU    UU        SS   |
|  LLLLLLLL  II       V       RR   RR    UUUUUU   SSSSSSSS   |
|                                                            |
|  VV       VV  II  RRRRRRR   TTTTTTTT  UU    UU   SSSSSSS   |
|   VV     VV   II  RR     R     TT     UU    UU  SS         |
|    VV   VV    II  RR     R     TT     UU    UU   SSSS      |
|     VV VV     II  RRRRRRR      TT     UU    UU     SSSS    |
|      VVV      II  RR RR        TT     UU    UU        SS   |
|       V       II  RR   RR      TT      UUUUUU   SSSSSSSS   |
|                                                            |
|                                               Versao 1.0.0 |
| Sistema integrante do projeto Livrus Virtus.               |
| Todos os direitos reservados para Henrique F. de Souza.    |
| Versao programada na linguagem Perl.                       |
*------------------------------------------------------------*
FRMSOBRE
 print $tela;
 for($cont = 1; $cont <= 4; $cont++) { print("\n"); }
 print($MSG_PRESS);
 $cont = digita();
}
#-----------------------------------------------------------------------------
# Mostra a tela de login do sistema.
# retorna - se o login foi validado corretamente
#------------------------------------------------------------------------------
sub frmLogin {
my $bret;
my $slinha;

  $bret = $false;
  print("*--------------------------------------------------------------*\n");
  print("| Login do sistema                                             |\n");
  print("*--------------------------------------------------------------*\n");
  $slinha = validaEntrada(tfUsuario, $opUsuario, 1, $tUsuario{"login"}, 3,
        $false, $opTexto);
  if (length($slinha) > 0) {
     $slinha = validaEntrada(tfUsuario, $opUsuario, 2, $tUsuario{"senha"}, 3,
        $false, $opSenha);
     if (length($slinha) > 0) {
        $tUsuario{"login"} = trim(copy($slinha, 1, 10));
        $tUsuario{"senha"} = trim(copy($slinha, 11, 10));
        $bret = $true;
     }
  }
  print("\n");
  return $bret;
}
#------------------------------------------------------------------------------
# Mostra os menus do sistema.
# num - o número do menu
#------------------------------------------------------------------------------
sub menu {
my $num = shift();
my $tela;

 if ($num==1) {
   print("*--------------------------------------------------------------*\n");
   print("| (C)adastros        (P)esquisas     (V)endas        (O)pções  |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==2) {
   print("*---------------------------------*\n");
   print("| 01. Cadastro de Assuntos        |\n");
   print("| 02. Cadastro de Autores         |\n");
   print("| 03. Cadastro de Editoras        |\n");
   print("| 04. Cadastro de Endereços       |\n");
   print("| 05. Cadastro de Idiomas         |\n");
   print("| 06. Cadastro de Países          |\n");
   print("| 07. Cadastro de Profissões      |\n");
   print("| 08. Cadastro de Clientes        |\n");
   print("| 09. Cadastro de Livros          |\n");
   print("| 10. Voltar ao menu              |\n");
   print("*---------------------------------*\n");
 } elsif ($num==3) {
   print("*---------------------------------*\n");
   print("| 01. Consulta de Assuntos        |\n");
   print("| 02. Consulta de Autores         |\n");
   print("| 03. Consulta de Editoras        |\n");
   print("| 04. Consulta de Endereços       |\n");
   print("| 05. Consulta de Idiomas         |\n");
   print("| 06. Consulta de Países          |\n");
   print("| 07. Consulta de Profissões      |\n");
   print("| 08. Consulta de Clientes        |\n");
   print("| 09. Consulta de Livros          |\n");
   print("| 10. Voltar ao menu              |\n");
   print("*---------------------------------*\n");
 } elsif ($num==4) {
   print("*---------------------------------*\n");
   print("| 01. Vender Livros               |\n");
   print("| 02. Vendas Realizadas           |\n");
   print("| 03. Voltar ao menu              |\n");
   print("*---------------------------------*\n");
 } elsif ($num==5) {
   print("*---------------------------------*\n");
   print("| 01. Alterar senha               |\n");
   print("| 02. Sobre o sistema             |\n");
   print("| 03. Sair do sistema             |\n");
   print("| 04. Voltar ao menu              |\n");
   print("*---------------------------------*\n");
 } elsif ($num==6) {
   print("*--------------------------------------------------------------*\n");
   print("| (1) Novo  (2) Pesquisar   (3) Voltar ao menu                 |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==7) {
   print("*--------------------------------------------------------------*\n");
   print("| (1) Salvar inclusão       (2) Voltar ao menu                 |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==8) {
   print("*--------------------------------------------------------------*\n");
   print("| (1) Alterar       (2) Excluir     (3) Voltar ao menu         |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==9) {
   print("*--------------------------------------------------------------*\n");
   print("| (1) Salvar alteração      (2) Voltar ao menu                 |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==10) {
   print("*--------------------------------------------------------------*\n");
   print("| Certeza de excluir? (S/N)                                    |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==11) {
   print("*--------------------------------------------------------------*\n");
   print("| Deseja sair do sistema? (S/N)                                |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==12) {
   print("*--------------------------------------------------------------*\n");
   print("| (1) Pesquisar  (2) Listar todos   (3) Voltar ao menu         |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==13) {
   print("*--------------------------------------------------------------*\n");
   print("| Deseja continuar? (S/N)                                      |\n");
   print("*--------------------------------------------------------------*\n");
 } elsif ($num==14) {
   print("*--------------------------------------------------------------*\n");
   print("| Salvar inclusão (S/N)                                        |\n");
   print("*--------------------------------------------------------------*\n");
 }
 print($MSG_OPCAO);
}
#------------------------------------------------------------------------------
# Realiza os cadastros de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
sub frmCadastros { 
my $sreg = $_[0];
my $sacao = $_[1];
my $slinha;

if ($sreg==$opAssunto) {
   if ($sacao==$opNovo) {
      $tAssunto{"codigo"} = pesqMaxCod(tfAssunto, 1, 10, tamReg($sreg));
      mostrarDados($sreg, "", 1);
      subMenu(7, $sreg);
   } elsif ($sacao==$opPesquisar) {
     $slinha = validaEntrada(tfAssunto,$sreg,1,$tAssunto{"codigo"},1,$false,$opNumero);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opAutor) {
   if ($sacao==$opNovo) {
      $tAutor{"codigo"} = pesqMaxCod(tfAutor, 1, 10, tamReg($sreg));
      mostrarDados($sreg, "", 1);
      subMenu(7, $sreg);
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfAutor, $sreg, 1, $tAutor{"codigo"},1,$false,$opNumero);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opEditora) {
   if ($sacao==$opNovo) {
      $tEditora{"codigo"} = pesqMaxCod(tfEditora, 1, 10, tamReg($sreg));
      mostrarDados($sreg, "", 1);
      subMenu(7, $sreg);
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfEditora,$sreg,1,$tEditora{"codigo"},1,$false,$opNumero);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opEndereco) {
   if ($sacao==$opNovo) {
      $tEndereco{"codigo"} = pesqMaxCod(tfEndereco, 1, 10, tamReg($sreg));
      mostrarDados($sreg, "", 1);
      subMenu(7, $sreg);
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfEndereco,$sreg,1,$tEndereco{"codigo"},1,
              $false,$opNumero);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opIdioma) {
   if ($sacao==$opNovo) {
      $tIdioma{"codigo"} = pesqMaxCod(tfIdioma, 1, 10, tamReg($sreg));
      mostrarDados($sreg, "", 1);
      subMenu(7, $sreg);
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfIdioma,$sreg,1,$tIdioma{"codigo"},1,$false,$opNumero);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opPais) {
   if ($sacao==$opNovo) {
      print(rotulo($sreg, 1));
      $tPais{"codigo"} = digita();
      $slinha = pesqArq(tfPais, $tPais{"codigo"}, 1, 3, tamReg($sreg));
      if (length($slinha)==0) {
         pesqLinhaExcluida(tfPais, tamReg($sreg));
         mostrarDados($sreg, "", 1);
         subMenu(7, $sreg);
      } else { print(MSG_REGEXST); }
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfPais, $sreg, 1, $tPais{"codigo"}, 1, $false, $opTexto);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      print(rotulo($sreg, 1).$tPais{"codigo"}."\n");
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opProfissao) {
   if ($sacao==$opNovo) {
      $tProfissao{"codigo"} = pesqMaxCod(tfProfissao, 1, 10, tamReg($sreg));
      mostrarDados($sreg, "", 1);
      subMenu(7, $sreg);
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfProfissao,$sreg,1,$tProfissao{"codigo"},1,
              $false,$opNumero);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opLivro) {
   if ($sacao==$opNovo) {
      print(rotulo($sreg, 1));
      $tLivro{"isbn"} = digita();
      if (validaISBN($tLivro{"isbn"})) {
          $slinha = pesqArq(tfLivro, $tLivro{"isbn"}, 1, 13, tamReg($sreg));
          if (length($slinha)==0) {
             pesqLinhaExcluida(tfLivro, tamReg($sreg));
             mostrarDados($sreg, "", 1);
             subMenu(7, $sreg);
             frmCadLigados($opLivroAss, $opNovo, $tLivro{"isbn"});
             frmCadLigados($opLivroAut, $opNovo, $tLivro{"isbn"});
          } else { print(MSG_REGEXST); }
      } else { print(MSG_ISBNINV); }
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfLivro, $sreg, 1, $tLivro{"isbn"}, 1,$false,$opTexto);
      if (length($slinha) > 0) {
         mostrarDados($sreg, "", 2);
         mostrarDados($sreg, $slinha, 3);
         subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      print(rotulo($sreg, 1).$tLivro{"isbn"}."\n");
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
      frmCadLigados($opLivroAss, $opExcluir, $tLivro{"isbn"});
      print("Assuntos dos livros excluídos, inclua novos!\n");
      frmCadLigados($opLivroAss, $opNovo, $tLivro{"isbn"});
      frmCadLigados($opLivroAut, $opExcluir, $tLivro{"isbn"});
      print("Autores dos livros excluídos, inclua novos!\n");
      frmCadLigados($opLivroAut, $opNovo, $tLivro{"isbn"});
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
      print("Assuntos dos livros sendo excluídos!\n");
      frmCadLigados($opLivroAss, $opExcluir, $tLivro{"isbn"});
      print("Autores dos livros sendo excluídos!\n");
      frmCadLigados($opLivroAut, $opExcluir, $tLivro{"isbn"});
   }
} elsif ($sreg==$opCliente) {
   if ($sacao==$opNovo) {
      print(rotulo($sreg, 1));
      $tCliente{"cpf"} = digita();
      if (validaCPF($tCliente{"cpf"})) {
          $slinha = pesqArq(tfCliente, $tCliente{"cpf"}, 1, 14, tamReg($sreg));
          if (length($slinha)==0) {
             pesqLinhaExcluida(tfCliente, tamReg($sreg));
             mostrarDados($sreg, "", 1);
             subMenu(7, $sreg);
          } else { print(MSG_REGEXST); }
      } else { print(MSG_CPFINV); }
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfCliente, $sreg, 1, $tCliente{"cpf"},1,$false,$opTexto);
      if (length($slinha) > 0) {
         mostrarDados($sreg, "", 2);
         mostrarDados($sreg, $slinha, 3);
         subMenu(8, $sreg);
      }
   } elsif ($sacao==$opAlterar) {
      print(rotulo($sreg, 1).$tCliente{"cpf"}."\n");
      mostrarDados($sreg, "", 1);
      subMenu(9, $sreg);
   } elsif ($sacao==$opExcluir) {
      subMenu(10, $sreg);
   }
} elsif ($sreg==$opVenda) {
   if ($sacao==$opNovo) {
      $tVenda{"dthrvenda"} = retDataHora();
      print(rotulo($sreg, 1).$tVenda{"dthrvenda"}."\n");
      $slinha = pesqArq(tfVenda, $tVenda{"dthrvenda"}, 1, 19, tamReg($sreg));
      if (length($slinha)==0) {
         $slinha = validaEntrada(tfCliente,$opCliente,1,$tVenda{"cpf"},3,
                 $false,$opTexto);
         if (length($slinha) > 0) {
            $tVenda{"cpf"} = trim(copy($slinha,1,14));
            if (validaCPF($tVenda{"cpf"})) {
               print(" ".rotulo($opCliente, 2)); # Nome 
               print(copy($slinha, $g_nPosChave, $g_nTamChave)."\n");
               frmCadLigados($opVenda, $opNovo, $tVenda{"cpf"});
            } else { print(MSG_CPFINV); }
         }
      } else { print(MSG_REGEXST); }
   } elsif ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfVenda, $sreg, 1, $tVenda{"dthrvenda"},1,
              $false,$opDataHora);
      if (length($slinha) > 0) {
        mostrarDados($sreg, "", 2);
        mostrarDados($sreg, $slinha, 3);
        subMenu(8, $sreg);
      }
   }
}

}
#------------------------------------------------------------------------------
# Realiza as consultas de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
sub frmConsultas {
my $sreg = $_[0]; 
my $sacao = $_[1];
my $slinha = "";

if ($sreg==$opAssunto) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfAssunto,$sreg,2,$tAssunto{"assunto"},1,$true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfAssunto, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
          print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opAutor) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfAutor,$sreg, 2, $tAutor{"autor"}, 1, $true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfAutor, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opEditora) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfEditora,$sreg,2,$tEditora{"editora"},1,$true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfEditora, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opEndereco) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfEndereco,$sreg,2,$tEndereco{"logradouro"},1,
              $true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfEndereco, $sreg, "", 0, 0, tamReg($sreg),
         3, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opIdioma) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfIdioma, $sreg, 2, $tIdioma{"idioma"},1,$true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfIdioma, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      } 
   }
} elsif ($sreg==$opPais) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfPais, $sreg, 2, $tPais{"pais"}, 1, $true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfPais, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opProfissao) {
   if ($sacao==$opPesquisar) {
     $slinha = validaEntrada(tfProfissao,$sreg,2,$tProfissao{"profissao"},1,
             $true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfProfissao, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opLivro) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfLivro, $sreg, 2, $tLivro{"titulo"}, 1, $true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfLivro, $sreg, "", 0, 0, tamReg($sreg),
        1, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opCliente) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfCliente, $sreg, 2, $tCliente{"nome"},1,$true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfCliente, $sreg, "", 0, 0, tamReg($sreg),
        1, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
} elsif ($sreg==$opVenda) {
   if ($sacao==$opPesquisar) {
      $slinha = validaEntrada(tfVenda, $sreg, 2, $tVenda{"cpf"}, 1, $true,$opTexto);
   } elsif ($sacao==$opListarTodos) {
      if (ListarTodos(tfVenda, $sreg, "", 0, 0, tamReg($sreg),
        $QTD_MAX_LINHA, $false) == $false) {
        print(rotulo($sreg, 0)."\n");
      }
   }
}
if (length($slinha)==0) {
   print("");
}
}
#------------------------------------------------------------------------------
# Mostra a tela de alteração de senha do sistema e realiza a alteração.
#------------------------------------------------------------------------------
sub frmAlterarSenha {
my $sres; my $sSenhaAtual; my $sNovaSenha; my $sConfirmaSenha;

print(rotulo($opUsuario, 1).$tUsuario{"login"}."\n");
my $nopcao = 1;
my $bQuebra = $false;
while ($bQuebra==$false) {
  SWITCH: {
    if ($nopcao==1) {
       $sSenhaAtual = digitaSenha("Senha Atual: ", 10);
       if (strcmp($sSenhaAtual,$tUsuario{"senha"})==$false) {
          print($MSG_SENCONFERE);
          $bQuebra = $true;
       } else { $nopcao = 2; }
       last SWITCH;
    }
    if ($nopcao==2) {
       $sNovaSenha = digitaSenha("Nova Senha: ", 10);
       $sConfirmaSenha = digitaSenha("Confirma Senha: ", 10);
       if (strcmp($sNovaSenha,$sConfirmaSenha)==$false) {
          print($MSG_SENCONFIRM);
          $bQuebra = $true;
       } else { $nopcao = 3; }
       last SWITCH;
    }
    if ($nopcao==3) {
       $sres = pesqArq(tfUsuario, $tUsuario{"login"}, 1, 10, tamReg($opUsuario));
       if (length($sres)==0) {
         print($MSG_LOGINENCON);
       } else {
         $tUsuario{"senha"} = $sConfirmaSenha;
         subMenu(9,$opUsuario);
         $bQuebra = $true;
       }
       last SWITCH;
    }
  }
}
}
#------------------------------------------------------------------------------
# Executa uma ação de gravação de acordo com o tipo de arquivo.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
#------------------------------------------------------------------------------
sub btnAcao {
my $sreg = $_[0];
my $sacao = $_[1];

if ($sreg==$opAssunto) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfAssunto, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfAssunto, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfAssunto, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opAutor) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfAutor, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfAutor, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfAutor, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opEditora) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfEditora, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfEditora, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfEditora, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opEndereco) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfEndereco, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfEndereco, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfEndereco, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opIdioma) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfIdioma, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfIdioma, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfIdioma, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opPais) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfPais, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfPais, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfPais, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opProfissao) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfProfissao, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfProfissao, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
     escreveArq(tfProfissao, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opLivro) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfLivro, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfLivro, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfLivro, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opLivroAss) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfLivroAss, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfLivroAss, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfLivroAss, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opLivroAut) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfLivroAut, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfLivroAut, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfLivroAut, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opCliente) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfCliente, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfCliente, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfCliente, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opVenda) {
   if ($sacao==$opSalvarInclusao) {
      escreveArq(tfVenda, LinhaReg($sreg), $MSG_REGINC, $MSG_REGNINC);
   } elsif ($sacao==$opSalvarAlteracao) {
      escreveArq(tfVenda, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   } elsif ($sacao==$opConfirmaExclusao) {
      escreveArq(tfVenda, repete("*",tamReg($sreg)), $MSG_REGEXC, $MSG_REGNEXC);
   }
} elsif ($sreg==$opUsuario) {
   if ($sacao==$opSalvarAlteracao) {
      escreveArq(tfUsuario, LinhaReg($sreg), $MSG_REGALT, $MSG_REGNALT);
   }
}
}
#------------------------------------------------------------------------------
# Seleciona o menu e/ou a tela certa de acordo com o tipo de arquivo.
# nmenu - o número do menu
# sreg - o tipo de arquivo
#------------------------------------------------------------------------------
sub subMenu {
my $nmenu = $_[0];
my $sreg = $_[1];

my $opSubMenu;
my $opCSubMenu;
my $bSOp = $true;
SWITCH: {
  if ($nmenu == 6) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opSubMenu = digita();
      SWITCH : {
        if ($opSubMenu == 1) { frmCadastros($sreg, $opNovo); last SWITCH; }
        if ($opSubMenu == 2) { frmCadastros($sreg, $opPesquisar); last SWITCH; }
        if ($opSubMenu == 3) { $bSOp = $false; last SWITCH; }
	      print($MSG_ERRO);
      }
    }
    last SWITCH;
  }
  if ($nmenu == 7) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opSubMenu = digita();
      SWITCH : {
        if ($opSubMenu == 1) { 
          btnAcao($sreg, $opSalvarInclusao); $bSOp = $false; last SWITCH; }
        if ($opSubMenu == 2) { $bSOp = $false; last SWITCH; }
        print($MSG_ERRO);
      }
    }
    last SWITCH;
  }
  if ($nmenu == 8) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opSubMenu = digita();
      SWITCH : {
        if ($opSubMenu == 1) { 
          frmCadastros($sreg, $opAlterar); $bSOp = $false; last SWITCH; }
        if ($opSubMenu == 2) { 
          frmCadastros($sreg, $opExcluir); $bSOp = $false; last SWITCH; }
        if ($opSubMenu == 3) { $bSOp = $false; last SWITCH; }
        print($MSG_ERRO);
      }
    }
    last SWITCH;
  }
  if ($nmenu == 9) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opSubMenu = digita();
      SWITCH : {
        if ($opSubMenu == 1) { 
          btnAcao($sreg, $opSalvarAlteracao); $bSOp = $false; last SWITCH; }
        if ($opSubMenu == 2) { $bSOp = $false; last SWITCH; }
        print($MSG_ERRO);
      }
    }
    last SWITCH;
  }
  if ($nmenu == 10) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opCSubMenu = digita();
      if (($opCSubMenu=~'S') || ($opCSubMenu=~'s')) {
        btnAcao($sreg, $opConfirmaExclusao);
        $bSOp = $false;
      } elsif (($opCSubMenu=~'N') || ($opCSubMenu=~'n')) { 
        $bSOp = $false;
      } else { 
        print($MSG_ERRO); 
      }
    }
    last SWITCH;
  }
  if ($nmenu == 12) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opSubMenu = digita();
      SWITCH : {
        if ($opSubMenu == 1) { frmConsultas($sreg, $opPesquisar); last SWITCH; }
        if ($opSubMenu == 2) { frmConsultas($sreg, $opListarTodos); last SWITCH; }
        if ($opSubMenu == 3) { $bSOp = $false; last SWITCH; }
        print($MSG_ERRO);
      }
    }
    last SWITCH;
  }
  if ($nmenu == 14) {
    while ($bSOp == $true) {
      menu($nmenu);
      $opCSubMenu = digita();
      if (($opCSubMenu=~'S') || ($opCSubMenu=~'s')) {
        btnAcao($sreg, $opSalvarInclusao);
        $bSOp = $false;
        $g_SalvarInclusao = $true;
      } elsif (($opCSubMenu=~'N') || ($opCSubMenu=~'n')) { 
        $bSOp = $false;
      } else {
        print($MSG_ERRO);
      } 
    }
    last SWITCH;
  }
}

}
#------------------------------------------------------------------------------
# Seleciona o submenu e/ou a tela certa de acordo com número do menu.
# nmenu - o número do menu
#------------------------------------------------------------------------------
sub usaMenu { 
my $num = shift();

my $opSubMenu;
my $opSair;
my $bSOp = $true;
 if ($num == 1) { # Cadastros
   while ($bSOp == $true) {
     menu(2);
     $opSubMenu = digita();
     SWITCH: {
       if ($opSubMenu==1) { subMenu(6, $opAssunto); last SWITCH; }
       if ($opSubMenu==2) { subMenu(6, $opAutor); last SWITCH; }
       if ($opSubMenu==3) { subMenu(6, $opEditora); last SWITCH; }
       if ($opSubMenu==4) { subMenu(6, $opEndereco); last SWITCH; }
       if ($opSubMenu==5) { subMenu(6, $opIdioma); last SWITCH; }
       if ($opSubMenu==6) { subMenu(6, $opPais); last SWITCH; }
       if ($opSubMenu==7) { subMenu(6, $opProfissao); last SWITCH; }
       if ($opSubMenu==8) { subMenu(6, $opCliente); last SWITCH; }
       if ($opSubMenu==9) { subMenu(6, $opLivro); last SWITCH; }
       if ($opSubMenu==10) { $bSOp = $false; last SWITCH; }
       print($MSG_ERRO);
     }
   }
 } elsif ($num == 2) { # Pesquisas
   while ($bSOp == $true) {
     menu(3);
     $opSubMenu = digita();
     SWITCH: {
       if ($opSubMenu==1) { subMenu(12, $opAssunto); last SWITCH; }
       if ($opSubMenu==2) { subMenu(12, $opAutor); last SWITCH; }
       if ($opSubMenu==3) { subMenu(12, $opEditora); last SWITCH; }
       if ($opSubMenu==4) { subMenu(12, $opEndereco); last SWITCH; }
       if ($opSubMenu==5) { subMenu(12, $opIdioma); last SWITCH; }
       if ($opSubMenu==6) { subMenu(12, $opPais); last SWITCH; }
       if ($opSubMenu==7) { subMenu(12, $opProfissao); last SWITCH; }
       if ($opSubMenu==8) { subMenu(12, $opCliente); last SWITCH; }
       if ($opSubMenu==9) { subMenu(12, $opLivro); last SWITCH; }
       if ($opSubMenu==10) { $bSOp = $false; last SWITCH; }
       print($MSG_ERRO);
     }
   }
 } elsif ($num == 3) { # Vendas
   while ($bSOp == $true) {
     menu(4);
     $opSubMenu = digita();
     SWITCH: {
       if ($opSubMenu==1) { subMenu(6, $opVenda); last SWITCH; }
       if ($opSubMenu==2) { subMenu(12, $opVenda); last SWITCH; }
       if ($opSubMenu==3) { $bSOp = $false; last SWITCH; }
       print($MSG_ERRO);
     }
   }
 } elsif ($num == 4) { # Opcoes
   while ($bSOp == $true) {
     menu(5);
     $opSubMenu = digita();
     SWITCH: {
       if ($opSubMenu==1) { frmAlterarSenha(); last SWITCH; }
       if ($opSubMenu==2) { frmSobre(); last SWITCH; }
       if ($opSubMenu==3) { 
         menu(11);
         $opSair = digita();
         if (($opSair=~'S') || ($opSair=~'s')) {
            fechaArqs();
            exit(0);
         }
         last SWITCH;
       }
       if ($opSubMenu==4) { $bSOp = $false; last SWITCH; }
       print($MSG_ERRO);
     }
   }
 }
}
#------------------------------------------------------------------------------
# Mostra as entradas e as saídas do sistema.
# sreg - o tipo de arquivo
# slinha - o registro com os dados
# nOpcao - indica qual opção será mostrada
#------------------------------------------------------------------------------
sub mostrarDados {
my $sreg = $_[0];
my $slinha = $_[1];
my $nOpcao = $_[2];
 
if ($sreg==$opAssunto) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 1).$tAssunto{"codigo"}."\n");
        print(rotulo($sreg, 2));
        $tAssunto{"assunto"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==2) {
        print("Código     Assunto\n");
        print("------     -------\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tAssunto{"codigo"} = trim(copy($slinha, 1, 10));
        $tAssunto{"assunto"} = trim(copy($slinha, 11, 30));
        print(esp($tAssunto{"codigo"},10)." ".esp($tAssunto{"assunto"},30)."\n");
        last SWITCH; 
    }
  }
} elsif ($sreg==$opAutor) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 1).$tAutor{"codigo"}."\n");
        print(rotulo($sreg, 2));
        $tAutor{"autor"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==2) {
        print("Código     Autor\n");
        print("------     -----\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tAutor{"codigo"} = trim(copy($slinha, 1, 10));
        $tAutor{"autor"} = trim(copy($slinha, 11, 30));
        print(esp($tAutor{"codigo"},10)." ".esp($tAutor{"autor"},30)."\n");
        last SWITCH; 
    }
  }
} elsif ($sreg==$opEditora) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 1).$tEditora{"codigo"}."\n");
        print(rotulo($sreg, 2));
        $tEditora{"editora"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==2) {
        print("Código     Editora\n");
        print("------     -------\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tEditora{"codigo"} = trim(copy($slinha, 1, 10));
        $tEditora{"editora"} = trim(copy($slinha, 11, 50));
        print(esp($tEditora{"codigo"},10)." ".esp($tEditora{"editora"},50)."\n");
        last SWITCH;  
    }
  }
} elsif ($sreg==$opEndereco) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 1).$tEndereco{"codigo"}."\n");
        print(rotulo($sreg, 2));
        $tEndereco{"logradouro"} = digita();
        print(rotulo($sreg, 3));
        $tEndereco{"bairro"} = digita();
        print(rotulo($sreg, 4));
        $tEndereco{"cep"} = digita();
        print(rotulo($sreg, 5));
        $tEndereco{"cidade"} = digita();
        print(rotulo($sreg, 6));
        $tEndereco{"estado"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tEndereco{"codigo"} = trim(copy($slinha, 1, 10));
        $tEndereco{"logradouro"} = trim(copy($slinha, 11, 40));
        $tEndereco{"bairro"} = trim(copy($slinha, 51, 15));
        $tEndereco{"cep"} = trim(copy($slinha, 66, 8));
        $tEndereco{"cidade"} = trim(copy($slinha, 74, 30));
        $tEndereco{"estado"} = trim(copy($slinha, 104, 20));
        print("--------------------\n");
        print(rotulo($sreg, 1).$tEndereco{"codigo"}."\n");
        print(rotulo($sreg, 2).$tEndereco{"logradouro"}."\n");
        print(rotulo($sreg, 3).$tEndereco{"bairro"}."\n");
        print(rotulo($sreg, 4).$tEndereco{"cep"}."\n");
        print(rotulo($sreg, 5).$tEndereco{"cidade"}."\n");
        print(rotulo($sreg, 6).$tEndereco{"estado"}."\n");
        last SWITCH; 
    }
  }
} elsif ($sreg==$opIdioma) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 1).$tIdioma{"codigo"}."\n");
        print(rotulo($sreg, 2));
        $tIdioma{"idioma"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==2) {
        print("Código     Idioma\n");
        print("------     ------\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tIdioma{"codigo"} = trim(copy($slinha, 1, 10));
        $tIdioma{"idioma"} = trim(copy($slinha, 11, 20));
        print(esp($tIdioma{"codigo"},10)." ".esp($tIdioma{"idioma"},20)."\n");
        last SWITCH; 
    }
  }
} elsif ($sreg==$opPais) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 2));
        $tPais{"pais"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==2) {
        print("Código País\n");
        print("------ ----\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tPais{"codigo"} = trim(copy($slinha, 1, 3));
        $tPais{"pais"} = trim(copy($slinha, 4, 50));
        print(esp($tPais{"codigo"},3)."    ".esp($tPais{"pais"},50)."\n");
        last SWITCH; 
    }
  }
} elsif ($sreg==$opProfissao) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 1).$tProfissao{"codigo"}."\n");
        print(rotulo($sreg, 2));
        $tProfissao{"profissao"} = digita();
        last SWITCH; 
    }
    if ($nOpcao==2) {
        print("Código     Profissão\n");
        print("------     ---------\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tProfissao{"codigo"} = trim(copy($slinha, 1, 10));
        $tProfissao{"profissao"} = trim(copy($slinha, 11, 50));
        print(esp($tProfissao{"codigo"},10)." ".
                esp($tProfissao{"profissao"},50)."\n");
        last SWITCH; 
    }
  }
} elsif ($sreg==$opLivro) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 2));
        $tLivro{"titulo"} = digita();
        $tLivro{"edicao"} = validaNumero(rotulo($sreg, 3), $tLivro{"edicao"});
        $tLivro{"anopubli"} = validaNumero(rotulo($sreg, 4), $tLivro{"anopubli"});
        mostrarSubDados($opLivro, $opEditora, $false);
        $tLivro{"volume"} = validaNumero(rotulo($sreg, 6), $tLivro{"volume"});
        mostrarSubDados($opLivro, $opIdioma, $false);
        $tLivro{"npaginas"} = validaNumero(rotulo($sreg, 8), $tLivro{"npaginas"});
        $tLivro{"preco"} = validaNumero(rotulo($sreg, 9), $tLivro{"preco"});
        $tLivro{"qtdestoque"} = validaNumero(rotulo($sreg, 10), 
            $tLivro{"qtdestoque"});
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tLivro{"isbn"} = trim(copy($slinha, 1, 13));
        $tLivro{"titulo"} = trim(copy($slinha, 14, 50));
        $tLivro{"edicao"} = trim(copy($slinha, 64, 10));
        $tLivro{"anopubli"} = trim(copy($slinha, 74, 10));
        $tLivro{"codeditora"} = trim(copy($slinha, 84, 10));
        $tLivro{"volume"} = trim(copy($slinha, 94, 10));
        $tLivro{"codidioma"} = trim(copy($slinha, 104, 10));
        $tLivro{"npaginas"} = trim(copy($slinha, 114, 10));
        $tLivro{"preco"} = trim(copy($slinha, 124, 10));
        $tLivro{"qtdestoque"} = trim(copy($slinha, 134, 10));
        print("--------------------\n");
        print(rotulo($sreg, 1).$tLivro{"isbn"}."\n");
        print(rotulo($sreg, 2).$tLivro{"titulo"}."\n");
        print(rotulo($sreg, 3).$tLivro{"edicao"}."\n");
        print(rotulo($sreg, 4).$tLivro{"anopubli"}."\n");
        print(rotulo($sreg, 5).$tLivro{"codeditora"}."\n");
        mostrarSubDados($opLivro, $opEditora, $true);
        print(rotulo($sreg, 6).$tLivro{"volume"}."\n");
        print(rotulo($sreg, 7).$tLivro{"codidioma"}."\n");
        mostrarSubDados($opLivro, $opIdioma, $true);
        print(rotulo($sreg, 8).$tLivro{"npaginas"}."\n");
        print(rotulo($sreg, 9).$tLivro{"preco"}."\n");
        print(rotulo($sreg, 10).$tLivro{"qtdestoque"}."\n");
        ListarRegLigados(tfLivroAss, $opLivroAss, 1, 13, 14, 10, $tLivro{"isbn"},
                         tfAssunto, $opAssunto, 1, 4);
        ListarRegLigados(tfLivroAut, $opLivroAut, 1, 13, 14, 10, $tLivro{"isbn"},
                         tfAutor, $opAutor, 1, 4);
        last SWITCH; 
    }
  }
} elsif ($sreg==$opCliente) {
  SWITCH: {
    if ($nOpcao==1) {
        print(rotulo($sreg, 2));
        $tCliente{"nome"} = digita();
        print(rotulo($sreg, 3));
        $tCliente{"email"} = digita();
        print(rotulo($sreg, 4));
        $tCliente{"identidade"} = digita();
        print(rotulo($sreg, 5));
        $tCliente{"sexo"} = digita();
        print(rotulo($sreg, 6));
        $tCliente{"telefone"} = digita();
        $tCliente{"dtnascimento"} = 
            validaDataHora(rotulo($sreg, 7), $tCliente{"dtnascimento"}, $true);
        mostrarSubDados($opCliente, $opEndereco, $false);
        mostrarSubDados($opCliente, $opPais, $false);
        mostrarSubDados($opCliente, $opProfissao, $false);
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tCliente{"cpf"} = trim(copy($slinha, 1, 14));
        $tCliente{"nome"} = trim(copy($slinha, 15, 30));
        $tCliente{"email"} = trim(copy($slinha, 45, 30));
        $tCliente{"identidade"} = trim(copy($slinha, 75, 10));
        $tCliente{"sexo"} = trim(copy($slinha, 85, 1));
        $tCliente{"telefone"} = trim(copy($slinha, 86, 17));
        $tCliente{"dtnascimento"} = trim(copy($slinha, 103, 10));
        $tCliente{"codendereco"} = trim(copy($slinha, 113, 10));
        $tCliente{"codpais"} = trim(copy($slinha, 123, 3));
        $tCliente{"codprofissao"} = trim(copy($slinha, 126, 10));
        print("--------------------\n");
        print(rotulo($sreg, 1).$tCliente{"cpf"}."\n");
        print(rotulo($sreg, 2).$tCliente{"nome"}."\n");
        print(rotulo($sreg, 3).$tCliente{"email"}."\n");
        print(rotulo($sreg, 4).$tCliente{"identidade"}."\n");
        print(rotulo($sreg, 5).$tCliente{"sexo"}."\n");
        print(rotulo($sreg, 6).$tCliente{"telefone"}."\n");
        print(rotulo($sreg, 7).$tCliente{"dtnascimento"}."\n");
        print(rotulo($sreg, 8).$tCliente{"codendereco"}."\n");
        mostrarSubDados($opCliente, $opEndereco, $true);
        print(rotulo($sreg, 9).$tCliente{"codpais"}."\n");
        mostrarSubDados($opCliente, $opPais, $true);
        print(rotulo($sreg, 10).$tCliente{"codprofissao"}."\n");
        mostrarSubDados($opCliente, $opProfissao, $true);
        last SWITCH; 
    }
   }
} elsif ($sreg==$opVenda) {
  SWITCH: {
    if ($nOpcao==1) {
      mostrarSubDados($opVenda,$opVenda, $false);
      last SWITCH; 
    }
    if ($nOpcao==2) {
        print("DataHoraVenda       CPF            ISBN          ".
        "PreçoVenda\n");
        print("-------------       ---            ----          ".
        "----------\n");
        last SWITCH; 
    }
    if ($nOpcao==3) {
        $tVenda{"dthrvenda"} = trim(copy($slinha, 1, 19));
        $tVenda{"cpf"} = trim(copy($slinha, 20, 14));
        $tVenda{"isbn"} = trim(copy($slinha, 34, 13));
        $tVenda{"precovenda"} = trim(copy($slinha, 47, 10));
        print(esp($tVenda{"dthrvenda"},19)." ".esp($tVenda{"cpf"},14)." ".
        esp($tVenda{"isbn"},13)." ".esp($tVenda{"precovenda"},10)."\n");
        last SWITCH; 
    }
  }
}

}
#------------------------------------------------------------------------------
# Mostra as sub informções de entrada e de saída.
# sreg - o tipo de arquivo
# ssubreg - o subtipo de arquivo
# bSoMostrar - se vai só mostrar na saída
#------------------------------------------------------------------------------
sub mostrarSubDados { 
my $sreg = $_[0];
my $ssubreg = $_[1];
my $bSoMostrar = $_[2];

my $sRegistro; my $sPreco;
my $nMaxTentativas = 3;
if ($sreg==$opLivro) {
  if ($ssubreg==$opEditora) {
    if ($bSoMostrar==$true) {
       $sRegistro = pesqArq(tfEditora,$tLivro{"codeditora"},1,10,tamReg($opEditora));
    } else {
       $sRegistro = validaEntrada(tfEditora,$ssubreg,1,$tLivro{"codeditora"},
                  $nMaxTentativas,$false,$opNumero);
    }
    if (length($sRegistro) > 0) {
      $tLivro{"codeditora"} = trim(copy($sRegistro,1,10));
      print(" ".rotulo($opEditora, 2));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
    }
  } elsif ($ssubreg==$opIdioma) {
    if ($bSoMostrar==$true) {
       $sRegistro = pesqArq(tfIdioma, $tLivro{"codidioma"}, 1, 10,tamReg($opIdioma));
    } else {
       $sRegistro = validaEntrada(tfIdioma,$ssubreg,1,$tLivro{"codidioma"},
                  $nMaxTentativas,$false,$opNumero);
    }
    if (length($sRegistro) > 0) {
      $tLivro{"codidioma"} = trim(copy($sRegistro,1,10));
      print(" ".rotulo($opIdioma, 2));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
    }
  }
} elsif ($sreg==$opCliente) {
  if ($ssubreg==$opEndereco) {
    if ($bSoMostrar==$true) {
       $sRegistro = pesqArq(tfEndereco, $tCliente{"codendereco"}, 1, 10,
                  tamReg($opEndereco));
    } else {
       $sRegistro = validaEntrada(tfEndereco,$ssubreg,1,$tCliente{"codendereco"},
                  $nMaxTentativas,$false,$opNumero);
    }
    if (length($sRegistro) > 0) {
      $tCliente{"codendereco"} = trim(copy($sRegistro,1,10));
      print(" ".rotulo($opEndereco, 2));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
      print(" ".rotulo($opEndereco, 3));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
      print(" ".rotulo($opEndereco, 4));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
      print(" ".rotulo($opEndereco, 5));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
      print(" ".rotulo($opEndereco, 6));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
    }
  } elsif ($ssubreg==$opPais) {
    if ($bSoMostrar==$true) {
       $sRegistro = pesqArq(tfPais, $tCliente{"codpais"}, 1, 3, tamReg($opPais));
    } else {
       $sRegistro = validaEntrada(tfPais,$ssubreg,1,$tCliente{"codpais"},
                  $nMaxTentativas,$false,$opTexto);
    }
    if (length($sRegistro) > 0) {
      $tCliente{"codpais"} = trim(copy($sRegistro,1,3));
      print(" ".rotulo($opPais, 2));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
    }
  } elsif ($ssubreg==$opProfissao) {
    if ($bSoMostrar==$true) {
       $sRegistro = pesqArq(tfProfissao, $tCliente{"codprofissao"}, 1, 10,
                  tamReg($opProfissao));
    } else {
       $sRegistro = validaEntrada(tfProfissao,$ssubreg,1,$tCliente{"codprofissao"},
                  $nMaxTentativas,$false,$opNumero);
    }
    if (length($sRegistro) > 0) {
      $tCliente{"codprofissao"} = trim(copy($sRegistro,1,10));
      print(" ".rotulo($opProfissao, 2));
      print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
    }
  }
} elsif ($sreg==$opVenda) {
  $sRegistro = pesqArq(tfLivro, $tVenda{"isbn"}, 1, 13, tamReg($opLivro));
  if (length($sRegistro) > 0) {
    print(" ".rotulo($opLivro, 2)); # Titulo
    print(copy($sRegistro, $g_nPosChave, $g_nTamChave)."\n");
    print(" ".rotulo($opLivro, 9)); # Preco
    $sPreco = copy($sRegistro, $g_nPosChave, $g_nTamChave);
    $g_nPreco = $sPreco;
    print($sPreco."\n");
  }
}
}
#------------------------------------------------------------------------------
# Realiza os cadastros dos arquivos que se ligam a outros arquivos.
# sreg - o tipo de arquivo
# sacao - a ação a ser realizada
# sCodigo - um das chaves do arquivo de ligação
#------------------------------------------------------------------------------
sub frmCadLigados { 
my $sreg = $_[0]; 
my $sacao = $_[1]; 
my $sCodigo = $_[2];

my $nQtd; my $nCont; my $nQtdEstoque;
my $nTotalPreco;
my $slinha; my $sTotalPreco; my $sPreco;
my $sQtd;

if ($sacao==$opNovo) {
  $nCont = 1;
  if ($sreg==$opLivroAss) {
    $sQtd = validaNumero("Quantos assuntos quer cadastrar?: ",$sQtd);
    $nQtd = $sQtd;
    seek(tfLivroAss, 0, $SEEK_SET);
    while ($nCont <= $nQtd) {
      $tLivroAss{"isbn"} = $sCodigo;
      print(rotulo($opLivroAss, 2));
      $tLivroAss{"codassunto"} = digita();
      $slinha = pesqArq(tfAssunto, $tLivroAss{"codassunto"},1,10,tamReg($opAssunto));
      print(" ".rotulo($opAssunto, 2));
      print(copy($slinha, $g_nPosChave, $g_nTamChave)."\n");
      pesqLinhaExcluida(tfLivroAss, tamReg($sreg));
      subMenu(14, $sreg);
      $nCont++;
    }
  } elsif ($sreg==$opLivroAut) {
    $sQtd = validaNumero("Quantos autores quer cadastrar?: ",$sQtd);
    $nQtd = $sQtd;
    seek(tfLivroAut, 0, $SEEK_SET);
    while ($nCont <= $nQtd) {
      $tLivroAut{"isbn"} = $sCodigo;
      print(rotulo($opLivroAut, 2));
      $tLivroAut{"codautor"} = digita();
      $slinha = pesqArq(tfAutor, $tLivroAut{"codautor"},1,10,tamReg($opAutor));
      print(" ".rotulo($opAutor, 2));
      print(copy($slinha, $g_nPosChave, $g_nTamChave)."\n");
      pesqLinhaExcluida(tfLivroAut, tamReg($sreg));
      subMenu(14, $sreg);
      $nCont++;
    }
  } elsif ($sreg==$opVenda) {
    $sPreco = "";
    $sTotalPreco = "";
    $sQtd = validaNumero("Quantos livros quer vender?: ",$sQtd);
    $nQtd = $sQtd;
    $nTotalPreco = 0;
    while ($nCont <= $nQtd) {
      $slinha = validaEntrada(tfLivro,$opLivro,1,$tVenda{"isbn"},3,$false,$opTexto);
      if (length($slinha) > 0) {
        $tVenda{"isbn"} = trim(copy($slinha,1,13));
        if (validaISBN($tVenda{"isbn"})) {
          mostrarDados($sreg, "", 1);
          $tLivro{"qtdestoque"} = trim(copy($slinha,134,10));
          $nQtdEstoque = $tLivro{"qtdestoque"};
          if ($nQtdEstoque > 0) {
             $nTotalPreco = $nTotalPreco + $g_nPreco;
             $sPreco = $g_nPreco;
             $tVenda{"precovenda"} = $sPreco;
             $g_SalvarInclusao = $false;
             subMenu(14, $sreg);
             if ($g_SalvarInclusao==$true) {
                $slinha = pesqArq(tfLivro, $tVenda{"isbn"}, 1, 13, tamReg($opLivro));
                if (length($slinha) > 0) {
                   $nQtdEstoque = $nQtdEstoque-1;
                   $tLivro{"qtdestoque"} = $nQtdEstoque;
                   $slinha=copy($slinha,1,133).esp($tLivro{"qtdestoque"},10);
                   escreveArq(tfLivro, $slinha, "", "");
                }
             }
             $nCont++;
          } else { print(MSG_SEMESTOQUE); }
        } else { print(MSG_ISBNINV); }
      }
    }
    $nTotalPreco = $sTotalPreco;
    print("Total de ".rotulo($sreg,4).$nTotalPreco."\n");
  }
} elsif ($sacao==$opExcluir) {
  if ($sreg==$opLivroAss) {
     ExcluirRegLigados(tfLivroAss, $sreg, 1, 13, $sCodigo);
  } elsif ($sreg==$opLivroAut) {
     ExcluirRegLigados(tfLivroAut, $sreg, 1, 13, $sCodigo);
  }
}

}
#------------------------------------------------------------------------------
# Realiza a exclusão dos arquivos de ligação.
# sArq - o arquivo de ligação
# sreg - o tipo de arquivo de ligação
# nPosChave - a posicao inicial da chave dentro do registro
# nTamChave - o tamanho da chave dentro do registro
# sChave - a chave a ser excluida
#------------------------------------------------------------------------------
sub ExcluirRegLigados {
my $sArq = $_[0];
my $sreg = $_[1];
my $nPosChave = $_[2];
my $nTamChave = $_[3];
my $sChave = $_[4];

my $slinha; my $sCodigo;

  seek($sArq, 0, $SEEK_SET);
  while (!eof($sArq)) {
    $slinha = <$sArq>;
    $sCodigo = trim(copy($slinha,$nPosChave,$nTamChave));
    if (strcmp($sCodigo,$sChave)==$true) {
       btnAcao($sreg,$opConfirmaExclusao);
    } 
  }
}
#------------------------------------------------------------------------------
# Parte inicial do código
#------------------------------------------------------------------------------
sub main {
 if (($#ARGV == 0) && (strcmp($ARGV[0],"-cria")==$true)) {
   abrecriaArqs($false);
 } else {
   frmSplash();
   abrecriaArqs($true);
   if (frmLogin()==$true) {
     $bopcao = $true;
     while ($bopcao==$true) {
       menu(1);
       $opmenu = digita();
       if (($opmenu=~'C') || ($opmenu=~'c')) { usaMenu(1); }
       elsif (($opmenu=~'P') || ($opmenu=~'p')) { usaMenu(2); }
       elsif (($opmenu=~'V') || ($opmenu=~'v')) { usaMenu(3); }
       elsif (($opmenu=~'O') || ($opmenu=~'o')) { usaMenu(4); }
       else { print($MSG_ERRO); }
     }
   } else {
     fechaArqs();
     exit(0);
   }
 }
 exit(0);
}

main();
