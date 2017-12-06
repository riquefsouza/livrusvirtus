#include "StdAfx.h"
#include "ConsultasSQL.h"

namespace Livrus
{

  ConsultasSQL::ConsultasSQL(void)
  {
  	//
  	// TODO: Add constructor logic here
  	//
  }

//---------------------------------------------------------------------------
String* ConsultasSQL::Assunto(char sTipo, String* sCodigo, String* sAssunto)
{
String* sCons=S"";

if (sTipo=='N')
  sCons=S"select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons=S"select a.codassunto as Código, a.assunto as Assunto from Assunto a" \
  S" where a.codassunto=a.codassunto";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and a.codassunto=",sCodigo);
  if (sAssunto->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and a.assunto like '%",sAssunto,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Assunto(codassunto, assunto) values(",
  sCodigo,S",'",sAssunto,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update Assunto set assunto='",sAssunto,
  S"' where codassunto=",sCodigo);
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Assunto where codassunto=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Autor(char sTipo, String* sCodigo, String* sAutor)
{
String* sCons=S"";

if (sTipo=='N')
  sCons=S"select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons=S"select a.codautor as Código, a.Autor as Autor from Autor a" \
  S" where a.codautor=a.codautor";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and a.codautor=",sCodigo);
  if (sAutor->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and a.autor like '%",sAutor,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Autor(codautor, autor) values(",
  sCodigo,S",'",sAutor,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update Autor set autor='",sAutor,
  S"' where codautor=",sCodigo);
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Autor where codautor=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Editora(char sTipo, String* sCodigo, String* sEditora)
{
String* sCons=S"";

if (sTipo=='N')
  sCons=S"select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons=S"select e.codeditora as Código, e.editora as Editora from editora e" \
  S" where e.codeditora=e.codeditora";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and e.codeditora=",sCodigo);
  if (sEditora->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and e.editora like '%",sEditora,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into editora(codeditora, editora) values(",
  sCodigo,S",'",sEditora,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update editora set editora='",sEditora,
  S"' where codeditora=",sCodigo);
else if (sTipo=='D')
  sCons=String::Concat(S"delete from editora where codeditora=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Idioma(char sTipo, String* sCodigo, String* sIdioma)
{
String* sCons=S"";

if (sTipo=='N')
  sCons=S"select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons=S"select i.codidioma as Código, i.idioma as idioma from Idioma i" \
  S" where i.codidioma=i.codidioma";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and i.codidioma=",sCodigo);
  if (sIdioma->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and i.idioma like '%",sIdioma,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Idioma(codidioma, idioma) values(",
  sCodigo,S",'",sIdioma,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update Idioma set idioma='",sIdioma,
  S"' where codidioma=",sCodigo);
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Idioma where codidioma=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Usuario(char sTipo, String* sLogin, String* sSenha)
{
String* sCons=S"";

if (sTipo=='S')
 sCons=String::Concat(S"select * from Usuario where login='",sLogin,S"' and senha='",sSenha,S"'");
else if (sTipo=='U')
 sCons=String::Concat(S"update Usuario set senha='",sSenha,S"' where login='",sLogin,S"'");

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Livro(char sTipo, String* sISBN, String* sTitulo, String* sEdicao,
String* sAnoPubli,String* sVolume,String* sCodEditora, String* sCodIdioma,
String* sNPaginas,String* sPreco,String* sQtdEstoque)
{
String* sCons=S"";

if (sTipo=='S') {
 sCons=S"select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," \
 S"l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," \
 S"e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," \
 S"l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" \
 S" from Livro l, editora e, idioma i" \
 S" where l.codeditora=e.codeditora" \
 S" and l.codidioma=i.codidioma";
 if (sISBN->Equals(S"")==false)
	sCons=String::Concat(sCons,S" and l.isbn='",sISBN,S"'");
 if (sTitulo->Equals(S"")==false)
	sCons=String::Concat(sCons,S" and l.titulo like '%",sTitulo,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Livro(isbn, titulo, edicao, anopubli, codeditora,", 
  S"volume, codidioma,npaginas, preco, qtdestoque) values('",
  sISBN,S"','",sTitulo,S"',",sEdicao,S",",sAnoPubli,S",",sCodEditora,S",",
  sVolume,S",",sCodIdioma,S",",sNPaginas,S",",sPreco,S",",sQtdEstoque,S")");
else if (sTipo=='U')
  sCons=String::Concat(S"update Livro set titulo='",sTitulo,S"',edicao=",sEdicao,
  S",anopubli=",sAnoPubli,S",volume=",sVolume,S",codeditora=",sCodEditora,
  S",codidioma=",sCodIdioma,S",npaginas=",sNPaginas,S",preco=",sPreco,
  S",qtdestoque=",sQtdEstoque,
  S" where isbn='",sISBN,S"'");
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Livro where isbn='",sISBN,S"'");
else if (sTipo=='Q') {
 sCons=S"select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," \
 S"l.qtdestoque as Estoque" \
 S" from Livro l" \
 S" where l.isbn=l.isbn";
 if (sISBN->Equals(S"")==false)
	sCons=String::Concat(sCons,S" and l.isbn='",sISBN,S"'");
 if (sTitulo->Equals(S"")==false)
	sCons=String::Concat(sCons,S" and l.titulo like '%",sTitulo,S"%'");
}

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Cliente(char sTipo, String* sCPF,String* sNome, String* sEmail,
String* sIdentidade,String* sSexo,String* sTelefone, String* sDtNascimento,
String* sCodEndereco,String* sCodPais, String* sCodProfissao)
{
String* sCons=S"";

if (sTipo=='S') {
 sCons=S"select c.cpf as CPF, c.nome as Nome, c.email as Email," \
 S"c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," \
 S"c.datanasc as DtNascimento, c.codendereco as CodEndereco," \
 S"e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," \
 S"e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís," \
 S"p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão" \
 S" from Cliente c, endereco e, pais p, profissao r" \
 S" where c.codendereco=e.codendereco" \
 S" and c.codpais=p.codpais" \
 S" and c.codprofissao=r.codprofissao";
 if (sCPF->Equals(S"")==false)
	sCons=String::Concat(sCons,S" and c.cpf='",sCPF,S"'");
 if (sNome->Equals(S"")==false)
	sCons=String::Concat(sCons,S" and c.nome like '%",sNome,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Cliente(cpf, nome, email, identidade, sexo,", 
  S"telefone, datanasc, codendereco, codpais, codprofissao) values('",
  sCPF,S"','",sNome,S"','",sEmail,S"','",sIdentidade,S"','",sSexo,S"','",
  sTelefone,S"','",sDtNascimento,S"',",sCodEndereco,S",'",sCodPais,S"',",
  sCodProfissao,S")");
else if (sTipo=='U')
  sCons=String::Concat(S"update Cliente set nome='",sNome,S"',email='",sEmail,
  S"',identidade=",sIdentidade,S"',sexo='",sSexo,S"',telefone='",sTelefone,
  S"',datanasc='",sDtNascimento,S"',codendereco=",sCodEndereco,
  S",codpais='",sCodPais,S"',codprofissao=",sCodProfissao,
  S" where cpf='",sCPF,S"'");
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Cliente where cpf='",sCPF,S"'");

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Endereco(char sTipo, String* sCodigo, String* sLogradouro,
String* sBairro,String* sCEP,String* sCidade, String* sEstado)
{
String* sCons=S"";

if (sTipo=='N')
  sCons=S"select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons=S"select e.codendereco as Código, e.logradouro as Logradouro," \
  S"e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" \
  S" from Endereco e" \
  S" where e.codendereco=e.codendereco";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and e.codendereco=",sCodigo);
  if (sLogradouro->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and e.logradouro like '%",sLogradouro,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Endereco(codendereco, logradouro, bairro, cep,", 
  S"cidade, estado) values(",sCodigo,S",'",sLogradouro,S"','",sBairro,
  S"','",sCEP,S"','",sCidade,S"','",sEstado,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update Endereco set logradouro='",sLogradouro,S"',bairro='",
  sBairro,S"',cep='",sCEP,S"',cidade='",sCidade,S"',estado='",sEstado,S"'",
  S" where codendereco=",sCodigo);
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Endereco where codendereco=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Pais(char sTipo, String* sCodigo, String* sPais)
{
String* sCons=S"";

if (sTipo=='S') {
  sCons=S"select p.codpais as Código, p.pais as País from Pais p" \
  S" where p.codpais=p.codpais";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and p.codpais='",sCodigo,S"'");
  if (sPais->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and p.pais like '%",sPais,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Pais(codpais, pais) values('",
  sCodigo,S"','",sPais,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update Pais set pais='",sPais,S"'",
  S" where codpais='",sCodigo,S"'");
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Pais where codpais='",sCodigo,S"'");

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Profissao(char sTipo, String* sCodigo, String* sProfissao)
{
String* sCons=S"";

if (sTipo=='N')
  sCons=S"select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons=S"select p.codprofissao as Código, p.profissao as Profissão from Profissao p" \
  S" where p.codprofissao=p.codprofissao";
  if (sCodigo->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and p.codprofissao=",sCodigo);
  if (sProfissao->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and p.profissao like '%",sProfissao,S"%'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Profissao(codprofissao, profissao) values(",
  sCodigo,S",'",sProfissao,S"')");
else if (sTipo=='U')
  sCons=String::Concat(S"update Profissao set profissao='",sProfissao,S"'",
  S" where codprofissao=",sCodigo);
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Profissao where codprofissao=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::LivroAss(char sTipo, String* sISBN, String* sCodAssunto)
{
String* sCons=S"";

if (sTipo=='S')
  sCons=String::Concat(S"select la.codassunto, a.assunto from LivroAss la, Assunto a", 
  S" where la.codassunto=a.codassunto", 
  S" and la.isbn='",sISBN,S"'");
else if (sTipo=='I')
  sCons=String::Concat(S"insert into LivroAss(isbn, codassunto) values('",
  sISBN,S"',",sCodAssunto,S")");
else if (sTipo=='D')
  sCons=String::Concat(S"delete from LivroAss where isbn='",sISBN,S"'");

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::LivroAut(char sTipo, String* sISBN, String* sCodAutor)
{
String* sCons=S"";

if (sTipo=='S')
  sCons=String::Concat(S"select la.codautor, a.autor from LivroAut la, Autor a", 
  S" where la.codautor=a.codautor", 
  S" and la.isbn='",sISBN,S"'");
else if (sTipo=='I')
  sCons=String::Concat(S"insert into LivroAut(isbn, codautor) values('",
  sISBN,S"',",sCodAutor,S")");
else if (sTipo=='D')
  sCons=String::Concat(S"delete from LivroAut where isbn='",sISBN,S"'");

return sCons;
}
//---------------------------------------------------------------------------
String* ConsultasSQL::Venda(char sTipo, String* sISBN,String* sCPF, String* sDataVenda,
String* sPrecoVenda,String* sQtdEstoque)
{
String* sCons=S"";

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
	 sCons=S"select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," \
	 S"v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" \
	 S" from Venda v, Livro l, Cliente c" \
	 S" where v.isbn=l.isbn and v.cpf=c.cpf";
  else if (sTipo=='P')
	 sCons=S"select sum(l.preco) as PreçoTotal" \
	 S" from Venda v, Livro l, Cliente c" \
	 S" where v.isbn=l.isbn and v.cpf=c.cpf";
  if (sISBN->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and v.isbn='",sISBN,S"'");
  if (sCPF->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and v.cpf='",sCPF,S"'");
  if (sDataVenda->Equals(S"")==false)
	 sCons=String::Concat(sCons,S" and v.datavenda='",sDataVenda,S"'");
} else if (sTipo=='I')
  sCons=String::Concat(S"insert into Venda(isbn, cpf, datavenda, precovenda) values('",
  sISBN,S"','",sCPF,S"','",sDataVenda,S"',",sPrecoVenda,S")");
else if (sTipo=='U')
  sCons=String::Concat(S"update Livro set qtdestoque=",sQtdEstoque,S" where isbn='",sISBN,S"'");
else if (sTipo=='D')
  sCons=String::Concat(S"delete from Venda where isbn='",sISBN,
  S"' and cpf='",sCPF,S"' and datavenda='",sDataVenda,S"'");

return sCons;
}
//---------------------------------------------------------------------------

}