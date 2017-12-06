function ConsSQL_Assunto(sTipo, sCodigo, sAssunto)
sCons = ""

if sTipo == "N" then
  sCons = "select max(codassunto)+1 from Assunto"
elseif sTipo == "S" then
  sCons = "select a.codassunto as Código, a.assunto as Assunto from Assunto a" ..
  " where a.codassunto=a.codassunto"
  if sCodigo ~= "" then
     sCons = sCons .. " and a.codassunto=" .. sCodigo
  end
  if sAssunto ~= "" then
     sCons = sCons .. " and a.assunto like '%" .. sAssunto .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into Assunto(codassunto, assunto) values(" ..
  sCodigo .. ",'" .. sAssunto .. "')"
elseif sTipo == "U" then
  sCons = "update Assunto set assunto='" .. sAssunto .. "'" ..
  " where codassunto=" .. sCodigo
elseif sTipo == "D" then
  sCons = "delete from Assunto where codassunto=" .. sCodigo
end

return sCons
end

function ConsSQL_Autor(sTipo, sCodigo, sAutor)
sCons = ""

if sTipo == "N" then
  sCons = "select max(codautor)+1 from Autor"
elseif sTipo == "S" then
  sCons = "select a.codautor as Código, a.Autor as Autor from Autor a" ..
  " where a.codautor=a.codautor"
  if sCodigo ~= "" then
     sCons = sCons .. " and a.codautor=" .. sCodigo
  end
  if sAutor ~= "" then
     sCons = sCons .. " and a.autor like '%" .. sAutor .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into Autor(codautor, autor) values(" ..
  sCodigo .. ",'" .. sAutor .. "')"
elseif sTipo == "U" then
  sCons = "update Autor set autor='" .. sAutor .. "'" ..
  " where codautor=" .. sCodigo
elseif sTipo == "D" then
  sCons = "delete from Autor where codautor=" .. sCodigo
end

return sCons
end

function ConsSQL_Editora(sTipo, sCodigo, sEditora)
sCons = ""

if sTipo == "N" then
  sCons = "select max(codeditora)+1 from Editora"
elseif sTipo == "S" then
  sCons = "select e.codeditora as Código, e.editora as Editora from Editora e" ..
  " where e.codeditora=e.codeditora"
  if sCodigo ~= "" then
     sCons = sCons .. " and e.codeditora=" .. sCodigo
  end
  if sEditora ~= "" then
     sCons = sCons .. " and e.editora like '%" .. sEditora .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into editora(codeditora, editora) values(" ..
  sCodigo .. ",'" .. sEditora .. "')"
elseif sTipo == "U" then
  sCons = "update editora set editora='" .. sEditora .. "'" ..
  " where codeditora=" .. sCodigo
elseif sTipo == "D" then
  sCons = "delete from editora where codeditora=" .. sCodigo
end

return sCons
end

function ConsSQL_Idioma(sTipo, sCodigo, sIdioma)
sCons = ""

if sTipo == "N" then
  sCons = "select max(codidioma)+1 from Idioma"
elseif sTipo == "S" then
  sCons = "select i.codidioma as Código, i.idioma as idioma from Idioma i" ..
  " where i.codidioma=i.codidioma"
  if sCodigo ~= "" then
     sCons = sCons .. " and i.codidioma=" .. sCodigo
  end
  if sIdioma ~= "" then
     sCons = sCons .. " and i.idioma like '%" .. sIdioma .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into Idioma(codidioma, idioma) values(" ..
  sCodigo .. ",'" .. sIdioma .. "')"
elseif sTipo == "U" then
  sCons = "update Idioma set idioma='" .. sIdioma .. "'" ..
  " where codidioma=" .. sCodigo
elseif sTipo == "D" then
  sCons = "delete from Idioma where codidioma=" .. sCodigo
end

return sCons
end

function ConsSQL_Usuario(sTipo, sLogin, sSenha)
sCons = ""

if sTipo == "S" then
 sCons = "select * from Usuario u where u.login='" .. sLogin ..
  "' and u.senha='" .. sSenha .. "'"
elseif sTipo == "U" then
 sCons = "update Usuario set senha='" .. sSenha .. "' where login='" .. sLogin .. "'"
end

return sCons
end

function ConsSQL_Livro(sTipo, sISBN, sTitulo,
sEdicao, sAnoPubli, sVolume,
sCodEditora, sCodIdioma, sNPaginas,
sPreco, sQtdEstoque)
sCons = ""

if sTipo == "S" then
 sCons = "select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," ..
 "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," ..
 "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," ..
 "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" ..
 " from Livro l, editora e, idioma i" ..
 " where l.codeditora=e.codeditora" ..
 " and l.codidioma=i.codidioma"
 if sISBN ~= "" then
    sCons = sCons .. " and l.isbn='" .. sISBN .. "'"
 end
 if sTitulo ~= "" then
    sCons = sCons .. " and l.titulo like '%" .. sTitulo .. "%'"
 end
elseif sTipo == "I" then
  sCons = "insert into Livro(isbn, titulo, edicao, anopubli, codeditora," ..
  "volume, codidioma,npaginas, preco, qtdestoque) values('" ..
  sISBN .. "','" .. sTitulo .. "'," .. sEdicao .. "," .. sAnoPubli .. "," .. sCodEditora .. "," ..
  sVolume .. "," .. sCodIdioma .. "," .. sNPaginas .. "," .. sPreco .. "," .. sQtdEstoque .. "')"
elseif sTipo == "U" then
  sCons = "update Livro set titulo='" .. sTitulo .. "',edicao=" .. sEdicao ..
  ",anopubli=" .. sAnoPubli .. ",volume=" .. sVolume .. ",codeditora=" .. sCodEditora ..
  ",codidioma=" .. sCodIdioma .. ",npaginas=" .. sNPaginas .. ",preco=" .. sPreco ..
  ",qtdestoque=" .. sQtdEstoque ..
  " where isbn='" .. sISBN .. "'"
elseif sTipo == "D" then
  sCons = "delete from Livro where isbn='" .. sISBN .. "'"
elseif sTipo == "Q" then
 sCons = "select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," ..
 "l.qtdestoque as Estoque" ..
 " from Livro l" ..
 " where l.isbn=l.isbn"
 if sISBN ~= "" then
    sCons = sCons .. " and l.isbn='" .. sISBN .. "'"
 end
 if sTitulo ~= "" then
    sCons = sCons .. " and l.titulo like '%" .. sTitulo .. "%'"
 end
end

return sCons
end

function ConsSQL_Cliente(sTipo, sCPF, sNome,
sEmail, sIdentidade, sSexo, sTelefone,
sDtNascimento, sCodEndereco, sCodPais,
sCodProfissao)
sCons = ""

if sTipo == "S" then
 sCons = "select c.cpf as CPF, c.nome as Nome, c.email as Email," ..
 "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," ..
 "c.datanasc as DtNascimento, c.codendereco as CodEndereco," ..
 "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," ..
 "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís," ..
 "p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão" ..
 " from Cliente c, endereco e, pais p, profissao r" ..
 " where c.codendereco=e.codendereco" ..
 " and c.codpais=p.codpais" ..
 " and c.codprofissao=r.codprofissao"
 if sCPF ~= "" then
    sCons = sCons .. " and c.cpf='" .. sCPF .. "'"
 end
 if sNome ~= "" then
    sCons = sCons .. " and c.nome like '%" .. sNome .. "%'"
 end
elseif sTipo == "I" then
  sCons = "insert into Cliente(cpf, nome, email, identidade, sexo," ..
  "telefone, datanasc, codendereco, codpais, codprofissao) values('" ..
  sCPF .. "','" .. sNome .. "','" .. sEmail .. "','" .. sIdentidade .. "','" .. sSexo .. "','" ..
  sTelefone .. "'," .. sepDTHR .. sDtNascimento .. sepDTHR ..
  "," .. sCodEndereco .. ",'" .. sCodPais .. "'," ..
  sCodProfissao .. ")"
elseif sTipo == "U" then
  sCons = "update Cliente set nome='" .. sNome .. "',email='" .. sEmail ..
  "',identidade='" .. sIdentidade .. "',sexo='" .. sSexo .. "',telefone='" .. sTelefone ..
  "',datanasc=" .. sepDTHR .. sDtNascimento .. sepDTHR ..
  ",codendereco=" .. sCodEndereco ..
  ",copais='" .. sCodPais .. "',codprofissao=" .. sCodProfissao ..
  " where cpf='" .. sCPF .. "'"
elseif sTipo == "D" then
  sCons = "delete from Cliente where cpf='" .. sCPF .. "'"
end

return sCons
end

function ConsSQL_Endereco(sTipo, sCodigo, sLogradouro,
sBairro, sCEP, sCidade, sEstado)
sCons = ""

if sTipo == "N" then
  sCons = "select max(codendereco)+1 from Endereco"
elseif sTipo == "S" then
  sCons = "select e.codendereco as Código, e.logradouro as Logradouro," ..
  "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" ..
  " from Endereco e" ..
  " where e.codendereco=e.codendereco"
  if sCodigo ~= "" then
     sCons = sCons .. " and e.codendereco=" .. sCodigo
  end
  if sLogradouro ~= "" then
     sCons = sCons .. " and e.logradouro like '%" .. sLogradouro .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into Endereco(codendereco, logradouro, bairro, cep," ..
  "cidade, estado) values(" .. sCodigo .. ",'" .. sLogradouro .. "','" .. sBairro ..
  "','" .. sCEP .. "','" .. sCidade .. "','" .. sEstado .. "')"
elseif sTipo == "U" then
  sCons = "update Endereco set logradouro='" .. sLogradouro .. "',bairro='" ..
  sBairro .. "',cep='" .. sCEP .. "',cidade='" .. sCidade .. "',estado='" .. sEstado .. "'" ..
  " where codendereco=" .. sCodigo
elseif sTipo == "D" then
  sCons = "delete from Endereco where codendereco=" .. sCodigo
end

return sCons
end

function ConsSQL_Pais(sTipo, sCodigo, sPais)
sCons = ""

if sTipo == "S" then
  sCons = "select p.codpais as Código, p.pais as País from Pais p" ..
  " where p.codpais=p.codpais"
  if sCodigo ~= "" then
     sCons = sCons .. " and p.codpais='" .. sCodigo .. "'"
  end
  if sPais ~= "" then
     sCons = sCons .. " and p.pais like '%" .. sPais .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into Pais(codpais, pais) values('" ..
  sCodigo .. "','" .. sPais .. "')"
elseif sTipo == "U" then
  sCons = "update Pais set pais='" .. sPais .. "'" ..
  " where codpais='" .. sCodigo .. "'"
elseif sTipo == "D" then
  sCons = "delete from Pais where codpais='" .. sCodigo .. "'"
end

return sCons
end

function ConsSQL_Profissao(sTipo, sCodigo, sProfissao)
sCons = ""

if sTipo == "N" then
  sCons = "select max(codprofissao)+1 from Profissao"
elseif sTipo == "S" then
  sCons = "select p.codprofissao as Código, p.profissao as Profissão from Profissao p" ..
  " where p.codprofissao=p.codprofissao"
  if sCodigo ~= "" then
     sCons = sCons .. " and p.codprofissao=" .. sCodigo
  end
  if sProfissao ~= "" then
     sCons = sCons .. " and p.profissao like '%" .. sProfissao .. "%'"
  end
elseif sTipo == "I" then
  sCons = "insert into Profissao(codprofissao, profissao) values(" ..
  sCodigo .. ",'" .. sProfissao .. "')"
elseif sTipo == "U" then
  sCons = "update Profissao set profissao='" .. sProfissao .. "'" ..
  " where codprofissao=" .. sCodigo
elseif sTipo == "D" then
  sCons = "delete from Profissao where codprofissao=" .. sCodigo
end

return sCons
end

function ConsSQL_LivroAss(sTipo, sISBN, sCodAssunto)
sCons = ""

if sTipo == "S" then
  sCons = "select la.codassunto, a.assunto from LivroAss la, Assunto a" ..
  " where la.codassunto=a.codassunto" ..
  " and la.isbn='" .. sISBN .. "'"
elseif sTipo == "I" then
  sCons = "insert into LivroAss(isbn, codassunto) values('" ..
  sISBN .. "'," .. sCodAssunto .. "')"
elseif sTipo == "D" then
  sCons = "delete from LivroAss where isbn='" .. sISBN .. "'"
end

return sCons
end

function ConsSQL_LivroAut(sTipo, sISBN, sCodAutor)
sCons = ""

if sTipo == "S" then
  sCons = "select la.codautor, a.autor from LivroAut la, Autor a" ..
  " where la.codautor=a.codautor" ..
  " and la.isbn='" .. sISBN .. "'"
elseif sTipo == "I" then
  sCons = "insert into LivroAut(isbn, codautor) values('" ..
  sISBN .. "'," .. sCodAutor .. ")"
elseif sTipo == "D" then
  sCons = "delete from LivroAut where isbn='" .. sISBN .. "'"
end

return sCons
end

function ConsSQL_Venda(sTipo, sISBN, sCPF,
sDataVenda, sPrecoVenda, sQtdEstoque)
sCons = ""

if (sTipo == "S") or (sTipo == "P") then
  if sTipo == "S" then
     sCons = "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," ..
     "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" ..
     " from Venda v, Livro l, Cliente c" ..
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  elseif sTipo == "P" then
     sCons = "select sum(l.preco) as PreçoTotal" ..
     " from Venda v, Livro l, Cliente c" ..
     " where v.isbn=l.isbn and v.cpf=c.cpf"
  end
  if sISBN ~= "" then
     sCons = sCons .. " and v.isbn='" .. sISBN .. "'"
  end
  if sCPF ~= "" then
     sCons = sCons .. " and v.cpf='" .. sCPF .. "'"
  end
  if sDataVenda ~= "" then
     sCons = sCons .. " and v.datavenda=" ..
     sepDTHR .. sDataVenda .. sepDTHR
  end
elseif sTipo == "I" then
  sCons = "insert into Venda(isbn, cpf, datavenda, precovenda) values('" ..
  sISBN .. "','" .. sCPF .. "'," .. sepDTHR .. sDataVenda ..
  sepDTHR .. "," .. sPrecoVenda .. ")"
elseif sTipo == "U" then
  sCons = "update Livro set qtdestoque=" .. sQtdEstoque + " where isbn='" .. sISBN .. "'"
elseif sTipo == "D" then
  sCons = "delete from Venda where isbn='" .. sISBN .. "'" ..
  " and cpf = '" .. sCPF .. "' and datavenda = " ..
  sepDTHR .. sDataVenda .. sepDTHR
end

return sCons
end
