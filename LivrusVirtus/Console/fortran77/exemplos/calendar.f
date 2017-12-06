!!*********************************************************************
!! No Copyright - this is Freeware
!!*********************************************************************
!! File:       Calendar.f
!! Author:     Xie Wei Bao
!! Email:      tech@cup.btinternet.co.uk
!!
!! Purpose:
!!    Display a calendar
!!
!!*********************************************************************
      program main
      integer month, year
      call GetData (month, year)
      call GenerateCalendar (month, year)
      call PrintCalendar (month, year)
      stop
      end
!**********************************************************************
! Data definitions
!**********************************************************************
      block data
      common /calinfo/ mDaysPerMonth, mWeek,
     &       mDayStr, mMonthStr, mDateStr
      integer mDaysPerMonth(12)
      integer mWeek(0:4,0:6)
      character*9  mDayStr(0:6)
      character*17 mMonthStr(12)
      character*2  mDateStr(0:31)
      data mDaysPerMonth /
     &     31, 28, 31, 30, 31, 30,
     &     31, 31, 30, 31, 30, 31 /
      data mDayStr /
     &    ' Monday  ',
     &    ' Tuesday ',
     &    'Wednesday',
     &    ' Thursday',
     &    '  Friday ',
     &    ' Saturday',
     &    '  Sunday ' /
      data mMonthStr /
     &    '    J A N U A R Y',
     &    '  F E B R U A R Y',
     &    '        M A R C H',
     &    '        A P R I L',
     &    '            M A Y',
     &    '          J U N E',
     &    '          J U L Y',
     &    '      A U G U S T',
     &    'S E P T E M B E R',
     &    '    O C T O B E R',
     &    '  N O V E M B E R',
     &    '  D E C E M B E R' /
      data mDateStr /
     &    '  ', ' 1', ' 2', ' 3', ' 4', ' 5', ' 6', ' 7', ' 8', ' 9',
     &    '10', '11', '12', '13', '14', '15', '16', '17', '18', '19',
     &    '20', '21', '22', '23', '24', '25', '26', '27', '28', '29',
     &    '30', '31' /
      end
!**********************************************************************
! Compute the day of the week.  Day 0 = Monday
!**********************************************************************
      integer function DayOfWeek (iDay, iMonth, iYear)
      implicit none
!     parameters
      integer iDay, iMonth, iYear
!     common
!     local
      integer dd, mm, yy
      if (iMonth .gt. 2) then
          mm = iMonth + 1
          yy = iYear
      else
          mm = iMonth + 13
          yy = iYear - 1
      endif
      dd = iDay + int (mm * 30.6) + int ((yy * 1461) / 4)
!     add 4 to make 0=Monday
      dd = dd + 4
      DayOfWeek = mod (dd, 7)
      return
      end
!**********************************************************************
! Get the month to be printed
!**********************************************************************
      subroutine GetData (oMonth, oYear)
!     parameters
      integer oMonth, oYear
!     common
!     local
      write (*, '(''Month: '')')
      read *, oMonth
      write (*, '(''Year: '')')
      read *, oYear
      return
      end
!**********************************************************************
! Place the days in the correct positions
!**********************************************************************
      subroutine GenerateCalendar (iMonth, iYear)
      implicit none
!     parameters
      integer iMonth, iYear
!     common
      common /calinfo/ mDaysPerMonth, mWeek,
     &       mDayStr, mMonthStr, mDateStr
      integer mDaysPerMonth(12)
      integer mWeek(0:4, 0:6)
      character*9  mDayStr(0:6)
      character*17 mMonthStr(12)
      character*2  mDateStr(0:31)
      external DayOfWeek
      integer DayOfWeek
!     local
      integer week, day
      integer mday  ! month day 1-31
      integer lastday ! of month
      
      do 20 week = 0, 4, 1
          do 10 day = 0, 6, 1
              mWeek(week,day) = 0
10        continue
20    continue
!     This will work until 2100
      lastday = mDaysPerMonth(iMonth)
      if (iMonth .eq. 2 .and. mod (iYear, 4) .eq. 0)
     &    lastday = lastday + 1
!     Fill in the calendar
      day = DayOfWeek (1, iMonth, iYear)
      week = 0
      do 30 mday = 1, lastday, 1
          mWeek(week,day) = mday
          day = mod (day + 1, 7)
          if (day .eq. 0) week = mod (week + 1, 5)
30    continue
      return
      end
!**********************************************************************
! Generate a calendar for the month and year
!**********************************************************************
      subroutine PrintCalendar (iMonth, iYear)
      implicit none
!     parameters
      integer iMonth, iYear
!     common
      integer pLineLen, pYearOffsetLo, pYearOffsetHi
      parameter (
     &    pLineLen = 80,
     &    pYearOffsetLo = 6,
     &    pYearOffsetHi = 12)
      common /calinfo/ mDaysPerMonth, mWeek,
     &       mDayStr, mMonthStr, mDateStr
      integer mDaysPerMonth(12)
      integer mWeek(0:4, 0:6)
      character*9  mDayStr(0:6)
      character*17 mMonthStr(12)
      character*2  mDateStr(0:31)
!     local
      character line*(pLineLen)
      integer linelen
      integer mid, i, w, d
      integer posn, digit, yval, offset

!     wipe out the line
      do 10 i = 1, pLineLen, 1
          line(i:i) = ' '
10    continue

!     Centralize month and year
      linelen = len(mMonthStr(iMonth))
      mid = (pLineLen - linelen - pYearOffsetHi) / 2
      line(mid:) = mMonthStr(iMonth)
      yval = iYear
      do 20 offset = pYearOffsetHi, pYearOffsetLo, -2
          digit = mod(yval, 10) + ichar ('0')
          posn = offset + mid + linelen
          line(posn:posn) = char(digit)
          yval = yval / 10
20    continue
      write (*, '(A80//)') line
!     Print the weekdays
      write (*, 1000) (mDayStr(d), d = 0, 6, 1)
1000  format (7(2x,A9)/'+',7('----------+'))
!     For some silly reason, we cannot do this in a
!     nested implied loop
      do 30 w = 0, 4, 1
          write (*, 1010) (mDateStr(mWeek(w,d)), d = 0, 6, 1)
1010      format (
     &        '|',7(8x,A2,'|')/
     &        4('|',7(10x,'|')/),
     &        '+',7('----------+'))
30    continue
      return
      end
