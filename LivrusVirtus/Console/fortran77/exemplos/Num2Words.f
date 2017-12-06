!!**********************************************************************
!! No Copyright - this is Freeware
!!**********************************************************************
!! File:        Num2Words.f
!! Author:      Xie Wei Bao
!! Email:       tech@cup.btinternet.co.uk
!!
!! Purpose:
!!    Print numbers in English, German and Roman Numerals
!!
!!*********************************************************************
      program main
      integer max
      parameter (max = 9999)
      integer i
10    continue
!         Have to use write otherwise an annoying leading space appears
          write (*, 15) max
15        format (//'Number (0 to exit, ',I4,' max)')
          read  *, i
          if (i .le. 0) goto 20
          if (i .le. 9999) then
              call UKEnglish (i)
              call German (i)
              call Chinese (i)
              call RomanTest (i)
          endif
          goto 10
20    continue
      stop
      end
      
!!**********************************************************************
      block data
!
!     English
      integer EngValMax
      parameter (EngValMax = 27)
      common /EngXlat/ EngVal, EngStr, EngStr100, EngStr1000, EngStrAnd
      integer EngVal(EngValMax)
      character*16 EngStr(EngValMax), EngStr100, EngStr1000, EngStrAnd
      data EngVal /
     &     1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
     &    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
     &            30, 40, 50, 60, 70, 80, 90 /
      data EngStr /
     &    ' one', ' two', ' three', ' four', ' five',
     &    ' six', ' seven', ' eight', ' nine', ' ten',
     &    ' eleven', ' twelve', ' thirteen', ' fourteen', ' fifteen',
     &    ' sixteen', ' seventeen', ' eighteen', ' nineteen', ' twenty',
     &    ' thirty', ' forty', ' fifty', ' sixty', ' seventy',
     &    ' eighty', ' ninety' /
      data EngStr100 / ' hundred' /
      data EngStr1000 / ' thousand' /
      data EngStrAnd / ' and' /
!
!     German
      integer GerValMax
      parameter (GerValMax = 27)
      common /GerXlat/ GerVal, GerStr, GerStr100, GerStr1000, GerStrAnd
      integer GerVal(GerValMax)
      character*16 GerStr(GerValMax), GerStr100, GerStr1000, GerStrAnd
      data GerVal /
     &     1,  2,  3,  4,  5,  6,  7,  8,  9, 10,
     &    11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
     &            30, 40, 50, 60, 70, 80, 90 /
      data GerStr /
     &    ' eins', ' zwei', ' drei', ' vier', ' funf',
     &    ' sechs', ' sieben', ' acht', ' neun', ' zehn',
     &    ' elf', ' zwolf', ' dreizehn', ' vierzehn', ' funfzehn',
     &    ' sechzehn', ' siebzehn', ' achtzehn', ' neunzehn',
     &    ' zwanzig',  ' dreizig',  ' vierzig', ' funfzig',
     &    ' sechzig',  ' siebzig',  ' achtzig', ' neunzig' /
      data GerStr100 / ' hundret' /
      data GerStr1000 / ' tousend' /
      data GerStrAnd / ' und' /
!
!     Chinese - the number indicates the tone
      integer ChiTenMax
      parameter (ChiTenMax = 5)
      common /ChiXlat/ ChiStr, ChiTenVal, ChiTenStr, ChiTwo
      integer ChiTenVal(ChiTenMax)
      character*16 ChiStr(10), ChiTenStr(ChiTenMax), ChiTwo
      data ChiStr /
     &    ' ling2', ' yi1' , ' er4', ' san1', ' si4',
     &    ' wu3',   ' liu4', ' qi1', ' ba1',  ' jiu3' /
!     Special for counting
      data ChiTwo / ' liang3' /
      data ChiTenVal / 1, 10, 100, 1000, 10000 /
      data ChiTenStr / ' ', ' shi2 ', ' bai3 ', ' qian1 ', ' wan4 '/
!
!     Roman Numerals
      integer rTenMax, rMax
      parameter (rTenMax = 5, rMax = 16)
      common /Roman/ romanVal, romanTen, romanFive,
     &               romanErrBig, romanErrSmall
      character*1 romanTen(rTenMax)
      character*1 romanFive(rTenMax)
      character*(rMax) romanErrBig, romanErrSmall
      integer romanVal(rTenMax)
      data romanTen  /   '?',  'M', 'C', 'X', 'I' /
      data romanFive /   '?',  'D', 'L', 'V', '?' /
      data romanVal  / 10000, 1000, 100,  10,   1 /
      data romanErrBig   / 'Too big'   /
      data romanErrSmall / 'Too small' /

      end
!*************************************************************************
!     Find the length of a string, given the old length of that string
!*************************************************************************
      subroutine StrCat (iStr, iCatStr, vLen)
!     parameters
      character*(*) iStr
      character*(*) iCatStr
      integer vLen
!     locals
      integer result
      iStr(vLen:) = iCatStr
      result = vLen + 2
!     Look for end of string
      do while (iStr(result:result) .ne. ' ')
          result = result + 1
      end do
      vLen = result
      return
      end
!*************************************************************************
!     Print the number in UK English
!*************************************************************************
      subroutine UKEnglish (numval)
      integer numval
!     common block
      integer EngValMax
      parameter (EngValMax = 27)
      common /EngXlat/ EngVal, EngStr, EngStr100, EngStr1000, EngStrAnd
      integer EngVal(EngValMax)
      character*16 EngStr(EngValMax), EngStr100, EngStr1000, EngStrAnd
!     local
      integer rem, dig, tens;
      integer curr, next, reslen
      character*64 result
      logical and;

!     Print it in English
      rem      = numval
      tens     = 1000
      result   = ' '
      reslen   = 1
      and      = numval .lt. 100
      do while (rem .ne. 0)
         dig = rem / tens
         if (dig .ne. 0) then
             next = 1
             do 50 curr = 1, EngValMax, 1
                next = next + 1
                if (rem .eq. EngVal(curr)) then
!                  1..20, 30, 40 .. 90
                   if (.not. and)
     &                call StrCat (result, EngStrAnd, reslen)
                   call StrCat (result, EngStr(curr), reslen)
                   rem = 0;
                   goto 60
                else if (dig .eq. EngVal(curr) .and. rem .gt. 20) then
                   if (tens .eq. 1 .and. .not. and) then
                      call StrCat (result, EngStrAnd, reslen)
                      and = .true.
                   endif
                   if (tens .eq. 1000) then
!                     xxx thousand ...
                      call StrCat (result, EngStr(curr), reslen);
                      call StrCat (result, EngStr1000, reslen);
                      goto 60
                   else if (tens .eq. 100) then
!                     xxx hundred ...
                      call StrCat (result, EngStr(curr), reslen);
                      call StrCat (result, EngStr100, reslen);
                      goto 60
                   endif
!               Otherwise look for a better option
                else if (rem.gt.EngVal(curr) .and.
     &              rem.lt.EngVal(next)) then
                    if (.not. and) then
                        call StrCat (result, EngStrAnd, reslen)
                        and = .true.
                    endif
!                   2x, 3x, 4x, ... 9x
                    call StrCat (result, EngStr(curr), reslen)
                    goto 60
                endif
50          continue
60          continue
         endif
         rem  = mod (rem, tens)
         tens = tens / 10
      enddo
      write (*, *) 'UK English:', result
      return
      end
!*************************************************************************
!     Print the number in German
!*************************************************************************
      subroutine German (numval)
      integer numval
!     common block
      integer GerValMax
      parameter (GerValMax = 27)
      common /GerXlat/ GerVal, GerStr, GerStr100, GerStr1000, GerStrAnd
      integer GerVal(GerValMax)
      character*16 GerStr(GerValMax), GerStr100, GerStr1000, GerStrAnd
!     local
      integer rem, dig, tens;
      integer curr, next, reslen
      character*64 result
      logical and;

!     Print it in German
      rem      = numval
      tens     = 1000
      result   = ' '
      reslen   = 1
      and      = numval .lt. 100
      do while (rem .ne. 0)
         dig = rem / tens
         if (dig .ne. 0) then
             next = 1
             do 50 curr = 1, GerValMax, 1
                next = next + 1
                if (rem .eq. GerVal(curr)) then
!                  1, 2, 3 ... 20, 30, 40, ... 90
                   if (.not. and)
     &                call StrCat (result, GerStrAnd, reslen)
                   call StrCat (result, GerStr(curr), reslen)
                   rem = 0;
                   goto 60
                else if (dig .eq. GerVal(curr) .and. rem .gt. 20) then
                   if (tens .eq. 1 .and. .not. and) then
                      call StrCat (result, GerStrAnd, reslen)
                      and = .true.
                   endif
                   if (tens .eq. 1000) then
!                     xxx tousend
                      call StrCat (result, GerStr(curr), reslen);
                      call StrCat (result, GerStr1000, reslen);
                      goto 60
                   else if (tens .eq. 100) then
!                     xxx hundert
                      call StrCat (result, GerStr(curr), reslen);
                      call StrCat (result, GerStr100, reslen);
                      goto 60
                   endif
!               Otherwise look for a better option
                else if (rem.gt.GerVal(curr) .and.
     &              rem.lt.GerVal(next)) then
                    if (.not. and) then
                        call StrCat (result, GerStrAnd, reslen)
                        and = .true.
                    endif
!                   do the units first
                    dig = rem - GerVal(curr)
                    if (dig .ne. 0) then
                       call StrCat (result, GerStr(dig), reslen)
                       call StrCat (result, GerStrAnd, reslen)
                    endif
!                   then do the tens
                    call StrCat (result, GerStr(curr), reslen)
                    rem = 0
                    goto 60
                endif
50          continue
60          continue
         endif
         rem  = mod (rem, tens)
         tens = tens / 10
      enddo
      write (*, *) 'German    :', result
      return
      end
!*************************************************************************
!     Convert from Arabic to Roman
!*************************************************************************
      character*16 function ArabToRoman (iArab)
!     parameters
      integer iArab
!     common
      integer rTenMax, rMax
      parameter (rTenMax = 5, rMax = 16)
      common /Roman/ romanVal, romanTen, romanFive,
     &               romanErrBig, romanErrSmall
      character*1 romanTen(rTenMax)
      character*1 romanFive(rTenMax)
      character*(rMax) romanErrBig, romanErrSmall
      integer romanVal(rTenMax)
!     local
      character*1 rone, rfive, rten
      integer      one
      character*(rMax) result
      integer rpos, mag
      integer rem, digit

      if (iArab .lt. 1)  then
         result = romanErrSmall
      else if (iArab .gt. 3999) then
         result = romanErrBig
      else
         rem = iArab
         rpos = 1
         result = '                '
         do 100 mag = 1, rTenMax - 1, 1
            one   = romanVal(mag + 1)
            rone  = romanTen(mag + 1)
            rfive = romanFive(mag)
            rten  = romanTen(mag)
            digit = rem / one
!           form the number in Roman numerals
            select case (digit)
            case (0)
            case (1)    ! I, X, C, M
               result(rpos:rpos) = rone
               rpos = rpos + 1
            case (2)    ! II
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
            case (3)    ! III
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
            case (4)    ! IV, XL, CD
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rfive
               rpos = rpos + 1
            case (5)    ! V, L, D
               result(rpos:rpos) = rfive
               rpos = rpos + 1
            case (6)    ! VI, LX, DC
               result(rpos:rpos) = rfive
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
            case (7)    ! VII
               result(rpos:rpos) = rfive
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
            case (8)    ! VIII
               result(rpos:rpos) = rfive
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rone
               rpos = rpos + 1
            case (9)    ! IX, XC, CM
               result(rpos:rpos) = rone
               rpos = rpos + 1
               result(rpos:rpos) = rten
               rpos = rpos + 1
            end select
            rem = mod (rem, one)

100      continue
      endif
      ArabToRoman = result
      return
      end

!*************************************************************************
!     Convert from Roman to Arabic
!*************************************************************************
      integer function RomanToArab (iRoman)
!     common
      integer rTenMax, rMax
      parameter (rTenMax = 5, rMax = 16)
      common /Roman/ romanVal, romanTen, romanFive,
     &               romanErrBig, romanErrSmall
      character*1 romanTen(rTenMax)
      character*1 romanFive(rTenMax)
      character*(rMax) romanErrBig, romanErrSmall
      integer romanVal(rTenMax)
!     parameters
      character*(rMax) iRoman
!     local
      character*1 rone, rfive, rten, digit, prev
      integer      one
      integer result
      integer rpos, mag
      integer nextDigit

      result = 0
      mag = 1
      digit = '?'
      assign 90 to nextDigit
      do 100 rpos = 1, rMax, 1
         prev  = digit
         digit = iRoman(rpos:rpos)
10       continue
!           Look for the family of numbers
            one   = romanVal(mag + 1)
            rone  = romanTen(mag + 1)
            rfive = romanFive(mag)
            rten  = romanTen(mag)

            if (digit .eq. rone) then
               result = result + one
               goto nextDigit
            else if (digit .eq. rfive) then
               result = result + one * 5
!              subtract one from 5 and one that was added earlier
               if (prev .eq. rone) result = result - one * 2
               goto nextDigit
            else if (digit .eq. rten) then
               result = result + one * 10
!              subtract one from 10 and one that was added earlier
               if (prev .eq. rone) result = result - one * 2
               goto nextDigit
            endif
!           drop by 10
            mag = mag + 1
            if (mag - rTenMax) 10, 110, 110
90       continue
!         print *, 'digit = ', digit, '  prev = ', prev,
!     &        '  one = ', rone, '  five = ', rfive,
!     &        '  ten = ', rten, '  result = ', result
!
100   continue  ! end of loop
110   continue  ! break out of loop
      RomanToArab = result
      return
      end
!*************************************************************************
!     Test for Roman Numerals
!*************************************************************************
      subroutine RomanTest (numval)
!     parameters
      integer numval
!     local
      external ArabToRoman, RomanToArab
      character*16 a2r, ArabToRoman
      integer      r2a, RomanToArab

      a2r = ArabToRoman(numval)
!     Test Roman to Arab conversion
      r2a = RomanToArab(a2r)
      if (r2a .ne. numval) then
         print *, 'Roman     : ', numval, ' ', a2r
      else
         print *, 'Roman     : ', a2r
      endif
      return
      end
!*************************************************************************
!     Convert a number to Chinese
!*************************************************************************
      subroutine Chinese (numval)
!     parameters
      integer numval
!     common
      integer ChiTenMax
      parameter (ChiTenMax = 5)
      common /ChiXlat/ ChiStr, ChiTenVal, ChiTenStr, ChiTwo
      integer ChiTenVal(5)
      character*16 ChiStr(10), ChiTenStr(5), ChiTwo
      character*16 Ling
      equivalence (Ling, ChiStr(1))
!     local
      character*64 result
      logical precedingDigits, counting
      integer rem, reslen, digit, break, tens
      
      precedingDigits = .false.
      counting = .true.  ! if true, 2 has a different sound
      rem = numval
      result = ' '
      reslen = 1
      assign 110 to break
      do 100 tens = ChiTenMax, 1, -1
         if (rem .ge. ChiTenVal(tens)) then
!           Get the digit
            digit = rem / ChiTenVal(tens)
!           Save it in string form
!           Only add the magnitude if it is greater than 20 so
!           we get 12 printed as "shi er" instead of "yi shi er"
            if (digit .ne. 1 .or. ChiTenVal(tens) .ne. 10)
     &         call StrCat (result, ChiStr(digit + 1), reslen)
!           See what is remaining
            rem = mod (rem, ChiTenVal(tens))
            if (rem .gt. 0) then
!              Add the tens tag.  Only do this if there are
!              remaining values.  This is so that 150 will be
!              "yi pai wu" instead of "yi pai wu shi"
               call StrCat (result, ChiTenStr(tens), reslen)
            else
!              Do we have something like 1000?  If so, we need
!              the tag so that 1000 will be "yi qian" instead
!              of "yi"
               if (.not. precedingDigits)
     &            call StrCat (result, ChiTenStr(tens), reslen)
!              Stop since there is nothing more to process
               goto break
            endif
!           Indicate that we need the 'ling's
            precedingDigits = .true.
     
         else if (precedingDigits .or. rem .eq. 0) then
!           Add the 'ling's
            call StrCat (result, Ling, reslen)
!           Stop if nothing more to process otherwise there
!           will be an infinite number of lings
            if (rem .eq. 0) goto break
!        Only when counting counting is enabled
         else if (.not. precedingDigits .and. rem .eq. 2
     &      .and. counting) then
!           special case for 2
            call StrCat (result, ChiTwo, reslen)
            goto break
         endif
100   continue
!     break
110   continue
      write (*, *) 'Chinese   :', result
      return
      end

