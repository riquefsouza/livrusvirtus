#ifndef CONSULTASSQL_H
  #define CONSULTASSQL_H

  #include "resource.h"

  class CConsultasSQL {
  public:
    CConsultasSQL();
    ~CConsultasSQL();
    Glib::ustring Assunto(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sAssunto);
    Glib::ustring Autor(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sAutor);
    Glib::ustring Editora(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sEditora);
    Glib::ustring Idioma(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sIdioma);
    Glib::ustring Usuario(char sTipo, Glib::ustring sLogin,
     Glib::ustring sSenha);
    Glib::ustring Livro(char sTipo, Glib::ustring sISBN,
     Glib::ustring sTitulo, Glib::ustring sEdicao,
     Glib::ustring sAnoPubli, Glib::ustring sVolume,
     Glib::ustring sCodEditora, Glib::ustring sCodIdioma,
     Glib::ustring sNPaginas, Glib::ustring sPreco,
     Glib::ustring sQtdEstoque);
    Glib::ustring Cliente(char sTipo, Glib::ustring sCPF,
     Glib::ustring sNome, Glib::ustring sEmail,
     Glib::ustring sIdentidade, Glib::ustring sSexo,
     Glib::ustring sTelefone, Glib::ustring sDtNascimento,
     Glib::ustring sCodEndereco, Glib::ustring sCodPais,
     Glib::ustring sCodProfissao);
    Glib::ustring Endereco(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sLogradouro, Glib::ustring sBairro,
     Glib::ustring sCEP, Glib::ustring sCidade,
     Glib::ustring sEstado);
    Glib::ustring Pais(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sPais);
    Glib::ustring Profissao(char sTipo, Glib::ustring sCodigo,
     Glib::ustring sProfissao);
    Glib::ustring LivroAss(char sTipo, Glib::ustring sISBN,
     Glib::ustring sCodAssunto);
    Glib::ustring LivroAut(char sTipo, Glib::ustring sISBN,
     Glib::ustring sCodAutor);
    Glib::ustring Venda(char sTipo, Glib::ustring sISBN,
     Glib::ustring sCPF, Glib::ustring sDataVenda,
     Glib::ustring sPrecoVenda, Glib::ustring sQtdEstoque);
  };

  extern CConsultasSQL * ConsSQL;

#endif
