-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de profissão";
   author: "Henrique F. de Souza";

class REGPROFISSAO

creation 
  make

feature
  codigo: STRING;
  profissao: STRING;
  
feature
  make is
  do
   codigo:="";
   profissao:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_profissao(sprofissao: STRING) is
  do
   profissao:=sprofissao;
  end;
  
end
