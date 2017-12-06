@echo off
rem %1=c:\jbuilder9\jdk1.4\bin
rem %2=c:\livrusvirtus\jbuilder9\livrus

echo criando livrus.jar
cd classes
%1\jar -cfm livrus.jar %2\manifest.tmp .
copy livrus.jar %2
del livrus.jar
cd ..
