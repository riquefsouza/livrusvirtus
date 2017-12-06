-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de autor";
   author: "Henrique F. de Souza";

class REGAUTOR

creation 
  make

feature
  codigo: STRING;
  autor: STRING;
  
feature
  make is
  do
   codigo:="";
   autor:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_autor(sautor: STRING) is
  do
   autor:=sautor;
  end;
  
end
