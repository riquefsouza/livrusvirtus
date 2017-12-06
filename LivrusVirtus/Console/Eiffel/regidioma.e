-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de idioma";
   author: "Henrique F. de Souza";

class REGIDIOMA

creation 
  make

feature
  codigo: STRING;
  idioma: STRING;
  
feature
  make is
  do
   codigo:="";
   idioma:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_idioma(sidioma: STRING) is
  do
   idioma:=sidioma;
  end;
  
end
