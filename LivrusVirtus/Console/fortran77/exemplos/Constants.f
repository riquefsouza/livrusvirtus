! 'binary-digits'B
! 'octal-digits'O
! 'hexadecimal-digits'Z
! 'hexadecimal-digits'X
!
!     or
!
! B'binary-digits'
! O'octal-digits'
! Z'hexadecimal-digits'
! X'hexadecimal-digits'

      !1234567890
      print *,'1001001100101100000001011010010'B  !Binary constant
      print *,'11145401322'O                      !Octal constant
      print *,'499602D2'X                         !Hexadecimal constant

      !1234567890
      print *,B'1001001100101100000001011010010'  !Binary constant
      print *,O'11145401322'                      !Octal constant
      print *,X'499602D2'                         !Hexadecimal constant

      end
