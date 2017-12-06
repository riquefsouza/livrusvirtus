#include "resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CConsultasSQL *ConsSQL = (CConsultasSQL *) NULL;

CConsultasSQL::CConsultasSQL() { }
CConsultasSQL::~CConsultasSQL() { }

FXString CConsultasSQL::Assunto(FXchar sTipo, FXString sCodigo, 
  FXString sAssunto)
{
FXString sCons;

if (sTipo=='N')
  sCons = "select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons = "select a.codassunto, a.assunto from Assunto a";
  sCons += " where a.codassunto=a.codassunto";
  if (sCodigo.length() > 0)
    sCons += " and a.codassunto=" + sCodigo;
  if (sAssunto.length() > 0)
    sCons += " and a.assunto like '%%" + sAssunto + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
    "insert into Assunto(codassunto, assunto) values(",
    sCodigo.text(),",'",sAssunto.text(),"')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s", "update Assunto set assunto='",
  sAssunto.text(),"' where codassunto=",sCodigo.text());
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s", "delete from Assunto where codassunto=",
  sCodigo.text());

return sCons;
}

FXString CConsultasSQL::Autor(FXchar sTipo, FXString sCodigo, FXString sAutor)
{
FXString sCons;

if (sTipo=='N')
  sCons = "select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons = "select a.codautor as Código, a.Autor as Autor from Autor a";
  sCons += " where a.codautor=a.codautor";
  if (sCodigo.length() > 0)
    sCons += " and a.codautor=" + sCodigo;
  if (sAutor.length() > 0)
    sCons += " and a.autor like '%%" + sAutor + "%%'";

} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into Autor(codautor, autor) values(",
  sCodigo.text(),",'",sAutor.text(),"')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s", " update Autor set autor='",
  sAutor.text(),"' where codautor=",sCodigo.text());
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s", "delete from Autor where codautor=",
  sCodigo.text());

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Editora(FXchar sTipo, FXString sCodigo, 
FXString sEditora)
{
FXString sCons;

if (sTipo=='N')
  sCons = "select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons = "select e.codeditora as Código, e.editora as Editora from editora e";
  sCons += " where e.codeditora=e.codeditora";
  if (sCodigo.length() > 0)
    sCons += " and e.codeditora=" + sCodigo;
  if (sEditora.length() > 0)
    sCons += " and e.editora like '%%" + sEditora + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into editora(codeditora, editora) values(",
  sCodigo.text(),",'",sEditora.text(),"')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s", "update editora set editora='",
  sEditora.text(),"' where codeditora=",sCodigo.text());
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s", "delete from editora where codeditora=",
  sCodigo.text());

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Idioma(FXchar sTipo, FXString sCodigo, FXString sIdioma)
{
FXString sCons;

if (sTipo=='N')
  sCons = "select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons = "select i.codidioma as Código, i.idioma as idioma from Idioma i";
  sCons += " where i.codidioma=i.codidioma";
  if (sCodigo.length() > 0)
    sCons += " and i.codidioma=" + sCodigo;
  if (sIdioma.length() > 0)
    sCons += " and i.idioma like '%%" + sIdioma + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into Idioma(codidioma, idioma) values(",
  sCodigo.text(),",'",sIdioma.text(),"')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s", "update Idioma set idioma='",
  sIdioma.text(),"' where codidioma=",sCodigo.text());
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s", "delete from Idioma where codidioma=",
  sCodigo.text());

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Usuario(FXchar sTipo, FXString sLogin, FXString sSenha)
{
FXString sCons;

if (sTipo=='S')
 sCons = FXStringFormat("%s%s%s%s%s", "select * from Usuario where login='", 
   sLogin.text(), "' and senha='", sSenha.text(), "'");
else if (sTipo=='U')
 sCons = FXStringFormat("%s%s%s%s%s", "update Usuario set senha='",
   sSenha.text(), "' where login='", sLogin.text(), "'");

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Livro(FXchar sTipo, FXString sISBN, FXString sTitulo, 
FXString sEdicao,FXString sAnoPubli,FXString sVolume,FXString sCodEditora, 
FXString sCodIdioma,FXString sNPaginas,FXString sPreco,FXString sQtdEstoque)
{
FXString sCons;

if (sTipo=='S') {
 sCons = FXStringFormat("%s%s%s%s%s%s%s", 
 "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição,",
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora,",
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma,",
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque",
 " from Livro l, editora e, idioma i",
 " where l.codeditora=e.codeditora",
 " and l.codidioma=i.codidioma");
 if (sISBN.length() > 0)
   sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.length() > 0)
   sCons += " and l.titulo like '%%" + sTitulo + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Livro(isbn, titulo, edicao, anopubli, codeditora,", 
  "volume, codidioma,npaginas, preco, qtdestoque) values('",
  sISBN.text(), "','", sTitulo.text(), "',", sEdicao.text(), ",", 
  sAnoPubli.text(), ",", sCodEditora.text(), ",",sVolume.text(), ",", 
  sCodIdioma.text(), ",", sNPaginas.text(), ",", sPreco.text(), ",", 
  sQtdEstoque.text(), ")");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Livro set titulo='", sTitulo.text(), "',edicao=", sEdicao.text(),
  ",anopubli=", sAnoPubli.text(), ",volume=", sVolume.text(), ",codeditora=", 
  sCodEditora.text(),",codidioma=", sCodIdioma.text(), ",npaginas=", 
  sNPaginas.text(), ",preco=", sPreco.text(),",qtdestoque=", 
  sQtdEstoque.text()," where isbn='", sISBN.text(), "'");
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s%s", " delete from Livro where isbn='", 
  sISBN.text(), "'");
