-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro dos livros";
   author: "Henrique F. de Souza";

class REGLIVRO

creation 
  make

feature
  isbn: STRING;
  titulo: STRING;
  edicao: STRING;
  anopubli: STRING;
  codeditora: STRING;
  volume: STRING;
  codidioma: STRING;
  npaginas: STRING;
  preco: STRING;
  qtdestoque: STRING;
  
feature
  make is
  do
   isbn:="";
   titulo:="";
   edicao:="";
   anopubli:="";
   codeditora:="";
   volume:="";
   codidioma:="";
   npaginas:="";
   preco:="";
   qtdestoque:="";
  end;
  
  set_isbn(sisbn: STRING) is
  do
   isbn:=sisbn;
  end;
  
  set_titulo(stitulo: STRING) is
  do
   titulo:=stitulo;
  end;

  set_edicao(sedicao: STRING) is
  do
   edicao:=sedicao;
  end;

  set_anopubli(sanopubli: STRING) is
  do
   anopubli:=sanopubli;
  end;

  set_codeditora(scodeditora: STRING) is
  do
   codeditora:=scodeditora;
  end;

  set_volume(svolume: STRING) is
  do
   volume:=svolume;
  end;

  set_codidioma(scodidioma: STRING) is
  do
   codidioma:=scodidioma;
  end;

  set_npaginas(snpaginas: STRING) is
  do
   npaginas:=snpaginas;
  end;

  set_preco(spreco: STRING) is
  do
   preco:=spreco;
  end;

  set_qtdestoque(sqtdestoque: STRING) is
  do
   qtdestoque:=sqtdestoque;
  end;  
end
