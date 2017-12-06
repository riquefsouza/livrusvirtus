IMPLEMENTATION MODULE Arquivos;


FROM SYSTEM IMPORT  WORD, ADR, ADDRESS;
FROM ASCII IMPORT nul, cr, lf;
FROM Rotinas IMPORT String, WriteLinha, trim, copy, esp, stemp, Ss,
     SomaStr, equal;
FROM NumberConversion IMPORT StringToCard, CardToString;
FROM Strings IMPORT Length, Append, Copy, CompareStr;
FROM FileSystem IMPORT File, Lookup, ReadNBytes, SetPos, WriteNBytes,
     Response, Close, GetPos;
IMPORT FileSystem; (* Length *)

(*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*)
PROCEDURE tamArq(VAR sArq: File): CARDINAL;
VAR nmaxtam, nmintam: CARDINAL;
BEGIN
FileSystem.Length(sArq, nmaxtam, nmintam);
RETURN nmaxtam;
END tamArq;

(*------------------------------------------------------------------------------
Verifica se chegou ao fim do arquivo.
sArq - o arquivo
ntam - o tamanho do arquivo
retorna - se chegou ao fim do arquivo
------------------------------------------------------------------------------*)
PROCEDURE fimArq(VAR sArq: File): BOOLEAN;
BEGIN
  RETURN sArq.eof;
END fimArq;

(*------------------------------------------------------------------------------
Lê uma linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho da linha
nTamCRLF - o tamanho do retorno da linha
npos - posicao dentro do arquivo
retorna - o texto lido
------------------------------------------------------------------------------*)
PROCEDURE lerArq(VAR sArq: File; nTamLinha, nTamCRLF: CARDINAL;
VAR npos: CARDINAL): String;
VAR nLidos: CARDINAL;
    slinha: String;
BEGIN
ReadNBytes(sArq, ADR(slinha), nTamLinha, nLidos);
IF nLidos <> nTamLinha THEN
   slinha:='';
ELSE
  slinha[nTamLinha]:=nul;
  npos:=npos + (nTamLinha + nTamCRLF);
  SetPos(tfAssunto, 0, npos);
END;
RETURN slinha;
END lerArq;

(*------------------------------------------------------------------------------
Grava uma linha no arquivo.
sArq - o arquivo
nTamLinha - o tamanho da linha
nTamCRLF - o tamanho do retorno da linha
sLinha - o texto a ser gravado
------------------------------------------------------------------------------*)
PROCEDURE gravarArq(VAR sArq: File; nTamLinha, nTamCRLF: CARDINAL;
          slinha: String): CARDINAL;
VAR ngravados: CARDINAL;
BEGIN
WriteNBytes(sArq, ADR(slinha), (nTamLinha + nTamCRLF), ngravados);
RETURN ngravados;
END gravarArq;

