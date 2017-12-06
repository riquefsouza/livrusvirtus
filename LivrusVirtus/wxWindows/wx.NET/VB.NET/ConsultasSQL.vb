Imports System

Namespace Livrus

Public Class ConsultasSQL

public Shared ConsSQL as ConsultasSQL

Public Sub New()
    MyBase.New()
End Sub

Public Function Assunto(sTipo As String, sCodigo As String, sAssunto As String) As String
Dim sCons As String

If sTipo = "N" Then
  sCons = "select max(codassunto)+1 from Assunto"
ElseIf sTipo = "S" Then
  sCons = "select a.codassunto as Código, a.assunto as Assunto from Assunto a" & _
  " where a.codassunto=a.codassunto"
  If sCodigo <> "" Then
     sCons = sCons & " and a.codassunto=" & sCodigo
  End If
  If sAssunto <> "" Then
     sCons = sCons & " and a.assunto like '%" & sAssunto & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Assunto(codassunto, assunto) values(" & _
  sCodigo & ",'" & sAssunto & "')"
ElseIf sTipo = "U" Then
  sCons = "update Assunto set assunto='" & sAssunto & "'" & _
  " where codassunto=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Assunto where codassunto=" & sCodigo
End If

Assunto = sCons
End Function

Function Autor(sTipo As String, sCodigo As String, sAutor As String) As String
Dim sCons As String

If sTipo = "N" Then
  sCons = "select max(codautor)+1 from Autor"
ElseIf sTipo = "S" Then
  sCons = "select a.codautor as Código, a.Autor as Autor from Autor a" & _
  " where a.codautor=a.codautor"
  If sCodigo <> "" Then
     sCons = sCons & " and a.codautor=" & sCodigo
  End If
  If sAutor <> "" Then
     sCons = sCons & " and a.autor like '%" & sAutor & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Autor(codautor, autor) values(" & _
  sCodigo & ",'" & sAutor & "')"
ElseIf sTipo = "U" Then
  sCons = "update Autor set autor='" & sAutor & "'" & _
  " where codautor=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Autor where codautor=" & sCodigo
End If

Autor = sCons
End Function

Function Editora(sTipo As String, sCodigo As String, sEditora As String) As String
Dim sCons As String

If sTipo = "N" Then
  sCons = "select max(codeditora)+1 from Editora"
ElseIf sTipo = "S" Then
  sCons = "select e.codeditora as Código, e.editora as Editora from Editora e" & _
  " where e.codeditora=e.codeditora"
  If sCodigo <> "" Then
     sCons = sCons & " and e.codeditora=" & sCodigo
  End If
  If sEditora <> "" Then
     sCons = sCons & " and e.editora like '%" & sEditora & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into editora(codeditora, editora) values(" & _
  sCodigo & ",'" & sEditora & "')"
ElseIf sTipo = "U" Then
  sCons = "update editora set editora='" & sEditora & "'" & _
  " where codeditora=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from editora where codeditora=" & sCodigo
End If

Editora = sCons
End Function

Function Idioma(sTipo As String, sCodigo As String, sIdioma As String) As String
Dim sCons As String

If sTipo = "N" Then
  sCons = "select max(codidioma)+1 from Idioma"
ElseIf sTipo = "S" Then
  sCons = "select i.codidioma as Código, i.idioma as idioma from Idioma i" & _
  " where i.codidioma=i.codidioma"
  If sCodigo <> "" Then
     sCons = sCons & " and i.codidioma=" & sCodigo
  End If
  If sIdioma <> "" Then
     sCons = sCons & " and i.idioma like '%" & sIdioma & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Idioma(codidioma, idioma) values(" & _
  sCodigo & ",'" & sIdioma & "')"
ElseIf sTipo = "U" Then
  sCons = "update Idioma set idioma='" & sIdioma & "'" & _
  " where codidioma=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Idioma where codidioma=" & sCodigo
End If

Idioma = sCons
End Function

Public Function Usuario(sTipo As String, sLogin As String, sSenha As String) As String
Dim sCons As String

If sTipo = "S" Then
 sCons = "select * from Usuario u where u.login='" & sLogin & _
  "' and u.senha='" & sSenha & "'"
ElseIf sTipo = "U" Then
 sCons = "update Usuario set senha='" & sSenha & "' where login='" & sLogin & "'"
End If

Usuario = sCons
End Function

Function Livro(sTipo As String, sISBN As String, sTitulo As String, _
sEdicao As String, sAnoPubli As String, sVolume As String, _
sCodEditora As String, sCodIdioma As String, sNPaginas As String, _
sPreco As String, sQtdEstoque As String) As String
Dim sCons As String

If sTipo = "S" Then
 sCons = "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," & _
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," & _
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," & _
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" & _
 " from Livro l, editora e, idioma i" & _
 " where l.codeditora=e.codeditora" & _
 " and l.codidioma=i.codidioma"
 If sISBN <> "" Then
    sCons = sCons & " and l.isbn='" & sISBN & "'"
 End If
 If sTitulo <> "" Then
    sCons = sCons & " and l.titulo like '%" & sTitulo & "%'"
 End If
ElseIf sTipo = "I" Then
  sCons = "insert into Livro(isbn, titulo, edicao, anopubli, codeditora," & _
  "volume, codidioma,npaginas, preco, qtdestoque) values('" & _
  sISBN & "','" & sTitulo & "'," & sEdicao & "," & sAnoPubli & "," & sCodEditora & "," & _
  sVolume & "," & sCodIdioma & "," & sNPaginas & "," & sPreco & "," & sQtdEstoque & "')"
ElseIf sTipo = "U" Then
  sCons = "update Livro set titulo='" & sTitulo & "',edicao=" & sEdicao & _
  ",anopubli=" & sAnoPubli & ",volume=" & sVolume & ",codeditora=" & sCodEditora & _
  ",codidioma=" & sCodIdioma & ",npaginas=" & sNPaginas & ",preco=" & sPreco & _
  ",qtdestoque=" & sQtdEstoque & _
  " where isbn='" & sISBN & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Livro where isbn='" & sISBN & "'"
ElseIf sTipo = "Q" Then
 sCons = "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," & _
 "l.qtdestoque as Estoque" & _
 " from Livro l" & _
 " where l.isbn=l.isbn"
 If sISBN <> "" Then
    sCons = sCons & " and l.isbn='" & sISBN & "'"
 End If
 If sTitulo <> "" Then
    sCons = sCons & " and l.titulo like '%" & sTitulo & "%'"
 End If
End If

Livro = sCons
End Function

Function Cliente(sTipo As String, sCPF As String, sNome As String, _
sEmail As String, sIdentidade As String, sSexo As String, sTelefone As String, _
sDtNascimento As String, sCodEndereco As String, sCodPais As String, _
sCodProfissao As String) As String
Dim sCons As String

If sTipo = "S" Then
 sCons = "select c.cpf as CPF, c.nome as Nome, c.email as Email," & _
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," & _
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," & _
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," & _
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís," & _
 "p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão" & _
 " from Cliente c, endereco e, pais p, profissao r" & _
 " where c.codendereco=e.codendereco" & _
 " and c.codpais=p.codpais" & _
 " and c.codprofissao=r.codprofissao"
 If sCPF <> "" Then
    sCons = sCons & " and c.cpf='" & sCPF & "'"
 End If
 If sNome <> "" Then
    sCons = sCons & " and c.nome like '%" & sNome & "%'"
 End If
ElseIf sTipo = "I" Then
  sCons = "insert into Cliente(cpf, nome, email, identidade, sexo," & _
  "telefone, datanasc, codendereco, codpais, codprofissao) values('" & _
  sCPF & "','" & sNome & "','" & sEmail & "','" & sIdentidade & "','" & sSexo & "','" & _
  sTelefone & "'," & RotinasGlobais.sepDTHR & sDtNascimento & RotinasGlobais.sepDTHR & _
  "," & sCodEndereco & ",'" & sCodPais & "'," & _
  sCodProfissao & ")"
ElseIf sTipo = "U" Then
  sCons = "update Cliente set nome='" & sNome & "',email='" & sEmail & _
  "',identidade='" & sIdentidade & "',sexo='" & sSexo & "',telefone='" & sTelefone & _
  "',datanasc=" & RotinasGlobais.sepDTHR & sDtNascimento & RotinasGlobais.sepDTHR & _
  ",codendereco=" & sCodEndereco & _
  ",codpais='" & sCodPais & "',codprofissao=" & sCodProfissao & _
  " where cpf='" & sCPF & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Cliente where cpf='" & sCPF & "'"
End If

Cliente = sCons
End Function

Function Endereco(sTipo As String, sCodigo As String, sLogradouro As String, _
sBairro As String, sCEP As String, sCidade As String, sEstado As String) As String
Dim sCons As String

If sTipo = "N" Then
  sCons = "select max(codendereco)+1 from Endereco"
ElseIf sTipo = "S" Then
  sCons = "select e.codendereco as Código, e.logradouro as Logradouro," & _
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" & _
  " from Endereco e" & _
  " where e.codendereco=e.codendereco"
  If sCodigo <> "" Then
     sCons = sCons & " and e.codendereco=" & sCodigo
  End If
  If sLogradouro <> "" Then
     sCons = sCons & " and e.logradouro like '%" & sLogradouro & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Endereco(codendereco, logradouro, bairro, cep," & _
  "cidade, estado) values(" & sCodigo & ",'" & sLogradouro & "','" & sBairro & _
  "','" & sCEP & "','" & sCidade & "','" & sEstado & "')"
ElseIf sTipo = "U" Then
  sCons = "update Endereco set logradouro='" & sLogradouro & "',bairro='" & _
  sBairro & "',cep='" & sCEP & "',cidade='" & sCidade & "',estado='" & sEstado & "'" & _
  " where codendereco=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Endereco where codendereco=" & sCodigo
End If

Endereco = sCons
End Function

Function Pais(sTipo As String, sCodigo As String, sPais As String) As String
Dim sCons As String

If sTipo = "S" Then
  sCons = "select p.codpais as Código, p.pais as País from Pais p" & _
  " where p.codpais=p.codpais"
  If sCodigo <> "" Then
     sCons = sCons & " and p.codpais='" & sCodigo & "'"
  End If
  If sPais <> "" Then
     sCons = sCons & " and p.pais like '%" & sPais & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Pais(codpais, pais) values('" & _
  sCodigo & "','" & sPais & "')"
ElseIf sTipo = "U" Then
  sCons = "update Pais set pais='" & sPais & "'" & _
  " where codpais='" & sCodigo & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Pais where codpais='" & sCodigo & "'"
End If

Pais = sCons
End Function

Function Profissao(sTipo As String, sCodigo As String, sProfissao As String) As String
Dim sCons As String

If sTipo = "N" Then
  sCons = "select max(codprofissao)+1 from Profissao"
ElseIf sTipo = "S" Then
  sCons = "select p.codprofissao as Código, p.profissao as Profissão from Profissao p" & _
  " where p.codprofissao=p.codprofissao"
  If sCodigo <> "" Then
     sCons = sCons & " and p.codprofissao=" & sCodigo
  End If
  If sProfissao <> "" Then
     sCons = sCons & " and p.profissao like '%" & sProfissao & "%'"
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Profissao(codprofissao, profissao) values(" & _
  sCodigo & ",'" & sProfissao & "')"
ElseIf sTipo = "U" Then
  sCons = "update Profissao set profissao='" & sProfissao & "'" & _
  " where codprofissao=" & sCodigo
ElseIf sTipo = "D" Then
  sCons = "delete from Profissao where codprofissao=" & sCodigo
End If

Profissao = sCons
End Function

Function LivroAss(sTipo As String, sISBN As String, sCodAssunto As String) As String
Dim sCons As String

If sTipo = "S" Then
  sCons = "select la.codassunto, a.assunto from LivroAss la, Assunto a" & _
  " where la.codassunto=a.codassunto" & _
  " and la.isbn='" & sISBN & "'"
ElseIf sTipo = "I" Then
  sCons = "insert into LivroAss(isbn, codassunto) values('" & _
  sISBN & "'," & sCodAssunto & "')"
ElseIf sTipo = "D" Then
  sCons = "delete from LivroAss where isbn='" & sISBN & "'"
End If

LivroAss = sCons
End Function

Function LivroAut(sTipo As String, sISBN As String, sCodAutor As String) As String
Dim sCons As String

If sTipo = "S" Then
  sCons = "select la.codautor, a.autor from LivroAut la, Autor a" & _
  " where la.codautor=a.codautor" & _
  " and la.isbn='" & sISBN & "'"
ElseIf sTipo = "I" Then
  sCons = "insert into LivroAut(isbn, codautor) values('" & _
  sISBN & "'," & sCodAutor & ")"
ElseIf sTipo = "D" Then
  sCons = "delete from LivroAut where isbn='" & sISBN & "'"
End If

LivroAut = sCons
End Function

Function Venda(sTipo As String, sISBN As String, sCPF As String, _
sDataVenda As String, sPrecoVenda As String, sQtdEstoque As String) As String
Dim sCons As String

If (sTipo = "S") Or (sTipo = "P") Then
  If sTipo = "S" Then
     sCons = "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," & _
     "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" & _
     " from Venda v, Livro l, Cliente c" & _
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  ElseIf sTipo = "P" Then
     sCons = "select sum(l.preco) as PreçoTotal" & _
     " from Venda v, Livro l, Cliente c" & _
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  End If
  If sISBN <> "" Then
     sCons = sCons & " and v.isbn='" & sISBN & "'"
  End If
  If sCPF <> "" Then
     sCons = sCons & " and v.cpf='" & sCPF & "'"
  End If
  If sDataVenda <> "" Then
     sCons = sCons & " and v.datavenda=" & _
     RotinasGlobais.sepDTHR & sDataVenda & RotinasGlobais.sepDTHR
  End If
ElseIf sTipo = "I" Then
  sCons = "insert into Venda(isbn, cpf, datavenda, precovenda) values('" & _
  sISBN & "','" & sCPF & "'," & RotinasGlobais.sepDTHR & sDataVenda & _
  RotinasGlobais.sepDTHR & "," & sPrecoVenda & ")"
ElseIf sTipo = "U" Then
  sCons = "update Livro set qtdestoque=" & sQtdEstoque + " where isbn='" & sISBN & "'"
ElseIf sTipo = "D" Then
  sCons = "delete from Venda where isbn='" & sISBN & "'" & _
  " and cpf = '" & sCPF & "' and datavenda = " & _
  RotinasGlobais.sepDTHR & sDataVenda & RotinasGlobais.sepDTHR
End If

Venda = sCons
End Function

End Class

End NameSpace
