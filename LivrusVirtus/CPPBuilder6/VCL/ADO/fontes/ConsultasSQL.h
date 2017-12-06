//---------------------------------------------------------------------------

#ifndef ConsultasSQLH
#define ConsultasSQLH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Dialogs.hpp>
#include <Sysutils.hpp>
//---------------------------------------------------------------------------
class TConsultasSQL : public TObject
{
private:	// User declarations
public:		// User declarations
  __fastcall TConsultasSQL();
  AnsiString Assunto(char sTipo, AnsiString sCodigo, AnsiString sAssunto);
  AnsiString Autor(char sTipo, AnsiString sCodigo, AnsiString sAutor);
  AnsiString Editora(char sTipo, AnsiString sCodigo, AnsiString sEditora);
  AnsiString Idioma(char sTipo, AnsiString sCodigo, AnsiString sIdioma);
  AnsiString Usuario(char sTipo, AnsiString sLogin, AnsiString sSenha);
  AnsiString Livro(char sTipo, AnsiString sISBN,AnsiString sTitulo,
  AnsiString sEdicao,AnsiString sAnoPubli,AnsiString sVolume,
  AnsiString sCodEditora,AnsiString sCodIdioma,
  AnsiString sNPaginas,AnsiString sPreco,AnsiString sQtdEstoque);
  AnsiString Cliente(char sTipo, AnsiString sCPF,AnsiString sNome,
  AnsiString sEmail,AnsiString sIdentidade,AnsiString sSexo,
  AnsiString sTelefone,AnsiString sDtNascimento,AnsiString sCodEndereco,
  AnsiString sCodPais, AnsiString sCodProfissao);
  AnsiString Endereco(char sTipo, AnsiString sCodigo, AnsiString sLogradouro,
  AnsiString sBairro,AnsiString sCEP,AnsiString sCidade,AnsiString sEstado);
  AnsiString Pais(char sTipo, AnsiString sCodigo,AnsiString sPais);
  AnsiString Profissao(char sTipo, AnsiString sCodigo,AnsiString sProfissao);
  AnsiString LivroAss(char sTipo, AnsiString sISBN,AnsiString sCodAssunto);
  AnsiString LivroAut(char sTipo, AnsiString sISBN,AnsiString sCodAutor);
  AnsiString Venda(char sTipo, AnsiString sISBN,AnsiString sCPF,
  AnsiString sDataVenda,AnsiString sPrecoVenda,AnsiString sQtdEstoque);

};
//---------------------------------------------------------------------------
extern PACKAGE TConsultasSQL *ConsSQL;
//---------------------------------------------------------------------------
#endif
