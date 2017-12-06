#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CConsultasSQL *ConsSQL;

CConsultasSQL::CConsultasSQL() {
}

string CConsultasSQL::Assunto(char sTipo, string sCodigo, string sAssunto)
{
string sCons;

if (sTipo=='N')
  sCons = "select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons = "select a.codassunto, a.assunto from Assunto a";
  sCons += " where a.codassunto=a.codassunto";
  if (sCodigo.length() > 0)
	  sCons += " and a.codassunto=" + sCodigo;
  if (sAssunto.length() > 0)
	  sCons += " and a.assunto like '%" + sAssunto + "%'";
} else if (sTipo=='I')
  sCons = "insert into Assunto(codassunto, assunto) values(" +
  sCodigo + ",'" + sAssunto + "')";
else if (sTipo=='U')
  sCons = "update Assunto set assunto='" + sAssunto + 
  "' where codassunto=" + sCodigo;
else if (sTipo=='D')
  sCons = "delete from Assunto where codassunto=" + sCodigo;

return sCons;
}

string CConsultasSQL::Autor(char sTipo, string sCodigo, string sAutor)
{
string sCons;

if (sTipo=='N')
  sCons = "select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons = "select a.codautor as Codigo, a.Autor as Autor from Autor a";
  sCons += " where a.codautor=a.codautor";
  if (sCodigo.length() > 0)
    sCons += " and a.codautor=" + sCodigo;
  if (sAutor.length() > 0)
    sCons += " and a.autor like '%" + sAutor + "%'";
} else if (sTipo=='I')
  sCons = "insert into Autor(codautor, autor) values(" + 
  sCodigo + ",'" + sAutor + "')";
else if (sTipo=='U')
  sCons = " update Autor set autor='" + sAutor + 
  "' where codautor=" + sCodigo;
else if (sTipo=='D')
  sCons = "delete from Autor where codautor=" + sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Editora(char sTipo, string sCodigo, string sEditora)
{
string sCons;

if (sTipo=='N')
  sCons = "select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons = "select e.codeditora as Codigo, e.editora as Editora from editora e";
  sCons += " where e.codeditora=e.codeditora";
  if (sCodigo.length() > 0)
    sCons += " and e.codeditora=" + sCodigo;
  if (sEditora.length() > 0)
    sCons += " and e.editora like '%" + sEditora + "%'";
} else if (sTipo=='I')
  sCons = " insert into editora(codeditora, editora) values(" + 
  sCodigo + ",'" + sEditora + "')";
else if (sTipo=='U')
  sCons = " update editora set editora='" + sEditora + 
  "' where codeditora=" + sCodigo;
else if (sTipo=='D')
  sCons = "delete from editora where codeditora=" + sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Idioma(char sTipo, string sCodigo, string sIdioma)
{
string sCons;

if (sTipo=='N')
  sCons = "select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons = "select i.codidioma as Codigo, i.idioma as idioma from Idioma i";
  sCons += " where i.codidioma=i.codidioma";
  if (sCodigo.length() > 0)
    sCons += " and i.codidioma=" + sCodigo;
  if (sIdioma.length() > 0)
    sCons += " and i.idioma like '%" + sIdioma + "%'";
} else if (sTipo=='I')
  sCons = "insert into Idioma(codidioma, idioma) values(" + 
  sCodigo + ",'" + sIdioma + "')";
else if (sTipo=='U')
  sCons = "update Idioma set idioma='" + sIdioma + 
  "' where codidioma=" + sCodigo;
