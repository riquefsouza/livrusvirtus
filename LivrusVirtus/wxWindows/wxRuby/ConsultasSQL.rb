require 'RotinasGlobais'

$ConsSQL = nil

class ConsultasSQL
  
  def Assunto(sTipo, sCodigo, sAssunto)
    sCons = ""
    
    if (sTipo=='N')
      sCons = "select max(codassunto)+1 from Assunto"
    elsif (sTipo=='S')
      sCons="select a.codassunto as Código, a.assunto as Assunto from Assunto a" + 
      " where a.codassunto=a.codassunto"
      if (sCodigo != "")
    	  sCons = sCons + " and a.codassunto=" + sCodigo
      end
      if (sAssunto != "")
    	  sCons = sCons + " and a.assunto like '%" + sAssunto + "%'"
      end
    elsif (sTipo=='I')
      sCons = "insert into Assunto(codassunto, assunto) values(" + 
      sCodigo + ",'" + sAssunto + "')"
    elsif (sTipo=='U')
      sCons = "update Assunto set assunto='" + sAssunto + 
      "' where codassunto=" + sCodigo
    elsif (sTipo=='D')
      sCons = "delete from Assunto where codassunto=" + sCodigo
    end
    return sCons
  end
  #---------------------------------------------------------------------------
  def Autor(sTipo, sCodigo, sAutor)
    sCons = ""
    
    if (sTipo=='N')
      sCons="select max(codautor)+1 from Autor"
    elsif (sTipo=='S') 
      sCons="select a.codautor as Código, a.Autor as Autor from Autor a" +
      " where a.codautor=a.codautor"
      if (sCodigo != "")
    	 sCons=sCons + " and a.codautor=" + sCodigo
      end  
      if (sAutor != "")
    	 sCons=sCons + " and a.autor like '%" + sAutor + "%'"
      end	  
    elsif (sTipo=='I')
      sCons="insert into Autor(codautor, autor) values(" + 
      sCodigo + ",'" + sAutor + "')"
    elsif (sTipo=='U')
      sCons="update Autor set autor='" + sAutor + 
      "' where codautor=" + sCodigo
    elsif (sTipo=='D')
      sCons = "delete from Autor where codautor=" + sCodigo
    end
    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Editora(sTipo, sCodigo, sEditora)
    sCons=""
    
    if (sTipo=='N')
      sCons="select max(codeditora)+1 from Editora"
    elsif (sTipo=='S') 
      sCons="select e.codeditora as Código, e.editora as Editora from editora e" +
      " where e.codeditora=e.codeditora"
      if (sCodigo != "")
     	  sCons=sCons + " and e.codeditora=" + sCodigo
      end
      if (sEditora != "")
     	  sCons=sCons + " and e.editora like '%" + sEditora + "%'"
      end
    elsif (sTipo=='I')
      sCons="insert into editora(codeditora, editora) values(" + 
      sCodigo + ",'" + sEditora + "')"
    elsif (sTipo=='U')
      sCons="update editora set editora='" + sEditora +
      "' where codeditora=" + sCodigo
    elsif (sTipo=='D')
      sCons="delete from editora where codeditora=" + sCodigo
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Idioma(sTipo, sCodigo, sIdioma)  
    sCons=""
    
    if (sTipo=='N')
      sCons="select max(codidioma)+1 from Idioma"
    elsif (sTipo=='S') 
      sCons="select i.codidioma as Código, i.idioma as idioma from Idioma i" +
      " where i.codidioma=i.codidioma"
      if (sCodigo != "")
     	  sCons=sCons + " and i.codidioma=" + sCodigo
      end
      if (sIdioma != "")
    	  sCons=sCons + " and i.idioma like '%" + sIdioma + "%'"
      end
    elsif (sTipo=='I')
      sCons="insert into Idioma(codidioma, idioma) values(" + 
      sCodigo + ",'" + sIdioma + "')"
    elsif (sTipo=='U')
      sCons="update Idioma set idioma='" + sIdioma +
      "' where codidioma=" + sCodigo
    elsif (sTipo=='D')
      sCons="delete from Idioma where codidioma=" + sCodigo
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Usuario(sTipo, sLogin, sSenha)
    sCons=""
    
    if (sTipo=='S')
      sCons="select * from Usuario where login='" + sLogin + 
            "' and senha='" + sSenha+ "'"
    elsif (sTipo=='U')
      sCons="update Usuario set senha='" + sSenha + 
            "' where login='" + sLogin + "'"
    end
    return sCons
  end
  #---------------------------------------------------------------------------
  def Livro(sTipo, sISBN, sTitulo, sEdicao,sAnoPubli,sVolume,sCodEditora, 
            sCodIdioma,sNPaginas,sPreco,sQtdEstoque)
    sCons=""
    
    if (sTipo=='S') 
      sCons="select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição," +
      "l.anopubli as AnoPublicação,l.volume as Volume,l.codeditora as CodEditora," +
      "e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma," +
      "l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque" +
      " from Livro l, editora e, idioma i" +
      " where l.codeditora=e.codeditora" +
      " and l.codidioma=i.codidioma"
      if (sISBN != "")
        sCons=sCons + " and l.isbn='" + sISBN + "'"
      end
      if (sTitulo != "")
        sCons=sCons + " and l.titulo like '%" + sTitulo + "%'"
      end  
    elsif (sTipo=='I')
      sCons="insert into Livro(isbn, titulo, edicao, anopubli, codeditora," +  
      "volume, codidioma,npaginas, preco, qtdestoque) values('" + 
      sISBN + "','" + sTitulo + "'," + sEdicao + "," + sAnoPubli + "," + sCodEditora + "," + 
      sVolume + "," + sCodIdioma + "," + sNPaginas + "," + sPreco + "," + sQtdEstoque + ")"
    elsif (sTipo=='U')
      sCons="update Livro set titulo='" + sTitulo + "',edicao=" + sEdicao +
      ",anopubli=" + sAnoPubli + ",volume=" + sVolume + ",codeditora=" + sCodEditora +
      ",codidioma=" + sCodIdioma + ",npaginas=" + sNPaginas + ",preco=" + sPreco +
      ",qtdestoque=" + sQtdEstoque +
      " where isbn='" + sISBN + "'"
    elsif (sTipo=='D')
      sCons="delete from Livro where isbn='" + sISBN + "'"
    elsif (sTipo=='Q') 
      sCons="select l.isbn as ISBN, l.titulo as Título, l.preco as Preço," +
      "l.qtdestoque as Estoque" +
      " from Livro l" +
      " where l.isbn=l.isbn"
      if (sISBN != "")
        sCons=sCons + " and l.isbn='" + sISBN + "'"
      end
      if (sTitulo != "")
        sCons=sCons + " and l.titulo like '%" + sTitulo + "%'"
      end
    end
    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Cliente(sTipo, sCPF,sNome, sEmail,sIdentidade,sSexo,sTelefone, 
              sDtNascimento,sCodEndereco,sCodPais, sCodProfissao) 
    sCons=""
    
    if (sTipo=='S') 
      sCons="select c.cpf as CPF, c.nome as Nome, c.email as Email," +
      "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone," +
      "c.datanasc as DtNascimento, c.codendereco as CodEndereco," +
      "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP," +
      "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís," +
      "p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão" +
      " from Cliente c, endereco e, pais p, profissao r" +
      " where c.codendereco=e.codendereco" +
      " and c.codpais=p.codpais" +
      " and c.codprofissao=r.codprofissao"
      if (sCPF != "")
        sCons=sCons + " and c.cpf='" + sCPF + "'"
      end
      if (sNome != "")
        sCons=sCons + " and c.nome like '%" + sNome + "%'"
      end
    elsif (sTipo=='I')
      sCons="insert into Cliente(cpf, nome, email, identidade, sexo," +  
      "telefone, datanasc, codendereco, codpais, codprofissao) values('" + 
      sCPF + "','" + sNome + "','" + sEmail + "','" + sIdentidade + "','" + sSexo + "','" + 
      sTelefone + "'," + RotinasGlobais::SepDTHR + sDtNascimento + 
      RotinasGlobais::SepDTHR + "," + 
      sCodEndereco + ",'" + sCodPais + "'," + 
      sCodProfissao + ")"
    elsif (sTipo=='U')
      sCons="update Cliente set nome='" + sNome + "',email='" + sEmail +
      "',identidade='" + sIdentidade + "',sexo='" + sSexo + "',telefone='" + sTelefone +
      "',datanasc=" + RotinasGlobais::SepDTHR + sDtNascimento + RotinasGlobais::SepDTHR + 
      ",codendereco=" + sCodEndereco +
      ",codpais='" + sCodPais + "',codprofissao=" + sCodProfissao +
      " where cpf='" + sCPF + "'"
    elsif (sTipo=='D')
      sCons="delete from Cliente where cpf='" + sCPF + "'"
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Endereco(sTipo, sCodigo, sLogradouro,sBairro,sCEP,sCidade, sEstado) 
    sCons=""
    
    if (sTipo=='N')
      sCons="select max(codendereco)+1 from Endereco"
    elsif (sTipo=='S') 
      sCons="select e.codendereco as Código, e.logradouro as Logradouro," +
      "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado" +
      " from Endereco e" +
      " where e.codendereco=e.codendereco"
      if (sCodigo != "")
     	  sCons=sCons + " and e.codendereco=" + sCodigo
      end
      if (sLogradouro != "")
    	  sCons=sCons + " and e.logradouro like '%" + sLogradouro + "%'"
      end
    elsif (sTipo=='I')
      sCons="insert into Endereco(codendereco, logradouro, bairro, cep," +  
      "cidade, estado) values(" + sCodigo + ",'" + sLogradouro + "','" + sBairro,
      "','" + sCEP + "','" + sCidade + "','" + sEstado + "')"
    elsif (sTipo=='U')
      sCons="update Endereco set logradouro='" + sLogradouro + "',bairro='" + 
      sBairro + "',cep='" + sCEP + "',cidade='" + sCidade + "',estado='" + sEstado + "'" + 
      " where codendereco=" + sCodigo
    elsif (sTipo=='D')
      sCons="delete from Endereco where codendereco=" + sCodigo
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Pais(sTipo, sCodigo, sPais)  
    sCons=""
    
    if (sTipo=='S') 
      sCons="select p.codpais as Código, p.pais as País from Pais p" +
      " where p.codpais=p.codpais"
      if (sCodigo != "")
    	  sCons=sCons + " and p.codpais='" + sCodigo + "'"
      end
      if (sPais != "")
     	  sCons=sCons + " and p.pais like '%" + sPais + "%'"
      end
    elsif (sTipo=='I')
      sCons="insert into Pais(codpais, pais) values('" + 
      sCodigo + "','" + sPais + "')"
    elsif (sTipo=='U')
      sCons="update Pais set pais='" + sPais + "'" + 
      " where codpais='" + sCodigo + "'"
    elsif (sTipo=='D')
      sCons="delete from Pais where codpais='" + sCodigo + "'"
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Profissao(sTipo, sCodigo, sProfissao) 
    sCons=""
    
    if (sTipo=='N')
      sCons="select max(codprofissao)+1 from Profissao"
    elsif (sTipo=='S') 
      sCons="select p.codprofissao as Código, p.profissao as Profissão from Profissao p" +
      " where p.codprofissao=p.codprofissao"
      if (sCodigo != "")
     	  sCons=sCons + " and p.codprofissao=" + sCodigo
      end
      if (sProfissao != "")
    	  sCons=sCons + " and p.profissao like '%" + sProfissao + "%'"
      end
    elsif (sTipo=='I')
      sCons="insert into Profissao(codprofissao, profissao) values(" + 
      sCodigo + ",'" + sProfissao + "')"
    elsif (sTipo=='U')
      sCons="update Profissao set profissao='" + sProfissao + "'" + 
      " where codprofissao=" + sCodigo
    elsif (sTipo=='D')
      sCons="delete from Profissao where codprofissao=" + sCodigo
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def LivroAss(sTipo, sISBN, sCodAssunto)
    sCons=""
    
    if (sTipo=='S')
      sCons="select la.codassunto, a.assunto from LivroAss la, Assunto a" +  
      " where la.codassunto=a.codassunto" +  
      " and la.isbn='" + sISBN + "'"
    elsif (sTipo=='I')
      sCons="insert into LivroAss(isbn, codassunto) values('" + 
      sISBN + "'," + sCodAssunto + ")"
    elsif (sTipo=='D')
      sCons="delete from LivroAss where isbn='" + sISBN + "'"
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def LivroAut(sTipo, sISBN, sCodAutor)
    sCons=""
    
    if (sTipo=='S')
      sCons="select la.codautor, a.autor from LivroAut la, Autor a" +  
      " where la.codautor=a.codautor" +  
      " and la.isbn='" + sISBN + "'"
    elsif (sTipo=='I')
      sCons="insert into LivroAut(isbn, codautor) values('" + 
      sISBN + "'," + sCodAutor + ")"
    elsif (sTipo=='D')
      sCons="delete from LivroAut where isbn='" + sISBN + "'"
    end    
    return sCons
  end
  #---------------------------------------------------------------------------
  def Venda(sTipo, sISBN,sCPF, sDataVenda,sPrecoVenda,sQtdEstoque) 
    sCons=""
    
    if ((sTipo=='S') or (sTipo=='P')) 
      if (sTipo=='S')
        sCons="select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente," +
        "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço" +
        " from Venda v, Livro l, Cliente c" +
        " where v.isbn=l.isbn and v.cpf=c.cpf"
      elsif (sTipo=='P')
        sCons="select sum(l.preco) as PreçoTotal" +
        " from Venda v, Livro l, Cliente c" +
        " where v.isbn=l.isbn and v.cpf=c.cpf"
      end
      if (sISBN != "")
    	  sCons=sCons + " and v.isbn='" + sISBN + "'"
      end
      if (sCPF != "")
    	  sCons=sCons + " and v.cpf='" + sCPF + "'"
      end
      if (sDataVenda != "")
     	  sCons=sCons + " and v.datavenda=" + RotinasGlobais::SepDTHR + sDataVenda + 
        RotinasGlobais::SepDTHR
      end
    elsif (sTipo=='I')
      sCons="insert into Venda(isbn, cpf, datavenda, precovenda) values('" + 
      sISBN + "','" + sCPF + "'," + RotinasGlobais::SepDTHR + sDataVenda + 
      RotinasGlobais::SepDTHR + "," + sPrecoVenda + ")"
    elsif (sTipo=='U')
      sCons="update Livro set qtdestoque=" + sQtdEstoque + 
      " where isbn='" + sISBN + "'"
    elsif (sTipo=='D')
      sCons="delete from Venda where isbn='" + sISBN,
      "' and cpf='" + sCPF + "' and datavenda=" + RotinasGlobais::SepDTHR + 
      sDataVenda + RotinasGlobais::SepDTHR
    end    
    return sCons
  end

 
end
