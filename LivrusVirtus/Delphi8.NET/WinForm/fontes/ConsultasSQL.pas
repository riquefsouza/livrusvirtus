unit ConsultasSQL;

interface

type
  TConsultasSQL = class(System.Object)
  private
    { Private Declarations }
  public
    function Assunto(sTipo: char; sCodigo, sAssunto: string): string;
    function Autor(sTipo: char; sCodigo, sAutor: string): string;
    function Editora(sTipo: char; sCodigo, sEditora: string): string;
    function Idioma(sTipo: char; sCodigo, sIdioma: string): string;
    function Usuario(sTipo: char; sLogin, sSenha: string): string;
    function Livro(sTipo: char; sISBN,sTitulo,sEdicao,sAnoPubli,sVolume,
           sCodEditora,sCodIdioma,sNPaginas,sPreco,sQtdEstoque:string):string;
    function Cliente(sTipo: char; sCPF,sNome,sEmail,sIdentidade,sSexo,
    sTelefone,sDtNascimento,sCodEndereco,sCodPais,sCodProfissao:string):string;
    function Endereco(sTipo: char; sCodigo, sLogradouro,sBairro,
                      sCEP,sCidade,sEstado: string): string;
    function Pais(sTipo: char; sCodigo, sPais: string): string;
    function Profissao(sTipo: char; sCodigo, sProfissao: string): string;
    function LivroAss(sTipo: char; sISBN, sCodAssunto: string): string;
    function LivroAut(sTipo: char; sISBN, sCodAutor: string): string;
    function Venda(sTipo: char; sISBN,sCPF,sDataVenda,
                   sPrecoVenda, sQtdEstoque: string): string;

    constructor Create;
  end;

var
  ConsSQL: TConsultasSQL;

implementation

constructor TConsultasSQL.Create;
begin
  inherited Create;
  // TODO: Add any constructor code here
end;

function TConsultasSQL.Assunto(sTipo: char; sCodigo, sAssunto: string): string;
var sCons: string;
begin
if sTipo='N' then
  sCons:='select max(codassunto)+1 from Assunto'
else if sTipo='S' then begin
  sCons:='select a.codassunto as Código, a.assunto as Assunto from Assunto a'+
  ' where a.codassunto=a.codassunto';
  if sCodigo<>'' then
     sCons:=sCons+' and a.codassunto='+sCodigo;
  if sAssunto<>'' then
     sCons:=sCons+' and a.assunto like ''%'+sAssunto+'%''';
end else if sTipo='I' then
  sCons:='insert into Assunto(codassunto, assunto) values('+
  sCodigo+','''+sAssunto+''')'
else if sTipo='U' then
  sCons:='update Assunto set assunto='''+sAssunto+''''+
  ' where codassunto='+sCodigo
else if sTipo='D' then
  sCons:='delete from Assunto where codassunto='+sCodigo;

result:=sCons;
end;

function TConsultasSQL.Autor(sTipo: char; sCodigo, sAutor: string): string;
var sCons: string;
begin
if sTipo='N' then
  sCons:='select max(codautor)+1 from Autor'
else if sTipo='S' then begin
  sCons:='select a.codautor as Código, a.Autor as Autor from Autor a'+
  ' where a.codautor=a.codautor';
  if sCodigo<>'' then
     sCons:=sCons+' and a.codautor='+sCodigo;
  if sAutor<>'' then
     sCons:=sCons+' and a.autor like ''%'+sAutor+'%''';
end else if sTipo='I' then
  sCons:='insert into Autor(codautor, autor) values('+
  sCodigo+','''+sAutor+''')'
else if sTipo='U' then
  sCons:='update Autor set autor='''+sAutor+''''+
  ' where codautor='+sCodigo
else if sTipo='D' then
  sCons:='delete from Autor where codautor='+sCodigo;

result:=sCons;
end;

function TConsultasSQL.Editora(sTipo: char; sCodigo, sEditora: string): string;
var sCons: string;
begin
if sTipo='N' then
  sCons:='select max(codeditora)+1 from Editora'
else if sTipo='S' then begin
  sCons:='select e.codeditora as Código, e.editora as Editora from editora e'+
  ' where e.codeditora=e.codeditora';
  if sCodigo<>'' then
     sCons:=sCons+' and e.codeditora='+sCodigo;
  if sEditora<>'' then
     sCons:=sCons+' and e.editora like ''%'+sEditora+'%''';
