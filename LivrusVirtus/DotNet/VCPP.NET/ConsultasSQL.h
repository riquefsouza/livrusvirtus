#pragma once

namespace Livrus
{
  /// <summary>
  /// Summary description for Class.
  /// </summary>
  public __gc class ConsultasSQL : public System::Object
  {
  public: 
      static ConsultasSQL* ConsSQL;
  
      ConsultasSQL(void);
      String* Assunto(char sTipo, String* sCodigo, String* sAssunto);
      String* Autor(char sTipo, String* sCodigo, String* sAutor);
      String* Editora(char sTipo, String* sCodigo, String* sEditora);
      String* Idioma(char sTipo, String* sCodigo, String* sIdioma);
      String* Usuario(char sTipo, String* sLogin, String* sSenha);
      String* Livro(char sTipo, String* sISBN, String* sTitulo, String* sEdicao,
      String* sAnoPubli,String* sVolume,String* sCodEditora, String* sCodIdioma,
      String* sNPaginas,String* sPreco,String* sQtdEstoque);
      String* Cliente(char sTipo, String* sCPF,String* sNome, String* sEmail,
      String* sIdentidade,String* sSexo,String* sTelefone, String* sDtNascimento,
      String* sCodEndereco,String* sCodPais, String* sCodProfissao);
      String* Endereco(char sTipo, String* sCodigo, String* sLogradouro,
      String* sBairro,String* sCEP,String* sCidade, String* sEstado);
      String* Pais(char sTipo, String* sCodigo, String* sPais);
      String* Profissao(char sTipo, String* sCodigo, String* sProfissao);
      String* LivroAss(char sTipo, String* sISBN, String* sCodAssunto);
      String* LivroAut(char sTipo, String* sISBN, String* sCodAutor);
      String* Venda(char sTipo, String* sISBN,String* sCPF, String* sDataVenda,
      String* sPrecoVenda,String* sQtdEstoque);
  };

}
