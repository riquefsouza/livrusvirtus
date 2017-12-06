//---------------------------------------------------------------------------

#include <clx.h>
#pragma hdrstop
USEFORM("Principal.cpp", frmPrincipal);
USEFORM("Cadastros.cpp", frmCadastros);
USEFORM("Consultas.cpp", frmConsultas);
USEFORM("CadAssuntos.cpp", frmCadAssuntos);
USEFORM("AlterarSenha.cpp", frmAlterarSenha);
USEFORM("CadAutores.cpp", frmCadAutores);
USEFORM("CadClientes.cpp", frmCadClientes);
USEFORM("CadEditoras.cpp", frmCadEditoras);
USEFORM("CadEnderecos.cpp", frmCadEnderecos);
USEFORM("CadIdiomas.cpp", frmCadIdiomas);
USEFORM("CadLivros.cpp", frmCadLivros);
USEFORM("CadPaises.cpp", frmCadPaises);
USEFORM("CadProfissoes.cpp", frmCadProfissoes);
USEFORM("ConAssuntos.cpp", frmConAssuntos);
USEFORM("ConAutores.cpp", frmConAutores);
USEFORM("ConClientes.cpp", frmConClientes);
USEFORM("ConEditoras.cpp", frmConEditoras);
USEFORM("ConEnderecos.cpp", frmConEnderecos);
USEFORM("ConIdiomas.cpp", frmConIdiomas);
USEFORM("ConLivros.cpp", frmConLivros);
USEFORM("ConPaises.cpp", frmConPaises);
USEFORM("ConProfissoes.cpp", frmConProfissoes);
USEFORM("ConVendas.cpp", frmConVendas);
USEFORM("Login.cpp", frmLogin);
USEFORM("Sobre.cpp", frmSobre);
USEFORM("Splash.cpp", frmSplash);
USEFORM("VenderLivros.cpp", frmVenderLivros);
//---------------------------------------------------------------------------
int main(void)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfrmPrincipal), &frmPrincipal);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch(...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch(Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
