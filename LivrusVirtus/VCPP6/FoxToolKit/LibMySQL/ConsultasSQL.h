#ifndef CONSULTASSQL_H
#define CONSULTASSQL_H

class CConsultasSQL {
public: 
  CConsultasSQL();
  ~CConsultasSQL();
  FXString Assunto(FXchar sTipo, FXString sCodigo, FXString sAssunto);
  FXString Autor(FXchar sTipo, FXString sCodigo, FXString sAutor);
  FXString Editora(FXchar sTipo, FXString sCodigo, FXString sEditora);
  FXString Idioma(FXchar sTipo, FXString sCodigo, FXString sIdioma);
  FXString Usuario(FXchar sTipo, FXString sLogin, FXString sSenha);
  FXString Livro(FXchar sTipo, FXString sISBN, FXString sTitulo, FXString sEdicao,
    FXString sAnoPubli,FXString sVolume,FXString sCodEditora, FXString sCodIdioma,
    FXString sNPaginas,FXString sPreco,FXString sQtdEstoque);
  FXString Cliente(FXchar sTipo, FXString sCPF,FXString sNome, FXString sEmail,
    FXString sIdentidade,FXString sSexo,FXString sTelefone, FXString sDtNascimento,
    FXString sCodEndereco,FXString sCodPais, FXString sCodProfissao);
  FXString Endereco(FXchar sTipo, FXString sCodigo, FXString sLogradouro,
    FXString sBairro,FXString sCEP,FXString sCidade, FXString sEstado);
  FXString Pais(FXchar sTipo, FXString sCodigo, FXString sPais);
  FXString Profissao(FXchar sTipo, FXString sCodigo, FXString sProfissao);
  FXString LivroAss(FXchar sTipo, FXString sISBN, FXString sCodAssunto);
  FXString LivroAut(FXchar sTipo, FXString sISBN, FXString sCodAutor);
  FXString Venda(FXchar sTipo, FXString sISBN,FXString sCPF, FXString sDataVenda,
    FXString sPrecoVenda,FXString sQtdEstoque);
};

extern CConsultasSQL *ConsSQL;

#endif
