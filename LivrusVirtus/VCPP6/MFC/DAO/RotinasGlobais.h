#ifndef ROTINASGLOBAIS_H
#define ROTINASGLOBAIS_H

#define TAM_MAX_STR 256
#define QTD_MAX_COL 20
#define MAXLINHAS_VISAOLISTA 100000

#include "afxdao.h"

struct listastr {
	CStringList col;
};
typedef struct listastr LISTASTR;

struct listamstr {
	CStringList col[QTD_MAX_COL];
};
typedef struct listamstr LISTAMSTR;

typedef CDaoDatabase *CONEXAO;
extern CONEXAO gConexao;
extern CDaoWorkspace *pDAOWS;

extern CString Rotinas_sBarraLogin;
extern CString Rotinas_sUsuarioLogin;
extern CString Rotinas_sUsuarioSenha;
extern CString Rotinas_sCodigoSelecionado;
extern CString Rotinas_sPreco;
extern CString Rotinas_sQtdEstoque;
extern CString Rotinas_sepDTHR;
extern CString Rotinas_sepLIKE;

class CRotinasGlobais : public CObject
{
public:
  CRotinasGlobais();

  BOOL VerificaInstancia(LPTSTR sNomeClasse, LPTSTR sNomeJanela);
  VOID habilitaSubMenu(INT nPosSubMenu, INT idSubMenu, BOOL bHabilita);
  LPTSTR alocaString(INT ntam);
  BOOL ValidaFloat(CString sNum);
  CString VirgulaParaPonto(CString sNum, BOOL bRevertido);
  INT modulo11(CString svalor, INT ndig);
  BOOL validaCPF(CString cpf);
  BOOL validaISBN(CString isbn);
  BOOL validaDataHora(CString sDataHora, BOOL bSoData);
  CString FormataDataHoraStr(SYSTEMTIME sTempo, CString sFrmtData, 
      CString sFrmtHora);
  CString retDataHoraStr(BOOL bData, BOOL bHora);
  CString ConverteDataHoraStr(CString sDTHR, BOOL DMY_ou_YMD, 
    CString sFrmtData, CString sFrmtHora);
  CString retTexto(CEdit *cWnd);
  CString retTexto(CComboBox *cCmb);
  CString retTexto(CDateTimeCtrl *cDTCtrl);
  VOID setDataHora(CDateTimeCtrl *cDTCtrl, 
    CString sData, CString sHora);
  CString retDataHora(CDateTimeCtrl *cDTCtrl, 
    CString sFrmtData, CString sFrmtHora);
  CString lerStr(UINT nId);

  CString VarianteStr(const COleVariant& var);
  BOOL ConectaBanco(CString sBancoDeDados, CString sLogin, CString sSenha);
  VOID DisconectaBanco();
  BOOL ConsultaDados(CONEXAO pBanco, CString sSql);
  BOOL ConsultaDadosLista(CONEXAO pBanco, 
    LISTAMSTR *lstLocal, CString sSql);
  BOOL AtualizaDados(CONEXAO pBanco, CString sSql);

  BOOL ValidaCampo(CString sCampo, CString sMensagemErro);
  CString ConsultaCampoDesc(LISTAMSTR *Campos, 
                        CString sTextoSql, CString sMensagemErro);

  VOID AdicionaItemLista(CListBox *lstLista,
     LISTASTR *slCodLista, CEdit *sCampoCodigo, CEdit *sCampoDesc);
  VOID RemoveItemLista(CListBox *lstLista, LISTASTR *slCodLista);
  VOID AdicionaValoresLista(CString sTextoSql, 
        CListBox *lstLista, LISTASTR *slCodLista);

  BOOL VisaoListaInsereColunas(CListCtrl *cVisaoLista, UINT largura[], 
      LISTASTR *sColunas);
  BOOL VisaoListaInsereLinhas(CListCtrl *cVisaoLista, LISTAMSTR *sLinhas);
  BOOL VisaoListaNotifica(CListCtrl *cVisaoLista, LISTAMSTR *sLinhas, 
      LPARAM lParam, INT *nLinha, CString *sSelecionado); 
};

static CRotinasGlobais *Rotinas;

#endif
