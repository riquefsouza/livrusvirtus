#ifndef ROTINASGLOBAIS_H
#define ROTINASGLOBAIS_H

#include "resource.h"

#include <sql.h>
#include <sqlext.h>
#include "ListaStr.h"

extern string Rotinas_sUsuarioLogin;
extern string Rotinas_sUsuarioSenha;
extern string Rotinas_sCodigoSelecionado;
extern string Rotinas_sPreco;
extern string Rotinas_sQtdEstoque;
extern string Rotinas_sepDTHR;

typedef SQLHSTMT CONEXAO;
extern CONEXAO gConexao;
extern SQLHENV  henv;
extern SQLHDBC  hdbc;

class CRotinasGlobais
{
public:
  CRotinasGlobais();

char* alocaString(int ntam);
char* trim(const char *sTexto);
string subString(string string, int nini, int ntam);
bool ValidaFloat(string sNum);
char *VirgulaParaPonto(char *sNum, bool bRevertido);
int modulo11(string svalor, int ndig);
bool validaCPF(string cpf);
bool validaISBN(string isbn);
bool validaDataHora(string sDataHora, bool bSoData);
char* FormataDataHoraStr(struct tm* sTempo, 
  string sFrmtData, string sFrmtHora);
char* retDataHoraStr(bool bData, bool bHora);
char* ConverteDataHoraStr(string sDTHR, bool DMY_ou_YMD, 
  string sFrmtData, string sFrmtHora);

bool ConectaBanco(string sFonteDeDados, string sLogin, string sSenha);
void DisconectaBanco();
bool ConsultaDados(CONEXAO hstmtlocal, string sSql);
void arrumaColunas(CONEXAO hstmtlocal, char *sLinha[], 
									SQLUSMALLINT nQtdCol);
bool ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR *lstLocal, string sSql);
bool AtualizaDados(CONEXAO hstmtlocal, string sSql);

bool ValidaCampo(string sCampo, string sMensagemErro);

string ConsultaCampoDesc(LISTAMSTR *Campos, 
                      string sTextoSql, string sMensagemErro);
bool VerificaItemLista(Fl_Browser *lstLista, string sItem);
void AdicionaItemLista(Fl_Browser *lstLista,
     LISTASTR *slCodLista, Fl_Input *sCampoCodigo, Fl_Input *sCampoDesc);
void RemoveItemLista(Fl_Browser *lstLista, LISTASTR *slCodLista);
void AdicionaValoresLista(string sTextoSql, Fl_Browser *lstLista, 
                                  LISTASTR *slCodLista);

string setLargura(string sTexto, int nTam);
void AdicionaLinhasBrowser(Fl_Browser *browser, LISTAMSTR sLinhas, 
                           int nQtdCol, int nLarguras[], string sRotulos[]);

};

extern CRotinasGlobais *Rotinas;

#endif
