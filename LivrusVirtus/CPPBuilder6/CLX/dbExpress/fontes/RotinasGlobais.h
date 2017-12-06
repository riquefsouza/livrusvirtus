//---------------------------------------------------------------------------

#ifndef RotinasGlobaisH
#define RotinasGlobaisH
//---------------------------------------------------------------------------
#include <QComCtrls.hpp>
#include <QExtCtrls.hpp>
#include <QDialogs.hpp>
#include <QStdCtrls.hpp>
#include <QControls.hpp>
#include <SysUtils.hpp>
#include <Classes.hpp>

#include <FMTBcd.hpp>
#include <SqlExpr.hpp>
#include <DBClient.hpp>
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
  Boolean ValidaDateTime(AnsiString sNum);  
  AnsiString VirgulaParaPonto(AnsiString sNum);
  int modulo11(AnsiString svalor, int ndig);
  Boolean ValidaCPF(AnsiString cpf);
  Boolean ValidaISBN(AnsiString isbn);
  Boolean ConsultaDados(TSQLQuery *Consulta, AnsiString sTextoSql);
  Boolean ConsultaDados(TSQLQuery *Consulta, TClientDataSet *CDSConsulta,
        AnsiString sTextoSql);
  Boolean ValidaCampo(AnsiString sCampo, AnsiString sMensagemErro);
  AnsiString ConsultaCampoDesc(TSQLQuery *Consulta, AnsiString sTextoSql,
             AnsiString sMensagemErro);
  AnsiString ConsultaCampoDesc(TSQLQuery *Consulta, AnsiString sCampoCodigo,
             AnsiString sTextoSql, AnsiString sMensagemErro);
  void AdicionaItemLista(TListBox *lstLista, TStringList *slCodLista,
       TEdit *sCampoCodigo, TEdit *sCampoDesc);
  void RemoveItemLista(TListBox *lstLista, TStringList *slCodLista);
  void AdicionaValoresLista(TSQLQuery *ConsLista, AnsiString sTextoSql,
       TListBox *lstLista, TStringList *slCodLista);
  void ChamarTela(TForm *Tela);
};
//---------------------------------------------------------------------------
extern PACKAGE TRotinasGlobais *Rotinas;
//---------------------------------------------------------------------------
#endif
