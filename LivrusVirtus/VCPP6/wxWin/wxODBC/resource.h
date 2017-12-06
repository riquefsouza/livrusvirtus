#ifndef RESOURCE_H
#define RESOURCE_H

// Para compiladores que suportam precompilação, inclua "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#ifndef WX_PRECOMP
    #include "wx/wx.h"
#endif

#include "wx/toolbar.h"
#include "wx/layout.h"
#include "wx/splash.h"
#include "wx/list.h"
#include "wx/string.h"
#include "wx/dynarray.h"
#include "wx/valtext.h"
#include "wx/datetime.h"
#include "wx/calctrl.h"
#include "wx/spinctrl.h"
#ifdef __WXMSW__
  #include "wx/popupwin.h"
#endif
#if wxUSE_ODBC
  #include "wx/db.h"
  #include "wx/dbtable.h"
#else
  #error Não pode ser compilado se no setup.h não tiver wxUSE_ODBC igual a 1
#endif
/*
#undef wxUSE_ODBC
#define wxUSE_ODBC 0
*/
#if wxUSE_NEW_GRID
  #include "wx/grid.h"
  #include "wx/generic/gridctrl.h"
  #include "wx/dbgrid.h"
#endif

#define ICO_LIVRUS	 "Livrus.ico"

#define FRMCADASSUNTOS		1000
#define FRMCADAUTORES		1001
#define FRMCADEDITORAS		1002
#define FRMCADENDERECOS		1003
#define FRMCADIDIOMAS		1004
#define FRMCADPAISES		1005
#define FRMCADPROFISSOES	1006
#define FRMCADCLIENTES		1007
#define FRMCADLIVROS		1008
#define FRMVENDERLIVROS		1009
#define FRMCONVENDAS		1010
#define FRMALTERARSENHA		1111

