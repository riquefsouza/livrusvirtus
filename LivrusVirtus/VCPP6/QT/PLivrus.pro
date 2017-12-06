TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

SOURCES	+= Livrus.cpp

FORMS	= Principal.ui \
	Sobre.ui \
	AlterarSenha.ui \
	Cadastros.ui \
	Consultas.ui \
	CadEnderecos.ui \
	CadClientes.ui \
	CadLivros.ui \
	VenderLivros.ui \
	ConVendas.ui \
	Splash.ui \
	Login.ui \
	Teste.ui

IMAGES	= figuras/Livrus.bmp \
	figuras/cliente.xpm \
	figuras/Livro.xpm \
	figuras/Livros.xpm \
	figuras/LivrusVirtus.xpm \
	figuras/Login.xpm \
	figuras/Sair.xpm \
	figuras/Sobre.xpm

DBFILE	= PLivrus.db
unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}



