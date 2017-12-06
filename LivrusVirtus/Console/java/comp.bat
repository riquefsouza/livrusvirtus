@echo off
echo compilando livrus
c:\jbuilder9\jdk1.4\bin\javac livrus.java
echo criando livrus.jar
c:\jbuilder9\jdk1.4\bin\jar -cfm livrus.jar cmanifest.tmp .
echo excluindo classes
del *.class

