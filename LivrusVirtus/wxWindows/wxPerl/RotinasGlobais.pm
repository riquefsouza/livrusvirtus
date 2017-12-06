use Wx 0.15 qw[:allclasses];
use strict;
package RotinasGlobais;

use Wx qw[:everything];
use POSIX qw(strftime);
use DBI qw(:sql_types);
use DBD::ODBC;

require resource;
require ListaStr;

our $Rotinas = undef;

my %atribs = ( gConexao => undef, sBarraLogin => "", sUsuarioLogin => "", 
  sUsuarioSenha => "", sCodigoSelecionado => "", sPreco => "",  
  sQtdEstoque => "" );

our $sepDTHR = "#"; #SOMENTE ACCESS
#our $sepDTHR = "'"; #OUTROS BANCOS

sub new {
  my $self = shift;

	return $self;
}

sub atrib {
  my( $self, $atributo ) = @_;
  return $atribs{$atributo};
}

sub set_atrib {
  my( $self, $atributo, $valor ) = @_;
  $atribs{$atributo} = $valor;
}

sub ValidaFloat {
  my( $self, $sNum ) = @_;
  my $bret = $Resource::true;
  my $ncont = 0;

  if (length($sNum) > 0) {
    for($ncont = 0; $ncont < length($sNum); $ncont++) {      
      if ( index('0123456789.',substr($sNum, $ncont, 1)) == -1) {
        $bret = $Resource::false;
      }
    }
    if ( $bret ) {
      if ($sNum > 0.01) {
        $bret = $Resource::true;
      } else {
        Wx::MessageBox($Resource::STR_NUMINV, 'Erro', wxOK | wxICON_ERROR);
        $bret = $Resource::false;
      }
    } else {
      Wx::MessageBox($Resource::STR_NUMINV, 'Erro', wxOK | wxICON_ERROR);
      $bret = $Resource::false;
    }
  }
  return $bret;
}

sub VirgulaParaPonto {
  my( $self, $sNum, $bRevertido ) = @_;
  
  if ($bRevertido) {
    $sNum =~ s/\./,/g;
    return $sNum;
  } else {
    $sNum =~ s/\,/./g;
    return $sNum;
  }
}