else if (sTipo=='D')
  sCons = "delete from Idioma where codidioma=" + sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Usuario(char sTipo, string sLogin, string sSenha)
{
string sCons;

if (sTipo=='S')
 sCons = "select * from Usuario where login='" +  
   sLogin +  "' and senha='" +  sSenha +  "'";
else if (sTipo=='U')
 sCons = "update Usuario set senha='" + 
   sSenha +  "' where login='" +  sLogin +  "'";

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Livro(char sTipo, string sISBN, string sTitulo, string sEdicao,
string sAnoPubli,string sVolume,string sCodEditora, string sCodIdioma,
string sNPaginas,string sPreco,string sQtdEstoque)
{
string sCons;

if (sTipo=='S') {
 sCons = "select l.isbn as ISBN, l.titulo as Titulo, l.edicao as Edicao," \
 "l.anopubli as AnoPublicacao,l.volume as Volume,l.codeditora as CodEditora," \
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," \
 "l.npaginas as NumPaginas, l.preco as Preco, l.qtdestoque as Estoque" \
 " from Livro l, editora e, idioma i" \
 " where l.codeditora=e.codeditora" \
 " and l.codidioma=i.codidioma";
 if (sISBN.length() > 0)
   sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.length() > 0)
   sCons += " and l.titulo like '%" + sTitulo + "%'";
} else if (sTipo=='I')
  sCons = "insert into Livro(isbn, titulo, edicao, anopubli, codeditora," \
  "volume, codidioma,npaginas, preco, qtdestoque) values('" +
  sISBN +  "','" +  sTitulo +  "'," +  sEdicao +  "," +  sAnoPubli +  "," +  sCodEditora +  "," +
  sVolume +  "," +  sCodIdioma +  "," +  sNPaginas +  "," +  sPreco +  "," +  sQtdEstoque +  ")";
else if (sTipo=='U')
  sCons = "update Livro set titulo='" +  sTitulo +  "',edicao=" +  sEdicao + 
  ",anopubli=" +  sAnoPubli +  ",volume=" +  sVolume +  ",codeditora=" +  sCodEditora + 
  ",codidioma=" +  sCodIdioma +  ",npaginas=" +  sNPaginas +  ",preco=" +  sPreco + 
  ",qtdestoque=" +  sQtdEstoque + 
  " where isbn='" +  sISBN +  "'";
else if (sTipo=='D')
  sCons = " delete from Livro where isbn='" +  sISBN +  "'";
else if (sTipo=='Q') {
  sCons = "select l.isbn as ISBN, l.titulo as Titulo, l.preco as Preco," \
  "l.qtdestoque as Estoque" \
  " from Livro l" \
  " where l.isbn=l.isbn";
 if (sISBN.length() > 0)
  sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.length() > 0)
  sCons += " and l.titulo like '%" + sTitulo + "%'";
}

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Cliente(char sTipo, string sCPF,string sNome, string sEmail,
string sIdentidade,string sSexo,string sTelefone, string sDtNascimento,
string sCodEndereco,string sCodPais, string sCodProfissao)
{
string sCons;

if (sTipo=='S') {
 sCons = "select c.cpf as CPF, c.nome as Nome, c.email as Email," \
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," \
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," \
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," \
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPais," \
 "p.pais as Pais, c.codprofissao as CodProfissao,r.profissao as Profissao" \
 " from Cliente c, endereco e, pais p, profissao r" \
 " where c.codendereco=e.codendereco" \
 " and c.codpais=p.codpais" \
 " and c.codprofissao=r.codprofissao";
 if (sCPF.length() > 0)
   sCons += " and c.cpf='" + sCPF + "'";
 if (sNome.length() > 0)
   sCons += " and c.nome like '%" + sNome + "%'";
} else if (sTipo=='I')
  sCons = "insert into Cliente(cpf, nome, email, identidade, sexo," \
  "telefone, datanasc, codendereco, codpais, codprofissao) values('" + 
  sCPF +  "','" +  sNome +  "','" +  sEmail +  "','" +  sIdentidade +  "','" +  sSexo +  "','" + 
  sTelefone +  "'," + Rotinas_sepDTHR +  sDtNascimento +  Rotinas_sepDTHR +  "," +  
  sCodEndereco +  ",'" +  sCodPais +  "'," +  sCodProfissao +  ")";
else if (sTipo=='U')
  sCons = "update Cliente set nome='" + sNome + "',email='" + sEmail + 
  "',identidade='" + sIdentidade +  "',sexo='" + sSexo + "',telefone='" + sTelefone + 
  "',datanasc=" + Rotinas_sepDTHR + sDtNascimento + Rotinas_sepDTHR + 
  ",codendereco=" + sCodEndereco + 
  ",codpais='" + sCodPais + "',codprofissao=" + sCodProfissao + 
  " where cpf='" + sCPF + "'";
else if (sTipo=='D')
  sCons = "delete from Cliente where cpf='" +  sCPF +  "'";

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Endereco(char sTipo, string sCodigo, string sLogradouro,
string sBairro,string sCEP,string sCidade, string sEstado)
{
string sCons;

if (sTipo=='N')
  sCons = "select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons = "select e.codendereco as Codigo, e.logradouro as Logradouro," \
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" \
  " from Endereco e" \
  " where e.codendereco=e.codendereco";
  if (sCodigo.length() > 0)
    sCons += " and e.codendereco=" + sCodigo;
  if (sLogradouro.length() > 0)
    sCons += " and e.logradouro like '%" + sLogradouro + "%'";
} else if (sTipo=='I')
  sCons = "insert into Endereco(codendereco, logradouro, bairro, cep," \
  "cidade, estado) values(" +  sCodigo +  ",'" +  sLogradouro +  "','" +  sBairro + 
  "','" +  sCEP +  "','" +  sCidade +  "','" +  sEstado +  "')";
else if (sTipo=='U')
  sCons = "update Endereco set logradouro='" + sLogradouro +  "',bairro='" + 
  sBairro +  "',cep='" +  sCEP +  "',cidade='" +  sCidade +  "',estado='" +  sEstado +  "'" + 
  " where codendereco=" +  sCodigo;
else if (sTipo=='D')
  sCons = "delete from Endereco where codendereco=" + sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Pais(char sTipo, string sCodigo, string sPais) {
string sCons;

if (sTipo=='S') {
  sCons = "select p.codpais as Codigo, p.pais as Pais from Pais p";
  sCons += " where p.codpais=p.codpais";
  if (sCodigo.length() > 0)
    sCons += " and p.codpais='" + sCodigo + "'";
  if (sPais.length() > 0)
    sCons += " and p.pais like '%" + sPais + "%'";
} else if (sTipo=='I')
  sCons = "insert into Pais(codpais, pais) values('" + 
  sCodigo + "','" + sPais + "')";
else if (sTipo=='U')
  sCons = "update Pais set pais='" + sPais + "'" + 
  " where codpais='" + sCodigo + "'";
else if (sTipo=='D')
  sCons = "delete from Pais where codpais='" + sCodigo + "'";

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Profissao(char sTipo, string sCodigo, string sProfissao)
{
string sCons;

if (sTipo=='N')
  sCons = "select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons = 
  "select p.codprofissao as Codigo, p.profissao as Profissao from Profissao p";
  sCons += " where p.codprofissao=p.codprofissao";
  if (sCodigo.length() > 0)
    sCons += " and p.codprofissao=" + sCodigo;
  if (sProfissao.length() > 0)
    sCons += " and p.profissao like '%" + sProfissao + "%'";
} else if (sTipo=='I')
  sCons = 
  "insert into Profissao(codprofissao, profissao) values(" + 
  sCodigo +  ",'" +  sProfissao +  "')";

else if (sTipo=='U')
  sCons = "update Profissao set profissao='" + 
  sProfissao + "' where codprofissao=" + sCodigo;
else if (sTipo=='D')
  sCons = "delete from Profissao where codprofissao=" + sCodigo;

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::LivroAss(char sTipo, string sISBN, string sCodAssunto)
{
string sCons;

if (sTipo=='S')
  sCons = "select la.codassunto, a.assunto from LivroAss la, Assunto a" \
  " where la.codassunto=a.codassunto" \
  " and la.isbn='" +  sISBN +  "'";
else if (sTipo=='I')
  sCons = 
  "insert into LivroAss(isbn, codassunto) values('" + 
  sISBN + "'," + sCodAssunto + ")";
else if (sTipo=='D')
  sCons = "delete from LivroAss where isbn='" + sISBN + "'";

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::LivroAut(char sTipo, string sISBN, string sCodAutor)
{
string sCons;

if (sTipo=='S')
  sCons = "select la.codautor, a.autor from LivroAut la, Autor a" \
  " where la.codautor=a.codautor" \
  " and la.isbn='" +  sISBN +  "'";
else if (sTipo=='I')
  sCons = "insert into LivroAut(isbn, codautor) values('" + 
  sISBN + "'," + sCodAutor + ")";
else if (sTipo=='D')
  sCons = "delete from LivroAut where isbn='" + sISBN + "'";

return sCons;
}
//---------------------------------------------------------------------------
string CConsultasSQL::Venda(char sTipo, string sISBN,string sCPF, string sDataVenda,
string sPrecoVenda,string sQtdEstoque)
{
string sCons;

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
    sCons = "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," \
    "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preco" \
    " from Venda v, Livro l, Cliente c" \
    " where v.isbn=l.isbn and v.cpf=c.cpf";
  else if (sTipo=='P')
    sCons = "select sum(l.preco) as PrecoTotal" \
    " from Venda v, Livro l, Cliente c" \
    " where v.isbn=l.isbn and v.cpf=c.cpf";
  if (sISBN.length() > 0)
    sCons += " and v.isbn='" + sISBN + "'";
  if (sCPF.length() > 0)
    sCons += " and v.cpf='" + sCPF + "'";
  if (sDataVenda.length() > 0)
    sCons += " and v.datavenda=" + Rotinas_sepDTHR + 
      sDataVenda + Rotinas_sepDTHR;
} else if (sTipo=='I')
  sCons = "insert into Venda(isbn, cpf, datavenda, precovenda) values('" + 
  sISBN + "','" + sCPF + "'," + Rotinas_sepDTHR + sDataVenda + Rotinas_sepDTHR + 
  "," + sPrecoVenda + ")";
else if (sTipo=='U')
  sCons = 
  "update Livro set qtdestoque=" + sQtdEstoque + " where isbn='" + sISBN + "'";
else if (sTipo=='D')
  sCons = "delete from Venda where isbn='" + sISBN + 
  "' and cpf='" + sCPF + 
  "' and datavenda=" + Rotinas_sepDTHR + sDataVenda + Rotinas_sepDTHR;

return sCons;
}


