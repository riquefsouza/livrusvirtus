DEFINE CLASS ConsultasSql AS CUSTOM
*------------------------------------------------------------------------------------
Function Assunto(sTipo, sCodigo, sAssunto)
Local sCons

If sTipo = "N" 
  sCons = "select (max(codassunto)+1) as Codigo from Assunto"
EndIf
If sTipo = "S" 
  sCons = "select a.codassunto as Codigo, a.assunto as Assunto from Assunto a" +; 
  " where a.codassunto=a.codassunto"
  If sCodigo <> "" 
     sCons = sCons + " and a.codassunto=" + sCodigo
  EndIf
  If sAssunto <> "" 
     sCons = sCons + " and a.assunto like '%" + sAssunto + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Assunto(codassunto, assunto) values(" +;
  sCodigo + ",'" + sAssunto + "')"
EndIf
If sTipo = "U" 
  sCons = "update Assunto set assunto='" + sAssunto + "'" +;
  " where codassunto=" + sCodigo
EndIf
If sTipo = "D" 
  sCons = "delete from Assunto where codassunto=" + sCodigo
EndIf

return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Autor(sTipo, sCodigo, sAutor)
Local sCons

If sTipo = "N" 
  sCons = "select (max(codautor)+1) as Codigo from Autor"
EndIf
If sTipo = "S" 
  sCons = "select a.codautor as Codigo, a.Autor as Autor from Autor a" +;
  " where a.codautor=a.codautor"
  If sCodigo <> "" 
     sCons = sCons + " and a.codautor=" + sCodigo
  EndIf
  If sAutor <> "" 
     sCons = sCons + " and a.autor like '%" + sAutor + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Autor(codautor, autor) values(" +;
  sCodigo + ",'" + sAutor + "')"
EndIf
If sTipo = "U" 
  sCons = "update Autor set autor='" + sAutor + "'" +;
  " where codautor=" + sCodigo
EndIf
If sTipo = "D" 
  sCons = "delete from Autor where codautor=" + sCodigo
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Editora(sTipo, sCodigo, sEditora)
Local sCons

If sTipo = "N" 
  sCons = "select (max(codeditora)+1) as Codigo from Editora"
EndIf
If sTipo = "S" 
  sCons = "select e.codeditora as Codigo, e.editora as Editora from Editora e" +;
  " where e.codeditora=e.codeditora"
  If sCodigo <> "" 
     sCons = sCons + " and e.codeditora=" + sCodigo
  EndIf
  If sEditora <> "" 
     sCons = sCons + " and e.editora like '%" + sEditora + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into editora(codeditora, editora) values(" +;
  sCodigo + ",'" + sEditora + "')"
EndIf
If sTipo = "U" 
  sCons = "update editora set editora='" + sEditora + "'" +;
  " where codeditora=" + sCodigo
EndIf
If sTipo = "D" 
  sCons = "delete from editora where codeditora=" + sCodigo
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Idioma(sTipo, sCodigo, sIdioma)
Local sCons

If sTipo = "N" 
  sCons = "select (max(codidioma)+1) as Codigo from Idioma"
EndIf
If sTipo = "S" 
  sCons = "select i.codidioma as Codigo, i.idioma as idioma from Idioma i" +;
  " where i.codidioma=i.codidioma"
  If sCodigo <> "" 
     sCons = sCons + " and i.codidioma=" + sCodigo
  EndIf
  If sIdioma <> "" 
     sCons = sCons + " and i.idioma like '%" + sIdioma + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Idioma(codidioma, idioma) values(" +;
  sCodigo + ",'" + sIdioma + "')"
EndIf
If sTipo = "U" 
  sCons = "update Idioma set idioma='" + sIdioma + "'" +;
  " where codidioma=" + sCodigo
EndIf
If sTipo = "D" 
  sCons = "delete from Idioma where codidioma=" + sCodigo
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
FUNCTION Usuario(sTipo, sLogin, sSenha)
Local sCons

If sTipo = "S" 
 sCons = "select * from Usuario u where u.login='" + sLogin +;
  "' and u.senha='" + sSenha + "'"
Endif
If sTipo = "U"
 sCons = "update Usuario set senha='" + sSenha + "' where login='" + sLogin + "'"
EndIf

RETURN sCons
ENDFUNC
*------------------------------------------------------------------------------------
Function Livro(sTipo, sISBN, sTitulo, sEdicao, sAnoPubli,;
    sVolume, sCodEditora, sCodIdioma, sNPaginas, sPreco, sQtdEstoque)
Local sCons

If sTipo = "S" 
 sCons = "select l.isbn as ISBN, l.titulo as Titulo, l.edicao as Edicao," +;
 "l.anopubli as AnoPublicacao, l.volume as Volume,l.codeditora as CodEditora," +;
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," +;
 "l.npaginas as NumPaginas, l.preco as Preco, l.qtdestoque as QtdEstoque" +;
 " from Livro l, editora e, idioma i" +;
 " where l.codeditora=e.codeditora" +;
 " and l.codidioma=i.codidioma"
 If sISBN <> "" 
    sCons = sCons + " and l.isbn='" + sISBN + "'"
 EndIf
 If sTitulo <> "" 
    sCons = sCons + " and l.titulo like '%" + sTitulo + "%'"
 EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Livro(isbn, titulo, edicao, anopubli, codeditora," +;
  "volume, codidioma,npaginas, preco, qtdestoque) values('" +;
  sISBN + "','" + sTitulo + "'," + sEdicao + "," + sAnoPubli + "," + sCodEditora + "," +;
  sVolume + "," + sCodIdioma + "," + sNPaginas + "," + sPreco + "," + sQtdEstoque + ")"
EndIf
If sTipo = "U" 
  sCons = "update Livro set titulo='" + sTitulo + "',edicao=" + sEdicao +;
  ",anopubli=" + sAnoPubli + ",volume=" + sVolume + ",codeditora=" + sCodEditora +;
  ",codidioma=" + sCodIdioma + ",npaginas=" + sNPaginas + ",preco=" + sPreco +;
  ",qtdestoque=" + sQtdEstoque +;
  " where isbn='" + sISBN + "'"
EndIf
If sTipo = "D" 
  sCons = "delete from Livro where isbn='" + sISBN + "'"
EndIf
If sTipo = "Q" 
 sCons = "select l.isbn as ISBN, l.titulo as Titulo, l.preco as Preco," +;
 "l.qtdestoque as QtdEstoque" +;
 " from Livro l" +;
 " where l.isbn=l.isbn"
 If sISBN <> "" 
    sCons = sCons + " and l.isbn='" + sISBN + "'"
 EndIf
 If sTitulo <> "" 
    sCons = sCons + " and l.titulo like '%" + sTitulo + "%'"
 EndIf
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Cliente(sTipo, sCPF, sNome, sEmail, sIdentidade, sSexo,;
sTelefone, sDtNascimento, sCodEndereco, sCodPais, sCodProfissao)
Local sCons

If sTipo = "S" 
 sCons = "select c.cpf as CPF, c.nome as Nome, c.email as Email," +;
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," +;
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," +;
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," +;
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPais," +;
 "p.pais as Pais, c.codprofissao as CodProfissao,r.profissao as Profissao" +;
 " from Cliente c, endereco e, pais p, profissao r" +;
 " where c.codendereco=e.codendereco" +;
 " and c.codpais=p.codpais" +;
 " and c.codprofissao=r.codprofissao"
 If sCPF <> "" 
    sCons = sCons + " and c.cpf='" + sCPF + "'"
 EndIf
 If sNome <> "" 
    sCons = sCons + " and c.nome like '%" + sNome + "%'"
 EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Cliente(cpf, nome, email, identidade, sexo," +;
  "telefone, datanasc, codendereco, codpais, codprofissao) values('" +;
  sCPF + "','" + sNome + "','" + sEmail + "','" + sIdentidade + "','" + sSexo + "','" +;
  sTelefone + "','" + sDtNascimento + "'," + sCodEndereco + ",'" + sCodPais + "'," +;
  sCodProfissao + ")"
EndIf
If sTipo = "U" 
  sCons = "update Cliente set nome='" + sNome + "',email='" + sEmail +;
  "',identidade=" + sIdentidade + "',sexo='" + sSexo + "',telefone='" + sTelefone +;
  "',datanasc='" + sDtNascimento + "',codendereco=" + sCodEndereco +;
  ",copais='" + sCodPais + "',codprofissao=" + sCodProfissao +;
  " where cpf='" + sCPF + "'"
EndIf
If sTipo = "D" 
  sCons = "delete from Cliente where cpf='" + sCPF + "'"
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Endereco(sTipo, sCodigo, sLogradouro, sBairro,;
                                sCEP, sCidade, sEstado)
Local sCons

If sTipo = "N" 
  sCons = "select (max(codendereco)+1) as Codigo from Endereco"
EndIf
If sTipo = "S" 
  sCons = "select e.codendereco as Codigo, e.logradouro as Logradouro," +;
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" +;
  " from Endereco e" +;
  " where e.codendereco=e.codendereco"
  If sCodigo <> "" 
     sCons = sCons + " and e.codendereco=" + sCodigo
  EndIf
  If sLogradouro <> "" 
     sCons = sCons + " and e.logradouro like '%" + sLogradouro + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Endereco(codendereco, logradouro, bairro, cep," +;
  "cidade, estado) values(" + sCodigo + ",'" + sLogradouro + "','" + sBairro +;
  "','" + sCEP + "','" + sCidade + "','" + sEstado + "')"
EndIf
If sTipo = "U" 
  sCons = "update Endereco set logradouro='" + sLogradouro + "',bairro='" +;
  sBairro + "',cep='" + sCEP + "',cidade='" + sCidade + "',estado='" + sEstado + "'" +;
  " where codendereco=" + sCodigo
EndIf
If sTipo = "D" 
  sCons = "delete from Endereco where codendereco=" + sCodigo
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Pais(sTipo, sCodigo, sPais)
Local sCons

If sTipo = "S" 
  sCons = "select p.codpais as Codigo, p.pais as Pais from Pais p" +;
  " where p.codpais=p.codpais"
  If sCodigo <> "" 
     sCons = sCons + " and p.codpais='" + sCodigo + "'"
  EndIf
  If sPais <> "" 
     sCons = sCons + " and p.pais like '%" + sPais + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Pais(codpais, pais) values('" +;
  sCodigo + "','" + sPais + "')"
EndIf
If sTipo = "U" 
  sCons = "update Pais set pais='" + sPais + "'" +;
  " where codpais='" + sCodigo + "'"
EndIf
If sTipo = "D" 
  sCons = "delete from Pais where codpais='" + sCodigo + "'"
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Profissao(sTipo, sCodigo, sProfissao)
Local sCons

If sTipo = "N" 
  sCons = "select (max(codprofissao)+1) as Codigo from Profissao"
EndIf
If sTipo = "S" 
  sCons = "select p.codprofissao as Codigo, p.profissao as Profissao from Profissao p" +;
  " where p.codprofissao=p.codprofissao"
  If sCodigo <> "" 
     sCons = sCons + " and p.codprofissao=" + sCodigo
  EndIf
  If sProfissao <> "" 
     sCons = sCons + " and p.profissao like '%" + sProfissao + "%'"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Profissao(codprofissao, profissao) values(" +;
  sCodigo + ",'" + sProfissao + "')"
EndIf
If sTipo = "U" 
  sCons = "update Profissao set profissao='" + sProfissao + "'" +;
  " where codprofissao=" + sCodigo
EndIf
If sTipo = "D" 
  sCons = "delete from Profissao where codprofissao=" + sCodigo
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function LivroAss(sTipo, sISBN, sCodAssunto)
Local sCons

If sTipo = "S" 
  sCons = "select la.codassunto, a.assunto from LivroAss la, Assunto a" +;
  " where la.codassunto=a.codassunto" +;
  " and la.isbn='" + sISBN + "'"
EndIf
If sTipo = "I" 
  sCons = "insert into LivroAss(isbn, codassunto) values('" +;
  sISBN + "'," + sCodAssunto + ")"
EndIf
If sTipo = "D" 
  sCons = "delete from LivroAss where isbn='" + sISBN + "'"
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function LivroAut(sTipo, sISBN, sCodAutor)
Local sCons

If sTipo = "S" 
  sCons = "select la.codautor, a.autor from LivroAut la, Autor a" +;
  " where la.codautor=a.codautor" +;
  " and la.isbn='" + sISBN + "'"
EndIf
If sTipo = "I" 
  sCons = "insert into LivroAut(isbn, codautor) values('" +;
  sISBN + "'," + sCodAutor + ")"
EndIf
If sTipo = "D" 
  sCons = "delete from LivroAut where isbn='" + sISBN + "'"
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
Function Venda(sTipo, sISBN, sCPF, sDataVenda,;
                             sPrecoVenda, sQtdEstoque)
Local sCons

If (sTipo = "S") Or (sTipo = "P") 
  If sTipo = "S" 
     sCons = "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," +;
     "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preco" +;
     " from Venda v, Livro l, Cliente c" +;
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  EndIf
  If sTipo = "P" 
     sCons = "select sum(l.preco) as PrecoTotal" +;
     " from Venda v, Livro l, Cliente c" +;
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  EndIf
  If sISBN <> "" 
     sCons = sCons + " and v.isbn='" + sISBN + "'"
  EndIf
  If sCPF <> "" 
     sCons = sCons + " and v.cpf='" + sCPF + "'"
  EndIf
  If sDataVenda <> "" 
     sCons = sCons + " and v.datavenda=CDate('" + sDataVenda + "')"
  EndIf
EndIf
If sTipo = "I" 
  sCons = "insert into Venda(isbn, cpf, datavenda, precovenda) values('" +;
  sISBN + "','" + sCPF + "','" + sDataVenda + "'," + sPrecoVenda + ")"
EndIf
If sTipo = "U" 
  sCons = "update Livro set qtdestoque=" + sQtdEstoque + " where isbn='" + sISBN + "'"
EndIf
If sTipo = "D" 
  sCons = "delete from Venda where isbn='" + sISBN + "'" +;
  " and cpf = '" + sCPF + "' and datavenda=CDate('" + sDataVenda + "')"
EndIf

Return sCons
EndFunc
*------------------------------------------------------------------------------------
ENDDEFINE
