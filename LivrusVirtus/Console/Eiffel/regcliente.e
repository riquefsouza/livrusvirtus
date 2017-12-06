-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro dos clientes";
   author: "Henrique F. de Souza";

class REGCLIENTE

creation 
  make

feature
  cpf: STRING;
  nome: STRING;
  email: STRING;
  identidade: STRING;
  sexo: STRING;
  telefone: STRING;
  dtnascimento: STRING;
  codendereco: STRING;
  codpais: STRING;
  codprofissao: STRING;
  
feature
  make is
  do
    cpf:="";
    nome:="";
    email:="";
    identidade:="";
    sexo:="";
    telefone:="";
    dtnascimento:="";
    codendereco:="";
    codpais:="";
    codprofissao:="";
  end;
  
  set_cpf(scpf: STRING) is
  do
   cpf:=scpf;
  end;
  
  set_nome(snome: STRING) is
  do
   nome:=snome;
  end;

  set_email(semail: STRING) is
  do
   email:=semail;
  end;

  set_identidade(sidentidade: STRING) is
  do
   identidade:=sidentidade;
  end;

  set_sexo(ssexo: STRING) is
  do
   sexo:=ssexo;
  end;

  set_telefone(stelefone: STRING) is
  do
   telefone:=stelefone;
  end;

  set_dtnascimento(sdtnascimento: STRING) is
  do
   dtnascimento:=sdtnascimento;
  end;

  set_codendereco(scodendereco: STRING) is
  do
   codendereco:=scodendereco;
  end;

  set_codpais(scodpais: STRING) is
  do
   codpais:=scodpais;
  end;

  set_codprofissao(scodprofissao: STRING) is
  do
   codprofissao:=scodprofissao;
  end;  
end
