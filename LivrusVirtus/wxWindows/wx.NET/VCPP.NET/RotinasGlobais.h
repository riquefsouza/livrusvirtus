#pragma once

namespace Livrus
{
  public __gc class RotinasGlobais
  {
  public:
  	static RotinasGlobais* Rotinas;
  	System::String* sUsuarioLogin; 
  	System::String* sUsuarioSenha;
    System::String* sBarraLogin;
  	System::String* sCodigoSelecionado;
    System::String* sPreco;
    System::String* sQtdEstoque;
    System::Data::OleDb::OleDbConnection* gConexao;
    static System::String* sepDTHR = "#"; /* SOMENTE ACCESS */
    //static System::String* sepDTHR = "'"; /* OUTROS BANCOS */

    RotinasGlobais(void);
    Boolean ValidaFloat(String* sNum);
    String* VirgulaParaPonto(String* sNum, Boolean revertido);
    int modulo11(String* svalor, int ndig);
    Boolean ValidaCPF(String* cpf);
    Boolean ValidaISBN(String* isbn);
    Boolean validaDataHora(String* sDataHora, Boolean bSoData);
    String* retDataHoraStr(Boolean bData, Boolean bHora);
    String* ConverteDataHoraStr(String* sData, String* formato);
    Boolean ConectaBanco(String* sFonteDeDados);
    Void DisconectaBanco();
    Boolean AtualizaDados(OleDbCommand* Arquiva, String* sTextoSql);
    Boolean ConsultaDados(OleDbCommand* Consulta, String* sTextoSql);
    Boolean ConsultaDadosLista(ArrayList* Registros, String* sTextoSql);
    Boolean ValidaCampo(String* sCampo,String* sMensagemErro);
    String* ConsultaCampoDesc(ArrayList* Campos, String* sTextoSql, String* sMensagemErro);
    int PesquisaItemLista(wx::ListBox* lstLista, String* sItem);
    Void AdicionaItemLista(wx::ListBox* lstLista,
    	 ArrayList* slCodLista, wx::TextCtrl* sCampoCodigo, wx::TextCtrl* sCampoDesc);
    Void RemoveItemLista(wx::ListBox* lstLista, ArrayList* slCodLista);
    Void AdicionaValoresLista(String* sTextoSql,wx::ListBox* lstLista, 
      ArrayList* slCodLista);
    Void AdicionaColunasGrid(wx::Grid* grid, int nPosIni, int nQtdCols, 
      int nLargura __gc[], String* sRotulos __gc[]);
    Void AdicionaLinhasGrid(wx::Grid* grid, ArrayList* lstLinhas, int nQtdCol);
  };
}
