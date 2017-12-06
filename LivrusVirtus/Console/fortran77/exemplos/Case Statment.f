      program Case_Statment

      integer i
      data i/15/

      select case (i)
        case (:5)
          print *,'i <= 5'
        case (6)
          print *,'i = 6'
        case (7:10)
          print *,'7 <= i <= 10'
        case (11,15,18)
          print *,'i = 11 or 15 or 18'
        case (20:)
          print *,'i >= 20'
      end select
      
      stop
      end