(*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*)
PROCEDURE abrecriaArqs(bAbre: BOOLEAN);
BEGIN
 IF bAbre THEN 
   Lookup(tfAssunto, ARQ_ASSUNTO, FALSE);
   IF tfAssunto.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_ASSUNTO));
   END; 
   Lookup(tfAutor, ARQ_AUTOR, FALSE);
   IF tfAutor.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_AUTOR));
   END; 
   Lookup(tfEditora, ARQ_EDITORA, FALSE);
   IF tfEditora.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_EDITORA));
   END; 
   Lookup(tfIdioma, ARQ_IDIOMA, FALSE);
   IF tfIdioma.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_IDIOMA));
   END; 
   Lookup(tfEndereco, ARQ_ENDERECO, FALSE);
   IF tfEndereco.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_ENDERECO));
   END; 
   Lookup(tfPais, ARQ_PAIS, FALSE);
   IF tfPais.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_PAIS));
   END; 
   Lookup(tfProfissao, ARQ_PROFISSAO, FALSE);
   IF tfProfissao.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_PROFISSAO));
   END; 
   Lookup(tfLivro, ARQ_LIVRO, FALSE);
   IF tfLivro.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_LIVRO));
   END; 
   Lookup(tfLivroAss, ARQ_LIVASS, FALSE);
   IF tfLivroAss.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_LIVASS));
   END; 
   Lookup(tfLivroAut, ARQ_LIVAUT, FALSE);
   IF tfLivroAut.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_LIVAUT));
   END; 
   Lookup(tfCliente, ARQ_CLIENTE, FALSE);
   IF tfCliente.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_CLIENTE));
   END; 
   Lookup(tfUsuario, ARQ_USUARIO, FALSE);
   IF tfUsuario.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_USUARIO));
   END; 
   Lookup(tfVenda, ARQ_VENDA, FALSE);
   IF tfVenda.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQERRO, ' --> '), ARQ_VENDA));
   END; 
 ELSE 
   Lookup(tfAssunto, ARQ_ASSUNTO, TRUE);
   IF tfAssunto.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_ASSUNTO));
   END; 
   Lookup(tfAutor, ARQ_AUTOR, TRUE);
   IF tfAutor.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_AUTOR));
   END; 
   Lookup(tfEditora, ARQ_EDITORA, TRUE);
   IF tfEditora.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_EDITORA));
   END; 
   Lookup(tfIdioma, ARQ_IDIOMA, TRUE);
   IF tfIdioma.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_IDIOMA));
   END; 
   Lookup(tfEndereco, ARQ_ENDERECO, TRUE);
   IF tfEndereco.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_ENDERECO));
   END; 
   Lookup(tfPais, ARQ_PAIS, TRUE);
   IF tfPais.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_PAIS));
   END; 
   Lookup(tfProfissao, ARQ_PROFISSAO, TRUE);
   IF tfProfissao.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_PROFISSAO));
   END; 
   Lookup(tfLivro, ARQ_LIVRO, TRUE);
   IF tfLivro.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_LIVRO));
   END; 
   Lookup(tfLivroAss, ARQ_LIVASS, TRUE);
   IF tfLivroAss.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_LIVASS));
   END; 
   Lookup(tfLivroAut, ARQ_LIVAUT, TRUE);
   IF tfLivroAut.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_LIVAUT));
   END; 
   Lookup(tfCliente, ARQ_CLIENTE, TRUE);
   IF tfCliente.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_CLIENTE));
   END; 
   Lookup(tfUsuario, ARQ_USUARIO, TRUE);
   IF tfUsuario.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_USUARIO));
   END; 
   Lookup(tfVenda, ARQ_VENDA, TRUE);
   IF tfVenda.res=notdone THEN
      WriteLinha(Ss(Ss(MSG_ARQCERRO, ' --> '), ARQ_VENDA));
   END; 
 END;
END abrecriaArqs;
(*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*)
PROCEDURE fechaArqs();
BEGIN
 Close(tfAssunto);
 Close(tfAutor);
 Close(tfEditora);
 Close(tfIdioma);
 Close(tfEndereco);
 Close(tfPais);
 Close(tfProfissao);
 Close(tfLivro);
 Close(tfLivroAss);
 Close(tfLivroAut);
 Close(tfCliente);
 Close(tfUsuario);
 Close(tfVenda);
END fechaArqs;

(*------------------------------------------------------------------------------
Pesquisa um registro através de um valor chave num arquivo.
sArq - o arquivo
sChave - a chave a ser pesquisada
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o registro pesquisado
------------------------------------------------------------------------------*)
PROCEDURE pesqArq(VAR sArq: File; sChave: String; nPosChave,
        nTamChave, nTamLinha: CARDINAL): String;
VAR slinha: String;
    sres: String;
    bQuebra: BOOLEAN;
    nPosicao, npos: CARDINAL;
BEGIN
bQuebra:=FALSE;
npos:=0;
SetPos(sArq, 0, 0);
WHILE (NOT fimArq(sArq)) AND (bQuebra=FALSE) DO 
  slinha:=lerArq(sArq, nTamLinha, TAM_CRLF, npos);
  sres:=trim(copy(slinha,nPosChave,nTamChave));
  IF CompareStr(sres, sChave)=equal THEN
     bQuebra:=TRUE;
  END;
END;
GetPos(sArq, npos, nPosicao);
nPosicao:=nPosicao-(nTamLinha + TAM_CRLF);
IF nPosicao > 0 THEN
   SetPos(sArq, 0, nPosicao);