end else if sTipo='I' then
  sCons:='insert into editora(codeditora, editora) values('+
  sCodigo+','''+sEditora+''')'
else if sTipo='U' then
  sCons:='update editora set editora='''+sEditora+''''+
  ' where codeditora='+sCodigo
else if sTipo='D' then
  sCons:='delete from editora where codeditora='+sCodigo;

result:=sCons;
end;

function TConsultasSQL.Idioma(sTipo: char; sCodigo, sIdioma: string): string;
var sCons: string;
begin
if sTipo='N' then
  sCons:='select max(codidioma)+1 from Idioma'
else if sTipo='S' then begin
  sCons:='select i.codidioma as Código, i.idioma as idioma from Idioma i'+
  ' where i.codidioma=i.codidioma';
  if sCodigo<>'' then
     sCons:=sCons+' and i.codidioma='+sCodigo;
  if sIdioma<>'' then
     sCons:=sCons+' and i.idioma like ''%'+sIdioma+'%''';
end else if sTipo='I' then
  sCons:='insert into Idioma(codidioma, idioma) values('+
  sCodigo+','''+sIdioma+''')'
else if sTipo='U' then
  sCons:='update Idioma set idioma='''+sIdioma+''''+
  ' where codidioma='+sCodigo
else if sTipo='D' then
  sCons:='delete from Idioma where codidioma='+sCodigo;

result:=sCons;
end;

function TConsultasSQL.Usuario(sTipo: char; sLogin, sSenha: string): string;
var sCons: string;
begin
if sTipo='S' then
 sCons:='select * from Usuario u where u.login='''+sLogin+
 ''' and u.senha='''+sSenha+''''
else if sTipo='U' then
 sCons:='update Usuario set senha='''+sSenha+''' where login='''+sLogin+'''';

result:=sCons;
end;

function TConsultasSQL.Livro(sTipo: char; sISBN,sTitulo,sEdicao,sAnoPubli,
    sVolume,sCodEditora,sCodIdioma,sNPaginas,sPreco,sQtdEstoque:string):string;
var sCons: string;
begin
if sTipo='S' then begin
 sCons:='select l.isbn as ISBN, l.titulo as Título, l.edicao as Edição,'+
 'l.anopubli as AnoPublicação, l.volume as Volume,l.codeditora as CodEditora,'+
 'e.editora as Editora, l.codidioma as CodIdioma, i.idioma as Idioma,'+
 'l.npaginas as NumPaginas, l.preco as Preço, l.qtdestoque as Estoque'+
 ' from Livro l, editora e, idioma i'+
 ' where l.codeditora=e.codeditora'+
 ' and l.codidioma=i.codidioma';
 if sISBN<>'' then
    sCons:=sCons+' and l.isbn='''+sISBN+'''';
 if sTitulo<>'' then
    sCons:=sCons+' and l.titulo like ''%'+sTitulo+'%''';
end else if sTipo='I' then
  sCons:='insert into Livro(isbn, titulo, edicao, anopubli, codeditora,'+
  'volume, codidioma,npaginas, preco, qtdestoque) values('''+
  sISBN+''','''+sTitulo+''','+sEdicao+','+sAnoPubli+','+sCodEditora+','+
  sVolume+','+sCodIdioma+','+sNPaginas+','+sPreco+','+sQtdEstoque+')'
else if sTipo='U' then
  sCons:='update Livro set titulo='''+sTitulo+''',edicao='+sEdicao+
  ',anopubli='+sAnoPubli+',volume='+sVolume+',codeditora='+sCodEditora+
  ',codidioma='+sCodIdioma+',npaginas='+sNPaginas+',preco='+sPreco+
  ',qtdestoque='+sQtdEstoque+
  ' where isbn='''+sISBN+''''
else if sTipo='D' then
  sCons:='delete from Livro where isbn='''+sISBN+''''
else if sTipo='Q' then begin
 sCons:='select l.isbn as ISBN, l.titulo as Título, l.preco as Preço,'+
 'l.qtdestoque as Estoque'+
 ' from Livro l'+
 ' where l.isbn=l.isbn';
 if sISBN<>'' then
    sCons:=sCons+' and l.isbn='''+sISBN+'''';
 if sTitulo<>'' then
    sCons:=sCons+' and l.titulo like ''%'+sTitulo+'%''';
