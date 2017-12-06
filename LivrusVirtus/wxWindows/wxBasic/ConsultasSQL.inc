option explicit

Function ConsSQL_Assunto(sTipo, sCodigo, sAssunto)
Dim sCons = ""

If sTipo = "N" Then
  sCons = "select max(codassunto)+1 from Assunto"
ElseIf sTipo = "S" Then
  sCons = "select a.codassunto as Código, a.assunto as Assunto from Assunto a" &
  " where a.codassunto=a.codassunto"
  If sCodigo <> "" Then
     sCons = sCons & " and a.codassunto=" & sCodigo
  End If
  If sAssunto <> "" Then
     sCons = sCons & " and a.assunto like '%" & sAssunto & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Assunto(codassunto, assunto) values(" &
  sCodigo & ",'" & sAssunto & "')"
ElseIf sTipo = "U" Then
  sCons = "update Assunto set assunto='" & sAssunto & "'" &
  " where codassunto=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Assunto where codassunto=" & sCodigo
End If

return sCons
End Function

Function ConsSQL_Autor(sTipo, sCodigo, sAutor)
Dim sCons = ""

If sTipo = "N" Then
  sCons = "select max(codautor)+1 from Autor"
ElseIf sTipo = "S" Then
  sCons = "select a.codautor as Código, a.Autor as Autor from Autor a" &
  " where a.codautor=a.codautor"
  If sCodigo <> "" Then
     sCons = sCons & " and a.codautor=" & sCodigo
  End If
  If sAutor <> "" Then
     sCons = sCons & " and a.autor like '%" & sAutor & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Autor(codautor, autor) values(" &
  sCodigo & ",'" & sAutor & "')"
ElseIf sTipo = "U" Then
  sCons = "update Autor set autor='" & sAutor & "'" &
  " where codautor=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Autor where codautor=" & sCodigo
End If

return sCons
End Function

Function ConsSQL_Editora(sTipo, sCodigo, sEditora)
Dim sCons = ""

If sTipo = "N" Then
  sCons = "select max(codeditora)+1 from Editora"
ElseIf sTipo = "S" Then
  sCons = "select e.codeditora as Código, e.editora as Editora from Editora e" &
  " where e.codeditora=e.codeditora"
  If sCodigo <> "" Then
     sCons = sCons & " and e.codeditora=" & sCodigo
  End If
  If sEditora <> "" Then
     sCons = sCons & " and e.editora like '%" & sEditora & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into editora(codeditora, editora) values(" &
  sCodigo & ",'" & sEditora & "')"
ElseIf sTipo = "U" Then
  sCons = "update editora set editora='" & sEditora & "'" &
  " where codeditora=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from editora where codeditora=" & sCodigo
End If

return sCons
End Function

Function ConsSQL_Idioma(sTipo, sCodigo, sIdioma)
Dim sCons = ""

If sTipo = "N" Then
  sCons = "select max(codidioma)+1 from Idioma"
ElseIf sTipo = "S" Then
  sCons = "select i.codidioma as Código, i.idioma as idioma from Idioma i" &
  " where i.codidioma=i.codidioma"
  If sCodigo <> "" Then
     sCons = sCons & " and i.codidioma=" & sCodigo
  End If
  If sIdioma <> "" Then
     sCons = sCons & " and i.idioma like '%" & sIdioma & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Idioma(codidioma, idioma) values(" &
  sCodigo & ",'" & sIdioma & "')"
ElseIf sTipo = "U" Then
  sCons = "update Idioma set idioma='" & sIdioma & "'" &
  " where codidioma=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Idioma where codidioma=" & sCodigo
End If

return sCons
End Function

Function ConsSQL_Usuario(sTipo, sLogin, sSenha)
Dim sCons = ""

If sTipo = "S" Then
 sCons = "select * from Usuario u where u.login='" & sLogin &
  "' and u.senha='" & sSenha & "'"
ElseIf sTipo = "U" Then
 sCons = "update Usuario set senha='" & sSenha & "' where login='" & sLogin & "'"
End If

return sCons
End Function

Function ConsSQL_Livro(sTipo, sISBN, sTitulo,
sEdicao, sAnoPubli, sVolume,
sCodEditora, sCodIdioma, sNPaginas,
sPreco, sQtdEstoque)
Dim sCons = ""

If sTipo = "S" Then
 sCons = "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," &
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," &
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," &
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" &
 " from Livro l, editora e, idioma i" &
 " where l.codeditora=e.codeditora" &
 " and l.codidioma=i.codidioma"
 If sISBN <> "" Then
    sCons = sCons & " and l.isbn='" & sISBN & "'"
 End If
 If sTitulo <> "" Then
    sCons = sCons & " and l.titulo like '%" & sTitulo & "%'"
 End If
ElseIf sTipo = "I" Then
  sCons = "insert into Livro(isbn, titulo, edicao, anopubli, codeditora," &
  "volume, codidioma,npaginas, preco, qtdestoque) values('" &
  sISBN & "','" & sTitulo & "'," & sEdicao & "," & sAnoPubli & "," & sCodEditora & "," &
  sVolume & "," & sCodIdioma & "," & sNPaginas & "," & sPreco & "," & sQtdEstoque & "')"
ElseIf sTipo = "U" Then
  sCons = "update Livro set titulo='" & sTitulo & "',edicao=" & sEdicao &
  ",anopubli=" & sAnoPubli & ",volume=" & sVolume & ",codeditora=" & sCodEditora &
  ",codidioma=" & sCodIdioma & ",npaginas=" & sNPaginas & ",preco=" & sPreco &
  ",qtdestoque=" & sQtdEstoque &
  " where isbn='" & sISBN & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Livro where isbn='" & sISBN & "'"
ElseIf sTipo = "Q" Then
 sCons = "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," &
 "l.qtdestoque as Estoque" &
 " from Livro l" &
 " where l.isbn=l.isbn"
 If sISBN <> "" Then
    sCons = sCons & " and l.isbn='" & sISBN & "'"
 End If
 If sTitulo <> "" Then
    sCons = sCons & " and l.titulo like '%" & sTitulo & "%'"
 End If
End If

return sCons
End Function

Function ConsSQL_Cliente(sTipo, sCPF, sNome,
sEmail, sIdentidade, sSexo, sTelefone,
sDtNascimento, sCodEndereco, sCodPais,
sCodProfissao)
Dim sCons = ""

If sTipo = "S" Then
 sCons = "select c.cpf as CPF, c.nome as Nome, c.email as Email," &
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," &
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," &
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," &
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís," &
 "p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão" &
 " from Cliente c, endereco e, pais p, profissao r" &
 " where c.codendereco=e.codendereco" &
 " and c.codpais=p.codpais" &
 " and c.codprofissao=r.codprofissao"
 If sCPF <> "" Then
    sCons = sCons & " and c.cpf='" & sCPF & "'"
 End If
 If sNome <> "" Then
    sCons = sCons & " and c.nome like '%" & sNome & "%'"
 End If
ElseIf sTipo = "I" Then
  sCons = "insert into Cliente(cpf, nome, email, identidade, sexo," &
  "telefone, datanasc, codendereco, codpais, codprofissao) values('" &
  sCPF & "','" & sNome & "','" & sEmail & "','" & sIdentidade & "','" & sSexo & "','" &
  sTelefone & "'," & sepDTHR & sDtNascimento & sepDTHR &
  "," & sCodEndereco & ",'" & sCodPais & "'," &
  sCodProfissao & ")"
ElseIf sTipo = "U" Then
  sCons = "update Cliente set nome='" & sNome & "',email='" & sEmail &
  "',identidade='" & sIdentidade & "',sexo='" & sSexo & "',telefone='" & sTelefone &
  "',datanasc=" & sepDTHR & sDtNascimento & sepDTHR &
  ",codendereco=" & sCodEndereco &
  ",copais='" & sCodPais & "',codprofissao=" & sCodProfissao &
  " where cpf='" & sCPF & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Cliente where cpf='" & sCPF & "'"
End If

return sCons
End Function

Function ConsSQL_Endereco(sTipo, sCodigo, sLogradouro,
sBairro, sCEP, sCidade, sEstado)
Dim sCons = ""

If sTipo = "N" Then
  sCons = "select max(codendereco)+1 from Endereco"
ElseIf sTipo = "S" Then
  sCons = "select e.codendereco as Código, e.logradouro as Logradouro," &
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" &
  " from Endereco e" &
  " where e.codendereco=e.codendereco"
  If sCodigo <> "" Then
     sCons = sCons & " and e.codendereco=" & sCodigo
  End If
  If sLogradouro <> "" Then
     sCons = sCons & " and e.logradouro like '%" & sLogradouro & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Endereco(codendereco, logradouro, bairro, cep," &
  "cidade, estado) values(" & sCodigo & ",'" & sLogradouro & "','" & sBairro &
  "','" & sCEP & "','" & sCidade & "','" & sEstado & "')"
ElseIf sTipo = "U" Then
  sCons = "update Endereco set logradouro='" & sLogradouro & "',bairro='" &
  sBairro & "',cep='" & sCEP & "',cidade='" & sCidade & "',estado='" & sEstado & "'" &
  " where codendereco=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Endereco where codendereco=" & sCodigo
End If

return sCons
End Function

Function ConsSQL_Pais(sTipo, sCodigo, sPais)
Dim sCons = ""

If sTipo = "S" Then
  sCons = "select p.codpais as Código, p.pais as País from Pais p" &
  " where p.codpais=p.codpais"
  If sCodigo <> "" Then
     sCons = sCons & " and p.codpais='" & sCodigo & "'"
  End If
  If sPais <> "" Then
     sCons = sCons & " and p.pais like '%" & sPais & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Pais(codpais, pais) values('" &
  sCodigo & "','" & sPais & "')"
ElseIf sTipo = "U" Then
  sCons = "update Pais set pais='" & sPais & "'" &
  " where codpais='" & sCodigo & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Pais where codpais='" & sCodigo & "'"
End If

return sCons
End Function

Function ConsSQL_Profissao(sTipo, sCodigo, sProfissao)
Dim sCons = ""

If sTipo = "N" Then
  sCons = "select max(codprofissao)+1 from Profissao"
ElseIf sTipo = "S" Then
  sCons = "select p.codprofissao as Código, p.profissao as Profissão from Profissao p" &
  " where p.codprofissao=p.codprofissao"
  If sCodigo <> "" Then
     sCons = sCons & " and p.codprofissao=" & sCodigo
  End If
  If sProfissao <> "" Then
     sCons = sCons & " and p.profissao like '%" & sProfissao & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Profissao(codprofissao, profissao) values(" &
  sCodigo & ",'" & sProfissao & "')"
ElseIf sTipo = "U" Then
  sCons = "update Profissao set profissao='" & sProfissao & "'" &
  " where codprofissao=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Profissao where codprofissao=" & sCodigo
End If

return sCons
End Function

Function ConsSQL_LivroAss(sTipo, sISBN, sCodAssunto)
Dim sCons = ""

If sTipo = "S" Then
  sCons = "select la.codassunto, a.assunto from LivroAss la, Assunto a" &
  " where la.codassunto=a.codassunto" &
  " and la.isbn='" & sISBN & "'"
ElseIf sTipo = "I" Then
  sCons = "insert into LivroAss(isbn, codassunto) values('" &
  sISBN & "'," & sCodAssunto & "')"
ElseIf sTipo = "D" Then
  sCons = "delete from LivroAss where isbn='" & sISBN & "'"
End If

return sCons
End Function

Function ConsSQL_LivroAut(sTipo, sISBN, sCodAutor)
Dim sCons = ""

If sTipo = "S" Then
  sCons = "select la.codautor, a.autor from LivroAut la, Autor a" &
  " where la.codautor=a.codautor" &
  " and la.isbn='" & sISBN & "'"
ElseIf sTipo = "I" Then
  sCons = "insert into LivroAut(isbn, codautor) values('" &
  sISBN & "'," & sCodAutor & ")"
ElseIf sTipo = "D" Then
  sCons = "delete from LivroAut where isbn='" & sISBN & "'"
End If

return sCons
End Function

Function ConsSQL_Venda(sTipo, sISBN, sCPF,
sDataVenda, sPrecoVenda, sQtdEstoque)
Dim sCons = ""

If (sTipo = "S") Or (sTipo = "P") Then
  If sTipo = "S" Then
     sCons = "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," &
     "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" &
     " from Venda v, Livro l, Cliente c" &
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  ElseIf sTipo = "P" Then
     sCons = "select sum(l.preco) as PreçoTotal" &
     " from Venda v, Livro l, Cliente c" &
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  End If
  If sISBN <> "" Then
     sCons = sCons & " and v.isbn='" & sISBN & "'"
  End If
  If sCPF <> "" Then
     sCons = sCons & " and v.cpf='" & sCPF & "'"
  End If
  If sDataVenda <> "" Then
     sCons = sCons & " and v.datavenda=" &
     sepDTHR & sDataVenda & sepDTHR
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Venda(isbn, cpf, datavenda, precovenda) values('" &
  sISBN & "','" & sCPF & "'," & sepDTHR & sDataVenda &
  sepDTHR & "," & sPrecoVenda & ")"
ElseIf sTipo = "U" Then
  sCons = "update Livro set qtdestoque=" & sQtdEstoque + " where isbn='" & sISBN & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Venda where isbn='" & sISBN & "'" &
  " and cpf = '" & sCPF & "' and datavenda = " &
  sepDTHR & sDataVenda & sepDTHR
End If

return sCons
End Function
