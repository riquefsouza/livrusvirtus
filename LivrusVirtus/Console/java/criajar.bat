cd classes
c:\jdk1.3\bin\jar -cfm glivrus.jar d:\livrus\win\java\livrus\gmanifest.tmp .
copy glivrus.jar d:\livrus\win\java\livrus
del glivrus.jar
c:\jdk1.3\bin\jar -cfm clivrus.jar d:\livrus\win\java\livrus\cmanifest.tmp .
copy clivrus.jar d:\livrus\win\java\livrus
del clivrus.jar
cd ..