end;

result:=sCons;
end;

function TConsultasSQL.Cliente(sTipo: char; sCPF,sNome,sEmail,sIdentidade,sSexo,
sTelefone,sDtNascimento,sCodEndereco,sCodPais,sCodProfissao:string):string;
var sCons: string;
begin
if sTipo='S' then begin
 sCons:='select c.cpf as CPF, c.nome as Nome, c.email as Email,'+
 'c.identidade as Identidade, c.sexo as Sexo, c.telefone as Telefone,'+
 'c.datanasc as DtNascimento, c.codendereco as CodEndereco,'+
 'e.logradouro as Logradouro,e.bairro as Bairro,e.cep as CEP,'+
 'e.cidade as Cidade,e.estado as Estado,c.codpais as CodPaís,'+
 'p.pais as País, c.codprofissao as CodProfissao,r.profissao as Profissão'+
 ' from Cliente c, endereco e, pais p, profissao r'+
 ' where c.codendereco=e.codendereco'+
 ' and c.codpais=p.codpais'+
 ' and c.codprofissao=r.codprofissao';
 if sCPF<>'' then
    sCons:=sCons+' and c.cpf='''+sCPF+'''';
 if sNome<>'' then
    sCons:=sCons+' and c.nome like ''%'+sNome+'%''';
end else if sTipo='I' then
  sCons:='insert into Cliente(cpf, nome, email, identidade, sexo,'+
  'telefone, datanasc, codendereco, codpais, codprofissao) values('''+
  sCPF+''','''+sNome+''','''+sEmail+''','''+sIdentidade+''','''+sSexo+''','''+
  sTelefone+''','''+sDtNascimento+''','+sCodEndereco+','''+sCodPais+''','+
  sCodProfissao+')'
else if sTipo='U' then
  sCons:='update Cliente set nome='''+sNome+''',email='''+sEmail+
  ''',identidade='+sIdentidade+''',sexo='''+sSexo+''',telefone='''+sTelefone+
  ''',datanasc='''+sDtNascimento+''',codendereco='+sCodEndereco+
  ',codpais='''+sCodPais+''',codprofissao='+sCodProfissao+
  ' where cpf='''+sCPF+''''
else if sTipo='D' then
  sCons:='delete from Cliente where cpf='''+sCPF+'''';

result:=sCons;
end;

function TConsultasSQL.Endereco(sTipo: char; sCodigo, sLogradouro,sBairro,
                                sCEP,sCidade,sEstado: string): string;
var sCons: string;
begin
if sTipo='N' then
  sCons:='select max(codendereco)+1 from Endereco'
else if sTipo='S' then begin
  sCons:='select e.codendereco as Código, e.logradouro as Logradouro,'+
  'e.bairro as Bairro,e.cep as CEP,e.cidade as Cidade,e.estado as Estado'+
  ' from Endereco e'+
  ' where e.codendereco=e.codendereco';
  if sCodigo<>'' then
     sCons:=sCons+' and e.codendereco='+sCodigo;
  if sLogradouro<>'' then
     sCons:=sCons+' and e.logradouro like ''%'+sLogradouro+'%''';
end else if sTipo='I' then
  sCons:='insert into Endereco(codendereco, logradouro, bairro, cep,'+
  'cidade, estado) values('+sCodigo+','''+sLogradouro+''','''+sBairro+
  ''','''+sCEP+''','''+sCidade+''','''+sEstado+''')'
else if sTipo='U' then
  sCons:='update Endereco set logradouro='''+sLogradouro+''',bairro='''+
  sBairro+''',cep='''+sCEP+''',cidade='''+sCidade+''',estado='''+sEstado+''''+
  ' where codendereco='+sCodigo
else if sTipo='D' then
  sCons:='delete from Endereco where codendereco='+sCodigo;

result:=sCons;
end;

function TConsultasSQL.Pais(sTipo: char; sCodigo, sPais: string): string;
var sCons: string;
begin
if sTipo='S' then begin
  sCons:='select p.codpais as Código, p.pais as País from Pais p'+
  ' where p.codpais=p.codpais';
  if sCodigo<>'' then
     sCons:=sCons+' and p.codpais='''+sCodigo+'''';
  if spais<>'' then
     sCons:=sCons+' and p.pais like ''%'+sPais+'%''';
