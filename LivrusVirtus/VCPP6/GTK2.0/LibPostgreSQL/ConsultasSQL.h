#include <gtk/gtk.h>

GString* ConsSQL_Assunto(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sAssunto);
GString* ConsSQL_Autor(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sAutor);
GString* ConsSQL_Editora(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sEditora);
GString* ConsSQL_Idioma(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sIdioma);
GString* ConsSQL_Usuario(gchar sTipo, G_CONST_RETURN gchar* sLogin, 
  G_CONST_RETURN gchar* sSenha);
GString* ConsSQL_Livro(gchar sTipo, G_CONST_RETURN gchar* sISBN, 
  G_CONST_RETURN gchar* sTitulo, G_CONST_RETURN gchar* sEdicao,
  G_CONST_RETURN gchar* sAnoPubli, G_CONST_RETURN gchar* sVolume, 
  G_CONST_RETURN gchar* sCodEditora, G_CONST_RETURN gchar* sCodIdioma,
  G_CONST_RETURN gchar* sNPaginas, G_CONST_RETURN gchar* sPreco,
  G_CONST_RETURN gchar* sQtdEstoque);
GString* ConsSQL_Cliente(gchar sTipo, G_CONST_RETURN gchar* sCPF, 
  G_CONST_RETURN gchar* sNome, G_CONST_RETURN gchar* sEmail,
  G_CONST_RETURN gchar* sIdentidade, G_CONST_RETURN gchar* sSexo,
  G_CONST_RETURN gchar* sTelefone, G_CONST_RETURN gchar* sDtNascimento,
  G_CONST_RETURN gchar* sCodEndereco, G_CONST_RETURN gchar* sCodPais, 
  G_CONST_RETURN gchar* sCodProfissao);
GString* ConsSQL_Endereco(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sLogradouro, G_CONST_RETURN gchar* sBairro, 
  G_CONST_RETURN gchar* sCEP, G_CONST_RETURN gchar* sCidade, 
  G_CONST_RETURN gchar* sEstado);
GString* ConsSQL_Pais(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sPais);
GString* ConsSQL_Profissao(gchar sTipo, G_CONST_RETURN gchar* sCodigo, 
  G_CONST_RETURN gchar* sProfissao);
GString* ConsSQL_LivroAss(gchar sTipo, G_CONST_RETURN gchar* sISBN, 
  G_CONST_RETURN gchar* sCodAssunto);
GString* ConsSQL_LivroAut(gchar sTipo, G_CONST_RETURN gchar* sISBN, 
  G_CONST_RETURN gchar* sCodAutor);
GString* ConsSQL_Venda(gchar sTipo, G_CONST_RETURN gchar* sISBN,
  G_CONST_RETURN gchar* sCPF, G_CONST_RETURN gchar* sDataVenda,
  G_CONST_RETURN gchar* sPrecoVenda, G_CONST_RETURN gchar* sQtdEstoque);

