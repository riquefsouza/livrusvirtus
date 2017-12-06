-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro dos assuntos dos livros";
   author: "Henrique F. de Souza";

class REGLIVROASS

creation 
  make

feature
  isbn: STRING;
  codassunto: STRING;
  
feature
  make is
  do
   isbn:="";
   codassunto:="";
  end;
  
  set_isbn(sisbn: STRING) is
  do
   isbn:=sisbn;
  end;
  
  set_codassunto(scodassunto: STRING) is
  do
   codassunto:=scodassunto;
  end;
  
end
