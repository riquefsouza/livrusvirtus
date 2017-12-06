-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Vers�o programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de pa�s";
   author: "Henrique F. de Souza";

class REGPAIS

creation 
  make

feature
  codigo: STRING;
  pais: STRING;
  
feature
  make is
  do
   codigo:="";
   pais:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_pais(spais: STRING) is
  do
   pais:=spais;
  end;
  
end
