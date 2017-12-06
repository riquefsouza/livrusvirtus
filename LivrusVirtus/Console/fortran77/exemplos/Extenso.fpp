! Author: Guilherme Lepsch
! Date: 11-08-2002

#ifndef UnitExtenso
#define UnitExtenso

#include "Strings.fpp"
      
      character*(*) function Extenso(Num)
      character*(*) Num
      character*10 Uni(0:19)/'zero\0','um\0','dois\0','tràs\0',
     .'quatro\0','cinco\0','seis\0','sete\0','oito\0','nove\0','dez\0',
     .'onze\0','doze\0','treze\0','quatorze\0','quinze\0',
     .'dezesseis\0','dezessete\0','dezoito\0','dezenove\0'/
      character*10 Dez(2:9)/'vinte\0','trinta\0','quarenta\0',
     .'cinquenta\0','sessenta\0','setenta\0','oitenta\0','noventa\0'/
      character*13 Cen(0:9)/'cem\0','cento\0','duzentos\0',
     .'trezentos\0','quatrocentos\0','quinhentos\0','seissentos\0',
     .'setecentos\0','oitocentos\0','novecentos\0'/
      character*11 Mil(1:5,0:1)/'mil\0','milh∆o\0','bilh∆o\0',
     .'trilh∆o\0','quatrilh∆o\0','mil\0','milh‰es\0','bilh‰es\0',
     .'trilh‰es\0','quatrilh‰es\0'/
      integer d,i,L,V,Plural,StrLen
      character Sep*3

        Extenso = '\0';
        Sep = '\0'

        L = StrLen(Num)
        i = 1
        do while (i.LE.L)
          d = L - i + 1;
          V = ICHAR(Num(i:i)) - 48;

          if ((V.EQ.0).AND.(L.GT.1)) then
            i = i + 1
            cycle
          endif
          
          if ((V.GT.1).OR.(MOD(d,3).NE.1)) then
            Plural = 1
          else
            Plural = 0
          endif
          
          if ((MOD(d,3).EQ.0).AND.(V.EQ.1).AND.
     .       (Num(i+1:i+2).EQ.'00')) then
            call StrCat2(Extenso,Sep,Cen(0))
            i = i + 2
            d = L - i + 1
          else
            if ((MOD(d,3).EQ.2).AND.((V.EQ.0).OR.(V.EQ.1))) then
              call StrCat2(
     .               Extenso,
     .               Sep,
     .               Uni(V*10+ICHAR(Num(i+1:i+1))-48))
              i = i + 1
              d = L - i + 1
            else
              select case (MOD(d,3))
                case (1)
                  call StrCat2(Extenso,Sep,Uni(V))
                case (2)
                  call StrCat2(Extenso,Sep,Dez(V))
                case (0)
                  call StrCat2(Extenso,Sep,Cen(V))
              end select
            endif
          endif
          
          if ((((d-1)/3).GT.0).AND.(MOD(d,3).EQ.1)) then
            Sep = ' \0'
            call StrCat2(Extenso,Sep,Mil((d-1)/3,Plural))
          else
            Sep = ' e '
          endif

          i = i + 1
        end do
      return
      end
      
#endif
