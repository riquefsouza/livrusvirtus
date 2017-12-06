IMPLEMENTATION MODULE Arquivos;

FROM Rotinas IMPORT WriteLinha, trim, copy, esp, stemp, Ss, SomaStr;
FROM CardStr IMPORT Value, Give, Alignment;
FROM Ascii IMPORT lf, cr, nul;
FROM StdStrings IMPORT String, Length, Delete, Assign,
Append, Extract, Compare, CompareResult;
FROM SYSTEM IMPORT CAST, ADDRESS, BYTE;
FROM Terminal IMPORT WriteString, GetKeyStroke, WriteLn;
FROM UxFiles IMPORT File, Open, Close, OpenMode, Create, SetPos, EndFile,
ReadByte, WriteByte, FileSize, GetPos;

FROM InOut IMPORT WriteCard, ReadLn;

(*------------------------------------------------------------------------------
Calcula o tamanho do arquivo.
sArq - o arquivo
retorna - o tamanho do arquivo
------------------------------------------------------------------------------*)
PROCEDURE tamArq(VAR sArq: File): CARDINAL;
VAR ntam: CARDINAL;
    bok: BOOLEAN;
BEGIN
IF sArq = tfAssunto THEN FileSize(ARQ_ASSUNTO, ntam, bok);
ELSIF sArq = tfAutor THEN FileSize(ARQ_AUTOR, ntam, bok);
ELSIF sArq = tfEditora THEN FileSize(ARQ_EDITORA, ntam, bok);
ELSIF sArq = tfIdioma THEN FileSize(ARQ_IDIOMA, ntam, bok);
ELSIF sArq = tfEndereco THEN FileSize(ARQ_ENDERECO, ntam, bok);
ELSIF sArq = tfPais THEN FileSize(ARQ_PAIS, ntam, bok);
ELSIF sArq = tfProfissao THEN FileSize(ARQ_PROFISSAO, ntam, bok);
ELSIF sArq = tfLivro THEN FileSize(ARQ_LIVRO, ntam, bok);
ELSIF sArq = tfLivroAss THEN FileSize(ARQ_LIVASS, ntam, bok);
ELSIF sArq = tfLivroAut THEN FileSize(ARQ_LIVAUT, ntam, bok);
ELSIF sArq = tfCliente THEN FileSize(ARQ_CLIENTE, ntam, bok);
ELSIF sArq = tfUsuario THEN FileSize(ARQ_USUARIO, ntam, bok);
ELSIF sArq = tfVenda THEN FileSize(ARQ_VENDA, ntam, bok);
END;

RETURN ntam;
END tamArq;

(*------------------------------------------------------------------------------
Verifica se chegou ao fim do arquivo.
sArq - o arquivo
ntam - o tamanho do arquivo
retorna - se chegou ao fim do arquivo
------------------------------------------------------------------------------*)
PROCEDURE fimArq(VAR sArq: File; ntam: CARDINAL): BOOLEAN;
VAR npos: CARDINAL;
BEGIN
 GetPos(sArq, npos);
 IF (npos = ntam) OR (ntam=999999) THEN
    RETURN TRUE;
 ELSE
    RETURN FALSE;
 END;
END fimArq;

(*------------------------------------------------------------------------------
Lê uma linha do arquivo.
sArq - o arquivo
nTamLinha - o tamanho da linha
nTamCRLF - o tamanho do retorno da linha
retorna - o texto lido
------------------------------------------------------------------------------*)
PROCEDURE lerArq(VAR sArq: File; nTamLinha, nTamCRLF: CARDINAL): String;
VAR sletra: BYTE; 
    cletra: CHAR;
    stexto: tregistro;
    ncont: CARDINAL;
    slinha: String;
BEGIN
ncont:=0;
  WHILE ncont < (nTamLinha + nTamCRLF) DO  
    ReadByte(sArq, sletra);
    cletra:=CAST(CHAR,sletra);
    stexto[ncont]:=cletra;
    ncont:=ncont+1;
    IF ncont=(nTamLinha + nTamCRLF) THEN
      stexto[nTamLinha+1]:=nul;
    END; 
  END; 
slinha:=CAST(String, stexto);
RETURN slinha;
END lerArq;

(*------------------------------------------------------------------------------
Grava uma linha no arquivo.
sArq - o arquivo
nTamLinha - o tamanho da linha
nTamCRLF - o tamanho do retorno da linha
sLinha - o texto a ser gravado
------------------------------------------------------------------------------*)
PROCEDURE gravarArq(VAR sArq: File; nTamLinha, nTamCRLF: CARDINAL; sLinha: String);
VAR sletra: BYTE; 
    cletra: CHAR;
    stexto: tregistro;
    ncont: CARDINAL;
BEGIN
ncont:=0;
stexto:=CAST(tregistro, sLinha);
  WHILE ncont < (nTamLinha + nTamCRLF) DO  
    cletra:=stexto[ncont];
    sletra:=CAST(BYTE,cletra);
    WriteByte(sArq, sletra);
    ncont:=ncont+1;
  END; 
END gravarArq;