sub modulo11 {
 my( $self, $svalor, $ndig ) = @_;

my $ncont; my $nsoma; my $nvalor; my $npos;
my $sres; my $slocal;

 $ncont=0;
 $slocal="";
 while ($ncont < 11) {
   $slocal=substr($svalor,$ncont,1).$slocal;
   $ncont++;
 }
 $nsoma=0;
 if ($ndig == 1) {
   $ncont=2;
 } else {
   $ncont=1;
 }
 $npos=2;
 while ($ncont < 11) {
   $sres = substr($slocal,$ncont,1);
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

sub validaCPF {
my( $self, $cpf ) = @_;

my $scpf; my $sres;
my $nvalor1; my $nvalor2;

if (length($cpf)==14) {
  $scpf = substr($cpf,0,3).substr($cpf,4,3).substr($cpf,8,3).substr($cpf,12,2);
  $sres = substr($cpf,12,1);
  $nvalor1 = $sres;
  $sres = substr($cpf,13,1);
  $nvalor2 = $sres;
  if (($self->modulo11($scpf,1)==$nvalor1) && 
      ($self->modulo11($scpf,2)==$nvalor2)) {
    return $Resource::true;
  } else {
    return $Resource::false;
  }
} else {
    return $Resource::false;
  }
}

sub validaISBN {
my( $self, $isbn ) = @_;

my $sisbn; my $sdigito; my $snum;
my $nvalor; my $nsoma; my $ncont;

if (length($isbn)==13) {
  $sdigito = substr($isbn, length($isbn)-1, 1);
  $sisbn="";
  for($ncont = 0; $ncont < length($isbn)-1; $ncont++)  {
    if (substr($isbn,$ncont,1) !~ '-') {
      $sisbn = $sisbn . substr($isbn,$ncont,1);
    }
  }  
  if ($sdigito =~ 'X') {
    $nsoma = 10;
  } else {
    $nvalor = $sdigito;
    $nsoma = $nvalor;
  }
  for($ncont = 1; $ncont <= 9; $ncont++)  {
    $snum = substr($sisbn, $ncont-1, 1);
    $nvalor = $snum;
    $nsoma = $nsoma + ($nvalor * (11 - $ncont));
  }
  if (($nsoma % 11) == 0) {
    return $Resource::true;
  } else {
    return $Resource::false;
  }
} else {
  return $Resource::false;
 }
}

sub validaDataHora {
my( $self, $sDataHora, $bSoData ) = @_;

my( $sdia, $smes, $sano, $shora, $smin, $sseg);
my( $ndia, $nmes, $nano, $nhora, $nmin, $nseg);
my $ntam;

my $bvalida = $Resource::false;
my $bdatavalida = $Resource::false;
my $bhoravalida = $Resource::false;
my $nudiames = 0;
if ($bSoData==$Resource::true) { 
  $ntam=10; 
} else { 
  $ntam=19;
}
if (length($sDataHora)==$ntam) {
  $sdia = substr($sDataHora,0,2);
  $ndia = $sdia;
  $smes = substr($sDataHora,3,2);
  $nmes = $smes;
  $sano = substr($sDataHora,6,4);
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
           $bdatavalida = $Resource::true;
        }
    }
  }

  if ($bSoData==$Resource::true) {
     if ($bdatavalida==$Resource::true) {
         $bvalida = $Resource::true;
     } else {
		   $bvalida = $Resource::false;
     }
  } else {
    if ($bdatavalida==$Resource::true) {
        $shora = substr($sDataHora,11,2);
        $nhora = $shora;
        $smin = substr($sDataHora,14,2);
        $nmin = $smin;
        $sseg = substr($sDataHora,17,2);
        $nseg = $sseg;

        if (($nhora >= 0) && ($nhora <= 23)) {
          if (($nmin >= 0) && ($nmin <= 59)) {
            if (($nseg >= 0) && ($nseg <= 59)) {
               $bhoravalida = $Resource::true;
            } 
          }
        }

        if ($bhoravalida==$Resource::true) {
		      $bvalida = $Resource::true;
        } else {
  		   $bvalida = $Resource::false;
        }
    } else {
	   $bvalida = $Resource::false;
    }
  }
} else {
  $bvalida = $Resource::false;
}
return $bvalida;
}

sub retDataHoraStr { 
my( $self, $bData, $bHora ) = @_;
my $sDataHora = '';

  if ($bData && $bHora) {
    $sDataHora = strftime "%d/%m/%Y %H:%M:%S", localtime;
  } elsif ($bData) {
    $sDataHora = strftime "%d/%m/%Y", localtime;
  } elsif ($bHora) {
    $sDataHora = strftime "%H:%M:%S", localtime;
  }
  return $sDataHora;
}

sub ConverteDataHoraStr {
my ($self, $sDTHR, $bDMY_ou_YMD, $sFrmtData, $sFrmtHora) = @_;
my $sDataHora = '';
my @sTempo;
my ($ndia,$nmes,$nano,$nhora,$nmin,$nseg) = 0;

if (length($sFrmtData) > 0) {
  if ($bDMY_ou_YMD) {
    $ndia = substr($sDTHR, 0, 2);
    $nmes = substr($sDTHR, 3, 2);
    $nano = substr($sDTHR, 6, 4);
  } else {
    $nano = substr($sDTHR, 0, 4);
    $nmes = substr($sDTHR, 5, 2);
    $ndia = substr($sDTHR, 8, 2);
  }
  $nhora = 0; $nmin = 0; $nseg = 0;
}
if (length($sFrmtHora) > 0) {
  $nhora = substr($sDTHR, 11, 2);
  $nmin = substr($sDTHR, 14, 2);
  $nseg = substr($sDTHR, 17, 2);
}
@sTempo = ($nseg,$nmin,$nhora,$ndia,$nmes-1,$nano-1900,0,0,0);
if (length($sFrmtHora) > 0) {
  $sDataHora = strftime $sFrmtData.' '.$sFrmtHora, @sTempo;
} else {
  $sDataHora = strftime $sFrmtData.' 00:00:00', @sTempo;
}
return $sDataHora;
}

