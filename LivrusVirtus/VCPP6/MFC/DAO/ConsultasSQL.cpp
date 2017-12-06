#include "stdafx.h"

#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CConsultasSQL::CConsultasSQL() {
}

CString CConsultasSQL::Assunto(TCHAR sTipo, CString sCodigo, CString sAssunto)
{
CString sCons;

if (sTipo=='N')
  sCons = "select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons = "select a.codassunto, a.assunto from Assunto a";
  sCons += " where a.codassunto=a.codassunto";
  if (sCodigo.GetLength() > 0)
	  sCons += " and a.codassunto=" + sCodigo;
  if (sAssunto.GetLength() > 0)
	  sCons += " and a.assunto like '" + Rotinas_sepLIKE + sAssunto + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", "insert into Assunto(codassunto, assunto) values(",
  sCodigo,",'",sAssunto,"')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s", "update Assunto set assunto='",sAssunto,
  "' where codassunto=",sCodigo);
else if (sTipo=='D')
  sCons.Format("%s%s", "delete from Assunto where codassunto=",sCodigo);

return sCons;
}

CString CConsultasSQL::Autor(TCHAR sTipo, CString sCodigo, CString sAutor)
{
CString sCons;

if (sTipo=='N')
  sCons = "select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons = "select a.codautor as Código, a.Autor as Autor from Autor a";
  sCons += " where a.codautor=a.codautor";
  if (sCodigo.GetLength() > 0)
    sCons += " and a.codautor=" + sCodigo;
  if (sAutor.GetLength() > 0)
    sCons += " and a.autor like '" + Rotinas_sepLIKE + sAutor + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", "insert into Autor(codautor, autor) values(",
  sCodigo,",'",sAutor,"')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s", " update Autor set autor='",sAutor,
  "' where codautor=",sCodigo);
else if (sTipo=='D')
  sCons.Format("%s%s", "delete from Autor where codautor=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Editora(TCHAR sTipo, CString sCodigo, CString sEditora)
{
CString sCons;

if (sTipo=='N')
  sCons = "select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons = "select e.codeditora as Código, e.editora as Editora from editora e";
  sCons += " where e.codeditora=e.codeditora";
  if (sCodigo.GetLength() > 0)
    sCons += " and e.codeditora=" + sCodigo;
  if (sEditora.GetLength() > 0)
    sCons += " and e.editora like '" + Rotinas_sepLIKE + sEditora + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", " insert into editora(codeditora, editora) values(",
  sCodigo,",'",sEditora,"')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s", " update editora set editora='",sEditora,
  "' where codeditora=",sCodigo);
else if (sTipo=='D')
  sCons.Format("%s%s", "delete from editora where codeditora=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Idioma(TCHAR sTipo, CString sCodigo, CString sIdioma)
{
CString sCons;

if (sTipo=='N')
  sCons = "select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons = "select i.codidioma as Código, i.idioma as idioma from Idioma i";
  sCons += " where i.codidioma=i.codidioma";
  if (sCodigo.GetLength() > 0)
    sCons += " and i.codidioma=" + sCodigo;
  if (sIdioma.GetLength() > 0)
    sCons += " and i.idioma like '" + Rotinas_sepLIKE + sIdioma + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", "insert into Idioma(codidioma, idioma) values(",
  sCodigo,",'",sIdioma,"')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s", "update Idioma set idioma='",sIdioma,
  "' where codidioma=",sCodigo);
else if (sTipo=='D')
  sCons.Format("%s%s", "delete from Idioma where codidioma=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Usuario(TCHAR sTipo, CString sLogin, CString sSenha)
{
CString sCons;

if (sTipo=='S')
 sCons.Format("%s%s%s%s%s", "select * from Usuario where login='", 
   sLogin, "' and senha='", sSenha, "'");
else if (sTipo=='U')
 sCons.Format("%s%s%s%s%s", "update Usuario set senha='",
   sSenha, "' where login='", sLogin, "'");

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Livro(TCHAR sTipo, CString sISBN, CString sTitulo, CString sEdicao,
CString sAnoPubli,CString sVolume,CString sCodEditora, CString sCodIdioma,
CString sNPaginas,CString sPreco,CString sQtdEstoque)
{
CString sCons;

if (sTipo=='S') {
 sCons.Format("%s%s%s%s%s%s%s", 
 "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição,",
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora,",
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma,",
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque",
 " from Livro l, editora e, idioma i",
 " where l.codeditora=e.codeditora",
 " and l.codidioma=i.codidioma");
 if (sISBN.GetLength() > 0)
   sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.GetLength() > 0)
   sCons += " and l.titulo like '" + Rotinas_sepLIKE + sTitulo + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Livro(isbn, titulo, edicao, anopubli, codeditora,", 
  "volume, codidioma,npaginas, preco, qtdestoque) values('",
  sISBN, "','", sTitulo, "',", sEdicao, ",", sAnoPubli, ",", sCodEditora, ",",
  sVolume, ",", sCodIdioma, ",", sNPaginas, ",", sPreco, ",", sQtdEstoque, ")");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Livro set titulo='", sTitulo, "',edicao=", sEdicao,
  ",anopubli=", sAnoPubli, ",volume=", sVolume, ",codeditora=", sCodEditora,
  ",codidioma=", sCodIdioma, ",npaginas=", sNPaginas, ",preco=", sPreco,
  ",qtdestoque=", sQtdEstoque,
  " where isbn='", sISBN, "'");
else if (sTipo=='D')
  sCons.Format("%s%s%s", " delete from Livro where isbn='", sISBN, "'");
else if (sTipo=='Q') {
  sCons.Format("%s%s%s%s",
  "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço,",
  "l.qtdestoque as Estoque",
  " from Livro l",
  " where l.isbn=l.isbn");
 if (sISBN.GetLength() > 0)
  sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.GetLength() > 0)
  sCons += " and l.titulo like '" + Rotinas_sepLIKE + sTitulo + Rotinas_sepLIKE + "'";
}

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Cliente(TCHAR sTipo, CString sCPF,CString sNome, CString sEmail,
CString sIdentidade,CString sSexo,CString sTelefone, CString sDtNascimento,
CString sCodEndereco,CString sCodPais, CString sCodProfissao)
{
CString sCons;

if (sTipo=='S') {
 sCons.Format("%s%s%s%s%s%s%s%s%s%s", 
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
 if (sCPF.GetLength() > 0)
   sCons += " and c.cpf='" + sCPF + "'";
 if (sNome.GetLength() > 0)
   sCons += " and c.nome like '" + Rotinas_sepLIKE + sNome + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Cliente(cpf, nome, email, identidade, sexo,", 
  "telefone, datanasc, codendereco, codpais, codprofissao) values('",
  sCPF, "','", sNome, "','", sEmail, "','", sIdentidade, "','", sSexo, "','",
  sTelefone, "',",Rotinas_sepDTHR, sDtNascimento, Rotinas_sepDTHR, ",", 
  sCodEndereco, ",'", sCodPais, "',", sCodProfissao, ")");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Cliente set nome='",sNome,"',email='",sEmail,
  "',identidade='",sIdentidade, "',sexo='",sSexo,"',telefone='",sTelefone,
  "',datanasc=",Rotinas_sepDTHR,sDtNascimento,Rotinas_sepDTHR,
  ",codendereco=",sCodEndereco,
  ",codpais='",sCodPais,"',codprofissao=",sCodProfissao,
  " where cpf='",sCPF,"'");
else if (sTipo=='D')
  sCons.Format("%s%s%s", "delete from Cliente where cpf='", sCPF, "'");

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Endereco(TCHAR sTipo, CString sCodigo, CString sLogradouro,
CString sBairro,CString sCEP,CString sCidade, CString sEstado)
{
CString sCons;

if (sTipo=='N')
  sCons = "select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons.Format("%s%s%s%s",
  "select e.codendereco as Código, e.logradouro as Logradouro,",
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado",
  " from Endereco e",
  " where e.codendereco=e.codendereco");
  if (sCodigo.GetLength() > 0)
    sCons += " and e.codendereco=" + sCodigo;
  if (sLogradouro.GetLength() > 0)
    sCons += " and e.logradouro like '" + Rotinas_sepLIKE + sLogradouro + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Endereco(codendereco, logradouro, bairro, cep,", 
  "cidade, estado) values(", sCodigo, ",'", sLogradouro, "','", sBairro,
  "','", sCEP, "','", sCidade, "','", sEstado, "')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s", 
  "update Endereco set logradouro='",sLogradouro, "',bairro='",
  sBairro, "',cep='", sCEP, "',cidade='", sCidade, "',estado='", sEstado, "'",
  " where codendereco=", sCodigo);
else if (sTipo=='D')
  sCons.Format("%s%s", "delete from Endereco where codendereco=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Pais(TCHAR sTipo, CString sCodigo, CString sPais)
{
CString sCons;

if (sTipo=='S') {
  sCons = "select p.codpais as Código, p.pais as País from Pais p";
  sCons += " where p.codpais=p.codpais";
  if (sCodigo.GetLength() > 0)
    sCons += " and p.codpais='" + sCodigo + "'";
  if (sPais.GetLength() > 0)
    sCons += " and p.pais like '" + Rotinas_sepLIKE + sPais + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", "insert into Pais(codpais, pais) values('",
  sCodigo,"','",sPais,"')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s%s%s", "update Pais set pais='",sPais,"'",
  " where codpais='",sCodigo,"'");
else if (sTipo=='D')
  sCons.Format("%s%s%s", "delete from Pais where codpais='",sCodigo,"'");

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Profissao(TCHAR sTipo, CString sCodigo, CString sProfissao)
{
CString sCons;

if (sTipo=='N')
  sCons = "select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons = 
  "select p.codprofissao as Código, p.profissao as Profissão from Profissao p";
  sCons += " where p.codprofissao=p.codprofissao";
  if (sCodigo.GetLength() > 0)
    sCons += " and p.codprofissao=" + sCodigo;
  if (sProfissao.GetLength() > 0)
    sCons += " and p.profissao like '" + Rotinas_sepLIKE + sProfissao + Rotinas_sepLIKE + "'";
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", 
  "insert into Profissao(codprofissao, profissao) values(",
  sCodigo, ",'", sProfissao, "')");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s", "update Profissao set profissao='",
  sProfissao,"' where codprofissao=",sCodigo);
else if (sTipo=='D')
  sCons.Format("%s%s", "delete from Profissao where codprofissao=",sCodigo);

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::LivroAss(TCHAR sTipo, CString sISBN, CString sCodAssunto)
{
CString sCons;

if (sTipo=='S')
  sCons.Format("%s%s%s%s%s",
  "select la.codassunto, a.assunto from LivroAss la, Assunto a", 
  " where la.codassunto=a.codassunto", 
  " and la.isbn='", sISBN, "'");
else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", 
  "insert into LivroAss(isbn, codassunto) values('",
  sISBN,"',",sCodAssunto,")");
else if (sTipo=='D')
  sCons.Format("%s%s%s", "delete from LivroAss where isbn='",sISBN,"'");

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::LivroAut(TCHAR sTipo, CString sISBN, CString sCodAutor)
{
CString sCons;

if (sTipo=='S')
  sCons.Format("%s%s%s%s%s",
  "select la.codautor, a.autor from LivroAut la, Autor a",
  " where la.codautor=a.codautor",
  " and la.isbn='", sISBN, "'");
else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s", "insert into LivroAut(isbn, codautor) values('",
  sISBN,"',",sCodAutor,")");
else if (sTipo=='D')
  sCons.Format("%s%s%s", "delete from LivroAut where isbn='",sISBN,"'");

return sCons;
}
//---------------------------------------------------------------------------
CString CConsultasSQL::Venda(TCHAR sTipo, CString sISBN,CString sCPF, CString sDataVenda,
CString sPrecoVenda,CString sQtdEstoque)
{
CString sCons;

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
    sCons.Format("%s%s%s%s",
    "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente,",
    "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  else if (sTipo=='P')
    sCons.Format("%s%s%s",
    "select sum(l.preco) as PreçoTotal",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  if (sISBN.GetLength() > 0)
    sCons += " and v.isbn='" + sISBN + "'";
  if (sCPF.GetLength() > 0)
    sCons += " and v.cpf='" + sCPF + "'";
  if (sDataVenda.GetLength() > 0)
    sCons += " and v.datavenda=" + Rotinas_sepDTHR + 
      sDataVenda + Rotinas_sepDTHR;
} else if (sTipo=='I')
  sCons.Format("%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Venda(isbn, cpf, datavenda, precovenda) values('",
  sISBN,"','",sCPF,"',",Rotinas_sepDTHR,sDataVenda,Rotinas_sepDTHR,
  ",",sPrecoVenda,")");
else if (sTipo=='U')
  sCons.Format("%s%s%s%s%s", 
  "update Livro set qtdestoque=",sQtdEstoque," where isbn='",sISBN,"'");
else if (sTipo=='D')
  sCons.Format("%s%s%s%s%s%s%s%s%s", "delete from Venda where isbn='",sISBN,
  "' and cpf='",sCPF,
  "' and datavenda=",Rotinas_sepDTHR,sDataVenda,Rotinas_sepDTHR);

return sCons;
}


