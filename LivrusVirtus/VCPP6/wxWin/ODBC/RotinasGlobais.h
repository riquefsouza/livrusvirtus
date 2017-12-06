#ifndef ROTINASGLOBAIS_H
#define ROTINASGLOBAIS_H

#include <sql.h>

#define TAM_MAX_STR 256
#define QTD_MAX_COL 20

struct listastr {
  wxArrayString col;
};
typedef struct listastr LISTASTR;

struct listamstr {
  wxArrayString col[QTD_MAX_COL];
};
typedef struct listamstr LISTAMSTR;

typedef SQLHSTMT CONEXAO;
extern CONEXAO  gConexao;
extern SQLHENV  henv;
extern SQLHDBC  hdbc;

extern wxString Rotinas_sBarraLogin;
extern wxString Rotinas_sUsuarioLogin;
extern wxString Rotinas_sUsuarioSenha;
extern wxString Rotinas_sCodigoSelecionado;
extern wxString Rotinas_sPreco;
extern wxString Rotinas_sQtdEstoque;
extern wxString Rotinas_sepDTHR;

class CRotinasGlobais : public wxObject
{
public:
	CRotinasGlobais();
	~CRotinasGlobais();

  bool ValidaFloat(wxString sNum);
  wxString VirgulaParaPonto(wxString sNum, bool bRevertido);
  int modulo11(wxString svalor, int ndig);
  bool validaCPF(wxString cpf);
  bool validaISBN(wxString isbn);
  bool validaDataHora(wxString sDataHora, bool bSoData);
  wxString FormataDataHoraStr(wxDateTime sTempo, 
    wxString sFrmtData, wxString sFrmtHora);
  wxString retDataHoraStr(bool bData, bool bHora);
  wxString ConverteDataHoraStr(wxString sDTHR, 
    bool DMY_ou_YMD, wxString sFrmtData, wxString sFrmtHora);

  bool ConectaBanco(wxString sFonteDeDados, wxString sLogin, wxString sSenha);
  void DisconectaBanco();
  bool ConsultaDados(CONEXAO hstmtlocal, wxString sSql);
  void arrumaColunas(CONEXAO hstmtlocal, wxString sLinha[], 
        SQLUSMALLINT nQtdCol);
  bool ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, wxString sSql);
  bool AtualizaDados(CONEXAO hstmtlocal, wxString sSql);

  bool ValidaCampo(wxString sCampo, wxString sMensagemErro);
  wxString ConsultaCampoDesc(LISTAMSTR *Campos, 
    wxString sTextoSql, wxString sMensagemErro);
  void AdicionaItemLista(wxListBox *lstLista,
    LISTASTR *slCodLista, wxTextCtrl *sCampoCodigo, wxTextCtrl *sCampoDesc);
  void RemoveItemLista(wxListBox *lstLista, LISTASTR *slCodLista);
  void AdicionaValoresLista(wxString sTextoSql, wxListBox *lstLista, 
    LISTASTR *slCodLista);
  void AdicionaColunasGrid(wxGrid *grid, int nPosIni, int nQtdCols, 
    int nLargura[], wxString sRotulos[]);
  void AdicionaLinhasGrid(wxGrid *grid, LISTAMSTR lstLinhas, 
    unsigned long nQtdCol);

};

extern CRotinasGlobais* Rotinas;

#endif

