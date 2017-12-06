      program ASCII_Table

      integer i

      do i=32,127
        print '($I3,3H = ,A1,1H )', i,CHAR(i)
      enddo
      
      stop
      end
