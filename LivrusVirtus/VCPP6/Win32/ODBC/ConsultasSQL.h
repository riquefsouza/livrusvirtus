#ifndef CONSULTASSQL_H
#define CONSULTASSQL_H

LPTSTR ConsSQL_Assunto(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sAssunto);
LPTSTR ConsSQL_Autor(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sAutor);
LPTSTR ConsSQL_Editora(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sEditora);
LPTSTR ConsSQL_Idioma(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sIdioma);
LPTSTR ConsSQL_Usuario(TCHAR sTipo, LPTSTR sLogin, LPTSTR sSenha);
LPTSTR ConsSQL_Livro(TCHAR sTipo, LPTSTR sISBN, LPTSTR sTitulo, LPTSTR sEdicao,
    LPTSTR sAnoPubli,LPTSTR sVolume,LPTSTR sCodEditora, LPTSTR sCodIdioma,
    LPTSTR sNPaginas,LPTSTR sPreco,LPTSTR sQtdEstoque);
LPTSTR ConsSQL_Cliente(TCHAR sTipo, LPTSTR sCPF,LPTSTR sNome, LPTSTR sEmail,
    LPTSTR sIdentidade,LPTSTR sSexo,LPTSTR sTelefone, LPTSTR sDtNascimento,
    LPTSTR sCodEndereco,LPTSTR sCodPais, LPTSTR sCodProfissao);
LPTSTR ConsSQL_Endereco(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sLogradouro,
    LPTSTR sBairro,LPTSTR sCEP,LPTSTR sCidade, LPTSTR sEstado);
LPTSTR ConsSQL_Pais(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sPais);
LPTSTR ConsSQL_Profissao(TCHAR sTipo, LPTSTR sCodigo, LPTSTR sProfissao);
LPTSTR ConsSQL_LivroAss(TCHAR sTipo, LPTSTR sISBN, LPTSTR sCodAssunto);
LPTSTR ConsSQL_LivroAut(TCHAR sTipo, LPTSTR sISBN, LPTSTR sCodAutor);
LPTSTR ConsSQL_Venda(TCHAR sTipo, LPTSTR sISBN,LPTSTR sCPF, LPTSTR sDataVenda,
    LPTSTR sPrecoVenda,LPTSTR sQtdEstoque);


#endif