ELSE
   SetPos(sArq, 0, 0);
END;
IF CompareStr(sres,sChave)<>equal THEN
   sres:='';
   RETURN sres;
ELSE
   RETURN copy(slinha,1,nTamLinha);
END;
END pesqArq;
(*------------------------------------------------------------------------------
Pesquisa se tem linha excluída senão vai para a última linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho do registro
------------------------------------------------------------------------------*)
PROCEDURE pesqLinhaExcluida(VAR sArq: File; nTamLinha: CARDINAL);
VAR sExcluido: String;
BEGIN
sExcluido:=pesqArq(sArq, '*', 1, 1, nTamLinha);
IF CompareStr(sExcluido,'')=equal THEN
   SetPos(sArq, 0, tamArq(sArq));
END;
END pesqLinhaExcluida;
(*------------------------------------------------------------------------------
Pesquisa o maior código num arquivo.
sArq - o arquivo
nPosChave - a posicao inicial da chave dentro do registro
nTamChave - o tamanho da chave dentro do registro
nTamLinha - o tamanho do registro
retorna - o maior código
------------------------------------------------------------------------------*)
PROCEDURE pesqMaxCod(VAR sArq: File; nPosChave,
        nTamChave, nTamLinha: CARDINAL): String;
VAR slinha: String;
    sres: String;
    bQuebra: BOOLEAN;
    nMaior, nCod, npos: CARDINAL;
    nStatus: BOOLEAN;
BEGIN
bQuebra:=FALSE;
nMaior:=0;
npos:=0;
SetPos(sArq, 0, 0);
WHILE (NOT fimArq(sArq)) AND (bQuebra=FALSE) DO 
  slinha:=lerArq(sArq, nTamLinha, TAM_CRLF, npos);  
  sres:=trim(copy(slinha,nPosChave,nTamChave));     
  StringToCard(sres, nCod, nStatus);
  IF nCod > nMaior THEN
     nMaior:=nCod;
  END;   
END;
pesqLinhaExcluida(sArq, nTamLinha);
CardToString((nMaior+1), sres, 7);
RETURN trim(sres);
END pesqMaxCod;
(*------------------------------------------------------------------------------
Grava os registros num determinado arquivo.
sArq - o arquivo
sTexto - o registro a ser gravado
sMsgAcerto - a mensagem caso o registro foi gravado
sMsgErro - a mensagem caso o registro não foi gravado
------------------------------------------------------------------------------*)
PROCEDURE escreveArq(VAR sArq: File; sTexto, sMsgAcerto,
	sMsgErro: String);
VAR ntam, nStatus: CARDINAL;
BEGIN
ntam:=Length(sTexto);
(*Append(sTexto, CRLF);*)
sTexto[ntam]:=cr;
sTexto[ntam+1]:=lf;
nStatus:=gravarArq(sArq, ntam, TAM_CRLF, sTexto);
IF nStatus > 0 THEN
   WriteLinha(sMsgAcerto);
ELSE
   WriteLinha(sMsgErro);
END;
END escreveArq;
(*------------------------------------------------------------------------------
Retorna o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o tamanho do registro
------------------------------------------------------------------------------*)
PROCEDURE tamReg(sreg: ctArqs): CARDINAL;
VAR nret: CARDINAL;
BEGIN
nret:=0;
IF sreg=opAssunto THEN nret:=TAM_ASSUNTO;
ELSIF sreg=opAutor THEN nret:=TAM_AUTOR;
ELSIF sreg=opEditora THEN nret:=TAM_EDITORA;
ELSIF sreg=opEndereco THEN nret:=TAM_ENDERECO;
ELSIF sreg=opIdioma THEN nret:=TAM_IDIOMA;
ELSIF sreg=opPais THEN nret:=TAM_PAIS;
ELSIF sreg=opProfissao THEN nret:=TAM_PROFISSAO;
ELSIF sreg=opUsuario THEN nret:=TAM_USUARIO;
ELSIF sreg=opLivro THEN nret:=TAM_LIVRO;
ELSIF sreg=opLivroAss THEN nret:=TAM_LIVASS;
ELSIF sreg=opLivroAut THEN nret:=TAM_LIVAUT;
ELSIF sreg=opCliente THEN nret:=TAM_CLIENTE;
ELSIF sreg=opVenda THEN nret:=TAM_VENDA;
END;
RETURN nret;
END tamReg;

