      program Random_Numbers
      real r

      !Initializes random numbers generator
      r = RAND(TIME())

      r = RAND(0)
      print *,r

      stop
      end
