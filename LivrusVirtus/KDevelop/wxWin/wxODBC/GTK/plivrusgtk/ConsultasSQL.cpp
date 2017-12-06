#include "resource.h"
#include "ConsultasSQL.h"
#include "RotinasGlobais.h"

CConsultasSQL *ConsSQL = (CConsultasSQL *) NULL;

CConsultasSQL::CConsultasSQL() { }
CConsultasSQL::~CConsultasSQL() { }

wxString CConsultasSQL::Assunto(wxChar sTipo, wxString sCodigo, 
wxString sAssunto)
{
wxString sCons;

if (sTipo=='N')
  sCons = "select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons = "select a.codassunto, a.assunto from Assunto a";
  sCons += " where a.codassunto=a.codassunto";
  if (sCodigo.Len() > 0)
    sCons += " and a.codassunto=" + sCodigo;
  if (sAssunto.Len() > 0)
    sCons += " and a.assunto like '%%" + sAssunto + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
    "insert into Assunto(codassunto, assunto) values(",
    sCodigo.c_str(),",'",sAssunto.c_str(),"')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s", "update Assunto set assunto='",
  sAssunto.c_str(),"' where codassunto=",sCodigo.c_str());
else if (sTipo=='D')
  sCons = wxString::Format("%s%s", "delete from Assunto where codassunto=",
  sCodigo.c_str());

return sCons;
}

wxString CConsultasSQL::Autor(wxChar sTipo, wxString sCodigo, wxString sAutor)
{
wxString sCons;

if (sTipo=='N')
  sCons = "select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons = "select a.codautor as Código, a.Autor as Autor from Autor a";
  sCons += " where a.codautor=a.codautor";
  if (sCodigo.Len() > 0)
    sCons += " and a.codautor=" + sCodigo;
  if (sAutor.Len() > 0)
    sCons += " and a.autor like '%%" + sAutor + "%%'";

} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into Autor(codautor, autor) values(",
  sCodigo.c_str(),",'",sAutor.c_str(),"')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s", " update Autor set autor='",
  sAutor.c_str(),"' where codautor=",sCodigo.c_str());
