package  Livrus;

public class ConsultasSQL {
  public static ConsultasSQL ConsSQL;

  public ConsultasSQL() {
    super();
  }
//---------------------------------------------------------------------------
public String Assunto(char sTipo, String sCodigo, String sAssunto)
{
String sCons="";

if (sTipo=='N')
  sCons="select max(codassunto)+1 from Assunto";
else if (sTipo=='S') {
  sCons="select a.codassunto as C�digo, a.assunto as Assunto from Assunto a" +
  " where a.codassunto=a.codassunto";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and a.codassunto="+sCodigo;
  if (sAssunto.equals("")==false)
	 sCons=sCons+" and a.assunto like '%"+sAssunto+"%'";
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
public String Autor(char sTipo, String sCodigo, String sAutor)
{
String sCons="";

if (sTipo=='N')
  sCons="select max(codautor)+1 from Autor";
else if (sTipo=='S') {
  sCons="select a.codautor as C�digo, a.Autor as Autor from Autor a" +
  " where a.codautor=a.codautor";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and a.codautor="+sCodigo;
  if (sAutor.equals("")==false)
	 sCons=sCons+" and a.autor like '%"+sAutor+"%'";
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
public String Editora(char sTipo, String sCodigo, String sEditora)
{
String sCons="";

if (sTipo=='N')
  sCons="select max(codeditora)+1 from Editora";
else if (sTipo=='S') {
  sCons="select e.codeditora as C�digo, e.editora as Editora from editora e" +
  " where e.codeditora=e.codeditora";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and e.codeditora="+sCodigo;
  if (sEditora.equals("")==false)
	 sCons=sCons+" and e.editora like '%"+sEditora+"%'";
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
public String Idioma(char sTipo, String sCodigo, String sIdioma)
{
String sCons="";

if (sTipo=='N')
  sCons="select max(codidioma)+1 from Idioma";
else if (sTipo=='S') {
  sCons="select i.codidioma as C�digo, i.idioma as idioma from Idioma i" +
  " where i.codidioma=i.codidioma";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and i.codidioma="+sCodigo;
  if (sIdioma.equals("")==false)
	 sCons=sCons+" and i.idioma like '%"+sIdioma+"%'";
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
public String Usuario(char sTipo, String sLogin, String sSenha)
{
String sCons="";

if (sTipo=='S')
 sCons="select * from Usuario where login='"+sLogin+"' and senha='"+sSenha+"'";
else if (sTipo=='U')
 sCons="update Usuario set senha='"+sSenha+"' where login='"+sLogin+"'";

return sCons;
}
//---------------------------------------------------------------------------
public String Livro(char sTipo, String sISBN, String sTitulo, String sEdicao,
String sAnoPubli,String sVolume,String sCodEditora, String sCodIdioma,
String sNPaginas,String sPreco,String sQtdEstoque)
{
String sCons="";

if (sTipo=='S') {
 sCons="select l.isbn as ISBN, l.titulo as T�tulo, l.edicao as Edi��o," +
 "l.anopubli as AnoPublica��o, l.volume as Volume,l.codeditora as CodEditora," +
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," +
 "l.npaginas as NumPaginas, l.preco as Pre�o, l.qtdestoque as Estoque" +
 " from Livro l, editora e, idioma i" +
 " where l.codeditora=e.codeditora" +
 " and l.codidioma=i.codidioma";
 if (sISBN.equals("")==false)
	sCons=sCons+" and l.isbn='"+sISBN+"'";
 if (sTitulo.equals("")==false)
	sCons=sCons+" and l.titulo like '%"+sTitulo+"%'";
} else if (sTipo=='I')
  sCons="insert into Livro(isbn, titulo, edicao, anopubli, codeditora," +
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
 sCons="select l.isbn as ISBN, l.titulo as T�tulo, l.preco as Pre�o," +
 "l.qtdestoque as Estoque" +
 " from Livro l" +
 " where l.isbn=l.isbn";
 if (sISBN.equals("")==false)
	sCons=sCons+" and l.isbn='"+sISBN+"'";
 if (sTitulo.equals("")==false)
	sCons=sCons+" and l.titulo like '%"+sTitulo+"%'";
}

return sCons;
}
//---------------------------------------------------------------------------
public String Cliente(char sTipo, String sCPF,String sNome, String sEmail,
String sIdentidade,String sSexo,String sTelefone, String sDtNascimento,
String sCodEndereco,String sCodPais, String sCodProfissao)
{
String sCons="";

if (sTipo=='S') {
 sCons="select c.cpf as CPF, c.nome as Nome, c.email as Email," +
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," +
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," +
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," +
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPa�s," +
 "p.pais as Pa�s, c.codprofissao as CodProfissao,r.profissao as Profiss�o" +
 " from Cliente c, endereco e, pais p, profissao r" +
 " where c.codendereco=e.codendereco" +
 " and c.codpais=p.codpais" +
 " and c.codprofissao=r.codprofissao";
 if (sCPF.equals("")==false)
	sCons=sCons+" and c.cpf='"+sCPF+"'";
 if (sNome.equals("")==false)
	sCons=sCons+" and c.nome like '%"+sNome+"%'";
} else if (sTipo=='I')
  sCons="insert into Cliente(cpf, nome, email, identidade, sexo," +
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
public String Endereco(char sTipo, String sCodigo, String sLogradouro,
String sBairro,String sCEP,String sCidade, String sEstado)
{
String sCons="";

if (sTipo=='N')
  sCons="select max(codendereco)+1 from Endereco";
else if (sTipo=='S') {
  sCons="select e.codendereco as C�digo, e.logradouro as Logradouro," +
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" +
  " from Endereco e" +
  " where e.codendereco=e.codendereco";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and e.codendereco="+sCodigo;
  if (sLogradouro.equals("")==false)
	 sCons=sCons+" and e.logradouro like '%"+sLogradouro+"%'";
} else if (sTipo=='I')
  sCons="insert into Endereco(codendereco, logradouro, bairro, cep," +
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
public String Pais(char sTipo, String sCodigo, String sPais)
{
String sCons="";

if (sTipo=='S') {
  sCons="select p.codpais as C�digo, p.pais as Pa�s from Pais p" +
  " where p.codpais=p.codpais";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and p.codpais='"+sCodigo+"'";
  if (sPais.equals("")==false)
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
public String Profissao(char sTipo, String sCodigo, String sProfissao)
{
String sCons="";

if (sTipo=='N')
  sCons="select max(codprofissao)+1 from Profissao";
else if (sTipo=='S') {
  sCons="select p.codprofissao as C�digo, p.profissao as Profiss�o from Profissao p" +
  " where p.codprofissao=p.codprofissao";
  if (sCodigo.equals("")==false)
	 sCons=sCons+" and p.codprofissao="+sCodigo;
  if (sProfissao.equals("")==false)
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
public String LivroAss(char sTipo, String sISBN, String sCodAssunto)
{
String sCons="";

if (sTipo=='S')
  sCons="select la.codassunto, a.assunto from LivroAss la, Assunto a" +
  " where la.codassunto=a.codassunto" +
  " and la.isbn='"+sISBN+"'";
else if (sTipo=='I')
  sCons="insert into LivroAss(isbn, codassunto) values('"+
  sISBN+"',"+sCodAssunto+")";
else if (sTipo=='D')
  sCons="delete from LivroAss where isbn='"+sISBN+"'";

return sCons;
}
//---------------------------------------------------------------------------
public String LivroAut(char sTipo, String sISBN, String sCodAutor)
{
String sCons="";

if (sTipo=='S')
  sCons="select la.codautor, a.autor from LivroAut la, Autor a" +
  " where la.codautor=a.codautor" +
  " and la.isbn='"+sISBN+"'";
else if (sTipo=='I')
  sCons="insert into LivroAut(isbn, codautor) values('"+
  sISBN+"',"+sCodAutor+")";
else if (sTipo=='D')
  sCons="delete from LivroAut where isbn='"+sISBN+"'";

return sCons;
}
//---------------------------------------------------------------------------
public String Venda(char sTipo, String sISBN,String sCPF, String sDataVenda,
String sPrecoVenda,String sQtdEstoque)
{
String sCons="";

if ((sTipo=='S') || (sTipo=='P')) {
  if (sTipo=='S')
	 sCons="select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," +
	 "v.isbn as ISBN,l.Titulo as Livro, l.preco as Pre�o" +
	 " from Venda v, Livro l, Cliente c" +
	 " where v.isbn=l.isbn and v.cpf=c.cpf";
  else if (sTipo=='P')
	 sCons="select sum(l.preco) as Pre�oTotal" +
	 " from Venda v, Livro l, Cliente c" +
	 " where v.isbn=l.isbn and v.cpf=c.cpf";
  if (sISBN.equals("")==false)
	 sCons=sCons+" and v.isbn='"+sISBN+"'";
  if (sCPF.equals("")==false)
	 sCons=sCons+" and v.cpf='"+sCPF+"'";
  if (sDataVenda.equals("")==false)
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

}

