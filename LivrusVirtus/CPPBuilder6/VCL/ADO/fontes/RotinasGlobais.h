//---------------------------------------------------------------------------

#ifndef RotinasGlobaisH
#define RotinasGlobaisH
//---------------------------------------------------------------------------
#include <Sysutils.hpp>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class TRotinasGlobais : public TObject
{
private:	// User declarations
public:		// User declarations
  __fastcall TRotinasGlobais();
  AnsiString sUsuarioLogin, sUsuarioSenha;
  AnsiString sCodigoSelecionado, sPreco, sQtdEstoque;
  Boolean ValidaInteger(AnsiString sNum);
  Boolean ValidaFloat(AnsiString sNum);
  AnsiString VirgulaParaPonto(AnsiString sNum);
  int modulo11(AnsiString svalor, int ndig);
  Boolean ValidaCPF(AnsiString cpf);
  Boolean ValidaISBN(AnsiString isbn);
  Boolean ConsultaDados(TADOQuery *Consulta, AnsiString sTextoSql);
  Boolean ValidaCampo(AnsiString sCampo, AnsiString sMensagemErro);
  AnsiString ConsultaCampoDesc(TADOQuery *Consulta, AnsiString sTextoSql,
             AnsiString sMensagemErro);
  AnsiString ConsultaCampoDesc(TADOQuery *Consulta, AnsiString sCampoCodigo,
             AnsiString sTextoSql, AnsiString sMensagemErro);
  void AdicionaItemLista(TListBox *lstLista, TStringList *slCodLista,
       TEdit *sCampoCodigo, TEdit *sCampoDesc);
  void RemoveItemLista(TListBox *lstLista, TStringList *slCodLista);
  void AdicionaValoresLista(TADOQuery *ConsLista, AnsiString sTextoSql,
       TListBox *lstLista, TStringList *slCodLista);
  void ChamarTela(TForm *Tela);
};
//---------------------------------------------------------------------------
extern PACKAGE TRotinasGlobais *Rotinas;
//---------------------------------------------------------------------------
#endif
