#ifndef CONSULTASSQL_H
#define CONSULTASSQL_H

class CConsultasSQL : public CObject
{
public:  
	CConsultasSQL();
  CString Assunto(TCHAR sTipo, CString sCodigo, CString sAssunto);
  CString Autor(TCHAR sTipo, CString sCodigo, CString sAutor);
  CString Editora(TCHAR sTipo, CString sCodigo, CString sEditora);
  CString Idioma(TCHAR sTipo, CString sCodigo, CString sIdioma);
  CString Usuario(TCHAR sTipo, CString sLogin, CString sSenha);
  CString Livro(TCHAR sTipo, CString sISBN, CString sTitulo, CString sEdicao,
      CString sAnoPubli,CString sVolume,CString sCodEditora, CString sCodIdioma,
      CString sNPaginas,CString sPreco,CString sQtdEstoque);
  CString Cliente(TCHAR sTipo, CString sCPF,CString sNome, CString sEmail,
      CString sIdentidade,CString sSexo,CString sTelefone, CString sDtNascimento,
      CString sCodEndereco,CString sCodPais, CString sCodProfissao);
  CString Endereco(TCHAR sTipo, CString sCodigo, CString sLogradouro,
      CString sBairro,CString sCEP,CString sCidade, CString sEstado);
  CString Pais(TCHAR sTipo, CString sCodigo, CString sPais);
  CString Profissao(TCHAR sTipo, CString sCodigo, CString sProfissao);
  CString LivroAss(TCHAR sTipo, CString sISBN, CString sCodAssunto);
  CString LivroAut(TCHAR sTipo, CString sISBN, CString sCodAutor);
  CString Venda(TCHAR sTipo, CString sISBN,CString sCPF, CString sDataVenda,
      CString sPrecoVenda,CString sQtdEstoque);
};

static CConsultasSQL *ConsSQL;

#endif


