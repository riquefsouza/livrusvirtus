#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>

#include "ConsultasSQL.h"
#include "ListaStr.h"
#include "RotinasGlobais.h"

LPTSTR ConsSQL_Assunto(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sAssunto)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='N')
  lstrcpy(sCons, "select max(codassunto)+1 from Assunto");
else if (sTipo=='S') {
  lstrcpy(sCons, "select a.codassunto, a.assunto from Assunto a");
  lstrcat(sCons, " where a.codassunto=a.codassunto");
  if (lstrlen(sCodigo) > 0)
	 wsprintf(sCons, "%s%s%s", sCons, " and a.codassunto=",sCodigo);
  if (lstrlen(sAssunto) > 0)
	 wsprintf(sCons, "%s%s%s%s", sCons, " and a.assunto like '%",sAssunto,"%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", "insert into Assunto(codassunto, assunto) values(",
  sCodigo,",'",sAssunto,"')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s", "update Assunto set assunto='",sAssunto,
  "' where codassunto=",sCodigo);
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%", "delete from Assunto where codassunto=",sCodigo);

return sCons;
}

LPTSTR ConsSQL_Autor(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sAutor)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='N')
  lstrcpy(sCons, "select max(codautor)+1 from Autor");
else if (sTipo=='S') {
  lstrcpy(sCons, "select a.codautor as Codigo, a.Autor as Autor from Autor a");
  lstrcat(sCons, " where a.codautor=a.codautor");
  if (lstrlen(sCodigo) > 0)
    wsprintf(sCons, "%s%s%s", sCons, " and a.codautor=",sCodigo);
  if (lstrlen(sAutor) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and a.autor like '%",sAutor,"%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", "insert into Autor(codautor, autor) values(",
  sCodigo,",'",sAutor,"')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s", " update Autor set autor='",sAutor,
  "' where codautor=",sCodigo);
else if (sTipo=='D')
  wsprintf(sCons, "%s%s", "delete from Autor where codautor=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Editora(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sEditora)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='N')
  lstrcpy(sCons, "select max(codeditora)+1 from Editora");
else if (sTipo=='S') {
  lstrcpy(sCons, "select e.codeditora as Codigo, e.editora as Editora from editora e");
  lstrcat(sCons, " where e.codeditora=e.codeditora");
  if (lstrlen(sCodigo) > 0)
    wsprintf(sCons, "%s%s%s", sCons, " and e.codeditora=",sCodigo);
  if (lstrlen(sEditora) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and e.editora like '%",sEditora, "%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", " insert into editora(codeditora, editora) values(",
  sCodigo,",'",sEditora,"')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s", " update editora set editora='",sEditora,
  "' where codeditora=",sCodigo);
else if (sTipo=='D')
  wsprintf(sCons, "%s%s", "delete from editora where codeditora=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Idioma(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sIdioma)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='N')
  lstrcpy(sCons, "select max(codidioma)+1 from Idioma");
else if (sTipo=='S') {
  lstrcpy(sCons, "select i.codidioma as Codigo, i.idioma as idioma from Idioma i");
  lstrcat(sCons, " where i.codidioma=i.codidioma");
  if (lstrlen(sCodigo) > 0)
    wsprintf(sCons, "%s%s%s", sCons, " and i.codidioma=",sCodigo);
  if (lstrlen(sIdioma) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and i.idioma like '%",sIdioma, "%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", "insert into Idioma(codidioma, idioma) values(",
  sCodigo,",'",sIdioma,"')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s", "update Idioma set idioma='",sIdioma,
  "' where codidioma=",sCodigo);
else if (sTipo=='D')
  wsprintf(sCons, "%s%s", "delete from Idioma where codidioma=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Usuario(TCHAR sTipo, LPTSTR sLogin, LPTSTR sSenha)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='S')
 wsprintf(sCons, "%s%s%s%s%s", "select * from Usuario where login='", 
   sLogin, "' and senha='", sSenha, "'");
else if (sTipo=='U')
 wsprintf(sCons, "%s%s%s%s%s", "update Usuario set senha='",
   sSenha, "' where login='", sLogin, "'");

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Livro(TCHAR sTipo, LPTSTR sISBN, LPTSTR sTitulo, LPTSTR sEdicao,
LPTSTR sAnoPubli,LPTSTR sVolume,LPTSTR sCodEditora, LPTSTR sCodIdioma,
LPTSTR sNPaginas,LPTSTR sPreco,LPTSTR sQtdEstoque)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='S') {
 wsprintf(sCons, "%s%s%s%s%s%s%s", 
 "select l.isbn as ISBN, l.titulo as Titulo, l.edicao as Edicao,",
 "l.anopubli as AnoPublicacao,l.volume as Volume,l.codeditora as CodEditora,",
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma,",
 "l.npaginas as NumPaginas, l.preco as Preco, l.qtdestoque as Estoque",
 " from Livro l, editora e, idioma i",
 " where l.codeditora=e.codeditora",
 " and l.codidioma=i.codidioma");
 if (lstrlen(sISBN) > 0)
   wsprintf(sCons, "%s%s%s%s", sCons, " and l.isbn='", sISBN, "'");
 if (lstrlen(sTitulo) > 0)
   wsprintf(sCons, "%s%s%s%s", sCons, " and l.titulo like '%", sTitulo, "%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Livro(isbn, titulo, edicao, anopubli, codeditora,", 
  "volume, codidioma,npaginas, preco, qtdestoque) values('",
  sISBN, "','", sTitulo, "',", sEdicao, ",", sAnoPubli, ",", sCodEditora, ",",
  sVolume, ",", sCodIdioma, ",", sNPaginas, ",", sPreco, ",", sQtdEstoque, ")");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Livro set titulo='", sTitulo, "',edicao=", sEdicao,
  ",anopubli=", sAnoPubli, ",volume=", sVolume, ",codeditora=", sCodEditora,
  ",codidioma=", sCodIdioma, ",npaginas=", sNPaginas, ",preco=", sPreco,
  ",qtdestoque=", sQtdEstoque,
  " where isbn='", sISBN, "'");
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%s", " delete from Livro where isbn='", sISBN, "'");
else if (sTipo=='Q') {
  wsprintf(sCons, "%s%s%s%s", 
  "select l.isbn as ISBN, l.titulo as Titulo, l.preco as Preco,",
  "l.qtdestoque as Estoque",
  " from Livro l",
  " where l.isbn=l.isbn");
 if (lstrlen(sISBN) > 0)
  wsprintf(sCons, "%s%s%s%s", sCons, " and l.isbn='", sISBN, "'");
 if (lstrlen(sTitulo) > 0)
  wsprintf(sCons, "%s%s%s%s", sCons, " and l.titulo like '%", sTitulo, "%'");
}

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Cliente(TCHAR sTipo, LPTSTR sCPF,LPTSTR sNome, LPTSTR sEmail,
LPTSTR sIdentidade,LPTSTR sSexo,LPTSTR sTelefone, LPTSTR sDtNascimento,
LPTSTR sCodEndereco,LPTSTR sCodPais, LPTSTR sCodProfissao)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 3);

if (sTipo=='S') {
 wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s", 
 "select c.cpf as CPF, c.nome as Nome, c.email as Email,",
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone,",
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco,",
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP,",
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPais,",
 "p.pais as Pais, c.codprofissao as CodProfissao,r.profissao as Profissao",
 " from Cliente c, endereco e, pais p, profissao r",
 " where c.codendereco=e.codendereco",
 " and c.codpais=p.codpais",
 " and c.codprofissao=r.codprofissao");
 if (lstrlen(sCPF) > 0)
   wsprintf(sCons, "%s%s%s%s", sCons, " and c.cpf='", sCPF, "'");
 if (lstrlen(sNome) > 0)
   wsprintf(sCons, "%s%s%s%s", sCons, " and c.nome like '%", sNome, "%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Cliente(cpf, nome, email, identidade, sexo,", 
  "telefone, datanasc, codendereco, codpais, codprofissao) values('",
  sCPF, "','", sNome, "','", sEmail, "','", sIdentidade, "','", sSexo, "','",
  sTelefone, "',",Rotinas_sepDTHR, sDtNascimento, Rotinas_sepDTHR, ",", 
  sCodEndereco, ",'", sCodPais, "',", sCodProfissao, ")");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Cliente set nome='",sNome,"',email='",sEmail,
  "',identidade='",sIdentidade, "',sexo='",sSexo,"',telefone='",sTelefone,
  "',datanasc=",Rotinas_sepDTHR,sDtNascimento,Rotinas_sepDTHR,
  ",codendereco=",sCodEndereco,
  ",codpais='",sCodPais,"',codprofissao=",sCodProfissao,
  " where cpf='",sCPF,"'");
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%s", "delete from Cliente where cpf='", sCPF, "'");

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Endereco(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sLogradouro,
LPTSTR sBairro,LPTSTR sCEP,LPTSTR sCidade, LPTSTR sEstado)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='N')
  lstrcpy(sCons, "select max(codendereco)+1 from Endereco");
else if (sTipo=='S') {
  wsprintf(sCons, "%s%s%s%s", 
  "select e.codendereco as Codigo, e.logradouro as Logradouro,",
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado",
  " from Endereco e",
  " where e.codendereco=e.codendereco");
  if (lstrlen(sCodigo) > 0)
    wsprintf(sCons, "%s%s%s", sCons, " and e.codendereco=",sCodigo);
  if (lstrlen(sLogradouro) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and e.logradouro like '%",sLogradouro, "%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Endereco(codendereco, logradouro, bairro, cep,", 
  "cidade, estado) values(", sCodigo, ",'", sLogradouro, "','", sBairro,
  "','", sCEP, "','", sCidade, "','", sEstado, "')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s", 
  "update Endereco set logradouro='",sLogradouro, "',bairro='",
  sBairro, "',cep='", sCEP, "',cidade='", sCidade, "',estado='", sEstado, "'",
  " where codendereco=", sCodigo);
else if (sTipo=='D')
  wsprintf(sCons, "%s%s", "delete from Endereco where codendereco=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Pais(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sPais)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='S') {
  lstrcpy(sCons, "select p.codpais as Codigo, p.pais as Pais from Pais p");
  lstrcat(sCons, " where p.codpais=p.codpais");
  if (lstrlen(sCodigo) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and p.codpais='",sCodigo,"'");
  if (lstrlen(sPais) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and p.pais like '%",sPais,"%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", "insert into Pais(codpais, pais) values('",
  sCodigo,"','",sPais,"')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s%s%s", "update Pais set pais='",sPais,"'",
  " where codpais='",sCodigo,"'");
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%s", "delete from Pais where codpais='",sCodigo,"'");

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Profissao(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sProfissao)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='N')
  lstrcpy(sCons, "select max(codprofissao)+1 from Profissao");
else if (sTipo=='S') {
  lstrcpy(sCons, 
  "select p.codprofissao as Codigo, p.profissao as Profissao from Profissao p");
  lstrcat(sCons, " where p.codprofissao=p.codprofissao");
  if (lstrlen(sCodigo) > 0)
    wsprintf(sCons, "%s%s%s", sCons, " and p.codprofissao=",sCodigo);
  if (lstrlen(sProfissao) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and p.profissao like '%", 
    sProfissao, "%'");
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", 
  "insert into Profissao(codprofissao, profissao) values(",
  sCodigo, ",'", sProfissao, "')");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s", "update Profissao set profissao='",
  sProfissao,"' where codprofissao=",sCodigo);
else if (sTipo=='D')
  wsprintf(sCons, "%s%s", "delete from Profissao where codprofissao=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_LivroAss(TCHAR sTipo, LPTSTR sISBN, LPTSTR sCodAssunto)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='S')
  wsprintf(sCons, "%s%s%s%s%s", 
  "select la.codassunto, a.assunto from LivroAss la, Assunto a", 
  " where la.codassunto=a.codassunto", 
  " and la.isbn='",sISBN,"'");
else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", 
  "insert into LivroAss(isbn, codassunto) values('",
  sISBN,"',",sCodAssunto,")");
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%s", "delete from LivroAss where isbn='",sISBN,"'");

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_LivroAut(TCHAR sTipo, LPTSTR sISBN, LPTSTR sCodAutor)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if (sTipo=='S')
  wsprintf(sCons, "%s%s%s%s%s", 
  "select la.codautor, a.autor from LivroAut la, Autor a", 
  " where la.codautor=a.codautor", 
  " and la.isbn='",sISBN,"'");
else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s", "insert into LivroAut(isbn, codautor) values('",
  sISBN,"',",sCodAutor,")");
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%s", "delete from LivroAut where isbn='",sISBN,"'");

return sCons;
}
//---------------------------------------------------------------------------
LPTSTR ConsSQL_Venda(TCHAR sTipo, LPTSTR sISBN,LPTSTR sCPF, LPTSTR sDataVenda,
LPTSTR sPrecoVenda,LPTSTR sQtdEstoque)
{
LPTSTR sCons;
sCons = Rotinas_alocaString(TAM_MAX_STR * 2);

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
    wsprintf(sCons, "%s%s%s%s",
    "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente,",
    "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preco",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  else if (sTipo=='P')
    wsprintf(sCons, "%s%s%s", "select sum(l.preco) as PrecoTotal",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  if (lstrlen(sISBN) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and v.isbn='",sISBN,"'");
  if (lstrlen(sCPF) > 0)
    wsprintf(sCons, "%s%s%s%s", sCons, " and v.cpf='",sCPF,"'");
  if (lstrlen(sDataVenda) > 0)
    wsprintf(sCons, "%s%s%s%s%s%s", sCons, " and v.datavenda=",
      Rotinas_sepDTHR,sDataVenda,Rotinas_sepDTHR);
} else if (sTipo=='I')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Venda(isbn, cpf, datavenda, precovenda) values('",
  sISBN,"','",sCPF,"',",Rotinas_sepDTHR,sDataVenda,Rotinas_sepDTHR,
  ",",sPrecoVenda,")");
else if (sTipo=='U')
  wsprintf(sCons, "%s%s%s%s%s", 
  "update Livro set qtdestoque=",sQtdEstoque," where isbn='",sISBN,"'");
else if (sTipo=='D')
  wsprintf(sCons, "%s%s%s%s%s%s%s%s%s", 
  "delete from Venda where isbn='",sISBN,
  "' and cpf='",sCPF,"' and datavenda=",
  Rotinas_sepDTHR,sDataVenda,Rotinas_sepDTHR);

return sCons;
}


