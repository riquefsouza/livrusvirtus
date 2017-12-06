#ifndef ROTINASGLOBAIS_H
#define ROTINASGLOBAIS_H

#include <sql.h>

#define TAM_MAX_STR 256
#define QTD_MAX_COL 20

struct listastr {
  GArray* col;
};
typedef struct listastr LISTASTR;

struct listamstr {
  GArray* col[QTD_MAX_COL];
};
typedef struct listamstr LISTAMSTR;

typedef SQLHSTMT CONEXAO;

extern CONEXAO  gConexao;
extern SQLHENV  henv;
extern SQLHDBC  hdbc;

extern GString* Rotinas_sBarraLogin;
extern GString* Rotinas_sUsuarioLogin; 
extern GString* Rotinas_sUsuarioSenha;
extern GString* Rotinas_sCodigoSelecionado;
extern GString* Rotinas_sPreco;
extern GString* Rotinas_sQtdEstoque;
extern gchar* Rotinas_sepDTHR;

void Rotinas_MsgDlg(gchar* sMensagem, GtkMessageType tipo);
gchar* Rotinas_substr(G_CONST_RETURN gchar* stexto, gint ini, gint tam);
gboolean Rotinas_ValidaInteger(G_CONST_RETURN gchar* sNum);
gboolean Rotinas_ValidaFloat(G_CONST_RETURN gchar* sNum);
gchar* Rotinas_VirgulaParaPonto(G_CONST_RETURN gchar* sNum, 
                                gboolean revertido);
gint Rotinas_modulo11(GString* svalor, gint ndig);
gboolean Rotinas_ValidaCPF(G_CONST_RETURN gchar* cpf);
gboolean Rotinas_ValidaISBN(G_CONST_RETURN gchar* isbn);
gboolean Rotinas_validaDataHora(G_CONST_RETURN gchar *sDataHora, 
                                  gboolean bSoData);
gchar* Rotinas_FormataDataHoraStr(struct tm* sTempo, 
  gchar *sFrmtData, gchar *sFrmtHora);
gchar* Rotinas_retDataHoraStr(gboolean bData, gboolean bHora);
gchar* Rotinas_ConverteDataHoraStr(G_CONST_RETURN gchar *sDTHR, 
  gboolean DMY_ou_YMD, gchar *sFrmtData, gchar *sFrmtHora);
G_CONST_RETURN gchar* Rotinas_retTexto(GtkWidget *sEdit);
gchar* Rotinas_retLocale(const gchar *sTexto);
gchar* Rotinas_retUTF8(const gchar *sTexto);

gboolean Rotinas_ConectaBanco(gchar *sFonteDeDados, 
                              gchar *sLogin, gchar *sSenha);
void Rotinas_DisconectaBanco();
gboolean Rotinas_AtualizaDados(CONEXAO hstmtlocal, GString *sSql);
gboolean Rotinas_ConsultaDados(CONEXAO hstmtlocal, GString *sSql);
void Rotinas_arrumaColunas(CONEXAO hstmtlocal, gchar *sLinha[], 
      SQLUSMALLINT nQtdCol);
gchar* Rotinas_retValorListaM(LISTAMSTR *lstLocal, gint nCol, gint nLinha);
gchar* Rotinas_retValorLista(LISTASTR lstLocal, gint nLinha);
gboolean Rotinas_ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, 
                                      GString *sSql);

gboolean Rotinas_ValidaCampo(G_CONST_RETURN gchar *sCampo, 
                             gchar *sMensagemErro);
gchar* Rotinas_ConsultaCampoDesc(LISTAMSTR *Campos, 
    G_CONST_RETURN gchar *sCampoCodigo, gboolean bValidaInt,
    GString *sTextoSql, gchar *sMensagemErro);

void Rotinas_CriaModeloGrid(GtkTreeView *grid);
void Rotinas_LimpaModeloGrid(GtkTreeView *grid);
void Rotinas_AdicionaColunasGrid(GtkTreeView *grid, gint nPosIni, gint nQtdCols, 
  gint nLargura[], GString *sRotulos[]);
void Rotinas_AdicionaLinhasGrid(GtkTreeView *grid, 
  LISTAMSTR *lstLinhas, gint nQtdCols, gboolean bLimparGrid);

gboolean Rotinas_PesquisaContaItemGrid(GtkTreeView *grid, gchar *sItem, 
                                       gint *nQtdLinhas);
void Rotinas_AdicionaItemLista(GtkTreeView *lstLista,
     GtkWidget *sCampoCodigo, GtkWidget *sCampoDesc);
void Rotinas_RemoveItemLista(GtkTreeView *lstLista);
void Rotinas_AdicionaValoresLista(GString *sTextoSql, GtkTreeView *lstLista);

#endif
