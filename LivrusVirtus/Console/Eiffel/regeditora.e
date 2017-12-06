-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de editora";
   author: "Henrique F. de Souza";

class REGEDITORA

creation 
  make

feature
  codigo: STRING;
  editora: STRING;
  
feature
  make is
  do
   codigo:="";
   editora:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_editora(seditora: STRING) is
  do
   editora:=seditora;
  end;
  
end
