@echo off
rem %1=c:\jbuilder9\jdk1.4\bin
rem %2=c:\livrusvirtus\jbuilder9\livrus

echo compilando Livrus

%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\ConsultasSQL.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\RotinasGlobais.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\MDIDesktopPane.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\WindowMenu.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConsultas.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadastros.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmAlterarSenha.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmLogin.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmSobre.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmSplash.java

%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadAssuntos.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConAssuntos.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadAutores.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConAutores.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadEditoras.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConEditoras.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadEnderecos.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConEnderecos.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadIdiomas.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConIdiomas.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadPaises.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConPaises.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadProfissoes.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConProfissoes.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadClientes.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConClientes.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmCadLivros.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConLivros.java

%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmConVendas.java

%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\frmPrincipal.java
%1\javac -deprecation -classpath %2\classes -d %2\classes %2\src\livrus\Livrus.java

echo criando livrus.jar
cd classes
%1\jar -cfm livrus.jar %2\manifest.tmp .
copy livrus.jar %2
del livrus.jar
cd ..

