rem gcc -O3 -c -gnatp -gnatn -s -m486 funcoesc.adb
rem gcc -gnatc -c ustrings.ads
rem gcc -c ustrings.adb

gcc -c %1.adb
gnatmake %1.adb
del *.o
del *.ali
del %1