#define STR_TITULO              "Livrus Virtus"
#define STR_APPEXEC             "A aplicação já está sendo executada."
#define STR_NREGJAN             "Não consigo registrar a janela principal."
#define STR_SEMJAN              "Sem janela principal"
#define STR_NCONBANCO           "Não consigo conectar com o banco de dados!"
#define STR_NALOCODBC           "Não foi possível alocar um manuseador para o ambiente ODBC"
#define STR_CADASSUNTO          "Cadastro de Assuntos"
#define STR_CADAUTOR            "Cadastro de Autores"
#define STR_CADEDITORA          "Cadastro de Editoras"
#define STR_CADENDERECO         "Cadastro de Endereços"
#define STR_CADIDIOMA           "Cadastro de Idiomas"
#define STR_CADPAIS             "Cadastro de Países"
#define STR_CADPROFISS          "Cadastro de Profissões"
#define STR_CADCLIENTE          "Cadastro de Clientes"
#define STR_CADLIVRO            "Cadastro de Livros"
#define STR_CONASSUNTO          "Consulta de Assuntos"
#define STR_CONAUTOR            "Consulta de Autores"
#define STR_CONEDITORA          "Consulta de Editoras"
#define STR_CONENDERECO         "Consulta de Endereços"
#define STR_CONIDIOMA           "Consulta de Idiomas"
#define STR_CONPAIS             "Consulta de Países"
#define STR_CONPROFISS          "Consulta de Profissões"
#define STR_CONCLIENTE          "Consulta de Clientes"
#define STR_CONLIVRO            "Consulta de Livros"
#define STR_VENLIVRO            "Vender Livros"
#define STR_CONVENLIVRO         "Vendas Realizadas"
#define STR_ALTSENHA            "Alteração de Senha"
#define STR_OPSOBRE             "Sobre o Sistema"
#define STR_OPSAIR              "Sair do Sistema"  
#define STR_SAIRSIS             "Deseja sair do sistema?"
#define STR_EMAILNINF           "E-mail não informado!"
#define STR_NCCRIADLG           "Não consigo criar a dialog!"
#define STR_CERTEXCL            "Certeza de excluir?"
#define STR_TELNINF             "Telefone não informado!"
#define STR_NREGTELA            "Não consigo registrar a tela!"
#define STR_NCCRIATELA          "Não consigo criar a tela!"
#define STR_NCPREPSQL           "Não conseguiu preparar o SQL!"
#define STR_NCEXECSQL           "Não conseguiu executar o SQL!"
#define STR_DATINV              "Data inválida!"
#define STR_SENALTSUC           "Senha alterada com sucesso!"
#define STR_SENNCSU             "A Senha atual não confere com a senha do usuário!"
#define STR_NSENNINF            "Nova senha não informada!"
#define STR_NSENNCCON           "A Nova senha não confere com a senha a confirmar!"
#define STR_DTHRINV             "Data/Hora inválida!"
#define STR_USUARIO             "Usuário: "
#define STR_LOGSENINC           "Login ou senha incorretos!"
#define STR_ISBNNINF            "ISBN não informado!"
#define STR_CODNINF             "Código não informado!"
#define STR_ASSNENC             "Assunto não encontrado!"
#define STR_ASSNINF             "Assunto não informado!"
#define STR_AUTNENC             "Autor não encontrado!"
#define STR_AUTNINF             "Autor não informado!"
#define STR_EDTNENC             "Editora não encontrada!"
#define STR_EDTNINF             "Editora não informada!"
#define STR_ENDNENC             "Endereço não encontrado!"
#define STR_ENDNINF             "Endereço não informado!"
#define STR_IDINENC             "Idioma não encontrado!"
#define STR_IDININF             "Idioma não informado!"
#define STR_PAISNENC            "País não encontrado!"
#define STR_PAISNINF            "País não informado!"
#define STR_PROFNENC            "Profissão não encontrada!"
#define STR_PROFNINF            "Profissão não informada!"
#define STR_CLINENC             "Cliente não encontrado!"
#define STR_CLININF             "Cliente não informado!"
#define STR_LIVNENC             "Livro não encontrado!"
#define STR_LIVNINF             "Livro não informado!"
#define STR_PE                  "Pernambuco"
#define STR_AC                  "Acre"
#define STR_AL                  "Alagoas"
#define STR_AP                  "Amapá"
#define STR_AM                  "Amazonas"
#define STR_BA                  "Bahia"
#define STR_BR                  "Brasília"
#define STR_CE                  "Ceará"
#define STR_DF                  "Distrito Federal"
#define STR_ES                  "Espírito Santo"
#define STR_GO                  "Goiás"
#define STR_MT                  "Mato Grosso"
#define STR_MS                  "Mato Grosso do Sul"
#define STR_MG                  "Minas Gerais"
#define STR_PA                  "Pará"
#define STR_PB                  "Paraíba"
#define STR_PR                  "Paraná"
#define STR_SC                  "Santa Catarina"
#define STR_RN                  "Rio Grande do Norte"
#define STR_RS                  "Rio Grande do Sul"
#define STR_RJ                  "Rio de Janeiro"
#define STR_RO                  "Rondônia"
#define STR_RR                  "Roraima"
#define STR_SP                  "São Paulo"
#define STR_SE                  "Sergipe"
#define STR_TO                  "Tocantins"
#define STR_CPFNINF             "CPF não informado!"
#define STR_SEXNINF             "Sexo não informado!"
#define STR_CPFINV              "CPF inválido!"
#define STR_TITNINF             "Título não informado!"
#define STR_ISBNINV             "ISBN inválido!"
#define STR_NUMINV              "Número inválido!"
#define STR_LIVVENNINF          "Livro(s) para vender não informado(s)!"
#define STR_LIVNEST             "Livro não existe no estoque!"
#define STR_VENRESUC            "Venda realizada com sucesso!"
#define STR_VENNENC             "Venda não encontrada!"
#define STR_BAIRRONINF          "Bairro não informado!"
#define STR_CEPNINF             "CEP não informado!"
#define STR_CIDADENINF          "Cidade não informada!"

#endif
