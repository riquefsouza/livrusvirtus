      program Character_List

      integer i

      do i=ICHAR('A'),ICHAR('Z')
        print '($A1,1H )',CHAR(i)
      enddo

      stop
      end
