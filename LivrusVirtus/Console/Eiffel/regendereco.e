-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro dos endereços";
   author: "Henrique F. de Souza";

class REGENDERECO

creation 
  make

feature
  codigo: STRING;
  logradouro: STRING;
  bairro: STRING;
  cep: STRING;
  cidade: STRING;
  estado: STRING;
  
feature
  make is
  do
    codigo:="";
    logradouro:="";
    bairro:="";
    cep:="";
    cidade:="";
    estado:="";
  end;
  
  set_codigo(scodigo: STRING) is
  do
   codigo:=scodigo;
  end;
  
  set_logradouro(slogradouro: STRING) is
  do
   logradouro:=slogradouro;
  end;

  set_bairro(sbairro: STRING) is
  do
   bairro:=sbairro;
  end;

  set_cep(scep: STRING) is
  do
   cep:=scep;
  end;

  set_cidade(scidade: STRING) is
  do
   cidade:=scidade;
  end;

  set_estado(sestado: STRING) is
  do
   estado:=sestado;
  end;
end
