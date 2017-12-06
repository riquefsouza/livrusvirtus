#ifndef CONSULTASSQL_H
#define CONSULTASSQL_H

#include "resource.h"

class CConsultasSQL
{
public:  
	CConsultasSQL();
  string Assunto(char sTipo, string sCodigo, string sAssunto);
  string Autor(char sTipo, string sCodigo, string sAutor);
  string Editora(char sTipo, string sCodigo, string sEditora);
  string Idioma(char sTipo, string sCodigo, string sIdioma);
  string Usuario(char sTipo, string sLogin, string sSenha);
  string Livro(char sTipo, string sISBN, string sTitulo, string sEdicao,
      string sAnoPubli,string sVolume,string sCodEditora, string sCodIdioma,
      string sNPaginas,string sPreco,string sQtdEstoque);
  string Cliente(char sTipo, string sCPF,string sNome, string sEmail,
      string sIdentidade,string sSexo,string sTelefone, string sDtNascimento,
      string sCodEndereco,string sCodPais, string sCodProfissao);
  string Endereco(char sTipo, string sCodigo, string sLogradouro,
      string sBairro,string sCEP,string sCidade, string sEstado);
  string Pais(char sTipo, string sCodigo, string sPais);
  string Profissao(char sTipo, string sCodigo, string sProfissao);
  string LivroAss(char sTipo, string sISBN, string sCodAssunto);
  string LivroAut(char sTipo, string sISBN, string sCodAutor);
  string Venda(char sTipo, string sISBN,string sCPF, string sDataVenda,
      string sPrecoVenda,string sQtdEstoque);
};

extern CConsultasSQL *ConsSQL;

#endif


