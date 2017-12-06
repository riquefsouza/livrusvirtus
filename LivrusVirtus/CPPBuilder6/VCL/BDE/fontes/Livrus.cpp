//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Livrus.res");
USEFORM("Principal.cpp", frmPrincipal);
USEUNIT("ConsultasSQL.cpp");
USEFORM("Splash.cpp", frmSplash);
USEFORM("Sobre.cpp", frmSobre);
USEFORM("Login.cpp", frmLogin);
USEFORM("AlterarSenha.cpp", frmAlterarSenha);
USEUNIT("RotinasGlobais.cpp");
USEFORM("Cadastros.cpp", frmCadastros);
USEFORM("Consultas.cpp", frmConsultas);
USEFORM("CadAssuntos.cpp", frmCadAssuntos);
USEFORM("ConAssuntos.cpp", frmConAssuntos);
USEFORM("CadAutores.cpp", frmCadAutores);
USEFORM("ConAutores.cpp", frmConAutores);
USEFORM("CadEditoras.cpp", frmCadEditoras);
USEFORM("ConEditoras.cpp", frmConEditoras);
USEFORM("CadIdiomas.cpp", frmCadIdiomas);
USEFORM("ConIdiomas.cpp", frmConIdiomas);
USEFORM("CadProfissoes.cpp", frmCadProfissoes);
USEFORM("ConProfissoes.cpp", frmConProfissoes);
USEFORM("CadPaises.cpp", frmCadPaises);
USEFORM("ConPaises.cpp", frmConPaises);
USEFORM("CadEnderecos.cpp", frmCadEnderecos);
USEFORM("ConEnderecos.cpp", frmConEnderecos);
USEFORM("CadLivros.cpp", frmCadLivros);
USEFORM("ConLivros.cpp", frmConLivros);
USEFORM("ConVendas.cpp", frmConVendas);
USEFORM("CadClientes.cpp", frmCadClientes);
USEFORM("ConClientes.cpp", frmConClientes);
USEFORM("VenderLivros.cpp", frmVenderLivros);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
//  if (FindWindow("TfrmPrincipal",NULL)==0) {
        try
        {
                 Application->Initialize();
                 Application->Title = "Livrus Virtus";
                 Application->CreateForm(__classid(TfrmPrincipal), &frmPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
//  } else
//     ShowMessage("A Aplicação já está sendo executada.");

  return 0;
}
//---------------------------------------------------------------------------
