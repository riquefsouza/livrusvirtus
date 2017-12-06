@echo off
rem %1=c:\jbuilder9\jdk1.4\bin
rem %2=C:\LivrusVirtus\wxWindows\wxJava\classes
rem %3=C:\wx4j\wx4j.jar
rem %4=C:\LivrusVirtus\wxWindows\wxJava\src\livrus

echo compilando Livrus

%1\javac -deprecation -classpath "%2;%3" -d %2 %4\ConsultasSQL.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmAlterarSenha.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadAssuntos.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadastros.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadAutores.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadClientes.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadEditoras.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadEnderecos.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadIdiomas.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadLivros.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadPaises.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmCadProfissoes.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConAssuntos.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConAutores.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConClientes.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConEditoras.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConEnderecos.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConIdiomas.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConLivros.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConPaises.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConProfissoes.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConsultas.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmConVendas.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmFilha.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmLogin.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmPrincipal.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmSobre.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmSplash.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\frmVenderLivros.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\LivrusApp.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\Resource.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\RotinasGlobais.java
%1\javac -deprecation -classpath "%2;%3" -d %2 %4\TextValidator.java

echo criando livrus.jar
cd classes
%1\jar -cfm livrus.jar C:\LivrusVirtus\wxWindows\wxJava\manifest.tmp .
copy livrus.jar C:\LivrusVirtus\wxWindows\wxJava
del livrus.jar
cd ..

