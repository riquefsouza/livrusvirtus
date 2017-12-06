
g++ -c `wx-config --cxxflags` -o ConsultasSQL.o ConsultasSQL.cpp

g++ -c `wx-config --cxxflags` -o RotinasGlobais.o RotinasGlobais.cpp

g++ -c `wx-config --cxxflags` -o Sobre.o Sobre.cpp

g++ -c `wx-config --cxxflags` -o Splash.o Splash.cpp

g++ -c `wx-config --cxxflags` -o Filha.o Filha.cpp

g++ -c `wx-config --cxxflags` -o Login.o Login.cpp

g++ -c `wx-config --cxxflags` -o Principal.o Principal.cpp

g++ -c `wx-config --cxxflags` -o Livrus.o Livrus.cpp

g++ -o Livrus.exe ConsultasSQL.o RotinasGlobais.o Sobre.o Splash.o Filha.o Login.o Principal.o Livrus.o `wx-config --libs`

