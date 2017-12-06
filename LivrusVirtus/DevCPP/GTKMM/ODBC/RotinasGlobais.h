#ifndef ROTINASGLOBAIS_H
  #define ROTINASGLOBAIS_H

  #include <sql.h>

  #define TAM_MAX_STR 256
  #define QTD_MAX_COL 20

  struct listastr { std::vector<Glib::ustring> col; };

  typedef struct listastr LISTASTR;

  struct listamstr { std::vector<Glib::ustring> col[QTD_MAX_COL]; };

  typedef struct listamstr LISTAMSTR;

  typedef SQLHSTMT CONEXAO;

  extern CONEXAO gConexao;
  extern SQLHENV henv;
  extern SQLHDBC hdbc;

  extern Glib::ustring Rotinas_sBarraLogin;
  extern Glib::ustring Rotinas_sUsuarioLogin;
  extern Glib::ustring Rotinas_sUsuarioSenha;
  extern Glib::ustring Rotinas_sCodigoSelecionado;
  extern Glib::ustring Rotinas_sPreco;
  extern Glib::ustring Rotinas_sQtdEstoque;
  extern char * Rotinas_sepDTHR;

  class CRotinasGlobais {
  public:
    CRotinasGlobais();
    ~CRotinasGlobais();
    void MsgDlg(Glib::ustring sMensagem, Gtk::MessageType tipo);
    bool ValidaInteger(Glib::ustring sNum);
    bool ValidaFloat(Glib::ustring sNum);
    Glib::ustring VirgulaParaPonto(Glib::ustring sNum, bool revertido);
    int modulo11(Glib::ustring svalor, int ndig);
    bool ValidaCPF(Glib::ustring cpf);
    bool ValidaISBN(Glib::ustring isbn);
    bool validaDataHora(Glib::ustring sDataHora, bool bSoData);
    Glib::ustring FormataDataHoraStr(struct tm * sTempo,
     Glib::ustring sFrmtData, Glib::ustring sFrmtHora);
    Glib::ustring retDataHoraStr(bool bData, bool bHora);
    Glib::ustring ConverteDataHoraStr(Glib::ustring sDTHR, bool DMY_ou_YMD,
     Glib::ustring sFrmtData, Glib::ustring sFrmtHora);
    Glib::ustring retTexto(GtkWidget * sEdit);
    Glib::ustring retLocale(Glib::ustring sTexto);
    Glib::ustring retUTF8(Glib::ustring sTexto);

    bool ConectaBanco(Glib::ustring sFonteDeDados, Glib::ustring sLogin,
     Glib::ustring sSenha);
    void DisconectaBanco();
    bool AtualizaDados(CONEXAO hstmtlocal, Glib::ustring sSql);
    bool ConsultaDados(CONEXAO hstmtlocal, Glib::ustring sSql);
    void arrumaColunas(CONEXAO hstmtlocal, char * sLinha[],
     SQLUSMALLINT nQtdCol);
    bool ConsultaDadosLista(CONEXAO hstmtlocal, LISTAMSTR * lstLocal,
     Glib::ustring sSql);

    bool ValidaCampo(Glib::ustring sCampo, Glib::ustring sMensagemErro);
    Glib::ustring ConsultaCampoDesc(LISTAMSTR * Campos,
     Glib::ustring sCampoCodigo, bool bValidaInt, Glib::ustring sTextoSql,
     Glib::ustring sMensagemErro);

    Glib::RefPtr<Gtk::ListStore> CriaModeloGrid(Gtk::TreeView * grid);
    void LimpaModeloGrid(Glib::RefPtr<Gtk::ListStore> gListaGrid);
    void AdicionaColunasGrid(Gtk::TreeView * grid, int nPosIni, int nQtdCols,
     int nLargura[], Glib::ustring sRotulos[]);
    void AdicionaLinhasGrid(Glib::RefPtr<Gtk::ListStore> gListaGrid,
      LISTAMSTR * lstLinhas, int nQtdCols, bool bLimparGrid);

    bool PesquisaContaItemGrid(Glib::RefPtr<Gtk::ListStore> gListaGrid,
      Glib::ustring sItem, int * nQtdLinhas);
    void AdicionaItemLista(Glib::RefPtr<Gtk::ListStore> gListaGrid,
      Gtk::Entry * sCampoCodigo, Gtk::Entry * sCampoDesc);
    void RemoveItemLista(Gtk::TreeView * lstLista,
      Glib::RefPtr<Gtk::ListStore> gListaGrid);
    void AdicionaValoresLista(Glib::ustring sTextoSql,
      Glib::RefPtr<Gtk::ListStore> gListaGrid);
  private:
    struct ModeloColunas : public Gtk::TreeModel::ColumnRecord {
    public:
      Gtk::TreeModelColumn<int> nCol;
      Gtk::TreeModelColumn<Glib::ustring> sCol[QTD_MAX_COL];

      ModeloColunas(){
        add(nCol);
        for (int nCont = 0; nCont < QTD_MAX_COL; nCont++)
          add(sCol[nCont]);
      }
    };

    ModeloColunas modeloGrid;
  };

  extern CRotinasGlobais * Rotinas;

#endif
