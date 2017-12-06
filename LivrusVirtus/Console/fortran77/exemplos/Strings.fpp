! Desc.: This unit defines many functions for Strings manipulation in FORTRAN.
!        Initialize strings with '\0'
! Author: Guilherme Lepsch
! Date: 08-12-2002
!
! Functions:
!   StrLen(S) -> Returns the length (integer) of the string S
!   StrToInt(S) -> Returns the integer value of the string S
!   IntToStr(N) -> Returns the string associated to the integer N
!   StrComp(Str1,Str2) -> Compares two strings with case sensitive.
!     Return 0 if Str1 = Str2, < 0 if Str < Str2 and > 0 if Str > Str2
!   StrIComp(Str1,Str2) -> Returns (logical) if Str1 is equal to Str2
!   StrPos(SubStr,Str) -> Returns the position of the string SubStr in the Str
!
! Subroutines:
!   StrCat(Dest,Source) -> Concatenate Source to Dest
!   StrInsert(Dest,Source,Index) -> Insert the string Source in Dest at position Index
!   StrDelete(S,Index,Count) -> Delete Count chars of the string S at position Index
!   StrLower(S) -> Convert all chars of the string S to lowercase
!   StrUpper(S) -> Convert all chars of the string S to uppercase
!   StrOfStr(Dest,Source,Count) -> Concatenate Source to Dest Count times
!   StrRead(Str) -> Reads a string

#ifndef UnitStrings
#define UnitStrings

      integer function StrLen(S)
      character*(*) S
      integer i
        StrLen = LEN(S)
        do i=1,StrLen
          if (S(i:i).EQ.'\0') then
            StrLen = i-1
            exit
          end if
        end do
      return
      end

      subroutine StrCat(Dest,Source)
      character*(*) Dest,Source
      integer LDest,LSource,StrLen
        LDest = StrLen(Dest)
        LSource = StrLen(Source)
        Dest(LDest+1:) = Source
        Dest(LDest+LSource+1:) = '\0'
      return
      end

      subroutine StrCat2(Dest,Source1,Source2)
      character*(*) Dest,Source1,Source2
        call StrCat(Dest,Source1)
        call StrCat(Dest,Source2)
      return
      end

      subroutine StrInsert(Dest,Source,Index)
      character*(*) Dest,Source
      integer L,StrLen
        L = StrLen(Source)
        Dest(L+Index:) = Dest(Index:)
        Dest(Index:L+Index-1) = Source(:L)
      return
      end
      
      subroutine StrDelete(S,Index,Count)
      character*(*) S
      integer Index,Count
        S(Index:) = S(Index+Count:)
      return
      end
      
      integer function StrToInt(S)
      character*(*) S
      integer i,StrLen,N,V
        StrToInt = 0
        N = 1
        do i=1,StrLen(S)
          V = ICHAR(S(i:i))
          select case (V)
            case (45)!ICHAR('-')
              if (i.EQ.1) then
                N = -1
              else
                return
              endif
            case (48:57)
              StrToInt = StrToInt*10 + (V-48)
            case default
              return
          end select
        end do
        StrToInt = StrToInt*N
      return
      end
      
      character*(*) function IntToStr(N)
      integer N,i
        i = ABS(N)
        IntToStr = '\0'
        do while (i.GE.10)
          call StrInsert(IntToStr,CHAR(MOD(i,10)+48),1)
          i = i / 10
        end do
        call StrInsert(IntToStr,CHAR(MOD(i,10)+48),1)
        if (N.LT.0) then
          call StrInsert(IntToStr,'-',1)
        endif
      return
      end
      
      subroutine StrLower(S)
      character*(*) S
      integer i,StrLen
        do i=1,StrLen(S)
          select case (ICHAR(S(i:i)))
            case (65:90)
              S(i:i) = CHAR(ICHAR(S(i:i)) + 32)
          end select
        end do
      return
      end

      subroutine StrUpper(S)
      character*(*) S
      integer i,StrLen
        do i=1,StrLen(S)
          select case (ICHAR(S(i:i)))
            case (97:122)
              S(i:i) = CHAR(ICHAR(S(i:i)) - 32)
          end select
        end do
      return
      end
      
      integer function StrComp(Str1,Str2)
      character*(*) Str1,Str2
      integer i,MIN,StrLen,L1,L2
        StrComp = 0
        L1 = StrLen(Str1)
        L2 = StrLen(Str2)
        do i=1,MIN(L1,L2)
          StrComp = StrComp + (ICHAR(Str1(i:i))-ICHAR(Str2(i:i)))
        end do
        
        if (L1.LT.L2) then
          do i=L1+1,L2
            StrComp = StrComp - ICHAR(Str2(i:i))
          end do
        else
          if (L1.GT.L2) then
            do i=L2+1,L1
              StrComp = StrComp + ICHAR(Str1(i:i))
            end do
          endif
        endif
        
      return
      end
      
      logical function StrIComp(Str1,Str2)
      character*(*) Str1,Str2
      integer L1,L2,i,StrLen
      character C1,C2
        L1 = StrLen(Str1)
        L2 = StrLen(Str2)
      
        StrIComp = (L1.EQ.L2)
        if (StrIComp) then
          do i=1,L1 !same as L2
            C1 = Str1(i:i)
            C2 = Str2(i:i)
            select case (ICHAR(C1))
              case (65:90,97:122)
                select case (ICHAR(C2))
                  case (65:90,97:122)
                    call StrUpper(C1)
                    call StrUpper(C2)
                end select
            end select
            StrIComp = (C1.EQ.C2)
            if (.NOT.StrIComp) exit
          end do
        end if
      return
      end

      integer function StrPos(SubStr,Str)
      character*(*) Substr,Str
      integer i,j,StrLen,L
        StrPos = 0
        L = StrLen(SubStr)
        do i=1,StrLen(Str)-L+1
          if (Str(i:i).EQ.SubStr(1:1)) then
            StrPos = i
            do j=i+1,i+L-1
              if (Str(j:j).NE.SubStr(j-i+1:j-i+1)) then
                StrPos = 0
                exit
              end if
            end do
          end if
        end do
      return
      end

      subroutine StrOfStr(Dest,Source,Count)
      character*(*) Dest,Source
      integer Count,i
        Dest = '\0'
        do i=1,Count
          call StrCat(Dest,Source)
        end do
      return
      end
      
      subroutine StrRead(Str)
      character*(*) Str
      integer FGetC,i
      character C

        Str = '\0'

        open(1,FILE='CON')
        do
          i = FGetC(1,C)
          select case (i)
            case (0)
              select case (ICHAR(C))
                case (10,13)
                  exit
              end select

              call StrCat(Str,C)
            case (-1)
              exit
            case default
              call ABORT
              return
          end select
        end do

        close(1)
      return
      end
      
#endif
