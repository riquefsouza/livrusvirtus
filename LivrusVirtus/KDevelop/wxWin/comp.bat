c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o ConsultasSQL.o ConsultasSQL.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o RotinasGlobais.o RotinasGlobais.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Sobre.o Sobre.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Splash.o Splash.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Filha.o Filha.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Login.o Login.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Principal.o Principal.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Livrus.o Livrus.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Cadastros.o Cadastros.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o CadAssuntos.o CadAssuntos.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o Consultas.o Consultas.cpp

c++ -c   -I/usr/local/lib/wx/include/x11univ-2.4 -I/usr/local/include -I/usr/X11R6/include -D_FILE_OFFSET_BITS=64 -D_LARGE_FILES    -D__WXUNIVERSAL__ -D__WXX11__  -D_IODBC_ -O2 -MMD -pthread -Wall  -o ConAssuntos.o ConAssuntos.cpp

c++  -o livrus ConsultasSQL.o RotinasGlobais.o Sobre.o Splash.o Filha.o Login.o Principal.o Cadastros.o CadAssuntos.o  Consultas.o ConAssuntos.o Livrus.o /home/hfs/wxX11-2.4.2/lib/libwx_x11univ-2.4.so.0.1.1 -pthread   -Wl,--version-script,/home/hfs/wxX11-2.4.2/version-script -L/usr/X11R6/lib -lX11 -lpng -ljpeg -ltiff -lz -ldl -lm



