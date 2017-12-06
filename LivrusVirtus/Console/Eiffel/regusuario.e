-- ----------------------------------------------------------------------------
-- Sistema integrante do projeto Livrus Virtus.
-- Todos os direitos reservados para Henrique F. de Souza.
-- Versão programada na linguagem Eiffel.
-- ----------------------------------------------------------------------------
indexing
   title: "Classe de registro de usuário";
   author: "Henrique F. de Souza";

class REGUSUARIO

creation 
  make

feature
  login: STRING;
  senha: STRING;
  
feature
  make is
  do
   login:="";
   senha:="";
  end;
  
  set_login(slogin: STRING) is
  do
   login:=slogin;
  end;
  
  set_senha(ssenha: STRING) is
  do
   senha:=ssenha;
  end;
  
end
