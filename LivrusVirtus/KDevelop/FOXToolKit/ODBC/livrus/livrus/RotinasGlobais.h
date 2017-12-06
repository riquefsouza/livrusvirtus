#ifndef ROTINASGLOBAIS_H
#define ROTINASGLOBAIS_H

#include <sql.h>

#define TAM_MAX_STR 256
#define QTD_MAX_COL 20

struct listastr {
  FXArray<FXString> col;
};
typedef struct listastr LISTASTR;

struct listamstr {
  FXArray<FXString> col[QTD_MAX_COL];
};
typedef struct listamstr LISTAMSTR;

typedef SQLHSTMT CONEXAO;
extern CONEXAO  gConexao;
extern SQLHENV  henv;
extern SQLHDBC  hdbc;

extern FXString Rotinas_sBarraLogin;
extern FXString Rotinas_sUsuarioLogin;
extern FXString Rotinas_sUsuarioSenha;
extern FXString Rotinas_sCodigoSelecionado;
extern FXString Rotinas_sPreco;
extern FXString Rotinas_sQtdEstoque;
extern FXString Rotinas_sepDTHR;

class CRotinasGlobais {
public:
  FXApp *app;
	CRotinasGlobais(FXApp* owner);
	~CRotinasGlobais();

  FXchar* alocaString(FXint ntam);
  FXbool ValidaFloat(FXString sNum);
  FXString VirgulaParaPonto(FXString sNum, FXbool bRevertido);
  FXint modulo11(FXString svalor, FXint ndig);
  FXbool validaCPF(FXString cpf);
  FXbool validaISBN(FXString isbn);
  FXbool validaDataHora(FXString sDataHora, FXbool bSoData);

  FXString retDataHoraStr(FXbool bData, FXbool bHora);
  FXString FormataDataHoraStr(struct tm* sTempo, 
    FXString sFrmtData, FXString sFrmtHora);
  FXString ConverteDataHoraStr(FXString sDTHR, FXbool DMY_ou_YMD, 
    FXString sFrmtData, FXString sFrmtHora);

  FXbool ConectaBanco(FXString sFonteDeDados, FXString sLogin, 
    FXString sSenha);
  void DisconectaBanco();
  FXbool ConsultaDados(CONEXAO hstmtlocal, FXString sSql);
  void arrumaColunas(CONEXAO hstmtlocal, FXString sLinha[], 
        SQLUSMALLINT nQtdCol);
  FXbool ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, 
    FXString sSql);
  FXbool AtualizaDados(CONEXAO hstmtlocal, FXString sSql);

  FXbool ValidaCampo(FXString sCampo, FXString sMensagemErro);  
  FXString ConsultaCampoDesc(LISTAMSTR *Campos, 
    FXString sTextoSql, FXString);
  void AdicionaItemLista(FXList *lstLista,
    LISTASTR *slCodLista, FXTextField *sCampoCodigo, FXTextField *sCampoDesc);
  void RemoveItemLista(FXList *lstLista, LISTASTR *slCodLista);
  void AdicionaValoresLista(FXString sTextoSql, FXList *lstLista, 
    LISTASTR *slCodLista);
  void AdicionaColunasGrid(FXTable *grid, FXint nPosIni, FXint nQtdCols, 
    FXint nLargura[], FXString sRotulos[]);
  void AdicionaLinhasGrid(FXTable *grid, LISTAMSTR lstLinhas, 
    FXint nQtdCol);
};

extern CRotinasGlobais* Rotinas;

#endif

