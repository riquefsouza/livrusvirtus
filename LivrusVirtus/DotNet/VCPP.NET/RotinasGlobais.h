#pragma once

namespace Livrus
{
  /// <summary>
  /// Summary description for Class.
  /// </summary>
  public __gc class RotinasGlobais : public System::Object
  {
  public:
  	static RotinasGlobais* Rotinas;
  	System::String* sUsuarioLogin; 
  	System::String* sUsuarioSenha;
  	System::String* sCodigoSelecionado;
	System::String* sPreco;
	System::String* sQtdEstoque;

    RotinasGlobais(void);
    Boolean ValidaInteger(String* sNum);
    Boolean ValidaFloat(String* sNum);
    String* VirgulaParaPonto(String* sNum, Boolean revertido);
    int modulo11(String* svalor, int ndig);
    Boolean ValidaCPF(String* cpf);
    Boolean ValidaISBN(String* isbn);
    Boolean ConsultaDados(OleDbCommand* Consulta, String* sTextoSql);
    Boolean ConsultaDados(DataSet* dsConsulta, ArrayList* Registros, String* sTextoSql);
    Boolean ConsultaDados(ArrayList* Registros, String* sTextoSql);
    Boolean ValidaCampo(String* sCampo,String* sMensagemErro);
    String* ConsultaCampoDesc(ArrayList* Campos, String* sTextoSql, String* sMensagemErro);
    String* ConsultaCampoDesc(ArrayList* Campos, String* sCampoCodigo,
				String* sTextoSql,String* sMensagemErro);
    String* retDataStr(DateTime* sData, String* formato);
    String* FormataDataStr(String* sData, String* formato);
    Void AdicionaItemLista(ListBox* lstLista,
    	 ArrayList* slCodLista, TextBox* sCampoCodigo, TextBox* sCampoDesc);
    Void RemoveItemLista(ListBox* lstLista, ArrayList* slCodLista);
    Void AdicionaValoresLista(ArrayList* ConsLista,
    	 String* sTextoSql,ListBox* lstLista, ArrayList* slCodLista);

  };

}