else if (sTipo=='Q') {
  sCons = FXStringFormat("%s%s%s%s",
  "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço,",
  "l.qtdestoque as Estoque",
  " from Livro l",
  " where l.isbn=l.isbn");
 if (sISBN.length() > 0)
  sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.length() > 0)
  sCons += " and l.titulo like '%%" + sTitulo + "%%'";
}

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Cliente(FXchar sTipo, FXString sCPF,FXString sNome, 
FXString sEmail,FXString sIdentidade,FXString sSexo,FXString sTelefone, 
FXString sDtNascimento,FXString sCodEndereco,FXString sCodPais, 
FXString sCodProfissao)
{
FXString sCons;

if (sTipo=='S') {
 sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s", 
 "select c.cpf as CPF, c.nome as Nome, c.email as Email,",
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone,",
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco,",
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP,",
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís,",
 "p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão",
 " from Cliente c, endereco e, pais p, profissao r",
 " where c.codendereco=e.codendereco",
 " and c.codpais=p.codpais",
 " and c.codprofissao=r.codprofissao");
 if (sCPF.length() > 0)
   sCons += " and c.cpf='" + sCPF + "'";
 if (sNome.length() > 0)
   sCons += " and c.nome like '%%" + sNome + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Cliente(cpf, nome, email, identidade, sexo,", 
  "telefone, datanasc, codendereco, codpais, codprofissao) values('",
  sCPF.text(), "','", sNome.text(), "','", sEmail.text(), "','", 
  sIdentidade.text(), "','", sSexo.text(), "','", sTelefone.text(), "',",
  Rotinas_sepDTHR.text(), sDtNascimento.text(), Rotinas_sepDTHR.text(), ",", 
  sCodEndereco.text(), ",'", sCodPais.text(), "',",sCodProfissao.text(),")");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Cliente set nome='",sNome.text(),"',email='",sEmail.text(),
  "',identidade='",sIdentidade.text(), "',sexo='",sSexo.text(),"',telefone='",
  sTelefone.text(),"',datanasc=",Rotinas_sepDTHR.text(),sDtNascimento.text(),
  Rotinas_sepDTHR.text(),",codendereco=",sCodEndereco.text(),
  ",codpais='",sCodPais.text(),"',codprofissao=",sCodProfissao.text(),
  " where cpf='",sCPF.text(),"'");
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s%s", "delete from Cliente where cpf='", 
  sCPF.text(), "'");

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Endereco(FXchar sTipo, FXString sCodigo, 
FXString sLogradouro,FXString sBairro,FXString sCEP,FXString sCidade, 
FXString sEstado)
{
FXString sCons;

if (sTipo=='N')
  sCons = "select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons = FXStringFormat("%s%s%s%s",
  "select e.codendereco as Código, e.logradouro as Logradouro,",
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado",
  " from Endereco e",
  " where e.codendereco=e.codendereco");
  if (sCodigo.length() > 0)
    sCons += " and e.codendereco=" + sCodigo;
  if (sLogradouro.length() > 0)
    sCons += " and e.logradouro like '%%" + sLogradouro + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Endereco(codendereco, logradouro, bairro, cep,", 
  "cidade, estado) values(", sCodigo.text(), ",'", sLogradouro.text(), "','", 
  sBairro.text(),"','", sCEP.text(), "','", sCidade.text(), "','", 
  sEstado.text(), "')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s%s%s", 
  "update Endereco set logradouro='",sLogradouro.text(), "',bairro='",
  sBairro.text(), "',cep='", sCEP.text(), "',cidade='", sCidade.text(), 
  "',estado='", sEstado.text(), "'",
  " where codendereco=", sCodigo.text());
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s", "delete from Endereco where codendereco=",
  sCodigo.text());

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Pais(FXchar sTipo, FXString sCodigo, FXString sPais)
{
FXString sCons;

if (sTipo=='S') {
  sCons = "select p.codpais as Código, p.pais as País from Pais p";
  sCons += " where p.codpais=p.codpais";
  if (sCodigo.length() > 0)
    sCons += " and p.codpais='" + sCodigo + "'";
  if (sPais.length() > 0)
    sCons += " and p.pais like '%%" + sPais + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into Pais(codpais, pais) values('",
  sCodigo.text(),"','",sPais.text(),"')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s%s%s", "update Pais set pais='",
  sPais.text(),"'"," where codpais='",sCodigo.text(),"'");
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s%s", "delete from Pais where codpais='",
  sCodigo.text(),"'");

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Profissao(FXchar sTipo, FXString sCodigo, 
FXString sProfissao)
{
FXString sCons;

if (sTipo=='N')
  sCons = "select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons = 
  "select p.codprofissao as Código, p.profissao as Profissão from Profissao p";
  sCons += " where p.codprofissao=p.codprofissao";
  if (sCodigo.length() > 0)
    sCons += " and p.codprofissao=" + sCodigo;
  if (sProfissao.length() > 0)
    sCons += " and p.profissao like '%%" + sProfissao + "%%'";
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into Profissao(codprofissao, profissao) values(",
  sCodigo.text(), ",'", sProfissao.text(), "')");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s", "update Profissao set profissao='",
  sProfissao.text(),"' where codprofissao=",sCodigo.text());
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s", "delete from Profissao where codprofissao=",
  sCodigo.text());

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::LivroAss(FXchar sTipo, FXString sISBN, 
FXString sCodAssunto)
{
FXString sCons;

if (sTipo=='S')
  sCons = FXStringFormat("%s%s%s%s%s",
  "select la.codassunto, a.assunto from LivroAss la, Assunto a", 
  " where la.codassunto=a.codassunto", 
  " and la.isbn='", sISBN.text(), "'");
else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into LivroAss(isbn, codassunto) values('",
  sISBN.text(),"',",sCodAssunto.text(),")");
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s%s", "delete from LivroAss where isbn='",
  sISBN.text(),"'");

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::LivroAut(FXchar sTipo, FXString sISBN, 
FXString sCodAutor)
{
FXString sCons;

if (sTipo=='S')
  sCons = FXStringFormat("%s%s%s%s%s",
  "select la.codautor, a.autor from LivroAut la, Autor a",
  " where la.codautor=a.codautor",
  " and la.isbn='", sISBN.text(), "'");
else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "insert into LivroAut(isbn, codautor) values('",
  sISBN.text(),"',",sCodAutor.text(),")");
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s%s", "delete from LivroAut where isbn='",
  sISBN.text(),"'");

