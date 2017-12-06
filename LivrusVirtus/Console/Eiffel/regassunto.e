-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Vers�o programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de assunto";
   author: "Henrique F. de Souza";

class REGASSUNTO

creation 
  make

feature
  codigo: STRING;
  assunto: STRING;
  
feature
  make is
  do
   codigo:="";
   assunto:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_assunto(sassunto: STRING) is
  do
   assunto:=sassunto;
  end;  
end
