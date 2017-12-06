-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro dos autores dos livros";
   author: "Henrique F. de Souza";

class REGLIVROAUT

creation 
  make

feature
  isbn: STRING;
  codautor: STRING;
  
feature
  make is
  do
   isbn:="";
   codautor:="";
  end;
  
  set_isbn(sisbn: STRING) is
  do
   isbn:=sisbn;
  end;
  
  set_codautor(scodautor: STRING) is
  do
   codautor:=scodautor;
  end;
  
end
