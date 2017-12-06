! Author: Guilherme Lepsch
! Date: 08-14-2002

#ifndef UnitCrt
#define UnitCrt

#include "Strings.fpp"

      subroutine ClrScr
        call System('@CLS')
      return
      end
      
      subroutine Mode(COLS,LINES)
      integer COLS,LINES
      character*255 Buf,sCOLS,sLINES,IntToStr
        Buf = '@MODE CON: COLS=\0'
        sCOLS = IntToStr(COLS)
        sLINES = IntToStr(LINES)
        call StrCat2(Buf,sCOLS,' ')
        call StrCat2(Buf,'LINES=',sLINES)
        call SYSTEM(Buf)
      return
      end
      
#endif
