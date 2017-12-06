#ifndef CONSULTASSQL_H
#define CONSULTASSQL_H

class CConsultasSQL : public wxObject {
public: 
  CConsultasSQL();
  ~CConsultasSQL();
  wxString Assunto(wxChar sTipo, wxString sCodigo, wxString sAssunto);
  wxString Autor(wxChar sTipo, wxString sCodigo, wxString sAutor);
  wxString Editora(wxChar sTipo, wxString sCodigo, wxString sEditora);
  wxString Idioma(wxChar sTipo, wxString sCodigo, wxString sIdioma);
  wxString Usuario(wxChar sTipo, wxString sLogin, wxString sSenha);
  wxString Livro(wxChar sTipo, wxString sISBN, wxString sTitulo, wxString sEdicao,
    wxString sAnoPubli,wxString sVolume,wxString sCodEditora, wxString sCodIdioma,
    wxString sNPaginas,wxString sPreco,wxString sQtdEstoque);
  wxString Cliente(wxChar sTipo, wxString sCPF,wxString sNome, wxString sEmail,
    wxString sIdentidade,wxString sSexo,wxString sTelefone, wxString sDtNascimento,
    wxString sCodEndereco,wxString sCodPais, wxString sCodProfissao);
  wxString Endereco(wxChar sTipo, wxString sCodigo, wxString sLogradouro,
    wxString sBairro,wxString sCEP,wxString sCidade, wxString sEstado);
  wxString Pais(wxChar sTipo, wxString sCodigo, wxString sPais);
  wxString Profissao(wxChar sTipo, wxString sCodigo, wxString sProfissao);
  wxString LivroAss(wxChar sTipo, wxString sISBN, wxString sCodAssunto);
  wxString LivroAut(wxChar sTipo, wxString sISBN, wxString sCodAutor);
  wxString Venda(wxChar sTipo, wxString sISBN,wxString sCPF, wxString sDataVenda,
    wxString sPrecoVenda,wxString sQtdEstoque);
};

extern CConsultasSQL *ConsSQL;

#endif