end else if sTipo='I' then
  sCons:='insert into Pais(codpais, pais) values('''+
  sCodigo+''','''+spais+''')'
else if sTipo='U' then
  sCons:='update Pais set pais='''+sPais+''''+
  ' where codpais='''+sCodigo+''''
else if sTipo='D' then
  sCons:='delete from Pais where codpais='''+sCodigo+'''';

result:=sCons;
end;

function TConsultasSQL.Profissao(sTipo: char; sCodigo, sProfissao: string): string;
var sCons: string;
begin
if sTipo='N' then
  sCons:='select max(codprofissao)+1 from Profissao'
else if sTipo='S' then begin
  sCons:='select p.codprofissao as Código, p.profissao as Profissão from Profissao p'+
  ' where p.codprofissao=p.codprofissao';
  if sCodigo<>'' then
     sCons:=sCons+' and p.codprofissao='+sCodigo;
  if sProfissao<>'' then
     sCons:=sCons+' and p.profissao like ''%'+sProfissao+'%''';
end else if sTipo='I' then
  sCons:='insert into Profissao(codprofissao, profissao) values('+
  sCodigo+','''+sProfissao+''')'
else if sTipo='U' then
  sCons:='update Profissao set profissao='''+sProfissao+''''+
  ' where codprofissao='+sCodigo
else if sTipo='D' then
  sCons:='delete from Profissao where codprofissao='+sCodigo;

result:=sCons;
end;

function TConsultasSQL.LivroAss(sTipo: char; sISBN, sCodAssunto: string): string;
var sCons: string;
begin
if sTipo='S' then begin
  sCons:='select la.codassunto, a.assunto from LivroAss la, Assunto a'+
  ' where la.codassunto=a.codassunto'+
  ' and la.isbn='''+sISBN+'''';
end else if sTipo='I' then
  sCons:='insert into LivroAss(isbn, codassunto) values('''+
  sISBN+''','+sCodAssunto+')'
else if sTipo='D' then
  sCons:='delete from LivroAss where isbn='''+sISBN+'''';

result:=sCons;
end;

function TConsultasSQL.LivroAut(sTipo: char; sISBN, sCodAutor: string): string;
var sCons: string;
begin
if sTipo='S' then begin
  sCons:='select la.codautor, a.autor from LivroAut la, Autor a'+
  ' where la.codautor=a.codautor'+
  ' and la.isbn='''+sISBN+'''';
end else if sTipo='I' then
  sCons:='insert into LivroAut(isbn, codautor) values('''+
  sISBN+''','+sCodAutor+')'
else if sTipo='D' then
  sCons:='delete from LivroAut where isbn='''+sISBN+'''';

result:=sCons;
end;

function TConsultasSQL.Venda(sTipo: char; sISBN,sCPF,sDataVenda,
                             sPrecoVenda, sQtdEstoque: string): string;
var sCons: string;
begin
if (sTipo='S') or (sTipo='P') then begin
  if sTipo='S' then
     sCons:='select v.datavenda as DataVenda, v.cpf as CPF, c.nome as Cliente,'+
     'v.isbn as ISBN,l.Titulo as Livro, l.preco as Preço'+
     ' from Venda v, Livro l, Cliente c'+
     ' where v.isbn=l.isbn and v.cpf=c.cpf'
  else if sTipo='P' then
     sCons:='select sum(l.preco) as PreçoTotal'+
     ' from Venda v, Livro l, Cliente c'+
     ' where v.isbn=l.isbn and v.cpf=c.cpf';
  if sISBN<>'' then
     sCons:=sCons+' and v.isbn='''+sISBN+'''';
  if sCPF<>'' then
     sCons:=sCons+' and v.cpf='''+sCPF+'''';
  if sDataVenda<>'' then
     sCons:=sCons+' and v.datavenda='''+sDataVenda+'''';
end else if sTipo='I' then
  sCons:='insert into Venda(isbn, cpf, datavenda, precovenda) values('''+
  sISBN+''','''+sCPF+''','''+sDataVenda+''','+sPrecoVenda+')'
else if sTipo='U' then
  sCons:='update Livro set qtdestoque='+sQtdEstoque+' where isbn='''+sISBN+''''
else if sTipo='D' then
  sCons:='delete from Venda where isbn='''+sISBN+
  ''' and cpf='''+sCPF+''' and datavenda='''+sDataVenda+'''';

result:=sCons;
end;

end.
