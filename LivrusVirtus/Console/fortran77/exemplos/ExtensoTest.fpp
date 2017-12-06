! Desc.: Main program to test the Extenso function
! Author: Guilherme Lepsch
! Date: 02-10-2003

#ifndef UnitMain
#define UnitMain

!Included files
#include "Extenso.fpp"
#include "Strings.fpp"
#include "Crt.fpp"

      program ExtensoTest

      implicit none
      character*255 Ex,Extenso
      integer StrLen

      call ClrScr
      call Mode(40,20)

      Ex = Extenso('1234567890')
      write (*,'(A)') Ex(:StrLen(Ex))

      end
      
#endif
