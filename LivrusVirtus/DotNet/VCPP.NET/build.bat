cl.exe /Zi /clr /c /Fe.\produto\Livrus.exe Livrus.cpp CadAssuntos.cpp Cadastros.cpp CadAutores.cpp CadClientes.cpp CadEditoras.cpp CadEnderecos.cpp CadIdiomas.cpp CadLivros.cpp CadPaises.cpp CadProfissoes.cpp ConAssuntos.cpp ConAutores.cpp ConClientes.cpp ConEditoras.cpp ConEnderecos.cpp ConIdiomas.cpp ConLivros.cpp ConPaises.cpp ConProfissoes.cpp Consultas.cpp ConsultasSQL.cpp ConVendas.cpp Login.cpp Principal.cpp RotinasGlobais.cpp Sobre.cpp Splash.cpp AlterarSenha.cpp VenderLivros.cpp
link.exe /OUT:.\produto\Livrus.exe /ASSEMBLYRESOURCE:Livrus.frmSplash.resources /ASSEMBLYRESOURCE:Livrus.frmSobre.resources /ASSEMBLYRESOURCE:Livrus.frmPrincipal.resources /ASSEMBLYRESOURCE:Livrus.frmLogin.resources Livrus.obj CadAssuntos.obj Cadastros.obj CadAutores.obj CadClientes.obj CadEditoras.obj CadEnderecos.obj CadIdiomas.obj CadLivros.obj CadPaises.obj CadProfissoes.obj ConAssuntos.obj ConAutores.obj ConClientes.obj ConEditoras.obj ConEnderecos.obj ConIdiomas.obj ConLivros.obj ConPaises.obj ConProfissoes.obj Consultas.obj ConsultasSQL.obj ConVendas.obj Login.obj Principal.obj RotinasGlobais.obj Sobre.obj Splash.obj AlterarSenha.obj VenderLivros.obj
del *.obj