from RotinasGlobais import RotinasGlobais

def create():
    return ConsultasSQL()

class ConsultasSQL:
  def __init__(self):
    self.data = []

  def Assunto(self, sTipo, sCodigo, sAssunto):
    sCons = ""    

    if sTipo=='N':
      sCons = "select max(codassunto)+1 from Assunto"
    elif sTipo=='S':
      sCons = "select a.codassunto, a.assunto from Assunto a"\
      " where a.codassunto=a.codassunto"
      if len(sCodigo) > 0:
        sCons = sCons + " and a.codassunto=" + sCodigo
      if len(sAssunto) > 0:
        sCons = sCons + " and a.assunto like '%" + sAssunto + "%'"
    elif sTipo=='I':
      sCons = "insert into Assunto(codassunto, assunto) values(" +\
      sCodigo + ",'" + sAssunto + "')"
    elif sTipo=='U':
      sCons = "update Assunto set assunto='" + sAssunto +\
      "' where codassunto=" + sCodigo
    elif sTipo=='D':
      sCons = "delete from Assunto where codassunto=" + sCodigo
    
    return sCons

  def Autor(self, sTipo, sCodigo, sAutor):
    sCons = ""
    
    if sTipo=='N':
      sCons = "select max(codautor)+1 from Autor"
    elif sTipo=='S':
      sCons = "select a.codautor as Codigo, a.Autor as Autor from Autor a"\
      " where a.codautor=a.codautor"
      if len(sCodigo) > 0:
        sCons = sCons + " and a.codautor=" + sCodigo
      if len(sAutor) > 0:
        sCons = sCons + " and a.autor like '%" + sAutor + "%'"
    elif sTipo=='I':
      sCons = "insert into Autor(codautor, autor) values("+\
      sCodigo + ",'" + sAutor + "')"
    elif sTipo=='U':
      sCons = "update Autor set autor='"+\
      sAutor + "' where codautor=" + sCodigo
    elif sTipo=='D':
      sCons = "delete from Autor where codautor=" + sCodigo
    
    return sCons

  def Editora(self, sTipo, sCodigo, sEditora):
    sCons = ""
    
    if sTipo=='N':
      sCons = "select max(codeditora)+1 from Editora"
    elif sTipo=='S':
      sCons = "select e.codeditora as Codigo, e.editora as Editora "\
      "from editora e where e.codeditora=e.codeditora"
      if len(sCodigo) > 0:
        sCons = sCons + " and e.codeditora=" + sCodigo
      if len(sEditora) > 0:
        sCons = sCons + " and e.editora like '%" + sEditora + "%'"
    elif sTipo=='I':
      sCons = "insert into editora(codeditora, editora) values("+\
      sCodigo + ",'" + sEditora + "')"
    elif sTipo=='U':
      sCons = "update editora set editora='"+\
      sEditora + "' where codeditora=" + sCodigo
    elif sTipo=='D':
      sCons = "delete from editora where codeditora=" + sCodigo
    
    return sCons

  def Idioma(self, sTipo, sCodigo, sIdioma):
    sCons = ""
    
    if sTipo=='N':
      sCons = "select max(codidioma)+1 from Idioma"
    elif sTipo=='S':
      sCons = "select i.codidioma as Codigo, i.idioma as idioma from Idioma i"\
      " where i.codidioma=i.codidioma"
      if len(sCodigo) > 0:
        sCons = sCons + " and i.codidioma=" + sCodigo
      if len(sIdioma) > 0:
        sCons = sCons + " and i.idioma like '%" + sIdioma + "%'"
    elif sTipo=='I':
      sCons = "insert into Idioma(codidioma, idioma) values("+\
      sCodigo + ",'" + sIdioma + "')"
    elif sTipo=='U':
      sCons = "update Idioma set idioma='"+\
      sIdioma + "' where codidioma=" + sCodigo
    elif sTipo=='D':
      sCons = "delete from Idioma where codidioma=" + sCodigo
    
    return sCons

  def Usuario(self, sTipo, sLogin, sSenha):
    sCons = ""
    
    if sTipo=='S':
      sCons = "select * from Usuario where login='"+\
      sLogin + "' and senha='" + sSenha + "'"
    elif sTipo=='U':
      sCons = "update Usuario set senha='"+\
      sSenha + "' where login='" + sLogin + "'"
    
    return sCons

  def Livro(self, sTipo, sISBN, sTitulo,sEdicao,sAnoPubli,sVolume,sCodEditora,
            sCodIdioma,sNPaginas,sPreco,sQtdEstoque):
    sCons = ""
    
    if sTipo=='S':
      sCons = "select l.isbn as ISBN, l.titulo as Titulo, l.edicao as Edicao,"\
      "l.anopubli as AnoPublicacao,l.volume as Volume,"\
      "l.codeditora as CodEditora,e.editora as Editora,"\
      "l.codidioma as CodIdioma,i.idioma as Idioma,"\
      "l.npaginas as NumPaginas, l.preco as Preco,"\
      "l.qtdestoque as Estoque from Livro l, editora e, idioma i"\
      " where l.codeditora=e.codeditora and l.codidioma=i.codidioma"
      if len(sISBN) > 0:
       sCons = sCons + " and l.isbn='" + sISBN + "'"
      if len(sTitulo) > 0:
       sCons = sCons + " and l.titulo like '%" + sTitulo + "%'"
    elif sTipo=='I':
      sCons = "insert into Livro(isbn, titulo, edicao, anopubli, codeditora,"\
      "volume, codidioma,npaginas, preco, qtdestoque) values('"+\
      sISBN + "','" + sTitulo + "'," + sEdicao + "," +\
      sAnoPubli + "," + sCodEditora + "," + sVolume + "," +\
      sCodIdioma + "," + sNPaginas + "," + sPreco + "," +\
      sQtdEstoque + ")"
    elif sTipo=='U':
      sCons = "update Livro set titulo='" + sTitulo + "',edicao=" + sEdicao +\
      ",anopubli=" + sAnoPubli + ",volume=" + sVolume + ",codeditora=" +\
      sCodEditora + ",codidioma=" + sCodIdioma + ",npaginas=" +\
      sNPaginas + ",preco=" + sPreco + ",qtdestoque=" +\
      sQtdEstoque + " where isbn='" + sISBN + "'"
    elif sTipo=='D':
      sCons = "delete from Livro where isbn='" + sISBN +  "'"
    elif sTipo=='Q':
      sCons = "select l.isbn as ISBN, l.titulo as Titulo, l.preco as Preco,"\
      "l.qtdestoque as Estoque from Livro l"\
      " where l.isbn=l.isbn"
      if len(sISBN) > 0:
        sCons = sCons + " and l.isbn='" + sISBN + "'"
      if len(sTitulo) > 0:
        sCons = sCons + " and l.titulo like '%" + sTitulo + "%'"
    
    return sCons

  def Cliente(self,sTipo,sCPF,sNome,sEmail,sIdentidade,sSexo,sTelefone,
              sDtNascimento,sCodEndereco,sCodPais,sCodProfissao):
    sCons = ""
    
    if sTipo=='S':
      sCons = "select c.cpf as CPF, c.nome as Nome, c.email as Email,"\
      "c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone,"\
      "c.datanasc as DtNascimento, c.codendereco as CodEndereco,"\
      "e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP,"\
      "e.cidade as Cidade,e.estado as Estado,c.codpais as CodPais,"\
      "p.pais as Pais, c.codprofissao as CodProfissao,r.profissao as Profissao"\
      " from Cliente c, endereco e, pais p, profissao r"\
      " where c.codendereco=e.codendereco"\
      " and c.codpais=p.codpais"\
      " and c.codprofissao=r.codprofissao"
      if len(sCPF) > 0:
        sCons = sCons + " and c.cpf='" + sCPF + "'"
      if len(sNome) > 0:
        sCons = sCons + " and c.nome like '%" + sNome + "%'"
    elif sTipo=='I':
      sCons = "insert into Cliente(cpf, nome, email, identidade, sexo,"\
      "telefone, datanasc, codendereco, codpais, codprofissao) values('" +\
      sCPF +  "','" +  sNome +  "','" +  sEmail +  "','" +\
      sIdentidade +  "','" +  sSexo +  "','" +  sTelefone +  "'," +\
      RotinasGlobais.sepDTHR +  sDtNascimento +  RotinasGlobais.sepDTHR + "," +\
      sCodEndereco +  ",'" +  sCodPais +  "'," + sCodProfissao + ")"
    elif sTipo=='U':
      sCons = "update Cliente set nome='" + sNome + "',email='" + sEmail +\
      "',identidade='" + sIdentidade +  "',sexo='" + sSexo + "',telefone='" +\
      sTelefone + "',datanasc=" + RotinasGlobais.sepDTHR + sDtNascimento +\
      RotinasGlobais.sepDTHR + ",codendereco=" + sCodEndereco +\
      ",codpais='" + sCodPais + "',codprofissao=" + sCodProfissao +\
      " where cpf='" + sCPF + "'"
    elif sTipo=='D':
      sCons = "delete from Cliente where cpf='" + sCPF + "'"
    
    return sCons

  def Endereco(self,sTipo,sCodigo,sLogradouro,sBairro,sCEP,sCidade,sEstado):
    sCons = ""
    
    if sTipo=='N':
      sCons = "select max(codendereco)+1 from Endereco"
    elif sTipo=='S':
      sCons = "select e.codendereco as Codigo, e.logradouro as Logradouro,"\
      "e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,"\
      "e.estado as Estado from Endereco e"\
      " where e.codendereco=e.codendereco"
      if len(sCodigo) > 0:
        sCons = sCons + " and e.codendereco=" + sCodigo
      if len(sLogradouro) > 0:
        sCons = sCons + " and e.logradouro like '%" + sLogradouro + "%'"
    elif sTipo=='I':
      sCons = "insert into Endereco(codendereco, logradouro, bairro, cep,"\
      "cidade, estado) values(" + sCodigo + ",'" + sLogradouro + "','" +\
      sBairro + "','" + sCEP + "','" + sCidade + "','" +\
      sEstado +  "')"
    elif sTipo=='U':
      sCons = "update Endereco set logradouro='" + sLogradouro +  "',bairro='" +\
      sBairro + "',cep='" + sCEP + "',cidade='" + sCidade +\
      "',estado='" + sEstado + "'" +\
      " where codendereco=" + sCodigo
    elif sTipo=='D':
      sCons = "delete from Endereco where codendereco=" + sCodigo
    
    return sCons

  def Pais(self, sTipo, sCodigo, sPais):
    sCons = ""
    
    if sTipo=='S':
      sCons = "select p.codpais as Codigo, p.pais as Pais from Pais p"\
      " where p.codpais=p.codpais"
      if len(sCodigo) > 0:
        sCons = sCons + " and p.codpais='" + sCodigo + "'"
      if len(sPais) > 0:
        sCons = sCons + " and p.pais like '%" + sPais + "%'"
    elif sTipo=='I':
      sCons = "insert into Pais(codpais, pais) values('" +\
      sCodigo + "','" + sPais + "')"
    elif sTipo=='U':
      sCons = "update Pais set pais='" +\
      sPais + "'"," where codpais='" + sCodigo + "'"
    elif sTipo=='D':
      sCons = "delete from Pais where codpais='" + sCodigo + "'"
    
    return sCons

  def Profissao(self,sTipo,sCodigo,sProfissao):
    sCons = ""
    
    if sTipo=='N':
      sCons = "select max(codprofissao)+1 from Profissao"
    elif sTipo=='S':
      sCons = "select p.codprofissao as Codigo, p.profissao as Profissao"\
      " from Profissao p where p.codprofissao=p.codprofissao"
      if len(sCodigo) > 0:
        sCons = sCons + " and p.codprofissao=" + sCodigo
      if len(sProfissao) > 0:
        sCons = sCons + " and p.profissao like '%" + sProfissao + "%'"
    elif sTipo=='I':
      sCons = "insert into Profissao(codprofissao, profissao) values(" +\
      sCodigo + ",'" + sProfissao + "')"
    elif sTipo=='U':
      sCons = "update Profissao set profissao='" +\
      sProfissao + "' where codprofissao=" + sCodigo
    elif sTipo=='D':
      sCons = "delete from Profissao where codprofissao=" + sCodigo
    
    return sCons

  def LivroAss(self, sTipo, sISBN, sCodAssunto):
    sCons = ""
    
    if sTipo=='S':
      sCons = "select la.codassunto, a.assunto from LivroAss la, Assunto a"\
      " where la.codassunto=a.codassunto"\
      " and la.isbn='" + sISBN + "'"
    elif sTipo=='I':
      sCons = "insert into LivroAss(isbn, codassunto) values('" +\
      sISBN + "'," + sCodAssunto + ")"
    elif sTipo=='D':
      sCons = "delete from LivroAss where isbn='" + sISBN + "'"
    
    return sCons

  def LivroAut(self, sTipo, sISBN, sCodAutor):
    sCons = ""
    
    if sTipo=='S':
      sCons = "select la.codautor, a.autor from LivroAut la, Autor a"\
      " where la.codautor=a.codautor"\
      " and la.isbn='" +  sISBN +  "'"
    elif sTipo=='I':
      sCons = "insert into LivroAut(isbn, codautor) values('" +\
      sISBN + "'," + sCodAutor + ")"
    elif sTipo=='D':
      sCons = "delete from LivroAut where isbn='" + sISBN + "'"
    
    return sCons

  def Venda(self,sTipo,sISBN,sCPF,sDataVenda,sPrecoVenda,sQtdEstoque):
    sCons = ""
    
    if (sTipo=='S' or sTipo=='P'):
      if sTipo=='S':
        sCons = "select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente,"\
        "v.isbn as ISBN,l.Titulo as Livro, l.preco as Preco"\
        " from Venda v, Livro l, Cliente c"\
        " where v.isbn=l.isbn and v.cpf=c.cpf"
      elif sTipo=='P':
        sCons = "select sum(l.preco) as PrecoTotal"\
        " from Venda v, Livro l, Cliente c"\
        " where v.isbn=l.isbn and v.cpf=c.cpf"
      if len(sISBN) > 0:
        sCons = sCons + " and v.isbn='" + sISBN + "'"
      if len(sCPF) > 0:
        sCons = sCons + " and v.cpf='" + sCPF + "'"
      if len(sDataVenda) > 0:
        sCons = sCons + " and v.datavenda=" + RotinasGlobais.sepDTHR +\
        sDataVenda + RotinasGlobais.sepDTHR
    elif sTipo=='I':
      sCons = "insert into Venda(isbn, cpf, datavenda, precovenda) values('" +\
      sISBN + "','" + sCPF + "'," +\
      RotinasGlobais.sepDTHR + sDataVenda + RotinasGlobais.sepDTHR +\
      "," + sPrecoVenda + ")"
    elif sTipo=='U':
      sCons = "update Livro set qtdestoque=" + sQtdEstoque
      " where isbn='" + sISBN + "'"
    elif sTipo=='D':
      sCons = "delete from Venda where isbn='" + sISBN +\
      "' and cpf='" + sCPF +\
      "' and datavenda=" + RotinasGlobais.sepDTHR +\
      sDataVenda + RotinasGlobais.sepDTHR
    
    return sCons   
