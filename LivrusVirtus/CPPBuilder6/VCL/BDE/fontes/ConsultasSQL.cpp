//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ConsultasSQL.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
TConsultasSQL *ConsSQL;
//---------------------------------------------------------------------------
__fastcall TConsultasSQL::TConsultasSQL()
        : TObject()
{
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Assunto(char sTipo, AnsiString sCodigo, AnsiString sAssunto)
{
AnsiString sCons;

if (sTipo=='N') 
  sCons="select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons="select a.codassunto as C�digo, a.assunto as Assunto from Assunto a" \
  " where a.codassunto=a.codassunto";
  if (sCodigo!="")
     sCons=sCons+" and codassunto="+sCodigo;
  if (sAssunto!="")
     sCons=sCons+" and assunto like '%"+sAssunto+"%'";
} else if (sTipo=='I')
  sCons="insert into Assunto(codassunto, assunto) values(" +
  sCodigo+",'"+sAssunto+"')";
else if (sTipo=='U')
  sCons="update Assunto set assunto='"+sAssunto+
  "' where codassunto="+sCodigo;
else if (sTipo=='D')
  sCons="delete from Assunto where codassunto="+sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Autor(char sTipo, AnsiString sCodigo, AnsiString sAutor)
{
AnsiString sCons;

if (sTipo=='N')
  sCons="select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons="select a.codautor as C�digo, a.Autor as Autor from Autor a" \
  " where a.codautor=a.codautor";
  if (sCodigo!="")
     sCons=sCons+" and codautor="+sCodigo;
  if (sAutor!="")
     sCons=sCons+" and autor like '%"+sAutor+"%'";
} else if (sTipo=='I')
  sCons="insert into Autor(codautor, autor) values("+
  sCodigo+",'"+sAutor+"')";
else if (sTipo=='U')
  sCons="update Autor set autor='"+sAutor+
  "' where codautor="+sCodigo;
else if (sTipo=='D') 
  sCons="delete from Autor where codautor="+sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Editora(char sTipo, AnsiString sCodigo, AnsiString sEditora)
{
AnsiString sCons;

if (sTipo=='N') 
  sCons="select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons="select e.codeditora as C�digo, e.editora as Editora from editora e" \
  " where e.codeditora=e.codeditora";
  if (sCodigo!="")
     sCons=sCons+" and codeditora="+sCodigo;
  if (sEditora!="")
     sCons=sCons+" and editora like '%"+sEditora+"%'";
} else if (sTipo=='I')
  sCons="insert into editora(codeditora, editora) values("+
  sCodigo+",'"+sEditora+"')";
else if (sTipo=='U') 
  sCons="update editora set editora='"+sEditora+
  "' where codeditora="+sCodigo;
else if (sTipo=='D')
  sCons="delete from editora where codeditora="+sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Idioma(char sTipo, AnsiString sCodigo, AnsiString sIdioma)
{
AnsiString sCons;

if (sTipo=='N')
  sCons="select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons="select i.codidioma as C�digo, i.idioma as idioma from Idioma i" \
  " where i.codidioma=i.codidioma";
  if (sCodigo!="")
     sCons=sCons+" and codidioma="+sCodigo;
  if (sIdioma!="")
     sCons=sCons+" and idioma like '%"+sIdioma+"%'";
} else if (sTipo=='I')
  sCons="insert into Idioma(codidioma, idioma) values("+
  sCodigo+",'"+sIdioma+"')";
else if (sTipo=='U')
  sCons="update Idioma set idioma='"+sIdioma+
  "' where codidioma="+sCodigo;
else if (sTipo=='D')
  sCons="delete from Idioma where codidioma="+sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Usuario(char sTipo, AnsiString sLogin, AnsiString sSenha)
{
AnsiString sCons;

if (sTipo=='S')
 sCons="select * from Usuario where login='"+sLogin+"' and senha='"+sSenha+"'";
else if (sTipo=='U')
 sCons="update Usuario set senha='"+sSenha+"' where login='"+sLogin+"'";

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Livro(char sTipo, AnsiString sISBN, AnsiString sTitulo,
AnsiString sEdicao,AnsiString sAnoPubli,AnsiString sVolume,AnsiString sCodEditora,
AnsiString sCodIdioma,AnsiString sNPaginas,AnsiString sPreco,AnsiString sQtdEstoque)
{
AnsiString sCons;

if (sTipo=='S') {
 sCons="select l.isbn as ISBN, l.titulo as T�tulo, l.edicao as Edi��o," \
 "l.anopubli as AnoPublica��o,l.volume as Volume,l.codeditora as CodEditora," \
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," \
 "l.npaginas as NumPaginas, l.preco as Pre�o, l.qtdestoque as Estoque" \
 " from Livro l, editora e, idioma i" \
 " where l.codeditora=e.codeditora" \
 " and l.codidioma=i.codidioma";
 if (sISBN!="")
    sCons=sCons+" and l.isbn='"+sISBN+"'";
 if (sTitulo!="")
    sCons=sCons+" and l.titulo like '%"+sTitulo+"%'";
} else if (sTipo=='I')
  sCons="insert into Livro(isbn, titulo, edicao, anopubli, codeditora," \
  "volume, codidioma,npaginas, preco, qtdestoque) values('"+
  sISBN+"','"+sTitulo+"',"+sEdicao+","+sAnoPubli+","+sCodEditora+","+
  sVolume+","+sCodIdioma+","+sNPaginas+","+sPreco+","+sQtdEstoque+")";
else if (sTipo=='U')
  sCons="update Livro set titulo='"+sTitulo+"',edicao="+sEdicao+
  ",anopubli="+sAnoPubli+",volume="+sVolume+",codeditora="+sCodEditora+
  ",codidioma="+sCodIdioma+",npaginas="+sNPaginas+",preco="+sPreco+
  ",qtdestoque="+sQtdEstoque+
  " where isbn='"+sISBN+"'";
else if (sTipo=='D')
  sCons="delete from Livro where isbn='"+sISBN+"'";
else if (sTipo=='Q') {
 sCons="select l.isbn as ISBN, l.titulo as T�tulo, l.preco as Pre�o," \
 "l.qtdestoque as Estoque" \
 " from Livro l" \
 " where l.isbn=l.isbn";
 if (sISBN!="")
    sCons=sCons+" and l.isbn='"+sISBN+"'";
 if (sTitulo!="")
    sCons=sCons+" and l.titulo like '%"+sTitulo+"%'";
}

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Cliente(char sTipo, AnsiString sCPF,AnsiString sNome,
AnsiString sEmail,AnsiString sIdentidade,AnsiString sSexo,AnsiString sTelefone,
AnsiString sDtNascimento,AnsiString sCodEndereco,AnsiString sCodPais,
AnsiString sCodProfissao)
{
AnsiString sCons;

if (sTipo=='S') {
 sCons="select c.cpf as CPF, c.nome as Nome, c.email as Email," \
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," \
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," \
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," \
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPa�s," \
 "p.pais as Pa�s, c.codprofissao as CodProfissao,r.profissao as Profiss�o" \
 " from Cliente c, endereco e, pais p, profissao r" \
 " where c.codendereco=e.codendereco" \
 " and c.codpais=p.codpais" \
 " and c.codprofissao=r.codprofissao";
 if (sCPF!="")
    sCons=sCons+" and c.cpf='"+sCPF+"'";
 if (sNome!="")
    sCons=sCons+" and c.nome like '%"+sNome+"%'";
} else if (sTipo=='I')
  sCons="insert into Cliente(cpf, nome, email, identidade, sexo," \
  "telefone, datanasc, codendereco, codpais, codprofissao) values('"+
  sCPF+"','"+sNome+"','"+sEmail+"','"+sIdentidade+"','"+sSexo+"','"+
  sTelefone+"','"+sDtNascimento+"',"+sCodEndereco+",'"+sCodPais+"',"+
  sCodProfissao+")";
else if (sTipo=='U')
  sCons="update Cliente set nome='"+sNome+"',email='"+sEmail+
  "',identidade="+sIdentidade+"',sexo='"+sSexo+"',telefone='"+sTelefone+
  "',datanasc='"+sDtNascimento+"',codendereco="+sCodEndereco+
  ",copais='"+sCodPais+"',codprofissao="+sCodProfissao+
  " where cpf='"+sCPF+"'";
else if (sTipo=='D')
  sCons="delete from Cliente where cpf='"+sCPF+"'";

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Endereco(char sTipo, AnsiString sCodigo,
AnsiString sLogradouro,AnsiString sBairro,AnsiString sCEP,AnsiString sCidade,
AnsiString sEstado)
{
AnsiString sCons;

if (sTipo=='N')
  sCons="select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons="select e.codendereco as C�digo, e.logradouro as Logradouro," \
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" \
  " from Endereco e" \
  " where e.codendereco=e.codendereco";
  if (sCodigo!="")
     sCons=sCons+" and e.codendereco="+sCodigo;
  if (sLogradouro!="")
     sCons=sCons+" and e.logradouro like '%"+sLogradouro+"%'";
} else if (sTipo=='I')
  sCons="insert into Endereco(codendereco, logradouro, bairro, cep," \
  "cidade, estado) values("+sCodigo+",'"+sLogradouro+"','"+sBairro+
  "','"+sCEP+"','"+sCidade+"','"+sEstado+"')";
else if (sTipo=='U')
  sCons="update Endereco set logradouro='"+sLogradouro+"',bairro='"+
  sBairro+"',cep='"+sCEP+"',cidade='"+sCidade+"',estado='"+sEstado+"'"+
  " where codendereco="+sCodigo;
else if (sTipo=='D')
  sCons="delete from Endereco where codendereco="+sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Pais(char sTipo, AnsiString sCodigo, AnsiString sPais)
{
AnsiString sCons;

if (sTipo=='S') {
  sCons="select p.codpais as C�digo, p.pais as Pa�s from Pais p" \
  " where p.codpais=p.codpais";
  if (sCodigo!="")
     sCons=sCons+" and p.codpais='"+sCodigo+"'";
  if (sPais!="")
     sCons=sCons+" and p.pais like '%"+sPais+"%'";
} else if (sTipo=='I')
  sCons="insert into Pais(codpais, pais) values('"+
  sCodigo+"','"+sPais+"')";
else if (sTipo=='U')
  sCons="update Pais set pais='"+sPais+"'"+
  " where codpais='"+sCodigo+"'";
else if (sTipo=='D')
  sCons="delete from Pais where codpais='"+sCodigo+"'";

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Profissao(char sTipo, AnsiString sCodigo,
AnsiString sProfissao)
{
AnsiString sCons;

if (sTipo=='N')
  sCons="select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons="select p.codprofissao as C�digo, p.profissao as Profiss�o from Profissao p" \
  " where p.codprofissao=p.codprofissao";
  if (sCodigo!="")
     sCons=sCons+" and p.codprofissao="+sCodigo;
  if (sProfissao!="")
     sCons=sCons+" and p.profissao like '%"+sProfissao+"%'";
} else if (sTipo=='I')
  sCons="insert into Profissao(codprofissao, profissao) values("+
  sCodigo+",'"+sProfissao+"')";
else if (sTipo=='U')
  sCons="update Profissao set profissao='"+sProfissao+"'"+
  " where codprofissao="+sCodigo;
else if (sTipo=='D')
  sCons="delete from Profissao where codprofissao="+sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::LivroAss(char sTipo, AnsiString sISBN, AnsiString sCodAssunto)
{
AnsiString sCons;

if (sTipo=='S')
  sCons="select la.codassunto, a.assunto from LivroAss la, Assunto a" \
  " where la.codassunto=a.codassunto" \
  " and la.isbn='"+sISBN+"'";
else if (sTipo=='I')
  sCons="insert into LivroAss(isbn, codassunto) values('"+
  sISBN+"',"+sCodAssunto+")";
else if (sTipo=='D')
  sCons="delete from LivroAss where isbn='"+sISBN+"'";

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::LivroAut(char sTipo, AnsiString sISBN, AnsiString sCodAutor)
{
AnsiString sCons;

if (sTipo=='S')
  sCons="select la.codautor, a.autor from LivroAut la, Autor a" \
  " where la.codautor=a.codautor" \
  " and la.isbn='"+sISBN+"'";
else if (sTipo=='I')
  sCons="insert into LivroAut(isbn, codautor) values('"+
  sISBN+"',"+sCodAutor+")";
else if (sTipo=='D')
  sCons="delete from LivroAut where isbn='"+sISBN+"'";

return sCons;
}
//---------------------------------------------------------------------------
AnsiString TConsultasSQL::Venda(char sTipo, AnsiString sISBN,AnsiString sCPF,
AnsiString sDataVenda,AnsiString sPrecoVenda,AnsiString sQtdEstoque)
{
AnsiString sCons;

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
     sCons="select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," \
     "v.isbn as ISBN,l.Titulo as Livro, l.preco as Pre�o" \
     " from Venda v, Livro l, Cliente c" \
     " where v.isbn=l.isbn and v.cpf=c.cpf";
  else if (sTipo=='P')
     sCons="select sum(l.preco) as Pre�oTotal" \
     " from Venda v, Livro l, Cliente c" \
     " where v.isbn=l.isbn and v.cpf=c.cpf";
  if (sISBN!="")
     sCons=sCons+" and v.isbn='"+sISBN+"'";
  if (sCPF!="")
     sCons=sCons+" and v.cpf='"+sCPF+"'";
  if (sDataVenda!="")
     sCons=sCons+" and v.datavenda='"+sDataVenda+"'";
} else if (sTipo=='I')
  sCons="insert into Venda(isbn, cpf, datavenda, precovenda) values('"+
  sISBN+"','"+sCPF+"','"+sDataVenda+"',"+sPrecoVenda+")";
else if (sTipo=='U')
  sCons="update Livro set qtdestoque="+sQtdEstoque+" where isbn='"+sISBN+"'";
else if (sTipo=='D')
  sCons="delete from Venda where isbn='"+sISBN+
  "' and cpf='"+sCPF+"' and datavenda='"+sDataVenda+"'";

return sCons;
}
//---------------------------------------------------------------------------