return sCons;
}
//---------------------------------------------------------------------------
FXString CConsultasSQL::Venda(FXchar sTipo, FXString sISBN,FXString sCPF, 
FXString sDataVenda,FXString sPrecoVenda,FXString sQtdEstoque)
{
FXString sCons;

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
    sCons = FXStringFormat("%s%s%s%s",
    "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente,",
    "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  else if (sTipo=='P')
    sCons = FXStringFormat("%s%s%s",
    "select sum(l.preco) as PreçoTotal",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  if (sISBN.length() > 0)
    sCons += " and v.isbn='" + sISBN + "'";
  if (sCPF.length() > 0)
    sCons += " and v.cpf='" + sCPF + "'";
  if (sDataVenda.length() > 0)
    sCons += " and v.datavenda=" + Rotinas_sepDTHR + 
      sDataVenda + Rotinas_sepDTHR;
} else if (sTipo=='I')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Venda(isbn, cpf, datavenda, precovenda) values('",
  sISBN.text(),"','",sCPF.text(),"',",
  Rotinas_sepDTHR.text(),sDataVenda.text(),Rotinas_sepDTHR.text(),
  ",",sPrecoVenda.text(),")");
else if (sTipo=='U')
  sCons = FXStringFormat("%s%s%s%s%s", 
  "update Livro set qtdestoque=",sQtdEstoque.text(),
  " where isbn='",sISBN.text(),"'");
else if (sTipo=='D')
  sCons = FXStringFormat("%s%s%s%s%s%s%s%s", 
  "delete from Venda where isbn='",sISBN.text(), "' and cpf='",sCPF.text(),
  "' and datavenda=",Rotinas_sepDTHR.text(),sDataVenda.text(),
  Rotinas_sepDTHR.text());

return sCons;
}