sub ConectaBanco {
my ($self, $sBancoDeDados, $sLogin, $sSenha) = @_;

  $atribs{'gConexao'} = DBI->connect( $sBancoDeDados, $sLogin, $sSenha );

  if ($atribs{'gConexao'}) {
    return $Resource::true;
  } else {
    Wx::MessageBox($Resource::STR_NCONBANCO, 'Erro', wxOK | wxICON_ERROR);
    return $Resource::false;
  }
}

sub DisconectaBanco {
  my $self = shift;

  $atribs{'gConexao'}->disconnect();
}

sub AtualizaDados {
my( $self, $hBancoLocal, $sSql ) = @_;

  my $sth = $hBancoLocal->prepare( $sSql );
  if ($sth->execute()) {
    $sth->finish();
    return $Resource::true;
  } else {
    Wx::MessageBox($Resource::STR_NCEXECSQL, 'Erro', wxOK | wxICON_ERROR);
    $sth->finish();
    return $Resource::false;
  }
}

sub ConsultaDados {
my( $self, $hBancoLocal, $sSql ) = @_;
my @lista = [];
my $nLinha = 0;

  my $sth = $hBancoLocal->prepare( $sSql );
  my $rc = $sth->execute();
  if ($rc) {
    while ( @lista = $sth->fetchrow_array() ) {
      $nLinha += 1;
    }
    $sth->finish();
    if ($nLinha > 0) {
      return $Resource::true;
    } else {
      return $Resource::false;
    }
  } else {
    Wx::MessageBox($Resource::STR_NCEXECSQL, 'Erro', wxOK | wxICON_ERROR);
    $sth->finish();
    return $Resource::false;
  }
}

sub arrumaColunas {
my( $self, $sth, $lstLocal ) = @_;
my @lstLinhas;
my @sDBILinha;
my $nCol = 0;
my $nLinha = 0;
my @lstCols;

while ( @sDBILinha = $sth->fetchrow_array() ) {
  @lstCols = [];
  for($nCol = 0; $nCol < $sth->{NUM_OF_FIELDS}; $nCol++) {
    if ($sth->{TYPE}->[$nCol] == SQL_SMALLINT) {
      $lstCols[$nCol] = sprintf("%d", $sDBILinha[$nCol]);
    } elsif ($sth->{TYPE}->[$nCol] == SQL_REAL) {
      $lstCols[$nCol] = sprintf("%.2f", $sDBILinha[$nCol]);
    } elsif ($sth->{TYPE}->[$nCol] == 93) {
      $lstCols[$nCol] = $self->ConverteDataHoraStr($sDBILinha[$nCol],
        $Resource::false, '%d/%m/%Y', '%H:%M:%S');
    } else {
      $lstCols[$nCol] = $sDBILinha[$nCol];
    }
    $lstLinhas[$nLinha][$nCol] = $lstCols[$nCol];
  }  
  $nLinha+=1; 
}
$lstLocal->set_tam( $nLinha );
$lstLocal->set_col( @lstLinhas );
}

sub ConsultaDadosLista {
my( $self, $hBancoLocal, $lstLocal, $sSql ) = @_;

  my $sth = $hBancoLocal->prepare( $sSql );
  my $rc = $sth->execute();
  if ($rc) {
    $lstLocal->clear();
    $self->arrumaColunas($sth, $lstLocal);
    $sth->finish();
    if ($lstLocal->tam > 0) {
      return $Resource::true;
    } else {
      return $Resource::false;
    }
  } else {
    Wx::MessageBox($Resource::STR_NCEXECSQL, 'Erro', wxOK | wxICON_ERROR);
    $sth->finish();
    return $Resource::false;
  }
}

sub ValidaCampo {
  my( $self, $sCampo, $sMensagemErro ) = @_;

  if (length($sCampo) == 0) {
    Wx::MessageBox($sMensagemErro, "Erro", wxOK | wxICON_ERROR);
    return $Resource::true;
  } else {
    return $Resource::false;
  }
}

