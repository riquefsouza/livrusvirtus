#ifndef RESOURCE_H
#define RESOURCE_H

#ifdef WIN32
  #include <windows.h>
#else
  #include <unistd.h>
#endif

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Text_Display.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Double_Window.H>
//#include <FL/Fl_Image.H>
#include <FL/Fl_Pixmap.H>
#include <FL/fl_ask.h>
#include <FL/Fl_Timer.H>
#include <FL/Fl_Select_Browser.H>
#include <FL/Fl_Value_Input.H>

#include <string>

using std::string;

#include <ctime>
#include <cmath>
#include <cstdlib>
#include <cstdio>

extern const char *idata_cliente[];
extern const char *idata_dcliente[];
extern const char *idata_livro[];
extern const char *idata_dlivro[];
extern const char *idata_livros[];
extern const char *idata_dlivros[];
extern const char *idata_sobre[];
extern const char *idata_dsobre[];
extern const char *idata_sair[];
extern const char *idata_dsair[];
extern const char *idata_livrusvirtus[];
extern const char *idata_login[];
extern unsigned char idata_Livrus[];

extern Fl_Pixmap image_livrusvirtus;

#define STR_TITULO              "Livrus Virtus"
#define STR_APPEXEC             "A aplica��o j� est� sendo executada."
#define STR_NREGJAN             "N�o consigo registrar a janela principal."
#define STR_SEMJAN              "Sem janela principal"
#define STR_NCONBANCO           "N�o consigo conectar com o banco de dados!"
#define STR_NALOCODBC           "N�o foi poss�vel alocar um manuseador para o ambiente ODBC"
#define STR_CADASSUNTO          "Cadastro de Assuntos"
#define STR_CADAUTOR            "Cadastro de Autores"
#define STR_CADEDITORA          "Cadastro de Editoras"
#define STR_CADENDERECO         "Cadastro de Endere�os"
#define STR_CADIDIOMA           "Cadastro de Idiomas"
#define STR_CADPAIS             "Cadastro de Pa�ses"
#define STR_CADPROFISS          "Cadastro de Profiss�es"
#define STR_CADCLIENTE          "Cadastro de Clientes"
#define STR_CADLIVRO            "Cadastro de Livros"
#define STR_CONASSUNTO          "Consulta de Assuntos"
#define STR_CONAUTOR            "Consulta de Autores"
#define STR_CONEDITORA          "Consulta de Editoras"
#define STR_CONENDERECO         "Consulta de Endere�os"
#define STR_CONIDIOMA           "Consulta de Idiomas"
#define STR_CONPAIS             "Consulta de Pa�ses"
#define STR_CONPROFISS          "Consulta de Profiss�es"
#define STR_CONCLIENTE          "Consulta de Clientes"
#define STR_CONLIVRO            "Consulta de Livros"
#define STR_VENLIVRO            "Vender Livros"
#define STR_CONVENLIVRO         "Vendas Realizadas"
#define STR_ALTSENHA            "Altera��o de Senha"
#define STR_OPSOBRE             "Sobre o Sistema"
#define STR_OPSAIR              "Sair do Sistema"  
#define STR_SAIRSIS             "Deseja sair do sistema?"
#define STR_EMAILNINF           "E-mail n�o informado!"
#define STR_NCCRIADLG           "N�o consigo criar a dialog!"
#define STR_CERTEXCL            "Certeza de excluir?"
#define STR_TELNINF             "Telefone n�o informado!"
#define STR_NREGTELA            "N�o consigo registrar a tela!"
#define STR_NCCRIATELA          "N�o consigo criar a tela!"
#define STR_NCPREPSQL           "N�o conseguiu preparar o SQL!"
#define STR_NCEXECSQL           "N�o conseguiu executar o SQL!"
#define STR_DATINV              "Data inv�lida!"
#define STR_SENALTSUC           "Senha alterada com sucesso!"
#define STR_SENNCSU             "A Senha atual n�o confere com a senha do usu�rio!"
#define STR_NSENNINF            "Nova senha n�o informada!"
#define STR_NSENNCCON           "A Nova senha n�o confere com a senha a confirmar!"
#define STR_DTHRINV             "Data/Hora inv�lida!"
#define STR_USUARIO             "Usu�rio: "
#define STR_LOGSENINC           "Login ou senha incorretos!"
#define STR_ISBNNINF            "ISBN n�o informado!"
#define STR_CODNINF             "C�digo n�o informado!"
#define STR_ASSNENC             "Assunto n�o encontrado!"
#define STR_ASSNINF             "Assunto n�o informado!"
#define STR_AUTNENC             "Autor n�o encontrado!"
#define STR_AUTNINF             "Autor n�o informado!"
#define STR_EDTNENC             "Editora n�o encontrada!"
#define STR_EDTNINF             "Editora n�o informada!"
#define STR_ENDNENC             "Endere�o n�o encontrado!"
#define STR_ENDNINF             "Endere�o n�o informado!"
#define STR_IDINENC             "Idioma n�o encontrado!"
#define STR_IDININF             "Idioma n�o informado!"
#define STR_PAISNENC            "Pa�s n�o encontrado!"
#define STR_PAISNINF            "Pa�s n�o informado!"
#define STR_PROFNENC            "Profiss�o n�o encontrada!"
#define STR_PROFNINF            "Profiss�o n�o informada!"
#define STR_CLINENC             "Cliente n�o encontrado!"
#define STR_CLININF             "Cliente n�o informado!"
#define STR_LIVNENC             "Livro n�o encontrado!"
#define STR_LIVNINF             "Livro n�o informado!"
#define STR_PE                  "Pernambuco"
#define STR_AC                  "Acre"
#define STR_AL                  "Alagoas"
#define STR_AP                  "Amap�"
#define STR_AM                  "Amazonas"
#define STR_BA                  "Bahia"
#define STR_BR                  "Bras�lia"
#define STR_CE                  "Cear�"
#define STR_DF                  "Distrito Federal"
#define STR_ES                  "Esp�rito Santo"
#define STR_GO                  "Goi�s"
#define STR_MT                  "Mato Grosso"
#define STR_MS                  "Mato Grosso do Sul"
#define STR_MG                  "Minas Gerais"
#define STR_PA                  "Par�"
#define STR_PB                  "Para�ba"
#define STR_PR                  "Paran�"
#define STR_SC                  "Santa Catarina"
#define STR_RN                  "Rio Grande do Norte"
#define STR_RS                  "Rio Grande do Sul"
#define STR_RJ                  "Rio de Janeiro"
#define STR_RO                  "Rond�nia"
#define STR_RR                  "Roraima"
#define STR_SP                  "S�o Paulo"
#define STR_SE                  "Sergipe"
#define STR_TO                  "Tocantins"
#define STR_CPFNINF             "CPF n�o informado!"
#define STR_SEXNINF             "Sexo n�o informado!"
#define STR_CPFINV              "CPF inv�lido!"
#define STR_TITNINF             "T�tulo n�o informado!"
#define STR_ISBNINV             "ISBN inv�lido!"
#define STR_NUMINV              "N�mero inv�lido!"
#define STR_LIVVENNINF          "Livro(s) para vender n�o informado(s)!"
#define STR_LIVNEST             "Livro n�o existe no estoque!"
#define STR_VENRESUC            "Venda realizada com sucesso!"
#define STR_VENNENC             "Venda n�o encontrada!"
#define STR_BAIRRONINF          "Bairro n�o informado!"
#define STR_CEPNINF             "CEP n�o informado!"
#define STR_CIDADENINF          "Cidade n�o informada!"

#endif

