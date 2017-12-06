C:\Comps\xharbour\bin\harbour %1.prg -n -q0 -gc -iC:\Comps\xharbour\include -p -w
c:\comps\bcc55\bin\bcc32 -O2 -d -Ic:\comps\bcc55\include -Lc:\comps\bcc55\lib -IC:\Comps\xharbour\include -LC:\Comps\xharbour\lib %1.c common.lib debug.lib vm.lib rtl.lib gtwin.lib lang.lib rdd.lib macro.lib pp.lib dbfdbt.lib dbffpt.lib dbfntx.lib dbfcdx.lib samples.lib hbzip.lib
del *.c
del *.obj
del *.ppo
del *.tds