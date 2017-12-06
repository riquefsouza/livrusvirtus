use Wx 0.15 qw[:allclasses];
use strict;
package ConsultasSQL;

use Wx qw[:everything];

require RotinasGlobais;
require resource;

our $ConsSQL = undef;

sub new {
  my $self = shift;
  return $self;
}

sub Assunto {
  my( $self, $sTipo, $sCodigo, $sAssunto ) = @_;
  my $sCons = "";
  
  if ($sTipo =~ 'N') {
    $sCons = "select max(codassunto)+1 from Assunto";
  } elsif ($sTipo=~'S') {
    $sCons="select a.codassunto as Código, a.assunto as Assunto from Assunto a" . 
    " where a.codassunto=a.codassunto";
    if (length($sCodigo) > 0) {
  	  $sCons = $sCons . " and a.codassunto=" . $sCodigo;
    }
    if (length($sAssunto) > 0) {
  	  $sCons = $sCons . " and a.assunto like '%" . $sAssunto . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons = "insert into Assunto(codassunto, assunto) values(" . 
    $sCodigo . ",'" . $sAssunto . "')";
  } elsif ($sTipo=~'U') {
    $sCons = "update Assunto set assunto='" . $sAssunto . 
    "' where codassunto=" . $sCodigo;
  } elsif ($sTipo=~'D') {
    $sCons = "delete from Assunto where codassunto=" . $sCodigo;
  }
  return $sCons;
}

sub Autor {
  my( $self, $sTipo, $sCodigo, $sAutor ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'N') {
    $sCons="select max(codautor)+1 from Autor";
  } elsif ($sTipo=~'S') {
    $sCons="select a.codautor as Código, a.Autor as Autor from Autor a" .
    " where a.codautor=a.codautor";
    if (length($sCodigo) > 0) { 
  	 $sCons=$sCons . " and a.codautor=" . $sCodigo;
    }  
    if (length($sAutor) > 0) { 
  	 $sCons=$sCons . " and a.autor like '%" . $sAutor . "%'";
    }	  
  } elsif ($sTipo=~'I') {
    $sCons="insert into Autor(codautor, autor) values(" . 
    $sCodigo . ",'" . $sAutor . "')";
  } elsif ($sTipo=~'U') {
    $sCons="update Autor set autor='" . $sAutor . 
    "' where codautor=" . $sCodigo;
  } elsif ($sTipo=~'D') {
    $sCons = "delete from Autor where codautor=" . $sCodigo;
  }
  
  return $sCons;
}
#---------------------------------------------------------------------------
sub Editora {
  my( $self, $sTipo, $sCodigo, $sEditora ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'N') {
    $sCons="select max(codeditora)+1 from Editora";
  } elsif ($sTipo=~'S') {
    $sCons="select e.codeditora as Código, e.editora as Editora from editora e" .
    " where e.codeditora=e.codeditora";
    if (length($sCodigo) > 0) { 
   	  $sCons=$sCons . " and e.codeditora=" . $sCodigo;
    }
    if (length($sEditora) > 0) { 
   	  $sCons=$sCons . " and e.editora like '%" . $sEditora . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into editora(codeditora, editora) values(" . 
    $sCodigo . ",'" . $sEditora . "')";
  } elsif ($sTipo=~'U') {
    $sCons="update editora set editora='" . $sEditora .
    "' where codeditora=" . $sCodigo;
  } elsif ($sTipo=~'D') {
    $sCons="delete from editora where codeditora=" . $sCodigo;
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub Idioma {
  my( $self, $sTipo, $sCodigo, $sIdioma ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'N') {
    $sCons="select max(codidioma)+1 from Idioma";
  } elsif ($sTipo=~'S') {
    $sCons="select i.codidioma as Código, i.idioma as idioma from Idioma i" .
    " where i.codidioma=i.codidioma";
    if (length($sCodigo) > 0) { 
   	  $sCons=$sCons . " and i.codidioma=" . $sCodigo;
    }
    if (length($sIdioma) > 0) { 
  	  $sCons=$sCons . " and i.idioma like '%" . $sIdioma . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into Idioma(codidioma, idioma) values(" . 
    $sCodigo . ",'" . $sIdioma . "')";
  } elsif ($sTipo=~'U') {
    $sCons="update Idioma set idioma='" . $sIdioma .
    "' where codidioma=" . $sCodigo;
  } elsif ($sTipo=~'D') {
    $sCons="delete from Idioma where codidioma=" . $sCodigo;
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub Usuario {
  my( $self, $sTipo, $sLogin, $sSenha ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'S') {
    $sCons="select * from Usuario where login='" . $sLogin . 
          "' and senha='" . $sSenha. "'";
  } elsif ($sTipo=~'U') {
    $sCons="update Usuario set senha='" . $sSenha . 
          "' where login='" . $sLogin . "'";
  }
  return $sCons;
}
#---------------------------------------------------------------------------
sub Livro {
  my( $self, $sTipo, $sISBN, $sTitulo, $sEdicao,$sAnoPubli,$sVolume,$sCodEditora, 
          $sCodIdioma,$sNPaginas,$sPreco,$sQtdEstoque ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'S') { 
    $sCons="select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," .
    "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," .
    "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," .
    "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" .
    " from Livro l, editora e, idioma i" .
    " where l.codeditora=e.codeditora" .
    " and l.codidioma=i.codidioma";
    if (length($sISBN) > 0) { 
      $sCons=$sCons . " and l.isbn='" . $sISBN . "'";
    }
    if (length($sTitulo) > 0) { 
      $sCons=$sCons . " and l.titulo like '%" . $sTitulo . "%'";
    }  
  } elsif ($sTipo=~'I') {
    $sCons="insert into Livro(isbn, titulo, edicao, anopubli, codeditora," .  
    "volume, codidioma,npaginas, preco, qtdestoque) values('" . 
    $sISBN . "','" . $sTitulo . "'," . $sEdicao . "," . $sAnoPubli . "," . $sCodEditora . "," . 
    $sVolume . "," . $sCodIdioma . "," . $sNPaginas . "," . $sPreco . "," . $sQtdEstoque . ")";
  } elsif ($sTipo=~'U') {
    $sCons="update Livro set titulo='" . $sTitulo . "',edicao=" . $sEdicao .
    ",anopubli=" . $sAnoPubli . ",volume=" . $sVolume . ",codeditora=" . $sCodEditora .
    ",codidioma=" . $sCodIdioma . ",npaginas=" . $sNPaginas . ",preco=" . $sPreco .
    ",qtdestoque=" . $sQtdEstoque .
    " where isbn='" . $sISBN . "'";
  } elsif ($sTipo=~'D') {
    $sCons="delete from Livro where isbn='" . $sISBN . "'";
  } elsif ($sTipo=~'Q') {
    $sCons="select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," .
    "l.qtdestoque as Estoque" .
    " from Livro l" .
    " where l.isbn=l.isbn";
    if (length($sISBN) > 0) { 
      $sCons=$sCons . " and l.isbn='" . $sISBN . "'";
    }
    if (length($sTitulo) > 0) { 
      $sCons=$sCons . " and l.titulo like '%" . $sTitulo . "%'";
    }
  }
  
  return $sCons;
}
#---------------------------------------------------------------------------
sub Cliente {
  my( $self, $sTipo, $sCPF,$sNome, $sEmail,$sIdentidade,$sSexo,$sTelefone, 
            $sDtNascimento,$sCodEndereco,$sCodPais, $sCodProfissao ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'S') { 
    $sCons="select c.cpf as CPF, c.nome as Nome, c.email as Email," .
    "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," .
    "c.datanasc as DtNascimento, c.codendereco as CodEndereco," .
    "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," .
    "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís," .
    "p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão" .
    " from Cliente c, endereco e, pais p, profissao r" .
    " where c.codendereco=e.codendereco" .
    " and c.codpais=p.codpais" .
    " and c.codprofissao=r.codprofissao";
    if (length($sCPF) > 0) { 
      $sCons=$sCons . " and c.cpf='" . $sCPF . "'";
    }
    if (length($sNome) > 0) { 
      $sCons=$sCons . " and c.nome like '%" . $sNome . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into Cliente(cpf, nome, email, identidade, sexo," .  
    "telefone, datanasc, codendereco, codpais, codprofissao) values('" . 
    $sCPF . "','" . $sNome . "','" . $sEmail . "','" . $sIdentidade . "','" . $sSexo . "','" . 
    $sTelefone . "'," . $RotinasGlobais::sepDTHR . $sDtNascimento . $RotinasGlobais::sepDTHR . "," . 
    $sCodEndereco . ",'" . $sCodPais . "'," . $sCodProfissao . ")";
  } elsif ($sTipo=~'U') {
    $sCons="update Cliente set nome='" . $sNome . "',email='" . $sEmail .
    "',identidade='" . $sIdentidade . "',sexo='" . $sSexo . "',telefone='" . $sTelefone .
    "',datanasc=" . $RotinasGlobais::sepDTHR . $sDtNascimento . $RotinasGlobais::sepDTHR . 
    ",codendereco=" . $sCodEndereco .
    ",codpais='" . $sCodPais . "',codprofissao=" . $sCodProfissao .
    " where cpf='" . $sCPF . "'";
  } elsif ($sTipo=~'D') {
    $sCons="delete from Cliente where cpf='" . $sCPF . "'";
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub Endereco {
  my( $self, $sTipo, $sCodigo, $sLogradouro,$sBairro,$sCEP,$sCidade, $sEstado ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'N') {
    $sCons="select max(codendereco)+1 from Endereco";
  } elsif ($sTipo=~'S') {
    $sCons="select e.codendereco as Código, e.logradouro as Logradouro," .
    "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" .
    " from Endereco e" .
    " where e.codendereco=e.codendereco";
    if (length($sCodigo) > 0) { 
   	  $sCons=$sCons . " and e.codendereco=" . $sCodigo;
    }
    if (length($sLogradouro) > 0) { 
  	  $sCons=$sCons . " and e.logradouro like '%" . $sLogradouro . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into Endereco(codendereco, logradouro, bairro, cep," .  
    "cidade, estado) values(" . $sCodigo . ",'" . $sLogradouro . "','" . $sBairro,
    "','" . $sCEP . "','" . $sCidade . "','" . $sEstado . "')";
  } elsif ($sTipo=~'U') {
    $sCons="update Endereco set logradouro='" . $sLogradouro . "',bairro='" . 
    $sBairro . "',cep='" . $sCEP . "',cidade='" . $sCidade . "',estado='" . $sEstado . "'" . 
    " where codendereco=" . $sCodigo;
  } elsif ($sTipo=~'D') {
    $sCons="delete from Endereco where codendereco=" . $sCodigo;
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub Pais {
  my( $self, $sTipo, $sCodigo, $sPais ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'S') { 
    $sCons="select p.codpais as Código, p.pais as País from Pais p" .
    " where p.codpais=p.codpais";
    if (length($sCodigo) > 0) { 
  	  $sCons=$sCons . " and p.codpais='" . $sCodigo . "'";
    }
    if (length($sPais) > 0) { 
   	  $sCons=$sCons . " and p.pais like '%" . $sPais . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into Pais(codpais, pais) values('" . 
    $sCodigo . "','" . $sPais . "')";
  } elsif ($sTipo=~'U') {
    $sCons="update Pais set pais='" . $sPais . "'" . 
    " where codpais='" . $sCodigo . "'";
  } elsif ($sTipo=~'D') {
    $sCons="delete from Pais where codpais='" . $sCodigo . "'";
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub Profissao {
  my( $self, $sTipo, $sCodigo, $sProfissao ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'N') {
    $sCons="select max(codprofissao)+1 from Profissao";
  } elsif ($sTipo=~'S') {
    $sCons="select p.codprofissao as Código, p.profissao as Profissão from Profissao p" .
    " where p.codprofissao=p.codprofissao";
    if (length($sCodigo) > 0) { 
   	  $sCons=$sCons . " and p.codprofissao=" . $sCodigo;
    }
    if (length($sProfissao) > 0) { 
  	  $sCons=$sCons . " and p.profissao like '%" . $sProfissao . "%'";
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into Profissao(codprofissao, profissao) values(" . 
    $sCodigo . ",'" . $sProfissao . "')";
  } elsif ($sTipo=~'U') {
    $sCons="update Profissao set profissao='" . $sProfissao . "'" . 
    " where codprofissao=" . $sCodigo;
  } elsif ($sTipo=~'D') {
    $sCons="delete from Profissao where codprofissao=" . $sCodigo;
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub LivroAss {
  my( $self, $sTipo, $sISBN, $sCodAssunto ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'S') {
    $sCons="select la.codassunto, a.assunto from LivroAss la, Assunto a" .  
    " where la.codassunto=a.codassunto" .  
    " and la.isbn='" . $sISBN . "'";
  } elsif ($sTipo=~'I') {
    $sCons="insert into LivroAss(isbn, codassunto) values('" . 
    $sISBN . "'," . $sCodAssunto . ")";
  } elsif ($sTipo=~'D') {
    $sCons="delete from LivroAss where isbn='" . $sISBN . "'";
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub LivroAut {
  my( $self, $sTipo, $sISBN, $sCodAutor ) = @_;
  my $sCons = "";
  
  if ($sTipo=~'S') {
    $sCons="select la.codautor, a.autor from LivroAut la, Autor a" .  
    " where la.codautor=a.codautor" .  
    " and la.isbn='" . $sISBN . "'";
  } elsif ($sTipo=~'I') {
    $sCons="insert into LivroAut(isbn, codautor) values('" . 
    $sISBN . "'," . $sCodAutor . ")";
  } elsif ($sTipo=~'D') {
    $sCons="delete from LivroAut where isbn='" . $sISBN . "'";
  }    
  return $sCons;
}
#---------------------------------------------------------------------------
sub Venda {
  my( $self, $sTipo, $sISBN,$sCPF, $sDataVenda,$sPrecoVenda,$sQtdEstoque ) = @_;
  my $sCons = "";
  
  if (($sTipo=~'S') || ($sTipo=~'P')) {
    if ($sTipo=~'S') {
      $sCons="select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," .
      "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" .
      " from Venda v, Livro l, Cliente c" .
      " where v.isbn=l.isbn and v.cpf=c.cpf";
    } elsif ($sTipo=~'P') {
      $sCons="select sum(l.preco) as PreçoTotal" .
      " from Venda v, Livro l, Cliente c" .
      " where v.isbn=l.isbn and v.cpf=c.cpf";
    }
    if (length($sISBN) > 0) { 
  	  $sCons=$sCons . " and v.isbn='" . $sISBN . "'";
    }
    if (length($sCPF) > 0) { 
  	  $sCons=$sCons . " and v.cpf='" . $sCPF . "'";
    }
    if (length($sDataVenda) > 0) { 
   	  $sCons=$sCons . " and v.datavenda=" . $RotinasGlobais::sepDTHR . $sDataVenda . 
      $RotinasGlobais::sepDTHR;
    }
  } elsif ($sTipo=~'I') {
    $sCons="insert into Venda(isbn, cpf, datavenda, precovenda) values('" . 
    $sISBN . "','" . $sCPF . "'," . $RotinasGlobais::sepDTHR . $sDataVenda . 
    $RotinasGlobais::sepDTHR . "," . $sPrecoVenda . ")";
  } elsif ($sTipo=~'U') {
    $sCons="update Livro set qtdestoque=" . $sQtdEstoque . 
    " where isbn='" . $sISBN . "'";
  } elsif ($sTipo=~'D') {
    $sCons="delete from Venda where isbn='" . $sISBN,
    "' and cpf='" . $sCPF . "' and datavenda=" . $RotinasGlobais::sepDTHR . 
    $sDataVenda . $RotinasGlobais::sepDTHR;
  }    
  return $sCons;
}

1;