sub ConsultaCampoDesc {
my( $self, $Campos, $sTextoSql, $sMensagemErro) = @_;
my $sret = "";

  if ($self->ConsultaDadosLista($atribs{'gConexao'}, $Campos, $sTextoSql)) {
    my @lista = $Campos->col();
    $sret = $lista[0][1];
  } else {
    Wx::MessageBox($sMensagemErro, "Erro", wxOK | wxICON_ERROR);
    $sret = "";
  }
  return $sret;
}

sub AdicionaItemLista {
my( $self, $lstLista, $slCodLista, $sCampoCodigo, $sCampoDesc) = @_;
my( $sItems, $sCodigo, $sDesc );
  
  if (length($sCampoDesc->GetValue()) > 0) {
    $sCodigo = $sCampoCodigo->GetValue();
    $sDesc = $sCampoDesc->GetValue();
    
    $sItems = $sCodigo . ' - ' . $sDesc;
    my @lista = $slCodLista->col();
    my $ntam = $slCodLista->tam();
    if ($lstLista->FindString($sItems) == -1) {
      push @lista, $sCodigo;
      $slCodLista->set_col(@lista);
      $ntam+=1;
      $slCodLista->set_tam($ntam);
      $lstLista->Append($sItems);
    }
    $sCampoCodigo->Clear();
    $sCampoDesc->Clear();
  }
}

sub RemoveItemLista {
my( $self, $lstLista, $slCodLista ) = @_;
my $nSelIndice = 0;

  if ($lstLista->GetCount() > 0) {
    $nSelIndice = $lstLista->GetSelection();
    if ($lstLista->Selected($nSelIndice)){
      my @lista = $slCodLista->col();
      my $ntam = $slCodLista->tam();

      splice @lista, $nSelIndice, 1;
      $slCodLista->set_col(@lista);
      $ntam-=1;
      $slCodLista->set_tam($ntam);
      $lstLista->Delete($nSelIndice);
    }
  }
}

sub AdicionaValoresLista {
my( $self, $sTextoSql, $lstLista, $slCodLista ) = @_;
my $LocalCampos = ListaStr->new();
my( $sItems, $sCodigo, $sDesc, $nLinha );

  $lstLista->Clear();
  $slCodLista->clear();
  if ($self->ConsultaDadosLista($atribs{'gConexao'}, $LocalCampos, $sTextoSql)) {
    my @lista = $LocalCampos->col();
    my @lista2 = [];
    for($nLinha = 0; $nLinha < $LocalCampos->tam(); $nLinha++) {
      $sCodigo = $lista[$nLinha][0];
      $sDesc = $lista[$nLinha][1];

      $lista2[$nLinha] = $sCodigo;
      $sItems = $sCodigo . ' - ' . $sDesc;
      $lstLista->Append($sItems);
    }
    $slCodLista->set_col(@lista2);
    $slCodLista->set_tam($LocalCampos->tam());
  }
}

sub AdicionaColunasGrid {
my( $self, $grid, $nPosIni, $nQtdCols, @nLarguras_sRotulos) = @_;
my( $nPos, $nCont );
  
  if ($nPosIni > 0) {
    $grid->AppendCols($nQtdCols);
  }
  $nCont = 0;
  my @nLarguras = @nLarguras_sRotulos[0..($nQtdCols-1)];
  my @sRotulos = @nLarguras_sRotulos[$nQtdCols..($nQtdCols*2)];
  for($nPos = $nPosIni; $nPos < ($nPosIni + $nQtdCols); $nPos++) {
    $grid->SetColSize($nPos, $nLarguras[$nCont]);
    $grid->SetColLabelValue($nPos, $sRotulos[$nCont]);
    $nCont = $nCont + 1;
  }
}

sub AdicionaLinhasGrid { 
my( $self, $grid, $lstLinhas, $nQtdCol) = @_;
my( $nCol, $nLinha );
my @lista = $lstLinhas->col();

  $grid->DeleteRows(0, $grid->GetNumberRows(), $Resource::true);
  $grid->AppendRows($lstLinhas->tam, $Resource::true);
  for($nCol = 0; $nCol < $nQtdCol; $nCol++) {
    for($nLinha = 0; $nLinha < $lstLinhas->tam; $nLinha++) {
      $grid->SetCellValue($nLinha, $nCol, $lista[$nLinha][$nCol]);
    }
  }
}

1;