(*------------------------------------------------------------------------------
Monta o tamanho do registro no arquivo de acordo com o tipo de arquivo.
sreg - o tipo de arquivo
retorna - o registro montado
------------------------------------------------------------------------------*)
PROCEDURE LinhaReg(sreg: ctArqs): String;
VAR slinha: String;
BEGIN
slinha:='';
IF sreg=opAssunto THEN
   slinha:=Ss(esp(tAssunto.codigo,10),esp(tAssunto.assunto,30));
ELSIF sreg=opAutor THEN   
   slinha:=Ss(esp(tAutor.codigo,10),esp(tAutor.autor,30));
ELSIF sreg=opEditora THEN
   slinha:=Ss(esp(tEditora.codigo,10),esp(tEditora.editora,50));
ELSIF sreg=opEndereco THEN
   stemp[0]:=esp(tEndereco.codigo,10);
   stemp[1]:=esp(tEndereco.logradouro,40);
   stemp[2]:=esp(tEndereco.bairro,15);
   stemp[3]:=esp(tEndereco.cep,8);
   stemp[4]:=esp(tEndereco.cidade,30);
   stemp[5]:=esp(tEndereco.estado,20);
   slinha:=SomaStr(6,stemp);
ELSIF sreg=opIdioma THEN   
   slinha:=Ss(esp(tIdioma.codigo,10),esp(tIdioma.idioma,20));
ELSIF sreg=opPais THEN   
   slinha:=Ss(esp(tPais.codigo,3),esp(tPais.pais,50));
ELSIF sreg=opProfissao THEN   
   slinha:=Ss(esp(tProfissao.codigo,10),esp(tProfissao.profissao,50));
ELSIF sreg=opUsuario THEN   
   slinha:=Ss(esp(tUsuario.login,10),esp(tUsuario.senha,10));
ELSIF sreg=opLivro THEN
   stemp[0]:=esp(tLivro.isbn,13);
   stemp[1]:=esp(tLivro.titulo,50);
   stemp[2]:=esp(tLivro.edicao,10);
   stemp[3]:=esp(tLivro.anopubli,10);
   stemp[4]:=esp(tLivro.codeditora,10);
   stemp[5]:=esp(tLivro.volume,10);
   stemp[6]:=esp(tLivro.codidioma,10);
   stemp[7]:=esp(tLivro.npaginas,10);
   stemp[8]:=esp(tLivro.preco,10);
   stemp[9]:=esp(tLivro.qtdestoque,10);
   slinha:=SomaStr(10,stemp);
ELSIF sreg=opLivroAss THEN
   slinha:=Ss(esp(tLivroAss.isbn,13),esp(tLivroAss.codassunto,10));
ELSIF sreg=opLivroAut THEN   
   slinha:=Ss(esp(tLivroAut.isbn,13),esp(tLivroAut.codautor,10));
ELSIF sreg=opCliente THEN
   stemp[0]:=esp(tCliente.cpf,14);
   stemp[1]:=esp(tCliente.nome,30);
   stemp[2]:=esp(tCliente.email,30);
   stemp[3]:=esp(tCliente.identidade,10);
   stemp[4]:=esp(tCliente.sexo,1);
   stemp[5]:=esp(tCliente.telefone,17);
   stemp[6]:=esp(tCliente.dtnascimento,10);
   stemp[7]:=esp(tCliente.codendereco,10);
   stemp[8]:=esp(tCliente.codpais,3);
   stemp[9]:=esp(tCliente.codprofissao,10);
   slinha:=SomaStr(10,stemp);
ELSIF sreg=opVenda THEN
   stemp[0]:=esp(tVenda.dthrvenda,19);
   stemp[1]:=esp(tVenda.cpf,14);
   stemp[2]:=esp(tVenda.isbn,13);
   stemp[3]:=esp(tVenda.precovenda,10);
   slinha:=SomaStr(4,stemp);
END;

RETURN slinha;
END LinhaReg;

END Arquivos.
