-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro das vendas";
   author: "Henrique F. de Souza";

class REGVENDA

creation 
  make

feature
  dthrvenda: STRING;  -- data/hora da venda dd/mm/yyyy hh:mm:ss
  cpf: STRING;
  isbn: STRING;
  precovenda: STRING;

feature
  make is
  do
    dthrvenda:="";
    cpf:="";
    isbn:="";
    precovenda:="";
  end;
  
  set_dthrvenda(sdthrvenda: STRING) is
  do
   dthrvenda:=sdthrvenda;
  end;
  
  set_cpf(scpf: STRING) is
  do
   cpf:=scpf;
  end;

  set_isbn(sisbn: STRING) is
  do
   isbn:=sisbn;
  end;

  set_precovenda(sprecovenda: STRING) is
  do
   precovenda:=sprecovenda;
  end;
end
