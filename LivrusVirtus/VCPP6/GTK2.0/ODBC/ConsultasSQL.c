#include "resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

//---------------------------------------------------------------------------
GString* ConsSQL_Assunto(gchar sTipo, 
  G_CONST_RETURN gchar* sCodigo, G_CONST_RETURN gchar* sAssunto)
{
GString* sCons = g_string_new("");

if (sTipo=='N') 
  g_string_assign(sCons, "select max(codassunto)+1 from Assunto");
else if (sTipo=='S') {
  g_string_assign(sCons, "select a.codassunto as Codigo, a.assunto as Assunto" \
  " from Assunto a" \
  " where a.codassunto=a.codassunto"); 

  if (strlen(sCodigo) > 0) 
     g_string_sprintfa(sCons, " and a.codassunto=%s", sCodigo);
  if (strlen(sAssunto) > 0) 
     g_string_sprintfa(sCons, "%s%s%s", " and a.assunto like '%%", sAssunto, "%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Assunto(codassunto, assunto) values(%s,'%s')",
  sCodigo,sAssunto);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Assunto set assunto='%s' where codassunto=%s",
  sAssunto, sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Assunto where codassunto=%s",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Autor(char sTipo, G_CONST_RETURN gchar* sCodigo, 
                       G_CONST_RETURN gchar* sAutor)
{
GString* sCons = g_string_new("");

if (sTipo=='N')
  g_string_assign(sCons, "select max(codautor)+1 from Autor");
else if (sTipo=='S') {
  g_string_assign(sCons, "select a.codautor as Código, a.Autor as Autor from Autor a" \
  " where a.codautor=a.codautor");
  if (strlen(sCodigo) > 0)
    g_string_sprintfa(sCons, " and a.codautor=%s",sCodigo);
  if (strlen(sAutor) > 0)
    g_string_sprintfa(sCons, "%s%s", " and a.autor like '%%",sAutor,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Autor(codautor, autor) values(%s,'%s')",
  sCodigo,sAutor);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Autor set autor='%s' where codautor=%s",
  sAutor, sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Autor where codautor=%s",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Editora(char sTipo, G_CONST_RETURN gchar* sCodigo, 
                         G_CONST_RETURN gchar* sEditora)
{
GString* sCons = g_string_new("");

if (sTipo=='N')
  g_string_assign(sCons, "select max(codeditora)+1 from Editora");
else if (sTipo=='S') {
  g_string_assign(sCons, "select e.codeditora as Código, e.editora as Editora" \
  " from editora e" \
  " where e.codeditora=e.codeditora");
  if (strlen(sCodigo) > 0)
    g_string_sprintfa(sCons, " and e.codeditora=%s",sCodigo);
  if (strlen(sEditora) > 0)
    g_string_sprintfa(sCons, "%s%s%s", " and e.editora like '%%",sEditora,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into editora(codeditora, editora) values(%s,'%s'",
  sCodigo,sEditora);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update editora set editora='%s' where codeditora=%s",
  sEditora, sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from editora where codeditora=%s",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Idioma(char sTipo, G_CONST_RETURN gchar* sCodigo, 
                        G_CONST_RETURN gchar* sIdioma)
{
GString* sCons = g_string_new("");

if (sTipo=='N')
  g_string_assign(sCons, "select max(codidioma)+1 from Idioma");
else if (sTipo=='S') {
  g_string_assign(sCons, "select i.codidioma as Código, i.idioma as idioma from Idioma i" \
  " where i.codidioma=i.codidioma");
  if (strlen(sCodigo) > 0)
    g_string_sprintfa(sCons, " and i.codidioma=%s",sCodigo);
  if (strlen(sIdioma) > 0)
    g_string_sprintfa(sCons, "%s%s%s", " and i.idioma like '%%",sIdioma,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Idioma(codidioma, idioma) values(%s,'%s')",
  sCodigo,sIdioma);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Idioma set idioma='%s' where codidioma=%s",
  sIdioma, sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Idioma where codidioma=%s",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Usuario(char sTipo, G_CONST_RETURN gchar* sLogin, 
                         G_CONST_RETURN gchar* sSenha)
{
GString* sCons = g_string_new("");

if (sTipo=='S')
 g_string_sprintf(sCons, "select * from Usuario where login='%s' and senha='%s'",
 sLogin,sSenha);
else if (sTipo=='U')
 g_string_sprintf(sCons, "update Usuario set senha='%s' where login='%s'",
 sSenha,sLogin);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Livro(char sTipo, G_CONST_RETURN gchar* sISBN, 
G_CONST_RETURN gchar* sTitulo, G_CONST_RETURN gchar* sEdicao,
G_CONST_RETURN gchar* sAnoPubli,G_CONST_RETURN gchar* sVolume,
G_CONST_RETURN gchar* sCodEditora, G_CONST_RETURN gchar* sCodIdioma,
G_CONST_RETURN gchar* sNPaginas,G_CONST_RETURN gchar* sPreco,
G_CONST_RETURN gchar* sQtdEstoque)
{
GString* sCons = g_string_new("");

if (sTipo=='S') {
 g_string_assign(sCons, "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," \
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," \
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," \
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" \
 " from Livro l, editora e, idioma i" \
 " where l.codeditora=e.codeditora" \
 " and l.codidioma=i.codidioma");
 if (strlen(sISBN) > 0)
   g_string_sprintfa(sCons, " and l.isbn='%s'",sISBN);
 if (strlen(sTitulo) > 0)
   g_string_sprintfa(sCons, "%s%s%s", " and l.titulo like '%%",sTitulo,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Livro(isbn, titulo, edicao, anopubli, codeditora," \
  "volume, codidioma,npaginas, preco, qtdestoque) values('%s','%s',%s,%s,%s,%s,%s,%s,%s,%s",
  sISBN,sTitulo,sEdicao,sAnoPubli,sCodEditora,sVolume,sCodIdioma,sNPaginas,sPreco,sQtdEstoque);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Livro set titulo='%s',edicao=%s,anopubli=%s,volume=%s," \
  "codeditora=%s,codidioma=%s,npaginas=%s,preco=%s,qtdestoque=%s where isbn='%s'",
  sTitulo,sEdicao,sAnoPubli,sVolume,sCodEditora,sCodIdioma,sNPaginas,sPreco,sQtdEstoque,sISBN);
else if (sTipo=='D')
  g_string_sprintfa(sCons, "delete from Livro where isbn='%s'",sISBN);
else if (sTipo=='Q') {
 g_string_assign(sCons, "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," \
 "l.qtdestoque as Estoque" \
 " from Livro l" \
 " where l.isbn=l.isbn");
 if (strlen(sISBN) > 0)
   g_string_sprintfa(sCons, " and l.isbn='%s'",sISBN);
 if (strlen(sTitulo) > 0)
   g_string_sprintfa(sCons, " and l.titulo like '%s'",sTitulo);
}

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Cliente(char sTipo, G_CONST_RETURN gchar* sCPF,
G_CONST_RETURN gchar* sNome, G_CONST_RETURN gchar* sEmail,
G_CONST_RETURN gchar* sIdentidade,G_CONST_RETURN gchar* sSexo,
G_CONST_RETURN gchar* sTelefone, G_CONST_RETURN gchar* sDtNascimento,
G_CONST_RETURN gchar* sCodEndereco,G_CONST_RETURN gchar* sCodPais, 
G_CONST_RETURN gchar* sCodProfissao)
{
GString* sCons = g_string_new("");

if (sTipo=='S') {
 g_string_assign(sCons, "select c.cpf as CPF, c.nome as Nome, c.email as Email," \
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," \
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," \
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," \
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPais," \
 "p.pais as Pais, c.codprofissao as CodProfissao,r.profissao as Profissao" \
 " from Cliente c, endereco e, pais p, profissao r" \
 " where c.codendereco=e.codendereco" \
 " and c.codpais=p.codpais" \
 " and c.codprofissao=r.codprofissao");
 if (strlen(sCPF) > 0)
   g_string_sprintfa(sCons, " and c.cpf='%s'",sCPF);
 if (strlen(sNome) > 0)
   g_string_sprintfa(sCons, "%s%s%s", " and c.nome like '%%",sNome,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Cliente(cpf, nome, email, identidade, sexo," \
  "telefone, datanasc, codendereco, codpais, codprofissao) " \
  "values('%s','%s','%s','%s','%s','%s','%s',%s,'%s',%s)", \
  sCPF,sNome,sEmail,sIdentidade,sSexo,sTelefone,sDtNascimento,
  sCodEndereco,sCodPais,sCodProfissao);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Cliente set nome='%s',email='%s',identidade='%s'," \
  "sexo='%s',telefone='%s',datanasc=%s%s%s,codendereco=%s,codpais='%s',codprofissao=%s " \
  "where cpf='%s'", sNome,sEmail,sIdentidade,sSexo,sTelefone,Rotinas_sepDTHR,
  sDtNascimento,Rotinas_sepDTHR,sCodEndereco, sCodPais,sCodProfissao,sCPF);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Cliente where cpf='%s'",sCPF);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Endereco(char sTipo, G_CONST_RETURN gchar* sCodigo, 
G_CONST_RETURN gchar* sLogradouro, G_CONST_RETURN gchar* sBairro,
G_CONST_RETURN gchar* sCEP,G_CONST_RETURN gchar* sCidade, 
G_CONST_RETURN gchar* sEstado)
{
GString* sCons = g_string_new("");

if (sTipo=='N')
  g_string_assign(sCons, "select max(codendereco)+1 from Endereco");
else if (sTipo=='S') {
  g_string_assign(sCons, "select e.codendereco as Código, e.logradouro as Logradouro," \
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" \
  " from Endereco e" \
  " where e.codendereco=e.codendereco");
  if (strlen(sCodigo) > 0)
    g_string_sprintfa(sCons, " and e.codendereco=%s",sCodigo);
  if (strlen(sLogradouro) > 0)
    g_string_sprintfa(sCons, "%s%s%s", " and e.logradouro like '%%",sLogradouro,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Endereco(codendereco, logradouro, " \
  "bairro, cep, cidade, estado) values(%s,'%s','%s','%s','%s','%s')",
  sCodigo,sLogradouro,sBairro,sCEP,sCidade,sEstado);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Endereco set logradouro='%s'," \
  "bairro='%s',cep='%s',cidade='%s',estado='%s' where codendereco=%s",
  sLogradouro,sBairro,sCEP,sCidade,sEstado,sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Endereco where codendereco=%s",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Pais(char sTipo, G_CONST_RETURN gchar* sCodigo, 
                      G_CONST_RETURN gchar* sPais)
{
GString* sCons = g_string_new("");

if (sTipo=='S') {
  g_string_assign(sCons, "select p.codpais as Código, p.pais as País from Pais p" \
  " where p.codpais=p.codpais");
  if (strlen(sCodigo) > 0)
    g_string_sprintfa(sCons, " and p.codpais='%s'",sCodigo);
  if (strlen(sPais) > 0)
    g_string_sprintfa(sCons, "%s%s%s", " and p.pais like '%%",sPais,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Pais(codpais, pais) values('%s','%s')",
  sCodigo,sPais);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Pais set pais='%s' where codpais='%s'",
  sPais,sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Pais where codpais='%s'",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Profissao(char sTipo, G_CONST_RETURN gchar* sCodigo, 
                           G_CONST_RETURN gchar* sProfissao)
{
GString* sCons = g_string_new("");

if (sTipo=='N')
  g_string_assign(sCons, "select max(codprofissao)+1 from Profissao");
else if (sTipo=='S') {
  g_string_assign(sCons, "select p.codprofissao as Código, p.profissao as Profissão" \
  " from Profissao p" \
  " where p.codprofissao=p.codprofissao");
  if (strlen(sCodigo) > 0)
    g_string_sprintfa(sCons, " and p.codprofissao=%s",sCodigo);
  if (strlen(sProfissao) > 0)
    g_string_sprintfa(sCons, "%s%s%s", " and p.profissao like '%%",sProfissao,"%%'");
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Profissao(codprofissao, profissao) values(%s,'%s')",
  sCodigo,sProfissao);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Profissao set profissao='%s' where codprofissao=%s",
  sProfissao,sCodigo);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Profissao where codprofissao=%s",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_LivroAss(char sTipo, G_CONST_RETURN gchar* sISBN, 
                          G_CONST_RETURN gchar* sCodAssunto)
{
GString* sCons = g_string_new("");

if (sTipo=='S')
  g_string_sprintf(sCons, "select la.codassunto, a.assunto" \
  " from LivroAss la, Assunto a" \
  " where la.codassunto=a.codassunto" \
  " and la.isbn='%s'",sISBN);
else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into LivroAss(isbn, codassunto) values('%s',%s)",
  sISBN,sCodAssunto);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from LivroAss where isbn='%s'",sISBN);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_LivroAut(char sTipo, G_CONST_RETURN gchar* sISBN, 
                          G_CONST_RETURN gchar* sCodAutor)
{
GString* sCons = g_string_new("");

if (sTipo=='S')
  g_string_sprintf(sCons, "select la.codautor, a.autor" \
  " from LivroAut la, Autor a" \
  " where la.codautor=a.codautor" \
  " and la.isbn='%s'",sISBN);
else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into LivroAut(isbn, codautor) values('%s',%s)",
  sISBN,sCodAutor);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from LivroAut where isbn='%s'",sISBN);

return sCons;
}
//---------------------------------------------------------------------------
GString* ConsSQL_Venda(char sTipo, G_CONST_RETURN gchar* sISBN,
G_CONST_RETURN gchar* sCPF, G_CONST_RETURN gchar* sDataVenda,
G_CONST_RETURN gchar* sPrecoVenda,G_CONST_RETURN gchar* sQtdEstoque)
{
GString* sCons = g_string_new("");

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
    g_string_assign(sCons, "select v.datavenda as DataVenda," \
    "v.cpf as CPF, c.nome as Cliente," \
    "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" \
    " from Venda v, Livro l, Cliente c" \
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  else if (sTipo=='P')
    g_string_assign(sCons, "select sum(l.preco) as PreçoTotal" \
    " from Venda v, Livro l, Cliente c" \
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  if (strlen(sISBN) > 0)
    g_string_sprintfa(sCons, " and v.isbn='%s'",sISBN);
  if (strlen(sCPF) > 0)
    g_string_sprintfa(sCons, " and v.cpf='%s'",sCPF);
  if (strlen(sDataVenda) > 0)
    g_string_sprintfa(sCons, " and v.datavenda=%s%s%s",
      Rotinas_sepDTHR, sDataVenda, Rotinas_sepDTHR);
} else if (sTipo=='I')
  g_string_sprintf(sCons, "insert into Venda(isbn, cpf, datavenda, precovenda)" \
  " values('%s','%s','%s',%s)",sISBN,sCPF,sDataVenda,sPrecoVenda);
else if (sTipo=='U')
  g_string_sprintf(sCons, "update Livro set qtdestoque=%s where isbn='%s'",
  sQtdEstoque,sISBN);
else if (sTipo=='D')
  g_string_sprintf(sCons, "delete from Venda where isbn='%s' and cpf='%s'" \
  " and datavenda='%s'", sISBN, sCPF, sDataVenda);

return sCons;
}
//---------------------------------------------------------------------------

