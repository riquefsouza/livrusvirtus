      program Main
! First, after program statment above you can declare many IMPLICIT FUNCTIONS
      RImpTan(X)=SIN(X)/COS(X)
! The first letter indicate the type of the implicit function:
!     I, J, K, L, M, N = Integer
!     Others = Real
!
! Note that the Tangent function already exists. It's called TAN.

      real T
      data T/5./  !same as T=5.
      
      print *,RImpTan(5.) ! call the RImpTan IMPLICIT FUNCTION
      
      print *,FuncTan(5.) ! call the FuncTan FUNCTION
      
      call SubTan(T)      ! call the SubTan SUBROUTINE
      print *,T
      
      stop
      end

! ---------- FUNCTIONS and SUBROUTINES ----------

! FUNCTION declaration:
!
!       [result TYPE] FUNCTION function_name[(param_1 [,param_2 [,param_n] ])]
!       [param_1 TYPE]
!       [param_2 TYPE]
!             ...
!       [param_n TYPE]
!
!         ... ! Function scope
!
!       return
!       end

      real function FuncTan(X)
      real X
        FuncTan=SIN(X)/COS(X)
      return
      end
      
! SUBROUTINE declaration:
!
!       SUBROUTINE subroutine_name[(param_1 [,param_2 [,param_n] ])]
!       [param_1 TYPE]
!       [param_2 TYPE]
!             ...
!       [param_n TYPE]
!
!         ... ! Subroutine scope
!
!       return
!       end

      subroutine SubTan(X)
        X = SIN(X)/COS(X)
      return
      end
! Note that I didn't declared any params. When you do it, the parameters
! are by reference, and not by value. Then when you change the parameter,
! you are changing the real variable that called this SUBROUTINE