else if (sTipo=='D')
  sCons = wxString::Format("%s%s", "delete from Autor where codautor=",
  sCodigo.c_str());

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Editora(wxChar sTipo, wxString sCodigo, 
wxString sEditora)
{
wxString sCons;

if (sTipo=='N')
  sCons = "select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons = "select e.codeditora as Código, e.editora as Editora from editora e";
  sCons += " where e.codeditora=e.codeditora";
  if (sCodigo.Len() > 0)
    sCons += " and e.codeditora=" + sCodigo;
  if (sEditora.Len() > 0)
    sCons += " and e.editora like '%%" + sEditora + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into editora(codeditora, editora) values(",
  sCodigo.c_str(),",'",sEditora.c_str(),"')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s", "update editora set editora='",
  sEditora.c_str(),"' where codeditora=",sCodigo.c_str());
else if (sTipo=='D')
  sCons = wxString::Format("%s%s", "delete from editora where codeditora=",
  sCodigo.c_str());

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Idioma(wxChar sTipo, wxString sCodigo, wxString sIdioma)
{
wxString sCons;

if (sTipo=='N')
  sCons = "select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons = "select i.codidioma as Código, i.idioma as idioma from Idioma i";
  sCons += " where i.codidioma=i.codidioma";
  if (sCodigo.Len() > 0)
    sCons += " and i.codidioma=" + sCodigo;
  if (sIdioma.Len() > 0)
    sCons += " and i.idioma like '%%" + sIdioma + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into Idioma(codidioma, idioma) values(",
  sCodigo.c_str(),",'",sIdioma.c_str(),"')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s", "update Idioma set idioma='",
  sIdioma.c_str(),"' where codidioma=",sCodigo.c_str());
else if (sTipo=='D')
  sCons = wxString::Format("%s%s", "delete from Idioma where codidioma=",
  sCodigo.c_str());

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Usuario(wxChar sTipo, wxString sLogin, wxString sSenha)
{
wxString sCons;

if (sTipo=='S')
 sCons = wxString::Format("%s%s%s%s%s", "select * from Usuario where login='", 
   sLogin.c_str(), "' and senha='", sSenha.c_str(), "'");
else if (sTipo=='U')
 sCons = wxString::Format("%s%s%s%s%s", "update Usuario set senha='",
   sSenha.c_str(), "' where login='", sLogin.c_str(), "'");

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Livro(wxChar sTipo, wxString sISBN, wxString sTitulo, 
wxString sEdicao,wxString sAnoPubli,wxString sVolume,wxString sCodEditora, 
wxString sCodIdioma,wxString sNPaginas,wxString sPreco,wxString sQtdEstoque)
{
wxString sCons;

if (sTipo=='S') {
 sCons = wxString::Format("%s%s%s%s%s%s%s", 
 "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição,",
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora,",
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma,",
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque",
 " from Livro l, editora e, idioma i",
 " where l.codeditora=e.codeditora",
 " and l.codidioma=i.codidioma");
 if (sISBN.Len() > 0)
   sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.Len() > 0)
   sCons += " and l.titulo like '%%" + sTitulo + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Livro(isbn, titulo, edicao, anopubli, codeditora,", 
  "volume, codidioma,npaginas, preco, qtdestoque) values('",
  sISBN.c_str(), "','", sTitulo.c_str(), "',", sEdicao.c_str(), ",", 
  sAnoPubli.c_str(), ",", sCodEditora.c_str(), ",",sVolume.c_str(), ",", 
  sCodIdioma.c_str(), ",", sNPaginas.c_str(), ",", sPreco.c_str(), ",", 
  sQtdEstoque.c_str(), ")");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Livro set titulo='", sTitulo.c_str(), "',edicao=", sEdicao.c_str(),
  ",anopubli=", sAnoPubli.c_str(), ",volume=", sVolume.c_str(), ",codeditora=", 
  sCodEditora.c_str(),",codidioma=", sCodIdioma.c_str(), ",npaginas=", 
  sNPaginas.c_str(), ",preco=", sPreco.c_str(),",qtdestoque=", 
  sQtdEstoque.c_str()," where isbn='", sISBN.c_str(), "'");
else if (sTipo=='D')
  sCons = wxString::Format("%s%s%s", " delete from Livro where isbn='", 
  sISBN.c_str(), "'");
else if (sTipo=='Q') {
  sCons = wxString::Format("%s%s%s%s",
  "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço,",
  "l.qtdestoque as Estoque",
  " from Livro l",
  " where l.isbn=l.isbn");
 if (sISBN.Len() > 0)
  sCons += " and l.isbn='" + sISBN + "'";
 if (sTitulo.Len() > 0)
  sCons += " and l.titulo like '%%" + sTitulo + "%%'";
}

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Cliente(wxChar sTipo, wxString sCPF,wxString sNome, 
wxString sEmail,wxString sIdentidade,wxString sSexo,wxString sTelefone, 
wxString sDtNascimento,wxString sCodEndereco,wxString sCodPais, 
wxString sCodProfissao)
{
wxString sCons;

if (sTipo=='S') {
 sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s", 
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
 if (sCPF.Len() > 0)
   sCons += " and c.cpf='" + sCPF + "'";
 if (sNome.Len() > 0)
   sCons += " and c.nome like '%%" + sNome + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "insert into Cliente(cpf, nome, email, identidade, sexo,", 
  "telefone, datanasc, codendereco, codpais, codprofissao) values('",
  sCPF.c_str(), "','", sNome.c_str(), "','", sEmail.c_str(), "','", 
  sIdentidade.c_str(), "','", sSexo.c_str(), "','", sTelefone.c_str(), "',",
  Rotinas_sepDTHR.c_str(), sDtNascimento.c_str(), Rotinas_sepDTHR.c_str(), ",", 
  sCodEndereco.c_str(), ",'", sCodPais.c_str(), "',",sCodProfissao.c_str(),")");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s",
  "update Cliente set nome='",sNome.c_str(),"',email='",sEmail.c_str(),
  "',identidade='",sIdentidade.c_str(), "',sexo='",sSexo.c_str(),"',telefone='",
  sTelefone.c_str(),"',datanasc=",Rotinas_sepDTHR.c_str(),sDtNascimento.c_str(),
  Rotinas_sepDTHR.c_str(),",codendereco=",sCodEndereco.c_str(),
  ",codpais='",sCodPais.c_str(),"',codprofissao=",sCodProfissao.c_str(),
  " where cpf='",sCPF.c_str(),"'");
else if (sTipo=='D')
  sCons = wxString::Format("%s%s%s", "delete from Cliente where cpf='", 
  sCPF.c_str(), "'");

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Endereco(wxChar sTipo, wxString sCodigo, 
wxString sLogradouro,wxString sBairro,wxString sCEP,wxString sCidade, 
wxString sEstado)
{
wxString sCons;

if (sTipo=='N')
  sCons = "select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons = wxString::Format("%s%s%s%s",
  "select e.codendereco as Código, e.logradouro as Logradouro,",
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado",
  " from Endereco e",
  " where e.codendereco=e.codendereco");
  if (sCodigo.Len() > 0)
    sCons += " and e.codendereco=" + sCodigo;
  if (sLogradouro.Len() > 0)
    sCons += " and e.logradouro like '%%" + sLogradouro + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Endereco(codendereco, logradouro, bairro, cep,", 
  "cidade, estado) values(", sCodigo.c_str(), ",'", sLogradouro.c_str(), "','", 
  sBairro.c_str(),"','", sCEP.c_str(), "','", sCidade.c_str(), "','", 
  sEstado.c_str(), "')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s%s%s", 
  "update Endereco set logradouro='",sLogradouro.c_str(), "',bairro='",
  sBairro.c_str(), "',cep='", sCEP.c_str(), "',cidade='", sCidade.c_str(), 
  "',estado='", sEstado.c_str(), "'",
  " where codendereco=", sCodigo.c_str());
else if (sTipo=='D')
  sCons = wxString::Format("%s%s", "delete from Endereco where codendereco=",
  sCodigo.c_str());

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Pais(wxChar sTipo, wxString sCodigo, wxString sPais)
{
wxString sCons;

if (sTipo=='S') {
  sCons = "select p.codpais as Código, p.pais as País from Pais p";
  sCons += " where p.codpais=p.codpais";
  if (sCodigo.Len() > 0)
    sCons += " and p.codpais='" + sCodigo + "'";
  if (sPais.Len() > 0)
    sCons += " and p.pais like '%%" + sPais + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into Pais(codpais, pais) values('",
  sCodigo.c_str(),"','",sPais.c_str(),"')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s%s%s", "update Pais set pais='",
  sPais.c_str(),"'"," where codpais='",sCodigo.c_str(),"'");
else if (sTipo=='D')
  sCons = wxString::Format("%s%s%s", "delete from Pais where codpais='",
  sCodigo.c_str(),"'");

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Profissao(wxChar sTipo, wxString sCodigo, 
wxString sProfissao)
{
wxString sCons;

if (sTipo=='N')
  sCons = "select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons = 
  "select p.codprofissao as Código, p.profissao as Profissão from Profissao p";
  sCons += " where p.codprofissao=p.codprofissao";
  if (sCodigo.Len() > 0)
    sCons += " and p.codprofissao=" + sCodigo;
  if (sProfissao.Len() > 0)
    sCons += " and p.profissao like '%%" + sProfissao + "%%'";
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into Profissao(codprofissao, profissao) values(",
  sCodigo.c_str(), ",'", sProfissao.c_str(), "')");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s", "update Profissao set profissao='",
  sProfissao.c_str(),"' where codprofissao=",sCodigo.c_str());
else if (sTipo=='D')
  sCons = wxString::Format("%s%s", "delete from Profissao where codprofissao=",
  sCodigo.c_str());

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::LivroAss(wxChar sTipo, wxString sISBN, 
wxString sCodAssunto)
{
wxString sCons;

if (sTipo=='S')
  sCons = wxString::Format("%s%s%s%s%s",
  "select la.codassunto, a.assunto from LivroAss la, Assunto a", 
  " where la.codassunto=a.codassunto", 
  " and la.isbn='", sISBN.c_str(), "'");
else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into LivroAss(isbn, codassunto) values('",
  sISBN.c_str(),"',",sCodAssunto.c_str(),")");
else if (sTipo=='D')
  sCons = wxString::Format("%s%s%s", "delete from LivroAss where isbn='",
  sISBN.c_str(),"'");

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::LivroAut(wxChar sTipo, wxString sISBN, 
wxString sCodAutor)
{
wxString sCons;

if (sTipo=='S')
  sCons = wxString::Format("%s%s%s%s%s",
  "select la.codautor, a.autor from LivroAut la, Autor a",
  " where la.codautor=a.codautor",
  " and la.isbn='", sISBN.c_str(), "'");
else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s", 
  "insert into LivroAut(isbn, codautor) values('",
  sISBN.c_str(),"',",sCodAutor.c_str(),")");
else if (sTipo=='D')
  sCons = wxString::Format("%s%s%s", "delete from LivroAut where isbn='",
  sISBN.c_str(),"'");

return sCons;
}
//---------------------------------------------------------------------------
wxString CConsultasSQL::Venda(wxChar sTipo, wxString sISBN,wxString sCPF, 
wxString sDataVenda,wxString sPrecoVenda,wxString sQtdEstoque)
{
wxString sCons;

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
    sCons = wxString::Format("%s%s%s%s",
    "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente,",
    "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  else if (sTipo=='P')
    sCons = wxString::Format("%s%s%s",
    "select sum(v.precovenda) as PreçoTotal",
    " from Venda v, Livro l, Cliente c",
    " where v.isbn=l.isbn and v.cpf=c.cpf");
  if (sISBN.Len() > 0)
    sCons += " and v.isbn='" + sISBN + "'";
  if (sCPF.Len() > 0)
    sCons += " and v.cpf='" + sCPF + "'";
  if (sDataVenda.Len() > 0)
    sCons += " and v.datavenda=" + Rotinas_sepDTHR + 
      sDataVenda + Rotinas_sepDTHR;
} else if (sTipo=='I')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s%s%s%s", 
  "insert into Venda(isbn, cpf, datavenda, precovenda) values('",
  sISBN.c_str(),"','",sCPF.c_str(),"',",
  Rotinas_sepDTHR.c_str(),sDataVenda.c_str(),Rotinas_sepDTHR.c_str(),
  ",",sPrecoVenda.c_str(),")");
else if (sTipo=='U')
  sCons = wxString::Format("%s%s%s%s%s", 
  "update Livro set qtdestoque=",sQtdEstoque.c_str(),
  " where isbn='",sISBN.c_str(),"'");
else if (sTipo=='D')
  sCons = wxString::Format("%s%s%s%s%s%s%s%s", 
  "delete from Venda where isbn='",sISBN.c_str(), "' and cpf='",sCPF.c_str(),
  "' and datavenda=",Rotinas_sepDTHR.c_str(),sDataVenda.c_str(),
  Rotinas_sepDTHR.c_str());

return sCons;
}