(*------------------------------------------------------------------------------
Abre ou cria os arquivos do sistema.
bAbre - condição para abrir ou criar os arquivos do sistema
------------------------------------------------------------------------------*)
PROCEDURE abrecriaArqs(bAbre: BOOLEAN);
VAR bStatus: BOOLEAN;
BEGIN
 IF bAbre THEN 
   Open(tfAssunto, ARQ_ASSUNTO,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_ASSUNTO);
   END; 
   Open(tfAutor, ARQ_AUTOR,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_AUTOR);
   END; 
   Open(tfEditora, ARQ_EDITORA,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_EDITORA);
   END; 
   Open(tfIdioma, ARQ_IDIOMA,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_IDIOMA);
   END; 
   Open(tfEndereco, ARQ_ENDERECO,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_ENDERECO);
   END; 
   Open(tfPais, ARQ_PAIS,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_PAIS);
   END; 
   Open(tfProfissao, ARQ_PROFISSAO,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_PROFISSAO);
   END; 
   Open(tfLivro, ARQ_LIVRO,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_LIVRO);
   END; 
   Open(tfLivroAss, ARQ_LIVASS,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_LIVASS);
   END; 
   Open(tfLivroAut, ARQ_LIVAUT,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_LIVAUT);
   END; 
   Open(tfCliente, ARQ_CLIENTE,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_CLIENTE);
   END; 
   Open(tfUsuario, ARQ_USUARIO,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_USUARIO);
   END; 
   Open(tfVenda, ARQ_VENDA,ReadWrite,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_VENDA);
   END; 
 ELSE 
   Create(tfAssunto, ARQ_ASSUNTO,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_ASSUNTO);
   END; 
   Create(tfAutor, ARQ_AUTOR,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_AUTOR);
   END; 
   Create(tfEditora, ARQ_EDITORA,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_EDITORA);
   END; 
   Create(tfIdioma, ARQ_IDIOMA,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_IDIOMA);
   END; 
   Create(tfEndereco, ARQ_ENDERECO,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_ENDERECO);
   END; 
   Create(tfPais, ARQ_PAIS,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_PAIS);
   END; 
   Create(tfProfissao, ARQ_PROFISSAO,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_PROFISSAO);
   END; 
   Create(tfLivro, ARQ_LIVRO,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_LIVRO);
   END; 
   Create(tfLivroAss, ARQ_LIVASS,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_LIVASS);
   END; 
   Create(tfLivroAut, ARQ_LIVAUT,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_LIVAUT);
   END; 
   Create(tfCliente, ARQ_CLIENTE,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_CLIENTE);
   END; 
   Create(tfUsuario, ARQ_USUARIO,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_USUARIO);
   END; 
   Create(tfVenda, ARQ_VENDA,bStatus);
   IF bStatus=FALSE THEN
      WriteLinha(MSG_ARQERRO + ' --> ' + ARQ_VENDA);
   END; 
 END;
END abrecriaArqs;
(*------------------------------------------------------------------------------
Fecha todos os arquivos abertos.
------------------------------------------------------------------------------*)
PROCEDURE fechaArqs();
VAR bStatus: BOOLEAN;
BEGIN
 Close(tfAssunto, bStatus);
 Close(tfAutor, bStatus);
 Close(tfEditora, bStatus);
 Close(tfIdioma, bStatus);
 Close(tfEndereco, bStatus);
 Close(tfPais, bStatus);
 Close(tfProfissao, bStatus);
 Close(tfLivro, bStatus);
 Close(tfLivroAss, bStatus);
 Close(tfLivroAut, bStatus);
 Close(tfCliente, bStatus);
 Close(tfUsuario, bStatus);
 Close(tfVenda, bStatus);
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
    nPosicao, ntam: CARDINAL;
BEGIN
bQuebra:=FALSE;
ntam:=tamArq(sArq);
SetPos(sArq, 0);
WHILE (NOT fimArq(sArq, ntam)) AND (bQuebra=FALSE) DO 
  slinha:=lerArq(sArq, nTamLinha, TAM_CRLF);
  IF NOT fimArq(sArq, ntam) THEN
    sres:=trim(copy(slinha,nPosChave,nTamChave));
    IF Compare(sres, sChave)=equal THEN      
       bQuebra:=TRUE;
    END;
  END;
END;
GetPos(sArq, nPosicao);
nPosicao:=nPosicao-(nTamLinha + TAM_CRLF);
IF nPosicao > 0 THEN
   SetPos(sArq, nPosicao);
ELSE
   SetPos(sArq, 0);
END;
IF Compare(sres,sChave)<>equal THEN
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
IF Compare(sExcluido,'')=equal THEN
   SetPos(sArq, tamArq(sArq));
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
    nMaior, nCod, ntam: CARDINAL;
BEGIN
bQuebra:=FALSE;
nMaior:=0;
ntam:=tamArq(sArq);
SetPos(sArq, 0);
WHILE (NOT fimArq(sArq, ntam)) AND (bQuebra=FALSE) DO 
  slinha:=lerArq(sArq, nTamLinha, TAM_CRLF);
  IF NOT fimArq(sArq, ntam) THEN
    sres:=trim(copy(slinha,nPosChave,nTamChave));     
    nCod:=Value(sres);
    IF nCod > nMaior THEN
       nMaior:=nCod;
    END;   
  END;
END;
pesqLinhaExcluida(sArq, nTamLinha);
Give(sres,(nMaior+1),10,left); 
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
BEGIN
Append(CRLF, sTexto);
gravarArq(sArq, Length(sTexto), TAM_CRLF, sTexto);
(* IF nStatus > 0 THEN  *)
   WriteLinha(sMsgAcerto);
(*ELSE 
   WriteLinha(sMsgErro);
END; *)
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
